@safe @nogc nothrow: // not pure

import frontend.ide.getTokens : reprTokens, Token;
import interpret.fakeExtern : FakeExternResult;
import lib.server :
	addOrChangeFile,
	deleteFile,
	getFile,
	getHover,
	getParseDiagnostics,
	getTokens,
	run,
	Server,
	StrParseDiagnostic;
import util.alloc.alloc : Alloc, allocateT;
import util.alloc.rangeAlloc : RangeAlloc;
import util.col.str : CStr, SafeCStr;
import util.memory : utilMemcpy = memcpy, utilMemmove = memmove;
import util.path : StorageKind;
import util.perf : eachMeasure, Perf, PerfMeasureResult, withNullPerf;
import util.ptr : ptrTrustMe_mut;
import util.repr : Repr, jsonStrOfRepr, nameAndRepr, reprArr, reprNamedRecord, reprStr;
import util.sourceRange : Pos, reprRangeWithinFile;
import util.writer : finishWriterToCStr, writeChar, writeNat, writeQuotedStr, Writer, writeStatic;

// seems to be the required entry point
extern(C) void _start() {}

extern(C) @system pure ubyte* memset(return scope ubyte* dest, immutable int c, immutable size_t n) {
	// Can't reuse implementation from util.memory due to
	// https://github.com/ldc-developers/ldc/issues/3843#issuecomment-999247519
	foreach (immutable size_t i; 0 .. n)
		dest[i] = cast(ubyte) c;
	return dest;
}

extern(C) @system pure int memcmp(scope const ubyte* s1, scope const ubyte* s2, immutable size_t n) {
	foreach (immutable size_t i; 0 .. n)
		if (s1[i] != s2[i])
			return s1[i] < s2[i] ? -1 : 1;
	return 0;
}

extern(C) @system pure void* memcpy(return scope ubyte* dest, scope const ubyte* src, immutable size_t n) {
	return utilMemcpy(dest, src, n);
}

extern(C) @system pure void* memmove(return scope ubyte* dest, scope const ubyte* src, immutable size_t n) {
	return utilMemmove(dest, src, n);
}

extern(C) immutable(size_t) getGlobalBufferSizeBytes() {
	return globalBuffer.length * globalBuffer[0].sizeof;
}

@system extern(C) ubyte* getGlobalBufferPtr() {
	return cast(ubyte*) globalBuffer.ptr;
}

@system extern(C) Server* newServer(ubyte* allocStart, immutable size_t allocLength) {
	RangeAlloc alloc = RangeAlloc(allocStart, allocLength);
	Server* ptr = allocateT!Server(alloc, 1);
	ptr.__ctor(alloc.move());
	return ptr;
}

@system extern(C) void addOrChangeFile(
	Server* server,
	immutable StorageKind storageKind,
	scope immutable CStr path,
	scope immutable CStr content,
) {
	addOrChangeFile(*server, storageKind, immutable SafeCStr(path), immutable SafeCStr(content));
}

@system extern(C) void deleteFile(Server* server, immutable StorageKind storageKind, scope immutable CStr path) {
	deleteFile(*server, storageKind, immutable SafeCStr(path));
}

@system extern(C) immutable(CStr) getFile(
	Server* server,
	immutable StorageKind storageKind,
	scope immutable CStr path,
) {
	return getFile(*server, storageKind, immutable SafeCStr(path)).ptr;
}

@system extern(C) immutable(CStr) getTokens(
	ubyte* resultStart, immutable size_t resultLength,
	Server* server,
	immutable StorageKind storageKind,
	scope immutable CStr path,
) {
	RangeAlloc resultAlloc = RangeAlloc(resultStart, resultLength);
	immutable Token[] tokens = withNullPerf!(immutable Token[], (scope ref Perf perf) =>
		getTokens(resultAlloc, perf, *server, storageKind, immutable SafeCStr(path)));
	immutable Repr repr = reprTokens(resultAlloc, tokens);
	return jsonStrOfRepr(resultAlloc, server.allSymbols, repr).ptr;
}

@system extern(C) immutable(CStr) getParseDiagnostics(
	ubyte* resultStart,
	immutable size_t resultLength,
	Server* server,
	immutable StorageKind storageKind,
	scope immutable CStr path,
) {
	RangeAlloc resultAlloc = RangeAlloc(resultStart, resultLength);
	immutable StrParseDiagnostic[] diags = withNullPerf!(immutable StrParseDiagnostic[], (scope ref Perf perf) =>
		getParseDiagnostics(resultAlloc, perf, *server, storageKind, immutable SafeCStr(path)));
	immutable Repr repr = reprParseDiagnostics(resultAlloc, diags);
	return jsonStrOfRepr(resultAlloc, server.allSymbols, repr).ptr;
}

@system extern(C) immutable(CStr) getHover(
	ubyte* resultStart,
	immutable size_t resultLength,
	Server* server,
	immutable StorageKind storageKind,
	scope immutable CStr path,
	immutable Pos pos,
) {
	RangeAlloc resultAlloc = RangeAlloc(resultStart, resultLength);
	return withNullPerf!(immutable SafeCStr, (scope ref Perf perf) =>
		getHover(perf, resultAlloc, *server, storageKind, immutable SafeCStr(path), pos)).ptr;
}

@system extern(C) immutable(CStr) run(
	ubyte* resultStart,
	immutable size_t resultLength,
	Server* server,
	scope immutable CStr path,
) {
	RangeAlloc resultAlloc = RangeAlloc(resultStart, resultLength);
	immutable FakeExternResult result = withWebPerf!(immutable FakeExternResult)((scope ref Perf perf) =>
		run(perf, resultAlloc, *server, immutable SafeCStr(path)));
	return writeRunResult(server.alloc, result);
}

// Not really pure, but JS doesn't know that
extern(C) pure immutable(ulong) getTimeNanos();
extern(C) void perfLog(
	immutable char* name,
	immutable ulong count,
	immutable ulong nanoseconds,
	immutable ulong bytesAllocated);

private:

@system immutable(T) withWebPerf(T)(
	scope immutable(T) delegate(scope ref Perf perf) @nogc nothrow cb,
) {
	scope Perf perf = Perf(() => getTimeNanos());
	immutable T res = cb(perf);
	eachMeasure(perf, (immutable SafeCStr name, immutable PerfMeasureResult m) {
		perfLog(name.ptr, m.count, m.nanoseconds, m.bytesAllocated);
	});
	return res;
}

// declaring as ulong[] to ensure it's word aligned
// Almost 2GB (which is size limit for a global array)
ulong[2047 * 1024 * 1024 / ulong.sizeof] globalBuffer;

immutable(Repr) reprParseDiagnostics(ref Alloc alloc, ref immutable StrParseDiagnostic[] a) {
	return reprArr(alloc, a, (ref immutable StrParseDiagnostic it) =>
		reprNamedRecord(alloc, "diagnostic", [
			nameAndRepr("range", reprRangeWithinFile(alloc, it.range)),
			nameAndRepr("message", reprStr(it.message))]));
}

immutable(CStr) writeRunResult(ref Alloc alloc, ref immutable FakeExternResult result) {
	Writer writer = Writer(ptrTrustMe_mut(alloc));
	writeStatic(writer, "{\"err\":");
	writeNat(writer, result.err.value);
	writeStatic(writer, ",\"stdout\":");
	writeQuotedStr(writer, result.stdout);
	writeStatic(writer, ",\"stderr\":");
	writeQuotedStr(writer, result.stderr);
	writeChar(writer, '}');
	return finishWriterToCStr(writer);
}
