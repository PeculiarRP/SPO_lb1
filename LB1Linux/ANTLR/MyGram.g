grammar MyGram;

options {
  backtrack=true;
  memoize=true;
  k=3;
  output=AST;
  //ASTLabelType=pANTLR3_BASE_TREE;
  language=C;
}

tokens{
	SOURCE;
	SOURCEITEM;
	FUNCDEF;
	FUNCSIGNATURE;
	LISTARG;
	TYPEREF;
	ARRAY;
	STATEMENT;
	BUILTIN;
	CUSTOM;
	BLOCKSTATEMENT;
	BREAKSTATEMENT;
	LOOPSTATEMENT;
	IFSTATEMENT;
	REPEATSTATEMENT;
	IDEN;
	ARG;
	ST;
	EXPSTATEMENT;
	EXPR;
	CALLEXPR;
	SLICEEXPR;
	ARGS;
}

@header{
	#include <assert.h>
}

source	: sourceItem* -> ^(SOURCE sourceItem*);
sourceItem: funcDef -> ^(SOURCEITEM funcDef);
funcDef: 'def' funcSignature statement* 'end' -> ^(FUNCDEF funcSignature statement*);
funcSignature
    : custom LPAREN listArg? RPAREN endTypeSpec? -> ^(FUNCSIGNATURE custom listArg? endTypeSpec?)
    ;
listArg	: argSpec (COMMA argSpec)* -> ^(LISTARG argSpec (argSpec)*);
argSpec: custom endTypeSpec? -> ^(ARG custom endTypeSpec?);
endTypeSpec
	: 'of' typeRef -> ^(TYPEREF typeRef);
typeRef
	: array;

baseRef
	: builtinInt -> ^(BUILTIN builtinInt)
	| custom -> ^(CUSTOM custom);

statement
	: ( ifStatement -> ^(STATEMENT ^(IFSTATEMENT ifStatement) repeat?)
	| loopStatement -> ^(STATEMENT ^(LOOPSTATEMENT loopStatement repeat?))
	| breakStatement -> ^(STATEMENT ^(BREAKSTATEMENT breakStatement repeat?))
	| expression -> ^(STATEMENT ^(EXPSTATEMENT expression repeat?))
	| block -> ^(STATEMENT ^(BLOCKSTATEMENT block) repeat?)) repeat?;

custom: IDENTIFIER -> ^(IDEN IDENTIFIER);
array: baseRef arraySpec?;
arraySpec: 
	'array' '[' DEC ']' arraySpec -> ^(ARRAY arraySpec DEC) 
	| 'array' '[' DEC ']'  -> ^(ARRAY DEC);

ifStatement: 'if' expr 'then' statement (elseClause)?;
elseClause: 'else' statement;
loopStatement: loopHeader statement* 'end';
loopHeader: loopWhile expr -> expr; 
repeat: loopWhile expr EndChar -> ^(REPEATSTATEMENT expr EndChar);
loopWhile: 'while' | loopUntil;
loopUntil: 'until';
breakStatement: 'break' EndChar;
expression: expr EndChar;
block: ('begin'|'{') (blockParam)* ('end'|'}') -> blockParam*;
blockParam
	: statement | funcDef;
expr: assigmentExpression -> ^(EXPR assigmentExpression);
assigmentExpression
	:logicalOrExpression
	(ASSIGNEQUAL^ logicalOrExpression)*;

logicalOrExpression
	:logicalAndExpression ('||'^ logicalAndExpression)* ;
	
logicalAndExpression 
	:inclusiveOrExpression ('&&'^ inclusiveOrExpression)*;

inclusiveOrExpression 
	:exclusiveOrExpression ('|'^ exclusiveOrExpression)*;

exclusiveOrExpression
	:andExpression ('^'^ andExpression )*;
andExpression
	:equalityExpression ('&'^ equalityExpression)*;

equalityExpression: relationalExpression (('!='^ | '=='^) relationalExpression)*;

relationalExpression 
	:shiftExpression (
	('<'^
	| '>'^ 
	| '<='^ 
	| '>='^)
	shiftExpression)*;

shiftExpression: additivePlusExpression (('<<'^ | '>>'^) additivePlusExpression)*;
additivePlusExpression: multiplicativeExpression (PLAS^ multiplicativeExpression | MINUS^ multiplicativeExpression)*;
multiplicativeExpression: unaryExpression (
		('*'^ 
		| '/'^ 
		| '%'^) 
		unaryExpression)?;
unaryExpression: PLAS unaryExpression -> ^(PLAS unaryExpression)
	| MINUS unaryExpression -> ^(MINUS unaryExpression)
	| '!' unaryExpression -> ^('!' unaryExpression)
	| '~' unaryExpression -> ^('~' unaryExpression)
	| callOrIndexer	
	;
callOrIndexer
	: primaryExpression
	| braces;
	
primaryExpression
	: literalHex
	| place
	| callExpr
	| sliceExpr;

braces: '(' assigmentExpression ')';

callExpr: place '(' (assigmentExpression (',' assigmentExpression)*)? ')' -> ^(CALLEXPR place assigmentExpression*);
sliceExpr: place  '[' (assigmentExpression exprRange (exprRangeList)*)? ']' -> ^(SLICEEXPR place assigmentExpression? exprRange? exprRangeList*);
exprRangeList: (',' assigmentExpression exprRange?);
exprRange: '..' assigmentExpression;
place: IDENTIFIER -> ^(IDEN IDENTIFIER);

ASSIGNEQUAL: '=';
PLAS: '+';
MINUS: '-';
EndChar: ';';
LPAREN  : '(' ;
RPAREN  : ')' ; 
COMMA: ',';
ELSEW: 'else';

BOOL_LITERAL: 'true'|'false';

IDENTIFIER  :	('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'0'..'9'|'_')*;

CHAR:  '\'' ( ~('\'') ) '\'';
STR:  '"' ~('\\'|'"') | ('?'':''\\''.'~('\\'|'"')*)* '"';

HEX: '0' ('x' | 'X') HEX_DIGIT+;

fragment
HEX_DIGIT : ('0'..'9'|'a'..'f'|'A'..'F') ;

BITS: '0' ('b' | 'B') ('0' | '1')+;

DEC :	'0'..'9'+;

WS: (' '|'\r'|'\n'|'\t'|'\f')+ { $channel=HIDDEN; };

literalHex: HEX | literalDec;
literalDec: DEC | literalChar;
literalChar: CHAR | literalStr;
literalStr: STR | literalBool_lit;
literalBool_lit: BOOL_LITERAL | literalBits;
literalBits: BITS;

builtinInt: 'int' | builtinChar;
builtinChar: 'char' | builtinBool;
builtinBool: 'bool' | builtinByte;
builtinByte: 'byte' | builtinUint;
builtinUint: 'uint' | builtinLong;
builtinLong: 'long' | builtinUlong;
builtinUlong: 'ulong' | builtinString;
builtinString: 'string';
