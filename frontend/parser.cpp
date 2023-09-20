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

  case 124: // expr_var: expr_var "**" expr_float
#line 420 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1848 "frontend/parser.cpp"
    break;

  case 125: // expr_var: expr_var "**" expr_var
#line 421 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1854 "frontend/parser.cpp"
    break;

  case 126: // expr_var: expr_int "*" expr_var
#line 423 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1860 "frontend/parser.cpp"
    break;

  case 127: // expr_var: expr_float "*" expr_var
#line 424 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1866 "frontend/parser.cpp"
    break;

  case 128: // expr_var: expr_var "*" expr_int
#line 425 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1872 "frontend/parser.cpp"
    break;

  case 129: // expr_var: expr_var "*" expr_float
#line 426 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1878 "frontend/parser.cpp"
    break;

  case 130: // expr_var: expr_mat "*" expr_mat
#line 427 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1884 "frontend/parser.cpp"
    break;

  case 131: // expr_var: expr_mat "*" expr_var
#line 428 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1890 "frontend/parser.cpp"
    break;

  case 132: // expr_var: expr_var "*" expr_mat
#line 429 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1896 "frontend/parser.cpp"
    break;

  case 133: // expr_var: expr_var "*" expr_var
#line 430 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1902 "frontend/parser.cpp"
    break;

  case 134: // expr_var: expr_int "/" expr_var
#line 432 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1908 "frontend/parser.cpp"
    break;

  case 135: // expr_var: expr_float "/" expr_var
#line 433 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1914 "frontend/parser.cpp"
    break;

  case 136: // expr_var: expr_var "/" expr_int
#line 434 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1920 "frontend/parser.cpp"
    break;

  case 137: // expr_var: expr_var "/" expr_float
#line 435 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1926 "frontend/parser.cpp"
    break;

  case 138: // expr_var: expr_var "/" expr_var
#line 436 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1932 "frontend/parser.cpp"
    break;

  case 139: // expr_var: expr_int "%" expr_var
#line 438 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1938 "frontend/parser.cpp"
    break;

  case 140: // expr_var: expr_float "%" expr_var
#line 439 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1944 "frontend/parser.cpp"
    break;

  case 141: // expr_var: expr_var "%" expr_int
#line 440 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1950 "frontend/parser.cpp"
    break;

  case 142: // expr_var: expr_var "%" expr_float
#line 441 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1956 "frontend/parser.cpp"
    break;

  case 143: // expr_var: expr_var "%" expr_var
#line 442 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1962 "frontend/parser.cpp"
    break;

  case 144: // expr_var: expr_int "+" expr_var
#line 444 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1968 "frontend/parser.cpp"
    break;

  case 145: // expr_var: expr_float "+" expr_var
#line 445 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1974 "frontend/parser.cpp"
    break;

  case 146: // expr_var: expr_var "+" expr_int
#line 446 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1980 "frontend/parser.cpp"
    break;

  case 147: // expr_var: expr_var "+" expr_float
#line 447 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1986 "frontend/parser.cpp"
    break;

  case 148: // expr_var: expr_mat "+" expr_mat
#line 448 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1992 "frontend/parser.cpp"
    break;

  case 149: // expr_var: expr_var "+" expr_mat
#line 449 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1998 "frontend/parser.cpp"
    break;

  case 150: // expr_var: expr_mat "+" expr_var
#line 450 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2004 "frontend/parser.cpp"
    break;

  case 151: // expr_var: expr_var "+" expr_var
#line 451 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2010 "frontend/parser.cpp"
    break;

  case 152: // expr_var: expr_int "-" expr_var
#line 453 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2016 "frontend/parser.cpp"
    break;

  case 153: // expr_var: expr_float "-" expr_var
#line 454 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2022 "frontend/parser.cpp"
    break;

  case 154: // expr_var: expr_var "-" expr_int
#line 455 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2028 "frontend/parser.cpp"
    break;

  case 155: // expr_var: expr_var "-" expr_float
#line 456 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2034 "frontend/parser.cpp"
    break;

  case 156: // expr_var: expr_mat "-" expr_mat
#line 457 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2040 "frontend/parser.cpp"
    break;

  case 157: // expr_var: expr_var "-" expr_mat
#line 458 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2046 "frontend/parser.cpp"
    break;

  case 158: // expr_var: expr_mat "-" expr_var
#line 459 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2052 "frontend/parser.cpp"
    break;

  case 159: // expr_var: expr_var "-" expr_var
#line 460 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2058 "frontend/parser.cpp"
    break;

  case 160: // expr_var: expr_int "<<" expr_var
#line 462 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2064 "frontend/parser.cpp"
    break;

  case 161: // expr_var: expr_var "<<" expr_int
#line 463 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2070 "frontend/parser.cpp"
    break;

  case 162: // expr_var: expr_var "<<" expr_var
#line 464 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2076 "frontend/parser.cpp"
    break;

  case 163: // expr_var: expr_int ">>" expr_var
#line 466 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2082 "frontend/parser.cpp"
    break;

  case 164: // expr_var: expr_var ">>" expr_int
#line 467 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2088 "frontend/parser.cpp"
    break;

  case 165: // expr_var: expr_var ">>" expr_var
#line 468 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2094 "frontend/parser.cpp"
    break;

  case 166: // expr_var: expr_int ">" expr_var
#line 470 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2100 "frontend/parser.cpp"
    break;

  case 167: // expr_var: expr_float ">" expr_var
#line 471 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2106 "frontend/parser.cpp"
    break;

  case 169: // expr_var: expr_var ">" expr_int
#line 473 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2112 "frontend/parser.cpp"
    break;

  case 170: // expr_var: expr_var ">" expr_float
#line 474 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2118 "frontend/parser.cpp"
    break;

  case 171: // expr_var: expr_var ">" expr_str
#line 475 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2124 "frontend/parser.cpp"
    break;

  case 172: // expr_var: expr_var ">" expr_var
#line 476 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2130 "frontend/parser.cpp"
    break;

  case 173: // expr_var: expr_int ">=" expr_var
#line 478 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2136 "frontend/parser.cpp"
    break;

  case 174: // expr_var: expr_float ">=" expr_var
#line 479 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2142 "frontend/parser.cpp"
    break;

  case 176: // expr_var: expr_var ">=" expr_int
#line 481 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2148 "frontend/parser.cpp"
    break;

  case 177: // expr_var: expr_var ">=" expr_float
#line 482 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2154 "frontend/parser.cpp"
    break;

  case 178: // expr_var: expr_var ">=" expr_str
#line 483 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2160 "frontend/parser.cpp"
    break;

  case 179: // expr_var: expr_var ">=" expr_var
#line 484 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2166 "frontend/parser.cpp"
    break;

  case 180: // expr_var: expr_int "<" expr_var
#line 486 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2172 "frontend/parser.cpp"
    break;

  case 181: // expr_var: expr_float "<" expr_var
#line 487 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2178 "frontend/parser.cpp"
    break;

  case 183: // expr_var: expr_var "<" expr_int
#line 489 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2184 "frontend/parser.cpp"
    break;

  case 184: // expr_var: expr_var "<" expr_float
#line 490 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2190 "frontend/parser.cpp"
    break;

  case 185: // expr_var: expr_var "<" expr_str
#line 491 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2196 "frontend/parser.cpp"
    break;

  case 186: // expr_var: expr_var "<" expr_var
#line 492 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2202 "frontend/parser.cpp"
    break;

  case 187: // expr_var: expr_int "<=" expr_var
#line 494 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2208 "frontend/parser.cpp"
    break;

  case 188: // expr_var: expr_float "<=" expr_var
#line 495 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2214 "frontend/parser.cpp"
    break;

  case 190: // expr_var: expr_var "<=" expr_int
#line 497 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2220 "frontend/parser.cpp"
    break;

  case 191: // expr_var: expr_var "<=" expr_float
#line 498 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2226 "frontend/parser.cpp"
    break;

  case 192: // expr_var: expr_var "<=" expr_str
#line 499 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2232 "frontend/parser.cpp"
    break;

  case 193: // expr_var: expr_var "<=" expr_var
#line 500 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2238 "frontend/parser.cpp"
    break;

  case 194: // expr_var: expr_int "==" expr_var
#line 502 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2244 "frontend/parser.cpp"
    break;

  case 195: // expr_var: expr_float "==" expr_var
#line 503 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2250 "frontend/parser.cpp"
    break;

  case 197: // expr_var: expr_bool "==" expr_var
#line 505 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2256 "frontend/parser.cpp"
    break;

  case 198: // expr_var: expr_none "==" expr_var
#line 506 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2262 "frontend/parser.cpp"
    break;

  case 201: // expr_var: expr_var "==" expr_int
#line 509 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2268 "frontend/parser.cpp"
    break;

  case 202: // expr_var: expr_var "==" expr_float
#line 510 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2274 "frontend/parser.cpp"
    break;

  case 203: // expr_var: expr_var "==" expr_str
#line 511 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2280 "frontend/parser.cpp"
    break;

  case 204: // expr_var: expr_var "==" expr_bool
#line 512 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2286 "frontend/parser.cpp"
    break;

  case 205: // expr_var: expr_var "==" expr_none
#line 513 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2292 "frontend/parser.cpp"
    break;

  case 206: // expr_var: expr_var "==" expr_struct
#line 514 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2298 "frontend/parser.cpp"
    break;

  case 207: // expr_var: expr_mat "==" expr_mat
#line 515 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2304 "frontend/parser.cpp"
    break;

  case 208: // expr_var: expr_var "==" expr_mat
#line 516 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2310 "frontend/parser.cpp"
    break;

  case 209: // expr_var: expr_mat "==" expr_var
#line 517 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2316 "frontend/parser.cpp"
    break;

  case 210: // expr_var: expr_var "==" expr_var
#line 518 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2322 "frontend/parser.cpp"
    break;

  case 211: // expr_var: expr_int "!=" expr_var
#line 520 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2328 "frontend/parser.cpp"
    break;

  case 212: // expr_var: expr_float "!=" expr_var
#line 521 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2334 "frontend/parser.cpp"
    break;

  case 215: // expr_var: expr_none "!=" expr_var
#line 524 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2340 "frontend/parser.cpp"
    break;

  case 218: // expr_var: expr_var "!=" expr_int
#line 527 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2346 "frontend/parser.cpp"
    break;

  case 219: // expr_var: expr_var "!=" expr_float
#line 528 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2352 "frontend/parser.cpp"
    break;

  case 220: // expr_var: expr_var "!=" expr_str
#line 529 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2358 "frontend/parser.cpp"
    break;

  case 221: // expr_var: expr_var "!=" expr_bool
#line 530 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2364 "frontend/parser.cpp"
    break;

  case 222: // expr_var: expr_var "!=" expr_none
#line 531 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2370 "frontend/parser.cpp"
    break;

  case 223: // expr_var: expr_var "!=" expr_struct
#line 532 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2376 "frontend/parser.cpp"
    break;

  case 224: // expr_var: expr_mat "!=" expr_mat
#line 533 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2382 "frontend/parser.cpp"
    break;

  case 225: // expr_var: expr_var "!=" expr_mat
#line 534 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2388 "frontend/parser.cpp"
    break;

  case 226: // expr_var: expr_mat "!=" expr_var
#line 535 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2394 "frontend/parser.cpp"
    break;

  case 227: // expr_var: expr_var "!=" expr_var
#line 536 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2400 "frontend/parser.cpp"
    break;

  case 228: // expr_var: expr_int "&" expr_var
#line 538 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2406 "frontend/parser.cpp"
    break;

  case 229: // expr_var: expr_var "&" expr_int
#line 539 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2412 "frontend/parser.cpp"
    break;

  case 230: // expr_var: expr_var "&" expr_var
#line 540 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2418 "frontend/parser.cpp"
    break;

  case 231: // expr_var: expr_int "^" expr_var
#line 542 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2424 "frontend/parser.cpp"
    break;

  case 232: // expr_var: expr_var "^" expr_int
