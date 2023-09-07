#include "codegen.hpp"
#include "logging.hpp"
#include "utils.hpp"
#include "ir.hpp"
#include "llvm/ADT/StringExtras.h"
#include "llvm/IR/CFG.h"
#include "llvm/Support/Casting.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Instructions.h"
#include "llvm/ADT/ArrayRef.h"
#include "llvm/IR/Attributes.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/StringMap.h"
#include <vector>

using namespace ptc;
using namespace ptc::cg;

cg::CGModule::CGModule(llvm::Module *llvmMod) : cg::CodeGen(llvmMod->getContext(), *this), llvmMod(llvmMod) {
    ptlibLoader = new PTLib(this, llvmMod, ctx);
}

CGModule::~CGModule() {
    delete ptlibLoader;
}

cg::CodeGenHandler *cg::CodeGenHandler::create(llvm::LLVMContext &ctx, llvm::TargetMachine *target) {
    return new CodeGenHandler(ctx, target);
}

llvm::StringMap<std::pair<llvm::Type *, llvm::Constant *>> cg::CodeGen::userTypes{};

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
    floatT = llvm::Type::getDoubleTy(ctx);

    std::vector<llvm::Type*> structElements{
        builder.getInt8Ty()->getPointerTo(),
        builder.getInt32Ty(),
        builder.getInt32Ty(),
        builder.getInt32Ty()
    };
    stringT = llvm::StructType::create(ctx, structElements, STRING_CSTR);
    stringTPtr = stringT->getPointerTo();

    std::vector<llvm::Type*> matrixElements{
        builder.getInt8Ty()->getPointerTo(),
        builder.getInt32Ty(),
        builder.getInt32Ty(),
        builder.getInt32Ty()
    };
    matrixT = llvm::StructType::create(ctx, matrixElements, MATRIX_CSTR);
    matrixTPtr = matrixT->getPointerTo();
}

llvm::Type *cg::CodeGen::convertType(ir::TypeDecl *t) {
    if(t->isMatrix()) {
        return matrixT;
    }
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
        return floatT;
    }
    if(t->getName() == STRING_CSTR) {
        return stringT;
    }
    if(t->getDecl()) {
        if(auto *v = llvm::dyn_cast<ir::StructDecl>(t->getDecl())) {
            std::string manName = mangleName(v);
            return userTypes[manName].first;
        }
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
    llvm::report_fatal_error("UNIMPLEMENTED module var write");
}

void cg::CGFunction::writeLocalVar(llvm::BasicBlock *BB, ir::IR *decl, llvm::Value *val) {
    assert(BB && "Basic block is nullptr");
    assert(
        (llvm::isa<ir::VarDecl>(decl) ||
        llvm::isa<ir::FormalParamDecl>(decl)) &&
        "Declaration must be variable or formal parameter");
    assert(val && "Value is nullptr");
    currDef[BB].defs[decl] = val;
}

