@safe @nogc nothrow: // not pure

import core.memory : pureFree, pureMalloc;
import core.stdc.errno : ENOENT, errno;
import core.stdc.stdio : fprintf, printf, SEEK_END, SEEK_SET, stderr;
import core.stdc.string : strerror;
import core.sys.posix.fcntl : open, O_CREAT, O_RDONLY, O_TRUNC, O_WRONLY, pid_t;
import core.sys.posix.spawn : posix_spawn;
import core.sys.posix.sys.wait : waitpid;
import core.sys.posix.dirent : DIR, dirent, opendir, readdir;
import core.sys.posix.sys.stat : mkdir, S_IRWXU;
import core.sys.posix.sys.types : off_t;
import core.sys.posix.time : clock_gettime, timespec;
import core.sys.posix.unistd : close, getcwd, lseek, read, readlink, unlink, posixWrite = write;
import std.process : execvpe;

import frontend.showDiag : ShowDiagOptions;
import interpret.allocTracker : AllocTracker, hasAllocedPtr, markAlloced, markFree, writeMarkedAllocedRanges;
import interpret.applyFn : nat64OfI32, nat64OfI64;
import interpret.bytecode : DynCallType, TimeSpec;
import lib.cliParser :
	BuildOptions,
	CCompileOptions,
	Command,
	matchCommand,
	parseCommand,
	ProgramDirAndMain,
	matchRunOptions,
	RunOptions;
import lib.compiler :
	buildAndInterpret,
	buildToC,
	BuildToCResult,
	compileAndDocument,
	DiagsAndResultStrs,
	DocumentResult,
	ExitCode,
	print;
import model.model : AbsolutePathsGetter;
import test.test : test;
import util.alloc.alloc : allocateBytes, freeBytes;
import util.alloc.rangeAlloc : RangeAlloc;
import util.collection.arr : begin, empty, size;
import util.collection.arrBuilder : add, addAll, ArrBuilder, finishArr;
import util.collection.arrUtil : cat, map, tail, zipImpureSystem;
import util.collection.str :
	asCStr,
	catToCStr,
	catToNulTerminatedStr,
	copyStr,
	CStr,
	cStrOfNulTerminatedStr,
	emptyNulTerminatedStr,
	NulTerminatedStr,
	startsWith,
	strEq,
	strOfCStr,
	strToCStr,
	strOfNulTerminatedStr;
import util.opt : force, forceOrTodo, has, none, Opt, some;
import util.path :
	AbsolutePath,
	AllPaths,
	baseName,
	Path,
	PathAndStorageKind,
	pathParent,
	pathToCStr,
	pathToNulTerminatedStr,
	pathToStr,
	removeFirstPathComponentIf,
	rootPath,
	StorageKind;
import util.ptr : Ptr, PtrRange, ptrTrustMe_mut;
import util.sym : AllSymbols;
import util.types :
	float64OfU64Bits,
	Nat64,
	safeSizeTFromU64,
	safeUlongFromLong,
	safeU32FromI64,
	u64OfFloat64Bits;
import util.util : todo, unreachable, verify;
import util.writer : Writer;

@system extern(C) immutable(int) main(immutable size_t argc, immutable CStr* argv) {
	immutable size_t memorySizeBytes = 1024 * 1024 * 1024;
	ubyte* mem = cast(ubyte*) pureMalloc(memorySizeBytes);
	scope(exit) pureFree(mem);
	verify(mem != null);
	RangeAlloc alloc = RangeAlloc(mem, memorySizeBytes);
	immutable CommandLineArgs args = parseCommandLineArgs(alloc, argc, argv);
	return go(alloc, args).value;
}

private:

struct StdoutDebug {
	@safe @nogc pure nothrow:

	bool enabled() {
		return false;
	}

	void write(scope immutable string a) {
		debug {
			printf("%.*s", cast(immutable uint) size(a), begin(a));
		}
	}

	void writeChar(immutable char c) {
		debug {
			printf("%c", c);
		}
	}
}

