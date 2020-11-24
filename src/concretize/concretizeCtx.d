module concretize.concretizeCtx;

@safe @nogc pure nothrow:

import concretize.allConstantsBuilder : AllConstantsBuilder;
import concretize.concretizeExpr : concretizeExpr;
import model.concreteModel :
	BuiltinStructKind,
	byVal,
	compareConcreteType,
	ConcreteField,
	ConcreteFieldSource,
	ConcreteFun,
	ConcreteFunBody,
	ConcreteFunSig,
	ConcreteFunSource,
	ConcreteParam,
	ConcreteParamSource,
	ConcreteType,
	concreteType_fromStruct,
	concreteType_pointer,
	ConcreteStruct,
	ConcreteStructBody,
	ConcreteStructInfo,
	ConcreteStructSource,
	purity,
	sizeOrPointerSizeBytes;
import model.model :
	body_,
	CommonTypes,
	decl,
	Expr,
	ForcedByValOrRef,
	FunBody,
	FunDecl,
	FunInst,
	matchFunBody,
	matchStructBody,
	matchType,
	name,
	noCtx,
	Param,
	params,
	Purity,
	range,
	RecordField,
	returnType,
	StructBody,
	StructDecl,
	StructInst,
	Type,
	typeArgs,
	TypeParam,
	typeParams,
	worsePurity;
import util.bools : Bool, False, not, True;
import util.collection.arr : Arr, at, empty, emptyArr, only, ptrAt, range, sizeEq;
import util.collection.arrBuilder : add, ArrBuilder;
import util.collection.arrUtil : arrMax, compareArr, exists, fold, map, mapPtrsWithIndex;
import util.collection.mutArr : MutArr;
import util.collection.mutDict : addToMutDict, getOrAdd, getOrAddAndDidAdd, mustDelete, MutDict, ValueAndDidAdd;
import util.collection.str : strLiteral;
import util.comparison : Comparison;
import util.late : Late, lateIsSet, lateSet, lateSetOverwrite, lazilySet;
import util.memory : nu, nuMut;
import util.opt : force, has, none, Opt, some;
import util.ptr : castImmutable, castMutable, comparePtr, Ptr, ptrEquals;
import util.sym : shortSymAlphaLiteralValue, Sym;
import util.types : safeSizeTToU8;
import util.util : min, max, roundUp, todo, unreachable, verify;

struct TypeArgsScope {
	@safe @nogc pure nothrow:

	/*
	Suppose we have:
	pair<?ts> record
		a ?ts
		b ?ts
	make-pair pair ?tf(value ?tf)
		new value, value

	When we instantiate the struct 'pair' for the return type, and are getting the type for 'a':
	The StructInst* for that will already have an instantiated fieldTypes containing ?tf and not ?ts.
	So the only type params and args we need here come from the concretefun.
	TODO:PERF no need to store typeParams then.
	*/

	immutable Arr!TypeParam typeParams;
	immutable Arr!ConcreteType typeArgs;

	immutable this(immutable Arr!TypeParam tp, immutable Arr!ConcreteType ta) {
		typeParams = tp;
		typeArgs = ta;
		verify(sizeEq(typeParams, typeArgs));
	}

	static immutable(TypeArgsScope) empty() {
		return immutable TypeArgsScope(emptyArr!TypeParam, emptyArr!ConcreteType);
	}
}

private struct ConcreteStructKey {
	immutable Ptr!StructDecl decl;
	immutable Arr!ConcreteType typeArgs;
}

private immutable(Comparison) compareConcreteStructKey(ref const ConcreteStructKey a, ref const ConcreteStructKey b) {
	immutable Comparison res = comparePtr(a.decl, b.decl);
	return res != Comparison.equal ? res : compareConcreteTypeArr(a.typeArgs, b.typeArgs);
}

