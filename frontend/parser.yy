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
%token <std::string> VOID "void"

/* Operators */
%token <std::string> LPAR "("
%token <std::string> RPAR ")"
%token <std::string> LSQ "["
%token <std::string> RSQ "]"
%token <std::string> LBR "{"
%token <std::string> RBR "}"
%token <std::string> PLUS "+"
%token <std::string> MUL "*"
%token <std::string> MINUS "-"
%token <std::string> DIV "/"
%token <std::string> MOD "%"
%token <std::string> POW "**"

%token <std::string> LAND "and"
%token <std::string> LOR "or"
%token <std::string> LNOT "not"
%token <std::string> IN "in"

%token <std::string> BAND "&"
%token <std::string> BOR "|"
%token <std::string> BXOR "^"
%token <std::string> BNOT "~"
%token <std::string> BLSHFT "<<"
%token <std::string> BRSHFT ">>"

%token <std::string> EQ "=="
%token <std::string> NEQ "!="
%token <std::string> BT ">"
%token <std::string> LT "<"
%token <std::string> BEQ ">="
%token <std::string> LEQ "<="

/* Keywords */
%token <std::string> VAR "var"
%token <std::string>  ""

/* Associativity and precedence */
%left LOR
%left LAND
%left IN
%left BOR
%left BXOR
%left BAND
%left EQ NEQ
%left BT BEQ LT LEQ
%left BLSHFT BRSHFT
%left PLUS MINUS
%left MUL DIV MOD
%right POW
%right LNOT BNOT


%precedence INT
%precedence FLOAT

%precedence NEG

%locations

%%

start : END_FILE
      | END start
      ;

%%

/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    std::cerr << scanner->loc->begin.line << ":" << scanner->loc->begin.column << ": " << err_message << std::endl;
}