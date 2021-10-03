module model.lowModel;

@safe @nogc pure nothrow:

import model.concreteModel :
	ConcreteField,
	ConcreteFun,
	concreteFunRange,
	ConcreteLocal,
	ConcreteParam,
	ConcreteStruct,
	ConcreteStructSource,
	isArr,
	matchConcreteStructSource,
	name,
	typeSize,
	TypeSize;
import model.constant : Constant;
import model.model : asRecord, body_, EnumValue;
import util.collection.dict : Dict;
import util.collection.fullIndexDict : FullIndexDict;
import util.comparison : compareEnum, compareSizeT, Comparison;
import util.opt : none, Opt;
import util.ptr : comparePtr, Ptr;
import util.sourceRange : FileAndRange;
import util.sym : shortSymAlphaLiteral, Sym;
import util.types : Nat16;
import util.util : verify;

struct LowExternPtrType {
	immutable Ptr!ConcreteStruct source;
}

struct LowRecord {
	@safe @nogc pure nothrow:

	immutable Ptr!ConcreteStruct source;
	immutable LowField[] fields;

	//TODO:MOVE
	immutable(bool) packed() immutable {
		return matchConcreteStructSource!(immutable bool)(
			source.source,
			(ref immutable ConcreteStructSource.Inst it) =>
				asRecord(body_(it.inst)).flags.packed,
			(ref immutable ConcreteStructSource.Lambda) =>
				false);
	}
}

immutable(TypeSize) typeSize(ref immutable LowRecord a) {
	return typeSize(a.source);
}

immutable(bool) isArr(ref immutable LowRecord a) {
	return isArr(a.source.deref());
}

struct LowUnion {
	immutable Ptr!ConcreteStruct source;
	immutable LowType[] members;
}

immutable(TypeSize) typeSize(ref immutable LowUnion a) {
	return typeSize(a.source);
}

struct LowFunPtrType {
	immutable Ptr!ConcreteStruct source;
	immutable LowType returnType;
	immutable LowType[] paramTypes;
}

enum PrimitiveType {
	bool_,
	char_,
	float32,
	float64,
	int8,
	int16,
	int32,
	int64,
	nat8,
	nat16,
	nat32,
	nat64,
	void_,
}

immutable(Sym) symOfPrimitiveType(immutable PrimitiveType a) {
	return shortSymAlphaLiteral(() {
		final switch (a) {
			case PrimitiveType.bool_:
				return "bool";
			case PrimitiveType.char_:
				return "char";
			case PrimitiveType.float32:
				return "float-32";
			case PrimitiveType.float64:
				return "float-64";
			case PrimitiveType.int8:
				return "int-8";
			case PrimitiveType.int16:
				return "int-16";
			case PrimitiveType.int32:
				return "int-32";
			case PrimitiveType.int64:
				return "int-64";
			case PrimitiveType.nat8:
				return "nat-8";
			case PrimitiveType.nat16:
				return "nat-16";
			case PrimitiveType.nat32:
				return "nat-32";
			case PrimitiveType.nat64:
				return "nat-64";
			case PrimitiveType.void_:
				return "void";
		}
	}());
}

struct LowType {
	@safe @nogc pure nothrow:

	struct ExternPtr {
		immutable size_t index;
	}
	struct FunPtr {
		immutable size_t index;
	}
	// May be gc-allocated or not; gc will try to trace
	struct PtrGc {
		immutable Ptr!LowType pointee;
	}
	struct PtrRaw {
		immutable Ptr!LowType pointee;
	}
	struct Record {
		immutable size_t index;
	}
	struct Union {
		immutable size_t index;
	}

	private:
	enum Kind {
		externPtr,
		funPtr,
		primitive,
		ptrGc,
		ptrRaw,
		record,
		union_,
	}
	immutable Kind kind_;
	union {
		immutable ExternPtr externPtr_;
		immutable FunPtr funPtr_;
		immutable PrimitiveType primitive_;
		immutable PtrGc ptrGc_;
		immutable PtrRaw ptrRaw_;
		immutable Record record_;
		immutable Union union_;
	}

	public:
	immutable this(immutable ExternPtr a) { kind_ = Kind.externPtr; externPtr_ = a; }
	immutable this(immutable FunPtr a) { kind_ = Kind.funPtr; funPtr_ = a; }
	@trusted immutable this(immutable PtrGc a) { kind_ = Kind.ptrGc; ptrGc_ = a; }
	@trusted immutable this(immutable PtrRaw a) { kind_ = Kind.ptrRaw; ptrRaw_ = a; }
	immutable this(immutable PrimitiveType a) { kind_ = Kind.primitive; primitive_ = a; }
	immutable this(immutable Record a) { kind_ = Kind.record; record_ = a; }
	immutable this(immutable Union a) { kind_ = Kind.union_; union_ = a; }
}
static assert(LowType.sizeof <= 16);

