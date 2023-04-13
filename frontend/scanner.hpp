#ifndef _SCANNER_HPP_
#define _SCANNER_HPP_

// Flex include has to be guarded
#if ! defined(yyFlexLexerOnce)
#include "FlexLexer.h"
#endif
#include <istream>
#include <vector>
#include "parser.hpp"
#include "ir.hpp"
#include "expression.hpp"
#include "scope.hpp"

namespace ptc {

class Scanner : public yyFlexLexer {
private:
    ptc::Parser::semantic_type *yylval = nullptr;
    std::vector<ir::IR *> decls;

    ir::IR *currentIR;
    Scope *currScope;

    ir::TypeDecl *intType;
    ir::TypeDecl *floatType;
    ir::TypeDecl *stringType;
    ir::TypeDecl *boolType;

public:
    ptc::Parser::location_type *loc = nullptr;     ///< Current parsing location
    
    Scanner();
    void init();

    virtual int yylex(ptc::Parser::semantic_type *const lval,
                      ptc::Parser::location_type *location);

    void parse(std::istream *code);
    void removeQuotes(char **str);

};


}

#endif//_SCANNER_HPP_