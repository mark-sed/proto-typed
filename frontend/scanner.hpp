/**
 * @file scanner.hpp
 * @author Marek Sedlacek
 * @brief Scanner and parsing driver (semantics)
 * @date 2023-04-20
 * 
 * @copyright Copyright (c) 2023
 * Takes care of scanning, parsing and creating
 * IR from parsed code.
 */

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
#include "scope.hpp"
#include "logging.hpp"

namespace ptc {

/**
 * Scanning, parsing and semantics driver
 */
class Scanner : public yyFlexLexer {
private:
    ptc::Parser::semantic_type *yylval = nullptr;
    std::vector<ir::IR *> decls;

    ir::IR *currentIR;
    Scope *currScope;
    Diagnostics &diags;

    llvm::SMLoc llvmloc;

    ir::TypeDecl *intType;
    ir::TypeDecl *floatType;
    ir::TypeDecl *stringType;
    ir::TypeDecl *boolType;

public:
    ptc::Parser::location_type *loc = nullptr;     ///< Current parsing location
    
    Scanner(Diagnostics &diags);

    /**
     * Initializer method to be called before parsing
     */
    void init();

    virtual int yylex(ptc::Parser::semantic_type *const lval,
                      ptc::Parser::location_type *location);

    /**
     * Starts parsing of the given code
     * @param code Code to be parsed
     */
    void parse(std::istream *code);

    /**
     * Removes quotes from a string
     * @param str String with quotes
     * @note The method does no checking, it just removes
     *       the first and last character
     */
    void removeQuotes(char **str);

    /**
     * Looks up a symbol in the current scope
     * @param name Symbol to lookup
     * @return The symbol if it is found or nullptr
     */
    ir::IR *sym_lookup(llvm::StringRef name) {
        LOGMAX("Symbol lookup: "+name.str());
        return currScope->lookup(name);
    }

    // Parsing methods
    ir::IR *parseVarDecl(ir::IR *type, std::string name);
    void parseVarDef(ir::IR *type, std::string name, ir::Expr *value);
    ir::IR *parseExprStmt(ir::Expr *e);
    ir::Expr *parseInt(long v);
    ir::Expr *parseFloat(double v);
    ir::Expr *parseBool(bool v);
    ir::Expr *parseString(std::string v);
    ir::Expr *parseVar(std::string v);
    ir::Expr *parseInfixExpr(ir::Expr *l, ir::Expr *r, ir::Operator op, bool is_const=false);
    ir::Expr *parseFunCall(ir::Expr *fun, std::vector<ir::Expr *> params);
    std::vector<ir::Expr *> parseFunCallArg(ir::Expr *e);
    std::vector<ir::Expr *> parseAddFunCallArg(std::vector<ir::Expr *> &list, ir::Expr *e);
};


}

#endif//_SCANNER_HPP_