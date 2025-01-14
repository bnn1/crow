module frontend.check.typeFromAst;

@safe @nogc pure nothrow:

import frontend.check.checkCtx :
	addDiag,
	CheckCtx,
	eachImportAndReExport,
	ImportIndex,
	markUsedImport,
	markUsedSpec,
	markUsedStructOrAlias;
import frontend.check.dicts : SpecDeclAndIndex, SpecsDict, StructsAndAliasesDict, StructOrAliasAndIndex;
import frontend.check.instantiate : DelayStructInsts, instantiateStruct, instantiateStructNeverDelay, TypeParamsScope;
import frontend.parse.ast : matchTypeAst, range, symForTypeAstDict, symForTypeAstSuffix, TypeAst;
import frontend.programState : ProgramState;
import model.diag : Diag;
import model.model :
	CommonTypes,
	FunKind,
	FunKindAndStructs,
	matchStructOrAliasPtr,
	Module,
	NameReferents,
	SpecDecl,
	StructAlias,
	StructDecl,
	StructDeclAndArgs,
	StructInst,
	StructOrAlias,
	target,
	Type,
	TypeParam,
	typeParams;
import util.alloc.alloc : Alloc;
import util.col.arr : empty, toArr;
import util.col.arrUtil : arrLiteral, fillArr, find, findPtr, map;
import util.col.dict : getAt;
import util.opt : force, has, none, Opt, some;
import util.ptr : Ptr;
import util.sourceRange : RangeWithinFile;
import util.sym : shortSymValue, Sym, symEq;
import util.util : todo;

private immutable(Type) instStructFromAst(
	ref Alloc alloc,
	ref CheckCtx ctx,
	ref immutable CommonTypes commonTypes,
	immutable Sym name,
	immutable RangeWithinFile range,
	scope immutable TypeAst[] typeArgAsts,
	ref immutable StructsAndAliasesDict structsAndAliasesDict,
	immutable TypeParamsScope typeParamsScope,
	DelayStructInsts delayStructInsts,
) {
	immutable Opt!StructOrAliasAndIndex opDeclFromHere = getAt(structsAndAliasesDict, name);
	if (has(opDeclFromHere))
		markUsedStructOrAlias(ctx, force(opDeclFromHere));
	immutable Opt!StructOrAlias here = has(opDeclFromHere)
		? some(force(opDeclFromHere).structOrAlias)
		: none!StructOrAlias;
	immutable Opt!StructOrAlias opDecl = tryFindT!StructOrAlias(
		alloc,
		ctx,
		name,
		range,
		here,
		Diag.DuplicateImports.Kind.type,
		Diag.NameNotFound.Kind.type,
		(ref immutable NameReferents nr) =>
			nr.structOrAlias);
	if (!has(opDecl))
		return immutable Type(Type.Bogus());
	else {
		immutable StructOrAlias sOrA = force(opDecl);
		immutable size_t nExpectedTypeArgs = typeParams(sOrA).length;
		immutable Type[] typeArgs = getTypeArgsIfNumberMatches(
			alloc, ctx, commonTypes, range, structsAndAliasesDict,
			sOrA, nExpectedTypeArgs, typeArgAsts, typeParamsScope, delayStructInsts);
		return matchStructOrAliasPtr!(immutable Type)(
			sOrA,
			(ref immutable StructAlias a) =>
				nExpectedTypeArgs != 0
					? todo!(immutable Type)("alias with type params")
					: typeFromOptInst(target(a)),
			(immutable Ptr!StructDecl decl) =>
				immutable Type(instantiateStruct(
					alloc,
					ctx.programState,
					immutable StructDeclAndArgs(decl, typeArgs),
					delayStructInsts)));
	}
}

private immutable(Type[]) getTypeArgsIfNumberMatches(
	ref Alloc alloc,
	ref CheckCtx ctx,
	ref immutable CommonTypes commonTypes,
	immutable RangeWithinFile range,
	ref immutable StructsAndAliasesDict structsAndAliasesDict,
	immutable StructOrAlias sOrA,
	immutable size_t nExpectedTypeArgs,
	scope immutable TypeAst[] typeArgAsts,
	immutable TypeParamsScope typeParamsScope,
	DelayStructInsts delayStructInsts,
) {
	if (typeArgAsts.length != nExpectedTypeArgs) {
		addDiag(alloc, ctx, range, immutable Diag(
			immutable Diag.WrongNumberTypeArgsForStruct(sOrA, nExpectedTypeArgs, typeArgAsts.length)));
		return fillArr!Type(alloc, nExpectedTypeArgs, (immutable size_t) => immutable Type(Type.Bogus()));
	} else
		return typeArgsFromAsts(
			alloc,
			ctx,
			commonTypes,
			typeArgAsts,
			structsAndAliasesDict,
			typeParamsScope,
			delayStructInsts);
}

