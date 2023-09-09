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
#line 227 "frontend/parser.yy"
                        { scanner->parseEntry(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1161 "frontend/parser.cpp"
    break;

  case 4: // stmt: stmts
#line 229 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1167 "frontend/parser.cpp"
    break;

  case 5: // stmt: stmt stmts
#line 230 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1173 "frontend/parser.cpp"
    break;

  case 6: // stmt: stmt error stmts
#line 231 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1179 "frontend/parser.cpp"
    break;

  case 9: // stmts: "terminator (\\n or ;)"
#line 238 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = nullptr; }
#line 1185 "frontend/parser.cpp"
    break;

  case 10: // stmts: stmts_ne
#line 239 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1191 "frontend/parser.cpp"
    break;

  case 11: // stmts_ne: set stmt_end
#line 241 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1197 "frontend/parser.cpp"
    break;

  case 12: // stmts_ne: vardecl stmt_end
#line 242 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1203 "frontend/parser.cpp"
    break;

  case 13: // stmts_ne: vardef stmt_end
#line 243 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1209 "frontend/parser.cpp"
    break;

  case 14: // stmts_ne: import stmt_end
#line 244 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1215 "frontend/parser.cpp"
    break;

  case 15: // stmts_ne: for
#line 245 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1221 "frontend/parser.cpp"
    break;

  case 16: // stmts_ne: if
#line 246 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1227 "frontend/parser.cpp"
    break;

  case 17: // stmts_ne: while
#line 247 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1233 "frontend/parser.cpp"
    break;

  case 18: // stmts_ne: dowhile
#line 248 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1239 "frontend/parser.cpp"
    break;

  case 19: // stmts_ne: struct
#line 249 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1245 "frontend/parser.cpp"
    break;

  case 20: // stmts_ne: function
#line 250 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1251 "frontend/parser.cpp"
    break;

  case 21: // stmts_ne: flowctl stmt_end
#line 251 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1257 "frontend/parser.cpp"
    break;

  case 22: // stmts_ne: expr stmt_end
#line 252 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1263 "frontend/parser.cpp"
    break;

  case 23: // block: "{" "}"
#line 256 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1269 "frontend/parser.cpp"
    break;

  case 24: // block: "{" stmt "}"
#line 257 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1275 "frontend/parser.cpp"
    break;

  case 25: // block: "terminator (\\n or ;)" "{" stmt "}"
#line 258 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1281 "frontend/parser.cpp"
    break;

  case 26: // block: "{" stmt "}" "terminator (\\n or ;)"
#line 259 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1287 "frontend/parser.cpp"
    break;

  case 27: // block: "terminator (\\n or ;)" "{" stmt "}" "terminator (\\n or ;)"
#line 260 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1293 "frontend/parser.cpp"
    break;

  case 28: // body: stmts_ne
#line 263 "frontend/parser.yy"
                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1299 "frontend/parser.cpp"
    break;

  case 29: // body: block
#line 264 "frontend/parser.yy"
                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1305 "frontend/parser.cpp"
    break;

  case 30: // scope_body: stmts_ne
#line 267 "frontend/parser.yy"
                      { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); scanner->leaveScope(); }
#line 1311 "frontend/parser.cpp"
    break;

  case 31: // scope_body: block
#line 268 "frontend/parser.yy"
                      { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); scanner->leaveScope(); }
#line 1317 "frontend/parser.cpp"
    break;

  case 32: // import: "import" id_list
#line 272 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::IR * > () = scanner->parseImports(yystack_[0].value.as < std::vector<std::string>  > ()); }
#line 1323 "frontend/parser.cpp"
    break;

  case 33: // id_list: "identifier"
#line 274 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseImportName(yystack_[0].value.as < std::string > ()); }
#line 1329 "frontend/parser.cpp"
    break;

  case 34: // id_list: "identifier" "," id_list
#line 275 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseAddImportName(yystack_[0].value.as < std::vector<std::string>  > (), yystack_[2].value.as < std::string > ()); }
#line 1335 "frontend/parser.cpp"
    break;

  case 35: // flowctl: "break"
#line 279 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseBreak(); }
#line 1341 "frontend/parser.cpp"
    break;

  case 36: // flowctl: "continue"
#line 280 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseContinue(); }
#line 1347 "frontend/parser.cpp"
    break;

  case 37: // flowctl: return
#line 281 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1353 "frontend/parser.cpp"
    break;

  case 38: // return: "return"
#line 283 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(nullptr); }
#line 1359 "frontend/parser.cpp"
    break;

  case 39: // return: "return" expr
#line 284 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1365 "frontend/parser.cpp"
    break;

  case 40: // for: "for" "(" vardecl ":" expr ")" body
