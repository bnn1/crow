module interpret.generateBytecode;

@safe @nogc pure nothrow:

import constant : Constant, matchConstant;
import interpret.bytecode :
	ByteCode,
	ByteCodeIndex,
	ByteCodeSource,
	DynCallType,
	ExternOp,
	FileToFuns,
	FnOp,
	FunNameAndPos,
	stackEntrySize;
import interpret.bytecodeWriter :
	ByteCodeWriter,
	nextByteCodeIndex,
	fillDelayedCall,
	fillDelayedSwitchEntry,
	fillInJumpDelayed,
	finishByteCode,
	getNextStackEntry,
	newByteCodeWriter,
	setNextStackEntry,
	setStackEntryAfterParameters,
	StackEntries,
	StackEntry,
	writeAddConstantNat64,
	writeAssertStackSize,
	writeAssertUnreachable,
	writeCallDelayed,
	writeCallFunPtr,
	writeDupEntries,
	writeDupEntry,
	writeDupPartial,
	writeExtern,
	writeExternDynCall,
	writeFn,
	writeFnHardFail,
	writeMulConstantNat64,
	writePushConstant,
	writePushConstantPointer,
	writePushEmptySpace,
	writePushFunPtrDelayed,
	writeJump,
	writeJumpDelayed,
	writePack,
	writeStackRef,
	writeRead,
	writeRemove,
	writeReturn,
	writeSwitchDelay,
	writeWrite;
import interpret.debugging : writeFunName, writeType;
import interpret.generateText : generateText, getTextInfoForArray, getTextPointer, TextAndInfo, TextArrInfo;
import interpret.typeLayout : layOutTypes, nStackEntriesForType, sizeOfType, TypeLayout, walkRecordFields;
import lowModel :
	asLocalRef,
	asNonFunPtrType,
	asParamRef,
	asRecordFieldAccess,
	asRecordType,
	asUnionType,
	firstRegularParamIndex,
	isLocalRef,
	isParamRef,
	isRecordFieldAccess,
	LowExpr,
	LowExprKind,
	LowField,
	LowFun,
	LowFunBody,
	LowFunExprBody,
	lowFunRange,
	LowFunIndex,
	LowLocal,
	LowParam,
	LowProgram,
	LowRecord,
	LowType,
	lowTypeEqual,
	matchLowExprKind,
	matchLowFunBody,
	matchLowType,
	PrimitiveType;
import model : FunDecl, Module, name, Program, range;
import util.alloc.stackAlloc : StackAlloc;
import util.bools : Bool, False, True;
import util.collection.arr : Arr, at, range, size, sizeNat;
import util.collection.arrUtil : map, mapOpWithIndex;
import util.collection.fullIndexDict :
	FullIndexDict,
	fullIndexDictEach,
	fullIndexDictGet,
	fullIndexDictOfArr,
	fullIndexDictSize,
	mapFullIndexDict;
import util.collection.mutDict : addToMutDict, mustDelete, mustGetAt_mut, MutDict;
import util.collection.mutIndexMultiDict :
	MutIndexMultiDict,
	mutIndexMultiDictAdd,
	mutIndexMultiDictMustGetAt,
	newMutIndexMultiDict;
import util.collection.str : Str, strEqLiteral;
import util.opt : force, has, none, Opt, some;
import util.ptr : comparePtr, Ptr, ptrTrustMe, ptrTrustMe_mut;
import util.print : print;
import util.sourceRange : FileIndex;
import util.types : Nat8, Nat16, Nat32, Nat64, safeSizeTToU8, zero;
import util.util : divRoundUp, todo, unreachable, verify;
import util.writer : finishWriterToCStr, writeChar, Writer, writeStatic;

immutable(ByteCode) generateBytecode(CodeAlloc)(
	ref CodeAlloc codeAlloc,
	ref immutable Program modelProgram,
	ref immutable LowProgram program,
) {
	alias TempAlloc = StackAlloc!("generateBytecode", 1024 * 1024);
	TempAlloc tempAlloc;

	immutable TypeLayout typeLayout = layOutTypes(tempAlloc, program);
	immutable TextAndInfo text = generateText(codeAlloc, tempAlloc, program, typeLayout, program.allConstants);

	MutIndexMultiDict!(LowFunIndex, ByteCodeIndex) funToReferences =
		newMutIndexMultiDict!(LowFunIndex, ByteCodeIndex)(tempAlloc, fullIndexDictSize(program.allFuns));

	ByteCodeWriter!CodeAlloc writer = newByteCodeWriter(ptrTrustMe_mut(codeAlloc));

	immutable FullIndexDict!(LowFunIndex, ByteCodeIndex) funToDefinition =
		mapFullIndexDict!(LowFunIndex, ByteCodeIndex, LowFun, TempAlloc)(
			tempAlloc,
			program.allFuns,
			(immutable LowFunIndex funIndex, ref immutable LowFun fun) {
				immutable ByteCodeIndex funPos = nextByteCodeIndex(writer);
				generateBytecodeForFun(tempAlloc, writer, funToReferences, typeLayout, text, program, funIndex, fun);
				return funPos;
		});

	fullIndexDictEach(funToDefinition, (immutable LowFunIndex index, ref immutable ByteCodeIndex definition) {
		foreach (immutable ByteCodeIndex reference; range(mutIndexMultiDictMustGetAt(funToReferences, index)))
			fillDelayedCall(writer, reference, definition);
	});

	return finishByteCode(
		writer,
		text.text,
		fullIndexDictGet(funToDefinition, program.main),
		fileToFuns(codeAlloc, modelProgram));
}

private:

immutable(FileToFuns) fileToFuns(Alloc)(ref Alloc alloc, ref immutable Program program) {
	immutable FullIndexDict!(FileIndex, Ptr!Module) modulesDict =
		fullIndexDictOfArr!(FileIndex, Ptr!Module)(program.allModules);
	return mapFullIndexDict!(FileIndex, Arr!FunNameAndPos, Ptr!Module, Alloc)(
		alloc,
		modulesDict,
		(immutable FileIndex, ref immutable Ptr!Module module_) =>
			map(alloc, module_.funs, (ref immutable FunDecl it) =>
				immutable FunNameAndPos(name(it), range(it).range.start)));
}

