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
#include "parser.hpp"
#include "scanner.hpp"
#include "llvm/Support/Casting.h"
#include <initializer_list>
#include <algorithm>

using namespace ptc;

void UnresolvedSymbolResolver::resolve(ir::Expr * expr, ir::SourceInfo loc) {
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
                return;
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
                    return;
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
                        return;
                    }
                    else {
                        diags.report(loc, diag::ERR_INTERNAL, "unknown element type in a struct");
                        return;
                    }
                }
                else {
                    diags.report(loc, diag::ERR_HAS_NO_MEMBER, "struct "+struDecl->getName(), elem->getName());
                    return;
                }
            }
            else {
                diags.report(loc, diag::ERR_TYPE_NOT_STRUCT, e->getLeft()->getType()->getName());
                return;
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
                return;
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
    else if(auto e = llvm::dyn_cast<ir::StructLiteral>(expr)) {
        for(auto [_, v]: e->getValues()) {
            resolve(v, loc);
        }
    }
    else if(auto e = llvm::dyn_cast<ir::Range>(expr)) {
        resolve(e->getStart(), loc);
        if(e->getStep()) {
            resolve(e->getStep(), loc);
        }
        resolve(e->getEnd(), loc);
    }
    else if(auto e = llvm::dyn_cast<ir::UnresolvedSymbolAccess>(expr)) {
        // TODO: Handle function pointer
        if(globalScope->lookupPossibleFun(e->getName())) {
            diags.report(loc, diag::ERR_INTERNAL, "Function pointers are not yet implemented in resolver");
            return;
        }
        else {
            diags.report(loc, diag::ERR_UNDEFINED_VAR, e->getName());
            return;
        }
    }
    else if(auto e = llvm::dyn_cast<ir::VarAccess>(expr)) {
        resolve(e->getVar());
    }
}

void UnresolvedSymbolResolver::resolveEmptyArray(ir::Expr *expr, ir::SourceInfo loc, ir::TypeDecl *deductedType) {
    // If deducted type is nullptr, then report as not inferable
    if(auto ml = llvm::dyn_cast<ir::MatrixLiteral>(expr)) {
        if(expr->getType()->getBaseName() == UNKNOWN_CSTR) {
            LOGMAX("Resolving array "+expr->debug());
            if(!deductedType)
                diags.report(loc, diag::ERR_CANNOT_INFER_TYPE, ml->debug());
            expr->setType(deductedType);
            LOGMAX("Resolved array as "+expr->debug());
        }
        if(expr->getType()->getDimensions() > 1) {
            // Go through all values and override deducted if some is set
            for(auto e : ml->getValue()) {
                resolveEmptyArray(e, loc, llvm::dyn_cast<ir::TypeDecl>(deductedType->getDecl()));
            }
        }
    }
}

void UnresolvedSymbolResolver::resolveEmptyArrays(ir::Expr *expr, ir::SourceInfo loc) {
    // TODO: Handle return type resolution
    if(auto e = llvm::dyn_cast<ir::BinaryInfixExpr>(expr)) {
        auto left = e->getLeft();
        auto right = e->getRight();
        ir::TypeDecl *dedT = llvm::dyn_cast<ir::TypeDecl>(left->getType());
        if(dedT->getBaseName() == UNKNOWN_CSTR) {
            dedT = right->getType();
        }
        if(dedT->getBaseName() == UNKNOWN_CSTR) {
            diags.report(loc, diag::ERR_CANNOT_INFER_TYPE, e->debug());
        }
        if(right->getType()->isMatrix()) {
            resolveEmptyArray(right, loc, llvm::dyn_cast<ir::TypeDecl>(left->getType()));
        }
    }
    else if(auto e = llvm::dyn_cast<ir::FunctionCall>(expr)) {
        for(size_t i = 0; i < e->getParams().size(); ++i) {
            // Get FunDecl types, if this function is not known, then
            // the type for an empty array might not be deductable -
            // emit error. But it is deductiable if it contains
            // other elements e.g. [[],[1]], but [[]] is not.
            auto fun = e->getFun();
            if(llvm::isa<ir::MatrixLiteral>(e->getParams()[i])) {
                if(!fun) {
                    // TODO: Some cases can be handled here -> [[],[1]]
                    resolveEmptyArray(e->getParams()[i], loc, nullptr);
                }
                else {
                    resolveEmptyArray(e->getParams()[i], loc, llvm::dyn_cast<ir::TypeDecl>(fun->getParams()[i]->getType()));
                }
            }
        }
    }
}

