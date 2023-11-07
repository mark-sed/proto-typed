/**
 * @file resolver.cpp
 * @author Marek Sedlacek
 * @brief Resolver for analysis that cannot be done in scanner
 * 
 * @copyright Copyright (c) 2023
 * Resolves types and does additional analysis that can be done
 * only after the whole IR is generated.
 */

#include "resolver.hpp"
#include "scanner.hpp"
#include "llvm/Support/Casting.h"
#include <initializer_list>
#include <algorithm>

using namespace ptc;

void UnresolvedSymbolResolver::resolve(ir::Expr * expr, llvm::SMLoc loc) {
    if(auto e = llvm::dyn_cast<ir::FunctionCall>(expr)) {
        for(auto a : e->getParams()) {
            resolve(a, loc);
        }
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
                    // Lib functions
                    // first try adding the arguments to the name
                    std::string appendix = "";
                    for(auto p: e->getParams()) {
                        appendix+="_"+p->getType()->getName();
                    }
                    propFIR = globalScope->lookup(e->getUnresolvedFun()->getName()+appendix);
                }
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
        if(e->getOperator().getKind() == ir::OperatorKind::OP_ACCESS && llvm::isa<ir::UnresolvedSymbolAccess>(e->getRight())) {
            // FIX: Type of e->getLeft()->getDecl() is somehow nullptr?!
            // --> works: LOGMAX(e->getLeft()->getType()->getDecl()->debug());

            auto elem = llvm::dyn_cast<ir::UnresolvedSymbolAccess>(e->getRight());
            auto struDecl = llvm::dyn_cast<ir::StructDecl>(e->getLeft()->getType()->getDecl());
            if(struDecl) {
                // Check if the element is present in the struct
                ir::IR *found = nullptr;
                int index = 0;
                for(index = 0; static_cast<size_t>(index) < struDecl->getElements().size(); ++index) {
                    if(struDecl->getElements()[index]->getName() == elem->getName()) {
                        found = struDecl->getElements()[index];
                        break;
                    }
                }
                if(found) {
                    if(auto fvar = llvm::dyn_cast<ir::VarDecl>(found)) {
                        e->setType(fvar->getType());
                        //auto oldR = r;
                        e->setRight(new ir::MemberAccess(found, index, fvar->getType()));
                        this->scanner->prependDecl(struDecl);
                        // FIXME: delete oldR
                        //delete oldR;
                        return;
                    }
                    else if(auto fvar = llvm::dyn_cast<ir::StructDecl>(found)) {
                        //TODO: Handle and set r correctly
                        (void)fvar;
                        diags.report(loc, diag::ERR_INTERNAL, "NOT YET IMPLEMENTED Structs inside of structs access");
                    }
                    else {
                        diags.report(loc, diag::ERR_INTERNAL, "unknown element type in a struct");
                    }
                }
                else {
                    diags.report(loc, diag::ERR_HAS_NO_MEMBER, "struct "+struDecl->getName(), elem->getName());
                }
            }
            else {
                diags.report(loc, diag::ERR_TYPE_NOT_STRUCT, e->getLeft()->getType()->getName());
            }


            return;
        }
        else {
            resolve(e->getRight(), loc);
        }
        
        // Unknown matrix type
        if(e->getOperator().getKind() == ir::OperatorKind::OP_ASSIGN &&
                llvm::isa<ir::MatrixLiteral>(e->getRight()) &&
                e->getRight()->getType()->getName() == UNKNOWN_CSTR) {
            if(e->getLeft()->getType()->getName() == UNKNOWN_CSTR) {
                diags.report(loc, diag::ERR_CANNOT_INFER_TYPE, e->getLeft()->debug());
            }
            e->getRight()->setType(e->getLeft()->getType());
        }
        auto newe = scanner->parseInfixExpr(e->getLeft(), e->getRight(), e->getOperator(), e->isConst());
        expr->setType(newe->getType());
    }
    else if(auto e = llvm::dyn_cast<ir::UnaryPrefixExpr>(expr)) {
        resolve(e->getExpr(), loc);
        
        auto newe = scanner->parseUnaryPrefixExpr(e->getExpr(), e->getOperator(), e->isConst());
        expr->setType(newe->getType());
    }
    else if(auto e = llvm::dyn_cast<ir::MatrixLiteral>(expr)) {
        for(auto v: e->getValue()) {
            resolve(v, loc);
        }
    }
    else if(auto e = llvm::dyn_cast<ir::Range>(expr)) {
        resolve(e->getStart(), loc);
        resolve(e->getStep(), loc);
        resolve(e->getEnd(), loc);
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
    else if(auto e = llvm::dyn_cast<ir::VarAccess>(expr)) {
        resolve(e->getVar());
    }
}

