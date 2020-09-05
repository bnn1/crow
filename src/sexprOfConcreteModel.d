module sexprOfConcreteModel;

@safe @nogc pure nothrow:

import concreteModel :
	body_,
	ConcreteExpr,
	ConcreteField,
	ConcreteFun,
	ConcreteFunBody,
	ConcreteFunExprBody,
	ConcreteLocal,
	ConcreteParam,
	ConcreteProgram,
	ConcreteStruct,
	ConcreteStructBody,
	ConcreteType,
	defaultIsPointer,
	isSelfMutable,
	matchConcreteExpr,
	matchConcreteFunBody,
	matchConcreteStructBody,
	returnType,
	SpecialStructInfo,
	symOfBuiltinFunEmit,
	strOfBuiltinFunKind,
	symOfBuiltinStructKind;
import util.bools : True;
import util.collection.arrBuilder : add, ArrBuilder, finishArr;
import util.collection.str : strLiteral;
import util.opt : force, has;
import util.ptr : Ptr;
import util.sexpr :
	NameAndSexpr,
	nameAndTata,
	Sexpr,
	tataArr,
	tataBool,
	tataNamedRecord,
	tataNat,
	tataOpt,
	tataRecord,
	tataStr,
	tataSym;
import util.sourceRange : sexprOfSourceRange;
import util.verify : unreachable;

immutable(Sexpr) tataOfConcreteProgram(Alloc)(ref Alloc alloc, ref immutable ConcreteProgram a) {
	return tataRecord(
		alloc,
		"program",
		tataArr(alloc, a.allStructs, (ref immutable Ptr!ConcreteStruct it) =>
			tataOfConcreteStruct(alloc, it)),
		tataArr(alloc, a.allFuns, (ref immutable Ptr!ConcreteFun it) =>
			tataOfConcreteFun(alloc, it)),
		tataOfConcreteFunPtr(alloc, a.rtMain),
		tataOfConcreteFunPtr(alloc, a.userMain),
		tataOfConcreteStructPtr(alloc, a.ctxType));
}

private:

immutable(Sexpr) tataOfConcreteStruct(Alloc)(ref Alloc alloc, ref immutable ConcreteStruct a) {
	ArrBuilder!NameAndSexpr fields;
	add(alloc, fields, nameAndTata("name", tataStr(a.mangledName)));
	if (has(a.special))
		add(alloc, fields, nameAndTata("special", tataOfSpecialStructInfo(alloc, force(a.special))));
	if (isSelfMutable(a))
		add(alloc, fields, nameAndTata("mut?", tataBool(True)));
	if (defaultIsPointer(a))
		add(alloc, fields, nameAndTata("ptr?", tataBool(True)));
	add(alloc, fields, nameAndTata("body", tataOfConcreteStructBody(alloc, body_(a))));
	return tataNamedRecord("struct", finishArr(alloc, fields));
}

immutable(Sexpr) tataOfSpecialStructInfo(Alloc)(ref Alloc alloc, ref immutable SpecialStructInfo a) {
	return tataRecord(
		alloc,
		"special",
		tataSym(() {
			final switch (a.kind) {
				case SpecialStructInfo.Kind.arr:
					return "arr";
			}
		}()),
		tataOfConcreteType(alloc, a.elementType));
}

immutable(Sexpr) tataOfConcreteStructBody(Alloc)(ref Alloc alloc, ref immutable ConcreteStructBody a) {
	return matchConcreteStructBody(
		a,
		(ref immutable ConcreteStructBody.Builtin it) =>
			tataOfConcreteStructBodyBuiltin(alloc, it),
		(ref immutable ConcreteStructBody.Record it) =>
			tataOfConcreteStructBodyRecord(alloc, it),
		(ref immutable ConcreteStructBody.Union it) =>
			tataOfConcreteStructBodyUnion(alloc, it));
}

immutable(Sexpr) tataOfConcreteStructBodyBuiltin(Alloc)(ref Alloc alloc, ref immutable ConcreteStructBody.Builtin a) {
	return tataRecord(
		alloc,
		"builtin",
		tataSym(symOfBuiltinStructKind(a.info.kind)),
		tataNat(a.info.sizeBytes),
		tataArr(alloc, a.typeArgs, (ref immutable ConcreteType it) =>
			tataOfConcreteType(alloc, it)));
}

immutable(Sexpr) tataOfConcreteType(Alloc)(ref Alloc alloc, ref immutable ConcreteType a) {
	return tataRecord(
		alloc,
		"type",
		tataBool(a.isPointer),
		tataStr(a.struct_.mangledName));
}

immutable(Sexpr) tataOfConcreteStructBodyRecord(Alloc)(ref Alloc alloc, ref immutable ConcreteStructBody.Record a) {
	return tataRecord(alloc, "record", tataArr(alloc, a.fields, (ref immutable ConcreteField it) =>
		tataOfConcreteField(alloc, it)));
}