@trusted immutable(Comparison) compareLowType(ref immutable LowType a, ref immutable LowType b) {
	immutable Comparison compareKind = compareEnum(a.kind_, b.kind_);
	if (compareKind != Comparison.equal)
		return compareKind;
	else {
		final switch (a.kind_) {
			case LowType.Kind.externPtr:
				return compareSizeT(a.externPtr_.index, b.externPtr_.index);
			case LowType.Kind.funPtr:
				return compareSizeT(a.funPtr_.index, b.funPtr_.index);
			case LowType.Kind.primitive:
				return compareEnum(a.primitive_, b.primitive_);
			case LowType.Kind.ptrGc:
				return compareLowType(a.ptrGc_.pointee, b.ptrGc_.pointee);
			case LowType.Kind.ptrRaw:
				return compareLowType(a.ptrRaw_.pointee, b.ptrRaw_.pointee);
			case LowType.Kind.record:
				return compareSizeT(a.record_.index, b.record_.index);
			case LowType.Kind.union_:
				return compareSizeT(a.union_.index, b.union_.index);
		}
	}
}

immutable(bool) lowTypeEqual(ref immutable LowType a, ref immutable LowType b) {
	return a.kind_ == b.kind_ && () {
		final switch (a.kind_) {
			case LowType.Kind.externPtr:
				return a.externPtr_.index == b.externPtr_.index;
			case LowType.Kind.funPtr:
				return a.funPtr_.index == b.funPtr_.index;
			case LowType.Kind.primitive:
				return a.primitive_ == b.primitive_;
			case LowType.Kind.ptrGc:
				return lowTypeEqual(a.ptrGc_.pointee, b.ptrGc_.pointee);
			case LowType.Kind.ptrRaw:
				return lowTypeEqual(a.ptrRaw_.pointee, b.ptrRaw_.pointee);
			case LowType.Kind.record:
				return a.record_.index == b.record_.index;
			case LowType.Kind.union_:
				return a.union_.index == b.union_.index;
		}
	}();
}

immutable(bool) isPrimitive(ref immutable LowType a) {
	return a.kind_ == LowType.Kind.primitive;
}

immutable(PrimitiveType) asPrimitive(ref immutable LowType a) {
	verify(isPrimitive(a));
	return a.primitive_;
}

immutable(bool) isChar(ref immutable LowType a) {
	return isPrimitive(a) && asPrimitive(a) == PrimitiveType.char_;
}

immutable(bool) isVoid(ref immutable LowType a) {
	return isPrimitive(a) && asPrimitive(a) == PrimitiveType.void_;
}

immutable(bool) isFunPtrType(ref immutable LowType a) {
	return a.kind_ == LowType.Kind.funPtr;
}

immutable(bool) isPtrGc(ref immutable LowType a) {
	return a.kind_ == LowType.Kind.ptrGc;
}

immutable(bool) isPtrRaw(ref immutable LowType a) {
	return a.kind_ == LowType.Kind.ptrRaw;
}

@trusted immutable(LowType.PtrGc) asPtrGc(ref immutable LowType a) {
	verify(isPtrGc(a));
	return a.ptrGc_;
}

@trusted immutable(LowType.PtrRaw) asPtrRaw(ref immutable LowType a) {
	verify(isPtrRaw(a));
	return a.ptrRaw_;
}

private immutable(bool) isPtrGcOrRaw(ref immutable LowType a) {
	return isPtrGc(a) || isPtrRaw(a);
}

@trusted immutable(Ptr!LowType) asGcOrRawPointee(ref immutable LowType a) {
	verify(isPtrGcOrRaw(a));
	return isPtrGc(a) ? a.ptrGc_.pointee : a.ptrRaw_.pointee;
}

immutable(LowType.FunPtr) asFunPtrType(ref immutable LowType a) {
	verify(a.kind_ == LowType.Kind.funPtr);
	return a.funPtr_;
}

immutable(PrimitiveType) asPrimitiveType(ref immutable LowType a) {
	verify(a.kind_ == LowType.Kind.primitive);
	return a.primitive_;
}

immutable(LowType.Record) asRecordType(ref immutable LowType a) {
	verify(a.kind_ == LowType.Kind.record);
	return a.record_;
}

immutable(LowType.Union) asUnionType(ref immutable LowType a) {
	verify(a.kind_ == LowType.Kind.union_);
	return a.union_;
}

@trusted T matchLowType(T)(
	ref immutable LowType a,
	scope T delegate(immutable LowType.ExternPtr) @safe @nogc pure nothrow cbExternPtr,
	scope T delegate(immutable LowType.FunPtr) @safe @nogc pure nothrow cbFunPtr,
	scope T delegate(immutable PrimitiveType) @safe @nogc pure nothrow cbPrimitive,
	scope T delegate(immutable LowType.PtrGc) @safe @nogc pure nothrow cbPtrGc,
	scope T delegate(immutable LowType.PtrRaw) @safe @nogc pure nothrow cbPtrRaw,
	scope T delegate(immutable LowType.Record) @safe @nogc pure nothrow cbRecord,
	scope T delegate(immutable LowType.Union) @safe @nogc pure nothrow cbUnion,
) {
	final switch (a.kind_) {
		case LowType.Kind.externPtr:
			return cbExternPtr(a.externPtr_);
		case LowType.Kind.funPtr:
			return cbFunPtr(a.funPtr_);
		case LowType.Kind.primitive:
			return cbPrimitive(a.primitive_);
		case LowType.Kind.ptrGc:
			return cbPtrGc(a.ptrGc_);
		case LowType.Kind.ptrRaw:
			return cbPtrRaw(a.ptrRaw_);
		case LowType.Kind.record:
			return cbRecord(a.record_);
		case LowType.Kind.union_:
			return cbUnion(a.union_);
	}
}

