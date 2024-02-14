/**
 * @file constant_folder.hpp
 * @author Marek Sedlacek
 * @brief Constant folding
 * 
 * @copyright Copyright (c) 2024
 */

#ifndef _CONSTANT_FOLDER_HPP_
#define _CONSTANT_FOLDER_HPP_

#include "logging.hpp"
#include "scanner.hpp"
#include <cassert>

namespace ptc {

class ConstantFolder {
private:
    ir::ModuleDecl *mod;
    Scanner *scanner;
    Diagnostics &diags;

    ir::TypeDecl *noneType;

    ir::Expr *getDefaultInitValue(ir::TypeDecl *t);
    ir::Expr *foldExpr(ir::Expr *e);

public:
    ConstantFolder(ir::ModuleDecl *mod, Scanner *scanner, Diagnostics &diags) : mod(mod), scanner(scanner), diags(diags) {
        auto noneTypeIR = scanner->sym_lookup(NONETYPE_CSTR);
        assert(noneTypeIR && "None type is not in a symbol table");
        auto noneType = llvm::dyn_cast<ir::TypeDecl>(noneTypeIR);
        assert(noneType && "None type is not a type");
    }
    void run();
};

}

#endif//_CONSTANT_FOLDER_HPP_