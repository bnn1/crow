module model.reprLowModel;

@safe @nogc pure nothrow:

import model.concreteModel : ConcreteFun, ConcreteLocal, ConcreteParam;
import model.constant : Constant;
import model.lowModel :
	LowExpr,
	LowExprKind,
	LowExternPtrType,
	LowField,
	LowFun,
	LowFunBody,
	LowFunExprBody,
	LowFunParamsKind,
	LowFunPtrType,
	LowFunSource,
	LowLocal,
	LowLocalSource,
	LowParam,
	LowParamSource,
	LowProgram,
	LowRecord,
	LowType,
	LowUnion,
	matchLowExprKind,
	matchLowFunBody,
	matchLowFunSource,
	matchLowLocalSource,
	matchLowParamSource,
	matchLowType,
	name,
	PrimitiveType,
	symOfPrimitiveType,
	UpdateParam;
import model.model : EnumValue;
import model.reprConcreteModel :
	reprOfConcreteFunRef,
	reprOfConcreteLocalRef,
	reprOfConcreteParamRef,
	reprOfConcreteStructRef;
import model.reprConstant : reprOfConstant;
import util.alloc.alloc : Alloc;
import util.ptr : Ptr;
import util.repr :
	nameAndRepr,
	Repr,
	reprArr,
	reprBool,
	reprFullIndexDict,
	reprInt,
	reprNamedRecord,
	reprNat,
	reprOpt,
	reprRecord,
	reprStr,
	reprSym;
import util.sourceRange : reprFileAndRange;

immutable(Repr) reprOfLowProgram(ref Alloc alloc, ref immutable LowProgram a) {
	return reprNamedRecord(alloc, "program", [
		nameAndRepr("extern-ptrs", reprFullIndexDict(alloc, a.allExternPtrTypes, (ref immutable LowExternPtrType it) =>
			reprOfExternPtrType(alloc, it))),
		nameAndRepr("fun-ptrs", reprFullIndexDict(alloc, a.allFunPtrTypes, (ref immutable LowFunPtrType it) =>
			reprOfLowFunPtrType(alloc, it))),
		nameAndRepr("records", reprFullIndexDict(alloc, a.allRecords, (ref immutable LowRecord it) =>
			reprOfLowRecord(alloc, it))),
		nameAndRepr("unions", reprFullIndexDict(alloc, a.allUnions, (ref immutable LowUnion it) =>
			reprOfLowUnion(alloc, it))),
		nameAndRepr("funs", reprFullIndexDict(alloc, a.allFuns, (ref immutable LowFun it) =>
			reprOfLowFun(alloc, it))),
		nameAndRepr("main", reprNat(a.main.index))]);
}

private:

immutable(Repr) reprOfLowType(ref Alloc alloc, ref immutable LowType a) {
	return matchLowType!(
		immutable Repr,
		(immutable LowType.ExternPtr it) =>
			reprRecord(alloc, "extern-ptr", [reprNat(it.index)]),
		(immutable LowType.FunPtr it) =>
			reprRecord(alloc, "fun-ptr", [reprNat(it.index)]),
		(immutable PrimitiveType it) =>
			reprSym(symOfPrimitiveType(it)),
		(immutable LowType.PtrGc it) =>
			reprRecord(alloc, "gc-ptr", [reprOfLowType(alloc, it.pointee.deref())]),
		(immutable LowType.PtrRawConst it) =>
			reprRecord(alloc, "ptr-const", [reprOfLowType(alloc, it.pointee.deref())]),
		(immutable LowType.PtrRawMut it) =>
			reprRecord(alloc, "ptr-mut", [reprOfLowType(alloc, it.pointee.deref())]),
		(immutable LowType.Record it) =>
			reprRecord(alloc, "record", [reprNat(it.index)]),
		(immutable LowType.Union it) =>
			reprRecord(alloc, "union", [reprNat(it.index)]),
	)(a);
}

immutable(Repr) reprOfExternPtrType(ref Alloc alloc, ref immutable LowExternPtrType a) {
	return reprRecord(alloc, "extern-ptr", [
		reprOfConcreteStructRef(alloc, a.source.deref())]);
}

