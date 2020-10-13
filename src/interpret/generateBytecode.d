module interpret.generateBytecode;

@safe @nogc pure nothrow:

import interpret.bytecode :
	addByteCodeIndex,
	ByteCode,
	ByteCodeIndex,
	ByteCodeOffset,
	FnOp,
	stackEntrySize,
	subtractByteCodeIndex;
import interpret.bytecodeWriter :
	ByteCodeWriter,
	curByteCodeIndex,
	fillDelayedU16,
	fillDelayedU32,
	fillInJumpDelayed,
	finishByteCode,
	getNextStackEntry,
	setNextStackEntry,
	setStackEntryAfterParameters,
	StackEntries,
	writeAddConstantNat64,
	writeCallDelayed,
	writeCallFunPtr,
	writeDup,
	writeDupPartial,
	writeFn,
	writeFnHardFail,
	writePushConstant,
	writePushConstantStr,
	writePushEmptySpace,
	writePushU32Delayed,
	writeJumpDelayed,
	writePack,
	writeStackRef,
	writeRead,
	writeRemove,
	writeReturn,
	writeSwitchDelay,
	writeWrite;
import lower.lowExprHelpers : genBool;
import lowModel :
	asLocalRef,
	asParamRef,
	asRecordFieldAccess,
	asRecordType,
	isLocalRef,
	isParamRef,
	isRecordFieldAccess,
	LowExpr,
	LowExprKind,
	LowField,
	LowFun,
	LowFunBody,
	LowFunExprBody,
	LowFunIndex,
	LowLocal,
	LowParam,
	LowProgram,
	LowRecord,
	LowType,
	LowUnion,
	matchLowExprKind,
	matchLowFunBody,
	matchLowType,
	matchSpecialConstant,
	PrimitiveType;
import util.alloc.stackAlloc : StackAlloc;
import util.bools : False, True;
import util.collection.arr : Arr, at, range, size;
import util.collection.arrUtil : arrMax, eachWithIndex, map, mapOpWithIndex, slice, sum, zip;
import util.collection.fullIndexDict :
	FullIndexDict,
	fullIndexDictEach,
	fullIndexDictGet,
	fullIndexDictOfArr,
	fullIndexDictSize,
	mapFullIndexDict;
import util.collection.fullIndexDictBuilder :
	finishFullIndexDict,
	FullIndexDictBuilder,
	fullIndexDictBuilderAdd,
	fullIndexDictBuilderHas,
	fullIndexDictBuilderOptGet,
	newFullIndexDictBuilder;
import util.collection.mutIndexDict;
import util.collection.mutDict : addToMutDict, mustDelete, mustGetAt_mut, MutDict;
import util.collection.mutIndexDict : MutIndexDict;
import util.collection.mutIndexMultiDict :
	MutIndexMultiDict,
	mutIndexMultiDictAdd,
	mutIndexMultiDictMustGetAt,
	newMutIndexMultiDict;
import util.collection.str : strEqLiteral;
import util.comparison : Comparison;
import util.opt : force, has, none, Opt, some;
import util.ptr : comparePtr, Ptr, ptrTrustMe, ptrTrustMe_mut;
import util.sourceRange : SourceRange;
import util.types : safeSizeTToU8, safeSizeTToU32, safeU32ToU8, u8;
import util.util : divRoundUp, roundUp, todo, verify;

immutable(ByteCode) generateBytecode(CodeAlloc)(ref CodeAlloc codeAlloc, ref immutable LowProgram program) {
	alias TempAlloc = StackAlloc!("generateBytecode", 1024 * 1024);
	TempAlloc tempAlloc;

	immutable TypeLayout typeLayout = layOutTypes(tempAlloc, program);

	MutIndexMultiDict!(LowFunIndex, ByteCodeIndex) funToReferences =
		newMutIndexMultiDict!(LowFunIndex, ByteCodeIndex)(tempAlloc, fullIndexDictSize(program.allFuns));

	ByteCodeWriter!CodeAlloc writer = ByteCodeWriter!CodeAlloc(ptrTrustMe_mut(codeAlloc));

	immutable FullIndexDict!(LowFunIndex, ByteCodeIndex) funToDefinition =
		mapFullIndexDict!(LowFunIndex, ByteCodeIndex, LowFun, TempAlloc)(
			tempAlloc,
			program.allFuns,
			(immutable LowFunIndex, ref immutable LowFun fun) {
				immutable ByteCodeIndex funPos = curByteCodeIndex(writer);
				generateBytecodeForFun(tempAlloc, writer, funToReferences, typeLayout, program, fun);
				return funPos;
		});

	fullIndexDictEach(funToDefinition, (immutable LowFunIndex index, ref immutable ByteCodeIndex definition) {
		foreach (immutable ByteCodeIndex reference; range(mutIndexMultiDictMustGetAt(funToReferences, index)))
			fillDelayedU32(writer, reference, definition);
	});

	immutable ByteCodeIndex mainIndex = todo!(immutable ByteCodeIndex)("mainIndex");

	return finishByteCode(writer, mainIndex);
}

private:

