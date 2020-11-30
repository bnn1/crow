module server;

@safe @nogc nothrow: // not pure

import compiler : buildAndInterpret;
import frontend.getTokens : Token, tokensOfAst;
import frontend.lang : nozeExtension;
import frontend.parse : FileAstAndParseDiagnostics, parseFile;
import frontend.showDiag : ShowDiagOptions, strOfParseDiag;
import interpret.fakeExtern : FakeExtern;
import model.parseDiag : ParseDiagnostic;
import model.model : AbsolutePathsGetter;
import util.bools : False;
import util.collection.arr : Arr, emptyArr, freeArr;
import util.collection.arrUtil : map;
import util.collection.mutDict : getAt_mut, insertOrUpdate, mustDelete, mustGetAt_mut, MutDict;
import util.collection.str :
	copyToNulTerminatedStr,
	CStr,
	cStrOfNulTerminatedStr,
	NulTerminatedStr,
	Str,
	strEq,
	strLiteral;
import util.opt : asImmutable, force, has, Opt;
import util.path : comparePathAndStorageKind, parsePath, Path, PathAndStorageKind, StorageKind;
import util.ptr : Ptr, ptrTrustMe_const, ptrTrustMe_mut;
import util.sourceRange : RangeWithinFile;
import util.sym : AllSymbols;
import util.util : verify;

struct Server(Alloc) {
	Alloc alloc;
	AllSymbols!Alloc allSymbols;
	MutFiles files;

	this(Alloc a) {
		alloc = a.move();
		allSymbols = AllSymbols!Alloc(Ptr!Alloc(&alloc));
	}
}

private alias MutFiles = MutDict!(immutable PathAndStorageKind, immutable NulTerminatedStr, comparePathAndStorageKind);

void addOrChangeFile(Alloc)(
	ref Server!Alloc server,
	immutable StorageKind storageKind,
	scope ref immutable Str path,
	scope ref immutable Str content,
) {
	immutable PathAndStorageKind key = immutable PathAndStorageKind(toPath(server, path), storageKind);
	immutable NulTerminatedStr contentCopy = copyToNulTerminatedStr(server.alloc, content);
	insertOrUpdate!(Alloc, immutable PathAndStorageKind, immutable NulTerminatedStr, comparePathAndStorageKind)(
		server.alloc,
		server.files,
		key,
		() => contentCopy,
		(ref immutable NulTerminatedStr old) {
			trustedFree(server.alloc, old.str);
			return contentCopy;
		});
}

void deleteFile(Alloc)(ref Server!Alloc server, immutable StorageKind storageKind, immutable Str path) {
	immutable PathAndStorageKind key = immutable PathAndStorageKind(toPath(server, path), storageKind);
	immutable(NulTerminatedStr) deleted = mustDelete(server.files, key);
	trustedFree(server.alloc, deleted.str);
}

immutable(CStr) getFile(ServerAlloc)(
	ref Server!ServerAlloc server,
	immutable StorageKind storageKind,
	immutable Str path,
) {
	immutable PathAndStorageKind key = immutable PathAndStorageKind(toPath(server, path), storageKind);
	immutable Opt!(immutable NulTerminatedStr) text = getAt_mut(server.files, key);
	return has(text) ? cStrOfNulTerminatedStr(force(text)) : "";
}

immutable(Arr!Token) getTokens(Alloc, ServerAlloc)(
	ref Alloc alloc,
	ref Server!ServerAlloc server,
	immutable StorageKind storageKind,
	immutable Str path,
) {
	immutable PathAndStorageKind key = immutable PathAndStorageKind(toPath(server, path), storageKind);
	immutable NulTerminatedStr text = mustGetAt_mut(server.files, key);
	immutable FileAstAndParseDiagnostics ast = parseFile(alloc, server.allSymbols, text);
	return tokensOfAst(alloc, ast.ast);
}

struct StrParseDiagnostic {
	immutable RangeWithinFile range;
	immutable Str message;
}

immutable(Arr!StrParseDiagnostic) getParseDiagnostics(Alloc, ServerAlloc)(
	ref Alloc alloc,
	ref Server!ServerAlloc server,
	immutable StorageKind storageKind,
	immutable Str path,
) {
	immutable PathAndStorageKind key = immutable PathAndStorageKind(toPath(server, path), storageKind);
	immutable NulTerminatedStr text = mustGetAt_mut(server.files, key);
	immutable FileAstAndParseDiagnostics ast = parseFile(alloc, server.allSymbols, text);
	return map!StrParseDiagnostic(alloc, ast.diagnostics, (ref immutable ParseDiagnostic it) =>
		immutable StrParseDiagnostic(it.range, strOfParseDiag(alloc, showDiagOptions, it.diag)));

}

struct RunResult {
	immutable int err;
	immutable Str stdout;
	immutable Str stderr;
}

immutable(RunResult) run(Debug, Alloc, ServerAlloc)(
	ref Debug dbg,
	ref Alloc alloc,
	ref Server!ServerAlloc server,
	immutable Str mainPathStr,
) {
	immutable Ptr!Path mainPath = toPath(server, mainPathStr);
	// TODO: use an arena so anything allocated during interpretation is cleaned up.
	// Or just have interpreter free things.
	immutable Arr!Str programArgs = emptyArr!Str;
	FakeExtern!Alloc extern_ = FakeExtern!Alloc(ptrTrustMe_mut(alloc));
	DictReadOnlyStorage storage = DictReadOnlyStorage(ptrTrustMe_const(server.files));
	immutable int err = buildAndInterpret!(Debug, Alloc, ServerAlloc, DictReadOnlyStorage, FakeExtern!Alloc)(
		dbg, alloc, server.allSymbols, storage, extern_, showDiagOptions, mainPath, programArgs);
	return RunResult(err, extern_.moveStdout(), extern_.moveStderr());
}

private:

@trusted void trustedFree(Alloc)(ref Alloc alloc, ref immutable Str a) {
	freeArr(alloc, a);
}

immutable ShowDiagOptions showDiagOptions = immutable ShowDiagOptions(False);

immutable(Ptr!Path) toPath(Alloc)(ref Server!Alloc server, immutable Str path) {
	return parsePath(server.alloc, server.allSymbols, path);
}

struct DictReadOnlyStorage {
	@safe @nogc nothrow: // not pure

	pure immutable(AbsolutePathsGetter) absolutePathsGetter() const {
		return immutable AbsolutePathsGetter(strLiteral("include"), strLiteral("user"));
	}

	immutable(T) withFile(T)(
		ref immutable PathAndStorageKind pk,
		immutable Str extension,
		scope immutable(T) delegate(ref immutable Opt!NulTerminatedStr) @safe @nogc nothrow cb,
	) const {
		verify(strEq(extension, nozeExtension));
		immutable Opt!NulTerminatedStr content = asImmutable(getAt_mut(files, pk));
		return cb(content);
	}

	private:
	const Ptr!MutFiles files;
}