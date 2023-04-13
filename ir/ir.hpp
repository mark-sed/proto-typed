#ifndef _IR_HPP_
#define _IR_HPP_

#include "llvm/Support/SMLoc.h"
#include "llvm/ADT/StringRef.h"

namespace ptc {

namespace ir {

enum IRKind {
    IR_VAR_DECL,
    IR_TYPE_DECL
};


class IR {
private:
    const IRKind kind;
protected:
    IR *enclosing_ir;
    llvm::SMLoc loc;
    llvm::StringRef name;
public:
    IR(IRKind kind, IR *enclosing_ir, llvm::SMLoc loc, llvm::StringRef name) : kind(kind),
                                                                               enclosing_ir(enclosing_ir),
                                                                               loc(loc),
                                                                               name(name) {
    }

    IRKind getKind() const { return kind; }
    llvm::SMLoc getLocation() { return loc; }
    llvm::StringRef getName() { return name; }
    IR *getEnclosingIR() { return enclosing_ir; }
};


class TypeDecl : public IR {
public:
    TypeDecl(IR *enclosing_ir, llvm::SMLoc loc, llvm::StringRef name)
            : IR(IRKind::IR_TYPE_DECL, enclosing_ir, loc, name) {}

    static bool classof(const IR *ir) {
        return ir->getKind() == IRKind::IR_TYPE_DECL;
    }
};


class VarDecl : public IR {
private:
    TypeDecl *td;
public:
    VarDecl(IR *enclosing_ir, llvm::SMLoc loc, llvm::StringRef name, TypeDecl *td)
           : IR(IRKind::IR_VAR_DECL, enclosing_ir, loc, name),
             td(td) {}
    
    TypeDecl *getType() { return td; }
    static bool classof(const IR *ir) {
        return ir->getKind() == IRKind::IR_VAR_DECL;
    }
};


}

}

#endif//_IR_HPP_