// NOTE: we should lay out structs so that no primitive field straddles multiple stack entries.
struct TypeLayout {
	// All in bytes
	immutable FullIndexDict!(LowType.Record, u8) recordSizes;
	immutable FullIndexDict!(LowType.Record, Arr!u8) fieldOffsets;
	immutable FullIndexDict!(LowType.Union, u8) unionSizes;
}

struct TypeLayoutBuilder {
	FullIndexDictBuilder!(LowType.Record, u8) resultSizes;
	FullIndexDictBuilder!(LowType.Record, Arr!u8) resultFieldOffsets;
	FullIndexDictBuilder!(LowType.Union, u8) unionSizes;
}

immutable(TypeLayout) layOutTypes(Alloc)(ref Alloc alloc, ref immutable LowProgram program) {
	TypeLayoutBuilder builder = TypeLayoutBuilder(
		newFullIndexDictBuilder!(LowType.Record, u8)(alloc, fullIndexDictSize(program.allRecords)),
		newFullIndexDictBuilder!(LowType.Record, Arr!u8)(alloc, fullIndexDictSize(program.allRecords)),
		newFullIndexDictBuilder!(LowType.Union, u8)(alloc, fullIndexDictSize(program.allUnions)));
	fullIndexDictEach(program.allRecords, (immutable LowType.Record index, ref immutable LowRecord record) {
		if (!fullIndexDictBuilderHas(builder.resultSizes, index))
			fillRecordSize!Alloc(alloc, program, index, record, builder);
	});
	fullIndexDictEach(program.allUnions, (immutable LowType.Union index, ref immutable LowUnion union_) {
		if (!fullIndexDictBuilderHas(builder.unionSizes, index))
			fillUnionSize!Alloc(alloc, program, index, union_, builder);
	});
	return immutable TypeLayout(
		finishFullIndexDict(builder.resultSizes),
		finishFullIndexDict(builder.resultFieldOffsets),
		finishFullIndexDict(builder.unionSizes));
}

immutable u8 fieldBoundary = 8;

immutable(u8) fillRecordSize(Alloc)(
	ref Alloc alloc,
	ref immutable LowProgram program,
	immutable LowType.Record index,
	ref immutable LowRecord record,
	ref TypeLayoutBuilder builder,
) {
	u8 offset = 0;
	immutable Arr!u8 fieldOffsets = map(alloc, record.fields, (ref immutable LowField field) {
		immutable u8 fieldSize = sizeOfType(alloc, program, field.type, builder);
		// If field would stretch across a boundary, move offset up to the next boundary
		immutable u8 mod = offset % fieldBoundary;
		if (mod != 0 && mod + fieldSize > fieldBoundary) {
			offset = roundUp(offset, fieldBoundary);
		}
		immutable u8 res = offset;
		offset += fieldSize;
		return res;
	});
	immutable u8 size = offset;
	fullIndexDictBuilderAdd(builder.resultSizes, index, size);
	fullIndexDictBuilderAdd(builder.resultFieldOffsets, index, fieldOffsets);
	return size;
}

immutable(u8) fillUnionSize(Alloc)(
	ref Alloc alloc,
	ref immutable LowProgram program,
	immutable LowType.Union index,
	ref immutable LowUnion union_,
	ref TypeLayoutBuilder builder,
) {
	immutable u8 maxMemberSize = arrMax(immutable u8(0), union_.members, (ref immutable LowType t) =>
		sizeOfType(alloc, program, t, builder));
	immutable u8 size = safeSizeTToU8(unionKindSize + maxMemberSize);
	fullIndexDictBuilderAdd(builder.unionSizes, index, size);
	return size;
}

immutable u8 externPtrSize = (void*).sizeof;
immutable u8 ptrSize = (void*).sizeof;
immutable u8 funPtrSize = 4;
immutable u8 unionKindSize = 8;

immutable(u8) sizeOfType(Alloc)(
	ref Alloc alloc,
	ref immutable LowProgram program,
	ref immutable LowType t,
	ref TypeLayoutBuilder builder,
) {
	return matchLowType!(immutable u8)(
		t,
		(immutable LowType.ExternPtr) => externPtrSize,
		(immutable LowType.FunPtr) => funPtrSize,
		(immutable LowType.NonFunPtr) => ptrSize,
		(immutable PrimitiveType it) => primitiveSize(it),
		(immutable LowType.Record index) {
			immutable Opt!u8 size = fullIndexDictBuilderOptGet(builder.resultSizes, index);
			return has(size)
				? force(size)
				: fillRecordSize(alloc, program, index, fullIndexDictGet(program.allRecords, index), builder);
		},
		(immutable LowType.Union index) {
			immutable Opt!u8 size = fullIndexDictBuilderOptGet(builder.unionSizes, index);
			return has(size)
				? force(size)
				: fillUnionSize(alloc, program, index, fullIndexDictGet(program.allUnions, index), builder);
		});
}

immutable(u8) sizeOfType(ref const ExprCtx ctx, ref immutable LowType t) {
	return sizeOfType(ctx.typeLayout, t);
}