void UnresolvedSymbolResolver::resolve(ir::IR* i) {
    // Statements to resolve further
    if(auto *stmt = llvm::dyn_cast<ir::ReturnStmt>(i)) {
        if(stmt->getValue())
            resolve(stmt->getValue(), stmt->getLocation());
    }
    else if(auto *stmt = llvm::dyn_cast<ir::FunctionDecl>(i)) {
        resolve(stmt->getDecl());
    }
    else if(auto *stmt = llvm::dyn_cast<ir::WhileStmt>(i)) {
        resolve(stmt->getCond(), stmt->getLocation());
        resolve(stmt->getBody());
    }
    else if(auto *stmt = llvm::dyn_cast<ir::ForeachStmt>(i)) {
        resolve(stmt->getI(), stmt->getLocation());
        resolve(stmt->getCollection(), stmt->getLocation());
        resolve(stmt->getBody());
    }
    else if(auto *stmt = llvm::dyn_cast<ir::IfStatement>(i)) {
        resolve(stmt->getCond(), stmt->getLocation());
        resolve(stmt->getIfBranch());
        resolve(stmt->getElseBranch());
    }
    else if(auto *stmt = llvm::dyn_cast<ir::ExprStmt>(i)) {
        resolve(stmt->getExpr(), stmt->getLocation());   
    }
    else if(auto *stmt = llvm::dyn_cast<ir::VarDecl>(i)) {
        if(stmt->getInitValue() && stmt->getInitValue()->getType()->getName() == UNKNOWN_CSTR) {
            auto *e = stmt->getInitValue();
            e->setType(stmt->getType());
        }   
    }
}

void UnresolvedSymbolResolver::resolve(std::vector<ir::IR *> body) {
    for(auto *i : body) {
        resolve(i);
    }
}

void UnresolvedSymbolResolver::run() {
    auto decls = mod->getDecls();
    resolve(decls);
}

void ExternalSymbolResolver::resolve(ir::IR *i) {
    // Statements to resolve further
    if(auto *stmt = llvm::dyn_cast<ir::ReturnStmt>(i)) {
        if(stmt->getValue())
            resolve(stmt->getValue(), stmt->getLocation());
    }
    else if(auto *stmt = llvm::dyn_cast<ir::FunctionDecl>(i)) {
        resolve(stmt->getDecl());
    }
    else if(auto *stmt = llvm::dyn_cast<ir::WhileStmt>(i)) {
        resolve(stmt->getCond(), stmt->getLocation());
        resolve(stmt->getBody());
    }
    else if(auto *stmt = llvm::dyn_cast<ir::ForeachStmt>(i)) {
        resolve(stmt->getI(), stmt->getLocation());
        resolve(stmt->getCollection(), stmt->getLocation());
        resolve(stmt->getBody());
    }
    else if(auto *stmt = llvm::dyn_cast<ir::IfStatement>(i)) {
        resolve(stmt->getCond(), stmt->getLocation());
        resolve(stmt->getIfBranch());
        resolve(stmt->getElseBranch());
    }
    else if(auto *stmt = llvm::dyn_cast<ir::ExprStmt>(i)) {
        auto e = stmt->getExpr();
        resolve(e, stmt->getLocation());
    }
    else if(auto *stmt = llvm::dyn_cast<ir::VarDecl>(i)) {
        auto stmtT = stmt->getType();
        // Resolve type
        if(stmtT->isUnresolved()) {
            LOGMAX("Resolving external vardecl "+stmt->debug());
            ModuleInfo *symbMod = getModule(stmtT->getExternalIR()->getModuleName());
            if(!symbMod) {
                diags.report(i->getLocation(), diag::ERR_UNKNOWN_MODULE, stmtT->getExternalIR()->getModuleName());
            }

            auto symb = symbMod->getScanner()->globalScope->lookup(stmtT->getExternalIR()->getSymbolName());
            if(!symb) {
                diags.report(i->getLocation(), diag::ERR_UNDEFINED_EXT_TYPE, stmtT->getExternalIR()->getSymbolName(), stmtT->getExternalIR()->getModuleName());
            }

            if(auto smt = llvm::dyn_cast<ir::TypeDecl>(symb)) {
                stmt->setType(smt);
                stmt->getType()->setUnresolved(false);
            }
            else {
                diags.report(i->getLocation(), diag::ERR_NOT_A_TYPE, stmtT->getName());
            }
        } 

        if(stmt->getInitValue() && stmt->getInitValue()->getType()->getName() == UNKNOWN_CSTR) {
            auto *e = stmt->getInitValue();
            e->setType(stmt->getType());
        }   
    }
}

void ExternalSymbolResolver::resolve(std::vector<ir::IR *> body) {
    for(auto *i: body) {
        resolve(i);
    }
}

ModuleInfo *ExternalSymbolResolver::getModule(std::string name) {
    for(auto m: allModules) {
        if(m->getName() == name) {
            return m;
        }
    }
    return nullptr;
}

