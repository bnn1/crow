module test.testByteReaderWriter;

@safe @nogc pure nothrow:

import test.testUtil : Test;
import util.collection.arr : begin;
import util.collection.byteReader : ByteReader, readU8, readU16, readU32, readU48, readU64;
import util.collection.byteWriter :
	ByteWriter,
	finishByteWriter,
	newByteWriter,
	pushU8,
	pushU16,
	pushU32,
	pushU48,
	pushU64;
import util.types : Nat8, Nat16, Nat32, Nat48, Nat64;
import util.util : verify;

@trusted void testByteReaderWriter(Debug)(ref Test!Debug test) {
	ByteWriter writer = newByteWriter(test.allocPtr);

	pushU8(writer, immutable Nat8(0xab));
	pushU16(writer, immutable Nat16(0xabcd));
	pushU32(writer, immutable Nat32(0xabcdef01));
	pushU48(writer, immutable Nat48(0xabcd, 0xef01, 0x2345));
	pushU64(writer, immutable Nat64(0x0123456789abcdef));

	immutable ubyte[] bytes = finishByteWriter(writer);

	ByteReader reader = ByteReader(begin(bytes));
	verify(readU8(reader) == immutable Nat8(0xab));
	verify(readU16(reader) == immutable Nat16(0xabcd));
	verify(readU32(reader) == immutable Nat32(0xabcdef01));
	verify(readU48(reader) == immutable Nat48(0xabcd, 0xef01, 0x2345));
	verify(readU64(reader) == immutable Nat64(0x0123456789abcdef));
}
