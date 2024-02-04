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
#line 48 "frontend/parser.yy"


    #include <map>
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

#line 62 "frontend/parser.cpp"


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
#line 155 "frontend/parser.cpp"

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
      case symbol_kind::S_slice: // slice
      case symbol_kind::S_expr_none: // expr_none
      case symbol_kind::S_expr_struct: // expr_struct
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
      case symbol_kind::S_funtype: // funtype
      case symbol_kind::S_mattype: // mattype
      case symbol_kind::S_type: // type
        value.copy< ptc::ir::IR * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_val: // struct_val
      case symbol_kind::S_struct_list: // struct_list
        value.copy< std::map<std::string, ptc::ir::Expr *>  > (YY_MOVE (that.value));
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
      case symbol_kind::S_typelist: // typelist
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
      case symbol_kind::S_slice: // slice
      case symbol_kind::S_expr_none: // expr_none
      case symbol_kind::S_expr_struct: // expr_struct
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
      case symbol_kind::S_funtype: // funtype
      case symbol_kind::S_mattype: // mattype
      case symbol_kind::S_type: // type
        value.move< ptc::ir::IR * > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_struct_val: // struct_val
      case symbol_kind::S_struct_list: // struct_list
        value.move< std::map<std::string, ptc::ir::Expr *>  > (YY_MOVE (s.value));
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
      case symbol_kind::S_typelist: // typelist
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
      case symbol_kind::S_slice: // slice
      case symbol_kind::S_expr_none: // expr_none
      case symbol_kind::S_expr_struct: // expr_struct
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
      case symbol_kind::S_funtype: // funtype
      case symbol_kind::S_mattype: // mattype
      case symbol_kind::S_type: // type
        value.YY_MOVE_OR_COPY< ptc::ir::IR * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_val: // struct_val
      case symbol_kind::S_struct_list: // struct_list
        value.YY_MOVE_OR_COPY< std::map<std::string, ptc::ir::Expr *>  > (YY_MOVE (that.value));
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
      case symbol_kind::S_typelist: // typelist
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
      case symbol_kind::S_slice: // slice
      case symbol_kind::S_expr_none: // expr_none
      case symbol_kind::S_expr_struct: // expr_struct
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
      case symbol_kind::S_funtype: // funtype
      case symbol_kind::S_mattype: // mattype
      case symbol_kind::S_type: // type
        value.move< ptc::ir::IR * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_val: // struct_val
      case symbol_kind::S_struct_list: // struct_list
        value.move< std::map<std::string, ptc::ir::Expr *>  > (YY_MOVE (that.value));
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
      case symbol_kind::S_typelist: // typelist
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
      case symbol_kind::S_slice: // slice
      case symbol_kind::S_expr_none: // expr_none
      case symbol_kind::S_expr_struct: // expr_struct
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
      case symbol_kind::S_funtype: // funtype
      case symbol_kind::S_mattype: // mattype
      case symbol_kind::S_type: // type
        value.copy< ptc::ir::IR * > (that.value);
        break;

      case symbol_kind::S_struct_val: // struct_val
      case symbol_kind::S_struct_list: // struct_list
        value.copy< std::map<std::string, ptc::ir::Expr *>  > (that.value);
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
      case symbol_kind::S_typelist: // typelist
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
      case symbol_kind::S_slice: // slice
      case symbol_kind::S_expr_none: // expr_none
      case symbol_kind::S_expr_struct: // expr_struct
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
      case symbol_kind::S_funtype: // funtype
      case symbol_kind::S_mattype: // mattype
      case symbol_kind::S_type: // type
        value.move< ptc::ir::IR * > (that.value);
        break;

      case symbol_kind::S_struct_val: // struct_val
      case symbol_kind::S_struct_list: // struct_list
        value.move< std::map<std::string, ptc::ir::Expr *>  > (that.value);
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
      case symbol_kind::S_typelist: // typelist
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
      case symbol_kind::S_slice: // slice
      case symbol_kind::S_expr_none: // expr_none
      case symbol_kind::S_expr_struct: // expr_struct
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
      case symbol_kind::S_funtype: // funtype
      case symbol_kind::S_mattype: // mattype
      case symbol_kind::S_type: // type
        yylhs.value.emplace< ptc::ir::IR * > ();
        break;

      case symbol_kind::S_struct_val: // struct_val
      case symbol_kind::S_struct_list: // struct_list
        yylhs.value.emplace< std::map<std::string, ptc::ir::Expr *>  > ();
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
      case symbol_kind::S_typelist: // typelist
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
#line 241 "frontend/parser.yy"
                        { scanner->parseEntry(std::vector<ptc::ir::IR *>{}); }
#line 1239 "frontend/parser.cpp"
    break;

  case 3: // start: stmt "end of file"
#line 242 "frontend/parser.yy"
                        { scanner->parseEntry(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1245 "frontend/parser.cpp"
    break;

  case 4: // stmt: stmts
#line 244 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1251 "frontend/parser.cpp"
    break;

  case 5: // stmt: stmt stmts
#line 245 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1257 "frontend/parser.cpp"
    break;

  case 6: // stmt: stmt error stmts
#line 246 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1263 "frontend/parser.cpp"
    break;

  case 9: // stmts: "terminator (\\n or ;)"
#line 253 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = nullptr; }
#line 1269 "frontend/parser.cpp"
    break;

  case 10: // stmts: stmts_ne
#line 254 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1275 "frontend/parser.cpp"
    break;

  case 11: // stmts_ne: set stmt_end
#line 256 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1281 "frontend/parser.cpp"
    break;

  case 12: // stmts_ne: vardecl stmt_end
#line 257 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1287 "frontend/parser.cpp"
    break;

  case 13: // stmts_ne: vardef stmt_end
#line 258 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1293 "frontend/parser.cpp"
    break;

  case 14: // stmts_ne: import stmt_end
#line 259 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1299 "frontend/parser.cpp"
    break;

  case 15: // stmts_ne: for
#line 260 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1305 "frontend/parser.cpp"
    break;

  case 16: // stmts_ne: if
#line 261 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1311 "frontend/parser.cpp"
    break;

  case 17: // stmts_ne: while
#line 262 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1317 "frontend/parser.cpp"
    break;

  case 18: // stmts_ne: dowhile
#line 263 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1323 "frontend/parser.cpp"
    break;

  case 19: // stmts_ne: struct
#line 264 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1329 "frontend/parser.cpp"
    break;

  case 20: // stmts_ne: function
#line 265 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1335 "frontend/parser.cpp"
    break;

  case 21: // stmts_ne: flowctl stmt_end
#line 266 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1341 "frontend/parser.cpp"
    break;

  case 22: // stmts_ne: expr stmt_end
#line 267 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1347 "frontend/parser.cpp"
    break;

  case 23: // block: "{" "}"
#line 271 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1353 "frontend/parser.cpp"
    break;

  case 24: // block: "{" stmt "}"
#line 272 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1359 "frontend/parser.cpp"
    break;

  case 25: // block: "terminator (\\n or ;)" "{" stmt "}"
#line 273 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1365 "frontend/parser.cpp"
    break;

  case 26: // block: "{" stmt "}" "terminator (\\n or ;)"
#line 274 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1371 "frontend/parser.cpp"
    break;

  case 27: // block: "terminator (\\n or ;)" "{" stmt "}" "terminator (\\n or ;)"
#line 275 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1377 "frontend/parser.cpp"
    break;

  case 28: // scope_body: stmts_ne
#line 278 "frontend/parser.yy"
                      { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); scanner->leaveScope(); }
#line 1383 "frontend/parser.cpp"
    break;

  case 29: // scope_body: block
#line 279 "frontend/parser.yy"
                      { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); scanner->leaveScope(); }
#line 1389 "frontend/parser.cpp"
    break;

  case 30: // import: "import" id_list
#line 283 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::IR * > () = scanner->parseImports(yystack_[0].value.as < std::vector<std::string>  > ()); }
#line 1395 "frontend/parser.cpp"
    break;

  case 31: // id_list: "identifier"
#line 285 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseImportName(yystack_[0].value.as < std::string > ()); }
#line 1401 "frontend/parser.cpp"
    break;

  case 32: // id_list: "identifier" "," id_list
#line 286 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseAddImportName(yystack_[0].value.as < std::vector<std::string>  > (), yystack_[2].value.as < std::string > ()); }
#line 1407 "frontend/parser.cpp"
    break;

  case 33: // flowctl: "break"
#line 290 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseBreak(); }
#line 1413 "frontend/parser.cpp"
    break;

  case 34: // flowctl: "continue"
#line 291 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseContinue(); }
#line 1419 "frontend/parser.cpp"
    break;

  case 35: // flowctl: return
#line 292 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1425 "frontend/parser.cpp"
    break;

  case 36: // return: "return"
#line 294 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(nullptr); }
#line 1431 "frontend/parser.cpp"
    break;

  case 37: // return: "return" expr
#line 295 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1437 "frontend/parser.cpp"
    break;

  case 38: // for: for_kw "(" vardecl ":" expr ")" scope_body
