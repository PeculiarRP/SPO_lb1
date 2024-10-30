/** \file
 *  This C header file was generated by $ANTLR version 3.5.2
 *
 *     -  From the grammar source file : MyGram.g
 *     -                            On : 2024-10-30 20:46:51
 *     -                for the parser : MyGramParserParser
 *
 * Editing it, at least manually, is not wise.
 *
 * C language generator and runtime by Jim Idle, jimi|hereisanat|idle|dotgoeshere|ws.
 *
 *
 * The parser 
MyGramParser

has the callable functions (rules) shown below,
 * which will invoke the code for the associated rule in the source grammar
 * assuming that the input stream is pointing to a token/text stream that could begin
 * this rule.
 *
 * For instance if you call the first (topmost) rule in a parser grammar, you will
 * get the results of a full parse, but calling a rule half way through the grammar will
 * allow you to pass part of a full token stream to the parser, such as for syntax checking
 * in editors and so on.
 *
 * The parser entry points are called indirectly (by function pointer to function) via
 * a parser context typedef pMyGramParser, which is returned from a call to MyGramParserNew().
 *
 * The methods in pMyGramParser are  as follows:
 *
 *  - 
 MyGramParser_source_return
      pMyGramParser->source(pMyGramParser)
 *  - 
 MyGramParser_sourceItem_return
      pMyGramParser->sourceItem(pMyGramParser)
 *  - 
 MyGramParser_funcDef_return
      pMyGramParser->funcDef(pMyGramParser)
 *  - 
 MyGramParser_funcSignature_return
      pMyGramParser->funcSignature(pMyGramParser)
 *  - 
 MyGramParser_listArg_return
      pMyGramParser->listArg(pMyGramParser)
 *  - 
 MyGramParser_argSpec_return
      pMyGramParser->argSpec(pMyGramParser)
 *  - 
 MyGramParser_endTypeSpec_return
      pMyGramParser->endTypeSpec(pMyGramParser)
 *  - 
 MyGramParser_typeRef_return
      pMyGramParser->typeRef(pMyGramParser)
 *  - 
 MyGramParser_baseRef_return
      pMyGramParser->baseRef(pMyGramParser)
 *  - 
 MyGramParser_statement_return
      pMyGramParser->statement(pMyGramParser)
 *  - 
 MyGramParser_custom_return
      pMyGramParser->custom(pMyGramParser)
 *  - 
 MyGramParser_array_return
      pMyGramParser->array(pMyGramParser)
 *  - 
 MyGramParser_arraySpec_return
      pMyGramParser->arraySpec(pMyGramParser)
 *  - 
 MyGramParser_ifStatement_return
      pMyGramParser->ifStatement(pMyGramParser)
 *  - 
 MyGramParser_elseClause_return
      pMyGramParser->elseClause(pMyGramParser)
 *  - 
 MyGramParser_loopStatement_return
      pMyGramParser->loopStatement(pMyGramParser)
 *  - 
 MyGramParser_loopHeader_return
      pMyGramParser->loopHeader(pMyGramParser)
 *  - 
 MyGramParser_repeat_return
      pMyGramParser->repeat(pMyGramParser)
 *  - 
 MyGramParser_loopWhile_return
      pMyGramParser->loopWhile(pMyGramParser)
 *  - 
 MyGramParser_loopUntil_return
      pMyGramParser->loopUntil(pMyGramParser)
 *  - 
 MyGramParser_breakStatement_return
      pMyGramParser->breakStatement(pMyGramParser)
 *  - 
 MyGramParser_expression_return
      pMyGramParser->expression(pMyGramParser)
 *  - 
 MyGramParser_block_return
      pMyGramParser->block(pMyGramParser)
 *  - 
 MyGramParser_blockParam_return
      pMyGramParser->blockParam(pMyGramParser)
 *  - 
 MyGramParser_expr_return
      pMyGramParser->expr(pMyGramParser)
 *  - 
 MyGramParser_assigmentExpression_return
      pMyGramParser->assigmentExpression(pMyGramParser)
 *  - 
 MyGramParser_logicalOrExpression_return
      pMyGramParser->logicalOrExpression(pMyGramParser)
 *  - 
 MyGramParser_logicalAndExpression_return
      pMyGramParser->logicalAndExpression(pMyGramParser)
 *  - 
 MyGramParser_inclusiveOrExpression_return
      pMyGramParser->inclusiveOrExpression(pMyGramParser)
 *  - 
 MyGramParser_exclusiveOrExpression_return
      pMyGramParser->exclusiveOrExpression(pMyGramParser)
 *  - 
 MyGramParser_andExpression_return
      pMyGramParser->andExpression(pMyGramParser)
 *  - 
 MyGramParser_equalityExpression_return
      pMyGramParser->equalityExpression(pMyGramParser)
 *  - 
 MyGramParser_relationalExpression_return
      pMyGramParser->relationalExpression(pMyGramParser)
 *  - 
 MyGramParser_shiftExpression_return
      pMyGramParser->shiftExpression(pMyGramParser)
 *  - 
 MyGramParser_additivePlusExpression_return
      pMyGramParser->additivePlusExpression(pMyGramParser)
 *  - 
 MyGramParser_multiplicativeExpression_return
      pMyGramParser->multiplicativeExpression(pMyGramParser)
 *  - 
 MyGramParser_unaryExpression_return
      pMyGramParser->unaryExpression(pMyGramParser)
 *  - 
 MyGramParser_callOrIndexer_return
      pMyGramParser->callOrIndexer(pMyGramParser)
 *  - 
 MyGramParser_primaryExpression_return
      pMyGramParser->primaryExpression(pMyGramParser)
 *  - 
 MyGramParser_braces_return
      pMyGramParser->braces(pMyGramParser)
 *  - 
 MyGramParser_callExpr_return
      pMyGramParser->callExpr(pMyGramParser)
 *  - 
 MyGramParser_sliceExpr_return
      pMyGramParser->sliceExpr(pMyGramParser)
 *  - 
 MyGramParser_exprRangeList_return
      pMyGramParser->exprRangeList(pMyGramParser)
 *  - 
 MyGramParser_exprRange_return
      pMyGramParser->exprRange(pMyGramParser)
 *  - 
 MyGramParser_place_return
      pMyGramParser->place(pMyGramParser)
 *  - 
 MyGramParser_literalHex_return
      pMyGramParser->literalHex(pMyGramParser)
 *  - 
 MyGramParser_literalDec_return
      pMyGramParser->literalDec(pMyGramParser)
 *  - 
 MyGramParser_literalChar_return
      pMyGramParser->literalChar(pMyGramParser)
 *  - 
 MyGramParser_literalStr_return
      pMyGramParser->literalStr(pMyGramParser)
 *  - 
 MyGramParser_literalBool_lit_return
      pMyGramParser->literalBool_lit(pMyGramParser)
 *  - 
 MyGramParser_literalBits_return
      pMyGramParser->literalBits(pMyGramParser)
 *  - 
 MyGramParser_builtinInt_return
      pMyGramParser->builtinInt(pMyGramParser)
 *  - 
 MyGramParser_builtinChar_return
      pMyGramParser->builtinChar(pMyGramParser)
 *  - 
 MyGramParser_builtinBool_return
      pMyGramParser->builtinBool(pMyGramParser)
 *  - 
 MyGramParser_builtinByte_return
      pMyGramParser->builtinByte(pMyGramParser)
 *  - 
 MyGramParser_builtinUint_return
      pMyGramParser->builtinUint(pMyGramParser)
 *  - 
 MyGramParser_builtinLong_return
      pMyGramParser->builtinLong(pMyGramParser)
 *  - 
 MyGramParser_builtinUlong_return
      pMyGramParser->builtinUlong(pMyGramParser)
 *  - 
 MyGramParser_builtinString_return
      pMyGramParser->builtinString(pMyGramParser)
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 *
 * The return type for any particular rule is of course determined by the source
 * grammar file.
 */
