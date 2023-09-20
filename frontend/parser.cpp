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
#line 230 "frontend/parser.yy"
                        { scanner->parseEntry(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1182 "frontend/parser.cpp"
    break;

  case 4: // stmt: stmts
#line 232 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1188 "frontend/parser.cpp"
    break;

  case 5: // stmt: stmt stmts
#line 233 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1194 "frontend/parser.cpp"
    break;

  case 6: // stmt: stmt error stmts
#line 234 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1200 "frontend/parser.cpp"
    break;

  case 9: // stmts: "terminator (\\n or ;)"
#line 241 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = nullptr; }
#line 1206 "frontend/parser.cpp"
    break;

  case 10: // stmts: stmts_ne
#line 242 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1212 "frontend/parser.cpp"
    break;

  case 11: // stmts_ne: set stmt_end
#line 244 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1218 "frontend/parser.cpp"
    break;

  case 12: // stmts_ne: vardecl stmt_end
#line 245 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1224 "frontend/parser.cpp"
    break;

  case 13: // stmts_ne: vardef stmt_end
#line 246 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1230 "frontend/parser.cpp"
    break;

  case 14: // stmts_ne: import stmt_end
#line 247 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1236 "frontend/parser.cpp"
    break;

  case 15: // stmts_ne: for
#line 248 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1242 "frontend/parser.cpp"
    break;

  case 16: // stmts_ne: if
#line 249 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1248 "frontend/parser.cpp"
    break;

  case 17: // stmts_ne: while
#line 250 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1254 "frontend/parser.cpp"
    break;

  case 18: // stmts_ne: dowhile
#line 251 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1260 "frontend/parser.cpp"
    break;

  case 19: // stmts_ne: struct
#line 252 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1266 "frontend/parser.cpp"
    break;

  case 20: // stmts_ne: function
#line 253 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1272 "frontend/parser.cpp"
    break;

  case 21: // stmts_ne: flowctl stmt_end
#line 254 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1278 "frontend/parser.cpp"
    break;

  case 22: // stmts_ne: expr stmt_end
#line 255 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1284 "frontend/parser.cpp"
    break;

  case 23: // block: "{" "}"
#line 259 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1290 "frontend/parser.cpp"
    break;

  case 24: // block: "{" stmt "}"
#line 260 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1296 "frontend/parser.cpp"
    break;

  case 25: // block: "terminator (\\n or ;)" "{" stmt "}"
#line 261 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1302 "frontend/parser.cpp"
    break;

  case 26: // block: "{" stmt "}" "terminator (\\n or ;)"
#line 262 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1308 "frontend/parser.cpp"
    break;

  case 27: // block: "terminator (\\n or ;)" "{" stmt "}" "terminator (\\n or ;)"
#line 263 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1314 "frontend/parser.cpp"
    break;

  case 28: // body: stmts_ne
#line 266 "frontend/parser.yy"
                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1320 "frontend/parser.cpp"
    break;

  case 29: // body: block
#line 267 "frontend/parser.yy"
                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1326 "frontend/parser.cpp"
    break;

  case 30: // scope_body: stmts_ne
#line 270 "frontend/parser.yy"
                      { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); scanner->leaveScope(); }
#line 1332 "frontend/parser.cpp"
    break;

  case 31: // scope_body: block
#line 271 "frontend/parser.yy"
                      { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); scanner->leaveScope(); }
#line 1338 "frontend/parser.cpp"
    break;

  case 32: // import: "import" id_list
#line 275 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::IR * > () = scanner->parseImports(yystack_[0].value.as < std::vector<std::string>  > ()); }
#line 1344 "frontend/parser.cpp"
    break;

  case 33: // id_list: "identifier"
#line 277 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseImportName(yystack_[0].value.as < std::string > ()); }
#line 1350 "frontend/parser.cpp"
    break;

  case 34: // id_list: "identifier" "," id_list
#line 278 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseAddImportName(yystack_[0].value.as < std::vector<std::string>  > (), yystack_[2].value.as < std::string > ()); }
#line 1356 "frontend/parser.cpp"
    break;

  case 35: // flowctl: "break"
#line 282 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseBreak(); }
#line 1362 "frontend/parser.cpp"
    break;

  case 36: // flowctl: "continue"
#line 283 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseContinue(); }
#line 1368 "frontend/parser.cpp"
    break;

  case 37: // flowctl: return
#line 284 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1374 "frontend/parser.cpp"
    break;

  case 38: // return: "return"
#line 286 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(nullptr); }
#line 1380 "frontend/parser.cpp"
    break;

  case 39: // return: "return" expr
#line 287 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1386 "frontend/parser.cpp"
    break;

  case 40: // for: "for" "(" vardecl ":" expr ")" body