immutable(Repr) reprOfLowFunPtrType(ref Alloc alloc, ref immutable LowFunPtrType a) {
	return reprRecord(alloc, "fun-ptr", [
		reprOfConcreteStructRef(alloc, a.source.deref()),
		reprOfLowType(alloc, a.returnType),
		reprArr(alloc, a.paramTypes, (ref immutable LowType it) =>
			reprOfLowType(alloc, it))]);
}

immutable(Repr) reprOfLowRecord(ref Alloc alloc, ref immutable LowRecord a) {
	return reprRecord(alloc, "record", [
		reprOfConcreteStructRef(alloc, a.source.deref()),
		reprArr(alloc, a.fields, (ref immutable LowField field) =>
			reprRecord(alloc, "field", [reprSym(name(field)), reprOfLowType(alloc, field.type)]))]);
}

immutable(Repr) reprOfLowUnion(ref Alloc alloc, ref immutable LowUnion a){
	return reprRecord(alloc, "union", [
		reprOfConcreteStructRef(alloc, a.source.deref()),
		reprArr(alloc, a.members, (ref immutable LowType it) =>
			reprOfLowType(alloc, it))]);
}

immutable(Repr) reprOfLowFun(ref Alloc alloc, ref immutable LowFun a) {
	return reprRecord(alloc, "fun", [
		reprOfLowFunSource(alloc, a.source),
		reprOfLowType(alloc, a.returnType),
		reprOfLowFunParamsKind(alloc, a.paramsKind),
		reprArr(alloc, a.params, (ref immutable LowParam it) =>
			reprRecord(alloc, "param", [reprOfLowParamSource(it.source), reprOfLowType(alloc, it.type)])),
		reprOfLowFunBody(alloc, a.body_)]);
}

immutable(Repr) reprOfLowFunParamsKind(ref Alloc alloc, ref immutable LowFunParamsKind a) {
	return reprNamedRecord(alloc, "param-kind", [
		nameAndRepr("ctx", reprBool(a.hasCtx)),
		nameAndRepr("closure", reprBool(a.hasClosure))]);
}

immutable(Repr) reprOfLowFunSource(ref Alloc alloc, ref immutable LowFunSource a) {
	return matchLowFunSource!(
		immutable Repr,
		(immutable Ptr!ConcreteFun it) =>
			reprOfConcreteFunRef(alloc, it.deref()),
		(ref immutable LowFunSource.Generated it) =>
			reprRecord(alloc, "generated", [reprSym(it.name)]),
	)(a);
}

immutable(Repr) reprOfLowParamSource(ref immutable LowParamSource a) {
	return matchLowParamSource!(
		immutable Repr,
		(ref immutable ConcreteParam it) =>
			reprOfConcreteParamRef(it),
		(ref immutable LowParamSource.Generated it) =>
			reprSym(it.name),
	)(a);
}

immutable(Repr) reprOfLowFunBody(ref Alloc alloc, ref immutable LowFunBody a) {
	return matchLowFunBody!(
		immutable Repr,
		(ref immutable LowFunBody.Extern it) =>
			reprSym("extern"),
		(ref immutable LowFunExprBody it) =>
			reprRecord(alloc, "expr-body", [reprOfLowExpr(alloc, it.expr)]),
	)(a);
}

immutable(Repr) reprOfLowLocalSource(ref Alloc alloc, ref immutable LowLocalSource a) {
	return matchLowLocalSource!(
		immutable Repr,
		(ref immutable ConcreteLocal it) =>
			reprOfConcreteLocalRef(it),
		(ref immutable LowLocalSource.Generated it) =>
			reprRecord(alloc, "generated", [reprSym(it.name), reprNat(it.index)]),
	)(a);
}

immutable(Repr) reprOfLowExpr(ref Alloc alloc, ref immutable LowExpr a) {
	return reprRecord(alloc, "expr", [
		reprOfLowType(alloc, a.type),
		reprFileAndRange(alloc, a.source),
		reprOfLowExprKind(alloc, a.kind)]);
}

