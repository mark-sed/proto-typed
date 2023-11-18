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
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > ()), scanner->parseVar(scanner->parseExtType(yystack_[0].value.as < std::string > (), false)->getName(), true), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1811 "frontend/parser.cpp"
    break;

  case 116: // expr_var: "external identifier" "as" "external identifier"
#line 409 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > (), true), scanner->parseVar(scanner->parseExtType(yystack_[0].value.as < std::string > (), false)->getName(), true), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1817 "frontend/parser.cpp"
    break;

  case 117: // expr_var: expr_var "as" "external identifier"
#line 410 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseVar(scanner->parseExtType(yystack_[0].value.as < std::string > (), false)->getName(), true), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1823 "frontend/parser.cpp"
    break;

  case 118: // expr_var: "identifier" "as" type
#line 411 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > ()), scanner->parseVar(yystack_[0].value.as < ptc::ir::IR * > ()->getName()), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1829 "frontend/parser.cpp"
    break;

  case 119: // expr_var: "external identifier" "as" type
#line 412 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > (), true), scanner->parseVar(yystack_[0].value.as < ptc::ir::IR * > ()->getName()), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1835 "frontend/parser.cpp"
    break;

  case 120: // expr_var: expr_var "as" type
#line 413 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseVar(yystack_[0].value.as < ptc::ir::IR * > ()->getName()), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1841 "frontend/parser.cpp"
    break;

  case 121: // expr_var: expr_mat slice
#line 415 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1847 "frontend/parser.cpp"
    break;

  case 124: // expr_var: expr_var slice
#line 418 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1853 "frontend/parser.cpp"
    break;

  case 125: // expr_var: expr_var "." "identifier"
#line 420 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1859 "frontend/parser.cpp"
    break;

  case 126: // expr_var: expr_var "." "external identifier"
#line 421 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1865 "frontend/parser.cpp"
    break;

  case 127: // expr_var: expr_float "**" expr_var
#line 424 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1871 "frontend/parser.cpp"
    break;

  case 128: // expr_var: expr_var "**" expr_float
#line 425 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1877 "frontend/parser.cpp"
    break;

  case 129: // expr_var: expr_var "**" expr_var
#line 426 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1883 "frontend/parser.cpp"
    break;

  case 130: // expr_var: expr_int "**" expr_var
#line 427 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < long > ()) /*Float on purpose*/, yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1889 "frontend/parser.cpp"
    break;

  case 131: // expr_var: expr_var "**" expr_int
#line 428 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < long > ()) /*Float on purpose*/, ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1895 "frontend/parser.cpp"
    break;

  case 132: // expr_var: expr_int "*" expr_var
#line 430 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1901 "frontend/parser.cpp"
    break;

  case 133: // expr_var: expr_float "*" expr_var
#line 431 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1907 "frontend/parser.cpp"
    break;

  case 134: // expr_var: expr_var "*" expr_int
#line 432 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1913 "frontend/parser.cpp"
    break;

  case 135: // expr_var: expr_var "*" expr_float
#line 433 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1919 "frontend/parser.cpp"
    break;

  case 136: // expr_var: expr_var "*" expr_var
#line 434 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1925 "frontend/parser.cpp"
    break;

  case 137: // expr_var: expr_int "/" expr_var
#line 436 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1931 "frontend/parser.cpp"
    break;

  case 138: // expr_var: expr_float "/" expr_var
#line 437 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1937 "frontend/parser.cpp"
    break;

  case 139: // expr_var: expr_var "/" expr_int
#line 438 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1943 "frontend/parser.cpp"
    break;

  case 140: // expr_var: expr_var "/" expr_float
#line 439 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1949 "frontend/parser.cpp"
    break;

  case 141: // expr_var: expr_var "/" expr_var
#line 440 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1955 "frontend/parser.cpp"
    break;

  case 142: // expr_var: expr_int "%" expr_var
#line 442 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1961 "frontend/parser.cpp"
    break;

  case 143: // expr_var: expr_float "%" expr_var
#line 443 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1967 "frontend/parser.cpp"
    break;

  case 144: // expr_var: expr_var "%" expr_int
#line 444 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1973 "frontend/parser.cpp"
    break;

  case 145: // expr_var: expr_var "%" expr_float
#line 445 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1979 "frontend/parser.cpp"
    break;

  case 146: // expr_var: expr_var "%" expr_var
#line 446 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1985 "frontend/parser.cpp"
    break;

  case 147: // expr_var: expr_int "+" expr_var
#line 448 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1991 "frontend/parser.cpp"
    break;

  case 148: // expr_var: expr_float "+" expr_var
#line 449 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1997 "frontend/parser.cpp"
    break;

  case 149: // expr_var: expr_var "+" expr_int
#line 450 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2003 "frontend/parser.cpp"
    break;

  case 150: // expr_var: expr_var "+" expr_float
#line 451 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2009 "frontend/parser.cpp"
    break;

  case 151: // expr_var: expr_mat "+" expr_mat
#line 452 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2015 "frontend/parser.cpp"
    break;

  case 152: // expr_var: expr_var "+" expr_mat
#line 453 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2021 "frontend/parser.cpp"
    break;

  case 153: // expr_var: expr_mat "+" expr_var
#line 454 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2027 "frontend/parser.cpp"
    break;

  case 154: // expr_var: expr_var "+" expr_var
#line 455 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2033 "frontend/parser.cpp"
    break;

  case 155: // expr_var: expr_int "-" expr_var
#line 457 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2039 "frontend/parser.cpp"
    break;

  case 156: // expr_var: expr_float "-" expr_var
#line 458 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2045 "frontend/parser.cpp"
    break;

  case 157: // expr_var: expr_var "-" expr_int
#line 459 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2051 "frontend/parser.cpp"
    break;

  case 158: // expr_var: expr_var "-" expr_float
#line 460 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2057 "frontend/parser.cpp"
    break;

  case 159: // expr_var: expr_var "-" expr_var
#line 461 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2063 "frontend/parser.cpp"
    break;

  case 160: // expr_var: expr_int "<<" expr_var
#line 463 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2069 "frontend/parser.cpp"
    break;

  case 161: // expr_var: expr_var "<<" expr_int
#line 464 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2075 "frontend/parser.cpp"
    break;

  case 162: // expr_var: expr_var "<<" expr_var
#line 465 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2081 "frontend/parser.cpp"
    break;

  case 163: // expr_var: expr_int ">>" expr_var
#line 467 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2087 "frontend/parser.cpp"
    break;

  case 164: // expr_var: expr_var ">>" expr_int
#line 468 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2093 "frontend/parser.cpp"
    break;

  case 165: // expr_var: expr_var ">>" expr_var
#line 469 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2099 "frontend/parser.cpp"
    break;

  case 166: // expr_var: expr_int ">" expr_var
#line 471 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2105 "frontend/parser.cpp"
    break;

  case 167: // expr_var: expr_float ">" expr_var
#line 472 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2111 "frontend/parser.cpp"
    break;

  case 168: // expr_var: expr_str ">" expr_var
#line 473 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2117 "frontend/parser.cpp"
    break;

  case 169: // expr_var: expr_var ">" expr_int
#line 474 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2123 "frontend/parser.cpp"
    break;

  case 170: // expr_var: expr_var ">" expr_float
#line 475 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2129 "frontend/parser.cpp"
    break;

  case 171: // expr_var: expr_var ">" expr_str
#line 476 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2135 "frontend/parser.cpp"
    break;

  case 172: // expr_var: expr_var ">" expr_var
#line 477 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2141 "frontend/parser.cpp"
    break;

  case 173: // expr_var: expr_int ">=" expr_var
#line 479 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2147 "frontend/parser.cpp"
    break;

  case 174: // expr_var: expr_float ">=" expr_var
#line 480 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2153 "frontend/parser.cpp"
    break;

  case 175: // expr_var: expr_str ">=" expr_var
#line 481 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2159 "frontend/parser.cpp"
    break;

  case 176: // expr_var: expr_var ">=" expr_int
#line 482 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2165 "frontend/parser.cpp"
    break;

  case 177: // expr_var: expr_var ">=" expr_float
#line 483 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2171 "frontend/parser.cpp"
    break;

  case 178: // expr_var: expr_var ">=" expr_str
#line 484 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2177 "frontend/parser.cpp"
    break;

  case 179: // expr_var: expr_var ">=" expr_var
#line 485 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2183 "frontend/parser.cpp"
    break;

  case 180: // expr_var: expr_int "<" expr_var
#line 487 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2189 "frontend/parser.cpp"
    break;

  case 181: // expr_var: expr_float "<" expr_var
#line 488 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2195 "frontend/parser.cpp"
    break;

  case 182: // expr_var: expr_str "<" expr_var
#line 489 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2201 "frontend/parser.cpp"
    break;

  case 183: // expr_var: expr_var "<" expr_int
#line 490 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2207 "frontend/parser.cpp"
    break;

  case 184: // expr_var: expr_var "<" expr_float
#line 491 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2213 "frontend/parser.cpp"
    break;

  case 185: // expr_var: expr_var "<" expr_str
#line 492 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2219 "frontend/parser.cpp"
    break;

  case 186: // expr_var: expr_var "<" expr_var
#line 493 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2225 "frontend/parser.cpp"
    break;

  case 187: // expr_var: expr_int "<=" expr_var
#line 495 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2231 "frontend/parser.cpp"
    break;

  case 188: // expr_var: expr_float "<=" expr_var
#line 496 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2237 "frontend/parser.cpp"
    break;

  case 189: // expr_var: expr_str "<=" expr_var
#line 497 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2243 "frontend/parser.cpp"
    break;

  case 190: // expr_var: expr_var "<=" expr_int
#line 498 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2249 "frontend/parser.cpp"
    break;

  case 191: // expr_var: expr_var "<=" expr_float
#line 499 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2255 "frontend/parser.cpp"
    break;

  case 192: // expr_var: expr_var "<=" expr_str
#line 500 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2261 "frontend/parser.cpp"
    break;

  case 193: // expr_var: expr_var "<=" expr_var
#line 501 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2267 "frontend/parser.cpp"
    break;

  case 194: // expr_var: expr_int "==" expr_var
#line 503 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2273 "frontend/parser.cpp"
    break;

  case 195: // expr_var: expr_float "==" expr_var
#line 504 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2279 "frontend/parser.cpp"
    break;

  case 196: // expr_var: expr_str "==" expr_var
#line 505 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2285 "frontend/parser.cpp"
    break;

  case 197: // expr_var: expr_bool "==" expr_var
#line 506 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2291 "frontend/parser.cpp"
    break;

  case 198: // expr_var: expr_none "==" expr_var
#line 507 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2297 "frontend/parser.cpp"
    break;

  case 201: // expr_var: expr_var "==" expr_int
#line 510 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2303 "frontend/parser.cpp"
    break;

  case 202: // expr_var: expr_var "==" expr_float
#line 511 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2309 "frontend/parser.cpp"
    break;

  case 203: // expr_var: expr_var "==" expr_str
#line 512 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2315 "frontend/parser.cpp"
    break;

  case 204: // expr_var: expr_var "==" expr_bool
