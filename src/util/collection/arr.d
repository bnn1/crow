module util.collection.arr;

@safe @nogc pure nothrow:

import util.bools : Bool;
import util.ptr : Ptr;
import util.memory : myEmplace;

struct Arr(T) {
	private:
	T* begin_;
	immutable size_t size_;
}

immutable(Arr!T) arrOfRange(T)(immutable T* begin, immutable T* end) {
	assert(begin <= end);
	return immutable Arr!T(begin, end - begin);
}

immutable(Arr!T) emptyArr(T)() {
	return immutable Arr!T(null, 0);
}

@system immutable(T*) begin(T)(immutable Arr!T a) {
	return a.begin_;
}

immutable(size_t) size(T)(const Arr!T a) {
	return a.size_;
}

immutable(Bool) sizeEq(T, U)(ref const Arr!T a, ref const Arr!U b) {
	return Bool(size(a) == size(b));
}

immutable(Bool) empty(T)(immutable Arr!T a) {
	return Bool(a.size == 0);
}

@trusted Ptr!T ptrAt(T)(ref Arr!T a, immutable size_t index) {
	assert(index < a.size_);
	return Ptr!T(a.begin_ + index);
}

@trusted immutable(Ptr!T) ptrAt(T)(ref immutable Arr!T a, immutable size_t index) {
	assert(index < a.size_);
	return immutable Ptr!T(a.begin_ + index);
}

@trusted ref T at(T)(ref Arr!T a, immutable size_t index) {
	return ptrAt(a, index).deref;
}
@trusted ref immutable(T) at(T)(ref immutable Arr!T a, immutable size_t index) {
	return ptrAt(a, index).deref;
}

ref immutable(T) first(T)(ref immutable Arr!T a) {
	return a.at(0);
}

ref immutable(T) only(T)(ref immutable Arr!T a) {
	assert(a.size == 1);
	return a.first;
}

ref immutable(T) last(T)(ref immutable Arr!T a) {
	assert(a.size != 0);
	return a.at(a.size - 1);
}

@trusted T[] range(T)(Arr!T a) {
	return a.begin_[0..a.size_];
}
@trusted immutable(T[]) range(T)(immutable Arr!T a) {
	return a.begin_[0..a.size_];
}

@trusted PtrsRange!T ptrsRange(T)(ref immutable Arr!T a) {
	return PtrsRange!T(a.begin_, a.begin_ + a.size);
}

struct PtrsRange(T) {
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