immutable(Repr) reprOfLowExprKind(ref Alloc alloc, ref immutable LowExprKind a) {
	return matchLowExprKind!(
		immutable Repr,
		(ref immutable LowExprKind.Call it) =>
			reprRecord(alloc, "call", [
				reprNat(it.called.index),
				reprArr(alloc, it.args, (ref immutable LowExpr e) =>
					reprOfLowExpr(alloc, e))]),
		(ref immutable LowExprKind.CallFunPtr it) =>
			reprRecord(alloc, "call-fun-ptr", [
				reprOfLowExpr(alloc, it.funPtr),
				reprArr(alloc, it.args, (ref immutable LowExpr arg) =>
					reprOfLowExpr(alloc, arg))]),
		(ref immutable LowExprKind.CreateRecord it) =>
			reprRecord(alloc, "record", [
				reprArr(alloc, it.args, (ref immutable LowExpr e) =>
					reprOfLowExpr(alloc, e))]),
		(ref immutable LowExprKind.CreateUnion it) =>
			reprRecord(alloc, "to-union", [reprNat(it.memberIndex), reprOfLowExpr(alloc, it.arg)]),
		(ref immutable LowExprKind.If it) =>
			reprRecord(alloc, "if", [
				reprOfLowExpr(alloc, it.cond),
				reprOfLowExpr(alloc, it.then),
				reprOfLowExpr(alloc, it.else_)]),
		(ref immutable LowExprKind.InitConstants) =>
			reprSym("init-const"),
		(ref immutable LowExprKind.Let it) =>
			reprRecord(alloc, "let", [
				reprOfLowLocalSource(alloc, it.local.deref().source),
				reprOfLowExpr(alloc, it.value),
				reprOfLowExpr(alloc, it.then)]),
		(ref immutable LowExprKind.LocalRef it) =>
			reprRecord(alloc, "local-ref", [reprOfLowLocalSource(alloc, it.local.deref().source)]),
		(ref immutable LowExprKind.MatchUnion it) =>
			reprOfMatchUnion(alloc, it),
		(ref immutable LowExprKind.ParamRef it) =>
			reprRecord(alloc, "param-ref", [reprNat(it.index.index)]),
		(ref immutable LowExprKind.PtrCast it) =>
			reprRecord(alloc, "ptr-cast", [reprOfLowExpr(alloc, it.target)]),
		(ref immutable LowExprKind.RecordFieldGet it) =>
			reprRecord(alloc, "get-field", [
				reprOfLowExpr(alloc, it.target),
				reprBool(it.targetIsPointer),
				reprNat(it.fieldIndex)]),
		(ref immutable LowExprKind.RecordFieldSet it) =>
			reprRecord(alloc, "set-field", [
				reprOfLowExpr(alloc, it.target),
				reprBool(it.targetIsPointer),
				reprNat(it.fieldIndex),
				reprOfLowExpr(alloc, it.value)]),
		(ref immutable LowExprKind.Seq it) =>
			reprRecord(alloc, "seq", [
				reprOfLowExpr(alloc, it.first),
				reprOfLowExpr(alloc, it.then)]),
		(ref immutable LowExprKind.SizeOf it) =>
			reprRecord(alloc, "size-of", [reprOfLowType(alloc, it.type)]),
		(ref immutable Constant it) =>
			reprOfConstant(alloc, it),
		(ref immutable LowExprKind.SpecialUnary it) =>
			reprRecord(alloc, "unary", [
				reprStr(strOfSpecialUnaryKind(it.kind)),
				reprOfLowExpr(alloc, it.arg)]),
		(ref immutable LowExprKind.SpecialBinary it) =>
			reprRecord(alloc, "binary", [
				reprStr(strOfSpecialBinaryKind(it.kind)),
				reprOfLowExpr(alloc, it.left),
				reprOfLowExpr(alloc, it.right)]),
		(ref immutable LowExprKind.Switch0ToN it) =>
			reprRecord(alloc, "switch-n", [
				reprOfLowExpr(alloc, it.value),
				reprArr(alloc, it.cases, (ref immutable LowExpr arg) =>
					reprOfLowExpr(alloc, arg))]),
		(ref immutable LowExprKind.SwitchWithValues it) =>
			reprRecord(alloc, "switch-v", [
				reprOfLowExpr(alloc, it.value),
				reprArr(alloc, it.values, (ref immutable EnumValue value) =>
					reprInt(value.value)),
				reprArr(alloc, it.cases, (ref immutable LowExpr case_) =>
					reprOfLowExpr(alloc, case_))]),
		(ref immutable LowExprKind.TailRecur it) =>
			reprRecord(alloc, "tail-recur", [
				reprArr(alloc, it.updateParams, (ref immutable UpdateParam updateParam) =>
					reprRecord(alloc, "update", [
						reprNat(updateParam.param.index),
						reprOfLowExpr(alloc, updateParam.newValue),
					]))]),
		(ref immutable LowExprKind.Zeroed) =>
			reprSym("uninit"),
	)(a);
}