// [The "BSD license"]
// Copyright (c) 2005-2009 Jim Idle, Temporal Wave LLC
// http://www.temporal-wave.com
// http://www.linkedin.com/in/jimidle
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. The name of the author may not be used to endorse or promote products
//    derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef	_MyGramParser_H
#define _MyGramParser_H
/* =============================================================================
 * Standard antlr3 C runtime definitions
 */
#include    <antlr3.h>

/* End of standard antlr 3 runtime definitions
 * =============================================================================
 */

#ifdef __cplusplus
extern "C" {
#endif

// Forward declare the context typedef so that we can use it before it is
// properly defined. Delegators and delegates (from import statements) are
// interdependent and their context structures contain pointers to each other
// C only allows such things to be declared if you pre-declare the typedef.
//
typedef struct MyGramParser_Ctx_struct MyGramParser, * pMyGramParser;



	#include <assert.h>


#ifdef	ANTLR3_WINDOWS
// Disable: Unreferenced parameter,							- Rules with parameters that are not used
//          constant conditional,							- ANTLR realizes that a prediction is always true (synpred usually)
//          initialized but unused variable					- tree rewrite variables declared but not needed
//          Unreferenced local variable						- lexer rule declares but does not always use _type
//          potentially unitialized variable used			- retval always returned from a rule
//			unreferenced local function has been removed	- susually getTokenNames or freeScope, they can go without warnigns
//
// These are only really displayed at warning level /W4 but that is the code ideal I am aiming at
// and the codegen must generate some of these warnings by necessity, apart from 4100, which is
// usually generated when a parser rule is given a parameter that it does not use. Mostly though
// this is a matter of orthogonality hence I disable that one.
//
#pragma warning( disable : 4100 )
#pragma warning( disable : 4101 )
#pragma warning( disable : 4127 )
#pragma warning( disable : 4189 )
#pragma warning( disable : 4505 )
#pragma warning( disable : 4701 )
#endif

/* ========================
 * BACKTRACKING IS ENABLED
 * ========================
 */

typedef struct MyGramParser_source_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_source_return;



typedef struct MyGramParser_sourceItem_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_sourceItem_return;



typedef struct MyGramParser_funcDef_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_funcDef_return;



typedef struct MyGramParser_funcSignature_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_funcSignature_return;



typedef struct MyGramParser_listArg_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_listArg_return;



typedef struct MyGramParser_argSpec_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_argSpec_return;



typedef struct MyGramParser_endTypeSpec_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_endTypeSpec_return;



typedef struct MyGramParser_typeRef_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_typeRef_return;



typedef struct MyGramParser_baseRef_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_baseRef_return;



typedef struct MyGramParser_statement_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_statement_return;



typedef struct MyGramParser_custom_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_custom_return;



typedef struct MyGramParser_array_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_array_return;



typedef struct MyGramParser_arraySpec_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_arraySpec_return;



typedef struct MyGramParser_ifStatement_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_ifStatement_return;



typedef struct MyGramParser_elseClause_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_elseClause_return;



typedef struct MyGramParser_loopStatement_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_loopStatement_return;



typedef struct MyGramParser_loopHeader_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_loopHeader_return;



typedef struct MyGramParser_repeat_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_repeat_return;



typedef struct MyGramParser_loopWhile_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_loopWhile_return;



typedef struct MyGramParser_loopUntil_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_loopUntil_return;



typedef struct MyGramParser_breakStatement_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_breakStatement_return;



typedef struct MyGramParser_expression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_expression_return;



typedef struct MyGramParser_block_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_block_return;



typedef struct MyGramParser_blockParam_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_blockParam_return;



typedef struct MyGramParser_expr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_expr_return;



typedef struct MyGramParser_assigmentExpression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_assigmentExpression_return;



typedef struct MyGramParser_logicalOrExpression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_logicalOrExpression_return;



typedef struct MyGramParser_logicalAndExpression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_logicalAndExpression_return;



typedef struct MyGramParser_inclusiveOrExpression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_inclusiveOrExpression_return;



typedef struct MyGramParser_exclusiveOrExpression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_exclusiveOrExpression_return;



typedef struct MyGramParser_andExpression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_andExpression_return;



typedef struct MyGramParser_equalityExpression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_equalityExpression_return;



typedef struct MyGramParser_relationalExpression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_relationalExpression_return;



typedef struct MyGramParser_shiftExpression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_shiftExpression_return;



typedef struct MyGramParser_additivePlusExpression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_additivePlusExpression_return;



typedef struct MyGramParser_multiplicativeExpression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_multiplicativeExpression_return;



typedef struct MyGramParser_unaryExpression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_unaryExpression_return;



typedef struct MyGramParser_callOrIndexer_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_callOrIndexer_return;



typedef struct MyGramParser_primaryExpression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_primaryExpression_return;



typedef struct MyGramParser_braces_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_braces_return;



typedef struct MyGramParser_callExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_callExpr_return;



typedef struct MyGramParser_sliceExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_sliceExpr_return;



typedef struct MyGramParser_exprRangeList_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_exprRangeList_return;



typedef struct MyGramParser_exprRange_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_exprRange_return;



typedef struct MyGramParser_place_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_place_return;



typedef struct MyGramParser_literalHex_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_literalHex_return;



typedef struct MyGramParser_literalDec_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_literalDec_return;



typedef struct MyGramParser_literalChar_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_literalChar_return;



typedef struct MyGramParser_literalStr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_literalStr_return;



typedef struct MyGramParser_literalBool_lit_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_literalBool_lit_return;



typedef struct MyGramParser_literalBits_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_literalBits_return;



typedef struct MyGramParser_builtinInt_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_builtinInt_return;



typedef struct MyGramParser_builtinChar_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_builtinChar_return;



typedef struct MyGramParser_builtinBool_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_builtinBool_return;



typedef struct MyGramParser_builtinByte_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_builtinByte_return;



typedef struct MyGramParser_builtinUint_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_builtinUint_return;



typedef struct MyGramParser_builtinLong_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_builtinLong_return;



typedef struct MyGramParser_builtinUlong_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_builtinUlong_return;



typedef struct MyGramParser_builtinString_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    MyGramParser_builtinString_return;




/** Context tracking structure for 
MyGramParser

 */
struct MyGramParser_Ctx_struct
{
    /** Built in ANTLR3 context tracker contains all the generic elements
     *  required for context tracking.
     */
    pANTLR3_PARSER   pParser;

     MyGramParser_source_return
     (*source)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_sourceItem_return
     (*sourceItem)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_funcDef_return
     (*funcDef)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_funcSignature_return
     (*funcSignature)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_listArg_return
     (*listArg)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_argSpec_return
     (*argSpec)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_endTypeSpec_return
     (*endTypeSpec)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_typeRef_return
     (*typeRef)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_baseRef_return
     (*baseRef)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_statement_return
     (*statement)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_custom_return
     (*custom)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_array_return
     (*array)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_arraySpec_return
     (*arraySpec)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_ifStatement_return
     (*ifStatement)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_elseClause_return
     (*elseClause)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_loopStatement_return
     (*loopStatement)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_loopHeader_return
     (*loopHeader)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_repeat_return
     (*repeat)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_loopWhile_return
     (*loopWhile)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_loopUntil_return
     (*loopUntil)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_breakStatement_return
     (*breakStatement)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_expression_return
     (*expression)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_block_return
     (*block)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_blockParam_return
     (*blockParam)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_expr_return
     (*expr)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_assigmentExpression_return
     (*assigmentExpression)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_logicalOrExpression_return
     (*logicalOrExpression)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_logicalAndExpression_return
     (*logicalAndExpression)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_inclusiveOrExpression_return
     (*inclusiveOrExpression)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_exclusiveOrExpression_return
     (*exclusiveOrExpression)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_andExpression_return
     (*andExpression)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_equalityExpression_return
     (*equalityExpression)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_relationalExpression_return
     (*relationalExpression)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_shiftExpression_return
     (*shiftExpression)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_additivePlusExpression_return
     (*additivePlusExpression)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_multiplicativeExpression_return
     (*multiplicativeExpression)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_unaryExpression_return
     (*unaryExpression)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_callOrIndexer_return
     (*callOrIndexer)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_primaryExpression_return
     (*primaryExpression)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_braces_return
     (*braces)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_callExpr_return
     (*callExpr)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_sliceExpr_return
     (*sliceExpr)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_exprRangeList_return
     (*exprRangeList)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_exprRange_return
     (*exprRange)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_place_return
     (*place)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_literalHex_return
     (*literalHex)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_literalDec_return
     (*literalDec)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_literalChar_return
     (*literalChar)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_literalStr_return
     (*literalStr)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_literalBool_lit_return
     (*literalBool_lit)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_literalBits_return
     (*literalBits)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_builtinInt_return
     (*builtinInt)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_builtinChar_return
     (*builtinChar)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_builtinBool_return
     (*builtinBool)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_builtinByte_return
     (*builtinByte)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_builtinUint_return
     (*builtinUint)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_builtinLong_return
     (*builtinLong)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_builtinUlong_return
     (*builtinUlong)	(struct MyGramParser_Ctx_struct * ctx);

     MyGramParser_builtinString_return
     (*builtinString)	(struct MyGramParser_Ctx_struct * ctx);

     ANTLR3_BOOLEAN
     (*synpred12_MyGram)	(struct MyGramParser_Ctx_struct * ctx);

     ANTLR3_BOOLEAN
     (*synpred14_MyGram)	(struct MyGramParser_Ctx_struct * ctx);

     ANTLR3_BOOLEAN
     (*synpred15_MyGram)	(struct MyGramParser_Ctx_struct * ctx);

     ANTLR3_BOOLEAN
     (*synpred36_MyGram)	(struct MyGramParser_Ctx_struct * ctx);

     ANTLR3_BOOLEAN
     (*synpred37_MyGram)	(struct MyGramParser_Ctx_struct * ctx);

     ANTLR3_BOOLEAN
     (*synpred47_MyGram)	(struct MyGramParser_Ctx_struct * ctx);

     ANTLR3_BOOLEAN
     (*synpred48_MyGram)	(struct MyGramParser_Ctx_struct * ctx);
    // Delegated rules

    const char * (*getGrammarFileName)();
    void            (*reset)  (struct MyGramParser_Ctx_struct * ctx);
    void	    (*free)   (struct MyGramParser_Ctx_struct * ctx);
/* @headerFile.members() */
pANTLR3_BASE_TREE_ADAPTOR	adaptor;
pANTLR3_VECTOR_FACTORY		vectors;
/* End @headerFile.members() */
};

// Function protoypes for the constructor functions that external translation units
// such as delegators and delegates may wish to call.
//
ANTLR3_API pMyGramParser MyGramParserNew         (
pANTLR3_COMMON_TOKEN_STREAM
 instream);
ANTLR3_API pMyGramParser MyGramParserNewSSD      (
pANTLR3_COMMON_TOKEN_STREAM
 instream, pANTLR3_RECOGNIZER_SHARED_STATE state);

/** Symbolic definitions of all the tokens that the 
parser
 will work with.
 * \{
 *
 * Antlr will define EOF, but we can't use that as it it is too common in
 * in C header files and that would be confusing. There is no way to filter this out at the moment
 * so we just undef it here for now. That isn't the value we get back from C recognizers
 * anyway. We are looking for ANTLR3_TOKEN_EOF.
 */
#ifdef	EOF
#undef	EOF
#endif
#ifdef	Tokens
#undef	Tokens
#endif
#define EOF      -1
#define T__44      44
#define T__45      45
#define T__46      46
#define T__47      47
#define T__48      48
#define T__49      49
#define T__50      50
#define T__51      51
#define T__52      52
#define T__53      53
#define T__54      54
#define T__55      55
#define T__56      56
#define T__57      57
#define T__58      58
#define T__59      59
#define T__60      60
#define T__61      61
#define T__62      62
#define T__63      63
#define T__64      64
#define T__65      65
#define T__66      66
#define T__67      67
#define T__68      68
#define T__69      69
#define T__70      70
#define T__71      71
#define T__72      72
#define T__73      73
#define T__74      74
#define T__75      75
#define T__76      76
#define T__77      77
#define T__78      78
#define T__79      79
#define T__80      80
#define T__81      81
#define T__82      82
#define T__83      83
#define T__84      84
#define ARG      4
#define ARGS      5
#define ARRAY      6
#define ASSIGNEQUAL      7
#define BITS      8
#define BLOCKSTATEMENT      9
#define BOOL_LITERAL      10
#define BREAKSTATEMENT      11
#define BUILTIN      12
#define CALLEXPR      13
#define CHAR      14
#define COMMA      15
#define CUSTOM      16
#define DEC      17
#define ELSEW      18
#define EXPR      19
#define EXPSTATEMENT      20
#define EndChar      21
#define FUNCDEF      22
#define FUNCSIGNATURE      23
#define HEX      24
#define HEX_DIGIT      25
#define IDEN      26
#define IDENTIFIER      27
#define IFSTATEMENT      28
#define LISTARG      29
#define LOOPSTATEMENT      30
#define LPAREN      31
#define MINUS      32
#define PLAS      33
#define REPEATSTATEMENT      34
#define RPAREN      35
#define SLICEEXPR      36
#define SOURCE      37
#define SOURCEITEM      38
#define ST      39
#define STATEMENT      40
#define STR      41
#define TYPEREF      42
#define WS      43
#ifdef	EOF
#undef	EOF
#define	EOF	ANTLR3_TOKEN_EOF
#endif

#ifndef TOKENSOURCE
#define TOKENSOURCE(lxr) lxr->pLexer->rec->state->tokSource
#endif

/* End of token definitions for MyGramParser
 * =============================================================================
 */
/** } */

#ifdef __cplusplus
}
#endif

#endif

/* END - Note:Keep extra line feed to satisfy UNIX systems */