#line 291 "frontend/parser.yy"
                                              { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1392 "frontend/parser.cpp"
    break;

  case 41: // for: "for" "(" "identifier" ":" expr ")" body
#line 292 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1398 "frontend/parser.cpp"
    break;

  case 42: // for: "for" "(" "external identifier" ":" expr ")" body
#line 293 "frontend/parser.yy"
                                              { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1404 "frontend/parser.cpp"
    break;

  case 43: // for: "for" "(" vardecl ":" range ")" body
#line 294 "frontend/parser.yy"
                                               { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1410 "frontend/parser.cpp"
    break;

  case 44: // for: "for" "(" "identifier" ":" range ")" body
#line 295 "frontend/parser.yy"
                                           { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1416 "frontend/parser.cpp"
    break;

  case 45: // for: "for" "(" "external identifier" ":" range ")" body
#line 296 "frontend/parser.yy"
                                               { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1422 "frontend/parser.cpp"
    break;

  case 46: // while: wh_kw "(" expr ")" scope_body
#line 300 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseWhile(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1428 "frontend/parser.cpp"
    break;

  case 47: // wh_kw: "while"
#line 302 "frontend/parser.yy"
                { scanner->enterBlockScope(); }
#line 1434 "frontend/parser.cpp"
    break;

  case 48: // dowhile: do_kw scope_body "while" "(" expr ")"
#line 304 "frontend/parser.yy"
                                                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseDoWhile(yystack_[1].value.as < ptc::ir::Expr * > (), yystack_[4].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1440 "frontend/parser.cpp"
    break;

  case 49: // do_kw: "do"
#line 306 "frontend/parser.yy"
             { scanner->enterBlockScope(); }
#line 1446 "frontend/parser.cpp"
    break;

  case 50: // if: if_kw "(" expr ")" scope_body else
#line 309 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseIfStmt(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1452 "frontend/parser.cpp"
    break;

  case 51: // else: el_kw scope_body
#line 311 "frontend/parser.yy"
                         { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1458 "frontend/parser.cpp"
    break;

  case 52: // else: %empty
#line 312 "frontend/parser.yy"
                    { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1464 "frontend/parser.cpp"
    break;

  case 53: // if_kw: "if"
#line 314 "frontend/parser.yy"
             { scanner->enterBlockScope(); }
#line 1470 "frontend/parser.cpp"
    break;

  case 54: // el_kw: "else"
#line 315 "frontend/parser.yy"
               { scanner->enterBlockScope(); }
#line 1476 "frontend/parser.cpp"
    break;

  case 55: // struct: "'struct'" "identifier" "{" "}"
#line 318 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[2].value.as < std::string > (), std::vector<ptc::ir::IR *>{}); }
#line 1482 "frontend/parser.cpp"
    break;

  case 56: // struct: "'struct'" "identifier" "{" decllist "}"
#line 319 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1488 "frontend/parser.cpp"
    break;

  case 57: // struct: "'struct'" "identifier" "terminator (\\n or ;)" "{" decllist "}"
#line 320 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[4].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1494 "frontend/parser.cpp"
    break;

  case 59: // decllist: "terminator (\\n or ;)" decllist
#line 323 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1500 "frontend/parser.cpp"
    break;

  case 60: // decllist: declistval "terminator (\\n or ;)"
#line 324 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[1].value.as < ptc::ir::IR * > (), std::vector<ptc::ir::IR *>{}); }
#line 1506 "frontend/parser.cpp"
    break;

  case 61: // decllist: declistval "terminator (\\n or ;)" decllist
#line 325 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[2].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1512 "frontend/parser.cpp"
    break;

  case 62: // declistval: type "identifier"
#line 327 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > (), nullptr); }
#line 1518 "frontend/parser.cpp"
    break;

  case 63: // declistval: type "identifier" "=" expr
#line 328 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1524 "frontend/parser.cpp"
    break;

  case 65: // function: type fun_id "(" ")" block
#line 333 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1530 "frontend/parser.cpp"
    break;

  case 66: // function: type fun_id "(" funargs ")" block
#line 334 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[5].value.as < ptc::ir::IR * > (), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1536 "frontend/parser.cpp"
    break;

  case 67: // function: "'void'" fun_id "(" ")" block
#line 335 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1542 "frontend/parser.cpp"
    break;

  case 68: // function: "'void'" fun_id "(" funargs ")" block
#line 336 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1548 "frontend/parser.cpp"
    break;

  case 69: // fun_id: "identifier"
#line 338 "frontend/parser.yy"
            { scanner->enterFunScope(); yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1554 "frontend/parser.cpp"
    break;

  case 70: // funargsnvar: type "identifier"
#line 340 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseFunParam(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1560 "frontend/parser.cpp"
    break;

  case 71: // funargsnvar: funargsnvar "," type "identifier"
#line 341 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseAddFunParam(yystack_[3].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1566 "frontend/parser.cpp"
    break;

  case 73: // funargs: funargsnvar "," ".." "identifier"
#line 344 "frontend/parser.yy"
          { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = yystack_[3].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (); }
#line 1572 "frontend/parser.cpp"
    break;

  case 74: // funargs: funargsnvar
#line 345 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = yystack_[0].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (); }
#line 1578 "frontend/parser.cpp"
    break;

  case 75: // vardecl: type "identifier"
#line 350 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1584 "frontend/parser.cpp"
    break;

  case 76: // vardef: type "identifier" "=" struct_val
#line 354 "frontend/parser.yy"
         { yylhs.value.as < ptc::ir::IR * > () = yystack_[3].value.as < ptc::ir::IR * > (); }
#line 1590 "frontend/parser.cpp"
    break;

  case 77: // vardef: type "identifier" "=" expr
#line 355 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1596 "frontend/parser.cpp"
    break;

  case 80: // set: expr "++=" expr
#line 361 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1602 "frontend/parser.cpp"
    break;

  case 81: // set: expr "**=" expr
#line 362 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1608 "frontend/parser.cpp"
    break;

  case 82: // set: expr "%=" expr
#line 363 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1614 "frontend/parser.cpp"
    break;

  case 83: // set: expr "/=" expr
#line 364 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1620 "frontend/parser.cpp"
    break;

  case 84: // set: expr "*=" expr
#line 365 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1626 "frontend/parser.cpp"
    break;

  case 85: // set: expr "-=" expr
#line 366 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1632 "frontend/parser.cpp"
    break;

  case 86: // set: expr "+=" expr
#line 367 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1638 "frontend/parser.cpp"
    break;

  case 87: // set: expr "&=" expr
#line 368 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1644 "frontend/parser.cpp"
    break;

  case 88: // set: expr "|=" expr
#line 369 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1650 "frontend/parser.cpp"
    break;

  case 89: // set: expr "^=" expr
#line 370 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1656 "frontend/parser.cpp"
    break;

  case 90: // set: expr "<<=" expr
#line 371 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1662 "frontend/parser.cpp"
    break;

  case 91: // set: expr ">>=" expr
#line 372 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1668 "frontend/parser.cpp"
    break;

  case 92: // set: expr "=" expr
#line 373 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1674 "frontend/parser.cpp"
    break;

  case 93: // set: expr "=" set
#line 374 "frontend/parser.yy"
      { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1680 "frontend/parser.cpp"
    break;

  case 94: // callarglist: expr
#line 378 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseFunCallArg(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1686 "frontend/parser.cpp"
    break;

  case 95: // callarglist: callarglist "," expr
#line 379 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddFunCallArg(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1692 "frontend/parser.cpp"
    break;

  case 96: // expr: expr_mat
#line 383 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1698 "frontend/parser.cpp"
    break;

  case 97: // expr: expr_var
#line 384 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1704 "frontend/parser.cpp"
    break;

  case 98: // expr: expr_none
#line 385 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1710 "frontend/parser.cpp"
    break;

  case 100: // expr: expr_int
#line 387 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 1716 "frontend/parser.cpp"
    break;

  case 101: // expr: expr_float
#line 388 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFloat(yystack_[0].value.as < double > ()); }
#line 1722 "frontend/parser.cpp"
    break;

  case 102: // expr: expr_str
#line 389 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseString(yystack_[0].value.as < std::string > ()); }
#line 1728 "frontend/parser.cpp"
    break;

  case 103: // expr: expr_bool
#line 390 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseBool(yystack_[0].value.as < bool > ()); }
#line 1734 "frontend/parser.cpp"
    break;

  case 104: // expr_var: "identifier"
#line 393 "frontend/parser.yy"
              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > ()); }
#line 1740 "frontend/parser.cpp"
    break;

  case 105: // expr_var: "external identifier"
#line 394 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > (), true); }
#line 1746 "frontend/parser.cpp"
    break;

  case 106: // expr_var: "-" "identifier"
#line 395 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1752 "frontend/parser.cpp"
    break;

  case 107: // expr_var: "-" "external identifier"
#line 396 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > (), true), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1758 "frontend/parser.cpp"
    break;

  case 108: // expr_var: "(" expr_var ")"
#line 397 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1764 "frontend/parser.cpp"
    break;

  case 109: // expr_var: expr_var "(" ")"
#line 399 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[2].value.as < ptc::ir::Expr * > (), std::vector<ptc::ir::Expr *>{}); }
#line 1770 "frontend/parser.cpp"
    break;

  case 110: // expr_var: expr_var "(" callarglist ")"
#line 400 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 1776 "frontend/parser.cpp"
    break;

  case 111: // expr_var: expr_str "[" int_val "]"
#line 402 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1782 "frontend/parser.cpp"
    break;

  case 112: // expr_var: expr_mat "[" int_val "]"
#line 403 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1788 "frontend/parser.cpp"
    break;

  case 113: // expr_var: "identifier" "[" int_val "]"
#line 404 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1794 "frontend/parser.cpp"
    break;

  case 114: // expr_var: "external identifier" "[" int_val "]"
#line 405 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1800 "frontend/parser.cpp"
    break;

  case 115: // expr_var: expr_var "[" int_val "]"
#line 406 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1806 "frontend/parser.cpp"
    break;

  case 116: // expr_var: expr_mat slice
#line 408 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1812 "frontend/parser.cpp"
    break;

  case 119: // expr_var: expr_var slice
#line 411 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1818 "frontend/parser.cpp"
    break;

  case 120: // expr_var: "identifier" "." expr_var
#line 413 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1824 "frontend/parser.cpp"
    break;

  case 121: // expr_var: "external identifier" "." expr_var
#line 414 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1830 "frontend/parser.cpp"
    break;

  case 122: // expr_var: expr_var "." expr_var
#line 415 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1836 "frontend/parser.cpp"
    break;

  case 124: // expr_var: expr_var "**" expr_float
#line 418 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1842 "frontend/parser.cpp"
    break;

  case 125: // expr_var: expr_var "**" expr_var
#line 419 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1848 "frontend/parser.cpp"
    break;

  case 126: // expr_var: expr_int "*" expr_var
#line 421 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1854 "frontend/parser.cpp"
    break;

  case 127: // expr_var: expr_float "*" expr_var
#line 422 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1860 "frontend/parser.cpp"
    break;

  case 128: // expr_var: expr_var "*" expr_int
#line 423 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1866 "frontend/parser.cpp"
    break;

  case 129: // expr_var: expr_var "*" expr_float
#line 424 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1872 "frontend/parser.cpp"
    break;

  case 130: // expr_var: expr_mat "*" expr_mat
#line 425 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1878 "frontend/parser.cpp"
    break;

  case 131: // expr_var: expr_mat "*" expr_var
#line 426 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1884 "frontend/parser.cpp"
    break;

  case 132: // expr_var: expr_var "*" expr_mat
#line 427 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1890 "frontend/parser.cpp"
    break;

  case 133: // expr_var: expr_var "*" expr_var
#line 428 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1896 "frontend/parser.cpp"
    break;

  case 134: // expr_var: expr_int "/" expr_var
#line 430 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1902 "frontend/parser.cpp"
    break;

  case 135: // expr_var: expr_float "/" expr_var
#line 431 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1908 "frontend/parser.cpp"
    break;

  case 136: // expr_var: expr_var "/" expr_int
#line 432 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1914 "frontend/parser.cpp"
    break;

  case 137: // expr_var: expr_var "/" expr_float
#line 433 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1920 "frontend/parser.cpp"
    break;

  case 138: // expr_var: expr_var "/" expr_var
#line 434 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1926 "frontend/parser.cpp"
    break;

  case 139: // expr_var: expr_int "%" expr_var
#line 436 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1932 "frontend/parser.cpp"
    break;

  case 140: // expr_var: expr_float "%" expr_var
#line 437 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1938 "frontend/parser.cpp"
    break;

  case 141: // expr_var: expr_var "%" expr_int
#line 438 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1944 "frontend/parser.cpp"
    break;

  case 142: // expr_var: expr_var "%" expr_float
#line 439 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1950 "frontend/parser.cpp"
    break;

  case 143: // expr_var: expr_var "%" expr_var
#line 440 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1956 "frontend/parser.cpp"
    break;

  case 144: // expr_var: expr_int "+" expr_var
#line 442 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1962 "frontend/parser.cpp"
    break;

  case 145: // expr_var: expr_float "+" expr_var
#line 443 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1968 "frontend/parser.cpp"
    break;

  case 146: // expr_var: expr_var "+" expr_int
#line 444 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1974 "frontend/parser.cpp"
    break;

  case 147: // expr_var: expr_var "+" expr_float
#line 445 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1980 "frontend/parser.cpp"
    break;

  case 148: // expr_var: expr_mat "+" expr_mat
#line 446 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1986 "frontend/parser.cpp"
    break;

  case 149: // expr_var: expr_var "+" expr_mat
#line 447 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1992 "frontend/parser.cpp"
    break;

  case 150: // expr_var: expr_mat "+" expr_var
#line 448 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1998 "frontend/parser.cpp"
    break;

  case 151: // expr_var: expr_var "+" expr_var
#line 449 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2004 "frontend/parser.cpp"
    break;

  case 152: // expr_var: expr_int "-" expr_var
#line 451 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2010 "frontend/parser.cpp"
    break;

  case 153: // expr_var: expr_float "-" expr_var
#line 452 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2016 "frontend/parser.cpp"
    break;

  case 154: // expr_var: expr_var "-" expr_int
#line 453 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2022 "frontend/parser.cpp"
    break;

  case 155: // expr_var: expr_var "-" expr_float
#line 454 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2028 "frontend/parser.cpp"
    break;

  case 156: // expr_var: expr_mat "-" expr_mat
#line 455 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2034 "frontend/parser.cpp"
    break;

  case 157: // expr_var: expr_var "-" expr_mat
#line 456 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2040 "frontend/parser.cpp"
    break;

  case 158: // expr_var: expr_mat "-" expr_var
#line 457 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2046 "frontend/parser.cpp"
    break;

  case 159: // expr_var: expr_var "-" expr_var
#line 458 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2052 "frontend/parser.cpp"
    break;

  case 160: // expr_var: expr_int "<<" expr_var
#line 460 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2058 "frontend/parser.cpp"
    break;

  case 161: // expr_var: expr_var "<<" expr_int
#line 461 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2064 "frontend/parser.cpp"
    break;

  case 162: // expr_var: expr_var "<<" expr_var
#line 462 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2070 "frontend/parser.cpp"
    break;

  case 163: // expr_var: expr_int ">>" expr_var
#line 464 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2076 "frontend/parser.cpp"
    break;

  case 164: // expr_var: expr_var ">>" expr_int
#line 465 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2082 "frontend/parser.cpp"
    break;

  case 165: // expr_var: expr_var ">>" expr_var
#line 466 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2088 "frontend/parser.cpp"
    break;

  case 166: // expr_var: expr_int ">" expr_var
#line 468 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2094 "frontend/parser.cpp"
    break;

  case 167: // expr_var: expr_float ">" expr_var
#line 469 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2100 "frontend/parser.cpp"
    break;

  case 169: // expr_var: expr_var ">" expr_int
#line 471 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2106 "frontend/parser.cpp"
    break;

  case 170: // expr_var: expr_var ">" expr_float
#line 472 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2112 "frontend/parser.cpp"
    break;

  case 171: // expr_var: expr_var ">" expr_str
#line 473 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2118 "frontend/parser.cpp"
    break;

  case 172: // expr_var: expr_var ">" expr_var
#line 474 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2124 "frontend/parser.cpp"
    break;

  case 173: // expr_var: expr_int ">=" expr_var
#line 476 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2130 "frontend/parser.cpp"
    break;

  case 174: // expr_var: expr_float ">=" expr_var
#line 477 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2136 "frontend/parser.cpp"
    break;

  case 176: // expr_var: expr_var ">=" expr_int
#line 479 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2142 "frontend/parser.cpp"
    break;

  case 177: // expr_var: expr_var ">=" expr_float
#line 480 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2148 "frontend/parser.cpp"
    break;

  case 178: // expr_var: expr_var ">=" expr_str
#line 481 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2154 "frontend/parser.cpp"
    break;

  case 179: // expr_var: expr_var ">=" expr_var
#line 482 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2160 "frontend/parser.cpp"
    break;

  case 180: // expr_var: expr_int "<" expr_var
#line 484 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2166 "frontend/parser.cpp"
    break;

  case 181: // expr_var: expr_float "<" expr_var
#line 485 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2172 "frontend/parser.cpp"
    break;

  case 183: // expr_var: expr_var "<" expr_int
#line 487 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2178 "frontend/parser.cpp"
    break;

  case 184: // expr_var: expr_var "<" expr_float
#line 488 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2184 "frontend/parser.cpp"
    break;

  case 185: // expr_var: expr_var "<" expr_str
#line 489 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2190 "frontend/parser.cpp"
    break;

  case 186: // expr_var: expr_var "<" expr_var
#line 490 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2196 "frontend/parser.cpp"
    break;

  case 187: // expr_var: expr_int "<=" expr_var
#line 492 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2202 "frontend/parser.cpp"
    break;

  case 188: // expr_var: expr_float "<=" expr_var
#line 493 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2208 "frontend/parser.cpp"
    break;

  case 190: // expr_var: expr_var "<=" expr_int
#line 495 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2214 "frontend/parser.cpp"
    break;

  case 191: // expr_var: expr_var "<=" expr_float
#line 496 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2220 "frontend/parser.cpp"
    break;

  case 192: // expr_var: expr_var "<=" expr_str
#line 497 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2226 "frontend/parser.cpp"
    break;

  case 193: // expr_var: expr_var "<=" expr_var
#line 498 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2232 "frontend/parser.cpp"
    break;

  case 194: // expr_var: expr_int "==" expr_var
#line 500 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2238 "frontend/parser.cpp"
    break;

  case 195: // expr_var: expr_float "==" expr_var
#line 501 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2244 "frontend/parser.cpp"
    break;

  case 197: // expr_var: expr_bool "==" expr_var
#line 503 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2250 "frontend/parser.cpp"
    break;

  case 198: // expr_var: expr_none "==" expr_var
#line 504 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2256 "frontend/parser.cpp"
    break;

  case 201: // expr_var: expr_var "==" expr_int
#line 507 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2262 "frontend/parser.cpp"
    break;

  case 202: // expr_var: expr_var "==" expr_float
#line 508 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2268 "frontend/parser.cpp"
    break;

  case 203: // expr_var: expr_var "==" expr_str
#line 509 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2274 "frontend/parser.cpp"
    break;

  case 204: // expr_var: expr_var "==" expr_bool
#line 510 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2280 "frontend/parser.cpp"
    break;

  case 205: // expr_var: expr_var "==" expr_none
#line 511 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2286 "frontend/parser.cpp"
    break;

  case 206: // expr_var: expr_var "==" expr_struct
#line 512 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2292 "frontend/parser.cpp"
    break;

  case 207: // expr_var: expr_mat "==" expr_mat
#line 513 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2298 "frontend/parser.cpp"
    break;

  case 208: // expr_var: expr_var "==" expr_mat
#line 514 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2304 "frontend/parser.cpp"
    break;

  case 209: // expr_var: expr_mat "==" expr_var
#line 515 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2310 "frontend/parser.cpp"
    break;

  case 210: // expr_var: expr_var "==" expr_var
#line 516 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2316 "frontend/parser.cpp"
    break;

  case 211: // expr_var: expr_int "!=" expr_var
#line 518 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2322 "frontend/parser.cpp"
    break;

  case 212: // expr_var: expr_float "!=" expr_var
#line 519 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2328 "frontend/parser.cpp"
    break;

  case 215: // expr_var: expr_none "!=" expr_var
#line 522 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2334 "frontend/parser.cpp"
    break;

  case 218: // expr_var: expr_var "!=" expr_int
#line 525 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2340 "frontend/parser.cpp"
    break;

  case 219: // expr_var: expr_var "!=" expr_float
#line 526 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2346 "frontend/parser.cpp"
    break;

  case 220: // expr_var: expr_var "!=" expr_str
#line 527 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2352 "frontend/parser.cpp"
    break;

  case 221: // expr_var: expr_var "!=" expr_bool
#line 528 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2358 "frontend/parser.cpp"
    break;

  case 222: // expr_var: expr_var "!=" expr_none
#line 529 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2364 "frontend/parser.cpp"
    break;

  case 223: // expr_var: expr_var "!=" expr_struct
#line 530 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2370 "frontend/parser.cpp"
    break;

  case 224: // expr_var: expr_mat "!=" expr_mat
#line 531 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2376 "frontend/parser.cpp"
    break;

  case 225: // expr_var: expr_var "!=" expr_mat
#line 532 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2382 "frontend/parser.cpp"
    break;

  case 226: // expr_var: expr_mat "!=" expr_var
#line 533 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2388 "frontend/parser.cpp"
    break;

  case 227: // expr_var: expr_var "!=" expr_var
#line 534 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2394 "frontend/parser.cpp"
    break;

  case 228: // expr_var: expr_int "&" expr_var
#line 536 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2400 "frontend/parser.cpp"
    break;

  case 229: // expr_var: expr_var "&" expr_int
#line 537 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2406 "frontend/parser.cpp"
    break;

  case 230: // expr_var: expr_var "&" expr_var
#line 538 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2412 "frontend/parser.cpp"
    break;

  case 231: // expr_var: expr_int "^" expr_var
#line 540 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2418 "frontend/parser.cpp"
    break;

  case 232: // expr_var: expr_var "^" expr_int
#line 541 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2424 "frontend/parser.cpp"
    break;

  case 233: // expr_var: expr_var "^" expr_var
#line 542 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2430 "frontend/parser.cpp"
    break;

  case 234: // expr_var: expr_int "|" expr_var
#line 544 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2436 "frontend/parser.cpp"
    break;

  case 235: // expr_var: expr_var "|" expr_int
#line 545 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2442 "frontend/parser.cpp"
    break;

  case 236: // expr_var: expr_var "|" expr_var
#line 546 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2448 "frontend/parser.cpp"
    break;

  case 241: // expr_var: expr_none "in" expr_mat
#line 552 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2454 "frontend/parser.cpp"
    break;

  case 243: // expr_var: expr_mat "in" expr_mat
#line 554 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2460 "frontend/parser.cpp"
    break;

  case 248: // expr_var: expr_none "in" expr_var
#line 559 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2466 "frontend/parser.cpp"
    break;

  case 250: // expr_var: expr_mat "in" expr_var
#line 561 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2472 "frontend/parser.cpp"
    break;

  case 251: // expr_var: expr_var "in" expr_str
#line 562 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2478 "frontend/parser.cpp"
    break;

  case 252: // expr_var: expr_var "in" expr_var
#line 563 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2484 "frontend/parser.cpp"
    break;

  case 253: // expr_var: expr_bool "and" expr_var
#line 565 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2490 "frontend/parser.cpp"
    break;

  case 254: // expr_var: expr_var "and" expr_bool
#line 566 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2496 "frontend/parser.cpp"
    break;

  case 255: // expr_var: expr_var "and" expr_var
#line 567 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2502 "frontend/parser.cpp"
    break;

  case 256: // expr_var: expr_bool "or" expr_var
#line 569 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2508 "frontend/parser.cpp"
    break;

  case 257: // expr_var: expr_var "or" expr_bool
#line 570 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2514 "frontend/parser.cpp"
    break;

  case 258: // expr_var: expr_var "or" expr_var
#line 571 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2520 "frontend/parser.cpp"
    break;

  case 263: // expr_var: expr_none "++" expr_struct
#line 577 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2526 "frontend/parser.cpp"
    break;

  case 270: // expr_var: expr_int "++" expr_var
#line 584 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2532 "frontend/parser.cpp"
    break;

  case 271: // expr_var: expr_float "++" expr_var
#line 585 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2538 "frontend/parser.cpp"
    break;

  case 272: // expr_var: expr_str "++" expr_var
#line 586 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2544 "frontend/parser.cpp"
    break;

  case 273: // expr_var: expr_bool "++" expr_var
#line 587 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2550 "frontend/parser.cpp"
    break;

  case 274: // expr_var: expr_none "++" expr_var
#line 588 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2556 "frontend/parser.cpp"
    break;

  case 276: // expr_var: expr_var "++" expr_int
#line 590 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2562 "frontend/parser.cpp"
    break;

  case 277: // expr_var: expr_var "++" expr_float
#line 591 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2568 "frontend/parser.cpp"
    break;

  case 278: // expr_var: expr_var "++" expr_str
#line 592 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2574 "frontend/parser.cpp"
    break;

  case 279: // expr_var: expr_var "++" expr_bool
#line 593 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2580 "frontend/parser.cpp"
    break;

  case 280: // expr_var: expr_var "++" expr_none
#line 594 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2586 "frontend/parser.cpp"
    break;

  case 281: // expr_var: expr_var "++" expr_struct
#line 595 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2592 "frontend/parser.cpp"
    break;

  case 282: // expr_var: expr_var "++" expr_var
#line 596 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2598 "frontend/parser.cpp"
    break;

  case 283: // matrix: "[" "]"
#line 600 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(std::vector<ptc::ir::Expr *>{}); }
#line 2604 "frontend/parser.cpp"
    break;

  case 284: // matrix: "[" matvals "]"
#line 601 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2610 "frontend/parser.cpp"
    break;

  case 285: // matrix: "[" "terminator (\\n or ;)" matvals "]"
#line 602 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2616 "frontend/parser.cpp"
    break;

  case 286: // matrix: "[" matvals "terminator (\\n or ;)" "]"
#line 603 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2622 "frontend/parser.cpp"
    break;

  case 287: // matrix: "[" "terminator (\\n or ;)" matvals "terminator (\\n or ;)" "]"
#line 604 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2628 "frontend/parser.cpp"
    break;

  case 288: // matvals: expr
#line 607 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixValue(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2634 "frontend/parser.cpp"
    break;

  case 289: // matvals: matvals "," expr
#line 608 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2640 "frontend/parser.cpp"
    break;

  case 290: // matvals: matvals "," "terminator (\\n or ;)" expr
#line 609 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[3].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2646 "frontend/parser.cpp"
    break;

  case 291: // expr_mat: matrix
#line 613 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2652 "frontend/parser.cpp"
    break;

  case 292: // expr_mat: "(" matrix ")"
#line 614 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2658 "frontend/parser.cpp"
    break;

  case 293: // range: "(" range ")"
#line 616 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2664 "frontend/parser.cpp"
    break;

  case 294: // range: int_val ".." int_val
#line 617 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseRange(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2670 "frontend/parser.cpp"
    break;

  case 295: // range: int_val "," int_val ".." int_val
#line 618 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseRange(yystack_[4].value.as < ptc::ir::Expr * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2676 "frontend/parser.cpp"
    break;

  case 296: // int_val: expr_int
#line 620 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 2682 "frontend/parser.cpp"
    break;

  case 297: // int_val: expr_var
#line 621 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2688 "frontend/parser.cpp"
    break;

  case 310: // expr_none: "none"
#line 638 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseNone(); }
#line 2694 "frontend/parser.cpp"
    break;

  case 311: // expr_none: "(" "none" ")"
#line 639 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseNone(); }
#line 2700 "frontend/parser.cpp"
    break;

  case 318: // expr_int: "int"
#line 654 "frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 2706 "frontend/parser.cpp"
    break;

  case 319: // expr_int: "-" expr_int
#line 655 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 2712 "frontend/parser.cpp"
    break;

  case 320: // expr_int: "(" expr_int ")"
#line 656 "frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 2718 "frontend/parser.cpp"
    break;

  case 321: // expr_int: "~" expr_int
#line 657 "frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 2724 "frontend/parser.cpp"
    break;

  case 322: // expr_int: expr_int "*" expr_int
#line 658 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 2730 "frontend/parser.cpp"
    break;

  case 323: // expr_int: expr_int "/" expr_int
#line 659 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 2736 "frontend/parser.cpp"
    break;

  case 324: // expr_int: expr_int "%" expr_int
#line 660 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 2742 "frontend/parser.cpp"
    break;

  case 325: // expr_int: expr_int "-" expr_int
#line 661 "frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 2748 "frontend/parser.cpp"
    break;

  case 326: // expr_int: expr_int "+" expr_int
#line 662 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 2754 "frontend/parser.cpp"
    break;

  case 327: // expr_int: expr_int "<<" expr_int
#line 663 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 2760 "frontend/parser.cpp"
    break;

  case 328: // expr_int: expr_int ">>" expr_int
#line 664 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 2766 "frontend/parser.cpp"
    break;

  case 329: // expr_int: expr_int "&" expr_int
#line 665 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 2772 "frontend/parser.cpp"
    break;

  case 330: // expr_int: expr_int "^" expr_int
#line 666 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 2778 "frontend/parser.cpp"
    break;

  case 331: // expr_int: expr_int "|" expr_int
#line 667 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 2784 "frontend/parser.cpp"
    break;

  case 332: // expr_float: "float"
#line 671 "frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 2790 "frontend/parser.cpp"
    break;

  case 333: // expr_float: "-" expr_float
#line 672 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 2796 "frontend/parser.cpp"
    break;

  case 334: // expr_float: "(" expr_float ")"
#line 673 "frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 2802 "frontend/parser.cpp"
    break;

  case 335: // expr_float: expr_float "**" expr_float
#line 674 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2808 "frontend/parser.cpp"
    break;

  case 336: // expr_float: expr_float "**" expr_int
#line 675 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2814 "frontend/parser.cpp"
    break;

  case 337: // expr_float: expr_int "**" expr_float
#line 676 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2820 "frontend/parser.cpp"
    break;

  case 338: // expr_float: expr_float "*" expr_float
#line 677 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 2826 "frontend/parser.cpp"
    break;

  case 339: // expr_float: expr_float "*" expr_int
#line 678 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 2832 "frontend/parser.cpp"
    break;

  case 340: // expr_float: expr_int "*" expr_float
#line 679 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 2838 "frontend/parser.cpp"
    break;

  case 341: // expr_float: expr_float "/" expr_float
#line 680 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 2844 "frontend/parser.cpp"
    break;

  case 342: // expr_float: expr_float "/" expr_int
#line 681 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 2850 "frontend/parser.cpp"
    break;

  case 343: // expr_float: expr_int "/" expr_float
#line 682 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 2856 "frontend/parser.cpp"
    break;

  case 344: // expr_float: expr_float "%" expr_float
#line 683 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2862 "frontend/parser.cpp"
    break;

  case 345: // expr_float: expr_float "%" expr_int
#line 684 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2868 "frontend/parser.cpp"
    break;

  case 346: // expr_float: expr_int "%" expr_float
#line 685 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2874 "frontend/parser.cpp"
    break;

  case 347: // expr_float: expr_float "-" expr_float
#line 686 "frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 2880 "frontend/parser.cpp"
    break;

  case 348: // expr_float: expr_float "-" expr_int
#line 687 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 2886 "frontend/parser.cpp"
    break;

  case 349: // expr_float: expr_int "-" expr_float
#line 688 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 2892 "frontend/parser.cpp"
    break;

  case 350: // expr_float: expr_float "+" expr_float
#line 689 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 2898 "frontend/parser.cpp"
    break;

  case 351: // expr_float: expr_float "+" expr_int
#line 690 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 2904 "frontend/parser.cpp"
    break;

  case 352: // expr_float: expr_int "+" expr_float
#line 691 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 2910 "frontend/parser.cpp"
    break;

  case 353: // expr_str: "string"
#line 695 "frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2916 "frontend/parser.cpp"
    break;

  case 354: // expr_str: "(" expr_str ")"
#line 696 "frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 2922 "frontend/parser.cpp"
    break;

  case 355: // expr_str: expr_str "++" expr_str
#line 697 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 2928 "frontend/parser.cpp"
    break;

  case 356: // expr_str: expr_str "++" expr_int
#line 698 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 2934 "frontend/parser.cpp"
    break;

  case 357: // expr_str: expr_str "++" expr_float
#line 699 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 2940 "frontend/parser.cpp"
    break;

  case 358: // expr_str: expr_str "++" expr_bool
#line 700 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2946 "frontend/parser.cpp"
    break;

  case 359: // expr_str: expr_str "++" expr_none
#line 701 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 2952 "frontend/parser.cpp"
    break;

  case 360: // expr_str: expr_int "++" expr_str
#line 702 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 2958 "frontend/parser.cpp"
    break;

  case 361: // expr_str: expr_int "++" expr_int
#line 703 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 2964 "frontend/parser.cpp"
    break;

  case 362: // expr_str: expr_int "++" expr_float
#line 704 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 2970 "frontend/parser.cpp"
    break;

  case 363: // expr_str: expr_int "++" expr_bool
#line 705 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2976 "frontend/parser.cpp"
    break;

  case 364: // expr_str: expr_int "++" expr_none
#line 706 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 2982 "frontend/parser.cpp"
    break;

  case 365: // expr_str: expr_float "++" expr_str
#line 707 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 2988 "frontend/parser.cpp"
    break;

  case 366: // expr_str: expr_float "++" expr_int
#line 708 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 2994 "frontend/parser.cpp"
    break;

  case 367: // expr_str: expr_float "++" expr_float
#line 709 "frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 3000 "frontend/parser.cpp"
    break;

  case 368: // expr_str: expr_float "++" expr_bool
#line 710 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3006 "frontend/parser.cpp"
    break;

  case 369: // expr_str: expr_float "++" expr_none
#line 711 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 3012 "frontend/parser.cpp"
    break;

  case 370: // expr_str: expr_bool "++" expr_str
#line 712 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 3018 "frontend/parser.cpp"
    break;

  case 371: // expr_str: expr_bool "++" expr_int
#line 713 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 3024 "frontend/parser.cpp"
    break;

  case 372: // expr_str: expr_bool "++" expr_float
#line 714 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 3030 "frontend/parser.cpp"
    break;

  case 373: // expr_str: expr_bool "++" expr_bool
#line 715 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3036 "frontend/parser.cpp"
    break;

  case 374: // expr_str: expr_bool "++" expr_none
#line 716 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 3042 "frontend/parser.cpp"
    break;

  case 375: // expr_str: expr_none "++" expr_str
#line 717 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 3048 "frontend/parser.cpp"
    break;

  case 376: // expr_str: expr_none "++" expr_int
#line 718 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 3054 "frontend/parser.cpp"
    break;

  case 377: // expr_str: expr_none "++" expr_float
#line 719 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 3060 "frontend/parser.cpp"
    break;

  case 378: // expr_str: expr_none "++" expr_bool
#line 720 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3066 "frontend/parser.cpp"
    break;

  case 379: // expr_str: expr_none "++" expr_none
#line 721 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 3072 "frontend/parser.cpp"
    break;

  case 380: // expr_bool: "bool"
#line 725 "frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 3078 "frontend/parser.cpp"
    break;

  case 381: // expr_bool: "(" expr_bool ")"
#line 726 "frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 3084 "frontend/parser.cpp"
    break;

  case 382: // expr_bool: "not" expr_bool
#line 727 "frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 3090 "frontend/parser.cpp"
    break;

  case 383: // expr_bool: expr_bool "or" expr_bool
#line 728 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 3096 "frontend/parser.cpp"
    break;

  case 384: // expr_bool: expr_bool "and" expr_bool
#line 729 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 3102 "frontend/parser.cpp"
    break;

  case 385: // expr_bool: expr_bool "==" expr_bool
#line 731 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 3108 "frontend/parser.cpp"
    break;

  case 386: // expr_bool: expr_int "==" expr_int
#line 732 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 3114 "frontend/parser.cpp"
    break;

  case 387: // expr_bool: expr_int "==" expr_float
#line 733 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 3120 "frontend/parser.cpp"
    break;

  case 388: // expr_bool: expr_float "==" expr_float
#line 734 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 3126 "frontend/parser.cpp"
    break;

  case 389: // expr_bool: expr_float "==" expr_int
#line 735 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 3132 "frontend/parser.cpp"
    break;

  case 390: // expr_bool: expr_str "==" expr_str
#line 736 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 3138 "frontend/parser.cpp"
    break;

  case 391: // expr_bool: expr_none "==" expr_none
#line 737 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 3144 "frontend/parser.cpp"
    break;

  case 392: // expr_bool: expr_bool "!=" expr_bool
#line 739 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 3150 "frontend/parser.cpp"
    break;

  case 393: // expr_bool: expr_int "!=" expr_int
#line 740 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 3156 "frontend/parser.cpp"
    break;

  case 394: // expr_bool: expr_int "!=" expr_float
#line 741 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 3162 "frontend/parser.cpp"
    break;

  case 395: // expr_bool: expr_float "!=" expr_float
#line 742 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 3168 "frontend/parser.cpp"
    break;

  case 396: // expr_bool: expr_float "!=" expr_int
#line 743 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 3174 "frontend/parser.cpp"
    break;

  case 397: // expr_bool: expr_str "!=" expr_str
#line 744 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 3180 "frontend/parser.cpp"
    break;

  case 398: // expr_bool: expr_none "!=" expr_none
#line 745 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 3186 "frontend/parser.cpp"
    break;

  case 399: // expr_bool: expr_int ">" expr_int
#line 747 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 3192 "frontend/parser.cpp"
    break;

  case 400: // expr_bool: expr_int ">" expr_float
#line 748 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 3198 "frontend/parser.cpp"
    break;

  case 401: // expr_bool: expr_float ">" expr_float
#line 749 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 3204 "frontend/parser.cpp"
    break;

  case 402: // expr_bool: expr_float ">" expr_int
#line 750 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 3210 "frontend/parser.cpp"
    break;

  case 403: // expr_bool: expr_str ">" expr_str
#line 751 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 3216 "frontend/parser.cpp"
    break;

  case 404: // expr_bool: expr_int "<" expr_int
#line 753 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 3222 "frontend/parser.cpp"
    break;

  case 405: // expr_bool: expr_int "<" expr_float
#line 754 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 3228 "frontend/parser.cpp"
    break;

  case 406: // expr_bool: expr_float "<" expr_float
#line 755 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 3234 "frontend/parser.cpp"
    break;

  case 407: // expr_bool: expr_float "<" expr_int
#line 756 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 3240 "frontend/parser.cpp"
    break;

  case 408: // expr_bool: expr_str "<" expr_str
#line 757 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 3246 "frontend/parser.cpp"
    break;

  case 409: // expr_bool: expr_int ">=" expr_int
#line 759 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 3252 "frontend/parser.cpp"
    break;

  case 410: // expr_bool: expr_int ">=" expr_float
#line 760 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 3258 "frontend/parser.cpp"
    break;

  case 411: // expr_bool: expr_float ">=" expr_float
#line 761 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 3264 "frontend/parser.cpp"
    break;

  case 412: // expr_bool: expr_float ">=" expr_int
#line 762 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 3270 "frontend/parser.cpp"
    break;

  case 413: // expr_bool: expr_str ">=" expr_str
#line 763 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 3276 "frontend/parser.cpp"
    break;

  case 414: // expr_bool: expr_int "<=" expr_int
#line 765 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 3282 "frontend/parser.cpp"
    break;

  case 415: // expr_bool: expr_int "<=" expr_float
#line 766 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 3288 "frontend/parser.cpp"
    break;

  case 416: // expr_bool: expr_float "<=" expr_float
#line 767 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 3294 "frontend/parser.cpp"
    break;

  case 417: // expr_bool: expr_float "<=" expr_int
#line 768 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 3300 "frontend/parser.cpp"
    break;

  case 418: // expr_bool: expr_str "<=" expr_str
#line 769 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 3306 "frontend/parser.cpp"
    break;

  case 419: // expr_bool: expr_str "in" expr_str
#line 771 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[0].value.as < std::string > ().find(yystack_[2].value.as < std::string > ()) != std::string::npos; }
#line 3312 "frontend/parser.cpp"
    break;

  case 424: // mattype: "identifier" matsq
#line 783 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3318 "frontend/parser.cpp"
    break;

  case 425: // mattype: "'int'" matsq
#line 784 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(INT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3324 "frontend/parser.cpp"
    break;

  case 426: // mattype: "'float'" matsq
#line 785 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(FLOAT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3330 "frontend/parser.cpp"
    break;

  case 427: // mattype: "'string'" matsq
#line 786 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(STRING_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3336 "frontend/parser.cpp"
    break;

  case 428: // mattype: "'bool'" matsq
#line 787 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(BOOL_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3342 "frontend/parser.cpp"
    break;

  case 436: // matsq: "[" "]"
#line 796 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(scanner->parseInt(-1)); }
#line 3348 "frontend/parser.cpp"
    break;

  case 437: // matsq: "[" int_val "]"
#line 797 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 3354 "frontend/parser.cpp"
    break;

  case 438: // matsq: "[" "]" matsq
#line 798 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), scanner->parseInt(-1)); }
#line 3360 "frontend/parser.cpp"
    break;

  case 439: // matsq: "[" int_val "]" matsq
#line 799 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[2].value.as < ptc::ir::Expr * > ()); }
#line 3366 "frontend/parser.cpp"
    break;

  case 440: // type: "'int'" "?"
#line 803 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, true, true); }
#line 3372 "frontend/parser.cpp"
    break;

  case 441: // type: "'float'" "?"
#line 804 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, true, true); }
#line 3378 "frontend/parser.cpp"
    break;

  case 442: // type: "'string'" "?"
#line 805 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, true, true); }
#line 3384 "frontend/parser.cpp"
    break;

  case 443: // type: "'bool'" "?"
#line 806 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, true, true); }
#line 3390 "frontend/parser.cpp"
    break;

  case 444: // type: "identifier" "?"
#line 807 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[1].value.as < std::string > (), true, true); }
#line 3396 "frontend/parser.cpp"
    break;

  case 446: // type: mattype "?"
#line 809 "frontend/parser.yy"
       { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 3402 "frontend/parser.cpp"
    break;

  case 447: // type: "'int'"
#line 810 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, false, true); }
#line 3408 "frontend/parser.cpp"
    break;

  case 448: // type: "'float'"
#line 811 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, false, true); }
#line 3414 "frontend/parser.cpp"
    break;

  case 449: // type: "'string'"
#line 812 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, false, true); }
#line 3420 "frontend/parser.cpp"
    break;

  case 450: // type: "'bool'"
#line 813 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, false, true); }
#line 3426 "frontend/parser.cpp"
    break;

  case 451: // type: "identifier"
#line 814 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[0].value.as < std::string > (), false, true); }
#line 3432 "frontend/parser.cpp"
    break;

  case 453: // type: mattype
#line 816 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 3438 "frontend/parser.cpp"
    break;


#line 3442 "frontend/parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -765;

  const short  Parser ::yytable_ninf_ = -452;

  const short
   Parser ::yypact_[] =
  {
     861,  -765,  -765,  -765,  -765,  -765,  -765,  -765,  1862,    22,
      71,  1215,   576,   -63,   -62,  -765,    13,  -765,  -765,  1955,
    -765,  -765,   -57,    24,    32,    36,    42,   -24,   -15,    31,
     105,    67,    57,  -765,  -765,   237,   237,  -765,  -765,  -765,
      81,  -765,  2570,  -765,    93,  -765,  -765,   237,   237,   237,
     805,  2855,  -765,  1230,   528,   568,  3104,  3242,   870,   700,
      43,    74,     0,   124,   310,  2795,   168,  1230,   528,   568,
    3025,  3081,   628,   589,  1955,  -765,   310,  -765,    29,   522,
     522,  -765,  -765,  -765,  -765,  1284,   103,  3127,  3276,  1448,
    -765,   576,   576,  -765,   196,   201,  -765,  1066,  -765,   202,
     671,   306,  -765,   306,  -765,   306,  -765,   306,  -765,   368,
    -765,   313,   567,   341,  1955,   306,  -765,  -765,  -765,  1553,
    1955,  -765,  -765,  -765,  2673,  -765,  -765,  -765,  -765,  -765,
    1955,   350,  2600,  -765,  -765,   316,  1955,  -765,  -765,  -765,
    1955,  1955,  1955,  1955,  1955,  1955,  1955,  1955,  1955,  1955,
    1955,  1955,  1955,  -765,   971,  1553,  1955,  1955,  1955,  1955,
    1955,  1955,  1955,  1955,  1955,  1955,  1955,  1955,  1955,  1955,
    1955,  1955,  1955,  1955,  1955,  1955,  1955,  1955,  -765,  1553,
    1955,  1955,  1955,  1955,  1955,  1955,  -765,  1955,  1955,  1955,
    1955,  1955,  1955,  1955,  1955,  1955,  1955,  1955,  1955,  1955,
     522,  1955,  1955,  1955,  1955,  1955,  1955,  1955,  1955,  1955,
    1955,  1955,  1955,  1955,  1955,  1955,  1955,  1955,  1955,  1955,
    1955,  1955,  1955,  1955,  1955,  1955,  1955,  1955,  1955,  1955,
    1955,  1955,  1955,  1955,  1955,  1955,  1955,  1955,  1955,  1955,
    1955,  1955,  1955,   306,  -765,  -765,   245,    10,   370,  -765,
    1553,   403,  -765,  -765,  -765,  -765,  -765,  -765,   130,   415,
    -765,   513,  1616,  1250,   522,   522,   522,   522,   522,   576,
     576,   576,   576,   576,   522,   522,   522,   522,   522,   522,
    2960,  2497,   729,  1089,  1215,    -1,    -1,  1215,   522,   522,
     522,   522,   522,   522,  1215,   522,   522,   522,   522,   522,
     522,  1215,  1215,  1215,  1215,  1215,  1215,  1215,  1215,  1215,
    1215,  1215,  1215,  1215,  1674,  -765,   576,   576,   576,   576,
     576,  1955,   -62,   295,   437,   439,     4,  1955,   306,  2855,
     481,  3104,  3242,   870,   700,  -765,  -765,  -765,  -765,   469,
     304,    69,  1270,   317,  -765,   430,   509,   322,  3104,  -765,
     320,   322,  -765,   518,  2673,  -765,  1431,   538,   545,  -765,
    1966,  -765,  -765,  -765,  -765,  -765,  -765,  -765,  -765,  -765,
    -765,  -765,  -765,  -765,   238,  -765,   325,   547,   573,   709,
     816,   547,   573,   709,   816,   315,   548,   543,   550,   315,
     543,   550,   315,   543,   550,   315,   550,  2374,    23,   214,
    3150,  1492,   674,   746,  2435,   332,  2932,   584,  2886,   788,
    2997,  3253,  2249,  3196,  2740,  3219,   234,  1379,   234,  1379,
     930,   635,  -765,  -765,  1321,  1113,   657,  -765,   930,   635,
    -765,  -765,  1321,  1113,   657,  -765,   470,  1556,  1528,   583,
     470,  1556,  1528,   583,   470,  1556,  1528,   583,   470,  1556,
    1528,   583,   322,   326,   547,   573,   547,   573,   315,   548,
    2886,  1314,   930,   635,   930,   635,  2374,    23,   214,  3150,
    1492,   674,   746,  2886,  1314,   930,  -765,   930,  -765,  2374,
      23,   214,  3150,  1492,   674,   746,  2886,  1314,   930,  -765,
     930,  -765,   547,   709,   816,   547,   709,   816,   315,   543,
     550,   315,   543,   550,   315,   543,   550,  2096,   575,  2374,
      23,   214,  3150,  1492,   674,   746,  2886,  1314,  2997,  3253,
    2249,  3196,  2740,  3219,   234,  1379,   234,  1379,   930,  1321,
    1113,   930,  1321,  1113,   470,  1556,  1528,   470,  1556,  1528,
     470,  1556,  1528,   470,  1556,  1528,   547,   709,   816,   547,
     709,   816,   315,   543,   550,   315,   543,   550,   315,   543,
     550,   315,   543,   550,  2374,    23,   214,  3150,  1492,   674,
     746,  2886,  1314,   930,  1321,  1113,   930,  1321,  1113,   470,
    1556,  1528,   470,  1556,  1528,   470,  1556,  1528,   470,  1556,
    1528,   585,  2374,    23,   214,  3150,  1492,   674,   746,  2886,
    1314,   788,   930,   657,   930,   657,   470,   583,   470,   583,
     470,   583,   470,   583,  2374,    23,   214,  3150,  1492,   674,
     746,  2435,   332,  2932,   584,  2886,  1314,   930,  -765,   930,
    -765,  -765,  -765,   261,   588,     9,  1584,   465,   328,  -765,
     592,  -765,  -765,  1955,  -765,   966,   979,   966,   979,   543,
     575,   543,   575,   543,   575,  1536,  1185,   480,   988,   988,
     966,   979,   966,   979,   543,   575,   543,   575,   543,   575,
     543,   575,   242,  3173,  3283,  1023,   719,   610,  -765,  -765,
     242,  3173,  3283,  1023,   719,  1925,  1586,  1925,  1586,  1925,
    1586,  1925,  1586,  1925,  1586,  1925,  1586,   242,  3173,  3283,
    1023,   719,  1925,  1586,  1925,  1586,  1925,  1586,  1925,  1586,
    1925,  1586,  1925,  1586,   242,  3173,  3283,  1023,   719,  1643,
     808,  1047,  1047,  -765,  -765,  -765,  -765,   242,  3173,  3283,
    1023,   719,   549,   508,  -765,  -765,   495,   495,  -765,  -765,
    -765,  -765,  -765,  2034,  2034,  2034,  -765,  -765,  -765,   306,
     274,   274,  -765,   546,   622,   637,    11,   471,   570,   603,
     656,    14,  -765,  1658,   364,    34,  1402,   605,  -765,  -765,
    2570,  2495,   664,  1955,  2570,  -765,  1955,  -765,  -765,  -765,
    -765,   885,  -765,  -765,   471,   661,  -765,  -765,  -765,   124,
    2188,   662,  2826,   663,   330,  3053,   676,   679,   686,   687,
    -765,   684,  -765,   659,  -765,   274,   660,  -765,  -765,   282,
     471,  -765,  -765,   692,  -765,  1768,  -765,  1800,   464,  1955,
    -765,   702,  -765,   721,   675,  -765,  -765,  -765,   471,  2795,
     728,  3025,  2570,  2570,  1955,  1955,  2570,  2570,  2570,  2570,
    -765,  1955,  -765,  1955,   682,    15,  -765,  -765,  -765,   747,
    -765,   748,  -765,  1922,   732,  -765,  -765,  -765,  -765,  2570,
    -765,  -765,  -765,  -765,  -765,  -765,  -765,   735,  -765,  -765,
    -765,  -765,  -765,  -765,  -765,  -765,  -765,  -765,  -765,   762,
     737,  -765,  1955,  -765,  -765,  -765
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     9,   318,   332,   353,   380,   310,     0,     0,
       0,     0,     0,     0,     0,    53,     0,    47,    49,    38,
      35,    36,     0,   447,   448,   449,   450,     0,     0,   104,
     105,     0,     0,     4,    10,     0,     0,    37,    15,    17,
       0,    18,     0,    16,     0,    19,    20,     0,     0,     0,
       0,    97,   291,    96,    98,    99,   100,   101,   102,   103,
     452,   453,     0,   310,   104,     0,   291,     0,     0,     0,
       0,     0,     0,     0,     0,   283,   104,   288,     0,     0,
       0,   106,   107,   319,   333,     0,     0,     0,     0,     0,
     382,     0,     0,   321,     0,    33,    32,     0,    39,     0,
       0,   440,   425,   441,   426,   442,   427,   443,   428,     0,
      69,     0,     0,     0,     0,   444,   117,   312,   424,     0,
       0,   118,     1,     3,     0,     5,     8,     7,    14,    21,
       0,     0,     0,    30,    31,     0,     0,    12,    13,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   119,     0,
       0,     0,     0,     0,     0,     0,   116,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   445,   429,   446,     0,    75,     0,   311,
       0,   312,   108,   292,   320,   334,   354,   381,     0,     0,
     284,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   319,     0,     0,     0,     0,
       0,     0,     0,   451,     0,     0,     0,     0,   436,   297,
       0,   296,     0,     0,     0,   431,   432,   433,   434,     0,
       0,     0,     0,     0,   314,     0,     0,   120,     0,   430,
       0,   121,     6,     0,     0,    23,     0,     0,     0,    93,
      92,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,   109,     0,    94,     0,   151,   149,   146,
     147,   159,   157,   154,   155,   133,   132,   128,   129,   138,
     136,   137,   143,   141,   142,   125,   124,   282,   280,   281,
     276,   277,   278,   279,   255,   254,   258,   257,   252,   251,
     230,   229,   236,   235,   233,   232,   162,   161,   165,   164,
     210,   208,   205,   206,   201,   202,   203,   204,   227,   225,
     222,   223,   218,   219,   220,   221,   172,   169,   170,   171,
     186,   183,   184,   185,   179,   176,   177,   178,   193,   190,
     191,   192,   122,     0,   150,   148,   158,   156,   131,   130,
     250,   243,   209,   207,   226,   224,   274,   379,   263,   376,
     377,   375,   378,   248,   241,   198,   391,   215,   398,   275,
     268,   269,   264,   265,   266,   267,   249,   242,   200,   199,
     217,   216,   144,   326,   352,   152,   325,   349,   126,   322,
     340,   134,   323,   343,   139,   324,   346,     0,   337,   270,
     364,   259,   361,   362,   360,   363,   244,   237,   228,   329,
     234,   331,   231,   330,   160,   327,   163,   328,   194,   386,
     387,   211,   393,   394,   166,   399,   400,   180,   404,   405,
     173,   409,   410,   187,   414,   415,   145,   351,   350,   153,
     348,   347,   127,   339,   338,   135,   342,   341,   140,   345,
     344,   123,   336,   335,   271,   369,   260,   366,   367,   365,
     368,   245,   238,   195,   389,   388,   212,   396,   395,   167,
     402,   401,   181,   407,   406,   174,   412,   411,   188,   417,
     416,     0,   272,   359,   261,   356,   357,   355,   358,   246,
     239,   419,   196,   390,   213,   397,   168,   403,   182,   408,
     175,   413,   189,   418,   273,   374,   262,   371,   372,   370,
     373,   253,   384,   256,   383,   247,   240,   197,   385,   214,
     392,   435,   421,   451,     0,   422,     0,     0,     0,   313,
       0,   285,   286,     0,   289,   326,   352,   325,   349,   322,
     340,   323,   343,   324,   346,   329,   331,   330,   327,   328,
     351,   350,   348,   347,   339,   338,   342,   341,   345,   344,
     336,   335,   379,   376,   377,   375,   378,     0,   391,   398,
     364,   361,   362,   360,   363,   386,   387,   393,   394,   399,
     400,   404,   405,   409,   410,   414,   415,   369,   366,   367,
     365,   368,   389,   388,   396,   395,   402,   401,   407,   406,
     412,   411,   417,   416,   359,   356,   357,   355,   358,   419,
       0,   390,   397,   403,   408,   413,   418,   374,   371,   372,
     370,   373,   384,   383,   385,   392,   326,   325,   322,   323,
     324,    79,    34,     0,     0,     0,    75,    78,   438,   437,
       0,    58,    55,     0,     0,     0,     0,     0,     0,    74,
       0,     0,   298,     0,     0,   113,     0,     0,   315,   114,
       0,     0,    24,     0,     0,   110,     0,   115,   112,   111,
     420,     0,    77,    76,     0,     0,   113,   287,   290,     0,
       0,     0,   297,     0,     0,   296,     0,     0,     0,     0,
     439,     0,    59,     0,    56,    60,    62,    67,    72,     0,
       0,    70,   302,     0,   300,     0,   299,     0,     0,     0,
      46,    25,    26,     0,    52,    95,   423,    65,     0,   297,
       0,   296,     0,     0,     0,     0,     0,     0,     0,     0,
      57,     0,    61,     0,     0,     0,    68,   305,   304,     0,
     303,     0,   301,     0,   316,    27,    48,    54,    50,     0,
      66,   293,    28,    29,    41,    44,   294,     0,    42,    45,
      40,    43,    64,    63,    73,    71,   308,   307,   306,     0,
       0,    51,     0,   309,   317,   295
  };

  const short
   Parser ::yypgoto_[] =
  {
    -765,  -765,  -118,   496,   -31,   -21,   -27,    76,  -764,  -765,
     458,  -765,  -765,  -765,  -765,  -765,  -765,  -765,  -765,  -765,
    -765,  -765,  -765,  -711,  -765,  -765,   738,  -765,   144,   705,
    -765,   666,  -765,  1704,   227,     8,   739,  1949,  -708,   569,
    1761,  1598,  2166,   -59,   -77,    -8,   878,   483,  1229,  -765,
      33,  -765,   447,   262
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    31,    32,   128,    33,    34,   863,   864,   135,    35,
      96,    36,    37,    38,    39,    40,    41,    42,    43,   858,
      44,   859,    45,   754,   755,    46,   111,   759,   760,    47,
      48,    49,   374,    50,    51,    52,    78,    67,   793,   794,
     178,    68,    69,   117,   346,    56,   332,   333,   334,    60,
     634,    61,   118,    62
  };

  const short
   Parser ::yytable_[] =
  {
      70,   125,    83,    87,    93,   251,   820,     7,   677,   246,
     824,    94,    95,   246,   356,   134,    66,    99,   246,   -69,
     246,   133,    97,   246,   246,    74,     3,     4,     5,     6,
       7,     8,   259,     9,    75,   100,   797,   799,    10,   801,
     802,   260,   112,   100,   113,   100,    11,   100,   188,   781,
     109,    12,   636,   100,   100,   189,   190,   123,   124,   110,
       2,     3,     4,     5,     6,     7,     8,   122,     9,   261,
     114,   262,    83,    10,   247,     3,     4,   280,   746,   757,
      79,    11,   830,   314,   315,   806,    12,    80,   811,   875,
     130,   101,   331,   352,   842,   881,    76,    30,   115,   103,
      12,  -437,   136,   105,   331,  -451,   348,   758,  -437,   107,
     243,   331,   348,    13,    14,    15,   119,    16,    17,    18,
      19,    20,    21,    22,   284,    23,    24,    25,    26,    27,
      28,    29,    30,   640,   249,   285,   286,    23,    24,    25,
      26,   245,   641,   633,   120,    81,    82,   331,   379,   383,
     387,   390,   393,   348,   400,   348,   348,   348,   411,   413,
     415,   417,   419,   424,   432,   437,   441,   445,   449,   348,
     261,   331,   348,   348,   348,   348,   348,   348,   253,   469,
     348,   348,   348,   482,   348,   348,   348,   493,   496,   499,
     502,   505,   507,   512,   348,   519,   521,   523,   525,   527,
     529,   532,   535,   538,   541,   544,   547,   550,   553,   556,
     559,   562,   567,   348,   574,   577,   580,   583,   586,   589,
     331,   595,   348,   348,   348,   348,   348,   348,   348,   617,
     348,   348,   348,   348,   348,    65,   771,   126,   321,   192,
     127,   322,   331,   154,   327,   155,   193,   194,   775,   156,
     157,   158,   159,   160,   161,   632,   645,   647,   649,   651,
     653,   655,   656,   657,   658,   659,   660,   662,   664,   666,
     668,   670,   100,   177,   285,   286,   673,   751,   776,   681,
     685,   687,   689,   691,   693,   695,   698,   702,   704,   706,
     708,   710,   712,   715,    87,    87,    87,    87,    87,    87,
      87,   728,    87,    87,    87,    87,   100,   751,   736,   737,
     738,   739,   740,    23,    24,    25,    26,   100,   752,   633,
     844,   250,   341,   113,   154,   125,   155,   329,   115,   765,
     753,   154,   769,   155,   331,   161,   743,   777,   778,   329,
     786,   347,    23,    24,    25,    26,   329,   351,   633,   114,
      23,    24,    25,    26,   177,   344,   633,   240,   766,   326,
     753,   766,   115,   354,   241,   242,   766,   766,   834,   766,
     835,   339,    23,    24,    25,    26,   814,   357,   633,   637,
     345,   340,   329,   377,   381,   385,   389,   392,   395,   397,
     404,   406,   408,   410,   412,   414,   416,   418,   420,   428,
     436,   440,   444,   448,   452,   815,   329,   454,   456,   458,
     460,   462,   464,   639,   466,   473,   475,   477,   479,   486,
     488,   490,   492,   495,   498,   501,   504,   642,   509,   516,
     518,   520,   522,   524,   526,   528,   531,   534,   537,   540,
     543,   546,   549,   552,   555,   558,   561,   564,   571,   573,
     576,   579,   582,   585,   588,   329,   592,   599,   602,   604,
     606,   608,   610,   612,   614,   621,   623,   625,   627,   629,
     102,   104,   106,   108,   131,   784,   852,   329,   744,   154,
     745,   155,   750,    58,   132,   156,   157,   158,   159,   160,
     161,    72,    58,   749,    89,   316,   317,   318,   319,   320,
     169,   170,    58,   758,   767,   853,   269,   244,   635,   177,
     272,   273,   318,   319,   320,    58,   643,     3,     4,     5,
       6,     7,     8,   768,     9,    58,     3,     4,   770,    10,
     310,    79,   129,    23,    24,    25,    26,    11,    80,   633,
     312,   313,    12,   137,   138,   139,   153,   773,   335,   187,
     336,    12,   337,   188,   338,   774,   154,    58,   155,   179,
     189,   190,   349,   200,   158,   159,   160,   161,   282,   329,
     219,     3,     4,     5,     6,     7,     8,   783,     9,   328,
       3,   312,   313,    10,   179,    91,   177,    76,    30,   191,
     182,    11,    92,   192,   228,   279,    12,   779,   780,   257,
     193,   194,   756,   761,   787,    12,   238,    58,   342,   240,
     237,   238,   239,    58,   240,    58,   241,   242,   789,    58,
     803,   241,   242,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,   804,    58,   256,   228,
     805,    76,    30,   809,   808,   402,   179,   819,   409,   229,
     180,   181,   182,   230,   426,   434,   439,   443,   447,   451,
     231,   232,   233,   234,   235,   236,   810,   822,   228,   330,
     471,   828,   832,   833,   484,     3,     4,     5,     6,     7,
       8,   343,     9,   328,   514,   228,   836,    10,   350,   837,
     631,   233,   234,   235,   236,    11,   838,   839,   840,   230,
      12,   841,   843,   569,   847,   855,   231,   232,   233,   234,
     235,   236,   597,   601,   603,   605,   607,   609,   611,   613,
     619,   237,   238,   239,   376,   240,   197,   198,   199,   200,
     807,   856,   241,   242,   857,   795,   795,   795,   861,   256,
     125,   310,   311,   134,    58,    76,    30,   134,   453,   133,
     301,   312,   313,   133,   302,   331,   874,   827,   331,   876,
     877,   303,   304,   305,   306,   307,   308,   675,   238,   239,
     683,   240,   880,   882,   883,   748,   345,   700,   241,   242,
     742,   785,   831,   846,   717,   719,   721,   722,   723,   724,
     725,   726,   730,    89,    89,    89,    89,   591,    66,   228,
     248,   860,   325,   884,    58,   126,   359,   331,   127,   331,
      58,   862,   862,   258,   826,   862,   862,   862,   862,   638,
     231,   232,   233,   234,   235,   236,   331,   331,     0,   309,
     310,   311,   134,   216,   217,   218,   219,    58,   133,    58,
     312,   313,     0,     0,     0,   331,     0,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,     0,   151,
     152,     1,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,   331,     0,     0,    10,    57,     0,
       0,   228,     0,     0,     0,    11,    71,    57,    84,    88,
      12,   229,     0,     0,     0,   230,     0,    57,     0,   761,
       0,     0,   231,   232,   233,   234,   235,   236,     0,   865,
      57,   764,   868,   869,   870,   871,     0,    13,    14,    15,
      57,    16,    17,    18,    19,    20,    21,    22,     0,    23,
      24,    25,    26,    27,    28,    29,    30,     0,     0,   154,
       0,   155,     0,     0,     0,   156,   157,   158,   159,   160,
     161,     0,    57,    23,    24,    25,    26,   263,    84,   633,
     169,   170,     0,   281,   173,   174,   175,   176,     0,   177,
     792,   792,   792,     0,     0,     3,     4,     5,     6,     7,
       8,   373,     9,   266,   267,   268,   200,    10,     0,     0,
     329,     0,     0,   329,     0,    11,   276,   277,   278,   279,
      12,     0,    57,   316,   317,   318,   319,   320,    57,     0,
      57,     0,   756,   756,    57,     0,     0,   829,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,     0,    57,     0,   380,   384,   388,   391,   394,   396,
     401,     0,   329,   635,   329,    76,    30,     0,   302,   425,
     433,   438,   442,   446,   450,   303,   304,   305,   306,   307,
     308,   329,   329,     0,     0,   470,     0,   756,     0,   483,
       0,   845,     0,   494,   497,   500,   503,   506,   508,   513,
     329,   305,   306,   307,   308,     0,   530,   533,   536,   539,
     542,   545,   548,   551,   554,   557,   560,   563,   568,   257,
     575,   578,   581,   584,   587,   590,     0,   596,     0,   329,
     309,   310,   311,     0,     0,   618,     0,     0,     0,    58,
       0,   312,   313,     0,     0,     0,    58,     0,   214,   215,
     216,   217,   218,   219,    23,    24,    25,    26,     0,    57,
     323,   324,   646,   648,   650,   652,   654,   224,   225,   226,
     227,     0,   661,   663,   665,   667,   669,   671,     0,     0,
       0,     0,   674,     0,     0,   682,   686,   688,   690,   692,
     694,   696,   699,   703,   705,   707,   709,   711,   713,   716,
      88,    88,    88,    88,    88,    88,    88,   729,    88,    88,
      88,    88,     0,     0,     0,     0,   800,     0,     0,    57,
     316,   317,   318,   319,   320,    57,     0,     0,     0,     0,
       0,   269,   800,   271,     0,   272,   273,     0,     0,     3,
       4,     5,     6,     7,    85,     0,    58,    58,    58,    59,
       0,    80,    57,     0,    57,     0,     0,    73,    59,    11,
      90,   179,     0,     0,    12,   180,   181,   182,    59,     0,
       0,     0,     0,    58,    58,   183,    58,    58,     0,    58,
     255,    59,   184,   185,     0,   274,   275,   276,   277,   278,
     279,    59,     0,    72,     3,     4,     5,     6,     7,     8,
       0,     9,   762,     0,     0,     0,    10,     0,     3,     4,
       5,     6,    63,    85,    11,     0,     0,     0,     0,    12,
      80,     0,    58,    59,     0,     0,     0,     0,    11,     0,
       0,   763,     0,    12,   283,    58,    58,     0,     0,    58,
      58,    58,    58,     0,    58,   179,    58,     0,     0,   180,
     181,   182,   813,     0,     0,   818,   195,   196,   197,   198,
     199,   200,    58,     0,    76,    30,   184,   185,     0,     0,
       0,   206,   207,    59,     0,   210,   211,   212,   213,    59,
       0,    59,     0,     0,     0,    59,     0,     0,     0,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,     0,    59,   849,     0,   851,     0,     0,     0,
       0,   403,   405,   407,   195,   196,   197,   198,   199,   200,
     427,   435,     0,   866,   867,     0,     3,     4,     5,     6,
       7,     8,     0,     9,   816,     0,   472,     0,    10,     0,
     485,     0,   879,     0,     0,     0,    11,     0,     0,     0,
     515,    12,   124,     0,     2,     3,     4,     5,     6,     7,
       8,     0,     9,   817,     0,   772,     0,    10,     0,   570,
       0,   885,     0,     0,     0,    11,     0,     0,   598,     0,
      12,     0,     0,     0,     0,     0,   620,   622,   624,   301,
     628,   630,     0,   302,     0,     0,    76,    30,     0,     0,
     303,   304,   305,   306,   307,   308,     0,    13,    14,    15,
      59,    16,    17,    18,    19,    20,    21,    22,     0,    23,
      24,    25,    26,    27,    28,    29,    30,   214,   215,   216,
     217,   218,   219,   676,    57,     0,   684,   221,     0,     0,
       0,    57,     0,   701,   222,   223,   224,   225,   226,   227,
     718,   720,   720,   720,   720,   720,   720,   720,   731,   732,
     733,   734,   735,   214,   215,   216,   217,   218,   219,     0,
      59,   316,   317,   318,   319,   320,    59,     3,     4,     5,
       6,     7,     8,     0,     9,     0,   272,   273,     0,    10,
       0,   195,   196,   197,   198,   199,   200,    11,     0,     0,
       0,     0,    12,    59,     0,    59,   206,   207,     3,     4,
       5,     6,     7,     8,   342,     9,     0,   113,    54,     0,
      10,   274,   275,   276,   277,   278,   279,    54,    11,    86,
       0,     0,     0,    12,     0,     0,     0,    54,     0,     0,
       0,    57,    57,    57,     0,     0,   254,    76,    30,     0,
      54,   264,   265,   266,   267,   268,   200,     0,     0,     0,
      54,     0,   269,   270,   271,     0,   272,   273,    57,    57,
       0,    57,    57,     0,    57,     0,     0,     0,    76,    30,
       0,     0,     3,     4,     5,     6,     7,     8,    71,     9,
     812,     0,    54,     0,    10,   303,   304,   305,   306,   307,
     308,     0,    11,    86,   254,     0,     0,    12,     0,   316,
     317,   318,   319,   320,     0,     0,     0,    57,     0,     0,
     269,   270,   271,     0,   272,   273,     0,     0,     0,     0,
      57,    57,     0,    77,    57,    57,    57,    57,     0,    57,
       0,    57,    54,    98,     0,     0,     0,     0,    54,     0,
      54,     0,    76,    30,    54,     0,     0,    57,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,     0,    54,     0,     0,     0,     0,     0,     0,     0,
     398,     0,     0,     0,     0,     0,     0,     0,     0,   422,
     430,     0,     3,     4,     5,     6,     7,     8,    77,     9,
     848,     0,     0,     0,    10,   467,     0,   476,   478,   480,
     116,   121,    11,     0,     0,     0,     0,    12,     0,   510,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     9,   850,     0,   186,     0,    10,     0,   565,     0,
       0,     0,     0,     0,    11,   116,     0,   593,   186,    12,
       0,     0,     0,     0,   353,   615,     0,   116,     0,     0,
     358,     0,    76,    30,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,     0,   375,    54,
       0,     0,     0,     0,     0,    59,     3,     4,     5,     6,
      63,     8,    59,     9,    76,    30,     0,     0,    10,     0,
       0,     0,   672,   678,   679,   680,    11,     0,     0,     0,
       0,    12,   697,     0,     0,     0,     0,     0,     0,   714,
      86,    86,    86,    86,    86,    86,    86,   727,    86,    86,
      86,    86,     0,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,    54,     3,     4,     5,     6,
       7,     8,     0,     9,   878,     0,    64,    30,    10,     0,
     264,   265,   266,   267,   268,   200,    11,     0,     0,    53,
       0,    12,    54,     0,    54,   272,   273,     0,    53,     3,
       4,     5,     6,     7,     8,   644,     9,     0,    53,     0,
       0,    10,    59,    59,    59,     0,     0,     0,     0,    11,
       0,    53,     0,     0,    12,     0,     0,     0,     0,     0,
       0,    53,     0,     0,     0,     0,    76,    30,     0,    59,
      59,     0,    59,    59,     0,    59,     0,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,    73,
     151,   152,     0,    53,     0,   741,     0,     0,     0,    76,
      30,   747,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,   790,     0,     9,     0,     0,    59,     0,
      10,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,    59,    59,    12,     0,    59,    59,    59,    59,     0,
      59,     0,    59,    53,     0,     0,     0,     0,     0,    53,
       0,    53,     0,     0,     0,    53,     0,     0,    59,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,     0,    53,     0,   378,   382,   386,    76,    30,
       0,   264,   265,   266,   267,   268,   200,     0,     0,     0,
     421,   429,   269,   270,   271,     0,   272,   273,     0,   455,
     457,   459,   461,   463,   465,     0,     0,   474,     0,   186,
       0,   487,     0,   186,     0,     0,     0,   186,     0,     0,
       0,   517,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,     0,     0,     0,
     572,     0,     0,     0,     0,    55,     0,     0,     0,   600,
       0,     0,   186,     0,     0,    55,     0,     0,     0,   626,
     186,     0,     3,     4,     5,     6,    63,   790,    55,     9,
       0,     0,     0,     0,    10,     0,     0,     0,    55,     0,
      53,     0,    11,     0,     0,     0,   186,    12,   186,     0,
     186,     0,   186,     0,   186,     0,   186,     0,     0,     0,
       0,     0,     0,     0,    54,   186,     0,     0,     0,     0,
      55,    54,     0,     0,     0,     0,     0,     0,   186,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   154,     0,
     155,     0,    64,    30,   156,   157,   158,   159,   160,   161,
      53,     0,     0,     0,     0,   166,    53,   168,   186,   169,
     170,   171,   172,   173,   174,   175,   176,     0,   177,     0,
      55,     0,     0,     0,     0,     0,    55,     0,    55,     0,
       0,     0,    55,    53,     0,    53,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,     0,
      55,     0,     0,     0,     0,     0,     0,     0,   399,     0,
       0,     0,     0,   186,     0,     0,     0,   423,   431,     0,
     782,    54,    54,    54,     0,     0,     0,   788,     0,     0,
       0,     0,     0,   468,     0,     0,     0,   481,     0,   489,
     491,   186,     0,     0,     0,     0,     0,   511,    54,    54,
       0,    54,    54,     0,    54,     0,     0,     0,     0,     0,
       0,     0,     0,   154,     0,   155,   566,   186,     0,   156,
     157,   158,   159,   160,   161,   594,   163,   164,     0,   165,
     166,   167,   168,   616,   169,   170,   171,   172,   173,   174,
     175,   176,     0,   177,     0,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,     0,     0,
      54,    54,     0,     0,    54,    54,    54,    54,     0,    54,
       0,    54,     0,     0,   154,     0,   155,   791,   796,   798,
     156,   157,   158,   159,   160,   161,     0,    54,     0,     0,
     165,   166,   167,   168,     0,   169,   170,   171,   172,   173,
     174,   175,   176,     0,   177,     0,     0,   823,     0,     0,
     825,     0,     0,     0,     0,     0,     0,    55,     0,     0,
       0,     0,     0,    55,     0,     0,   124,     0,     2,     3,
       4,     5,     6,     7,     8,     0,     9,   255,     0,   821,
       0,    10,   274,   275,   276,   277,   278,   279,   294,    11,
      55,     0,    55,   854,    12,     0,     0,     0,     0,   295,
     296,   297,   298,   299,   300,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   872,     0,   873,     0,     0,
       0,    13,    14,    15,     0,    16,    17,    18,    19,    20,
      21,    22,     0,    23,    24,    25,    26,    27,    28,    29,
      30,     0,     0,   131,     3,     4,     5,     6,     7,     8,
       0,     9,     0,   132,     0,    53,    10,     0,     0,     0,
       0,     0,    53,     0,    11,     0,     0,     0,     0,    12,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,   355,     0,    10,     0,     0,     0,
       0,     0,     0,     0,    11,     0,    13,    14,    15,    12,
      16,    17,    18,    19,    20,    21,    22,     0,    23,    24,
      25,    26,    27,    28,    29,    30,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,    14,    15,     0,
      16,    17,    18,    19,    20,    21,    22,     0,    23,    24,
      25,    26,    27,    28,    29,    30,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,     0,    10,
       0,     0,    53,    53,    53,     0,     0,    11,     0,     0,
       0,     0,    12,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      53,     0,    53,    53,     0,    53,     0,     0,     0,    13,
      14,    15,     0,    16,    17,    18,    19,    20,    21,    22,
       0,    23,    24,    25,    26,    27,    28,    29,    30,   154,
       0,   155,     0,     0,     0,   156,   157,   158,   159,   160,
     161,     0,     0,     0,     0,     0,   166,     0,    53,     0,
     169,   170,   171,   172,   173,   174,   175,   176,     0,   177,
       0,    53,    53,     0,     0,    53,    53,    53,    53,     0,
      53,     0,    53,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,   154,   252,   155,     0,    53,    55,
     156,   157,   158,   159,   160,   161,   162,   163,   164,     0,
     165,   166,   167,   168,     0,   169,   170,   171,   172,   173,
     174,   175,   176,     0,   177,   154,   -97,   155,     0,     0,
       0,   156,   157,   158,   159,   160,   161,   162,   163,   164,
       0,   165,   166,   167,   168,     0,   169,   170,   171,   172,
     173,   174,   175,   176,   154,   177,   155,     0,     0,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,     0,
     165,   166,   167,   168,     0,   169,   170,   171,   172,   173,
     174,   175,   176,     0,   177,   154,     0,   155,     0,     0,
       0,   156,   157,   158,   159,   160,   161,     0,     0,    55,
      55,    55,   166,   167,   168,     0,   169,   170,   171,   172,
     173,   174,   175,   176,     0,   177,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,    55,     0,    55,
      55,   154,    55,   155,     0,     0,     0,   156,   157,   158,
     159,   160,   161,     0,   163,     0,     0,   165,   166,   167,
     168,     0,   169,   170,   171,   172,   173,   174,   175,   176,
     254,   177,     0,     0,     0,   264,   265,   266,   267,   268,
     200,   287,     0,     0,     0,    55,   269,   270,   271,     0,
     272,   273,   288,   289,   290,   291,   292,   293,    55,    55,
       0,     0,    55,    55,    55,    55,   154,    55,   155,    55,
       0,     0,   156,   157,   158,   159,   160,   161,     0,     0,
       0,     0,     0,     0,     0,    55,     0,   169,   170,   171,
     172,   173,   174,   175,   176,   254,   177,     0,     0,     0,
     195,   196,   197,   198,   199,   200,   201,     0,     0,     0,
     202,   203,   204,   205,     0,   206,   207,   208,   209,   210,
     211,   212,   213,  -100,     0,     0,     0,     0,   195,   196,
     197,   198,   199,   200,   201,     0,     0,     0,   202,   203,
     204,   205,     0,   206,   207,   208,   209,   210,   211,   212,
     213,   255,     0,     0,     0,     0,   214,   215,   216,   217,
     218,   219,   220,     0,     0,     0,   221,     0,     0,     0,
       0,     0,     0,   222,   223,   224,   225,   226,   227,   195,
     196,   197,   198,   199,   200,   201,     0,     0,     0,   202,
     203,   204,   205,     0,   206,   207,   208,   209,   210,   211,
     212,   213,   264,   265,   266,   267,   268,   200,   287,     0,
       0,     0,     0,   269,   270,   271,     0,   272,   273,   288,
     289,   290,   291,   292,   293,   195,   196,   197,   198,   199,
     200,     0,     0,     0,     0,   202,   203,   204,   205,     0,
     206,   207,   208,   209,   210,   211,   212,   213,   264,   265,
     266,   267,   268,   200,     0,     0,     0,     0,     0,   269,
     270,   271,     0,   272,   273,   288,   289,   290,   291,   292,
     293,   195,   196,   197,   198,   199,   200,     0,     0,     0,
       0,     0,   203,     0,   205,     0,   206,   207,   208,   209,
     210,   211,   212,   213,   195,   196,   197,   198,   199,   200,
       0,     0,     0,     0,     0,   203,     0,     0,     0,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,     0,     0,     0,   221,   195,   196,
     197,   198,   199,   200,   222,   223,   224,   225,   226,   227,
       0,     0,     0,   206,   207,   208,   209,   210,   211,   212,
     213,   274,   275,   276,   277,   278,   279,   294,   274,   275,
     276,   277,   278,   279,     0,     0,     0,     0,   295,   296,
     297,   298,   299,   300,     0,   295,   296,   297,   298,   299,
     300
  };

  const short
   Parser ::yycheck_[] =
  {
       8,    32,    10,    11,    12,    64,   770,     8,     9,     9,
     774,    74,    74,     9,   132,    42,     8,    74,     9,     9,
       9,    42,     9,     9,     9,     3,     4,     5,     6,     7,
       8,     9,     3,    11,    12,    11,   744,   745,    16,   750,
     751,    12,    11,    11,    13,    11,    24,    11,    25,    40,
      74,    29,    42,    11,    11,    32,    33,     0,     1,    74,
       3,     4,     5,     6,     7,     8,     9,     0,    11,    40,
      39,    79,    80,    16,    74,     4,     5,    85,    74,    10,
       9,    24,   790,    91,    92,    74,    29,    16,    74,    74,
       9,    67,   100,   124,   805,   859,    74,    75,    67,    67,
      29,    67,     9,    67,   112,    74,   114,    38,    74,    67,
      67,   119,   120,    56,    57,    58,    11,    60,    61,    62,
      63,    64,    65,    66,    21,    68,    69,    70,    71,    72,
      73,    74,    75,     3,    10,    32,    33,    68,    69,    70,
      71,    67,    12,    74,    39,    74,    75,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
      40,   179,   180,   181,   182,   183,   184,   185,    10,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     8,   354,     0,    42,    25,
       3,    40,   250,     9,    42,    11,    32,    33,    10,    15,
      16,    17,    18,    19,    20,    10,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,    11,    39,    32,    33,   284,     3,    40,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,    11,     3,   316,   317,
     318,   319,   320,    68,    69,    70,    71,    11,    14,    74,
      38,    11,     9,    13,     9,   356,    11,   100,    67,    12,
      56,     9,    12,    11,   342,    20,    41,    12,    12,   112,
      12,   114,    68,    69,    70,    71,   119,   120,    74,    39,
      68,    69,    70,    71,    39,    14,    74,    25,    41,    97,
      56,    41,    67,    13,    32,    33,    41,    41,    38,    41,
      40,     3,    68,    69,    70,    71,    12,    61,    74,     9,
      39,    13,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,    41,   179,   180,   181,   182,
     183,   184,   185,    10,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    12,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      23,    24,    25,    26,     3,    10,    12,   250,    41,     9,
      41,    11,    13,     0,    13,    15,    16,    17,    18,    19,
      20,     8,     9,    12,    11,    15,    16,    17,    18,    19,
      30,    31,    19,    38,    74,    41,    26,    60,   246,    39,
      30,    31,    17,    18,    19,    32,     3,     4,     5,     6,
       7,     8,     9,    14,    11,    42,     4,     5,    10,    16,
      22,     9,    36,    68,    69,    70,    71,    24,    16,    74,
      32,    33,    29,    47,    48,    49,    50,     9,   101,    21,
     103,    29,   105,    25,   107,    10,     9,    74,    11,    11,
      32,    33,   115,    20,    17,    18,    19,    20,    85,   342,
      20,     4,     5,     6,     7,     8,     9,   636,    11,    12,
       4,    32,    33,    16,    11,     9,    39,    74,    75,    21,
      17,    24,    16,    25,    11,    20,    29,    12,    10,    10,
      32,    33,   340,   341,    12,    29,    22,   124,    41,    25,
      21,    22,    23,   130,    25,   132,    32,    33,     8,   136,
      74,    32,    33,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    14,   154,    10,    11,
       3,    74,    75,    40,    74,   162,    11,    42,   165,    21,
      15,    16,    17,    25,   171,   172,   173,   174,   175,   176,
      32,    33,    34,    35,    36,    37,    10,     3,    11,   100,
     187,    10,    10,    10,   191,     4,     5,     6,     7,     8,
       9,   112,    11,    12,   201,    11,    10,    16,   119,    10,
     243,    34,    35,    36,    37,    24,    10,    10,    14,    25,
      29,    42,    42,   220,    12,     3,    32,    33,    34,    35,
      36,    37,   229,   230,   231,   232,   233,   234,   235,   236,
     237,    21,    22,    23,   155,    25,    17,    18,    19,    20,
     757,    10,    32,    33,    59,   743,   744,   745,    10,    10,
     771,    22,    23,   770,   261,    74,    75,   774,   179,   770,
      21,    32,    33,   774,    25,   763,    74,   784,   766,    12,
      12,    32,    33,    34,    35,    36,    37,   284,    22,    23,
     287,    25,    40,    38,    12,   328,    39,   294,    32,    33,
     322,   637,   790,   810,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   228,   790,    11,
      62,   828,    97,   880,   321,     0,   140,   815,     3,   817,
     327,   832,   833,    74,   781,   836,   837,   838,   839,   250,
      32,    33,    34,    35,    36,    37,   834,   835,    -1,    21,
      22,    23,   859,    17,    18,    19,    20,   354,   859,   356,
      32,    33,    -1,    -1,    -1,   853,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,     0,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    -1,   882,    -1,    -1,    16,     0,    -1,
      -1,    11,    -1,    -1,    -1,    24,     8,     9,    10,    11,
      29,    21,    -1,    -1,    -1,    25,    -1,    19,    -1,   637,
      -1,    -1,    32,    33,    34,    35,    36,    37,    -1,   833,
      32,   342,   836,   837,   838,   839,    -1,    56,    57,    58,
      42,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,     9,
      -1,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,    74,    68,    69,    70,    71,    79,    80,    74,
      30,    31,    -1,    85,    34,    35,    36,    37,    -1,    39,
     743,   744,   745,    -1,    -1,     4,     5,     6,     7,     8,
       9,    10,    11,    17,    18,    19,    20,    16,    -1,    -1,
     763,    -1,    -1,   766,    -1,    24,    17,    18,    19,    20,
      29,    -1,   124,    15,    16,    17,    18,    19,   130,    -1,
     132,    -1,   750,   751,   136,    -1,    -1,   790,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,    -1,   154,    -1,   156,   157,   158,   159,   160,   161,
     162,    -1,   815,   781,   817,    74,    75,    -1,    25,   171,
     172,   173,   174,   175,   176,    32,    33,    34,    35,    36,
      37,   834,   835,    -1,    -1,   187,    -1,   805,    -1,   191,
      -1,   809,    -1,   195,   196,   197,   198,   199,   200,   201,
     853,    34,    35,    36,    37,    -1,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,    10,
     222,   223,   224,   225,   226,   227,    -1,   229,    -1,   882,
      21,    22,    23,    -1,    -1,   237,    -1,    -1,    -1,   636,
      -1,    32,    33,    -1,    -1,    -1,   643,    -1,    15,    16,
      17,    18,    19,    20,    68,    69,    70,    71,    -1,   261,
      74,    75,   264,   265,   266,   267,   268,    34,    35,    36,
      37,    -1,   274,   275,   276,   277,   278,   279,    -1,    -1,
      -1,    -1,   284,    -1,    -1,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,    -1,    -1,    -1,    -1,   749,    -1,    -1,   321,
      15,    16,    17,    18,    19,   327,    -1,    -1,    -1,    -1,
      -1,    26,   765,    28,    -1,    30,    31,    -1,    -1,     4,
       5,     6,     7,     8,     9,    -1,   743,   744,   745,     0,
      -1,    16,   354,    -1,   356,    -1,    -1,     8,     9,    24,
      11,    11,    -1,    -1,    29,    15,    16,    17,    19,    -1,
      -1,    -1,    -1,   770,   771,    25,   773,   774,    -1,   776,
      10,    32,    32,    33,    -1,    15,    16,    17,    18,    19,
      20,    42,    -1,   790,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    -1,    -1,    16,    -1,     4,     5,
       6,     7,     8,     9,    24,    -1,    -1,    -1,    -1,    29,
      16,    -1,   819,    74,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    41,    -1,    29,    85,   832,   833,    -1,    -1,   836,
     837,   838,   839,    -1,   841,    11,   843,    -1,    -1,    15,
      16,    17,   763,    -1,    -1,   766,    15,    16,    17,    18,
      19,    20,   859,    -1,    74,    75,    32,    33,    -1,    -1,
      -1,    30,    31,   124,    -1,    34,    35,    36,    37,   130,
      -1,   132,    -1,    -1,    -1,   136,    -1,    -1,    -1,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,   154,   815,    -1,   817,    -1,    -1,    -1,
      -1,   162,   163,   164,    15,    16,    17,    18,    19,    20,
     171,   172,    -1,   834,   835,    -1,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,   187,    -1,    16,    -1,
     191,    -1,   853,    -1,    -1,    -1,    24,    -1,    -1,    -1,
     201,    29,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    41,    -1,    14,    -1,    16,    -1,   220,
      -1,   882,    -1,    -1,    -1,    24,    -1,    -1,   229,    -1,
      29,    -1,    -1,    -1,    -1,    -1,   237,   238,   239,    21,
     241,   242,    -1,    25,    -1,    -1,    74,    75,    -1,    -1,
      32,    33,    34,    35,    36,    37,    -1,    56,    57,    58,
     261,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    15,    16,    17,
      18,    19,    20,   284,   636,    -1,   287,    25,    -1,    -1,
      -1,   643,    -1,   294,    32,    33,    34,    35,    36,    37,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,    15,    16,    17,    18,    19,    20,    -1,
     321,    15,    16,    17,    18,    19,   327,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    30,    31,    -1,    16,
      -1,    15,    16,    17,    18,    19,    20,    24,    -1,    -1,
      -1,    -1,    29,   354,    -1,   356,    30,    31,     4,     5,
       6,     7,     8,     9,    41,    11,    -1,    13,     0,    -1,
      16,    15,    16,    17,    18,    19,    20,     9,    24,    11,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    19,    -1,    -1,
      -1,   743,   744,   745,    -1,    -1,    10,    74,    75,    -1,
      32,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      42,    -1,    26,    27,    28,    -1,    30,    31,   770,   771,
      -1,   773,   774,    -1,   776,    -1,    -1,    -1,    74,    75,
      -1,    -1,     4,     5,     6,     7,     8,     9,   790,    11,
      12,    -1,    74,    -1,    16,    32,    33,    34,    35,    36,
      37,    -1,    24,    85,    10,    -1,    -1,    29,    -1,    15,
      16,    17,    18,    19,    -1,    -1,    -1,   819,    -1,    -1,
      26,    27,    28,    -1,    30,    31,    -1,    -1,    -1,    -1,
     832,   833,    -1,     9,   836,   837,   838,   839,    -1,   841,
      -1,   843,   124,    19,    -1,    -1,    -1,    -1,   130,    -1,
     132,    -1,    74,    75,   136,    -1,    -1,   859,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,
     172,    -1,     4,     5,     6,     7,     8,     9,    74,    11,
      12,    -1,    -1,    -1,    16,   187,    -1,   189,   190,   191,
      29,    30,    24,    -1,    -1,    -1,    -1,    29,    -1,   201,
      -1,    -1,    -1,    -1,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    53,    -1,    16,    -1,   220,    -1,
      -1,    -1,    -1,    -1,    24,    64,    -1,   229,    67,    29,
      -1,    -1,    -1,    -1,   130,   237,    -1,    76,    -1,    -1,
     136,    -1,    74,    75,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,    -1,   154,   261,
      -1,    -1,    -1,    -1,    -1,   636,     4,     5,     6,     7,
       8,     9,   643,    11,    74,    75,    -1,    -1,    16,    -1,
      -1,    -1,   284,   285,   286,   287,    24,    -1,    -1,    -1,
      -1,    29,   294,    -1,    -1,    -1,    -1,    -1,    -1,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   321,
      -1,    -1,    -1,    -1,    -1,   327,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    74,    75,    16,    -1,
      15,    16,    17,    18,    19,    20,    24,    -1,    -1,     0,
      -1,    29,   354,    -1,   356,    30,    31,    -1,     9,     4,
       5,     6,     7,     8,     9,   261,    11,    -1,    19,    -1,
      -1,    16,   743,   744,   745,    -1,    -1,    -1,    -1,    24,
      -1,    32,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    74,    75,    -1,   770,
     771,    -1,   773,   774,    -1,   776,    -1,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,   790,
      54,    55,    -1,    74,    -1,   321,    -1,    -1,    -1,    74,
      75,   327,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,
       6,     7,     8,     9,    -1,    11,    -1,    -1,   819,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,   832,   833,    29,    -1,   836,   837,   838,   839,    -1,
     841,    -1,   843,   124,    -1,    -1,    -1,    -1,    -1,   130,
      -1,   132,    -1,    -1,    -1,   136,    -1,    -1,   859,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,   154,    -1,   156,   157,   158,    74,    75,
      -1,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
     171,   172,    26,    27,    28,    -1,    30,    31,    -1,   180,
     181,   182,   183,   184,   185,    -1,    -1,   188,    -1,   378,
      -1,   192,    -1,   382,    -1,    -1,    -1,   386,    -1,    -1,
      -1,   202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,    -1,    -1,
     221,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,   230,
      -1,    -1,   421,    -1,    -1,    19,    -1,    -1,    -1,   240,
     429,    -1,     4,     5,     6,     7,     8,     9,    32,    11,
      -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,    42,    -1,
     261,    -1,    24,    -1,    -1,    -1,   455,    29,   457,    -1,
     459,    -1,   461,    -1,   463,    -1,   465,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   636,   474,    -1,    -1,    -1,    -1,
      74,   643,    -1,    -1,    -1,    -1,    -1,    -1,   487,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,
      11,    -1,    74,    75,    15,    16,    17,    18,    19,    20,
     321,    -1,    -1,    -1,    -1,    26,   327,    28,   517,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    39,    -1,
     124,    -1,    -1,    -1,    -1,    -1,   130,    -1,   132,    -1,
      -1,    -1,   136,   354,    -1,   356,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,    -1,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,    -1,
      -1,    -1,    -1,   572,    -1,    -1,    -1,   171,   172,    -1,
     636,   743,   744,   745,    -1,    -1,    -1,   643,    -1,    -1,
      -1,    -1,    -1,   187,    -1,    -1,    -1,   191,    -1,   193,
     194,   600,    -1,    -1,    -1,    -1,    -1,   201,   770,   771,
      -1,   773,   774,    -1,   776,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    -1,    11,   220,   626,    -1,    15,
      16,    17,    18,    19,    20,   229,    22,    23,    -1,    25,
      26,    27,    28,   237,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    39,    -1,    -1,    -1,   819,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,
     832,   833,    -1,    -1,   836,   837,   838,   839,    -1,   841,
      -1,   843,    -1,    -1,     9,    -1,    11,   743,   744,   745,
      15,    16,    17,    18,    19,    20,    -1,   859,    -1,    -1,
      25,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    39,    -1,    -1,   773,    -1,    -1,
     776,    -1,    -1,    -1,    -1,    -1,    -1,   321,    -1,    -1,
      -1,    -1,    -1,   327,    -1,    -1,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    10,    -1,    14,
      -1,    16,    15,    16,    17,    18,    19,    20,    21,    24,
     354,    -1,   356,   819,    29,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   841,    -1,   843,    -1,    -1,
      -1,    56,    57,    58,    -1,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    13,    -1,   636,    16,    -1,    -1,    -1,
      -1,    -1,   643,    -1,    24,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    -1,    14,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    56,    57,    58,    29,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    -1,    -1,    -1,    16,
      -1,    -1,   743,   744,   745,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   770,
     771,    -1,   773,   774,    -1,   776,    -1,    -1,    -1,    56,
      57,    58,    -1,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,     9,
      -1,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    26,    -1,   819,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    39,
      -1,   832,   833,    -1,    -1,   836,   837,   838,   839,    -1,
     841,    -1,   843,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   636,    -1,     9,    10,    11,    -1,   859,   643,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      25,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    39,     9,    10,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    25,    26,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,     9,    39,    11,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      25,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    39,     9,    -1,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    -1,    -1,   743,
     744,   745,    26,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   770,   771,    -1,   773,
     774,     9,   776,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    -1,    22,    -1,    -1,    25,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      10,    39,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,   819,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,   832,   833,
      -1,    -1,   836,   837,   838,   839,     9,   841,    11,   843,
      -1,    -1,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   859,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    10,    39,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      25,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    10,    -1,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    25,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    10,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    25,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    25,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,    -1,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    25,    15,    16,
      17,    18,    19,    20,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    15,    16,    17,    18,    19,    20,    21,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37,    -1,    32,    33,    34,    35,    36,
      37
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     0,     3,     4,     5,     6,     7,     8,     9,    11,
      16,    24,    29,    56,    57,    58,    60,    61,    62,    63,
      64,    65,    66,    68,    69,    70,    71,    72,    73,    74,
      75,    78,    79,    81,    82,    86,    88,    89,    90,    91,
      92,    93,    94,    95,    97,    99,   102,   106,   107,   108,
     110,   111,   112,   114,   118,   119,   122,   123,   124,   125,
     126,   128,   130,     8,    74,   111,   112,   114,   118,   119,
     122,   123,   124,   125,     3,    12,    74,   110,   113,     9,
      16,    74,    75,   122,   123,     9,   118,   122,   123,   124,
     125,     9,    16,   122,    74,    74,    87,     9,   110,    74,
      11,    67,   129,    67,   129,    67,   129,    67,   129,    74,
      74,   103,    11,    13,    39,    67,   117,   120,   129,    11,
      39,   117,     0,     0,     1,    81,     0,     3,    80,    80,
       9,     3,    13,    82,    83,    85,     9,    80,    80,    80,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    54,    55,    80,     9,    11,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    25,    26,    27,    28,    30,
      31,    32,    33,    34,    35,    36,    37,    39,   117,    11,
      15,    16,    17,    25,    32,    33,   117,    21,    25,    32,
      33,    21,    25,    32,    33,    15,    16,    17,    18,    19,
      20,    21,    25,    26,    27,    28,    30,    31,    32,    33,
      34,    35,    36,    37,    15,    16,    17,    18,    19,    20,
      21,    25,    32,    33,    34,    35,    36,    37,    11,    21,
      25,    32,    33,    34,    35,    36,    37,    21,    22,    23,
      25,    32,    33,    67,   129,    67,     9,    74,   103,    10,
      11,   120,    10,    10,    10,    10,    10,    10,   113,     3,
      12,    40,   122,   123,    15,    16,    17,    18,    19,    26,
      27,    28,    30,    31,    15,    16,    17,    18,    19,    20,
     122,   123,   124,   125,    21,    32,    33,    21,    32,    33,
      34,    35,    36,    37,    21,    32,    33,    34,    35,    36,
      37,    21,    25,    32,    33,    34,    35,    36,    37,    21,
      22,    23,    32,    33,   122,   122,    15,    16,    17,    18,
      19,    42,    40,    74,    75,   106,   130,    42,    12,   111,
     116,   122,   123,   124,   125,   129,   129,   129,   129,     3,
      13,     9,    41,   116,    14,    39,   121,   111,   122,   129,
     116,   111,    81,   110,    13,    14,    79,    61,   110,   108,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,    10,   109,   110,   116,   111,   114,   122,
     123,   111,   114,   122,   123,   111,   114,   122,   123,   111,
     122,   123,   111,   122,   123,   111,   123,   111,   118,   119,
     122,   123,   124,   125,   111,   125,   111,   125,   111,   124,
     111,   122,   111,   122,   111,   122,   111,   122,   111,   122,
     111,   114,   118,   119,   122,   123,   124,   125,   111,   114,
     118,   119,   122,   123,   124,   125,   111,   122,   123,   124,
     111,   122,   123,   124,   111,   122,   123,   124,   111,   122,
     123,   124,   111,   116,   111,   114,   111,   114,   111,   114,
     111,   114,   111,   114,   111,   114,   111,   118,   119,   122,
     123,   124,   125,   111,   114,   111,   118,   111,   118,   111,
     118,   119,   122,   123,   124,   125,   111,   114,   111,   119,
     111,   119,   111,   122,   123,   111,   122,   123,   111,   122,
     123,   111,   122,   123,   111,   122,   123,   122,   123,   111,
     118,   119,   122,   123,   124,   125,   111,   114,   111,   122,
     111,   122,   111,   122,   111,   122,   111,   122,   111,   122,
     123,   111,   122,   123,   111,   122,   123,   111,   122,   123,
     111,   122,   123,   111,   122,   123,   111,   122,   123,   111,
     122,   123,   111,   122,   123,   111,   122,   123,   111,   122,
     123,   111,   122,   123,   111,   118,   119,   122,   123,   124,
     125,   111,   114,   111,   122,   123,   111,   122,   123,   111,
     122,   123,   111,   122,   123,   111,   122,   123,   111,   122,
     123,   116,   111,   118,   119,   122,   123,   124,   125,   111,
     114,   124,   111,   124,   111,   124,   111,   124,   111,   124,
     111,   124,   111,   124,   111,   118,   119,   122,   123,   124,
     125,   111,   125,   111,   125,   111,   114,   111,   125,   111,
     125,   129,    10,    74,   127,   130,    42,     9,   116,    10,
       3,    12,    12,     3,   110,   122,   123,   122,   123,   122,
     123,   122,   123,   122,   123,   122,   122,   122,   122,   122,
     122,   123,   122,   123,   122,   123,   122,   123,   122,   123,
     122,   123,   118,   122,   123,   124,   125,     9,   118,   118,
     118,   122,   123,   124,   125,   122,   123,   122,   123,   122,
     123,   122,   123,   122,   123,   122,   123,   118,   122,   123,
     124,   125,   122,   123,   122,   123,   122,   123,   122,   123,
     122,   123,   122,   123,   118,   122,   123,   124,   125,   124,
     125,   124,   124,   124,   124,   124,   124,   118,   122,   123,
     124,   125,   125,   125,   125,   125,   122,   122,   122,   122,
     122,   110,    87,    41,    41,    41,    74,   110,   129,    12,
      13,     3,    14,    56,   100,   101,   130,    10,    38,   104,
     105,   130,    12,    41,   116,    12,    41,    74,    14,    12,
      10,    79,    14,     9,    10,    10,    40,    12,    12,    12,
      10,    40,   110,   120,    10,   105,    12,    12,   110,     8,
       9,   110,   111,   115,   116,   122,   110,   115,   110,   115,
     129,   100,   100,    74,    14,     3,    74,    83,    74,    40,
      10,    74,    12,   116,    12,    41,    12,    41,   116,    42,
      85,    14,     3,   110,    85,   110,   127,    83,    10,   111,
     115,   122,    10,    10,    38,    40,    10,    10,    10,    10,
      14,    42,   100,    42,    38,   130,    83,    12,    12,   116,
      12,   116,    12,    41,   110,     3,    10,    59,    96,    98,
      83,    10,    82,    83,    84,    84,   116,   116,    84,    84,
      84,    84,   110,   110,    74,    74,    12,    12,    12,   116,
      40,    85,    38,    12,   121,   116
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    77,    78,    78,    79,    79,    79,    80,    80,    81,
      81,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    83,    83,    83,    83,    83,    84,    84,
      85,    85,    86,    87,    87,    88,    88,    88,    89,    89,
      90,    90,    90,    90,    90,    90,    91,    92,    93,    94,
      95,    96,    96,    97,    98,    99,    99,    99,   100,   100,
     100,   100,   101,   101,   101,   102,   102,   102,   102,   103,
     104,   104,   105,   105,   105,   106,   107,   107,   107,   107,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   109,   109,   110,   110,   110,   110,
     110,   110,   110,   110,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   112,   112,   112,   112,   112,   113,   113,
     113,   114,   114,   115,   115,   115,   116,   116,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     118,   118,   119,   119,   120,   120,   121,   121,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     126,   126,   127,   127,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   129,   129,   129,   129,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130
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
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
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
       4,     3,     1,     3,     2,     2,     2,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     4,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1
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
  "\"import\"", "\"if\"", "\"else\"", "\"for\"", "\"while\"", "\"do\"",
  "\"return\"", "\"break\"", "\"continue\"", "\"const\"", "\"?\"",
  "\"'int'\"", "\"'float'\"", "\"'string'\"", "\"'bool'\"", "\"'struct'\"",
  "\"'void'\"", "\"identifier\"", "\"external identifier\"", "NEG",
  "$accept", "start", "stmt", "stmt_end", "stmts", "stmts_ne", "block",
  "body", "scope_body", "import", "id_list", "flowctl", "return", "for",
  "while", "wh_kw", "dowhile", "do_kw", "if", "else", "if_kw", "el_kw",
  "struct", "decllist", "declistval", "function", "fun_id", "funargsnvar",
  "funargs", "vardecl", "vardef", "set", "callarglist", "expr", "expr_var",
  "matrix", "matvals", "expr_mat", "range", "int_val", "slice",
  "expr_none", "expr_struct", "struct_val", "struct_list", "expr_int",
  "expr_float", "expr_str", "expr_bool", "funtype", "typelist", "mattype",
  "matsq", "type", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   229,   229,   230,   232,   233,   234,   237,   238,   241,
     242,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   259,   260,   261,   262,   263,   266,   267,
     270,   271,   275,   277,   278,   282,   283,   284,   286,   287,
     291,   292,   293,   294,   295,   296,   300,   302,   304,   306,
     309,   311,   312,   314,   315,   318,   319,   320,   322,   323,
     324,   325,   327,   328,   329,   333,   334,   335,   336,   338,
     340,   341,   343,   344,   345,   350,   354,   355,   356,   357,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   378,   379,   383,   384,   385,   386,
     387,   388,   389,   390,   393,   394,   395,   396,   397,   399,
     400,   402,   403,   404,   405,   406,   408,   409,   410,   411,
     413,   414,   415,   417,   418,   419,   421,   422,   423,   424,
     425,   426,   427,   428,   430,   431,   432,   433,   434,   436,
     437,   438,   439,   440,   442,   443,   444,   445,   446,   447,
     448,   449,   451,   452,   453,   454,   455,   456,   457,   458,
     460,   461,   462,   464,   465,   466,   468,   469,   470,   471,
     472,   473,   474,   476,   477,   478,   479,   480,   481,   482,
     484,   485,   486,   487,   488,   489,   490,   492,   493,   494,
     495,   496,   497,   498,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   536,   537,
     538,   540,   541,   542,   544,   545,   546,   548,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   565,   566,   567,   569,   570,   571,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   600,   601,   602,   603,   604,   607,   608,
     609,   613,   614,   616,   617,   618,   620,   621,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     638,   639,   643,   644,   646,   647,   649,   650,   654,   655,
     656,   657,   658,   659,   660,   661,   662,   663,   664,   665,
     666,   667,   671,   672,   673,   674,   675,   676,   677,   678,
     679,   680,   681,   682,   683,   684,   685,   686,   687,   688,
     689,   690,   691,   695,   696,   697,   698,   699,   700,   701,
     702,   703,   704,   705,   706,   707,   708,   709,   710,   711,
     712,   713,   714,   715,   716,   717,   718,   719,   720,   721,
     725,   726,   727,   728,   729,   731,   732,   733,   734,   735,
     736,   737,   739,   740,   741,   742,   743,   744,   745,   747,
     748,   749,   750,   751,   753,   754,   755,   756,   757,   759,
     760,   761,   762,   763,   765,   766,   767,   768,   769,   771,
     775,   776,   778,   779,   783,   784,   785,   786,   787,   788,
     789,   790,   791,   792,   793,   794,   796,   797,   798,   799,
     803,   804,   805,   806,   807,   808,   809,   810,   811,   812,
     813,   814,   815,   816
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
#line 5000 "frontend/parser.cpp"

#line 819 "frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    auto msg = std::to_string(scanner->loc->begin.line) + ":" + std::to_string(scanner->loc->begin.column) + ": " + err_message;
    scanner->fatal_error(ptc::diag::ERR_SYNTAX, msg);
}