#line 543 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2430 "frontend/parser.cpp"
    break;

  case 233: // expr_var: expr_var "^" expr_var
#line 544 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2436 "frontend/parser.cpp"
    break;

  case 234: // expr_var: expr_int "|" expr_var
#line 546 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2442 "frontend/parser.cpp"
    break;

  case 235: // expr_var: expr_var "|" expr_int
#line 547 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2448 "frontend/parser.cpp"
    break;

  case 236: // expr_var: expr_var "|" expr_var
#line 548 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2454 "frontend/parser.cpp"
    break;

  case 241: // expr_var: expr_none "in" expr_mat
#line 554 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2460 "frontend/parser.cpp"
    break;

  case 243: // expr_var: expr_mat "in" expr_mat
#line 556 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2466 "frontend/parser.cpp"
    break;

  case 248: // expr_var: expr_none "in" expr_var
#line 561 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2472 "frontend/parser.cpp"
    break;

  case 250: // expr_var: expr_mat "in" expr_var
#line 563 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2478 "frontend/parser.cpp"
    break;

  case 251: // expr_var: expr_var "in" expr_str
#line 564 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2484 "frontend/parser.cpp"
    break;

  case 252: // expr_var: expr_var "in" expr_var
#line 565 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2490 "frontend/parser.cpp"
    break;

  case 253: // expr_var: expr_bool "and" expr_var
#line 567 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2496 "frontend/parser.cpp"
    break;

  case 254: // expr_var: expr_var "and" expr_bool
#line 568 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2502 "frontend/parser.cpp"
    break;

  case 255: // expr_var: expr_var "and" expr_var
#line 569 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2508 "frontend/parser.cpp"
    break;

  case 256: // expr_var: expr_bool "or" expr_var
#line 571 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2514 "frontend/parser.cpp"
    break;

  case 257: // expr_var: expr_var "or" expr_bool
#line 572 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2520 "frontend/parser.cpp"
    break;

  case 258: // expr_var: expr_var "or" expr_var
#line 573 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2526 "frontend/parser.cpp"
    break;

  case 263: // expr_var: expr_none "++" expr_struct
#line 579 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2532 "frontend/parser.cpp"
    break;

  case 270: // expr_var: expr_int "++" expr_var
#line 586 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2538 "frontend/parser.cpp"
    break;

  case 271: // expr_var: expr_float "++" expr_var
#line 587 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2544 "frontend/parser.cpp"
    break;

  case 272: // expr_var: expr_str "++" expr_var
#line 588 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2550 "frontend/parser.cpp"
    break;

  case 273: // expr_var: expr_bool "++" expr_var
#line 589 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2556 "frontend/parser.cpp"
    break;

  case 274: // expr_var: expr_none "++" expr_var
#line 590 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2562 "frontend/parser.cpp"
    break;

  case 276: // expr_var: expr_var "++" expr_int
#line 592 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2568 "frontend/parser.cpp"
    break;

  case 277: // expr_var: expr_var "++" expr_float
#line 593 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2574 "frontend/parser.cpp"
    break;

  case 278: // expr_var: expr_var "++" expr_str
#line 594 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2580 "frontend/parser.cpp"
    break;

  case 279: // expr_var: expr_var "++" expr_bool
#line 595 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2586 "frontend/parser.cpp"
    break;

  case 280: // expr_var: expr_var "++" expr_none
#line 596 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2592 "frontend/parser.cpp"
    break;

  case 281: // expr_var: expr_var "++" expr_struct
#line 597 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2598 "frontend/parser.cpp"
    break;

  case 282: // expr_var: expr_var "++" expr_var
#line 598 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2604 "frontend/parser.cpp"
    break;

  case 283: // matrix: "[" "]"
#line 602 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(std::vector<ptc::ir::Expr *>{}); }
#line 2610 "frontend/parser.cpp"
    break;

  case 284: // matrix: "[" matvals "]"
#line 603 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2616 "frontend/parser.cpp"
    break;

  case 285: // matrix: "[" "terminator (\\n or ;)" matvals "]"
#line 604 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2622 "frontend/parser.cpp"
    break;

  case 286: // matrix: "[" matvals "terminator (\\n or ;)" "]"
#line 605 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2628 "frontend/parser.cpp"
    break;

  case 287: // matrix: "[" "terminator (\\n or ;)" matvals "terminator (\\n or ;)" "]"
#line 606 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2634 "frontend/parser.cpp"
    break;

  case 288: // matvals: expr
#line 609 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixValue(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2640 "frontend/parser.cpp"
    break;

  case 289: // matvals: matvals "," expr
#line 610 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2646 "frontend/parser.cpp"
    break;

  case 290: // matvals: matvals "," "terminator (\\n or ;)" expr
#line 611 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[3].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2652 "frontend/parser.cpp"
    break;

  case 291: // expr_mat: matrix
#line 615 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2658 "frontend/parser.cpp"
    break;

  case 292: // expr_mat: "(" matrix ")"
#line 616 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2664 "frontend/parser.cpp"
    break;

  case 293: // range: "(" range ")"
#line 618 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2670 "frontend/parser.cpp"
    break;

  case 294: // range: int_val ".." int_val
#line 619 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseRange(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2676 "frontend/parser.cpp"
    break;

  case 295: // range: int_val "," int_val ".." int_val
#line 620 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseRange(yystack_[4].value.as < ptc::ir::Expr * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2682 "frontend/parser.cpp"
    break;

  case 296: // int_val: expr_int
#line 622 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 2688 "frontend/parser.cpp"
    break;

  case 297: // int_val: expr_var
#line 623 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2694 "frontend/parser.cpp"
    break;

  case 310: // expr_none: "none"
#line 640 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseNone(); }
#line 2700 "frontend/parser.cpp"
    break;

  case 311: // expr_none: "(" "none" ")"
#line 641 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseNone(); }
#line 2706 "frontend/parser.cpp"
    break;

  case 318: // expr_int: "int"
#line 656 "frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 2712 "frontend/parser.cpp"
    break;

  case 319: // expr_int: "-" expr_int
#line 657 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 2718 "frontend/parser.cpp"
    break;

  case 320: // expr_int: "(" expr_int ")"
#line 658 "frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 2724 "frontend/parser.cpp"
    break;

  case 321: // expr_int: "~" expr_int
#line 659 "frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 2730 "frontend/parser.cpp"
    break;

  case 322: // expr_int: expr_int "*" expr_int
#line 660 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 2736 "frontend/parser.cpp"
    break;

  case 323: // expr_int: expr_int "/" expr_int
#line 661 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 2742 "frontend/parser.cpp"
    break;

  case 324: // expr_int: expr_int "%" expr_int
#line 662 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 2748 "frontend/parser.cpp"
    break;

  case 325: // expr_int: expr_int "-" expr_int
#line 663 "frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 2754 "frontend/parser.cpp"
    break;

  case 326: // expr_int: expr_int "+" expr_int
#line 664 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 2760 "frontend/parser.cpp"
    break;

  case 327: // expr_int: expr_int "<<" expr_int
#line 665 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 2766 "frontend/parser.cpp"
    break;

  case 328: // expr_int: expr_int ">>" expr_int
#line 666 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 2772 "frontend/parser.cpp"
    break;

  case 329: // expr_int: expr_int "&" expr_int
#line 667 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 2778 "frontend/parser.cpp"
    break;

  case 330: // expr_int: expr_int "^" expr_int
#line 668 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 2784 "frontend/parser.cpp"
    break;

  case 331: // expr_int: expr_int "|" expr_int
#line 669 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 2790 "frontend/parser.cpp"
    break;

  case 332: // expr_float: "float"
#line 673 "frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 2796 "frontend/parser.cpp"
    break;

  case 333: // expr_float: "-" expr_float
#line 674 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 2802 "frontend/parser.cpp"
    break;

  case 334: // expr_float: "(" expr_float ")"
#line 675 "frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 2808 "frontend/parser.cpp"
    break;

  case 335: // expr_float: expr_float "**" expr_float
#line 676 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2814 "frontend/parser.cpp"
    break;

  case 336: // expr_float: expr_float "**" expr_int
#line 677 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2820 "frontend/parser.cpp"
    break;

  case 337: // expr_float: expr_int "**" expr_float
#line 678 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2826 "frontend/parser.cpp"
    break;

  case 338: // expr_float: expr_float "*" expr_float
#line 679 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 2832 "frontend/parser.cpp"
    break;

  case 339: // expr_float: expr_float "*" expr_int
#line 680 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 2838 "frontend/parser.cpp"
    break;

  case 340: // expr_float: expr_int "*" expr_float
#line 681 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 2844 "frontend/parser.cpp"
    break;

  case 341: // expr_float: expr_float "/" expr_float
#line 682 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 2850 "frontend/parser.cpp"
    break;

  case 342: // expr_float: expr_float "/" expr_int
#line 683 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 2856 "frontend/parser.cpp"
    break;

  case 343: // expr_float: expr_int "/" expr_float
#line 684 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 2862 "frontend/parser.cpp"
    break;

  case 344: // expr_float: expr_float "%" expr_float
#line 685 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2868 "frontend/parser.cpp"
    break;

  case 345: // expr_float: expr_float "%" expr_int
#line 686 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2874 "frontend/parser.cpp"
    break;

  case 346: // expr_float: expr_int "%" expr_float
#line 687 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2880 "frontend/parser.cpp"
    break;

  case 347: // expr_float: expr_float "-" expr_float
#line 688 "frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 2886 "frontend/parser.cpp"
    break;

  case 348: // expr_float: expr_float "-" expr_int
#line 689 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 2892 "frontend/parser.cpp"
    break;

  case 349: // expr_float: expr_int "-" expr_float
#line 690 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 2898 "frontend/parser.cpp"
    break;

  case 350: // expr_float: expr_float "+" expr_float
#line 691 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 2904 "frontend/parser.cpp"
    break;

  case 351: // expr_float: expr_float "+" expr_int
#line 692 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 2910 "frontend/parser.cpp"
    break;

  case 352: // expr_float: expr_int "+" expr_float
#line 693 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 2916 "frontend/parser.cpp"
    break;

  case 353: // expr_str: "string"
#line 697 "frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2922 "frontend/parser.cpp"
    break;

  case 354: // expr_str: "(" expr_str ")"
#line 698 "frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 2928 "frontend/parser.cpp"
    break;

  case 355: // expr_str: expr_str "++" expr_str
#line 699 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 2934 "frontend/parser.cpp"
    break;

  case 356: // expr_str: expr_str "++" expr_int
#line 700 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 2940 "frontend/parser.cpp"
    break;

  case 357: // expr_str: expr_str "++" expr_float
#line 701 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 2946 "frontend/parser.cpp"
    break;

  case 358: // expr_str: expr_str "++" expr_bool
#line 702 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2952 "frontend/parser.cpp"
    break;

  case 359: // expr_str: expr_str "++" expr_none
#line 703 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 2958 "frontend/parser.cpp"
    break;

  case 360: // expr_str: expr_int "++" expr_str
#line 704 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 2964 "frontend/parser.cpp"
    break;

  case 361: // expr_str: expr_int "++" expr_int
#line 705 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 2970 "frontend/parser.cpp"
    break;

  case 362: // expr_str: expr_int "++" expr_float
#line 706 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 2976 "frontend/parser.cpp"
    break;

  case 363: // expr_str: expr_int "++" expr_bool
#line 707 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2982 "frontend/parser.cpp"
    break;

  case 364: // expr_str: expr_int "++" expr_none
#line 708 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 2988 "frontend/parser.cpp"
    break;

  case 365: // expr_str: expr_float "++" expr_str
#line 709 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 2994 "frontend/parser.cpp"
    break;

  case 366: // expr_str: expr_float "++" expr_int
#line 710 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 3000 "frontend/parser.cpp"
    break;

  case 367: // expr_str: expr_float "++" expr_float
#line 711 "frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 3006 "frontend/parser.cpp"
    break;

  case 368: // expr_str: expr_float "++" expr_bool