immutable(Nat8) sizeOfType(ref const ExprCtx ctx, ref immutable LowType t) {
	return sizeOfType(ctx.typeLayout, t);
}

immutable(Nat8) nStackEntriesForType(ref const ExprCtx ctx, ref immutable LowType t) {
	return nStackEntriesForType(ctx.typeLayout, t);
}

immutable(Nat8) nStackEntriesForRecordType(ref const ExprCtx ctx, ref immutable LowType.Record t) {
	immutable LowType type = immutable LowType(t);
	return nStackEntriesForType(ctx, type);
}

immutable(Nat8) nStackEntriesForUnionType(ref const ExprCtx ctx, ref immutable LowType.Union t) {
	immutable LowType type = immutable LowType(t);
	return nStackEntriesForType(ctx, type);
}

void generateBytecodeForFun(TempAlloc, CodeAlloc)(
	ref TempAlloc tempAlloc,
	ref ByteCodeWriter!CodeAlloc writer,
	ref MutIndexMultiDict!(LowFunIndex, ByteCodeIndex) funToReferences,
	ref immutable TypeLayout typeLayout,
	ref immutable TextAndInfo textInfo,
	ref immutable LowProgram program,
	immutable LowFunIndex funIndex,
	ref immutable LowFun fun,
) {
	Nat16 stackEntry = Nat16(0);
	immutable Arr!StackEntries parameters = map!StackEntries(
		tempAlloc,
		fun.params,
		(ref immutable LowParam it) {
			immutable StackEntry start = immutable StackEntry(stackEntry);
			immutable Nat8 n = nStackEntriesForType(typeLayout, it.type);
			stackEntry += n.to16();
			return immutable StackEntries(start, n);
		});
	immutable StackEntry stackEntryAfterParameters = immutable StackEntry(stackEntry);
	setStackEntryAfterParameters(writer, stackEntryAfterParameters);
	immutable Nat8 returnEntries = nStackEntriesForType(typeLayout, fun.returnType);
	immutable ByteCodeSource source = immutable ByteCodeSource(funIndex, lowFunRange(fun).range.start);

	debug {
		if (false) {
			Writer!TempAlloc w = Writer!TempAlloc(ptrTrustMe_mut(tempAlloc));
			writeStatic(w, "Generating bytecode for function ");
			writeFunName(w, program, fun);
			writeChar(w, '\n');
			print(finishWriterToCStr(w));
		}
	}

	matchLowFunBody!void(
		fun.body_,
		(ref immutable LowFunBody.Extern body_) {
			generateExternCall(tempAlloc, writer, funIndex, fun, body_);
		},
		(ref immutable LowFunExprBody body_) {
			// Note: not doing it for locals because they might be unrelated and occupy the same stack entry
			immutable size_t firstRegularParameterIndex = firstRegularParamIndex(fun);
			immutable StackEntry regularParametersStart = firstRegularParameterIndex == size(parameters)
				? stackEntryAfterParameters
				: at(parameters, firstRegularParameterIndex).start;
			ExprCtx ctx = ExprCtx(
				ptrTrustMe(program),
				ptrTrustMe(typeLayout),
				ptrTrustMe(textInfo),
				funIndex,
				returnEntries,
				ptrTrustMe_mut(funToReferences),
				nextByteCodeIndex(writer),
				regularParametersStart,
				parameters);
			generateExpr(tempAlloc, writer, ctx, body_.expr);
			verify(stackEntryAfterParameters.entry + returnEntries.to16() == getNextStackEntry(writer).entry);
			writeRemove(
				writer,
				source,
				immutable StackEntries(
					immutable StackEntry(immutable Nat16(0)),
					stackEntryAfterParameters.entry.to8()));
		});
	verify(getNextStackEntry(writer).entry == returnEntries.to16());
	writeReturn(writer, source);
	setNextStackEntry(writer, immutable StackEntry(immutable Nat16(0)));
}

void generateExternCall(TempAlloc, CodeAlloc)(
	ref TempAlloc tempAlloc,
	ref ByteCodeWriter!CodeAlloc writer,
	immutable LowFunIndex funIndex,
	ref immutable LowFun fun,
	ref immutable LowFunBody.Extern a,
) {
	immutable ByteCodeSource source = immutable ByteCodeSource(funIndex, lowFunRange(fun).range.start);
	immutable Opt!ExternOp op = externOpFromName(a.externName);
	if (has(op))
		writeExtern(writer, source, force(op));
	else {
		immutable Arr!DynCallType parameterTypes = map(tempAlloc, fun.params, (ref immutable LowParam it) =>
			toDynCallType(it.type));
		immutable DynCallType returnType = toDynCallType(fun.returnType);
		writeExternDynCall(writer, source, a.externName, returnType, parameterTypes);
	}
	writeReturn(writer, source);
}

immutable(DynCallType) toDynCallType(ref immutable LowType a) {
	return matchLowType!(immutable DynCallType)(
		a,
		(immutable LowType.ExternPtr) =>
			DynCallType.pointer,
		(immutable LowType.FunPtr) =>
			DynCallType.pointer,
		(immutable LowType.NonFunPtr) =>
			DynCallType.pointer,
		(immutable PrimitiveType it) {
			final switch (it) {
				case PrimitiveType.bool_:
					return DynCallType.bool_;
				case PrimitiveType.char_:
					return DynCallType.char_;
				case PrimitiveType.float64:
					return DynCallType.float64;
				case PrimitiveType.int8:
					return DynCallType.int8;
				case PrimitiveType.int16:
					return DynCallType.int16;
				case PrimitiveType.int32:
					return DynCallType.int32;
				case PrimitiveType.int64:
					return DynCallType.int64;
				case PrimitiveType.nat8:
					return DynCallType.nat8;
				case PrimitiveType.nat16:
					return DynCallType.nat16;
				case PrimitiveType.nat32:
					return DynCallType.nat32;
				case PrimitiveType.nat64:
					return DynCallType.nat64;
				case PrimitiveType.void_:
					return DynCallType.void_;
			}
		},
		(immutable LowType.Record) =>
			unreachable!(immutable DynCallType),
		(immutable LowType.Union) =>
			unreachable!(immutable DynCallType));
}