immutable(u8) sizeOfType(ref immutable TypeLayout typeLayout, ref immutable LowType t) {
	return matchLowType!(immutable u8)(
		t,
		(immutable LowType.ExternPtr) =>
			externPtrSize,
		(immutable LowType.FunPtr) =>
			funPtrSize,
		(immutable LowType.NonFunPtr) =>
			ptrSize,
		(immutable PrimitiveType it) =>
			primitiveSize(it),
		(immutable LowType.Record index) =>
			fullIndexDictGet(typeLayout.recordSizes, index),
		(immutable LowType.Union index) =>
			fullIndexDictGet(typeLayout.unionSizes, index));
}

immutable(u8) primitiveSize(immutable PrimitiveType a) {
	final switch (a) {
		case PrimitiveType.void_:
			return 0;
		case PrimitiveType.bool_:
		case PrimitiveType.char_:
		case PrimitiveType.int8:
		case PrimitiveType.nat8:
			return 1;
		case PrimitiveType.int16:
		case PrimitiveType.nat16:
			return 2;
		case PrimitiveType.int32:
		case PrimitiveType.nat32:
			return 4;
		case PrimitiveType.float64:
		case PrimitiveType.int64:
		case PrimitiveType.nat64:
			return 8;
	}
}

immutable(u8) nStackEntriesForType(ref const ExprCtx ctx, ref immutable LowType t) {
	return nStackEntriesForType(ctx.typeLayout, t);
}

immutable(u8) nStackEntriesForType(ref immutable TypeLayout typeLayout, ref immutable LowType t) {
	return divRoundUp(sizeOfType(typeLayout, t), stackEntrySize);
}

void generateBytecodeForFun(TempAlloc, CodeAlloc)(
	ref TempAlloc tempAlloc,
	ref ByteCodeWriter!CodeAlloc writer,
	ref MutIndexMultiDict!(LowFunIndex, ByteCodeIndex) funToReferences,
	ref immutable TypeLayout typeLayout,
	ref immutable LowProgram program,
	ref immutable LowFun fun,
) {
	debug {
		immutable Str mn = fun.mangledName;
		printf("\n\n=== Start compiling fun: %.*s ===\n", cast(int) size(mn), begin(mn));
	}

	matchLowFunBody!void(
		fun.body_,
		(ref immutable LowFunBody.Extern body_) {
			generateExternCall(tempAlloc, writer, fun, body_);
		},
		(ref immutable LowFunExprBody body_) {
			uint stackEntry = 0;
			immutable Arr!StackEntries parameters = map!StackEntries(
				tempAlloc,
				fun.params,
				(ref immutable LowParam it) {
					immutable uint start = stackEntry;
					immutable uint n = nStackEntriesForType(typeLayout, it.type);
					stackEntry += n;
					return immutable StackEntries(start, n);
				});
			setStackEntryAfterParameters(writer, stackEntry);
			immutable uint stackEntryAfterParameters = stackEntry;
			// Note: not doing it for locals because they might be unrelated and occupy the same stack entry
			ExprCtx ctx = ExprCtx(
				ptrTrustMe(program),
				ptrTrustMe(typeLayout),
				ptrTrustMe_mut(funToReferences),
				parameters);
			generateExpr(tempAlloc, writer, ctx, body_.expr);
			writeReturn(writer);

			immutable uint returnEntries = nStackEntriesForType(typeLayout, fun.returnType);
			debug {
				printf("RETURNING: stackEntryAfterParameters: %d, returnEntries: %d, nextStackEntry: %d\n",
					stackEntryAfterParameters,
					returnEntries,
					getNextStackEntry(writer));
			}
			verify(stackEntryAfterParameters + returnEntries == getNextStackEntry(writer));
			writeRemove(writer, immutable StackEntries(0, safeU32ToU8(stackEntryAfterParameters)));
			verify(getNextStackEntry(writer) == returnEntries);
			setNextStackEntry(writer, 0);
		});
}

void generateExternCall(TempAlloc, CodeAlloc)(
	ref TempAlloc tempAlloc,
	ref ByteCodeWriter!CodeAlloc writer,
	ref immutable LowFun fun,
	ref immutable LowFunBody.Extern a,
) {
	if (strEqLiteral(fun.mangledName, "malloc")) {
		writeFn(writer, FnOp.malloc);
	}
}

struct ExprCtx {
	immutable Ptr!LowProgram program;
	immutable Ptr!TypeLayout typeLayout;
	Ptr!(MutIndexMultiDict!(LowFunIndex, ByteCodeIndex)) funToReferences;
	immutable Arr!StackEntries parameterEntries;
	MutDict!(immutable Ptr!LowLocal, immutable StackEntries, comparePtr!LowLocal) localEntries;
}

//TODO:KILL (for debug)
import core.stdc.stdio : printf;
import util.collection.arr : begin;
import util.collection.str : Str;