#line 712 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3012 "frontend/parser.cpp"
    break;

  case 369: // expr_str: expr_float "++" expr_none
#line 713 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 3018 "frontend/parser.cpp"
    break;

  case 370: // expr_str: expr_bool "++" expr_str
#line 714 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 3024 "frontend/parser.cpp"
    break;

  case 371: // expr_str: expr_bool "++" expr_int
#line 715 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 3030 "frontend/parser.cpp"
    break;

  case 372: // expr_str: expr_bool "++" expr_float
#line 716 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 3036 "frontend/parser.cpp"
    break;

  case 373: // expr_str: expr_bool "++" expr_bool
#line 717 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3042 "frontend/parser.cpp"
    break;

  case 374: // expr_str: expr_bool "++" expr_none
#line 718 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 3048 "frontend/parser.cpp"
    break;

  case 375: // expr_str: expr_none "++" expr_str
#line 719 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 3054 "frontend/parser.cpp"
    break;

  case 376: // expr_str: expr_none "++" expr_int
#line 720 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 3060 "frontend/parser.cpp"
    break;

  case 377: // expr_str: expr_none "++" expr_float
#line 721 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 3066 "frontend/parser.cpp"
    break;

  case 378: // expr_str: expr_none "++" expr_bool
#line 722 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3072 "frontend/parser.cpp"
    break;

  case 379: // expr_str: expr_none "++" expr_none
#line 723 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 3078 "frontend/parser.cpp"
    break;

  case 380: // expr_bool: "bool"
#line 727 "frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 3084 "frontend/parser.cpp"
    break;

  case 381: // expr_bool: "(" expr_bool ")"
#line 728 "frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 3090 "frontend/parser.cpp"
    break;

  case 382: // expr_bool: "not" expr_bool
#line 729 "frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 3096 "frontend/parser.cpp"
    break;

  case 383: // expr_bool: expr_bool "or" expr_bool
#line 730 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 3102 "frontend/parser.cpp"
    break;

  case 384: // expr_bool: expr_bool "and" expr_bool
#line 731 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 3108 "frontend/parser.cpp"
    break;

  case 385: // expr_bool: expr_bool "==" expr_bool
#line 733 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 3114 "frontend/parser.cpp"
    break;

  case 386: // expr_bool: expr_int "==" expr_int
#line 734 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 3120 "frontend/parser.cpp"
    break;

  case 387: // expr_bool: expr_int "==" expr_float
#line 735 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 3126 "frontend/parser.cpp"
    break;

  case 388: // expr_bool: expr_float "==" expr_float
#line 736 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 3132 "frontend/parser.cpp"
    break;

  case 389: // expr_bool: expr_float "==" expr_int
#line 737 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 3138 "frontend/parser.cpp"
    break;

  case 390: // expr_bool: expr_str "==" expr_str
#line 738 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 3144 "frontend/parser.cpp"
    break;

  case 391: // expr_bool: expr_none "==" expr_none
#line 739 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 3150 "frontend/parser.cpp"
    break;

  case 392: // expr_bool: expr_bool "!=" expr_bool
#line 741 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 3156 "frontend/parser.cpp"
    break;

  case 393: // expr_bool: expr_int "!=" expr_int
#line 742 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 3162 "frontend/parser.cpp"
    break;

  case 394: // expr_bool: expr_int "!=" expr_float
#line 743 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 3168 "frontend/parser.cpp"
    break;

  case 395: // expr_bool: expr_float "!=" expr_float
#line 744 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 3174 "frontend/parser.cpp"
    break;

  case 396: // expr_bool: expr_float "!=" expr_int
#line 745 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 3180 "frontend/parser.cpp"
    break;

  case 397: // expr_bool: expr_str "!=" expr_str
#line 746 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 3186 "frontend/parser.cpp"
    break;

  case 398: // expr_bool: expr_none "!=" expr_none
#line 747 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 3192 "frontend/parser.cpp"
    break;

  case 399: // expr_bool: expr_int ">" expr_int
#line 749 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 3198 "frontend/parser.cpp"
    break;

  case 400: // expr_bool: expr_int ">" expr_float
#line 750 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 3204 "frontend/parser.cpp"
    break;

  case 401: // expr_bool: expr_float ">" expr_float
#line 751 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 3210 "frontend/parser.cpp"
    break;

  case 402: // expr_bool: expr_float ">" expr_int
#line 752 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 3216 "frontend/parser.cpp"
    break;

  case 403: // expr_bool: expr_str ">" expr_str
#line 753 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 3222 "frontend/parser.cpp"
    break;

  case 404: // expr_bool: expr_int "<" expr_int
#line 755 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 3228 "frontend/parser.cpp"
    break;

  case 405: // expr_bool: expr_int "<" expr_float
#line 756 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 3234 "frontend/parser.cpp"
    break;

  case 406: // expr_bool: expr_float "<" expr_float
#line 757 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 3240 "frontend/parser.cpp"
    break;

  case 407: // expr_bool: expr_float "<" expr_int
#line 758 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 3246 "frontend/parser.cpp"
    break;

  case 408: // expr_bool: expr_str "<" expr_str
#line 759 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 3252 "frontend/parser.cpp"
    break;

  case 409: // expr_bool: expr_int ">=" expr_int
#line 761 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 3258 "frontend/parser.cpp"
    break;

  case 410: // expr_bool: expr_int ">=" expr_float
#line 762 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 3264 "frontend/parser.cpp"
    break;

  case 411: // expr_bool: expr_float ">=" expr_float
#line 763 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 3270 "frontend/parser.cpp"
    break;

  case 412: // expr_bool: expr_float ">=" expr_int
#line 764 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 3276 "frontend/parser.cpp"
    break;

  case 413: // expr_bool: expr_str ">=" expr_str
#line 765 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 3282 "frontend/parser.cpp"
    break;

  case 414: // expr_bool: expr_int "<=" expr_int
#line 767 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 3288 "frontend/parser.cpp"
    break;

  case 415: // expr_bool: expr_int "<=" expr_float
#line 768 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 3294 "frontend/parser.cpp"
    break;

  case 416: // expr_bool: expr_float "<=" expr_float
#line 769 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 3300 "frontend/parser.cpp"
    break;

  case 417: // expr_bool: expr_float "<=" expr_int
#line 770 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 3306 "frontend/parser.cpp"
    break;

  case 418: // expr_bool: expr_str "<=" expr_str
#line 771 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 3312 "frontend/parser.cpp"
    break;

  case 419: // expr_bool: expr_str "in" expr_str
#line 773 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[0].value.as < std::string > ().find(yystack_[2].value.as < std::string > ()) != std::string::npos; }
#line 3318 "frontend/parser.cpp"
    break;

  case 424: // mattype: "identifier" matsq
#line 785 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3324 "frontend/parser.cpp"
    break;

  case 425: // mattype: "'int'" matsq
#line 786 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(INT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3330 "frontend/parser.cpp"
    break;

  case 426: // mattype: "'float'" matsq
#line 787 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(FLOAT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3336 "frontend/parser.cpp"
    break;

  case 427: // mattype: "'string'" matsq
#line 788 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(STRING_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3342 "frontend/parser.cpp"
    break;

  case 428: // mattype: "'bool'" matsq
#line 789 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(BOOL_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3348 "frontend/parser.cpp"
    break;

  case 436: // matsq: "[" "]"
#line 798 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(scanner->parseInt(-1)); }
#line 3354 "frontend/parser.cpp"
    break;

  case 437: // matsq: "[" int_val "]"
#line 799 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 3360 "frontend/parser.cpp"
    break;

  case 438: // matsq: "[" "]" matsq
#line 800 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), scanner->parseInt(-1)); }
#line 3366 "frontend/parser.cpp"
    break;

  case 439: // matsq: "[" int_val "]" matsq
#line 801 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[2].value.as < ptc::ir::Expr * > ()); }
#line 3372 "frontend/parser.cpp"
    break;

  case 440: // type: "'int'" "?"
#line 805 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, true, true); }
#line 3378 "frontend/parser.cpp"
    break;

  case 441: // type: "'float'" "?"
#line 806 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, true, true); }
#line 3384 "frontend/parser.cpp"
    break;

  case 442: // type: "'string'" "?"
#line 807 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, true, true); }
#line 3390 "frontend/parser.cpp"
    break;

  case 443: // type: "'bool'" "?"
#line 808 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, true, true); }
#line 3396 "frontend/parser.cpp"
    break;

  case 444: // type: "identifier" "?"
#line 809 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[1].value.as < std::string > (), true, true); }
#line 3402 "frontend/parser.cpp"
    break;

  case 446: // type: mattype "?"
