module lower.getBuiltinCall;

@safe @nogc pure nothrow:

import constant : Constant;
import lowModel :
	asPrimitive,
	isFunPtrType,
	isNonFunPtrType,
	isPrimitive,
	LowExprKind,
	LowType,
	PrimitiveType;
import util.bools : Bool, False, True;
import util.collection.arr : size;
import util.sym : shortSymAlphaLiteralValue, shortSymOperatorLiteralValue, Sym, symEqLongAlphaLiteral;
import util.util : todo;

struct BuiltinKind {
	@safe @nogc pure nothrow:

	struct As {}
	struct GetCtx {}
	struct PtrCast {}
	struct SizeOf {}

	immutable this(immutable As a) { kind_ = Kind.as; as_ = a; }
	immutable this(immutable GetCtx a) { kind_ = Kind.getCtx; getCtx_ = a; }
	@trusted immutable this(immutable Constant a) { kind_ = Kind.constant; constant_ = a; }
	immutable this(immutable LowExprKind.SpecialUnary.Kind a) { kind_ = Kind.unary; unary_ = a; }
	immutable this(immutable LowExprKind.SpecialBinary.Kind a) { kind_ = Kind.binary; binary_ = a; }
	immutable this(immutable LowExprKind.SpecialTrinary.Kind a) { kind_ = Kind.trinary; trinary_ = a; }
	immutable this(immutable LowExprKind.SpecialNAry.Kind a) { kind_ = Kind.nary; nary_ = a; }
	immutable this(immutable PtrCast a) { kind_ = Kind.ptrCast; ptrCast_ = a; }
	immutable this(immutable SizeOf a) { kind_ = Kind.sizeOf; sizeOf_ = a; }

	private:
	enum Kind {
		as,
		getCtx,
		constant,
		unary,
		binary,
		trinary,
		nary,
		ptrCast,
		sizeOf,
	}
	immutable Kind kind_;
	union {
		immutable As as_;
		immutable GetCtx getCtx_;
		immutable Constant constant_;
		immutable LowExprKind.SpecialUnary.Kind unary_;
		immutable LowExprKind.SpecialBinary.Kind binary_;
		immutable LowExprKind.SpecialTrinary.Kind trinary_;
		immutable LowExprKind.SpecialNAry.Kind nary_;
		immutable SizeOf sizeOf_;
		immutable PtrCast ptrCast_;
	}
}

@trusted T matchBuiltinKind(T)(
	ref immutable BuiltinKind a,
	scope T delegate(ref immutable BuiltinKind.As) @safe @nogc pure nothrow cbAs,
	scope T delegate(ref immutable BuiltinKind.GetCtx) @safe @nogc pure nothrow cbGetCtx,
	scope T delegate(ref immutable Constant) @safe @nogc pure nothrow cbConstant,
	scope T delegate(immutable LowExprKind.SpecialUnary.Kind) @safe @nogc pure nothrow cbUnary,
	scope T delegate(immutable LowExprKind.SpecialBinary.Kind) @safe @nogc pure nothrow cbBinary,
	scope T delegate(immutable LowExprKind.SpecialTrinary.Kind) @safe @nogc pure nothrow cbTrinary,
	scope T delegate(immutable LowExprKind.SpecialNAry.Kind) @safe @nogc pure nothrow cbNary,
	scope T delegate(ref immutable BuiltinKind.PtrCast) @safe @nogc pure nothrow cbPtrCast,
	scope T delegate(ref immutable BuiltinKind.SizeOf) @safe @nogc pure nothrow cbSizeOf,
) {
	final switch (a.kind_) {
		case BuiltinKind.Kind.as:
			return cbAs(a.as_);
		case BuiltinKind.Kind.getCtx:
			return cbGetCtx(a.getCtx_);
		case BuiltinKind.Kind.constant:
			return cbConstant(a.constant_);
		case BuiltinKind.Kind.unary:
			return cbUnary(a.unary_);
		case BuiltinKind.Kind.binary:
			return cbBinary(a.binary_);
		case BuiltinKind.Kind.trinary:
			return cbTrinary(a.trinary_);
		case BuiltinKind.Kind.nary:
			return cbNary(a.nary_);
		case BuiltinKind.Kind.ptrCast:
			return cbPtrCast(a.ptrCast_);
		case BuiltinKind.Kind.sizeOf:
			return cbSizeOf(a.sizeOf_);
	}
}

