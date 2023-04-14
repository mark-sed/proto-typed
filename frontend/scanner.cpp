#include "scanner.hpp"
#include "logging.hpp"
#include <cstring>

using namespace ptc;

Scanner::Scanner() : currentIR(nullptr) {
    loc = new Parser::location_type();
    init();
}

void Scanner::init() {
    currScope = new Scope();
    currentIR = nullptr;
    
    intType = new ir::TypeDecl(currentIR, llvm::SMLoc(), "int");
    floatType = new ir::TypeDecl(currentIR, llvm::SMLoc(), "float");
    stringType = new ir::TypeDecl(currentIR, llvm::SMLoc(), "string");
    boolType = new ir::TypeDecl(currentIR, llvm::SMLoc(), "bool");

    currScope->insert(intType);
    currScope->insert(boolType);
    currScope->insert(floatType);
    currScope->insert(stringType);
}

void Scanner::parse(std::istream *code) {
    this->switch_streams(code);
    loc = new Parser::location_type();
    auto parser = new Parser(this);

    if(parser->parse() != 0) {
        // TODO: ERROR
        log::error("Could not parse the source code.");
        exit(1);
    }
}

void Scanner::removeQuotes(char **str) {
    // Remove first quote
    *str = &(*str)[1];
    // Remove last quote
    (*str)[std::strlen(*str)-1] = '\0';
}