immutable(Sexpr) tataOfConcreteField(Alloc)(ref Alloc alloc, ref immutable ConcreteField a) {
	return tataRecord(
		alloc,
		"field",
		tataBool(a.isMutable),
		tataStr(a.mangledName),
		tataOfConcreteType(alloc, a.type));
}

immutable(Sexpr) tataOfConcreteStructBodyUnion(Alloc)(ref Alloc alloc, ref immutable ConcreteStructBody.Union a) {
	return tataRecord(alloc, "union", tataArr(alloc, a.members, (ref immutable ConcreteType it) =>
		tataOfConcreteType(alloc, it)));
}

immutable(Sexpr) tataOfConcreteFun(Alloc)(ref Alloc alloc, ref immutable ConcreteFun a) {
	return tataRecord(
		alloc,
		"fun",
		tataBool(a.needsCtx),
		tataStr(a.mangledName),
		tataOfConcreteType(alloc, a.returnType),
		tataOpt(alloc, a.closureParam, (ref immutable ConcreteParam it) =>
			tataOfParam(alloc, it)),
		tataArr(alloc, a.paramsExcludingCtxAndClosure, (ref immutable ConcreteParam it) =>
			tataOfParam(alloc, it)),
		tataOfConcreteFunBody(alloc, body_(a)));
}

immutable(Sexpr) tataOfParam(Alloc)(ref Alloc alloc, ref immutable ConcreteParam a) {
	return tataRecord(
		alloc,
		"param",
		tataStr(a.mangledName),
		tataOfConcreteType(alloc, a.type));
}

immutable(Sexpr) tataOfConcreteStructPtr(Alloc)(ref Alloc alloc, immutable Ptr!ConcreteStruct a) {
	return tataStr(a.mangledName);
}

immutable(Sexpr) tataOfConcreteFunPtr(Alloc)(ref Alloc alloc, immutable Ptr!ConcreteFun a) {
	return tataStr(a.mangledName);
}

immutable(Sexpr) tataOfConcreteFunBody(Alloc)(ref Alloc alloc, ref immutable ConcreteFunBody a) {
	return matchConcreteFunBody!(immutable Sexpr)(
		a,
		(ref immutable ConcreteFunBody.Builtin it) =>
			tataOfConcreteFunBodyBuiltin(alloc, it),
		(ref immutable ConcreteFunBody.Extern it) =>
			tataRecord(alloc, "extern", tataBool(it.isGlobal)),
		(ref immutable ConcreteFunExprBody it) =>
			tataOfConcreteFunExprBody(alloc, it));
}

immutable(Sexpr) tataOfConcreteFunBodyBuiltin(Alloc)(ref Alloc alloc, ref immutable ConcreteFunBody.Builtin a) {
	return tataRecord(
		alloc,
		"builtin",
		tataSym(symOfBuiltinFunEmit(a.builtinInfo.emit)),
		tataStr(strLiteral(strOfBuiltinFunKind(a.builtinInfo.kind))),
		tataArr(alloc, a.typeArgs, (ref immutable ConcreteType it) =>
			tataOfConcreteType(alloc, it)));
}

immutable(Sexpr) tataOfConcreteFunExprBody(Alloc)(ref Alloc alloc, ref immutable ConcreteFunExprBody a) {
	return tataRecord(
		alloc,
		"expr-body",
		tataArr(alloc, a.allLocals, (ref immutable Ptr!ConcreteLocal it) =>
			tataRecord(
				alloc,
				"local",
				tataStr(it.mangledName),
				tataOfConcreteType(alloc, it.type))),
		tataOfConcreteExpr(alloc, a.expr));
}

immutable(Sexpr) tataOfConcreteExpr(Alloc)(ref Alloc alloc, ref immutable ConcreteExpr a) {
	// For brevity.. (change back once we have tail recursion and noze can handle long strings)
	return tataOfConcreteExprKind(alloc, a);
	//return tataRecord(
	//	alloc,
	//	"expr",
	//	tataOfConcreteType(alloc, a.type),
	//	sexprOfSourceRange(alloc, a.range),
	//	tataOfConcreteExprKind(alloc, a));
}

