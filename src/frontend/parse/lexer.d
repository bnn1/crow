module frontend.parse.lexer;

@safe @nogc pure nothrow:

import frontend.parse.ast :
	LiteralAst,
	LiteralIntOrNat,
	matchLiteralAst,
	NameAndRange,
	NameOrUnderscoreOrNone,
	rangeOfNameAndRange;
import model.parseDiag : ParseDiag, ParseDiagnostic;
import util.alloc.alloc : Alloc, allocateBytes;
import util.cell : Cell, cellGet, cellSet;
import util.collection.arr : arrOfRange, at, begin, empty, first, last, size;
import util.collection.arrBuilder : add, ArrBuilder, finishArr;
import util.collection.arrUtil : cat, rtail;
import util.collection.str :
	copyStr,
	copyToSafeCStr,
	CStr,
	emptySafeCStr,
	NulTerminatedStr,
	SafeCStr,
	strOfNulTerminatedStr;
import util.opt : force, has, none, Opt, optOr, some;
import util.ptr : Ptr;
import util.sourceRange : Pos, RangeWithinFile;
import util.sym :
	AllSymbols,
	getSymFromAlphaIdentifier,
	getSymFromOperator,
	isAlphaIdentifierStart,
	isAlphaIdentifierContinue,
	isDigit,
	Operator,
	shortSymAlphaLiteral,
	shortSymAlphaLiteralValue,
	Sym,
	symForOperator,
	symOfStr;
import util.types : safeI32FromU32, safeSizeTToU32;
import util.util : drop, todo, unreachable, verify;

private enum IndentKind {
	tabs,
	spaces2,
	spaces4,
}

struct Lexer {
	private:
	Ptr!Alloc allocPtr;
	Ptr!AllSymbols allSymbolsPtr;
	ArrBuilder!ParseDiagnostic diags;
	immutable Sym symUnderscore;
	//TODO:PRIVATE
	public immutable CStr sourceBegin;
	//TODO:PRIVATE
	public CStr ptr;
	immutable IndentKind indentKind;
	union {
		bool ignore;
		Cell!Sym curSym; // For Token.name
		Cell!Operator curOperator;
		Cell!LiteralAst curLiteral; // for Token.literal
	}
}

private ref Alloc alloc(return scope ref Lexer lexer) {
	return lexer.allocPtr.deref();
}

private ref AllSymbols allSymbols(return scope ref Lexer lexer) {
	return lexer.allSymbolsPtr.deref();
}

@trusted Lexer createLexer(
	Ptr!Alloc alloc,
	Ptr!AllSymbols allSymbols,
	immutable NulTerminatedStr source,
) {
	// Note: We *are* relying on the nul terminator to stop the lexer.
	immutable string str = strOfNulTerminatedStr(source);
	immutable string useStr = !empty(str) && last(str) == '\n' ? str : rtail(cat!char(alloc.deref(), str, "\n\0"));
	return Lexer(
		alloc,
		allSymbols,
		ArrBuilder!ParseDiagnostic(),
		getSymFromAlphaIdentifier(allSymbols.deref(), "_"),
		begin(useStr),
		begin(useStr),
		detectIndentKind(useStr));
}

immutable(char) curChar(ref const Lexer lexer) {
	return *lexer.ptr;
}

immutable(Pos) curPos(ref const Lexer lexer) {
	return posOfPtr(lexer, lexer.ptr);
}

private immutable(Pos) posOfPtr(ref const Lexer lexer, immutable CStr ptr) {
	return safeSizeTToU32(ptr - lexer.sourceBegin);
}

void addDiag(
	ref Alloc alloc,
	ref Lexer lexer,
	immutable RangeWithinFile range,
	immutable ParseDiag diag,
) {
	add(alloc, lexer.diags, immutable ParseDiagnostic(range, diag));
}

immutable(ParseDiagnostic[]) finishDiags(ref Alloc alloc, ref Lexer lexer) {
	return finishArr(alloc, lexer.diags);
}

void addDiagAtChar(ref Alloc alloc, ref Lexer lexer, immutable ParseDiag diag) {
	immutable Pos a = curPos(lexer);
	addDiag(alloc, lexer, immutable RangeWithinFile(a, lexer.curChar == '\0' ? a : a + 1), diag);
}

void addDiagUnexpected(ref Alloc alloc, ref Lexer lexer) {
	addDiagAtChar(alloc, lexer, immutable ParseDiag(immutable ParseDiag.UnexpectedCharacter(curChar(lexer))));
}

@trusted immutable(bool) peekExact(ref const Lexer lexer, immutable char c) {
	return *lexer.ptr == c;
}

@trusted immutable(bool) peekExact(ref const Lexer lexer, immutable CStr c) {
	CStr ptr = lexer.ptr;
	for (CStr cptr = c; *cptr != 0; cptr++) {
		if (*ptr != *cptr)
			return false;
		ptr++;
	}
	return true;
}

@trusted immutable(bool) tryTake(ref Lexer lexer, immutable char c) {
	if (*lexer.ptr == c) {
		lexer.ptr++;
		return true;
	} else
		return false;
}

immutable(bool) tryTake(ref Lexer, immutable(Token)) {
	return todo!(immutable bool)("Use tryTakeToken!!!");
}

@trusted immutable(bool) tryTake(ref Lexer lexer, immutable CStr c) {
	CStr ptr2 = lexer.ptr;
	for (CStr cptr = c; *cptr != 0; cptr++) {
		if (*ptr2 != *cptr)
			return false;
		ptr2++;
	}
	lexer.ptr = ptr2;
	return true;
}