immutable(ExitCode) go(Alloc)(ref Alloc alloc, ref immutable CommandLineArgs args) {
	AllPaths!Alloc allPaths = AllPaths!Alloc(ptrTrustMe_mut(alloc));
	immutable string crowDir = getCrowDirectory(args.pathToThisExecutable);
	immutable string includeDir = getIncludeDirectory(alloc, crowDir);
	immutable string tempDir = setupTempDir(alloc, allPaths, crowDir);

	immutable string cwd = getCwd(alloc);
	immutable Command command = parseCommand!Alloc(alloc, allPaths, cwd, args.args);
	immutable ShowDiagOptions showDiagOptions = immutable ShowDiagOptions(true);
	StdoutDebug dbg;

	return matchCommand!(immutable ExitCode)(
		command,
		(ref immutable Command.Build it) =>
			runBuild(alloc, allPaths, cwd, includeDir, tempDir, it.programDirAndMain, it.options).err,
		(ref immutable Command.Document it) =>
			runDocument(alloc, allPaths, cwd, includeDir, it.programDirAndMain, it.out_),
		(ref immutable Command.Help it) =>
			help(it),
		(ref immutable Command.Print it) {
			RealReadOnlyStorage!(Alloc, Alloc) storage = RealReadOnlyStorage!(Alloc, Alloc)(
				ptrTrustMe_mut(allPaths),
				ptrTrustMe_mut(alloc),
				cwd,
				includeDir,
				it.programDirAndMain.programDir);
			immutable DiagsAndResultStrs printed = print(
				alloc,
				allPaths,
				storage,
				showDiagOptions,
				it.kind,
				it.format,
				getMain(allPaths, includeDir, it.programDirAndMain));
			if (!empty(printed.diagnostics)) printErr(printed.diagnostics);
			if (!empty(printed.result)) print(printed.result);
			return empty(printed.diagnostics) ? ExitCode.ok : ExitCode.error;
		},
		(ref immutable Command.Run run) =>
			matchRunOptions!(immutable ExitCode)(
				run.options,
				(ref immutable RunOptions.BuildAndRun it) {
					immutable RunBuildResult built =
						runBuild(alloc, allPaths, cwd, includeDir, tempDir, run.programDirAndMain, it.build);
					if (built.err != ExitCode.ok)
						return built.err;
					else {
						replaceCurrentProcess(alloc, allPaths, built.exePath, run.programArgs);
						return unreachable!ExitCode();
					}
				},
				(ref immutable RunOptions.Interpret) {
					RealReadOnlyStorage!(Alloc, Alloc) storage = RealReadOnlyStorage!(Alloc, Alloc)(
						ptrTrustMe_mut(allPaths),
						ptrTrustMe_mut(alloc),
						cwd,
						includeDir,
						run.programDirAndMain.programDir);
					RealExtern extern_ = RealExtern(ptrTrustMe_mut(alloc));
					AllSymbols!Alloc allSymbols = AllSymbols!Alloc(ptrTrustMe_mut(alloc));
					return buildAndInterpret(
						dbg,
						alloc,
						allPaths,
						allSymbols,
						storage,
						extern_,
						showDiagOptions,
						getMain(allPaths, includeDir, run.programDirAndMain),
						run.programArgs);
				}),
		(ref immutable Command.Test it) =>
			test(dbg, alloc, it.name));
}

@trusted immutable(string) setupTempDir(Alloc, PathAlloc)(
	ref Alloc alloc,
	ref AllPaths!PathAlloc allPaths,
	immutable string crowDir,
) {
	immutable NulTerminatedStr dirPath = catToNulTerminatedStr(alloc, crowDir, "/temp");
	DIR* dir = opendir(cStrOfNulTerminatedStr(dirPath));
	if (dir == null) {
		if (errno == ENOENT) {
			immutable int err = mkdir(cStrOfNulTerminatedStr(dirPath), S_IRWXU);
			if (err != 0)
				todo!void("error making temp");
		} else
			todo!void("failed to open dir");
	} else {
		while (true) {
			immutable dirent* entry = cast(immutable) readdir(dir);
			if (entry == null)
				break;
			immutable string entryName = strOfCStr(entry.d_name.ptr);
			if (!strEq(entryName, ".") && !strEq(entryName, "..")) {
				immutable CStr toUnlink = catToCStr(alloc, strOfNulTerminatedStr(dirPath), "/", entryName);
				immutable int err = unlink(toUnlink);
				if (err != 0) {
					todo!void("failed to unlink");
				}
			}
		}
	}
	return strOfNulTerminatedStr(dirPath);
}