immutable(BuiltinKind) getBuiltinKind(
	immutable Sym name,
	ref immutable LowType rt,
	ref immutable LowType p0,
	ref immutable LowType p1,
) {
	immutable(BuiltinKind) constant(immutable Constant kind) {
		return immutable BuiltinKind(kind);
	}
	immutable(BuiltinKind) constantBool(immutable Bool value) {
		return constant(immutable Constant(immutable Constant.BoolConstant(value)));
	}
	immutable(BuiltinKind) constantIntegral(int value) {
		return constant(immutable Constant(immutable Constant.Integral(value)));
	}
	immutable(BuiltinKind) unary(immutable LowExprKind.SpecialUnary.Kind kind) {
		return immutable BuiltinKind(kind);
	}
	immutable(BuiltinKind) binary(immutable LowExprKind.SpecialBinary.Kind kind) {
		return immutable BuiltinKind(kind);
	}
	immutable(BuiltinKind) trinary(immutable LowExprKind.SpecialTrinary.Kind kind) {
		return immutable BuiltinKind(kind);
	}
	immutable(BuiltinKind) nAry(immutable LowExprKind.SpecialNAry.Kind kind) {
		return immutable BuiltinKind(kind);
	}

	immutable(T) failT(T)() {
		debug {
			import util.alloc.stackAlloc : StackAlloc;
			import util.sym : strOfSym;
			import util.print : print;
			StackAlloc!("temp", 1024) alloc;
			print(strOfSym(alloc, name));
		}
		return todo!T("not a builtin fun");
	}
	immutable(BuiltinKind) fail() {
		return failT!(immutable BuiltinKind);
	}
	immutable(LowExprKind.SpecialUnary.Kind) failUnary() {
		return failT!(immutable LowExprKind.SpecialUnary.Kind);
	}
	immutable(LowExprKind.SpecialBinary.Kind) failBinary() {
		return failT!(immutable LowExprKind.SpecialBinary.Kind);
	}

	switch (name.value) {
		case shortSymOperatorLiteralValue("+"):
			return binary(isFloat64(rt)
					? LowExprKind.SpecialBinary.Kind.addFloat64
					: isNonFunPtrType(rt)
					? LowExprKind.SpecialBinary.Kind.addPtr
					: failBinary());
		case shortSymOperatorLiteralValue("-"):
			return binary(isFloat64(rt)
				? LowExprKind.SpecialBinary.Kind.subFloat64
				: isNonFunPtrType(p0) && isNat64(p1)
				? LowExprKind.SpecialBinary.Kind.subPtrNat
				: failBinary());
		case shortSymOperatorLiteralValue("*"):
			return binary(isFloat64(rt) ? LowExprKind.SpecialBinary.Kind.mulFloat64 : failBinary());
		case shortSymAlphaLiteralValue("as-any-ptr"):
			return unary(LowExprKind.SpecialUnary.Kind.asAnyPtr);
		case shortSymAlphaLiteralValue("and"):
			return binary(LowExprKind.SpecialBinary.Kind.and);
		case shortSymAlphaLiteralValue("as"):
			return immutable BuiltinKind(immutable BuiltinKind.As());
		case shortSymAlphaLiteralValue("as-ref"):
			return unary(LowExprKind.SpecialUnary.Kind.asRef);
		case shortSymAlphaLiteralValue("bits-and"):
			return binary(isInt8(rt)
				? LowExprKind.SpecialBinary.Kind.bitwiseAndInt8
				: isInt16(rt)
				? LowExprKind.SpecialBinary.Kind.bitwiseAndInt16
				: isInt32(rt)
				? LowExprKind.SpecialBinary.Kind.bitwiseAndInt32
				: isInt64(rt)
				? LowExprKind.SpecialBinary.Kind.bitwiseAndInt64
				: isNat8(rt)
				? LowExprKind.SpecialBinary.Kind.bitwiseAndNat8
				: isNat16(rt)
				? LowExprKind.SpecialBinary.Kind.bitwiseAndNat16
				: isNat32(rt)
				? LowExprKind.SpecialBinary.Kind.bitwiseAndNat32
				: isNat64(rt)
				? LowExprKind.SpecialBinary.Kind.bitwiseAndNat64
				: failBinary());
		case shortSymAlphaLiteralValue("bits-or"):
			return binary(isInt8(rt)
				? LowExprKind.SpecialBinary.Kind.bitwiseOrInt8
				: isInt16(rt)
				? LowExprKind.SpecialBinary.Kind.bitwiseOrInt16
				: isInt32(rt)
				? LowExprKind.SpecialBinary.Kind.bitwiseOrInt32
				: isInt64(rt)
				? LowExprKind.SpecialBinary.Kind.bitwiseOrInt64
				: isNat8(rt)
				? LowExprKind.SpecialBinary.Kind.bitwiseOrNat8
				: isNat16(rt)
				? LowExprKind.SpecialBinary.Kind.bitwiseOrNat16
				: isNat32(rt)
				? LowExprKind.SpecialBinary.Kind.bitwiseOrNat32
				: isNat64(rt)
				? LowExprKind.SpecialBinary.Kind.bitwiseOrNat64
				: failBinary());
		case shortSymAlphaLiteralValue("call"):
			return isFunPtrType(p0)
				? nAry(LowExprKind.SpecialNAry.Kind.callFunPtr)
				: fail();
		case shortSymAlphaLiteralValue("deref"):
			return unary(LowExprKind.SpecialUnary.Kind.deref);
		case shortSymAlphaLiteralValue("false"):
			return constantBool(False);
		case shortSymAlphaLiteralValue("get-ctx"):
			return immutable BuiltinKind(immutable BuiltinKind.GetCtx());
		case shortSymAlphaLiteralValue("hard-fail"):
			return unary(LowExprKind.SpecialUnary.Kind.hardFail);
		case shortSymAlphaLiteralValue("if"):
			return trinary(LowExprKind.SpecialTrinary.Kind.if_);
		case shortSymAlphaLiteralValue("not"):
			return unary(LowExprKind.SpecialUnary.Kind.not);
		case shortSymAlphaLiteralValue("null"):
			return constant(immutable Constant(immutable Constant.Null()));
		case shortSymAlphaLiteralValue("one"):
			return isIntegral(rt) ? constantIntegral(1) : fail();
		case shortSymAlphaLiteralValue("or"):
			return binary(LowExprKind.SpecialBinary.Kind.or);
		case shortSymAlphaLiteralValue("pass"):
			return constant(immutable Constant(immutable Constant.Void()));
		case shortSymAlphaLiteralValue("ptr-cast"):
			return immutable BuiltinKind(immutable BuiltinKind.PtrCast());
		case shortSymAlphaLiteralValue("ptr-eq?"):
			return binary(LowExprKind.SpecialBinary.Kind.eqPtr);
		case shortSymAlphaLiteralValue("ptr-to"):
			return unary(LowExprKind.SpecialUnary.Kind.ptrTo);
		case shortSymAlphaLiteralValue("ref-of-val"):
			return unary(LowExprKind.SpecialUnary.Kind.refOfVal);
		case shortSymAlphaLiteralValue("set"):
			return isNonFunPtrType(p0) ? binary(LowExprKind.SpecialBinary.Kind.writeToPtr) : fail();
		case shortSymAlphaLiteralValue("size-of"):
			return immutable BuiltinKind(immutable BuiltinKind.SizeOf());
		case shortSymAlphaLiteralValue("to-float"):
			return unary(isInt64(p0)
				? LowExprKind.SpecialUnary.Kind.toFloat64FromInt64
				: isNat64(p0)
				? LowExprKind.SpecialUnary.Kind.toFloat64FromNat64
				: failUnary());
		case shortSymAlphaLiteralValue("to-int"):
			return unary(isInt16(p0)
				? LowExprKind.SpecialUnary.Kind.toIntFromInt16
				: isInt32(p0)
				? LowExprKind.SpecialUnary.Kind.toIntFromInt32
				: failUnary());
		case shortSymAlphaLiteralValue("to-nat"):
			return unary(isNat8(p0)
				? LowExprKind.SpecialUnary.Kind.toNatFromNat8
				: isNat16(p0)
				? LowExprKind.SpecialUnary.Kind.toNatFromNat16
				: isNat32(p0)
				? LowExprKind.SpecialUnary.Kind.toNatFromNat32
				: isNonFunPtrType(p0)
				? LowExprKind.SpecialUnary.Kind.toNatFromPtr
				: failUnary());
		case shortSymAlphaLiteralValue("true"):
			return constantBool(True);
		case shortSymAlphaLiteralValue("unsafe-div"):
			return binary(isFloat64(rt)
				? LowExprKind.SpecialBinary.Kind.unsafeDivFloat64
				: isInt64(rt)
				? LowExprKind.SpecialBinary.Kind.unsafeDivInt64
				: isNat64(rt)
				? LowExprKind.SpecialBinary.Kind.unsafeDivNat64
				: failBinary());
		case shortSymAlphaLiteralValue("wrap-add"):
			return binary(isInt16(rt)
				? LowExprKind.SpecialBinary.Kind.wrapAddInt16
				: isInt32(rt)
				? LowExprKind.SpecialBinary.Kind.wrapAddInt32
				: isInt64(rt)
				? LowExprKind.SpecialBinary.Kind.wrapAddInt64
				: isNat8(rt)
				? LowExprKind.SpecialBinary.Kind.wrapAddNat8
				: isNat16(rt)
				? LowExprKind.SpecialBinary.Kind.wrapAddNat16
				: isNat32(rt)
				? LowExprKind.SpecialBinary.Kind.wrapAddNat32
				: isNat64(rt)
				? LowExprKind.SpecialBinary.Kind.wrapAddNat64
				: failBinary());
		case shortSymAlphaLiteralValue("wrap-mul"):
			return binary(isInt16(rt)
				? LowExprKind.SpecialBinary.Kind.wrapMulInt16
				: isInt32(rt)
				? LowExprKind.SpecialBinary.Kind.wrapMulInt32
				: isInt64(rt)
				? LowExprKind.SpecialBinary.Kind.wrapMulInt64
				: isNat16(rt)
				? LowExprKind.SpecialBinary.Kind.wrapMulNat16
				: isNat32(rt)
				? LowExprKind.SpecialBinary.Kind.wrapMulNat32
				: isNat64(rt)
				? LowExprKind.SpecialBinary.Kind.wrapMulNat64
				: failBinary());
		case shortSymAlphaLiteralValue("wrap-sub"):
			return binary(isInt16(rt)
				? LowExprKind.SpecialBinary.Kind.wrapSubInt16
				: isInt32(rt)
				? LowExprKind.SpecialBinary.Kind.wrapSubInt32
				: isInt64(rt)
				? LowExprKind.SpecialBinary.Kind.wrapSubInt64
				: isNat8(rt)
				? LowExprKind.SpecialBinary.Kind.wrapSubNat8
				: isNat16(rt)
				? LowExprKind.SpecialBinary.Kind.wrapSubNat16
				: isNat32(rt)
				? LowExprKind.SpecialBinary.Kind.wrapSubNat32
				: isNat64(rt)
				? LowExprKind.SpecialBinary.Kind.wrapSubNat64
				: failBinary());
		case shortSymAlphaLiteralValue("zero"):
			return isIntegral(rt) ? constantIntegral(0) : fail();
		case shortSymAlphaLiteralValue("unsafe-mod"):
			return isNat64(rt) ? binary(LowExprKind.SpecialBinary.Kind.unsafeModNat64) : fail();
		default:
			if (symEqLongAlphaLiteral(name, "unsafe-bit-shift-left"))
				return isNat64(rt) ? binary(LowExprKind.SpecialBinary.Kind.unsafeBitShiftLeftNat64) : fail();
			else if (symEqLongAlphaLiteral(name, "unsafe-bit-shift-right"))
				return isNat64(rt)
					? binary(LowExprKind.SpecialBinary.Kind.unsafeBitShiftRightNat64)
					: fail();
			else if (symEqLongAlphaLiteral(name, "compare-exchange-strong"))
				return trinary(LowExprKind.SpecialTrinary.Kind.compareExchangeStrongBool);
			else if (symEqLongAlphaLiteral(name, "is-reference-type?"))
				return todo!(immutable BuiltinKind)("is-reference-type?");
			else if (symEqLongAlphaLiteral(name, "truncate-to-int"))
				return unary(LowExprKind.SpecialUnary.Kind.truncateToInt64FromFloat64);
			else if (symEqLongAlphaLiteral(name, "unsafe-to-int"))
				return isNat64(p0) ? unary(LowExprKind.SpecialUnary.Kind.unsafeNat64ToInt64) : fail();
			else if (symEqLongAlphaLiteral(name, "unsafe-to-int8"))
				return isInt64(p0) ? unary(LowExprKind.SpecialUnary.Kind.unsafeInt64ToInt8) : fail();
			else if (symEqLongAlphaLiteral(name, "unsafe-to-int16"))
				return isInt64(p0) ? unary(LowExprKind.SpecialUnary.Kind.unsafeInt64ToInt16) : fail();
			else if (symEqLongAlphaLiteral(name, "unsafe-to-int32"))
				return isInt64(p0) ? unary(LowExprKind.SpecialUnary.Kind.unsafeInt64ToInt32) : fail();
			else if (symEqLongAlphaLiteral(name, "unsafe-to-nat"))
				return isInt64(p0) ? unary(LowExprKind.SpecialUnary.Kind.unsafeInt64ToNat64) : fail();
			else if (symEqLongAlphaLiteral(name, "unsafe-to-nat8"))
				return isNat64(p0) ? unary(LowExprKind.SpecialUnary.Kind.unsafeNat64ToNat8) : fail();
			else if (symEqLongAlphaLiteral(name, "unsafe-to-nat16"))
				return isNat64(p0) ? unary(LowExprKind.SpecialUnary.Kind.unsafeNat64ToNat16): fail();
			else if (symEqLongAlphaLiteral(name, "unsafe-to-nat32"))
				return isNat64(p0) ? unary(LowExprKind.SpecialUnary.Kind.unsafeNat64ToNat32) : fail();
			else
				return fail();
	}
}

