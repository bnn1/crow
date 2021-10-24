module frontend.parse.parseExpr;

@safe @nogc pure nothrow:

import frontend.parse.ast :
	asCall,
	asIdentifier,
	BogusAst,
	CallAst,
	ExprAst,
	ExprAstKind,
	FunPtrAst,
	IdentifierAst,
	IfAst,
	IfOptionAst,
	InterpolatedAst,
	InterpolatedPart,
	isCall,
	isIdentifier,
	LambdaAst,
	LetAst,
	LiteralAst,
	MatchAst,
	NameAndRange,
	NameOrUnderscoreOrNone,
	ParenthesizedAst,
	SeqAst,
	ThenAst,
	ThenVoidAst,
	TypeAst;
import frontend.parse.lexer :
	addDiag,
	addDiagAtChar,
	addDiagOnReservedName,
	addDiagUnexpected,
	backUp,
	curPos,
	isReservedName,
	Lexer,
	lookaheadWillTakeEqualsOrThen,
	lookaheadWillTakeArrow,
	next,
	peekExact,
	range,
	Sign,
	skipUntilNewlineNoDiag,
	StringPart,
	takeIndentOrDiagTopLevel,
	takeIndentOrFailGeneric,
	takeName,
	takeNameAndRange,
	takeNameOrUnderscoreOrNone,
	takeNameRest,
	takeNewlineOrDedentAmount,
	takeNumberAfterSign,
	takeOrAddDiagExpected,
	takeStringPart,
	takeSymbolLiteral,
	tryTake;
import frontend.parse.parseType : parseType, tryParseTypeArgsBracketed;
import model.parseDiag : ParseDiag;
import util.alloc.alloc : Alloc;
import util.collection.arr : ArrWithSize, empty, emptyArr, emptyArrWithSize, only, toArr;
import util.collection.arrUtil : append, arrLiteral, arrWithSizeLiteral, prepend;
import util.collection.arrBuilder : add, ArrBuilder, finishArr;
import util.collection.arrWithSizeBuilder : add, ArrWithSizeBuilder, finishArrWithSize;
import util.collection.str : CStr;
import util.memory : allocate;
import util.opt : force, has, none, nonePtr, Opt, OptPtr, some, somePtr;
import util.ptr : Ptr;
import util.sourceRange : Pos, RangeWithinFile;
import util.sym :
	AllSymbols,
	getSymFromAlphaIdentifier,
	isAlphaIdentifierStart,
	isDigit,
	isSymOperator,
	Operator,
	operatorForSym,
	prependSet,
	shortSymAlphaLiteral,
	shortSymAlphaLiteralValue,
	Sym,
	symEq,
	symForOperator;
import util.util : max, todo, unreachable, verify;

immutable(ExprAst) parseFunExprBody(ref Alloc alloc, ref AllSymbols allSymbols, ref Lexer lexer) {
	immutable Pos start = curPos(lexer);
	if (takeIndentOrDiagTopLevel(alloc, lexer)) {
		immutable ExprAndDedent ed = parseStatementsAndExtraDedents(alloc, allSymbols, lexer, 1);
		verify(ed.dedents == 0); // Since we started at the root, can't dedent more
		return ed.expr;
	} else
		return bogusExpr(range(lexer, start));
}

private:

immutable(ExprAst) bogusExpr(immutable RangeWithinFile range) {
	return immutable ExprAst(range, immutable ExprAstKind(immutable BogusAst()));
}

immutable(Ptr!ExprAst) allocExpr(ref Alloc alloc, immutable ExprAst e) {
	return allocate(alloc, e);
}

struct AllowedBlock {
	@safe @nogc pure nothrow:

	struct NoBlock {}
	struct AllowBlock { immutable uint curIndent; }

	immutable this(immutable NoBlock a) { kind = Kind.noBlock; noBlock = a; }
	immutable this(immutable AllowBlock a) { kind = Kind.allowBlock; allowBlock = a; }

	private:
	enum Kind {
		noBlock,
		allowBlock,
	}
	immutable Kind kind;
	union {
		immutable NoBlock noBlock;
		immutable AllowBlock allowBlock;
	}
}

immutable(AllowedBlock) noBlock() {
	return immutable AllowedBlock(immutable AllowedBlock.NoBlock());
}

immutable(AllowedBlock) allowBlock(immutable uint curIndent) {
	return immutable AllowedBlock(immutable AllowedBlock.AllowBlock(curIndent));
}

immutable(bool) isAllowBlock(ref immutable AllowedBlock a) {
	return a.kind == AllowedBlock.Kind.allowBlock;
}

immutable(AllowedBlock.AllowBlock) asAllowBlock(ref immutable AllowedBlock a) {
	verify(isAllowBlock(a));
	return a.allowBlock;
}

struct AllowedCalls {
	immutable int minPrecedenceExclusive;
}

immutable(AllowedCalls) allowAllCalls() {
	return immutable AllowedCalls(int.min);
}

immutable(AllowedCalls) allowAllCallsExceptComma() {
	return immutable AllowedCalls(commaPrecedence);
}

struct ArgCtx {
	// Allow things like 'if', 'match', '\' that continue into an indented block.
	immutable AllowedBlock allowedBlock;
	// In `a b: c d e`, we parse `a b (c d e) and not `(a b c) d e`, since `: turns on `allowCall`.
	immutable AllowedCalls allowedCalls;
}

immutable(ArgCtx) requirePrecedenceGt(ref immutable ArgCtx a, immutable int precedence) {
	return immutable ArgCtx(
		a.allowedBlock,
		immutable AllowedCalls(max(a.allowedCalls.minPrecedenceExclusive, precedence)));
}

immutable(ArgCtx) requirePrecedenceGtComma(ref immutable ArgCtx a) {
	return requirePrecedenceGt(a, commaPrecedence);
}

struct ExprAndDedent {
	immutable ExprAst expr;
	immutable uint dedents;
}

// dedent=none means we didn't see a newline.
// dedent=0 means a newline was parsed and is on the same indent level.
struct ExprAndMaybeDedent {
	immutable ExprAst expr;
	immutable Opt!uint dedents;
}

struct OptNameOrDedent {
	@safe @nogc pure nothrow:

	struct Comma {}
	struct Dedent { immutable uint dedents; }
	struct None {}

	immutable this(immutable NameAndRange a) { kind = Kind.name; name = a; }
	immutable this(immutable Comma a) { kind = Kind.comma; comma = a; }
	immutable this(immutable Dedent a) { kind = Kind.dedent; dedent = a; }
	immutable this(immutable None a) { kind = Kind.none; none = a; }