struct ConcreteFunKey {
	// We only need a FunDecl since we have the typeArgs and specImpls.
	// FunInst is for debug info
	immutable Ptr!FunInst inst;
	immutable Arr!ConcreteType typeArgs;
	immutable Arr!(Ptr!ConcreteFun) specImpls;
}

immutable(TypeArgsScope) typeArgsScope(ref immutable ConcreteFunKey a) {
	return immutable TypeArgsScope(typeParams(a.inst.decl.deref()), a.typeArgs);
}

private immutable(Comparison) compareConcreteFunKey(ref immutable ConcreteFunKey a, ref immutable ConcreteFunKey b) {
	// Compare decls, not insts.
	// Two different FunInsts may concretize to the same thing.
	// (e.g. f<?t> and f<bool> if ?t = bool)
	immutable Comparison cmpDecl = comparePtr(a.inst.decl, b.inst.decl);
	if (cmpDecl != Comparison.equal)
		return cmpDecl;
	else {
		immutable Comparison res = compareConcreteTypeArr(a.typeArgs, b.typeArgs);
		return res != Comparison.equal
			? res
			: compareArr!(Ptr!ConcreteFun)(
				a.specImpls,
				b.specImpls,
				(ref immutable Ptr!ConcreteFun x, ref immutable Ptr!ConcreteFun y) =>
					comparePtr(x, y));
	}
}

struct ConcreteFunBodyInputs {
	immutable Ptr!ConcreteFun concreteFun;
	// NOTE: for a lambda, this is for the *outermost* fun (the one with type args and spec impls).
	// The FunDecl is needed for its TypeParam declataions.
	immutable ConcreteFunKey containingConcreteFunKey;
	// Similarly, body of the current fun, not the outer one.
	// For a lambda this is always an Expr.
	immutable FunBody body_;
}

ref immutable(Arr!ConcreteType) typeArgs(return scope ref immutable ConcreteFunBodyInputs a) {
	return a.containingConcreteFunKey.typeArgs;
}

immutable(TypeArgsScope) typeArgsScope(ref immutable ConcreteFunBodyInputs a) {
	return typeArgsScope(a.containingConcreteFunKey);
}

ref immutable(Arr!(Ptr!ConcreteFun)) specImpls(return scope ref immutable ConcreteFunBodyInputs a) {
	return a.containingConcreteFunKey.specImpls;
}

struct ConcretizeCtx {
	@safe @nogc pure nothrow:

	immutable Ptr!FunInst getVatAndActorFun;
	immutable Arr!(Ptr!FunDecl) ifFuns;
	immutable Arr!(Ptr!FunDecl) callFuns;
	immutable Ptr!StructInst ctxStructInst;
	immutable Ptr!CommonTypes commonTypes;
	AllConstantsBuilder allConstants;
	MutDict!(
		immutable ConcreteStructKey,
		immutable Ptr!ConcreteStruct,
		compareConcreteStructKey,
	) nonLambdaConcreteStructs;
	ArrBuilder!(immutable Ptr!ConcreteStruct) allConcreteStructs;
	MutDict!(immutable ConcreteFunKey, immutable Ptr!ConcreteFun, compareConcreteFunKey) nonLambdaConcreteFuns;
	ArrBuilder!(immutable Ptr!ConcreteFun) allConcreteFuns;

	// Funs we still need to write the bodies for
	MutArr!(Ptr!ConcreteFun) concreteFunsQueue;
	// This will only have an entry while a ConcreteFun hasn't had it's body filled in yet.
	MutDict!(
		immutable Ptr!ConcreteFun,
		immutable ConcreteFunBodyInputs,
		comparePtr!ConcreteFun,
	) concreteFunToBodyInputs;
	// TODO: do these eagerly
	Late!(immutable ConcreteType) _boolType;
	Late!(immutable ConcreteType) _charType;
	Late!(immutable ConcreteType) _voidType;
	Late!(immutable ConcreteType) _anyPtrType;
	Late!(immutable ConcreteType) _ctxType;
}

