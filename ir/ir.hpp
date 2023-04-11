#ifndef _IR_HPP_
#define _IR_HPP_

#include "llvm/Support/SMLoc.h"
#include "llvm/ADT/StringRef.h"

namespace ptc {

namespace ir {

enum IRKind {
    VAR_DECL
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

    IRKind get_kind() const { return kind; }
    llvm::SMLoc get_location() { return loc; }
    llvm::StringRef get_name() { return name; }
    IR *get_enclosing_ir() { return enclosing_ir; }
};

class TypeDecl : public IR {

};

class VarDecl : public IR {



};


}

}

#endif//_IR_HPP_