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
stmts_ne : set END
         | vardecl END
         | vardef END
         | import END
         | for
         | if
         | while
         | dowhile
         | struct
         | function
         | flowctl END
         | expr END
         ;

// Code block     
block : LBR RBR
      | LBR stmt RBR
      | END LBR stmt RBR
      | LBR stmt RBR END
      | END LBR stmt RBR END
      ;
// Code block or single statement
body : stmts_ne
     | block
     ;

// Import
import : KWIMPORT id_list
       ;
id_list : ID
        | id_list COMMA ID
        ;

// Flow controll
flowctl : KWBREAK
        | KWCONTINUE
        | return
        ;
return : KWRETURN
       | KWRETURN expr
       ;

// For loop
for : KWFOR LPAR ID COLON ID RPAR body
    | KWFOR LPAR ID COLON expr_str RPAR body
    ;

// While loop
while : KWWHILE LPAR expr RPAR body
      ;
// Do while
dowhile : KWDO body KWWHILE LPAR expr RPAR
        ;

// If-elif-else statement
if : KWIF LPAR expr RPAR body elif else
   ;
elif : KWELIF LPAR expr RPAR body
     | elif KWELIF LPAR expr RPAR body
     |
     ;
else : KWELSE body
     |
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
function : type ID LPAR RPAR block
         | type ID LPAR funargs RPAR block
         | KWVOID ID LPAR RPAR block
         | KWVOID ID LPAR funargs RPAR block
         ;
funargs : type ID
        | funargdef
        | funargs COMMA funargs
        ;
funargdef : type ID SET expr
          | funargdef COMMA funargdef
          ;

// Variable declaration
vardecl : type ID
        ;

// Definition
vardef : type ID SET struct_val
       | type ID SET expr
       | KWCONST ID SET expr
       | KWVAR ID SET expr
       ;

// Assignment and compound assignment
set : scope SETCONCAT expr
    | scope SETPOW expr
    | scope SETMOD expr
    | scope SETDIV expr
    | scope SETMUL expr
    | scope SETMINUS expr
    | scope SETPLUS expr
    | scope SETBAND expr
    | scope SETBOR expr
    | scope SETBXOR expr
    | scope SETBNOT expr
    | scope SETBLSHFT expr
    | scope SETBRSHFT expr
    | scope SET expr
    | scope SET set
    ;

// Function call
funcall : scope LPAR RPAR
        | scope LPAR callarglist RPAR
        ;
callarglist : expr
            | expr COMMA callarglist
            ;

// Scope - Complex id
scope : ID
      | funcall
      | ID LSQ int_val RSQ
      | scope LSQ int_val RSQ
      | scope DOT scope
      ;

// Expressions
expr : expr_mat
     | expr_var
     | expr_none
     | expr_struct
     | val
     ;