immutable(bool) takeOrAddDiagExpected(
	ref Alloc alloc,
	ref Lexer lexer,
	immutable char c,
	immutable ParseDiag.Expected.Kind kind,
) {
	immutable bool res = tryTake(lexer, c);
	if (!res)
		addDiagAtChar(alloc, lexer, immutable ParseDiag(immutable ParseDiag.Expected(kind)));
	return res;
}

immutable(bool) takeOrAddDiagExpected(
	ref Alloc alloc,
	ref Lexer lexer,
	immutable CStr c,
	immutable ParseDiag.Expected.Kind kind,
) {
	immutable bool res = tryTake(lexer, c);
	if (!res)
		addDiagAtChar(alloc, lexer, immutable ParseDiag(immutable ParseDiag.Expected(kind)));
	return res;
}

enum NewlineOrIndent {
	newline,
	indent,
}

immutable(NewlineOrIndent) takeNewlineOrIndent_topLevel(ref Alloc alloc, ref Lexer lexer) {
	if (!takeOrAddDiagExpected(alloc, lexer, '\n', ParseDiag.Expected.Kind.endOfLine))
		skipRestOfLineAndNewline(lexer);
	immutable IndentDelta delta = skipBlankLinesAndGetIndentDelta(alloc, lexer, 0);
	return matchIndentDelta!(immutable NewlineOrIndent)(
		delta,
		(ref immutable IndentDelta.DedentOrSame it) {
			verify(it.nDedents == 0);
			return NewlineOrIndent.newline;
		},
		(ref immutable IndentDelta.Indent) {
			return NewlineOrIndent.indent;
		});
}

immutable(bool) takeIndentOrDiagTopLevel(ref Alloc alloc, ref Lexer lexer) {
	return takeIndentOrFailGeneric!(immutable bool)(
		alloc,
		lexer,
		0,
		() => true,
		(immutable RangeWithinFile, immutable uint dedent) {
			verify(dedent == 0);
			return false;
		});
}

immutable(bool) takeIndentOrDiagTopLevelAfterNewline(ref Alloc alloc, ref Lexer lexer) {
	immutable Pos start = curPos(lexer);
	immutable IndentDelta delta = skipBlankLinesAndGetIndentDelta(alloc, lexer, 0);
	return matchIndentDelta!(immutable bool)(
		delta,
		(ref immutable IndentDelta.DedentOrSame dedent) {
			verify(dedent.nDedents == 0);
			addDiag(
				alloc,
				lexer,
				immutable RangeWithinFile(start, start + 1),
				immutable ParseDiag(immutable ParseDiag.Expected(ParseDiag.Expected.Kind.indent)));
			return false;
		},
		(ref immutable IndentDelta.Indent) => true);
}

immutable(T) takeIndentOrFailGeneric(T)(
	ref Alloc alloc,
	ref Lexer lexer,
	immutable uint curIndent,
	scope immutable(T) delegate() @safe @nogc pure nothrow cbIndent,
	scope immutable(T) delegate(immutable RangeWithinFile, immutable uint) @safe @nogc pure nothrow cbFail,
) {
	immutable Pos start = curPos(lexer);
	immutable IndentDelta delta = takeNewlineAndReturnIndentDelta(alloc, lexer, curIndent);
	return matchIndentDelta!(immutable T)(
		delta,
		(ref immutable IndentDelta.DedentOrSame dedent) {
			addDiag(
				alloc,
				lexer,
				immutable RangeWithinFile(start, start + 1),
				immutable ParseDiag(immutable ParseDiag.Expected(ParseDiag.Expected.Kind.indent)));
			return cbFail(range(lexer, start), dedent.nDedents);
		},
		(ref immutable IndentDelta.Indent) {
			return cbIndent();
		});
}

private @trusted immutable(IndentDelta) takeNewlineAndReturnIndentDelta(
	ref Alloc alloc,
	ref Lexer lexer,
	immutable uint curIndent,
) {
	if (*lexer.ptr != '\n') {
		//TODO: not always expecting indent..
		addDiagAtChar(alloc, lexer, immutable ParseDiag(immutable ParseDiag.Expected(ParseDiag.Expected.Kind.indent)));
		skipUntilNewlineNoDiag(lexer);
	}
	verify(*lexer.ptr == '\n');
	lexer.ptr++;
	return skipBlankLinesAndGetIndentDelta(alloc, lexer, curIndent);
}

void takeDedentFromIndent1(ref Alloc alloc, ref Lexer lexer) {
	immutable IndentDelta delta = skipBlankLinesAndGetIndentDelta(alloc, lexer, 1);
	immutable bool success = matchIndentDelta!(immutable bool)(
		delta,
		(ref immutable IndentDelta.DedentOrSame it) =>
			it.nDedents == 1,
		(ref immutable IndentDelta.Indent) =>
			false);
	if (!success) {
		addDiagAtChar(alloc, lexer, immutable ParseDiag(immutable ParseDiag.Expected(ParseDiag.Expected.Kind.dedent)));
		skipRestOfLineAndNewline(lexer);
		takeDedentFromIndent1(alloc, lexer);
	}
}

immutable(NewlineOrIndent) tryTakeIndentAfterNewline_topLevel(
	ref Alloc alloc,
	ref Lexer lexer,
) {
	immutable IndentDelta delta = skipBlankLinesAndGetIndentDelta(alloc, lexer, 0);
	return matchIndentDelta!(immutable NewlineOrIndent)(
		delta,
		(ref immutable IndentDelta.DedentOrSame it) {
			verify(it.nDedents == 0);
			return NewlineOrIndent.newline;
		},
		(ref immutable IndentDelta.Indent) =>
			NewlineOrIndent.indent);
}

