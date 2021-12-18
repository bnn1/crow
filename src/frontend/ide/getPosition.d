module frontend.ide.getPosition;

@safe @nogc pure nothrow:

import model.model :
	body_,
	decl,
	EnumFunction,
	Expr,
	FlagsFunction,
	FunBody,
	FunDecl,
	matchFunBody,
	matchStructBody,
	matchType,
	Module,
	ModuleAndNames,
	range,
	RecordField,
	SpecDecl,
	StructBody,
	StructDecl,
	StructInst,
	Type,
	TypeParam;
import util.col.arr : ptrsRange;
import util.opt : force, has, none, Opt, optOr2, some;
import util.ptr : Ptr;
import util.sourceRange : hasPos, Pos;
import util.sym : AllSymbols, Sym, symSize;

struct Position {
	@safe @nogc pure nothrow:

	struct ImportedModule {
		immutable Ptr!ModuleAndNames import_;
	}
	struct ImportedName {
		immutable Ptr!ModuleAndNames import_;
		immutable Sym name;
	}
	struct RecordFieldPosition {
		immutable Ptr!StructDecl struct_;
		immutable Ptr!RecordField field;
	}

	@trusted immutable this(immutable Expr a) { kind = Kind.expr; expr = a; }
	@trusted immutable this(immutable Ptr!FunDecl a) { kind = Kind.funDecl; funDecl = a; }
	@trusted immutable this(immutable ImportedModule a) { kind = Kind.importedModule; importedModule = a; }
	@trusted immutable this(immutable ImportedName a) { kind = Kind.importedName; importedName = a; }
	@trusted immutable this(immutable RecordFieldPosition a) { kind = Kind.recordField; recordField = a; }
	@trusted immutable this(immutable Ptr!SpecDecl a) { kind = Kind.specDecl; specDecl = a; }
	@trusted immutable this(immutable Ptr!StructDecl a) { kind = Kind.structDecl; structDecl = a; }
	@trusted immutable this(immutable Ptr!TypeParam a) { kind = Kind.typeParam; typeParam = a; }

	private:
	enum Kind {
		expr,
		funDecl,
		importedModule,
		importedName,
		recordField,
		specDecl,
		structDecl,
		typeParam,
	}
	immutable Kind kind;
	union {
		immutable Expr expr;
		immutable Ptr!FunDecl funDecl;
		immutable ImportedModule importedModule;
		immutable ImportedName importedName;
		immutable RecordFieldPosition recordField;
		immutable Ptr!SpecDecl specDecl;
		immutable Ptr!StructDecl structDecl;
		immutable Ptr!TypeParam typeParam;
	}
}

@trusted T matchPosition(T)(
	ref immutable Position a,
	scope T delegate(ref immutable Expr) @safe @nogc pure nothrow cbExpr,
	scope T delegate(ref immutable FunDecl) @safe @nogc pure nothrow cbFunDecl,
	scope T delegate(ref immutable Position.ImportedModule) @safe @nogc pure nothrow cbImportedModule,
	scope T delegate(ref immutable Position.ImportedName) @safe @nogc pure nothrow cbImportedName,
	scope T delegate(ref immutable Position.RecordFieldPosition) @safe @nogc pure nothrow cbRecordField,
	scope T delegate(ref immutable SpecDecl) @safe @nogc pure nothrow cbSpecDecl,
	scope T delegate(ref immutable StructDecl) @safe @nogc pure nothrow cbStructDecl,
	scope T delegate(ref immutable TypeParam) @safe @nogc pure nothrow cbTypeParam,
) {
	final switch (a.kind) {
		case Position.Kind.expr:
			return cbExpr(a.expr);
		case Position.Kind.funDecl:
			return cbFunDecl(a.funDecl.deref());
		case Position.Kind.importedModule:
			return cbImportedModule(a.importedModule);
		case Position.Kind.importedName:
			return cbImportedName(a.importedName);
		case Position.Kind.recordField:
			return cbRecordField(a.recordField);
		case Position.Kind.specDecl:
			return cbSpecDecl(a.specDecl.deref());
		case Position.Kind.structDecl:
			return cbStructDecl(a.structDecl.deref());
		case Position.Kind.typeParam:
			return cbTypeParam(a.typeParam.deref());
	}
}

