module model.concreteModel;

@safe @nogc pure nothrow:

import model.constant : Constant;
import model.model :
	ClosureField,
	decl,
	EnumBackingType,
	EnumFunction,
	EnumValue,
	FlagsFunction,
	FunInst,
	isArr,
	isCallWithCtxFun,
	isCompareFun,
	isMarkVisitFun,
	Local,
	matchParams,
	name,
	Param,
	Params,
	params,
	Purity,
	range,
	RecordField,
	StructInst,
	summon;
import util.col.arr : only;
import util.col.dict : PtrDict;
import util.col.str : SafeCStr;
import util.hash : hashBool, Hasher;
import util.late : Late, lateGet, lateIsSet, lateSet;
import util.opt : none, Opt, some;
import util.ptr : hashPtr, ptrEquals, Ptr;
import util.sourceRange : FileAndRange;
import util.sym : AllSymbols, shortSym, Sym;
import util.util : unreachable, verify;

enum BuiltinStructKind {
	bool_,
	char8,
	float32,
	float64,
	fun, // 'fun' or 'act'
	funPtrN, // fun-ptr0, fun-ptr1, etc...
	int8,
	int16,
	int32,
	int64,
	nat8,
	nat16,
	nat32,
	nat64,
	ptrConst,
	ptrMut,
	void_,
}

immutable(Sym) symOfBuiltinStructKind(immutable BuiltinStructKind a) {
	final switch (a) {
		case BuiltinStructKind.bool_:
			return shortSym("bool");
		case BuiltinStructKind.char8:
			return shortSym("char8");
		case BuiltinStructKind.float32:
			return shortSym("float-32");
		case BuiltinStructKind.float64:
			return shortSym("float-64");
		case BuiltinStructKind.fun:
			return shortSym("fun");
		case BuiltinStructKind.funPtrN:
			return shortSym("fun-ptr");
		case BuiltinStructKind.int8:
			return shortSym("int-8");
		case BuiltinStructKind.int16:
			return shortSym("int-16");
		case BuiltinStructKind.int32:
			return shortSym("int-32");
		case BuiltinStructKind.int64:
			return shortSym("int-64");
		case BuiltinStructKind.nat8:
			return shortSym("nat-8");
		case BuiltinStructKind.nat16:
			return shortSym("nat-16");
		case BuiltinStructKind.nat32:
			return shortSym("nat-32");
		case BuiltinStructKind.nat64:
			return shortSym("nat-64");
		case BuiltinStructKind.ptrConst:
			return shortSym("ptr-const");
		case BuiltinStructKind.ptrMut:
			return shortSym("ptr-mut");
		case BuiltinStructKind.void_:
			return shortSym("void");
	}
}

struct ConcreteStructBody {
	@safe @nogc pure nothrow:

	struct Builtin {
		immutable BuiltinStructKind kind;
		immutable ConcreteType[] typeArgs;
	}
	struct Enum {
		@safe @nogc pure nothrow:

		@disable this();
		immutable this(immutable EnumBackingType b, immutable size_t a) {
			backingType = b; kind = Kind.size; size = a;
		}
		@trusted immutable this(immutable EnumBackingType b, immutable EnumValue[] a) {
			backingType = b; kind = Kind.values; values = a;
		}

		immutable EnumBackingType backingType;
		private:
		enum Kind {
			size, // for 0 to N
			values,
		}
		immutable Kind kind;
		union {
			immutable size_t size;
			immutable EnumValue[] values;
		}
	}
	struct Flags {
		immutable EnumBackingType backingType;
		immutable ulong[] values;
	}
	struct ExternPtr {}
	struct Record {
		immutable ConcreteField[] fields;
	}
	struct Union {
		// In the concrete model we identify members by index, so don't care about their names
		immutable Opt!ConcreteType[] members;
	}

	private:
	enum Kind {
		builtin,
		externPtr,
		record,
		enum_,
		flags,
		union_,
	}
	immutable Kind kind;
	union {
		immutable Builtin builtin;
		immutable Enum enum_;
		immutable Flags flags;
		immutable ExternPtr externPtr;
		immutable Record record;
		immutable Union union_;
	}

	public:
	@trusted immutable this(immutable Builtin a) { kind = Kind.builtin; builtin = a; }
	@trusted immutable this(immutable Enum a) { kind = Kind.enum_; enum_ = a; }
	@trusted immutable this(immutable Flags a) { kind = Kind.flags; flags = a; }
	immutable this(immutable ExternPtr a) { kind = Kind.externPtr; externPtr = a; }
	@trusted immutable this(immutable Record a) { kind = Kind.record; record = a; }
	@trusted immutable this(immutable Union a) { kind = Kind.union_; union_ = a; }
}

