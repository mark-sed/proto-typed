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

  case 120: // expr_var: expr_var "." "identifier"
#line 415 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1830 "frontend/parser.cpp"
    break;

  case 121: // expr_var: expr_var "." "external identifier"
#line 416 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1836 "frontend/parser.cpp"
    break;

  case 122: // expr_var: expr_float "**" expr_var
#line 419 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1842 "frontend/parser.cpp"
    break;

  case 123: // expr_var: expr_var "**" expr_float
#line 420 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1848 "frontend/parser.cpp"
    break;

  case 124: // expr_var: expr_var "**" expr_var
#line 421 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1854 "frontend/parser.cpp"
    break;

  case 125: // expr_var: expr_int "**" expr_var
#line 422 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < long > ()) /*Float on purpose*/, yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1860 "frontend/parser.cpp"
    break;

  case 126: // expr_var: expr_var "**" expr_int
#line 423 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < long > ()) /*Float on purpose*/, ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1866 "frontend/parser.cpp"
    break;

  case 127: // expr_var: expr_int "*" expr_var
#line 425 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1872 "frontend/parser.cpp"
    break;

  case 128: // expr_var: expr_float "*" expr_var
#line 426 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1878 "frontend/parser.cpp"
    break;

  case 129: // expr_var: expr_var "*" expr_int
#line 427 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1884 "frontend/parser.cpp"
    break;

  case 130: // expr_var: expr_var "*" expr_float
#line 428 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1890 "frontend/parser.cpp"
    break;

  case 131: // expr_var: expr_mat "*" expr_mat
#line 429 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1896 "frontend/parser.cpp"
    break;

  case 132: // expr_var: expr_mat "*" expr_var
#line 430 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1902 "frontend/parser.cpp"
    break;

  case 133: // expr_var: expr_var "*" expr_mat
#line 431 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1908 "frontend/parser.cpp"
    break;

  case 134: // expr_var: expr_var "*" expr_var
#line 432 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1914 "frontend/parser.cpp"
    break;

  case 135: // expr_var: expr_int "/" expr_var
#line 434 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1920 "frontend/parser.cpp"
    break;

  case 136: // expr_var: expr_float "/" expr_var
#line 435 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1926 "frontend/parser.cpp"
    break;

  case 137: // expr_var: expr_var "/" expr_int
#line 436 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1932 "frontend/parser.cpp"
    break;

  case 138: // expr_var: expr_var "/" expr_float
#line 437 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1938 "frontend/parser.cpp"
    break;

  case 139: // expr_var: expr_var "/" expr_var
#line 438 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1944 "frontend/parser.cpp"
    break;

  case 140: // expr_var: expr_int "%" expr_var
#line 440 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1950 "frontend/parser.cpp"
    break;

  case 141: // expr_var: expr_float "%" expr_var
#line 441 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1956 "frontend/parser.cpp"
    break;

  case 142: // expr_var: expr_var "%" expr_int
#line 442 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1962 "frontend/parser.cpp"
    break;

  case 143: // expr_var: expr_var "%" expr_float
#line 443 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1968 "frontend/parser.cpp"
    break;

  case 144: // expr_var: expr_var "%" expr_var
#line 444 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1974 "frontend/parser.cpp"
    break;

  case 145: // expr_var: expr_int "+" expr_var
#line 446 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1980 "frontend/parser.cpp"
    break;

  case 146: // expr_var: expr_float "+" expr_var
#line 447 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1986 "frontend/parser.cpp"
    break;

  case 147: // expr_var: expr_var "+" expr_int
#line 448 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1992 "frontend/parser.cpp"
    break;

  case 148: // expr_var: expr_var "+" expr_float
#line 449 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1998 "frontend/parser.cpp"
    break;

  case 149: // expr_var: expr_mat "+" expr_mat
#line 450 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2004 "frontend/parser.cpp"
    break;

  case 150: // expr_var: expr_var "+" expr_mat
#line 451 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2010 "frontend/parser.cpp"
    break;

  case 151: // expr_var: expr_mat "+" expr_var
#line 452 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2016 "frontend/parser.cpp"
    break;

  case 152: // expr_var: expr_var "+" expr_var
#line 453 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2022 "frontend/parser.cpp"
    break;

  case 153: // expr_var: expr_int "-" expr_var
#line 455 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2028 "frontend/parser.cpp"
    break;

  case 154: // expr_var: expr_float "-" expr_var
#line 456 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2034 "frontend/parser.cpp"
    break;

  case 155: // expr_var: expr_var "-" expr_int
#line 457 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2040 "frontend/parser.cpp"
    break;

  case 156: // expr_var: expr_var "-" expr_float
#line 458 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2046 "frontend/parser.cpp"
    break;

  case 157: // expr_var: expr_mat "-" expr_mat
#line 459 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2052 "frontend/parser.cpp"
    break;

  case 158: // expr_var: expr_var "-" expr_mat
#line 460 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2058 "frontend/parser.cpp"
    break;

  case 159: // expr_var: expr_mat "-" expr_var
#line 461 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2064 "frontend/parser.cpp"
    break;

  case 160: // expr_var: expr_var "-" expr_var
#line 462 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2070 "frontend/parser.cpp"
    break;

  case 161: // expr_var: expr_int "<<" expr_var
#line 464 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2076 "frontend/parser.cpp"
    break;

  case 162: // expr_var: expr_var "<<" expr_int
#line 465 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2082 "frontend/parser.cpp"
    break;

  case 163: // expr_var: expr_var "<<" expr_var
#line 466 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2088 "frontend/parser.cpp"
    break;

  case 164: // expr_var: expr_int ">>" expr_var
#line 468 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2094 "frontend/parser.cpp"
    break;

  case 165: // expr_var: expr_var ">>" expr_int
#line 469 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2100 "frontend/parser.cpp"
    break;

  case 166: // expr_var: expr_var ">>" expr_var
#line 470 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2106 "frontend/parser.cpp"
    break;

  case 167: // expr_var: expr_int ">" expr_var
#line 472 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2112 "frontend/parser.cpp"
    break;

  case 168: // expr_var: expr_float ">" expr_var
#line 473 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2118 "frontend/parser.cpp"
    break;

  case 169: // expr_var: expr_str ">" expr_var
#line 474 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2124 "frontend/parser.cpp"
    break;

  case 170: // expr_var: expr_var ">" expr_int
#line 475 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2130 "frontend/parser.cpp"
    break;

  case 171: // expr_var: expr_var ">" expr_float
#line 476 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2136 "frontend/parser.cpp"
    break;

  case 172: // expr_var: expr_var ">" expr_str
#line 477 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2142 "frontend/parser.cpp"
    break;

  case 173: // expr_var: expr_var ">" expr_var
#line 478 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2148 "frontend/parser.cpp"
    break;

  case 174: // expr_var: expr_int ">=" expr_var
#line 480 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2154 "frontend/parser.cpp"
    break;

  case 175: // expr_var: expr_float ">=" expr_var
#line 481 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2160 "frontend/parser.cpp"
    break;

  case 176: // expr_var: expr_str ">=" expr_var
#line 482 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2166 "frontend/parser.cpp"
    break;

  case 177: // expr_var: expr_var ">=" expr_int
#line 483 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2172 "frontend/parser.cpp"
    break;

  case 178: // expr_var: expr_var ">=" expr_float
#line 484 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2178 "frontend/parser.cpp"
    break;

  case 179: // expr_var: expr_var ">=" expr_str
#line 485 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2184 "frontend/parser.cpp"
    break;

  case 180: // expr_var: expr_var ">=" expr_var
#line 486 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2190 "frontend/parser.cpp"
    break;

  case 181: // expr_var: expr_int "<" expr_var
#line 488 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2196 "frontend/parser.cpp"
    break;

  case 182: // expr_var: expr_float "<" expr_var
#line 489 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2202 "frontend/parser.cpp"
    break;

  case 183: // expr_var: expr_str "<" expr_var
#line 490 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2208 "frontend/parser.cpp"
    break;

  case 184: // expr_var: expr_var "<" expr_int
#line 491 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2214 "frontend/parser.cpp"
    break;

  case 185: // expr_var: expr_var "<" expr_float
#line 492 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2220 "frontend/parser.cpp"
    break;

  case 186: // expr_var: expr_var "<" expr_str
#line 493 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2226 "frontend/parser.cpp"
    break;

  case 187: // expr_var: expr_var "<" expr_var
#line 494 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2232 "frontend/parser.cpp"
    break;

  case 188: // expr_var: expr_int "<=" expr_var
#line 496 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2238 "frontend/parser.cpp"
    break;

  case 189: // expr_var: expr_float "<=" expr_var
#line 497 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2244 "frontend/parser.cpp"
    break;

  case 190: // expr_var: expr_str "<=" expr_var
#line 498 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2250 "frontend/parser.cpp"
    break;

  case 191: // expr_var: expr_var "<=" expr_int
#line 499 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2256 "frontend/parser.cpp"
    break;

  case 192: // expr_var: expr_var "<=" expr_float
#line 500 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2262 "frontend/parser.cpp"
    break;

  case 193: // expr_var: expr_var "<=" expr_str
#line 501 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2268 "frontend/parser.cpp"
    break;

  case 194: // expr_var: expr_var "<=" expr_var
#line 502 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2274 "frontend/parser.cpp"
    break;

  case 195: // expr_var: expr_int "==" expr_var
#line 504 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2280 "frontend/parser.cpp"
    break;

  case 196: // expr_var: expr_float "==" expr_var
#line 505 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2286 "frontend/parser.cpp"
    break;

  case 197: // expr_var: expr_str "==" expr_var
#line 506 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2292 "frontend/parser.cpp"
    break;

  case 198: // expr_var: expr_bool "==" expr_var
#line 507 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2298 "frontend/parser.cpp"
    break;

  case 199: // expr_var: expr_none "==" expr_var
#line 508 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2304 "frontend/parser.cpp"
    break;

  case 202: // expr_var: expr_var "==" expr_int
#line 511 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2310 "frontend/parser.cpp"
    break;

  case 203: // expr_var: expr_var "==" expr_float
#line 512 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2316 "frontend/parser.cpp"
    break;

  case 204: // expr_var: expr_var "==" expr_str
#line 513 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2322 "frontend/parser.cpp"
    break;

  case 205: // expr_var: expr_var "==" expr_bool
#line 514 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2328 "frontend/parser.cpp"
    break;

  case 206: // expr_var: expr_var "==" expr_none
#line 515 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2334 "frontend/parser.cpp"
    break;

  case 207: // expr_var: expr_var "==" expr_struct
#line 516 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2340 "frontend/parser.cpp"
    break;

  case 208: // expr_var: expr_mat "==" expr_mat
#line 517 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2346 "frontend/parser.cpp"
    break;

  case 209: // expr_var: expr_var "==" expr_mat
#line 518 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2352 "frontend/parser.cpp"
    break;

  case 210: // expr_var: expr_mat "==" expr_var
#line 519 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2358 "frontend/parser.cpp"
    break;

  case 211: // expr_var: expr_var "==" expr_var
#line 520 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2364 "frontend/parser.cpp"
    break;

  case 212: // expr_var: expr_int "!=" expr_var
#line 522 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2370 "frontend/parser.cpp"
    break;

  case 213: // expr_var: expr_float "!=" expr_var
#line 523 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2376 "frontend/parser.cpp"
    break;

  case 214: // expr_var: expr_str "!=" expr_var