@trusted T matchLowTypeCombinePtr(T)(
	ref immutable LowType a,
	scope T delegate(immutable LowType.ExternPtr) @safe @nogc pure nothrow cbExternPtr,
	scope T delegate(immutable LowType.FunPtr) @safe @nogc pure nothrow cbFunPtr,
	scope T delegate(immutable PrimitiveType) @safe @nogc pure nothrow cbPrimitive,
	scope T delegate(immutable Ptr!LowType) @safe @nogc pure nothrow cbPtr,
	scope T delegate(immutable LowType.Record) @safe @nogc pure nothrow cbRecord,
	scope T delegate(immutable LowType.Union) @safe @nogc pure nothrow cbUnion,
) {
	return matchLowType!T(
		a,
		cbExternPtr,
		cbFunPtr,
		cbPrimitive,
		(immutable LowType.PtrGc it) => cbPtr(it.pointee),
		(immutable LowType.PtrRaw it) => cbPtr(it.pointee),
		cbRecord,
		cbUnion);
}

struct LowField {
	immutable Ptr!ConcreteField source;
	immutable Nat16 offset;
	immutable LowType type;
}

immutable(Sym) name(ref immutable LowField a) {
	return name(a.source);
}

struct LowParamSource {
	@safe @nogc pure nothrow:

	struct Generated {
		immutable Sym name;
	}

	@trusted immutable this(immutable Ptr!ConcreteParam a) { kind_ = Kind.concreteParam; concreteParam_ = a; }
	immutable this(immutable Generated a) { kind_ = Kind.generated; generated_ = a; }

	private:
	enum Kind {
		concreteParam,
		generated,
	}
	immutable Kind kind_;
	union {
		immutable Ptr!ConcreteParam concreteParam_;
		immutable Generated generated_;
	}
}

@trusted T matchLowParamSource(T)(
	ref immutable LowParamSource a,
	scope T delegate(immutable Ptr!ConcreteParam) @safe @nogc pure nothrow cbConcreteParam,
	scope T delegate(ref immutable LowParamSource.Generated) @safe @nogc pure nothrow cbGenerated,
) {
	final switch (a.kind_) {
		case LowParamSource.Kind.concreteParam:
			return cbConcreteParam(a.concreteParam_);
		case LowParamSource.Kind.generated:
			return cbGenerated(a.generated_);
	}
}

struct LowParam {
	immutable LowParamSource source;
	immutable LowType type;
}

struct LowLocalSource {
	@safe @nogc pure nothrow:

	struct Generated {
		immutable Sym name;
		immutable size_t index; // TODO: Nat8
	}

	@trusted immutable this(immutable Ptr!ConcreteLocal a) { kind_ = Kind.concreteLocal; concreteLocal_ = a; }
	immutable this(immutable Generated a) { kind_ = Kind.generated; generated_ = a; }

	private:
	enum Kind {
		concreteLocal,
		generated,
	}
	immutable Kind kind_;
	union {
		immutable Ptr!ConcreteLocal concreteLocal_;
		immutable Generated generated_;
	}
}

@trusted T matchLowLocalSource(T)(
	ref immutable LowLocalSource a,
	scope T delegate(immutable Ptr!ConcreteLocal) @safe @nogc pure nothrow cbConcreteLocal,
	scope T delegate(ref immutable LowLocalSource.Generated) @safe @nogc pure nothrow cbGenerated,
) {
	final switch (a.kind_) {
		case LowLocalSource.Kind.concreteLocal:
			return cbConcreteLocal(a.concreteLocal_);
		case LowLocalSource.Kind.generated:
			return cbGenerated(a.generated_);
	}
}


struct LowLocal {
	@safe @nogc pure nothrow:
	@disable this(ref const LowLocal);
	immutable this(immutable LowLocalSource s, immutable LowType t) {
		source = s;
		type = t;
	}

	immutable LowLocalSource source;
	immutable LowType type;
}

struct LowFunExprBody {
	immutable bool hasTailRecur;
	immutable Ptr!LowExpr expr;
}

// Unlike ConcreteFunBody, this is always an expr or extern.
struct LowFunBody {
	@safe @nogc pure nothrow:

	struct Extern {
		immutable bool isGlobal;
	}

	enum Kind {
		extern_,
		expr,
	}
	immutable Kind kind;
	union {
		immutable Ptr!Extern extern_;
		immutable LowFunExprBody expr_;
	}