@trusted immutable(T) matchEnum(T)(
	ref immutable ConcreteStructBody.Enum a,
	scope immutable(T) delegate(immutable size_t) @safe @nogc pure nothrow cbSize,
	scope immutable(T) delegate(immutable EnumValue[]) @safe @nogc pure nothrow cbValues,
) {
	final switch (a.kind) {
		case ConcreteStructBody.Enum.Kind.size:
			return cbSize(a.size);
		case ConcreteStructBody.Enum.Kind.values:
			return cbValues(a.values);
	}
}

@trusted ref immutable(ConcreteStructBody.Builtin) asBuiltin(return scope ref immutable ConcreteStructBody a) {
	verify(a.kind == ConcreteStructBody.Kind.builtin);
	return a.builtin;
}

@trusted ref immutable(ConcreteStructBody.Enum) asEnum(return scope ref immutable ConcreteStructBody a) {
	verify(a.kind == ConcreteStructBody.Kind.enum_);
	return a.enum_;
}

@trusted ref immutable(ConcreteStructBody.Flags) asFlags(return scope ref immutable ConcreteStructBody a) {
	verify(a.kind == ConcreteStructBody.Kind.flags);
	return a.flags;
}

@trusted ref immutable(ConcreteStructBody.Record) asRecord(return scope ref immutable ConcreteStructBody a) {
	verify(a.kind == ConcreteStructBody.Kind.record);
	return a.record;
}

@trusted ref immutable(ConcreteStructBody.Union) asUnion(return scope ref immutable ConcreteStructBody a) {
	verify(a.kind == ConcreteStructBody.Kind.union_);
	return a.union_;
}

@trusted immutable(T) matchConcreteStructBody(T)(
	ref immutable ConcreteStructBody a,
	scope immutable(T) delegate(ref immutable ConcreteStructBody.Builtin) @safe @nogc pure nothrow cbBuiltin,
	scope immutable(T) delegate(ref immutable ConcreteStructBody.Enum) @safe @nogc pure nothrow cbEnum,
	scope immutable(T) delegate(ref immutable ConcreteStructBody.Flags) @safe @nogc pure nothrow cbFlags,
	scope immutable(T) delegate(ref immutable ConcreteStructBody.ExternPtr) @safe @nogc pure nothrow cbExternPtr,
	scope immutable(T) delegate(ref immutable ConcreteStructBody.Record) @safe @nogc pure nothrow cbRecord,
	scope immutable(T) delegate(ref immutable ConcreteStructBody.Union) @safe @nogc pure nothrow cbUnion,
) {
	final switch (a.kind) {
		case ConcreteStructBody.Kind.builtin:
			return cbBuiltin(a.builtin);
		case ConcreteStructBody.Kind.enum_:
			return cbEnum(a.enum_);
		case ConcreteStructBody.Kind.flags:
			return cbFlags(a.flags);
		case ConcreteStructBody.Kind.externPtr:
			return cbExternPtr(a.externPtr);
		case ConcreteStructBody.Kind.record:
			return cbRecord(a.record);
		case ConcreteStructBody.Kind.union_:
			return cbUnion(a.union_);
	}
}

struct ConcreteType {
	// NOTE: ConcreteType for 'ptr' (e.g. 'ptr byte') will *not* have isPointer set -- since it's not a ptr*
	immutable bool isPointer;
	immutable Ptr!ConcreteStruct struct_;
}

struct TypeSize {
	immutable size_t size;
	immutable size_t alignment;
}

immutable(Purity) purity(immutable ConcreteType a) {
	return a.struct_.deref().purity;
}

immutable(Ptr!ConcreteStruct) mustBeNonPointer(immutable ConcreteType a) {
	verify(!a.isPointer);
	return a.struct_;
}

struct ConcreteStructInfo {
	immutable ConcreteStructBody body_;
	immutable bool isSelfMutable; //TODO: never used? (may need for GC though)
}

struct ConcreteStructSource {
	@safe @nogc pure nothrow:

	struct Inst {
		immutable Ptr!StructInst inst;
		immutable ConcreteType[] typeArgs;
	}

	struct Lambda {
		immutable Ptr!ConcreteFun containingFun;
		immutable size_t index;
	}

	@trusted immutable this(immutable Lambda a) { kind_ = Kind.lambda; lambda_ = a; }
	@trusted immutable this(immutable Inst a) { kind_ = Kind.inst; inst_ = a; }

	private:
	enum Kind {
		inst,
		lambda,
	}
	immutable Kind kind_;
	union {
		immutable Inst inst_;
		immutable Lambda lambda_;
	}
}

@trusted ref immutable(ConcreteStructSource.Inst) asInst(return scope ref immutable ConcreteStructSource a) {
	verify(a.kind_ == ConcreteStructSource.Kind.inst);
	return a.inst_;
}

@trusted immutable(T) matchConcreteStructSource(T, alias cbInst, alias cbLambda)(ref immutable ConcreteStructSource a) {
	final switch (a.kind_) {
		case ConcreteStructSource.Kind.inst:
			return cbInst(a.inst_);
		case ConcreteStructSource.Kind.lambda:
			return cbLambda(a.lambda_);
	}
}