#line 513 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2321 "frontend/parser.cpp"
    break;

  case 205: // expr_var: expr_var "==" expr_none
#line 514 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2327 "frontend/parser.cpp"
    break;

  case 206: // expr_var: expr_var "==" expr_struct
#line 515 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2333 "frontend/parser.cpp"
    break;

  case 207: // expr_var: expr_mat "==" expr_mat
#line 516 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2339 "frontend/parser.cpp"
    break;

  case 208: // expr_var: expr_var "==" expr_mat
#line 517 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2345 "frontend/parser.cpp"
    break;

  case 209: // expr_var: expr_mat "==" expr_var
#line 518 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2351 "frontend/parser.cpp"
    break;

  case 210: // expr_var: expr_var "==" expr_var
#line 519 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2357 "frontend/parser.cpp"
    break;

  case 211: // expr_var: expr_int "!=" expr_var
#line 521 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2363 "frontend/parser.cpp"
    break;

  case 212: // expr_var: expr_float "!=" expr_var
#line 522 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2369 "frontend/parser.cpp"
    break;

  case 213: // expr_var: expr_str "!=" expr_var
#line 523 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2375 "frontend/parser.cpp"
    break;

  case 214: // expr_var: expr_bool "!=" expr_var
#line 524 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2381 "frontend/parser.cpp"
    break;

  case 215: // expr_var: expr_none "!=" expr_var
#line 525 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2387 "frontend/parser.cpp"
    break;

  case 218: // expr_var: expr_var "!=" expr_int
#line 528 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2393 "frontend/parser.cpp"
    break;

  case 219: // expr_var: expr_var "!=" expr_float
#line 529 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2399 "frontend/parser.cpp"
    break;

  case 220: // expr_var: expr_var "!=" expr_str
#line 530 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2405 "frontend/parser.cpp"
    break;

  case 221: // expr_var: expr_var "!=" expr_bool
#line 531 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2411 "frontend/parser.cpp"
    break;

  case 222: // expr_var: expr_var "!=" expr_none
#line 532 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2417 "frontend/parser.cpp"
    break;

  case 223: // expr_var: expr_var "!=" expr_struct
#line 533 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2423 "frontend/parser.cpp"
    break;

  case 224: // expr_var: expr_mat "!=" expr_mat
#line 534 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2429 "frontend/parser.cpp"
    break;

  case 225: // expr_var: expr_var "!=" expr_mat
#line 535 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2435 "frontend/parser.cpp"
    break;

  case 226: // expr_var: expr_mat "!=" expr_var
#line 536 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2441 "frontend/parser.cpp"
    break;

  case 227: // expr_var: expr_var "!=" expr_var
#line 537 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2447 "frontend/parser.cpp"
    break;

  case 228: // expr_var: expr_int "&" expr_var
#line 539 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2453 "frontend/parser.cpp"
    break;

  case 229: // expr_var: expr_var "&" expr_int
#line 540 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2459 "frontend/parser.cpp"
    break;

  case 230: // expr_var: expr_var "&" expr_var
#line 541 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2465 "frontend/parser.cpp"
    break;

  case 231: // expr_var: expr_int "^" expr_var
#line 543 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2471 "frontend/parser.cpp"
    break;

  case 232: // expr_var: expr_var "^" expr_int
#line 544 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2477 "frontend/parser.cpp"
    break;

  case 233: // expr_var: expr_var "^" expr_var
#line 545 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2483 "frontend/parser.cpp"
    break;

  case 234: // expr_var: expr_int "|" expr_var
#line 547 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2489 "frontend/parser.cpp"
    break;

  case 235: // expr_var: expr_var "|" expr_int
#line 548 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2495 "frontend/parser.cpp"
    break;

  case 236: // expr_var: expr_var "|" expr_var
#line 549 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2501 "frontend/parser.cpp"
    break;

  case 241: // expr_var: expr_none "in" expr_mat
#line 555 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2507 "frontend/parser.cpp"
    break;

  case 243: // expr_var: expr_mat "in" expr_mat
#line 557 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2513 "frontend/parser.cpp"
    break;

  case 248: // expr_var: expr_none "in" expr_var
#line 562 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2519 "frontend/parser.cpp"
    break;

  case 250: // expr_var: expr_mat "in" expr_var
#line 564 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2525 "frontend/parser.cpp"
    break;

  case 251: // expr_var: expr_var "in" expr_str
#line 565 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2531 "frontend/parser.cpp"
    break;

  case 252: // expr_var: expr_var "in" expr_var
#line 566 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2537 "frontend/parser.cpp"
    break;

  case 253: // expr_var: expr_bool "and" expr_var
#line 568 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2543 "frontend/parser.cpp"
    break;

  case 254: // expr_var: expr_var "and" expr_bool
#line 569 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2549 "frontend/parser.cpp"
    break;

  case 255: // expr_var: expr_var "and" expr_var
#line 570 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2555 "frontend/parser.cpp"
    break;

  case 256: // expr_var: expr_bool "or" expr_var
#line 572 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2561 "frontend/parser.cpp"
    break;

  case 257: // expr_var: expr_var "or" expr_bool
#line 573 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2567 "frontend/parser.cpp"
    break;

  case 258: // expr_var: expr_var "or" expr_var
#line 574 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2573 "frontend/parser.cpp"
    break;

  case 259: // expr_var: "not" expr_var
#line 576 "frontend/parser.yy"
                         { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseUnaryPrefixExpr(yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LNOT)); }
#line 2579 "frontend/parser.cpp"
    break;

  case 260: // expr_var: "~" expr_var
#line 578 "frontend/parser.yy"
                         { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseUnaryPrefixExpr(yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BNOT)); }
#line 2585 "frontend/parser.cpp"
    break;

  case 261: // expr_var: expr_int "++" expr_var
#line 580 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2591 "frontend/parser.cpp"
    break;

  case 262: // expr_var: expr_float "++" expr_var
#line 581 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2597 "frontend/parser.cpp"
    break;

  case 263: // expr_var: expr_str "++" expr_var
#line 582 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2603 "frontend/parser.cpp"
    break;

  case 264: // expr_var: expr_bool "++" expr_var
#line 583 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2609 "frontend/parser.cpp"
    break;

  case 265: // expr_var: expr_none "++" expr_var
#line 584 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseNone(), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2615 "frontend/parser.cpp"
    break;

  case 266: // expr_var: expr_var "++" expr_int
#line 585 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2621 "frontend/parser.cpp"
    break;

  case 267: // expr_var: expr_var "++" expr_float
#line 586 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2627 "frontend/parser.cpp"
    break;

  case 268: // expr_var: expr_var "++" expr_str
#line 587 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2633 "frontend/parser.cpp"
    break;

  case 269: // expr_var: expr_var "++" expr_bool
#line 588 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2639 "frontend/parser.cpp"
    break;

  case 270: // expr_var: expr_var "++" expr_none
#line 589 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseNone(), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2645 "frontend/parser.cpp"
    break;

  case 271: // expr_var: expr_var "++" expr_var
#line 590 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2651 "frontend/parser.cpp"
    break;

  case 272: // matrix: "[" "]"
#line 594 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(std::vector<ptc::ir::Expr *>{}); }
#line 2657 "frontend/parser.cpp"
    break;

  case 273: // matrix: "[" matvals "]"
#line 595 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2663 "frontend/parser.cpp"
    break;

  case 274: // matrix: "[" "terminator (\\n or ;)" matvals "]"
#line 596 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2669 "frontend/parser.cpp"
    break;

  case 275: // matrix: "[" matvals "terminator (\\n or ;)" "]"
#line 597 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2675 "frontend/parser.cpp"
    break;

  case 276: // matrix: "[" "terminator (\\n or ;)" matvals "terminator (\\n or ;)" "]"
#line 598 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2681 "frontend/parser.cpp"
    break;

  case 277: // matvals: expr
#line 601 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixValue(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2687 "frontend/parser.cpp"
    break;

  case 278: // matvals: matvals "," expr
#line 602 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2693 "frontend/parser.cpp"
    break;

  case 279: // matvals: matvals "," "terminator (\\n or ;)" expr
#line 603 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[3].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2699 "frontend/parser.cpp"
    break;

  case 280: // expr_mat: matrix
#line 607 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2705 "frontend/parser.cpp"
    break;

  case 281: // expr_mat: "(" matrix ")"
#line 608 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2711 "frontend/parser.cpp"
    break;

  case 282: // range: "(" range ")"
#line 610 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2717 "frontend/parser.cpp"
    break;

  case 283: // range: int_val ".." int_val
#line 611 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseRange(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2723 "frontend/parser.cpp"
    break;

  case 284: // range: int_val "," int_val ".." int_val
#line 612 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseRange(yystack_[4].value.as < ptc::ir::Expr * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2729 "frontend/parser.cpp"
    break;

  case 285: // int_val: expr_int
#line 614 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 2735 "frontend/parser.cpp"
    break;

  case 286: // int_val: expr_var
#line 615 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2741 "frontend/parser.cpp"
    break;

  case 299: // expr_none: "none"
#line 632 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseNone(); }
#line 2747 "frontend/parser.cpp"
    break;

  case 300: // expr_none: "(" "none" ")"
#line 633 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseNone(); }
#line 2753 "frontend/parser.cpp"
    break;

  case 307: // expr_int: "int"
#line 648 "frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 2759 "frontend/parser.cpp"
    break;

  case 308: // expr_int: "-" expr_int
#line 649 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 2765 "frontend/parser.cpp"
    break;

  case 309: // expr_int: "(" expr_int ")"
#line 650 "frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 2771 "frontend/parser.cpp"
    break;

  case 310: // expr_int: "~" expr_int
#line 651 "frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 2777 "frontend/parser.cpp"
    break;

  case 311: // expr_int: expr_int "*" expr_int
#line 652 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 2783 "frontend/parser.cpp"
    break;

  case 312: // expr_int: expr_int "/" expr_int
#line 653 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 2789 "frontend/parser.cpp"
    break;

  case 313: // expr_int: expr_int "%" expr_int
#line 654 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 2795 "frontend/parser.cpp"
    break;

  case 314: // expr_int: expr_int "-" expr_int
#line 655 "frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 2801 "frontend/parser.cpp"
    break;

  case 315: // expr_int: expr_int "+" expr_int
#line 656 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 2807 "frontend/parser.cpp"
    break;

  case 316: // expr_int: expr_int "<<" expr_int
#line 657 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 2813 "frontend/parser.cpp"
    break;

  case 317: // expr_int: expr_int ">>" expr_int
#line 658 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 2819 "frontend/parser.cpp"
    break;

  case 318: // expr_int: expr_int "&" expr_int
#line 659 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 2825 "frontend/parser.cpp"
    break;

  case 319: // expr_int: expr_int "^" expr_int
#line 660 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 2831 "frontend/parser.cpp"
    break;

  case 320: // expr_int: expr_int "|" expr_int
#line 661 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 2837 "frontend/parser.cpp"
    break;

  case 321: // expr_float: "float"
#line 665 "frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 2843 "frontend/parser.cpp"
    break;

  case 322: // expr_float: "-" expr_float
#line 666 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 2849 "frontend/parser.cpp"
    break;

  case 323: // expr_float: "(" expr_float ")"