	public:
	@trusted immutable this(immutable Ptr!Extern a) { kind = Kind.extern_; extern_ = a; }
	@trusted immutable this(immutable LowFunExprBody a) { kind = Kind.expr; expr_ = a; }
}
static assert(LowFunBody.sizeof <= 24);

immutable(bool) isExtern(ref immutable LowFunBody a) {
	return a.kind == LowFunBody.Kind.extern_;
}

@trusted immutable(bool) isGlobal(ref immutable LowFunBody a) {
	return isExtern(a) && a.extern_.isGlobal;
}

@trusted T matchLowFunBody(T)(
	ref immutable LowFunBody a,
	scope T delegate(ref immutable LowFunBody.Extern) @safe @nogc pure nothrow cbExtern,
	scope T delegate(ref immutable LowFunExprBody) @safe @nogc pure nothrow cbExpr,
) {
	final switch (a.kind) {
		case LowFunBody.Kind.extern_:
			return cbExtern(a.extern_);
		case LowFunBody.Kind.expr:
			return cbExpr(a.expr_);
	}
}

struct LowFunSource {
	@safe @nogc pure nothrow:

	struct Generated {
		immutable Sym name;
		immutable LowType[] typeArgs;
	}

	@trusted immutable this(immutable Ptr!ConcreteFun a) { kind_ = Kind.concreteFun; concreteFun_ = a; }
	@trusted immutable this(immutable Ptr!Generated a) { kind_ = Kind.generated; generated_ = a; }

	private:
	enum Kind {
		concreteFun,
		generated,
	}
	immutable Kind kind_;
	union {
		immutable Ptr!ConcreteFun concreteFun_;
		immutable Ptr!Generated generated_;
	}
}
static assert(LowFunSource.sizeof <= 16);

@trusted T matchLowFunSource(T)(
	ref immutable LowFunSource a,
	scope T delegate(immutable Ptr!ConcreteFun) @safe @nogc pure nothrow cbConcreteFun,
	scope T delegate(ref immutable LowFunSource.Generated) @safe @nogc pure nothrow cbGenerated,
) {
	final switch (a.kind_) {
		case LowFunSource.Kind.concreteFun:
			return cbConcreteFun(a.concreteFun_);
		case LowFunSource.Kind.generated:
			return cbGenerated(a.generated_);
	}
}

struct LowFunParamsKind {
	immutable bool hasCtx;
	immutable bool hasClosure;
}

struct LowFun {
	@safe @nogc pure nothrow:

	@disable this(ref const LowFun);
	immutable this(
		immutable LowFunSource src,
		immutable Ptr!LowFunSig sg,
		immutable LowFunBody b,
	) {
		source = src;
		sig = sg;
		body_ = b;
	}

	immutable LowFunSource source;
	immutable Ptr!LowFunSig sig;
	immutable LowFunBody body_;

	//TODO:NOT INSTANCE
	ref immutable(LowType) returnType() return scope immutable {
		return sig.returnType;
	}
	ref immutable(LowFunParamsKind) paramsKind() return scope immutable {
		return sig.paramsKind;
	}
	ref immutable(LowParam[]) params() return scope immutable {
		return sig.params;
	}
}
static assert(LowFun.sizeof <= 48);

immutable(Opt!Sym) name(ref immutable LowFun a) {
	return matchLowFunSource!(immutable Opt!Sym)(
		a.source,
		(immutable Ptr!ConcreteFun it) => name(it),
		(ref immutable LowFunSource.Generated) => none!Sym);
}

struct LowFunSig {
	immutable LowType returnType;
	immutable LowFunParamsKind paramsKind;
	// Includes ctx and closure params
	immutable LowParam[] params;
}

immutable(size_t) firstRegularParamIndex(ref immutable LowFun a) {
	return (a.paramsKind.hasCtx ? 1 : 0) + (a.paramsKind.hasClosure ? 1 : 0);
}

immutable(LowParam[]) regularParams(ref immutable LowFun a) {
	return a.params[firstRegularParamIndex(a) .. $];
}

immutable(FileAndRange) lowFunRange(ref immutable LowFun a) {
	return matchLowFunSource!(immutable FileAndRange)(
		a.source,
		(immutable Ptr!ConcreteFun cf) =>
			concreteFunRange(cf),
		(ref immutable LowFunSource.Generated) =>
			FileAndRange.empty);
}

// TODO: use Ptr!ConcreteExpr
private alias LowExprSource = FileAndRange;

struct LowExpr {
	immutable LowType type;
	immutable LowExprSource source;
	immutable LowExprKind kind;
}

struct LowFunIndex {
	immutable size_t index;
}

struct LowParamIndex {
	immutable size_t index;
}

struct LowExprKind {
	@safe @nogc pure nothrow:

	struct Call {
		immutable LowFunIndex called;
		immutable LowExpr[] args; // Includes implicit ctx arg if needed
	}

	struct CreateRecord {
		immutable LowExpr[] args;
	}

