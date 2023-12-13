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
#line 239 "frontend/parser.yy"
                        { scanner->parseEntry(std::vector<ptc::ir::IR *>{}); }
#line 1225 "frontend/parser.cpp"
    break;

  case 3: // start: stmt "end of file"
#line 240 "frontend/parser.yy"
                        { scanner->parseEntry(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1231 "frontend/parser.cpp"
    break;

  case 4: // stmt: stmts
#line 242 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1237 "frontend/parser.cpp"
    break;

  case 5: // stmt: stmt stmts
#line 243 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1243 "frontend/parser.cpp"
    break;

  case 6: // stmt: stmt error stmts
#line 244 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1249 "frontend/parser.cpp"
    break;

  case 9: // stmts: "terminator (\\n or ;)"
#line 251 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = nullptr; }
#line 1255 "frontend/parser.cpp"
    break;

  case 10: // stmts: stmts_ne
#line 252 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1261 "frontend/parser.cpp"
    break;

  case 11: // stmts_ne: set stmt_end
#line 254 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1267 "frontend/parser.cpp"
    break;

  case 12: // stmts_ne: vardecl stmt_end
#line 255 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1273 "frontend/parser.cpp"
    break;

  case 13: // stmts_ne: vardef stmt_end
#line 256 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1279 "frontend/parser.cpp"
    break;

  case 14: // stmts_ne: import stmt_end
#line 257 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1285 "frontend/parser.cpp"
    break;

  case 15: // stmts_ne: for
#line 258 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1291 "frontend/parser.cpp"
    break;

  case 16: // stmts_ne: if
#line 259 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1297 "frontend/parser.cpp"
    break;

  case 17: // stmts_ne: while
#line 260 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1303 "frontend/parser.cpp"
    break;

  case 18: // stmts_ne: dowhile
#line 261 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1309 "frontend/parser.cpp"
    break;

  case 19: // stmts_ne: struct
#line 262 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1315 "frontend/parser.cpp"
    break;

  case 20: // stmts_ne: function
#line 263 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1321 "frontend/parser.cpp"
    break;

  case 21: // stmts_ne: flowctl stmt_end
#line 264 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1327 "frontend/parser.cpp"
    break;

  case 22: // stmts_ne: expr stmt_end
#line 265 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1333 "frontend/parser.cpp"
    break;

  case 23: // block: "{" "}"
#line 269 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1339 "frontend/parser.cpp"
    break;

  case 24: // block: "{" stmt "}"
#line 270 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1345 "frontend/parser.cpp"
    break;

  case 25: // block: "terminator (\\n or ;)" "{" stmt "}"
#line 271 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1351 "frontend/parser.cpp"
    break;

  case 26: // block: "{" stmt "}" "terminator (\\n or ;)"
#line 272 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1357 "frontend/parser.cpp"
    break;

  case 27: // block: "terminator (\\n or ;)" "{" stmt "}" "terminator (\\n or ;)"
#line 273 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1363 "frontend/parser.cpp"
    break;

  case 28: // scope_body: stmts_ne
#line 276 "frontend/parser.yy"
                      { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); scanner->leaveScope(); }
#line 1369 "frontend/parser.cpp"
    break;

  case 29: // scope_body: block
#line 277 "frontend/parser.yy"
                      { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); scanner->leaveScope(); }
#line 1375 "frontend/parser.cpp"
    break;

  case 30: // import: "import" id_list
#line 281 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::IR * > () = scanner->parseImports(yystack_[0].value.as < std::vector<std::string>  > ()); }
#line 1381 "frontend/parser.cpp"
    break;

  case 31: // id_list: "identifier"
#line 283 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseImportName(yystack_[0].value.as < std::string > ()); }
#line 1387 "frontend/parser.cpp"
    break;

  case 32: // id_list: "identifier" "," id_list
#line 284 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseAddImportName(yystack_[0].value.as < std::vector<std::string>  > (), yystack_[2].value.as < std::string > ()); }
#line 1393 "frontend/parser.cpp"
    break;

  case 33: // flowctl: "break"
#line 288 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseBreak(); }
#line 1399 "frontend/parser.cpp"
    break;

  case 34: // flowctl: "continue"
#line 289 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseContinue(); }
#line 1405 "frontend/parser.cpp"
    break;

  case 35: // flowctl: return
#line 290 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1411 "frontend/parser.cpp"
    break;

  case 36: // return: "return"
#line 292 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(nullptr); }
#line 1417 "frontend/parser.cpp"
    break;

  case 37: // return: "return" expr
#line 293 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1423 "frontend/parser.cpp"
    break;

  case 38: // for: for_kw "(" vardecl ":" expr ")" scope_body
