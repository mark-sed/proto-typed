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
#line 228 "frontend/parser.yy"
                        { scanner->parseEntry(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1168 "frontend/parser.cpp"
    break;

  case 4: // stmt: stmts
#line 230 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1174 "frontend/parser.cpp"
    break;

  case 5: // stmt: stmt stmts
#line 231 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1180 "frontend/parser.cpp"
    break;

  case 6: // stmt: stmt error stmts
#line 232 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1186 "frontend/parser.cpp"
    break;

  case 9: // stmts: "terminator (\\n or ;)"
#line 239 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = nullptr; }
#line 1192 "frontend/parser.cpp"
    break;

  case 10: // stmts: stmts_ne
#line 240 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1198 "frontend/parser.cpp"
    break;

  case 11: // stmts_ne: set stmt_end
#line 242 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1204 "frontend/parser.cpp"
    break;

  case 12: // stmts_ne: vardecl stmt_end
#line 243 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1210 "frontend/parser.cpp"
    break;

  case 13: // stmts_ne: vardef stmt_end
#line 244 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1216 "frontend/parser.cpp"
    break;

  case 14: // stmts_ne: import stmt_end
#line 245 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1222 "frontend/parser.cpp"
    break;

  case 15: // stmts_ne: for
#line 246 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1228 "frontend/parser.cpp"
    break;

  case 16: // stmts_ne: if
#line 247 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1234 "frontend/parser.cpp"
    break;

  case 17: // stmts_ne: while
#line 248 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1240 "frontend/parser.cpp"
    break;

  case 18: // stmts_ne: dowhile
#line 249 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1246 "frontend/parser.cpp"
    break;

  case 19: // stmts_ne: struct
#line 250 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1252 "frontend/parser.cpp"
    break;

  case 20: // stmts_ne: function
#line 251 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1258 "frontend/parser.cpp"
    break;

  case 21: // stmts_ne: flowctl stmt_end
#line 252 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1264 "frontend/parser.cpp"
    break;

  case 22: // stmts_ne: expr stmt_end
#line 253 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1270 "frontend/parser.cpp"
    break;

  case 23: // block: "{" "}"
#line 257 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1276 "frontend/parser.cpp"
    break;

  case 24: // block: "{" stmt "}"
#line 258 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1282 "frontend/parser.cpp"
    break;

  case 25: // block: "terminator (\\n or ;)" "{" stmt "}"
#line 259 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1288 "frontend/parser.cpp"
    break;

  case 26: // block: "{" stmt "}" "terminator (\\n or ;)"
#line 260 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1294 "frontend/parser.cpp"
    break;

  case 27: // block: "terminator (\\n or ;)" "{" stmt "}" "terminator (\\n or ;)"
#line 261 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1300 "frontend/parser.cpp"
    break;

  case 28: // body: stmts_ne
#line 264 "frontend/parser.yy"
                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1306 "frontend/parser.cpp"
    break;

  case 29: // body: block
#line 265 "frontend/parser.yy"
                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1312 "frontend/parser.cpp"
    break;

  case 30: // scope_body: stmts_ne
#line 268 "frontend/parser.yy"
                      { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); scanner->leaveScope(); }
#line 1318 "frontend/parser.cpp"
    break;

  case 31: // scope_body: block
#line 269 "frontend/parser.yy"
                      { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); scanner->leaveScope(); }
#line 1324 "frontend/parser.cpp"
    break;

  case 32: // import: "import" id_list
#line 273 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::IR * > () = scanner->parseImports(yystack_[0].value.as < std::vector<std::string>  > ()); }
#line 1330 "frontend/parser.cpp"
    break;

  case 33: // id_list: "identifier"
#line 275 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseImportName(yystack_[0].value.as < std::string > ()); }
#line 1336 "frontend/parser.cpp"
    break;

  case 34: // id_list: "identifier" "," id_list
#line 276 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseAddImportName(yystack_[0].value.as < std::vector<std::string>  > (), yystack_[2].value.as < std::string > ()); }
#line 1342 "frontend/parser.cpp"
    break;

  case 35: // flowctl: "break"
#line 280 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseBreak(); }
#line 1348 "frontend/parser.cpp"
    break;

  case 36: // flowctl: "continue"
#line 281 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseContinue(); }
#line 1354 "frontend/parser.cpp"
    break;

  case 37: // flowctl: return
#line 282 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1360 "frontend/parser.cpp"
    break;

  case 38: // return: "return"
#line 284 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(nullptr); }
#line 1366 "frontend/parser.cpp"
    break;

  case 39: // return: "return" expr
#line 285 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1372 "frontend/parser.cpp"
    break;

  case 40: // for: "for" "(" vardecl ":" expr ")" body