#line 524 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2382 "frontend/parser.cpp"
    break;

  case 215: // expr_var: expr_bool "!=" expr_var
#line 525 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2388 "frontend/parser.cpp"
    break;

  case 216: // expr_var: expr_none "!=" expr_var
#line 526 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2394 "frontend/parser.cpp"
    break;

  case 219: // expr_var: expr_var "!=" expr_int
#line 529 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2400 "frontend/parser.cpp"
    break;

  case 220: // expr_var: expr_var "!=" expr_float
#line 530 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2406 "frontend/parser.cpp"
    break;

  case 221: // expr_var: expr_var "!=" expr_str
#line 531 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2412 "frontend/parser.cpp"
    break;

  case 222: // expr_var: expr_var "!=" expr_bool
#line 532 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2418 "frontend/parser.cpp"
    break;

  case 223: // expr_var: expr_var "!=" expr_none
#line 533 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2424 "frontend/parser.cpp"
    break;

  case 224: // expr_var: expr_var "!=" expr_struct
#line 534 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2430 "frontend/parser.cpp"
    break;

  case 225: // expr_var: expr_mat "!=" expr_mat
#line 535 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2436 "frontend/parser.cpp"
    break;

  case 226: // expr_var: expr_var "!=" expr_mat
#line 536 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2442 "frontend/parser.cpp"
    break;

  case 227: // expr_var: expr_mat "!=" expr_var
#line 537 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2448 "frontend/parser.cpp"
    break;

  case 228: // expr_var: expr_var "!=" expr_var
#line 538 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2454 "frontend/parser.cpp"
    break;

  case 229: // expr_var: expr_int "&" expr_var
#line 540 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2460 "frontend/parser.cpp"
    break;

  case 230: // expr_var: expr_var "&" expr_int
#line 541 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2466 "frontend/parser.cpp"
    break;

  case 231: // expr_var: expr_var "&" expr_var
#line 542 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2472 "frontend/parser.cpp"
    break;

  case 232: // expr_var: expr_int "^" expr_var
#line 544 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2478 "frontend/parser.cpp"
    break;

  case 233: // expr_var: expr_var "^" expr_int
#line 545 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2484 "frontend/parser.cpp"
    break;

  case 234: // expr_var: expr_var "^" expr_var
#line 546 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2490 "frontend/parser.cpp"
    break;

  case 235: // expr_var: expr_int "|" expr_var
#line 548 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2496 "frontend/parser.cpp"
    break;

  case 236: // expr_var: expr_var "|" expr_int
#line 549 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2502 "frontend/parser.cpp"
    break;

  case 237: // expr_var: expr_var "|" expr_var
#line 550 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2508 "frontend/parser.cpp"
    break;

  case 242: // expr_var: expr_none "in" expr_mat
#line 556 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2514 "frontend/parser.cpp"
    break;

  case 244: // expr_var: expr_mat "in" expr_mat
#line 558 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2520 "frontend/parser.cpp"
    break;

  case 249: // expr_var: expr_none "in" expr_var
#line 563 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2526 "frontend/parser.cpp"
    break;

  case 251: // expr_var: expr_mat "in" expr_var
#line 565 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2532 "frontend/parser.cpp"
    break;

  case 252: // expr_var: expr_var "in" expr_str
#line 566 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2538 "frontend/parser.cpp"
    break;

  case 253: // expr_var: expr_var "in" expr_var
#line 567 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2544 "frontend/parser.cpp"
    break;

  case 254: // expr_var: expr_bool "and" expr_var
#line 569 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2550 "frontend/parser.cpp"
    break;

  case 255: // expr_var: expr_var "and" expr_bool
#line 570 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2556 "frontend/parser.cpp"
    break;

  case 256: // expr_var: expr_var "and" expr_var
#line 571 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2562 "frontend/parser.cpp"
    break;

  case 257: // expr_var: expr_bool "or" expr_var
#line 573 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2568 "frontend/parser.cpp"
    break;

  case 258: // expr_var: expr_var "or" expr_bool
#line 574 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2574 "frontend/parser.cpp"
    break;

  case 259: // expr_var: expr_var "or" expr_var
#line 575 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2580 "frontend/parser.cpp"
    break;

  case 260: // expr_var: "not" expr_var
#line 577 "frontend/parser.yy"
                         { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseUnaryPrefixExpr(yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LNOT)); }
#line 2586 "frontend/parser.cpp"
    break;

  case 261: // expr_var: "~" expr_var
#line 579 "frontend/parser.yy"
                         { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseUnaryPrefixExpr(yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BNOT)); }
#line 2592 "frontend/parser.cpp"
    break;

  case 266: // expr_var: expr_none "++" expr_struct
#line 585 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2598 "frontend/parser.cpp"
    break;

  case 273: // expr_var: expr_int "++" expr_var
#line 592 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2604 "frontend/parser.cpp"
    break;

  case 274: // expr_var: expr_float "++" expr_var
#line 593 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2610 "frontend/parser.cpp"
    break;

  case 275: // expr_var: expr_str "++" expr_var
#line 594 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2616 "frontend/parser.cpp"
    break;

  case 276: // expr_var: expr_bool "++" expr_var
#line 595 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2622 "frontend/parser.cpp"
    break;

  case 277: // expr_var: expr_none "++" expr_var
#line 596 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2628 "frontend/parser.cpp"
    break;

  case 279: // expr_var: expr_var "++" expr_int
#line 598 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2634 "frontend/parser.cpp"
    break;

  case 280: // expr_var: expr_var "++" expr_float
#line 599 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2640 "frontend/parser.cpp"
    break;

  case 281: // expr_var: expr_var "++" expr_str
#line 600 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2646 "frontend/parser.cpp"
    break;

  case 282: // expr_var: expr_var "++" expr_bool
#line 601 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2652 "frontend/parser.cpp"
    break;

  case 283: // expr_var: expr_var "++" expr_none
#line 602 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2658 "frontend/parser.cpp"
    break;

  case 284: // expr_var: expr_var "++" expr_struct
#line 603 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2664 "frontend/parser.cpp"
    break;

  case 285: // expr_var: expr_var "++" expr_var
#line 604 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2670 "frontend/parser.cpp"
    break;

  case 286: // matrix: "[" "]"
#line 608 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(std::vector<ptc::ir::Expr *>{}); }
#line 2676 "frontend/parser.cpp"
    break;

  case 287: // matrix: "[" matvals "]"
#line 609 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2682 "frontend/parser.cpp"
    break;

  case 288: // matrix: "[" "terminator (\\n or ;)" matvals "]"
#line 610 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2688 "frontend/parser.cpp"
    break;

  case 289: // matrix: "[" matvals "terminator (\\n or ;)" "]"
#line 611 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2694 "frontend/parser.cpp"
    break;

  case 290: // matrix: "[" "terminator (\\n or ;)" matvals "terminator (\\n or ;)" "]"
#line 612 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2700 "frontend/parser.cpp"
    break;

  case 291: // matvals: expr
#line 615 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixValue(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2706 "frontend/parser.cpp"
    break;

  case 292: // matvals: matvals "," expr
#line 616 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2712 "frontend/parser.cpp"
    break;

  case 293: // matvals: matvals "," "terminator (\\n or ;)" expr
#line 617 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[3].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2718 "frontend/parser.cpp"
    break;

  case 294: // expr_mat: matrix
#line 621 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2724 "frontend/parser.cpp"
    break;

  case 295: // expr_mat: "(" matrix ")"
#line 622 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2730 "frontend/parser.cpp"
    break;

  case 296: // range: "(" range ")"
#line 624 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2736 "frontend/parser.cpp"
    break;

  case 297: // range: int_val ".." int_val
#line 625 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseRange(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2742 "frontend/parser.cpp"
    break;

  case 298: // range: int_val "," int_val ".." int_val
#line 626 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseRange(yystack_[4].value.as < ptc::ir::Expr * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2748 "frontend/parser.cpp"
    break;

  case 299: // int_val: expr_int
#line 628 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 2754 "frontend/parser.cpp"
    break;

  case 300: // int_val: expr_var
#line 629 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2760 "frontend/parser.cpp"
    break;

  case 313: // expr_none: "none"
#line 646 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseNone(); }
#line 2766 "frontend/parser.cpp"
    break;

  case 314: // expr_none: "(" "none" ")"
#line 647 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseNone(); }
#line 2772 "frontend/parser.cpp"
    break;

  case 321: // expr_int: "int"
#line 662 "frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 2778 "frontend/parser.cpp"
    break;

  case 322: // expr_int: "-" expr_int
#line 663 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 2784 "frontend/parser.cpp"
    break;

  case 323: // expr_int: "(" expr_int ")"
#line 664 "frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 2790 "frontend/parser.cpp"
    break;

  case 324: // expr_int: "~" expr_int
#line 665 "frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 2796 "frontend/parser.cpp"
    break;

  case 325: // expr_int: expr_int "*" expr_int
#line 666 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 2802 "frontend/parser.cpp"
    break;

  case 326: // expr_int: expr_int "/" expr_int
#line 667 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 2808 "frontend/parser.cpp"
    break;

  case 327: // expr_int: expr_int "%" expr_int
#line 668 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 2814 "frontend/parser.cpp"
    break;

  case 328: // expr_int: expr_int "-" expr_int
#line 669 "frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 2820 "frontend/parser.cpp"
    break;

  case 329: // expr_int: expr_int "+" expr_int
#line 670 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 2826 "frontend/parser.cpp"
    break;

  case 330: // expr_int: expr_int "<<" expr_int
#line 671 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 2832 "frontend/parser.cpp"
    break;

  case 331: // expr_int: expr_int ">>" expr_int
#line 672 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 2838 "frontend/parser.cpp"
    break;

  case 332: // expr_int: expr_int "&" expr_int
#line 673 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 2844 "frontend/parser.cpp"
    break;

  case 333: // expr_int: expr_int "^" expr_int
#line 674 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 2850 "frontend/parser.cpp"
    break;

  case 334: // expr_int: expr_int "|" expr_int
#line 675 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 2856 "frontend/parser.cpp"
    break;

  case 335: // expr_float: "float"
#line 679 "frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 2862 "frontend/parser.cpp"
    break;

  case 336: // expr_float: "-" expr_float
#line 680 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 2868 "frontend/parser.cpp"
    break;

  case 337: // expr_float: "(" expr_float ")"
#line 681 "frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 2874 "frontend/parser.cpp"
    break;

  case 338: // expr_float: expr_float "**" expr_float
#line 682 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2880 "frontend/parser.cpp"
    break;

  case 339: // expr_float: expr_float "**" expr_int
#line 683 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2886 "frontend/parser.cpp"
    break;

  case 340: // expr_float: expr_int "**" expr_float
#line 684 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2892 "frontend/parser.cpp"
    break;

  case 341: // expr_float: expr_float "*" expr_float
#line 685 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 2898 "frontend/parser.cpp"
    break;

  case 342: // expr_float: expr_float "*" expr_int
#line 686 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 2904 "frontend/parser.cpp"
    break;

  case 343: // expr_float: expr_int "*" expr_float
#line 687 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 2910 "frontend/parser.cpp"
    break;

  case 344: // expr_float: expr_float "/" expr_float
#line 688 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 2916 "frontend/parser.cpp"
    break;

  case 345: // expr_float: expr_float "/" expr_int
#line 689 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 2922 "frontend/parser.cpp"
    break;

  case 346: // expr_float: expr_int "/" expr_float
