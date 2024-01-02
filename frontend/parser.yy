/**
 * Grammar file for Bison tool for Proto-typed language
 * @copyright Marek Sedlacek, 2024
 */

/* Since new constructs are used, newer version is needed */
%require "3.7"
/* Use C++ parser */
%language "c++"
%skeleton "lalr1.cc"

%defines
/* Set namespace used */
%define api.namespace { ptc }
/* Parser class */
%define api.parser.class { Parser }
%define api.location.file none
%define api.token.raw

/* Forward declarations */
%code requires {
    namespace ptc {
        class Scanner;
        namespace ir {
            class IR;
            class Expr;
            class FormalParamDecl;
        }
        namespace diag {
        }
    }

    #include <map>

    #ifndef YY_NULLPTR
        #if defined __cplusplus && 201103L <= __cplusplus
            #define YY_NULLPTR nullptr
        #else
            #define YY_NULLPTR 0
        #endif
    #endif
}

/* Setup parser params */
%parse-param { Scanner *scanner }

/* Includes */
%code {

    #include <map>
    #include <cmath>
    #include <sstream>
    #include <vector>
    #include "scanner.hpp"
    #include "logging.hpp"
    #include "ir.hpp"
    #include "diagnostics.def"

    // Set correct token method
    #undef yylex
    #define yylex scanner->yylex
}

%define api.value.type variant
//%define parse.assert
%define parse.error verbose

/* Tokens */
/* Control */
%token END_FILE 0 "end of file"
%token END "terminator (\\n or ;)"

/* Types */
%token <long> INT "int"
%token <double> FLOAT "float"
%token <std::string> STRING "string"
%token <bool> BOOL "bool"
%token NONE "none" // TODO: Add type

/* Operators */
%token LPAR "("
%token RPAR ")"
%token LSQ "["
%token RSQ "]"
%token LBR "{"
%token RBR "}"
%token PLUS "+"
%token MINUS "-"
%token MUL "*"
%token DIV "/"
%token MOD "%"
%token POW "**"
%token CONCAT "++"

%token LAND "and"
%token LOR "or"
%token LNOT "not"
%token IN "in"
%token AS "as"

%token BAND "&"
%token BOR "|"
%token BXOR "^"
%token BNOT "~"
%token BLSHFT "<<"
%token BRSHFT ">>"

%token EQ "=="
%token NEQ "!="
%token BT ">"
%token LT "<"
%token BEQ ">="
%token LEQ "<="

%token RANGE ".."

%token DOT "."
%token COMMA ","
%token COLON ":"

%token SET "="
%token SETCONCAT "++="
%token SETPOW "**="
%token SETMOD "%="
%token SETDIV "/="
%token SETMUL "*="
%token SETMINUS "-="
%token SETPLUS "+="
%token SETBAND "&="
%token SETBOR "|="
%token SETBXOR "^="
%token SETBNOT "~="
%token SETBLSHFT "<<="
%token SETBRSHFT ">>="

/* Keywords */
%token KWVAR "var"
%token KWANY "any"
%token KWIMPORT "import"
%token KWIF "if"
%token KWELSE "else"
%token KWFOR "for"
%token KWWHILE "while"
%token KWDO "do"
%token KWRETURN "return"
%token KWBREAK "break"
%token KWCONTINUE "continue"
%token KWCONST "const"
%token KWMAYBE "?"
%token KWINT "'int'"
%token KWFLOAT "'float'"
%token KWSTRING "'string'"
%token KWBOOL "'bool'"
%token KWSTRUCT "'struct'"
%token KWVOID "'void'"
%token KWRANGE "'range'"

/* Identifiers */
%token <std::string> ID "identifier"
%token <std::string> EXT_ID "external identifier"

/* Associativity and precedence */
%right SET
%left CONCAT
%left LOR
%left LAND
%left IN
%left BOR
%left BXOR
%left BAND
%left EQ NEQ
%left BT BEQ LT LEQ
%left RANGE
%left BLSHFT BRSHFT
%left PLUS MINUS
%left MUL DIV MOD
%right POW
%right LNOT BNOT
%left DOT
%left AS

%precedence INT
%precedence FLOAT

%precedence NEG

// Terminal types
%type <long> expr_int
%type <double> expr_float
%type <std::string> expr_str
%type <std::string> fun_id
%type <bool> expr_bool

%type <ptc::ir::IR *> type
%type <ptc::ir::IR *> funtype
%type <ptc::ir::IR *> mattype
%type <ptc::ir::IR *> vardecl
%type <ptc::ir::IR *> vardef
%type <ptc::ir::IR *> stmts_ne
%type <ptc::ir::IR *> if
%type <ptc::ir::IR *> while
%type <ptc::ir::IR *> for
%type <ptc::ir::IR *> dowhile
%type <ptc::ir::IR *> stmts
%type <ptc::ir::IR *> function
%type <ptc::ir::IR *> return
%type <ptc::ir::IR *> flowctl
%type <ptc::ir::IR *> import
%type <ptc::ir::IR *> struct
%type <ptc::ir::IR *> declistval
%type <ptc::ir::Expr *> expr
%type <ptc::ir::Expr *> int_val
%type <ptc::ir::Expr *> expr_var
%type <ptc::ir::Expr *> expr_mat
%type <ptc::ir::Expr *> expr_struct
%type <ptc::ir::Expr *> expr_none
%type <ptc::ir::Expr *> set
%type <ptc::ir::Expr *> matrix
%type <ptc::ir::Expr *> range
%type <ptc::ir::Expr *> slice
%type <std::vector<ptc::ir::Expr *> > callarglist
%type <std::vector<ptc::ir::Expr *> > matsq
%type <std::vector<ptc::ir::Expr *> > matvals
%type <std::map<std::string, ptc::ir::Expr *> > struct_val
%type <std::map<std::string, ptc::ir::Expr *> > struct_list
%type <std::vector<ptc::ir::IR *> > scope_body
%type <std::vector<ptc::ir::IR *> > block
%type <std::vector<ptc::ir::IR *> > else
%type <std::vector<ptc::ir::IR *> > stmt
%type <std::vector<ptc::ir::IR *> > decllist
%type <std::vector<ptc::ir::IR *> > typelist
%type <std::vector<std::string> > id_list
%type <std::vector<ptc::ir::FormalParamDecl *> > funargs
%type <std::vector<ptc::ir::FormalParamDecl *> > funargsnvar

%locations

%%

// Start
start : END_FILE        { scanner->parseEntry(std::vector<ptc::ir::IR *>{}); }
      | stmt END_FILE   { scanner->parseEntry($1); }
      ;