immutable(Repr) reprOfMatchUnion(ref Alloc alloc, ref immutable LowExprKind.MatchUnion a) {
	return reprRecord(alloc, "match", [
		reprOfLowExpr(alloc, a.matchedValue),
		reprArr(alloc, a.cases, (ref immutable LowExprKind.MatchUnion.Case case_) =>
			reprRecord(alloc, "case", [
				reprOpt(alloc, case_.local, (ref immutable Ptr!LowLocal it) =>
					reprOfLowLocalSource(alloc, it.deref().source)),
				reprOfLowExpr(alloc, case_.then)]))]);
}

immutable(string) strOfSpecialUnaryKind(immutable LowExprKind.SpecialUnary.Kind a) {
	final switch (a) {
		case LowExprKind.SpecialUnary.Kind.asAnyPtr:
			return "as-any-ptr";
		case LowExprKind.SpecialUnary.Kind.asRef:
			return "as-ref";
		case LowExprKind.SpecialUnary.Kind.bitwiseNotNat8:
			return "bitwise-not (nat8)";
		case LowExprKind.SpecialUnary.Kind.bitwiseNotNat16:
			return "bitwise-not (nat16)";
		case LowExprKind.SpecialUnary.Kind.bitwiseNotNat32:
			return "bitwise-not (nat32)";
		case LowExprKind.SpecialUnary.Kind.bitwiseNotNat64:
			return "bitwise-not (nat64)";
		case LowExprKind.SpecialUnary.Kind.countOnesNat64:
			return "count-ones (nat64)";
		case LowExprKind.SpecialUnary.Kind.deref:
			return "deref";
		case LowExprKind.SpecialUnary.Kind.enumToIntegral:
			return "to integral (from enum)";
		case LowExprKind.SpecialUnary.Kind.ptrTo:
			return "ptr-to";
		case LowExprKind.SpecialUnary.Kind.refOfVal:
			return "ref-of-val";
		case LowExprKind.SpecialUnary.Kind.toCharFromNat8:
			return "to-char8 (from nat8)";
		case LowExprKind.SpecialUnary.Kind.toFloat32FromFloat64:
			return "to-float32 (from float64)";
		case LowExprKind.SpecialUnary.Kind.toFloat64FromFloat32:
			return "to-float64 (from float32)";
		case LowExprKind.SpecialUnary.Kind.toFloat64FromInt64:
			return "to-float64 (from int64)";
		case LowExprKind.SpecialUnary.Kind.toFloat64FromNat64:
			return "to-float64 (from nat64)";
		case LowExprKind.SpecialUnary.Kind.toInt64FromInt16:
			return "to-int (from int16)";
		case LowExprKind.SpecialUnary.Kind.toInt64FromInt32:
			return "to-int (from int32)";
		case LowExprKind.SpecialUnary.Kind.toNat8FromChar:
			return "to-nat8 (from char8)";
		case LowExprKind.SpecialUnary.Kind.toNat64FromNat8:
			return "to-nat (from nat8)";
		case LowExprKind.SpecialUnary.Kind.toNat64FromNat16:
			return "to-nat (from nat16)";
		case LowExprKind.SpecialUnary.Kind.toNat64FromNat32:
			return "to-nat (from nat32)";
		case LowExprKind.SpecialUnary.Kind.toNat64FromPtr:
			return "to-nat (from ptr)";
		case LowExprKind.SpecialUnary.Kind.toPtrFromNat64:
			return "to-ptr (from nat64)";
		case LowExprKind.SpecialUnary.Kind.truncateToInt64FromFloat64:
			return "truncate-to-int (from float64)";
		case LowExprKind.SpecialUnary.Kind.unsafeInt64ToInt8:
			return "unsafe-int64-to-int8";
		case LowExprKind.SpecialUnary.Kind.unsafeInt64ToInt16:
			return "unsafe-int64-to-int16";
		case LowExprKind.SpecialUnary.Kind.unsafeInt64ToInt32:
			return "unsafe-int64-to-int32";
		case LowExprKind.SpecialUnary.Kind.unsafeInt64ToNat64:
			return "unsafe-int64-to-nat64";
		case LowExprKind.SpecialUnary.Kind.unsafeNat64ToInt64:
			return "unsafe-nat64-to-int64";
		case LowExprKind.SpecialUnary.Kind.unsafeNat64ToNat8:
			return "unsafe-nat64-to-nat8";
		case LowExprKind.SpecialUnary.Kind.unsafeNat64ToNat16:
			return "unsafe-nat64-to-nat16";
		case LowExprKind.SpecialUnary.Kind.unsafeNat64ToNat32:
			return "unsafe-nat64-to-nat32";
	}
}