	private:
	enum Kind {
		name,
		comma,
		dedent,
		none,
	}
	immutable Kind kind;
	union {
		immutable NameAndRange name;
		immutable Comma comma;
		immutable Dedent dedent;
		immutable None none;
	}
}

immutable(OptNameOrDedent) noNameOrDedent() {
	return immutable OptNameOrDedent(immutable OptNameOrDedent.None());
}

immutable(bool) isNone(ref immutable OptNameOrDedent a) {
	return a.kind == OptNameOrDedent.Kind.none;
}

T matchOptNameOrDedent(T)(
	ref immutable OptNameOrDedent a,
	scope T delegate(ref immutable OptNameOrDedent.None) @safe @nogc pure nothrow cbNone,
	scope T delegate(ref immutable OptNameOrDedent.Comma) @safe @nogc pure nothrow cbComma,
	scope T delegate(ref immutable NameAndRange) @safe @nogc pure nothrow cbName,
	scope T delegate(ref immutable OptNameOrDedent.Dedent) @safe @nogc pure nothrow cbDedent,
) {
	final switch (a.kind) {
		case OptNameOrDedent.Kind.none:
			return cbNone(a.none);
		case OptNameOrDedent.Kind.comma:
			return cbComma(a.comma);
		case OptNameOrDedent.Kind.name:
			return cbName(a.name);
		case OptNameOrDedent.Kind.dedent:
			return cbDedent(a.dedent);
	}
}

struct ExprAndMaybeNameOrDedent {
	immutable ExprAst expr;
	immutable OptNameOrDedent nameOrDedent;
}

immutable(ExprAst) assertNoNameOrDedent(immutable ExprAndMaybeNameOrDedent a) {
	verify(isNone(a.nameOrDedent));
	return a.expr;
}
immutable(ArrWithSize!ExprAst) assertNoNameOrDedent(immutable ArgsAndMaybeNameOrDedent a) {
	verify(isNone(a.nameOrDedent));
	return a.args;
}

struct OptExprAndDedent {
	immutable Opt!(Ptr!ExprAst) expr;
	immutable uint dedents;
}

struct ArgsAndMaybeNameOrDedent {
	immutable ArrWithSize!ExprAst args;
	immutable OptNameOrDedent nameOrDedent;
}

immutable(ExprAndMaybeDedent) noDedent(immutable ExprAst e) {
	return immutable ExprAndMaybeDedent(e, none!uint);
}

immutable(ExprAndMaybeDedent) toMaybeDedent(immutable ExprAndDedent a) {
	return immutable ExprAndMaybeDedent(a.expr, some(a.dedents));
}

immutable(ArrWithSize!ExprAst) parseSubscriptArgs(ref Alloc alloc, ref AllSymbols allSymbols, ref Lexer lexer) {
	if (tryTake(lexer, ']'))
		//TODO: syntax error
		return emptyArrWithSize!ExprAst;
	else {
		ArrWithSizeBuilder!ExprAst builder;
		immutable ArgCtx argCtx = immutable ArgCtx(noBlock(), allowAllCallsExceptComma());
		immutable ArgsAndMaybeNameOrDedent res = parseArgsRecur(alloc, allSymbols, lexer, argCtx, builder);
		if (!tryTake(lexer, ']'))
			addDiagAtChar(alloc, lexer, immutable ParseDiag(
				immutable ParseDiag.Expected(ParseDiag.Expected.Kind.closingBracket)));
		return assertNoNameOrDedent(res);
	}
}

immutable(ArgsAndMaybeNameOrDedent) parseArgsForOperator(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	ref immutable ArgCtx ctx,
) {
	if (!tryTake(lexer, ' '))
		return immutable ArgsAndMaybeNameOrDedent(emptyArrWithSize!ExprAst, noNameOrDedent());
	else {
		immutable ExprAndMaybeNameOrDedent ad = parseExprAndCalls(alloc, allSymbols, lexer, ctx);
		return immutable ArgsAndMaybeNameOrDedent(arrWithSizeLiteral!ExprAst(alloc, [ad.expr]), ad.nameOrDedent);
	}
}

immutable(ArgsAndMaybeNameOrDedent) parseArgs(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	immutable ArgCtx ctx,
) {
	if (tryTake(lexer, ' ')) {
		ArrWithSizeBuilder!ExprAst builder;
		return parseArgsRecur(alloc, allSymbols, lexer, ctx, builder);
	} else if (tryTake(lexer, ", "))
		return immutable ArgsAndMaybeNameOrDedent(
			emptyArrWithSize!ExprAst,
			immutable OptNameOrDedent(immutable OptNameOrDedent.Comma()));
	else
		return immutable ArgsAndMaybeNameOrDedent(emptyArrWithSize!ExprAst, noNameOrDedent());
}

immutable(ArgsAndMaybeNameOrDedent) parseArgsRecur(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	immutable ArgCtx ctx,
	ref ArrWithSizeBuilder!ExprAst args,
) {
	verify(ctx.allowedCalls.minPrecedenceExclusive >= commaPrecedence);
	immutable ExprAndMaybeNameOrDedent ad = parseExprAndCalls(alloc, allSymbols, lexer, ctx);
	add(alloc, args, ad.expr);
	immutable(ArgsAndMaybeNameOrDedent) finish() {
		return immutable ArgsAndMaybeNameOrDedent(finishArrWithSize(alloc, args), ad.nameOrDedent);
	}
	return matchOptNameOrDedent!(immutable ArgsAndMaybeNameOrDedent)(
		ad.nameOrDedent,
		(ref immutable OptNameOrDedent.None) =>
			finish(),
		(ref immutable OptNameOrDedent.Comma) =>
			parseArgsRecur(alloc, allSymbols, lexer, ctx, args),
		(ref immutable NameAndRange) =>
			finish(),
		(ref immutable OptNameOrDedent.Dedent) =>
			finish());
}