immutable(uint) takeNewlineOrDedentAmount(
	ref Alloc alloc,
	ref Lexer lexer,
	immutable uint curIndent,
) {
	// Must be at the end of a line
	if (!takeOrAddDiagExpected(alloc, lexer, '\n', ParseDiag.Expected.Kind.endOfLine))
		skipRestOfLineAndNewline(lexer);
	immutable IndentDelta delta = skipBlankLinesAndGetIndentDelta(alloc, lexer, curIndent);
	return matchIndentDelta!(immutable uint)(
		delta,
		(ref immutable IndentDelta.DedentOrSame it) {
			return it.nDedents;
		},
		(ref immutable IndentDelta.Indent) {
			addDiagAtChar(alloc, lexer, immutable ParseDiag(
				immutable ParseDiag.Unexpected(ParseDiag.Unexpected.Kind.indent)));
			skipUntilNewlineNoDiag(lexer);
			return takeNewlineOrDedentAmount(alloc, lexer, curIndent);
		});
}

enum NewlineOrDedent {
	newline,
	dedent,
}

immutable(NewlineOrDedent) takeNewlineOrSingleDedent(ref Alloc alloc, ref Lexer lexer) {
	switch (takeNewlineOrDedentAmount(alloc, lexer, 1)) {
		case 0:
			return NewlineOrDedent.newline;
		case 1:
			return NewlineOrDedent.dedent;
		default:
			return unreachable!NewlineOrDedent;
	}
}

immutable(RangeWithinFile) range(ref Lexer lexer, immutable Pos begin) {
	verify(begin <= curPos(lexer));
	return immutable RangeWithinFile(begin, curPos(lexer));
}

void addDiagOnReservedName(
	ref Alloc alloc,
	ref Lexer lexer,
	immutable NameAndRange name,
) {
	addDiag(alloc, lexer, rangeOfNameAndRange(name), immutable ParseDiag(immutable ParseDiag.ReservedName(name.name)));
}

struct SymAndIsReserved {
	immutable NameAndRange name;
	immutable bool isReserved;
}

immutable(SymAndIsReserved) takeNameAllowReserved(ref Alloc alloc, ref AllSymbols allSymbols, ref Lexer lexer) {
	immutable StrAndIsOperator s = takeNameAsTempStr(alloc, lexer);
	if (s.isOperator) {
		immutable Opt!Sym op = getSymFromOperator(allSymbols, s.str);
		if (has(op))
			return immutable SymAndIsReserved(immutable NameAndRange(s.start, force(op)), false);
		else {
			addDiag(alloc, lexer, range(lexer, s.start), immutable ParseDiag(
				immutable ParseDiag.InvalidName(copyStr(alloc, s.str))));
			return immutable SymAndIsReserved(immutable NameAndRange(s.start, shortSymAlphaLiteral("bogus")), false);
		}
	} else {
		immutable Sym name = getSymFromAlphaIdentifier(allSymbols, s.str);
		return immutable SymAndIsReserved(immutable NameAndRange(s.start, name), isReservedName(lexer, name));
	}
}

immutable(NameAndRange) takeNameAndRange(ref Alloc alloc, ref AllSymbols allSymbols, ref Lexer lexer) {
	while (tryTake(lexer, ' ')) {}
	immutable SymAndIsReserved s = takeNameAllowReserved(alloc, allSymbols, lexer);
	if (s.isReserved)
		addDiagOnReservedName(alloc, lexer, s.name);
	return s.name;
}

immutable(Sym) takeName(ref Alloc alloc, ref AllSymbols allSymbols, ref Lexer lexer) {
	return takeNameAndRange(alloc, allSymbols, lexer).name;
}

immutable(NameOrUnderscoreOrNone) takeNameOrUnderscoreOrNone(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
) {
	if (tryTake(lexer, ' ')) {
		immutable SymAndIsReserved s = takeNameAllowReserved(alloc, allSymbols, lexer);
		if (s.isReserved) {
			if (s.name.name == lexer.symUnderscore)
				return immutable NameOrUnderscoreOrNone(immutable NameOrUnderscoreOrNone.Underscore());
			else {
				addDiagOnReservedName(alloc, lexer, s.name);
				return immutable NameOrUnderscoreOrNone(s.name.name);
			}
		} else
			return immutable NameOrUnderscoreOrNone(s.name.name);
	} else
		return immutable NameOrUnderscoreOrNone(immutable NameOrUnderscoreOrNone.None());
}

immutable(string) takeQuotedStr(ref Lexer lexer, ref Alloc alloc) {
	if (takeOrAddDiagExpected(alloc, lexer, '"', ParseDiag.Expected.Kind.quote)) {
		immutable StringPart sp = takeStringPart(alloc, lexer, '"');
		final switch (sp.after) {
			case StringPart.After.quote:
				return sp.text;
			case StringPart.After.lbrace:
				return todo!(immutable string)("!");
		}
	} else
		return "";
}

@trusted void skipUntilNewlineNoDiag(ref Lexer lexer) {
	while (*lexer.ptr != '\n') {
		assert(*lexer.ptr != '\0');
		lexer.ptr++;
	}
}

private:

@trusted immutable(SafeCStr) takeRestOfLineAndNewline(ref Alloc alloc, ref Lexer lexer) {
	immutable char* begin = lexer.ptr;
	skipRestOfLineAndNewline(lexer);
	immutable char* end = lexer.ptr - 1;
	return copyToSafeCStr(alloc, arrOfRange(begin, end));
}

@trusted void skipRestOfLineAndNewline(ref Lexer lexer) {
	skipUntilNewlineNoDiag(lexer);
	lexer.ptr++;
}

