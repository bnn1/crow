module lib.server;

@safe @nogc nothrow: // not pure

import lib.compiler : buildAndInterpret;
import frontend.frontendCompile : frontendCompile;
import frontend.ide.getHover : getHoverStr;
import frontend.ide.getPosition : getPosition, Position;
import frontend.ide.getTokens : Token, tokensOfAst;
import frontend.parse.parse : FileAstAndParseDiagnostics, parseFile;
import frontend.showDiag : ShowDiagOptions, strOfParseDiag;
import interpret.fakeExtern : FakeExtern;
import model.parseDiag : ParseDiagnostic;
import model.model : Program;
import util.collection.arr : at, emptyArr, freeArr;
import util.collection.arrUtil : map;
import util.collection.fullIndexDict : FullIndexDict, fullIndexDictSize;
import util.collection.mutDict : getAt_mut, insertOrUpdate, mustDelete, mustGetAt_mut;
import util.collection.str : copyToNulTerminatedStr, CStr, cStrOfNulTerminatedStr, emptyStr, NulTerminatedStr;
import util.comparison : Comparison;
import util.dictReadOnlyStorage : DictReadOnlyStorage, MutFiles;
import util.opt : force, has, none, Opt, some;
import util.path : AllPaths, comparePathAndStorageKind, parsePath, Path, PathAndStorageKind, StorageKind;
import util.ptr : Ptr, ptrTrustMe_const, ptrTrustMe_mut;
import util.sourceRange : FileIndex, Pos, RangeWithinFile;
import util.sym : AllSymbols;
import util.types : safeSizeTToU16;

struct Server(Alloc) {
	Alloc alloc;
	AllSymbols!Alloc allSymbols;
	AllPaths!Alloc allPaths;
	MutFiles files;

	this(Alloc a) {
		alloc = a.move();
		allSymbols = AllSymbols!Alloc(Ptr!Alloc(&alloc));
		allPaths = AllPaths!Alloc(Ptr!Alloc(&alloc));
		files = MutFiles.init;
	}
}

void addOrChangeFile(Debug, ServerAlloc)(
	ref Debug,
	ref Server!ServerAlloc server,
	immutable StorageKind storageKind,
	scope ref immutable string path,
	scope ref immutable string content,
) {
	immutable PathAndStorageKind key = immutable PathAndStorageKind(toPath(server, path), storageKind);
	immutable NulTerminatedStr contentCopy = copyToNulTerminatedStr(server.alloc, content);
	insertOrUpdate!(ServerAlloc, immutable PathAndStorageKind, immutable NulTerminatedStr, comparePathAndStorageKind)(
		server.alloc,
		server.files,
		key,
		() => contentCopy,
		(ref immutable NulTerminatedStr old) {
			trustedFree(server.alloc, old.str);
			return contentCopy;
		});
}

void deleteFile(Alloc)(ref Server!Alloc server, immutable StorageKind storageKind, immutable string path) {
	immutable PathAndStorageKind key = immutable PathAndStorageKind(toPath(server, path), storageKind);
	immutable(NulTerminatedStr) deleted = mustDelete(server.files, key);
	trustedFree(server.alloc, deleted.str);
}

immutable(CStr) getFile(ServerAlloc)(
	ref Server!ServerAlloc server,
	immutable StorageKind storageKind,
	immutable string path,
) {
	immutable PathAndStorageKind key = immutable PathAndStorageKind(toPath(server, path), storageKind);
	immutable Opt!(immutable NulTerminatedStr) text = getAt_mut(server.files, key);
	return has(text) ? cStrOfNulTerminatedStr(force(text)) : "";
}

immutable(Token[]) getTokens(Alloc, ServerAlloc)(
	ref Alloc alloc,
	ref Server!ServerAlloc server,
	immutable StorageKind storageKind,
	immutable string path,
) {
	immutable PathAndStorageKind key = immutable PathAndStorageKind(toPath(server, path), storageKind);
	immutable NulTerminatedStr text = mustGetAt_mut(server.files, key);
	immutable FileAstAndParseDiagnostics ast = parseFile(alloc, server.allPaths, server.allSymbols, text);
	return tokensOfAst(alloc, ast.ast);
}

