module interpret.runBytecode;

@safe @nogc nothrow: // not pure

import interpret.bytecode : ByteCode, FnOp, matchOperation, Operation, StackOffset;
import interpret.bytecodeReader : ByteCodeReader, readerJump, readOperation, readerSwitch;
import interpret.opcode : OpCode;
import util.bools : Bool;
import util.collection.arr : begin, ptrAt;
import util.ptr : Ptr, ptrTrustMe;
import util.types : maxU64, u8, u16, u32, u64;
import util.util : todo, unreachable, verify;

//TODO:MOVE
struct GlobalAllocatedStack(T, size_t capacity) {
	@safe @nogc nothrow:

	static T[capacity] values = void;
	static size_t size = 0;

	immutable(Bool) isEmpty() {
		return immutable Bool(size == 0);
	}

	void push(T value) {
		verify(size != capacity);
		values[size] = value;
		size++;
	}

	immutable(T) peek(immutable u8 offset) {
		verify(offset + 1 < size);
		return values[size - 1 - offset];
	}

	void popN(immutable u8 n) {
		foreach (immutable size_t i; 0..n)
			pop();
	}

	immutable(T) pop() {
		verify(size != 0);
		size--;
		return values[size];
	}

	immutable(T) get(immutable u8 offset) {
		verify(offset + 1 < size);
		return values[size - 1 - offset];
	}

	void dup(immutable u8 offset) {
		verify(offset + 1 < size);
		verify(size != capacity);
		values[size] = values[size - 1 - offset];
		size++;
	}

	immutable(T) remove(immutable u8 offset) {
		verify(offset + 1 < size);
		immutable T res = values[size - 1 - offset];
		remove(offset, 1);
		return res;
	}

	void remove(immutable u8 offset, immutable u8 nEntries) {
		verify(nEntries != 0);
		verify(offset <= nEntries);
		verify(offset + 1 + nEntries < size);
		foreach (immutable size_t i; size - 1 - offset..size - nEntries)
			values[i] = values[i + nEntries];
		size -= nEntries;
	}
}

@system void run(ref immutable ByteCode byteCode) {
	Interpreter interpreter = Interpreter(ptrTrustMe(byteCode), ByteCodeReader(begin(byteCode.byteCode)));
	while (true) {
		final switch (step(interpreter)) {
			case StepResult.continue_:
				break;
			case StepResult.exit:
				return;
		}
	}
}

private:

enum StepResult {
	continue_,
	exit,
}

alias DataStack = GlobalAllocatedStack!(u64, 1024 * 4);

struct Interpreter {
	immutable Ptr!ByteCode byteCode;
	ByteCodeReader reader;
	DataStack dataStack;
	GlobalAllocatedStack!(immutable(OpCode)*, 1024) returnStack;
}

immutable(StepResult) step(ref Interpreter interpreter) {
	immutable Operation operation = readOperation(interpreter.reader);
	return matchOperation!(immutable StepResult)(
		operation,
		(ref immutable Operation.Call it) {
			call(interpreter, it.address);
			return StepResult.continue_;
		},
		(ref immutable Operation.CallFunPtr it) {
			call(interpreter, removeAtStackOffset(interpreter, it.stackOffsetOfFunPtr));
			return StepResult.continue_;
		},
		(ref immutable Operation.Dup it) {
			interpreter.dataStack.dup(it.offset.offset);
			return StepResult.continue_;
		},
		(ref immutable Operation.DupPartial it) {
			interpreter.dataStack.push(
				getBytes(interpreter.dataStack.get(it.entryOffset.offset), it.byteOffset, it.sizeBytes));
			return StepResult.continue_;
		},
		(ref immutable Operation.Fn it) {
			applyFn(interpreter, it.fnOp);
			return StepResult.continue_;
		},
		(ref immutable Operation.Jump it) {
			readerJump(interpreter.reader, it.offset);
			return StepResult.continue_;
		},
		(ref immutable Operation.PushValue it) {
			interpreter.dataStack.push(it.value);
			return StepResult.continue_;
		},
		(ref immutable Operation.Read it) {
			read(interpreter.dataStack, it.offset, it.size);
			return StepResult.continue_;
		},
		(ref immutable Operation.Remove it) {
			interpreter.dataStack.remove(it.offset.offset, it.nEntries);
			return StepResult.continue_;
		},
		(ref immutable Operation.Return) {
			if (interpreter.returnStack.isEmpty())
				return StepResult.exit;
			else {
				interpreter.reader.ptr = interpreter.returnStack.pop();
				return StepResult.continue_;
			}
		},
		(ref immutable Operation.Switch) {
			readerSwitch(interpreter.reader, interpreter.dataStack.pop());
			return StepResult.continue_;
		},
		(ref immutable Operation.Write it) {
			write(interpreter.dataStack, it.offset, it.size);
			return StepResult.continue_;
		});
}

