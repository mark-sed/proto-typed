#include "resolver.hpp"
#include "scanner.hpp"
#include "llvm/Support/Casting.h"
#include <initializer_list>

using namespace ptc;

void UnresolvedSymbolResolver::resolve(ir::Expr * expr, llvm::SMLoc loc) {
    if(auto e = llvm::dyn_cast<ir::FunctionCall>(expr)) {
        if(e->isUnresolved()) {
            LOGMAX("Resolving function "+e->getUnresolvedFun()->getName());
            auto name = e->getUnresolvedFun()->getName();
            if(!globalScope->lookupPossibleFun(name)) {
                // Undefined
                diags.report(loc, diag::ERR_UNDEFINED_VAR, name);
            }
            else {
                std::string properName = encodeFunction(name, e->getParams());
                auto propFIR = globalScope->lookup(properName);
                if(!propFIR) {
                    diags.report(loc, diag::ERR_INCORRECT_ARGS, name);
                }
                else {
                    LOGMAX("Resolved function "+name)
                    auto propF = llvm::dyn_cast<ir::FunctionDecl>(propFIR);
                    e->setFun(propF);
                    e->setUnresolved(false);
                    e->setType(propF->getReturnType());
                }
            }
        }
    }
    else if(auto e = llvm::dyn_cast<ir::BinaryInfixExpr>(expr)) {
        resolve(e->getLeft(), loc);
        resolve(e->getRight(), loc);
    }
    else if(auto e = llvm::dyn_cast<ir::UnaryPrefixExpr>(expr)) {
        resolve(e->getExpr(), loc);
    }
    else if(auto e = llvm::dyn_cast<ir::UnresolvedSymbolAccess>(expr)) {
        // TODO: Handle function pointer
        if(globalScope->lookupPossibleFun(e->getName())) {
            diags.report(loc, diag::ERR_INTERNAL, "Function pointers are not yet implemented in resolver");
        }
        else {
            diags.report(loc, diag::ERR_UNDEFINED_VAR, e->getName());
        }
    }
}

void UnresolvedSymbolResolver::resolve(std::vector<ir::IR *> body) {
    for(auto i : body) {
        // Statements to resolve further
        if(auto stmt = llvm::dyn_cast<ir::ReturnStmt>(i)) {
            if(stmt->getValue())
                resolve(stmt->getValue(), stmt->getLocation());
        }
        else if(auto stmt = llvm::dyn_cast<ir::FunctionDecl>(i)) {
            resolve(stmt->getDecl());
        }
        else if(auto stmt = llvm::dyn_cast<ir::WhileStmt>(i)) {
            resolve(stmt->getBody());
        }
        else if(auto stmt = llvm::dyn_cast<ir::ExprStmt>(i)) {
            resolve(stmt->getExpr(), stmt->getLocation());   
        }
    }
}

void UnresolvedSymbolResolver::run() {
    auto decls = mod->getDecls();
    resolve(decls);
}

void FunctionAnalyzer::checkReturnType(std::vector<ir::IR *> decls, int *num_found, int *nested_ret, ir::TypeDecl * expected) {
    for(auto decl : decls) {
        if(auto stmt = llvm::dyn_cast<ir::ReturnStmt>(decl)) {
            *num_found += 1;
            auto encl = stmt->getEnclosingIR();
            if(llvm::isa<ir::WhileStmt>(encl)) { // TODO: Add for loop
                *nested_ret += 1;
            }
            else if(auto ifs = llvm::dyn_cast<ir::IfStatement>(encl)) {
                // Add to nested only if only one branch has return
                // But some may be nested
                // if(t) { return 1 } else { if(m) { return 1; } else { return 4; } }
                // Don't add to nested if this is in true branch and false branch has return as well
                *nested_ret += 1;
                auto trbr = ifs->getIfBranch();
                if(std::find(trbr.begin(), trbr.end(), decl) != trbr.end()) {
                    auto flbr = ifs->getElseBranch();
                    if(std::count_if(flbr.begin(), flbr.end(), 
                       [](ir::IR *i) { return llvm::isa<ir::ReturnStmt>(i); }) > 0) {
                        *nested_ret -= 1;
                    }
                }
            }
            
            std::string tname = "void";
            if(stmt->getValue()) {
                tname = stmt->getValue()->getType()->getName();
            }
            if(tname != expected->getName()) {
                diags.report(stmt->getLocation(), diag::ERR_INCORRECT_RET_TYPE,
                            fun->getOGName(),
                            tname,
                            expected->getName());
            }
        }
        else if(auto stmt = llvm::dyn_cast<ir::IfStatement>(decl)) {
            checkReturnType(stmt->getIfBranch(), num_found, nested_ret, expected);
            checkReturnType(stmt->getElseBranch(), num_found, nested_ret, expected);
        }
        else if(auto stmt = llvm::dyn_cast<ir::WhileStmt>(decl)) {
            checkReturnType(stmt->getBody(), num_found, nested_ret, expected);
        }
        // TODO: Add for loop
    }
}

void FunctionAnalyzer::checkReturns() {
    auto rtype = fun->getReturnType();
    auto body = fun->getDecl();
    int num_found = 0;
    int nested_ret = 0;
    // TODO: Handle implicit conversions ?
    checkReturnType(body, &num_found, &nested_ret, rtype);
    if(rtype->getName() != VOID_CSTR && num_found == 0) {
        diags.report(fun->getLocation(), diag::ERR_MISSING_RETURN, fun->getOGName());
    }
    else if(rtype->getName() != VOID_CSTR && num_found - nested_ret <= 0) {
        diags.report(fun->getLocation(), diag::ERR_MISSING_RETURN_IN_BRANCH, fun->getOGName());
    }
}

void FunctionAnalyzer::run() {
    checkReturns();
}