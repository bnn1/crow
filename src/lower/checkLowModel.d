module lower.checkLowModel;

@safe @nogc pure nothrow:

import lower.lowExprHelpers : boolType, nat64Type, voidType;
import model.constant : Constant;
import model.lowModel :
	asFunPtrType,
	asRecordType,
	asUnionType,
	isVoid,
	LowExpr,
	LowExprKind,
	LowField,
	LowFun,
	LowFunBody,
	LowFunExprBody,
	LowFunIndex,
	LowFunPtrType,
	LowParam,
	LowProgram,
	LowType,
	lowTypeEqual,
	matchLowExprKind,
	matchLowFunBody,
	matchLowType,
	PrimitiveType,
	symOfPrimitiveType,
	UpdateParam;
import model.reprConcreteModel : reprOfConcreteStructRef;
import util.alloc.alloc : Alloc;
import util.col.arr : sizeEq;
import util.col.arrUtil : zip;
import util.col.fullIndexDict : fullIndexDictEachValue, fullIndexDictGet, fullIndexDictGetPtr;
import util.opt : force, has;
import util.ptr : Ptr, ptrTrustMe;
import util.repr : Repr, reprRecord, reprSym;
import util.util : verify;

void checkLowProgram(ref Alloc alloc, ref immutable LowProgram a) {
	immutable Ctx ctx = immutable Ctx(ptrTrustMe(a));
	fullIndexDictEachValue!(LowFunIndex, LowFun)(a.allFuns, (ref immutable LowFun fun) {
		checkLowFun(alloc, ctx, fun);
	});
}

private:

struct Ctx {
	@safe @nogc pure nothrow:

	immutable Ptr!LowProgram programPtr;

	ref immutable(LowProgram) program() return scope const {
		return programPtr.deref();
	}
}

struct FunCtx {
	@safe @nogc pure nothrow:

	immutable Ctx ctx;
	immutable Ptr!LowFun funPtr;

	ref immutable(LowFun) fun() return scope const {
		return funPtr.deref();
	}
}

void checkLowFun(ref Alloc alloc, ref immutable Ctx ctx, ref immutable LowFun fun) {
	//debug {
	//	import core.stdc.stdio : printf;
	//	import interpret.debugging : writeFunName;
	//	import util.ptr : ptrTrustMe_mut;
	//	import util.writer : Writer, finishWriterToCStr;
	//
	//	Writer writer = Writer(ptrTrustMe_mut(alloc));
	//	writeFunName(writer, ctx.program, fun);
	//	printf("Will check function %s\n", finishWriterToCStr(writer));
	//}

	matchLowFunBody!(
		void,
		(ref immutable LowFunBody.Extern) {},
		(ref immutable LowFunExprBody it) {
			immutable FunCtx funCtx = immutable FunCtx(ctx, ptrTrustMe(fun));
			checkLowExpr(alloc, funCtx, fun.returnType, it.expr);
		},
	)(fun.body_);
}