#line 690 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 2928 "frontend/parser.cpp"
    break;

  case 347: // expr_float: expr_float "%" expr_float
#line 691 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2934 "frontend/parser.cpp"
    break;

  case 348: // expr_float: expr_float "%" expr_int
#line 692 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2940 "frontend/parser.cpp"
    break;

  case 349: // expr_float: expr_int "%" expr_float
#line 693 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2946 "frontend/parser.cpp"
    break;

  case 350: // expr_float: expr_float "-" expr_float
#line 694 "frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 2952 "frontend/parser.cpp"
    break;

  case 351: // expr_float: expr_float "-" expr_int
#line 695 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 2958 "frontend/parser.cpp"
    break;

  case 352: // expr_float: expr_int "-" expr_float
#line 696 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 2964 "frontend/parser.cpp"
    break;

  case 353: // expr_float: expr_float "+" expr_float
#line 697 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 2970 "frontend/parser.cpp"
    break;

  case 354: // expr_float: expr_float "+" expr_int
#line 698 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 2976 "frontend/parser.cpp"
    break;

  case 355: // expr_float: expr_int "+" expr_float
#line 699 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 2982 "frontend/parser.cpp"
    break;

  case 356: // expr_str: "string"
#line 703 "frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2988 "frontend/parser.cpp"
    break;

  case 357: // expr_str: "(" expr_str ")"
#line 704 "frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 2994 "frontend/parser.cpp"
    break;

  case 358: // expr_str: expr_str "++" expr_str
#line 705 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 3000 "frontend/parser.cpp"
    break;

  case 359: // expr_str: expr_str "++" expr_int
#line 706 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 3006 "frontend/parser.cpp"
    break;

  case 360: // expr_str: expr_str "++" expr_float
#line 707 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 3012 "frontend/parser.cpp"
    break;

  case 361: // expr_str: expr_str "++" expr_bool
#line 708 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3018 "frontend/parser.cpp"
    break;

  case 362: // expr_str: expr_str "++" expr_none
#line 709 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 3024 "frontend/parser.cpp"
    break;

  case 363: // expr_str: expr_int "++" expr_str
#line 710 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 3030 "frontend/parser.cpp"
    break;

  case 364: // expr_str: expr_int "++" expr_int
#line 711 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 3036 "frontend/parser.cpp"
    break;

  case 365: // expr_str: expr_int "++" expr_float
#line 712 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 3042 "frontend/parser.cpp"
    break;

  case 366: // expr_str: expr_int "++" expr_bool
#line 713 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3048 "frontend/parser.cpp"
    break;

  case 367: // expr_str: expr_int "++" expr_none
#line 714 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 3054 "frontend/parser.cpp"
    break;

  case 368: // expr_str: expr_float "++" expr_str
#line 715 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 3060 "frontend/parser.cpp"
    break;

  case 369: // expr_str: expr_float "++" expr_int
#line 716 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 3066 "frontend/parser.cpp"
    break;

  case 370: // expr_str: expr_float "++" expr_float
#line 717 "frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 3072 "frontend/parser.cpp"
    break;

  case 371: // expr_str: expr_float "++" expr_bool
#line 718 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3078 "frontend/parser.cpp"
    break;

  case 372: // expr_str: expr_float "++" expr_none
#line 719 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 3084 "frontend/parser.cpp"
    break;

  case 373: // expr_str: expr_bool "++" expr_str
#line 720 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 3090 "frontend/parser.cpp"
    break;

  case 374: // expr_str: expr_bool "++" expr_int
#line 721 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 3096 "frontend/parser.cpp"
    break;

  case 375: // expr_str: expr_bool "++" expr_float
#line 722 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 3102 "frontend/parser.cpp"
    break;

  case 376: // expr_str: expr_bool "++" expr_bool
#line 723 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3108 "frontend/parser.cpp"
    break;

  case 377: // expr_str: expr_bool "++" expr_none
#line 724 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 3114 "frontend/parser.cpp"
    break;

  case 378: // expr_str: expr_none "++" expr_str
#line 725 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 3120 "frontend/parser.cpp"
    break;

  case 379: // expr_str: expr_none "++" expr_int
#line 726 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 3126 "frontend/parser.cpp"
    break;

  case 380: // expr_str: expr_none "++" expr_float
#line 727 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 3132 "frontend/parser.cpp"
    break;

  case 381: // expr_str: expr_none "++" expr_bool
#line 728 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3138 "frontend/parser.cpp"
    break;

  case 382: // expr_str: expr_none "++" expr_none
#line 729 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 3144 "frontend/parser.cpp"
    break;

  case 383: // expr_bool: "bool"
#line 733 "frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 3150 "frontend/parser.cpp"
    break;

  case 384: // expr_bool: "(" expr_bool ")"
#line 734 "frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 3156 "frontend/parser.cpp"
    break;

  case 385: // expr_bool: "not" expr_bool
#line 735 "frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 3162 "frontend/parser.cpp"
    break;

  case 386: // expr_bool: expr_bool "or" expr_bool
#line 736 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 3168 "frontend/parser.cpp"
    break;

  case 387: // expr_bool: expr_bool "and" expr_bool
#line 737 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 3174 "frontend/parser.cpp"
    break;

  case 388: // expr_bool: expr_bool "==" expr_bool
#line 739 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 3180 "frontend/parser.cpp"
    break;

  case 389: // expr_bool: expr_int "==" expr_int
#line 740 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 3186 "frontend/parser.cpp"
    break;

  case 390: // expr_bool: expr_int "==" expr_float
#line 741 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 3192 "frontend/parser.cpp"
    break;

  case 391: // expr_bool: expr_float "==" expr_float
#line 742 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 3198 "frontend/parser.cpp"
    break;

  case 392: // expr_bool: expr_float "==" expr_int
#line 743 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 3204 "frontend/parser.cpp"
    break;

  case 393: // expr_bool: expr_str "==" expr_str
#line 744 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 3210 "frontend/parser.cpp"
    break;

  case 394: // expr_bool: expr_none "==" expr_none
#line 745 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 3216 "frontend/parser.cpp"
    break;

  case 395: // expr_bool: expr_bool "!=" expr_bool
#line 747 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 3222 "frontend/parser.cpp"
    break;

  case 396: // expr_bool: expr_int "!=" expr_int
#line 748 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 3228 "frontend/parser.cpp"
    break;

  case 397: // expr_bool: expr_int "!=" expr_float
#line 749 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 3234 "frontend/parser.cpp"
    break;

  case 398: // expr_bool: expr_float "!=" expr_float
#line 750 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 3240 "frontend/parser.cpp"
    break;

  case 399: // expr_bool: expr_float "!=" expr_int
#line 751 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 3246 "frontend/parser.cpp"
    break;

  case 400: // expr_bool: expr_str "!=" expr_str
#line 752 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 3252 "frontend/parser.cpp"
    break;

  case 401: // expr_bool: expr_none "!=" expr_none
#line 753 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 3258 "frontend/parser.cpp"
    break;

  case 402: // expr_bool: expr_int ">" expr_int
#line 755 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 3264 "frontend/parser.cpp"
    break;

  case 403: // expr_bool: expr_int ">" expr_float
#line 756 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 3270 "frontend/parser.cpp"
    break;

  case 404: // expr_bool: expr_float ">" expr_float
#line 757 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 3276 "frontend/parser.cpp"
    break;

  case 405: // expr_bool: expr_float ">" expr_int
#line 758 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 3282 "frontend/parser.cpp"
    break;

  case 406: // expr_bool: expr_str ">" expr_str
#line 759 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 3288 "frontend/parser.cpp"
    break;

  case 407: // expr_bool: expr_int "<" expr_int
#line 761 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 3294 "frontend/parser.cpp"
    break;

  case 408: // expr_bool: expr_int "<" expr_float
#line 762 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 3300 "frontend/parser.cpp"
    break;

  case 409: // expr_bool: expr_float "<" expr_float
#line 763 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 3306 "frontend/parser.cpp"
    break;

  case 410: // expr_bool: expr_float "<" expr_int
#line 764 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 3312 "frontend/parser.cpp"
    break;

  case 411: // expr_bool: expr_str "<" expr_str
#line 765 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 3318 "frontend/parser.cpp"
    break;

  case 412: // expr_bool: expr_int ">=" expr_int
#line 767 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 3324 "frontend/parser.cpp"
    break;

  case 413: // expr_bool: expr_int ">=" expr_float
#line 768 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 3330 "frontend/parser.cpp"
    break;

  case 414: // expr_bool: expr_float ">=" expr_float
#line 769 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 3336 "frontend/parser.cpp"
    break;

  case 415: // expr_bool: expr_float ">=" expr_int
#line 770 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 3342 "frontend/parser.cpp"
    break;

  case 416: // expr_bool: expr_str ">=" expr_str
#line 771 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 3348 "frontend/parser.cpp"
    break;

  case 417: // expr_bool: expr_int "<=" expr_int
#line 773 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 3354 "frontend/parser.cpp"
    break;

  case 418: // expr_bool: expr_int "<=" expr_float
#line 774 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 3360 "frontend/parser.cpp"
    break;

  case 419: // expr_bool: expr_float "<=" expr_float
#line 775 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 3366 "frontend/parser.cpp"
    break;

  case 420: // expr_bool: expr_float "<=" expr_int
#line 776 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 3372 "frontend/parser.cpp"
    break;

  case 421: // expr_bool: expr_str "<=" expr_str
#line 777 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 3378 "frontend/parser.cpp"
    break;

  case 422: // expr_bool: expr_str "in" expr_str
#line 779 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[0].value.as < std::string > ().find(yystack_[2].value.as < std::string > ()) != std::string::npos; }
#line 3384 "frontend/parser.cpp"
    break;

  case 427: // mattype: "identifier" matsq
#line 791 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3390 "frontend/parser.cpp"
    break;

  case 428: // mattype: "'int'" matsq
#line 792 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(INT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3396 "frontend/parser.cpp"
    break;

  case 429: // mattype: "'float'" matsq
#line 793 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(FLOAT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3402 "frontend/parser.cpp"
    break;

  case 430: // mattype: "'string'" matsq
#line 794 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(STRING_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3408 "frontend/parser.cpp"
    break;

  case 431: // mattype: "'bool'" matsq
#line 795 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(BOOL_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3414 "frontend/parser.cpp"
    break;

  case 440: // matsq: "[" "]"
#line 805 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(scanner->parseInt(-1)); }
#line 3420 "frontend/parser.cpp"
    break;

  case 441: // matsq: "[" int_val "]"
#line 806 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 3426 "frontend/parser.cpp"
    break;

  case 442: // matsq: "[" "]" matsq
#line 807 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), scanner->parseInt(-1)); }
#line 3432 "frontend/parser.cpp"
    break;

  case 443: // matsq: "[" int_val "]" matsq
#line 808 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[2].value.as < ptc::ir::Expr * > ()); }
#line 3438 "frontend/parser.cpp"
    break;

  case 444: // type: "'int'" "?"
#line 812 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, true, true); }
#line 3444 "frontend/parser.cpp"
    break;

  case 445: // type: "'float'" "?"
#line 813 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, true, true); }
#line 3450 "frontend/parser.cpp"
    break;

  case 446: // type: "'string'" "?"
#line 814 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, true, true); }
#line 3456 "frontend/parser.cpp"
    break;

  case 447: // type: "'bool'" "?"