immutable(ExprAndDedent) parseMutEquals(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	immutable Pos start,
	ref immutable ExprAst before,
	immutable uint curIndent,
) {
	immutable ExprAndDedent initAndDedent = parseExprNoLet(alloc, allSymbols, lexer, curIndent);
	struct FromBefore {
		immutable Sym name;
		immutable ArrWithSize!ExprAst args;
		immutable ArrWithSize!TypeAst typeArgs;
		immutable CallAst.Style style;
	}
	immutable FromBefore fromBefore = () {
		if (isIdentifier(before.kind))
			return immutable FromBefore(
				asIdentifier(before.kind).name,
				emptyArrWithSize!ExprAst,
				emptyArrWithSize!TypeAst,
				CallAst.Style.setSingle);
		else if (isCall(before.kind)) {
			immutable CallAst beforeCall = asCall(before.kind);
			immutable CallAst.Style style = () {
				final switch (beforeCall.style) {
					case CallAst.Style.dot:
						return CallAst.Style.setDot;
					case CallAst.style.emptyParens:
						// `() := foo` is a syntax error
						return todo!(immutable CallAst.Style)("!");
					case CallAst.Style.single:
						return CallAst.Style.setSingle;
					case CallAst.Style.subscript:
						return CallAst.Style.setSubscript;
					case CallAst.Style.prefixOperator:
						if (symEq(beforeCall.funName.name, symForOperator(Operator.times)))
							return CallAst.Style.setDeref;
						else
							// This is `~x := foo` or `-x := foo`. Have a diagnostic for this.
							return todo!(immutable CallAst.Style)("!");
					case CallAst.Style.comma:
					case CallAst.Style.infix:
					case CallAst.Style.prefix:
					case CallAst.Style.setDeref:
					case CallAst.Style.setDot:
					case CallAst.Style.setSingle:
					case CallAst.Style.setSubscript:
						// We did parseExprBeforeCall before this, which can't parse any of these
						return unreachable!(immutable CallAst.Style)();
				}
			}();
			return immutable FromBefore(beforeCall.funNameName, beforeCall.args, beforeCall.typeArgs, style);
		} else {
			addDiag(alloc, lexer, range(lexer, start), immutable ParseDiag(immutable ParseDiag.CantPrecedeMutEquals()));
			return immutable FromBefore(
				shortSymAlphaLiteral("bogus"),
				emptyArrWithSize!ExprAst,
				emptyArrWithSize!TypeAst,
				CallAst.Style.setSingle);
		}
	}();
	// TODO: range is wrong..
	immutable ExprAst call = immutable ExprAst(
		range(lexer, start),
		immutable ExprAstKind(immutable CallAst(
			fromBefore.style,
			immutable NameAndRange(
				before.range.start,
				fromBefore.style == CallAst.Style.setDeref
					? shortSymAlphaLiteral("set-deref")
					: prependSet(allSymbols, fromBefore.name)),
			fromBefore.typeArgs,
			append(alloc, fromBefore.args, initAndDedent.expr))));
	return immutable ExprAndDedent(call, initAndDedent.dedents);
}

immutable(ExprAndDedent) mustParseNextLines(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	immutable Pos start,
	immutable uint dedentsBefore,
	immutable uint curIndent,
) {
	if (dedentsBefore != 0) {
		immutable RangeWithinFile range = range(lexer, start);
		addDiag(alloc, lexer, range, immutable ParseDiag(immutable ParseDiag.LetMustHaveThen()));
		return immutable ExprAndDedent(bogusExpr(range), dedentsBefore);
	} else
		return parseStatementsAndDedents(alloc, allSymbols, lexer, curIndent);
}

immutable(NameAndRange) asIdentifierOrDiagnostic(
	ref Alloc alloc,
	ref Lexer lexer,
	ref immutable ExprAst a,
) {
	if (isIdentifier(a.kind))
		return identifierAsNameAndRange(a);
	else {
		addDiag(alloc, lexer, a.range, immutable ParseDiag(immutable ParseDiag.CantPrecedeOptEquals()));
		return immutable NameAndRange(a.range.start, shortSymAlphaLiteral("a"));
	}
}

immutable(NameAndRange) identifierAsNameAndRange(ref immutable ExprAst a) {
	return immutable NameAndRange(a.range.start, asIdentifier(a.kind).name);
}

immutable(ExprAndMaybeNameOrDedent) parseCalls(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	immutable Pos start,
	ref immutable ExprAst lhs,
	immutable ArgCtx argCtx,
) {
	if (tryTake(lexer, ',')) {
		tryTake(lexer, ' ');
		if (canParseCommaExpr(argCtx))
			return parseCallsAfterComma(alloc, allSymbols, lexer, start, lhs, argCtx);
		else
			return immutable ExprAndMaybeNameOrDedent(
				lhs,
				immutable OptNameOrDedent(immutable OptNameOrDedent.Comma()));
	} else if (tryTake(lexer, ' ')) {
		immutable NameAndRange funName = takeNameAndRange(alloc, allSymbols, lexer);
		return parseCallsAfterName(alloc, allSymbols, lexer, start, lhs, funName, argCtx);
	} else
		return immutable ExprAndMaybeNameOrDedent(lhs, noNameOrDedent());
}

immutable(bool) canParseCommaExpr(ref immutable ArgCtx argCtx) {
	return commaPrecedence > argCtx.allowedCalls.minPrecedenceExclusive;
}

immutable(ExprAndMaybeNameOrDedent) parseCallsAfterComma(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	immutable Pos start,
	ref immutable ExprAst lhs,
	immutable ArgCtx argCtx,
) {
	ArrWithSizeBuilder!ExprAst builder;
	add(alloc, builder, lhs);
	immutable ArgsAndMaybeNameOrDedent args = peekExact(lexer, '\n') || peekExact(lexer, ')')
		? immutable ArgsAndMaybeNameOrDedent(
			finishArrWithSize(alloc, builder),
			immutable OptNameOrDedent(immutable OptNameOrDedent.None()))
		: parseArgsRecur(alloc, allSymbols, lexer, requirePrecedenceGtComma(argCtx), builder);
	immutable RangeWithinFile range = range(lexer, start);
	return immutable ExprAndMaybeNameOrDedent(
		immutable ExprAst(range, immutable ExprAstKind(
			immutable CallAst(
				CallAst.Style.comma,
				//TODO: range is wrong..
				immutable NameAndRange(range.start, shortSymAlphaLiteral("new")),
				emptyArrWithSize!TypeAst,
				args.args))),
		args.nameOrDedent);
}