void checkLowExpr(
	ref Alloc alloc,
	ref immutable FunCtx ctx,
	ref immutable LowType type,
	ref immutable LowExpr expr,
) {
	checkTypeEqual(alloc, ctx.ctx, type, expr.type);
	matchLowExprKind!(
		void,
		(ref immutable LowExprKind.Call it) {
			immutable Ptr!LowFun fun = fullIndexDictGetPtr(ctx.ctx.program.allFuns, it.called);
			checkTypeEqual(alloc, ctx.ctx, type, fun.deref().returnType);
			verify(sizeEq(fun.deref().params, it.args));
			zip!(LowParam, LowExpr)(
				fun.deref().params,
				it.args,
				(ref immutable LowParam param, ref immutable LowExpr arg) {
					checkLowExpr(alloc, ctx, param.type, arg);
				});
		},
		(ref immutable LowExprKind.CallFunPtr it) {
			immutable LowFunPtrType funPtrType =
				fullIndexDictGetPtr(ctx.ctx.program.allFunPtrTypes, asFunPtrType(it.funPtr.type)).deref();
			checkTypeEqual(alloc, ctx.ctx, type, funPtrType.returnType);
			verify(sizeEq(funPtrType.paramTypes, it.args));
			zip!(LowType, LowExpr)(
				funPtrType.paramTypes,
				it.args,
				(ref immutable LowType paramType, ref immutable LowExpr arg) {
					checkLowExpr(alloc, ctx, paramType, arg);
				});
		},
		(ref immutable LowExprKind.CreateRecord it) {
			immutable LowField[] fields = fullIndexDictGet(ctx.ctx.program.allRecords, asRecordType(type)).fields;
			zip!(LowField, LowExpr)(fields, it.args, (ref immutable LowField field, ref immutable LowExpr arg) {
				checkLowExpr(alloc, ctx, field.type, arg);
			});
		},
		(ref immutable LowExprKind.CreateUnion it) {
			immutable LowType member =
				fullIndexDictGet(ctx.ctx.program.allUnions, asUnionType(type)).members[it.memberIndex];
			checkLowExpr(alloc, ctx, member, it.arg);
		},
		(ref immutable LowExprKind.If it) {
			checkLowExpr(alloc, ctx, boolType, it.cond);
			checkLowExpr(alloc, ctx, type, it.then);
			checkLowExpr(alloc, ctx, type, it.else_);
		},
		(ref immutable LowExprKind.InitConstants) {
			verify(isVoid(type));
		},
		(ref immutable LowExprKind.Let it) {
			checkLowExpr(alloc, ctx, it.local.deref().type, it.value);
			checkLowExpr(alloc, ctx, type, it.then);
		},
		(ref immutable LowExprKind.LocalRef it) {
			checkTypeEqual(alloc, ctx.ctx, type, it.local.deref().type);
		},
		(ref immutable LowExprKind.MatchUnion it) {
			checkLowExpr(alloc, ctx, it.matchedValue.type, it.matchedValue);
			zip!(LowType, LowExprKind.MatchUnion.Case)(
				fullIndexDictGet(ctx.ctx.program.allUnions, asUnionType(it.matchedValue.type)).members,
				it.cases,
				(ref immutable LowType memberType, ref immutable LowExprKind.MatchUnion.Case case_) {
					if (has(case_.local))
						checkTypeEqual(alloc, ctx.ctx, memberType, force(case_.local).deref().type);
					checkLowExpr(alloc, ctx, type, case_.then);
				});
		},
		(ref immutable LowExprKind.ParamRef it) {
			checkTypeEqual(alloc, ctx.ctx, type, ctx.fun.params[it.index.index].type);
		},
		(ref immutable LowExprKind.PtrCast it) {
			// TODO: there are some limitations on target...
			checkLowExpr(alloc, ctx, it.target.type, it.target);
		},
		(ref immutable LowExprKind.RecordFieldGet it) {
			immutable LowType targetTypeNonPtr = immutable LowType(it.record);
			immutable LowType targetType = it.targetIsPointer
				? immutable LowType(immutable LowType.PtrGc(ptrTrustMe(targetTypeNonPtr)))
				: targetTypeNonPtr;
			checkLowExpr(alloc, ctx, targetType, it.target);
			immutable LowType fieldType =
				fullIndexDictGet(ctx.ctx.program.allRecords, it.record).fields[it.fieldIndex].type;
			checkTypeEqual(alloc, ctx.ctx, type, fieldType);
		},
		(ref immutable LowExprKind.RecordFieldSet it) {
			immutable LowType targetTypeNonPtr = immutable LowType(it.record);
			immutable LowType targetType = it.targetIsPointer
				? immutable LowType(immutable LowType.PtrGc(ptrTrustMe(targetTypeNonPtr)))
				: targetTypeNonPtr;
			checkLowExpr(alloc, ctx, targetType, it.target);
			immutable LowType fieldType =
				fullIndexDictGet(ctx.ctx.program.allRecords, it.record).fields[it.fieldIndex].type;
			checkLowExpr(alloc, ctx, fieldType, it.value);
			checkTypeEqual(alloc, ctx.ctx, type, voidType);
		},
		(ref immutable LowExprKind.Seq it) {
			checkLowExpr(alloc, ctx, voidType, it.first);
			checkLowExpr(alloc, ctx, type, it.then);
		},
		(ref immutable LowExprKind.SizeOf it) {
			checkTypeEqual(alloc, ctx.ctx, type, nat64Type);
		},
		(ref immutable Constant it) {
			// Constants are untyped, so can't check more
		},
		(ref immutable LowExprKind.SpecialUnary it) {
			// TODO
		},
		(ref immutable LowExprKind.SpecialBinary it) {
			// TODO
		},
		(ref immutable LowExprKind.Switch0ToN it) {
			checkLowExpr(alloc, ctx, it.value.type, it.value);
			foreach (ref immutable LowExpr case_; it.cases)
				checkLowExpr(alloc, ctx, type, case_);
		},
		(ref immutable LowExprKind.SwitchWithValues it) {
			checkLowExpr(alloc, ctx, it.value.type, it.value);
			foreach (ref immutable LowExpr case_; it.cases)
				checkLowExpr(alloc, ctx, type, case_);
		},
		(ref immutable LowExprKind.TailRecur it) {
			checkTypeEqual(alloc, ctx.ctx, type, ctx.fun.returnType);
			foreach (ref immutable UpdateParam update; it.updateParams)
				checkLowExpr(alloc, ctx, ctx.fun.params[update.param.index].type, update.newValue);
		},
		(ref immutable LowExprKind.Zeroed) {},
	)(expr.kind);
}