struct StrParseDiagnostic {
	immutable RangeWithinFile range;
	immutable string message;
}

immutable(StrParseDiagnostic[]) getParseDiagnostics(Alloc, ServerAlloc)(
	ref Alloc alloc,
	ref Server!ServerAlloc server,
	immutable StorageKind storageKind,
	immutable string path,
) {
	immutable PathAndStorageKind key = immutable PathAndStorageKind(toPath(server, path), storageKind);
	immutable NulTerminatedStr text = mustGetAt_mut(server.files, key);
	immutable FileAstAndParseDiagnostics ast = parseFile(alloc, server.allPaths, server.allSymbols, text);
	return map!StrParseDiagnostic(alloc, ast.diagnostics, (ref immutable ParseDiagnostic it) =>
		immutable StrParseDiagnostic(it.range, strOfParseDiag(alloc, server.allPaths, showDiagOptions, it.diag)));
}

immutable(string) getHover(Debug, Alloc, ServerAlloc)(
	ref Debug dbg,
	ref Alloc alloc,
	ref Server!ServerAlloc server,
	immutable StorageKind storageKind,
	immutable string path,
	immutable Pos pos,
) {
	DictReadOnlyStorage storage = DictReadOnlyStorage(ptrTrustMe_const(server.files));
	immutable Ptr!Program program =
		frontendCompile(alloc, alloc, server.allPaths, server.allSymbols, storage, toPath(server, path));
	return getHoverFromProgram(alloc, server, storageKind, path, program, pos);
}

private pure immutable(string) getHoverFromProgram(Alloc, ServerAlloc)(
	ref Alloc alloc,
	ref Server!ServerAlloc server,
	immutable StorageKind storageKind,
	immutable string path,
	ref immutable Program program,
	immutable Pos pos,
) {
	immutable PathAndStorageKind pk = immutable PathAndStorageKind(toPath(server, path), storageKind);
	immutable Opt!FileIndex fileIndex = getFileIndex(program.filesInfo.filePaths, pk);
	if (has(fileIndex)) {
		immutable Opt!Position position = getPosition(at(program.allModules, force(fileIndex).index), pos);
		return has(position) ? getHoverStr(alloc, alloc, server.allPaths, program, force(position)) : emptyStr;
	} else
		return emptyStr;
}

//TODO:KILL, use a reverse lookup
private pure immutable(Opt!FileIndex) getFileIndex(
	scope ref immutable FullIndexDict!(FileIndex, PathAndStorageKind) filePaths,
	scope ref immutable PathAndStorageKind search,
) {
	foreach (immutable size_t i; 0..fullIndexDictSize(filePaths))
		if (comparePathAndStorageKind(at(filePaths.values, i), search) == Comparison.equal)
			return some(immutable FileIndex(safeSizeTToU16(i)));
	return none!FileIndex;
}

struct RunResult {
	immutable int err;
	immutable string stdout;
	immutable string stderr;
}

immutable(RunResult) run(Debug, Alloc, ServerAlloc)(
	ref Debug dbg,
	ref Alloc alloc,
	ref Server!ServerAlloc server,
	immutable string mainPathStr,
) {
	immutable Path mainPath = toPath(server, mainPathStr);
	// TODO: use an arena so anything allocated during interpretation is cleaned up.
	// Or just have interpreter free things.
	immutable string[] programArgs = emptyArr!string;
	FakeExtern!Alloc extern_ = FakeExtern!Alloc(ptrTrustMe_mut(alloc));
	DictReadOnlyStorage storage = DictReadOnlyStorage(ptrTrustMe_const(server.files));
	immutable int err = buildAndInterpret(
		dbg, alloc, server.allPaths, server.allSymbols, storage, extern_, showDiagOptions, mainPath, programArgs);
	return RunResult(err, extern_.moveStdout(), extern_.moveStderr());
}

private:

@trusted void trustedFree(Alloc)(ref Alloc alloc, ref immutable string a) {
	freeArr(alloc, a);
}

pure immutable(Path) toPath(Alloc)(ref Server!Alloc server, scope ref immutable string path) {
	return parsePath(server.allPaths, path);
}

immutable ShowDiagOptions showDiagOptions = immutable ShowDiagOptions(false);