#line 667 "frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 2855 "frontend/parser.cpp"
    break;

  case 324: // expr_float: expr_float "**" expr_float
#line 668 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2861 "frontend/parser.cpp"
    break;

  case 325: // expr_float: expr_float "**" expr_int
#line 669 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2867 "frontend/parser.cpp"
    break;

  case 326: // expr_float: expr_int "**" expr_float
#line 670 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2873 "frontend/parser.cpp"
    break;

  case 327: // expr_float: expr_float "*" expr_float
#line 671 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 2879 "frontend/parser.cpp"
    break;

  case 328: // expr_float: expr_float "*" expr_int
#line 672 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 2885 "frontend/parser.cpp"
    break;

  case 329: // expr_float: expr_int "*" expr_float
#line 673 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 2891 "frontend/parser.cpp"
    break;

  case 330: // expr_float: expr_float "/" expr_float
#line 674 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 2897 "frontend/parser.cpp"
    break;

  case 331: // expr_float: expr_float "/" expr_int
#line 675 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 2903 "frontend/parser.cpp"
    break;

  case 332: // expr_float: expr_int "/" expr_float
#line 676 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 2909 "frontend/parser.cpp"
    break;

  case 333: // expr_float: expr_float "%" expr_float
#line 677 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2915 "frontend/parser.cpp"
    break;

  case 334: // expr_float: expr_float "%" expr_int
#line 678 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2921 "frontend/parser.cpp"
    break;

  case 335: // expr_float: expr_int "%" expr_float
#line 679 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2927 "frontend/parser.cpp"
    break;

  case 336: // expr_float: expr_float "-" expr_float
#line 680 "frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 2933 "frontend/parser.cpp"
    break;

  case 337: // expr_float: expr_float "-" expr_int
#line 681 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 2939 "frontend/parser.cpp"
    break;

  case 338: // expr_float: expr_int "-" expr_float
#line 682 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 2945 "frontend/parser.cpp"
    break;

  case 339: // expr_float: expr_float "+" expr_float
#line 683 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 2951 "frontend/parser.cpp"
    break;

  case 340: // expr_float: expr_float "+" expr_int
#line 684 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 2957 "frontend/parser.cpp"
    break;

  case 341: // expr_float: expr_int "+" expr_float
#line 685 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 2963 "frontend/parser.cpp"
    break;

  case 342: // expr_str: "string"
#line 689 "frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2969 "frontend/parser.cpp"
    break;

  case 343: // expr_str: "(" expr_str ")"
#line 690 "frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 2975 "frontend/parser.cpp"
    break;

  case 344: // expr_str: expr_str "++" expr_str
#line 691 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 2981 "frontend/parser.cpp"
    break;

  case 345: // expr_str: expr_str "++" expr_int
#line 692 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 2987 "frontend/parser.cpp"
    break;

  case 346: // expr_str: expr_str "++" expr_float
#line 693 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 2993 "frontend/parser.cpp"
    break;

  case 347: // expr_str: expr_str "++" expr_bool
#line 694 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2999 "frontend/parser.cpp"
    break;

  case 348: // expr_str: expr_str "++" expr_none
#line 695 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 3005 "frontend/parser.cpp"
    break;

  case 349: // expr_str: expr_int "++" expr_str
#line 696 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 3011 "frontend/parser.cpp"
    break;

  case 350: // expr_str: expr_int "++" expr_int
#line 697 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 3017 "frontend/parser.cpp"
    break;

  case 351: // expr_str: expr_int "++" expr_float
#line 698 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 3023 "frontend/parser.cpp"
    break;

  case 352: // expr_str: expr_int "++" expr_bool
#line 699 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3029 "frontend/parser.cpp"
    break;

  case 353: // expr_str: expr_int "++" expr_none
#line 700 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 3035 "frontend/parser.cpp"
    break;

  case 354: // expr_str: expr_float "++" expr_str
#line 701 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 3041 "frontend/parser.cpp"
    break;

  case 355: // expr_str: expr_float "++" expr_int
#line 702 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 3047 "frontend/parser.cpp"
    break;

  case 356: // expr_str: expr_float "++" expr_float
#line 703 "frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 3053 "frontend/parser.cpp"
    break;

  case 357: // expr_str: expr_float "++" expr_bool
#line 704 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3059 "frontend/parser.cpp"
    break;

  case 358: // expr_str: expr_float "++" expr_none
#line 705 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 3065 "frontend/parser.cpp"
    break;

  case 359: // expr_str: expr_bool "++" expr_str
#line 706 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 3071 "frontend/parser.cpp"
    break;

  case 360: // expr_str: expr_bool "++" expr_int
#line 707 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 3077 "frontend/parser.cpp"
    break;

  case 361: // expr_str: expr_bool "++" expr_float
#line 708 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 3083 "frontend/parser.cpp"
    break;

  case 362: // expr_str: expr_bool "++" expr_bool
#line 709 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3089 "frontend/parser.cpp"
    break;

  case 363: // expr_str: expr_bool "++" expr_none
#line 710 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 3095 "frontend/parser.cpp"
    break;

  case 364: // expr_str: expr_none "++" expr_str
#line 711 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 3101 "frontend/parser.cpp"
    break;

  case 365: // expr_str: expr_none "++" expr_int
#line 712 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 3107 "frontend/parser.cpp"
    break;

  case 366: // expr_str: expr_none "++" expr_float
#line 713 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 3113 "frontend/parser.cpp"
    break;

  case 367: // expr_str: expr_none "++" expr_bool
#line 714 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3119 "frontend/parser.cpp"
    break;

  case 368: // expr_str: expr_none "++" expr_none
#line 715 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 3125 "frontend/parser.cpp"
    break;

  case 369: // expr_bool: "bool"
#line 719 "frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 3131 "frontend/parser.cpp"
    break;

  case 370: // expr_bool: "(" expr_bool ")"
#line 720 "frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 3137 "frontend/parser.cpp"
    break;

  case 371: // expr_bool: "not" expr_bool
#line 721 "frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 3143 "frontend/parser.cpp"
    break;

  case 372: // expr_bool: expr_bool "or" expr_bool
#line 722 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 3149 "frontend/parser.cpp"
    break;

  case 373: // expr_bool: expr_bool "and" expr_bool
#line 723 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 3155 "frontend/parser.cpp"
    break;

  case 374: // expr_bool: expr_bool "==" expr_bool
#line 725 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 3161 "frontend/parser.cpp"
    break;

  case 375: // expr_bool: expr_int "==" expr_int
#line 726 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 3167 "frontend/parser.cpp"
    break;

  case 376: // expr_bool: expr_int "==" expr_float
#line 727 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 3173 "frontend/parser.cpp"
    break;

  case 377: // expr_bool: expr_float "==" expr_float
#line 728 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 3179 "frontend/parser.cpp"
    break;

  case 378: // expr_bool: expr_float "==" expr_int
#line 729 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 3185 "frontend/parser.cpp"
    break;

  case 379: // expr_bool: expr_str "==" expr_str
#line 730 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 3191 "frontend/parser.cpp"
    break;

  case 380: // expr_bool: expr_none "==" expr_none
#line 731 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 3197 "frontend/parser.cpp"
    break;

  case 381: // expr_bool: expr_bool "!=" expr_bool
#line 733 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 3203 "frontend/parser.cpp"
    break;

  case 382: // expr_bool: expr_int "!=" expr_int
#line 734 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 3209 "frontend/parser.cpp"
    break;

  case 383: // expr_bool: expr_int "!=" expr_float
#line 735 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 3215 "frontend/parser.cpp"
    break;

  case 384: // expr_bool: expr_float "!=" expr_float
#line 736 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 3221 "frontend/parser.cpp"
    break;

  case 385: // expr_bool: expr_float "!=" expr_int
#line 737 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 3227 "frontend/parser.cpp"
    break;

  case 386: // expr_bool: expr_str "!=" expr_str
#line 738 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 3233 "frontend/parser.cpp"
    break;

  case 387: // expr_bool: expr_none "!=" expr_none
#line 739 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 3239 "frontend/parser.cpp"
    break;

  case 388: // expr_bool: expr_int ">" expr_int
#line 741 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 3245 "frontend/parser.cpp"
    break;

  case 389: // expr_bool: expr_int ">" expr_float
#line 742 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 3251 "frontend/parser.cpp"
    break;

  case 390: // expr_bool: expr_float ">" expr_float
#line 743 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 3257 "frontend/parser.cpp"
    break;

  case 391: // expr_bool: expr_float ">" expr_int
#line 744 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 3263 "frontend/parser.cpp"
    break;

  case 392: // expr_bool: expr_str ">" expr_str
#line 745 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 3269 "frontend/parser.cpp"
    break;

  case 393: // expr_bool: expr_int "<" expr_int
#line 747 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 3275 "frontend/parser.cpp"
    break;

  case 394: // expr_bool: expr_int "<" expr_float
#line 748 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 3281 "frontend/parser.cpp"
    break;

  case 395: // expr_bool: expr_float "<" expr_float
#line 749 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 3287 "frontend/parser.cpp"
    break;

  case 396: // expr_bool: expr_float "<" expr_int
#line 750 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 3293 "frontend/parser.cpp"
    break;

  case 397: // expr_bool: expr_str "<" expr_str
#line 751 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 3299 "frontend/parser.cpp"
    break;

  case 398: // expr_bool: expr_int ">=" expr_int
#line 753 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 3305 "frontend/parser.cpp"
    break;

  case 399: // expr_bool: expr_int ">=" expr_float
#line 754 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 3311 "frontend/parser.cpp"
    break;

  case 400: // expr_bool: expr_float ">=" expr_float
#line 755 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 3317 "frontend/parser.cpp"
    break;

  case 401: // expr_bool: expr_float ">=" expr_int
#line 756 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 3323 "frontend/parser.cpp"
    break;

  case 402: // expr_bool: expr_str ">=" expr_str
#line 757 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 3329 "frontend/parser.cpp"
    break;

  case 403: // expr_bool: expr_int "<=" expr_int
#line 759 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 3335 "frontend/parser.cpp"
    break;

  case 404: // expr_bool: expr_int "<=" expr_float
#line 760 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 3341 "frontend/parser.cpp"
    break;

  case 405: // expr_bool: expr_float "<=" expr_float
#line 761 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 3347 "frontend/parser.cpp"
    break;

  case 406: // expr_bool: expr_float "<=" expr_int
#line 762 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 3353 "frontend/parser.cpp"
    break;

  case 407: // expr_bool: expr_str "<=" expr_str
#line 763 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 3359 "frontend/parser.cpp"
    break;

  case 408: // expr_bool: expr_str "in" expr_str
#line 765 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[0].value.as < std::string > ().find(yystack_[2].value.as < std::string > ()) != std::string::npos; }
#line 3365 "frontend/parser.cpp"
    break;

  case 415: // mattype: "identifier" matsq
#line 779 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3371 "frontend/parser.cpp"
    break;

  case 416: // mattype: "'int'" matsq
#line 780 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(INT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3377 "frontend/parser.cpp"
    break;

  case 417: // mattype: "'float'" matsq