stmt : stmts            { $$ = scanner->parseStmtBody($1); }
     | stmt stmts       { $$ = scanner->parseStmtBodyAdd($1, $2); }
     | stmt error stmts { $$ = scanner->parseStmtBodyAdd($1, $3); }
     ;

stmt_end : END
         | END_FILE
         ;
// Statements
stmts : END      { $$ = nullptr; }
      | stmts_ne { $$ = $1; }
      ;
stmts_ne : set stmt_end      { $$ = scanner->parseExprStmt($1); }
         | vardecl stmt_end  { $$ = $1; }
         | vardef stmt_end   { $$ = $1; }
         | import stmt_end   { $$ = $1; }
         | for          { $$ = $1; }
         | if           { $$ = $1; }
         | while        { $$ = $1; }
         | dowhile      { $$ = $1; }
         | struct       { $$ = $1; }
         | function     { $$ = $1; }
         | flowctl stmt_end  { $$ = $1; }
         | expr stmt_end     { $$ = scanner->parseExprStmt($1); }
         ;

// Code block
block : LBR RBR                 { $$ = scanner->parseStmtBody(nullptr); }
      | LBR stmt RBR            { $$ = $2; }
      | END LBR stmt RBR        { $$ = $3; }
      | LBR stmt RBR END        { $$ = $2; }
      | END LBR stmt RBR END    { $$ = $3; }
      ;
// Code block or single statement
scope_body : stmts_ne { $$ = scanner->parseStmtBody($1); scanner->leaveScope(); }
           | block    { $$ = $1; scanner->leaveScope(); }
           ;

// Import
import : KWIMPORT id_list   { $$ = scanner->parseImports($2); }
       ;
id_list : ID                { $$ = scanner->parseImportName($1); }
        | ID COMMA id_list  { $$ = scanner->parseAddImportName($3, $1); }
        ;

// Flow controll
flowctl : KWBREAK       { $$ = scanner->parseBreak(); }
        | KWCONTINUE    { $$ = scanner->parseContinue(); }
        | return        { $$ = $1; }
        ;
return : KWRETURN       { $$ = scanner->parseReturn(nullptr); }
       | KWRETURN expr  { $$ = scanner->parseReturn($2); }
       ;

// For loop
for : for_kw LPAR vardecl COLON expr RPAR scope_body  { $$ = scanner->parseForeach($3, $5, $7); }
    | for_kw LPAR ID COLON expr RPAR scope_body       { $$ = scanner->parseForeach(scanner->parseVar($3), $5, $7); }
    | for_kw LPAR EXT_ID COLON expr RPAR scope_body   { $$ = scanner->parseForeach(scanner->parseVar($3), $5, $7); }
    | for_kw LPAR vardecl COLON range RPAR scope_body { $$ = scanner->parseForeach($3, $5, $7); }
    | for_kw LPAR ID COLON range RPAR scope_body      { $$ = scanner->parseForeach(scanner->parseVar($3), $5, $7); }
    | for_kw LPAR EXT_ID COLON range RPAR scope_body  { $$ = scanner->parseForeach(scanner->parseVar($3), $5, $7); }
    ;
for_kw : KWFOR { scanner->enterBlockScope(); }

// While loop
while : wh_kw LPAR expr RPAR scope_body { $$ = scanner->parseWhile($3, $5); }
      ;
wh_kw : KWWHILE { scanner->enterBlockScope(); }
// Do while
dowhile : do_kw scope_body KWWHILE LPAR expr RPAR { $$ = scanner->parseDoWhile($5, $2); }
        ;
do_kw : KWDO { scanner->enterBlockScope(); }

// If-else statement (works also as else if)
if : if_kw LPAR expr RPAR scope_body else { $$ = scanner->parseIfStmt($3, $5, $6); }
   ;
else : el_kw scope_body  { $$ = $2; }
     |                   { $$ = scanner->parseStmtBody(nullptr); }
     ;
if_kw : KWIF { scanner->enterBlockScope(); }
el_kw : KWELSE { scanner->enterBlockScope(); }

// Struct definition
struct : KWSTRUCT ID LBR RBR              { $$ = scanner->parseStruct($2, std::vector<ptc::ir::IR *>{}); }
       | KWSTRUCT ID LBR decllist RBR     { $$ = scanner->parseStruct($2, $4); }
       | KWSTRUCT ID END LBR decllist RBR { $$ = scanner->parseStruct($2, $5); }
       ;
decllist : END
         | END decllist            { $$ = $2; }
         | declistval END          { $$ = scanner->parseAddStructElement($1, std::vector<ptc::ir::IR *>{}); }
         | declistval END decllist { $$ = scanner->parseAddStructElement($1, $3); }
         ;
declistval : type ID            { $$ = scanner->parseStructElement($1, $2, nullptr); }
           | type ID SET expr   { $$ = scanner->parseStructElement($1, $2, $4); }
           ;

// Function definition
function : type fun_id LPAR RPAR block           { $$ = scanner->parseFun($1, $2, std::vector<ptc::ir::FormalParamDecl *>{}, $5); }
         | type fun_id LPAR funargs RPAR block   { $$ = scanner->parseFun($1, $2, $4, $6); }
         | KWVOID fun_id LPAR RPAR block         { $$ = scanner->parseFun(scanner->sym_lookup(VOID_CSTR), $2, std::vector<ptc::ir::FormalParamDecl *>{}, $5); }
         | KWVOID fun_id LPAR funargs RPAR block { $$ = scanner->parseFun(scanner->sym_lookup(VOID_CSTR), $2, $4, $6); }
         ;
fun_id : ID { scanner->enterFunScope(); $$ = $1; }
       ;
funargsnvar : type ID                   { $$ = scanner->parseFunParam($1, $2); }
            | funargsnvar COMMA type ID { $$ = scanner->parseAddFunParam($1, $3, $4); }
            ;
funargs : RANGE ID                      { $$ = scanner->parseFunParam(scanner->sym_lookup(VARARGS_CSTR, false, true), $2); }
        | funargsnvar COMMA RANGE ID    { $$ = $$ = scanner->parseAddFunParam($1, scanner->sym_lookup(VARARGS_CSTR, false, true), $4);}
        | funargsnvar                   { $$ = $1; }
        ;
         

// Variable declaration
vardecl : type ID { $$ = scanner->parseVarDecl($1, $2); }
        ;