immutable(string) strOfSpecialBinaryKind(immutable LowExprKind.SpecialBinary.Kind a) {
	final switch (a) {
		case LowExprKind.SpecialBinary.Kind.addFloat32:
			return "+ (float32)";
		case LowExprKind.SpecialBinary.Kind.addFloat64:
			return "+ (float64)";
		case LowExprKind.SpecialBinary.Kind.addPtrAndNat64:
			return "+ (ptr + nat64)";
		case LowExprKind.SpecialBinary.Kind.and:
			return "and";
		case LowExprKind.SpecialBinary.Kind.bitwiseAndInt8:
			return "bitwise-and (int8)";
		case LowExprKind.SpecialBinary.Kind.bitwiseAndInt16:
			return "bitwise-and (int16)";
		case LowExprKind.SpecialBinary.Kind.bitwiseAndInt32:
			return "bitwise-and (int32)";
		case LowExprKind.SpecialBinary.Kind.bitwiseAndInt64:
			return "bitwise-and (int64)";
		case LowExprKind.SpecialBinary.Kind.bitwiseAndNat8:
			return "bitwise-and (nat8)";
		case LowExprKind.SpecialBinary.Kind.bitwiseAndNat16:
			return "bitwise-and (nat16)";
		case LowExprKind.SpecialBinary.Kind.bitwiseAndNat32:
			return "bitwise-and (nat32)";
		case LowExprKind.SpecialBinary.Kind.bitwiseAndNat64:
			return "bitwise-and (nat64)";
		case LowExprKind.SpecialBinary.Kind.bitwiseOrInt8:
			return "bitwise-or (int8)";
		case LowExprKind.SpecialBinary.Kind.bitwiseOrInt16:
			return "bitwise-or (int16)";
		case LowExprKind.SpecialBinary.Kind.bitwiseOrInt32:
			return "bitwise-or (int32)";
		case LowExprKind.SpecialBinary.Kind.bitwiseOrInt64:
			return "bitwise-or (int64)";
		case LowExprKind.SpecialBinary.Kind.bitwiseOrNat8:
			return "bitwise-or (nat8)";
		case LowExprKind.SpecialBinary.Kind.bitwiseOrNat16:
			return "bitwise-or (nat16)";
		case LowExprKind.SpecialBinary.Kind.bitwiseOrNat32:
			return "bitwise-or (nat32)";
		case LowExprKind.SpecialBinary.Kind.bitwiseOrNat64:
			return "bitwise-or (nat64)";
		case LowExprKind.SpecialBinary.Kind.bitwiseXorInt8:
			return "bitwise-xor (int8)";
		case LowExprKind.SpecialBinary.Kind.bitwiseXorInt16:
			return "bitwise-xor (int16)";
		case LowExprKind.SpecialBinary.Kind.bitwiseXorInt32:
			return "bitwise-xor (int32)";
		case LowExprKind.SpecialBinary.Kind.bitwiseXorInt64:
			return "bitwise-xor (int64)";
		case LowExprKind.SpecialBinary.Kind.bitwiseXorNat8:
			return "bitwise-xor (nat8)";
		case LowExprKind.SpecialBinary.Kind.bitwiseXorNat16:
			return "bitwise-xor (nat16)";
		case LowExprKind.SpecialBinary.Kind.bitwiseXorNat32:
			return "bitwise-xor (nat32)";
		case LowExprKind.SpecialBinary.Kind.bitwiseXorNat64:
			return "bitwise-xor (nat64)";
		case LowExprKind.SpecialBinary.Kind.eqFloat32:
			return "== (float32)";
		case LowExprKind.SpecialBinary.Kind.eqFloat64:
			return "== (float64)";
		case LowExprKind.SpecialBinary.Kind.eqInt8:
			return "== (int8)";
		case LowExprKind.SpecialBinary.Kind.eqInt16:
			return "== (int16)";
		case LowExprKind.SpecialBinary.Kind.eqInt32:
			return "== (int32)";
		case LowExprKind.SpecialBinary.Kind.eqInt64:
			return "== (int64)";
		case LowExprKind.SpecialBinary.Kind.eqNat8:
			return "== (nat8)";
		case LowExprKind.SpecialBinary.Kind.eqNat16:
			return "== (nat16)";
		case LowExprKind.SpecialBinary.Kind.eqNat32:
			return "== (nat32)";
		case LowExprKind.SpecialBinary.Kind.eqNat64:
			return "== (nat64)";
		case LowExprKind.SpecialBinary.Kind.eqPtr:
			return "ptr-eq?";
		case LowExprKind.SpecialBinary.Kind.lessBool:
			return "< (bool)";
		case LowExprKind.SpecialBinary.Kind.lessChar:
			return "< (char)";
		case LowExprKind.SpecialBinary.Kind.lessFloat32:
			return "< (float32)";
		case LowExprKind.SpecialBinary.Kind.lessFloat64:
			return "< (float32)";
		case LowExprKind.SpecialBinary.Kind.lessInt8:
			return "< (int8)";
		case LowExprKind.SpecialBinary.Kind.lessInt16:
			return "< (int16)";
		case LowExprKind.SpecialBinary.Kind.lessInt32:
			return "< (int32)";
		case LowExprKind.SpecialBinary.Kind.lessInt64:
			return "< (int64)";
		case LowExprKind.SpecialBinary.Kind.lessNat8:
			return "< (nat8)";
		case LowExprKind.SpecialBinary.Kind.lessNat16:
			return "< (nat16)";
		case LowExprKind.SpecialBinary.Kind.lessNat32:
			return "< (nat32)";
		case LowExprKind.SpecialBinary.Kind.lessNat64:
			return "< (nat64)";
		case LowExprKind.SpecialBinary.Kind.lessPtr:
			return "< (ptr)";
		case LowExprKind.SpecialBinary.Kind.mulFloat32:
			return "* (float32)";
		case LowExprKind.SpecialBinary.Kind.mulFloat64:
			return "* (float64)";
		case LowExprKind.SpecialBinary.Kind.orBool:
			return "or (bool)";
		case LowExprKind.SpecialBinary.Kind.subFloat32:
			return "- (float32)";
		case LowExprKind.SpecialBinary.Kind.subFloat64:
			return "- (float64)";
		case LowExprKind.SpecialBinary.Kind.subPtrAndNat64:
			return "- (ptr - nat64)";
		case LowExprKind.SpecialBinary.Kind.unsafeAddInt8:
			return "unsafe-add (int8)";
		case LowExprKind.SpecialBinary.Kind.unsafeAddInt16:
			return "unsafe-add (int16)";
		case LowExprKind.SpecialBinary.Kind.unsafeAddInt32:
			return "unsafe-add (int32)";
		case LowExprKind.SpecialBinary.Kind.unsafeAddInt64:
			return "unsafe-add (int64)";
		case LowExprKind.SpecialBinary.Kind.unsafeBitShiftLeftNat64:
			return "unsafe-bit-shift-left (nat64)";
		case LowExprKind.SpecialBinary.Kind.unsafeBitShiftRightNat64:
			return "unsafe-bit-shift-left (nat64)";
		case LowExprKind.SpecialBinary.Kind.unsafeDivFloat32:
			return "unsafe-div (float32)";
		case LowExprKind.SpecialBinary.Kind.unsafeDivFloat64:
			return "unsafe-div (float64)";
		case LowExprKind.SpecialBinary.Kind.unsafeDivInt8:
			return "unsafe-div (int8)";
		case LowExprKind.SpecialBinary.Kind.unsafeDivInt16:
			return "unsafe-div (int16)";
		case LowExprKind.SpecialBinary.Kind.unsafeDivInt32:
			return "unsafe-div (int32)";
		case LowExprKind.SpecialBinary.Kind.unsafeDivInt64:
			return "unsafe-div (int64)";
		case LowExprKind.SpecialBinary.Kind.unsafeDivNat8:
			return "unsafe-div (nat8)";
		case LowExprKind.SpecialBinary.Kind.unsafeDivNat16:
			return "unsafe-div (nat16)";
		case LowExprKind.SpecialBinary.Kind.unsafeDivNat32:
			return "unsafe-div (nat32)";
		case LowExprKind.SpecialBinary.Kind.unsafeDivNat64:
			return "unsafe-div (nat64)";
		case LowExprKind.SpecialBinary.Kind.unsafeModNat64:
			return "unsafe-mod (nat64)";
		case LowExprKind.SpecialBinary.Kind.unsafeMulInt8:
			return "unsafe-mul (int8)";
		case LowExprKind.SpecialBinary.Kind.unsafeMulInt16:
			return "unsafe-mul (int16)";
		case LowExprKind.SpecialBinary.Kind.unsafeMulInt32:
			return "unsafe-mul (int32)";
		case LowExprKind.SpecialBinary.Kind.unsafeMulInt64:
			return "unsafe-mul (int64)";
		case LowExprKind.SpecialBinary.Kind.unsafeSubInt8:
			return "unsafe-sub (int8)";
		case LowExprKind.SpecialBinary.Kind.unsafeSubInt16:
			return "unsafe-sub (int16)";
		case LowExprKind.SpecialBinary.Kind.unsafeSubInt32:
			return "unsafe-sub (int32)";
		case LowExprKind.SpecialBinary.Kind.unsafeSubInt64:
			return "unsafe-sub (int64)";
		case LowExprKind.SpecialBinary.Kind.wrapAddNat8:
			return "wrap-add (nat8)";
		case LowExprKind.SpecialBinary.Kind.wrapAddNat16:
			return "wrap-add (nat16)";
		case LowExprKind.SpecialBinary.Kind.wrapAddNat32:
			return "wrap-add (nat32)";
		case LowExprKind.SpecialBinary.Kind.wrapAddNat64:
			return "wrap-add (nat64)";
		case LowExprKind.SpecialBinary.Kind.wrapMulNat8:
			return "wrap-mul (nat8)";
		case LowExprKind.SpecialBinary.Kind.wrapMulNat16:
			return "wrap-mul (nat16)";
		case LowExprKind.SpecialBinary.Kind.wrapMulNat32:
			return "wrap-mul (nat32)";
		case LowExprKind.SpecialBinary.Kind.wrapMulNat64:
			return "wrap-mul (nat64)";
		case LowExprKind.SpecialBinary.Kind.wrapSubNat8:
			return "wrap-sub (nat8)";
		case LowExprKind.SpecialBinary.Kind.wrapSubNat16:
			return "wrap-sub (nat16)";
		case LowExprKind.SpecialBinary.Kind.wrapSubNat32:
			return "wrap-sub (nat32)";
		case LowExprKind.SpecialBinary.Kind.wrapSubNat64:
			return "wrap-sub (nat64)";
		case LowExprKind.SpecialBinary.Kind.writeToPtr:
			return "wriite to ptr";
	}
}