immutable(Opt!ExternOp) externOpFromName(immutable Str a) {
	return strEqLiteral(a, "free")
			? some(ExternOp.free)
		: strEqLiteral(a, "get_nprocs")
			? some(ExternOp.getNProcs)
		: strEqLiteral(a, "longjmp")
			? some(ExternOp.longjmp)
		: strEqLiteral(a, "malloc")
			? some(ExternOp.malloc)
		: strEqLiteral(a, "pthread_create")
			? some(ExternOp.pthreadCreate)
		: strEqLiteral(a, "pthread_join")
			? some(ExternOp.pthreadJoin)
		: strEqLiteral(a, "pthread_yield")
			? some(ExternOp.pthreadYield)
		: strEqLiteral(a, "setjmp")
			? some(ExternOp.setjmp)
		: strEqLiteral(a, "write")
			? some(ExternOp.write)
		: none!ExternOp;
}


struct ExprCtx {
	immutable Ptr!LowProgram program;
	immutable Ptr!TypeLayout typeLayout;
	immutable Ptr!TextAndInfo textInfo;
	immutable LowFunIndex curFunIndex;
	immutable Nat8 returnTypeSizeInStackEntries;
	Ptr!(MutIndexMultiDict!(LowFunIndex, ByteCodeIndex)) funToReferences;
	immutable ByteCodeIndex startOfCurrentFun;
	immutable StackEntry regularParametersStart;
	immutable Arr!StackEntries parameterEntries;
	MutDict!(immutable Ptr!LowLocal, immutable StackEntries, comparePtr!LowLocal) localEntries;
}

void generateExpr(CodeAlloc, TempAlloc)(
	ref TempAlloc tempAlloc,
	ref ByteCodeWriter!CodeAlloc writer,
	ref ExprCtx ctx,
	ref immutable LowExpr expr,
) {
	immutable ByteCodeSource source = immutable ByteCodeSource(ctx.curFunIndex, expr.source.range.start);
	//writeAssertStackSize(writer, source);
	return matchLowExprKind(
		expr.kind,
		(ref immutable LowExprKind.Call it) {
			immutable StackEntry stackEntryBeforeArgs = getNextStackEntry(writer);
			immutable Nat8 expectedStackEffect = nStackEntriesForType(ctx, expr.type);
			generateArgs(tempAlloc, writer, ctx, it.args);
			registerFunAddress(tempAlloc, ctx, it.called,
				writeCallDelayed(writer, source, stackEntryBeforeArgs, expectedStackEffect));
			verify(stackEntryBeforeArgs.entry + expectedStackEffect.to16() == getNextStackEntry(writer).entry);
		},
		(ref immutable LowExprKind.CreateRecord it) {
			generateCreateRecord(tempAlloc, writer, ctx, asRecordType(expr.type), source, it);
		},
		(ref immutable LowExprKind.ConvertToUnion it) {
			generateConvertToUnion(tempAlloc, writer, ctx, asUnionType(expr.type), source, it);
		},
		(ref immutable LowExprKind.FunPtr it) {
			registerFunAddress(tempAlloc, ctx, it.fun, writePushFunPtrDelayed(writer, source));
		},
		(ref immutable LowExprKind.Let it) {
			immutable StackEntries localEntries =
				immutable StackEntries(getNextStackEntry(writer), nStackEntriesForType(ctx, it.local.type));
			generateExpr(tempAlloc, writer, ctx, it.value);
			verify(getNextStackEntry(writer).entry == localEntries.start.entry + localEntries.size.to16());
			addToMutDict(tempAlloc, ctx.localEntries, it.local, localEntries);
			generateExpr(tempAlloc, writer, ctx, it.then);
			mustDelete(ctx.localEntries, it.local);
			writeRemove(writer, source, localEntries);
		},
		(ref immutable LowExprKind.LocalRef it) {
			immutable StackEntries entries = mustGetAt_mut(ctx.localEntries, it.local);
			if (!zero(entries.size))
				writeDupEntries(writer, source, entries);
		},
		(ref immutable LowExprKind.Match it) {
			//debug {
			//	import core.stdc.stdio : printf;
			//	printf("generating match\n");
			//}

			immutable StackEntry startStack = getNextStackEntry(writer);
			generateExpr(tempAlloc, writer, ctx, it.matchedValue);
			// Move the union kind to top of stack
			writeDupEntry(writer, source, startStack);
			writeRemove(writer, source, immutable StackEntries(startStack, immutable Nat8(1)));
			// Get the kind (always the first entry)
			immutable ByteCodeIndex indexOfFirstCaseOffset = writeSwitchDelay(writer, source, sizeNat(it.cases).to8());
			// Start of the union values is where the kind used to be.
			immutable StackEntry stackAfterMatched = getNextStackEntry(writer);
			immutable StackEntries matchedEntriesWithoutKind =
				immutable StackEntries(startStack, (stackAfterMatched.entry - startStack.entry).to8());
			immutable Arr!ByteCodeIndex delayedGotos = mapOpWithIndex!ByteCodeIndex(
				tempAlloc,
				it.cases,
				(immutable size_t caseIndex, ref immutable LowExprKind.Match.Case case_) {
					fillDelayedSwitchEntry(writer, indexOfFirstCaseOffset, immutable Nat8(safeSizeTToU8(caseIndex)));
					nextByteCodeIndex(writer);
					if (has(case_.local)) {
						immutable Nat8 nEntries = nStackEntriesForType(ctx, force(case_.local).type);
						verify(nEntries <= matchedEntriesWithoutKind.size);
						addToMutDict(
							tempAlloc,
							ctx.localEntries,
							force(case_.local),
							immutable StackEntries(matchedEntriesWithoutKind.start, nEntries));
					}
					generateExpr(tempAlloc, writer, ctx, case_.then);
					if (has(case_.local))
						mustDelete(ctx.localEntries, force(case_.local));
					if (caseIndex != size(it.cases) - 1) {
						setNextStackEntry(writer, stackAfterMatched);
						return some(writeJumpDelayed(writer, source));
					} else
						// For the last one, don't reset the stack as by the end one of the cases will have run.
						// Last one doesn't need a jump, just continues straight into the code after it.
						return none!ByteCodeIndex;
				});
			foreach (immutable ByteCodeIndex jumpIndex; range(delayedGotos))
				fillInJumpDelayed(writer, jumpIndex);
			writeRemove(writer, source, matchedEntriesWithoutKind);
		},
		(ref immutable LowExprKind.ParamRef it) {
			immutable StackEntries entries = at(ctx.parameterEntries, it.index.index);
			if (!zero(entries.size))
				writeDupEntries(writer, source, entries);
		},
		(ref immutable LowExprKind.PtrCast it) {
			generateExpr(tempAlloc, writer, ctx, it.target);
		},
		(ref immutable LowExprKind.RecordFieldAccess it) {
			generateRecordFieldAccess(tempAlloc, writer, ctx, source, it);
		},
		(ref immutable LowExprKind.RecordFieldSet it) {
			immutable StackEntry before = getNextStackEntry(writer);
			verify(it.targetIsPointer);
			generateExpr(tempAlloc, writer, ctx, it.target);
			immutable StackEntry mid = getNextStackEntry(writer);
			generateExpr(tempAlloc, writer, ctx, it.value);
			immutable FieldOffsetAndSize offsetAndSize =
				getFieldOffsetAndSize(ctx, it.record, immutable Nat8(it.fieldIndex));
			verify(
				mid.entry + divRoundUp(offsetAndSize.size, stackEntrySize).to16() ==
					getNextStackEntry(writer).entry);
			writeWrite(writer, source, offsetAndSize.offset, offsetAndSize.size);
			verify(getNextStackEntry(writer) == before);
		},
		(ref immutable LowExprKind.Seq it) {
			generateExpr(tempAlloc, writer, ctx, it.first);
			generateExpr(tempAlloc, writer, ctx, it.then);
		},
		(ref immutable LowExprKind.SizeOf it) {
			writePushConstant(writer, source, sizeOfType(ctx, it.type));
		},
		(ref immutable Constant it) {
			generateConstant(tempAlloc, writer, ctx, source, expr.type, it);
		},
		(ref immutable LowExprKind.Special0Ary it) {
			generateSpecial0Ary(writer, source, it);
		},
		(ref immutable LowExprKind.SpecialUnary it) {
			generateSpecialUnary(tempAlloc, writer, ctx, source, expr.type, it);
		},
		(ref immutable LowExprKind.SpecialBinary it) {
			generateSpecialBinary(tempAlloc, writer, ctx, source, it);
		},
		(ref immutable LowExprKind.SpecialTrinary it) {
			generateSpecialTrinary(tempAlloc, writer, ctx, source, it);
		},
		(ref immutable LowExprKind.SpecialNAry it) {
			generateSpecialNAry(tempAlloc, writer, ctx, source, expr.type, it);
		},
		(ref immutable LowExprKind.TailRecur it) {
			immutable StackEntry before = getNextStackEntry(writer);
			generateArgs(tempAlloc, writer, ctx, it.args);
			// Delete the original parameters and anything else on the stack except for the new args
			writeRemove(writer, source, immutable StackEntries(
				ctx.regularParametersStart,
				(before.entry - ctx.regularParametersStart.entry).to8()));
			writeJump(writer, source, ctx.startOfCurrentFun);
			// We'll continue to write code after the jump for cleaning up the stack, but it's unreachable.
			// Set the stack entry as if this was a regular call returning.
			setNextStackEntry(writer, immutable StackEntry(before.entry + ctx.returnTypeSizeInStackEntries.to16()));
			writeAssertUnreachable(writer, source);
		});
}

