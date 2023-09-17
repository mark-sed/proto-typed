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
#line 229 "frontend/parser.yy"
                        { scanner->parseEntry(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1175 "frontend/parser.cpp"
    break;

  case 4: // stmt: stmts
#line 231 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1181 "frontend/parser.cpp"
    break;

  case 5: // stmt: stmt stmts
#line 232 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1187 "frontend/parser.cpp"
    break;

  case 6: // stmt: stmt error stmts
#line 233 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1193 "frontend/parser.cpp"
    break;

  case 9: // stmts: "terminator (\\n or ;)"
#line 240 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = nullptr; }
#line 1199 "frontend/parser.cpp"
    break;

  case 10: // stmts: stmts_ne
#line 241 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1205 "frontend/parser.cpp"
    break;

  case 11: // stmts_ne: set stmt_end
#line 243 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1211 "frontend/parser.cpp"
    break;

  case 12: // stmts_ne: vardecl stmt_end
#line 244 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1217 "frontend/parser.cpp"
    break;

  case 13: // stmts_ne: vardef stmt_end
#line 245 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1223 "frontend/parser.cpp"
    break;

  case 14: // stmts_ne: import stmt_end
#line 246 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1229 "frontend/parser.cpp"
    break;

  case 15: // stmts_ne: for
#line 247 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1235 "frontend/parser.cpp"
    break;

  case 16: // stmts_ne: if
#line 248 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1241 "frontend/parser.cpp"
    break;

  case 17: // stmts_ne: while
#line 249 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1247 "frontend/parser.cpp"
    break;

  case 18: // stmts_ne: dowhile
#line 250 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1253 "frontend/parser.cpp"
    break;

  case 19: // stmts_ne: struct
#line 251 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1259 "frontend/parser.cpp"
    break;

  case 20: // stmts_ne: function
#line 252 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1265 "frontend/parser.cpp"
    break;

  case 21: // stmts_ne: flowctl stmt_end
#line 253 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1271 "frontend/parser.cpp"
    break;

  case 22: // stmts_ne: expr stmt_end
#line 254 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1277 "frontend/parser.cpp"
    break;

  case 23: // block: "{" "}"
#line 258 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1283 "frontend/parser.cpp"
    break;

  case 24: // block: "{" stmt "}"
#line 259 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1289 "frontend/parser.cpp"
    break;

  case 25: // block: "terminator (\\n or ;)" "{" stmt "}"
#line 260 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1295 "frontend/parser.cpp"
    break;

  case 26: // block: "{" stmt "}" "terminator (\\n or ;)"
#line 261 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1301 "frontend/parser.cpp"
    break;

  case 27: // block: "terminator (\\n or ;)" "{" stmt "}" "terminator (\\n or ;)"
#line 262 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1307 "frontend/parser.cpp"
    break;

  case 28: // body: stmts_ne
#line 265 "frontend/parser.yy"
                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1313 "frontend/parser.cpp"
    break;

  case 29: // body: block
#line 266 "frontend/parser.yy"
                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1319 "frontend/parser.cpp"
    break;

  case 30: // scope_body: stmts_ne
#line 269 "frontend/parser.yy"
                      { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); scanner->leaveScope(); }
#line 1325 "frontend/parser.cpp"
    break;

  case 31: // scope_body: block
#line 270 "frontend/parser.yy"
                      { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); scanner->leaveScope(); }
#line 1331 "frontend/parser.cpp"
    break;

  case 32: // import: "import" id_list
#line 274 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::IR * > () = scanner->parseImports(yystack_[0].value.as < std::vector<std::string>  > ()); }
#line 1337 "frontend/parser.cpp"
    break;

  case 33: // id_list: "identifier"
#line 276 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseImportName(yystack_[0].value.as < std::string > ()); }
#line 1343 "frontend/parser.cpp"
    break;

  case 34: // id_list: "identifier" "," id_list
#line 277 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseAddImportName(yystack_[0].value.as < std::vector<std::string>  > (), yystack_[2].value.as < std::string > ()); }
#line 1349 "frontend/parser.cpp"
    break;

  case 35: // flowctl: "break"
#line 281 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseBreak(); }
#line 1355 "frontend/parser.cpp"
    break;

  case 36: // flowctl: "continue"
#line 282 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseContinue(); }
#line 1361 "frontend/parser.cpp"
    break;

  case 37: // flowctl: return
#line 283 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1367 "frontend/parser.cpp"
    break;

  case 38: // return: "return"
#line 285 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(nullptr); }
#line 1373 "frontend/parser.cpp"
    break;

  case 39: // return: "return" expr
#line 286 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1379 "frontend/parser.cpp"
    break;

  case 40: // for: "for" "(" vardecl ":" expr ")" body
