#ifndef _SCANNER_HPP_
#define _SCANNER_HPP_

// Flex include has to be guarded
#if ! defined(yyFlexLexerOnce)
#include "FlexLexer.h"
#endif
#include <istream>
#include "parser.hpp"

namespace ptc {

class Scanner : public yyFlexLexer {
private:
    ptc::Parser::semantic_type *yylval = nullptr;

public:
    ptc::Parser::location_type *loc = nullptr;     ///< Current parsing location
    
    Scanner();

    virtual int yylex(ptc::Parser::semantic_type *const lval,
                      ptc::Parser::location_type *location);

    void parse(std::istream *code);
};


}

#endif//_SCANNER_HPP_