immutable(ConcreteType) boolType(Alloc)(ref Alloc alloc, ref ConcretizeCtx a) {
	return lazilySet(a._boolType, () =>
		getConcreteType_forStructInst(alloc, a, a.commonTypes.bool_, TypeArgsScope.empty));
}

immutable(ConcreteType) charType(Alloc)(ref Alloc alloc, ref ConcretizeCtx a) {
	return lazilySet(a._charType, () =>
		getConcreteType_forStructInst(alloc, a, a.commonTypes.char_, TypeArgsScope.empty));
}

immutable(ConcreteType) voidType(Alloc)(ref Alloc alloc, ref ConcretizeCtx a) {
	return lazilySet(a._voidType, () =>
		getConcreteType_forStructInst(alloc, a, a.commonTypes.void_, TypeArgsScope.empty));
}

immutable(ConcreteType) anyPtrType(Alloc)(ref Alloc alloc, ref ConcretizeCtx a) {
	return lazilySet(a._anyPtrType, () =>
		getConcreteType_forStructInst(alloc, a, a.commonTypes.anyPtr, TypeArgsScope.empty));
}

immutable(ConcreteType) ctxType(Alloc)(ref Alloc alloc, ref ConcretizeCtx a)
out(it) { verify(it.isPointer); }
body {
	return lazilySet(a._ctxType, () =>
		getConcreteType_forStructInst(alloc, a, a.ctxStructInst, TypeArgsScope.empty));
}

immutable(Ptr!ConcreteFun) getOrAddConcreteFunAndFillBody(Alloc)(
	ref Alloc alloc,
	ref ConcretizeCtx ctx,
	ref immutable ConcreteFunKey key,
) {
	Ptr!ConcreteFun cf = castMutable(getOrAddConcreteFunWithoutFillingBody(alloc, ctx, key));
	fillInConcreteFunBody(alloc, ctx, cf);
	return castImmutable(cf);
}

immutable(Ptr!ConcreteFun) getConcreteFunForLambdaAndFillBody(Alloc)(
	ref Alloc alloc,
	ref ConcretizeCtx ctx,
	immutable Bool needsCtx,
	immutable Ptr!ConcreteFun containingConcreteFun,
	immutable size_t index,
	immutable ConcreteType returnType,
	ref immutable Opt!(Ptr!ConcreteParam) closureParam,
	ref immutable Arr!ConcreteParam params,
	ref immutable ConcreteFunKey containingConcreteFunKey,
	immutable Ptr!Expr body_,
) {
	Ptr!ConcreteFun res =
		nuMut!ConcreteFun(
			alloc,
			immutable ConcreteFunSource(
				nu!(ConcreteFunSource.Lambda)(alloc, body_.range, containingConcreteFun, index)),
			nu!ConcreteFunSig(alloc, returnType, needsCtx, closureParam, params));
	immutable ConcreteFunBodyInputs bodyInputs = immutable ConcreteFunBodyInputs(
		castImmutable(res),
		containingConcreteFunKey,
		immutable FunBody(body_));
	addToMutDict(alloc, ctx.concreteFunToBodyInputs, castImmutable(res), bodyInputs);
	fillInConcreteFunBody(alloc, ctx, res);
	add(alloc, ctx.allConcreteFuns, castImmutable(res));
	return castImmutable(res);
}

immutable(Ptr!ConcreteFun) getOrAddNonTemplateConcreteFunAndFillBody(Alloc)(
	ref Alloc alloc,
	ref ConcretizeCtx ctx,
	immutable Ptr!FunInst decl,
) {
	immutable ConcreteFunKey key = immutable ConcreteFunKey(decl, emptyArr!ConcreteType, emptyArr!(Ptr!ConcreteFun));
	return getOrAddConcreteFunAndFillBody(alloc, ctx, key);
}