void generateExpr(CodeAlloc, TempAlloc)(
	ref TempAlloc tempAlloc,
	ref ByteCodeWriter!CodeAlloc writer,
	ref ExprCtx ctx,
	ref immutable LowExpr expr,
) {
	return matchLowExprKind(
		expr.kind,
		(ref immutable LowExprKind.Call it) {
			immutable uint stackEntryBeforeArgs = getNextStackEntry(writer);
			immutable uint expectedStackEffect = nStackEntriesForType(ctx, expr.type);

			debug {
				immutable Str mn = fullIndexDictGet(ctx.program.allFuns, it.called).mangledName;
				printf("START COMPILING CALL %.*s\n", cast(int) size(mn), begin(mn));
				printf("Stack before: %i\n", stackEntryBeforeArgs);
			}

			foreach (ref immutable LowExpr arg; range(it.args))
				generateExpr(tempAlloc, writer, ctx, arg);
			registerFunAddress(tempAlloc, ctx, it.called,
				writeCallDelayed(writer, stackEntryBeforeArgs, expectedStackEffect));

			debug {
				printf("DONE COMPILING CALL %.*s\n", cast(int) size(mn), begin(mn));
				printf("Stack after: %i\n", getNextStackEntry(writer));
			}
			verify(stackEntryBeforeArgs + expectedStackEffect == getNextStackEntry(writer));
		},
		(ref immutable LowExprKind.CreateRecord it) {
			debug {
				printf("\nCOMPILING CREATERECORD\n");
			}

			immutable uint before = getNextStackEntry(writer);

			void maybePack(immutable Opt!size_t packStart, immutable size_t packEnd) {
				if (has(packStart)) {
					debug {
						printf("Packing! start=%lu, end=%lu\n", force(packStart), packEnd);
						printf("Packing stack entry before: %d\n", getNextStackEntry(writer));
					}
					// Need to give the instruction the field sizes
					immutable Arr!u8 fieldSizes = map(
						tempAlloc,
						slice(it.args, force(packStart), packEnd - force(packStart)),
						(ref immutable LowExpr arg) => safeSizeTToU8(sizeOfType(ctx, arg.type)));
					writePack(writer, fieldSizes);
					debug {
						printf("Packing stack entry after: %d\n", getNextStackEntry(writer));
					}
				}
			}

			void recur(immutable Opt!size_t packStart, immutable size_t fieldIndex) {
				if (fieldIndex == size(it.args)) {
					maybePack(packStart, fieldIndex);
				} else {
					immutable size_t fieldSize = sizeOfType(ctx, at(it.args, fieldIndex).type);
					debug {
						printf("Compiling field %lu, size %lu\n", fieldIndex, fieldSize);
						printf("field kind is %d\n", cast(int)at(it.args, fieldIndex).kind.kind);
						printf("Cur stack entry: %d\n", getNextStackEntry(writer));
					}
					if (fieldSize < 8) {
						generateExpr(tempAlloc, writer, ctx, at(it.args, fieldIndex));
						recur(has(packStart) ? packStart : some(fieldIndex), fieldIndex + 1);
					} else {
						verify(fieldSize % 8 == 0);
						maybePack(packStart, fieldIndex);
						generateExpr(tempAlloc, writer, ctx, at(it.args, fieldIndex));
						recur(none!size_t, fieldIndex + 1);
					}
				}
			}

			recur(none!size_t, 0);

			immutable uint after = getNextStackEntry(writer);
			immutable uint stackEntriesForType = nStackEntriesForType(ctx, expr.type);
			debug {
				printf(
					"CreateRecord; before: %d, after: %d, stackEntriesForType: %d\n",
					before, after, stackEntriesForType);
			}
			verify(after - before == stackEntriesForType);
		},
		(ref immutable LowExprKind.ConvertToUnion it) {
			//immutable uint offset = nStackEntriesForUnionTypeExcludingKind(ctx.program, asUnionType(it.type));
			immutable uint before = getNextStackEntry(writer);
			immutable uint size = nStackEntriesForType(ctx, expr.type);
			writePushConstant(writer, it.memberIndex);
			generateExpr(tempAlloc, writer, ctx, it.arg);
			immutable uint after = getNextStackEntry(writer);
			if (before + size != after) {
				// Some members of a union are smaller than the union.
				verify(before + size > after);
				writePushEmptySpace(writer, before + size - after);
			}
		},
		(ref immutable LowExprKind.FunPtr it) {
			debug {
				printf("compiling funptr\n");
			}
			registerFunAddress(tempAlloc, ctx, it.fun,
				writePushU32Delayed(writer));
		},
		(ref immutable LowExprKind.Let it) {
			debug {

				immutable Str mn = it.local.mangledName;
				printf("START COMPILING LET %.*s\n", cast(int) size(mn), begin(mn));
			}

			immutable StackEntries localEntries =
				immutable StackEntries(getNextStackEntry(writer), nStackEntriesForType(ctx, it.local.type));
			generateExpr(tempAlloc, writer, ctx, it.value);

			debug {
				printf("MID COMPILING LET %.*s\n", cast(int) size(mn), begin(mn));
				printf("First entry: %u\n", localEntries.start);
				printf("Size: %u\n", localEntries.size);
				printf("New next entry is: %u\n", getNextStackEntry(writer));
			}
			verify(getNextStackEntry(writer) == localEntries.start + localEntries.size);
			addToMutDict(tempAlloc, ctx.localEntries, it.local, localEntries);
			generateExpr(tempAlloc, writer, ctx, it.then);
			mustDelete(ctx.localEntries, it.local);
			writeRemove(writer, localEntries);

			debug {
				printf(
					"DONE COMPILING LET %.*s: next stack entry %d\n",
					cast(int) size(mn), begin(mn), getNextStackEntry(writer));
			}
		},
		(ref immutable LowExprKind.LocalRef it) {
			writeDup(writer, mustGetAt_mut(ctx.localEntries, it.local));
		},
		(ref immutable LowExprKind.Match it) {
			immutable uint startStack = getNextStackEntry(writer);
			generateExpr(tempAlloc, writer, ctx, it.matchedValue);
			// Move the union kind to top of stack
			writeDup(writer, immutable StackEntries(startStack, 1));
			writeRemove(writer, immutable StackEntries(startStack, 1));
			// Get the kind (always the first entry)
			immutable ByteCodeIndex indexOfFirstCaseOffset = writeSwitchDelay(writer, size(it.cases));
			// Start of the union values is where the kind used to be.
			immutable uint stackAfterMatched = getNextStackEntry(writer);
			immutable StackEntries matchedEntriesWithoutKind =
				immutable StackEntries(startStack, safeU32ToU8(stackAfterMatched - startStack));
			immutable Arr!ByteCodeIndex delayedGotos = mapOpWithIndex!ByteCodeIndex(
				tempAlloc,
				it.cases,
				(immutable size_t caseIndex, ref immutable LowExprKind.Match.Case case_) {
					fillDelayedU16(
						writer,
						addByteCodeIndex(indexOfFirstCaseOffset, safeSizeTToU32(caseIndex)),
						subtractByteCodeIndex(curByteCodeIndex(writer), indexOfFirstCaseOffset));
					curByteCodeIndex(writer);
					if (has(case_.local)) {
						immutable uint nEntries = nStackEntriesForType(ctx, force(case_.local).type);
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
						return some(writeJumpDelayed(writer));
					} else
						// For the last one, don't reset the stack as by the end one of the cases will have run.
						// Last one doesn't need a jump, just continues straight into the code after it.
						return none!ByteCodeIndex;
				});
			foreach (immutable ByteCodeIndex jumpIndex; range(delayedGotos))
				fillInJumpDelayed(writer, jumpIndex);
			writeRemove(writer, matchedEntriesWithoutKind);
		},
		(ref immutable LowExprKind.ParamRef it) {
			writeDup(writer, at(ctx.parameterEntries, it.index.index));
		},
		(ref immutable LowExprKind.PtrCast it) {
			generateExpr(tempAlloc, writer, ctx, it.target);
		},
		(ref immutable LowExprKind.RecordFieldAccess it) {
			generateRecordFieldAccess(tempAlloc, writer, ctx, it);
		},
		(ref immutable LowExprKind.RecordFieldSet it) {
			immutable uint before = getNextStackEntry(writer);

			verify(it.targetIsPointer);
			generateExpr(tempAlloc, writer, ctx, it.target);
			immutable uint mid = getNextStackEntry(writer);
			generateExpr(tempAlloc, writer, ctx, it.value);
			immutable FieldOffsetAndSize offsetAndSize = getFieldOffsetAndSize(ctx, it.record, it.fieldIndex);
			debug {
				printf("Compiling RecordFieldSet: before: %d, mid: %d, field size (bytes): %d, now: %d\n",
					before, mid, offsetAndSize.size, getNextStackEntry(writer));
			}
			verify(mid + divRoundUp(offsetAndSize.size, stackEntrySize) == getNextStackEntry(writer));
			writeWrite(writer, offsetAndSize.offset, offsetAndSize.size);

			debug {
				printf("Compiling RecordFieldSet: before: %d, after: %d\n",
					before,
					getNextStackEntry(writer));
			}
			verify(getNextStackEntry(writer) == before);
		},
		(ref immutable LowExprKind.Seq it) {
			generateExpr(tempAlloc, writer, ctx, it.first);
			generateExpr(tempAlloc, writer, ctx, it.then);
		},
		(ref immutable LowExprKind.SizeOf it) {
			writePushConstant(writer, sizeOfType(ctx, it.type));
		},
		(ref immutable LowExprKind.SpecialConstant it) {
			generateSpecialConstant(writer, it);
		},
		(ref immutable LowExprKind.Special0Ary it) {
			generateSpecial0Ary(writer, it);
		},
		(ref immutable LowExprKind.SpecialUnary it) {
			debug {
				import sexprOfLowModel : strOfSpecialUnaryKind;
				immutable string kind = strOfSpecialUnaryKind(it.kind);
				printf("Unary %.*s stack before: %d\n", cast(int) kind.length, kind.ptr, getNextStackEntry(writer));
			}
			generateSpecialUnary(tempAlloc, writer, ctx, expr, it);
			debug {
				printf("Unary %.*s stack after: %d\n", cast(int) kind.length, kind.ptr, getNextStackEntry(writer));
			}
		},
		(ref immutable LowExprKind.SpecialBinary it) {
			generateSpecialBinary(tempAlloc, writer, ctx, expr.range, it);
		},
		(ref immutable LowExprKind.SpecialTrinary it) {
			generateSpecialTrinary(tempAlloc, writer, ctx, it);
		},
		(ref immutable LowExprKind.SpecialNAry it) {
			generateSpecialNAry(tempAlloc, writer, ctx, expr, it);
		});
}