void generateArgs(CodeAlloc, TempAlloc)(
	ref TempAlloc tempAlloc,
	ref ByteCodeWriter!CodeAlloc writer,
	ref ExprCtx ctx,
	ref immutable Arr!LowExpr args,
) {
	foreach (ref immutable LowExpr arg; range(args))
		generateExpr(tempAlloc, writer, ctx, arg);
}

void generateCreateRecord(CodeAlloc, TempAlloc)(
	ref TempAlloc tempAlloc,
	ref ByteCodeWriter!CodeAlloc writer,
	ref ExprCtx ctx,
	immutable LowType.Record type,
	ref immutable ByteCodeSource source,
	ref immutable LowExprKind.CreateRecord it,
) {
	generateCreateRecordOrConstantRecord(
		tempAlloc,
		writer,
		ctx,
		type,
		source,
		(immutable size_t fieldIndex, ref immutable LowType fieldType) {
			immutable LowExpr arg = at(it.args, fieldIndex);
			verify(lowTypeEqual(arg.type, fieldType));
			generateExpr(tempAlloc, writer, ctx, arg);
		});
}

void generateCreateRecordOrConstantRecord(CodeAlloc, TempAlloc)(
	ref TempAlloc tempAlloc,
	ref ByteCodeWriter!CodeAlloc writer,
	ref const ExprCtx ctx,
	immutable LowType.Record type,
	ref immutable ByteCodeSource source,
	scope void delegate(immutable size_t, ref immutable LowType) @safe @nogc pure nothrow cbGenerateField,
) {
	immutable StackEntry before = getNextStackEntry(writer);

	walkRecordFields(
		tempAlloc,
		ctx.program,
		ctx.typeLayout,
		type,
		(ref immutable Arr!Nat8 fieldSizes) {
			// TODO:PERF: if generating a record constant, could do the pack at compile time
			writePack(writer, source, fieldSizes);
		},
		(immutable size_t fieldIndex, ref immutable LowType fieldType, immutable Nat8) {
			cbGenerateField(fieldIndex, fieldType);
		});

	immutable StackEntry after = getNextStackEntry(writer);
	immutable Nat8 stackEntriesForType = nStackEntriesForRecordType(ctx, type);
	verify(after.entry - before.entry == stackEntriesForType.to16());
}

