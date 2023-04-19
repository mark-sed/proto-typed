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
    void init();

    virtual int yylex(ptc::Parser::semantic_type *const lval,
                      ptc::Parser::location_type *location);

    void parse(std::istream *code);
    void removeQuotes(char **str);

    ir::IR *sym_lookup(llvm::StringRef name) {
        LOGMAX("Symbol lookup: "+name.str());
        return currScope->lookup(name);
    }

    ir::IR *parseVarDecl(ir::IR *type, std::string name);
    ir::IR *parseExprStmt(ir::Expr *e);

    ir::Expr *parseAssignment(ir::Expr *dst, ir::Expr *value);
    ir::Expr *parseInt(long v);
    ir::Expr *parseFloat(double v);
    ir::Expr *parseBool(bool v);
    ir::Expr *parseString(std::string v);
    ir::Expr *parseVar(std::string v);
    ir::Expr *parseInfixExpr(ir::Expr *l, ir::Expr *r, ir::Operator op, bool is_const=false);
};


}

#endif//_SCANNER_HPP_