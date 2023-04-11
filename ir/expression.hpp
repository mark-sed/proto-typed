#ifndef _EXPRESSION_HPP_
#define _EXPRESSION_HPP_

#include "ir.hpp"

namespace ptc {

namespace ir {

enum ExprKind {

};

class Expr {
private:
    const ExprKind kind;
    TypeDecl *type;
    bool is_const;
};

}

}

#endif//_EXPRESSION_HPP_