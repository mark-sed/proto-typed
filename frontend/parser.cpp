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
  case 2: // start: "end of file"
#line 231 "frontend/parser.yy"
                        { scanner->parseEntry(std::vector<ptc::ir::IR *>{}); }
#line 1182 "frontend/parser.cpp"
    break;

  case 3: // start: stmt "end of file"
#line 232 "frontend/parser.yy"
                        { scanner->parseEntry(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1188 "frontend/parser.cpp"
    break;

  case 4: // stmt: stmts
#line 234 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1194 "frontend/parser.cpp"
    break;

  case 5: // stmt: stmt stmts
#line 235 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1200 "frontend/parser.cpp"
    break;

  case 6: // stmt: stmt error stmts
#line 236 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1206 "frontend/parser.cpp"
    break;

  case 9: // stmts: "terminator (\\n or ;)"
#line 243 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = nullptr; }
#line 1212 "frontend/parser.cpp"
    break;

  case 10: // stmts: stmts_ne
#line 244 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1218 "frontend/parser.cpp"
    break;

  case 11: // stmts_ne: set stmt_end
#line 246 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1224 "frontend/parser.cpp"
    break;

  case 12: // stmts_ne: vardecl stmt_end
#line 247 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1230 "frontend/parser.cpp"
    break;

  case 13: // stmts_ne: vardef stmt_end
#line 248 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1236 "frontend/parser.cpp"
    break;

  case 14: // stmts_ne: import stmt_end
#line 249 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1242 "frontend/parser.cpp"
    break;

  case 15: // stmts_ne: for
#line 250 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1248 "frontend/parser.cpp"
    break;

  case 16: // stmts_ne: if
#line 251 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1254 "frontend/parser.cpp"
    break;

  case 17: // stmts_ne: while
#line 252 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1260 "frontend/parser.cpp"
    break;

  case 18: // stmts_ne: dowhile
#line 253 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1266 "frontend/parser.cpp"
    break;

  case 19: // stmts_ne: struct
#line 254 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1272 "frontend/parser.cpp"
    break;

  case 20: // stmts_ne: function
#line 255 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1278 "frontend/parser.cpp"
    break;

  case 21: // stmts_ne: flowctl stmt_end
#line 256 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1284 "frontend/parser.cpp"
    break;

  case 22: // stmts_ne: expr stmt_end
#line 257 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1290 "frontend/parser.cpp"
    break;

  case 23: // block: "{" "}"
#line 261 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1296 "frontend/parser.cpp"
    break;

  case 24: // block: "{" stmt "}"
#line 262 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1302 "frontend/parser.cpp"
    break;

  case 25: // block: "terminator (\\n or ;)" "{" stmt "}"
#line 263 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1308 "frontend/parser.cpp"
    break;

  case 26: // block: "{" stmt "}" "terminator (\\n or ;)"
#line 264 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1314 "frontend/parser.cpp"
    break;

  case 27: // block: "terminator (\\n or ;)" "{" stmt "}" "terminator (\\n or ;)"
#line 265 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1320 "frontend/parser.cpp"
    break;

  case 28: // body: stmts_ne
#line 268 "frontend/parser.yy"
                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1326 "frontend/parser.cpp"
    break;

  case 29: // body: block
#line 269 "frontend/parser.yy"
                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1332 "frontend/parser.cpp"
    break;

  case 30: // scope_body: stmts_ne
#line 272 "frontend/parser.yy"
                      { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); scanner->leaveScope(); }
#line 1338 "frontend/parser.cpp"
    break;

  case 31: // scope_body: block
#line 273 "frontend/parser.yy"
                      { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); scanner->leaveScope(); }
#line 1344 "frontend/parser.cpp"
    break;

  case 32: // import: "import" id_list
#line 277 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::IR * > () = scanner->parseImports(yystack_[0].value.as < std::vector<std::string>  > ()); }
#line 1350 "frontend/parser.cpp"
    break;

  case 33: // id_list: "identifier"
#line 279 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseImportName(yystack_[0].value.as < std::string > ()); }
#line 1356 "frontend/parser.cpp"
    break;

  case 34: // id_list: "identifier" "," id_list
#line 280 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseAddImportName(yystack_[0].value.as < std::vector<std::string>  > (), yystack_[2].value.as < std::string > ()); }
#line 1362 "frontend/parser.cpp"
    break;

  case 35: // flowctl: "break"
#line 284 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseBreak(); }
#line 1368 "frontend/parser.cpp"
    break;

  case 36: // flowctl: "continue"
#line 285 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseContinue(); }
#line 1374 "frontend/parser.cpp"
    break;

  case 37: // flowctl: return
#line 286 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1380 "frontend/parser.cpp"
    break;

  case 38: // return: "return"
#line 288 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(nullptr); }
#line 1386 "frontend/parser.cpp"
    break;

  case 39: // return: "return" expr
#line 289 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1392 "frontend/parser.cpp"
    break;

  case 40: // for: "for" "(" vardecl ":" expr ")" body