// Definition
vardef : type ID SET expr        { $$ = scanner->parseVarDecl($1, $2, $4); }
       | KWVAR ID SET expr       { $$ = scanner->parseVarDecl(nullptr, $2, $4); }
       //| type KWCONST ID SET expr
       //| KWVAR KWCONST ID SET expr
       ;

// Assignment and compound assignment
set : expr SETCONCAT expr { $$ = scanner->parseInfixExpr($1, scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_CONCAT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
    | expr SETPOW expr    { $$ = scanner->parseInfixExpr($1, scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_POW)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
    | expr SETMOD expr    { $$ = scanner->parseInfixExpr($1, scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_MOD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
    | expr SETDIV expr    { $$ = scanner->parseInfixExpr($1, scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_DIV)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
    | expr SETMUL expr    { $$ = scanner->parseInfixExpr($1, scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_MUL)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
    | expr SETMINUS expr  { $$ = scanner->parseInfixExpr($1, scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_SUB)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
    | expr SETPLUS expr   { $$ = scanner->parseInfixExpr($1, scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_ADD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
    | expr SETBAND expr   { $$ = scanner->parseInfixExpr($1, scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_BAND)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
    | expr SETBOR expr    { $$ = scanner->parseInfixExpr($1, scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_BOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
    | expr SETBXOR expr   { $$ = scanner->parseInfixExpr($1, scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_BXOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
    | expr SETBLSHFT expr { $$ = scanner->parseInfixExpr($1, scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_BLSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
    | expr SETBRSHFT expr { $$ = scanner->parseInfixExpr($1, scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_BRSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
    | expr SET expr       { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
    | expr SET set        { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
    ;

// Function call arguments
callarglist : expr                    { $$ = scanner->parseFunCallArg($1); }
            | callarglist COMMA expr  { $$ = scanner->parseAddFunCallArg($1, $3); }
            ;

// Expressions
expr : expr_mat     { $$ = $1; }
     | expr_var     { $$ = $1; }
     | expr_none    { $$ = $1; }
     | expr_struct  { $$ = $1; }
     | expr_int     { $$ = scanner->parseInt($1); }
     | expr_float   { $$ = scanner->parseFloat($1); }
     | expr_str     { $$ = scanner->parseString($1); }
     | expr_bool    { $$ = scanner->parseBool($1); }
     ;

expr_var : ID { $$ = scanner->parseVar($1); }
         | EXT_ID { $$ = scanner->parseVar($1, true); }
         | MINUS ID %prec NEG { $$ = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar($2), ir::Operator(ir::OperatorKind::OP_SUB)); }
         | MINUS EXT_ID %prec NEG { $$ = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar($2, true), ir::Operator(ir::OperatorKind::OP_SUB)); }
         | LPAR expr_var RPAR { $$ = $2; }

         | expr_var LPAR RPAR             { $$ = scanner->parseFunCall($1, std::vector<ptc::ir::Expr *>{}); }
         | expr_var LPAR callarglist RPAR { $$ = scanner->parseFunCall($1, $3); }

         | expr_str LSQ int_val RSQ { $$ = scanner->parseInfixExpr(scanner->parseString($1), $3, ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
         | expr_mat LSQ int_val RSQ { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
         | ID LSQ int_val RSQ       { $$ = scanner->parseInfixExpr(scanner->parseVar($1), $3, ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
         | EXT_ID LSQ int_val RSQ   { $$ = scanner->parseInfixExpr(scanner->parseVar($1), $3, ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
         | expr_var LSQ int_val RSQ { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_SUBSCR)); }

         | ID AS EXT_ID       { $$ = scanner->parseInfixExpr(scanner->parseVar($1), scanner->parseVar(scanner->parseExtType($3, false)->getName(), true, false), ir::Operator(ir::OperatorKind::OP_AS)); }
         | EXT_ID AS EXT_ID   { $$ = scanner->parseInfixExpr(scanner->parseVar($1, true), scanner->parseVar(scanner->parseExtType($3, false)->getName(), true, false), ir::Operator(ir::OperatorKind::OP_AS)); }
         | expr_var AS EXT_ID { $$ = scanner->parseInfixExpr($1, scanner->parseVar(scanner->parseExtType($3, false)->getName(), true, false), ir::Operator(ir::OperatorKind::OP_AS)); }
         | ID AS EXT_ID KWMAYBE       { $$ = scanner->parseInfixExpr(scanner->parseVar($1), scanner->parseVar(scanner->parseExtType($3, true)->getName(), true, true), ir::Operator(ir::OperatorKind::OP_AS)); }
         | EXT_ID AS EXT_ID KWMAYBE   { $$ = scanner->parseInfixExpr(scanner->parseVar($1, true), scanner->parseVar(scanner->parseExtType($3, true)->getName(), true, true), ir::Operator(ir::OperatorKind::OP_AS)); }
         | expr_var AS EXT_ID KWMAYBE { $$ = scanner->parseInfixExpr($1, scanner->parseVar(scanner->parseExtType($3, true)->getName(), true, true), ir::Operator(ir::OperatorKind::OP_AS)); }
         | ID AS type         { $$ = scanner->parseInfixExpr(scanner->parseVar($1), scanner->parseVar($3->getName(), false, llvm::dyn_cast<ptc::ir::TypeDecl>($3)->isMaybe()), ir::Operator(ir::OperatorKind::OP_AS)); }
         | EXT_ID AS type     { $$ = scanner->parseInfixExpr(scanner->parseVar($1, true), scanner->parseVar($3->getName(), false, llvm::dyn_cast<ptc::ir::TypeDecl>($3)->isMaybe()), ir::Operator(ir::OperatorKind::OP_AS)); }
         | expr_var AS type   { $$ = scanner->parseInfixExpr($1, scanner->parseVar($3->getName(), false, llvm::dyn_cast<ptc::ir::TypeDecl>($3)->isMaybe()), ir::Operator(ir::OperatorKind::OP_AS)); }

         | expr_mat slice   { $$ = scanner->parseInfixExpr($1, $2, ir::Operator(ir::OperatorKind::OP_SLICE)); }
         | ID slice         { $$ = scanner->parseInfixExpr(scanner->parseVar($1), $2, ir::Operator(ir::OperatorKind::OP_SLICE)); }
         | EXT_ID slice     { $$ = scanner->parseInfixExpr(scanner->parseVar($1, true), $2, ir::Operator(ir::OperatorKind::OP_SLICE)); }
         | expr_var slice   { $$ = scanner->parseInfixExpr($1, $2, ir::Operator(ir::OperatorKind::OP_SLICE)); }

         | expr_var DOT ID         { $$ = scanner->parseInfixExpr($1, scanner->parseVar($3), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
         | expr_var DOT EXT_ID     { $$ = scanner->parseInfixExpr($1, scanner->parseVar($3), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
         //| expr_var DOT expr_var   { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_ACCESS)); }

         | expr_float POW expr_var { $$ = scanner->parseInfixExpr(scanner->parseFloat($1), $3, ir::Operator(ir::OperatorKind::OP_POW)); }
         | expr_var POW expr_float { $$ = scanner->parseInfixExpr($1, scanner->parseFloat($3), ir::Operator(ir::OperatorKind::OP_POW)); }
         | expr_var POW expr_var   { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_POW)); }
         | expr_int POW expr_var   { $$ = scanner->parseInfixExpr(scanner->parseFloat($1) /*Float on purpose*/, $3, ir::Operator(ir::OperatorKind::OP_POW)); }
         | expr_var POW expr_int   { $$ = scanner->parseInfixExpr($1, scanner->parseFloat($3) /*Float on purpose*/, ir::Operator(ir::OperatorKind::OP_POW)); }

         | expr_int MUL expr_var   { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_MUL)); }
         | expr_float MUL expr_var { $$ = scanner->parseInfixExpr(scanner->parseFloat($1), $3, ir::Operator(ir::OperatorKind::OP_MUL)); }
         | expr_var MUL expr_int   { $$ = scanner->parseInfixExpr($1, scanner->parseInt($3), ir::Operator(ir::OperatorKind::OP_MUL)); }
         | expr_var MUL expr_float { $$ = scanner->parseInfixExpr($1, scanner->parseFloat($3), ir::Operator(ir::OperatorKind::OP_MUL)); }
         | expr_var MUL expr_var   { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_MUL)); }

         | expr_int DIV expr_var   { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_DIV)); }
         | expr_float DIV expr_var { $$ = scanner->parseInfixExpr(scanner->parseFloat($1), $3, ir::Operator(ir::OperatorKind::OP_DIV)); } 
         | expr_var DIV expr_int   { $$ = scanner->parseInfixExpr($1, scanner->parseInt($3), ir::Operator(ir::OperatorKind::OP_DIV)); }
         | expr_var DIV expr_float { $$ = scanner->parseInfixExpr($1, scanner->parseFloat($3), ir::Operator(ir::OperatorKind::OP_DIV)); }
         | expr_var DIV expr_var   { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_DIV)); }

         | expr_int MOD expr_var   { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_MOD)); }
         | expr_float MOD expr_var { $$ = scanner->parseInfixExpr(scanner->parseFloat($1), $3, ir::Operator(ir::OperatorKind::OP_MOD)); } 
         | expr_var MOD expr_int   { $$ = scanner->parseInfixExpr($1, scanner->parseInt($3), ir::Operator(ir::OperatorKind::OP_MOD)); }
         | expr_var MOD expr_float { $$ = scanner->parseInfixExpr($1, scanner->parseFloat($3), ir::Operator(ir::OperatorKind::OP_MOD)); }
         | expr_var MOD expr_var   { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_MOD)); }

         | expr_int PLUS expr_var   { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_ADD)); }
         | expr_float PLUS expr_var { $$ = scanner->parseInfixExpr(scanner->parseFloat($1), $3, ir::Operator(ir::OperatorKind::OP_ADD)); }
         | expr_var PLUS expr_int   { $$ = scanner->parseInfixExpr($1, scanner->parseInt($3), ir::Operator(ir::OperatorKind::OP_ADD)); }
         | expr_var PLUS expr_float { $$ = scanner->parseInfixExpr($1, scanner->parseFloat($3), ir::Operator(ir::OperatorKind::OP_ADD)); }
         | expr_mat PLUS expr_mat   { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_ADD)); }
         | expr_var PLUS expr_mat   { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_ADD)); }
         | expr_mat PLUS expr_var   { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_ADD)); }
         | expr_var PLUS expr_var   { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_ADD)); }

         | expr_int MINUS expr_var   { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_SUB)); } 
         | expr_float MINUS expr_var { $$ = scanner->parseInfixExpr(scanner->parseFloat($1), $3, ir::Operator(ir::OperatorKind::OP_SUB)); } 
         | expr_var MINUS expr_int   { $$ = scanner->parseInfixExpr($1, scanner->parseInt($3), ir::Operator(ir::OperatorKind::OP_SUB)); }
         | expr_var MINUS expr_float { $$ = scanner->parseInfixExpr($1, scanner->parseFloat($3), ir::Operator(ir::OperatorKind::OP_SUB)); } 
         | expr_var MINUS expr_var   { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_SUB)); }

         | expr_int BLSHFT expr_var { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
         | expr_var BLSHFT expr_int { $$ = scanner->parseInfixExpr($1, scanner->parseInt($3), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
         | expr_var BLSHFT expr_var { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_BLSHFT)); }                   

         | expr_int BRSHFT expr_var { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
         | expr_var BRSHFT expr_int { $$ = scanner->parseInfixExpr($1, scanner->parseInt($3), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
         | expr_var BRSHFT expr_var { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_BRSHFT)); }                   

         | expr_int BT expr_var   { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_BT)); }
         | expr_float BT expr_var { $$ = scanner->parseInfixExpr(scanner->parseFloat($1), $3, ir::Operator(ir::OperatorKind::OP_BT)); } 
         | expr_str BT expr_var   { $$ = scanner->parseInfixExpr(scanner->parseString($1), $3, ir::Operator(ir::OperatorKind::OP_BT)); } 
         | expr_var BT expr_int   { $$ = scanner->parseInfixExpr($1, scanner->parseInt($3), ir::Operator(ir::OperatorKind::OP_BT)); }
         | expr_var BT expr_float { $$ = scanner->parseInfixExpr($1, scanner->parseFloat($3), ir::Operator(ir::OperatorKind::OP_BT)); }
         | expr_var BT expr_str   { $$ = scanner->parseInfixExpr($1, scanner->parseString($3), ir::Operator(ir::OperatorKind::OP_BT)); }
         | expr_var BT expr_var   { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_BT)); }

         | expr_int BEQ expr_var   { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_BEQ)); }  
         | expr_float BEQ expr_var { $$ = scanner->parseInfixExpr(scanner->parseFloat($1), $3, ir::Operator(ir::OperatorKind::OP_BEQ)); }
         | expr_str BEQ expr_var   { $$ = scanner->parseInfixExpr(scanner->parseString($1), $3, ir::Operator(ir::OperatorKind::OP_BEQ)); }
         | expr_var BEQ expr_int   { $$ = scanner->parseInfixExpr($1, scanner->parseInt($3), ir::Operator(ir::OperatorKind::OP_BEQ)); }  
         | expr_var BEQ expr_float { $$ = scanner->parseInfixExpr($1, scanner->parseFloat($3), ir::Operator(ir::OperatorKind::OP_BEQ)); }
         | expr_var BEQ expr_str   { $$ = scanner->parseInfixExpr($1, scanner->parseString($3), ir::Operator(ir::OperatorKind::OP_BEQ)); }
         | expr_var BEQ expr_var   { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_BEQ)); }

         | expr_int LT expr_var   { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_LT)); }  
         | expr_float LT expr_var { $$ = scanner->parseInfixExpr(scanner->parseFloat($1), $3, ir::Operator(ir::OperatorKind::OP_LT)); }
         | expr_str LT expr_var   { $$ = scanner->parseInfixExpr(scanner->parseString($1), $3, ir::Operator(ir::OperatorKind::OP_LT)); }
         | expr_var LT expr_int   { $$ = scanner->parseInfixExpr($1, scanner->parseInt($3), ir::Operator(ir::OperatorKind::OP_LT)); }  
         | expr_var LT expr_float { $$ = scanner->parseInfixExpr($1, scanner->parseFloat($3), ir::Operator(ir::OperatorKind::OP_LT)); }
         | expr_var LT expr_str   { $$ = scanner->parseInfixExpr($1, scanner->parseString($3), ir::Operator(ir::OperatorKind::OP_LT)); }
         | expr_var LT expr_var   { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_LT)); }

         | expr_int LEQ expr_var   { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_LEQ)); }  
         | expr_float LEQ expr_var { $$ = scanner->parseInfixExpr(scanner->parseFloat($1), $3, ir::Operator(ir::OperatorKind::OP_LEQ)); }
         | expr_str LEQ expr_var   { $$ = scanner->parseInfixExpr(scanner->parseString($1), $3, ir::Operator(ir::OperatorKind::OP_LEQ)); }
         | expr_var LEQ expr_int   { $$ = scanner->parseInfixExpr($1, scanner->parseInt($3), ir::Operator(ir::OperatorKind::OP_LEQ)); }  
         | expr_var LEQ expr_float { $$ = scanner->parseInfixExpr($1, scanner->parseFloat($3), ir::Operator(ir::OperatorKind::OP_LEQ)); }
         | expr_var LEQ expr_str   { $$ = scanner->parseInfixExpr($1, scanner->parseString($3), ir::Operator(ir::OperatorKind::OP_LEQ)); }
         | expr_var LEQ expr_var   { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_LEQ)); }

         | expr_int EQ expr_var         { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_EQ)); }
         | expr_float EQ expr_var       { $$ = scanner->parseInfixExpr(scanner->parseFloat($1), $3, ir::Operator(ir::OperatorKind::OP_EQ)); }
         | expr_str EQ expr_var         { $$ = scanner->parseInfixExpr(scanner->parseString($1), $3, ir::Operator(ir::OperatorKind::OP_EQ)); }
         | expr_bool EQ expr_var        { $$ = scanner->parseInfixExpr(scanner->parseBool($1), $3, ir::Operator(ir::OperatorKind::OP_EQ)); }
         | expr_none EQ expr_var        { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_EQ)); }
         | expr_struct EQ expr_struct   { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_EQ)); }
         | expr_struct EQ expr_var      { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_EQ)); }
         | expr_var EQ expr_struct      { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_EQ)); }
         | expr_var EQ expr_int         { $$ = scanner->parseInfixExpr($1, scanner->parseInt($3), ir::Operator(ir::OperatorKind::OP_EQ)); }
         | expr_var EQ expr_float       { $$ = scanner->parseInfixExpr($1, scanner->parseFloat($3), ir::Operator(ir::OperatorKind::OP_EQ)); }
         | expr_var EQ expr_str         { $$ = scanner->parseInfixExpr($1, scanner->parseString($3), ir::Operator(ir::OperatorKind::OP_EQ)); }
         | expr_var EQ expr_bool        { $$ = scanner->parseInfixExpr($1, scanner->parseBool($3), ir::Operator(ir::OperatorKind::OP_EQ)); }
         | expr_var EQ expr_none        { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_EQ)); }
         | expr_mat EQ expr_mat         { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_EQ)); }
         | expr_var EQ expr_mat         { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_EQ)); }
         | expr_mat EQ expr_var         { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_EQ)); }
         | expr_var EQ expr_var         { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_EQ)); }

         | expr_int NEQ expr_var       { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_NEQ)); }  
         | expr_float NEQ expr_var     { $$ = scanner->parseInfixExpr(scanner->parseFloat($1), $3, ir::Operator(ir::OperatorKind::OP_NEQ)); }
         | expr_str NEQ expr_var       { $$ = scanner->parseInfixExpr(scanner->parseString($1), $3, ir::Operator(ir::OperatorKind::OP_NEQ)); }
         | expr_bool NEQ expr_var      { $$ = scanner->parseInfixExpr(scanner->parseBool($1), $3, ir::Operator(ir::OperatorKind::OP_NEQ)); }
         | expr_none NEQ expr_var      { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_NEQ)); }
         | expr_struct NEQ expr_struct { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_NEQ)); }
         | expr_struct NEQ expr_var    { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_NEQ)); }
         | expr_var NEQ expr_struct    { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_NEQ)); }
         | expr_var NEQ expr_int       { $$ = scanner->parseInfixExpr($1, scanner->parseInt($3), ir::Operator(ir::OperatorKind::OP_NEQ)); }  
         | expr_var NEQ expr_float     { $$ = scanner->parseInfixExpr($1, scanner->parseFloat($3), ir::Operator(ir::OperatorKind::OP_NEQ)); }
         | expr_var NEQ expr_str       { $$ = scanner->parseInfixExpr($1, scanner->parseString($3), ir::Operator(ir::OperatorKind::OP_NEQ)); }
         | expr_var NEQ expr_bool      { $$ = scanner->parseInfixExpr($1, scanner->parseBool($3), ir::Operator(ir::OperatorKind::OP_NEQ)); }
         | expr_var NEQ expr_none      { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_NEQ)); }
         | expr_mat NEQ expr_mat       { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_NEQ)); }
         | expr_var NEQ expr_mat       { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_NEQ)); }
         | expr_mat NEQ expr_var       { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_NEQ)); }
         | expr_var NEQ expr_var       { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_NEQ)); }

         | expr_int BAND expr_var { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_BAND)); }
         | expr_var BAND expr_int { $$ = scanner->parseInfixExpr($1, scanner->parseInt($3), ir::Operator(ir::OperatorKind::OP_BAND)); } 
         | expr_var BAND expr_var { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_BAND)); }                   

         | expr_int BXOR expr_var { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_BXOR)); }
         | expr_var BXOR expr_int { $$ = scanner->parseInfixExpr($1, scanner->parseInt($3), ir::Operator(ir::OperatorKind::OP_BXOR)); }
         | expr_var BXOR expr_var { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_BXOR)); }                   

         | expr_int BOR expr_var { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_BOR)); }
         | expr_var BOR expr_int { $$ = scanner->parseInfixExpr($1, scanner->parseInt($3), ir::Operator(ir::OperatorKind::OP_BOR)); }
         | expr_var BOR expr_var { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_BOR)); }                   

         | expr_int IN expr_mat    { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_IN)); }
         | expr_float IN expr_mat  { $$ = scanner->parseInfixExpr(scanner->parseFloat($1), $3, ir::Operator(ir::OperatorKind::OP_IN)); }
         | expr_str IN expr_mat    { $$ = scanner->parseInfixExpr(scanner->parseString($1), $3, ir::Operator(ir::OperatorKind::OP_IN)); }
         | expr_bool IN expr_mat   { $$ = scanner->parseInfixExpr(scanner->parseBool($1), $3, ir::Operator(ir::OperatorKind::OP_IN)); }
         | expr_none IN expr_mat   { $$ = scanner->parseInfixExpr(scanner->parseNone(), $3, ir::Operator(ir::OperatorKind::OP_IN)); }
         | expr_struct IN expr_mat { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_IN)); }
         | expr_mat IN expr_mat    { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_IN)); }
         | expr_int IN expr_var    { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_IN)); }
         | expr_float IN expr_var  { $$ = scanner->parseInfixExpr(scanner->parseFloat($1), $3, ir::Operator(ir::OperatorKind::OP_IN)); }
         | expr_str IN expr_var    { $$ = scanner->parseInfixExpr(scanner->parseString($1), $3, ir::Operator(ir::OperatorKind::OP_IN)); }
         | expr_bool IN expr_var   { $$ = scanner->parseInfixExpr(scanner->parseBool($1), $3, ir::Operator(ir::OperatorKind::OP_IN)); }
         | expr_none IN expr_var   { $$ = scanner->parseInfixExpr(scanner->parseNone(), $3, ir::Operator(ir::OperatorKind::OP_IN)); }
         | expr_struct IN expr_var { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_IN)); }
         | expr_mat IN expr_var    { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_IN)); }
         | expr_var IN expr_str    { $$ = scanner->parseInfixExpr($1, scanner->parseString($3), ir::Operator(ir::OperatorKind::OP_IN)); }
         | expr_var IN expr_var    { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_IN)); }

         | expr_bool LAND expr_var { $$ = scanner->parseInfixExpr(scanner->parseBool($1), $3, ir::Operator(ir::OperatorKind::OP_LAND)); }
         | expr_var LAND expr_bool { $$ = scanner->parseInfixExpr($1, scanner->parseBool($3), ir::Operator(ir::OperatorKind::OP_LAND)); }
         | expr_var LAND expr_var  { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_LAND)); }                   
         
         | expr_bool LOR expr_var { $$ = scanner->parseInfixExpr(scanner->parseBool($1), $3, ir::Operator(ir::OperatorKind::OP_LOR)); }
         | expr_var LOR expr_bool { $$ = scanner->parseInfixExpr($1, scanner->parseBool($3), ir::Operator(ir::OperatorKind::OP_LOR)); }
         | expr_var LOR expr_var  { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_LOR)); }                   

         | LNOT expr_var { $$ = scanner->parseUnaryPrefixExpr($2, ir::Operator(ir::OperatorKind::OP_LNOT)); }

         | BNOT expr_var { $$ = scanner->parseUnaryPrefixExpr($2, ir::Operator(ir::OperatorKind::OP_BNOT)); }

         | expr_int CONCAT expr_var       { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_CONCAT)); }
         | expr_float CONCAT expr_var     { $$ = scanner->parseInfixExpr(scanner->parseFloat($1), $3, ir::Operator(ir::OperatorKind::OP_CONCAT)); }
         | expr_str CONCAT expr_var       { $$ = scanner->parseInfixExpr(scanner->parseString($1), $3, ir::Operator(ir::OperatorKind::OP_CONCAT)); }
         | expr_bool CONCAT expr_var      { $$ = scanner->parseInfixExpr(scanner->parseBool($1), $3, ir::Operator(ir::OperatorKind::OP_CONCAT)); }  
         | expr_none CONCAT expr_var      { $$ = scanner->parseInfixExpr(scanner->parseNone(), $3, ir::Operator(ir::OperatorKind::OP_CONCAT)); }
         | expr_var CONCAT expr_int       { $$ = scanner->parseInfixExpr($1, scanner->parseInt($3), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
         | expr_var CONCAT expr_float     { $$ = scanner->parseInfixExpr($1, scanner->parseFloat($3), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
         | expr_var CONCAT expr_str       { $$ = scanner->parseInfixExpr($1, scanner->parseString($3), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
         | expr_var CONCAT expr_bool      { $$ = scanner->parseInfixExpr($1, scanner->parseBool($3), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
         | expr_var CONCAT expr_none      { $$ = scanner->parseInfixExpr($1, scanner->parseNone(), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
         | expr_var CONCAT expr_var       { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_CONCAT)); }
         ;

// Matrix value
matrix : LSQ RSQ                 { $$ = scanner->parseMatrix(std::vector<ptc::ir::Expr *>{}); }
       | LSQ matvals RSQ         { $$ = scanner->parseMatrix($2); }
       | LSQ END matvals RSQ     { $$ = scanner->parseMatrix($3); }
       | LSQ matvals END RSQ     { $$ = scanner->parseMatrix($2); }
       | LSQ END matvals END RSQ { $$ = scanner->parseMatrix($3); }
       ;
matvals : expr                   { $$ = scanner->parseMatrixValue($1); }
        | matvals COMMA expr     { $$ = scanner->parseAddMatrixValue($1, $3); }
        | matvals COMMA END expr { $$ = scanner->parseAddMatrixValue($1, $4); }
        ;

// Matrix expression
expr_mat : matrix           { $$ = $1; }
         | LPAR matrix RPAR { $$ = $2; }
         ;
range : LPAR range RPAR                     { $$ = $2; }
      | int_val RANGE int_val               { $$ = scanner->parseRange($1, $3); }
      | int_val COMMA int_val RANGE int_val { $$ = scanner->parseRange($1, $3, $5); }
      ;
int_val : expr_int  { $$ = scanner->parseInt($1); }
        | expr_var  { $$ = $1; }
        ;
slice : LSQ range RSQ  { $$ = $2; }
      ;

// None expression
expr_none : NONE            { $$ = scanner->parseNone(); }
          | LPAR NONE RPAR  { $$ = scanner->parseNone(); }
          ;

// Struct expression
expr_struct : ID struct_val         { $$ = scanner->parseStructLiteral(scanner->sym_lookup($1, false, true), $2); }
            | EXT_ID struct_val     { $$ = scanner->parseExternalStructLiteral(scanner->parseExtType($1, false), $2); }
            | LPAR expr_struct RPAR { $$ = $2; }
            ;
struct_val : LBR RBR                { $$ = std::map<std::string, ptc::ir::Expr*>{}; }
           | LBR struct_list RBR    { $$ = $2; }
           ;
struct_list : DOT ID SET expr                   { $$ = scanner->parseStructVals($2, $4); }
            | struct_list COMMA DOT ID SET expr { $$ = scanner->parseStructVals($1, $4, $6); }
            ;

// Integer expression
expr_int : INT { $$ = $1; }
         | MINUS expr_int %prec NEG { $$ = -$2; }
         | LPAR expr_int RPAR { $$ = $2; }
         | BNOT expr_int { $$ = ~$2; }
         | expr_int MUL expr_int { $$ = $1 * $3; }
         | expr_int DIV expr_int { $$ = $1 / $3; }
         | expr_int MOD expr_int { $$ = $1 % $3; }
         | expr_int MINUS expr_int { $$ = $1 - $3; }
         | expr_int PLUS expr_int { $$ = $1 + $3; }
         | expr_int BLSHFT expr_int { $$ = $1 << $3; }
         | expr_int BRSHFT expr_int { $$ = $1 >> $3; }
         | expr_int BAND expr_int { $$ = $1 & $3; }
         | expr_int BXOR expr_int { $$ = $1 ^ $3; }
         | expr_int BOR expr_int { $$ = $1 | $3; }
         ;

// Float expression
expr_float : FLOAT { $$ = $1; }
           | MINUS expr_float %prec NEG { $$ = -$2; }
           | LPAR expr_float RPAR { $$ = $2; }
           | expr_float POW expr_float { $$ = std::pow($1, $3); }
           | expr_float POW expr_int { $$ = std::pow($1, $3); }
           | expr_int POW expr_float { $$ = std::pow($1, $3); }
           | expr_float MUL expr_float { $$ = $1 * $3; }
           | expr_float MUL expr_int { $$ = $1 * $3; }
           | expr_int MUL expr_float { $$ = $1 * $3; }
           | expr_float DIV expr_float { $$ = $1 / $3; }
           | expr_float DIV expr_int { $$ = $1 / $3; }
           | expr_int DIV expr_float { $$ = $1 / $3; }
           | expr_float MOD expr_float { $$ = std::fmod($1, $3); }
           | expr_float MOD expr_int { $$ = std::fmod($1, $3); }
           | expr_int MOD expr_float { $$ = std::fmod($1, $3); }
           | expr_float MINUS expr_float { $$ = $1 - $3; }
           | expr_float MINUS expr_int { $$ = $1 - $3; }
           | expr_int MINUS expr_float { $$ = $1 - $3; }
           | expr_float PLUS expr_float { $$ = $1 + $3; }
           | expr_float PLUS expr_int { $$ = $1 + $3; }
           | expr_int PLUS expr_float { $$ = $1 + $3; }
           ;

// String expression
expr_str : STRING { $$ = $1; }
         | LPAR expr_str RPAR { $$ = $2; }
         | expr_str CONCAT expr_str { $$ = $1 + $3; }
         | expr_str CONCAT expr_int { $$ = $1 + std::to_string($3); }
         | expr_str CONCAT expr_float { $$ = $1 + std::to_string($3); }
         | expr_str CONCAT expr_bool { $$ = $1 + ($3 ? "true" : "false"); }
         | expr_str CONCAT expr_none { $$ = $1 + "none"; }
         | expr_int CONCAT expr_str { $$ = std::to_string($1) + $3; }
         | expr_int CONCAT expr_int { $$ = std::to_string($1) + std::to_string($3); }
         | expr_int CONCAT expr_float { $$ = std::to_string($1) + std::to_string($3); }
         | expr_int CONCAT expr_bool { $$ = std::to_string($1) + ($3 ? "true" : "false"); }
         | expr_int CONCAT expr_none { $$ = std::to_string($1) + "none"; }
         | expr_float CONCAT expr_str { $$ = std::to_string($1) + $3; }
         | expr_float CONCAT expr_int { $$ = std::to_string($1) + std::to_string($3); }
         | expr_float CONCAT expr_float { $$ = std::to_string($1) + std::to_string($3); }
         | expr_float CONCAT expr_bool { $$ = std::to_string($1) + ($3 ? "true" : "false"); }
         | expr_float CONCAT expr_none { $$ = std::to_string($1) + "none"; }
         | expr_bool CONCAT expr_str { $$ = ($1 ? "true" : "false") + $3; }
         | expr_bool CONCAT expr_int { $$ = ($1 ? "true" : "false") + std::to_string($3); }
         | expr_bool CONCAT expr_float { $$ = ($1 ? "true" : "false") + std::to_string($3); }
         | expr_bool CONCAT expr_bool { $$ = ($1 ? std::string("true") : std::string("false")) + ($3 ? "true" : "false"); }
         | expr_bool CONCAT expr_none { $$ = ($1 ? std::string("true") : std::string("false")) + "none"; }
         | expr_none CONCAT expr_str { $$ = std::string("none") + $3; }
         | expr_none CONCAT expr_int { $$ = std::string("none") + std::to_string($3); }
         | expr_none CONCAT expr_float { $$ = std::string("none") + std::to_string($3); }
         | expr_none CONCAT expr_bool { $$ = std::string("none") + ($3 ? "true" : "false"); }
         | expr_none CONCAT expr_none { $$ = std::string("nonenone"); }
         ;

// Boolean expression
expr_bool : BOOL { $$ = $1; }
          | LPAR expr_bool RPAR { $$ = $2; }
          | LNOT expr_bool { $$ = !$2; }
          | expr_bool LOR expr_bool { $$ = $1 || $3; }
          | expr_bool LAND expr_bool { $$ = $1 && $3; }

          | expr_bool EQ expr_bool { $$ = $1 == $3; }
          | expr_int EQ expr_int { $$ = $1 == $3; }
          | expr_int EQ expr_float { $$ = $1 == $3; }
          | expr_float EQ expr_float { $$ = $1 == $3; }
          | expr_float EQ expr_int { $$ = $1 == $3; }
          | expr_str EQ expr_str { $$ = $1 == $3; }
          | expr_none EQ expr_none { $$ = true; }

          | expr_bool NEQ expr_bool { $$ = $1 != $3; }
          | expr_int NEQ expr_int { $$ = $1 != $3; }
          | expr_int NEQ expr_float { $$ = $1 != $3; }
          | expr_float NEQ expr_float { $$ = $1 != $3; }
          | expr_float NEQ expr_int { $$ = $1 != $3; }
          | expr_str NEQ expr_str { $$ = $1 != $3; }
          | expr_none NEQ expr_none { $$ = false; }

          | expr_int BT expr_int { $$ = $1 > $3; }
          | expr_int BT expr_float { $$ = $1 > $3; }
          | expr_float BT expr_float { $$ = $1 > $3; }
          | expr_float BT expr_int { $$ = $1 > $3; }
          | expr_str BT expr_str { $$ = $1 > $3; }

          | expr_int LT expr_int { $$ = $1 < $3; }
          | expr_int LT expr_float { $$ = $1 < $3; }
          | expr_float LT expr_float { $$ = $1 < $3; }
          | expr_float LT expr_int { $$ = $1 < $3; }
          | expr_str LT expr_str { $$ = $1 < $3; }

          | expr_int BEQ expr_int { $$ = $1 >= $3; }
          | expr_int BEQ expr_float { $$ = $1 >= $3; }
          | expr_float BEQ expr_float { $$ = $1 >= $3; }
          | expr_float BEQ expr_int { $$ = $1 >= $3; }
          | expr_str BEQ expr_str { $$ = $1 >= $3; }

          | expr_int LEQ expr_int { $$ = $1 <= $3; }
          | expr_int LEQ expr_float { $$ = $1 <= $3; }
          | expr_float LEQ expr_float { $$ = $1 <= $3; }
          | expr_float LEQ expr_int { $$ = $1 <= $3; }
          | expr_str LEQ expr_str { $$ = $1 <= $3; }

          | expr_str IN expr_str { $$ = $3.find($1) != std::string::npos; }
          ;

// Function signature (as a type)
funtype : type LPAR typelist RPAR   { $$ = scanner->parseFunType($1, $3); }
        | type LPAR RPAR            { $$ = scanner->parseFunType($1, std::vector<ir::IR *>{}); }
        | KWVOID LPAR typelist RPAR { $$ = scanner->parseFunType(scanner->sym_lookup(VOID_CSTR), $3); }
        | KWVOID LPAR RPAR          { $$ = scanner->parseFunType(scanner->sym_lookup(VOID_CSTR), std::vector<ir::IR *>{}); }
        ;
typelist : type                 { $$ = scanner->parseFunTypeList($1); }
         | typelist COMMA type  { $$ = scanner->parseFunTypeListAdd($1, $3); }
         ;

// Matrix type
mattype : ID matsq               { $$ = scanner->parseMatrixType($1, $2); }
        | KWINT matsq            { $$ = scanner->parseMatrixType(INT_CSTR, $2); }
        | KWFLOAT matsq          { $$ = scanner->parseMatrixType(FLOAT_CSTR, $2); }
        | KWSTRING matsq         { $$ = scanner->parseMatrixType(STRING_CSTR, $2); }
        | KWBOOL matsq           { $$ = scanner->parseMatrixType(BOOL_CSTR, $2); }
        | KWANY matsq            { $$ = scanner->parseMatrixType(ANY_CSTR, $2); }
        | funtype matsq          { $$ = scanner->parseMatrixType($1, $2); }
        | ID KWMAYBE matsq
        | KWINT KWMAYBE matsq
        | KWFLOAT KWMAYBE matsq
        | KWSTRING KWMAYBE matsq 
        | KWBOOL KWMAYBE matsq
        ;
matsq : LSQ RSQ                 { $$ = scanner->parseMatrixSize(scanner->parseInt(-1)); }
      //| LSQ int_val RSQ         { $$ = scanner->parseMatrixSize($2); }
      | LSQ RSQ matsq           { $$ = scanner->parseAddMatrixSize($3, scanner->parseInt(-1)); }
      //| LSQ int_val RSQ matsq   { $$ = scanner->parseAddMatrixSize($4, $2); }
      ;

// Variable types
type : KWINT KWMAYBE    { $$ = scanner->sym_lookup(INT_CSTR, true, true); }
     | KWFLOAT KWMAYBE  { $$ = scanner->sym_lookup(FLOAT_CSTR, true, true); }
     | KWSTRING KWMAYBE { $$ = scanner->sym_lookup(STRING_CSTR, true, true); }
     | KWBOOL KWMAYBE   { $$ = scanner->sym_lookup(BOOL_CSTR, true, true); }
     | ID KWMAYBE       { $$ = scanner->sym_lookup($1, true, true); }
     | EXT_ID KWMAYBE   { $$ = scanner->parseExtType($1, true); }
     | mattype KWMAYBE  { $$ = scanner->parseMaybeMatrixType($1); }
     | KWINT            { $$ = scanner->sym_lookup(INT_CSTR, false, true); }
     | KWFLOAT          { $$ = scanner->sym_lookup(FLOAT_CSTR, false, true); }
     | KWSTRING         { $$ = scanner->sym_lookup(STRING_CSTR, false, true); }
     | KWBOOL           { $$ = scanner->sym_lookup(BOOL_CSTR, false, true); }
     | KWANY            { $$ = scanner->sym_lookup(ANY_CSTR, false, true); }
     | ID               { $$ = scanner->sym_lookup($1, false, true); }
     | EXT_ID           { $$ = scanner->parseExtType($1, false); }
     | funtype          { $$ = $1; }
     | mattype          { $$ = $1; }
     ;

%%

/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    auto msg = std::to_string(scanner->llvmloc->begin.line) + ":" + std::to_string(scanner->llvmloc->begin.column) + ": " + err_message;
    scanner->fatal_error(ptc::diag::ERR_SYNTAX, msg);
}