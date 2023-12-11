#include "function_analysis.hpp"
#include "ir.hpp"
#include "scanner.hpp"

using namespace ptc;

void FunctionAnalysis::checkReturnType(std::vector<ir::IR *> decls, int *num_found, int *nested_ret, ir::TypeDecl * expected) {
    for(auto decl : decls) {
        if(auto stmt = llvm::dyn_cast<ir::ReturnStmt>(decl)) {
            *num_found += 1;
            auto encl = stmt->getEnclosingIR();
            if(llvm::isa<ir::WhileStmt>(encl) || llvm::isa<ir::ForeachStmt>(encl)) { 
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
                return;
            }
        }
        else if(auto stmt = llvm::dyn_cast<ir::IfStatement>(decl)) {
            checkReturnType(stmt->getIfBranch(), num_found, nested_ret, expected);
            checkReturnType(stmt->getElseBranch(), num_found, nested_ret, expected);
        }
        else if(auto stmt = llvm::dyn_cast<ir::WhileStmt>(decl)) {
            checkReturnType(stmt->getBody(), num_found, nested_ret, expected);
        }
        else if(auto stmt = llvm::dyn_cast<ir::ForeachStmt>(decl)) {
            checkReturnType(stmt->getBody(), num_found, nested_ret, expected);
        }
    }
}

void FunctionAnalysis::countReturns(std::vector<ir::IR *> decls, int *num_found, int *nested_ret) {
    for(auto decl : decls) {
        if(auto stmt = llvm::dyn_cast<ir::ReturnStmt>(decl)) {
            *num_found += 1;
            auto encl = stmt->getEnclosingIR();
            if(llvm::isa<ir::WhileStmt>(encl) || llvm::isa<ir::ForeachStmt>(encl)) { 
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
        }
        else if(auto stmt = llvm::dyn_cast<ir::IfStatement>(decl)) {
            countReturns(stmt->getIfBranch(), num_found, nested_ret);
            countReturns(stmt->getElseBranch(), num_found, nested_ret);
        }
        else if(auto stmt = llvm::dyn_cast<ir::WhileStmt>(decl)) {
            countReturns(stmt->getBody(), num_found, nested_ret);
        }
        else if(auto stmt = llvm::dyn_cast<ir::ForeachStmt>(decl)) {
            countReturns(stmt->getBody(), num_found, nested_ret);
        }
    }
}

void FunctionAnalysis::checkReturns() {
    auto rtype = fun->getReturnType();
    auto body = fun->getDecl();
    int num_found = 0;
    int nested_ret = 0;
    // _entry cannot have return
    if(fun->getOGName() == _ENTRY_NAME) {
        countReturns(body, &num_found, &nested_ret);
        if(num_found > 0) {
            diags.report(fun->getLocation(), diag::ERR_MISPLACED_RETURN);
            return;
        }
    }
    else {
        checkReturnType(body, &num_found, &nested_ret, rtype);
        if(rtype->getName() != VOID_CSTR && num_found == 0) {
            diags.report(fun->getLocation(), diag::ERR_MISSING_RETURN, fun->getOGName());
            return;
        }
        else if(rtype->getName() != VOID_CSTR && num_found - nested_ret <= 0) {
            diags.report(fun->getLocation(), diag::ERR_MISSING_RETURN_IN_BRANCH, fun->getOGName());
            return;
        }
    }
}

void FunctionAnalysis::run() {
    checkReturns();
}