immutable(ExprAndMaybeNameOrDedent) parseCallsAfterName(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	immutable Pos start,
	ref immutable ExprAst lhs,
	immutable NameAndRange funName,
	immutable ArgCtx argCtx,
) {
	immutable int precedence = symPrecedence(funName.name);
	if (precedence > argCtx.allowedCalls.minPrecedenceExclusive) {
		//TODO: don't do this for operators
		immutable ArrWithSize!TypeAst typeArgs = tryParseTypeArgsBracketed(alloc, allSymbols, lexer);
		immutable ArgCtx innerCtx = requirePrecedenceGt(argCtx, precedence);
		immutable ArgsAndMaybeNameOrDedent args = isSymOperator(funName.name)
			? parseArgsForOperator(alloc, allSymbols, lexer, innerCtx)
			: parseArgs(alloc, allSymbols, lexer, innerCtx);
		immutable ExprAstKind exprKind = immutable ExprAstKind(
			immutable CallAst(CallAst.Style.infix, funName, typeArgs, prepend!ExprAst(alloc, lhs, args.args)));
		immutable ExprAst expr = immutable ExprAst(range(lexer, start), exprKind);
		immutable ExprAndMaybeNameOrDedent stopHere = immutable ExprAndMaybeNameOrDedent(expr, args.nameOrDedent);
		return matchOptNameOrDedent(
			args.nameOrDedent,
			(ref immutable OptNameOrDedent.None) =>
				stopHere,
			(ref immutable OptNameOrDedent.Comma) =>
				canParseCommaExpr(argCtx)
					? parseCallsAfterComma(alloc, allSymbols, lexer, start, expr, argCtx)
					: stopHere,
			(ref immutable NameAndRange name) =>
				parseCallsAfterName(alloc, allSymbols, lexer, start, expr, name, argCtx),
			(ref immutable OptNameOrDedent.Dedent) =>
				stopHere);
	} else
		return immutable ExprAndMaybeNameOrDedent(lhs, immutable OptNameOrDedent(funName));
}

immutable(int) symPrecedence(immutable Sym a) {
	immutable Opt!Operator operator = operatorForSym(a);
	return has(operator) ? operatorPrecedence(force(operator)) : 0;
}

// This is for the , in `1, 2`, not the comma between args
immutable int commaPrecedence = -4;

immutable(int) operatorPrecedence(immutable Operator a) {
	final switch (a) {
		case Operator.concatEquals:
			return -3;
		case Operator.or2:
			return -2;
		case Operator.and2:
			return -1;
		case Operator.equal:
		case Operator.notEqual:
		case Operator.less:
		case Operator.lessOrEqual:
		case Operator.greater:
		case Operator.greaterOrEqual:
		case Operator.compare:
		case Operator.arrow:
		case Operator.range:
		case Operator.tilde:
			return 1;
		case Operator.or1:
			return 2;
		case Operator.xor1:
			return 3;
		case Operator.and1:
			return 4;
		case Operator.shiftLeft:
		case Operator.shiftRight:
			return 5;
		case Operator.plus:
		case Operator.minus:
			return 6;
		case Operator.times:
		case Operator.divide:
			return 7;
		case Operator.exponent:
			return 8;
		case Operator.not:
			// prefix only
			return unreachable!int();
	}
}

immutable(ExprAndMaybeNameOrDedent) parseCallsAfterSimpleExpr(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	immutable Pos start,
	ref immutable ExprAst lhs,
	immutable ArgCtx argCtx,
) {
	immutable ExprAstKind kind = lhs.kind;
	if (((isCall(kind) && asCall(kind).style == CallAst.Style.single) || isIdentifier(kind))
		&& tryTake(lexer, ':')) {
		struct NameAndTypeArgs {
			immutable NameAndRange name;
			immutable ArrWithSize!TypeAst typeArgs;
		}
		immutable NameAndTypeArgs nameAndTypeArgs = () {
			if (isCall(kind))
				return immutable NameAndTypeArgs(asCall(kind).funName, asCall(kind).typeArgs);
			else
				return immutable NameAndTypeArgs(
					immutable NameAndRange(lhs.range.start, asIdentifier(kind).name),
					emptyArrWithSize!TypeAst);
		}();
		immutable ArgsAndMaybeNameOrDedent ad = parseArgs(alloc, allSymbols, lexer, requirePrecedenceGtComma(argCtx));
		immutable CallAst call = immutable CallAst(
			CallAst.Style.prefix,
			nameAndTypeArgs.name,
			nameAndTypeArgs.typeArgs,
			ad.args);
		return immutable ExprAndMaybeNameOrDedent(
			immutable ExprAst(range(lexer, start), immutable ExprAstKind(call)),
			ad.nameOrDedent);
	} else
		return parseCalls(alloc, allSymbols, lexer, start, lhs, argCtx);
}

immutable(OptNameOrDedent) nameOrDedentFromOptDedents(immutable Opt!uint dedents) {
	return has(dedents)
		? immutable OptNameOrDedent(immutable OptNameOrDedent.Dedent(force(dedents)))
		: noNameOrDedent();
}

immutable(ExprAst) tryParseDotsAndSubscripts(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	ref immutable ExprAst initial
) {
	immutable Pos start = curPos(lexer);
	if (tryTake(lexer, '.')) {
		immutable NameAndRange name = takeNameAndRange(alloc, allSymbols, lexer);
		immutable ArrWithSize!TypeAst typeArgs = tryParseTypeArgsBracketed(alloc, allSymbols, lexer);
		immutable CallAst call = immutable CallAst(
			CallAst.Style.dot, name, typeArgs, arrWithSizeLiteral!ExprAst(alloc, [initial]));
		immutable ExprAst expr = immutable ExprAst(range(lexer, start), immutable ExprAstKind(call));
		return tryParseDotsAndSubscripts(alloc, allSymbols, lexer, expr);
	} else if (tryTake(lexer, '[')) {
		immutable ArrWithSize!ExprAst args = parseSubscriptArgs(alloc, allSymbols, lexer);
		immutable CallAst call = immutable CallAst(
			//TODO: the range is wrong..
			CallAst.Style.subscript,
			immutable NameAndRange(start, shortSymAlphaLiteral("subscript")),
			emptyArrWithSize!TypeAst,
			prepend(alloc, initial, args));
		immutable ExprAst expr = immutable ExprAst(range(lexer, start), immutable ExprAstKind(call));
		return tryParseDotsAndSubscripts(alloc, allSymbols, lexer, expr);
	} else
		return initial;
}

immutable(ExprAndDedent) parseMatch(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	immutable Pos start,
	immutable uint curIndent,
) {
	immutable Ptr!ExprAst matched = tryTake(lexer, ' ')
		? allocate(alloc, parseExprNoBlock(alloc, allSymbols, lexer))
		: allocate(alloc, immutable ExprAst(range(lexer, start), immutable ExprAstKind(immutable BogusAst())));
	immutable uint dedentsAfterMatched = takeNewlineOrDedentAmount(alloc, lexer, curIndent);
	ArrBuilder!(MatchAst.CaseAst) cases;
	immutable uint dedents = dedentsAfterMatched != 0
		? dedentsAfterMatched
		: parseMatchCases(alloc, allSymbols, lexer, cases, curIndent);
	return immutable ExprAndDedent(
		immutable ExprAst(
			range(lexer, start),
			immutable ExprAstKind(immutable MatchAst(matched, finishArr(alloc, cases)))),
		dedents);
}

