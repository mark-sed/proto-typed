/**
 * Grammar file for Bison tool for Proto-typed language
 * @copyright Marek Sedlacek, 2023
 */

/* Since new constructs are used, newer version is needed */
%require "3.7"
/* Use C++ parser */
%skeleton "lalr1.cc"

%defines
/* Set namespace used */
%define api.namespace { ptc }
/* Parser class */
%define api.parser.class { Parser }
%define api.location.file none

/* Forward declarations */
%code requires {
    namespace ptc {
        class Scanner;
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
    // Include compiler to use error
    #include "scanner.hpp"

    // Set correct token method
    #undef yylex
    #define yylex scanner->yylex
}

%define api.value.type variant
%define parse.assert
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
// TODO: Add more op - +=, -=...

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
%token KWINT "\"int\""
%token KWFLOAT "\"float\""
%token KWSTRING "\"string\""
%token KWBOOL "\"bool\""
%token KWSTRUCT "\"struct\""
%token KWVOID "\"void\""

//%token NIL "nil"

/* Identifiers */
%token <std::string> ID "identifier"

/* Associativity and precedence */
%right SET
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
%left CONCAT
%right LNOT BNOT
%left DOT

%precedence INT
%precedence FLOAT

%precedence NEG

// Terminal types
%type <long> expr_int
%type <double> expr_float
%type <std::string> expr_str
%type <bool> expr_bool

%locations

%%

// Start
start : END_FILE
      | stmt END_FILE
      ;
stmt : stmts
     | stmt stmts
     | stmt error stmts
     ;

// Statements
stmts : END
      | stmts_ne
      ;
stmts_ne : set
         | val
         | vardecl
         | vardef
         | import
         | for
         | if
         | while
         | dowhile
         | funcall
         ;

// Code block     
block : LBR RBR
      | LBR stmt RBR
      | END LBR stmt RBR
      | LBR stmt RBR END
      | END LBR stmt RBR END
      ;
// Code block or single statement
body : stmts_ne END
     | block
     ;

// Import
import : KWIMPORT id_list
       ;
id_list : ID
        | id_list COMMA ID
        ;

// Condition
cond : scope
     | val
     ;

// For loop
for : KWFOR LPAR ID COLON ID RPAR body
    | KWFOR LPAR ID COLON expr_str RPAR body
    ;

// While loop
while : KWWHILE LPAR cond RPAR body
      ;
// Do while
dowhile : KWDO body KWWHILE LPAR cond RPAR
        ;

// If-elif-else statement
if : KWIF LPAR cond RPAR body elif else
   ;
elif : KWELIF LPAR cond RPAR body
     | elif KWELIF LPAR cond RPAR body
     |
     ;
else : KWELSE body
     |
     ;

// Variable declaration
vardecl : type ID
        ;

// Definition
vardef : type ID SET ID
       | type ID SET val
       ;

// Assignment
set : scope SET val
    | scope SET scope
    ;

// Function call
funcall : scope LPAR RPAR
        | scope LPAR callarglist RPAR
        ;
callarglist : callarg
            | callargnamed
            | callarg COMMA callarglist
            ;
callarg : val
        | scope
        ;
callargnamed : ID SET val
             | ID SET scope
             | callargnamed COMMA callargnamed
             ;

// Index
index : val
      | scope
      ;

select : LSQ index RSQ
       | LSQ index RSQ select

// Scope - Complex id
scope : ID
      | funcall
      | ID select
      | scope DOT scope
      ;

// Constant values
val : expr_int //{ std::cout << "=" << $1 << std::endl; }
    | expr_float //{ std::cout << "=" << $1 << std::endl; }
    | expr_str //{ std::cout << "=" << $1 << std::endl; }
    | expr_bool //{ std::cout << "=" << $1 << std::endl; }
    ;

// Integer expression
expr_int : INT { $$ = $1; }
         | MINUS expr_int %prec NEG { $$ = -$2; }
         | LPAR expr_int RPAR { $$ = $2; }
         | expr_int MUL expr_int { $$ = $1 * $3; }
         | expr_int DIV expr_int { $$ = $1 / $3; }
         | expr_int MOD expr_int { $$ = $1 % $3; }
         | expr_int MINUS expr_int { $$ = $1 - $3; }
         | expr_int PLUS expr_int { $$ = $1 + $3; }
         | expr_int BAND expr_int { $$ = $1 & $3; }
         | expr_int BOR expr_int { $$ = $1 | $3; }
         | expr_int BXOR expr_int { $$ = $1 ^ $3; }
         | BNOT expr_int { $$ = ~$2; }
         | expr_int BLSHFT expr_int { $$ = $1 << $3; }
         | expr_int BRSHFT expr_int { $$ = $1 >> $3; }
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
         | expr_int CONCAT expr_str { $$ = std::to_string($1) + $3; }
         | expr_int CONCAT expr_int { $$ = std::to_string($1) + std::to_string($3); }
         | expr_int CONCAT expr_float { $$ = std::to_string($1) + std::to_string($3); }
         | expr_int CONCAT expr_bool { $$ = std::to_string($1) + ($3 ? "true" : "false"); }
         | expr_float CONCAT expr_str { $$ = std::to_string($1) + $3; }
         | expr_float CONCAT expr_int { $$ = std::to_string($1) + std::to_string($3); }
         | expr_float CONCAT expr_float { $$ = std::to_string($1) + std::to_string($3); }
         | expr_float CONCAT expr_bool { $$ = std::to_string($1) + ($3 ? "true" : "false"); }
         | expr_bool CONCAT expr_str { $$ = ($1 ? "true" : "false") + $3; }
         | expr_bool CONCAT expr_int { $$ = ($1 ? "true" : "false") + std::to_string($3); }
         | expr_bool CONCAT expr_float { $$ = ($1 ? "true" : "false") + std::to_string($3); }
         | expr_bool CONCAT expr_bool { $$ = ($1 ? std::string("true") : std::string("false")) + ($3 ? "true" : "false"); }
         ;

// Boolean expression
expr_bool : BOOL { $$ = $1; }
          | LPAR expr_bool RPAR { $$ = $2; }
          | LNOT expr_bool { $$ = !$2; }
          | expr_bool LOR expr_bool { $$ = $1 || $3; }
          | expr_bool LAND expr_bool { $$ = $1 && $3; }
          | expr_bool EQ expr_bool { $$ = $1 == $3; }
          | expr_int EQ expr_int { $$ = $1 == $3; }
          | expr_float EQ expr_float { $$ = $1 == $3; }
          | expr_str EQ expr_str { $$ = $1 == $3; }
          | expr_bool NEQ expr_bool { $$ = $1 != $3; }
          | expr_int NEQ expr_int { $$ = $1 != $3; }
          | expr_float NEQ expr_float { $$ = $1 != $3; }
          | expr_str NEQ expr_str { $$ = $1 != $3; }
          | expr_int BT expr_int { $$ = $1 > $3; }
          | expr_float BT expr_float { $$ = $1 > $3; }
          | expr_str BT expr_str { $$ = $1 > $3; }
          | expr_int LT expr_int { $$ = $1 < $3; }
          | expr_float LT expr_float { $$ = $1 < $3; }
          | expr_str LT expr_str { $$ = $1 < $3; }
          | expr_int BEQ expr_int { $$ = $1 >= $3; }
          | expr_float BEQ expr_float { $$ = $1 >= $3; }
          | expr_str BEQ expr_str { $$ = $1 >= $3; }
          | expr_int LEQ expr_int { $$ = $1 <= $3; }
          | expr_float LEQ expr_float { $$ = $1 <= $3; }
          | expr_str LEQ expr_str { $$ = $1 <= $3; }
          ;

// Function signature (as a type)
funtype : type LPAR typelist RPAR
        | type LPAR RPAR
        ;

typelist : type
         | type COMMA typelist
         ;

// Variable types
type : KWINT
     | KWFLOAT
     | KWSTRING
     | KWBOOL
     | ID
     | funtype
     ;

%%

/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    std::cerr << scanner->loc->begin.line << ":" << scanner->loc->begin.column << ": " << err_message << std::endl;
}