struct ConcreteStruct {
	@safe @nogc pure nothrow:

	immutable Purity purity;
	immutable ConcreteStructSource source;
	Late!(immutable ConcreteStructInfo) info_;
	//TODO: this isn't needed outside of concretizeCtx.d
	Late!(immutable bool) defaultIsPointer_;
	Late!(immutable TypeSize) typeSize_;
	// Only set for records
	Late!(immutable size_t[]) fieldOffsets_;
}

immutable(bool) isArr(ref immutable ConcreteStruct a) {
	return matchConcreteStructSource!(
		immutable bool,
		(ref immutable ConcreteStructSource.Inst it) =>
			isArr(it.inst.deref()),
		(ref immutable ConcreteStructSource.Lambda it) =>
			false,
	)(a.source);
}

private ref immutable(ConcreteStructInfo) info(return scope ref const ConcreteStruct a) {
	return lateGet(a.info_);
}

ref immutable(ConcreteStructBody) body_(return scope ref immutable ConcreteStruct a) {
	return info(a).body_;
}

immutable(TypeSize) typeSize(ref immutable ConcreteStruct a) {
	return lateGet(a.typeSize_);
}

ref immutable(size_t[]) fieldOffsets(return scope ref immutable ConcreteStruct a) {
	return lateGet(a.fieldOffsets_);
}

immutable(bool) isSelfMutable(ref immutable ConcreteStruct a) {
	return info(a).isSelfMutable;
}

immutable(bool) defaultIsPointer(ref immutable ConcreteStruct a) {
	return lateGet(a.defaultIsPointer_);
}

//TODO: this is only useful during concretize, move
immutable(bool) hasSizeOrPointerSizeBytes(ref immutable ConcreteType a) {
	return a.isPointer || lateIsSet(a.struct_.deref().typeSize_);
}

immutable(TypeSize) sizeOrPointerSizeBytes(ref immutable ConcreteType a) {
	return a.isPointer
		? immutable TypeSize(8, 8)
		: typeSize(a.struct_.deref());
}

immutable(ConcreteType) byRef(immutable ConcreteType t) {
	return immutable ConcreteType(true, t.struct_);
}

immutable(ConcreteType) byVal(ref immutable ConcreteType t) {
	return immutable ConcreteType(false, t.struct_);
}

immutable(bool) concreteTypeEqual(ref immutable ConcreteType a, ref immutable ConcreteType b) {
	return ptrEquals(a.struct_, b.struct_) && a.isPointer == b.isPointer;
}

void hashConcreteType(ref Hasher hasher, ref immutable ConcreteType a) {
	hashPtr(hasher, a.struct_);
	hashBool(hasher, a.isPointer);
}

struct ConcreteFieldSource {
	@safe @nogc pure nothrow:

	@trusted immutable this(immutable Ptr!ClosureField a) { kind_ = Kind.closureField; closureField_ = a; }
	@trusted immutable this(immutable Ptr!RecordField a) { kind_ = Kind.recordField; recordField_ = a; }

	private:
	enum Kind {
		closureField,
		recordField,
	}
	immutable Kind kind_;
	union {
		immutable Ptr!ClosureField closureField_;
		immutable Ptr!RecordField recordField_;
	}
}

@trusted immutable(T) matchConcreteFieldSource(T, alias cbClosureField, alias cbRecordField)(
	ref immutable ConcreteFieldSource a,
) {
	final switch (a.kind_) {
		case ConcreteFieldSource.Kind.closureField:
			return cbClosureField(a.closureField_);
		case ConcreteFieldSource.Kind.recordField:
			return cbRecordField(a.recordField_);
	}
}

enum ConcreteMutability {
	const_,
	mutable,
}

immutable(Sym) symOfConcreteMutability(immutable ConcreteMutability a) {
	final switch (a) {
		case ConcreteMutability.const_:
			return shortSym("const");
		case ConcreteMutability.mutable:
			return shortSym("mutable");
	}
}

struct ConcreteField {
	immutable ConcreteFieldSource source;
	immutable size_t index;
	immutable ConcreteMutability mutability;
	immutable ConcreteType type;
}

immutable(Sym) name(ref immutable ConcreteField a) {
	return matchConcreteFieldSource!(
		immutable Sym,
		(immutable Ptr!ClosureField it) =>
			it.deref().name,
		(immutable Ptr!RecordField it) =>
			it.deref().name,
	)(a.source);
}

struct ConcreteParamSource {
	@safe @nogc pure nothrow:

	struct Closure {}
	struct Synthetic {}

	immutable this(immutable Closure a) { kind_ = Kind.closure; closure_ = a; }
	@trusted immutable this(immutable Ptr!Param a) { kind_ = Kind.param; param_ = a; }
	immutable this(immutable Synthetic a) { kind_ = Kind.synthetic; synthetic_ = a; }