immutable(uint) parseMatchCases(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	ref ArrBuilder!(MatchAst.CaseAst) cases,
	immutable uint curIndent,
) {
	immutable Pos startCase = curPos(lexer);
	if (tryTake(lexer, "as ")) {
		immutable Sym memberName = takeName(alloc, allSymbols, lexer);
		immutable NameOrUnderscoreOrNone localName = takeNameOrUnderscoreOrNone(alloc, allSymbols, lexer);
		immutable ExprAndDedent ed = takeIndentOrFail_ExprAndDedent(alloc, allSymbols, lexer, curIndent, () =>
			parseStatementsAndExtraDedents(alloc, allSymbols, lexer, curIndent + 1));
		add(alloc, cases, immutable MatchAst.CaseAst(
			range(lexer, startCase),
			memberName,
			localName,
			allocExpr(alloc, ed.expr)));
		return ed.dedents == 0 ? parseMatchCases(alloc, allSymbols, lexer, cases, curIndent) : ed.dedents;
	} else
		return 0;
}

immutable(ExprAndDedent) parseIf(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	immutable Pos start,
	immutable uint curIndent,
) {
	if (!tryTake(lexer, ' '))
		return todo!(immutable ExprAndDedent)("!");
	return parseIfRecur(alloc, allSymbols, lexer, start, curIndent);
}

immutable(OptExprAndDedent) toOptExprAndDedent(ref Alloc alloc, immutable ExprAndDedent a) {
	return immutable OptExprAndDedent(some(allocate(alloc, a.expr)), a.dedents);
}

immutable(ExprAndDedent) parseIfRecur(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	immutable Pos start,
	immutable uint curIndent,
) {
	immutable ExprAndMaybeDedent beforeCallAndDedent = parseExprBeforeCall(alloc, allSymbols, lexer, noBlock());
	assert(!has(beforeCallAndDedent.dedents));
	immutable ExprAst beforeCall = beforeCallAndDedent.expr;
	immutable bool isOption = tryTake(lexer, " ?= ");
	immutable ExprAst optionOrCondition = isOption
		? parseExprNoBlock(alloc, allSymbols, lexer)
		: assertNoNameOrDedent(parseCallsAfterSimpleExpr(
			alloc, allSymbols, lexer, start, beforeCall, immutable ArgCtx(noBlock(), allowAllCalls())));
	immutable ExprAndDedent thenAndDedent = takeIndentOrFail_ExprAndDedent(alloc, allSymbols, lexer, curIndent, () =>
		parseStatementsAndExtraDedents(alloc, allSymbols, lexer, curIndent + 1));
	immutable ExprAst then = thenAndDedent.expr;
	immutable Pos elifStart = curPos(lexer);
	immutable OptExprAndDedent else_ = thenAndDedent.dedents != 0
		? immutable OptExprAndDedent(none!(Ptr!ExprAst), thenAndDedent.dedents)
		: tryTake(lexer, "elif ")
		? toOptExprAndDedent(alloc, parseIfRecur(alloc, allSymbols, lexer, elifStart, curIndent))
		: tryTake(lexer, "else")
		? toOptExprAndDedent(alloc, takeIndentOrFail_ExprAndDedent(alloc, allSymbols, lexer, curIndent, () =>
			parseStatementsAndExtraDedents(alloc, allSymbols, lexer, curIndent + 1)))
		: immutable OptExprAndDedent(none!(Ptr!ExprAst), 0);

	immutable ExprAstKind kind = isOption
		? immutable ExprAstKind(allocate(alloc, immutable IfOptionAst(
			asIdentifierOrDiagnostic(alloc, lexer, beforeCall),
			optionOrCondition,
			then,
			has(else_.expr) ? some(force(else_.expr).deref()) : none!ExprAst)))
		: immutable ExprAstKind(immutable IfAst(
			allocate(alloc, optionOrCondition),
			allocate(alloc, then),
			else_.expr));
	return immutable ExprAndDedent(immutable ExprAst(range(lexer, start), kind), else_.dedents);
}

immutable(ExprAndDedent) takeIndentOrFail_ExprAndDedent(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	immutable uint curIndent,
	scope immutable(ExprAndDedent) delegate() @safe @nogc pure nothrow cbIndent,
) {
	return takeIndentOrFailGeneric!ExprAndDedent(
		alloc,
		lexer,
		curIndent,
		cbIndent,
		(immutable RangeWithinFile range, immutable uint nDedents) =>
			immutable ExprAndDedent(bogusExpr(range), nDedents));
}

immutable(ExprAndMaybeDedent) parseLambdaWithParenthesizedParameters(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	immutable Pos start,
	immutable AllowedBlock allowedBlock,
) {
	immutable LambdaAst.Param[] parameters = parseParenthesizedLambdaParameters(alloc, allSymbols, lexer);
	if (!tryTake(lexer, " =>"))
		addDiagAtChar(alloc, lexer, immutable ParseDiag(
			immutable ParseDiag.Expected(ParseDiag.Expected.Kind.lambdaArrow)));
	return parseLambdaAfterArrow(alloc, allSymbols, lexer, start, allowedBlock, parameters);
}

immutable(LambdaAst.Param[]) parseParenthesizedLambdaParameters(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
) {
	if (tryTake(lexer, ')'))
		return emptyArr!(LambdaAst.Param);
	else {
		ArrBuilder!(LambdaAst.Param) parameters;
		return parseParenthesizedLambdaParametersRecur(alloc, allSymbols, lexer, parameters);
	}
}

immutable(LambdaAst.Param[]) parseParenthesizedLambdaParametersRecur(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	ref ArrBuilder!(LambdaAst.Param) parameters,
) {
	immutable Pos start = curPos(lexer);
	immutable Sym name = takeName(alloc, allSymbols, lexer);
	add(alloc, parameters, immutable LambdaAst.Param(start, name));
	if (tryTake(lexer, ", "))
		return parseParenthesizedLambdaParametersRecur(alloc, allSymbols, lexer, parameters);
	else {
		if (!tryTake(lexer, ')'))
			addDiagAtChar(alloc, lexer, immutable ParseDiag(
				immutable ParseDiag.Expected(ParseDiag.Expected.Kind.closingParen)));
		return finishArr(alloc, parameters);
	}
}