#line 297 "frontend/parser.yy"
                                                      { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1429 "frontend/parser.cpp"
    break;

  case 39: // for: for_kw "(" "identifier" ":" expr ")" scope_body
#line 298 "frontend/parser.yy"
                                                      { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1435 "frontend/parser.cpp"
    break;

  case 40: // for: for_kw "(" "external identifier" ":" expr ")" scope_body
#line 299 "frontend/parser.yy"
                                                      { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1441 "frontend/parser.cpp"
    break;

  case 41: // for: for_kw "(" vardecl ":" range ")" scope_body
#line 300 "frontend/parser.yy"
                                                      { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1447 "frontend/parser.cpp"
    break;

  case 42: // for: for_kw "(" "identifier" ":" range ")" scope_body
#line 301 "frontend/parser.yy"
                                                      { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1453 "frontend/parser.cpp"
    break;

  case 43: // for: for_kw "(" "external identifier" ":" range ")" scope_body
#line 302 "frontend/parser.yy"
                                                      { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1459 "frontend/parser.cpp"
    break;

  case 44: // for_kw: "for"
#line 304 "frontend/parser.yy"
               { scanner->enterBlockScope(); }
#line 1465 "frontend/parser.cpp"
    break;

  case 45: // while: wh_kw "(" expr ")" scope_body
#line 307 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseWhile(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1471 "frontend/parser.cpp"
    break;

  case 46: // wh_kw: "while"
#line 309 "frontend/parser.yy"
                { scanner->enterBlockScope(); }
#line 1477 "frontend/parser.cpp"
    break;

  case 47: // dowhile: do_kw scope_body "while" "(" expr ")"
#line 311 "frontend/parser.yy"
                                                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseDoWhile(yystack_[1].value.as < ptc::ir::Expr * > (), yystack_[4].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1483 "frontend/parser.cpp"
    break;

  case 48: // do_kw: "do"
#line 313 "frontend/parser.yy"
             { scanner->enterBlockScope(); }
#line 1489 "frontend/parser.cpp"
    break;

  case 49: // if: if_kw "(" expr ")" scope_body else
#line 316 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseIfStmt(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1495 "frontend/parser.cpp"
    break;

  case 50: // else: el_kw scope_body
#line 318 "frontend/parser.yy"
                         { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1501 "frontend/parser.cpp"
    break;

  case 51: // else: %empty
#line 319 "frontend/parser.yy"
                         { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1507 "frontend/parser.cpp"
    break;

  case 52: // if_kw: "if"
#line 321 "frontend/parser.yy"
             { scanner->enterBlockScope(); }
#line 1513 "frontend/parser.cpp"
    break;

  case 53: // el_kw: "else"
#line 322 "frontend/parser.yy"
               { scanner->enterBlockScope(); }
#line 1519 "frontend/parser.cpp"
    break;

  case 54: // struct: "'struct'" "identifier" "{" "}"
#line 325 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[2].value.as < std::string > (), std::vector<ptc::ir::IR *>{}); }
#line 1525 "frontend/parser.cpp"
    break;

  case 55: // struct: "'struct'" "identifier" "{" decllist "}"
#line 326 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1531 "frontend/parser.cpp"
    break;

  case 56: // struct: "'struct'" "identifier" "terminator (\\n or ;)" "{" decllist "}"
#line 327 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[4].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1537 "frontend/parser.cpp"
    break;

  case 58: // decllist: "terminator (\\n or ;)" decllist
#line 330 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1543 "frontend/parser.cpp"
    break;

  case 59: // decllist: declistval "terminator (\\n or ;)"
#line 331 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[1].value.as < ptc::ir::IR * > (), std::vector<ptc::ir::IR *>{}); }
#line 1549 "frontend/parser.cpp"
    break;

  case 60: // decllist: declistval "terminator (\\n or ;)" decllist
#line 332 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[2].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1555 "frontend/parser.cpp"
    break;

  case 61: // declistval: type "identifier"
#line 334 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > (), nullptr); }
#line 1561 "frontend/parser.cpp"
    break;

  case 62: // declistval: type "identifier" "=" expr
#line 335 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1567 "frontend/parser.cpp"
    break;

  case 64: // function: type fun_id "(" ")" block
#line 340 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1573 "frontend/parser.cpp"
    break;

  case 65: // function: type fun_id "(" funargs ")" block
#line 341 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[5].value.as < ptc::ir::IR * > (), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1579 "frontend/parser.cpp"
    break;

  case 66: // function: "'void'" fun_id "(" ")" block
#line 342 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1585 "frontend/parser.cpp"
    break;

  case 67: // function: "'void'" fun_id "(" funargs ")" block
#line 343 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1591 "frontend/parser.cpp"
    break;

  case 68: // fun_id: "identifier"
#line 345 "frontend/parser.yy"
            { scanner->enterFunScope(); yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1597 "frontend/parser.cpp"
    break;

  case 69: // funargsnvar: type "identifier"
#line 347 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseFunParam(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1603 "frontend/parser.cpp"
    break;

  case 70: // funargsnvar: funargsnvar "," type "identifier"
#line 348 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseAddFunParam(yystack_[3].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1609 "frontend/parser.cpp"
    break;

  case 71: // funargs: ".." "identifier"
#line 350 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseFunParam(scanner->sym_lookup(VARARGS_CSTR, false, true), yystack_[0].value.as < std::string > ()); }
#line 1615 "frontend/parser.cpp"
    break;

  case 72: // funargs: funargsnvar "," ".." "identifier"
#line 351 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseAddFunParam(yystack_[3].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), scanner->sym_lookup(VARARGS_CSTR, false, true), yystack_[0].value.as < std::string > ());}
#line 1621 "frontend/parser.cpp"
    break;

  case 73: // funargs: funargsnvar
#line 352 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = yystack_[0].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (); }
#line 1627 "frontend/parser.cpp"
    break;

  case 74: // vardecl: type "identifier"
#line 357 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1633 "frontend/parser.cpp"
    break;

  case 75: // vardef: type "identifier" "=" expr
#line 361 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1639 "frontend/parser.cpp"
    break;

  case 76: // vardef: "var" "identifier" "=" expr
#line 362 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(nullptr, yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1645 "frontend/parser.cpp"
    break;

  case 77: // set: expr "++=" expr
#line 368 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1651 "frontend/parser.cpp"
    break;

  case 78: // set: expr "**=" expr
#line 369 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1657 "frontend/parser.cpp"
    break;

  case 79: // set: expr "%=" expr
#line 370 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1663 "frontend/parser.cpp"
    break;

  case 80: // set: expr "/=" expr
#line 371 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1669 "frontend/parser.cpp"
    break;

  case 81: // set: expr "*=" expr
#line 372 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1675 "frontend/parser.cpp"
    break;

  case 82: // set: expr "-=" expr
#line 373 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1681 "frontend/parser.cpp"
    break;

  case 83: // set: expr "+=" expr
#line 374 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1687 "frontend/parser.cpp"
    break;

  case 84: // set: expr "&=" expr
#line 375 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1693 "frontend/parser.cpp"
    break;

  case 85: // set: expr "|=" expr
#line 376 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1699 "frontend/parser.cpp"
    break;

  case 86: // set: expr "^=" expr
#line 377 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1705 "frontend/parser.cpp"
    break;

  case 87: // set: expr "<<=" expr
#line 378 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1711 "frontend/parser.cpp"
    break;

  case 88: // set: expr ">>=" expr
#line 379 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1717 "frontend/parser.cpp"
    break;

  case 89: // set: expr "=" expr
#line 380 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1723 "frontend/parser.cpp"
    break;

  case 90: // set: expr "=" set
#line 381 "frontend/parser.yy"
      { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1729 "frontend/parser.cpp"
    break;

  case 91: // callarglist: expr
#line 385 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseFunCallArg(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1735 "frontend/parser.cpp"
    break;

  case 92: // callarglist: callarglist "," expr
#line 386 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddFunCallArg(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1741 "frontend/parser.cpp"
    break;

  case 93: // expr: expr_mat
#line 390 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1747 "frontend/parser.cpp"
    break;

  case 94: // expr: expr_var
#line 391 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1753 "frontend/parser.cpp"
    break;

  case 95: // expr: expr_none
#line 392 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1759 "frontend/parser.cpp"
    break;

  case 96: // expr: expr_struct
#line 393 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1765 "frontend/parser.cpp"
    break;

  case 97: // expr: expr_int
#line 394 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 1771 "frontend/parser.cpp"
    break;

  case 98: // expr: expr_float
#line 395 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFloat(yystack_[0].value.as < double > ()); }
#line 1777 "frontend/parser.cpp"
    break;

  case 99: // expr: expr_str
#line 396 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseString(yystack_[0].value.as < std::string > ()); }
#line 1783 "frontend/parser.cpp"
    break;

  case 100: // expr: expr_bool
#line 397 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseBool(yystack_[0].value.as < bool > ()); }
#line 1789 "frontend/parser.cpp"
    break;

  case 101: // expr_var: "identifier"
#line 400 "frontend/parser.yy"
              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > ()); }
#line 1795 "frontend/parser.cpp"
    break;

  case 102: // expr_var: "external identifier"
#line 401 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > (), true); }
#line 1801 "frontend/parser.cpp"
    break;

  case 103: // expr_var: "-" "identifier"
#line 402 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1807 "frontend/parser.cpp"
    break;

  case 104: // expr_var: "-" "external identifier"
#line 403 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > (), true), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1813 "frontend/parser.cpp"
    break;

  case 105: // expr_var: "(" expr_var ")"
#line 404 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1819 "frontend/parser.cpp"
    break;

  case 106: // expr_var: expr_var "(" ")"
#line 406 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[2].value.as < ptc::ir::Expr * > (), std::vector<ptc::ir::Expr *>{}); }
#line 1825 "frontend/parser.cpp"
    break;

  case 107: // expr_var: expr_var "(" callarglist ")"
#line 407 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 1831 "frontend/parser.cpp"
    break;

  case 108: // expr_var: expr_str "[" int_val "]"
#line 409 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1837 "frontend/parser.cpp"
    break;

  case 109: // expr_var: expr_mat "[" int_val "]"
#line 410 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1843 "frontend/parser.cpp"
    break;

  case 110: // expr_var: "identifier" "[" int_val "]"
#line 411 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1849 "frontend/parser.cpp"
    break;

  case 111: // expr_var: "external identifier" "[" int_val "]"
#line 412 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1855 "frontend/parser.cpp"
    break;

  case 112: // expr_var: expr_var "[" int_val "]"
#line 413 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1861 "frontend/parser.cpp"
    break;

  case 113: // expr_var: "identifier" "as" "external identifier"
#line 415 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > ()), scanner->parseVar(scanner->parseExtType(yystack_[0].value.as < std::string > (), false)->getName(), true, false), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1867 "frontend/parser.cpp"
    break;

  case 114: // expr_var: "external identifier" "as" "external identifier"
#line 416 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > (), true), scanner->parseVar(scanner->parseExtType(yystack_[0].value.as < std::string > (), false)->getName(), true, false), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1873 "frontend/parser.cpp"
    break;

  case 115: // expr_var: expr_var "as" "external identifier"
#line 417 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseVar(scanner->parseExtType(yystack_[0].value.as < std::string > (), false)->getName(), true, false), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1879 "frontend/parser.cpp"
    break;

  case 116: // expr_var: "identifier" "as" "external identifier" "?"
#line 418 "frontend/parser.yy"
                                      { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), scanner->parseVar(scanner->parseExtType(yystack_[1].value.as < std::string > (), true)->getName(), true, true), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1885 "frontend/parser.cpp"
    break;

  case 117: // expr_var: "external identifier" "as" "external identifier" "?"
#line 419 "frontend/parser.yy"
                                      { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > (), true), scanner->parseVar(scanner->parseExtType(yystack_[1].value.as < std::string > (), true)->getName(), true, true), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1891 "frontend/parser.cpp"
    break;

  case 118: // expr_var: expr_var "as" "external identifier" "?"
#line 420 "frontend/parser.yy"
                                      { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), scanner->parseVar(scanner->parseExtType(yystack_[1].value.as < std::string > (), true)->getName(), true, true), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1897 "frontend/parser.cpp"
    break;

  case 119: // expr_var: "identifier" "as" type
#line 421 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > ()), scanner->parseVar(yystack_[0].value.as < ptc::ir::IR * > ()->getName(), false, llvm::dyn_cast<ptc::ir::TypeDecl>(yystack_[0].value.as < ptc::ir::IR * > ())->isMaybe()), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1903 "frontend/parser.cpp"
    break;

  case 120: // expr_var: "external identifier" "as" type
#line 422 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > (), true), scanner->parseVar(yystack_[0].value.as < ptc::ir::IR * > ()->getName(), false, llvm::dyn_cast<ptc::ir::TypeDecl>(yystack_[0].value.as < ptc::ir::IR * > ())->isMaybe()), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1909 "frontend/parser.cpp"
    break;

  case 121: // expr_var: expr_var "as" type
#line 423 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseVar(yystack_[0].value.as < ptc::ir::IR * > ()->getName(), false, llvm::dyn_cast<ptc::ir::TypeDecl>(yystack_[0].value.as < ptc::ir::IR * > ())->isMaybe()), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1915 "frontend/parser.cpp"
    break;

  case 122: // expr_var: expr_mat slice
#line 425 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[1].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SLICE)); }
#line 1921 "frontend/parser.cpp"
    break;

  case 123: // expr_var: "identifier" slice
#line 426 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[1].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SLICE)); }
#line 1927 "frontend/parser.cpp"
    break;

  case 124: // expr_var: "external identifier" slice
#line 427 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[1].value.as < std::string > (), true), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SLICE)); }
#line 1933 "frontend/parser.cpp"
    break;

  case 125: // expr_var: expr_var slice
#line 428 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[1].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SLICE)); }
#line 1939 "frontend/parser.cpp"
    break;

  case 126: // expr_var: expr_var "." "identifier"
#line 430 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1945 "frontend/parser.cpp"
    break;

  case 127: // expr_var: expr_var "." "external identifier"
#line 431 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1951 "frontend/parser.cpp"
    break;

  case 128: // expr_var: expr_float "**" expr_var
#line 434 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1957 "frontend/parser.cpp"
    break;

  case 129: // expr_var: expr_var "**" expr_float
#line 435 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1963 "frontend/parser.cpp"
    break;

  case 130: // expr_var: expr_var "**" expr_var
#line 436 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1969 "frontend/parser.cpp"
    break;

  case 131: // expr_var: expr_int "**" expr_var
#line 437 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < long > ()) /*Float on purpose*/, yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1975 "frontend/parser.cpp"
    break;

  case 132: // expr_var: expr_var "**" expr_int
#line 438 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < long > ()) /*Float on purpose*/, ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1981 "frontend/parser.cpp"
    break;

  case 133: // expr_var: expr_int "*" expr_var
#line 440 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1987 "frontend/parser.cpp"
    break;

  case 134: // expr_var: expr_float "*" expr_var
#line 441 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1993 "frontend/parser.cpp"
    break;

  case 135: // expr_var: expr_var "*" expr_int
#line 442 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1999 "frontend/parser.cpp"
    break;

  case 136: // expr_var: expr_var "*" expr_float
#line 443 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 2005 "frontend/parser.cpp"
    break;

  case 137: // expr_var: expr_var "*" expr_var
#line 444 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 2011 "frontend/parser.cpp"
    break;

  case 138: // expr_var: expr_int "/" expr_var
#line 446 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 2017 "frontend/parser.cpp"
    break;

  case 139: // expr_var: expr_float "/" expr_var
#line 447 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 2023 "frontend/parser.cpp"
    break;

  case 140: // expr_var: expr_var "/" expr_int
#line 448 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 2029 "frontend/parser.cpp"
    break;

  case 141: // expr_var: expr_var "/" expr_float
#line 449 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 2035 "frontend/parser.cpp"
    break;

  case 142: // expr_var: expr_var "/" expr_var
#line 450 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 2041 "frontend/parser.cpp"
    break;

  case 143: // expr_var: expr_int "%" expr_var
#line 452 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 2047 "frontend/parser.cpp"
    break;

  case 144: // expr_var: expr_float "%" expr_var
#line 453 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 2053 "frontend/parser.cpp"
    break;

  case 145: // expr_var: expr_var "%" expr_int
#line 454 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 2059 "frontend/parser.cpp"
    break;

  case 146: // expr_var: expr_var "%" expr_float
#line 455 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 2065 "frontend/parser.cpp"
    break;

  case 147: // expr_var: expr_var "%" expr_var
#line 456 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 2071 "frontend/parser.cpp"
    break;

  case 148: // expr_var: expr_int "+" expr_var
#line 458 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2077 "frontend/parser.cpp"
    break;

  case 149: // expr_var: expr_float "+" expr_var
#line 459 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2083 "frontend/parser.cpp"
    break;

  case 150: // expr_var: expr_var "+" expr_int
#line 460 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2089 "frontend/parser.cpp"
    break;

  case 151: // expr_var: expr_var "+" expr_float
#line 461 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2095 "frontend/parser.cpp"
    break;

  case 152: // expr_var: expr_mat "+" expr_mat
#line 462 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2101 "frontend/parser.cpp"
    break;

  case 153: // expr_var: expr_var "+" expr_mat
#line 463 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2107 "frontend/parser.cpp"
    break;

  case 154: // expr_var: expr_mat "+" expr_var
#line 464 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2113 "frontend/parser.cpp"
    break;

  case 155: // expr_var: expr_var "+" expr_var
#line 465 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2119 "frontend/parser.cpp"
    break;

  case 156: // expr_var: expr_int "-" expr_var
#line 467 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2125 "frontend/parser.cpp"
    break;

  case 157: // expr_var: expr_float "-" expr_var
#line 468 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2131 "frontend/parser.cpp"
    break;

  case 158: // expr_var: expr_var "-" expr_int
#line 469 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2137 "frontend/parser.cpp"
    break;

  case 159: // expr_var: expr_var "-" expr_float
#line 470 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2143 "frontend/parser.cpp"
    break;

  case 160: // expr_var: expr_var "-" expr_var
#line 471 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2149 "frontend/parser.cpp"
    break;

  case 161: // expr_var: expr_int "<<" expr_var
#line 473 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2155 "frontend/parser.cpp"
    break;

  case 162: // expr_var: expr_var "<<" expr_int
#line 474 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2161 "frontend/parser.cpp"
    break;

  case 163: // expr_var: expr_var "<<" expr_var
#line 475 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2167 "frontend/parser.cpp"
    break;

  case 164: // expr_var: expr_int ">>" expr_var
#line 477 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2173 "frontend/parser.cpp"
    break;

  case 165: // expr_var: expr_var ">>" expr_int
#line 478 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2179 "frontend/parser.cpp"
    break;

  case 166: // expr_var: expr_var ">>" expr_var
#line 479 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2185 "frontend/parser.cpp"
    break;

  case 167: // expr_var: expr_int ">" expr_var
#line 481 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2191 "frontend/parser.cpp"
    break;

  case 168: // expr_var: expr_float ">" expr_var
#line 482 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2197 "frontend/parser.cpp"
    break;

  case 169: // expr_var: expr_str ">" expr_var
#line 483 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2203 "frontend/parser.cpp"
    break;

  case 170: // expr_var: expr_var ">" expr_int
#line 484 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2209 "frontend/parser.cpp"
    break;

  case 171: // expr_var: expr_var ">" expr_float
#line 485 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2215 "frontend/parser.cpp"
    break;

  case 172: // expr_var: expr_var ">" expr_str
#line 486 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2221 "frontend/parser.cpp"
    break;

  case 173: // expr_var: expr_var ">" expr_var
#line 487 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2227 "frontend/parser.cpp"
    break;

  case 174: // expr_var: expr_int ">=" expr_var
#line 489 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2233 "frontend/parser.cpp"
    break;

  case 175: // expr_var: expr_float ">=" expr_var
#line 490 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2239 "frontend/parser.cpp"
    break;

  case 176: // expr_var: expr_str ">=" expr_var
#line 491 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2245 "frontend/parser.cpp"
    break;

  case 177: // expr_var: expr_var ">=" expr_int
#line 492 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2251 "frontend/parser.cpp"
    break;

  case 178: // expr_var: expr_var ">=" expr_float
#line 493 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2257 "frontend/parser.cpp"
    break;

  case 179: // expr_var: expr_var ">=" expr_str
#line 494 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2263 "frontend/parser.cpp"
    break;

  case 180: // expr_var: expr_var ">=" expr_var
#line 495 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2269 "frontend/parser.cpp"
    break;

  case 181: // expr_var: expr_int "<" expr_var
#line 497 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2275 "frontend/parser.cpp"
    break;

  case 182: // expr_var: expr_float "<" expr_var
#line 498 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2281 "frontend/parser.cpp"
    break;

  case 183: // expr_var: expr_str "<" expr_var
#line 499 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2287 "frontend/parser.cpp"
    break;

  case 184: // expr_var: expr_var "<" expr_int
#line 500 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2293 "frontend/parser.cpp"
    break;

  case 185: // expr_var: expr_var "<" expr_float
#line 501 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2299 "frontend/parser.cpp"
    break;

  case 186: // expr_var: expr_var "<" expr_str
#line 502 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2305 "frontend/parser.cpp"
    break;

  case 187: // expr_var: expr_var "<" expr_var
#line 503 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2311 "frontend/parser.cpp"
    break;

  case 188: // expr_var: expr_int "<=" expr_var
#line 505 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2317 "frontend/parser.cpp"
    break;

  case 189: // expr_var: expr_float "<=" expr_var
#line 506 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2323 "frontend/parser.cpp"
    break;

  case 190: // expr_var: expr_str "<=" expr_var
#line 507 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2329 "frontend/parser.cpp"
    break;

  case 191: // expr_var: expr_var "<=" expr_int
#line 508 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2335 "frontend/parser.cpp"
    break;

  case 192: // expr_var: expr_var "<=" expr_float
#line 509 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2341 "frontend/parser.cpp"
    break;

  case 193: // expr_var: expr_var "<=" expr_str
#line 510 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2347 "frontend/parser.cpp"
    break;

  case 194: // expr_var: expr_var "<=" expr_var
#line 511 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2353 "frontend/parser.cpp"
    break;

  case 195: // expr_var: expr_int "==" expr_var
#line 513 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2359 "frontend/parser.cpp"
    break;

  case 196: // expr_var: expr_float "==" expr_var
#line 514 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2365 "frontend/parser.cpp"
    break;

  case 197: // expr_var: expr_str "==" expr_var
#line 515 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2371 "frontend/parser.cpp"
    break;

  case 198: // expr_var: expr_bool "==" expr_var
#line 516 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2377 "frontend/parser.cpp"
    break;

  case 199: // expr_var: expr_none "==" expr_var
#line 517 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2383 "frontend/parser.cpp"
    break;

  case 200: // expr_var: expr_struct "==" expr_struct
#line 518 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2389 "frontend/parser.cpp"
    break;

  case 201: // expr_var: expr_struct "==" expr_var
#line 519 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2395 "frontend/parser.cpp"
    break;

  case 202: // expr_var: expr_var "==" expr_struct
#line 520 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2401 "frontend/parser.cpp"
    break;

  case 203: // expr_var: expr_var "==" expr_int
#line 521 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2407 "frontend/parser.cpp"
    break;

  case 204: // expr_var: expr_var "==" expr_float
#line 522 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2413 "frontend/parser.cpp"
    break;

  case 205: // expr_var: expr_var "==" expr_str
#line 523 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2419 "frontend/parser.cpp"
    break;

  case 206: // expr_var: expr_var "==" expr_bool
#line 524 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2425 "frontend/parser.cpp"
    break;

  case 207: // expr_var: expr_var "==" expr_none
#line 525 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2431 "frontend/parser.cpp"
    break;

  case 208: // expr_var: expr_mat "==" expr_mat
#line 526 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2437 "frontend/parser.cpp"
    break;

  case 209: // expr_var: expr_var "==" expr_mat
#line 527 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2443 "frontend/parser.cpp"
    break;

  case 210: // expr_var: expr_mat "==" expr_var
#line 528 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2449 "frontend/parser.cpp"
    break;

  case 211: // expr_var: expr_var "==" expr_var
#line 529 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2455 "frontend/parser.cpp"
    break;

  case 212: // expr_var: expr_int "!=" expr_var
#line 531 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2461 "frontend/parser.cpp"
    break;

  case 213: // expr_var: expr_float "!=" expr_var
#line 532 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2467 "frontend/parser.cpp"
    break;

  case 214: // expr_var: expr_str "!=" expr_var
#line 533 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2473 "frontend/parser.cpp"
    break;

  case 215: // expr_var: expr_bool "!=" expr_var
#line 534 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2479 "frontend/parser.cpp"
    break;

  case 216: // expr_var: expr_none "!=" expr_var
#line 535 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2485 "frontend/parser.cpp"
    break;

  case 217: // expr_var: expr_struct "!=" expr_struct
#line 536 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2491 "frontend/parser.cpp"
    break;

  case 218: // expr_var: expr_struct "!=" expr_var
#line 537 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2497 "frontend/parser.cpp"
    break;

  case 219: // expr_var: expr_var "!=" expr_struct
#line 538 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2503 "frontend/parser.cpp"
    break;

  case 220: // expr_var: expr_var "!=" expr_int
#line 539 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2509 "frontend/parser.cpp"
    break;

  case 221: // expr_var: expr_var "!=" expr_float
#line 540 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2515 "frontend/parser.cpp"
    break;

  case 222: // expr_var: expr_var "!=" expr_str
#line 541 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2521 "frontend/parser.cpp"
    break;

  case 223: // expr_var: expr_var "!=" expr_bool
#line 542 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2527 "frontend/parser.cpp"
    break;

  case 224: // expr_var: expr_var "!=" expr_none
#line 543 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2533 "frontend/parser.cpp"
    break;

  case 225: // expr_var: expr_mat "!=" expr_mat
#line 544 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2539 "frontend/parser.cpp"
    break;

  case 226: // expr_var: expr_var "!=" expr_mat
#line 545 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2545 "frontend/parser.cpp"
    break;

  case 227: // expr_var: expr_mat "!=" expr_var
#line 546 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2551 "frontend/parser.cpp"
    break;

  case 228: // expr_var: expr_var "!=" expr_var
#line 547 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2557 "frontend/parser.cpp"
    break;

  case 229: // expr_var: expr_int "&" expr_var
#line 549 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2563 "frontend/parser.cpp"
    break;

  case 230: // expr_var: expr_var "&" expr_int
#line 550 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2569 "frontend/parser.cpp"
    break;

  case 231: // expr_var: expr_var "&" expr_var
#line 551 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2575 "frontend/parser.cpp"
    break;

  case 232: // expr_var: expr_int "^" expr_var
#line 553 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2581 "frontend/parser.cpp"
    break;

  case 233: // expr_var: expr_var "^" expr_int
#line 554 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2587 "frontend/parser.cpp"
    break;

  case 234: // expr_var: expr_var "^" expr_var
#line 555 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2593 "frontend/parser.cpp"
    break;

  case 235: // expr_var: expr_int "|" expr_var
#line 557 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2599 "frontend/parser.cpp"
    break;

  case 236: // expr_var: expr_var "|" expr_int
#line 558 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2605 "frontend/parser.cpp"
    break;

  case 237: // expr_var: expr_var "|" expr_var
#line 559 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2611 "frontend/parser.cpp"
    break;

  case 238: // expr_var: expr_int "in" expr_mat
#line 561 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2617 "frontend/parser.cpp"
    break;

  case 239: // expr_var: expr_float "in" expr_mat
#line 562 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2623 "frontend/parser.cpp"
    break;

  case 240: // expr_var: expr_str "in" expr_mat
#line 563 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2629 "frontend/parser.cpp"
    break;

  case 241: // expr_var: expr_bool "in" expr_mat
#line 564 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2635 "frontend/parser.cpp"
    break;

  case 242: // expr_var: expr_none "in" expr_mat
#line 565 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseNone(), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2641 "frontend/parser.cpp"
    break;

  case 243: // expr_var: expr_struct "in" expr_mat
#line 566 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2647 "frontend/parser.cpp"
    break;

  case 244: // expr_var: expr_mat "in" expr_mat
#line 567 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2653 "frontend/parser.cpp"
    break;

  case 245: // expr_var: expr_int "in" expr_var
#line 568 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2659 "frontend/parser.cpp"
    break;

  case 246: // expr_var: expr_float "in" expr_var
#line 569 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2665 "frontend/parser.cpp"
    break;

  case 247: // expr_var: expr_str "in" expr_var
#line 570 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2671 "frontend/parser.cpp"
    break;

  case 248: // expr_var: expr_bool "in" expr_var
#line 571 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2677 "frontend/parser.cpp"
    break;

  case 249: // expr_var: expr_none "in" expr_var
#line 572 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseNone(), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2683 "frontend/parser.cpp"
    break;

  case 250: // expr_var: expr_struct "in" expr_var
#line 573 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2689 "frontend/parser.cpp"
    break;

  case 251: // expr_var: expr_mat "in" expr_var
#line 574 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2695 "frontend/parser.cpp"
    break;

  case 252: // expr_var: expr_var "in" expr_str
#line 575 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2701 "frontend/parser.cpp"
    break;

  case 253: // expr_var: expr_var "in" expr_var
#line 576 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2707 "frontend/parser.cpp"
    break;

  case 254: // expr_var: expr_bool "and" expr_var
#line 578 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2713 "frontend/parser.cpp"
    break;

  case 255: // expr_var: expr_var "and" expr_bool
#line 579 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2719 "frontend/parser.cpp"
    break;

  case 256: // expr_var: expr_var "and" expr_var
#line 580 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2725 "frontend/parser.cpp"
    break;

  case 257: // expr_var: expr_bool "or" expr_var
#line 582 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2731 "frontend/parser.cpp"
    break;

  case 258: // expr_var: expr_var "or" expr_bool
#line 583 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2737 "frontend/parser.cpp"
    break;

  case 259: // expr_var: expr_var "or" expr_var
#line 584 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2743 "frontend/parser.cpp"
    break;

  case 260: // expr_var: "not" expr_var
#line 586 "frontend/parser.yy"
                         { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseUnaryPrefixExpr(yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LNOT)); }
#line 2749 "frontend/parser.cpp"
    break;

  case 261: // expr_var: "~" expr_var
#line 588 "frontend/parser.yy"
                         { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseUnaryPrefixExpr(yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BNOT)); }
#line 2755 "frontend/parser.cpp"
    break;

  case 262: // expr_var: expr_int "++" expr_var
#line 590 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2761 "frontend/parser.cpp"
    break;

  case 263: // expr_var: expr_float "++" expr_var
#line 591 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2767 "frontend/parser.cpp"
    break;

  case 264: // expr_var: expr_str "++" expr_var
#line 592 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2773 "frontend/parser.cpp"
    break;

  case 265: // expr_var: expr_bool "++" expr_var
#line 593 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2779 "frontend/parser.cpp"
    break;

  case 266: // expr_var: expr_none "++" expr_var
#line 594 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseNone(), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2785 "frontend/parser.cpp"
    break;

  case 267: // expr_var: expr_var "++" expr_int
#line 595 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2791 "frontend/parser.cpp"
    break;

  case 268: // expr_var: expr_var "++" expr_float
#line 596 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2797 "frontend/parser.cpp"
    break;

  case 269: // expr_var: expr_var "++" expr_str
#line 597 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2803 "frontend/parser.cpp"
    break;

  case 270: // expr_var: expr_var "++" expr_bool
#line 598 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2809 "frontend/parser.cpp"
    break;

  case 271: // expr_var: expr_var "++" expr_none
#line 599 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseNone(), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2815 "frontend/parser.cpp"
    break;

  case 272: // expr_var: expr_var "++" expr_var
#line 600 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2821 "frontend/parser.cpp"
    break;

  case 273: // matrix: "[" "]"
#line 604 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(std::vector<ptc::ir::Expr *>{}); }
#line 2827 "frontend/parser.cpp"
    break;

  case 274: // matrix: "[" matvals "]"
#line 605 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2833 "frontend/parser.cpp"
    break;

  case 275: // matrix: "[" "terminator (\\n or ;)" matvals "]"
#line 606 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2839 "frontend/parser.cpp"
    break;

  case 276: // matrix: "[" matvals "terminator (\\n or ;)" "]"
#line 607 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2845 "frontend/parser.cpp"
    break;

  case 277: // matrix: "[" "terminator (\\n or ;)" matvals "terminator (\\n or ;)" "]"
#line 608 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2851 "frontend/parser.cpp"
    break;

  case 278: // matvals: expr
#line 611 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixValue(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2857 "frontend/parser.cpp"
    break;

  case 279: // matvals: matvals "," expr
#line 612 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2863 "frontend/parser.cpp"
    break;

  case 280: // matvals: matvals "," "terminator (\\n or ;)" expr
#line 613 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[3].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2869 "frontend/parser.cpp"
    break;

  case 281: // expr_mat: matrix
#line 617 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2875 "frontend/parser.cpp"
    break;

  case 282: // expr_mat: "(" matrix ")"
#line 618 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2881 "frontend/parser.cpp"
    break;

  case 283: // range: "(" range ")"
#line 620 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2887 "frontend/parser.cpp"
    break;

  case 284: // range: int_val ".." int_val
#line 621 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseRange(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2893 "frontend/parser.cpp"
    break;

  case 285: // range: int_val "," int_val ".." int_val
#line 622 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseRange(yystack_[4].value.as < ptc::ir::Expr * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2899 "frontend/parser.cpp"
    break;

  case 286: // int_val: expr_int
#line 624 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 2905 "frontend/parser.cpp"
    break;

  case 287: // int_val: expr_var
#line 625 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2911 "frontend/parser.cpp"
    break;

  case 288: // slice: "[" range "]"
#line 627 "frontend/parser.yy"
                       { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2917 "frontend/parser.cpp"
    break;

  case 289: // expr_none: "none"
#line 632 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseNone(); }
#line 2923 "frontend/parser.cpp"
    break;

  case 290: // expr_none: "(" "none" ")"
#line 633 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseNone(); }
#line 2929 "frontend/parser.cpp"
    break;

  case 291: // expr_struct: "identifier" struct_val
#line 637 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseStructLiteral(scanner->sym_lookup(yystack_[1].value.as < std::string > (), false, true), yystack_[0].value.as < std::map<std::string, ptc::ir::Expr *>  > ()); }
#line 2935 "frontend/parser.cpp"
    break;

  case 292: // expr_struct: "external identifier" struct_val
#line 638 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseExternalStructLiteral(scanner->parseExtType(yystack_[1].value.as < std::string > (), false), yystack_[0].value.as < std::map<std::string, ptc::ir::Expr *>  > ()); }
#line 2941 "frontend/parser.cpp"
    break;

  case 293: // expr_struct: "(" expr_struct ")"
#line 639 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2947 "frontend/parser.cpp"
    break;

  case 294: // struct_val: "{" "}"
#line 641 "frontend/parser.yy"
                                    { yylhs.value.as < std::map<std::string, ptc::ir::Expr *>  > () = std::map<std::string, ptc::ir::Expr*>{}; }
#line 2953 "frontend/parser.cpp"
    break;

  case 295: // struct_val: "{" struct_list "}"
#line 642 "frontend/parser.yy"
                                    { yylhs.value.as < std::map<std::string, ptc::ir::Expr *>  > () = yystack_[1].value.as < std::map<std::string, ptc::ir::Expr *>  > (); }
#line 2959 "frontend/parser.cpp"
    break;

  case 296: // struct_list: "." "identifier" "=" expr
#line 644 "frontend/parser.yy"
                                                { yylhs.value.as < std::map<std::string, ptc::ir::Expr *>  > () = scanner->parseStructVals(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2965 "frontend/parser.cpp"
    break;

  case 297: // struct_list: struct_list "," "." "identifier" "=" expr
#line 645 "frontend/parser.yy"
                                                { yylhs.value.as < std::map<std::string, ptc::ir::Expr *>  > () = scanner->parseStructVals(yystack_[5].value.as < std::map<std::string, ptc::ir::Expr *>  > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2971 "frontend/parser.cpp"
    break;

  case 298: // expr_int: "int"
#line 649 "frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 2977 "frontend/parser.cpp"
    break;

  case 299: // expr_int: "-" expr_int
#line 650 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 2983 "frontend/parser.cpp"
    break;

  case 300: // expr_int: "(" expr_int ")"
#line 651 "frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 2989 "frontend/parser.cpp"
    break;

  case 301: // expr_int: "~" expr_int
#line 652 "frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 2995 "frontend/parser.cpp"
    break;

  case 302: // expr_int: expr_int "*" expr_int
#line 653 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 3001 "frontend/parser.cpp"
    break;

  case 303: // expr_int: expr_int "/" expr_int
#line 654 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 3007 "frontend/parser.cpp"
    break;

  case 304: // expr_int: expr_int "%" expr_int
#line 655 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 3013 "frontend/parser.cpp"
    break;

  case 305: // expr_int: expr_int "-" expr_int
#line 656 "frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 3019 "frontend/parser.cpp"
    break;

  case 306: // expr_int: expr_int "+" expr_int
#line 657 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 3025 "frontend/parser.cpp"
    break;

  case 307: // expr_int: expr_int "<<" expr_int
#line 658 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 3031 "frontend/parser.cpp"
    break;

  case 308: // expr_int: expr_int ">>" expr_int
#line 659 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 3037 "frontend/parser.cpp"
    break;

  case 309: // expr_int: expr_int "&" expr_int
#line 660 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 3043 "frontend/parser.cpp"
    break;

  case 310: // expr_int: expr_int "^" expr_int
#line 661 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 3049 "frontend/parser.cpp"
    break;

  case 311: // expr_int: expr_int "|" expr_int
#line 662 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 3055 "frontend/parser.cpp"
    break;

  case 312: // expr_float: "float"
#line 666 "frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 3061 "frontend/parser.cpp"
    break;

  case 313: // expr_float: "-" expr_float
#line 667 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 3067 "frontend/parser.cpp"
    break;

  case 314: // expr_float: "(" expr_float ")"
#line 668 "frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 3073 "frontend/parser.cpp"
    break;

  case 315: // expr_float: expr_float "**" expr_float
#line 669 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 3079 "frontend/parser.cpp"
    break;

  case 316: // expr_float: expr_float "**" expr_int
#line 670 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 3085 "frontend/parser.cpp"
    break;

  case 317: // expr_float: expr_int "**" expr_float
#line 671 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 3091 "frontend/parser.cpp"
    break;

  case 318: // expr_float: expr_float "*" expr_float
#line 672 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 3097 "frontend/parser.cpp"
    break;

  case 319: // expr_float: expr_float "*" expr_int
#line 673 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 3103 "frontend/parser.cpp"
    break;

  case 320: // expr_float: expr_int "*" expr_float
#line 674 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 3109 "frontend/parser.cpp"
    break;

  case 321: // expr_float: expr_float "/" expr_float
#line 675 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 3115 "frontend/parser.cpp"
    break;

  case 322: // expr_float: expr_float "/" expr_int
#line 676 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 3121 "frontend/parser.cpp"
    break;

  case 323: // expr_float: expr_int "/" expr_float
#line 677 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 3127 "frontend/parser.cpp"
    break;

  case 324: // expr_float: expr_float "%" expr_float
#line 678 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 3133 "frontend/parser.cpp"
    break;

  case 325: // expr_float: expr_float "%" expr_int
#line 679 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 3139 "frontend/parser.cpp"
    break;

  case 326: // expr_float: expr_int "%" expr_float
#line 680 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 3145 "frontend/parser.cpp"
    break;

  case 327: // expr_float: expr_float "-" expr_float
#line 681 "frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 3151 "frontend/parser.cpp"
    break;

  case 328: // expr_float: expr_float "-" expr_int
#line 682 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 3157 "frontend/parser.cpp"
    break;

  case 329: // expr_float: expr_int "-" expr_float
#line 683 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 3163 "frontend/parser.cpp"
    break;

  case 330: // expr_float: expr_float "+" expr_float
#line 684 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 3169 "frontend/parser.cpp"
    break;

  case 331: // expr_float: expr_float "+" expr_int
#line 685 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 3175 "frontend/parser.cpp"
    break;

  case 332: // expr_float: expr_int "+" expr_float
#line 686 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 3181 "frontend/parser.cpp"
    break;

  case 333: // expr_str: "string"
#line 690 "frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3187 "frontend/parser.cpp"
    break;

  case 334: // expr_str: "(" expr_str ")"
#line 691 "frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 3193 "frontend/parser.cpp"
    break;

  case 335: // expr_str: expr_str "++" expr_str
#line 692 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 3199 "frontend/parser.cpp"
    break;

  case 336: // expr_str: expr_str "++" expr_int
#line 693 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 3205 "frontend/parser.cpp"
    break;

  case 337: // expr_str: expr_str "++" expr_float
#line 694 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 3211 "frontend/parser.cpp"
    break;

  case 338: // expr_str: expr_str "++" expr_bool
#line 695 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3217 "frontend/parser.cpp"
    break;

  case 339: // expr_str: expr_str "++" expr_none
#line 696 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 3223 "frontend/parser.cpp"
    break;

  case 340: // expr_str: expr_int "++" expr_str
#line 697 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 3229 "frontend/parser.cpp"
    break;

  case 341: // expr_str: expr_int "++" expr_int
#line 698 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 3235 "frontend/parser.cpp"
    break;

  case 342: // expr_str: expr_int "++" expr_float
#line 699 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 3241 "frontend/parser.cpp"
    break;

  case 343: // expr_str: expr_int "++" expr_bool
#line 700 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3247 "frontend/parser.cpp"
    break;

  case 344: // expr_str: expr_int "++" expr_none
#line 701 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 3253 "frontend/parser.cpp"
    break;

  case 345: // expr_str: expr_float "++" expr_str
#line 702 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 3259 "frontend/parser.cpp"
    break;

  case 346: // expr_str: expr_float "++" expr_int
#line 703 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 3265 "frontend/parser.cpp"
    break;

  case 347: // expr_str: expr_float "++" expr_float
#line 704 "frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 3271 "frontend/parser.cpp"
    break;

  case 348: // expr_str: expr_float "++" expr_bool
#line 705 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3277 "frontend/parser.cpp"
    break;

  case 349: // expr_str: expr_float "++" expr_none
#line 706 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 3283 "frontend/parser.cpp"
    break;

  case 350: // expr_str: expr_bool "++" expr_str
#line 707 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 3289 "frontend/parser.cpp"
    break;

  case 351: // expr_str: expr_bool "++" expr_int
#line 708 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 3295 "frontend/parser.cpp"
    break;

  case 352: // expr_str: expr_bool "++" expr_float
#line 709 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 3301 "frontend/parser.cpp"
    break;

  case 353: // expr_str: expr_bool "++" expr_bool
#line 710 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3307 "frontend/parser.cpp"
    break;

  case 354: // expr_str: expr_bool "++" expr_none
#line 711 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 3313 "frontend/parser.cpp"
    break;

  case 355: // expr_str: expr_none "++" expr_str
#line 712 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 3319 "frontend/parser.cpp"
    break;

  case 356: // expr_str: expr_none "++" expr_int
#line 713 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 3325 "frontend/parser.cpp"
    break;

  case 357: // expr_str: expr_none "++" expr_float
#line 714 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 3331 "frontend/parser.cpp"
    break;

  case 358: // expr_str: expr_none "++" expr_bool
#line 715 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3337 "frontend/parser.cpp"
    break;

  case 359: // expr_str: expr_none "++" expr_none
#line 716 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 3343 "frontend/parser.cpp"
    break;

  case 360: // expr_bool: "bool"
#line 720 "frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 3349 "frontend/parser.cpp"
    break;

  case 361: // expr_bool: "(" expr_bool ")"
#line 721 "frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 3355 "frontend/parser.cpp"
    break;

  case 362: // expr_bool: "not" expr_bool
#line 722 "frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 3361 "frontend/parser.cpp"
    break;

  case 363: // expr_bool: expr_bool "or" expr_bool
#line 723 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 3367 "frontend/parser.cpp"
    break;

  case 364: // expr_bool: expr_bool "and" expr_bool
#line 724 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 3373 "frontend/parser.cpp"
    break;

  case 365: // expr_bool: expr_bool "==" expr_bool
#line 726 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 3379 "frontend/parser.cpp"
    break;

  case 366: // expr_bool: expr_int "==" expr_int
#line 727 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 3385 "frontend/parser.cpp"
    break;

  case 367: // expr_bool: expr_int "==" expr_float
#line 728 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 3391 "frontend/parser.cpp"
    break;

  case 368: // expr_bool: expr_float "==" expr_float
#line 729 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 3397 "frontend/parser.cpp"
    break;

  case 369: // expr_bool: expr_float "==" expr_int
#line 730 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 3403 "frontend/parser.cpp"
    break;

  case 370: // expr_bool: expr_str "==" expr_str
#line 731 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 3409 "frontend/parser.cpp"
    break;

  case 371: // expr_bool: expr_none "==" expr_none
#line 732 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 3415 "frontend/parser.cpp"
    break;

  case 372: // expr_bool: expr_bool "!=" expr_bool
#line 734 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 3421 "frontend/parser.cpp"
    break;

  case 373: // expr_bool: expr_int "!=" expr_int
#line 735 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 3427 "frontend/parser.cpp"
    break;

  case 374: // expr_bool: expr_int "!=" expr_float
#line 736 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 3433 "frontend/parser.cpp"
    break;

  case 375: // expr_bool: expr_float "!=" expr_float
#line 737 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 3439 "frontend/parser.cpp"
    break;

  case 376: // expr_bool: expr_float "!=" expr_int
#line 738 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 3445 "frontend/parser.cpp"
    break;

  case 377: // expr_bool: expr_str "!=" expr_str
#line 739 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 3451 "frontend/parser.cpp"
    break;

  case 378: // expr_bool: expr_none "!=" expr_none
#line 740 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 3457 "frontend/parser.cpp"
    break;

  case 379: // expr_bool: expr_int ">" expr_int
#line 742 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 3463 "frontend/parser.cpp"
    break;

  case 380: // expr_bool: expr_int ">" expr_float
#line 743 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 3469 "frontend/parser.cpp"
    break;

  case 381: // expr_bool: expr_float ">" expr_float
#line 744 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 3475 "frontend/parser.cpp"
    break;

  case 382: // expr_bool: expr_float ">" expr_int
#line 745 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 3481 "frontend/parser.cpp"
    break;

  case 383: // expr_bool: expr_str ">" expr_str
#line 746 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 3487 "frontend/parser.cpp"
    break;

  case 384: // expr_bool: expr_int "<" expr_int
#line 748 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 3493 "frontend/parser.cpp"
    break;

  case 385: // expr_bool: expr_int "<" expr_float
#line 749 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 3499 "frontend/parser.cpp"
    break;

  case 386: // expr_bool: expr_float "<" expr_float
#line 750 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 3505 "frontend/parser.cpp"
    break;

  case 387: // expr_bool: expr_float "<" expr_int
#line 751 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 3511 "frontend/parser.cpp"
    break;

  case 388: // expr_bool: expr_str "<" expr_str
#line 752 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 3517 "frontend/parser.cpp"
    break;

  case 389: // expr_bool: expr_int ">=" expr_int
#line 754 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 3523 "frontend/parser.cpp"
    break;

  case 390: // expr_bool: expr_int ">=" expr_float
#line 755 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 3529 "frontend/parser.cpp"
    break;

  case 391: // expr_bool: expr_float ">=" expr_float
#line 756 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 3535 "frontend/parser.cpp"
    break;

  case 392: // expr_bool: expr_float ">=" expr_int
#line 757 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 3541 "frontend/parser.cpp"
    break;

  case 393: // expr_bool: expr_str ">=" expr_str
#line 758 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 3547 "frontend/parser.cpp"
    break;

  case 394: // expr_bool: expr_int "<=" expr_int
#line 760 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 3553 "frontend/parser.cpp"
    break;

  case 395: // expr_bool: expr_int "<=" expr_float
#line 761 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 3559 "frontend/parser.cpp"
    break;

  case 396: // expr_bool: expr_float "<=" expr_float
#line 762 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 3565 "frontend/parser.cpp"
    break;

  case 397: // expr_bool: expr_float "<=" expr_int
#line 763 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 3571 "frontend/parser.cpp"
    break;

  case 398: // expr_bool: expr_str "<=" expr_str
#line 764 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 3577 "frontend/parser.cpp"
    break;

  case 399: // expr_bool: expr_str "in" expr_str
#line 766 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[0].value.as < std::string > ().find(yystack_[2].value.as < std::string > ()) != std::string::npos; }
#line 3583 "frontend/parser.cpp"
    break;

  case 406: // mattype: "identifier" matsq
#line 780 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3589 "frontend/parser.cpp"
    break;

  case 407: // mattype: "'int'" matsq
#line 781 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(INT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3595 "frontend/parser.cpp"
    break;

  case 408: // mattype: "'float'" matsq
#line 782 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(FLOAT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3601 "frontend/parser.cpp"
    break;

  case 409: // mattype: "'string'" matsq
#line 783 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(STRING_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3607 "frontend/parser.cpp"
    break;

  case 410: // mattype: "'bool'" matsq
#line 784 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(BOOL_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3613 "frontend/parser.cpp"
    break;

  case 411: // mattype: "any" matsq
#line 785 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(ANY_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3619 "frontend/parser.cpp"
    break;

  case 419: // matsq: "[" "]"
#line 794 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(scanner->parseInt(-1)); }
#line 3625 "frontend/parser.cpp"
    break;

  case 420: // matsq: "[" "]" matsq
#line 796 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), scanner->parseInt(-1)); }
#line 3631 "frontend/parser.cpp"
    break;

  case 421: // type: "'int'" "?"
#line 801 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, true, true); }
#line 3637 "frontend/parser.cpp"
    break;

  case 422: // type: "'float'" "?"
#line 802 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, true, true); }
#line 3643 "frontend/parser.cpp"
    break;

  case 423: // type: "'string'" "?"
#line 803 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, true, true); }
#line 3649 "frontend/parser.cpp"
    break;

  case 424: // type: "'bool'" "?"
#line 804 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, true, true); }
#line 3655 "frontend/parser.cpp"
    break;

  case 425: // type: "identifier" "?"
#line 805 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[1].value.as < std::string > (), true, true); }
#line 3661 "frontend/parser.cpp"
    break;

  case 428: // type: mattype "?"
#line 808 "frontend/parser.yy"
       { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 3667 "frontend/parser.cpp"
    break;

  case 429: // type: "'int'"
#line 809 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, false, true); }
#line 3673 "frontend/parser.cpp"
    break;

  case 430: // type: "'float'"
#line 810 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, false, true); }
#line 3679 "frontend/parser.cpp"
    break;

  case 431: // type: "'string'"
#line 811 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, false, true); }
#line 3685 "frontend/parser.cpp"
    break;

  case 432: // type: "'bool'"
#line 812 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, false, true); }
#line 3691 "frontend/parser.cpp"
    break;

  case 433: // type: "any"
#line 813 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(ANY_CSTR, false, true); }
#line 3697 "frontend/parser.cpp"
    break;

  case 434: // type: "identifier"
#line 814 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[0].value.as < std::string > (), false, true); }
#line 3703 "frontend/parser.cpp"
    break;

  case 435: // type: "external identifier"
#line 815 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExtType(yystack_[0].value.as < std::string > (), false); }
#line 3709 "frontend/parser.cpp"
    break;

  case 437: // type: mattype
#line 817 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 3715 "frontend/parser.cpp"
    break;


#line 3719 "frontend/parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -630;

  const short  Parser ::yytable_ninf_ = -436;

  const short
   Parser ::yypact_[] =
  {
    1168,  -630,  -630,  -630,  -630,  -630,  -630,  -630,   368,    54,
      12,   414,   414,   -50,    42,   -43,  -630,  -630,  -630,  -630,
     414,  -630,  -630,    57,    93,   157,   196,   -36,    -4,    92,
      95,    64,  1092,  -630,  -630,    72,    72,  -630,  -630,    68,
    -630,    74,  -630,  1245,  -630,    79,  -630,  -630,    72,    72,
      72,   963,  2289,  -630,   416,   759,   548,  1735,  1930,   844,
     488,   200,    38,     2,   109,    41,   367,  2036,   114,   416,
     759,   356,  1007,  1314,   623,   694,   414,  -630,  -630,   184,
     546,   546,   387,  -630,  -630,  -630,  -630,   249,   548,  1735,
    1930,   844,  -630,   249,  -630,   488,    73,   128,  -630,   117,
    -630,  -630,    42,  -630,    42,  -630,    42,  -630,    42,  -630,
     214,   667,  -630,   186,   194,    -1,   995,    42,  -630,  -630,
    -630,   530,  1141,  -630,  -630,  -630,  -630,  -630,  2169,  -630,
    -630,  -630,  -630,  -630,  1201,   414,   202,  1928,  -630,  -630,
     159,   414,  -630,  -630,  -630,   414,   414,   414,   414,   414,
     414,   414,   414,   414,   414,   414,   414,   414,  -630,   274,
     530,   414,   414,   414,   414,   414,   414,   414,   414,   414,
     414,  1301,   414,   414,   414,   414,   414,   414,   414,   414,
     414,   414,   414,   136,  -630,   530,   414,   414,   414,   414,
    -630,   414,   414,   414,   414,   414,   414,   414,   414,   414,
     414,   414,   414,   414,   414,   414,   414,   414,   414,   414,
     414,   414,   414,   414,   414,   414,   414,   414,   414,   414,
     414,   414,   414,   414,   414,   414,   414,   414,   414,   414,
     414,   414,   414,   414,   414,   414,   414,   414,   414,   414,
     414,   414,   414,   414,   414,   414,    42,  -630,  -630,   733,
      13,   211,  -630,   530,  -630,  -630,  -630,  -630,  -630,  -630,
    -630,   216,   236,  -630,   106,  1113,  1621,   387,   387,  -630,
     546,   546,   546,   546,   546,   546,   387,   387,   387,   387,
     387,   546,   546,   546,   546,   546,   546,   414,    42,   -43,
    -630,  -630,  -630,  -630,   250,    23,  -630,   253,   201,   197,
     263,    14,   389,   561,  2289,   262,   247,  1735,  -630,   199,
     125,   208,   282,  -630,   256,   223,   282,  -630,    91,   102,
     254,     9,   289,  2169,  -630,  1406,   292,   295,  -630,  2540,
    -630,  -630,  -630,  -630,  -630,  -630,  -630,  -630,  -630,  -630,
    -630,  -630,  -630,    30,  -630,   318,   327,   297,   841,  1029,
     327,   841,  1029,   374,   306,   307,   374,   306,   307,   374,
     306,   307,   374,   306,   307,  2322,   666,  1849,  2528,   461,
     850,  2382,   668,  2352,   696,  2412,   567,   266,   282,  2172,
    1992,  2442,  1366,  2472,  1408,   831,   933,   831,   933,  2502,
      18,  -630,  -630,  2539,  1171,   397,  -630,  2502,    18,  -630,
    -630,  2539,  1171,   397,  -630,   609,  2233,   960,   338,   609,
    2233,   960,   338,   609,  2233,   960,   338,   609,  2233,   960,
     338,  -630,  -630,   329,   327,   297,  2412,   749,  2502,    18,
    2502,    18,  2322,   666,  1849,  2528,   461,   850,  2412,   749,
    2502,  -630,  2502,  -630,  2412,   749,  2502,  -630,  2502,  -630,
     327,   841,  1029,   327,   841,  1029,   374,   306,   307,   374,
     306,   307,   374,   306,   307,   374,   307,  2322,   666,  1849,
    2528,   461,   850,  2412,   749,  2172,  1992,  2442,  1366,  2472,
    1408,   831,   933,   831,   933,  2502,  2539,  1171,  2502,  2539,
    1171,   609,  2233,   960,   609,  2233,   960,   609,  2233,   960,
     609,  2233,   960,   327,   841,  1029,   327,   841,  1029,   374,
     306,   307,   374,   306,   307,   374,   306,   307,   374,   306,
     307,  2322,   666,  1849,  2528,   461,   850,  2412,   749,  2502,
    2539,  1171,  2502,  2539,  1171,   609,  2233,   960,   609,  2233,
     960,   609,  2233,   960,   609,  2233,   960,   342,  2322,   666,
    1849,  2528,   461,   850,  2412,   749,   567,  2502,   397,  2502,
     397,   609,   338,   609,   338,   609,   338,   609,   338,  2322,
     666,  1849,  2528,   461,   850,  2382,   668,  2352,   696,  2412,
     749,  2502,  -630,  2502,  -630,  -630,  -630,   330,   414,   636,
     343,  -630,  -630,   414,  -630,  1498,  -630,   387,   387,   387,
     387,   387,  1068,  1087,  1068,  1087,   319,   341,   319,   341,
     319,   341,  1891,   341,  1282,   876,   954,  1062,  1062,  1068,
    1087,  1068,  1087,   319,   341,   319,   341,   319,   341,   319,
     341,  -630,  -630,  -630,   172,   172,  -630,   273,   344,   359,
      10,  -630,  1427,   218,   305,   345,   377,    15,  2036,   391,
     153,  1007,  -630,  -630,   414,   414,   372,  -630,   362,  -630,
    -630,  -630,   530,   530,   530,  -630,  1245,  1671,   413,   414,
    1245,  -630,   414,  -630,  -630,  -630,  -630,  -630,  -630,   218,
     426,  -630,  -630,   394,   394,  -630,  -630,  -630,   410,  -630,
     383,  -630,   172,   396,  -630,  -630,  -630,   454,   218,  -630,
    -630,  -630,   398,   414,   363,   432,  2259,   433,  1687,   438,
     441,   443,   444,  -630,   452,  -630,   447,   409,  -630,  -630,
     218,  -630,   414,  -630,   414,   381,    22,  -630,   414,  -630,
     428,  1245,  1245,  1245,  1245,  1245,  1245,  -630,  -630,  -630,
    -630,  1245,  -630,  -630,  -630,  -630,  -630,  -630,   414,  -630,
    -630,  -630,  -630,  -630,  -630,  -630,  -630
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     9,   298,   312,   333,   360,   289,     0,     0,
       0,     0,     0,     0,   433,     0,    52,    44,    46,    48,
      36,    33,    34,   429,   430,   431,   432,     0,     0,   101,
     102,     0,     0,     4,    10,     0,     0,    35,    15,     0,
      17,     0,    18,     0,    16,     0,    19,    20,     0,     0,
       0,     0,    94,   281,    93,    95,    96,    97,    98,    99,
     100,   436,   437,     0,   289,   101,   102,     0,   281,     0,
       0,     0,     0,     0,     0,     0,     0,   273,   278,     0,
       0,     0,     0,   103,   104,   299,   313,   260,     0,     0,
       0,     0,   362,   261,   301,     0,     0,     0,   411,    31,
      30,    37,   421,   407,   422,   408,   423,   409,   424,   410,
       0,     0,    68,     0,     0,     0,     0,   425,   123,   291,
     406,     0,     0,   426,   124,   292,     1,     3,     0,     5,
       8,     7,    14,    21,     0,     0,     0,     0,    28,    29,
       0,     0,    12,    13,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   125,     0,     0,     0,     0,     0,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   427,   412,   428,     0,
      74,     0,   290,     0,   105,   282,   293,   300,   314,   334,
     361,     0,     0,   274,     0,     0,     0,     0,     0,   301,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   419,     0,
     414,   415,   416,   417,     0,     0,   403,     0,   434,   435,
       0,   404,     0,     0,   287,     0,     0,   286,   294,     0,
       0,   113,   119,   413,     0,   114,   120,     6,   434,   435,
       0,     0,     0,     0,    23,     0,     0,     0,    90,    89,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,   106,     0,    91,     0,   155,   153,   150,   151,
     160,   158,   159,   137,   135,   136,   142,   140,   141,   147,
     145,   146,   130,   132,   129,   272,   271,   267,   268,   269,
     270,   256,   255,   259,   258,   253,   252,   115,   121,   231,
     230,   237,   236,   234,   233,   163,   162,   166,   165,   211,
     209,   207,   202,   203,   204,   205,   206,   228,   226,   224,
     219,   220,   221,   222,   223,   173,   170,   171,   172,   187,
     184,   185,   186,   180,   177,   178,   179,   194,   191,   192,
     193,   126,   127,     0,   154,   152,   251,   244,   210,   208,
     227,   225,   266,   359,   356,   357,   355,   358,   249,   242,
     199,   371,   216,   378,   250,   243,   201,   200,   218,   217,
     148,   306,   332,   156,   305,   329,   133,   302,   320,   138,
     303,   323,   143,   304,   326,   131,   317,   262,   344,   341,
     342,   340,   343,   245,   238,   229,   309,   235,   311,   232,
     310,   161,   307,   164,   308,   195,   366,   367,   212,   373,
     374,   167,   379,   380,   181,   384,   385,   174,   389,   390,
     188,   394,   395,   149,   331,   330,   157,   328,   327,   134,
     319,   318,   139,   322,   321,   144,   325,   324,   128,   316,
     315,   263,   349,   346,   347,   345,   348,   246,   239,   196,
     369,   368,   213,   376,   375,   168,   382,   381,   182,   387,
     386,   175,   392,   391,   189,   397,   396,     0,   264,   339,
     336,   337,   335,   338,   247,   240,   399,   197,   370,   214,
     377,   169,   383,   183,   388,   176,   393,   190,   398,   265,
     354,   351,   352,   350,   353,   254,   364,   257,   363,   248,
     241,   198,   365,   215,   372,   418,   401,     0,     0,     0,
       0,   275,   276,     0,   279,     0,   299,     0,     0,     0,
       0,     0,   306,   332,   305,   329,   302,   320,   303,   323,
     304,   326,     0,   317,   309,   311,   310,   307,   308,   331,
     330,   328,   327,   319,   318,   322,   321,   325,   324,   316,
     315,    76,   420,    32,     0,    57,    54,     0,     0,     0,
       0,   402,     0,     0,     0,    73,     0,     0,   287,     0,
       0,   286,   288,   110,     0,     0,     0,   295,     0,   116,
     111,   117,     0,     0,     0,    74,     0,     0,    24,     0,
       0,   107,     0,   112,   118,   109,   108,   400,    75,     0,
       0,   277,   280,   306,   305,   302,   303,   304,     0,    58,
       0,    55,    59,    61,   405,    66,    71,     0,     0,    69,
     283,   284,     0,     0,     0,     0,   287,     0,   286,     0,
       0,     0,     0,    45,    25,    26,     0,    51,    92,    64,
       0,    56,     0,    60,     0,     0,     0,    67,     0,   296,
       0,     0,     0,     0,     0,     0,     0,    27,    47,    53,
      49,     0,    65,    63,    62,    72,    70,   285,     0,    39,
      42,    40,    43,    38,    41,    50,   297
  };

  const short
   Parser ::yypgoto_[] =
  {
    -630,  -630,  -130,   773,   -31,     6,  -629,  -480,  -630,   212,
    -630,  -630,  -630,  -630,  -630,  -630,  -630,  -630,  -630,  -630,
    -630,  -630,  -630,  -446,  -630,  -630,   437,  -630,   -87,   370,
    -630,   373,  -630,   533,  1918,     4,   431,   328,  -299,  -111,
     529,   622,   787,   -15,  -630,  1380,  1618,     0,   165,  -630,
    -247,  -630,    21,   -86
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    31,    32,   132,    33,   138,   139,   140,    35,   100,
      36,    37,    38,    39,    40,    41,    42,    43,    44,   740,
      45,   741,    46,   638,   639,    47,   113,   645,   646,    48,
      49,    50,   343,    51,    52,    53,    79,    69,   305,   650,
     184,    70,    88,   119,   310,    57,    58,    91,    95,    61,
     300,    62,   120,    63
  };

  const short
   Parser ::yytable_[] =
  {
      59,   129,   587,   306,   649,   111,    34,   325,    74,    59,
     314,   249,    68,   308,   695,   125,     3,     4,   249,   249,
      59,    80,   -68,   249,   249,   301,   635,    96,    81,   185,
     312,   249,    59,   186,    99,    98,   316,   636,    34,   309,
     671,   110,    82,    59,   103,   105,   107,   109,   321,   345,
     719,   125,   253,    97,   115,   642,   588,    76,     3,     4,
       5,     6,     7,     8,   126,     9,    77,   116,    97,   727,
      10,   672,   130,   112,   423,   131,    59,   134,    11,   250,
     637,    14,   247,   135,    12,   378,   665,   693,   141,    83,
      84,   742,   699,    23,    24,    25,    26,   317,   297,   746,
     298,   299,    97,   114,    97,   115,   121,   248,   115,   593,
       3,     4,     5,     6,     7,     8,   287,     9,   116,   252,
     547,   122,    10,   290,   255,   291,   102,   292,    59,   293,
      11,    65,    66,   662,    34,    59,    12,    59,   313,   657,
     288,    59,   306,    34,   663,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,   289,    59,
     117,   117,   104,   301,   123,    60,   658,   369,    97,  -434,
     376,   123,  -435,    75,    60,   635,    92,   395,   403,   408,
     412,   416,   420,    65,    66,    60,   713,   262,   688,   689,
     717,   436,   654,   667,   655,   302,   263,    60,     3,     4,
       5,     6,     7,   303,   471,     9,   288,    97,    60,   640,
      10,    97,    97,   421,   422,   323,   647,   294,    11,   590,
     589,   136,   326,   525,    12,   264,   106,   295,   591,   637,
      14,   137,   552,   556,   558,   560,   562,   564,   566,   568,
     573,    60,    23,    24,    25,    26,   723,   297,   592,   298,
     299,   749,   750,   751,   752,   753,   754,   264,   159,   653,
     160,   755,   111,   634,    59,   108,   123,   585,   660,   246,
     117,    65,    66,   641,   652,   171,   656,   659,     3,     4,
       5,     6,     7,     8,   342,     9,   654,    59,   655,   183,
      10,   249,   661,    60,   129,   654,   664,   655,    11,   666,
      60,   669,    60,    74,    12,   670,    60,    68,   185,   632,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    59,    60,    59,   203,   222,    54,    34,
     673,    34,   370,   372,   374,   674,   159,    54,   160,   275,
     677,   675,   396,   404,   163,   164,   165,   166,    54,   231,
     690,    65,    66,   171,   676,   681,   437,   654,   691,   655,
      54,   286,   692,   707,   710,   712,   256,   183,   654,   472,
     655,    54,     3,     4,     5,     6,    64,     8,   121,     9,
     115,   195,   696,   159,    10,   160,   697,   698,   526,   196,
     197,     3,    11,   122,   166,   694,   267,   553,    12,   643,
     171,   700,   704,   268,    54,   574,   576,   578,   231,   582,
     584,   599,   600,   601,   183,   703,   715,    82,     3,     4,
       5,     6,     7,     8,   721,     9,   722,   185,   644,    60,
      10,   186,   236,   237,   238,   239,   720,   728,    11,   724,
     730,   187,   731,   732,    12,    65,    66,    14,   733,   188,
     189,   734,    60,   735,   736,   737,    54,   738,   745,    23,
      24,    25,    26,    54,   297,    54,   298,   299,    75,    54,
     739,   748,   231,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,   233,    54,    60,   347,
      60,    65,    66,   725,   234,   235,   236,   237,   238,   239,
     251,   633,   680,   647,   320,   390,   398,   261,     0,   240,
     241,   242,    14,   243,   425,   427,   429,   431,   328,     0,
     439,   244,   245,   445,    23,    24,    25,    26,     0,   297,
       0,   298,   299,   474,     3,     4,     5,     6,     7,   303,
       0,     9,    78,   701,   702,     0,    10,     0,   640,   640,
       3,     4,   528,   101,    11,    80,   301,     0,   118,   124,
      12,   555,    81,     0,     0,     3,     4,     5,     6,    64,
     303,   580,     9,   195,     0,     0,    82,    10,   231,     0,
       0,   196,   197,   190,     0,    11,     0,     0,    59,     0,
       0,    12,    54,    59,   118,   124,     0,     0,   190,     0,
     234,   235,   236,   237,   238,   239,   640,    65,    66,    78,
       0,   726,     0,     0,     0,    54,     0,   747,   159,     0,
     160,     0,    55,     0,   161,   162,   163,   164,   165,   166,
       0,    55,     0,   259,   231,   171,   129,     0,    65,    66,
     175,   176,    55,     0,   232,     0,   679,     0,   233,   183,
       0,    54,     0,    54,    55,     0,   234,   235,   236,   237,
     238,   239,    59,    59,    59,    55,    59,    59,   322,    59,
      59,     0,    59,    34,   327,   644,     0,   296,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   192,   344,   243,    14,     0,     0,     0,    55,   193,
     194,   244,   245,    59,   260,     0,    23,    24,    25,    26,
       0,   297,     0,   298,   299,   240,   241,   242,   241,   243,
       0,   243,    59,     0,    59,    14,     0,   244,   245,   244,
     245,    59,    59,    59,    59,    59,    59,    23,    24,    25,
      26,    59,   297,   586,   298,   299,     0,     0,    59,     0,
      55,     0,     0,    60,     0,     0,     0,    55,    60,    55,
     185,     0,     0,    55,   186,     0,     0,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
     191,    55,   188,   189,   192,     0,     0,    56,     0,   366,
       0,    14,   193,   194,     0,    71,    56,   594,     0,   391,
     399,     0,     0,    23,    24,    25,    26,    56,   297,   133,
     298,   299,     0,   433,     0,   441,   443,     0,     0,    56,
     631,   142,   143,   144,   158,     0,   468,    60,    60,    60,
      56,    60,    60,     0,    60,    60,     0,    60,     0,     0,
     159,     0,   160,     0,     0,   522,   161,   162,   163,   164,
     165,   166,     0,     0,   549,   231,     0,   171,   200,   201,
     202,   203,   570,    56,     0,   232,     0,     0,    60,   233,
       0,   183,   241,   242,     0,   243,   190,   234,   235,   236,
     237,   238,   239,   244,   245,     0,    55,    60,     0,    60,
       0,   597,   598,   599,   600,   601,    60,    60,    60,    60,
      60,    60,     0,   276,     0,   278,    60,   279,   280,    55,
       0,     0,     0,    60,     0,    56,    54,     0,     0,   190,
       0,    54,    56,     0,    56,     0,     0,   190,    56,     0,
       0,     0,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    55,    56,    55,   198,   199,
     200,   201,   202,   203,   190,     0,   190,     0,   190,     0,
     190,     0,     0,   130,   392,   400,   131,     0,   190,   597,
     598,   599,   600,   601,   190,   217,   218,   219,   220,   221,
     222,   276,     0,   447,   449,   279,   280,     0,     0,     0,
      54,    54,    54,     0,    54,    54,     0,    54,    54,     0,
      54,     0,     0,   190,     0,     0,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   257,   156,   157,
       0,     0,   198,   199,   200,   201,   202,   203,   204,     0,
       0,    54,   205,     0,   206,   207,   208,     0,   209,   210,
     211,   212,   213,   214,   215,   216,   219,   220,   221,   222,
      54,    56,    54,    14,     0,     0,     0,   190,     0,    54,
      54,    54,    54,    54,    54,    23,    24,    25,    26,    54,
     297,     0,   298,   311,    56,     0,    54,   597,   598,   599,
     600,   601,     0,     0,   190,   272,   273,   274,   275,     0,
      71,     0,   127,   128,     0,     2,     3,     4,     5,     6,
       7,     8,     0,     9,   283,   284,   285,   286,    10,   190,
      56,     0,    56,     0,     0,     0,    11,     0,     0,     0,
       0,   678,    12,   257,     0,     0,   682,     0,   270,   271,
     272,   273,   274,   275,     0,     0,     0,     0,     0,     0,
     276,   277,   278,     0,   279,   280,     0,     0,     0,    13,
      14,    15,    16,     0,    17,    18,    19,    20,    21,    22,
       0,     0,    23,    24,    25,    26,    27,    28,     1,    29,
      30,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,     0,     0,    10,     0,   217,   218,   219,   220,
     221,   222,    11,     0,     0,   705,   709,   711,    12,    14,
       0,     0,   716,     0,     0,   718,   227,   228,   229,   230,
      55,    23,    24,    25,    26,    55,   297,     0,   298,   315,
       0,     0,     0,     0,     0,    13,    14,    15,    16,     0,
      17,    18,    19,    20,    21,    22,   729,     0,    23,    24,
      25,    26,    27,    28,     0,    29,    30,     0,   136,     3,
       4,     5,     6,     7,     8,   743,     9,   744,   137,    14,
       0,    10,     0,     0,     0,     0,     0,     0,     0,    11,
       0,    23,    24,    25,    26,    12,   297,     0,   318,   319,
       0,   756,     0,     0,    55,    55,    55,     0,    55,    55,
       0,    55,    55,     0,    55,     0,     0,   597,   598,   599,
     600,   601,    13,    14,    15,    16,     0,    17,    18,    19,
      20,    21,    22,   279,   280,    23,    24,    25,    26,    27,
      28,     0,    29,    30,   258,    55,     0,     0,     0,   217,
     218,   219,   220,   221,   222,   223,     0,     0,     0,   224,
       0,     0,     0,     0,    55,     0,    55,   225,   226,   227,
     228,   229,   230,    55,    55,    55,    55,    55,    55,    14,
       0,     0,     0,    55,     0,     0,     0,     0,     0,     0,
      55,    23,    24,    25,    26,    56,   297,     0,   298,   377,
      56,   198,   199,   200,   201,   202,   203,     0,    72,     0,
      85,    89,    94,   206,     0,   208,     0,   209,   210,   211,
     212,   213,   214,   215,   216,     0,     0,   128,     0,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
     668,     0,    10,   198,   199,   200,   201,   202,   203,     0,
      11,     0,     0,     0,     0,   206,    12,     0,     0,   209,
     210,   211,   212,   213,   214,   215,   216,     0,     0,    56,
      56,    56,     0,    56,    56,     0,    56,    56,     0,    56,
     265,    85,   269,    13,    14,    15,    16,     0,    17,    18,
      19,    20,    21,    22,     0,     0,    23,    24,    25,    26,
      27,    28,     0,    29,    30,    14,     0,     0,     0,     0,
      56,     0,     0,     0,   307,     0,     0,    23,    24,    25,
      26,   307,   297,     0,   298,   299,     0,     0,   257,    56,
       0,    56,     0,   597,   598,   599,   600,   601,    56,    56,
      56,    56,    56,    56,     0,   276,   277,   278,    56,   279,
     280,     0,     0,     0,     0,    56,     0,     0,     0,     0,
     307,   348,   351,   354,   357,   360,   363,   367,    89,    89,
      89,     0,   380,   382,   384,   386,   388,   393,   401,   406,
     410,   414,   418,     0,     0,   307,    89,    89,    89,    89,
       0,   434,    89,    89,    89,    89,    89,    89,   451,   454,
     457,   460,   463,    89,   469,    89,   476,   478,   480,   482,
     484,   486,   489,   492,   495,   498,   501,   504,   507,   510,
     513,   516,   519,   523,    89,   530,   533,   536,   539,   542,
     545,   307,   550,    89,    89,    89,    89,    89,    89,    89,
     571,    89,    89,    89,    89,    89,    73,     0,    86,    90,
      90,   258,     0,   307,     0,     0,   281,   282,   283,   284,
     285,   286,     0,     0,     0,     0,     0,   595,   596,     0,
     602,   604,   606,   608,   610,   612,   614,   615,   616,   617,
     618,   619,   621,   623,   625,   627,   629,     0,     0,     0,
       0,     0,   128,     0,     2,     3,     4,     5,     6,     7,
       8,     0,     9,   651,     0,   714,     0,    10,     0,     0,
       0,     0,     0,     0,     0,    11,     0,   -97,   266,    86,
       0,    12,   198,   199,   200,   201,   202,   203,   204,     0,
       0,     0,   205,     0,   206,   207,   208,     0,   209,   210,
     211,   212,   213,   214,   215,   216,     0,     0,    13,    14,
      15,    16,    90,    17,    18,    19,    20,    21,    22,    90,
       0,    23,    24,    25,    26,    27,    28,     0,    29,    30,
     198,   199,   200,   201,   202,   203,   204,     0,     0,     0,
     205,     0,   206,   207,   208,     0,   209,   210,   211,   212,
     213,   214,   215,   216,     0,     0,     0,     0,    90,   349,
     352,   355,   358,   361,   364,   368,    90,    90,    90,     0,
      90,    90,    90,    90,    90,   394,   402,   407,   411,   415,
     419,     0,     0,    90,    90,    90,    90,    90,     0,   435,
      90,    90,    90,    90,    90,    90,   452,   455,   458,   461,
     464,   466,   470,    90,    90,    90,    90,    90,    90,   487,
     490,   493,   496,   499,   502,   505,   508,   511,   514,   517,
     520,   524,    90,   531,   534,   537,   540,   543,   546,    90,
     551,    90,    90,    90,    90,    90,    90,    90,   572,    90,
      90,    90,    90,    90,   198,   199,   200,   201,   202,   203,
       0,    90,     0,     0,   205,     0,   206,   207,   208,     0,
     209,   210,   211,   212,   213,   214,   215,   216,   603,   605,
     607,   609,   611,   613,     0,     0,     0,     0,     0,   620,
     622,   624,   626,   628,   630,     0,   270,   271,   272,   273,
     274,   275,     0,     0,     0,     0,     0,     0,   276,   277,
     278,    73,   279,   280,     0,     0,    67,     0,     0,    87,
      93,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,   324,     0,    10,   217,   218,   219,   220,   221,
     222,   223,    11,     0,     0,   224,     0,     0,    12,     0,
       0,     0,     0,   225,   226,   227,   228,   229,   230,     0,
       0,     0,     0,     0,     0,     0,     0,   683,   684,   685,
     686,   687,     0,     0,     0,    13,    14,    15,    16,     0,
      17,    18,    19,    20,    21,    22,     0,     0,    23,    24,
      25,    26,    27,    28,     0,    29,    30,   198,   199,   200,
     201,   202,   203,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   209,   210,   211,   212,   213,   214,   215,
     216,     0,   304,     0,   307,   307,     0,     0,     0,   304,
       0,     0,   708,   708,   708,   159,   254,   160,     0,     0,
       0,   161,   162,   163,   164,   165,   166,   167,   168,   169,
       0,   170,   171,   172,   173,   174,     0,   175,   176,   177,
     178,   179,   180,   181,   182,     0,   183,     0,   304,   346,
     350,   353,   356,   359,   362,   365,   371,   373,   375,     0,
     379,   381,   383,   385,   387,   389,   397,   405,   409,   413,
     417,     0,     0,   304,   424,   426,   428,   430,   307,   432,
     438,   440,   442,   444,   446,   448,   450,   453,   456,   459,
     462,   465,   467,   473,   475,   477,   479,   481,   483,   485,
     488,   491,   494,   497,   500,   503,   506,   509,   512,   515,
     518,   521,   527,   529,   532,   535,   538,   541,   544,   304,
     548,   554,   557,   559,   561,   563,   565,   567,   569,   575,
     577,   579,   581,   583,     0,     0,     0,     0,     0,     0,
       0,   304,     2,     3,     4,     5,     6,     7,     8,     0,
       9,   159,     0,   160,     0,    10,     0,   161,   162,   163,
     164,   165,   166,    11,     0,     0,     0,     0,   171,    12,
       0,     0,     0,   175,   176,   177,   178,   179,   180,   181,
     182,     0,   183,     0,     0,     0,     0,     0,     0,     0,
       0,   648,     0,     0,     0,     0,    13,    14,    15,    16,
       0,    17,    18,    19,    20,    21,    22,     0,     0,    23,
      24,    25,    26,    27,    28,     0,    29,    30,   198,   199,
     200,   201,   202,   203,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   209,   210,     0,     0,   159,   -94,
     160,     0,    90,    90,   161,   162,   163,   164,   165,   166,
     167,   168,   169,     0,   170,   171,   172,   173,   174,     0,
     175,   176,   177,   178,   179,   180,   181,   182,   159,   183,
     160,     0,     0,     0,   161,   162,   163,   164,   165,   166,
     167,   168,   169,     0,   170,   171,   172,   173,   174,     0,
     175,   176,   177,   178,   179,   180,   181,   182,     0,   183,
       0,   159,     0,   160,     0,     0,     0,   161,   162,   163,
     164,   165,   166,     0,   168,   169,    90,   170,   171,   172,
     173,   174,     0,   175,   176,   177,   178,   179,   180,   181,
     182,   159,   183,   160,     0,     0,     0,   161,   162,   163,
     164,   165,   166,     0,   168,     0,     0,   170,   171,   172,
     173,   174,     0,   175,   176,   177,   178,   179,   180,   181,
     182,   159,   183,   160,     0,     0,     0,   161,   162,   163,
     164,   165,   166,     0,     0,     0,     0,   170,   171,   172,
     173,   174,     0,   175,   176,   177,   178,   179,   180,   181,
     182,   159,   183,   160,     0,     0,     0,   161,   162,   163,
     164,   165,   166,     0,     0,     0,     0,     0,   171,   172,
     173,   174,     0,   175,   176,   177,   178,   179,   180,   181,
     182,   159,   183,   160,     0,     0,     0,   161,   162,   163,
     164,   165,   166,     0,     0,     0,     0,     0,   171,   172,
       0,   174,     0,   175,   176,   177,   178,   179,   180,   181,
     182,   159,   183,   160,     0,     0,     0,   161,   162,   163,
     164,   165,   166,     0,     0,     0,     0,     0,   171,   172,
       0,     0,     0,   175,   176,   177,   178,   179,   180,   181,
     182,   159,   183,   160,     0,     0,     0,   161,   162,   163,
     164,   165,   166,     0,     0,     0,     0,     0,   171,     0,
       0,     0,     0,   175,   176,     0,     0,   179,   180,   181,
     182,     0,   183,   217,   218,   219,   220,   221,   222,     0,
       0,     0,     0,   224,   198,   199,   200,   201,   202,   203,
       0,   225,   226,   227,   228,   229,   230,     0,     0,     0,
     209,   210,   304,   304,   213,   214,   215,   216,     0,     0,
     706,   706,   706,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,     0,   156,   157,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   304
  };

  const short
   Parser ::yycheck_[] =
  {
       0,    32,   249,   114,   303,     9,     0,   137,     8,     9,
     121,     9,     8,    14,   643,    30,     4,     5,     9,     9,
      20,     9,     9,     9,     9,   111,     3,    77,    16,    11,
     116,     9,    32,    15,    77,    14,   122,    14,    32,    40,
      10,    77,    30,    43,    23,    24,    25,    26,   134,   160,
     679,    66,    11,    11,    13,    41,    43,     3,     4,     5,
       6,     7,     8,     9,     0,    11,    12,    26,    11,   698,
      16,    41,     0,    77,   185,     3,    76,     9,    24,    77,
      57,    58,    61,     9,    30,   171,    77,    77,     9,    77,
      78,   720,    77,    70,    71,    72,    73,   128,    75,    77,
      77,    78,    11,    11,    11,    13,    11,    69,    13,     3,
       4,     5,     6,     7,     8,     9,    43,    11,    26,    10,
     231,    26,    16,   102,    10,   104,    69,   106,   128,   108,
      24,    77,    78,    42,   128,   135,    30,   137,   117,    14,
      12,   141,   253,   137,    42,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,    41,   159,
      69,    69,    69,   249,    69,     0,    41,   167,    11,    77,
     170,    69,    77,     8,     9,     3,    11,   177,   178,   179,
     180,   181,   182,    77,    78,    20,   666,     3,   634,   635,
     670,   191,    39,   323,    41,     9,    12,    32,     4,     5,
       6,     7,     8,     9,   204,    11,    12,    11,    43,   295,
      16,    11,    11,    77,    78,    13,   302,     3,    24,     3,
       9,     3,    63,   223,    30,    41,    69,    13,    12,    57,
      58,    13,   232,   233,   234,   235,   236,   237,   238,   239,
     240,    76,    70,    71,    72,    73,   692,    75,    12,    77,
      78,   731,   732,   733,   734,   735,   736,    41,     9,    12,
      11,   741,     9,    13,   264,    69,    69,   246,    12,    69,
      69,    77,    78,    10,    12,    26,    77,    69,     4,     5,
       6,     7,     8,     9,    10,    11,    39,   287,    41,    40,
      16,     9,    69,   128,   325,    39,    42,    41,    24,    10,
     135,     9,   137,   303,    30,    10,   141,   303,    11,   288,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   323,   159,   325,    20,    20,     0,   323,
      12,   325,   167,   168,   169,    69,     9,     9,    11,    20,
      10,    12,   177,   178,    17,    18,    19,    20,    20,    11,
      77,    77,    78,    26,    12,    12,   191,    39,    14,    41,
      32,    20,     3,   662,   663,   664,    10,    40,    39,   204,
      41,    43,     4,     5,     6,     7,     8,     9,    11,    11,
      13,    25,    77,     9,    16,    11,    41,    10,   223,    33,
      34,     4,    24,    26,    20,   642,     9,   232,    30,    10,
      26,    10,    40,    16,    76,   240,   241,   242,    11,   244,
     245,    17,    18,    19,    40,    43,     3,    30,     4,     5,
       6,     7,     8,     9,    14,    11,    43,    11,    39,   264,
      16,    15,    35,    36,    37,    38,    10,    39,    24,    43,
      77,    25,    10,    10,    30,    77,    78,    58,    10,    33,
      34,    10,   287,    10,    10,     3,   128,    10,    77,    70,
      71,    72,    73,   135,    75,   137,    77,    78,   303,   141,
      61,    43,    11,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,    25,   159,   323,   161,
     325,    77,    78,    39,    33,    34,    35,    36,    37,    38,
      63,   289,   589,   589,   134,   177,   178,    76,    -1,    21,
      22,    23,    58,    25,   186,   187,   188,   189,   145,    -1,
     192,    33,    34,   195,    70,    71,    72,    73,    -1,    75,
      -1,    77,    78,   205,     4,     5,     6,     7,     8,     9,
      -1,    11,     9,   654,   655,    -1,    16,    -1,   634,   635,
       4,     5,   224,    20,    24,     9,   642,    -1,    29,    30,
      30,   233,    16,    -1,    -1,     4,     5,     6,     7,     8,
       9,   243,    11,    25,    -1,    -1,    30,    16,    11,    -1,
      -1,    33,    34,    54,    -1,    24,    -1,    -1,   588,    -1,
      -1,    30,   264,   593,    65,    66,    -1,    -1,    69,    -1,
      33,    34,    35,    36,    37,    38,   692,    77,    78,    76,
      -1,   697,    -1,    -1,    -1,   287,    -1,   728,     9,    -1,
      11,    -1,     0,    -1,    15,    16,    17,    18,    19,    20,
      -1,     9,    -1,    10,    11,    26,   667,    -1,    77,    78,
      31,    32,    20,    -1,    21,    -1,    10,    -1,    25,    40,
      -1,   323,    -1,   325,    32,    -1,    33,    34,    35,    36,
      37,    38,   662,   663,   664,    43,   666,   667,   135,   669,
     670,    -1,   672,   667,   141,    39,    -1,    10,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,    25,   159,    25,    58,    -1,    -1,    -1,    76,    33,
      34,    33,    34,   703,    10,    -1,    70,    71,    72,    73,
      -1,    75,    -1,    77,    78,    21,    22,    23,    22,    25,
      -1,    25,   722,    -1,   724,    58,    -1,    33,    34,    33,
      34,   731,   732,   733,   734,   735,   736,    70,    71,    72,
      73,   741,    75,    10,    77,    78,    -1,    -1,   748,    -1,
     128,    -1,    -1,   588,    -1,    -1,    -1,   135,   593,   137,
      11,    -1,    -1,   141,    15,    -1,    -1,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
      21,   159,    33,    34,    25,    -1,    -1,     0,    -1,   167,
      -1,    58,    33,    34,    -1,     8,     9,   264,    -1,   177,
     178,    -1,    -1,    70,    71,    72,    73,    20,    75,    36,
      77,    78,    -1,   191,    -1,   193,   194,    -1,    -1,    32,
     287,    48,    49,    50,    51,    -1,   204,   662,   663,   664,
      43,   666,   667,    -1,   669,   670,    -1,   672,    -1,    -1,
       9,    -1,    11,    -1,    -1,   223,    15,    16,    17,    18,
      19,    20,    -1,    -1,   232,    11,    -1,    26,    17,    18,
      19,    20,   240,    76,    -1,    21,    -1,    -1,   703,    25,
      -1,    40,    22,    23,    -1,    25,   347,    33,    34,    35,
      36,    37,    38,    33,    34,    -1,   264,   722,    -1,   724,
      -1,    15,    16,    17,    18,    19,   731,   732,   733,   734,
     735,   736,    -1,    27,    -1,    29,   741,    31,    32,   287,
      -1,    -1,    -1,   748,    -1,   128,   588,    -1,    -1,   390,
      -1,   593,   135,    -1,   137,    -1,    -1,   398,   141,    -1,
      -1,    -1,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   323,   159,   325,    15,    16,
      17,    18,    19,    20,   425,    -1,   427,    -1,   429,    -1,
     431,    -1,    -1,     0,   177,   178,     3,    -1,   439,    15,
      16,    17,    18,    19,   445,    15,    16,    17,    18,    19,
      20,    27,    -1,   196,   197,    31,    32,    -1,    -1,    -1,
     662,   663,   664,    -1,   666,   667,    -1,   669,   670,    -1,
     672,    -1,    -1,   474,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    10,    55,    56,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,   703,    25,    -1,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    17,    18,    19,    20,
     722,   264,   724,    58,    -1,    -1,    -1,   528,    -1,   731,
     732,   733,   734,   735,   736,    70,    71,    72,    73,   741,
      75,    -1,    77,    78,   287,    -1,   748,    15,    16,    17,
      18,    19,    -1,    -1,   555,    17,    18,    19,    20,    -1,
     303,    -1,     0,     1,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    17,    18,    19,    20,    16,   580,
     323,    -1,   325,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,   588,    30,    10,    -1,    -1,   593,    -1,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    -1,    31,    32,    -1,    -1,    -1,    57,
      58,    59,    60,    -1,    62,    63,    64,    65,    66,    67,
      -1,    -1,    70,    71,    72,    73,    74,    75,     0,    77,
      78,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      -1,    -1,    -1,    -1,    16,    -1,    15,    16,    17,    18,
      19,    20,    24,    -1,    -1,   662,   663,   664,    30,    58,
      -1,    -1,   669,    -1,    -1,   672,    35,    36,    37,    38,
     588,    70,    71,    72,    73,   593,    75,    -1,    77,    78,
      -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    66,    67,   703,    -1,    70,    71,
      72,    73,    74,    75,    -1,    77,    78,    -1,     3,     4,
       5,     6,     7,     8,     9,   722,    11,   724,    13,    58,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    70,    71,    72,    73,    30,    75,    -1,    77,    78,
      -1,   748,    -1,    -1,   662,   663,   664,    -1,   666,   667,
      -1,   669,   670,    -1,   672,    -1,    -1,    15,    16,    17,
      18,    19,    57,    58,    59,    60,    -1,    62,    63,    64,
      65,    66,    67,    31,    32,    70,    71,    72,    73,    74,
      75,    -1,    77,    78,    10,   703,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    -1,   722,    -1,   724,    33,    34,    35,
      36,    37,    38,   731,   732,   733,   734,   735,   736,    58,
      -1,    -1,    -1,   741,    -1,    -1,    -1,    -1,    -1,    -1,
     748,    70,    71,    72,    73,   588,    75,    -1,    77,    78,
     593,    15,    16,    17,    18,    19,    20,    -1,     8,    -1,
      10,    11,    12,    27,    -1,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,     1,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    -1,    -1,
      14,    -1,    16,    15,    16,    17,    18,    19,    20,    -1,
      24,    -1,    -1,    -1,    -1,    27,    30,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,   662,
     663,   664,    -1,   666,   667,    -1,   669,   670,    -1,   672,
      80,    81,    82,    57,    58,    59,    60,    -1,    62,    63,
      64,    65,    66,    67,    -1,    -1,    70,    71,    72,    73,
      74,    75,    -1,    77,    78,    58,    -1,    -1,    -1,    -1,
     703,    -1,    -1,    -1,   114,    -1,    -1,    70,    71,    72,
      73,   121,    75,    -1,    77,    78,    -1,    -1,    10,   722,
      -1,   724,    -1,    15,    16,    17,    18,    19,   731,   732,
     733,   734,   735,   736,    -1,    27,    28,    29,   741,    31,
      32,    -1,    -1,    -1,    -1,   748,    -1,    -1,    -1,    -1,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,    -1,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,    -1,    -1,   185,   186,   187,   188,   189,
      -1,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,     8,    -1,    10,    11,
      12,    10,    -1,   253,    -1,    -1,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,   267,   268,    -1,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,    -1,    -1,    -1,
      -1,    -1,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,   303,    -1,    14,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    10,    80,    81,
      -1,    30,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    25,    -1,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    57,    58,
      59,    60,   114,    62,    63,    64,    65,    66,    67,   121,
      -1,    70,    71,    72,    73,    74,    75,    -1,    77,    78,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      25,    -1,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,    -1,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,   185,   186,   187,   188,   189,    -1,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,    15,    16,    17,    18,    19,    20,
      -1,   253,    -1,    -1,    25,    -1,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,   270,   271,
     272,   273,   274,   275,    -1,    -1,    -1,    -1,    -1,   281,
     282,   283,   284,   285,   286,    -1,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,   303,    31,    32,    -1,    -1,     8,    -1,    -1,    11,
      12,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      -1,    -1,    14,    -1,    16,    15,    16,    17,    18,    19,
      20,    21,    24,    -1,    -1,    25,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   597,   598,   599,
     600,   601,    -1,    -1,    -1,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    66,    67,    -1,    -1,    70,    71,
      72,    73,    74,    75,    -1,    77,    78,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,   114,    -1,   654,   655,    -1,    -1,    -1,   121,
      -1,    -1,   662,   663,   664,     9,    10,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    40,    -1,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,    -1,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,   185,   186,   187,   188,   189,   728,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   253,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,     9,    -1,    11,    -1,    16,    -1,    15,    16,    17,
      18,    19,    20,    24,    -1,    -1,    -1,    -1,    26,    30,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   303,    -1,    -1,    -1,    -1,    57,    58,    59,    60,
      -1,    62,    63,    64,    65,    66,    67,    -1,    -1,    70,
      71,    72,    73,    74,    75,    -1,    77,    78,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    -1,    -1,     9,    10,
      11,    -1,   654,   655,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,     9,    40,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    40,
      -1,     9,    -1,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    -1,    22,    23,   728,    25,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,     9,    40,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    -1,    22,    -1,    -1,    25,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,     9,    40,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,     9,    40,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,     9,    40,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,
      -1,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,     9,    40,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,     9,    40,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,    -1,
      -1,    -1,    -1,    31,    32,    -1,    -1,    35,    36,    37,
      38,    -1,    40,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    25,    15,    16,    17,    18,    19,    20,
      -1,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      31,    32,   654,   655,    35,    36,    37,    38,    -1,    -1,
     662,   663,   664,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   728
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
      21,    22,    23,    25,    33,    34,    69,   132,    69,     9,
      77,   106,    10,    11,    10,    10,    10,    10,    10,    10,
      10,   116,     3,    12,    41,   125,   126,     9,    16,   125,
      15,    16,    17,    18,    19,    20,    27,    28,    29,    31,
      32,    15,    16,    17,    18,    19,    20,    43,    12,    41,
     132,   132,   132,   132,     3,    13,    10,    75,    77,    78,
     130,   133,     9,     9,   114,   118,   119,   125,    14,    40,
     124,    78,   133,   132,   119,    78,   133,    84,    77,    78,
     109,   133,   113,    13,    14,    82,    63,   113,   111,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,    10,   112,   113,   119,   114,   117,   125,   126,
     114,   125,   126,   114,   125,   126,   114,   125,   126,   114,
     125,   126,   114,   125,   126,   114,   121,   125,   126,   127,
     128,   114,   128,   114,   128,   114,   127,    78,   133,   114,
     125,   114,   125,   114,   125,   114,   125,   114,   125,   114,
     117,   121,   122,   125,   126,   127,   128,   114,   117,   121,
     122,   125,   126,   127,   128,   114,   125,   126,   127,   114,
     125,   126,   127,   114,   125,   126,   127,   114,   125,   126,
     127,    77,    78,   119,   114,   117,   114,   117,   114,   117,
     114,   117,   114,   121,   125,   126,   127,   128,   114,   117,
     114,   121,   114,   121,   114,   117,   114,   122,   114,   122,
     114,   125,   126,   114,   125,   126,   114,   125,   126,   114,
     125,   126,   114,   125,   126,   114,   126,   114,   121,   125,
     126,   127,   128,   114,   117,   114,   125,   114,   125,   114,
     125,   114,   125,   114,   125,   114,   125,   126,   114,   125,
     126,   114,   125,   126,   114,   125,   126,   114,   125,   126,
     114,   125,   126,   114,   125,   126,   114,   125,   126,   114,
     125,   126,   114,   125,   126,   114,   125,   126,   114,   125,
     126,   114,   121,   125,   126,   127,   128,   114,   117,   114,
     125,   126,   114,   125,   126,   114,   125,   126,   114,   125,
     126,   114,   125,   126,   114,   125,   126,   119,   114,   121,
     125,   126,   127,   128,   114,   117,   127,   114,   127,   114,
     127,   114,   127,   114,   127,   114,   127,   114,   127,   114,
     121,   125,   126,   127,   128,   114,   128,   114,   128,   114,
     117,   114,   128,   114,   128,   132,    10,   130,    43,     9,
       3,    12,    12,     3,   113,   125,   125,    15,    16,    17,
      18,    19,   125,   126,   125,   126,   125,   126,   125,   126,
     125,   126,   125,   126,   125,   125,   125,   125,   125,   125,
     126,   125,   126,   125,   126,   125,   126,   125,   126,   125,
     126,   113,   132,    89,    13,     3,    14,    57,   103,   104,
     133,    10,    41,    10,    39,   107,   108,   133,   114,   118,
     119,   125,    12,    12,    39,    41,    77,    14,    41,    69,
      12,    69,    42,    42,    42,    77,    10,    82,    14,     9,
      10,    10,    41,    12,    69,    12,    12,    10,   113,    10,
     108,    12,   113,   125,   125,   125,   125,   125,   103,   103,
      77,    14,     3,    77,   130,    86,    77,    41,    10,    77,
      10,   119,   119,    43,    40,   113,   114,   118,   125,   113,
     118,   113,   118,    87,    14,     3,   113,    87,   113,    86,
      10,    14,    43,   103,    43,    39,   133,    86,    39,   113,
      77,    10,    10,    10,    10,    10,    10,     3,    10,    61,
      99,   101,    86,   113,   113,    77,    77,   119,    43,    87,
      87,    87,    87,    87,    87,    87,   113
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
     107,   108,   108,   108,   109,   110,   110,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   112,   112,   113,   113,   113,   113,   113,   113,   113,
     113,   114,   114,   114,   114,   114,   114,   114,   114,   114,
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
     114,   114,   114,   115,   115,   115,   115,   115,   116,   116,
     116,   117,   117,   118,   118,   118,   119,   119,   120,   121,
     121,   122,   122,   122,   123,   123,   124,   124,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     129,   129,   129,   129,   130,   130,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   132,
     132,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133
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
       4,     2,     4,     1,     2,     4,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     3,     4,     4,     4,
       4,     4,     4,     3,     3,     3,     4,     4,     4,     3,
       3,     3,     2,     2,     2,     2,     3,     3,     3,     3,
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
       3,     3,     3,     2,     3,     4,     4,     5,     1,     3,
       4,     1,     3,     3,     3,     5,     1,     1,     3,     1,
       3,     2,     2,     3,     2,     3,     4,     6,     1,     2,
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
       4,     3,     4,     3,     1,     3,     2,     2,     2,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     2,
       3,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1
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
       0,   239,   239,   240,   242,   243,   244,   247,   248,   251,
     252,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   269,   270,   271,   272,   273,   276,   277,
     281,   283,   284,   288,   289,   290,   292,   293,   297,   298,
     299,   300,   301,   302,   304,   307,   309,   311,   313,   316,
     318,   319,   321,   322,   325,   326,   327,   329,   330,   331,
     332,   334,   335,   336,   340,   341,   342,   343,   345,   347,
     348,   350,   351,   352,   357,   361,   362,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   385,   386,   390,   391,   392,   393,   394,   395,   396,
     397,   400,   401,   402,   403,   404,   406,   407,   409,   410,
     411,   412,   413,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   425,   426,   427,   428,   430,   431,   434,   435,
     436,   437,   438,   440,   441,   442,   443,   444,   446,   447,
     448,   449,   450,   452,   453,   454,   455,   456,   458,   459,
     460,   461,   462,   463,   464,   465,   467,   468,   469,   470,
     471,   473,   474,   475,   477,   478,   479,   481,   482,   483,
     484,   485,   486,   487,   489,   490,   491,   492,   493,   494,
     495,   497,   498,   499,   500,   501,   502,   503,   505,   506,
     507,   508,   509,   510,   511,   513,   514,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   527,
     528,   529,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   549,
     550,   551,   553,   554,   555,   557,   558,   559,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   578,   579,   580,   582,   583,   584,
     586,   588,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   604,   605,   606,   607,   608,   611,   612,
     613,   617,   618,   620,   621,   622,   624,   625,   627,   632,
     633,   637,   638,   639,   641,   642,   644,   645,   649,   650,
     651,   652,   653,   654,   655,   656,   657,   658,   659,   660,
     661,   662,   666,   667,   668,   669,   670,   671,   672,   673,
     674,   675,   676,   677,   678,   679,   680,   681,   682,   683,
     684,   685,   686,   690,   691,   692,   693,   694,   695,   696,
     697,   698,   699,   700,   701,   702,   703,   704,   705,   706,
     707,   708,   709,   710,   711,   712,   713,   714,   715,   716,
     720,   721,   722,   723,   724,   726,   727,   728,   729,   730,
     731,   732,   734,   735,   736,   737,   738,   739,   740,   742,
     743,   744,   745,   746,   748,   749,   750,   751,   752,   754,
     755,   756,   757,   758,   760,   761,   762,   763,   764,   766,
     770,   771,   772,   773,   775,   776,   780,   781,   782,   783,
     784,   785,   786,   787,   788,   789,   790,   791,   792,   794,
     796,   801,   802,   803,   804,   805,   806,   807,   808,   809,
     810,   811,   812,   813,   814,   815,   816,   817
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
#line 5096 "frontend/parser.cpp"

#line 820 "frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    auto msg = std::to_string(scanner->llvmloc->begin.line) + ":" + std::to_string(scanner->llvmloc->begin.column) + ": " + err_message;
    scanner->fatal_error(ptc::diag::ERR_SYNTAX, msg);
}
