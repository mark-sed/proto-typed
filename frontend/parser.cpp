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
#line 230 "frontend/parser.yy"
                        { scanner->parseEntry(std::vector<ptc::ir::IR *>{}); }
#line 1175 "frontend/parser.cpp"
    break;

  case 3: // start: stmt "end of file"
#line 231 "frontend/parser.yy"
                        { scanner->parseEntry(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1181 "frontend/parser.cpp"
    break;

  case 4: // stmt: stmts
#line 233 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1187 "frontend/parser.cpp"
    break;

  case 5: // stmt: stmt stmts
#line 234 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1193 "frontend/parser.cpp"
    break;

  case 6: // stmt: stmt error stmts
#line 235 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1199 "frontend/parser.cpp"
    break;

  case 9: // stmts: "terminator (\\n or ;)"
#line 242 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = nullptr; }
#line 1205 "frontend/parser.cpp"
    break;

  case 10: // stmts: stmts_ne
#line 243 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1211 "frontend/parser.cpp"
    break;

  case 11: // stmts_ne: set stmt_end
#line 245 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1217 "frontend/parser.cpp"
    break;

  case 12: // stmts_ne: vardecl stmt_end
#line 246 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1223 "frontend/parser.cpp"
    break;

  case 13: // stmts_ne: vardef stmt_end
#line 247 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1229 "frontend/parser.cpp"
    break;

  case 14: // stmts_ne: import stmt_end
#line 248 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1235 "frontend/parser.cpp"
    break;

  case 15: // stmts_ne: for
#line 249 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1241 "frontend/parser.cpp"
    break;

  case 16: // stmts_ne: if
#line 250 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1247 "frontend/parser.cpp"
    break;

  case 17: // stmts_ne: while
#line 251 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1253 "frontend/parser.cpp"
    break;

  case 18: // stmts_ne: dowhile
#line 252 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1259 "frontend/parser.cpp"
    break;

  case 19: // stmts_ne: struct
#line 253 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1265 "frontend/parser.cpp"
    break;

  case 20: // stmts_ne: function
#line 254 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1271 "frontend/parser.cpp"
    break;

  case 21: // stmts_ne: flowctl stmt_end
#line 255 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1277 "frontend/parser.cpp"
    break;

  case 22: // stmts_ne: expr stmt_end
#line 256 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1283 "frontend/parser.cpp"
    break;

  case 23: // block: "{" "}"
#line 260 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1289 "frontend/parser.cpp"
    break;

  case 24: // block: "{" stmt "}"
#line 261 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1295 "frontend/parser.cpp"
    break;

  case 25: // block: "terminator (\\n or ;)" "{" stmt "}"
#line 262 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1301 "frontend/parser.cpp"
    break;

  case 26: // block: "{" stmt "}" "terminator (\\n or ;)"
#line 263 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1307 "frontend/parser.cpp"
    break;

  case 27: // block: "terminator (\\n or ;)" "{" stmt "}" "terminator (\\n or ;)"
#line 264 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1313 "frontend/parser.cpp"
    break;

  case 28: // scope_body: stmts_ne
#line 267 "frontend/parser.yy"
                      { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); scanner->leaveScope(); }
#line 1319 "frontend/parser.cpp"
    break;

  case 29: // scope_body: block
#line 268 "frontend/parser.yy"
                      { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); scanner->leaveScope(); }
#line 1325 "frontend/parser.cpp"
    break;

  case 30: // import: "import" id_list
#line 272 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::IR * > () = scanner->parseImports(yystack_[0].value.as < std::vector<std::string>  > ()); }
#line 1331 "frontend/parser.cpp"
    break;

  case 31: // id_list: "identifier"
#line 274 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseImportName(yystack_[0].value.as < std::string > ()); }
#line 1337 "frontend/parser.cpp"
    break;

  case 32: // id_list: "identifier" "," id_list
#line 275 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseAddImportName(yystack_[0].value.as < std::vector<std::string>  > (), yystack_[2].value.as < std::string > ()); }
#line 1343 "frontend/parser.cpp"
    break;

  case 33: // flowctl: "break"
#line 279 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseBreak(); }
#line 1349 "frontend/parser.cpp"
    break;

  case 34: // flowctl: "continue"
#line 280 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseContinue(); }
#line 1355 "frontend/parser.cpp"
    break;

  case 35: // flowctl: return
#line 281 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1361 "frontend/parser.cpp"
    break;

  case 36: // return: "return"
#line 283 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(nullptr); }
#line 1367 "frontend/parser.cpp"
    break;

  case 37: // return: "return" expr
#line 284 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1373 "frontend/parser.cpp"
    break;

  case 38: // for: for_kw "(" vardecl ":" expr ")" scope_body