#line 290 "frontend/parser.yy"
                                              { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1385 "frontend/parser.cpp"
    break;

  case 41: // for: "for" "(" "identifier" ":" expr ")" body
#line 291 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1391 "frontend/parser.cpp"
    break;

  case 42: // for: "for" "(" "external identifier" ":" expr ")" body
#line 292 "frontend/parser.yy"
                                              { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1397 "frontend/parser.cpp"
    break;

  case 43: // for: "for" "(" vardecl ":" range ")" body
#line 293 "frontend/parser.yy"
                                               { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1403 "frontend/parser.cpp"
    break;

  case 44: // for: "for" "(" "identifier" ":" range ")" body
#line 294 "frontend/parser.yy"
                                           { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1409 "frontend/parser.cpp"
    break;

  case 45: // for: "for" "(" "external identifier" ":" range ")" body
#line 295 "frontend/parser.yy"
                                               { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1415 "frontend/parser.cpp"
    break;

  case 46: // while: wh_kw "(" expr ")" scope_body
#line 299 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseWhile(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1421 "frontend/parser.cpp"
    break;

  case 47: // wh_kw: "while"
#line 301 "frontend/parser.yy"
                { scanner->enterBlockScope(); }
#line 1427 "frontend/parser.cpp"
    break;

  case 48: // dowhile: do_kw scope_body "while" "(" expr ")"
#line 303 "frontend/parser.yy"
                                                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseDoWhile(yystack_[1].value.as < ptc::ir::Expr * > (), yystack_[4].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1433 "frontend/parser.cpp"
    break;

  case 49: // do_kw: "do"
#line 305 "frontend/parser.yy"
             { scanner->enterBlockScope(); }
#line 1439 "frontend/parser.cpp"
    break;

  case 50: // if: if_kw "(" expr ")" scope_body else
#line 308 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseIfStmt(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1445 "frontend/parser.cpp"
    break;

  case 51: // else: el_kw scope_body
#line 310 "frontend/parser.yy"
                         { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1451 "frontend/parser.cpp"
    break;

  case 52: // else: %empty
#line 311 "frontend/parser.yy"
                    { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1457 "frontend/parser.cpp"
    break;

  case 53: // if_kw: "if"
#line 313 "frontend/parser.yy"
             { scanner->enterBlockScope(); }
#line 1463 "frontend/parser.cpp"
    break;

  case 54: // el_kw: "else"
#line 314 "frontend/parser.yy"
               { scanner->enterBlockScope(); }
#line 1469 "frontend/parser.cpp"
    break;

  case 55: // struct: "'struct'" "identifier" "{" "}"
#line 317 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[2].value.as < std::string > (), std::vector<ptc::ir::IR *>{}); }
#line 1475 "frontend/parser.cpp"
    break;

  case 56: // struct: "'struct'" "identifier" "{" decllist "}"
#line 318 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1481 "frontend/parser.cpp"
    break;

  case 57: // struct: "'struct'" "identifier" "terminator (\\n or ;)" "{" decllist "}"
#line 319 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[4].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1487 "frontend/parser.cpp"
    break;

  case 59: // decllist: "terminator (\\n or ;)" decllist
#line 322 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1493 "frontend/parser.cpp"
    break;

  case 60: // decllist: declistval "terminator (\\n or ;)"
#line 323 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[1].value.as < ptc::ir::IR * > (), std::vector<ptc::ir::IR *>{}); }
#line 1499 "frontend/parser.cpp"
    break;

  case 61: // decllist: declistval "terminator (\\n or ;)" decllist
#line 324 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[2].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1505 "frontend/parser.cpp"
    break;

  case 62: // declistval: type "identifier"
#line 326 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > (), nullptr); }
#line 1511 "frontend/parser.cpp"
    break;

  case 63: // declistval: type "identifier" "=" expr
#line 327 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1517 "frontend/parser.cpp"
    break;

  case 65: // function: type fun_id "(" ")" block
#line 332 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1523 "frontend/parser.cpp"
    break;

  case 66: // function: type fun_id "(" funargs ")" block
#line 333 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[5].value.as < ptc::ir::IR * > (), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1529 "frontend/parser.cpp"
    break;

  case 67: // function: "'void'" fun_id "(" ")" block
#line 334 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1535 "frontend/parser.cpp"
    break;

  case 68: // function: "'void'" fun_id "(" funargs ")" block
#line 335 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1541 "frontend/parser.cpp"
    break;

  case 69: // fun_id: "identifier"
#line 337 "frontend/parser.yy"
            { scanner->enterFunScope(); yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1547 "frontend/parser.cpp"
    break;

  case 70: // funargs: type "identifier"
#line 339 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseFunParam(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1553 "frontend/parser.cpp"
    break;

  case 71: // funargs: funargs "," type "identifier"
#line 341 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseAddFunParam(yystack_[3].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1559 "frontend/parser.cpp"
    break;

  case 72: // vardecl: type "identifier"
#line 348 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1565 "frontend/parser.cpp"
    break;

  case 73: // vardef: type "identifier" "=" struct_val
#line 352 "frontend/parser.yy"
         { yylhs.value.as < ptc::ir::IR * > () = yystack_[3].value.as < ptc::ir::IR * > (); }
#line 1571 "frontend/parser.cpp"
    break;

  case 74: // vardef: type "identifier" "=" expr
#line 353 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1577 "frontend/parser.cpp"
    break;

  case 77: // set: expr "++=" expr
#line 359 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1583 "frontend/parser.cpp"
    break;

  case 78: // set: expr "**=" expr
#line 360 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1589 "frontend/parser.cpp"
    break;

  case 79: // set: expr "%=" expr
#line 361 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1595 "frontend/parser.cpp"
    break;

  case 80: // set: expr "/=" expr
#line 362 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1601 "frontend/parser.cpp"
    break;

  case 81: // set: expr "*=" expr
#line 363 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1607 "frontend/parser.cpp"
    break;

  case 82: // set: expr "-=" expr
#line 364 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1613 "frontend/parser.cpp"
    break;

  case 83: // set: expr "+=" expr
#line 365 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1619 "frontend/parser.cpp"
    break;

  case 84: // set: expr "&=" expr
#line 366 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1625 "frontend/parser.cpp"
    break;

  case 85: // set: expr "|=" expr
#line 367 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1631 "frontend/parser.cpp"
    break;

  case 86: // set: expr "^=" expr
#line 368 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1637 "frontend/parser.cpp"
    break;

  case 87: // set: expr "<<=" expr
#line 369 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1643 "frontend/parser.cpp"
    break;

  case 88: // set: expr ">>=" expr
#line 370 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1649 "frontend/parser.cpp"
    break;

  case 89: // set: expr "=" expr
#line 371 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1655 "frontend/parser.cpp"
    break;

  case 90: // set: expr "=" set
#line 372 "frontend/parser.yy"
      { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1661 "frontend/parser.cpp"
    break;

  case 91: // callarglist: expr
#line 376 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseFunCallArg(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1667 "frontend/parser.cpp"
    break;

  case 92: // callarglist: callarglist "," expr
#line 377 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddFunCallArg(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1673 "frontend/parser.cpp"
    break;

  case 93: // expr: expr_mat
#line 381 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1679 "frontend/parser.cpp"
    break;

  case 94: // expr: expr_var
#line 382 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1685 "frontend/parser.cpp"
    break;

  case 95: // expr: expr_none
#line 383 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1691 "frontend/parser.cpp"
    break;

  case 97: // expr: expr_int
#line 385 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 1697 "frontend/parser.cpp"
    break;

  case 98: // expr: expr_float
#line 386 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFloat(yystack_[0].value.as < double > ()); }
#line 1703 "frontend/parser.cpp"
    break;

  case 99: // expr: expr_str
#line 387 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseString(yystack_[0].value.as < std::string > ()); }
#line 1709 "frontend/parser.cpp"
    break;

  case 100: // expr: expr_bool
#line 388 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseBool(yystack_[0].value.as < bool > ()); }
#line 1715 "frontend/parser.cpp"
    break;

  case 101: // expr_var: "identifier"
#line 391 "frontend/parser.yy"
              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > ()); }
#line 1721 "frontend/parser.cpp"
    break;

  case 102: // expr_var: "external identifier"
#line 392 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > (), true); }
#line 1727 "frontend/parser.cpp"
    break;

  case 103: // expr_var: "-" "identifier"
#line 393 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1733 "frontend/parser.cpp"
    break;

  case 104: // expr_var: "-" "external identifier"
#line 394 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > (), true), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1739 "frontend/parser.cpp"
    break;

  case 105: // expr_var: "(" expr_var ")"
#line 395 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1745 "frontend/parser.cpp"
    break;

  case 106: // expr_var: expr_var "(" ")"
#line 397 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[2].value.as < ptc::ir::Expr * > (), std::vector<ptc::ir::Expr *>{}); }
#line 1751 "frontend/parser.cpp"
    break;

  case 107: // expr_var: expr_var "(" callarglist ")"
#line 398 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 1757 "frontend/parser.cpp"
    break;

  case 108: // expr_var: expr_str "[" int_val "]"
#line 400 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1763 "frontend/parser.cpp"
    break;

  case 109: // expr_var: expr_mat "[" int_val "]"
#line 401 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1769 "frontend/parser.cpp"
    break;

  case 110: // expr_var: "identifier" "[" int_val "]"
#line 402 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1775 "frontend/parser.cpp"
    break;

  case 111: // expr_var: "external identifier" "[" int_val "]"
#line 403 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1781 "frontend/parser.cpp"
    break;

  case 112: // expr_var: expr_var "[" int_val "]"
#line 404 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1787 "frontend/parser.cpp"
    break;

  case 113: // expr_var: expr_mat slice
#line 406 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1793 "frontend/parser.cpp"
    break;

  case 116: // expr_var: expr_var slice
#line 409 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1799 "frontend/parser.cpp"
    break;

  case 117: // expr_var: "identifier" "." expr_var
#line 411 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1805 "frontend/parser.cpp"
    break;

  case 118: // expr_var: "external identifier" "." expr_var
#line 412 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1811 "frontend/parser.cpp"
    break;

  case 119: // expr_var: expr_var "." expr_var
#line 413 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1817 "frontend/parser.cpp"
    break;

  case 121: // expr_var: expr_var "**" expr_float
#line 416 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1823 "frontend/parser.cpp"
    break;

  case 122: // expr_var: expr_var "**" expr_var
#line 417 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1829 "frontend/parser.cpp"
    break;

  case 123: // expr_var: expr_int "*" expr_var
#line 419 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1835 "frontend/parser.cpp"
    break;

  case 124: // expr_var: expr_float "*" expr_var
#line 420 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1841 "frontend/parser.cpp"
    break;

  case 125: // expr_var: expr_var "*" expr_int
#line 421 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1847 "frontend/parser.cpp"
    break;

  case 126: // expr_var: expr_var "*" expr_float
#line 422 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1853 "frontend/parser.cpp"
    break;

  case 127: // expr_var: expr_mat "*" expr_mat
#line 423 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1859 "frontend/parser.cpp"
    break;

  case 128: // expr_var: expr_mat "*" expr_var
#line 424 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1865 "frontend/parser.cpp"
    break;

  case 129: // expr_var: expr_var "*" expr_mat
#line 425 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1871 "frontend/parser.cpp"
    break;

  case 130: // expr_var: expr_var "*" expr_var
#line 426 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1877 "frontend/parser.cpp"
    break;

  case 131: // expr_var: expr_int "/" expr_var
#line 428 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1883 "frontend/parser.cpp"
    break;

  case 132: // expr_var: expr_float "/" expr_var
#line 429 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1889 "frontend/parser.cpp"
    break;

  case 133: // expr_var: expr_var "/" expr_int
#line 430 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1895 "frontend/parser.cpp"
    break;

  case 134: // expr_var: expr_var "/" expr_float
#line 431 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1901 "frontend/parser.cpp"
    break;

  case 135: // expr_var: expr_var "/" expr_var
#line 432 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1907 "frontend/parser.cpp"
    break;

  case 136: // expr_var: expr_int "%" expr_var
#line 434 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1913 "frontend/parser.cpp"
    break;

  case 137: // expr_var: expr_float "%" expr_var
#line 435 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1919 "frontend/parser.cpp"
    break;

  case 138: // expr_var: expr_var "%" expr_int
#line 436 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1925 "frontend/parser.cpp"
    break;

  case 139: // expr_var: expr_var "%" expr_float
#line 437 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1931 "frontend/parser.cpp"
    break;

  case 140: // expr_var: expr_var "%" expr_var
#line 438 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1937 "frontend/parser.cpp"
    break;

  case 141: // expr_var: expr_int "+" expr_var
#line 440 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1943 "frontend/parser.cpp"
    break;

  case 142: // expr_var: expr_float "+" expr_var
#line 441 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1949 "frontend/parser.cpp"
    break;

  case 143: // expr_var: expr_var "+" expr_int
#line 442 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1955 "frontend/parser.cpp"
    break;

  case 144: // expr_var: expr_var "+" expr_float
#line 443 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1961 "frontend/parser.cpp"
    break;

  case 145: // expr_var: expr_mat "+" expr_mat
#line 444 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1967 "frontend/parser.cpp"
    break;

  case 146: // expr_var: expr_var "+" expr_mat
#line 445 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1973 "frontend/parser.cpp"
    break;

  case 147: // expr_var: expr_mat "+" expr_var
#line 446 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1979 "frontend/parser.cpp"
    break;

  case 148: // expr_var: expr_var "+" expr_var
#line 447 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1985 "frontend/parser.cpp"
    break;

  case 149: // expr_var: expr_int "-" expr_var
#line 449 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1991 "frontend/parser.cpp"
    break;

  case 150: // expr_var: expr_float "-" expr_var
#line 450 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1997 "frontend/parser.cpp"
    break;

  case 151: // expr_var: expr_var "-" expr_int
#line 451 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2003 "frontend/parser.cpp"
    break;

  case 152: // expr_var: expr_var "-" expr_float
#line 452 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2009 "frontend/parser.cpp"
    break;

  case 153: // expr_var: expr_mat "-" expr_mat
#line 453 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2015 "frontend/parser.cpp"
    break;

  case 154: // expr_var: expr_var "-" expr_mat
#line 454 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2021 "frontend/parser.cpp"
    break;

  case 155: // expr_var: expr_mat "-" expr_var
#line 455 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2027 "frontend/parser.cpp"
    break;

  case 156: // expr_var: expr_var "-" expr_var
#line 456 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2033 "frontend/parser.cpp"
    break;

  case 157: // expr_var: expr_int "<<" expr_var
#line 458 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2039 "frontend/parser.cpp"
    break;

  case 158: // expr_var: expr_var "<<" expr_int
#line 459 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2045 "frontend/parser.cpp"
    break;

  case 159: // expr_var: expr_var "<<" expr_var
#line 460 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2051 "frontend/parser.cpp"
    break;

  case 160: // expr_var: expr_int ">>" expr_var
#line 462 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2057 "frontend/parser.cpp"
    break;

  case 161: // expr_var: expr_var ">>" expr_int
#line 463 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2063 "frontend/parser.cpp"
    break;

  case 162: // expr_var: expr_var ">>" expr_var
#line 464 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2069 "frontend/parser.cpp"
    break;

  case 163: // expr_var: expr_int ">" expr_var
#line 466 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2075 "frontend/parser.cpp"
    break;

  case 164: // expr_var: expr_float ">" expr_var
#line 467 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2081 "frontend/parser.cpp"
    break;

  case 166: // expr_var: expr_var ">" expr_int
#line 469 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2087 "frontend/parser.cpp"
    break;

  case 167: // expr_var: expr_var ">" expr_float
#line 470 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2093 "frontend/parser.cpp"
    break;

  case 168: // expr_var: expr_var ">" expr_str
#line 471 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2099 "frontend/parser.cpp"
    break;

  case 169: // expr_var: expr_var ">" expr_var
#line 472 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2105 "frontend/parser.cpp"
    break;

  case 170: // expr_var: expr_int ">=" expr_var
#line 474 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2111 "frontend/parser.cpp"
    break;

  case 171: // expr_var: expr_float ">=" expr_var
#line 475 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2117 "frontend/parser.cpp"
    break;

  case 173: // expr_var: expr_var ">=" expr_int
#line 477 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2123 "frontend/parser.cpp"
    break;

  case 174: // expr_var: expr_var ">=" expr_float
#line 478 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2129 "frontend/parser.cpp"
    break;

  case 175: // expr_var: expr_var ">=" expr_str
#line 479 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2135 "frontend/parser.cpp"
    break;

  case 176: // expr_var: expr_var ">=" expr_var
#line 480 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2141 "frontend/parser.cpp"
    break;

  case 177: // expr_var: expr_int "<" expr_var
#line 482 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2147 "frontend/parser.cpp"
    break;

  case 178: // expr_var: expr_float "<" expr_var
#line 483 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2153 "frontend/parser.cpp"
    break;

  case 180: // expr_var: expr_var "<" expr_int
#line 485 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2159 "frontend/parser.cpp"
    break;

  case 181: // expr_var: expr_var "<" expr_float
#line 486 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2165 "frontend/parser.cpp"
    break;

  case 182: // expr_var: expr_var "<" expr_str
#line 487 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2171 "frontend/parser.cpp"
    break;

  case 183: // expr_var: expr_var "<" expr_var
#line 488 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2177 "frontend/parser.cpp"
    break;

  case 184: // expr_var: expr_int "<=" expr_var
#line 490 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2183 "frontend/parser.cpp"
    break;

  case 185: // expr_var: expr_float "<=" expr_var
#line 491 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2189 "frontend/parser.cpp"
    break;

  case 187: // expr_var: expr_var "<=" expr_int
#line 493 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2195 "frontend/parser.cpp"
    break;

  case 188: // expr_var: expr_var "<=" expr_float
#line 494 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2201 "frontend/parser.cpp"
    break;

  case 189: // expr_var: expr_var "<=" expr_str
#line 495 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2207 "frontend/parser.cpp"
    break;

  case 190: // expr_var: expr_var "<=" expr_var
#line 496 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2213 "frontend/parser.cpp"
    break;

  case 191: // expr_var: expr_int "==" expr_var
#line 498 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2219 "frontend/parser.cpp"
    break;

  case 192: // expr_var: expr_float "==" expr_var
#line 499 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2225 "frontend/parser.cpp"
    break;

  case 194: // expr_var: expr_bool "==" expr_var
#line 501 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2231 "frontend/parser.cpp"
    break;

  case 195: // expr_var: expr_none "==" expr_var
#line 502 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2237 "frontend/parser.cpp"
    break;

  case 198: // expr_var: expr_var "==" expr_int
#line 505 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2243 "frontend/parser.cpp"
    break;

  case 199: // expr_var: expr_var "==" expr_float
#line 506 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2249 "frontend/parser.cpp"
    break;

  case 200: // expr_var: expr_var "==" expr_str
#line 507 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2255 "frontend/parser.cpp"
    break;

  case 201: // expr_var: expr_var "==" expr_bool
#line 508 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2261 "frontend/parser.cpp"
    break;

  case 202: // expr_var: expr_var "==" expr_none
#line 509 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2267 "frontend/parser.cpp"
    break;

  case 203: // expr_var: expr_var "==" expr_struct
#line 510 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2273 "frontend/parser.cpp"
    break;

  case 204: // expr_var: expr_mat "==" expr_mat
#line 511 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2279 "frontend/parser.cpp"
    break;

  case 205: // expr_var: expr_var "==" expr_mat
#line 512 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2285 "frontend/parser.cpp"
    break;

  case 206: // expr_var: expr_mat "==" expr_var
#line 513 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2291 "frontend/parser.cpp"
    break;

  case 207: // expr_var: expr_var "==" expr_var
#line 514 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2297 "frontend/parser.cpp"
    break;

  case 208: // expr_var: expr_int "!=" expr_var
#line 516 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2303 "frontend/parser.cpp"
    break;

  case 209: // expr_var: expr_float "!=" expr_var
#line 517 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2309 "frontend/parser.cpp"
    break;

  case 212: // expr_var: expr_none "!=" expr_var
#line 520 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2315 "frontend/parser.cpp"
    break;

  case 215: // expr_var: expr_var "!=" expr_int
#line 523 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2321 "frontend/parser.cpp"
    break;

  case 216: // expr_var: expr_var "!=" expr_float
#line 524 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2327 "frontend/parser.cpp"
    break;

  case 217: // expr_var: expr_var "!=" expr_str
#line 525 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2333 "frontend/parser.cpp"
    break;

  case 218: // expr_var: expr_var "!=" expr_bool
#line 526 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2339 "frontend/parser.cpp"
    break;

  case 219: // expr_var: expr_var "!=" expr_none
#line 527 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2345 "frontend/parser.cpp"
    break;

  case 220: // expr_var: expr_var "!=" expr_struct
#line 528 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2351 "frontend/parser.cpp"
    break;

  case 221: // expr_var: expr_mat "!=" expr_mat
#line 529 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2357 "frontend/parser.cpp"
    break;

  case 222: // expr_var: expr_var "!=" expr_mat
#line 530 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2363 "frontend/parser.cpp"
    break;

  case 223: // expr_var: expr_mat "!=" expr_var
#line 531 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2369 "frontend/parser.cpp"
    break;

  case 224: // expr_var: expr_var "!=" expr_var
#line 532 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2375 "frontend/parser.cpp"
    break;

  case 225: // expr_var: expr_int "&" expr_var
#line 534 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2381 "frontend/parser.cpp"
    break;

  case 226: // expr_var: expr_var "&" expr_int
#line 535 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2387 "frontend/parser.cpp"
    break;

  case 227: // expr_var: expr_var "&" expr_var
#line 536 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2393 "frontend/parser.cpp"
    break;

  case 228: // expr_var: expr_int "^" expr_var
#line 538 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2399 "frontend/parser.cpp"
    break;

  case 229: // expr_var: expr_var "^" expr_int
#line 539 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2405 "frontend/parser.cpp"
    break;

  case 230: // expr_var: expr_var "^" expr_var
#line 540 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2411 "frontend/parser.cpp"
    break;

  case 231: // expr_var: expr_int "|" expr_var
#line 542 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2417 "frontend/parser.cpp"
    break;

  case 232: // expr_var: expr_var "|" expr_int
#line 543 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2423 "frontend/parser.cpp"
    break;

  case 233: // expr_var: expr_var "|" expr_var
#line 544 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2429 "frontend/parser.cpp"
    break;

  case 238: // expr_var: expr_none "in" expr_mat
#line 550 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2435 "frontend/parser.cpp"
    break;

  case 240: // expr_var: expr_mat "in" expr_mat
#line 552 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2441 "frontend/parser.cpp"
    break;

  case 245: // expr_var: expr_none "in" expr_var
#line 557 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2447 "frontend/parser.cpp"
    break;

  case 247: // expr_var: expr_mat "in" expr_var
#line 559 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2453 "frontend/parser.cpp"
    break;

  case 248: // expr_var: expr_var "in" expr_str
#line 560 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2459 "frontend/parser.cpp"
    break;

  case 249: // expr_var: expr_var "in" expr_var
#line 561 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2465 "frontend/parser.cpp"
    break;

  case 250: // expr_var: expr_bool "and" expr_var
#line 563 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2471 "frontend/parser.cpp"
    break;

  case 251: // expr_var: expr_var "and" expr_bool
#line 564 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2477 "frontend/parser.cpp"
    break;

  case 252: // expr_var: expr_var "and" expr_var
#line 565 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2483 "frontend/parser.cpp"
    break;

  case 253: // expr_var: expr_bool "or" expr_var
#line 567 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2489 "frontend/parser.cpp"
    break;

  case 254: // expr_var: expr_var "or" expr_bool
#line 568 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2495 "frontend/parser.cpp"
    break;

  case 255: // expr_var: expr_var "or" expr_var
#line 569 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2501 "frontend/parser.cpp"
    break;

  case 260: // expr_var: expr_none "++" expr_struct
#line 575 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2507 "frontend/parser.cpp"
    break;

  case 267: // expr_var: expr_int "++" expr_var
#line 582 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2513 "frontend/parser.cpp"
    break;

  case 268: // expr_var: expr_float "++" expr_var
#line 583 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2519 "frontend/parser.cpp"
    break;

  case 269: // expr_var: expr_str "++" expr_var
#line 584 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2525 "frontend/parser.cpp"
    break;

  case 270: // expr_var: expr_bool "++" expr_var
#line 585 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2531 "frontend/parser.cpp"
    break;

  case 271: // expr_var: expr_none "++" expr_var
#line 586 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2537 "frontend/parser.cpp"
    break;

  case 273: // expr_var: expr_var "++" expr_int
#line 588 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2543 "frontend/parser.cpp"
    break;

  case 274: // expr_var: expr_var "++" expr_float
#line 589 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2549 "frontend/parser.cpp"
    break;

  case 275: // expr_var: expr_var "++" expr_str
#line 590 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2555 "frontend/parser.cpp"
    break;

  case 276: // expr_var: expr_var "++" expr_bool
#line 591 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2561 "frontend/parser.cpp"
    break;

  case 277: // expr_var: expr_var "++" expr_none
#line 592 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2567 "frontend/parser.cpp"
    break;

  case 278: // expr_var: expr_var "++" expr_struct
#line 593 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2573 "frontend/parser.cpp"
    break;

  case 279: // expr_var: expr_var "++" expr_var
#line 594 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2579 "frontend/parser.cpp"
    break;

  case 280: // matrix: "[" "]"
#line 598 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(std::vector<ptc::ir::Expr *>{}); }
#line 2585 "frontend/parser.cpp"
    break;

  case 281: // matrix: "[" matvals "]"
#line 599 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2591 "frontend/parser.cpp"
    break;

  case 282: // matrix: "[" "terminator (\\n or ;)" matvals "]"
#line 600 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2597 "frontend/parser.cpp"
    break;

  case 283: // matrix: "[" matvals "terminator (\\n or ;)" "]"
#line 601 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2603 "frontend/parser.cpp"
    break;

  case 284: // matrix: "[" "terminator (\\n or ;)" matvals "terminator (\\n or ;)" "]"
#line 602 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2609 "frontend/parser.cpp"
    break;

  case 285: // matvals: expr
#line 605 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixValue(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2615 "frontend/parser.cpp"
    break;

  case 286: // matvals: matvals "," expr
#line 606 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2621 "frontend/parser.cpp"
    break;

  case 287: // matvals: matvals "," "terminator (\\n or ;)" expr
#line 607 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[3].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2627 "frontend/parser.cpp"
    break;

  case 288: // expr_mat: matrix
#line 611 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2633 "frontend/parser.cpp"
    break;

  case 289: // expr_mat: "(" matrix ")"
#line 612 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2639 "frontend/parser.cpp"
    break;

  case 290: // range: "(" range ")"
#line 614 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2645 "frontend/parser.cpp"
    break;

  case 291: // range: int_val ".." int_val
#line 615 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseRange(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2651 "frontend/parser.cpp"
    break;

  case 292: // range: int_val "," int_val ".." int_val
#line 616 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseRange(yystack_[4].value.as < ptc::ir::Expr * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2657 "frontend/parser.cpp"
    break;

  case 293: // int_val: expr_int
#line 618 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 2663 "frontend/parser.cpp"
    break;

  case 294: // int_val: expr_var
#line 619 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2669 "frontend/parser.cpp"
    break;

  case 307: // expr_none: "none"
#line 636 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseNone(); }
#line 2675 "frontend/parser.cpp"
    break;

  case 308: // expr_none: "(" "none" ")"
#line 637 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseNone(); }
#line 2681 "frontend/parser.cpp"
    break;

  case 315: // expr_int: "int"
#line 652 "frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 2687 "frontend/parser.cpp"
    break;

  case 316: // expr_int: "-" expr_int
#line 653 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 2693 "frontend/parser.cpp"
    break;

  case 317: // expr_int: "(" expr_int ")"
#line 654 "frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 2699 "frontend/parser.cpp"
    break;

  case 318: // expr_int: "~" expr_int
#line 655 "frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 2705 "frontend/parser.cpp"
    break;

  case 319: // expr_int: expr_int "*" expr_int
#line 656 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 2711 "frontend/parser.cpp"
    break;

  case 320: // expr_int: expr_int "/" expr_int
#line 657 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 2717 "frontend/parser.cpp"
    break;

  case 321: // expr_int: expr_int "%" expr_int
#line 658 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 2723 "frontend/parser.cpp"
    break;

  case 322: // expr_int: expr_int "-" expr_int
#line 659 "frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 2729 "frontend/parser.cpp"
    break;

  case 323: // expr_int: expr_int "+" expr_int
#line 660 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 2735 "frontend/parser.cpp"
    break;

  case 324: // expr_int: expr_int "<<" expr_int
#line 661 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 2741 "frontend/parser.cpp"
    break;

  case 325: // expr_int: expr_int ">>" expr_int
#line 662 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 2747 "frontend/parser.cpp"
    break;

  case 326: // expr_int: expr_int "&" expr_int
#line 663 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 2753 "frontend/parser.cpp"
    break;

  case 327: // expr_int: expr_int "^" expr_int
#line 664 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 2759 "frontend/parser.cpp"
    break;

  case 328: // expr_int: expr_int "|" expr_int
#line 665 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 2765 "frontend/parser.cpp"
    break;

  case 329: // expr_float: "float"
#line 669 "frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 2771 "frontend/parser.cpp"
    break;

  case 330: // expr_float: "-" expr_float
#line 670 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 2777 "frontend/parser.cpp"
    break;

  case 331: // expr_float: "(" expr_float ")"
#line 671 "frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 2783 "frontend/parser.cpp"
    break;

  case 332: // expr_float: expr_float "**" expr_float
#line 672 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2789 "frontend/parser.cpp"
    break;

  case 333: // expr_float: expr_float "**" expr_int
#line 673 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2795 "frontend/parser.cpp"
    break;

  case 334: // expr_float: expr_int "**" expr_float
#line 674 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2801 "frontend/parser.cpp"
    break;

  case 335: // expr_float: expr_float "*" expr_float
#line 675 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 2807 "frontend/parser.cpp"
    break;

  case 336: // expr_float: expr_float "*" expr_int
#line 676 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 2813 "frontend/parser.cpp"
    break;

  case 337: // expr_float: expr_int "*" expr_float
#line 677 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 2819 "frontend/parser.cpp"
    break;

  case 338: // expr_float: expr_float "/" expr_float
#line 678 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 2825 "frontend/parser.cpp"
    break;

  case 339: // expr_float: expr_float "/" expr_int
#line 679 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 2831 "frontend/parser.cpp"
    break;

  case 340: // expr_float: expr_int "/" expr_float
#line 680 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 2837 "frontend/parser.cpp"
    break;

  case 341: // expr_float: expr_float "%" expr_float
#line 681 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2843 "frontend/parser.cpp"
    break;

  case 342: // expr_float: expr_float "%" expr_int
#line 682 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2849 "frontend/parser.cpp"
    break;

  case 343: // expr_float: expr_int "%" expr_float
#line 683 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2855 "frontend/parser.cpp"
    break;

  case 344: // expr_float: expr_float "-" expr_float
#line 684 "frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 2861 "frontend/parser.cpp"
    break;

  case 345: // expr_float: expr_float "-" expr_int
#line 685 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 2867 "frontend/parser.cpp"
    break;

  case 346: // expr_float: expr_int "-" expr_float
#line 686 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 2873 "frontend/parser.cpp"
    break;

  case 347: // expr_float: expr_float "+" expr_float
#line 687 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 2879 "frontend/parser.cpp"
    break;

  case 348: // expr_float: expr_float "+" expr_int
#line 688 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 2885 "frontend/parser.cpp"
    break;

  case 349: // expr_float: expr_int "+" expr_float
#line 689 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 2891 "frontend/parser.cpp"
    break;

  case 350: // expr_str: "string"
#line 693 "frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2897 "frontend/parser.cpp"
    break;

  case 351: // expr_str: "(" expr_str ")"
#line 694 "frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 2903 "frontend/parser.cpp"
    break;

  case 352: // expr_str: expr_str "++" expr_str
#line 695 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 2909 "frontend/parser.cpp"
    break;

  case 353: // expr_str: expr_str "++" expr_int
#line 696 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 2915 "frontend/parser.cpp"
    break;

  case 354: // expr_str: expr_str "++" expr_float
#line 697 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 2921 "frontend/parser.cpp"
    break;

  case 355: // expr_str: expr_str "++" expr_bool
#line 698 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2927 "frontend/parser.cpp"
    break;

  case 356: // expr_str: expr_str "++" expr_none
#line 699 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 2933 "frontend/parser.cpp"
    break;

  case 357: // expr_str: expr_int "++" expr_str
#line 700 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 2939 "frontend/parser.cpp"
    break;

  case 358: // expr_str: expr_int "++" expr_int
#line 701 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 2945 "frontend/parser.cpp"
    break;

  case 359: // expr_str: expr_int "++" expr_float
#line 702 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 2951 "frontend/parser.cpp"
    break;

  case 360: // expr_str: expr_int "++" expr_bool
#line 703 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2957 "frontend/parser.cpp"
    break;

  case 361: // expr_str: expr_int "++" expr_none
#line 704 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 2963 "frontend/parser.cpp"
    break;

  case 362: // expr_str: expr_float "++" expr_str
#line 705 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 2969 "frontend/parser.cpp"
    break;

  case 363: // expr_str: expr_float "++" expr_int
#line 706 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 2975 "frontend/parser.cpp"
    break;

  case 364: // expr_str: expr_float "++" expr_float
#line 707 "frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 2981 "frontend/parser.cpp"
    break;

  case 365: // expr_str: expr_float "++" expr_bool
#line 708 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2987 "frontend/parser.cpp"
    break;

  case 366: // expr_str: expr_float "++" expr_none
#line 709 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 2993 "frontend/parser.cpp"
    break;

  case 367: // expr_str: expr_bool "++" expr_str
#line 710 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 2999 "frontend/parser.cpp"
    break;

  case 368: // expr_str: expr_bool "++" expr_int
#line 711 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 3005 "frontend/parser.cpp"
    break;

  case 369: // expr_str: expr_bool "++" expr_float
#line 712 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 3011 "frontend/parser.cpp"
    break;

  case 370: // expr_str: expr_bool "++" expr_bool
#line 713 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3017 "frontend/parser.cpp"
    break;

  case 371: // expr_str: expr_bool "++" expr_none
#line 714 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 3023 "frontend/parser.cpp"
    break;

  case 372: // expr_str: expr_none "++" expr_str
#line 715 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 3029 "frontend/parser.cpp"
    break;

  case 373: // expr_str: expr_none "++" expr_int
#line 716 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 3035 "frontend/parser.cpp"
    break;

  case 374: // expr_str: expr_none "++" expr_float
#line 717 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 3041 "frontend/parser.cpp"
    break;

  case 375: // expr_str: expr_none "++" expr_bool
#line 718 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3047 "frontend/parser.cpp"
    break;

  case 376: // expr_str: expr_none "++" expr_none
#line 719 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 3053 "frontend/parser.cpp"
    break;

  case 377: // expr_bool: "bool"
#line 723 "frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 3059 "frontend/parser.cpp"
    break;

  case 378: // expr_bool: "(" expr_bool ")"
#line 724 "frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 3065 "frontend/parser.cpp"
    break;

  case 379: // expr_bool: "not" expr_bool
#line 725 "frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 3071 "frontend/parser.cpp"
    break;

  case 380: // expr_bool: expr_bool "or" expr_bool
#line 726 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 3077 "frontend/parser.cpp"
    break;

  case 381: // expr_bool: expr_bool "and" expr_bool
#line 727 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 3083 "frontend/parser.cpp"
    break;

  case 382: // expr_bool: expr_bool "==" expr_bool
#line 729 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 3089 "frontend/parser.cpp"
    break;

  case 383: // expr_bool: expr_int "==" expr_int
#line 730 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 3095 "frontend/parser.cpp"
    break;

  case 384: // expr_bool: expr_int "==" expr_float
#line 731 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 3101 "frontend/parser.cpp"
    break;

  case 385: // expr_bool: expr_float "==" expr_float
#line 732 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 3107 "frontend/parser.cpp"
    break;

  case 386: // expr_bool: expr_float "==" expr_int
#line 733 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 3113 "frontend/parser.cpp"
    break;

  case 387: // expr_bool: expr_str "==" expr_str
#line 734 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 3119 "frontend/parser.cpp"
    break;

  case 388: // expr_bool: expr_none "==" expr_none
#line 735 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 3125 "frontend/parser.cpp"
    break;

  case 389: // expr_bool: expr_bool "!=" expr_bool
#line 737 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 3131 "frontend/parser.cpp"
    break;

  case 390: // expr_bool: expr_int "!=" expr_int
#line 738 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 3137 "frontend/parser.cpp"
    break;

  case 391: // expr_bool: expr_int "!=" expr_float
#line 739 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 3143 "frontend/parser.cpp"
    break;

  case 392: // expr_bool: expr_float "!=" expr_float
#line 740 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 3149 "frontend/parser.cpp"
    break;

  case 393: // expr_bool: expr_float "!=" expr_int
#line 741 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 3155 "frontend/parser.cpp"
    break;

  case 394: // expr_bool: expr_str "!=" expr_str
#line 742 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 3161 "frontend/parser.cpp"
    break;

  case 395: // expr_bool: expr_none "!=" expr_none
#line 743 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 3167 "frontend/parser.cpp"
    break;

  case 396: // expr_bool: expr_int ">" expr_int
#line 745 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 3173 "frontend/parser.cpp"
    break;

  case 397: // expr_bool: expr_int ">" expr_float
#line 746 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 3179 "frontend/parser.cpp"
    break;

  case 398: // expr_bool: expr_float ">" expr_float
#line 747 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 3185 "frontend/parser.cpp"
    break;

  case 399: // expr_bool: expr_float ">" expr_int
#line 748 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 3191 "frontend/parser.cpp"
    break;

  case 400: // expr_bool: expr_str ">" expr_str
#line 749 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 3197 "frontend/parser.cpp"
    break;

  case 401: // expr_bool: expr_int "<" expr_int
#line 751 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 3203 "frontend/parser.cpp"
    break;

  case 402: // expr_bool: expr_int "<" expr_float
#line 752 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 3209 "frontend/parser.cpp"
    break;

  case 403: // expr_bool: expr_float "<" expr_float
#line 753 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 3215 "frontend/parser.cpp"
    break;

  case 404: // expr_bool: expr_float "<" expr_int
#line 754 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 3221 "frontend/parser.cpp"
    break;

  case 405: // expr_bool: expr_str "<" expr_str
#line 755 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 3227 "frontend/parser.cpp"
    break;

  case 406: // expr_bool: expr_int ">=" expr_int
#line 757 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 3233 "frontend/parser.cpp"
    break;

  case 407: // expr_bool: expr_int ">=" expr_float
#line 758 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 3239 "frontend/parser.cpp"
    break;

  case 408: // expr_bool: expr_float ">=" expr_float
#line 759 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 3245 "frontend/parser.cpp"
    break;

  case 409: // expr_bool: expr_float ">=" expr_int
#line 760 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 3251 "frontend/parser.cpp"
    break;

  case 410: // expr_bool: expr_str ">=" expr_str
#line 761 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 3257 "frontend/parser.cpp"
    break;

  case 411: // expr_bool: expr_int "<=" expr_int
#line 763 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 3263 "frontend/parser.cpp"
    break;

  case 412: // expr_bool: expr_int "<=" expr_float
#line 764 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 3269 "frontend/parser.cpp"
    break;

  case 413: // expr_bool: expr_float "<=" expr_float
#line 765 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 3275 "frontend/parser.cpp"
    break;

  case 414: // expr_bool: expr_float "<=" expr_int
#line 766 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 3281 "frontend/parser.cpp"
    break;

  case 415: // expr_bool: expr_str "<=" expr_str
#line 767 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 3287 "frontend/parser.cpp"
    break;

  case 416: // expr_bool: expr_str "in" expr_str
#line 769 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[0].value.as < std::string > ().find(yystack_[2].value.as < std::string > ()) != std::string::npos; }
#line 3293 "frontend/parser.cpp"
    break;

  case 421: // mattype: "identifier" matsq
#line 781 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3299 "frontend/parser.cpp"
    break;

  case 422: // mattype: "'int'" matsq
#line 782 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(INT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3305 "frontend/parser.cpp"
    break;

  case 423: // mattype: "'float'" matsq
#line 783 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(FLOAT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3311 "frontend/parser.cpp"
    break;

  case 424: // mattype: "'string'" matsq
#line 784 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(STRING_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3317 "frontend/parser.cpp"
    break;

  case 425: // mattype: "'bool'" matsq
#line 785 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(BOOL_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3323 "frontend/parser.cpp"
    break;

  case 433: // matsq: "[" "]"
#line 794 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(scanner->parseInt(-1)); }
#line 3329 "frontend/parser.cpp"
    break;

  case 434: // matsq: "[" int_val "]"
#line 795 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 3335 "frontend/parser.cpp"
    break;

  case 435: // matsq: "[" "]" matsq
#line 796 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), scanner->parseInt(-1)); }
#line 3341 "frontend/parser.cpp"
    break;

  case 436: // matsq: "[" int_val "]" matsq
#line 797 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[2].value.as < ptc::ir::Expr * > ()); }
#line 3347 "frontend/parser.cpp"
    break;

  case 437: // type: "'int'" "?"
#line 801 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, true, true); }
#line 3353 "frontend/parser.cpp"
    break;

  case 438: // type: "'float'" "?"
#line 802 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, true, true); }
#line 3359 "frontend/parser.cpp"
    break;

  case 439: // type: "'string'" "?"
#line 803 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, true, true); }
#line 3365 "frontend/parser.cpp"
    break;

  case 440: // type: "'bool'" "?"
#line 804 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, true, true); }
#line 3371 "frontend/parser.cpp"
    break;

  case 441: // type: "identifier" "?"
#line 805 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[1].value.as < std::string > (), true, true); }
#line 3377 "frontend/parser.cpp"
    break;

  case 443: // type: mattype "?"
#line 807 "frontend/parser.yy"
       { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 3383 "frontend/parser.cpp"
    break;

  case 444: // type: "'int'"
#line 808 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, false, true); }
#line 3389 "frontend/parser.cpp"
    break;

  case 445: // type: "'float'"
#line 809 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, false, true); }
#line 3395 "frontend/parser.cpp"
    break;

  case 446: // type: "'string'"
#line 810 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, false, true); }
#line 3401 "frontend/parser.cpp"
    break;

  case 447: // type: "'bool'"
#line 811 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, false, true); }
#line 3407 "frontend/parser.cpp"
    break;

  case 448: // type: "identifier"
#line 812 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[0].value.as < std::string > (), false, true); }
#line 3413 "frontend/parser.cpp"
    break;

  case 450: // type: mattype
#line 814 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 3419 "frontend/parser.cpp"
    break;


#line 3423 "frontend/parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -761;

  const short  Parser ::yytable_ninf_ = -449;

  const short
   Parser ::yypact_[] =
  {
    1481,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  1603,    25,
       6,  1467,   497,   -12,    19,  -761,    57,  -761,  -761,  1692,
    -761,  -761,    34,    27,    29,    78,    79,    46,    61,   469,
      63,   141,   524,  -761,  -761,    16,    16,  -761,  -761,  -761,
     135,  -761,  1809,  -761,   169,  -761,  -761,    16,    16,    16,
     317,  2888,  -761,   735,   538,   615,  2683,  3263,   775,   631,
     239,   171,     4,   230,   318,  2212,   243,   735,   538,   615,
    3054,  2483,   923,   929,  1692,  -761,   318,  -761,   130,   494,
     494,  -761,  -761,  -761,  -761,  1589,   581,  3148,  3297,  1498,
    -761,   497,   497,  -761,   202,   233,  -761,  1097,  -761,   276,
     867,   321,  -761,   321,  -761,   321,  -761,   321,  -761,   123,
    -761,   316,   480,   319,  1692,   321,  -761,  -761,  -761,   894,
    1692,  -761,  -761,  -761,  2792,  -761,  -761,  -761,  -761,  -761,
    1692,   327,  2718,  -761,  -761,   281,  1692,  -761,  -761,  -761,
    1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,
    1692,  1692,  1692,  -761,   973,   894,  1692,  1692,  1692,  1692,
    1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,
    1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,  -761,   894,
    1692,  1692,  1692,  1692,  1692,  1692,  -761,  1692,  1692,  1692,
    1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,
     494,  1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,
    1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,
    1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,
    1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,
    1692,  1692,  1692,   321,  -761,  -761,    60,    55,   335,  -761,
     894,   403,  -761,  -761,  -761,  -761,  -761,  -761,   234,   344,
    -761,    39,  1826,   994,   494,   494,   494,   494,   494,   497,
     497,   497,   497,   497,   494,   494,   494,   494,   494,   494,
    3085,  2637,  1619,   535,  1467,   366,   366,  1467,   494,   494,
     494,   494,   494,   494,  1467,   494,   494,   494,   494,   494,
     494,  1467,  1467,  1467,  1467,  1467,  1467,  1467,  1467,  1467,
    1467,  1467,  1467,  1467,  1657,  -761,   497,   497,   497,   497,
     497,  1692,    19,    -2,   386,   432,     8,  1692,   321,  2888,
     467,  2683,  3263,   775,   631,  -761,  -761,  -761,  -761,   462,
      53,    69,   600,   314,  -761,   407,   483,    50,  2683,  -761,
     336,    50,  -761,   501,  2792,  -761,  2521,   503,   508,  -761,
    2157,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,   235,  -761,   364,   640,    10,   947,
    1173,   640,    10,   947,  1173,   463,   511,   517,   518,   463,
     517,   518,   463,   517,   518,   463,   518,  2046,   514,   636,
    3171,  1984,   852,   595,  2328,   677,  2923,   732,  2360,   688,
    3010,  3274,  2952,  3217,  2981,  3240,   334,  1108,   334,  1108,
    1144,   628,  -761,  -761,  1901,   802,   540,  -761,  1144,   628,
    -761,  -761,  1901,   802,   540,  -761,   897,  1220,  1419,   523,
     897,  1220,  1419,   523,   897,  1220,  1419,   523,   897,  1220,
    1419,   523,    50,   459,   640,    10,   640,    10,   463,   511,
    2360,   849,  1144,   628,  1144,   628,  2046,   514,   636,  3171,
    1984,   852,   595,  2360,   849,  1144,  -761,  1144,  -761,  2046,
     514,   636,  3171,  1984,   852,   595,  2360,   849,  1144,  -761,
    1144,  -761,   640,   947,  1173,   640,   947,  1173,   463,   517,
     518,   463,   517,   518,   463,   517,   518,  1083,   522,  2046,
     514,   636,  3171,  1984,   852,   595,  2360,   849,  3010,  3274,
    2952,  3217,  2981,  3240,   334,  1108,   334,  1108,  1144,  1901,
     802,  1144,  1901,   802,   897,  1220,  1419,   897,  1220,  1419,
     897,  1220,  1419,   897,  1220,  1419,   640,   947,  1173,   640,
     947,  1173,   463,   517,   518,   463,   517,   518,   463,   517,
     518,   463,   517,   518,  2046,   514,   636,  3171,  1984,   852,
     595,  2360,   849,  1144,  1901,   802,  1144,  1901,   802,   897,
    1220,  1419,   897,  1220,  1419,   897,  1220,  1419,   897,  1220,
    1419,   532,  2046,   514,   636,  3171,  1984,   852,   595,  2360,
     849,   688,  1144,   540,  1144,   540,   897,   523,   897,   523,
     897,   523,   897,   523,  2046,   514,   636,  3171,  1984,   852,
     595,  2328,   677,  2923,   732,  2360,   849,  1144,  -761,  1144,
    -761,  -761,  -761,   240,   551,   232,  1013,   245,   464,  -761,
     550,  -761,  -761,  1692,  -761,  1184,  1226,  1184,  1226,   517,
     522,   517,   522,   517,   522,  1995,  1276,  1328,   840,   840,
    1184,  1226,  1184,  1226,   517,   522,   517,   522,   517,   522,
     517,   522,   290,  3194,  2524,  1237,   707,   558,  -761,  -761,
     290,  3194,  2524,  1237,   707,  1606,  1429,  1606,  1429,  1606,
    1429,  1606,  1429,  1606,  1429,  1606,  1429,   290,  3194,  2524,
    1237,   707,  1606,  1429,  1606,  1429,  1606,  1429,  1606,  1429,
    1606,  1429,  1606,  1429,   290,  3194,  2524,  1237,   707,  1535,
     675,  1282,  1282,  -761,  -761,  -761,  -761,   290,  3194,  2524,
    1237,   707,   346,   348,  -761,  -761,   476,   476,  -761,  -761,
    -761,  -761,  -761,  1723,  1723,  1723,  -761,  -761,  -761,   321,
      17,    17,  -761,   498,   564,   597,    42,   236,   237,    43,
    -761,  1252,   466,    58,   626,   559,  -761,  -761,  1809,  2622,
     616,  1692,  1809,  -761,  1692,  -761,  -761,  -761,  -761,   446,
    -761,  -761,   236,   238,  -761,  -761,  -761,   230,  1882,   611,
    2859,   612,   214,  3125,   613,   652,   656,   662,  -761,   664,
    -761,   583,  -761,    17,   634,  -761,   236,   446,  -761,  -761,
     668,  -761,  1326,  -761,  1378,   478,  1692,  -761,   691,  -761,
     694,   646,  -761,  -761,  -761,   236,  2212,   701,  3054,  1809,
    1809,  1692,  1692,  1809,  1809,  1809,  1809,  -761,  1692,  -761,
    1692,  -761,    44,  -761,  -761,   706,  -761,   714,  -761,  1453,
     698,  -761,  -761,  -761,  -761,  1809,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,   696,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,   733,   708,  -761,  1692,  -761,  -761,
    -761
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     9,   315,   329,   350,   377,   307,     0,     0,
       0,     0,     0,     0,     0,    53,     0,    47,    49,    38,
      35,    36,     0,   444,   445,   446,   447,     0,     0,   101,
     102,     0,     0,     4,    10,     0,     0,    37,    15,    17,
       0,    18,     0,    16,     0,    19,    20,     0,     0,     0,
       0,    94,   288,    93,    95,    96,    97,    98,    99,   100,
     449,   450,     0,   307,   101,     0,   288,     0,     0,     0,
       0,     0,     0,     0,     0,   280,   101,   285,     0,     0,
       0,   103,   104,   316,   330,     0,     0,     0,     0,     0,
     379,     0,     0,   318,     0,    33,    32,     0,    39,     0,
       0,   437,   422,   438,   423,   439,   424,   440,   425,     0,
      69,     0,     0,     0,     0,   441,   114,   309,   421,     0,
       0,   115,     1,     3,     0,     5,     8,     7,    14,    21,
       0,     0,     0,    30,    31,     0,     0,    12,    13,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   116,     0,
       0,     0,     0,     0,     0,     0,   113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   442,   426,   443,     0,    72,     0,   308,
       0,   309,   105,   289,   317,   331,   351,   378,     0,     0,
     281,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   316,     0,     0,     0,     0,
       0,     0,     0,   448,     0,     0,     0,     0,   433,   294,
       0,   293,     0,     0,     0,   428,   429,   430,   431,     0,
       0,     0,     0,     0,   311,     0,     0,   117,     0,   427,
       0,   118,     6,     0,     0,    23,     0,     0,     0,    90,
      89,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,   106,     0,    91,     0,   148,   146,   143,
     144,   156,   154,   151,   152,   130,   129,   125,   126,   135,
     133,   134,   140,   138,   139,   122,   121,   279,   277,   278,
     273,   274,   275,   276,   252,   251,   255,   254,   249,   248,
     227,   226,   233,   232,   230,   229,   159,   158,   162,   161,
     207,   205,   202,   203,   198,   199,   200,   201,   224,   222,
     219,   220,   215,   216,   217,   218,   169,   166,   167,   168,
     183,   180,   181,   182,   176,   173,   174,   175,   190,   187,
     188,   189,   119,     0,   147,   145,   155,   153,   128,   127,
     247,   240,   206,   204,   223,   221,   271,   376,   260,   373,
     374,   372,   375,   245,   238,   195,   388,   212,   395,   272,
     265,   266,   261,   262,   263,   264,   246,   239,   197,   196,
     214,   213,   141,   323,   349,   149,   322,   346,   123,   319,
     337,   131,   320,   340,   136,   321,   343,     0,   334,   267,
     361,   256,   358,   359,   357,   360,   241,   234,   225,   326,
     231,   328,   228,   327,   157,   324,   160,   325,   191,   383,
     384,   208,   390,   391,   163,   396,   397,   177,   401,   402,
     170,   406,   407,   184,   411,   412,   142,   348,   347,   150,
     345,   344,   124,   336,   335,   132,   339,   338,   137,   342,
     341,   120,   333,   332,   268,   366,   257,   363,   364,   362,
     365,   242,   235,   192,   386,   385,   209,   393,   392,   164,
     399,   398,   178,   404,   403,   171,   409,   408,   185,   414,
     413,     0,   269,   356,   258,   353,   354,   352,   355,   243,
     236,   416,   193,   387,   210,   394,   165,   400,   179,   405,
     172,   410,   186,   415,   270,   371,   259,   368,   369,   367,
     370,   250,   381,   253,   380,   244,   237,   194,   382,   211,
     389,   432,   418,   448,     0,   419,     0,     0,     0,   310,
       0,   282,   283,     0,   286,   323,   349,   322,   346,   319,
     337,   320,   340,   321,   343,   326,   328,   327,   324,   325,
     348,   347,   345,   344,   336,   335,   339,   338,   342,   341,
     333,   332,   376,   373,   374,   372,   375,     0,   388,   395,
     361,   358,   359,   357,   360,   383,   384,   390,   391,   396,
     397,   401,   402,   406,   407,   411,   412,   366,   363,   364,
     362,   365,   386,   385,   393,   392,   399,   398,   404,   403,
     409,   408,   414,   413,   356,   353,   354,   352,   355,   416,
       0,   387,   394,   400,   405,   410,   415,   371,   368,   369,
     367,   370,   381,   380,   382,   389,   323,   322,   319,   320,
     321,    76,    34,     0,     0,     0,    72,    75,   435,   434,
       0,    58,    55,     0,     0,     0,     0,     0,     0,     0,
     295,     0,     0,   110,     0,     0,   312,   111,     0,     0,
      24,     0,     0,   107,     0,   112,   109,   108,   417,     0,
      74,    73,     0,     0,   110,   284,   287,     0,     0,     0,
     294,     0,     0,   293,     0,     0,     0,     0,   436,     0,
      59,     0,    56,    60,    62,    67,     0,     0,    70,   299,
       0,   297,     0,   296,     0,     0,     0,    46,    25,    26,
       0,    52,    92,   420,    65,     0,   294,     0,   293,     0,
       0,     0,     0,     0,     0,     0,     0,    57,     0,    61,
       0,    68,     0,   302,   301,     0,   300,     0,   298,     0,
     313,    27,    48,    54,    50,     0,    66,   290,    28,    29,
      41,    44,   291,     0,    42,    45,    40,    43,    64,    63,
      71,   305,   304,   303,     0,     0,    51,     0,   306,   314,
     292
  };

  const short
   Parser ::yypgoto_[] =
  {
    -761,  -761,  -118,   288,   -26,   -41,   -24,   200,  -760,  -761,
     433,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -693,  -761,  -761,   697,   125,   669,  -761,
     629,  -761,  1828,   227,    -3,   705,  1996,  -669,   491,  1832,
    1639,  2294,   -57,   -94,    -8,   921,   541,  1279,  -761,     5,
    -761,     0,   224
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    31,    32,   128,    33,    34,   859,   860,   135,    35,
      96,    36,    37,    38,    39,    40,    41,    42,    43,   854,
      44,   855,    45,   754,   755,    46,   111,   758,    47,    48,
      49,   374,    50,    51,    52,    78,    67,   791,   792,   178,
      68,    69,   117,   346,    56,   332,   333,   334,    60,   634,
      61,   118,    62
  };

  const short
   Parser ::yytable_[] =
  {
      70,   133,    83,    87,    93,    66,   125,   251,   817,   100,
       3,     4,   821,   246,   356,    79,   126,   246,   134,   127,
     751,   179,    80,   102,   104,   106,   108,   182,    74,     3,
       4,     5,     6,     7,     8,    12,     9,    75,   100,   743,
     100,    10,   643,     3,     4,     5,     6,     7,     8,    11,
       9,   246,   246,   246,    12,    10,   751,   799,   800,   154,
     244,   155,    94,    11,   -69,   115,    97,   752,    12,   100,
     632,   262,    83,   753,   119,   795,   797,   280,   247,   757,
      81,    82,   746,   314,   315,    23,    24,    25,    26,   100,
     100,   633,   331,    95,   101,   876,   103,   636,   352,    76,
      30,   335,   120,   336,   331,   337,   348,   338,    99,   753,
     839,   331,   348,    76,    30,   349,   804,   808,   870,   827,
     109,    23,    24,    25,    26,  -434,   339,   633,    23,    24,
      25,    26,  -434,   259,   633,   110,   340,    23,    24,    25,
      26,   122,   260,   633,   130,   105,   107,   331,   379,   383,
     387,   390,   393,   348,   400,   348,   348,   348,   411,   413,
     415,   417,   419,   424,   432,   437,   441,   445,   449,   348,
     261,   331,   348,   348,   348,   348,   348,   348,   136,   469,
     348,   348,   348,   482,   348,   348,   348,   493,   496,   499,
     502,   505,   507,   512,   348,   519,   521,   523,   525,   527,
     529,   532,   535,   538,   541,   544,   547,   550,   553,   556,
     559,   562,   567,   348,   574,   577,   580,   583,   586,   589,
     331,   595,   348,   348,   348,   348,   348,   348,   348,   617,
     348,   348,   348,   348,   348,    65,   769,   640,   245,   131,
     249,   246,   331,   631,   321,   773,   641,   806,   825,   132,
     100,   100,   831,   253,   832,   782,   645,   647,   649,   651,
     653,   655,   656,   657,   658,   659,   660,   662,   664,   666,
     668,   670,   779,   322,   261,   774,   673,   807,   807,   681,
     685,   687,   689,   691,   693,   695,   698,   702,   704,   706,
     708,   710,   712,   715,    87,    87,    87,    87,    87,    87,
      87,   728,    87,    87,    87,    87,   243,   115,   736,   737,
     738,   739,   740,    23,    24,    25,    26,   126,   327,   633,
     127,   326,   285,   286,   129,   341,   763,   329,   748,   250,
     125,   113,   100,   344,   331,   137,   138,   139,   153,   329,
     354,   347,   357,   154,   637,   155,   329,   351,   767,   156,
     157,   158,   159,   160,   161,   764,   642,   114,   345,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     310,   151,   152,   177,     7,   677,   775,   764,   312,   313,
     312,   313,   329,   377,   381,   385,   389,   392,   395,   397,
     404,   406,   408,   410,   412,   414,   416,   418,   420,   428,
     436,   440,   444,   448,   452,   764,   329,   454,   456,   458,
     460,   462,   464,   639,   466,   473,   475,   477,   479,   486,
     488,   490,   492,   495,   498,   501,   504,   744,   509,   516,
     518,   520,   522,   524,   526,   528,   531,   534,   537,   540,
     543,   546,   549,   552,   555,   558,   561,   564,   571,   573,
     576,   579,   582,   585,   588,   329,   592,   599,   602,   604,
     606,   608,   610,   612,   614,   621,   623,   625,   627,   629,
     635,   776,   154,   745,   155,   750,   784,   329,   811,   749,
     112,   765,   113,   161,     3,     4,     5,     6,     7,     8,
     848,     9,   328,   318,   319,   320,    10,   766,     3,     4,
     764,     3,   177,    79,    11,   764,    91,   812,   114,    12,
      80,   768,   771,    92,    23,    24,    25,    26,   772,   849,
     633,   342,   179,    12,   123,   124,    12,     2,     3,     4,
       5,     6,     7,     8,   228,     9,   115,   200,   219,   188,
      10,    58,   279,  -448,   777,   257,   189,   190,    11,    72,
      58,   228,    89,    12,    76,    30,   309,   310,   311,   187,
      58,   778,   785,   188,   756,   759,   787,   312,   313,   329,
     189,   190,   801,    58,   233,   234,   235,   236,   802,   781,
      13,    14,    15,    58,    16,    17,    18,    19,    20,    21,
      22,   330,    23,    24,    25,    26,    27,    28,    29,    30,
     803,   816,   284,   343,     3,     4,     5,     6,     7,     8,
     350,     9,   760,   285,   286,    58,    10,   238,   239,   819,
     240,   829,   830,   833,    11,   838,   282,   241,   242,    12,
       3,     4,     5,     6,     7,     8,   191,     9,   813,   179,
     192,   761,    10,   180,   181,   182,   376,   193,   194,   154,
      11,   155,   237,   238,   239,    12,   240,   158,   159,   160,
     161,   192,   834,   241,   242,    58,   835,   814,   193,   194,
     453,    58,   836,    58,    76,    30,   840,    58,   837,   177,
     843,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,   851,    58,   309,   310,   311,   228,
      76,    30,   240,   402,   852,   853,   409,   312,   313,   241,
     242,   857,   426,   434,   439,   443,   447,   451,   871,   591,
     231,   232,   233,   234,   235,   236,   872,   133,   471,   310,
     311,   133,   484,   805,   877,   793,   793,   793,   875,   312,
     313,   638,   514,   125,   134,   878,   179,   345,   134,   798,
     180,   181,   182,   331,   238,   742,   331,   240,   824,   248,
     183,   569,   783,   798,   241,   242,   325,   184,   185,   359,
     597,   601,   603,   605,   607,   609,   611,   613,   619,   258,
     828,   879,   841,     0,   823,    66,   228,     0,   858,   858,
       0,     0,   858,   858,   858,   858,   229,     0,     0,     0,
     230,   856,    58,     0,   331,     0,   331,   231,   232,   233,
     234,   235,   236,     0,   133,     0,     0,   214,   215,   216,
     217,   218,   219,   331,   331,   675,     0,     0,   683,     0,
       0,   134,     0,   762,     0,   700,   224,   225,   226,   227,
       0,   331,   717,   719,   721,   722,   723,   724,   725,   726,
     730,    89,    89,    89,    89,   316,   317,   318,   319,   320,
     179,   759,    58,   228,   180,   181,   182,     0,    58,   331,
       0,     3,     4,     5,     6,     7,     8,   230,     9,   328,
       0,   184,   185,    10,   231,   232,   233,   234,   235,   236,
       0,    11,     0,     0,     0,    58,    12,    58,     3,     4,
       5,     6,     7,     8,     0,     9,   154,     0,   155,     0,
      10,     0,   156,   157,   158,   159,   160,   161,    11,     0,
       0,    57,     0,    12,     0,     0,     0,   169,   170,    71,
      57,    84,    88,   256,   228,   342,   177,     0,     0,   257,
      57,    76,    30,     0,   229,     0,     0,     0,   230,     0,
     237,   238,   239,    57,   240,   231,   232,   233,   234,   235,
     236,   241,   242,    57,   197,   198,   199,   200,    76,    30,
     790,   790,   790,     0,   756,   756,     0,     3,     4,     5,
       6,     7,     8,   373,     9,     0,     0,     0,   329,    10,
       0,   329,     0,     0,     0,    57,     0,    11,     0,     0,
     263,    84,    12,   635,   255,     0,   281,     0,     0,   274,
     275,   276,   277,   278,   279,   826,     0,     3,     4,     5,
       6,     7,     8,     0,     9,     0,   113,   756,     0,    10,
     861,   842,     0,   864,   865,   866,   867,    11,     0,   329,
       0,   329,    12,     0,     0,    57,     0,    76,    30,     0,
       0,    57,     0,    57,     0,     0,     0,    57,   329,   329,
       0,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,     0,    57,   329,   380,   384,   388,
     391,   394,   396,   401,     0,     0,     0,    76,    30,     0,
       0,     0,   425,   433,   438,   442,   446,   450,   264,   265,
     266,   267,   268,   200,   329,     0,     0,     0,   470,   269,
     270,   271,   483,   272,   273,     0,   494,   497,   500,   503,
     506,   508,   513,   195,   196,   197,   198,   199,   200,   530,
     533,   536,   539,   542,   545,   548,   551,   554,   557,   560,
     563,   568,     0,   575,   578,   581,   584,   587,   590,     0,
     596,     0,     0,   154,     0,   155,     0,     0,   618,   156,
     157,   158,   159,   160,   161,    23,    24,    25,    26,     0,
       0,   323,   324,     0,   169,   170,     0,    58,   173,   174,
     175,   176,    57,   177,    58,   646,   648,   650,   652,   654,
     216,   217,   218,   219,     0,   661,   663,   665,   667,   669,
     671,   266,   267,   268,   200,   674,     0,     0,   682,   686,
     688,   690,   692,   694,   696,   699,   703,   705,   707,   709,
     711,   713,   716,    88,    88,    88,    88,    88,    88,    88,
     729,    88,    88,    88,    88,   195,   196,   197,   198,   199,
     200,     0,    57,   276,   277,   278,   279,     0,    57,     0,
     206,   207,   810,     0,     0,   815,     3,     4,     5,     6,
       7,     8,   302,     9,   809,     0,     0,     0,    10,   303,
     304,   305,   306,   307,   308,    57,    11,    57,     0,    59,
       0,    12,     0,     0,    58,    58,    58,    73,    59,     0,
      90,   316,   317,   318,   319,   320,     0,     0,    59,     0,
       0,     0,   269,   845,   271,   847,   272,   273,     0,    58,
      58,    59,    58,    58,     0,    58,   305,   306,   307,   308,
       0,    59,   862,   863,     0,     0,    76,    30,     0,    72,
       3,     4,     5,     6,     7,     8,     0,     9,   844,     0,
     874,     0,    10,   316,   317,   318,   319,   320,     0,     0,
      11,     0,     0,    59,   269,    12,     0,    58,   272,   273,
       0,     0,     0,     0,   283,     0,     0,     0,   880,     0,
      58,    58,     0,     0,    58,    58,    58,    58,     0,    58,
       0,    58,     3,     4,     5,     6,     7,     8,     0,     9,
     846,     0,     0,     0,    10,     0,    58,     0,     0,     0,
      76,    30,    11,    59,     0,     0,     0,    12,     0,    59,
       0,    59,     0,     0,     0,    59,     0,     0,     0,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,     0,    59,   214,   215,   216,   217,   218,   219,
       0,   403,   405,   407,   274,   275,   276,   277,   278,   279,
     427,   435,    76,    30,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     0,     9,   873,   472,     0,     0,    10,
     485,     3,     4,     5,     6,     7,    85,    11,     0,     0,
     515,     1,    12,    80,     2,     3,     4,     5,     6,     7,
       8,    11,     9,     0,     0,     0,    12,    10,     0,   570,
       0,     0,     0,     0,     0,    11,     0,     0,   598,     0,
      12,     0,     0,     0,     0,     0,   620,   622,   624,   301,
     628,   630,     0,   302,     0,     0,     0,    76,    30,     0,
     303,   304,   305,   306,   307,   308,     0,    13,    14,    15,
      59,    16,    17,    18,    19,    20,    21,    22,     0,    23,
      24,    25,    26,    27,    28,    29,    30,    57,     0,     0,
       0,     0,     0,   676,    57,     0,   684,   303,   304,   305,
     306,   307,   308,   701,     0,     0,     0,     0,     0,     0,
     718,   720,   720,   720,   720,   720,   720,   720,   731,   732,
     733,   734,   735,     3,     4,     5,     6,    63,    85,     0,
      59,     0,     0,     0,     0,    80,    59,     3,     4,     5,
       6,    63,     8,    11,     9,     0,     0,     0,    12,    10,
       0,   264,   265,   266,   267,   268,   200,    11,     0,   256,
       0,     0,    12,    59,     0,    59,   272,   273,     0,    54,
     301,     0,     0,     0,   302,     0,     0,     0,    54,     0,
      86,   303,   304,   305,   306,   307,   308,     0,    54,     0,
       0,     0,     0,     0,    57,    57,    57,   254,     0,     0,
       0,    54,   316,   317,   318,   319,   320,    64,    30,     0,
       0,    54,     0,   269,   270,   271,     0,   272,   273,    57,
      57,     0,    57,    57,     0,    57,     3,     4,     5,     6,
       7,     8,     0,     9,     0,     0,     0,     0,    10,    71,
       0,     0,     0,    54,     0,     0,    11,     0,     0,     0,
       0,    12,     0,     0,    86,     0,     0,     3,     4,     5,
       6,     7,   788,     0,     9,     0,     0,    57,     0,    10,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     0,
      57,    57,    12,     0,    57,    57,    57,    57,     0,    57,
       0,    57,     0,    54,     0,     0,    76,    30,     0,    54,
       0,    54,     0,     0,     0,    54,    57,     0,     0,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,     0,    54,     0,     0,     0,    76,    30,     0,
       0,   398,     0,     0,     0,     0,     0,     0,     0,     0,
     422,   430,   131,     3,     4,     5,     6,     7,     8,     0,
       9,     0,   132,     0,     0,    10,   467,     0,   476,   478,
     480,     0,     0,    11,     0,     0,   254,    77,    12,     0,
     510,   264,   265,   266,   267,   268,   200,    98,     0,     0,
       0,     0,   269,   270,   271,     0,   272,   273,     0,   565,
       0,   116,   121,     0,     0,    13,    14,    15,   593,    16,
      17,    18,    19,    20,    21,    22,   615,    23,    24,    25,
      26,    27,    28,    29,    30,   186,     3,     4,     5,     6,
      63,   788,     0,     9,     0,     0,   116,     0,    10,   186,
      54,     0,    77,     0,     0,     0,    11,     0,   116,     0,
       0,    12,     0,     0,     0,    59,   195,   196,   197,   198,
     199,   200,    59,   672,   678,   679,   680,     0,     0,     0,
       0,   206,   207,   697,     0,   210,   211,   212,   213,     0,
     714,    86,    86,    86,    86,    86,    86,    86,   727,    86,
      86,    86,    86,     0,     0,     0,    64,    30,   353,     0,
      54,     0,     0,     0,   358,     0,    54,     0,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,     0,   375,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    54,     0,    54,    53,     0,     0,   214,
     215,   216,   217,   218,   219,    53,     0,     0,     0,   221,
     316,   317,   318,   319,   320,    53,   222,   223,   224,   225,
     226,   227,    59,    59,    59,   272,   273,     0,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,     0,
       0,     0,     0,     0,     0,     0,     0,    59,    59,     0,
      59,    59,     0,    59,     0,   154,     0,   155,     0,     0,
       0,   156,   157,   158,   159,   160,   161,    73,   163,   164,
      53,   165,   166,   167,   168,     0,   169,   170,   171,   172,
     173,   174,   175,   176,     0,   177,     0,     0,     0,   644,
       0,     0,     0,     0,     0,    59,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    59,    59,
       0,     0,    59,    59,    59,    59,     0,    59,     0,    59,
      53,     0,     0,     0,     0,     0,    53,     0,    53,     0,
       0,     0,    53,     0,    59,     0,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,   741,
      53,     0,   378,   382,   386,   747,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   421,   429,     0,
       0,     0,     0,     0,     0,     0,   455,   457,   459,   461,
     463,   465,     0,     0,   474,     0,     0,     0,   487,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   517,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     186,   151,   152,     0,   186,     0,     0,   572,   186,     0,
       0,   154,   252,   155,     0,     0,   600,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   626,   165,   166,   167,
     168,     0,   169,   170,   171,   172,   173,   174,   175,   176,
       0,   177,     0,   186,     0,     0,     0,    53,     0,     0,
       0,   186,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,     0,     0,     0,     0,
       0,     0,    54,     0,     0,     0,     0,   186,     0,   186,
       0,   186,     0,   186,    55,   186,     0,   186,     0,     0,
       0,     0,     0,    55,     0,     0,   186,     0,     0,     0,
       0,     0,     0,    55,     0,     0,     0,    53,     0,   186,
       0,     0,     0,    53,     0,     0,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,   154,     0,   155,
       0,     0,     0,   156,   157,   158,   159,   160,   161,   186,
      53,     0,    53,   165,   166,   167,   168,     0,   169,   170,
     171,   172,   173,   174,   175,   176,     0,   177,    55,   154,
       0,   155,     0,     0,     0,   156,   157,   158,   159,   160,
     161,     0,    54,    54,    54,     0,   166,   167,   168,     0,
     169,   170,   171,   172,   173,   174,   175,   176,     0,   177,
       0,     0,     0,     0,   186,     0,     0,    54,    54,     0,
      54,    54,     0,    54,     0,     0,     0,     0,    55,     0,
       0,     0,     0,     0,    55,     0,    55,     0,     0,     0,
      55,     0,   186,     0,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,     0,    55,     0,
       0,     0,     0,     0,     0,    54,   399,     0,   186,     0,
       0,     0,     0,     0,   780,   423,   431,     0,    54,    54,
       0,   786,    54,    54,    54,    54,     0,    54,     0,    54,
       0,   468,     0,     0,     0,   481,     0,   489,   491,     0,
       0,     0,     0,   255,    54,   511,     0,     0,   214,   215,
     216,   217,   218,   219,   220,     0,     0,     0,   221,     0,
       0,     0,     0,     0,   566,   222,   223,   224,   225,   226,
     227,     0,   124,   594,     2,     3,     4,     5,     6,     7,
       8,   616,     9,     0,     0,   770,     0,    10,     0,   274,
     275,   276,   277,   278,   279,    11,     0,     0,     0,     0,
      12,     0,     0,     0,     0,    55,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   789,   794,   796,     0,     0,     0,    13,    14,    15,
       0,    16,    17,    18,    19,    20,    21,    22,     0,    23,
      24,    25,    26,    27,    28,    29,    30,     0,     0,   820,
       0,     0,   822,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,     0,     0,     0,
       0,    55,     0,   124,     0,     2,     3,     4,     5,     6,
       7,     8,    53,     9,     0,     0,   818,     0,    10,    53,
       0,     0,     0,     0,   850,     0,    11,   255,    55,     0,
      55,    12,   274,   275,   276,   277,   278,   279,   294,     0,
       0,     0,     0,     0,     0,     0,   868,     0,   869,   295,
     296,   297,   298,   299,   300,     0,     0,     0,    13,    14,
      15,     0,    16,    17,    18,    19,    20,    21,    22,     0,
      23,    24,    25,    26,    27,    28,    29,    30,   195,   196,
     197,   198,   199,   200,   201,     0,     0,     0,   202,   203,
     204,   205,     0,   206,   207,   208,   209,   210,   211,   212,
     213,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,   355,     0,    10,     0,     0,     0,     0,    53,
      53,    53,    11,     0,     0,     0,     0,    12,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    53,     0,    53,    53,     0,
      53,     0,     0,     0,    13,    14,    15,     0,    16,    17,
      18,    19,    20,    21,    22,     0,    23,    24,    25,    26,
      27,    28,    29,    30,     0,     2,     3,     4,     5,     6,
       7,     8,     0,     9,     0,     0,     0,     0,    10,     0,
       0,     0,    53,     0,     0,     0,    11,     0,     0,     0,
       0,    12,     0,     0,     0,    53,    53,     0,     0,    53,
      53,    53,    53,     0,    53,     0,    53,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,    14,
      15,    53,    16,    17,    18,    19,    20,    21,    22,     0,
      23,    24,    25,    26,    27,    28,    29,    30,   154,   -94,
     155,     0,     0,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,     0,   165,   166,   167,   168,     0,   169,
     170,   171,   172,   173,   174,   175,   176,   154,   177,   155,
       0,     0,     0,   156,   157,   158,   159,   160,   161,   162,
     163,   164,     0,   165,   166,   167,   168,     0,   169,   170,
     171,   172,   173,   174,   175,   176,     0,   177,     0,     0,
      55,     0,   154,     0,   155,     0,     0,    55,   156,   157,
     158,   159,   160,   161,     0,   163,     0,     0,   165,   166,
     167,   168,     0,   169,   170,   171,   172,   173,   174,   175,
     176,   154,   177,   155,     0,     0,     0,   156,   157,   158,
     159,   160,   161,     0,     0,     0,     0,     0,   166,     0,
     168,     0,   169,   170,   171,   172,   173,   174,   175,   176,
     154,   177,   155,     0,     0,     0,   156,   157,   158,   159,
     160,   161,     0,     0,     0,     0,     0,   166,     0,     0,
       0,   169,   170,   171,   172,   173,   174,   175,   176,   154,
     177,   155,     0,     0,     0,   156,   157,   158,   159,   160,
     161,     0,     0,     0,     0,     0,     0,    55,    55,    55,
     169,   170,   171,   172,   173,   174,   175,   176,     0,   177,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,    55,   254,    55,    55,     0,    55,   195,
     196,   197,   198,   199,   200,   201,     0,     0,     0,   202,
     203,   204,   205,     0,   206,   207,   208,   209,   210,   211,
     212,   213,     0,     0,     0,   254,     0,     0,     0,     0,
     264,   265,   266,   267,   268,   200,   287,     0,     0,     0,
      55,   269,   270,   271,     0,   272,   273,   288,   289,   290,
     291,   292,   293,    55,    55,     0,     0,    55,    55,    55,
      55,     0,    55,     0,    55,   -97,     0,     0,     0,     0,
     195,   196,   197,   198,   199,   200,   201,     0,     0,    55,
     202,   203,   204,   205,     0,   206,   207,   208,   209,   210,
     211,   212,   213,   264,   265,   266,   267,   268,   200,   287,
       0,     0,     0,     0,   269,   270,   271,     0,   272,   273,
     288,   289,   290,   291,   292,   293,   195,   196,   197,   198,
     199,   200,     0,     0,     0,     0,   202,   203,   204,   205,
       0,   206,   207,   208,   209,   210,   211,   212,   213,   264,
     265,   266,   267,   268,   200,     0,     0,     0,     0,     0,
     269,   270,   271,     0,   272,   273,   288,   289,   290,   291,
     292,   293,   195,   196,   197,   198,   199,   200,     0,     0,
       0,     0,     0,   203,     0,   205,     0,   206,   207,   208,
     209,   210,   211,   212,   213,   195,   196,   197,   198,   199,
     200,     0,     0,     0,     0,     0,   203,     0,     0,     0,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,     0,     0,     0,   221,   195,
     196,   197,   198,   199,   200,   222,   223,   224,   225,   226,
     227,     0,     0,     0,   206,   207,   208,   209,   210,   211,
     212,   213,   274,   275,   276,   277,   278,   279,   294,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   295,
     296,   297,   298,   299,   300
  };

  const short
   Parser ::yycheck_[] =
  {
       8,    42,    10,    11,    12,     8,    32,    64,   768,    11,
       4,     5,   772,     9,   132,     9,     0,     9,    42,     3,
       3,    11,    16,    23,    24,    25,    26,    17,     3,     4,
       5,     6,     7,     8,     9,    29,    11,    12,    11,    41,
      11,    16,     3,     4,     5,     6,     7,     8,     9,    24,
      11,     9,     9,     9,    29,    16,     3,   750,   751,     9,
      60,    11,    74,    24,     9,    67,     9,    14,    29,    11,
      10,    79,    80,    56,    11,   744,   745,    85,    74,    10,
      74,    75,    74,    91,    92,    68,    69,    70,    71,    11,
      11,    74,   100,    74,    67,   855,    67,    42,   124,    74,
      75,   101,    39,   103,   112,   105,   114,   107,    74,    56,
     803,   119,   120,    74,    75,   115,    74,    74,    74,   788,
      74,    68,    69,    70,    71,    67,     3,    74,    68,    69,
      70,    71,    74,     3,    74,    74,    13,    68,    69,    70,
      71,     0,    12,    74,     9,    67,    67,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
      40,   179,   180,   181,   182,   183,   184,   185,     9,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     8,   354,     3,    67,     3,
      10,     9,   250,   243,    42,    10,    12,    10,    10,    13,
      11,    11,    38,    10,    40,    10,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,    40,    40,    40,    40,   284,    40,    40,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,    67,    67,   316,   317,
     318,   319,   320,    68,    69,    70,    71,     0,    42,    74,
       3,    97,    32,    33,    36,     9,    12,   100,   328,    11,
     356,    13,    11,    14,   342,    47,    48,    49,    50,   112,
      13,   114,    61,     9,     9,    11,   119,   120,    12,    15,
      16,    17,    18,    19,    20,    41,    12,    39,    39,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      22,    54,    55,    39,     8,     9,    12,    41,    32,    33,
      32,    33,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,    41,   179,   180,   181,   182,
     183,   184,   185,    10,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    41,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     246,    12,     9,    41,    11,    13,    12,   250,    12,    12,
      11,    74,    13,    20,     4,     5,     6,     7,     8,     9,
      12,    11,    12,    17,    18,    19,    16,    14,     4,     5,
      41,     4,    39,     9,    24,    41,     9,    41,    39,    29,
      16,    10,     9,    16,    68,    69,    70,    71,    10,    41,
      74,    41,    11,    29,     0,     1,    29,     3,     4,     5,
       6,     7,     8,     9,    11,    11,    67,    20,    20,    25,
      16,     0,    20,    74,    12,    10,    32,    33,    24,     8,
       9,    11,    11,    29,    74,    75,    21,    22,    23,    21,
      19,    10,    12,    25,   340,   341,     8,    32,    33,   342,
      32,    33,    74,    32,    34,    35,    36,    37,    14,   636,
      56,    57,    58,    42,    60,    61,    62,    63,    64,    65,
      66,   100,    68,    69,    70,    71,    72,    73,    74,    75,
       3,    42,    21,   112,     4,     5,     6,     7,     8,     9,
     119,    11,    12,    32,    33,    74,    16,    22,    23,     3,
      25,    10,    10,    10,    24,    42,    85,    32,    33,    29,
       4,     5,     6,     7,     8,     9,    21,    11,    12,    11,
      25,    41,    16,    15,    16,    17,   155,    32,    33,     9,
      24,    11,    21,    22,    23,    29,    25,    17,    18,    19,
      20,    25,    10,    32,    33,   124,    10,    41,    32,    33,
     179,   130,    10,   132,    74,    75,    42,   136,    14,    39,
      12,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     3,   154,    21,    22,    23,    11,
      74,    75,    25,   162,    10,    59,   165,    32,    33,    32,
      33,    10,   171,   172,   173,   174,   175,   176,    12,   228,
      32,    33,    34,    35,    36,    37,    12,   768,   187,    22,
      23,   772,   191,   757,    38,   743,   744,   745,    40,    32,
      33,   250,   201,   769,   768,    12,    11,    39,   772,   749,
      15,    16,    17,   761,    22,   322,   764,    25,   782,    62,
      25,   220,   637,   763,    32,    33,    97,    32,    33,   140,
     229,   230,   231,   232,   233,   234,   235,   236,   237,    74,
     788,   875,   806,    -1,   779,   788,    11,    -1,   829,   830,
      -1,    -1,   833,   834,   835,   836,    21,    -1,    -1,    -1,
      25,   825,   261,    -1,   812,    -1,   814,    32,    33,    34,
      35,    36,    37,    -1,   855,    -1,    -1,    15,    16,    17,
      18,    19,    20,   831,   832,   284,    -1,    -1,   287,    -1,
      -1,   855,    -1,   342,    -1,   294,    34,    35,    36,    37,
      -1,   849,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,    15,    16,    17,    18,    19,
      11,   637,   321,    11,    15,    16,    17,    -1,   327,   877,
      -1,     4,     5,     6,     7,     8,     9,    25,    11,    12,
      -1,    32,    33,    16,    32,    33,    34,    35,    36,    37,
      -1,    24,    -1,    -1,    -1,   354,    29,   356,     4,     5,
       6,     7,     8,     9,    -1,    11,     9,    -1,    11,    -1,
      16,    -1,    15,    16,    17,    18,    19,    20,    24,    -1,
      -1,     0,    -1,    29,    -1,    -1,    -1,    30,    31,     8,
       9,    10,    11,    10,    11,    41,    39,    -1,    -1,    10,
      19,    74,    75,    -1,    21,    -1,    -1,    -1,    25,    -1,
      21,    22,    23,    32,    25,    32,    33,    34,    35,    36,
      37,    32,    33,    42,    17,    18,    19,    20,    74,    75,
     743,   744,   745,    -1,   750,   751,    -1,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,   761,    16,
      -1,   764,    -1,    -1,    -1,    74,    -1,    24,    -1,    -1,
      79,    80,    29,   779,    10,    -1,    85,    -1,    -1,    15,
      16,    17,    18,    19,    20,   788,    -1,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    13,   803,    -1,    16,
     830,   807,    -1,   833,   834,   835,   836,    24,    -1,   812,
      -1,   814,    29,    -1,    -1,   124,    -1,    74,    75,    -1,
      -1,   130,    -1,   132,    -1,    -1,    -1,   136,   831,   832,
      -1,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,   154,   849,   156,   157,   158,
     159,   160,   161,   162,    -1,    -1,    -1,    74,    75,    -1,
      -1,    -1,   171,   172,   173,   174,   175,   176,    15,    16,
      17,    18,    19,    20,   877,    -1,    -1,    -1,   187,    26,
      27,    28,   191,    30,    31,    -1,   195,   196,   197,   198,
     199,   200,   201,    15,    16,    17,    18,    19,    20,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,   222,   223,   224,   225,   226,   227,    -1,
     229,    -1,    -1,     9,    -1,    11,    -1,    -1,   237,    15,
      16,    17,    18,    19,    20,    68,    69,    70,    71,    -1,
      -1,    74,    75,    -1,    30,    31,    -1,   636,    34,    35,
      36,    37,   261,    39,   643,   264,   265,   266,   267,   268,
      17,    18,    19,    20,    -1,   274,   275,   276,   277,   278,
     279,    17,    18,    19,    20,   284,    -1,    -1,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,    15,    16,    17,    18,    19,
      20,    -1,   321,    17,    18,    19,    20,    -1,   327,    -1,
      30,    31,   761,    -1,    -1,   764,     4,     5,     6,     7,
       8,     9,    25,    11,    12,    -1,    -1,    -1,    16,    32,
      33,    34,    35,    36,    37,   354,    24,   356,    -1,     0,
      -1,    29,    -1,    -1,   743,   744,   745,     8,     9,    -1,
      11,    15,    16,    17,    18,    19,    -1,    -1,    19,    -1,
      -1,    -1,    26,   812,    28,   814,    30,    31,    -1,   768,
     769,    32,   771,   772,    -1,   774,    34,    35,    36,    37,
      -1,    42,   831,   832,    -1,    -1,    74,    75,    -1,   788,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
     849,    -1,    16,    15,    16,    17,    18,    19,    -1,    -1,
      24,    -1,    -1,    74,    26,    29,    -1,   816,    30,    31,
      -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,   877,    -1,
     829,   830,    -1,    -1,   833,   834,   835,   836,    -1,   838,
      -1,   840,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    -1,    -1,    16,    -1,   855,    -1,    -1,    -1,
      74,    75,    24,   124,    -1,    -1,    -1,    29,    -1,   130,
      -1,   132,    -1,    -1,    -1,   136,    -1,    -1,    -1,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,   154,    15,    16,    17,    18,    19,    20,
      -1,   162,   163,   164,    15,    16,    17,    18,    19,    20,
     171,   172,    74,    75,    -1,    -1,    -1,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,   187,    -1,    -1,    16,
     191,     4,     5,     6,     7,     8,     9,    24,    -1,    -1,
     201,     0,    29,    16,     3,     4,     5,     6,     7,     8,
       9,    24,    11,    -1,    -1,    -1,    29,    16,    -1,   220,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,   229,    -1,
      29,    -1,    -1,    -1,    -1,    -1,   237,   238,   239,    21,
     241,   242,    -1,    25,    -1,    -1,    -1,    74,    75,    -1,
      32,    33,    34,    35,    36,    37,    -1,    56,    57,    58,
     261,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,   636,    -1,    -1,
      -1,    -1,    -1,   284,   643,    -1,   287,    32,    33,    34,
      35,    36,    37,   294,    -1,    -1,    -1,    -1,    -1,    -1,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,     4,     5,     6,     7,     8,     9,    -1,
     321,    -1,    -1,    -1,    -1,    16,   327,     4,     5,     6,
       7,     8,     9,    24,    11,    -1,    -1,    -1,    29,    16,
      -1,    15,    16,    17,    18,    19,    20,    24,    -1,    10,
      -1,    -1,    29,   354,    -1,   356,    30,    31,    -1,     0,
      21,    -1,    -1,    -1,    25,    -1,    -1,    -1,     9,    -1,
      11,    32,    33,    34,    35,    36,    37,    -1,    19,    -1,
      -1,    -1,    -1,    -1,   743,   744,   745,    10,    -1,    -1,
      -1,    32,    15,    16,    17,    18,    19,    74,    75,    -1,
      -1,    42,    -1,    26,    27,    28,    -1,    30,    31,   768,
     769,    -1,   771,   772,    -1,   774,     4,     5,     6,     7,
       8,     9,    -1,    11,    -1,    -1,    -1,    -1,    16,   788,
      -1,    -1,    -1,    74,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    85,    -1,    -1,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    -1,   816,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
     829,   830,    29,    -1,   833,   834,   835,   836,    -1,   838,
      -1,   840,    -1,   124,    -1,    -1,    74,    75,    -1,   130,
      -1,   132,    -1,    -1,    -1,   136,   855,    -1,    -1,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,   154,    -1,    -1,    -1,    74,    75,    -1,
      -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     171,   172,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    -1,    13,    -1,    -1,    16,   187,    -1,   189,   190,
     191,    -1,    -1,    24,    -1,    -1,    10,     9,    29,    -1,
     201,    15,    16,    17,    18,    19,    20,    19,    -1,    -1,
      -1,    -1,    26,    27,    28,    -1,    30,    31,    -1,   220,
      -1,    29,    30,    -1,    -1,    56,    57,    58,   229,    60,
      61,    62,    63,    64,    65,    66,   237,    68,    69,    70,
      71,    72,    73,    74,    75,    53,     4,     5,     6,     7,
       8,     9,    -1,    11,    -1,    -1,    64,    -1,    16,    67,
     261,    -1,    74,    -1,    -1,    -1,    24,    -1,    76,    -1,
      -1,    29,    -1,    -1,    -1,   636,    15,    16,    17,    18,
      19,    20,   643,   284,   285,   286,   287,    -1,    -1,    -1,
      -1,    30,    31,   294,    -1,    34,    35,    36,    37,    -1,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,    -1,    -1,    -1,    74,    75,   130,    -1,
     321,    -1,    -1,    -1,   136,    -1,   327,    -1,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   354,    -1,   356,     0,    -1,    -1,    15,
      16,    17,    18,    19,    20,     9,    -1,    -1,    -1,    25,
      15,    16,    17,    18,    19,    19,    32,    33,    34,    35,
      36,    37,   743,   744,   745,    30,    31,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   768,   769,    -1,
     771,   772,    -1,   774,    -1,     9,    -1,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,   788,    22,    23,
      74,    25,    26,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    39,    -1,    -1,    -1,   261,
      -1,    -1,    -1,    -1,    -1,   816,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   829,   830,
      -1,    -1,   833,   834,   835,   836,    -1,   838,    -1,   840,
     124,    -1,    -1,    -1,    -1,    -1,   130,    -1,   132,    -1,
      -1,    -1,   136,    -1,   855,    -1,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   321,
     154,    -1,   156,   157,   158,   327,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,   172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,   183,
     184,   185,    -1,    -1,   188,    -1,    -1,    -1,   192,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
     378,    54,    55,    -1,   382,    -1,    -1,   221,   386,    -1,
      -1,     9,    10,    11,    -1,    -1,   230,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   240,    25,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    39,    -1,   421,    -1,    -1,    -1,   261,    -1,    -1,
      -1,   429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   636,    -1,    -1,    -1,    -1,
      -1,    -1,   643,    -1,    -1,    -1,    -1,   455,    -1,   457,
      -1,   459,    -1,   461,     0,   463,    -1,   465,    -1,    -1,
      -1,    -1,    -1,     9,    -1,    -1,   474,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    -1,    -1,    -1,   321,    -1,   487,
      -1,    -1,    -1,   327,    -1,    -1,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,     9,    -1,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,   517,
     354,    -1,   356,    25,    26,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    39,    74,     9,
      -1,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,   743,   744,   745,    -1,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    39,
      -1,    -1,    -1,    -1,   572,    -1,    -1,   768,   769,    -1,
     771,   772,    -1,   774,    -1,    -1,    -1,    -1,   124,    -1,
      -1,    -1,    -1,    -1,   130,    -1,   132,    -1,    -1,    -1,
     136,    -1,   600,    -1,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,   816,   162,    -1,   626,    -1,
      -1,    -1,    -1,    -1,   636,   171,   172,    -1,   829,   830,
      -1,   643,   833,   834,   835,   836,    -1,   838,    -1,   840,
      -1,   187,    -1,    -1,    -1,   191,    -1,   193,   194,    -1,
      -1,    -1,    -1,    10,   855,   201,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    -1,   220,    32,    33,    34,    35,    36,
      37,    -1,     1,   229,     3,     4,     5,     6,     7,     8,
       9,   237,    11,    -1,    -1,    14,    -1,    16,    -1,    15,
      16,    17,    18,    19,    20,    24,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    -1,   261,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   743,   744,   745,    -1,    -1,    -1,    56,    57,    58,
      -1,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,   771,
      -1,    -1,   774,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   321,    -1,    -1,    -1,    -1,
      -1,   327,    -1,     1,    -1,     3,     4,     5,     6,     7,
       8,     9,   636,    11,    -1,    -1,    14,    -1,    16,   643,
      -1,    -1,    -1,    -1,   816,    -1,    24,    10,   354,    -1,
     356,    29,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   838,    -1,   840,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    56,    57,
      58,    -1,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    25,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      -1,    -1,    14,    -1,    16,    -1,    -1,    -1,    -1,   743,
     744,   745,    24,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   768,   769,    -1,   771,   772,    -1,
     774,    -1,    -1,    -1,    56,    57,    58,    -1,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    -1,    -1,    -1,    -1,    16,    -1,
      -1,    -1,   816,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,   829,   830,    -1,    -1,   833,
     834,   835,   836,    -1,   838,    -1,   840,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,   855,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,     9,    10,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,     9,    39,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    25,    26,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    39,    -1,    -1,
     636,    -1,     9,    -1,    11,    -1,    -1,   643,    15,    16,
      17,    18,    19,    20,    -1,    22,    -1,    -1,    25,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,     9,    39,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,    -1,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
       9,    39,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,     9,
      39,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,   743,   744,   745,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   768,   769,    10,   771,   772,    -1,   774,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    25,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
     816,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,   829,   830,    -1,    -1,   833,   834,   835,
     836,    -1,   838,    -1,   840,    10,    -1,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,   855,
      25,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    26,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    25,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    25,    15,
      16,    17,    18,    19,    20,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    37
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     0,     3,     4,     5,     6,     7,     8,     9,    11,
      16,    24,    29,    56,    57,    58,    60,    61,    62,    63,
      64,    65,    66,    68,    69,    70,    71,    72,    73,    74,
      75,    78,    79,    81,    82,    86,    88,    89,    90,    91,
      92,    93,    94,    95,    97,    99,   102,   105,   106,   107,
     109,   110,   111,   113,   117,   118,   121,   122,   123,   124,
     125,   127,   129,     8,    74,   110,   111,   113,   117,   118,
     121,   122,   123,   124,     3,    12,    74,   109,   112,     9,
      16,    74,    75,   121,   122,     9,   117,   121,   122,   123,
     124,     9,    16,   121,    74,    74,    87,     9,   109,    74,
      11,    67,   128,    67,   128,    67,   128,    67,   128,    74,
      74,   103,    11,    13,    39,    67,   116,   119,   128,    11,
      39,   116,     0,     0,     1,    81,     0,     3,    80,    80,
       9,     3,    13,    82,    83,    85,     9,    80,    80,    80,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    54,    55,    80,     9,    11,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    25,    26,    27,    28,    30,
      31,    32,    33,    34,    35,    36,    37,    39,   116,    11,
      15,    16,    17,    25,    32,    33,   116,    21,    25,    32,
      33,    21,    25,    32,    33,    15,    16,    17,    18,    19,
      20,    21,    25,    26,    27,    28,    30,    31,    32,    33,
      34,    35,    36,    37,    15,    16,    17,    18,    19,    20,
      21,    25,    32,    33,    34,    35,    36,    37,    11,    21,
      25,    32,    33,    34,    35,    36,    37,    21,    22,    23,
      25,    32,    33,    67,   128,    67,     9,    74,   103,    10,
      11,   119,    10,    10,    10,    10,    10,    10,   112,     3,
      12,    40,   121,   122,    15,    16,    17,    18,    19,    26,
      27,    28,    30,    31,    15,    16,    17,    18,    19,    20,
     121,   122,   123,   124,    21,    32,    33,    21,    32,    33,
      34,    35,    36,    37,    21,    32,    33,    34,    35,    36,
      37,    21,    25,    32,    33,    34,    35,    36,    37,    21,
      22,    23,    32,    33,   121,   121,    15,    16,    17,    18,
      19,    42,    40,    74,    75,   105,   129,    42,    12,   110,
     115,   121,   122,   123,   124,   128,   128,   128,   128,     3,
      13,     9,    41,   115,    14,    39,   120,   110,   121,   128,
     115,   110,    81,   109,    13,    14,    79,    61,   109,   107,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,    10,   108,   109,   115,   110,   113,   121,
     122,   110,   113,   121,   122,   110,   113,   121,   122,   110,
     121,   122,   110,   121,   122,   110,   122,   110,   117,   118,
     121,   122,   123,   124,   110,   124,   110,   124,   110,   123,
     110,   121,   110,   121,   110,   121,   110,   121,   110,   121,
     110,   113,   117,   118,   121,   122,   123,   124,   110,   113,
     117,   118,   121,   122,   123,   124,   110,   121,   122,   123,
     110,   121,   122,   123,   110,   121,   122,   123,   110,   121,
     122,   123,   110,   115,   110,   113,   110,   113,   110,   113,
     110,   113,   110,   113,   110,   113,   110,   117,   118,   121,
     122,   123,   124,   110,   113,   110,   117,   110,   117,   110,
     117,   118,   121,   122,   123,   124,   110,   113,   110,   118,
     110,   118,   110,   121,   122,   110,   121,   122,   110,   121,
     122,   110,   121,   122,   110,   121,   122,   121,   122,   110,
     117,   118,   121,   122,   123,   124,   110,   113,   110,   121,
     110,   121,   110,   121,   110,   121,   110,   121,   110,   121,
     122,   110,   121,   122,   110,   121,   122,   110,   121,   122,
     110,   121,   122,   110,   121,   122,   110,   121,   122,   110,
     121,   122,   110,   121,   122,   110,   121,   122,   110,   121,
     122,   110,   121,   122,   110,   117,   118,   121,   122,   123,
     124,   110,   113,   110,   121,   122,   110,   121,   122,   110,
     121,   122,   110,   121,   122,   110,   121,   122,   110,   121,
     122,   115,   110,   117,   118,   121,   122,   123,   124,   110,
     113,   123,   110,   123,   110,   123,   110,   123,   110,   123,
     110,   123,   110,   123,   110,   117,   118,   121,   122,   123,
     124,   110,   124,   110,   124,   110,   113,   110,   124,   110,
     124,   128,    10,    74,   126,   129,    42,     9,   115,    10,
       3,    12,    12,     3,   109,   121,   122,   121,   122,   121,
     122,   121,   122,   121,   122,   121,   121,   121,   121,   121,
     121,   122,   121,   122,   121,   122,   121,   122,   121,   122,
     121,   122,   117,   121,   122,   123,   124,     9,   117,   117,
     117,   121,   122,   123,   124,   121,   122,   121,   122,   121,
     122,   121,   122,   121,   122,   121,   122,   117,   121,   122,
     123,   124,   121,   122,   121,   122,   121,   122,   121,   122,
     121,   122,   121,   122,   117,   121,   122,   123,   124,   123,
     124,   123,   123,   123,   123,   123,   123,   117,   121,   122,
     123,   124,   124,   124,   124,   124,   121,   121,   121,   121,
     121,   109,    87,    41,    41,    41,    74,   109,   128,    12,
      13,     3,    14,    56,   100,   101,   129,    10,   104,   129,
      12,    41,   115,    12,    41,    74,    14,    12,    10,    79,
      14,     9,    10,    10,    40,    12,    12,    12,    10,    40,
     109,   119,    10,   104,    12,    12,   109,     8,     9,   109,
     110,   114,   115,   121,   109,   114,   109,   114,   128,   100,
     100,    74,    14,     3,    74,    83,    10,    40,    74,    12,
     115,    12,    41,    12,    41,   115,    42,    85,    14,     3,
     109,    85,   109,   126,    83,    10,   110,   114,   121,    10,
      10,    38,    40,    10,    10,    10,    10,    14,    42,   100,
      42,    83,   129,    12,    12,   115,    12,   115,    12,    41,
     109,     3,    10,    59,    96,    98,    83,    10,    82,    83,
      84,    84,   115,   115,    84,    84,    84,    84,   109,   109,
      74,    12,    12,    12,   115,    40,    85,    38,    12,   120,
     115
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
     104,   104,   105,   106,   106,   106,   106,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   108,   108,   109,   109,   109,   109,   109,   109,   109,
     109,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     111,   111,   111,   111,   111,   112,   112,   112,   113,   113,
     114,   114,   114,   115,   115,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   117,   117,   118,
     118,   119,   119,   120,   120,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   125,   125,   126,
     126,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   128,   128,   128,   128,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129
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
       2,     4,     2,     4,     4,     4,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     3,     4,     4,     4,
       4,     4,     4,     2,     2,     2,     2,     3,     3,     3,
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
       2,     3,     4,     4,     5,     1,     3,     4,     1,     3,
       3,     3,     5,     1,     1,     3,     4,     4,     5,     4,
       5,     5,     5,     6,     6,     6,     7,     1,     3,     2,
       4,     2,     3,     4,     6,     1,     2,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     3,     1,
       3,     2,     2,     2,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     4,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
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
  "\"import\"", "\"if\"", "\"else\"", "\"for\"", "\"while\"", "\"do\"",
  "\"return\"", "\"break\"", "\"continue\"", "\"const\"", "\"?\"",
  "\"'int'\"", "\"'float'\"", "\"'string'\"", "\"'bool'\"", "\"'struct'\"",
  "\"'void'\"", "\"identifier\"", "\"external identifier\"", "NEG",
  "$accept", "start", "stmt", "stmt_end", "stmts", "stmts_ne", "block",
  "body", "scope_body", "import", "id_list", "flowctl", "return", "for",
  "while", "wh_kw", "dowhile", "do_kw", "if", "else", "if_kw", "el_kw",
  "struct", "decllist", "declistval", "function", "fun_id", "funargs",
  "vardecl", "vardef", "set", "callarglist", "expr", "expr_var", "matrix",
  "matvals", "expr_mat", "range", "int_val", "slice", "expr_none",
  "expr_struct", "struct_val", "struct_list", "expr_int", "expr_float",
  "expr_str", "expr_bool", "funtype", "typelist", "mattype", "matsq",
  "type", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   228,   228,   229,   231,   232,   233,   236,   237,   240,
     241,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   258,   259,   260,   261,   262,   265,   266,
     269,   270,   274,   276,   277,   281,   282,   283,   285,   286,
     290,   291,   292,   293,   294,   295,   299,   301,   303,   305,
     308,   310,   311,   313,   314,   317,   318,   319,   321,   322,
     323,   324,   326,   327,   328,   332,   333,   334,   335,   337,
     339,   341,   348,   352,   353,   354,   355,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   376,   377,   381,   382,   383,   384,   385,   386,   387,
     388,   391,   392,   393,   394,   395,   397,   398,   400,   401,
     402,   403,   404,   406,   407,   408,   409,   411,   412,   413,
     415,   416,   417,   419,   420,   421,   422,   423,   424,   425,
     426,   428,   429,   430,   431,   432,   434,   435,   436,   437,
     438,   440,   441,   442,   443,   444,   445,   446,   447,   449,
     450,   451,   452,   453,   454,   455,   456,   458,   459,   460,
     462,   463,   464,   466,   467,   468,   469,   470,   471,   472,
     474,   475,   476,   477,   478,   479,   480,   482,   483,   484,
     485,   486,   487,   488,   490,   491,   492,   493,   494,   495,
     496,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   534,   535,   536,   538,   539,
     540,   542,   543,   544,   546,   547,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     563,   564,   565,   567,   568,   569,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     598,   599,   600,   601,   602,   605,   606,   607,   611,   612,
     614,   615,   616,   618,   619,   621,   622,   623,   624,   625,
     626,   627,   628,   629,   630,   631,   632,   636,   637,   641,
     642,   644,   645,   647,   648,   652,   653,   654,   655,   656,
     657,   658,   659,   660,   661,   662,   663,   664,   665,   669,
     670,   671,   672,   673,   674,   675,   676,   677,   678,   679,
     680,   681,   682,   683,   684,   685,   686,   687,   688,   689,
     693,   694,   695,   696,   697,   698,   699,   700,   701,   702,
     703,   704,   705,   706,   707,   708,   709,   710,   711,   712,
     713,   714,   715,   716,   717,   718,   719,   723,   724,   725,
     726,   727,   729,   730,   731,   732,   733,   734,   735,   737,
     738,   739,   740,   741,   742,   743,   745,   746,   747,   748,
     749,   751,   752,   753,   754,   755,   757,   758,   759,   760,
     761,   763,   764,   765,   766,   767,   769,   773,   774,   776,
     777,   781,   782,   783,   784,   785,   786,   787,   788,   789,
     790,   791,   792,   794,   795,   796,   797,   801,   802,   803,
     804,   805,   806,   807,   808,   809,   810,   811,   812,   813,
     814
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
#line 4983 "frontend/parser.cpp"

#line 817 "frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    auto msg = std::to_string(scanner->loc->begin.line) + ":" + std::to_string(scanner->loc->begin.column) + ": " + err_message;
    scanner->fatal_error(ptc::diag::ERR_SYNTAX, msg);
}