	private:
	enum Kind {
		closure,
		param,
		synthetic,
	}
	immutable Kind kind_;
	union {
		immutable Closure closure_;
		immutable Ptr!Param param_;
		immutable Synthetic synthetic_;
	}
}

immutable(bool) isClosure(ref immutable ConcreteParamSource a) {
	return a.kind_ == ConcreteParamSource.Kind.closure;
}

@trusted immutable(T) matchConcreteParamSource(T)(
	ref immutable ConcreteParamSource a,
	scope immutable(T) delegate(ref immutable ConcreteParamSource.Closure) @safe @nogc pure nothrow cbClosure,
	scope immutable(T) delegate(ref immutable Param) @safe @nogc pure nothrow cbParam,
	scope immutable(T) delegate(ref immutable ConcreteParamSource.Synthetic) @safe @nogc pure nothrow cbSynthetic,
) {
	final switch (a.kind_) {
		case ConcreteParamSource.Kind.closure:
			return cbClosure(a.closure_);
		case ConcreteParamSource.Kind.param:
			return cbParam(a.param_.deref());
		case ConcreteParamSource.Kind.synthetic:
			return cbSynthetic(a.synthetic_);
	}
}

struct ConcreteParam {
	immutable ConcreteParamSource source;
	immutable Opt!size_t index; // not present for ctx/ closure param
	immutable ConcreteType type;
}

struct ConcreteLocal {
	immutable Ptr!Local source;
	// Needed to distinguish two locals with the same name when compiling to C
	immutable size_t index;
	immutable ConcreteType type;
}

struct ConcreteFunBody {
	@safe @nogc pure nothrow:

	struct Builtin {
		immutable ConcreteType[] typeArgs;
	}
	struct CreateEnum {
		immutable EnumValue value;
	}
	struct CreateRecord {}
	struct CreateUnion {
		immutable size_t memberIndex;
	}
	struct Extern {
		immutable bool isGlobal;
	}
	struct FlagsFn {
		immutable ulong allValue;
		immutable FlagsFunction fn;
	}
	struct RecordFieldGet {
		immutable size_t fieldIndex;
	}
	struct RecordFieldSet {
		immutable size_t fieldIndex;
	}

	private:
	enum Kind {
		builtin,
		createEnum,
		createRecord,
		createUnion,
		enumFunction,
		extern_,
		flagsFn,
		concreteExpr,
		recordFieldGet,
		recordFieldSet,
	}
	immutable Kind kind;
	union {
		immutable Builtin builtin;
		immutable CreateEnum createEnum;
		immutable CreateRecord createRecord;
		immutable CreateUnion createUnion;
		immutable EnumFunction enumFunction;
		immutable Extern extern_;
		immutable FlagsFn flagsFn;
		immutable ConcreteExpr concreteExpr;
		immutable RecordFieldGet recordFieldGet;
		immutable RecordFieldSet recordFieldSet;
	}

	public:
	@trusted immutable this(immutable Builtin a) { kind = Kind.builtin; builtin = a; }
	immutable this(immutable CreateEnum a) { kind = Kind.createEnum; createEnum = a; }
	@trusted immutable this(immutable CreateRecord a) { kind = Kind.createRecord; createRecord = a; }
	immutable this(immutable CreateUnion a) { kind = Kind.createUnion; createUnion = a; }
	immutable this(immutable EnumFunction a) { kind = Kind.enumFunction; enumFunction = a; }
	@trusted immutable this(immutable Extern a) { kind = Kind.extern_; extern_ = a; }
	@trusted immutable this(immutable ConcreteExpr a) {
		kind = Kind.concreteExpr; concreteExpr = a;
	}
	immutable this(immutable FlagsFn a) { kind = Kind.flagsFn; flagsFn = a; }
	immutable this(immutable RecordFieldGet a) { kind = Kind.recordFieldGet; recordFieldGet = a; }
	immutable this(immutable RecordFieldSet a) { kind = Kind.recordFieldSet; recordFieldSet = a; }
}

immutable(bool) isExtern(ref immutable ConcreteFunBody a) {
	return a.kind == ConcreteFunBody.Kind.extern_;
}

@trusted ref immutable(ConcreteFunBody.Builtin) asBuiltin(return scope ref immutable ConcreteFunBody a) {
	verify(a.kind == ConcreteFunBody.Kind.builtin);
	return a.builtin;
}

private @trusted ref immutable(ConcreteFunBody.Extern) asExtern(return scope ref immutable ConcreteFunBody a) {
	verify(isExtern(a));
	return a.extern_;
}