immutable(Type) typeFromAst(
	ref Alloc alloc,
	ref CheckCtx ctx,
	ref immutable CommonTypes commonTypes,
	scope immutable TypeAst ast,
	ref immutable StructsAndAliasesDict structsAndAliasesDict,
	immutable TypeParamsScope typeParamsScope,
	DelayStructInsts delayStructInsts,
) {
	return matchTypeAst!(
		immutable Type,
		(immutable TypeAst.Dict it) =>
			instStructFromAst(
				alloc,
				ctx,
				commonTypes,
				symForTypeAstDict(it.kind),
				range(it),
				[it.k, it.v],
				structsAndAliasesDict,
				typeParamsScope,
				delayStructInsts),
		(immutable TypeAst.Fun it) =>
			typeFromFunAst(alloc, ctx, commonTypes, it, structsAndAliasesDict, typeParamsScope, delayStructInsts),
		(immutable TypeAst.InstStruct iAst) {
			immutable Opt!(Diag.TypeShouldUseSyntax.Kind) optSyntax = typeSyntaxKind(iAst.name.name);
			if (has(optSyntax))
				addDiag(alloc, ctx, iAst.range, immutable Diag(immutable Diag.TypeShouldUseSyntax(force(optSyntax))));

			immutable Opt!(Ptr!TypeParam) found =
				findPtr!TypeParam(typeParamsScope.innerTypeParams, (immutable Ptr!TypeParam it) =>
					symEq(it.deref().name, iAst.name.name));
			if (has(found)) {
				if (!empty(toArr(iAst.typeArgs)))
					addDiag(alloc, ctx, iAst.range, immutable Diag(immutable Diag.TypeParamCantHaveTypeArgs()));
				return immutable Type(force(found));
			} else
				return instStructFromAst(
					alloc,
					ctx,
					commonTypes,
					iAst.name.name,
					iAst.range,
					toArr(iAst.typeArgs),
					structsAndAliasesDict,
					typeParamsScope,
					delayStructInsts);
		},
		(immutable TypeAst.Suffix it) =>
			instStructFromAst(
				alloc,
				ctx,
				commonTypes,
				symForTypeAstSuffix(it.kind),
				range(it),
				[it.left],
				structsAndAliasesDict,
				typeParamsScope,
				delayStructInsts),
	)(ast);
}

private immutable(Opt!(Diag.TypeShouldUseSyntax.Kind)) typeSyntaxKind(immutable Sym a) {
	switch (a.value) {
		case shortSymValue("arr"):
			return some(Diag.TypeShouldUseSyntax.Kind.arr);
		case shortSymValue("const-ptr"):
			return some(Diag.TypeShouldUseSyntax.Kind.ptr);
		case shortSymValue("dict"):
			return some(Diag.TypeShouldUseSyntax.Kind.dict);
		case shortSymValue("mut-arr"):
			return some(Diag.TypeShouldUseSyntax.Kind.arrMut);
		case shortSymValue("mut-dict"):
			return some(Diag.TypeShouldUseSyntax.Kind.dictMut);
		case shortSymValue("opt"):
			return some(Diag.TypeShouldUseSyntax.Kind.opt);
		case shortSymValue("mut-ptr"):
			return some(Diag.TypeShouldUseSyntax.Kind.ptrMut);
		default:
			return none!(Diag.TypeShouldUseSyntax.Kind);
	}
}

private immutable(Type) typeFromOptInst(immutable Opt!(Ptr!StructInst) a) {
	return has(a) ? immutable Type(force(a)) : immutable Type(Type.Bogus());
}