#line 811 "frontend/parser.yy"
       { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 3408 "frontend/parser.cpp"
    break;

  case 447: // type: "'int'"
#line 812 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, false, true); }
#line 3414 "frontend/parser.cpp"
    break;

  case 448: // type: "'float'"
#line 813 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, false, true); }
#line 3420 "frontend/parser.cpp"
    break;

  case 449: // type: "'string'"
#line 814 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, false, true); }
#line 3426 "frontend/parser.cpp"
    break;

  case 450: // type: "'bool'"
#line 815 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, false, true); }
#line 3432 "frontend/parser.cpp"
    break;

  case 452: // type: "identifier"
#line 817 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[0].value.as < std::string > (), false, true); }
#line 3438 "frontend/parser.cpp"
    break;

  case 454: // type: mattype
#line 819 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 3444 "frontend/parser.cpp"
    break;


#line 3448 "frontend/parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -767;

  const short  Parser ::yytable_ninf_ = -453;

  const short
   Parser ::yypact_[] =
  {
     633,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  1327,    32,
     532,  1941,   338,   -60,  -767,   -51,  -767,    51,  -767,  -767,
    1658,  -767,  -767,    21,    43,    58,    60,    63,    45,    48,
      19,    -5,   129,   518,  -767,  -767,   317,   317,  -767,  -767,
    -767,   135,  -767,  1821,  -767,   237,  -767,  -767,   317,   317,
     317,  1811,  2853,  -767,  1068,   635,   853,  3074,  3212,   729,
     592,    65,   173,     1,   266,   326,  2298,   330,  1068,   635,
     853,  2967,  3023,   866,  1142,  1658,  -767,   326,  -767,     5,
     504,   504,  -767,  -767,  -767,  -767,  2040,   300,  3097,  3235,
    2238,  -767,   338,   338,  -767,   273,   288,  -767,  1159,  -767,
     303,   483,   355,  -767,   355,  -767,   355,  -767,   355,  -767,
     134,  -767,   370,   469,   106,  1658,   355,  -767,  -767,  -767,
    1216,  1658,  -767,  -767,  -767,  2716,  -767,  -767,  -767,  -767,
    -767,  1658,   394,  2623,  -767,  -767,   321,  1658,  -767,  -767,
    -767,  1658,  1658,  1658,  1658,  1658,  1658,  1658,  1658,  1658,
    1658,  1658,  1658,  1658,  -767,   978,  1216,  1658,  1658,  1658,
    1658,  1658,  1658,  1658,  1658,  1658,  1658,  1658,  1658,  1658,
    1658,  1658,  1658,  1658,  1658,  1658,  1658,  1658,  1658,  -767,
    1216,  1658,  1658,  1658,  1658,  1658,  1658,  -767,  1658,  1658,
    1658,  1658,  1658,  1658,  1658,  1658,  1658,  1658,  1658,  1658,
    1658,   504,  1658,  1658,  1658,  1658,  1658,  1658,  1658,  1658,
    1658,  1658,  1658,  1658,  1658,  1658,  1658,  1658,  1658,  1658,
    1658,  1658,  1658,  1658,  1658,  1658,  1658,  1658,  1658,  1658,
    1658,  1658,  1658,  1658,  1658,  1658,  1658,  1658,  1658,  1658,
    1658,  1658,  1658,  1658,   355,  -767,  -767,    70,    73,   406,
    -767,  1216,   419,  -767,  -767,  -767,  -767,  -767,  -767,   131,
     474,  -767,    59,  3270,  1455,   504,   504,   504,   504,   504,
     338,   338,   338,   338,   338,   504,   504,   504,   504,   504,
     504,  2552,  3051,  1479,  1469,  1941,   369,   369,  1941,   504,
     504,   504,   504,   504,   504,  1941,   504,   504,   504,   504,
     504,   504,  1941,  1941,  1941,  1941,  1941,  1941,  1941,  1941,
    1941,  1941,  1941,  1941,  1941,  2226,  -767,   338,   338,   338,
     338,   338,  1658,   -51,    18,   456,   461,     3,  1658,   355,
    2853,   494,  3074,  3212,   729,   592,  -767,  -767,  -767,  -767,
     498,   304,   609,   594,    16,  -767,   454,   521,    22,  3074,
    -767,    89,    22,  -767,   522,  2716,  -767,  2456,   529,   530,
    -767,  3260,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,  -767,  -767,   238,  -767,   232,   547,   121,
     896,   958,   547,   121,   896,   958,   305,   520,   523,   524,
     305,   523,   524,   305,   523,   524,   305,   524,  2910,   537,
     683,  3120,  2086,  1277,   217,  2337,   689,  2939,   650,  2795,
     517,  2719,  2822,  1344,  3166,  2581,  3189,   236,  1165,   236,
    1165,  1991,   347,  -767,  -767,  2262,  1895,   593,  -767,  1991,
     347,  -767,  -767,  2262,  1895,   593,  -767,  1779,  1675,  1390,
     544,  1779,  1675,  1390,   544,  1779,  1675,  1390,   544,  1779,
    1675,  1390,   544,    22,   267,   547,   121,   547,   121,   305,
     520,  2795,   947,  1991,   347,  1991,   347,  2910,   537,   683,
    3120,  2086,  1277,   217,  2795,   947,  1991,  -767,  1991,  -767,
    2910,   537,   683,  3120,  2086,  1277,   217,  2795,   947,  1991,
    -767,  1991,  -767,   547,   896,   958,   547,   896,   958,   305,
     523,   524,   305,   523,   524,   305,   523,   524,  2164,   548,
    2910,   537,   683,  3120,  2086,  1277,   217,  2795,   947,  2719,
    2822,  1344,  3166,  2581,  3189,   236,  1165,   236,  1165,  1991,
    2262,  1895,  1991,  2262,  1895,  1779,  1675,  1390,  1779,  1675,
    1390,  1779,  1675,  1390,  1779,  1675,  1390,   547,   896,   958,
     547,   896,   958,   305,   523,   524,   305,   523,   524,   305,
     523,   524,   305,   523,   524,  2910,   537,   683,  3120,  2086,
    1277,   217,  2795,   947,  1991,  2262,  1895,  1991,  2262,  1895,
    1779,  1675,  1390,  1779,  1675,  1390,  1779,  1675,  1390,  1779,
    1675,  1390,   545,  2910,   537,   683,  3120,  2086,  1277,   217,
    2795,   947,   517,  1991,   593,  1991,   593,  1779,   544,  1779,
     544,  1779,   544,  1779,   544,  2910,   537,   683,  3120,  2086,
    1277,   217,  2337,   689,  2939,   650,  2795,   947,  1991,  -767,
    1991,  -767,  -767,  -767,   111,   562,     2,  1083,   663,   314,
    -767,   566,  -767,  -767,  1658,  -767,  1023,  1115,  1023,  1115,
     523,   548,   523,   548,   523,   548,  1936,  2060,  2364,   832,
     832,  1023,  1115,  1023,  1115,   523,   548,   523,   548,   523,
     548,   523,   548,   468,  3143,  3242,  1960,   482,   585,  -767,
    -767,   468,  3143,  3242,  1960,   482,  2127,  1626,  2127,  1626,
    2127,  1626,  2127,  1626,  2127,  1626,  2127,  1626,   468,  3143,
    3242,  1960,   482,  2127,  1626,  2127,  1626,  2127,  1626,  2127,
    1626,  2127,  1626,  2127,  1626,   468,  3143,  3242,  1960,   482,
    1738,   349,  1168,  1168,  -767,  -767,  -767,  -767,   468,  3143,
    3242,  1960,   482,   484,   450,  -767,  -767,    34,    34,  -767,
    -767,  -767,  -767,  -767,  1672,  1672,  1672,  -767,  -767,  -767,
     355,    47,    47,  -767,   531,   582,   608,    13,   333,   540,
     557,   610,    14,  -767,  1244,   315,    38,  1132,   579,  -767,
    -767,  1821,  2487,   619,  1658,  1821,  -767,  1658,  -767,  -767,
    -767,  -767,   701,  -767,  -767,   333,   616,  -767,  -767,  -767,
     266,  1703,   621,  2388,   622,   284,  2995,   636,   638,   640,
     645,  -767,   631,  -767,   617,  -767,    47,   627,  -767,  -767,
     281,   333,  -767,  -767,   646,  -767,  1270,  -767,  1536,   318,
    1658,  -767,   658,  -767,   654,   614,  -767,  -767,  -767,   333,
    2298,   667,  2967,  1821,  1821,  1658,  1658,  1821,  1821,  1821,
    1821,  -767,  1658,  -767,  1658,   611,    15,  -767,  -767,  -767,
     672,  -767,   676,  -767,  1563,   653,  -767,  -767,  -767,  -767,
    1821,  -767,  -767,  -767,  -767,  -767,  -767,  -767,   673,  -767,
    -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,
     700,   674,  -767,  1658,  -767,  -767,  -767
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     9,   318,   332,   353,   380,   310,     0,     0,
       0,     0,     0,     0,   451,     0,    53,     0,    47,    49,
      38,    35,    36,     0,   447,   448,   449,   450,     0,     0,
     104,   105,     0,     0,     4,    10,     0,     0,    37,    15,
      17,     0,    18,     0,    16,     0,    19,    20,     0,     0,
       0,     0,    97,   291,    96,    98,    99,   100,   101,   102,
     103,   453,   454,     0,   310,   104,     0,   291,     0,     0,
       0,     0,     0,     0,     0,     0,   283,   104,   288,     0,
       0,     0,   106,   107,   319,   333,     0,     0,     0,     0,
       0,   382,     0,     0,   321,     0,    33,    32,     0,    39,
       0,     0,   440,   425,   441,   426,   442,   427,   443,   428,
       0,    69,     0,     0,     0,     0,   444,   117,   312,   424,
       0,     0,   118,     1,     3,     0,     5,     8,     7,    14,
      21,     0,     0,     0,    30,    31,     0,     0,    12,    13,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   119,
       0,     0,     0,     0,     0,     0,     0,   116,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   445,   429,   446,     0,    75,     0,
     311,     0,   312,   108,   292,   320,   334,   354,   381,     0,
       0,   284,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   319,     0,     0,     0,
       0,     0,     0,     0,   452,     0,     0,     0,     0,   436,
     297,     0,   296,     0,     0,     0,   431,   432,   433,   434,
       0,     0,     0,     0,     0,   314,     0,     0,   120,     0,
     430,     0,   121,     6,     0,     0,    23,     0,     0,     0,
      93,    92,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,   109,     0,    94,     0,   151,   149,
     146,   147,   159,   157,   154,   155,   133,   132,   128,   129,
     138,   136,   137,   143,   141,   142,   125,   124,   282,   280,
     281,   276,   277,   278,   279,   255,   254,   258,   257,   252,
     251,   230,   229,   236,   235,   233,   232,   162,   161,   165,
     164,   210,   208,   205,   206,   201,   202,   203,   204,   227,
     225,   222,   223,   218,   219,   220,   221,   172,   169,   170,
     171,   186,   183,   184,   185,   179,   176,   177,   178,   193,
     190,   191,   192,   122,     0,   150,   148,   158,   156,   131,
     130,   250,   243,   209,   207,   226,   224,   274,   379,   263,
     376,   377,   375,   378,   248,   241,   198,   391,   215,   398,
     275,   268,   269,   264,   265,   266,   267,   249,   242,   200,
     199,   217,   216,   144,   326,   352,   152,   325,   349,   126,
     322,   340,   134,   323,   343,   139,   324,   346,     0,   337,
     270,   364,   259,   361,   362,   360,   363,   244,   237,   228,
     329,   234,   331,   231,   330,   160,   327,   163,   328,   194,
     386,   387,   211,   393,   394,   166,   399,   400,   180,   404,
     405,   173,   409,   410,   187,   414,   415,   145,   351,   350,
     153,   348,   347,   127,   339,   338,   135,   342,   341,   140,
     345,   344,   123,   336,   335,   271,   369,   260,   366,   367,
     365,   368,   245,   238,   195,   389,   388,   212,   396,   395,
     167,   402,   401,   181,   407,   406,   174,   412,   411,   188,
     417,   416,     0,   272,   359,   261,   356,   357,   355,   358,
     246,   239,   419,   196,   390,   213,   397,   168,   403,   182,
     408,   175,   413,   189,   418,   273,   374,   262,   371,   372,
     370,   373,   253,   384,   256,   383,   247,   240,   197,   385,
     214,   392,   435,   421,   452,     0,   422,     0,     0,     0,
     313,     0,   285,   286,     0,   289,   326,   352,   325,   349,
     322,   340,   323,   343,   324,   346,   329,   331,   330,   327,
     328,   351,   350,   348,   347,   339,   338,   342,   341,   345,
     344,   336,   335,   379,   376,   377,   375,   378,     0,   391,
     398,   364,   361,   362,   360,   363,   386,   387,   393,   394,
     399,   400,   404,   405,   409,   410,   414,   415,   369,   366,
     367,   365,   368,   389,   388,   396,   395,   402,   401,   407,
     406,   412,   411,   417,   416,   359,   356,   357,   355,   358,
     419,     0,   390,   397,   403,   408,   413,   418,   374,   371,
     372,   370,   373,   384,   383,   385,   392,   326,   325,   322,
     323,   324,    79,    34,     0,     0,     0,    75,    78,   438,
     437,     0,    58,    55,     0,     0,     0,     0,     0,     0,
      74,     0,     0,   298,     0,     0,   113,     0,     0,   315,
     114,     0,     0,    24,     0,     0,   110,     0,   115,   112,
     111,   420,     0,    77,    76,     0,     0,   113,   287,   290,
       0,     0,     0,   297,     0,     0,   296,     0,     0,     0,
       0,   439,     0,    59,     0,    56,    60,    62,    67,    72,
       0,     0,    70,   302,     0,   300,     0,   299,     0,     0,
       0,    46,    25,    26,     0,    52,    95,   423,    65,     0,
     297,     0,   296,     0,     0,     0,     0,     0,     0,     0,
       0,    57,     0,    61,     0,     0,     0,    68,   305,   304,
       0,   303,     0,   301,     0,   316,    27,    48,    54,    50,
       0,    66,   293,    28,    29,    41,    44,   294,     0,    42,
      45,    40,    43,    64,    63,    73,    71,   308,   307,   306,
       0,     0,    51,     0,   309,   317,   295
  };

  const short
   Parser ::yypgoto_[] =
  {
    -767,  -767,  -118,   774,   -26,   291,   -30,   231,  -766,  -767,
     396,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,  -725,  -767,  -767,   662,  -767,    79,   629,
    -767,   589,  -767,  2023,   228,     6,   656,  1831,  -699,   383,
     936,  1614,  2074,   -64,  -139,    -8,   643,   884,  1296,  -767,
     -39,  -767,    -6,    27
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    32,    33,   129,    34,    35,   864,   865,   136,    36,
      97,    37,    38,    39,    40,    41,    42,    43,    44,   859,
      45,   860,    46,   755,   756,    47,   112,   760,   761,    48,
      49,    50,   375,    51,    52,    53,    79,    68,   794,   795,
     179,    69,    70,   118,   347,    57,   333,   334,   335,    61,
     635,    62,   119,    63
  };

  const short
   Parser ::yytable_[] =
  {
      71,   252,    84,    88,    94,   821,   120,   126,   260,   825,
     247,   247,   247,   135,    67,   357,    95,   261,   103,   105,
     107,   109,   247,   247,   247,    96,   802,   803,   766,   101,
     113,   155,   114,   156,   121,    75,     3,     4,     5,     6,
       7,     8,   782,     9,    76,   262,   798,   800,    10,   101,
     752,   319,   320,   321,   101,   245,    11,   767,   115,   744,
      98,    12,   644,     3,     4,     5,     6,     7,     8,   101,
       9,   101,   263,    84,   101,    10,   101,   248,   281,   747,
     633,   843,   -69,    11,   315,   316,   116,   116,    12,   807,
     812,   876,   831,   332,   882,  -452,   336,   100,   337,   353,
     338,   770,   339,   754,    14,   332,  -437,   349,    77,    31,
     350,   102,   332,   349,  -437,   637,    24,    25,    26,    27,
     345,   110,   101,   634,   111,   327,   104,    14,   106,   123,
     767,   108,   180,   244,   641,    77,    31,   340,   183,    24,
      25,    26,    27,   642,   131,   346,   634,   341,   332,   380,
     384,   388,   391,   394,   349,   401,   349,   349,   349,   412,
     414,   416,   418,   420,   425,   433,   438,   442,   446,   450,
     349,   262,   332,   349,   349,   349,   349,   349,   349,   116,
     470,   349,   349,   349,   483,   349,   349,   349,   494,   497,
     500,   503,   506,   508,   513,   349,   520,   522,   524,   526,
     528,   530,   533,   536,   539,   542,   545,   548,   551,   554,
     557,   560,   563,   568,   349,   575,   578,   581,   584,   587,
     590,   332,   596,   349,   349,   349,   349,   349,   349,   349,
     618,   349,   349,   349,   349,   349,    66,   772,   632,   239,
     240,   246,   241,   332,   778,   155,   137,   156,   776,   242,
     243,   157,   158,   159,   160,   161,   162,   646,   648,   650,
     652,   654,   656,   657,   658,   659,   660,   661,   663,   665,
     667,   669,   671,   767,   636,   178,   250,   674,   777,   779,
     682,   686,   688,   690,   692,   694,   696,   699,   703,   705,
     707,   709,   711,   713,   716,    88,    88,    88,    88,    88,
      88,    88,   729,    88,    88,    88,    88,   752,   767,   737,
     738,   739,   740,   741,   155,   322,   156,   127,   753,   845,
     128,   285,   835,   749,   836,   162,   787,   815,   323,   330,
     853,   126,   286,   287,   134,   332,   132,   251,    14,   114,
     254,   330,     3,   348,   178,   328,   133,    92,   330,   352,
      24,    25,    26,    27,    93,   767,   816,   634,   180,   854,
     754,    14,   181,   182,   183,   115,   101,    12,   757,   762,
     310,   311,   312,    24,    25,    26,    27,     7,   678,   342,
     634,   313,   314,   358,   330,   378,   382,   386,   390,   393,
     396,   398,   405,   407,   409,   411,   413,   415,   417,   419,
     421,   429,   437,   441,   445,   449,   453,   355,   330,   455,
     457,   459,   461,   463,   465,   638,   467,   474,   476,   478,
     480,   487,   489,   491,   493,   496,   499,   502,   505,   640,
     510,   517,   519,   521,   523,   525,   527,   529,   532,   535,
     538,   541,   544,   547,   550,   553,   556,   559,   562,   565,
     572,   574,   577,   580,   583,   586,   589,   330,   593,   600,
     603,   605,   607,   609,   611,   613,   615,   622,   624,   626,
     628,   630,   311,     3,     4,     5,     6,     7,     8,   330,
       9,   329,   313,   314,   331,    10,   643,     3,     4,     5,
       6,     7,     8,    11,     9,   329,   344,   745,    12,    10,
     286,   287,   746,   351,   311,   312,   750,    11,     3,     4,
     343,   751,    12,    80,   313,   314,   313,   314,   124,   125,
      81,     2,     3,     4,     5,     6,     7,     8,   229,     9,
     768,   180,   771,    12,    10,   769,     3,     4,   774,   377,
     775,    80,    11,   201,   220,    77,    31,    12,    81,   232,
     233,   234,   235,   236,   237,   229,   155,   780,   156,    77,
      31,    12,   189,   454,   159,   160,   161,   162,   280,   190,
     191,   330,   781,   784,    13,    14,    15,    16,   788,    17,
      18,    19,    20,    21,    22,    23,   178,    24,    25,    26,
      27,    28,    29,   790,    30,    31,   805,   810,     3,     4,
       5,     6,     7,     8,   229,     9,   763,   804,    82,    83,
      10,   806,   592,   238,   239,   240,   809,   241,    11,   758,
     811,   820,   823,    12,   242,   243,   829,   234,   235,   236,
     237,   833,   834,     1,   639,   764,     2,     3,     4,     5,
       6,     7,     8,    58,     9,   841,   837,   759,   838,    10,
     839,    72,    58,    85,    89,   840,   188,    11,   848,   842,
     189,   856,    12,    58,   857,   762,    14,   190,   191,   844,
      77,    31,   239,   785,   858,   241,    58,   862,    24,    25,
      26,    27,   242,   243,   877,   634,    58,   875,   878,    13,
      14,    15,    16,   881,    17,    18,    19,    20,    21,    22,
      23,   759,    24,    25,    26,    27,    28,    29,   193,    30,
      31,   883,   884,   346,   241,   194,   195,   786,    58,   743,
      14,   242,   243,   264,    85,   249,   765,   326,   808,   282,
     360,   259,    24,    25,    26,    27,   796,   796,   796,   634,
     229,   135,   885,   827,   801,   135,   126,     0,     0,     0,
     230,     0,     0,     0,   231,   828,   332,     0,    14,   332,
     801,   232,   233,   234,   235,   236,   237,     0,    58,     0,
      24,    25,    26,    27,    58,     0,    58,   634,   757,   757,
      58,   847,     0,   832,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    67,    58,   861,
     381,   385,   389,   392,   395,   397,   402,     0,   332,   636,
     332,   130,     0,     0,     0,   426,   434,   439,   443,   447,
     451,     0,   138,   139,   140,   154,     0,   332,   332,     0,
     135,   471,     0,   757,     0,   484,     0,   846,     0,   495,
     498,   501,   504,   507,   509,   514,   332,   317,   318,   319,
     320,   321,   531,   534,   537,   540,   543,   546,   549,   552,
     555,   558,   561,   564,   569,     0,   576,   579,   582,   585,
     588,   591,     0,   597,   192,   332,   257,   229,   193,     0,
       0,   619,     0,     0,    59,   194,   195,   230,     0,     0,
       0,   231,    73,    59,     0,    90,     0,     0,   232,   233,
     234,   235,   236,   237,    59,    58,     0,     0,   647,   649,
     651,   653,   655,   198,   199,   200,   201,    59,   662,   664,
     666,   668,   670,   672,     0,     0,     0,    59,   675,     0,
       0,   683,   687,   689,   691,   693,   695,   697,   700,   704,
     706,   708,   710,   712,   714,   717,    89,    89,    89,    89,
      89,    89,    89,   730,    89,    89,    89,    89,   180,    59,
       0,     0,   181,   182,   183,    58,   117,   122,     0,     0,
     283,    58,   793,   793,   793,   217,   218,   219,   220,   185,
     186,     0,     3,     4,     5,     6,     7,     8,   374,     9,
     187,     0,   330,     0,    10,   330,     0,     0,    58,     0,
      58,   117,    11,     0,   187,     0,     0,    12,     0,    59,
       0,     0,     0,   117,     0,    59,     0,    59,     0,   830,
       0,    59,     0,     0,     0,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,     0,    59,
     267,   268,   269,   201,   330,     0,   330,   403,     0,     0,
     410,     0,     0,     0,    77,    31,   427,   435,   440,   444,
     448,   452,   134,   330,   330,   866,   134,     0,   869,   870,
     871,   872,   472,     0,     0,     0,   485,     0,     0,   180,
       0,     0,   330,   181,   182,   183,   515,     3,     4,     5,
       6,     7,     8,   184,     9,     0,   114,     0,     0,    10,
     185,   186,     0,     0,     0,   570,     0,    11,     0,     0,
       0,   330,    12,     0,   598,   602,   604,   606,   608,   610,
     612,   614,   620,     0,   863,   863,     0,     0,   863,   863,
     863,   863,   277,   278,   279,   280,     3,     4,     5,     6,
       7,     8,     0,     9,   817,     0,    59,   814,    10,     0,
     819,   134,   258,     0,     0,     0,    11,     0,     0,    77,
      31,    12,     0,   238,   239,   240,     0,   241,     0,   676,
       0,     0,   684,   818,   242,   243,     0,     0,     0,   701,
     196,   197,   198,   199,   200,   201,   718,   720,   722,   723,
     724,   725,   726,   727,   731,    90,    90,    90,    90,   850,
       0,   852,   306,   307,   308,   309,    59,     0,    77,    31,
       0,     0,    59,     0,     0,     0,    14,     0,   867,   868,
       3,     4,     5,     6,     7,     8,     0,     9,    24,    25,
      26,    27,    10,     0,     0,   324,   325,   880,     0,    59,
      11,    59,     0,     0,     0,    12,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     9,   813,   343,     0,     0,
      10,     0,     0,     0,     0,     0,   886,     0,    11,     0,
       0,     0,     0,    12,     3,     4,     5,     6,     7,     8,
      58,     9,   849,     0,     0,     0,    10,    58,   229,     0,
       0,     0,    77,    31,    11,     0,    60,     0,     0,    12,
       0,     0,   231,     0,    74,    60,     0,    91,     0,   232,
     233,   234,   235,   236,   237,   187,    60,     0,     0,   187,
      77,    31,     0,   187,     0,     0,     0,     0,     0,    60,
       0,     3,     4,     5,     6,    64,     8,     0,     9,    60,
       0,     0,     0,    10,     0,     0,    77,    31,     0,     0,
       0,    11,     0,   155,     0,   156,    12,     0,   187,   157,
     158,   159,   160,   161,   162,     0,   187,     0,     0,     0,
     167,    60,   169,     0,   170,   171,   172,   173,   174,   175,
     176,   177,   284,   178,     0,     0,     0,    58,    58,    58,
       0,     0,   187,     0,   187,     0,   187,     0,   187,     0,
     187,     0,   187,    65,    31,   215,   216,   217,   218,   219,
     220,   187,     0,     0,    58,    58,     0,    58,    58,     0,
      58,    60,     0,     0,   187,     0,     0,    60,     0,    60,
       0,     0,     0,    60,    72,     0,     0,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
       0,    60,     0,     0,   187,     0,     0,     0,     0,   404,
     406,   408,     0,    58,     0,   256,     0,     0,   428,   436,
     275,   276,   277,   278,   279,   280,    58,    58,     0,   258,
      58,    58,    58,    58,   473,    58,     0,    58,   486,   257,
     310,   311,   312,     0,     0,     0,     0,     0,   516,     0,
     302,   313,   314,    58,   303,     0,     0,     0,     0,   187,
       0,   304,   305,   306,   307,   308,   309,   571,     0,     0,
       0,    59,     0,     0,     0,     0,   599,     0,    59,     0,
       0,     0,     0,     0,   621,   623,   625,   187,   629,   631,
       3,     4,     5,     6,     7,     8,     0,     9,   851,     0,
       0,     0,    10,     0,     0,     0,     0,     0,    60,     0,
      11,     0,     0,   187,     0,    12,     0,     3,     4,     5,
       6,     7,     8,     0,     9,   879,     0,     0,     0,    10,
       0,   677,     0,     0,   685,     0,     0,    11,     0,     0,
       0,   702,    12,     0,     0,     0,     0,     0,   719,   721,
     721,   721,   721,   721,   721,   721,   732,   733,   734,   735,
     736,     0,    77,    31,    55,     0,     0,     0,    60,     0,
       0,     0,     0,    55,    60,    87,     0,     0,    59,    59,
      59,     0,     0,     0,    55,     0,     0,     0,     0,    77,
      31,   275,   276,   277,   278,   279,   280,    55,     0,     0,
       0,    60,     0,    60,     0,    59,    59,    55,    59,    59,
       0,    59,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,     0,     0,    10,    73,     3,     4,     5,     6,
       7,   791,    11,     9,     0,     0,     0,    12,    10,    55,
     196,   197,   198,   199,   200,   201,    11,     0,     0,     0,
      87,    12,     0,     0,    59,   207,   208,     3,     4,     5,
       6,    64,   791,     0,     9,     0,     0,    59,    59,    10,
       0,    59,    59,    59,    59,     0,    59,    11,    59,     0,
       0,     0,    12,     0,    77,    31,     0,     0,     0,    55,
       0,     0,     0,     0,    59,    55,     0,    55,    77,    31,
       0,    55,     0,     0,     0,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,     0,    55,
     304,   305,   306,   307,   308,   309,     0,   399,     0,    65,
      31,     0,     0,     0,     0,     0,   423,   431,   155,     0,
     156,     0,     0,     0,   157,   158,   159,   160,   161,   162,
       0,     0,   468,     0,   477,   479,   481,     0,     0,   170,
     171,   127,     0,     0,   128,     0,   511,     0,   178,     0,
       0,     0,     0,     0,   132,     3,     4,     5,     6,     7,
       8,    54,     9,     0,   133,   566,     0,    10,     0,     0,
      54,     0,     0,     0,   594,    11,     0,     0,     0,     0,
      12,    54,   616,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,    54,   152,   153,     0,     0,     0,
       0,     0,     0,     0,    54,     0,    55,    13,    14,    15,
      16,     0,    17,    18,    19,    20,    21,    22,    23,     0,
      24,    25,    26,    27,    28,    29,     0,    30,    31,   673,
     679,   680,   681,     0,     0,     0,    54,     0,     0,   698,
     215,   216,   217,   218,   219,   220,   715,    87,    87,    87,
      87,    87,    87,    87,   728,    87,    87,    87,    87,   225,
     226,   227,   228,    60,     0,     0,    55,     0,     0,     0,
      60,     0,    55,     0,     0,     3,     4,     5,     6,     7,
      86,   317,   318,   319,   320,   321,    54,    81,     0,     0,
       0,     0,    54,     0,    54,    11,   273,   274,    54,    55,
      12,    55,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,   303,    54,     0,   379,   383,
     387,     0,   304,   305,   306,   307,   308,   309,     0,     0,
     155,     0,   156,   422,   430,     0,   157,   158,   159,   160,
     161,   162,   456,   458,   460,   462,   464,   466,     0,     0,
     475,   170,   171,     0,   488,   174,   175,   176,   177,     0,
     178,     0,    78,     0,   518,     0,     0,     0,     0,     0,
      60,    60,    60,    99,     3,     4,     5,     6,    64,    86,
       0,     0,     0,   573,     0,     0,    81,     0,     0,     0,
       0,     0,   601,     0,    11,     0,     0,    60,    60,    12,
      60,    60,   627,    60,    56,   317,   318,   319,   320,   321,
       0,     0,     0,    56,     0,     0,   270,    74,   272,     0,
     273,   274,     0,    54,    56,     0,     0,     0,    78,     0,
       0,   215,   216,   217,   218,   219,   220,    56,     0,     0,
       0,   222,     0,     0,     0,     0,    60,    56,   223,   224,
     225,   226,   227,   228,     0,     0,     0,     0,     0,    60,
      60,     0,     0,    60,    60,    60,    60,     0,    60,     0,
      60,     0,   265,   266,   267,   268,   269,   201,     0,    56,
       0,     0,     0,    54,   354,     0,    60,   273,   274,    54,
     359,     0,     0,     0,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,     0,   376,   265,
     266,   267,   268,   269,   201,     0,    54,     0,    54,     0,
     270,   271,   272,     0,   273,   274,     0,     0,     0,    56,
       0,     0,     0,     0,     0,    56,     0,    56,     0,     0,
       0,    56,     0,     0,     0,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,     0,    56,
       0,     0,     0,     0,     0,     0,   255,   400,     0,     0,
       0,   317,   318,   319,   320,   321,   424,   432,     0,     0,
       0,    55,   270,   271,   272,     0,   273,   274,    55,   302,
       0,     0,   469,   303,     0,     0,   482,     0,   490,   492,
     304,   305,   306,   307,   308,   309,   512,   196,   197,   198,
     199,   200,   201,     0,     0,   645,     0,     0,     0,     0,
       0,     0,   207,   208,     0,   567,   211,   212,   213,   214,
       0,     0,     0,     0,   595,     0,     0,   155,   253,   156,
       0,     0,   617,   157,   158,   159,   160,   161,   162,   163,
     164,   165,     0,   166,   167,   168,   169,     0,   170,   171,
     172,   173,   174,   175,   176,   177,    56,   178,     0,     0,
       0,     0,     0,     0,     0,   742,   155,     0,   156,     0,
       0,   748,   157,   158,   159,   160,   161,   162,    55,    55,
      55,     0,   166,   167,   168,   169,     0,   170,   171,   172,
     173,   174,   175,   176,   177,     0,   178,     0,     0,   317,
     318,   319,   320,   321,     0,    55,    55,     0,    55,    55,
     270,    55,     0,     0,   273,   274,    56,   155,   -97,   156,
       0,     0,    56,   157,   158,   159,   160,   161,   162,   163,
     164,   165,     0,   166,   167,   168,   169,     0,   170,   171,
     172,   173,   174,   175,   176,   177,     0,   178,     0,    56,
       0,    56,     0,     0,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,    55,     0,
       0,    55,    55,    55,    55,     0,    55,   125,    55,     2,
       3,     4,     5,     6,     7,     8,     0,     9,    54,     0,
     773,     0,    10,     0,    55,    54,     0,     0,     0,     0,
      11,     0,     0,     0,     0,    12,     0,     0,   125,     0,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,   822,     0,    10,     0,     0,     0,     0,     0,     0,
       0,    11,    13,    14,    15,    16,    12,    17,    18,    19,
      20,    21,    22,    23,     0,    24,    25,    26,    27,    28,
      29,     0,    30,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    14,    15,    16,     0,    17,    18,
      19,    20,    21,    22,    23,     0,    24,    25,    26,    27,
      28,    29,   255,    30,    31,     0,     0,   265,   266,   267,
     268,   269,   201,   288,     0,    54,    54,    54,   270,   271,
     272,     0,   273,   274,   289,   290,   291,   292,   293,   294,
     155,     0,   156,     0,     0,     0,   157,   158,   159,   160,
     161,   162,    54,    54,     0,    54,    54,   167,    54,     0,
       0,   170,   171,   172,   173,   174,   175,   176,   177,     0,
     178,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,   356,     0,    10,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     0,
       0,    54,    12,     0,     0,     0,     0,     0,     0,     0,
     783,     0,     0,     0,    54,    54,     0,   789,    54,    54,
      54,    54,     0,    54,     0,    54,     0,     0,     0,    13,
      14,    15,    16,     0,    17,    18,    19,    20,    21,    22,
      23,    54,    24,    25,    26,    27,    28,    29,     0,    30,
      31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    56,     0,     0,     0,     0,     0,     0,    56,     2,
       3,     4,     5,     6,     7,     8,     0,     9,   155,     0,
     156,     0,    10,     0,   157,   158,   159,   160,   161,   162,
      11,     0,     0,     0,     0,    12,     0,     0,     0,   170,
     171,   172,   173,   174,   175,   176,   177,     0,   178,     0,
       0,     0,     0,     0,     0,     0,     0,   792,   797,   799,
       0,     0,    13,    14,    15,    16,     0,    17,    18,    19,
      20,    21,    22,    23,     0,    24,    25,    26,    27,    28,
      29,     0,    30,    31,     0,     0,     0,   824,     0,     0,
     826,     0,     0,     0,   155,     0,   156,     0,     0,     0,
     157,   158,   159,   160,   161,   162,     0,     0,    56,    56,
      56,   167,   168,   169,     0,   170,   171,   172,   173,   174,
     175,   176,   177,     0,   178,     0,     0,   196,   197,   198,
     199,   200,   201,   855,     0,    56,    56,     0,    56,    56,
       0,    56,   207,   208,   209,   210,   211,   212,   213,   214,
       0,     0,   155,     0,   156,   873,     0,   874,   157,   158,
     159,   160,   161,   162,   163,   164,   165,     0,   166,   167,
     168,   169,     0,   170,   171,   172,   173,   174,   175,   176,
     177,     0,   178,     0,    56,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    56,    56,     0,
       0,    56,    56,    56,    56,     0,    56,     0,    56,   155,
       0,   156,     0,     0,     0,   157,   158,   159,   160,   161,
     162,     0,   164,   165,    56,   166,   167,   168,   169,     0,
     170,   171,   172,   173,   174,   175,   176,   177,   155,   178,
     156,     0,     0,     0,   157,   158,   159,   160,   161,   162,
       0,   164,     0,     0,   166,   167,   168,   169,     0,   170,
     171,   172,   173,   174,   175,   176,   177,   255,   178,     0,
       0,     0,   196,   197,   198,   199,   200,   201,   202,     0,
       0,     0,   203,   204,   205,   206,     0,   207,   208,   209,
     210,   211,   212,   213,   214,  -100,     0,     0,     0,     0,
     196,   197,   198,   199,   200,   201,   202,     0,     0,     0,
     203,   204,   205,   206,     0,   207,   208,   209,   210,   211,
     212,   213,   214,   256,     0,     0,     0,     0,   215,   216,
     217,   218,   219,   220,   221,     0,     0,     0,   222,     0,
       0,     0,     0,     0,     0,   223,   224,   225,   226,   227,
     228,   256,     0,     0,     0,     0,   275,   276,   277,   278,
     279,   280,   295,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   296,   297,   298,   299,   300,   301,   196,
     197,   198,   199,   200,   201,   202,     0,     0,     0,   203,
     204,   205,   206,     0,   207,   208,   209,   210,   211,   212,
     213,   214,   265,   266,   267,   268,   269,   201,   288,     0,
       0,     0,     0,   270,   271,   272,     0,   273,   274,   289,
     290,   291,   292,   293,   294,   196,   197,   198,   199,   200,
     201,     0,     0,     0,     0,   203,   204,   205,   206,     0,
     207,   208,   209,   210,   211,   212,   213,   214,   265,   266,
     267,   268,   269,   201,     0,     0,     0,     0,     0,   270,
     271,   272,     0,   273,   274,   289,   290,   291,   292,   293,
     294,   196,   197,   198,   199,   200,   201,     0,     0,     0,
       0,     0,   204,     0,   206,     0,   207,   208,   209,   210,
     211,   212,   213,   214,   196,   197,   198,   199,   200,   201,
       0,     0,     0,     0,     0,   204,     0,     0,     0,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,     0,     0,     0,   222,     0,     0,
       0,     0,     0,     0,   223,   224,   225,   226,   227,   228,
     275,   276,   277,   278,   279,   280,   295,   275,   276,   277,
     278,   279,   280,     0,     0,     0,     0,   296,   297,   298,
     299,   300,   301,     0,   296,   297,   298,   299,   300,   301,
     255,     0,     0,     0,     0,   265,   266,   267,   268,   269,
     201,     0,     0,     0,     0,     0,   270,   271,   272,     0,
     273,   274,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,     0,   152,   153
  };

  const short
   Parser ::yycheck_[] =
  {
       8,    65,    10,    11,    12,   771,    11,    33,     3,   775,
       9,     9,     9,    43,     8,   133,    76,    12,    24,    25,
      26,    27,     9,     9,     9,    76,   751,   752,    12,    11,
      11,     9,    13,    11,    39,     3,     4,     5,     6,     7,
       8,     9,    40,    11,    12,    40,   745,   746,    16,    11,
       3,    17,    18,    19,    11,    61,    24,    41,    39,    41,
       9,    29,     3,     4,     5,     6,     7,     8,     9,    11,
      11,    11,    80,    81,    11,    16,    11,    76,    86,    76,
      10,   806,     9,    24,    92,    93,    68,    68,    29,    76,
      76,    76,   791,   101,   860,    76,   102,    76,   104,   125,
     106,    12,   108,    56,    57,   113,    68,   115,    76,    77,
     116,    68,   120,   121,    76,    42,    69,    70,    71,    72,
      14,    76,    11,    76,    76,    98,    68,    57,    68,     0,
      41,    68,    11,    68,     3,    76,    77,     3,    17,    69,
      70,    71,    72,    12,     9,    39,    76,    13,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,    40,   180,   181,   182,   183,   184,   185,   186,    68,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,     8,   355,   244,    22,
      23,    68,    25,   251,    12,     9,     9,    11,    10,    32,
      33,    15,    16,    17,    18,    19,    20,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,    41,   247,    39,    10,   285,    40,    12,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     3,    41,   317,
     318,   319,   320,   321,     9,    42,    11,     0,    14,    38,
       3,    21,    38,   329,    40,    20,    12,    12,    40,   101,
      12,   357,    32,    33,    43,   343,     3,    11,    57,    13,
      10,   113,     4,   115,    39,    42,    13,     9,   120,   121,
      69,    70,    71,    72,    16,    41,    41,    76,    11,    41,
      56,    57,    15,    16,    17,    39,    11,    29,   341,   342,
      21,    22,    23,    69,    70,    71,    72,     8,     9,     9,
      76,    32,    33,    62,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,    13,   180,   181,
     182,   183,   184,   185,   186,     9,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    10,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,    22,     4,     5,     6,     7,     8,     9,   251,
      11,    12,    32,    33,   101,    16,    12,     4,     5,     6,
       7,     8,     9,    24,    11,    12,   113,    41,    29,    16,
      32,    33,    41,   120,    22,    23,    12,    24,     4,     5,
      41,    13,    29,     9,    32,    33,    32,    33,     0,     1,
      16,     3,     4,     5,     6,     7,     8,     9,    11,    11,
      76,    11,    10,    29,    16,    14,     4,     5,     9,   156,
      10,     9,    24,    20,    20,    76,    77,    29,    16,    32,
      33,    34,    35,    36,    37,    11,     9,    12,    11,    76,
      77,    29,    25,   180,    17,    18,    19,    20,    20,    32,
      33,   343,    10,   637,    56,    57,    58,    59,    12,    61,
      62,    63,    64,    65,    66,    67,    39,    69,    70,    71,
      72,    73,    74,     8,    76,    77,    14,    40,     4,     5,
       6,     7,     8,     9,    11,    11,    12,    76,    76,    77,
      16,     3,   229,    21,    22,    23,    76,    25,    24,    10,
      10,    42,     3,    29,    32,    33,    10,    34,    35,    36,
      37,    10,    10,     0,   251,    41,     3,     4,     5,     6,
       7,     8,     9,     0,    11,    14,    10,    38,    10,    16,
      10,     8,     9,    10,    11,    10,    21,    24,    12,    42,
      25,     3,    29,    20,    10,   638,    57,    32,    33,    42,
      76,    77,    22,    10,    60,    25,    33,    10,    69,    70,
      71,    72,    32,    33,    12,    76,    43,    76,    12,    56,
      57,    58,    59,    40,    61,    62,    63,    64,    65,    66,
      67,    38,    69,    70,    71,    72,    73,    74,    25,    76,
      77,    38,    12,    39,    25,    32,    33,   638,    75,   323,
      57,    32,    33,    80,    81,    63,   343,    98,   758,    86,
     141,    75,    69,    70,    71,    72,   744,   745,   746,    76,
      11,   771,   881,   782,   750,   775,   772,    -1,    -1,    -1,
      21,    -1,    -1,    -1,    25,   785,   764,    -1,    57,   767,
     766,    32,    33,    34,    35,    36,    37,    -1,   125,    -1,
      69,    70,    71,    72,   131,    -1,   133,    76,   751,   752,
     137,   811,    -1,   791,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   791,   155,   829,
     157,   158,   159,   160,   161,   162,   163,    -1,   816,   782,
     818,    37,    -1,    -1,    -1,   172,   173,   174,   175,   176,
     177,    -1,    48,    49,    50,    51,    -1,   835,   836,    -1,
     860,   188,    -1,   806,    -1,   192,    -1,   810,    -1,   196,
     197,   198,   199,   200,   201,   202,   854,    15,    16,    17,
      18,    19,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,   223,   224,   225,   226,
     227,   228,    -1,   230,    21,   883,    10,    11,    25,    -1,
      -1,   238,    -1,    -1,     0,    32,    33,    21,    -1,    -1,
      -1,    25,     8,     9,    -1,    11,    -1,    -1,    32,    33,
      34,    35,    36,    37,    20,   262,    -1,    -1,   265,   266,
     267,   268,   269,    17,    18,    19,    20,    33,   275,   276,
     277,   278,   279,   280,    -1,    -1,    -1,    43,   285,    -1,
      -1,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,    11,    75,
      -1,    -1,    15,    16,    17,   322,    30,    31,    -1,    -1,
      86,   328,   744,   745,   746,    17,    18,    19,    20,    32,
      33,    -1,     4,     5,     6,     7,     8,     9,    10,    11,
      54,    -1,   764,    -1,    16,   767,    -1,    -1,   355,    -1,
     357,    65,    24,    -1,    68,    -1,    -1,    29,    -1,   125,
      -1,    -1,    -1,    77,    -1,   131,    -1,   133,    -1,   791,
      -1,   137,    -1,    -1,    -1,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,   155,
      17,    18,    19,    20,   816,    -1,   818,   163,    -1,    -1,
     166,    -1,    -1,    -1,    76,    77,   172,   173,   174,   175,
     176,   177,   771,   835,   836,   834,   775,    -1,   837,   838,
     839,   840,   188,    -1,    -1,    -1,   192,    -1,    -1,    11,
      -1,    -1,   854,    15,    16,    17,   202,     4,     5,     6,
       7,     8,     9,    25,    11,    -1,    13,    -1,    -1,    16,
      32,    33,    -1,    -1,    -1,   221,    -1,    24,    -1,    -1,
      -1,   883,    29,    -1,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,   833,   834,    -1,    -1,   837,   838,
     839,   840,    17,    18,    19,    20,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,   262,   764,    16,    -1,
     767,   860,    10,    -1,    -1,    -1,    24,    -1,    -1,    76,
      77,    29,    -1,    21,    22,    23,    -1,    25,    -1,   285,
      -1,    -1,   288,    41,    32,    33,    -1,    -1,    -1,   295,
      15,    16,    17,    18,    19,    20,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   816,
      -1,   818,    34,    35,    36,    37,   322,    -1,    76,    77,
      -1,    -1,   328,    -1,    -1,    -1,    57,    -1,   835,   836,
       4,     5,     6,     7,     8,     9,    -1,    11,    69,    70,
      71,    72,    16,    -1,    -1,    76,    77,   854,    -1,   355,
      24,   357,    -1,    -1,    -1,    29,    -1,    -1,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    41,    -1,    -1,
      16,    -1,    -1,    -1,    -1,    -1,   883,    -1,    24,    -1,
      -1,    -1,    -1,    29,     4,     5,     6,     7,     8,     9,
     637,    11,    12,    -1,    -1,    -1,    16,   644,    11,    -1,
      -1,    -1,    76,    77,    24,    -1,     0,    -1,    -1,    29,
      -1,    -1,    25,    -1,     8,     9,    -1,    11,    -1,    32,
      33,    34,    35,    36,    37,   379,    20,    -1,    -1,   383,
      76,    77,    -1,   387,    -1,    -1,    -1,    -1,    -1,    33,
      -1,     4,     5,     6,     7,     8,     9,    -1,    11,    43,
      -1,    -1,    -1,    16,    -1,    -1,    76,    77,    -1,    -1,
      -1,    24,    -1,     9,    -1,    11,    29,    -1,   422,    15,
      16,    17,    18,    19,    20,    -1,   430,    -1,    -1,    -1,
      26,    75,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    86,    39,    -1,    -1,    -1,   744,   745,   746,
      -1,    -1,   456,    -1,   458,    -1,   460,    -1,   462,    -1,
     464,    -1,   466,    76,    77,    15,    16,    17,    18,    19,
      20,   475,    -1,    -1,   771,   772,    -1,   774,   775,    -1,
     777,   125,    -1,    -1,   488,    -1,    -1,   131,    -1,   133,
      -1,    -1,    -1,   137,   791,    -1,    -1,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
      -1,   155,    -1,    -1,   518,    -1,    -1,    -1,    -1,   163,
     164,   165,    -1,   820,    -1,    10,    -1,    -1,   172,   173,
      15,    16,    17,    18,    19,    20,   833,   834,    -1,    10,
     837,   838,   839,   840,   188,   842,    -1,   844,   192,    10,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,   202,    -1,
      21,    32,    33,   860,    25,    -1,    -1,    -1,    -1,   573,
      -1,    32,    33,    34,    35,    36,    37,   221,    -1,    -1,
      -1,   637,    -1,    -1,    -1,    -1,   230,    -1,   644,    -1,
      -1,    -1,    -1,    -1,   238,   239,   240,   601,   242,   243,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,   262,    -1,
      24,    -1,    -1,   627,    -1,    29,    -1,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,    16,
      -1,   285,    -1,    -1,   288,    -1,    -1,    24,    -1,    -1,
      -1,   295,    29,    -1,    -1,    -1,    -1,    -1,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,    -1,    76,    77,     0,    -1,    -1,    -1,   322,    -1,
      -1,    -1,    -1,     9,   328,    11,    -1,    -1,   744,   745,
     746,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    76,
      77,    15,    16,    17,    18,    19,    20,    33,    -1,    -1,
      -1,   355,    -1,   357,    -1,   771,   772,    43,   774,   775,
      -1,   777,     4,     5,     6,     7,     8,     9,    -1,    11,
      -1,    -1,    -1,    -1,    16,   791,     4,     5,     6,     7,
       8,     9,    24,    11,    -1,    -1,    -1,    29,    16,    75,
      15,    16,    17,    18,    19,    20,    24,    -1,    -1,    -1,
      86,    29,    -1,    -1,   820,    30,    31,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    -1,   833,   834,    16,
      -1,   837,   838,   839,   840,    -1,   842,    24,   844,    -1,
      -1,    -1,    29,    -1,    76,    77,    -1,    -1,    -1,   125,
      -1,    -1,    -1,    -1,   860,   131,    -1,   133,    76,    77,
      -1,   137,    -1,    -1,    -1,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,   155,
      32,    33,    34,    35,    36,    37,    -1,   163,    -1,    76,
      77,    -1,    -1,    -1,    -1,    -1,   172,   173,     9,    -1,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      -1,    -1,   188,    -1,   190,   191,   192,    -1,    -1,    30,
      31,     0,    -1,    -1,     3,    -1,   202,    -1,    39,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,     0,    11,    -1,    13,   221,    -1,    16,    -1,    -1,
       9,    -1,    -1,    -1,   230,    24,    -1,    -1,    -1,    -1,
      29,    20,   238,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    33,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    -1,   262,    56,    57,    58,
      59,    -1,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    -1,    76,    77,   285,
     286,   287,   288,    -1,    -1,    -1,    75,    -1,    -1,   295,
      15,    16,    17,    18,    19,    20,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,    34,
      35,    36,    37,   637,    -1,    -1,   322,    -1,    -1,    -1,
     644,    -1,   328,    -1,    -1,     4,     5,     6,     7,     8,
       9,    15,    16,    17,    18,    19,   125,    16,    -1,    -1,
      -1,    -1,   131,    -1,   133,    24,    30,    31,   137,   355,
      29,   357,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    25,   155,    -1,   157,   158,
     159,    -1,    32,    33,    34,    35,    36,    37,    -1,    -1,
       9,    -1,    11,   172,   173,    -1,    15,    16,    17,    18,
      19,    20,   181,   182,   183,   184,   185,   186,    -1,    -1,
     189,    30,    31,    -1,   193,    34,    35,    36,    37,    -1,
      39,    -1,     9,    -1,   203,    -1,    -1,    -1,    -1,    -1,
     744,   745,   746,    20,     4,     5,     6,     7,     8,     9,
      -1,    -1,    -1,   222,    -1,    -1,    16,    -1,    -1,    -1,
      -1,    -1,   231,    -1,    24,    -1,    -1,   771,   772,    29,
     774,   775,   241,   777,     0,    15,    16,    17,    18,    19,
      -1,    -1,    -1,     9,    -1,    -1,    26,   791,    28,    -1,
      30,    31,    -1,   262,    20,    -1,    -1,    -1,    75,    -1,
      -1,    15,    16,    17,    18,    19,    20,    33,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    -1,   820,    43,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,   833,
     834,    -1,    -1,   837,   838,   839,   840,    -1,   842,    -1,
     844,    -1,    15,    16,    17,    18,    19,    20,    -1,    75,
      -1,    -1,    -1,   322,   131,    -1,   860,    30,    31,   328,
     137,    -1,    -1,    -1,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,   155,    15,
      16,    17,    18,    19,    20,    -1,   355,    -1,   357,    -1,
      26,    27,    28,    -1,    30,    31,    -1,    -1,    -1,   125,
      -1,    -1,    -1,    -1,    -1,   131,    -1,   133,    -1,    -1,
      -1,   137,    -1,    -1,    -1,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,   155,
      -1,    -1,    -1,    -1,    -1,    -1,    10,   163,    -1,    -1,
      -1,    15,    16,    17,    18,    19,   172,   173,    -1,    -1,
      -1,   637,    26,    27,    28,    -1,    30,    31,   644,    21,
      -1,    -1,   188,    25,    -1,    -1,   192,    -1,   194,   195,
      32,    33,    34,    35,    36,    37,   202,    15,    16,    17,
      18,    19,    20,    -1,    -1,   262,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,   221,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,   230,    -1,    -1,     9,    10,    11,
      -1,    -1,   238,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    25,    26,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,   262,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   322,     9,    -1,    11,    -1,
      -1,   328,    15,    16,    17,    18,    19,    20,   744,   745,
     746,    -1,    25,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    39,    -1,    -1,    15,
      16,    17,    18,    19,    -1,   771,   772,    -1,   774,   775,
      26,   777,    -1,    -1,    30,    31,   322,     9,    10,    11,
      -1,    -1,   328,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    25,    26,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    39,    -1,   355,
      -1,   357,    -1,    -1,   820,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   833,   834,    -1,
      -1,   837,   838,   839,   840,    -1,   842,     1,   844,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,   637,    -1,
      14,    -1,    16,    -1,   860,   644,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    29,    -1,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
      -1,    14,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    56,    57,    58,    59,    29,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    -1,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    -1,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    10,    76,    77,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    -1,   744,   745,   746,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
       9,    -1,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,   771,   772,    -1,   774,   775,    26,   777,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      39,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    -1,    14,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,   820,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     637,    -1,    -1,    -1,   833,   834,    -1,   644,   837,   838,
     839,   840,    -1,   842,    -1,   844,    -1,    -1,    -1,    56,
      57,    58,    59,    -1,    61,    62,    63,    64,    65,    66,
      67,   860,    69,    70,    71,    72,    73,    74,    -1,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   637,    -1,    -1,    -1,    -1,    -1,    -1,   644,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,     9,    -1,
      11,    -1,    16,    -1,    15,    16,    17,    18,    19,    20,
      24,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   744,   745,   746,
      -1,    -1,    56,    57,    58,    59,    -1,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    -1,    76,    77,    -1,    -1,    -1,   774,    -1,    -1,
     777,    -1,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    -1,    -1,   744,   745,
     746,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    39,    -1,    -1,    15,    16,    17,
      18,    19,    20,   820,    -1,   771,   772,    -1,   774,   775,
      -1,   777,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,     9,    -1,    11,   842,    -1,   844,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    -1,   820,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   833,   834,    -1,
      -1,   837,   838,   839,   840,    -1,   842,    -1,   844,     9,
      -1,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,    22,    23,   860,    25,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,     9,    39,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      -1,    22,    -1,    -1,    25,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    10,    39,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    25,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    10,    -1,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      25,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    10,    -1,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      37,    10,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      18,    19,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    37,
      15,    16,    17,    18,    19,    20,    21,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    37,    -1,    32,    33,    34,    35,    36,    37,
      10,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    -1,
      30,    31,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55
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
       9,    16,    76,    77,   124,   125,     9,   120,   124,   125,
     126,   127,     9,    16,   124,    76,    76,    89,     9,   112,
      76,    11,    68,   131,    68,   131,    68,   131,    68,   131,
      76,    76,   105,    11,    13,    39,    68,   119,   122,   131,
      11,    39,   119,     0,     0,     1,    83,     0,     3,    82,
      82,     9,     3,    13,    84,    85,    87,     9,    82,    82,
      82,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    54,    55,    82,     9,    11,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    25,    26,    27,    28,
      30,    31,    32,    33,    34,    35,    36,    37,    39,   119,
      11,    15,    16,    17,    25,    32,    33,   119,    21,    25,
      32,    33,    21,    25,    32,    33,    15,    16,    17,    18,
      19,    20,    21,    25,    26,    27,    28,    30,    31,    32,
      33,    34,    35,    36,    37,    15,    16,    17,    18,    19,
      20,    21,    25,    32,    33,    34,    35,    36,    37,    11,
      21,    25,    32,    33,    34,    35,    36,    37,    21,    22,
      23,    25,    32,    33,    68,   131,    68,     9,    76,   105,
      10,    11,   122,    10,    10,    10,    10,    10,    10,   115,
       3,    12,    40,   124,   125,    15,    16,    17,    18,    19,
      26,    27,    28,    30,    31,    15,    16,    17,    18,    19,
      20,   124,   125,   126,   127,    21,    32,    33,    21,    32,
      33,    34,    35,    36,    37,    21,    32,    33,    34,    35,
      36,    37,    21,    25,    32,    33,    34,    35,    36,    37,
      21,    22,    23,    32,    33,   124,   124,    15,    16,    17,
      18,    19,    42,    40,    76,    77,   108,   132,    42,    12,
     113,   118,   124,   125,   126,   127,   131,   131,   131,   131,
       3,    13,     9,    41,   118,    14,    39,   123,   113,   124,
     131,   118,   113,    83,   112,    13,    14,    81,    62,   112,
     110,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,    10,   111,   112,   118,   113,   116,
     124,   125,   113,   116,   124,   125,   113,   116,   124,   125,
     113,   124,   125,   113,   124,   125,   113,   125,   113,   120,
     121,   124,   125,   126,   127,   113,   127,   113,   127,   113,
     126,   113,   124,   113,   124,   113,   124,   113,   124,   113,
     124,   113,   116,   120,   121,   124,   125,   126,   127,   113,
     116,   120,   121,   124,   125,   126,   127,   113,   124,   125,
     126,   113,   124,   125,   126,   113,   124,   125,   126,   113,
     124,   125,   126,   113,   118,   113,   116,   113,   116,   113,
     116,   113,   116,   113,   116,   113,   116,   113,   120,   121,
     124,   125,   126,   127,   113,   116,   113,   120,   113,   120,
     113,   120,   121,   124,   125,   126,   127,   113,   116,   113,
     121,   113,   121,   113,   124,   125,   113,   124,   125,   113,
     124,   125,   113,   124,   125,   113,   124,   125,   124,   125,
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
     113,   127,   131,    10,    76,   129,   132,    42,     9,   118,
      10,     3,    12,    12,     3,   112,   124,   125,   124,   125,
     124,   125,   124,   125,   124,   125,   124,   124,   124,   124,
     124,   124,   125,   124,   125,   124,   125,   124,   125,   124,
     125,   124,   125,   120,   124,   125,   126,   127,     9,   120,
     120,   120,   124,   125,   126,   127,   124,   125,   124,   125,
     124,   125,   124,   125,   124,   125,   124,   125,   120,   124,
     125,   126,   127,   124,   125,   124,   125,   124,   125,   124,
     125,   124,   125,   124,   125,   120,   124,   125,   126,   127,
     126,   127,   126,   126,   126,   126,   126,   126,   120,   124,
     125,   126,   127,   127,   127,   127,   127,   124,   124,   124,
     124,   124,   112,    89,    41,    41,    41,    76,   112,   131,
      12,    13,     3,    14,    56,   102,   103,   132,    10,    38,
     106,   107,   132,    12,    41,   118,    12,    41,    76,    14,
      12,    10,    81,    14,     9,    10,    10,    40,    12,    12,
      12,    10,    40,   112,   122,    10,   107,    12,    12,   112,
       8,     9,   112,   113,   117,   118,   124,   112,   117,   112,
     117,   131,   102,   102,    76,    14,     3,    76,    85,    76,
      40,    10,    76,    12,   118,    12,    41,    12,    41,   118,
      42,    87,    14,     3,   112,    87,   112,   129,    85,    10,
     113,   117,   124,    10,    10,    38,    40,    10,    10,    10,
      10,    14,    42,   102,    42,    38,   132,    85,    12,    12,
     118,    12,   118,    12,    41,   112,     3,    10,    60,    98,
     100,    85,    10,    84,    85,    86,    86,   118,   118,    86,
      86,    86,    86,   112,   112,    76,    76,    12,    12,    12,
     118,    40,    87,    38,    12,   123,   118
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
     128,   128,   129,   129,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   131,   131,   131,   131,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132
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
       1,     1,     1,     1,     1
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
     415,   416,   417,   419,   420,   421,   423,   424,   425,   426,
     427,   428,   429,   430,   432,   433,   434,   435,   436,   438,
     439,   440,   441,   442,   444,   445,   446,   447,   448,   449,
     450,   451,   453,   454,   455,   456,   457,   458,   459,   460,
     462,   463,   464,   466,   467,   468,   470,   471,   472,   473,
     474,   475,   476,   478,   479,   480,   481,   482,   483,   484,
     486,   487,   488,   489,   490,   491,   492,   494,   495,   496,
     497,   498,   499,   500,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   538,   539,
     540,   542,   543,   544,   546,   547,   548,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   567,   568,   569,   571,   572,   573,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   602,   603,   604,   605,   606,   609,   610,
     611,   615,   616,   618,   619,   620,   622,   623,   625,   626,
     627,   628,   629,   630,   631,   632,   633,   634,   635,   636,
     640,   641,   645,   646,   648,   649,   651,   652,   656,   657,
     658,   659,   660,   661,   662,   663,   664,   665,   666,   667,
     668,   669,   673,   674,   675,   676,   677,   678,   679,   680,
     681,   682,   683,   684,   685,   686,   687,   688,   689,   690,
     691,   692,   693,   697,   698,   699,   700,   701,   702,   703,
     704,   705,   706,   707,   708,   709,   710,   711,   712,   713,
     714,   715,   716,   717,   718,   719,   720,   721,   722,   723,
     727,   728,   729,   730,   731,   733,   734,   735,   736,   737,
     738,   739,   741,   742,   743,   744,   745,   746,   747,   749,
     750,   751,   752,   753,   755,   756,   757,   758,   759,   761,
     762,   763,   764,   765,   767,   768,   769,   770,   771,   773,
     777,   778,   780,   781,   785,   786,   787,   788,   789,   790,
     791,   792,   793,   794,   795,   796,   798,   799,   800,   801,
     805,   806,   807,   808,   809,   810,   811,   812,   813,   814,
     815,   816,   817,   818,   819
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
#line 5004 "frontend/parser.cpp"

#line 822 "frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    auto msg = std::to_string(scanner->loc->begin.line) + ":" + std::to_string(scanner->loc->begin.column) + ": " + err_message;
    scanner->fatal_error(ptc::diag::ERR_SYNTAX, msg);
}
