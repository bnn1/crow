module lower.lowExprHelpers;

@safe @nogc pure nothrow:

import lowModel :
	asNonFunPtrType,
	asRecordType,
	isNonFunPtrType,
	LowExpr,
	LowExprKind,
	LowField,
	LowFun,
	LowFunIndex,
	LowLocal,
	LowParamIndex,
	LowType,
	PrimitiveType;
import util.collection.arr : Arr, emptyArr;
import util.memory : allocate;
import util.ptr : Ptr;
import util.sourceRange : SourceRange;
import util.types : u8;
import util.util : todo;

immutable LowType boolType = immutable LowType(PrimitiveType.bool_);
immutable LowType charType = immutable LowType(PrimitiveType.char_);
immutable LowType charPtrType = immutable LowType(immutable LowType.NonFunPtr(immutable Ptr!LowType(&charType)));
immutable LowType charPtrPtrType = immutable LowType(immutable LowType.NonFunPtr(immutable Ptr!LowType(&charPtrType)));
immutable LowType int32Type = immutable LowType(PrimitiveType.int32);
immutable LowType nat8Type = immutable LowType(PrimitiveType.nat8);
immutable LowType nat64Type = immutable LowType(PrimitiveType.nat64);
immutable LowType anyPtrType = immutable LowType(immutable LowType.NonFunPtr(immutable Ptr!LowType(&nat8Type)));
immutable LowType voidType = immutable LowType(PrimitiveType.void_);

immutable(LowExpr) addPtr(Alloc)(
	ref Alloc alloc,
	ref immutable LowType ptrType,
	ref immutable SourceRange range,
	ref immutable LowExpr ptr,
	immutable size_t value,
) {
	return immutable LowExpr(
		ptrType,
		range,
		immutable LowExprKind(immutable LowExprKind.SpecialBinary(
			LowExprKind.SpecialBinary.Kind.addPtr,
			allocate(alloc, ptr),
			allocate(alloc, constantNat64(range, value)))));
}

immutable(LowExpr) genDeref(Alloc)(
	ref Alloc alloc,
	ref immutable SourceRange range,
	immutable LowExpr ptr,
) {
	return genUnary(alloc, range, asNonFunPtrType(ptr.type).pointee, LowExprKind.SpecialUnary.Kind.deref, ptr);
}

immutable(LowExpr) genUnary(Alloc)(
	ref Alloc alloc,
	ref immutable SourceRange range,
	immutable LowType type,
	immutable LowExprKind.SpecialUnary.Kind kind,
	immutable LowExpr arg,
) {
	return immutable LowExpr(
		type,
		range,
		immutable LowExprKind(immutable LowExprKind.SpecialUnary(kind, allocate(alloc, arg))));
}

immutable(LowExpr) genIf(Alloc)(
	ref Alloc alloc,
	ref immutable SourceRange range,
	immutable LowExpr cond,
	immutable LowExpr then,
	immutable LowExpr else_,
) {
	return immutable LowExpr(
		then.type,
		range,
		immutable LowExprKind(immutable LowExprKind.SpecialTrinary(
			LowExprKind.SpecialTrinary.Kind.if_,
			allocate(alloc, cond),
			allocate(alloc, then),
			allocate(alloc, else_))));
}

immutable(LowExpr) genNat64Eq0(Alloc)(
	ref Alloc alloc,
	ref immutable SourceRange range,
	immutable LowExpr a,
) {
	return genBinary(alloc, range, boolType, LowExprKind.SpecialBinary.Kind.eqNat64, a, constantNat64(range, 0));
}

immutable(LowExpr) incrPointer(Alloc)(
	ref Alloc alloc,
	ref immutable SourceRange range,
	ref immutable LowType ptrType,
	ref immutable LowExpr ptr,
) {
	return addPtr(alloc, ptrType, range, ptr, 1);
}

immutable(LowExpr) constantNat64(
	ref immutable SourceRange range,
	immutable size_t value,
) {
	return immutable LowExpr(
		nat64Type,
		range,
		immutable LowExprKind(immutable LowExprKind.SpecialConstant(
			immutable LowExprKind.SpecialConstant.Integral(value))));
}

immutable(LowExpr) genCreateRecord(
	ref immutable SourceRange range,
	immutable LowType.Record record,
	immutable Arr!LowExpr args,
) {
	return immutable LowExpr(
		immutable LowType(record),
		range,
		immutable LowExprKind(immutable LowExprKind.CreateRecord(args)));
}

immutable(LowExpr) genCreateRecord(ref immutable SourceRange range, immutable LowType.Record record) {
	return genCreateRecord(range, record, emptyArr!LowExpr);
}

immutable(LowExpr) genCreateUnion(Alloc)(
	ref Alloc alloc,
	ref immutable SourceRange range,
	immutable LowType.Union union_,
	immutable u8 memberIndex,
	immutable LowExpr member,
) {
	return immutable LowExpr(
		immutable LowType(union_),
		range,
		immutable LowExprKind(immutable LowExprKind.ConvertToUnion(memberIndex, allocate(alloc, member))));
}

