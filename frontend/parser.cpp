// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hpp"


// Unqualified %code blocks.
#line 46 "frontend/parser.yy"


    #include <cmath>
    #include <sstream>
    #include <vector>
    #include "scanner.hpp"
    #include "logging.hpp"
    #include "ir.hpp"
    #include "diagnostics.def"

    // Set correct token method
    #undef yylex
    #define yylex scanner->yylex

#line 61 "frontend/parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 14 "frontend/parser.yy"
namespace  ptc  {
#line 154 "frontend/parser.cpp"

  /// Build a parser object.
   Parser :: Parser  (Scanner *scanner_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg)
  {}

   Parser ::~ Parser  ()
  {}

   Parser ::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_BOOL: // "bool"
      case symbol_kind::S_expr_bool: // expr_bool
        value.copy< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // "float"
      case symbol_kind::S_expr_float: // expr_float
        value.copy< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // "int"
      case symbol_kind::S_expr_int: // expr_int
        value.copy< long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_set: // set
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_var: // expr_var
      case symbol_kind::S_matrix: // matrix
      case symbol_kind::S_expr_mat: // expr_mat
      case symbol_kind::S_range: // range
      case symbol_kind::S_int_val: // int_val
      case symbol_kind::S_expr_none: // expr_none
        value.copy< ptc::ir::Expr * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmts_ne: // stmts_ne
      case symbol_kind::S_import: // import
      case symbol_kind::S_flowctl: // flowctl
      case symbol_kind::S_return: // return
      case symbol_kind::S_for: // for
      case symbol_kind::S_while: // while
      case symbol_kind::S_dowhile: // dowhile
      case symbol_kind::S_if: // if
      case symbol_kind::S_struct: // struct
      case symbol_kind::S_declistval: // declistval
      case symbol_kind::S_function: // function
      case symbol_kind::S_vardecl: // vardecl
      case symbol_kind::S_vardef: // vardef
      case symbol_kind::S_mattype: // mattype
      case symbol_kind::S_type: // type
        value.copy< ptc::ir::IR * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_EXT_ID: // "external identifier"
      case symbol_kind::S_fun_id: // fun_id
      case symbol_kind::S_expr_str: // expr_str
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_callarglist: // callarglist
      case symbol_kind::S_matvals: // matvals
      case symbol_kind::S_matsq: // matsq
        value.copy< std::vector<ptc::ir::Expr *>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_funargsnvar: // funargsnvar
      case symbol_kind::S_funargs: // funargs
        value.copy< std::vector<ptc::ir::FormalParamDecl *>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_block: // block
      case symbol_kind::S_body: // body
      case symbol_kind::S_scope_body: // scope_body
      case symbol_kind::S_else: // else
      case symbol_kind::S_decllist: // decllist
        value.copy< std::vector<ptc::ir::IR *>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_id_list: // id_list
        value.copy< std::vector<std::string>  > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
   Parser ::symbol_kind_type
   Parser ::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
   Parser ::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
   Parser ::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_BOOL: // "bool"
      case symbol_kind::S_expr_bool: // expr_bool
        value.move< bool > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_FLOAT: // "float"
      case symbol_kind::S_expr_float: // expr_float
        value.move< double > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INT: // "int"
      case symbol_kind::S_expr_int: // expr_int
        value.move< long > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_set: // set
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_var: // expr_var
      case symbol_kind::S_matrix: // matrix
      case symbol_kind::S_expr_mat: // expr_mat
      case symbol_kind::S_range: // range
      case symbol_kind::S_int_val: // int_val
      case symbol_kind::S_expr_none: // expr_none
        value.move< ptc::ir::Expr * > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmts_ne: // stmts_ne
      case symbol_kind::S_import: // import
      case symbol_kind::S_flowctl: // flowctl
      case symbol_kind::S_return: // return
      case symbol_kind::S_for: // for
      case symbol_kind::S_while: // while
      case symbol_kind::S_dowhile: // dowhile
      case symbol_kind::S_if: // if
      case symbol_kind::S_struct: // struct
      case symbol_kind::S_declistval: // declistval
      case symbol_kind::S_function: // function
      case symbol_kind::S_vardecl: // vardecl
      case symbol_kind::S_vardef: // vardef
      case symbol_kind::S_mattype: // mattype
      case symbol_kind::S_type: // type
        value.move< ptc::ir::IR * > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_EXT_ID: // "external identifier"
      case symbol_kind::S_fun_id: // fun_id
      case symbol_kind::S_expr_str: // expr_str
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_callarglist: // callarglist
      case symbol_kind::S_matvals: // matvals
      case symbol_kind::S_matsq: // matsq
        value.move< std::vector<ptc::ir::Expr *>  > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_funargsnvar: // funargsnvar
      case symbol_kind::S_funargs: // funargs
        value.move< std::vector<ptc::ir::FormalParamDecl *>  > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_block: // block
      case symbol_kind::S_body: // body
      case symbol_kind::S_scope_body: // scope_body
      case symbol_kind::S_else: // else
      case symbol_kind::S_decllist: // decllist
        value.move< std::vector<ptc::ir::IR *>  > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_id_list: // id_list
        value.move< std::vector<std::string>  > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
   Parser ::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
   Parser ::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

   Parser ::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

   Parser ::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
   Parser ::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
   Parser ::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

   Parser ::symbol_kind_type
   Parser ::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


   Parser ::symbol_kind_type
   Parser ::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
   Parser ::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

   Parser ::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
   Parser ::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
   Parser ::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

   Parser ::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

   Parser ::symbol_kind_type
   Parser ::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

   Parser ::stack_symbol_type::stack_symbol_type ()
  {}

   Parser ::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_BOOL: // "bool"
      case symbol_kind::S_expr_bool: // expr_bool
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // "float"
      case symbol_kind::S_expr_float: // expr_float
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // "int"
      case symbol_kind::S_expr_int: // expr_int
        value.YY_MOVE_OR_COPY< long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_set: // set
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_var: // expr_var
      case symbol_kind::S_matrix: // matrix
      case symbol_kind::S_expr_mat: // expr_mat
      case symbol_kind::S_range: // range
      case symbol_kind::S_int_val: // int_val
      case symbol_kind::S_expr_none: // expr_none
        value.YY_MOVE_OR_COPY< ptc::ir::Expr * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmts_ne: // stmts_ne
      case symbol_kind::S_import: // import
      case symbol_kind::S_flowctl: // flowctl
      case symbol_kind::S_return: // return
      case symbol_kind::S_for: // for
      case symbol_kind::S_while: // while
      case symbol_kind::S_dowhile: // dowhile
      case symbol_kind::S_if: // if
      case symbol_kind::S_struct: // struct
      case symbol_kind::S_declistval: // declistval
      case symbol_kind::S_function: // function
      case symbol_kind::S_vardecl: // vardecl
      case symbol_kind::S_vardef: // vardef
      case symbol_kind::S_mattype: // mattype
      case symbol_kind::S_type: // type
        value.YY_MOVE_OR_COPY< ptc::ir::IR * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_EXT_ID: // "external identifier"
      case symbol_kind::S_fun_id: // fun_id
      case symbol_kind::S_expr_str: // expr_str
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_callarglist: // callarglist
      case symbol_kind::S_matvals: // matvals
      case symbol_kind::S_matsq: // matsq
        value.YY_MOVE_OR_COPY< std::vector<ptc::ir::Expr *>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_funargsnvar: // funargsnvar
      case symbol_kind::S_funargs: // funargs
        value.YY_MOVE_OR_COPY< std::vector<ptc::ir::FormalParamDecl *>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_block: // block
      case symbol_kind::S_body: // body
      case symbol_kind::S_scope_body: // scope_body
      case symbol_kind::S_else: // else
      case symbol_kind::S_decllist: // decllist
        value.YY_MOVE_OR_COPY< std::vector<ptc::ir::IR *>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_id_list: // id_list
        value.YY_MOVE_OR_COPY< std::vector<std::string>  > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

   Parser ::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_BOOL: // "bool"
      case symbol_kind::S_expr_bool: // expr_bool
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // "float"
      case symbol_kind::S_expr_float: // expr_float
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // "int"
      case symbol_kind::S_expr_int: // expr_int
        value.move< long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_set: // set
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_var: // expr_var
      case symbol_kind::S_matrix: // matrix
      case symbol_kind::S_expr_mat: // expr_mat
      case symbol_kind::S_range: // range
      case symbol_kind::S_int_val: // int_val
      case symbol_kind::S_expr_none: // expr_none
        value.move< ptc::ir::Expr * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmts_ne: // stmts_ne
      case symbol_kind::S_import: // import
      case symbol_kind::S_flowctl: // flowctl
      case symbol_kind::S_return: // return
      case symbol_kind::S_for: // for
      case symbol_kind::S_while: // while
      case symbol_kind::S_dowhile: // dowhile
      case symbol_kind::S_if: // if
      case symbol_kind::S_struct: // struct
      case symbol_kind::S_declistval: // declistval
      case symbol_kind::S_function: // function
      case symbol_kind::S_vardecl: // vardecl
      case symbol_kind::S_vardef: // vardef
      case symbol_kind::S_mattype: // mattype
      case symbol_kind::S_type: // type
        value.move< ptc::ir::IR * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_EXT_ID: // "external identifier"
      case symbol_kind::S_fun_id: // fun_id
      case symbol_kind::S_expr_str: // expr_str
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_callarglist: // callarglist
      case symbol_kind::S_matvals: // matvals
      case symbol_kind::S_matsq: // matsq
        value.move< std::vector<ptc::ir::Expr *>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_funargsnvar: // funargsnvar
      case symbol_kind::S_funargs: // funargs
        value.move< std::vector<ptc::ir::FormalParamDecl *>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_block: // block
      case symbol_kind::S_body: // body
      case symbol_kind::S_scope_body: // scope_body
      case symbol_kind::S_else: // else
      case symbol_kind::S_decllist: // decllist
        value.move< std::vector<ptc::ir::IR *>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_id_list: // id_list
        value.move< std::vector<std::string>  > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_BOOL: // "bool"
      case symbol_kind::S_expr_bool: // expr_bool
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_FLOAT: // "float"
      case symbol_kind::S_expr_float: // expr_float
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_INT: // "int"
      case symbol_kind::S_expr_int: // expr_int
        value.copy< long > (that.value);
        break;

      case symbol_kind::S_set: // set
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_var: // expr_var
      case symbol_kind::S_matrix: // matrix
      case symbol_kind::S_expr_mat: // expr_mat
      case symbol_kind::S_range: // range
      case symbol_kind::S_int_val: // int_val
      case symbol_kind::S_expr_none: // expr_none
        value.copy< ptc::ir::Expr * > (that.value);
        break;

      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmts_ne: // stmts_ne
      case symbol_kind::S_import: // import
      case symbol_kind::S_flowctl: // flowctl
      case symbol_kind::S_return: // return
      case symbol_kind::S_for: // for
      case symbol_kind::S_while: // while
      case symbol_kind::S_dowhile: // dowhile
      case symbol_kind::S_if: // if
      case symbol_kind::S_struct: // struct
      case symbol_kind::S_declistval: // declistval
      case symbol_kind::S_function: // function
      case symbol_kind::S_vardecl: // vardecl
      case symbol_kind::S_vardef: // vardef
      case symbol_kind::S_mattype: // mattype
      case symbol_kind::S_type: // type
        value.copy< ptc::ir::IR * > (that.value);
        break;

      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_EXT_ID: // "external identifier"
      case symbol_kind::S_fun_id: // fun_id
      case symbol_kind::S_expr_str: // expr_str
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_callarglist: // callarglist
      case symbol_kind::S_matvals: // matvals
      case symbol_kind::S_matsq: // matsq
        value.copy< std::vector<ptc::ir::Expr *>  > (that.value);
        break;

      case symbol_kind::S_funargsnvar: // funargsnvar
      case symbol_kind::S_funargs: // funargs
        value.copy< std::vector<ptc::ir::FormalParamDecl *>  > (that.value);
        break;

      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_block: // block
      case symbol_kind::S_body: // body
      case symbol_kind::S_scope_body: // scope_body
      case symbol_kind::S_else: // else
      case symbol_kind::S_decllist: // decllist
        value.copy< std::vector<ptc::ir::IR *>  > (that.value);
        break;

      case symbol_kind::S_id_list: // id_list
        value.copy< std::vector<std::string>  > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_BOOL: // "bool"
      case symbol_kind::S_expr_bool: // expr_bool
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_FLOAT: // "float"
      case symbol_kind::S_expr_float: // expr_float
        value.move< double > (that.value);
        break;

      case symbol_kind::S_INT: // "int"
      case symbol_kind::S_expr_int: // expr_int
        value.move< long > (that.value);
        break;

      case symbol_kind::S_set: // set
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_var: // expr_var
      case symbol_kind::S_matrix: // matrix
      case symbol_kind::S_expr_mat: // expr_mat
      case symbol_kind::S_range: // range
      case symbol_kind::S_int_val: // int_val
      case symbol_kind::S_expr_none: // expr_none
        value.move< ptc::ir::Expr * > (that.value);
        break;

      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmts_ne: // stmts_ne
      case symbol_kind::S_import: // import
      case symbol_kind::S_flowctl: // flowctl
      case symbol_kind::S_return: // return
      case symbol_kind::S_for: // for
      case symbol_kind::S_while: // while
      case symbol_kind::S_dowhile: // dowhile
      case symbol_kind::S_if: // if
      case symbol_kind::S_struct: // struct
      case symbol_kind::S_declistval: // declistval
      case symbol_kind::S_function: // function
      case symbol_kind::S_vardecl: // vardecl
      case symbol_kind::S_vardef: // vardef
      case symbol_kind::S_mattype: // mattype
      case symbol_kind::S_type: // type
        value.move< ptc::ir::IR * > (that.value);
        break;

      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_EXT_ID: // "external identifier"
      case symbol_kind::S_fun_id: // fun_id
      case symbol_kind::S_expr_str: // expr_str
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_callarglist: // callarglist
      case symbol_kind::S_matvals: // matvals
      case symbol_kind::S_matsq: // matsq
        value.move< std::vector<ptc::ir::Expr *>  > (that.value);
        break;

      case symbol_kind::S_funargsnvar: // funargsnvar
      case symbol_kind::S_funargs: // funargs
        value.move< std::vector<ptc::ir::FormalParamDecl *>  > (that.value);
        break;

      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_block: // block
      case symbol_kind::S_body: // body
      case symbol_kind::S_scope_body: // scope_body
      case symbol_kind::S_else: // else
      case symbol_kind::S_decllist: // decllist
        value.move< std::vector<ptc::ir::IR *>  > (that.value);
        break;

      case symbol_kind::S_id_list: // id_list
        value.move< std::vector<std::string>  > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
   Parser ::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
   Parser ::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
   Parser ::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
   Parser ::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
   Parser ::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
   Parser ::debug_stream () const
  {
    return *yycdebug_;
  }

  void
   Parser ::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


   Parser ::debug_level_type
   Parser ::debug_level () const
  {
    return yydebug_;
  }

  void
   Parser ::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

   Parser ::state_type
   Parser ::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
   Parser ::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
   Parser ::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
   Parser ::operator() ()
  {
    return parse ();
  }

  int
   Parser ::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_BOOL: // "bool"
      case symbol_kind::S_expr_bool: // expr_bool
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_FLOAT: // "float"
      case symbol_kind::S_expr_float: // expr_float
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_INT: // "int"
      case symbol_kind::S_expr_int: // expr_int
        yylhs.value.emplace< long > ();
        break;