void ExternalSymbolResolver::resolve(ir::Expr *expr, llvm::SMLoc loc) {
    if(auto e = llvm::dyn_cast<ir::ExternalSymbolAccess>(expr)) {
        LOGMAX("Resolving external symbol "+e->debug());
        ModuleInfo *symbMod = getModule(e->getModuleName());

        if(!symbMod) {
            diags.report(loc, diag::ERR_UNKNOWN_MODULE, e->getModuleName());
        }

        // TODO: check functions some other way?
        auto symb = symbMod->getScanner()->globalScope->lookup(e->getSymbolName());
        if(!symb) {
            diags.report(loc, diag::ERR_UNDEFINED_EXT_VAR, e->getSymbolName(), e->getModuleName());
        }

        e->setModDecl(symbMod->getModule());
        if(auto s = llvm::dyn_cast<ir::VarDecl>(symb)) {
            expr->setType(s->getType());
            e->setExtIR(s);
        }
        // TODO: implement other
        else {
            llvm::report_fatal_error("UNIMPLEMENTED OTHER IRS");
        }
    }
    else if(auto e = llvm::dyn_cast<ir::FunctionCall>(expr)) {
        for(auto a : e->getParams()) {
            resolve(a, loc);
        }
        if(e->isExternal()) {
            auto name = e->getExternalFun()->getSymbolName();
            LOGMAX("Resolving external function "+name);
            ModuleInfo *symbMod = getModule(e->getExternalFun()->getModuleName());
            if(!symbMod) {
                diags.report(loc, diag::ERR_UNKNOWN_MODULE, e->getExternalFun()->getModuleName());
            }
            if(!symbMod->getScanner()->globalScope->lookupPossibleFun(name)) {
                // Undefined
                diags.report(loc, diag::ERR_UNDEFINED_VAR, name);
            }
            else {
                std::string properName = encodeFunction(name, e->getParams());
                auto propFIR = symbMod->getScanner()->globalScope->lookup(properName);
                if(!propFIR) {
                    // Lib functions
                    // first try adding the arguments to the name
                    std::string appendix = "";
                    for(auto p: e->getParams()) {
                        appendix+="_"+p->getType()->getName();
                    }
                    propFIR = symbMod->getScanner()->globalScope->lookup(e->getExternalFun()->getSymbolName()+appendix);
                }
                if(!propFIR) {
                    diags.report(loc, diag::ERR_INCORRECT_ARGS, name);
                }
                else {
                    LOGMAX("Resolved external function "+name)
                    auto propF = llvm::dyn_cast<ir::FunctionDecl>(propFIR);
                    e->setFun(propF);
                    e->setType(propF->getReturnType());
                }
            }
        }
    }
    else if(auto e = llvm::dyn_cast<ir::BinaryInfixExpr>(expr)) {
        resolve(e->getLeft(), loc);
        resolve(e->getRight(), loc);

        auto newe = scanner->parseInfixExpr(e->getLeft(), e->getRight(), e->getOperator(), e->isConst());
        expr->setType(newe->getType());
    }
    else if(auto e = llvm::dyn_cast<ir::UnaryPrefixExpr>(expr)) {
        resolve(e->getExpr(), loc);
    }
    else if(auto e = llvm::dyn_cast<ir::MatrixLiteral>(expr)) {
        for(auto v: e->getValue()) {
            resolve(v, loc);
        }
    }
    else if(auto e = llvm::dyn_cast<ir::Range>(expr)) {
        resolve(e->getStart(), loc);
        resolve(e->getStep(), loc);
        resolve(e->getEnd(), loc);
    }
    else if(auto e = llvm::dyn_cast<ir::VarAccess>(expr)) {
        if(auto stmt = llvm::dyn_cast<ir::VarDecl>(e->getVar())) {
            auto stmtT = stmt->getType();
            if(stmtT->isUnresolved()) {
                LOGMAX("Resolving external VarAccess "+e->debug());
                ModuleInfo *symbMod = getModule(stmtT->getExternalIR()->getModuleName());
                if(!symbMod) {
                    diags.report(loc, diag::ERR_UNKNOWN_MODULE, stmtT->getExternalIR()->getModuleName());
                }

                auto symb = symbMod->getScanner()->globalScope->lookup(stmtT->getExternalIR()->getSymbolName());
                if(!symb) {
                    diags.report(loc, diag::ERR_UNDEFINED_EXT_TYPE, stmtT->getExternalIR()->getSymbolName(), stmtT->getExternalIR()->getModuleName());
                }

                if(auto smt = llvm::dyn_cast<ir::TypeDecl>(symb)) {
                    stmt->setType(smt);
                }
                else {
                    diags.report(loc, diag::ERR_NOT_A_TYPE, stmtT->getName());
                }
            }
            else if(e->getType()->isUnresolved()) {
                LOGMAX("Resolving varaccess type "+e->debug());
                e->setType(stmt->getType());
                e->getType()->setUnresolved(false);
            }
        }
    }
}

void ExternalSymbolResolver::run() {
    auto decls = currMod->getModule()->getDecls();
    resolve(decls);
}

void FunctionAnalyzer::checkReturnType(std::vector<ir::IR *> decls, int *num_found, int *nested_ret, ir::TypeDecl * expected) {
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