immutable(ExprAndMaybeDedent) parseLambdaAfterArrow(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	immutable Pos start,
	immutable AllowedBlock allowedBlock,
	immutable LambdaAst.Param[] parameters,
) {
	immutable bool inLine = tryTake(lexer, ' ');
	immutable ExprAndMaybeDedent body_ = () {
		if (isAllowBlock(allowedBlock)) {
			immutable uint curIndent = asAllowBlock(allowedBlock).curIndent;
			return inLine
				? toMaybeDedent(parseExprNoLet(alloc, allSymbols, lexer, curIndent))
				: toMaybeDedent(takeIndentOrFail_ExprAndDedent(alloc, allSymbols, lexer, curIndent, () =>
					parseStatementsAndExtraDedents(alloc, allSymbols, lexer, curIndent + 1)));
		} else
			return inLine
				? noDedent(parseExprNoBlock(alloc, allSymbols, lexer))
				: exprBlockNotAllowed(alloc, lexer, start, ParseDiag.MatchWhenOrLambdaNeedsBlockCtx.Kind.lambda);
	}();
	immutable LambdaAst lambda = immutable LambdaAst(parameters, allocExpr(alloc, body_.expr));
	return immutable ExprAndMaybeDedent(
		immutable ExprAst(range(lexer, start), immutable ExprAstKind(lambda)),
		body_.dedents);
}

immutable(ExprAndMaybeDedent) skipRestOfLineAndReturnBogusNoDiag(
	ref Lexer lexer,
	immutable Pos start,
) {
	skipUntilNewlineNoDiag(lexer);
	return noDedent(bogusExpr(range(lexer, start)));
}

immutable(ExprAndMaybeDedent) skipRestOfLineAndReturnBogus(
	ref Alloc alloc,
	ref Lexer lexer,
	immutable Pos start,
	immutable ParseDiag diag,
) {
	addDiag(alloc, lexer, range(lexer, start), diag);
	return skipRestOfLineAndReturnBogusNoDiag(lexer, start);
}

immutable(ExprAndMaybeDedent) exprBlockNotAllowed(
	ref Alloc alloc,
	ref Lexer lexer,
	immutable Pos start,
	immutable ParseDiag.MatchWhenOrLambdaNeedsBlockCtx.Kind kind,
) {
	return skipRestOfLineAndReturnBogus(
		alloc,
		lexer,
		start,
		immutable ParseDiag(immutable ParseDiag.MatchWhenOrLambdaNeedsBlockCtx(kind)));
}

immutable(ExprAndMaybeDedent) parseExprBeforeCall(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	immutable AllowedBlock allowedBlock,
) {
	immutable Pos start = curPos(lexer);

	immutable CStr begin = lexer.ptr;
	immutable char c = next(lexer);
	switch (c) {
		case '(':
			if (lookaheadWillTakeArrow(lexer))
				return parseLambdaWithParenthesizedParameters(alloc, allSymbols, lexer, start, allowedBlock);
			else if (tryTake(lexer, ')')) {
				immutable ExprAst expr = immutable ExprAst(
					range(lexer, start),
					immutable ExprAstKind(immutable CallAst(
						CallAst.Style.emptyParens,
						//TODO: range is wrong..
						immutable NameAndRange(start, shortSymAlphaLiteral("new")),
						emptyArrWithSize!TypeAst,
						emptyArrWithSize!ExprAst)));
				return noDedent(tryParseDotsAndSubscripts(alloc, allSymbols, lexer, expr));
			} else {
				immutable ExprAst inner = parseExprNoBlock(alloc, allSymbols, lexer);
				takeOrAddDiagExpected(alloc, lexer, ')', ParseDiag.Expected.Kind.closingParen);
				immutable ExprAst expr = immutable ExprAst(
					range(lexer, start),
					immutable ExprAstKind(immutable ParenthesizedAst(allocate(alloc, inner))));
				return noDedent(tryParseDotsAndSubscripts(alloc, allSymbols, lexer, expr));
			}
		case '&':
			immutable Sym name = takeName(alloc, allSymbols, lexer);
			return noDedent(immutable ExprAst(
				range(lexer, start),
				immutable ExprAstKind(immutable FunPtrAst(name))));
		case '"': {
			immutable StringPart part = takeStringPart(alloc, lexer, '"');
			final switch (part.after) {
				case StringPart.After.quote:
					return handleLiteral(alloc, allSymbols, lexer, start, immutable LiteralAst(part.text));
				case StringPart.After.lbrace:
					immutable ExprAst interpolated = takeInterpolated(alloc, allSymbols, lexer, start, part.text);
					return noDedent(tryParseDotsAndSubscripts(alloc, allSymbols, lexer, interpolated));
			}
		}
		case '\'':
			immutable Sym sym = takeSymbolLiteral(alloc, allSymbols, lexer);
			immutable ExprAst expr = immutable ExprAst(
				range(lexer, start),
				immutable ExprAstKind(immutable LiteralAst(sym)));
			return noDedent(tryParseDotsAndSubscripts(alloc, allSymbols, lexer, expr));
		case '+':
			return isDigit(*lexer.ptr)
				? handleLiteral(alloc, allSymbols, lexer, start, takeNumberAfterSign(lexer, some(Sign.plus)))
				: handleUnexpectedChar(alloc, lexer, start);
		case '-':
			return isDigit(*lexer.ptr)
				? handleLiteral(alloc, allSymbols, lexer, start, takeNumberAfterSign(lexer, some(Sign.minus)))
				: handlePrefixOperator(alloc, allSymbols, lexer, allowedBlock, start, Operator.minus);
		case '!':
			return handlePrefixOperator(alloc, allSymbols, lexer, allowedBlock, start, Operator.not);
		case '~':
			return handlePrefixOperator(alloc, allSymbols, lexer, allowedBlock, start, Operator.tilde);
		case '*':
			return handlePrefixOperator(alloc, allSymbols, lexer, allowedBlock, start, Operator.times);
		default:
			if (isAlphaIdentifierStart(c)) {
				immutable string nameStr = takeNameRest(lexer, begin);
				immutable Sym name = getSymFromAlphaIdentifier(allSymbols, nameStr);
				if (isReservedName(lexer, name))
					switch (name.value) {
						case shortSymAlphaLiteralValue("if"):
							return isAllowBlock(allowedBlock)
								? toMaybeDedent(
									parseIf(alloc, allSymbols, lexer, start, asAllowBlock(allowedBlock).curIndent))
								: exprBlockNotAllowed(
									alloc, lexer, start, ParseDiag.MatchWhenOrLambdaNeedsBlockCtx.Kind.if_);
						case shortSymAlphaLiteralValue("match"):
							return isAllowBlock(allowedBlock)
								? toMaybeDedent(
									parseMatch(alloc, allSymbols, lexer, start, asAllowBlock(allowedBlock).curIndent))
								: exprBlockNotAllowed(
									alloc, lexer, start, ParseDiag.MatchWhenOrLambdaNeedsBlockCtx.Kind.match);
						default:
							addDiagOnReservedName(alloc, lexer, immutable NameAndRange(start, name));
							return skipRestOfLineAndReturnBogusNoDiag(lexer, start);
					}
				else if (tryTake(lexer, " =>"))
					return parseLambdaAfterArrow(
						alloc,
						allSymbols,
						lexer,
						start,
						allowedBlock,
						arrLiteral!(LambdaAst.Param)(alloc, [immutable LambdaAst.Param(start, name)]));
				else
					return handleName(alloc, allSymbols, lexer, start, immutable NameAndRange(start, name));
			} else if (isDigit(c)) {
				backUp(lexer);
				return handleLiteral(alloc, allSymbols, lexer, start, takeNumberAfterSign(lexer, none!Sign));
			} else
				return handleUnexpectedChar(alloc, lexer, start);
	}
}

