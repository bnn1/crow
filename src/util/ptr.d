module util.ptr;

@safe @nogc pure nothrow:

import util.col.arr : ArrWithSize, toArr;
import util.hash : Hasher, hashSizeT;
import util.opt : hasInvalid;
import util.util : verify;

struct TaggedPtr(E) {
	@safe @nogc pure nothrow:

	immutable this(immutable E tag, immutable void* ptr) {
		immutable size_t tagValue = cast(size_t) tag;
		immutable size_t ptrValue = cast(size_t) ptr;
		verify(tagValue < 4);
		// Ptr must be word-aligned.
		verify((ptrValue & 0b11) == 0);
		value = ptrValue | tagValue;
	}

	immutable(E) tag() immutable {
		return cast(E) (value & 0b11);
	}
	@system immutable(void*) ptr() immutable {
		return cast(immutable void*) cast(void*) (value & ~0b11);
	}
	@system immutable(T[]) arrWithSize(T)() immutable {
		return toArr(immutable ArrWithSize!T(cast(immutable ubyte*) ptr()));
	}

	private:
	size_t value;
}

// Non-null
struct Ptr(T) {
	static immutable Ptr!T INVALID = immutable Ptr!T(null, true);
	static Ptr!T INVALID_mut = Ptr!T(null, true);

	@safe @nogc pure nothrow:
	@disable this(); // No nulls!
	@trusted this(inout T* p) inout {
		ptr = cast(inout void*) p;
		verify(ptr != null);
	}
	@trusted this(immutable T* p, immutable bool) immutable {
		ptr = p;
	}
	@trusted this(T* p, immutable bool) {
		ptr = p;
	}

	// Using a void* greatly speeds up compile times. Don't know why.
	private void* ptr;

	ref T deref() {
		return *rawPtr();
	}
	ref const(T) deref() const {
		return *rawPtr();
	}
	ref immutable(T) deref() immutable {
		return *rawPtr();
	}

	@trusted T* rawPtr() { return cast(T*) ptr; }
	@trusted const(T*) rawPtr() const { return cast(const T*) ptr; }
	@trusted immutable(T*) rawPtr() immutable { return cast(immutable T*) ptr; }
}
static assert(hasInvalid!(Ptr!int));

// Only for use as a sentinel
static immutable Ptr!T nullPtr(T) = immutable Ptr!T(null, true);

@trusted immutable(Ptr!T) ptrTrustMe(T)(scope ref immutable T t) {
	return immutable Ptr!T(&t);
}

@trusted Ptr!T ptrTrustMe_mut(T)(scope ref T t) {
	return Ptr!T(&t);
}

@trusted const(Ptr!T) ptrTrustMe_const(T)(ref const T t) {
	return const Ptr!T(&t);
}

immutable(bool) ptrEquals(T)(const Ptr!T a, const Ptr!T b) {
	return a.ptr == b.ptr;
}

void hashPtr(T)(ref Hasher hasher, const Ptr!T a) {
	hashSizeT(hasher, cast(immutable size_t) a.rawPtr());
}

@trusted immutable(Ptr!T) castImmutable(T)(Ptr!T a) {
	return cast(immutable) a;
}

@trusted Ptr!T castMutable(T)(immutable Ptr!T a) {
	return cast(Ptr!T) a;
}