void generateConvertToUnion(CodeAlloc, TempAlloc)(
	ref TempAlloc tempAlloc,
	ref ByteCodeWriter!CodeAlloc writer,
	ref ExprCtx ctx,
	immutable LowType.Union type,
	ref immutable ByteCodeSource source,
	ref immutable LowExprKind.ConvertToUnion it,
) {
	generateConvertToUnionOrConstantUnion(
		tempAlloc,
		writer,
		ctx,
		type,
		it.memberIndex,
		source,
		(ref immutable LowType) {
			generateExpr(tempAlloc, writer, ctx, it.arg);
		});
}

void generateConvertToUnionOrConstantUnion(CodeAlloc, TempAlloc)(
	ref TempAlloc tempAlloc,
	ref ByteCodeWriter!CodeAlloc writer,
	ref const ExprCtx ctx,
	immutable LowType.Union type,
	immutable ubyte memberIndex,
	ref immutable ByteCodeSource source,
	scope void delegate(ref immutable LowType) @safe @nogc pure nothrow cbGenerateMember,
) {
	immutable StackEntry before = getNextStackEntry(writer);
	immutable Nat8 size = nStackEntriesForUnionType(ctx, type);
	writePushConstant(writer, source, immutable Nat8(memberIndex));
	immutable LowType memberType = at(fullIndexDictGet(ctx.program.allUnions, type).members, memberIndex);
	cbGenerateMember(memberType);
	immutable StackEntry after = getNextStackEntry(writer);
	if (before.entry + size.to16() != after.entry) {
		// Some members of a union are smaller than the union.
		verify(before.entry + size.to16() > after.entry);
		writePushEmptySpace(writer, source, before.entry + size.to16() - after.entry);
	}
}

struct FieldOffsetAndSize {
	immutable Nat8 offset;
	immutable Nat8 size;
}

immutable(Nat8) getFieldOffset(ref const ExprCtx ctx, immutable LowType.Record record, immutable Nat8 fieldIndex) {
	immutable Arr!Nat8 fieldOffsets = fullIndexDictGet(ctx.typeLayout.fieldOffsets, record);
	return at(fieldOffsets, fieldIndex);
}

immutable(FieldOffsetAndSize) getFieldOffsetAndSize(
	ref const ExprCtx ctx,
	immutable LowType.Record record,
	immutable Nat8 fieldIndex,
) {
	immutable LowRecord r = fullIndexDictGet(ctx.program.allRecords, record);
	immutable LowField f = at(r.fields, fieldIndex);
	immutable Nat8 size = sizeOfType(ctx, f.type);
	//debug {
	//	import core.stdc.stdio : printf;
	//	alias TempAlloc = StackAlloc!("temp", 1024);
	//	TempAlloc tempAlloc;
	//	Writer!TempAlloc writer = Writer!TempAlloc(ptrTrustMe_mut(tempAlloc));
	//	writeRecordName(writer, r);
	//	writeChar(writer, '#');
	//	writeFieldName(writer, f);
	//	printf("getFieldOffsetAndSize of %s\n", finishWriterToCStr(writer));
	//}
	return immutable FieldOffsetAndSize(getFieldOffset(ctx, record, fieldIndex), size);
}

void registerFunAddress(TempAlloc)(
	ref TempAlloc tempAlloc,
	ref ExprCtx ctx,
	immutable LowFunIndex fun,
	immutable ByteCodeIndex index,
) {
	mutIndexMultiDictAdd(tempAlloc, ctx.funToReferences, fun, index);
}

void generateConstant(CodeAlloc, TempAlloc)(
	ref TempAlloc tempAlloc,
	ref ByteCodeWriter!CodeAlloc writer,
	ref const ExprCtx ctx,
	ref immutable ByteCodeSource source,
	ref immutable LowType type,
	ref immutable Constant constant,
) {
	debug {
		if (false) {
			Writer!TempAlloc w = Writer!TempAlloc(ptrTrustMe_mut(tempAlloc));
			writeStatic(w, "generateConstant of type ");
			writeType(w, ctx.program, type);
			writeChar(w, '\n');
			print(finishWriterToCStr(w));
		}
	}

	matchConstant!void(
		constant,
		(ref immutable Constant.ArrConstant it) {
			immutable TextArrInfo info = getTextInfoForArray(ctx.textInfo, ctx.program.allConstants, it);
			writePushConstant(writer, source, immutable Nat64(info.size));
			writePushConstantPointer(writer, source, info.textPtr);
		},
		(immutable Constant.BoolConstant it) {
			writeBoolConstant(writer, source, it.value);
		},
		(immutable Constant.Integral it) {
			writePushConstant(writer, source, immutable Nat64(it.value));
		},
		(immutable Constant.Null) {
			writePushConstant(writer, source, immutable Nat8(0));
		},
		(immutable Constant.Pointer it) {
			immutable ubyte* pointer = getTextPointer(ctx.textInfo, it);
			writePushConstantPointer(writer, source, pointer);
		},
		(ref immutable Constant.Record it) {
			generateCreateRecordOrConstantRecord(
				tempAlloc,
				writer,
				ctx,
				asRecordType(type),
				source,
				(immutable size_t argIndex, ref immutable LowType argType) {
					generateConstant(tempAlloc, writer, ctx, source, argType, at(it.args, argIndex));
				});
		},
		(ref immutable Constant.Union it) {
			generateConvertToUnionOrConstantUnion(
				tempAlloc,
				writer,
				ctx,
				asUnionType(type),
				it.memberIndex,
				source,
				(ref immutable LowType memberType) {
					generateConstant(tempAlloc, writer, ctx, source, memberType, it.arg);
				});
		},
		(immutable Constant.Void) {
			// do nothing
		});
}

void writeBoolConstant(CodeAlloc)(
	ref ByteCodeWriter!CodeAlloc writer,
	ref immutable ByteCodeSource source,
	immutable Bool value,
) {
	writePushConstant(writer, source, immutable Nat8(value ? 1 : 0));
}

void generateSpecial0Ary(CodeAlloc)(
	ref ByteCodeWriter!CodeAlloc writer,
	ref immutable ByteCodeSource source,
	ref immutable LowExprKind.Special0Ary it,
) {
	final switch (it.kind) {
		case LowExprKind.Special0Ary.Kind.getErrno:
			todo!void("generate getErrno");
	}
}

