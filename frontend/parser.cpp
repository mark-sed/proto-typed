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

  case 450: // type: mattype "?"
#line 818 "frontend/parser.yy"
       { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 3474 "frontend/parser.cpp"
    break;

  case 451: // type: "'int'"
#line 819 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, false, true); }
#line 3480 "frontend/parser.cpp"
    break;

  case 452: // type: "'float'"
#line 820 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, false, true); }
#line 3486 "frontend/parser.cpp"
    break;

  case 453: // type: "'string'"
#line 821 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, false, true); }
#line 3492 "frontend/parser.cpp"
    break;

  case 454: // type: "'bool'"
#line 822 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, false, true); }
#line 3498 "frontend/parser.cpp"
    break;

  case 455: // type: "any"
#line 823 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(ANY_CSTR, false, true); }
#line 3504 "frontend/parser.cpp"
    break;

  case 456: // type: "identifier"
#line 824 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[0].value.as < std::string > (), false, true); }
#line 3510 "frontend/parser.cpp"
    break;

  case 458: // type: mattype
#line 826 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 3516 "frontend/parser.cpp"
    break;


#line 3520 "frontend/parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -663;

  const short  Parser ::yytable_ninf_ = -457;

  const short
   Parser ::yypact_[] =
  {
     296,  -663,  -663,  -663,  -663,  -663,  -663,  -663,  1371,   467,
     640,  1416,  1416,   -32,    79,   -26,  -663,   104,  -663,  -663,
    1416,  -663,  -663,   -22,    24,    25,    31,    36,    52,    65,
      67,   158,   178,    60,  -663,  -663,   237,   237,  -663,  -663,
    -663,   245,  -663,  2363,  -663,   279,  -663,  -663,   237,   237,
     237,  1985,  2652,  -663,  1339,   634,   651,  2818,  2910,  1231,
     806,    40,   182,    -1,   285,   235,  2592,   303,  1339,   634,
     651,  2767,  1539,  1175,   502,  1416,  -663,   235,  -663,    43,
     481,   481,   478,  -663,  -663,  -663,  -663,   131,  2818,  2910,
    1231,  -663,   131,  -663,   806,   264,   874,  -663,   281,  -663,
    1327,  -663,   280,    79,  -663,    79,  -663,    79,  -663,    79,
    -663,    17,  -663,   315,   497,   106,    79,  -663,  -663,  -663,
     902,  -663,  -663,  -663,  2478,  -663,  -663,  -663,  -663,  -663,
    1416,   314,   556,  -663,  -663,   269,  1416,  -663,  -663,  -663,
    1416,  1416,  1416,  1416,  1416,  1416,  1416,  1416,  1416,  1416,
    1416,  1416,  1416,  -663,  1125,   902,  1416,  1416,  1416,  1416,
    1416,  1416,  1416,  1416,  1416,  1416,  1416,  1416,  1416,  1416,
    1416,  1416,  1416,  1416,  1416,  1416,  1416,   202,  -663,   902,
    1416,  1416,  1416,  1416,  1416,  1416,  -663,  1416,  1416,  1416,
    1416,  1416,  1416,  1416,  1416,  1416,  1416,  1416,  1416,  1416,
    1416,  1416,  1416,  1416,  1416,  1416,  1416,  1416,  1416,  1416,
    1416,  1416,  1416,  1416,  1416,  1416,  1416,  1416,  1416,  1416,
    1416,  1416,  1416,  1416,  1416,  1416,  1416,  1416,  1416,  1416,
    1416,  1416,  1416,  1416,  1416,  1416,  1416,  1416,  1416,  1416,
    1416,  1416,  1416,    79,  -663,  -663,   956,    20,   324,  -663,
     902,   336,  -663,  -663,  -663,  -663,  -663,  -663,    99,   338,
    -663,    10,  1647,  1210,   478,   478,  -663,   481,   481,   481,
     481,   481,   481,   478,   478,   478,   478,   478,   481,   481,
     481,   481,   481,   481,  1416,    79,  2652,   352,  2818,   -26,
      41,   339,   363,     1,  1416,  -663,  -663,  -663,  -663,   335,
     273,   765,   747,    29,  -663,   305,   391,  -663,    44,  -663,
     403,  2478,  -663,  2169,   471,   474,  -663,  2107,  -663,  -663,
    -663,  -663,  -663,  -663,  -663,  -663,  -663,  -663,  -663,  -663,
    -663,    39,  -663,   103,   317,    26,   882,   935,   317,    26,
     882,   935,   238,   482,   472,   475,   238,   472,   475,   238,
     472,   475,   238,   472,   475,  2242,   307,   346,  2841,  2944,
     572,   872,  2710,   456,  2681,   546,  2739,   814,  2435,  2921,
    2088,  2864,  2548,  2887,   299,  1031,   299,  1031,  1729,   500,
    -663,  -663,  1073,  1462,   340,  -663,  1729,   500,  -663,  -663,
    1073,  1462,   340,  -663,  1322,  1611,  1486,   487,  1322,  1611,
    1486,   487,  1322,  1611,  1486,   487,  1322,  1611,  1486,   487,
    -663,  -663,   239,   317,    26,   317,    26,   238,   482,  2739,
     757,  1729,   500,  1729,   500,  2242,   307,   346,  2841,  2944,
     572,   872,  2739,   757,  1729,  -663,  1729,  -663,  2242,   307,
     346,  2841,  2944,   572,   872,  2739,   757,  1729,  -663,  1729,
    -663,   317,   882,   935,   317,   882,   935,   238,   472,   475,
     238,   472,   475,   238,   472,   475,   238,   475,  2242,   307,
     346,  2841,  2944,   572,   872,  2739,   757,  2435,  2921,  2088,
    2864,  2548,  2887,   299,  1031,   299,  1031,  1729,  1073,  1462,
    1729,  1073,  1462,  1322,  1611,  1486,  1322,  1611,  1486,  1322,
    1611,  1486,  1322,  1611,  1486,   317,   882,   935,   317,   882,
     935,   238,   472,   475,   238,   472,   475,   238,   472,   475,
     238,   472,   475,  2242,   307,   346,  2841,  2944,   572,   872,
    2739,   757,  1729,  1073,  1462,  1729,  1073,  1462,  1322,  1611,
    1486,  1322,  1611,  1486,  1322,  1611,  1486,  1322,  1611,  1486,
     488,  2242,   307,   346,  2841,  2944,   572,   872,  2739,   757,
     814,  1729,   340,  1729,   340,  1322,   487,  1322,   487,  1322,
     487,  1322,   487,  2242,   307,   346,  2841,  2944,   572,   872,
    2710,   456,  2681,   546,  2739,   757,  1729,  -663,  1729,  -663,
    -663,  -663,    42,   504,     0,   933,   858,   240,  -663,   507,
    -663,  -663,  1416,  -663,  1909,  -663,   478,   478,   478,   478,
     478,   941,   952,   941,   952,   525,   527,   525,   527,   525,
     527,  2967,   527,  1159,  1400,  1842,   840,   840,   941,   952,
     941,   952,   525,   527,   525,   527,   525,   527,   525,   527,
    -663,  -663,    79,  -663,  1446,  1446,  1446,  -663,  -663,   519,
     519,  -663,   444,   534,   547,    18,    45,   490,   511,   567,
      19,  -663,  1071,   241,    70,   789,   539,  -663,  -663,  2363,
    2284,   581,  1416,  2363,  -663,  1416,  -663,  -663,  -663,  -663,
     745,  -663,  -663,    45,   576,  -663,  -663,  -663,   522,   522,
    -663,  -663,  -663,  -663,  1524,   584,  2623,   586,   271,  2795,
     593,   600,   606,   621,   620,  -663,   597,  -663,   519,   599,
    -663,  -663,   461,    45,  -663,  -663,   623,  -663,  1155,  -663,
    1229,   243,  1416,  -663,   645,  -663,   633,   590,  -663,  -663,
    -663,    45,  2592,   642,  2767,  2363,  2363,  1416,  1416,  2363,
    2363,  2363,  2363,  -663,  1416,  -663,  1416,   577,    22,  -663,
    -663,  -663,   646,  -663,   649,  -663,  1270,   625,  -663,  -663,
    -663,  -663,  2363,  -663,  -663,  -663,  -663,  -663,  -663,  -663,
     632,  -663,  -663,  -663,  -663,  -663,  -663,  -663,  -663,  -663,
    -663,  -663,   662,   624,  -663,  1416,  -663,  -663,  -663
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     9,   321,   335,   356,   383,   313,     0,     0,
       0,     0,     0,     0,   455,     0,    53,     0,    47,    49,
      38,    35,    36,     0,   451,   452,   453,   454,     0,     0,
     104,   105,     0,     0,     4,    10,     0,     0,    37,    15,
      17,     0,    18,     0,    16,     0,    19,    20,     0,     0,
       0,     0,    97,   294,    96,    98,    99,   100,   101,   102,
     103,   457,   458,     0,   313,   104,     0,   294,     0,     0,
       0,     0,     0,     0,     0,     0,   286,   104,   291,     0,
       0,     0,     0,   106,   107,   322,   336,   260,     0,     0,
       0,   385,   261,   324,     0,     0,     0,   432,    33,    32,
       0,    39,     0,   444,   428,   445,   429,   446,   430,   447,
     431,     0,    69,     0,     0,     0,   448,   117,   315,   427,
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
       0,     0,     0,   449,   433,   450,     0,    75,     0,   314,
       0,   315,   108,   295,   323,   337,   357,   384,     0,     0,
     287,     0,     0,     0,     0,     0,   324,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   440,   300,     0,   299,     0,
     456,     0,     0,     0,     0,   435,   436,   437,   438,     0,
       0,     0,     0,     0,   317,     0,     0,   434,     0,     6,
       0,     0,    23,     0,     0,     0,    93,    92,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
     109,     0,    94,     0,   152,   150,   147,   148,   160,   158,
     155,   156,   134,   133,   129,   130,   139,   137,   138,   144,
     142,   143,   124,   126,   123,   285,   283,   284,   279,   280,
     281,   282,   256,   255,   259,   258,   253,   252,   231,   230,
     237,   236,   234,   233,   163,   162,   166,   165,   211,   209,
     206,   207,   202,   203,   204,   205,   228,   226,   223,   224,
     219,   220,   221,   222,   173,   170,   171,   172,   187,   184,
     185,   186,   180,   177,   178,   179,   194,   191,   192,   193,
     120,   121,     0,   151,   149,   159,   157,   132,   131,   251,
     244,   210,   208,   227,   225,   277,   382,   266,   379,   380,
     378,   381,   249,   242,   199,   394,   216,   401,   278,   271,
     272,   267,   268,   269,   270,   250,   243,   201,   200,   218,
     217,   145,   329,   355,   153,   328,   352,   127,   325,   343,
     135,   326,   346,   140,   327,   349,   125,   340,   273,   367,
     262,   364,   365,   363,   366,   245,   238,   229,   332,   235,
     334,   232,   333,   161,   330,   164,   331,   195,   389,   390,
     212,   396,   397,   167,   402,   403,   181,   407,   408,   174,
     412,   413,   188,   417,   418,   146,   354,   353,   154,   351,
     350,   128,   342,   341,   136,   345,   344,   141,   348,   347,
     122,   339,   338,   274,   372,   263,   369,   370,   368,   371,
     246,   239,   196,   392,   391,   213,   399,   398,   168,   405,
     404,   182,   410,   409,   175,   415,   414,   189,   420,   419,
       0,   275,   362,   264,   359,   360,   358,   361,   247,   240,
     422,   197,   393,   214,   400,   169,   406,   183,   411,   176,
     416,   190,   421,   276,   377,   265,   374,   375,   373,   376,
     254,   387,   257,   386,   248,   241,   198,   388,   215,   395,
     439,   424,   456,     0,   425,     0,     0,     0,   316,     0,
     288,   289,     0,   292,     0,   322,     0,     0,     0,     0,
       0,   329,   355,   328,   352,   325,   343,   326,   346,   327,
     349,     0,   340,   332,   334,   333,   330,   331,   354,   353,
     351,   350,   342,   341,   345,   344,   348,   347,   339,   338,
      79,   442,   441,    34,     0,     0,     0,    75,    78,     0,
      58,    55,     0,     0,     0,     0,     0,     0,    74,     0,
       0,   301,     0,     0,   113,     0,     0,   318,   114,     0,
       0,    24,     0,     0,   110,     0,   115,   112,   111,   423,
       0,    77,    76,     0,     0,   113,   290,   293,   329,   328,
     325,   326,   327,   443,     0,     0,   300,     0,     0,   299,
       0,     0,     0,     0,     0,    59,     0,    56,    60,    62,
      67,    72,     0,     0,    70,   305,     0,   303,     0,   302,
       0,     0,     0,    46,    25,    26,     0,    52,    95,   426,
      65,     0,   300,     0,   299,     0,     0,     0,     0,     0,
       0,     0,     0,    57,     0,    61,     0,     0,     0,    68,
     308,   307,     0,   306,     0,   304,     0,   319,    27,    48,
      54,    50,     0,    66,   296,    28,    29,    41,    44,   297,
       0,    42,    45,    40,    43,    64,    63,    73,    71,   311,
     310,   309,     0,     0,    51,     0,   312,   320,   298
  };

  const short
   Parser ::yypgoto_[] =
  {
    -663,  -663,   -75,   505,   -28,     2,    -5,  -450,  -662,  -663,
     399,  -663,  -663,  -663,  -663,  -663,  -663,  -663,  -663,  -663,
    -663,  -663,  -663,  -617,  -663,  -663,   617,  -663,   108,   602,
    -663,   566,  -663,  1816,   227,    -7,   638,  1467,  -401,   432,
    1297,  1661,  1854,   -59,   -76,    -8,   844,   549,  1172,  -663,
      35,  -663,    -2,    -3
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    32,    33,   128,    34,    35,   766,   767,   135,    36,
      99,    37,    38,    39,    40,    41,    42,    43,    44,   761,
      45,   762,    46,   653,   654,    47,   113,   658,   659,    48,
      49,    50,   331,    51,    52,    53,    79,    68,   697,   698,
     178,    69,    70,   118,   306,    57,    89,    90,    94,    61,
     593,    62,   119,    63
  };

  const short
   Parser ::yytable_[] =
  {
      71,    67,    85,    88,    93,   125,   251,   723,   246,   246,
     246,   727,    97,   602,     3,     4,     5,     6,     7,     8,
     299,     9,   104,   106,   108,   110,    10,   246,   246,   -69,
     300,   246,   704,   705,    11,    96,    96,   179,   134,    12,
     680,   664,    96,   182,    95,   133,   259,    96,   131,   674,
      98,    96,    96,    96,   102,   260,   668,   313,   132,   244,
     123,   124,   595,     2,     3,     4,     5,     6,     7,     8,
     665,     9,   262,    85,   266,   247,    10,   647,   114,   675,
     115,    96,   644,   261,    11,   665,    77,    31,   288,    12,
      96,   745,   103,   105,   709,   714,   309,   293,   778,   107,
     784,   295,   599,   296,   109,   297,   288,   298,   243,   116,
     116,   600,   288,   100,   307,   676,    13,    14,    15,    16,
     304,    17,    18,    19,    20,    21,    22,    23,   111,    24,
      25,    26,    27,    28,    29,   116,    30,    31,  -441,   261,
     154,   112,   155,  -456,   665,   305,  -441,   288,   336,   340,
     344,   347,   350,   353,   358,    88,    88,    88,   369,   371,
     373,   375,   377,   382,   390,   395,   399,   403,   407,   120,
     177,   288,    88,    88,    88,    88,    88,    88,   122,   428,
      88,    88,    88,   441,    88,    88,    88,   452,   455,   458,
     461,   464,    88,   471,    88,   478,   480,   482,   484,   486,
     488,   491,   494,   497,   500,   503,   506,   509,   512,   515,
     518,   521,   526,    88,   533,   536,   539,   542,   545,   548,
     288,   554,    88,    88,    88,    88,    88,    88,    88,   576,
      88,    88,    88,    88,    88,    66,   670,   126,    87,    92,
     127,   590,   288,   594,   701,   703,   250,   154,   115,   155,
     245,   677,   685,   717,   130,   755,   604,   605,   161,   611,
     613,   615,   617,   619,   621,   623,   624,   625,   626,   627,
     628,   630,   632,   634,   636,   638,   650,   177,   410,   411,
     665,   665,   718,   641,   756,   125,   768,   651,   136,   771,
     772,   773,   774,   733,   288,   249,     1,   655,   660,     2,
       3,     4,     5,     6,     7,     8,   284,     9,   154,   737,
     155,   738,    10,   253,   156,   157,   158,   159,   160,   161,
      11,   289,   294,   286,   301,    12,   154,   311,   155,   652,
      14,   314,   188,   596,   158,   159,   160,   161,   177,   189,
     190,   286,    24,    25,    26,    27,   598,   286,   649,   592,
     601,   228,    13,    14,    15,    16,   177,    17,    18,    19,
      20,    21,    22,    23,   642,    24,    25,    26,    27,    28,
      29,   192,    30,    31,   233,   234,   235,   236,   193,   194,
     645,   666,   286,   334,   338,   342,   346,   349,   352,   355,
     362,   364,   366,   368,   370,   372,   374,   376,   378,   386,
     394,   398,   402,   406,   646,   667,   286,   413,   415,   417,
     419,   421,   423,   669,   425,   432,   434,   436,   438,   445,
     447,   449,   451,   454,   457,   460,   463,   466,   468,   475,
     477,   479,   481,   483,   485,   487,   490,   493,   496,   499,
     502,   505,   508,   511,   514,   517,   520,   523,   530,   532,
     535,   538,   541,   544,   547,   286,   551,   558,   561,   563,
     565,   567,   569,   571,   573,   580,   582,   584,   586,   588,
      75,     3,     4,     5,     6,     7,     8,   286,     9,    76,
     672,   240,     3,    10,   673,     3,     4,   264,   241,   242,
      80,    11,   200,   179,   265,   219,    12,    81,   228,   747,
     678,     3,     4,     5,     6,     7,     8,    82,     9,   285,
      82,   179,   257,    10,   679,   180,   181,   182,    14,   686,
     706,    11,   650,   237,   238,   239,    12,   240,   287,   286,
      24,    25,    26,    27,   241,   242,   682,   592,   302,   608,
     609,   610,   129,    77,    31,   272,   303,   283,   707,    59,
     708,   712,   308,   137,   138,   139,   153,    73,    59,     2,
       3,     4,     5,     6,     7,     8,   711,     9,   238,    59,
     312,   240,    10,    77,    31,   652,    14,   713,   241,   242,
      11,   722,    59,   228,   725,    12,   731,   333,    24,    25,
      26,    27,    59,   660,   735,   592,   736,   230,   688,   689,
     690,   691,   692,   739,   231,   232,   233,   234,   235,   236,
     740,   412,    13,    14,    15,    16,   741,    17,    18,    19,
      20,    21,    22,    23,    59,    24,    25,    26,    27,    28,
      29,   742,    30,    31,   743,   750,   699,   699,   699,   744,
     693,   746,   125,   759,     3,     4,   655,   655,   758,    80,
     760,   710,   764,   777,   288,   187,    81,   288,   779,   188,
     550,   780,   693,   305,   134,   783,   189,   190,   134,    82,
     785,   133,   191,    59,   786,   133,   192,   594,   730,    59,
     248,    59,   597,   193,   194,    59,   734,    67,   643,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,   292,    59,   684,   655,   316,   787,   749,   748,
     288,   360,   288,   258,   367,   729,    83,    84,     0,     0,
     384,   392,   397,   401,   405,   409,   763,     0,     0,   288,
     288,     0,     0,     0,   663,     0,   430,   765,   765,     0,
     443,   765,   765,   765,   765,     0,     0,     0,   288,     0,
     473,     3,     4,     5,     6,     7,     8,   134,     9,   661,
       0,     0,     0,    10,   133,     0,     0,     0,   179,   528,
       0,    11,   180,   181,   182,   656,    12,   288,   556,   560,
     562,   564,   566,   568,   570,   572,   578,     0,   662,   184,
     185,     0,     0,     3,     4,     5,     6,     7,     8,     0,
       9,   719,    14,   657,     0,    10,     0,     0,     0,     0,
      59,     0,     0,    11,    24,    25,    26,    27,    12,     0,
       0,   592,    14,    77,    31,   228,     0,   237,   238,   239,
     720,   240,     0,    59,    24,    25,    26,    27,   241,   242,
       0,   592,     0,    59,    58,     0,   231,   232,   233,   234,
     235,   236,    72,    58,    86,   606,   607,   608,   609,   610,
      59,     0,    59,     0,    58,    77,    31,     0,   683,     0,
       0,   696,   696,   696,     0,     0,     0,    58,     3,     4,
       5,     6,     7,     8,     0,     9,   285,    58,     0,   286,
      10,     0,   286,     0,   238,   239,   657,   240,    11,   197,
     198,   199,   200,    12,   241,   242,     3,     4,     5,     6,
       7,     8,     0,     9,     0,    14,     0,     0,    10,    58,
       0,   732,     0,     0,   263,    86,    11,    24,    25,    26,
      27,    12,     0,     0,   592,     0,     0,     3,     4,     5,
       6,     7,     8,   302,     9,   286,   115,   286,     0,    10,
      77,    31,   216,   217,   218,   219,     0,    11,   269,   270,
     271,   272,    12,     0,   286,   286,   591,     0,    58,   280,
     281,   282,   283,     0,    58,     0,    58,     0,    77,    31,
      58,     0,     0,   286,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,     0,    58,     0,
     337,   341,   345,   348,   351,   354,   359,     0,     0,    77,
      31,     0,   286,    14,     0,   383,   391,   396,   400,   404,
     408,     0,     0,     0,     0,    24,    25,    26,    27,     0,
       0,   429,   592,     0,     0,   442,     0,     0,     0,   453,
     456,   459,   462,   465,   467,   472,   195,   196,   197,   198,
     199,   200,   489,   492,   495,   498,   501,   504,   507,   510,
     513,   516,   519,   522,   527,     0,   534,   537,   540,   543,
     546,   549,     0,   555,     0,     3,     4,     5,     6,     7,
       8,   577,     9,   715,     0,     0,     0,    10,   195,   196,
     197,   198,   199,   200,   716,    11,     0,   721,     0,     0,
      12,     0,     0,   206,   207,    58,     0,   210,   211,   212,
     213,   612,   614,   616,   618,   620,   622,     0,     0,     0,
       0,     0,   629,   631,   633,   635,   637,   639,    58,     3,
       4,     5,     6,     7,     8,   330,     9,     0,    58,     0,
       0,    10,     0,     0,    59,     0,     0,    77,    31,    11,
     752,    59,   754,     0,    12,    58,     0,    58,     0,     3,
       4,     5,     6,     7,     8,     0,     9,   751,     0,   769,
     770,    10,    60,     0,   606,   607,   608,   609,   610,    11,
      74,    60,     0,    91,    12,   256,   228,     0,   782,   276,
     277,     0,    60,    59,    59,    59,   229,     0,     0,     0,
     230,    77,    31,     0,     0,    60,     0,   231,   232,   233,
     234,   235,   236,     0,     0,    60,     0,   788,    59,    59,
     255,    59,    59,     0,    59,   278,   279,   280,   281,   282,
     283,    77,    31,     3,     4,     5,     6,     7,     8,     0,
       9,   753,   228,    73,     0,    10,     0,    60,     0,     0,
       0,     0,   229,    11,     0,     0,   230,     0,    12,     0,
       0,     0,     0,   231,   232,   233,   234,   235,   236,     0,
       0,    59,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     9,   781,     0,    59,    59,    10,     0,    59,    59,
      59,    59,     0,    59,    11,    59,    60,     0,     0,    12,
       0,     0,    60,     0,    60,    77,    31,     0,    60,     0,
       0,    59,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,     0,    60,   117,   121,     0,
       0,   154,     0,   155,   361,   363,   365,   156,   157,   158,
     159,   160,   161,   385,   393,     0,    77,    31,     0,     0,
     179,   186,   169,   170,   180,   181,   182,     0,     0,   431,
       0,   177,   117,   444,   183,   186,     0,     0,     0,     0,
       0,   184,   185,   474,   117,     3,     4,     5,     6,    64,
       8,     0,     9,     0,    14,     0,     0,    10,     0,     0,
       0,     0,   529,     0,     0,    11,    24,    25,    26,    27,
      12,   557,     0,   290,   291,     0,     0,     0,     0,   579,
     581,   583,     0,   587,   589,   606,   607,   608,   609,   610,
       3,     4,     5,     6,     7,     8,   273,     9,   275,     0,
     276,   277,    10,    60,     0,     0,     0,     0,     0,    58,
      11,     0,     0,     0,     0,    12,    58,    65,    31,     0,
       3,     4,     5,     6,     7,   694,    60,     9,     0,     0,
       0,     0,    10,     0,     0,     0,    60,    54,     0,     0,
      11,     0,     0,     0,     0,    12,    54,   214,   215,   216,
     217,   218,   219,    60,     0,    60,     0,    54,    58,    58,
      58,     0,    77,    31,     0,     0,   224,   225,   226,   227,
      54,   214,   215,   216,   217,   218,   219,     0,     0,     0,
      54,     0,     0,    58,    58,     0,    58,    58,     0,    58,
       0,     0,    77,    31,     0,     0,     0,     0,     3,     4,
       5,     6,    64,   694,     0,     9,     0,     0,    72,     0,
      10,     0,    54,     0,     0,     0,     0,     0,    11,   255,
       0,     0,     0,    12,   214,   215,   216,   217,   218,   219,
     220,     0,     0,     0,   221,     0,    58,     0,     0,     0,
       0,   222,   223,   224,   225,   226,   227,     0,     0,    58,
      58,     0,     0,    58,    58,    58,    58,     0,    58,     0,
      58,    54,     0,     0,     0,     0,     0,    54,     0,    54,
      65,    31,     0,    54,     0,     0,    58,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
       0,    54,     0,   335,   339,   343,   195,   196,   197,   198,
     199,   200,   186,     0,     0,     0,   186,     0,   379,   387,
     186,   206,   207,     0,     0,     0,     0,   414,   416,   418,
     420,   422,   424,     0,     0,   433,     0,   254,     0,   446,
       0,    55,   267,   268,   269,   270,   271,   272,     0,   476,
      55,     0,     0,   273,   274,   275,   186,   276,   277,     0,
       0,    55,     0,     0,   186,     0,     0,     0,   531,     0,
       0,     0,     0,     0,    55,     0,     0,   559,     0,     0,
       0,     0,     0,     0,    55,     0,     0,   585,     0,     0,
       0,   186,     0,   186,     0,   186,     0,   186,     0,   186,
       0,   186,     0,     0,     0,     0,     0,     0,    54,     0,
     186,     0,     0,     0,     0,     0,    55,     0,   154,     0,
     155,     0,     0,   186,   156,   157,   158,   159,   160,   161,
       0,    54,     0,     0,     0,     0,     0,     0,     0,   169,
     170,    54,     0,   173,   174,   175,   176,    60,   177,     0,
       0,     0,     0,   186,    60,     0,     0,     0,    54,     0,
      54,     0,     0,     0,     0,    55,     0,     0,     0,     0,
       0,    55,     0,    55,     0,     0,     0,    55,     0,     0,
       0,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,     0,    55,    60,    60,    60,     0,
       0,     0,     0,   356,     0,    78,     0,     0,   186,     0,
       0,     0,   380,   388,     0,     0,   101,     0,     0,     0,
       0,    60,    60,     0,    60,    60,     0,    60,   426,     0,
     435,   437,   439,     0,    56,     0,   186,   606,   607,   608,
     609,   610,   469,    56,     0,     0,    74,     0,   273,     0,
       0,     0,   276,   277,    56,     0,     0,     0,     0,     0,
       0,   524,   186,     0,     0,     0,     0,    56,     0,     0,
     552,    78,     0,     0,    60,     0,     0,    56,   574,     0,
       0,     0,     0,     0,     0,     0,     0,    60,    60,     0,
       0,    60,    60,    60,    60,     0,    60,     0,    60,   254,
       0,     0,    55,     0,   606,   607,   608,   609,   610,    56,
       0,     0,     0,     0,    60,   273,   274,   275,     0,   276,
     277,     0,     0,     0,     0,    55,   310,     0,     0,     0,
       0,     0,   315,     0,     0,    55,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,     0,
     332,     0,    55,     0,    55,     0,     0,     0,    56,     0,
       0,     0,     0,     0,    56,   126,    56,     0,   127,     0,
      56,     0,     0,     0,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,     0,    56,     0,
       0,     0,     0,     0,     0,     0,   357,     0,     0,     0,
       0,     0,     0,     0,     0,   381,   389,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,     0,   151,
     152,   427,     0,     0,     0,   440,     0,   448,   450,     0,
       0,     0,     0,     0,     0,   470,     0,     0,     0,     0,
       0,     0,    54,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,   525,     0,     0,   603,     0,     0,
       0,     0,     0,   553,     0,     0,     0,     0,     0,     0,
       0,   575,     0,     0,     0,     0,     0,   154,     0,   155,
     640,     0,     0,   156,   157,   158,   159,   160,   161,     0,
     648,    54,    54,    54,   166,    56,   168,     0,   169,   170,
     171,   172,   173,   174,   175,   176,     0,   177,     0,     0,
       0,     0,     0,     0,     0,     0,    54,    54,    56,    54,
      54,     0,    54,     0,     0,     0,     0,     0,    56,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
       0,   151,   152,     0,     0,    56,     0,    56,     0,     0,
     124,     0,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,   671,     0,    10,     0,     0,     0,    54,
       0,     0,     0,    11,     0,     0,     0,     0,    12,     0,
       0,     0,    54,    54,     0,     0,    54,    54,    54,    54,
       0,    54,     0,    54,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,    14,    15,    16,    54,
      17,    18,    19,    20,    21,    22,    23,     0,    24,    25,
      26,    27,    28,    29,     0,    30,    31,     0,     0,     0,
       0,   154,     0,   155,     0,     0,    55,   156,   157,   158,
     159,   160,   161,    55,   163,   164,     0,   165,   166,   167,
     168,     0,   169,   170,   171,   172,   173,   174,   175,   176,
       0,   177,     0,     0,     0,   124,     0,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,   724,     0,
      10,     0,     0,     0,     0,    55,    55,    55,    11,     0,
       0,     0,     0,    12,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,    55,     0,    55,    55,     0,    55,     0,     0,     0,
      13,    14,    15,    16,     0,    17,    18,    19,    20,    21,
      22,    23,     0,    24,    25,    26,    27,    28,    29,     0,
      30,    31,     0,     0,     0,     0,   131,     3,     4,     5,
       6,     7,     8,     0,     9,     0,   132,     0,     0,    10,
       0,     0,     0,    55,     0,     0,     0,    11,     0,     0,
       0,     0,    12,     0,     0,     0,    55,    55,     0,     0,
      55,    55,    55,    55,     0,    55,     0,    55,     0,     0,
       0,   681,     0,     0,     0,     0,     0,     0,   687,    13,
      14,    15,    16,    55,    17,    18,    19,    20,    21,    22,
      23,     0,    24,    25,    26,    27,    28,    29,     0,    30,
      31,     0,     0,     0,   154,     0,   155,     0,     0,    56,
     156,   157,   158,   159,   160,   161,    56,     0,     0,     0,
     695,   700,   702,     0,     0,   169,   170,   171,   172,   173,
     174,   175,   176,     0,   177,     0,     0,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     8,   726,     9,
       0,   728,     0,     0,    10,     0,     0,     0,    56,    56,
      56,     0,    11,     0,     0,     0,     0,    12,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,    56,     0,    56,    56,     0,    56,
       0,     0,     0,     0,    13,    14,    15,    16,   757,    17,
      18,    19,    20,    21,    22,    23,     0,    24,    25,    26,
      27,    28,    29,     0,    30,    31,     0,   154,     0,   155,
     775,     0,   776,   156,   157,   158,   159,   160,   161,     0,
       0,     0,     0,     0,   166,     0,    56,     0,   169,   170,
     171,   172,   173,   174,   175,   176,     0,   177,     0,    56,
      56,     0,     0,    56,    56,    56,    56,     0,    56,     0,
      56,   154,   252,   155,     0,     0,     0,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    56,   165,   166,   167,
     168,     0,   169,   170,   171,   172,   173,   174,   175,   176,
       0,   177,   154,   -97,   155,     0,     0,     0,   156,   157,
     158,   159,   160,   161,   162,   163,   164,     0,   165,   166,
     167,   168,     0,   169,   170,   171,   172,   173,   174,   175,
     176,   154,   177,   155,     0,     0,     0,   156,   157,   158,
     159,   160,   161,   162,   163,   164,     0,   165,   166,   167,
     168,     0,   169,   170,   171,   172,   173,   174,   175,   176,
     154,   177,   155,     0,     0,     0,   156,   157,   158,   159,
     160,   161,     0,   163,     0,     0,   165,   166,   167,   168,
       0,   169,   170,   171,   172,   173,   174,   175,   176,   154,
     177,   155,     0,     0,     0,   156,   157,   158,   159,   160,
     161,     0,     0,     0,     0,   165,   166,   167,   168,     0,
     169,   170,   171,   172,   173,   174,   175,   176,   154,   177,
     155,     0,     0,     0,   156,   157,   158,   159,   160,   161,
       0,     0,     0,     0,     0,   166,   167,   168,     0,   169,
     170,   171,   172,   173,   174,   175,   176,   254,   177,     0,
       0,     0,   195,   196,   197,   198,   199,   200,   201,     0,
       0,     0,   202,   203,   204,   205,     0,   206,   207,   208,
     209,   210,   211,   212,   213,  -100,     0,     0,     0,     0,
     195,   196,   197,   198,   199,   200,   201,     0,     0,     0,
     202,   203,   204,   205,     0,   206,   207,   208,   209,   210,
     211,   212,   213,   195,   196,   197,   198,   199,   200,   201,
       0,     0,     0,   202,   203,   204,   205,     0,   206,   207,
     208,   209,   210,   211,   212,   213,   195,   196,   197,   198,
     199,   200,     0,     0,     0,     0,   202,   203,   204,   205,
       0,   206,   207,   208,   209,   210,   211,   212,   213,   195,
     196,   197,   198,   199,   200,     0,     0,     0,     0,     0,
     203,     0,   205,     0,   206,   207,   208,   209,   210,   211,
     212,   213,   195,   196,   197,   198,   199,   200,     0,     0,
       0,     0,     0,   203,     0,     0,     0,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,     0,     0,     0,   221,   195,   196,   197,   198,
     199,   200,   222,   223,   224,   225,   226,   227,     0,     0,
       0,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,     0,     0,     0,     0,   221,
       0,     0,     0,     0,     0,     0,   222,   223,   224,   225,
     226,   227,   267,   268,   269,   270,   271,   272,     0,     0,
       0,     0,     0,   273,   274,   275,     0,   276,   277
  };

  const short
   Parser ::yycheck_[] =
  {
       8,     8,    10,    11,    12,    33,    65,   669,     9,     9,
       9,   673,    14,     3,     4,     5,     6,     7,     8,     9,
       3,    11,    24,    25,    26,    27,    16,     9,     9,     9,
      13,     9,   649,   650,    24,    11,    11,    11,    43,    29,
      40,    12,    11,    17,    76,    43,     3,    11,     3,    10,
      76,    11,    11,    11,    76,    12,    12,   132,    13,    61,
       0,     1,    42,     3,     4,     5,     6,     7,     8,     9,
      41,    11,    80,    81,    82,    76,    16,    76,    11,    40,
      13,    11,    41,    40,    24,    41,    76,    77,    96,    29,
      11,   708,    68,    68,    76,    76,   124,   100,    76,    68,
     762,   103,     3,   105,    68,   107,   114,   109,    68,    68,
      68,    12,   120,     9,   116,    12,    56,    57,    58,    59,
      14,    61,    62,    63,    64,    65,    66,    67,    76,    69,
      70,    71,    72,    73,    74,    68,    76,    77,    68,    40,
       9,    76,    11,    76,    41,    39,    76,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    11,
      39,   179,   180,   181,   182,   183,   184,   185,     0,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     8,   311,     0,    11,    12,
       3,   243,   250,   246,   645,   646,    11,     9,    13,    11,
      68,    12,    12,    12,     9,    12,   264,   265,    20,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,     3,    39,    76,    77,
      41,    41,    41,   285,    41,   313,   736,    14,     9,   739,
     740,   741,   742,   694,   302,    10,     0,   300,   301,     3,
       4,     5,     6,     7,     8,     9,    42,    11,     9,    38,
      11,    40,    16,    10,    15,    16,    17,    18,    19,    20,
      24,    40,    42,    96,     9,    29,     9,    13,    11,    56,
      57,    62,    25,     9,    17,    18,    19,    20,    39,    32,
      33,   114,    69,    70,    71,    72,    10,   120,    13,    76,
      12,    11,    56,    57,    58,    59,    39,    61,    62,    63,
      64,    65,    66,    67,    12,    69,    70,    71,    72,    73,
      74,    25,    76,    77,    34,    35,    36,    37,    32,    33,
      41,    76,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,    41,    14,   179,   180,   181,   182,
     183,   184,   185,    10,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       3,     4,     5,     6,     7,     8,     9,   250,    11,    12,
       9,    25,     4,    16,    10,     4,     5,     9,    32,    33,
       9,    24,    20,    11,    16,    20,    29,    16,    11,    38,
      12,     4,     5,     6,     7,     8,     9,    29,    11,    12,
      29,    11,    10,    16,    10,    15,    16,    17,    57,    12,
      76,    24,     3,    21,    22,    23,    29,    25,    96,   302,
      69,    70,    71,    72,    32,    33,   595,    76,    41,    17,
      18,    19,    37,    76,    77,    20,   114,    20,    14,     0,
       3,    40,   120,    48,    49,    50,    51,     8,     9,     3,
       4,     5,     6,     7,     8,     9,    76,    11,    22,    20,
      14,    25,    16,    76,    77,    56,    57,    10,    32,    33,
      24,    42,    33,    11,     3,    29,    10,   155,    69,    70,
      71,    72,    43,   596,    10,    76,    10,    25,   606,   607,
     608,   609,   610,    10,    32,    33,    34,    35,    36,    37,
      10,   179,    56,    57,    58,    59,    10,    61,    62,    63,
      64,    65,    66,    67,    75,    69,    70,    71,    72,    73,
      74,    10,    76,    77,    14,    12,   644,   645,   646,    42,
     642,    42,   670,    10,     4,     5,   649,   650,     3,     9,
      60,   656,    10,    76,   662,    21,    16,   665,    12,    25,
     228,    12,   664,    39,   669,    40,    32,    33,   673,    29,
      38,   669,    21,   124,    12,   673,    25,   680,   683,   130,
      63,   132,   250,    32,    33,   136,   694,   694,   289,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   100,   154,   596,   708,   140,   783,   713,   712,
     718,   162,   720,    75,   165,   680,    76,    77,    -1,    -1,
     171,   172,   173,   174,   175,   176,   731,    -1,    -1,   737,
     738,    -1,    -1,    -1,   302,    -1,   187,   735,   736,    -1,
     191,   739,   740,   741,   742,    -1,    -1,    -1,   756,    -1,
     201,     4,     5,     6,     7,     8,     9,   762,    11,    12,
      -1,    -1,    -1,    16,   762,    -1,    -1,    -1,    11,   220,
      -1,    24,    15,    16,    17,    10,    29,   785,   229,   230,
     231,   232,   233,   234,   235,   236,   237,    -1,    41,    32,
      33,    -1,    -1,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    57,    38,    -1,    16,    -1,    -1,    -1,    -1,
     261,    -1,    -1,    24,    69,    70,    71,    72,    29,    -1,
      -1,    76,    57,    76,    77,    11,    -1,    21,    22,    23,
      41,    25,    -1,   284,    69,    70,    71,    72,    32,    33,
      -1,    76,    -1,   294,     0,    -1,    32,    33,    34,    35,
      36,    37,     8,     9,    10,    15,    16,    17,    18,    19,
     311,    -1,   313,    -1,    20,    76,    77,    -1,    10,    -1,
      -1,   644,   645,   646,    -1,    -1,    -1,    33,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    43,    -1,   662,
      16,    -1,   665,    -1,    22,    23,    38,    25,    24,    17,
      18,    19,    20,    29,    32,    33,     4,     5,     6,     7,
       8,     9,    -1,    11,    -1,    57,    -1,    -1,    16,    75,
      -1,   694,    -1,    -1,    80,    81,    24,    69,    70,    71,
      72,    29,    -1,    -1,    76,    -1,    -1,     4,     5,     6,
       7,     8,     9,    41,    11,   718,    13,   720,    -1,    16,
      76,    77,    17,    18,    19,    20,    -1,    24,    17,    18,
      19,    20,    29,    -1,   737,   738,    10,    -1,   124,    17,
      18,    19,    20,    -1,   130,    -1,   132,    -1,    76,    77,
     136,    -1,    -1,   756,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,    -1,   154,    -1,
     156,   157,   158,   159,   160,   161,   162,    -1,    -1,    76,
      77,    -1,   785,    57,    -1,   171,   172,   173,   174,   175,
     176,    -1,    -1,    -1,    -1,    69,    70,    71,    72,    -1,
      -1,   187,    76,    -1,    -1,   191,    -1,    -1,    -1,   195,
     196,   197,   198,   199,   200,   201,    15,    16,    17,    18,
      19,    20,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,    -1,   222,   223,   224,   225,
     226,   227,    -1,   229,    -1,     4,     5,     6,     7,     8,
       9,   237,    11,    12,    -1,    -1,    -1,    16,    15,    16,
      17,    18,    19,    20,   662,    24,    -1,   665,    -1,    -1,
      29,    -1,    -1,    30,    31,   261,    -1,    34,    35,    36,
      37,   267,   268,   269,   270,   271,   272,    -1,    -1,    -1,
      -1,    -1,   278,   279,   280,   281,   282,   283,   284,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,   294,    -1,
      -1,    16,    -1,    -1,   595,    -1,    -1,    76,    77,    24,
     718,   602,   720,    -1,    29,   311,    -1,   313,    -1,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    -1,   737,
     738,    16,     0,    -1,    15,    16,    17,    18,    19,    24,
       8,     9,    -1,    11,    29,    10,    11,    -1,   756,    30,
      31,    -1,    20,   644,   645,   646,    21,    -1,    -1,    -1,
      25,    76,    77,    -1,    -1,    33,    -1,    32,    33,    34,
      35,    36,    37,    -1,    -1,    43,    -1,   785,   669,   670,
      10,   672,   673,    -1,   675,    15,    16,    17,    18,    19,
      20,    76,    77,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    11,   694,    -1,    16,    -1,    75,    -1,    -1,
      -1,    -1,    21,    24,    -1,    -1,    25,    -1,    29,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    -1,
      -1,   722,    -1,    -1,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,   735,   736,    16,    -1,   739,   740,
     741,   742,    -1,   744,    24,   746,   124,    -1,    -1,    29,
      -1,    -1,   130,    -1,   132,    76,    77,    -1,   136,    -1,
      -1,   762,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,   154,    30,    31,    -1,
      -1,     9,    -1,    11,   162,   163,   164,    15,    16,    17,
      18,    19,    20,   171,   172,    -1,    76,    77,    -1,    -1,
      11,    54,    30,    31,    15,    16,    17,    -1,    -1,   187,
      -1,    39,    65,   191,    25,    68,    -1,    -1,    -1,    -1,
      -1,    32,    33,   201,    77,     4,     5,     6,     7,     8,
       9,    -1,    11,    -1,    57,    -1,    -1,    16,    -1,    -1,
      -1,    -1,   220,    -1,    -1,    24,    69,    70,    71,    72,
      29,   229,    -1,    76,    77,    -1,    -1,    -1,    -1,   237,
     238,   239,    -1,   241,   242,    15,    16,    17,    18,    19,
       4,     5,     6,     7,     8,     9,    26,    11,    28,    -1,
      30,    31,    16,   261,    -1,    -1,    -1,    -1,    -1,   595,
      24,    -1,    -1,    -1,    -1,    29,   602,    76,    77,    -1,
       4,     5,     6,     7,     8,     9,   284,    11,    -1,    -1,
      -1,    -1,    16,    -1,    -1,    -1,   294,     0,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    29,     9,    15,    16,    17,
      18,    19,    20,   311,    -1,   313,    -1,    20,   644,   645,
     646,    -1,    76,    77,    -1,    -1,    34,    35,    36,    37,
      33,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      43,    -1,    -1,   669,   670,    -1,   672,   673,    -1,   675,
      -1,    -1,    76,    77,    -1,    -1,    -1,    -1,     4,     5,
       6,     7,     8,     9,    -1,    11,    -1,    -1,   694,    -1,
      16,    -1,    75,    -1,    -1,    -1,    -1,    -1,    24,    10,
      -1,    -1,    -1,    29,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    25,    -1,   722,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    37,    -1,    -1,   735,
     736,    -1,    -1,   739,   740,   741,   742,    -1,   744,    -1,
     746,   124,    -1,    -1,    -1,    -1,    -1,   130,    -1,   132,
      76,    77,    -1,   136,    -1,    -1,   762,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,   154,    -1,   156,   157,   158,    15,    16,    17,    18,
      19,    20,   335,    -1,    -1,    -1,   339,    -1,   171,   172,
     343,    30,    31,    -1,    -1,    -1,    -1,   180,   181,   182,
     183,   184,   185,    -1,    -1,   188,    -1,    10,    -1,   192,
      -1,     0,    15,    16,    17,    18,    19,    20,    -1,   202,
       9,    -1,    -1,    26,    27,    28,   379,    30,    31,    -1,
      -1,    20,    -1,    -1,   387,    -1,    -1,    -1,   221,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    -1,    -1,   240,    -1,    -1,
      -1,   414,    -1,   416,    -1,   418,    -1,   420,    -1,   422,
      -1,   424,    -1,    -1,    -1,    -1,    -1,    -1,   261,    -1,
     433,    -1,    -1,    -1,    -1,    -1,    75,    -1,     9,    -1,
      11,    -1,    -1,   446,    15,    16,    17,    18,    19,    20,
      -1,   284,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,   294,    -1,    34,    35,    36,    37,   595,    39,    -1,
      -1,    -1,    -1,   476,   602,    -1,    -1,    -1,   311,    -1,
     313,    -1,    -1,    -1,    -1,   124,    -1,    -1,    -1,    -1,
      -1,   130,    -1,   132,    -1,    -1,    -1,   136,    -1,    -1,
      -1,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,   154,   644,   645,   646,    -1,
      -1,    -1,    -1,   162,    -1,     9,    -1,    -1,   531,    -1,
      -1,    -1,   171,   172,    -1,    -1,    20,    -1,    -1,    -1,
      -1,   669,   670,    -1,   672,   673,    -1,   675,   187,    -1,
     189,   190,   191,    -1,     0,    -1,   559,    15,    16,    17,
      18,    19,   201,     9,    -1,    -1,   694,    -1,    26,    -1,
      -1,    -1,    30,    31,    20,    -1,    -1,    -1,    -1,    -1,
      -1,   220,   585,    -1,    -1,    -1,    -1,    33,    -1,    -1,
     229,    75,    -1,    -1,   722,    -1,    -1,    43,   237,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   735,   736,    -1,
      -1,   739,   740,   741,   742,    -1,   744,    -1,   746,    10,
      -1,    -1,   261,    -1,    15,    16,    17,    18,    19,    75,
      -1,    -1,    -1,    -1,   762,    26,    27,    28,    -1,    30,
      31,    -1,    -1,    -1,    -1,   284,   130,    -1,    -1,    -1,
      -1,    -1,   136,    -1,    -1,   294,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,    -1,
     154,    -1,   311,    -1,   313,    -1,    -1,    -1,   124,    -1,
      -1,    -1,    -1,    -1,   130,     0,   132,    -1,     3,    -1,
     136,    -1,    -1,    -1,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   162,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   171,   172,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,   187,    -1,    -1,    -1,   191,    -1,   193,   194,    -1,
      -1,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,
      -1,    -1,   595,    -1,    -1,    -1,    -1,    -1,    -1,   602,
      -1,    -1,    -1,    -1,   220,    -1,    -1,   261,    -1,    -1,
      -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,    -1,     9,    -1,    11,
     284,    -1,    -1,    15,    16,    17,    18,    19,    20,    -1,
     294,   644,   645,   646,    26,   261,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   669,   670,   284,   672,
     673,    -1,   675,    -1,    -1,    -1,    -1,    -1,   294,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    -1,    -1,   311,    -1,   313,    -1,    -1,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    -1,    -1,    14,    -1,    16,    -1,    -1,    -1,   722,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,   735,   736,    -1,    -1,   739,   740,   741,   742,
      -1,   744,    -1,   746,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,   762,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    -1,    76,    77,    -1,    -1,    -1,
      -1,     9,    -1,    11,    -1,    -1,   595,    15,    16,    17,
      18,    19,    20,   602,    22,    23,    -1,    25,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    39,    -1,    -1,    -1,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    -1,    -1,    14,    -1,
      16,    -1,    -1,    -1,    -1,   644,   645,   646,    24,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     669,   670,    -1,   672,   673,    -1,   675,    -1,    -1,    -1,
      56,    57,    58,    59,    -1,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    -1,
      76,    77,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    13,    -1,    -1,    16,
      -1,    -1,    -1,   722,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,   735,   736,    -1,    -1,
     739,   740,   741,   742,    -1,   744,    -1,   746,    -1,    -1,
      -1,   595,    -1,    -1,    -1,    -1,    -1,    -1,   602,    56,
      57,    58,    59,   762,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    -1,    76,
      77,    -1,    -1,    -1,     9,    -1,    11,    -1,    -1,   595,
      15,    16,    17,    18,    19,    20,   602,    -1,    -1,    -1,
     644,   645,   646,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,   672,    11,
      -1,   675,    -1,    -1,    16,    -1,    -1,    -1,   644,   645,
     646,    -1,    24,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   669,   670,    -1,   672,   673,    -1,   675,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,   722,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    -1,    76,    77,    -1,     9,    -1,    11,
     744,    -1,   746,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    26,    -1,   722,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    39,    -1,   735,
     736,    -1,    -1,   739,   740,   741,   742,    -1,   744,    -1,
     746,     9,    10,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   762,    25,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    39,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,     9,    39,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    25,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
       9,    39,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    -1,    22,    -1,    -1,    25,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,     9,
      39,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    25,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,     9,    39,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    10,    39,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    25,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    10,    -1,    -1,    -1,    -1,
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
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    37,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    -1,    30,    31
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
     131,    76,    76,   105,    11,    13,    68,   119,   122,   131,
      11,   119,     0,     0,     1,    83,     0,     3,    82,    82,
       9,     3,    13,    84,    85,    87,     9,    82,    82,    82,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    54,    55,    82,     9,    11,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    25,    26,    27,    28,    30,
      31,    32,    33,    34,    35,    36,    37,    39,   119,    11,
      15,    16,    17,    25,    32,    33,   119,    21,    25,    32,
      33,    21,    25,    32,    33,    15,    16,    17,    18,    19,
      20,    21,    25,    26,    27,    28,    30,    31,    32,    33,
      34,    35,    36,    37,    15,    16,    17,    18,    19,    20,
      21,    25,    32,    33,    34,    35,    36,    37,    11,    21,
      25,    32,    33,    34,    35,    36,    37,    21,    22,    23,
      25,    32,    33,    68,   131,    68,     9,    76,   105,    10,
      11,   122,    10,    10,    10,    10,    10,    10,   115,     3,
      12,    40,   124,   125,     9,    16,   124,    15,    16,    17,
      18,    19,    20,    26,    27,    28,    30,    31,    15,    16,
      17,    18,    19,    20,    42,    12,   113,   118,   124,    40,
      76,    77,   108,   132,    42,   131,   131,   131,   131,     3,
      13,     9,    41,   118,    14,    39,   123,   131,   118,    83,
     112,    13,    14,    81,    62,   112,   110,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
      10,   111,   112,   118,   113,   116,   124,   125,   113,   116,
     124,   125,   113,   116,   124,   125,   113,   124,   125,   113,
     124,   125,   113,   124,   125,   113,   120,   121,   124,   125,
     126,   127,   113,   127,   113,   127,   113,   126,   113,   124,
     113,   124,   113,   124,   113,   124,   113,   124,   113,   116,
     120,   121,   124,   125,   126,   127,   113,   116,   120,   121,
     124,   125,   126,   127,   113,   124,   125,   126,   113,   124,
     125,   126,   113,   124,   125,   126,   113,   124,   125,   126,
      76,    77,   118,   113,   116,   113,   116,   113,   116,   113,
     116,   113,   116,   113,   116,   113,   120,   121,   124,   125,
     126,   127,   113,   116,   113,   120,   113,   120,   113,   120,
     121,   124,   125,   126,   127,   113,   116,   113,   121,   113,
     121,   113,   124,   125,   113,   124,   125,   113,   124,   125,
     113,   124,   125,   113,   124,   125,   113,   125,   113,   120,
     121,   124,   125,   126,   127,   113,   116,   113,   124,   113,
     124,   113,   124,   113,   124,   113,   124,   113,   124,   125,
     113,   124,   125,   113,   124,   125,   113,   124,   125,   113,
     124,   125,   113,   124,   125,   113,   124,   125,   113,   124,
     125,   113,   124,   125,   113,   124,   125,   113,   124,   125,
     113,   124,   125,   113,   120,   121,   124,   125,   126,   127,
     113,   116,   113,   124,   125,   113,   124,   125,   113,   124,
     125,   113,   124,   125,   113,   124,   125,   113,   124,   125,
     118,   113,   120,   121,   124,   125,   126,   127,   113,   116,
     126,   113,   126,   113,   126,   113,   126,   113,   126,   113,
     126,   113,   126,   113,   120,   121,   124,   125,   126,   127,
     113,   127,   113,   127,   113,   116,   113,   127,   113,   127,
     131,    10,    76,   129,   132,    42,     9,   118,    10,     3,
      12,    12,     3,   112,   124,   124,    15,    16,    17,    18,
      19,   124,   125,   124,   125,   124,   125,   124,   125,   124,
     125,   124,   125,   124,   124,   124,   124,   124,   124,   125,
     124,   125,   124,   125,   124,   125,   124,   125,   124,   125,
     112,   131,    12,    89,    41,    41,    41,    76,   112,    13,
       3,    14,    56,   102,   103,   132,    10,    38,   106,   107,
     132,    12,    41,   118,    12,    41,    76,    14,    12,    10,
      81,    14,     9,    10,    10,    40,    12,    12,    12,    10,
      40,   112,   122,    10,   107,    12,    12,   112,   124,   124,
     124,   124,   124,   131,     9,   112,   113,   117,   118,   124,
     112,   117,   112,   117,   102,   102,    76,    14,     3,    76,
      85,    76,    40,    10,    76,    12,   118,    12,    41,    12,
      41,   118,    42,    87,    14,     3,   112,    87,   112,   129,
      85,    10,   113,   117,   124,    10,    10,    38,    40,    10,
      10,    10,    10,    14,    42,   102,    42,    38,   132,    85,
      12,    12,   118,    12,   118,    12,    41,   112,     3,    10,
      60,    98,   100,    85,    10,    84,    85,    86,    86,   118,
     118,    86,    86,    86,    86,   112,   112,    76,    76,    12,
      12,    12,   118,    40,    87,    38,    12,   123,   118
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
     132,   132,   132,   132,   132,   132,   132,   132,   132
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
       2,     1,     1,     1,     1,     1,     1,     1,     1
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
     818,   819,   820,   821,   822,   823,   824,   825,   826
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
#line 4982 "frontend/parser.cpp"

#line 829 "frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    auto msg = std::to_string(scanner->loc->begin.line) + ":" + std::to_string(scanner->loc->begin.column) + ": " + err_message;
    scanner->fatal_error(ptc::diag::ERR_SYNTAX, msg);
}