      case symbol_kind::S_set: // set
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_var: // expr_var
      case symbol_kind::S_matrix: // matrix
      case symbol_kind::S_expr_mat: // expr_mat
      case symbol_kind::S_range: // range
      case symbol_kind::S_int_val: // int_val
      case symbol_kind::S_expr_none: // expr_none
        yylhs.value.emplace< ptc::ir::Expr * > ();
        break;

      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmts_ne: // stmts_ne
      case symbol_kind::S_import: // import
      case symbol_kind::S_flowctl: // flowctl
      case symbol_kind::S_return: // return
      case symbol_kind::S_for: // for
      case symbol_kind::S_while: // while
      case symbol_kind::S_dowhile: // dowhile
      case symbol_kind::S_if: // if
      case symbol_kind::S_struct: // struct
      case symbol_kind::S_declistval: // declistval
      case symbol_kind::S_function: // function
      case symbol_kind::S_vardecl: // vardecl
      case symbol_kind::S_vardef: // vardef
      case symbol_kind::S_mattype: // mattype
      case symbol_kind::S_type: // type
        yylhs.value.emplace< ptc::ir::IR * > ();
        break;

      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_EXT_ID: // "external identifier"
      case symbol_kind::S_fun_id: // fun_id
      case symbol_kind::S_expr_str: // expr_str
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_callarglist: // callarglist
      case symbol_kind::S_matvals: // matvals
      case symbol_kind::S_matsq: // matsq
        yylhs.value.emplace< std::vector<ptc::ir::Expr *>  > ();
        break;

      case symbol_kind::S_funargsnvar: // funargsnvar
      case symbol_kind::S_funargs: // funargs
        yylhs.value.emplace< std::vector<ptc::ir::FormalParamDecl *>  > ();
        break;

      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_block: // block
      case symbol_kind::S_body: // body
      case symbol_kind::S_scope_body: // scope_body
      case symbol_kind::S_else: // else
      case symbol_kind::S_decllist: // decllist
        yylhs.value.emplace< std::vector<ptc::ir::IR *>  > ();
        break;

      case symbol_kind::S_id_list: // id_list
        yylhs.value.emplace< std::vector<std::string>  > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 3: // start: stmt "end of file"
#line 232 "frontend/parser.yy"
                        { scanner->parseEntry(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1182 "frontend/parser.cpp"
    break;

  case 4: // stmt: stmts
#line 234 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1188 "frontend/parser.cpp"
    break;

  case 5: // stmt: stmt stmts
#line 235 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1194 "frontend/parser.cpp"
    break;

  case 6: // stmt: stmt error stmts
#line 236 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1200 "frontend/parser.cpp"
    break;

  case 9: // stmts: "terminator (\\n or ;)"
#line 243 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = nullptr; }
#line 1206 "frontend/parser.cpp"
    break;

  case 10: // stmts: stmts_ne
#line 244 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1212 "frontend/parser.cpp"
    break;

  case 11: // stmts_ne: set stmt_end
#line 246 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1218 "frontend/parser.cpp"
    break;

  case 12: // stmts_ne: vardecl stmt_end
#line 247 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1224 "frontend/parser.cpp"
    break;

  case 13: // stmts_ne: vardef stmt_end
#line 248 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1230 "frontend/parser.cpp"
    break;

  case 14: // stmts_ne: import stmt_end
#line 249 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1236 "frontend/parser.cpp"
    break;

  case 15: // stmts_ne: for
#line 250 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1242 "frontend/parser.cpp"
    break;

  case 16: // stmts_ne: if
#line 251 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1248 "frontend/parser.cpp"
    break;

  case 17: // stmts_ne: while
#line 252 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1254 "frontend/parser.cpp"
    break;

  case 18: // stmts_ne: dowhile
#line 253 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1260 "frontend/parser.cpp"
    break;

  case 19: // stmts_ne: struct
#line 254 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1266 "frontend/parser.cpp"
    break;

  case 20: // stmts_ne: function
#line 255 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1272 "frontend/parser.cpp"
    break;

  case 21: // stmts_ne: flowctl stmt_end
#line 256 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1278 "frontend/parser.cpp"
    break;

  case 22: // stmts_ne: expr stmt_end
#line 257 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1284 "frontend/parser.cpp"
    break;

  case 23: // block: "{" "}"
#line 261 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1290 "frontend/parser.cpp"
    break;

  case 24: // block: "{" stmt "}"
#line 262 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1296 "frontend/parser.cpp"
    break;

  case 25: // block: "terminator (\\n or ;)" "{" stmt "}"
#line 263 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1302 "frontend/parser.cpp"
    break;

  case 26: // block: "{" stmt "}" "terminator (\\n or ;)"
#line 264 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1308 "frontend/parser.cpp"
    break;

  case 27: // block: "terminator (\\n or ;)" "{" stmt "}" "terminator (\\n or ;)"
#line 265 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1314 "frontend/parser.cpp"
    break;

  case 28: // body: stmts_ne
#line 268 "frontend/parser.yy"
                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1320 "frontend/parser.cpp"
    break;

  case 29: // body: block
#line 269 "frontend/parser.yy"
                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1326 "frontend/parser.cpp"
    break;

  case 30: // scope_body: stmts_ne
#line 272 "frontend/parser.yy"
                      { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); scanner->leaveScope(); }
#line 1332 "frontend/parser.cpp"
    break;

  case 31: // scope_body: block
#line 273 "frontend/parser.yy"
                      { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); scanner->leaveScope(); }
#line 1338 "frontend/parser.cpp"
    break;

  case 32: // import: "import" id_list
#line 277 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::IR * > () = scanner->parseImports(yystack_[0].value.as < std::vector<std::string>  > ()); }
#line 1344 "frontend/parser.cpp"
    break;

  case 33: // id_list: "identifier"
#line 279 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseImportName(yystack_[0].value.as < std::string > ()); }
#line 1350 "frontend/parser.cpp"
    break;

  case 34: // id_list: "identifier" "," id_list
#line 280 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseAddImportName(yystack_[0].value.as < std::vector<std::string>  > (), yystack_[2].value.as < std::string > ()); }
#line 1356 "frontend/parser.cpp"
    break;

  case 35: // flowctl: "break"
#line 284 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseBreak(); }
#line 1362 "frontend/parser.cpp"
    break;

  case 36: // flowctl: "continue"
#line 285 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseContinue(); }
#line 1368 "frontend/parser.cpp"
    break;

  case 37: // flowctl: return
#line 286 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1374 "frontend/parser.cpp"
    break;

  case 38: // return: "return"
#line 288 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(nullptr); }
#line 1380 "frontend/parser.cpp"
    break;

  case 39: // return: "return" expr
#line 289 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1386 "frontend/parser.cpp"
    break;