immutable(Opt!Position) getPosition(ref const AllSymbols allSymbols, ref immutable Module module_, immutable Pos pos) {
	immutable Opt!Position fromImportsOrExports = optOr2(
		positionInImportsOrExports(allSymbols, module_.imports, pos),
		() => positionInImportsOrExports(allSymbols, module_.exports, pos));
	if (has(fromImportsOrExports))
		return fromImportsOrExports;

	foreach (immutable Ptr!StructDecl s; ptrsRange(module_.structs))
		if (hasPos(s.deref().range.range, pos))
			return some(positionInStruct(allSymbols, s, pos));

	foreach (immutable Ptr!SpecDecl s; ptrsRange(module_.specs))
		if (hasPos(s.deref().range.range, pos))
			//TODO: delve inside!
			return some(immutable Position(s));

	foreach (immutable Ptr!FunDecl f; ptrsRange(module_.funs)) {
		if (hasPos(f.deref().sig.range(allSymbols), pos))
			//TODO: delve inside!
			return some(immutable Position(f));
		immutable Opt!Position fromBody = matchFunBody!(
			immutable Opt!Position,
			(ref immutable FunBody.Builtin) =>
				none!Position,
			(ref immutable FunBody.CreateEnum) =>
				none!Position,
			(ref immutable FunBody.CreateRecord) =>
				none!Position,
			(ref immutable FunBody.CreateUnion) =>
				none!Position,
			(immutable(EnumFunction)) =>
				none!Position,
			(ref immutable FunBody.Extern) =>
				none!Position,
			(ref immutable Expr it) =>
				hasPos(range(it).range, pos)
					//TODO: delve inside!
					? some(immutable Position(it))
					: none!Position,
			(immutable(FlagsFunction)) =>
				none!Position,
			(ref immutable FunBody.RecordFieldGet) =>
				none!Position,
			(ref immutable FunBody.RecordFieldSet) =>
				none!Position,
		)(f.deref().body_);
		if (has(fromBody))
			return fromBody;
	}

	return none!Position;

	//TODO: check for aliases too
}

private:

immutable(Opt!Position) positionInImportsOrExports(
	ref const AllSymbols allSymbols,
	ref immutable ModuleAndNames[] importsOrExports,
	immutable Pos pos,
) {
	foreach (immutable Ptr!ModuleAndNames im; ptrsRange(importsOrExports)) {
		if (has(im.deref().importSource) && hasPos(force(im.deref().importSource), pos)) {
			if (has(im.deref().names)) {
				Pos namePos = force(im.deref().importSource).start;
				foreach (immutable Sym name; force(im.deref().names)) {
					immutable Pos nameEnd = namePos + symSize(allSymbols, name);
					if (pos < nameEnd)
						return some(immutable Position(immutable Position.ImportedName(im, name)));
					namePos = nameEnd + 1;
				}
			}
			return some(immutable Position(immutable Position.ImportedModule(im)));
		}
	}
	return none!Position;
}

immutable(Position) positionInStruct(ref const AllSymbols allSymbols, immutable Ptr!StructDecl a, immutable Pos pos) {
	//TODO: look through type params!

	immutable Opt!Position specific = matchStructBody!(immutable Opt!Position)(
		body_(a.deref()),
		(ref immutable StructBody.Bogus) =>
			none!Position,
		(ref immutable StructBody.Builtin) =>
			none!Position,
		(ref immutable StructBody.Enum) =>
			none!Position, // TODO
		(ref immutable StructBody.Flags) =>
			none!Position, // TODO
		(ref immutable StructBody.ExternPtr) =>
			none!Position,
		(ref immutable StructBody.Record it) {
			foreach (immutable Ptr!RecordField field; ptrsRange(it.fields))
				if (hasPos(field.deref().range.range, pos))
					return nameHasPos(allSymbols, field.deref().range.start, field.deref().name, pos)
						? some(immutable Position(immutable Position.RecordFieldPosition(a, field)))
						: positionOfType(field.deref().type);
			return none!Position;
		},
		(ref immutable StructBody.Union) =>
			//TODO
			none!Position);
	return has(specific) ? force(specific) : immutable Position(a);
}

immutable(Opt!Position) positionOfType(immutable Type a) {
	return matchType!(immutable Opt!Position)(
		a,
		(immutable Type.Bogus) => none!Position,
		(immutable Ptr!TypeParam it) => some(immutable Position(it)),
		(immutable Ptr!StructInst it) => some(immutable Position(decl(it.deref()))));
}

immutable(bool) nameHasPos(
	ref const AllSymbols allSymbols,
	immutable Pos start,
	immutable Sym name,
	immutable Pos pos,
) {
	return start <= pos && pos < start + symSize(allSymbols, name);
}
