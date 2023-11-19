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
#line 232 "frontend/parser.yy"
                        { scanner->parseEntry(std::vector<ptc::ir::IR *>{}); }
#line 1175 "frontend/parser.cpp"
    break;

  case 3: // start: stmt "end of file"
#line 233 "frontend/parser.yy"
                        { scanner->parseEntry(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1181 "frontend/parser.cpp"
    break;

  case 4: // stmt: stmts
#line 235 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1187 "frontend/parser.cpp"
    break;

  case 5: // stmt: stmt stmts
#line 236 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1193 "frontend/parser.cpp"
    break;

  case 6: // stmt: stmt error stmts
#line 237 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1199 "frontend/parser.cpp"
    break;

  case 9: // stmts: "terminator (\\n or ;)"
#line 244 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = nullptr; }
#line 1205 "frontend/parser.cpp"
    break;

  case 10: // stmts: stmts_ne
#line 245 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1211 "frontend/parser.cpp"
    break;

  case 11: // stmts_ne: set stmt_end
#line 247 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1217 "frontend/parser.cpp"
    break;

  case 12: // stmts_ne: vardecl stmt_end
#line 248 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1223 "frontend/parser.cpp"
    break;

  case 13: // stmts_ne: vardef stmt_end
#line 249 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1229 "frontend/parser.cpp"
    break;

  case 14: // stmts_ne: import stmt_end
#line 250 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1235 "frontend/parser.cpp"
    break;

  case 15: // stmts_ne: for
#line 251 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1241 "frontend/parser.cpp"
    break;

  case 16: // stmts_ne: if
#line 252 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1247 "frontend/parser.cpp"
    break;

  case 17: // stmts_ne: while
#line 253 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1253 "frontend/parser.cpp"
    break;

  case 18: // stmts_ne: dowhile
#line 254 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1259 "frontend/parser.cpp"
    break;

  case 19: // stmts_ne: struct
#line 255 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1265 "frontend/parser.cpp"
    break;

  case 20: // stmts_ne: function
#line 256 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1271 "frontend/parser.cpp"
    break;

  case 21: // stmts_ne: flowctl stmt_end
#line 257 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1277 "frontend/parser.cpp"
    break;

  case 22: // stmts_ne: expr stmt_end
#line 258 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1283 "frontend/parser.cpp"
    break;

  case 23: // block: "{" "}"
#line 262 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1289 "frontend/parser.cpp"
    break;

  case 24: // block: "{" stmt "}"
#line 263 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1295 "frontend/parser.cpp"
    break;

  case 25: // block: "terminator (\\n or ;)" "{" stmt "}"
#line 264 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1301 "frontend/parser.cpp"
    break;

  case 26: // block: "{" stmt "}" "terminator (\\n or ;)"
#line 265 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1307 "frontend/parser.cpp"
    break;

  case 27: // block: "terminator (\\n or ;)" "{" stmt "}" "terminator (\\n or ;)"
#line 266 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1313 "frontend/parser.cpp"
    break;

  case 28: // scope_body: stmts_ne
#line 269 "frontend/parser.yy"
                      { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); scanner->leaveScope(); }
#line 1319 "frontend/parser.cpp"
    break;

  case 29: // scope_body: block
#line 270 "frontend/parser.yy"
                      { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); scanner->leaveScope(); }
#line 1325 "frontend/parser.cpp"
    break;

  case 30: // import: "import" id_list
#line 274 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::IR * > () = scanner->parseImports(yystack_[0].value.as < std::vector<std::string>  > ()); }
#line 1331 "frontend/parser.cpp"
    break;

  case 31: // id_list: "identifier"
#line 276 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseImportName(yystack_[0].value.as < std::string > ()); }
#line 1337 "frontend/parser.cpp"
    break;

  case 32: // id_list: "identifier" "," id_list
#line 277 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseAddImportName(yystack_[0].value.as < std::vector<std::string>  > (), yystack_[2].value.as < std::string > ()); }
#line 1343 "frontend/parser.cpp"
    break;

  case 33: // flowctl: "break"
#line 281 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseBreak(); }
#line 1349 "frontend/parser.cpp"
    break;

  case 34: // flowctl: "continue"
#line 282 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseContinue(); }
#line 1355 "frontend/parser.cpp"
    break;

  case 35: // flowctl: return
#line 283 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1361 "frontend/parser.cpp"
    break;

  case 36: // return: "return"
#line 285 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(nullptr); }
#line 1367 "frontend/parser.cpp"
    break;

  case 37: // return: "return" expr
#line 286 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1373 "frontend/parser.cpp"
    break;

  case 38: // for: for_kw "(" vardecl ":" expr ")" scope_body