	struct ConvertToUnion {
		immutable ubyte memberIndex;
		immutable Ptr!LowExpr arg;
	}

	struct FunPtr {
		immutable LowFunIndex fun;
	}

	struct Let {
		immutable Ptr!LowLocal local;
		immutable Ptr!LowExpr value;
		immutable Ptr!LowExpr then;
	}

	struct LocalRef {
		immutable Ptr!LowLocal local;
	}

	// TODO: compile down to a Switch?
	struct MatchUnion {
		struct Case {
			immutable Opt!(Ptr!LowLocal) local;
			immutable LowExpr then;
		}

		immutable Ptr!LowExpr matchedValue;
		immutable Case[] cases;
	}

	struct ParamRef {
		immutable LowParamIndex index;
	}

	struct PtrCast {
		immutable Ptr!LowExpr target;
	}

	struct RecordFieldGet {
		@safe @nogc pure nothrow:

		immutable Ptr!LowExpr target;
		immutable ubyte fieldIndex;

		//TODO:NOT INSTANCE
		immutable(bool) targetIsPointer() immutable {
			return isPtrGcOrRaw(target.type);
		}

		//TODO:NOT INSTANCE
		immutable(LowType.Record) record() immutable {
			return asRecordType(isPtrGcOrRaw(target.type)
				? asGcOrRawPointee(target.type)
				: target.type);
		}
	}

	struct RecordFieldSet {
		@safe @nogc pure nothrow:

		immutable Ptr!LowExpr target;
		immutable ubyte fieldIndex;
		immutable Ptr!LowExpr value;

		//TODO:NOT INSTANCE
		immutable(bool) targetIsPointer() immutable {
			return isPtrGcOrRaw(target.type);
		}

		//TODO:NOT INSTANCE
		immutable(LowType.Record) record() immutable {
			return asRecordType(asGcOrRawPointee(target.type).deref());
		}
	}

	struct Seq {
		immutable Ptr!LowExpr first;
		immutable Ptr!LowExpr then;
	}

	struct SizeOf {
		immutable LowType type;
	}

	struct SpecialUnary {
		enum Kind {
			asAnyPtr,
			asRef,
			bitwiseNotNat8,
			bitwiseNotNat16,
			bitwiseNotNat32,
			bitwiseNotNat64,
			countOnesNat64,
			deref,
			enumToIntegral,
			isNanFloat32,
			isNanFloat64,
			ptrTo,
			refOfVal,
			toCharFromNat8,
			toFloat64FromFloat32,
			toFloat64FromInt64,
			toFloat64FromNat64,
			toInt64FromInt16,
			toInt64FromInt32,
			toNat8FromChar,
			toNat64FromNat8,
			toNat64FromNat16,
			toNat64FromNat32,
			toNat64FromPtr,
			toPtrFromNat64,
			truncateToInt64FromFloat64,
			unsafeInt64ToInt8,
			unsafeInt64ToInt16,
			unsafeInt64ToInt32,
			unsafeInt64ToNat64,
			unsafeNat64ToInt64,
			unsafeNat64ToNat8,
			unsafeNat64ToNat16,
			unsafeNat64ToNat32,
		}
		immutable Kind kind;
		immutable Ptr!LowExpr arg;
	}

	struct SpecialBinary {
		enum Kind {
			addFloat32,
			addFloat64,
			addPtr, // RHS is multiplied by size of pointee first
			and,
			bitwiseAndInt8,
			bitwiseAndInt16,
			bitwiseAndInt32,
			bitwiseAndInt64,
			bitwiseAndNat8,
			bitwiseAndNat16,
			bitwiseAndNat32,
			bitwiseAndNat64,
			bitwiseOrInt8,
			bitwiseOrInt16,
			bitwiseOrInt32,
			bitwiseOrInt64,
			bitwiseOrNat8,
			bitwiseOrNat16,
			bitwiseOrNat32,
			bitwiseOrNat64,
			bitwiseXorInt8,
			bitwiseXorInt16,
			bitwiseXorInt32,
			bitwiseXorInt64,
			bitwiseXorNat8,
			bitwiseXorNat16,
			bitwiseXorNat32,
			bitwiseXorNat64,
			eqFloat64,
			eqInt8,
			eqInt16,
			eqInt32,
			eqInt64,
			eqNat8,
			eqNat16,
			eqNat32,
			eqNat64,
			eqPtr,
			lessBool,
			lessChar,
			lessFloat32,
			lessFloat64,
			lessInt8,
			lessInt16,
			lessInt32,
			lessInt64,
			lessNat8,
			lessNat16,
			lessNat32,
			lessNat64,
			lessPtr,
			mulFloat64,
			or,
			subFloat64,
			subPtrNat, // RHS is multiplied by size of pointee first
			unsafeBitShiftLeftNat64,
			unsafeBitShiftRightNat64,
			unsafeDivFloat32,
			unsafeDivFloat64,
			unsafeDivInt64,
			unsafeDivNat64,
			unsafeModNat64,
			wrapAddInt16,
			wrapAddInt32,
			wrapAddInt64,
			wrapAddNat8,
			wrapAddNat16,
			wrapAddNat32,
			wrapAddNat64,
			wrapMulInt16,
			wrapMulInt32,
			wrapMulInt64,
			wrapMulNat16,
			wrapMulNat32,
			wrapMulNat64,
			wrapSubInt16,
			wrapSubInt32,
			wrapSubInt64,
			wrapSubNat8,
			wrapSubNat16,
			wrapSubNat32,
			wrapSubNat64,
			writeToPtr,
		}
		immutable Kind kind;
		immutable Ptr!LowExpr left;
		immutable Ptr!LowExpr right;
	}

