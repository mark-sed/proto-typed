#include "scanner.hpp"
#include "error.hpp"
#include <cstring>

using namespace ptc;

Scanner::Scanner() {
    loc = new Parser::location_type();
}

void Scanner::parse(std::istream *code) {
    this->switch_streams(code);
    loc = new Parser::location_type();
    auto parser = new Parser(this);

    if(parser->parse() != 0) {
        // TODO: ERROR
        err::error("Could not parse the source code.");
        exit(1);
    }
}

void Scanner::remove_quotes(char **str) {
    // Remove first quote
    *str = &(*str)[1];
    // Remove last quote
    (*str)[std::strlen(*str)-1] = '\0';
}