@system immutable(ExitCode) mkdirRecur(TempAlloc)(ref TempAlloc tempAlloc, immutable string dir) {
	immutable char* dirCStr = strToCStr(tempAlloc, dir);
	immutable int err = mkdir(dirCStr, S_IRWXU);
	if (err == ENOENT) {
		immutable Opt!string par = pathParent(dir);
		if (has(par)) {
			immutable ExitCode res = mkdirRecur(tempAlloc, force(par));
			return res == ExitCode.ok
				? handleMkdirErr(mkdir(dirCStr, S_IRWXU), dirCStr)
				: res;
		}
	}
	return handleMkdirErr(err, dirCStr);
}

@system immutable(ExitCode) handleMkdirErr(immutable int err, immutable char* dir) {
	if (err != 0)
		fprintf(stderr, "Error making directory %s: %s\n", dir, strerror(errno));
	return immutable ExitCode(err);
}

immutable(ExitCode) runDocument(Alloc, PathAlloc)(
	ref Alloc alloc,
	ref AllPaths!PathAlloc allPaths,
	immutable string cwd,
	immutable string includeDir,
	ref immutable ProgramDirAndMain programDirAndMain,
	ref immutable Opt!AbsolutePath out_,
) {
	RealReadOnlyStorage!(PathAlloc, Alloc) storage = RealReadOnlyStorage!(PathAlloc, Alloc)(
		ptrTrustMe_mut(allPaths),
		ptrTrustMe_mut(alloc),
		cwd,
		includeDir,
		programDirAndMain.programDir);
	immutable DocumentResult result =
		compileAndDocument(alloc, allPaths, storage, showDiagOptions, getMain(allPaths, includeDir, programDirAndMain));
	return empty(result.diagnostics)
		? has(out_)
			? writeFile(alloc, pathToNulTerminatedStr(alloc, allPaths, force(out_)), result.document)
			: print(result.document)
		: printErr(result.diagnostics);
}

struct RunBuildResult {
	immutable ExitCode err;
	immutable AbsolutePath exePath;
}

immutable(RunBuildResult) runBuild(Alloc, PathAlloc)(
	ref Alloc alloc,
	ref AllPaths!PathAlloc allPaths,
	immutable string cwd,
	immutable string includeDir,
	immutable string tempDir,
	ref immutable ProgramDirAndMain programDirAndMain,
	ref immutable BuildOptions options,
) {
	immutable string name = baseName(allPaths, programDirAndMain.mainPath);
	immutable AbsolutePath cPath = has(options.out_.outC)
		? force(options.out_.outC)
		: immutable AbsolutePath(tempDir, rootPath(allPaths, name), ".c");
	immutable AbsolutePath exePath = has(options.out_.outExecutable)
		? force(options.out_.outExecutable)
		: immutable AbsolutePath(tempDir, rootPath(allPaths, name), "");
	immutable ExitCode err = buildToCAndCompile(
		alloc,
		allPaths,
		showDiagOptions,
		cwd,
		programDirAndMain,
		includeDir,
		cPath,
		exePath,
		options.cCompileOptions);
	return immutable RunBuildResult(err, exePath);
}

immutable ShowDiagOptions showDiagOptions = immutable ShowDiagOptions(true);

immutable(string) getIncludeDirectory(Alloc)(ref Alloc alloc, immutable string crowDir) {
	return cat(alloc, crowDir, "/include");
}

immutable(string) getCrowDirectory(immutable string pathToThisExecutable) {
	immutable Opt!string parent = pathParent(pathToThisExecutable);
	immutable Opt!string res = pathParent(forceOrTodo(parent));
	return forceOrTodo(res);
}

immutable(ExitCode) buildToCAndCompile(Alloc, PathAlloc)(
	ref Alloc alloc,
	ref AllPaths!PathAlloc allPaths,
	ref immutable ShowDiagOptions showDiagOptions,
	immutable string cwd,
	ref immutable ProgramDirAndMain programDirAndMain,
	immutable string includeDir,
	immutable AbsolutePath cPath,
	immutable AbsolutePath exePath,
	ref immutable CCompileOptions cCompileOptions,
) {
	RealReadOnlyStorage!(PathAlloc, Alloc) storage = RealReadOnlyStorage!(PathAlloc, Alloc)(
		ptrTrustMe_mut(allPaths),
		ptrTrustMe_mut(alloc),
		cwd,
		includeDir,
		programDirAndMain.programDir);
	immutable BuildToCResult result =
		buildToC(alloc, allPaths, storage, showDiagOptions, getMain(allPaths, includeDir, programDirAndMain));
	if (empty(result.diagnostics)) {
		immutable ExitCode res = writeFile(alloc, pathToNulTerminatedStr(alloc, allPaths, cPath), result.cSource);
		return res == ExitCode.ok
			? compileC(alloc, allPaths, cPath, exePath, result.allExternLibraryNames, cCompileOptions)
			: res;
	} else
		return printErr(result.diagnostics);
}