immutable(ExprAndMaybeDedent) handlePrefixOperator(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	immutable AllowedBlock allowedBlock,
	immutable Pos start,
	immutable Operator operator,
) {
	immutable ExprAndMaybeDedent arg = parseExprBeforeCall(alloc, allSymbols, lexer, allowedBlock);
	immutable ExprAst expr = immutable ExprAst(range(lexer, start), immutable ExprAstKind(
		immutable CallAst(
			CallAst.Style.prefixOperator,
			immutable NameAndRange(start, symForOperator(operator)),
			emptyArrWithSize!TypeAst,
			arrWithSizeLiteral!ExprAst(alloc, [arg.expr]))));
	return immutable ExprAndMaybeDedent(expr, arg.dedents);
}

immutable(ExprAndMaybeDedent) handleUnexpectedChar(
	ref Alloc alloc,
	ref Lexer lexer,
	immutable Pos start,
) {
	backUp(lexer);
	addDiagUnexpected(alloc, lexer);
	return skipRestOfLineAndReturnBogusNoDiag(lexer, start);
}

immutable(ExprAndMaybeDedent) handleLiteral(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	immutable Pos start,
	immutable LiteralAst literal,
) {
	immutable ExprAst expr = immutable ExprAst(range(lexer, start), immutable ExprAstKind(literal));
	return noDedent(tryParseDotsAndSubscripts(alloc, allSymbols, lexer, expr));
}

immutable(ExprAndMaybeDedent) handleName(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	immutable Pos start,
	immutable NameAndRange name,
) {
	immutable ArrWithSize!TypeAst typeArgs = tryParseTypeArgsBracketed(alloc, allSymbols, lexer);
	if (!empty(toArr(typeArgs))) {
		return noDedent(immutable ExprAst(
			range(lexer, start),
			immutable ExprAstKind(
				immutable CallAst(CallAst.Style.single, name, typeArgs, emptyArrWithSize!ExprAst))));
	} else {
		immutable ExprAst expr = immutable ExprAst(
			range(lexer, start),
			immutable ExprAstKind(immutable IdentifierAst(name.name)));
		return noDedent(tryParseDotsAndSubscripts(alloc, allSymbols, lexer, expr));
	}
}

immutable(ExprAst) takeInterpolated(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	immutable Pos start,
	immutable string firstText,
) {
	ArrBuilder!InterpolatedPart parts;
	if (!empty(firstText))
		add(alloc, parts, immutable InterpolatedPart(firstText));
	return takeInterpolatedRecur(alloc, allSymbols, lexer, start, parts);
}

immutable(ExprAst) takeInterpolatedRecur(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	immutable Pos start,
	ref ArrBuilder!InterpolatedPart parts,
) {
	immutable ExprAst e = parseExprNoBlock(alloc, allSymbols, lexer);
	add(alloc, parts, immutable InterpolatedPart(e));
	if (!tryTake(lexer, '}'))
		todo!void("!");
	immutable StringPart part = takeStringPart(alloc, lexer, '"');
	if (!empty(part.text))
		add(alloc, parts, immutable InterpolatedPart(part.text));
	final switch (part.after) {
		case StringPart.After.quote:
			return immutable ExprAst(
				range(lexer, start),
				immutable ExprAstKind(immutable InterpolatedAst(finishArr(alloc, parts))));
		case StringPart.After.lbrace:
			return takeInterpolatedRecur(alloc, allSymbols, lexer, start, parts);
	}
}

immutable(ExprAndMaybeDedent) assertNoNameAfter(immutable ExprAndMaybeNameOrDedent a) {
	return immutable ExprAndMaybeDedent(a.expr, assertNoName(a.nameOrDedent));
}

immutable(Opt!uint) assertNoName(immutable OptNameOrDedent a) {
	return matchOptNameOrDedent!(immutable Opt!uint)(
		a,
		(ref immutable OptNameOrDedent.None) =>
			none!uint,
		(ref immutable OptNameOrDedent.Comma) =>
			unreachable!(immutable Opt!uint),
		(ref immutable NameAndRange) =>
			// We allowed all calls, so should be no dangling names
			unreachable!(immutable Opt!uint),
		(ref immutable OptNameOrDedent.Dedent it) =>
			some(it.dedents));
}

immutable(ExprAst) parseExprNoBlock(ref Alloc alloc, ref AllSymbols allSymbols, ref Lexer lexer) {
	immutable ExprAndMaybeDedent ed = parseExprAndAllCalls(alloc, allSymbols, lexer, noBlock());
	verify(!has(ed.dedents));
	return ed.expr;
}

immutable(ExprAndMaybeDedent) parseExprAndAllCalls(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	immutable AllowedBlock allowedBlock,
) {
	immutable ArgCtx argCtx = immutable ArgCtx(allowedBlock, allowAllCalls());
	return assertNoNameAfter(parseExprAndCalls(alloc, allSymbols, lexer, argCtx));
}

immutable(ExprAndMaybeNameOrDedent) parseExprAndCalls(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	ref immutable ArgCtx argCtx,
) {
	immutable Pos start = curPos(lexer);
	immutable ExprAndMaybeDedent ed = parseExprBeforeCall(alloc, allSymbols, lexer, argCtx.allowedBlock);
	return has(ed.dedents)
		? immutable ExprAndMaybeNameOrDedent(ed.expr, nameOrDedentFromOptDedents(ed.dedents))
		: parseCallsAfterSimpleExpr(alloc, allSymbols, lexer, start, ed.expr, argCtx);
}

immutable(ExprAndDedent) parseExprNoLet(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	immutable uint curIndent,
) {
	return addDedent(alloc, lexer, parseExprAndAllCalls(alloc, allSymbols, lexer, allowBlock(curIndent)), curIndent);
}

