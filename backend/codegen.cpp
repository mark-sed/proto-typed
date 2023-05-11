#include "codegen.hpp"
#include "logging.hpp"
#include "ir.hpp"
#include "llvm/ADT/StringExtras.h"
#include "llvm/IR/CFG.h"
#include "llvm/Support/Casting.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"

using namespace ptc;

cg::CodeGenHandler *cg::CodeGenHandler::create(llvm::LLVMContext &ctx, llvm::TargetMachine *target) {
    return new CodeGenHandler(ctx, target);
}

std::unique_ptr<llvm::Module> cg::CodeGenHandler::run(ir::ModuleDecl *module, std::string fileName) {
    std::unique_ptr<llvm::Module> m = std::make_unique<llvm::Module>(fileName, ctx);
    m->setTargetTriple(target->getTargetTriple().getTriple());
    m->setDataLayout(target->createDataLayout());
    cg::CGModule cgm(m.get());
    cgm.run(module);
    return m;
}

void cg::CodeGen::init() {
    voidT = llvm::Type::getVoidTy(ctx);
    int1T = llvm::Type::getInt1Ty(ctx);
    int64T = llvm::Type::getInt64Ty(ctx);
    doubleT = llvm::Type::getDoubleTy(ctx);
}

llvm::Type *cg::CodeGen::convertType(ir::TypeDecl *t) {
    if(t->getName() == INT_CSTR) {
        return int64T;
    }
    if(t->getName() == BOOL_CSTR) {
        return int1T;
    }
    if(t->getName() == VOID_CSTR) {
        return voidT;
    }
    if(t->getName() == FLOAT_CSTR) {
        return doubleT;
    }
    llvm::report_fatal_error("Unsupported type");
    return nullptr;
}

std::string cg::CodeGen::mangleName(ir::IR *ir) {
    std::string mangled;
    while(ir) {
        mangled.insert(0, ir->getName()+"_");
        ir = ir->getEnclosingIR();
    }
    mangled.insert(0, "_ptc_");
    return mangled;
}

llvm::Type *cg::CodeGen::mapType(ir::IR *decl) {
    if(auto *fp = llvm::dyn_cast<ir::FormalParamDecl>(decl)) {
        llvm::Type *t = convertType(fp->getType());
        if(fp->isByReference()) {
            t = t->getPointerTo();
        }
        return t;
    }
    if(auto *v = llvm::dyn_cast<ir::VarDecl>(decl)) {
        return convertType(v->getType());
    }
    return convertType(llvm::cast<ir::TypeDecl>(decl));
}

void cg::CGModule::writeVar(llvm::BasicBlock *BB, ir::IR *decl, llvm::Value *val) {
    /*if(llvm::dyn_cast<ir::VarDecl>(decl)) {
        LOGMAX("Writing variable in module");
        builder.CreateStore(val, getGlobals(decl));
    } else {
        llvm::report_fatal_error("Unsupported variable access");
    }*/
    llvm::report_fatal_error("UNIMPLEMENTED module var read");
}

void cg::CGFunction::writeVar(llvm::BasicBlock *BB, ir::IR *decl, llvm::Value *val) {
    if(auto *v = llvm::dyn_cast<ir::VarDecl>(decl)) {
        if(v->getEnclosingIR() == fun) {
            // TODO:
            //writeLocalVar(BB, decl, val);
        }
        else if(v->getEnclosingIR() == cgm.getModuleDecl()) {
            builder.CreateStore(val, cgm.getGlobals(decl));
        }
        else {
            llvm::report_fatal_error("Unsupported variable access in module");
        }
    } else if (auto *v = llvm::dyn_cast<ir::FormalParamDecl>(decl)) {
        if(v->isByReference()) {
            builder.CreateStore(val, formalParams[v]);
        }
        else {
            // TODO:
            //writeLocalVar(BB, decl, val);
        }
    } else {
        llvm::report_fatal_error("Unsupported variable access");
    }
}

llvm::Value *cg::CGModule::readVar(llvm::BasicBlock *BB, ir::IR *decl) {
    /*if(auto *v = llvm::dyn_cast<ir::VarDecl>(decl)) {
        if(v->getEnclosingIR()->getKind() == ir::IRKind::IR_MODULE_DECL) {
            return builder.CreateLoad(mapType(v), getGlobals(decl));
        }
        else {
            llvm::report_fatal_error("Unsupported variable access in module");
        }
    } else {
        llvm::report_fatal_error("Unsupported variable declaration");
    }*/
    llvm::report_fatal_error("UNIMPLEMENTED module var read");
}

llvm::Value *cg::CGFunction::readLocalVar(llvm::BasicBlock *BB, ir::IR *decl) {
    // TODO: Checks for type
    
    // TODO: implement
    return nullptr;
}