@trusted immutable(T) matchConcreteFunBody(T)(
	ref immutable ConcreteFunBody a,
	scope immutable(T) delegate(ref immutable ConcreteFunBody.Builtin) @safe @nogc pure nothrow cbBuiltin,
	scope immutable(T) delegate(ref immutable ConcreteFunBody.CreateEnum) @safe @nogc pure nothrow cbCreateEnum,
	scope immutable(T) delegate(ref immutable ConcreteFunBody.CreateRecord) @safe @nogc pure nothrow cbCreateRecord,
	scope immutable(T) delegate(ref immutable ConcreteFunBody.CreateUnion) @safe @nogc pure nothrow cbCreateUnion,
	scope immutable(T) delegate(immutable EnumFunction) @safe @nogc pure nothrow cbEnumFunction,
	scope immutable(T) delegate(ref immutable ConcreteFunBody.Extern) @safe @nogc pure nothrow cbExtern,
	scope immutable(T) delegate(ref immutable ConcreteExpr) @safe @nogc pure nothrow cbConcreteExpr,
	scope immutable(T) delegate(ref immutable ConcreteFunBody.FlagsFn) @safe @nogc pure nothrow cbFlagsFn,
	scope immutable(T) delegate(ref immutable ConcreteFunBody.RecordFieldGet) @safe @nogc pure nothrow cbRecordFieldGet,
	scope immutable(T) delegate(ref immutable ConcreteFunBody.RecordFieldSet) @safe @nogc pure nothrow cbRecordFieldSet,
) {
	final switch (a.kind) {
		case ConcreteFunBody.Kind.builtin:
			return cbBuiltin(a.builtin);
		case ConcreteFunBody.Kind.createEnum:
			return cbCreateEnum(a.createEnum);
		case ConcreteFunBody.Kind.createRecord:
			return cbCreateRecord(a.createRecord);
		case ConcreteFunBody.Kind.createUnion:
			return cbCreateUnion(a.createUnion);
		case ConcreteFunBody.Kind.enumFunction:
			return cbEnumFunction(a.enumFunction);
		case ConcreteFunBody.Kind.extern_:
			return cbExtern(a.extern_);
		case ConcreteFunBody.Kind.flagsFn:
			return cbFlagsFn(a.flagsFn);
		case ConcreteFunBody.Kind.concreteExpr:
			return cbConcreteExpr(a.concreteExpr);
		case ConcreteFunBody.Kind.recordFieldGet:
			return cbRecordFieldGet(a.recordFieldGet);
		case ConcreteFunBody.Kind.recordFieldSet:
			return cbRecordFieldSet(a.recordFieldSet);
	}
}

immutable(bool) isGlobal(ref immutable ConcreteFunBody a) {
	return isExtern(a) && asExtern(a).isGlobal;
}

struct ConcreteFunSource {
	@safe @nogc pure nothrow:

	struct Lambda {
		immutable FileAndRange range;
		immutable Ptr!ConcreteFun containingFun;
		immutable size_t index; // nth lambda in the containing function
	}

	struct Test {
		immutable FileAndRange range;
		immutable size_t testIndex;
	}

	@trusted immutable this(immutable Ptr!FunInst a) { kind_ = Kind.funInst; funInst_ = a; }
	@trusted immutable this(immutable Ptr!Lambda a) { kind_ = Kind.lambda; lambda_ = a; }
	@trusted immutable this(immutable Ptr!Test a) { kind_ = Kind.test; test_ = a; }

	private:
	enum Kind {
		funInst,
		lambda,
		test,
	}
	immutable Kind kind_;
	union {
		immutable Ptr!FunInst funInst_;
		immutable Ptr!Lambda lambda_;
		immutable Ptr!Test test_;
	}
}
static assert(ConcreteFunSource.sizeof <= 16);

@trusted immutable(Ptr!FunInst) asFunInst(ref immutable ConcreteFunSource a) {
	verify(a.kind_ == ConcreteFunSource.Kind.funInst);
	return a.funInst_;
}

@trusted immutable(T) matchConcreteFunSource(T, alias cbFunInst, alias cbLambda, alias cbTest)(
	ref immutable ConcreteFunSource a,
) {
	final switch (a.kind_) {
		case ConcreteFunSource.Kind.funInst:
			return cbFunInst(a.funInst_.deref());
		case ConcreteFunSource.Kind.lambda:
			return cbLambda(a.lambda_.deref());
		case ConcreteFunSource.Kind.test:
			return cbTest(a.test_.deref());
	}
}

enum NeedsCtx { yes, no }

// We generate a ConcreteFun for:
// Each instantiation of a FunDecl
// Each lambda inside an instantiation of a FunDecl
struct ConcreteFun {
	immutable ConcreteFunSource source;
	immutable ConcreteType returnType;
	immutable NeedsCtx needsCtx;
	immutable Opt!(Ptr!ConcreteParam) closureParam;
	immutable ConcreteParam[] paramsExcludingCtxAndClosure;
	Late!(immutable ConcreteFunBody) _body_;
}