#line 299 "frontend/parser.yy"
                                                      { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1443 "frontend/parser.cpp"
    break;

  case 39: // for: for_kw "(" "identifier" ":" expr ")" scope_body
#line 300 "frontend/parser.yy"
                                                      { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1449 "frontend/parser.cpp"
    break;

  case 40: // for: for_kw "(" "external identifier" ":" expr ")" scope_body
#line 301 "frontend/parser.yy"
                                                      { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1455 "frontend/parser.cpp"
    break;

  case 41: // for: for_kw "(" vardecl ":" range ")" scope_body
#line 302 "frontend/parser.yy"
                                                      { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1461 "frontend/parser.cpp"
    break;

  case 42: // for: for_kw "(" "identifier" ":" range ")" scope_body
#line 303 "frontend/parser.yy"
                                                      { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1467 "frontend/parser.cpp"
    break;

  case 43: // for: for_kw "(" "external identifier" ":" range ")" scope_body
#line 304 "frontend/parser.yy"
                                                      { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1473 "frontend/parser.cpp"
    break;

  case 44: // for_kw: "for"
#line 306 "frontend/parser.yy"
               { scanner->enterBlockScope(); }
#line 1479 "frontend/parser.cpp"
    break;

  case 45: // while: wh_kw "(" expr ")" scope_body
#line 309 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseWhile(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1485 "frontend/parser.cpp"
    break;

  case 46: // wh_kw: "while"
#line 311 "frontend/parser.yy"
                { scanner->enterBlockScope(); }
#line 1491 "frontend/parser.cpp"
    break;

  case 47: // dowhile: do_kw scope_body "while" "(" expr ")"
#line 313 "frontend/parser.yy"
                                                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseDoWhile(yystack_[1].value.as < ptc::ir::Expr * > (), yystack_[4].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1497 "frontend/parser.cpp"
    break;

  case 48: // do_kw: "do"
#line 315 "frontend/parser.yy"
             { scanner->enterBlockScope(); }
#line 1503 "frontend/parser.cpp"
    break;

  case 49: // if: if_kw "(" expr ")" scope_body else
#line 318 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseIfStmt(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1509 "frontend/parser.cpp"
    break;

  case 50: // else: el_kw scope_body
#line 320 "frontend/parser.yy"
                         { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1515 "frontend/parser.cpp"
    break;

  case 51: // else: %empty
#line 321 "frontend/parser.yy"
                         { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1521 "frontend/parser.cpp"
    break;

  case 52: // if_kw: "if"
#line 323 "frontend/parser.yy"
             { scanner->enterBlockScope(); }
#line 1527 "frontend/parser.cpp"
    break;

  case 53: // el_kw: "else"
#line 324 "frontend/parser.yy"
               { scanner->enterBlockScope(); }
#line 1533 "frontend/parser.cpp"
    break;

  case 54: // struct: "'struct'" "identifier" "{" "}"
#line 327 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[2].value.as < std::string > (), std::vector<ptc::ir::IR *>{}); }
#line 1539 "frontend/parser.cpp"
    break;

  case 55: // struct: "'struct'" "identifier" "{" decllist "}"
#line 328 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1545 "frontend/parser.cpp"
    break;

  case 56: // struct: "'struct'" "identifier" "terminator (\\n or ;)" "{" decllist "}"
#line 329 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[4].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1551 "frontend/parser.cpp"
    break;

  case 58: // decllist: "terminator (\\n or ;)" decllist
#line 332 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1557 "frontend/parser.cpp"
    break;

  case 59: // decllist: declistval "terminator (\\n or ;)"
#line 333 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[1].value.as < ptc::ir::IR * > (), std::vector<ptc::ir::IR *>{}); }
#line 1563 "frontend/parser.cpp"
    break;

  case 60: // decllist: declistval "terminator (\\n or ;)" decllist
#line 334 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[2].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1569 "frontend/parser.cpp"
    break;

  case 61: // declistval: type "identifier"
#line 336 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > (), nullptr); }
#line 1575 "frontend/parser.cpp"
    break;

  case 62: // declistval: type "identifier" "=" expr
#line 337 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1581 "frontend/parser.cpp"
    break;

  case 63: // function: type fun_id "(" ")" block
#line 341 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1587 "frontend/parser.cpp"
    break;

  case 64: // function: type fun_id "(" funargs ")" block
#line 342 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[5].value.as < ptc::ir::IR * > (), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1593 "frontend/parser.cpp"
    break;

  case 65: // function: "'void'" fun_id "(" ")" block
#line 343 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup(VOID_CSTR), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1599 "frontend/parser.cpp"
    break;

  case 66: // function: "'void'" fun_id "(" funargs ")" block
#line 344 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup(VOID_CSTR), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1605 "frontend/parser.cpp"
    break;

  case 67: // fun_id: "identifier"
#line 346 "frontend/parser.yy"
            { scanner->enterFunScope(); yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1611 "frontend/parser.cpp"
    break;

  case 68: // funargsnvar: type "identifier"
#line 348 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseFunParam(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1617 "frontend/parser.cpp"
    break;

  case 69: // funargsnvar: funargsnvar "," type "identifier"
#line 349 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseAddFunParam(yystack_[3].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1623 "frontend/parser.cpp"
    break;

  case 70: // funargs: ".." "identifier"
#line 351 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseFunParam(scanner->sym_lookup(VARARGS_CSTR, false, true), yystack_[0].value.as < std::string > ()); }
#line 1629 "frontend/parser.cpp"
    break;

  case 71: // funargs: funargsnvar "," ".." "identifier"
#line 352 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseAddFunParam(yystack_[3].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), scanner->sym_lookup(VARARGS_CSTR, false, true), yystack_[0].value.as < std::string > ());}
#line 1635 "frontend/parser.cpp"
    break;

  case 72: // funargs: funargsnvar
#line 353 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = yystack_[0].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (); }
#line 1641 "frontend/parser.cpp"
    break;

  case 73: // vardecl: type "identifier"
#line 358 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1647 "frontend/parser.cpp"
    break;

  case 74: // vardef: type "identifier" "=" expr
#line 362 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1653 "frontend/parser.cpp"
    break;

  case 75: // vardef: "var" "identifier" "=" expr
#line 363 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(nullptr, yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1659 "frontend/parser.cpp"
    break;

  case 76: // set: expr "++=" expr
#line 369 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1665 "frontend/parser.cpp"
    break;

  case 77: // set: expr "**=" expr
#line 370 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1671 "frontend/parser.cpp"
    break;

  case 78: // set: expr "%=" expr
#line 371 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1677 "frontend/parser.cpp"
    break;

  case 79: // set: expr "/=" expr
#line 372 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1683 "frontend/parser.cpp"
    break;

  case 80: // set: expr "*=" expr
#line 373 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1689 "frontend/parser.cpp"
    break;

  case 81: // set: expr "-=" expr
#line 374 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1695 "frontend/parser.cpp"
    break;

  case 82: // set: expr "+=" expr
#line 375 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1701 "frontend/parser.cpp"
    break;

  case 83: // set: expr "&=" expr
#line 376 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1707 "frontend/parser.cpp"
    break;

  case 84: // set: expr "|=" expr
#line 377 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1713 "frontend/parser.cpp"
    break;

  case 85: // set: expr "^=" expr
#line 378 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1719 "frontend/parser.cpp"
    break;

  case 86: // set: expr "<<=" expr
#line 379 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1725 "frontend/parser.cpp"
    break;

  case 87: // set: expr ">>=" expr
#line 380 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1731 "frontend/parser.cpp"
    break;

  case 88: // set: expr "=" expr
#line 381 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1737 "frontend/parser.cpp"
    break;

  case 89: // set: expr "=" set
#line 382 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1743 "frontend/parser.cpp"
    break;

  case 90: // callarglist: expr
#line 386 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseFunCallArg(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1749 "frontend/parser.cpp"
    break;

  case 91: // callarglist: callarglist "," expr
#line 387 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddFunCallArg(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1755 "frontend/parser.cpp"
    break;

  case 92: // expr: expr_mat
#line 391 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1761 "frontend/parser.cpp"
    break;

  case 93: // expr: expr_var
#line 392 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1767 "frontend/parser.cpp"
    break;

  case 94: // expr: expr_none
#line 393 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1773 "frontend/parser.cpp"
    break;

  case 95: // expr: expr_struct
#line 394 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1779 "frontend/parser.cpp"
    break;

  case 96: // expr: expr_int
#line 395 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 1785 "frontend/parser.cpp"
    break;

  case 97: // expr: expr_float
#line 396 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFloat(yystack_[0].value.as < double > ()); }
#line 1791 "frontend/parser.cpp"
    break;

  case 98: // expr: expr_str
#line 397 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseString(yystack_[0].value.as < std::string > ()); }
#line 1797 "frontend/parser.cpp"
    break;

  case 99: // expr: expr_bool
#line 398 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseBool(yystack_[0].value.as < bool > ()); }
#line 1803 "frontend/parser.cpp"
    break;

  case 100: // expr_var: "identifier"
#line 401 "frontend/parser.yy"
              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > ()); }
#line 1809 "frontend/parser.cpp"
    break;

  case 101: // expr_var: "external identifier"
#line 402 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > (), true); }
#line 1815 "frontend/parser.cpp"
    break;

  case 102: // expr_var: "(" expr_var ")"
#line 404 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1821 "frontend/parser.cpp"
    break;

  case 103: // expr_var: expr_var "(" ")"
#line 406 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[2].value.as < ptc::ir::Expr * > (), std::vector<ptc::ir::Expr *>{}); }
#line 1827 "frontend/parser.cpp"
    break;

  case 104: // expr_var: expr_var "(" callarglist ")"
#line 407 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 1833 "frontend/parser.cpp"
    break;

  case 105: // expr_var: "-" "identifier"
#line 409 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1839 "frontend/parser.cpp"
    break;

  case 106: // expr_var: "-" "external identifier"
#line 410 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > (), true), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1845 "frontend/parser.cpp"
    break;

  case 107: // expr_var: expr_str "[" int_val "]"
#line 412 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1851 "frontend/parser.cpp"
    break;

  case 108: // expr_var: expr_mat "[" int_val "]"
#line 413 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1857 "frontend/parser.cpp"
    break;

  case 109: // expr_var: "identifier" "[" int_val "]"
#line 414 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1863 "frontend/parser.cpp"
    break;

  case 110: // expr_var: "external identifier" "[" int_val "]"
#line 415 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1869 "frontend/parser.cpp"
    break;

  case 111: // expr_var: expr_var "[" int_val "]"
#line 416 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1875 "frontend/parser.cpp"
    break;

  case 112: // expr_var: "identifier" "as" "external identifier"
#line 418 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > ()), scanner->parseVar(scanner->parseExtType(yystack_[0].value.as < std::string > (), false)->getName(), true, false), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1881 "frontend/parser.cpp"
    break;

  case 113: // expr_var: "external identifier" "as" "external identifier"
#line 419 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > (), true), scanner->parseVar(scanner->parseExtType(yystack_[0].value.as < std::string > (), false)->getName(), true, false), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1887 "frontend/parser.cpp"
    break;

  case 114: // expr_var: expr_var "as" "external identifier"
#line 420 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseVar(scanner->parseExtType(yystack_[0].value.as < std::string > (), false)->getName(), true, false), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1893 "frontend/parser.cpp"
    break;

  case 115: // expr_var: "identifier" "as" "external identifier" "?"
#line 421 "frontend/parser.yy"
                                      { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), scanner->parseVar(scanner->parseExtType(yystack_[1].value.as < std::string > (), true)->getName(), true, true), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1899 "frontend/parser.cpp"
    break;

  case 116: // expr_var: "external identifier" "as" "external identifier" "?"
#line 422 "frontend/parser.yy"
                                      { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > (), true), scanner->parseVar(scanner->parseExtType(yystack_[1].value.as < std::string > (), true)->getName(), true, true), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1905 "frontend/parser.cpp"
    break;

  case 117: // expr_var: expr_var "as" "external identifier" "?"
#line 423 "frontend/parser.yy"
                                      { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), scanner->parseVar(scanner->parseExtType(yystack_[1].value.as < std::string > (), true)->getName(), true, true), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1911 "frontend/parser.cpp"
    break;

  case 118: // expr_var: "identifier" "as" type
#line 424 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > ()), scanner->parseVar(yystack_[0].value.as < ptc::ir::IR * > ()->getName(), false, llvm::dyn_cast<ptc::ir::TypeDecl>(yystack_[0].value.as < ptc::ir::IR * > ())->isMaybe()), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1917 "frontend/parser.cpp"
    break;

  case 119: // expr_var: "external identifier" "as" type
#line 425 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > (), true), scanner->parseVar(yystack_[0].value.as < ptc::ir::IR * > ()->getName(), false, llvm::dyn_cast<ptc::ir::TypeDecl>(yystack_[0].value.as < ptc::ir::IR * > ())->isMaybe()), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1923 "frontend/parser.cpp"
    break;

  case 120: // expr_var: expr_var "as" type
#line 426 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseVar(yystack_[0].value.as < ptc::ir::IR * > ()->getName(), false, llvm::dyn_cast<ptc::ir::TypeDecl>(yystack_[0].value.as < ptc::ir::IR * > ())->isMaybe()), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1929 "frontend/parser.cpp"
    break;

  case 121: // expr_var: expr_mat slice
#line 428 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[1].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SLICE)); }
#line 1935 "frontend/parser.cpp"
    break;

  case 122: // expr_var: "identifier" slice
#line 429 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[1].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SLICE)); }
#line 1941 "frontend/parser.cpp"
    break;

  case 123: // expr_var: "external identifier" slice
#line 430 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[1].value.as < std::string > (), true), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SLICE)); }
#line 1947 "frontend/parser.cpp"
    break;

  case 124: // expr_var: expr_var slice
#line 431 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[1].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SLICE)); }
#line 1953 "frontend/parser.cpp"
    break;

  case 125: // expr_var: expr_var "." "identifier"
#line 433 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1959 "frontend/parser.cpp"
    break;

  case 126: // expr_var: expr_var "." "external identifier"
#line 434 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1965 "frontend/parser.cpp"
    break;

  case 127: // expr_var: expr_float "**" expr_var
#line 437 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1971 "frontend/parser.cpp"
    break;

  case 128: // expr_var: expr_var "**" expr_float
#line 438 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1977 "frontend/parser.cpp"
    break;

  case 129: // expr_var: expr_var "**" expr_var
#line 439 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1983 "frontend/parser.cpp"
    break;

  case 130: // expr_var: expr_int "**" expr_var
#line 440 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < long > ()) /*Float on purpose*/, yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1989 "frontend/parser.cpp"
    break;

  case 131: // expr_var: expr_var "**" expr_int
#line 441 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < long > ()) /*Float on purpose*/, ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1995 "frontend/parser.cpp"
    break;

  case 132: // expr_var: expr_int "*" expr_var
#line 443 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 2001 "frontend/parser.cpp"
    break;

  case 133: // expr_var: expr_float "*" expr_var
#line 444 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 2007 "frontend/parser.cpp"
    break;

  case 134: // expr_var: expr_var "*" expr_int
#line 445 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 2013 "frontend/parser.cpp"
    break;

  case 135: // expr_var: expr_var "*" expr_float
#line 446 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 2019 "frontend/parser.cpp"
    break;

  case 136: // expr_var: expr_var "*" expr_var
#line 447 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 2025 "frontend/parser.cpp"
    break;

  case 137: // expr_var: expr_int "/" expr_var
#line 449 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 2031 "frontend/parser.cpp"
    break;

  case 138: // expr_var: expr_float "/" expr_var
#line 450 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 2037 "frontend/parser.cpp"
    break;

  case 139: // expr_var: expr_var "/" expr_int
#line 451 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 2043 "frontend/parser.cpp"
    break;

  case 140: // expr_var: expr_var "/" expr_float
#line 452 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 2049 "frontend/parser.cpp"
    break;

  case 141: // expr_var: expr_var "/" expr_var
#line 453 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 2055 "frontend/parser.cpp"
    break;

  case 142: // expr_var: expr_int "%" expr_var
#line 455 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 2061 "frontend/parser.cpp"
    break;

  case 143: // expr_var: expr_float "%" expr_var
#line 456 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 2067 "frontend/parser.cpp"
    break;

  case 144: // expr_var: expr_var "%" expr_int
#line 457 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 2073 "frontend/parser.cpp"
    break;

  case 145: // expr_var: expr_var "%" expr_float
#line 458 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 2079 "frontend/parser.cpp"
    break;

  case 146: // expr_var: expr_var "%" expr_var
#line 459 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 2085 "frontend/parser.cpp"
    break;

  case 147: // expr_var: expr_int "+" expr_var
#line 461 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2091 "frontend/parser.cpp"
    break;

  case 148: // expr_var: expr_float "+" expr_var
#line 462 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2097 "frontend/parser.cpp"
    break;

  case 149: // expr_var: expr_var "+" expr_int
#line 463 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2103 "frontend/parser.cpp"
    break;

  case 150: // expr_var: expr_var "+" expr_float
#line 464 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2109 "frontend/parser.cpp"
    break;

  case 151: // expr_var: expr_mat "+" expr_mat
#line 465 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2115 "frontend/parser.cpp"
    break;

  case 152: // expr_var: expr_var "+" expr_mat
#line 466 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2121 "frontend/parser.cpp"
    break;

  case 153: // expr_var: expr_mat "+" expr_var
#line 467 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2127 "frontend/parser.cpp"
    break;

  case 154: // expr_var: expr_var "+" expr_var
#line 468 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2133 "frontend/parser.cpp"
    break;

  case 155: // expr_var: expr_int "-" expr_var
#line 470 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2139 "frontend/parser.cpp"
    break;

  case 156: // expr_var: expr_float "-" expr_var
#line 471 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2145 "frontend/parser.cpp"
    break;

  case 157: // expr_var: expr_var "-" expr_int
#line 472 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2151 "frontend/parser.cpp"
    break;

  case 158: // expr_var: expr_var "-" expr_float
#line 473 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2157 "frontend/parser.cpp"
    break;

  case 159: // expr_var: expr_var "-" expr_var
#line 474 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2163 "frontend/parser.cpp"
    break;

  case 160: // expr_var: expr_int "<<" expr_var
#line 476 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2169 "frontend/parser.cpp"
    break;

  case 161: // expr_var: expr_var "<<" expr_int
#line 477 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2175 "frontend/parser.cpp"
    break;

  case 162: // expr_var: expr_var "<<" expr_var
#line 478 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2181 "frontend/parser.cpp"
    break;

  case 163: // expr_var: expr_int ">>" expr_var
#line 480 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2187 "frontend/parser.cpp"
    break;

  case 164: // expr_var: expr_var ">>" expr_int
#line 481 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2193 "frontend/parser.cpp"
    break;

  case 165: // expr_var: expr_var ">>" expr_var
#line 482 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2199 "frontend/parser.cpp"
    break;

  case 166: // expr_var: expr_int ">" expr_var
#line 484 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2205 "frontend/parser.cpp"
    break;

  case 167: // expr_var: expr_float ">" expr_var
#line 485 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2211 "frontend/parser.cpp"
    break;

  case 168: // expr_var: expr_str ">" expr_var
#line 486 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2217 "frontend/parser.cpp"
    break;

  case 169: // expr_var: expr_var ">" expr_int
#line 487 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2223 "frontend/parser.cpp"
    break;

  case 170: // expr_var: expr_var ">" expr_float
#line 488 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2229 "frontend/parser.cpp"
    break;

  case 171: // expr_var: expr_var ">" expr_str
#line 489 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2235 "frontend/parser.cpp"
    break;

  case 172: // expr_var: expr_var ">" expr_var
#line 490 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2241 "frontend/parser.cpp"
    break;

  case 173: // expr_var: expr_int ">=" expr_var
#line 492 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2247 "frontend/parser.cpp"
    break;

  case 174: // expr_var: expr_float ">=" expr_var
#line 493 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2253 "frontend/parser.cpp"
    break;

  case 175: // expr_var: expr_str ">=" expr_var
#line 494 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2259 "frontend/parser.cpp"
    break;

  case 176: // expr_var: expr_var ">=" expr_int
#line 495 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2265 "frontend/parser.cpp"
    break;

  case 177: // expr_var: expr_var ">=" expr_float
#line 496 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2271 "frontend/parser.cpp"
    break;

  case 178: // expr_var: expr_var ">=" expr_str
#line 497 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2277 "frontend/parser.cpp"
    break;

  case 179: // expr_var: expr_var ">=" expr_var
#line 498 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2283 "frontend/parser.cpp"
    break;

  case 180: // expr_var: expr_int "<" expr_var
#line 500 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2289 "frontend/parser.cpp"
    break;

  case 181: // expr_var: expr_float "<" expr_var
#line 501 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2295 "frontend/parser.cpp"
    break;

  case 182: // expr_var: expr_str "<" expr_var
#line 502 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2301 "frontend/parser.cpp"
    break;

  case 183: // expr_var: expr_var "<" expr_int
#line 503 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2307 "frontend/parser.cpp"
    break;

  case 184: // expr_var: expr_var "<" expr_float
#line 504 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2313 "frontend/parser.cpp"
    break;

  case 185: // expr_var: expr_var "<" expr_str
#line 505 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2319 "frontend/parser.cpp"
    break;

  case 186: // expr_var: expr_var "<" expr_var
#line 506 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2325 "frontend/parser.cpp"
    break;

  case 187: // expr_var: expr_int "<=" expr_var
#line 508 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2331 "frontend/parser.cpp"
    break;

  case 188: // expr_var: expr_float "<=" expr_var
#line 509 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2337 "frontend/parser.cpp"
    break;

  case 189: // expr_var: expr_str "<=" expr_var
#line 510 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2343 "frontend/parser.cpp"
    break;

  case 190: // expr_var: expr_var "<=" expr_int
#line 511 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2349 "frontend/parser.cpp"
    break;

  case 191: // expr_var: expr_var "<=" expr_float
#line 512 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2355 "frontend/parser.cpp"
    break;

  case 192: // expr_var: expr_var "<=" expr_str
#line 513 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2361 "frontend/parser.cpp"
    break;

  case 193: // expr_var: expr_var "<=" expr_var
#line 514 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2367 "frontend/parser.cpp"
    break;

  case 194: // expr_var: expr_int "==" expr_var
#line 516 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2373 "frontend/parser.cpp"
    break;

  case 195: // expr_var: expr_float "==" expr_var
#line 517 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2379 "frontend/parser.cpp"
    break;

  case 196: // expr_var: expr_str "==" expr_var
#line 518 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2385 "frontend/parser.cpp"
    break;

  case 197: // expr_var: expr_bool "==" expr_var
#line 519 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2391 "frontend/parser.cpp"
    break;

  case 198: // expr_var: expr_none "==" expr_var
#line 520 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2397 "frontend/parser.cpp"
    break;

  case 199: // expr_var: expr_struct "==" expr_struct
#line 521 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2403 "frontend/parser.cpp"
    break;

  case 200: // expr_var: expr_struct "==" expr_var
#line 522 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2409 "frontend/parser.cpp"
    break;

  case 201: // expr_var: expr_var "==" expr_struct
#line 523 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2415 "frontend/parser.cpp"
    break;

  case 202: // expr_var: expr_var "==" expr_int
#line 524 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2421 "frontend/parser.cpp"
    break;

  case 203: // expr_var: expr_var "==" expr_float
#line 525 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2427 "frontend/parser.cpp"
    break;

  case 204: // expr_var: expr_var "==" expr_str
#line 526 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2433 "frontend/parser.cpp"
    break;

  case 205: // expr_var: expr_var "==" expr_bool
#line 527 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2439 "frontend/parser.cpp"
    break;

  case 206: // expr_var: expr_var "==" expr_none
#line 528 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2445 "frontend/parser.cpp"
    break;

  case 207: // expr_var: expr_mat "==" expr_mat
#line 529 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2451 "frontend/parser.cpp"
    break;

  case 208: // expr_var: expr_var "==" expr_mat
#line 530 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2457 "frontend/parser.cpp"
    break;

  case 209: // expr_var: expr_mat "==" expr_var
#line 531 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2463 "frontend/parser.cpp"
    break;

  case 210: // expr_var: expr_var "==" expr_var
#line 532 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2469 "frontend/parser.cpp"
    break;

  case 211: // expr_var: expr_int "!=" expr_var
#line 534 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2475 "frontend/parser.cpp"
    break;

  case 212: // expr_var: expr_float "!=" expr_var
#line 535 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2481 "frontend/parser.cpp"
    break;

  case 213: // expr_var: expr_str "!=" expr_var
#line 536 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2487 "frontend/parser.cpp"
    break;

  case 214: // expr_var: expr_bool "!=" expr_var
#line 537 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2493 "frontend/parser.cpp"
    break;

  case 215: // expr_var: expr_none "!=" expr_var
#line 538 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2499 "frontend/parser.cpp"
    break;

  case 216: // expr_var: expr_struct "!=" expr_struct
#line 539 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2505 "frontend/parser.cpp"
    break;

  case 217: // expr_var: expr_struct "!=" expr_var
#line 540 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2511 "frontend/parser.cpp"
    break;

  case 218: // expr_var: expr_var "!=" expr_struct
#line 541 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2517 "frontend/parser.cpp"
    break;

  case 219: // expr_var: expr_var "!=" expr_int
#line 542 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2523 "frontend/parser.cpp"
    break;

  case 220: // expr_var: expr_var "!=" expr_float
#line 543 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2529 "frontend/parser.cpp"
    break;

  case 221: // expr_var: expr_var "!=" expr_str
#line 544 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2535 "frontend/parser.cpp"
    break;

  case 222: // expr_var: expr_var "!=" expr_bool
#line 545 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2541 "frontend/parser.cpp"
    break;

  case 223: // expr_var: expr_var "!=" expr_none
#line 546 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2547 "frontend/parser.cpp"
    break;

  case 224: // expr_var: expr_mat "!=" expr_mat
#line 547 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2553 "frontend/parser.cpp"
    break;

  case 225: // expr_var: expr_var "!=" expr_mat
#line 548 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2559 "frontend/parser.cpp"
    break;

  case 226: // expr_var: expr_mat "!=" expr_var
#line 549 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2565 "frontend/parser.cpp"
    break;

  case 227: // expr_var: expr_var "!=" expr_var
#line 550 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2571 "frontend/parser.cpp"
    break;

  case 228: // expr_var: expr_int "&" expr_var
#line 552 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2577 "frontend/parser.cpp"
    break;

  case 229: // expr_var: expr_var "&" expr_int
#line 553 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2583 "frontend/parser.cpp"
    break;

  case 230: // expr_var: expr_var "&" expr_var
#line 554 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2589 "frontend/parser.cpp"
    break;

  case 231: // expr_var: expr_int "^" expr_var
#line 556 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2595 "frontend/parser.cpp"
    break;

  case 232: // expr_var: expr_var "^" expr_int
#line 557 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2601 "frontend/parser.cpp"
    break;

  case 233: // expr_var: expr_var "^" expr_var
#line 558 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2607 "frontend/parser.cpp"
    break;

  case 234: // expr_var: expr_int "|" expr_var
#line 560 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2613 "frontend/parser.cpp"
    break;

  case 235: // expr_var: expr_var "|" expr_int
#line 561 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2619 "frontend/parser.cpp"
    break;

  case 236: // expr_var: expr_var "|" expr_var
#line 562 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2625 "frontend/parser.cpp"
    break;

  case 237: // expr_var: expr_int "in" expr_mat
#line 564 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2631 "frontend/parser.cpp"
    break;

  case 238: // expr_var: expr_float "in" expr_mat
#line 565 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2637 "frontend/parser.cpp"
    break;

  case 239: // expr_var: expr_str "in" expr_mat
#line 566 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2643 "frontend/parser.cpp"
    break;

  case 240: // expr_var: expr_bool "in" expr_mat
#line 567 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2649 "frontend/parser.cpp"
    break;

  case 241: // expr_var: expr_none "in" expr_mat
#line 568 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseNone(), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2655 "frontend/parser.cpp"
    break;

  case 242: // expr_var: expr_struct "in" expr_mat
#line 569 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2661 "frontend/parser.cpp"
    break;

  case 243: // expr_var: expr_mat "in" expr_mat
#line 570 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2667 "frontend/parser.cpp"
    break;

  case 244: // expr_var: expr_int "in" expr_var
#line 571 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2673 "frontend/parser.cpp"
    break;

  case 245: // expr_var: expr_float "in" expr_var
#line 572 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2679 "frontend/parser.cpp"
    break;

  case 246: // expr_var: expr_str "in" expr_var
#line 573 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2685 "frontend/parser.cpp"
    break;

  case 247: // expr_var: expr_bool "in" expr_var
#line 574 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2691 "frontend/parser.cpp"
    break;

  case 248: // expr_var: expr_none "in" expr_var
#line 575 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseNone(), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2697 "frontend/parser.cpp"
    break;

  case 249: // expr_var: expr_struct "in" expr_var
#line 576 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2703 "frontend/parser.cpp"
    break;

  case 250: // expr_var: expr_mat "in" expr_var
#line 577 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2709 "frontend/parser.cpp"
    break;

  case 251: // expr_var: expr_var "in" expr_str
#line 578 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2715 "frontend/parser.cpp"
    break;

  case 252: // expr_var: expr_var "in" expr_var
#line 579 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2721 "frontend/parser.cpp"
    break;

  case 253: // expr_var: expr_bool "and" expr_var
#line 581 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2727 "frontend/parser.cpp"
    break;

  case 254: // expr_var: expr_var "and" expr_bool
#line 582 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2733 "frontend/parser.cpp"
    break;

  case 255: // expr_var: expr_var "and" expr_var
#line 583 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2739 "frontend/parser.cpp"
    break;

  case 256: // expr_var: expr_bool "or" expr_var
#line 585 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2745 "frontend/parser.cpp"
    break;

  case 257: // expr_var: expr_var "or" expr_bool
#line 586 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2751 "frontend/parser.cpp"
    break;

  case 258: // expr_var: expr_var "or" expr_var
#line 587 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2757 "frontend/parser.cpp"
    break;

  case 259: // expr_var: "not" expr_var
#line 589 "frontend/parser.yy"
                         { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseUnaryPrefixExpr(yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LNOT)); }
#line 2763 "frontend/parser.cpp"
    break;

  case 260: // expr_var: "~" expr_var
#line 591 "frontend/parser.yy"
                         { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseUnaryPrefixExpr(yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BNOT)); }
#line 2769 "frontend/parser.cpp"
    break;

  case 261: // expr_var: expr_int "++" expr_var
#line 593 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2775 "frontend/parser.cpp"
    break;

  case 262: // expr_var: expr_float "++" expr_var
#line 594 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2781 "frontend/parser.cpp"
    break;

  case 263: // expr_var: expr_str "++" expr_var
#line 595 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2787 "frontend/parser.cpp"
    break;

  case 264: // expr_var: expr_bool "++" expr_var
#line 596 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2793 "frontend/parser.cpp"
    break;

  case 265: // expr_var: expr_none "++" expr_var
#line 597 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseNone(), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2799 "frontend/parser.cpp"
    break;

  case 266: // expr_var: expr_var "++" expr_int
#line 598 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2805 "frontend/parser.cpp"
    break;

  case 267: // expr_var: expr_var "++" expr_float
#line 599 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2811 "frontend/parser.cpp"
    break;

  case 268: // expr_var: expr_var "++" expr_str
#line 600 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2817 "frontend/parser.cpp"
    break;

  case 269: // expr_var: expr_var "++" expr_bool
#line 601 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2823 "frontend/parser.cpp"
    break;

  case 270: // expr_var: expr_var "++" expr_none
#line 602 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseNone(), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2829 "frontend/parser.cpp"
    break;

  case 271: // expr_var: expr_var "++" expr_var
#line 603 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2835 "frontend/parser.cpp"
    break;

  case 272: // matrix: "[" "]"
#line 607 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(std::vector<ptc::ir::Expr *>{}); }
#line 2841 "frontend/parser.cpp"
    break;

  case 273: // matrix: "[" matvals "]"
#line 608 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2847 "frontend/parser.cpp"
    break;

  case 274: // matrix: "[" "terminator (\\n or ;)" matvals "]"
#line 609 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2853 "frontend/parser.cpp"
    break;

  case 275: // matrix: "[" matvals "terminator (\\n or ;)" "]"
#line 610 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2859 "frontend/parser.cpp"
    break;

  case 276: // matrix: "[" "terminator (\\n or ;)" matvals "terminator (\\n or ;)" "]"
#line 611 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2865 "frontend/parser.cpp"
    break;

  case 277: // matvals: expr
#line 613 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixValue(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2871 "frontend/parser.cpp"
    break;

  case 278: // matvals: matvals "," expr
#line 614 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2877 "frontend/parser.cpp"
    break;

  case 279: // matvals: matvals "," "terminator (\\n or ;)" expr
#line 615 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[3].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2883 "frontend/parser.cpp"
    break;

  case 280: // expr_mat: matrix
#line 619 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2889 "frontend/parser.cpp"
    break;

  case 281: // expr_mat: "(" matrix ")"
#line 620 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2895 "frontend/parser.cpp"
    break;

  case 282: // range: "(" range ")"
#line 622 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2901 "frontend/parser.cpp"
    break;

  case 283: // range: int_val ".." int_val
#line 623 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseRange(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2907 "frontend/parser.cpp"
    break;

  case 284: // range: int_val "," int_val ".." int_val
#line 624 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseRange(yystack_[4].value.as < ptc::ir::Expr * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2913 "frontend/parser.cpp"
    break;

  case 285: // int_val: expr_int
#line 626 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 2919 "frontend/parser.cpp"
    break;

  case 286: // int_val: expr_var
#line 627 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2925 "frontend/parser.cpp"
    break;

  case 287: // slice: "[" range "]"
#line 629 "frontend/parser.yy"
                       { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2931 "frontend/parser.cpp"
    break;

  case 288: // expr_none: "none"
#line 633 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseNone(); }
#line 2937 "frontend/parser.cpp"
    break;

  case 289: // expr_none: "(" "none" ")"
#line 634 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseNone(); }
#line 2943 "frontend/parser.cpp"
    break;

  case 290: // expr_struct: "identifier" struct_val
#line 638 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseStructLiteral(scanner->sym_lookup(yystack_[1].value.as < std::string > (), false, true), yystack_[0].value.as < std::map<std::string, ptc::ir::Expr *>  > ()); }
#line 2949 "frontend/parser.cpp"
    break;

  case 291: // expr_struct: "external identifier" struct_val
#line 639 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseExternalStructLiteral(scanner->parseExtType(yystack_[1].value.as < std::string > (), false), yystack_[0].value.as < std::map<std::string, ptc::ir::Expr *>  > ()); }
#line 2955 "frontend/parser.cpp"
    break;

  case 292: // expr_struct: "(" expr_struct ")"
#line 640 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2961 "frontend/parser.cpp"
    break;

  case 293: // struct_val: "{" "}"
#line 642 "frontend/parser.yy"
                                    { yylhs.value.as < std::map<std::string, ptc::ir::Expr *>  > () = std::map<std::string, ptc::ir::Expr*>{}; }
#line 2967 "frontend/parser.cpp"
    break;

  case 294: // struct_val: "{" struct_list "}"
#line 643 "frontend/parser.yy"
                                    { yylhs.value.as < std::map<std::string, ptc::ir::Expr *>  > () = yystack_[1].value.as < std::map<std::string, ptc::ir::Expr *>  > (); }
#line 2973 "frontend/parser.cpp"
    break;

  case 295: // struct_list: "." "identifier" "=" expr
#line 645 "frontend/parser.yy"
                                                { yylhs.value.as < std::map<std::string, ptc::ir::Expr *>  > () = scanner->parseStructVals(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2979 "frontend/parser.cpp"
    break;

  case 296: // struct_list: struct_list "," "." "identifier" "=" expr
#line 646 "frontend/parser.yy"
                                                { yylhs.value.as < std::map<std::string, ptc::ir::Expr *>  > () = scanner->parseStructVals(yystack_[5].value.as < std::map<std::string, ptc::ir::Expr *>  > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2985 "frontend/parser.cpp"
    break;

  case 297: // expr_int: "int"
#line 650 "frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 2991 "frontend/parser.cpp"
    break;

  case 298: // expr_int: "-" expr_int
#line 651 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 2997 "frontend/parser.cpp"
    break;

  case 299: // expr_int: "(" expr_int ")"
#line 652 "frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 3003 "frontend/parser.cpp"
    break;

  case 300: // expr_int: "~" expr_int
#line 653 "frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 3009 "frontend/parser.cpp"
    break;

  case 301: // expr_int: expr_int "*" expr_int
#line 654 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 3015 "frontend/parser.cpp"
    break;

  case 302: // expr_int: expr_int "/" expr_int
#line 655 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 3021 "frontend/parser.cpp"
    break;

  case 303: // expr_int: expr_int "%" expr_int
#line 656 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 3027 "frontend/parser.cpp"
    break;

  case 304: // expr_int: expr_int "-" expr_int
#line 657 "frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 3033 "frontend/parser.cpp"
    break;

  case 305: // expr_int: expr_int "+" expr_int
#line 658 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 3039 "frontend/parser.cpp"
    break;

  case 306: // expr_int: expr_int "<<" expr_int
#line 659 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 3045 "frontend/parser.cpp"
    break;

  case 307: // expr_int: expr_int ">>" expr_int
#line 660 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 3051 "frontend/parser.cpp"
    break;

  case 308: // expr_int: expr_int "&" expr_int
#line 661 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 3057 "frontend/parser.cpp"
    break;

  case 309: // expr_int: expr_int "^" expr_int
#line 662 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 3063 "frontend/parser.cpp"
    break;

  case 310: // expr_int: expr_int "|" expr_int
#line 663 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 3069 "frontend/parser.cpp"
    break;

  case 311: // expr_float: "float"
#line 667 "frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 3075 "frontend/parser.cpp"
    break;

  case 312: // expr_float: "-" expr_float
#line 668 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 3081 "frontend/parser.cpp"
    break;

  case 313: // expr_float: "(" expr_float ")"
#line 669 "frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 3087 "frontend/parser.cpp"
    break;

  case 314: // expr_float: expr_float "**" expr_float
#line 670 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 3093 "frontend/parser.cpp"
    break;

  case 315: // expr_float: expr_float "**" expr_int
#line 671 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 3099 "frontend/parser.cpp"
    break;

  case 316: // expr_float: expr_int "**" expr_float
#line 672 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 3105 "frontend/parser.cpp"
    break;

  case 317: // expr_float: expr_float "*" expr_float
#line 673 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 3111 "frontend/parser.cpp"
    break;

  case 318: // expr_float: expr_float "*" expr_int
#line 674 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 3117 "frontend/parser.cpp"
    break;

  case 319: // expr_float: expr_int "*" expr_float
#line 675 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 3123 "frontend/parser.cpp"
    break;

  case 320: // expr_float: expr_float "/" expr_float
#line 676 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 3129 "frontend/parser.cpp"
    break;

  case 321: // expr_float: expr_float "/" expr_int
#line 677 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 3135 "frontend/parser.cpp"
    break;

  case 322: // expr_float: expr_int "/" expr_float
#line 678 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 3141 "frontend/parser.cpp"
    break;

  case 323: // expr_float: expr_float "%" expr_float
#line 679 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 3147 "frontend/parser.cpp"
    break;

  case 324: // expr_float: expr_float "%" expr_int
#line 680 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 3153 "frontend/parser.cpp"
    break;

  case 325: // expr_float: expr_int "%" expr_float
#line 681 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 3159 "frontend/parser.cpp"
    break;

  case 326: // expr_float: expr_float "-" expr_float
#line 682 "frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 3165 "frontend/parser.cpp"
    break;

  case 327: // expr_float: expr_float "-" expr_int
#line 683 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 3171 "frontend/parser.cpp"
    break;

  case 328: // expr_float: expr_int "-" expr_float
#line 684 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 3177 "frontend/parser.cpp"
    break;

  case 329: // expr_float: expr_float "+" expr_float
#line 685 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 3183 "frontend/parser.cpp"
    break;

  case 330: // expr_float: expr_float "+" expr_int
#line 686 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 3189 "frontend/parser.cpp"
    break;

  case 331: // expr_float: expr_int "+" expr_float
#line 687 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 3195 "frontend/parser.cpp"
    break;

  case 332: // expr_str: "string"
#line 691 "frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3201 "frontend/parser.cpp"
    break;

  case 333: // expr_str: "(" expr_str ")"
#line 692 "frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 3207 "frontend/parser.cpp"
    break;

  case 334: // expr_str: expr_str "++" expr_str
#line 693 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 3213 "frontend/parser.cpp"
    break;

  case 335: // expr_str: expr_str "++" expr_int
#line 694 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 3219 "frontend/parser.cpp"
    break;

  case 336: // expr_str: expr_str "++" expr_float
#line 695 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 3225 "frontend/parser.cpp"
    break;

  case 337: // expr_str: expr_str "++" expr_bool
#line 696 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3231 "frontend/parser.cpp"
    break;

  case 338: // expr_str: expr_str "++" expr_none
#line 697 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 3237 "frontend/parser.cpp"
    break;

  case 339: // expr_str: expr_int "++" expr_str
#line 698 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 3243 "frontend/parser.cpp"
    break;

  case 340: // expr_str: expr_int "++" expr_int
#line 699 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 3249 "frontend/parser.cpp"
    break;

  case 341: // expr_str: expr_int "++" expr_float
#line 700 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 3255 "frontend/parser.cpp"
    break;

  case 342: // expr_str: expr_int "++" expr_bool
#line 701 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3261 "frontend/parser.cpp"
    break;

  case 343: // expr_str: expr_int "++" expr_none
#line 702 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 3267 "frontend/parser.cpp"
    break;

  case 344: // expr_str: expr_float "++" expr_str
#line 703 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 3273 "frontend/parser.cpp"
    break;

  case 345: // expr_str: expr_float "++" expr_int
#line 704 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 3279 "frontend/parser.cpp"
    break;

  case 346: // expr_str: expr_float "++" expr_float
#line 705 "frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 3285 "frontend/parser.cpp"
    break;

  case 347: // expr_str: expr_float "++" expr_bool
#line 706 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3291 "frontend/parser.cpp"
    break;

  case 348: // expr_str: expr_float "++" expr_none
#line 707 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 3297 "frontend/parser.cpp"
    break;

  case 349: // expr_str: expr_bool "++" expr_str
#line 708 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 3303 "frontend/parser.cpp"
    break;

  case 350: // expr_str: expr_bool "++" expr_int
#line 709 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 3309 "frontend/parser.cpp"
    break;

  case 351: // expr_str: expr_bool "++" expr_float
#line 710 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 3315 "frontend/parser.cpp"
    break;

  case 352: // expr_str: expr_bool "++" expr_bool
#line 711 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3321 "frontend/parser.cpp"
    break;

  case 353: // expr_str: expr_bool "++" expr_none
#line 712 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 3327 "frontend/parser.cpp"
    break;

  case 354: // expr_str: expr_none "++" expr_str
#line 713 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 3333 "frontend/parser.cpp"
    break;

  case 355: // expr_str: expr_none "++" expr_int
#line 714 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 3339 "frontend/parser.cpp"
    break;

  case 356: // expr_str: expr_none "++" expr_float
#line 715 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 3345 "frontend/parser.cpp"
    break;

  case 357: // expr_str: expr_none "++" expr_bool
#line 716 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3351 "frontend/parser.cpp"
    break;

  case 358: // expr_str: expr_none "++" expr_none
#line 717 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 3357 "frontend/parser.cpp"
    break;

  case 359: // expr_bool: "bool"
#line 721 "frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 3363 "frontend/parser.cpp"
    break;

  case 360: // expr_bool: "(" expr_bool ")"
#line 722 "frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 3369 "frontend/parser.cpp"
    break;

  case 361: // expr_bool: "not" expr_bool
#line 723 "frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 3375 "frontend/parser.cpp"
    break;

  case 362: // expr_bool: expr_bool "or" expr_bool
#line 724 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 3381 "frontend/parser.cpp"
    break;

  case 363: // expr_bool: expr_bool "and" expr_bool
#line 725 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 3387 "frontend/parser.cpp"
    break;

  case 364: // expr_bool: expr_bool "==" expr_bool
#line 727 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 3393 "frontend/parser.cpp"
    break;

  case 365: // expr_bool: expr_int "==" expr_int
#line 728 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 3399 "frontend/parser.cpp"
    break;

  case 366: // expr_bool: expr_int "==" expr_float
#line 729 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 3405 "frontend/parser.cpp"
    break;

  case 367: // expr_bool: expr_float "==" expr_float
#line 730 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 3411 "frontend/parser.cpp"
    break;

  case 368: // expr_bool: expr_float "==" expr_int
#line 731 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 3417 "frontend/parser.cpp"
    break;

  case 369: // expr_bool: expr_str "==" expr_str
#line 732 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 3423 "frontend/parser.cpp"
    break;

  case 370: // expr_bool: expr_none "==" expr_none
#line 733 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 3429 "frontend/parser.cpp"
    break;

  case 371: // expr_bool: expr_bool "!=" expr_bool
#line 735 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 3435 "frontend/parser.cpp"
    break;

  case 372: // expr_bool: expr_int "!=" expr_int
#line 736 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 3441 "frontend/parser.cpp"
    break;

  case 373: // expr_bool: expr_int "!=" expr_float
#line 737 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 3447 "frontend/parser.cpp"
    break;

  case 374: // expr_bool: expr_float "!=" expr_float
#line 738 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 3453 "frontend/parser.cpp"
    break;

  case 375: // expr_bool: expr_float "!=" expr_int
#line 739 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 3459 "frontend/parser.cpp"
    break;

  case 376: // expr_bool: expr_str "!=" expr_str
#line 740 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 3465 "frontend/parser.cpp"
    break;

  case 377: // expr_bool: expr_none "!=" expr_none
#line 741 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 3471 "frontend/parser.cpp"
    break;

  case 378: // expr_bool: expr_int ">" expr_int
#line 743 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 3477 "frontend/parser.cpp"
    break;

  case 379: // expr_bool: expr_int ">" expr_float
#line 744 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 3483 "frontend/parser.cpp"
    break;

  case 380: // expr_bool: expr_float ">" expr_float
#line 745 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 3489 "frontend/parser.cpp"
    break;

  case 381: // expr_bool: expr_float ">" expr_int
#line 746 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 3495 "frontend/parser.cpp"
    break;

  case 382: // expr_bool: expr_str ">" expr_str
#line 747 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 3501 "frontend/parser.cpp"
    break;

  case 383: // expr_bool: expr_int "<" expr_int
#line 749 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 3507 "frontend/parser.cpp"
    break;

  case 384: // expr_bool: expr_int "<" expr_float
#line 750 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 3513 "frontend/parser.cpp"
    break;

  case 385: // expr_bool: expr_float "<" expr_float
#line 751 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 3519 "frontend/parser.cpp"
    break;

  case 386: // expr_bool: expr_float "<" expr_int
#line 752 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 3525 "frontend/parser.cpp"
    break;

  case 387: // expr_bool: expr_str "<" expr_str
#line 753 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 3531 "frontend/parser.cpp"
    break;

  case 388: // expr_bool: expr_int ">=" expr_int
#line 755 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 3537 "frontend/parser.cpp"
    break;

  case 389: // expr_bool: expr_int ">=" expr_float
#line 756 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 3543 "frontend/parser.cpp"
    break;

  case 390: // expr_bool: expr_float ">=" expr_float
#line 757 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 3549 "frontend/parser.cpp"
    break;

  case 391: // expr_bool: expr_float ">=" expr_int
#line 758 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 3555 "frontend/parser.cpp"
    break;

  case 392: // expr_bool: expr_str ">=" expr_str
#line 759 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 3561 "frontend/parser.cpp"
    break;

  case 393: // expr_bool: expr_int "<=" expr_int
#line 761 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 3567 "frontend/parser.cpp"
    break;

  case 394: // expr_bool: expr_int "<=" expr_float
#line 762 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 3573 "frontend/parser.cpp"
    break;

  case 395: // expr_bool: expr_float "<=" expr_float
#line 763 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 3579 "frontend/parser.cpp"
    break;

  case 396: // expr_bool: expr_float "<=" expr_int
#line 764 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 3585 "frontend/parser.cpp"
    break;

  case 397: // expr_bool: expr_str "<=" expr_str
#line 765 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 3591 "frontend/parser.cpp"
    break;

  case 398: // expr_bool: expr_str "in" expr_str
#line 767 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[0].value.as < std::string > ().find(yystack_[2].value.as < std::string > ()) != std::string::npos; }
#line 3597 "frontend/parser.cpp"
    break;

  case 399: // funtype: type "(" typelist ")"
#line 771 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFunType(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 3603 "frontend/parser.cpp"
    break;

  case 400: // funtype: type "(" ")"
#line 772 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFunType(yystack_[2].value.as < ptc::ir::IR * > (), std::vector<ir::IR *>{}); }
#line 3609 "frontend/parser.cpp"
    break;

  case 401: // funtype: "'void'" "(" typelist ")"
#line 773 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFunType(scanner->sym_lookup(VOID_CSTR), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 3615 "frontend/parser.cpp"
    break;

  case 402: // funtype: "'void'" "(" ")"
#line 774 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFunType(scanner->sym_lookup(VOID_CSTR), std::vector<ir::IR *>{}); }
#line 3621 "frontend/parser.cpp"
    break;

  case 403: // typelist: type
#line 776 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseFunTypeList(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 3627 "frontend/parser.cpp"
    break;

  case 404: // typelist: typelist "," type
#line 777 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseFunTypeListAdd(yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 3633 "frontend/parser.cpp"
    break;

  case 405: // mattype: "identifier" matsq
#line 781 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3639 "frontend/parser.cpp"
    break;

  case 406: // mattype: "'int'" matsq
#line 782 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(INT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3645 "frontend/parser.cpp"
    break;

  case 407: // mattype: "'float'" matsq
#line 783 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(FLOAT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3651 "frontend/parser.cpp"
    break;

  case 408: // mattype: "'string'" matsq
#line 784 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(STRING_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3657 "frontend/parser.cpp"
    break;

  case 409: // mattype: "'bool'" matsq
#line 785 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(BOOL_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3663 "frontend/parser.cpp"
    break;

  case 410: // mattype: "any" matsq
#line 786 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(ANY_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3669 "frontend/parser.cpp"
    break;

  case 411: // mattype: funtype matsq
#line 787 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3675 "frontend/parser.cpp"
    break;

  case 412: // mattype: "identifier" "?" matsq
#line 788 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), true); }
#line 3681 "frontend/parser.cpp"
    break;

  case 413: // mattype: "'int'" "?" matsq
#line 789 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(INT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), true); }
#line 3687 "frontend/parser.cpp"
    break;

  case 414: // mattype: "'float'" "?" matsq
#line 790 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(FLOAT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), true); }
#line 3693 "frontend/parser.cpp"
    break;

  case 415: // mattype: "'string'" "?" matsq
#line 791 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(STRING_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), true); }
#line 3699 "frontend/parser.cpp"
    break;

  case 416: // mattype: "'bool'" "?" matsq
#line 792 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(BOOL_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), true); }
#line 3705 "frontend/parser.cpp"
    break;

  case 417: // matsq: "[" "]"
#line 794 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(scanner->parseInt(-1)); }
#line 3711 "frontend/parser.cpp"
    break;

  case 418: // matsq: "[" "]" matsq
#line 796 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), scanner->parseInt(-1)); }
#line 3717 "frontend/parser.cpp"
    break;

  case 419: // type: "'int'" "?"
#line 801 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, true, true); }
#line 3723 "frontend/parser.cpp"
    break;

  case 420: // type: "'float'" "?"
#line 802 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, true, true); }
#line 3729 "frontend/parser.cpp"
    break;

  case 421: // type: "'string'" "?"
#line 803 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, true, true); }
#line 3735 "frontend/parser.cpp"
    break;

  case 422: // type: "'bool'" "?"
#line 804 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, true, true); }
#line 3741 "frontend/parser.cpp"
    break;

  case 423: // type: "identifier" "?"
#line 805 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[1].value.as < std::string > (), true, true); }
#line 3747 "frontend/parser.cpp"
    break;

  case 424: // type: "external identifier" "?"
#line 806 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExtType(yystack_[1].value.as < std::string > (), true); }
#line 3753 "frontend/parser.cpp"
    break;

  case 425: // type: mattype "?"
#line 807 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMaybeMatrixType(yystack_[1].value.as < ptc::ir::IR * > ()); }
#line 3759 "frontend/parser.cpp"
    break;

  case 426: // type: "'int'"
#line 808 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, false, true); }
#line 3765 "frontend/parser.cpp"
    break;

  case 427: // type: "'float'"
#line 809 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, false, true); }
#line 3771 "frontend/parser.cpp"
    break;

  case 428: // type: "'string'"
#line 810 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, false, true); }
#line 3777 "frontend/parser.cpp"
    break;

  case 429: // type: "'bool'"
#line 811 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, false, true); }
#line 3783 "frontend/parser.cpp"
    break;

  case 430: // type: "any"
#line 812 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(ANY_CSTR, false, true); }
#line 3789 "frontend/parser.cpp"
    break;

  case 431: // type: "identifier"
#line 813 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[0].value.as < std::string > (), false, true); }
#line 3795 "frontend/parser.cpp"
    break;

  case 432: // type: "external identifier"
#line 814 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExtType(yystack_[0].value.as < std::string > (), false); }
#line 3801 "frontend/parser.cpp"
    break;

  case 433: // type: funtype
#line 815 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 3807 "frontend/parser.cpp"
    break;

  case 434: // type: mattype
#line 816 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 3813 "frontend/parser.cpp"
    break;


#line 3817 "frontend/parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -631;

  const short  Parser ::yytable_ninf_ = -433;

  const short
   Parser ::yypact_[] =
  {
     990,  -631,  -631,  -631,  -631,  -631,  -631,  -631,   574,    49,
      10,   757,   757,   -30,   101,    42,  -631,  -631,  -631,  -631,
     757,  -631,  -631,    51,    55,    60,    61,    62,     4,    56,
      97,   193,  1120,  -631,  -631,   202,   202,  -631,  -631,   194,
    -631,   200,  -631,  1418,  -631,   203,  -631,  -631,   202,   202,
     202,  1273,  2156,  -631,   462,   270,   350,  2458,  2565,   273,
     768,   101,    89,     7,   207,   248,   369,  1738,   218,   462,
     270,   604,  2405,   873,   946,   267,   757,  -631,  -631,    39,
     539,   539,   159,  -631,  -631,  -631,  -631,   174,   350,  2458,
    2565,   273,  -631,   174,  -631,   768,   198,   263,  -631,   219,
    -631,  -631,   101,  -631,   101,  -631,   101,  -631,   101,  -631,
      32,   316,  -631,   287,   474,   100,   681,   101,  -631,  -631,
    -631,   857,  1093,  -631,  -631,  -631,  -631,  -631,  1928,  -631,
    -631,  -631,  -631,  -631,  1130,   757,   266,  1668,  -631,  -631,
     236,   757,  -631,  -631,  -631,   757,   757,   757,   757,   757,
     757,   757,   757,   757,   757,   757,   757,   757,  -631,   392,
     857,   757,   757,   757,   757,   757,   757,   757,   757,   757,
     757,  1374,   757,   757,   757,   757,   757,   757,   757,   757,
     757,   757,   757,    95,  -631,   857,   757,   757,   757,   757,
    -631,   757,   757,   757,   757,   757,   757,   757,   757,   757,
     757,   757,   757,   757,   757,   757,   757,   757,   757,   757,
     757,   757,   757,   757,   757,   757,   757,   757,   757,   757,
     757,   757,   757,   757,   757,   757,   757,   757,   757,   757,
     757,   757,   757,   757,   757,   757,   757,   757,   757,   757,
     757,   757,   757,   757,   757,   757,  -631,  -631,   363,    20,
     303,  -631,   857,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
     119,   264,  -631,    87,  1360,  1194,   159,   159,  -631,   539,
     539,   539,   539,   539,   539,   159,   159,   159,   159,   159,
     539,   539,   539,   539,   539,   539,   757,   101,    42,  -631,
    -631,  -631,  -631,   269,   173,  -631,   304,    63,   246,     8,
     310,   553,  1151,  2156,   313,    77,  2458,  -631,   275,    -7,
     288,   310,  -631,   172,   293,   310,  -631,    67,   -25,   323,
      22,   366,  1928,  -631,  1237,   370,   368,  -631,  2599,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,   103,  -631,   213,   238,   395,   668,   839,   238,
     668,   839,   190,   387,   397,   190,   387,   397,   190,   387,
     397,   190,   387,   397,  2190,   380,  2482,  2600,   333,   649,
    2252,   412,  2220,   481,  2282,   501,   354,   310,  1931,  2576,
    2316,  2506,  2346,  2530,   601,  1067,   601,  1067,  2376,   181,
    -631,  -631,  1057,  1007,   456,  -631,  2376,   181,  -631,  -631,
    1057,  1007,   456,  -631,  1998,   805,  1215,   408,  1998,   805,
    1215,   408,  1998,   805,  1215,   408,  1998,   805,  1215,   408,
    -631,  -631,   230,   238,   395,  2282,   409,  2376,   181,  2376,
     181,  2190,   380,  2482,  2600,   333,   649,  2282,   409,  2376,
    -631,  2376,  -631,  2282,   409,  2376,  -631,  2376,  -631,   238,
     668,   839,   238,   668,   839,   190,   387,   397,   190,   387,
     397,   190,   387,   397,   190,   397,  2190,   380,  2482,  2600,
     333,   649,  2282,   409,  1931,  2576,  2316,  2506,  2346,  2530,
     601,  1067,   601,  1067,  2376,  1057,  1007,  2376,  1057,  1007,
    1998,   805,  1215,  1998,   805,  1215,  1998,   805,  1215,  1998,
     805,  1215,   238,   668,   839,   238,   668,   839,   190,   387,
     397,   190,   387,   397,   190,   387,   397,   190,   387,   397,
    2190,   380,  2482,  2600,   333,   649,  2282,   409,  2376,  1057,
    1007,  2376,  1057,  1007,  1998,   805,  1215,  1998,   805,  1215,
    1998,   805,  1215,  1998,   805,  1215,   413,  2190,   380,  2482,
    2600,   333,   649,  2282,   409,   501,  2376,   456,  2376,   456,
    1998,   408,  1998,   408,  1998,   408,  1998,   408,  2190,   380,
    2482,  2600,   333,   649,  2252,   412,  2220,   481,  2282,   409,
    2376,  -631,  2376,  -631,  -631,   128,   757,   736,   417,  -631,
    -631,   757,  -631,  1501,  -631,   159,   159,   159,   159,   159,
     884,   901,   884,   901,   419,   427,   419,   427,   419,   427,
    1854,   427,   767,  1883,  1122,   628,   628,   884,   901,   884,
     901,   419,   427,   419,   427,   419,   427,   419,   427,  -631,
    -631,  -631,   195,   195,  -631,   418,   448,    24,  -631,  1635,
     158,   375,   430,   443,    28,  1738,   464,    29,  2405,  -631,
    -631,   757,   757,   432,  -631,   436,  -631,  -631,  -631,   857,
     857,   857,  -631,  1418,  1341,   486,   757,  1418,  -631,   757,
    -631,  -631,  -631,  -631,  -631,  -631,   158,   487,  -631,  -631,
     393,   393,  -631,  -631,  -631,   470,  -631,  -631,   195,   459,
     310,  -631,  -631,   149,   158,  -631,  -631,  -631,   460,   757,
     428,   506,  2032,   520,  2434,   522,   530,   535,   544,  -631,
     508,  -631,   547,   505,  -631,  -631,   158,  -631,  -631,   757,
     485,    30,  -631,   757,  -631,   525,  1418,  1418,  1418,  1418,
    1418,  1418,  -631,  -631,  -631,  -631,  1418,  -631,  -631,  -631,
    -631,  -631,   757,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     9,   297,   311,   332,   359,   288,     0,     0,
       0,     0,     0,     0,   430,     0,    52,    44,    46,    48,
      36,    33,    34,   426,   427,   428,   429,     0,     0,   100,
     101,     0,     0,     4,    10,     0,     0,    35,    15,     0,
      17,     0,    18,     0,    16,     0,    19,    20,     0,     0,
       0,     0,    93,   280,    92,    94,    95,    96,    97,    98,
      99,   433,   434,     0,   288,   100,   101,     0,   280,     0,
       0,     0,     0,     0,     0,     0,     0,   272,   277,     0,
       0,     0,     0,   105,   106,   298,   312,   259,     0,     0,
       0,     0,   361,   260,   300,     0,     0,     0,   410,    31,
      30,    37,   419,   406,   420,   407,   421,   408,   422,   409,
       0,     0,    67,     0,     0,     0,     0,   423,   122,   290,
     405,     0,     0,   424,   123,   291,     1,     3,     0,     5,
       8,     7,    14,    21,     0,     0,     0,     0,    28,    29,
       0,     0,    12,    13,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   124,     0,     0,     0,     0,     0,
     121,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   411,   425,     0,    73,
       0,   289,     0,   102,   281,   292,   299,   313,   333,   360,
       0,     0,   273,     0,     0,     0,     0,     0,   300,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   417,     0,   413,
     414,   415,   416,     0,     0,   402,     0,   431,   432,     0,
     403,     0,     0,   286,     0,     0,   285,   293,     0,     0,
     112,   118,   412,     0,   113,   119,     6,   431,   432,     0,
       0,     0,     0,    23,     0,     0,     0,    89,    88,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,   103,     0,    90,     0,   154,   152,   149,   150,   159,
     157,   158,   136,   134,   135,   141,   139,   140,   146,   144,
     145,   129,   131,   128,   271,   270,   266,   267,   268,   269,
     255,   254,   258,   257,   252,   251,   114,   120,   230,   229,
     236,   235,   233,   232,   162,   161,   165,   164,   210,   208,
     206,   201,   202,   203,   204,   205,   227,   225,   223,   218,
     219,   220,   221,   222,   172,   169,   170,   171,   186,   183,
     184,   185,   179,   176,   177,   178,   193,   190,   191,   192,
     125,   126,     0,   153,   151,   250,   243,   209,   207,   226,
     224,   265,   358,   355,   356,   354,   357,   248,   241,   198,
     370,   215,   377,   249,   242,   200,   199,   217,   216,   147,
     305,   331,   155,   304,   328,   132,   301,   319,   137,   302,
     322,   142,   303,   325,   130,   316,   261,   343,   340,   341,
     339,   342,   244,   237,   228,   308,   234,   310,   231,   309,
     160,   306,   163,   307,   194,   365,   366,   211,   372,   373,
     166,   378,   379,   180,   383,   384,   173,   388,   389,   187,
     393,   394,   148,   330,   329,   156,   327,   326,   133,   318,
     317,   138,   321,   320,   143,   324,   323,   127,   315,   314,
     262,   348,   345,   346,   344,   347,   245,   238,   195,   368,
     367,   212,   375,   374,   167,   381,   380,   181,   386,   385,
     174,   391,   390,   188,   396,   395,     0,   263,   338,   335,
     336,   334,   337,   246,   239,   398,   196,   369,   213,   376,
     168,   382,   182,   387,   175,   392,   189,   397,   264,   353,
     350,   351,   349,   352,   253,   363,   256,   362,   247,   240,
     197,   364,   214,   371,   400,     0,     0,     0,     0,   274,
     275,     0,   278,     0,   298,     0,     0,     0,     0,     0,
     305,   331,   304,   328,   301,   319,   302,   322,   303,   325,
       0,   316,   308,   310,   309,   306,   307,   330,   329,   327,
     326,   318,   317,   321,   320,   324,   323,   315,   314,    75,
     418,    32,     0,    57,    54,     0,     0,     0,   401,     0,
       0,     0,    72,     0,     0,   286,     0,     0,   285,   287,
     109,     0,     0,     0,   294,     0,   115,   110,   116,     0,
       0,     0,    73,     0,     0,    24,     0,     0,   104,     0,
     111,   117,   108,   107,   399,    74,     0,     0,   276,   279,
     305,   304,   301,   302,   303,     0,    58,    55,    59,    61,
     404,    65,    70,     0,     0,    68,   282,   283,     0,     0,
       0,     0,   286,     0,   285,     0,     0,     0,     0,    45,
      25,    26,     0,    51,    91,    63,     0,    56,    60,     0,
       0,     0,    66,     0,   295,     0,     0,     0,     0,     0,
       0,     0,    27,    47,    53,    49,     0,    64,    62,    71,
      69,   284,     0,    39,    42,    40,    43,    38,    41,    50,
     296
  };

  const short
   Parser ::yypgoto_[] =
  {
    -631,  -631,  -132,   606,   -31,     6,  -630,  -380,  -631,   282,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -605,  -631,  -631,   510,  -631,   -16,   440,
    -631,   439,  -631,   309,  1918,    -5,   499,   372,  -300,  -110,
     251,   556,   795,    11,  -631,  1385,  1623,     0,   186,  -631,
     339,  -631,    -2,   -86
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    31,    32,   132,    33,   138,   139,   140,    35,   100,
      36,    37,    38,    39,    40,    41,    42,    43,    44,   735,
      45,   736,    46,   635,   636,    47,   113,   642,   643,    48,
      49,    50,   342,    51,    52,    53,    79,    69,   304,   647,
     184,    70,    88,   119,   309,    57,    58,    91,    95,    61,
     299,    62,   120,    63
  };

  const short
   Parser ::yytable_[] =
  {
      59,   129,   646,    68,   305,   324,    34,   654,    74,    59,
     691,   313,    98,   111,     3,     4,   248,   660,   638,    80,
      59,   103,   105,   107,   109,   300,    81,   685,   686,   -67,
     311,   248,    59,   248,   655,   293,   315,   248,    34,   248,
      82,   125,   261,    59,   123,   294,   715,    96,   320,   639,
     344,   262,    76,     3,     4,     5,     6,     7,     8,   246,
       9,    77,    97,   586,   722,    10,    97,   114,   651,   115,
     652,    97,    97,    11,    97,   422,    59,   125,    97,    12,
     263,   112,   116,   718,   249,   377,   737,    83,    84,   650,
     591,     3,     4,     5,     6,     7,     8,   316,     9,   662,
     289,   689,   290,    10,   291,   695,   292,   740,   121,   659,
     115,    11,    97,   668,   307,   312,   651,    12,   652,    99,
     102,   546,   588,   122,   104,   117,    65,    66,    59,   106,
     108,   589,   117,  -431,    34,    59,   117,    59,   674,   110,
     308,    59,   305,    34,   669,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,   247,    59,
     263,   136,   300,     3,    65,    66,   123,   368,   266,   639,
     375,   137,   420,   421,  -432,   267,   633,   394,   402,   407,
     411,   415,   419,   159,   657,   160,    60,   634,   720,    82,
     664,   435,   185,   126,    75,    60,   186,    92,   633,   159,
     171,   160,   130,   134,   470,   131,    60,    14,   637,   135,
     166,   651,   141,   652,   183,   644,   171,   251,    60,    23,
      24,    25,    26,   524,   296,   670,   297,   298,   254,    60,
     183,    14,   551,   555,   557,   559,   561,   563,   565,   567,
     572,   286,   672,    23,    24,    25,    26,   159,   296,   160,
     297,   298,   651,    14,   652,   163,   164,   165,   166,   252,
     288,   115,    60,    59,   171,    23,    24,    25,    26,   651,
     296,   652,   297,   298,   116,   287,   590,   259,   183,   322,
     118,   124,   632,   709,   231,   630,    59,   713,   240,   241,
     242,   191,   243,   129,   232,   192,   301,    68,   233,   325,
     244,   245,    74,   193,   194,   190,   234,   235,   236,   237,
     238,   239,   587,   111,    60,   123,   118,   124,    78,   248,
     190,    60,    59,    60,    59,   649,   295,    60,    34,   101,
      34,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,   231,    60,   743,   744,   745,   746,
     747,   748,   653,   369,   371,   373,   749,   656,   233,   703,
     706,   708,   658,   395,   403,   661,   234,   235,   236,   237,
     238,   239,    54,   584,    14,   195,   663,   436,   667,   666,
     121,    54,   115,   196,   197,    78,    23,    24,    25,    26,
     471,   296,    54,   297,   298,   122,     3,     4,     5,     6,
       7,     8,   341,     9,    54,   192,   185,   203,    10,   525,
     597,   598,   599,   193,   194,    54,    11,   222,   552,   231,
     185,    14,    12,   671,   186,   673,   573,   575,   577,   678,
     581,   583,   687,    23,    24,    25,    26,   243,   296,   274,
     297,   298,   188,   189,   321,   244,   245,   285,    54,    60,
     326,   688,   692,   694,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   231,   343,    65,
      66,   693,    60,   185,   696,   699,   700,   186,     3,     4,
       5,     6,     7,   302,   717,     9,   287,   187,    75,   711,
      10,   236,   237,   238,   239,   188,   189,   716,    11,   723,
      54,   644,   719,   241,    12,   725,   243,    54,    60,    54,
      60,   732,   231,    54,   244,   245,   726,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
     727,    54,   728,   346,   234,   235,   236,   237,   238,   239,
     729,   697,   698,     3,     4,   730,   637,   637,    80,   389,
     397,    65,    66,   690,   731,    81,    55,   733,   424,   426,
     428,   430,   739,   640,   438,    55,   734,   444,   742,    82,
     631,   677,   592,   250,   319,   260,    55,   473,     3,     4,
       5,     6,    64,     8,   327,     9,    59,   585,    55,     0,
      10,    59,   641,     0,     0,   629,   527,   190,    11,    55,
       0,     0,   637,     0,    12,   554,     0,   721,     0,     0,
     159,    14,   160,   741,   255,   579,   161,   162,   163,   164,
     165,   166,     0,    23,    24,    25,    26,   171,   296,   195,
     297,   298,    55,   129,     0,    54,     0,   196,   197,     0,
     190,   183,   133,   595,   596,   597,   598,   599,   190,     0,
       0,    65,    66,     0,   142,   143,   144,   158,    54,    59,
      59,    59,     0,    59,    59,     0,    59,    59,     0,    59,
      34,   241,   242,     0,   243,   190,     0,   190,     0,   190,
       0,   190,   244,   245,    55,   200,   201,   202,   203,   190,
       0,    55,     0,    55,    54,   190,    54,    55,     0,    59,
       0,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,     0,    55,     0,     0,     0,    59,
       0,     0,     0,   365,   190,     0,    59,    59,    59,    59,
      59,    59,     0,   390,   398,     0,    59,     0,     0,    14,
       0,     0,    59,     0,     0,     0,   676,   432,     0,   440,
     442,    23,    24,    25,    26,     0,   296,     0,   297,   310,
     467,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,     0,    60,    10,     0,   641,     0,    60,   190,   521,
       0,    11,   595,   596,   597,   598,   599,    12,   548,   240,
     241,   242,     0,   243,    14,    56,   569,     0,   278,   279,
       0,   244,   245,    71,    56,   190,    23,    24,    25,    26,
       0,   296,     0,   297,   298,    56,     0,     0,     0,    55,
     198,   199,   200,   201,   202,   203,     0,    56,     0,     0,
     190,     0,     0,     0,    65,    66,   209,   210,    56,     0,
       0,     0,    55,     0,     0,    60,    60,    60,     0,    60,
      60,     0,    60,    60,     0,    60,   219,   220,   221,   222,
       0,     3,     4,     5,     6,     7,   302,     0,     9,     0,
       0,    56,     0,    10,     0,     0,     0,     0,    55,     0,
      55,    11,     0,   257,     0,    60,     0,    12,   217,   218,
     219,   220,   221,   222,   223,   675,     0,     0,   224,     0,
     679,   271,   272,   273,   274,    60,   225,   226,   227,   228,
     229,   230,    60,    60,    60,    60,    60,    60,   282,   283,
     284,   285,    60,    56,     0,     0,     0,     0,    60,     0,
      56,     0,    56,     0,    65,    66,    56,     0,     0,     0,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,     0,    56,     0,   258,   231,    54,     0,
       0,     0,     0,    54,     0,     0,     0,   232,   701,   705,
     707,   233,   391,   399,     0,   712,     0,     0,   714,   234,
     235,   236,   237,   238,   239,     0,     0,     0,     0,     0,
       1,   446,   448,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,     0,     0,    10,     0,   724,     0,
       0,     0,     0,     0,    11,     0,     0,     0,     0,     0,
      12,     0,   217,   218,   219,   220,   221,   222,   738,     0,
       0,    54,    54,    54,     0,    54,    54,     0,    54,    54,
       0,    54,   227,   228,   229,   230,     0,    13,    14,    15,
      16,   750,    17,    18,    19,    20,    21,    22,    56,     0,
      23,    24,    25,    26,    27,    28,     0,    29,    30,     0,
       0,    54,   198,   199,   200,   201,   202,   203,     0,     0,
       0,    56,   198,   199,   200,   201,   202,   203,   209,   210,
       0,    54,   213,   214,   215,   216,     0,    71,    54,    54,
      54,    54,    54,    54,     0,     0,     0,     0,    54,     0,
       0,     0,     0,     0,    54,     0,     0,    56,     0,    56,
     127,   128,     0,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,     0,     0,    10,   595,   596,   597,
     598,   599,    55,     0,    11,     0,     0,    55,     0,   275,
      12,    14,     0,   278,   279,     3,     4,     5,     6,    64,
     302,     0,     9,    23,    24,    25,    26,    10,   296,     0,
     297,   314,     0,     0,     0,    11,     0,    13,    14,    15,
      16,    12,    17,    18,    19,    20,    21,    22,    14,     0,
      23,    24,    25,    26,    27,    28,     0,    29,    30,     0,
      23,    24,    25,    26,   257,   296,     0,   317,   318,   280,
     281,   282,   283,   284,   285,    55,    55,    55,     0,    55,
      55,     0,    55,    55,     0,    55,     0,     0,    65,    66,
     217,   218,   219,   220,   221,   222,     0,     0,   128,     0,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,   665,     0,    10,     0,    55,     0,     0,     0,     0,
       0,    11,     0,     0,     0,     0,     0,    12,     0,     0,
       0,     0,     0,   130,     0,    55,   131,     0,     0,     0,
       0,     0,    55,    55,    55,    55,    55,    55,     0,     0,
       0,     0,    55,     0,    13,    14,    15,    16,    55,    17,
      18,    19,    20,    21,    22,     0,     0,    23,    24,    25,
      26,    27,    28,     0,    29,    30,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,     0,   156,   157,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   128,     0,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,   710,     0,    10,     0,     0,
       0,     0,     0,     0,     0,    11,     0,     0,     0,     0,
     256,    12,     0,     0,     0,   269,   270,   271,   272,   273,
     274,    56,     0,     0,     0,     0,    56,   275,   276,   277,
       0,   278,   279,    72,     0,    85,    89,    94,    13,    14,
      15,    16,     0,    17,    18,    19,    20,    21,    22,     0,
       0,    23,    24,    25,    26,    27,    28,     0,    29,    30,
       0,   136,     3,     4,     5,     6,     7,     8,     0,     9,
       0,   137,    14,     0,    10,     0,     0,     0,     0,     0,
       0,     0,    11,     0,    23,    24,    25,    26,    12,   296,
       0,   297,   376,     0,    56,    56,    56,     0,    56,    56,
       0,    56,    56,     0,    56,   264,    85,   268,     0,     0,
       0,     0,     0,     0,     0,    13,    14,    15,    16,     0,
      17,    18,    19,    20,    21,    22,     0,     0,    23,    24,
      25,    26,    27,    28,    56,    29,    30,     0,     0,   306,
       0,     0,     0,     0,     0,     0,   306,     0,     0,     0,
       0,   256,     0,     0,    56,     0,   595,   596,   597,   598,
     599,    56,    56,    56,    56,    56,    56,     0,   275,   276,
     277,    56,   278,   279,     0,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,   306,   347,   350,   353,   356,
     359,   362,   366,    89,    89,    89,     0,   379,   381,   383,
     385,   387,   392,   400,   405,   409,   413,   417,     0,     0,
     306,    89,    89,    89,    89,     0,   433,    89,    89,    89,
      89,    89,    89,   450,   453,   456,   459,   462,    89,   468,
      89,   475,   477,   479,   481,   483,   485,   488,   491,   494,
     497,   500,   503,   506,   509,   512,   515,   518,   522,    89,
     529,   532,   535,   538,   541,   544,   306,   549,    89,    89,
      89,    89,    89,    89,    89,   570,    89,    89,    89,    89,
      89,    73,     0,    86,    90,    90,     0,   306,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   593,   594,     0,   600,   602,   604,   606,   608,   610,
     612,   613,   614,   615,   616,   617,   619,   621,   623,   625,
     627,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,   323,     0,    10,     0,     0,   648,     0,     0,
       0,     0,    11,    14,     0,     0,     0,     0,    12,     0,
       0,     0,     0,   265,    86,    23,    24,    25,    26,     0,
     296,     0,   297,   298,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,    14,    15,    16,     0,
      17,    18,    19,    20,    21,    22,     0,    90,    23,    24,
      25,    26,    27,    28,    90,    29,    30,   159,   253,   160,
       0,     0,     0,   161,   162,   163,   164,   165,   166,   167,
     168,   169,     0,   170,   171,   172,   173,   174,     0,   175,
     176,   177,   178,   179,   180,   181,   182,     0,   183,     0,
       0,     0,     0,    90,   348,   351,   354,   357,   360,   363,
     367,    90,    90,    90,     0,    90,    90,    90,    90,    90,
     393,   401,   406,   410,   414,   418,     0,     0,    90,    90,
      90,    90,    90,     0,   434,    90,    90,    90,    90,    90,
      90,   451,   454,   457,   460,   463,   465,   469,    90,    90,
      90,    90,    90,    90,   486,   489,   492,   495,   498,   501,
     504,   507,   510,   513,   516,   519,   523,    90,   530,   533,
     536,   539,   542,   545,    90,   550,    90,    90,    90,    90,
      90,    90,    90,   571,    90,    90,    90,    90,    90,   269,
     270,   271,   272,   273,   274,    90,     0,     0,     0,     0,
       0,   275,   276,   277,     0,   278,   279,     0,     0,     0,
       0,     0,   601,   603,   605,   607,   609,   611,   595,   596,
     597,   598,   599,   618,   620,   622,   624,   626,   628,     0,
     275,     0,   277,     0,   278,   279,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,    67,     0,     0,    87,
      93,     2,     3,     4,     5,     6,     7,     8,     0,     9,
     159,     0,   160,     0,    10,     0,   161,   162,   163,   164,
     165,   166,    11,     0,     0,     0,     0,   171,    12,     0,
       0,     0,   175,   176,   177,   178,   179,   180,   181,   182,
       0,   183,     0,     0,     0,     0,     0,     0,     0,     0,
     680,   681,   682,   683,   684,    13,    14,    15,    16,     0,
      17,    18,    19,    20,    21,    22,     0,     0,    23,    24,
      25,    26,    27,    28,     0,    29,    30,   159,     0,   160,
       0,     0,     0,   161,   162,   163,   164,   165,   166,     0,
       0,     0,     0,     0,   171,     0,     0,     0,     0,   175,
     176,     0,   303,     0,     0,     0,   306,   306,   183,   303,
       0,   159,   -93,   160,   704,   704,   704,   161,   162,   163,
     164,   165,   166,   167,   168,   169,     0,   170,   171,   172,
     173,   174,     0,   175,   176,   177,   178,   179,   180,   181,
     182,     0,   183,     0,     0,     0,     0,     0,   303,   345,
     349,   352,   355,   358,   361,   364,   370,   372,   374,     0,
     378,   380,   382,   384,   386,   388,   396,   404,   408,   412,
     416,     0,     0,   303,   423,   425,   427,   429,   306,   431,
     437,   439,   441,   443,   445,   447,   449,   452,   455,   458,
     461,   464,   466,   472,   474,   476,   478,   480,   482,   484,
     487,   490,   493,   496,   499,   502,   505,   508,   511,   514,
     517,   520,   526,   528,   531,   534,   537,   540,   543,   303,
     547,   553,   556,   558,   560,   562,   564,   566,   568,   574,
     576,   578,   580,   582,     0,   159,     0,   160,     0,     0,
     303,   161,   162,   163,   164,   165,   166,   167,   168,   169,
       0,   170,   171,   172,   173,   174,     0,   175,   176,   177,
     178,   179,   180,   181,   182,     0,   183,     0,     0,   159,
       0,   160,     0,     0,     0,   161,   162,   163,   164,   165,
     166,     0,   168,   169,     0,   170,   171,   172,   173,   174,
     645,   175,   176,   177,   178,   179,   180,   181,   182,   159,
     183,   160,     0,     0,     0,   161,   162,   163,   164,   165,
     166,     0,   168,     0,     0,   170,   171,   172,   173,   174,
       0,   175,   176,   177,   178,   179,   180,   181,   182,     0,
     183,   159,     0,   160,     0,     0,     0,   161,   162,   163,
     164,   165,   166,     0,    90,    90,     0,   170,   171,   172,
     173,   174,     0,   175,   176,   177,   178,   179,   180,   181,
     182,   159,   183,   160,     0,     0,     0,   161,   162,   163,
     164,   165,   166,     0,     0,     0,     0,     0,   171,   172,
     173,   174,     0,   175,   176,   177,   178,   179,   180,   181,
     182,     0,   183,     0,     0,   159,     0,   160,     0,     0,
       0,   161,   162,   163,   164,   165,   166,     0,     0,     0,
       0,     0,   171,   172,     0,   174,    90,   175,   176,   177,
     178,   179,   180,   181,   182,   159,   183,   160,     0,     0,
       0,   161,   162,   163,   164,   165,   166,     0,     0,     0,
       0,     0,   171,   172,     0,     0,     0,   175,   176,   177,
     178,   179,   180,   181,   182,   159,   183,   160,     0,     0,
       0,   161,   162,   163,   164,   165,   166,     0,     0,     0,
       0,     0,   171,     0,     0,     0,     0,   175,   176,     0,
       0,   179,   180,   181,   182,   256,   183,     0,     0,     0,
     198,   199,   200,   201,   202,   203,   204,     0,     0,     0,
     205,     0,   206,   207,   208,     0,   209,   210,   211,   212,
     213,   214,   215,   216,   -96,     0,     0,     0,     0,   198,
     199,   200,   201,   202,   203,   204,     0,     0,     0,   205,
       0,   206,   207,   208,     0,   209,   210,   211,   212,   213,
     214,   215,   216,   198,   199,   200,   201,   202,   203,   204,
       0,     0,     0,   205,     0,   206,   207,   208,     0,   209,
     210,   211,   212,   213,   214,   215,   216,   198,   199,   200,
     201,   202,   203,     0,     0,     0,     0,   205,     0,   206,
     207,   208,     0,   209,   210,   211,   212,   213,   214,   215,
     216,   198,   199,   200,   201,   202,   203,     0,     0,     0,
       0,     0,     0,   206,     0,   208,     0,   209,   210,   211,
     212,   213,   214,   215,   216,   198,   199,   200,   201,   202,
     203,     0,     0,     0,     0,     0,     0,   206,     0,     0,
       0,   209,   210,   211,   212,   213,   214,   215,   216,   303,
     303,     0,     0,     0,     0,     0,     0,   702,   702,   702,
     217,   218,   219,   220,   221,   222,   223,     0,     0,     0,
     224,   198,   199,   200,   201,   202,   203,     0,   225,   226,
     227,   228,   229,   230,     0,     0,     0,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,     0,     0,     0,     0,   224,     0,     0,     0,     0,
       0,     0,     0,   225,   226,   227,   228,   229,   230,     0,
       0,   303,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,     0,   156,   157
  };

  const short
   Parser ::yycheck_[] =
  {
       0,    32,   302,     8,   114,   137,     0,    14,     8,     9,
     640,   121,    14,     9,     4,     5,     9,    42,    10,     9,
      20,    23,    24,    25,    26,   111,    16,   632,   633,     9,
     116,     9,    32,     9,    41,     3,   122,     9,    32,     9,
      30,    30,     3,    43,    69,    13,   676,    77,   134,    41,
     160,    12,     3,     4,     5,     6,     7,     8,     9,    61,
      11,    12,    11,    43,   694,    16,    11,    11,    39,    13,
      41,    11,    11,    24,    11,   185,    76,    66,    11,    30,
      41,    77,    26,   688,    77,   171,   716,    77,    78,    12,
       3,     4,     5,     6,     7,     8,     9,   128,    11,    77,
     102,    77,   104,    16,   106,    77,   108,    77,    11,    42,
      13,    24,    11,    10,    14,   117,    39,    30,    41,    77,
      69,   231,     3,    26,    69,    69,    77,    78,   128,    69,
      69,    12,    69,    77,   128,   135,    69,   137,    10,    77,
      40,   141,   252,   137,    41,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,    69,   159,
      41,     3,   248,     4,    77,    78,    69,   167,     9,    41,
     170,    13,    77,    78,    77,    16,     3,   177,   178,   179,
     180,   181,   182,     9,    12,    11,     0,    14,    39,    30,
     322,   191,    11,     0,     8,     9,    15,    11,     3,     9,
      26,    11,     0,     9,   204,     3,    20,    58,   294,     9,
      20,    39,     9,    41,    40,   301,    26,    10,    32,    70,
      71,    72,    73,   223,    75,    12,    77,    78,    10,    43,
      40,    58,   232,   233,   234,   235,   236,   237,   238,   239,
     240,    43,    12,    70,    71,    72,    73,     9,    75,    11,
      77,    78,    39,    58,    41,    17,    18,    19,    20,    11,
      41,    13,    76,   263,    26,    70,    71,    72,    73,    39,
      75,    41,    77,    78,    26,    12,    12,    10,    40,    13,
      29,    30,    13,   663,    11,   287,   286,   667,    21,    22,
      23,    21,    25,   324,    21,    25,     9,   302,    25,    63,
      33,    34,   302,    33,    34,    54,    33,    34,    35,    36,
      37,    38,     9,     9,   128,    69,    65,    66,     9,     9,
      69,   135,   322,   137,   324,    12,    10,   141,   322,    20,
     324,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,    11,   159,   726,   727,   728,   729,
     730,   731,    77,   167,   168,   169,   736,    69,    25,   659,
     660,   661,    69,   177,   178,    42,    33,    34,    35,    36,
      37,    38,     0,    10,    58,    25,    10,   191,    10,     9,
      11,     9,    13,    33,    34,    76,    70,    71,    72,    73,
     204,    75,    20,    77,    78,    26,     4,     5,     6,     7,
       8,     9,    10,    11,    32,    25,    11,    20,    16,   223,
      17,    18,    19,    33,    34,    43,    24,    20,   232,    11,
      11,    58,    30,    69,    15,    12,   240,   241,   242,    12,
     244,   245,    14,    70,    71,    72,    73,    25,    75,    20,
      77,    78,    33,    34,   135,    33,    34,    20,    76,   263,
     141,     3,    77,    10,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,    11,   159,    77,
      78,    41,   286,    11,    10,    43,    40,    15,     4,     5,
       6,     7,     8,     9,    14,    11,    12,    25,   302,     3,
      16,    35,    36,    37,    38,    33,    34,    10,    24,    39,
     128,   587,    43,    22,    30,    77,    25,   135,   322,   137,
     324,     3,    11,   141,    33,    34,    10,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
      10,   159,    10,   161,    33,    34,    35,    36,    37,    38,
      10,   651,   652,     4,     5,    10,   632,   633,     9,   177,
     178,    77,    78,   639,    10,    16,     0,    10,   186,   187,
     188,   189,    77,    10,   192,     9,    61,   195,    43,    30,
     288,   587,   263,    63,   134,    76,    20,   205,     4,     5,
       6,     7,     8,     9,   145,    11,   586,   248,    32,    -1,
      16,   591,    39,    -1,    -1,   286,   224,   346,    24,    43,
      -1,    -1,   688,    -1,    30,   233,    -1,   693,    -1,    -1,
       9,    58,    11,   723,    10,   243,    15,    16,    17,    18,
      19,    20,    -1,    70,    71,    72,    73,    26,    75,    25,
      77,    78,    76,   664,    -1,   263,    -1,    33,    34,    -1,
     389,    40,    36,    15,    16,    17,    18,    19,   397,    -1,
      -1,    77,    78,    -1,    48,    49,    50,    51,   286,   659,
     660,   661,    -1,   663,   664,    -1,   666,   667,    -1,   669,
     664,    22,    23,    -1,    25,   424,    -1,   426,    -1,   428,
      -1,   430,    33,    34,   128,    17,    18,    19,    20,   438,
      -1,   135,    -1,   137,   322,   444,   324,   141,    -1,   699,
      -1,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,    -1,   159,    -1,    -1,    -1,   719,
      -1,    -1,    -1,   167,   473,    -1,   726,   727,   728,   729,
     730,   731,    -1,   177,   178,    -1,   736,    -1,    -1,    58,
      -1,    -1,   742,    -1,    -1,    -1,    10,   191,    -1,   193,
     194,    70,    71,    72,    73,    -1,    75,    -1,    77,    78,
     204,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
      -1,    -1,   586,    16,    -1,    39,    -1,   591,   527,   223,
      -1,    24,    15,    16,    17,    18,    19,    30,   232,    21,
      22,    23,    -1,    25,    58,     0,   240,    -1,    31,    32,
      -1,    33,    34,     8,     9,   554,    70,    71,    72,    73,
      -1,    75,    -1,    77,    78,    20,    -1,    -1,    -1,   263,
      15,    16,    17,    18,    19,    20,    -1,    32,    -1,    -1,
     579,    -1,    -1,    -1,    77,    78,    31,    32,    43,    -1,
      -1,    -1,   286,    -1,    -1,   659,   660,   661,    -1,   663,
     664,    -1,   666,   667,    -1,   669,    17,    18,    19,    20,
      -1,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
      -1,    76,    -1,    16,    -1,    -1,    -1,    -1,   322,    -1,
     324,    24,    -1,    10,    -1,   699,    -1,    30,    15,    16,
      17,    18,    19,    20,    21,   586,    -1,    -1,    25,    -1,
     591,    17,    18,    19,    20,   719,    33,    34,    35,    36,
      37,    38,   726,   727,   728,   729,   730,   731,    17,    18,
      19,    20,   736,   128,    -1,    -1,    -1,    -1,   742,    -1,
     135,    -1,   137,    -1,    77,    78,   141,    -1,    -1,    -1,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,    -1,   159,    -1,    10,    11,   586,    -1,
      -1,    -1,    -1,   591,    -1,    -1,    -1,    21,   659,   660,
     661,    25,   177,   178,    -1,   666,    -1,    -1,   669,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
       0,   196,   197,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    -1,    -1,    -1,    16,    -1,   699,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    15,    16,    17,    18,    19,    20,   719,    -1,
      -1,   659,   660,   661,    -1,   663,   664,    -1,   666,   667,
      -1,   669,    35,    36,    37,    38,    -1,    57,    58,    59,
      60,   742,    62,    63,    64,    65,    66,    67,   263,    -1,
      70,    71,    72,    73,    74,    75,    -1,    77,    78,    -1,
      -1,   699,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,   286,    15,    16,    17,    18,    19,    20,    31,    32,
      -1,   719,    35,    36,    37,    38,    -1,   302,   726,   727,
     728,   729,   730,   731,    -1,    -1,    -1,    -1,   736,    -1,
      -1,    -1,    -1,    -1,   742,    -1,    -1,   322,    -1,   324,
       0,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    -1,    -1,    -1,    16,    15,    16,    17,
      18,    19,   586,    -1,    24,    -1,    -1,   591,    -1,    27,
      30,    58,    -1,    31,    32,     4,     5,     6,     7,     8,
       9,    -1,    11,    70,    71,    72,    73,    16,    75,    -1,
      77,    78,    -1,    -1,    -1,    24,    -1,    57,    58,    59,
      60,    30,    62,    63,    64,    65,    66,    67,    58,    -1,
      70,    71,    72,    73,    74,    75,    -1,    77,    78,    -1,
      70,    71,    72,    73,    10,    75,    -1,    77,    78,    15,
      16,    17,    18,    19,    20,   659,   660,   661,    -1,   663,
     664,    -1,   666,   667,    -1,   669,    -1,    -1,    77,    78,
      15,    16,    17,    18,    19,    20,    -1,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
      -1,    14,    -1,    16,    -1,   699,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,     0,    -1,   719,     3,    -1,    -1,    -1,
      -1,    -1,   726,   727,   728,   729,   730,   731,    -1,    -1,
      -1,    -1,   736,    -1,    57,    58,    59,    60,   742,    62,
      63,    64,    65,    66,    67,    -1,    -1,    70,    71,    72,
      73,    74,    75,    -1,    77,    78,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    -1,    -1,    14,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      10,    30,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,   586,    -1,    -1,    -1,    -1,   591,    27,    28,    29,
      -1,    31,    32,     8,    -1,    10,    11,    12,    57,    58,
      59,    60,    -1,    62,    63,    64,    65,    66,    67,    -1,
      -1,    70,    71,    72,    73,    74,    75,    -1,    77,    78,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      -1,    13,    58,    -1,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    70,    71,    72,    73,    30,    75,
      -1,    77,    78,    -1,   659,   660,   661,    -1,   663,   664,
      -1,   666,   667,    -1,   669,    80,    81,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    66,    67,    -1,    -1,    70,    71,
      72,    73,    74,    75,   699,    77,    78,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,
      -1,    10,    -1,    -1,   719,    -1,    15,    16,    17,    18,
      19,   726,   727,   728,   729,   730,   731,    -1,    27,    28,
      29,   736,    31,    32,    -1,    -1,    -1,   742,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,    -1,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,    -1,    -1,
     185,   186,   187,   188,   189,    -1,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,     8,    -1,    10,    11,    12,    -1,   252,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   266,   267,    -1,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      -1,    -1,    14,    -1,    16,    -1,    -1,   302,    -1,    -1,
      -1,    -1,    24,    58,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    80,    81,    70,    71,    72,    73,    -1,
      75,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    66,    67,    -1,   114,    70,    71,
      72,    73,    74,    75,   121,    77,    78,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    25,    26,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    40,    -1,
      -1,    -1,    -1,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,    -1,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,    -1,    -1,   185,   186,
     187,   188,   189,    -1,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,    15,
      16,    17,    18,    19,    20,   252,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,   269,   270,   271,   272,   273,   274,    15,    16,
      17,    18,    19,   280,   281,   282,   283,   284,   285,    -1,
      27,    -1,    29,    -1,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   302,     8,    -1,    -1,    11,
      12,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
       9,    -1,    11,    -1,    16,    -1,    15,    16,    17,    18,
      19,    20,    24,    -1,    -1,    -1,    -1,    26,    30,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     595,   596,   597,   598,   599,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    66,    67,    -1,    -1,    70,    71,
      72,    73,    74,    75,    -1,    77,    78,     9,    -1,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    31,
      32,    -1,   114,    -1,    -1,    -1,   651,   652,    40,   121,
      -1,     9,    10,    11,   659,   660,   661,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    25,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    -1,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,    -1,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,   185,   186,   187,   188,   189,   723,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,    -1,     9,    -1,    11,    -1,    -1,
     252,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    40,    -1,    -1,     9,
      -1,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,    22,    23,    -1,    25,    26,    27,    28,    29,
     302,    31,    32,    33,    34,    35,    36,    37,    38,     9,
      40,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,    22,    -1,    -1,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      40,     9,    -1,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    -1,   651,   652,    -1,    25,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,     9,    40,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    -1,    -1,     9,    -1,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    -1,    29,   723,    31,    32,    33,
      34,    35,    36,    37,    38,     9,    40,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,     9,    40,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    35,    36,    37,    38,    10,    40,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      25,    -1,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    10,    -1,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    25,
      -1,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    25,    -1,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    25,    -1,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    -1,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,   651,
     652,    -1,    -1,    -1,    -1,    -1,    -1,   659,   660,   661,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      25,    15,    16,    17,    18,    19,    20,    -1,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,    36,    37,    38,    -1,
      -1,   723,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     0,     3,     4,     5,     6,     7,     8,     9,    11,
      16,    24,    30,    57,    58,    59,    60,    62,    63,    64,
      65,    66,    67,    70,    71,    72,    73,    74,    75,    77,
      78,    81,    82,    84,    85,    88,    90,    91,    92,    93,
      94,    95,    96,    97,    98,   100,   102,   105,   109,   110,
     111,   113,   114,   115,   117,   121,   122,   125,   126,   127,
     128,   129,   131,   133,     8,    77,    78,   114,   115,   117,
     121,   122,   125,   126,   127,   128,     3,    12,   113,   116,
       9,    16,    30,    77,    78,   125,   126,   114,   122,   125,
     126,   127,   128,   114,   125,   128,    77,    11,   132,    77,
      89,   113,    69,   132,    69,   132,    69,   132,    69,   132,
      77,     9,    77,   106,    11,    13,    26,    69,   120,   123,
     132,    11,    26,    69,   120,   123,     0,     0,     1,    84,
       0,     3,    83,    83,     9,     9,     3,    13,    85,    86,
      87,     9,    83,    83,    83,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    55,    56,    83,     9,
      11,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      25,    26,    27,    28,    29,    31,    32,    33,    34,    35,
      36,    37,    38,    40,   120,    11,    15,    25,    33,    34,
     120,    21,    25,    33,    34,    25,    33,    34,    15,    16,
      17,    18,    19,    20,    21,    25,    27,    28,    29,    31,
      32,    33,    34,    35,    36,    37,    38,    15,    16,    17,
      18,    19,    20,    21,    25,    33,    34,    35,    36,    37,
      38,    11,    21,    25,    33,    34,    35,    36,    37,    38,
      21,    22,    23,    25,    33,    34,   132,    69,     9,    77,
     106,    10,    11,    10,    10,    10,    10,    10,    10,    10,
     116,     3,    12,    41,   125,   126,     9,    16,   125,    15,
      16,    17,    18,    19,    20,    27,    28,    29,    31,    32,
      15,    16,    17,    18,    19,    20,    43,    12,    41,   132,
     132,   132,   132,     3,    13,    10,    75,    77,    78,   130,
     133,     9,     9,   114,   118,   119,   125,    14,    40,   124,
      78,   133,   132,   119,    78,   133,    84,    77,    78,   109,
     133,   113,    13,    14,    82,    63,   113,   111,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,    10,   112,   113,   119,   114,   117,   125,   126,   114,
     125,   126,   114,   125,   126,   114,   125,   126,   114,   125,
     126,   114,   125,   126,   114,   121,   125,   126,   127,   128,
     114,   128,   114,   128,   114,   127,    78,   133,   114,   125,
     114,   125,   114,   125,   114,   125,   114,   125,   114,   117,
     121,   122,   125,   126,   127,   128,   114,   117,   121,   122,
     125,   126,   127,   128,   114,   125,   126,   127,   114,   125,
     126,   127,   114,   125,   126,   127,   114,   125,   126,   127,
      77,    78,   119,   114,   117,   114,   117,   114,   117,   114,
     117,   114,   121,   125,   126,   127,   128,   114,   117,   114,
     121,   114,   121,   114,   117,   114,   122,   114,   122,   114,
     125,   126,   114,   125,   126,   114,   125,   126,   114,   125,
     126,   114,   125,   126,   114,   126,   114,   121,   125,   126,
     127,   128,   114,   117,   114,   125,   114,   125,   114,   125,
     114,   125,   114,   125,   114,   125,   126,   114,   125,   126,
     114,   125,   126,   114,   125,   126,   114,   125,   126,   114,
     125,   126,   114,   125,   126,   114,   125,   126,   114,   125,
     126,   114,   125,   126,   114,   125,   126,   114,   125,   126,
     114,   121,   125,   126,   127,   128,   114,   117,   114,   125,
     126,   114,   125,   126,   114,   125,   126,   114,   125,   126,
     114,   125,   126,   114,   125,   126,   119,   114,   121,   125,
     126,   127,   128,   114,   117,   127,   114,   127,   114,   127,
     114,   127,   114,   127,   114,   127,   114,   127,   114,   121,
     125,   126,   127,   128,   114,   128,   114,   128,   114,   117,
     114,   128,   114,   128,    10,   130,    43,     9,     3,    12,
      12,     3,   113,   125,   125,    15,    16,    17,    18,    19,
     125,   126,   125,   126,   125,   126,   125,   126,   125,   126,
     125,   126,   125,   125,   125,   125,   125,   125,   126,   125,
     126,   125,   126,   125,   126,   125,   126,   125,   126,   113,
     132,    89,    13,     3,    14,   103,   104,   133,    10,    41,
      10,    39,   107,   108,   133,   114,   118,   119,   125,    12,
      12,    39,    41,    77,    14,    41,    69,    12,    69,    42,
      42,    42,    77,    10,    82,    14,     9,    10,    10,    41,
      12,    69,    12,    12,    10,   113,    10,   108,    12,   113,
     125,   125,   125,   125,   125,   103,   103,    14,     3,    77,
     133,    86,    77,    41,    10,    77,    10,   119,   119,    43,
      40,   113,   114,   118,   125,   113,   118,   113,   118,    87,
      14,     3,   113,    87,   113,    86,    10,    14,   103,    43,
      39,   133,    86,    39,   113,    77,    10,    10,    10,    10,
      10,    10,     3,    10,    61,    99,   101,    86,   113,    77,
      77,   119,    43,    87,    87,    87,    87,    87,    87,    87,
     113
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
     103,   104,   104,   105,   105,   105,   105,   106,   107,   107,
     108,   108,   108,   109,   110,   110,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     112,   112,   113,   113,   113,   113,   113,   113,   113,   113,
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
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   115,   115,   115,   115,   115,   116,   116,   116,
     117,   117,   118,   118,   118,   119,   119,   120,   121,   121,
     122,   122,   122,   123,   123,   124,   124,   125,   125,   125,
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
     131,   131,   131,   131,   131,   131,   131,   132,   132,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133
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
       3,     2,     4,     5,     6,     5,     6,     1,     2,     4,
       2,     4,     1,     2,     4,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     4,     2,     2,     4,     4,     4,
       4,     4,     3,     3,     3,     4,     4,     4,     3,     3,
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
       1,     3,     3,     3,     5,     1,     1,     3,     1,     3,
       2,     2,     3,     2,     3,     4,     6,     1,     2,     3,
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
       2,     2,     3,     3,     3,     3,     3,     2,     3,     2,
       2,     2,     2,     2,     2,     2,     1,     1,     1,     1,
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
       0,   241,   241,   242,   244,   245,   246,   249,   250,   253,
     254,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   271,   272,   273,   274,   275,   278,   279,
     283,   285,   286,   290,   291,   292,   294,   295,   299,   300,
     301,   302,   303,   304,   306,   309,   311,   313,   315,   318,
     320,   321,   323,   324,   327,   328,   329,   331,   332,   333,
     334,   336,   337,   341,   342,   343,   344,   346,   348,   349,
     351,   352,   353,   358,   362,   363,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     386,   387,   391,   392,   393,   394,   395,   396,   397,   398,
     401,   402,   404,   406,   407,   409,   410,   412,   413,   414,
     415,   416,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   428,   429,   430,   431,   433,   434,   437,   438,   439,
     440,   441,   443,   444,   445,   446,   447,   449,   450,   451,
     452,   453,   455,   456,   457,   458,   459,   461,   462,   463,
     464,   465,   466,   467,   468,   470,   471,   472,   473,   474,
     476,   477,   478,   480,   481,   482,   484,   485,   486,   487,
     488,   489,   490,   492,   493,   494,   495,   496,   497,   498,
     500,   501,   502,   503,   504,   505,   506,   508,   509,   510,
     511,   512,   513,   514,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   552,   553,
     554,   556,   557,   558,   560,   561,   562,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   581,   582,   583,   585,   586,   587,   589,
     591,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   607,   608,   609,   610,   611,   613,   614,   615,
     619,   620,   622,   623,   624,   626,   627,   629,   633,   634,
     638,   639,   640,   642,   643,   645,   646,   650,   651,   652,
     653,   654,   655,   656,   657,   658,   659,   660,   661,   662,
     663,   667,   668,   669,   670,   671,   672,   673,   674,   675,
     676,   677,   678,   679,   680,   681,   682,   683,   684,   685,
     686,   687,   691,   692,   693,   694,   695,   696,   697,   698,
     699,   700,   701,   702,   703,   704,   705,   706,   707,   708,
     709,   710,   711,   712,   713,   714,   715,   716,   717,   721,
     722,   723,   724,   725,   727,   728,   729,   730,   731,   732,
     733,   735,   736,   737,   738,   739,   740,   741,   743,   744,
     745,   746,   747,   749,   750,   751,   752,   753,   755,   756,
     757,   758,   759,   761,   762,   763,   764,   765,   767,   771,
     772,   773,   774,   776,   777,   781,   782,   783,   784,   785,
     786,   787,   788,   789,   790,   791,   792,   794,   796,   801,
     802,   803,   804,   805,   806,   807,   808,   809,   810,   811,
     812,   813,   814,   815,   816
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
#line 5196 "frontend/parser.cpp"

#line 819 "frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    auto msg = std::to_string(scanner->llvmloc->begin.line) + ":" + std::to_string(scanner->llvmloc->begin.column) + ": " + err_message;
    scanner->fatal_error(ptc::diag::ERR_SYNTAX, msg);
}