// Note: Not issuing any diagnostics here. We'll fail later if we detect the wrong indent kind.
immutable(IndentKind) detectIndentKind(immutable string str) {
	if (empty(str))
		// No indented lines, so it's irrelevant
		return IndentKind.tabs;
	else {
		immutable char c0 = first(str);
		if (c0 == '\t')
			return IndentKind.tabs;
		else if (c0 == ' ') {
			// Count spaces
			uint i = 0;
			for (; i < size(str); i++)
				if (at(str, i) != ' ')
					break;
			// Only allowed amounts are 2 and 4.
			return i == 2 ? IndentKind.spaces2 : IndentKind.spaces4;
		} else {
			foreach (immutable size_t i; 0 .. size(str))
				if (at(str, i) == '\n')
					return detectIndentKind(str[i + 1 .. $]);
			return IndentKind.tabs;
		}
	}
}

//TODO:PRIVATE
public @trusted void backUp(ref Lexer lexer) {
	lexer.ptr--;
}

public @trusted immutable(char) next(ref Lexer lexer) {
	immutable char res = *lexer.ptr;
	lexer.ptr++;
	return res;
}

public enum Token {
	act, // 'act'
	arrowLambda, // =>
	arrowThen, // '<-'
	as, // 'as'
	atLess, // '!<'
	braceLeft, // '{'
	braceRight, // '}'
	bracketLeft, // '['
	bracketRight, // ']'
	colon, // ':'
	colonEqual, // ':='
	comma, // ','
	dot, // '.'
	elif, // 'elif'
	else_, // 'else'
	equal, // '='
	EOF, // end of file
	fun, // 'fun'
	if_, // 'if'
	invalid,
	literal, // Use getCurLiteral
	match, // 'match'
	mut, // 'mut'
	name, // Any non-keyword, non-operator name; use getCurSym with this
	newline, // end of line
	operator, // Any operator; use getCurOperator with this
	parenLeft, // '('
	parenRight, // ')'
	question, // '?'
	questionEqual, // '?='
	quoteDouble, // '"'
	quoteSingle, // "'"
	ref_, // 'ref'
}

@trusted public immutable(Token) nextToken(ref Lexer lexer) {
	immutable Pos start = curPos(lexer);
	immutable CStr begin = lexer.ptr;
	immutable char c = next(lexer);

	immutable(Token) nameToken(immutable Sym a) {
		cellSet(lexer.curSym, a);
		return Token.name;
	}

	immutable(Token) operatorToken(immutable Operator a) {
		cellSet(lexer.curOperator, a);
		return Token.operator;
	}

	immutable(Token) literalToken(immutable LiteralAst a) {
		cellSet(lexer.curLiteral, a);
		return Token.literal;
	}

	switch (c) {
		case '\0':
			backUp(lexer);
			return Token.EOF;
		case ' ':
			return nextToken(lexer);
		case '\n':
			return Token.newline;
		case '~':
			return operatorToken(tryTake(lexer, '=') ? Operator.concatEquals : Operator.tilde);
		case '@':
			return tryTake(lexer, '<')
				? Token.atLess
				: Token.invalid;
		case '!':
			return operatorToken(tryTake(lexer, '=') ? Operator.notEqual : Operator.not);
		case '^':
			return operatorToken(Operator.xor1);
		case '&':
			return operatorToken(tryTake(lexer, '&') ? Operator.and2 : Operator.and1);
		case '*':
			return operatorToken(tryTake(lexer, '*') ? Operator.exponent : Operator.times);
		case '(':
			return Token.parenLeft;
		case ')':
			return Token.parenRight;
		case '[':
			return Token.bracketLeft;
		case '{':
			return Token.braceLeft;
		case '}':
			return Token.braceRight;
		case ']':
			return Token.bracketRight;
		case '-':
			return isDigit(*lexer.ptr)
				? literalToken(takeNumberAfterSign(lexer, some(Sign.minus)))
				: operatorToken(tryTake(lexer, '>') ? Operator.arrow : Operator.minus);
		case '=':
			return tryTake(lexer, '>')
				? Token.arrowLambda
				: tryTake(lexer, '=')
				? operatorToken(Operator.equal)
				: Token.equal;
		case '+':
			return isDigit(*lexer.ptr)
				? literalToken(takeNumberAfterSign(lexer, some(Sign.plus)))
				: operatorToken(Operator.plus);
		case '|':
			return tryTake(lexer, '|')
				? operatorToken(Operator.or2)
				: operatorToken(Operator.or1);
		case ':':
			return tryTake(lexer, '=')
				? Token.colonEqual
				: Token.colon;
		case '\'':
			return Token.quoteSingle;
		case '"':
			return Token.quoteDouble;
		case ',':
			return Token.comma;
		case '<':
			return tryTake(lexer, '-')
				? Token.arrowThen
				: operatorToken(tryTake(lexer, '=')
					? tryTake(lexer, '>') ? Operator.compare : Operator.lessOrEqual
					: tryTake(lexer, '<')
					? Operator.shiftLeft
					: Operator.less);
		case '>':
			return operatorToken(tryTake(lexer, '=')
				? Operator.greaterOrEqual
				: tryTake(lexer, '>')
				? Operator.shiftRight
				: Operator.greater);
		case '.':
			return tryTake(lexer, '.')
				? operatorToken(Operator.range)
				: Token.dot;
		case '/':
			return operatorToken(Operator.divide);
		case '?':
			return tryTake(lexer, '=') ? Token.questionEqual : Token.question;
		default:
			if (isAlphaIdentifierStart(c)) {
				immutable string nameStr = takeNameRest(lexer, begin);
				immutable Sym name = getSymFromAlphaIdentifier(lexer.allSymbols, nameStr);
				if (isReservedName(lexer, name))
					switch (name.value) {
						case shortSymAlphaLiteralValue("act"):
							return Token.act;
						case shortSymAlphaLiteralValue("as"):
							return Token.as;
						case shortSymAlphaLiteralValue("fun"):
							return Token.fun;
						case shortSymAlphaLiteralValue("if"):
							return Token.if_;
						case shortSymAlphaLiteralValue("elif"):
							return Token.elif;
						case shortSymAlphaLiteralValue("else"):
							return Token.else_;
						case shortSymAlphaLiteralValue("match"):
							return Token.match;
						case shortSymAlphaLiteralValue("mut"):
							return Token.mut;
						case shortSymAlphaLiteralValue("ref"):
							return Token.ref_;
						default:
							//TODO: have tokens for every reserved name, so this never happens.
							addDiagOnReservedName(lexer.alloc, lexer, immutable NameAndRange(start, name));
							return Token.name;
					}
				else
					return nameToken(name);
			} else if (isDigit(c)) {
				backUp(lexer);
				return literalToken(takeNumberAfterSign(lexer, none!Sign));
			} else
				return Token.invalid;
	}
}

