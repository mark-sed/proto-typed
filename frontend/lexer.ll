/**
 * Grammar file for Flex tool for Proto-typed language
 * @copyright Marek Sedlacek, 2023
 */

%{

#include <string>
#include "scanner.hpp"
#include "logging.hpp"

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
id      [a-zA-Z_][a-zA-Z0-9_]*
hex     0[Xx][0-9A-Fa-f]+
bin     0[Bb][01]+
oct     0[Qq][0-7]+

%%
%{
    yylval = lval;
%}

{ws}            { /* Ignore spaces and tabs */; }
"/*"        	  { /* Multiline comment */
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
";"             { return token::END; }

"("             { return token::LPAR; }
")"             { return token::RPAR; }
"["             { return token::LSQ; }
"]"             { return token::RSQ; }
"{"             { return token::LBR; }
"}"             { return token::RBR; }

"++="           { return token::SETCONCAT; }
"**="           { return token::SETPOW; }
"+="            { return token::SETPLUS; }
"-="            { return token::SETMINUS; }
"/="            { return token::SETDIV; }
"*="            { return token::SETMUL; }
"%="            { return token::SETMOD; }

"&="            { return token::SETBAND; }
"|="            { return token::SETBOR; }
"^="            { return token::SETBXOR; }
"~="            { return token::SETBNOT; }
"<<="           { return token::SETBLSHFT; }
">>="           { return token::SETBRSHFT; }

"++"            { return token::CONCAT; }
"**"            { return token::POW; }
"+"             { return token::PLUS; }
"-"             { return token::MINUS; }
"/"             { return token::DIV; }
"*"             { return token::MUL; }
"%"             { return token::MOD; }

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
"?"             { return token::KWMAYBE; }

"var"           { return token::KWVAR; }
"any"           { return token::KWANY; }
"import"        { return token::KWIMPORT; }
"if"            { return token::KWIF; }
"else"          { return token::KWELSE; }
"for"           { return token::KWFOR; }
"while"         { return token::KWWHILE; }
"do"            { return token::KWDO; }
"return"        { return token::KWRETURN; }
"break"         { return token::KWBREAK; }
"continue"      { return token::KWCONTINUE; }
"const"         { return token::KWCONST; }
"int"           { return token::KWINT; }
"float"         { return token::KWFLOAT; }
"string"        { return token::KWSTRING; }
"bool"          { return token::KWBOOL; }
"struct"        { return token::KWSTRUCT; }
"void"          { return token::KWVOID; }
"range"         { return token::KWRANGE; }

"true"          {
                  yylval->emplace<bool>(true);
                  return token::BOOL; 
                }
"false"         {
                  yylval->emplace<bool>(false);
                  return token::BOOL; 
                }
"none"          {
                  //yylval->emplace<>();
                  return token::NONE; 
                }
"r\""           { // Raw string
                  std::string txt;
                  int c;
                  bool esc = false;
                  while((c = yyinput()) != 0) {
                      if(static_cast<char>(c) == '\"' && !esc) {
                        break;
                      }
                      if(esc && static_cast<char>(c) != '\"') {
                        txt += '\\';
                      }
                      if(!esc && static_cast<char>(c) == '\\') {
                        esc = true;
                        continue;
                      }
                      else {
                        esc = false;
                      }
                      txt += c;
                  }
                  yylval->build<std::string>(txt);
                  return token::STRING;
                }
"\""            { // String
                  std::string txt;
                  int c;
                  bool esc = false;
                  while((c = yyinput()) != 0) {
                      if(static_cast<char>(c) == '\"' && !esc) {
                        break;
                      }
                      if(!esc && static_cast<char>(c) == '\\') {
                        esc = true;
                      }
                      else {
                        esc = false;
                      }
                      txt += c;
                  }
                  yylval->build<std::string>(escapeString(txt));
                  return token::STRING;
                }

[-]?[0-9]+      { /* Integer (long) */
                  // atol can be used since syntactical analysis was done here
                  yylval->emplace<long>(atol(yytext));
                  return token::INT;
                }
[-]?{hex}       { /* Hex Integer (long) */
                  // atol can be used since syntactical analysis was done here
                  yylval->emplace<long>(std::strtol(yytext, nullptr, 16));
                  return token::INT;
                }
[-]?{bin}       { /* Binary Integer (long) */
                  // atol can be used since syntactical analysis was done here
                  yylval->emplace<long>(std::strtol(&(yytext[2]), nullptr, 2));
                  return token::INT;
                }
[-]?{oct}       { /* Octal Integer (long) */
                  // atol can be used since syntactical analysis was done here
                  yylval->emplace<long>(std::strtol(&(yytext[2]), nullptr, 8));
                  return token::INT;
                }
[-]?[0-9]+\.?[0-9]+[eE][+-]?[0-9]+ {   // Float in scientific notation
                  yylval->build<double>(std::stod(yytext)); 
                  return token::FLOAT;
                }
[-]?[0-9]+\.?[0-9]+[eE][+-]?[0-9]+ {   // Float in scientific notation
                  yylval->build<double>(std::stod(yytext)); 
                  return token::FLOAT;
                }
[-]?[0-9]+\.[0-9]+ {   // Float
                  yylval->build<double>(std::stod(yytext)); 
                  return token::FLOAT;
                }
[-]?[0-9]+\.[0-9]+ {   // Float
                  yylval->build<double>(std::stod(yytext));
                  return token::FLOAT;
                }
{id}::{id}      {
                    yylval->build<std::string>(yytext);
                    return token::EXT_ID;
                }
{id}            {
                    yylval->build<std::string>(yytext);
                    return token::ID;
                }
.               {
                  auto msg = std::string("ERROR: Unknown token '")+ yytext + std::string("'");
                  ptc::log::error(msg);
                }
%%