private:

immutable(Bool) isPrimitiveType(ref immutable LowType t, immutable PrimitiveType p) {
	return immutable Bool(isPrimitive(t) && asPrimitive(t) == p);
}

immutable(Bool) isInt8(ref immutable LowType t) {
	return isPrimitiveType(t, PrimitiveType.int8);
}

immutable(Bool) isInt16(ref immutable LowType t) {
	return isPrimitiveType(t, PrimitiveType.int16);
}

immutable(Bool) isInt32(ref immutable LowType t) {
	return isPrimitiveType(t, PrimitiveType.int32);
}

immutable(Bool) isInt64(ref immutable LowType t) {
	return isPrimitiveType(t, PrimitiveType.int64);
}

immutable(Bool) isNat8(ref immutable LowType t) {
	return isPrimitiveType(t, PrimitiveType.nat8);
}

immutable(Bool) isNat16(ref immutable LowType t) {
	return isPrimitiveType(t, PrimitiveType.nat16);
}

immutable(Bool) isNat32(ref immutable LowType t) {
	return isPrimitiveType(t, PrimitiveType.nat32);
}

immutable(Bool) isNat64(ref immutable LowType t) {
	return isPrimitiveType(t, PrimitiveType.nat64);
}

immutable(Bool) isFloat64(ref immutable LowType t) {
	return isPrimitiveType(t, PrimitiveType.float64);
}

immutable(Bool) isIntegral(ref immutable LowType t) {
	return immutable Bool(isPrimitive(t) && () {
		final switch (asPrimitive(t)) {
			case PrimitiveType.int8:
			case PrimitiveType.int16:
			case PrimitiveType.int32:
			case PrimitiveType.int64:
			case PrimitiveType.nat8:
			case PrimitiveType.nat16:
			case PrimitiveType.nat32:
			case PrimitiveType.nat64:
				return True;
			case PrimitiveType.bool_:
			case PrimitiveType.char_:
			case PrimitiveType.float64:
			case PrimitiveType.void_:
				return False;
		}
	}());
}