@trusted void read(ref DataStack data, immutable u8 offset, immutable u8 size) {
	immutable u64* ptr = cast(immutable u64*) data.pop();
	if (size < 8) { //TODO: just have 2 different ops then
		data.push(readPartialBytes((cast(immutable u8*) ptr) + offset, size));
	} else {
		verify(size % 8 == 0);
		verify(offset % 8 == 0);
		foreach (immutable size_t i; 0..(size / 8))
			data.push((ptr + (offset / 8))[i]);
	}
}

@trusted void write(ref DataStack data, immutable u8 offset, immutable u8 size) {
	if (size < 8) { //TODO: just have 2 different ops then
		immutable u64 value = data.pop();
		u64* ptr = cast(u64*) data.pop();
		writePartialBytes((cast(u8*) ptr) + offset, value, size);
	} else {
		verify(size % 8 == 0);
		verify(offset % 8 == 0);
		immutable u8 sizeWords = size / 8;
		u64* ptr = (cast(u64*) data.peek(sizeWords)) + (offset / 8);
		foreach (immutable size_t i; 0..sizeWords)
			*ptr = data.peek(cast(immutable u8) (sizeWords - 1 - i));
		data.popN(sizeWords + 1);
	}
}

@trusted immutable(u64) readPartialBytes(immutable u8* ptr, immutable u8 size) {
	//TODO: Just have separate ops for separate sizes?
	switch (size) {
		case 1:
			return *(cast(immutable u8*) ptr);
		case 2:
			return *(cast(immutable u16*) ptr);
		case 4:
			return *(cast(immutable u32*) ptr);
		default:
			return unreachable!(immutable u64);
	}
}

@trusted void writePartialBytes(u8* ptr, immutable u64 value, immutable u8 size) {
	//TODO: Just have separate ops for separate sizes?
	switch (size) {
		case 1:
			*(cast(u8*) ptr) = cast(immutable u8) value;
			break;
		case 2:
			*(cast(u16*) ptr) = cast(immutable u16) value;
			break;
		case 4:
			*(cast(u32*) ptr) = cast(immutable u32) value;
			break;
		default:
			unreachable!void();
			break;
	}
}

void applyFn(ref Interpreter interpreter, immutable FnOp fn) {
	todo!void("!");
}

immutable(u64) getBytes(immutable u64 a, immutable u8 byteOffset, immutable u8 sizeBytes) {
	verify(byteOffset + sizeBytes <= 8);
	immutable u64 shift = 8 - sizeBytes - byteOffset;
	immutable u64 mask = maxU64 >> (8 - sizeBytes);
	return (a >> shift) & mask;
}

void call(ref Interpreter interpreter, immutable u64 address) {
	interpreter.returnStack.push(interpreter.reader.ptr);
	interpreter.reader.ptr = ptrAt(interpreter.byteCode.byteCode, address).rawPtr();
}

immutable(u64) removeAtStackOffset(ref Interpreter interpreter, immutable StackOffset offset) {
	return interpreter.dataStack.remove(offset.offset);
}