immutable(PathAndStorageKind) getMain(PathAlloc)(
	ref AllPaths!PathAlloc allPaths,
	immutable string includeDir,
	immutable ProgramDirAndMain programDirAndMain,
) {
	// Detect if we're building something already in 'include'
	if (startsWith(includeDir, programDirAndMain.programDir)
		&& strEq(includeDir[programDirAndMain.programDir.length .. $], "/include")) {
		immutable Opt!Path withoutInclude = removeFirstPathComponentIf(allPaths, programDirAndMain.mainPath, "include");
		if (has(withoutInclude))
			return immutable PathAndStorageKind(force(withoutInclude), StorageKind.global);
	}

	return immutable PathAndStorageKind(
		programDirAndMain.mainPath,
		strEq(includeDir, programDirAndMain.programDir) ? StorageKind.global : StorageKind.local);
}

immutable(ExitCode) help(ref immutable Command.Help a) {
	println(a.helpText);
	final switch (a.kind) {
		case Command.Help.Kind.requested:
			return ExitCode.ok;
		case Command.Help.Kind.error:
			return ExitCode.error;
	}
}

immutable(string[]) cCompilerArgs(ref immutable CCompileOptions options) {
	static immutable string[] optimizedArgs = [
		"-Werror",
		"-Wextra",
		"-Wall",
		"-ansi",
		"-std=c11",
		"-Wno-unused-parameter",
		"-Wno-unused-but-set-variable",
		"-Wno-unused-variable",
		"-Wno-unused-value",
		"-Wno-builtin-declaration-mismatch", //TODO:KILL?
		"-pthread",
		"-lm",
		"-Ofast",
	];
	static immutable string[] regularArgs = optimizedArgs[0 .. $ - 1];
	return options.optimize ? optimizedArgs : regularArgs;
}

@trusted immutable(ExitCode) compileC(Alloc, PathAlloc)(
	ref Alloc alloc,
	ref AllPaths!PathAlloc allPaths,
	ref immutable AbsolutePath cPath,
	ref immutable AbsolutePath exePath,
	immutable string[] allExternLibraryNames,
	ref immutable CCompileOptions options,
) {
	immutable string[] args = cCompileArgs(alloc, allPaths, cPath, exePath, allExternLibraryNames, options);
	// if (true) {
	// 	printf("/usr/bin/cc");
	// 	foreach (immutable string arg; args) {
	// 		printf(" %.*s", cast(int) size(arg), arg.ptr);
	// 	}
	// 	printf("\n");
	// }
	immutable int err = spawnAndWait(alloc, allPaths, "/usr/bin/cc", args);
	return immutable ExitCode(err);
}

immutable(string[]) cCompileArgs(Alloc, PathAlloc)(
	ref Alloc alloc,
	ref AllPaths!PathAlloc allPaths,
	ref immutable AbsolutePath cPath,
	ref immutable AbsolutePath exePath,
	immutable string[] allExternLibraryNames,
	ref immutable CCompileOptions options,
) {
	ArrBuilder!string args;
	addAll(alloc, args, cCompilerArgs(options));
	foreach (immutable string it; allExternLibraryNames)
		add(alloc, args, cat(alloc, "-l", it));
	addAll(alloc, args, [
		// TODO: configurable whether we want debug or release
		"-g",
		pathToStr(alloc, allPaths, cPath),
		"-o",
		pathToStr(alloc, allPaths, exePath),
	]);
	return finishArr(alloc, args);
}

@trusted immutable(ExitCode) print(immutable string a) {
	printf("%.*s", cast(uint) size(a), begin(a));
	return ExitCode.ok;
}

@trusted void println(immutable string a) {
	printf("%.*s\n", cast(uint) size(a), begin(a));
}

@trusted immutable(ExitCode) printErr(immutable string a) {
	fprintf(stderr, "%.*s", cast(uint) size(a), begin(a));
	return ExitCode.error;
}

struct RealReadOnlyStorage(PathAlloc, Alloc) {
	@safe @nogc nothrow: // not pure