#line 293 "frontend/parser.yy"
                                              { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1398 "frontend/parser.cpp"
    break;

  case 41: // for: "for" "(" "identifier" ":" expr ")" body
#line 294 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1404 "frontend/parser.cpp"
    break;

  case 42: // for: "for" "(" "external identifier" ":" expr ")" body
#line 295 "frontend/parser.yy"
                                              { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1410 "frontend/parser.cpp"
    break;

  case 43: // for: "for" "(" vardecl ":" range ")" body
#line 296 "frontend/parser.yy"
                                               { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1416 "frontend/parser.cpp"
    break;

  case 44: // for: "for" "(" "identifier" ":" range ")" body
#line 297 "frontend/parser.yy"
                                           { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1422 "frontend/parser.cpp"
    break;

  case 45: // for: "for" "(" "external identifier" ":" range ")" body
#line 298 "frontend/parser.yy"
                                               { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1428 "frontend/parser.cpp"
    break;

  case 46: // while: wh_kw "(" expr ")" scope_body
#line 302 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseWhile(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1434 "frontend/parser.cpp"
    break;

  case 47: // wh_kw: "while"
#line 304 "frontend/parser.yy"
                { scanner->enterBlockScope(); }
#line 1440 "frontend/parser.cpp"
    break;

  case 48: // dowhile: do_kw scope_body "while" "(" expr ")"
#line 306 "frontend/parser.yy"
                                                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseDoWhile(yystack_[1].value.as < ptc::ir::Expr * > (), yystack_[4].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1446 "frontend/parser.cpp"
    break;

  case 49: // do_kw: "do"
#line 308 "frontend/parser.yy"
             { scanner->enterBlockScope(); }
#line 1452 "frontend/parser.cpp"
    break;

  case 50: // if: if_kw "(" expr ")" scope_body else
#line 311 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseIfStmt(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1458 "frontend/parser.cpp"
    break;

  case 51: // else: el_kw scope_body
#line 313 "frontend/parser.yy"
                         { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1464 "frontend/parser.cpp"
    break;

  case 52: // else: %empty
#line 314 "frontend/parser.yy"
                    { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1470 "frontend/parser.cpp"
    break;

  case 53: // if_kw: "if"
#line 316 "frontend/parser.yy"
             { scanner->enterBlockScope(); }
#line 1476 "frontend/parser.cpp"
    break;

  case 54: // el_kw: "else"
#line 317 "frontend/parser.yy"
               { scanner->enterBlockScope(); }
#line 1482 "frontend/parser.cpp"
    break;

  case 55: // struct: "'struct'" "identifier" "{" "}"
#line 320 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[2].value.as < std::string > (), std::vector<ptc::ir::IR *>{}); }
#line 1488 "frontend/parser.cpp"
    break;

  case 56: // struct: "'struct'" "identifier" "{" decllist "}"
#line 321 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1494 "frontend/parser.cpp"
    break;

  case 57: // struct: "'struct'" "identifier" "terminator (\\n or ;)" "{" decllist "}"
#line 322 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[4].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1500 "frontend/parser.cpp"
    break;

  case 59: // decllist: "terminator (\\n or ;)" decllist
#line 325 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1506 "frontend/parser.cpp"
    break;

  case 60: // decllist: declistval "terminator (\\n or ;)"
#line 326 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[1].value.as < ptc::ir::IR * > (), std::vector<ptc::ir::IR *>{}); }
#line 1512 "frontend/parser.cpp"
    break;

  case 61: // decllist: declistval "terminator (\\n or ;)" decllist
#line 327 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[2].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1518 "frontend/parser.cpp"
    break;

  case 62: // declistval: type "identifier"
#line 329 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > (), nullptr); }
#line 1524 "frontend/parser.cpp"
    break;

  case 63: // declistval: type "identifier" "=" expr
#line 330 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1530 "frontend/parser.cpp"
    break;

  case 65: // function: type fun_id "(" ")" block
#line 335 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1536 "frontend/parser.cpp"
    break;

  case 66: // function: type fun_id "(" funargs ")" block
#line 336 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[5].value.as < ptc::ir::IR * > (), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1542 "frontend/parser.cpp"
    break;

  case 67: // function: "'void'" fun_id "(" ")" block
#line 337 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1548 "frontend/parser.cpp"
    break;

  case 68: // function: "'void'" fun_id "(" funargs ")" block
#line 338 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1554 "frontend/parser.cpp"
    break;

  case 69: // fun_id: "identifier"
#line 340 "frontend/parser.yy"
            { scanner->enterFunScope(); yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1560 "frontend/parser.cpp"
    break;

  case 70: // funargsnvar: type "identifier"
#line 342 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseFunParam(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1566 "frontend/parser.cpp"
    break;

  case 71: // funargsnvar: funargsnvar "," type "identifier"
#line 343 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseAddFunParam(yystack_[3].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1572 "frontend/parser.cpp"
    break;

  case 72: // funargs: ".." "identifier"
#line 345 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseFunParam(scanner->sym_lookup(VARARGS_CSTR, false, true), yystack_[0].value.as < std::string > ()); }
#line 1578 "frontend/parser.cpp"
    break;

  case 73: // funargs: funargsnvar "," ".." "identifier"
#line 346 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseAddFunParam(yystack_[3].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), scanner->sym_lookup(VARARGS_CSTR, false, true), yystack_[0].value.as < std::string > ());}
#line 1584 "frontend/parser.cpp"
    break;

  case 74: // funargs: funargsnvar
#line 347 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = yystack_[0].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (); }
#line 1590 "frontend/parser.cpp"
    break;

  case 75: // vardecl: type "identifier"
#line 352 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1596 "frontend/parser.cpp"
    break;

  case 76: // vardef: type "identifier" "=" struct_val
#line 356 "frontend/parser.yy"
         { yylhs.value.as < ptc::ir::IR * > () = yystack_[3].value.as < ptc::ir::IR * > (); }
#line 1602 "frontend/parser.cpp"
    break;

  case 77: // vardef: type "identifier" "=" expr
#line 357 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1608 "frontend/parser.cpp"
    break;

  case 80: // set: expr "++=" expr
#line 363 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1614 "frontend/parser.cpp"
    break;

  case 81: // set: expr "**=" expr
#line 364 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1620 "frontend/parser.cpp"
    break;

  case 82: // set: expr "%=" expr
#line 365 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1626 "frontend/parser.cpp"
    break;

  case 83: // set: expr "/=" expr
#line 366 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1632 "frontend/parser.cpp"
    break;

  case 84: // set: expr "*=" expr
#line 367 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1638 "frontend/parser.cpp"
    break;

  case 85: // set: expr "-=" expr
#line 368 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1644 "frontend/parser.cpp"
    break;

  case 86: // set: expr "+=" expr
#line 369 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1650 "frontend/parser.cpp"
    break;

  case 87: // set: expr "&=" expr
#line 370 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1656 "frontend/parser.cpp"
    break;

  case 88: // set: expr "|=" expr
#line 371 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1662 "frontend/parser.cpp"
    break;

  case 89: // set: expr "^=" expr
#line 372 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1668 "frontend/parser.cpp"
    break;

  case 90: // set: expr "<<=" expr
#line 373 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1674 "frontend/parser.cpp"
    break;

  case 91: // set: expr ">>=" expr
#line 374 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1680 "frontend/parser.cpp"
    break;

  case 92: // set: expr "=" expr
#line 375 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1686 "frontend/parser.cpp"
    break;

  case 93: // set: expr "=" set
#line 376 "frontend/parser.yy"
      { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1692 "frontend/parser.cpp"
    break;

  case 94: // callarglist: expr
#line 380 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseFunCallArg(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1698 "frontend/parser.cpp"
    break;

  case 95: // callarglist: callarglist "," expr
#line 381 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddFunCallArg(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1704 "frontend/parser.cpp"
    break;

  case 96: // expr: expr_mat
#line 385 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1710 "frontend/parser.cpp"
    break;

  case 97: // expr: expr_var
#line 386 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1716 "frontend/parser.cpp"
    break;

  case 98: // expr: expr_none
#line 387 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1722 "frontend/parser.cpp"
    break;

  case 100: // expr: expr_int
#line 389 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 1728 "frontend/parser.cpp"
    break;

  case 101: // expr: expr_float
#line 390 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFloat(yystack_[0].value.as < double > ()); }
#line 1734 "frontend/parser.cpp"
    break;

  case 102: // expr: expr_str
#line 391 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseString(yystack_[0].value.as < std::string > ()); }
#line 1740 "frontend/parser.cpp"
    break;

  case 103: // expr: expr_bool
#line 392 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseBool(yystack_[0].value.as < bool > ()); }
#line 1746 "frontend/parser.cpp"
    break;

  case 104: // expr_var: "identifier"
#line 395 "frontend/parser.yy"
              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > ()); }
#line 1752 "frontend/parser.cpp"
    break;

  case 105: // expr_var: "external identifier"
#line 396 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > (), true); }
#line 1758 "frontend/parser.cpp"
    break;

  case 106: // expr_var: "-" "identifier"
#line 397 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1764 "frontend/parser.cpp"
    break;

  case 107: // expr_var: "-" "external identifier"
#line 398 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > (), true), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1770 "frontend/parser.cpp"
    break;

  case 108: // expr_var: "(" expr_var ")"
#line 399 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1776 "frontend/parser.cpp"
    break;

  case 109: // expr_var: expr_var "(" ")"
#line 401 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[2].value.as < ptc::ir::Expr * > (), std::vector<ptc::ir::Expr *>{}); }
#line 1782 "frontend/parser.cpp"
    break;

  case 110: // expr_var: expr_var "(" callarglist ")"
#line 402 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 1788 "frontend/parser.cpp"
    break;

  case 111: // expr_var: expr_str "[" int_val "]"
#line 404 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1794 "frontend/parser.cpp"
    break;

  case 112: // expr_var: expr_mat "[" int_val "]"
#line 405 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1800 "frontend/parser.cpp"
    break;

  case 113: // expr_var: "identifier" "[" int_val "]"
#line 406 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1806 "frontend/parser.cpp"
    break;

  case 114: // expr_var: "external identifier" "[" int_val "]"
#line 407 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1812 "frontend/parser.cpp"
    break;

  case 115: // expr_var: expr_var "[" int_val "]"
#line 408 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1818 "frontend/parser.cpp"
    break;

  case 116: // expr_var: expr_mat slice
#line 410 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1824 "frontend/parser.cpp"
    break;

  case 119: // expr_var: expr_var slice
#line 413 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1830 "frontend/parser.cpp"
    break;

  case 120: // expr_var: expr_var "." "identifier"
#line 415 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1836 "frontend/parser.cpp"
    break;

  case 121: // expr_var: expr_var "." "external identifier"
#line 416 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1842 "frontend/parser.cpp"
    break;

  case 122: // expr_var: expr_float "**" expr_var
#line 419 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1848 "frontend/parser.cpp"
    break;

  case 123: // expr_var: expr_var "**" expr_float
#line 420 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1854 "frontend/parser.cpp"
    break;

  case 124: // expr_var: expr_var "**" expr_var
#line 421 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1860 "frontend/parser.cpp"
    break;

  case 125: // expr_var: expr_int "**" expr_var
#line 422 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < long > ()) /*Float on purpose*/, yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1866 "frontend/parser.cpp"
    break;

  case 126: // expr_var: expr_var "**" expr_int
#line 423 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < long > ()) /*Float on purpose*/, ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1872 "frontend/parser.cpp"
    break;

  case 127: // expr_var: expr_int "*" expr_var
#line 425 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1878 "frontend/parser.cpp"
    break;

  case 128: // expr_var: expr_float "*" expr_var
#line 426 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1884 "frontend/parser.cpp"
    break;

  case 129: // expr_var: expr_var "*" expr_int
#line 427 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1890 "frontend/parser.cpp"
    break;

  case 130: // expr_var: expr_var "*" expr_float
#line 428 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1896 "frontend/parser.cpp"
    break;

  case 131: // expr_var: expr_mat "*" expr_mat
#line 429 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1902 "frontend/parser.cpp"
    break;

  case 132: // expr_var: expr_mat "*" expr_var
#line 430 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1908 "frontend/parser.cpp"
    break;

  case 133: // expr_var: expr_var "*" expr_mat
#line 431 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1914 "frontend/parser.cpp"
    break;

  case 134: // expr_var: expr_var "*" expr_var
#line 432 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1920 "frontend/parser.cpp"
    break;

  case 135: // expr_var: expr_int "/" expr_var
#line 434 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1926 "frontend/parser.cpp"
    break;

  case 136: // expr_var: expr_float "/" expr_var
#line 435 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1932 "frontend/parser.cpp"
    break;

  case 137: // expr_var: expr_var "/" expr_int
#line 436 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1938 "frontend/parser.cpp"
    break;

  case 138: // expr_var: expr_var "/" expr_float
#line 437 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1944 "frontend/parser.cpp"
    break;

  case 139: // expr_var: expr_var "/" expr_var
#line 438 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1950 "frontend/parser.cpp"
    break;

  case 140: // expr_var: expr_int "%" expr_var
#line 440 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1956 "frontend/parser.cpp"
    break;

  case 141: // expr_var: expr_float "%" expr_var
#line 441 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1962 "frontend/parser.cpp"
    break;

  case 142: // expr_var: expr_var "%" expr_int
#line 442 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1968 "frontend/parser.cpp"
    break;

  case 143: // expr_var: expr_var "%" expr_float
#line 443 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1974 "frontend/parser.cpp"
    break;

  case 144: // expr_var: expr_var "%" expr_var
#line 444 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1980 "frontend/parser.cpp"
    break;

  case 145: // expr_var: expr_int "+" expr_var
#line 446 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1986 "frontend/parser.cpp"
    break;

  case 146: // expr_var: expr_float "+" expr_var
#line 447 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1992 "frontend/parser.cpp"
    break;

  case 147: // expr_var: expr_var "+" expr_int
#line 448 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1998 "frontend/parser.cpp"
    break;

  case 148: // expr_var: expr_var "+" expr_float
#line 449 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2004 "frontend/parser.cpp"
    break;

  case 149: // expr_var: expr_mat "+" expr_mat
#line 450 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2010 "frontend/parser.cpp"
    break;

  case 150: // expr_var: expr_var "+" expr_mat
#line 451 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2016 "frontend/parser.cpp"
    break;

  case 151: // expr_var: expr_mat "+" expr_var
#line 452 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2022 "frontend/parser.cpp"
    break;

  case 152: // expr_var: expr_var "+" expr_var
#line 453 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2028 "frontend/parser.cpp"
    break;

  case 153: // expr_var: expr_int "-" expr_var
#line 455 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2034 "frontend/parser.cpp"
    break;

  case 154: // expr_var: expr_float "-" expr_var
#line 456 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2040 "frontend/parser.cpp"
    break;

  case 155: // expr_var: expr_var "-" expr_int
#line 457 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2046 "frontend/parser.cpp"
    break;

  case 156: // expr_var: expr_var "-" expr_float
#line 458 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2052 "frontend/parser.cpp"
    break;

  case 157: // expr_var: expr_mat "-" expr_mat
#line 459 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2058 "frontend/parser.cpp"
    break;

  case 158: // expr_var: expr_var "-" expr_mat
#line 460 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2064 "frontend/parser.cpp"
    break;

  case 159: // expr_var: expr_mat "-" expr_var
#line 461 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2070 "frontend/parser.cpp"
    break;

  case 160: // expr_var: expr_var "-" expr_var
#line 462 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2076 "frontend/parser.cpp"
    break;

  case 161: // expr_var: expr_int "<<" expr_var
#line 464 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2082 "frontend/parser.cpp"
    break;

  case 162: // expr_var: expr_var "<<" expr_int
#line 465 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2088 "frontend/parser.cpp"
    break;

  case 163: // expr_var: expr_var "<<" expr_var
#line 466 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2094 "frontend/parser.cpp"
    break;

  case 164: // expr_var: expr_int ">>" expr_var
#line 468 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2100 "frontend/parser.cpp"
    break;

  case 165: // expr_var: expr_var ">>" expr_int
#line 469 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2106 "frontend/parser.cpp"
    break;

  case 166: // expr_var: expr_var ">>" expr_var
#line 470 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2112 "frontend/parser.cpp"
    break;

  case 167: // expr_var: expr_int ">" expr_var
#line 472 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2118 "frontend/parser.cpp"
    break;

  case 168: // expr_var: expr_float ">" expr_var
#line 473 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2124 "frontend/parser.cpp"
    break;

  case 169: // expr_var: expr_str ">" expr_var
#line 474 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2130 "frontend/parser.cpp"
    break;

  case 170: // expr_var: expr_var ">" expr_int
#line 475 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2136 "frontend/parser.cpp"
    break;

  case 171: // expr_var: expr_var ">" expr_float
#line 476 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2142 "frontend/parser.cpp"
    break;

  case 172: // expr_var: expr_var ">" expr_str
#line 477 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2148 "frontend/parser.cpp"
    break;

  case 173: // expr_var: expr_var ">" expr_var
#line 478 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2154 "frontend/parser.cpp"
    break;

  case 174: // expr_var: expr_int ">=" expr_var
#line 480 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2160 "frontend/parser.cpp"
    break;

  case 175: // expr_var: expr_float ">=" expr_var
#line 481 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2166 "frontend/parser.cpp"
    break;

  case 176: // expr_var: expr_str ">=" expr_var
#line 482 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2172 "frontend/parser.cpp"
    break;

  case 177: // expr_var: expr_var ">=" expr_int
#line 483 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2178 "frontend/parser.cpp"
    break;

  case 178: // expr_var: expr_var ">=" expr_float
#line 484 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2184 "frontend/parser.cpp"
    break;

  case 179: // expr_var: expr_var ">=" expr_str
#line 485 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2190 "frontend/parser.cpp"
    break;

  case 180: // expr_var: expr_var ">=" expr_var
#line 486 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2196 "frontend/parser.cpp"
    break;

  case 181: // expr_var: expr_int "<" expr_var
#line 488 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2202 "frontend/parser.cpp"
    break;

  case 182: // expr_var: expr_float "<" expr_var
#line 489 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2208 "frontend/parser.cpp"
    break;

  case 183: // expr_var: expr_str "<" expr_var
#line 490 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2214 "frontend/parser.cpp"
    break;

  case 184: // expr_var: expr_var "<" expr_int
#line 491 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2220 "frontend/parser.cpp"
    break;

  case 185: // expr_var: expr_var "<" expr_float
#line 492 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2226 "frontend/parser.cpp"
    break;

  case 186: // expr_var: expr_var "<" expr_str
#line 493 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2232 "frontend/parser.cpp"
    break;

  case 187: // expr_var: expr_var "<" expr_var
#line 494 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2238 "frontend/parser.cpp"
    break;

  case 188: // expr_var: expr_int "<=" expr_var
#line 496 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2244 "frontend/parser.cpp"
    break;

  case 189: // expr_var: expr_float "<=" expr_var
#line 497 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2250 "frontend/parser.cpp"
    break;

  case 190: // expr_var: expr_str "<=" expr_var
#line 498 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2256 "frontend/parser.cpp"
    break;

  case 191: // expr_var: expr_var "<=" expr_int
#line 499 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2262 "frontend/parser.cpp"
    break;

  case 192: // expr_var: expr_var "<=" expr_float
#line 500 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2268 "frontend/parser.cpp"
    break;

  case 193: // expr_var: expr_var "<=" expr_str
#line 501 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2274 "frontend/parser.cpp"
    break;

  case 194: // expr_var: expr_var "<=" expr_var
#line 502 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2280 "frontend/parser.cpp"
    break;

  case 195: // expr_var: expr_int "==" expr_var
#line 504 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2286 "frontend/parser.cpp"
    break;

  case 196: // expr_var: expr_float "==" expr_var
#line 505 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2292 "frontend/parser.cpp"
    break;

  case 197: // expr_var: expr_str "==" expr_var
#line 506 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2298 "frontend/parser.cpp"
    break;

  case 198: // expr_var: expr_bool "==" expr_var
#line 507 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2304 "frontend/parser.cpp"
    break;

  case 199: // expr_var: expr_none "==" expr_var
#line 508 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2310 "frontend/parser.cpp"
    break;

  case 202: // expr_var: expr_var "==" expr_int
#line 511 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2316 "frontend/parser.cpp"
    break;

  case 203: // expr_var: expr_var "==" expr_float
#line 512 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2322 "frontend/parser.cpp"
    break;

  case 204: // expr_var: expr_var "==" expr_str
#line 513 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2328 "frontend/parser.cpp"
    break;

  case 205: // expr_var: expr_var "==" expr_bool
#line 514 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2334 "frontend/parser.cpp"
    break;

  case 206: // expr_var: expr_var "==" expr_none
#line 515 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2340 "frontend/parser.cpp"
    break;

  case 207: // expr_var: expr_var "==" expr_struct
#line 516 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2346 "frontend/parser.cpp"
    break;

  case 208: // expr_var: expr_mat "==" expr_mat
#line 517 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2352 "frontend/parser.cpp"
    break;

  case 209: // expr_var: expr_var "==" expr_mat
#line 518 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2358 "frontend/parser.cpp"
    break;

  case 210: // expr_var: expr_mat "==" expr_var
#line 519 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2364 "frontend/parser.cpp"
    break;

  case 211: // expr_var: expr_var "==" expr_var
#line 520 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2370 "frontend/parser.cpp"
    break;

  case 212: // expr_var: expr_int "!=" expr_var
#line 522 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2376 "frontend/parser.cpp"
    break;

  case 213: // expr_var: expr_float "!=" expr_var
#line 523 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2382 "frontend/parser.cpp"
    break;

  case 214: // expr_var: expr_str "!=" expr_var
#line 524 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2388 "frontend/parser.cpp"
    break;

  case 215: // expr_var: expr_bool "!=" expr_var
#line 525 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2394 "frontend/parser.cpp"
    break;

  case 216: // expr_var: expr_none "!=" expr_var
#line 526 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2400 "frontend/parser.cpp"
    break;

  case 219: // expr_var: expr_var "!=" expr_int
#line 529 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2406 "frontend/parser.cpp"
    break;

  case 220: // expr_var: expr_var "!=" expr_float
#line 530 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2412 "frontend/parser.cpp"
    break;

  case 221: // expr_var: expr_var "!=" expr_str
#line 531 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2418 "frontend/parser.cpp"
    break;

  case 222: // expr_var: expr_var "!=" expr_bool
#line 532 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2424 "frontend/parser.cpp"
    break;

  case 223: // expr_var: expr_var "!=" expr_none
#line 533 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2430 "frontend/parser.cpp"
    break;

  case 224: // expr_var: expr_var "!=" expr_struct
#line 534 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2436 "frontend/parser.cpp"
    break;

  case 225: // expr_var: expr_mat "!=" expr_mat
#line 535 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2442 "frontend/parser.cpp"
    break;

  case 226: // expr_var: expr_var "!=" expr_mat
#line 536 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2448 "frontend/parser.cpp"
    break;

  case 227: // expr_var: expr_mat "!=" expr_var
#line 537 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2454 "frontend/parser.cpp"
    break;

  case 228: // expr_var: expr_var "!=" expr_var
#line 538 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2460 "frontend/parser.cpp"
    break;

  case 229: // expr_var: expr_int "&" expr_var
#line 540 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2466 "frontend/parser.cpp"
    break;

  case 230: // expr_var: expr_var "&" expr_int
#line 541 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2472 "frontend/parser.cpp"
    break;

  case 231: // expr_var: expr_var "&" expr_var
#line 542 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2478 "frontend/parser.cpp"
    break;

  case 232: // expr_var: expr_int "^" expr_var
#line 544 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2484 "frontend/parser.cpp"
    break;

  case 233: // expr_var: expr_var "^" expr_int
#line 545 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2490 "frontend/parser.cpp"
    break;

  case 234: // expr_var: expr_var "^" expr_var
#line 546 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2496 "frontend/parser.cpp"
    break;

  case 235: // expr_var: expr_int "|" expr_var
#line 548 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2502 "frontend/parser.cpp"
    break;

  case 236: // expr_var: expr_var "|" expr_int
#line 549 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2508 "frontend/parser.cpp"
    break;

  case 237: // expr_var: expr_var "|" expr_var
#line 550 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2514 "frontend/parser.cpp"
    break;

  case 242: // expr_var: expr_none "in" expr_mat
#line 556 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2520 "frontend/parser.cpp"
    break;

  case 244: // expr_var: expr_mat "in" expr_mat
#line 558 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2526 "frontend/parser.cpp"
    break;

  case 249: // expr_var: expr_none "in" expr_var
#line 563 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2532 "frontend/parser.cpp"
    break;

  case 251: // expr_var: expr_mat "in" expr_var
#line 565 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2538 "frontend/parser.cpp"
    break;

  case 252: // expr_var: expr_var "in" expr_str
#line 566 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2544 "frontend/parser.cpp"
    break;

  case 253: // expr_var: expr_var "in" expr_var
#line 567 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2550 "frontend/parser.cpp"
    break;

  case 254: // expr_var: expr_bool "and" expr_var
#line 569 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2556 "frontend/parser.cpp"
    break;

  case 255: // expr_var: expr_var "and" expr_bool
#line 570 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2562 "frontend/parser.cpp"
    break;

  case 256: // expr_var: expr_var "and" expr_var
#line 571 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2568 "frontend/parser.cpp"
    break;

  case 257: // expr_var: expr_bool "or" expr_var
#line 573 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2574 "frontend/parser.cpp"
    break;

  case 258: // expr_var: expr_var "or" expr_bool
#line 574 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2580 "frontend/parser.cpp"
    break;

  case 259: // expr_var: expr_var "or" expr_var
#line 575 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2586 "frontend/parser.cpp"
    break;

  case 260: // expr_var: "not" expr_var
#line 577 "frontend/parser.yy"
                         { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseUnaryPrefixExpr(yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LNOT)); }
#line 2592 "frontend/parser.cpp"
    break;

  case 261: // expr_var: "~" expr_var
#line 579 "frontend/parser.yy"
                         { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseUnaryPrefixExpr(yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BNOT)); }
#line 2598 "frontend/parser.cpp"
    break;

  case 262: // expr_var: expr_int "++" expr_var
#line 581 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2604 "frontend/parser.cpp"
    break;

  case 263: // expr_var: expr_float "++" expr_var
#line 582 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2610 "frontend/parser.cpp"
    break;

  case 264: // expr_var: expr_str "++" expr_var
#line 583 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2616 "frontend/parser.cpp"
    break;

  case 265: // expr_var: expr_bool "++" expr_var
#line 584 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2622 "frontend/parser.cpp"
    break;

  case 266: // expr_var: expr_none "++" expr_var
#line 585 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseNone(), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2628 "frontend/parser.cpp"
    break;

  case 267: // expr_var: expr_var "++" expr_int
#line 586 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2634 "frontend/parser.cpp"
    break;

  case 268: // expr_var: expr_var "++" expr_float
#line 587 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2640 "frontend/parser.cpp"
    break;

  case 269: // expr_var: expr_var "++" expr_str
#line 588 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2646 "frontend/parser.cpp"
    break;

  case 270: // expr_var: expr_var "++" expr_bool
#line 589 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2652 "frontend/parser.cpp"
    break;

  case 271: // expr_var: expr_var "++" expr_none
#line 590 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseNone(), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2658 "frontend/parser.cpp"
    break;

  case 272: // expr_var: expr_var "++" expr_var
#line 591 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2664 "frontend/parser.cpp"
    break;

  case 273: // matrix: "[" "]"
#line 595 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(std::vector<ptc::ir::Expr *>{}); }
#line 2670 "frontend/parser.cpp"
    break;

  case 274: // matrix: "[" matvals "]"
#line 596 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2676 "frontend/parser.cpp"
    break;

  case 275: // matrix: "[" "terminator (\\n or ;)" matvals "]"
#line 597 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2682 "frontend/parser.cpp"
    break;

  case 276: // matrix: "[" matvals "terminator (\\n or ;)" "]"
#line 598 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2688 "frontend/parser.cpp"
    break;

  case 277: // matrix: "[" "terminator (\\n or ;)" matvals "terminator (\\n or ;)" "]"
#line 599 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2694 "frontend/parser.cpp"
    break;

  case 278: // matvals: expr
#line 602 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixValue(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2700 "frontend/parser.cpp"
    break;

  case 279: // matvals: matvals "," expr
#line 603 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2706 "frontend/parser.cpp"
    break;

  case 280: // matvals: matvals "," "terminator (\\n or ;)" expr
#line 604 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[3].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2712 "frontend/parser.cpp"
    break;

  case 281: // expr_mat: matrix
#line 608 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2718 "frontend/parser.cpp"
    break;

  case 282: // expr_mat: "(" matrix ")"
#line 609 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2724 "frontend/parser.cpp"
    break;

  case 283: // range: "(" range ")"
#line 611 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2730 "frontend/parser.cpp"
    break;

  case 284: // range: int_val ".." int_val
#line 612 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseRange(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2736 "frontend/parser.cpp"
    break;

  case 285: // range: int_val "," int_val ".." int_val
#line 613 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseRange(yystack_[4].value.as < ptc::ir::Expr * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2742 "frontend/parser.cpp"
    break;

  case 286: // int_val: expr_int
#line 615 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 2748 "frontend/parser.cpp"
    break;

  case 287: // int_val: expr_var
#line 616 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2754 "frontend/parser.cpp"
    break;

  case 300: // expr_none: "none"
#line 633 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseNone(); }
#line 2760 "frontend/parser.cpp"
    break;

  case 301: // expr_none: "(" "none" ")"
#line 634 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseNone(); }
#line 2766 "frontend/parser.cpp"
    break;

  case 308: // expr_int: "int"
#line 649 "frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 2772 "frontend/parser.cpp"
    break;

  case 309: // expr_int: "-" expr_int
#line 650 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 2778 "frontend/parser.cpp"
    break;

  case 310: // expr_int: "(" expr_int ")"
#line 651 "frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 2784 "frontend/parser.cpp"
    break;

  case 311: // expr_int: "~" expr_int
#line 652 "frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 2790 "frontend/parser.cpp"
    break;

  case 312: // expr_int: expr_int "*" expr_int
#line 653 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 2796 "frontend/parser.cpp"
    break;

  case 313: // expr_int: expr_int "/" expr_int
#line 654 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 2802 "frontend/parser.cpp"
    break;

  case 314: // expr_int: expr_int "%" expr_int
#line 655 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 2808 "frontend/parser.cpp"
    break;

  case 315: // expr_int: expr_int "-" expr_int
#line 656 "frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 2814 "frontend/parser.cpp"
    break;

  case 316: // expr_int: expr_int "+" expr_int
#line 657 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 2820 "frontend/parser.cpp"
    break;

  case 317: // expr_int: expr_int "<<" expr_int
#line 658 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 2826 "frontend/parser.cpp"
    break;

  case 318: // expr_int: expr_int ">>" expr_int
#line 659 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 2832 "frontend/parser.cpp"
    break;

  case 319: // expr_int: expr_int "&" expr_int
#line 660 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 2838 "frontend/parser.cpp"
    break;

  case 320: // expr_int: expr_int "^" expr_int
#line 661 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 2844 "frontend/parser.cpp"
    break;

  case 321: // expr_int: expr_int "|" expr_int
#line 662 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 2850 "frontend/parser.cpp"
    break;

  case 322: // expr_float: "float"
#line 666 "frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 2856 "frontend/parser.cpp"
    break;

  case 323: // expr_float: "-" expr_float
#line 667 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 2862 "frontend/parser.cpp"
    break;

  case 324: // expr_float: "(" expr_float ")"
#line 668 "frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 2868 "frontend/parser.cpp"
    break;

  case 325: // expr_float: expr_float "**" expr_float
#line 669 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2874 "frontend/parser.cpp"
    break;

  case 326: // expr_float: expr_float "**" expr_int
#line 670 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2880 "frontend/parser.cpp"
    break;

  case 327: // expr_float: expr_int "**" expr_float
#line 671 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2886 "frontend/parser.cpp"
    break;

  case 328: // expr_float: expr_float "*" expr_float
#line 672 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 2892 "frontend/parser.cpp"
    break;

  case 329: // expr_float: expr_float "*" expr_int
#line 673 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 2898 "frontend/parser.cpp"
    break;

  case 330: // expr_float: expr_int "*" expr_float
#line 674 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 2904 "frontend/parser.cpp"
    break;

  case 331: // expr_float: expr_float "/" expr_float
#line 675 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 2910 "frontend/parser.cpp"
    break;

  case 332: // expr_float: expr_float "/" expr_int
#line 676 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 2916 "frontend/parser.cpp"
    break;

  case 333: // expr_float: expr_int "/" expr_float
#line 677 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 2922 "frontend/parser.cpp"
    break;

  case 334: // expr_float: expr_float "%" expr_float
#line 678 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2928 "frontend/parser.cpp"
    break;

  case 335: // expr_float: expr_float "%" expr_int
#line 679 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2934 "frontend/parser.cpp"
    break;

  case 336: // expr_float: expr_int "%" expr_float
#line 680 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2940 "frontend/parser.cpp"
    break;

  case 337: // expr_float: expr_float "-" expr_float
#line 681 "frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 2946 "frontend/parser.cpp"
    break;

  case 338: // expr_float: expr_float "-" expr_int
#line 682 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 2952 "frontend/parser.cpp"
    break;

  case 339: // expr_float: expr_int "-" expr_float
#line 683 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 2958 "frontend/parser.cpp"
    break;

  case 340: // expr_float: expr_float "+" expr_float
#line 684 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 2964 "frontend/parser.cpp"
    break;

  case 341: // expr_float: expr_float "+" expr_int
#line 685 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 2970 "frontend/parser.cpp"
    break;

  case 342: // expr_float: expr_int "+" expr_float
#line 686 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 2976 "frontend/parser.cpp"
    break;

  case 343: // expr_str: "string"
#line 690 "frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2982 "frontend/parser.cpp"
    break;

  case 344: // expr_str: "(" expr_str ")"
#line 691 "frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 2988 "frontend/parser.cpp"
    break;

  case 345: // expr_str: expr_str "++" expr_str
#line 692 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 2994 "frontend/parser.cpp"
    break;

  case 346: // expr_str: expr_str "++" expr_int
#line 693 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 3000 "frontend/parser.cpp"
    break;

  case 347: // expr_str: expr_str "++" expr_float
#line 694 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 3006 "frontend/parser.cpp"
    break;

  case 348: // expr_str: expr_str "++" expr_bool
#line 695 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3012 "frontend/parser.cpp"
    break;

  case 349: // expr_str: expr_str "++" expr_none
#line 696 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 3018 "frontend/parser.cpp"
    break;

  case 350: // expr_str: expr_int "++" expr_str
#line 697 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 3024 "frontend/parser.cpp"
    break;

  case 351: // expr_str: expr_int "++" expr_int
#line 698 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 3030 "frontend/parser.cpp"
    break;

  case 352: // expr_str: expr_int "++" expr_float
#line 699 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 3036 "frontend/parser.cpp"
    break;

  case 353: // expr_str: expr_int "++" expr_bool
#line 700 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3042 "frontend/parser.cpp"
    break;

  case 354: // expr_str: expr_int "++" expr_none
#line 701 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 3048 "frontend/parser.cpp"
    break;

  case 355: // expr_str: expr_float "++" expr_str
#line 702 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 3054 "frontend/parser.cpp"
    break;

  case 356: // expr_str: expr_float "++" expr_int
#line 703 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 3060 "frontend/parser.cpp"
    break;

  case 357: // expr_str: expr_float "++" expr_float
#line 704 "frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 3066 "frontend/parser.cpp"
    break;

  case 358: // expr_str: expr_float "++" expr_bool
#line 705 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3072 "frontend/parser.cpp"
    break;

  case 359: // expr_str: expr_float "++" expr_none
#line 706 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 3078 "frontend/parser.cpp"
    break;

  case 360: // expr_str: expr_bool "++" expr_str
#line 707 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 3084 "frontend/parser.cpp"
    break;

  case 361: // expr_str: expr_bool "++" expr_int
#line 708 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 3090 "frontend/parser.cpp"
    break;

  case 362: // expr_str: expr_bool "++" expr_float
#line 709 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 3096 "frontend/parser.cpp"
    break;

  case 363: // expr_str: expr_bool "++" expr_bool
#line 710 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3102 "frontend/parser.cpp"
    break;

  case 364: // expr_str: expr_bool "++" expr_none
#line 711 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 3108 "frontend/parser.cpp"
    break;

  case 365: // expr_str: expr_none "++" expr_str
#line 712 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 3114 "frontend/parser.cpp"
    break;

  case 366: // expr_str: expr_none "++" expr_int
#line 713 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 3120 "frontend/parser.cpp"
    break;

  case 367: // expr_str: expr_none "++" expr_float
#line 714 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 3126 "frontend/parser.cpp"
    break;

  case 368: // expr_str: expr_none "++" expr_bool
#line 715 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3132 "frontend/parser.cpp"
    break;

  case 369: // expr_str: expr_none "++" expr_none
#line 716 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 3138 "frontend/parser.cpp"
    break;

  case 370: // expr_bool: "bool"
#line 720 "frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 3144 "frontend/parser.cpp"
    break;

  case 371: // expr_bool: "(" expr_bool ")"
#line 721 "frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 3150 "frontend/parser.cpp"
    break;

  case 372: // expr_bool: "not" expr_bool
#line 722 "frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 3156 "frontend/parser.cpp"
    break;

  case 373: // expr_bool: expr_bool "or" expr_bool
#line 723 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 3162 "frontend/parser.cpp"
    break;

  case 374: // expr_bool: expr_bool "and" expr_bool
#line 724 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 3168 "frontend/parser.cpp"
    break;

  case 375: // expr_bool: expr_bool "==" expr_bool
#line 726 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 3174 "frontend/parser.cpp"
    break;

  case 376: // expr_bool: expr_int "==" expr_int
#line 727 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 3180 "frontend/parser.cpp"
    break;

  case 377: // expr_bool: expr_int "==" expr_float
#line 728 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 3186 "frontend/parser.cpp"
    break;

  case 378: // expr_bool: expr_float "==" expr_float
#line 729 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 3192 "frontend/parser.cpp"
    break;

  case 379: // expr_bool: expr_float "==" expr_int
#line 730 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 3198 "frontend/parser.cpp"
    break;

  case 380: // expr_bool: expr_str "==" expr_str
#line 731 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 3204 "frontend/parser.cpp"
    break;

  case 381: // expr_bool: expr_none "==" expr_none
#line 732 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 3210 "frontend/parser.cpp"
    break;

  case 382: // expr_bool: expr_bool "!=" expr_bool
#line 734 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 3216 "frontend/parser.cpp"
    break;

  case 383: // expr_bool: expr_int "!=" expr_int
#line 735 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 3222 "frontend/parser.cpp"
    break;

  case 384: // expr_bool: expr_int "!=" expr_float
#line 736 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 3228 "frontend/parser.cpp"
    break;

  case 385: // expr_bool: expr_float "!=" expr_float
#line 737 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 3234 "frontend/parser.cpp"
    break;

  case 386: // expr_bool: expr_float "!=" expr_int
#line 738 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 3240 "frontend/parser.cpp"
    break;

  case 387: // expr_bool: expr_str "!=" expr_str
#line 739 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 3246 "frontend/parser.cpp"
    break;

  case 388: // expr_bool: expr_none "!=" expr_none
#line 740 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 3252 "frontend/parser.cpp"
    break;

  case 389: // expr_bool: expr_int ">" expr_int
#line 742 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 3258 "frontend/parser.cpp"
    break;

  case 390: // expr_bool: expr_int ">" expr_float
#line 743 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 3264 "frontend/parser.cpp"
    break;

  case 391: // expr_bool: expr_float ">" expr_float
#line 744 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 3270 "frontend/parser.cpp"
    break;

  case 392: // expr_bool: expr_float ">" expr_int
#line 745 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 3276 "frontend/parser.cpp"
    break;

  case 393: // expr_bool: expr_str ">" expr_str
#line 746 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 3282 "frontend/parser.cpp"
    break;

  case 394: // expr_bool: expr_int "<" expr_int
#line 748 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 3288 "frontend/parser.cpp"
    break;

  case 395: // expr_bool: expr_int "<" expr_float
#line 749 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 3294 "frontend/parser.cpp"
    break;

  case 396: // expr_bool: expr_float "<" expr_float
#line 750 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 3300 "frontend/parser.cpp"
    break;

  case 397: // expr_bool: expr_float "<" expr_int
#line 751 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 3306 "frontend/parser.cpp"
    break;

  case 398: // expr_bool: expr_str "<" expr_str
#line 752 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 3312 "frontend/parser.cpp"
    break;

  case 399: // expr_bool: expr_int ">=" expr_int
#line 754 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 3318 "frontend/parser.cpp"
    break;

  case 400: // expr_bool: expr_int ">=" expr_float
#line 755 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 3324 "frontend/parser.cpp"
    break;

  case 401: // expr_bool: expr_float ">=" expr_float
#line 756 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 3330 "frontend/parser.cpp"
    break;

  case 402: // expr_bool: expr_float ">=" expr_int
#line 757 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 3336 "frontend/parser.cpp"
    break;

  case 403: // expr_bool: expr_str ">=" expr_str
#line 758 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 3342 "frontend/parser.cpp"
    break;

  case 404: // expr_bool: expr_int "<=" expr_int
#line 760 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 3348 "frontend/parser.cpp"
    break;

  case 405: // expr_bool: expr_int "<=" expr_float
#line 761 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 3354 "frontend/parser.cpp"
    break;

  case 406: // expr_bool: expr_float "<=" expr_float
#line 762 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 3360 "frontend/parser.cpp"
    break;

  case 407: // expr_bool: expr_float "<=" expr_int
#line 763 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 3366 "frontend/parser.cpp"
    break;

  case 408: // expr_bool: expr_str "<=" expr_str
#line 764 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 3372 "frontend/parser.cpp"
    break;

  case 409: // expr_bool: expr_str "in" expr_str
#line 766 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[0].value.as < std::string > ().find(yystack_[2].value.as < std::string > ()) != std::string::npos; }
#line 3378 "frontend/parser.cpp"
    break;

  case 416: // mattype: "identifier" matsq
#line 780 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3384 "frontend/parser.cpp"
    break;

  case 417: // mattype: "'int'" matsq
#line 781 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(INT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3390 "frontend/parser.cpp"
    break;

  case 418: // mattype: "'float'" matsq
#line 782 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(FLOAT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3396 "frontend/parser.cpp"
    break;

  case 419: // mattype: "'string'" matsq
#line 783 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(STRING_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3402 "frontend/parser.cpp"
    break;

  case 420: // mattype: "'bool'" matsq
#line 784 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(BOOL_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3408 "frontend/parser.cpp"
    break;

  case 421: // mattype: "any" matsq
#line 785 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(ANY_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3414 "frontend/parser.cpp"
    break;

  case 429: // matsq: "[" "]"
#line 794 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(scanner->parseInt(-1)); }
#line 3420 "frontend/parser.cpp"
    break;

  case 430: // matsq: "[" int_val "]"
#line 795 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 3426 "frontend/parser.cpp"
    break;

  case 431: // matsq: "[" "]" matsq
#line 796 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), scanner->parseInt(-1)); }
#line 3432 "frontend/parser.cpp"
    break;

  case 432: // matsq: "[" int_val "]" matsq
#line 797 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[2].value.as < ptc::ir::Expr * > ()); }
#line 3438 "frontend/parser.cpp"
    break;

  case 433: // type: "'int'" "?"
#line 801 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, true, true); }
#line 3444 "frontend/parser.cpp"
    break;

  case 434: // type: "'float'" "?"
#line 802 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, true, true); }
#line 3450 "frontend/parser.cpp"
    break;

  case 435: // type: "'string'" "?"
#line 803 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, true, true); }
#line 3456 "frontend/parser.cpp"
    break;

  case 436: // type: "'bool'" "?"
#line 804 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, true, true); }
#line 3462 "frontend/parser.cpp"
    break;

  case 437: // type: "identifier" "?"
#line 805 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[1].value.as < std::string > (), true, true); }
#line 3468 "frontend/parser.cpp"
    break;

  case 440: // type: mattype "?"
#line 808 "frontend/parser.yy"
       { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 3474 "frontend/parser.cpp"
    break;

  case 441: // type: "'int'"
#line 809 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, false, true); }
#line 3480 "frontend/parser.cpp"
    break;

  case 442: // type: "'float'"
#line 810 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, false, true); }
#line 3486 "frontend/parser.cpp"
    break;

  case 443: // type: "'string'"
#line 811 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, false, true); }
#line 3492 "frontend/parser.cpp"
    break;

  case 444: // type: "'bool'"
#line 812 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, false, true); }
#line 3498 "frontend/parser.cpp"
    break;

  case 445: // type: "any"
#line 813 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(ANY_CSTR, false, true); }
#line 3504 "frontend/parser.cpp"
    break;

  case 446: // type: "identifier"
#line 814 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[0].value.as < std::string > (), false, true); }
#line 3510 "frontend/parser.cpp"
    break;

  case 447: // type: "external identifier"
#line 815 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExtType(yystack_[0].value.as < std::string > (), false); }
#line 3516 "frontend/parser.cpp"
    break;

  case 449: // type: mattype
#line 817 "frontend/parser.yy"
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


  const short  Parser ::yypact_ninf_ = -659;

  const short  Parser ::yytable_ninf_ = -448;

  const short
   Parser ::yypact_[] =
  {
    2193,  -659,  -659,  -659,  -659,  -659,  -659,  -659,  1078,    40,
       4,  1140,  1140,   -34,   138,   105,  -659,   236,  -659,  -659,
    1140,  -659,  -659,   172,    24,    39,    42,    44,   177,     6,
      23,    26,   256,   300,  -659,  -659,    22,    22,  -659,  -659,
    -659,   251,  -659,  2525,  -659,   273,  -659,  -659,    22,    22,
      22,  1750,  2696,  -659,   924,   585,   214,  2857,  2141,   552,
    1095,    61,   220,     8,   303,    27,   308,  1940,   304,   924,
     585,   214,  2806,  1631,  1901,   855,  1140,  -659,    27,  -659,
     239,   474,   474,   511,  -659,  -659,  -659,  -659,    94,  2857,
    2141,   552,  -659,    94,  -659,  1095,   280,   592,  -659,   285,
    -659,   728,  -659,   292,   138,  -659,   138,  -659,   138,  -659,
     138,  -659,   125,  1370,  -659,   330,   488,     2,   138,  -659,
    -659,  -659,   922,  -659,  -659,  -659,  -659,  2680,  -659,  -659,
    -659,  -659,  -659,  1140,   328,  2605,  -659,  -659,   288,  1140,
    -659,  -659,  -659,  1140,  1140,  1140,  1140,  1140,  1140,  1140,
    1140,  1140,  1140,  1140,  1140,  1140,  -659,   845,   922,  1140,
    1140,  1140,  1140,  1140,  1140,  1140,  1140,  1140,  1140,  1140,
    1140,  1140,  1140,  1140,  1140,  1140,  1140,  1140,  1140,  1140,
     302,  -659,   922,  1140,  1140,  1140,  1140,  1140,  1140,  -659,
    1140,  1140,  1140,  1140,  1140,  1140,  1140,  1140,  1140,  1140,
    1140,  1140,  1140,  1140,  1140,  1140,  1140,  1140,  1140,  1140,
    1140,  1140,  1140,  1140,  1140,  1140,  1140,  1140,  1140,  1140,
    1140,  1140,  1140,  1140,  1140,  1140,  1140,  1140,  1140,  1140,
    1140,  1140,  1140,  1140,  1140,  1140,  1140,  1140,  1140,  1140,
    1140,  1140,  1140,  1140,  1140,   138,  -659,  -659,  1559,    78,
     343,  -659,   922,   358,  -659,  -659,  -659,  -659,  -659,  -659,
     240,   363,  -659,    54,  2216,  1300,   511,   511,  -659,   474,
     474,   474,   474,   474,   474,   511,   511,   511,   511,   511,
     474,   474,   474,   474,   474,   474,  1140,   138,  2696,   368,
    2857,   105,   401,    56,   104,   377,     9,  1140,  -659,  -659,
    -659,  -659,   478,    65,  -659,    75,   414,   477,    92,  1212,
     502,   106,  -659,   422,   505,  -659,   107,  -659,   506,  2680,
    -659,  2317,   513,   515,  -659,  1983,  -659,  -659,  -659,  -659,
    -659,  -659,  -659,  -659,  -659,  -659,  -659,  -659,  -659,    66,
    -659,   132,   276,   129,   457,   691,   276,   129,   457,   691,
     301,   512,   516,   517,   301,   516,   517,   301,   516,   517,
     301,   516,   517,  1977,   265,  2880,  2972,   621,  1148,  2475,
     311,  2275,   295,  1748,   349,  2778,  2949,  2749,  2903,  2062,
    2926,   825,  1438,   825,  1438,  1314,   559,  -659,  -659,  1688,
     608,   312,  -659,  1314,   559,  -659,  -659,  1688,   608,   312,
    -659,   764,   714,  1463,   534,   764,   714,  1463,   534,   764,
     714,  1463,   534,   764,   714,  1463,   534,  -659,  -659,   237,
     276,   129,   276,   129,   301,   512,  1748,   469,  1314,   559,
    1314,   559,  1977,   265,  2880,  2972,   621,  1148,  1748,   469,
    1314,  -659,  1314,  -659,  1748,   469,  1314,  -659,  1314,  -659,
     276,   457,   691,   276,   457,   691,   301,   516,   517,   301,
     516,   517,   301,   516,   517,   301,   517,  1977,   265,  2880,
    2972,   621,  1148,  1748,   469,  2778,  2949,  2749,  2903,  2062,
    2926,   825,  1438,   825,  1438,  1314,  1688,   608,  1314,  1688,
     608,   764,   714,  1463,   764,   714,  1463,   764,   714,  1463,
     764,   714,  1463,   276,   457,   691,   276,   457,   691,   301,
     516,   517,   301,   516,   517,   301,   516,   517,   301,   516,
     517,  1977,   265,  2880,  2972,   621,  1148,  1748,   469,  1314,
    1688,   608,  1314,  1688,   608,   764,   714,  1463,   764,   714,
    1463,   764,   714,  1463,   764,   714,  1463,   537,  1977,   265,
    2880,  2972,   621,  1148,  1748,   469,   349,  1314,   312,  1314,
     312,   764,   534,   764,   534,   764,   534,   764,   534,  1977,
     265,  2880,  2972,   621,  1148,  2475,   311,  2275,   295,  1748,
     469,  1314,  -659,  1314,  -659,  -659,  -659,   541,  1014,  1601,
     242,  -659,   540,  -659,  -659,  1140,  -659,  2332,  -659,   511,
     511,   511,   511,   511,   797,   935,   797,   935,   533,   547,
     533,   547,   533,   547,  2540,   547,  1031,  1795,   893,   810,
     810,   797,   935,   797,   935,   533,   547,   533,   547,   533,
     547,   533,   547,  -659,  -659,   138,  -659,  1507,  1507,  1507,
    -659,  -659,   485,   485,  -659,   492,   546,   566,    12,  -659,
    1826,   278,   496,   542,   570,    14,  -659,  1028,   243,    28,
     891,   560,  -659,  -659,  2525,  2397,   580,  1140,  2525,  -659,
    1140,  -659,  -659,  -659,  -659,  -659,  -659,   278,   595,  -659,
    -659,  -659,   108,   108,  -659,  -659,  -659,  -659,  1536,   597,
    2116,   599,   315,  2834,   601,   602,   603,   605,   620,  -659,
     594,  -659,   485,   609,  -659,  -659,  -659,   261,   278,  -659,
    -659,   625,  -659,  1185,  -659,  1354,   245,  1140,  -659,   638,
    -659,   637,   590,  -659,  -659,   278,  1940,   649,  2806,  2525,
    2525,  1140,  1140,  2525,  2525,  2525,  2525,  -659,  1140,  -659,
    1140,   586,    17,  -659,  -659,  -659,   651,  -659,   654,  -659,
    1393,   627,  -659,  -659,  -659,  -659,  2525,  -659,  -659,  -659,
    -659,  -659,  -659,  -659,   623,  -659,  -659,  -659,  -659,  -659,
    -659,  -659,  -659,  -659,  -659,  -659,   658,   633,  -659,  1140,
    -659,  -659,  -659
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     9,   308,   322,   343,   370,   300,     0,     0,
       0,     0,     0,     0,   445,     0,    53,     0,    47,    49,
      38,    35,    36,     0,   441,   442,   443,   444,     0,     0,
     104,   105,     0,     0,     4,    10,     0,     0,    37,    15,
      17,     0,    18,     0,    16,     0,    19,    20,     0,     0,
       0,     0,    97,   281,    96,    98,    99,   100,   101,   102,
     103,   448,   449,     0,   300,   104,   105,     0,   281,     0,
       0,     0,     0,     0,     0,     0,     0,   273,   104,   278,
       0,     0,     0,     0,   106,   107,   309,   323,   260,     0,
       0,     0,   372,   261,   311,     0,     0,     0,   421,    33,
      32,     0,    39,     0,   433,   417,   434,   418,   435,   419,
     436,   420,     0,     0,    69,     0,     0,     0,   437,   117,
     302,   416,     0,   438,   118,     1,     3,     0,     5,     8,
       7,    14,    21,     0,     0,     0,    30,    31,     0,     0,
      12,    13,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   119,     0,     0,     0,     0,     0,     0,     0,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   439,   422,   440,     0,    75,
       0,   301,     0,   302,   108,   282,   310,   324,   344,   371,
       0,     0,   274,     0,     0,     0,     0,     0,   311,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   429,   287,     0,
     286,     0,     0,   446,   447,     0,     0,     0,   424,   425,
     426,   427,     0,     0,   413,   446,   447,     0,   414,     0,
       0,     0,   304,     0,     0,   423,     0,     6,     0,     0,
      23,     0,     0,     0,    93,    92,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,   109,     0,
      94,     0,   152,   150,   147,   148,   160,   158,   155,   156,
     134,   133,   129,   130,   139,   137,   138,   144,   142,   143,
     124,   126,   123,   272,   271,   267,   268,   269,   270,   256,
     255,   259,   258,   253,   252,   231,   230,   237,   236,   234,
     233,   163,   162,   166,   165,   211,   209,   206,   207,   202,
     203,   204,   205,   228,   226,   223,   224,   219,   220,   221,
     222,   173,   170,   171,   172,   187,   184,   185,   186,   180,
     177,   178,   179,   194,   191,   192,   193,   120,   121,     0,
     151,   149,   159,   157,   132,   131,   251,   244,   210,   208,
     227,   225,   266,   369,   366,   367,   365,   368,   249,   242,
     199,   381,   216,   388,   250,   243,   201,   200,   218,   217,
     145,   316,   342,   153,   315,   339,   127,   312,   330,   135,
     313,   333,   140,   314,   336,   125,   327,   262,   354,   351,
     352,   350,   353,   245,   238,   229,   319,   235,   321,   232,
     320,   161,   317,   164,   318,   195,   376,   377,   212,   383,
     384,   167,   389,   390,   181,   394,   395,   174,   399,   400,
     188,   404,   405,   146,   341,   340,   154,   338,   337,   128,
     329,   328,   136,   332,   331,   141,   335,   334,   122,   326,
     325,   263,   359,   356,   357,   355,   358,   246,   239,   196,
     379,   378,   213,   386,   385,   168,   392,   391,   182,   397,
     396,   175,   402,   401,   189,   407,   406,     0,   264,   349,
     346,   347,   345,   348,   247,   240,   409,   197,   380,   214,
     387,   169,   393,   183,   398,   176,   403,   190,   408,   265,
     364,   361,   362,   360,   363,   254,   374,   257,   373,   248,
     241,   198,   375,   215,   382,   428,   411,     0,     0,     0,
       0,   303,     0,   275,   276,     0,   279,     0,   309,     0,
       0,     0,     0,     0,   316,   342,   315,   339,   312,   330,
     313,   333,   314,   336,     0,   327,   319,   321,   320,   317,
     318,   341,   340,   338,   337,   329,   328,   332,   331,   335,
     334,   326,   325,    79,   431,   430,    34,     0,     0,     0,
      75,    78,     0,    58,    55,     0,     0,     0,     0,   412,
       0,     0,     0,    74,     0,     0,   288,     0,     0,   113,
       0,     0,   305,   114,     0,     0,    24,     0,     0,   110,
       0,   115,   112,   111,   410,    77,    76,     0,     0,   113,
     277,   280,   316,   315,   312,   313,   314,   432,     0,     0,
     287,     0,     0,   286,     0,     0,     0,     0,     0,    59,
       0,    56,    60,    62,   415,    67,    72,     0,     0,    70,
     292,     0,   290,     0,   289,     0,     0,     0,    46,    25,
      26,     0,    52,    95,    65,     0,   287,     0,   286,     0,
       0,     0,     0,     0,     0,     0,     0,    57,     0,    61,
       0,     0,     0,    68,   295,   294,     0,   293,     0,   291,
       0,   306,    27,    48,    54,    50,     0,    66,   283,    28,
      29,    41,    44,   284,     0,    42,    45,    40,    43,    64,
      63,    73,    71,   298,   297,   296,     0,     0,    51,     0,
     299,   307,   285
  };

  const short
   Parser ::yypgoto_[] =
  {
    -659,  -659,   -81,   484,   -32,    57,   -29,   379,  -658,  -659,
     383,  -659,  -659,  -659,  -659,  -659,  -659,  -659,  -659,  -659,
    -659,  -659,  -659,  -631,  -659,  -659,   612,  -659,    87,   577,
    -659,   551,  -659,  1091,   229,    16,   630,  1152,  -611,   408,
    1065,  1701,  1909,   -60,   -58,    -8,   538,   838,  1452,  -659,
    -241,  -659,     5,   241
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    32,    33,   131,    34,    35,   760,   761,   138,    36,
     100,    37,    38,    39,    40,    41,    42,    43,    44,   755,
      45,   756,    46,   646,   647,    47,   115,   653,   654,    48,
      49,    50,   339,    51,    52,    53,    80,    69,   691,   692,
     181,    70,    71,   120,   314,    57,    90,    91,    95,    61,
     307,    62,   121,    63
  };

  const short
   Parser ::yytable_[] =
  {
      72,   128,    86,    89,    94,   253,   718,   587,     3,     4,
     722,   698,   699,    81,   137,   113,   312,   248,   248,    98,
      82,   248,   129,   248,    68,   130,   248,   695,   697,   105,
     107,   109,   111,    83,   116,    97,   117,   122,   252,    97,
     117,   313,    96,    76,     3,     4,     5,     6,     7,     8,
      97,     9,    77,    97,   321,    97,    10,   595,     3,     4,
       5,     6,     7,     8,    11,     9,   246,    97,   643,    12,
      10,   739,    97,   264,    86,   268,   669,   727,    11,   644,
      84,    85,   114,    12,   249,   640,    97,   -69,   703,   290,
     709,   118,   104,   772,   123,   317,  -430,   637,   778,  -446,
     136,   248,  -447,   157,  -430,   158,   670,   106,   290,   298,
     108,   299,   110,   300,   290,   301,    78,    66,   659,   663,
     588,   645,    14,   315,   118,   601,   602,   603,   302,   245,
      78,    66,   650,   180,    24,    25,    26,    27,   303,   292,
     182,   305,   306,   118,   671,   638,   185,   660,   660,    97,
     290,   344,   348,   352,   355,   358,   361,   365,    89,    89,
      89,   376,   378,   380,   382,   384,   389,   397,   402,   406,
     410,   414,   123,   660,   290,    89,    89,    89,    89,    89,
      89,    99,   434,    89,    89,    89,    89,    89,    89,   451,
     454,   457,   460,   463,    89,   469,    89,   476,   478,   480,
     482,   484,   486,   489,   492,   495,   498,   501,   504,   507,
     510,   513,   516,   519,   523,    89,   530,   533,   536,   539,
     542,   545,   290,   550,    89,    89,    89,    89,    89,    89,
      89,   571,    89,    89,    89,    89,    89,    67,   665,   194,
      88,    93,   261,   592,   290,   101,   195,   196,   103,   672,
     585,   262,   593,   112,   679,   712,   125,   749,   597,   598,
     133,   604,   606,   608,   610,   612,   614,   616,   617,   618,
     619,   620,   621,   623,   625,   627,   629,   631,   660,   263,
     263,   134,   139,   660,   713,   157,   750,   158,   247,   128,
     191,   135,   634,   161,   162,   163,   164,   192,   193,   741,
     126,   127,   290,     2,     3,     4,     5,     6,     7,     8,
     157,     9,   158,   251,   255,   180,    10,   240,    14,   122,
     242,   164,   286,   230,    11,   291,   288,   243,   244,    12,
      24,    25,    26,    27,   297,   292,   242,   305,   306,   309,
     180,   319,   296,   243,   244,   288,   235,   236,   237,   238,
     322,   288,   589,   731,   308,   732,    13,    14,    15,    16,
     230,    17,    18,    19,    20,    21,    22,    23,   591,    24,
      25,    26,    27,    28,    29,   594,    30,    31,   417,   418,
     635,   233,   234,   235,   236,   237,   238,   288,   342,   346,
     350,   354,   357,   360,   363,   369,   371,   373,   375,   377,
     379,   381,   383,   385,   393,   401,   405,   409,   413,   704,
     113,   288,   420,   422,   424,   426,   428,   430,   639,   432,
     438,   440,   442,   444,   446,   448,   450,   453,   456,   459,
     462,   465,   467,   473,   475,   477,   479,   481,   483,   485,
     488,   491,   494,   497,   500,   503,   506,   509,   512,   515,
     518,   521,   527,   529,   532,   535,   538,   541,   544,   288,
     548,   554,   557,   559,   561,   563,   565,   567,   569,   575,
     577,   579,   581,   583,   199,   200,   201,   202,     3,     4,
     182,   288,   123,    81,   183,   184,   185,   649,   643,   308,
      82,   642,     3,     4,     5,     6,     7,     8,   661,     9,
     287,   187,   188,    83,    10,   289,     3,     4,     5,     6,
       7,     8,    11,     9,   656,     3,   664,    12,    10,   662,
     266,   132,   667,   182,   311,   668,    11,   267,   676,   310,
     316,    12,   140,   141,   142,   156,   202,   221,    58,   288,
      83,   645,    14,   657,   648,   230,    73,    58,    87,   673,
     655,   674,   680,   274,    24,    25,    26,    27,    58,   292,
     701,   305,   306,   230,    78,    66,   341,   285,   700,   702,
     182,    58,   706,   231,   183,   184,   185,   232,    78,    66,
     708,    58,   707,   720,   233,   234,   235,   236,   237,   238,
     419,   682,   683,   684,   685,   686,     3,     4,     5,     6,
       7,     8,   717,     9,   287,   725,   190,   729,    10,   730,
     191,   733,   734,   735,    58,   736,    11,   192,   193,   265,
      87,    12,   705,   216,   217,   218,   219,   220,   221,   693,
     693,   693,   230,   128,   737,   137,   738,   744,   547,   137,
     687,   752,   226,   227,   228,   229,   232,   753,   724,   290,
     754,   740,   290,   233,   234,   235,   236,   237,   238,   758,
     590,   779,   771,   773,   687,    58,   774,   777,    78,    66,
     780,    58,   313,    58,   636,   250,   678,    58,   295,   743,
     728,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,   324,    58,   757,   345,   349,   353,
     356,   359,   362,   366,    68,   290,   260,   290,   218,   219,
     220,   221,   390,   398,   403,   407,   411,   415,   658,   781,
       0,   136,     0,   290,   290,   136,     0,   137,   435,   197,
     198,   199,   200,   201,   202,   452,   455,   458,   461,   464,
     466,   470,   290,     0,   208,   209,     0,     0,   487,   490,
     493,   496,   499,   502,   505,   508,   511,   514,   517,   520,
     524,     0,   531,   534,   537,   540,   543,   546,     0,   551,
       0,   290,     0,   157,     0,   158,     0,   572,     0,   159,
     160,   161,   162,   163,   164,    14,   759,   759,     0,     0,
     759,   759,   759,   759,   172,   173,     0,    24,    25,    26,
      27,    58,   292,   180,   293,   294,     0,   605,   607,   609,
     611,   613,   615,   136,   271,   272,   273,   274,   622,   624,
     626,   628,   630,   632,    58,   599,   600,   601,   602,   603,
     655,     0,     0,     0,   157,    58,   158,     0,    59,     0,
     159,   160,   161,   162,   163,   164,    74,    59,     0,     3,
       4,     5,     6,     7,     8,   338,     9,    58,    59,    58,
       0,    10,     0,     0,   180,   259,   690,   690,   690,    11,
       0,    59,     0,     0,    12,     0,   239,   240,   241,     0,
     242,    59,     0,   648,   648,     0,   288,   243,   244,   288,
       0,   308,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     0,     9,   714,     0,     0,     0,    10,   599,   600,
     601,   602,   603,     0,    59,    11,     0,   726,     0,   275,
      12,    78,    66,   278,   279,     0,     3,     4,     5,     6,
       7,     8,   715,     9,     0,   182,     0,     0,    10,   183,
     184,   185,   288,   648,   288,     0,    11,     0,   742,   186,
       0,    12,   282,   283,   284,   285,   187,   188,     0,     0,
     288,   288,     0,   310,     0,    59,     0,    78,    66,     0,
       0,    59,     0,    59,     0,     0,     0,    59,     0,   288,
       0,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,     0,    59,     0,     0,    78,    66,
       0,     0,     0,   367,     0,     0,   374,     0,   288,     0,
       0,     0,   391,   399,   404,   408,   412,   416,     3,     4,
       5,     6,     7,     8,     0,     9,     0,   117,   436,     0,
      10,     0,     3,     4,     5,     6,     7,     8,    11,     9,
     710,   471,     0,    12,    10,     0,   599,   600,   601,   602,
     603,     0,    11,     0,     0,     0,     0,    12,     0,     0,
     525,   278,   279,     0,     0,   711,     0,     0,   716,   552,
     556,   558,   560,   562,   564,   566,   568,   573,     0,     0,
       0,     0,     3,     4,     5,     6,    64,     8,     0,     9,
      78,    66,     0,     0,    10,   119,   124,     0,     0,     0,
      79,    59,    11,     0,    78,    66,     0,    12,     0,   762,
       0,   102,   765,   766,   767,   768,   239,   240,   241,   189,
     242,   746,     0,   748,    59,     0,    58,   243,   244,     0,
     119,   124,     0,    58,   189,    59,     0,     0,     0,   763,
     764,     0,     0,   119,     3,     4,     5,     6,     7,     8,
       0,     9,    54,     0,    65,    66,    10,    59,   776,    59,
       0,    54,     0,     0,    11,     0,     0,    79,     0,    12,
     240,   241,    54,   242,     0,    58,    58,    58,     0,     0,
     243,   244,     0,     0,     0,    54,     0,   782,     0,     3,
       4,     5,     6,     7,     8,    54,     9,   745,     0,     0,
       0,    10,    58,    58,     0,    58,    58,     0,    58,    11,
       0,     0,     0,     0,    12,     0,    78,    66,     0,     0,
       0,     0,   651,     0,   318,     0,    73,     0,    54,     0,
     323,     0,     0,     0,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,     0,   340,     0,
     652,     0,     0,     0,     0,    58,     0,     0,     0,     0,
       0,    78,    66,     0,     0,     0,     0,    58,    58,    14,
       0,    58,    58,    58,    58,     0,    58,     0,    58,    54,
       0,    24,    25,    26,    27,    54,   292,    54,   305,   306,
       0,    54,     0,     0,    58,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,     0,    54,
     257,   343,   347,   351,     0,   280,   281,   282,   283,   284,
     285,     0,     0,   157,     0,   158,   386,   394,     0,   159,
     160,   161,   162,   163,   164,   421,   423,   425,   427,   429,
     431,     0,     0,   439,   172,   173,   445,     0,   176,   177,
     178,   179,     0,   180,   596,     0,   474,     0,     3,     4,
       5,     6,     7,     8,     0,     9,   747,     0,     0,     0,
      10,     0,     0,     0,     0,   528,     0,   633,    11,     0,
     304,     0,     0,    12,   555,     0,     0,     0,   641,     0,
       0,     0,     0,     0,   580,     0,     0,     3,     4,     5,
       6,     7,     8,     0,     9,   775,     0,     0,   189,    10,
       0,     0,   189,     0,     0,    54,   189,    11,     0,     0,
       0,     0,    12,     0,     0,     0,    59,    14,     0,     0,
      78,    66,     0,    59,     0,     0,     0,     0,    54,    24,
      25,    26,    27,     0,   292,     0,   305,   306,     0,    54,
       0,   189,    60,   197,   198,   199,   200,   201,   202,   189,
      75,    60,     0,    92,     0,     0,     0,     0,     0,    78,
      66,    54,    60,    54,     0,    59,    59,    59,   216,   217,
     218,   219,   220,   221,     0,    60,   189,     0,   189,     0,
     189,     0,   189,     0,   189,    60,   189,     0,     0,     0,
       0,     0,    59,    59,   189,    59,    59,     0,    59,     0,
     189,     3,     4,     5,     6,     7,   688,     0,     9,     0,
       0,     0,     0,    10,     0,     0,    74,     0,    60,     0,
       0,    11,     0,     0,     0,     0,    12,     0,     0,   189,
       3,     4,     5,     6,    64,   688,     0,     9,     0,     0,
       0,     0,    10,     0,     0,    59,     0,     0,     0,     0,
      11,     0,     0,     0,     0,    12,     0,    59,    59,   586,
       0,    59,    59,    59,    59,     0,    59,     0,    59,    60,
       0,     0,     0,    78,    66,    60,     0,    60,     0,     0,
       0,    60,     0,   189,    59,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,     0,    60,
       0,   677,    65,    66,     0,     0,    14,   368,   370,   372,
     189,     0,     0,     0,     0,     0,   392,   400,    24,    25,
      26,    27,     0,   292,     0,   305,   306,     0,     0,   652,
       0,   257,   437,     0,     0,   189,   216,   217,   218,   219,
     220,   221,   222,     0,     0,   472,   223,     0,    14,     0,
       0,     0,     0,   224,   225,   226,   227,   228,   229,     0,
      24,    25,    26,    27,   526,   292,     0,   305,   306,   675,
       0,     0,     0,   553,     0,     0,   681,     0,     0,     0,
       0,   574,   576,   578,     0,   582,   584,     0,     0,     0,
       0,    55,     0,   197,   198,   199,   200,   201,   202,     0,
      55,     0,     0,     0,     0,    60,     0,     0,   208,   209,
       0,    55,   212,   213,   214,   215,     0,     0,   689,   694,
     696,     0,     0,     0,    55,     0,     0,     0,    60,     0,
      54,     0,     0,     0,    55,     0,     0,    54,     0,    60,
     129,     0,     0,   130,     0,     0,     0,   157,   721,   158,
       0,   723,     0,   159,   160,   161,   162,   163,   164,     0,
       0,    60,     0,    60,   169,   170,   171,    55,   172,   173,
     174,   175,   176,   177,   178,   179,     0,   180,     0,    54,
      54,    54,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,     0,   154,   155,     0,     0,   751,     0,
     599,   600,   601,   602,   603,     0,    54,    54,     0,    54,
      54,   275,    54,   277,     0,   278,   279,     0,    55,   769,
       0,   770,     0,     0,    55,     0,    55,     0,     0,     0,
      55,     0,     0,     0,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,     0,    55,     0,
       0,     0,     0,     0,     0,     0,   364,     0,     0,    54,
       0,     0,     0,     0,     0,   387,   395,     0,     0,     0,
       0,    54,    54,    14,     0,    54,    54,    54,    54,     0,
      54,   433,    54,   441,   443,    24,    25,    26,    27,     0,
     292,     0,   305,   306,   468,     0,     0,     0,    54,    56,
       0,   258,   230,     0,     0,     0,     0,     0,    56,     0,
       0,     0,   231,   522,     0,     0,   232,     0,     0,    56,
       0,     0,   549,   233,   234,   235,   236,   237,   238,     0,
     570,     0,    56,     0,     0,     0,     0,     0,     0,   157,
     254,   158,    56,     0,     0,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    55,   168,   169,   170,   171,     0,
     172,   173,   174,   175,   176,   177,   178,   179,     0,   180,
       0,     0,     0,     0,     0,    56,   157,    55,   158,     0,
       0,     0,   159,   160,   161,   162,   163,   164,    55,   166,
     167,     0,   168,   169,   170,   171,     0,   172,   173,   174,
     175,   176,   177,   178,   179,     0,   180,     0,     0,     0,
      55,     0,    55,     0,     0,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,    56,   154,   155,     0,
      60,     0,    56,     0,    56,     0,     0,    60,    56,     0,
       0,     0,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,     0,    56,     0,     0,     0,
       0,   157,     0,   158,     0,     0,     0,   159,   160,   161,
     162,   163,   164,   388,   396,     0,     0,     0,   169,    60,
      60,    60,   172,   173,   174,   175,   176,   177,   178,   179,
       0,   180,     0,     0,   447,   449,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    60,    60,     0,    60,
      60,     0,    60,     0,     0,   157,   -97,   158,     0,     0,
       0,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      75,   168,   169,   170,   171,     0,   172,   173,   174,   175,
     176,   177,   178,   179,     0,   180,   216,   217,   218,   219,
     220,   221,   222,     0,     0,     0,   223,     0,     0,    60,
       0,     0,    56,   224,   225,   226,   227,   228,   229,     0,
       0,    60,    60,     0,     0,    60,    60,    60,    60,     0,
      60,     0,    60,     1,     0,    56,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,    56,     0,    60,    10,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     0,
       0,     0,    12,     0,     0,     0,   256,     0,    56,     0,
      56,   269,   270,   271,   272,   273,   274,     0,     0,     0,
       0,     0,   275,   276,   277,     0,   278,   279,     0,    13,
      14,    15,    16,     0,    17,    18,    19,    20,    21,    22,
      23,     0,    24,    25,    26,    27,    28,    29,     0,    30,
      31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   157,     0,   158,     0,     0,    55,
     159,   160,   161,   162,   163,   164,    55,   166,     0,     0,
     168,   169,   170,   171,     0,   172,   173,   174,   175,   176,
     177,   178,   179,     0,   180,     0,     0,     0,   127,     0,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,   666,     0,    10,     0,     0,     0,     0,    55,    55,
      55,    11,   256,     0,     0,     0,    12,   599,   600,   601,
     602,   603,     0,     0,     0,     0,     0,     0,   275,   276,
     277,     0,   278,   279,     0,    55,    55,     0,    55,    55,
       0,    55,     0,    13,    14,    15,    16,     0,    17,    18,
      19,    20,    21,    22,    23,     0,    24,    25,    26,    27,
      28,    29,     0,    30,    31,     0,     0,     0,   127,     0,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,   719,     0,    10,     0,     0,     0,     0,    55,     0,
       0,    11,     0,     0,     0,     0,    12,     0,     0,     0,
      55,    55,     0,     0,    55,    55,    55,    55,     0,    55,
       0,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    14,    15,    16,    55,    17,    18,
      19,    20,    21,    22,    23,     0,    24,    25,    26,    27,
      28,    29,     0,    30,    31,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   157,     0,   158,     0,     0,     0,
     159,   160,   161,   162,   163,   164,     0,    56,     0,     0,
     168,   169,   170,   171,    56,   172,   173,   174,   175,   176,
     177,   178,   179,     0,   180,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   134,     3,
       4,     5,     6,     7,     8,     0,     9,     0,   135,     0,
       0,    10,     0,     0,     0,     0,    56,    56,    56,    11,
       0,     0,     0,     0,    12,   269,   270,   271,   272,   273,
     274,     0,     0,     0,     0,     0,   275,   276,   277,     0,
     278,   279,     0,    56,    56,     0,    56,    56,     0,    56,
       0,    13,    14,    15,    16,     0,    17,    18,    19,    20,
      21,    22,    23,     0,    24,    25,    26,    27,    28,    29,
       0,    30,    31,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,   320,
       0,    10,     0,     0,     0,     0,    56,     0,     0,    11,
       0,     0,     0,     0,    12,     0,     0,     0,    56,    56,
       0,     0,    56,    56,    56,    56,     0,    56,     0,    56,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13,    14,    15,    16,    56,    17,    18,    19,    20,
      21,    22,    23,     0,    24,    25,    26,    27,    28,    29,
       0,    30,    31,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,     0,     0,    10,     0,     0,     0,
       0,     0,     0,     0,    11,   157,     0,   158,     0,    12,
       0,   159,   160,   161,   162,   163,   164,   165,   166,   167,
       0,   168,   169,   170,   171,     0,   172,   173,   174,   175,
     176,   177,   178,   179,     0,   180,    13,    14,    15,    16,
       0,    17,    18,    19,    20,    21,    22,    23,     0,    24,
      25,    26,    27,    28,    29,     0,    30,    31,   157,     0,
     158,     0,     0,     0,   159,   160,   161,   162,   163,   164,
       0,     0,     0,     0,     0,   169,     0,   171,     0,   172,
     173,   174,   175,   176,   177,   178,   179,   157,   180,   158,
       0,     0,     0,   159,   160,   161,   162,   163,   164,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   172,   173,
     174,   175,   176,   177,   178,   179,   256,   180,     0,     0,
       0,   197,   198,   199,   200,   201,   202,   203,     0,     0,
       0,   204,   205,   206,   207,     0,   208,   209,   210,   211,
     212,   213,   214,   215,  -100,     0,     0,     0,     0,   197,
     198,   199,   200,   201,   202,   203,     0,     0,     0,   204,
     205,   206,   207,     0,   208,   209,   210,   211,   212,   213,
     214,   215,   197,   198,   199,   200,   201,   202,   203,     0,
       0,     0,   204,   205,   206,   207,     0,   208,   209,   210,
     211,   212,   213,   214,   215,   197,   198,   199,   200,   201,
     202,     0,     0,     0,     0,   204,   205,   206,   207,     0,
     208,   209,   210,   211,   212,   213,   214,   215,   197,   198,
     199,   200,   201,   202,     0,     0,     0,     0,     0,   205,
       0,   207,     0,   208,   209,   210,   211,   212,   213,   214,
     215,   197,   198,   199,   200,   201,   202,     0,     0,     0,
       0,     0,   205,     0,     0,     0,   208,   209,   210,   211,
     212,   213,   214,   215,   197,   198,   199,   200,   201,   202,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,     0,     0,     0,     0,   223,     0,     0,
       0,     0,     0,     0,   224,   225,   226,   227,   228,   229
  };

  const short
   Parser ::yycheck_[] =
  {
       8,    33,    10,    11,    12,    65,   664,   248,     4,     5,
     668,   642,   643,     9,    43,     9,    14,     9,     9,    14,
      16,     9,     0,     9,     8,     3,     9,   638,   639,    24,
      25,    26,    27,    29,    11,    11,    13,    11,    11,    11,
      13,    39,    76,     3,     4,     5,     6,     7,     8,     9,
      11,    11,    12,    11,   135,    11,    16,     3,     4,     5,
       6,     7,     8,     9,    24,    11,    61,    11,     3,    29,
      16,   702,    11,    81,    82,    83,    10,   688,    24,    14,
      76,    77,    76,    29,    76,    76,    11,     9,    76,    97,
      76,    68,    68,    76,    68,   127,    68,    41,   756,    76,
      43,     9,    76,     9,    76,    11,    40,    68,   116,   104,
      68,   106,    68,   108,   122,   110,    76,    77,    12,    12,
      42,    56,    57,   118,    68,    17,    18,    19,     3,    68,
      76,    77,    40,    39,    69,    70,    71,    72,    13,    74,
      11,    76,    77,    68,    12,    41,    17,    41,    41,    11,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,    68,    41,   182,   183,   184,   185,   186,   187,
     188,    76,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,     8,   319,    25,
      11,    12,     3,     3,   252,     9,    32,    33,    76,    12,
     245,    12,    12,    76,    12,    12,     0,    12,   266,   267,
       9,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,    41,    40,
      40,     3,     9,    41,    41,     9,    41,    11,    68,   321,
      25,    13,   287,    17,    18,    19,    20,    32,    33,    38,
       0,     1,   310,     3,     4,     5,     6,     7,     8,     9,
       9,    11,    11,    10,    10,    39,    16,    22,    57,    11,
      25,    20,    42,    11,    24,    40,    97,    32,    33,    29,
      69,    70,    71,    72,    42,    74,    25,    76,    77,     9,
      39,    13,   101,    32,    33,   116,    34,    35,    36,    37,
      62,   122,     9,    38,   113,    40,    56,    57,    58,    59,
      11,    61,    62,    63,    64,    65,    66,    67,    10,    69,
      70,    71,    72,    73,    74,    12,    76,    77,    76,    77,
      12,    32,    33,    34,    35,    36,    37,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   650,
       9,   182,   183,   184,   185,   186,   187,   188,    41,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,    17,    18,    19,    20,     4,     5,
      11,   252,    68,     9,    15,    16,    17,    10,     3,   248,
      16,    13,     4,     5,     6,     7,     8,     9,    76,    11,
      12,    32,    33,    29,    16,    97,     4,     5,     6,     7,
       8,     9,    24,    11,    12,     4,    10,    29,    16,    14,
       9,    37,     9,    11,   116,    10,    24,    16,   588,    41,
     122,    29,    48,    49,    50,    51,    20,    20,     0,   310,
      29,    56,    57,    41,   303,    11,     8,     9,    10,    12,
     309,    10,    12,    20,    69,    70,    71,    72,    20,    74,
      14,    76,    77,    11,    76,    77,   158,    20,    76,     3,
      11,    33,    76,    21,    15,    16,    17,    25,    76,    77,
      10,    43,    40,     3,    32,    33,    34,    35,    36,    37,
     182,   599,   600,   601,   602,   603,     4,     5,     6,     7,
       8,     9,    42,    11,    12,    10,    21,    10,    16,    10,
      25,    10,    10,    10,    76,    10,    24,    32,    33,    81,
      82,    29,   651,    15,    16,    17,    18,    19,    20,   637,
     638,   639,    11,   665,    14,   664,    42,    12,   230,   668,
     635,     3,    34,    35,    36,    37,    25,    10,   677,   657,
      60,    42,   660,    32,    33,    34,    35,    36,    37,    10,
     252,    38,    76,    12,   659,   127,    12,    40,    76,    77,
      12,   133,    39,   135,   291,    63,   589,   139,   101,   708,
     688,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   143,   157,   725,   159,   160,   161,
     162,   163,   164,   165,   688,   713,    76,   715,    17,    18,
      19,    20,   174,   175,   176,   177,   178,   179,   310,   777,
      -1,   664,    -1,   731,   732,   668,    -1,   756,   190,    15,
      16,    17,    18,    19,    20,   197,   198,   199,   200,   201,
     202,   203,   750,    -1,    30,    31,    -1,    -1,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,   224,   225,   226,   227,   228,   229,    -1,   231,
      -1,   779,    -1,     9,    -1,    11,    -1,   239,    -1,    15,
      16,    17,    18,    19,    20,    57,   729,   730,    -1,    -1,
     733,   734,   735,   736,    30,    31,    -1,    69,    70,    71,
      72,   263,    74,    39,    76,    77,    -1,   269,   270,   271,
     272,   273,   274,   756,    17,    18,    19,    20,   280,   281,
     282,   283,   284,   285,   286,    15,    16,    17,    18,    19,
     589,    -1,    -1,    -1,     9,   297,    11,    -1,     0,    -1,
      15,    16,    17,    18,    19,    20,     8,     9,    -1,     4,
       5,     6,     7,     8,     9,    10,    11,   319,    20,   321,
      -1,    16,    -1,    -1,    39,    10,   637,   638,   639,    24,
      -1,    33,    -1,    -1,    29,    -1,    21,    22,    23,    -1,
      25,    43,    -1,   642,   643,    -1,   657,    32,    33,   660,
      -1,   650,    -1,    -1,    -1,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    -1,    -1,    -1,    16,    15,    16,
      17,    18,    19,    -1,    76,    24,    -1,   688,    -1,    26,
      29,    76,    77,    30,    31,    -1,     4,     5,     6,     7,
       8,     9,    41,    11,    -1,    11,    -1,    -1,    16,    15,
      16,    17,   713,   702,   715,    -1,    24,    -1,   707,    25,
      -1,    29,    17,    18,    19,    20,    32,    33,    -1,    -1,
     731,   732,    -1,    41,    -1,   127,    -1,    76,    77,    -1,
      -1,   133,    -1,   135,    -1,    -1,    -1,   139,    -1,   750,
      -1,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,   157,    -1,    -1,    76,    77,
      -1,    -1,    -1,   165,    -1,    -1,   168,    -1,   779,    -1,
      -1,    -1,   174,   175,   176,   177,   178,   179,     4,     5,
       6,     7,     8,     9,    -1,    11,    -1,    13,   190,    -1,
      16,    -1,     4,     5,     6,     7,     8,     9,    24,    11,
      12,   203,    -1,    29,    16,    -1,    15,    16,    17,    18,
      19,    -1,    24,    -1,    -1,    -1,    -1,    29,    -1,    -1,
     222,    30,    31,    -1,    -1,   657,    -1,    -1,   660,   231,
     232,   233,   234,   235,   236,   237,   238,   239,    -1,    -1,
      -1,    -1,     4,     5,     6,     7,     8,     9,    -1,    11,
      76,    77,    -1,    -1,    16,    30,    31,    -1,    -1,    -1,
       9,   263,    24,    -1,    76,    77,    -1,    29,    -1,   730,
      -1,    20,   733,   734,   735,   736,    21,    22,    23,    54,
      25,   713,    -1,   715,   286,    -1,   588,    32,    33,    -1,
      65,    66,    -1,   595,    69,   297,    -1,    -1,    -1,   731,
     732,    -1,    -1,    78,     4,     5,     6,     7,     8,     9,
      -1,    11,     0,    -1,    76,    77,    16,   319,   750,   321,
      -1,     9,    -1,    -1,    24,    -1,    -1,    76,    -1,    29,
      22,    23,    20,    25,    -1,   637,   638,   639,    -1,    -1,
      32,    33,    -1,    -1,    -1,    33,    -1,   779,    -1,     4,
       5,     6,     7,     8,     9,    43,    11,    12,    -1,    -1,
      -1,    16,   664,   665,    -1,   667,   668,    -1,   670,    24,
      -1,    -1,    -1,    -1,    29,    -1,    76,    77,    -1,    -1,
      -1,    -1,    10,    -1,   133,    -1,   688,    -1,    76,    -1,
     139,    -1,    -1,    -1,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,   157,    -1,
      38,    -1,    -1,    -1,    -1,   717,    -1,    -1,    -1,    -1,
      -1,    76,    77,    -1,    -1,    -1,    -1,   729,   730,    57,
      -1,   733,   734,   735,   736,    -1,   738,    -1,   740,   127,
      -1,    69,    70,    71,    72,   133,    74,   135,    76,    77,
      -1,   139,    -1,    -1,   756,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,    -1,   157,
      10,   159,   160,   161,    -1,    15,    16,    17,    18,    19,
      20,    -1,    -1,     9,    -1,    11,   174,   175,    -1,    15,
      16,    17,    18,    19,    20,   183,   184,   185,   186,   187,
     188,    -1,    -1,   191,    30,    31,   194,    -1,    34,    35,
      36,    37,    -1,    39,   263,    -1,   204,    -1,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    -1,   223,    -1,   286,    24,    -1,
      10,    -1,    -1,    29,   232,    -1,    -1,    -1,   297,    -1,
      -1,    -1,    -1,    -1,   242,    -1,    -1,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    -1,    -1,   343,    16,
      -1,    -1,   347,    -1,    -1,   263,   351,    24,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,   588,    57,    -1,    -1,
      76,    77,    -1,   595,    -1,    -1,    -1,    -1,   286,    69,
      70,    71,    72,    -1,    74,    -1,    76,    77,    -1,   297,
      -1,   386,     0,    15,    16,    17,    18,    19,    20,   394,
       8,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    76,
      77,   319,    20,   321,    -1,   637,   638,   639,    15,    16,
      17,    18,    19,    20,    -1,    33,   421,    -1,   423,    -1,
     425,    -1,   427,    -1,   429,    43,   431,    -1,    -1,    -1,
      -1,    -1,   664,   665,   439,   667,   668,    -1,   670,    -1,
     445,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
      -1,    -1,    -1,    16,    -1,    -1,   688,    -1,    76,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    29,    -1,    -1,   474,
       4,     5,     6,     7,     8,     9,    -1,    11,    -1,    -1,
      -1,    -1,    16,    -1,    -1,   717,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    29,    -1,   729,   730,    10,
      -1,   733,   734,   735,   736,    -1,   738,    -1,   740,   127,
      -1,    -1,    -1,    76,    77,   133,    -1,   135,    -1,    -1,
      -1,   139,    -1,   528,   756,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,    -1,   157,
      -1,    10,    76,    77,    -1,    -1,    57,   165,   166,   167,
     555,    -1,    -1,    -1,    -1,    -1,   174,   175,    69,    70,
      71,    72,    -1,    74,    -1,    76,    77,    -1,    -1,    38,
      -1,    10,   190,    -1,    -1,   580,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,   203,    25,    -1,    57,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    -1,
      69,    70,    71,    72,   222,    74,    -1,    76,    77,   588,
      -1,    -1,    -1,   231,    -1,    -1,   595,    -1,    -1,    -1,
      -1,   239,   240,   241,    -1,   243,   244,    -1,    -1,    -1,
      -1,     0,    -1,    15,    16,    17,    18,    19,    20,    -1,
       9,    -1,    -1,    -1,    -1,   263,    -1,    -1,    30,    31,
      -1,    20,    34,    35,    36,    37,    -1,    -1,   637,   638,
     639,    -1,    -1,    -1,    33,    -1,    -1,    -1,   286,    -1,
     588,    -1,    -1,    -1,    43,    -1,    -1,   595,    -1,   297,
       0,    -1,    -1,     3,    -1,    -1,    -1,     9,   667,    11,
      -1,   670,    -1,    15,    16,    17,    18,    19,    20,    -1,
      -1,   319,    -1,   321,    26,    27,    28,    76,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    39,    -1,   637,
     638,   639,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    -1,    -1,   717,    -1,
      15,    16,    17,    18,    19,    -1,   664,   665,    -1,   667,
     668,    26,   670,    28,    -1,    30,    31,    -1,   127,   738,
      -1,   740,    -1,    -1,   133,    -1,   135,    -1,    -1,    -1,
     139,    -1,    -1,    -1,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,   157,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   165,    -1,    -1,   717,
      -1,    -1,    -1,    -1,    -1,   174,   175,    -1,    -1,    -1,
      -1,   729,   730,    57,    -1,   733,   734,   735,   736,    -1,
     738,   190,   740,   192,   193,    69,    70,    71,    72,    -1,
      74,    -1,    76,    77,   203,    -1,    -1,    -1,   756,     0,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,     9,    -1,
      -1,    -1,    21,   222,    -1,    -1,    25,    -1,    -1,    20,
      -1,    -1,   231,    32,    33,    34,    35,    36,    37,    -1,
     239,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      10,    11,    43,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   263,    25,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    76,     9,   286,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,   297,    22,
      23,    -1,    25,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    39,    -1,    -1,    -1,
     319,    -1,   321,    -1,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,   127,    54,    55,    -1,
     588,    -1,   133,    -1,   135,    -1,    -1,   595,   139,    -1,
      -1,    -1,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,   157,    -1,    -1,    -1,
      -1,     9,    -1,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,   174,   175,    -1,    -1,    -1,    26,   637,
     638,   639,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    39,    -1,    -1,   195,   196,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   664,   665,    -1,   667,
     668,    -1,   670,    -1,    -1,     9,    10,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     688,    25,    26,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    39,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,   717,
      -1,    -1,   263,    32,    33,    34,    35,    36,    37,    -1,
      -1,   729,   730,    -1,    -1,   733,   734,   735,   736,    -1,
     738,    -1,   740,     0,    -1,   286,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,   297,    -1,   756,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    10,    -1,   319,    -1,
     321,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    -1,    30,    31,    -1,    56,
      57,    58,    59,    -1,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    -1,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     9,    -1,    11,    -1,    -1,   588,
      15,    16,    17,    18,    19,    20,   595,    22,    -1,    -1,
      25,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    39,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
      -1,    14,    -1,    16,    -1,    -1,    -1,    -1,   637,   638,
     639,    24,    10,    -1,    -1,    -1,    29,    15,    16,    17,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    -1,    30,    31,    -1,   664,   665,    -1,   667,   668,
      -1,   670,    -1,    56,    57,    58,    59,    -1,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    -1,    76,    77,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
      -1,    14,    -1,    16,    -1,    -1,    -1,    -1,   717,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
     729,   730,    -1,    -1,   733,   734,   735,   736,    -1,   738,
      -1,   740,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,   756,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    -1,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    -1,   588,    -1,    -1,
      25,    26,    27,    28,   595,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    -1,    13,    -1,
      -1,    16,    -1,    -1,    -1,    -1,   637,   638,   639,    24,
      -1,    -1,    -1,    -1,    29,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    -1,
      30,    31,    -1,   664,   665,    -1,   667,   668,    -1,   670,
      -1,    56,    57,    58,    59,    -1,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      -1,    76,    77,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    -1,    -1,    14,
      -1,    16,    -1,    -1,    -1,    -1,   717,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,   729,   730,
      -1,    -1,   733,   734,   735,   736,    -1,   738,    -1,   740,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,   756,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      -1,    76,    77,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,     9,    -1,    11,    -1,    29,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    25,    26,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    39,    56,    57,    58,    59,
      -1,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    -1,    76,    77,     9,    -1,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,     9,    39,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    10,    39,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    25,    26,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    10,    -1,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    25,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    25,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    25,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    37
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
     127,   128,   130,   132,     8,    76,    77,   113,   114,   116,
     120,   121,   124,   125,   126,   127,     3,    12,    76,   112,
     115,     9,    16,    29,    76,    77,   124,   125,   113,   124,
     125,   126,   127,   113,   124,   127,    76,    11,   131,    76,
      89,     9,   112,    76,    68,   131,    68,   131,    68,   131,
      68,   131,    76,     9,    76,   105,    11,    13,    68,   119,
     122,   131,    11,    68,   119,     0,     0,     1,    83,     0,
       3,    82,    82,     9,     3,    13,    84,    85,    87,     9,
      82,    82,    82,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    54,    55,    82,     9,    11,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    25,    26,
      27,    28,    30,    31,    32,    33,    34,    35,    36,    37,
      39,   119,    11,    15,    16,    17,    25,    32,    33,   119,
      21,    25,    32,    33,    25,    32,    33,    15,    16,    17,
      18,    19,    20,    21,    25,    26,    27,    28,    30,    31,
      32,    33,    34,    35,    36,    37,    15,    16,    17,    18,
      19,    20,    21,    25,    32,    33,    34,    35,    36,    37,
      11,    21,    25,    32,    33,    34,    35,    36,    37,    21,
      22,    23,    25,    32,    33,    68,   131,    68,     9,    76,
     105,    10,    11,   122,    10,    10,    10,    10,    10,    10,
     115,     3,    12,    40,   124,   125,     9,    16,   124,    15,
      16,    17,    18,    19,    20,    26,    27,    28,    30,    31,
      15,    16,    17,    18,    19,    20,    42,    12,   113,   118,
     124,    40,    74,    76,    77,   108,   132,    42,   131,   131,
     131,   131,     3,    13,    10,    76,    77,   129,   132,     9,
      41,   118,    14,    39,   123,   131,   118,    83,   112,    13,
      14,    81,    62,   112,   110,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,    10,   111,
     112,   118,   113,   116,   124,   125,   113,   116,   124,   125,
     113,   116,   124,   125,   113,   124,   125,   113,   124,   125,
     113,   124,   125,   113,   120,   124,   125,   126,   127,   113,
     127,   113,   127,   113,   126,   113,   124,   113,   124,   113,
     124,   113,   124,   113,   124,   113,   116,   120,   121,   124,
     125,   126,   127,   113,   116,   120,   121,   124,   125,   126,
     127,   113,   124,   125,   126,   113,   124,   125,   126,   113,
     124,   125,   126,   113,   124,   125,   126,    76,    77,   118,
     113,   116,   113,   116,   113,   116,   113,   116,   113,   116,
     113,   116,   113,   120,   124,   125,   126,   127,   113,   116,
     113,   120,   113,   120,   113,   116,   113,   121,   113,   121,
     113,   124,   125,   113,   124,   125,   113,   124,   125,   113,
     124,   125,   113,   124,   125,   113,   125,   113,   120,   124,
     125,   126,   127,   113,   116,   113,   124,   113,   124,   113,
     124,   113,   124,   113,   124,   113,   124,   125,   113,   124,
     125,   113,   124,   125,   113,   124,   125,   113,   124,   125,
     113,   124,   125,   113,   124,   125,   113,   124,   125,   113,
     124,   125,   113,   124,   125,   113,   124,   125,   113,   124,
     125,   113,   120,   124,   125,   126,   127,   113,   116,   113,
     124,   125,   113,   124,   125,   113,   124,   125,   113,   124,
     125,   113,   124,   125,   113,   124,   125,   118,   113,   120,
     124,   125,   126,   127,   113,   116,   126,   113,   126,   113,
     126,   113,   126,   113,   126,   113,   126,   113,   126,   113,
     120,   124,   125,   126,   127,   113,   127,   113,   127,   113,
     116,   113,   127,   113,   127,   131,    10,   129,    42,     9,
     118,    10,     3,    12,    12,     3,   112,   124,   124,    15,
      16,    17,    18,    19,   124,   125,   124,   125,   124,   125,
     124,   125,   124,   125,   124,   125,   124,   124,   124,   124,
     124,   124,   125,   124,   125,   124,   125,   124,   125,   124,
     125,   124,   125,   112,   131,    12,    89,    41,    41,    41,
      76,   112,    13,     3,    14,    56,   102,   103,   132,    10,
      40,    10,    38,   106,   107,   132,    12,    41,   118,    12,
      41,    76,    14,    12,    10,    81,    14,     9,    10,    10,
      40,    12,    12,    12,    10,   112,   122,    10,   107,    12,
      12,   112,   124,   124,   124,   124,   124,   131,     9,   112,
     113,   117,   118,   124,   112,   117,   112,   117,   102,   102,
      76,    14,     3,    76,   129,    85,    76,    40,    10,    76,
      12,   118,    12,    41,    12,    41,   118,    42,    87,    14,
       3,   112,    87,   112,    85,    10,   113,   117,   124,    10,
      10,    38,    40,    10,    10,    10,    10,    14,    42,   102,
      42,    38,   132,    85,    12,    12,   118,    12,   118,    12,
      41,   112,     3,    10,    60,    98,   100,    85,    10,    84,
      85,    86,    86,   118,   118,    86,    86,    86,    86,   112,
     112,    76,    76,    12,    12,    12,   118,    40,    87,    38,
      12,   123,   118
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
     113,   113,   113,   114,   114,   114,   114,   114,   115,   115,
     115,   116,   116,   117,   117,   117,   118,   118,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     120,   120,   121,   121,   122,   122,   123,   123,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     128,   128,   128,   128,   129,   129,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   131,
     131,   131,   131,   132,   132,   132,   132,   132,   132,   132,
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
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     4,     4,     5,     1,     3,
       4,     1,     3,     3,     3,     5,     1,     1,     3,     4,
       4,     5,     4,     5,     5,     5,     6,     6,     6,     7,
       1,     3,     2,     4,     2,     3,     4,     6,     1,     2,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     3,     4,     3,     1,     3,     2,     2,     2,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     4,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
     415,   416,   419,   420,   421,   422,   423,   425,   426,   427,
     428,   429,   430,   431,   432,   434,   435,   436,   437,   438,
     440,   441,   442,   443,   444,   446,   447,   448,   449,   450,
     451,   452,   453,   455,   456,   457,   458,   459,   460,   461,
     462,   464,   465,   466,   468,   469,   470,   472,   473,   474,
     475,   476,   477,   478,   480,   481,   482,   483,   484,   485,
     486,   488,   489,   490,   491,   492,   493,   494,   496,   497,
     498,   499,   500,   501,   502,   504,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   540,
     541,   542,   544,   545,   546,   548,   549,   550,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   569,   570,   571,   573,   574,   575,
     577,   579,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   595,   596,   597,   598,   599,   602,   603,
     604,   608,   609,   611,   612,   613,   615,   616,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   628,   629,
     633,   634,   638,   639,   641,   642,   644,   645,   649,   650,
     651,   652,   653,   654,   655,   656,   657,   658,   659,   660,
     661,   662,   666,   667,   668,   669,   670,   671,   672,   673,
     674,   675,   676,   677,   678,   679,   680,   681,   682,   683,
     684,   685,   686,   690,   691,   692,   693,   694,   695,   696,
     697,   698,   699,   700,   701,   702,   703,   704,   705,   706,
     707,   708,   709,   710,   711,   712,   713,   714,   715,   716,
     720,   721,   722,   723,   724,   726,   727,   728,   729,   730,
     731,   732,   734,   735,   736,   737,   738,   739,   740,   742,
     743,   744,   745,   746,   748,   749,   750,   751,   752,   754,
     755,   756,   757,   758,   760,   761,   762,   763,   764,   766,
     770,   771,   772,   773,   775,   776,   780,   781,   782,   783,
     784,   785,   786,   787,   788,   789,   790,   791,   792,   794,
     795,   796,   797,   801,   802,   803,   804,   805,   806,   807,
     808,   809,   810,   811,   812,   813,   814,   815,   816,   817
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
#line 4987 "frontend/parser.cpp"

#line 820 "frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    auto msg = std::to_string(scanner->loc->begin.line) + ":" + std::to_string(scanner->loc->begin.column) + ": " + err_message;
    scanner->fatal_error(ptc::diag::ERR_SYNTAX, msg);
}