immutable(LowExpr) genBinary(Alloc)(
	ref Alloc alloc,
	ref immutable SourceRange range,
	immutable LowType returnType,
	immutable LowExprKind.SpecialBinary.Kind kind,
	immutable LowExpr a,
	immutable LowExpr b,
) {
	return immutable LowExpr(
		returnType,
		range,
		immutable LowExprKind(immutable LowExprKind.SpecialBinary(kind, allocate(alloc, a), allocate(alloc, b))));
}

immutable(LowExpr) decrNat64(Alloc)(
	ref Alloc alloc,
	ref immutable SourceRange range,
	immutable LowExpr arg,
) {
	return immutable LowExpr(
		nat64Type,
		range,
		immutable LowExprKind(immutable LowExprKind.SpecialBinary(
			LowExprKind.SpecialBinary.Kind.wrapSubNat64,
			allocate(alloc, arg),
			allocate(alloc, constantNat64(range, 1)))));
}

immutable(LowExpr) genCall(Alloc)(
	ref Alloc alloc,
	ref immutable SourceRange range,
	immutable LowFunIndex called,
	immutable LowType returnType,
	immutable Arr!LowExpr args,
) {
	return immutable LowExpr(
		returnType,
		range,
		immutable LowExprKind(immutable LowExprKind.Call(called, args)));
}

immutable(LowExpr) getSizeOf(immutable SourceRange range, immutable LowType t) {
	return immutable LowExpr(nat64Type, range, immutable LowExprKind(immutable LowExprKind.SizeOf(t)));
}

immutable(LowExpr) localRef(Alloc)(ref Alloc alloc, ref immutable SourceRange range, immutable Ptr!LowLocal local) {
	return immutable LowExpr(local.type, range, immutable LowExprKind(immutable LowExprKind.LocalRef(local)));
}

immutable(LowExpr) genLet(Alloc)(
	ref Alloc alloc,
	ref immutable SourceRange range,
	immutable Ptr!LowLocal local,
	immutable LowExpr value,
	immutable LowExpr then,
) {
	return immutable LowExpr(
		then.type,
		range,
		immutable LowExprKind(immutable LowExprKind.Let(
			local,
			allocate(alloc, value),
			allocate(alloc, then))));
}

immutable(LowExpr) paramRef(
	ref immutable SourceRange range,
	ref immutable LowType type,
	immutable LowParamIndex param,
) {
	return immutable LowExpr(
		type,
		range,
		immutable LowExprKind(immutable LowExprKind.ParamRef(param)));
}

immutable(LowExpr) wrapMulNat64(Alloc)(
	ref Alloc alloc,
	ref immutable SourceRange range,
	ref immutable LowExpr left,
	ref immutable LowExpr right,
) {
	return immutable LowExpr(
		nat64Type,
		range,
		immutable LowExprKind(immutable LowExprKind.SpecialBinary(
			LowExprKind.SpecialBinary.Kind.wrapMulNat64,
			allocate(alloc, left),
			allocate(alloc, right))));
}

immutable(LowExpr) ptrCast(Alloc)(
	ref Alloc alloc,
	ref immutable LowType type,
	ref immutable SourceRange range,
	immutable LowExpr inner,
) {
	return immutable LowExpr(type, range, ptrCastKind(alloc, inner));
}

immutable(LowExprKind) ptrCastKind(Alloc)(ref Alloc alloc, immutable LowExpr inner) {
	return immutable LowExprKind(immutable LowExprKind.PtrCast(allocate(alloc, inner)));
}

immutable(LowExpr) recordFieldAccess(Alloc)(
	ref Alloc alloc,
	ref immutable SourceRange range,
	ref immutable LowExpr target,
	immutable Ptr!LowField field,
) {
	immutable LowType.Record recordType = asRecordType(isNonFunPtrType(target.type)
		? asNonFunPtrType(target.type).pointee
		: target.type);
	return immutable LowExpr(field.type, range, immutable LowExprKind(
		immutable LowExprKind.RecordFieldAccess(
			allocate(alloc, target),
			isNonFunPtrType(target.type),
			recordType,
			field)));
}

immutable(LowExpr) seq(Alloc)(
	ref Alloc alloc,
	ref immutable SourceRange range,
	immutable LowExpr first,
	immutable LowExpr then,
) {
	return immutable LowExpr(
		then.type,
		range,
		immutable LowExprKind(immutable LowExprKind.Seq(allocate(alloc, first), allocate(alloc, then))));
}

immutable(LowExpr) writeToPtr(Alloc)(
	ref Alloc alloc,
	ref immutable SourceRange range,
	ref immutable LowExpr ptr,
	ref immutable LowExpr value,
) {
	return immutable LowExpr(voidType, range, immutable LowExprKind(
		immutable LowExprKind.SpecialBinary(
			LowExprKind.SpecialBinary.Kind.writeToPtr,
			allocate(alloc, ptr),
			allocate(alloc, value))));
}
