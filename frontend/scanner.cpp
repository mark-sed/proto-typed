#include "scanner.hpp"

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
        std::cerr << "ERROR!" << std::endl;
        exit(1);
    }
}