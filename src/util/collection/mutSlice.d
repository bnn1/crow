module util.collection.mutSlice;

@safe @nogc pure nothrow:

import util.collection.arr : Arr;
import util.memory : overwriteMemory;

struct MutSlice(T) {
	T* begin_;
	size_t size_;
}

immutable(size_t) mutSliceSize(T)(ref const MutSlice!T a) {
	return a.size_;
}

@trusted ref const(T) mutSliceAt(T)(return scope ref const MutSlice!T a, immutable size_t index) {
	assert(index < mutSliceSize(a));
	return a.begin_[index];
}

@trusted void mutSliceSetAt(T)(ref MutSlice!T a, immutable size_t index, immutable T value) {
	assert(index < mutSliceSize(a));
	overwriteMemory(a.begin_ + index, value);
}

@trusted MutSlice!T mutSlice(T)(MutSlice!T a, immutable size_t lo, immutable size_t newSize) {
	assert(lo + newSize <= mutSliceSize(a));
	return MutSlice!T(a.begin_ + lo, newSize);
}

MutSlice!T mutSlice(T)(MutSlice!T a, immutable size_t lo) {
	assert(lo <= mutSliceSize(a));
	return mutSlice(a, lo, mutSliceSize(a) - lo);
}

@trusted MutSlice!T newUninitializedMutSlice(T, Alloc)(
	ref Alloc alloc,
	immutable size_t size,
) {
	return MutSlice!T(cast(T*) alloc.allocate(T.sizeof * size), size);
}

const(Arr!T) mutSliceTempAsArr(T)(ref const MutSlice!T a) {
	return const Arr!T(a.begin_, a.size_);
}

void mutSliceFill(T)(ref MutSlice!T a, immutable T value) {
	foreach (immutable size_t i; 0..mutSliceSize(a))
		mutSliceSetAt(a, i, value);
}