immutable(ConcreteType) getConcreteType_forStructInst(Alloc)(
	ref Alloc alloc,
	ref ConcretizeCtx ctx,
	immutable Ptr!StructInst i,
	immutable TypeArgsScope typeArgsScope,
) {
	immutable Arr!ConcreteType typeArgs = typesToConcreteTypes!Alloc(alloc, ctx, typeArgs(i), typeArgsScope);
	if (ptrEquals(i.decl, ctx.commonTypes.byVal))
		return byVal(only(typeArgs));
	else {
		immutable ConcreteStructKey key = ConcreteStructKey(i.decl, typeArgs);
		immutable ValueAndDidAdd!(immutable Ptr!ConcreteStruct) res =
			getOrAddAndDidAdd(alloc, ctx.nonLambdaConcreteStructs, key, () {
				immutable Purity purity = fold(
					i.bestCasePurity,
					typeArgs,
					(ref immutable Purity p, ref immutable ConcreteType ta) =>
						worsePurity(p, purity(ta)));
				immutable Ptr!ConcreteStruct res = nu!ConcreteStruct(
					alloc,
					purity,
					immutable ConcreteStructSource(immutable ConcreteStructSource.Inst(i, key.typeArgs)));
				add(alloc, ctx.allConcreteStructs, res);
				return res;
			});
		if (res.didAdd)
			initializeConcreteStruct!Alloc(alloc, ctx, typeArgs, i, castMutable(res.value).deref, typeArgsScope);
		return concreteType_fromStruct(res.value);
	}
}

immutable(ConcreteType) getConcreteType(Alloc)(
	ref Alloc alloc,
	ref ConcretizeCtx ctx,
	ref immutable Type t,
	ref immutable TypeArgsScope typeArgsScope,
) {
	return matchType!(immutable ConcreteType)(
		t,
		(ref immutable Type.Bogus) =>
			unreachable!(immutable ConcreteType),
		(immutable Ptr!TypeParam p) {
			// Handle calledConcreteFun first
			verify(ptrEquals(p, ptrAt(typeArgsScope.typeParams, p.index)));
			return at(typeArgsScope.typeArgs, p.index);
		},
		(immutable Ptr!StructInst i) =>
			getConcreteType_forStructInst!Alloc(alloc, ctx, i, typeArgsScope));
}

immutable(Arr!ConcreteType) typesToConcreteTypes(Alloc)(
	ref Alloc alloc,
	ref ConcretizeCtx ctx,
	immutable Arr!Type types,
	ref immutable TypeArgsScope typeArgsScope,
) {
	return map!ConcreteType(alloc, types, (ref immutable Type t) =>
		getConcreteType(alloc, ctx, t, typeArgsScope));
}

immutable(ConcreteType) concreteTypeFromFields_alwaysPointer(Alloc)(
	ref Alloc alloc,
	ref ConcretizeCtx ctx,
	ref immutable Arr!ConcreteField fields,
	immutable ConcreteStructSource source,
) {
	verify(!empty(fields));
	immutable Purity purity = fold(Purity.data, fields, (ref immutable Purity p, ref immutable ConcreteField f) {
		verify(!f.isMutable); // TODO: lambda fields are never mutable, use a different type?
		return worsePurity(p, purity(f.type));
	});
	Ptr!ConcreteStruct cs = nuMut!ConcreteStruct(alloc, purity, source);
	lateSet(cs.info_, getConcreteStructInfoForFields(none!ForcedByValOrRef, fields));
	add(alloc, ctx.allConcreteStructs, castImmutable(cs));
	return concreteType_pointer(castImmutable(cs));
}

immutable(Ptr!ConcreteFun) getGetVatAndActorFun(Alloc)(ref Alloc alloc, ref ConcretizeCtx ctx) {
	return getOrAddNonTemplateConcreteFunAndFillBody(alloc, ctx, ctx.getVatAndActorFun);
}

private:

immutable(Ptr!ConcreteFun) getOrAddConcreteFunWithoutFillingBody(Alloc)(
	ref Alloc alloc,
	ref ConcretizeCtx ctx,
	ref immutable ConcreteFunKey key,
) {
	return getOrAdd(alloc, ctx.nonLambdaConcreteFuns, key, () {
		immutable Ptr!ConcreteFun res = getConcreteFunFromKey(alloc, ctx, key);
		add(alloc, ctx.allConcreteFuns, res);
		return res;
	});
}

immutable(Ptr!ConcreteFun) getConcreteFunFromKey(Alloc)(
	ref Alloc alloc,
	ref ConcretizeCtx ctx,
	ref immutable ConcreteFunKey key,
) {
	immutable Ptr!FunDecl decl = key.inst.decl;
	immutable TypeArgsScope typeScope = typeArgsScope(key);
	immutable ConcreteType returnType = getConcreteType(alloc, ctx, returnType(decl), typeScope);
	immutable Arr!ConcreteParam params = concretizeParams(alloc, ctx, params(decl), typeScope);
	Ptr!ConcreteFun res = nuMut!ConcreteFun(
		alloc,
		immutable ConcreteFunSource(key.inst),
		nu!ConcreteFunSig(alloc, returnType, not(noCtx(decl)), none!(Ptr!ConcreteParam), params));
	immutable ConcreteFunBodyInputs bodyInputs = ConcreteFunBodyInputs(
		castImmutable(res),
		key,
		decl.body_);
	addToMutDict(alloc, ctx.concreteFunToBodyInputs, castImmutable(res), bodyInputs);
	return castImmutable(res);
}

immutable(Comparison) compareConcreteTypeArr(ref immutable Arr!ConcreteType a, ref immutable Arr!ConcreteType b) {
	return compareArr!ConcreteType(a, b, (ref immutable ConcreteType x, ref immutable ConcreteType y) =>
		compareConcreteType(x, y));
}

size_t sizeFromConcreteFields(immutable Arr!ConcreteField fields) {
	// TODO: this is definitely not accurate. Luckily I use static asserts in the generated code to check this.
	size_t s = 0;
	size_t maxFieldAlign = 1;
	foreach (ref immutable ConcreteField field; range(fields)) {
		immutable size_t itsSize = sizeOrPointerSizeBytes(field.type);
		//TODO: this is wrong!
		const size_t itsAlign = min(itsSize, 8);
		maxFieldAlign = max(maxFieldAlign, itsAlign);
		while (s % itsAlign != 0)
			s++;
		s += itsSize;
	}
	while (s % maxFieldAlign != 0)
		s++;
	return max(s, 1);
}

immutable(Bool) getDefaultIsPointerForFields(
	immutable Opt!ForcedByValOrRef forcedByValOrRef,
	immutable size_t sizeBytes,
	immutable Bool isSelfMutable,
) {
	if (has(forcedByValOrRef))
		final switch (force(forcedByValOrRef)) {
			case ForcedByValOrRef.byVal:
				verify(!isSelfMutable);
				return False;
			case ForcedByValOrRef.byRef:
				return True;
		}
	else
		return Bool(isSelfMutable || sizeBytes > (void*).sizeof * 2);
}

immutable(ConcreteStructInfo) getConcreteStructInfoForFields(
	immutable Opt!ForcedByValOrRef forcedByValOrRef,
	immutable Arr!ConcreteField fields,
) {
	immutable size_t sizeBytes = sizeFromConcreteFields(fields);
	immutable Bool isSelfMutable = exists(fields, (ref immutable ConcreteField fld) =>
		fld.isMutable);
	return immutable ConcreteStructInfo(
		immutable ConcreteStructBody(ConcreteStructBody.Record(fields)),
		sizeBytes,
		isSelfMutable,
		getDefaultIsPointerForFields(forcedByValOrRef, sizeBytes, isSelfMutable));
}