#line 781 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(FLOAT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3383 "frontend/parser.cpp"
    break;

  case 418: // mattype: "'string'" matsq
#line 782 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(STRING_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3389 "frontend/parser.cpp"
    break;

  case 419: // mattype: "'bool'" matsq
#line 783 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(BOOL_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3395 "frontend/parser.cpp"
    break;

  case 420: // mattype: "any" matsq
#line 784 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(ANY_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3401 "frontend/parser.cpp"
    break;

  case 428: // matsq: "[" "]"
#line 793 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(scanner->parseInt(-1)); }
#line 3407 "frontend/parser.cpp"
    break;

  case 429: // matsq: "[" "]" matsq
#line 795 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), scanner->parseInt(-1)); }
#line 3413 "frontend/parser.cpp"
    break;

  case 430: // type: "'int'" "?"
#line 800 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, true, true); }
#line 3419 "frontend/parser.cpp"
    break;

  case 431: // type: "'float'" "?"
#line 801 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, true, true); }
#line 3425 "frontend/parser.cpp"
    break;

  case 432: // type: "'string'" "?"
#line 802 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, true, true); }
#line 3431 "frontend/parser.cpp"
    break;

  case 433: // type: "'bool'" "?"
#line 803 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, true, true); }
#line 3437 "frontend/parser.cpp"
    break;

  case 434: // type: "identifier" "?"
#line 804 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[1].value.as < std::string > (), true, true); }
#line 3443 "frontend/parser.cpp"
    break;

  case 437: // type: mattype "?"
