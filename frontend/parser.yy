/**
 * Grammar file for Bison tool for Proto-typed language
 * @copyright Marek Sedlacek, 2023
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
        namespace diags {
        }
    }

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
%token KWIMPORT "import"
%token KWIF "if"
%token KWELIF "elif"
%token KWELSE "else"
%token KWFOR "for"
%token KWWHILE "while"
%token KWDO "do"
%token KWRETURN "return"
%token KWBREAK "break"
%token KWCONTINUE "continue"
%token KWCONST "const"
%token KWMAYBE "?"
%token KWINT "\"int\""
%token KWFLOAT "\"float\""
%token KWSTRING "\"string\""
%token KWBOOL "\"bool\""
%token KWSTRUCT "\"struct\""
%token KWVOID "\"void\""

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
%type <ptc::ir::IR *> vardecl
%type <ptc::ir::IR *> vardef
%type <ptc::ir::IR *> stmts_ne
%type <ptc::ir::IR *> if
%type <ptc::ir::IR *> while
%type <ptc::ir::IR *> stmts
%type <ptc::ir::IR *> function
%type <ptc::ir::IR *> return
%type <ptc::ir::IR *> flowctl
%type <ptc::ir::IR *> import
%type <ptc::ir::Expr *> expr
%type <ptc::ir::Expr *> expr_var
%type <ptc::ir::Expr *> set
%type <std::vector<ptc::ir::Expr *> > callarglist
%type <std::vector<ptc::ir::IR *> > body
%type <std::vector<ptc::ir::IR *> > block
%type <std::vector<ptc::ir::IR *> > else
%type <std::vector<ptc::ir::IR *> > stmt
%type <std::vector<std::string> > id_list
%type <std::vector<ptc::ir::FormalParamDecl *> > funargs

%locations

%%

// Start
start : END_FILE
      | stmt END_FILE   { scanner->parseEntry($1); }
      ;
stmt : stmts            { $$ = scanner->parseStmtBody($1); }
     | stmt stmts       { $$ = scanner->parseStmtBodyAdd($1, $2); }
     | stmt error stmts { $$ = scanner->parseStmtBodyAdd($1, $3); }
     ;

// Statements
stmts : END      { $$ = nullptr; }
      | stmts_ne { $$ = $1; }
      ;
stmts_ne : set END      { $$ = scanner->parseExprStmt($1); }
         | vardecl END  { $$ = $1; }
         | vardef END   { $$ = $1; }
         | import END   { $$ = $1; }
         | for
         | if           { $$ = $1; }
         | while        { $$ = $1; }
         | dowhile
         | struct
         | function     { $$ = $1; }
         | flowctl END  { $$ = $1; }
         | expr END     { $$ = scanner->parseExprStmt($1); }
         ;

// Code block
block : LBR RBR                 { $$ = scanner->parseStmtBody(nullptr); }
      | LBR stmt RBR            { $$ = $2; }
      | END LBR stmt RBR        { $$ = $3; }
      | LBR stmt RBR END        { $$ = $2; }
      | END LBR stmt RBR END    { $$ = $3; }
      ;
// Code block or single statement
body : stmts_ne { $$ = scanner->parseStmtBody($1); }
     | block    { $$ = $1; }
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
for : KWFOR LPAR ID COLON expr RPAR body
    ;

// While loop
while : KWWHILE LPAR expr RPAR body { $$ = scanner->parseWhile($3, $5); }
      ;
// Do while
dowhile : KWDO body KWWHILE LPAR expr RPAR
        ;

// If-elif-else statement
if : KWIF LPAR expr RPAR body else { $$ = scanner->parseIfStmt($3, $5, $6); }
   ;
//elif : KWELIF LPAR expr RPAR body
//     | elif KWELIF LPAR expr RPAR body
//     |
//     ;
else : KWELSE body  { $$ = $2; }
     |              { $$ = scanner->parseStmtBody(nullptr); }
     ;

// Struct definition
struct : KWSTRUCT ID LBR RBR
       | KWSTRUCT ID LBR decllist RBR
       | KWSTRUCT ID END LBR decllist RBR
       ;
decllist : END
         | END decllist
         | declistval END
         | declistval END decllist
         ;
declistval : vardecl
           | type ID SET expr
           | KWVAR ID SET expr
           ;

// Function definition
function : type fun_id LPAR RPAR block               { $$ = scanner->parseFun($1, $2, std::vector<ptc::ir::FormalParamDecl *>{}, $5); }
         | type fun_id LPAR funargs RPAR block       { $$ = scanner->parseFun($1, $2, $4, $6); }
         | KWVOID fun_id LPAR RPAR block         { $$ = scanner->parseFun(scanner->sym_lookup("void"), $2, std::vector<ptc::ir::FormalParamDecl *>{}, $5); }
         | KWVOID fun_id LPAR funargs RPAR block { $$ = scanner->parseFun(scanner->sym_lookup("void"), $2, $4, $6); }
         ;
fun_id : ID { scanner->enterFunScope(); $$ = $1; }
       ;
funargs : type ID               { $$ = scanner->parseFunParam($1, $2); }
        | funargdef
        | funargs COMMA type ID { $$ = scanner->parseAddFunParam($1, $3, $4); }
        ;
funargdef : type ID SET expr
          | funargdef COMMA funargdef
          ;

// Variable declaration
vardecl : type ID { $$ = scanner->parseVarDecl($1, $2); }
        ;

// Definition
vardef : type ID SET struct_val
       | type ID SET expr        { scanner->parseVarDef($1, $2, $4); }
       | KWCONST ID SET expr
       | KWVAR ID SET expr
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
    | expr SET set        
    ;

// Function call arguments
callarglist : expr                    { $$ = scanner->parseFunCallArg($1); }
            | expr COMMA callarglist  { $$ = scanner->parseAddFunCallArg($3, $1); }
            ;

// Expressions
expr : expr_mat     { $$ = nullptr; }
     | expr_var     { $$ = $1; }
     | expr_none    { $$ = nullptr; }
     | expr_struct  { $$ = nullptr; }
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

         | expr_str LSQ int_val RSQ
         | expr_mat LSQ int_val RSQ
         | ID LSQ int_val RSQ
         | EXT_ID LSQ int_val RSQ
         | expr_var LSQ int_val RSQ

         | expr_mat slice
         | ID slice
         | EXT_ID slice
         | expr_var slice

         | ID DOT expr_var
         | EXT_ID DOT expr_var
         | expr_var DOT expr_var

         | expr_float POW expr_var
         | expr_var POW expr_float
         | expr_var POW expr_var

         | expr_int MUL expr_var   { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_MUL)); }
         | expr_float MUL expr_var { $$ = scanner->parseInfixExpr(scanner->parseFloat($1), $3, ir::Operator(ir::OperatorKind::OP_MUL)); }
         | expr_var MUL expr_int   { $$ = scanner->parseInfixExpr($1, scanner->parseInt($3), ir::Operator(ir::OperatorKind::OP_MUL)); }
         | expr_var MUL expr_float { $$ = scanner->parseInfixExpr($1, scanner->parseFloat($3), ir::Operator(ir::OperatorKind::OP_MUL)); }
         | expr_mat MUL expr_mat
         | expr_mat MUL expr_var
         | expr_var MUL expr_mat
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
         | expr_mat PLUS expr_mat
         | expr_var PLUS expr_mat
         | expr_mat PLUS expr_var
         | expr_var PLUS expr_var   { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_ADD)); }

         | expr_int MINUS expr_var   { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_SUB)); } 
         | expr_float MINUS expr_var { $$ = scanner->parseInfixExpr(scanner->parseFloat($1), $3, ir::Operator(ir::OperatorKind::OP_SUB)); } 
         | expr_var MINUS expr_int   { $$ = scanner->parseInfixExpr($1, scanner->parseInt($3), ir::Operator(ir::OperatorKind::OP_SUB)); }
         | expr_var MINUS expr_float { $$ = scanner->parseInfixExpr($1, scanner->parseFloat($3), ir::Operator(ir::OperatorKind::OP_SUB)); } 
         | expr_mat MINUS expr_mat
         | expr_var MINUS expr_mat
         | expr_mat MINUS expr_var
         | expr_var MINUS expr_var   { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_SUB)); }

         | expr_int BLSHFT expr_var { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
         | expr_var BLSHFT expr_int { $$ = scanner->parseInfixExpr($1, scanner->parseInt($3), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
         | expr_var BLSHFT expr_var { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_BLSHFT)); }                   

         | expr_int BRSHFT expr_var { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
         | expr_var BRSHFT expr_int { $$ = scanner->parseInfixExpr($1, scanner->parseInt($3), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
         | expr_var BRSHFT expr_var { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_BRSHFT)); }                   

         | expr_int BT expr_var   { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_BT)); }
         | expr_float BT expr_var { $$ = scanner->parseInfixExpr(scanner->parseFloat($1), $3, ir::Operator(ir::OperatorKind::OP_BT)); } 
         | expr_str BT expr_var   
         | expr_var BT expr_int   { $$ = scanner->parseInfixExpr($1, scanner->parseInt($3), ir::Operator(ir::OperatorKind::OP_BT)); }
         | expr_var BT expr_float { $$ = scanner->parseInfixExpr($1, scanner->parseFloat($3), ir::Operator(ir::OperatorKind::OP_BT)); }
         | expr_var BT expr_str
         | expr_var BT expr_var   { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_BT)); }

         | expr_int BEQ expr_var   { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_BEQ)); }  
         | expr_float BEQ expr_var { $$ = scanner->parseInfixExpr(scanner->parseFloat($1), $3, ir::Operator(ir::OperatorKind::OP_BEQ)); }
         | expr_str BEQ expr_var   
         | expr_var BEQ expr_int   { $$ = scanner->parseInfixExpr($1, scanner->parseInt($3), ir::Operator(ir::OperatorKind::OP_BEQ)); }  
         | expr_var BEQ expr_float { $$ = scanner->parseInfixExpr($1, scanner->parseFloat($3), ir::Operator(ir::OperatorKind::OP_BEQ)); }
         | expr_var BEQ expr_str
         | expr_var BEQ expr_var   { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_BEQ)); }

         | expr_int LT expr_var   { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_LT)); }  
         | expr_float LT expr_var { $$ = scanner->parseInfixExpr(scanner->parseFloat($1), $3, ir::Operator(ir::OperatorKind::OP_LT)); }
         | expr_str LT expr_var
         | expr_var LT expr_int   { $$ = scanner->parseInfixExpr($1, scanner->parseInt($3), ir::Operator(ir::OperatorKind::OP_LT)); }  
         | expr_var LT expr_float { $$ = scanner->parseInfixExpr($1, scanner->parseFloat($3), ir::Operator(ir::OperatorKind::OP_LT)); }
         | expr_var LT expr_str
         | expr_var LT expr_var   { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_LT)); }

         | expr_int LEQ expr_var   { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_LEQ)); }  
         | expr_float LEQ expr_var { $$ = scanner->parseInfixExpr(scanner->parseFloat($1), $3, ir::Operator(ir::OperatorKind::OP_LEQ)); }
         | expr_str LEQ expr_var
         | expr_var LEQ expr_int   { $$ = scanner->parseInfixExpr($1, scanner->parseInt($3), ir::Operator(ir::OperatorKind::OP_LEQ)); }  
         | expr_var LEQ expr_float { $$ = scanner->parseInfixExpr($1, scanner->parseFloat($3), ir::Operator(ir::OperatorKind::OP_LEQ)); }
         | expr_var LEQ expr_str
         | expr_var LEQ expr_var   { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_LEQ)); }

         | expr_int EQ expr_var         { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_EQ)); }
         | expr_float EQ expr_var       { $$ = scanner->parseInfixExpr(scanner->parseFloat($1), $3, ir::Operator(ir::OperatorKind::OP_EQ)); }
         | expr_str EQ expr_var
         | expr_bool EQ expr_var        { $$ = scanner->parseInfixExpr(scanner->parseBool($1), $3, ir::Operator(ir::OperatorKind::OP_EQ)); }
         | expr_none EQ expr_var
         | expr_struct EQ expr_struct
         | expr_struct EQ expr_var
         | expr_var EQ expr_int         { $$ = scanner->parseInfixExpr($1, scanner->parseInt($3), ir::Operator(ir::OperatorKind::OP_EQ)); }
         | expr_var EQ expr_float       { $$ = scanner->parseInfixExpr($1, scanner->parseFloat($3), ir::Operator(ir::OperatorKind::OP_EQ)); }
         | expr_var EQ expr_str
         | expr_var EQ expr_bool        { $$ = scanner->parseInfixExpr($1, scanner->parseBool($3), ir::Operator(ir::OperatorKind::OP_EQ)); }
         | expr_var EQ expr_none
         | expr_var EQ expr_struct
         | expr_mat EQ expr_mat
         | expr_var EQ expr_mat
         | expr_mat EQ expr_var
         | expr_var EQ expr_var         { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_EQ)); }

         | expr_int NEQ expr_var       { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_NEQ)); }  
         | expr_float NEQ expr_var     { $$ = scanner->parseInfixExpr(scanner->parseFloat($1), $3, ir::Operator(ir::OperatorKind::OP_NEQ)); }
         | expr_str NEQ expr_var
         | expr_bool NEQ expr_var
         | expr_none NEQ expr_var
         | expr_struct NEQ expr_struct
         | expr_struct NEQ expr_var
         | expr_var NEQ expr_int       { $$ = scanner->parseInfixExpr($1, scanner->parseInt($3), ir::Operator(ir::OperatorKind::OP_NEQ)); }  
         | expr_var NEQ expr_float     { $$ = scanner->parseInfixExpr($1, scanner->parseFloat($3), ir::Operator(ir::OperatorKind::OP_NEQ)); }
         | expr_var NEQ expr_str
         | expr_var NEQ expr_bool
         | expr_var NEQ expr_none
         | expr_var NEQ expr_struct
         | expr_mat NEQ expr_mat
         | expr_var NEQ expr_mat
         | expr_mat NEQ expr_var
         | expr_var NEQ expr_var        { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_NEQ)); }

         | expr_int BAND expr_var { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_BAND)); }
         | expr_var BAND expr_int { $$ = scanner->parseInfixExpr($1, scanner->parseInt($3), ir::Operator(ir::OperatorKind::OP_BAND)); } 
         | expr_var BAND expr_var { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_BAND)); }                   

         | expr_int BXOR expr_var { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_BXOR)); }
         | expr_var BXOR expr_int { $$ = scanner->parseInfixExpr($1, scanner->parseInt($3), ir::Operator(ir::OperatorKind::OP_BXOR)); }
         | expr_var BXOR expr_var { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_BXOR)); }                   

         | expr_int BOR expr_var { $$ = scanner->parseInfixExpr(scanner->parseInt($1), $3, ir::Operator(ir::OperatorKind::OP_BOR)); }
         | expr_var BOR expr_int { $$ = scanner->parseInfixExpr($1, scanner->parseInt($3), ir::Operator(ir::OperatorKind::OP_BOR)); }
         | expr_var BOR expr_var { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_BOR)); }                   

         | expr_int IN expr_mat
         | expr_float IN expr_mat
         | expr_str IN expr_mat
         | expr_bool IN expr_mat
         | expr_none IN expr_mat
         | expr_struct IN expr_mat
         | expr_mat IN expr_mat
         | expr_int IN expr_var
         | expr_float IN expr_var
         | expr_str IN expr_var
         | expr_bool IN expr_var
         | expr_none IN expr_var
         | expr_struct IN expr_var
         | expr_mat IN expr_var
         | expr_var IN expr_str
         | expr_var IN expr_var

         | expr_bool LAND expr_var { $$ = scanner->parseInfixExpr(scanner->parseBool($1), $3, ir::Operator(ir::OperatorKind::OP_LAND)); }
         | expr_var LAND expr_bool { $$ = scanner->parseInfixExpr($1, scanner->parseBool($3), ir::Operator(ir::OperatorKind::OP_LAND)); }
         | expr_var LAND expr_var  { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_LAND)); }                   
         
         | expr_bool LOR expr_var { $$ = scanner->parseInfixExpr(scanner->parseBool($1), $3, ir::Operator(ir::OperatorKind::OP_LOR)); }
         | expr_var LOR expr_bool { $$ = scanner->parseInfixExpr($1, scanner->parseBool($3), ir::Operator(ir::OperatorKind::OP_LOR)); }
         | expr_var LOR expr_var  { $$ = scanner->parseInfixExpr($1, $3, ir::Operator(ir::OperatorKind::OP_LOR)); }                   

         | expr_int CONCAT expr_struct
         | expr_float CONCAT expr_struct
         | expr_str CONCAT expr_struct
         | expr_bool CONCAT expr_struct
         | expr_none CONCAT expr_struct
         | expr_struct CONCAT expr_int
         | expr_struct CONCAT expr_float
         | expr_struct CONCAT expr_str
         | expr_struct CONCAT expr_bool
         | expr_struct CONCAT expr_none
         | expr_struct CONCAT expr_struct
         | expr_int CONCAT expr_var
         | expr_float CONCAT expr_var
         | expr_str CONCAT expr_var
         | expr_bool CONCAT expr_var
         | expr_none CONCAT expr_var
         | expr_struct CONCAT expr_var
         | expr_var CONCAT expr_int
         | expr_var CONCAT expr_float
         | expr_var CONCAT expr_str
         | expr_var CONCAT expr_bool
         | expr_var CONCAT expr_none
         | expr_var CONCAT expr_struct
         | expr_var CONCAT expr_var
         ;

// Matrix value
matrix : LSQ RSQ
       | LSQ matvals RSQ
       | LSQ END matvals RSQ
       | LSQ matvals END RSQ
       | LSQ END matvals END RSQ
       ;
matvals : expr
        | expr COMMA matvals
        | expr COMMA END matvals
        ;

// Matrix expression
expr_mat : matrix
         | range
         | LPAR matrix RPAR
         | LPAR range RPAR
         ; // TODO: Add compile time matrix simplification?
range : LPAR int_val RANGE int_val RPAR
      | LPAR int_val COMMA int_val RANGE int_val RPAR
      ;
int_val : expr_int
        | expr_var
        ;
slice : LSQ COLON RSQ
      | LSQ int_val COLON RSQ
      | LSQ COLON int_val RSQ
      | LSQ int_val COLON int_val RSQ
      | LSQ COLON COLON RSQ
      | LSQ int_val COLON COLON RSQ
      | LSQ COLON int_val COLON RSQ
      | LSQ COLON COLON int_val RSQ
      | LSQ int_val COLON int_val COLON RSQ
      | LSQ int_val COLON COLON int_val RSQ
      | LSQ COLON int_val COLON int_val RSQ
      | LSQ int_val COLON int_val COLON int_val RSQ
      ;

// None expression
expr_none : NONE
          | LPAR NONE RPAR
          ;

// Struct expression
expr_struct : ID struct_val
            | LPAR ID struct_val RPAR
            ;
struct_val : LBR RBR
           | LBR struct_list RBR
           ;
struct_list : DOT ID SET expr
            | DOT ID SET expr COMMA struct_list
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
funtype : type LPAR typelist RPAR
        | type LPAR RPAR
        ;
typelist : type
         | type COMMA typelist
         ;

// Matrix type
mattype : ID LSQ matsize RSQ
        | ID LSQ RSQ
        | KWINT LSQ matsize RSQ
        | KWINT LSQ RSQ
        | KWFLOAT LSQ matsize RSQ
        | KWFLOAT LSQ RSQ
        | KWSTRING LSQ matsize RSQ
        | KWSTRING LSQ RSQ
        | KWBOOL LSQ matsize RSQ
        | KWBOOL LSQ RSQ
        ;
matsize : int_val
        | int_val COMMA matsize
        ;

// Variable types
type : KWINT KWMAYBE    { $$ = nullptr; /*TODO*/ }
     | KWFLOAT KWMAYBE  { $$ = nullptr; /*TODO*/ }
     | KWSTRING KWMAYBE { $$ = nullptr; /*TODO*/ }
     | KWBOOL KWMAYBE   { $$ = nullptr; /*TODO*/ }
     | ID KWMAYBE       { $$ = nullptr; /*TODO*/ }
     | funtype KWMAYBE  { $$ = nullptr; /*TODO*/ }
     | mattype KWMAYBE  { $$ = nullptr; /*TODO*/ }
     | KWINT            { $$ = scanner->sym_lookup("int"); }
     | KWFLOAT          { $$ = scanner->sym_lookup("float"); }
     | KWSTRING         { $$ = scanner->sym_lookup("string"); }
     | KWBOOL           { $$ = scanner->sym_lookup("bool"); }
     | ID               { $$ = scanner->sym_lookup($1); }
     | funtype          { $$ = nullptr; /*TODO*/ }
     | mattype          { $$ = nullptr; /*TODO*/ }
     ;

%%

/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    auto msg = std::to_string(scanner->loc->begin.line) + ":" + std::to_string(scanner->loc->begin.column) + ": " + err_message;
    scanner->fatal_error(ptc::diag::ERR_SYNTAX, msg);
}