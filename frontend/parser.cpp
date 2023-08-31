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
#line 226 "frontend/parser.yy"
                        { scanner->parseEntry(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1154 "frontend/parser.cpp"
    break;

  case 4: // stmt: stmts
#line 228 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1160 "frontend/parser.cpp"
    break;

  case 5: // stmt: stmt stmts
#line 229 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1166 "frontend/parser.cpp"
    break;

  case 6: // stmt: stmt error stmts
#line 230 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1172 "frontend/parser.cpp"
    break;

  case 9: // stmts: "terminator (\\n or ;)"
#line 237 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = nullptr; }
#line 1178 "frontend/parser.cpp"
    break;

  case 10: // stmts: stmts_ne
#line 238 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1184 "frontend/parser.cpp"
    break;

  case 11: // stmts_ne: set stmt_end
#line 240 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1190 "frontend/parser.cpp"
    break;

  case 12: // stmts_ne: vardecl stmt_end
#line 241 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1196 "frontend/parser.cpp"
    break;

  case 13: // stmts_ne: vardef stmt_end
#line 242 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1202 "frontend/parser.cpp"
    break;

  case 14: // stmts_ne: import stmt_end
#line 243 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1208 "frontend/parser.cpp"
    break;

  case 16: // stmts_ne: if
#line 245 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1214 "frontend/parser.cpp"
    break;

  case 17: // stmts_ne: while
#line 246 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1220 "frontend/parser.cpp"
    break;

  case 18: // stmts_ne: dowhile
#line 247 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1226 "frontend/parser.cpp"
    break;

  case 19: // stmts_ne: struct
#line 248 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1232 "frontend/parser.cpp"
    break;

  case 20: // stmts_ne: function
#line 249 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1238 "frontend/parser.cpp"
    break;

  case 21: // stmts_ne: flowctl stmt_end
#line 250 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1244 "frontend/parser.cpp"
    break;

  case 22: // stmts_ne: expr stmt_end
#line 251 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1250 "frontend/parser.cpp"
    break;

  case 23: // block: "{" "}"
#line 255 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1256 "frontend/parser.cpp"
    break;

  case 24: // block: "{" stmt "}"
#line 256 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1262 "frontend/parser.cpp"
    break;

  case 25: // block: "terminator (\\n or ;)" "{" stmt "}"
#line 257 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1268 "frontend/parser.cpp"
    break;

  case 26: // block: "{" stmt "}" "terminator (\\n or ;)"
#line 258 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1274 "frontend/parser.cpp"
    break;

  case 27: // block: "terminator (\\n or ;)" "{" stmt "}" "terminator (\\n or ;)"
#line 259 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1280 "frontend/parser.cpp"
    break;

  case 28: // body: stmts_ne
#line 262 "frontend/parser.yy"
                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1286 "frontend/parser.cpp"
    break;

  case 29: // body: block
#line 263 "frontend/parser.yy"
                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1292 "frontend/parser.cpp"
    break;

  case 30: // scope_body: stmts_ne
#line 266 "frontend/parser.yy"
                      { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); scanner->leaveScope(); }
#line 1298 "frontend/parser.cpp"
    break;

  case 31: // scope_body: block
#line 267 "frontend/parser.yy"
                      { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); scanner->leaveScope(); }
#line 1304 "frontend/parser.cpp"
    break;

  case 32: // import: "import" id_list
#line 271 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::IR * > () = scanner->parseImports(yystack_[0].value.as < std::vector<std::string>  > ()); }
#line 1310 "frontend/parser.cpp"
    break;

  case 33: // id_list: "identifier"
#line 273 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseImportName(yystack_[0].value.as < std::string > ()); }
#line 1316 "frontend/parser.cpp"
    break;

  case 34: // id_list: "identifier" "," id_list
#line 274 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseAddImportName(yystack_[0].value.as < std::vector<std::string>  > (), yystack_[2].value.as < std::string > ()); }
#line 1322 "frontend/parser.cpp"
    break;

  case 35: // flowctl: "break"
#line 278 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseBreak(); }
#line 1328 "frontend/parser.cpp"
    break;

  case 36: // flowctl: "continue"
#line 279 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseContinue(); }
#line 1334 "frontend/parser.cpp"
    break;

  case 37: // flowctl: return
#line 280 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1340 "frontend/parser.cpp"
    break;

  case 38: // return: "return"
#line 282 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(nullptr); }
#line 1346 "frontend/parser.cpp"
    break;

  case 39: // return: "return" expr
#line 283 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1352 "frontend/parser.cpp"
    break;

  case 41: // while: wh_kw "(" expr ")" scope_body
#line 291 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseWhile(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1358 "frontend/parser.cpp"
    break;

  case 42: // wh_kw: "while"
#line 293 "frontend/parser.yy"
                { scanner->enterBlockScope(); }
#line 1364 "frontend/parser.cpp"
    break;

  case 43: // dowhile: do_kw scope_body "while" "(" expr ")"
