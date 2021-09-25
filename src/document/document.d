module document.document;

@safe @nogc pure nothrow:

import model.model :
	body_,
	FunDecl,
	generated,
	matchSpecBody,
	matchStructBody,
	matchStructOrAlias,
	matchType,
	Module,
	name,
	NameReferents,
	Param,
	params,
	Program,
	RecordField,
	returnType,
	Sig,
	SpecBody,
	SpecDecl,
	StructAlias,
	StructBody,
	StructDecl,
	StructInst,
	StructOrAlias,
	target,
	Type,
	typeArgs,
	TypeParam,
	typeParams;
import util.collection.arr : empty, only, size;
import util.collection.arrUtil : findIndex;
import util.collection.dict : dictEach;
import util.collection.fullIndexDict : fullIndexDictGet;
import util.collection.str : SafeCStr, strOfSafeCStr;
import util.opt : force, has, Opt;
import util.path : AllPaths, eachPathPart, nPathComponents, Path;
import util.ptr : Ptr, ptrTrustMe_mut;
import util.sym : compareSym, Sym, writeSym;
import util.util : repeat, todo, unreachable;
import util.writer : finishWriter, Writer, writeChar, writeStatic, writeStr, writeWithCommas;

immutable(string) document(Alloc, PathAlloc)(
	ref Alloc alloc,
	ref const AllPaths!PathAlloc allPaths,
	ref immutable Program p,
	ref immutable Module a,
) {
	Writer!Alloc writer = Writer!Alloc(ptrTrustMe_mut(alloc));

	writeStatic(writer, "// generated by `crow doc`\n");
	immutable Path path = fullIndexDictGet(p.filesInfo.filePaths, a.fileIndex).path;
	writeStatic(writer, "include ");
	repeat(nPathComponents(allPaths, path), () {
		writeStatic(writer, "../");
	});
	writeStatic(writer, "pug-include/documentation.pug\n");
	writeStatic(writer, "+documentationPage(\"");
	writeModulePath(writer, allPaths, path);
	writeStatic(writer, "\")\n");
	writeStatic(writer, "\tsection");
	dictEach!(Sym, NameReferents, compareSym)(
		a.allExportedNames,
		(ref immutable Sym name, ref immutable NameReferents referents) {
			if (has(referents.structOrAlias))
				writeStructOrAlias(writer, force(referents.structOrAlias));
			if (has(referents.spec))
				writeSpec(writer, force(referents.spec));
			foreach (immutable Ptr!FunDecl fun; referents.funs)
				if (!fun.generated)
					writeFun(writer, fun);
		});
	writeStatic(writer, "\n");
	return finishWriter(writer);
}

private:

void writeModulePath(Alloc, PathAlloc)(
	ref Writer!Alloc writer,
	ref const AllPaths!PathAlloc allPaths,
	immutable Path path,
) {
	bool first = true;
	eachPathPart(allPaths, path, (immutable string part) {
		if (first)
			first = false;
		else
			writeChar(writer, '.');
		writeStatic(writer, part);
	});
}

void writeStructOrAlias(Alloc)(ref Writer!Alloc writer, ref immutable StructOrAlias a) {
	matchStructOrAlias!void(
		a,
		(immutable Ptr!StructAlias it) {
			writeStructAlias(writer, it);
		},
		(immutable Ptr!StructDecl it) {
			writeStructDecl(writer, it);
		});
}

void writeStructAlias(Alloc)(ref Writer!Alloc writer, ref immutable StructAlias a) {
	writeStatic(writer, "\n\t\t+alias(");
	writeQuotedSym(writer, a.name);
	writeTypeParams(writer, typeParams(a));
	writeStatic(writer, ", ");
	immutable Opt!(Ptr!StructInst) optTarget = target(a);
	writeQuotedType(writer, immutable Type(force(optTarget)));
	writeChar(writer, ')');
	writeDocComment(writer, a.docComment);
}

void writeStructDecl(Alloc)(ref Writer!Alloc writer, ref immutable StructDecl a) {
	matchStructBody!void(
		body_(a),
		(ref immutable(StructBody.Bogus)) {
			unreachable!void();
		},
		(ref immutable(StructBody.Builtin)) {
			writeStatic(writer, "\n\t\t+builtinType(");
			writeQuotedSym(writer, a.name);
			writeTypeParams(writer, typeParams(a));
			writeStatic(writer, ")");
		},
		(ref immutable(StructBody.Enum)) {
			todo!void("!");
		},
		(ref immutable(StructBody.Flags)) {
			todo!void("!");
		},
		(ref immutable(StructBody.ExternPtr)) {
			writeStatic(writer, "\n\t\t+externPtrType(");
			writeQuotedSym(writer, a.name);
			writeTypeParams(writer, typeParams(a));
			writeStatic(writer, ")");
		},
		(ref immutable StructBody.Record it) {
			writeRecord(writer, a, it);
		},
		(ref immutable StructBody.Union it) {
			writeUnion(writer, a, it);
		});
	writeDocComment(writer, a.docComment);
}