	struct SpecialTrinary {
		enum Kind {
			if_,
			compareExchangeStrongBool,
		}
		immutable Kind kind;
		immutable Ptr!LowExpr p0;
		immutable Ptr!LowExpr p1;
		immutable Ptr!LowExpr p2;
	}

	struct SpecialNAry {
		enum Kind {
			callFunPtr,
		}
		immutable Kind kind;
		immutable LowExpr[] args;
	}

	struct Switch0ToN {
		immutable Ptr!LowExpr value;
		immutable LowExpr[] cases;
	}

	struct SwitchWithValues {
		immutable LowExpr value;
		immutable EnumValue[] values;
		immutable LowExpr[] cases;
	}

	struct TailRecur {
		// Note: This omits the ctx param since it doesn't change.
		immutable LowExpr[] args;
	}

	struct Zeroed {}

	private:
	enum Kind {
		call,
		createRecord,
		convertToUnion,
		funPtr,
		let,
		localRef,
		matchUnion,
		paramRef,
		ptrCast,
		recordFieldGet,
		recordFieldSet,
		seq,
		sizeOf,
		constant,
		specialUnary,
		specialBinary,
		specialTrinary,
		specialNAry,
		switchWithValues,
		switch0ToN,
		tailRecur,
		zeroed,
	}
	public immutable Kind kind; //TODO:PRIVATE
	union {
		immutable Call call;
		immutable CreateRecord createRecord;
		immutable FunPtr funPtr;
		immutable ConvertToUnion convertToUnion;
		immutable Let let;
		immutable LocalRef localRef;
		immutable Ptr!MatchUnion matchUnion;
		immutable ParamRef paramRef;
		immutable PtrCast ptrCast;
		immutable RecordFieldGet recordFieldGet;
		immutable RecordFieldSet recordFieldSet;
		immutable Seq seq;
		immutable SizeOf sizeOf;
		immutable Constant constant;
		immutable SpecialUnary specialUnary;
		immutable SpecialBinary specialBinary;
		immutable Ptr!SpecialTrinary specialTrinary;
		immutable SpecialNAry specialNAry;
		immutable Switch0ToN switch0ToN;
		immutable Ptr!SwitchWithValues switchWithValues;
		immutable TailRecur tailRecur;
		immutable Zeroed zeroed;
	}

	public:
	@trusted immutable this(immutable Call a) { kind = Kind.call; call = a; }
	@trusted immutable this(immutable CreateRecord a) { kind = Kind.createRecord; createRecord = a; }
	immutable this(immutable FunPtr a) { kind = Kind.funPtr; funPtr = a; }
	@trusted immutable this(immutable ConvertToUnion a) { kind = Kind.convertToUnion; convertToUnion = a; }
	@trusted immutable this(immutable Let a) { kind = Kind.let; let = a; }
	@trusted immutable this(immutable LocalRef a) { kind = Kind.localRef; localRef = a; }
	@trusted immutable this(immutable Ptr!MatchUnion a) { kind = Kind.matchUnion; matchUnion = a; }
	@trusted immutable this(immutable ParamRef a) { kind = Kind.paramRef; paramRef = a; }
	@trusted immutable this(immutable PtrCast a) { kind = Kind.ptrCast; ptrCast = a; }
	@trusted immutable this(immutable RecordFieldGet a) { kind = Kind.recordFieldGet; recordFieldGet = a; }
	@trusted immutable this(immutable RecordFieldSet a) { kind = Kind.recordFieldSet; recordFieldSet = a; }
	@trusted immutable this(immutable Seq a) { kind = Kind.seq; seq = a; }
	@trusted immutable this(immutable SizeOf a) { kind = Kind.sizeOf; sizeOf = a; }
	@trusted immutable this(immutable Constant a) { kind = Kind.constant; constant = a; }
	@trusted immutable this(immutable SpecialUnary a) { kind = Kind.specialUnary; specialUnary = a; }
	@trusted immutable this(immutable SpecialBinary a) { kind = Kind.specialBinary; specialBinary = a; }
	@trusted immutable this(immutable Ptr!SpecialTrinary a) { kind = Kind.specialTrinary; specialTrinary = a; }
	@trusted immutable this(immutable SpecialNAry a) { kind = Kind.specialNAry; specialNAry = a; }
	@trusted immutable this(immutable Switch0ToN a) { kind = Kind.switch0ToN; switch0ToN = a; }
	@trusted immutable this(immutable Ptr!SwitchWithValues a) { kind = Kind.switchWithValues; switchWithValues = a; }
	@trusted immutable this(immutable TailRecur a) { kind = Kind.tailRecur; tailRecur = a; }
	@trusted immutable this(immutable Zeroed a) { kind = Kind.zeroed; zeroed = a; }
}
static assert(LowExprKind.sizeof <= 32);