void generateSpecialUnary(CodeAlloc, TempAlloc)(
	ref TempAlloc tempAlloc,
	ref ByteCodeWriter!CodeAlloc writer,
	ref ExprCtx ctx,
	ref immutable ByteCodeSource source,
	ref immutable LowType type,
	ref immutable LowExprKind.SpecialUnary a,
) {
	void generateArg() {
		generateExpr(tempAlloc, writer, ctx, a.arg);
	}

	void fn(immutable FnOp fnOp) {
		generateArg();
		writeFn(writer, source, fnOp);
	}

	final switch (a.kind) {
		case LowExprKind.SpecialUnary.Kind.asAnyPtr:
		case LowExprKind.SpecialUnary.Kind.asRef:
		case LowExprKind.SpecialUnary.Kind.toNatFromPtr:
		case LowExprKind.SpecialUnary.Kind.unsafeInt64ToInt8:
		case LowExprKind.SpecialUnary.Kind.unsafeInt64ToInt16:
		case LowExprKind.SpecialUnary.Kind.unsafeInt64ToInt32:
		case LowExprKind.SpecialUnary.Kind.unsafeInt64ToNat64:
		case LowExprKind.SpecialUnary.Kind.unsafeNat64ToInt64:
		case LowExprKind.SpecialUnary.Kind.unsafeNat64ToNat8:
		case LowExprKind.SpecialUnary.Kind.unsafeNat64ToNat16:
		case LowExprKind.SpecialUnary.Kind.unsafeNat64ToNat32:
			// do nothing (doesn't change the bits, just their type)
			// Some of these widen, but all fit within the one stack entry so nothing to do
			// NOTE: we treat the upper bits of <64-bit types as arbitrary, so those are no-ops too
			generateArg();
			break;

		case LowExprKind.SpecialUnary.Kind.toIntFromInt16:
			fn(FnOp.intFromInt16);
			break;
		case LowExprKind.SpecialUnary.Kind.toIntFromInt32:
			fn(FnOp.intFromInt32);
			break;
		// Normal operations on <64-bit values treat other bits as garbage
		// (they may be written to, such as in a wrap-add operation that overflows)
		// So we must mask out just the lower bits now.
		case LowExprKind.SpecialUnary.Kind.toNatFromNat8:
			generateArg();
			writePushConstant(writer, source, Nat8.max);
			writeFn(writer, source, FnOp.bitwiseAnd);
			break;
		case LowExprKind.SpecialUnary.Kind.toNatFromNat16:
			generateArg();
			writePushConstant(writer, source, Nat16.max);
			writeFn(writer, source, FnOp.bitwiseAnd);
			break;
		case LowExprKind.SpecialUnary.Kind.toNatFromNat32:
			generateArg();
			writePushConstant(writer, source, Nat32.max);
			writeFn(writer, source, FnOp.bitwiseAnd);
			break;
		case LowExprKind.SpecialUnary.Kind.deref:
			generateArg();
			writeRead(writer, source, immutable Nat8(0), sizeOfType(ctx, type));
			break;
		case LowExprKind.SpecialUnary.Kind.hardFail:
			generateArg();
			writeFnHardFail(writer, source, nStackEntriesForType(ctx, type));
			break;
		case LowExprKind.SpecialUnary.Kind.not:
			fn(FnOp.not);
			break;
		case LowExprKind.SpecialUnary.Kind.ptrTo:
		case LowExprKind.SpecialUnary.Kind.refOfVal:
			generateRefOfVal(tempAlloc, writer, ctx, source, a.arg);
			break;
		case LowExprKind.SpecialUnary.Kind.toFloat64FromInt64: // FnOp.float64FromInt64
			fn(FnOp.float64FromInt64);
			break;
		case LowExprKind.SpecialUnary.Kind.toFloat64FromNat64:
			fn(FnOp.float64FromNat64);
			break;
		case LowExprKind.SpecialUnary.Kind.truncateToInt64FromFloat64:
			fn(FnOp.truncateToInt64FromFloat64);
			break;
	}
}

void generateRefOfVal(TempAlloc, CodeAlloc)(
	ref TempAlloc tempAlloc,
	ref ByteCodeWriter!CodeAlloc writer,
	ref ExprCtx ctx,
	ref immutable ByteCodeSource source,
	ref immutable LowExpr arg,
) {
	if (isLocalRef(arg.kind))
		writeStackRef(writer, source, mustGetAt_mut(ctx.localEntries, asLocalRef(arg.kind).local).start);
	else if (isParamRef(arg.kind))
		writeStackRef(writer, source, at(ctx.parameterEntries, asParamRef(arg.kind).index.index).start);
	else if (isRecordFieldAccess(arg.kind))
		generatePtrToRecordFieldAccess(tempAlloc, writer, ctx, source, asRecordFieldAccess(arg.kind));
	else {
		todo!void("ref-of-val -- not a local or record field");
	}
}

void generateRecordFieldAccess(TempAlloc, CodeAlloc)(
	ref TempAlloc tempAlloc,
	ref ByteCodeWriter!CodeAlloc writer,
	ref ExprCtx ctx,
	ref immutable ByteCodeSource source,
	ref immutable LowExprKind.RecordFieldAccess it,
) {
	immutable StackEntry targetEntry = getNextStackEntry(writer);
	generateExpr(tempAlloc, writer, ctx, it.target);
	immutable StackEntries targetEntries = immutable StackEntries(
		targetEntry,
		(getNextStackEntry(writer).entry - targetEntry.entry).to8());
	immutable FieldOffsetAndSize offsetAndSize = getFieldOffsetAndSize(ctx, it.record, immutable Nat8(it.fieldIndex));
	if (it.targetIsPointer) {
		if (zero(offsetAndSize.size))
			writeRemove(writer, source, targetEntries);
		else
			writeRead(writer, source, offsetAndSize.offset, offsetAndSize.size);
	} else {
		if (!zero(offsetAndSize.size)) {
			immutable StackEntry firstEntry =
				immutable StackEntry(targetEntry.entry + (offsetAndSize.offset / stackEntrySize).to16());
			if (zero(offsetAndSize.size % stackEntrySize)) {
				verify(zero(offsetAndSize.offset % stackEntrySize));
				immutable StackEntries entries =
					immutable StackEntries(firstEntry, offsetAndSize.size / stackEntrySize);
				writeDupEntries(writer, source, entries);
			} else {
				writeDupPartial(
					writer,
					source,
					firstEntry,
					offsetAndSize.offset % stackEntrySize,
					offsetAndSize.size);
			}
		}
		writeRemove(writer, source, targetEntries);
	}
}