	immutable(AbsolutePathsGetter) absolutePathsGetter() const {
		return immutable AbsolutePathsGetter(cwd, include, user);
	}

	immutable(T) withFile(T)(
		ref immutable PathAndStorageKind pk,
		immutable string extension,
		scope immutable(T) delegate(ref immutable Opt!NulTerminatedStr) @safe @nogc nothrow cb,
	) {
		immutable string root = () {
			final switch (pk.storageKind) {
				case StorageKind.global:
					return include;
				case StorageKind.local:
					return user;
			}
		}();
		immutable AbsolutePath ap = immutable AbsolutePath(root, pk.path, extension);
		return tryReadFile(tempAlloc.deref(), allPaths, ap, cb);
	}

	private:
	Ptr!(AllPaths!PathAlloc) allPaths;
	Ptr!Alloc tempAlloc;
	immutable string cwd;
	immutable string include;
	immutable string user;
}

struct RealExtern {
	@safe @nogc nothrow: // not pure

	private:
	@disable this();
	@disable this(ref const RealExtern);

	Ptr!RangeAlloc alloc;
	AllocTracker allocTracker;
	void* sdlHandle;
	DCCallVM* dcVm;

	this(Ptr!RangeAlloc a) {
		alloc = a;
		// TODO: better way to find where it is (may depend on system)
		sdlHandle = dlopen("/usr/lib64/libSDL2-2.0.so.0", RTLD_LAZY);
		verify(sdlHandle != null);

		dcVm = dcNewCallVM(4096);
		verify(dcVm != null);
		dcMode(dcVm, DC_CALL_C_DEFAULT);
	}

	public:

	~this() {
		immutable int err = dlclose(sdlHandle);
		verify(err == 0);
		dcFree(dcVm);
	}

	@system immutable(int) clockGetTime(immutable int clockId, Ptr!TimeSpec tp) {
		return clock_gettime(clockId, cast(timespec*) tp.rawPtr());
	}

	@system pure void free(ubyte* ptr) {
		immutable size_t size = markFree(allocTracker, ptr);
		freeBytes(alloc.deref(), ptr, size);
	}

	@system pure ubyte* malloc(immutable size_t size) {
		ubyte* ptr = allocateBytes(alloc.deref(), size);
		markAlloced(alloc.deref(), allocTracker, ptr, size);
		return ptr;
	}

	@system immutable(long) write(int fd, immutable char* buf, immutable size_t nBytes) const {
		return posixWrite(fd, buf, nBytes);
	}

	immutable(size_t) getNProcs() const {
		// TODO: interpreter needs to support multiple threads
		return 1;
	}

	immutable(size_t) pthreadYield() const {
		// We don't support launching other threads, so do nothing
		return 0;
	}

	immutable(bool) hasMallocedPtr(ref const PtrRange range) const {
		return hasAllocedPtr(allocTracker, range);
	}

	@trusted void writeMallocedRanges(WriterAlloc)(ref Writer!WriterAlloc writer) const {
		writeMarkedAllocedRanges(writer, allocTracker);
	}