struct FieldOffsetAndSize {
	immutable u8 offset;
	immutable u8 size;
}

immutable(u8) getFieldOffset(ref const ExprCtx ctx, immutable LowType.Record record, immutable u8 fieldIndex) {
	immutable Arr!u8 fieldOffsets = fullIndexDictGet(ctx.typeLayout.fieldOffsets, record);
	return at(fieldOffsets, fieldIndex);
}

immutable(FieldOffsetAndSize) getFieldOffsetAndSize(
	ref const ExprCtx ctx,
	immutable LowType.Record record,
	immutable u8 fieldIndex,
) {
	immutable u8 size = sizeOfType(ctx, at(fullIndexDictGet(ctx.program.allRecords, record).fields, fieldIndex).type);
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

void generateSpecialConstant(CodeAlloc)(
	ref ByteCodeWriter!CodeAlloc writer,
	ref immutable LowExprKind.SpecialConstant constant,
) {
	matchSpecialConstant(
		constant,
		(immutable LowExprKind.SpecialConstant.BoolConstant it) {
			writePushConstant(writer, it.value ? 1 : 0);
		},
		(immutable LowExprKind.SpecialConstant.Integral it) {
			writePushConstant(writer, it.value);
		},
		(immutable LowExprKind.SpecialConstant.Null) {
			writePushConstant(writer, 0);
		},
		(immutable LowExprKind.SpecialConstant.StrConstant it) {
			debug {
				printf("Compiling str constant, stack before: %d\n", getNextStackEntry(writer));
			}
			writePushConstantStr(writer, it.value);
			debug {
				printf("Str constant stack after: %d\n", getNextStackEntry(writer));
			}
		},
		(immutable LowExprKind.SpecialConstant.Void) {
			// do nothing
		});
}

void generateSpecial0Ary(CodeAlloc)(ref ByteCodeWriter!CodeAlloc writer, ref immutable LowExprKind.Special0Ary it) {
	final switch (it.kind) {
		case LowExprKind.Special0Ary.Kind.getErrno:
			todo!void("generate getErrno");
	}
}

void generateSpecialUnary(CodeAlloc, TempAlloc)(
	ref TempAlloc tempAlloc,
	ref ByteCodeWriter!CodeAlloc writer,
	ref ExprCtx ctx,
	ref immutable LowExpr expr,
	ref immutable LowExprKind.SpecialUnary a,
) {
	void generateArg() {
		generateExpr(tempAlloc, writer, ctx, a.arg);
	}

	void fn(immutable FnOp fnOp) {
		generateArg();
		writeFn(writer, fnOp);
	}

	final switch (a.kind) {
		case LowExprKind.SpecialUnary.Kind.asAnyPtr:
		case LowExprKind.SpecialUnary.Kind.asRef:
		case LowExprKind.SpecialUnary.Kind.toIntFromInt16:
		case LowExprKind.SpecialUnary.Kind.toIntFromInt32:
		case LowExprKind.SpecialUnary.Kind.toNatFromNat16:
		case LowExprKind.SpecialUnary.Kind.toNatFromNat32:
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
			generateArg();
			break;
		case LowExprKind.SpecialUnary.Kind.deref:
			generateArg();
			writeRead(writer, 0, sizeOfType(ctx, expr.type));
			break;
		case LowExprKind.SpecialUnary.Kind.hardFail:
			generateArg();
			writeFnHardFail(writer, nStackEntriesForType(ctx, expr.type));
			break;
		case LowExprKind.SpecialUnary.Kind.not:
			fn(FnOp.not);
			break;
		case LowExprKind.SpecialUnary.Kind.ptrTo:
		case LowExprKind.SpecialUnary.Kind.refOfVal:
			generateRefOfVal(tempAlloc, writer, ctx, a.arg);
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
	ref immutable LowExpr arg,
) {
	if (isLocalRef(arg.kind))
		writeStackRef(writer, mustGetAt_mut(ctx.localEntries, asLocalRef(arg.kind).local).start);
	else if (isParamRef(arg.kind))
		writeStackRef(writer, at(ctx.parameterEntries, asParamRef(arg.kind).index.index).start);
	else if (isRecordFieldAccess(arg.kind))
		generatePtrToRecordFieldAccess(tempAlloc, writer, ctx, asRecordFieldAccess(arg.kind));
	else {
		todo!void("ref-of-val -- not a local or record field");
	}
}

void generateRecordFieldAccess(TempAlloc, CodeAlloc)(
	ref TempAlloc tempAlloc,
	ref ByteCodeWriter!CodeAlloc writer,
	ref ExprCtx ctx,
	ref immutable LowExprKind.RecordFieldAccess it,
) {
	//debug {
	//	immutable LowRecord record = fullIndexDictGet(ctx.program.allRecords, it.record);
	//	immutable LowField field = at(record.fields, it.fieldIndex);
	//	printf("compiling RecordFieldAccess, record=%.*s, field=%.*s\n",
	//		cast(int) size(record.mangledName), begin(record.mangledName),
	//		cast(int) size(field.mangledName), begin(field.mangledName));
	//}
	immutable uint targetEntry = getNextStackEntry(writer);
	generateExpr(tempAlloc, writer, ctx, it.target);
	immutable StackEntries targetEntries = immutable StackEntries(
		targetEntry,
		safeU32ToU8(getNextStackEntry(writer) - targetEntry));
	immutable FieldOffsetAndSize offsetAndSize = getFieldOffsetAndSize(ctx, it.record, it.fieldIndex);
	if (it.targetIsPointer) {
		writeRead(writer, offsetAndSize.offset, offsetAndSize.size);
	} else {
		//debug {
		//	printf("Field offset is %d, size is %d\n", offsetAndSize.offset, offsetAndSize.size);
		//}
		if (offsetAndSize.size % stackEntrySize == 0) {
			verify(offsetAndSize.offset % stackEntrySize == 0);
			immutable StackEntries entries = immutable StackEntries(
				targetEntry + (offsetAndSize.offset / stackEntrySize),
				offsetAndSize.size / stackEntrySize);
			writeDup(writer, entries);
		} else {
			writeDupPartial(
				writer,
				safeU32ToU8(targetEntry + (offsetAndSize.offset / stackEntrySize)),
				offsetAndSize.offset % stackEntrySize,
				offsetAndSize.size);
		}
		writeRemove(writer, targetEntries);
	}
}

void generatePtrToRecordFieldAccess(TempAlloc, CodeAlloc)(
	ref TempAlloc tempAlloc,
	ref ByteCodeWriter!CodeAlloc writer,
	ref ExprCtx ctx,
	ref immutable LowExprKind.RecordFieldAccess it,
) {
	generateExpr(tempAlloc, writer, ctx, it.target);
	immutable u8 offset = getFieldOffset(ctx, it.record, it.fieldIndex);
	if (it.targetIsPointer)
		writeAddConstantNat64(writer, offset);
	else {
		// This only works if it's a local .. or another recordfieldaccess
		todo!void("ptr-to-record-field-access");
	}
}

void generateSpecialBinary(TempAlloc, CodeAlloc)(
	ref TempAlloc tempAlloc,
	ref ByteCodeWriter!CodeAlloc writer,
	ref ExprCtx ctx,
	ref immutable SourceRange range,
	ref immutable LowExprKind.SpecialBinary a,
) {
	void fn(immutable FnOp fn) {
		generateExpr(tempAlloc, writer, ctx, a.left);
		generateExpr(tempAlloc, writer, ctx, a.right);
		writeFn(writer, fn);
	}

	final switch (a.kind) {
		case LowExprKind.SpecialBinary.Kind.addFloat64:
			fn(FnOp.addFloat64);
			break;
		case LowExprKind.SpecialBinary.Kind.addPtr:
			fn(FnOp.addInt64OrNat64);
			break;
		case LowExprKind.SpecialBinary.Kind.and:
			immutable LowExpr falseExpr = genBool(range, False);
			generateIf(tempAlloc, writer, ctx, a.left, a.right, falseExpr);
			break;
		case LowExprKind.SpecialBinary.Kind.bitShiftLeftInt32:
			fn(FnOp.bitShiftLeftInt32);
			break;
		case LowExprKind.SpecialBinary.Kind.bitShiftLeftNat32:
			fn(FnOp.bitShiftLeftNat32);
			break;
		case LowExprKind.SpecialBinary.Kind.bitShiftRightInt32:
			fn(FnOp.bitShiftRightInt32);
			break;
		case LowExprKind.SpecialBinary.Kind.bitShiftRightNat32:
			fn(FnOp.bitShiftRightNat32);
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
			fn(FnOp.eqNat);
			break;
		case LowExprKind.SpecialBinary.Kind.less: // TODO:KILL
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
			immutable LowExpr trueExpr = genBool(range, True);
			generateIf(tempAlloc, writer, ctx, a.left, trueExpr, a.right);
			break;
		case LowExprKind.SpecialBinary.Kind.subFloat64:
			fn(FnOp.subFloat64);
			break;
		case LowExprKind.SpecialBinary.Kind.subPtrNat:
			fn(FnOp.wrapSubNat64);
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
			fn(FnOp.wrapAddInt16);
			break;
		case LowExprKind.SpecialBinary.Kind.wrapAddInt32:
			fn(FnOp.wrapAddInt32);
			break;
		case LowExprKind.SpecialBinary.Kind.wrapAddInt64:
			fn(FnOp.wrapAddInt64);
			break;
		case LowExprKind.SpecialBinary.Kind.wrapAddNat16:
			fn(FnOp.wrapAddNat16);
			break;
		case LowExprKind.SpecialBinary.Kind.wrapAddNat32:
			fn(FnOp.wrapAddNat32);
			break;
		case LowExprKind.SpecialBinary.Kind.wrapAddNat64:
			fn(FnOp.wrapAddNat64);
			break;
		case LowExprKind.SpecialBinary.Kind.wrapMulInt16:
			fn(FnOp.wrapMulInt16);
			break;
		case LowExprKind.SpecialBinary.Kind.wrapMulInt32:
			fn(FnOp.wrapMulInt32);
			break;
		case LowExprKind.SpecialBinary.Kind.wrapMulInt64:
			fn(FnOp.wrapMulInt64);
			break;
		case LowExprKind.SpecialBinary.Kind.wrapMulNat16:
			fn(FnOp.wrapMulNat16);
			break;
		case LowExprKind.SpecialBinary.Kind.wrapMulNat32:
			fn(FnOp.wrapMulNat32);
			break;
		case LowExprKind.SpecialBinary.Kind.wrapMulNat64:
			fn(FnOp.wrapMulNat64);
			break;
		case LowExprKind.SpecialBinary.Kind.wrapSubInt16:
			fn(FnOp.wrapSubInt16);
			break;
		case LowExprKind.SpecialBinary.Kind.wrapSubInt32:
			fn(FnOp.wrapSubInt32);
			break;
		case LowExprKind.SpecialBinary.Kind.wrapSubInt64:
			fn(FnOp.wrapSubInt64);
			break;
		case LowExprKind.SpecialBinary.Kind.wrapSubNat16:
			fn(FnOp.wrapSubNat16);
			break;
		case LowExprKind.SpecialBinary.Kind.wrapSubNat32:
			fn(FnOp.wrapSubNat32);
			break;
		case LowExprKind.SpecialBinary.Kind.wrapSubNat64:
			fn(FnOp.wrapSubNat64);
			break;
		case LowExprKind.SpecialBinary.Kind.writeToPtr:
			generateExpr(tempAlloc, writer, ctx, a.left);
			generateExpr(tempAlloc, writer, ctx, a.right);
			writeWrite(writer, 0, sizeOfType(ctx, a.right.type));
			break;
	}
}

void generateSpecialTrinary(TempAlloc, CodeAlloc)(
	ref TempAlloc tempAlloc,
	ref ByteCodeWriter!CodeAlloc writer,
	ref ExprCtx ctx,
	ref immutable LowExprKind.SpecialTrinary a,
) {
	final switch (a.kind) {
		case LowExprKind.SpecialTrinary.Kind.if_:
			generateIf(tempAlloc, writer, ctx, a.p0, a.p1, a.p2);
			break;
		case LowExprKind.SpecialTrinary.Kind.compareExchangeStrong:
			generateExpr(tempAlloc, writer, ctx, a.p0);
			generateExpr(tempAlloc, writer, ctx, a.p1);
			generateExpr(tempAlloc, writer, ctx, a.p2);
			writeFn(writer, FnOp.compareExchangeStrong);
			break;
	}
}

void generateIf(TempAlloc, CodeAlloc)(
	ref TempAlloc tempAlloc,
	ref ByteCodeWriter!CodeAlloc writer,
	ref ExprCtx ctx,
	ref immutable LowExpr cond,
	ref immutable LowExpr then,
	ref immutable LowExpr else_,
) {
	immutable uint startStack = getNextStackEntry(writer);
	generateExpr(tempAlloc, writer, ctx, cond);
	immutable ByteCodeIndex delayed = writeSwitchDelay(writer, 2);
	fillDelayedU16(writer, addByteCodeIndex(delayed, 0), subtractByteCodeIndex(curByteCodeIndex(writer), delayed));
	generateExpr(tempAlloc, writer, ctx, else_);
	setNextStackEntry(writer, startStack);
	immutable ByteCodeIndex jumpIndex = writeJumpDelayed(writer);
	fillDelayedU16(writer, addByteCodeIndex(delayed, 1), subtractByteCodeIndex(curByteCodeIndex(writer), delayed));
	generateExpr(tempAlloc, writer, ctx, then);
	fillInJumpDelayed(writer, jumpIndex);
}

void generateSpecialNAry(TempAlloc, CodeAlloc)(
	ref TempAlloc tempAlloc,
	ref ByteCodeWriter!CodeAlloc writer,
	ref ExprCtx ctx,
	ref immutable LowExpr expr,
	ref immutable LowExprKind.SpecialNAry a,
) {
	final switch (a.kind) {
		case LowExprKind.SpecialNAry.Kind.callFunPtr:
			immutable uint stackEntryBeforeArgs = getNextStackEntry(writer);
			foreach (ref immutable LowExpr arg; range(a.args))
				generateExpr(tempAlloc, writer, ctx, arg);
			writeCallFunPtr(writer, stackEntryBeforeArgs, nStackEntriesForType(ctx, expr.type));
			break;
	}
}