immutable(bool) isVariadic(ref immutable ConcreteFun a) {
	return matchConcreteFunSource!(
		immutable bool,
		(ref immutable FunInst i) =>
			matchParams!(
				immutable bool,
				(immutable Param[]) =>
					false,
				(ref immutable Params.Varargs) =>
					true,
			)(params(i)),
		(ref immutable ConcreteFunSource.Lambda) =>
			false,
		(ref immutable ConcreteFunSource.Test) =>
			false,
	)(a.source);
}

immutable(Opt!Sym) name(ref immutable ConcreteFun a) {
	return matchConcreteFunSource!(
		immutable Opt!Sym,
		(ref immutable FunInst it) =>
			some(name(it)),
		(ref immutable ConcreteFunSource.Lambda) =>
			none!Sym,
		(ref immutable ConcreteFunSource.Test) =>
			none!Sym,
	)(a.source);
}

immutable(bool) isSummon(ref immutable ConcreteFun a) {
	return matchConcreteFunSource!(
		immutable bool,
		(ref immutable FunInst it) =>
			summon(decl(it).deref()),
		(ref immutable ConcreteFunSource.Lambda it) =>
			isSummon(it.containingFun.deref()),
		(ref immutable ConcreteFunSource.Test) =>
			// 'isSummon' is called for direct calls, but tests are never called directly
			unreachable!(immutable bool)(),
	)(a.source);
}

immutable(FileAndRange) concreteFunRange(ref immutable ConcreteFun a, ref const AllSymbols allSymbols) {
	return matchConcreteFunSource!(
		immutable FileAndRange,
		(ref immutable FunInst it) =>
			decl(it).deref().range,
		(ref immutable ConcreteFunSource.Lambda it) =>
			it.range,
		(ref immutable ConcreteFunSource.Test it) =>
			it.range,
	)(a.source);
}

immutable(bool) isCallWithCtxFun(ref immutable ConcreteFun a) {
	return matchConcreteFunSource!(
		immutable bool,
		(ref immutable FunInst it) =>
			isCallWithCtxFun(it),
		(ref immutable ConcreteFunSource.Lambda) =>
			false,
		(ref immutable ConcreteFunSource.Test) =>
			false,
	)(a.source);
}

immutable(bool) isCompareFun(ref immutable ConcreteFun a) {
	return matchConcreteFunSource!(
		immutable bool,
		(ref immutable FunInst it) =>
			isCompareFun(it),
		(ref immutable ConcreteFunSource.Lambda) =>
			false,
		(ref immutable ConcreteFunSource.Test) =>
			false,
	)(a.source);
}

immutable(bool) isMarkVisitFun(ref immutable ConcreteFun a) {
	return matchConcreteFunSource!(
		immutable bool,
		(ref immutable FunInst it) =>
			isMarkVisitFun(it),
		(ref immutable ConcreteFunSource.Lambda) =>
			false,
		(ref immutable ConcreteFunSource.Test) =>
			false,
	)(a.source);
}

ref immutable(ConcreteFunBody) body_(return scope ref const ConcreteFun a) {
	return lateGet(a._body_);
}

void setBody(ref ConcreteFun a, immutable ConcreteFunBody value) {
	lateSet(a._body_, value);
}

immutable(bool) isExtern(ref immutable ConcreteFun a) {
	return isExtern(body_(a));
}

immutable(bool) isGlobal(ref immutable ConcreteFun a) {
	return isGlobal(body_(a));
}

struct ConcreteExpr {
	immutable ConcreteType type;
	immutable FileAndRange range;
	immutable ConcreteExprKind kind;
}

struct ConcreteExprKind {
	@safe @nogc pure nothrow:

	struct Alloc {
		immutable ConcreteExpr inner;
	}

	struct Call {
		immutable Ptr!ConcreteFun called;
		immutable ConcreteExpr[] args;
	}

	struct Cond {
		immutable ConcreteExpr cond;
		immutable ConcreteExpr then;
		immutable ConcreteExpr else_;
	}

	struct CreateArr {
		immutable Ptr!ConcreteStruct arrType;
		immutable ConcreteExpr[] args;
	}

	// TODO: this is only used for closures now, since normal record creation always goes through a function.
	struct CreateRecord {
		immutable ConcreteExpr[] args;
	}

	// Only used for 'safe-value', otherwise it goes through a function
	struct CreateUnion {
		immutable size_t memberIndex;
		immutable ConcreteExpr arg;
	}

	struct Let {
		immutable Ptr!ConcreteLocal local;
		immutable ConcreteExpr value; // If a constant, we just use 'then' in place of the Let
		immutable ConcreteExpr then;
	}

	// May be a fun or fun-mut.
	// (A fun-ref is a lambda wrapped in CreateRecord.)
	struct Lambda {
		immutable size_t memberIndex; // Member index of a Union (which hasn't been created yet)
		immutable ConcreteExpr closure;
	}

	struct LocalRef {
		immutable Ptr!ConcreteLocal local;
	}

