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

%%
%{
    yylval = lval;    
%}

{ws} /* Ignore spaces and tabs */
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

{string}        { 
                    yylval->build<std::string>(yytext);
                    return token::STRING;
                }

.               { std::cout << "ERROR" << std::endl; }
%%