#line 815 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, true, true); }
#line 3462 "frontend/parser.cpp"
    break;

  case 448: // type: "identifier" "?"
#line 816 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[1].value.as < std::string > (), true, true); }
#line 3468 "frontend/parser.cpp"
    break;

  case 451: // type: mattype "?"
#line 819 "frontend/parser.yy"
       { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 3474 "frontend/parser.cpp"
    break;

  case 452: // type: "'int'"
#line 820 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, false, true); }
#line 3480 "frontend/parser.cpp"
    break;

  case 453: // type: "'float'"
#line 821 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, false, true); }
#line 3486 "frontend/parser.cpp"
    break;

  case 454: // type: "'string'"
#line 822 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, false, true); }
#line 3492 "frontend/parser.cpp"
    break;

  case 455: // type: "'bool'"
#line 823 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, false, true); }
#line 3498 "frontend/parser.cpp"
    break;

  case 456: // type: "any"
#line 824 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(ANY_CSTR, false, true); }
#line 3504 "frontend/parser.cpp"
    break;

  case 457: // type: "identifier"
#line 825 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[0].value.as < std::string > (), false, true); }
#line 3510 "frontend/parser.cpp"
    break;

  case 458: // type: "external identifier"
#line 826 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExtType(yystack_[0].value.as < std::string > (), false); }
#line 3516 "frontend/parser.cpp"
    break;

  case 460: // type: mattype
#line 828 "frontend/parser.yy"
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

  const short  Parser ::yytable_ninf_ = -459;

  const short
   Parser ::yypact_[] =
  {
     295,  -666,  -666,  -666,  -666,  -666,  -666,  -666,  1672,   479,
     633,  1721,  1721,   -36,    41,   -19,  -666,    54,  -666,  -666,
    1721,  -666,  -666,    27,    24,    25,    31,    42,    38,    45,
      33,    68,   172,    61,  -666,  -666,    47,    47,  -666,  -666,
    -666,    62,  -666,   558,  -666,   171,  -666,  -666,    47,    47,
      47,  2085,  2668,  -666,   905,   315,   623,  2934,  2600,   837,
     775,    43,   177,     0,   246,   129,   236,  2222,   284,   905,
     315,   623,  2883,  2361,   574,   820,  1721,  -666,   129,  -666,
     239,   309,   309,   326,  -666,  -666,  -666,  -666,   132,  2934,
    2600,   837,  -666,   132,  -666,   775,   211,   951,  -666,   257,
    -666,   961,  -666,   275,    41,  -666,    41,  -666,    41,  -666,
      41,  -666,   235,  -666,   320,   512,    17,    41,  -666,  -666,
    -666,  1160,  -666,  -666,  -666,  -666,  2583,  -666,  -666,  -666,
    -666,  -666,  1721,   302,  2485,  -666,  -666,   269,  1721,  -666,
    -666,  -666,  1721,  1721,  1721,  1721,  1721,  1721,  1721,  1721,
    1721,  1721,  1721,  1721,  1721,  -666,  1205,  1160,  1721,  1721,
    1721,  1721,  1721,  1721,  1721,  1721,  1721,  1721,  1721,  1721,
    1721,  1721,  1721,  1721,  1721,  1721,  1721,  1721,  1721,     7,
    -666,  1160,  1721,  1721,  1721,  1721,  1721,  1721,  -666,  1721,
    1721,  1721,  1721,  1721,  1721,  1721,  1721,  1721,  1721,  1721,
    1721,  1721,  1721,  1721,  1721,  1721,  1721,  1721,  1721,  1721,
    1721,  1721,  1721,  1721,  1721,  1721,  1721,  1721,  1721,  1721,
    1721,  1721,  1721,  1721,  1721,  1721,  1721,  1721,  1721,  1721,
    1721,  1721,  1721,  1721,  1721,  1721,  1721,  1721,  1721,  1721,
    1721,  1721,  1721,  1721,  1721,    41,  -666,  -666,   306,    -1,
     323,  -666,  1160,   327,  -666,  -666,  -666,  -666,  -666,  -666,
     243,   329,  -666,    10,  1225,  1134,   326,   326,  -666,   309,
     309,   309,   309,   309,   309,   326,   326,   326,   326,   326,
     309,   309,   309,   309,   309,   309,  1721,    41,  2668,   331,
    2934,   -19,    37,   -31,   304,    18,  1721,  -666,  -666,  -666,
    -666,   333,   734,  1032,   810,   104,  -666,   303,   335,  -666,
     237,  -666,   364,  2583,  -666,  1377,   375,   398,  -666,  2299,
    -666,  -666,  -666,  -666,  -666,  -666,  -666,  -666,  -666,  -666,
    -666,  -666,  -666,    48,  -666,   240,   487,    32,   922,  1080,
     487,    32,   922,  1080,   490,   374,   389,   397,   490,   389,
     397,   490,   389,   397,   490,   389,   397,  2443,   626,   733,
    2957,  1871,   543,   647,  2734,   795,  2701,   348,  2768,   511,
    2855,  3026,  2797,  2980,  2826,  3003,   273,   459,   273,   459,
    2286,   575,  -666,  -666,  1746,   758,   720,  -666,  2286,   575,
    -666,  -666,  1746,   758,   720,  -666,  1076,  1536,  1036,   478,
    1076,  1536,  1036,   478,  1076,  1536,  1036,   478,  1076,  1536,
    1036,   478,  -666,  -666,   245,   487,    32,   487,    32,   490,
     374,  2768,   916,  2286,   575,  2286,   575,  2443,   626,   733,
    2957,  1871,   543,   647,  2768,   916,  2286,  -666,  2286,  -666,
    2443,   626,   733,  2957,  1871,   543,   647,  2768,   916,  2286,
    -666,  2286,  -666,   487,   922,  1080,   487,   922,  1080,   490,
     389,   397,   490,   389,   397,   490,   389,   397,   490,   397,
    2443,   626,   733,  2957,  1871,   543,   647,  2768,   916,  2855,
    3026,  2797,  2980,  2826,  3003,   273,   459,   273,   459,  2286,
    1746,   758,  2286,  1746,   758,  1076,  1536,  1036,  1076,  1536,
    1036,  1076,  1536,  1036,  1076,  1536,  1036,   487,   922,  1080,
     487,   922,  1080,   490,   389,   397,   490,   389,   397,   490,
     389,   397,   490,   389,   397,  2443,   626,   733,  2957,  1871,
     543,   647,  2768,   916,  2286,  1746,   758,  2286,  1746,   758,
    1076,  1536,  1036,  1076,  1536,  1036,  1076,  1536,  1036,  1076,
    1536,  1036,   485,  2443,   626,   733,  2957,  1871,   543,   647,
    2768,   916,   511,  2286,   720,  2286,   720,  1076,   478,  1076,
     478,  1076,   478,  1076,   478,  2443,   626,   733,  2957,  1871,
     543,   647,  2734,   795,  2701,   348,  2768,   916,  2286,  -666,
    2286,  -666,  -666,  -666,    44,   432,   492,    11,  1255,  1354,
     268,  -666,   497,  -666,  -666,  1721,  -666,  1482,  -666,   326,
     326,   326,   326,   326,  1094,  1316,  1094,  1316,   491,   494,
     491,   494,   491,   494,  1812,   494,  1692,  1162,  1620,  1107,
    1107,  1094,  1316,  1094,  1316,   491,   494,   491,   494,   491,
     494,   491,   494,  -666,  -666,    41,  -666,  1922,  1922,  1922,
    -666,  -666,   251,   251,  -666,   436,   501,   522,    19,   247,
     451,   498,   520,    20,  -666,  1345,   293,    71,   895,   500,
    -666,  -666,   558,  2359,   529,  1721,   558,  -666,  1721,  -666,
    -666,  -666,  -666,  1233,  -666,  -666,   247,   530,  -666,  -666,
    -666,   475,   475,  -666,  -666,  -666,  -666,  1960,   539,  2253,
     541,   108,  2911,   542,   547,   562,   571,   546,  -666,   552,
    -666,   251,   554,  -666,  -666,   692,   247,  -666,  -666,   586,
    -666,  1457,  -666,  1534,   298,  1721,  -666,   597,  -666,   602,
     553,  -666,  -666,  -666,   247,  2222,   608,  2883,   558,   558,
    1721,  1721,   558,   558,   558,   558,  -666,  1721,  -666,  1721,
     557,    21,  -666,  -666,  -666,   624,  -666,   635,  -666,  1571,
     610,  -666,  -666,  -666,  -666,   558,  -666,  -666,  -666,  -666,
    -666,  -666,  -666,   614,  -666,  -666,  -666,  -666,  -666,  -666,
    -666,  -666,  -666,  -666,  -666,   641,   622,  -666,  1721,  -666,
    -666,  -666
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     9,   321,   335,   356,   383,   313,     0,     0,
       0,     0,     0,     0,   456,     0,    53,     0,    47,    49,
      38,    35,    36,     0,   452,   453,   454,   455,     0,     0,
     104,   105,     0,     0,     4,    10,     0,     0,    37,    15,
      17,     0,    18,     0,    16,     0,    19,    20,     0,     0,
       0,     0,    97,   294,    96,    98,    99,   100,   101,   102,
     103,   459,   460,     0,   313,   104,   105,     0,   294,     0,
       0,     0,     0,     0,     0,     0,     0,   286,   104,   291,
       0,     0,     0,     0,   106,   107,   322,   336,   260,     0,
       0,     0,   385,   261,   324,     0,     0,     0,   432,    33,
      32,     0,    39,     0,   444,   428,   445,   429,   446,   430,
     447,   431,     0,    69,     0,     0,     0,   448,   117,   315,
     427,     0,   449,   118,     1,     3,     0,     5,     8,     7,
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
       0,     0,     0,     0,     0,   450,   433,   451,     0,    75,
       0,   314,     0,   315,   108,   295,   323,   337,   357,   384,
       0,     0,   287,     0,     0,     0,     0,     0,   324,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   440,   300,     0,
     299,     0,   457,   458,     0,     0,     0,   435,   436,   437,
     438,     0,     0,     0,     0,     0,   317,     0,     0,   434,
       0,     6,     0,     0,    23,     0,     0,     0,    93,    92,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,   109,     0,    94,     0,   152,   150,   147,   148,
     160,   158,   155,   156,   134,   133,   129,   130,   139,   137,
     138,   144,   142,   143,   124,   126,   123,   285,   283,   284,
     279,   280,   281,   282,   256,   255,   259,   258,   253,   252,
     231,   230,   237,   236,   234,   233,   163,   162,   166,   165,
     211,   209,   206,   207,   202,   203,   204,   205,   228,   226,
     223,   224,   219,   220,   221,   222,   173,   170,   171,   172,
     187,   184,   185,   186,   180,   177,   178,   179,   194,   191,
     192,   193,   120,   121,     0,   151,   149,   159,   157,   132,
     131,   251,   244,   210,   208,   227,   225,   277,   382,   266,
     379,   380,   378,   381,   249,   242,   199,   394,   216,   401,
     278,   271,   272,   267,   268,   269,   270,   250,   243,   201,
     200,   218,   217,   145,   329,   355,   153,   328,   352,   127,
     325,   343,   135,   326,   346,   140,   327,   349,   125,   340,
     273,   367,   262,   364,   365,   363,   366,   245,   238,   229,
     332,   235,   334,   232,   333,   161,   330,   164,   331,   195,
     389,   390,   212,   396,   397,   167,   402,   403,   181,   407,
     408,   174,   412,   413,   188,   417,   418,   146,   354,   353,
     154,   351,   350,   128,   342,   341,   136,   345,   344,   141,
     348,   347,   122,   339,   338,   274,   372,   263,   369,   370,
     368,   371,   246,   239,   196,   392,   391,   213,   399,   398,
     168,   405,   404,   182,   410,   409,   175,   415,   414,   189,
     420,   419,     0,   275,   362,   264,   359,   360,   358,   361,
     247,   240,   422,   197,   393,   214,   400,   169,   406,   183,
     411,   176,   416,   190,   421,   276,   377,   265,   374,   375,
     373,   376,   254,   387,   257,   386,   248,   241,   198,   388,
     215,   395,   439,   424,   457,   458,     0,   425,     0,     0,
       0,   316,     0,   288,   289,     0,   292,     0,   322,     0,
       0,     0,     0,     0,   329,   355,   328,   352,   325,   343,
     326,   346,   327,   349,     0,   340,   332,   334,   333,   330,
     331,   354,   353,   351,   350,   342,   341,   345,   344,   348,
     347,   339,   338,    79,   442,   441,    34,     0,     0,     0,
      75,    78,     0,    58,    55,     0,     0,     0,     0,     0,
       0,    74,     0,     0,   301,     0,     0,   113,     0,     0,
     318,   114,     0,     0,    24,     0,     0,   110,     0,   115,
     112,   111,   423,     0,    77,    76,     0,     0,   113,   290,
     293,   329,   328,   325,   326,   327,   443,     0,     0,   300,
       0,     0,   299,     0,     0,     0,     0,     0,    59,     0,
      56,    60,    62,    67,    72,     0,     0,    70,   305,     0,
     303,     0,   302,     0,     0,     0,    46,    25,    26,     0,
      52,    95,   426,    65,     0,   300,     0,   299,     0,     0,
       0,     0,     0,     0,     0,     0,    57,     0,    61,     0,
       0,     0,    68,   308,   307,     0,   306,     0,   304,     0,
     319,    27,    48,    54,    50,     0,    66,   296,    28,    29,
      41,    44,   297,     0,    42,    45,    40,    43,    64,    63,
      73,    71,   311,   310,   309,     0,     0,    51,     0,   312,
     320,   298
  };

  const short
   Parser ::yypgoto_[] =
  {
    -666,  -666,   -74,   965,   -28,     2,    -5,   488,  -665,  -666,
     372,  -666,  -666,  -666,  -666,  -666,  -666,  -666,  -666,  -666,
    -666,  -666,  -666,  -620,  -666,  -666,   601,  -666,    67,   572,
    -666,   533,  -666,  2033,   229,    -7,   607,  1471,  -568,   416,
    1690,  1662,  1859,   -59,  -109,    -8,   847,   550,  1174,  -666,
       3,  -666,    -2,   232
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    32,    33,   130,    34,    35,   769,   770,   137,    36,
     100,    37,    38,    39,    40,    41,    42,    43,    44,   764,
      45,   765,    46,   656,   657,    47,   114,   661,   662,    48,
      49,    50,   333,    51,    52,    53,    80,    69,   700,   701,
     180,    70,    71,   119,   308,    57,    90,    91,    95,    61,
     596,    62,   120,    63
  };

  const short
   Parser ::yytable_[] =
  {
      72,    68,    86,    89,    94,   127,   253,   726,   -69,   248,
     648,   730,    98,   605,     3,     4,     5,     6,     7,     8,
     248,     9,   105,   107,   109,   111,    10,   248,   248,   248,
     248,   306,   707,   708,    11,    97,    97,   122,   136,    12,
      96,   598,    97,   181,   115,   135,   116,   128,    97,   184,
     129,   683,    97,    97,    97,    97,   307,    99,   677,   246,
     315,   125,   126,   101,     2,     3,     4,     5,     6,     7,
       8,   132,     9,   264,    86,   268,   249,    10,   647,   121,
     704,   706,    97,   412,   413,    11,    78,    66,   678,   290,
      12,   748,   104,   106,   650,   712,   717,   781,   311,   108,
     787,   117,   297,   103,   298,   117,   299,   290,   300,  -457,
     110,   245,   117,   290,   112,   309,   667,    13,    14,    15,
      16,   113,    17,    18,    19,    20,    21,    22,    23,   736,
      24,    25,    26,    27,    28,    29,   122,    30,    31,  -441,
     252,   156,   116,   157,  -458,   668,   740,  -441,   741,   290,
     338,   342,   346,   349,   352,   355,   360,    89,    89,    89,
     371,   373,   375,   377,   379,   384,   392,   397,   401,   405,
     409,   179,   124,   290,    89,    89,    89,    89,    89,    89,
     138,   430,    89,    89,    89,   443,    89,    89,    89,   454,
     457,   460,   463,   466,    89,   473,    89,   480,   482,   484,
     486,   488,   490,   493,   496,   499,   502,   505,   508,   511,
     514,   517,   520,   523,   528,    89,   535,   538,   541,   544,
     547,   550,   290,   556,    89,    89,    89,    89,    89,    89,
      89,   578,    89,    89,    89,    89,    89,    67,   301,   673,
      88,    93,   261,   592,   290,   247,   602,   121,   302,   671,
     133,   262,   679,   286,   653,   603,   251,   680,   607,   608,
     134,   614,   616,   618,   620,   622,   624,   626,   627,   628,
     629,   630,   631,   633,   635,   637,   639,   641,   668,   263,
     688,   668,   156,   263,   157,   644,   668,   127,   158,   159,
     160,   161,   162,   163,   255,     1,   290,   291,     2,     3,
       4,     5,     6,     7,     8,   720,     9,   655,    14,   668,
     758,    10,   179,     3,     4,   313,   593,   296,    81,    11,
      24,    25,    26,    27,    12,    82,   288,   594,   595,   303,
       3,   316,   599,   295,   721,   266,   189,   601,    83,   759,
     190,   604,   267,   645,   288,   649,   652,   191,   192,   670,
     288,    13,    14,    15,    16,    83,    17,    18,    19,    20,
      21,    22,    23,    14,    24,    25,    26,    27,    28,    29,
     240,    30,    31,   242,   672,    24,    25,    26,    27,   669,
     243,   244,   594,   595,   675,   181,   288,   336,   340,   344,
     348,   351,   354,   357,   364,   366,   368,   370,   372,   374,
     376,   378,   380,   388,   396,   400,   404,   408,   676,   202,
     288,   415,   417,   419,   421,   423,   425,   221,   427,   434,
     436,   438,   440,   447,   449,   451,   453,   456,   459,   462,
     465,   468,   470,   477,   479,   481,   483,   485,   487,   489,
     492,   495,   498,   501,   504,   507,   510,   513,   516,   519,
     522,   525,   532,   534,   537,   540,   543,   546,   549,   288,
     553,   560,   563,   565,   567,   569,   571,   573,   575,   582,
     584,   586,   588,   590,   197,   198,   199,   200,   201,   202,
     597,   288,    76,     3,     4,     5,     6,     7,     8,   230,
       9,    77,   611,   612,   613,    10,   156,   681,   157,   156,
     122,   157,   682,    11,   160,   161,   162,   163,    12,   689,
     163,   274,   709,   289,   285,   710,     3,     4,     5,     6,
       7,     8,   230,     9,   287,   711,   179,   714,    10,   179,
     716,   305,   728,   288,   658,   663,    11,   310,   715,   685,
     734,    12,   725,   233,   234,   235,   236,   237,   238,   738,
      59,   739,   742,   304,   230,    78,    66,   743,    74,    59,
     746,   133,     3,     4,     5,     6,     7,     8,   232,     9,
      59,   134,   744,   335,    10,   233,   234,   235,   236,   237,
     238,   745,    11,    59,   258,   230,   181,    12,    78,    66,
     182,   183,   184,    59,   747,   231,   749,   414,   753,   232,
     761,   691,   692,   693,   694,   695,   233,   234,   235,   236,
     237,   238,   762,   763,    13,    14,    15,    16,   767,    17,
      18,    19,    20,    21,    22,    23,    59,    24,    25,    26,
      27,    28,    29,   780,    30,    31,   782,     3,     4,   702,
     702,   702,    81,   696,   193,   127,   552,   783,   194,    82,
     786,   190,   788,   789,   713,   195,   196,   290,   191,   192,
     290,   307,    83,   646,   250,   696,   687,   136,   600,   240,
     241,   136,   242,   294,   135,   318,    59,   790,   135,   243,
     244,   733,    59,   260,    59,     0,   732,     0,    59,   737,
      68,     0,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,     0,    59,     0,     0,    84,
      85,   752,     0,   290,   362,   290,     0,   369,     0,     0,
     666,     0,     0,   386,   394,   399,   403,   407,   411,   766,
     750,   230,   290,   290,     0,     0,     0,   653,     0,   432,
     768,   768,     0,   445,   768,   768,   768,   768,   654,    14,
       0,   290,     0,   475,   235,   236,   237,   238,   194,     0,
     136,    24,    25,    26,    27,   195,   196,   135,   594,   595,
       0,     0,   530,   216,   217,   218,   219,   220,   221,     0,
     290,   558,   562,   564,   566,   568,   570,   572,   574,   580,
     655,    14,   226,   227,   228,   229,   239,   240,   241,     0,
     242,     0,     0,    24,    25,    26,    27,   243,   244,     0,
     594,   595,     0,    59,     3,     4,     5,     6,     7,     8,
     242,     9,   664,     0,     0,     0,    10,   243,   244,     0,
     259,   663,     0,     0,    11,     0,    59,     0,     0,    12,
       0,   239,   240,   241,     0,   242,    59,    58,   230,     0,
       0,   665,   243,   244,     0,    73,    58,    87,   231,     0,
       0,     0,   232,    59,     0,    59,     0,    58,     0,   233,
     234,   235,   236,   237,   238,     0,   699,   699,   699,     0,
      58,     0,     0,     0,   658,   658,    78,    66,     0,     0,
      58,     0,     0,     0,   288,     0,     0,   288,     0,     3,
       4,     5,     6,     7,     8,     0,     9,   722,     0,     0,
       0,    10,     0,     0,     0,   597,   181,     0,     0,    11,
     182,   183,   184,    58,    12,     0,   735,   181,   265,    87,
     185,   182,   183,   184,     0,     0,   723,   186,   187,   199,
     200,   201,   202,   658,     0,     0,     0,   751,   186,   187,
     288,     0,   288,     0,     0,     3,     4,     5,     6,     7,
       8,     0,     9,   287,     0,     0,     0,    10,     0,   288,
     288,    78,    66,    58,     0,    11,     0,     0,     0,    58,
      12,    58,     0,     0,     0,    58,     0,     0,   288,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,   131,    58,     0,   339,   343,   347,   350,   353,
     356,   361,     0,   139,   140,   141,   155,   288,    14,     0,
     385,   393,   398,   402,   406,   410,     0,    78,    66,     0,
      24,    25,    26,    27,     0,     0,   431,   292,   293,     0,
     444,     0,   659,     0,   455,   458,   461,   464,   467,   469,
     474,   216,   217,   218,   219,   220,   221,   491,   494,   497,
     500,   503,   506,   509,   512,   515,   518,   521,   524,   529,
     660,   536,   539,   542,   545,   548,   551,     0,   557,     0,
       0,   719,     0,     0,   724,   156,   579,   157,     0,    14,
       0,   158,   159,   160,   161,   162,   163,   218,   219,   220,
     221,    24,    25,    26,    27,     0,   171,   172,   594,   595,
      58,   271,   272,   273,   274,   179,   615,   617,   619,   621,
     623,   625,   609,   610,   611,   612,   613,   632,   634,   636,
     638,   640,   642,    58,     0,     0,     0,   755,     0,   757,
       0,     0,     0,    58,   257,     0,     0,     0,    59,   280,
     281,   282,   283,   284,   285,    59,   772,   773,     0,     0,
      58,     0,    58,     0,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,    60,   785,    10,   609,   610,   611,
     612,   613,    75,    60,    11,    92,     0,     0,   275,    12,
     277,     0,   278,   279,    60,     0,     0,    59,    59,    59,
       0,   304,     0,     0,   791,     0,     0,    60,     0,     3,
       4,     5,     6,     7,     8,   332,     9,    60,     0,     0,
       0,    10,    59,    59,     0,    59,    59,   771,    59,    11,
     774,   775,   776,   777,    12,   256,    78,    66,     0,     0,
     269,   270,   271,   272,   273,   274,     0,    74,     0,     0,
      60,   275,   276,   277,     0,   278,   279,     0,     0,     3,
       4,     5,     6,     7,     8,     0,     9,     0,   116,     0,
       0,    10,     0,     0,     0,    59,     0,     0,     0,    11,
       0,    78,    66,     0,    12,     0,     0,     0,    59,    59,
      14,     0,    59,    59,    59,    59,     0,    59,     0,    59,
      60,     0,    24,    25,    26,    27,    60,     0,    60,   594,
     595,     0,    60,     0,     0,    59,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,     0,
      60,    78,    66,   282,   283,   284,   285,     0,   363,   365,
     367,     0,     0,     0,     0,     0,     0,   387,   395,     3,
       4,     5,     6,     7,     8,     0,     9,   718,     0,     0,
       0,    10,     0,   433,   686,     0,     0,   446,     0,    11,
       0,     0,     0,     0,    12,     0,     0,   476,   126,     0,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,   674,   660,    10,     0,     0,   531,     0,     0,     0,
       0,    11,     0,     0,     0,   559,    12,     0,     0,     0,
       0,    14,     0,   581,   583,   585,     0,   589,   591,     0,
       0,    78,    66,    24,    25,    26,    27,     0,     0,     0,
     594,   595,     0,    13,    14,    15,    16,    60,    17,    18,
      19,    20,    21,    22,    23,    58,    24,    25,    26,    27,
      28,    29,    58,    30,    31,     0,     0,     0,     0,     0,
      60,     3,     4,     5,     6,     7,     8,     0,     9,   754,
      60,    54,     0,    10,     0,     0,     0,     0,     0,     0,
      54,    11,     0,     0,     0,     0,    12,    60,     0,    60,
       0,    54,   256,     0,    58,    58,    58,   609,   610,   611,
     612,   613,     0,     0,    54,     0,     0,     0,   275,   276,
     277,     0,   278,   279,    54,     0,     0,     0,     0,    58,
      58,     0,    58,    58,     0,    58,     0,     0,     0,     0,
       0,     0,     0,    78,    66,     0,     0,     0,     3,     4,
       5,     6,     7,     8,    73,     9,   756,    54,     0,     0,
      10,   197,   198,   199,   200,   201,   202,     0,    11,     0,
       0,     0,     0,    12,     0,     0,   208,   209,     0,     0,
       0,     0,    58,     0,     0,     3,     4,     5,     6,     7,
       8,     0,     9,   784,     0,    58,    58,    10,     0,    58,
      58,    58,    58,     0,    58,    11,    58,    54,     0,     0,
      12,     0,     0,    54,     0,    54,     0,     0,     0,    54,
      78,    66,    58,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,     0,    54,     0,   337,
     341,   345,     0,     0,     0,   609,   610,   611,   612,   613,
       0,     0,     0,     0,   381,   389,   275,    78,    66,     0,
     278,   279,     0,   416,   418,   420,   422,   424,   426,     0,
       0,   435,    55,     0,     0,   448,     0,     0,     0,     0,
       0,    55,     0,     0,     0,   478,     3,     4,     5,     6,
      64,     8,    55,     9,     0,     0,     0,     0,    10,     0,
       0,     0,     0,     0,   533,    55,    11,     0,     0,     0,
       0,    12,     0,   561,     0,    55,     0,   609,   610,   611,
     612,   613,     0,   587,     0,     0,     0,     0,     0,     0,
     118,   123,   278,   279,     0,     3,     4,     5,     6,     7,
       8,     0,     9,     0,    54,     0,     0,    10,    55,     0,
       0,     0,     0,     0,   188,    11,     0,     0,    65,    66,
      12,     0,     0,     0,     0,   118,   123,    54,     0,   188,
       0,   197,   198,   199,   200,   201,   202,    54,   118,     0,
       0,     0,    60,     0,     0,     0,   208,   209,     0,    60,
     212,   213,   214,   215,    54,     0,    54,     0,    55,     0,
       0,     0,     0,     0,    55,     0,    55,    78,    66,     0,
      55,     0,     0,     0,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,     0,    55,     0,
       0,    60,    60,    60,     0,     0,   358,   269,   270,   271,
     272,   273,   274,     0,     0,   382,   390,     0,   275,   276,
     277,     0,   278,   279,     0,     0,    60,    60,     0,    60,
      60,   428,    60,   437,   439,   441,     0,     0,     0,    56,
       0,     0,     0,     0,     0,   471,     0,     0,    56,     0,
       0,    75,     0,     0,     0,     0,     0,     0,     0,    56,
       0,     0,     0,     0,   526,     0,   216,   217,   218,   219,
     220,   221,    56,   554,     0,     0,   223,     0,     0,    60,
       0,   576,    56,   224,   225,   226,   227,   228,   229,     0,
       0,     0,    60,    60,     0,     0,    60,    60,    60,    60,
       0,    60,     0,    60,     0,    55,     3,     4,     5,     6,
       7,   697,     0,     9,     0,    56,     0,     0,    10,    60,
       0,     0,     0,     0,     0,     0,    11,     0,    55,     0,
       0,    12,     0,     0,     0,     0,     0,     0,    55,     0,
       0,     0,     0,     0,     3,     4,     5,     6,    64,   697,
       0,     9,     0,     0,     0,    55,    10,    55,     0,     0,
       0,     0,     0,     0,    11,    56,     0,     0,     0,    12,
       0,    56,     0,    56,     0,     0,     0,    56,    78,    66,
       0,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,     0,    56,     0,     0,     0,     0,
       0,     0,     0,   359,     0,     0,     0,   188,     0,     0,
       0,   188,   383,   391,     0,   188,    65,    66,     0,     0,
       0,     0,    79,     0,     0,     0,     0,     0,   429,     0,
       0,     0,   442,   102,   450,   452,     0,     0,     0,     0,
       0,     0,   472,     0,     0,     0,     0,     0,     0,    54,
       0,   188,     0,     0,     0,     0,    54,     0,     0,   188,
       0,   527,     0,     0,     0,   128,     0,     0,   129,     0,
     555,     0,     0,     0,     0,     0,     0,     0,   577,     0,
       0,     0,     0,     0,     0,     0,   188,     0,   188,    79,
     188,     0,   188,     0,   188,     0,   188,     0,    54,    54,
      54,     0,    56,     0,     0,   188,     0,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   188,   153,
     154,     0,     0,    54,    54,    56,    54,    54,     0,    54,
       0,     0,     0,     0,     0,    56,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   312,     0,     0,   188,     0,
       0,   317,    56,     0,    56,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,     0,   334,
       0,     0,     0,     0,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
      54,     0,     0,    54,    54,    54,    54,     0,    54,     0,
      54,     0,     0,   188,     0,     0,     0,     0,     0,     0,
       0,   156,   254,   157,     0,     0,    54,   158,   159,   160,
     161,   162,   163,   164,   165,   166,     0,   167,   168,   169,
     170,   188,   171,   172,   173,   174,   175,   176,   177,   178,
      55,   179,   156,   -97,   157,     0,     0,    55,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   188,   167,   168,
     169,   170,     0,   171,   172,   173,   174,   175,   176,   177,
     178,     0,   179,     0,     0,   156,   606,   157,     0,     0,
       0,   158,   159,   160,   161,   162,   163,     0,     0,    55,
      55,    55,     0,     0,     0,     0,   171,   172,     0,   643,
     175,   176,   177,   178,     0,   179,     0,     0,     0,   651,
       0,     0,     0,     0,    55,    55,     0,    55,    55,     0,
      55,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     0,   153,   154,     0,     0,     0,     0,     0,
     126,     0,     2,     3,     4,     5,     6,     7,     8,     0,
       9,   257,     0,   727,     0,    10,   216,   217,   218,   219,
     220,   221,   222,    11,     0,     0,   223,    55,    12,     0,
       0,     0,     0,   224,   225,   226,   227,   228,   229,     0,
      55,    55,     0,     0,    55,    55,    55,    55,     0,    55,
       0,    55,     0,     0,     0,    13,    14,    15,    16,     0,
      17,    18,    19,    20,    21,    22,    23,    55,    24,    25,
      26,    27,    28,    29,     0,    30,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156,     0,   157,     0,     0,    56,   158,   159,
     160,   161,   162,   163,    56,   165,   166,     0,   167,   168,
     169,   170,     0,   171,   172,   173,   174,   175,   176,   177,
     178,     0,   179,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,   314,
       0,    10,     0,     0,     0,     0,    56,    56,    56,    11,
       0,     0,     0,     0,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    56,    56,     0,    56,    56,     0,    56,     0,     0,
       0,    13,    14,    15,    16,     0,    17,    18,    19,    20,
      21,    22,    23,     0,    24,    25,    26,    27,    28,    29,
       0,    30,    31,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    56,     0,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,    56,    56,    10,
       0,    56,    56,    56,    56,     0,    56,    11,    56,     0,
       0,     0,    12,     0,     0,   216,   217,   218,   219,   220,
     221,   222,     0,     0,    56,   223,     0,     0,     0,     0,
       0,   684,   224,   225,   226,   227,   228,   229,   690,    13,
      14,    15,    16,     0,    17,    18,    19,    20,    21,    22,
      23,     0,    24,    25,    26,    27,    28,    29,     0,    30,
      31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   156,     0,   157,
     698,   703,   705,   158,   159,   160,   161,   162,   163,   164,
     165,   166,     0,   167,   168,   169,   170,     0,   171,   172,
     173,   174,   175,   176,   177,   178,     0,   179,   729,     0,
     156,   731,   157,     0,     0,     0,   158,   159,   160,   161,
     162,   163,     0,   165,     0,     0,   167,   168,   169,   170,
       0,   171,   172,   173,   174,   175,   176,   177,   178,     0,
     179,     0,     0,   156,     0,   157,     0,     0,     0,   158,
     159,   160,   161,   162,   163,     0,     0,     0,   760,   167,
     168,   169,   170,     0,   171,   172,   173,   174,   175,   176,
     177,   178,     0,   179,     0,     0,     0,   156,     0,   157,
     778,     0,   779,   158,   159,   160,   161,   162,   163,     0,
       0,     0,     0,     0,   168,   169,   170,     0,   171,   172,
     173,   174,   175,   176,   177,   178,   156,   179,   157,     0,
       0,     0,   158,   159,   160,   161,   162,   163,     0,     0,
       0,     0,     0,   168,     0,   170,     0,   171,   172,   173,
     174,   175,   176,   177,   178,   156,   179,   157,     0,     0,
       0,   158,   159,   160,   161,   162,   163,     0,     0,     0,
       0,     0,   168,     0,     0,     0,   171,   172,   173,   174,
     175,   176,   177,   178,   156,   179,   157,     0,     0,     0,
     158,   159,   160,   161,   162,   163,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   171,   172,   173,   174,   175,
     176,   177,   178,   256,   179,     0,     0,     0,   197,   198,
     199,   200,   201,   202,   203,     0,     0,     0,   204,   205,
     206,   207,     0,   208,   209,   210,   211,   212,   213,   214,
     215,  -100,     0,     0,     0,     0,   197,   198,   199,   200,
     201,   202,   203,     0,     0,     0,   204,   205,   206,   207,
       0,   208,   209,   210,   211,   212,   213,   214,   215,   197,
     198,   199,   200,   201,   202,   203,     0,     0,     0,   204,
     205,   206,   207,     0,   208,   209,   210,   211,   212,   213,
     214,   215,   197,   198,   199,   200,   201,   202,     0,     0,
       0,     0,   204,   205,   206,   207,     0,   208,   209,   210,
     211,   212,   213,   214,   215,   197,   198,   199,   200,   201,
     202,     0,     0,     0,     0,     0,   205,     0,   207,     0,
     208,   209,   210,   211,   212,   213,   214,   215,   197,   198,
     199,   200,   201,   202,     0,     0,     0,     0,     0,   205,
       0,     0,     0,   208,   209,   210,   211,   212,   213,   214,
     215,   197,   198,   199,   200,   201,   202,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   208,   209,   210,   211,
     212,   213,   214,   215
  };

  const short
   Parser ::yycheck_[] =
  {
       8,     8,    10,    11,    12,    33,    65,   672,     9,     9,
      41,   676,    14,     3,     4,     5,     6,     7,     8,     9,
       9,    11,    24,    25,    26,    27,    16,     9,     9,     9,
       9,    14,   652,   653,    24,    11,    11,    68,    43,    29,
      76,    42,    11,    11,    11,    43,    13,     0,    11,    17,
       3,    40,    11,    11,    11,    11,    39,    76,    10,    61,
     134,     0,     1,     9,     3,     4,     5,     6,     7,     8,
       9,     9,    11,    81,    82,    83,    76,    16,    41,    11,
     648,   649,    11,    76,    77,    24,    76,    77,    40,    97,
      29,   711,    68,    68,    76,    76,    76,    76,   126,    68,
     765,    68,   104,    76,   106,    68,   108,   115,   110,    76,
      68,    68,    68,   121,    76,   117,    12,    56,    57,    58,
      59,    76,    61,    62,    63,    64,    65,    66,    67,   697,
      69,    70,    71,    72,    73,    74,    68,    76,    77,    68,
      11,     9,    13,    11,    76,    41,    38,    76,    40,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,    39,     0,   181,   182,   183,   184,   185,   186,   187,
       9,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,     8,     3,   313,
      11,    12,     3,   245,   252,    68,     3,    11,    13,    12,
       3,    12,    12,    42,     3,    12,    10,    12,   266,   267,
      13,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,    41,    40,
      12,    41,     9,    40,    11,   287,    41,   315,    15,    16,
      17,    18,    19,    20,    10,     0,   304,    40,     3,     4,
       5,     6,     7,     8,     9,    12,    11,    56,    57,    41,
      12,    16,    39,     4,     5,    13,    10,    42,     9,    24,
      69,    70,    71,    72,    29,    16,    97,    76,    77,     9,
       4,    62,     9,   101,    41,     9,    21,    10,    29,    41,
      25,    12,    16,    12,   115,    41,    13,    32,    33,    14,
     121,    56,    57,    58,    59,    29,    61,    62,    63,    64,
      65,    66,    67,    57,    69,    70,    71,    72,    73,    74,
      22,    76,    77,    25,    10,    69,    70,    71,    72,    76,
      32,    33,    76,    77,     9,    11,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,    10,    20,
     181,   182,   183,   184,   185,   186,   187,    20,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,    15,    16,    17,    18,    19,    20,
     248,   252,     3,     4,     5,     6,     7,     8,     9,    11,
      11,    12,    17,    18,    19,    16,     9,    12,    11,     9,
      68,    11,    10,    24,    17,    18,    19,    20,    29,    12,
      20,    20,    76,    97,    20,    14,     4,     5,     6,     7,
       8,     9,    11,    11,    12,     3,    39,    76,    16,    39,
      10,   115,     3,   304,   302,   303,    24,   121,    40,   598,
      10,    29,    42,    32,    33,    34,    35,    36,    37,    10,
       0,    10,    10,    41,    11,    76,    77,    10,     8,     9,
      14,     3,     4,     5,     6,     7,     8,     9,    25,    11,
      20,    13,    10,   157,    16,    32,    33,    34,    35,    36,
      37,    10,    24,    33,    10,    11,    11,    29,    76,    77,
      15,    16,    17,    43,    42,    21,    42,   181,    12,    25,
       3,   609,   610,   611,   612,   613,    32,    33,    34,    35,
      36,    37,    10,    60,    56,    57,    58,    59,    10,    61,
      62,    63,    64,    65,    66,    67,    76,    69,    70,    71,
      72,    73,    74,    76,    76,    77,    12,     4,     5,   647,
     648,   649,     9,   645,    21,   673,   230,    12,    25,    16,
      40,    25,    38,    12,   659,    32,    33,   665,    32,    33,
     668,    39,    29,   291,    63,   667,   599,   672,   252,    22,
      23,   676,    25,   101,   672,   142,   126,   786,   676,    32,
      33,   686,   132,    76,   134,    -1,   683,    -1,   138,   697,
     697,    -1,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,   156,    -1,    -1,    76,
      77,   716,    -1,   721,   164,   723,    -1,   167,    -1,    -1,
     304,    -1,    -1,   173,   174,   175,   176,   177,   178,   734,
      38,    11,   740,   741,    -1,    -1,    -1,     3,    -1,   189,
     738,   739,    -1,   193,   742,   743,   744,   745,    14,    57,
      -1,   759,    -1,   203,    34,    35,    36,    37,    25,    -1,
     765,    69,    70,    71,    72,    32,    33,   765,    76,    77,
      -1,    -1,   222,    15,    16,    17,    18,    19,    20,    -1,
     788,   231,   232,   233,   234,   235,   236,   237,   238,   239,
      56,    57,    34,    35,    36,    37,    21,    22,    23,    -1,
      25,    -1,    -1,    69,    70,    71,    72,    32,    33,    -1,
      76,    77,    -1,   263,     4,     5,     6,     7,     8,     9,
      25,    11,    12,    -1,    -1,    -1,    16,    32,    33,    -1,
      10,   599,    -1,    -1,    24,    -1,   286,    -1,    -1,    29,
      -1,    21,    22,    23,    -1,    25,   296,     0,    11,    -1,
      -1,    41,    32,    33,    -1,     8,     9,    10,    21,    -1,
      -1,    -1,    25,   313,    -1,   315,    -1,    20,    -1,    32,
      33,    34,    35,    36,    37,    -1,   647,   648,   649,    -1,
      33,    -1,    -1,    -1,   652,   653,    76,    77,    -1,    -1,
      43,    -1,    -1,    -1,   665,    -1,    -1,   668,    -1,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    -1,    -1,
      -1,    16,    -1,    -1,    -1,   683,    11,    -1,    -1,    24,
      15,    16,    17,    76,    29,    -1,   697,    11,    81,    82,
      25,    15,    16,    17,    -1,    -1,    41,    32,    33,    17,
      18,    19,    20,   711,    -1,    -1,    -1,   715,    32,    33,
     721,    -1,   723,    -1,    -1,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    -1,    -1,    -1,    16,    -1,   740,
     741,    76,    77,   126,    -1,    24,    -1,    -1,    -1,   132,
      29,   134,    -1,    -1,    -1,   138,    -1,    -1,   759,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    37,   156,    -1,   158,   159,   160,   161,   162,
     163,   164,    -1,    48,    49,    50,    51,   788,    57,    -1,
     173,   174,   175,   176,   177,   178,    -1,    76,    77,    -1,
      69,    70,    71,    72,    -1,    -1,   189,    76,    77,    -1,
     193,    -1,    10,    -1,   197,   198,   199,   200,   201,   202,
     203,    15,    16,    17,    18,    19,    20,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      38,   224,   225,   226,   227,   228,   229,    -1,   231,    -1,
      -1,   665,    -1,    -1,   668,     9,   239,    11,    -1,    57,
      -1,    15,    16,    17,    18,    19,    20,    17,    18,    19,
      20,    69,    70,    71,    72,    -1,    30,    31,    76,    77,
     263,    17,    18,    19,    20,    39,   269,   270,   271,   272,
     273,   274,    15,    16,    17,    18,    19,   280,   281,   282,
     283,   284,   285,   286,    -1,    -1,    -1,   721,    -1,   723,
      -1,    -1,    -1,   296,    10,    -1,    -1,    -1,   598,    15,
      16,    17,    18,    19,    20,   605,   740,   741,    -1,    -1,
     313,    -1,   315,    -1,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    -1,     0,   759,    16,    15,    16,    17,
      18,    19,     8,     9,    24,    11,    -1,    -1,    26,    29,
      28,    -1,    30,    31,    20,    -1,    -1,   647,   648,   649,
      -1,    41,    -1,    -1,   788,    -1,    -1,    33,    -1,     4,
       5,     6,     7,     8,     9,    10,    11,    43,    -1,    -1,
      -1,    16,   672,   673,    -1,   675,   676,   739,   678,    24,
     742,   743,   744,   745,    29,    10,    76,    77,    -1,    -1,
      15,    16,    17,    18,    19,    20,    -1,   697,    -1,    -1,
      76,    26,    27,    28,    -1,    30,    31,    -1,    -1,     4,
       5,     6,     7,     8,     9,    -1,    11,    -1,    13,    -1,
      -1,    16,    -1,    -1,    -1,   725,    -1,    -1,    -1,    24,
      -1,    76,    77,    -1,    29,    -1,    -1,    -1,   738,   739,
      57,    -1,   742,   743,   744,   745,    -1,   747,    -1,   749,
     126,    -1,    69,    70,    71,    72,   132,    -1,   134,    76,
      77,    -1,   138,    -1,    -1,   765,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,    76,    77,    17,    18,    19,    20,    -1,   164,   165,
     166,    -1,    -1,    -1,    -1,    -1,    -1,   173,   174,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    -1,    -1,
      -1,    16,    -1,   189,    10,    -1,    -1,   193,    -1,    24,
      -1,    -1,    -1,    -1,    29,    -1,    -1,   203,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
      -1,    14,    38,    16,    -1,    -1,   222,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,   231,    29,    -1,    -1,    -1,
      -1,    57,    -1,   239,   240,   241,    -1,   243,   244,    -1,
      -1,    76,    77,    69,    70,    71,    72,    -1,    -1,    -1,
      76,    77,    -1,    56,    57,    58,    59,   263,    61,    62,
      63,    64,    65,    66,    67,   598,    69,    70,    71,    72,
      73,    74,   605,    76,    77,    -1,    -1,    -1,    -1,    -1,
     286,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
     296,     0,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    24,    -1,    -1,    -1,    -1,    29,   313,    -1,   315,
      -1,    20,    10,    -1,   647,   648,   649,    15,    16,    17,
      18,    19,    -1,    -1,    33,    -1,    -1,    -1,    26,    27,
      28,    -1,    30,    31,    43,    -1,    -1,    -1,    -1,   672,
     673,    -1,   675,   676,    -1,   678,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    77,    -1,    -1,    -1,     4,     5,
       6,     7,     8,     9,   697,    11,    12,    76,    -1,    -1,
      16,    15,    16,    17,    18,    19,    20,    -1,    24,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,   725,    -1,    -1,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    -1,   738,   739,    16,    -1,   742,
     743,   744,   745,    -1,   747,    24,   749,   126,    -1,    -1,
      29,    -1,    -1,   132,    -1,   134,    -1,    -1,    -1,   138,
      76,    77,   765,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,   156,    -1,   158,
     159,   160,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    -1,   173,   174,    26,    76,    77,    -1,
      30,    31,    -1,   182,   183,   184,   185,   186,   187,    -1,
      -1,   190,     0,    -1,    -1,   194,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    -1,    -1,   204,     4,     5,     6,     7,
       8,     9,    20,    11,    -1,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    -1,    -1,   223,    33,    24,    -1,    -1,    -1,
      -1,    29,    -1,   232,    -1,    43,    -1,    15,    16,    17,
      18,    19,    -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    30,    31,    -1,     4,     5,     6,     7,     8,
       9,    -1,    11,    -1,   263,    -1,    -1,    16,    76,    -1,
      -1,    -1,    -1,    -1,    54,    24,    -1,    -1,    76,    77,
      29,    -1,    -1,    -1,    -1,    65,    66,   286,    -1,    69,
      -1,    15,    16,    17,    18,    19,    20,   296,    78,    -1,
      -1,    -1,   598,    -1,    -1,    -1,    30,    31,    -1,   605,
      34,    35,    36,    37,   313,    -1,   315,    -1,   126,    -1,
      -1,    -1,    -1,    -1,   132,    -1,   134,    76,    77,    -1,
     138,    -1,    -1,    -1,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,   156,    -1,
      -1,   647,   648,   649,    -1,    -1,   164,    15,    16,    17,
      18,    19,    20,    -1,    -1,   173,   174,    -1,    26,    27,
      28,    -1,    30,    31,    -1,    -1,   672,   673,    -1,   675,
     676,   189,   678,   191,   192,   193,    -1,    -1,    -1,     0,
      -1,    -1,    -1,    -1,    -1,   203,    -1,    -1,     9,    -1,
      -1,   697,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    -1,   222,    -1,    15,    16,    17,    18,
      19,    20,    33,   231,    -1,    -1,    25,    -1,    -1,   725,
      -1,   239,    43,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,   738,   739,    -1,    -1,   742,   743,   744,   745,
      -1,   747,    -1,   749,    -1,   263,     4,     5,     6,     7,
       8,     9,    -1,    11,    -1,    76,    -1,    -1,    16,   765,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,   286,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,   296,    -1,
      -1,    -1,    -1,    -1,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    -1,    -1,   313,    16,   315,    -1,    -1,
      -1,    -1,    -1,    -1,    24,   126,    -1,    -1,    -1,    29,
      -1,   132,    -1,   134,    -1,    -1,    -1,   138,    76,    77,
      -1,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,   156,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   164,    -1,    -1,    -1,   337,    -1,    -1,
      -1,   341,   173,   174,    -1,   345,    76,    77,    -1,    -1,
      -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,   189,    -1,
      -1,    -1,   193,    20,   195,   196,    -1,    -1,    -1,    -1,
      -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,   598,
      -1,   381,    -1,    -1,    -1,    -1,   605,    -1,    -1,   389,
      -1,   222,    -1,    -1,    -1,     0,    -1,    -1,     3,    -1,
     231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   416,    -1,   418,    76,
     420,    -1,   422,    -1,   424,    -1,   426,    -1,   647,   648,
     649,    -1,   263,    -1,    -1,   435,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,   448,    54,
      55,    -1,    -1,   672,   673,   286,   675,   676,    -1,   678,
      -1,    -1,    -1,    -1,    -1,   296,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   132,    -1,    -1,   478,    -1,
      -1,   138,   313,    -1,   315,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,   156,
      -1,    -1,    -1,    -1,    -1,    -1,   725,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   738,
     739,    -1,    -1,   742,   743,   744,   745,    -1,   747,    -1,
     749,    -1,    -1,   533,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,   765,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    25,    26,    27,
      28,   561,    30,    31,    32,    33,    34,    35,    36,    37,
     598,    39,     9,    10,    11,    -1,    -1,   605,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   587,    25,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    -1,    -1,     9,   263,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    -1,    -1,   647,
     648,   649,    -1,    -1,    -1,    -1,    30,    31,    -1,   286,
      34,    35,    36,    37,    -1,    39,    -1,    -1,    -1,   296,
      -1,    -1,    -1,    -1,   672,   673,    -1,   675,   676,    -1,
     678,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    10,    -1,    14,    -1,    16,    15,    16,    17,    18,
      19,    20,    21,    24,    -1,    -1,    25,   725,    29,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    -1,
     738,   739,    -1,    -1,   742,   743,   744,   745,    -1,   747,
      -1,   749,    -1,    -1,    -1,    56,    57,    58,    59,    -1,
      61,    62,    63,    64,    65,    66,    67,   765,    69,    70,
      71,    72,    73,    74,    -1,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    -1,    11,    -1,    -1,   598,    15,    16,
      17,    18,    19,    20,   605,    22,    23,    -1,    25,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    -1,    -1,    14,
      -1,    16,    -1,    -1,    -1,    -1,   647,   648,   649,    24,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   672,   673,    -1,   675,   676,    -1,   678,    -1,    -1,
      -1,    56,    57,    58,    59,    -1,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      -1,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   725,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    -1,   738,   739,    16,
      -1,   742,   743,   744,   745,    -1,   747,    24,   749,    -1,
      -1,    -1,    29,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,   765,    25,    -1,    -1,    -1,    -1,
      -1,   598,    32,    33,    34,    35,    36,    37,   605,    56,
      57,    58,    59,    -1,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    -1,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    11,
     647,   648,   649,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    25,    26,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    39,   675,    -1,
       9,   678,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    -1,    22,    -1,    -1,    25,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      39,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,   725,    25,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    39,    -1,    -1,    -1,     9,    -1,    11,
     747,    -1,   749,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,     9,    39,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,     9,    39,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,     9,    39,    11,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    10,    39,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    25,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    10,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    25,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    25,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    37
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
      68,   131,    76,    76,   105,    11,    13,    68,   119,   122,
     131,    11,    68,   119,     0,     0,     1,    83,     0,     3,
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
     131,     3,    13,     9,    41,   118,    14,    39,   123,   131,
     118,    83,   112,    13,    14,    81,    62,   112,   110,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,    10,   111,   112,   118,   113,   116,   124,   125,
     113,   116,   124,   125,   113,   116,   124,   125,   113,   124,
     125,   113,   124,   125,   113,   124,   125,   113,   120,   121,
     124,   125,   126,   127,   113,   127,   113,   127,   113,   126,
     113,   124,   113,   124,   113,   124,   113,   124,   113,   124,
     113,   116,   120,   121,   124,   125,   126,   127,   113,   116,
     120,   121,   124,   125,   126,   127,   113,   124,   125,   126,
     113,   124,   125,   126,   113,   124,   125,   126,   113,   124,
     125,   126,    76,    77,   118,   113,   116,   113,   116,   113,
     116,   113,   116,   113,   116,   113,   116,   113,   120,   121,
     124,   125,   126,   127,   113,   116,   113,   120,   113,   120,
     113,   120,   121,   124,   125,   126,   127,   113,   116,   113,
     121,   113,   121,   113,   124,   125,   113,   124,   125,   113,
     124,   125,   113,   124,   125,   113,   124,   125,   113,   125,
     113,   120,   121,   124,   125,   126,   127,   113,   116,   113,
     124,   113,   124,   113,   124,   113,   124,   113,   124,   113,
     124,   125,   113,   124,   125,   113,   124,   125,   113,   124,
     125,   113,   124,   125,   113,   124,   125,   113,   124,   125,
     113,   124,   125,   113,   124,   125,   113,   124,   125,   113,
     124,   125,   113,   124,   125,   113,   120,   121,   124,   125,
     126,   127,   113,   116,   113,   124,   125,   113,   124,   125,
     113,   124,   125,   113,   124,   125,   113,   124,   125,   113,
     124,   125,   118,   113,   120,   121,   124,   125,   126,   127,
     113,   116,   126,   113,   126,   113,   126,   113,   126,   113,
     126,   113,   126,   113,   126,   113,   120,   121,   124,   125,
     126,   127,   113,   127,   113,   127,   113,   116,   113,   127,
     113,   127,   131,    10,    76,    77,   129,   132,    42,     9,
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
     113,   113,   113,   113,   113,   113,   114,   114,   114,   114,
     114,   115,   115,   115,   116,   116,   117,   117,   117,   118,
     118,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   120,   120,   121,   121,   122,   122,   123,
     123,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   128,   128,   129,   129,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     131,   131,   131,   131,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132
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
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     4,     4,
       5,     1,     3,     4,     1,     3,     3,     3,     5,     1,
       1,     3,     4,     4,     5,     4,     5,     5,     5,     6,
       6,     6,     7,     1,     3,     2,     4,     2,     3,     4,
       6,     1,     2,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     3,     1,     3,     2,     2,     2,
       2,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     4,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1
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
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   608,   609,   610,   611,
     612,   615,   616,   617,   621,   622,   624,   625,   626,   628,
     629,   631,   632,   633,   634,   635,   636,   637,   638,   639,
     640,   641,   642,   646,   647,   651,   652,   654,   655,   657,
     658,   662,   663,   664,   665,   666,   667,   668,   669,   670,
     671,   672,   673,   674,   675,   679,   680,   681,   682,   683,
     684,   685,   686,   687,   688,   689,   690,   691,   692,   693,
     694,   695,   696,   697,   698,   699,   703,   704,   705,   706,
     707,   708,   709,   710,   711,   712,   713,   714,   715,   716,
     717,   718,   719,   720,   721,   722,   723,   724,   725,   726,
     727,   728,   729,   733,   734,   735,   736,   737,   739,   740,
     741,   742,   743,   744,   745,   747,   748,   749,   750,   751,
     752,   753,   755,   756,   757,   758,   759,   761,   762,   763,
     764,   765,   767,   768,   769,   770,   771,   773,   774,   775,
     776,   777,   779,   783,   784,   786,   787,   791,   792,   793,
     794,   795,   796,   797,   798,   799,   800,   801,   802,   803,
     805,   806,   807,   808,   812,   813,   814,   815,   816,   817,
     818,   819,   820,   821,   822,   823,   824,   825,   826,   827,
     828
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
#line 5008 "frontend/parser.cpp"

#line 831 "frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    auto msg = std::to_string(scanner->loc->begin.line) + ":" + std::to_string(scanner->loc->begin.column) + ": " + err_message;
    scanner->fatal_error(ptc::diag::ERR_SYNTAX, msg);
}
