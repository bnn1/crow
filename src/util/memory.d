module util.memory;

@safe @nogc pure nothrow:

import util.alloc.alloc : Alloc, allocateT;
import util.ptr : Ptr;

@trusted void initMemory(T)(T* ptr, const T value) {
	*(cast(byte[T.sizeof]*) ptr) = *(cast(const byte[T.sizeof]*) &value);
}
@trusted void initMemory(T)(T* ptr, ref const T value) {
	*(cast(byte[T.sizeof]*) ptr) = *(cast(const byte[T.sizeof]*) &value);
}

@trusted void initMemory_mut(T)(T* ptr, ref T value) {
	*(cast(byte[T.sizeof]*) ptr) = *(cast(const byte[T.sizeof]*) &value);
}

@system ubyte* memcpy(return scope ubyte* dest, scope const ubyte* src, immutable size_t length) {
	return memmove(dest, src, length);
}

@system ubyte* memmove(return scope ubyte* dest, scope const ubyte* src, immutable size_t length) {
	foreach (immutable size_t i; 0 .. length)
		dest[i] = src[i];
	return dest;
}

@system ubyte* memset(return scope ubyte* dest, immutable ubyte value, immutable size_t length) {
	foreach (immutable size_t i; 0 .. length)
		dest[i] = value;
	return dest;
}

void overwriteMemory(T)(T* ptr, T value) {
	initMemory_mut!T(ptr, value);
}

@trusted immutable(Ptr!T) allocate(T)(ref Alloc alloc, immutable T value) {
	T* ptr = allocateT!T(alloc, 1);
	initMemory!T(ptr, value);
	return immutable Ptr!T(cast(immutable) ptr);
}

@trusted Ptr!T allocateMut(T)(ref Alloc alloc, T value) {
	T* ptr = allocateT!T(alloc, 1);
	initMemory_mut!T(ptr, value);
	return Ptr!T(ptr);
}