void cg::CGFunction::writeVar(llvm::BasicBlock *BB, ir::IR *decl, llvm::Value *val) {
    if(auto *v = llvm::dyn_cast<ir::VarDecl>(decl)) {
        if(v->getEnclosingIR() == cgm.getModuleDecl()) {
            builder.CreateStore(val, cgm.getGlobals(decl));
        }
        else {
            writeLocalVar(BB, decl, val);
        }
    } else if (auto *v = llvm::dyn_cast<ir::FormalParamDecl>(decl)) {
        if(v->isByReference()) {
            builder.CreateStore(val, formalParams[v]);
        }
        else {
            writeLocalVar(BB, decl, val);
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
    auto val = currDef[BB].defs.find(decl);
    if(val != currDef[BB].defs.end()) {
        return val->second;
    }
    return readLocalVarRecursive(BB, decl);
}

llvm::Value *cg::CGFunction::readLocalVarRecursive(llvm::BasicBlock *BB, ir::IR *decl) {
    // TODO: Checks for type
    llvm::Value *val = nullptr;
    if(!currDef[BB].sealed) {
        // incomplete for var
        llvm::PHINode *phi = addEmptyPhi(BB, decl);
        currDef[BB].incompletePhis[phi] = decl;
        val = phi;
    }
    else if(auto *predBB = BB->getSinglePredecessor()) {
        // only one predecessor
        val = readLocalVar(predBB, decl);
    }
    else {
        // Creating empty phi to break potential cycles
        llvm::PHINode *phi = addEmptyPhi(BB, decl);
        val = phi;
        writeLocalVar(BB, decl, val);
        addPhiOperands(BB, decl, phi);
    }
    writeLocalVar(BB, decl, val);
    return val;
}

llvm::PHINode *cg::CGFunction::addEmptyPhi(llvm::BasicBlock *BB, ir::IR *decl) {
    if(BB->empty()) {
        return llvm::PHINode::Create(mapType(decl), 0, "", BB);
    }
    return llvm::PHINode::Create(mapType(decl), 0, "", &BB->front());
}

void cg::CGFunction::addPhiOperands(llvm::BasicBlock *BB, ir::IR *decl, llvm::PHINode *phi) {
    for(auto i = llvm::pred_begin(BB), e = llvm::pred_end(BB); i != e; ++i) {
        phi->addIncoming(readLocalVar(*i, decl), *i);
    }
    //optimizePhi(phi);
}

void cg::CGFunction::optimizePhi(llvm::PHINode *phi) {
    // FIXME: Causes crash
    llvm::Value *same = nullptr;
    for(llvm::Value *v : phi->incoming_values()) {
        if(v == same || v == phi) continue;
        if(same && v != same) return;
        same = v;
    }
    if(same == nullptr) {
        same = llvm::UndefValue::get(phi->getType());
    }
    llvm::SmallVector<llvm::PHINode *, 8> candidatePhis;
    for(llvm::Use &u: phi->uses()) {
        if(auto *p = llvm::dyn_cast<llvm::PHINode>(u.getUser())) {
            if(p != phi) {
                candidatePhis.push_back(p);
            }
        }
    }
    phi->replaceAllUsesWith(same);
    phi->eraseFromParent();
    for(auto *p: candidatePhis) {
        optimizePhi(p);
    }
}

void cg::CGFunction::sealBlock(llvm::BasicBlock *BB) {
    for(auto phi: currDef[BB].incompletePhis) {
        addPhiOperands(BB, phi.second, phi.first);
    }
    currDef[BB].incompletePhis.clear();
    currDef[BB].sealed = true;
}

llvm::Value *cg::CGFunction::readVar(llvm::BasicBlock *BB, ir::IR *decl) {
    if(auto *v = llvm::dyn_cast<ir::VarDecl>(decl)) {
        if(v->getEnclosingIR()->getKind() == ir::IRKind::IR_MODULE_DECL) {
            return builder.CreateLoad(mapType(v), currModule.getGlobals(decl));
        }
        else {
            return readLocalVar(BB, decl);
        }
        /*else {
            llvm::report_fatal_error("Nested functions are not supported");
        }*/
    } else if(auto *v = llvm::dyn_cast<ir::FormalParamDecl>(decl)) {
        if(v->isByReference()) {
            return builder.CreateLoad(mapType(v)->getNonOpaquePointerElementType(), formalParams[v]);
        }
        else {
            return readLocalVar(BB, decl);
        }
    }
    llvm::report_fatal_error("Unsupported variable declaration");
    return nullptr;
}

llvm::Value *cg::CGFunction::emitFunCall(ir::FunctionCall *e) {
    if(e->isUnresolved()) {
        llvm::report_fatal_error("Function call was not resolved by a resolver");
    }
    ir::FunctionDecl *f = e->getFun();
    std::vector<llvm::Value *> args{};
    int index = 0;
    for(auto a: e->getParams()) {
        auto emEx = emitExpr(a);
        if(f->getParams()[index]->isByReference()) {
            if(auto li = llvm::dyn_cast<llvm::LoadInst>(emEx)) {
                emEx = li->getOperand(0);
            }
            else {
                llvm::report_fatal_error("Argument in a function call cannot be passed in by a reference");
            }
        }
        args.push_back(emEx);
        ++index;
    }
    // TODO: Set last arg to true is argvars
    //llvm::FunctionType *fType = llvm::FunctionType::get(voidType, argTypes, false);
    // Try looking up non mangled function
    llvm::Function *funDecl = cgm.getLLVMMod()->getFunction(mangleName(f));
    if(!funDecl) {
        // Lib functions
        funDecl = cgm.getLLVMMod()->getFunction(f->getName());
    }
    if(!funDecl) {
        auto msg = "Somehow function "+f->getOGName()+" could not be found";
        llvm::report_fatal_error(msg.c_str());
    }
    return builder.CreateCall(funDecl, args);
}

llvm::Value *cg::CGFunction::emitExpr(ir::Expr *e) {
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
    case ir::ExprKind::EX_STRING: 
    {
        llvm::GlobalVariable *v = new llvm::GlobalVariable(*cgm.getLLVMMod(),
                                                            builder.getInt8Ty()->getPointerTo(),
                                                            false,
                                                            llvm::GlobalValue::PrivateLinkage,
                                                            nullptr);
        v->setInitializer(builder.CreateGlobalStringPtr(llvm::dyn_cast<ir::StringLiteral>(e)->getValue().c_str(), "", 0, cgm.getLLVMMod()));
        
        auto strobj = builder.CreateAlloca(stringT);

        auto stringInitF = cgm.getLLVMMod()->getOrInsertFunction("string_Create_Init", 
                                                    llvm::FunctionType::get(
                                                        voidT,
                                                        {
                                                            stringTPtr,
                                                            builder.getInt8Ty()->getPointerTo()
                                                        },
                                                        false
                                                    ));
        // Init string
        auto vloaded = builder.CreateLoad(builder.getInt8Ty()->getPointerTo(), v);
        builder.CreateCall(stringInitF, { strobj, vloaded });
        auto strval = builder.CreateLoad(stringT, strobj);
        
        return strval;

    }
    case ir::ExprKind::EX_BOOL: return llvm::ConstantInt::get(int1T, llvm::dyn_cast<ir::BoolLiteral>(e)->getValue());
    case ir::ExprKind::EX_FLOAT: return llvm::ConstantFP::get(floatT,llvm::dyn_cast<ir::FloatLiteral>(e)->getValue());
    case ir::ExprKind::EX_FUN_CALL: return emitFunCall(llvm::dyn_cast<ir::FunctionCall>(e));
    case ir::ExprKind::EX_MEMBER_ACCESS: return nullptr; // Member access is handeled by the left hand side
    // TODO: Other ones
    default:
        llvm::report_fatal_error(("Unimplemented expression kind in code generation "+e->debug()).c_str());
        return nullptr;
    }
}

void cg::CGFunction::emitMemberAssignment(ir::BinaryInfixExpr *l, llvm::Value *r) {
    auto left = l->getLeft();
    auto right = l->getRight();

    if(auto var = llvm::dyn_cast<ir::VarAccess>(left)) {
        if(auto elem = llvm::dyn_cast<ir::MemberAccess>(right)) {
            auto strucType = left->getType();
            if(!strucType->getDecl() || !llvm::isa<ir::StructDecl>(strucType->getDecl())) {
                llvm::report_fatal_error("Assignment variable is not a struct");
            }
            llvm::Value* zero = llvm::ConstantInt::get(llvm::Type::getInt32Ty(cgm.getLLVMCtx()), 0);
            llvm::Value* stIndex = llvm::ConstantInt::get(llvm::Type::getInt32Ty(cgm.getLLVMCtx()), elem->getIndex());
            
            llvm::Value *llvar = nullptr;
            if(auto v = llvm::dyn_cast<ir::VarDecl>(var->getVar())) {
                if(v->getEnclosingIR() == cgm.getModuleDecl()) {
                    llvar = cgm.getGlobals(var->getVar());
                }
                else if(v->getEnclosingIR() == fun) {
                    llvar = currDef[currBB].defs[var->getVar()];
                }
                else {
                    llvm::report_fatal_error("Unknown variable scope");
                }
            }
            else if(auto v = llvm::dyn_cast<ir::FormalParamDecl>(var->getVar())) {
                if(v->isByReference()) {
                    llvar = formalParams[v];
                }
                else {
                    llvar = builder.CreateAlloca(mapType(strucType));
                    builder.CreateStore(currDef[currBB].defs[var->getVar()], llvar);
                }
            }
            else {
                llvm::report_fatal_error("Unknown variable type for assignment");
            }
            llvm::Value *elemPtr = builder.CreateGEP(mapType(strucType), llvar, {zero, stIndex});
            builder.CreateStore(r, elemPtr);
        }
        else {
            llvm::report_fatal_error("Left hand side is not assignable");
        }
    }
    else {
        llvm::report_fatal_error("NOT YET IMPLEMENTED nested struct assignment");
    }
}

llvm::Value *cg::CGFunction::emitInfixExpr(ir::BinaryInfixExpr *e) {
    llvm::Value *left = emitExpr(e->getLeft());
    llvm::Value *right = emitExpr(e->getRight());
    llvm::Value *result = nullptr;
    switch(e->getOperator().getKind()) {
    case ir::OperatorKind::OP_ASSIGN:
    {
        LOGMAX("Creating assignment instruction");
        if(auto *var = llvm::dyn_cast<ir::VarAccess>(e->getLeft())) {
            if(auto *varDecl = llvm::dyn_cast<ir::VarDecl>(var->getVar())) {
                writeVar(currBB, varDecl, right);
            }
            else if(auto *fp = llvm::dyn_cast<ir::FormalParamDecl>(var->getVar())) {
                writeVar(currBB, fp, right);
            }
            else {
                llvm::report_fatal_error("Unknown left value in an assignment");
            }
        }
        else if(auto *var = llvm::dyn_cast<ir::BinaryInfixExpr>(e->getLeft())) {
            emitMemberAssignment(var, right);
        }
        else {
            llvm::report_fatal_error("Left hand side of an assignment is not assignable");
        }
    }
    break;
    case ir::OperatorKind::OP_ADD:
    {
        LOGMAX("Creating ADD instruction");
        if(left->getType() == right->getType() && left->getType() == int64T) {
            result = builder.CreateNSWAdd(left, right);
        }
        else if(left->getType() == right->getType() && left->getType() == floatT) {
            result = builder.CreateFAdd(left, right);
        }
        else if(left->getType() == floatT && right->getType() == int64T) {
            auto intv = builder.CreateSIToFP(right, floatT);
            result = builder.CreateFAdd(left, intv);
        }
        else if(left->getType() == int64T && right->getType() == floatT) {
            auto intv = builder.CreateSIToFP(left, floatT);
            result = builder.CreateFAdd(intv, right);
        }
        else {
            llvm::report_fatal_error("ADD does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_SUB:
    {
        LOGMAX("Creating SUB instruction");
        if(left->getType() == right->getType() && left->getType() == int64T) {
            result = builder.CreateNSWSub(left, right);
        }
        else if(left->getType() == right->getType() && left->getType() == floatT) {
            result = builder.CreateFSub(left, right);
        }
        else if(left->getType() == floatT && right->getType() == int64T) {
            auto intv = builder.CreateSIToFP(right, floatT);
            result = builder.CreateFSub(left, intv);
        }
        else if(left->getType() == int64T && right->getType() == floatT) {
            auto intv = builder.CreateSIToFP(left, floatT);
            result = builder.CreateFSub(intv, right);
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
        if(left->getType() == right->getType() && left->getType() == int64T) {
            result = builder.CreateNSWMul(left, right);
        }
        else if(left->getType() == right->getType() && left->getType() == floatT) {
            result = builder.CreateFMul(left, right);
        }
        else if(left->getType() == floatT && right->getType() == int64T) {
            auto intv = builder.CreateSIToFP(right, floatT);
            result = builder.CreateFMul(left, intv);
        }
        else if(left->getType() == int64T && right->getType() == floatT) {
            auto intv = builder.CreateSIToFP(left, floatT);
            result = builder.CreateFMul(intv, right);
        }
        else {
            llvm::report_fatal_error("MUL does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_DIV:
    {
        LOGMAX("Creating DIV instruction");
        if(left->getType() == right->getType() && left->getType() == int64T) {
            result = builder.CreateSDiv(left, right);
        }
        else if(left->getType() == right->getType() && left->getType() == floatT) {
            result = builder.CreateFDiv(left, right);
        }
        else if(left->getType() == floatT && right->getType() == int64T) {
            auto intv = builder.CreateSIToFP(right, floatT);
            result = builder.CreateFDiv(left, intv);
        }
        else if(left->getType() == int64T && right->getType() == floatT) {
            auto intv = builder.CreateSIToFP(left, floatT);
            result = builder.CreateFDiv(intv, right);
        }
        else {
            llvm::report_fatal_error("DIV does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_MOD:
    {
        LOGMAX("Creating MOD instruction");
        if(left->getType() == right->getType() && left->getType() == int64T) {
            result = builder.CreateSRem(left, right);
        }
        else if(left->getType() == right->getType() && left->getType() == floatT) {
            result = builder.CreateFRem(left, right);
        }
        else if(left->getType() == floatT && right->getType() == int64T) {
            auto intv = builder.CreateSIToFP(right, floatT);
            result = builder.CreateFRem(left, intv);
        }
        else if(left->getType() == int64T && right->getType() == floatT) {
            auto intv = builder.CreateSIToFP(left, floatT);
            result = builder.CreateFRem(intv, right);
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
        LOGMAX("Creating BAND instruction");
        if(left->getType() == int64T && left->getType() == right->getType()) {
            result = builder.CreateAnd(left, right);
        }
        else {
            llvm::report_fatal_error("BAND does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_BXOR:
    {
        LOGMAX("Creating BXOR instruction");
        if(left->getType() == int64T && left->getType() == right->getType()) {
            result = builder.CreateXor(left, right);
        }
        else {
            llvm::report_fatal_error("BXOR does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_BOR:
    {
        LOGMAX("Creating OR instruction");
        if(left->getType() == int64T && left->getType() == right->getType()) {
            result = builder.CreateOr(left, right);
        }
        else {
            llvm::report_fatal_error("BOR does not supported given type");
        }
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
        LOGMAX("Creating CONCAT instruction");
        llvm::Value *lval = left;
        llvm::Value *rval = right;
        auto to_str_int = cgm.getLLVMMod()->getOrInsertFunction("to_string_int",
                                 llvm::FunctionType::get(
                                    stringT,
                                    int64T,
                                    false
                                 ));
        auto to_str_float = cgm.getLLVMMod()->getOrInsertFunction("to_string_float",
                                 llvm::FunctionType::get(
                                    stringT,
                                    floatT,
                                    false
                                 ));
        auto to_str_bool = cgm.getLLVMMod()->getOrInsertFunction("to_string_bool",
                                 llvm::FunctionType::get(
                                    stringT,
                                    int1T,
                                    false
                                 ));
        auto str_concat = cgm.getLLVMMod()->getOrInsertFunction("string_Add_Str",
                                 llvm::FunctionType::get(
                                    voidT,
                                    {
                                        stringT->getPointerTo(),
                                        stringT,
                                        stringT
                                    },
                                    false
                                 ));
        if(left->getType() == int64T) {
            lval = builder.CreateCall(to_str_int, { left });
        }
        else if(left->getType() == floatT) {
            lval = builder.CreateCall(to_str_float, { left });
        }
        else if(left->getType() == int1T) {
            lval = builder.CreateCall(to_str_bool, { left });
        }

        if(right->getType() == int64T) {
            rval = builder.CreateCall(to_str_int, { right });
        }
        else if(right->getType() == floatT) {
            rval = builder.CreateCall(to_str_float, { right });
        }
        else if(right->getType() == int1T) {
            rval = builder.CreateCall(to_str_bool, { right });
        }

        auto res = builder.CreateAlloca(stringT);
        builder.CreateCall(str_concat, {res, lval, rval});
        result = builder.CreateLoad(stringT, res);
    }
    break;
    case ir::OperatorKind::OP_ACCESS:
        // FIXME: this creates unnecessary extract for assignment where
        // access is no the left side a.c = 4. 
        // Although it can will be removed as an unused var
        if(auto rMemAcc = llvm::dyn_cast<ir::MemberAccess>(e->getRight())) {
            result = builder.CreateExtractValue(left, rMemAcc->getIndex());
        }
        else {
            llvm::report_fatal_error("Member access is of a different type");
        }
    break;
    // TODO: implement rest
    default: llvm::report_fatal_error("Uknown operator in code generation");
    }
    return result;
}

void cg::CGFunction::emitStmt(ir::ExprStmt *stmt) {
    ir::Expr *e = stmt->getExpr();
    emitExpr(e);
}

void cg::CGFunction::emitStmt(ir::IfStatement *stmt) {
    bool hasElse = stmt->getElseBranch().size() > 0;

    llvm::BasicBlock *ifBB = llvm::BasicBlock::Create(ctx, "if.body", llvmFun);
    llvm::BasicBlock *elseBB = hasElse ? llvm::BasicBlock::Create(ctx, "if.else", llvmFun) : nullptr;
    llvm::BasicBlock *afterBB = llvm::BasicBlock::Create(ctx, "if.after", llvmFun);

    llvm::Value *cnd = emitExpr(stmt->getCond());
    builder.CreateCondBr(cnd, ifBB, hasElse ? elseBB : afterBB);

    sealBlock(currBB);

    setCurrBB(ifBB);
    emit(stmt->getIfBranch());
    if(!currBB->getTerminator()) {
        builder.CreateBr(afterBB);
    }
    sealBlock(currBB);

    if(hasElse) {
        setCurrBB(elseBB);
        emit(stmt->getElseBranch());
        if(!currBB->getTerminator()) {
            builder.CreateBr(afterBB);
        }
        sealBlock(currBB);
    }

    setCurrBB(afterBB);
}

void cg::CGFunction::emitStmt(ir::WhileStmt *stmt) {
    llvm::BasicBlock *whileCondBB = llvm::BasicBlock::Create(ctx, "while.cond", llvmFun);
    llvm::BasicBlock *whileBodyBB = llvm::BasicBlock::Create(ctx, "while.body", llvmFun);
    llvm::BasicBlock *whileAfterBB = llvm::BasicBlock::Create(ctx, "while.after", llvmFun);

    stmt->setAfterBB(whileAfterBB);
    stmt->setCondBB(whileCondBB);

    if(stmt->isDoWhile()) {
        builder.CreateBr(whileBodyBB);
    }
    else {
        builder.CreateBr(whileCondBB);
    }
    sealBlock(currBB);
    setCurrBB(whileCondBB);
    llvm::Value *cond = emitExpr(stmt->getCond());
    builder.CreateCondBr(cond, whileBodyBB, whileAfterBB);

    setCurrBB(whileBodyBB);
    auto stacksave = cgm.getLLVMMod()->getOrInsertFunction("llvm.stacksave", 
                                                    llvm::FunctionType::get(
                                                        builder.getInt8Ty()->getPointerTo(),
                                                        false
                                                    ));
    auto stackrestore = cgm.getLLVMMod()->getOrInsertFunction("llvm.stackrestore", 
                                                    llvm::FunctionType::get(
                                                        voidT,
                                                        builder.getInt8Ty()->getPointerTo(),
                                                        false
                                                    ));
    auto stp = builder.CreateCall(stacksave);
    emit(stmt->getBody());
    builder.CreateCall(stackrestore, { stp });
    builder.CreateBr(whileCondBB);
    sealBlock(currBB);
    sealBlock(whileCondBB);

    setCurrBB(whileAfterBB);
}

void cg::CGFunction::emitStmt(ir::ReturnStmt *stmt) {
    if(fun->getName() == "_entry") {
        llvm::report_fatal_error("return can appear only inside of a function");
    }
    if(stmt->getValue()) {
        LOGMAX("Creating return with value");
        llvm::Value *retVal = emitExpr(stmt->getValue());
        builder.CreateRet(retVal);
    }
    else {
        LOGMAX("Creating return void");
        builder.CreateRetVoid();
    }
}

void cg::CGFunction::emitStmt(ir::BreakStmt *stmt) {
    LOGMAX("Creating break");
    ir::IR *cycle = stmt->getEnclosingIR();
    // TODO: Add for when implemented
    while(cycle && !llvm::isa<ir::WhileStmt>(cycle)) {
        cycle = cycle->getEnclosingIR();
    }
    if(!cycle) {
        llvm::report_fatal_error("break can appear only inside of a while or a for loop");
    }
    if(auto loop = llvm::dyn_cast<ir::WhileStmt>(cycle)) {
        builder.CreateBr(loop->getAfterBB());
    }
    /*else if(auto loop = llvm::dyn_cast<ir::ForStmt>(cycle)) {
        builder.CreateBr(loop->getAfterBB());
    }*/
}

void cg::CGFunction::emitStmt(ir::ContinueStmt *stmt) {
    LOGMAX("Creating continue");
    ir::IR *cycle = stmt->getEnclosingIR();
    // TODO: Add for when implemented
    while(cycle && !llvm::isa<ir::WhileStmt>(cycle)) {
        cycle = cycle->getEnclosingIR();
    }
    if(!cycle) {
        llvm::report_fatal_error("continue can appear only inside of a while or a for loop");
    }
    if(auto loop = llvm::dyn_cast<ir::WhileStmt>(cycle)) {
        builder.CreateBr(loop->getCondBB());
    }
    /*else if(auto loop = llvm::dyn_cast<ir::ForStmt>(cycle)) {
        builder.CreateBr(loop->getAfterBB());
    }*/
}

void cg::CGFunction::emitStmt(ir::Import *stmt) {
    //llvm::report_fatal_error("Imports are not yet implemented");
}

void cg::CGFunction::emitStmt(ir::VarDecl *stmt) {
    LOGMAX("Local variable declaration");
    auto value = stmt->getInitValue();
    llvm::Value *v = nullptr;
    if(value) {
        v = emitExpr(value);
    }
    else {
        auto ty = stmt->getType()->getName();
        if(ty == INT_CSTR) {
            v = llvm::ConstantInt::get(int64T, 0, true);
        }
        else if(ty == BOOL_CSTR) {
            v = llvm::ConstantInt::getFalse(int1T);
        }
        else if(ty == FLOAT_CSTR) {
            v = llvm::ConstantFP::get(floatT, 0.0);
        }
        else if(ty == STRING_CSTR) {
            std::string s = "";
            ir::StringLiteral *empt = new ir::StringLiteral(stmt->getLocation(), s, stmt->getType());
            v = emitExpr(empt);
        }
        else {
            llvm::report_fatal_error("Local struct intializer not yet implemented");
        }
    }
    writeVar(currBB, stmt, v);
}

void cg::CGFunction::emit(std::vector<ir::IR *> stmts) {
    for(auto *s : stmts) {
        if(auto *stmt = llvm::dyn_cast<ir::ExprStmt>(s)) {
            emitStmt(stmt);
        }
        else if(auto *stmt = llvm::dyn_cast<ir::ReturnStmt>(s)) {
            emitStmt(stmt);
        }
        else if(auto *stmt = llvm::dyn_cast<ir::IfStatement>(s)) {
            emitStmt(stmt);
        }
        else if(auto *stmt = llvm::dyn_cast<ir::WhileStmt>(s)) {
            emitStmt(stmt);
        }
        else if(auto *stmt = llvm::dyn_cast<ir::Import>(s)) {
            emitStmt(stmt);
        }
        else if(auto *stmt = llvm::dyn_cast<ir::BreakStmt>(s)) {
            emitStmt(stmt);
        }
        else if(auto *stmt = llvm::dyn_cast<ir::ContinueStmt>(s)) {
            emitStmt(stmt);
        }
        else if(auto *stmt = llvm::dyn_cast<ir::VarDecl>(s)) {
            emitStmt(stmt);
        }
        else {
            llvm::report_fatal_error("Unknown statement in code generation");
        }
    }
}

void cg::CGModule::defineStruct(ir::StructDecl *decl) {
    std::vector<llvm::Type*> structElements;
    for(auto elem: decl->getElements()) {
        structElements.push_back(mapType(elem));
    }
    std::string name = mangleName(decl);
    auto tp = llvm::StructType::create(getLLVMCtx(), structElements, name);

    llvm::Constant *init;

    if(decl->is_zero_init()) {
        init = llvm::ConstantAggregateZero::get(tp);
    }
    else {
        llvm::SmallVector<llvm::Constant *> vals; //{ llvm::ConstantInt::get(builder.getInt32Ty(), 0, true) };
        for(auto e : decl->getElements()) {
            auto evar = llvm::dyn_cast<ir::VarDecl>(e);
            if(auto ival = evar->getInitValue()) {
                if(auto vcast = llvm::dyn_cast<ir::IntLiteral>(ival)) {
                    vals.push_back(llvm::ConstantInt::get(ctx, vcast->getValue()));
                }
                else if(auto vcast = llvm::dyn_cast<ir::BoolLiteral>(ival)) {
                    vals.push_back(llvm::ConstantInt::getBool(int1T, vcast->getValue()));
                }
                else if(auto vcast = llvm::dyn_cast<ir::FloatLiteral>(ival)) {
                    vals.push_back(llvm::ConstantFP::get(ctx, vcast->getValue()));
                }
                else if(llvm::dyn_cast<ir::StringLiteral>(ival)) {
                    // Initialization is handeled when new instance is created
                    auto init = llvm::ConstantAggregateZero::get(stringT);
                    vals.push_back(init);
                }
                else {
                    // TODO: Handle structs
                    llvm::report_fatal_error("Struct element initializer is not a constant");
                }
            }
            else {
                auto ty = evar->getType()->getName();
                if(ty == INT_CSTR) {
                    vals.push_back(llvm::ConstantInt::get(int64T, 0, true));
                }
                else if(ty == BOOL_CSTR) {
                    vals.push_back(llvm::ConstantInt::getFalse(int1T));
                }
                else if(ty == FLOAT_CSTR) {
                    vals.push_back(llvm::ConstantFP::get(floatT, 0.0));
                }
                else if(ty == STRING_CSTR) {
                    // Initialization is handeled when new instance is created
                    auto init = llvm::ConstantAggregateZero::get(stringT);
                    vals.push_back(init);
                }
                else {
                    llvm::report_fatal_error("Struct nested intializer is not yet implemented");
                }
            }
        }
        init = llvm::ConstantStruct::get(tp, vals);
    }

    userTypes[name] = std::make_pair(tp, init);
}

void cg::CGModule::run(ir::ModuleDecl *mod) {
    this->mod = mod;

    ptlibLoader->setupExternLib();
    ptlibLoader->setupLib();
    ir::FunctionDecl *entryFun = nullptr;
    std::vector<CGFunction *> funs;

    str_empty = new llvm::GlobalVariable(*llvmMod,
                                        builder.getInt8Ty()->getPointerTo(),
                                        false,
                                        llvm::GlobalValue::PrivateLinkage,
                                        nullptr);
    str_empty->setInitializer(builder.CreateGlobalStringPtr("", "", 0, llvmMod));

    for(auto *decl: mod->getDecls()) {
        auto kind = decl->getKind();
        switch(kind) {
        case ir::IRKind::IR_VAR_DECL:
        {   // new variable needs its own scope
            auto var = llvm::dyn_cast<ir::VarDecl>(decl);
            llvm::GlobalVariable *v = new llvm::GlobalVariable(*llvmMod,
                                                            mapType(var),
                                                            false,
                                                            llvm::GlobalValue::PrivateLinkage,
                                                            nullptr,
                                                            mangleName(var));
            auto value = var->getInitValue();
            if(value) {
                if(auto vcast = llvm::dyn_cast<ir::IntLiteral>(value)) {
                    v->setInitializer(llvm::ConstantInt::get(ctx, vcast->getValue()));
                }
                else if(auto vcast = llvm::dyn_cast<ir::BoolLiteral>(value)) {
                    v->setInitializer(llvm::ConstantInt::getBool(int1T, vcast->getValue()));
                }
                else if(auto vcast = llvm::dyn_cast<ir::FloatLiteral>(value)) {
                    v->setInitializer(llvm::ConstantFP::get(ctx, vcast->getValue()));
                }
                else if(auto vcast = llvm::dyn_cast<ir::StringLiteral>(value)) {
                    llvm::GlobalVariable *str_txt = new llvm::GlobalVariable(*llvmMod,
                                                            builder.getInt8Ty()->getPointerTo(),
                                                            false,
                                                            llvm::GlobalValue::PrivateLinkage,
                                                            nullptr);
                    str_txt->setInitializer(builder.CreateGlobalStringPtr(vcast->getValue().c_str(), "", 0, llvmMod));
                    stringsToInit.push_back(std::make_pair(v, str_txt));
                    auto init = llvm::ConstantAggregateZero::get(stringT);
                    v->setInitializer(init);
                }
                else if(var->getType()->isMatrix()) {
                    llvm::report_fatal_error("Matrix initialization is not yet implemented");
                }
                else {
                    llvm::report_fatal_error("Global variable initializer is not a constant");
                }
            }
            else { //if(utils::isOneOf(var->getType()->getName(), {FLOAT_CSTR, INT_CSTR, BOOL_CSTR, STRING_CSTR})) {
                auto ty = var->getType()->getName();
                if(ty == INT_CSTR) {
                    v->setInitializer(llvm::ConstantInt::get(int64T, 0, true));
                }
                else if(ty == BOOL_CSTR) {
                    v->setInitializer(llvm::ConstantInt::getFalse(int1T));
                }
                else if(ty == FLOAT_CSTR) {
                    v->setInitializer(llvm::ConstantFP::get(floatT, 0.0));
                }
                else if(ty == STRING_CSTR) {
                    auto init = llvm::ConstantAggregateZero::get(stringT);
                    v->setInitializer(init);
                    stringsToInit.push_back(std::make_pair(v, str_empty));
                }
                else if(var->getType()->isMatrix()) {
                    auto init = llvm::ConstantAggregateZero::get(matrixT);
                    v->setInitializer(init);
                    matricesToInit.push_back(std::make_pair(v, nullptr));
                }
                else {
                    // struct
                    v->setInitializer(userTypes[mangleName(var->getType()->getDecl())].second);
                    // TODO: Handle nested structs
                    // Initialize all strings
                    if(auto struDecl = llvm::dyn_cast<ir::StructDecl>(var->getType()->getDecl())) {
                        int index = 0;
                        for(auto e: struDecl->getElements()) {
                            if(auto eVar = llvm::dyn_cast<ir::VarDecl>(e)) {
                                if(eVar->getType()->getName() == STRING_CSTR) {
                                    if(auto val = eVar->getInitValue()) {
                                        llvm::Value* zero = llvm::ConstantInt::get(llvm::Type::getInt32Ty(getLLVMCtx()), 0);
                                        llvm::Value* stIndex = llvm::ConstantInt::get(llvm::Type::getInt32Ty(getLLVMCtx()), index);
                                        llvm::Value *elemPtr = builder.CreateGEP(mapType(var->getType()), v, {zero, stIndex});

                                        auto vcast = llvm::dyn_cast<ir::StringLiteral>(val);
                                        llvm::GlobalVariable *str_txt = new llvm::GlobalVariable(*llvmMod,
                                                                                                builder.getInt8Ty()->getPointerTo(),
                                                                                                false,
                                                                                                llvm::GlobalValue::PrivateLinkage,
                                                                                                nullptr);
                                        str_txt->setInitializer(builder.CreateGlobalStringPtr(vcast->getValue().c_str(), "", 0, llvmMod));

                                        stringsToInit.push_back(std::make_pair(elemPtr, str_txt));
                                    }
                                    else {
                                        // Default
                                        llvm::Value* zero = llvm::ConstantInt::get(llvm::Type::getInt32Ty(getLLVMCtx()), 0);
                                        llvm::Value* stIndex = llvm::ConstantInt::get(llvm::Type::getInt32Ty(getLLVMCtx()), index);
                                        llvm::Value *elemPtr = builder.CreateGEP(mapType(var->getType()), v, {zero, stIndex});
                                        stringsToInit.push_back(std::make_pair(elemPtr, str_empty));
                                    }
                                }
                            }
                            // TODO: make this function and recursively go deeper if e is StructDecl
                            ++index;
                        }
                    }
                    else {
                        llvm::report_fatal_error("Global variable is of unknown type");
                    }
                }
            }
            globals[var] = v;
        }
        break;
        case ir::IRKind::IR_FUNCTION_DECL:
        {
            auto *fun = llvm::dyn_cast<ir::FunctionDecl>(decl);
            // This also creates forward declaration
            CGFunction *cgf = new CGFunction(*this, fun);
            if(fun->getName() == "_entry") {
                entryFun = fun;
            }
            funs.push_back(cgf);
        }
        break;
        case ir::IRKind::IR_STRUCT_DECL:
            defineStruct(llvm::dyn_cast<ir::StructDecl>(decl));
        break;
        default: llvm::report_fatal_error("Code generation invoked for not yet implemented IR");
        break;
        }
    }

    // Generate templated libFunctions
    for(auto f: mod->getLibFunctions()) {
        if(f->getOGName() == "append") {
            ptlibLoader->appendInit(f->getName(), mapType(f->getParams()[0]), mapType(f->getParams()[1]));
        }
        else {
            llvm::report_fatal_error(("Missing code for function "+f->getOGName()).c_str()); 
        }
    }

    // Create function bodies
    for(auto f: funs) {
        f->run();
    }

    // Insert _main
    auto bytePtrPtrTy = builder.getInt8Ty()->getPointerTo()->getPointerTo();
    llvm::Function *main = llvm::Function::Create(llvm::FunctionType::get(
                                                builder.getInt32Ty(),
                                                {builder.getInt32Ty(), bytePtrPtrTy},
                                                false
                                               ), 
                                               llvm::GlobalValue::ExternalLinkage,
                                               "main",
                                               llvmMod);
    main->setDSOLocal(true);
    llvm::BasicBlock *bb = llvm::BasicBlock::Create(getLLVMCtx(), "", main);
    setCurrBB(bb);

    auto stringInitF = llvmMod->getOrInsertFunction("string_Create_Init", 
                                                    llvm::FunctionType::get(
                                                        voidT,
                                                        {
                                                            stringTPtr,
                                                            builder.getInt8Ty()->getPointerTo()->getPointerTo()
                                                        },
                                                        false
                                                    ));
    // Init strings
    for(auto s: stringsToInit) {
        auto secloaded = builder.CreateLoad(builder.getInt8Ty()->getPointerTo(), s.second);
        builder.CreateCall(stringInitF, { s.first, secloaded});
    }

    auto matrixCreateF = llvmMod->getOrInsertFunction("matrix_Create_Default", 
                                                      llvm::FunctionType::get(
                                                        voidT,
                                                        matrixTPtr,
                                                        false
                                                      ));
    // Init matrices
    for(auto m: matricesToInit) {
        builder.CreateCall(matrixCreateF, { m.first });
    }

    auto entryFunLLVM = llvmMod->getFunction(mangleName(entryFun));
    std::vector<llvm::Value *> args{};
    builder.CreateCall(entryFunLLVM, args);

    builder.CreateRet(llvm::ConstantInt::get(builder.getInt32Ty(), 0));
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

void cg::CGFunction::run() {
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

    /* llvm::Type *retTy = llvm::Type::getInt32Ty(ctx);
    llvm::FunctionType* FuncTy = llvm::FunctionType::get(retTy, false);
    llvm::Type *charTy = llvm::Type::getInt8Ty(ctx);
    llvm::Type *charPtrTy = charTy->getPointerTo();
    //llvm::Argument arg(charTy, "s");
    llvm::Attribute arg = llvm::Attribute::get(ctx, llvm::Attribute::AttrKind::ByVal, charTy);
    llvm::AttributeList atl;
    atl.addAttributeAtIndex(ctx, 0, arg);
    llvm::FunctionCallee putcFun = cgm.getLLVMMod()->getOrInsertFunction("puts", llvm::Type::getInt32Ty(ctx));
    llvm::Value *v = llvm::ConstantDataArray::getString(ctx, llvm::StringRef("Hello!"));
    llvm::ArrayRef<llvm::Value *> args{v};
    llvm::Instruction* putcCall = llvm::CallInst::Create(putcFun, args);
    builder.Insert(putcCall);*/

    auto block = fun->getDecl();
    emit(fun->getDecl());
    if(!currBB->getTerminator()) {
        builder.CreateRetVoid();
    }
    sealBlock(currBB);
}

//void cg::CGFunction::run() { }