#line 289 "frontend/parser.yy"
                                              { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1378 "frontend/parser.cpp"
    break;

  case 41: // for: "for" "(" "identifier" ":" expr ")" body
#line 290 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1384 "frontend/parser.cpp"
    break;

  case 42: // for: "for" "(" "external identifier" ":" expr ")" body
#line 291 "frontend/parser.yy"
                                              { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1390 "frontend/parser.cpp"
    break;

  case 43: // for: "for" "(" vardecl ":" range ")" body
#line 292 "frontend/parser.yy"
                                               { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1396 "frontend/parser.cpp"
    break;

  case 44: // for: "for" "(" "identifier" ":" range ")" body
#line 293 "frontend/parser.yy"
                                           { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1402 "frontend/parser.cpp"
    break;

  case 45: // for: "for" "(" "external identifier" ":" range ")" body
#line 294 "frontend/parser.yy"
                                               { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1408 "frontend/parser.cpp"
    break;

  case 46: // while: wh_kw "(" expr ")" scope_body
#line 298 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseWhile(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1414 "frontend/parser.cpp"
    break;

  case 47: // wh_kw: "while"
#line 300 "frontend/parser.yy"
                { scanner->enterBlockScope(); }
#line 1420 "frontend/parser.cpp"
    break;

  case 48: // dowhile: do_kw scope_body "while" "(" expr ")"
#line 302 "frontend/parser.yy"
                                                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseDoWhile(yystack_[1].value.as < ptc::ir::Expr * > (), yystack_[4].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1426 "frontend/parser.cpp"
    break;

  case 49: // do_kw: "do"
#line 304 "frontend/parser.yy"
             { scanner->enterBlockScope(); }
#line 1432 "frontend/parser.cpp"
    break;

  case 50: // if: if_kw "(" expr ")" scope_body else
#line 307 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseIfStmt(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1438 "frontend/parser.cpp"
    break;

  case 51: // else: el_kw scope_body
#line 309 "frontend/parser.yy"
                         { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1444 "frontend/parser.cpp"
    break;

  case 52: // else: %empty
#line 310 "frontend/parser.yy"
                    { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1450 "frontend/parser.cpp"
    break;

  case 53: // if_kw: "if"
#line 312 "frontend/parser.yy"
             { scanner->enterBlockScope(); }
#line 1456 "frontend/parser.cpp"
    break;

  case 54: // el_kw: "else"
#line 313 "frontend/parser.yy"
               { scanner->enterBlockScope(); }
#line 1462 "frontend/parser.cpp"
    break;

  case 55: // struct: "'struct'" "identifier" "{" "}"
#line 316 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[2].value.as < std::string > (), std::vector<ptc::ir::IR *>{}); }
#line 1468 "frontend/parser.cpp"
    break;

  case 56: // struct: "'struct'" "identifier" "{" decllist "}"
#line 317 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1474 "frontend/parser.cpp"
    break;

  case 57: // struct: "'struct'" "identifier" "terminator (\\n or ;)" "{" decllist "}"
#line 318 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[4].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1480 "frontend/parser.cpp"
    break;

  case 59: // decllist: "terminator (\\n or ;)" decllist
#line 321 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1486 "frontend/parser.cpp"
    break;

  case 60: // decllist: declistval "terminator (\\n or ;)"
#line 322 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[1].value.as < ptc::ir::IR * > (), std::vector<ptc::ir::IR *>{}); }
#line 1492 "frontend/parser.cpp"
    break;

  case 61: // decllist: declistval "terminator (\\n or ;)" decllist
#line 323 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[2].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1498 "frontend/parser.cpp"
    break;

  case 62: // declistval: type "identifier"
#line 325 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > (), nullptr); }
#line 1504 "frontend/parser.cpp"
    break;

  case 63: // declistval: type "identifier" "=" expr
#line 326 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1510 "frontend/parser.cpp"
    break;

  case 65: // function: type fun_id "(" ")" block
#line 331 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1516 "frontend/parser.cpp"
    break;

  case 66: // function: type fun_id "(" funargs ")" block
#line 332 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[5].value.as < ptc::ir::IR * > (), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1522 "frontend/parser.cpp"
    break;

  case 67: // function: "'void'" fun_id "(" ")" block
#line 333 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1528 "frontend/parser.cpp"
    break;

  case 68: // function: "'void'" fun_id "(" funargs ")" block
#line 334 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1534 "frontend/parser.cpp"
    break;

  case 69: // fun_id: "identifier"
#line 336 "frontend/parser.yy"
            { scanner->enterFunScope(); yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1540 "frontend/parser.cpp"
    break;

  case 70: // funargs: type "identifier"
#line 338 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseFunParam(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1546 "frontend/parser.cpp"
    break;

  case 72: // funargs: funargs "," type "identifier"
#line 340 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseAddFunParam(yystack_[3].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1552 "frontend/parser.cpp"
    break;

  case 75: // vardecl: type "identifier"
#line 347 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1558 "frontend/parser.cpp"
    break;

  case 76: // vardef: type "identifier" "=" struct_val
#line 351 "frontend/parser.yy"
         { yylhs.value.as < ptc::ir::IR * > () = yystack_[3].value.as < ptc::ir::IR * > (); }
#line 1564 "frontend/parser.cpp"
    break;

  case 77: // vardef: type "identifier" "=" expr
#line 352 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1570 "frontend/parser.cpp"
    break;

  case 80: // set: expr "++=" expr
#line 358 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1576 "frontend/parser.cpp"
    break;

  case 81: // set: expr "**=" expr
#line 359 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1582 "frontend/parser.cpp"
    break;

  case 82: // set: expr "%=" expr
#line 360 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1588 "frontend/parser.cpp"
    break;

  case 83: // set: expr "/=" expr
#line 361 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1594 "frontend/parser.cpp"
    break;

  case 84: // set: expr "*=" expr
#line 362 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1600 "frontend/parser.cpp"
    break;

  case 85: // set: expr "-=" expr
#line 363 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1606 "frontend/parser.cpp"
    break;

  case 86: // set: expr "+=" expr
#line 364 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1612 "frontend/parser.cpp"
    break;

  case 87: // set: expr "&=" expr
#line 365 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1618 "frontend/parser.cpp"
    break;

  case 88: // set: expr "|=" expr
#line 366 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1624 "frontend/parser.cpp"
    break;

  case 89: // set: expr "^=" expr
#line 367 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1630 "frontend/parser.cpp"
    break;

  case 90: // set: expr "<<=" expr
#line 368 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1636 "frontend/parser.cpp"
    break;

  case 91: // set: expr ">>=" expr
#line 369 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1642 "frontend/parser.cpp"
    break;

  case 92: // set: expr "=" expr
#line 370 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1648 "frontend/parser.cpp"
    break;

  case 93: // set: expr "=" set
#line 371 "frontend/parser.yy"
      { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1654 "frontend/parser.cpp"
    break;

  case 94: // callarglist: expr
#line 375 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseFunCallArg(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1660 "frontend/parser.cpp"
    break;

  case 95: // callarglist: callarglist "," expr
#line 376 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddFunCallArg(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1666 "frontend/parser.cpp"
    break;

  case 96: // expr: expr_mat
#line 380 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1672 "frontend/parser.cpp"
    break;

  case 97: // expr: expr_var
#line 381 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1678 "frontend/parser.cpp"
    break;

  case 100: // expr: expr_int
#line 384 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 1684 "frontend/parser.cpp"
    break;

  case 101: // expr: expr_float
#line 385 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFloat(yystack_[0].value.as < double > ()); }
#line 1690 "frontend/parser.cpp"
    break;

  case 102: // expr: expr_str
#line 386 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseString(yystack_[0].value.as < std::string > ()); }
#line 1696 "frontend/parser.cpp"
    break;

  case 103: // expr: expr_bool
#line 387 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseBool(yystack_[0].value.as < bool > ()); }
#line 1702 "frontend/parser.cpp"
    break;

  case 104: // expr_var: "identifier"
#line 390 "frontend/parser.yy"
              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > ()); }
#line 1708 "frontend/parser.cpp"
    break;

  case 105: // expr_var: "external identifier"
#line 391 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > (), true); }
#line 1714 "frontend/parser.cpp"
    break;

  case 106: // expr_var: "-" "identifier"
#line 392 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1720 "frontend/parser.cpp"
    break;

  case 107: // expr_var: "-" "external identifier"
#line 393 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > (), true), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1726 "frontend/parser.cpp"
    break;

  case 108: // expr_var: "(" expr_var ")"
#line 394 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1732 "frontend/parser.cpp"
    break;

  case 109: // expr_var: expr_var "(" ")"
#line 396 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[2].value.as < ptc::ir::Expr * > (), std::vector<ptc::ir::Expr *>{}); }
#line 1738 "frontend/parser.cpp"
    break;

  case 110: // expr_var: expr_var "(" callarglist ")"
#line 397 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 1744 "frontend/parser.cpp"
    break;

  case 111: // expr_var: expr_str "[" int_val "]"
#line 399 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1750 "frontend/parser.cpp"
    break;

  case 112: // expr_var: expr_mat "[" int_val "]"
#line 400 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1756 "frontend/parser.cpp"
    break;

  case 113: // expr_var: "identifier" "[" int_val "]"
#line 401 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1762 "frontend/parser.cpp"
    break;

  case 114: // expr_var: "external identifier" "[" int_val "]"
#line 402 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1768 "frontend/parser.cpp"
    break;

  case 115: // expr_var: expr_var "[" int_val "]"
#line 403 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1774 "frontend/parser.cpp"
    break;

  case 116: // expr_var: expr_mat slice
#line 405 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1780 "frontend/parser.cpp"
    break;

  case 119: // expr_var: expr_var slice
#line 408 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1786 "frontend/parser.cpp"
    break;

  case 120: // expr_var: "identifier" "." expr_var
#line 410 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1792 "frontend/parser.cpp"
    break;

  case 121: // expr_var: "external identifier" "." expr_var
#line 411 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1798 "frontend/parser.cpp"
    break;

  case 122: // expr_var: expr_var "." expr_var
#line 412 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1804 "frontend/parser.cpp"
    break;

  case 124: // expr_var: expr_var "**" expr_float
#line 415 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1810 "frontend/parser.cpp"
    break;

  case 125: // expr_var: expr_var "**" expr_var
#line 416 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1816 "frontend/parser.cpp"
    break;

  case 126: // expr_var: expr_int "*" expr_var
#line 418 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1822 "frontend/parser.cpp"
    break;

  case 127: // expr_var: expr_float "*" expr_var
#line 419 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1828 "frontend/parser.cpp"
    break;

  case 128: // expr_var: expr_var "*" expr_int
#line 420 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1834 "frontend/parser.cpp"
    break;

  case 129: // expr_var: expr_var "*" expr_float
#line 421 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1840 "frontend/parser.cpp"
    break;

  case 130: // expr_var: expr_mat "*" expr_mat
#line 422 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1846 "frontend/parser.cpp"
    break;

  case 131: // expr_var: expr_mat "*" expr_var
#line 423 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1852 "frontend/parser.cpp"
    break;

  case 132: // expr_var: expr_var "*" expr_mat
#line 424 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1858 "frontend/parser.cpp"
    break;

  case 133: // expr_var: expr_var "*" expr_var
#line 425 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1864 "frontend/parser.cpp"
    break;

  case 134: // expr_var: expr_int "/" expr_var
#line 427 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1870 "frontend/parser.cpp"
    break;

  case 135: // expr_var: expr_float "/" expr_var
#line 428 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1876 "frontend/parser.cpp"
    break;

  case 136: // expr_var: expr_var "/" expr_int
#line 429 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1882 "frontend/parser.cpp"
    break;

  case 137: // expr_var: expr_var "/" expr_float
#line 430 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1888 "frontend/parser.cpp"
    break;

  case 138: // expr_var: expr_var "/" expr_var
#line 431 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1894 "frontend/parser.cpp"
    break;

  case 139: // expr_var: expr_int "%" expr_var
#line 433 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1900 "frontend/parser.cpp"
    break;

  case 140: // expr_var: expr_float "%" expr_var
#line 434 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1906 "frontend/parser.cpp"
    break;

  case 141: // expr_var: expr_var "%" expr_int
#line 435 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1912 "frontend/parser.cpp"
    break;

  case 142: // expr_var: expr_var "%" expr_float
#line 436 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1918 "frontend/parser.cpp"
    break;

  case 143: // expr_var: expr_var "%" expr_var
#line 437 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1924 "frontend/parser.cpp"
    break;

  case 144: // expr_var: expr_int "+" expr_var
#line 439 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1930 "frontend/parser.cpp"
    break;

  case 145: // expr_var: expr_float "+" expr_var
#line 440 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1936 "frontend/parser.cpp"
    break;

  case 146: // expr_var: expr_var "+" expr_int
#line 441 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1942 "frontend/parser.cpp"
    break;

  case 147: // expr_var: expr_var "+" expr_float
#line 442 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1948 "frontend/parser.cpp"
    break;

  case 148: // expr_var: expr_mat "+" expr_mat
#line 443 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1954 "frontend/parser.cpp"
    break;

  case 149: // expr_var: expr_var "+" expr_mat
#line 444 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1960 "frontend/parser.cpp"
    break;

  case 150: // expr_var: expr_mat "+" expr_var
#line 445 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1966 "frontend/parser.cpp"
    break;

  case 151: // expr_var: expr_var "+" expr_var
#line 446 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1972 "frontend/parser.cpp"
    break;

  case 152: // expr_var: expr_int "-" expr_var
#line 448 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1978 "frontend/parser.cpp"
    break;

  case 153: // expr_var: expr_float "-" expr_var
#line 449 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1984 "frontend/parser.cpp"
    break;

  case 154: // expr_var: expr_var "-" expr_int
#line 450 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1990 "frontend/parser.cpp"
    break;

  case 155: // expr_var: expr_var "-" expr_float
#line 451 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1996 "frontend/parser.cpp"
    break;

  case 156: // expr_var: expr_mat "-" expr_mat
#line 452 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2002 "frontend/parser.cpp"
    break;

  case 157: // expr_var: expr_var "-" expr_mat
#line 453 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2008 "frontend/parser.cpp"
    break;

  case 158: // expr_var: expr_mat "-" expr_var
#line 454 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2014 "frontend/parser.cpp"
    break;

  case 159: // expr_var: expr_var "-" expr_var
#line 455 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2020 "frontend/parser.cpp"
    break;

  case 160: // expr_var: expr_int "<<" expr_var
#line 457 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2026 "frontend/parser.cpp"
    break;

  case 161: // expr_var: expr_var "<<" expr_int
#line 458 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2032 "frontend/parser.cpp"
    break;

  case 162: // expr_var: expr_var "<<" expr_var
#line 459 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2038 "frontend/parser.cpp"
    break;

  case 163: // expr_var: expr_int ">>" expr_var
#line 461 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2044 "frontend/parser.cpp"
    break;

  case 164: // expr_var: expr_var ">>" expr_int
#line 462 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2050 "frontend/parser.cpp"
    break;

  case 165: // expr_var: expr_var ">>" expr_var
#line 463 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2056 "frontend/parser.cpp"
    break;

  case 166: // expr_var: expr_int ">" expr_var
#line 465 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2062 "frontend/parser.cpp"
    break;

  case 167: // expr_var: expr_float ">" expr_var
#line 466 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2068 "frontend/parser.cpp"
    break;

  case 169: // expr_var: expr_var ">" expr_int
#line 468 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2074 "frontend/parser.cpp"
    break;

  case 170: // expr_var: expr_var ">" expr_float
#line 469 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2080 "frontend/parser.cpp"
    break;

  case 171: // expr_var: expr_var ">" expr_str
#line 470 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2086 "frontend/parser.cpp"
    break;

  case 172: // expr_var: expr_var ">" expr_var
#line 471 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2092 "frontend/parser.cpp"
    break;

  case 173: // expr_var: expr_int ">=" expr_var
#line 473 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2098 "frontend/parser.cpp"
    break;

  case 174: // expr_var: expr_float ">=" expr_var
#line 474 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2104 "frontend/parser.cpp"
    break;

  case 176: // expr_var: expr_var ">=" expr_int
#line 476 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2110 "frontend/parser.cpp"
    break;

  case 177: // expr_var: expr_var ">=" expr_float
#line 477 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2116 "frontend/parser.cpp"
    break;

  case 178: // expr_var: expr_var ">=" expr_str
#line 478 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2122 "frontend/parser.cpp"
    break;

  case 179: // expr_var: expr_var ">=" expr_var
#line 479 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2128 "frontend/parser.cpp"
    break;

  case 180: // expr_var: expr_int "<" expr_var
#line 481 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2134 "frontend/parser.cpp"
    break;

  case 181: // expr_var: expr_float "<" expr_var
#line 482 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2140 "frontend/parser.cpp"
    break;

  case 183: // expr_var: expr_var "<" expr_int
#line 484 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2146 "frontend/parser.cpp"
    break;

  case 184: // expr_var: expr_var "<" expr_float
#line 485 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2152 "frontend/parser.cpp"
    break;

  case 185: // expr_var: expr_var "<" expr_str
#line 486 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2158 "frontend/parser.cpp"
    break;

  case 186: // expr_var: expr_var "<" expr_var
#line 487 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2164 "frontend/parser.cpp"
    break;

  case 187: // expr_var: expr_int "<=" expr_var
#line 489 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2170 "frontend/parser.cpp"
    break;

  case 188: // expr_var: expr_float "<=" expr_var
#line 490 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2176 "frontend/parser.cpp"
    break;

  case 190: // expr_var: expr_var "<=" expr_int
#line 492 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2182 "frontend/parser.cpp"
    break;

  case 191: // expr_var: expr_var "<=" expr_float
#line 493 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2188 "frontend/parser.cpp"
    break;

  case 192: // expr_var: expr_var "<=" expr_str
#line 494 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2194 "frontend/parser.cpp"
    break;

  case 193: // expr_var: expr_var "<=" expr_var
#line 495 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2200 "frontend/parser.cpp"
    break;

  case 194: // expr_var: expr_int "==" expr_var
#line 497 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2206 "frontend/parser.cpp"
    break;

  case 195: // expr_var: expr_float "==" expr_var
#line 498 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2212 "frontend/parser.cpp"
    break;

  case 197: // expr_var: expr_bool "==" expr_var
#line 500 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2218 "frontend/parser.cpp"
    break;

  case 201: // expr_var: expr_var "==" expr_int
#line 504 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2224 "frontend/parser.cpp"
    break;

  case 202: // expr_var: expr_var "==" expr_float
#line 505 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2230 "frontend/parser.cpp"
    break;

  case 203: // expr_var: expr_var "==" expr_str
#line 506 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2236 "frontend/parser.cpp"
    break;

  case 204: // expr_var: expr_var "==" expr_bool
#line 507 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2242 "frontend/parser.cpp"
    break;

  case 205: // expr_var: expr_var "==" expr_none
#line 508 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2248 "frontend/parser.cpp"
    break;

  case 206: // expr_var: expr_var "==" expr_struct
#line 509 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2254 "frontend/parser.cpp"
    break;

  case 207: // expr_var: expr_mat "==" expr_mat
#line 510 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2260 "frontend/parser.cpp"
    break;

  case 208: // expr_var: expr_var "==" expr_mat
#line 511 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2266 "frontend/parser.cpp"
    break;

  case 209: // expr_var: expr_mat "==" expr_var
#line 512 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2272 "frontend/parser.cpp"
    break;

  case 210: // expr_var: expr_var "==" expr_var
#line 513 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2278 "frontend/parser.cpp"
    break;

  case 211: // expr_var: expr_int "!=" expr_var
#line 515 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2284 "frontend/parser.cpp"
    break;

  case 212: // expr_var: expr_float "!=" expr_var
#line 516 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2290 "frontend/parser.cpp"
    break;

  case 218: // expr_var: expr_var "!=" expr_int
#line 522 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2296 "frontend/parser.cpp"
    break;

  case 219: // expr_var: expr_var "!=" expr_float
#line 523 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2302 "frontend/parser.cpp"
    break;

  case 220: // expr_var: expr_var "!=" expr_str
#line 524 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2308 "frontend/parser.cpp"
    break;

  case 221: // expr_var: expr_var "!=" expr_bool
#line 525 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2314 "frontend/parser.cpp"
    break;

  case 222: // expr_var: expr_var "!=" expr_none
#line 526 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2320 "frontend/parser.cpp"
    break;

  case 223: // expr_var: expr_var "!=" expr_struct
#line 527 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2326 "frontend/parser.cpp"
    break;

  case 224: // expr_var: expr_mat "!=" expr_mat
#line 528 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2332 "frontend/parser.cpp"
    break;

  case 225: // expr_var: expr_var "!=" expr_mat
#line 529 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2338 "frontend/parser.cpp"
    break;

  case 226: // expr_var: expr_mat "!=" expr_var
#line 530 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2344 "frontend/parser.cpp"
    break;

  case 227: // expr_var: expr_var "!=" expr_var
#line 531 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2350 "frontend/parser.cpp"
    break;

  case 228: // expr_var: expr_int "&" expr_var
#line 533 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2356 "frontend/parser.cpp"
    break;

  case 229: // expr_var: expr_var "&" expr_int
#line 534 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2362 "frontend/parser.cpp"
    break;

  case 230: // expr_var: expr_var "&" expr_var
#line 535 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2368 "frontend/parser.cpp"
    break;

  case 231: // expr_var: expr_int "^" expr_var
#line 537 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2374 "frontend/parser.cpp"
    break;

  case 232: // expr_var: expr_var "^" expr_int
#line 538 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2380 "frontend/parser.cpp"
    break;

  case 233: // expr_var: expr_var "^" expr_var
#line 539 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2386 "frontend/parser.cpp"
    break;

  case 234: // expr_var: expr_int "|" expr_var
#line 541 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2392 "frontend/parser.cpp"
    break;

  case 235: // expr_var: expr_var "|" expr_int
#line 542 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2398 "frontend/parser.cpp"
    break;

  case 236: // expr_var: expr_var "|" expr_var
#line 543 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2404 "frontend/parser.cpp"
    break;

  case 243: // expr_var: expr_mat "in" expr_mat
#line 551 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2410 "frontend/parser.cpp"
    break;

  case 250: // expr_var: expr_mat "in" expr_var
#line 558 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2416 "frontend/parser.cpp"
    break;

  case 251: // expr_var: expr_var "in" expr_str
#line 559 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2422 "frontend/parser.cpp"
    break;

  case 252: // expr_var: expr_var "in" expr_var
#line 560 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2428 "frontend/parser.cpp"
    break;

  case 253: // expr_var: expr_bool "and" expr_var
#line 562 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2434 "frontend/parser.cpp"
    break;

  case 254: // expr_var: expr_var "and" expr_bool
#line 563 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2440 "frontend/parser.cpp"
    break;

  case 255: // expr_var: expr_var "and" expr_var
#line 564 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2446 "frontend/parser.cpp"
    break;

  case 256: // expr_var: expr_bool "or" expr_var
#line 566 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2452 "frontend/parser.cpp"
    break;

  case 257: // expr_var: expr_var "or" expr_bool
#line 567 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2458 "frontend/parser.cpp"
    break;

  case 258: // expr_var: expr_var "or" expr_var
#line 568 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2464 "frontend/parser.cpp"
    break;

  case 270: // expr_var: expr_int "++" expr_var
#line 581 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2470 "frontend/parser.cpp"
    break;

  case 271: // expr_var: expr_float "++" expr_var
#line 582 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2476 "frontend/parser.cpp"
    break;

  case 272: // expr_var: expr_str "++" expr_var
#line 583 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2482 "frontend/parser.cpp"
    break;

  case 273: // expr_var: expr_bool "++" expr_var
#line 584 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2488 "frontend/parser.cpp"
    break;

  case 276: // expr_var: expr_var "++" expr_int
#line 587 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2494 "frontend/parser.cpp"
    break;

  case 277: // expr_var: expr_var "++" expr_float
#line 588 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2500 "frontend/parser.cpp"
    break;

  case 278: // expr_var: expr_var "++" expr_str
#line 589 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2506 "frontend/parser.cpp"
    break;

  case 279: // expr_var: expr_var "++" expr_bool
#line 590 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2512 "frontend/parser.cpp"
    break;

  case 280: // expr_var: expr_var "++" expr_none
#line 591 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2518 "frontend/parser.cpp"
    break;

  case 281: // expr_var: expr_var "++" expr_struct
#line 592 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2524 "frontend/parser.cpp"
    break;

  case 282: // expr_var: expr_var "++" expr_var
#line 593 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2530 "frontend/parser.cpp"
    break;

  case 283: // matrix: "[" "]"
#line 597 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(std::vector<ptc::ir::Expr *>{}); }
#line 2536 "frontend/parser.cpp"
    break;

  case 284: // matrix: "[" matvals "]"
#line 598 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2542 "frontend/parser.cpp"
    break;

  case 285: // matrix: "[" "terminator (\\n or ;)" matvals "]"
#line 599 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2548 "frontend/parser.cpp"
    break;

  case 286: // matrix: "[" matvals "terminator (\\n or ;)" "]"
#line 600 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2554 "frontend/parser.cpp"
    break;

  case 287: // matrix: "[" "terminator (\\n or ;)" matvals "terminator (\\n or ;)" "]"
#line 601 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2560 "frontend/parser.cpp"
    break;

  case 288: // matvals: expr
#line 604 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixValue(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2566 "frontend/parser.cpp"
    break;

  case 289: // matvals: matvals "," expr
#line 605 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2572 "frontend/parser.cpp"
    break;

  case 290: // matvals: matvals "," "terminator (\\n or ;)" expr
#line 606 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[3].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2578 "frontend/parser.cpp"
    break;

  case 291: // expr_mat: matrix
#line 610 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2584 "frontend/parser.cpp"
    break;

  case 292: // expr_mat: "(" matrix ")"
#line 611 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2590 "frontend/parser.cpp"
    break;

  case 293: // range: "(" range ")"
#line 613 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2596 "frontend/parser.cpp"
    break;

  case 294: // range: int_val ".." int_val
#line 614 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseRange(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2602 "frontend/parser.cpp"
    break;

  case 295: // range: int_val "," int_val ".." int_val
#line 615 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseRange(yystack_[4].value.as < ptc::ir::Expr * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2608 "frontend/parser.cpp"
    break;

  case 296: // int_val: expr_int
#line 617 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 2614 "frontend/parser.cpp"
    break;

  case 297: // int_val: expr_var
#line 618 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2620 "frontend/parser.cpp"
    break;

  case 318: // expr_int: "int"
#line 651 "frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 2626 "frontend/parser.cpp"
    break;

  case 319: // expr_int: "-" expr_int
#line 652 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 2632 "frontend/parser.cpp"
    break;

  case 320: // expr_int: "(" expr_int ")"
#line 653 "frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 2638 "frontend/parser.cpp"
    break;

  case 321: // expr_int: "~" expr_int
#line 654 "frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 2644 "frontend/parser.cpp"
    break;

  case 322: // expr_int: expr_int "*" expr_int
#line 655 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 2650 "frontend/parser.cpp"
    break;

  case 323: // expr_int: expr_int "/" expr_int
#line 656 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 2656 "frontend/parser.cpp"
    break;

  case 324: // expr_int: expr_int "%" expr_int
#line 657 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 2662 "frontend/parser.cpp"
    break;

  case 325: // expr_int: expr_int "-" expr_int
#line 658 "frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 2668 "frontend/parser.cpp"
    break;

  case 326: // expr_int: expr_int "+" expr_int
#line 659 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 2674 "frontend/parser.cpp"
    break;

  case 327: // expr_int: expr_int "<<" expr_int
#line 660 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 2680 "frontend/parser.cpp"
    break;

  case 328: // expr_int: expr_int ">>" expr_int
#line 661 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 2686 "frontend/parser.cpp"
    break;

  case 329: // expr_int: expr_int "&" expr_int
#line 662 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 2692 "frontend/parser.cpp"
    break;

  case 330: // expr_int: expr_int "^" expr_int
#line 663 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 2698 "frontend/parser.cpp"
    break;

  case 331: // expr_int: expr_int "|" expr_int
#line 664 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 2704 "frontend/parser.cpp"
    break;

  case 332: // expr_float: "float"
#line 668 "frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 2710 "frontend/parser.cpp"
    break;

  case 333: // expr_float: "-" expr_float
#line 669 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 2716 "frontend/parser.cpp"
    break;

  case 334: // expr_float: "(" expr_float ")"
#line 670 "frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 2722 "frontend/parser.cpp"
    break;

  case 335: // expr_float: expr_float "**" expr_float
#line 671 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2728 "frontend/parser.cpp"
    break;

  case 336: // expr_float: expr_float "**" expr_int
#line 672 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2734 "frontend/parser.cpp"
    break;

  case 337: // expr_float: expr_int "**" expr_float
#line 673 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2740 "frontend/parser.cpp"
    break;

  case 338: // expr_float: expr_float "*" expr_float
#line 674 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 2746 "frontend/parser.cpp"
    break;

  case 339: // expr_float: expr_float "*" expr_int
#line 675 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 2752 "frontend/parser.cpp"
    break;

  case 340: // expr_float: expr_int "*" expr_float
#line 676 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 2758 "frontend/parser.cpp"
    break;

  case 341: // expr_float: expr_float "/" expr_float
#line 677 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 2764 "frontend/parser.cpp"
    break;

  case 342: // expr_float: expr_float "/" expr_int
#line 678 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 2770 "frontend/parser.cpp"
    break;

  case 343: // expr_float: expr_int "/" expr_float
#line 679 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 2776 "frontend/parser.cpp"
    break;

  case 344: // expr_float: expr_float "%" expr_float
#line 680 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2782 "frontend/parser.cpp"
    break;

  case 345: // expr_float: expr_float "%" expr_int
#line 681 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2788 "frontend/parser.cpp"
    break;

  case 346: // expr_float: expr_int "%" expr_float
#line 682 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2794 "frontend/parser.cpp"
    break;

  case 347: // expr_float: expr_float "-" expr_float
#line 683 "frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 2800 "frontend/parser.cpp"
    break;

  case 348: // expr_float: expr_float "-" expr_int
#line 684 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 2806 "frontend/parser.cpp"
    break;

  case 349: // expr_float: expr_int "-" expr_float
#line 685 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 2812 "frontend/parser.cpp"
    break;

  case 350: // expr_float: expr_float "+" expr_float
#line 686 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 2818 "frontend/parser.cpp"
    break;

  case 351: // expr_float: expr_float "+" expr_int
#line 687 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 2824 "frontend/parser.cpp"
    break;

  case 352: // expr_float: expr_int "+" expr_float
#line 688 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 2830 "frontend/parser.cpp"
    break;

  case 353: // expr_str: "string"
#line 692 "frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2836 "frontend/parser.cpp"
    break;

  case 354: // expr_str: "(" expr_str ")"
#line 693 "frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 2842 "frontend/parser.cpp"
    break;

  case 355: // expr_str: expr_str "++" expr_str
#line 694 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 2848 "frontend/parser.cpp"
    break;

  case 356: // expr_str: expr_str "++" expr_int
#line 695 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 2854 "frontend/parser.cpp"
    break;

  case 357: // expr_str: expr_str "++" expr_float
#line 696 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 2860 "frontend/parser.cpp"
    break;

  case 358: // expr_str: expr_str "++" expr_bool
#line 697 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2866 "frontend/parser.cpp"
    break;

  case 359: // expr_str: expr_str "++" expr_none
#line 698 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 2872 "frontend/parser.cpp"
    break;

  case 360: // expr_str: expr_int "++" expr_str
#line 699 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 2878 "frontend/parser.cpp"
    break;

  case 361: // expr_str: expr_int "++" expr_int
#line 700 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 2884 "frontend/parser.cpp"
    break;

  case 362: // expr_str: expr_int "++" expr_float
#line 701 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 2890 "frontend/parser.cpp"
    break;

  case 363: // expr_str: expr_int "++" expr_bool
#line 702 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2896 "frontend/parser.cpp"
    break;

  case 364: // expr_str: expr_int "++" expr_none
#line 703 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 2902 "frontend/parser.cpp"
    break;

  case 365: // expr_str: expr_float "++" expr_str
#line 704 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 2908 "frontend/parser.cpp"
    break;

  case 366: // expr_str: expr_float "++" expr_int
#line 705 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 2914 "frontend/parser.cpp"
    break;

  case 367: // expr_str: expr_float "++" expr_float
#line 706 "frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 2920 "frontend/parser.cpp"
    break;

  case 368: // expr_str: expr_float "++" expr_bool
#line 707 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2926 "frontend/parser.cpp"
    break;

  case 369: // expr_str: expr_float "++" expr_none
#line 708 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 2932 "frontend/parser.cpp"
    break;

  case 370: // expr_str: expr_bool "++" expr_str
#line 709 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 2938 "frontend/parser.cpp"
    break;

  case 371: // expr_str: expr_bool "++" expr_int
#line 710 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 2944 "frontend/parser.cpp"
    break;

  case 372: // expr_str: expr_bool "++" expr_float
#line 711 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 2950 "frontend/parser.cpp"
    break;

  case 373: // expr_str: expr_bool "++" expr_bool
#line 712 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2956 "frontend/parser.cpp"
    break;

  case 374: // expr_str: expr_bool "++" expr_none
#line 713 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 2962 "frontend/parser.cpp"
    break;

  case 375: // expr_str: expr_none "++" expr_str
#line 714 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 2968 "frontend/parser.cpp"
    break;

  case 376: // expr_str: expr_none "++" expr_int
#line 715 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 2974 "frontend/parser.cpp"
    break;

  case 377: // expr_str: expr_none "++" expr_float
#line 716 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 2980 "frontend/parser.cpp"
    break;

  case 378: // expr_str: expr_none "++" expr_bool
#line 717 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2986 "frontend/parser.cpp"
    break;

  case 379: // expr_str: expr_none "++" expr_none
#line 718 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 2992 "frontend/parser.cpp"
    break;

  case 380: // expr_bool: "bool"
#line 722 "frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 2998 "frontend/parser.cpp"
    break;

  case 381: // expr_bool: "(" expr_bool ")"
#line 723 "frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 3004 "frontend/parser.cpp"
    break;

  case 382: // expr_bool: "not" expr_bool
#line 724 "frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 3010 "frontend/parser.cpp"
    break;

  case 383: // expr_bool: expr_bool "or" expr_bool
#line 725 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 3016 "frontend/parser.cpp"
    break;

  case 384: // expr_bool: expr_bool "and" expr_bool
#line 726 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 3022 "frontend/parser.cpp"
    break;

  case 385: // expr_bool: expr_bool "==" expr_bool
#line 728 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 3028 "frontend/parser.cpp"
    break;

  case 386: // expr_bool: expr_int "==" expr_int
#line 729 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 3034 "frontend/parser.cpp"
    break;

  case 387: // expr_bool: expr_int "==" expr_float
#line 730 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 3040 "frontend/parser.cpp"
    break;

  case 388: // expr_bool: expr_float "==" expr_float
#line 731 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 3046 "frontend/parser.cpp"
    break;

  case 389: // expr_bool: expr_float "==" expr_int
#line 732 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 3052 "frontend/parser.cpp"
    break;

  case 390: // expr_bool: expr_str "==" expr_str
#line 733 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 3058 "frontend/parser.cpp"
    break;

  case 391: // expr_bool: expr_none "==" expr_none
#line 734 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 3064 "frontend/parser.cpp"
    break;

  case 392: // expr_bool: expr_bool "!=" expr_bool
#line 736 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 3070 "frontend/parser.cpp"
    break;

  case 393: // expr_bool: expr_int "!=" expr_int
#line 737 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 3076 "frontend/parser.cpp"
    break;

  case 394: // expr_bool: expr_int "!=" expr_float
#line 738 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 3082 "frontend/parser.cpp"
    break;

  case 395: // expr_bool: expr_float "!=" expr_float
#line 739 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 3088 "frontend/parser.cpp"
    break;

  case 396: // expr_bool: expr_float "!=" expr_int
#line 740 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 3094 "frontend/parser.cpp"
    break;

  case 397: // expr_bool: expr_str "!=" expr_str
#line 741 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 3100 "frontend/parser.cpp"
    break;

  case 398: // expr_bool: expr_none "!=" expr_none
#line 742 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 3106 "frontend/parser.cpp"
    break;

  case 399: // expr_bool: expr_int ">" expr_int
#line 744 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 3112 "frontend/parser.cpp"
    break;

  case 400: // expr_bool: expr_int ">" expr_float
#line 745 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 3118 "frontend/parser.cpp"
    break;

  case 401: // expr_bool: expr_float ">" expr_float
#line 746 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 3124 "frontend/parser.cpp"
    break;

  case 402: // expr_bool: expr_float ">" expr_int
#line 747 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 3130 "frontend/parser.cpp"
    break;

  case 403: // expr_bool: expr_str ">" expr_str
#line 748 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 3136 "frontend/parser.cpp"
    break;

  case 404: // expr_bool: expr_int "<" expr_int
#line 750 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 3142 "frontend/parser.cpp"
    break;

  case 405: // expr_bool: expr_int "<" expr_float
#line 751 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 3148 "frontend/parser.cpp"
    break;

  case 406: // expr_bool: expr_float "<" expr_float
#line 752 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 3154 "frontend/parser.cpp"
    break;

  case 407: // expr_bool: expr_float "<" expr_int
#line 753 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 3160 "frontend/parser.cpp"
    break;

  case 408: // expr_bool: expr_str "<" expr_str
#line 754 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 3166 "frontend/parser.cpp"
    break;

  case 409: // expr_bool: expr_int ">=" expr_int
#line 756 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 3172 "frontend/parser.cpp"
    break;

  case 410: // expr_bool: expr_int ">=" expr_float
#line 757 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 3178 "frontend/parser.cpp"
    break;

  case 411: // expr_bool: expr_float ">=" expr_float
#line 758 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 3184 "frontend/parser.cpp"
    break;

  case 412: // expr_bool: expr_float ">=" expr_int
#line 759 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 3190 "frontend/parser.cpp"
    break;

  case 413: // expr_bool: expr_str ">=" expr_str
#line 760 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 3196 "frontend/parser.cpp"
    break;

  case 414: // expr_bool: expr_int "<=" expr_int
#line 762 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 3202 "frontend/parser.cpp"
    break;

  case 415: // expr_bool: expr_int "<=" expr_float
#line 763 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 3208 "frontend/parser.cpp"
    break;

  case 416: // expr_bool: expr_float "<=" expr_float
#line 764 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 3214 "frontend/parser.cpp"
    break;

  case 417: // expr_bool: expr_float "<=" expr_int
#line 765 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 3220 "frontend/parser.cpp"
    break;

  case 418: // expr_bool: expr_str "<=" expr_str
#line 766 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 3226 "frontend/parser.cpp"
    break;

  case 419: // expr_bool: expr_str "in" expr_str
#line 768 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[0].value.as < std::string > ().find(yystack_[2].value.as < std::string > ()) != std::string::npos; }
#line 3232 "frontend/parser.cpp"
    break;

  case 424: // mattype: "identifier" matsq
#line 780 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3238 "frontend/parser.cpp"
    break;

  case 425: // mattype: "'int'" matsq
#line 781 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(INT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3244 "frontend/parser.cpp"
    break;

  case 426: // mattype: "'float'" matsq
#line 782 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(FLOAT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3250 "frontend/parser.cpp"
    break;

  case 427: // mattype: "'string'" matsq
#line 783 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(STRING_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3256 "frontend/parser.cpp"
    break;

  case 428: // mattype: "'bool'" matsq
#line 784 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(BOOL_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3262 "frontend/parser.cpp"
    break;

  case 436: // matsq: "[" "]"
#line 793 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(scanner->parseInt(-1)); }
#line 3268 "frontend/parser.cpp"
    break;

  case 437: // matsq: "[" int_val "]"
#line 794 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 3274 "frontend/parser.cpp"
    break;

  case 438: // matsq: "[" "]" matsq
#line 795 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), scanner->parseInt(-1)); }
#line 3280 "frontend/parser.cpp"
    break;

  case 439: // matsq: "[" int_val "]" matsq
#line 796 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[2].value.as < ptc::ir::Expr * > ()); }
#line 3286 "frontend/parser.cpp"
    break;

  case 446: // type: mattype "?"
#line 806 "frontend/parser.yy"
       { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 3292 "frontend/parser.cpp"
    break;

  case 447: // type: "'int'"
#line 807 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, true); }
#line 3298 "frontend/parser.cpp"
    break;

  case 448: // type: "'float'"
#line 808 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, true); }
#line 3304 "frontend/parser.cpp"
    break;

  case 449: // type: "'string'"
#line 809 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, true); }
#line 3310 "frontend/parser.cpp"
    break;

  case 450: // type: "'bool'"
#line 810 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, true); }
#line 3316 "frontend/parser.cpp"
    break;

  case 451: // type: "identifier"
#line 811 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[0].value.as < std::string > (), true); }
#line 3322 "frontend/parser.cpp"
    break;

  case 453: // type: mattype
#line 813 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 3328 "frontend/parser.cpp"
    break;


#line 3332 "frontend/parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -763;

  const short  Parser ::yytable_ninf_ = -452;

  const short
   Parser ::yypact_[] =
  {
     486,  -763,  -763,  -763,  -763,  -763,  -763,  -763,  1763,   516,
     500,   701,   334,   -38,   -26,  -763,    44,  -763,  -763,  2308,
    -763,  -763,    50,    18,    35,    38,    40,    62,    68,   303,
      16,    80,    57,  -763,  -763,   376,   376,  -763,  -763,  -763,
     169,  -763,  2192,  -763,   243,  -763,  -763,   376,   376,   376,
    2352,  2623,  -763,   686,    12,   547,  3149,  3287,   852,   218,
      41,   270,     0,   330,   462,  2553,   338,   686,    12,   547,
    2655,  3098,   634,   719,  2308,  -763,   462,  -763,     3,   502,
     502,  -763,  -763,  -763,  -763,  1257,   455,  3172,  3321,  1073,
    -763,   334,   334,  -763,   313,   304,  -763,   905,  -763,   363,
    1372,   369,  -763,   369,  -763,   369,  -763,   369,  -763,   233,
    -763,   404,   617,   315,  2308,   369,  -763,  -763,  -763,   977,
    2308,  -763,  -763,  -763,  2421,  -763,  -763,  -763,  -763,  -763,
    2308,   414,  2451,  -763,  -763,   413,  2308,  -763,  -763,  -763,
    2308,  2308,  2308,  2308,  2308,  2308,  2308,  2308,  2308,  2308,
    2308,  2308,  2308,  -763,  1446,   977,  2308,  2308,  2308,  2308,
    2308,  2308,  2308,  2308,  2308,  2308,  2308,  2308,  2308,  2308,
    2308,  2308,  2308,  2308,  2308,  2308,  2308,  2308,  -763,   977,
    2308,  2308,  2308,  2308,  2308,  2308,  -763,  2308,  2308,  2308,
    2308,  2308,  2308,  2308,  2308,  2308,  2308,  2308,  2308,  2308,
     502,  2308,  2308,  2308,  2308,  2308,  2308,  2308,  2308,  2308,
    2308,  2308,  2308,  2308,  2308,  2308,  2308,  2308,  2308,  2308,
    2308,  2308,  2308,  2308,  2308,  2308,  2308,  2308,  2308,  2308,
    2308,  2308,  2308,  2308,  2308,  2308,  2308,  2308,  2308,  2308,
    2308,  2308,  2308,   369,  -763,  -763,    69,    -1,   473,  -763,
     977,   489,  -763,  -763,  -763,  -763,  -763,  -763,    27,   505,
    -763,   589,  1145,  1353,   502,   502,   502,   502,   502,   334,
     334,   334,   334,   334,   502,   502,   502,   502,   502,   502,
    2942,  3126,   728,   799,   701,   366,   366,   701,   502,   502,
     502,   502,   502,   502,   701,   502,   502,   502,   502,   502,
     502,   701,   701,   701,   701,   701,   701,   701,   701,   701,
     701,   701,   701,   701,  1911,  -763,   334,   334,   334,   334,
     334,  2308,   -26,    15,   512,   521,     1,  2308,   369,  2623,
     518,  3149,  3287,   852,   218,  -763,  -763,  -763,  -763,   557,
      20,   262,   671,     9,  -763,   527,   593,   474,  3149,  -763,
     129,   474,  -763,   601,  2421,  -763,  1243,   608,   609,  -763,
    2316,  -763,  -763,  -763,  -763,  -763,  -763,  -763,  -763,  -763,
    -763,  -763,  -763,  -763,     2,  -763,   236,   461,    21,   947,
    1082,   461,    21,   947,  1082,   306,   616,   623,   627,   306,
     623,   627,   306,   623,   627,   306,   627,  2771,   556,   583,
    3195,  3344,   501,   222,  2829,   624,  2800,   577,  2869,   603,
    3013,  3298,  2914,  3241,  2984,  3264,   567,  1476,   567,  1476,
    3042,   760,  -763,  -763,  1390,  1614,   530,  -763,  3042,   760,
    -763,  -763,  1390,  1614,   530,  -763,   342,   881,  1516,   637,
     342,   881,  1516,   637,   342,   881,  1516,   637,   342,   881,
    1516,   637,   474,   237,   461,    21,   461,    21,   306,   616,
    2869,   945,  3042,   760,  3042,   760,  2771,   556,   583,  3195,
    3344,   501,   222,  2869,   945,  3042,  -763,  3042,  -763,  2771,
     556,   583,  3195,  3344,   501,   222,  2869,   945,  3042,  -763,
    3042,  -763,   461,   947,  1082,   461,   947,  1082,   306,   623,
     627,   306,   623,   627,   306,   623,   627,  1782,   645,  2771,
     556,   583,  3195,  3344,   501,   222,  2869,   945,  3013,  3298,
    2914,  3241,  2984,  3264,   567,  1476,   567,  1476,  3042,  1390,
    1614,  3042,  1390,  1614,   342,   881,  1516,   342,   881,  1516,
     342,   881,  1516,   342,   881,  1516,   461,   947,  1082,   461,
     947,  1082,   306,   623,   627,   306,   623,   627,   306,   623,
     627,   306,   623,   627,  2771,   556,   583,  3195,  3344,   501,
     222,  2869,   945,  3042,  1390,  1614,  3042,  1390,  1614,   342,
     881,  1516,   342,   881,  1516,   342,   881,  1516,   342,   881,
    1516,   648,  2771,   556,   583,  3195,  3344,   501,   222,  2869,
     945,   603,  3042,   530,  3042,   530,   342,   637,   342,   637,
     342,   637,   342,   637,  2771,   556,   583,  3195,  3344,   501,
     222,  2829,   624,  2800,   577,  2869,   945,  3042,  -763,  3042,
    -763,  -763,  -763,   302,   644,    19,  1563,   297,   311,  -763,
     669,  -763,  -763,  2308,  -763,  1214,  1311,  1214,  1311,   623,
     645,   623,   645,   623,   645,  1418,  1306,  1190,  1111,  1111,
    1214,  1311,  1214,  1311,   623,   645,   623,   645,   623,   645,
     623,   645,   481,  3218,  3355,  1258,   666,   677,  -763,  -763,
     481,  3218,  3355,  1258,   666,  1210,  1565,  1210,  1565,  1210,
    1565,  1210,  1565,  1210,  1565,  1210,  1565,   481,  3218,  3355,
    1258,   666,  1210,  1565,  1210,  1565,  1210,  1565,  1210,  1565,
    1210,  1565,  1210,  1565,   481,  3218,  3355,  1258,   666,  1584,
     112,  1324,  1324,  -763,  -763,  -763,  -763,   481,  3218,  3355,
    1258,   666,   571,   640,  -763,  -763,   613,   613,  -763,  -763,
    -763,  -763,  -763,  2523,  2523,  2523,  -763,  -763,  -763,   369,
     250,   250,  -763,   612,   676,   690,     4,   495,    30,   654,
      13,  -763,  1657,   323,    36,  1127,   662,  -763,  -763,  2192,
    1537,   693,  2308,  2192,  -763,  2308,  -763,  -763,  -763,  -763,
     699,  -763,  -763,   495,   106,  -763,  -763,  -763,   330,  2537,
     703,  2695,   713,   533,  3070,   714,   718,   737,   738,  -763,
     736,  -763,   717,  -763,   250,   755,  -763,   495,   699,   699,
     763,  -763,   743,  -763,  1687,  -763,  1844,   337,  2308,  -763,
     753,  -763,   769,   721,  -763,  -763,  -763,   495,  2553,   797,
    2655,  2192,  2192,  2308,  2308,  2192,  2192,  2192,  2192,  -763,
    2308,  -763,  2308,  -763,    22,   654,    26,  2308,  -763,  -763,
     798,  -763,   800,  -763,  1870,   771,  -763,  -763,  -763,  -763,
    2192,  -763,  -763,  -763,  -763,  -763,  -763,  -763,   781,  -763,
    -763,  -763,  -763,  -763,  -763,  -763,   763,  -763,  -763,  -763,
    -763,   811,   785,  -763,  2308,  -763,  -763,  -763
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
       0,    58,    55,     0,     0,     0,     0,     0,     0,    71,
       0,   298,     0,     0,   113,     0,     0,   315,   114,     0,
       0,    24,     0,     0,   110,     0,   115,   112,   111,   420,
       0,    77,    76,     0,     0,   113,   287,   290,     0,     0,
       0,   297,     0,     0,   296,     0,     0,     0,     0,   439,
       0,    59,     0,    56,    60,    62,    67,     0,     0,     0,
      70,   302,     0,   300,     0,   299,     0,     0,     0,    46,
      25,    26,     0,    52,    95,   423,    65,     0,   297,     0,
     296,     0,     0,     0,     0,     0,     0,     0,     0,    57,
       0,    61,     0,    68,     0,    74,     0,     0,   305,   304,
       0,   303,     0,   301,     0,   316,    27,    48,    54,    50,
       0,    66,   293,    28,    29,    41,    44,   294,     0,    42,
      45,    40,    43,    64,    63,    72,     0,    73,   308,   307,
     306,     0,     0,    51,     0,   309,   317,   295
  };

  const short
   Parser ::yypgoto_[] =
  {
    -763,  -763,  -116,   684,   -31,   231,   314,   240,  -762,  -763,
     506,  -763,  -763,  -763,  -763,  -763,  -763,  -763,  -763,  -763,
    -763,  -763,  -763,  -476,  -763,  -763,   765,   193,    25,   739,
    -763,   695,  -763,  1861,   227,     6,   770,  1924,  -720,   384,
    1754,  1604,  2149,   -59,   -37,    -8,   642,   883,  1203,  -763,
      67,  -763,    -6,   374
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    31,    32,   128,    33,    34,   864,   865,   135,    35,
      96,    36,    37,    38,    39,    40,    41,    42,    43,   859,
      44,   860,    45,   754,   755,    46,   111,   758,   759,    47,
      48,    49,   374,    50,    51,    52,    78,    67,   792,   793,
     178,    68,    69,   117,   346,    56,   332,   333,   334,    60,
     634,    61,   118,    62
  };

  const short
   Parser ::yytable_[] =
  {
      70,   125,    83,    87,    93,   251,   259,   819,   -69,   246,
     246,   823,   774,   246,    66,   260,   356,   102,   104,   106,
     108,   764,   246,   751,   796,   798,   100,   119,   246,   100,
     640,   246,   179,   187,   752,   246,    94,   188,   182,   641,
     807,   636,   775,   261,   189,   190,   100,   100,    95,   100,
     765,   100,   100,    97,   244,   120,   743,   123,   124,   780,
       2,     3,     4,     5,     6,     7,     8,   261,     9,   829,
     808,   262,    83,    10,   247,   746,   753,   280,   805,   632,
     122,    11,   115,   314,   315,   101,    12,   810,    23,    24,
      25,    26,   331,   352,   633,   335,   875,   336,   883,   337,
     876,   338,   103,  -437,   331,   105,   348,   107,   243,   349,
    -437,   331,   348,    13,    14,    15,   827,    16,    17,    18,
      19,    20,    21,    22,    99,    23,    24,    25,    26,    27,
      28,    29,    30,   309,   310,   311,   109,    23,    24,    25,
      26,   768,   110,   633,   312,   313,   808,   331,   379,   383,
     387,   390,   393,   348,   400,   348,   348,   348,   411,   413,
     415,   417,   419,   424,   432,   437,   441,   445,   449,   348,
     765,   331,   348,   348,   348,   348,   348,   348,   130,   469,
     348,   348,   348,   482,   348,   348,   348,   493,   496,   499,
     502,   505,   507,   512,   348,   519,   521,   523,   525,   527,
     529,   532,   535,   538,   541,   544,   547,   550,   553,   556,
     559,   562,   567,   348,   574,   577,   580,   583,   586,   589,
     331,   595,   348,   348,   348,   348,   348,   348,   348,   617,
     348,   348,   348,   348,   348,    65,   339,   631,   770,   237,
     238,   239,   331,   240,   238,   239,   340,   240,   776,   777,
     241,   242,   136,   751,   241,   242,   645,   647,   649,   651,
     653,   655,   656,   657,   658,   659,   660,   662,   664,   666,
     668,   670,   757,   133,   800,   801,   673,   765,   765,   681,
     685,   687,   689,   691,   693,   695,   698,   702,   704,   706,
     708,   710,   712,   715,    87,    87,    87,    87,    87,    87,
      87,   728,    87,    87,    87,    87,   753,   783,   736,   737,
     738,   739,   740,   100,   112,   154,   113,   155,    23,    24,
      25,    26,   748,   785,   633,   125,   161,   329,   841,   344,
      23,    24,    25,    26,   331,   813,   633,   245,     3,   329,
     249,   347,   114,    91,   322,   177,   329,   351,   253,   853,
      92,   154,   765,   155,   345,   321,   134,   156,   157,   158,
     159,   160,   161,    12,   814,    23,    24,    25,    26,   115,
     115,   633,   169,   170,     7,   677,   126,  -451,   854,   127,
     100,   177,   329,   377,   381,   385,   389,   392,   395,   397,
     404,   406,   408,   410,   412,   414,   416,   418,   420,   428,
     436,   440,   444,   448,   452,   327,   329,   454,   456,   458,
     460,   462,   464,   341,   466,   473,   475,   477,   479,   486,
     488,   490,   492,   495,   498,   501,   504,   354,   509,   516,
     518,   520,   522,   524,   526,   528,   531,   534,   537,   540,
     543,   546,   549,   552,   555,   558,   561,   564,   571,   573,
     576,   579,   582,   585,   588,   329,   592,   599,   602,   604,
     606,   608,   610,   612,   614,   621,   623,   625,   627,   629,
     154,   326,   155,   250,   357,   113,   284,   329,   158,   159,
     160,   161,   637,   154,   330,   155,     1,   285,   286,     2,
       3,     4,     5,     6,     7,     8,   343,     9,   131,   639,
     177,   114,    10,   350,     3,     4,     3,     4,   132,    79,
      11,    79,   228,   285,   286,    12,    80,   642,    80,    74,
       3,     4,     5,     6,     7,     8,   230,     9,    75,    12,
     749,    12,    10,   231,   232,   233,   234,   235,   236,   376,
      11,   228,    13,    14,    15,    12,    16,    17,    18,    19,
      20,    21,    22,   744,    23,    24,    25,    26,    27,    28,
      29,    30,   745,   453,   233,   234,   235,   236,   191,   329,
     750,   833,   192,   834,    81,    82,   154,   782,   155,   193,
     194,   188,   156,   157,   158,   159,   160,   161,   189,   190,
      76,    30,   643,     3,     4,     5,     6,     7,     8,   238,
       9,   766,   240,   312,   313,    10,   177,   767,   192,   241,
     242,   769,   591,    11,   228,   193,   194,   772,    12,   773,
     635,     3,     4,     5,     6,     7,     8,   179,     9,   328,
     318,   319,   320,    10,   638,   231,   232,   233,   234,   235,
     236,    11,    57,   200,   256,   228,    12,   219,   228,   240,
      71,    57,    84,    88,   779,   229,   241,   242,   342,   230,
     778,    57,   310,    76,    30,   279,   231,   232,   233,   234,
     235,   236,   312,   313,    57,     3,     4,     5,     6,     7,
       8,   786,     9,   761,    57,   788,   802,    10,   310,   311,
     803,    76,    30,   804,   809,    11,   821,   179,   312,   313,
      12,   180,   181,   182,   818,     3,     4,     5,     6,     7,
      85,   183,   762,   831,   756,   760,    57,    80,   184,   185,
     129,   263,    84,   832,   835,    11,   763,   281,   836,   257,
      12,   137,   138,   139,   153,   794,   794,   794,   256,   125,
     237,   238,   239,   799,   240,    76,    30,   837,   838,   301,
     839,   241,   242,   302,   331,   848,   856,   331,   799,   840,
     303,   304,   305,   306,   307,   308,    57,    23,    24,    25,
      26,   179,    57,   633,    57,   180,   181,   182,    57,   857,
     858,   830,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    66,    57,   842,   380,   384,
     388,   391,   394,   396,   401,   847,   331,   862,   331,   257,
     878,   882,   879,   425,   433,   438,   442,   446,   450,   884,
     309,   310,   311,   885,   345,   331,   331,   248,   742,   470,
     784,   312,   313,   483,   845,   359,   325,   494,   497,   500,
     503,   506,   508,   513,   258,   886,   331,   825,     0,     0,
     530,   533,   536,   539,   542,   545,   548,   551,   554,   557,
     560,   563,   568,   228,   575,   578,   581,   584,   587,   590,
       0,   596,     0,   229,     0,     0,   331,   230,     0,   618,
       0,     0,     0,    58,   231,   232,   233,   234,   235,   236,
       0,    72,    58,     0,    89,     0,   195,   196,   197,   198,
     199,   200,    58,    57,     0,     0,   646,   648,   650,   652,
     654,   206,   207,     0,     0,    58,   661,   663,   665,   667,
     669,   671,     0,     0,     0,    58,   674,     0,     0,   682,
     686,   688,   690,   692,   694,   696,   699,   703,   705,   707,
     709,   711,   713,   716,    88,    88,    88,    88,    88,    88,
      88,   729,    88,    88,    88,    88,   179,    58,     0,     0,
     180,   181,   182,    57,   197,   198,   199,   200,   282,    57,
     791,   791,   791,    23,    24,    25,    26,   184,   185,   323,
     324,     3,     4,     5,     6,     7,     8,     0,     9,   329,
       0,     0,   329,    10,     0,     0,    57,     0,    57,     0,
     133,    11,     0,     0,   133,     0,    12,    58,     0,     0,
       0,   760,     0,    58,     0,    58,   828,     0,   342,    58,
       0,     0,     0,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,     0,    58,     0,     0,
       0,   329,     0,   329,     0,   402,     0,     0,   409,     0,
       0,    76,    30,     0,   426,   434,   439,   443,   447,   451,
     329,   329,   863,   863,     0,     0,   863,   863,   863,   863,
     471,   806,   866,     0,   484,   869,   870,   871,   872,     0,
       0,   329,     0,   134,   514,     0,     0,   134,     0,     0,
       0,   133,     0,     0,   301,     0,     0,   826,   302,   216,
     217,   218,   219,   569,     0,   303,   304,   305,   306,   307,
     308,   329,   597,   601,   603,   605,   607,   609,   611,   613,
     619,   843,     0,     0,   756,   756,   316,   317,   318,   319,
     320,     3,     4,     5,     6,     7,     8,     0,     9,   815,
       0,   861,     0,    10,    58,     0,   812,     0,     0,   817,
       0,    11,     0,     0,   635,   254,    12,     0,     0,     0,
     264,   265,   266,   267,   268,   200,     0,   675,   816,     0,
     683,   269,   270,   271,   134,   272,   273,   700,   756,     0,
       0,     0,   844,   846,   717,   719,   721,   722,   723,   724,
     725,   726,   730,    89,    89,    89,    89,     0,   850,     0,
     852,    76,    30,    59,    58,   316,   317,   318,   319,   320,
      58,    73,    59,     0,    90,     0,   269,   867,   868,     0,
     272,   273,    59,     0,     0,   264,   265,   266,   267,   268,
     200,   266,   267,   268,   200,    59,     0,    58,   881,    58,
     272,   273,     0,     0,   124,    59,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,   771,     0,    10,
       0,     3,     4,     5,     6,    63,    85,    11,   887,     0,
       0,     0,    12,    80,     0,     0,     0,    59,    57,     0,
       0,    11,     0,   302,     0,    57,    12,     0,   283,     0,
     303,   304,   305,   306,   307,   308,     0,     0,     0,    13,
      14,    15,     0,    16,    17,    18,    19,    20,    21,    22,
       0,    23,    24,    25,    26,    27,    28,    29,    30,     0,
       0,   316,   317,   318,   319,   320,     0,    59,   276,   277,
     278,   279,   269,    59,   271,    59,   272,   273,     0,    59,
       0,     0,     0,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,     0,    59,   305,   306,
     307,   308,     0,   255,     0,   403,   405,   407,   274,   275,
     276,   277,   278,   279,   427,   435,     3,     4,     5,     6,
       7,     8,     0,     9,   328,    57,    57,    57,    10,     0,
     472,     0,     0,     0,   485,     0,    11,     0,     0,     0,
       0,    12,     0,     0,   515,   195,   196,   197,   198,   199,
     200,    57,    57,     0,    57,    57,     0,    57,     0,     0,
     206,   207,     0,   570,   210,   211,   212,   213,     0,     0,
       0,    71,   598,   316,   317,   318,   319,   320,     0,     0,
     620,   622,   624,     0,   628,   630,    76,    30,   272,   273,
       3,     4,     5,     6,     7,     8,   373,     9,     0,     0,
      57,     0,    10,     0,    59,     0,     0,     0,     0,     0,
      11,     0,     0,    57,    57,    12,     0,    57,    57,    57,
      57,     0,    57,     0,    57,     0,     0,   676,     0,    57,
     684,   195,   196,   197,   198,   199,   200,   701,     0,     0,
       0,     0,    57,     0,   718,   720,   720,   720,   720,   720,
     720,   720,   731,   732,   733,   734,   735,     0,     0,    58,
      76,    30,     0,     0,    59,     0,    58,     0,     0,     0,
      59,   214,   215,   216,   217,   218,   219,     0,   124,     0,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,   820,     0,    10,     0,     0,     0,    59,     0,    59,
       0,    11,     0,     0,     0,     0,    12,     3,     4,     5,
       6,     7,     8,     0,     9,     0,   113,     0,     0,    10,
     274,   275,   276,   277,   278,   279,     0,    11,     0,     0,
       0,     0,    12,    13,    14,    15,     0,    16,    17,    18,
      19,    20,    21,    22,    54,    23,    24,    25,    26,    27,
      28,    29,    30,    54,     0,    86,   303,   304,   305,   306,
     307,   308,     0,    54,     0,     0,    58,    58,    58,   214,
     215,   216,   217,   218,   219,     0,    54,    76,    30,     0,
       0,     0,     0,     0,     0,     0,    54,     0,   224,   225,
     226,   227,    58,    58,     0,    58,    58,     0,    58,     0,
       0,     3,     4,     5,     6,     7,     8,     0,     9,   811,
       0,     0,    72,    10,     0,     0,     0,     0,    54,     0,
       0,    11,     0,     0,     0,     0,    12,     0,     0,    86,
       0,     3,     4,     5,     6,     7,     8,     0,     9,   849,
       0,    58,     0,    10,     0,     0,     0,     0,     0,     0,
       0,    11,     0,     0,    58,    58,    12,     0,    58,    58,
      58,    58,     0,    58,     0,    58,     0,     0,    54,     0,
      58,    76,    30,     0,    54,     0,    54,     0,     0,     0,
      54,     0,     0,    58,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,     0,    54,     0,
       0,    76,    30,     0,     0,     0,   398,     3,     4,     5,
       6,    63,     8,     0,     9,   422,   430,     0,     0,    10,
       0,     0,     0,   116,   121,     0,     0,    11,     0,     0,
       0,   467,    12,   476,   478,   480,     0,   264,   265,   266,
     267,   268,   200,     0,     0,   510,     0,   186,   269,   270,
     271,     0,   272,   273,     0,     0,     0,     0,   116,     0,
       0,   186,     0,     0,   565,     0,     0,     0,     0,     0,
     116,     0,     0,   593,     0,     0,     0,    64,    30,    59,
       0,   615,     0,     0,     0,     0,    59,     0,     3,     4,
       5,     6,     7,     8,     0,     9,   851,     0,     0,     0,
      10,     0,     0,     0,     0,    54,     0,     0,    11,     0,
      77,     0,     0,    12,     3,     4,     5,     6,     7,     8,
      98,     9,   880,     0,     0,     0,    10,     0,   672,   678,
     679,   680,     0,     0,    11,     0,     0,     0,   697,    12,
       0,     0,     0,     0,     0,   714,    86,    86,    86,    86,
      86,    86,    86,   727,    86,    86,    86,    86,    76,    30,
       0,   254,     0,     0,    53,    54,   316,   317,   318,   319,
     320,    54,     0,    53,     0,    77,     0,   269,   270,   271,
       0,   272,   273,    53,    76,    30,    59,    59,    59,     0,
       0,     0,     0,     0,     0,     0,    53,     0,    54,     0,
      54,     0,     0,     0,     0,     0,    53,     0,     0,     0,
       0,     0,    59,    59,     0,    59,    59,     0,    59,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   353,    73,     0,     0,     0,     0,   358,    53,     0,
       0,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,     0,   375,     0,     0,     0,     0,
       0,    59,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    59,    59,     0,     0,    59,    59,
      59,    59,     0,    59,     0,    59,     0,     0,    53,     0,
      59,     0,     0,     0,    53,     0,    53,     0,     0,     0,
      53,     0,     0,    59,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,     0,    53,     0,
     378,   382,   386,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   421,   429,     0,     0,     0,
       0,     0,     0,     0,   455,   457,   459,   461,   463,   465,
       0,     0,   474,     0,     0,     0,   487,     0,     0,     0,
       0,     0,   644,     0,     0,     0,   517,     0,     0,     0,
       0,     0,   186,     0,     0,     0,   186,     0,     0,     0,
     186,     0,     0,     0,     0,   572,     0,     0,     0,    55,
       0,     0,     0,     0,   600,     0,     0,     0,    55,     0,
       0,     0,     0,     0,   626,     0,     0,     0,    55,     0,
       0,     0,     0,     0,     0,   186,     0,     0,     0,     0,
       0,    55,   741,   186,     0,    53,     0,     0,   747,     0,
       0,    55,     0,     0,     0,   131,     3,     4,     5,     6,
       7,     8,     0,     9,     0,   132,     0,     0,    10,   186,
       0,   186,     0,   186,     0,   186,    11,   186,     0,   186,
       0,    12,     0,    55,     0,     0,     0,     0,   186,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,   186,     0,     0,     0,    53,     0,    54,    13,    14,
      15,    53,    16,    17,    18,    19,    20,    21,    22,     0,
      23,    24,    25,    26,    27,    28,    29,    30,     0,     0,
       0,   186,     0,    55,     0,     0,     0,     0,    53,    55,
      53,    55,     0,     0,     0,    55,     0,     0,     0,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,     0,    55,     0,     0,     0,     0,     0,     0,
       0,   399,     3,     4,     5,     6,     7,     8,     0,     9,
     423,   431,     0,     0,    10,     0,   186,     0,     0,     0,
       0,     0,    11,     0,     0,     0,   468,    12,     0,     0,
     481,     0,   489,   491,     0,     0,     0,    54,    54,    54,
     511,     0,   126,     0,   186,   127,     0,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   566,
     151,   152,     0,    54,    54,     0,    54,    54,   594,    54,
     186,     0,    76,    30,     0,     0,   616,     0,     0,     0,
       0,     0,     0,     0,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,     0,   151,   152,     0,     0,
      55,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    54,     0,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,    54,    54,    10,     0,    54,
      54,    54,    54,     0,    54,    11,    54,     0,     0,     0,
      12,    54,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,    54,   355,     0,    10,     0,     0,
      55,     0,     0,     0,     0,    11,    55,    13,    14,    15,
      12,    16,    17,    18,    19,    20,    21,    22,     0,    23,
      24,    25,    26,    27,    28,    29,    30,   781,     0,     0,
       0,     0,     0,    55,   787,    55,     0,    13,    14,    15,
       0,    16,    17,    18,    19,    20,    21,    22,     0,    23,
      24,    25,    26,    27,    28,    29,    30,     3,     4,     5,
       6,     7,   789,     0,     9,     0,     0,     0,     0,    10,
       0,     3,     4,     5,     6,    63,   789,    11,     9,     0,
       0,     0,    12,    10,     0,     0,     0,     0,     0,     0,
      53,    11,   154,   252,   155,     0,    12,    53,   156,   157,
     158,   159,   160,   161,   162,   163,   164,     0,   165,   166,
     167,   168,     0,   169,   170,   171,   172,   173,   174,   175,
     176,     0,   177,     0,     0,     0,     0,    76,    30,     0,
       0,     0,     0,     0,   790,   795,   797,     0,     0,     0,
       0,    64,    30,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   154,   822,   155,     0,   824,     0,   156,   157,
     158,   159,   160,   161,   162,   163,   164,     0,   165,   166,
     167,   168,     0,   169,   170,   171,   172,   173,   174,   175,
     176,     0,   177,     0,     0,   254,     0,    53,    53,    53,
     195,   196,   197,   198,   199,   200,   201,     0,     0,   855,
     202,   203,   204,   205,     0,   206,   207,   208,   209,   210,
     211,   212,   213,    53,    53,     0,    53,    53,     0,    53,
       0,   873,     0,   874,   154,   -97,   155,     0,   877,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,     0,
     165,   166,   167,   168,     0,   169,   170,   171,   172,   173,
     174,   175,   176,     0,   177,     0,     0,     0,     0,     0,
       0,     0,    53,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    53,     0,     0,    53,
      53,    53,    53,     0,    53,     0,    53,     0,     0,     0,
       0,    53,     0,     0,     0,     0,     0,     0,     0,     0,
     154,     0,   155,     0,    53,    55,   156,   157,   158,   159,
     160,   161,    55,   163,   164,     0,   165,   166,   167,   168,
       0,   169,   170,   171,   172,   173,   174,   175,   176,   154,
     177,   155,     0,     0,     0,   156,   157,   158,   159,   160,
     161,     0,   163,     0,     0,   165,   166,   167,   168,     0,
     169,   170,   171,   172,   173,   174,   175,   176,   154,   177,
     155,     0,     0,     0,   156,   157,   158,   159,   160,   161,
       0,     0,     0,     0,   165,   166,   167,   168,     0,   169,
     170,   171,   172,   173,   174,   175,   176,     0,   177,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   154,     0,
     155,     0,     0,     0,   156,   157,   158,   159,   160,   161,
       0,     0,    55,    55,    55,   166,   167,   168,     0,   169,
     170,   171,   172,   173,   174,   175,   176,     0,   177,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,    55,
       0,    55,    55,   154,    55,   155,     0,     0,     0,   156,
     157,   158,   159,   160,   161,     0,     0,     0,     0,     0,
     166,     0,   168,     0,   169,   170,   171,   172,   173,   174,
     175,   176,   254,   177,     0,     0,     0,   264,   265,   266,
     267,   268,   200,   287,     0,     0,     0,    55,   269,   270,
     271,     0,   272,   273,   288,   289,   290,   291,   292,   293,
      55,    55,     0,     0,    55,    55,    55,    55,     0,    55,
       0,    55,     0,   154,     0,   155,    55,     0,     0,   156,
     157,   158,   159,   160,   161,     0,     0,     0,     0,    55,
     166,     0,     0,     0,   169,   170,   171,   172,   173,   174,
     175,   176,   154,   177,   155,     0,     0,     0,   156,   157,
     158,   159,   160,   161,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   169,   170,   171,   172,   173,   174,   175,
     176,   154,   177,   155,     0,     0,     0,   156,   157,   158,
     159,   160,   161,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,   170,     0,     0,   173,   174,   175,   176,
    -100,   177,     0,     0,     0,   195,   196,   197,   198,   199,
     200,   201,     0,     0,     0,   202,   203,   204,   205,     0,
     206,   207,   208,   209,   210,   211,   212,   213,   255,     0,
       0,     0,     0,   214,   215,   216,   217,   218,   219,   220,
       0,     0,     0,   221,     0,     0,     0,     0,     0,     0,
     222,   223,   224,   225,   226,   227,   255,     0,     0,     0,
       0,   274,   275,   276,   277,   278,   279,   294,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,   296,
     297,   298,   299,   300,   195,   196,   197,   198,   199,   200,
     201,     0,     0,     0,   202,   203,   204,   205,     0,   206,
     207,   208,   209,   210,   211,   212,   213,   264,   265,   266,
     267,   268,   200,   287,     0,     0,     0,     0,   269,   270,
     271,     0,   272,   273,   288,   289,   290,   291,   292,   293,
     195,   196,   197,   198,   199,   200,     0,     0,     0,     0,
     202,   203,   204,   205,     0,   206,   207,   208,   209,   210,
     211,   212,   213,   264,   265,   266,   267,   268,   200,     0,
       0,     0,     0,     0,   269,   270,   271,     0,   272,   273,
     288,   289,   290,   291,   292,   293,   195,   196,   197,   198,
     199,   200,     0,     0,     0,     0,     0,   203,     0,   205,
       0,   206,   207,   208,   209,   210,   211,   212,   213,   195,
     196,   197,   198,   199,   200,     0,     0,     0,     0,     0,
     203,     0,     0,     0,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,     0,
       0,     0,   221,   195,   196,   197,   198,   199,   200,   222,
     223,   224,   225,   226,   227,     0,     0,     0,   206,   207,
     208,   209,   210,   211,   212,   213,   274,   275,   276,   277,
     278,   279,   294,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   295,   296,   297,   298,   299,   300,   214,
     215,   216,   217,   218,   219,     0,     0,     0,     0,   221,
     274,   275,   276,   277,   278,   279,   222,   223,   224,   225,
     226,   227,     0,     0,     0,     0,     0,   295,   296,   297,
     298,   299,   300
  };

  const short
   Parser ::yycheck_[] =
  {
       8,    32,    10,    11,    12,    64,     3,   769,     9,     9,
       9,   773,    10,     9,     8,    12,   132,    23,    24,    25,
      26,    12,     9,     3,   744,   745,    11,    11,     9,    11,
       3,     9,    11,    21,    14,     9,    74,    25,    17,    12,
      10,    42,    40,    40,    32,    33,    11,    11,    74,    11,
      41,    11,    11,     9,    60,    39,    41,     0,     1,    40,
       3,     4,     5,     6,     7,     8,     9,    40,    11,   789,
      40,    79,    80,    16,    74,    74,    56,    85,    74,    10,
       0,    24,    67,    91,    92,    67,    29,    74,    68,    69,
      70,    71,   100,   124,    74,   101,    74,   103,   860,   105,
      74,   107,    67,    67,   112,    67,   114,    67,    67,   115,
      74,   119,   120,    56,    57,    58,    10,    60,    61,    62,
      63,    64,    65,    66,    74,    68,    69,    70,    71,    72,
      73,    74,    75,    21,    22,    23,    74,    68,    69,    70,
      71,    12,    74,    74,    32,    33,    40,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
      41,   179,   180,   181,   182,   183,   184,   185,     9,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     8,     3,   243,   354,    21,
      22,    23,   250,    25,    22,    23,    13,    25,    12,    12,
      32,    33,     9,     3,    32,    33,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,    10,    42,   750,   751,   284,    41,    41,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,    56,    10,   316,   317,
     318,   319,   320,    11,    11,     9,    13,    11,    68,    69,
      70,    71,   328,    12,    74,   356,    20,   100,   804,    14,
      68,    69,    70,    71,   342,    12,    74,    67,     4,   112,
      10,   114,    39,     9,    40,    39,   119,   120,    10,    12,
      16,     9,    41,    11,    39,    42,    42,    15,    16,    17,
      18,    19,    20,    29,    41,    68,    69,    70,    71,    67,
      67,    74,    30,    31,     8,     9,     0,    74,    41,     3,
      11,    39,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,    42,   179,   180,   181,   182,
     183,   184,   185,     9,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    13,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       9,    97,    11,    11,    61,    13,    21,   250,    17,    18,
      19,    20,     9,     9,   100,    11,     0,    32,    33,     3,
       4,     5,     6,     7,     8,     9,   112,    11,     3,    10,
      39,    39,    16,   119,     4,     5,     4,     5,    13,     9,
      24,     9,    11,    32,    33,    29,    16,    12,    16,     3,
       4,     5,     6,     7,     8,     9,    25,    11,    12,    29,
      12,    29,    16,    32,    33,    34,    35,    36,    37,   155,
      24,    11,    56,    57,    58,    29,    60,    61,    62,    63,
      64,    65,    66,    41,    68,    69,    70,    71,    72,    73,
      74,    75,    41,   179,    34,    35,    36,    37,    21,   342,
      13,    38,    25,    40,    74,    75,     9,   636,    11,    32,
      33,    25,    15,    16,    17,    18,    19,    20,    32,    33,
      74,    75,     3,     4,     5,     6,     7,     8,     9,    22,
      11,    74,    25,    32,    33,    16,    39,    14,    25,    32,
      33,    10,   228,    24,    11,    32,    33,     9,    29,    10,
     246,     4,     5,     6,     7,     8,     9,    11,    11,    12,
      17,    18,    19,    16,   250,    32,    33,    34,    35,    36,
      37,    24,     0,    20,    10,    11,    29,    20,    11,    25,
       8,     9,    10,    11,    10,    21,    32,    33,    41,    25,
      12,    19,    22,    74,    75,    20,    32,    33,    34,    35,
      36,    37,    32,    33,    32,     4,     5,     6,     7,     8,
       9,    12,    11,    12,    42,     8,    74,    16,    22,    23,
      14,    74,    75,     3,    40,    24,     3,    11,    32,    33,
      29,    15,    16,    17,    42,     4,     5,     6,     7,     8,
       9,    25,    41,    10,   340,   341,    74,    16,    32,    33,
      36,    79,    80,    10,    10,    24,   342,    85,    10,    10,
      29,    47,    48,    49,    50,   743,   744,   745,    10,   770,
      21,    22,    23,   749,    25,    74,    75,    10,    10,    21,
      14,    32,    33,    25,   762,    12,     3,   765,   764,    42,
      32,    33,    34,    35,    36,    37,   124,    68,    69,    70,
      71,    11,   130,    74,   132,    15,    16,    17,   136,    10,
      59,   789,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   789,   154,    42,   156,   157,
     158,   159,   160,   161,   162,    42,   814,    10,   816,    10,
      12,    40,    12,   171,   172,   173,   174,   175,   176,    38,
      21,    22,    23,    12,    39,   833,   834,    62,   322,   187,
     637,    32,    33,   191,   809,   140,    97,   195,   196,   197,
     198,   199,   200,   201,    74,   882,   854,   780,    -1,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,    11,   222,   223,   224,   225,   226,   227,
      -1,   229,    -1,    21,    -1,    -1,   884,    25,    -1,   237,
      -1,    -1,    -1,     0,    32,    33,    34,    35,    36,    37,
      -1,     8,     9,    -1,    11,    -1,    15,    16,    17,    18,
      19,    20,    19,   261,    -1,    -1,   264,   265,   266,   267,
     268,    30,    31,    -1,    -1,    32,   274,   275,   276,   277,
     278,   279,    -1,    -1,    -1,    42,   284,    -1,    -1,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,    11,    74,    -1,    -1,
      15,    16,    17,   321,    17,    18,    19,    20,    85,   327,
     743,   744,   745,    68,    69,    70,    71,    32,    33,    74,
      75,     4,     5,     6,     7,     8,     9,    -1,    11,   762,
      -1,    -1,   765,    16,    -1,    -1,   354,    -1,   356,    -1,
     769,    24,    -1,    -1,   773,    -1,    29,   124,    -1,    -1,
      -1,   637,    -1,   130,    -1,   132,   789,    -1,    41,   136,
      -1,    -1,    -1,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,   154,    -1,    -1,
      -1,   814,    -1,   816,    -1,   162,    -1,    -1,   165,    -1,
      -1,    74,    75,    -1,   171,   172,   173,   174,   175,   176,
     833,   834,   831,   832,    -1,    -1,   835,   836,   837,   838,
     187,   757,   832,    -1,   191,   835,   836,   837,   838,    -1,
      -1,   854,    -1,   769,   201,    -1,    -1,   773,    -1,    -1,
      -1,   860,    -1,    -1,    21,    -1,    -1,   783,    25,    17,
      18,    19,    20,   220,    -1,    32,    33,    34,    35,    36,
      37,   884,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   807,    -1,    -1,   750,   751,    15,    16,    17,    18,
      19,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      -1,   827,    -1,    16,   261,    -1,   762,    -1,    -1,   765,
      -1,    24,    -1,    -1,   780,    10,    29,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    -1,   284,    41,    -1,
     287,    26,    27,    28,   860,    30,    31,   294,   804,    -1,
      -1,    -1,   808,   809,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,    -1,   814,    -1,
     816,    74,    75,     0,   321,    15,    16,    17,    18,    19,
     327,     8,     9,    -1,    11,    -1,    26,   833,   834,    -1,
      30,    31,    19,    -1,    -1,    15,    16,    17,    18,    19,
      20,    17,    18,    19,    20,    32,    -1,   354,   854,   356,
      30,    31,    -1,    -1,     1,    42,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    -1,    14,    -1,    16,
      -1,     4,     5,     6,     7,     8,     9,    24,   884,    -1,
      -1,    -1,    29,    16,    -1,    -1,    -1,    74,   636,    -1,
      -1,    24,    -1,    25,    -1,   643,    29,    -1,    85,    -1,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    56,
      57,    58,    -1,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    15,    16,    17,    18,    19,    -1,   124,    17,    18,
      19,    20,    26,   130,    28,   132,    30,    31,    -1,   136,
      -1,    -1,    -1,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,   154,    34,    35,
      36,    37,    -1,    10,    -1,   162,   163,   164,    15,    16,
      17,    18,    19,    20,   171,   172,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,   743,   744,   745,    16,    -1,
     187,    -1,    -1,    -1,   191,    -1,    24,    -1,    -1,    -1,
      -1,    29,    -1,    -1,   201,    15,    16,    17,    18,    19,
      20,   769,   770,    -1,   772,   773,    -1,   775,    -1,    -1,
      30,    31,    -1,   220,    34,    35,    36,    37,    -1,    -1,
      -1,   789,   229,    15,    16,    17,    18,    19,    -1,    -1,
     237,   238,   239,    -1,   241,   242,    74,    75,    30,    31,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
     818,    -1,    16,    -1,   261,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,   831,   832,    29,    -1,   835,   836,   837,
     838,    -1,   840,    -1,   842,    -1,    -1,   284,    -1,   847,
     287,    15,    16,    17,    18,    19,    20,   294,    -1,    -1,
      -1,    -1,   860,    -1,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,    -1,    -1,   636,
      74,    75,    -1,    -1,   321,    -1,   643,    -1,    -1,    -1,
     327,    15,    16,    17,    18,    19,    20,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
      -1,    14,    -1,    16,    -1,    -1,    -1,   354,    -1,   356,
      -1,    24,    -1,    -1,    -1,    -1,    29,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    13,    -1,    -1,    16,
      15,    16,    17,    18,    19,    20,    -1,    24,    -1,    -1,
      -1,    -1,    29,    56,    57,    58,    -1,    60,    61,    62,
      63,    64,    65,    66,     0,    68,    69,    70,    71,    72,
      73,    74,    75,     9,    -1,    11,    32,    33,    34,    35,
      36,    37,    -1,    19,    -1,    -1,   743,   744,   745,    15,
      16,    17,    18,    19,    20,    -1,    32,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    34,    35,
      36,    37,   769,   770,    -1,   772,   773,    -1,   775,    -1,
      -1,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      -1,    -1,   789,    16,    -1,    -1,    -1,    -1,    74,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    29,    -1,    -1,    85,
      -1,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      -1,   818,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,   831,   832,    29,    -1,   835,   836,
     837,   838,    -1,   840,    -1,   842,    -1,    -1,   124,    -1,
     847,    74,    75,    -1,   130,    -1,   132,    -1,    -1,    -1,
     136,    -1,    -1,   860,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,    -1,   154,    -1,
      -1,    74,    75,    -1,    -1,    -1,   162,     4,     5,     6,
       7,     8,     9,    -1,    11,   171,   172,    -1,    -1,    16,
      -1,    -1,    -1,    29,    30,    -1,    -1,    24,    -1,    -1,
      -1,   187,    29,   189,   190,   191,    -1,    15,    16,    17,
      18,    19,    20,    -1,    -1,   201,    -1,    53,    26,    27,
      28,    -1,    30,    31,    -1,    -1,    -1,    -1,    64,    -1,
      -1,    67,    -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,   229,    -1,    -1,    -1,    74,    75,   636,
      -1,   237,    -1,    -1,    -1,    -1,   643,    -1,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    -1,   261,    -1,    -1,    24,    -1,
       9,    -1,    -1,    29,     4,     5,     6,     7,     8,     9,
      19,    11,    12,    -1,    -1,    -1,    16,    -1,   284,   285,
     286,   287,    -1,    -1,    24,    -1,    -1,    -1,   294,    29,
      -1,    -1,    -1,    -1,    -1,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,    74,    75,
      -1,    10,    -1,    -1,     0,   321,    15,    16,    17,    18,
      19,   327,    -1,     9,    -1,    74,    -1,    26,    27,    28,
      -1,    30,    31,    19,    74,    75,   743,   744,   745,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,   354,    -1,
     356,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,   769,   770,    -1,   772,   773,    -1,   775,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   789,    -1,    -1,    -1,    -1,   136,    74,    -1,
      -1,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,   154,    -1,    -1,    -1,    -1,
      -1,   818,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   831,   832,    -1,    -1,   835,   836,
     837,   838,    -1,   840,    -1,   842,    -1,    -1,   124,    -1,
     847,    -1,    -1,    -1,   130,    -1,   132,    -1,    -1,    -1,
     136,    -1,    -1,   860,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,    -1,   154,    -1,
     156,   157,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,   183,   184,   185,
      -1,    -1,   188,    -1,    -1,    -1,   192,    -1,    -1,    -1,
      -1,    -1,   261,    -1,    -1,    -1,   202,    -1,    -1,    -1,
      -1,    -1,   378,    -1,    -1,    -1,   382,    -1,    -1,    -1,
     386,    -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,     0,
      -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,     9,    -1,
      -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    19,    -1,
      -1,    -1,    -1,    -1,    -1,   421,    -1,    -1,    -1,    -1,
      -1,    32,   321,   429,    -1,   261,    -1,    -1,   327,    -1,
      -1,    42,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    -1,    13,    -1,    -1,    16,   455,
      -1,   457,    -1,   459,    -1,   461,    24,   463,    -1,   465,
      -1,    29,    -1,    74,    -1,    -1,    -1,    -1,   474,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     636,   487,    -1,    -1,    -1,   321,    -1,   643,    56,    57,
      58,   327,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    -1,    -1,
      -1,   517,    -1,   124,    -1,    -1,    -1,    -1,   354,   130,
     356,   132,    -1,    -1,    -1,   136,    -1,    -1,    -1,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   162,     4,     5,     6,     7,     8,     9,    -1,    11,
     171,   172,    -1,    -1,    16,    -1,   572,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,   187,    29,    -1,    -1,
     191,    -1,   193,   194,    -1,    -1,    -1,   743,   744,   745,
     201,    -1,     0,    -1,   600,     3,    -1,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,   220,
      54,    55,    -1,   769,   770,    -1,   772,   773,   229,   775,
     626,    -1,    74,    75,    -1,    -1,   237,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    -1,    -1,
     261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   818,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    -1,    -1,   831,   832,    16,    -1,   835,
     836,   837,   838,    -1,   840,    24,   842,    -1,    -1,    -1,
      29,   847,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    -1,   860,    14,    -1,    16,    -1,    -1,
     321,    -1,    -1,    -1,    -1,    24,   327,    56,    57,    58,
      29,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,   636,    -1,    -1,
      -1,    -1,    -1,   354,   643,   356,    -1,    56,    57,    58,
      -1,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    -1,    -1,    -1,    16,
      -1,     4,     5,     6,     7,     8,     9,    24,    11,    -1,
      -1,    -1,    29,    16,    -1,    -1,    -1,    -1,    -1,    -1,
     636,    24,     9,    10,    11,    -1,    29,   643,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    -1,    -1,    -1,    -1,    74,    75,    -1,
      -1,    -1,    -1,    -1,   743,   744,   745,    -1,    -1,    -1,
      -1,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     9,   772,    11,    -1,   775,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    -1,    -1,    10,    -1,   743,   744,   745,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,   818,
      25,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,   769,   770,    -1,   772,   773,    -1,   775,
      -1,   840,    -1,   842,     9,    10,    11,    -1,   847,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      25,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   818,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   831,   832,    -1,    -1,   835,
     836,   837,   838,    -1,   840,    -1,   842,    -1,    -1,    -1,
      -1,   847,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    -1,    11,    -1,   860,   636,    15,    16,    17,    18,
      19,    20,   643,    22,    23,    -1,    25,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,     9,
      39,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,    22,    -1,    -1,    25,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,     9,    39,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    25,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      -1,    -1,   743,   744,   745,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   769,   770,
      -1,   772,   773,     9,   775,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    10,    39,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,   818,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
     831,   832,    -1,    -1,   835,   836,   837,   838,    -1,   840,
      -1,   842,    -1,     9,    -1,    11,   847,    -1,    -1,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,   860,
      26,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,     9,    39,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,     9,    39,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    34,    35,    36,    37,
      10,    39,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    25,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    10,    -1,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    37,    10,    -1,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    25,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      25,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    25,    15,    16,    17,    18,    19,    20,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    25,
      15,    16,    17,    18,    19,    20,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    37
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
      13,     3,    14,    56,   100,   101,   130,    10,   104,   105,
     130,    12,    41,   116,    12,    41,    74,    14,    12,    10,
      79,    14,     9,    10,    10,    40,    12,    12,    12,    10,
      40,   110,   120,    10,   104,    12,    12,   110,     8,     9,
     110,   111,   115,   116,   122,   110,   115,   110,   115,   129,
     100,   100,    74,    14,     3,    74,    83,    10,    40,    40,
      74,    12,   116,    12,    41,    12,    41,   116,    42,    85,
      14,     3,   110,    85,   110,   127,    83,    10,   111,   115,
     122,    10,    10,    38,    40,    10,    10,    10,    10,    14,
      42,   100,    42,    83,   130,   105,   130,    42,    12,    12,
     116,    12,   116,    12,    41,   110,     3,    10,    59,    96,
      98,    83,    10,    82,    83,    84,    84,   116,   116,    84,
      84,    84,    84,   110,   110,    74,    74,   110,    12,    12,
      12,   116,    40,    85,    38,    12,   121,   116
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
     104,   104,   104,   105,   105,   106,   107,   107,   107,   107,
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
       2,     1,     4,     4,     3,     2,     4,     4,     4,     4,
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
  "struct", "decllist", "declistval", "function", "fun_id", "funargs",
  "funargdef", "vardecl", "vardef", "set", "callarglist", "expr",
  "expr_var", "matrix", "matvals", "expr_mat", "range", "int_val", "slice",
  "expr_none", "expr_struct", "struct_val", "struct_list", "expr_int",
  "expr_float", "expr_str", "expr_bool", "funtype", "typelist", "mattype",
  "matsq", "type", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   227,   227,   228,   230,   231,   232,   235,   236,   239,
     240,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   257,   258,   259,   260,   261,   264,   265,
     268,   269,   273,   275,   276,   280,   281,   282,   284,   285,
     289,   290,   291,   292,   293,   294,   298,   300,   302,   304,
     307,   309,   310,   312,   313,   316,   317,   318,   320,   321,
     322,   323,   325,   326,   327,   331,   332,   333,   334,   336,
     338,   339,   340,   342,   343,   347,   351,   352,   353,   354,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   375,   376,   380,   381,   382,   383,
     384,   385,   386,   387,   390,   391,   392,   393,   394,   396,
     397,   399,   400,   401,   402,   403,   405,   406,   407,   408,
     410,   411,   412,   414,   415,   416,   418,   419,   420,   421,
     422,   423,   424,   425,   427,   428,   429,   430,   431,   433,
     434,   435,   436,   437,   439,   440,   441,   442,   443,   444,
     445,   446,   448,   449,   450,   451,   452,   453,   454,   455,
     457,   458,   459,   461,   462,   463,   465,   466,   467,   468,
     469,   470,   471,   473,   474,   475,   476,   477,   478,   479,
     481,   482,   483,   484,   485,   486,   487,   489,   490,   491,
     492,   493,   494,   495,   497,   498,   499,   500,   501,   502,
     503,   504,   505,   506,   507,   508,   509,   510,   511,   512,
     513,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   533,   534,
     535,   537,   538,   539,   541,   542,   543,   545,   546,   547,
     548,   549,   550,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   562,   563,   564,   566,   567,   568,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   597,   598,   599,   600,   601,   604,   605,
     606,   610,   611,   613,   614,   615,   617,   618,   620,   621,
     622,   623,   624,   625,   626,   627,   628,   629,   630,   631,
     635,   636,   640,   641,   643,   644,   646,   647,   651,   652,
     653,   654,   655,   656,   657,   658,   659,   660,   661,   662,
     663,   664,   668,   669,   670,   671,   672,   673,   674,   675,
     676,   677,   678,   679,   680,   681,   682,   683,   684,   685,
     686,   687,   688,   692,   693,   694,   695,   696,   697,   698,
     699,   700,   701,   702,   703,   704,   705,   706,   707,   708,
     709,   710,   711,   712,   713,   714,   715,   716,   717,   718,
     722,   723,   724,   725,   726,   728,   729,   730,   731,   732,
     733,   734,   736,   737,   738,   739,   740,   741,   742,   744,
     745,   746,   747,   748,   750,   751,   752,   753,   754,   756,
     757,   758,   759,   760,   762,   763,   764,   765,   766,   768,
     772,   773,   775,   776,   780,   781,   782,   783,   784,   785,
     786,   787,   788,   789,   790,   791,   793,   794,   795,   796,
     800,   801,   802,   803,   804,   805,   806,   807,   808,   809,
     810,   811,   812,   813
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
#line 4904 "frontend/parser.cpp"

#line 816 "frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    auto msg = std::to_string(scanner->loc->begin.line) + ":" + std::to_string(scanner->loc->begin.column) + ": " + err_message;
    scanner->fatal_error(ptc::diag::ERR_SYNTAX, msg);
}