@trusted T matchLowExprKind(T)(
	ref immutable LowExprKind a,
	scope T delegate(ref immutable LowExprKind.Call) @safe @nogc pure nothrow cbCall,
	scope T delegate(ref immutable LowExprKind.CreateRecord) @safe @nogc pure nothrow cbCreateRecord,
	scope T delegate(ref immutable LowExprKind.ConvertToUnion) @safe @nogc pure nothrow cbConvertToUnion,
	scope T delegate(ref immutable LowExprKind.FunPtr) @safe @nogc pure nothrow cbFunPtr,
	scope T delegate(ref immutable LowExprKind.Let) @safe @nogc pure nothrow cbLet,
	scope T delegate(ref immutable LowExprKind.LocalRef) @safe @nogc pure nothrow cbLocalRef,
	scope T delegate(ref immutable LowExprKind.MatchUnion) @safe @nogc pure nothrow cbMatchUnion,
	scope T delegate(ref immutable LowExprKind.ParamRef) @safe @nogc pure nothrow cbParamRef,
	scope T delegate(ref immutable LowExprKind.PtrCast) @safe @nogc pure nothrow cbPtrCast,
	scope T delegate(ref immutable LowExprKind.RecordFieldGet) @safe @nogc pure nothrow cbRecordFieldGet,
	scope T delegate(ref immutable LowExprKind.RecordFieldSet) @safe @nogc pure nothrow cbRecordFieldSet,
	scope T delegate(ref immutable LowExprKind.Seq) @safe @nogc pure nothrow cbSeq,
	scope T delegate(ref immutable LowExprKind.SizeOf) @safe @nogc pure nothrow cbSizeOf,
	scope T delegate(ref immutable Constant) @safe @nogc pure nothrow cbConstant,
	scope T delegate(ref immutable LowExprKind.SpecialUnary) @safe @nogc pure nothrow cbSpecialUnary,
	scope T delegate(ref immutable LowExprKind.SpecialBinary) @safe @nogc pure nothrow cbSpecialBinary,
	scope T delegate(ref immutable LowExprKind.SpecialTrinary) @safe @nogc pure nothrow cbSpecialTrinary,
	scope T delegate(ref immutable LowExprKind.SpecialNAry) @safe @nogc pure nothrow cbSpecialNAry,
	scope T delegate(ref immutable LowExprKind.Switch0ToN) @safe @nogc pure nothrow cbSwitch0ToN,
	scope T delegate(ref immutable LowExprKind.SwitchWithValues) @safe @nogc pure nothrow cbSwitchWithValues,
	scope T delegate(ref immutable LowExprKind.TailRecur) @safe @nogc pure nothrow cbTailRecur,
	scope T delegate(ref immutable LowExprKind.Zeroed) @safe @nogc pure nothrow cbZeroed,
) {
	final switch (a.kind) {
		case LowExprKind.Kind.call:
			return cbCall(a.call);
		case LowExprKind.Kind.createRecord:
			return cbCreateRecord(a.createRecord);
		case LowExprKind.Kind.convertToUnion:
			return cbConvertToUnion(a.convertToUnion);
		case LowExprKind.Kind.funPtr:
			return cbFunPtr(a.funPtr);
		case LowExprKind.Kind.let:
			return cbLet(a.let);
		case LowExprKind.Kind.localRef:
			return cbLocalRef(a.localRef);
		case LowExprKind.Kind.matchUnion:
			return cbMatchUnion(a.matchUnion);
		case LowExprKind.Kind.paramRef:
			return cbParamRef(a.paramRef);
		case LowExprKind.Kind.ptrCast:
			return cbPtrCast(a.ptrCast);
		case LowExprKind.Kind.recordFieldGet:
			return cbRecordFieldGet(a.recordFieldGet);
		case LowExprKind.Kind.recordFieldSet:
			return cbRecordFieldSet(a.recordFieldSet);
		case LowExprKind.Kind.seq:
			return cbSeq(a.seq);
		case LowExprKind.Kind.sizeOf:
			return cbSizeOf(a.sizeOf);
		case LowExprKind.Kind.constant:
			return cbConstant(a.constant);
		case LowExprKind.Kind.specialUnary:
			return cbSpecialUnary(a.specialUnary);
		case LowExprKind.Kind.specialBinary:
			return cbSpecialBinary(a.specialBinary);
		case LowExprKind.Kind.specialTrinary:
			return cbSpecialTrinary(a.specialTrinary);
		case LowExprKind.Kind.specialNAry:
			return cbSpecialNAry(a.specialNAry);
		case LowExprKind.Kind.switch0ToN:
			return cbSwitch0ToN(a.switch0ToN);
		case LowExprKind.Kind.switchWithValues:
			return cbSwitchWithValues(a.switchWithValues);
		case LowExprKind.Kind.tailRecur:
			return cbTailRecur(a.tailRecur);
		case LowExprKind.Kind.zeroed:
			return cbZeroed(a.zeroed);
	}
}