immutable(ExprAndDedent) parseSingleStatementLine(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	immutable uint curIndent,
) {
	immutable Pos start = curPos(lexer);
	if (lookaheadWillTakeEqualsOrThen(lexer))
		return parseEqualsOrThen(alloc, allSymbols, lexer, curIndent);
	else if (tryTake(lexer, "<- ")) {
		immutable ExprAndDedent init = parseExprNoLet(alloc, allSymbols, lexer, curIndent);
		immutable ExprAndDedent then = mustParseNextLines(alloc, allSymbols, lexer, start, init.dedents, curIndent);
		return immutable ExprAndDedent(
			immutable ExprAst(
				range(lexer, start),
				immutable ExprAstKind(immutable ThenVoidAst(allocate(alloc, init.expr), allocate(alloc, then.expr)))),
			then.dedents);
	} else {
		immutable ExprAndMaybeDedent expr = parseExprBeforeCall(alloc, allSymbols, lexer, allowBlock(curIndent));
		if (!has(expr.dedents) && tryTake(lexer, " := "))
			return parseMutEquals(alloc, allSymbols, lexer, start, expr.expr, curIndent);
		else {
			immutable ExprAndMaybeDedent fullExpr = has(expr.dedents)
				? expr
				: assertNoNameAfter(parseCallsAfterSimpleExpr(
					alloc,
					allSymbols,
					lexer,
					start,
					expr.expr,
					immutable ArgCtx(allowBlock(curIndent), allowAllCalls())));
			return addDedent(alloc, lexer, fullExpr, curIndent);
		}
	}
}

immutable(ExprAndDedent) parseEqualsOrThen(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	immutable uint curIndent,
) {
	immutable Pos start = curPos(lexer);
	immutable NameAndRange name = takeNameAndRange(alloc, allSymbols, lexer);
	immutable TypeAndEqualsOrThen te = parseTypeAndEqualsOrThen(alloc, allSymbols, lexer);
	immutable ExprAndDedent initAndDedent = parseExprNoLet(alloc, allSymbols, lexer, curIndent);
	immutable ExprAndDedent thenAndDedent =
		mustParseNextLines(alloc, allSymbols, lexer, start, initAndDedent.dedents, curIndent);
	immutable ExprAstKind exprKind =
		letOrThen(alloc, name, te.type, te.equalsOrThen, initAndDedent.expr, thenAndDedent.expr);
	return immutable ExprAndDedent(immutable ExprAst(range(lexer, start), exprKind), thenAndDedent.dedents);
}

immutable(ExprAstKind) letOrThen(
	ref Alloc alloc,
	immutable NameAndRange name,
	immutable OptPtr!TypeAst type,
	immutable EqualsOrThen kind,
	immutable ExprAst init,
	immutable ExprAst then,
) {
	immutable Ptr!ExprAst ptrInit = allocate(alloc, init);
	immutable Ptr!ExprAst ptrThen = allocate(alloc, then);
	final switch (kind) {
		case EqualsOrThen.equals:
			return immutable ExprAstKind(immutable LetAst(name.name, type, ptrInit, ptrThen));
		case EqualsOrThen.then:
			// TODO: use the type
			return immutable ExprAstKind(immutable ThenAst(name, ptrInit, ptrThen));
	}
}

enum EqualsOrThen { equals, then }
struct TypeAndEqualsOrThen {
	immutable OptPtr!TypeAst type;
	immutable EqualsOrThen equalsOrThen;
}
immutable(TypeAndEqualsOrThen) parseTypeAndEqualsOrThen(ref Alloc alloc, ref AllSymbols allSymbols, ref Lexer lexer) {
	immutable Opt!EqualsOrThen res = tryTakeEqualsOrThen(lexer);
	if (has(res))
		return immutable TypeAndEqualsOrThen(nonePtr!TypeAst, force(res));
	else {
		takeOrAddDiagExpected(alloc, lexer, ' ', ParseDiag.Expected.Kind.space);
		immutable TypeAst type = parseType(alloc, allSymbols, lexer);
		immutable Opt!EqualsOrThen optEqualsOrThen = tryTakeEqualsOrThen(lexer);
		immutable EqualsOrThen equalsOrThen = () {
			if (has(optEqualsOrThen))
				return force(optEqualsOrThen);
			else {
				addDiagAtChar(alloc, lexer, immutable ParseDiag(
					immutable ParseDiag.Expected(ParseDiag.Expected.Kind.spaceEqualsSpace)));
				return EqualsOrThen.equals;
			}
		}();
		return immutable TypeAndEqualsOrThen(somePtr(allocate(alloc, type)), equalsOrThen);
	}
}

immutable(Opt!EqualsOrThen) tryTakeEqualsOrThen(ref Lexer lexer) {
	return tryTake(lexer, " = ")
		? some(EqualsOrThen.equals)
		: tryTake(lexer, " <- ")
		? some(EqualsOrThen.then)
		: none!EqualsOrThen;
}

immutable(ExprAndDedent) addDedent(
	ref Alloc alloc,
	ref Lexer lexer,
	immutable ExprAndMaybeDedent e,
	immutable uint curIndent,
) {
	return immutable ExprAndDedent(
		e.expr,
		has(e.dedents) ? force(e.dedents) : takeNewlineOrDedentAmount(alloc, lexer, curIndent));
}


immutable(ExprAndDedent) parseStatementsAndDedents(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	immutable uint curIndent,
) {
	immutable ExprAndDedent res = parseStatementsAndExtraDedents(alloc, allSymbols, lexer, curIndent);
	// Since we don't always expect a dedent here,
	// the dedent isn't *extra*, so increment to get the correct number of dedents.
	return immutable ExprAndDedent(res.expr, res.dedents + 1);
}

// Return value is number of dedents - 1; the number of *extra* dedents
immutable(ExprAndDedent) parseStatementsAndExtraDedents(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	immutable uint curIndent,
) {
	immutable Pos start = curPos(lexer);
	immutable ExprAndDedent ed = parseSingleStatementLine(alloc, allSymbols, lexer, curIndent);
	return parseStatementsAndExtraDedentsRecur(alloc, allSymbols, lexer, start, ed.expr, curIndent, ed.dedents);
}

immutable(ExprAndDedent) parseStatementsAndExtraDedentsRecur(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
	immutable Pos start,
	immutable ExprAst expr,
	immutable uint curIndent,
	immutable uint dedents,
) {
	if (dedents == 0) {
		immutable ExprAndDedent ed = parseSingleStatementLine(alloc, allSymbols, lexer, curIndent);
		immutable SeqAst seq = immutable SeqAst(allocExpr(alloc, expr), allocExpr(alloc, ed.expr));
		return parseStatementsAndExtraDedentsRecur(
			alloc,
			allSymbols,
			lexer,
			start,
			immutable ExprAst(range(lexer, start), immutable ExprAstKind(seq)),
			curIndent,
			ed.dedents);
	} else
		return immutable ExprAndDedent(expr, dedents - 1);
}