	@trusted immutable(Nat64) doDynCall(
		ref immutable NulTerminatedStr name,
		immutable DynCallType returnType,
		ref immutable Nat64[] parameters,
		ref immutable DynCallType[] parameterTypes,
	) {
		// TODO: don't just get everything from SDL...
		immutable CStr nameCStr = asCStr(name);
		DCpointer ptr = dlsym(sdlHandle, nameCStr);
		if (ptr == null)
			printf("Can't load symbol %s\n", nameCStr);
		verify(ptr != null);

		dcReset(dcVm);
		zipImpureSystem!(Nat64, DynCallType)(
			parameters,
			parameterTypes,
			(ref immutable Nat64 value, ref immutable DynCallType type) {
				final switch (type) {
					case DynCallType.bool_:
						todo!void("handle this type");
						break;
					case DynCallType.char_:
						todo!void("handle this type");
						break;
					case DynCallType.int8:
						todo!void("handle this type");
						break;
					case DynCallType.int16:
						todo!void("handle this type");
						break;
					case DynCallType.int32:
						dcArgInt(dcVm, cast(int) value.raw());
						break;
					case DynCallType.float32:
						todo!void("handle this type");
						break;
					case DynCallType.float64:
						dcArgDouble(dcVm, float64OfU64Bits(value.raw()));
						break;
					case DynCallType.nat8:
						todo!void("handle this type");
						break;
					case DynCallType.nat16:
						todo!void("handle this type");
						break;
					case DynCallType.nat32:
						dcArgInt(dcVm, cast(uint) value.raw());
						break;
					case DynCallType.int64:
					case DynCallType.nat64:
						dcArgLong(dcVm, value.raw());
						break;
					case DynCallType.pointer:
						dcArgPointer(dcVm, cast(void*) value.raw());
						break;
					case DynCallType.void_:
						unreachable!void();
				}
			});

		immutable Nat64 res = () {
			final switch (returnType) {
				case DynCallType.bool_:
					return todo!(immutable Nat64)("handle this type");
				case DynCallType.char_:
					return todo!(immutable Nat64)("handle this type");
				case DynCallType.int8:
					return todo!(immutable Nat64)("handle this type");
				case DynCallType.int16:
					return todo!(immutable Nat64)("handle this type");
				case DynCallType.int32:
					return nat64OfI32(dcCallInt(dcVm, ptr));
				case DynCallType.int64:
					return nat64OfI64(dcCallLong(dcVm, ptr));
				case DynCallType.float32:
					return todo!(immutable Nat64)("handle this type");
				case DynCallType.float64:
					return u64OfFloat64Bits(dcCallDouble(dcVm, ptr));
				case DynCallType.nat8:
					return todo!(immutable Nat64)("handle this type");
				case DynCallType.nat16:
					return todo!(immutable Nat64)("handle this type");
				case DynCallType.nat32:
					return todo!(immutable Nat64)("handle this type");
				case DynCallType.nat64:
					return todo!(immutable Nat64)("handle this type");
				case DynCallType.pointer:
					return immutable Nat64(cast(size_t) dcCallPointer(dcVm, ptr));
				case DynCallType.void_:
					dcCallVoid(dcVm, ptr);
					return immutable Nat64(0);
			}
		}();
		dcReset(dcVm);
		return res;
	}
}

extern(C) {
	// dlfcn.h
	void* dlopen(const char* file, int mode);
	int dlclose(void* handle);
	void* dlsym(void* handle, const char* name);
	enum RTLD_LAZY = 1;

	// dyncall_types.h
	//alias DCvoid = void;
	alias DCbool = int;
	alias DCchar = char;
	//alias DCuchar = uchar;
	alias DCshort = short;
	//alias DCushort = ushort;
	alias DCint = int;
	//alias DCuint = uint;
	alias DClong = long;
	//alias DCulong = ulong;
	//typedef DC_LONG_LONG DClonglong;
	//typedef unsigned DC_LONG_LONG DCulonglong;
	alias DCfloat = float;
	alias DCdouble = double;
	alias DCpointer = void*;
	//alias DCstring = const char*;
	alias DCsize = size_t;

	// dyncall.h
	struct DCCallVM;

	enum DC_CALL_C_DEFAULT = 0;

	DCCallVM* dcNewCallVM(DCsize size);
	void dcFree(DCCallVM* vm);
	void dcReset(DCCallVM* vm);

	void dcMode(DCCallVM* vm, DCint mode);

	//void dcArgBool (DCCallVM* vm, DCbool value);
	//void dcArgChar (DCCallVM* vm, DCchar value);
	//void dcArgShort (DCCallVM* vm, DCshort value);
	void dcArgInt (DCCallVM* vm, DCint value);
	void dcArgLong (DCCallVM* vm, DClong value);
	//void dcArgLongLong (DCCallVM* vm, DClonglong value);
	//void dcArgFloat (DCCallVM* vm, DCfloat value);
	void dcArgDouble (DCCallVM* vm, DCdouble value);
	void dcArgPointer (DCCallVM* vm, DCpointer value);
	// void dcArgStruct (DCCallVM* vm, DCstruct* s, DCpointer value);

	void dcCallVoid (DCCallVM* vm, DCpointer funcptr);
	//DCbool dcCallBool (DCCallVM* vm, DCpointer funcptr);
	//DCchar dcCallChar (DCCallVM* vm, DCpointer funcptr);
	//DCshort dcCallShort (DCCallVM* vm, DCpointer funcptr);
	DCint dcCallInt (DCCallVM* vm, DCpointer funcptr);
	DClong dcCallLong (DCCallVM* vm, DCpointer funcptr);
	//DClonglong dcCallLongLong (DCCallVM* vm, DCpointer funcptr);
	//DCfloat dcCallFloat (DCCallVM* vm, DCpointer funcptr);
	DCdouble dcCallDouble (DCCallVM* vm, DCpointer funcptr);
	DCpointer dcCallPointer (DCCallVM* vm, DCpointer funcptr);
	// void dcCallStruct (DCCallVM* vm, DCpointer funcptr, DCstruct* s, DCpointer returnValue);

	//DCint dcGetError (DCCallVM* vm);
}