#line 807 "frontend/parser.yy"
       { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 3449 "frontend/parser.cpp"
    break;

  case 438: // type: "'int'"
#line 808 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, false, true); }
#line 3455 "frontend/parser.cpp"
    break;

  case 439: // type: "'float'"
#line 809 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, false, true); }
#line 3461 "frontend/parser.cpp"
    break;

  case 440: // type: "'string'"
#line 810 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, false, true); }
#line 3467 "frontend/parser.cpp"
    break;

  case 441: // type: "'bool'"
#line 811 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, false, true); }
#line 3473 "frontend/parser.cpp"
    break;

  case 442: // type: "any"
#line 812 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(ANY_CSTR, false, true); }
#line 3479 "frontend/parser.cpp"
    break;

  case 443: // type: "identifier"
#line 813 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[0].value.as < std::string > (), false, true); }
#line 3485 "frontend/parser.cpp"
    break;

  case 444: // type: "external identifier"
#line 814 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExtType(yystack_[0].value.as < std::string > (), false); }
#line 3491 "frontend/parser.cpp"
    break;

  case 446: // type: mattype
#line 816 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 3497 "frontend/parser.cpp"
    break;


#line 3501 "frontend/parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -657;

  const short  Parser ::yytable_ninf_ = -445;

  const short
   Parser ::yypact_[] =
  {
    1913,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  1362,    32,
      63,  1734,  1734,   -49,    34,     0,  -657,  -657,  -657,  -657,
    1734,  -657,  -657,    19,    -3,    35,    43,    47,    41,     1,
     362,    54,   145,  1467,  -657,  -657,   146,   146,  -657,  -657,
     120,  -657,   174,  -657,  2165,  -657,   236,  -657,  -657,   146,
     146,   146,  1351,  2413,  -657,   409,   666,   118,  2695,  1597,
    1237,   640,    48,   178,     4,   243,   365,   124,  2102,   249,
     409,   666,   118,  2613,  2671,   950,   535,  1734,  -657,   365,
    -657,   135,   459,   459,   484,  -657,  -657,  -657,  -657,   389,
    2695,  1597,  1237,  -657,   389,  -657,   640,   219,   297,  -657,
     275,  -657,  -657,   344,    34,  -657,    34,  -657,    34,  -657,
      34,  -657,   129,   562,  -657,   381,   672,    33,  1566,    34,
    -657,  -657,  -657,  1174,  2262,  -657,  -657,  -657,  -657,  2320,
    -657,  -657,  -657,  -657,  -657,  2331,  1734,   386,  2244,  -657,
    -657,   334,  1734,  -657,  -657,  -657,  1734,  1734,  1734,  1734,
    1734,  1734,  1734,  1734,  1734,  1734,  1734,  1734,  1734,  -657,
     867,  1174,  1734,  1734,  1734,  1734,  1734,  1734,  1734,  1734,
    1734,  1734,  2786,  1734,  1734,  1734,  1734,  1734,  1734,  1734,
    1734,  1734,  1734,  1734,   318,  -657,  1174,  1734,  1734,  1734,
    1734,  -657,  1734,  1734,  1734,  1734,  1734,  1734,  1734,  1734,
    1734,  1734,  1734,  1734,  1734,  1734,  1734,  1734,  1734,  1734,
    1734,  1734,  1734,  1734,  1734,  1734,  1734,  1734,  1734,  1734,
    1734,  1734,  1734,  1734,  1734,  1734,  1734,  1734,  1734,  1734,
    1734,  1734,  1734,  1734,  1734,  1734,  1734,  1734,  1734,  1734,
    1734,  1734,  1734,  1734,  1734,  1734,  1734,    34,  -657,  -657,
    1046,    21,   396,  -657,  1174,   406,  -657,  -657,  -657,  -657,
    -657,  -657,   136,   401,  -657,   403,  2012,  1080,   484,   484,
    -657,   459,   459,   459,   459,   459,   459,   484,   484,   484,
     484,   484,   459,   459,   459,   459,   459,   459,  1734,    34,
       0,  1734,  -657,  -657,  -657,  -657,   405,    49,  -657,   416,
      59,   357,   426,    14,   434,   715,  2413,    83,  2695,  -657,
     364,   439,   357,   456,  -657,    88,   357,   456,  -657,    18,
      29,   436,     5,   491,  2320,  -657,  1991,   493,   498,  -657,
    2849,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,
    -657,  -657,  -657,  -657,     8,  -657,   122,   363,   499,   478,
     609,   363,   478,   609,   412,   501,   503,   412,   501,   503,
     412,   501,   503,   412,   501,   503,  2494,   352,  2719,  2246,
     718,   682,  2554,   425,  2524,   684,  2584,   449,   357,   456,
    2168,  2791,  2450,  2743,   993,  2767,   779,  1126,   779,  1126,
    1538,    16,  -657,  -657,  2799,   822,   411,  -657,  1538,    16,
    -657,  -657,  2799,   822,   411,  -657,  1470,  1248,  1135,   513,
    1470,  1248,  1135,   513,  1470,  1248,  1135,   513,  1470,  1248,
    1135,   513,  -657,  -657,   238,   363,   499,  2584,   608,  1538,
      16,  1538,    16,  2494,   352,  2719,  2246,   718,   682,  2584,
     608,  1538,  -657,  1538,  -657,  2584,   608,  1538,  -657,  1538,
    -657,   363,   478,   609,   363,   478,   609,   412,   501,   503,
     412,   501,   503,   412,   501,   503,   412,   503,  2494,   352,
    2719,  2246,   718,   682,  2584,   608,  2168,  2791,  2450,  2743,
     993,  2767,   779,  1126,   779,  1126,  1538,  2799,   822,  1538,
    2799,   822,  1470,  1248,  1135,  1470,  1248,  1135,  1470,  1248,
    1135,  1470,  1248,  1135,   363,   478,   609,   363,   478,   609,
     412,   501,   503,   412,   501,   503,   412,   501,   503,   412,
     501,   503,  2494,   352,  2719,  2246,   718,   682,  2584,   608,
    1538,  2799,   822,  1538,  2799,   822,  1470,  1248,  1135,  1470,
    1248,  1135,  1470,  1248,  1135,  1470,  1248,  1135,   515,  2494,
     352,  2719,  2246,   718,   682,  2584,   608,   449,  1538,   411,
    1538,   411,  1470,   513,  1470,   513,  1470,   513,  1470,   513,
    2494,   352,  2719,  2246,   718,   682,  2554,   425,  2524,   684,
    2584,   608,  1538,  -657,  1538,  -657,  -657,  -657,   519,  1230,
     964,  -657,   531,  -657,  -657,  1734,  -657,  2823,  -657,   484,
     484,   484,   484,   484,   828,   902,   828,   902,   505,   533,
     505,   533,   505,   533,  2859,   533,  1803,  1213,  1923,   500,
     500,   828,   902,   828,   902,   505,   533,   505,   533,   505,
     533,   505,   533,  -657,  -657,  -657,  -657,   399,   399,  -657,
     477,   541,   556,     6,  -657,  2795,   241,   494,   520,   560,
       7,  -657,  1333,   239,  -657,   802,   532,  -657,  -657,  1764,
    1764,  1764,  -657,  2165,  2086,   571,  1734,  2165,  -657,  1734,
    -657,  -657,  -657,  -657,  -657,  -657,   241,   568,  -657,  -657,
      15,    15,  -657,  -657,  -657,   565,  -657,   538,  -657,   399,
     539,  -657,  -657,  -657,  1148,   241,  -657,  -657,   578,  -657,
    1595,  -657,  1650,   240,  1734,  1849,   599,  2336,   606,   244,
    2642,   611,   612,   620,   626,  -657,   635,  -657,   636,   584,
    -657,  -657,   241,  -657,  1734,  -657,  1734,   573,    17,  -657,
    -657,  -657,   642,  -657,   652,  -657,  1821,   641,  2102,   675,
    2613,  2165,  2165,  1734,  1734,  2165,  2165,  2165,  2165,  -657,
    -657,  -657,  -657,  2165,  -657,  -657,  -657,  -657,  -657,  -657,
    -657,  -657,   674,   650,  -657,  -657,  -657,  -657,   654,  -657,
    -657,  -657,  -657,  -657,  -657,  -657,  1734,  -657
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     9,   307,   321,   342,   369,   299,     0,     0,
       0,     0,     0,     0,   442,     0,    52,    44,    46,    48,
      36,    33,    34,     0,   438,   439,   440,   441,     0,     0,
     103,   104,     0,     0,     4,    10,     0,     0,    35,    15,
       0,    17,     0,    18,     0,    16,     0,    19,    20,     0,
       0,     0,     0,    96,   280,    95,    97,    98,    99,   100,
     101,   102,   445,   446,     0,   299,   103,   104,     0,   280,
       0,     0,     0,     0,     0,     0,     0,     0,   272,   103,
     277,     0,     0,     0,     0,   105,   106,   308,   322,   259,
       0,     0,     0,   371,   260,   310,     0,     0,     0,   420,
      31,    30,    37,     0,   430,   416,   431,   417,   432,   418,
     433,   419,     0,     0,    68,     0,     0,     0,     0,   434,
     122,   301,   415,     0,     0,   435,   123,     1,     3,     0,
       5,     8,     7,    14,    21,     0,     0,     0,     0,    28,
      29,     0,     0,    12,    13,    11,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   124,     0,     0,     0,     0,
       0,   121,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   436,   421,   437,
       0,    74,     0,   300,     0,   301,   107,   281,   309,   323,
     343,   370,     0,     0,   273,     0,     0,     0,     0,     0,
     310,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   428,
       0,     0,   423,   424,   425,   426,     0,     0,   412,     0,
     443,   444,     0,   413,     0,     0,   286,     0,   285,   303,
       0,     0,   115,   118,   422,     0,   116,   119,     6,   443,
     444,     0,     0,     0,     0,    23,     0,     0,     0,    92,
      91,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,   108,     0,    93,     0,   154,   152,   149,
     150,   159,   157,   158,   136,   134,   135,   141,   139,   140,
     146,   144,   145,   129,   131,   128,   271,   270,   266,   267,
     268,   269,   255,   254,   258,   257,   252,   251,   117,   120,
     230,   229,   236,   235,   233,   232,   162,   161,   165,   164,
     210,   208,   205,   206,   201,   202,   203,   204,   227,   225,
     222,   223,   218,   219,   220,   221,   172,   169,   170,   171,
     186,   183,   184,   185,   179,   176,   177,   178,   193,   190,
     191,   192,   125,   126,     0,   153,   151,   250,   243,   209,
     207,   226,   224,   265,   368,   365,   366,   364,   367,   248,
     241,   198,   380,   215,   387,   249,   242,   200,   199,   217,
     216,   147,   315,   341,   155,   314,   338,   132,   311,   329,
     137,   312,   332,   142,   313,   335,   130,   326,   261,   353,
     350,   351,   349,   352,   244,   237,   228,   318,   234,   320,
     231,   319,   160,   316,   163,   317,   194,   375,   376,   211,
     382,   383,   166,   388,   389,   180,   393,   394,   173,   398,
     399,   187,   403,   404,   148,   340,   339,   156,   337,   336,
     133,   328,   327,   138,   331,   330,   143,   334,   333,   127,
     325,   324,   262,   358,   355,   356,   354,   357,   245,   238,
     195,   378,   377,   212,   385,   384,   167,   391,   390,   181,
     396,   395,   174,   401,   400,   188,   406,   405,     0,   263,
     348,   345,   346,   344,   347,   246,   239,   408,   196,   379,
     213,   386,   168,   392,   182,   397,   175,   402,   189,   407,
     264,   363,   360,   361,   359,   362,   253,   373,   256,   372,
     247,   240,   197,   374,   214,   381,   427,   410,     0,     0,
       0,   302,     0,   274,   275,     0,   278,     0,   308,     0,
       0,     0,     0,     0,   315,   341,   314,   338,   311,   329,
     312,   332,   313,   335,     0,   326,   318,   320,   319,   316,
     317,   340,   339,   337,   336,   328,   327,   331,   330,   334,
     333,   325,   324,    78,   429,    32,    77,     0,    57,    54,
       0,     0,     0,     0,   411,     0,     0,     0,    73,     0,
       0,   287,     0,     0,   112,     0,     0,   304,   113,     0,
       0,     0,    74,     0,     0,    24,     0,     0,   109,     0,
     114,   111,   110,   409,    76,    75,     0,     0,   276,   279,
     315,   314,   311,   312,   313,     0,    58,     0,    55,    59,
      61,   414,    66,    71,     0,     0,    69,   291,     0,   289,
       0,   288,     0,     0,     0,     0,     0,   286,     0,     0,
     285,     0,     0,     0,     0,    45,    25,    26,     0,    51,
      94,    64,     0,    56,     0,    60,     0,     0,     0,    67,
     294,   293,     0,   292,     0,   290,     0,   305,   286,     0,
     285,     0,     0,     0,     0,     0,     0,     0,     0,    27,
      47,    53,    49,     0,    65,    63,    62,    72,    70,   297,
     296,   295,     0,     0,   282,    39,    42,   283,     0,    40,
      43,    38,    41,    50,   298,   306,     0,   284
  };

  const short
   Parser ::yypgoto_[] =
  {
    -657,  -657,   -85,   206,   -16,   111,  -634,  -656,  -657,   413,
    -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,
    -657,  -657,  -657,  -587,  -657,  -657,   631,  -657,   123,   566,
    -657,   579,  -657,  1300,   125,    -7,   653,  1140,  -636,   457,
     424,  1552,  1754,   -61,   -51,    -8,   384,   758,   923,  -657,
    -244,  -657,    -5,   327
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    32,    33,   133,    34,   139,   140,   141,    36,   101,
      37,    38,    39,    40,    41,    42,    43,    44,    45,   752,
      46,   753,    47,   641,   642,    48,   115,   648,   649,    49,
      50,    51,   344,    52,    53,    54,    81,    70,   708,   709,
     185,    71,    72,   121,   311,    58,    91,    92,    96,    62,
     302,    63,   122,    64
  };

  const short
   Parser ::yytable_[] =
  {
      73,    69,    87,    90,    95,   255,   588,   715,    98,    99,
     113,   719,   692,   250,   250,   250,   250,   130,   668,   105,
     107,   109,   111,   250,   712,   714,   250,   186,    97,    98,
     -68,   187,   601,   602,   603,    77,     3,     4,     5,     6,
       7,     8,   721,     9,    78,    98,    98,   309,    10,   669,
     685,   686,   638,   326,    98,   645,    11,   248,    98,    98,
     659,   729,    12,   639,   589,   123,   104,     3,     4,   739,
      98,   660,    82,   310,   266,    87,   270,   100,   114,    83,
     124,   251,   662,   690,   696,   765,   766,   119,   754,   769,
     770,   771,   772,    84,   758,   654,   103,   773,   125,   292,
     658,   293,   725,   294,   106,   295,   640,    14,   308,    79,
      67,    35,   108,   318,   314,   308,   110,   247,   112,    24,
      25,    26,    27,   125,   299,   655,   300,   301,   119,   135,
     655,  -444,   296,    68,   670,   123,    89,    94,   263,   592,
      85,    86,   297,   196,    35,   127,   131,   264,   593,   132,
     124,   197,   198,   308,   349,   352,   355,   358,   361,   364,
     368,    90,    90,    90,   655,   381,   383,   385,   387,   389,
     394,   402,   407,   411,   415,   419,   265,   265,   308,    90,
      90,    90,    90,   136,   435,    90,    90,    90,    90,    90,
      90,   452,   455,   458,   461,   464,    90,   470,    90,   477,
     479,   481,   483,   485,   487,   490,   493,   496,   499,   502,
     505,   508,   511,   514,   517,   520,   524,    90,   531,   534,
     537,   540,   543,   546,   308,   551,    90,    90,    90,    90,
      90,    90,    90,   572,    90,    90,    90,    90,    90,   664,
      35,   306,   586,   134,   137,   142,   308,   249,   306,    35,
     671,   699,   735,   253,   138,   143,   144,   145,   159,   257,
     597,   598,   288,   604,   606,   608,   610,   612,   614,   616,
     617,   618,   619,   620,   621,   623,   625,   627,   629,   631,
     655,   700,   736,   743,   634,   744,   306,   347,   351,   354,
     357,   360,   363,   366,   372,   374,   376,   308,   380,   382,
     384,   386,   388,   390,   398,   406,   410,   414,   418,   289,
     130,   306,   425,   427,   429,   431,   290,   433,   439,   441,
     443,   445,   447,   449,   451,   454,   457,   460,   463,   466,
     468,   474,   476,   478,   480,   482,   484,   486,   489,   492,
     495,   498,   501,   504,   507,   510,   513,   516,   519,   522,
     528,   530,   533,   536,   539,   542,   545,   306,   549,   555,
     558,   560,   562,   564,   566,   568,   570,   576,   578,   580,
     582,   584,   160,   116,   161,   117,   254,   193,   117,   306,
     164,   165,   166,   167,    59,   194,   195,   291,   118,   172,
     304,   118,    74,    59,    88,   422,   423,   327,   160,   324,
     161,   691,   638,   184,    59,   590,   595,     3,     4,     5,
       6,     7,     8,   594,     9,   172,   591,    59,   637,    10,
     186,   160,   232,   161,   187,   113,   125,    11,    59,   184,
     306,   119,   167,    12,   188,    35,   644,    35,   172,  -443,
     303,   656,   189,   190,   646,   313,   237,   238,   239,   240,
     244,   317,   184,   657,   120,   126,   640,    14,   245,   246,
     232,    59,   322,     3,     4,   250,   267,    88,    82,    24,
      25,    26,    27,   647,   299,    83,   300,   301,   661,   191,
      79,    67,   235,   236,   237,   238,   239,   240,     3,    84,
     120,   126,    14,   268,   191,   201,   202,   203,   204,   379,
     269,   663,   666,   120,    24,    25,    26,    27,   667,   299,
     186,   300,   301,    59,    84,   599,   600,   601,   602,   603,
      59,   204,    59,   223,   232,   276,    59,   672,   675,   673,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,   678,    59,   261,   350,   353,   356,   359,
     362,   365,   369,   287,   687,   688,   241,   242,   243,   689,
     244,   694,   395,   403,   408,   412,   416,   420,   245,   246,
     695,   693,   298,   307,   717,   704,   436,   303,   722,   723,
     315,   724,   726,   453,   456,   459,   462,   465,   467,   471,
     730,   680,   681,   682,   683,   684,   488,   491,   494,   497,
     500,   503,   506,   509,   512,   515,   518,   521,   525,   741,
     532,   535,   538,   541,   544,   547,   742,   552,   346,   186,
      14,   745,   746,   187,   643,   573,   220,   221,   222,   223,
     747,   650,    24,    25,    26,    27,   748,   299,   749,   300,
     301,   189,   190,   424,   308,   751,   750,   308,   130,    59,
     757,   710,   710,   710,   759,   605,   607,   609,   611,   613,
     615,   241,   242,   243,   760,   244,   622,   624,   626,   628,
     630,   632,    59,   245,   246,    59,     3,     4,     5,     6,
       7,     8,   763,     9,   289,   764,   774,   192,    10,   548,
     310,   193,   308,   776,   308,   252,    11,   740,    69,   194,
     195,   321,    12,   635,   242,   243,   242,   244,    59,   244,
      59,   307,   775,   677,   305,   245,   246,   245,   246,     3,
       4,     5,     6,     7,     8,   329,     9,   651,   308,   232,
     262,    10,     0,     0,     0,   308,   308,     0,     0,    11,
       0,     0,     0,   234,     0,    12,     0,     0,     0,    79,
      67,   235,   236,   237,   238,   239,   240,   652,    60,     0,
       0,     0,   653,     0,     0,     0,    75,    60,   308,     0,
       0,     0,   191,     0,     0,    35,     0,   306,    60,     0,
     306,     0,     0,     0,   707,   707,   707,     0,   160,     0,
     161,    60,    79,    67,   162,   163,   164,   165,   166,   167,
       0,     0,    60,     0,     0,   172,     3,     4,     5,     6,
       7,     8,     0,     9,   701,   191,     0,     0,    10,   184,
       0,     0,     0,   191,     0,   306,    11,   306,     0,     0,
     738,     0,    12,     0,     0,    60,     0,   218,   219,   220,
     221,   222,   223,     0,   702,   273,   274,   275,   276,     0,
     191,     0,   191,     0,   191,     0,   191,   228,   229,   230,
     231,   306,     0,     0,   191,     0,     0,     0,   306,   306,
     191,     3,     4,     5,     6,     7,     8,   343,     9,    79,
      67,     0,     0,    10,     0,     0,     0,    60,     0,     0,
       0,    11,     0,     0,    60,     0,    60,    12,     0,   191,
      60,   306,     0,     0,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,   650,    60,   284,
     285,   286,   287,    61,     0,     0,   370,     0,     0,   377,
       0,    76,    61,     0,    93,     0,   396,   404,   409,   413,
     417,   421,     0,    61,    79,    67,     0,     0,     0,     0,
     437,     0,     0,   191,     0,     0,    61,     0,     0,     0,
     260,   232,     0,   472,   643,   643,     0,    61,     0,     0,
       0,   233,   303,    59,   676,   234,     0,     0,     0,    59,
     191,     0,   526,   235,   236,   237,   238,   239,   240,     0,
       0,   553,   557,   559,   561,   563,   565,   567,   569,   574,
      61,     0,   160,   647,   161,   191,     0,     0,   162,   163,
     164,   165,   166,   167,     0,     0,   643,     0,     0,   172,
     173,   728,    14,    60,   176,   177,   178,   179,   180,   181,
     182,   183,     0,   184,    24,    25,    26,    27,     0,   299,
       0,   300,   301,    59,    59,    59,    60,    59,    59,    60,
      59,    59,    61,    59,     0,     0,   587,     0,     0,    61,
       0,    61,     0,     0,     0,    61,     0,     0,     0,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    60,    61,    60,     0,     0,     0,    59,    74,
     259,   371,   373,   375,     0,   282,   283,   284,   285,   286,
     287,   397,   405,     0,    14,     0,     0,     0,    59,   698,
      59,     0,   703,     0,     0,   438,    24,    25,    26,    27,
       0,   299,     0,   300,   301,    59,    59,     0,   473,    59,
      59,    59,    59,     0,     0,     0,     0,    59,     0,     0,
      55,   199,   200,   201,   202,   203,   204,   527,     0,    55,
     218,   219,   220,   221,   222,   223,   554,   732,     0,   734,
      55,     0,     0,     0,   575,   577,   579,     0,   583,   585,
       0,     0,     0,    55,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,    55,     9,     0,   727,    61,     0,
      10,     0,     0,   762,     0,     0,     0,     0,    11,     0,
     767,   768,     0,     0,    12,     0,    14,     0,     0,     0,
       0,    61,     0,     0,    61,     0,   305,    55,    24,    25,
      26,    27,     0,   299,     0,   300,   301,     0,   599,   600,
     601,   602,   603,   777,     3,     4,     5,     6,     7,     8,
     277,     9,   279,   117,   280,   281,    10,    61,   232,    61,
       0,    79,    67,     0,    11,     0,     0,     0,   233,     0,
      12,     0,   234,   199,   200,   201,   202,   203,   204,    55,
     235,   236,   237,   238,   239,   240,    55,     0,    55,   210,
     211,     0,    55,     0,     0,     0,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,     0,
      55,     0,   348,     0,     0,     0,     0,    79,    67,    80,
       0,     0,     0,     0,     0,     0,     0,     0,   391,   399,
     102,     0,     0,     0,     0,     0,     0,   426,   428,   430,
     432,     0,     0,   440,     0,     0,   446,     3,     4,     5,
       6,     7,     8,     0,     9,   697,   475,    60,     0,    10,
       0,   131,     0,    60,   132,     0,     0,    11,     0,     0,
       0,     0,     0,    12,     0,   529,     3,     4,     5,     6,
      65,     8,     0,     9,   556,     0,     0,    80,    10,     0,
       0,     0,     0,     0,   581,     0,    11,     0,     0,     0,
       0,     0,    12,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,    55,   157,   158,     0,     0,
      79,    67,     0,     0,     0,     0,     0,    60,    60,    60,
       0,    60,    60,     0,    60,    60,     0,    60,    55,     0,
       0,    55,     0,     0,     0,     0,   323,     0,     0,    66,
      67,     0,   328,     0,     0,     0,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,     0,
     345,     0,    60,    75,    55,     0,    55,   128,   129,     0,
       2,     3,     4,     5,     6,     7,     8,     0,     9,   160,
       0,   161,    60,    10,    60,   162,   163,   164,   165,   166,
     167,    11,     0,     0,     0,     0,   172,    12,     0,    60,
      60,   176,   177,    60,    60,    60,    60,     0,     0,     0,
     184,    60,    61,     0,     0,     0,     0,     0,    61,     0,
       0,     0,     0,     0,    13,    14,    15,    16,     0,    17,
      18,    19,    20,    21,    22,    23,     0,    24,    25,    26,
      27,    28,    29,     0,    30,    31,     0,   160,     0,   161,
       0,     0,    56,   162,   163,   164,   165,   166,   167,     0,
       0,    56,     0,     0,   172,   596,     0,     0,     0,   176,
     177,     0,    56,   180,   181,   182,   183,     0,   184,     0,
       0,     0,    61,    61,    61,    56,    61,    61,   633,    61,
      61,   636,    61,     0,     0,     0,    56,     0,     0,     3,
       4,     5,     6,     7,     8,     0,     9,   731,     0,     0,
       0,    10,   218,   219,   220,   221,   222,   223,   224,    11,
       0,     0,   225,     0,    14,    12,     0,    61,    76,    56,
     226,   227,   228,   229,   230,   231,    24,    25,    26,    27,
       0,   299,     0,   300,   312,     0,     0,    61,     0,    61,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     9,   733,     0,    61,    61,    10,     0,    61,    61,
      61,    61,    79,    67,    11,     0,    61,     0,     0,     0,
      12,    56,     0,     0,     0,     0,     0,     0,    56,     0,
      56,     0,     0,     0,    56,     0,     0,     0,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,     0,    56,     0,     0,     0,     0,     0,     0,     0,
     367,     0,     0,     0,     0,     0,     0,    79,    67,    55,
     392,   400,     0,     0,     0,    55,     0,     0,     3,     4,
       5,     6,     7,     8,   434,     9,   442,   444,     0,     0,
      10,     0,     0,     0,    57,     0,     0,   469,    11,     0,
       0,     0,     0,    57,    12,     0,     0,     0,     3,     4,
       5,     6,     7,   705,    57,     9,   523,     0,     0,     0,
      10,     0,     0,     0,     0,   550,     0,    57,    11,     0,
       0,     0,     0,   571,    12,     0,     0,     0,    57,    55,
      55,    55,     0,    55,    55,     0,    55,    55,     0,    55,
       0,    79,    67,     0,     0,     0,     0,    56,   599,   600,
     601,   602,   603,     0,     0,     3,     4,     5,     6,     7,
       8,    57,     9,   761,   280,   281,     0,    10,     0,     0,
      56,    79,    67,    56,    55,    11,     0,     0,     0,     0,
       0,    12,     0,     3,     4,     5,     6,    65,   705,     0,
       9,     0,     0,     0,    55,    10,    55,     0,     0,     0,
       0,     0,     0,    11,     0,     0,    56,     0,    56,    12,
       0,    55,    55,    57,     0,    55,    55,    55,    55,   674,
      57,     0,    57,    55,     0,   679,    57,     0,    79,    67,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,     1,    57,     0,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,    66,    67,     0,    10,
       0,     0,   393,   401,     0,     0,     0,    11,   599,   600,
     601,   602,   603,    12,     0,     0,     0,     0,     0,     0,
     277,   448,   450,     0,   280,   281,     0,     0,     0,   706,
     711,   713,     0,     0,     0,     0,   718,     0,     0,   720,
      13,    14,    15,    16,     0,    17,    18,    19,    20,    21,
      22,    23,     0,    24,    25,    26,    27,    28,    29,     0,
      30,    31,   129,     0,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,   737,   665,     0,    10,     0,     0,
       0,     0,     0,     0,     0,    11,     0,     0,     0,    57,
       0,    12,   258,     0,   755,     0,   756,   271,   272,   273,
     274,   275,   276,     0,     0,     0,     0,     0,     0,   277,
     278,   279,    57,   280,   281,    57,     0,     0,    13,    14,
      15,    16,     0,    17,    18,    19,    20,    21,    22,    23,
       0,    24,    25,    26,    27,    28,    29,     0,    30,    31,
       0,     0,     0,     0,     0,     0,     0,     0,    57,     0,
      57,     0,     0,     0,     0,     0,     0,   129,     0,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
     716,     0,    10,     0,     0,     0,     0,     0,     0,     0,
      11,   160,   256,   161,     0,     0,    12,   162,   163,   164,
     165,   166,   167,   168,   169,   170,     0,   171,   172,   173,
     174,   175,     0,   176,   177,   178,   179,   180,   181,   182,
     183,    56,   184,    13,    14,    15,    16,    56,    17,    18,
      19,    20,    21,    22,    23,     0,    24,    25,    26,    27,
      28,    29,     0,    30,    31,     0,     0,     0,   137,     3,
       4,     5,     6,     7,     8,     0,     9,   160,   138,   161,
       0,    10,     0,   162,   163,   164,   165,   166,   167,    11,
       0,     0,     0,     0,   172,    12,     0,     0,     0,   176,
     177,   178,   179,   180,   181,   182,   183,     0,   184,     0,
       0,    56,    56,    56,     0,    56,    56,     0,    56,    56,
       0,    56,    13,    14,    15,    16,     0,    17,    18,    19,
      20,    21,    22,    23,     0,    24,    25,    26,    27,    28,
      29,     0,    30,    31,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     0,     9,    56,     0,   325,     0,
      10,   218,   219,   220,   221,   222,   223,     0,    11,     0,
       0,   225,     0,     0,    12,     0,    56,     0,    56,   226,
     227,   228,   229,   230,   231,     0,     0,     0,     0,     0,
       0,     0,     0,    56,    56,     0,     0,    56,    56,    56,
      56,    13,    14,    15,    16,    56,    17,    18,    19,    20,
      21,    22,    23,     0,    24,    25,    26,    27,    28,    29,
      14,    30,    31,     2,     3,     4,     5,     6,     7,     8,
       0,     9,    24,    25,    26,    27,    10,   299,     0,   300,
     316,     0,     0,    57,    11,   160,   -96,   161,     0,    57,
      12,   162,   163,   164,   165,   166,   167,   168,   169,   170,
       0,   171,   172,   173,   174,   175,     0,   176,   177,   178,
     179,   180,   181,   182,   183,     0,   184,    13,    14,    15,
      16,     0,    17,    18,    19,    20,    21,    22,    23,    14,
      24,    25,    26,    27,    28,    29,     0,    30,    31,     0,
       0,    24,    25,    26,    27,     0,   299,     0,   319,   320,
       0,     0,     0,    57,    57,    57,     0,    57,    57,     0,
      57,    57,   160,    57,   161,     0,     0,     0,   162,   163,
     164,   165,   166,   167,   168,   169,   170,     0,   171,   172,
     173,   174,   175,     0,   176,   177,   178,   179,   180,   181,
     182,   183,     0,   184,     0,     0,     0,     0,    57,   160,
       0,   161,     0,     0,     0,   162,   163,   164,   165,   166,
     167,     0,     0,     0,     0,     0,   172,   173,    57,   175,
      57,   176,   177,   178,   179,   180,   181,   182,   183,     0,
     184,     0,     0,     0,     0,    57,    57,     0,     0,    57,
      57,    57,    57,   160,     0,   161,     0,    57,     0,   162,
     163,   164,   165,   166,   167,     0,   169,   170,     0,   171,
     172,   173,   174,   175,     0,   176,   177,   178,   179,   180,
     181,   182,   183,   160,   184,   161,     0,     0,     0,   162,
     163,   164,   165,   166,   167,     0,   169,     0,     0,   171,
     172,   173,   174,   175,     0,   176,   177,   178,   179,   180,
     181,   182,   183,   160,   184,   161,     0,     0,     0,   162,
     163,   164,   165,   166,   167,     0,     0,     0,     0,   171,
     172,   173,   174,   175,     0,   176,   177,   178,   179,   180,
     181,   182,   183,   160,   184,   161,     0,     0,     0,   162,
     163,   164,   165,   166,   167,     0,     0,     0,     0,     0,
     172,   173,   174,   175,     0,   176,   177,   178,   179,   180,
     181,   182,   183,   258,   184,     0,     0,     0,   199,   200,
     201,   202,   203,   204,   205,     0,     0,     0,   206,     0,
     207,   208,   209,     0,   210,   211,   212,   213,   214,   215,
     216,   217,   -99,     0,     0,     0,     0,   199,   200,   201,
     202,   203,   204,   205,     0,     0,     0,   206,     0,   207,
     208,   209,     0,   210,   211,   212,   213,   214,   215,   216,
     217,   259,     0,     0,     0,     0,   218,   219,   220,   221,
     222,   223,   224,     0,     0,     0,   225,     0,     0,     0,
       0,     0,     0,     0,   226,   227,   228,   229,   230,   231,
     199,   200,   201,   202,   203,   204,   205,     0,     0,     0,
     206,     0,   207,   208,   209,     0,   210,   211,   212,   213,
     214,   215,   216,   217,   199,   200,   201,   202,   203,   204,
       0,     0,     0,     0,   206,     0,   207,   208,   209,     0,
     210,   211,   212,   213,   214,   215,   216,   217,   199,   200,
     201,   202,   203,   204,     0,     0,     0,     0,     0,     0,
     207,     0,   209,     0,   210,   211,   212,   213,   214,   215,
     216,   217,   199,   200,   201,   202,   203,   204,     0,     0,
       0,     0,     0,     0,   207,     0,     0,     0,   210,   211,
     212,   213,   214,   215,   216,   217,   199,   200,   201,   202,
     203,   204,     0,     0,   199,   200,   201,   202,   203,   204,
       0,     0,   210,   211,   212,   213,   214,   215,   216,   217,
     210,   211,     0,   258,   214,   215,   216,   217,   599,   600,
     601,   602,   603,     0,    14,     0,     0,     0,     0,     0,
     277,   278,   279,    14,   280,   281,    24,    25,    26,    27,
       0,   299,     0,   300,   378,    24,    25,    26,    27,     0,
     299,     0,   300,   301,   271,   272,   273,   274,   275,   276,
       0,     0,     0,     0,     0,     0,   277,   278,   279,     0,
     280,   281,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,     0,   157,   158
  };

  const short
   Parser ::yycheck_[] =
  {
       8,     8,    10,    11,    12,    66,   250,   663,    11,    14,
       9,   667,   646,     9,     9,     9,     9,    33,    10,    24,
      25,    26,    27,     9,   660,   661,     9,    11,    77,    11,
       9,    15,    17,    18,    19,     3,     4,     5,     6,     7,
       8,     9,   676,    11,    12,    11,    11,    14,    16,    41,
     637,   638,     3,   138,    11,    41,    24,    62,    11,    11,
      42,   695,    30,    14,    43,    11,    69,     4,     5,   705,
      11,    42,     9,    40,    82,    83,    84,    77,    77,    16,
      26,    77,    77,    77,    77,   741,   742,    69,   722,   745,
     746,   747,   748,    30,    77,    12,    77,   753,    69,   104,
      12,   106,   689,   108,    69,   110,    57,    58,   116,    77,
      78,     0,    69,   129,   119,   123,    69,    69,    77,    70,
      71,    72,    73,    69,    75,    42,    77,    78,    69,     9,
      42,    77,     3,     8,    12,    11,    11,    12,     3,     3,
      77,    78,    13,    25,    33,     0,     0,    12,    12,     3,
      26,    33,    34,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    42,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,    41,    41,   186,   187,
     188,   189,   190,     9,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   324,
     129,   116,   247,    37,     3,     9,   254,    69,   123,   138,
      12,    12,    12,    10,    13,    49,    50,    51,    52,    10,
     268,   269,    43,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
      42,    42,    42,    39,   289,    41,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   305,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    12,
     326,   186,   187,   188,   189,   190,    41,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,     9,    11,    11,    13,    11,    25,    13,   254,
      17,    18,    19,    20,     0,    33,    34,    43,    26,    26,
       9,    26,     8,     9,    10,    77,    78,    63,     9,    13,
      11,   645,     3,    40,    20,     9,     3,     4,     5,     6,
       7,     8,     9,    12,    11,    26,    10,    33,    13,    16,
      11,     9,    11,    11,    15,     9,    69,    24,    44,    40,
     305,    69,    20,    30,    25,   324,    10,   326,    26,    77,
     113,    77,    33,    34,    10,   118,    35,    36,    37,    38,
      25,   124,    40,    14,    30,    31,    57,    58,    33,    34,
      11,    77,   135,     4,     5,     9,    82,    83,     9,    70,
      71,    72,    73,    39,    75,    16,    77,    78,    42,    55,
      77,    78,    33,    34,    35,    36,    37,    38,     4,    30,
      66,    67,    58,     9,    70,    17,    18,    19,    20,   172,
      16,    10,     9,    79,    70,    71,    72,    73,    10,    75,
      11,    77,    78,   129,    30,    15,    16,    17,    18,    19,
     136,    20,   138,    20,    11,    20,   142,    12,   589,    10,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    12,   160,    10,   162,   163,   164,   165,
     166,   167,   168,    20,    77,    14,    21,    22,    23,     3,
      25,    41,   178,   179,   180,   181,   182,   183,    33,    34,
      10,    77,    10,   116,     3,    43,   192,   250,    10,    14,
     123,    43,    43,   199,   200,   201,   202,   203,   204,   205,
      12,   599,   600,   601,   602,   603,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    10,
     226,   227,   228,   229,   230,   231,    10,   233,   161,    11,
      58,    10,    10,    15,   297,   241,    17,    18,    19,    20,
      10,   304,    70,    71,    72,    73,    10,    75,     3,    77,
      78,    33,    34,   186,   652,    61,    10,   655,   664,   265,
      77,   659,   660,   661,    12,   271,   272,   273,   274,   275,
     276,    21,    22,    23,    12,    25,   282,   283,   284,   285,
     286,   287,   288,    33,    34,   291,     4,     5,     6,     7,
       8,     9,    41,    11,    12,    10,    12,    21,    16,   232,
      40,    25,   700,    39,   702,    64,    24,   705,   705,    33,
      34,   135,    30,   290,    22,    23,    22,    25,   324,    25,
     326,   254,   763,   590,    42,    33,    34,    33,    34,     4,
       5,     6,     7,     8,     9,   146,    11,    12,   736,    11,
      77,    16,    -1,    -1,    -1,   743,   744,    -1,    -1,    24,
      -1,    -1,    -1,    25,    -1,    30,    -1,    -1,    -1,    77,
      78,    33,    34,    35,    36,    37,    38,    42,     0,    -1,
      -1,    -1,   305,    -1,    -1,    -1,     8,     9,   776,    -1,
      -1,    -1,   348,    -1,    -1,   664,    -1,   652,    20,    -1,
     655,    -1,    -1,    -1,   659,   660,   661,    -1,     9,    -1,
      11,    33,    77,    78,    15,    16,    17,    18,    19,    20,
      -1,    -1,    44,    -1,    -1,    26,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,   391,    -1,    -1,    16,    40,
      -1,    -1,    -1,   399,    -1,   700,    24,   702,    -1,    -1,
     705,    -1,    30,    -1,    -1,    77,    -1,    15,    16,    17,
      18,    19,    20,    -1,    42,    17,    18,    19,    20,    -1,
     426,    -1,   428,    -1,   430,    -1,   432,    35,    36,    37,
      38,   736,    -1,    -1,   440,    -1,    -1,    -1,   743,   744,
     446,     4,     5,     6,     7,     8,     9,    10,    11,    77,
      78,    -1,    -1,    16,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    24,    -1,    -1,   136,    -1,   138,    30,    -1,   475,
     142,   776,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   590,   160,    17,
      18,    19,    20,     0,    -1,    -1,   168,    -1,    -1,   171,
      -1,     8,     9,    -1,    11,    -1,   178,   179,   180,   181,
     182,   183,    -1,    20,    77,    78,    -1,    -1,    -1,    -1,
     192,    -1,    -1,   529,    -1,    -1,    33,    -1,    -1,    -1,
      10,    11,    -1,   205,   637,   638,    -1,    44,    -1,    -1,
      -1,    21,   645,   589,    10,    25,    -1,    -1,    -1,   595,
     556,    -1,   224,    33,    34,    35,    36,    37,    38,    -1,
      -1,   233,   234,   235,   236,   237,   238,   239,   240,   241,
      77,    -1,     9,    39,    11,   581,    -1,    -1,    15,    16,
      17,    18,    19,    20,    -1,    -1,   689,    -1,    -1,    26,
      27,   694,    58,   265,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    40,    70,    71,    72,    73,    -1,    75,
      -1,    77,    78,   659,   660,   661,   288,   663,   664,   291,
     666,   667,   129,   669,    -1,    -1,    10,    -1,    -1,   136,
      -1,   138,    -1,    -1,    -1,   142,    -1,    -1,    -1,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   324,   160,   326,    -1,    -1,    -1,   704,   705,
      10,   168,   169,   170,    -1,    15,    16,    17,    18,    19,
      20,   178,   179,    -1,    58,    -1,    -1,    -1,   724,   652,
     726,    -1,   655,    -1,    -1,   192,    70,    71,    72,    73,
      -1,    75,    -1,    77,    78,   741,   742,    -1,   205,   745,
     746,   747,   748,    -1,    -1,    -1,    -1,   753,    -1,    -1,
       0,    15,    16,    17,    18,    19,    20,   224,    -1,     9,
      15,    16,    17,    18,    19,    20,   233,   700,    -1,   702,
      20,    -1,    -1,    -1,   241,   242,   243,    -1,   245,   246,
      -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,     4,     5,
       6,     7,     8,     9,    44,    11,    -1,    39,   265,    -1,
      16,    -1,    -1,   736,    -1,    -1,    -1,    -1,    24,    -1,
     743,   744,    -1,    -1,    30,    -1,    58,    -1,    -1,    -1,
      -1,   288,    -1,    -1,   291,    -1,    42,    77,    70,    71,
      72,    73,    -1,    75,    -1,    77,    78,    -1,    15,    16,
      17,    18,    19,   776,     4,     5,     6,     7,     8,     9,
      27,    11,    29,    13,    31,    32,    16,   324,    11,   326,
      -1,    77,    78,    -1,    24,    -1,    -1,    -1,    21,    -1,
      30,    -1,    25,    15,    16,    17,    18,    19,    20,   129,
      33,    34,    35,    36,    37,    38,   136,    -1,   138,    31,
      32,    -1,   142,    -1,    -1,    -1,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
     160,    -1,   162,    -1,    -1,    -1,    -1,    77,    78,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,   179,
      20,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,   193,    -1,    -1,   196,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,   206,   589,    -1,    16,
      -1,     0,    -1,   595,     3,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    30,    -1,   225,     4,     5,     6,     7,
       8,     9,    -1,    11,   234,    -1,    -1,    77,    16,    -1,
      -1,    -1,    -1,    -1,   244,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,   265,    55,    56,    -1,    -1,
      77,    78,    -1,    -1,    -1,    -1,    -1,   659,   660,   661,
      -1,   663,   664,    -1,   666,   667,    -1,   669,   288,    -1,
      -1,   291,    -1,    -1,    -1,    -1,   136,    -1,    -1,    77,
      78,    -1,   142,    -1,    -1,    -1,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
     160,    -1,   704,   705,   324,    -1,   326,     0,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,     9,
      -1,    11,   724,    16,   726,    15,    16,    17,    18,    19,
      20,    24,    -1,    -1,    -1,    -1,    26,    30,    -1,   741,
     742,    31,    32,   745,   746,   747,   748,    -1,    -1,    -1,
      40,   753,   589,    -1,    -1,    -1,    -1,    -1,   595,    -1,
      -1,    -1,    -1,    -1,    57,    58,    59,    60,    -1,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    -1,    77,    78,    -1,     9,    -1,    11,
      -1,    -1,     0,    15,    16,    17,    18,    19,    20,    -1,
      -1,     9,    -1,    -1,    26,   265,    -1,    -1,    -1,    31,
      32,    -1,    20,    35,    36,    37,    38,    -1,    40,    -1,
      -1,    -1,   659,   660,   661,    33,   663,   664,   288,   666,
     667,   291,   669,    -1,    -1,    -1,    44,    -1,    -1,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    -1,    -1,
      -1,    16,    15,    16,    17,    18,    19,    20,    21,    24,
      -1,    -1,    25,    -1,    58,    30,    -1,   704,   705,    77,
      33,    34,    35,    36,    37,    38,    70,    71,    72,    73,
      -1,    75,    -1,    77,    78,    -1,    -1,   724,    -1,   726,
      -1,    -1,    -1,    -1,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,   741,   742,    16,    -1,   745,   746,
     747,   748,    77,    78,    24,    -1,   753,    -1,    -1,    -1,
      30,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,
     138,    -1,    -1,    -1,   142,    -1,    -1,    -1,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     168,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,   589,
     178,   179,    -1,    -1,    -1,   595,    -1,    -1,     4,     5,
       6,     7,     8,     9,   192,    11,   194,   195,    -1,    -1,
      16,    -1,    -1,    -1,     0,    -1,    -1,   205,    24,    -1,
      -1,    -1,    -1,     9,    30,    -1,    -1,    -1,     4,     5,
       6,     7,     8,     9,    20,    11,   224,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    -1,   233,    -1,    33,    24,    -1,
      -1,    -1,    -1,   241,    30,    -1,    -1,    -1,    44,   659,
     660,   661,    -1,   663,   664,    -1,   666,   667,    -1,   669,
      -1,    77,    78,    -1,    -1,    -1,    -1,   265,    15,    16,
      17,    18,    19,    -1,    -1,     4,     5,     6,     7,     8,
       9,    77,    11,    12,    31,    32,    -1,    16,    -1,    -1,
     288,    77,    78,   291,   704,    24,    -1,    -1,    -1,    -1,
      -1,    30,    -1,     4,     5,     6,     7,     8,     9,    -1,
      11,    -1,    -1,    -1,   724,    16,   726,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,   324,    -1,   326,    30,
      -1,   741,   742,   129,    -1,   745,   746,   747,   748,   589,
     136,    -1,   138,   753,    -1,   595,   142,    -1,    77,    78,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,     0,   160,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    77,    78,    -1,    16,
      -1,    -1,   178,   179,    -1,    -1,    -1,    24,    15,    16,
      17,    18,    19,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      27,   197,   198,    -1,    31,    32,    -1,    -1,    -1,   659,
     660,   661,    -1,    -1,    -1,    -1,   666,    -1,    -1,   669,
      57,    58,    59,    60,    -1,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    -1,
      77,    78,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    -1,   704,    14,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,   265,
      -1,    30,    10,    -1,   724,    -1,   726,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    29,   288,    31,    32,   291,    -1,    -1,    57,    58,
      59,    60,    -1,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    -1,    77,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,    -1,
     326,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    -1,    -1,
      14,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,     9,    10,    11,    -1,    -1,    30,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    25,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,   589,    40,    57,    58,    59,    60,   595,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    -1,    77,    78,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,     9,    13,    11,
      -1,    16,    -1,    15,    16,    17,    18,    19,    20,    24,
      -1,    -1,    -1,    -1,    26,    30,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    40,    -1,
      -1,   659,   660,   661,    -1,   663,   664,    -1,   666,   667,
      -1,   669,    57,    58,    59,    60,    -1,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    -1,    77,    78,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,   704,    -1,    14,    -1,
      16,    15,    16,    17,    18,    19,    20,    -1,    24,    -1,
      -1,    25,    -1,    -1,    30,    -1,   724,    -1,   726,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   741,   742,    -1,    -1,   745,   746,   747,
     748,    57,    58,    59,    60,   753,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      58,    77,    78,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    70,    71,    72,    73,    16,    75,    -1,    77,
      78,    -1,    -1,   589,    24,     9,    10,    11,    -1,   595,
      30,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    40,    57,    58,    59,
      60,    -1,    62,    63,    64,    65,    66,    67,    68,    58,
      70,    71,    72,    73,    74,    75,    -1,    77,    78,    -1,
      -1,    70,    71,    72,    73,    -1,    75,    -1,    77,    78,
      -1,    -1,    -1,   659,   660,   661,    -1,   663,   664,    -1,
     666,   667,     9,   669,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    40,    -1,    -1,    -1,    -1,   704,     9,
      -1,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    26,    27,   724,    29,
     726,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      40,    -1,    -1,    -1,    -1,   741,   742,    -1,    -1,   745,
     746,   747,   748,     9,    -1,    11,    -1,   753,    -1,    15,
      16,    17,    18,    19,    20,    -1,    22,    23,    -1,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,     9,    40,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    -1,    22,    -1,    -1,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,     9,    40,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,     9,    40,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    10,    40,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    25,    -1,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    10,    -1,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    25,    -1,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    10,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      25,    -1,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    25,    -1,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    -1,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    15,    16,    17,    18,
      19,    20,    -1,    -1,    15,    16,    17,    18,    19,    20,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      31,    32,    -1,    10,    35,    36,    37,    38,    15,    16,
      17,    18,    19,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    58,    31,    32,    70,    71,    72,    73,
      -1,    75,    -1,    77,    78,    70,    71,    72,    73,    -1,
      75,    -1,    77,    78,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,
      31,    32,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56
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
     133,    12,    42,   119,    12,    42,    77,    14,    12,    42,
      42,    42,    77,    10,    82,    14,     9,    10,    10,    41,
      12,    12,    12,    10,   113,   123,    10,   108,    12,   113,
     125,   125,   125,   125,   125,   103,   103,    77,    14,     3,
      77,   130,    86,    77,    41,    10,    77,    12,   119,    12,
      42,    12,    42,   119,    43,     9,   113,   114,   118,   119,
     125,   113,   118,   113,   118,    87,    14,     3,   113,    87,
     113,    86,    10,    14,    43,   103,    43,    39,   133,    86,
      12,    12,   119,    12,   119,    12,    42,   113,   114,   118,
     125,    10,    10,    39,    41,    10,    10,    10,    10,     3,
      10,    61,    99,   101,    86,   113,   113,    77,    77,    12,
      12,    12,   119,    41,    10,    87,    87,   119,   119,    87,
      87,    87,    87,    87,    12,   124,    39,   119
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
     114,   114,   115,   115,   115,   115,   115,   116,   116,   116,
     117,   117,   118,   118,   118,   119,   119,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   121,
     121,   122,   122,   123,   123,   124,   124,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   129,
     129,   129,   129,   130,   130,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   132,   132,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133
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
       4,     4,     4,     4,     4,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     2,     3,     3,     3,     3,     3,
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
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     4,     4,     5,     1,     3,     4,
       1,     3,     3,     3,     5,     1,     1,     3,     4,     4,
       5,     4,     5,     5,     5,     6,     6,     6,     7,     1,
       3,     2,     4,     2,     3,     4,     6,     1,     2,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       3,     4,     3,     1,     3,     2,     2,     2,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     2,     3,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1
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
     413,   415,   416,   417,   418,   420,   421,   424,   425,   426,
     427,   428,   430,   431,   432,   433,   434,   436,   437,   438,
     439,   440,   442,   443,   444,   445,   446,   448,   449,   450,
     451,   452,   453,   454,   455,   457,   458,   459,   460,   461,
     463,   464,   465,   467,   468,   469,   471,   472,   473,   474,
     475,   476,   477,   479,   480,   481,   482,   483,   484,   485,
     487,   488,   489,   490,   491,   492,   493,   495,   496,   497,
     498,   499,   500,   501,   503,   504,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   539,   540,
     541,   543,   544,   545,   547,   548,   549,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   568,   569,   570,   572,   573,   574,   576,
     578,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   594,   595,   596,   597,   598,   601,   602,   603,
     607,   608,   610,   611,   612,   614,   615,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   628,   632,
     633,   637,   638,   640,   641,   643,   644,   648,   649,   650,
     651,   652,   653,   654,   655,   656,   657,   658,   659,   660,
     661,   665,   666,   667,   668,   669,   670,   671,   672,   673,
     674,   675,   676,   677,   678,   679,   680,   681,   682,   683,
     684,   685,   689,   690,   691,   692,   693,   694,   695,   696,
     697,   698,   699,   700,   701,   702,   703,   704,   705,   706,
     707,   708,   709,   710,   711,   712,   713,   714,   715,   719,
     720,   721,   722,   723,   725,   726,   727,   728,   729,   730,
     731,   733,   734,   735,   736,   737,   738,   739,   741,   742,
     743,   744,   745,   747,   748,   749,   750,   751,   753,   754,
     755,   756,   757,   759,   760,   761,   762,   763,   765,   769,
     770,   771,   772,   774,   775,   779,   780,   781,   782,   783,
     784,   785,   786,   787,   788,   789,   790,   791,   793,   795,
     800,   801,   802,   803,   804,   805,   806,   807,   808,   809,
     810,   811,   812,   813,   814,   815,   816
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
#line 4939 "frontend/parser.cpp"

#line 819 "frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    auto msg = std::to_string(scanner->llvmloc->begin.line) + ":" + std::to_string(scanner->llvmloc->begin.column) + ": " + err_message;
    scanner->fatal_error(ptc::diag::ERR_SYNTAX, msg);
}
