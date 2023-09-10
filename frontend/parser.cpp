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

  case 41: // for: "for" "(" "identifier" ":" expr ")" body
#line 289 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1377 "frontend/parser.cpp"
    break;

  case 42: // for: "for" "(" "external identifier" ":" expr ")" body
#line 290 "frontend/parser.yy"
                                              { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1383 "frontend/parser.cpp"
    break;

  case 43: // while: wh_kw "(" expr ")" scope_body
#line 294 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseWhile(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1389 "frontend/parser.cpp"
    break;

  case 44: // wh_kw: "while"
#line 296 "frontend/parser.yy"
                { scanner->enterBlockScope(); }
#line 1395 "frontend/parser.cpp"
    break;

  case 45: // dowhile: do_kw scope_body "while" "(" expr ")"
#line 298 "frontend/parser.yy"
                                                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseDoWhile(yystack_[1].value.as < ptc::ir::Expr * > (), yystack_[4].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1401 "frontend/parser.cpp"
    break;

  case 46: // do_kw: "do"
#line 300 "frontend/parser.yy"
             { scanner->enterBlockScope(); }
#line 1407 "frontend/parser.cpp"
    break;

  case 47: // if: if_kw "(" expr ")" scope_body else
#line 303 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseIfStmt(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1413 "frontend/parser.cpp"
    break;

  case 48: // else: el_kw scope_body
#line 305 "frontend/parser.yy"
                         { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1419 "frontend/parser.cpp"
    break;

  case 49: // else: %empty
#line 306 "frontend/parser.yy"
                    { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1425 "frontend/parser.cpp"
    break;

  case 50: // if_kw: "if"
#line 308 "frontend/parser.yy"
             { scanner->enterBlockScope(); }
#line 1431 "frontend/parser.cpp"
    break;

  case 51: // el_kw: "else"
#line 309 "frontend/parser.yy"
               { scanner->enterBlockScope(); }
#line 1437 "frontend/parser.cpp"
    break;

  case 52: // struct: "'struct'" "identifier" "{" "}"
#line 312 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[2].value.as < std::string > (), std::vector<ptc::ir::IR *>{}); }
#line 1443 "frontend/parser.cpp"
    break;

  case 53: // struct: "'struct'" "identifier" "{" decllist "}"
#line 313 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1449 "frontend/parser.cpp"
    break;

  case 54: // struct: "'struct'" "identifier" "terminator (\\n or ;)" "{" decllist "}"
#line 314 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[4].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1455 "frontend/parser.cpp"
    break;

  case 56: // decllist: "terminator (\\n or ;)" decllist
#line 317 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1461 "frontend/parser.cpp"
    break;

  case 57: // decllist: declistval "terminator (\\n or ;)"
#line 318 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[1].value.as < ptc::ir::IR * > (), std::vector<ptc::ir::IR *>{}); }
#line 1467 "frontend/parser.cpp"
    break;

  case 58: // decllist: declistval "terminator (\\n or ;)" decllist
#line 319 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[2].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1473 "frontend/parser.cpp"
    break;

  case 59: // declistval: type "identifier"
#line 321 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > (), nullptr); }
#line 1479 "frontend/parser.cpp"
    break;

  case 60: // declistval: type "identifier" "=" expr
#line 322 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1485 "frontend/parser.cpp"
    break;

  case 62: // function: type fun_id "(" ")" block
#line 327 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1491 "frontend/parser.cpp"
    break;

  case 63: // function: type fun_id "(" funargs ")" block
#line 328 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[5].value.as < ptc::ir::IR * > (), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1497 "frontend/parser.cpp"
    break;

  case 64: // function: "'void'" fun_id "(" ")" block
#line 329 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1503 "frontend/parser.cpp"
    break;

  case 65: // function: "'void'" fun_id "(" funargs ")" block
#line 330 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1509 "frontend/parser.cpp"
    break;

  case 66: // fun_id: "identifier"
#line 332 "frontend/parser.yy"
            { scanner->enterFunScope(); yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1515 "frontend/parser.cpp"
    break;

  case 67: // funargs: type "identifier"
#line 334 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseFunParam(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1521 "frontend/parser.cpp"
    break;

  case 69: // funargs: funargs "," type "identifier"
#line 336 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseAddFunParam(yystack_[3].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1527 "frontend/parser.cpp"
    break;

  case 72: // vardecl: type "identifier"
#line 343 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1533 "frontend/parser.cpp"
    break;

  case 73: // vardef: type "identifier" "=" struct_val
#line 347 "frontend/parser.yy"
         { yylhs.value.as < ptc::ir::IR * > () = yystack_[3].value.as < ptc::ir::IR * > (); }
#line 1539 "frontend/parser.cpp"
    break;

  case 74: // vardef: type "identifier" "=" expr
#line 348 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1545 "frontend/parser.cpp"
    break;

  case 77: // set: expr "++=" expr
#line 354 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1551 "frontend/parser.cpp"
    break;

  case 78: // set: expr "**=" expr
#line 355 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1557 "frontend/parser.cpp"
    break;

  case 79: // set: expr "%=" expr
#line 356 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1563 "frontend/parser.cpp"
    break;

  case 80: // set: expr "/=" expr
#line 357 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1569 "frontend/parser.cpp"
    break;

  case 81: // set: expr "*=" expr
#line 358 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1575 "frontend/parser.cpp"
    break;

  case 82: // set: expr "-=" expr
#line 359 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1581 "frontend/parser.cpp"
    break;

  case 83: // set: expr "+=" expr
#line 360 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1587 "frontend/parser.cpp"
    break;

  case 84: // set: expr "&=" expr
#line 361 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1593 "frontend/parser.cpp"
    break;

  case 85: // set: expr "|=" expr
#line 362 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1599 "frontend/parser.cpp"
    break;

  case 86: // set: expr "^=" expr
#line 363 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1605 "frontend/parser.cpp"
    break;

  case 87: // set: expr "<<=" expr
#line 364 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1611 "frontend/parser.cpp"
    break;

  case 88: // set: expr ">>=" expr
#line 365 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1617 "frontend/parser.cpp"
    break;

  case 89: // set: expr "=" expr
#line 366 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1623 "frontend/parser.cpp"
    break;

  case 90: // set: expr "=" set
#line 367 "frontend/parser.yy"
      { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1629 "frontend/parser.cpp"
    break;

  case 91: // callarglist: expr
#line 371 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseFunCallArg(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1635 "frontend/parser.cpp"
    break;

  case 92: // callarglist: callarglist "," expr
#line 372 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddFunCallArg(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1641 "frontend/parser.cpp"
    break;

  case 93: // expr: expr_mat
#line 376 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1647 "frontend/parser.cpp"
    break;

  case 94: // expr: expr_var
#line 377 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1653 "frontend/parser.cpp"
    break;

  case 97: // expr: expr_int
#line 380 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 1659 "frontend/parser.cpp"
    break;

  case 98: // expr: expr_float
#line 381 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFloat(yystack_[0].value.as < double > ()); }
#line 1665 "frontend/parser.cpp"
    break;

  case 99: // expr: expr_str
#line 382 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseString(yystack_[0].value.as < std::string > ()); }
#line 1671 "frontend/parser.cpp"
    break;

  case 100: // expr: expr_bool
#line 383 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseBool(yystack_[0].value.as < bool > ()); }
#line 1677 "frontend/parser.cpp"
    break;

  case 101: // expr_var: "identifier"
#line 386 "frontend/parser.yy"
              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > ()); }
#line 1683 "frontend/parser.cpp"
    break;

  case 102: // expr_var: "external identifier"
#line 387 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > (), true); }
#line 1689 "frontend/parser.cpp"
    break;

  case 103: // expr_var: "-" "identifier"
#line 388 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1695 "frontend/parser.cpp"
    break;

  case 104: // expr_var: "-" "external identifier"
#line 389 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > (), true), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1701 "frontend/parser.cpp"
    break;

  case 105: // expr_var: "(" expr_var ")"
#line 390 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1707 "frontend/parser.cpp"
    break;

  case 106: // expr_var: expr_var "(" ")"
#line 392 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[2].value.as < ptc::ir::Expr * > (), std::vector<ptc::ir::Expr *>{}); }
#line 1713 "frontend/parser.cpp"
    break;

  case 107: // expr_var: expr_var "(" callarglist ")"
#line 393 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 1719 "frontend/parser.cpp"
    break;

  case 108: // expr_var: expr_str "[" int_val "]"
#line 395 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1725 "frontend/parser.cpp"
    break;

  case 109: // expr_var: expr_mat "[" int_val "]"
#line 396 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1731 "frontend/parser.cpp"
    break;

  case 110: // expr_var: "identifier" "[" int_val "]"
#line 397 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1737 "frontend/parser.cpp"
    break;

  case 111: // expr_var: "external identifier" "[" int_val "]"
#line 398 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1743 "frontend/parser.cpp"
    break;

  case 112: // expr_var: expr_var "[" int_val "]"
#line 399 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1749 "frontend/parser.cpp"
    break;

  case 113: // expr_var: expr_mat slice
#line 401 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1755 "frontend/parser.cpp"
    break;

  case 116: // expr_var: expr_var slice
#line 404 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1761 "frontend/parser.cpp"
    break;

  case 117: // expr_var: "identifier" "." expr_var
#line 406 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1767 "frontend/parser.cpp"
    break;

  case 118: // expr_var: "external identifier" "." expr_var
#line 407 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1773 "frontend/parser.cpp"
    break;

  case 119: // expr_var: expr_var "." expr_var
#line 408 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1779 "frontend/parser.cpp"
    break;

  case 121: // expr_var: expr_var "**" expr_float
#line 411 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1785 "frontend/parser.cpp"
    break;

  case 122: // expr_var: expr_var "**" expr_var
#line 412 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1791 "frontend/parser.cpp"
    break;

  case 123: // expr_var: expr_int "*" expr_var
#line 414 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1797 "frontend/parser.cpp"
    break;

  case 124: // expr_var: expr_float "*" expr_var
#line 415 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1803 "frontend/parser.cpp"
    break;

  case 125: // expr_var: expr_var "*" expr_int
#line 416 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1809 "frontend/parser.cpp"
    break;

  case 126: // expr_var: expr_var "*" expr_float
#line 417 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1815 "frontend/parser.cpp"
    break;

  case 127: // expr_var: expr_mat "*" expr_mat
#line 418 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1821 "frontend/parser.cpp"
    break;

  case 128: // expr_var: expr_mat "*" expr_var
#line 419 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1827 "frontend/parser.cpp"
    break;

  case 129: // expr_var: expr_var "*" expr_mat
#line 420 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1833 "frontend/parser.cpp"
    break;

  case 130: // expr_var: expr_var "*" expr_var
#line 421 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1839 "frontend/parser.cpp"
    break;

  case 131: // expr_var: expr_int "/" expr_var
#line 423 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1845 "frontend/parser.cpp"
    break;

  case 132: // expr_var: expr_float "/" expr_var
#line 424 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1851 "frontend/parser.cpp"
    break;

  case 133: // expr_var: expr_var "/" expr_int
#line 425 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1857 "frontend/parser.cpp"
    break;

  case 134: // expr_var: expr_var "/" expr_float
#line 426 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1863 "frontend/parser.cpp"
    break;

  case 135: // expr_var: expr_var "/" expr_var
#line 427 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1869 "frontend/parser.cpp"
    break;

  case 136: // expr_var: expr_int "%" expr_var
#line 429 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1875 "frontend/parser.cpp"
    break;

  case 137: // expr_var: expr_float "%" expr_var
#line 430 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1881 "frontend/parser.cpp"
    break;

  case 138: // expr_var: expr_var "%" expr_int
#line 431 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1887 "frontend/parser.cpp"
    break;

  case 139: // expr_var: expr_var "%" expr_float
#line 432 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1893 "frontend/parser.cpp"
    break;

  case 140: // expr_var: expr_var "%" expr_var
#line 433 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1899 "frontend/parser.cpp"
    break;

  case 141: // expr_var: expr_int "+" expr_var
#line 435 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1905 "frontend/parser.cpp"
    break;

  case 142: // expr_var: expr_float "+" expr_var
#line 436 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1911 "frontend/parser.cpp"
    break;

  case 143: // expr_var: expr_var "+" expr_int
#line 437 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1917 "frontend/parser.cpp"
    break;

  case 144: // expr_var: expr_var "+" expr_float
#line 438 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1923 "frontend/parser.cpp"
    break;

  case 145: // expr_var: expr_mat "+" expr_mat
#line 439 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1929 "frontend/parser.cpp"
    break;

  case 146: // expr_var: expr_var "+" expr_mat
#line 440 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1935 "frontend/parser.cpp"
    break;

  case 147: // expr_var: expr_mat "+" expr_var
#line 441 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1941 "frontend/parser.cpp"
    break;

  case 148: // expr_var: expr_var "+" expr_var
#line 442 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1947 "frontend/parser.cpp"
    break;

  case 149: // expr_var: expr_int "-" expr_var
#line 444 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1953 "frontend/parser.cpp"
    break;

  case 150: // expr_var: expr_float "-" expr_var
#line 445 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1959 "frontend/parser.cpp"
    break;

  case 151: // expr_var: expr_var "-" expr_int
#line 446 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1965 "frontend/parser.cpp"
    break;

  case 152: // expr_var: expr_var "-" expr_float
#line 447 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1971 "frontend/parser.cpp"
    break;

  case 153: // expr_var: expr_mat "-" expr_mat
#line 448 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1977 "frontend/parser.cpp"
    break;

  case 154: // expr_var: expr_var "-" expr_mat
#line 449 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1983 "frontend/parser.cpp"
    break;

  case 155: // expr_var: expr_mat "-" expr_var
#line 450 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1989 "frontend/parser.cpp"
    break;

  case 156: // expr_var: expr_var "-" expr_var
#line 451 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1995 "frontend/parser.cpp"
    break;

  case 157: // expr_var: expr_int "<<" expr_var
#line 453 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2001 "frontend/parser.cpp"
    break;

  case 158: // expr_var: expr_var "<<" expr_int
#line 454 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2007 "frontend/parser.cpp"
    break;

  case 159: // expr_var: expr_var "<<" expr_var
#line 455 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2013 "frontend/parser.cpp"
    break;

  case 160: // expr_var: expr_int ">>" expr_var
#line 457 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2019 "frontend/parser.cpp"
    break;

  case 161: // expr_var: expr_var ">>" expr_int
#line 458 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2025 "frontend/parser.cpp"
    break;

  case 162: // expr_var: expr_var ">>" expr_var
#line 459 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2031 "frontend/parser.cpp"
    break;

  case 163: // expr_var: expr_int ">" expr_var
#line 461 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2037 "frontend/parser.cpp"
    break;

  case 164: // expr_var: expr_float ">" expr_var
#line 462 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2043 "frontend/parser.cpp"
    break;

  case 166: // expr_var: expr_var ">" expr_int
#line 464 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2049 "frontend/parser.cpp"
    break;

  case 167: // expr_var: expr_var ">" expr_float
#line 465 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2055 "frontend/parser.cpp"
    break;

  case 168: // expr_var: expr_var ">" expr_str
#line 466 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2061 "frontend/parser.cpp"
    break;

  case 169: // expr_var: expr_var ">" expr_var
#line 467 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2067 "frontend/parser.cpp"
    break;

  case 170: // expr_var: expr_int ">=" expr_var
#line 469 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2073 "frontend/parser.cpp"
    break;

  case 171: // expr_var: expr_float ">=" expr_var
#line 470 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2079 "frontend/parser.cpp"
    break;

  case 173: // expr_var: expr_var ">=" expr_int
#line 472 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2085 "frontend/parser.cpp"
    break;

  case 174: // expr_var: expr_var ">=" expr_float
#line 473 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2091 "frontend/parser.cpp"
    break;

  case 175: // expr_var: expr_var ">=" expr_str
#line 474 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2097 "frontend/parser.cpp"
    break;

  case 176: // expr_var: expr_var ">=" expr_var
#line 475 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2103 "frontend/parser.cpp"
    break;

  case 177: // expr_var: expr_int "<" expr_var
#line 477 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2109 "frontend/parser.cpp"
    break;

  case 178: // expr_var: expr_float "<" expr_var
#line 478 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2115 "frontend/parser.cpp"
    break;

  case 180: // expr_var: expr_var "<" expr_int
#line 480 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2121 "frontend/parser.cpp"
    break;

  case 181: // expr_var: expr_var "<" expr_float
#line 481 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2127 "frontend/parser.cpp"
    break;

  case 182: // expr_var: expr_var "<" expr_str
#line 482 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2133 "frontend/parser.cpp"
    break;

  case 183: // expr_var: expr_var "<" expr_var
#line 483 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2139 "frontend/parser.cpp"
    break;

  case 184: // expr_var: expr_int "<=" expr_var
#line 485 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2145 "frontend/parser.cpp"
    break;

  case 185: // expr_var: expr_float "<=" expr_var
#line 486 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2151 "frontend/parser.cpp"
    break;

  case 187: // expr_var: expr_var "<=" expr_int
#line 488 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2157 "frontend/parser.cpp"
    break;

  case 188: // expr_var: expr_var "<=" expr_float
#line 489 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2163 "frontend/parser.cpp"
    break;

  case 189: // expr_var: expr_var "<=" expr_str
#line 490 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2169 "frontend/parser.cpp"
    break;

  case 190: // expr_var: expr_var "<=" expr_var
#line 491 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2175 "frontend/parser.cpp"
    break;

  case 191: // expr_var: expr_int "==" expr_var
#line 493 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2181 "frontend/parser.cpp"
    break;

  case 192: // expr_var: expr_float "==" expr_var
#line 494 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2187 "frontend/parser.cpp"
    break;

  case 194: // expr_var: expr_bool "==" expr_var
#line 496 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2193 "frontend/parser.cpp"
    break;

  case 198: // expr_var: expr_var "==" expr_int
#line 500 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2199 "frontend/parser.cpp"
    break;

  case 199: // expr_var: expr_var "==" expr_float
#line 501 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2205 "frontend/parser.cpp"
    break;

  case 200: // expr_var: expr_var "==" expr_str
#line 502 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2211 "frontend/parser.cpp"
    break;

  case 201: // expr_var: expr_var "==" expr_bool
#line 503 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2217 "frontend/parser.cpp"
    break;

  case 202: // expr_var: expr_var "==" expr_none
#line 504 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2223 "frontend/parser.cpp"
    break;

  case 203: // expr_var: expr_var "==" expr_struct
#line 505 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2229 "frontend/parser.cpp"
    break;

  case 204: // expr_var: expr_mat "==" expr_mat
#line 506 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2235 "frontend/parser.cpp"
    break;

  case 205: // expr_var: expr_var "==" expr_mat
#line 507 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2241 "frontend/parser.cpp"
    break;

  case 206: // expr_var: expr_mat "==" expr_var
#line 508 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2247 "frontend/parser.cpp"
    break;

  case 207: // expr_var: expr_var "==" expr_var
#line 509 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2253 "frontend/parser.cpp"
    break;

  case 208: // expr_var: expr_int "!=" expr_var
#line 511 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2259 "frontend/parser.cpp"
    break;

  case 209: // expr_var: expr_float "!=" expr_var
#line 512 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2265 "frontend/parser.cpp"
    break;

  case 215: // expr_var: expr_var "!=" expr_int
#line 518 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2271 "frontend/parser.cpp"
    break;

  case 216: // expr_var: expr_var "!=" expr_float
#line 519 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2277 "frontend/parser.cpp"
    break;

  case 217: // expr_var: expr_var "!=" expr_str
#line 520 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2283 "frontend/parser.cpp"
    break;

  case 218: // expr_var: expr_var "!=" expr_bool
#line 521 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2289 "frontend/parser.cpp"
    break;

  case 219: // expr_var: expr_var "!=" expr_none
#line 522 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2295 "frontend/parser.cpp"
    break;

  case 220: // expr_var: expr_var "!=" expr_struct
#line 523 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2301 "frontend/parser.cpp"
    break;

  case 221: // expr_var: expr_mat "!=" expr_mat
#line 524 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2307 "frontend/parser.cpp"
    break;

  case 222: // expr_var: expr_var "!=" expr_mat
#line 525 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2313 "frontend/parser.cpp"
    break;

  case 223: // expr_var: expr_mat "!=" expr_var
#line 526 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2319 "frontend/parser.cpp"
    break;

  case 224: // expr_var: expr_var "!=" expr_var
#line 527 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2325 "frontend/parser.cpp"
    break;

  case 225: // expr_var: expr_int "&" expr_var
#line 529 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2331 "frontend/parser.cpp"
    break;

  case 226: // expr_var: expr_var "&" expr_int
#line 530 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2337 "frontend/parser.cpp"
    break;

  case 227: // expr_var: expr_var "&" expr_var
#line 531 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2343 "frontend/parser.cpp"
    break;

  case 228: // expr_var: expr_int "^" expr_var
#line 533 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2349 "frontend/parser.cpp"
    break;

  case 229: // expr_var: expr_var "^" expr_int
#line 534 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2355 "frontend/parser.cpp"
    break;

  case 230: // expr_var: expr_var "^" expr_var
#line 535 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2361 "frontend/parser.cpp"
    break;

  case 231: // expr_var: expr_int "|" expr_var
#line 537 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2367 "frontend/parser.cpp"
    break;

  case 232: // expr_var: expr_var "|" expr_int
#line 538 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2373 "frontend/parser.cpp"
    break;

  case 233: // expr_var: expr_var "|" expr_var
#line 539 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2379 "frontend/parser.cpp"
    break;

  case 240: // expr_var: expr_mat "in" expr_mat
#line 547 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2385 "frontend/parser.cpp"
    break;

  case 247: // expr_var: expr_mat "in" expr_var
#line 554 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2391 "frontend/parser.cpp"
    break;

  case 248: // expr_var: expr_var "in" expr_str
#line 555 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2397 "frontend/parser.cpp"
    break;

  case 249: // expr_var: expr_var "in" expr_var
#line 556 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2403 "frontend/parser.cpp"
    break;

  case 250: // expr_var: expr_bool "and" expr_var
#line 558 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2409 "frontend/parser.cpp"
    break;

  case 251: // expr_var: expr_var "and" expr_bool
#line 559 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2415 "frontend/parser.cpp"
    break;

  case 252: // expr_var: expr_var "and" expr_var
#line 560 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2421 "frontend/parser.cpp"
    break;

  case 253: // expr_var: expr_bool "or" expr_var
#line 562 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2427 "frontend/parser.cpp"
    break;

  case 254: // expr_var: expr_var "or" expr_bool
#line 563 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2433 "frontend/parser.cpp"
    break;

  case 255: // expr_var: expr_var "or" expr_var
#line 564 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2439 "frontend/parser.cpp"
    break;

  case 267: // expr_var: expr_int "++" expr_var
#line 577 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2445 "frontend/parser.cpp"
    break;

  case 268: // expr_var: expr_float "++" expr_var
#line 578 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2451 "frontend/parser.cpp"
    break;

  case 269: // expr_var: expr_str "++" expr_var
#line 579 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2457 "frontend/parser.cpp"
    break;

  case 270: // expr_var: expr_bool "++" expr_var
#line 580 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2463 "frontend/parser.cpp"
    break;

  case 273: // expr_var: expr_var "++" expr_int
#line 583 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2469 "frontend/parser.cpp"
    break;

  case 274: // expr_var: expr_var "++" expr_float
#line 584 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2475 "frontend/parser.cpp"
    break;

  case 275: // expr_var: expr_var "++" expr_str
#line 585 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2481 "frontend/parser.cpp"
    break;

  case 276: // expr_var: expr_var "++" expr_bool
#line 586 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2487 "frontend/parser.cpp"
    break;

  case 277: // expr_var: expr_var "++" expr_none
#line 587 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2493 "frontend/parser.cpp"
    break;

  case 278: // expr_var: expr_var "++" expr_struct
#line 588 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2499 "frontend/parser.cpp"
    break;

  case 279: // expr_var: expr_var "++" expr_var
#line 589 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2505 "frontend/parser.cpp"
    break;

  case 280: // matrix: "[" "]"
#line 593 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(std::vector<ptc::ir::Expr *>{}); }
#line 2511 "frontend/parser.cpp"
    break;

  case 281: // matrix: "[" matvals "]"
#line 594 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2517 "frontend/parser.cpp"
    break;

  case 282: // matrix: "[" "terminator (\\n or ;)" matvals "]"
#line 595 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2523 "frontend/parser.cpp"
    break;

  case 283: // matrix: "[" matvals "terminator (\\n or ;)" "]"
#line 596 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2529 "frontend/parser.cpp"
    break;

  case 284: // matrix: "[" "terminator (\\n or ;)" matvals "terminator (\\n or ;)" "]"
#line 597 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2535 "frontend/parser.cpp"
    break;

  case 285: // matvals: expr
#line 599 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixValue(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2541 "frontend/parser.cpp"
    break;

  case 286: // matvals: matvals "," expr
#line 600 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2547 "frontend/parser.cpp"
    break;

  case 287: // matvals: matvals "," "terminator (\\n or ;)" expr
#line 601 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[3].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2553 "frontend/parser.cpp"
    break;

  case 288: // expr_mat: matrix
#line 605 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2559 "frontend/parser.cpp"
    break;

  case 294: // int_val: expr_int
#line 613 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 2565 "frontend/parser.cpp"
    break;

  case 295: // int_val: expr_var
#line 614 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2571 "frontend/parser.cpp"
    break;

  case 316: // expr_int: "int"
#line 647 "frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 2577 "frontend/parser.cpp"
    break;

  case 317: // expr_int: "-" expr_int
#line 648 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 2583 "frontend/parser.cpp"
    break;

  case 318: // expr_int: "(" expr_int ")"
#line 649 "frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 2589 "frontend/parser.cpp"
    break;

  case 319: // expr_int: "~" expr_int
#line 650 "frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 2595 "frontend/parser.cpp"
    break;

  case 320: // expr_int: expr_int "*" expr_int
#line 651 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 2601 "frontend/parser.cpp"
    break;

  case 321: // expr_int: expr_int "/" expr_int
#line 652 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 2607 "frontend/parser.cpp"
    break;

  case 322: // expr_int: expr_int "%" expr_int
#line 653 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 2613 "frontend/parser.cpp"
    break;

  case 323: // expr_int: expr_int "-" expr_int
#line 654 "frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 2619 "frontend/parser.cpp"
    break;

  case 324: // expr_int: expr_int "+" expr_int
#line 655 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 2625 "frontend/parser.cpp"
    break;

  case 325: // expr_int: expr_int "<<" expr_int
#line 656 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 2631 "frontend/parser.cpp"
    break;

  case 326: // expr_int: expr_int ">>" expr_int
#line 657 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 2637 "frontend/parser.cpp"
    break;

  case 327: // expr_int: expr_int "&" expr_int
#line 658 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 2643 "frontend/parser.cpp"
    break;

  case 328: // expr_int: expr_int "^" expr_int
#line 659 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 2649 "frontend/parser.cpp"
    break;

  case 329: // expr_int: expr_int "|" expr_int
#line 660 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 2655 "frontend/parser.cpp"
    break;

  case 330: // expr_float: "float"
#line 664 "frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 2661 "frontend/parser.cpp"
    break;

  case 331: // expr_float: "-" expr_float
#line 665 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 2667 "frontend/parser.cpp"
    break;

  case 332: // expr_float: "(" expr_float ")"
#line 666 "frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 2673 "frontend/parser.cpp"
    break;

  case 333: // expr_float: expr_float "**" expr_float
#line 667 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2679 "frontend/parser.cpp"
    break;

  case 334: // expr_float: expr_float "**" expr_int
#line 668 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2685 "frontend/parser.cpp"
    break;

  case 335: // expr_float: expr_int "**" expr_float
#line 669 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2691 "frontend/parser.cpp"
    break;

  case 336: // expr_float: expr_float "*" expr_float
#line 670 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 2697 "frontend/parser.cpp"
    break;

  case 337: // expr_float: expr_float "*" expr_int
#line 671 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 2703 "frontend/parser.cpp"
    break;

  case 338: // expr_float: expr_int "*" expr_float
#line 672 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 2709 "frontend/parser.cpp"
    break;

  case 339: // expr_float: expr_float "/" expr_float
#line 673 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 2715 "frontend/parser.cpp"
    break;

  case 340: // expr_float: expr_float "/" expr_int
#line 674 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 2721 "frontend/parser.cpp"
    break;

  case 341: // expr_float: expr_int "/" expr_float
#line 675 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 2727 "frontend/parser.cpp"
    break;

  case 342: // expr_float: expr_float "%" expr_float
#line 676 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2733 "frontend/parser.cpp"
    break;

  case 343: // expr_float: expr_float "%" expr_int
#line 677 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2739 "frontend/parser.cpp"
    break;

  case 344: // expr_float: expr_int "%" expr_float
#line 678 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2745 "frontend/parser.cpp"
    break;

  case 345: // expr_float: expr_float "-" expr_float
#line 679 "frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 2751 "frontend/parser.cpp"
    break;

  case 346: // expr_float: expr_float "-" expr_int
#line 680 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 2757 "frontend/parser.cpp"
    break;

  case 347: // expr_float: expr_int "-" expr_float
#line 681 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 2763 "frontend/parser.cpp"
    break;

  case 348: // expr_float: expr_float "+" expr_float
#line 682 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 2769 "frontend/parser.cpp"
    break;

  case 349: // expr_float: expr_float "+" expr_int
#line 683 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 2775 "frontend/parser.cpp"
    break;

  case 350: // expr_float: expr_int "+" expr_float
#line 684 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 2781 "frontend/parser.cpp"
    break;

  case 351: // expr_str: "string"
#line 688 "frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2787 "frontend/parser.cpp"
    break;

  case 352: // expr_str: "(" expr_str ")"
#line 689 "frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 2793 "frontend/parser.cpp"
    break;

  case 353: // expr_str: expr_str "++" expr_str
#line 690 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 2799 "frontend/parser.cpp"
    break;

  case 354: // expr_str: expr_str "++" expr_int
#line 691 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 2805 "frontend/parser.cpp"
    break;

  case 355: // expr_str: expr_str "++" expr_float
#line 692 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 2811 "frontend/parser.cpp"
    break;

  case 356: // expr_str: expr_str "++" expr_bool
#line 693 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2817 "frontend/parser.cpp"
    break;

  case 357: // expr_str: expr_str "++" expr_none
#line 694 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 2823 "frontend/parser.cpp"
    break;

  case 358: // expr_str: expr_int "++" expr_str
#line 695 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 2829 "frontend/parser.cpp"
    break;

  case 359: // expr_str: expr_int "++" expr_int
#line 696 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 2835 "frontend/parser.cpp"
    break;

  case 360: // expr_str: expr_int "++" expr_float
#line 697 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 2841 "frontend/parser.cpp"
    break;

  case 361: // expr_str: expr_int "++" expr_bool
#line 698 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2847 "frontend/parser.cpp"
    break;

  case 362: // expr_str: expr_int "++" expr_none
#line 699 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 2853 "frontend/parser.cpp"
    break;

  case 363: // expr_str: expr_float "++" expr_str
#line 700 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 2859 "frontend/parser.cpp"
    break;

  case 364: // expr_str: expr_float "++" expr_int
#line 701 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 2865 "frontend/parser.cpp"
    break;

  case 365: // expr_str: expr_float "++" expr_float
#line 702 "frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 2871 "frontend/parser.cpp"
    break;

  case 366: // expr_str: expr_float "++" expr_bool
#line 703 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2877 "frontend/parser.cpp"
    break;

  case 367: // expr_str: expr_float "++" expr_none
#line 704 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 2883 "frontend/parser.cpp"
    break;

  case 368: // expr_str: expr_bool "++" expr_str
#line 705 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 2889 "frontend/parser.cpp"
    break;

  case 369: // expr_str: expr_bool "++" expr_int
#line 706 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 2895 "frontend/parser.cpp"
    break;

  case 370: // expr_str: expr_bool "++" expr_float
#line 707 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 2901 "frontend/parser.cpp"
    break;

  case 371: // expr_str: expr_bool "++" expr_bool
#line 708 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2907 "frontend/parser.cpp"
    break;

  case 372: // expr_str: expr_bool "++" expr_none
#line 709 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 2913 "frontend/parser.cpp"
    break;

  case 373: // expr_str: expr_none "++" expr_str
#line 710 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 2919 "frontend/parser.cpp"
    break;

  case 374: // expr_str: expr_none "++" expr_int
#line 711 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 2925 "frontend/parser.cpp"
    break;

  case 375: // expr_str: expr_none "++" expr_float
#line 712 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 2931 "frontend/parser.cpp"
    break;

  case 376: // expr_str: expr_none "++" expr_bool
#line 713 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2937 "frontend/parser.cpp"
    break;

  case 377: // expr_str: expr_none "++" expr_none
#line 714 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 2943 "frontend/parser.cpp"
    break;

  case 378: // expr_bool: "bool"
#line 718 "frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 2949 "frontend/parser.cpp"
    break;

  case 379: // expr_bool: "(" expr_bool ")"
#line 719 "frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 2955 "frontend/parser.cpp"
    break;

  case 380: // expr_bool: "not" expr_bool
#line 720 "frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 2961 "frontend/parser.cpp"
    break;

  case 381: // expr_bool: expr_bool "or" expr_bool
#line 721 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 2967 "frontend/parser.cpp"
    break;

  case 382: // expr_bool: expr_bool "and" expr_bool
#line 722 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 2973 "frontend/parser.cpp"
    break;

  case 383: // expr_bool: expr_bool "==" expr_bool
#line 724 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 2979 "frontend/parser.cpp"
    break;

  case 384: // expr_bool: expr_int "==" expr_int
#line 725 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 2985 "frontend/parser.cpp"
    break;

  case 385: // expr_bool: expr_int "==" expr_float
#line 726 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 2991 "frontend/parser.cpp"
    break;

  case 386: // expr_bool: expr_float "==" expr_float
#line 727 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 2997 "frontend/parser.cpp"
    break;

  case 387: // expr_bool: expr_float "==" expr_int
#line 728 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 3003 "frontend/parser.cpp"
    break;

  case 388: // expr_bool: expr_str "==" expr_str
#line 729 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 3009 "frontend/parser.cpp"
    break;

  case 389: // expr_bool: expr_none "==" expr_none
#line 730 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 3015 "frontend/parser.cpp"
    break;

  case 390: // expr_bool: expr_bool "!=" expr_bool
#line 732 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 3021 "frontend/parser.cpp"
    break;

  case 391: // expr_bool: expr_int "!=" expr_int
#line 733 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 3027 "frontend/parser.cpp"
    break;

  case 392: // expr_bool: expr_int "!=" expr_float
#line 734 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 3033 "frontend/parser.cpp"
    break;

  case 393: // expr_bool: expr_float "!=" expr_float
#line 735 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 3039 "frontend/parser.cpp"
    break;

  case 394: // expr_bool: expr_float "!=" expr_int
#line 736 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 3045 "frontend/parser.cpp"
    break;

  case 395: // expr_bool: expr_str "!=" expr_str
#line 737 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 3051 "frontend/parser.cpp"
    break;

  case 396: // expr_bool: expr_none "!=" expr_none
#line 738 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 3057 "frontend/parser.cpp"
    break;

  case 397: // expr_bool: expr_int ">" expr_int
#line 740 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 3063 "frontend/parser.cpp"
    break;

  case 398: // expr_bool: expr_int ">" expr_float
#line 741 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 3069 "frontend/parser.cpp"
    break;

  case 399: // expr_bool: expr_float ">" expr_float
#line 742 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 3075 "frontend/parser.cpp"
    break;

  case 400: // expr_bool: expr_float ">" expr_int
#line 743 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 3081 "frontend/parser.cpp"
    break;

  case 401: // expr_bool: expr_str ">" expr_str
#line 744 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 3087 "frontend/parser.cpp"
    break;

  case 402: // expr_bool: expr_int "<" expr_int
#line 746 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 3093 "frontend/parser.cpp"
    break;

  case 403: // expr_bool: expr_int "<" expr_float
#line 747 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 3099 "frontend/parser.cpp"
    break;

  case 404: // expr_bool: expr_float "<" expr_float
#line 748 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 3105 "frontend/parser.cpp"
    break;

  case 405: // expr_bool: expr_float "<" expr_int
#line 749 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 3111 "frontend/parser.cpp"
    break;

  case 406: // expr_bool: expr_str "<" expr_str
#line 750 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 3117 "frontend/parser.cpp"
    break;

  case 407: // expr_bool: expr_int ">=" expr_int
#line 752 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 3123 "frontend/parser.cpp"
    break;

  case 408: // expr_bool: expr_int ">=" expr_float
#line 753 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 3129 "frontend/parser.cpp"
    break;

  case 409: // expr_bool: expr_float ">=" expr_float
#line 754 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 3135 "frontend/parser.cpp"
    break;

  case 410: // expr_bool: expr_float ">=" expr_int
#line 755 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 3141 "frontend/parser.cpp"
    break;

  case 411: // expr_bool: expr_str ">=" expr_str
#line 756 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 3147 "frontend/parser.cpp"
    break;

  case 412: // expr_bool: expr_int "<=" expr_int
#line 758 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 3153 "frontend/parser.cpp"
    break;

  case 413: // expr_bool: expr_int "<=" expr_float
#line 759 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 3159 "frontend/parser.cpp"
    break;

  case 414: // expr_bool: expr_float "<=" expr_float
#line 760 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 3165 "frontend/parser.cpp"
    break;

  case 415: // expr_bool: expr_float "<=" expr_int
#line 761 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 3171 "frontend/parser.cpp"
    break;

  case 416: // expr_bool: expr_str "<=" expr_str
#line 762 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 3177 "frontend/parser.cpp"
    break;

  case 417: // expr_bool: expr_str "in" expr_str
#line 764 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[0].value.as < std::string > ().find(yystack_[2].value.as < std::string > ()) != std::string::npos; }
#line 3183 "frontend/parser.cpp"
    break;

  case 422: // mattype: "identifier" matsq
#line 776 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3189 "frontend/parser.cpp"
    break;

  case 423: // mattype: "'int'" matsq
#line 777 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(INT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3195 "frontend/parser.cpp"
    break;

  case 424: // mattype: "'float'" matsq
#line 778 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(FLOAT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3201 "frontend/parser.cpp"
    break;

  case 425: // mattype: "'string'" matsq
#line 779 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(STRING_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3207 "frontend/parser.cpp"
    break;

  case 426: // mattype: "'bool'" matsq
#line 780 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(BOOL_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3213 "frontend/parser.cpp"
    break;

  case 434: // matsq: "[" "]"
#line 789 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(scanner->parseInt(-1)); }
#line 3219 "frontend/parser.cpp"
    break;

  case 435: // matsq: "[" int_val "]"
#line 790 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 3225 "frontend/parser.cpp"
    break;

  case 436: // matsq: "[" "]" matsq
#line 791 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), scanner->parseInt(-1)); }
#line 3231 "frontend/parser.cpp"
    break;

  case 437: // matsq: "[" int_val "]" matsq
#line 792 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[2].value.as < ptc::ir::Expr * > ()); }
#line 3237 "frontend/parser.cpp"
    break;

  case 444: // type: mattype "?"
#line 802 "frontend/parser.yy"
       { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 3243 "frontend/parser.cpp"
    break;

  case 445: // type: "'int'"
#line 803 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, true); }
#line 3249 "frontend/parser.cpp"
    break;

  case 446: // type: "'float'"
#line 804 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, true); }
#line 3255 "frontend/parser.cpp"
    break;

  case 447: // type: "'string'"
#line 805 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, true); }
#line 3261 "frontend/parser.cpp"
    break;

  case 448: // type: "'bool'"
#line 806 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, true); }
#line 3267 "frontend/parser.cpp"
    break;

  case 449: // type: "identifier"
#line 807 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[0].value.as < std::string > (), true); }
#line 3273 "frontend/parser.cpp"
    break;

  case 451: // type: mattype
#line 809 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 3279 "frontend/parser.cpp"
    break;


#line 3283 "frontend/parser.cpp"

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

  const short  Parser ::yytable_ninf_ = -450;

  const short
   Parser ::yypact_[] =
  {
    1823,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  1621,    40,
      50,   621,   431,   -38,   -21,  -761,    48,  -761,  -761,  1654,
    -761,  -761,    45,    19,    27,    56,    65,    64,   164,   369,
     230,   242,   607,  -761,  -761,   193,   193,  -761,  -761,  -761,
     253,  -761,  2007,  -761,   259,  -761,  -761,   193,   193,   193,
    1688,  2493,  -761,   779,  -761,   496,   614,  2874,  2990,  1058,
     353,    69,   220,    -6,   255,   145,  1839,   282,   779,   310,
     205,   496,   614,  2823,   565,   623,   465,  1654,  -761,   145,
    -761,   194,   437,   437,  -761,  -761,  -761,  -761,  1141,   256,
    2912,  2238,  1104,  -761,   431,   431,  -761,   284,   291,  -761,
     776,  -761,   305,  1216,   358,  -761,   358,  -761,   358,  -761,
     358,  -761,   107,  -761,   372,   421,   103,  1654,   358,  -761,
    -761,  -761,   332,  1654,  -761,  -761,  -761,  2641,  -761,  -761,
    -761,  -761,  -761,  1654,   371,  2103,  -761,  -761,   339,  1654,
    -761,  -761,  -761,  1654,  1654,  1654,  1654,  1654,  1654,  1654,
    1654,  1654,  1654,  1654,  1654,  1654,  -761,   714,   332,  1654,
    1654,  1654,  1654,  1654,  1654,  1654,  1654,  1654,  1654,  1654,
    1654,  1654,  1654,  1654,  1654,  1654,  1654,  1654,  1654,  1654,
    1654,  -761,   332,  1654,  1654,  1654,  1654,  1654,  1654,  -761,
    1654,  1654,  1654,  1654,  1654,  1654,  1654,  1654,  1654,  1654,
    1654,  1654,  1654,   437,  1654,  1654,  1654,  1654,  1654,  1654,
    1654,  1654,  1654,  1654,  1654,  1654,  1654,  1654,  1654,  1654,
    1654,  1654,  1654,  1654,  1654,  1654,  1654,  1654,  1654,  1654,
    1654,  1654,  1654,  1654,  1654,  1654,  1654,  1654,  1654,  1654,
    1654,  1654,  1654,  1654,  1654,  1654,   358,  -761,  -761,    99,
      -5,   408,  -761,   332,   414,  -761,  -761,  -761,  1654,  1654,
    -761,  -761,  -761,  -761,   221,   432,  -761,    97,  2073,  1409,
     437,   437,   437,   437,   437,   431,   431,   431,   431,   431,
     437,   437,   437,   437,   437,   437,  2851,  1422,   738,   509,
     621,   183,   183,   621,   437,   437,   437,   437,   437,   437,
     621,   437,   437,   437,   437,   437,   437,   621,   621,   621,
     621,   621,   621,   621,   621,   621,   621,   621,   621,   621,
    2220,  -761,   431,   431,   431,   431,   431,  1654,   -21,    51,
     411,   418,    -4,  1654,   358,  2493,   449,  2874,  2990,  1058,
     353,  -761,  -761,  -761,  -761,   436,     4,   112,   498,   100,
    -761,   390,   471,   361,  2874,  -761,   198,   361,  -761,   458,
    2641,  -761,  1898,   480,   481,  -761,  1886,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
      21,  -761,   225,   239,   178,   602,   747,   239,   178,   602,
     747,   240,   490,   488,   492,   240,   488,   492,   240,   488,
     492,   240,   492,  2657,   297,   378,  2941,  3013,   513,   775,
    2173,   467,  2708,     1,  2737,   331,  2795,  2378,  1750,  1682,
    2766,  2105,   454,  1449,   454,  1449,   917,   576,  -761,  -761,
    1328,   925,   420,  -761,   917,   576,  -761,  -761,  1328,   925,
     420,  -761,   809,  1535,  1738,   502,   809,  1535,  1738,   502,
     809,  1535,  1738,   502,   809,  1535,  1738,   502,   361,   234,
     239,   178,   239,   178,   240,   490,  2737,   700,   917,   576,
     917,   576,  2657,   297,   378,  2941,  3013,   513,   775,  2737,
     700,   917,  -761,   917,  -761,  2657,   297,   378,  2941,  3013,
     513,   775,  2737,   700,   917,  -761,   917,  -761,   239,   602,
     747,   239,   602,   747,   240,   488,   492,   240,   488,   492,
     240,   488,   492,  1163,   500,  2657,   297,   378,  2941,  3013,
     513,   775,  2737,   700,  2795,  2378,  1750,  1682,  2766,  2105,
     454,  1449,   454,  1449,   917,  1328,   925,   917,  1328,   925,
     809,  1535,  1738,   809,  1535,  1738,   809,  1535,  1738,   809,
    1535,  1738,   239,   602,   747,   239,   602,   747,   240,   488,
     492,   240,   488,   492,   240,   488,   492,   240,   488,   492,
    2657,   297,   378,  2941,  3013,   513,   775,  2737,   700,   917,
    1328,   925,   917,  1328,   925,   809,  1535,  1738,   809,  1535,
    1738,   809,  1535,  1738,   809,  1535,  1738,   511,  2657,   297,
     378,  2941,  3013,   513,   775,  2737,   700,   331,   917,   420,
     917,   420,   809,   502,   809,   502,   809,   502,   809,   502,
    2657,   297,   378,  2941,  3013,   513,   775,  2173,   467,  2708,
       1,  2737,   700,   917,  -761,   917,  -761,  -761,  -761,    70,
     523,    18,   999,   281,   312,  -761,   525,   505,   524,  -761,
    -761,  1654,  -761,   879,   957,   879,   957,   488,   500,   488,
     500,   488,   500,  1430,  1032,   968,   674,   674,   879,   957,
     879,   957,   488,   500,   488,   500,   488,   500,   488,   500,
     302,  2967,  1455,  1238,   493,   532,  -761,  -761,   302,  2967,
    1455,  1238,   493,  1779,  1825,  1779,  1825,  1779,  1825,  1779,
    1825,  1779,  1825,  1779,  1825,   302,  2967,  1455,  1238,   493,
    1779,  1825,  1779,  1825,  1779,  1825,  1779,  1825,  1779,  1825,
    1779,  1825,   302,  2967,  1455,  1238,   493,  1992,   664,   955,
     955,  -761,  -761,  -761,  -761,   302,  2967,  1455,  1238,   493,
     326,     7,  -761,  -761,   551,   551,  -761,  -761,  -761,  -761,
    -761,  1654,  1654,  1654,  -761,  -761,  -761,   358,    60,    60,
    -761,   491,   552,   573,    11,   251,    25,   538,    13,  -761,
    1376,   313,    17,   898,   546,  -761,  -761,  2007,  1977,   593,
    1654,  2007,  -761,  1654,  -761,  -761,  -761,  -761,  1143,  -761,
    -761,   251,    31,  -761,  -761,  1654,  -761,  -761,   255,   595,
     599,   628,  -761,   589,  -761,   575,  -761,    60,   582,  -761,
     251,  1143,  1143,   598,  -761,   631,  -761,  1406,  -761,  1506,
     316,  1654,  -761,   646,  -761,   642,   594,  -761,  -761,  -761,
     251,   644,  2007,  2007,  2007,  -761,  1654,  -761,  1654,  -761,
      15,   538,    16,  1654,  -761,  -761,   649,  -761,   650,  -761,
    1532,   626,  -761,  -761,  -761,  -761,  2007,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,   598,  -761,  -761,
    -761,  -761,   662,   656,  -761,  -761,  -761
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     9,   316,   330,   351,   378,   308,     0,     0,
       0,     0,     0,     0,     0,    50,     0,    44,    46,    38,
      35,    36,     0,   445,   446,   447,   448,     0,     0,   101,
     102,     0,     0,     4,    10,     0,     0,    37,    15,    17,
       0,    18,     0,    16,     0,    19,    20,     0,     0,     0,
       0,    94,   288,    93,   289,    95,    96,    97,    98,    99,
     100,   450,   451,     0,   308,   101,   295,   288,     0,   289,
       0,     0,     0,   294,     0,     0,     0,     0,   280,   101,
     285,     0,     0,     0,   103,   104,   317,   331,     0,     0,
       0,     0,     0,   380,     0,     0,   319,     0,    33,    32,
       0,    39,     0,     0,   438,   423,   439,   424,   440,   425,
     441,   426,     0,    66,     0,     0,     0,     0,   442,   114,
     310,   422,     0,     0,   115,     1,     3,     0,     5,     8,
       7,    14,    21,     0,     0,     0,    30,    31,     0,     0,
      12,    13,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   116,     0,     0,     0,     0,     0,     0,     0,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   443,   427,   444,     0,
      72,     0,   309,     0,   310,   105,   290,   291,     0,     0,
     318,   332,   352,   379,     0,     0,   281,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   317,     0,     0,     0,     0,     0,     0,     0,   449,
       0,     0,     0,     0,   434,   295,     0,   294,     0,     0,
       0,   429,   430,   431,   432,     0,     0,     0,     0,     0,
     312,     0,     0,   117,     0,   428,     0,   118,     6,     0,
       0,    23,     0,     0,     0,    90,    89,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,   106,
       0,    91,     0,   148,   146,   143,   144,   156,   154,   151,
     152,   130,   129,   125,   126,   135,   133,   134,   140,   138,
     139,   122,   121,   279,   277,   278,   273,   274,   275,   276,
     252,   251,   255,   254,   249,   248,   227,   226,   233,   232,
     230,   229,   159,   158,   162,   161,   207,   205,   202,   203,
     198,   199,   200,   201,   224,   222,   219,   220,   215,   216,
     217,   218,   169,   166,   167,   168,   183,   180,   181,   182,
     176,   173,   174,   175,   190,   187,   188,   189,   119,     0,
     147,   145,   155,   153,   128,   127,   247,   240,   206,   204,
     223,   221,   271,   377,   260,   374,   375,   373,   376,   245,
     238,   195,   389,   212,   396,   272,   265,   266,   261,   262,
     263,   264,   246,   239,   197,   196,   214,   213,   141,   324,
     350,   149,   323,   347,   123,   320,   338,   131,   321,   341,
     136,   322,   344,     0,   335,   267,   362,   256,   359,   360,
     358,   361,   241,   234,   225,   327,   231,   329,   228,   328,
     157,   325,   160,   326,   191,   384,   385,   208,   391,   392,
     163,   397,   398,   177,   402,   403,   170,   407,   408,   184,
     412,   413,   142,   349,   348,   150,   346,   345,   124,   337,
     336,   132,   340,   339,   137,   343,   342,   120,   334,   333,
     268,   367,   257,   364,   365,   363,   366,   242,   235,   192,
     387,   386,   209,   394,   393,   164,   400,   399,   178,   405,
     404,   171,   410,   409,   185,   415,   414,     0,   269,   357,
     258,   354,   355,   353,   356,   243,   236,   417,   193,   388,
     210,   395,   165,   401,   179,   406,   172,   411,   186,   416,
     270,   372,   259,   369,   370,   368,   371,   250,   382,   253,
     381,   244,   237,   194,   383,   211,   390,   433,   419,   449,
       0,   420,     0,     0,     0,   311,     0,     0,     0,   282,
     283,     0,   286,   324,   350,   323,   347,   320,   338,   321,
     341,   322,   344,   327,   329,   328,   325,   326,   349,   348,
     346,   345,   337,   336,   340,   339,   343,   342,   334,   333,
     377,   374,   375,   373,   376,     0,   389,   396,   362,   359,
     360,   358,   361,   384,   385,   391,   392,   397,   398,   402,
     403,   407,   408,   412,   413,   367,   364,   365,   363,   366,
     387,   386,   394,   393,   400,   399,   405,   404,   410,   409,
     415,   414,   357,   354,   355,   353,   356,   417,     0,   388,
     395,   401,   406,   411,   416,   372,   369,   370,   368,   371,
     382,   381,   383,   390,   324,   323,   320,   321,   322,    76,
      34,     0,     0,     0,    72,    75,   436,   435,     0,    55,
      52,     0,     0,     0,     0,     0,     0,    68,     0,   296,
       0,     0,   110,     0,     0,   313,   111,     0,     0,    24,
       0,     0,   107,     0,   112,   109,   108,   418,     0,    74,
      73,     0,     0,   110,   292,     0,   284,   287,     0,     0,
       0,     0,   437,     0,    56,     0,    53,    57,    59,    64,
       0,     0,     0,    67,   300,     0,   298,     0,   297,     0,
       0,     0,    43,    25,    26,     0,    49,    92,   421,    62,
       0,     0,     0,     0,     0,    54,     0,    58,     0,    65,
       0,    71,     0,     0,   303,   302,     0,   301,     0,   299,
       0,   314,    27,    45,    51,    47,     0,    63,   293,    28,
      29,    41,    42,    40,    61,    60,    69,     0,    70,   306,
     305,   304,     0,     0,    48,   307,   315
  };

  const short
   Parser ::yypgoto_[] =
  {
    -761,  -761,  -129,   366,   -16,   -41,  -625,  -429,  -760,  -761,
     355,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -571,  -761,  -761,   651,    84,   -99,   629,
    -761,   585,  -761,   555,  2384,   723,   665,  1166,   731,   336,
    1186,   969,  1444,   -63,  -132,  2146,     0,   244,   726,  -761,
     -44,  -761,   -11,    -2
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    31,    32,   131,    33,    34,   137,   861,   138,    35,
      99,    36,    37,    38,    39,    40,    41,    42,    43,   855,
      44,   856,    45,   762,   763,    46,   114,   766,   767,    47,
      48,    49,   380,    50,    51,    52,    81,    68,    54,    70,
     181,    71,    72,   120,   352,    57,   338,   339,   340,    61,
     640,    62,   121,    63
  };

  const short
   Parser ::yytable_[] =
  {
      58,   136,   254,   249,   -66,   249,   362,   759,    74,    58,
      87,    91,   105,   107,   109,   111,   128,   822,   760,    58,
     249,   826,   249,   241,   249,   249,   243,   249,   103,   316,
     103,   782,    58,   244,   245,   810,    97,   642,   103,   318,
     319,   830,    58,    77,     3,     4,     5,     6,     7,     8,
     247,     9,    78,    98,     3,     4,    10,   100,   788,    82,
     761,   783,   103,   759,    11,   811,    83,   103,   250,    12,
     754,   811,    23,    24,    25,    26,   103,    58,   639,    12,
     103,   103,   269,    87,  -435,   808,   104,   813,   287,   866,
     867,  -435,   751,   341,   106,   342,   874,   343,   332,   344,
     651,     3,     4,     5,     6,     7,     8,   355,     9,   638,
     345,   358,   772,    10,    79,    30,   761,   350,   118,   102,
     346,    11,   765,   108,    84,    85,    12,    58,    23,    24,
      25,    26,   110,    58,   639,    58,   246,   118,   112,    58,
     809,   773,   351,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,   253,    58,   116,   386,
     390,   394,   397,   400,   402,   407,   829,    23,    24,    25,
      26,    79,    30,   639,   431,   439,   444,   448,   452,   456,
      23,    24,    25,    26,   117,   839,   639,   803,   804,   182,
     476,     7,   685,   129,   489,   185,   130,   265,   500,   503,
     506,   509,   512,   514,   519,   857,   266,   860,   860,   860,
     776,   536,   539,   542,   545,   548,   551,   554,   557,   560,
     563,   566,   569,   574,   648,   581,   584,   587,   590,   593,
     596,   778,   602,   649,   267,   637,   837,   784,   113,   773,
     624,   122,   125,   258,    59,   259,   785,   641,   157,   157,
     158,   158,    75,    59,   134,    92,   161,   162,   163,   164,
     164,   267,   133,    59,   135,   252,   773,    58,   139,   123,
     654,   656,   658,   660,   662,   773,    59,   290,   180,   180,
     669,   671,   673,   675,   677,   679,    59,   248,   291,   292,
     682,   791,   256,   690,   694,   696,   698,   700,   702,   704,
     707,   711,   713,   715,   717,   719,   721,   724,    91,    91,
      91,    91,    91,    91,    91,   737,    91,    91,    91,    91,
     257,    59,   191,   756,   793,   816,   327,    58,   849,   192,
     193,   328,   288,    58,   291,   292,     3,     4,     5,     6,
       7,     8,   231,     9,   764,   768,   128,   333,    10,    23,
      24,    25,    26,   773,   817,   639,    11,   850,   318,   319,
      58,    12,    58,   234,   235,   236,   237,   238,   239,   103,
     157,    59,   158,   348,   240,   241,   242,    59,   243,    59,
     115,   347,   116,    59,   360,   244,   245,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
     363,    59,   132,   195,   862,   863,    79,    30,   117,   408,
     196,   197,   415,   140,   141,   142,   156,   643,   432,   440,
     445,   449,   453,   457,   645,     3,     4,     5,     6,     7,
       8,   231,     9,   334,   477,     3,   118,    10,   490,   336,
      94,     3,     4,  -449,   650,    11,    82,    95,   520,   758,
      12,   349,   752,    83,   236,   237,   238,   239,   356,   753,
      12,   757,   348,   157,   774,   158,    12,   575,   777,   159,
     160,   161,   162,   163,   164,   263,   603,   607,   609,   611,
     613,   615,   617,   619,   625,   775,   240,   241,   242,   780,
     243,   781,   243,   180,   382,    79,    30,   244,   245,   244,
     245,   182,     3,     4,     5,     6,     7,     8,   203,     9,
     769,    59,   222,   231,    10,   316,   317,   190,   459,   263,
     285,   191,    11,   786,   231,   318,   319,    12,   192,   193,
     315,   316,   317,   787,   683,   794,   796,   691,   233,   770,
     798,   318,   319,   795,   708,   234,   235,   236,   237,   238,
     239,   725,   727,   729,   730,   731,   732,   733,   734,   738,
      92,    92,    92,    92,    80,   805,   806,   597,   324,   325,
     326,    59,    79,    30,   101,   261,   807,    59,   812,   790,
     217,   218,   219,   220,   221,   222,   223,   182,   821,   644,
     224,   183,   184,   185,   646,   647,   824,   225,   226,   227,
     228,   229,   230,   835,    59,   832,    59,   126,   127,   833,
       2,     3,     4,     5,     6,     7,     8,   836,     9,   200,
     201,   202,   203,    10,   838,     3,     4,     5,     6,     7,
      88,    11,    80,   262,   231,   194,    12,    83,   834,   195,
     843,   768,    58,   844,   232,    11,   196,   197,   233,   852,
      12,    58,   853,   854,   858,   234,   235,   236,   237,   238,
     239,   869,   870,    13,    14,    15,   873,    16,    17,    18,
      19,    20,    21,    22,   875,    23,    24,    25,    26,    27,
      28,    29,    30,   750,   771,   315,   316,   317,   359,   322,
     323,   324,   325,   326,   364,   351,   318,   319,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   182,   381,   841,   251,   183,   184,   185,     3,     4,
       5,     6,     7,     8,   379,     9,    60,   792,   365,   331,
      10,    67,   187,   188,    76,    60,   136,    93,    11,    69,
     136,   876,   264,    12,   828,    60,   802,     0,   262,     0,
       0,    58,    58,    58,     0,     0,   764,   764,    60,   307,
       0,   802,   128,   308,   219,   220,   221,   222,    60,     0,
     309,   310,   311,   312,   313,   314,     0,    58,    58,     0,
      58,    58,     0,    58,     0,     0,   641,     0,    79,    30,
     182,   859,   859,   859,   183,   184,   185,   241,   242,     0,
     243,     0,     0,    60,   186,   764,     0,   244,   245,   840,
     842,   187,   188,     0,   289,   136,     0,     0,   157,     0,
     158,    58,   652,     0,   159,   160,   161,   162,   163,   164,
       0,     0,    58,    58,    58,     0,    58,     0,    58,   172,
     173,     0,     0,    58,    23,    24,    25,    26,   180,     0,
     329,   330,     0,    60,     0,     0,    58,     0,     0,    60,
       0,    60,     0,     0,     0,    60,     0,     0,     0,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,   749,    60,     0,     0,    59,     0,   755,     0,
       0,   409,   411,   413,     0,    59,   272,   273,   274,   203,
     433,   441,     3,     4,     5,     6,     7,     8,     0,     9,
     818,     0,     0,     0,    10,     0,   478,     0,     0,     0,
     491,     0,    11,     0,     0,     0,   157,    12,   158,     0,
     521,     0,   159,   160,   161,   162,   163,   164,     0,   819,
     217,   218,   219,   220,   221,   222,     0,   172,   173,   576,
       0,   176,   177,   178,   179,     0,   180,     0,   604,   227,
     228,   229,   230,     0,     0,     0,   626,   628,   630,    55,
     634,   636,    79,    30,   282,   283,   284,   285,    55,     0,
      89,     0,     0,   322,   323,   324,   325,   326,    55,   311,
     312,   313,   314,    60,   275,    59,    59,    59,   278,   279,
       0,    55,     0,     3,     4,     5,     6,     7,     8,     0,
       9,    55,   116,     0,     0,    10,   684,     0,     0,   692,
       0,    59,    59,    11,    59,    59,   709,    59,    12,     0,
       0,     0,     0,   726,   728,   728,   728,   728,   728,   728,
     728,   739,   740,   741,   742,   743,    55,   322,   323,   324,
     325,   326,     0,    60,     0,     0,     0,    89,   275,    60,
     277,     0,   278,   279,     0,    59,     0,     0,     0,   231,
       0,     0,     0,    79,    30,     0,    59,    59,    59,   232,
      59,     0,    59,   233,     0,     0,    60,    59,    60,     0,
     234,   235,   236,   237,   238,   239,    55,     0,     0,     0,
      59,     0,    55,     0,    55,     0,   815,     0,    55,   820,
       0,     0,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,   307,    55,     0,     0,   308,
       0,   831,     0,     0,   404,     0,   309,   310,   311,   312,
     313,   314,     0,   428,   436,     3,     4,     5,     6,    64,
      88,     0,     0,   846,     0,   848,     0,    83,     0,   473,
       0,   482,   484,   486,     0,    11,    53,     0,     0,     0,
      12,     0,     0,   516,     0,    53,     0,     0,   270,   271,
     272,   273,   274,   203,     0,    53,   872,     0,     0,   275,
     276,   277,   571,   278,   279,     0,     0,   789,    53,     0,
       0,   599,     0,     0,     0,     0,   797,     0,    53,   621,
       0,    23,    24,    25,    26,   119,   124,   639,     0,     0,
       3,     4,     5,     6,     7,     8,     0,     9,   334,     0,
       0,     0,    10,     0,     0,     0,    55,     0,     0,   189,
      11,     0,     0,    53,     0,    12,     0,     0,     0,     0,
       0,   119,     0,     0,   189,     0,     0,     0,     0,   680,
     686,   687,   688,   308,     0,   119,     0,     0,     0,   705,
     309,   310,   311,   312,   313,   314,   722,    89,    89,    89,
      89,    89,    89,    89,   735,    89,    89,    89,    89,     0,
      79,    30,     0,    53,     0,     0,    55,     0,     0,    53,
       0,    53,    55,     0,     0,    53,   799,   800,   801,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,     0,    53,     0,   384,   388,   392,     0,    55,
       0,    55,     0,     0,     0,   825,     0,     0,   827,     0,
     427,   435,     0,   198,   199,   200,   201,   202,   203,   461,
     463,   465,   467,   469,   471,     0,     0,   480,   209,   210,
       0,   493,   213,   214,   215,   216,     0,     0,    60,     0,
       0,   523,     0,     0,     0,     0,   851,    60,     0,     0,
       3,     4,     5,     6,     7,     8,     0,     9,   814,     0,
     578,   864,    10,   865,     0,     0,     0,     0,   868,   606,
      11,     0,     0,     0,     0,    12,     0,     0,     0,   632,
       3,     4,     5,     6,     7,     8,     0,     9,   845,   261,
       0,     0,    10,     0,   280,   281,   282,   283,   284,   285,
      11,     0,   261,    53,     0,    12,     0,   280,   281,   282,
     283,   284,   285,   300,    56,   322,   323,   324,   325,   326,
      79,    30,     0,    56,   301,   302,   303,   304,   305,   306,
     278,   279,     0,    56,   198,   199,   200,   201,   202,   203,
     280,   281,   282,   283,   284,   285,    56,    60,    60,    60,
      79,    30,     0,     0,     0,     0,    56,   301,   302,   303,
     304,   305,   306,    53,     0,     0,     0,     0,     0,    53,
       0,     0,     0,    60,    60,     0,    60,    60,     0,    60,
       3,     4,     5,     6,     7,     8,     0,     9,   847,     0,
       0,    56,    10,     0,     0,     0,    53,     0,    53,     0,
      11,     0,     0,     0,     0,    12,     3,     4,     5,     6,
       7,     8,     0,     9,   871,     0,     0,    60,    10,     0,
     198,   199,   200,   201,   202,   203,    11,     0,    60,    60,
      60,    12,    60,     0,    60,   209,   210,     0,     0,    60,
     189,    56,     0,     0,   189,     0,     0,    56,   189,    56,
      79,    30,    60,    56,     0,     0,     0,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
       0,    56,     0,     0,     0,     0,    79,    30,     0,   405,
       0,    55,     0,   189,     0,     0,     0,     0,   429,   437,
      55,   189,     0,     0,     0,     3,     4,     5,     6,    64,
       8,     0,     9,     0,   474,     0,     0,    10,   487,     0,
     495,   497,     0,     0,     0,    11,     0,   189,   517,   189,
      12,   189,     0,   189,     0,   189,     0,   189,     3,     4,
       5,     6,     7,     8,     0,     9,   189,   572,     0,     0,
      10,     0,     0,     0,     0,     0,   600,     0,    11,   189,
       0,     0,     0,    12,   622,     0,     0,     0,   129,     0,
       0,   130,     0,     0,     0,    65,    30,   198,   199,   200,
     201,   202,   203,     0,     0,     0,     0,     0,   206,   189,
     208,    56,   209,   210,   211,   212,   213,   214,   215,   216,
      55,    55,    55,     0,     0,     0,     0,     0,    79,    30,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,     0,   154,   155,     0,     0,    55,    55,     0,    55,
      55,     0,    55,   217,   218,   219,   220,   221,   222,   157,
       0,   158,     0,     0,   189,   159,   160,   161,   162,   163,
     164,    56,     0,     0,     0,     0,   169,    56,   171,     0,
     172,   173,   174,   175,   176,   177,   178,   179,     0,   180,
      55,     0,   189,     0,   270,   271,   272,   273,   274,   203,
       0,    55,    55,    55,    56,    55,    56,    55,    53,   278,
     279,     0,    55,     0,     0,     0,     0,    53,   189,     0,
       0,     0,     0,     1,     0,    55,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,     0,    10,
     280,   281,   282,   283,   284,   285,     0,    11,   157,   255,
     158,     0,    12,     0,   159,   160,   161,   162,   163,   164,
     165,   166,   167,     0,   168,   169,   170,   171,     0,   172,
     173,   174,   175,   176,   177,   178,   179,     0,   180,    13,
      14,    15,     0,    16,    17,    18,    19,    20,    21,    22,
       0,    23,    24,    25,    26,    27,    28,    29,    30,   127,
       0,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,   779,     0,    10,     0,     0,    53,    53,    53,
       0,     0,    11,     0,     0,     0,     0,    12,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,     0,
     154,   155,     0,    53,    53,     0,    53,    53,     0,    53,
       0,     0,     0,     0,    13,    14,    15,     0,    16,    17,
      18,    19,    20,    21,    22,     0,    23,    24,    25,    26,
      27,    28,    29,    30,     0,     0,     0,     0,   127,     0,
       2,     3,     4,     5,     6,     7,     8,    53,     9,     0,
       0,   823,     0,    10,     0,     0,     0,     0,    53,    53,
      53,    11,    53,     0,    53,     0,    12,     0,     0,    53,
     134,     3,     4,     5,     6,     7,     8,     0,     9,     0,
     135,     0,    53,    10,   309,   310,   311,   312,   313,   314,
       0,    11,     0,    13,    14,    15,    12,    16,    17,    18,
      19,    20,    21,    22,     0,    23,    24,    25,    26,    27,
      28,    29,    30,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    14,    15,     0,    16,    17,    18,
      19,    20,    21,    22,     0,    23,    24,    25,    26,    27,
      28,    29,    30,   260,     0,     0,    56,     0,   270,   271,
     272,   273,   274,   203,     0,    56,     0,     0,     0,   275,
     276,   277,     0,   278,   279,     0,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,   361,     0,    10,
     198,   199,   200,   201,   202,   203,     0,    11,     0,     0,
       0,   206,    12,     0,     0,   209,   210,   211,   212,   213,
     214,   215,   216,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    73,     0,    86,    90,    96,    13,
      14,    15,     0,    16,    17,    18,    19,    20,    21,    22,
       0,    23,    24,    25,    26,    27,    28,    29,    30,     0,
       0,     0,   157,     0,   158,     0,     0,     0,   159,   160,
     161,   162,   163,   164,     0,    56,    56,    56,   168,   169,
     170,   171,     0,   172,   173,   174,   175,   176,   177,   178,
     179,     0,   180,     0,     0,     0,     0,     0,     0,     0,
       0,    56,    56,     0,    56,    56,     0,    56,   268,    86,
     260,     0,     0,     0,   286,   322,   323,   324,   325,   326,
     320,   321,     0,     0,     0,     0,   275,   276,   277,   337,
     278,   279,     0,   280,   281,   282,   283,   284,   285,   300,
       0,   337,     0,   354,     0,    56,     0,     0,   337,   354,
     301,   302,   303,   304,   305,   306,    56,    56,    56,     0,
      56,     0,    56,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,     0,     0,     0,   337,   385,   389,   393,   396,   399,
     354,   406,   354,   354,   354,   417,   419,   421,   423,   425,
     430,   438,   443,   447,   451,   455,   354,     0,   337,   354,
     354,   354,   354,   354,   354,     0,   475,   354,   354,   354,
     488,   354,   354,   354,   499,   502,   505,   508,   511,   513,
     518,   354,   525,   527,   529,   531,   533,   535,   538,   541,
     544,   547,   550,   553,   556,   559,   562,   565,   568,   573,
     354,   580,   583,   586,   589,   592,   595,   337,   601,   354,
     354,   354,   354,   354,   354,   354,   623,   354,   354,   354,
     354,   354,    66,   198,   199,   200,   201,   202,   203,   337,
       0,     0,     0,     0,   337,   337,     0,     0,   209,   210,
     211,   212,   213,   214,   215,   216,   653,   655,   657,   659,
     661,   663,   664,   665,   666,   667,   668,   670,   672,   674,
     676,   678,     0,     0,     0,     0,   681,     0,     0,   689,
     693,   695,   697,   699,   701,   703,   706,   710,   712,   714,
     716,   718,   720,   723,    90,    90,    90,    90,    90,    90,
      90,   736,    90,    90,    90,    90,     0,     0,   744,   745,
     746,   747,   748,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   335,     0,     0,
       0,     0,     0,     0,   337,     0,     0,     0,     0,   335,
       0,   353,   157,     0,   158,     0,   335,   357,   159,   160,
     161,   162,   163,   164,   165,   166,   167,     0,   168,   169,
     170,   171,     0,   172,   173,   174,   175,   176,   177,   178,
     179,     0,   180,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   335,   383,   387,   391,   395,   398,   401,   403,
     410,   412,   414,   416,   418,   420,   422,   424,   426,   434,
     442,   446,   450,   454,   458,     0,   335,   460,   462,   464,
     466,   468,   470,     0,   472,   479,   481,   483,   485,   492,
     494,   496,   498,   501,   504,   507,   510,     0,   515,   522,
     524,   526,   528,   530,   532,   534,   537,   540,   543,   546,
     549,   552,   555,   558,   561,   564,   567,   570,   577,   579,
     582,   585,   588,   591,   594,   335,   598,   605,   608,   610,
     612,   614,   616,   618,   620,   627,   629,   631,   633,   635,
       0,     0,     0,     0,     0,     0,     0,   335,     0,     0,
       0,     0,   335,   335,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,     0,     0,    10,     0,     0,
       0,     0,     0,     0,     0,    11,   157,     0,   158,     0,
      12,     0,   159,   160,   161,   162,   163,   164,     0,   166,
     167,     0,   168,   169,   170,   171,     0,   172,   173,   174,
     175,   176,   177,   178,   179,     0,   180,    13,    14,    15,
       0,    16,    17,    18,    19,    20,    21,    22,     0,    23,
      24,    25,    26,    27,    28,    29,    30,   157,     0,   158,
       0,     0,     0,   159,   160,   161,   162,   163,   164,     0,
     166,     0,   335,   168,   169,   170,   171,     0,   172,   173,
     174,   175,   176,   177,   178,   179,   157,   180,   158,     0,
       0,     0,   159,   160,   161,   162,   163,   164,     0,     0,
       0,     0,     0,   169,   170,   171,     0,   172,   173,   174,
     175,   176,   177,   178,   179,   157,   180,   158,     0,     0,
       0,   159,   160,   161,   162,   163,   164,     0,     0,     0,
       0,     0,   169,     0,     0,     0,   172,   173,   174,   175,
     176,   177,   178,   179,   157,   180,   158,     0,     0,     0,
     159,   160,   161,   162,   163,   164,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   172,   173,   174,   175,   176,
     177,   178,   179,   260,   180,     0,     0,     0,   198,   199,
     200,   201,   202,   203,   204,     0,     0,     0,   205,   206,
     207,   208,     0,   209,   210,   211,   212,   213,   214,   215,
     216,   260,     0,     0,     0,     0,   270,   271,   272,   273,
     274,   203,   293,     0,     0,     0,     0,   275,   276,   277,
       0,   278,   279,   294,   295,   296,   297,   298,   299,   198,
     199,   200,   201,   202,   203,   204,     0,     0,     0,   205,
     206,   207,   208,     0,   209,   210,   211,   212,   213,   214,
     215,   216,     0,     0,     0,     0,   337,     0,     0,   337,
       0,     0,     0,     0,     0,     0,     0,   270,   271,   272,
     273,   274,   203,   293,     0,     0,     0,     0,   275,   276,
     277,   337,   278,   279,   294,   295,   296,   297,   298,   299,
       0,     0,     0,     0,     0,     0,   198,   199,   200,   201,
     202,   203,     0,   337,     0,   337,   205,   206,   207,   208,
       0,   209,   210,   211,   212,   213,   214,   215,   216,     0,
       0,     0,   270,   271,   272,   273,   274,   203,     0,     0,
       0,     0,     0,   275,   276,   277,   337,   278,   279,   294,
     295,   296,   297,   298,   299,   217,   218,   219,   220,   221,
     222,   223,     0,     0,     0,   224,     0,     0,     0,     0,
       0,     0,   225,   226,   227,   228,   229,   230,   217,   218,
     219,   220,   221,   222,     0,     0,     0,     0,   224,     0,
       0,     0,     0,     0,     0,   225,   226,   227,   228,   229,
     230,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   335,     0,     0,   335,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   335,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   335,     0,   335,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   335
  };

  const short
   Parser ::yycheck_[] =
  {
       0,    42,    65,     9,     9,     9,   135,     3,     8,     9,
      10,    11,    23,    24,    25,    26,    32,   777,    14,    19,
       9,   781,     9,    22,     9,     9,    25,     9,    11,    22,
      11,    10,    32,    32,    33,    10,    74,    42,    11,    32,
      33,    10,    42,     3,     4,     5,     6,     7,     8,     9,
      61,    11,    12,    74,     4,     5,    16,     9,    40,     9,
      56,    40,    11,     3,    24,    40,    16,    11,    74,    29,
      74,    40,    68,    69,    70,    71,    11,    77,    74,    29,
      11,    11,    82,    83,    67,    74,    67,    74,    88,    74,
      74,    74,    41,   104,    67,   106,   856,   108,   100,   110,
       3,     4,     5,     6,     7,     8,     9,   118,    11,    10,
       3,   127,    12,    16,    74,    75,    56,    14,    67,    74,
      13,    24,    10,    67,    74,    75,    29,   127,    68,    69,
      70,    71,    67,   133,    74,   135,    67,    67,    74,   139,
     765,    41,    39,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    11,   157,    13,   159,
     160,   161,   162,   163,   164,   165,   791,    68,    69,    70,
      71,    74,    75,    74,   174,   175,   176,   177,   178,   179,
      68,    69,    70,    71,    39,   810,    74,   758,   759,    11,
     190,     8,     9,     0,   194,    17,     3,     3,   198,   199,
     200,   201,   202,   203,   204,   830,    12,   832,   833,   834,
      12,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,     3,   225,   226,   227,   228,   229,
     230,   360,   232,    12,    40,   246,   807,    12,    74,    41,
     240,    11,     0,    38,     0,    40,    12,   249,     9,     9,
      11,    11,     8,     9,     3,    11,    17,    18,    19,    20,
      20,    40,     9,    19,    13,    10,    41,   267,     9,    39,
     270,   271,   272,   273,   274,    41,    32,    21,    39,    39,
     280,   281,   282,   283,   284,   285,    42,    67,    32,    33,
     290,    10,    10,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
      10,    77,    25,   334,    12,    12,    42,   327,    12,    32,
      33,    40,    88,   333,    32,    33,     4,     5,     6,     7,
       8,     9,    11,    11,   346,   347,   362,    42,    16,    68,
      69,    70,    71,    41,    41,    74,    24,    41,    32,    33,
     360,    29,   362,    32,    33,    34,    35,    36,    37,    11,
       9,   127,    11,    41,    21,    22,    23,   133,    25,   135,
      11,     9,    13,   139,    13,    32,    33,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
      61,   157,    36,    25,   833,   834,    74,    75,    39,   165,
      32,    33,   168,    47,    48,    49,    50,     9,   174,   175,
     176,   177,   178,   179,    10,     4,     5,     6,     7,     8,
       9,    11,    11,    12,   190,     4,    67,    16,   194,   103,
       9,     4,     5,    74,    12,    24,     9,    16,   204,    13,
      29,   115,    41,    16,    34,    35,    36,    37,   122,    41,
      29,    12,    41,     9,    74,    11,    29,   223,    10,    15,
      16,    17,    18,    19,    20,    10,   232,   233,   234,   235,
     236,   237,   238,   239,   240,    14,    21,    22,    23,     9,
      25,    10,    25,    39,   158,    74,    75,    32,    33,    32,
      33,    11,     4,     5,     6,     7,     8,     9,    20,    11,
      12,   267,    20,    11,    16,    22,    23,    21,   182,    10,
      20,    25,    24,    12,    11,    32,    33,    29,    32,    33,
      21,    22,    23,    10,   290,    10,    12,   293,    25,    41,
       8,    32,    33,    38,   300,    32,    33,    34,    35,    36,
      37,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,     9,    74,    14,   231,    17,    18,
      19,   327,    74,    75,    19,    10,     3,   333,    40,   642,
      15,    16,    17,    18,    19,    20,    21,    11,    42,   253,
      25,    15,    16,    17,   258,   259,     3,    32,    33,    34,
      35,    36,    37,    14,   360,    10,   362,     0,     1,    10,
       3,     4,     5,     6,     7,     8,     9,    42,    11,    17,
      18,    19,    20,    16,    42,     4,     5,     6,     7,     8,
       9,    24,    77,    10,    11,    21,    29,    16,    10,    25,
      42,   643,   642,    12,    21,    24,    32,    33,    25,     3,
      29,   651,    10,    59,    10,    32,    33,    34,    35,    36,
      37,    12,    12,    56,    57,    58,    40,    60,    61,    62,
      63,    64,    65,    66,    12,    68,    69,    70,    71,    72,
      73,    74,    75,   328,   348,    21,    22,    23,   133,    15,
      16,    17,    18,    19,   139,    39,    32,    33,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    11,   157,   812,    63,    15,    16,    17,     4,     5,
       6,     7,     8,     9,    10,    11,     0,   643,   143,   100,
      16,     8,    32,    33,     8,     9,   777,    11,    24,     8,
     781,   873,    77,    29,   788,    19,   757,    -1,    10,    -1,
      -1,   751,   752,   753,    -1,    -1,   758,   759,    32,    21,
      -1,   772,   778,    25,    17,    18,    19,    20,    42,    -1,
      32,    33,    34,    35,    36,    37,    -1,   777,   778,    -1,
     780,   781,    -1,   783,    -1,    -1,   788,    -1,    74,    75,
      11,   832,   833,   834,    15,    16,    17,    22,    23,    -1,
      25,    -1,    -1,    77,    25,   807,    -1,    32,    33,   811,
     812,    32,    33,    -1,    88,   856,    -1,    -1,     9,    -1,
      11,   821,   267,    -1,    15,    16,    17,    18,    19,    20,
      -1,    -1,   832,   833,   834,    -1,   836,    -1,   838,    30,
      31,    -1,    -1,   843,    68,    69,    70,    71,    39,    -1,
      74,    75,    -1,   127,    -1,    -1,   856,    -1,    -1,   133,
      -1,   135,    -1,    -1,    -1,   139,    -1,    -1,    -1,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   327,   157,    -1,    -1,   642,    -1,   333,    -1,
      -1,   165,   166,   167,    -1,   651,    17,    18,    19,    20,
     174,   175,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    -1,    -1,    16,    -1,   190,    -1,    -1,    -1,
     194,    -1,    24,    -1,    -1,    -1,     9,    29,    11,    -1,
     204,    -1,    15,    16,    17,    18,    19,    20,    -1,    41,
      15,    16,    17,    18,    19,    20,    -1,    30,    31,   223,
      -1,    34,    35,    36,    37,    -1,    39,    -1,   232,    34,
      35,    36,    37,    -1,    -1,    -1,   240,   241,   242,     0,
     244,   245,    74,    75,    17,    18,    19,    20,     9,    -1,
      11,    -1,    -1,    15,    16,    17,    18,    19,    19,    34,
      35,    36,    37,   267,    26,   751,   752,   753,    30,    31,
      -1,    32,    -1,     4,     5,     6,     7,     8,     9,    -1,
      11,    42,    13,    -1,    -1,    16,   290,    -1,    -1,   293,
      -1,   777,   778,    24,   780,   781,   300,   783,    29,    -1,
      -1,    -1,    -1,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,    77,    15,    16,    17,
      18,    19,    -1,   327,    -1,    -1,    -1,    88,    26,   333,
      28,    -1,    30,    31,    -1,   821,    -1,    -1,    -1,    11,
      -1,    -1,    -1,    74,    75,    -1,   832,   833,   834,    21,
     836,    -1,   838,    25,    -1,    -1,   360,   843,   362,    -1,
      32,    33,    34,    35,    36,    37,   127,    -1,    -1,    -1,
     856,    -1,   133,    -1,   135,    -1,   770,    -1,   139,   773,
      -1,    -1,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    21,   157,    -1,    -1,    25,
      -1,   795,    -1,    -1,   165,    -1,    32,    33,    34,    35,
      36,    37,    -1,   174,   175,     4,     5,     6,     7,     8,
       9,    -1,    -1,   817,    -1,   819,    -1,    16,    -1,   190,
      -1,   192,   193,   194,    -1,    24,     0,    -1,    -1,    -1,
      29,    -1,    -1,   204,    -1,     9,    -1,    -1,    15,    16,
      17,    18,    19,    20,    -1,    19,   850,    -1,    -1,    26,
      27,    28,   223,    30,    31,    -1,    -1,   642,    32,    -1,
      -1,   232,    -1,    -1,    -1,    -1,   651,    -1,    42,   240,
      -1,    68,    69,    70,    71,    29,    30,    74,    -1,    -1,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
      -1,    -1,    16,    -1,    -1,    -1,   267,    -1,    -1,    53,
      24,    -1,    -1,    77,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,   290,
     291,   292,   293,    25,    -1,    79,    -1,    -1,    -1,   300,
      32,    33,    34,    35,    36,    37,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,    -1,
      74,    75,    -1,   127,    -1,    -1,   327,    -1,    -1,   133,
      -1,   135,   333,    -1,    -1,   139,   751,   752,   753,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    -1,   157,    -1,   159,   160,   161,    -1,   360,
      -1,   362,    -1,    -1,    -1,   780,    -1,    -1,   783,    -1,
     174,   175,    -1,    15,    16,    17,    18,    19,    20,   183,
     184,   185,   186,   187,   188,    -1,    -1,   191,    30,    31,
      -1,   195,    34,    35,    36,    37,    -1,    -1,   642,    -1,
      -1,   205,    -1,    -1,    -1,    -1,   821,   651,    -1,    -1,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
     224,   836,    16,   838,    -1,    -1,    -1,    -1,   843,   233,
      24,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,   243,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    10,
      -1,    -1,    16,    -1,    15,    16,    17,    18,    19,    20,
      24,    -1,    10,   267,    -1,    29,    -1,    15,    16,    17,
      18,    19,    20,    21,     0,    15,    16,    17,    18,    19,
      74,    75,    -1,     9,    32,    33,    34,    35,    36,    37,
      30,    31,    -1,    19,    15,    16,    17,    18,    19,    20,
      15,    16,    17,    18,    19,    20,    32,   751,   752,   753,
      74,    75,    -1,    -1,    -1,    -1,    42,    32,    33,    34,
      35,    36,    37,   327,    -1,    -1,    -1,    -1,    -1,   333,
      -1,    -1,    -1,   777,   778,    -1,   780,   781,    -1,   783,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
      -1,    77,    16,    -1,    -1,    -1,   360,    -1,   362,    -1,
      24,    -1,    -1,    -1,    -1,    29,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,   821,    16,    -1,
      15,    16,    17,    18,    19,    20,    24,    -1,   832,   833,
     834,    29,   836,    -1,   838,    30,    31,    -1,    -1,   843,
     384,   127,    -1,    -1,   388,    -1,    -1,   133,   392,   135,
      74,    75,   856,   139,    -1,    -1,    -1,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
      -1,   157,    -1,    -1,    -1,    -1,    74,    75,    -1,   165,
      -1,   642,    -1,   427,    -1,    -1,    -1,    -1,   174,   175,
     651,   435,    -1,    -1,    -1,     4,     5,     6,     7,     8,
       9,    -1,    11,    -1,   190,    -1,    -1,    16,   194,    -1,
     196,   197,    -1,    -1,    -1,    24,    -1,   461,   204,   463,
      29,   465,    -1,   467,    -1,   469,    -1,   471,     4,     5,
       6,     7,     8,     9,    -1,    11,   480,   223,    -1,    -1,
      16,    -1,    -1,    -1,    -1,    -1,   232,    -1,    24,   493,
      -1,    -1,    -1,    29,   240,    -1,    -1,    -1,     0,    -1,
      -1,     3,    -1,    -1,    -1,    74,    75,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,   523,
      28,   267,    30,    31,    32,    33,    34,    35,    36,    37,
     751,   752,   753,    -1,    -1,    -1,    -1,    -1,    74,    75,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    54,    55,    -1,    -1,   777,   778,    -1,   780,
     781,    -1,   783,    15,    16,    17,    18,    19,    20,     9,
      -1,    11,    -1,    -1,   578,    15,    16,    17,    18,    19,
      20,   327,    -1,    -1,    -1,    -1,    26,   333,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    39,
     821,    -1,   606,    -1,    15,    16,    17,    18,    19,    20,
      -1,   832,   833,   834,   360,   836,   362,   838,   642,    30,
      31,    -1,   843,    -1,    -1,    -1,    -1,   651,   632,    -1,
      -1,    -1,    -1,     0,    -1,   856,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    -1,    -1,    -1,    16,
      15,    16,    17,    18,    19,    20,    -1,    24,     9,    10,
      11,    -1,    29,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    39,    56,
      57,    58,    -1,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      -1,    -1,    14,    -1,    16,    -1,    -1,   751,   752,   753,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      54,    55,    -1,   777,   778,    -1,   780,   781,    -1,   783,
      -1,    -1,    -1,    -1,    56,    57,    58,    -1,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,   821,    11,    -1,
      -1,    14,    -1,    16,    -1,    -1,    -1,    -1,   832,   833,
     834,    24,   836,    -1,   838,    -1,    29,    -1,    -1,   843,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
      13,    -1,   856,    16,    32,    33,    34,    35,    36,    37,
      -1,    24,    -1,    56,    57,    58,    29,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    -1,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    10,    -1,    -1,   642,    -1,    15,    16,
      17,    18,    19,    20,    -1,   651,    -1,    -1,    -1,    26,
      27,    28,    -1,    30,    31,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    -1,    14,    -1,    16,
      15,    16,    17,    18,    19,    20,    -1,    24,    -1,    -1,
      -1,    26,    29,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     8,    -1,    10,    11,    12,    56,
      57,    58,    -1,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    -1,   751,   752,   753,    25,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   777,   778,    -1,   780,   781,    -1,   783,    82,    83,
      10,    -1,    -1,    -1,    88,    15,    16,    17,    18,    19,
      94,    95,    -1,    -1,    -1,    -1,    26,    27,    28,   103,
      30,    31,    -1,    15,    16,    17,    18,    19,    20,    21,
      -1,   115,    -1,   117,    -1,   821,    -1,    -1,   122,   123,
      32,    33,    34,    35,    36,    37,   832,   833,   834,    -1,
     836,    -1,   838,    -1,    -1,    -1,    -1,   843,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     856,    -1,    -1,    -1,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,    -1,   182,   183,
     184,   185,   186,   187,   188,    -1,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,     8,    15,    16,    17,    18,    19,    20,   253,
      -1,    -1,    -1,    -1,   258,   259,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,    -1,    -1,    -1,    -1,   290,    -1,    -1,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,    -1,    -1,   322,   323,
     324,   325,   326,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,
      -1,    -1,    -1,    -1,   348,    -1,    -1,    -1,    -1,   115,
      -1,   117,     9,    -1,    11,    -1,   122,   123,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,    -1,   182,   183,   184,   185,
     186,   187,   188,    -1,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,    -1,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,    -1,    -1,
      -1,    -1,   258,   259,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    -1,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,     9,    -1,    11,    -1,
      29,    -1,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    -1,    25,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    39,    56,    57,    58,
      -1,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,     9,    -1,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    -1,
      22,    -1,   348,    25,    26,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,     9,    39,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    -1,    30,    31,    32,
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
      19,    20,    21,    -1,    -1,    -1,    -1,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    25,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,   770,    -1,    -1,   773,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    26,    27,
      28,   795,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    -1,   817,    -1,   819,    25,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,   850,    30,    31,    32,
      33,    34,    35,    36,    37,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    37,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   770,    -1,    -1,   773,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   795,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   817,    -1,   819,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   850
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
     125,   111,   114,   111,   125,   111,   125,   129,    10,    74,
     127,   130,    42,     9,   116,    10,   116,   116,     3,    12,
      12,     3,   110,   122,   123,   122,   123,   122,   123,   122,
     123,   122,   123,   122,   122,   122,   122,   122,   122,   123,
     122,   123,   122,   123,   122,   123,   122,   123,   122,   123,
     118,   122,   123,   124,   125,     9,   118,   118,   118,   122,
     123,   124,   125,   122,   123,   122,   123,   122,   123,   122,
     123,   122,   123,   122,   123,   118,   122,   123,   124,   125,
     122,   123,   122,   123,   122,   123,   122,   123,   122,   123,
     122,   123,   118,   122,   123,   124,   125,   124,   125,   124,
     124,   124,   124,   124,   124,   118,   122,   123,   124,   125,
     125,   125,   125,   125,   122,   122,   122,   122,   122,   110,
      87,    41,    41,    41,    74,   110,   129,    12,    13,     3,
      14,    56,   100,   101,   130,    10,   104,   105,   130,    12,
      41,   116,    12,    41,    74,    14,    12,    10,    79,    14,
       9,    10,    10,    40,    12,    12,    12,    10,    40,   110,
     120,    10,   104,    12,    10,    38,    12,   110,     8,   110,
     110,   110,   129,   100,   100,    74,    14,     3,    74,    83,
      10,    40,    40,    74,    12,   116,    12,    41,    12,    41,
     116,    42,    85,    14,     3,   110,    85,   110,   127,    83,
      10,   116,    10,    10,    10,    14,    42,   100,    42,    83,
     130,   105,   130,    42,    12,    12,   116,    12,   116,    12,
      41,   110,     3,    10,    59,    96,    98,    83,    10,    82,
      83,    84,    84,    84,   110,   110,    74,    74,   110,    12,
      12,    12,   116,    40,    85,    12,   121
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    77,    78,    78,    79,    79,    79,    80,    80,    81,
      81,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    83,    83,    83,    83,    83,    84,    84,
      85,    85,    86,    87,    87,    88,    88,    88,    89,    89,
      90,    90,    90,    91,    92,    93,    94,    95,    96,    96,
      97,    98,    99,    99,    99,   100,   100,   100,   100,   101,
     101,   101,   102,   102,   102,   102,   103,   104,   104,   104,
     105,   105,   106,   107,   107,   107,   107,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   109,   109,   110,   110,   110,   110,   110,   110,   110,
     110,   111,   111,   111,   111,   111,   111,   111,   111,   111,
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
     112,   112,   112,   112,   112,   113,   113,   113,   114,   114,
     114,   114,   115,   115,   116,   116,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   118,   118,
     119,   119,   120,   120,   121,   121,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   126,   126,
     127,   127,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   129,   129,   129,   129,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     1,     2,     1,     2,     3,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     3,     4,     4,     5,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     1,     1,     2,
       7,     7,     7,     5,     1,     6,     1,     6,     2,     0,
       1,     1,     4,     5,     6,     1,     2,     2,     3,     2,
       4,     4,     5,     6,     5,     6,     1,     2,     1,     4,
       4,     3,     2,     4,     4,     4,     4,     3,     3,     3,
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
       2,     3,     4,     4,     5,     1,     3,     4,     1,     1,
       3,     3,     5,     7,     1,     1,     3,     4,     4,     5,
       4,     5,     5,     5,     6,     6,     6,     7,     1,     3,
       2,     4,     2,     3,     4,     6,     1,     2,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     3,
       1,     3,     2,     2,     2,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     4,     2,     2,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1
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
     288,   289,   290,   294,   296,   298,   300,   303,   305,   306,
     308,   309,   312,   313,   314,   316,   317,   318,   319,   321,
     322,   323,   327,   328,   329,   330,   332,   334,   335,   336,
     338,   339,   343,   347,   348,   349,   350,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   371,   372,   376,   377,   378,   379,   380,   381,   382,
     383,   386,   387,   388,   389,   390,   392,   393,   395,   396,
     397,   398,   399,   401,   402,   403,   404,   406,   407,   408,
     410,   411,   412,   414,   415,   416,   417,   418,   419,   420,
     421,   423,   424,   425,   426,   427,   429,   430,   431,   432,
     433,   435,   436,   437,   438,   439,   440,   441,   442,   444,
     445,   446,   447,   448,   449,   450,   451,   453,   454,   455,
     457,   458,   459,   461,   462,   463,   464,   465,   466,   467,
     469,   470,   471,   472,   473,   474,   475,   477,   478,   479,
     480,   481,   482,   483,   485,   486,   487,   488,   489,   490,
     491,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   526,   527,   529,   530,   531,   533,   534,
     535,   537,   538,   539,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   553,   554,   555,   556,
     558,   559,   560,   562,   563,   564,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     593,   594,   595,   596,   597,   599,   600,   601,   605,   606,
     607,   608,   610,   611,   613,   614,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   631,   632,
     636,   637,   639,   640,   642,   643,   647,   648,   649,   650,
     651,   652,   653,   654,   655,   656,   657,   658,   659,   660,
     664,   665,   666,   667,   668,   669,   670,   671,   672,   673,
     674,   675,   676,   677,   678,   679,   680,   681,   682,   683,
     684,   688,   689,   690,   691,   692,   693,   694,   695,   696,
     697,   698,   699,   700,   701,   702,   703,   704,   705,   706,
     707,   708,   709,   710,   711,   712,   713,   714,   718,   719,
     720,   721,   722,   724,   725,   726,   727,   728,   729,   730,
     732,   733,   734,   735,   736,   737,   738,   740,   741,   742,
     743,   744,   746,   747,   748,   749,   750,   752,   753,   754,
     755,   756,   758,   759,   760,   761,   762,   764,   768,   769,
     771,   772,   776,   777,   778,   779,   780,   781,   782,   783,
     784,   785,   786,   787,   789,   790,   791,   792,   796,   797,
     798,   799,   800,   801,   802,   803,   804,   805,   806,   807,
     808,   809
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
#line 4820 "frontend/parser.cpp"

#line 812 "frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    auto msg = std::to_string(scanner->loc->begin.line) + ":" + std::to_string(scanner->loc->begin.column) + ": " + err_message;
    scanner->fatal_error(ptc::diag::ERR_SYNTAX, msg);
}