void generatePtrToRecordFieldAccess(TempAlloc, CodeAlloc)(
	ref TempAlloc tempAlloc,
	ref ByteCodeWriter!CodeAlloc writer,
	ref ExprCtx ctx,
	ref immutable ByteCodeSource source,
	ref immutable LowExprKind.RecordFieldAccess it,
) {
	generateExpr(tempAlloc, writer, ctx, it.target);
	immutable Nat8 offset = getFieldOffset(ctx, it.record, immutable Nat8(it.fieldIndex));
	if (it.targetIsPointer) {
		if (!zero(offset))
			writeAddConstantNat64(writer, source, offset.to64());
	} else
		// This only works if it's a local .. or another recordfieldaccess
		todo!void("ptr-to-record-field-access");
}

void generateSpecialBinary(TempAlloc, CodeAlloc)(
	ref TempAlloc tempAlloc,
	ref ByteCodeWriter!CodeAlloc writer,
	ref ExprCtx ctx,
	ref immutable ByteCodeSource source,
	ref immutable LowExprKind.SpecialBinary a,
) {
	void fn(immutable FnOp fn) {
		generateExpr(tempAlloc, writer, ctx, a.left);
		generateExpr(tempAlloc, writer, ctx, a.right);
		writeFn(writer, source, fn);
	}

	final switch (a.kind) {
		case LowExprKind.SpecialBinary.Kind.addPtr:
		case LowExprKind.SpecialBinary.Kind.subPtrNat:
			immutable LowType pointee = asNonFunPtrType(a.left.type).pointee;
			generateExpr(tempAlloc, writer, ctx, a.left);
			generateExpr(tempAlloc, writer, ctx, a.right);
			immutable Nat8 pointeeSize = sizeOfType(ctx, pointee);
			if (pointeeSize != immutable Nat8(1))
				writeMulConstantNat64(writer, source, pointeeSize.to64());
			writeFn(
				writer,
				source,
				a.kind == LowExprKind.SpecialBinary.Kind.addPtr ? FnOp.wrapAddIntegral : FnOp.wrapSubIntegral);
			break;
		case LowExprKind.SpecialBinary.Kind.addFloat64:
			fn(FnOp.addFloat64);
			break;
		case LowExprKind.SpecialBinary.Kind.and:
			generateIf(
				tempAlloc,
				writer,
				ctx,
				source,
				a.left,
				() {
					generateExpr(tempAlloc, writer, ctx, a.right);
				},
				() {
					writeBoolConstant(writer, source, False);
				});
			break;
		case LowExprKind.SpecialBinary.Kind.unsafeBitShiftLeftNat64:
			fn(FnOp.unsafeBitShiftLeftNat64);
			break;
		case LowExprKind.SpecialBinary.Kind.unsafeBitShiftRightNat64:
			fn(FnOp.unsafeBitShiftRightNat64);
			break;
		case LowExprKind.SpecialBinary.Kind.bitwiseAndInt8:
		case LowExprKind.SpecialBinary.Kind.bitwiseAndInt16:
		case LowExprKind.SpecialBinary.Kind.bitwiseAndInt32:
		case LowExprKind.SpecialBinary.Kind.bitwiseAndInt64:
		case LowExprKind.SpecialBinary.Kind.bitwiseAndNat8:
		case LowExprKind.SpecialBinary.Kind.bitwiseAndNat16:
		case LowExprKind.SpecialBinary.Kind.bitwiseAndNat32:
		case LowExprKind.SpecialBinary.Kind.bitwiseAndNat64:
			fn(FnOp.bitwiseAnd);
			break;
		case LowExprKind.SpecialBinary.Kind.bitwiseOrInt8:
		case LowExprKind.SpecialBinary.Kind.bitwiseOrInt16:
		case LowExprKind.SpecialBinary.Kind.bitwiseOrInt32:
		case LowExprKind.SpecialBinary.Kind.bitwiseOrInt64:
		case LowExprKind.SpecialBinary.Kind.bitwiseOrNat8:
		case LowExprKind.SpecialBinary.Kind.bitwiseOrNat16:
		case LowExprKind.SpecialBinary.Kind.bitwiseOrNat32:
		case LowExprKind.SpecialBinary.Kind.bitwiseOrNat64:
			fn(FnOp.bitwiseOr);
			break;
		case LowExprKind.SpecialBinary.Kind.eqNat64:
		case LowExprKind.SpecialBinary.Kind.eqPtr:
			fn(FnOp.eqBits);
			break;
		case LowExprKind.SpecialBinary.Kind.lessBool:
		case LowExprKind.SpecialBinary.Kind.lessChar:
		case LowExprKind.SpecialBinary.Kind.lessNat8:
		case LowExprKind.SpecialBinary.Kind.lessNat16:
		case LowExprKind.SpecialBinary.Kind.lessNat32:
		case LowExprKind.SpecialBinary.Kind.lessNat64:
			fn(FnOp.lessNat);
			break;
		case LowExprKind.SpecialBinary.Kind.lessFloat64:
			fn(FnOp.lessFloat64);
			break;
		case LowExprKind.SpecialBinary.Kind.lessInt8:
			fn(FnOp.lessInt8);
			break;
		case LowExprKind.SpecialBinary.Kind.lessInt16:
			fn(FnOp.lessInt16);
			break;
		case LowExprKind.SpecialBinary.Kind.lessInt32:
			fn(FnOp.lessInt32);
			break;
		case LowExprKind.SpecialBinary.Kind.lessInt64:
			fn(FnOp.lessInt64);
			break;
		case LowExprKind.SpecialBinary.Kind.mulFloat64:
			fn(FnOp.mulFloat64);
			break;
		case LowExprKind.SpecialBinary.Kind.or:
			generateIf(
				tempAlloc,
				writer,
				ctx,
				source,
				a.left,
				() {
					writeBoolConstant(writer, source, True);
				},
				() {
					generateExpr(tempAlloc, writer, ctx, a.right);
				});
			break;
		case LowExprKind.SpecialBinary.Kind.subFloat64:
			fn(FnOp.subFloat64);
			break;
		case LowExprKind.SpecialBinary.Kind.wrapSubInt16:
		case LowExprKind.SpecialBinary.Kind.wrapSubInt32:
		case LowExprKind.SpecialBinary.Kind.wrapSubInt64:
		case LowExprKind.SpecialBinary.Kind.wrapSubNat8:
		case LowExprKind.SpecialBinary.Kind.wrapSubNat16:
		case LowExprKind.SpecialBinary.Kind.wrapSubNat32:
		case LowExprKind.SpecialBinary.Kind.wrapSubNat64:
			fn(FnOp.wrapSubIntegral);
			break;
		case LowExprKind.SpecialBinary.Kind.unsafeDivFloat64:
			fn(FnOp.unsafeDivFloat64);
			break;
		case LowExprKind.SpecialBinary.Kind.unsafeDivInt64:
			fn(FnOp.unsafeDivInt64);
			break;
		case LowExprKind.SpecialBinary.Kind.unsafeDivNat64:
			fn(FnOp.unsafeDivNat64);
			break;
		case LowExprKind.SpecialBinary.Kind.unsafeModNat64:
			fn(FnOp.unsafeModNat64);
			break;
		case LowExprKind.SpecialBinary.Kind.wrapAddInt16:
		case LowExprKind.SpecialBinary.Kind.wrapAddInt32:
		case LowExprKind.SpecialBinary.Kind.wrapAddInt64:
		case LowExprKind.SpecialBinary.Kind.wrapAddNat8:
		case LowExprKind.SpecialBinary.Kind.wrapAddNat16:
		case LowExprKind.SpecialBinary.Kind.wrapAddNat32:
		case LowExprKind.SpecialBinary.Kind.wrapAddNat64:
			fn(FnOp.wrapAddIntegral);
			break;
		case LowExprKind.SpecialBinary.Kind.wrapMulInt16:
		case LowExprKind.SpecialBinary.Kind.wrapMulInt32:
		case LowExprKind.SpecialBinary.Kind.wrapMulInt64:
		case LowExprKind.SpecialBinary.Kind.wrapMulNat16:
		case LowExprKind.SpecialBinary.Kind.wrapMulNat32:
		case LowExprKind.SpecialBinary.Kind.wrapMulNat64:
			fn(FnOp.wrapMulIntegral);
			break;
		case LowExprKind.SpecialBinary.Kind.writeToPtr:
			generateExpr(tempAlloc, writer, ctx, a.left);
			generateExpr(tempAlloc, writer, ctx, a.right);
			writeWrite(writer, source, immutable Nat8(0), sizeOfType(ctx, a.right.type));
			break;
	}
}