llvm::Value *cg::CGFunction::readVar(llvm::BasicBlock *BB, ir::IR *decl) {
    if(auto *v = llvm::dyn_cast<ir::VarDecl>(decl)) {
        if(v->getEnclosingIR()->getKind() == ir::IRKind::IR_MODULE_DECL) {
            return builder.CreateLoad(mapType(v), currModule.getGlobals(decl));
        }
        else if(v->getEnclosingIR() == fun) {
            return readLocalVar(BB, decl);
        }
        else {
            llvm::report_fatal_error("Nested functions are not supported");
        }
    } else if(auto *v = llvm::dyn_cast<ir::FormalParamDecl>(decl)) {
        if(v->isByReference()) {
            return builder.CreateLoad(mapType(v)->getNonOpaquePointerElementType(), formalParams[v]);
        }
    } else {
        llvm::report_fatal_error("Unsupported variable declaration");
    }
    return nullptr;
}

llvm::Value *cg::CodeGen::emitExpr(ir::Expr *e) {
    switch(e->getKind()) {
    case ir::ExprKind::EX_BIN_INF: return emitInfixExpr(llvm::dyn_cast<ir::BinaryInfixExpr>(e));
    case ir::ExprKind::EX_VAR:
    {
        auto *decl = llvm::dyn_cast<ir::VarAccess>(e)->getVar();
        return readVar(currBB, decl);
    }
    case ir::ExprKind::EX_INT:
        LOGMAX("Accessing int value");
        return llvm::ConstantInt::get(int64T, llvm::dyn_cast<ir::IntLiteral>(e)->getValue());
    case ir::ExprKind::EX_BOOL: return llvm::ConstantInt::get(int1T, llvm::dyn_cast<ir::BoolLiteral>(e)->getValue());
    // TODO: Double
    // TODO: Other ones
    default:
        llvm::report_fatal_error("Unimplemented expression kind in code generation");
        return nullptr;
    }
}