public immutable(Sym) getCurSym(ref Lexer lexer) {
	//TODO: assert that cur token is Token.name
	return cellGet(lexer.curSym);
}

public immutable(NameAndRange) getCurNameAndRange(ref Lexer lexer, immutable Pos start) {
	return immutable NameAndRange(start, getCurSym(lexer));
}

public immutable(Operator) getCurOperator(ref Lexer lexer) {
	return cellGet(lexer.curOperator);
}

@trusted public immutable(LiteralAst) getCurLiteral(ref Lexer lexer) {
	//TODO: assert that cur token is Token.literal
	return cellGet(lexer.curLiteral);
}

public immutable(bool) tryTakeToken(ref Lexer lexer, immutable Token expected) {
	//TODO: always have the next token ready, so we don't need to repeatedly lex the same token
	immutable char* before = lexer.ptr;
	immutable Token actual = nextToken(lexer);
	if (actual == expected)
		return true;
	else {
		lexer.ptr = before;
		return false;
	}
}

public immutable(bool) tryTakeOperator(ref Lexer lexer, immutable Operator expected) {
	immutable char* before = lexer.ptr;
	immutable Token actual = nextToken(lexer);
	if (actual == Token.operator && getCurOperator(lexer) == expected)
		return true;
	else {
		lexer.ptr = before;
		return false;
	}
}

immutable(Token) getPeekToken(ref Lexer lexer) {
	//TODO: always have the next token ready, so we don't need to repeatedly lex the same token
	immutable char* before = lexer.ptr;
	immutable Token res = nextToken(lexer);
	lexer.ptr = before;
	return res;
}

public immutable(bool) peekToken(ref Lexer lexer, immutable Token expected) {
	return getPeekToken(lexer) == expected;
}

public immutable(bool) peekTokenExpression(ref Lexer lexer) {
	return isExpressionToken(getPeekToken(lexer));
}

// Whether a token may start an expression
immutable(bool) isExpressionToken(immutable Token a) {
	final switch (a) {
		case Token.act:
		case Token.arrowLambda:
		case Token.arrowThen:
		case Token.as:
		case Token.atLess:
		case Token.braceLeft:
		case Token.braceRight:
		case Token.bracketRight:
		case Token.colon:
		case Token.colonEqual:
		case Token.comma:
		case Token.dot:
		case Token.elif:
		case Token.else_:
		case Token.equal:
		case Token.EOF:
		case Token.fun:
		case Token.invalid:
		case Token.mut:
		case Token.newline:
		case Token.parenRight:
		case Token.question:
		case Token.questionEqual:
		case Token.ref_:
			return false;
		case Token.bracketLeft:
		case Token.if_:
		case Token.literal:
		case Token.match:
		case Token.name:
		case Token.operator:
		case Token.parenLeft:
		case Token.quoteDouble:
		case Token.quoteSingle:
			return true;
	}
}

immutable(RangeWithinFile) range(ref Lexer lexer, immutable CStr begin) {
	verify(begin >= lexer.sourceBegin);
	return range(lexer, safeSizeTToU32(begin - lexer.sourceBegin));
}

public enum Sign {
	plus,
	minus,
}

public @trusted immutable(LiteralIntOrNat) takeIntOrNat(ref Lexer lexer) {
	immutable Opt!Sign sign = tryTake(lexer, '+')
		? some(Sign.plus)
		: tryTake(lexer, '-')
		? some(Sign.minus)
		: none!Sign;
	immutable LiteralAst res = takeNumberAfterSign(lexer, sign);
	return matchLiteralAst!(LiteralIntOrNat)(
		res,
		(immutable LiteralAst.Float) => todo!(immutable LiteralIntOrNat)("no float in enum"),
		(immutable LiteralAst.Int i) => immutable LiteralIntOrNat(i),
		(immutable LiteralAst.Nat n) => immutable LiteralIntOrNat(n),
		(immutable(string)) => unreachable!(immutable LiteralIntOrNat),
		(immutable(Sym)) => unreachable!(immutable LiteralIntOrNat));
}

public @trusted immutable(LiteralAst) takeNumberAfterSign(ref Lexer lexer, immutable Opt!Sign sign) {
	immutable ulong base = tryTake(lexer, "0x") ? 16 : tryTake(lexer, "0o") ? 8 : tryTake(lexer, "0b") ? 2 : 10;
	immutable LiteralAst.Nat n = takeNat(lexer, base);
	if (*lexer.ptr == '.' && isDigit(*(lexer.ptr + 1))) {
		lexer.ptr++;
		return immutable LiteralAst(takeFloat(lexer, optOr!Sign(sign, () => Sign.plus), n, base));
	} else if (has(sign))
		final switch (force(sign)) {
			case Sign.plus:
				return immutable LiteralAst(immutable LiteralAst.Int(n.value, n.value > long.max));
			case Sign.minus:
				return immutable LiteralAst(immutable LiteralAst.Int(-n.value, n.value > (cast(ulong) long.max) + 1));
		}
	else
		return immutable LiteralAst(n);
}

