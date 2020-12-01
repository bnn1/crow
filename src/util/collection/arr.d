module util.collection.arr;

@safe @nogc pure nothrow:

import util.bools : Bool;
import util.ptr : Ptr;
import util.memory : overwriteMemory;
import util.types : Nat8, Nat32, Nat64;
import util.util : verify;

struct ArrWithSize(T) {
	ubyte* sizeAndBegin_;
	@disable this();
	@system immutable this(immutable ubyte* p) { sizeAndBegin_ = p; }
}

@trusted immutable(Arr!T) toArr(T)(ref immutable ArrWithSize!T a) {
	immutable T* begin = cast(immutable T*) (a.sizeAndBegin_ + size_t.sizeof);
	immutable size_t size = *(cast(immutable size_t*) a.sizeAndBegin_);
	return immutable Arr!T(begin, size);
}

@trusted immutable(ArrWithSize!T) emptyArrWithSize(T)() {
	static immutable size_t zero = 0;
	return immutable ArrWithSize!T(cast(immutable ubyte*) &zero);
}

struct Arr(T) {
	private:
	T* begin_;
	size_t size_;
	@disable this();

	public:
	immutable this(immutable T* b, immutable size_t s) { begin_ = b; size_ = s; }
	const this(const T* b, immutable size_t s) { begin_ = b; size_ = s; }
	this(T* b, immutable size_t s) { begin_ = b; size_ = s; }
}

@system void freeArr(Alloc, T)(ref Alloc alloc, immutable Arr!T a) {
	alloc.freeBytes(cast(ubyte*) begin(a), size(a) * T.sizeof);
}

immutable(Arr!T) asImmutable(T)(Arr!(immutable T) a) {
	return immutable Arr!T(a.begin_, a.size_);
}

@trusted immutable(Arr!T) castImmutable(T)(Arr!T a) {
	return immutable Arr!T(cast(immutable) a.begin_, a.size_);
}

@trusted immutable(Arr!T) arrOfD(T)(return scope immutable T[] a) {
	return immutable Arr!T(a.ptr, a.length);
}

@system immutable(Arr!T) arrOfRange(T)(immutable T* begin, immutable T* end) {
	verify(begin <= end);
	return immutable Arr!T(begin, end - begin);
}

@system Arr!T arrOfRange_mut(T)(T* begin, T* end) {
	verify(begin <= end);
	return Arr!T(begin, end - begin);
}

immutable(Arr!T) emptyArr(T)() {
	return immutable Arr!T(null, 0);
}

Arr!T emptyArr_mut(T)() {
	return Arr!T(null, 0);
}

@system immutable(T*) begin(T)(immutable Arr!T a) {
	return a.begin_;
}
@system const(T*) begin(T)(const Arr!T a) {
	return a.begin_;
}
@system T* begin(T)(Arr!T a) {
	return a.begin_;
}

@system const(T*) end(T)(const Arr!T a) {
	return a.begin_ + a.size_;
}

immutable(Nat64) sizeNat(T)(const Arr!T a) {
	return immutable Nat64(a.size_);
}

immutable(size_t) size(T)(const Arr!T a) {
	return a.size_;
}

immutable(Bool) sizeEq(T, U)(const Arr!T a, const Arr!U b) {
	return immutable Bool(size(a) == size(b));
}

immutable(Bool) empty(T)(const Arr!T a) {
	return immutable Bool(a.size == 0);
}

@trusted Ptr!T ptrAt(T)(return scope ref Arr!T a, immutable size_t index) {
	verify(index < a.size_);
	return Ptr!T(a.begin_ + index);
}

@trusted const(Ptr!T) ptrAt(T)(const Arr!T a, immutable size_t index) {
	verify(index < a.size_);
	return const Ptr!T(a.begin_ + index);
}

@trusted immutable(Ptr!T) ptrAt(T)(immutable Arr!T a, immutable size_t index) {
	verify(index < a.size_);
	return immutable Ptr!T(a.begin_ + index);
}
@trusted ref T at(T)(ref Arr!T a, immutable size_t index) {
	verify(index < a.size_);
	return a.begin_[index];
}
@trusted ref const(T) at(T)(ref const Arr!T a, immutable size_t index) {
	verify(index < a.size_);
	return a.begin_[index];
}
@trusted ref immutable(T) at(T)(ref immutable Arr!T a, immutable Nat8 index) {
	return at(a, index.raw());
}
@trusted ref immutable(T) at(T)(ref immutable Arr!T a, immutable Nat32 index) {
	return at(a, index.raw());
}
@trusted ref immutable(T) at(T)(return scope ref immutable Arr!T a, immutable size_t index) {
	verify(index < a.size_);
	return a.begin_[index];
}

@trusted void setAt(T)(ref Arr!T a, immutable size_t index, T value) {
	verify(index < a.size_);
	overwriteMemory(a.begin_ + index, value);
}

ref immutable(T) first(T)(return scope ref immutable Arr!T a) {
	return at(a, 0);
}
ref const(T) first(T)(const Arr!T a) {
	return at(a, 0);
}
ref T first(T)(Arr!T a) {
	return at(a, 0);
}

ref immutable(T) only(T)(return scope ref immutable Arr!T a) {
	verify(size(a) == 1);
	return first(a);
}
ref const(T) only_const(T)(ref const Arr!T a) {
	verify(size(a) == 1);
	return first(a);
}

Ptr!T onlyPtr_mut(T)(ref Arr!T a) {
	verify(a.size == 1);
	return ptrAt(a, 0);
}

ref immutable(T) last(T)(ref immutable Arr!T a) {
	verify(a.size != 0);
	return at(a, a.size - 1);
}

@trusted T[] range(T)(Arr!T a) {
	return a.begin_[0..a.size_];
}
@trusted const(T[]) range(T)(const Arr!T a) {
	return a.begin_[0..a.size_];
}
@trusted immutable(T[]) range(T)(immutable Arr!T a) {
	return a.begin_[0..a.size_];
}

@trusted PtrsRange!T ptrsRange(T)(ref immutable Arr!T a) {
	return PtrsRange!T(a.begin_, a.begin_ + a.size);
}

private struct PtrsRange(T) {
	immutable(T)* begin;
	immutable(T)* end;

	bool empty() const {
		return begin >= end;
	}

	immutable(Ptr!T) front() const {
		return immutable Ptr!T(begin);
	}

	@trusted void popFront() {
		begin++;
	}
}