#line 295 "frontend/parser.yy"
                                                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseDoWhile(yystack_[1].value.as < ptc::ir::Expr * > (), yystack_[4].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1370 "frontend/parser.cpp"
    break;

  case 44: // do_kw: "do"
#line 297 "frontend/parser.yy"
             { scanner->enterBlockScope(); }
#line 1376 "frontend/parser.cpp"
    break;

  case 45: // if: if_kw "(" expr ")" scope_body else
#line 300 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseIfStmt(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1382 "frontend/parser.cpp"
    break;

  case 46: // else: el_kw scope_body
#line 302 "frontend/parser.yy"
                         { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1388 "frontend/parser.cpp"
    break;

  case 47: // else: %empty
#line 303 "frontend/parser.yy"
                    { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1394 "frontend/parser.cpp"
    break;

  case 48: // if_kw: "if"
#line 305 "frontend/parser.yy"
             { scanner->enterBlockScope(); }
#line 1400 "frontend/parser.cpp"
    break;

  case 49: // el_kw: "else"
#line 306 "frontend/parser.yy"
               { scanner->enterBlockScope(); }
#line 1406 "frontend/parser.cpp"
    break;

  case 50: // struct: "'struct'" "identifier" "{" "}"
#line 309 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[2].value.as < std::string > (), std::vector<ptc::ir::IR *>{}); }
#line 1412 "frontend/parser.cpp"
    break;

  case 51: // struct: "'struct'" "identifier" "{" decllist "}"
#line 310 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1418 "frontend/parser.cpp"
    break;

  case 52: // struct: "'struct'" "identifier" "terminator (\\n or ;)" "{" decllist "}"
#line 311 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[4].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1424 "frontend/parser.cpp"
    break;

  case 54: // decllist: "terminator (\\n or ;)" decllist
#line 314 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1430 "frontend/parser.cpp"
    break;

  case 55: // decllist: declistval "terminator (\\n or ;)"
#line 315 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[1].value.as < ptc::ir::IR * > (), std::vector<ptc::ir::IR *>{}); }
#line 1436 "frontend/parser.cpp"
    break;

  case 56: // decllist: declistval "terminator (\\n or ;)" decllist
#line 316 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[2].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1442 "frontend/parser.cpp"
    break;

  case 57: // declistval: type "identifier"
#line 318 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > (), nullptr); }
#line 1448 "frontend/parser.cpp"
    break;

  case 58: // declistval: type "identifier" "=" expr
#line 319 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1454 "frontend/parser.cpp"
    break;

  case 60: // function: type fun_id "(" ")" block
#line 324 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1460 "frontend/parser.cpp"
    break;

  case 61: // function: type fun_id "(" funargs ")" block
#line 325 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[5].value.as < ptc::ir::IR * > (), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1466 "frontend/parser.cpp"
    break;

  case 62: // function: "'void'" fun_id "(" ")" block
#line 326 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1472 "frontend/parser.cpp"
    break;

  case 63: // function: "'void'" fun_id "(" funargs ")" block
#line 327 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1478 "frontend/parser.cpp"
    break;

  case 64: // fun_id: "identifier"
#line 329 "frontend/parser.yy"
            { scanner->enterFunScope(); yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1484 "frontend/parser.cpp"
    break;

  case 65: // funargs: type "identifier"
#line 331 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseFunParam(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1490 "frontend/parser.cpp"
    break;

  case 67: // funargs: funargs "," type "identifier"
#line 333 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseAddFunParam(yystack_[3].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1496 "frontend/parser.cpp"
    break;

  case 70: // vardecl: type "identifier"
#line 340 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1502 "frontend/parser.cpp"
    break;

  case 71: // vardef: type "identifier" "=" struct_val
#line 344 "frontend/parser.yy"
         { yylhs.value.as < ptc::ir::IR * > () = yystack_[3].value.as < ptc::ir::IR * > (); }
#line 1508 "frontend/parser.cpp"
    break;

  case 72: // vardef: type "identifier" "=" expr
#line 345 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1514 "frontend/parser.cpp"
    break;

  case 75: // set: expr "++=" expr
#line 351 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1520 "frontend/parser.cpp"
    break;

  case 76: // set: expr "**=" expr
#line 352 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1526 "frontend/parser.cpp"
    break;

  case 77: // set: expr "%=" expr
#line 353 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1532 "frontend/parser.cpp"
    break;

  case 78: // set: expr "/=" expr
#line 354 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1538 "frontend/parser.cpp"
    break;

  case 79: // set: expr "*=" expr
#line 355 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1544 "frontend/parser.cpp"
    break;

  case 80: // set: expr "-=" expr
#line 356 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1550 "frontend/parser.cpp"
    break;

  case 81: // set: expr "+=" expr
#line 357 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1556 "frontend/parser.cpp"
    break;

  case 82: // set: expr "&=" expr
#line 358 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1562 "frontend/parser.cpp"
    break;

  case 83: // set: expr "|=" expr
#line 359 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1568 "frontend/parser.cpp"
    break;

  case 84: // set: expr "^=" expr
#line 360 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1574 "frontend/parser.cpp"
    break;

  case 85: // set: expr "<<=" expr
#line 361 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1580 "frontend/parser.cpp"
    break;

  case 86: // set: expr ">>=" expr
#line 362 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1586 "frontend/parser.cpp"
    break;

  case 87: // set: expr "=" expr
#line 363 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1592 "frontend/parser.cpp"
    break;

  case 88: // set: expr "=" set
#line 364 "frontend/parser.yy"
      { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1598 "frontend/parser.cpp"
    break;

  case 89: // callarglist: expr
#line 368 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseFunCallArg(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1604 "frontend/parser.cpp"
    break;

  case 90: // callarglist: expr "," callarglist
#line 369 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddFunCallArg(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[2].value.as < ptc::ir::Expr * > ()); }
#line 1610 "frontend/parser.cpp"
    break;

  case 91: // expr: expr_mat
#line 373 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1616 "frontend/parser.cpp"
    break;

  case 92: // expr: expr_var
#line 374 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1622 "frontend/parser.cpp"
    break;

  case 95: // expr: expr_int
#line 377 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 1628 "frontend/parser.cpp"
    break;

  case 96: // expr: expr_float
#line 378 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFloat(yystack_[0].value.as < double > ()); }
#line 1634 "frontend/parser.cpp"
    break;

  case 97: // expr: expr_str
#line 379 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseString(yystack_[0].value.as < std::string > ()); }
#line 1640 "frontend/parser.cpp"
    break;

  case 98: // expr: expr_bool
#line 380 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseBool(yystack_[0].value.as < bool > ()); }
#line 1646 "frontend/parser.cpp"
    break;

  case 99: // expr_var: "identifier"
#line 383 "frontend/parser.yy"
              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > ()); }
#line 1652 "frontend/parser.cpp"
    break;

  case 100: // expr_var: "external identifier"
#line 384 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > (), true); }
#line 1658 "frontend/parser.cpp"
    break;

  case 101: // expr_var: "-" "identifier"
#line 385 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1664 "frontend/parser.cpp"
    break;

  case 102: // expr_var: "-" "external identifier"
#line 386 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > (), true), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1670 "frontend/parser.cpp"
    break;

  case 103: // expr_var: "(" expr_var ")"
#line 387 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1676 "frontend/parser.cpp"
    break;

  case 104: // expr_var: expr_var "(" ")"
#line 389 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[2].value.as < ptc::ir::Expr * > (), std::vector<ptc::ir::Expr *>{}); }
#line 1682 "frontend/parser.cpp"
    break;

  case 105: // expr_var: expr_var "(" callarglist ")"
#line 390 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 1688 "frontend/parser.cpp"
    break;

  case 107: // expr_var: expr_mat "[" int_val "]"
#line 393 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[3].value.as < ptc::ir::Expr * > (); }
#line 1694 "frontend/parser.cpp"
    break;

  case 110: // expr_var: expr_var "[" int_val "]"
#line 396 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[3].value.as < ptc::ir::Expr * > (); }
#line 1700 "frontend/parser.cpp"
    break;

  case 111: // expr_var: expr_mat slice
#line 398 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1706 "frontend/parser.cpp"
    break;

  case 114: // expr_var: expr_var slice
#line 401 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1712 "frontend/parser.cpp"
    break;

  case 115: // expr_var: "identifier" "." expr_var
#line 403 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1718 "frontend/parser.cpp"
    break;

  case 116: // expr_var: "external identifier" "." expr_var
#line 404 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1724 "frontend/parser.cpp"
    break;

  case 117: // expr_var: expr_var "." expr_var
#line 405 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1730 "frontend/parser.cpp"
    break;

  case 119: // expr_var: expr_var "**" expr_float
#line 408 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1736 "frontend/parser.cpp"
    break;

  case 120: // expr_var: expr_var "**" expr_var
#line 409 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1742 "frontend/parser.cpp"
    break;

  case 121: // expr_var: expr_int "*" expr_var
#line 411 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1748 "frontend/parser.cpp"
    break;

  case 122: // expr_var: expr_float "*" expr_var
#line 412 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1754 "frontend/parser.cpp"
    break;

  case 123: // expr_var: expr_var "*" expr_int
#line 413 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1760 "frontend/parser.cpp"
    break;

  case 124: // expr_var: expr_var "*" expr_float
#line 414 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1766 "frontend/parser.cpp"
    break;

  case 125: // expr_var: expr_mat "*" expr_mat
#line 415 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1772 "frontend/parser.cpp"
    break;

  case 126: // expr_var: expr_mat "*" expr_var
#line 416 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1778 "frontend/parser.cpp"
    break;

  case 127: // expr_var: expr_var "*" expr_mat
#line 417 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1784 "frontend/parser.cpp"
    break;

  case 128: // expr_var: expr_var "*" expr_var
#line 418 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1790 "frontend/parser.cpp"
    break;

  case 129: // expr_var: expr_int "/" expr_var
#line 420 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1796 "frontend/parser.cpp"
    break;

  case 130: // expr_var: expr_float "/" expr_var
#line 421 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1802 "frontend/parser.cpp"
    break;

  case 131: // expr_var: expr_var "/" expr_int
#line 422 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1808 "frontend/parser.cpp"
    break;

  case 132: // expr_var: expr_var "/" expr_float
#line 423 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1814 "frontend/parser.cpp"
    break;

  case 133: // expr_var: expr_var "/" expr_var
#line 424 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1820 "frontend/parser.cpp"
    break;

  case 134: // expr_var: expr_int "%" expr_var
#line 426 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1826 "frontend/parser.cpp"
    break;

  case 135: // expr_var: expr_float "%" expr_var
#line 427 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1832 "frontend/parser.cpp"
    break;

  case 136: // expr_var: expr_var "%" expr_int
#line 428 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1838 "frontend/parser.cpp"
    break;

  case 137: // expr_var: expr_var "%" expr_float
#line 429 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1844 "frontend/parser.cpp"
    break;

  case 138: // expr_var: expr_var "%" expr_var
#line 430 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1850 "frontend/parser.cpp"
    break;

  case 139: // expr_var: expr_int "+" expr_var
#line 432 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1856 "frontend/parser.cpp"
    break;

  case 140: // expr_var: expr_float "+" expr_var
#line 433 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1862 "frontend/parser.cpp"
    break;

  case 141: // expr_var: expr_var "+" expr_int
#line 434 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1868 "frontend/parser.cpp"
    break;

  case 142: // expr_var: expr_var "+" expr_float
#line 435 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1874 "frontend/parser.cpp"
    break;

  case 143: // expr_var: expr_mat "+" expr_mat
#line 436 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1880 "frontend/parser.cpp"
    break;

  case 144: // expr_var: expr_var "+" expr_mat
#line 437 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1886 "frontend/parser.cpp"
    break;

  case 145: // expr_var: expr_mat "+" expr_var
#line 438 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1892 "frontend/parser.cpp"
    break;

  case 146: // expr_var: expr_var "+" expr_var
#line 439 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1898 "frontend/parser.cpp"
    break;

  case 147: // expr_var: expr_int "-" expr_var
#line 441 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1904 "frontend/parser.cpp"
    break;

  case 148: // expr_var: expr_float "-" expr_var
#line 442 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1910 "frontend/parser.cpp"
    break;

  case 149: // expr_var: expr_var "-" expr_int
#line 443 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1916 "frontend/parser.cpp"
    break;

  case 150: // expr_var: expr_var "-" expr_float
#line 444 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1922 "frontend/parser.cpp"
    break;

  case 151: // expr_var: expr_mat "-" expr_mat
#line 445 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1928 "frontend/parser.cpp"
    break;

  case 152: // expr_var: expr_var "-" expr_mat
#line 446 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1934 "frontend/parser.cpp"
    break;

  case 153: // expr_var: expr_mat "-" expr_var
#line 447 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1940 "frontend/parser.cpp"
    break;

  case 154: // expr_var: expr_var "-" expr_var
#line 448 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1946 "frontend/parser.cpp"
    break;

  case 155: // expr_var: expr_int "<<" expr_var
#line 450 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 1952 "frontend/parser.cpp"
    break;

  case 156: // expr_var: expr_var "<<" expr_int
#line 451 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 1958 "frontend/parser.cpp"
    break;

  case 157: // expr_var: expr_var "<<" expr_var
#line 452 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 1964 "frontend/parser.cpp"
    break;

  case 158: // expr_var: expr_int ">>" expr_var
#line 454 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 1970 "frontend/parser.cpp"
    break;

  case 159: // expr_var: expr_var ">>" expr_int
#line 455 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 1976 "frontend/parser.cpp"
    break;

  case 160: // expr_var: expr_var ">>" expr_var
#line 456 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 1982 "frontend/parser.cpp"
    break;

  case 161: // expr_var: expr_int ">" expr_var
#line 458 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 1988 "frontend/parser.cpp"
    break;

  case 162: // expr_var: expr_float ">" expr_var
#line 459 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 1994 "frontend/parser.cpp"
    break;

  case 164: // expr_var: expr_var ">" expr_int
#line 461 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2000 "frontend/parser.cpp"
    break;

  case 165: // expr_var: expr_var ">" expr_float
#line 462 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2006 "frontend/parser.cpp"
    break;

  case 166: // expr_var: expr_var ">" expr_str
#line 463 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2012 "frontend/parser.cpp"
    break;

  case 167: // expr_var: expr_var ">" expr_var
#line 464 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2018 "frontend/parser.cpp"
    break;

  case 168: // expr_var: expr_int ">=" expr_var
#line 466 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2024 "frontend/parser.cpp"
    break;

  case 169: // expr_var: expr_float ">=" expr_var
#line 467 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2030 "frontend/parser.cpp"
    break;

  case 171: // expr_var: expr_var ">=" expr_int
#line 469 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2036 "frontend/parser.cpp"
    break;

  case 172: // expr_var: expr_var ">=" expr_float
#line 470 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2042 "frontend/parser.cpp"
    break;

  case 173: // expr_var: expr_var ">=" expr_str
#line 471 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2048 "frontend/parser.cpp"
    break;

  case 174: // expr_var: expr_var ">=" expr_var
#line 472 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2054 "frontend/parser.cpp"
    break;

  case 175: // expr_var: expr_int "<" expr_var
#line 474 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2060 "frontend/parser.cpp"
    break;

  case 176: // expr_var: expr_float "<" expr_var
#line 475 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2066 "frontend/parser.cpp"
    break;

  case 178: // expr_var: expr_var "<" expr_int
#line 477 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2072 "frontend/parser.cpp"
    break;

  case 179: // expr_var: expr_var "<" expr_float
#line 478 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2078 "frontend/parser.cpp"
    break;

  case 180: // expr_var: expr_var "<" expr_str
#line 479 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2084 "frontend/parser.cpp"
    break;

  case 181: // expr_var: expr_var "<" expr_var
#line 480 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2090 "frontend/parser.cpp"
    break;

  case 182: // expr_var: expr_int "<=" expr_var
#line 482 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2096 "frontend/parser.cpp"
    break;

  case 183: // expr_var: expr_float "<=" expr_var
#line 483 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2102 "frontend/parser.cpp"
    break;

  case 185: // expr_var: expr_var "<=" expr_int
#line 485 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2108 "frontend/parser.cpp"
    break;

  case 186: // expr_var: expr_var "<=" expr_float
#line 486 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2114 "frontend/parser.cpp"
    break;

  case 187: // expr_var: expr_var "<=" expr_str
#line 487 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2120 "frontend/parser.cpp"
    break;

  case 188: // expr_var: expr_var "<=" expr_var
#line 488 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2126 "frontend/parser.cpp"
    break;

  case 189: // expr_var: expr_int "==" expr_var
#line 490 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2132 "frontend/parser.cpp"
    break;

  case 190: // expr_var: expr_float "==" expr_var
#line 491 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2138 "frontend/parser.cpp"
    break;

  case 192: // expr_var: expr_bool "==" expr_var
#line 493 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2144 "frontend/parser.cpp"
    break;

  case 196: // expr_var: expr_var "==" expr_int
#line 497 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2150 "frontend/parser.cpp"
    break;

  case 197: // expr_var: expr_var "==" expr_float
#line 498 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2156 "frontend/parser.cpp"
    break;

  case 198: // expr_var: expr_var "==" expr_str
#line 499 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2162 "frontend/parser.cpp"
    break;

  case 199: // expr_var: expr_var "==" expr_bool
#line 500 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2168 "frontend/parser.cpp"
    break;

  case 200: // expr_var: expr_var "==" expr_none
#line 501 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2174 "frontend/parser.cpp"
    break;

  case 201: // expr_var: expr_var "==" expr_struct
#line 502 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2180 "frontend/parser.cpp"
    break;

  case 202: // expr_var: expr_mat "==" expr_mat
#line 503 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2186 "frontend/parser.cpp"
    break;

  case 203: // expr_var: expr_var "==" expr_mat
#line 504 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2192 "frontend/parser.cpp"
    break;

  case 204: // expr_var: expr_mat "==" expr_var
#line 505 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2198 "frontend/parser.cpp"
    break;

  case 205: // expr_var: expr_var "==" expr_var
#line 506 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2204 "frontend/parser.cpp"
    break;

  case 206: // expr_var: expr_int "!=" expr_var
#line 508 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2210 "frontend/parser.cpp"
    break;

  case 207: // expr_var: expr_float "!=" expr_var
#line 509 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2216 "frontend/parser.cpp"
    break;

  case 213: // expr_var: expr_var "!=" expr_int
#line 515 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2222 "frontend/parser.cpp"
    break;

  case 214: // expr_var: expr_var "!=" expr_float
#line 516 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2228 "frontend/parser.cpp"
    break;

  case 215: // expr_var: expr_var "!=" expr_str
#line 517 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2234 "frontend/parser.cpp"
    break;

  case 216: // expr_var: expr_var "!=" expr_bool
#line 518 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2240 "frontend/parser.cpp"
    break;

  case 217: // expr_var: expr_var "!=" expr_none
#line 519 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2246 "frontend/parser.cpp"
    break;

  case 218: // expr_var: expr_var "!=" expr_struct
#line 520 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2252 "frontend/parser.cpp"
    break;

  case 219: // expr_var: expr_mat "!=" expr_mat
#line 521 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2258 "frontend/parser.cpp"
    break;

  case 220: // expr_var: expr_var "!=" expr_mat
#line 522 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2264 "frontend/parser.cpp"
    break;

  case 221: // expr_var: expr_mat "!=" expr_var
#line 523 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2270 "frontend/parser.cpp"
    break;

  case 222: // expr_var: expr_var "!=" expr_var
#line 524 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2276 "frontend/parser.cpp"
    break;

  case 223: // expr_var: expr_int "&" expr_var
#line 526 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2282 "frontend/parser.cpp"
    break;

  case 224: // expr_var: expr_var "&" expr_int
#line 527 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2288 "frontend/parser.cpp"
    break;

  case 225: // expr_var: expr_var "&" expr_var
#line 528 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2294 "frontend/parser.cpp"
    break;

  case 226: // expr_var: expr_int "^" expr_var
#line 530 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2300 "frontend/parser.cpp"
    break;

  case 227: // expr_var: expr_var "^" expr_int
#line 531 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2306 "frontend/parser.cpp"
    break;

  case 228: // expr_var: expr_var "^" expr_var
#line 532 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2312 "frontend/parser.cpp"
    break;

  case 229: // expr_var: expr_int "|" expr_var
#line 534 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2318 "frontend/parser.cpp"
    break;

  case 230: // expr_var: expr_var "|" expr_int
#line 535 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2324 "frontend/parser.cpp"
    break;

  case 231: // expr_var: expr_var "|" expr_var
#line 536 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2330 "frontend/parser.cpp"
    break;

  case 238: // expr_var: expr_mat "in" expr_mat
#line 544 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2336 "frontend/parser.cpp"
    break;

  case 245: // expr_var: expr_mat "in" expr_var
#line 551 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2342 "frontend/parser.cpp"
    break;

  case 246: // expr_var: expr_var "in" expr_str
#line 552 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2348 "frontend/parser.cpp"
    break;

  case 247: // expr_var: expr_var "in" expr_var
#line 553 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2354 "frontend/parser.cpp"
    break;

  case 248: // expr_var: expr_bool "and" expr_var
#line 555 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2360 "frontend/parser.cpp"
    break;

  case 249: // expr_var: expr_var "and" expr_bool
#line 556 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2366 "frontend/parser.cpp"
    break;

  case 250: // expr_var: expr_var "and" expr_var
#line 557 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2372 "frontend/parser.cpp"
    break;

  case 251: // expr_var: expr_bool "or" expr_var
#line 559 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2378 "frontend/parser.cpp"
    break;

  case 252: // expr_var: expr_var "or" expr_bool
#line 560 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2384 "frontend/parser.cpp"
    break;

  case 253: // expr_var: expr_var "or" expr_var
#line 561 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2390 "frontend/parser.cpp"
    break;

  case 265: // expr_var: expr_int "++" expr_var
#line 574 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2396 "frontend/parser.cpp"
    break;

  case 266: // expr_var: expr_float "++" expr_var
#line 575 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2402 "frontend/parser.cpp"
    break;

  case 267: // expr_var: expr_str "++" expr_var
#line 576 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2408 "frontend/parser.cpp"
    break;

  case 268: // expr_var: expr_bool "++" expr_var
#line 577 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2414 "frontend/parser.cpp"
    break;

  case 271: // expr_var: expr_var "++" expr_int
#line 580 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2420 "frontend/parser.cpp"
    break;

  case 272: // expr_var: expr_var "++" expr_float
#line 581 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2426 "frontend/parser.cpp"
    break;

  case 273: // expr_var: expr_var "++" expr_str
#line 582 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2432 "frontend/parser.cpp"
    break;

  case 274: // expr_var: expr_var "++" expr_bool
#line 583 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2438 "frontend/parser.cpp"
    break;

  case 275: // expr_var: expr_var "++" expr_none
#line 584 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2444 "frontend/parser.cpp"
    break;

  case 276: // expr_var: expr_var "++" expr_struct
#line 585 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2450 "frontend/parser.cpp"
    break;

  case 277: // expr_var: expr_var "++" expr_var
#line 586 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2456 "frontend/parser.cpp"
    break;

  case 278: // matrix: "[" "]"
#line 590 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(std::vector<ptc::ir::Expr *>{}); }
#line 2462 "frontend/parser.cpp"
    break;

  case 279: // matrix: "[" matvals "]"
#line 591 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2468 "frontend/parser.cpp"
    break;

  case 280: // matrix: "[" "terminator (\\n or ;)" matvals "]"
#line 592 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2474 "frontend/parser.cpp"
    break;

  case 281: // matrix: "[" matvals "terminator (\\n or ;)" "]"
#line 593 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2480 "frontend/parser.cpp"
    break;

  case 282: // matrix: "[" "terminator (\\n or ;)" matvals "terminator (\\n or ;)" "]"
#line 594 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2486 "frontend/parser.cpp"
    break;

  case 283: // matvals: expr
#line 596 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixValue(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2492 "frontend/parser.cpp"
    break;

  case 284: // matvals: matvals "," expr
#line 597 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2498 "frontend/parser.cpp"
    break;

  case 285: // matvals: matvals "," "terminator (\\n or ;)" expr
#line 598 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[3].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2504 "frontend/parser.cpp"
    break;

  case 286: // expr_mat: matrix
#line 602 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2510 "frontend/parser.cpp"
    break;

  case 292: // int_val: expr_int
#line 610 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 2516 "frontend/parser.cpp"
    break;

  case 293: // int_val: expr_var
#line 611 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2522 "frontend/parser.cpp"
    break;

  case 314: // expr_int: "int"
#line 644 "frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 2528 "frontend/parser.cpp"
    break;

  case 315: // expr_int: "-" expr_int
#line 645 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 2534 "frontend/parser.cpp"
    break;

  case 316: // expr_int: "(" expr_int ")"
#line 646 "frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 2540 "frontend/parser.cpp"
    break;

  case 317: // expr_int: "~" expr_int
#line 647 "frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 2546 "frontend/parser.cpp"
    break;

  case 318: // expr_int: expr_int "*" expr_int
#line 648 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 2552 "frontend/parser.cpp"
    break;

  case 319: // expr_int: expr_int "/" expr_int
#line 649 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 2558 "frontend/parser.cpp"
    break;

  case 320: // expr_int: expr_int "%" expr_int
#line 650 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 2564 "frontend/parser.cpp"
    break;

  case 321: // expr_int: expr_int "-" expr_int
#line 651 "frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 2570 "frontend/parser.cpp"
    break;

  case 322: // expr_int: expr_int "+" expr_int
#line 652 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 2576 "frontend/parser.cpp"
    break;

  case 323: // expr_int: expr_int "<<" expr_int
#line 653 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 2582 "frontend/parser.cpp"
    break;

  case 324: // expr_int: expr_int ">>" expr_int
#line 654 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 2588 "frontend/parser.cpp"
    break;

  case 325: // expr_int: expr_int "&" expr_int
#line 655 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 2594 "frontend/parser.cpp"
    break;

  case 326: // expr_int: expr_int "^" expr_int
#line 656 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 2600 "frontend/parser.cpp"
    break;

  case 327: // expr_int: expr_int "|" expr_int
#line 657 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 2606 "frontend/parser.cpp"
    break;

  case 328: // expr_float: "float"
#line 661 "frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 2612 "frontend/parser.cpp"
    break;

  case 329: // expr_float: "-" expr_float
#line 662 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 2618 "frontend/parser.cpp"
    break;

  case 330: // expr_float: "(" expr_float ")"
#line 663 "frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 2624 "frontend/parser.cpp"
    break;

  case 331: // expr_float: expr_float "**" expr_float
#line 664 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2630 "frontend/parser.cpp"
    break;

  case 332: // expr_float: expr_float "**" expr_int
#line 665 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2636 "frontend/parser.cpp"
    break;

  case 333: // expr_float: expr_int "**" expr_float
#line 666 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2642 "frontend/parser.cpp"
    break;

  case 334: // expr_float: expr_float "*" expr_float
#line 667 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 2648 "frontend/parser.cpp"
    break;

  case 335: // expr_float: expr_float "*" expr_int
#line 668 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 2654 "frontend/parser.cpp"
    break;

  case 336: // expr_float: expr_int "*" expr_float
#line 669 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 2660 "frontend/parser.cpp"
    break;

  case 337: // expr_float: expr_float "/" expr_float
#line 670 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 2666 "frontend/parser.cpp"
    break;

  case 338: // expr_float: expr_float "/" expr_int
#line 671 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 2672 "frontend/parser.cpp"
    break;

  case 339: // expr_float: expr_int "/" expr_float
#line 672 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 2678 "frontend/parser.cpp"
    break;

  case 340: // expr_float: expr_float "%" expr_float
#line 673 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2684 "frontend/parser.cpp"
    break;

  case 341: // expr_float: expr_float "%" expr_int
#line 674 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2690 "frontend/parser.cpp"
    break;

  case 342: // expr_float: expr_int "%" expr_float
#line 675 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2696 "frontend/parser.cpp"
    break;

  case 343: // expr_float: expr_float "-" expr_float
#line 676 "frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 2702 "frontend/parser.cpp"
    break;

  case 344: // expr_float: expr_float "-" expr_int
#line 677 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 2708 "frontend/parser.cpp"
    break;

  case 345: // expr_float: expr_int "-" expr_float
#line 678 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 2714 "frontend/parser.cpp"
    break;

  case 346: // expr_float: expr_float "+" expr_float
#line 679 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 2720 "frontend/parser.cpp"
    break;

  case 347: // expr_float: expr_float "+" expr_int
#line 680 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 2726 "frontend/parser.cpp"
    break;

  case 348: // expr_float: expr_int "+" expr_float
#line 681 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 2732 "frontend/parser.cpp"
    break;

  case 349: // expr_str: "string"
#line 685 "frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2738 "frontend/parser.cpp"
    break;

  case 350: // expr_str: "(" expr_str ")"
#line 686 "frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 2744 "frontend/parser.cpp"
    break;

  case 351: // expr_str: expr_str "++" expr_str
#line 687 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 2750 "frontend/parser.cpp"
    break;

  case 352: // expr_str: expr_str "++" expr_int
#line 688 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 2756 "frontend/parser.cpp"
    break;

  case 353: // expr_str: expr_str "++" expr_float
#line 689 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 2762 "frontend/parser.cpp"
    break;

  case 354: // expr_str: expr_str "++" expr_bool
#line 690 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2768 "frontend/parser.cpp"
    break;

  case 355: // expr_str: expr_str "++" expr_none
#line 691 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 2774 "frontend/parser.cpp"
    break;

  case 356: // expr_str: expr_int "++" expr_str
#line 692 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 2780 "frontend/parser.cpp"
    break;

  case 357: // expr_str: expr_int "++" expr_int
#line 693 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 2786 "frontend/parser.cpp"
    break;

  case 358: // expr_str: expr_int "++" expr_float
#line 694 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 2792 "frontend/parser.cpp"
    break;

  case 359: // expr_str: expr_int "++" expr_bool
#line 695 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2798 "frontend/parser.cpp"
    break;

  case 360: // expr_str: expr_int "++" expr_none
#line 696 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 2804 "frontend/parser.cpp"
    break;

  case 361: // expr_str: expr_float "++" expr_str
#line 697 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 2810 "frontend/parser.cpp"
    break;

  case 362: // expr_str: expr_float "++" expr_int
#line 698 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 2816 "frontend/parser.cpp"
    break;

  case 363: // expr_str: expr_float "++" expr_float
#line 699 "frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 2822 "frontend/parser.cpp"
    break;

  case 364: // expr_str: expr_float "++" expr_bool
#line 700 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2828 "frontend/parser.cpp"
    break;

  case 365: // expr_str: expr_float "++" expr_none
#line 701 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 2834 "frontend/parser.cpp"
    break;

  case 366: // expr_str: expr_bool "++" expr_str
#line 702 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 2840 "frontend/parser.cpp"
    break;

  case 367: // expr_str: expr_bool "++" expr_int
#line 703 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 2846 "frontend/parser.cpp"
    break;

  case 368: // expr_str: expr_bool "++" expr_float
#line 704 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 2852 "frontend/parser.cpp"
    break;

  case 369: // expr_str: expr_bool "++" expr_bool
#line 705 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2858 "frontend/parser.cpp"
    break;

  case 370: // expr_str: expr_bool "++" expr_none
#line 706 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 2864 "frontend/parser.cpp"
    break;

  case 371: // expr_str: expr_none "++" expr_str
#line 707 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 2870 "frontend/parser.cpp"
    break;

  case 372: // expr_str: expr_none "++" expr_int
#line 708 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 2876 "frontend/parser.cpp"
    break;

  case 373: // expr_str: expr_none "++" expr_float
#line 709 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 2882 "frontend/parser.cpp"
    break;

  case 374: // expr_str: expr_none "++" expr_bool
#line 710 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2888 "frontend/parser.cpp"
    break;

  case 375: // expr_str: expr_none "++" expr_none
#line 711 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 2894 "frontend/parser.cpp"
    break;

  case 376: // expr_bool: "bool"
#line 715 "frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 2900 "frontend/parser.cpp"
    break;

  case 377: // expr_bool: "(" expr_bool ")"
#line 716 "frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 2906 "frontend/parser.cpp"
    break;

  case 378: // expr_bool: "not" expr_bool
#line 717 "frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 2912 "frontend/parser.cpp"
    break;

  case 379: // expr_bool: expr_bool "or" expr_bool
#line 718 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 2918 "frontend/parser.cpp"
    break;

  case 380: // expr_bool: expr_bool "and" expr_bool
#line 719 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 2924 "frontend/parser.cpp"
    break;

  case 381: // expr_bool: expr_bool "==" expr_bool
#line 721 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 2930 "frontend/parser.cpp"
    break;

  case 382: // expr_bool: expr_int "==" expr_int
#line 722 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 2936 "frontend/parser.cpp"
    break;

  case 383: // expr_bool: expr_int "==" expr_float
#line 723 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 2942 "frontend/parser.cpp"
    break;

  case 384: // expr_bool: expr_float "==" expr_float
#line 724 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 2948 "frontend/parser.cpp"
    break;

  case 385: // expr_bool: expr_float "==" expr_int
#line 725 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 2954 "frontend/parser.cpp"
    break;

  case 386: // expr_bool: expr_str "==" expr_str
#line 726 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 2960 "frontend/parser.cpp"
    break;

  case 387: // expr_bool: expr_none "==" expr_none
#line 727 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 2966 "frontend/parser.cpp"
    break;

  case 388: // expr_bool: expr_bool "!=" expr_bool
#line 729 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 2972 "frontend/parser.cpp"
    break;

  case 389: // expr_bool: expr_int "!=" expr_int
#line 730 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 2978 "frontend/parser.cpp"
    break;

  case 390: // expr_bool: expr_int "!=" expr_float
#line 731 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 2984 "frontend/parser.cpp"
    break;

  case 391: // expr_bool: expr_float "!=" expr_float
#line 732 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 2990 "frontend/parser.cpp"
    break;

  case 392: // expr_bool: expr_float "!=" expr_int
#line 733 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 2996 "frontend/parser.cpp"
    break;

  case 393: // expr_bool: expr_str "!=" expr_str
#line 734 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 3002 "frontend/parser.cpp"
    break;

  case 394: // expr_bool: expr_none "!=" expr_none
#line 735 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 3008 "frontend/parser.cpp"
    break;

  case 395: // expr_bool: expr_int ">" expr_int
#line 737 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 3014 "frontend/parser.cpp"
    break;

  case 396: // expr_bool: expr_int ">" expr_float
#line 738 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 3020 "frontend/parser.cpp"
    break;

  case 397: // expr_bool: expr_float ">" expr_float
#line 739 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 3026 "frontend/parser.cpp"
    break;

  case 398: // expr_bool: expr_float ">" expr_int
#line 740 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 3032 "frontend/parser.cpp"
    break;

  case 399: // expr_bool: expr_str ">" expr_str
#line 741 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 3038 "frontend/parser.cpp"
    break;

  case 400: // expr_bool: expr_int "<" expr_int
#line 743 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 3044 "frontend/parser.cpp"
    break;

  case 401: // expr_bool: expr_int "<" expr_float
#line 744 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 3050 "frontend/parser.cpp"
    break;

  case 402: // expr_bool: expr_float "<" expr_float
#line 745 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 3056 "frontend/parser.cpp"
    break;

  case 403: // expr_bool: expr_float "<" expr_int
#line 746 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 3062 "frontend/parser.cpp"
    break;

  case 404: // expr_bool: expr_str "<" expr_str
#line 747 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 3068 "frontend/parser.cpp"
    break;

  case 405: // expr_bool: expr_int ">=" expr_int
#line 749 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 3074 "frontend/parser.cpp"
    break;

  case 406: // expr_bool: expr_int ">=" expr_float
#line 750 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 3080 "frontend/parser.cpp"
    break;

  case 407: // expr_bool: expr_float ">=" expr_float
#line 751 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 3086 "frontend/parser.cpp"
    break;

  case 408: // expr_bool: expr_float ">=" expr_int
#line 752 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 3092 "frontend/parser.cpp"
    break;

  case 409: // expr_bool: expr_str ">=" expr_str
#line 753 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 3098 "frontend/parser.cpp"
    break;

  case 410: // expr_bool: expr_int "<=" expr_int
#line 755 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 3104 "frontend/parser.cpp"
    break;

  case 411: // expr_bool: expr_int "<=" expr_float
#line 756 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 3110 "frontend/parser.cpp"
    break;

  case 412: // expr_bool: expr_float "<=" expr_float
#line 757 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 3116 "frontend/parser.cpp"
    break;

  case 413: // expr_bool: expr_float "<=" expr_int
#line 758 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 3122 "frontend/parser.cpp"
    break;

  case 414: // expr_bool: expr_str "<=" expr_str
#line 759 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 3128 "frontend/parser.cpp"
    break;

  case 415: // expr_bool: expr_str "in" expr_str
#line 761 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[0].value.as < std::string > ().find(yystack_[2].value.as < std::string > ()) != std::string::npos; }
#line 3134 "frontend/parser.cpp"
    break;

  case 420: // mattype: "identifier" matsq
#line 773 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3140 "frontend/parser.cpp"
    break;

  case 421: // mattype: "'int'" matsq
#line 774 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(INT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3146 "frontend/parser.cpp"
    break;

  case 422: // mattype: "'float'" matsq
#line 775 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(FLOAT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3152 "frontend/parser.cpp"
    break;

  case 423: // mattype: "'string'" matsq
#line 776 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(STRING_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3158 "frontend/parser.cpp"
    break;

  case 424: // mattype: "'bool'" matsq
#line 777 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(BOOL_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3164 "frontend/parser.cpp"
    break;

  case 432: // matsq: "[" "]"
#line 786 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(scanner->parseInt(-1)); }
#line 3170 "frontend/parser.cpp"
    break;

  case 433: // matsq: "[" int_val "]"
#line 787 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 3176 "frontend/parser.cpp"
    break;

  case 434: // matsq: "[" "]" matsq
#line 788 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), scanner->parseInt(-1)); }
#line 3182 "frontend/parser.cpp"
    break;

  case 435: // matsq: "[" int_val "]" matsq
#line 789 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[2].value.as < ptc::ir::Expr * > ()); }
#line 3188 "frontend/parser.cpp"
    break;

  case 442: // type: mattype "?"
#line 799 "frontend/parser.yy"
       { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 3194 "frontend/parser.cpp"
    break;

  case 443: // type: "'int'"
#line 800 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, true); }
#line 3200 "frontend/parser.cpp"
    break;

  case 444: // type: "'float'"
#line 801 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, true); }
#line 3206 "frontend/parser.cpp"
    break;

  case 445: // type: "'string'"
#line 802 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, true); }
#line 3212 "frontend/parser.cpp"
    break;

  case 446: // type: "'bool'"
#line 803 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, true); }
#line 3218 "frontend/parser.cpp"
    break;

  case 447: // type: "identifier"
#line 804 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[0].value.as < std::string > (), true); }
#line 3224 "frontend/parser.cpp"
    break;

  case 449: // type: mattype
#line 806 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 3230 "frontend/parser.cpp"
    break;


#line 3234 "frontend/parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -756;

  const short  Parser ::yytable_ninf_ = -448;

  const short
   Parser ::yypact_[] =
  {
    1939,  -756,  -756,  -756,  -756,  -756,  -756,  -756,  1135,    40,
     176,  1192,   179,   -51,   -40,  -756,    32,  -756,  -756,  1352,
    -756,  -756,   -11,    -6,     7,    28,    29,     1,    33,    99,
     230,   125,  1655,  -756,  -756,   129,   129,  -756,  -756,  -756,
     127,  -756,  2457,  -756,   132,  -756,  -756,   129,   129,   129,
     613,  2364,  -756,   882,  -756,   353,   381,  2803,  2923,   953,
     224,    46,   105,    -3,   183,   171,  1748,   187,   882,   238,
     151,   353,   381,  2713,  1512,   824,   789,  1352,  -756,   171,
    -756,    14,   519,   519,  -756,  -756,  -756,  -756,  1510,   233,
    2829,  2779,  1867,  -756,   179,   179,  -756,   144,   203,  -756,
     185,  -756,   247,   616,   250,  -756,   250,  -756,   250,  -756,
     250,  -756,    55,  -756,   266,   329,   103,  1352,   250,  -756,
    -756,  -756,   690,  1352,  -756,  -756,  -756,  2560,  -756,  -756,
    -756,  -756,  -756,  1352,   307,  2530,  -756,  -756,   265,  1352,
    -756,  -756,  -756,  1352,  1352,  1352,  1352,  1352,  1352,  1352,
    1352,  1352,  1352,  1352,  1352,  1352,  -756,   716,   690,  1352,
    1352,  1352,  1352,  1352,  1352,  1352,  1352,  1352,  1352,  1352,
    1352,  1352,  1352,  1352,  1352,  1352,  1352,  1352,  1352,  1352,
    1352,  -756,   690,  1352,  1352,  1352,  1352,  1352,  1352,  -756,
    1352,  1352,  1352,  1352,  1352,  1352,  1352,  1352,  1352,  1352,
    1352,  1352,  1352,   519,  1352,  1352,  1352,  1352,  1352,  1352,
    1352,  1352,  1352,  1352,  1352,  1352,  1352,  1352,  1352,  1352,
    1352,  1352,  1352,  1352,  1352,  1352,  1352,  1352,  1352,  1352,
    1352,  1352,  1352,  1352,  1352,  1352,  1352,  1352,  1352,  1352,
    1352,  1352,  1352,  1352,  1352,  1352,   250,  -756,  -756,   254,
      44,   322,  -756,   690,   332,  -756,  -756,  -756,  1352,  1352,
    -756,  -756,  -756,  -756,   128,   327,  -756,    95,  1670,  1367,
     519,   519,   519,   519,   519,   179,   179,   179,   179,   179,
     519,   519,   519,   519,   519,   519,  2741,  2769,   869,   771,
    1192,   283,   283,  1192,   519,   519,   519,   519,   519,   519,
    1192,   519,   519,   519,   519,   519,   519,  1192,  1192,  1192,
    1192,  1192,  1192,  1192,  1192,  1192,  1192,  1192,  1192,  1192,
    1721,  -756,   179,   179,   179,   179,   179,  1352,   -40,   303,
    1352,   250,  2364,   368,  2803,  2923,   953,   224,  -756,  -756,
    -756,  -756,   369,    10,   278,   420,    82,  -756,   336,   416,
     198,  2803,  -756,    93,   198,  -756,   425,  2560,  -756,  2014,
     428,   436,  -756,  2139,  -756,  -756,  -756,  -756,  -756,  -756,
    -756,  -756,  -756,  -756,  -756,  -756,  -756,   437,   410,   146,
     632,     4,   698,   819,   632,     4,   698,   819,   117,   442,
     435,   440,   117,   435,   440,   117,   435,   440,   117,   440,
    2627,   375,   482,  2854,  1582,  1077,   507,  2685,   517,  2656,
     480,  1433,   455,  1402,  2934,  1897,  2900,  2030,  2274,   454,
    1187,   454,  1187,  1557,   400,  -756,  -756,  1608,  1633,   422,
    -756,  1557,   400,  -756,  -756,  1608,  1633,   422,  -756,   345,
    2080,  1210,   453,   345,  2080,  1210,   453,   345,  2080,  1210,
     453,   345,  2080,  1210,   453,   198,   155,   632,     4,   632,
       4,   117,   442,  1433,   696,  1557,   400,  1557,   400,  2627,
     375,   482,  2854,  1582,  1077,   507,  1433,   696,  1557,  -756,
    1557,  -756,  2627,   375,   482,  2854,  1582,  1077,   507,  1433,
     696,  1557,  -756,  1557,  -756,   632,   698,   819,   632,   698,
     819,   117,   435,   440,   117,   435,   440,   117,   435,   440,
    1298,   448,  2627,   375,   482,  2854,  1582,  1077,   507,  1433,
     696,  1402,  2934,  1897,  2900,  2030,  2274,   454,  1187,   454,
    1187,  1557,  1608,  1633,  1557,  1608,  1633,   345,  2080,  1210,
     345,  2080,  1210,   345,  2080,  1210,   345,  2080,  1210,   632,
     698,   819,   632,   698,   819,   117,   435,   440,   117,   435,
     440,   117,   435,   440,   117,   435,   440,  2627,   375,   482,
    2854,  1582,  1077,   507,  1433,   696,  1557,  1608,  1633,  1557,
    1608,  1633,   345,  2080,  1210,   345,  2080,  1210,   345,  2080,
    1210,   345,  2080,  1210,   474,  2627,   375,   482,  2854,  1582,
    1077,   507,  1433,   696,   455,  1557,   422,  1557,   422,   345,
     453,   345,   453,   345,   453,   345,   453,  2627,   375,   482,
    2854,  1582,  1077,   507,  2685,   517,  2656,   480,  1433,   696,
    1557,  -756,  1557,  -756,  -756,  -756,    54,   496,    22,   862,
     371,   194,  -756,   499,   472,   510,  -756,  -756,  1352,  -756,
     845,   952,   845,   952,   435,   448,   435,   448,   435,   448,
    1020,  1676,   978,  1037,  1037,   845,   952,   845,   952,   435,
     448,   435,   448,   435,   448,   435,   448,   318,  2877,  2957,
    1149,   647,   511,  -756,  -756,   318,  2877,  2957,  1149,   647,
    2124,  1542,  2124,  1542,  2124,  1542,  2124,  1542,  2124,  1542,
    2124,  1542,   318,  2877,  2957,  1149,   647,  2124,  1542,  2124,
    1542,  2124,  1542,  2124,  1542,  2124,  1542,  2124,  1542,   318,
    2877,  2957,  1149,   647,  1756,   809,  1060,  1060,  -756,  -756,
    -756,  -756,   318,  2877,  2957,  1149,   647,   340,   246,  -756,
    -756,   566,   566,  -756,  -756,  -756,  -756,  -756,  1352,  -756,
    -756,   250,   168,   168,  -756,   451,   513,   533,    13,   274,
      45,   501,    16,  -756,  1018,   219,    -7,   492,   504,  -756,
    -756,  2457,  2427,   540,  1352,  2457,  -756,  1352,  -756,  -756,
    -756,  -756,   634,  -756,  -756,   274,    49,  -756,  -756,  1352,
    -756,  -756,   183,   555,  -756,   558,  -756,   531,  -756,   168,
     537,  -756,   274,   634,   634,   538,  -756,   563,  -756,  1055,
    -756,  1164,   221,  1352,  -756,   596,  -756,   592,   545,  -756,
    -756,  -756,   274,   597,  2457,  -756,  1352,  -756,  1352,  -756,
      18,   501,    19,  1352,  -756,  -756,   594,  -756,   599,  -756,
    1236,   572,  -756,  -756,  -756,  -756,  2457,  -756,  -756,  -756,
    -756,  -756,  -756,  -756,  -756,   538,  -756,  -756,  -756,  -756,
     602,   576,  -756,  -756,  -756
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     9,   314,   328,   349,   376,   306,     0,     0,
       0,     0,     0,     0,     0,    48,     0,    42,    44,    38,
      35,    36,     0,   443,   444,   445,   446,     0,     0,    99,
     100,     0,     0,     4,    10,     0,     0,    37,    15,    17,
       0,    18,     0,    16,     0,    19,    20,     0,     0,     0,
       0,    92,   286,    91,   287,    93,    94,    95,    96,    97,
      98,   448,   449,     0,   306,    99,   293,   286,     0,   287,
       0,     0,     0,   292,     0,     0,     0,     0,   278,    99,
     283,     0,     0,     0,   101,   102,   315,   329,     0,     0,
       0,     0,     0,   378,     0,     0,   317,     0,    33,    32,
       0,    39,     0,     0,   436,   421,   437,   422,   438,   423,
     439,   424,     0,    64,     0,     0,     0,     0,   440,   112,
     308,   420,     0,     0,   113,     1,     3,     0,     5,     8,
       7,    14,    21,     0,     0,     0,    30,    31,     0,     0,
      12,    13,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,     0,     0,     0,     0,     0,     0,     0,   111,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   441,   425,   442,     0,
      70,     0,   307,     0,   308,   103,   288,   289,     0,     0,
     316,   330,   350,   377,     0,     0,   279,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   315,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   432,   293,     0,   292,     0,     0,     0,   427,   428,
     429,   430,     0,     0,     0,     0,     0,   310,     0,     0,
     115,     0,   426,     0,   116,     6,     0,     0,    23,     0,
       0,     0,    88,    87,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,   104,     0,    89,     0,
     146,   144,   141,   142,   154,   152,   149,   150,   128,   127,
     123,   124,   133,   131,   132,   138,   136,   137,   120,   119,
     277,   275,   276,   271,   272,   273,   274,   250,   249,   253,
     252,   247,   246,   225,   224,   231,   230,   228,   227,   157,
     156,   160,   159,   205,   203,   200,   201,   196,   197,   198,
     199,   222,   220,   217,   218,   213,   214,   215,   216,   167,
     164,   165,   166,   181,   178,   179,   180,   174,   171,   172,
     173,   188,   185,   186,   187,   117,     0,   145,   143,   153,
     151,   126,   125,   245,   238,   204,   202,   221,   219,   269,
     375,   258,   372,   373,   371,   374,   243,   236,   193,   387,
     210,   394,   270,   263,   264,   259,   260,   261,   262,   244,
     237,   195,   194,   212,   211,   139,   322,   348,   147,   321,
     345,   121,   318,   336,   129,   319,   339,   134,   320,   342,
       0,   333,   265,   360,   254,   357,   358,   356,   359,   239,
     232,   223,   325,   229,   327,   226,   326,   155,   323,   158,
     324,   189,   382,   383,   206,   389,   390,   161,   395,   396,
     175,   400,   401,   168,   405,   406,   182,   410,   411,   140,
     347,   346,   148,   344,   343,   122,   335,   334,   130,   338,
     337,   135,   341,   340,   118,   332,   331,   266,   365,   255,
     362,   363,   361,   364,   240,   233,   190,   385,   384,   207,
     392,   391,   162,   398,   397,   176,   403,   402,   169,   408,
     407,   183,   413,   412,     0,   267,   355,   256,   352,   353,
     351,   354,   241,   234,   415,   191,   386,   208,   393,   163,
     399,   177,   404,   170,   409,   184,   414,   268,   370,   257,
     367,   368,   366,   369,   248,   380,   251,   379,   242,   235,
     192,   381,   209,   388,   431,   417,   447,     0,   418,     0,
       0,     0,   309,     0,     0,     0,   280,   281,     0,   284,
     322,   348,   321,   345,   318,   336,   319,   339,   320,   342,
     325,   327,   326,   323,   324,   347,   346,   344,   343,   335,
     334,   338,   337,   341,   340,   332,   331,   375,   372,   373,
     371,   374,     0,   387,   394,   360,   357,   358,   356,   359,
     382,   383,   389,   390,   395,   396,   400,   401,   405,   406,
     410,   411,   365,   362,   363,   361,   364,   385,   384,   392,
     391,   398,   397,   403,   402,   408,   407,   413,   412,   355,
     352,   353,   351,   354,   415,     0,   386,   393,   399,   404,
     409,   414,   370,   367,   368,   366,   369,   380,   379,   381,
     388,   322,   321,   318,   319,   320,    74,    34,     0,    73,
     434,   433,     0,    53,    50,     0,     0,     0,     0,     0,
       0,    66,     0,   294,     0,     0,   108,     0,     0,   311,
     109,     0,     0,    24,     0,     0,   105,     0,   110,   107,
     106,   416,     0,    72,    71,     0,     0,   108,   290,     0,
     282,   285,     0,     0,   435,     0,    54,     0,    51,    55,
      57,    62,     0,     0,     0,    65,   298,     0,   296,     0,
     295,     0,     0,     0,    41,    25,    26,     0,    47,    90,
     419,    60,     0,     0,     0,    52,     0,    56,     0,    63,
       0,    69,     0,     0,   301,   300,     0,   299,     0,   297,
       0,   312,    27,    43,    49,    45,     0,    61,   291,    28,
      29,    40,    59,    58,    67,     0,    68,   304,   303,   302,
       0,     0,    46,   305,   313
  };

  const short
   Parser ::yypgoto_[] =
  {
    -756,  -756,  -123,   319,   -30,   -41,  -752,  -756,  -755,  -756,
     291,  -756,  -756,  -756,  -756,  -756,  -756,  -756,  -756,  -756,
    -756,  -756,  -756,  -723,  -756,  -756,   567,   -14,  -175,  -756,
    -756,   488,  -143,   777,  1638,   627,   559,  1147,   630,   423,
     938,   808,  1346,   -62,  -219,  2043,     0,   244,   443,  -756,
    -138,  -756,    12,  -235
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    31,    32,   131,    33,    34,   137,   851,   138,    35,
      99,    36,    37,    38,    39,    40,    41,    42,    43,   845,
      44,   846,    45,   756,   757,    46,   114,   760,   761,    47,
      48,    49,   377,    50,    51,    52,    81,    68,    54,    70,
     181,    71,    72,   120,   349,    57,   335,   336,   337,    61,
     637,    62,   121,    63
  };

  const short
   Parser ::yytable_[] =
  {
      58,   136,   128,   254,   103,   103,   249,   801,    74,    58,
      87,    91,   359,   753,   638,   182,   814,   265,   103,    58,
     818,   185,   249,    97,   754,   249,   266,   249,   249,   795,
     796,   249,    58,   821,    98,   105,   107,   109,   111,   103,
     103,   100,    58,    77,     3,     4,     5,     6,     7,     8,
     829,     9,    78,   -64,   267,   802,    10,   103,   342,   822,
    -433,   104,   782,   102,    11,   103,   755,  -433,   343,    12,
     847,   250,   850,   247,   106,   112,   827,    58,    23,    24,
      25,    26,   269,    87,   636,   803,   639,   800,   287,   803,
     805,   862,   854,   855,   766,   108,   110,   355,   648,     3,
       4,     5,     6,     7,     8,   770,     9,   113,   758,   762,
     115,    10,   116,   246,    79,    30,   338,   347,   339,    11,
     340,   118,   341,   767,    12,   125,   157,    58,   158,   129,
     352,   645,   130,    58,   767,    58,   133,   164,   117,    58,
     646,   139,   348,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,   180,    58,   778,   383,
     387,   391,   394,   397,   399,   404,   118,   779,   267,    79,
      30,   753,   248,  -447,   428,   436,   441,   445,   449,   453,
       3,     4,   253,     3,   116,    82,   327,   767,    94,   258,
     473,   259,    83,   252,   486,    95,   767,   256,   497,   500,
     503,   506,   509,   511,   516,    12,   787,   157,    12,   158,
     117,   533,   536,   539,   542,   545,   548,   551,   554,   557,
     560,   563,   566,   571,   755,   578,   581,   584,   587,   590,
     593,   808,   599,   839,   772,   767,    23,    24,    25,    26,
     621,   122,   636,   328,    59,   240,   241,   242,   257,   243,
      84,    85,    75,    59,   290,    92,   244,   245,   634,   329,
     809,   103,   840,    59,   635,   291,   292,    58,   316,   123,
     651,   653,   655,   657,   659,   344,    59,   134,   318,   319,
     666,   668,   670,   672,   674,   676,    59,   135,   759,   330,
     679,     7,   682,   687,   691,   693,   695,   697,   699,   701,
     704,   708,   710,   712,   714,   716,   718,   721,    91,    91,
      91,    91,    91,    91,    91,   734,    91,    91,    91,    91,
     357,    59,    23,    24,    25,    26,   360,    58,   636,   128,
      58,   640,   288,     3,     4,     5,     6,     7,     8,   647,
       9,   331,   642,   750,   748,    10,    23,    24,    25,    26,
     291,   292,   636,    11,   157,   132,   158,    58,    12,    58,
     159,   160,   161,   162,   163,   164,   140,   141,   142,   156,
     345,    59,   318,   319,   190,   172,   173,    59,   191,    59,
     751,   785,   752,    59,   180,   192,   193,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
     191,    59,   194,    79,    30,   762,   195,   192,   193,   405,
     768,   182,   412,   196,   197,   183,   184,   185,   429,   437,
     442,   446,   450,   454,     3,     4,     5,     6,     7,     8,
     769,     9,   763,   231,   474,   771,    10,   774,   487,    23,
      24,    25,    26,    60,    11,   636,   775,   776,   517,    12,
     777,    76,    60,   182,    93,   203,   236,   237,   238,   239,
     222,   764,    60,   157,   231,   158,   231,   572,   285,   159,
     160,   161,   162,   163,   164,    60,   600,   604,   606,   608,
     610,   612,   614,   616,   622,    60,   780,   234,   235,   236,
     237,   238,   239,   180,    79,    30,     3,     4,     5,     6,
       7,     8,   241,     9,   810,   243,   781,   195,    10,   788,
     789,    59,   244,   245,   196,   197,    11,   758,   758,   792,
      60,    12,   790,     3,     4,   797,   333,   798,    82,   241,
     242,   289,   243,   811,   680,    83,   799,   688,   346,   244,
     245,   804,   243,   816,   705,   353,   813,   638,    12,   244,
     245,   722,   724,   726,   727,   728,   729,   730,   731,   735,
      92,    92,    92,    92,   758,   824,    79,    30,   830,   832,
      60,    59,   825,   826,    59,   834,    60,   784,    60,   828,
     833,   379,    60,   324,   325,   326,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,   842,
      60,    59,   843,    59,   844,   456,   857,   848,   406,   408,
     410,   858,   861,   129,   863,   348,   130,   430,   438,   747,
       3,     4,     5,     6,     7,     8,   786,     9,   331,   831,
     251,   362,    10,   475,   819,    67,   264,   488,    69,    58,
      11,   157,   864,   158,   820,    12,     0,   518,    58,   161,
     162,   163,   164,     0,   594,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   573,   154,   155,   316,
     317,   180,     0,     0,     0,   601,   641,     0,     0,   318,
     319,   643,   644,   623,   625,   627,     0,   631,   633,     0,
      79,    30,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     9,    23,    24,    25,    26,    10,   182,   636,     0,
      60,   183,   184,   185,    11,   200,   201,   202,   203,    12,
       3,     4,     5,     6,     7,     8,   376,     9,   187,   188,
     136,   345,    10,   681,   136,     0,   689,     0,     0,     0,
      11,     0,   128,   706,     0,    12,     0,     0,    58,     0,
     723,   725,   725,   725,   725,   725,   725,   725,   736,   737,
     738,   739,   740,   794,    79,    30,     0,     0,   765,     0,
      60,    58,    58,    60,    58,    58,     0,    58,   794,     0,
       0,   263,     0,   849,     0,     0,    80,     0,     0,     0,
      79,    30,   315,   316,   317,     0,   101,     0,     0,   263,
      60,     0,    60,   318,   319,   136,     0,     0,    55,     0,
     240,   241,   242,    58,   243,     0,     0,    55,     0,    89,
       0,   244,   245,     0,    58,     0,    58,    55,    58,     0,
     315,   316,   317,    58,   262,   231,   219,   220,   221,   222,
      55,   318,   319,     0,     0,   232,    58,     0,     0,   233,
      55,     0,     0,     0,    80,     0,   234,   235,   236,   237,
     238,   239,   272,   273,   274,   203,     3,     4,     5,     6,
       7,     8,     0,     9,     0,   116,     0,     0,    10,   262,
       0,     0,     0,    59,     0,    55,    11,     0,     0,     0,
     307,    12,    59,   182,   308,     0,    89,   183,   184,   185,
       0,   309,   310,   311,   312,   313,   314,   186,     0,     0,
     356,     0,     0,     0,   187,   188,   361,     0,     0,     0,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,     0,   378,    55,    79,    30,     0,     0,
       0,    55,     0,    55,     0,     0,     0,    55,     0,     0,
       0,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,   231,    55,     0,   119,   124,   282,
     283,   284,   285,   401,   232,     0,     0,     0,   233,     0,
       0,     0,   425,   433,     0,   234,   235,   236,   237,   238,
     239,   189,    59,   322,   323,   324,   325,   326,   470,     0,
     479,   481,   483,   119,   275,     0,   189,     0,   278,   279,
       0,     0,   513,     0,     0,    59,    59,   119,    59,    59,
       0,    59,     3,     4,     5,     6,     7,     8,     0,     9,
     806,   568,     0,     0,    10,   322,   323,   324,   325,   326,
     596,     0,    11,     0,   649,     0,     0,    12,   618,     0,
     278,   279,   322,   323,   324,   325,   326,    59,     0,     3,
       4,     5,     6,     7,     8,     0,     9,   835,    59,     0,
      59,    10,    59,     0,     0,    55,     0,    59,     0,    11,
       0,     0,    60,     0,    12,     0,     0,     0,   231,     0,
      59,    60,    79,    30,   311,   312,   313,   314,   677,   683,
     684,   685,   233,     0,   746,     0,     0,   749,   702,   234,
     235,   236,   237,   238,   239,   719,    89,    89,    89,    89,
      89,    89,    89,   732,    89,    89,    89,    89,     0,    79,
      30,     0,     0,     0,     0,    55,     0,     0,    55,     3,
       4,     5,     6,    64,     8,     0,     9,    53,     0,     0,
       0,    10,     0,     0,     0,     0,    53,     0,     0,    11,
       0,     0,     0,     0,    12,    55,    53,    55,     3,     4,
       5,     6,     7,     8,   308,     9,   837,     0,     0,    53,
      10,   309,   310,   311,   312,   313,   314,   807,    11,    53,
     812,    60,     0,    12,     0,     0,     3,     4,     5,     6,
       7,    88,   198,   199,   200,   201,   202,   203,    83,    65,
      30,     0,   823,     0,    60,    60,    11,    60,    60,     0,
      60,    12,     0,     0,    53,   217,   218,   219,   220,   221,
     222,     0,   836,     0,   838,     0,     0,     0,    79,    30,
       3,     4,     5,     6,     7,     8,     0,     9,   859,     0,
       0,     0,    10,     0,     0,     0,    60,     0,     0,     0,
      11,     0,     0,   860,     0,    12,     0,    60,     0,    60,
       0,    60,     0,     0,    53,     0,    60,     0,     0,     0,
      53,     0,    53,     0,     0,     0,    53,     0,     0,    60,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,     0,    53,     0,   381,   385,   389,     0,
      79,    30,     0,   270,   271,   272,   273,   274,   203,   189,
       0,   424,   432,   189,   275,   276,   277,   189,   278,   279,
     458,   460,   462,   464,   466,   468,     0,     0,   477,     0,
       0,     0,   490,     0,     0,     0,    56,     0,     0,     0,
       0,     0,   520,     0,     0,    56,     3,     4,     5,     6,
       7,     8,   189,     9,     0,    56,     0,     0,    10,     0,
     189,   575,     0,     0,     0,     0,    11,   261,    56,     0,
     603,    12,   280,   281,   282,   283,   284,   285,    56,     0,
     629,     0,     0,     0,     0,     0,   189,     0,   189,     0,
     189,     0,   189,     0,   189,     0,   189,     0,     0,     0,
       0,   157,     0,   158,    53,   189,   783,   159,   160,   161,
     162,   163,   164,    56,     0,   791,    79,    30,   189,     0,
       0,     0,   172,   173,   174,   175,   176,   177,   178,   179,
       0,   180,   157,     0,   158,     0,     0,    55,   159,   160,
     161,   162,   163,   164,     0,     0,    55,     0,   189,   169,
     170,   171,     0,   172,   173,   174,   175,   176,   177,   178,
     179,     0,   180,    56,    53,     0,     0,    53,     0,    56,
       0,    56,     0,     0,     0,    56,     0,     0,     0,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,     0,    56,    53,     0,    53,     0,     0,     0,
       0,   402,     0,   189,     3,     4,     5,     6,    64,    88,
     426,   434,   261,     0,     0,   793,    83,   217,   218,   219,
     220,   221,   222,   223,    11,     0,   471,   224,     0,    12,
     484,   189,   492,   494,   225,   226,   227,   228,   229,   230,
     514,   817,     0,     0,   378,     0,    55,   280,   281,   282,
     283,   284,   285,     0,     0,     0,   157,   189,   158,   569,
       0,     0,   159,   160,   161,   162,   163,   164,   597,    55,
      55,     0,    55,    55,     0,    55,   619,   172,   173,     0,
     841,   176,   177,   178,   179,     0,   180,   217,   218,   219,
     220,   221,   222,   852,     0,   853,     0,   224,     0,     0,
     856,     0,     0,    56,   225,   226,   227,   228,   229,   230,
       0,    55,     0,   198,   199,   200,   201,   202,   203,     0,
       0,     0,    55,     0,    55,     0,    55,     0,   209,   210,
       0,    55,   213,   214,   215,   216,    66,     0,   217,   218,
     219,   220,   221,   222,    55,   126,   127,     0,     2,     3,
       4,     5,     6,     7,     8,     0,     9,   227,   228,   229,
     230,    10,     0,    56,     0,     0,    56,     0,     0,    11,
     260,     0,     0,     0,    12,   270,   271,   272,   273,   274,
     203,   322,   323,   324,   325,   326,   275,   276,   277,     0,
     278,   279,   275,    56,   277,    56,   278,   279,     0,     0,
       0,    13,    14,    15,     0,    16,    17,    18,    19,    20,
      21,    22,     0,    23,    24,    25,    26,    27,    28,    29,
      30,   260,     0,     0,     0,     0,   322,   323,   324,   325,
     326,   332,     0,     0,     0,     0,     0,   275,   276,   277,
       0,   278,   279,   332,     0,   350,     0,   157,   255,   158,
     332,   354,     0,   159,   160,   161,   162,   163,   164,   165,
     166,   167,     0,   168,   169,   170,   171,     0,   172,   173,
     174,   175,   176,   177,   178,   179,    53,   180,   309,   310,
     311,   312,   313,   314,     0,    53,   332,   380,   384,   388,
     392,   395,   398,   400,   407,   409,   411,   413,   415,   417,
     419,   421,   423,   431,   439,   443,   447,   451,   455,     0,
     332,   457,   459,   461,   463,   465,   467,     0,   469,   476,
     478,   480,   482,   489,   491,   493,   495,   498,   501,   504,
     507,     0,   512,   519,   521,   523,   525,   527,   529,   531,
     534,   537,   540,   543,   546,   549,   552,   555,   558,   561,
     564,   567,   574,   576,   579,   582,   585,   588,   591,   332,
     595,   602,   605,   607,   609,   611,   613,   615,   617,   624,
     626,   628,   630,   632,     0,     0,     0,     0,   307,     0,
       0,   332,   308,     0,     0,    53,   332,   332,     0,   309,
     310,   311,   312,   313,   314,     0,   157,     0,   158,     0,
       0,     0,   159,   160,   161,   162,   163,   164,    53,    53,
       0,    53,    53,   169,    53,   171,     0,   172,   173,   174,
     175,   176,   177,   178,   179,     0,   180,     0,     0,     1,
       0,     0,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,     0,     0,    10,     0,     0,     0,     0,
      53,     0,     0,    11,     0,     0,     0,     0,    12,     0,
       0,    53,     0,    53,     0,    53,     0,     0,     0,     0,
      53,     0,     0,   332,     0,    56,     0,     0,     0,     0,
       0,     0,     0,    53,    56,    13,    14,    15,     0,    16,
      17,    18,    19,    20,    21,    22,     0,    23,    24,    25,
      26,    27,    28,    29,    30,   127,     0,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,   773,     0,
      10,     0,     0,     0,     0,     0,     0,     0,    11,   157,
       0,   158,     0,    12,     0,   159,   160,   161,   162,   163,
     164,    73,     0,    86,    90,    96,   169,     0,     0,     0,
     172,   173,   174,   175,   176,   177,   178,   179,     0,   180,
      13,    14,    15,     0,    16,    17,    18,    19,    20,    21,
      22,     0,    23,    24,    25,    26,    27,    28,    29,    30,
       0,     0,     0,     0,    56,   198,   199,   200,   201,   202,
     203,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     209,   210,     0,     0,     0,     0,     0,    56,    56,     0,
      56,    56,     0,    56,     0,   268,    86,     0,     0,     0,
       0,   286,     0,     0,     0,     0,     0,   320,   321,   270,
     271,   272,   273,   274,   203,     0,   334,     0,     0,     0,
       0,     0,     0,     0,   278,   279,     0,     0,   334,    56,
     351,     0,     0,     0,     0,   334,   351,     0,     0,     0,
      56,     0,    56,     0,    56,     0,     0,     0,     0,    56,
       0,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    56,   154,   155,     0,     0,     0,     0,     0,
       0,   334,   382,   386,   390,   393,   396,   351,   403,   351,
     351,   351,   414,   416,   418,   420,   422,   427,   435,   440,
     444,   448,   452,   351,     0,   334,   351,   351,   351,   351,
     351,   351,     0,   472,   351,   351,   351,   485,   351,   351,
     351,   496,   499,   502,   505,   508,   510,   515,   351,   522,
     524,   526,   528,   530,   532,   535,   538,   541,   544,   547,
     550,   553,   556,   559,   562,   565,   570,   351,   577,   580,
     583,   586,   589,   592,   334,   598,   351,   351,   351,   351,
     351,   351,   351,   620,   351,   351,   351,   351,   351,   198,
     199,   200,   201,   202,   203,     0,   334,     0,     0,     0,
     206,   334,   334,     0,   209,   210,   211,   212,   213,   214,
     215,   216,     0,   650,   652,   654,   656,   658,   660,   661,
     662,   663,   664,   665,   667,   669,   671,   673,   675,     0,
       0,     0,     0,   678,     0,     0,   686,   690,   692,   694,
     696,   698,   700,   703,   707,   709,   711,   713,   715,   717,
     720,    90,    90,    90,    90,    90,    90,    90,   733,    90,
      90,    90,    90,     0,     0,   741,   742,   743,   744,   745,
       0,     0,     0,   157,     0,   158,     0,     0,     0,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   334,   168,
     169,   170,   171,     0,   172,   173,   174,   175,   176,   177,
     178,   179,   332,   180,     0,   332,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   332,   127,     0,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,   815,     0,    10,     0,     0,     0,   332,     0,   332,
       0,    11,     0,     0,     0,     0,    12,     0,     0,     0,
     134,     3,     4,     5,     6,     7,     8,     0,     9,     0,
     135,     0,     0,    10,     0,     0,     0,     0,   332,     0,
       0,    11,     0,    13,    14,    15,    12,    16,    17,    18,
      19,    20,    21,    22,     0,    23,    24,    25,    26,    27,
      28,    29,    30,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    14,    15,     0,    16,    17,    18,
      19,    20,    21,    22,     0,    23,    24,    25,    26,    27,
      28,    29,    30,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,   358,     0,    10,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,     0,     0,    12,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,     0,     0,    10,     0,     0,     0,
       0,     0,     0,     0,    11,     0,    13,    14,    15,    12,
      16,    17,    18,    19,    20,    21,    22,     0,    23,    24,
      25,    26,    27,    28,    29,    30,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,    14,    15,     0,
      16,    17,    18,    19,    20,    21,    22,     0,    23,    24,
      25,    26,    27,    28,    29,    30,   157,     0,   158,     0,
       0,     0,   159,   160,   161,   162,   163,   164,     0,   166,
     167,     0,   168,   169,   170,   171,     0,   172,   173,   174,
     175,   176,   177,   178,   179,   157,   180,   158,     0,     0,
       0,   159,   160,   161,   162,   163,   164,     0,   166,     0,
       0,   168,   169,   170,   171,     0,   172,   173,   174,   175,
     176,   177,   178,   179,   157,   180,   158,     0,     0,     0,
     159,   160,   161,   162,   163,   164,     0,     0,     0,     0,
     168,   169,   170,   171,     0,   172,   173,   174,   175,   176,
     177,   178,   179,   260,   180,     0,     0,     0,   198,   199,
     200,   201,   202,   203,   204,     0,     0,     0,   205,   206,
     207,   208,     0,   209,   210,   211,   212,   213,   214,   215,
     216,   260,     0,     0,     0,     0,   270,   271,   272,   273,
     274,   203,   293,     0,     0,     0,     0,   275,   276,   277,
       0,   278,   279,   294,   295,   296,   297,   298,   299,   261,
       0,     0,     0,     0,   280,   281,   282,   283,   284,   285,
     300,     0,     0,     0,   280,   281,   282,   283,   284,   285,
     300,   301,   302,   303,   304,   305,   306,   334,     0,     0,
     334,   301,   302,   303,   304,   305,   306,     0,   198,   199,
     200,   201,   202,   203,   204,     0,     0,     0,   205,   206,
     207,   208,   334,   209,   210,   211,   212,   213,   214,   215,
     216,     0,     0,     0,   270,   271,   272,   273,   274,   203,
     293,     0,   334,     0,   334,   275,   276,   277,     0,   278,
     279,   294,   295,   296,   297,   298,   299,     0,     0,   198,
     199,   200,   201,   202,   203,     0,     0,     0,     0,   205,
     206,   207,   208,   334,   209,   210,   211,   212,   213,   214,
     215,   216,   270,   271,   272,   273,   274,   203,     0,     0,
       0,     0,     0,   275,   276,   277,     0,   278,   279,   294,
     295,   296,   297,   298,   299,   198,   199,   200,   201,   202,
     203,     0,     0,     0,     0,     0,   206,     0,   208,     0,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,     0,     0,     0,   224,   198,
     199,   200,   201,   202,   203,   225,   226,   227,   228,   229,
     230,     0,     0,     0,   209,   210,   211,   212,   213,   214,
     215,   216,   280,   281,   282,   283,   284,   285,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   301,
     302,   303,   304,   305,   306
  };

  const short
   Parser ::yycheck_[] =
  {
       0,    42,    32,    65,    11,    11,     9,   759,     8,     9,
      10,    11,   135,     3,   249,    11,   771,     3,    11,    19,
     775,    17,     9,    74,    14,     9,    12,     9,     9,   752,
     753,     9,    32,   785,    74,    23,    24,    25,    26,    11,
      11,     9,    42,     3,     4,     5,     6,     7,     8,     9,
     802,    11,    12,     9,    40,    10,    16,    11,     3,    10,
      67,    67,    40,    74,    24,    11,    56,    74,    13,    29,
     822,    74,   824,    61,    67,    74,   799,    77,    68,    69,
      70,    71,    82,    83,    74,    40,    42,    74,    88,    40,
      74,   846,    74,    74,    12,    67,    67,   127,     3,     4,
       5,     6,     7,     8,     9,    12,    11,    74,   343,   344,
      11,    16,    13,    67,    74,    75,   104,    14,   106,    24,
     108,    67,   110,    41,    29,     0,     9,   127,    11,     0,
     118,     3,     3,   133,    41,   135,     9,    20,    39,   139,
      12,     9,    39,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    39,   157,    12,   159,
     160,   161,   162,   163,   164,   165,    67,    12,    40,    74,
      75,     3,    67,    74,   174,   175,   176,   177,   178,   179,
       4,     5,    11,     4,    13,     9,    42,    41,     9,    38,
     190,    40,    16,    10,   194,    16,    41,    10,   198,   199,
     200,   201,   202,   203,   204,    29,    12,     9,    29,    11,
      39,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,    56,   225,   226,   227,   228,   229,
     230,    12,   232,    12,   357,    41,    68,    69,    70,    71,
     240,    11,    74,    40,     0,    21,    22,    23,    10,    25,
      74,    75,     8,     9,    21,    11,    32,    33,   246,    74,
      41,    11,    41,    19,    10,    32,    33,   267,    22,    39,
     270,   271,   272,   273,   274,     9,    32,     3,    32,    33,
     280,   281,   282,   283,   284,   285,    42,    13,    10,    42,
     290,     8,     9,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
      13,    77,    68,    69,    70,    71,    61,   327,    74,   359,
     330,     9,    88,     4,     5,     6,     7,     8,     9,    12,
      11,    12,    10,   331,    41,    16,    68,    69,    70,    71,
      32,    33,    74,    24,     9,    36,    11,   357,    29,   359,
      15,    16,    17,    18,    19,    20,    47,    48,    49,    50,
      41,   127,    32,    33,    21,    30,    31,   133,    25,   135,
      12,    10,    13,   139,    39,    32,    33,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
      25,   157,    21,    74,    75,   640,    25,    32,    33,   165,
      74,    11,   168,    32,    33,    15,    16,    17,   174,   175,
     176,   177,   178,   179,     4,     5,     6,     7,     8,     9,
      14,    11,    12,    11,   190,    10,    16,     9,   194,    68,
      69,    70,    71,     0,    24,    74,    10,    10,   204,    29,
      40,     8,     9,    11,    11,    20,    34,    35,    36,    37,
      20,    41,    19,     9,    11,    11,    11,   223,    20,    15,
      16,    17,    18,    19,    20,    32,   232,   233,   234,   235,
     236,   237,   238,   239,   240,    42,    12,    32,    33,    34,
      35,    36,    37,    39,    74,    75,     4,     5,     6,     7,
       8,     9,    22,    11,    12,    25,    10,    25,    16,    10,
      38,   267,    32,    33,    32,    33,    24,   752,   753,     8,
      77,    29,    12,     4,     5,    74,   103,    14,     9,    22,
      23,    88,    25,    41,   290,    16,     3,   293,   115,    32,
      33,    40,    25,     3,   300,   122,    42,   782,    29,    32,
      33,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   799,    10,    74,    75,   803,   804,
     127,   327,    14,    42,   330,    12,   133,   639,   135,    42,
      42,   158,   139,    17,    18,    19,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,     3,
     157,   357,    10,   359,    59,   182,    12,    10,   165,   166,
     167,    12,    40,     0,    12,    39,     3,   174,   175,   328,
       4,     5,     6,     7,     8,     9,   640,    11,    12,   804,
      63,   143,    16,   190,   777,     8,    77,   194,     8,   639,
      24,     9,   861,    11,   782,    29,    -1,   204,   648,    17,
      18,    19,    20,    -1,   231,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,   223,    54,    55,    22,
      23,    39,    -1,    -1,    -1,   232,   253,    -1,    -1,    32,
      33,   258,   259,   240,   241,   242,    -1,   244,   245,    -1,
      74,    75,    -1,    -1,     4,     5,     6,     7,     8,     9,
      -1,    11,    68,    69,    70,    71,    16,    11,    74,    -1,
     267,    15,    16,    17,    24,    17,    18,    19,    20,    29,
       4,     5,     6,     7,     8,     9,    10,    11,    32,    33,
     771,    41,    16,   290,   775,    -1,   293,    -1,    -1,    -1,
      24,    -1,   772,   300,    -1,    29,    -1,    -1,   748,    -1,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   751,    74,    75,    -1,    -1,   345,    -1,
     327,   771,   772,   330,   774,   775,    -1,   777,   766,    -1,
      -1,    10,    -1,   824,    -1,    -1,     9,    -1,    -1,    -1,
      74,    75,    21,    22,    23,    -1,    19,    -1,    -1,    10,
     357,    -1,   359,    32,    33,   846,    -1,    -1,     0,    -1,
      21,    22,    23,   813,    25,    -1,    -1,     9,    -1,    11,
      -1,    32,    33,    -1,   824,    -1,   826,    19,   828,    -1,
      21,    22,    23,   833,    10,    11,    17,    18,    19,    20,
      32,    32,    33,    -1,    -1,    21,   846,    -1,    -1,    25,
      42,    -1,    -1,    -1,    77,    -1,    32,    33,    34,    35,
      36,    37,    17,    18,    19,    20,     4,     5,     6,     7,
       8,     9,    -1,    11,    -1,    13,    -1,    -1,    16,    10,
      -1,    -1,    -1,   639,    -1,    77,    24,    -1,    -1,    -1,
      21,    29,   648,    11,    25,    -1,    88,    15,    16,    17,
      -1,    32,    33,    34,    35,    36,    37,    25,    -1,    -1,
     133,    -1,    -1,    -1,    32,    33,   139,    -1,    -1,    -1,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   127,    74,    75,    -1,    -1,
      -1,   133,    -1,   135,    -1,    -1,    -1,   139,    -1,    -1,
      -1,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    11,   157,    -1,    29,    30,    17,
      18,    19,    20,   165,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,   174,   175,    -1,    32,    33,    34,    35,    36,
      37,    53,   748,    15,    16,    17,    18,    19,   190,    -1,
     192,   193,   194,    65,    26,    -1,    68,    -1,    30,    31,
      -1,    -1,   204,    -1,    -1,   771,   772,    79,   774,   775,
      -1,   777,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,   223,    -1,    -1,    16,    15,    16,    17,    18,    19,
     232,    -1,    24,    -1,   267,    -1,    -1,    29,   240,    -1,
      30,    31,    15,    16,    17,    18,    19,   813,    -1,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,   824,    -1,
     826,    16,   828,    -1,    -1,   267,    -1,   833,    -1,    24,
      -1,    -1,   639,    -1,    29,    -1,    -1,    -1,    11,    -1,
     846,   648,    74,    75,    34,    35,    36,    37,   290,   291,
     292,   293,    25,    -1,   327,    -1,    -1,   330,   300,    32,
      33,    34,    35,    36,    37,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,    -1,    74,
      75,    -1,    -1,    -1,    -1,   327,    -1,    -1,   330,     4,
       5,     6,     7,     8,     9,    -1,    11,     0,    -1,    -1,
      -1,    16,    -1,    -1,    -1,    -1,     9,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    29,   357,    19,   359,     4,     5,
       6,     7,     8,     9,    25,    11,    12,    -1,    -1,    32,
      16,    32,    33,    34,    35,    36,    37,   764,    24,    42,
     767,   748,    -1,    29,    -1,    -1,     4,     5,     6,     7,
       8,     9,    15,    16,    17,    18,    19,    20,    16,    74,
      75,    -1,   789,    -1,   771,   772,    24,   774,   775,    -1,
     777,    29,    -1,    -1,    77,    15,    16,    17,    18,    19,
      20,    -1,   809,    -1,   811,    -1,    -1,    -1,    74,    75,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
      -1,    -1,    16,    -1,    -1,    -1,   813,    -1,    -1,    -1,
      24,    -1,    -1,   840,    -1,    29,    -1,   824,    -1,   826,
      -1,   828,    -1,    -1,   127,    -1,   833,    -1,    -1,    -1,
     133,    -1,   135,    -1,    -1,    -1,   139,    -1,    -1,   846,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,    -1,   159,   160,   161,    -1,
      74,    75,    -1,    15,    16,    17,    18,    19,    20,   381,
      -1,   174,   175,   385,    26,    27,    28,   389,    30,    31,
     183,   184,   185,   186,   187,   188,    -1,    -1,   191,    -1,
      -1,    -1,   195,    -1,    -1,    -1,     0,    -1,    -1,    -1,
      -1,    -1,   205,    -1,    -1,     9,     4,     5,     6,     7,
       8,     9,   424,    11,    -1,    19,    -1,    -1,    16,    -1,
     432,   224,    -1,    -1,    -1,    -1,    24,    10,    32,    -1,
     233,    29,    15,    16,    17,    18,    19,    20,    42,    -1,
     243,    -1,    -1,    -1,    -1,    -1,   458,    -1,   460,    -1,
     462,    -1,   464,    -1,   466,    -1,   468,    -1,    -1,    -1,
      -1,     9,    -1,    11,   267,   477,   639,    15,    16,    17,
      18,    19,    20,    77,    -1,   648,    74,    75,   490,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    39,     9,    -1,    11,    -1,    -1,   639,    15,    16,
      17,    18,    19,    20,    -1,    -1,   648,    -1,   520,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,   127,   327,    -1,    -1,   330,    -1,   133,
      -1,   135,    -1,    -1,    -1,   139,    -1,    -1,    -1,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    -1,   157,   357,    -1,   359,    -1,    -1,    -1,
      -1,   165,    -1,   575,     4,     5,     6,     7,     8,     9,
     174,   175,    10,    -1,    -1,   748,    16,    15,    16,    17,
      18,    19,    20,    21,    24,    -1,   190,    25,    -1,    29,
     194,   603,   196,   197,    32,    33,    34,    35,    36,    37,
     204,   774,    -1,    -1,   777,    -1,   748,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,     9,   629,    11,   223,
      -1,    -1,    15,    16,    17,    18,    19,    20,   232,   771,
     772,    -1,   774,   775,    -1,   777,   240,    30,    31,    -1,
     813,    34,    35,    36,    37,    -1,    39,    15,    16,    17,
      18,    19,    20,   826,    -1,   828,    -1,    25,    -1,    -1,
     833,    -1,    -1,   267,    32,    33,    34,    35,    36,    37,
      -1,   813,    -1,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,   824,    -1,   826,    -1,   828,    -1,    30,    31,
      -1,   833,    34,    35,    36,    37,     8,    -1,    15,    16,
      17,    18,    19,    20,   846,     0,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    34,    35,    36,
      37,    16,    -1,   327,    -1,    -1,   330,    -1,    -1,    24,
      10,    -1,    -1,    -1,    29,    15,    16,    17,    18,    19,
      20,    15,    16,    17,    18,    19,    26,    27,    28,    -1,
      30,    31,    26,   357,    28,   359,    30,    31,    -1,    -1,
      -1,    56,    57,    58,    -1,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    10,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      19,   103,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      -1,    30,    31,   115,    -1,   117,    -1,     9,    10,    11,
     122,   123,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    25,    26,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,   639,    39,    32,    33,
      34,    35,    36,    37,    -1,   648,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,    -1,
     182,   183,   184,   185,   186,   187,   188,    -1,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,    -1,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,    -1,    -1,    -1,    -1,    21,    -1,
      -1,   253,    25,    -1,    -1,   748,   258,   259,    -1,    32,
      33,    34,    35,    36,    37,    -1,     9,    -1,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,   771,   772,
      -1,   774,   775,    26,   777,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    39,    -1,    -1,     0,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,
     813,    -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    -1,
      -1,   824,    -1,   826,    -1,   828,    -1,    -1,    -1,    -1,
     833,    -1,    -1,   345,    -1,   639,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   846,   648,    56,    57,    58,    -1,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    -1,    -1,    14,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,     9,
      -1,    11,    -1,    29,    -1,    15,    16,    17,    18,    19,
      20,     8,    -1,    10,    11,    12,    26,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    39,
      56,    57,    58,    -1,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,   748,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,   771,   772,    -1,
     774,   775,    -1,   777,    -1,    82,    83,    -1,    -1,    -1,
      -1,    88,    -1,    -1,    -1,    -1,    -1,    94,    95,    15,
      16,    17,    18,    19,    20,    -1,   103,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,   115,   813,
     117,    -1,    -1,    -1,    -1,   122,   123,    -1,    -1,    -1,
     824,    -1,   826,    -1,   828,    -1,    -1,    -1,    -1,   833,
      -1,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,   846,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,    -1,   182,   183,   184,   185,   186,
     187,   188,    -1,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,    15,
      16,    17,    18,    19,    20,    -1,   253,    -1,    -1,    -1,
      26,   258,   259,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,    -1,
      -1,    -1,    -1,   290,    -1,    -1,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,    -1,    -1,   322,   323,   324,   325,   326,
      -1,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   345,    25,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,   764,    39,    -1,   767,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   789,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
      -1,    14,    -1,    16,    -1,    -1,    -1,   809,    -1,   811,
      -1,    24,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
      13,    -1,    -1,    16,    -1,    -1,    -1,    -1,   840,    -1,
      -1,    24,    -1,    56,    57,    58,    29,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    -1,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    -1,    14,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    56,    57,    58,    29,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,     9,    -1,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    -1,    25,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,     9,    39,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    -1,    22,    -1,
      -1,    25,    26,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,     9,    39,    11,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      25,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    10,    39,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    25,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    10,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    10,
      -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    32,    33,    34,    35,    36,    37,   764,    -1,    -1,
     767,    32,    33,    34,    35,    36,    37,    -1,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    25,    26,
      27,    28,   789,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    -1,   809,    -1,   811,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,   840,    30,    31,    32,    33,    34,    35,
      36,    37,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    25,    15,
      16,    17,    18,    19,    20,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    15,    16,    17,    18,    19,    20,    -1,    -1,
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
      42,    12,   111,   116,   122,   123,   124,   125,   129,   129,
     129,   129,     3,    13,     9,    41,   116,    14,    39,   121,
     111,   122,   129,   116,   111,    81,   110,    13,    14,    79,
      61,   110,   108,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,    10,   109,   110,   116,
     111,   114,   122,   123,   111,   114,   122,   123,   111,   114,
     122,   123,   111,   122,   123,   111,   122,   123,   111,   123,
     111,   118,   119,   122,   123,   124,   125,   111,   125,   111,
     125,   111,   124,   111,   122,   111,   122,   111,   122,   111,
     122,   111,   122,   111,   114,   118,   119,   122,   123,   124,
     125,   111,   114,   118,   119,   122,   123,   124,   125,   111,
     122,   123,   124,   111,   122,   123,   124,   111,   122,   123,
     124,   111,   122,   123,   124,   111,   116,   111,   114,   111,
     114,   111,   114,   111,   114,   111,   114,   111,   114,   111,
     118,   119,   122,   123,   124,   125,   111,   114,   111,   118,
     111,   118,   111,   118,   119,   122,   123,   124,   125,   111,
     114,   111,   119,   111,   119,   111,   122,   123,   111,   122,
     123,   111,   122,   123,   111,   122,   123,   111,   122,   123,
     122,   123,   111,   118,   119,   122,   123,   124,   125,   111,
     114,   111,   122,   111,   122,   111,   122,   111,   122,   111,
     122,   111,   122,   123,   111,   122,   123,   111,   122,   123,
     111,   122,   123,   111,   122,   123,   111,   122,   123,   111,
     122,   123,   111,   122,   123,   111,   122,   123,   111,   122,
     123,   111,   122,   123,   111,   122,   123,   111,   118,   119,
     122,   123,   124,   125,   111,   114,   111,   122,   123,   111,
     122,   123,   111,   122,   123,   111,   122,   123,   111,   122,
     123,   111,   122,   123,   116,   111,   118,   119,   122,   123,
     124,   125,   111,   114,   124,   111,   124,   111,   124,   111,
     124,   111,   124,   111,   124,   111,   124,   111,   118,   119,
     122,   123,   124,   125,   111,   125,   111,   125,   111,   114,
     111,   125,   111,   125,   129,    10,    74,   127,   130,    42,
       9,   116,    10,   116,   116,     3,    12,    12,     3,   110,
     122,   123,   122,   123,   122,   123,   122,   123,   122,   123,
     122,   122,   122,   122,   122,   122,   123,   122,   123,   122,
     123,   122,   123,   122,   123,   122,   123,   118,   122,   123,
     124,   125,     9,   118,   118,   118,   122,   123,   124,   125,
     122,   123,   122,   123,   122,   123,   122,   123,   122,   123,
     122,   123,   118,   122,   123,   124,   125,   122,   123,   122,
     123,   122,   123,   122,   123,   122,   123,   122,   123,   118,
     122,   123,   124,   125,   124,   125,   124,   124,   124,   124,
     124,   124,   118,   122,   123,   124,   125,   125,   125,   125,
     125,   122,   122,   122,   122,   122,   110,    87,    41,   110,
     129,    12,    13,     3,    14,    56,   100,   101,   130,    10,
     104,   105,   130,    12,    41,   116,    12,    41,    74,    14,
      12,    10,    79,    14,     9,    10,    10,    40,    12,    12,
      12,    10,    40,   110,   120,    10,   104,    12,    10,    38,
      12,   110,     8,   110,   129,   100,   100,    74,    14,     3,
      74,    83,    10,    40,    40,    74,    12,   116,    12,    41,
      12,    41,   116,    42,    85,    14,     3,   110,    85,   109,
     127,    83,    10,   116,    10,    14,    42,   100,    42,    83,
     130,   105,   130,    42,    12,    12,   116,    12,   116,    12,
      41,   110,     3,    10,    59,    96,    98,    83,    10,    82,
      83,    84,   110,   110,    74,    74,   110,    12,    12,    12,
     116,    40,    85,    12,   121
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    77,    78,    78,    79,    79,    79,    80,    80,    81,
      81,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    83,    83,    83,    83,    83,    84,    84,
      85,    85,    86,    87,    87,    88,    88,    88,    89,    89,
      90,    91,    92,    93,    94,    95,    96,    96,    97,    98,
      99,    99,    99,   100,   100,   100,   100,   101,   101,   101,
     102,   102,   102,   102,   103,   104,   104,   104,   105,   105,
     106,   107,   107,   107,   107,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   109,
     109,   110,   110,   110,   110,   110,   110,   110,   110,   111,
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
     111,   111,   111,   111,   111,   111,   111,   111,   112,   112,
     112,   112,   112,   113,   113,   113,   114,   114,   114,   114,
     115,   115,   116,   116,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   118,   118,   119,   119,
     120,   120,   121,   121,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   126,   126,   127,   127,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   129,   129,   129,   129,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     1,     2,     1,     2,     3,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     3,     4,     4,     5,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     1,     1,     2,
       7,     5,     1,     6,     1,     6,     2,     0,     1,     1,
       4,     5,     6,     1,     2,     2,     3,     2,     4,     4,
       5,     6,     5,     6,     1,     2,     1,     4,     4,     3,
       2,     4,     4,     4,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     3,     4,     4,     4,     4,     4,
       4,     2,     2,     2,     2,     3,     3,     3,     3,     3,
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
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       4,     4,     5,     1,     3,     4,     1,     1,     3,     3,
       5,     7,     1,     1,     3,     4,     4,     5,     4,     5,
       5,     5,     6,     6,     6,     7,     1,     3,     2,     4,
       2,     3,     4,     6,     1,     2,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     3,     1,     3,
       2,     2,     2,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     4,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1
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
       0,   225,   225,   226,   228,   229,   230,   233,   234,   237,
     238,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   255,   256,   257,   258,   259,   262,   263,
     266,   267,   271,   273,   274,   278,   279,   280,   282,   283,
     287,   291,   293,   295,   297,   300,   302,   303,   305,   306,
     309,   310,   311,   313,   314,   315,   316,   318,   319,   320,
     324,   325,   326,   327,   329,   331,   332,   333,   335,   336,
     340,   344,   345,   346,   347,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   368,
     369,   373,   374,   375,   376,   377,   378,   379,   380,   383,
     384,   385,   386,   387,   389,   390,   392,   393,   394,   395,
     396,   398,   399,   400,   401,   403,   404,   405,   407,   408,
     409,   411,   412,   413,   414,   415,   416,   417,   418,   420,
     421,   422,   423,   424,   426,   427,   428,   429,   430,   432,
     433,   434,   435,   436,   437,   438,   439,   441,   442,   443,
     444,   445,   446,   447,   448,   450,   451,   452,   454,   455,
     456,   458,   459,   460,   461,   462,   463,   464,   466,   467,
     468,   469,   470,   471,   472,   474,   475,   476,   477,   478,
     479,   480,   482,   483,   484,   485,   486,   487,   488,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   526,   527,   528,   530,   531,   532,   534,
     535,   536,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   553,   555,   556,
     557,   559,   560,   561,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   590,   591,
     592,   593,   594,   596,   597,   598,   602,   603,   604,   605,
     607,   608,   610,   611,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   628,   629,   633,   634,
     636,   637,   639,   640,   644,   645,   646,   647,   648,   649,
     650,   651,   652,   653,   654,   655,   656,   657,   661,   662,
     663,   664,   665,   666,   667,   668,   669,   670,   671,   672,
     673,   674,   675,   676,   677,   678,   679,   680,   681,   685,
     686,   687,   688,   689,   690,   691,   692,   693,   694,   695,
     696,   697,   698,   699,   700,   701,   702,   703,   704,   705,
     706,   707,   708,   709,   710,   711,   715,   716,   717,   718,
     719,   721,   722,   723,   724,   725,   726,   727,   729,   730,
     731,   732,   733,   734,   735,   737,   738,   739,   740,   741,
     743,   744,   745,   746,   747,   749,   750,   751,   752,   753,
     755,   756,   757,   758,   759,   761,   765,   766,   768,   769,
     773,   774,   775,   776,   777,   778,   779,   780,   781,   782,
     783,   784,   786,   787,   788,   789,   793,   794,   795,   796,
     797,   798,   799,   800,   801,   802,   803,   804,   805,   806
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
#line 4717 "frontend/parser.cpp"

#line 809 "frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    auto msg = std::to_string(scanner->loc->begin.line) + ":" + std::to_string(scanner->loc->begin.column) + ": " + err_message;
    scanner->fatal_error(ptc::diag::ERR_SYNTAX, msg);
}