  case 40: // for: "for" "(" vardecl ":" expr ")" body
#line 293 "frontend/parser.yy"
                                              { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1392 "frontend/parser.cpp"
    break;

  case 41: // for: "for" "(" "identifier" ":" expr ")" body
#line 294 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1398 "frontend/parser.cpp"
    break;

  case 42: // for: "for" "(" "external identifier" ":" expr ")" body
#line 295 "frontend/parser.yy"
                                              { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1404 "frontend/parser.cpp"
    break;

  case 43: // for: "for" "(" vardecl ":" range ")" body
#line 296 "frontend/parser.yy"
                                               { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1410 "frontend/parser.cpp"
    break;

  case 44: // for: "for" "(" "identifier" ":" range ")" body
#line 297 "frontend/parser.yy"
                                           { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1416 "frontend/parser.cpp"
    break;

  case 45: // for: "for" "(" "external identifier" ":" range ")" body
#line 298 "frontend/parser.yy"
                                               { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1422 "frontend/parser.cpp"
    break;

  case 46: // while: wh_kw "(" expr ")" scope_body
#line 302 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseWhile(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1428 "frontend/parser.cpp"
    break;

  case 47: // wh_kw: "while"
#line 304 "frontend/parser.yy"
                { scanner->enterBlockScope(); }
#line 1434 "frontend/parser.cpp"
    break;

  case 48: // dowhile: do_kw scope_body "while" "(" expr ")"
#line 306 "frontend/parser.yy"
                                                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseDoWhile(yystack_[1].value.as < ptc::ir::Expr * > (), yystack_[4].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1440 "frontend/parser.cpp"
    break;

  case 49: // do_kw: "do"
#line 308 "frontend/parser.yy"
             { scanner->enterBlockScope(); }
#line 1446 "frontend/parser.cpp"
    break;

  case 50: // if: if_kw "(" expr ")" scope_body else
#line 311 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseIfStmt(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1452 "frontend/parser.cpp"
    break;

  case 51: // else: el_kw scope_body
#line 313 "frontend/parser.yy"
                         { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1458 "frontend/parser.cpp"
    break;

  case 52: // else: %empty
#line 314 "frontend/parser.yy"
                    { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1464 "frontend/parser.cpp"
    break;

  case 53: // if_kw: "if"
#line 316 "frontend/parser.yy"
             { scanner->enterBlockScope(); }
#line 1470 "frontend/parser.cpp"
    break;

  case 54: // el_kw: "else"
#line 317 "frontend/parser.yy"
               { scanner->enterBlockScope(); }
#line 1476 "frontend/parser.cpp"
    break;

  case 55: // struct: "'struct'" "identifier" "{" "}"
#line 320 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[2].value.as < std::string > (), std::vector<ptc::ir::IR *>{}); }
#line 1482 "frontend/parser.cpp"
    break;

  case 56: // struct: "'struct'" "identifier" "{" decllist "}"
#line 321 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1488 "frontend/parser.cpp"
    break;

  case 57: // struct: "'struct'" "identifier" "terminator (\\n or ;)" "{" decllist "}"
#line 322 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[4].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1494 "frontend/parser.cpp"
    break;

  case 59: // decllist: "terminator (\\n or ;)" decllist
#line 325 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1500 "frontend/parser.cpp"
    break;

  case 60: // decllist: declistval "terminator (\\n or ;)"
#line 326 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[1].value.as < ptc::ir::IR * > (), std::vector<ptc::ir::IR *>{}); }
#line 1506 "frontend/parser.cpp"
    break;

  case 61: // decllist: declistval "terminator (\\n or ;)" decllist
#line 327 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[2].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1512 "frontend/parser.cpp"
    break;

  case 62: // declistval: type "identifier"
#line 329 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > (), nullptr); }
#line 1518 "frontend/parser.cpp"
    break;

  case 63: // declistval: type "identifier" "=" expr
#line 330 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1524 "frontend/parser.cpp"
    break;

  case 65: // function: type fun_id "(" ")" block
#line 335 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1530 "frontend/parser.cpp"
    break;

  case 66: // function: type fun_id "(" funargs ")" block
#line 336 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[5].value.as < ptc::ir::IR * > (), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1536 "frontend/parser.cpp"
    break;

  case 67: // function: "'void'" fun_id "(" ")" block
#line 337 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1542 "frontend/parser.cpp"
    break;

  case 68: // function: "'void'" fun_id "(" funargs ")" block
#line 338 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1548 "frontend/parser.cpp"
    break;

  case 69: // fun_id: "identifier"
#line 340 "frontend/parser.yy"
            { scanner->enterFunScope(); yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1554 "frontend/parser.cpp"
    break;

  case 70: // funargsnvar: type "identifier"
#line 342 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseFunParam(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1560 "frontend/parser.cpp"
    break;

  case 71: // funargsnvar: funargsnvar "," type "identifier"
#line 343 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseAddFunParam(yystack_[3].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1566 "frontend/parser.cpp"
    break;

  case 72: // funargs: ".." "identifier"
#line 345 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseFunParam(scanner->sym_lookup(VARARGS_CSTR, false, true), yystack_[0].value.as < std::string > ()); }
#line 1572 "frontend/parser.cpp"
    break;

  case 73: // funargs: funargsnvar "," ".." "identifier"
#line 346 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseAddFunParam(yystack_[3].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), scanner->sym_lookup(VARARGS_CSTR, false, true), yystack_[0].value.as < std::string > ());}
#line 1578 "frontend/parser.cpp"
    break;

  case 74: // funargs: funargsnvar
#line 347 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = yystack_[0].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (); }
#line 1584 "frontend/parser.cpp"
    break;

  case 75: // vardecl: type "identifier"
#line 352 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1590 "frontend/parser.cpp"
    break;

  case 76: // vardef: type "identifier" "=" struct_val
#line 356 "frontend/parser.yy"
         { yylhs.value.as < ptc::ir::IR * > () = yystack_[3].value.as < ptc::ir::IR * > (); }
#line 1596 "frontend/parser.cpp"
    break;

  case 77: // vardef: type "identifier" "=" expr
#line 357 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1602 "frontend/parser.cpp"
    break;

  case 80: // set: expr "++=" expr
#line 363 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1608 "frontend/parser.cpp"
    break;

  case 81: // set: expr "**=" expr
#line 364 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1614 "frontend/parser.cpp"
    break;

  case 82: // set: expr "%=" expr
#line 365 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1620 "frontend/parser.cpp"
    break;

  case 83: // set: expr "/=" expr
#line 366 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1626 "frontend/parser.cpp"
    break;

  case 84: // set: expr "*=" expr
#line 367 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1632 "frontend/parser.cpp"
    break;

  case 85: // set: expr "-=" expr
#line 368 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1638 "frontend/parser.cpp"
    break;

  case 86: // set: expr "+=" expr
#line 369 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1644 "frontend/parser.cpp"
    break;

  case 87: // set: expr "&=" expr
#line 370 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1650 "frontend/parser.cpp"
    break;

  case 88: // set: expr "|=" expr
#line 371 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1656 "frontend/parser.cpp"
    break;

  case 89: // set: expr "^=" expr
#line 372 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1662 "frontend/parser.cpp"
    break;

  case 90: // set: expr "<<=" expr
#line 373 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1668 "frontend/parser.cpp"
    break;

  case 91: // set: expr ">>=" expr
#line 374 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1674 "frontend/parser.cpp"
    break;

  case 92: // set: expr "=" expr
#line 375 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1680 "frontend/parser.cpp"
    break;

  case 93: // set: expr "=" set
#line 376 "frontend/parser.yy"
      { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1686 "frontend/parser.cpp"
    break;

  case 94: // callarglist: expr
#line 380 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseFunCallArg(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1692 "frontend/parser.cpp"
    break;

  case 95: // callarglist: callarglist "," expr
#line 381 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddFunCallArg(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1698 "frontend/parser.cpp"
    break;

  case 96: // expr: expr_mat
#line 385 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1704 "frontend/parser.cpp"
    break;

  case 97: // expr: expr_var
#line 386 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1710 "frontend/parser.cpp"
    break;

  case 98: // expr: expr_none
#line 387 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1716 "frontend/parser.cpp"
    break;

  case 100: // expr: expr_int
#line 389 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 1722 "frontend/parser.cpp"
    break;

  case 101: // expr: expr_float
#line 390 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFloat(yystack_[0].value.as < double > ()); }
#line 1728 "frontend/parser.cpp"
    break;

  case 102: // expr: expr_str
#line 391 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseString(yystack_[0].value.as < std::string > ()); }
#line 1734 "frontend/parser.cpp"
    break;

  case 103: // expr: expr_bool
#line 392 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseBool(yystack_[0].value.as < bool > ()); }
#line 1740 "frontend/parser.cpp"
    break;

  case 104: // expr_var: "identifier"
#line 395 "frontend/parser.yy"
              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > ()); }
#line 1746 "frontend/parser.cpp"
    break;

  case 105: // expr_var: "external identifier"
#line 396 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > (), true); }
#line 1752 "frontend/parser.cpp"
    break;

  case 106: // expr_var: "-" "identifier"
#line 397 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1758 "frontend/parser.cpp"
    break;

  case 107: // expr_var: "-" "external identifier"
#line 398 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > (), true), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1764 "frontend/parser.cpp"
    break;

  case 108: // expr_var: "(" expr_var ")"
#line 399 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1770 "frontend/parser.cpp"
    break;

  case 109: // expr_var: expr_var "(" ")"
#line 401 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[2].value.as < ptc::ir::Expr * > (), std::vector<ptc::ir::Expr *>{}); }
#line 1776 "frontend/parser.cpp"
    break;

  case 110: // expr_var: expr_var "(" callarglist ")"
#line 402 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 1782 "frontend/parser.cpp"
    break;

  case 111: // expr_var: expr_str "[" int_val "]"
#line 404 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1788 "frontend/parser.cpp"
    break;

  case 112: // expr_var: expr_mat "[" int_val "]"
#line 405 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1794 "frontend/parser.cpp"
    break;

  case 113: // expr_var: "identifier" "[" int_val "]"
#line 406 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1800 "frontend/parser.cpp"
    break;

  case 114: // expr_var: "external identifier" "[" int_val "]"
#line 407 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1806 "frontend/parser.cpp"
    break;

  case 115: // expr_var: expr_var "[" int_val "]"
#line 408 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1812 "frontend/parser.cpp"
    break;

  case 116: // expr_var: expr_mat slice
#line 410 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1818 "frontend/parser.cpp"
    break;

  case 119: // expr_var: expr_var slice
#line 413 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1824 "frontend/parser.cpp"
    break;

  case 120: // expr_var: "identifier" "." expr_var
#line 415 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1830 "frontend/parser.cpp"
    break;

  case 121: // expr_var: "external identifier" "." expr_var
#line 416 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1836 "frontend/parser.cpp"
    break;

  case 122: // expr_var: expr_var "." expr_var
#line 417 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1842 "frontend/parser.cpp"
    break;

  case 123: // expr_var: expr_float "**" expr_var
#line 419 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1848 "frontend/parser.cpp"
    break;

  case 124: // expr_var: expr_var "**" expr_float
#line 420 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1854 "frontend/parser.cpp"
    break;

  case 125: // expr_var: expr_var "**" expr_var
#line 421 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1860 "frontend/parser.cpp"
    break;

  case 126: // expr_var: expr_int "**" expr_var
#line 422 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < long > ()) /*Float on purpose*/, yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1866 "frontend/parser.cpp"
    break;

  case 127: // expr_var: expr_var "**" expr_int
#line 423 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < long > ()) /*Float on purpose*/, ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1872 "frontend/parser.cpp"
    break;

  case 128: // expr_var: expr_int "*" expr_var
#line 425 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1878 "frontend/parser.cpp"
    break;

  case 129: // expr_var: expr_float "*" expr_var
#line 426 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1884 "frontend/parser.cpp"
    break;

  case 130: // expr_var: expr_var "*" expr_int
#line 427 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1890 "frontend/parser.cpp"
    break;

  case 131: // expr_var: expr_var "*" expr_float
#line 428 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1896 "frontend/parser.cpp"
    break;

  case 132: // expr_var: expr_mat "*" expr_mat
#line 429 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1902 "frontend/parser.cpp"
    break;

  case 133: // expr_var: expr_mat "*" expr_var
#line 430 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1908 "frontend/parser.cpp"
    break;

  case 134: // expr_var: expr_var "*" expr_mat
#line 431 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1914 "frontend/parser.cpp"
    break;

  case 135: // expr_var: expr_var "*" expr_var
#line 432 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1920 "frontend/parser.cpp"
    break;

  case 136: // expr_var: expr_int "/" expr_var
#line 434 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1926 "frontend/parser.cpp"
    break;

  case 137: // expr_var: expr_float "/" expr_var
#line 435 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1932 "frontend/parser.cpp"
    break;

  case 138: // expr_var: expr_var "/" expr_int
#line 436 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1938 "frontend/parser.cpp"
    break;

  case 139: // expr_var: expr_var "/" expr_float
#line 437 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1944 "frontend/parser.cpp"
    break;

  case 140: // expr_var: expr_var "/" expr_var
#line 438 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1950 "frontend/parser.cpp"
    break;

  case 141: // expr_var: expr_int "%" expr_var
#line 440 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1956 "frontend/parser.cpp"
    break;

  case 142: // expr_var: expr_float "%" expr_var
#line 441 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1962 "frontend/parser.cpp"
    break;

  case 143: // expr_var: expr_var "%" expr_int
#line 442 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1968 "frontend/parser.cpp"
    break;

  case 144: // expr_var: expr_var "%" expr_float
#line 443 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1974 "frontend/parser.cpp"
    break;

  case 145: // expr_var: expr_var "%" expr_var
#line 444 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1980 "frontend/parser.cpp"
    break;

  case 146: // expr_var: expr_int "+" expr_var
#line 446 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1986 "frontend/parser.cpp"
    break;

  case 147: // expr_var: expr_float "+" expr_var
#line 447 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1992 "frontend/parser.cpp"
    break;

  case 148: // expr_var: expr_var "+" expr_int
#line 448 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1998 "frontend/parser.cpp"
    break;

  case 149: // expr_var: expr_var "+" expr_float
#line 449 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2004 "frontend/parser.cpp"
    break;

  case 150: // expr_var: expr_mat "+" expr_mat
#line 450 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2010 "frontend/parser.cpp"
    break;

  case 151: // expr_var: expr_var "+" expr_mat
#line 451 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2016 "frontend/parser.cpp"
    break;

  case 152: // expr_var: expr_mat "+" expr_var
#line 452 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2022 "frontend/parser.cpp"
    break;

  case 153: // expr_var: expr_var "+" expr_var
#line 453 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2028 "frontend/parser.cpp"
    break;

  case 154: // expr_var: expr_int "-" expr_var
#line 455 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2034 "frontend/parser.cpp"
    break;

  case 155: // expr_var: expr_float "-" expr_var
#line 456 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2040 "frontend/parser.cpp"
    break;

  case 156: // expr_var: expr_var "-" expr_int
#line 457 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2046 "frontend/parser.cpp"
    break;

  case 157: // expr_var: expr_var "-" expr_float
#line 458 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2052 "frontend/parser.cpp"
    break;

  case 158: // expr_var: expr_mat "-" expr_mat
#line 459 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2058 "frontend/parser.cpp"
    break;

  case 159: // expr_var: expr_var "-" expr_mat
#line 460 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2064 "frontend/parser.cpp"
    break;

  case 160: // expr_var: expr_mat "-" expr_var
#line 461 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2070 "frontend/parser.cpp"
    break;

  case 161: // expr_var: expr_var "-" expr_var
#line 462 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2076 "frontend/parser.cpp"
    break;

  case 162: // expr_var: expr_int "<<" expr_var
#line 464 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2082 "frontend/parser.cpp"
    break;

  case 163: // expr_var: expr_var "<<" expr_int
#line 465 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2088 "frontend/parser.cpp"
    break;

  case 164: // expr_var: expr_var "<<" expr_var
#line 466 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2094 "frontend/parser.cpp"
    break;

  case 165: // expr_var: expr_int ">>" expr_var
#line 468 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2100 "frontend/parser.cpp"
    break;

  case 166: // expr_var: expr_var ">>" expr_int
#line 469 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2106 "frontend/parser.cpp"
    break;

  case 167: // expr_var: expr_var ">>" expr_var
#line 470 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2112 "frontend/parser.cpp"
    break;

  case 168: // expr_var: expr_int ">" expr_var
#line 472 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2118 "frontend/parser.cpp"
    break;

  case 169: // expr_var: expr_float ">" expr_var
#line 473 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2124 "frontend/parser.cpp"
    break;

  case 170: // expr_var: expr_str ">" expr_var
#line 474 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2130 "frontend/parser.cpp"
    break;

  case 171: // expr_var: expr_var ">" expr_int
#line 475 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2136 "frontend/parser.cpp"
    break;

  case 172: // expr_var: expr_var ">" expr_float
#line 476 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2142 "frontend/parser.cpp"
    break;

  case 173: // expr_var: expr_var ">" expr_str
#line 477 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2148 "frontend/parser.cpp"
    break;

  case 174: // expr_var: expr_var ">" expr_var
#line 478 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2154 "frontend/parser.cpp"
    break;

  case 175: // expr_var: expr_int ">=" expr_var
#line 480 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2160 "frontend/parser.cpp"
    break;

  case 176: // expr_var: expr_float ">=" expr_var
#line 481 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2166 "frontend/parser.cpp"
    break;

  case 177: // expr_var: expr_str ">=" expr_var
#line 482 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2172 "frontend/parser.cpp"
    break;

  case 178: // expr_var: expr_var ">=" expr_int
#line 483 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2178 "frontend/parser.cpp"
    break;

  case 179: // expr_var: expr_var ">=" expr_float
#line 484 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2184 "frontend/parser.cpp"
    break;

  case 180: // expr_var: expr_var ">=" expr_str
#line 485 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2190 "frontend/parser.cpp"
    break;

  case 181: // expr_var: expr_var ">=" expr_var
#line 486 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2196 "frontend/parser.cpp"
    break;

  case 182: // expr_var: expr_int "<" expr_var
#line 488 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2202 "frontend/parser.cpp"
    break;

  case 183: // expr_var: expr_float "<" expr_var
#line 489 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2208 "frontend/parser.cpp"
    break;

  case 184: // expr_var: expr_str "<" expr_var
#line 490 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2214 "frontend/parser.cpp"
    break;

  case 185: // expr_var: expr_var "<" expr_int
#line 491 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2220 "frontend/parser.cpp"
    break;

  case 186: // expr_var: expr_var "<" expr_float
#line 492 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2226 "frontend/parser.cpp"
    break;

  case 187: // expr_var: expr_var "<" expr_str
#line 493 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2232 "frontend/parser.cpp"
    break;

  case 188: // expr_var: expr_var "<" expr_var
#line 494 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2238 "frontend/parser.cpp"
    break;

  case 189: // expr_var: expr_int "<=" expr_var
#line 496 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2244 "frontend/parser.cpp"
    break;

  case 190: // expr_var: expr_float "<=" expr_var
#line 497 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2250 "frontend/parser.cpp"
    break;

  case 191: // expr_var: expr_str "<=" expr_var
#line 498 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2256 "frontend/parser.cpp"
    break;

  case 192: // expr_var: expr_var "<=" expr_int
#line 499 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2262 "frontend/parser.cpp"
    break;

  case 193: // expr_var: expr_var "<=" expr_float
#line 500 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2268 "frontend/parser.cpp"
    break;

  case 194: // expr_var: expr_var "<=" expr_str
#line 501 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2274 "frontend/parser.cpp"
    break;

  case 195: // expr_var: expr_var "<=" expr_var
#line 502 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2280 "frontend/parser.cpp"
    break;

  case 196: // expr_var: expr_int "==" expr_var
#line 504 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2286 "frontend/parser.cpp"
    break;

  case 197: // expr_var: expr_float "==" expr_var
#line 505 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2292 "frontend/parser.cpp"
    break;

  case 198: // expr_var: expr_str "==" expr_var
#line 506 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2298 "frontend/parser.cpp"
    break;

  case 199: // expr_var: expr_bool "==" expr_var
#line 507 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2304 "frontend/parser.cpp"
    break;

  case 200: // expr_var: expr_none "==" expr_var
#line 508 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2310 "frontend/parser.cpp"
    break;

  case 203: // expr_var: expr_var "==" expr_int
#line 511 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2316 "frontend/parser.cpp"
    break;

  case 204: // expr_var: expr_var "==" expr_float
#line 512 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2322 "frontend/parser.cpp"
    break;

  case 205: // expr_var: expr_var "==" expr_str
#line 513 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2328 "frontend/parser.cpp"
    break;

  case 206: // expr_var: expr_var "==" expr_bool
#line 514 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2334 "frontend/parser.cpp"
    break;

  case 207: // expr_var: expr_var "==" expr_none
#line 515 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2340 "frontend/parser.cpp"
    break;

  case 208: // expr_var: expr_var "==" expr_struct
#line 516 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2346 "frontend/parser.cpp"
    break;

  case 209: // expr_var: expr_mat "==" expr_mat
#line 517 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2352 "frontend/parser.cpp"
    break;

  case 210: // expr_var: expr_var "==" expr_mat
#line 518 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2358 "frontend/parser.cpp"
    break;

  case 211: // expr_var: expr_mat "==" expr_var
#line 519 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2364 "frontend/parser.cpp"
    break;

  case 212: // expr_var: expr_var "==" expr_var
#line 520 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2370 "frontend/parser.cpp"
    break;

  case 213: // expr_var: expr_int "!=" expr_var
#line 522 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2376 "frontend/parser.cpp"
    break;

  case 214: // expr_var: expr_float "!=" expr_var
#line 523 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2382 "frontend/parser.cpp"
    break;

  case 215: // expr_var: expr_str "!=" expr_var
#line 524 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2388 "frontend/parser.cpp"
    break;

  case 216: // expr_var: expr_bool "!=" expr_var
#line 525 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2394 "frontend/parser.cpp"
    break;

  case 217: // expr_var: expr_none "!=" expr_var
#line 526 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2400 "frontend/parser.cpp"
    break;

  case 220: // expr_var: expr_var "!=" expr_int
#line 529 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2406 "frontend/parser.cpp"
    break;

  case 221: // expr_var: expr_var "!=" expr_float
#line 530 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2412 "frontend/parser.cpp"
    break;

  case 222: // expr_var: expr_var "!=" expr_str
#line 531 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2418 "frontend/parser.cpp"
    break;

  case 223: // expr_var: expr_var "!=" expr_bool
#line 532 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2424 "frontend/parser.cpp"
    break;

  case 224: // expr_var: expr_var "!=" expr_none
#line 533 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2430 "frontend/parser.cpp"
    break;

  case 225: // expr_var: expr_var "!=" expr_struct
#line 534 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2436 "frontend/parser.cpp"
    break;

  case 226: // expr_var: expr_mat "!=" expr_mat
#line 535 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2442 "frontend/parser.cpp"
    break;

  case 227: // expr_var: expr_var "!=" expr_mat
#line 536 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2448 "frontend/parser.cpp"
    break;

  case 228: // expr_var: expr_mat "!=" expr_var
#line 537 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2454 "frontend/parser.cpp"
    break;

  case 229: // expr_var: expr_var "!=" expr_var
#line 538 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2460 "frontend/parser.cpp"
    break;

  case 230: // expr_var: expr_int "&" expr_var
#line 540 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2466 "frontend/parser.cpp"
    break;

  case 231: // expr_var: expr_var "&" expr_int
#line 541 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2472 "frontend/parser.cpp"
    break;

  case 232: // expr_var: expr_var "&" expr_var
#line 542 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2478 "frontend/parser.cpp"
    break;

  case 233: // expr_var: expr_int "^" expr_var
#line 544 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2484 "frontend/parser.cpp"
    break;

  case 234: // expr_var: expr_var "^" expr_int
#line 545 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2490 "frontend/parser.cpp"
    break;

  case 235: // expr_var: expr_var "^" expr_var
#line 546 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2496 "frontend/parser.cpp"
    break;

  case 236: // expr_var: expr_int "|" expr_var
#line 548 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2502 "frontend/parser.cpp"
    break;

  case 237: // expr_var: expr_var "|" expr_int
#line 549 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2508 "frontend/parser.cpp"
    break;

  case 238: // expr_var: expr_var "|" expr_var
#line 550 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2514 "frontend/parser.cpp"
    break;

  case 243: // expr_var: expr_none "in" expr_mat
#line 556 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2520 "frontend/parser.cpp"
    break;

  case 245: // expr_var: expr_mat "in" expr_mat
#line 558 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2526 "frontend/parser.cpp"
    break;

  case 250: // expr_var: expr_none "in" expr_var
#line 563 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2532 "frontend/parser.cpp"
    break;

  case 252: // expr_var: expr_mat "in" expr_var
#line 565 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2538 "frontend/parser.cpp"
    break;

  case 253: // expr_var: expr_var "in" expr_str
#line 566 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2544 "frontend/parser.cpp"
    break;

  case 254: // expr_var: expr_var "in" expr_var
#line 567 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2550 "frontend/parser.cpp"
    break;

  case 255: // expr_var: expr_bool "and" expr_var
#line 569 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2556 "frontend/parser.cpp"
    break;

  case 256: // expr_var: expr_var "and" expr_bool
#line 570 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2562 "frontend/parser.cpp"
    break;

  case 257: // expr_var: expr_var "and" expr_var
#line 571 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2568 "frontend/parser.cpp"
    break;

  case 258: // expr_var: expr_bool "or" expr_var
#line 573 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2574 "frontend/parser.cpp"
    break;

  case 259: // expr_var: expr_var "or" expr_bool
#line 574 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2580 "frontend/parser.cpp"
    break;

  case 260: // expr_var: expr_var "or" expr_var
#line 575 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2586 "frontend/parser.cpp"
    break;

  case 261: // expr_var: "not" expr_var
#line 577 "frontend/parser.yy"
                         { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseUnaryPrefixExpr(yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LNOT)); }
#line 2592 "frontend/parser.cpp"
    break;

  case 262: // expr_var: "~" expr_var
#line 579 "frontend/parser.yy"
                         { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseUnaryPrefixExpr(yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BNOT)); }
#line 2598 "frontend/parser.cpp"
    break;

  case 267: // expr_var: expr_none "++" expr_struct
#line 585 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2604 "frontend/parser.cpp"
    break;

  case 274: // expr_var: expr_int "++" expr_var
#line 592 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2610 "frontend/parser.cpp"
    break;

  case 275: // expr_var: expr_float "++" expr_var
#line 593 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2616 "frontend/parser.cpp"
    break;

  case 276: // expr_var: expr_str "++" expr_var
#line 594 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2622 "frontend/parser.cpp"
    break;

  case 277: // expr_var: expr_bool "++" expr_var
#line 595 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2628 "frontend/parser.cpp"
    break;

  case 278: // expr_var: expr_none "++" expr_var
#line 596 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2634 "frontend/parser.cpp"
    break;

  case 280: // expr_var: expr_var "++" expr_int
#line 598 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2640 "frontend/parser.cpp"
    break;

  case 281: // expr_var: expr_var "++" expr_float
#line 599 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2646 "frontend/parser.cpp"
    break;

  case 282: // expr_var: expr_var "++" expr_str
#line 600 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2652 "frontend/parser.cpp"
    break;

  case 283: // expr_var: expr_var "++" expr_bool
#line 601 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2658 "frontend/parser.cpp"
    break;

  case 284: // expr_var: expr_var "++" expr_none
#line 602 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2664 "frontend/parser.cpp"
    break;

  case 285: // expr_var: expr_var "++" expr_struct
#line 603 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2670 "frontend/parser.cpp"
    break;

  case 286: // expr_var: expr_var "++" expr_var
#line 604 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2676 "frontend/parser.cpp"
    break;

  case 287: // matrix: "[" "]"
#line 608 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(std::vector<ptc::ir::Expr *>{}); }
#line 2682 "frontend/parser.cpp"
    break;

  case 288: // matrix: "[" matvals "]"
#line 609 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2688 "frontend/parser.cpp"
    break;

  case 289: // matrix: "[" "terminator (\\n or ;)" matvals "]"
#line 610 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2694 "frontend/parser.cpp"
    break;

  case 290: // matrix: "[" matvals "terminator (\\n or ;)" "]"
#line 611 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2700 "frontend/parser.cpp"
    break;

  case 291: // matrix: "[" "terminator (\\n or ;)" matvals "terminator (\\n or ;)" "]"
#line 612 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2706 "frontend/parser.cpp"
    break;

  case 292: // matvals: expr
#line 615 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixValue(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2712 "frontend/parser.cpp"
    break;

  case 293: // matvals: matvals "," expr
#line 616 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2718 "frontend/parser.cpp"
    break;

  case 294: // matvals: matvals "," "terminator (\\n or ;)" expr
#line 617 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[3].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2724 "frontend/parser.cpp"
    break;

  case 295: // expr_mat: matrix
#line 621 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2730 "frontend/parser.cpp"
    break;

  case 296: // expr_mat: "(" matrix ")"
#line 622 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2736 "frontend/parser.cpp"
    break;

  case 297: // range: "(" range ")"
#line 624 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2742 "frontend/parser.cpp"
    break;

  case 298: // range: int_val ".." int_val
#line 625 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseRange(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2748 "frontend/parser.cpp"
    break;

  case 299: // range: int_val "," int_val ".." int_val
#line 626 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseRange(yystack_[4].value.as < ptc::ir::Expr * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2754 "frontend/parser.cpp"
    break;

  case 300: // int_val: expr_int
#line 628 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 2760 "frontend/parser.cpp"
    break;

  case 301: // int_val: expr_var
#line 629 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2766 "frontend/parser.cpp"
    break;

  case 314: // expr_none: "none"
#line 646 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseNone(); }
#line 2772 "frontend/parser.cpp"
    break;

  case 315: // expr_none: "(" "none" ")"
#line 647 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseNone(); }
#line 2778 "frontend/parser.cpp"
    break;

  case 322: // expr_int: "int"
#line 662 "frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 2784 "frontend/parser.cpp"
    break;

  case 323: // expr_int: "-" expr_int
#line 663 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 2790 "frontend/parser.cpp"
    break;

  case 324: // expr_int: "(" expr_int ")"
#line 664 "frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 2796 "frontend/parser.cpp"
    break;

  case 325: // expr_int: "~" expr_int
#line 665 "frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 2802 "frontend/parser.cpp"
    break;

  case 326: // expr_int: expr_int "*" expr_int
#line 666 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 2808 "frontend/parser.cpp"
    break;

  case 327: // expr_int: expr_int "/" expr_int
#line 667 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 2814 "frontend/parser.cpp"
    break;

  case 328: // expr_int: expr_int "%" expr_int
#line 668 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 2820 "frontend/parser.cpp"
    break;

  case 329: // expr_int: expr_int "-" expr_int
#line 669 "frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 2826 "frontend/parser.cpp"
    break;

  case 330: // expr_int: expr_int "+" expr_int
#line 670 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 2832 "frontend/parser.cpp"
    break;

  case 331: // expr_int: expr_int "<<" expr_int
#line 671 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 2838 "frontend/parser.cpp"
    break;

  case 332: // expr_int: expr_int ">>" expr_int
#line 672 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 2844 "frontend/parser.cpp"
    break;

  case 333: // expr_int: expr_int "&" expr_int
#line 673 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 2850 "frontend/parser.cpp"
    break;

  case 334: // expr_int: expr_int "^" expr_int
#line 674 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 2856 "frontend/parser.cpp"
    break;

  case 335: // expr_int: expr_int "|" expr_int
#line 675 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 2862 "frontend/parser.cpp"
    break;

  case 336: // expr_float: "float"
#line 679 "frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 2868 "frontend/parser.cpp"
    break;

  case 337: // expr_float: "-" expr_float
#line 680 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 2874 "frontend/parser.cpp"
    break;

  case 338: // expr_float: "(" expr_float ")"
#line 681 "frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 2880 "frontend/parser.cpp"
    break;

  case 339: // expr_float: expr_float "**" expr_float
#line 682 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2886 "frontend/parser.cpp"
    break;

  case 340: // expr_float: expr_float "**" expr_int
#line 683 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2892 "frontend/parser.cpp"
    break;

  case 341: // expr_float: expr_int "**" expr_float
#line 684 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2898 "frontend/parser.cpp"
    break;

  case 342: // expr_float: expr_float "*" expr_float
#line 685 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 2904 "frontend/parser.cpp"
    break;

  case 343: // expr_float: expr_float "*" expr_int
#line 686 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 2910 "frontend/parser.cpp"
    break;

  case 344: // expr_float: expr_int "*" expr_float
#line 687 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 2916 "frontend/parser.cpp"
    break;

  case 345: // expr_float: expr_float "/" expr_float
#line 688 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 2922 "frontend/parser.cpp"
    break;

  case 346: // expr_float: expr_float "/" expr_int
#line 689 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 2928 "frontend/parser.cpp"
    break;

  case 347: // expr_float: expr_int "/" expr_float
#line 690 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 2934 "frontend/parser.cpp"
    break;

  case 348: // expr_float: expr_float "%" expr_float
#line 691 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2940 "frontend/parser.cpp"
    break;

  case 349: // expr_float: expr_float "%" expr_int
#line 692 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2946 "frontend/parser.cpp"
    break;

  case 350: // expr_float: expr_int "%" expr_float
#line 693 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2952 "frontend/parser.cpp"
    break;

  case 351: // expr_float: expr_float "-" expr_float
#line 694 "frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 2958 "frontend/parser.cpp"
    break;

  case 352: // expr_float: expr_float "-" expr_int
#line 695 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 2964 "frontend/parser.cpp"
    break;

  case 353: // expr_float: expr_int "-" expr_float
#line 696 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 2970 "frontend/parser.cpp"
    break;

  case 354: // expr_float: expr_float "+" expr_float
#line 697 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 2976 "frontend/parser.cpp"
    break;

  case 355: // expr_float: expr_float "+" expr_int
#line 698 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 2982 "frontend/parser.cpp"
    break;

  case 356: // expr_float: expr_int "+" expr_float
#line 699 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 2988 "frontend/parser.cpp"
    break;

  case 357: // expr_str: "string"
#line 703 "frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2994 "frontend/parser.cpp"
    break;

  case 358: // expr_str: "(" expr_str ")"
#line 704 "frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 3000 "frontend/parser.cpp"
    break;

  case 359: // expr_str: expr_str "++" expr_str
#line 705 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 3006 "frontend/parser.cpp"
    break;

  case 360: // expr_str: expr_str "++" expr_int
#line 706 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 3012 "frontend/parser.cpp"
    break;

  case 361: // expr_str: expr_str "++" expr_float
#line 707 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 3018 "frontend/parser.cpp"
    break;

  case 362: // expr_str: expr_str "++" expr_bool
#line 708 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3024 "frontend/parser.cpp"
    break;

  case 363: // expr_str: expr_str "++" expr_none
#line 709 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 3030 "frontend/parser.cpp"
    break;

  case 364: // expr_str: expr_int "++" expr_str
#line 710 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 3036 "frontend/parser.cpp"
    break;

  case 365: // expr_str: expr_int "++" expr_int
#line 711 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 3042 "frontend/parser.cpp"
    break;

  case 366: // expr_str: expr_int "++" expr_float
#line 712 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 3048 "frontend/parser.cpp"
    break;

  case 367: // expr_str: expr_int "++" expr_bool
#line 713 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3054 "frontend/parser.cpp"
    break;

  case 368: // expr_str: expr_int "++" expr_none
#line 714 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 3060 "frontend/parser.cpp"
    break;

  case 369: // expr_str: expr_float "++" expr_str
#line 715 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 3066 "frontend/parser.cpp"
    break;

  case 370: // expr_str: expr_float "++" expr_int
#line 716 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 3072 "frontend/parser.cpp"
    break;

  case 371: // expr_str: expr_float "++" expr_float
#line 717 "frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 3078 "frontend/parser.cpp"
    break;

  case 372: // expr_str: expr_float "++" expr_bool
#line 718 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3084 "frontend/parser.cpp"
    break;

  case 373: // expr_str: expr_float "++" expr_none
#line 719 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 3090 "frontend/parser.cpp"
    break;

  case 374: // expr_str: expr_bool "++" expr_str
#line 720 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 3096 "frontend/parser.cpp"
    break;

  case 375: // expr_str: expr_bool "++" expr_int
#line 721 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 3102 "frontend/parser.cpp"
    break;

  case 376: // expr_str: expr_bool "++" expr_float
#line 722 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 3108 "frontend/parser.cpp"
    break;

  case 377: // expr_str: expr_bool "++" expr_bool
#line 723 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3114 "frontend/parser.cpp"
    break;

  case 378: // expr_str: expr_bool "++" expr_none
#line 724 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 3120 "frontend/parser.cpp"
    break;

  case 379: // expr_str: expr_none "++" expr_str
#line 725 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 3126 "frontend/parser.cpp"
    break;

  case 380: // expr_str: expr_none "++" expr_int
#line 726 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 3132 "frontend/parser.cpp"
    break;

  case 381: // expr_str: expr_none "++" expr_float
#line 727 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 3138 "frontend/parser.cpp"
    break;

  case 382: // expr_str: expr_none "++" expr_bool
#line 728 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3144 "frontend/parser.cpp"
    break;

  case 383: // expr_str: expr_none "++" expr_none
#line 729 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 3150 "frontend/parser.cpp"
    break;

  case 384: // expr_bool: "bool"
#line 733 "frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 3156 "frontend/parser.cpp"
    break;

  case 385: // expr_bool: "(" expr_bool ")"
#line 734 "frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 3162 "frontend/parser.cpp"
    break;

  case 386: // expr_bool: "not" expr_bool
#line 735 "frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 3168 "frontend/parser.cpp"
    break;

  case 387: // expr_bool: expr_bool "or" expr_bool
#line 736 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 3174 "frontend/parser.cpp"
    break;

  case 388: // expr_bool: expr_bool "and" expr_bool
#line 737 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 3180 "frontend/parser.cpp"
    break;

  case 389: // expr_bool: expr_bool "==" expr_bool
#line 739 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 3186 "frontend/parser.cpp"
    break;

  case 390: // expr_bool: expr_int "==" expr_int
#line 740 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 3192 "frontend/parser.cpp"
    break;

  case 391: // expr_bool: expr_int "==" expr_float
#line 741 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 3198 "frontend/parser.cpp"
    break;

  case 392: // expr_bool: expr_float "==" expr_float
#line 742 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 3204 "frontend/parser.cpp"
    break;

  case 393: // expr_bool: expr_float "==" expr_int
#line 743 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 3210 "frontend/parser.cpp"
    break;

  case 394: // expr_bool: expr_str "==" expr_str
#line 744 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 3216 "frontend/parser.cpp"
    break;

  case 395: // expr_bool: expr_none "==" expr_none
#line 745 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 3222 "frontend/parser.cpp"
    break;

  case 396: // expr_bool: expr_bool "!=" expr_bool
#line 747 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 3228 "frontend/parser.cpp"
    break;

  case 397: // expr_bool: expr_int "!=" expr_int
#line 748 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 3234 "frontend/parser.cpp"
    break;

  case 398: // expr_bool: expr_int "!=" expr_float
#line 749 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 3240 "frontend/parser.cpp"
    break;

  case 399: // expr_bool: expr_float "!=" expr_float
#line 750 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 3246 "frontend/parser.cpp"
    break;

  case 400: // expr_bool: expr_float "!=" expr_int
#line 751 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 3252 "frontend/parser.cpp"
    break;

  case 401: // expr_bool: expr_str "!=" expr_str
#line 752 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 3258 "frontend/parser.cpp"
    break;

  case 402: // expr_bool: expr_none "!=" expr_none
#line 753 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 3264 "frontend/parser.cpp"
    break;

  case 403: // expr_bool: expr_int ">" expr_int
#line 755 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 3270 "frontend/parser.cpp"
    break;

  case 404: // expr_bool: expr_int ">" expr_float
#line 756 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 3276 "frontend/parser.cpp"
    break;

  case 405: // expr_bool: expr_float ">" expr_float
#line 757 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 3282 "frontend/parser.cpp"
    break;

  case 406: // expr_bool: expr_float ">" expr_int
#line 758 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 3288 "frontend/parser.cpp"
    break;

  case 407: // expr_bool: expr_str ">" expr_str
#line 759 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 3294 "frontend/parser.cpp"
    break;

  case 408: // expr_bool: expr_int "<" expr_int
#line 761 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 3300 "frontend/parser.cpp"
    break;

  case 409: // expr_bool: expr_int "<" expr_float
#line 762 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 3306 "frontend/parser.cpp"
    break;

  case 410: // expr_bool: expr_float "<" expr_float
#line 763 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 3312 "frontend/parser.cpp"
    break;

  case 411: // expr_bool: expr_float "<" expr_int
#line 764 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 3318 "frontend/parser.cpp"
    break;

  case 412: // expr_bool: expr_str "<" expr_str
#line 765 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 3324 "frontend/parser.cpp"
    break;

  case 413: // expr_bool: expr_int ">=" expr_int
#line 767 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 3330 "frontend/parser.cpp"
    break;

  case 414: // expr_bool: expr_int ">=" expr_float
#line 768 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 3336 "frontend/parser.cpp"
    break;

  case 415: // expr_bool: expr_float ">=" expr_float
#line 769 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 3342 "frontend/parser.cpp"
    break;

  case 416: // expr_bool: expr_float ">=" expr_int
#line 770 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 3348 "frontend/parser.cpp"
    break;

  case 417: // expr_bool: expr_str ">=" expr_str
#line 771 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 3354 "frontend/parser.cpp"
    break;

  case 418: // expr_bool: expr_int "<=" expr_int
#line 773 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 3360 "frontend/parser.cpp"
    break;

  case 419: // expr_bool: expr_int "<=" expr_float
#line 774 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 3366 "frontend/parser.cpp"
    break;

  case 420: // expr_bool: expr_float "<=" expr_float
#line 775 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 3372 "frontend/parser.cpp"
    break;

  case 421: // expr_bool: expr_float "<=" expr_int
#line 776 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 3378 "frontend/parser.cpp"
    break;

  case 422: // expr_bool: expr_str "<=" expr_str
#line 777 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 3384 "frontend/parser.cpp"
    break;

  case 423: // expr_bool: expr_str "in" expr_str
#line 779 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[0].value.as < std::string > ().find(yystack_[2].value.as < std::string > ()) != std::string::npos; }
#line 3390 "frontend/parser.cpp"
    break;

  case 428: // mattype: "identifier" matsq
#line 791 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3396 "frontend/parser.cpp"
    break;

  case 429: // mattype: "'int'" matsq
#line 792 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(INT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3402 "frontend/parser.cpp"
    break;

  case 430: // mattype: "'float'" matsq
#line 793 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(FLOAT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3408 "frontend/parser.cpp"
    break;

  case 431: // mattype: "'string'" matsq
#line 794 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(STRING_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3414 "frontend/parser.cpp"
    break;

  case 432: // mattype: "'bool'" matsq
#line 795 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(BOOL_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3420 "frontend/parser.cpp"
    break;

  case 441: // matsq: "[" "]"
#line 805 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(scanner->parseInt(-1)); }
#line 3426 "frontend/parser.cpp"
    break;

  case 442: // matsq: "[" int_val "]"
#line 806 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 3432 "frontend/parser.cpp"
    break;

  case 443: // matsq: "[" "]" matsq
#line 807 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), scanner->parseInt(-1)); }
#line 3438 "frontend/parser.cpp"
    break;

  case 444: // matsq: "[" int_val "]" matsq
#line 808 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[2].value.as < ptc::ir::Expr * > ()); }
#line 3444 "frontend/parser.cpp"
    break;

  case 445: // type: "'int'" "?"
#line 812 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, true, true); }
#line 3450 "frontend/parser.cpp"
    break;

  case 446: // type: "'float'" "?"
#line 813 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, true, true); }
#line 3456 "frontend/parser.cpp"
    break;

  case 447: // type: "'string'" "?"
#line 814 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, true, true); }
#line 3462 "frontend/parser.cpp"
    break;

  case 448: // type: "'bool'" "?"
#line 815 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, true, true); }
#line 3468 "frontend/parser.cpp"
    break;

  case 449: // type: "identifier" "?"
#line 816 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[1].value.as < std::string > (), true, true); }
#line 3474 "frontend/parser.cpp"
    break;

  case 451: // type: mattype "?"
#line 818 "frontend/parser.yy"
       { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 3480 "frontend/parser.cpp"
    break;

  case 452: // type: "'int'"
#line 819 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, false, true); }
#line 3486 "frontend/parser.cpp"
    break;

  case 453: // type: "'float'"
#line 820 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, false, true); }
#line 3492 "frontend/parser.cpp"
    break;

  case 454: // type: "'string'"
#line 821 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, false, true); }
#line 3498 "frontend/parser.cpp"
    break;

  case 455: // type: "'bool'"
#line 822 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, false, true); }
#line 3504 "frontend/parser.cpp"
    break;

  case 456: // type: "any"
#line 823 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(ANY_CSTR, false, true); }
#line 3510 "frontend/parser.cpp"
    break;

  case 457: // type: "identifier"
#line 824 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[0].value.as < std::string > (), false, true); }
#line 3516 "frontend/parser.cpp"
    break;

  case 459: // type: mattype
#line 826 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 3522 "frontend/parser.cpp"
    break;


#line 3526 "frontend/parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
   Parser ::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
   Parser ::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
   Parser ::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  //  Parser ::context.
   Parser ::context::context (const  Parser & yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
   Parser ::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
   Parser ::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
   Parser ::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short  Parser ::yypact_ninf_ = -666;

  const short  Parser ::yytable_ninf_ = -458;

  const short
   Parser ::yypact_[] =
  {
    2177,  -666,  -666,  -666,  -666,  -666,  -666,  -666,  1451,    25,
      66,  1482,  1482,   -41,    40,   -17,  -666,    47,  -666,  -666,
    1482,  -666,  -666,   -16,    29,    42,    53,    65,    17,    18,
     239,   305,    98,   297,  -666,  -666,    15,    15,  -666,  -666,
    -666,   114,  -666,  2439,  -666,   136,  -666,  -666,    15,    15,
      15,   285,  2609,  -666,   738,   107,   566,  2858,  2950,   884,
     934,    78,    73,     1,   170,   370,  1249,   246,   738,   107,
     566,  2404,  2139,  1113,  1005,  1482,  -666,   370,  -666,   132,
     519,   519,   560,  -666,  -666,  -666,  -666,   240,  2858,  2950,
     884,  -666,   240,  -666,   934,   197,   664,  -666,   217,  -666,
     906,  -666,   315,    40,  -666,    40,  -666,    40,  -666,    40,
    -666,   296,  -666,   302,   478,    -1,  1482,    40,  -666,  -666,
    -666,   797,  1482,  -666,  -666,  -666,  2593,  -666,  -666,  -666,
    -666,  -666,  1482,   304,  2518,  -666,  -666,   262,  1482,  -666,
    -666,  -666,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,
    1482,  1482,  1482,  1482,  1482,  -666,   877,   797,  1482,  1482,
    1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,
    1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,
    -666,   797,  1482,  1482,  1482,  1482,  1482,  1482,  -666,  1482,
    1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,
    1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,
    1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,
    1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,
    1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,
    1482,  1482,  1482,  1482,  1482,    40,  -666,  -666,   508,   238,
     329,  -666,   797,   332,  -666,  -666,  -666,  -666,  -666,  -666,
     243,   337,  -666,    39,  1663,  1198,   560,   560,  -666,   519,
     519,   519,   519,   519,   519,   560,   560,   560,   560,   560,
     519,   519,   519,   519,   519,   519,  1482,    40,  2609,   363,
    2858,   -17,    51,   335,   344,     7,  1482,  -666,  -666,  -666,
    -666,   404,    55,   308,   505,   241,  -666,   412,   479,   125,
    -666,   248,   125,  -666,   486,  2593,  -666,  2254,   495,   496,
    -666,  2242,  -666,  -666,  -666,  -666,  -666,  -666,  -666,  -666,
    -666,  -666,  -666,  -666,  -666,    12,  -666,   269,   275,   237,
     719,   805,   275,   237,   719,   805,   109,   494,   488,   500,
     109,   488,   500,   109,   488,   500,   109,   488,   500,  2662,
     105,   507,  2881,  2078,   826,   787,  2720,   535,  2691,   633,
    2749,   878,  2778,  1808,  1861,  2904,  2048,  2927,   825,  1086,
     825,  1086,  2807,   526,  -666,  -666,  2961,  1976,   464,  -666,
    2807,   526,  -666,  -666,  2961,  1976,   464,  -666,   605,  1292,
    1150,   504,   605,  1292,  1150,   504,   605,  1292,  1150,   504,
     605,  1292,  1150,   504,   125,   300,   275,   237,   275,   237,
     109,   494,  2749,   615,  2807,   526,  2807,   526,  2662,   105,
     507,  2881,  2078,   826,   787,  2749,   615,  2807,  -666,  2807,
    -666,  2662,   105,   507,  2881,  2078,   826,   787,  2749,   615,
    2807,  -666,  2807,  -666,   275,   719,   805,   275,   719,   805,
     109,   488,   500,   109,   488,   500,   109,   488,   500,   109,
     500,  2662,   105,   507,  2881,  2078,   826,   787,  2749,   615,
    2778,  1808,  1861,  2904,  2048,  2927,   825,  1086,   825,  1086,
    2807,  2961,  1976,  2807,  2961,  1976,   605,  1292,  1150,   605,
    1292,  1150,   605,  1292,  1150,   605,  1292,  1150,   275,   719,
     805,   275,   719,   805,   109,   488,   500,   109,   488,   500,
     109,   488,   500,   109,   488,   500,  2662,   105,   507,  2881,
    2078,   826,   787,  2749,   615,  2807,  2961,  1976,  2807,  2961,
    1976,   605,  1292,  1150,   605,  1292,  1150,   605,  1292,  1150,
     605,  1292,  1150,   510,  2662,   105,   507,  2881,  2078,   826,
     787,  2749,   615,   878,  2807,   464,  2807,   464,   605,   504,
     605,   504,   605,   504,   605,   504,  2662,   105,   507,  2881,
    2078,   826,   787,  2720,   535,  2691,   633,  2749,   615,  2807,
    -666,  2807,  -666,  -666,  -666,    79,   516,    82,  1084,   487,
     307,  -666,   518,  -666,  -666,  1482,  -666,  1376,  -666,   560,
     560,   560,   560,   560,  1122,  1204,  1122,  1204,   511,   527,
     511,   527,   511,   527,  1721,   527,   461,  1778,  1888,  1016,
    1016,  1122,  1204,  1122,  1204,   511,   527,   511,   527,   511,
     527,   511,   527,  -666,  -666,    40,  -666,  1525,  1525,  1525,
    -666,  -666,     9,     9,  -666,   460,   552,   548,     8,   369,
     498,   530,   561,    10,  -666,  1170,   311,    28,   753,   541,
    -666,  -666,  2439,  2332,   569,  1482,  2439,  -666,  1482,  -666,
    -666,  -666,  -666,  1134,  -666,  -666,   369,   575,  -666,  -666,
    -666,   600,   600,  -666,  -666,  -666,  -666,  1558,   580,  1690,
     582,   282,  2835,   583,   585,   587,   590,   596,  -666,   573,
    -666,     9,   591,  -666,  -666,   537,   369,  -666,  -666,   599,
    -666,  1228,  -666,  1358,   462,  1482,  -666,   624,  -666,   619,
     574,  -666,  -666,  -666,   369,  1249,   628,  2404,  2439,  2439,
    1482,  1482,  2439,  2439,  2439,  2439,  -666,  1482,  -666,  1482,
     567,    11,  -666,  -666,  -666,   630,  -666,   637,  -666,  1408,
     611,  -666,  -666,  -666,  -666,  2439,  -666,  -666,  -666,  -666,
    -666,  -666,  -666,   621,  -666,  -666,  -666,  -666,  -666,  -666,
    -666,  -666,  -666,  -666,  -666,   641,   623,  -666,  1482,  -666,
    -666,  -666
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     9,   322,   336,   357,   384,   314,     0,     0,
       0,     0,     0,     0,   456,     0,    53,     0,    47,    49,
      38,    35,    36,     0,   452,   453,   454,   455,     0,     0,
     104,   105,     0,     0,     4,    10,     0,     0,    37,    15,
      17,     0,    18,     0,    16,     0,    19,    20,     0,     0,
       0,     0,    97,   295,    96,    98,    99,   100,   101,   102,
     103,   458,   459,     0,   314,   104,     0,   295,     0,     0,
       0,     0,     0,     0,     0,     0,   287,   104,   292,     0,
       0,     0,     0,   106,   107,   323,   337,   261,     0,     0,
       0,   386,   262,   325,     0,     0,     0,   433,    33,    32,
       0,    39,     0,   445,   429,   446,   430,   447,   431,   448,
     432,     0,    69,     0,     0,     0,     0,   449,   117,   316,
     428,     0,     0,   118,     1,     3,     0,     5,     8,     7,
      14,    21,     0,     0,     0,    30,    31,     0,     0,    12,
      13,    11,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,   116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   450,   434,   451,     0,    75,
       0,   315,     0,   316,   108,   296,   324,   338,   358,   385,
       0,     0,   288,     0,     0,     0,     0,     0,   325,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   441,   301,     0,
     300,     0,   457,     0,     0,     0,     0,   436,   437,   438,
     439,     0,     0,     0,     0,     0,   318,     0,     0,   120,
     435,     0,   121,     6,     0,     0,    23,     0,     0,     0,
      93,    92,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,   109,     0,    94,     0,   153,   151,
     148,   149,   161,   159,   156,   157,   135,   134,   130,   131,
     140,   138,   139,   145,   143,   144,   125,   127,   124,   286,
     284,   285,   280,   281,   282,   283,   257,   256,   260,   259,
     254,   253,   232,   231,   238,   237,   235,   234,   164,   163,
     167,   166,   212,   210,   207,   208,   203,   204,   205,   206,
     229,   227,   224,   225,   220,   221,   222,   223,   174,   171,
     172,   173,   188,   185,   186,   187,   181,   178,   179,   180,
     195,   192,   193,   194,   122,     0,   152,   150,   160,   158,
     133,   132,   252,   245,   211,   209,   228,   226,   278,   383,
     267,   380,   381,   379,   382,   250,   243,   200,   395,   217,
     402,   279,   272,   273,   268,   269,   270,   271,   251,   244,
     202,   201,   219,   218,   146,   330,   356,   154,   329,   353,
     128,   326,   344,   136,   327,   347,   141,   328,   350,   126,
     341,   274,   368,   263,   365,   366,   364,   367,   246,   239,
     230,   333,   236,   335,   233,   334,   162,   331,   165,   332,
     196,   390,   391,   213,   397,   398,   168,   403,   404,   182,
     408,   409,   175,   413,   414,   189,   418,   419,   147,   355,
     354,   155,   352,   351,   129,   343,   342,   137,   346,   345,
     142,   349,   348,   123,   340,   339,   275,   373,   264,   370,
     371,   369,   372,   247,   240,   197,   393,   392,   214,   400,
     399,   169,   406,   405,   183,   411,   410,   176,   416,   415,
     190,   421,   420,     0,   276,   363,   265,   360,   361,   359,
     362,   248,   241,   423,   198,   394,   215,   401,   170,   407,
     184,   412,   177,   417,   191,   422,   277,   378,   266,   375,
     376,   374,   377,   255,   388,   258,   387,   249,   242,   199,
     389,   216,   396,   440,   425,   457,     0,   426,     0,     0,
       0,   317,     0,   289,   290,     0,   293,     0,   323,     0,
       0,     0,     0,     0,   330,   356,   329,   353,   326,   344,
     327,   347,   328,   350,     0,   341,   333,   335,   334,   331,
     332,   355,   354,   352,   351,   343,   342,   346,   345,   349,
     348,   340,   339,    79,   443,   442,    34,     0,     0,     0,
      75,    78,     0,    58,    55,     0,     0,     0,     0,     0,
       0,    74,     0,     0,   302,     0,     0,   113,     0,     0,
     319,   114,     0,     0,    24,     0,     0,   110,     0,   115,
     112,   111,   424,     0,    77,    76,     0,     0,   113,   291,
     294,   330,   329,   326,   327,   328,   444,     0,     0,   301,
       0,     0,   300,     0,     0,     0,     0,     0,    59,     0,
      56,    60,    62,    67,    72,     0,     0,    70,   306,     0,
     304,     0,   303,     0,     0,     0,    46,    25,    26,     0,
      52,    95,   427,    65,     0,   301,     0,   300,     0,     0,
       0,     0,     0,     0,     0,     0,    57,     0,    61,     0,
       0,     0,    68,   309,   308,     0,   307,     0,   305,     0,
     320,    27,    48,    54,    50,     0,    66,   297,    28,    29,
      41,    44,   298,     0,    42,    45,    40,    43,    64,    63,
      73,    71,   312,   311,   310,     0,     0,    51,     0,   313,
     321,   299
  };

  const short
   Parser ::yypgoto_[] =
  {
    -666,  -666,   -77,  1033,   -27,   -20,   -22,    54,  -665,  -666,
     372,  -666,  -666,  -666,  -666,  -666,  -666,  -666,  -666,  -666,
    -666,  -666,  -666,  -644,  -666,  -666,   614,  -666,    75,   578,
    -666,   539,  -666,   791,   229,    -7,   607,  1472,  -406,   431,
    1607,  1627,  1813,   -60,  -102,    -8,   847,   553,  1187,  -666,
       3,  -666,     0,   247
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    32,    33,   130,    34,    35,   769,   770,   137,    36,
      99,    37,    38,    39,    40,    41,    42,    43,    44,   764,
      45,   765,    46,   656,   657,    47,   113,   661,   662,    48,
      49,    50,   335,    51,    52,    53,    79,    68,   700,   701,
     180,    69,    70,   119,   308,    57,    89,    90,    94,    61,
     596,    62,   120,    63
  };

  const short
   Parser ::yytable_[] =
  {
      71,    67,    85,    88,    93,   253,   127,   726,   707,   708,
     248,   730,   653,   306,    97,   128,   248,   248,   129,   248,
     248,   136,   677,   135,   104,   106,   108,   110,    75,     3,
       4,     5,     6,     7,     8,    95,     9,    76,   307,    96,
      96,    10,   605,     3,     4,     5,     6,     7,     8,    11,
       9,    96,   678,    96,    12,    10,   100,   317,   653,    98,
     102,   246,    96,    11,    96,   655,    14,   748,    12,   654,
       3,     4,   264,    85,   268,    80,    96,   249,    24,    25,
      26,    27,    81,   650,   712,   595,   717,   781,   290,    96,
      96,   248,   647,   111,   112,    82,  -442,   103,   124,   313,
     787,    77,    31,   297,  -442,   298,   290,   299,    88,   300,
     105,   655,    14,   290,    88,    77,    31,   310,   156,   117,
     157,   107,   683,   132,    24,    25,    26,    27,   189,   163,
     190,   595,   190,   109,   156,   261,   157,   191,   192,   191,
     192,   247,    83,    84,   262,   138,   245,   117,   179,   290,
     340,   344,   348,   351,   354,   357,   362,    88,    88,    88,
     373,   375,   377,   379,   381,   386,   394,   399,   403,   407,
     411,    88,   263,   290,    88,    88,    88,    88,    88,    88,
     251,   431,    88,    88,    88,   444,    88,    88,    88,   455,
     458,   461,   464,   467,    88,   474,    88,   481,   483,   485,
     487,   489,   491,   494,   497,   500,   503,   506,   509,   512,
     515,   518,   521,   524,   529,    88,   536,   539,   542,   545,
     548,   551,   290,   557,    88,    88,    88,    88,    88,    88,
      88,   579,    88,    88,    88,    88,    88,    66,   673,   286,
      87,    92,   704,   706,   290,   593,   602,   -69,   181,   156,
     114,   157,   115,   667,   184,   603,   255,   291,   607,   608,
     671,   614,   616,   618,   620,   622,   624,   626,   627,   628,
     629,   630,   631,   633,   635,   637,   639,   641,   116,   179,
     598,   679,   668,   263,   156,   128,   157,   644,   129,   668,
     127,   736,   160,   161,   162,   163,   290,   125,   126,   301,
       2,     3,     4,     5,     6,     7,     8,   117,     9,   302,
     668,   303,   680,    10,   179,  -457,   121,   315,   659,   688,
     740,    11,   741,   720,   318,   288,    12,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   599,   153,
     154,   668,   601,   288,   122,   309,   660,   295,   668,   604,
     288,   312,   721,    13,    14,    15,    16,   296,    17,    18,
      19,    20,    21,    22,    23,    14,    24,    25,    26,    27,
      28,    29,   133,    30,    31,   645,   648,    24,    25,    26,
      27,   252,   134,   115,   595,   649,   288,   338,   342,   346,
     350,   353,   356,   359,   366,   368,   370,   372,   374,   376,
     378,   380,   382,   390,   398,   402,   406,   410,   414,   116,
     288,   416,   418,   420,   422,   424,   426,   652,   428,   435,
     437,   439,   441,   448,   450,   452,   454,   457,   460,   463,
     466,   469,   471,   478,   480,   482,   484,   486,   488,   490,
     493,   496,   499,   502,   505,   508,   511,   514,   517,   520,
     523,   526,   533,   535,   538,   541,   544,   547,   550,   288,
     554,   561,   564,   566,   568,   570,   572,   574,   576,   583,
     585,   587,   589,   591,   758,   230,   609,   610,   611,   612,
     613,   288,     3,     4,     5,     6,     7,     8,   669,     9,
     287,   278,   279,   670,    10,   597,   672,   686,   235,   236,
     237,   238,    11,   759,   675,   181,   676,    12,   202,     3,
       4,     5,     6,     7,     8,   230,     9,   664,   594,   304,
     221,    10,   681,     3,     4,   660,   682,   289,    80,    11,
     689,   274,   194,   288,    12,    81,   709,   181,   685,   195,
     196,   182,   183,   184,    14,   305,   665,   285,    82,   658,
     663,   711,   311,    59,    77,    31,    24,    25,    26,    27,
     242,    73,    59,   595,     3,    14,   710,   243,   244,   266,
     715,   716,   728,    59,   714,   750,   267,    24,    25,    26,
      27,    77,    31,   725,   595,   734,    59,   193,   337,    82,
     738,   194,   739,   742,    14,   743,    59,   744,   195,   196,
     745,   691,   692,   693,   694,   695,    24,    25,    26,    27,
     746,   753,   415,   595,   156,   747,   157,   611,   612,   613,
     158,   159,   160,   161,   162,   163,   181,   761,    59,   762,
     182,   183,   184,   749,   763,   171,   172,   713,   767,   702,
     702,   702,   782,   780,   179,   696,   127,   186,   187,   783,
     136,   786,   135,   789,   136,   240,   135,   290,   242,   788,
     290,   553,   307,   646,   733,   243,   244,   696,     3,     4,
       5,     6,     7,     8,   687,     9,   287,   250,   294,    59,
      10,   320,   260,   600,   790,    59,   732,    59,    11,   737,
      67,    59,     0,    12,   752,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,     0,    59,
       0,     0,   766,   290,     0,   290,     0,   364,   768,   768,
     371,     0,   768,   768,   768,   768,   388,   396,   401,   405,
     409,   413,   290,   290,     0,   666,   199,   200,   201,   202,
      77,    31,   433,   136,     0,   135,   446,     0,     0,   181,
       0,   290,     0,   182,   183,   184,   476,     3,     4,     5,
       6,     7,     8,   185,     9,   722,     0,     0,     0,    10,
     186,   187,     0,     0,     0,   531,     0,    11,     0,     0,
     290,     0,    12,     0,   559,   563,   565,   567,   569,   571,
     573,   575,   581,   771,   723,     0,   774,   775,   776,   777,
      78,     3,     4,     5,     6,     7,     8,     0,     9,   240,
     241,   101,   242,    10,     0,     0,    59,     0,     0,   243,
     244,    11,   218,   219,   220,   221,    12,     0,     0,    77,
      31,     0,     0,     0,   156,     0,   157,   230,   304,    59,
     158,   159,   160,   161,   162,   163,   663,    58,     0,    59,
       0,   232,     0,     0,     0,    72,    58,    86,   233,   234,
     235,   236,   237,   238,   179,     0,    78,    58,    59,     0,
      59,     0,     0,    77,    31,     0,   699,   699,   699,     0,
      58,     3,     4,     5,     6,     7,     8,   334,     9,   230,
      58,     0,     0,    10,   288,   230,     0,   288,     0,   658,
     658,    11,     0,     0,     0,   231,    12,     0,     0,   232,
     233,   234,   235,   236,   237,   238,   233,   234,   235,   236,
     237,   238,    58,   314,     0,     0,   735,   265,    86,   319,
     597,     0,     0,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,     0,   336,     0,     0,
     288,     0,   288,    77,    31,   239,   240,   241,   658,   242,
       0,     0,   751,    14,     0,     0,   243,   244,     0,   288,
     288,     0,     0,    58,     0,    24,    25,    26,    27,    58,
       0,    58,   292,   293,     0,    58,     0,     0,   288,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,     0,    58,     0,   341,   345,   349,   352,   355,
     358,   363,     0,     0,     0,   259,     0,   288,     0,     0,
     387,   395,   400,   404,   408,   412,   239,   240,   241,     0,
     242,   609,   610,   611,   612,   613,   432,   243,   244,     0,
     445,     0,     0,     0,   456,   459,   462,   465,   468,   470,
     475,     0,     0,     0,   606,     0,     0,   492,   495,   498,
     501,   504,   507,   510,   513,   516,   519,   522,   525,   530,
     131,   537,   540,   543,   546,   549,   552,   643,   558,     0,
       0,   139,   140,   141,   155,     0,   580,   651,     3,     4,
       5,     6,     7,     8,     0,     9,   719,   115,     0,   724,
      10,   197,   198,   199,   200,   201,   202,     0,    11,     0,
      58,     0,     0,    12,     0,     0,   615,   617,   619,   621,
     623,   625,     0,   258,   230,     0,     0,   632,   634,   636,
     638,   640,   642,    58,   231,     0,     0,     0,   232,   271,
     272,   273,   274,    58,     0,   233,   234,   235,   236,   237,
     238,    59,   755,     0,   757,     0,     0,     0,    59,     0,
      77,    31,    58,     0,    58,   216,   217,   218,   219,   220,
     221,   772,   773,     0,     3,     4,     5,     6,     7,     8,
       0,     9,   718,     0,     0,     0,    10,    60,     0,     0,
     785,    14,     0,     0,    11,    74,    60,     0,    91,    12,
      59,    59,    59,    24,    25,    26,    27,    60,   257,     0,
     595,     0,     0,   280,   281,   282,   283,   284,   285,   791,
      60,   282,   283,   284,   285,    59,    59,     0,    59,    59,
      60,    59,     3,     4,     5,     6,     7,     8,     0,     9,
     754,     0,     0,     0,    10,     0,    77,    31,     0,     0,
      73,     0,    11,     0,     0,     0,     0,    12,   156,   254,
     157,     0,    60,     0,   158,   159,   160,   161,   162,   163,
     164,   165,   166,     0,   167,   168,   169,   170,    59,   171,
     172,   173,   174,   175,   176,   177,   178,     0,   179,     0,
       0,    59,    59,     0,     0,    59,    59,    59,    59,     0,
      59,     0,    59,     0,    77,    31,     0,   197,   198,   199,
     200,   201,   202,    60,     0,     0,     0,     0,    59,    60,
       0,    60,   208,   209,     0,    60,     0,     0,     0,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,     0,    60,     0,     0,     0,     0,     0,     0,
       0,   365,   367,   369,     0,     0,     0,     0,     0,     0,
     389,   397,     3,     4,     5,     6,     7,     8,     0,     9,
     756,     0,     0,     0,    10,     0,   434,     0,     0,     0,
     447,     0,    11,     0,     0,     0,   256,    12,     0,   684,
     477,   609,   610,   611,   612,   613,   690,     0,     0,     0,
       0,     0,   275,   276,   277,     0,   278,   279,     0,   532,
       0,     0,     3,     4,     5,     6,     7,     8,   560,     9,
     784,     0,     0,     0,    10,     0,   582,   584,   586,     0,
     590,   592,    11,     0,    77,    31,     0,    12,   698,   703,
     705,     0,     0,     0,     0,    58,     0,     0,     0,     0,
      60,     0,    58,     0,     0,     3,     4,     5,     6,    64,
       8,     0,     9,     0,     0,     0,   729,    10,     0,   731,
       0,     0,    54,    60,     0,    11,     0,     0,     0,     0,
      12,    54,     0,    60,    77,    31,     3,     4,     5,     6,
       7,     8,    54,     9,    58,    58,    58,     0,    10,     0,
       0,     0,    60,     0,    60,    54,    11,     0,     0,     0,
       0,    12,     0,     0,     0,    54,   760,     0,     0,    58,
      58,     0,    58,    58,     0,    58,     0,    65,    31,     3,
       4,     5,     6,     7,   697,     0,     9,     0,   778,     0,
     779,    10,     0,     0,    72,     0,     0,    54,     0,    11,
       0,     0,     0,     0,    12,     0,     0,     0,    77,    31,
       0,     0,     3,     4,     5,     6,    64,   697,     0,     9,
       0,     0,    58,     0,    10,     0,     0,     0,     0,     0,
       0,     0,    11,     0,     0,    58,    58,    12,     0,    58,
      58,    58,    58,     0,    58,     0,    58,     0,    54,     0,
       0,    77,    31,     0,    54,     0,    54,     0,     0,     0,
      54,     0,    58,     0,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    55,    54,     0,
     339,   343,   347,     0,    65,    31,    55,   118,   123,     0,
       0,     0,     0,     0,     0,   383,   391,    55,     0,     0,
       0,     0,     0,     0,   417,   419,   421,   423,   425,   427,
      55,   188,   436,     0,     0,     0,   449,     0,     0,     0,
      55,     0,   118,   256,     0,   188,   479,     0,   269,   270,
     271,   272,   273,   274,   118,     0,     0,     0,     0,   275,
     276,   277,     0,   278,   279,   534,     0,     0,     0,   156,
     -97,   157,    55,     0,   562,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   588,   167,   168,   169,   170,     0,
     171,   172,   173,   174,   175,   176,   177,   178,     0,   179,
       0,     0,     0,     0,     0,    54,   269,   270,   271,   272,
     273,   274,     0,     0,     0,     0,     0,   275,   276,   277,
       0,   278,   279,    55,     0,     0,     0,     0,    54,    55,
       0,    55,     0,     0,     0,    55,     0,     0,    54,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,     0,    55,     0,    60,     0,    54,     0,    54,
       0,   360,    60,   609,   610,   611,   612,   613,     0,     0,
     384,   392,     0,     0,   275,     0,   277,     0,   278,   279,
       0,     0,     0,    56,     0,     0,   429,     0,   438,   440,
     442,     0,    56,   197,   198,   199,   200,   201,   202,     0,
     472,     0,     0,    56,    60,    60,    60,     0,   208,   209,
     210,   211,   212,   213,   214,   215,    56,     0,     0,   527,
       0,     0,     0,     0,     0,     0,    56,     0,   555,    60,
      60,     0,    60,    60,     0,    60,   577,     0,     0,     0,
     156,     0,   157,     0,     0,     0,   158,   159,   160,   161,
     162,   163,     0,     0,    74,     0,     0,   168,    56,   170,
      55,   171,   172,   173,   174,   175,   176,   177,   178,     0,
     179,     0,     0,   609,   610,   611,   612,   613,     0,     0,
       0,     0,    60,    55,   275,     0,     0,     0,   278,   279,
       0,     0,     0,    55,     0,    60,    60,     0,     0,    60,
      60,    60,    60,     0,    60,     0,    60,     0,     0,    56,
       0,     0,    55,     0,    55,    56,   188,    56,     0,     0,
     188,    56,    60,     0,   188,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,     0,    56,
       0,     0,     0,     0,     0,     0,     0,   361,     0,     0,
       0,     0,     0,     0,     0,     0,   385,   393,     0,     0,
     188,   216,   217,   218,   219,   220,   221,     0,   188,     0,
       0,     0,   430,     0,     0,     0,   443,     0,   451,   453,
     226,   227,   228,   229,     0,     0,   473,     0,     0,     0,
       0,     0,     0,     0,   188,     0,   188,     0,   188,     0,
     188,     0,   188,     0,   188,   528,     0,     0,     0,     0,
       0,     0,     0,   188,   556,     0,     0,     0,     0,     0,
       0,     0,   578,     0,     0,     0,   188,   156,     0,   157,
       0,     0,     0,   158,   159,   160,   161,   162,   163,     0,
      54,     0,     0,     0,   168,     0,    56,    54,   171,   172,
     173,   174,   175,   176,   177,   178,   188,   179,     0,     0,
       0,     0,     0,   216,   217,   218,   219,   220,   221,    56,
       0,     0,     0,   223,     0,     0,     0,     0,     0,    56,
     224,   225,   226,   227,   228,   229,     0,     0,     0,    54,
      54,    54,     0,     0,     0,     0,     0,     0,    56,     0,
      56,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   188,     0,     0,    54,    54,     0,    54,    54,   257,
      54,     0,     0,     0,   216,   217,   218,   219,   220,   221,
     222,     0,     0,     0,   223,     0,     0,     0,     0,   188,
       0,   224,   225,   226,   227,   228,   229,     1,     0,     0,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,     0,     0,    10,     0,   188,     0,    54,     0,     0,
       0,    11,     0,     0,     0,     0,    12,     0,     0,     0,
      54,    54,     0,     0,    54,    54,    54,    54,     0,    54,
       0,    54,     0,     0,     0,    55,     0,     0,     0,     0,
       0,     0,    55,    13,    14,    15,    16,    54,    17,    18,
      19,    20,    21,    22,    23,     0,    24,    25,    26,    27,
      28,    29,     0,    30,    31,   126,     0,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,   674,     0,
      10,     0,     0,     0,    55,    55,    55,     0,    11,     0,
       0,     0,     0,    12,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,     0,   153,   154,     0,    55,
      55,     0,    55,    55,     0,    55,     0,     0,     0,     0,
      13,    14,    15,    16,     0,    17,    18,    19,    20,    21,
      22,    23,     0,    24,    25,    26,    27,    28,    29,     0,
      30,    31,     0,   126,     0,     2,     3,     4,     5,     6,
       7,     8,     0,     9,     0,     0,   727,     0,    10,     0,
       0,     0,    55,     0,     0,     0,    11,     0,     0,     0,
       0,    12,     0,     0,     0,    55,    55,     0,     0,    55,
      55,    55,    55,     0,    55,     0,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,    14,
      15,    16,    55,    17,    18,    19,    20,    21,    22,    23,
       0,    24,    25,    26,    27,    28,    29,     0,    30,    31,
       0,    56,     0,     0,   256,     0,     0,     0,    56,   197,
     198,   199,   200,   201,   202,   203,     0,     0,     0,   204,
     205,   206,   207,     0,   208,   209,   210,   211,   212,   213,
     214,   215,   133,     3,     4,     5,     6,     7,     8,     0,
       9,     0,   134,     0,     0,    10,     0,     0,     0,     0,
      56,    56,    56,    11,     0,     0,     0,     0,    12,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    56,    56,     0,    56,    56,
       0,    56,     0,     0,     0,    13,    14,    15,    16,     0,
      17,    18,    19,    20,    21,    22,    23,     0,    24,    25,
      26,    27,    28,    29,     0,    30,    31,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,   316,     0,    10,     0,     0,     0,    56,     0,
       0,     0,    11,     0,     0,     0,     0,    12,     0,     0,
       0,    56,    56,     0,     0,    56,    56,    56,    56,     0,
      56,     0,    56,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,    14,    15,    16,    56,    17,
      18,    19,    20,    21,    22,    23,     0,    24,    25,    26,
      27,    28,    29,     0,    30,    31,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,     0,    10,
       0,     0,     0,     0,     0,     0,     0,    11,   156,     0,
     157,     0,    12,     0,   158,   159,   160,   161,   162,   163,
     164,   165,   166,     0,   167,   168,   169,   170,     0,   171,
     172,   173,   174,   175,   176,   177,   178,     0,   179,    13,
      14,    15,    16,     0,    17,    18,    19,    20,    21,    22,
      23,     0,    24,    25,    26,    27,    28,    29,     0,    30,
      31,   156,     0,   157,     0,     0,     0,   158,   159,   160,
     161,   162,   163,     0,   165,   166,     0,   167,   168,   169,
     170,     0,   171,   172,   173,   174,   175,   176,   177,   178,
     156,   179,   157,     0,     0,     0,   158,   159,   160,   161,
     162,   163,     0,   165,     0,     0,   167,   168,   169,   170,
       0,   171,   172,   173,   174,   175,   176,   177,   178,   156,
     179,   157,     0,     0,     0,   158,   159,   160,   161,   162,
     163,     0,     0,     0,     0,   167,   168,   169,   170,     0,
     171,   172,   173,   174,   175,   176,   177,   178,   156,   179,
     157,     0,     0,     0,   158,   159,   160,   161,   162,   163,
       0,     0,     0,     0,     0,   168,   169,   170,     0,   171,
     172,   173,   174,   175,   176,   177,   178,   156,   179,   157,
       0,     0,     0,   158,   159,   160,   161,   162,   163,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   171,   172,
     173,   174,   175,   176,   177,   178,   156,   179,   157,     0,
       0,     0,   158,   159,   160,   161,   162,   163,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   171,   172,     0,
       0,   175,   176,   177,   178,  -100,   179,     0,     0,     0,
     197,   198,   199,   200,   201,   202,   203,     0,     0,     0,
     204,   205,   206,   207,     0,   208,   209,   210,   211,   212,
     213,   214,   215,   197,   198,   199,   200,   201,   202,   203,
       0,     0,     0,   204,   205,   206,   207,     0,   208,   209,
     210,   211,   212,   213,   214,   215,   197,   198,   199,   200,
     201,   202,     0,     0,     0,     0,   204,   205,   206,   207,
       0,   208,   209,   210,   211,   212,   213,   214,   215,   197,
     198,   199,   200,   201,   202,     0,     0,     0,     0,     0,
     205,     0,   207,     0,   208,   209,   210,   211,   212,   213,
     214,   215,   197,   198,   199,   200,   201,   202,     0,     0,
       0,     0,     0,   205,     0,     0,     0,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,     0,     0,     0,   223,   197,   198,   199,   200,
     201,   202,   224,   225,   226,   227,   228,   229,     0,     0,
       0,   208,   209,     0,     0,   212,   213,   214,   215
  };

  const short
   Parser ::yycheck_[] =
  {
       8,     8,    10,    11,    12,    65,    33,   672,   652,   653,
       9,   676,     3,    14,    14,     0,     9,     9,     3,     9,
       9,    43,    10,    43,    24,    25,    26,    27,     3,     4,
       5,     6,     7,     8,     9,    76,    11,    12,    39,    11,
      11,    16,     3,     4,     5,     6,     7,     8,     9,    24,
      11,    11,    40,    11,    29,    16,     9,   134,     3,    76,
      76,    61,    11,    24,    11,    56,    57,   711,    29,    14,
       4,     5,    80,    81,    82,     9,    11,    76,    69,    70,
      71,    72,    16,    76,    76,    76,    76,    76,    96,    11,
      11,     9,    41,    76,    76,    29,    68,    68,     0,   126,
     765,    76,    77,   103,    76,   105,   114,   107,   116,   109,
      68,    56,    57,   121,   122,    76,    77,   117,     9,    68,
      11,    68,    40,     9,    69,    70,    71,    72,    21,    20,
      25,    76,    25,    68,     9,     3,    11,    32,    33,    32,
      33,    68,    76,    77,    12,     9,    68,    68,    39,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,    40,   181,   182,   183,   184,   185,   186,   187,
      10,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,     8,   315,    42,
      11,    12,   648,   649,   252,   245,     3,     9,    11,     9,
      11,    11,    13,    12,    17,    12,    10,    40,   266,   267,
      12,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,    39,    39,
      42,    12,    41,    40,     9,     0,    11,   287,     3,    41,
     317,   697,    17,    18,    19,    20,   304,     0,     1,     3,
       3,     4,     5,     6,     7,     8,     9,    68,    11,    13,
      41,     9,    12,    16,    39,    76,    11,    13,    10,    12,
      38,    24,    40,    12,    62,    96,    29,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,     9,    54,
      55,    41,    10,   114,    39,   116,    38,   100,    41,    12,
     121,   122,    41,    56,    57,    58,    59,    42,    61,    62,
      63,    64,    65,    66,    67,    57,    69,    70,    71,    72,
      73,    74,     3,    76,    77,    12,    41,    69,    70,    71,
      72,    11,    13,    13,    76,    41,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,    39,
     181,   182,   183,   184,   185,   186,   187,    13,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,    12,    11,    15,    16,    17,    18,
      19,   252,     4,     5,     6,     7,     8,     9,    76,    11,
      12,    30,    31,    14,    16,   248,    10,    10,    34,    35,
      36,    37,    24,    41,     9,    11,    10,    29,    20,     4,
       5,     6,     7,     8,     9,    11,    11,    12,    10,    41,
      20,    16,    12,     4,     5,    38,    10,    96,     9,    24,
      12,    20,    25,   304,    29,    16,    76,    11,   598,    32,
      33,    15,    16,    17,    57,   114,    41,    20,    29,   302,
     303,     3,   121,     0,    76,    77,    69,    70,    71,    72,
      25,     8,     9,    76,     4,    57,    14,    32,    33,     9,
      40,    10,     3,    20,    76,    38,    16,    69,    70,    71,
      72,    76,    77,    42,    76,    10,    33,    21,   157,    29,
      10,    25,    10,    10,    57,    10,    43,    10,    32,    33,
      10,   609,   610,   611,   612,   613,    69,    70,    71,    72,
      14,    12,   181,    76,     9,    42,    11,    17,    18,    19,
      15,    16,    17,    18,    19,    20,    11,     3,    75,    10,
      15,    16,    17,    42,    60,    30,    31,   659,    10,   647,
     648,   649,    12,    76,    39,   645,   673,    32,    33,    12,
     672,    40,   672,    12,   676,    22,   676,   665,    25,    38,
     668,   230,    39,   291,   686,    32,    33,   667,     4,     5,
       6,     7,     8,     9,   599,    11,    12,    63,   100,   126,
      16,   142,    75,   252,   786,   132,   683,   134,    24,   697,
     697,   138,    -1,    29,   716,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,   156,
      -1,    -1,   734,   721,    -1,   723,    -1,   164,   738,   739,
     167,    -1,   742,   743,   744,   745,   173,   174,   175,   176,
     177,   178,   740,   741,    -1,   304,    17,    18,    19,    20,
      76,    77,   189,   765,    -1,   765,   193,    -1,    -1,    11,
      -1,   759,    -1,    15,    16,    17,   203,     4,     5,     6,
       7,     8,     9,    25,    11,    12,    -1,    -1,    -1,    16,
      32,    33,    -1,    -1,    -1,   222,    -1,    24,    -1,    -1,
     788,    -1,    29,    -1,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   739,    41,    -1,   742,   743,   744,   745,
       9,     4,     5,     6,     7,     8,     9,    -1,    11,    22,
      23,    20,    25,    16,    -1,    -1,   263,    -1,    -1,    32,
      33,    24,    17,    18,    19,    20,    29,    -1,    -1,    76,
      77,    -1,    -1,    -1,     9,    -1,    11,    11,    41,   286,
      15,    16,    17,    18,    19,    20,   599,     0,    -1,   296,
      -1,    25,    -1,    -1,    -1,     8,     9,    10,    32,    33,
      34,    35,    36,    37,    39,    -1,    75,    20,   315,    -1,
     317,    -1,    -1,    76,    77,    -1,   647,   648,   649,    -1,
      33,     4,     5,     6,     7,     8,     9,    10,    11,    11,
      43,    -1,    -1,    16,   665,    11,    -1,   668,    -1,   652,
     653,    24,    -1,    -1,    -1,    21,    29,    -1,    -1,    25,
      32,    33,    34,    35,    36,    37,    32,    33,    34,    35,
      36,    37,    75,   132,    -1,    -1,   697,    80,    81,   138,
     683,    -1,    -1,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,   156,    -1,    -1,
     721,    -1,   723,    76,    77,    21,    22,    23,   711,    25,
      -1,    -1,   715,    57,    -1,    -1,    32,    33,    -1,   740,
     741,    -1,    -1,   126,    -1,    69,    70,    71,    72,   132,
      -1,   134,    76,    77,    -1,   138,    -1,    -1,   759,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,   156,    -1,   158,   159,   160,   161,   162,
     163,   164,    -1,    -1,    -1,    10,    -1,   788,    -1,    -1,
     173,   174,   175,   176,   177,   178,    21,    22,    23,    -1,
      25,    15,    16,    17,    18,    19,   189,    32,    33,    -1,
     193,    -1,    -1,    -1,   197,   198,   199,   200,   201,   202,
     203,    -1,    -1,    -1,   263,    -1,    -1,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      37,   224,   225,   226,   227,   228,   229,   286,   231,    -1,
      -1,    48,    49,    50,    51,    -1,   239,   296,     4,     5,
       6,     7,     8,     9,    -1,    11,   665,    13,    -1,   668,
      16,    15,    16,    17,    18,    19,    20,    -1,    24,    -1,
     263,    -1,    -1,    29,    -1,    -1,   269,   270,   271,   272,
     273,   274,    -1,    10,    11,    -1,    -1,   280,   281,   282,
     283,   284,   285,   286,    21,    -1,    -1,    -1,    25,    17,
      18,    19,    20,   296,    -1,    32,    33,    34,    35,    36,
      37,   598,   721,    -1,   723,    -1,    -1,    -1,   605,    -1,
      76,    77,   315,    -1,   317,    15,    16,    17,    18,    19,
      20,   740,   741,    -1,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    -1,    -1,    16,     0,    -1,    -1,
     759,    57,    -1,    -1,    24,     8,     9,    -1,    11,    29,
     647,   648,   649,    69,    70,    71,    72,    20,    10,    -1,
      76,    -1,    -1,    15,    16,    17,    18,    19,    20,   788,
      33,    17,    18,    19,    20,   672,   673,    -1,   675,   676,
      43,   678,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    -1,    -1,    16,    -1,    76,    77,    -1,    -1,
     697,    -1,    24,    -1,    -1,    -1,    -1,    29,     9,    10,
      11,    -1,    75,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,   725,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    39,    -1,
      -1,   738,   739,    -1,    -1,   742,   743,   744,   745,    -1,
     747,    -1,   749,    -1,    76,    77,    -1,    15,    16,    17,
      18,    19,    20,   126,    -1,    -1,    -1,    -1,   765,   132,
      -1,   134,    30,    31,    -1,   138,    -1,    -1,    -1,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   164,   165,   166,    -1,    -1,    -1,    -1,    -1,    -1,
     173,   174,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    -1,    -1,    16,    -1,   189,    -1,    -1,    -1,
     193,    -1,    24,    -1,    -1,    -1,    10,    29,    -1,   598,
     203,    15,    16,    17,    18,    19,   605,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    -1,    30,    31,    -1,   222,
      -1,    -1,     4,     5,     6,     7,     8,     9,   231,    11,
      12,    -1,    -1,    -1,    16,    -1,   239,   240,   241,    -1,
     243,   244,    24,    -1,    76,    77,    -1,    29,   647,   648,
     649,    -1,    -1,    -1,    -1,   598,    -1,    -1,    -1,    -1,
     263,    -1,   605,    -1,    -1,     4,     5,     6,     7,     8,
       9,    -1,    11,    -1,    -1,    -1,   675,    16,    -1,   678,
      -1,    -1,     0,   286,    -1,    24,    -1,    -1,    -1,    -1,
      29,     9,    -1,   296,    76,    77,     4,     5,     6,     7,
       8,     9,    20,    11,   647,   648,   649,    -1,    16,    -1,
      -1,    -1,   315,    -1,   317,    33,    24,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    43,   725,    -1,    -1,   672,
     673,    -1,   675,   676,    -1,   678,    -1,    76,    77,     4,
       5,     6,     7,     8,     9,    -1,    11,    -1,   747,    -1,
     749,    16,    -1,    -1,   697,    -1,    -1,    75,    -1,    24,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    76,    77,
      -1,    -1,     4,     5,     6,     7,     8,     9,    -1,    11,
      -1,    -1,   725,    -1,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,   738,   739,    29,    -1,   742,
     743,   744,   745,    -1,   747,    -1,   749,    -1,   126,    -1,
      -1,    76,    77,    -1,   132,    -1,   134,    -1,    -1,    -1,
     138,    -1,   765,    -1,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     0,   156,    -1,
     158,   159,   160,    -1,    76,    77,     9,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,   173,   174,    20,    -1,    -1,
      -1,    -1,    -1,    -1,   182,   183,   184,   185,   186,   187,
      33,    54,   190,    -1,    -1,    -1,   194,    -1,    -1,    -1,
      43,    -1,    65,    10,    -1,    68,   204,    -1,    15,    16,
      17,    18,    19,    20,    77,    -1,    -1,    -1,    -1,    26,
      27,    28,    -1,    30,    31,   223,    -1,    -1,    -1,     9,
      10,    11,    75,    -1,   232,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   242,    25,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    39,
      -1,    -1,    -1,    -1,    -1,   263,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      -1,    30,    31,   126,    -1,    -1,    -1,    -1,   286,   132,
      -1,   134,    -1,    -1,    -1,   138,    -1,    -1,   296,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,   156,    -1,   598,    -1,   315,    -1,   317,
      -1,   164,   605,    15,    16,    17,    18,    19,    -1,    -1,
     173,   174,    -1,    -1,    26,    -1,    28,    -1,    30,    31,
      -1,    -1,    -1,     0,    -1,    -1,   189,    -1,   191,   192,
     193,    -1,     9,    15,    16,    17,    18,    19,    20,    -1,
     203,    -1,    -1,    20,   647,   648,   649,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    33,    -1,    -1,   222,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,   231,   672,
     673,    -1,   675,   676,    -1,   678,   239,    -1,    -1,    -1,
       9,    -1,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    -1,    -1,   697,    -1,    -1,    26,    75,    28,
     263,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      39,    -1,    -1,    15,    16,    17,    18,    19,    -1,    -1,
      -1,    -1,   725,   286,    26,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,   296,    -1,   738,   739,    -1,    -1,   742,
     743,   744,   745,    -1,   747,    -1,   749,    -1,    -1,   126,
      -1,    -1,   315,    -1,   317,   132,   339,   134,    -1,    -1,
     343,   138,   765,    -1,   347,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,   156,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   164,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   173,   174,    -1,    -1,
     383,    15,    16,    17,    18,    19,    20,    -1,   391,    -1,
      -1,    -1,   189,    -1,    -1,    -1,   193,    -1,   195,   196,
      34,    35,    36,    37,    -1,    -1,   203,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   417,    -1,   419,    -1,   421,    -1,
     423,    -1,   425,    -1,   427,   222,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   436,   231,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   239,    -1,    -1,    -1,   449,     9,    -1,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    -1,
     598,    -1,    -1,    -1,    26,    -1,   263,   605,    30,    31,
      32,    33,    34,    35,    36,    37,   479,    39,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,   286,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,   296,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,   647,
     648,   649,    -1,    -1,    -1,    -1,    -1,    -1,   315,    -1,
     317,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   534,    -1,    -1,   672,   673,    -1,   675,   676,    10,
     678,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,   562,
      -1,    32,    33,    34,    35,    36,    37,     0,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
      -1,    -1,    -1,    16,    -1,   588,    -1,   725,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
     738,   739,    -1,    -1,   742,   743,   744,   745,    -1,   747,
      -1,   749,    -1,    -1,    -1,   598,    -1,    -1,    -1,    -1,
      -1,    -1,   605,    56,    57,    58,    59,   765,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    -1,    76,    77,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    -1,    -1,    14,    -1,
      16,    -1,    -1,    -1,   647,   648,   649,    -1,    24,    -1,
      -1,    -1,    -1,    29,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    -1,   672,
     673,    -1,   675,   676,    -1,   678,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    -1,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    -1,
      76,    77,    -1,     1,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    -1,    -1,    14,    -1,    16,    -1,
      -1,    -1,   725,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,   738,   739,    -1,    -1,   742,
     743,   744,   745,    -1,   747,    -1,   749,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,   765,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    -1,    76,    77,
      -1,   598,    -1,    -1,    10,    -1,    -1,    -1,   605,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    25,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    -1,    13,    -1,    -1,    16,    -1,    -1,    -1,    -1,
     647,   648,   649,    24,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   672,   673,    -1,   675,   676,
      -1,   678,    -1,    -1,    -1,    56,    57,    58,    59,    -1,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    -1,    76,    77,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      -1,    -1,    14,    -1,    16,    -1,    -1,    -1,   725,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,   738,   739,    -1,    -1,   742,   743,   744,   745,    -1,
     747,    -1,   749,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,   765,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    -1,    76,    77,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,     9,    -1,
      11,    -1,    29,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    39,    56,
      57,    58,    59,    -1,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    -1,    76,
      77,     9,    -1,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    -1,    22,    23,    -1,    25,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
       9,    39,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    -1,    22,    -1,    -1,    25,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,     9,
      39,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    25,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,     9,    39,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,     9,    39,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,     9,    39,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    34,    35,    36,    37,    10,    39,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      25,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    25,    26,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    25,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    25,    15,    16,    17,    18,
      19,    20,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    30,    31,    -1,    -1,    34,    35,    36,    37
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     0,     3,     4,     5,     6,     7,     8,     9,    11,
      16,    24,    29,    56,    57,    58,    59,    61,    62,    63,
      64,    65,    66,    67,    69,    70,    71,    72,    73,    74,
      76,    77,    80,    81,    83,    84,    88,    90,    91,    92,
      93,    94,    95,    96,    97,    99,   101,   104,   108,   109,
     110,   112,   113,   114,   116,   120,   121,   124,   125,   126,
     127,   128,   130,   132,     8,    76,   113,   114,   116,   120,
     121,   124,   125,   126,   127,     3,    12,    76,   112,   115,
       9,    16,    29,    76,    77,   124,   125,   113,   124,   125,
     126,   127,   113,   124,   127,    76,    11,   131,    76,    89,
       9,   112,    76,    68,   131,    68,   131,    68,   131,    68,
     131,    76,    76,   105,    11,    13,    39,    68,   119,   122,
     131,    11,    39,   119,     0,     0,     1,    83,     0,     3,
      82,    82,     9,     3,    13,    84,    85,    87,     9,    82,
      82,    82,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    54,    55,    82,     9,    11,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    25,    26,    27,
      28,    30,    31,    32,    33,    34,    35,    36,    37,    39,
     119,    11,    15,    16,    17,    25,    32,    33,   119,    21,
      25,    32,    33,    21,    25,    32,    33,    15,    16,    17,
      18,    19,    20,    21,    25,    26,    27,    28,    30,    31,
      32,    33,    34,    35,    36,    37,    15,    16,    17,    18,
      19,    20,    21,    25,    32,    33,    34,    35,    36,    37,
      11,    21,    25,    32,    33,    34,    35,    36,    37,    21,
      22,    23,    25,    32,    33,    68,   131,    68,     9,    76,
     105,    10,    11,   122,    10,    10,    10,    10,    10,    10,
     115,     3,    12,    40,   124,   125,     9,    16,   124,    15,
      16,    17,    18,    19,    20,    26,    27,    28,    30,    31,
      15,    16,    17,    18,    19,    20,    42,    12,   113,   118,
     124,    40,    76,    77,   108,   132,    42,   131,   131,   131,
     131,     3,    13,     9,    41,   118,    14,    39,   123,   113,
     131,   118,   113,    83,   112,    13,    14,    81,    62,   112,
     110,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,    10,   111,   112,   118,   113,   116,
     124,   125,   113,   116,   124,   125,   113,   116,   124,   125,
     113,   124,   125,   113,   124,   125,   113,   124,   125,   113,
     120,   121,   124,   125,   126,   127,   113,   127,   113,   127,
     113,   126,   113,   124,   113,   124,   113,   124,   113,   124,
     113,   124,   113,   116,   120,   121,   124,   125,   126,   127,
     113,   116,   120,   121,   124,   125,   126,   127,   113,   124,
     125,   126,   113,   124,   125,   126,   113,   124,   125,   126,
     113,   124,   125,   126,   113,   118,   113,   116,   113,   116,
     113,   116,   113,   116,   113,   116,   113,   116,   113,   120,
     121,   124,   125,   126,   127,   113,   116,   113,   120,   113,
     120,   113,   120,   121,   124,   125,   126,   127,   113,   116,
     113,   121,   113,   121,   113,   124,   125,   113,   124,   125,
     113,   124,   125,   113,   124,   125,   113,   124,   125,   113,
     125,   113,   120,   121,   124,   125,   126,   127,   113,   116,
     113,   124,   113,   124,   113,   124,   113,   124,   113,   124,
     113,   124,   125,   113,   124,   125,   113,   124,   125,   113,
     124,   125,   113,   124,   125,   113,   124,   125,   113,   124,
     125,   113,   124,   125,   113,   124,   125,   113,   124,   125,
     113,   124,   125,   113,   124,   125,   113,   120,   121,   124,
     125,   126,   127,   113,   116,   113,   124,   125,   113,   124,
     125,   113,   124,   125,   113,   124,   125,   113,   124,   125,
     113,   124,   125,   118,   113,   120,   121,   124,   125,   126,
     127,   113,   116,   126,   113,   126,   113,   126,   113,   126,
     113,   126,   113,   126,   113,   126,   113,   120,   121,   124,
     125,   126,   127,   113,   127,   113,   127,   113,   116,   113,
     127,   113,   127,   131,    10,    76,   129,   132,    42,     9,
     118,    10,     3,    12,    12,     3,   112,   124,   124,    15,
      16,    17,    18,    19,   124,   125,   124,   125,   124,   125,
     124,   125,   124,   125,   124,   125,   124,   124,   124,   124,
     124,   124,   125,   124,   125,   124,   125,   124,   125,   124,
     125,   124,   125,   112,   131,    12,    89,    41,    41,    41,
      76,   112,    13,     3,    14,    56,   102,   103,   132,    10,
      38,   106,   107,   132,    12,    41,   118,    12,    41,    76,
      14,    12,    10,    81,    14,     9,    10,    10,    40,    12,
      12,    12,    10,    40,   112,   122,    10,   107,    12,    12,
     112,   124,   124,   124,   124,   124,   131,     9,   112,   113,
     117,   118,   124,   112,   117,   112,   117,   102,   102,    76,
      14,     3,    76,    85,    76,    40,    10,    76,    12,   118,
      12,    41,    12,    41,   118,    42,    87,    14,     3,   112,
      87,   112,   129,    85,    10,   113,   117,   124,    10,    10,
      38,    40,    10,    10,    10,    10,    14,    42,   102,    42,
      38,   132,    85,    12,    12,   118,    12,   118,    12,    41,
     112,     3,    10,    60,    98,   100,    85,    10,    84,    85,
      86,    86,   118,   118,    86,    86,    86,    86,   112,   112,
      76,    76,    12,    12,    12,   118,    40,    87,    38,    12,
     123,   118
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    79,    80,    80,    81,    81,    81,    82,    82,    83,
      83,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    85,    85,    85,    85,    85,    86,    86,
      87,    87,    88,    89,    89,    90,    90,    90,    91,    91,
      92,    92,    92,    92,    92,    92,    93,    94,    95,    96,
      97,    98,    98,    99,   100,   101,   101,   101,   102,   102,
     102,   102,   103,   103,   103,   104,   104,   104,   104,   105,
     106,   106,   107,   107,   107,   108,   109,   109,   109,   109,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   111,   111,   112,   112,   112,   112,
     112,   112,   112,   112,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   114,   114,   114,
     114,   114,   115,   115,   115,   116,   116,   117,   117,   117,
     118,   118,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   120,   120,   121,   121,   122,   122,
     123,   123,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   128,   128,   129,   129,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   131,   131,   131,   131,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     1,     2,     1,     2,     3,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     3,     4,     4,     5,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     1,     1,     2,
       7,     7,     7,     7,     7,     7,     5,     1,     6,     1,
       6,     2,     0,     1,     1,     4,     5,     6,     1,     2,
       2,     3,     2,     4,     4,     5,     6,     5,     6,     1,
       2,     4,     2,     4,     1,     2,     4,     4,     4,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     3,     3,
       4,     4,     4,     4,     4,     4,     2,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     4,
       4,     5,     1,     3,     4,     1,     3,     3,     3,     5,
       1,     1,     3,     4,     4,     5,     4,     5,     5,     5,
       6,     6,     6,     7,     1,     3,     2,     4,     2,     3,
       4,     6,     1,     2,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     3,     1,     3,     2,     2,
       2,     2,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     4,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"",
  "\"terminator (\\\\n or ;)\"", "\"int\"", "\"float\"", "\"string\"",
  "\"bool\"", "\"none\"", "\"(\"", "\")\"", "\"[\"", "\"]\"", "\"{\"",
  "\"}\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"%\"", "\"**\"", "\"++\"",
  "\"and\"", "\"or\"", "\"not\"", "\"in\"", "\"&\"", "\"|\"", "\"^\"",
  "\"~\"", "\"<<\"", "\">>\"", "\"==\"", "\"!=\"", "\">\"", "\"<\"",
  "\">=\"", "\"<=\"", "\"..\"", "\".\"", "\",\"", "\":\"", "\"=\"",
  "\"++=\"", "\"**=\"", "\"%=\"", "\"/=\"", "\"*=\"", "\"-=\"", "\"+=\"",
  "\"&=\"", "\"|=\"", "\"^=\"", "\"~=\"", "\"<<=\"", "\">>=\"", "\"var\"",
  "\"any\"", "\"import\"", "\"if\"", "\"else\"", "\"for\"", "\"while\"",
  "\"do\"", "\"return\"", "\"break\"", "\"continue\"", "\"const\"",
  "\"?\"", "\"'int'\"", "\"'float'\"", "\"'string'\"", "\"'bool'\"",
  "\"'struct'\"", "\"'void'\"", "\"'range'\"", "\"identifier\"",
  "\"external identifier\"", "NEG", "$accept", "start", "stmt", "stmt_end",
  "stmts", "stmts_ne", "block", "body", "scope_body", "import", "id_list",
  "flowctl", "return", "for", "while", "wh_kw", "dowhile", "do_kw", "if",
  "else", "if_kw", "el_kw", "struct", "decllist", "declistval", "function",
  "fun_id", "funargsnvar", "funargs", "vardecl", "vardef", "set",
  "callarglist", "expr", "expr_var", "matrix", "matvals", "expr_mat",
  "range", "int_val", "slice", "expr_none", "expr_struct", "struct_val",
  "struct_list", "expr_int", "expr_float", "expr_str", "expr_bool",
  "funtype", "typelist", "mattype", "matsq", "type", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   231,   231,   232,   234,   235,   236,   239,   240,   243,
     244,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   261,   262,   263,   264,   265,   268,   269,
     272,   273,   277,   279,   280,   284,   285,   286,   288,   289,
     293,   294,   295,   296,   297,   298,   302,   304,   306,   308,
     311,   313,   314,   316,   317,   320,   321,   322,   324,   325,
     326,   327,   329,   330,   331,   335,   336,   337,   338,   340,
     342,   343,   345,   346,   347,   352,   356,   357,   358,   359,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   380,   381,   385,   386,   387,   388,
     389,   390,   391,   392,   395,   396,   397,   398,   399,   401,
     402,   404,   405,   406,   407,   408,   410,   411,   412,   413,
     415,   416,   417,   419,   420,   421,   422,   423,   425,   426,
     427,   428,   429,   430,   431,   432,   434,   435,   436,   437,
     438,   440,   441,   442,   443,   444,   446,   447,   448,   449,
     450,   451,   452,   453,   455,   456,   457,   458,   459,   460,
     461,   462,   464,   465,   466,   468,   469,   470,   472,   473,
     474,   475,   476,   477,   478,   480,   481,   482,   483,   484,
     485,   486,   488,   489,   490,   491,   492,   493,   494,   496,
     497,   498,   499,   500,   501,   502,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   522,   523,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     540,   541,   542,   544,   545,   546,   548,   549,   550,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   569,   570,   571,   573,   574,
     575,   577,   579,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   608,   609,   610,
     611,   612,   615,   616,   617,   621,   622,   624,   625,   626,
     628,   629,   631,   632,   633,   634,   635,   636,   637,   638,
     639,   640,   641,   642,   646,   647,   651,   652,   654,   655,
     657,   658,   662,   663,   664,   665,   666,   667,   668,   669,
     670,   671,   672,   673,   674,   675,   679,   680,   681,   682,
     683,   684,   685,   686,   687,   688,   689,   690,   691,   692,
     693,   694,   695,   696,   697,   698,   699,   703,   704,   705,
     706,   707,   708,   709,   710,   711,   712,   713,   714,   715,
     716,   717,   718,   719,   720,   721,   722,   723,   724,   725,
     726,   727,   728,   729,   733,   734,   735,   736,   737,   739,
     740,   741,   742,   743,   744,   745,   747,   748,   749,   750,
     751,   752,   753,   755,   756,   757,   758,   759,   761,   762,
     763,   764,   765,   767,   768,   769,   770,   771,   773,   774,
     775,   776,   777,   779,   783,   784,   786,   787,   791,   792,
     793,   794,   795,   796,   797,   798,   799,   800,   801,   802,
     803,   805,   806,   807,   808,   812,   813,   814,   815,   816,
     817,   818,   819,   820,   821,   822,   823,   824,   825,   826
  };

  void
   Parser ::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
   Parser ::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

   Parser ::symbol_kind_type
   Parser ::yytranslate_ (int t) YY_NOEXCEPT
  {
    return static_cast<symbol_kind_type> (t);
  }

#line 14 "frontend/parser.yy"
} //  ptc 
#line 4991 "frontend/parser.cpp"

#line 829 "frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    auto msg = std::to_string(scanner->loc->begin.line) + ":" + std::to_string(scanner->loc->begin.column) + ": " + err_message;
    scanner->fatal_error(ptc::diag::ERR_SYNTAX, msg);
}