void generateSpecialTrinary(TempAlloc, CodeAlloc)(
	ref TempAlloc tempAlloc,
	ref ByteCodeWriter!CodeAlloc writer,
	ref ExprCtx ctx,
	ref immutable ByteCodeSource source,
	ref immutable LowExprKind.SpecialTrinary a,
) {
	final switch (a.kind) {
		case LowExprKind.SpecialTrinary.Kind.if_:
			generateIf(
				tempAlloc,
				writer,
				ctx,
				source,
				a.p0,
				() {
					generateExpr(tempAlloc, writer, ctx, a.p1);
				},
				() {
					generateExpr(tempAlloc, writer, ctx, a.p2);
				});
			break;
		case LowExprKind.SpecialTrinary.Kind.compareExchangeStrongBool:
			generateExpr(tempAlloc, writer, ctx, a.p0);
			generateExpr(tempAlloc, writer, ctx, a.p1);
			generateExpr(tempAlloc, writer, ctx, a.p2);
			writeFn(writer, source, FnOp.compareExchangeStrongBool);
			break;
	}
}

void generateIf(TempAlloc, CodeAlloc)(
	ref TempAlloc tempAlloc,
	ref ByteCodeWriter!CodeAlloc writer,
	ref ExprCtx ctx,
	ref immutable ByteCodeSource source,
	ref immutable LowExpr cond,
	scope void delegate() @safe @nogc pure nothrow cbThen,
	scope void delegate() @safe @nogc pure nothrow cbElse,
) {
	immutable StackEntry startStack = getNextStackEntry(writer);
	generateExpr(tempAlloc, writer, ctx, cond);
	immutable ByteCodeIndex delayed = writeSwitchDelay(writer, source, immutable Nat8(2));
	fillDelayedSwitchEntry(writer, delayed, immutable Nat8(0));
	cbElse();
	setNextStackEntry(writer, startStack);
	immutable ByteCodeIndex jumpIndex = writeJumpDelayed(writer, source);
	fillDelayedSwitchEntry(writer, delayed, immutable Nat8(1));
	cbThen();
	fillInJumpDelayed(writer, jumpIndex);
}

void generateSpecialNAry(TempAlloc, CodeAlloc)(
	ref TempAlloc tempAlloc,
	ref ByteCodeWriter!CodeAlloc writer,
	ref ExprCtx ctx,
	ref immutable ByteCodeSource source,
	ref immutable LowType type,
	ref immutable LowExprKind.SpecialNAry a,
) {
	final switch (a.kind) {
		case LowExprKind.SpecialNAry.Kind.callFunPtr:
			immutable StackEntry stackEntryBeforeArgs = getNextStackEntry(writer);
			generateArgs(tempAlloc, writer, ctx, a.args);
			writeCallFunPtr(writer, source, stackEntryBeforeArgs, nStackEntriesForType(ctx, type));
			break;
	}
}