void initializeConcreteStruct(Alloc)(
	ref Alloc alloc,
	ref ConcretizeCtx ctx,
	ref immutable Arr!ConcreteType typeArgs,
	immutable Ptr!StructInst i,
	ref ConcreteStruct res,
	ref immutable TypeArgsScope typeArgsScope,
) {
	// Initially make this a by-ref type, so we don't recurse infinitely when computing size
	// TODO: is this a bug? We compute the size based on assuming it's a pointer,
	// then make it not be a pointer and that would change the size?
	lateSet(res.info_, immutable ConcreteStructInfo(
		immutable ConcreteStructBody(ConcreteStructBody.Record(emptyArr!ConcreteField)),
		/*sizeBytes*/ 9999,
		/*isSelfMutable*/ True,
		/*defaultIsPointer*/ True));

	immutable ConcreteStructInfo info = matchStructBody!(immutable ConcreteStructInfo)(
		body_(i),
		(ref immutable StructBody.Bogus) => unreachable!(immutable ConcreteStructInfo),
		(ref immutable StructBody.Builtin) {
			immutable BuiltinStructKind kind = getBuiltinStructKind(i.decl.name);
			return immutable ConcreteStructInfo(
				immutable ConcreteStructBody(ConcreteStructBody.Builtin(kind, typeArgs)),
				getBuiltinStructSize(kind),
				False,
				False);
		},
		(ref immutable StructBody.ExternPtr it) =>
			immutable ConcreteStructInfo(
				immutable ConcreteStructBody(immutable ConcreteStructBody.ExternPtr()),
				(void*).sizeof,
				False,
				//defaultIsPointer is false because the 'extern' type *is* a pointer
				False),
		(ref immutable StructBody.Record r) {
			immutable Arr!ConcreteField fields =
				mapPtrsWithIndex!ConcreteField(alloc, r.fields, (immutable size_t index, immutable Ptr!RecordField f) =>
					immutable ConcreteField(
						immutable ConcreteFieldSource(f),
						safeSizeTToU8(index),
						f.isMutable,
						getConcreteType(alloc, ctx, f.type, typeArgsScope)));
			return getConcreteStructInfoForFields(r.forcedByValOrRef, fields);
		},
		(ref immutable StructBody.Union u) {
			immutable Arr!ConcreteType members = map!ConcreteType(alloc, u.members, (ref immutable Ptr!StructInst si) =>
				getConcreteType_forStructInst(alloc, ctx, si, typeArgsScope));
			immutable size_t maxMember =
				arrMax(0, members, (ref immutable ConcreteType t) => sizeOrPointerSizeBytes(t));
			// Must factor in the 'kind' size. It seems that enums are int-sized.
			immutable size_t sizeBytes = roundUp(int.sizeof + maxMember, (void*).sizeof);
			return immutable ConcreteStructInfo(
				immutable ConcreteStructBody(ConcreteStructBody.Union(members)),
				sizeBytes,
				False,
				False);
		});
	lateSetOverwrite(res.info_, info);
}

void fillInConcreteFunBody(Alloc)(
	ref Alloc alloc,
	ref ConcretizeCtx ctx,
	Ptr!ConcreteFun cf,
) {
	// TODO: just assert it's not already set?
	if (!lateIsSet(cf._body_)) {
		// set to arbitrary temporarily
		lateSet(cf._body_, immutable ConcreteFunBody(immutable ConcreteFunBody.Extern(False, strLiteral("<<temp>>"))));
		immutable ConcreteFunBodyInputs inputs = mustDelete(ctx.concreteFunToBodyInputs, castImmutable(cf));
		immutable ConcreteFunBody body_ = matchFunBody!(immutable ConcreteFunBody)(
			inputs.body_,
			(ref immutable FunBody.Builtin) =>
				immutable ConcreteFunBody(immutable ConcreteFunBody.Builtin(typeArgs(inputs))),
			(ref immutable FunBody.CreateRecord) =>
				immutable ConcreteFunBody(immutable ConcreteFunBody.CreateRecord()),
			(ref immutable FunBody.Extern e) =>
				immutable ConcreteFunBody(immutable ConcreteFunBody.Extern(e.isGlobal, e.externName)),
			(immutable Ptr!Expr e) =>
				concretizeExpr(alloc, ctx, inputs, castImmutable(cf), e.deref));
		lateSetOverwrite(cf._body_, body_);
	}
}