immutable(bool) isLocalRef(ref immutable LowExprKind a) {
	return a.kind == LowExprKind.Kind.localRef;
}

@trusted ref immutable(LowExprKind.LocalRef) asLocalRef(return scope ref immutable LowExprKind a) {
	verify(isLocalRef(a));
	return a.localRef;
}

immutable(bool) isParamRef(ref immutable LowExprKind a) {
	return a.kind == LowExprKind.Kind.paramRef;
}

ref immutable(LowExprKind.ParamRef) asParamRef(return scope ref immutable LowExprKind a) {
	verify(isParamRef(a));
	return a.paramRef;
}

immutable(bool) isRecordFieldGet(ref immutable LowExprKind a) {
	return a.kind == LowExprKind.Kind.recordFieldGet;
}

@trusted ref immutable(LowExprKind.RecordFieldGet) asRecordFieldGet(return scope ref immutable LowExprKind a) {
	verify(isRecordFieldGet(a));
	return a.recordFieldGet;
}

immutable(bool) isSpecialUnary(ref immutable LowExprKind a) {
	return a.kind == LowExprKind.Kind.specialUnary;
}

@trusted ref immutable(LowExprKind.SpecialUnary) asSpecialUnary(return scope ref immutable LowExprKind a) {
	verify(isSpecialUnary(a));
	return a.specialUnary;
}

struct ArrTypeAndConstantsLow {
	@safe @nogc pure nothrow:

	@disable this(ref const ArrTypeAndConstantsLow);
	immutable this(immutable LowType.Record a, immutable LowType e, immutable Constant[][] c) {
		arrType = a; elementType = e; constants = c;
	}

	immutable LowType.Record arrType;
	immutable LowType elementType;
	immutable Constant[][] constants;
}

struct PointerTypeAndConstantsLow {
	@safe @nogc pure nothrow:

	@disable this(ref const PointerTypeAndConstantsLow);
	immutable this(immutable LowType p, immutable Ptr!Constant[] c) {
		pointeeType = p; constants = c;
	}

	immutable LowType pointeeType;
	immutable Ptr!Constant[] constants;
}

// TODO: rename -- this is not all constants, just the ones by-ref
struct AllConstantsLow {
	immutable string[] cStrings;
	immutable ArrTypeAndConstantsLow[] arrs;
	// These are just the by-ref records
	immutable PointerTypeAndConstantsLow[] pointers;
}

alias ConcreteFunToLowFunIndex = immutable Dict!(Ptr!ConcreteFun, LowFunIndex, comparePtr!ConcreteFun);

struct LowProgram {
	@safe @nogc pure nothrow:

	@disable this(ref const LowProgram);
	immutable this(
		immutable ConcreteFunToLowFunIndex cflf,
		immutable AllConstantsLow ac,
		immutable Ptr!AllLowTypes at,
		immutable FullIndexDict!(LowFunIndex, LowFun) af,
		immutable LowFunIndex m,
	) {
		concreteFunToLowFunIndex = cflf;
		allConstants = ac;
		allTypes = at;
		allFuns = af;
		main = m;
	}

	immutable ConcreteFunToLowFunIndex concreteFunToLowFunIndex;
	immutable AllConstantsLow allConstants;
	immutable Ptr!AllLowTypes allTypes;
	immutable FullIndexDict!(LowFunIndex, LowFun) allFuns;
	immutable LowFunIndex main;

	//TODO: NOT INSTANCE
	ref immutable(FullIndexDict!(LowType.ExternPtr, LowExternPtrType)) allExternPtrTypes() return scope immutable {
		return allTypes.allExternPtrTypes;
	}

	ref immutable(FullIndexDict!(LowType.FunPtr, LowFunPtrType)) allFunPtrTypes() return scope immutable {
		return allTypes.allFunPtrTypes;
	}

	ref immutable(FullIndexDict!(LowType.Record, LowRecord)) allRecords() return scope immutable {
		return allTypes.allRecords;
	}

	ref immutable(FullIndexDict!(LowType.Union, LowUnion)) allUnions() return scope immutable {
		return allTypes.allUnions;
	}
}

struct AllLowTypes {
	immutable FullIndexDict!(LowType.ExternPtr, LowExternPtrType) allExternPtrTypes;
	immutable FullIndexDict!(LowType.FunPtr, LowFunPtrType) allFunPtrTypes;
	immutable FullIndexDict!(LowType.Record, LowRecord) allRecords;
	immutable FullIndexDict!(LowType.Union, LowUnion) allUnions;
}