private immutable(Type) typeFromFunAst(
	ref Alloc alloc,
	ref CheckCtx ctx,
	ref immutable CommonTypes commonTypes,
	immutable TypeAst.Fun ast,
	ref immutable StructsAndAliasesDict structsAndAliasesDict,
	immutable TypeParamsScope typeParamsScope,
	DelayStructInsts delayStructInsts,
) {
	immutable FunKind funKind = () {
		final switch (ast.kind) {
			case TypeAst.Fun.Kind.act:
				return FunKind.mut;
			case TypeAst.Fun.Kind.fun:
				return FunKind.plain;
			case TypeAst.Fun.Kind.ref_:
				return FunKind.ref_;
		}
	}();
	immutable Opt!FunKindAndStructs optF = find!FunKindAndStructs(
		commonTypes.funKindsAndStructs,
		(ref immutable FunKindAndStructs it) =>
			it.kind == funKind);
	immutable Ptr!StructDecl[] structs = force(optF).structs;
	if (ast.returnAndParamTypes.length > structs.length)
		// We don't have a fun type big enough
		todo!void("!");
	immutable Ptr!StructDecl decl = structs[ast.returnAndParamTypes.length - 1];
	immutable Type[] typeArgs = map!Type(alloc, ast.returnAndParamTypes, (ref immutable TypeAst it) =>
		typeFromAst(alloc, ctx, commonTypes, it, structsAndAliasesDict, typeParamsScope, delayStructInsts));
	return immutable Type(instantiateStruct(
		alloc,
		ctx.programState,
		immutable StructDeclAndArgs(decl, typeArgs),
		delayStructInsts));
}

immutable(Opt!(Ptr!SpecDecl)) tryFindSpec(
	ref Alloc alloc,
	ref CheckCtx ctx,
	immutable Sym name,
	immutable RangeWithinFile range,
	ref immutable SpecsDict specsDict,
) {
	immutable Opt!SpecDeclAndIndex opDeclFromHere = getAt(specsDict, name);
	if (has(opDeclFromHere))
		markUsedSpec(ctx, force(opDeclFromHere).index);
	immutable Opt!(Ptr!SpecDecl) here = has(opDeclFromHere) ? some(force(opDeclFromHere).decl) : none!(Ptr!SpecDecl);
	return tryFindT!(Ptr!SpecDecl)(
		alloc,
		ctx,
		name,
		range,
		here,
		Diag.DuplicateImports.Kind.spec,
		Diag.NameNotFound.Kind.spec,
		(ref immutable NameReferents nr) =>
			nr.spec);
}

immutable(Type[]) typeArgsFromAsts(
	ref Alloc alloc,
	ref CheckCtx ctx,
	ref immutable CommonTypes commonTypes,
	scope immutable TypeAst[] typeAsts,
	ref immutable StructsAndAliasesDict structsAndAliasesDict,
	immutable TypeParamsScope typeParamsScope,
	DelayStructInsts delayStructInsts,
) {
	return map!Type(alloc, typeAsts, (ref immutable TypeAst it) =>
		typeFromAst(alloc, ctx, commonTypes, it, structsAndAliasesDict, typeParamsScope, delayStructInsts));
}

immutable(Type) makeFutType(
	ref Alloc alloc,
	ref ProgramState programState,
	ref immutable CommonTypes commonTypes,
	immutable Type type,
) {
	return immutable Type(instantiateStructNeverDelay(
		alloc,
		programState,
		immutable StructDeclAndArgs(commonTypes.fut, arrLiteral!Type(alloc, [type]))));
}

private:

immutable(Opt!T) tryFindT(T)(
	ref Alloc alloc,
	ref CheckCtx ctx,
	immutable Sym name,
	immutable RangeWithinFile range,
	ref immutable Opt!T fromThisModule,
	immutable Diag.DuplicateImports.Kind duplicateImportKind,
	immutable Diag.NameNotFound.Kind nameNotFoundKind,
	scope immutable(Opt!T) delegate(ref immutable NameReferents) @safe @nogc pure nothrow getFromNameReferents,
) {
	immutable Opt!T res = eachImportAndReExport!(immutable Opt!T)(
		ctx,
		name,
		fromThisModule,
		(immutable Opt!T acc,
		 immutable Ptr!Module,
		 immutable ImportIndex index,
		 ref immutable NameReferents referents) {
			immutable Opt!T got = getFromNameReferents(referents);
			if (has(got)) {
				markUsedImport(ctx, index);
				if (has(acc))
					// TODO: include both modules in the diag
					addDiag(alloc, ctx, range, immutable Diag(
						immutable Diag.DuplicateImports(duplicateImportKind, name)));
				return got;
			} else
				return acc;
		});
	if (!has(res))
		addDiag(alloc, ctx, range, immutable Diag(immutable Diag.NameNotFound(nameNotFoundKind, name)));
	return res;
}
