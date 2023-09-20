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
#include "diagnostics.def"

namespace ptc {

std::string encodeFunction(std::string name, std::vector<ir::FormalParamDecl *> params);
std::string encodeFunction(std::string name, std::vector<ir::Expr *> params);

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

    // Type declarations for language types
    ir::TypeDecl *intType;
    ir::TypeDecl *floatType;
    ir::TypeDecl *stringType;
    ir::TypeDecl *boolType;
    ir::TypeDecl *voidType;
    ir::TypeDecl *noneType;
    ir::TypeDecl *rangeType;
    ir::TypeDecl *varargsType;
    ir::TypeDecl *unknownType;

    /**
     * Adds a custom generated matrix function (templated) to the symbol table
     * Based on the defined types there needs to be generic Matrix functions
     * generated (e.g. append, length...)
     * @param t Matrix type declaration
     * @param elemT Matrix element type
     */
    void addMatrixTemplatedFunction(ir::TypeDecl *t, ir::TypeDecl *elemT);
public:
    ptc::Parser::location_type *loc = nullptr;     ///< Current parsing location
    ir::ModuleDecl *mainModule;
    std::string moduleName;
    Scope *globalScope;

    Scanner(Diagnostics &diags, std::string moduleName);
    ~Scanner();

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
     * Parses escape sequences in read PT string to work with LLVM strings
     * @param str String to escape
     * @return escaped string str
     */
    std::string escapeString(std::string str);

    /**
     * Denotes that a new scope was entered during parsing for a given IR
     * @param decl IR which was entered
     */
    void enterScope(ir::IR *decl);
    /**
     * Denotes that a new function scope was entered of not yet known function
     * The function has to be later on set (once all the information is parsed)
     */
    void enterFunScope();
    /**
     * Works pretty much the same as enterFunScope, but has different logging
     * The IR has to be later on set (function is used as a placeholder)
     */
    void enterBlockScope();
    /**
     * Denotes that the current scope was left and a new one should be taken from the
     * stack of scopes
     */
    void leaveScope();
    /**
     * Reports fatal error using diag::diagmsg
     * If possible use the diags argument
     */
    void fatal_error(diag::diagmsg d, std::string msg);

    /**
     * Looks up a symbol in the current scope
     * @param name Symbol to lookup
     * @return The symbol if it is found or nullptr
     */
    ir::IR *sym_lookup(std::string name, bool isMaybe=false, bool fail_if_not_found=false) {
        LOGMAX("Symbol lookup: "+name);
        // Remove matrix brackets
        name.erase(std::remove(name.begin(), name.end(), '['), name.end());
        name.erase(std::remove(name.begin(), name.end(), ']'), name.end());
        auto rval = currScope->lookup(name, isMaybe);
        if(!rval && fail_if_not_found) {
            diags.report(llvmloc, diag::ERR_UNDEFINED_TYPE, name);
        }
        return rval;
    }

    // Parsing methods
    ir::IR *parseVarDecl(ir::IR *type, const std::string name, ir::Expr *value=nullptr);
    ir::IR *parseExprStmt(ir::Expr *e);
    ir::IR *parseIfStmt(ir::Expr *cond, std::vector<ir::IR *> &ifBranch, std::vector<ir::IR *> &elseBranch);
    ir::IR *parseWhile(ir::Expr *cond, std::vector<ir::IR *> &body);
    ir::IR *parseForeach(ir::Expr *i, ir::Expr *collection, std::vector<ir::IR *> &body, bool defineI=false);
    ir::IR *parseForeach(ir::IR *i, ir::Expr *collection, std::vector<ir::IR *> &body);
    ir::IR *parseDoWhile(ir::Expr *cond, std::vector<ir::IR *> &body);
    ir::IR *parseFun(ir::IR *type, std::string name, std::vector<ir::FormalParamDecl *> params, std::vector<ir::IR *> body);
    ir::IR *parseMatrixType(std::string name, std::vector<ir::Expr *> &matsize, bool isMaybe=false);
    ir::IR *parseReturn(ir::Expr *e);
    ir::IR *parseBreak();
    ir::IR *parseContinue();
    ir::IR *parseImports(std::vector<std::string> names);
    ir::Expr *parseInt(long v);
    ir::Expr *parseFloat(double v);
    ir::Expr *parseBool(bool v);
    ir::Expr *parseString(std::string v);
    ir::Expr *parseVar(std::string v, bool external=false);
    ir::Expr *parseMatrix(std::vector<ir::Expr *> values);
    ir::Expr *parseNone();
    ir::Expr *parseInfixExpr(ir::Expr *l, ir::Expr *r, ir::Operator op, bool is_const=false);
    ir::Expr *parseFunCall(ir::Expr *fun, std::vector<ir::Expr *> params);
    ir::Expr *parseRange(ir::Expr *start, ir::Expr *second, ir::Expr *end);
    ir::Expr *parseRange(ir::Expr *start, ir::Expr *end);
    std::vector<ir::Expr *> parseFunCallArg(ir::Expr *e);
    std::vector<ir::Expr *> parseAddFunCallArg(std::vector<ir::Expr *> &list, ir::Expr *e);
    std::vector<ir::Expr *> parseMatrixSize(ir::Expr *e);
    std::vector<ir::Expr *> parseAddMatrixSize(std::vector<ir::Expr *> &list, ir::Expr *e);
    std::vector<ir::Expr *> parseMatrixValue(ir::Expr *e);
    std::vector<ir::Expr *> parseAddMatrixValue(std::vector<ir::Expr *> &list, ir::Expr *e);
    std::vector<ir::FormalParamDecl *> parseFunParam(ir::IR *type, std::string name);
    std::vector<ir::FormalParamDecl *> parseAddFunParam(std::vector<ir::FormalParamDecl *> &list, ir::IR *type, std::string name);
    std::vector<std::string> parseImportName(std::string name);
    std::vector<std::string> parseAddImportName(std::vector<std::string> &list, std::string name);
    std::vector<ir::IR *> parseStmtBody(ir::IR *stmt);
    std::vector<ir::IR *> parseStmtBodyAdd(std::vector<ir::IR *> &body, ir::IR *stmt);
    ir::IR *parseStruct(std::string name, std::vector<ir::IR *> body);
    ir::IR *parseStructElement(ir::IR *type, const std::string name, ir::Expr *value=nullptr);
    std::vector<ir::IR *> parseAddStructElement(ir::IR *elem, std::vector<ir::IR *> body);
    void parseEntry(std::vector<ir::IR *> body);
};


}

#endif//_SCANNER_HPP_