//extern void *dlopen (const char *__file, int __mode) __THROWNL;

@trusted immutable(T) tryReadFile(T, TempAlloc, PathAlloc)(
	ref TempAlloc tempAlloc,
	ref const AllPaths!PathAlloc allPaths,
	immutable AbsolutePath path,
	scope immutable(T) delegate(ref immutable Opt!NulTerminatedStr) @safe @nogc nothrow cb,
) {
	immutable CStr pathCStr = pathToCStr(tempAlloc, allPaths, path);

	immutable int fd = open(pathCStr, O_RDONLY);
	if (fd == -1) {
		if (errno == ENOENT) {
			immutable Opt!NulTerminatedStr n = none!NulTerminatedStr;
			return cb(n);
		} else {
			fprintf(stderr, "Failed to open file %s\n", pathCStr);
			return todo!T("fail");
		}
	}

	scope(exit) close(fd);

	immutable off_t fileSizeOff = lseek(fd, 0, SEEK_END);
	if (fileSizeOff == -1)
		return todo!T("lseek fialed");

	if (fileSizeOff > 99_999)
		return todo!T("size suspiciously large");

	immutable uint fileSize = safeU32FromI64(fileSizeOff);

	if (fileSize == 0) {
		immutable Opt!NulTerminatedStr s = some(emptyNulTerminatedStr);
		return cb(s);
	}

	// Go back to the beginning so we can read
	immutable off_t off = lseek(fd, 0, SEEK_SET);
	if (off == -1)
		return todo!T("lseek failed");

	verify(off == 0);

	immutable size_t contentSize = safeSizeTFromU64(fileSize + 1);
	char* content = cast(char*) allocateBytes(tempAlloc, char.sizeof * contentSize); // + 1 for the '\0'
	scope (exit) freeBytes(tempAlloc, cast(ubyte*) content, char.sizeof * contentSize);
	immutable long nBytesRead = read(fd, content, fileSize);

	if (nBytesRead == -1)
		return todo!T("read failed");

	if (nBytesRead != fileSize)
		return todo!T("nBytesRead not right?");

	content[fileSize] = '\0';

	immutable Opt!NulTerminatedStr s =
		some(immutable NulTerminatedStr(cast(immutable) content[0 .. contentSize]));
	return cb(s);
}

@trusted immutable(ExitCode) writeFile(TempAlloc)(
	ref TempAlloc tempAlloc,
	immutable NulTerminatedStr path,
	string content,
) {
	immutable int fd = tryOpenFile(tempAlloc, path);
	if (fd == -1) {
		fprintf(stderr, "Failed to write file %s: %s\n", asCStr(path), strerror(errno));
		return ExitCode.error;
	} else {
		scope(exit) close(fd);

		immutable long wroteBytes = posixWrite(fd, content.begin, size(content));
		if (wroteBytes != size(content))
			if (wroteBytes == -1)
				todo!void("writeFile failed");
			else
				todo!void("writeFile -- didn't write all the bytes?");
		return ExitCode.ok;
	}
}

@system immutable(int) tryOpenFile(TempAlloc)(ref TempAlloc tempAlloc, immutable NulTerminatedStr path) {
	immutable int fd = open(asCStr(path), O_CREAT | O_WRONLY | O_TRUNC, 0b110_100_100);
	if (fd == -1 && errno == ENOENT) {
		immutable Opt!string par = pathParent(strOfNulTerminatedStr(path));
		if (has(par)) {
			immutable ExitCode res = mkdirRecur(tempAlloc, force(par));
			if (res == ExitCode.ok)
				return open(asCStr(path), O_CREAT | O_WRONLY | O_TRUNC, 0b110_100_100);
		}
	}
	return fd;
}