void writeRecord(Alloc)(ref Writer!Alloc writer, ref immutable StructDecl a, ref immutable StructBody.Record r) {
	writeStatic(writer, "\n\t\t+record(");
	writeQuotedSym(writer, a.name);
	writeTypeParams(writer, typeParams(a));
	writeStatic(writer, ", [");
	writeWithCommas!RecordField(writer, r.fields, (ref immutable RecordField field) {
		writeChar(writer, '[');
		writeQuotedSym(writer, field.name);
		writeStatic(writer, ", ");
		writeQuotedType(writer, field.type);
		if (field.isMutable)
			writeStatic(writer, ", \"mut\"");
		writeChar(writer, ']');
	});
	writeStatic(writer, "])");
}

void writeUnion(Alloc)(ref Writer!Alloc writer, ref immutable StructDecl a, ref immutable StructBody.Union u) {
	writeStatic(writer, "\n\t\t+union(");
	writeQuotedSym(writer, a.name);
	writeTypeParams(writer, typeParams(a));
	writeStatic(writer, ", [");
	writeWithCommas!(Ptr!StructInst)(writer, u.members, (ref immutable Ptr!StructInst member) {
		writeQuotedType(writer, immutable Type(member));
	});
	writeStatic(writer, "])");
}

void writeSpec(Alloc)(ref Writer!Alloc writer, ref immutable SpecDecl a) {
	writeStatic(writer, "\n\t\t+spec(");
	writeQuotedSym(writer, a.name);
	writeTypeParams(writer, typeParams(a));
	writeStatic(writer, ", ");
	matchSpecBody!void(
		a.body_,
		(ref immutable SpecBody.Builtin) {
			writeStatic(writer, "\"builtin\"");
		},
		(ref immutable Sig[] sigs) {
			writeStatic(writer, "\"TODO:WRITE SIGS\"");
			cast(void) sigs;
		});
	writeStatic(writer, ")");
	writeDocComment(writer, a.docComment);
}

void writeFun(Alloc)(ref Writer!Alloc writer, ref immutable FunDecl a) {
	writeStatic(writer, "\n\t\t+function(");
	writeQuotedSym(writer, name(a));
	writeTypeParams(writer, typeParams(a));
	writeStatic(writer, ", ");
	writeQuotedType(writer, returnType(a));
	writeStatic(writer, ", [");
	writeWithCommas!(Param, Alloc)(writer, params(a), (ref immutable Param it) {
		writeChar(writer, '[');
		writeQuotedOptSym(writer, it.name);
		writeStatic(writer, ", ");
		writeQuotedType(writer, it.type);
		writeChar(writer, ']');
	});
	writeStatic(writer, "])");
	writeDocComment(writer, a.docComment);
}

void writeDocComment(Alloc)(ref Writer!Alloc writer, immutable SafeCStr comment) {
	immutable string str = strOfSafeCStr(comment);
	if (!empty(str)) {
		// Comment may contain newlines!
		eachLine(str, (immutable string line) {
			writeStatic(writer, "\n\t\t\t|");
			writeStr(writer, line);
		});
	}
}

void writeQuotedOptSym(Alloc)(ref Writer!Alloc writer, ref immutable Opt!Sym a) {
	if (has(a))
		writeQuotedSym(writer, force(a));
	else
		writeStatic(writer, "\"_\"");
}

void writeQuotedSym(Alloc)(ref Writer!Alloc writer, immutable Sym a) {
	writeChar(writer, '\"');
	writeSym(writer, a);
	writeChar(writer, '\"');
}

void writeQuotedType(Alloc)(ref Writer!Alloc writer, immutable Type a) {
	writeChar(writer, '\"');
	writeType(writer, a);
	writeChar(writer, '\"');
}

void writeType(Alloc)(ref Writer!Alloc writer, immutable Type a) {
	matchType!void(
		a,
		(ref immutable Type.Bogus) {
			unreachable!void();
		},
		(immutable Ptr!TypeParam it) {
			writeChar(writer, '?');
			writeSym(writer, it.name);
		},
		(immutable Ptr!StructInst it) {
			writeSym(writer, it.name);
			immutable Type[] typeArgs = typeArgs(it);
			if (!empty(typeArgs)) {
				if (size(typeArgs) == 1) {
					writeChar(writer, ' ');
					writeType(writer, only(typeArgs));
				} else {
					writeChar(writer, '<');
					writeWithCommas!Type(writer, typeArgs, (ref immutable Type t) {
						writeType(writer, t);
					});
					writeChar(writer, '>');
				}
			}
		});
}

void writeTypeParams(Alloc)(ref Writer!Alloc writer, immutable TypeParam[] typeParams) {
	writeStatic(writer, ", ");
	if (empty(typeParams))
		writeStatic(writer, "[]");
	else {
		writeChar(writer, '[');
		writeWithCommas!TypeParam(writer, typeParams, (ref immutable TypeParam it) {
			writeStatic(writer, "\"?");
			writeSym(writer, it.name);
			writeChar(writer, '"');
		});
		writeChar(writer, ']');
	}
}

void eachLine(
	immutable string a,
	scope void delegate(immutable string) @safe @nogc pure nothrow cb
) {
	immutable Opt!size_t index = findIndex!char(a, (ref immutable char c) => c == '\n');
	if (has(index)) {
		cb(a[0..force(index)]);
		eachLine(a[force(index)+1 .. $], cb);
	} else
		cb(a);
}