immutable(Sexpr) tataOfConcreteExprKind(Alloc)(ref Alloc alloc, ref immutable ConcreteExpr a) {
	return matchConcreteExpr!(immutable Sexpr)(
		a,
		(ref immutable ConcreteExpr.Alloc it) =>
			tataRecord(
				alloc,
				"alloc",
				tataStr(it.alloc.mangledName),
				tataOfConcreteExpr(alloc, it.inner)),
		(ref immutable ConcreteExpr.Call it) =>
			tataRecord(
				alloc,
				"call",
				tataStr(it.called.mangledName),
				tataArr(alloc, it.args, (ref immutable ConcreteExpr arg) =>
					tataOfConcreteExpr(alloc, arg))),
		(ref immutable ConcreteExpr.Cond it) =>
			tataRecord(
				alloc,
				"cond",
				tataOfConcreteExpr(alloc, it.cond),
				tataOfConcreteExpr(alloc, it.then),
				tataOfConcreteExpr(alloc, it.else_)),
		(ref immutable ConcreteExpr.CreateArr it) =>
			tataRecord(
				alloc,
				"create-arr",
				tataStr(it.arrType.mangledName),
				tataOfConcreteType(alloc, it.elementType),
				tataStr(it.alloc.mangledName),
				tataStr(it.local.mangledName),
				tataArr(alloc, it.args, (ref immutable ConcreteExpr arg) =>
					tataOfConcreteExpr(alloc, arg))),
		(ref immutable ConcreteExpr.CreateRecord it) =>
			tataRecord(alloc, "record", tataArr(alloc, it.args, (ref immutable ConcreteExpr arg) =>
				tataOfConcreteExpr(alloc, arg))),
		(ref immutable ConcreteExpr.ConvertToUnion it) =>
			tataRecord(
				alloc,
				"to-union",
				tataNat(it.memberIndex),
				tataOfConcreteExpr(alloc, it.arg)),
		(ref immutable ConcreteExpr.Lambda it) =>
			tataRecord(
				alloc,
				"lambda",
				tataStr(it.fun.mangledName),
				tataOpt(alloc, it.closure, (ref immutable Ptr!ConcreteExpr closure) =>
					tataOfConcreteExpr(alloc, closure))),
		(ref immutable ConcreteExpr.Let it) =>
			tataRecord(
				alloc,
				"let",
				tataStr(it.local.mangledName),
				tataOfConcreteExpr(alloc, it.value),
				tataOfConcreteExpr(alloc, it.then)),
		(ref immutable ConcreteExpr.LocalRef it) =>
			tataRecord(
				alloc,
				"local-ref",
				tataStr(it.local.mangledName)),
		(ref immutable ConcreteExpr.Match it) =>
			tataRecord(
				alloc,
				"match",
				tataStr(it.matchedLocal.mangledName),
				tataOfConcreteExpr(alloc, it.matchedValue),
				tataArr(alloc, it.cases, (ref immutable ConcreteExpr.Match.Case case_) =>
					tataRecord(
						alloc,
						"case",
						tataOpt(alloc, case_.local, (ref immutable Ptr!ConcreteLocal local) =>
							tataStr(local.mangledName)),
						tataOfConcreteExpr(alloc, case_.then)))),
		(ref immutable ConcreteExpr.ParamRef it) =>
			tataRecord(alloc, "param-ref", tataStr(it.param.mangledName)),
		(ref immutable ConcreteExpr.RecordFieldAccess it) =>
			tataRecord(
				alloc,
				"get-field",
				tataOfConcreteExpr(alloc, it.target),
				tataStr(it.field.mangledName)),
		(ref immutable ConcreteExpr.RecordFieldSet it) =>
			tataRecord(
				alloc,
				"set-field",
				tataOfConcreteExpr(alloc, it.target),
				tataStr(it.field.mangledName),
				tataOfConcreteExpr(alloc, it.value)),
		(ref immutable ConcreteExpr.Seq it) =>
			tataRecord(
				alloc,
				"seq",
				tataOfConcreteExpr(alloc, it.first),
				tataOfConcreteExpr(alloc, it.then)),
		(ref immutable ConcreteExpr.SpecialConstant it) =>
			tataRecord(
				alloc,
				"special",
				tataSym(() {
					final switch (it.kind) {
						case ConcreteExpr.SpecialConstant.Kind.one:
							return "one";
						case ConcreteExpr.SpecialConstant.Kind.zero:
							return "zero";
					}
				}())),
		(ref immutable ConcreteExpr.SpecialUnary it) =>
			tataRecord(
				alloc,
				"special",
				tataSym(() {
					final switch (it.kind) {
						case ConcreteExpr.SpecialUnary.Kind.deref:
							return "deref";
					}
				}()),
				tataOfConcreteExpr(alloc, it.arg)),
		(ref immutable ConcreteExpr.SpecialBinary it) =>
			tataRecord(
				alloc,
				"special",
				tataSym(() {
					final switch (it.kind) {
						case ConcreteExpr.SpecialBinary.Kind.add:
							return "add";
						case ConcreteExpr.SpecialBinary.Kind.eq:
							return "eq";
						case ConcreteExpr.SpecialBinary.Kind.less:
							return "less";
						case ConcreteExpr.SpecialBinary.Kind.or:
							return "or";
						case ConcreteExpr.SpecialBinary.Kind.sub:
							return "sub";
					}
				}()),
				tataOfConcreteExpr(alloc, it.left),
				tataOfConcreteExpr(alloc, it.right)),
		(ref immutable ConcreteExpr.StringLiteral it) =>
			tataRecord(alloc, "str-lit", tataStr(it.literal)));
}