void UnresolvedSymbolResolver::resolve(ir::IR* i) {
    // Statements to resolve further
    if(auto *stmt = llvm::dyn_cast<ir::ReturnStmt>(i)) {
        if(stmt->getValue()) {
            resolve(stmt->getValue(), stmt->getLocation());
            resolveEmptyArrays(stmt->getValue(), stmt->getLocation());
        }
    }
    else if(auto *stmt = llvm::dyn_cast<ir::FunctionDecl>(i)) {
        resolve(stmt->getDecl());
    }
    else if(auto *stmt = llvm::dyn_cast<ir::WhileStmt>(i)) {
        resolve(stmt->getCond(), stmt->getLocation());
        resolveEmptyArrays(stmt->getCond(), stmt->getLocation());
        resolve(stmt->getBody());
    }
    else if(auto *stmt = llvm::dyn_cast<ir::ForeachStmt>(i)) {
        resolve(stmt->getI(), stmt->getLocation());
        resolveEmptyArrays(stmt->getI(), stmt->getLocation());
        resolve(stmt->getCollection(), stmt->getLocation());
        resolveEmptyArrays(stmt->getCollection(), stmt->getLocation());
        resolve(stmt->getBody());
    }
    else if(auto *stmt = llvm::dyn_cast<ir::IfStatement>(i)) {
        resolve(stmt->getCond(), stmt->getLocation());
        resolveEmptyArrays(stmt->getCond(), stmt->getLocation());
        resolve(stmt->getIfBranch());
        resolve(stmt->getElseBranch());
    }
    else if(auto *stmt = llvm::dyn_cast<ir::ExprStmt>(i)) {
        resolveEmptyArrays(stmt->getExpr(), stmt->getLocation());
        resolve(stmt->getExpr(), stmt->getLocation());
    }
    else if(auto *stmt = llvm::dyn_cast<ir::VarDecl>(i)) {
        if(stmt->getInitValue() && stmt->getInitValue()->getType()->getName() == UNKNOWN_CSTR) {
            auto *e = stmt->getInitValue();
            resolveEmptyArrays(e, stmt->getLocation());
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
        if(stmt->getReturnType()->isUnresolved()) {
            stmt->setReturnType(resolveType(stmt->getReturnType(), stmt->getLocation()));
        }
        for(auto p : stmt->getParams()) {
            resolve(p);
        }
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
                return;
            }

            auto symb = symbMod->getScanner()->globalScope->lookup(stmtT->getExternalIR()->getSymbolName());
            if(!symb) {
                diags.report(i->getLocation(), diag::ERR_UNDEFINED_EXT_TYPE, stmtT->getExternalIR()->getSymbolName(), stmtT->getExternalIR()->getModuleName());
                return;
            }

            if(auto smt = llvm::dyn_cast<ir::TypeDecl>(symb)) {
                stmt->setType(smt);
                stmt->getType()->setUnresolved(false);
            }
            else {
                diags.report(i->getLocation(), diag::ERR_NOT_A_TYPE, stmtT->getName());
                return;
            }
        } 

        if(stmt->getInitValue() && stmt->getInitValue()->getType()->getName() == UNKNOWN_CSTR) {
            auto *e = stmt->getInitValue();
            e->setType(stmt->getType());
        }   
    }
    else if(auto *stmt = llvm::dyn_cast<ir::FormalParamDecl>(i)) {
        if(stmt->getType()->isUnresolved()) {
            stmt->setType(resolveType(stmt->getType(), stmt->getLocation()));
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

void ExternalSymbolResolver::resolveType(ir::Expr **expr, ir::SourceInfo loc) {
    ir::Expr *e = *expr;
    ir::TypeDecl *t = e->getType();
    if(t->isUnresolved()) {
        e->setType(resolveType(t, loc));
    }
}

ir::TypeDecl *ExternalSymbolResolver::resolveType(ir::TypeDecl *t, ir::SourceInfo loc) {
    if(t->isUnresolved()) {
        LOGMAX("Resolving type "+t->debug());
        auto er = t->getExternalIR();
        ModuleInfo *symbMod = getModule(er->getModuleName());
        if(!symbMod) {
            diags.report(loc, diag::ERR_UNKNOWN_MODULE, er->getModuleName());
            return t;
        }
        auto symb = symbMod->getScanner()->globalScope->lookup(er->getSymbolName());
        if(!symb) {
            diags.report(loc, diag::ERR_UNDEFINED_EXT_TYPE, t->getName());
            return t;
        }

        er->setModDecl(symbMod->getModule());
        if(auto s = llvm::dyn_cast<ir::TypeDecl>(symb)) {
            return s;
        }
        else {
            diags.report(loc, diag::ERR_NOT_A_TYPE, t->getName());
            return t;
        }
    }
    return t;
}

void ExternalSymbolResolver::resolve(ir::Expr *expr, ir::SourceInfo loc) {
    resolveType(&expr, loc);
    if(auto e = llvm::dyn_cast<ir::ExternalSymbolAccess>(expr)) {
        LOGMAX("Resolving external symbol "+e->debug());
        ModuleInfo *symbMod = getModule(e->getModuleName());

        if(!symbMod) {
            diags.report(loc, diag::ERR_UNKNOWN_MODULE, e->getModuleName());
            return;
        }

        // TODO: check functions some other way?
        auto symb = symbMod->getScanner()->globalScope->lookup(e->getSymbolName());
        if(!symb) {
            diags.report(loc, diag::ERR_UNDEFINED_EXT_VAR, e->getSymbolName(), e->getModuleName());
            return;
        }

        e->setModDecl(symbMod->getModule());
        if(auto s = llvm::dyn_cast<ir::VarDecl>(symb)) {
            expr->setType(s->getType());
            e->setExtIR(s);
        }
        else if(auto s = llvm::dyn_cast<ir::TypeDecl>(symb)) {
            expr->setType(s);
            e->setExtIR(s);
        }
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
                return;
            }
            if(!symbMod->getScanner()->globalScope->lookupPossibleFun(name)) {
                // Undefined
                diags.report(loc, diag::ERR_UNDEFINED_VAR, name);
                return;
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
                    return;
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
    else if(auto e = llvm::dyn_cast<ir::StructLiteral>(expr)) {
        for(auto [_, v]: e->getValues()) {
            resolve(v, loc);
        }

        auto t = e->getType();
        if(!t) {
            diags.report(loc, diag::ERR_TYPE_NOT_STRUCT, t->getName());
            return;
        }
        if(!t->getDecl() || !llvm::isa<ir::StructDecl>(t->getDecl())) {
            diags.report(loc, diag::ERR_TYPE_NOT_STRUCT, t->getName());
            return;
        }
        // This cast is checked above
        auto sdt = llvm::dyn_cast<ir::StructDecl>(t->getDecl());
        // Check key correctness
        for(auto [k, v] : e->getValues()) {
            ir::VarDecl *elemD = nullptr;
            for(auto el : sdt->getElements()) {
                if(el->getName() == k) {
                    elemD = llvm::dyn_cast<ir::VarDecl>(el);
                    break;
                }
            }
            if(!elemD) {
                diags.report(loc, diag::ERR_HAS_NO_MEMBER, "struct "+t->getName(), k);
                continue;
            } else if(elemD->getType()->getName() != v->getType()->getName()) {
                diags.report(loc, diag::ERR_INCORRECT_ASSIGNMENT, elemD->getType()->getName(), v->getType()->getName());
                continue;
            }
        }
    }
    else if(auto e = llvm::dyn_cast<ir::Range>(expr)) {
        resolve(e->getStart(), loc);
        if(e->getStep()) {
            resolve(e->getStep(), loc);
        }
        resolve(e->getEnd(), loc);
    }
    else if(auto e = llvm::dyn_cast<ir::VarAccess>(expr)) {
        if(auto stmt = llvm::dyn_cast<ir::VarDecl>(e->getVar())) {
            auto stmtT = stmt->getType();
            if(stmtT->isUnresolved()) {
                stmt->setType(resolveType(stmtT, stmt->getLocation()));
            }
            if(e->getType()->isUnresolved()) {
                LOGMAX("Resolving varaccess type "+e->debug());
                e->setType(stmt->getType());
            }
        }
    }
}

void ExternalSymbolResolver::run() {
    auto decls = currMod->getModule()->getDecls();
    resolve(decls);
}