@system immutable(LiteralAst.Float) takeFloat(
	ref Lexer lexer,
	immutable Sign sign,
	ref immutable LiteralAst.Nat natPart,
	immutable ulong base,
) {
	// TODO: improve accuracy
	const char *cur = lexer.ptr;
	immutable LiteralAst.Nat rest = takeNat(lexer, base);
	immutable bool overflow = natPart.overflow || rest.overflow;
	immutable ulong power = lexer.ptr - cur;
	immutable double multiplier = pow(1.0, 1.0 / base, power);
	immutable double floatSign = () {
		final switch (sign) {
			case Sign.minus:
				return -1.0;
			case Sign.plus:
				return 1.0;
		}
	}();
	immutable double f = floatSign * (natPart.value + (rest.value * multiplier));
	return immutable LiteralAst.Float(f, overflow);
}

immutable(double) pow(immutable double acc, immutable double base, immutable ulong power) {
	return power == 0 ? acc : pow(acc * base, base, power - 1);
}

//TODO: overflow bug possible here
immutable(ulong) getDivisor(immutable ulong acc, immutable ulong a, immutable ulong base) {
	return acc < a ? getDivisor(acc * base, a, base) : acc;
}

@system immutable(LiteralAst.Nat) takeNat(ref Lexer lexer, immutable ulong base) {
	return takeNatRecur(lexer, base, 0, false);
}

@system immutable(LiteralAst.Nat) takeNatRecur(
	ref Lexer lexer,
	immutable ulong base,
	immutable ulong value,
	immutable bool overflow,
) {
	immutable ulong digit = charToNat(*lexer.ptr);
	if (digit < base) {
		lexer.ptr++;
		immutable ulong newValue = value * base + digit;
		drop(tryTake(lexer, '_'));
		return takeNatRecur(lexer, base, newValue, overflow || newValue / base != value);
	} else
		return immutable LiteralAst.Nat(value, overflow);
}

immutable(ulong) charToNat(immutable char c) {
	return '0' <= c && c <= '9'
		? c - '0'
		: 'a' <= c && c <= 'f'
		? 10 + (c - 'a')
		: 'A' <= c && c <= 'F'
		? 10 + (c - 'A')
		: ulong.max;
}

@trusted immutable(string) takeOperatorRest(ref Lexer lexer, immutable CStr begin) {
	while (isOperatorChar(*lexer.ptr))
		lexer.ptr++;
	return arrOfRange(begin, lexer.ptr);
}

// NOTE: this will allow taking invalid operators, then we'll issue a diagnostic for them
immutable(bool) isOperatorChar(immutable char c) {
	switch (c) {
		case '=':
		case '!':
		case '<':
		case '>':
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
		case '~':
		case '&':
		case '|':
		case '.':
			return true;
		default:
			return false;
	}
}


immutable(size_t) toHexDigit(immutable char c) {
	if ('0' <= c && c <= '9')
		return c - '0';
	else if ('a' <= c && c <= 'f')
		return 10 + c - 'a';
	else
		return todo!size_t("parse diagnostic -- bad hex digit");
}

public struct StringPart {
	immutable string text;
	immutable After after;

	enum After {
		quote,
		lbrace,
	}
}

immutable(bool) allowedStringPartCharacter(immutable char c, immutable char endQuote) {
	switch (c) {
		case '\n':
		case '\0':
		case '{':
		case endQuote:
			return false;
		default:
			return true;
	}
}

public immutable(Sym) takeSymbolLiteral(
	ref Alloc alloc,
	ref AllSymbols allSymbols,
	ref Lexer lexer,
) {
	immutable StringPart part = takeStringPart(alloc, lexer, '\'');
	final switch (part.after) {
		case StringPart.After.quote:
			return symOfStr(allSymbols, part.text);
		case StringPart.After.lbrace:
			// Diagnostic: '{' should be escaped to avoid confusion with interpolation
			return todo!(immutable Sym)("!");
	}
}

public @trusted immutable(StringPart) takeStringPart(
	ref Alloc alloc,
	ref Lexer lexer,
	immutable char endQuote,
) {
	immutable CStr begin = lexer.ptr;
	size_t nEscapedCharacters = 0;
	// First get the max size
	while (allowedStringPartCharacter(*lexer.ptr, endQuote)) {
		if (*lexer.ptr == '\\') {
			lexer.ptr++;
			nEscapedCharacters++;
			if (*lexer.ptr == 'x') {
				lexer.ptr++;
				if (allowedStringPartCharacter(*lexer.ptr, endQuote)) {
					lexer.ptr++;
					nEscapedCharacters++;
					if (allowedStringPartCharacter(*lexer.ptr, endQuote)) {
						lexer.ptr++;
						nEscapedCharacters++;
					}
				}
			} else {
				lexer.ptr++;
			}
		} else {
			lexer.ptr++;
		}
	}

	immutable size_t size = (lexer.ptr - begin) - nEscapedCharacters;
	char* res = cast(char*) allocateBytes(alloc, char.sizeof * size);

	size_t outI = 0;
	lexer.ptr = begin;
	while (allowedStringPartCharacter(*lexer.ptr, endQuote)) {
		if (*lexer.ptr == '\\') {
			lexer.ptr++;
			immutable char c = () {
				immutable char esc = *lexer.ptr;
				switch (esc) {
					case 'x':
						// Take two more
						lexer.ptr++;
						immutable char a = *lexer.ptr;
						lexer.ptr++;
						immutable char b = *lexer.ptr;
						immutable size_t na = toHexDigit(a);
						immutable size_t nb = toHexDigit(b);
						return cast(char) (na * 16 + nb);
					case 'n':
						return '\n';
					case 'r':
						return '\r';
					case 't':
						return '\t';
					case '\\':
						return '\\';
					case '{':
						return '{';
					case '0':
						return '\0';
					case endQuote:
						return endQuote;
					default:
						addDiagAtChar(alloc, lexer, immutable ParseDiag(immutable ParseDiag.InvalidStringEscape(esc)));
						return 'a';
				}
			}();
			res[outI] = c;
			outI++;
		} else {
			res[outI] = *lexer.ptr;
			outI++;
		}
		lexer.ptr++;
	}

	immutable StringPart.After after = () {
		switch (*lexer.ptr) {
			case '{':
				return StringPart.After.lbrace;
			case endQuote:
				return StringPart.After.quote;
			default:
				return unreachable!(immutable StringPart.After);
		}
	}();
	lexer.ptr++;
	verify(outI == size);
	return immutable StringPart(cast(immutable) res[0 .. size], after);
}