#line 288 "frontend/parser.yy"
                                                      { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1379 "frontend/parser.cpp"
    break;

  case 39: // for: for_kw "(" "identifier" ":" expr ")" scope_body
#line 289 "frontend/parser.yy"
                                                      { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1385 "frontend/parser.cpp"
    break;

  case 40: // for: for_kw "(" "external identifier" ":" expr ")" scope_body
#line 290 "frontend/parser.yy"
                                                      { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1391 "frontend/parser.cpp"
    break;

  case 41: // for: for_kw "(" vardecl ":" range ")" scope_body
#line 291 "frontend/parser.yy"
                                                      { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1397 "frontend/parser.cpp"
    break;

  case 42: // for: for_kw "(" "identifier" ":" range ")" scope_body
#line 292 "frontend/parser.yy"
                                                      { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1403 "frontend/parser.cpp"
    break;

  case 43: // for: for_kw "(" "external identifier" ":" range ")" scope_body
#line 293 "frontend/parser.yy"
                                                      { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1409 "frontend/parser.cpp"
    break;

  case 44: // for_kw: "for"
#line 295 "frontend/parser.yy"
               { scanner->enterBlockScope(); }
#line 1415 "frontend/parser.cpp"
    break;

  case 45: // while: wh_kw "(" expr ")" scope_body
#line 298 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseWhile(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1421 "frontend/parser.cpp"
    break;

  case 46: // wh_kw: "while"
#line 300 "frontend/parser.yy"
                { scanner->enterBlockScope(); }
#line 1427 "frontend/parser.cpp"
    break;

  case 47: // dowhile: do_kw scope_body "while" "(" expr ")"
#line 302 "frontend/parser.yy"
                                                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseDoWhile(yystack_[1].value.as < ptc::ir::Expr * > (), yystack_[4].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1433 "frontend/parser.cpp"
    break;

  case 48: // do_kw: "do"
#line 304 "frontend/parser.yy"
             { scanner->enterBlockScope(); }
#line 1439 "frontend/parser.cpp"
    break;

  case 49: // if: if_kw "(" expr ")" scope_body else
#line 307 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseIfStmt(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1445 "frontend/parser.cpp"
    break;

  case 50: // else: el_kw scope_body
#line 309 "frontend/parser.yy"
                         { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1451 "frontend/parser.cpp"
    break;

  case 51: // else: %empty
#line 310 "frontend/parser.yy"
                         { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1457 "frontend/parser.cpp"
    break;

  case 52: // if_kw: "if"
#line 312 "frontend/parser.yy"
             { scanner->enterBlockScope(); }
#line 1463 "frontend/parser.cpp"
    break;

  case 53: // el_kw: "else"
#line 313 "frontend/parser.yy"
               { scanner->enterBlockScope(); }
#line 1469 "frontend/parser.cpp"
    break;

  case 54: // struct: "'struct'" "identifier" "{" "}"
#line 316 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[2].value.as < std::string > (), std::vector<ptc::ir::IR *>{}); }
#line 1475 "frontend/parser.cpp"
    break;

  case 55: // struct: "'struct'" "identifier" "{" decllist "}"
#line 317 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1481 "frontend/parser.cpp"
    break;

  case 56: // struct: "'struct'" "identifier" "terminator (\\n or ;)" "{" decllist "}"
#line 318 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[4].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1487 "frontend/parser.cpp"
    break;

  case 58: // decllist: "terminator (\\n or ;)" decllist
#line 321 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1493 "frontend/parser.cpp"
    break;

  case 59: // decllist: declistval "terminator (\\n or ;)"
#line 322 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[1].value.as < ptc::ir::IR * > (), std::vector<ptc::ir::IR *>{}); }
#line 1499 "frontend/parser.cpp"
    break;

  case 60: // decllist: declistval "terminator (\\n or ;)" decllist
#line 323 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[2].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1505 "frontend/parser.cpp"
    break;

  case 61: // declistval: type "identifier"
#line 325 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > (), nullptr); }
#line 1511 "frontend/parser.cpp"
    break;

  case 62: // declistval: type "identifier" "=" expr
#line 326 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1517 "frontend/parser.cpp"
    break;

  case 64: // function: type fun_id "(" ")" block
#line 331 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1523 "frontend/parser.cpp"
    break;

  case 65: // function: type fun_id "(" funargs ")" block
#line 332 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[5].value.as < ptc::ir::IR * > (), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1529 "frontend/parser.cpp"
    break;

  case 66: // function: "'void'" fun_id "(" ")" block
#line 333 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1535 "frontend/parser.cpp"
    break;

  case 67: // function: "'void'" fun_id "(" funargs ")" block
#line 334 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1541 "frontend/parser.cpp"
    break;

  case 68: // fun_id: "identifier"
#line 336 "frontend/parser.yy"
            { scanner->enterFunScope(); yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1547 "frontend/parser.cpp"
    break;

  case 69: // funargsnvar: type "identifier"
#line 338 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseFunParam(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1553 "frontend/parser.cpp"
    break;

  case 70: // funargsnvar: funargsnvar "," type "identifier"
#line 339 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseAddFunParam(yystack_[3].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1559 "frontend/parser.cpp"
    break;

  case 71: // funargs: ".." "identifier"
#line 341 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseFunParam(scanner->sym_lookup(VARARGS_CSTR, false, true), yystack_[0].value.as < std::string > ()); }
#line 1565 "frontend/parser.cpp"
    break;

  case 72: // funargs: funargsnvar "," ".." "identifier"
#line 342 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseAddFunParam(yystack_[3].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), scanner->sym_lookup(VARARGS_CSTR, false, true), yystack_[0].value.as < std::string > ());}
#line 1571 "frontend/parser.cpp"
    break;

  case 73: // funargs: funargsnvar
#line 343 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = yystack_[0].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (); }
#line 1577 "frontend/parser.cpp"
    break;

  case 74: // vardecl: type "identifier"
#line 348 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1583 "frontend/parser.cpp"
    break;

  case 75: // vardef: type "identifier" "=" struct_val
#line 352 "frontend/parser.yy"
         { yylhs.value.as < ptc::ir::IR * > () = yystack_[3].value.as < ptc::ir::IR * > (); }
#line 1589 "frontend/parser.cpp"
    break;

  case 76: // vardef: type "identifier" "=" expr
#line 353 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1595 "frontend/parser.cpp"
    break;

  case 79: // set: expr "++=" expr
#line 359 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1601 "frontend/parser.cpp"
    break;

  case 80: // set: expr "**=" expr
#line 360 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1607 "frontend/parser.cpp"
    break;

  case 81: // set: expr "%=" expr
#line 361 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1613 "frontend/parser.cpp"
    break;

  case 82: // set: expr "/=" expr
#line 362 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1619 "frontend/parser.cpp"
    break;

  case 83: // set: expr "*=" expr
#line 363 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1625 "frontend/parser.cpp"
    break;

  case 84: // set: expr "-=" expr
#line 364 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1631 "frontend/parser.cpp"
    break;

  case 85: // set: expr "+=" expr
#line 365 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1637 "frontend/parser.cpp"
    break;

  case 86: // set: expr "&=" expr
#line 366 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1643 "frontend/parser.cpp"
    break;

  case 87: // set: expr "|=" expr
#line 367 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1649 "frontend/parser.cpp"
    break;

  case 88: // set: expr "^=" expr
#line 368 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1655 "frontend/parser.cpp"
    break;

  case 89: // set: expr "<<=" expr
#line 369 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1661 "frontend/parser.cpp"
    break;

  case 90: // set: expr ">>=" expr
#line 370 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1667 "frontend/parser.cpp"
    break;

  case 91: // set: expr "=" expr
#line 371 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1673 "frontend/parser.cpp"
    break;

  case 92: // set: expr "=" set
#line 372 "frontend/parser.yy"
      { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1679 "frontend/parser.cpp"
    break;

  case 93: // callarglist: expr
#line 376 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseFunCallArg(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1685 "frontend/parser.cpp"
    break;

  case 94: // callarglist: callarglist "," expr
#line 377 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddFunCallArg(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1691 "frontend/parser.cpp"
    break;

  case 95: // expr: expr_mat
#line 381 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1697 "frontend/parser.cpp"
    break;

  case 96: // expr: expr_var
#line 382 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1703 "frontend/parser.cpp"
    break;

  case 97: // expr: expr_none
#line 383 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1709 "frontend/parser.cpp"
    break;

  case 99: // expr: expr_int
#line 385 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 1715 "frontend/parser.cpp"
    break;

  case 100: // expr: expr_float
#line 386 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFloat(yystack_[0].value.as < double > ()); }
#line 1721 "frontend/parser.cpp"
    break;

  case 101: // expr: expr_str
#line 387 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseString(yystack_[0].value.as < std::string > ()); }
#line 1727 "frontend/parser.cpp"
    break;

  case 102: // expr: expr_bool
#line 388 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseBool(yystack_[0].value.as < bool > ()); }
#line 1733 "frontend/parser.cpp"
    break;

  case 103: // expr_var: "identifier"
#line 391 "frontend/parser.yy"
              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > ()); }
#line 1739 "frontend/parser.cpp"
    break;

  case 104: // expr_var: "external identifier"
#line 392 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > (), true); }
#line 1745 "frontend/parser.cpp"
    break;

  case 105: // expr_var: "-" "identifier"
#line 393 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1751 "frontend/parser.cpp"
    break;

  case 106: // expr_var: "-" "external identifier"
#line 394 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > (), true), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1757 "frontend/parser.cpp"
    break;

  case 107: // expr_var: "(" expr_var ")"
#line 395 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1763 "frontend/parser.cpp"
    break;

  case 108: // expr_var: expr_var "(" ")"
#line 397 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[2].value.as < ptc::ir::Expr * > (), std::vector<ptc::ir::Expr *>{}); }
#line 1769 "frontend/parser.cpp"
    break;

  case 109: // expr_var: expr_var "(" callarglist ")"
#line 398 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 1775 "frontend/parser.cpp"
    break;

  case 110: // expr_var: expr_str "[" int_val "]"
#line 400 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1781 "frontend/parser.cpp"
    break;

  case 111: // expr_var: expr_mat "[" int_val "]"
#line 401 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1787 "frontend/parser.cpp"
    break;

  case 112: // expr_var: "identifier" "[" int_val "]"
#line 402 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1793 "frontend/parser.cpp"
    break;

  case 113: // expr_var: "external identifier" "[" int_val "]"
#line 403 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1799 "frontend/parser.cpp"
    break;

  case 114: // expr_var: expr_var "[" int_val "]"
#line 404 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1805 "frontend/parser.cpp"
    break;

  case 115: // expr_var: expr_mat slice
#line 406 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1811 "frontend/parser.cpp"
    break;

  case 118: // expr_var: expr_var slice
#line 409 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1817 "frontend/parser.cpp"
    break;

  case 119: // expr_var: expr_var "." "identifier"
#line 411 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1823 "frontend/parser.cpp"
    break;

  case 120: // expr_var: expr_var "." "external identifier"
#line 412 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1829 "frontend/parser.cpp"
    break;

  case 121: // expr_var: expr_float "**" expr_var
#line 415 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1835 "frontend/parser.cpp"
    break;

  case 122: // expr_var: expr_var "**" expr_float
#line 416 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1841 "frontend/parser.cpp"
    break;

  case 123: // expr_var: expr_var "**" expr_var
#line 417 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1847 "frontend/parser.cpp"
    break;

  case 124: // expr_var: expr_int "**" expr_var
#line 418 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < long > ()) /*Float on purpose*/, yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1853 "frontend/parser.cpp"
    break;

  case 125: // expr_var: expr_var "**" expr_int
#line 419 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < long > ()) /*Float on purpose*/, ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1859 "frontend/parser.cpp"
    break;

  case 126: // expr_var: expr_int "*" expr_var
#line 421 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1865 "frontend/parser.cpp"
    break;

  case 127: // expr_var: expr_float "*" expr_var
#line 422 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1871 "frontend/parser.cpp"
    break;

  case 128: // expr_var: expr_var "*" expr_int
#line 423 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1877 "frontend/parser.cpp"
    break;

  case 129: // expr_var: expr_var "*" expr_float
#line 424 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1883 "frontend/parser.cpp"
    break;

  case 130: // expr_var: expr_var "*" expr_var
#line 425 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1889 "frontend/parser.cpp"
    break;

  case 131: // expr_var: expr_int "/" expr_var
#line 427 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1895 "frontend/parser.cpp"
    break;

  case 132: // expr_var: expr_float "/" expr_var
#line 428 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1901 "frontend/parser.cpp"
    break;

  case 133: // expr_var: expr_var "/" expr_int
#line 429 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1907 "frontend/parser.cpp"
    break;

  case 134: // expr_var: expr_var "/" expr_float
#line 430 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1913 "frontend/parser.cpp"
    break;

  case 135: // expr_var: expr_var "/" expr_var
#line 431 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1919 "frontend/parser.cpp"
    break;

  case 136: // expr_var: expr_int "%" expr_var
#line 433 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1925 "frontend/parser.cpp"
    break;

  case 137: // expr_var: expr_float "%" expr_var
#line 434 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1931 "frontend/parser.cpp"
    break;

  case 138: // expr_var: expr_var "%" expr_int
#line 435 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1937 "frontend/parser.cpp"
    break;

  case 139: // expr_var: expr_var "%" expr_float
#line 436 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1943 "frontend/parser.cpp"
    break;

  case 140: // expr_var: expr_var "%" expr_var
#line 437 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1949 "frontend/parser.cpp"
    break;

  case 141: // expr_var: expr_int "+" expr_var
#line 439 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1955 "frontend/parser.cpp"
    break;

  case 142: // expr_var: expr_float "+" expr_var
#line 440 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1961 "frontend/parser.cpp"
    break;

  case 143: // expr_var: expr_var "+" expr_int
#line 441 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1967 "frontend/parser.cpp"
    break;

  case 144: // expr_var: expr_var "+" expr_float
#line 442 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1973 "frontend/parser.cpp"
    break;

  case 145: // expr_var: expr_mat "+" expr_mat
#line 443 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1979 "frontend/parser.cpp"
    break;

  case 146: // expr_var: expr_var "+" expr_mat
#line 444 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1985 "frontend/parser.cpp"
    break;

  case 147: // expr_var: expr_mat "+" expr_var
#line 445 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1991 "frontend/parser.cpp"
    break;

  case 148: // expr_var: expr_var "+" expr_var
#line 446 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1997 "frontend/parser.cpp"
    break;

  case 149: // expr_var: expr_int "-" expr_var
#line 448 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2003 "frontend/parser.cpp"
    break;

  case 150: // expr_var: expr_float "-" expr_var
#line 449 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2009 "frontend/parser.cpp"
    break;

  case 151: // expr_var: expr_var "-" expr_int
#line 450 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2015 "frontend/parser.cpp"
    break;

  case 152: // expr_var: expr_var "-" expr_float
#line 451 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2021 "frontend/parser.cpp"
    break;

  case 153: // expr_var: expr_var "-" expr_var
#line 452 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2027 "frontend/parser.cpp"
    break;

  case 154: // expr_var: expr_int "<<" expr_var
#line 454 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2033 "frontend/parser.cpp"
    break;

  case 155: // expr_var: expr_var "<<" expr_int
#line 455 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2039 "frontend/parser.cpp"
    break;

  case 156: // expr_var: expr_var "<<" expr_var
#line 456 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2045 "frontend/parser.cpp"
    break;

  case 157: // expr_var: expr_int ">>" expr_var
#line 458 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2051 "frontend/parser.cpp"
    break;

  case 158: // expr_var: expr_var ">>" expr_int
#line 459 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2057 "frontend/parser.cpp"
    break;

  case 159: // expr_var: expr_var ">>" expr_var
#line 460 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2063 "frontend/parser.cpp"
    break;

  case 160: // expr_var: expr_int ">" expr_var
#line 462 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2069 "frontend/parser.cpp"
    break;

  case 161: // expr_var: expr_float ">" expr_var
#line 463 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2075 "frontend/parser.cpp"
    break;

  case 162: // expr_var: expr_str ">" expr_var
#line 464 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2081 "frontend/parser.cpp"
    break;

  case 163: // expr_var: expr_var ">" expr_int
#line 465 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2087 "frontend/parser.cpp"
    break;

  case 164: // expr_var: expr_var ">" expr_float
#line 466 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2093 "frontend/parser.cpp"
    break;

  case 165: // expr_var: expr_var ">" expr_str
#line 467 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2099 "frontend/parser.cpp"
    break;

  case 166: // expr_var: expr_var ">" expr_var
#line 468 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2105 "frontend/parser.cpp"
    break;

  case 167: // expr_var: expr_int ">=" expr_var
#line 470 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2111 "frontend/parser.cpp"
    break;

  case 168: // expr_var: expr_float ">=" expr_var
#line 471 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2117 "frontend/parser.cpp"
    break;

  case 169: // expr_var: expr_str ">=" expr_var
#line 472 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2123 "frontend/parser.cpp"
    break;

  case 170: // expr_var: expr_var ">=" expr_int
#line 473 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2129 "frontend/parser.cpp"
    break;

  case 171: // expr_var: expr_var ">=" expr_float
#line 474 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2135 "frontend/parser.cpp"
    break;

  case 172: // expr_var: expr_var ">=" expr_str
#line 475 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2141 "frontend/parser.cpp"
    break;

  case 173: // expr_var: expr_var ">=" expr_var
#line 476 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2147 "frontend/parser.cpp"
    break;

  case 174: // expr_var: expr_int "<" expr_var
#line 478 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2153 "frontend/parser.cpp"
    break;

  case 175: // expr_var: expr_float "<" expr_var
#line 479 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2159 "frontend/parser.cpp"
    break;

  case 176: // expr_var: expr_str "<" expr_var
#line 480 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2165 "frontend/parser.cpp"
    break;

  case 177: // expr_var: expr_var "<" expr_int
#line 481 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2171 "frontend/parser.cpp"
    break;

  case 178: // expr_var: expr_var "<" expr_float
#line 482 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2177 "frontend/parser.cpp"
    break;

  case 179: // expr_var: expr_var "<" expr_str
#line 483 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2183 "frontend/parser.cpp"
    break;

  case 180: // expr_var: expr_var "<" expr_var
#line 484 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2189 "frontend/parser.cpp"
    break;

  case 181: // expr_var: expr_int "<=" expr_var
#line 486 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2195 "frontend/parser.cpp"
    break;

  case 182: // expr_var: expr_float "<=" expr_var
#line 487 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2201 "frontend/parser.cpp"
    break;

  case 183: // expr_var: expr_str "<=" expr_var
#line 488 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2207 "frontend/parser.cpp"
    break;

  case 184: // expr_var: expr_var "<=" expr_int
#line 489 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2213 "frontend/parser.cpp"
    break;

  case 185: // expr_var: expr_var "<=" expr_float
#line 490 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2219 "frontend/parser.cpp"
    break;

  case 186: // expr_var: expr_var "<=" expr_str
#line 491 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2225 "frontend/parser.cpp"
    break;

  case 187: // expr_var: expr_var "<=" expr_var
#line 492 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2231 "frontend/parser.cpp"
    break;

  case 188: // expr_var: expr_int "==" expr_var
#line 494 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2237 "frontend/parser.cpp"
    break;

  case 189: // expr_var: expr_float "==" expr_var
#line 495 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2243 "frontend/parser.cpp"
    break;

  case 190: // expr_var: expr_str "==" expr_var
#line 496 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2249 "frontend/parser.cpp"
    break;

  case 191: // expr_var: expr_bool "==" expr_var
#line 497 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2255 "frontend/parser.cpp"
    break;

  case 192: // expr_var: expr_none "==" expr_var
#line 498 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2261 "frontend/parser.cpp"
    break;

  case 195: // expr_var: expr_var "==" expr_int
#line 501 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2267 "frontend/parser.cpp"
    break;

  case 196: // expr_var: expr_var "==" expr_float
#line 502 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2273 "frontend/parser.cpp"
    break;

  case 197: // expr_var: expr_var "==" expr_str
#line 503 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2279 "frontend/parser.cpp"
    break;

  case 198: // expr_var: expr_var "==" expr_bool
#line 504 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2285 "frontend/parser.cpp"
    break;

  case 199: // expr_var: expr_var "==" expr_none
#line 505 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2291 "frontend/parser.cpp"
    break;

  case 200: // expr_var: expr_var "==" expr_struct
#line 506 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2297 "frontend/parser.cpp"
    break;

  case 201: // expr_var: expr_mat "==" expr_mat
#line 507 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2303 "frontend/parser.cpp"
    break;

  case 202: // expr_var: expr_var "==" expr_mat
#line 508 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2309 "frontend/parser.cpp"
    break;

  case 203: // expr_var: expr_mat "==" expr_var
#line 509 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2315 "frontend/parser.cpp"
    break;

  case 204: // expr_var: expr_var "==" expr_var
#line 510 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2321 "frontend/parser.cpp"
    break;

  case 205: // expr_var: expr_int "!=" expr_var
#line 512 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2327 "frontend/parser.cpp"
    break;

  case 206: // expr_var: expr_float "!=" expr_var
#line 513 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2333 "frontend/parser.cpp"
    break;

  case 207: // expr_var: expr_str "!=" expr_var
#line 514 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2339 "frontend/parser.cpp"
    break;

  case 208: // expr_var: expr_bool "!=" expr_var
#line 515 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2345 "frontend/parser.cpp"
    break;

  case 209: // expr_var: expr_none "!=" expr_var
#line 516 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2351 "frontend/parser.cpp"
    break;

  case 212: // expr_var: expr_var "!=" expr_int
#line 519 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2357 "frontend/parser.cpp"
    break;

  case 213: // expr_var: expr_var "!=" expr_float
#line 520 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2363 "frontend/parser.cpp"
    break;

  case 214: // expr_var: expr_var "!=" expr_str
#line 521 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2369 "frontend/parser.cpp"
    break;

  case 215: // expr_var: expr_var "!=" expr_bool
#line 522 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2375 "frontend/parser.cpp"
    break;

  case 216: // expr_var: expr_var "!=" expr_none
#line 523 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2381 "frontend/parser.cpp"
    break;

  case 217: // expr_var: expr_var "!=" expr_struct
#line 524 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2387 "frontend/parser.cpp"
    break;

  case 218: // expr_var: expr_mat "!=" expr_mat
#line 525 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2393 "frontend/parser.cpp"
    break;

  case 219: // expr_var: expr_var "!=" expr_mat
#line 526 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2399 "frontend/parser.cpp"
    break;

  case 220: // expr_var: expr_mat "!=" expr_var
#line 527 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2405 "frontend/parser.cpp"
    break;

  case 221: // expr_var: expr_var "!=" expr_var
#line 528 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2411 "frontend/parser.cpp"
    break;

  case 222: // expr_var: expr_int "&" expr_var
#line 530 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2417 "frontend/parser.cpp"
    break;

  case 223: // expr_var: expr_var "&" expr_int
#line 531 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2423 "frontend/parser.cpp"
    break;

  case 224: // expr_var: expr_var "&" expr_var
#line 532 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2429 "frontend/parser.cpp"
    break;

  case 225: // expr_var: expr_int "^" expr_var
#line 534 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2435 "frontend/parser.cpp"
    break;

  case 226: // expr_var: expr_var "^" expr_int
#line 535 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2441 "frontend/parser.cpp"
    break;

  case 227: // expr_var: expr_var "^" expr_var
#line 536 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2447 "frontend/parser.cpp"
    break;

  case 228: // expr_var: expr_int "|" expr_var
#line 538 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2453 "frontend/parser.cpp"
    break;

  case 229: // expr_var: expr_var "|" expr_int
#line 539 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2459 "frontend/parser.cpp"
    break;

  case 230: // expr_var: expr_var "|" expr_var
#line 540 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2465 "frontend/parser.cpp"
    break;

  case 235: // expr_var: expr_none "in" expr_mat
#line 546 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2471 "frontend/parser.cpp"
    break;

  case 237: // expr_var: expr_mat "in" expr_mat
#line 548 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2477 "frontend/parser.cpp"
    break;

  case 242: // expr_var: expr_none "in" expr_var
#line 553 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2483 "frontend/parser.cpp"
    break;

  case 244: // expr_var: expr_mat "in" expr_var
#line 555 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2489 "frontend/parser.cpp"
    break;

  case 245: // expr_var: expr_var "in" expr_str
#line 556 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2495 "frontend/parser.cpp"
    break;

  case 246: // expr_var: expr_var "in" expr_var
#line 557 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2501 "frontend/parser.cpp"
    break;

  case 247: // expr_var: expr_bool "and" expr_var
#line 559 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2507 "frontend/parser.cpp"
    break;

  case 248: // expr_var: expr_var "and" expr_bool
#line 560 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2513 "frontend/parser.cpp"
    break;

  case 249: // expr_var: expr_var "and" expr_var
#line 561 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2519 "frontend/parser.cpp"
    break;

  case 250: // expr_var: expr_bool "or" expr_var
#line 563 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2525 "frontend/parser.cpp"
    break;

  case 251: // expr_var: expr_var "or" expr_bool
#line 564 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2531 "frontend/parser.cpp"
    break;

  case 252: // expr_var: expr_var "or" expr_var
#line 565 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2537 "frontend/parser.cpp"
    break;

  case 253: // expr_var: "not" expr_var
#line 567 "frontend/parser.yy"
                         { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseUnaryPrefixExpr(yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LNOT)); }
#line 2543 "frontend/parser.cpp"
    break;

  case 254: // expr_var: "~" expr_var
#line 569 "frontend/parser.yy"
                         { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseUnaryPrefixExpr(yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BNOT)); }
#line 2549 "frontend/parser.cpp"
    break;

  case 255: // expr_var: expr_int "++" expr_var
#line 571 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2555 "frontend/parser.cpp"
    break;

  case 256: // expr_var: expr_float "++" expr_var
#line 572 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2561 "frontend/parser.cpp"
    break;

  case 257: // expr_var: expr_str "++" expr_var
#line 573 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2567 "frontend/parser.cpp"
    break;

  case 258: // expr_var: expr_bool "++" expr_var
#line 574 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2573 "frontend/parser.cpp"
    break;

  case 259: // expr_var: expr_none "++" expr_var
#line 575 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseNone(), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2579 "frontend/parser.cpp"
    break;

  case 260: // expr_var: expr_var "++" expr_int
#line 576 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2585 "frontend/parser.cpp"
    break;

  case 261: // expr_var: expr_var "++" expr_float
#line 577 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2591 "frontend/parser.cpp"
    break;

  case 262: // expr_var: expr_var "++" expr_str
#line 578 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2597 "frontend/parser.cpp"
    break;

  case 263: // expr_var: expr_var "++" expr_bool
#line 579 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2603 "frontend/parser.cpp"
    break;

  case 264: // expr_var: expr_var "++" expr_none
#line 580 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseNone(), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2609 "frontend/parser.cpp"
    break;

  case 265: // expr_var: expr_var "++" expr_var
#line 581 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2615 "frontend/parser.cpp"
    break;

  case 266: // matrix: "[" "]"
#line 585 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(std::vector<ptc::ir::Expr *>{}); }
#line 2621 "frontend/parser.cpp"
    break;

  case 267: // matrix: "[" matvals "]"
#line 586 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2627 "frontend/parser.cpp"
    break;

  case 268: // matrix: "[" "terminator (\\n or ;)" matvals "]"
#line 587 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2633 "frontend/parser.cpp"
    break;

  case 269: // matrix: "[" matvals "terminator (\\n or ;)" "]"
#line 588 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2639 "frontend/parser.cpp"
    break;

  case 270: // matrix: "[" "terminator (\\n or ;)" matvals "terminator (\\n or ;)" "]"
#line 589 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2645 "frontend/parser.cpp"
    break;

  case 271: // matvals: expr
#line 592 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixValue(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2651 "frontend/parser.cpp"
    break;

  case 272: // matvals: matvals "," expr
#line 593 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2657 "frontend/parser.cpp"
    break;

  case 273: // matvals: matvals "," "terminator (\\n or ;)" expr
#line 594 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[3].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2663 "frontend/parser.cpp"
    break;

  case 274: // expr_mat: matrix
#line 598 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2669 "frontend/parser.cpp"
    break;

  case 275: // expr_mat: "(" matrix ")"
#line 599 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2675 "frontend/parser.cpp"
    break;

  case 276: // range: "(" range ")"
#line 601 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2681 "frontend/parser.cpp"
    break;

  case 277: // range: int_val ".." int_val
#line 602 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseRange(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2687 "frontend/parser.cpp"
    break;

  case 278: // range: int_val "," int_val ".." int_val
#line 603 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseRange(yystack_[4].value.as < ptc::ir::Expr * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2693 "frontend/parser.cpp"
    break;

  case 279: // int_val: expr_int
#line 605 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 2699 "frontend/parser.cpp"
    break;

  case 280: // int_val: expr_var
#line 606 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2705 "frontend/parser.cpp"
    break;

  case 293: // expr_none: "none"
#line 623 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseNone(); }
#line 2711 "frontend/parser.cpp"
    break;

  case 294: // expr_none: "(" "none" ")"
#line 624 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseNone(); }
#line 2717 "frontend/parser.cpp"
    break;

  case 301: // expr_int: "int"
#line 639 "frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 2723 "frontend/parser.cpp"
    break;

  case 302: // expr_int: "-" expr_int
#line 640 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 2729 "frontend/parser.cpp"
    break;

  case 303: // expr_int: "(" expr_int ")"
#line 641 "frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 2735 "frontend/parser.cpp"
    break;

  case 304: // expr_int: "~" expr_int
#line 642 "frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 2741 "frontend/parser.cpp"
    break;

  case 305: // expr_int: expr_int "*" expr_int
#line 643 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 2747 "frontend/parser.cpp"
    break;

  case 306: // expr_int: expr_int "/" expr_int
#line 644 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 2753 "frontend/parser.cpp"
    break;

  case 307: // expr_int: expr_int "%" expr_int
#line 645 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 2759 "frontend/parser.cpp"
    break;

  case 308: // expr_int: expr_int "-" expr_int
#line 646 "frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 2765 "frontend/parser.cpp"
    break;

  case 309: // expr_int: expr_int "+" expr_int
#line 647 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 2771 "frontend/parser.cpp"
    break;

  case 310: // expr_int: expr_int "<<" expr_int
#line 648 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 2777 "frontend/parser.cpp"
    break;

  case 311: // expr_int: expr_int ">>" expr_int
#line 649 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 2783 "frontend/parser.cpp"
    break;

  case 312: // expr_int: expr_int "&" expr_int
#line 650 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 2789 "frontend/parser.cpp"
    break;

  case 313: // expr_int: expr_int "^" expr_int
#line 651 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 2795 "frontend/parser.cpp"
    break;

  case 314: // expr_int: expr_int "|" expr_int
#line 652 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 2801 "frontend/parser.cpp"
    break;

  case 315: // expr_float: "float"
#line 656 "frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 2807 "frontend/parser.cpp"
    break;

  case 316: // expr_float: "-" expr_float
#line 657 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 2813 "frontend/parser.cpp"
    break;

  case 317: // expr_float: "(" expr_float ")"
#line 658 "frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 2819 "frontend/parser.cpp"
    break;

  case 318: // expr_float: expr_float "**" expr_float
#line 659 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2825 "frontend/parser.cpp"
    break;

  case 319: // expr_float: expr_float "**" expr_int
#line 660 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2831 "frontend/parser.cpp"
    break;

  case 320: // expr_float: expr_int "**" expr_float
#line 661 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2837 "frontend/parser.cpp"
    break;

  case 321: // expr_float: expr_float "*" expr_float
#line 662 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 2843 "frontend/parser.cpp"
    break;

  case 322: // expr_float: expr_float "*" expr_int
#line 663 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 2849 "frontend/parser.cpp"
    break;

  case 323: // expr_float: expr_int "*" expr_float
#line 664 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 2855 "frontend/parser.cpp"
    break;

  case 324: // expr_float: expr_float "/" expr_float
#line 665 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 2861 "frontend/parser.cpp"
    break;

  case 325: // expr_float: expr_float "/" expr_int
#line 666 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 2867 "frontend/parser.cpp"
    break;

  case 326: // expr_float: expr_int "/" expr_float
#line 667 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 2873 "frontend/parser.cpp"
    break;

  case 327: // expr_float: expr_float "%" expr_float
#line 668 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2879 "frontend/parser.cpp"
    break;

  case 328: // expr_float: expr_float "%" expr_int
#line 669 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2885 "frontend/parser.cpp"
    break;

  case 329: // expr_float: expr_int "%" expr_float
#line 670 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2891 "frontend/parser.cpp"
    break;

  case 330: // expr_float: expr_float "-" expr_float
#line 671 "frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 2897 "frontend/parser.cpp"
    break;

  case 331: // expr_float: expr_float "-" expr_int
#line 672 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 2903 "frontend/parser.cpp"
    break;

  case 332: // expr_float: expr_int "-" expr_float
#line 673 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 2909 "frontend/parser.cpp"
    break;

  case 333: // expr_float: expr_float "+" expr_float
#line 674 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 2915 "frontend/parser.cpp"
    break;

  case 334: // expr_float: expr_float "+" expr_int
#line 675 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 2921 "frontend/parser.cpp"
    break;

  case 335: // expr_float: expr_int "+" expr_float
#line 676 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 2927 "frontend/parser.cpp"
    break;

  case 336: // expr_str: "string"
#line 680 "frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2933 "frontend/parser.cpp"
    break;

  case 337: // expr_str: "(" expr_str ")"
#line 681 "frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 2939 "frontend/parser.cpp"
    break;

  case 338: // expr_str: expr_str "++" expr_str
#line 682 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 2945 "frontend/parser.cpp"
    break;

  case 339: // expr_str: expr_str "++" expr_int
#line 683 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 2951 "frontend/parser.cpp"
    break;

  case 340: // expr_str: expr_str "++" expr_float
#line 684 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 2957 "frontend/parser.cpp"
    break;

  case 341: // expr_str: expr_str "++" expr_bool
#line 685 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2963 "frontend/parser.cpp"
    break;

  case 342: // expr_str: expr_str "++" expr_none
#line 686 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 2969 "frontend/parser.cpp"
    break;

  case 343: // expr_str: expr_int "++" expr_str
#line 687 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 2975 "frontend/parser.cpp"
    break;

  case 344: // expr_str: expr_int "++" expr_int
#line 688 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 2981 "frontend/parser.cpp"
    break;

  case 345: // expr_str: expr_int "++" expr_float
#line 689 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 2987 "frontend/parser.cpp"
    break;

  case 346: // expr_str: expr_int "++" expr_bool
#line 690 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2993 "frontend/parser.cpp"
    break;

  case 347: // expr_str: expr_int "++" expr_none
#line 691 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 2999 "frontend/parser.cpp"
    break;

  case 348: // expr_str: expr_float "++" expr_str
#line 692 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 3005 "frontend/parser.cpp"
    break;

  case 349: // expr_str: expr_float "++" expr_int
#line 693 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 3011 "frontend/parser.cpp"
    break;

  case 350: // expr_str: expr_float "++" expr_float
#line 694 "frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 3017 "frontend/parser.cpp"
    break;

  case 351: // expr_str: expr_float "++" expr_bool
#line 695 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3023 "frontend/parser.cpp"
    break;

  case 352: // expr_str: expr_float "++" expr_none
#line 696 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 3029 "frontend/parser.cpp"
    break;

  case 353: // expr_str: expr_bool "++" expr_str
#line 697 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 3035 "frontend/parser.cpp"
    break;

  case 354: // expr_str: expr_bool "++" expr_int
#line 698 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 3041 "frontend/parser.cpp"
    break;

  case 355: // expr_str: expr_bool "++" expr_float
#line 699 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 3047 "frontend/parser.cpp"
    break;

  case 356: // expr_str: expr_bool "++" expr_bool
#line 700 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3053 "frontend/parser.cpp"
    break;

  case 357: // expr_str: expr_bool "++" expr_none
#line 701 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 3059 "frontend/parser.cpp"
    break;

  case 358: // expr_str: expr_none "++" expr_str
#line 702 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 3065 "frontend/parser.cpp"
    break;

  case 359: // expr_str: expr_none "++" expr_int
#line 703 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 3071 "frontend/parser.cpp"
    break;

  case 360: // expr_str: expr_none "++" expr_float
#line 704 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 3077 "frontend/parser.cpp"
    break;

  case 361: // expr_str: expr_none "++" expr_bool
#line 705 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3083 "frontend/parser.cpp"
    break;

  case 362: // expr_str: expr_none "++" expr_none
#line 706 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 3089 "frontend/parser.cpp"
    break;

  case 363: // expr_bool: "bool"
#line 710 "frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 3095 "frontend/parser.cpp"
    break;

  case 364: // expr_bool: "(" expr_bool ")"
#line 711 "frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 3101 "frontend/parser.cpp"
    break;

  case 365: // expr_bool: "not" expr_bool
#line 712 "frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 3107 "frontend/parser.cpp"
    break;

  case 366: // expr_bool: expr_bool "or" expr_bool
#line 713 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 3113 "frontend/parser.cpp"
    break;

  case 367: // expr_bool: expr_bool "and" expr_bool
#line 714 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 3119 "frontend/parser.cpp"
    break;

  case 368: // expr_bool: expr_bool "==" expr_bool
#line 716 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 3125 "frontend/parser.cpp"
    break;

  case 369: // expr_bool: expr_int "==" expr_int
#line 717 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 3131 "frontend/parser.cpp"
    break;

  case 370: // expr_bool: expr_int "==" expr_float
#line 718 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 3137 "frontend/parser.cpp"
    break;

  case 371: // expr_bool: expr_float "==" expr_float
#line 719 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 3143 "frontend/parser.cpp"
    break;

  case 372: // expr_bool: expr_float "==" expr_int
#line 720 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 3149 "frontend/parser.cpp"
    break;

  case 373: // expr_bool: expr_str "==" expr_str
#line 721 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 3155 "frontend/parser.cpp"
    break;

  case 374: // expr_bool: expr_none "==" expr_none
#line 722 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 3161 "frontend/parser.cpp"
    break;

  case 375: // expr_bool: expr_bool "!=" expr_bool
#line 724 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 3167 "frontend/parser.cpp"
    break;

  case 376: // expr_bool: expr_int "!=" expr_int
#line 725 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 3173 "frontend/parser.cpp"
    break;

  case 377: // expr_bool: expr_int "!=" expr_float
#line 726 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 3179 "frontend/parser.cpp"
    break;

  case 378: // expr_bool: expr_float "!=" expr_float
#line 727 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 3185 "frontend/parser.cpp"
    break;

  case 379: // expr_bool: expr_float "!=" expr_int
#line 728 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 3191 "frontend/parser.cpp"
    break;

  case 380: // expr_bool: expr_str "!=" expr_str
#line 729 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 3197 "frontend/parser.cpp"
    break;

  case 381: // expr_bool: expr_none "!=" expr_none
#line 730 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 3203 "frontend/parser.cpp"
    break;

  case 382: // expr_bool: expr_int ">" expr_int
#line 732 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 3209 "frontend/parser.cpp"
    break;

  case 383: // expr_bool: expr_int ">" expr_float
#line 733 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 3215 "frontend/parser.cpp"
    break;

  case 384: // expr_bool: expr_float ">" expr_float
#line 734 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 3221 "frontend/parser.cpp"
    break;

  case 385: // expr_bool: expr_float ">" expr_int
#line 735 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 3227 "frontend/parser.cpp"
    break;

  case 386: // expr_bool: expr_str ">" expr_str
#line 736 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 3233 "frontend/parser.cpp"
    break;

  case 387: // expr_bool: expr_int "<" expr_int
#line 738 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 3239 "frontend/parser.cpp"
    break;

  case 388: // expr_bool: expr_int "<" expr_float
#line 739 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 3245 "frontend/parser.cpp"
    break;

  case 389: // expr_bool: expr_float "<" expr_float
#line 740 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 3251 "frontend/parser.cpp"
    break;

  case 390: // expr_bool: expr_float "<" expr_int
#line 741 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 3257 "frontend/parser.cpp"
    break;

  case 391: // expr_bool: expr_str "<" expr_str
#line 742 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 3263 "frontend/parser.cpp"
    break;

  case 392: // expr_bool: expr_int ">=" expr_int
#line 744 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 3269 "frontend/parser.cpp"
    break;

  case 393: // expr_bool: expr_int ">=" expr_float
#line 745 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 3275 "frontend/parser.cpp"
    break;

  case 394: // expr_bool: expr_float ">=" expr_float
#line 746 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 3281 "frontend/parser.cpp"
    break;

  case 395: // expr_bool: expr_float ">=" expr_int
#line 747 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 3287 "frontend/parser.cpp"
    break;

  case 396: // expr_bool: expr_str ">=" expr_str
#line 748 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 3293 "frontend/parser.cpp"
    break;

  case 397: // expr_bool: expr_int "<=" expr_int
#line 750 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 3299 "frontend/parser.cpp"
    break;

  case 398: // expr_bool: expr_int "<=" expr_float
#line 751 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 3305 "frontend/parser.cpp"
    break;

  case 399: // expr_bool: expr_float "<=" expr_float
#line 752 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 3311 "frontend/parser.cpp"
    break;

  case 400: // expr_bool: expr_float "<=" expr_int
#line 753 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 3317 "frontend/parser.cpp"
    break;

  case 401: // expr_bool: expr_str "<=" expr_str
#line 754 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 3323 "frontend/parser.cpp"
    break;

  case 402: // expr_bool: expr_str "in" expr_str
#line 756 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[0].value.as < std::string > ().find(yystack_[2].value.as < std::string > ()) != std::string::npos; }
#line 3329 "frontend/parser.cpp"
    break;

  case 409: // mattype: "identifier" matsq
#line 770 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3335 "frontend/parser.cpp"
    break;

  case 410: // mattype: "'int'" matsq
#line 771 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(INT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3341 "frontend/parser.cpp"
    break;

  case 411: // mattype: "'float'" matsq
#line 772 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(FLOAT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3347 "frontend/parser.cpp"
    break;

  case 412: // mattype: "'string'" matsq
#line 773 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(STRING_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3353 "frontend/parser.cpp"
    break;

  case 413: // mattype: "'bool'" matsq
#line 774 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(BOOL_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3359 "frontend/parser.cpp"
    break;

  case 414: // mattype: "any" matsq
#line 775 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(ANY_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3365 "frontend/parser.cpp"
    break;

  case 422: // matsq: "[" "]"
#line 784 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(scanner->parseInt(-1)); }
#line 3371 "frontend/parser.cpp"
    break;

  case 423: // matsq: "[" "]" matsq
#line 786 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), scanner->parseInt(-1)); }
#line 3377 "frontend/parser.cpp"
    break;

  case 424: // type: "'int'" "?"
#line 791 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, true, true); }
#line 3383 "frontend/parser.cpp"
    break;

  case 425: // type: "'float'" "?"
#line 792 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, true, true); }
#line 3389 "frontend/parser.cpp"
    break;

  case 426: // type: "'string'" "?"
#line 793 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, true, true); }
#line 3395 "frontend/parser.cpp"
    break;

  case 427: // type: "'bool'" "?"
#line 794 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, true, true); }
#line 3401 "frontend/parser.cpp"
    break;

  case 428: // type: "identifier" "?"
#line 795 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[1].value.as < std::string > (), true, true); }
#line 3407 "frontend/parser.cpp"
    break;

  case 431: // type: mattype "?"
#line 798 "frontend/parser.yy"
       { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 3413 "frontend/parser.cpp"
    break;

  case 432: // type: "'int'"
#line 799 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, false, true); }
#line 3419 "frontend/parser.cpp"
    break;

  case 433: // type: "'float'"
#line 800 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, false, true); }
#line 3425 "frontend/parser.cpp"
    break;

  case 434: // type: "'string'"
#line 801 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, false, true); }
#line 3431 "frontend/parser.cpp"
    break;

  case 435: // type: "'bool'"
#line 802 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, false, true); }
#line 3437 "frontend/parser.cpp"
    break;

  case 436: // type: "any"
#line 803 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(ANY_CSTR, false, true); }
#line 3443 "frontend/parser.cpp"
    break;

  case 437: // type: "identifier"
#line 804 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[0].value.as < std::string > (), false, true); }
#line 3449 "frontend/parser.cpp"
    break;

  case 438: // type: "external identifier"
#line 805 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExtType(yystack_[0].value.as < std::string > (), false); }
#line 3455 "frontend/parser.cpp"
    break;

  case 440: // type: mattype
#line 807 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 3461 "frontend/parser.cpp"
    break;


#line 3465 "frontend/parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -644;

  const short  Parser ::yytable_ninf_ = -439;

  const short
   Parser ::yypact_[] =
  {
    1725,  -644,  -644,  -644,  -644,  -644,  -644,  -644,  1258,   409,
     393,  1490,  1490,   -67,    21,   -27,  -644,  -644,  -644,  -644,
    1490,  -644,  -644,   -12,    17,    42,    49,   169,    54,     1,
      11,    29,   174,    62,  -644,  -644,    45,    45,  -644,  -644,
     247,  -644,   273,  -644,  2164,  -644,   283,  -644,  -644,    45,
      45,    45,  1970,  2472,  -644,   690,   501,    19,  2726,  2818,
     894,   633,   314,   225,     4,   285,   130,   370,  2332,   379,
     690,   501,    19,  2254,  1057,  1196,   878,  1490,  -644,   130,
    -644,   110,   427,   427,   678,  -644,  -644,  -644,  -644,    18,
    2726,  2818,   894,  -644,    18,  -644,   633,   348,   381,  -644,
     363,  -644,  -644,   365,    21,  -644,    21,  -644,    21,  -644,
      21,  -644,   134,  1413,  -644,   395,   727,   101,    21,  -644,
    -644,  -644,  1055,  -644,  -644,  -644,  -644,  2374,  -644,  -644,
    -644,  -644,  -644,  1792,  1490,   397,  2239,  -644,  -644,   346,
    1490,  -644,  -644,  -644,  1490,  1490,  1490,  1490,  1490,  1490,
    1490,  1490,  1490,  1490,  1490,  1490,  1490,  -644,   499,  1055,
    1490,  1490,  1490,  1490,  1490,  1490,  1490,  1490,  1490,  1490,
    1490,  1490,  1490,  1490,  1490,  1490,  1490,  1490,  1490,  1490,
    1490,   210,  -644,  1055,  1490,  1490,  1490,  1490,  -644,  1490,
    1490,  1490,  1490,  1490,  1490,  1490,  1490,  1490,  1490,  1490,
    1490,  1490,  1490,  1490,  1490,  1490,  1490,  1490,  1490,  1490,
    1490,  1490,  1490,  1490,  1490,  1490,  1490,  1490,  1490,  1490,
    1490,  1490,  1490,  1490,  1490,  1490,  1490,  1490,  1490,  1490,
    1490,  1490,  1490,  1490,  1490,  1490,  1490,  1490,  1490,  1490,
    1490,  1490,  1490,  1490,    21,  -644,  -644,  1499,   102,   410,
    -644,  1055,   437,  -644,  -644,  -644,  -644,  -644,  -644,   239,
     436,  -644,    30,  1375,  1298,   678,   678,  -644,   427,   427,
     427,   427,   427,   427,   678,   678,   678,   678,   678,   427,
     427,   427,   427,   427,   427,  1490,    21,   -27,  1490,  -644,
    -644,  -644,  -644,   449,   420,  -644,   448,   372,   399,   461,
      63,  1808,   766,  2472,    14,  2726,  -644,   396,   469,  -644,
     240,  -644,   105,   -18,   434,     5,   477,  2374,  -644,  1890,
     479,   485,  -644,  2160,  -644,  -644,  -644,  -644,  -644,  -644,
    -644,  -644,  -644,  -644,  -644,  -644,  -644,   237,  -644,   242,
     857,   487,   743,   782,   857,   743,   782,   473,   480,   481,
     473,   480,   481,   473,   480,   481,   473,   480,   481,  2501,
     717,  2749,  2852,   999,   362,  2530,   720,  2041,   696,  2559,
     562,  2646,  2829,  2588,  2772,  2617,  2795,   630,   543,   630,
     543,  2675,    32,  -644,  -644,  2391,  1261,   444,  -644,  2675,
      32,  -644,  -644,  2391,  1261,   444,  -644,   934,  1095,  1160,
     491,   934,  1095,  1160,   491,   934,  1095,  1160,   491,   934,
    1095,  1160,   491,  -644,  -644,   243,   857,   487,  2559,   619,
    2675,    32,  2675,    32,  2501,   717,  2749,  2852,   999,   362,
    2559,   619,  2675,  -644,  2675,  -644,  2559,   619,  2675,  -644,
    2675,  -644,   857,   743,   782,   857,   743,   782,   473,   480,
     481,   473,   480,   481,   473,   480,   481,   473,   481,  2501,
     717,  2749,  2852,   999,   362,  2559,   619,  2646,  2829,  2588,
    2772,  2617,  2795,   630,   543,   630,   543,  2675,  2391,  1261,
    2675,  2391,  1261,   934,  1095,  1160,   934,  1095,  1160,   934,
    1095,  1160,   934,  1095,  1160,   857,   743,   782,   857,   743,
     782,   473,   480,   481,   473,   480,   481,   473,   480,   481,
     473,   480,   481,  2501,   717,  2749,  2852,   999,   362,  2559,
     619,  2675,  2391,  1261,  2675,  2391,  1261,   934,  1095,  1160,
     934,  1095,  1160,   934,  1095,  1160,   934,  1095,  1160,   502,
    2501,   717,  2749,  2852,   999,   362,  2559,   619,   562,  2675,
     444,  2675,   444,   934,   491,   934,   491,   934,   491,   934,
     491,  2501,   717,  2749,  2852,   999,   362,  2530,   720,  2041,
     696,  2559,   619,  2675,  -644,  2675,  -644,  -644,  -644,   503,
     810,  1933,  -644,   504,  -644,  -644,  1490,  -644,  1224,  -644,
     678,   678,   678,   678,   678,   791,   872,   791,   872,   497,
     509,   497,   509,   497,   509,  1961,   509,   963,  2166,  2093,
     983,   983,   791,   872,   791,   872,   497,   509,   497,   509,
     497,   509,   497,   509,  -644,  -644,  -644,  -644,   621,   621,
    -644,   435,   505,   521,     7,  -644,  1846,   275,   454,   492,
     538,     8,  -644,  1093,   277,  -644,   979,   508,  -644,  -644,
    1591,  1591,  1591,  -644,  2164,  2089,   561,  1490,  2164,  -644,
    1490,  -644,  -644,  -644,  -644,  -644,  -644,   275,   555,  -644,
    -644,   231,   231,  -644,  -644,  -644,   560,  -644,   535,  -644,
     621,   537,  -644,  -644,  -644,   389,   275,  -644,  -644,   569,
    -644,  1180,  -644,  1295,   278,  1490,  1687,   603,  2443,   610,
     206,  2703,   612,   613,   616,   618,  -644,   628,  -644,   623,
     576,  -644,  -644,   275,  -644,  1490,  -644,  1490,   564,    16,
    -644,  -644,  -644,   625,  -644,   645,  -644,  1445,   627,  2332,
     658,  2254,  2164,  2164,  1490,  1490,  2164,  2164,  2164,  2164,
    -644,  -644,  -644,  -644,  2164,  -644,  -644,  -644,  -644,  -644,
    -644,  -644,  -644,   668,   642,  -644,  -644,  -644,  -644,   646,
    -644,  -644,  -644,  -644,  -644,  -644,  -644,  1490,  -644
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     9,   301,   315,   336,   363,   293,     0,     0,
       0,     0,     0,     0,   436,     0,    52,    44,    46,    48,
      36,    33,    34,     0,   432,   433,   434,   435,     0,     0,
     103,   104,     0,     0,     4,    10,     0,     0,    35,    15,
       0,    17,     0,    18,     0,    16,     0,    19,    20,     0,
       0,     0,     0,    96,   274,    95,    97,    98,    99,   100,
     101,   102,   439,   440,     0,   293,   103,   104,     0,   274,
       0,     0,     0,     0,     0,     0,     0,     0,   266,   103,
     271,     0,     0,     0,     0,   105,   106,   302,   316,   253,
       0,     0,     0,   365,   254,   304,     0,     0,     0,   414,
      31,    30,    37,     0,   424,   410,   425,   411,   426,   412,
     427,   413,     0,     0,    68,     0,     0,     0,   428,   116,
     295,   409,     0,   429,   117,     1,     3,     0,     5,     8,
       7,    14,    21,     0,     0,     0,     0,    28,    29,     0,
       0,    12,    13,    11,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   118,     0,     0,     0,     0,     0,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   430,   415,   431,     0,    74,     0,
     294,     0,   295,   107,   275,   303,   317,   337,   364,     0,
       0,   267,     0,     0,     0,     0,     0,   304,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   422,     0,     0,   417,
     418,   419,   420,     0,     0,   406,     0,   437,   438,     0,
     407,     0,     0,   280,     0,   279,   297,     0,     0,   416,
       0,     6,   437,   438,     0,     0,     0,     0,    23,     0,
       0,     0,    92,    91,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,   108,     0,    93,     0,
     148,   146,   143,   144,   153,   151,   152,   130,   128,   129,
     135,   133,   134,   140,   138,   139,   123,   125,   122,   265,
     264,   260,   261,   262,   263,   249,   248,   252,   251,   246,
     245,   224,   223,   230,   229,   227,   226,   156,   155,   159,
     158,   204,   202,   199,   200,   195,   196,   197,   198,   221,
     219,   216,   217,   212,   213,   214,   215,   166,   163,   164,
     165,   180,   177,   178,   179,   173,   170,   171,   172,   187,
     184,   185,   186,   119,   120,     0,   147,   145,   244,   237,
     203,   201,   220,   218,   259,   362,   359,   360,   358,   361,
     242,   235,   192,   374,   209,   381,   243,   236,   194,   193,
     211,   210,   141,   309,   335,   149,   308,   332,   126,   305,
     323,   131,   306,   326,   136,   307,   329,   124,   320,   255,
     347,   344,   345,   343,   346,   238,   231,   222,   312,   228,
     314,   225,   313,   154,   310,   157,   311,   188,   369,   370,
     205,   376,   377,   160,   382,   383,   174,   387,   388,   167,
     392,   393,   181,   397,   398,   142,   334,   333,   150,   331,
     330,   127,   322,   321,   132,   325,   324,   137,   328,   327,
     121,   319,   318,   256,   352,   349,   350,   348,   351,   239,
     232,   189,   372,   371,   206,   379,   378,   161,   385,   384,
     175,   390,   389,   168,   395,   394,   182,   400,   399,     0,
     257,   342,   339,   340,   338,   341,   240,   233,   402,   190,
     373,   207,   380,   162,   386,   176,   391,   169,   396,   183,
     401,   258,   357,   354,   355,   353,   356,   247,   367,   250,
     366,   241,   234,   191,   368,   208,   375,   421,   404,     0,
       0,     0,   296,     0,   268,   269,     0,   272,     0,   302,
       0,     0,     0,     0,     0,   309,   335,   308,   332,   305,
     323,   306,   326,   307,   329,     0,   320,   312,   314,   313,
     310,   311,   334,   333,   331,   330,   322,   321,   325,   324,
     328,   327,   319,   318,    78,   423,    32,    77,     0,    57,
      54,     0,     0,     0,     0,   405,     0,     0,     0,    73,
       0,     0,   281,     0,     0,   112,     0,     0,   298,   113,
       0,     0,     0,    74,     0,     0,    24,     0,     0,   109,
       0,   114,   111,   110,   403,    76,    75,     0,     0,   270,
     273,   309,   308,   305,   306,   307,     0,    58,     0,    55,
      59,    61,   408,    66,    71,     0,     0,    69,   285,     0,
     283,     0,   282,     0,     0,     0,     0,     0,   280,     0,
       0,   279,     0,     0,     0,     0,    45,    25,    26,     0,
      51,    94,    64,     0,    56,     0,    60,     0,     0,     0,
      67,   288,   287,     0,   286,     0,   284,     0,   299,   280,
       0,   279,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    47,    53,    49,     0,    65,    63,    62,    72,    70,
     291,   290,   289,     0,     0,   276,    39,    42,   277,     0,
      40,    43,    38,    41,    50,   292,   300,     0,   278
  };

  const short
   Parser ::yypgoto_[] =
  {
    -644,  -644,   -78,   400,   -28,   109,  -625,  -643,  -644,   412,
    -644,  -644,  -644,  -644,  -644,  -644,  -644,  -644,  -644,  -644,
    -644,  -644,  -644,  -598,  -644,  -644,   622,  -644,   115,   567,
    -644,   558,  -644,  1484,   137,    -7,   626,  1193,  -411,   270,
     375,  1389,  1680,   -60,   -48,    -8,   391,   704,  1006,  -644,
    -240,  -644,    -6,   331
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    32,    33,   131,    34,   137,   138,   139,    36,   101,
      37,    38,    39,    40,    41,    42,    43,    44,    45,   743,
      46,   744,    47,   632,   633,    48,   115,   639,   640,    49,
      50,    51,   337,    52,    53,    54,    81,    70,   699,   700,
     182,    71,    72,   120,   308,    58,    91,    92,    96,    62,
     299,    63,   121,    64
  };

  const short
   Parser ::yytable_[] =
  {
      73,    69,    87,    90,    95,   128,   252,   579,    99,    97,
     113,   706,   683,   247,   247,   710,   247,   247,   105,   107,
     109,   111,   116,   651,   117,   247,   645,   158,    98,   159,
     676,   677,    98,   586,     3,     4,     5,     6,     7,     8,
     122,     9,   712,   183,   193,   129,    10,   184,   130,   100,
     123,   194,   195,    98,    11,   646,   245,   181,   319,    12,
      98,   720,   126,   127,   103,     2,     3,     4,     5,     6,
       7,     8,   247,     9,   263,    87,   267,   114,    10,   118,
     248,   653,   716,   681,   687,   104,    11,  -437,   745,   756,
     757,    12,   749,   760,   761,   762,   763,   123,   289,   311,
     290,   764,   291,   636,   292,  -438,    79,    67,   305,    35,
     106,   -68,   309,   260,   305,   306,    98,   108,    13,    14,
      15,    16,   261,    17,    18,    19,    20,    21,    22,    23,
     112,    24,    25,    26,    27,    28,    29,   293,    30,    31,
     307,   251,    35,   117,   580,    68,   650,   294,    89,    94,
     262,   305,   342,   345,   348,   351,   354,   357,   361,    90,
      90,    90,   372,   374,   376,   378,   380,   385,   393,   398,
     402,   406,   410,   118,   125,   305,    90,    90,    90,    90,
      98,   426,    90,    90,    90,    90,    90,    90,   443,   446,
     449,   452,   455,    90,   461,    90,   468,   470,   472,   474,
     476,   478,   481,   484,   487,   490,   493,   496,   499,   502,
     505,   508,   511,   515,    90,   522,   525,   528,   531,   534,
     537,   305,   542,    90,    90,    90,    90,    90,    90,    90,
     563,    90,    90,    90,    90,    90,    35,   110,   577,   655,
     703,   705,   583,   305,   734,    35,   735,   659,   592,   593,
     594,   584,   649,   303,   661,   662,   133,   588,   589,   303,
     595,   597,   599,   601,   603,   605,   607,   608,   609,   610,
     611,   612,   614,   616,   618,   620,   622,   660,   135,   262,
     625,   646,   134,   646,   646,   730,   413,   414,   136,   690,
     726,   128,   140,   246,   305,   250,   303,   340,   344,   347,
     350,   353,   356,   359,   365,   367,   369,   371,   373,   375,
     377,   379,   381,   389,   397,   401,   405,   409,   691,   727,
     303,   416,   418,   420,   422,    98,   424,   430,   432,   434,
     436,   438,   440,   442,   445,   448,   451,   454,   457,   459,
     465,   467,   469,   471,   473,   475,   477,   480,   483,   486,
     489,   492,   495,   498,   501,   504,   507,   510,   513,   519,
     521,   524,   527,   530,   533,   536,   303,   540,   546,   549,
     551,   553,   555,   557,   559,   561,   567,   569,   571,   573,
     575,   122,   244,    98,   239,   240,   304,   241,   303,   254,
     285,    59,   310,   286,   242,   243,   682,     3,     4,    74,
      59,    88,    82,   287,   301,   119,   124,   288,   320,    83,
     317,    59,    77,     3,     4,     5,     6,     7,     8,   581,
       9,    78,    84,   629,    59,    10,    35,   718,    35,   339,
     188,     3,     4,    11,   630,    59,    82,   132,    12,   303,
     118,   119,   124,    83,   300,   188,    14,   582,   585,   141,
     142,   143,   157,   415,   119,   229,    84,   113,    24,    25,
      26,    27,   628,   296,   315,   297,   298,   123,    59,    85,
      86,   635,   647,   264,    88,   652,   631,    14,   234,   235,
     236,   237,   158,   648,   159,    79,    67,   654,   657,    24,
      25,    26,    27,   165,   296,   658,   297,   298,   183,   539,
     201,   220,   229,     3,     4,     5,     6,     7,     8,   336,
       9,   678,   181,   664,   663,    10,   669,   273,    59,   679,
     666,   304,   189,    11,   680,    59,   190,    59,    12,   284,
     684,    59,   685,   191,   192,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,   686,    59,
     695,   343,   346,   349,   352,   355,   358,   362,   196,   197,
     198,   199,   200,   201,   708,   713,   386,   394,   399,   403,
     407,   411,   644,   229,   714,    79,    67,   715,   300,   717,
     427,   721,   671,   672,   673,   674,   675,   444,   447,   450,
     453,   456,   458,   462,   232,   233,   234,   235,   236,   237,
     479,   482,   485,   488,   491,   494,   497,   500,   503,   506,
     509,   512,   516,   732,   523,   526,   529,   532,   535,   538,
     733,   543,   736,   737,   629,   634,   738,   128,   739,   564,
     183,   740,   641,   741,   184,   305,   742,   750,   305,   158,
     748,   159,   701,   701,   701,   160,   161,   162,   163,   164,
     165,   186,   187,    59,   238,   239,   240,   751,   241,   596,
     598,   600,   602,   604,   606,   242,   243,   754,   755,   181,
     613,   615,   617,   619,   621,   623,    59,   631,    14,    59,
     765,   307,     3,   305,   767,   305,   249,   265,   731,    69,
      24,    25,    26,    27,   266,   296,   668,   297,   298,   626,
     314,   183,   322,   259,    60,   184,   766,    84,    59,     0,
      59,     0,    75,    60,     0,   185,   188,     0,   239,   305,
       0,   241,   186,   187,    60,     0,   305,   305,   242,   243,
       0,     3,     4,     5,     6,     7,     8,    60,     9,   286,
       0,     0,   190,    10,     0,   241,     0,     0,    60,   191,
     192,    11,   242,   243,     0,     0,    12,   188,     0,   305,
     198,   199,   200,   201,    35,   188,     0,     0,   302,     0,
       3,     4,     5,     6,     7,     8,     0,     9,   642,     0,
     303,    60,    10,   303,     0,     0,     0,   698,   698,   698,
      11,     0,   188,     0,   188,    12,   188,     0,   188,   217,
     218,   219,   220,    79,    67,     0,   188,   643,   270,   271,
     272,   273,   188,     0,     3,     4,     5,     6,     7,     8,
       0,     9,     0,   117,     0,     0,    10,     0,   303,     0,
     303,    60,     0,   729,    11,     0,     0,     0,    60,    12,
      60,   188,    79,    67,    60,     0,     0,     0,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,     0,    60,     0,   303,     0,   158,     0,   159,     0,
     363,   303,   303,   370,   162,   163,   164,   165,     0,   387,
     395,   400,   404,   408,   412,     0,    79,    67,   258,   281,
     282,   283,   284,   428,     0,   188,   181,     0,     0,   238,
     239,   240,     0,   241,   303,   229,   463,     0,     0,     0,
     242,   243,   641,   689,     0,   230,   694,     0,     0,   231,
       0,     0,   188,     0,     0,   517,   232,   233,   234,   235,
     236,   237,     0,     0,   544,   548,   550,   552,   554,   556,
     558,   560,   565,   158,     0,   159,     0,   188,     0,   160,
     161,   162,   163,   164,   165,     0,     0,     0,     0,   634,
     634,   723,     0,   725,   173,   174,    60,   300,     0,     0,
       0,    59,     0,   181,     0,     0,     0,    59,   590,   591,
     592,   593,   594,     3,     4,     5,     6,     7,     8,    60,
       9,   692,    60,   277,   278,    10,     0,   753,   590,   591,
     592,   593,   594,    11,   758,   759,    61,     0,    12,     0,
     229,   634,     0,     0,    76,    61,   719,    93,     0,     0,
     693,    60,     0,    60,   231,     0,    61,     0,     0,     0,
       0,   232,   233,   234,   235,   236,   237,   768,     0,    61,
       0,    59,    59,    59,     0,    59,    59,     0,    59,    59,
      61,    59,     0,     0,     0,    79,    67,     0,     0,     3,
       4,     5,     6,     7,     8,     0,     9,   256,     0,     0,
       0,    10,   215,   216,   217,   218,   219,   220,   221,    11,
       0,     0,   222,    61,    12,     0,    59,    74,     0,   223,
     224,   225,   226,   227,   228,     0,   302,     3,     4,     5,
       6,     7,     8,     0,     9,   688,    59,     0,    59,    10,
     196,   197,   198,   199,   200,   201,     0,    11,     0,     0,
       0,     0,    12,    59,    59,   207,   208,    59,    59,    59,
      59,    79,    67,    61,     0,    59,     0,     0,     0,     0,
      61,     0,    61,     0,     0,     0,    61,     0,     0,     0,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,     0,    61,     0,     0,     0,     0,    79,
      67,     0,   364,   366,   368,   215,   216,   217,   218,   219,
     220,   388,   396,     0,     3,     4,     5,     6,     7,     8,
       0,     9,   722,    55,     0,   429,    10,     0,     0,     0,
       0,     0,    55,     0,    11,     0,   257,   229,   464,    12,
       0,     0,     0,    55,     0,     0,     0,   230,     0,     0,
       0,   231,     0,     0,     0,     0,    55,   518,   232,   233,
     234,   235,   236,   237,   255,     0,   545,    55,     0,   590,
     591,   592,   593,   594,   566,   568,   570,     0,   574,   576,
     274,   275,   276,     0,   277,   278,    79,    67,     0,     0,
       0,     0,     3,     4,     5,     6,    65,     8,    61,     9,
      55,     0,     0,     0,    10,     0,   215,   216,   217,   218,
     219,   220,    11,     0,    60,     0,     0,    12,     0,     0,
      60,    61,     0,     0,    61,   225,   226,   227,   228,     3,
       4,     5,     6,     7,     8,     0,     9,   724,   256,     0,
       0,    10,     0,   279,   280,   281,   282,   283,   284,    11,
      55,     0,     0,    61,    12,    61,     0,    55,     0,    55,
       0,     0,     0,    55,    66,    67,     0,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
       0,    55,     0,   341,    60,    60,    60,     0,    60,    60,
       0,    60,    60,     0,    60,     0,     0,     0,   382,   390,
       0,    79,    67,     0,     0,     0,     0,   417,   419,   421,
     423,     0,     0,   431,     0,   255,   437,     0,     0,    56,
     268,   269,   270,   271,   272,   273,   466,     0,    56,    60,
      75,   274,   275,   276,     0,   277,   278,     0,     0,    56,
       0,     0,     0,     0,     0,   520,     0,     0,     0,    60,
       0,    60,    56,   295,   547,     0,     0,     0,     0,     0,
       0,     0,     0,    56,   572,     0,    60,    60,     0,     0,
      60,    60,    60,    60,     0,     0,     0,     0,    60,     3,
       4,     5,     6,     7,     8,    55,     9,   752,     0,     0,
       0,    10,     0,     0,     0,     0,    56,     0,     0,    11,
      14,     0,     0,     0,    12,     0,     0,     0,    55,     0,
       0,    55,    24,    25,    26,    27,     0,   296,     0,   297,
     298,     0,     0,    80,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,   102,     0,    10,     0,     0,   578,
      55,     0,    55,     0,    11,     0,    56,     0,     0,    12,
       0,    79,    67,    56,     0,    56,     0,     0,     0,    56,
       0,     0,     0,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,     0,    56,     0,     0,
       0,     0,     0,     0,     0,   360,    14,     0,     0,     0,
       0,    80,     0,     0,   383,   391,    79,    67,    24,    25,
      26,    27,     0,   296,     0,   297,   298,     0,   425,     0,
     433,   435,     0,     0,     0,     0,    61,     0,     0,     0,
       0,   460,    61,     0,     0,     3,     4,     5,     6,     7,
     696,     0,     9,     0,     0,     0,     0,    10,     0,     0,
     514,     0,     0,     0,     0,    11,     0,     0,   316,   541,
      12,     0,     0,     0,   321,     0,     0,   562,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,     0,   338,     0,     0,     0,     0,     0,     0,     0,
       0,    56,     0,     0,     0,     0,    61,    61,    61,     0,
      61,    61,     0,    61,    61,     0,    61,    79,    67,     0,
       0,     0,     0,     0,    56,     0,     0,    56,     0,     0,
      57,     0,     0,     0,     0,     0,     0,     0,     0,    57,
       0,     3,     4,     5,     6,    65,   696,     0,     9,     0,
      57,    61,    76,    10,     0,     0,    56,     0,    56,     0,
       0,    11,     0,    57,     0,     0,    12,     0,     0,     0,
       0,    61,     0,    61,    57,     1,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,    61,    61,
       0,    10,    61,    61,    61,    61,   587,     0,     0,    11,
      61,     0,     0,     0,    12,     0,     0,    57,     0,     0,
       0,     0,     0,    66,    67,     0,     0,     0,     0,   624,
       0,     0,   627,    55,     0,     0,     0,     0,     0,    55,
       0,    13,    14,    15,    16,     0,    17,    18,    19,    20,
      21,    22,    23,     0,    24,    25,    26,    27,    28,    29,
       0,    30,    31,     0,     0,     0,     0,    57,     0,     0,
       0,     0,     0,     0,    57,     0,    57,     0,   637,     0,
      57,     0,     0,     0,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,     0,    57,     0,
       0,     0,     0,    55,    55,    55,   638,    55,    55,    14,
      55,    55,     0,    55,     0,   384,   392,     0,     0,     0,
       0,    24,    25,    26,    27,    14,   296,     0,   312,   313,
       0,     0,     0,     0,   439,   441,     0,    24,    25,    26,
      27,     0,   296,     0,   297,   298,     0,     0,    55,     0,
       0,   127,     0,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,    14,   656,     0,    10,     0,    55,     0,
      55,     0,     0,     0,    11,    24,    25,    26,    27,    12,
     296,     0,   297,   298,     0,    55,    55,     0,     0,    55,
      55,    55,    55,     0,     0,     0,     0,    55,     0,     0,
       0,     0,    57,   667,     0,     0,    13,    14,    15,    16,
       0,    17,    18,    19,    20,    21,    22,    23,     0,    24,
      25,    26,    27,    28,    29,    57,    30,    31,    57,    56,
     129,   638,     0,   130,     0,    56,   268,   269,   270,   271,
     272,   273,     0,     0,     0,     0,     0,   274,   275,   276,
      14,   277,   278,     0,     0,     0,     0,    57,     0,    57,
       0,     0,    24,    25,    26,    27,     0,   296,     0,   297,
     298,     0,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,   155,   156,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    56,
      56,    56,     0,    56,    56,     0,    56,    56,     0,    56,
     158,     0,   159,     0,     0,     0,   160,   161,   162,   163,
     164,   165,     0,   167,   665,     0,   169,   170,   171,   172,
     670,   173,   174,   175,   176,   177,   178,   179,   180,     0,
     181,     0,     0,     0,    56,     0,     0,     0,     0,     0,
     127,     0,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,   707,    56,    10,    56,     0,   590,   591,
     592,   593,   594,    11,     0,     0,     0,     0,    12,   274,
       0,    56,    56,   277,   278,    56,    56,    56,    56,     0,
       0,     0,     0,    56,   697,   702,   704,     0,     0,     0,
       0,   709,     0,     0,   711,    13,    14,    15,    16,     0,
      17,    18,    19,    20,    21,    22,    23,     0,    24,    25,
      26,    27,    28,    29,     0,    30,    31,   135,     3,     4,
       5,     6,     7,     8,     0,     9,     0,   136,     0,   728,
      10,   590,   591,   592,   593,   594,     0,     0,    11,     0,
       0,     0,   274,    12,   276,     0,   277,   278,     0,   746,
       0,   747,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,   155,   156,     0,     0,     0,     0,
      13,    14,    15,    16,     0,    17,    18,    19,    20,    21,
      22,    23,     0,    24,    25,    26,    27,    28,    29,     0,
      30,    31,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,   318,     0,    10,     0,     0,     0,     0,
      57,     0,     0,    11,   255,     0,    57,     0,    12,   196,
     197,   198,   199,   200,   201,   202,     0,     0,     0,   203,
     204,   205,   206,     0,   207,   208,   209,   210,   211,   212,
     213,   214,     0,     0,     0,    13,    14,    15,    16,     0,
      17,    18,    19,    20,    21,    22,    23,     0,    24,    25,
      26,    27,    28,    29,     0,    30,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      57,    57,    57,     0,    57,    57,     0,    57,    57,     0,
      57,   158,   253,   159,     0,     0,     0,   160,   161,   162,
     163,   164,   165,   166,   167,   168,     0,   169,   170,   171,
     172,     0,   173,   174,   175,   176,   177,   178,   179,   180,
       0,   181,     0,     0,     0,    57,     0,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,     0,     0,
      10,     0,     0,     0,     0,    57,     0,    57,    11,     0,
       0,     0,     0,    12,     0,     0,   196,   197,   198,   199,
     200,   201,    57,    57,     0,     0,    57,    57,    57,    57,
       0,   207,   208,     0,    57,   211,   212,   213,   214,     0,
      13,    14,    15,    16,     0,    17,    18,    19,    20,    21,
      22,    23,     0,    24,    25,    26,    27,    28,    29,     0,
      30,    31,   158,   -96,   159,     0,     0,     0,   160,   161,
     162,   163,   164,   165,   166,   167,   168,     0,   169,   170,
     171,   172,     0,   173,   174,   175,   176,   177,   178,   179,
     180,   158,   181,   159,     0,     0,     0,   160,   161,   162,
     163,   164,   165,   166,   167,   168,     0,   169,   170,   171,
     172,     0,   173,   174,   175,   176,   177,   178,   179,   180,
     158,   181,   159,     0,     0,     0,   160,   161,   162,   163,
     164,   165,     0,   167,   168,     0,   169,   170,   171,   172,
       0,   173,   174,   175,   176,   177,   178,   179,   180,   158,
     181,   159,     0,     0,     0,   160,   161,   162,   163,   164,
     165,     0,     0,     0,     0,   169,   170,   171,   172,     0,
     173,   174,   175,   176,   177,   178,   179,   180,   158,   181,
     159,     0,     0,     0,   160,   161,   162,   163,   164,   165,
       0,     0,     0,     0,     0,   170,   171,   172,     0,   173,
     174,   175,   176,   177,   178,   179,   180,   158,   181,   159,
       0,     0,     0,   160,   161,   162,   163,   164,   165,     0,
       0,     0,     0,     0,   170,     0,   172,     0,   173,   174,
     175,   176,   177,   178,   179,   180,   158,   181,   159,     0,
       0,     0,   160,   161,   162,   163,   164,   165,     0,     0,
       0,     0,     0,   170,     0,     0,     0,   173,   174,   175,
     176,   177,   178,   179,   180,   158,   181,   159,     0,     0,
       0,   160,   161,   162,   163,   164,   165,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   173,   174,   175,   176,
     177,   178,   179,   180,   158,   181,   159,     0,     0,     0,
     160,   161,   162,   163,   164,   165,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   173,   174,     0,     0,   177,
     178,   179,   180,   -99,   181,     0,     0,     0,   196,   197,
     198,   199,   200,   201,   202,     0,     0,     0,   203,   204,
     205,   206,     0,   207,   208,   209,   210,   211,   212,   213,
     214,   196,   197,   198,   199,   200,   201,   202,     0,     0,
       0,   203,   204,   205,   206,     0,   207,   208,   209,   210,
     211,   212,   213,   214,   196,   197,   198,   199,   200,   201,
       0,     0,     0,     0,   203,   204,   205,   206,     0,   207,
     208,   209,   210,   211,   212,   213,   214,   196,   197,   198,
     199,   200,   201,     0,     0,     0,     0,     0,   204,     0,
     206,     0,   207,   208,   209,   210,   211,   212,   213,   214,
     196,   197,   198,   199,   200,   201,     0,     0,     0,     0,
       0,   204,     0,     0,     0,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
       0,     0,     0,   222,   196,   197,   198,   199,   200,   201,
     223,   224,   225,   226,   227,   228,     0,     0,     0,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,     0,     0,     0,     0,   222,     0,     0,
       0,     0,     0,     0,   223,   224,   225,   226,   227,   228
  };

  const short
   Parser ::yycheck_[] =
  {
       8,     8,    10,    11,    12,    33,    66,   247,    14,    76,
       9,   654,   637,     9,     9,   658,     9,     9,    24,    25,
      26,    27,    11,    41,    13,     9,    12,     9,    11,    11,
     628,   629,    11,     3,     4,     5,     6,     7,     8,     9,
      11,    11,   667,    11,    25,     0,    16,    15,     3,    76,
      68,    32,    33,    11,    24,    41,    62,    39,   136,    29,
      11,   686,     0,     1,    76,     3,     4,     5,     6,     7,
       8,     9,     9,    11,    82,    83,    84,    76,    16,    68,
      76,    76,   680,    76,    76,    68,    24,    76,   713,   732,
     733,    29,    76,   736,   737,   738,   739,    68,   104,   127,
     106,   744,   108,    40,   110,    76,    76,    77,   116,     0,
      68,     9,   118,     3,   122,    14,    11,    68,    56,    57,
      58,    59,    12,    61,    62,    63,    64,    65,    66,    67,
      76,    69,    70,    71,    72,    73,    74,     3,    76,    77,
      39,    11,    33,    13,    42,     8,    41,    13,    11,    12,
      40,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,    68,     0,   183,   184,   185,   186,   187,
      11,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   127,    68,   244,   317,
     651,   652,     3,   251,    38,   136,    40,    10,    17,    18,
      19,    12,    12,   116,    12,    12,     9,   265,   266,   122,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,    40,     3,    40,
     286,    41,     9,    41,    41,   696,    76,    77,    13,    12,
      12,   319,     9,    68,   302,    10,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    41,    41,
     183,   184,   185,   186,   187,    11,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    11,    68,    11,    22,    23,   116,    25,   251,    10,
      42,     0,   122,    12,    32,    33,   636,     4,     5,     8,
       9,    10,     9,    40,     9,    30,    31,    42,    62,    16,
      13,    20,     3,     4,     5,     6,     7,     8,     9,     9,
      11,    12,    29,     3,    33,    16,   317,    38,   319,   159,
      55,     4,     5,    24,    14,    44,     9,    37,    29,   302,
      68,    66,    67,    16,   113,    70,    57,    10,    12,    49,
      50,    51,    52,   183,    79,    11,    29,     9,    69,    70,
      71,    72,    13,    74,   133,    76,    77,    68,    77,    76,
      77,    10,    76,    82,    83,    41,    56,    57,    34,    35,
      36,    37,     9,    14,    11,    76,    77,    10,     9,    69,
      70,    71,    72,    20,    74,    10,    76,    77,    11,   229,
      20,    20,    11,     4,     5,     6,     7,     8,     9,    10,
      11,    76,    39,    10,    12,    16,    12,    20,   127,    14,
     580,   251,    21,    24,     3,   134,    25,   136,    29,    20,
      76,   140,    40,    32,    33,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    10,   158,
      42,   160,   161,   162,   163,   164,   165,   166,    15,    16,
      17,    18,    19,    20,     3,    10,   175,   176,   177,   178,
     179,   180,   302,    11,    14,    76,    77,    42,   247,    42,
     189,    12,   590,   591,   592,   593,   594,   196,   197,   198,
     199,   200,   201,   202,    32,    33,    34,    35,    36,    37,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    10,   223,   224,   225,   226,   227,   228,
      10,   230,    10,    10,     3,   294,    10,   655,    10,   238,
      11,     3,   301,    10,    15,   643,    60,    12,   646,     9,
      76,    11,   650,   651,   652,    15,    16,    17,    18,    19,
      20,    32,    33,   262,    21,    22,    23,    12,    25,   268,
     269,   270,   271,   272,   273,    32,    33,    40,    10,    39,
     279,   280,   281,   282,   283,   284,   285,    56,    57,   288,
      12,    39,     4,   691,    38,   693,    64,     9,   696,   696,
      69,    70,    71,    72,    16,    74,   581,    76,    77,   287,
     133,    11,   144,    77,     0,    15,   754,    29,   317,    -1,
     319,    -1,     8,     9,    -1,    25,   341,    -1,    22,   727,
      -1,    25,    32,    33,    20,    -1,   734,   735,    32,    33,
      -1,     4,     5,     6,     7,     8,     9,    33,    11,    12,
      -1,    -1,    25,    16,    -1,    25,    -1,    -1,    44,    32,
      33,    24,    32,    33,    -1,    -1,    29,   382,    -1,   767,
      17,    18,    19,    20,   655,   390,    -1,    -1,    41,    -1,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
     643,    77,    16,   646,    -1,    -1,    -1,   650,   651,   652,
      24,    -1,   417,    -1,   419,    29,   421,    -1,   423,    17,
      18,    19,    20,    76,    77,    -1,   431,    41,    17,    18,
      19,    20,   437,    -1,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    13,    -1,    -1,    16,    -1,   691,    -1,
     693,   127,    -1,   696,    24,    -1,    -1,    -1,   134,    29,
     136,   466,    76,    77,   140,    -1,    -1,    -1,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,    -1,   158,    -1,   727,    -1,     9,    -1,    11,    -1,
     166,   734,   735,   169,    17,    18,    19,    20,    -1,   175,
     176,   177,   178,   179,   180,    -1,    76,    77,    10,    17,
      18,    19,    20,   189,    -1,   520,    39,    -1,    -1,    21,
      22,    23,    -1,    25,   767,    11,   202,    -1,    -1,    -1,
      32,    33,   581,   643,    -1,    21,   646,    -1,    -1,    25,
      -1,    -1,   547,    -1,    -1,   221,    32,    33,    34,    35,
      36,    37,    -1,    -1,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     9,    -1,    11,    -1,   572,    -1,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,   628,
     629,   691,    -1,   693,    30,    31,   262,   636,    -1,    -1,
      -1,   580,    -1,    39,    -1,    -1,    -1,   586,    15,    16,
      17,    18,    19,     4,     5,     6,     7,     8,     9,   285,
      11,    12,   288,    30,    31,    16,    -1,   727,    15,    16,
      17,    18,    19,    24,   734,   735,     0,    -1,    29,    -1,
      11,   680,    -1,    -1,     8,     9,   685,    11,    -1,    -1,
      41,   317,    -1,   319,    25,    -1,    20,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    37,   767,    -1,    33,
      -1,   650,   651,   652,    -1,   654,   655,    -1,   657,   658,
      44,   660,    -1,    -1,    -1,    76,    77,    -1,    -1,     4,
       5,     6,     7,     8,     9,    -1,    11,    10,    -1,    -1,
      -1,    16,    15,    16,    17,    18,    19,    20,    21,    24,
      -1,    -1,    25,    77,    29,    -1,   695,   696,    -1,    32,
      33,    34,    35,    36,    37,    -1,    41,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,   715,    -1,   717,    16,
      15,    16,    17,    18,    19,    20,    -1,    24,    -1,    -1,
      -1,    -1,    29,   732,   733,    30,    31,   736,   737,   738,
     739,    76,    77,   127,    -1,   744,    -1,    -1,    -1,    -1,
     134,    -1,   136,    -1,    -1,    -1,   140,    -1,    -1,    -1,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,    -1,   158,    -1,    -1,    -1,    -1,    76,
      77,    -1,   166,   167,   168,    15,    16,    17,    18,    19,
      20,   175,   176,    -1,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,     0,    -1,   189,    16,    -1,    -1,    -1,
      -1,    -1,     9,    -1,    24,    -1,    10,    11,   202,    29,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    33,   221,    32,    33,
      34,    35,    36,    37,    10,    -1,   230,    44,    -1,    15,
      16,    17,    18,    19,   238,   239,   240,    -1,   242,   243,
      26,    27,    28,    -1,    30,    31,    76,    77,    -1,    -1,
      -1,    -1,     4,     5,     6,     7,     8,     9,   262,    11,
      77,    -1,    -1,    -1,    16,    -1,    15,    16,    17,    18,
      19,    20,    24,    -1,   580,    -1,    -1,    29,    -1,    -1,
     586,   285,    -1,    -1,   288,    34,    35,    36,    37,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    10,    -1,
      -1,    16,    -1,    15,    16,    17,    18,    19,    20,    24,
     127,    -1,    -1,   317,    29,   319,    -1,   134,    -1,   136,
      -1,    -1,    -1,   140,    76,    77,    -1,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
      -1,   158,    -1,   160,   650,   651,   652,    -1,   654,   655,
      -1,   657,   658,    -1,   660,    -1,    -1,    -1,   175,   176,
      -1,    76,    77,    -1,    -1,    -1,    -1,   184,   185,   186,
     187,    -1,    -1,   190,    -1,    10,   193,    -1,    -1,     0,
      15,    16,    17,    18,    19,    20,   203,    -1,     9,   695,
     696,    26,    27,    28,    -1,    30,    31,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,   715,
      -1,   717,    33,    10,   231,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,   241,    -1,   732,   733,    -1,    -1,
     736,   737,   738,   739,    -1,    -1,    -1,    -1,   744,     4,
       5,     6,     7,     8,     9,   262,    11,    12,    -1,    -1,
      -1,    16,    -1,    -1,    -1,    -1,    77,    -1,    -1,    24,
      57,    -1,    -1,    -1,    29,    -1,    -1,    -1,   285,    -1,
      -1,   288,    69,    70,    71,    72,    -1,    74,    -1,    76,
      77,    -1,    -1,     9,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    -1,    20,    -1,    16,    -1,    -1,    10,
     317,    -1,   319,    -1,    24,    -1,   127,    -1,    -1,    29,
      -1,    76,    77,   134,    -1,   136,    -1,    -1,    -1,   140,
      -1,    -1,    -1,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,    -1,   158,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   166,    57,    -1,    -1,    -1,
      -1,    77,    -1,    -1,   175,   176,    76,    77,    69,    70,
      71,    72,    -1,    74,    -1,    76,    77,    -1,   189,    -1,
     191,   192,    -1,    -1,    -1,    -1,   580,    -1,    -1,    -1,
      -1,   202,   586,    -1,    -1,     4,     5,     6,     7,     8,
       9,    -1,    11,    -1,    -1,    -1,    -1,    16,    -1,    -1,
     221,    -1,    -1,    -1,    -1,    24,    -1,    -1,   134,   230,
      29,    -1,    -1,    -1,   140,    -1,    -1,   238,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,    -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   262,    -1,    -1,    -1,    -1,   650,   651,   652,    -1,
     654,   655,    -1,   657,   658,    -1,   660,    76,    77,    -1,
      -1,    -1,    -1,    -1,   285,    -1,    -1,   288,    -1,    -1,
       0,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      -1,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
      20,   695,   696,    16,    -1,    -1,   317,    -1,   319,    -1,
      -1,    24,    -1,    33,    -1,    -1,    29,    -1,    -1,    -1,
      -1,   715,    -1,   717,    44,     0,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    -1,   732,   733,
      -1,    16,   736,   737,   738,   739,   262,    -1,    -1,    24,
     744,    -1,    -1,    -1,    29,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    76,    77,    -1,    -1,    -1,    -1,   285,
      -1,    -1,   288,   580,    -1,    -1,    -1,    -1,    -1,   586,
      -1,    56,    57,    58,    59,    -1,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      -1,    76,    77,    -1,    -1,    -1,    -1,   127,    -1,    -1,
      -1,    -1,    -1,    -1,   134,    -1,   136,    -1,    10,    -1,
     140,    -1,    -1,    -1,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,    -1,   158,    -1,
      -1,    -1,    -1,   650,   651,   652,    38,   654,   655,    57,
     657,   658,    -1,   660,    -1,   175,   176,    -1,    -1,    -1,
      -1,    69,    70,    71,    72,    57,    74,    -1,    76,    77,
      -1,    -1,    -1,    -1,   194,   195,    -1,    69,    70,    71,
      72,    -1,    74,    -1,    76,    77,    -1,    -1,   695,    -1,
      -1,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    57,    14,    -1,    16,    -1,   715,    -1,
     717,    -1,    -1,    -1,    24,    69,    70,    71,    72,    29,
      74,    -1,    76,    77,    -1,   732,   733,    -1,    -1,   736,
     737,   738,   739,    -1,    -1,    -1,    -1,   744,    -1,    -1,
      -1,    -1,   262,    10,    -1,    -1,    56,    57,    58,    59,
      -1,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,   285,    76,    77,   288,   580,
       0,    38,    -1,     3,    -1,   586,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      57,    30,    31,    -1,    -1,    -1,    -1,   317,    -1,   319,
      -1,    -1,    69,    70,    71,    72,    -1,    74,    -1,    76,
      77,    -1,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   650,
     651,   652,    -1,   654,   655,    -1,   657,   658,    -1,   660,
       9,    -1,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    -1,    22,   580,    -1,    25,    26,    27,    28,
     586,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      39,    -1,    -1,    -1,   695,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    -1,    -1,    14,   715,    16,   717,    -1,    15,    16,
      17,    18,    19,    24,    -1,    -1,    -1,    -1,    29,    26,
      -1,   732,   733,    30,    31,   736,   737,   738,   739,    -1,
      -1,    -1,    -1,   744,   650,   651,   652,    -1,    -1,    -1,
      -1,   657,    -1,    -1,   660,    56,    57,    58,    59,    -1,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    -1,    76,    77,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    -1,    13,    -1,   695,
      16,    15,    16,    17,    18,    19,    -1,    -1,    24,    -1,
      -1,    -1,    26,    29,    28,    -1,    30,    31,    -1,   715,
      -1,   717,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    -1,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    -1,
      76,    77,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    -1,    -1,    14,    -1,    16,    -1,    -1,    -1,    -1,
     580,    -1,    -1,    24,    10,    -1,   586,    -1,    29,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    25,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    56,    57,    58,    59,    -1,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    -1,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     650,   651,   652,    -1,   654,   655,    -1,   657,   658,    -1,
     660,     9,    10,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    25,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    39,    -1,    -1,    -1,   695,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    -1,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    -1,   715,    -1,   717,    24,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    15,    16,    17,    18,
      19,    20,   732,   733,    -1,    -1,   736,   737,   738,   739,
      -1,    30,    31,    -1,   744,    34,    35,    36,    37,    -1,
      56,    57,    58,    59,    -1,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    -1,
      76,    77,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,     9,    39,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    25,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
       9,    39,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    -1,    25,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,     9,
      39,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    25,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,     9,    39,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,     9,    39,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,     9,    39,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,     9,    39,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,     9,    39,    11,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    34,
      35,    36,    37,    10,    39,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    25,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    25,    26,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    25,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,    -1,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    25,    15,    16,    17,    18,    19,    20,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    37
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     0,     3,     4,     5,     6,     7,     8,     9,    11,
      16,    24,    29,    56,    57,    58,    59,    61,    62,    63,
      64,    65,    66,    67,    69,    70,    71,    72,    73,    74,
      76,    77,    80,    81,    83,    84,    87,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    99,   101,   104,   108,
     109,   110,   112,   113,   114,   116,   120,   121,   124,   125,
     126,   127,   128,   130,   132,     8,    76,    77,   113,   114,
     116,   120,   121,   124,   125,   126,   127,     3,    12,    76,
     112,   115,     9,    16,    29,    76,    77,   124,   125,   113,
     124,   125,   126,   127,   113,   124,   127,    76,    11,   131,
      76,    88,   112,    76,    68,   131,    68,   131,    68,   131,
      68,   131,    76,     9,    76,   105,    11,    13,    68,   119,
     122,   131,    11,    68,   119,     0,     0,     1,    83,     0,
       3,    82,    82,     9,     9,     3,    13,    84,    85,    86,
       9,    82,    82,    82,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    54,    55,    82,     9,    11,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    25,
      26,    27,    28,    30,    31,    32,    33,    34,    35,    36,
      37,    39,   119,    11,    15,    25,    32,    33,   119,    21,
      25,    32,    33,    25,    32,    33,    15,    16,    17,    18,
      19,    20,    21,    25,    26,    27,    28,    30,    31,    32,
      33,    34,    35,    36,    37,    15,    16,    17,    18,    19,
      20,    21,    25,    32,    33,    34,    35,    36,    37,    11,
      21,    25,    32,    33,    34,    35,    36,    37,    21,    22,
      23,    25,    32,    33,    68,   131,    68,     9,    76,   105,
      10,    11,   122,    10,    10,    10,    10,    10,    10,   115,
       3,    12,    40,   124,   125,     9,    16,   124,    15,    16,
      17,    18,    19,    20,    26,    27,    28,    30,    31,    15,
      16,    17,    18,    19,    20,    42,    12,    40,    42,   131,
     131,   131,   131,     3,    13,    10,    74,    76,    77,   129,
     132,     9,    41,   113,   118,   124,    14,    39,   123,   131,
     118,    83,    76,    77,   108,   132,   112,    13,    14,    81,
      62,   112,   110,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,    10,   111,   112,   118,
     113,   116,   124,   125,   113,   124,   125,   113,   124,   125,
     113,   124,   125,   113,   124,   125,   113,   124,   125,   113,
     120,   124,   125,   126,   127,   113,   127,   113,   127,   113,
     126,   113,   124,   113,   124,   113,   124,   113,   124,   113,
     124,   113,   116,   120,   121,   124,   125,   126,   127,   113,
     116,   120,   121,   124,   125,   126,   127,   113,   124,   125,
     126,   113,   124,   125,   126,   113,   124,   125,   126,   113,
     124,   125,   126,    76,    77,   118,   113,   116,   113,   116,
     113,   116,   113,   116,   113,   120,   124,   125,   126,   127,
     113,   116,   113,   120,   113,   120,   113,   116,   113,   121,
     113,   121,   113,   124,   125,   113,   124,   125,   113,   124,
     125,   113,   124,   125,   113,   124,   125,   113,   125,   113,
     120,   124,   125,   126,   127,   113,   116,   113,   124,   113,
     124,   113,   124,   113,   124,   113,   124,   113,   124,   125,
     113,   124,   125,   113,   124,   125,   113,   124,   125,   113,
     124,   125,   113,   124,   125,   113,   124,   125,   113,   124,
     125,   113,   124,   125,   113,   124,   125,   113,   124,   125,
     113,   124,   125,   113,   120,   124,   125,   126,   127,   113,
     116,   113,   124,   125,   113,   124,   125,   113,   124,   125,
     113,   124,   125,   113,   124,   125,   113,   124,   125,   118,
     113,   120,   124,   125,   126,   127,   113,   116,   126,   113,
     126,   113,   126,   113,   126,   113,   126,   113,   126,   113,
     126,   113,   120,   124,   125,   126,   127,   113,   127,   113,
     127,   113,   116,   113,   127,   113,   127,   131,    10,   129,
      42,     9,    10,     3,    12,    12,     3,   112,   124,   124,
      15,    16,    17,    18,    19,   124,   125,   124,   125,   124,
     125,   124,   125,   124,   125,   124,   125,   124,   124,   124,
     124,   124,   124,   125,   124,   125,   124,   125,   124,   125,
     124,   125,   124,   125,   112,   131,    88,   112,    13,     3,
      14,    56,   102,   103,   132,    10,    40,    10,    38,   106,
     107,   132,    12,    41,   118,    12,    41,    76,    14,    12,
      41,    41,    41,    76,    10,    81,    14,     9,    10,    10,
      40,    12,    12,    12,    10,   112,   122,    10,   107,    12,
     112,   124,   124,   124,   124,   124,   102,   102,    76,    14,
       3,    76,   129,    85,    76,    40,    10,    76,    12,   118,
      12,    41,    12,    41,   118,    42,     9,   112,   113,   117,
     118,   124,   112,   117,   112,   117,    86,    14,     3,   112,
      86,   112,    85,    10,    14,    42,   102,    42,    38,   132,
      85,    12,    12,   118,    12,   118,    12,    41,   112,   113,
     117,   124,    10,    10,    38,    40,    10,    10,    10,    10,
       3,    10,    60,    98,   100,    85,   112,   112,    76,    76,
      12,    12,    12,   118,    40,    10,    86,    86,   118,   118,
      86,    86,    86,    86,    86,    12,   123,    38,   118
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    79,    80,    80,    81,    81,    81,    82,    82,    83,
      83,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    85,    85,    85,    85,    85,    86,    86,
      87,    88,    88,    89,    89,    89,    90,    90,    91,    91,
      91,    91,    91,    91,    92,    93,    94,    95,    96,    97,
      98,    98,    99,   100,   101,   101,   101,   102,   102,   102,
     102,   103,   103,   103,   104,   104,   104,   104,   105,   106,
     106,   107,   107,   107,   108,   109,   109,   109,   109,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   111,   111,   112,   112,   112,   112,   112,
     112,   112,   112,   113,   113,   113,   113,   113,   113,   113,
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
     127,   127,   127,   128,   128,   128,   128,   129,   129,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   131,   131,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132
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
       4,     4,     4,     4,     4,     2,     2,     2,     2,     3,
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
       3,     3,     3,     2,     2,     3,     3,     3,     3,     3,
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
       3,     3,     3,     4,     3,     4,     3,     1,     3,     2,
       2,     2,     2,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     2,     3,     2,     2,     2,     2,     2,     2,
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
  "stmts", "stmts_ne", "block", "scope_body", "import", "id_list",
  "flowctl", "return", "for", "for_kw", "while", "wh_kw", "dowhile",
  "do_kw", "if", "else", "if_kw", "el_kw", "struct", "decllist",
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
       0,   230,   230,   231,   233,   234,   235,   238,   239,   242,
     243,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   260,   261,   262,   263,   264,   267,   268,
     272,   274,   275,   279,   280,   281,   283,   284,   288,   289,
     290,   291,   292,   293,   295,   298,   300,   302,   304,   307,
     309,   310,   312,   313,   316,   317,   318,   320,   321,   322,
     323,   325,   326,   327,   331,   332,   333,   334,   336,   338,
     339,   341,   342,   343,   348,   352,   353,   354,   355,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   376,   377,   381,   382,   383,   384,   385,
     386,   387,   388,   391,   392,   393,   394,   395,   397,   398,
     400,   401,   402,   403,   404,   406,   407,   408,   409,   411,
     412,   415,   416,   417,   418,   419,   421,   422,   423,   424,
     425,   427,   428,   429,   430,   431,   433,   434,   435,   436,
     437,   439,   440,   441,   442,   443,   444,   445,   446,   448,
     449,   450,   451,   452,   454,   455,   456,   458,   459,   460,
     462,   463,   464,   465,   466,   467,   468,   470,   471,   472,
     473,   474,   475,   476,   478,   479,   480,   481,   482,   483,
     484,   486,   487,   488,   489,   490,   491,   492,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   530,   531,   532,   534,   535,   536,   538,   539,
     540,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   559,   560,   561,
     563,   564,   565,   567,   569,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   585,   586,   587,   588,
     589,   592,   593,   594,   598,   599,   601,   602,   603,   605,
     606,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   623,   624,   628,   629,   631,   632,   634,
     635,   639,   640,   641,   642,   643,   644,   645,   646,   647,
     648,   649,   650,   651,   652,   656,   657,   658,   659,   660,
     661,   662,   663,   664,   665,   666,   667,   668,   669,   670,
     671,   672,   673,   674,   675,   676,   680,   681,   682,   683,
     684,   685,   686,   687,   688,   689,   690,   691,   692,   693,
     694,   695,   696,   697,   698,   699,   700,   701,   702,   703,
     704,   705,   706,   710,   711,   712,   713,   714,   716,   717,
     718,   719,   720,   721,   722,   724,   725,   726,   727,   728,
     729,   730,   732,   733,   734,   735,   736,   738,   739,   740,
     741,   742,   744,   745,   746,   747,   748,   750,   751,   752,
     753,   754,   756,   760,   761,   762,   763,   765,   766,   770,
     771,   772,   773,   774,   775,   776,   777,   778,   779,   780,
     781,   782,   784,   786,   791,   792,   793,   794,   795,   796,
     797,   798,   799,   800,   801,   802,   803,   804,   805,   806,
     807
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
#line 4896 "frontend/parser.cpp"

#line 810 "frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    auto msg = std::to_string(scanner->llvmloc->begin.line) + ":" + std::to_string(scanner->llvmloc->begin.column) + ": " + err_message;
    scanner->fatal_error(ptc::diag::ERR_SYNTAX, msg);
}
