module util.col.exactSizeArrBuilder;

@safe @nogc pure nothrow:

import util.alloc.alloc : Alloc, allocateT;
import util.col.arr : arrOfRange_mut;
import util.col.str : eachChar, SafeCStr, safeCStrSize;
import util.memory : initMemory_mut, memset;
import util.util : verify;

//TODO:MOVE
struct ExactSizeArrBuilder(T) {
	private:
	T* begin;
	T* cur;
	T* end;
}

immutable(size_t) exactSizeArrBuilderCurSize(T)(ref const ExactSizeArrBuilder!T a) {
	return a.cur - a.begin;
}

@trusted ExactSizeArrBuilder!T newExactSizeArrBuilder(T)(ref Alloc alloc, immutable size_t size) {
	T* begin = allocateT!T(alloc, size);
	return ExactSizeArrBuilder!T(begin, begin, begin + size);
}

@trusted void exactSizeArrBuilderAdd(T)(ref ExactSizeArrBuilder!T a, T value) {
	verify(a.cur < a.end);
	initMemory_mut!T(a.cur, value);
	a.cur++;
}

@trusted void add16(ref ExactSizeArrBuilder!ubyte a, immutable ushort value) {
	verify(a.cur + 2 <= a.end);
	ushort* ptr = cast(ushort*) a.cur;
	*ptr = value;
	a.cur = cast(ubyte*) (ptr + 1);
}

@trusted void add32(ref ExactSizeArrBuilder!ubyte a, immutable uint value) {
	verify(a.cur + 4 <= a.end);
	uint* ptr = cast(uint*) a.cur;
	*ptr = value;
	a.cur = cast(ubyte*) (ptr + 1);
}

@trusted void add64(ref ExactSizeArrBuilder!ubyte a, immutable ulong value) {
	verify(a.cur + 8 <= a.end);
	ulong* ptr = cast(ulong*) a.cur;
	*ptr = value;
	a.cur = cast(ubyte*) (ptr + 1);
}

void padTo(ref ExactSizeArrBuilder!ubyte a, immutable size_t desiredSize) {
	if (exactSizeArrBuilderCurSize(a) < desiredSize)
		add0Bytes(a, desiredSize - exactSizeArrBuilderCurSize(a));
	verify(exactSizeArrBuilderCurSize(a) == desiredSize);
}

@trusted void add0Bytes(ref ExactSizeArrBuilder!ubyte a, immutable size_t nBytes) {
	verify(a.cur + nBytes <= a.end);
	memset(a.cur, 0, nBytes);
	a.cur += nBytes;
}

@trusted void add64TextPtr(ref ExactSizeArrBuilder!ubyte a, immutable size_t textIndex) {
	add64(a, cast(immutable ulong) (a.begin + textIndex));
}

@trusted void addStringAndNulTerminate(ref ExactSizeArrBuilder!ubyte a, immutable SafeCStr value) {
	verify(a.cur + safeCStrSize(value) < a.end);
	eachChar(value, (immutable char c) @trusted {
		*a.cur = c;
		a.cur++;
	});
	*a.cur = '\0';
	a.cur++;
}

@trusted T[] finish(T)(ref ExactSizeArrBuilder!T a) {
	verify(a.cur == a.end);
	T[] res = arrOfRange_mut(a.begin, a.end);
	a.begin = null;
	a.cur = null;
	a.end = null;
	return res;
}