public @trusted immutable(string) takeNameRest(ref Lexer lexer, immutable CStr begin) {
	while (isAlphaIdentifierContinue(*lexer.ptr))
		lexer.ptr++;
	if (*lexer.ptr == '!')
		lexer.ptr++;
	return arrOfRange(begin, lexer.ptr);
}

// Called after the newline
@trusted uint takeIndentAmount(ref Alloc alloc, ref Lexer lexer) {
	immutable CStr begin = lexer.ptr;
	if (lexer.indentKind == IndentKind.tabs) {
		while (*lexer.ptr == '\t') lexer.ptr++;
		if (*lexer.ptr == ' ')
			addDiagAtChar(alloc, lexer, immutable ParseDiag(immutable ParseDiag.IndentWrongCharacter(true)));
		immutable uint res = (lexer.ptr - begin).safeSizeTToU32;
		return res;
	} else {
		immutable Pos start = curPos(lexer);
		while (*lexer.ptr == ' ')
			lexer.ptr++;
		if (*lexer.ptr == '\t')
			addDiagAtChar(alloc, lexer, immutable ParseDiag(immutable ParseDiag.IndentWrongCharacter(false)));
		immutable uint nSpaces = (lexer.ptr - begin).safeSizeTToU32;
		immutable uint nSpacesPerIndent = lexer.indentKind == IndentKind.spaces2 ? 2 : 4;
		immutable uint res = nSpaces / nSpacesPerIndent;
		if (res * nSpacesPerIndent != nSpaces)
			addDiag(alloc, lexer, range(lexer, start), immutable ParseDiag(
				immutable ParseDiag.IndentNotDivisible(nSpaces, nSpacesPerIndent)));
		return res;
	}
}

struct IndentDelta {
	@safe @nogc pure nothrow:

	struct DedentOrSame {
		immutable uint nDedents;
	}
	struct Indent {}
	enum Kind {
		dedentOrSame,
		indent,
	}
	private:
	immutable Kind kind;
	union {
		immutable DedentOrSame dedentOrSame_;
		immutable Indent indent_;
	}

	public:
	immutable this(immutable DedentOrSame a) { kind = Kind.dedentOrSame; dedentOrSame_ = a; }
	immutable this(immutable Indent a) { kind = Kind.indent; indent_ = a; }
}

@trusted T matchIndentDelta(T)(
	ref immutable IndentDelta a,
	scope T delegate(ref immutable IndentDelta.DedentOrSame) @safe @nogc pure nothrow cbDedentOrSame,
	scope T delegate(ref immutable IndentDelta.Indent) @safe @nogc pure nothrow cbIndent,
) {
	final switch (a.kind) {
		case IndentDelta.Kind.dedentOrSame:
			return cbDedentOrSame(a.dedentOrSame_);
		case IndentDelta.Kind.indent:
			return cbIndent(a.indent_);
	}
}

public immutable(SafeCStr) skipBlankLinesAndGetDocComment(ref Alloc alloc, ref Lexer lexer) {
	return skipBlankLinesAndGetDocCommentRecur(alloc, lexer, emptySafeCStr);
}

immutable(SafeCStr) skipBlankLinesAndGetDocCommentRecur(
	ref Alloc alloc,
	ref Lexer lexer,
	immutable SafeCStr comment,
) {
	if (tryTake(lexer, '\n'))
		return skipBlankLinesAndGetDocCommentRecur(alloc, lexer, emptySafeCStr);
	else if (tryTake(lexer, "###\n"))
		return skipBlankLinesAndGetDocCommentRecur(alloc, lexer, takeBlockComment(alloc, lexer));
	else if (tryTake(lexer, '#'))
		return skipBlankLinesAndGetDocCommentRecur(alloc, lexer, takeRestOfLineAndNewline(alloc, lexer));
	else if (tryTake(lexer, "region ")) {
		skipRestOfLineAndNewline(lexer);
		return skipBlankLinesAndGetDocCommentRecur(alloc, lexer, emptySafeCStr);
	} else
		return comment;
}