// Replaces this process with the given executable.
// DOES NOT RETURN!
@trusted void replaceCurrentProcess(TempAlloc, PathAlloc)(
	ref TempAlloc tempAlloc,
	ref const AllPaths!PathAlloc allPaths,
	immutable AbsolutePath executable,
	immutable string[] args,
) {
	immutable CStr executableCStr = pathToCStr(tempAlloc, allPaths, executable);
	immutable int err = execvpe(executableCStr, convertArgs(tempAlloc, executableCStr, args), environ);
	// 'execvpe' only returns if we failed to create the process (maybe executable does not exist?)
	verify(err == -1);
	fprintf(stderr, "Failed to launch %s: error %s\n", executableCStr, strerror(errno));
	todo!void("failed to launch");
}

struct CommandLineArgs {
	immutable string pathToThisExecutable;
	immutable string[] args;
}

@trusted immutable(CommandLineArgs) parseCommandLineArgs(Alloc)(
	ref Alloc alloc,
	immutable size_t argc,
	immutable CStr* argv,
) {
	immutable CStr[] allArgs = argv[0 .. argc];
	immutable string[] args = map!(string, CStr, Alloc)(alloc, allArgs, (ref immutable CStr a) => strOfCStr(a));
	// Take the tail because the first one is 'crow'
	return immutable CommandLineArgs(getPathToThisExecutable(alloc), tail(args));
}

@trusted immutable(string) getCwd(Alloc)(ref Alloc alloc) {
	char[maxPathSize] buff;
	char* b = getcwd(buff.ptr, maxPathSize);
	if (b == null)
		return todo!string("getcwd failed");
	else {
		verify(b == buff.ptr);
		return copyCStrToStr(alloc, cast(immutable) buff.ptr);
	}
}

immutable(string) copyCStrToStr(Alloc)(ref Alloc alloc, immutable CStr begin) {
	return copyStr(alloc, strOfCStr(begin));
}

immutable size_t maxPathSize = 0x1000;

@trusted immutable(string) getPathToThisExecutable(Alloc)(ref Alloc alloc) {
	char[maxPathSize] buff;
	immutable long size = readlink("/proc/self/exe", buff.ptr, maxPathSize);
	if (size < 0)
		todo!void("posix error");
	return copyStr(alloc, cast(immutable) buff.ptr[0 .. safeUlongFromLong(size)]);
}

// Returns the child process' error code.
// WARN: A first arg will be prepended that is the executable path.
@trusted immutable(int) spawnAndWait(TempAlloc, PathAlloc)(
	ref TempAlloc tempAlloc,
	ref const AllPaths!PathAlloc allPaths,
	immutable CStr executablePath,
	immutable string[] args,
) {
	pid_t pid;
	immutable int spawnStatus = posix_spawn(
		&pid,
		executablePath,
		null,
		null,
		// https://stackoverflow.com/questions/50596439/can-string-literals-be-passed-in-posix-spawns-argv
		cast(char**) convertArgs(tempAlloc, executablePath, args),
		cast(char**) environ);
	if (spawnStatus == 0) {
		int waitStatus;
		immutable int resPid = waitpid(pid, &waitStatus, 0);
		verify(resPid == pid);
		if (WIFEXITED(waitStatus))
			return WEXITSTATUS(waitStatus); // only valid if WIFEXITED
		else {
			if (WIFSIGNALED(waitStatus))
				return todo!int("process exited with signal");
			else
				return todo!int("process exited non-normally");
		}
	} else
		return todo!int("posix_spawn failed");
}

// Return should be const, but some posix functions aren't marked that way
@system immutable(CStr*) convertArgs(Alloc)(
	ref Alloc alloc,
	immutable CStr executable,
	immutable string[] args,
) {
	ArrBuilder!CStr cArgs;
	add(alloc, cArgs, executable);
	foreach (immutable string arg; args)
		add(alloc, cArgs, strToCStr(alloc, arg));
	add(alloc, cArgs, null);
	return finishArr(alloc, cArgs).begin;
}

// D doesn't declare this anywhere for some reason
extern(C) int execvpe(const char *__file, const char ** __argv, const char ** __envp);
extern(C) extern immutable char** environ;

// Copying from /usr/include/dmd/druntime/import/core/sys/posix/sys/wait.d
// to avoid linking to druntime
int __WTERMSIG( int status ) { return status & 0x7F; }
int WEXITSTATUS( int status ) { return ( status & 0xFF00 ) >> 8; }
bool WIFEXITED( int status ) { return __WTERMSIG( status ) == 0; }
bool WIFSIGNALED( int status )
{
	return ( cast(byte) ( ( status & 0x7F ) + 1 ) >> 1 ) > 0;
}