void checkTypeEqual(
	ref Alloc alloc,
	ref immutable Ctx ctx,
	ref immutable LowType expected,
	ref immutable LowType actual,
) {
	//debug {
	//	if (!lowTypeEqual(expected, actual)) {
	//		import core.stdc.stdio : printf;
	//		import util.repr : writeRepr;
	//		import util.writer : finishWriterToCStr, Writer, writeStatic;
	//		import util.ptr : ptrTrustMe_mut;
	//		Writer writer = Writer(ptrTrustMe_mut(alloc));
	//		writeStatic(writer, "Type is not as expected. Expected:\n");
	//		writeRepr(writer, allSymbols, reprOfLowType2(alloc, ctx, expected));
	//		writeStatic(writer, "Actual:\n");
	//		writeRepr(writer, allSymbols, reprOfLowType2(alloc, ctx, actual));
	//		printf("%s\n", finishWriterToCStr(writer));
	//	}
	//}
	verify(lowTypeEqual(expected, actual));
}

immutable(Repr) reprOfLowType2(ref Alloc alloc, ref immutable Ctx ctx, immutable LowType a) {
	return matchLowType!(
		immutable Repr,
		(immutable LowType.ExternPtr) =>
			reprSym("a-extern-ptr"), //TODO: more detail
		(immutable LowType.FunPtr) =>
			reprSym("some-fun-ptr"), //TODO: more detail
		(immutable PrimitiveType it) =>
			reprSym(symOfPrimitiveType(it)),
		(immutable LowType.PtrGc it) =>
			reprRecord(alloc, "gc-ptr", [reprOfLowType2(alloc, ctx, it.pointee.deref())]),
		(immutable LowType.PtrRawConst it) =>
			reprRecord(alloc, "ptr-const", [reprOfLowType2(alloc, ctx, it.pointee.deref())]),
		(immutable LowType.PtrRawMut it) =>
			reprRecord(alloc, "ptr-mut", [reprOfLowType2(alloc, ctx, it.pointee.deref())]),
		(immutable LowType.Record it) =>
			reprOfConcreteStructRef(alloc, fullIndexDictGet(ctx.program.allRecords, it).source.deref()),
		(immutable LowType.Union it) =>
			reprOfConcreteStructRef(alloc, fullIndexDictGet(ctx.program.allUnions, it).source.deref()),
	)(a);
}