// Returns the change in indent (and updates the indent)
// Note: does nothing if not looking at a newline!
// NOTE: never returns a value > 1 as double-indent is always illegal.
immutable(IndentDelta) skipBlankLinesAndGetIndentDelta(
	ref Alloc alloc,
	ref Lexer lexer,
	immutable uint curIndent,
) {
	// comment / region counts as a blank line no matter its indent level.
	immutable uint newIndent = takeIndentAmount(alloc, lexer);
	if (tryTake(lexer, '\n'))
		// Ignore lines that are just whitespace
		return skipBlankLinesAndGetIndentDelta(alloc, lexer, curIndent);

	// For indent == 0, we'll try taking any comments as doc comments
	if (newIndent != 0) {
		// Comments can mean a dedent
		if (tryTake(lexer, "###\n")) {
			skipBlockComment(alloc, lexer);
			return skipBlankLinesAndGetIndentDelta(alloc, lexer, curIndent);
		} else if (tryTake(lexer, '#')) {
			skipRestOfLineAndNewline(lexer);
			return skipBlankLinesAndGetIndentDelta(alloc, lexer, curIndent);
		}
	}

	// If we got here, we're looking at a non-empty line (or EOF)
	immutable int delta = safeI32FromU32(newIndent) - safeI32FromU32(curIndent);
	if (delta > 1) {
		addDiagAtChar(alloc, lexer, immutable ParseDiag(immutable ParseDiag.IndentTooMuch()));
		skipRestOfLineAndNewline(lexer);
		return skipBlankLinesAndGetIndentDelta(alloc, lexer, curIndent);
	} else
		return delta == 1
			? immutable IndentDelta(immutable IndentDelta.Indent())
			: immutable IndentDelta(immutable IndentDelta.DedentOrSame(-delta));
}

@trusted immutable(SafeCStr) takeBlockComment(ref Alloc alloc, ref Lexer lexer) {
	immutable char* begin = lexer.ptr;
	skipBlockComment(alloc, lexer);
	immutable char* end = lexer.ptr - "\n###\n".length;
	return copyToSafeCStr(alloc, arrOfRange(begin, end));
}

void skipBlockComment(ref Alloc alloc, ref Lexer lexer) {
	skipRestOfLineAndNewline(lexer);
	drop(takeIndentAmount(alloc, lexer));
	if (!tryTake(lexer, "###\n"))
		skipBlockComment(alloc, lexer);
}

struct StrAndIsOperator {
	immutable string str;
	immutable Pos start;
	immutable bool isOperator;
}

@trusted public immutable(StrAndIsOperator) takeNameAsTempStr(
	ref Alloc alloc,
	ref Lexer lexer,
) {
	immutable CStr begin = lexer.ptr;
	immutable Pos start = curPos(lexer);
	if (isOperatorChar(*lexer.ptr)) {
		lexer.ptr++;
		immutable string op = takeOperatorRest(lexer, begin);
		return immutable StrAndIsOperator(op, start, true);
	} else if (isAlphaIdentifierStart(*lexer.ptr)) {
		lexer.ptr++;
		immutable string name = takeNameRest(lexer, begin);
		return immutable StrAndIsOperator(name, start, false);
	} else {
		while (*lexer.ptr != ' ' && *lexer.ptr != '\n')
			lexer.ptr++;
		// Copy since it's used in a diag
		immutable string s = copyStr(alloc, arrOfRange(begin, lexer.ptr));
		addDiag(alloc, lexer, range(lexer, begin), immutable ParseDiag(
			immutable ParseDiag.InvalidName(s)));
		return immutable StrAndIsOperator("", start, false);
	}
}

public immutable(bool) isReservedName(ref const Lexer lexer, immutable Sym name) {
	switch (name.value) {
		case shortSymAlphaLiteralValue("act"):
		case shortSymAlphaLiteralValue("alias"):
		case shortSymAlphaLiteralValue("as"):
		case shortSymAlphaLiteralValue("builtin"):
		case shortSymAlphaLiteralValue("elif"):
		case shortSymAlphaLiteralValue("else"):
		case shortSymAlphaLiteralValue("export"):
		case shortSymAlphaLiteralValue("extern"):
		case shortSymAlphaLiteralValue("extern-ptr"):
		case shortSymAlphaLiteralValue("fun"):
		case shortSymAlphaLiteralValue("global"):
		case shortSymAlphaLiteralValue("if"):
		case shortSymAlphaLiteralValue("import"):
		case shortSymAlphaLiteralValue("match"):
		case shortSymAlphaLiteralValue("mut"):
		case shortSymAlphaLiteralValue("noctx"):
		case shortSymAlphaLiteralValue("record"):
		case shortSymAlphaLiteralValue("ref"):
		case shortSymAlphaLiteralValue("sendable"):
		case shortSymAlphaLiteralValue("spec"):
		case shortSymAlphaLiteralValue("summon"):
		case shortSymAlphaLiteralValue("trusted"):
		case shortSymAlphaLiteralValue("union"):
		case shortSymAlphaLiteralValue("unsafe"):
			return true;
		default:
			return name == lexer.symUnderscore;
	}
}

public @trusted immutable(bool) lookaheadWillTakeEqualsOrThen(ref Lexer lexer) {
	immutable(char)* ptr = lexer.ptr;
	while (true) {
		switch (*ptr) {
			case ' ':
				if ((ptr[1] == '=' && ptr[2] == ' ') || (ptr[1] == '<' && ptr[2] == '-' && ptr[3] == ' '))
					return true;
				break;
			// characters that appear in typse
			case '<':
			case '>':
			case ',':
			case '?':
			case '*':
			case '[':
			case ']':
			case '(':
			case ')':
				break;
			default:
				if (!isAlphaIdentifierContinue(*ptr))
					return false;
				break;
		}
		ptr++;
	}
}

public @trusted immutable(bool) lookaheadWillTakeArrow(ref Lexer lexer) {
	immutable(char)* ptr = lexer.ptr;
	while (true) {
		switch (*ptr) {
			case '(':
				// Arrow function parameters never have '(' in them
				return false;
			case ')':
				return ptr[1] == ' ' && ptr[2] == '=' && ptr[3] == '>';
			case '\n':
			case '\0':
				return false;
			default:
				break;
		}
		ptr++;
	}
}