expr_var : scope
         | MINUS scope %prec NEG
         | LPAR scope RPAR

         | expr_float POW expr_var
         | expr_var POW expr_float
         | expr_var POW expr_var

         | expr_int MUL expr_var
         | expr_float MUL expr_var
         | expr_var MUL expr_int
         | expr_var MUL expr_float
         | expr_mat MUL expr_mat
         | expr_mat MUL expr_var
         | expr_var MUL expr_mat
         | expr_var MUL expr_var

         | expr_int DIV expr_var
         | expr_float DIV expr_var
         | expr_var DIV expr_int
         | expr_var DIV expr_float
         | expr_var DIV expr_var

         | expr_int MOD expr_var
         | expr_float MOD expr_var
         | expr_var MOD expr_int
         | expr_var MOD expr_float
         | expr_var MOD expr_var

         | expr_int PLUS expr_var
         | expr_float PLUS expr_var
         | expr_var PLUS expr_int
         | expr_var PLUS expr_float
         | expr_mat PLUS expr_mat
         | expr_var PLUS expr_mat
         | expr_mat PLUS expr_var
         | expr_var PLUS expr_var

         | expr_int MINUS expr_var
         | expr_float MINUS expr_var
         | expr_var MINUS expr_int
         | expr_var MINUS expr_float
         | expr_mat MINUS expr_mat
         | expr_var MINUS expr_mat
         | expr_mat MINUS expr_var
         | expr_var MINUS expr_var

         | expr_int BLSHFT expr_var
         | expr_var BLSHFT expr_int
         | expr_var BLSHFT expr_var

         | expr_int BRSHFT expr_var
         | expr_var BRSHFT expr_int
         | expr_var BRSHFT expr_var

         | expr_int BT expr_var
         | expr_float BT expr_var
         | expr_str BT expr_var
         | expr_var BT expr_int
         | expr_var BT expr_float
         | expr_var BT expr_str
         | expr_var BT expr_var

         | expr_int BEQ expr_var
         | expr_float BEQ expr_var
         | expr_str BEQ expr_var
         | expr_var BEQ expr_int
         | expr_var BEQ expr_float
         | expr_var BEQ expr_str
         | expr_var BEQ expr_var

         | expr_int LT expr_var
         | expr_float LT expr_var
         | expr_str LT expr_var
         | expr_var LT expr_int
         | expr_var LT expr_float
         | expr_var LT expr_str
         | expr_var LT expr_var

         | expr_int LEQ expr_var
         | expr_float LEQ expr_var
         | expr_str LEQ expr_var
         | expr_var LEQ expr_int
         | expr_var LEQ expr_float
         | expr_var LEQ expr_str
         | expr_var LEQ expr_var

         | expr_int EQ expr_var
         | expr_float EQ expr_var
         | expr_str EQ expr_var
         | expr_bool EQ expr_var
         | expr_none EQ expr_var
         | expr_struct EQ expr_struct
         | expr_struct EQ expr_var
         | expr_var EQ expr_int
         | expr_var EQ expr_float
         | expr_var EQ expr_str
         | expr_var EQ expr_bool
         | expr_var EQ expr_none
         | expr_var EQ expr_struct
         | expr_mat EQ expr_mat
         | expr_var EQ expr_mat
         | expr_mat EQ expr_var
         | expr_var EQ expr_var

         | expr_int NEQ expr_var
         | expr_float NEQ expr_var
         | expr_str NEQ expr_var
         | expr_bool NEQ expr_var
         | expr_none NEQ expr_var
         | expr_struct NEQ expr_struct
         | expr_struct NEQ expr_var
         | expr_var NEQ expr_int
         | expr_var NEQ expr_float
         | expr_var NEQ expr_str
         | expr_var NEQ expr_bool
         | expr_var NEQ expr_none
         | expr_var NEQ expr_struct
         | expr_mat NEQ expr_mat
         | expr_var NEQ expr_mat
         | expr_mat NEQ expr_var
         | expr_var NEQ expr_var

         | expr_int BAND expr_var
         | expr_var BAND expr_int
         | expr_var BAND expr_var

         | expr_int BXOR expr_var
         | expr_var BXOR expr_int
         | expr_var BXOR expr_var

         | expr_int BOR expr_var
         | expr_var BOR expr_int
         | expr_var BOR expr_var

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

         | expr_bool LAND expr_var
         | expr_var LAND expr_bool
         | expr_var LAND expr_var
         
         | expr_bool LOR expr_var
         | expr_var LOR expr_bool
         | expr_var LOR expr_var

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

// Constant values
val : expr_int //{ std::cout << "=" << $1 << std::endl; }
    | expr_float //{ std::cout << "=" << $1 << std::endl; }
    | expr_str //{ std::cout << "=" << $1 << std::endl; }
    | expr_bool //{ std::cout << "=" << $1 << std::endl; }
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
         | slice
         | LPAR matrix RPAR
         | LPAR slice RPAR
         | LPAR range RPAR
         ; // TODO: Add compile time matrix simplification?
range : LPAR int_val RANGE int_val RPAR
      | LPAR int_val COMMA int_val RANGE int_val RPAR
      ;
int_val : expr_int
        | expr_var
        ;
slice : ID LSQ COLON RSQ
      | ID LSQ int_val COLON RSQ
      | ID LSQ COLON int_val RSQ
      | ID LSQ int_val COLON int_val RSQ
      | ID LSQ COLON COLON RSQ
      | ID LSQ int_val COLON COLON RSQ
      | ID LSQ COLON int_val COLON RSQ
      | ID LSQ COLON COLON int_val RSQ
      | ID LSQ int_val COLON int_val COLON RSQ
      | ID LSQ int_val COLON COLON int_val RSQ
      | ID LSQ COLON int_val COLON int_val RSQ
      | ID LSQ int_val COLON int_val COLON int_val RSQ
      | scope LSQ COLON RSQ
      | scope LSQ int_val COLON RSQ
      | scope LSQ COLON int_val RSQ
      | scope LSQ int_val COLON int_val RSQ
      | scope LSQ COLON COLON RSQ
      | scope LSQ int_val COLON COLON RSQ
      | scope LSQ COLON int_val COLON RSQ
      | scope LSQ COLON COLON int_val RSQ
      | scope LSQ int_val COLON int_val COLON RSQ
      | scope LSQ int_val COLON COLON int_val RSQ
      | scope LSQ COLON int_val COLON int_val RSQ
      | scope LSQ int_val COLON int_val COLON int_val RSQ
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
type : KWMAYBE KWMAYBE
     | KWINT KWMAYBE
     | KWFLOAT KWMAYBE
     | KWSTRING KWMAYBE
     | KWBOOL KWMAYBE
     | ID KWMAYBE
     | funtype KWMAYBE
     | mattype KWMAYBE
     | KWINT
     | KWFLOAT
     | KWSTRING
     | KWBOOL
     | ID
     | funtype
     | mattype
     ;

%%

/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    std::cerr << scanner->loc->begin.line << ":" << scanner->loc->begin.column << ": " << err_message << std::endl;
}