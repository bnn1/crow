module lowModel;

@safe @nogc pure nothrow:

import util.bools : Bool;
import util.collection.arr : Arr;
import util.collection.str : Str;
import util.opt : Opt;
import util.ptr : Ptr;
import util.sourceRange : SourceRange;
import util.sym : shortSymAlphaLiteral, Sym;

struct LowRecord {
	immutable Str mangledName;
	immutable Arr!LowField fields;
}

struct LowUnion {
	immutable Str mangledName;
	immutable Arr!LowType members;
}

struct LowFunPtrType {
	immutable LowType returnType;
	immutable Arr!LowType paramTypes;
}

struct LowPtrType {
	immutable Ptr!LowType pointee;
}

enum PrimitiveType {
	bool_,
	byte_,
	char_,
	float64,
	int16,
	int32,
	int64,
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
			case PrimitiveType.byte_:
				return "byte";
			case PrimitiveType.char_:
				return "char";
			case PrimitiveType.float64:
				return "float-64";
			case PrimitiveType.int16:
				return "int-16";
			case PrimitiveType.int32:
				return "int-32";
			case PrimitiveType.int64:
				return "int-64";
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

	struct FunPtr {
		immutable size_t index;
	}
	struct NonFunPtr {
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
		funPtr,
		nonFunPtr,
		primitive,
		record,
		union_,
	}
	immutable Kind kind_;
	union {
		immutable FunPtr funPtr_;
		immutable NonFunPtr nonFunPtr_;
		immutable PrimitiveType primitive_;
		immutable Record record_;
		immutable Union union_;
	}

	public:
	immutable this(immutable FunPtr a) { kind_ = Kind.funPtr; funPtr_ = a; }
	@trusted immutable this(immutable NonFunPtr a) { kind_ = Kind.nonFunPtr; nonFunPtr_ = a; }
	immutable this(immutable PrimitiveType a) { kind_ = Kind.primitive; primitive_ = a; }
	immutable this(immutable Record a) { kind_ = Kind.record; record_ = a; }
	immutable this(immutable Union a) { kind_ = Kind.union_; union_ = a; }
}

immutable(Bool) isPrimitive(ref immutable LowType a) {
	return immutable Bool(a.kind_ == LowType.Kind.primitive);
}

immutable(PrimitiveType) asPrimitive(ref immutable LowType a) {
	assert(isPrimitive(a));
	return a.primitive_;
}

immutable(Bool) isVoid(ref immutable LowType a) {
	return immutable Bool(isPrimitive(a) && asPrimitive(a) == PrimitiveType.void_);
}

immutable(Bool) isNonFunPtrType(ref immutable LowType a) {
	return Bool(a.kind_ == LowType.Kind.nonFunPtr);
}

@trusted immutable(LowType.NonFunPtr) asNonFunPtrType(ref immutable LowType a) {
	assert(isNonFunPtrType(a));
	return a.nonFunPtr_;
}

immutable(LowType.FunPtr) asFunPtrType(ref immutable LowType a) {
	assert(a.kind_ == LowType.Kind.funPtr);
	return a.funPtr_;
}

immutable(LowType.Record) asRecordType(ref immutable LowType a) {
	assert(a.kind_ == LowType.Kind.record);
	return a.record_;
}

@trusted T matchLowType(T)(
	ref immutable LowType a,
	scope T delegate(immutable LowType.FunPtr) @safe @nogc pure nothrow cbFunPtr,
	scope T delegate(immutable LowType.NonFunPtr) @safe @nogc pure nothrow cbNonFunPtr,
	scope T delegate(immutable PrimitiveType) @safe @nogc pure nothrow cbPtr,
	scope T delegate(immutable LowType.Record) @safe @nogc pure nothrow cbRecord,
	scope T delegate(immutable LowType.Union) @safe @nogc pure nothrow cbUnion,
) {
	final switch (a.kind_) {
		case LowType.Kind.funPtr:
			return cbFunPtr(a.funPtr_);
		case LowType.Kind.nonFunPtr:
			return cbNonFunPtr(a.nonFunPtr_);
		case LowType.Kind.primitive:
			return cbPtr(a.primitive_);
		case LowType.Kind.record:
			return cbRecord(a.record_);
		case LowType.Kind.union_:
			return cbUnion(a.union_);
	}
}

struct LowField {
	immutable Str mangledName;
	immutable LowType type;
}

struct LowParam {
	immutable Str mangledName;
	immutable LowType type;
}

struct LowLocal {
	immutable Str mangledName;
	immutable LowType type;
}

struct LowFunExprBody {
	immutable Arr!(Ptr!LowLocal) allLocals;
	immutable LowExpr expr;
}

// Unlike ConcreteFunBody, this is always an expr or extern.
struct LowFunBody {
	@safe @nogc pure nothrow:

	struct Extern {
		immutable Bool isGlobal_;
	}

	enum Kind {
		extern_,
		expr,
	}
	immutable Kind kind;
	union {
		immutable Extern extern_;
		immutable LowFunExprBody expr_;
	}

	public:
	immutable this(immutable Extern a) { kind = Kind.extern_; extern_ = a; }
	@trusted immutable this(immutable LowFunExprBody a) { kind = Kind.expr; expr_ = a; }
}

immutable(Bool) isExtern(ref immutable LowFunBody a) {
	return immutable Bool(a.kind == LowFunBody.Kind.extern_);
}

immutable(Bool) isGlobal(ref immutable LowFunBody a) {
	return immutable Bool(isExtern(a) && a.extern_.isGlobal_);
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

struct LowFun {
	immutable(Str) mangledName;
	immutable(LowType) returnType;
	immutable Arr!LowParam params;
	immutable LowFunBody body_;
}

struct LowExpr {
	immutable LowType type;
	immutable SourceRange range;
	immutable LowExprKind kind;
}

struct LowFunIndex {
	immutable size_t index;
}

struct LowExprKind {
	@safe @nogc pure nothrow:

	struct Call {
		immutable LowFunIndex called;
		immutable Arr!LowExpr args;
	}

	struct CreateRecord {
		immutable Arr!LowExpr args;
	}

	struct ConvertToUnion {
		immutable size_t memberIndex;
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

	//TODO: make this disappear into Cond on getting the union idx?
	struct Match {
		struct Case {
			immutable Opt!(Ptr!LowLocal) local;
			immutable LowExpr then;
		}

		immutable Ptr!LowLocal matchedLocal;
		immutable Ptr!LowExpr matchedValue;
		immutable Arr!Case cases;
	}

	struct ParamRef {
		immutable Ptr!LowParam param;
	}

	struct PtrCast {
		immutable Ptr!LowExpr target;
	}

	struct RecordFieldAccess {
		immutable Ptr!LowExpr target;
		immutable Bool targetIsPointer; // TODO: is this redundant?
		immutable Ptr!LowField field;
	}

	struct RecordFieldSet {
		immutable Ptr!LowExpr target;
		immutable Bool targetIsPointer;
		immutable Ptr!LowField field;
		immutable Ptr!LowExpr value;
	}

	struct Seq {
		immutable Ptr!LowExpr first;
		immutable Ptr!LowExpr then;
	}

	struct SizeOf {
		immutable LowType type;
	}

	struct SpecialConstant {
		@safe @nogc pure nothrow:

		struct BoolConstant {
			immutable Bool value;
		}
		// For int and nat types
		struct Integral {
			immutable size_t value;
		}
		struct Null {}
		struct Void {}

		private:
		enum Kind {
			bool_,
			integral,
			null_,
			void_,
		}
		immutable Kind kind;
		union {
			immutable BoolConstant bool_;
			immutable Integral integral_;
			immutable Null null_;
			immutable Void void_;
		}
		public:
		immutable this(immutable BoolConstant a) { kind = Kind.bool_; bool_ = a; }
		immutable this(immutable Integral a) { kind = Kind.integral; integral_ = a; }
		immutable this(immutable Null a) { kind = Kind.null_; null_ = a; }
		immutable this(immutable Void a) { kind = Kind.void_; void_ = a; }
	}

	struct Special0Ary {
		enum Kind {
			getErrno,
		}
		immutable Kind kind;
	}

	struct SpecialUnary {
		enum Kind {
			asAnyPtr,
			asRef,
			deref,
			hardFail,
			not,
			ptrTo,
			refOfVal,
			toIntFromInt16,
			toIntFromInt32,
			toNatFromNat16,
			toNatFromNat32,
			toNatFromPtr,
			unsafeInt64ToInt16,
			unsafeInt64ToInt32,
			unsafeInt64ToNat64,
			unsafeNat64ToInt64,
			unsafeNat64ToNat16,
			unsafeNat64ToNat32,
		}
		immutable Kind kind;
		immutable Ptr!LowExpr arg;
	}

	struct SpecialBinary {
		enum Kind {
			add, //TODO:KILL, use typed versions
			addFloat64,
			addPtr,
			and,
			bitShiftLeftInt32,
			bitShiftRightInt32,
			bitwiseAndInt16,
			bitwiseAndInt32,
			bitwiseAndInt64,
			bitwiseAndNat16,
			bitwiseAndNat32,
			bitwiseAndNat64,
			bitwiseOrInt16,
			bitwiseOrInt32,
			bitwiseOrInt64,
			bitwiseOrNat16,
			bitwiseOrNat32,
			bitwiseOrNat64,
			eq, // TODO:KILL, use typed versions
			less, // TODO:KILL, use typed versions
			mulFloat64,
			mulNat64,
			or,
			sub, // TODO:KILL, use typed versions
			subFloat64,
			subPtrNat,
			unsafeDivFloat64,
			unsafeDivInt64,
			unsafeDivNat64,
			unsafeModNat64,
			wrapAddInt16,
			wrapAddInt32,
			wrapAddInt64,
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
			//TODO: why is this special?
			compareExchangeStrong,
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
		immutable Arr!LowExpr args;
	}

	struct StringLiteral {
		immutable Str literal;
	}

	private:
	enum Kind {
		call,
		createRecord,
		convertToUnion,
		funPtr,
		let,
		localRef,
		match,
		paramRef,
		ptrCast,
		recordFieldAccess,
		recordFieldSet,
		seq,
		sizeOf,
		specialConstant,
		special0Ary,
		specialUnary,
		specialBinary,
		specialTrinary,
		specialNAry,
		stringLiteral,
	}
	immutable Kind kind;
	union {
		immutable Call call;
		immutable CreateRecord createRecord;
		immutable FunPtr funPtr;
		immutable ConvertToUnion convertToUnion;
		immutable Let let;
		immutable LocalRef localRef;
		immutable Match match;
		immutable ParamRef paramRef;
		immutable PtrCast ptrCast;
		immutable RecordFieldAccess recordFieldAccess;
		immutable RecordFieldSet recordFieldSet;
		immutable Seq seq;
		immutable SizeOf sizeOf;
		immutable SpecialConstant specialConstant;
		immutable Special0Ary special0Ary;
		immutable SpecialUnary specialUnary;
		immutable SpecialBinary specialBinary;
		immutable SpecialTrinary specialTrinary;
		immutable SpecialNAry specialNAry;
		immutable StringLiteral stringLiteral;
	}

	public:
	@trusted immutable this(immutable Call a) { kind = Kind.call; call = a; }
	@trusted immutable this(immutable CreateRecord a) { kind = Kind.createRecord; createRecord = a; }
	immutable this(immutable FunPtr a) { kind = Kind.funPtr; funPtr = a; }
	@trusted immutable this(immutable ConvertToUnion a) { kind = Kind.convertToUnion; convertToUnion = a; }
	@trusted immutable this(immutable Let a) { kind = Kind.let; let = a; }
	@trusted immutable this(immutable LocalRef a) { kind = Kind.localRef; localRef = a; }
	@trusted immutable this(immutable Match a) { kind = Kind.match; match = a; }
	@trusted immutable this(immutable ParamRef a) { kind = Kind.paramRef; paramRef = a; }
	@trusted immutable this(immutable PtrCast a) { kind = Kind.ptrCast; ptrCast = a; }
	@trusted immutable this(immutable RecordFieldAccess a) { kind = Kind.recordFieldAccess; recordFieldAccess = a; }
	@trusted immutable this(immutable RecordFieldSet a) { kind = Kind.recordFieldSet; recordFieldSet = a; }
	@trusted immutable this(immutable Seq a) { kind = Kind.seq; seq = a; }
	@trusted immutable this(immutable SizeOf a) { kind = Kind.sizeOf; sizeOf = a; }
	@trusted immutable this(immutable SpecialConstant a) { kind = Kind.specialConstant; specialConstant = a; }
	@trusted immutable this(immutable Special0Ary a) { kind = Kind.special0Ary; special0Ary = a; }
	@trusted immutable this(immutable SpecialUnary a) { kind = Kind.specialUnary; specialUnary = a; }
	@trusted immutable this(immutable SpecialBinary a) { kind = Kind.specialBinary; specialBinary = a; }
	@trusted immutable this(immutable SpecialTrinary a) { kind = Kind.specialTrinary; specialTrinary = a; }
	@trusted immutable this(immutable SpecialNAry a) { kind = Kind.specialNAry; specialNAry = a; }
	@trusted immutable this(immutable StringLiteral a) { kind = Kind.stringLiteral; stringLiteral = a; }
}

T matchSpecialConstant(T)(
	ref immutable LowExprKind.SpecialConstant a,
	scope T delegate(immutable LowExprKind.SpecialConstant.BoolConstant) @safe @nogc pure nothrow cbBool,
	scope T delegate(immutable LowExprKind.SpecialConstant.Integral) @safe @nogc pure nothrow cbIntegral,
	scope T delegate(immutable LowExprKind.SpecialConstant.Null) @safe @nogc pure nothrow cbNull,
	scope T delegate(immutable LowExprKind.SpecialConstant.Void) @safe @nogc pure nothrow cbVoid,
) {
	final switch (a.kind) {
		case LowExprKind.SpecialConstant.Kind.bool_:
			return cbBool(a.bool_);
		case LowExprKind.SpecialConstant.Kind.integral:
			return cbIntegral(a.integral_);
		case LowExprKind.SpecialConstant.Kind.null_:
			return cbNull(a.null_);
		case LowExprKind.SpecialConstant.Kind.void_:
			return cbVoid(a.void_);
	}
}

@trusted T matchLowExprKind(T)(
	ref immutable LowExprKind a,
	scope T delegate(ref immutable LowExprKind.Call) @safe @nogc pure nothrow cbCall,
	scope T delegate(ref immutable LowExprKind.CreateRecord) @safe @nogc pure nothrow cbCreateRecord,
	scope T delegate(ref immutable LowExprKind.ConvertToUnion) @safe @nogc pure nothrow cbConvertToUnion,
	scope T delegate(ref immutable LowExprKind.FunPtr) @safe @nogc pure nothrow cbFunPtr,
	scope T delegate(ref immutable LowExprKind.Let) @safe @nogc pure nothrow cbLet,
	scope T delegate(ref immutable LowExprKind.LocalRef) @safe @nogc pure nothrow cbLocalRef,
	scope T delegate(ref immutable LowExprKind.Match) @safe @nogc pure nothrow cbMatch,
	scope T delegate(ref immutable LowExprKind.ParamRef) @safe @nogc pure nothrow cbParamRef,
	scope T delegate(ref immutable LowExprKind.PtrCast) @safe @nogc pure nothrow cbPtrCast,
	scope T delegate(ref immutable LowExprKind.RecordFieldAccess) @safe @nogc pure nothrow cbRecordFieldAccess,
	scope T delegate(ref immutable LowExprKind.RecordFieldSet) @safe @nogc pure nothrow cbRecordFieldSet,
	scope T delegate(ref immutable LowExprKind.Seq) @safe @nogc pure nothrow cbSeq,
	scope T delegate(ref immutable LowExprKind.SizeOf) @safe @nogc pure nothrow cbSizeOf,
	scope T delegate(ref immutable LowExprKind.SpecialConstant) @safe @nogc pure nothrow cbSpecialConstant,
	scope T delegate(ref immutable LowExprKind.Special0Ary) @safe @nogc pure nothrow cbSpecial0Ary,
	scope T delegate(ref immutable LowExprKind.SpecialUnary) @safe @nogc pure nothrow cbSpecialUnary,
	scope T delegate(ref immutable LowExprKind.SpecialBinary) @safe @nogc pure nothrow cbSpecialBinary,
	scope T delegate(ref immutable LowExprKind.SpecialTrinary) @safe @nogc pure nothrow cbSpecialTrinary,
	scope T delegate(ref immutable LowExprKind.SpecialNAry) @safe @nogc pure nothrow cbSpecialNAry,
	scope T delegate(ref immutable LowExprKind.StringLiteral) @safe @nogc pure nothrow cbStringLiteral,
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
		case LowExprKind.Kind.match:
			return cbMatch(a.match);
		case LowExprKind.Kind.paramRef:
			return cbParamRef(a.paramRef);
		case LowExprKind.Kind.ptrCast:
			return cbPtrCast(a.ptrCast);
		case LowExprKind.Kind.recordFieldAccess:
			return cbRecordFieldAccess(a.recordFieldAccess);
		case LowExprKind.Kind.recordFieldSet:
			return cbRecordFieldSet(a.recordFieldSet);
		case LowExprKind.Kind.seq:
			return cbSeq(a.seq);
		case LowExprKind.Kind.sizeOf:
			return cbSizeOf(a.sizeOf);
		case LowExprKind.Kind.specialConstant:
			return cbSpecialConstant(a.specialConstant);
		case LowExprKind.Kind.special0Ary:
			return cbSpecial0Ary(a.special0Ary);
		case LowExprKind.Kind.specialUnary:
			return cbSpecialUnary(a.specialUnary);
		case LowExprKind.Kind.specialBinary:
			return cbSpecialBinary(a.specialBinary);
		case LowExprKind.Kind.specialTrinary:
			return cbSpecialTrinary(a.specialTrinary);
		case LowExprKind.Kind.specialNAry:
			return cbSpecialNAry(a.specialNAry);
		case LowExprKind.Kind.stringLiteral:
			return cbStringLiteral(a.stringLiteral);
	}
}

struct LowProgram {
	immutable Arr!LowFunPtrType allFunPtrTypes;
	immutable Arr!LowRecord allRecords;
	immutable Arr!LowUnion allUnions;
	immutable Arr!LowFun allFuns;
	//TODO: just have a generated 'main' fun instead of separate rtMain and userMain
	immutable LowFunIndex rtMain;
	immutable LowFunIndex userMain;
}