#line 290 "frontend/parser.yy"
                                                      { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1379 "frontend/parser.cpp"
    break;

  case 39: // for: for_kw "(" "identifier" ":" expr ")" scope_body
#line 291 "frontend/parser.yy"
                                                      { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1385 "frontend/parser.cpp"
    break;

  case 40: // for: for_kw "(" "external identifier" ":" expr ")" scope_body
#line 292 "frontend/parser.yy"
                                                      { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1391 "frontend/parser.cpp"
    break;

  case 41: // for: for_kw "(" vardecl ":" range ")" scope_body
#line 293 "frontend/parser.yy"
                                                      { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1397 "frontend/parser.cpp"
    break;

  case 42: // for: for_kw "(" "identifier" ":" range ")" scope_body
#line 294 "frontend/parser.yy"
                                                      { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1403 "frontend/parser.cpp"
    break;

  case 43: // for: for_kw "(" "external identifier" ":" range ")" scope_body
#line 295 "frontend/parser.yy"
                                                      { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1409 "frontend/parser.cpp"
    break;

  case 44: // for_kw: "for"
#line 297 "frontend/parser.yy"
               { scanner->enterBlockScope(); }
#line 1415 "frontend/parser.cpp"
    break;

  case 45: // while: wh_kw "(" expr ")" scope_body
#line 300 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseWhile(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1421 "frontend/parser.cpp"
    break;

  case 46: // wh_kw: "while"
#line 302 "frontend/parser.yy"
                { scanner->enterBlockScope(); }
#line 1427 "frontend/parser.cpp"
    break;

  case 47: // dowhile: do_kw scope_body "while" "(" expr ")"
#line 304 "frontend/parser.yy"
                                                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseDoWhile(yystack_[1].value.as < ptc::ir::Expr * > (), yystack_[4].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1433 "frontend/parser.cpp"
    break;

  case 48: // do_kw: "do"
#line 306 "frontend/parser.yy"
             { scanner->enterBlockScope(); }
#line 1439 "frontend/parser.cpp"
    break;

  case 49: // if: if_kw "(" expr ")" scope_body else
#line 309 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseIfStmt(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1445 "frontend/parser.cpp"
    break;

  case 50: // else: el_kw scope_body
#line 311 "frontend/parser.yy"
                         { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1451 "frontend/parser.cpp"
    break;

  case 51: // else: %empty
#line 312 "frontend/parser.yy"
                         { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1457 "frontend/parser.cpp"
    break;

  case 52: // if_kw: "if"
#line 314 "frontend/parser.yy"
             { scanner->enterBlockScope(); }
#line 1463 "frontend/parser.cpp"
    break;

  case 53: // el_kw: "else"
#line 315 "frontend/parser.yy"
               { scanner->enterBlockScope(); }
#line 1469 "frontend/parser.cpp"
    break;

  case 54: // struct: "'struct'" "identifier" "{" "}"
#line 318 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[2].value.as < std::string > (), std::vector<ptc::ir::IR *>{}); }
#line 1475 "frontend/parser.cpp"
    break;

  case 55: // struct: "'struct'" "identifier" "{" decllist "}"
#line 319 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1481 "frontend/parser.cpp"
    break;

  case 56: // struct: "'struct'" "identifier" "terminator (\\n or ;)" "{" decllist "}"
#line 320 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[4].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1487 "frontend/parser.cpp"
    break;

  case 58: // decllist: "terminator (\\n or ;)" decllist
#line 323 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1493 "frontend/parser.cpp"
    break;

  case 59: // decllist: declistval "terminator (\\n or ;)"
#line 324 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[1].value.as < ptc::ir::IR * > (), std::vector<ptc::ir::IR *>{}); }
#line 1499 "frontend/parser.cpp"
    break;

  case 60: // decllist: declistval "terminator (\\n or ;)" decllist
#line 325 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[2].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1505 "frontend/parser.cpp"
    break;

  case 61: // declistval: type "identifier"
#line 327 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > (), nullptr); }
#line 1511 "frontend/parser.cpp"
    break;

  case 62: // declistval: type "identifier" "=" expr
#line 328 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1517 "frontend/parser.cpp"
    break;

  case 64: // function: type fun_id "(" ")" block
#line 333 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1523 "frontend/parser.cpp"
    break;

  case 65: // function: type fun_id "(" funargs ")" block
#line 334 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[5].value.as < ptc::ir::IR * > (), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1529 "frontend/parser.cpp"
    break;

  case 66: // function: "'void'" fun_id "(" ")" block
#line 335 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1535 "frontend/parser.cpp"
    break;

  case 67: // function: "'void'" fun_id "(" funargs ")" block
#line 336 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1541 "frontend/parser.cpp"
    break;

  case 68: // fun_id: "identifier"
#line 338 "frontend/parser.yy"
            { scanner->enterFunScope(); yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1547 "frontend/parser.cpp"
    break;

  case 69: // funargsnvar: type "identifier"
#line 340 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseFunParam(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1553 "frontend/parser.cpp"
    break;

  case 70: // funargsnvar: funargsnvar "," type "identifier"
#line 341 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseAddFunParam(yystack_[3].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1559 "frontend/parser.cpp"
    break;

  case 71: // funargs: ".." "identifier"
#line 343 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseFunParam(scanner->sym_lookup(VARARGS_CSTR, false, true), yystack_[0].value.as < std::string > ()); }
#line 1565 "frontend/parser.cpp"
    break;

  case 72: // funargs: funargsnvar "," ".." "identifier"
#line 344 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseAddFunParam(yystack_[3].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), scanner->sym_lookup(VARARGS_CSTR, false, true), yystack_[0].value.as < std::string > ());}
#line 1571 "frontend/parser.cpp"
    break;

  case 73: // funargs: funargsnvar
#line 345 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = yystack_[0].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (); }
#line 1577 "frontend/parser.cpp"
    break;

  case 74: // vardecl: type "identifier"
#line 350 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1583 "frontend/parser.cpp"
    break;

  case 75: // vardef: type "identifier" "=" struct_val
#line 354 "frontend/parser.yy"
         { yylhs.value.as < ptc::ir::IR * > () = yystack_[3].value.as < ptc::ir::IR * > (); }
#line 1589 "frontend/parser.cpp"
    break;

  case 76: // vardef: type "identifier" "=" expr
#line 355 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1595 "frontend/parser.cpp"
    break;

  case 79: // set: expr "++=" expr
#line 361 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1601 "frontend/parser.cpp"
    break;

  case 80: // set: expr "**=" expr
#line 362 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1607 "frontend/parser.cpp"
    break;

  case 81: // set: expr "%=" expr
#line 363 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1613 "frontend/parser.cpp"
    break;

  case 82: // set: expr "/=" expr
#line 364 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1619 "frontend/parser.cpp"
    break;

  case 83: // set: expr "*=" expr
#line 365 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1625 "frontend/parser.cpp"
    break;

  case 84: // set: expr "-=" expr
#line 366 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1631 "frontend/parser.cpp"
    break;

  case 85: // set: expr "+=" expr
#line 367 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1637 "frontend/parser.cpp"
    break;

  case 86: // set: expr "&=" expr
#line 368 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1643 "frontend/parser.cpp"
    break;

  case 87: // set: expr "|=" expr
#line 369 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1649 "frontend/parser.cpp"
    break;

  case 88: // set: expr "^=" expr
#line 370 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1655 "frontend/parser.cpp"
    break;

  case 89: // set: expr "<<=" expr
#line 371 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1661 "frontend/parser.cpp"
    break;

  case 90: // set: expr ">>=" expr
#line 372 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1667 "frontend/parser.cpp"
    break;

  case 91: // set: expr "=" expr
#line 373 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1673 "frontend/parser.cpp"
    break;

  case 92: // set: expr "=" set
#line 374 "frontend/parser.yy"
      { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1679 "frontend/parser.cpp"
    break;

  case 93: // callarglist: expr
#line 378 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseFunCallArg(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1685 "frontend/parser.cpp"
    break;

  case 94: // callarglist: callarglist "," expr
#line 379 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddFunCallArg(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1691 "frontend/parser.cpp"
    break;

  case 95: // expr: expr_mat
#line 383 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1697 "frontend/parser.cpp"
    break;

  case 96: // expr: expr_var
#line 384 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1703 "frontend/parser.cpp"
    break;

  case 97: // expr: expr_none
#line 385 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1709 "frontend/parser.cpp"
    break;

  case 99: // expr: expr_int
#line 387 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 1715 "frontend/parser.cpp"
    break;

  case 100: // expr: expr_float
#line 388 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFloat(yystack_[0].value.as < double > ()); }
#line 1721 "frontend/parser.cpp"
    break;

  case 101: // expr: expr_str
#line 389 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseString(yystack_[0].value.as < std::string > ()); }
#line 1727 "frontend/parser.cpp"
    break;

  case 102: // expr: expr_bool
#line 390 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseBool(yystack_[0].value.as < bool > ()); }
#line 1733 "frontend/parser.cpp"
    break;

  case 103: // expr_var: "identifier"
#line 393 "frontend/parser.yy"
              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > ()); }
#line 1739 "frontend/parser.cpp"
    break;

  case 104: // expr_var: "external identifier"
#line 394 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > (), true); }
#line 1745 "frontend/parser.cpp"
    break;

  case 105: // expr_var: "-" "identifier"
#line 395 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1751 "frontend/parser.cpp"
    break;

  case 106: // expr_var: "-" "external identifier"
#line 396 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > (), true), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1757 "frontend/parser.cpp"
    break;

  case 107: // expr_var: "(" expr_var ")"
#line 397 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1763 "frontend/parser.cpp"
    break;

  case 108: // expr_var: expr_var "(" ")"
#line 399 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[2].value.as < ptc::ir::Expr * > (), std::vector<ptc::ir::Expr *>{}); }
#line 1769 "frontend/parser.cpp"
    break;

  case 109: // expr_var: expr_var "(" callarglist ")"
#line 400 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 1775 "frontend/parser.cpp"
    break;

  case 110: // expr_var: expr_str "[" int_val "]"
#line 402 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1781 "frontend/parser.cpp"
    break;

  case 111: // expr_var: expr_mat "[" int_val "]"
#line 403 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1787 "frontend/parser.cpp"
    break;

  case 112: // expr_var: "identifier" "[" int_val "]"
#line 404 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1793 "frontend/parser.cpp"
    break;

  case 113: // expr_var: "external identifier" "[" int_val "]"
#line 405 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1799 "frontend/parser.cpp"
    break;

  case 114: // expr_var: expr_var "[" int_val "]"
#line 406 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1805 "frontend/parser.cpp"
    break;

  case 115: // expr_var: "identifier" "as" "external identifier"
#line 408 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > ()), scanner->parseVar(scanner->parseExtType(yystack_[0].value.as < std::string > (), false)->getName(), true, false), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1811 "frontend/parser.cpp"
    break;

  case 116: // expr_var: "external identifier" "as" "external identifier"
#line 409 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > (), true), scanner->parseVar(scanner->parseExtType(yystack_[0].value.as < std::string > (), false)->getName(), true, false), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1817 "frontend/parser.cpp"
    break;

  case 117: // expr_var: expr_var "as" "external identifier"
#line 410 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseVar(scanner->parseExtType(yystack_[0].value.as < std::string > (), false)->getName(), true, false), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1823 "frontend/parser.cpp"
    break;

  case 118: // expr_var: "identifier" "as" "external identifier" "?"
#line 411 "frontend/parser.yy"
                                      { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), scanner->parseVar(scanner->parseExtType(yystack_[1].value.as < std::string > (), true)->getName(), true, true), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1829 "frontend/parser.cpp"
    break;

  case 119: // expr_var: "external identifier" "as" "external identifier" "?"
#line 412 "frontend/parser.yy"
                                      { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > (), true), scanner->parseVar(scanner->parseExtType(yystack_[1].value.as < std::string > (), true)->getName(), true, true), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1835 "frontend/parser.cpp"
    break;

  case 120: // expr_var: expr_var "as" "external identifier" "?"
#line 413 "frontend/parser.yy"
                                      { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), scanner->parseVar(scanner->parseExtType(yystack_[1].value.as < std::string > (), true)->getName(), true, true), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1841 "frontend/parser.cpp"
    break;

  case 121: // expr_var: "identifier" "as" type
#line 414 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > ()), scanner->parseVar(yystack_[0].value.as < ptc::ir::IR * > ()->getName(), false, llvm::dyn_cast<ptc::ir::TypeDecl>(yystack_[0].value.as < ptc::ir::IR * > ())->isMaybe()), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1847 "frontend/parser.cpp"
    break;

  case 122: // expr_var: "external identifier" "as" type
#line 415 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > (), true), scanner->parseVar(yystack_[0].value.as < ptc::ir::IR * > ()->getName(), false, llvm::dyn_cast<ptc::ir::TypeDecl>(yystack_[0].value.as < ptc::ir::IR * > ())->isMaybe()), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1853 "frontend/parser.cpp"
    break;

  case 123: // expr_var: expr_var "as" type
#line 416 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseVar(yystack_[0].value.as < ptc::ir::IR * > ()->getName(), false, llvm::dyn_cast<ptc::ir::TypeDecl>(yystack_[0].value.as < ptc::ir::IR * > ())->isMaybe()), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1859 "frontend/parser.cpp"
    break;

  case 124: // expr_var: expr_mat slice
#line 418 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1865 "frontend/parser.cpp"
    break;

  case 127: // expr_var: expr_var slice
#line 421 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1871 "frontend/parser.cpp"
    break;

  case 128: // expr_var: expr_var "." "identifier"
#line 423 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1877 "frontend/parser.cpp"
    break;

  case 129: // expr_var: expr_var "." "external identifier"
#line 424 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1883 "frontend/parser.cpp"
    break;

  case 130: // expr_var: expr_float "**" expr_var
#line 427 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1889 "frontend/parser.cpp"
    break;

  case 131: // expr_var: expr_var "**" expr_float
#line 428 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1895 "frontend/parser.cpp"
    break;

  case 132: // expr_var: expr_var "**" expr_var
#line 429 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1901 "frontend/parser.cpp"
    break;

  case 133: // expr_var: expr_int "**" expr_var
#line 430 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < long > ()) /*Float on purpose*/, yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1907 "frontend/parser.cpp"
    break;

  case 134: // expr_var: expr_var "**" expr_int
#line 431 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < long > ()) /*Float on purpose*/, ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1913 "frontend/parser.cpp"
    break;

  case 135: // expr_var: expr_int "*" expr_var
#line 433 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1919 "frontend/parser.cpp"
    break;

  case 136: // expr_var: expr_float "*" expr_var
#line 434 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1925 "frontend/parser.cpp"
    break;

  case 137: // expr_var: expr_var "*" expr_int
#line 435 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1931 "frontend/parser.cpp"
    break;

  case 138: // expr_var: expr_var "*" expr_float
#line 436 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1937 "frontend/parser.cpp"
    break;

  case 139: // expr_var: expr_var "*" expr_var
#line 437 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1943 "frontend/parser.cpp"
    break;

  case 140: // expr_var: expr_int "/" expr_var
#line 439 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1949 "frontend/parser.cpp"
    break;

  case 141: // expr_var: expr_float "/" expr_var
#line 440 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1955 "frontend/parser.cpp"
    break;

  case 142: // expr_var: expr_var "/" expr_int
#line 441 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1961 "frontend/parser.cpp"
    break;

  case 143: // expr_var: expr_var "/" expr_float
#line 442 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1967 "frontend/parser.cpp"
    break;

  case 144: // expr_var: expr_var "/" expr_var
#line 443 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1973 "frontend/parser.cpp"
    break;

  case 145: // expr_var: expr_int "%" expr_var
#line 445 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1979 "frontend/parser.cpp"
    break;

  case 146: // expr_var: expr_float "%" expr_var
#line 446 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1985 "frontend/parser.cpp"
    break;

  case 147: // expr_var: expr_var "%" expr_int
#line 447 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1991 "frontend/parser.cpp"
    break;

  case 148: // expr_var: expr_var "%" expr_float
#line 448 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1997 "frontend/parser.cpp"
    break;

  case 149: // expr_var: expr_var "%" expr_var
#line 449 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 2003 "frontend/parser.cpp"
    break;

  case 150: // expr_var: expr_int "+" expr_var
#line 451 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2009 "frontend/parser.cpp"
    break;

  case 151: // expr_var: expr_float "+" expr_var
#line 452 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2015 "frontend/parser.cpp"
    break;

  case 152: // expr_var: expr_var "+" expr_int
#line 453 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2021 "frontend/parser.cpp"
    break;

  case 153: // expr_var: expr_var "+" expr_float
#line 454 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2027 "frontend/parser.cpp"
    break;

  case 154: // expr_var: expr_mat "+" expr_mat
#line 455 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2033 "frontend/parser.cpp"
    break;

  case 155: // expr_var: expr_var "+" expr_mat
#line 456 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2039 "frontend/parser.cpp"
    break;

  case 156: // expr_var: expr_mat "+" expr_var
#line 457 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2045 "frontend/parser.cpp"
    break;

  case 157: // expr_var: expr_var "+" expr_var
#line 458 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2051 "frontend/parser.cpp"
    break;

  case 158: // expr_var: expr_int "-" expr_var
#line 460 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2057 "frontend/parser.cpp"
    break;

  case 159: // expr_var: expr_float "-" expr_var
#line 461 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2063 "frontend/parser.cpp"
    break;

  case 160: // expr_var: expr_var "-" expr_int
#line 462 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2069 "frontend/parser.cpp"
    break;

  case 161: // expr_var: expr_var "-" expr_float
#line 463 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2075 "frontend/parser.cpp"
    break;

  case 162: // expr_var: expr_var "-" expr_var
#line 464 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2081 "frontend/parser.cpp"
    break;

  case 163: // expr_var: expr_int "<<" expr_var
#line 466 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2087 "frontend/parser.cpp"
    break;

  case 164: // expr_var: expr_var "<<" expr_int
#line 467 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2093 "frontend/parser.cpp"
    break;

  case 165: // expr_var: expr_var "<<" expr_var
#line 468 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2099 "frontend/parser.cpp"
    break;

  case 166: // expr_var: expr_int ">>" expr_var
#line 470 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2105 "frontend/parser.cpp"
    break;

  case 167: // expr_var: expr_var ">>" expr_int
#line 471 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2111 "frontend/parser.cpp"
    break;

  case 168: // expr_var: expr_var ">>" expr_var
#line 472 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2117 "frontend/parser.cpp"
    break;

  case 169: // expr_var: expr_int ">" expr_var
#line 474 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2123 "frontend/parser.cpp"
    break;

  case 170: // expr_var: expr_float ">" expr_var
#line 475 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2129 "frontend/parser.cpp"
    break;

  case 171: // expr_var: expr_str ">" expr_var
#line 476 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2135 "frontend/parser.cpp"
    break;

  case 172: // expr_var: expr_var ">" expr_int
#line 477 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2141 "frontend/parser.cpp"
    break;

  case 173: // expr_var: expr_var ">" expr_float
#line 478 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2147 "frontend/parser.cpp"
    break;

  case 174: // expr_var: expr_var ">" expr_str
#line 479 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2153 "frontend/parser.cpp"
    break;

  case 175: // expr_var: expr_var ">" expr_var
#line 480 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2159 "frontend/parser.cpp"
    break;

  case 176: // expr_var: expr_int ">=" expr_var
#line 482 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2165 "frontend/parser.cpp"
    break;

  case 177: // expr_var: expr_float ">=" expr_var
#line 483 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2171 "frontend/parser.cpp"
    break;

  case 178: // expr_var: expr_str ">=" expr_var
#line 484 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2177 "frontend/parser.cpp"
    break;

  case 179: // expr_var: expr_var ">=" expr_int
#line 485 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2183 "frontend/parser.cpp"
    break;

  case 180: // expr_var: expr_var ">=" expr_float
#line 486 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2189 "frontend/parser.cpp"
    break;

  case 181: // expr_var: expr_var ">=" expr_str
#line 487 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2195 "frontend/parser.cpp"
    break;

  case 182: // expr_var: expr_var ">=" expr_var
#line 488 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2201 "frontend/parser.cpp"
    break;

  case 183: // expr_var: expr_int "<" expr_var
#line 490 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2207 "frontend/parser.cpp"
    break;

  case 184: // expr_var: expr_float "<" expr_var
#line 491 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2213 "frontend/parser.cpp"
    break;

  case 185: // expr_var: expr_str "<" expr_var
#line 492 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2219 "frontend/parser.cpp"
    break;

  case 186: // expr_var: expr_var "<" expr_int
#line 493 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2225 "frontend/parser.cpp"
    break;

  case 187: // expr_var: expr_var "<" expr_float
#line 494 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2231 "frontend/parser.cpp"
    break;

  case 188: // expr_var: expr_var "<" expr_str
#line 495 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2237 "frontend/parser.cpp"
    break;

  case 189: // expr_var: expr_var "<" expr_var
#line 496 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2243 "frontend/parser.cpp"
    break;

  case 190: // expr_var: expr_int "<=" expr_var
#line 498 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2249 "frontend/parser.cpp"
    break;

  case 191: // expr_var: expr_float "<=" expr_var
#line 499 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2255 "frontend/parser.cpp"
    break;

  case 192: // expr_var: expr_str "<=" expr_var
#line 500 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2261 "frontend/parser.cpp"
    break;

  case 193: // expr_var: expr_var "<=" expr_int
#line 501 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2267 "frontend/parser.cpp"
    break;

  case 194: // expr_var: expr_var "<=" expr_float
#line 502 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2273 "frontend/parser.cpp"
    break;

  case 195: // expr_var: expr_var "<=" expr_str
#line 503 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2279 "frontend/parser.cpp"
    break;

  case 196: // expr_var: expr_var "<=" expr_var
#line 504 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2285 "frontend/parser.cpp"
    break;

  case 197: // expr_var: expr_int "==" expr_var
#line 506 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2291 "frontend/parser.cpp"
    break;

  case 198: // expr_var: expr_float "==" expr_var
#line 507 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2297 "frontend/parser.cpp"
    break;

  case 199: // expr_var: expr_str "==" expr_var
#line 508 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2303 "frontend/parser.cpp"
    break;

  case 200: // expr_var: expr_bool "==" expr_var
#line 509 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2309 "frontend/parser.cpp"
    break;

  case 201: // expr_var: expr_none "==" expr_var
#line 510 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2315 "frontend/parser.cpp"
    break;

  case 204: // expr_var: expr_var "==" expr_int
#line 513 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2321 "frontend/parser.cpp"
    break;

  case 205: // expr_var: expr_var "==" expr_float
#line 514 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2327 "frontend/parser.cpp"
    break;

  case 206: // expr_var: expr_var "==" expr_str
#line 515 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2333 "frontend/parser.cpp"
    break;

  case 207: // expr_var: expr_var "==" expr_bool
#line 516 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2339 "frontend/parser.cpp"
    break;

  case 208: // expr_var: expr_var "==" expr_none
#line 517 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2345 "frontend/parser.cpp"
    break;

  case 209: // expr_var: expr_var "==" expr_struct
#line 518 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2351 "frontend/parser.cpp"
    break;

  case 210: // expr_var: expr_mat "==" expr_mat
#line 519 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2357 "frontend/parser.cpp"
    break;

  case 211: // expr_var: expr_var "==" expr_mat
#line 520 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2363 "frontend/parser.cpp"
    break;

  case 212: // expr_var: expr_mat "==" expr_var
#line 521 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2369 "frontend/parser.cpp"
    break;

  case 213: // expr_var: expr_var "==" expr_var
#line 522 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2375 "frontend/parser.cpp"
    break;

  case 214: // expr_var: expr_int "!=" expr_var
#line 524 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2381 "frontend/parser.cpp"
    break;

  case 215: // expr_var: expr_float "!=" expr_var
#line 525 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2387 "frontend/parser.cpp"
    break;

  case 216: // expr_var: expr_str "!=" expr_var
#line 526 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2393 "frontend/parser.cpp"
    break;

  case 217: // expr_var: expr_bool "!=" expr_var
#line 527 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2399 "frontend/parser.cpp"
    break;

  case 218: // expr_var: expr_none "!=" expr_var
#line 528 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2405 "frontend/parser.cpp"
    break;

  case 221: // expr_var: expr_var "!=" expr_int
#line 531 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2411 "frontend/parser.cpp"
    break;

  case 222: // expr_var: expr_var "!=" expr_float
#line 532 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2417 "frontend/parser.cpp"
    break;

  case 223: // expr_var: expr_var "!=" expr_str
#line 533 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2423 "frontend/parser.cpp"
    break;

  case 224: // expr_var: expr_var "!=" expr_bool
#line 534 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2429 "frontend/parser.cpp"
    break;

  case 225: // expr_var: expr_var "!=" expr_none
#line 535 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2435 "frontend/parser.cpp"
    break;

  case 226: // expr_var: expr_var "!=" expr_struct
#line 536 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2441 "frontend/parser.cpp"
    break;

  case 227: // expr_var: expr_mat "!=" expr_mat
#line 537 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2447 "frontend/parser.cpp"
    break;

  case 228: // expr_var: expr_var "!=" expr_mat
#line 538 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2453 "frontend/parser.cpp"
    break;

  case 229: // expr_var: expr_mat "!=" expr_var
#line 539 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2459 "frontend/parser.cpp"
    break;

  case 230: // expr_var: expr_var "!=" expr_var
#line 540 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2465 "frontend/parser.cpp"
    break;

  case 231: // expr_var: expr_int "&" expr_var
#line 542 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2471 "frontend/parser.cpp"
    break;

  case 232: // expr_var: expr_var "&" expr_int
#line 543 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2477 "frontend/parser.cpp"
    break;

  case 233: // expr_var: expr_var "&" expr_var
#line 544 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2483 "frontend/parser.cpp"
    break;

  case 234: // expr_var: expr_int "^" expr_var
#line 546 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2489 "frontend/parser.cpp"
    break;

  case 235: // expr_var: expr_var "^" expr_int
#line 547 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2495 "frontend/parser.cpp"
    break;

  case 236: // expr_var: expr_var "^" expr_var
#line 548 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2501 "frontend/parser.cpp"
    break;

  case 237: // expr_var: expr_int "|" expr_var
#line 550 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2507 "frontend/parser.cpp"
    break;

  case 238: // expr_var: expr_var "|" expr_int
#line 551 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2513 "frontend/parser.cpp"
    break;

  case 239: // expr_var: expr_var "|" expr_var
#line 552 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2519 "frontend/parser.cpp"
    break;

  case 244: // expr_var: expr_none "in" expr_mat
#line 558 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2525 "frontend/parser.cpp"
    break;

  case 246: // expr_var: expr_mat "in" expr_mat
#line 560 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2531 "frontend/parser.cpp"
    break;

  case 251: // expr_var: expr_none "in" expr_var
#line 565 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2537 "frontend/parser.cpp"
    break;

  case 253: // expr_var: expr_mat "in" expr_var
#line 567 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2543 "frontend/parser.cpp"
    break;

  case 254: // expr_var: expr_var "in" expr_str
#line 568 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2549 "frontend/parser.cpp"
    break;

  case 255: // expr_var: expr_var "in" expr_var
#line 569 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2555 "frontend/parser.cpp"
    break;

  case 256: // expr_var: expr_bool "and" expr_var
#line 571 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2561 "frontend/parser.cpp"
    break;

  case 257: // expr_var: expr_var "and" expr_bool
#line 572 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2567 "frontend/parser.cpp"
    break;

  case 258: // expr_var: expr_var "and" expr_var
#line 573 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2573 "frontend/parser.cpp"
    break;

  case 259: // expr_var: expr_bool "or" expr_var
#line 575 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2579 "frontend/parser.cpp"
    break;

  case 260: // expr_var: expr_var "or" expr_bool
#line 576 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2585 "frontend/parser.cpp"
    break;

  case 261: // expr_var: expr_var "or" expr_var
#line 577 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2591 "frontend/parser.cpp"
    break;

  case 262: // expr_var: "not" expr_var
#line 579 "frontend/parser.yy"
                         { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseUnaryPrefixExpr(yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LNOT)); }
#line 2597 "frontend/parser.cpp"
    break;

  case 263: // expr_var: "~" expr_var
#line 581 "frontend/parser.yy"
                         { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseUnaryPrefixExpr(yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BNOT)); }
#line 2603 "frontend/parser.cpp"
    break;

  case 264: // expr_var: expr_int "++" expr_var
#line 583 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2609 "frontend/parser.cpp"
    break;

  case 265: // expr_var: expr_float "++" expr_var
#line 584 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2615 "frontend/parser.cpp"
    break;

  case 266: // expr_var: expr_str "++" expr_var
#line 585 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2621 "frontend/parser.cpp"
    break;

  case 267: // expr_var: expr_bool "++" expr_var
#line 586 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2627 "frontend/parser.cpp"
    break;

  case 268: // expr_var: expr_none "++" expr_var
#line 587 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseNone(), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2633 "frontend/parser.cpp"
    break;

  case 269: // expr_var: expr_var "++" expr_int
#line 588 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2639 "frontend/parser.cpp"
    break;

  case 270: // expr_var: expr_var "++" expr_float
#line 589 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2645 "frontend/parser.cpp"
    break;

  case 271: // expr_var: expr_var "++" expr_str
#line 590 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2651 "frontend/parser.cpp"
    break;

  case 272: // expr_var: expr_var "++" expr_bool
#line 591 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2657 "frontend/parser.cpp"
    break;

  case 273: // expr_var: expr_var "++" expr_none
#line 592 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseNone(), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2663 "frontend/parser.cpp"
    break;

  case 274: // expr_var: expr_var "++" expr_var
#line 593 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2669 "frontend/parser.cpp"
    break;

  case 275: // matrix: "[" "]"
#line 597 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(std::vector<ptc::ir::Expr *>{}); }
#line 2675 "frontend/parser.cpp"
    break;

  case 276: // matrix: "[" matvals "]"
#line 598 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2681 "frontend/parser.cpp"
    break;

  case 277: // matrix: "[" "terminator (\\n or ;)" matvals "]"
#line 599 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2687 "frontend/parser.cpp"
    break;

  case 278: // matrix: "[" matvals "terminator (\\n or ;)" "]"
#line 600 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2693 "frontend/parser.cpp"
    break;

  case 279: // matrix: "[" "terminator (\\n or ;)" matvals "terminator (\\n or ;)" "]"
#line 601 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2699 "frontend/parser.cpp"
    break;

  case 280: // matvals: expr
#line 604 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixValue(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2705 "frontend/parser.cpp"
    break;

  case 281: // matvals: matvals "," expr
#line 605 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2711 "frontend/parser.cpp"
    break;

  case 282: // matvals: matvals "," "terminator (\\n or ;)" expr
#line 606 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[3].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2717 "frontend/parser.cpp"
    break;

  case 283: // expr_mat: matrix
#line 610 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2723 "frontend/parser.cpp"
    break;

  case 284: // expr_mat: "(" matrix ")"
#line 611 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2729 "frontend/parser.cpp"
    break;

  case 285: // range: "(" range ")"
#line 613 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2735 "frontend/parser.cpp"
    break;

  case 286: // range: int_val ".." int_val
#line 614 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseRange(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2741 "frontend/parser.cpp"
    break;

  case 287: // range: int_val "," int_val ".." int_val
#line 615 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseRange(yystack_[4].value.as < ptc::ir::Expr * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2747 "frontend/parser.cpp"
    break;

  case 288: // int_val: expr_int
#line 617 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 2753 "frontend/parser.cpp"
    break;

  case 289: // int_val: expr_var
#line 618 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2759 "frontend/parser.cpp"
    break;

  case 302: // expr_none: "none"
#line 635 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseNone(); }
#line 2765 "frontend/parser.cpp"
    break;

  case 303: // expr_none: "(" "none" ")"
#line 636 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseNone(); }
#line 2771 "frontend/parser.cpp"
    break;

  case 310: // expr_int: "int"
#line 651 "frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 2777 "frontend/parser.cpp"
    break;

  case 311: // expr_int: "-" expr_int
#line 652 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 2783 "frontend/parser.cpp"
    break;

  case 312: // expr_int: "(" expr_int ")"
#line 653 "frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 2789 "frontend/parser.cpp"
    break;

  case 313: // expr_int: "~" expr_int
#line 654 "frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 2795 "frontend/parser.cpp"
    break;

  case 314: // expr_int: expr_int "*" expr_int
#line 655 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 2801 "frontend/parser.cpp"
    break;

  case 315: // expr_int: expr_int "/" expr_int
#line 656 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 2807 "frontend/parser.cpp"
    break;

  case 316: // expr_int: expr_int "%" expr_int
#line 657 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 2813 "frontend/parser.cpp"
    break;

  case 317: // expr_int: expr_int "-" expr_int
#line 658 "frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 2819 "frontend/parser.cpp"
    break;

  case 318: // expr_int: expr_int "+" expr_int
#line 659 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 2825 "frontend/parser.cpp"
    break;

  case 319: // expr_int: expr_int "<<" expr_int
#line 660 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 2831 "frontend/parser.cpp"
    break;

  case 320: // expr_int: expr_int ">>" expr_int
#line 661 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 2837 "frontend/parser.cpp"
    break;

  case 321: // expr_int: expr_int "&" expr_int
#line 662 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 2843 "frontend/parser.cpp"
    break;

  case 322: // expr_int: expr_int "^" expr_int
#line 663 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 2849 "frontend/parser.cpp"
    break;

  case 323: // expr_int: expr_int "|" expr_int
#line 664 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 2855 "frontend/parser.cpp"
    break;

  case 324: // expr_float: "float"
#line 668 "frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 2861 "frontend/parser.cpp"
    break;

  case 325: // expr_float: "-" expr_float
#line 669 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 2867 "frontend/parser.cpp"
    break;

  case 326: // expr_float: "(" expr_float ")"
#line 670 "frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 2873 "frontend/parser.cpp"
    break;

  case 327: // expr_float: expr_float "**" expr_float
#line 671 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2879 "frontend/parser.cpp"
    break;

  case 328: // expr_float: expr_float "**" expr_int
#line 672 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2885 "frontend/parser.cpp"
    break;

  case 329: // expr_float: expr_int "**" expr_float
#line 673 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2891 "frontend/parser.cpp"
    break;

  case 330: // expr_float: expr_float "*" expr_float
#line 674 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 2897 "frontend/parser.cpp"
    break;

  case 331: // expr_float: expr_float "*" expr_int
#line 675 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 2903 "frontend/parser.cpp"
    break;

  case 332: // expr_float: expr_int "*" expr_float
#line 676 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 2909 "frontend/parser.cpp"
    break;

  case 333: // expr_float: expr_float "/" expr_float
#line 677 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 2915 "frontend/parser.cpp"
    break;

  case 334: // expr_float: expr_float "/" expr_int
#line 678 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 2921 "frontend/parser.cpp"
    break;

  case 335: // expr_float: expr_int "/" expr_float
#line 679 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 2927 "frontend/parser.cpp"
    break;

  case 336: // expr_float: expr_float "%" expr_float
#line 680 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2933 "frontend/parser.cpp"
    break;

  case 337: // expr_float: expr_float "%" expr_int
#line 681 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2939 "frontend/parser.cpp"
    break;

  case 338: // expr_float: expr_int "%" expr_float
#line 682 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2945 "frontend/parser.cpp"
    break;

  case 339: // expr_float: expr_float "-" expr_float
#line 683 "frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 2951 "frontend/parser.cpp"
    break;

  case 340: // expr_float: expr_float "-" expr_int
#line 684 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 2957 "frontend/parser.cpp"
    break;

  case 341: // expr_float: expr_int "-" expr_float
#line 685 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 2963 "frontend/parser.cpp"
    break;

  case 342: // expr_float: expr_float "+" expr_float
#line 686 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 2969 "frontend/parser.cpp"
    break;

  case 343: // expr_float: expr_float "+" expr_int
#line 687 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 2975 "frontend/parser.cpp"
    break;

  case 344: // expr_float: expr_int "+" expr_float
#line 688 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 2981 "frontend/parser.cpp"
    break;

  case 345: // expr_str: "string"
#line 692 "frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2987 "frontend/parser.cpp"
    break;

  case 346: // expr_str: "(" expr_str ")"
#line 693 "frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 2993 "frontend/parser.cpp"
    break;

  case 347: // expr_str: expr_str "++" expr_str
#line 694 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 2999 "frontend/parser.cpp"
    break;

  case 348: // expr_str: expr_str "++" expr_int
#line 695 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 3005 "frontend/parser.cpp"
    break;

  case 349: // expr_str: expr_str "++" expr_float
#line 696 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 3011 "frontend/parser.cpp"
    break;

  case 350: // expr_str: expr_str "++" expr_bool
#line 697 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3017 "frontend/parser.cpp"
    break;

  case 351: // expr_str: expr_str "++" expr_none
#line 698 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 3023 "frontend/parser.cpp"
    break;

  case 352: // expr_str: expr_int "++" expr_str
#line 699 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 3029 "frontend/parser.cpp"
    break;

  case 353: // expr_str: expr_int "++" expr_int
#line 700 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 3035 "frontend/parser.cpp"
    break;

  case 354: // expr_str: expr_int "++" expr_float
#line 701 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 3041 "frontend/parser.cpp"
    break;

  case 355: // expr_str: expr_int "++" expr_bool
#line 702 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3047 "frontend/parser.cpp"
    break;

  case 356: // expr_str: expr_int "++" expr_none
#line 703 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 3053 "frontend/parser.cpp"
    break;

  case 357: // expr_str: expr_float "++" expr_str
#line 704 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 3059 "frontend/parser.cpp"
    break;

  case 358: // expr_str: expr_float "++" expr_int
#line 705 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 3065 "frontend/parser.cpp"
    break;

  case 359: // expr_str: expr_float "++" expr_float
#line 706 "frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 3071 "frontend/parser.cpp"
    break;

  case 360: // expr_str: expr_float "++" expr_bool
#line 707 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3077 "frontend/parser.cpp"
    break;

  case 361: // expr_str: expr_float "++" expr_none
#line 708 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 3083 "frontend/parser.cpp"
    break;

  case 362: // expr_str: expr_bool "++" expr_str
#line 709 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 3089 "frontend/parser.cpp"
    break;

  case 363: // expr_str: expr_bool "++" expr_int
#line 710 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 3095 "frontend/parser.cpp"
    break;

  case 364: // expr_str: expr_bool "++" expr_float
#line 711 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 3101 "frontend/parser.cpp"
    break;

  case 365: // expr_str: expr_bool "++" expr_bool
#line 712 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3107 "frontend/parser.cpp"
    break;

  case 366: // expr_str: expr_bool "++" expr_none
#line 713 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 3113 "frontend/parser.cpp"
    break;

  case 367: // expr_str: expr_none "++" expr_str
#line 714 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 3119 "frontend/parser.cpp"
    break;

  case 368: // expr_str: expr_none "++" expr_int
#line 715 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 3125 "frontend/parser.cpp"
    break;

  case 369: // expr_str: expr_none "++" expr_float
#line 716 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 3131 "frontend/parser.cpp"
    break;

  case 370: // expr_str: expr_none "++" expr_bool
#line 717 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3137 "frontend/parser.cpp"
    break;

  case 371: // expr_str: expr_none "++" expr_none
#line 718 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 3143 "frontend/parser.cpp"
    break;

  case 372: // expr_bool: "bool"
#line 722 "frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 3149 "frontend/parser.cpp"
    break;

  case 373: // expr_bool: "(" expr_bool ")"
#line 723 "frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 3155 "frontend/parser.cpp"
    break;

  case 374: // expr_bool: "not" expr_bool
#line 724 "frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 3161 "frontend/parser.cpp"
    break;

  case 375: // expr_bool: expr_bool "or" expr_bool
#line 725 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 3167 "frontend/parser.cpp"
    break;

  case 376: // expr_bool: expr_bool "and" expr_bool
#line 726 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 3173 "frontend/parser.cpp"
    break;

  case 377: // expr_bool: expr_bool "==" expr_bool
#line 728 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 3179 "frontend/parser.cpp"
    break;

  case 378: // expr_bool: expr_int "==" expr_int
#line 729 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 3185 "frontend/parser.cpp"
    break;

  case 379: // expr_bool: expr_int "==" expr_float
#line 730 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 3191 "frontend/parser.cpp"
    break;

  case 380: // expr_bool: expr_float "==" expr_float
#line 731 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 3197 "frontend/parser.cpp"
    break;

  case 381: // expr_bool: expr_float "==" expr_int
#line 732 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 3203 "frontend/parser.cpp"
    break;

  case 382: // expr_bool: expr_str "==" expr_str
#line 733 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 3209 "frontend/parser.cpp"
    break;

  case 383: // expr_bool: expr_none "==" expr_none
#line 734 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 3215 "frontend/parser.cpp"
    break;

  case 384: // expr_bool: expr_bool "!=" expr_bool
#line 736 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 3221 "frontend/parser.cpp"
    break;

  case 385: // expr_bool: expr_int "!=" expr_int
#line 737 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 3227 "frontend/parser.cpp"
    break;

  case 386: // expr_bool: expr_int "!=" expr_float
#line 738 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 3233 "frontend/parser.cpp"
    break;

  case 387: // expr_bool: expr_float "!=" expr_float
#line 739 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 3239 "frontend/parser.cpp"
    break;

  case 388: // expr_bool: expr_float "!=" expr_int
#line 740 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 3245 "frontend/parser.cpp"
    break;

  case 389: // expr_bool: expr_str "!=" expr_str
#line 741 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 3251 "frontend/parser.cpp"
    break;

  case 390: // expr_bool: expr_none "!=" expr_none
#line 742 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 3257 "frontend/parser.cpp"
    break;

  case 391: // expr_bool: expr_int ">" expr_int
#line 744 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 3263 "frontend/parser.cpp"
    break;

  case 392: // expr_bool: expr_int ">" expr_float
#line 745 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 3269 "frontend/parser.cpp"
    break;

  case 393: // expr_bool: expr_float ">" expr_float
#line 746 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 3275 "frontend/parser.cpp"
    break;

  case 394: // expr_bool: expr_float ">" expr_int
#line 747 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 3281 "frontend/parser.cpp"
    break;

  case 395: // expr_bool: expr_str ">" expr_str
#line 748 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 3287 "frontend/parser.cpp"
    break;

  case 396: // expr_bool: expr_int "<" expr_int
#line 750 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 3293 "frontend/parser.cpp"
    break;

  case 397: // expr_bool: expr_int "<" expr_float
#line 751 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 3299 "frontend/parser.cpp"
    break;

  case 398: // expr_bool: expr_float "<" expr_float
#line 752 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 3305 "frontend/parser.cpp"
    break;

  case 399: // expr_bool: expr_float "<" expr_int
#line 753 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 3311 "frontend/parser.cpp"
    break;

  case 400: // expr_bool: expr_str "<" expr_str
#line 754 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 3317 "frontend/parser.cpp"
    break;

  case 401: // expr_bool: expr_int ">=" expr_int
#line 756 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 3323 "frontend/parser.cpp"
    break;

  case 402: // expr_bool: expr_int ">=" expr_float
#line 757 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 3329 "frontend/parser.cpp"
    break;

  case 403: // expr_bool: expr_float ">=" expr_float
#line 758 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 3335 "frontend/parser.cpp"
    break;

  case 404: // expr_bool: expr_float ">=" expr_int
#line 759 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 3341 "frontend/parser.cpp"
    break;

  case 405: // expr_bool: expr_str ">=" expr_str
#line 760 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 3347 "frontend/parser.cpp"
    break;

  case 406: // expr_bool: expr_int "<=" expr_int
#line 762 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 3353 "frontend/parser.cpp"
    break;

  case 407: // expr_bool: expr_int "<=" expr_float
#line 763 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 3359 "frontend/parser.cpp"
    break;

  case 408: // expr_bool: expr_float "<=" expr_float
#line 764 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 3365 "frontend/parser.cpp"
    break;

  case 409: // expr_bool: expr_float "<=" expr_int
#line 765 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 3371 "frontend/parser.cpp"
    break;

  case 410: // expr_bool: expr_str "<=" expr_str
#line 766 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 3377 "frontend/parser.cpp"
    break;

  case 411: // expr_bool: expr_str "in" expr_str
#line 768 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[0].value.as < std::string > ().find(yystack_[2].value.as < std::string > ()) != std::string::npos; }
#line 3383 "frontend/parser.cpp"
    break;

  case 418: // mattype: "identifier" matsq
#line 782 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3389 "frontend/parser.cpp"
    break;

  case 419: // mattype: "'int'" matsq
#line 783 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(INT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3395 "frontend/parser.cpp"
    break;

  case 420: // mattype: "'float'" matsq
#line 784 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(FLOAT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3401 "frontend/parser.cpp"
    break;

  case 421: // mattype: "'string'" matsq
#line 785 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(STRING_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3407 "frontend/parser.cpp"
    break;

  case 422: // mattype: "'bool'" matsq
#line 786 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(BOOL_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3413 "frontend/parser.cpp"
    break;

  case 423: // mattype: "any" matsq
#line 787 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(ANY_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3419 "frontend/parser.cpp"
    break;

  case 431: // matsq: "[" "]"
#line 796 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(scanner->parseInt(-1)); }
#line 3425 "frontend/parser.cpp"
    break;

  case 432: // matsq: "[" "]" matsq
#line 798 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), scanner->parseInt(-1)); }
#line 3431 "frontend/parser.cpp"
    break;

  case 433: // type: "'int'" "?"
#line 803 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, true, true); }
#line 3437 "frontend/parser.cpp"
    break;

  case 434: // type: "'float'" "?"
#line 804 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, true, true); }
#line 3443 "frontend/parser.cpp"
    break;

  case 435: // type: "'string'" "?"
#line 805 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, true, true); }
#line 3449 "frontend/parser.cpp"
    break;

  case 436: // type: "'bool'" "?"
#line 806 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, true, true); }
#line 3455 "frontend/parser.cpp"
    break;

  case 437: // type: "identifier" "?"
#line 807 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[1].value.as < std::string > (), true, true); }
#line 3461 "frontend/parser.cpp"
    break;

  case 440: // type: mattype "?"
#line 810 "frontend/parser.yy"
       { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 3467 "frontend/parser.cpp"
    break;

  case 441: // type: "'int'"
#line 811 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, false, true); }
#line 3473 "frontend/parser.cpp"
    break;

  case 442: // type: "'float'"
#line 812 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, false, true); }
#line 3479 "frontend/parser.cpp"
    break;

  case 443: // type: "'string'"
#line 813 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, false, true); }
#line 3485 "frontend/parser.cpp"
    break;

  case 444: // type: "'bool'"
#line 814 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, false, true); }
#line 3491 "frontend/parser.cpp"
    break;

  case 445: // type: "any"
#line 815 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(ANY_CSTR, false, true); }
#line 3497 "frontend/parser.cpp"
    break;

  case 446: // type: "identifier"
#line 816 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[0].value.as < std::string > (), false, true); }
#line 3503 "frontend/parser.cpp"
    break;

  case 447: // type: "external identifier"
#line 817 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExtType(yystack_[0].value.as < std::string > (), false); }
#line 3509 "frontend/parser.cpp"
    break;

  case 449: // type: mattype
#line 819 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 3515 "frontend/parser.cpp"
    break;


#line 3519 "frontend/parser.cpp"

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
    1881,  -659,  -659,  -659,  -659,  -659,  -659,  -659,  1729,    17,
      53,  2069,  2069,   -29,    43,   -22,  -659,  -659,  -659,  -659,
    2069,  -659,  -659,    -9,     1,     3,    32,    40,    50,     4,
     365,    45,   134,  1378,  -659,  -659,   145,   145,  -659,  -659,
     143,  -659,   167,  -659,  2194,  -659,   174,  -659,  -659,   145,
     145,   145,  1822,  2490,  -659,   612,   402,   521,  2210,  1204,
    1128,   453,    41,    69,    22,   133,   236,    19,  1975,   230,
     612,   402,   521,  2729,  2787,  1333,   618,  2069,  -659,   236,
    -659,   108,   553,   553,   429,  -659,  -659,  -659,  -659,   363,
    2210,  1204,  1128,  -659,   363,  -659,   453,   267,   269,  -659,
     275,  -659,  -659,   334,    43,  -659,    43,  -659,    43,  -659,
      43,  -659,    37,   773,  -659,   372,   678,    49,  1115,    43,
    -659,  -659,  -659,  1202,  1125,  -659,  -659,  -659,  -659,  2351,
    -659,  -659,  -659,  -659,  -659,  1339,  2069,   367,  2270,  -659,
    -659,   329,  2069,  -659,  -659,  -659,  2069,  2069,  2069,  2069,
    2069,  2069,  2069,  2069,  2069,  2069,  2069,  2069,  2069,  -659,
    1012,  1202,  2069,  2069,  2069,  2069,  2069,  2069,  2069,  2069,
    2069,  2069,  1854,  2069,  2069,  2069,  2069,  2069,  2069,  2069,
    2069,  2069,  2069,  2069,   -42,  -659,  1202,  2069,  2069,  2069,
    2069,  -659,  2069,  2069,  2069,  2069,  2069,  2069,  2069,  2069,
    2069,  2069,  2069,  2069,  2069,  2069,  2069,  2069,  2069,  2069,
    2069,  2069,  2069,  2069,  2069,  2069,  2069,  2069,  2069,  2069,
    2069,  2069,  2069,  2069,  2069,  2069,  2069,  2069,  2069,  2069,
    2069,  2069,  2069,  2069,  2069,  2069,  2069,  2069,  2069,  2069,
    2069,  2069,  2069,  2069,  2069,  2069,  2069,    43,  -659,  -659,
     890,    98,   411,  -659,  1202,   416,  -659,  -659,  -659,  -659,
    -659,  -659,   123,   419,  -659,   447,  1620,  1015,   429,   429,
    -659,   553,   553,   553,   553,   553,   553,   429,   429,   429,
     429,   429,   553,   553,   553,   553,   553,   553,  2069,    43,
     -22,  2069,  -659,  -659,  -659,  -659,   415,    46,  -659,   423,
      56,   374,   434,    18,   431,   721,  2490,   135,  2210,  -659,
     388,   432,   397,   460,  -659,   238,   403,   460,  -659,    -3,
     -25,   455,    23,   485,  2351,  -659,  1959,   489,   501,  -659,
    2440,  -659,  -659,  -659,  -659,  -659,  -659,  -659,  -659,  -659,
    -659,  -659,  -659,  -659,     5,  -659,   240,   695,   502,   379,
     747,   695,   379,   747,   364,   492,   506,   364,   492,   506,
     364,   492,   506,   364,   492,   506,  2520,   685,  2811,  1884,
     482,   548,  2580,   715,  2550,   466,  2610,   446,   461,   460,
    2147,   973,  2640,  2835,  2670,  2859,  1272,  1255,  1272,  1255,
    2700,   129,  -659,  -659,  2367,  2102,   371,  -659,  2700,   129,
    -659,  -659,  2367,  2102,   371,  -659,  1106,  1345,  1731,   511,
    1106,  1345,  1731,   511,  1106,  1345,  1731,   511,  1106,  1345,
    1731,   511,  -659,  -659,   241,   695,   502,  2610,   117,  2700,
     129,  2700,   129,  2520,   685,  2811,  1884,   482,   548,  2610,
     117,  2700,  -659,  2700,  -659,  2610,   117,  2700,  -659,  2700,
    -659,   695,   379,   747,   695,   379,   747,   364,   492,   506,
     364,   492,   506,   364,   492,   506,   364,   506,  2520,   685,
    2811,  1884,   482,   548,  2610,   117,  2147,   973,  2640,  2835,
    2670,  2859,  1272,  1255,  1272,  1255,  2700,  2367,  2102,  2700,
    2367,  2102,  1106,  1345,  1731,  1106,  1345,  1731,  1106,  1345,
    1731,  1106,  1345,  1731,   695,   379,   747,   695,   379,   747,
     364,   492,   506,   364,   492,   506,   364,   492,   506,   364,
     492,   506,  2520,   685,  2811,  1884,   482,   548,  2610,   117,
    2700,  2367,  2102,  2700,  2367,  2102,  1106,  1345,  1731,  1106,
    1345,  1731,  1106,  1345,  1731,  1106,  1345,  1731,   517,  2520,
     685,  2811,  1884,   482,   548,  2610,   117,   446,  2700,   371,
    2700,   371,  1106,   511,  1106,   511,  1106,   511,  1106,   511,
    2520,   685,  2811,  1884,   482,   548,  2580,   715,  2550,   466,
    2610,   117,  2700,  -659,  2700,  -659,  -659,  -659,   534,  1329,
     737,  -659,   547,  -659,  -659,  2069,  -659,  1552,  -659,   429,
     429,   429,   429,   429,   755,   772,   755,   772,   540,   541,
     540,   541,   540,   541,  2883,   541,   870,  2272,  1668,   647,
     647,   755,   772,   755,   772,   540,   541,   540,   541,   540,
     541,   540,   541,  -659,  -659,  -659,  -659,     7,     7,  -659,
     495,   560,   572,    25,  -659,  2011,   126,   499,   538,   570,
      28,  -659,  1470,   242,  -659,   850,   567,  -659,  -659,  -659,
    -659,  2144,  2144,  2144,  -659,  2194,  2038,   593,  2069,  2194,
    -659,  2069,  -659,  -659,  -659,  -659,  -659,  -659,  -659,   126,
     607,  -659,  -659,   369,   369,  -659,  -659,  -659,   605,  -659,
     578,  -659,     7,   579,  -659,  -659,  -659,   344,   126,  -659,
    -659,   620,  -659,  1521,  -659,  1548,   243,  2069,  2426,   614,
    2442,   624,   204,  2758,   625,   626,   628,   638,  -659,   627,
    -659,   664,   616,  -659,  -659,   126,  -659,  2069,  -659,  2069,
     601,    29,  -659,  -659,  -659,   668,  -659,   669,  -659,  1702,
     650,  1975,   682,  2729,  2194,  2194,  2069,  2069,  2194,  2194,
    2194,  2194,  -659,  -659,  -659,  -659,  2194,  -659,  -659,  -659,
    -659,  -659,  -659,  -659,  -659,   676,   653,  -659,  -659,  -659,
    -659,   657,  -659,  -659,  -659,  -659,  -659,  -659,  -659,  2069,
    -659
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     9,   310,   324,   345,   372,   302,     0,     0,
       0,     0,     0,     0,   445,     0,    52,    44,    46,    48,
      36,    33,    34,     0,   441,   442,   443,   444,     0,     0,
     103,   104,     0,     0,     4,    10,     0,     0,    35,    15,
       0,    17,     0,    18,     0,    16,     0,    19,    20,     0,
       0,     0,     0,    96,   283,    95,    97,    98,    99,   100,
     101,   102,   448,   449,     0,   302,   103,   104,     0,   283,
       0,     0,     0,     0,     0,     0,     0,     0,   275,   103,
     280,     0,     0,     0,     0,   105,   106,   311,   325,   262,
       0,     0,     0,   374,   263,   313,     0,     0,     0,   423,
      31,    30,    37,     0,   433,   419,   434,   420,   435,   421,
     436,   422,     0,     0,    68,     0,     0,     0,     0,   437,
     125,   304,   418,     0,     0,   438,   126,     1,     3,     0,
       5,     8,     7,    14,    21,     0,     0,     0,     0,    28,
      29,     0,     0,    12,    13,    11,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,     0,     0,     0,     0,
       0,   124,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   439,   424,   440,
       0,    74,     0,   303,     0,   304,   107,   284,   312,   326,
     346,   373,     0,     0,   276,     0,     0,     0,     0,     0,
     313,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   431,
       0,     0,   426,   427,   428,   429,     0,     0,   415,     0,
     446,   447,     0,   416,     0,     0,   289,     0,   288,   306,
       0,     0,   115,   121,   425,     0,   116,   122,     6,   446,
     447,     0,     0,     0,     0,    23,     0,     0,     0,    92,
      91,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,   108,     0,    93,     0,   157,   155,   152,
     153,   162,   160,   161,   139,   137,   138,   144,   142,   143,
     149,   147,   148,   132,   134,   131,   274,   273,   269,   270,
     271,   272,   258,   257,   261,   260,   255,   254,   117,   123,
     233,   232,   239,   238,   236,   235,   165,   164,   168,   167,
     213,   211,   208,   209,   204,   205,   206,   207,   230,   228,
     225,   226,   221,   222,   223,   224,   175,   172,   173,   174,
     189,   186,   187,   188,   182,   179,   180,   181,   196,   193,
     194,   195,   128,   129,     0,   156,   154,   253,   246,   212,
     210,   229,   227,   268,   371,   368,   369,   367,   370,   251,
     244,   201,   383,   218,   390,   252,   245,   203,   202,   220,
     219,   150,   318,   344,   158,   317,   341,   135,   314,   332,
     140,   315,   335,   145,   316,   338,   133,   329,   264,   356,
     353,   354,   352,   355,   247,   240,   231,   321,   237,   323,
     234,   322,   163,   319,   166,   320,   197,   378,   379,   214,
     385,   386,   169,   391,   392,   183,   396,   397,   176,   401,
     402,   190,   406,   407,   151,   343,   342,   159,   340,   339,
     136,   331,   330,   141,   334,   333,   146,   337,   336,   130,
     328,   327,   265,   361,   358,   359,   357,   360,   248,   241,
     198,   381,   380,   215,   388,   387,   170,   394,   393,   184,
     399,   398,   177,   404,   403,   191,   409,   408,     0,   266,
     351,   348,   349,   347,   350,   249,   242,   411,   199,   382,
     216,   389,   171,   395,   185,   400,   178,   405,   192,   410,
     267,   366,   363,   364,   362,   365,   256,   376,   259,   375,
     250,   243,   200,   377,   217,   384,   430,   413,     0,     0,
       0,   305,     0,   277,   278,     0,   281,     0,   311,     0,
       0,     0,     0,     0,   318,   344,   317,   341,   314,   332,
     315,   335,   316,   338,     0,   329,   321,   323,   322,   319,
     320,   343,   342,   340,   339,   331,   330,   334,   333,   337,
     336,   328,   327,    78,   432,    32,    77,     0,    57,    54,
       0,     0,     0,     0,   414,     0,     0,     0,    73,     0,
       0,   290,     0,     0,   112,     0,     0,   307,   118,   113,
     119,     0,     0,     0,    74,     0,     0,    24,     0,     0,
     109,     0,   114,   120,   111,   110,   412,    76,    75,     0,
       0,   279,   282,   318,   317,   314,   315,   316,     0,    58,
       0,    55,    59,    61,   417,    66,    71,     0,     0,    69,
     294,     0,   292,     0,   291,     0,     0,     0,     0,     0,
     289,     0,     0,   288,     0,     0,     0,     0,    45,    25,
      26,     0,    51,    94,    64,     0,    56,     0,    60,     0,
       0,     0,    67,   297,   296,     0,   295,     0,   293,     0,
     308,   289,     0,   288,     0,     0,     0,     0,     0,     0,
       0,     0,    27,    47,    53,    49,     0,    65,    63,    62,
      72,    70,   300,   299,   298,     0,     0,   285,    39,    42,
     286,     0,    40,    43,    38,    41,    50,   301,   309,     0,
     287
  };

  const short
   Parser ::yypgoto_[] =
  {
    -659,  -659,   -85,   207,   -17,   113,  -637,  -658,  -659,   408,
    -659,  -659,  -659,  -659,  -659,  -659,  -659,  -659,  -659,  -659,
    -659,  -659,  -659,  -619,  -659,  -659,   635,  -659,   115,   568,
    -659,   561,  -659,  1169,   125,    -7,   639,  1107,  -566,   324,
     394,  1464,  1645,   -61,   -49,    -8,   385,   761,   926,  -659,
    -244,  -659,   386,   507
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    32,    33,   133,    34,   139,   140,   141,    36,   101,
      37,    38,    39,    40,    41,    42,    43,    44,    45,   755,
      46,   756,    47,   641,   642,    48,   115,   648,   649,    49,
      50,    51,   344,    52,    53,    54,    81,    70,   711,   712,
     185,    71,    72,   121,   311,    58,    91,    92,    96,    62,
     302,    63,   122,    64
  };

  const short
   Parser ::yytable_[] =
  {
      73,    69,    87,    90,    95,   255,   588,   718,    98,   695,
     638,   722,    98,   113,    98,   670,   130,   662,   688,   689,
      77,     3,     4,     5,     6,     7,     8,   250,     9,    78,
     123,   250,   250,    10,   250,   422,   423,   250,   250,   661,
     296,    11,   724,    98,   125,   124,   671,    12,    97,   638,
     297,    98,    98,   326,    98,   100,   123,     3,     4,   645,
     639,   732,    82,   309,   640,    14,   119,    98,   103,    83,
     104,   124,   106,   728,   266,    87,   270,    24,    25,    26,
      27,   114,   299,    84,   300,   301,   768,   769,   757,   310,
     772,   773,   774,   775,    79,    67,   715,   717,   776,   251,
     664,   108,   693,   640,    14,   699,   761,   -68,   308,   110,
     247,   263,   318,    35,   125,   308,    24,    25,    26,    27,
     264,   299,  -447,   300,   301,   119,   592,   112,   186,   137,
      85,    86,   187,    68,   127,   593,    89,    94,   249,   138,
     186,   589,   742,   253,   187,   131,    35,   654,   132,   265,
     189,   190,   135,   308,   349,   352,   355,   358,   361,   364,
     368,    90,    90,    90,   265,   381,   383,   385,   387,   389,
     394,   402,   407,   411,   415,   419,   136,   655,   308,    90,
      90,    90,    90,   142,   435,    90,    90,    90,    90,    90,
      90,   452,   455,   458,   461,   464,    90,   470,    90,   477,
     479,   481,   483,   485,   487,   490,   493,   496,   499,   502,
     505,   508,   511,   514,   517,   520,   524,    90,   531,   534,
     537,   540,   543,   546,   308,   551,    90,    90,    90,    90,
      90,    90,    90,   572,    90,    90,    90,    90,    90,   666,
     257,   306,    35,   746,   134,   747,   308,   254,   306,   117,
     659,    35,   672,   674,   702,   738,   143,   144,   145,   159,
     597,   598,   118,   604,   606,   608,   610,   612,   614,   616,
     617,   618,   619,   620,   621,   623,   625,   627,   629,   631,
     655,   289,   655,   655,   703,   739,   306,   347,   351,   354,
     357,   360,   363,   366,   372,   374,   376,   308,   380,   382,
     384,   386,   388,   390,   398,   406,   410,   414,   418,   130,
     288,   306,   425,   427,   429,   431,   290,   433,   439,   441,
     443,   445,   447,   449,   451,   454,   457,   460,   463,   466,
     468,   474,   476,   478,   480,   482,   484,   486,   489,   492,
     495,   498,   501,   504,   507,   510,   513,   516,   519,   522,
     528,   530,   533,   536,   539,   542,   545,   306,   549,   555,
     558,   560,   562,   564,   566,   568,   570,   576,   578,   580,
     582,   584,   160,   160,   161,   161,   116,   291,   117,   306,
     324,   304,   232,   730,   167,    59,   601,   602,   603,   172,
     172,   118,   327,    74,    59,    88,   201,   202,   203,   204,
      99,   694,    14,   184,   184,    59,   237,   238,   239,   240,
     105,   107,   109,   111,    24,    25,    26,    27,    59,   299,
     590,   300,   301,   192,   120,   126,   591,   193,   637,    59,
     306,   594,   113,     3,   119,   194,   195,    35,   268,    35,
     307,   646,  -446,   125,   644,   269,   657,   315,   248,   191,
     595,     3,     4,     5,     6,     7,     8,   232,     9,    84,
     120,   126,    59,    10,   191,   656,   658,   267,    88,   250,
     647,    11,   660,   120,   241,   242,   243,    12,   244,   235,
     236,   237,   238,   239,   240,   346,   245,   246,   242,    14,
     292,   244,   293,   232,   294,   665,   295,   663,   668,   245,
     246,    24,    25,    26,    27,   314,   299,   234,   300,   301,
     424,   669,   204,   186,    59,   235,   236,   237,   238,   239,
     240,    59,   232,    59,    79,    67,   223,    59,   678,   675,
     673,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,   676,    59,   196,   350,   353,   356,
     359,   362,   365,   369,   197,   198,   548,     3,     4,   681,
     276,   287,    82,   395,   403,   408,   412,   416,   420,    83,
     242,   243,   690,   244,   691,   692,   696,   436,   307,   697,
     698,   245,   246,    84,   453,   456,   459,   462,   465,   467,
     471,   683,   684,   685,   686,   687,   720,   488,   491,   494,
     497,   500,   503,   506,   509,   512,   515,   518,   521,   525,
     707,   532,   535,   538,   541,   544,   547,   725,   552,   726,
     303,   727,   729,   186,   744,   313,   573,   187,   261,   653,
     752,   317,   733,   586,   745,   748,   749,   188,   750,   241,
     242,   243,   322,   244,   308,   189,   190,   308,   751,   130,
      59,   245,   246,   713,   713,   713,   605,   607,   609,   611,
     613,   615,   599,   600,   601,   602,   603,   622,   624,   626,
     628,   630,   632,    59,   753,   634,    59,   754,   760,   379,
     762,   763,     3,     4,     5,     6,     7,     8,   777,     9,
     289,   766,   767,   310,    10,   308,   779,   308,   635,   252,
     743,    69,    11,   321,   160,   680,   161,   329,    12,    59,
     193,    59,   164,   165,   166,   167,   262,   778,   194,   195,
     305,   172,     0,     0,     0,     3,     4,     5,     6,     7,
       8,   308,     9,   651,     0,   184,     0,    10,   308,   308,
     244,     0,   191,     0,     0,    11,     0,   679,   245,   246,
       0,    12,     0,     0,     0,    79,    67,   303,     0,     0,
       0,    60,     0,   652,   220,   221,   222,   223,     0,    75,
      60,   308,   273,   274,   275,   276,   647,   306,     0,    35,
     306,    60,     0,   298,     0,   191,   710,   710,   710,   284,
     285,   286,   287,   191,    60,    14,     0,     0,    79,    67,
       0,     0,     0,     0,   643,    60,     0,    24,    25,    26,
      27,   650,   299,     0,   300,   301,     0,     0,     0,     0,
     191,     0,   191,     0,   191,     0,   191,     0,   306,     0,
     306,    14,     0,   741,   191,     0,     0,     0,    60,     0,
     191,     0,     0,    24,    25,    26,    27,     0,   299,     0,
     300,   301,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     9,   704,     0,   306,     0,    10,     0,     0,   191,
       0,   306,   306,     0,    11,     0,     0,     0,     0,     0,
      12,     0,     0,     0,     0,   599,   600,   601,   602,   603,
      60,     0,   705,     0,     0,     0,     0,    60,     0,    60,
     587,   280,   281,    60,   306,     0,     0,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
       0,    60,     0,   191,     0,     0,    61,    79,    67,   370,
       0,     0,   377,     0,    76,    61,     0,    93,     0,   396,
     404,   409,   413,   417,   421,     0,    61,     0,    14,     0,
     191,     0,     0,   437,     0,     0,     0,     0,     0,    61,
      24,    25,    26,    27,     0,   299,   472,   300,   301,     0,
      61,     0,     0,     0,    59,   191,   701,     0,     0,   706,
      59,     0,     0,     0,     0,   526,     0,     0,   199,   200,
     201,   202,   203,   204,   553,   557,   559,   561,   563,   565,
     567,   569,   574,    61,   210,   211,   212,   213,   214,   215,
     216,   217,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,   343,     9,     0,   259,    60,   735,    10,   737,
     282,   283,   284,   285,   286,   287,    11,     0,     0,     0,
       0,     0,    12,     0,     0,     0,    59,    59,    59,    60,
      59,    59,    60,    59,    59,    61,    59,     0,     0,     0,
       0,     0,    61,   765,    61,     0,     0,     0,    61,     0,
     770,   771,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    60,    61,    60,     0,    79,
      67,     0,    59,    74,   371,   373,   375,   650,     0,     0,
       0,     0,     0,   780,   397,   405,     0,    55,     0,     0,
       0,     0,    59,     0,    59,   160,    55,   161,   438,     0,
       0,   162,   163,   164,   165,   166,   167,    55,     0,    59,
      59,   473,   172,    59,    59,    59,    59,   176,   177,   232,
      55,    59,     0,     0,   643,   643,   184,     0,     0,   233,
     527,    55,   303,   234,     0,     0,     0,     0,     0,   554,
       0,   235,   236,   237,   238,   239,   240,   575,   577,   579,
       0,   583,   585,    14,     0,     0,     0,     0,    80,     0,
       0,     0,     0,    14,    55,    24,    25,    26,    27,   102,
     299,    61,   300,   312,     0,    24,    25,    26,    27,   643,
     299,     0,   300,   316,   731,     0,     3,     4,     5,     6,
       7,     8,     0,     9,    61,     0,     0,    61,    10,   218,
     219,   220,   221,   222,   223,   224,    11,     0,     0,   225,
       0,     0,    12,     0,     0,     0,    55,   226,   227,   228,
     229,   230,   231,    55,   305,    55,    80,     0,     0,    55,
      61,     0,    61,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,     0,    55,     0,   348,
     199,   200,   201,   202,   203,   204,     0,     0,     0,    79,
      67,   160,     0,   161,     0,   391,   399,   162,   163,   164,
     165,   166,   167,     0,   426,   428,   430,   432,   172,     0,
     440,     0,     0,   446,     0,   323,     0,     0,     0,     0,
       0,   328,   184,   475,     0,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,     0,   345,
       0,     0,   529,     3,     4,     5,     6,     7,     8,     0,
       9,   556,   117,   260,   232,    10,     0,     0,     0,     0,
      60,   581,     0,    11,   233,     0,    60,     0,   234,    12,
     199,   200,   201,   202,   203,   204,   235,   236,   237,   238,
     239,   240,    55,     0,     0,     0,   210,   211,   128,   129,
       0,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,     0,     0,    10,    55,     0,    14,    55,     0,
       0,     0,    11,     0,     0,     0,    79,    67,    12,    24,
      25,    26,    27,     0,   299,     0,   319,   320,     0,     0,
       0,     0,    60,    60,    60,     0,    60,    60,     0,    60,
      60,    55,    60,    55,   596,    13,    14,    15,    16,     0,
      17,    18,    19,    20,    21,    22,    23,     0,    24,    25,
      26,    27,    28,    29,     0,    30,    31,   633,     0,     0,
     636,     0,     0,     0,    56,     0,     0,     0,    60,    75,
       0,     0,     0,    56,     3,     4,     5,     6,     7,     8,
       0,     9,   700,     0,    56,     0,    10,     0,    60,     0,
      60,     0,     0,     0,    11,     0,     0,    56,     0,     0,
      12,     0,     0,     0,     0,    60,    60,     0,    56,    60,
      60,    60,    60,     0,     0,    61,     0,    60,     0,     0,
       0,    61,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     0,     9,   734,     0,     0,     0,    10,     0,     0,
       0,    56,     0,     0,     0,    11,     0,    79,    67,     0,
       0,    12,     3,     4,     5,     6,     7,     8,     0,     9,
     736,     0,   258,     0,    10,     0,     0,   599,   600,   601,
     602,   603,    11,     0,     0,     0,     0,     0,    12,   277,
     278,   279,     0,   280,   281,     0,     0,    61,    61,    61,
       0,    61,    61,    56,    61,    61,     0,    61,    79,    67,
      56,     0,    56,     0,     0,     0,    56,     0,     0,     0,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,     0,    56,    79,    67,     0,     0,     0,
     258,     0,   367,    61,    76,   271,   272,   273,   274,   275,
     276,     0,   392,   400,     0,    57,     0,   277,   278,   279,
       0,   280,   281,    61,    57,    61,   434,     0,   442,   444,
       0,     0,     0,     0,     0,    57,     0,     0,     0,   469,
      61,    61,     0,     0,    61,    61,    61,    61,    57,     0,
       0,     0,    61,   599,   600,   601,   602,   603,   523,    57,
       0,     0,     0,     0,     0,   277,    55,   550,     0,   280,
     281,     0,    55,     0,     0,   571,     3,     4,     5,     6,
       7,     8,     0,     9,   764,     0,     0,     0,    10,     0,
       0,     0,    57,     0,     0,     0,    11,     0,     0,    56,
       0,     0,    12,     3,     4,     5,     6,    65,     8,     0,
       9,     0,     0,     0,     0,    10,   218,   219,   220,   221,
     222,   223,    56,    11,     0,    56,     0,     0,   677,    12,
       0,     0,     0,     0,   682,     0,     0,     0,    55,    55,
      55,     0,    55,    55,    57,    55,    55,     0,    55,    79,
      67,    57,     0,    57,     0,     0,     0,    57,    56,     0,
      56,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,     0,    57,    66,    67,     0,     0,
       0,     0,     0,     0,    55,     0,     0,     0,     0,     0,
       0,     0,   131,   393,   401,   132,     0,     0,     0,     0,
     709,   714,   716,     0,    55,     0,    55,   721,     0,     0,
     723,     0,   448,   450,     0,     0,     0,     0,     0,     0,
       0,    55,    55,     0,     0,    55,    55,    55,    55,     0,
       0,     0,     0,    55,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   740,   157,   158,     0,
       0,     1,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,     0,   758,    10,   759,   218,
     219,   220,   221,   222,   223,    11,     0,     0,     0,   225,
      57,    12,    14,     0,     0,     0,     0,   226,   227,   228,
     229,   230,   231,     0,    24,    25,    26,    27,     0,   299,
       0,   300,   378,    57,     0,     0,    57,     0,    13,    14,
      15,    16,     0,    17,    18,    19,    20,    21,    22,    23,
       0,    24,    25,    26,    27,    28,    29,     0,    30,    31,
     129,     0,     2,     3,     4,     5,     6,     7,     8,    57,
       9,    57,     0,   667,     0,    10,     0,     0,     0,     0,
       0,     0,     0,    11,   160,   256,   161,     0,     0,    12,
     162,   163,   164,   165,   166,   167,   168,   169,   170,     0,
     171,   172,   173,   174,   175,     0,   176,   177,   178,   179,
     180,   181,   182,   183,     0,   184,    13,    14,    15,    16,
       0,    17,    18,    19,    20,    21,    22,    23,     0,    24,
      25,    26,    27,    28,    29,     0,    30,    31,     0,   129,
       0,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,   719,    56,    10,     0,     0,     0,     0,    56,
       0,     0,    11,     0,     0,     0,     0,     0,    12,    14,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     0,
       9,    24,    25,    26,    27,    10,   299,     0,   300,   301,
       0,     0,     0,    11,     0,    13,    14,    15,    16,    12,
      17,    18,    19,    20,    21,    22,    23,     0,    24,    25,
      26,    27,    28,    29,     0,    30,    31,   218,   219,   220,
     221,   222,   223,     0,     0,    56,    56,    56,     0,    56,
      56,     0,    56,    56,     0,    56,     0,   228,   229,   230,
     231,     0,     0,     0,     0,     0,    79,    67,     3,     4,
       5,     6,     7,   708,     0,     9,   160,     0,   161,     0,
      10,     0,   162,   163,   164,   165,   166,   167,    11,     0,
       0,    56,     0,   172,    12,     0,     0,     0,   176,   177,
     178,   179,   180,   181,   182,   183,     0,   184,     0,     0,
       0,    56,     0,    56,     0,     0,     0,   137,     3,     4,
       5,     6,     7,     8,     0,     9,     0,   138,    56,    56,
      10,     0,    56,    56,    56,    56,     0,     0,    11,     0,
      56,    79,    67,     0,    12,   199,   200,   201,   202,   203,
     204,   205,     0,     0,    57,   206,     0,   207,   208,   209,
      57,   210,   211,   212,   213,   214,   215,   216,   217,     0,
       0,    13,    14,    15,    16,     0,    17,    18,    19,    20,
      21,    22,    23,     0,    24,    25,    26,    27,    28,    29,
       0,    30,    31,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,   325,     0,    10,   599,   600,   601,
     602,   603,     0,     0,    11,     0,     0,     0,     0,   277,
      12,   279,     0,   280,   281,     0,    57,    57,    57,     0,
      57,    57,     0,    57,    57,     0,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,    14,    15,
      16,     0,    17,    18,    19,    20,    21,    22,    23,     0,
      24,    25,    26,    27,    28,    29,     0,    30,    31,     0,
       0,     0,    57,     0,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,     0,     0,    10,     0,     0,
       0,     0,    57,     0,    57,    11,     0,     0,     0,     0,
       0,    12,   199,   200,   201,   202,   203,   204,     0,    57,
      57,     0,     0,    57,    57,    57,    57,     0,   210,   211,
       0,    57,   214,   215,   216,   217,     0,     0,    13,    14,
      15,    16,     0,    17,    18,    19,    20,    21,    22,    23,
       0,    24,    25,    26,    27,    28,    29,     0,    30,    31,
       3,     4,     5,     6,    65,   708,     0,     9,     0,     0,
       0,     0,    10,     0,     0,     0,     0,     0,     0,     0,
      11,   160,   -96,   161,     0,     0,    12,   162,   163,   164,
     165,   166,   167,   168,   169,   170,     0,   171,   172,   173,
     174,   175,     0,   176,   177,   178,   179,   180,   181,   182,
     183,     0,   184,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,     0,   157,   158,     0,     0,   160,
       0,   161,     0,    66,    67,   162,   163,   164,   165,   166,
     167,   168,   169,   170,     0,   171,   172,   173,   174,   175,
       0,   176,   177,   178,   179,   180,   181,   182,   183,   160,
     184,   161,     0,     0,     0,   162,   163,   164,   165,   166,
     167,     0,   169,   170,     0,   171,   172,   173,   174,   175,
       0,   176,   177,   178,   179,   180,   181,   182,   183,   160,
     184,   161,     0,     0,     0,   162,   163,   164,   165,   166,
     167,     0,   169,     0,     0,   171,   172,   173,   174,   175,
       0,   176,   177,   178,   179,   180,   181,   182,   183,   160,
     184,   161,     0,     0,     0,   162,   163,   164,   165,   166,
     167,     0,     0,     0,     0,   171,   172,   173,   174,   175,
       0,   176,   177,   178,   179,   180,   181,   182,   183,   160,
     184,   161,     0,     0,     0,   162,   163,   164,   165,   166,
     167,     0,     0,     0,     0,     0,   172,   173,   174,   175,
       0,   176,   177,   178,   179,   180,   181,   182,   183,   160,
     184,   161,     0,     0,     0,   162,   163,   164,   165,   166,
     167,     0,     0,     0,     0,     0,   172,   173,     0,   175,
       0,   176,   177,   178,   179,   180,   181,   182,   183,   160,
     184,   161,     0,     0,     0,   162,   163,   164,   165,   166,
     167,     0,     0,     0,     0,     0,   172,   173,     0,     0,
       0,   176,   177,   178,   179,   180,   181,   182,   183,   160,
     184,   161,     0,     0,     0,   162,   163,   164,   165,   166,
     167,     0,     0,     0,     0,     0,   172,     0,     0,     0,
       0,   176,   177,     0,     0,   180,   181,   182,   183,   258,
     184,     0,     0,     0,   199,   200,   201,   202,   203,   204,
     205,     0,     0,     0,   206,     0,   207,   208,   209,     0,
     210,   211,   212,   213,   214,   215,   216,   217,   -99,     0,
       0,     0,     0,   199,   200,   201,   202,   203,   204,   205,
       0,     0,     0,   206,     0,   207,   208,   209,     0,   210,
     211,   212,   213,   214,   215,   216,   217,   259,     0,     0,
       0,     0,   218,   219,   220,   221,   222,   223,   224,     0,
       0,     0,   225,     0,     0,     0,     0,     0,     0,     0,
     226,   227,   228,   229,   230,   231,   199,   200,   201,   202,
     203,   204,     0,     0,     0,     0,   206,     0,   207,   208,
     209,     0,   210,   211,   212,   213,   214,   215,   216,   217,
     199,   200,   201,   202,   203,   204,     0,     0,     0,     0,
       0,     0,   207,     0,   209,     0,   210,   211,   212,   213,
     214,   215,   216,   217,   199,   200,   201,   202,   203,   204,
       0,     0,     0,     0,     0,     0,   207,     0,     0,     0,
     210,   211,   212,   213,   214,   215,   216,   217,   271,   272,
     273,   274,   275,   276,     0,     0,     0,     0,     0,     0,
     277,   278,   279,     0,   280,   281
  };

  const short
   Parser ::yycheck_[] =
  {
       8,     8,    10,    11,    12,    66,   250,   665,    11,   646,
       3,   669,    11,     9,    11,    10,    33,    42,   637,   638,
       3,     4,     5,     6,     7,     8,     9,     9,    11,    12,
      11,     9,     9,    16,     9,    77,    78,     9,     9,    42,
       3,    24,   679,    11,    69,    26,    41,    30,    77,     3,
      13,    11,    11,   138,    11,    77,    11,     4,     5,    41,
      14,   698,     9,    14,    57,    58,    69,    11,    77,    16,
      69,    26,    69,   692,    82,    83,    84,    70,    71,    72,
      73,    77,    75,    30,    77,    78,   744,   745,   725,    40,
     748,   749,   750,   751,    77,    78,   662,   663,   756,    77,
      77,    69,    77,    57,    58,    77,    77,     9,   116,    69,
      69,     3,   129,     0,    69,   123,    70,    71,    72,    73,
      12,    75,    77,    77,    78,    69,     3,    77,    11,     3,
      77,    78,    15,     8,     0,    12,    11,    12,    69,    13,
      11,    43,   708,    10,    15,     0,    33,    12,     3,    41,
      33,    34,     9,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    41,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,     9,    42,   186,   187,
     188,   189,   190,     9,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   324,
      10,   116,   129,    39,    37,    41,   254,    11,   123,    13,
      12,   138,    12,    12,    12,    12,    49,    50,    51,    52,
     268,   269,    26,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
      42,    12,    42,    42,    42,    42,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   305,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   326,
      43,   186,   187,   188,   189,   190,    41,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,     9,     9,    11,    11,    11,    43,    13,   254,
      13,     9,    11,    39,    20,     0,    17,    18,    19,    26,
      26,    26,    63,     8,     9,    10,    17,    18,    19,    20,
      14,   645,    58,    40,    40,    20,    35,    36,    37,    38,
      24,    25,    26,    27,    70,    71,    72,    73,    33,    75,
       9,    77,    78,    21,    30,    31,    10,    25,    13,    44,
     305,    12,     9,     4,    69,    33,    34,   324,     9,   326,
     116,    10,    77,    69,    10,    16,    14,   123,    62,    55,
       3,     4,     5,     6,     7,     8,     9,    11,    11,    30,
      66,    67,    77,    16,    70,    77,    69,    82,    83,     9,
      39,    24,    69,    79,    21,    22,    23,    30,    25,    33,
      34,    35,    36,    37,    38,   161,    33,    34,    22,    58,
     104,    25,   106,    11,   108,    10,   110,    42,     9,    33,
      34,    70,    71,    72,    73,   119,    75,    25,    77,    78,
     186,    10,    20,    11,   129,    33,    34,    35,    36,    37,
      38,   136,    11,   138,    77,    78,    20,   142,   589,    12,
      69,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,    10,   160,    25,   162,   163,   164,
     165,   166,   167,   168,    33,    34,   232,     4,     5,    12,
      20,    20,     9,   178,   179,   180,   181,   182,   183,    16,
      22,    23,    77,    25,    14,     3,    77,   192,   254,    41,
      10,    33,    34,    30,   199,   200,   201,   202,   203,   204,
     205,   599,   600,   601,   602,   603,     3,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
      43,   226,   227,   228,   229,   230,   231,    10,   233,    14,
     113,    43,    43,    11,    10,   118,   241,    15,    10,   305,
       3,   124,    12,   247,    10,    10,    10,    25,    10,    21,
      22,    23,   135,    25,   652,    33,    34,   655,    10,   666,
     265,    33,    34,   661,   662,   663,   271,   272,   273,   274,
     275,   276,    15,    16,    17,    18,    19,   282,   283,   284,
     285,   286,   287,   288,    10,   289,   291,    61,    77,   172,
      12,    12,     4,     5,     6,     7,     8,     9,    12,    11,
      12,    41,    10,    40,    16,   703,    39,   705,   290,    64,
     708,   708,    24,   135,     9,   590,    11,   146,    30,   324,
      25,   326,    17,    18,    19,    20,    77,   766,    33,    34,
      42,    26,    -1,    -1,    -1,     4,     5,     6,     7,     8,
       9,   739,    11,    12,    -1,    40,    -1,    16,   746,   747,
      25,    -1,   348,    -1,    -1,    24,    -1,    10,    33,    34,
      -1,    30,    -1,    -1,    -1,    77,    78,   250,    -1,    -1,
      -1,     0,    -1,    42,    17,    18,    19,    20,    -1,     8,
       9,   779,    17,    18,    19,    20,    39,   652,    -1,   666,
     655,    20,    -1,    10,    -1,   391,   661,   662,   663,    17,
      18,    19,    20,   399,    33,    58,    -1,    -1,    77,    78,
      -1,    -1,    -1,    -1,   297,    44,    -1,    70,    71,    72,
      73,   304,    75,    -1,    77,    78,    -1,    -1,    -1,    -1,
     426,    -1,   428,    -1,   430,    -1,   432,    -1,   703,    -1,
     705,    58,    -1,   708,   440,    -1,    -1,    -1,    77,    -1,
     446,    -1,    -1,    70,    71,    72,    73,    -1,    75,    -1,
      77,    78,    -1,    -1,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,   739,    -1,    16,    -1,    -1,   475,
      -1,   746,   747,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,
     129,    -1,    42,    -1,    -1,    -1,    -1,   136,    -1,   138,
      10,    31,    32,   142,   779,    -1,    -1,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,   160,    -1,   529,    -1,    -1,     0,    77,    78,   168,
      -1,    -1,   171,    -1,     8,     9,    -1,    11,    -1,   178,
     179,   180,   181,   182,   183,    -1,    20,    -1,    58,    -1,
     556,    -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,    33,
      70,    71,    72,    73,    -1,    75,   205,    77,    78,    -1,
      44,    -1,    -1,    -1,   589,   581,   652,    -1,    -1,   655,
     595,    -1,    -1,    -1,    -1,   224,    -1,    -1,    15,    16,
      17,    18,    19,    20,   233,   234,   235,   236,   237,   238,
     239,   240,   241,    77,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    10,   265,   703,    16,   705,
      15,    16,    17,    18,    19,    20,    24,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    -1,   661,   662,   663,   288,
     665,   666,   291,   668,   669,   129,   671,    -1,    -1,    -1,
      -1,    -1,   136,   739,   138,    -1,    -1,    -1,   142,    -1,
     746,   747,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   324,   160,   326,    -1,    77,
      78,    -1,   707,   708,   168,   169,   170,   590,    -1,    -1,
      -1,    -1,    -1,   779,   178,   179,    -1,     0,    -1,    -1,
      -1,    -1,   727,    -1,   729,     9,     9,    11,   192,    -1,
      -1,    15,    16,    17,    18,    19,    20,    20,    -1,   744,
     745,   205,    26,   748,   749,   750,   751,    31,    32,    11,
      33,   756,    -1,    -1,   637,   638,    40,    -1,    -1,    21,
     224,    44,   645,    25,    -1,    -1,    -1,    -1,    -1,   233,
      -1,    33,    34,    35,    36,    37,    38,   241,   242,   243,
      -1,   245,   246,    58,    -1,    -1,    -1,    -1,     9,    -1,
      -1,    -1,    -1,    58,    77,    70,    71,    72,    73,    20,
      75,   265,    77,    78,    -1,    70,    71,    72,    73,   692,
      75,    -1,    77,    78,   697,    -1,     4,     5,     6,     7,
       8,     9,    -1,    11,   288,    -1,    -1,   291,    16,    15,
      16,    17,    18,    19,    20,    21,    24,    -1,    -1,    25,
      -1,    -1,    30,    -1,    -1,    -1,   129,    33,    34,    35,
      36,    37,    38,   136,    42,   138,    77,    -1,    -1,   142,
     324,    -1,   326,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,    -1,   160,    -1,   162,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    77,
      78,     9,    -1,    11,    -1,   178,   179,    15,    16,    17,
      18,    19,    20,    -1,   187,   188,   189,   190,    26,    -1,
     193,    -1,    -1,   196,    -1,   136,    -1,    -1,    -1,    -1,
      -1,   142,    40,   206,    -1,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,    -1,   160,
      -1,    -1,   225,     4,     5,     6,     7,     8,     9,    -1,
      11,   234,    13,    10,    11,    16,    -1,    -1,    -1,    -1,
     589,   244,    -1,    24,    21,    -1,   595,    -1,    25,    30,
      15,    16,    17,    18,    19,    20,    33,    34,    35,    36,
      37,    38,   265,    -1,    -1,    -1,    31,    32,     0,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      -1,    -1,    -1,    -1,    16,   288,    -1,    58,   291,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    77,    78,    30,    70,
      71,    72,    73,    -1,    75,    -1,    77,    78,    -1,    -1,
      -1,    -1,   661,   662,   663,    -1,   665,   666,    -1,   668,
     669,   324,   671,   326,   265,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    -1,    77,    78,   288,    -1,    -1,
     291,    -1,    -1,    -1,     0,    -1,    -1,    -1,   707,   708,
      -1,    -1,    -1,     9,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    20,    -1,    16,    -1,   727,    -1,
     729,    -1,    -1,    -1,    24,    -1,    -1,    33,    -1,    -1,
      30,    -1,    -1,    -1,    -1,   744,   745,    -1,    44,   748,
     749,   750,   751,    -1,    -1,   589,    -1,   756,    -1,    -1,
      -1,   595,    -1,    -1,    -1,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    77,    -1,    -1,    -1,    24,    -1,    77,    78,    -1,
      -1,    30,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    10,    -1,    16,    -1,    -1,    15,    16,    17,
      18,    19,    24,    -1,    -1,    -1,    -1,    -1,    30,    27,
      28,    29,    -1,    31,    32,    -1,    -1,   661,   662,   663,
      -1,   665,   666,   129,   668,   669,    -1,   671,    77,    78,
     136,    -1,   138,    -1,    -1,    -1,   142,    -1,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,   160,    77,    78,    -1,    -1,    -1,
      10,    -1,   168,   707,   708,    15,    16,    17,    18,    19,
      20,    -1,   178,   179,    -1,     0,    -1,    27,    28,    29,
      -1,    31,    32,   727,     9,   729,   192,    -1,   194,   195,
      -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,   205,
     744,   745,    -1,    -1,   748,   749,   750,   751,    33,    -1,
      -1,    -1,   756,    15,    16,    17,    18,    19,   224,    44,
      -1,    -1,    -1,    -1,    -1,    27,   589,   233,    -1,    31,
      32,    -1,   595,    -1,    -1,   241,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    24,    -1,    -1,   265,
      -1,    -1,    30,     4,     5,     6,     7,     8,     9,    -1,
      11,    -1,    -1,    -1,    -1,    16,    15,    16,    17,    18,
      19,    20,   288,    24,    -1,   291,    -1,    -1,   589,    30,
      -1,    -1,    -1,    -1,   595,    -1,    -1,    -1,   661,   662,
     663,    -1,   665,   666,   129,   668,   669,    -1,   671,    77,
      78,   136,    -1,   138,    -1,    -1,    -1,   142,   324,    -1,
     326,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,    -1,   160,    77,    78,    -1,    -1,
      -1,    -1,    -1,    -1,   707,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     0,   178,   179,     3,    -1,    -1,    -1,    -1,
     661,   662,   663,    -1,   727,    -1,   729,   668,    -1,    -1,
     671,    -1,   197,   198,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   744,   745,    -1,    -1,   748,   749,   750,   751,    -1,
      -1,    -1,    -1,   756,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,   707,    55,    56,    -1,
      -1,     0,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    -1,    -1,    -1,   727,    16,   729,    15,
      16,    17,    18,    19,    20,    24,    -1,    -1,    -1,    25,
     265,    30,    58,    -1,    -1,    -1,    -1,    33,    34,    35,
      36,    37,    38,    -1,    70,    71,    72,    73,    -1,    75,
      -1,    77,    78,   288,    -1,    -1,   291,    -1,    57,    58,
      59,    60,    -1,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    -1,    77,    78,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,   324,
      11,   326,    -1,    14,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,     9,    10,    11,    -1,    -1,    30,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    40,    57,    58,    59,    60,
      -1,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    -1,    77,    78,    -1,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      -1,    -1,    14,   589,    16,    -1,    -1,    -1,    -1,   595,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    58,
      -1,    -1,    -1,     4,     5,     6,     7,     8,     9,    -1,
      11,    70,    71,    72,    73,    16,    75,    -1,    77,    78,
      -1,    -1,    -1,    24,    -1,    57,    58,    59,    60,    30,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    -1,    77,    78,    15,    16,    17,
      18,    19,    20,    -1,    -1,   661,   662,   663,    -1,   665,
     666,    -1,   668,   669,    -1,   671,    -1,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    77,    78,     4,     5,
       6,     7,     8,     9,    -1,    11,     9,    -1,    11,    -1,
      16,    -1,    15,    16,    17,    18,    19,    20,    24,    -1,
      -1,   707,    -1,    26,    30,    -1,    -1,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    40,    -1,    -1,
      -1,   727,    -1,   729,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    -1,    13,   744,   745,
      16,    -1,   748,   749,   750,   751,    -1,    -1,    24,    -1,
     756,    77,    78,    -1,    30,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,   589,    25,    -1,    27,    28,    29,
     595,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    57,    58,    59,    60,    -1,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      -1,    77,    78,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    -1,    14,    -1,    16,    15,    16,    17,
      18,    19,    -1,    -1,    24,    -1,    -1,    -1,    -1,    27,
      30,    29,    -1,    31,    32,    -1,   661,   662,   663,    -1,
     665,   666,    -1,   668,   669,    -1,   671,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,
      60,    -1,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    -1,    77,    78,    -1,
      -1,    -1,   707,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    -1,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    -1,   727,    -1,   729,    24,    -1,    -1,    -1,    -1,
      -1,    30,    15,    16,    17,    18,    19,    20,    -1,   744,
     745,    -1,    -1,   748,   749,   750,   751,    -1,    31,    32,
      -1,   756,    35,    36,    37,    38,    -1,    -1,    57,    58,
      59,    60,    -1,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    -1,    77,    78,
       4,     5,     6,     7,     8,     9,    -1,    11,    -1,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,     9,    10,    11,    -1,    -1,    30,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    25,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    -1,    -1,     9,
      -1,    11,    -1,    77,    78,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,     9,
      40,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,    22,    23,    -1,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,     9,
      40,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,    22,    -1,    -1,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,     9,
      40,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,     9,
      40,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,     9,
      40,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,     9,
      40,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,     9,
      40,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    35,    36,    37,    38,    10,
      40,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    25,    -1,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    10,    -1,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    25,    -1,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    10,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    37,    38,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    25,    -1,    27,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    -1,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    -1,    31,    32
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     0,     3,     4,     5,     6,     7,     8,     9,    11,
      16,    24,    30,    57,    58,    59,    60,    62,    63,    64,
      65,    66,    67,    68,    70,    71,    72,    73,    74,    75,
      77,    78,    81,    82,    84,    85,    88,    90,    91,    92,
      93,    94,    95,    96,    97,    98,   100,   102,   105,   109,
     110,   111,   113,   114,   115,   117,   121,   122,   125,   126,
     127,   128,   129,   131,   133,     8,    77,    78,   114,   115,
     117,   121,   122,   125,   126,   127,   128,     3,    12,    77,
     113,   116,     9,    16,    30,    77,    78,   125,   126,   114,
     125,   126,   127,   128,   114,   125,   128,    77,    11,   132,
      77,    89,   113,    77,    69,   132,    69,   132,    69,   132,
      69,   132,    77,     9,    77,   106,    11,    13,    26,    69,
     120,   123,   132,    11,    26,    69,   120,     0,     0,     1,
      84,     0,     3,    83,    83,     9,     9,     3,    13,    85,
      86,    87,     9,    83,    83,    83,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    55,    56,    83,
       9,    11,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    25,    26,    27,    28,    29,    31,    32,    33,    34,
      35,    36,    37,    38,    40,   120,    11,    15,    25,    33,
      34,   120,    21,    25,    33,    34,    25,    33,    34,    15,
      16,    17,    18,    19,    20,    21,    25,    27,    28,    29,
      31,    32,    33,    34,    35,    36,    37,    38,    15,    16,
      17,    18,    19,    20,    21,    25,    33,    34,    35,    36,
      37,    38,    11,    21,    25,    33,    34,    35,    36,    37,
      38,    21,    22,    23,    25,    33,    34,    69,   132,    69,
       9,    77,   106,    10,    11,   123,    10,    10,    10,    10,
      10,    10,   116,     3,    12,    41,   125,   126,     9,    16,
     125,    15,    16,    17,    18,    19,    20,    27,    28,    29,
      31,    32,    15,    16,    17,    18,    19,    20,    43,    12,
      41,    43,   132,   132,   132,   132,     3,    13,    10,    75,
      77,    78,   130,   133,     9,    42,   114,   119,   125,    14,
      40,   124,    78,   133,   132,   119,    78,   133,    84,    77,
      78,   109,   133,   113,    13,    14,    82,    63,   113,   111,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,    10,   112,   113,   119,   114,   117,   125,
     126,   114,   125,   126,   114,   125,   126,   114,   125,   126,
     114,   125,   126,   114,   125,   126,   114,   121,   125,   126,
     127,   128,   114,   128,   114,   128,   114,   127,    78,   133,
     114,   125,   114,   125,   114,   125,   114,   125,   114,   125,
     114,   117,   121,   122,   125,   126,   127,   128,   114,   117,
     121,   122,   125,   126,   127,   128,   114,   125,   126,   127,
     114,   125,   126,   127,   114,   125,   126,   127,   114,   125,
     126,   127,    77,    78,   119,   114,   117,   114,   117,   114,
     117,   114,   117,   114,   121,   125,   126,   127,   128,   114,
     117,   114,   121,   114,   121,   114,   117,   114,   122,   114,
     122,   114,   125,   126,   114,   125,   126,   114,   125,   126,
     114,   125,   126,   114,   125,   126,   114,   126,   114,   121,
     125,   126,   127,   128,   114,   117,   114,   125,   114,   125,
     114,   125,   114,   125,   114,   125,   114,   125,   126,   114,
     125,   126,   114,   125,   126,   114,   125,   126,   114,   125,
     126,   114,   125,   126,   114,   125,   126,   114,   125,   126,
     114,   125,   126,   114,   125,   126,   114,   125,   126,   114,
     125,   126,   114,   121,   125,   126,   127,   128,   114,   117,
     114,   125,   126,   114,   125,   126,   114,   125,   126,   114,
     125,   126,   114,   125,   126,   114,   125,   126,   119,   114,
     121,   125,   126,   127,   128,   114,   117,   127,   114,   127,
     114,   127,   114,   127,   114,   127,   114,   127,   114,   127,
     114,   121,   125,   126,   127,   128,   114,   128,   114,   128,
     114,   117,   114,   128,   114,   128,   132,    10,   130,    43,
       9,    10,     3,    12,    12,     3,   113,   125,   125,    15,
      16,    17,    18,    19,   125,   126,   125,   126,   125,   126,
     125,   126,   125,   126,   125,   126,   125,   125,   125,   125,
     125,   125,   126,   125,   126,   125,   126,   125,   126,   125,
     126,   125,   126,   113,   132,    89,   113,    13,     3,    14,
      57,   103,   104,   133,    10,    41,    10,    39,   107,   108,
     133,    12,    42,   119,    12,    42,    77,    14,    69,    12,
      69,    42,    42,    42,    77,    10,    82,    14,     9,    10,
      10,    41,    12,    69,    12,    12,    10,   113,   123,    10,
     108,    12,   113,   125,   125,   125,   125,   125,   103,   103,
      77,    14,     3,    77,   130,    86,    77,    41,    10,    77,
      12,   119,    12,    42,    12,    42,   119,    43,     9,   113,
     114,   118,   119,   125,   113,   118,   113,   118,    87,    14,
       3,   113,    87,   113,    86,    10,    14,    43,   103,    43,
      39,   133,    86,    12,    12,   119,    12,   119,    12,    42,
     113,   114,   118,   125,    10,    10,    39,    41,    10,    10,
      10,    10,     3,    10,    61,    99,   101,    86,   113,   113,
      77,    77,    12,    12,    12,   119,    41,    10,    87,    87,
     119,   119,    87,    87,    87,    87,    87,    12,   124,    39,
     119
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    80,    81,    81,    82,    82,    82,    83,    83,    84,
      84,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    86,    86,    86,    86,    86,    87,    87,
      88,    89,    89,    90,    90,    90,    91,    91,    92,    92,
      92,    92,    92,    92,    93,    94,    95,    96,    97,    98,
      99,    99,   100,   101,   102,   102,   102,   103,   103,   103,
     103,   104,   104,   104,   105,   105,   105,   105,   106,   107,
     107,   108,   108,   108,   109,   110,   110,   110,   110,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   112,   112,   113,   113,   113,   113,   113,
     113,   113,   113,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   115,   115,   115,   115,   115,
     116,   116,   116,   117,   117,   118,   118,   118,   119,   119,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   121,   121,   122,   122,   123,   123,   124,   124,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   129,   129,   129,   129,   130,   130,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   132,   132,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     1,     2,     1,     2,     3,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     3,     4,     4,     5,     1,     1,
       2,     1,     3,     1,     1,     1,     1,     2,     7,     7,
       7,     7,     7,     7,     1,     5,     1,     6,     1,     6,
       2,     0,     1,     1,     4,     5,     6,     1,     2,     2,
       3,     2,     4,     4,     5,     6,     5,     6,     1,     2,
       4,     2,     4,     1,     2,     4,     4,     4,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     3,     3,     4,
       4,     4,     4,     4,     4,     3,     3,     3,     4,     4,
       4,     3,     3,     3,     2,     2,     2,     2,     3,     3,
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
       3,     3,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     4,     4,     5,
       1,     3,     4,     1,     3,     3,     3,     5,     1,     1,
       3,     4,     4,     5,     4,     5,     5,     5,     6,     6,
       6,     7,     1,     3,     2,     4,     2,     3,     4,     6,
       1,     2,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     3,     4,     3,     1,     3,     2,     2,
       2,     2,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     2,     3,     2,     2,     2,     2,     2,     2,     2,
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
  "\"and\"", "\"or\"", "\"not\"", "\"in\"", "\"as\"", "\"&\"", "\"|\"",
  "\"^\"", "\"~\"", "\"<<\"", "\">>\"", "\"==\"", "\"!=\"", "\">\"",
  "\"<\"", "\">=\"", "\"<=\"", "\"..\"", "\".\"", "\",\"", "\":\"",
  "\"=\"", "\"++=\"", "\"**=\"", "\"%=\"", "\"/=\"", "\"*=\"", "\"-=\"",
  "\"+=\"", "\"&=\"", "\"|=\"", "\"^=\"", "\"~=\"", "\"<<=\"", "\">>=\"",
  "\"var\"", "\"any\"", "\"import\"", "\"if\"", "\"else\"", "\"for\"",
  "\"while\"", "\"do\"", "\"return\"", "\"break\"", "\"continue\"",
  "\"const\"", "\"?\"", "\"'int'\"", "\"'float'\"", "\"'string'\"",
  "\"'bool'\"", "\"'struct'\"", "\"'void'\"", "\"'range'\"",
  "\"identifier\"", "\"external identifier\"", "NEG", "$accept", "start",
  "stmt", "stmt_end", "stmts", "stmts_ne", "block", "scope_body", "import",
  "id_list", "flowctl", "return", "for", "for_kw", "while", "wh_kw",
  "dowhile", "do_kw", "if", "else", "if_kw", "el_kw", "struct", "decllist",
  "declistval", "function", "fun_id", "funargsnvar", "funargs", "vardecl",
  "vardef", "set", "callarglist", "expr", "expr_var", "matrix", "matvals",
  "expr_mat", "range", "int_val", "slice", "expr_none", "expr_struct",
  "struct_val", "struct_list", "expr_int", "expr_float", "expr_str",
  "expr_bool", "funtype", "typelist", "mattype", "matsq", "type", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   232,   232,   233,   235,   236,   237,   240,   241,   244,
     245,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   262,   263,   264,   265,   266,   269,   270,
     274,   276,   277,   281,   282,   283,   285,   286,   290,   291,
     292,   293,   294,   295,   297,   300,   302,   304,   306,   309,
     311,   312,   314,   315,   318,   319,   320,   322,   323,   324,
     325,   327,   328,   329,   333,   334,   335,   336,   338,   340,
     341,   343,   344,   345,   350,   354,   355,   356,   357,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   378,   379,   383,   384,   385,   386,   387,
     388,   389,   390,   393,   394,   395,   396,   397,   399,   400,
     402,   403,   404,   405,   406,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   418,   419,   420,   421,   423,   424,
     427,   428,   429,   430,   431,   433,   434,   435,   436,   437,
     439,   440,   441,   442,   443,   445,   446,   447,   448,   449,
     451,   452,   453,   454,   455,   456,   457,   458,   460,   461,
     462,   463,   464,   466,   467,   468,   470,   471,   472,   474,
     475,   476,   477,   478,   479,   480,   482,   483,   484,   485,
     486,   487,   488,   490,   491,   492,   493,   494,   495,   496,
     498,   499,   500,   501,   502,   503,   504,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   542,   543,   544,   546,   547,   548,   550,   551,   552,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   571,   572,   573,   575,
     576,   577,   579,   581,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   597,   598,   599,   600,   601,
     604,   605,   606,   610,   611,   613,   614,   615,   617,   618,
     620,   621,   622,   623,   624,   625,   626,   627,   628,   629,
     630,   631,   635,   636,   640,   641,   643,   644,   646,   647,
     651,   652,   653,   654,   655,   656,   657,   658,   659,   660,
     661,   662,   663,   664,   668,   669,   670,   671,   672,   673,
     674,   675,   676,   677,   678,   679,   680,   681,   682,   683,
     684,   685,   686,   687,   688,   692,   693,   694,   695,   696,
     697,   698,   699,   700,   701,   702,   703,   704,   705,   706,
     707,   708,   709,   710,   711,   712,   713,   714,   715,   716,
     717,   718,   722,   723,   724,   725,   726,   728,   729,   730,
     731,   732,   733,   734,   736,   737,   738,   739,   740,   741,
     742,   744,   745,   746,   747,   748,   750,   751,   752,   753,
     754,   756,   757,   758,   759,   760,   762,   763,   764,   765,
     766,   768,   772,   773,   774,   775,   777,   778,   782,   783,
     784,   785,   786,   787,   788,   789,   790,   791,   792,   793,
     794,   796,   798,   803,   804,   805,   806,   807,   808,   809,
     810,   811,   812,   813,   814,   815,   816,   817,   818,   819
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
#line 4962 "frontend/parser.cpp"

#line 822 "frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    auto msg = std::to_string(scanner->llvmloc->begin.line) + ":" + std::to_string(scanner->llvmloc->begin.column) + ": " + err_message;
    scanner->fatal_error(ptc::diag::ERR_SYNTAX, msg);
}