	struct MatchEnum {
		immutable ConcreteExpr matchedValue;
		immutable ConcreteExpr[] cases;
	}

	struct MatchUnion {
		struct Case {
			immutable Opt!(Ptr!ConcreteLocal) local;
			immutable ConcreteExpr then;
		}

		immutable ConcreteExpr matchedValue;
		immutable Case[] cases;
	}

	struct ParamRef {
		immutable Ptr!ConcreteParam param;
	}

	// TODO: this is only used for closure field accesses now. At least rename.
	struct RecordFieldGet {
		immutable ConcreteExpr target;
		immutable Ptr!ConcreteField field;
	}

	struct Seq {
		immutable ConcreteExpr first;
		immutable ConcreteExpr then;
	}

	private:
	enum Kind {
		alloc,
		call,
		cond,
		constant,
		createArr,
		createRecord,
		createUnion,
		lambda,
		let,
		localRef,
		matchEnum,
		matchUnion,
		paramRef,
		recordFieldGet,
		seq,
	}
	immutable Kind kind;
	union {
		immutable Ptr!Alloc alloc;
		immutable Call call;
		immutable Ptr!Cond cond;
		immutable Ptr!CreateArr createArr;
		immutable Constant constant;
		immutable CreateRecord createRecord;
		immutable Ptr!CreateUnion createUnion;
		immutable Ptr!Lambda lambda;
		immutable Ptr!Let let;
		immutable LocalRef localRef;
		immutable Ptr!MatchEnum matchEnum;
		immutable Ptr!MatchUnion matchUnion;
		immutable ParamRef paramRef;
		immutable Ptr!RecordFieldGet recordFieldGet;
		immutable Ptr!Seq seq;
	}

	public:
	@trusted immutable this(immutable Ptr!Alloc a) { kind = Kind.alloc; alloc = a; }
	@trusted immutable this(immutable Call a) { kind = Kind.call; call = a; }
	@trusted immutable this(immutable Ptr!Cond a) { kind = Kind.cond; cond = a; }
	@trusted immutable this(immutable Ptr!CreateArr a) { kind = Kind.createArr; createArr = a; }
	@trusted immutable this(immutable Constant a) { kind = Kind.constant; constant = a; }
	@trusted immutable this(immutable CreateRecord a) { kind = Kind.createRecord; createRecord = a; }
	immutable this(immutable Ptr!CreateUnion a) { kind = Kind.createUnion; createUnion = a; }
	@trusted immutable this(immutable Ptr!Lambda a) { kind = Kind.lambda; lambda = a; }
	@trusted immutable this(immutable Ptr!Let a) { kind = Kind.let; let = a; }
	@trusted immutable this(immutable LocalRef a) { kind = Kind.localRef; localRef = a; }
	@trusted immutable this(immutable Ptr!MatchEnum a) { kind = Kind.matchEnum; matchEnum = a; }
	@trusted immutable this(immutable Ptr!MatchUnion a) { kind = Kind.matchUnion; matchUnion = a; }
	@trusted immutable this(immutable ParamRef a) { kind = Kind.paramRef; paramRef = a; }
	@trusted immutable this(immutable Ptr!RecordFieldGet a) { kind = Kind.recordFieldGet; recordFieldGet = a; }
	@trusted immutable this(immutable Ptr!Seq a) { kind = Kind.seq; seq = a; }
}

immutable(ConcreteType) elementType(return scope ref immutable ConcreteExprKind.CreateArr a) {
	return only(asInst(a.arrType.deref().source).typeArgs);
}

immutable(ConcreteType) returnType(return scope ref immutable ConcreteExprKind.Call a) {
	return a.called.deref().returnType;
}

immutable(bool) isConstant(ref immutable ConcreteExprKind a) {
	return a.kind == ConcreteExprKind.Kind.constant;
}

@trusted ref immutable(Constant) asConstant(return scope ref immutable ConcreteExprKind a) {
	verify(isConstant(a));
	return a.constant;
}