llvm::Value *cg::CodeGen::emitInfixExpr(ir::BinaryInfixExpr *e) {
    llvm::Value *left = emitExpr(e->getLeft());
    llvm::Value *right = emitExpr(e->getRight());
    llvm::Value *result = nullptr;
    switch(e->getOperator().getKind()) {
    case ir::OperatorKind::OP_ASSIGN:
    {
        LOGMAX("Creating assignment instruction");
        auto var = llvm::dyn_cast<ir::VarAccess>(e->getLeft());
        auto varDecl = llvm::dyn_cast<ir::VarDecl>(var->getVar());
        writeVar(currBB, varDecl, right);
    }
    break;
    case ir::OperatorKind::OP_ADD:
    {
        LOGMAX("Creating ADD instruction");
        if(left->getType() == this->int64T && left->getType() == right->getType()) {
            result = builder.CreateNSWAdd(left, right);
        }
        else {
            llvm::report_fatal_error("ADD does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_SUB:
    {
        LOGMAX("Creating SUB instruction");
        if(left->getType() == this->int64T && left->getType() == right->getType()) {
            result = builder.CreateNSWSub(left, right);
        }
        else {
            llvm::report_fatal_error("SUB does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_POW:
    {
        // TODO:
    }
    break;
    case ir::OperatorKind::OP_MUL:
    {
        LOGMAX("Creating MUL instruction");
        if(left->getType() == this->int64T && left->getType() == right->getType()) {
            result = builder.CreateNSWMul(left, right);
        }
        else {
            llvm::report_fatal_error("MUL does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_DIV:
    {
        LOGMAX("Creating DIV instruction");
        if(left->getType() == this->int64T && left->getType() == right->getType()) {
            result = builder.CreateSDiv(left, right);
        }
        else {
            llvm::report_fatal_error("DIV does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_MOD:
    {
        LOGMAX("Creating MOD instruction");
        if(left->getType() == this->int64T && left->getType() == right->getType()) {
            result = builder.CreateSRem(left, right);
        }
        else {
            llvm::report_fatal_error("MOD does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_BLSHFT:
    {

    }
    break;
    case ir::OperatorKind::OP_BRSHFT:
    {

    }
    break;
    case ir::OperatorKind::OP_BT:
    {
        LOGMAX("Creating BT instruction");
        if(left->getType() == right->getType()) {
            result = builder.CreateICmpSGT(left, right);
        }
        else {
            llvm::report_fatal_error("BT does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_BEQ:
    {
        LOGMAX("Creating BEQ instruction");
        if(left->getType() == right->getType()) {
            result = builder.CreateICmpSGE(left, right);
        }
        else {
            llvm::report_fatal_error("BEQ does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_LT:
    {
        LOGMAX("Creating LT instruction");
        if(left->getType() == right->getType()) {
            result = builder.CreateICmpSLT(left, right);
        }
        else {
            llvm::report_fatal_error("LT does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_LEQ:
    {
        LOGMAX("Creating LEQ instruction");
        if(left->getType() == right->getType()) {
            result = builder.CreateICmpSLE(left, right);
        }
        else {
            llvm::report_fatal_error("LEQ does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_EQ:
    {
        LOGMAX("Creating EQ instruction");
        if(left->getType() == right->getType()) {
            result = builder.CreateICmpEQ(left, right);
        }
        else {
            llvm::report_fatal_error("EQ does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_NEQ:
    {
        LOGMAX("Creating NEQ instruction");
        if(left->getType() == right->getType()) {
            result = builder.CreateICmpNE(left, right);
        }
        else {
            llvm::report_fatal_error("NEQ does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_BAND:
    {

    }
    break;
    case ir::OperatorKind::OP_BXOR:
    {

    }
    break;
    case ir::OperatorKind::OP_BOR:
    {

    }
    break;
    case ir::OperatorKind::OP_IN:
    {

    }
    break;
    case ir::OperatorKind::OP_LAND:
    {
        LOGMAX("Creating AND instruction");
        if(left->getType() == int1T && left->getType() == right->getType()) {
            result = builder.CreateAnd(left, right);
        }
        else {
            llvm::report_fatal_error("AND does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_LOR:
    {
        LOGMAX("Creating OR instruction");
        if(left->getType() == int1T && left->getType() == right->getType()) {
            result = builder.CreateOr(left, right);
        }
        else {
            llvm::report_fatal_error("OR does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_CONCAT:
    {
        // TODO:
    }
    break;
    // TODO: implement rest
    default: llvm::report_fatal_error("Uknown operator in code generation");
    }
    return result;
}

void cg::CodeGen::emitStmt(ir::ExprStmt *stmt) {
    ir::Expr *e = stmt->getExpr();
    emitExpr(e);
}

void cg::CGFunction::emit(std::vector<ir::IR *> stmts) {
    for(auto *s : stmts) {
        if(auto *stmt = llvm::dyn_cast<ir::ExprStmt>(s)) {
            emitStmt(stmt);
        }
        //else {
        //    llvm::report_fatal_error("Unknwon statement in code generation");
        //}
    }
}

void cg::CGModule::run(ir::ModuleDecl *mod) {
    this->mod = mod;
    for(auto *decl: mod->getDecls()) {
        auto kind = decl->getKind();
        switch(kind) {
        case ir::IRKind::IR_VAR_DECL:
        {   // new variable needs its own scope
            auto var = llvm::dyn_cast<ir::VarDecl>(decl);
            llvm::GlobalVariable *v = new llvm::GlobalVariable(*llvmMod,
                                                               convertType(var->getType()),
                                                               false,
                                                               llvm::GlobalValue::PrivateLinkage,
                                                               nullptr,
                                                               mangleName(var));
            globals[var] = v;
        }
        break;
        case ir::IRKind::IR_FUNCTION_DECL:
        {
            auto *fun = llvm::dyn_cast<ir::FunctionDecl>(decl);
            CGFunction cgf(*this);
            cgf.run(fun);
        }
        break;
        default: //llvm::report_fatal_error("Code generation invoked for not yet implemented IR");
        break;
        }
    }
}

llvm::FunctionType *cg::CGFunction::createFunctionType(ir::FunctionDecl *fun) {
    // FIXME: Handle values passed by reference
    llvm::Type *retType = mapType(fun->getReturnType());
    llvm::SmallVector<llvm::Type *> paramTypes;
    for(auto p : fun->getParams()) {
        llvm::Type *t = mapType(p);
        paramTypes.push_back(t);
    }
    return llvm::FunctionType::get(retType, paramTypes, false);
}

llvm::Function *cg::CGFunction::createFunction(ir::FunctionDecl *fun, llvm::FunctionType *funType) {
    llvm::Function *f = llvm::Function::Create(funType, 
                                               llvm::GlobalValue::ExternalLinkage,
                                               mangleName(fun),
                                               cgm.getLLVMMod());
    size_t idx = 0;
    for(auto i = f->arg_begin(); i != f->arg_end(); ++i, ++idx) {
        llvm::Argument *arg = i;
        ir::FormalParamDecl *param = fun->getParams()[idx];
        if(param->isByReference()) {
            // FIXME: Handle referenced params
        }
        arg->setName(param->getName());
    }
    return f;
}

void cg::CGFunction::run(ir::FunctionDecl *fun) {
    this->fun = fun;
    funType = createFunctionType(fun);
    this->llvmFun = createFunction(fun, funType);

    llvm::BasicBlock *bb = llvm::BasicBlock::Create(cgm.getLLVMCtx(), "entry", llvmFun);
    setCurrBB(bb);

    size_t idx = 0;
    auto &defs = currDef[bb];
    for(auto i = llvmFun->arg_begin(); i != llvmFun->arg_end(); ++i, ++idx) {
        llvm::Argument *arg = i;
        ir::FormalParamDecl *fp = fun->getParams()[idx];
        formalParams[fp] = arg;
        defs.defs.insert(std::pair<ir::IR *, llvm::Value *>(fp, arg));
    }

    for(auto *d : fun->getDecl()) {
        if(auto *var = llvm::dyn_cast<ir::VarDecl>(d)) {
            llvm::Type *ty = mapType(var);
            if(ty->isAggregateType()) {
                llvm::Value *val = builder.CreateAlloca(ty);
                defs.defs.insert(std::pair<ir::IR *, llvm::Value *>(var, val));
            }
        }
    }

    auto block = fun->getDecl();
    emit(fun->getDecl());
    if(!currBB->getTerminator()) {
        builder.CreateRetVoid();
    }
    //sealBlock(currBB);
}

//void cg::CGFunction::run() { }