#line 288 "frontend/parser.yy"
                                              { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1371 "frontend/parser.cpp"
    break;

  case 41: // for: "for" "(" "external identifier" ":" expr ")" body
#line 289 "frontend/parser.yy"
                                              { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1377 "frontend/parser.cpp"
    break;

  case 42: // while: wh_kw "(" expr ")" scope_body
#line 293 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseWhile(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1383 "frontend/parser.cpp"
    break;

  case 43: // wh_kw: "while"
#line 295 "frontend/parser.yy"
                { scanner->enterBlockScope(); }
#line 1389 "frontend/parser.cpp"
    break;

  case 44: // dowhile: do_kw scope_body "while" "(" expr ")"
#line 297 "frontend/parser.yy"
                                                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseDoWhile(yystack_[1].value.as < ptc::ir::Expr * > (), yystack_[4].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1395 "frontend/parser.cpp"
    break;

  case 45: // do_kw: "do"
#line 299 "frontend/parser.yy"
             { scanner->enterBlockScope(); }
#line 1401 "frontend/parser.cpp"
    break;

  case 46: // if: if_kw "(" expr ")" scope_body else
#line 302 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseIfStmt(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1407 "frontend/parser.cpp"
    break;

  case 47: // else: el_kw scope_body
#line 304 "frontend/parser.yy"
                         { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1413 "frontend/parser.cpp"
    break;

  case 48: // else: %empty
#line 305 "frontend/parser.yy"
                    { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1419 "frontend/parser.cpp"
    break;

  case 49: // if_kw: "if"
#line 307 "frontend/parser.yy"
             { scanner->enterBlockScope(); }
#line 1425 "frontend/parser.cpp"
    break;

  case 50: // el_kw: "else"
#line 308 "frontend/parser.yy"
               { scanner->enterBlockScope(); }
#line 1431 "frontend/parser.cpp"
    break;

  case 51: // struct: "'struct'" "identifier" "{" "}"
#line 311 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[2].value.as < std::string > (), std::vector<ptc::ir::IR *>{}); }
#line 1437 "frontend/parser.cpp"
    break;

  case 52: // struct: "'struct'" "identifier" "{" decllist "}"
#line 312 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1443 "frontend/parser.cpp"
    break;

  case 53: // struct: "'struct'" "identifier" "terminator (\\n or ;)" "{" decllist "}"
#line 313 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[4].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1449 "frontend/parser.cpp"
    break;

  case 55: // decllist: "terminator (\\n or ;)" decllist
#line 316 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1455 "frontend/parser.cpp"
    break;

  case 56: // decllist: declistval "terminator (\\n or ;)"
#line 317 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[1].value.as < ptc::ir::IR * > (), std::vector<ptc::ir::IR *>{}); }
#line 1461 "frontend/parser.cpp"
    break;

  case 57: // decllist: declistval "terminator (\\n or ;)" decllist
#line 318 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[2].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1467 "frontend/parser.cpp"
    break;

  case 58: // declistval: type "identifier"
#line 320 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > (), nullptr); }
#line 1473 "frontend/parser.cpp"
    break;

  case 59: // declistval: type "identifier" "=" expr
#line 321 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1479 "frontend/parser.cpp"
    break;

  case 61: // function: type fun_id "(" ")" block
#line 326 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1485 "frontend/parser.cpp"
    break;

  case 62: // function: type fun_id "(" funargs ")" block
#line 327 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[5].value.as < ptc::ir::IR * > (), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1491 "frontend/parser.cpp"
    break;

  case 63: // function: "'void'" fun_id "(" ")" block
#line 328 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1497 "frontend/parser.cpp"
    break;

  case 64: // function: "'void'" fun_id "(" funargs ")" block
#line 329 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1503 "frontend/parser.cpp"
    break;

  case 65: // fun_id: "identifier"
#line 331 "frontend/parser.yy"
            { scanner->enterFunScope(); yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1509 "frontend/parser.cpp"
    break;

  case 66: // funargs: type "identifier"
#line 333 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseFunParam(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1515 "frontend/parser.cpp"
    break;

  case 68: // funargs: funargs "," type "identifier"
#line 335 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseAddFunParam(yystack_[3].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1521 "frontend/parser.cpp"
    break;

  case 71: // vardecl: type "identifier"
#line 342 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1527 "frontend/parser.cpp"
    break;

  case 72: // vardef: type "identifier" "=" struct_val
#line 346 "frontend/parser.yy"
         { yylhs.value.as < ptc::ir::IR * > () = yystack_[3].value.as < ptc::ir::IR * > (); }
#line 1533 "frontend/parser.cpp"
    break;

  case 73: // vardef: type "identifier" "=" expr
#line 347 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1539 "frontend/parser.cpp"
    break;

  case 76: // set: expr "++=" expr
#line 353 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1545 "frontend/parser.cpp"
    break;

  case 77: // set: expr "**=" expr
#line 354 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1551 "frontend/parser.cpp"
    break;

  case 78: // set: expr "%=" expr
#line 355 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1557 "frontend/parser.cpp"
    break;

  case 79: // set: expr "/=" expr
#line 356 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1563 "frontend/parser.cpp"
    break;

  case 80: // set: expr "*=" expr
#line 357 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1569 "frontend/parser.cpp"
    break;

  case 81: // set: expr "-=" expr
#line 358 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1575 "frontend/parser.cpp"
    break;

  case 82: // set: expr "+=" expr
#line 359 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1581 "frontend/parser.cpp"
    break;

  case 83: // set: expr "&=" expr
#line 360 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1587 "frontend/parser.cpp"
    break;

  case 84: // set: expr "|=" expr
#line 361 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1593 "frontend/parser.cpp"
    break;

  case 85: // set: expr "^=" expr
#line 362 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1599 "frontend/parser.cpp"
    break;

  case 86: // set: expr "<<=" expr
#line 363 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1605 "frontend/parser.cpp"
    break;

  case 87: // set: expr ">>=" expr
#line 364 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1611 "frontend/parser.cpp"
    break;

  case 88: // set: expr "=" expr
#line 365 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1617 "frontend/parser.cpp"
    break;

  case 89: // set: expr "=" set
#line 366 "frontend/parser.yy"
      { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1623 "frontend/parser.cpp"
    break;

  case 90: // callarglist: expr
#line 370 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseFunCallArg(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1629 "frontend/parser.cpp"
    break;

  case 91: // callarglist: callarglist "," expr
#line 371 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddFunCallArg(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1635 "frontend/parser.cpp"
    break;

  case 92: // expr: expr_mat
#line 375 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1641 "frontend/parser.cpp"
    break;

  case 93: // expr: expr_var
#line 376 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1647 "frontend/parser.cpp"
    break;

  case 96: // expr: expr_int
#line 379 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 1653 "frontend/parser.cpp"
    break;

  case 97: // expr: expr_float
#line 380 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFloat(yystack_[0].value.as < double > ()); }
#line 1659 "frontend/parser.cpp"
    break;

  case 98: // expr: expr_str
#line 381 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseString(yystack_[0].value.as < std::string > ()); }
#line 1665 "frontend/parser.cpp"
    break;

  case 99: // expr: expr_bool
#line 382 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseBool(yystack_[0].value.as < bool > ()); }
#line 1671 "frontend/parser.cpp"
    break;

  case 100: // expr_var: "identifier"
#line 385 "frontend/parser.yy"
              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > ()); }
#line 1677 "frontend/parser.cpp"
    break;

  case 101: // expr_var: "external identifier"
#line 386 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > (), true); }
#line 1683 "frontend/parser.cpp"
    break;

  case 102: // expr_var: "-" "identifier"
#line 387 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1689 "frontend/parser.cpp"
    break;

  case 103: // expr_var: "-" "external identifier"
#line 388 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > (), true), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1695 "frontend/parser.cpp"
    break;

  case 104: // expr_var: "(" expr_var ")"
#line 389 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1701 "frontend/parser.cpp"
    break;

  case 105: // expr_var: expr_var "(" ")"
#line 391 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[2].value.as < ptc::ir::Expr * > (), std::vector<ptc::ir::Expr *>{}); }
#line 1707 "frontend/parser.cpp"
    break;

  case 106: // expr_var: expr_var "(" callarglist ")"
#line 392 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 1713 "frontend/parser.cpp"
    break;

  case 107: // expr_var: expr_str "[" int_val "]"
#line 394 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1719 "frontend/parser.cpp"
    break;

  case 108: // expr_var: expr_mat "[" int_val "]"
#line 395 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1725 "frontend/parser.cpp"
    break;

  case 109: // expr_var: "identifier" "[" int_val "]"
#line 396 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1731 "frontend/parser.cpp"
    break;

  case 110: // expr_var: "external identifier" "[" int_val "]"
#line 397 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1737 "frontend/parser.cpp"
    break;

  case 111: // expr_var: expr_var "[" int_val "]"
#line 398 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1743 "frontend/parser.cpp"
    break;

  case 112: // expr_var: expr_mat slice
#line 400 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1749 "frontend/parser.cpp"
    break;

  case 115: // expr_var: expr_var slice
#line 403 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1755 "frontend/parser.cpp"
    break;

  case 116: // expr_var: "identifier" "." expr_var
#line 405 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1761 "frontend/parser.cpp"
    break;

  case 117: // expr_var: "external identifier" "." expr_var
#line 406 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1767 "frontend/parser.cpp"
    break;

  case 118: // expr_var: expr_var "." expr_var
#line 407 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1773 "frontend/parser.cpp"
    break;

  case 120: // expr_var: expr_var "**" expr_float
#line 410 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1779 "frontend/parser.cpp"
    break;

  case 121: // expr_var: expr_var "**" expr_var
#line 411 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1785 "frontend/parser.cpp"
    break;

  case 122: // expr_var: expr_int "*" expr_var
#line 413 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1791 "frontend/parser.cpp"
    break;

  case 123: // expr_var: expr_float "*" expr_var
#line 414 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1797 "frontend/parser.cpp"
    break;

  case 124: // expr_var: expr_var "*" expr_int
#line 415 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1803 "frontend/parser.cpp"
    break;

  case 125: // expr_var: expr_var "*" expr_float
#line 416 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1809 "frontend/parser.cpp"
    break;

  case 126: // expr_var: expr_mat "*" expr_mat
#line 417 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1815 "frontend/parser.cpp"
    break;

  case 127: // expr_var: expr_mat "*" expr_var
#line 418 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1821 "frontend/parser.cpp"
    break;

  case 128: // expr_var: expr_var "*" expr_mat
#line 419 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1827 "frontend/parser.cpp"
    break;

  case 129: // expr_var: expr_var "*" expr_var
#line 420 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1833 "frontend/parser.cpp"
    break;

  case 130: // expr_var: expr_int "/" expr_var
#line 422 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1839 "frontend/parser.cpp"
    break;

  case 131: // expr_var: expr_float "/" expr_var
#line 423 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1845 "frontend/parser.cpp"
    break;

  case 132: // expr_var: expr_var "/" expr_int
#line 424 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1851 "frontend/parser.cpp"
    break;

  case 133: // expr_var: expr_var "/" expr_float
#line 425 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1857 "frontend/parser.cpp"
    break;

  case 134: // expr_var: expr_var "/" expr_var
#line 426 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1863 "frontend/parser.cpp"
    break;

  case 135: // expr_var: expr_int "%" expr_var
#line 428 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1869 "frontend/parser.cpp"
    break;

  case 136: // expr_var: expr_float "%" expr_var
#line 429 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1875 "frontend/parser.cpp"
    break;

  case 137: // expr_var: expr_var "%" expr_int
#line 430 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1881 "frontend/parser.cpp"
    break;

  case 138: // expr_var: expr_var "%" expr_float
#line 431 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1887 "frontend/parser.cpp"
    break;

  case 139: // expr_var: expr_var "%" expr_var
#line 432 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1893 "frontend/parser.cpp"
    break;

  case 140: // expr_var: expr_int "+" expr_var
#line 434 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1899 "frontend/parser.cpp"
    break;

  case 141: // expr_var: expr_float "+" expr_var
#line 435 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1905 "frontend/parser.cpp"
    break;

  case 142: // expr_var: expr_var "+" expr_int
#line 436 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1911 "frontend/parser.cpp"
    break;

  case 143: // expr_var: expr_var "+" expr_float
#line 437 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1917 "frontend/parser.cpp"
    break;

  case 144: // expr_var: expr_mat "+" expr_mat
#line 438 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1923 "frontend/parser.cpp"
    break;

  case 145: // expr_var: expr_var "+" expr_mat
#line 439 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1929 "frontend/parser.cpp"
    break;

  case 146: // expr_var: expr_mat "+" expr_var
#line 440 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1935 "frontend/parser.cpp"
    break;

  case 147: // expr_var: expr_var "+" expr_var
#line 441 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1941 "frontend/parser.cpp"
    break;

  case 148: // expr_var: expr_int "-" expr_var
#line 443 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1947 "frontend/parser.cpp"
    break;

  case 149: // expr_var: expr_float "-" expr_var
#line 444 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1953 "frontend/parser.cpp"
    break;

  case 150: // expr_var: expr_var "-" expr_int
#line 445 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1959 "frontend/parser.cpp"
    break;

  case 151: // expr_var: expr_var "-" expr_float
#line 446 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1965 "frontend/parser.cpp"
    break;

  case 152: // expr_var: expr_mat "-" expr_mat
#line 447 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1971 "frontend/parser.cpp"
    break;

  case 153: // expr_var: expr_var "-" expr_mat
#line 448 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1977 "frontend/parser.cpp"
    break;

  case 154: // expr_var: expr_mat "-" expr_var
#line 449 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1983 "frontend/parser.cpp"
    break;

  case 155: // expr_var: expr_var "-" expr_var
#line 450 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1989 "frontend/parser.cpp"
    break;

  case 156: // expr_var: expr_int "<<" expr_var
#line 452 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 1995 "frontend/parser.cpp"
    break;

  case 157: // expr_var: expr_var "<<" expr_int
#line 453 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2001 "frontend/parser.cpp"
    break;

  case 158: // expr_var: expr_var "<<" expr_var
#line 454 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2007 "frontend/parser.cpp"
    break;

  case 159: // expr_var: expr_int ">>" expr_var
#line 456 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2013 "frontend/parser.cpp"
    break;

  case 160: // expr_var: expr_var ">>" expr_int
#line 457 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2019 "frontend/parser.cpp"
    break;

  case 161: // expr_var: expr_var ">>" expr_var
#line 458 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2025 "frontend/parser.cpp"
    break;

  case 162: // expr_var: expr_int ">" expr_var
#line 460 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2031 "frontend/parser.cpp"
    break;

  case 163: // expr_var: expr_float ">" expr_var
#line 461 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2037 "frontend/parser.cpp"
    break;

  case 165: // expr_var: expr_var ">" expr_int
#line 463 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2043 "frontend/parser.cpp"
    break;

  case 166: // expr_var: expr_var ">" expr_float
#line 464 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2049 "frontend/parser.cpp"
    break;

  case 167: // expr_var: expr_var ">" expr_str
#line 465 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2055 "frontend/parser.cpp"
    break;

  case 168: // expr_var: expr_var ">" expr_var
#line 466 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2061 "frontend/parser.cpp"
    break;

  case 169: // expr_var: expr_int ">=" expr_var
#line 468 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2067 "frontend/parser.cpp"
    break;

  case 170: // expr_var: expr_float ">=" expr_var
#line 469 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2073 "frontend/parser.cpp"
    break;

  case 172: // expr_var: expr_var ">=" expr_int
#line 471 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2079 "frontend/parser.cpp"
    break;

  case 173: // expr_var: expr_var ">=" expr_float
#line 472 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2085 "frontend/parser.cpp"
    break;

  case 174: // expr_var: expr_var ">=" expr_str
#line 473 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2091 "frontend/parser.cpp"
    break;

  case 175: // expr_var: expr_var ">=" expr_var
#line 474 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2097 "frontend/parser.cpp"
    break;

  case 176: // expr_var: expr_int "<" expr_var
#line 476 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2103 "frontend/parser.cpp"
    break;

  case 177: // expr_var: expr_float "<" expr_var
#line 477 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2109 "frontend/parser.cpp"
    break;

  case 179: // expr_var: expr_var "<" expr_int
#line 479 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2115 "frontend/parser.cpp"
    break;

  case 180: // expr_var: expr_var "<" expr_float
#line 480 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2121 "frontend/parser.cpp"
    break;

  case 181: // expr_var: expr_var "<" expr_str
#line 481 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2127 "frontend/parser.cpp"
    break;

  case 182: // expr_var: expr_var "<" expr_var
#line 482 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2133 "frontend/parser.cpp"
    break;

  case 183: // expr_var: expr_int "<=" expr_var
#line 484 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2139 "frontend/parser.cpp"
    break;

  case 184: // expr_var: expr_float "<=" expr_var
#line 485 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2145 "frontend/parser.cpp"
    break;

  case 186: // expr_var: expr_var "<=" expr_int
#line 487 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2151 "frontend/parser.cpp"
    break;

  case 187: // expr_var: expr_var "<=" expr_float
#line 488 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2157 "frontend/parser.cpp"
    break;

  case 188: // expr_var: expr_var "<=" expr_str
#line 489 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2163 "frontend/parser.cpp"
    break;

  case 189: // expr_var: expr_var "<=" expr_var
#line 490 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2169 "frontend/parser.cpp"
    break;

  case 190: // expr_var: expr_int "==" expr_var
#line 492 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2175 "frontend/parser.cpp"
    break;

  case 191: // expr_var: expr_float "==" expr_var
#line 493 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2181 "frontend/parser.cpp"
    break;

  case 193: // expr_var: expr_bool "==" expr_var
#line 495 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2187 "frontend/parser.cpp"
    break;

  case 197: // expr_var: expr_var "==" expr_int
#line 499 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2193 "frontend/parser.cpp"
    break;

  case 198: // expr_var: expr_var "==" expr_float
#line 500 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2199 "frontend/parser.cpp"
    break;

  case 199: // expr_var: expr_var "==" expr_str
#line 501 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2205 "frontend/parser.cpp"
    break;

  case 200: // expr_var: expr_var "==" expr_bool
#line 502 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2211 "frontend/parser.cpp"
    break;

  case 201: // expr_var: expr_var "==" expr_none
#line 503 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2217 "frontend/parser.cpp"
    break;

  case 202: // expr_var: expr_var "==" expr_struct
#line 504 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2223 "frontend/parser.cpp"
    break;

  case 203: // expr_var: expr_mat "==" expr_mat
#line 505 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2229 "frontend/parser.cpp"
    break;

  case 204: // expr_var: expr_var "==" expr_mat
#line 506 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2235 "frontend/parser.cpp"
    break;

  case 205: // expr_var: expr_mat "==" expr_var
#line 507 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2241 "frontend/parser.cpp"
    break;

  case 206: // expr_var: expr_var "==" expr_var
#line 508 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2247 "frontend/parser.cpp"
    break;

  case 207: // expr_var: expr_int "!=" expr_var
#line 510 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2253 "frontend/parser.cpp"
    break;

  case 208: // expr_var: expr_float "!=" expr_var
#line 511 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2259 "frontend/parser.cpp"
    break;

  case 214: // expr_var: expr_var "!=" expr_int
#line 517 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2265 "frontend/parser.cpp"
    break;

  case 215: // expr_var: expr_var "!=" expr_float
#line 518 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2271 "frontend/parser.cpp"
    break;

  case 216: // expr_var: expr_var "!=" expr_str
#line 519 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2277 "frontend/parser.cpp"
    break;

  case 217: // expr_var: expr_var "!=" expr_bool
#line 520 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2283 "frontend/parser.cpp"
    break;

  case 218: // expr_var: expr_var "!=" expr_none
#line 521 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2289 "frontend/parser.cpp"
    break;

  case 219: // expr_var: expr_var "!=" expr_struct
#line 522 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2295 "frontend/parser.cpp"
    break;

  case 220: // expr_var: expr_mat "!=" expr_mat
#line 523 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2301 "frontend/parser.cpp"
    break;

  case 221: // expr_var: expr_var "!=" expr_mat
#line 524 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2307 "frontend/parser.cpp"
    break;

  case 222: // expr_var: expr_mat "!=" expr_var
#line 525 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2313 "frontend/parser.cpp"
    break;

  case 223: // expr_var: expr_var "!=" expr_var
#line 526 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2319 "frontend/parser.cpp"
    break;

  case 224: // expr_var: expr_int "&" expr_var
#line 528 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2325 "frontend/parser.cpp"
    break;

  case 225: // expr_var: expr_var "&" expr_int
#line 529 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2331 "frontend/parser.cpp"
    break;

  case 226: // expr_var: expr_var "&" expr_var
#line 530 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2337 "frontend/parser.cpp"
    break;

  case 227: // expr_var: expr_int "^" expr_var
#line 532 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2343 "frontend/parser.cpp"
    break;

  case 228: // expr_var: expr_var "^" expr_int
#line 533 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2349 "frontend/parser.cpp"
    break;

  case 229: // expr_var: expr_var "^" expr_var
#line 534 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2355 "frontend/parser.cpp"
    break;

  case 230: // expr_var: expr_int "|" expr_var
#line 536 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2361 "frontend/parser.cpp"
    break;

  case 231: // expr_var: expr_var "|" expr_int
#line 537 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2367 "frontend/parser.cpp"
    break;

  case 232: // expr_var: expr_var "|" expr_var
#line 538 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2373 "frontend/parser.cpp"
    break;

  case 239: // expr_var: expr_mat "in" expr_mat
#line 546 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2379 "frontend/parser.cpp"
    break;

  case 246: // expr_var: expr_mat "in" expr_var
#line 553 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2385 "frontend/parser.cpp"
    break;

  case 247: // expr_var: expr_var "in" expr_str
#line 554 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2391 "frontend/parser.cpp"
    break;

  case 248: // expr_var: expr_var "in" expr_var
#line 555 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2397 "frontend/parser.cpp"
    break;

  case 249: // expr_var: expr_bool "and" expr_var
#line 557 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2403 "frontend/parser.cpp"
    break;

  case 250: // expr_var: expr_var "and" expr_bool
#line 558 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2409 "frontend/parser.cpp"
    break;

  case 251: // expr_var: expr_var "and" expr_var
#line 559 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2415 "frontend/parser.cpp"
    break;

  case 252: // expr_var: expr_bool "or" expr_var
#line 561 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2421 "frontend/parser.cpp"
    break;

  case 253: // expr_var: expr_var "or" expr_bool
#line 562 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2427 "frontend/parser.cpp"
    break;

  case 254: // expr_var: expr_var "or" expr_var
#line 563 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2433 "frontend/parser.cpp"
    break;

  case 266: // expr_var: expr_int "++" expr_var
#line 576 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2439 "frontend/parser.cpp"
    break;

  case 267: // expr_var: expr_float "++" expr_var
#line 577 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2445 "frontend/parser.cpp"
    break;

  case 268: // expr_var: expr_str "++" expr_var
#line 578 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2451 "frontend/parser.cpp"
    break;

  case 269: // expr_var: expr_bool "++" expr_var
#line 579 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2457 "frontend/parser.cpp"
    break;

  case 272: // expr_var: expr_var "++" expr_int
#line 582 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2463 "frontend/parser.cpp"
    break;

  case 273: // expr_var: expr_var "++" expr_float
#line 583 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2469 "frontend/parser.cpp"
    break;

  case 274: // expr_var: expr_var "++" expr_str
#line 584 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2475 "frontend/parser.cpp"
    break;

  case 275: // expr_var: expr_var "++" expr_bool
#line 585 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2481 "frontend/parser.cpp"
    break;

  case 276: // expr_var: expr_var "++" expr_none
#line 586 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2487 "frontend/parser.cpp"
    break;

  case 277: // expr_var: expr_var "++" expr_struct
#line 587 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2493 "frontend/parser.cpp"
    break;

  case 278: // expr_var: expr_var "++" expr_var
#line 588 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2499 "frontend/parser.cpp"
    break;

  case 279: // matrix: "[" "]"
#line 592 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(std::vector<ptc::ir::Expr *>{}); }
#line 2505 "frontend/parser.cpp"
    break;

  case 280: // matrix: "[" matvals "]"
#line 593 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2511 "frontend/parser.cpp"
    break;

  case 281: // matrix: "[" "terminator (\\n or ;)" matvals "]"
#line 594 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2517 "frontend/parser.cpp"
    break;

  case 282: // matrix: "[" matvals "terminator (\\n or ;)" "]"
#line 595 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2523 "frontend/parser.cpp"
    break;

  case 283: // matrix: "[" "terminator (\\n or ;)" matvals "terminator (\\n or ;)" "]"
#line 596 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2529 "frontend/parser.cpp"
    break;

  case 284: // matvals: expr
#line 598 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixValue(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2535 "frontend/parser.cpp"
    break;

  case 285: // matvals: matvals "," expr
#line 599 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2541 "frontend/parser.cpp"
    break;

  case 286: // matvals: matvals "," "terminator (\\n or ;)" expr
#line 600 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[3].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2547 "frontend/parser.cpp"
    break;

  case 287: // expr_mat: matrix
#line 604 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2553 "frontend/parser.cpp"
    break;

  case 293: // int_val: expr_int
#line 612 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 2559 "frontend/parser.cpp"
    break;

  case 294: // int_val: expr_var
#line 613 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2565 "frontend/parser.cpp"
    break;

  case 315: // expr_int: "int"
#line 646 "frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 2571 "frontend/parser.cpp"
    break;

  case 316: // expr_int: "-" expr_int
#line 647 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 2577 "frontend/parser.cpp"
    break;

  case 317: // expr_int: "(" expr_int ")"
#line 648 "frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 2583 "frontend/parser.cpp"
    break;

  case 318: // expr_int: "~" expr_int
#line 649 "frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 2589 "frontend/parser.cpp"
    break;

  case 319: // expr_int: expr_int "*" expr_int
#line 650 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 2595 "frontend/parser.cpp"
    break;

  case 320: // expr_int: expr_int "/" expr_int
#line 651 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 2601 "frontend/parser.cpp"
    break;

  case 321: // expr_int: expr_int "%" expr_int
#line 652 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 2607 "frontend/parser.cpp"
    break;

  case 322: // expr_int: expr_int "-" expr_int
#line 653 "frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 2613 "frontend/parser.cpp"
    break;

  case 323: // expr_int: expr_int "+" expr_int
#line 654 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 2619 "frontend/parser.cpp"
    break;

  case 324: // expr_int: expr_int "<<" expr_int
#line 655 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 2625 "frontend/parser.cpp"
    break;

  case 325: // expr_int: expr_int ">>" expr_int
#line 656 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 2631 "frontend/parser.cpp"
    break;

  case 326: // expr_int: expr_int "&" expr_int
#line 657 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 2637 "frontend/parser.cpp"
    break;

  case 327: // expr_int: expr_int "^" expr_int
#line 658 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 2643 "frontend/parser.cpp"
    break;

  case 328: // expr_int: expr_int "|" expr_int
#line 659 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 2649 "frontend/parser.cpp"
    break;

  case 329: // expr_float: "float"
#line 663 "frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 2655 "frontend/parser.cpp"
    break;

  case 330: // expr_float: "-" expr_float
#line 664 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 2661 "frontend/parser.cpp"
    break;

  case 331: // expr_float: "(" expr_float ")"
#line 665 "frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 2667 "frontend/parser.cpp"
    break;

  case 332: // expr_float: expr_float "**" expr_float
#line 666 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2673 "frontend/parser.cpp"
    break;

  case 333: // expr_float: expr_float "**" expr_int
#line 667 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2679 "frontend/parser.cpp"
    break;

  case 334: // expr_float: expr_int "**" expr_float
#line 668 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2685 "frontend/parser.cpp"
    break;

  case 335: // expr_float: expr_float "*" expr_float
#line 669 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 2691 "frontend/parser.cpp"
    break;

  case 336: // expr_float: expr_float "*" expr_int
#line 670 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 2697 "frontend/parser.cpp"
    break;

  case 337: // expr_float: expr_int "*" expr_float
#line 671 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 2703 "frontend/parser.cpp"
    break;

  case 338: // expr_float: expr_float "/" expr_float
#line 672 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 2709 "frontend/parser.cpp"
    break;

  case 339: // expr_float: expr_float "/" expr_int
#line 673 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 2715 "frontend/parser.cpp"
    break;

  case 340: // expr_float: expr_int "/" expr_float
#line 674 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 2721 "frontend/parser.cpp"
    break;

  case 341: // expr_float: expr_float "%" expr_float
#line 675 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2727 "frontend/parser.cpp"
    break;

  case 342: // expr_float: expr_float "%" expr_int
#line 676 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2733 "frontend/parser.cpp"
    break;

  case 343: // expr_float: expr_int "%" expr_float
#line 677 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2739 "frontend/parser.cpp"
    break;

  case 344: // expr_float: expr_float "-" expr_float
#line 678 "frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 2745 "frontend/parser.cpp"
    break;

  case 345: // expr_float: expr_float "-" expr_int
#line 679 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 2751 "frontend/parser.cpp"
    break;

  case 346: // expr_float: expr_int "-" expr_float
#line 680 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 2757 "frontend/parser.cpp"
    break;

  case 347: // expr_float: expr_float "+" expr_float
#line 681 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 2763 "frontend/parser.cpp"
    break;

  case 348: // expr_float: expr_float "+" expr_int
#line 682 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 2769 "frontend/parser.cpp"
    break;

  case 349: // expr_float: expr_int "+" expr_float
#line 683 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 2775 "frontend/parser.cpp"
    break;

  case 350: // expr_str: "string"
#line 687 "frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2781 "frontend/parser.cpp"
    break;

  case 351: // expr_str: "(" expr_str ")"
#line 688 "frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 2787 "frontend/parser.cpp"
    break;

  case 352: // expr_str: expr_str "++" expr_str
#line 689 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 2793 "frontend/parser.cpp"
    break;

  case 353: // expr_str: expr_str "++" expr_int
#line 690 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 2799 "frontend/parser.cpp"
    break;

  case 354: // expr_str: expr_str "++" expr_float
#line 691 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 2805 "frontend/parser.cpp"
    break;

  case 355: // expr_str: expr_str "++" expr_bool
#line 692 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2811 "frontend/parser.cpp"
    break;

  case 356: // expr_str: expr_str "++" expr_none
#line 693 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 2817 "frontend/parser.cpp"
    break;

  case 357: // expr_str: expr_int "++" expr_str
#line 694 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 2823 "frontend/parser.cpp"
    break;

  case 358: // expr_str: expr_int "++" expr_int
#line 695 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 2829 "frontend/parser.cpp"
    break;

  case 359: // expr_str: expr_int "++" expr_float
#line 696 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 2835 "frontend/parser.cpp"
    break;

  case 360: // expr_str: expr_int "++" expr_bool
#line 697 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2841 "frontend/parser.cpp"
    break;

  case 361: // expr_str: expr_int "++" expr_none
#line 698 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 2847 "frontend/parser.cpp"
    break;

  case 362: // expr_str: expr_float "++" expr_str
#line 699 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 2853 "frontend/parser.cpp"
    break;

  case 363: // expr_str: expr_float "++" expr_int
#line 700 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 2859 "frontend/parser.cpp"
    break;

  case 364: // expr_str: expr_float "++" expr_float
#line 701 "frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 2865 "frontend/parser.cpp"
    break;

  case 365: // expr_str: expr_float "++" expr_bool
#line 702 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2871 "frontend/parser.cpp"
    break;

  case 366: // expr_str: expr_float "++" expr_none
#line 703 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 2877 "frontend/parser.cpp"
    break;

  case 367: // expr_str: expr_bool "++" expr_str
#line 704 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 2883 "frontend/parser.cpp"
    break;

  case 368: // expr_str: expr_bool "++" expr_int
#line 705 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 2889 "frontend/parser.cpp"
    break;

  case 369: // expr_str: expr_bool "++" expr_float
#line 706 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 2895 "frontend/parser.cpp"
    break;

  case 370: // expr_str: expr_bool "++" expr_bool
#line 707 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2901 "frontend/parser.cpp"
    break;

  case 371: // expr_str: expr_bool "++" expr_none
#line 708 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 2907 "frontend/parser.cpp"
    break;

  case 372: // expr_str: expr_none "++" expr_str
#line 709 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 2913 "frontend/parser.cpp"
    break;

  case 373: // expr_str: expr_none "++" expr_int
#line 710 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 2919 "frontend/parser.cpp"
    break;

  case 374: // expr_str: expr_none "++" expr_float
#line 711 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 2925 "frontend/parser.cpp"
    break;

  case 375: // expr_str: expr_none "++" expr_bool
#line 712 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2931 "frontend/parser.cpp"
    break;

  case 376: // expr_str: expr_none "++" expr_none
#line 713 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 2937 "frontend/parser.cpp"
    break;

  case 377: // expr_bool: "bool"
#line 717 "frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 2943 "frontend/parser.cpp"
    break;

  case 378: // expr_bool: "(" expr_bool ")"
#line 718 "frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 2949 "frontend/parser.cpp"
    break;

  case 379: // expr_bool: "not" expr_bool
#line 719 "frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 2955 "frontend/parser.cpp"
    break;

  case 380: // expr_bool: expr_bool "or" expr_bool
#line 720 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 2961 "frontend/parser.cpp"
    break;

  case 381: // expr_bool: expr_bool "and" expr_bool
#line 721 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 2967 "frontend/parser.cpp"
    break;

  case 382: // expr_bool: expr_bool "==" expr_bool
#line 723 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 2973 "frontend/parser.cpp"
    break;

  case 383: // expr_bool: expr_int "==" expr_int
#line 724 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 2979 "frontend/parser.cpp"
    break;

  case 384: // expr_bool: expr_int "==" expr_float
#line 725 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 2985 "frontend/parser.cpp"
    break;

  case 385: // expr_bool: expr_float "==" expr_float
#line 726 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 2991 "frontend/parser.cpp"
    break;

  case 386: // expr_bool: expr_float "==" expr_int
#line 727 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 2997 "frontend/parser.cpp"
    break;

  case 387: // expr_bool: expr_str "==" expr_str
#line 728 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 3003 "frontend/parser.cpp"
    break;

  case 388: // expr_bool: expr_none "==" expr_none
#line 729 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 3009 "frontend/parser.cpp"
    break;

  case 389: // expr_bool: expr_bool "!=" expr_bool
#line 731 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 3015 "frontend/parser.cpp"
    break;

  case 390: // expr_bool: expr_int "!=" expr_int
#line 732 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 3021 "frontend/parser.cpp"
    break;

  case 391: // expr_bool: expr_int "!=" expr_float
#line 733 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 3027 "frontend/parser.cpp"
    break;

  case 392: // expr_bool: expr_float "!=" expr_float
#line 734 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 3033 "frontend/parser.cpp"
    break;

  case 393: // expr_bool: expr_float "!=" expr_int
#line 735 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 3039 "frontend/parser.cpp"
    break;

  case 394: // expr_bool: expr_str "!=" expr_str
#line 736 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 3045 "frontend/parser.cpp"
    break;

  case 395: // expr_bool: expr_none "!=" expr_none
#line 737 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 3051 "frontend/parser.cpp"
    break;

  case 396: // expr_bool: expr_int ">" expr_int
#line 739 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 3057 "frontend/parser.cpp"
    break;

  case 397: // expr_bool: expr_int ">" expr_float
#line 740 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 3063 "frontend/parser.cpp"
    break;

  case 398: // expr_bool: expr_float ">" expr_float
#line 741 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 3069 "frontend/parser.cpp"
    break;

  case 399: // expr_bool: expr_float ">" expr_int
#line 742 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 3075 "frontend/parser.cpp"
    break;

  case 400: // expr_bool: expr_str ">" expr_str
#line 743 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 3081 "frontend/parser.cpp"
    break;

  case 401: // expr_bool: expr_int "<" expr_int
#line 745 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 3087 "frontend/parser.cpp"
    break;

  case 402: // expr_bool: expr_int "<" expr_float
#line 746 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 3093 "frontend/parser.cpp"
    break;

  case 403: // expr_bool: expr_float "<" expr_float
#line 747 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 3099 "frontend/parser.cpp"
    break;

  case 404: // expr_bool: expr_float "<" expr_int
#line 748 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 3105 "frontend/parser.cpp"
    break;

  case 405: // expr_bool: expr_str "<" expr_str
#line 749 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 3111 "frontend/parser.cpp"
    break;

  case 406: // expr_bool: expr_int ">=" expr_int
#line 751 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 3117 "frontend/parser.cpp"
    break;

  case 407: // expr_bool: expr_int ">=" expr_float
#line 752 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 3123 "frontend/parser.cpp"
    break;

  case 408: // expr_bool: expr_float ">=" expr_float
#line 753 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 3129 "frontend/parser.cpp"
    break;

  case 409: // expr_bool: expr_float ">=" expr_int
#line 754 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 3135 "frontend/parser.cpp"
    break;

  case 410: // expr_bool: expr_str ">=" expr_str
#line 755 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 3141 "frontend/parser.cpp"
    break;

  case 411: // expr_bool: expr_int "<=" expr_int
#line 757 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 3147 "frontend/parser.cpp"
    break;

  case 412: // expr_bool: expr_int "<=" expr_float
#line 758 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 3153 "frontend/parser.cpp"
    break;

  case 413: // expr_bool: expr_float "<=" expr_float
#line 759 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 3159 "frontend/parser.cpp"
    break;

  case 414: // expr_bool: expr_float "<=" expr_int
#line 760 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 3165 "frontend/parser.cpp"
    break;

  case 415: // expr_bool: expr_str "<=" expr_str
#line 761 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 3171 "frontend/parser.cpp"
    break;

  case 416: // expr_bool: expr_str "in" expr_str
#line 763 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[0].value.as < std::string > ().find(yystack_[2].value.as < std::string > ()) != std::string::npos; }
#line 3177 "frontend/parser.cpp"
    break;

  case 421: // mattype: "identifier" matsq
#line 775 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3183 "frontend/parser.cpp"
    break;

  case 422: // mattype: "'int'" matsq
#line 776 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(INT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3189 "frontend/parser.cpp"
    break;

  case 423: // mattype: "'float'" matsq
#line 777 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(FLOAT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3195 "frontend/parser.cpp"
    break;

  case 424: // mattype: "'string'" matsq
#line 778 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(STRING_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3201 "frontend/parser.cpp"
    break;

  case 425: // mattype: "'bool'" matsq
#line 779 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(BOOL_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3207 "frontend/parser.cpp"
    break;

  case 433: // matsq: "[" "]"
#line 788 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(scanner->parseInt(-1)); }
#line 3213 "frontend/parser.cpp"
    break;

  case 434: // matsq: "[" int_val "]"
#line 789 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 3219 "frontend/parser.cpp"
    break;

  case 435: // matsq: "[" "]" matsq
#line 790 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), scanner->parseInt(-1)); }
#line 3225 "frontend/parser.cpp"
    break;

  case 436: // matsq: "[" int_val "]" matsq
#line 791 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[2].value.as < ptc::ir::Expr * > ()); }
#line 3231 "frontend/parser.cpp"
    break;

  case 443: // type: mattype "?"
#line 801 "frontend/parser.yy"
       { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 3237 "frontend/parser.cpp"
    break;

  case 444: // type: "'int'"
#line 802 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, true); }
#line 3243 "frontend/parser.cpp"
    break;

  case 445: // type: "'float'"
#line 803 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, true); }
#line 3249 "frontend/parser.cpp"
    break;

  case 446: // type: "'string'"
#line 804 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, true); }
#line 3255 "frontend/parser.cpp"
    break;

  case 447: // type: "'bool'"
#line 805 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, true); }
#line 3261 "frontend/parser.cpp"
    break;

  case 448: // type: "identifier"
#line 806 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[0].value.as < std::string > (), true); }
#line 3267 "frontend/parser.cpp"
    break;

  case 450: // type: mattype
#line 808 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 3273 "frontend/parser.cpp"
    break;


#line 3277 "frontend/parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -773;

  const short  Parser ::yytable_ninf_ = -449;

  const short
   Parser ::yypact_[] =
  {
    1630,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  1061,    17,
      35,   630,   347,   -38,    15,  -773,   180,  -773,  -773,  1217,
    -773,  -773,    37,    19,    27,    48,    65,    98,   183,   311,
     230,   254,  2106,  -773,  -773,   170,   170,  -773,  -773,  -773,
     249,  -773,  2585,  -773,   255,  -773,  -773,   170,   170,   170,
    1446,  2799,  -773,   497,  -773,   715,   721,  2925,  2676,   506,
     700,    73,   201,    -5,   265,   145,  1961,   269,   497,   277,
     288,   715,   721,  2496,  1370,   392,  1124,  1217,  -773,   145,
    -773,   194,   456,   456,  -773,  -773,  -773,  -773,  1300,   256,
    2948,  2734,  1134,  -773,   347,   347,  -773,   278,   285,  -773,
     643,  -773,   292,   656,   338,  -773,   338,  -773,   338,  -773,
     338,  -773,    14,  -773,   336,   446,     4,  1217,   338,  -773,
    -773,  -773,   686,  1217,  -773,  -773,  -773,  2732,  -773,  -773,
    -773,  -773,  -773,  1217,   345,  2658,  -773,  -773,   309,  1217,
    -773,  -773,  -773,  1217,  1217,  1217,  1217,  1217,  1217,  1217,
    1217,  1217,  1217,  1217,  1217,  1217,  -773,   838,   686,  1217,
    1217,  1217,  1217,  1217,  1217,  1217,  1217,  1217,  1217,  1217,
    1217,  1217,  1217,  1217,  1217,  1217,  1217,  1217,  1217,  1217,
    1217,  -773,   686,  1217,  1217,  1217,  1217,  1217,  1217,  -773,
    1217,  1217,  1217,  1217,  1217,  1217,  1217,  1217,  1217,  1217,
    1217,  1217,  1217,   456,  1217,  1217,  1217,  1217,  1217,  1217,
    1217,  1217,  1217,  1217,  1217,  1217,  1217,  1217,  1217,  1217,
    1217,  1217,  1217,  1217,  1217,  1217,  1217,  1217,  1217,  1217,
    1217,  1217,  1217,  1217,  1217,  1217,  1217,  1217,  1217,  1217,
    1217,  1217,  1217,  1217,  1217,  1217,   338,  -773,  -773,   112,
      25,   363,  -773,   686,   365,  -773,  -773,  -773,  1217,  1217,
    -773,  -773,  -773,  -773,   221,   361,  -773,    49,  1569,  1254,
     456,   456,   456,   456,   456,   347,   347,   347,   347,   347,
     456,   456,   456,   456,   456,   456,  2900,  1807,   731,   981,
     630,   234,   234,   630,   456,   456,   456,   456,   456,   456,
     630,   456,   456,   456,   456,   456,   456,   630,   630,   630,
     630,   630,   630,   630,   630,   630,   630,   630,   630,   630,
    1598,  -773,   347,   347,   347,   347,   347,  1217,    15,   102,
     339,   341,     7,  1217,   338,  2799,   372,  2925,  2676,   506,
     700,  -773,  -773,  -773,  -773,   373,    34,   177,   494,    33,
    -773,   326,   394,   350,  2925,  -773,   125,   350,  -773,   401,
    2732,  -773,  2480,   421,   426,  -773,  1907,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
      77,  -773,   130,   335,   245,   878,   898,   335,   245,   878,
     898,    59,   434,   427,   439,    59,   427,   439,    59,   427,
     439,    59,   439,  2828,   163,   441,  2971,  1996,   332,   651,
    1697,   500,  2872,   464,  2435,   513,  1741,  2109,  1494,  3017,
     564,  2339,   424,  2035,   424,  2035,   914,   858,  -773,  -773,
    1417,  2026,   370,  -773,   914,   858,  -773,  -773,  1417,  2026,
     370,  -773,   689,  1186,  2069,   435,   689,  1186,  2069,   435,
     689,  1186,  2069,   435,   689,  1186,  2069,   435,   350,   197,
     335,   245,   335,   245,    59,   434,  2435,   399,   914,   858,
     914,   858,  2828,   163,   441,  2971,  1996,   332,   651,  2435,
     399,   914,  -773,   914,  -773,  2828,   163,   441,  2971,  1996,
     332,   651,  2435,   399,   914,  -773,   914,  -773,   335,   878,
     898,   335,   878,   898,    59,   427,   439,    59,   427,   439,
      59,   427,   439,  1338,   444,  2828,   163,   441,  2971,  1996,
     332,   651,  2435,   399,  1741,  2109,  1494,  3017,   564,  2339,
     424,  2035,   424,  2035,   914,  1417,  2026,   914,  1417,  2026,
     689,  1186,  2069,   689,  1186,  2069,   689,  1186,  2069,   689,
    1186,  2069,   335,   878,   898,   335,   878,   898,    59,   427,
     439,    59,   427,   439,    59,   427,   439,    59,   427,   439,
    2828,   163,   441,  2971,  1996,   332,   651,  2435,   399,   914,
    1417,  2026,   914,  1417,  2026,   689,  1186,  2069,   689,  1186,
    2069,   689,  1186,  2069,   689,  1186,  2069,   457,  2828,   163,
     441,  2971,  1996,   332,   651,  2435,   399,   513,   914,   370,
     914,   370,   689,   435,   689,   435,   689,   435,   689,   435,
    2828,   163,   441,  2971,  1996,   332,   651,  1697,   500,  2872,
     464,  2435,   399,   914,  -773,   914,  -773,  -773,  -773,   458,
      26,   852,   268,   198,  -773,   461,   450,   478,  -773,  -773,
    1217,  -773,   979,   998,   979,   998,   427,   444,   427,   444,
     427,   444,   754,  1441,  1650,  1042,  1042,   979,   998,   979,
     998,   427,   444,   427,   444,   427,   444,   427,   444,    88,
    2994,  3040,   588,   784,   483,  -773,  -773,    88,  2994,  3040,
     588,   784,  1815,  2075,  1815,  2075,  1815,  2075,  1815,  2075,
    1815,  2075,  1815,  2075,    88,  2994,  3040,   588,   784,  1815,
    2075,  1815,  2075,  1815,  2075,  1815,  2075,  1815,  2075,  1815,
    2075,    88,  2994,  3040,   588,   784,  2064,   308,  1007,  1007,
    -773,  -773,  -773,  -773,    88,  2994,  3040,   588,   784,   259,
     227,  -773,  -773,   174,   174,  -773,  -773,  -773,  -773,  -773,
    1217,  1217,  -773,  -773,  -773,   338,    60,    60,  -773,   419,
     480,   492,    22,    72,    96,   467,    38,  -773,   895,   224,
      51,   603,   462,  -773,  -773,  2585,  2555,   512,  1217,  2585,
    -773,  1217,  -773,  -773,  -773,  -773,   757,  -773,  -773,    72,
     128,  -773,  -773,  1217,  -773,  -773,   265,   499,   509,  -773,
     514,  -773,   484,  -773,    60,   522,  -773,    72,   757,   757,
     524,  -773,   555,  -773,   977,  -773,  1024,   225,  1217,  -773,
     533,  -773,   560,   515,  -773,  -773,  -773,    72,   562,  2585,
    2585,  -773,  1217,  -773,  1217,  -773,    40,   467,    52,  1217,
    -773,  -773,   573,  -773,   574,  -773,  1170,   536,  -773,  -773,
    -773,  -773,  2585,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,   524,  -773,  -773,  -773,  -773,   576,   550,  -773,
    -773,  -773
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     9,   315,   329,   350,   377,   307,     0,     0,
       0,     0,     0,     0,     0,    49,     0,    43,    45,    38,
      35,    36,     0,   444,   445,   446,   447,     0,     0,   100,
     101,     0,     0,     4,    10,     0,     0,    37,    15,    17,
       0,    18,     0,    16,     0,    19,    20,     0,     0,     0,
       0,    93,   287,    92,   288,    94,    95,    96,    97,    98,
      99,   449,   450,     0,   307,   100,   294,   287,     0,   288,
       0,     0,     0,   293,     0,     0,     0,     0,   279,   100,
     284,     0,     0,     0,   102,   103,   316,   330,     0,     0,
       0,     0,     0,   379,     0,     0,   318,     0,    33,    32,
       0,    39,     0,     0,   437,   422,   438,   423,   439,   424,
     440,   425,     0,    65,     0,     0,     0,     0,   441,   113,
     309,   421,     0,     0,   114,     1,     3,     0,     5,     8,
       7,    14,    21,     0,     0,     0,    30,    31,     0,     0,
      12,    13,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   115,     0,     0,     0,     0,     0,     0,     0,   112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   442,   426,   443,     0,
      71,     0,   308,     0,   309,   104,   289,   290,     0,     0,
     317,   331,   351,   378,     0,     0,   280,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   316,     0,     0,     0,     0,     0,     0,     0,   448,
       0,     0,     0,     0,   433,   294,     0,   293,     0,     0,
       0,   428,   429,   430,   431,     0,     0,     0,     0,     0,
     311,     0,     0,   116,     0,   427,     0,   117,     6,     0,
       0,    23,     0,     0,     0,    89,    88,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,   105,
       0,    90,     0,   147,   145,   142,   143,   155,   153,   150,
     151,   129,   128,   124,   125,   134,   132,   133,   139,   137,
     138,   121,   120,   278,   276,   277,   272,   273,   274,   275,
     251,   250,   254,   253,   248,   247,   226,   225,   232,   231,
     229,   228,   158,   157,   161,   160,   206,   204,   201,   202,
     197,   198,   199,   200,   223,   221,   218,   219,   214,   215,
     216,   217,   168,   165,   166,   167,   182,   179,   180,   181,
     175,   172,   173,   174,   189,   186,   187,   188,   118,     0,
     146,   144,   154,   152,   127,   126,   246,   239,   205,   203,
     222,   220,   270,   376,   259,   373,   374,   372,   375,   244,
     237,   194,   388,   211,   395,   271,   264,   265,   260,   261,
     262,   263,   245,   238,   196,   195,   213,   212,   140,   323,
     349,   148,   322,   346,   122,   319,   337,   130,   320,   340,
     135,   321,   343,     0,   334,   266,   361,   255,   358,   359,
     357,   360,   240,   233,   224,   326,   230,   328,   227,   327,
     156,   324,   159,   325,   190,   383,   384,   207,   390,   391,
     162,   396,   397,   176,   401,   402,   169,   406,   407,   183,
     411,   412,   141,   348,   347,   149,   345,   344,   123,   336,
     335,   131,   339,   338,   136,   342,   341,   119,   333,   332,
     267,   366,   256,   363,   364,   362,   365,   241,   234,   191,
     386,   385,   208,   393,   392,   163,   399,   398,   177,   404,
     403,   170,   409,   408,   184,   414,   413,     0,   268,   356,
     257,   353,   354,   352,   355,   242,   235,   416,   192,   387,
     209,   394,   164,   400,   178,   405,   171,   410,   185,   415,
     269,   371,   258,   368,   369,   367,   370,   249,   381,   252,
     380,   243,   236,   193,   382,   210,   389,   432,   418,     0,
     419,     0,     0,     0,   310,     0,     0,     0,   281,   282,
       0,   285,   323,   349,   322,   346,   319,   337,   320,   340,
     321,   343,   326,   328,   327,   324,   325,   348,   347,   345,
     344,   336,   335,   339,   338,   342,   341,   333,   332,   376,
     373,   374,   372,   375,     0,   388,   395,   361,   358,   359,
     357,   360,   383,   384,   390,   391,   396,   397,   401,   402,
     406,   407,   411,   412,   366,   363,   364,   362,   365,   386,
     385,   393,   392,   399,   398,   404,   403,   409,   408,   414,
     413,   356,   353,   354,   352,   355,   416,     0,   387,   394,
     400,   405,   410,   415,   371,   368,   369,   367,   370,   381,
     380,   382,   389,   323,   322,   319,   320,   321,    75,    34,
       0,     0,    71,    74,   435,   434,     0,    54,    51,     0,
       0,     0,     0,     0,     0,    67,     0,   295,     0,     0,
     109,     0,     0,   312,   110,     0,     0,    24,     0,     0,
     106,     0,   111,   108,   107,   417,     0,    73,    72,     0,
       0,   109,   291,     0,   283,   286,     0,     0,     0,   436,
       0,    55,     0,    52,    56,    58,    63,     0,     0,     0,
      66,   299,     0,   297,     0,   296,     0,     0,     0,    42,
      25,    26,     0,    48,    91,   420,    61,     0,     0,     0,
       0,    53,     0,    57,     0,    64,     0,    70,     0,     0,
     302,   301,     0,   300,     0,   298,     0,   313,    27,    44,
      50,    46,     0,    62,   292,    28,    29,    41,    40,    60,
      59,    68,     0,    69,   305,   304,   303,     0,     0,    47,
     306,   314
  };

  const short
   Parser ::yypgoto_[] =
  {
    -773,  -773,  -129,   581,   -27,   -41,  -622,  -239,  -772,  -773,
     274,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -685,  -773,  -773,   542,   -26,  -191,   526,
    -773,   490,  -773,  1926,  1689,   632,   565,  1188,   637,   334,
    1184,   968,  1408,   -63,  -220,  2108,     0,   244,   647,  -773,
    -137,  -773,   -11,     1
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    31,    32,   131,    33,    34,   137,   857,   138,    35,
      99,    36,    37,    38,    39,    40,    41,    42,    43,   851,
      44,   852,    45,   760,   761,    46,   114,   764,   765,    47,
      48,    49,   380,    50,    51,    52,    81,    68,    54,    70,
     181,    71,    72,   120,   352,    57,   338,   339,   340,    61,
     639,    62,   121,    63
  };

  const short
   Parser ::yytable_[] =
  {
      58,   136,   254,   819,   249,   128,   362,   823,    74,    58,
      87,    91,   105,   107,   109,   111,   249,   345,   350,    58,
      77,     3,     4,     5,     6,     7,     8,   346,     9,    78,
     103,   249,    58,    10,   -65,   249,    97,   757,   103,     3,
       4,    11,    58,   351,    82,   770,    12,   249,   758,   249,
     247,    83,   650,     3,     4,     5,     6,     7,     8,   103,
       9,   249,   103,   757,    12,    10,   786,   641,   157,   250,
     158,   800,   801,    11,   771,   134,   103,    58,    12,   164,
     869,   752,   269,    87,   103,   135,   104,   780,   287,    98,
     759,    79,    30,   341,   106,   342,   805,   343,   180,   344,
     358,   332,    23,    24,    25,    26,   807,   355,   329,    84,
      85,   102,   810,   103,   861,   108,   759,   781,  -434,   833,
     291,   292,   638,    79,    30,  -434,   862,    58,    23,    24,
      25,    26,   110,    58,   329,    58,   808,   774,   827,    58,
     246,   806,   782,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,   253,    58,   116,   386,
     390,   394,   397,   400,   402,   407,   771,   826,   808,   118,
     129,   771,   112,   130,   431,   439,   444,   448,   452,   456,
      23,    24,    25,    26,   117,   835,   329,   763,   191,   100,
     476,   324,   325,   326,   489,   192,   193,   265,   500,   503,
     506,   509,   512,   514,   519,   853,   266,   856,   856,   783,
     791,   536,   539,   542,   545,   548,   551,   554,   557,   560,
     563,   566,   569,   574,   647,   581,   584,   587,   590,   593,
     596,   776,   602,   648,   267,   637,   813,   845,   771,   771,
     624,   122,     7,   684,    59,    23,    24,    25,    26,   316,
     640,   329,    75,    59,   125,    92,   182,   113,   133,   318,
     319,   267,   185,    59,   139,   814,   846,    58,   248,   123,
     653,   655,   657,   659,   661,   252,    59,   290,   789,   256,
     668,   670,   672,   674,   676,   678,    59,   257,   291,   292,
     681,   318,   319,   689,   693,   695,   697,   699,   701,   703,
     706,   710,   712,   714,   716,   718,   720,   723,    91,    91,
      91,    91,    91,    91,    91,   736,    91,    91,    91,    91,
     327,    59,   115,   754,   116,   328,   258,    58,   259,   315,
     316,   317,   288,    58,   333,   128,    23,    24,    25,    26,
     318,   319,   329,   231,   157,   347,   158,   762,   766,   103,
     117,     3,   161,   162,   163,   164,    94,   233,   360,   157,
      58,   158,    58,    95,   234,   235,   236,   237,   238,   239,
     363,    59,   642,   649,   180,   644,    12,    59,   118,    59,
     750,   231,   751,    59,   755,  -448,   756,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
     772,    59,   262,   231,   236,   237,   238,   239,   773,   408,
     182,   775,   415,   232,   183,   184,   185,   233,   432,   440,
     445,   449,   453,   457,   234,   235,   236,   237,   238,   239,
     778,   187,   188,   157,   477,   158,   779,   336,   490,   159,
     160,   161,   162,   163,   164,   182,   231,   203,   520,   349,
       3,     4,     5,     6,     7,     8,   356,     9,   334,   222,
       3,     4,    10,   180,   285,    82,   195,   575,   785,   784,
      11,   792,    83,   196,   197,    12,   603,   607,   609,   611,
     613,   615,   617,   619,   625,    12,   241,   348,   793,   243,
     794,   796,   382,   802,   803,   804,   244,   245,     3,     4,
       5,     6,     7,     8,   818,     9,   767,   809,   182,   829,
      10,    59,   183,   184,   185,   821,   459,   231,    11,   830,
      79,    30,   186,    12,   231,   243,   832,   232,   831,   187,
     188,   233,   244,   245,   682,   768,   848,   690,   234,   235,
     236,   237,   238,   239,   707,   234,   235,   236,   237,   238,
     239,   724,   726,   728,   729,   730,   731,   732,   733,   737,
      92,    92,    92,    92,   834,   597,   839,   840,    79,    30,
     849,    59,   854,   157,   850,   158,   868,    59,   788,   159,
     160,   161,   162,   163,   164,   864,   865,   643,   870,   351,
     169,   858,   645,   646,   172,   173,   174,   175,   176,   177,
     178,   179,   749,   180,    59,   251,    59,     3,     4,     5,
       6,     7,     8,   308,     9,   815,   790,   132,   837,    10,
     309,   310,   311,   312,   313,   314,   331,    11,   140,   141,
     142,   156,    12,   365,     3,     4,     5,     6,     7,    88,
      67,    58,   264,   766,   816,    69,    83,    60,   871,   825,
      58,     0,     0,     0,    11,    76,    60,     0,    93,    12,
       3,     4,     5,     6,     7,     8,    60,     9,   334,     0,
       0,     0,    10,   241,   242,     0,   243,    79,    30,    60,
      11,     0,   769,   244,   245,    12,     0,     0,     0,    60,
       3,     4,     5,     6,     7,     8,     0,     9,   157,     0,
     158,     0,    10,     0,   159,   160,   161,   162,   163,   164,
      11,    23,    24,    25,    26,    12,     0,   329,   330,   172,
     173,   240,   241,   242,    60,   243,     0,   348,   180,     0,
      79,    30,   244,   245,   136,   289,   190,     0,   136,     0,
     191,   262,   194,     0,   799,     0,   195,   192,   193,   128,
      58,    58,   307,   196,   197,     0,   308,   762,   762,   799,
      79,    30,     0,   309,   310,   311,   312,   313,   314,   322,
     323,   324,   325,   326,    60,    58,    58,     0,    58,    58,
      60,    58,    60,     0,   278,   279,    60,   640,   855,   855,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,     0,    60,   762,   316,   317,     0,   836,
     838,   136,   409,   411,   413,     0,   318,   319,    58,     0,
       0,   433,   441,     0,     0,    23,    24,    25,    26,    58,
      58,   329,    58,     0,    58,     0,     0,   478,     0,    58,
       0,   491,     3,     4,     5,     6,     7,     8,   379,     9,
       0,   521,    58,     0,    10,     0,     3,     4,     5,     6,
       7,     8,    11,     9,     0,   116,     0,    12,    10,   182,
     576,     0,     0,   183,   184,   185,    11,     0,     0,   604,
       0,    12,     0,     0,     0,    59,     0,   626,   628,   630,
       0,   634,   636,     0,    59,   200,   201,   202,   203,     3,
       4,     5,     6,     7,     8,     0,     9,   811,     0,     0,
       0,    10,    79,    30,    60,   219,   220,   221,   222,    11,
       0,     0,     0,   157,    12,   158,    79,    30,     0,   159,
     160,   161,   162,   163,   164,     0,     0,   683,     0,     0,
     691,     0,     0,     0,   172,   173,     0,   708,   176,   177,
     178,   179,     0,   180,   725,   727,   727,   727,   727,   727,
     727,   727,   738,   739,   740,   741,   742,     0,    55,    79,
      30,     0,     0,     0,    60,     0,     0,    55,     0,    89,
      60,     3,     4,     5,     6,     7,     8,    55,     9,   841,
       0,   263,     0,    10,    59,    59,   272,   273,   274,   203,
      55,    11,   315,   316,   317,     0,    12,    60,     0,    60,
      55,     0,     0,   318,   319,   282,   283,   284,   285,    59,
      59,     0,    59,    59,     0,    59,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     9,   843,     0,     0,     0,
      10,   311,   312,   313,   314,    55,     0,     0,    11,     0,
       0,    79,    30,    12,     0,     0,    89,   322,   323,   324,
     325,   326,    59,     0,     0,     3,     4,     5,     6,    64,
       8,     0,     9,    59,    59,     0,    59,    10,    59,     0,
       0,     0,     0,    59,     0,    11,     0,     0,     0,     0,
      12,     0,     0,     0,     0,    55,    59,     0,    79,    30,
       0,    55,   812,    55,     0,   817,     0,    55,     0,     0,
       0,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,     0,    55,     0,   828,     0,     0,
       0,     0,     0,   404,   263,    65,    30,     0,     0,     0,
       0,     0,   428,   436,     0,   240,   241,   242,   842,   243,
     844,     0,     0,     0,     0,   307,   244,   245,   473,   308,
     482,   484,   486,     0,     0,     0,   309,   310,   311,   312,
     313,   314,   516,     0,     3,     4,     5,     6,     7,     8,
     867,     9,   866,     0,     0,     0,    10,     0,    53,     0,
       0,   571,     0,     0,    11,     0,     0,    53,     0,    12,
     599,   198,   199,   200,   201,   202,   203,    53,   621,     0,
       0,     0,     0,   119,   124,     0,   209,   210,     0,     0,
      53,     3,     4,     5,     6,     7,     8,     0,     9,     0,
      53,     0,     0,    10,     0,    55,     0,   189,     0,     0,
       0,    11,     0,     0,    79,    30,    12,     0,     0,   119,
       0,     0,   189,     0,     0,     0,     0,     0,   679,   685,
     686,   687,     0,   119,   261,    53,     0,     0,   704,   280,
     281,   282,   283,   284,   285,   721,    89,    89,    89,    89,
      89,    89,    89,   734,    89,    89,    89,    89,    60,     0,
       0,    79,    30,     0,     0,    55,     0,    60,     0,     0,
       0,    55,     0,     0,     3,     4,     5,     6,    64,    88,
       0,     0,     0,     0,     0,    53,    83,     0,     0,     0,
       0,    53,     0,    53,    11,     0,     0,    53,    55,    12,
      55,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,     0,    53,     0,   384,   388,   392,
       0,     0,     0,   270,   271,   272,   273,   274,   203,     0,
       0,     0,   427,   435,   275,   276,   277,     0,   278,   279,
       0,   461,   463,   465,   467,   469,   471,     0,     0,   480,
     261,     0,     0,   493,     0,   217,   218,   219,   220,   221,
     222,   223,     0,   523,     0,   224,     0,    60,    60,     0,
       0,     0,   225,   226,   227,   228,   229,   230,    56,     0,
       0,     0,   578,     0,     0,     0,     0,    56,     0,     0,
       0,   606,    60,    60,     0,    60,    60,    56,    60,     0,
       0,   632,   198,   199,   200,   201,   202,   203,     0,     0,
      56,     0,     0,     0,     0,     0,   129,   209,   210,   130,
      56,   213,   214,   215,   216,    53,   322,   323,   324,   325,
     326,     0,     0,     0,     0,    60,     0,   275,     0,   277,
       0,   278,   279,     0,     0,     0,    60,    60,     0,    60,
       0,    60,     0,     0,     0,    56,    60,     0,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    60,
     154,   155,     0,   157,     0,   158,     0,     0,     0,   159,
     160,   161,   162,   163,   164,    53,     0,     0,     0,     0,
     169,    53,   171,     0,   172,   173,   174,   175,   176,   177,
     178,   179,     0,   180,     0,    56,     0,     0,     0,     0,
       0,    56,     0,    56,     0,     0,     0,    56,    53,     0,
      53,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,     0,    56,     0,     0,   189,     0,
       0,     0,   189,   405,     0,     0,   189,     0,     0,   260,
       0,     0,   429,   437,   270,   271,   272,   273,   274,   203,
       0,     0,     0,     0,     0,   275,   276,   277,   474,   278,
     279,     0,   487,     0,   495,   497,     0,     0,   260,    55,
       0,   189,   517,   322,   323,   324,   325,   326,    55,   189,
       0,     0,     0,     0,   275,   276,   277,     0,   278,   279,
       1,   572,     0,     2,     3,     4,     5,     6,     7,     8,
     600,     9,     0,     0,     0,   189,    10,   189,   622,   189,
       0,   189,     0,   189,    11,   189,     0,     0,     0,    12,
       0,     0,     0,     0,   189,   322,   323,   324,   325,   326,
       0,     0,     0,     0,     0,    56,   275,   189,     0,     0,
     278,   279,     0,     0,     0,     0,    13,    14,    15,     0,
      16,    17,    18,    19,    20,    21,    22,    66,    23,    24,
      25,    26,    27,    28,    29,    30,   157,   189,   158,     0,
       0,     0,   159,   160,   161,   162,   163,   164,    55,    55,
       0,     0,   168,   169,   170,   171,     0,   172,   173,   174,
     175,   176,   177,   178,   179,    56,   180,     0,     0,     0,
       0,    56,     0,    55,    55,     0,    55,    55,     0,    55,
     157,     0,   158,     0,     0,     0,   159,   160,   161,   162,
     163,   164,   189,     0,     0,     0,     0,     0,    56,     0,
      56,   172,   173,   174,   175,   176,   177,   178,   179,     0,
     180,     0,     0,     0,     0,     0,    55,     0,     0,     0,
     189,     0,   335,     0,     0,     0,     0,    55,    55,     0,
      55,     0,    55,     0,   335,     0,   353,    55,     0,     0,
       0,   335,   357,     0,     0,     0,   189,   261,     0,     0,
      55,     0,   280,   281,   282,   283,   284,   285,   300,    53,
     270,   271,   272,   273,   274,   203,     0,     0,    53,   301,
     302,   303,   304,   305,   306,   278,   279,   335,   383,   387,
     391,   395,   398,   401,   403,   410,   412,   414,   416,   418,
     420,   422,   424,   426,   434,   442,   446,   450,   454,   458,
       0,   335,   460,   462,   464,   466,   468,   470,     0,   472,
     479,   481,   483,   485,   492,   494,   496,   498,   501,   504,
     507,   510,     0,   515,   522,   524,   526,   528,   530,   532,
     534,   537,   540,   543,   546,   549,   552,   555,   558,   561,
     564,   567,   570,   577,   579,   582,   585,   588,   591,   594,
     335,   598,   605,   608,   610,   612,   614,   616,   618,   620,
     627,   629,   631,   633,   635,    80,     0,     0,    53,    53,
       0,     0,   335,     0,     0,   101,     0,   335,   335,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
       0,   154,   155,    53,    53,     0,    53,    53,     0,    53,
     157,   255,   158,     0,     0,     0,   159,   160,   161,   162,
     163,   164,   165,   166,   167,     0,   168,   169,   170,   171,
       0,   172,   173,   174,   175,   176,   177,   178,   179,     0,
     180,     0,     0,    80,     0,     0,    53,     0,     0,     0,
       0,   217,   218,   219,   220,   221,   222,    53,    53,     0,
      53,   224,    53,     0,     0,     0,     0,    53,   225,   226,
     227,   228,   229,   230,     0,     0,     0,   335,     0,     0,
      53,   217,   218,   219,   220,   221,   222,     0,     0,    56,
     198,   199,   200,   201,   202,   203,     0,     0,    56,   359,
     227,   228,   229,   230,     0,   364,     0,     0,     0,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,     0,   381,   217,   218,   219,   220,   221,   222,
     280,   281,   282,   283,   284,   285,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,   126,   127,     0,     2,
       3,     4,     5,     6,     7,     8,    73,     9,    86,    90,
      96,     0,    10,     0,   198,   199,   200,   201,   202,   203,
      11,     0,     0,     0,     0,    12,     0,     0,     0,   209,
     210,   211,   212,   213,   214,   215,   216,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    56,    56,
       0,     0,    13,    14,    15,     0,    16,    17,    18,    19,
      20,    21,    22,     0,    23,    24,    25,    26,    27,    28,
      29,    30,     0,    56,    56,     0,    56,    56,     0,    56,
     268,    86,     0,   651,     0,     0,   286,     0,     0,     0,
       0,     0,   320,   321,     0,     0,     0,     0,     0,     0,
       0,   337,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   337,     0,   354,    56,     0,     0,     0,
     337,   354,     0,     0,     0,     0,     0,    56,    56,     0,
      56,     0,    56,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,   748,     0,     0,     0,     0,     0,   753,
      56,     0,     0,     0,     0,     0,   337,   385,   389,   393,
     396,   399,   354,   406,   354,   354,   354,   417,   419,   421,
     423,   425,   430,   438,   443,   447,   451,   455,   354,     0,
     337,   354,   354,   354,   354,   354,   354,     0,   475,   354,
     354,   354,   488,   354,   354,   354,   499,   502,   505,   508,
     511,   513,   518,   354,   525,   527,   529,   531,   533,   535,
     538,   541,   544,   547,   550,   553,   556,   559,   562,   565,
     568,   573,   354,   580,   583,   586,   589,   592,   595,   337,
     601,   354,   354,   354,   354,   354,   354,   354,   623,   354,
     354,   354,   354,   354,   198,   199,   200,   201,   202,   203,
       0,   337,     0,     0,     0,   206,   337,   337,     0,   209,
     210,   211,   212,   213,   214,   215,   216,     0,   652,   654,
     656,   658,   660,   662,   663,   664,   665,   666,   667,   669,
     671,   673,   675,   677,     0,     0,     0,     0,   680,     0,
       0,   688,   692,   694,   696,   698,   700,   702,   705,   709,
     711,   713,   715,   717,   719,   722,    90,    90,    90,    90,
      90,    90,    90,   735,    90,    90,    90,    90,     0,     0,
     743,   744,   745,   746,   747,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   157,     0,   158,     0,     0,     0,
     159,   160,   161,   162,   163,   164,   337,   335,     0,     0,
     335,   169,   170,   171,     0,   172,   173,   174,   175,   176,
     177,   178,   179,     0,   180,     0,     0,     0,     0,     0,
       0,   127,   335,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,   777,     0,    10,     0,     0,     0,
       0,     0,     0,   335,    11,   335,   260,     0,     0,    12,
       0,   198,   199,   200,   201,   202,   203,   204,     0,     0,
       0,   205,   206,   207,   208,     0,   209,   210,   211,   212,
     213,   214,   215,   216,     0,   335,    13,    14,    15,     0,
      16,    17,    18,    19,    20,    21,    22,     0,    23,    24,
      25,    26,    27,    28,    29,    30,   127,     0,     2,     3,
       4,     5,     6,     7,     8,     0,     9,   787,     0,   820,
       0,    10,     0,     0,     0,     0,   795,     0,     0,    11,
       0,     0,     0,     0,    12,     0,     0,     0,   134,     3,
       4,     5,     6,     7,     8,     0,     9,     0,   135,     0,
       0,    10,     0,     0,     0,     0,     0,     0,     0,    11,
       0,    13,    14,    15,    12,    16,    17,    18,    19,    20,
      21,    22,     0,    23,    24,    25,    26,    27,    28,    29,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13,    14,    15,     0,    16,    17,    18,    19,    20,
      21,    22,     0,    23,    24,    25,    26,    27,    28,    29,
      30,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,   361,     0,    10,     0,   797,   798,     0,     0,
       0,     0,    11,     0,     0,     0,     0,    12,     0,     0,
       0,   217,   218,   219,   220,   221,   222,   223,     0,     0,
       0,   224,     0,     0,   822,     0,     0,   824,   225,   226,
     227,   228,   229,   230,    13,    14,    15,     0,    16,    17,
      18,    19,    20,    21,    22,     0,    23,    24,    25,    26,
      27,    28,    29,    30,     0,     2,     3,     4,     5,     6,
       7,     8,     0,     9,   847,     0,     0,     0,    10,   280,
     281,   282,   283,   284,   285,   300,    11,     0,   859,     0,
     860,    12,     0,     0,     0,   863,   301,   302,   303,   304,
     305,   306,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,    14,
      15,     0,    16,    17,    18,    19,    20,    21,    22,     0,
      23,    24,    25,    26,    27,    28,    29,    30,   157,     0,
     158,     0,     0,     0,   159,   160,   161,   162,   163,   164,
     165,   166,   167,     0,   168,   169,   170,   171,     0,   172,
     173,   174,   175,   176,   177,   178,   179,   157,   180,   158,
       0,     0,     0,   159,   160,   161,   162,   163,   164,     0,
     166,   167,     0,   168,   169,   170,   171,     0,   172,   173,
     174,   175,   176,   177,   178,   179,     0,   180,     0,     0,
       0,     0,     0,     0,     0,     0,   337,     0,     0,   337,
       0,   157,     0,   158,     0,     0,     0,   159,   160,   161,
     162,   163,   164,     0,   166,     0,     0,   168,   169,   170,
     171,   337,   172,   173,   174,   175,   176,   177,   178,   179,
     260,   180,     0,     0,     0,   270,   271,   272,   273,   274,
     203,   293,   337,     0,   337,     0,   275,   276,   277,     0,
     278,   279,   294,   295,   296,   297,   298,   299,     0,     0,
     198,   199,   200,   201,   202,   203,   204,     0,     0,     0,
     205,   206,   207,   208,   337,   209,   210,   211,   212,   213,
     214,   215,   216,   270,   271,   272,   273,   274,   203,   293,
       0,     0,     0,     0,   275,   276,   277,     0,   278,   279,
     294,   295,   296,   297,   298,   299,   198,   199,   200,   201,
     202,   203,     0,     0,     0,     0,   205,   206,   207,   208,
       0,   209,   210,   211,   212,   213,   214,   215,   216,   270,
     271,   272,   273,   274,   203,     0,     0,     0,     0,     0,
     275,   276,   277,     0,   278,   279,   294,   295,   296,   297,
     298,   299,   198,   199,   200,   201,   202,   203,     0,     0,
       0,     0,     0,   206,     0,   208,     0,   209,   210,   211,
     212,   213,   214,   215,   216,   280,   281,   282,   283,   284,
     285,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   301,   302,   303,   304,   305,   306
  };

  const short
   Parser ::yycheck_[] =
  {
       0,    42,    65,   775,     9,    32,   135,   779,     8,     9,
      10,    11,    23,    24,    25,    26,     9,     3,    14,    19,
       3,     4,     5,     6,     7,     8,     9,    13,    11,    12,
      11,     9,    32,    16,     9,     9,    74,     3,    11,     4,
       5,    24,    42,    39,     9,    12,    29,     9,    14,     9,
      61,    16,     3,     4,     5,     6,     7,     8,     9,    11,
      11,     9,    11,     3,    29,    16,    40,    42,     9,    74,
      11,   756,   757,    24,    41,     3,    11,    77,    29,    20,
     852,    74,    82,    83,    11,    13,    67,    10,    88,    74,
      56,    74,    75,   104,    67,   106,    74,   108,    39,   110,
     127,   100,    68,    69,    70,    71,    10,   118,    74,    74,
      75,    74,    74,    11,    74,    67,    56,    40,    67,   804,
      32,    33,    10,    74,    75,    74,    74,   127,    68,    69,
      70,    71,    67,   133,    74,   135,    40,    12,    10,   139,
      67,   763,    12,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    11,   157,    13,   159,
     160,   161,   162,   163,   164,   165,    41,   789,    40,    67,
       0,    41,    74,     3,   174,   175,   176,   177,   178,   179,
      68,    69,    70,    71,    39,   807,    74,    10,    25,     9,
     190,    17,    18,    19,   194,    32,    33,     3,   198,   199,
     200,   201,   202,   203,   204,   827,    12,   829,   830,    12,
      12,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,     3,   225,   226,   227,   228,   229,
     230,   360,   232,    12,    40,   246,    12,    12,    41,    41,
     240,    11,     8,     9,     0,    68,    69,    70,    71,    22,
     249,    74,     8,     9,     0,    11,    11,    74,     9,    32,
      33,    40,    17,    19,     9,    41,    41,   267,    67,    39,
     270,   271,   272,   273,   274,    10,    32,    21,    10,    10,
     280,   281,   282,   283,   284,   285,    42,    10,    32,    33,
     290,    32,    33,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
      42,    77,    11,   334,    13,    40,    38,   327,    40,    21,
      22,    23,    88,   333,    42,   362,    68,    69,    70,    71,
      32,    33,    74,    11,     9,     9,    11,   346,   347,    11,
      39,     4,    17,    18,    19,    20,     9,    25,    13,     9,
     360,    11,   362,    16,    32,    33,    34,    35,    36,    37,
      61,   127,     9,    12,    39,    10,    29,   133,    67,   135,
      41,    11,    41,   139,    12,    74,    13,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
      74,   157,    10,    11,    34,    35,    36,    37,    14,   165,
      11,    10,   168,    21,    15,    16,    17,    25,   174,   175,
     176,   177,   178,   179,    32,    33,    34,    35,    36,    37,
       9,    32,    33,     9,   190,    11,    10,   103,   194,    15,
      16,    17,    18,    19,    20,    11,    11,    20,   204,   115,
       4,     5,     6,     7,     8,     9,   122,    11,    12,    20,
       4,     5,    16,    39,    20,     9,    25,   223,    10,    12,
      24,    10,    16,    32,    33,    29,   232,   233,   234,   235,
     236,   237,   238,   239,   240,    29,    22,    41,    38,    25,
      12,     8,   158,    74,    14,     3,    32,    33,     4,     5,
       6,     7,     8,     9,    42,    11,    12,    40,    11,    10,
      16,   267,    15,    16,    17,     3,   182,    11,    24,    10,
      74,    75,    25,    29,    11,    25,    42,    21,    14,    32,
      33,    25,    32,    33,   290,    41,     3,   293,    32,    33,
      34,    35,    36,    37,   300,    32,    33,    34,    35,    36,
      37,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,    42,   231,    42,    12,    74,    75,
      10,   327,    10,     9,    59,    11,    40,   333,   641,    15,
      16,    17,    18,    19,    20,    12,    12,   253,    12,    39,
      26,   830,   258,   259,    30,    31,    32,    33,    34,    35,
      36,    37,   328,    39,   360,    63,   362,     4,     5,     6,
       7,     8,     9,    25,    11,    12,   642,    36,   809,    16,
      32,    33,    34,    35,    36,    37,   100,    24,    47,    48,
      49,    50,    29,   143,     4,     5,     6,     7,     8,     9,
       8,   641,    77,   642,    41,     8,    16,     0,   868,   786,
     650,    -1,    -1,    -1,    24,     8,     9,    -1,    11,    29,
       4,     5,     6,     7,     8,     9,    19,    11,    12,    -1,
      -1,    -1,    16,    22,    23,    -1,    25,    74,    75,    32,
      24,    -1,   348,    32,    33,    29,    -1,    -1,    -1,    42,
       4,     5,     6,     7,     8,     9,    -1,    11,     9,    -1,
      11,    -1,    16,    -1,    15,    16,    17,    18,    19,    20,
      24,    68,    69,    70,    71,    29,    -1,    74,    75,    30,
      31,    21,    22,    23,    77,    25,    -1,    41,    39,    -1,
      74,    75,    32,    33,   775,    88,    21,    -1,   779,    -1,
      25,    10,    21,    -1,   755,    -1,    25,    32,    33,   776,
     750,   751,    21,    32,    33,    -1,    25,   756,   757,   770,
      74,    75,    -1,    32,    33,    34,    35,    36,    37,    15,
      16,    17,    18,    19,   127,   775,   776,    -1,   778,   779,
     133,   781,   135,    -1,    30,    31,   139,   786,   829,   830,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   804,    22,    23,    -1,   808,
     809,   852,   165,   166,   167,    -1,    32,    33,   818,    -1,
      -1,   174,   175,    -1,    -1,    68,    69,    70,    71,   829,
     830,    74,   832,    -1,   834,    -1,    -1,   190,    -1,   839,
      -1,   194,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,   204,   852,    -1,    16,    -1,     4,     5,     6,     7,
       8,     9,    24,    11,    -1,    13,    -1,    29,    16,    11,
     223,    -1,    -1,    15,    16,    17,    24,    -1,    -1,   232,
      -1,    29,    -1,    -1,    -1,   641,    -1,   240,   241,   242,
      -1,   244,   245,    -1,   650,    17,    18,    19,    20,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    -1,    -1,
      -1,    16,    74,    75,   267,    17,    18,    19,    20,    24,
      -1,    -1,    -1,     9,    29,    11,    74,    75,    -1,    15,
      16,    17,    18,    19,    20,    -1,    -1,   290,    -1,    -1,
     293,    -1,    -1,    -1,    30,    31,    -1,   300,    34,    35,
      36,    37,    -1,    39,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,    -1,     0,    74,
      75,    -1,    -1,    -1,   327,    -1,    -1,     9,    -1,    11,
     333,     4,     5,     6,     7,     8,     9,    19,    11,    12,
      -1,    10,    -1,    16,   750,   751,    17,    18,    19,    20,
      32,    24,    21,    22,    23,    -1,    29,   360,    -1,   362,
      42,    -1,    -1,    32,    33,    17,    18,    19,    20,   775,
     776,    -1,   778,   779,    -1,   781,    -1,    -1,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,
      16,    34,    35,    36,    37,    77,    -1,    -1,    24,    -1,
      -1,    74,    75,    29,    -1,    -1,    88,    15,    16,    17,
      18,    19,   818,    -1,    -1,     4,     5,     6,     7,     8,
       9,    -1,    11,   829,   830,    -1,   832,    16,   834,    -1,
      -1,    -1,    -1,   839,    -1,    24,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    -1,   127,   852,    -1,    74,    75,
      -1,   133,   768,   135,    -1,   771,    -1,   139,    -1,    -1,
      -1,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,   157,    -1,   793,    -1,    -1,
      -1,    -1,    -1,   165,    10,    74,    75,    -1,    -1,    -1,
      -1,    -1,   174,   175,    -1,    21,    22,    23,   814,    25,
     816,    -1,    -1,    -1,    -1,    21,    32,    33,   190,    25,
     192,   193,   194,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    37,   204,    -1,     4,     5,     6,     7,     8,     9,
     846,    11,    12,    -1,    -1,    -1,    16,    -1,     0,    -1,
      -1,   223,    -1,    -1,    24,    -1,    -1,     9,    -1,    29,
     232,    15,    16,    17,    18,    19,    20,    19,   240,    -1,
      -1,    -1,    -1,    29,    30,    -1,    30,    31,    -1,    -1,
      32,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
      42,    -1,    -1,    16,    -1,   267,    -1,    53,    -1,    -1,
      -1,    24,    -1,    -1,    74,    75,    29,    -1,    -1,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,   290,   291,
     292,   293,    -1,    79,    10,    77,    -1,    -1,   300,    15,
      16,    17,    18,    19,    20,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   641,    -1,
      -1,    74,    75,    -1,    -1,   327,    -1,   650,    -1,    -1,
      -1,   333,    -1,    -1,     4,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,   127,    16,    -1,    -1,    -1,
      -1,   133,    -1,   135,    24,    -1,    -1,   139,   360,    29,
     362,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,   157,    -1,   159,   160,   161,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,   174,   175,    26,    27,    28,    -1,    30,    31,
      -1,   183,   184,   185,   186,   187,   188,    -1,    -1,   191,
      10,    -1,    -1,   195,    -1,    15,    16,    17,    18,    19,
      20,    21,    -1,   205,    -1,    25,    -1,   750,   751,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    37,     0,    -1,
      -1,    -1,   224,    -1,    -1,    -1,    -1,     9,    -1,    -1,
      -1,   233,   775,   776,    -1,   778,   779,    19,   781,    -1,
      -1,   243,    15,    16,    17,    18,    19,    20,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,     0,    30,    31,     3,
      42,    34,    35,    36,    37,   267,    15,    16,    17,    18,
      19,    -1,    -1,    -1,    -1,   818,    -1,    26,    -1,    28,
      -1,    30,    31,    -1,    -1,    -1,   829,   830,    -1,   832,
      -1,   834,    -1,    -1,    -1,    77,   839,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,   852,
      54,    55,    -1,     9,    -1,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,   327,    -1,    -1,    -1,    -1,
      26,   333,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    39,    -1,   127,    -1,    -1,    -1,    -1,
      -1,   133,    -1,   135,    -1,    -1,    -1,   139,   360,    -1,
     362,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,   157,    -1,    -1,   384,    -1,
      -1,    -1,   388,   165,    -1,    -1,   392,    -1,    -1,    10,
      -1,    -1,   174,   175,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,   190,    30,
      31,    -1,   194,    -1,   196,   197,    -1,    -1,    10,   641,
      -1,   427,   204,    15,    16,    17,    18,    19,   650,   435,
      -1,    -1,    -1,    -1,    26,    27,    28,    -1,    30,    31,
       0,   223,    -1,     3,     4,     5,     6,     7,     8,     9,
     232,    11,    -1,    -1,    -1,   461,    16,   463,   240,   465,
      -1,   467,    -1,   469,    24,   471,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,   480,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    -1,    -1,   267,    26,   493,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,
      60,    61,    62,    63,    64,    65,    66,     8,    68,    69,
      70,    71,    72,    73,    74,    75,     9,   523,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,   750,   751,
      -1,    -1,    25,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,   327,    39,    -1,    -1,    -1,
      -1,   333,    -1,   775,   776,    -1,   778,   779,    -1,   781,
       9,    -1,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,   578,    -1,    -1,    -1,    -1,    -1,   360,    -1,
     362,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      39,    -1,    -1,    -1,    -1,    -1,   818,    -1,    -1,    -1,
     606,    -1,   103,    -1,    -1,    -1,    -1,   829,   830,    -1,
     832,    -1,   834,    -1,   115,    -1,   117,   839,    -1,    -1,
      -1,   122,   123,    -1,    -1,    -1,   632,    10,    -1,    -1,
     852,    -1,    15,    16,    17,    18,    19,    20,    21,   641,
      15,    16,    17,    18,    19,    20,    -1,    -1,   650,    32,
      33,    34,    35,    36,    37,    30,    31,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,   182,   183,   184,   185,   186,   187,   188,    -1,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,    -1,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,     9,    -1,    -1,   750,   751,
      -1,    -1,   253,    -1,    -1,    19,    -1,   258,   259,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,   775,   776,    -1,   778,   779,    -1,   781,
       9,    10,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    25,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      39,    -1,    -1,    77,    -1,    -1,   818,    -1,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,   829,   830,    -1,
     832,    25,   834,    -1,    -1,    -1,    -1,   839,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,   348,    -1,    -1,
     852,    15,    16,    17,    18,    19,    20,    -1,    -1,   641,
      15,    16,    17,    18,    19,    20,    -1,    -1,   650,   133,
      34,    35,    36,    37,    -1,   139,    -1,    -1,    -1,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    -1,   157,    15,    16,    17,    18,    19,    20,
      15,    16,    17,    18,    19,    20,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,     0,     1,    -1,     3,
       4,     5,     6,     7,     8,     9,     8,    11,    10,    11,
      12,    -1,    16,    -1,    15,    16,    17,    18,    19,    20,
      24,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   750,   751,
      -1,    -1,    56,    57,    58,    -1,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    -1,   775,   776,    -1,   778,   779,    -1,   781,
      82,    83,    -1,   267,    -1,    -1,    88,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   115,    -1,   117,   818,    -1,    -1,    -1,
     122,   123,    -1,    -1,    -1,    -1,    -1,   829,   830,    -1,
     832,    -1,   834,    -1,    -1,    -1,    -1,   839,    -1,    -1,
      -1,    -1,    -1,   327,    -1,    -1,    -1,    -1,    -1,   333,
     852,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,    -1,
     182,   183,   184,   185,   186,   187,   188,    -1,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,    15,    16,    17,    18,    19,    20,
      -1,   253,    -1,    -1,    -1,    26,   258,   259,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,    -1,    -1,    -1,    -1,   290,    -1,
      -1,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,    -1,    -1,
     322,   323,   324,   325,   326,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,   348,   768,    -1,    -1,
     771,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,     1,   793,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    -1,    14,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    -1,   814,    24,   816,    10,    -1,    -1,    29,
      -1,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    25,    26,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,   846,    56,    57,    58,    -1,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,   641,    -1,    14,
      -1,    16,    -1,    -1,    -1,    -1,   650,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    -1,    13,    -1,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    56,    57,    58,    29,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    -1,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      -1,    -1,    14,    -1,    16,    -1,   750,   751,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    25,    -1,    -1,   778,    -1,    -1,   781,    32,    33,
      34,    35,    36,    37,    56,    57,    58,    -1,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,   818,    -1,    -1,    -1,    16,    15,
      16,    17,    18,    19,    20,    21,    24,    -1,   832,    -1,
     834,    29,    -1,    -1,    -1,   839,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    -1,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,     9,    -1,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,     9,    39,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    -1,
      22,    23,    -1,    25,    26,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   768,    -1,    -1,   771,
      -1,     9,    -1,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    -1,    22,    -1,    -1,    25,    26,    27,
      28,   793,    30,    31,    32,    33,    34,    35,    36,    37,
      10,    39,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,   814,    -1,   816,    -1,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      25,    26,    27,    28,   846,    30,    31,    32,    33,    34,
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
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    37
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     0,     3,     4,     5,     6,     7,     8,     9,    11,
      16,    24,    29,    56,    57,    58,    60,    61,    62,    63,
      64,    65,    66,    68,    69,    70,    71,    72,    73,    74,
      75,    78,    79,    81,    82,    86,    88,    89,    90,    91,
      92,    93,    94,    95,    97,    99,   102,   106,   107,   108,
     110,   111,   112,   114,   115,   118,   119,   122,   123,   124,
     125,   126,   128,   130,     8,    74,   111,   112,   114,   115,
     116,   118,   119,   122,   123,   124,   125,     3,    12,    74,
     110,   113,     9,    16,    74,    75,   122,   123,     9,   118,
     122,   123,   124,   125,     9,    16,   122,    74,    74,    87,
       9,   110,    74,    11,    67,   129,    67,   129,    67,   129,
      67,   129,    74,    74,   103,    11,    13,    39,    67,   117,
     120,   129,    11,    39,   117,     0,     0,     1,    81,     0,
       3,    80,    80,     9,     3,    13,    82,    83,    85,     9,
      80,    80,    80,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    54,    55,    80,     9,    11,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    25,    26,
      27,    28,    30,    31,    32,    33,    34,    35,    36,    37,
      39,   117,    11,    15,    16,    17,    25,    32,    33,   117,
      21,    25,    32,    33,    21,    25,    32,    33,    15,    16,
      17,    18,    19,    20,    21,    25,    26,    27,    28,    30,
      31,    32,    33,    34,    35,    36,    37,    15,    16,    17,
      18,    19,    20,    21,    25,    32,    33,    34,    35,    36,
      37,    11,    21,    25,    32,    33,    34,    35,    36,    37,
      21,    22,    23,    25,    32,    33,    67,   129,    67,     9,
      74,   103,    10,    11,   120,    10,    10,    10,    38,    40,
      10,    10,    10,    10,   113,     3,    12,    40,   122,   123,
      15,    16,    17,    18,    19,    26,    27,    28,    30,    31,
      15,    16,    17,    18,    19,    20,   122,   123,   124,   125,
      21,    32,    33,    21,    32,    33,    34,    35,    36,    37,
      21,    32,    33,    34,    35,    36,    37,    21,    25,    32,
      33,    34,    35,    36,    37,    21,    22,    23,    32,    33,
     122,   122,    15,    16,    17,    18,    19,    42,    40,    74,
      75,   106,   130,    42,    12,   111,   116,   122,   123,   124,
     125,   129,   129,   129,   129,     3,    13,     9,    41,   116,
      14,    39,   121,   111,   122,   129,   116,   111,    81,   110,
      13,    14,    79,    61,   110,   108,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,    10,
     109,   110,   116,   111,   114,   122,   123,   111,   114,   122,
     123,   111,   114,   122,   123,   111,   122,   123,   111,   122,
     123,   111,   123,   111,   118,   119,   122,   123,   124,   125,
     111,   125,   111,   125,   111,   124,   111,   122,   111,   122,
     111,   122,   111,   122,   111,   122,   111,   114,   118,   119,
     122,   123,   124,   125,   111,   114,   118,   119,   122,   123,
     124,   125,   111,   122,   123,   124,   111,   122,   123,   124,
     111,   122,   123,   124,   111,   122,   123,   124,   111,   116,
     111,   114,   111,   114,   111,   114,   111,   114,   111,   114,
     111,   114,   111,   118,   119,   122,   123,   124,   125,   111,
     114,   111,   118,   111,   118,   111,   118,   119,   122,   123,
     124,   125,   111,   114,   111,   119,   111,   119,   111,   122,
     123,   111,   122,   123,   111,   122,   123,   111,   122,   123,
     111,   122,   123,   122,   123,   111,   118,   119,   122,   123,
     124,   125,   111,   114,   111,   122,   111,   122,   111,   122,
     111,   122,   111,   122,   111,   122,   123,   111,   122,   123,
     111,   122,   123,   111,   122,   123,   111,   122,   123,   111,
     122,   123,   111,   122,   123,   111,   122,   123,   111,   122,
     123,   111,   122,   123,   111,   122,   123,   111,   122,   123,
     111,   118,   119,   122,   123,   124,   125,   111,   114,   111,
     122,   123,   111,   122,   123,   111,   122,   123,   111,   122,
     123,   111,   122,   123,   111,   122,   123,   116,   111,   118,
     119,   122,   123,   124,   125,   111,   114,   124,   111,   124,
     111,   124,   111,   124,   111,   124,   111,   124,   111,   124,
     111,   118,   119,   122,   123,   124,   125,   111,   125,   111,
     125,   111,   114,   111,   125,   111,   125,   129,    10,   127,
     130,    42,     9,   116,    10,   116,   116,     3,    12,    12,
       3,   110,   122,   123,   122,   123,   122,   123,   122,   123,
     122,   123,   122,   122,   122,   122,   122,   122,   123,   122,
     123,   122,   123,   122,   123,   122,   123,   122,   123,   118,
     122,   123,   124,   125,     9,   118,   118,   118,   122,   123,
     124,   125,   122,   123,   122,   123,   122,   123,   122,   123,
     122,   123,   122,   123,   118,   122,   123,   124,   125,   122,
     123,   122,   123,   122,   123,   122,   123,   122,   123,   122,
     123,   118,   122,   123,   124,   125,   124,   125,   124,   124,
     124,   124,   124,   124,   118,   122,   123,   124,   125,   125,
     125,   125,   125,   122,   122,   122,   122,   122,   110,    87,
      41,    41,    74,   110,   129,    12,    13,     3,    14,    56,
     100,   101,   130,    10,   104,   105,   130,    12,    41,   116,
      12,    41,    74,    14,    12,    10,    79,    14,     9,    10,
      10,    40,    12,    12,    12,    10,    40,   110,   120,    10,
     104,    12,    10,    38,    12,   110,     8,   110,   110,   129,
     100,   100,    74,    14,     3,    74,    83,    10,    40,    40,
      74,    12,   116,    12,    41,    12,    41,   116,    42,    85,
      14,     3,   110,    85,   110,   127,    83,    10,   116,    10,
      10,    14,    42,   100,    42,    83,   130,   105,   130,    42,
      12,    12,   116,    12,   116,    12,    41,   110,     3,    10,
      59,    96,    98,    83,    10,    82,    83,    84,    84,   110,
     110,    74,    74,   110,    12,    12,    12,   116,    40,    85,
      12,   121
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    77,    78,    78,    79,    79,    79,    80,    80,    81,
      81,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    83,    83,    83,    83,    83,    84,    84,
      85,    85,    86,    87,    87,    88,    88,    88,    89,    89,
      90,    90,    91,    92,    93,    94,    95,    96,    96,    97,
      98,    99,    99,    99,   100,   100,   100,   100,   101,   101,
     101,   102,   102,   102,   102,   103,   104,   104,   104,   105,
     105,   106,   107,   107,   107,   107,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     109,   109,   110,   110,   110,   110,   110,   110,   110,   110,
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
     111,   111,   111,   111,   111,   111,   111,   111,   111,   112,
     112,   112,   112,   112,   113,   113,   113,   114,   114,   114,
     114,   115,   115,   116,   116,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   118,   118,   119,
     119,   120,   120,   121,   121,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   126,   126,   127,
     127,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   129,   129,   129,   129,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     1,     2,     1,     2,     3,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     3,     4,     4,     5,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     1,     1,     2,
       7,     7,     5,     1,     6,     1,     6,     2,     0,     1,
       1,     4,     5,     6,     1,     2,     2,     3,     2,     4,
       4,     5,     6,     5,     6,     1,     2,     1,     4,     4,
       3,     2,     4,     4,     4,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     3,     3,     4,     4,     4,     4,
       4,     4,     2,     2,     2,     2,     3,     3,     3,     3,
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
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     4,     4,     5,     1,     3,     4,     1,     1,     3,
       3,     5,     7,     1,     1,     3,     4,     4,     5,     4,
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
       0,   226,   226,   227,   229,   230,   231,   234,   235,   238,
     239,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   256,   257,   258,   259,   260,   263,   264,
     267,   268,   272,   274,   275,   279,   280,   281,   283,   284,
     288,   289,   293,   295,   297,   299,   302,   304,   305,   307,
     308,   311,   312,   313,   315,   316,   317,   318,   320,   321,
     322,   326,   327,   328,   329,   331,   333,   334,   335,   337,
     338,   342,   346,   347,   348,   349,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     370,   371,   375,   376,   377,   378,   379,   380,   381,   382,
     385,   386,   387,   388,   389,   391,   392,   394,   395,   396,
     397,   398,   400,   401,   402,   403,   405,   406,   407,   409,
     410,   411,   413,   414,   415,   416,   417,   418,   419,   420,
     422,   423,   424,   425,   426,   428,   429,   430,   431,   432,
     434,   435,   436,   437,   438,   439,   440,   441,   443,   444,
     445,   446,   447,   448,   449,   450,   452,   453,   454,   456,
     457,   458,   460,   461,   462,   463,   464,   465,   466,   468,
     469,   470,   471,   472,   473,   474,   476,   477,   478,   479,
     480,   481,   482,   484,   485,   486,   487,   488,   489,   490,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   508,   510,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   526,   528,   529,   530,   532,   533,   534,
     536,   537,   538,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   553,   554,   555,   557,
     558,   559,   561,   562,   563,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   592,
     593,   594,   595,   596,   598,   599,   600,   604,   605,   606,
     607,   609,   610,   612,   613,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   630,   631,   635,
     636,   638,   639,   641,   642,   646,   647,   648,   649,   650,
     651,   652,   653,   654,   655,   656,   657,   658,   659,   663,
     664,   665,   666,   667,   668,   669,   670,   671,   672,   673,
     674,   675,   676,   677,   678,   679,   680,   681,   682,   683,
     687,   688,   689,   690,   691,   692,   693,   694,   695,   696,
     697,   698,   699,   700,   701,   702,   703,   704,   705,   706,
     707,   708,   709,   710,   711,   712,   713,   717,   718,   719,
     720,   721,   723,   724,   725,   726,   727,   728,   729,   731,
     732,   733,   734,   735,   736,   737,   739,   740,   741,   742,
     743,   745,   746,   747,   748,   749,   751,   752,   753,   754,
     755,   757,   758,   759,   760,   761,   763,   767,   768,   770,
     771,   775,   776,   777,   778,   779,   780,   781,   782,   783,
     784,   785,   786,   788,   789,   790,   791,   795,   796,   797,
     798,   799,   800,   801,   802,   803,   804,   805,   806,   807,
     808
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
#line 4782 "frontend/parser.cpp"

#line 811 "frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    auto msg = std::to_string(scanner->loc->begin.line) + ":" + std::to_string(scanner->loc->begin.column) + ": " + err_message;
    scanner->fatal_error(ptc::diag::ERR_SYNTAX, msg);
}