immutable(Arr!ConcreteParam) concretizeParams(Alloc)(
	ref Alloc alloc,
	ref ConcretizeCtx ctx,
	ref immutable Arr!Param params,
	ref immutable TypeArgsScope typeArgsScope,
) {
	return mapPtrsWithIndex!ConcreteParam(alloc, params, (immutable size_t index, immutable Ptr!Param p) =>
		immutable ConcreteParam(
			immutable ConcreteParamSource(p),
			some!size_t(index),
			getConcreteType(alloc, ctx, p.type, typeArgsScope)));
}

immutable(BuiltinStructKind) getBuiltinStructKind(immutable Sym name) {
	switch (name.value) {
		case shortSymAlphaLiteralValue("bool"):
			return BuiltinStructKind.bool_;
		case shortSymAlphaLiteralValue("char"):
			return BuiltinStructKind.char_;
		case shortSymAlphaLiteralValue("float"):
			return BuiltinStructKind.float64;
		case shortSymAlphaLiteralValue("fun-ptr0"):
		case shortSymAlphaLiteralValue("fun-ptr1"):
		case shortSymAlphaLiteralValue("fun-ptr2"):
		case shortSymAlphaLiteralValue("fun-ptr3"):
		case shortSymAlphaLiteralValue("fun-ptr4"):
		case shortSymAlphaLiteralValue("fun-ptr5"):
		case shortSymAlphaLiteralValue("fun-ptr6"):
			return BuiltinStructKind.funPtrN;
		case shortSymAlphaLiteralValue("int8"):
			return BuiltinStructKind.int8;
		case shortSymAlphaLiteralValue("int16"):
			return BuiltinStructKind.int16;
		case shortSymAlphaLiteralValue("int32"):
			return BuiltinStructKind.int32;
		case shortSymAlphaLiteralValue("int"):
			return BuiltinStructKind.int64;
		case shortSymAlphaLiteralValue("nat8"):
			return BuiltinStructKind.nat8;
		case shortSymAlphaLiteralValue("nat16"):
			return BuiltinStructKind.nat16;
		case shortSymAlphaLiteralValue("nat32"):
			return BuiltinStructKind.nat32;
		case shortSymAlphaLiteralValue("nat"):
			return BuiltinStructKind.nat64;
		case shortSymAlphaLiteralValue("ptr"):
			return BuiltinStructKind.ptr;
		case shortSymAlphaLiteralValue("void"):
			return BuiltinStructKind.void_;
		default:
			return todo!(immutable BuiltinStructKind)("not a builtin struct");
	}
}

immutable(size_t) getBuiltinStructSize(immutable BuiltinStructKind kind) {
	final switch (kind) {
		case BuiltinStructKind.bool_:
			return Bool.sizeof;
		case BuiltinStructKind.char_:
			return char.sizeof;
		case BuiltinStructKind.float64:
			return double.sizeof;
		case BuiltinStructKind.funPtrN:
			return (void*).sizeof;
		case BuiltinStructKind.int8:
			return byte.sizeof;
		case BuiltinStructKind.int16:
			return short.sizeof;
		case BuiltinStructKind.int32:
			return int.sizeof;
		case BuiltinStructKind.int64:
			return long.sizeof;
		case BuiltinStructKind.nat8:
			return ubyte.sizeof;
		case BuiltinStructKind.nat16:
			return ushort.sizeof;
		case BuiltinStructKind.nat32:
			return uint.sizeof;
		case BuiltinStructKind.nat64:
			return ulong.sizeof;
		case BuiltinStructKind.ptr:
			return (void*).sizeof;
		case BuiltinStructKind.void_:
			return 1; // TODO: should be 0?
	}
}
