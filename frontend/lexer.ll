/**
 * Grammar file for Flex tool for Proto-typed language
 * @copyright Marek Sedlacek, 2023
 */

%{

#include <string>
#include "scanner.hpp"

// Define custom lex method
#undef YY_DECL
#define YY_DECL int ptc::Scanner::yylex(ptc::Parser::semantic_type * const lval, ptc::Parser::location_type *location)

#define YY_USER_ACTION loc->step(); loc->columns(yyleng);

// Typedef to shorten scope
using token = ptc::Parser::token;

// Redefine termination token to not use NULL
#define yyterminate() return (token::END_FILE)

#include <iostream>
%}

%option nodefault
%option noyywrap
%option c++
%option yylineno

/* Define what scanner class is used */
%option yyclass="ptc::Scanner"

ws      [ \t]
string	\"[^\n"]+\"
id      [a-zA-Z_][a-zA-Z0-9_]*

%%
%{
    yylval = lval;    
%}

{ws}            { /* Ignore spaces and tabs */; }
"/*"        	{   /* Multiline comment */
                    int c; 
                    while((c = yyinput()) != 0) {
                        if(c == '\n') {
                            loc->lines();
                        }
                        else if(c == '*') {
                            if((c = yyinput()) == '/')
                                break;
                            else
                                unput(c);
                        }
                    }
                }
"//".*          { /* Line comment */ ; }
\n              {
                  loc->lines();
                  return token::END;
                }

"("             { return token::LPAR; }
")"             { return token::RPAR; }
"["             { return token::LSQ; }
"]"             { return token::RSQ; }
"{"             { return token::LBR; }
"}"             { return token::RBR; }
"+"             { return token::PLUS; }
"-"             { return token::MINUS; }
"/"             { return token::DIV; }
"%"             { return token::MOD; }
"**"            { return token::POW; }
"++"            { return token::CONCAT; }

"and"           { return token::LAND; }
"or"            { return token::LOR; }
"not"           { return token::LNOT; }
"in"            { return token::IN; }

"&"             { return token::BAND; }
"|"             { return token::BOR; }
"^"             { return token::BXOR; }
"~"             { return token::BNOT; }
"<<"            { return token::BLSHFT; }
">>"            { return token::BRSHFT; }

"=="            { return token::EQ; }
"!="            { return token::NEQ; }
">"             { return token::BT; }
"<"             { return token::LT; }
">="            { return token::BEQ; }
"<="            { return token::LEQ; }

".."            { return token::RANGE; }
"."             { return token::DOT; }
","             { return token::COMMA; }
":"             { return token::COLON; }

"="             { return token::SET; }

"var"           { return token::KWVAR; }
"import"        { return token::KWIMPORT; }
"as"            { return token::KWAS; }
"from"          { return token::KWFROM; }
"if"            { return token::KWIF; }
"elif"          { return token::KWELIF; }
"else"          { return token::KWELSE; }
"for"           { return token::KWFOR; }
"while"         { return token::KWWHILE; }
"do"            { return token::KWDO; }
"int"           { return token::KWINT; }
"float"         { return token::KWFLOAT; }
"string"        { return token::KWSTRING; }
"bool"          { return token::KWBOOL; }
"void"          { return token::KWVOID; }
"struct"        { return token::KWSTRUCT; }

{string}        { 
                    yylval->build<std::string>(yytext);
                    return token::STRING;
                }
{id}            {
                    yylval->build<std::string>(yytext);
                    return token::ID;
                }
.               { std::cout << "ERROR" << std::endl; }
%%