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
string	\"[^\n"]*\"
id      [a-zA-Z_][a-zA-Z0-9_]*
hex     0[Xx][0-9A-Fa-f]+

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
";"             { return token::END; }

"("             { return token::LPAR; }
")"             { return token::RPAR; }
"["             { return token::LSQ; }
"]"             { return token::RSQ; }
"{"             { return token::LBR; }
"}"             { return token::RBR; }
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

"var"           { return token::KWVAR; }
"import"        { return token::KWIMPORT; }
"if"            { return token::KWIF; }
"elif"          { return token::KWELIF; }
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

"true"          { 
                  yylval->emplace<bool>(true);
                  return token::BOOL; 
                }
"false"         { 
                  yylval->emplace<bool>(false);
                  return token::BOOL; 
                }
"r"{string}     { /* Raw string */
                  auto no_pref = (yytext + 1);
                  remove_quotes(&no_pref);
                  yylval->build<std::string>(yytext);
                  return token::STRING;
                }
{string}        { /* String */
                  remove_quotes(&yytext);
                  // TODO: Process escape chars
                  yylval->build<std::string>(yytext);
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
[-]?[0-9]+\.?[0-9]*[eE][+-]?[0-9]+ {   // Float in scientific notation
                  yylval->build<double>(std::stod(yytext)); 
                  return token::FLOAT;
                }
[-]?[0-9]*\.?[0-9]+[eE][+-]?[0-9]+ {   // Float in scientific notation
                  yylval->build<double>(std::stod(yytext)); 
                  return token::FLOAT;
                }
[-]?[0-9]*\.[0-9]+ {   // Float
                  yylval->build<double>(std::stod(yytext)); 
                  return token::FLOAT;
                }
[-]?[0-9]+\.[0-9]* {   // Float
                  yylval->build<double>(std::stod(yytext)); 
                  return token::FLOAT;
                }
{id}            {
                    yylval->build<std::string>(yytext);
                    return token::ID;
                }
.               { std::cout << "ERROR: Unknown token '" << yytext << "'" << std::endl; }
%%