@trusted immutable(T) matchConcreteExprKind(T)(
	ref immutable ConcreteExprKind a,
	scope immutable(T) delegate(ref immutable ConcreteExprKind.Alloc) @safe @nogc pure nothrow cbAlloc,
	scope immutable(T) delegate(ref immutable ConcreteExprKind.Call) @safe @nogc pure nothrow cbCall,
	scope immutable(T) delegate(ref immutable ConcreteExprKind.Cond) @safe @nogc pure nothrow cbCond,
	scope immutable(T) delegate(immutable Constant) @safe @nogc pure nothrow cbConstant,
	scope immutable(T) delegate(ref immutable ConcreteExprKind.CreateArr) @safe @nogc pure nothrow cbCreateArr,
	scope immutable(T) delegate(ref immutable ConcreteExprKind.CreateRecord) @safe @nogc pure nothrow cbCreateRecord,
	scope immutable(T) delegate(ref immutable ConcreteExprKind.CreateUnion) @safe @nogc pure nothrow cbCreateUnion,
	scope immutable(T) delegate(ref immutable ConcreteExprKind.Lambda) @safe @nogc pure nothrow cbLambda,
	scope immutable(T) delegate(ref immutable ConcreteExprKind.Let) @safe @nogc pure nothrow cbLet,
	scope immutable(T) delegate(ref immutable ConcreteExprKind.LocalRef) @safe @nogc pure nothrow cbLocalRef,
	scope immutable(T) delegate(ref immutable ConcreteExprKind.MatchEnum) @safe @nogc pure nothrow cbMatchEnum,
	scope immutable(T) delegate(ref immutable ConcreteExprKind.MatchUnion) @safe @nogc pure nothrow cbMatchUnion,
	scope immutable(T) delegate(ref immutable ConcreteExprKind.ParamRef) @safe @nogc pure nothrow cbParamRef,
	scope immutable(T) delegate(
		ref immutable ConcreteExprKind.RecordFieldGet,
	) @safe @nogc pure nothrow cbRecordFieldGet,
	scope immutable(T) delegate(ref immutable ConcreteExprKind.Seq) @safe @nogc pure nothrow cbSeq,
) {
	final switch (a.kind) {
		case ConcreteExprKind.Kind.alloc:
			return cbAlloc(a.alloc.deref());
		case ConcreteExprKind.Kind.call:
			return cbCall(a.call);
		case ConcreteExprKind.Kind.cond:
			return cbCond(a.cond.deref());
		case ConcreteExprKind.Kind.constant:
			return cbConstant(a.constant);
		case ConcreteExprKind.Kind.createArr:
			return cbCreateArr(a.createArr.deref());
		case ConcreteExprKind.Kind.createRecord:
			return cbCreateRecord(a.createRecord);
		case ConcreteExprKind.Kind.createUnion:
			return cbCreateUnion(a.createUnion.deref());
		case ConcreteExprKind.Kind.lambda:
			return cbLambda(a.lambda.deref());
		case ConcreteExprKind.Kind.let:
			return cbLet(a.let.deref());
		case ConcreteExprKind.Kind.localRef:
			return cbLocalRef(a.localRef);
		case ConcreteExprKind.Kind.matchEnum:
			return cbMatchEnum(a.matchEnum.deref());
		case ConcreteExprKind.Kind.matchUnion:
			return cbMatchUnion(a.matchUnion.deref());
		case ConcreteExprKind.Kind.paramRef:
			return cbParamRef(a.paramRef);
		case ConcreteExprKind.Kind.recordFieldGet:
			return cbRecordFieldGet(a.recordFieldGet.deref());
		case ConcreteExprKind.Kind.seq:
			return cbSeq(a.seq.deref());
	}
}

struct ArrTypeAndConstantsConcrete {
	immutable Ptr!ConcreteStruct arrType;
	immutable ConcreteType elementType;
	immutable Constant[][] constants;
}

struct PointerTypeAndConstantsConcrete {
	immutable Ptr!ConcreteStruct pointeeType;
	immutable Ptr!Constant[] constants;
}

// TODO: rename -- this is not all constants, just the ones by-ref
struct AllConstantsConcrete {
	immutable SafeCStr[] cStrings;
	immutable Constant allFuns;
	immutable Constant staticSyms;
	immutable ArrTypeAndConstantsConcrete[] arrs;
	// These are just the by-ref records
	immutable PointerTypeAndConstantsConcrete[] pointers;
}

struct ConcreteProgram {
	@safe @nogc pure nothrow:

	immutable AllConstantsConcrete allConstants;
	immutable Ptr!ConcreteStruct[] allStructs;
	immutable Ptr!ConcreteFun[] allFuns;
	immutable PtrDict!(ConcreteStruct, ConcreteLambdaImpl[]) funStructToImpls;
	immutable ConcreteCommonFuns commonFuns;
	immutable Ptr!ConcreteStruct ctxType;
	immutable Sym[] allExternLibraryNames;

	//TODO:NOT INSTANCE
	immutable(Ptr!ConcreteFun) markFun() immutable { return commonFuns.markFun; }
	immutable(Ptr!ConcreteFun) rtMain() immutable { return commonFuns.rtMain; }
	immutable(Ptr!ConcreteFun) userMain() immutable { return commonFuns.userMain; }
	immutable(Ptr!ConcreteFun) allocFun() immutable { return commonFuns.allocFun; }
}

struct ConcreteCommonFuns {
	immutable Ptr!ConcreteFun markFun;
	immutable Ptr!ConcreteFun rtMain;
	immutable Ptr!ConcreteFun userMain;
	immutable Ptr!ConcreteFun allocFun;
}

struct ConcreteLambdaImpl {
	immutable ConcreteType closureType;
	immutable Ptr!ConcreteFun impl;
}
