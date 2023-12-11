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

  case 78: // set: expr "++=" expr
#line 367 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1645 "frontend/parser.cpp"
    break;

  case 79: // set: expr "**=" expr
#line 368 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1651 "frontend/parser.cpp"
    break;

  case 80: // set: expr "%=" expr
#line 369 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1657 "frontend/parser.cpp"
    break;

  case 81: // set: expr "/=" expr
#line 370 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1663 "frontend/parser.cpp"
    break;

  case 82: // set: expr "*=" expr
#line 371 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1669 "frontend/parser.cpp"
    break;

  case 83: // set: expr "-=" expr
#line 372 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1675 "frontend/parser.cpp"
    break;

  case 84: // set: expr "+=" expr
#line 373 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1681 "frontend/parser.cpp"
    break;

  case 85: // set: expr "&=" expr
#line 374 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1687 "frontend/parser.cpp"
    break;

  case 86: // set: expr "|=" expr
#line 375 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1693 "frontend/parser.cpp"
    break;

  case 87: // set: expr "^=" expr
#line 376 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1699 "frontend/parser.cpp"
    break;

  case 88: // set: expr "<<=" expr
#line 377 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1705 "frontend/parser.cpp"
    break;

  case 89: // set: expr ">>=" expr
#line 378 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1711 "frontend/parser.cpp"
    break;

  case 90: // set: expr "=" expr
#line 379 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1717 "frontend/parser.cpp"
    break;

  case 91: // set: expr "=" set
#line 380 "frontend/parser.yy"
      { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1723 "frontend/parser.cpp"
    break;

  case 92: // callarglist: expr
#line 384 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseFunCallArg(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1729 "frontend/parser.cpp"
    break;

  case 93: // callarglist: callarglist "," expr
#line 385 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddFunCallArg(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1735 "frontend/parser.cpp"
    break;

  case 94: // expr: expr_mat
#line 389 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1741 "frontend/parser.cpp"
    break;

  case 95: // expr: expr_var
#line 390 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1747 "frontend/parser.cpp"
    break;

  case 96: // expr: expr_none
#line 391 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1753 "frontend/parser.cpp"
    break;

  case 97: // expr: expr_struct
#line 392 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1759 "frontend/parser.cpp"
    break;

  case 98: // expr: expr_int
#line 393 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 1765 "frontend/parser.cpp"
    break;

  case 99: // expr: expr_float
#line 394 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFloat(yystack_[0].value.as < double > ()); }
#line 1771 "frontend/parser.cpp"
    break;

  case 100: // expr: expr_str
#line 395 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseString(yystack_[0].value.as < std::string > ()); }
#line 1777 "frontend/parser.cpp"
    break;

  case 101: // expr: expr_bool
#line 396 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseBool(yystack_[0].value.as < bool > ()); }
#line 1783 "frontend/parser.cpp"
    break;

  case 102: // expr_var: "identifier"
#line 399 "frontend/parser.yy"
              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > ()); }
#line 1789 "frontend/parser.cpp"
    break;

  case 103: // expr_var: "external identifier"
#line 400 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > (), true); }
#line 1795 "frontend/parser.cpp"
    break;

  case 104: // expr_var: "-" "identifier"
#line 401 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1801 "frontend/parser.cpp"
    break;

  case 105: // expr_var: "-" "external identifier"
#line 402 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > (), true), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1807 "frontend/parser.cpp"
    break;

  case 106: // expr_var: "(" expr_var ")"
#line 403 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1813 "frontend/parser.cpp"
    break;

  case 107: // expr_var: expr_var "(" ")"
#line 405 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[2].value.as < ptc::ir::Expr * > (), std::vector<ptc::ir::Expr *>{}); }
#line 1819 "frontend/parser.cpp"
    break;

  case 108: // expr_var: expr_var "(" callarglist ")"
#line 406 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 1825 "frontend/parser.cpp"
    break;

  case 109: // expr_var: expr_str "[" int_val "]"
#line 408 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1831 "frontend/parser.cpp"
    break;

  case 110: // expr_var: expr_mat "[" int_val "]"
#line 409 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1837 "frontend/parser.cpp"
    break;

  case 111: // expr_var: "identifier" "[" int_val "]"
#line 410 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1843 "frontend/parser.cpp"
    break;

  case 112: // expr_var: "external identifier" "[" int_val "]"
#line 411 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1849 "frontend/parser.cpp"
    break;

  case 113: // expr_var: expr_var "[" int_val "]"
#line 412 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1855 "frontend/parser.cpp"
    break;

  case 114: // expr_var: "identifier" "as" "external identifier"
#line 414 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > ()), scanner->parseVar(scanner->parseExtType(yystack_[0].value.as < std::string > (), false)->getName(), true, false), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1861 "frontend/parser.cpp"
    break;

  case 115: // expr_var: "external identifier" "as" "external identifier"
#line 415 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > (), true), scanner->parseVar(scanner->parseExtType(yystack_[0].value.as < std::string > (), false)->getName(), true, false), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1867 "frontend/parser.cpp"
    break;

  case 116: // expr_var: expr_var "as" "external identifier"
#line 416 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseVar(scanner->parseExtType(yystack_[0].value.as < std::string > (), false)->getName(), true, false), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1873 "frontend/parser.cpp"
    break;

  case 117: // expr_var: "identifier" "as" "external identifier" "?"
#line 417 "frontend/parser.yy"
                                      { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), scanner->parseVar(scanner->parseExtType(yystack_[1].value.as < std::string > (), true)->getName(), true, true), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1879 "frontend/parser.cpp"
    break;

  case 118: // expr_var: "external identifier" "as" "external identifier" "?"
#line 418 "frontend/parser.yy"
                                      { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > (), true), scanner->parseVar(scanner->parseExtType(yystack_[1].value.as < std::string > (), true)->getName(), true, true), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1885 "frontend/parser.cpp"
    break;

  case 119: // expr_var: expr_var "as" "external identifier" "?"
#line 419 "frontend/parser.yy"
                                      { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), scanner->parseVar(scanner->parseExtType(yystack_[1].value.as < std::string > (), true)->getName(), true, true), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1891 "frontend/parser.cpp"
    break;

  case 120: // expr_var: "identifier" "as" type
#line 420 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > ()), scanner->parseVar(yystack_[0].value.as < ptc::ir::IR * > ()->getName(), false, llvm::dyn_cast<ptc::ir::TypeDecl>(yystack_[0].value.as < ptc::ir::IR * > ())->isMaybe()), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1897 "frontend/parser.cpp"
    break;

  case 121: // expr_var: "external identifier" "as" type
#line 421 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > (), true), scanner->parseVar(yystack_[0].value.as < ptc::ir::IR * > ()->getName(), false, llvm::dyn_cast<ptc::ir::TypeDecl>(yystack_[0].value.as < ptc::ir::IR * > ())->isMaybe()), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1903 "frontend/parser.cpp"
    break;

  case 122: // expr_var: expr_var "as" type
#line 422 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseVar(yystack_[0].value.as < ptc::ir::IR * > ()->getName(), false, llvm::dyn_cast<ptc::ir::TypeDecl>(yystack_[0].value.as < ptc::ir::IR * > ())->isMaybe()), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1909 "frontend/parser.cpp"
    break;

  case 123: // expr_var: expr_mat slice
#line 424 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[1].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SLICE)); }
#line 1915 "frontend/parser.cpp"
    break;

  case 124: // expr_var: "identifier" slice
#line 425 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[1].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SLICE)); }
#line 1921 "frontend/parser.cpp"
    break;

  case 125: // expr_var: "external identifier" slice
#line 426 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[1].value.as < std::string > (), true), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SLICE)); }
#line 1927 "frontend/parser.cpp"
    break;

  case 126: // expr_var: expr_var slice
#line 427 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[1].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SLICE)); }
#line 1933 "frontend/parser.cpp"
    break;

  case 127: // expr_var: expr_var "." "identifier"
#line 429 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1939 "frontend/parser.cpp"
    break;

  case 128: // expr_var: expr_var "." "external identifier"
#line 430 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1945 "frontend/parser.cpp"
    break;

  case 129: // expr_var: expr_float "**" expr_var
#line 433 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1951 "frontend/parser.cpp"
    break;

  case 130: // expr_var: expr_var "**" expr_float
#line 434 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1957 "frontend/parser.cpp"
    break;

  case 131: // expr_var: expr_var "**" expr_var
#line 435 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1963 "frontend/parser.cpp"
    break;

  case 132: // expr_var: expr_int "**" expr_var
#line 436 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < long > ()) /*Float on purpose*/, yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1969 "frontend/parser.cpp"
    break;

  case 133: // expr_var: expr_var "**" expr_int
#line 437 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < long > ()) /*Float on purpose*/, ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1975 "frontend/parser.cpp"
    break;

  case 134: // expr_var: expr_int "*" expr_var
#line 439 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1981 "frontend/parser.cpp"
    break;

  case 135: // expr_var: expr_float "*" expr_var
#line 440 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1987 "frontend/parser.cpp"
    break;

  case 136: // expr_var: expr_var "*" expr_int
#line 441 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1993 "frontend/parser.cpp"
    break;

  case 137: // expr_var: expr_var "*" expr_float
#line 442 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1999 "frontend/parser.cpp"
    break;

  case 138: // expr_var: expr_var "*" expr_var
#line 443 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 2005 "frontend/parser.cpp"
    break;

  case 139: // expr_var: expr_int "/" expr_var
#line 445 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 2011 "frontend/parser.cpp"
    break;

  case 140: // expr_var: expr_float "/" expr_var
#line 446 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 2017 "frontend/parser.cpp"
    break;

  case 141: // expr_var: expr_var "/" expr_int
#line 447 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 2023 "frontend/parser.cpp"
    break;

  case 142: // expr_var: expr_var "/" expr_float
#line 448 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 2029 "frontend/parser.cpp"
    break;

  case 143: // expr_var: expr_var "/" expr_var
#line 449 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 2035 "frontend/parser.cpp"
    break;

  case 144: // expr_var: expr_int "%" expr_var
#line 451 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 2041 "frontend/parser.cpp"
    break;

  case 145: // expr_var: expr_float "%" expr_var
#line 452 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 2047 "frontend/parser.cpp"
    break;

  case 146: // expr_var: expr_var "%" expr_int
#line 453 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 2053 "frontend/parser.cpp"
    break;

  case 147: // expr_var: expr_var "%" expr_float
#line 454 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 2059 "frontend/parser.cpp"
    break;

  case 148: // expr_var: expr_var "%" expr_var
#line 455 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 2065 "frontend/parser.cpp"
    break;

  case 149: // expr_var: expr_int "+" expr_var
#line 457 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2071 "frontend/parser.cpp"
    break;

  case 150: // expr_var: expr_float "+" expr_var
#line 458 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2077 "frontend/parser.cpp"
    break;

  case 151: // expr_var: expr_var "+" expr_int
#line 459 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2083 "frontend/parser.cpp"
    break;

  case 152: // expr_var: expr_var "+" expr_float
#line 460 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2089 "frontend/parser.cpp"
    break;

  case 153: // expr_var: expr_mat "+" expr_mat
#line 461 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2095 "frontend/parser.cpp"
    break;

  case 154: // expr_var: expr_var "+" expr_mat
#line 462 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2101 "frontend/parser.cpp"
    break;

  case 155: // expr_var: expr_mat "+" expr_var
#line 463 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2107 "frontend/parser.cpp"
    break;

  case 156: // expr_var: expr_var "+" expr_var
#line 464 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2113 "frontend/parser.cpp"
    break;

  case 157: // expr_var: expr_int "-" expr_var
#line 466 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2119 "frontend/parser.cpp"
    break;

  case 158: // expr_var: expr_float "-" expr_var
#line 467 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2125 "frontend/parser.cpp"
    break;

  case 159: // expr_var: expr_var "-" expr_int
#line 468 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2131 "frontend/parser.cpp"
    break;

  case 160: // expr_var: expr_var "-" expr_float
#line 469 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2137 "frontend/parser.cpp"
    break;

  case 161: // expr_var: expr_var "-" expr_var
#line 470 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2143 "frontend/parser.cpp"
    break;

  case 162: // expr_var: expr_int "<<" expr_var
#line 472 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2149 "frontend/parser.cpp"
    break;

  case 163: // expr_var: expr_var "<<" expr_int
#line 473 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2155 "frontend/parser.cpp"
    break;

  case 164: // expr_var: expr_var "<<" expr_var
#line 474 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2161 "frontend/parser.cpp"
    break;

  case 165: // expr_var: expr_int ">>" expr_var
#line 476 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2167 "frontend/parser.cpp"
    break;

  case 166: // expr_var: expr_var ">>" expr_int
#line 477 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2173 "frontend/parser.cpp"
    break;

  case 167: // expr_var: expr_var ">>" expr_var
#line 478 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2179 "frontend/parser.cpp"
    break;

  case 168: // expr_var: expr_int ">" expr_var
#line 480 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2185 "frontend/parser.cpp"
    break;

  case 169: // expr_var: expr_float ">" expr_var
#line 481 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2191 "frontend/parser.cpp"
    break;

  case 170: // expr_var: expr_str ">" expr_var
#line 482 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2197 "frontend/parser.cpp"
    break;

  case 171: // expr_var: expr_var ">" expr_int
#line 483 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2203 "frontend/parser.cpp"
    break;

  case 172: // expr_var: expr_var ">" expr_float
#line 484 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2209 "frontend/parser.cpp"
    break;

  case 173: // expr_var: expr_var ">" expr_str
#line 485 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2215 "frontend/parser.cpp"
    break;

  case 174: // expr_var: expr_var ">" expr_var
#line 486 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2221 "frontend/parser.cpp"
    break;

  case 175: // expr_var: expr_int ">=" expr_var
#line 488 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2227 "frontend/parser.cpp"
    break;

  case 176: // expr_var: expr_float ">=" expr_var
#line 489 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2233 "frontend/parser.cpp"
    break;

  case 177: // expr_var: expr_str ">=" expr_var
#line 490 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2239 "frontend/parser.cpp"
    break;

  case 178: // expr_var: expr_var ">=" expr_int
#line 491 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2245 "frontend/parser.cpp"
    break;

  case 179: // expr_var: expr_var ">=" expr_float
#line 492 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2251 "frontend/parser.cpp"
    break;

  case 180: // expr_var: expr_var ">=" expr_str
#line 493 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2257 "frontend/parser.cpp"
    break;

  case 181: // expr_var: expr_var ">=" expr_var
#line 494 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2263 "frontend/parser.cpp"
    break;

  case 182: // expr_var: expr_int "<" expr_var
#line 496 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2269 "frontend/parser.cpp"
    break;

  case 183: // expr_var: expr_float "<" expr_var
#line 497 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2275 "frontend/parser.cpp"
    break;

  case 184: // expr_var: expr_str "<" expr_var
#line 498 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2281 "frontend/parser.cpp"
    break;

  case 185: // expr_var: expr_var "<" expr_int
#line 499 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2287 "frontend/parser.cpp"
    break;

  case 186: // expr_var: expr_var "<" expr_float
#line 500 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2293 "frontend/parser.cpp"
    break;

  case 187: // expr_var: expr_var "<" expr_str
#line 501 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2299 "frontend/parser.cpp"
    break;

  case 188: // expr_var: expr_var "<" expr_var
#line 502 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2305 "frontend/parser.cpp"
    break;

  case 189: // expr_var: expr_int "<=" expr_var
#line 504 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2311 "frontend/parser.cpp"
    break;

  case 190: // expr_var: expr_float "<=" expr_var
#line 505 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2317 "frontend/parser.cpp"
    break;

  case 191: // expr_var: expr_str "<=" expr_var
#line 506 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2323 "frontend/parser.cpp"
    break;

  case 192: // expr_var: expr_var "<=" expr_int
#line 507 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2329 "frontend/parser.cpp"
    break;

  case 193: // expr_var: expr_var "<=" expr_float
#line 508 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2335 "frontend/parser.cpp"
    break;

  case 194: // expr_var: expr_var "<=" expr_str
#line 509 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2341 "frontend/parser.cpp"
    break;

  case 195: // expr_var: expr_var "<=" expr_var
#line 510 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2347 "frontend/parser.cpp"
    break;

  case 196: // expr_var: expr_int "==" expr_var
#line 512 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2353 "frontend/parser.cpp"
    break;

  case 197: // expr_var: expr_float "==" expr_var
#line 513 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2359 "frontend/parser.cpp"
    break;

  case 198: // expr_var: expr_str "==" expr_var
#line 514 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2365 "frontend/parser.cpp"
    break;

  case 199: // expr_var: expr_bool "==" expr_var
#line 515 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2371 "frontend/parser.cpp"
    break;

  case 200: // expr_var: expr_none "==" expr_var
#line 516 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2377 "frontend/parser.cpp"
    break;

  case 201: // expr_var: expr_struct "==" expr_struct
#line 517 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2383 "frontend/parser.cpp"
    break;

  case 202: // expr_var: expr_struct "==" expr_var
#line 518 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2389 "frontend/parser.cpp"
    break;

  case 203: // expr_var: expr_var "==" expr_struct
#line 519 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2395 "frontend/parser.cpp"
    break;

  case 204: // expr_var: expr_var "==" expr_int
#line 520 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2401 "frontend/parser.cpp"
    break;

  case 205: // expr_var: expr_var "==" expr_float
#line 521 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2407 "frontend/parser.cpp"
    break;

  case 206: // expr_var: expr_var "==" expr_str
#line 522 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2413 "frontend/parser.cpp"
    break;

  case 207: // expr_var: expr_var "==" expr_bool
#line 523 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2419 "frontend/parser.cpp"
    break;

  case 208: // expr_var: expr_var "==" expr_none
#line 524 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2425 "frontend/parser.cpp"
    break;

  case 209: // expr_var: expr_mat "==" expr_mat
#line 525 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2431 "frontend/parser.cpp"
    break;

  case 210: // expr_var: expr_var "==" expr_mat
#line 526 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2437 "frontend/parser.cpp"
    break;

  case 211: // expr_var: expr_mat "==" expr_var
#line 527 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2443 "frontend/parser.cpp"
    break;

  case 212: // expr_var: expr_var "==" expr_var
#line 528 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2449 "frontend/parser.cpp"
    break;

  case 213: // expr_var: expr_int "!=" expr_var
#line 530 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2455 "frontend/parser.cpp"
    break;

  case 214: // expr_var: expr_float "!=" expr_var
#line 531 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2461 "frontend/parser.cpp"
    break;

  case 215: // expr_var: expr_str "!=" expr_var
#line 532 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2467 "frontend/parser.cpp"
    break;

  case 216: // expr_var: expr_bool "!=" expr_var
#line 533 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2473 "frontend/parser.cpp"
    break;

  case 217: // expr_var: expr_none "!=" expr_var
#line 534 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2479 "frontend/parser.cpp"
    break;

  case 218: // expr_var: expr_struct "!=" expr_struct
#line 535 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2485 "frontend/parser.cpp"
    break;

  case 219: // expr_var: expr_struct "!=" expr_var
#line 536 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2491 "frontend/parser.cpp"
    break;

  case 220: // expr_var: expr_var "!=" expr_struct
#line 537 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2497 "frontend/parser.cpp"
    break;

  case 221: // expr_var: expr_var "!=" expr_int
#line 538 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2503 "frontend/parser.cpp"
    break;

  case 222: // expr_var: expr_var "!=" expr_float
#line 539 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2509 "frontend/parser.cpp"
    break;

  case 223: // expr_var: expr_var "!=" expr_str
#line 540 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2515 "frontend/parser.cpp"
    break;

  case 224: // expr_var: expr_var "!=" expr_bool
#line 541 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2521 "frontend/parser.cpp"
    break;

  case 225: // expr_var: expr_var "!=" expr_none
#line 542 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2527 "frontend/parser.cpp"
    break;

  case 226: // expr_var: expr_mat "!=" expr_mat
#line 543 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2533 "frontend/parser.cpp"
    break;

  case 227: // expr_var: expr_var "!=" expr_mat
#line 544 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2539 "frontend/parser.cpp"
    break;

  case 228: // expr_var: expr_mat "!=" expr_var
#line 545 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2545 "frontend/parser.cpp"
    break;

  case 229: // expr_var: expr_var "!=" expr_var
#line 546 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2551 "frontend/parser.cpp"
    break;

  case 230: // expr_var: expr_int "&" expr_var
#line 548 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2557 "frontend/parser.cpp"
    break;

  case 231: // expr_var: expr_var "&" expr_int
#line 549 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2563 "frontend/parser.cpp"
    break;

  case 232: // expr_var: expr_var "&" expr_var
#line 550 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2569 "frontend/parser.cpp"
    break;

  case 233: // expr_var: expr_int "^" expr_var
#line 552 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2575 "frontend/parser.cpp"
    break;

  case 234: // expr_var: expr_var "^" expr_int
#line 553 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2581 "frontend/parser.cpp"
    break;

  case 235: // expr_var: expr_var "^" expr_var
#line 554 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2587 "frontend/parser.cpp"
    break;

  case 236: // expr_var: expr_int "|" expr_var
#line 556 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2593 "frontend/parser.cpp"
    break;

  case 237: // expr_var: expr_var "|" expr_int
#line 557 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2599 "frontend/parser.cpp"
    break;

  case 238: // expr_var: expr_var "|" expr_var
#line 558 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2605 "frontend/parser.cpp"
    break;

  case 239: // expr_var: expr_int "in" expr_mat
#line 560 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2611 "frontend/parser.cpp"
    break;

  case 240: // expr_var: expr_float "in" expr_mat
#line 561 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2617 "frontend/parser.cpp"
    break;

  case 241: // expr_var: expr_str "in" expr_mat
#line 562 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2623 "frontend/parser.cpp"
    break;

  case 242: // expr_var: expr_bool "in" expr_mat
#line 563 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2629 "frontend/parser.cpp"
    break;

  case 243: // expr_var: expr_none "in" expr_mat
#line 564 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseNone(), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2635 "frontend/parser.cpp"
    break;

  case 244: // expr_var: expr_struct "in" expr_mat
#line 565 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2641 "frontend/parser.cpp"
    break;

  case 245: // expr_var: expr_mat "in" expr_mat
#line 566 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2647 "frontend/parser.cpp"
    break;

  case 246: // expr_var: expr_int "in" expr_var
#line 567 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2653 "frontend/parser.cpp"
    break;

  case 247: // expr_var: expr_float "in" expr_var
#line 568 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2659 "frontend/parser.cpp"
    break;

  case 248: // expr_var: expr_str "in" expr_var
#line 569 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2665 "frontend/parser.cpp"
    break;

  case 249: // expr_var: expr_bool "in" expr_var
#line 570 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2671 "frontend/parser.cpp"
    break;

  case 250: // expr_var: expr_none "in" expr_var
#line 571 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseNone(), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2677 "frontend/parser.cpp"
    break;

  case 251: // expr_var: expr_struct "in" expr_var
#line 572 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2683 "frontend/parser.cpp"
    break;

  case 252: // expr_var: expr_mat "in" expr_var
#line 573 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2689 "frontend/parser.cpp"
    break;

  case 253: // expr_var: expr_var "in" expr_str
#line 574 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2695 "frontend/parser.cpp"
    break;

  case 254: // expr_var: expr_var "in" expr_var
#line 575 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_IN)); }
#line 2701 "frontend/parser.cpp"
    break;

  case 255: // expr_var: expr_bool "and" expr_var
#line 577 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2707 "frontend/parser.cpp"
    break;

  case 256: // expr_var: expr_var "and" expr_bool
#line 578 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2713 "frontend/parser.cpp"
    break;

  case 257: // expr_var: expr_var "and" expr_var
#line 579 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2719 "frontend/parser.cpp"
    break;

  case 258: // expr_var: expr_bool "or" expr_var
#line 581 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2725 "frontend/parser.cpp"
    break;

  case 259: // expr_var: expr_var "or" expr_bool
#line 582 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2731 "frontend/parser.cpp"
    break;

  case 260: // expr_var: expr_var "or" expr_var
#line 583 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2737 "frontend/parser.cpp"
    break;

  case 261: // expr_var: "not" expr_var
#line 585 "frontend/parser.yy"
                         { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseUnaryPrefixExpr(yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LNOT)); }
#line 2743 "frontend/parser.cpp"
    break;

  case 262: // expr_var: "~" expr_var
#line 587 "frontend/parser.yy"
                         { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseUnaryPrefixExpr(yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BNOT)); }
#line 2749 "frontend/parser.cpp"
    break;

  case 263: // expr_var: expr_int "++" expr_var
#line 589 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2755 "frontend/parser.cpp"
    break;

  case 264: // expr_var: expr_float "++" expr_var
#line 590 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2761 "frontend/parser.cpp"
    break;

  case 265: // expr_var: expr_str "++" expr_var
#line 591 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2767 "frontend/parser.cpp"
    break;

  case 266: // expr_var: expr_bool "++" expr_var
#line 592 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2773 "frontend/parser.cpp"
    break;

  case 267: // expr_var: expr_none "++" expr_var
#line 593 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseNone(), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2779 "frontend/parser.cpp"
    break;

  case 268: // expr_var: expr_var "++" expr_int
#line 594 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2785 "frontend/parser.cpp"
    break;

  case 269: // expr_var: expr_var "++" expr_float
#line 595 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2791 "frontend/parser.cpp"
    break;

  case 270: // expr_var: expr_var "++" expr_str
#line 596 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2797 "frontend/parser.cpp"
    break;

  case 271: // expr_var: expr_var "++" expr_bool
#line 597 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2803 "frontend/parser.cpp"
    break;

  case 272: // expr_var: expr_var "++" expr_none
#line 598 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseNone(), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2809 "frontend/parser.cpp"
    break;

  case 273: // expr_var: expr_var "++" expr_var
#line 599 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2815 "frontend/parser.cpp"
    break;

  case 274: // matrix: "[" "]"
#line 603 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(std::vector<ptc::ir::Expr *>{}); }
#line 2821 "frontend/parser.cpp"
    break;

  case 275: // matrix: "[" matvals "]"
#line 604 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2827 "frontend/parser.cpp"
    break;

  case 276: // matrix: "[" "terminator (\\n or ;)" matvals "]"
#line 605 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2833 "frontend/parser.cpp"
    break;

  case 277: // matrix: "[" matvals "terminator (\\n or ;)" "]"
#line 606 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2839 "frontend/parser.cpp"
    break;

  case 278: // matrix: "[" "terminator (\\n or ;)" matvals "terminator (\\n or ;)" "]"
#line 607 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2845 "frontend/parser.cpp"
    break;

  case 279: // matvals: expr
#line 610 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixValue(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2851 "frontend/parser.cpp"
    break;

  case 280: // matvals: matvals "," expr
#line 611 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2857 "frontend/parser.cpp"
    break;

  case 281: // matvals: matvals "," "terminator (\\n or ;)" expr
#line 612 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[3].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2863 "frontend/parser.cpp"
    break;

  case 282: // expr_mat: matrix
#line 616 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2869 "frontend/parser.cpp"
    break;

  case 283: // expr_mat: "(" matrix ")"
#line 617 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2875 "frontend/parser.cpp"
    break;

  case 284: // range: "(" range ")"
#line 619 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2881 "frontend/parser.cpp"
    break;

  case 285: // range: int_val ".." int_val
#line 620 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseRange(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2887 "frontend/parser.cpp"
    break;

  case 286: // range: int_val "," int_val ".." int_val
#line 621 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseRange(yystack_[4].value.as < ptc::ir::Expr * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2893 "frontend/parser.cpp"
    break;

  case 287: // int_val: expr_int
#line 623 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 2899 "frontend/parser.cpp"
    break;

  case 288: // int_val: expr_var
#line 624 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2905 "frontend/parser.cpp"
    break;

  case 289: // slice: "[" range "]"
#line 626 "frontend/parser.yy"
                       { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2911 "frontend/parser.cpp"
    break;

  case 290: // expr_none: "none"
#line 631 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseNone(); }
#line 2917 "frontend/parser.cpp"
    break;

  case 291: // expr_none: "(" "none" ")"
#line 632 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseNone(); }
#line 2923 "frontend/parser.cpp"
    break;

  case 292: // expr_struct: "identifier" struct_val
#line 636 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseStructLiteral(scanner->sym_lookup(yystack_[1].value.as < std::string > (), false, true), yystack_[0].value.as < std::map<std::string, ptc::ir::Expr *>  > ()); }
#line 2929 "frontend/parser.cpp"
    break;

  case 293: // expr_struct: "external identifier" struct_val
#line 637 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseExternalStructLiteral(scanner->parseExtType(yystack_[1].value.as < std::string > (), false), yystack_[0].value.as < std::map<std::string, ptc::ir::Expr *>  > ()); }
#line 2935 "frontend/parser.cpp"
    break;

  case 294: // expr_struct: "(" expr_struct ")"
#line 638 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2941 "frontend/parser.cpp"
    break;

  case 295: // struct_val: "{" "}"
#line 640 "frontend/parser.yy"
                                    { yylhs.value.as < std::map<std::string, ptc::ir::Expr *>  > () = std::map<std::string, ptc::ir::Expr*>{}; }
#line 2947 "frontend/parser.cpp"
    break;

  case 296: // struct_val: "{" struct_list "}"
#line 641 "frontend/parser.yy"
                                    { yylhs.value.as < std::map<std::string, ptc::ir::Expr *>  > () = yystack_[1].value.as < std::map<std::string, ptc::ir::Expr *>  > (); }
#line 2953 "frontend/parser.cpp"
    break;

  case 297: // struct_list: "." "identifier" "=" expr
#line 643 "frontend/parser.yy"
                                                { yylhs.value.as < std::map<std::string, ptc::ir::Expr *>  > () = scanner->parseStructVals(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2959 "frontend/parser.cpp"
    break;

  case 298: // struct_list: struct_list "," "." "identifier" "=" expr
#line 644 "frontend/parser.yy"
                                                { yylhs.value.as < std::map<std::string, ptc::ir::Expr *>  > () = scanner->parseStructVals(yystack_[5].value.as < std::map<std::string, ptc::ir::Expr *>  > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2965 "frontend/parser.cpp"
    break;

  case 299: // expr_int: "int"
#line 648 "frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 2971 "frontend/parser.cpp"
    break;

  case 300: // expr_int: "-" expr_int
#line 649 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 2977 "frontend/parser.cpp"
    break;

  case 301: // expr_int: "(" expr_int ")"
#line 650 "frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 2983 "frontend/parser.cpp"
    break;

  case 302: // expr_int: "~" expr_int
#line 651 "frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 2989 "frontend/parser.cpp"
    break;

  case 303: // expr_int: expr_int "*" expr_int
#line 652 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 2995 "frontend/parser.cpp"
    break;

  case 304: // expr_int: expr_int "/" expr_int
#line 653 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 3001 "frontend/parser.cpp"
    break;

  case 305: // expr_int: expr_int "%" expr_int
#line 654 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 3007 "frontend/parser.cpp"
    break;

  case 306: // expr_int: expr_int "-" expr_int
#line 655 "frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 3013 "frontend/parser.cpp"
    break;

  case 307: // expr_int: expr_int "+" expr_int
#line 656 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 3019 "frontend/parser.cpp"
    break;

  case 308: // expr_int: expr_int "<<" expr_int
#line 657 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 3025 "frontend/parser.cpp"
    break;

  case 309: // expr_int: expr_int ">>" expr_int
#line 658 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 3031 "frontend/parser.cpp"
    break;

  case 310: // expr_int: expr_int "&" expr_int
#line 659 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 3037 "frontend/parser.cpp"
    break;

  case 311: // expr_int: expr_int "^" expr_int
#line 660 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 3043 "frontend/parser.cpp"
    break;

  case 312: // expr_int: expr_int "|" expr_int
#line 661 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 3049 "frontend/parser.cpp"
    break;

  case 313: // expr_float: "float"
#line 665 "frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 3055 "frontend/parser.cpp"
    break;

  case 314: // expr_float: "-" expr_float
#line 666 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 3061 "frontend/parser.cpp"
    break;

  case 315: // expr_float: "(" expr_float ")"
#line 667 "frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 3067 "frontend/parser.cpp"
    break;

  case 316: // expr_float: expr_float "**" expr_float
#line 668 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 3073 "frontend/parser.cpp"
    break;

  case 317: // expr_float: expr_float "**" expr_int
#line 669 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 3079 "frontend/parser.cpp"
    break;

  case 318: // expr_float: expr_int "**" expr_float
#line 670 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 3085 "frontend/parser.cpp"
    break;

  case 319: // expr_float: expr_float "*" expr_float
#line 671 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 3091 "frontend/parser.cpp"
    break;

  case 320: // expr_float: expr_float "*" expr_int
#line 672 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 3097 "frontend/parser.cpp"
    break;

  case 321: // expr_float: expr_int "*" expr_float
#line 673 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 3103 "frontend/parser.cpp"
    break;

  case 322: // expr_float: expr_float "/" expr_float
#line 674 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 3109 "frontend/parser.cpp"
    break;

  case 323: // expr_float: expr_float "/" expr_int
#line 675 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 3115 "frontend/parser.cpp"
    break;

  case 324: // expr_float: expr_int "/" expr_float
#line 676 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 3121 "frontend/parser.cpp"
    break;

  case 325: // expr_float: expr_float "%" expr_float
#line 677 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 3127 "frontend/parser.cpp"
    break;

  case 326: // expr_float: expr_float "%" expr_int
#line 678 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 3133 "frontend/parser.cpp"
    break;

  case 327: // expr_float: expr_int "%" expr_float
#line 679 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 3139 "frontend/parser.cpp"
    break;

  case 328: // expr_float: expr_float "-" expr_float
#line 680 "frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 3145 "frontend/parser.cpp"
    break;

  case 329: // expr_float: expr_float "-" expr_int
#line 681 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 3151 "frontend/parser.cpp"
    break;

  case 330: // expr_float: expr_int "-" expr_float
#line 682 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 3157 "frontend/parser.cpp"
    break;

  case 331: // expr_float: expr_float "+" expr_float
#line 683 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 3163 "frontend/parser.cpp"
    break;

  case 332: // expr_float: expr_float "+" expr_int
#line 684 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 3169 "frontend/parser.cpp"
    break;

  case 333: // expr_float: expr_int "+" expr_float
#line 685 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 3175 "frontend/parser.cpp"
    break;

  case 334: // expr_str: "string"
#line 689 "frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3181 "frontend/parser.cpp"
    break;

  case 335: // expr_str: "(" expr_str ")"
#line 690 "frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 3187 "frontend/parser.cpp"
    break;

  case 336: // expr_str: expr_str "++" expr_str
#line 691 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 3193 "frontend/parser.cpp"
    break;

  case 337: // expr_str: expr_str "++" expr_int
#line 692 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 3199 "frontend/parser.cpp"
    break;

  case 338: // expr_str: expr_str "++" expr_float
#line 693 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 3205 "frontend/parser.cpp"
    break;

  case 339: // expr_str: expr_str "++" expr_bool
#line 694 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3211 "frontend/parser.cpp"
    break;

  case 340: // expr_str: expr_str "++" expr_none
#line 695 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 3217 "frontend/parser.cpp"
    break;

  case 341: // expr_str: expr_int "++" expr_str
#line 696 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 3223 "frontend/parser.cpp"
    break;

  case 342: // expr_str: expr_int "++" expr_int
#line 697 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 3229 "frontend/parser.cpp"
    break;

  case 343: // expr_str: expr_int "++" expr_float
#line 698 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 3235 "frontend/parser.cpp"
    break;

  case 344: // expr_str: expr_int "++" expr_bool
#line 699 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3241 "frontend/parser.cpp"
    break;

  case 345: // expr_str: expr_int "++" expr_none
#line 700 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 3247 "frontend/parser.cpp"
    break;

  case 346: // expr_str: expr_float "++" expr_str
#line 701 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 3253 "frontend/parser.cpp"
    break;

  case 347: // expr_str: expr_float "++" expr_int
#line 702 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 3259 "frontend/parser.cpp"
    break;

  case 348: // expr_str: expr_float "++" expr_float
#line 703 "frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 3265 "frontend/parser.cpp"
    break;

  case 349: // expr_str: expr_float "++" expr_bool
#line 704 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3271 "frontend/parser.cpp"
    break;

  case 350: // expr_str: expr_float "++" expr_none
#line 705 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 3277 "frontend/parser.cpp"
    break;

  case 351: // expr_str: expr_bool "++" expr_str
#line 706 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 3283 "frontend/parser.cpp"
    break;

  case 352: // expr_str: expr_bool "++" expr_int
#line 707 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 3289 "frontend/parser.cpp"
    break;

  case 353: // expr_str: expr_bool "++" expr_float
#line 708 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 3295 "frontend/parser.cpp"
    break;

  case 354: // expr_str: expr_bool "++" expr_bool
#line 709 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3301 "frontend/parser.cpp"
    break;

  case 355: // expr_str: expr_bool "++" expr_none
#line 710 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 3307 "frontend/parser.cpp"
    break;

  case 356: // expr_str: expr_none "++" expr_str
#line 711 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 3313 "frontend/parser.cpp"
    break;

  case 357: // expr_str: expr_none "++" expr_int
#line 712 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 3319 "frontend/parser.cpp"
    break;

  case 358: // expr_str: expr_none "++" expr_float
#line 713 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 3325 "frontend/parser.cpp"
    break;

  case 359: // expr_str: expr_none "++" expr_bool
#line 714 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3331 "frontend/parser.cpp"
    break;

  case 360: // expr_str: expr_none "++" expr_none
#line 715 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 3337 "frontend/parser.cpp"
    break;

  case 361: // expr_bool: "bool"
#line 719 "frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 3343 "frontend/parser.cpp"
    break;

  case 362: // expr_bool: "(" expr_bool ")"
#line 720 "frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 3349 "frontend/parser.cpp"
    break;

  case 363: // expr_bool: "not" expr_bool
#line 721 "frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 3355 "frontend/parser.cpp"
    break;

  case 364: // expr_bool: expr_bool "or" expr_bool
#line 722 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 3361 "frontend/parser.cpp"
    break;

  case 365: // expr_bool: expr_bool "and" expr_bool
#line 723 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 3367 "frontend/parser.cpp"
    break;

  case 366: // expr_bool: expr_bool "==" expr_bool
#line 725 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 3373 "frontend/parser.cpp"
    break;

  case 367: // expr_bool: expr_int "==" expr_int
#line 726 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 3379 "frontend/parser.cpp"
    break;

  case 368: // expr_bool: expr_int "==" expr_float
#line 727 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 3385 "frontend/parser.cpp"
    break;

  case 369: // expr_bool: expr_float "==" expr_float
#line 728 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 3391 "frontend/parser.cpp"
    break;

  case 370: // expr_bool: expr_float "==" expr_int
#line 729 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 3397 "frontend/parser.cpp"
    break;

  case 371: // expr_bool: expr_str "==" expr_str
#line 730 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 3403 "frontend/parser.cpp"
    break;

  case 372: // expr_bool: expr_none "==" expr_none
#line 731 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 3409 "frontend/parser.cpp"
    break;

  case 373: // expr_bool: expr_bool "!=" expr_bool
#line 733 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 3415 "frontend/parser.cpp"
    break;

  case 374: // expr_bool: expr_int "!=" expr_int
#line 734 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 3421 "frontend/parser.cpp"
    break;

  case 375: // expr_bool: expr_int "!=" expr_float
#line 735 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 3427 "frontend/parser.cpp"
    break;

  case 376: // expr_bool: expr_float "!=" expr_float
#line 736 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 3433 "frontend/parser.cpp"
    break;

  case 377: // expr_bool: expr_float "!=" expr_int
#line 737 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 3439 "frontend/parser.cpp"
    break;

  case 378: // expr_bool: expr_str "!=" expr_str
#line 738 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 3445 "frontend/parser.cpp"
    break;

  case 379: // expr_bool: expr_none "!=" expr_none
#line 739 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 3451 "frontend/parser.cpp"
    break;

  case 380: // expr_bool: expr_int ">" expr_int
#line 741 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 3457 "frontend/parser.cpp"
    break;

  case 381: // expr_bool: expr_int ">" expr_float
#line 742 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 3463 "frontend/parser.cpp"
    break;

  case 382: // expr_bool: expr_float ">" expr_float
#line 743 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 3469 "frontend/parser.cpp"
    break;

  case 383: // expr_bool: expr_float ">" expr_int
#line 744 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 3475 "frontend/parser.cpp"
    break;

  case 384: // expr_bool: expr_str ">" expr_str
#line 745 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 3481 "frontend/parser.cpp"
    break;

  case 385: // expr_bool: expr_int "<" expr_int
#line 747 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 3487 "frontend/parser.cpp"
    break;

  case 386: // expr_bool: expr_int "<" expr_float
#line 748 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 3493 "frontend/parser.cpp"
    break;

  case 387: // expr_bool: expr_float "<" expr_float
#line 749 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 3499 "frontend/parser.cpp"
    break;

  case 388: // expr_bool: expr_float "<" expr_int
#line 750 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 3505 "frontend/parser.cpp"
    break;

  case 389: // expr_bool: expr_str "<" expr_str
#line 751 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 3511 "frontend/parser.cpp"
    break;

  case 390: // expr_bool: expr_int ">=" expr_int
#line 753 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 3517 "frontend/parser.cpp"
    break;

  case 391: // expr_bool: expr_int ">=" expr_float
#line 754 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 3523 "frontend/parser.cpp"
    break;

  case 392: // expr_bool: expr_float ">=" expr_float
#line 755 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 3529 "frontend/parser.cpp"
    break;

  case 393: // expr_bool: expr_float ">=" expr_int
#line 756 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 3535 "frontend/parser.cpp"
    break;

  case 394: // expr_bool: expr_str ">=" expr_str
#line 757 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 3541 "frontend/parser.cpp"
    break;

  case 395: // expr_bool: expr_int "<=" expr_int
#line 759 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 3547 "frontend/parser.cpp"
    break;

  case 396: // expr_bool: expr_int "<=" expr_float
#line 760 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 3553 "frontend/parser.cpp"
    break;

  case 397: // expr_bool: expr_float "<=" expr_float
#line 761 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 3559 "frontend/parser.cpp"
    break;

  case 398: // expr_bool: expr_float "<=" expr_int
#line 762 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 3565 "frontend/parser.cpp"
    break;

  case 399: // expr_bool: expr_str "<=" expr_str
#line 763 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 3571 "frontend/parser.cpp"
    break;

  case 400: // expr_bool: expr_str "in" expr_str
#line 765 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[0].value.as < std::string > ().find(yystack_[2].value.as < std::string > ()) != std::string::npos; }
#line 3577 "frontend/parser.cpp"
    break;

  case 407: // mattype: "identifier" matsq
#line 779 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3583 "frontend/parser.cpp"
    break;

  case 408: // mattype: "'int'" matsq
#line 780 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(INT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3589 "frontend/parser.cpp"
    break;

  case 409: // mattype: "'float'" matsq
#line 781 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(FLOAT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3595 "frontend/parser.cpp"
    break;

  case 410: // mattype: "'string'" matsq
#line 782 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(STRING_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3601 "frontend/parser.cpp"
    break;

  case 411: // mattype: "'bool'" matsq
#line 783 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(BOOL_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3607 "frontend/parser.cpp"
    break;

  case 412: // mattype: "any" matsq
#line 784 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(ANY_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3613 "frontend/parser.cpp"
    break;

  case 420: // matsq: "[" "]"
#line 793 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(scanner->parseInt(-1)); }
#line 3619 "frontend/parser.cpp"
    break;

  case 421: // matsq: "[" "]" matsq
#line 795 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), scanner->parseInt(-1)); }
#line 3625 "frontend/parser.cpp"
    break;

  case 422: // type: "'int'" "?"
#line 800 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, true, true); }
#line 3631 "frontend/parser.cpp"
    break;

  case 423: // type: "'float'" "?"
#line 801 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, true, true); }
#line 3637 "frontend/parser.cpp"
    break;

  case 424: // type: "'string'" "?"
#line 802 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, true, true); }
#line 3643 "frontend/parser.cpp"
    break;

  case 425: // type: "'bool'" "?"
#line 803 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, true, true); }
#line 3649 "frontend/parser.cpp"
    break;

  case 426: // type: "identifier" "?"
#line 804 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[1].value.as < std::string > (), true, true); }
#line 3655 "frontend/parser.cpp"
    break;

  case 429: // type: mattype "?"
#line 807 "frontend/parser.yy"
       { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 3661 "frontend/parser.cpp"
    break;

  case 430: // type: "'int'"
#line 808 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, false, true); }
#line 3667 "frontend/parser.cpp"
    break;

  case 431: // type: "'float'"
#line 809 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, false, true); }
#line 3673 "frontend/parser.cpp"
    break;

  case 432: // type: "'string'"
#line 810 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, false, true); }
#line 3679 "frontend/parser.cpp"
    break;

  case 433: // type: "'bool'"
#line 811 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, false, true); }
#line 3685 "frontend/parser.cpp"
    break;

  case 434: // type: "any"
#line 812 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(ANY_CSTR, false, true); }
#line 3691 "frontend/parser.cpp"
    break;

  case 435: // type: "identifier"
#line 813 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[0].value.as < std::string > (), false, true); }
#line 3697 "frontend/parser.cpp"
    break;

  case 436: // type: "external identifier"
#line 814 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExtType(yystack_[0].value.as < std::string > (), false); }
#line 3703 "frontend/parser.cpp"
    break;

  case 438: // type: mattype
#line 816 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 3709 "frontend/parser.cpp"
    break;


#line 3713 "frontend/parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -638;

  const short  Parser ::yytable_ninf_ = -437;

  const short
   Parser ::yypact_[] =
  {
    1200,  -638,  -638,  -638,  -638,  -638,  -638,  -638,   688,    85,
      33,   780,   780,   -51,    30,   -27,  -638,  -638,  -638,  -638,
     780,  -638,  -638,   -20,    36,    51,    56,    57,    -3,     2,
     101,   185,   100,  1124,  -638,  -638,    72,    72,  -638,  -638,
      98,  -638,   167,  -638,  1480,  -638,   180,  -638,  -638,    72,
      72,    72,   928,  1805,  -638,   107,   327,   250,  1921,  1265,
     369,   465,    60,    66,     4,   181,   219,   259,  1037,   199,
     107,   327,   401,  2415,  2473,  1126,   593,   780,  -638,  -638,
      28,   704,   704,   112,  -638,  -638,  -638,  -638,   239,   250,
    1921,  1265,   369,  -638,   239,  -638,   465,   152,   203,  -638,
     190,  -638,  -638,   209,    30,  -638,    30,  -638,    30,  -638,
      30,  -638,   110,   298,  -638,   213,   601,   120,  1095,    30,
    -638,  -638,  -638,   860,  1235,  -638,  -638,  -638,  -638,  -638,
    1998,  -638,  -638,  -638,  -638,  -638,  1292,   780,   220,  1735,
    -638,  -638,   218,   780,  -638,  -638,  -638,   780,   780,   780,
     780,   780,   780,   780,   780,   780,   780,   780,   780,   780,
    -638,   628,   860,   780,   780,   780,   780,   780,   780,   780,
     780,   780,   780,  1504,   780,   780,   780,   780,   780,   780,
     780,   780,   780,   780,   780,   -42,  -638,   860,   780,   780,
     780,   780,  -638,   780,   780,   780,   780,   780,   780,   780,
     780,   780,   780,   780,   780,   780,   780,   780,   780,   780,
     780,   780,   780,   780,   780,   780,   780,   780,   780,   780,
     780,   780,   780,   780,   780,   780,   780,   780,   780,   780,
     780,   780,   780,   780,   780,   780,   780,   780,   780,   780,
     780,   780,   780,   780,   780,   780,   780,   780,    30,  -638,
    -638,   405,    23,   244,  -638,   860,  -638,  -638,  -638,  -638,
    -638,  -638,  -638,   261,   275,  -638,   252,  1422,  1019,   112,
     112,  -638,   704,   704,   704,   704,   704,   704,   112,   112,
     112,   112,   112,   704,   704,   704,   704,   704,   704,   780,
      30,   -27,   780,  -638,  -638,  -638,  -638,   277,   130,  -638,
     282,    62,   229,   297,    39,   652,   916,  1805,   299,   126,
    1921,  -638,   235,    20,   278,   342,  -638,   208,   284,   342,
    -638,    34,    14,   313,     7,   352,  1998,  -638,  1318,   348,
     368,  -638,  2623,  -638,  -638,  -638,  -638,  -638,  -638,  -638,
    -638,  -638,  -638,  -638,  -638,  -638,    11,  -638,   292,  1094,
     375,   535,   631,  1094,   535,   631,   260,   372,   373,   260,
     372,   373,   260,   372,   373,   260,   372,   373,  2108,   427,
    2497,  2593,   489,   506,  2264,   568,  2229,   553,  2294,   650,
     319,   342,  2001,  2569,  2324,  2521,  2354,  2545,   548,  1203,
     548,  1203,  2386,   153,  -638,  -638,  2604,  1497,   347,  -638,
    2386,   153,  -638,  -638,  2604,  1497,   347,  -638,  2068,  1320,
    1382,   384,  2068,  1320,  1382,   384,  2068,  1320,  1382,   384,
    2068,  1320,  1382,   384,  -638,  -638,   338,  1094,   375,  2294,
     179,  2386,   153,  2386,   153,  2108,   427,  2497,  2593,   489,
     506,  2294,   179,  2386,  -638,  2386,  -638,  2294,   179,  2386,
    -638,  2386,  -638,  1094,   535,   631,  1094,   535,   631,   260,
     372,   373,   260,   372,   373,   260,   372,   373,   260,   373,
    2108,   427,  2497,  2593,   489,   506,  2294,   179,  2001,  2569,
    2324,  2521,  2354,  2545,   548,  1203,   548,  1203,  2386,  2604,
    1497,  2386,  2604,  1497,  2068,  1320,  1382,  2068,  1320,  1382,
    2068,  1320,  1382,  2068,  1320,  1382,  1094,   535,   631,  1094,
     535,   631,   260,   372,   373,   260,   372,   373,   260,   372,
     373,   260,   372,   373,  2108,   427,  2497,  2593,   489,   506,
    2294,   179,  2386,  2604,  1497,  2386,  2604,  1497,  2068,  1320,
    1382,  2068,  1320,  1382,  2068,  1320,  1382,  2068,  1320,  1382,
     385,  2108,   427,  2497,  2593,   489,   506,  2294,   179,   650,
    2386,   347,  2386,   347,  2068,   384,  2068,   384,  2068,   384,
    2068,   384,  2108,   427,  2497,  2593,   489,   506,  2264,   568,
    2229,   553,  2294,   179,  2386,  -638,  2386,  -638,  -638,  -638,
     391,   780,   753,   402,  -638,  -638,   780,  -638,  1069,  -638,
     112,   112,   112,   112,   112,   683,   697,   683,   697,   397,
     399,   397,   399,   397,   399,  1756,   399,   790,  1951,  2633,
     731,   731,   683,   697,   683,   697,   397,   399,   397,   399,
     397,   399,   397,   399,  -638,  -638,  -638,  -638,   396,   396,
    -638,   344,   409,   421,     8,  -638,  1528,   264,   351,   388,
     415,    18,  1037,   440,   132,  2415,  -638,  -638,   780,   780,
     413,  -638,   417,  -638,  -638,  -638,   860,   860,   860,  -638,
    1480,  1404,   456,   780,  1480,  -638,   780,  -638,  -638,  -638,
    -638,  -638,  -638,   264,   452,  -638,  -638,   276,   276,  -638,
    -638,  -638,   450,  -638,   436,  -638,   396,   438,  -638,  -638,
    -638,   146,   264,  -638,  -638,  -638,   431,   780,   408,   479,
    1216,   485,  2444,   486,   508,   510,   511,  -638,   513,  -638,
     520,   471,  -638,  -638,   264,  -638,   780,  -638,   780,   458,
      21,  -638,   780,  -638,   493,  1480,  1480,  1480,  1480,  1480,
    1480,  -638,  -638,  -638,  -638,  1480,  -638,  -638,  -638,  -638,
    -638,  -638,   780,  -638,  -638,  -638,  -638,  -638,  -638,  -638,
    -638
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     9,   299,   313,   334,   361,   290,     0,     0,
       0,     0,     0,     0,   434,     0,    52,    44,    46,    48,
      36,    33,    34,     0,   430,   431,   432,   433,     0,     0,
     102,   103,     0,     0,     4,    10,     0,     0,    35,    15,
       0,    17,     0,    18,     0,    16,     0,    19,    20,     0,
       0,     0,     0,    95,   282,    94,    96,    97,    98,    99,
     100,   101,   437,   438,     0,   290,   102,   103,     0,   282,
       0,     0,     0,     0,     0,     0,     0,     0,   274,   279,
       0,     0,     0,     0,   104,   105,   300,   314,   261,     0,
       0,     0,     0,   363,   262,   302,     0,     0,     0,   412,
      31,    30,    37,     0,   422,   408,   423,   409,   424,   410,
     425,   411,     0,     0,    68,     0,     0,     0,     0,   426,
     124,   292,   407,     0,     0,   427,   125,   293,     1,     3,
       0,     5,     8,     7,    14,    21,     0,     0,     0,     0,
      28,    29,     0,     0,    12,    13,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   126,     0,     0,     0,
       0,     0,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   428,   413,
     429,     0,    74,     0,   291,     0,   106,   283,   294,   301,
     315,   335,   362,     0,     0,   275,     0,     0,     0,     0,
       0,   302,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     420,     0,     0,   415,   416,   417,   418,     0,     0,   404,
       0,   435,   436,     0,   405,     0,     0,   288,     0,     0,
     287,   295,     0,     0,   114,   120,   414,     0,   115,   121,
       6,   435,   436,     0,     0,     0,     0,    23,     0,     0,
       0,    91,    90,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,   107,     0,    92,     0,   156,
     154,   151,   152,   161,   159,   160,   138,   136,   137,   143,
     141,   142,   148,   146,   147,   131,   133,   130,   273,   272,
     268,   269,   270,   271,   257,   256,   260,   259,   254,   253,
     116,   122,   232,   231,   238,   237,   235,   234,   164,   163,
     167,   166,   212,   210,   208,   203,   204,   205,   206,   207,
     229,   227,   225,   220,   221,   222,   223,   224,   174,   171,
     172,   173,   188,   185,   186,   187,   181,   178,   179,   180,
     195,   192,   193,   194,   127,   128,     0,   155,   153,   252,
     245,   211,   209,   228,   226,   267,   360,   357,   358,   356,
     359,   250,   243,   200,   372,   217,   379,   251,   244,   202,
     201,   219,   218,   149,   307,   333,   157,   306,   330,   134,
     303,   321,   139,   304,   324,   144,   305,   327,   132,   318,
     263,   345,   342,   343,   341,   344,   246,   239,   230,   310,
     236,   312,   233,   311,   162,   308,   165,   309,   196,   367,
     368,   213,   374,   375,   168,   380,   381,   182,   385,   386,
     175,   390,   391,   189,   395,   396,   150,   332,   331,   158,
     329,   328,   135,   320,   319,   140,   323,   322,   145,   326,
     325,   129,   317,   316,   264,   350,   347,   348,   346,   349,
     247,   240,   197,   370,   369,   214,   377,   376,   169,   383,
     382,   183,   388,   387,   176,   393,   392,   190,   398,   397,
       0,   265,   340,   337,   338,   336,   339,   248,   241,   400,
     198,   371,   215,   378,   170,   384,   184,   389,   177,   394,
     191,   399,   266,   355,   352,   353,   351,   354,   255,   365,
     258,   364,   249,   242,   199,   366,   216,   373,   419,   402,
       0,     0,     0,     0,   276,   277,     0,   280,     0,   300,
       0,     0,     0,     0,     0,   307,   333,   306,   330,   303,
     321,   304,   324,   305,   327,     0,   318,   310,   312,   311,
     308,   309,   332,   331,   329,   328,   320,   319,   323,   322,
     326,   325,   317,   316,    77,   421,    32,    76,     0,    57,
      54,     0,     0,     0,     0,   403,     0,     0,     0,    73,
       0,     0,   288,     0,     0,   287,   289,   111,     0,     0,
       0,   296,     0,   117,   112,   118,     0,     0,     0,    74,
       0,     0,    24,     0,     0,   108,     0,   113,   119,   110,
     109,   401,    75,     0,     0,   278,   281,   307,   306,   303,
     304,   305,     0,    58,     0,    55,    59,    61,   406,    66,
      71,     0,     0,    69,   284,   285,     0,     0,     0,     0,
     288,     0,   287,     0,     0,     0,     0,    45,    25,    26,
       0,    51,    93,    64,     0,    56,     0,    60,     0,     0,
       0,    67,     0,   297,     0,     0,     0,     0,     0,     0,
       0,    27,    47,    53,    49,     0,    65,    63,    62,    72,
      70,   286,     0,    39,    42,    40,    43,    38,    41,    50,
     298
  };

  const short
   Parser ::yypgoto_[] =
  {
    -638,  -638,  -134,   177,   -31,     6,  -637,  -396,  -638,   246,
    -638,  -638,  -638,  -638,  -638,  -638,  -638,  -638,  -638,  -638,
    -638,  -638,  -638,  -610,  -638,  -638,   477,  -638,   -45,   422,
    -638,   423,  -638,   290,  1988,    -5,   483,   354,  -302,  -109,
     -12,   621,   852,   -16,  -638,  1448,  1688,     0,   166,  -638,
    -250,  -638,    -2,   -54
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    32,    33,   134,    34,   140,   141,   142,    36,   101,
      37,    38,    39,    40,    41,    42,    43,    44,    45,   744,
      46,   745,    47,   642,   643,    48,   115,   649,   650,    49,
      50,    51,   346,    52,    53,    54,    80,    70,   308,   654,
     186,    71,    89,   121,   313,    58,    59,    92,    96,    62,
     303,    63,   122,    64
  };

  const short
   Parser ::yytable_[] =
  {
      60,   590,   131,    69,   653,   328,    35,   309,    75,    60,
     699,   113,    99,   251,   317,   127,   251,   251,   120,   126,
      60,   675,   105,   107,   109,   111,    97,   251,   692,   693,
     251,   264,   -68,    60,   661,   424,   425,     3,     4,    35,
     265,    98,    81,   192,    60,    98,   723,    98,   251,    82,
     100,   127,   676,   348,   120,   126,   667,   103,   192,   304,
     249,   662,    98,    83,   315,   731,   591,    98,    98,   266,
     319,    98,   132,    98,   112,   133,   666,    60,   426,   114,
     646,   252,   324,   125,   669,   697,   727,   746,    77,     3,
       4,     5,     6,     7,     8,   703,     9,    78,   750,   320,
     128,    10,   293,   119,   294,   104,   295,   136,   296,    11,
      84,    85,   116,   297,   117,    12,     3,   316,   187,   381,
     106,   269,   188,   298,   550,   108,   110,   118,   270,   248,
      60,   119,   189,   639,   311,   250,    35,    60,   657,    60,
     190,   191,    83,    60,   640,    35,   309,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
     312,    60,    66,    67,   187,   658,    61,   659,   188,   372,
     119,   658,   379,   659,    76,    61,   137,    93,  -435,   398,
     406,   411,   415,   419,   423,   729,    61,   641,    14,   143,
     187,   254,   671,   439,   188,   289,   123,   304,   117,    61,
      24,    25,    26,    27,    14,   300,   474,   301,   302,   257,
      61,   124,   190,   191,   135,   290,    24,    25,    26,    27,
     664,   300,   305,   301,   302,   528,   144,   145,   146,   160,
     255,   291,   117,   326,   555,   559,   561,   563,   565,   567,
     569,   571,   576,    61,   644,   118,   588,   658,   161,   659,
     162,   651,   292,   592,   125,   596,     3,     4,     5,     6,
       7,     8,  -436,     9,   593,   173,    60,   138,    10,   161,
     123,   162,   117,   594,   717,   197,    11,   139,   721,   185,
     168,   329,    12,   198,   199,   124,   173,   595,   635,    60,
     638,   113,    60,   602,   603,   604,    61,   131,   125,    79,
     185,    69,   266,    61,   677,    61,    75,   645,   299,    61,
     102,   656,   660,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    60,    61,    60,    66,
      67,   658,    35,   659,    35,   373,   375,   377,   192,   753,
     754,   755,   756,   757,   758,   399,   407,   663,   193,   759,
     679,   251,   194,   665,    55,   668,    14,   673,   233,   440,
     195,   196,   670,    55,   711,   714,   716,    79,    24,    25,
      26,    27,   475,   300,    55,   301,   302,   658,   674,   659,
     233,   192,   238,   239,   240,   241,   187,    55,   678,   192,
     234,   529,   205,   224,   235,   233,   698,   680,    55,   639,
     556,   681,   236,   237,   238,   239,   240,   241,   577,   579,
     581,   258,   585,   587,   685,   589,   192,   277,   192,   288,
     192,   694,   192,   695,   696,   702,   197,   325,   700,   701,
     192,    55,    61,   330,   198,   199,   192,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     704,   347,   194,   641,    14,    61,   707,   708,    61,   719,
     195,   196,   724,    14,   725,   192,    24,    25,    26,    27,
     732,   300,    76,   301,   302,    24,    25,    26,    27,   726,
     300,   728,   301,   302,    55,   734,   242,   243,   244,   735,
     245,    55,    61,    55,    61,   736,   737,    55,   246,   247,
     233,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,   235,    55,   741,   350,   738,   192,
     739,   740,   236,   237,   238,   239,   240,   241,   243,   244,
     742,   245,   743,   393,   401,   749,   752,   636,   651,   246,
     247,   253,   428,   430,   432,   434,   192,   684,   442,   705,
     706,   448,   202,   203,   204,   205,   597,   161,   323,   162,
     263,   477,     0,   163,   164,   165,   166,   167,   168,     0,
     331,   192,     0,     0,   173,   243,     0,     0,   245,   634,
     531,     0,   637,     0,   644,   644,   246,   247,   185,   558,
       0,    60,   304,   245,     0,     0,    60,     0,     0,   583,
       0,   246,   247,   262,     0,     3,     4,     5,     6,     7,
     306,     0,     9,   290,   242,   243,   244,    10,   245,     0,
      55,    56,     0,   751,     0,    11,   246,   247,     0,     0,
      56,    12,     3,     4,     5,     6,     7,     8,   345,     9,
     131,    56,   644,    55,    10,     0,    55,   730,   221,   222,
     223,   224,    11,     0,    56,     0,     0,     0,    12,     0,
       0,   233,   647,     0,     0,    56,    60,    60,    60,     0,
      60,    60,     0,    60,    60,     0,    60,    35,    66,    67,
      55,     0,    55,   236,   237,   238,   239,   240,   241,     0,
       0,   648,     3,     4,     5,     6,    65,     8,    56,     9,
     274,   275,   276,   277,    10,    66,    67,    60,     3,     4,
      14,     0,    11,    81,   285,   286,   287,   288,    12,     0,
      82,     0,    24,    25,    26,    27,    60,   300,    60,   301,
     302,     0,     0,     0,    83,    60,    60,    60,    60,    60,
      60,     0,     0,     0,     0,    60,   600,   601,   602,   603,
     604,    56,    60,     0,     0,     0,     0,    61,    56,     0,
      56,     0,    61,   683,    56,    66,    67,     0,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,     0,    56,     0,     3,     4,     5,     6,     7,     8,
     369,     9,   648,     0,     0,     0,    10,     0,     0,     0,
     394,   402,     0,     0,    11,   600,   601,   602,   603,   604,
      12,    14,     0,     0,   436,     0,   444,   446,     0,     0,
       0,   281,   282,    24,    25,    26,    27,   471,   300,     0,
     301,   302,    61,    61,    61,     0,    61,    61,     0,    61,
      61,     0,    61,     0,     0,     0,   525,     0,     0,     0,
       0,     0,    57,     0,     0,   552,     0,    66,    67,     0,
      72,    57,     0,   573,     3,     4,     5,     6,     7,   306,
       0,     9,    57,    61,     0,     0,    10,     0,     0,     0,
       0,   682,     0,     0,    11,    57,   686,    56,     0,     0,
      12,     0,    61,     0,    61,     0,    57,     0,     0,     0,
       0,    61,    61,    61,    61,    61,    61,     0,     0,     0,
      56,    61,     0,    56,     0,     0,     0,     0,    61,     0,
       3,     4,     5,     6,    65,   306,     0,     9,   132,    57,
       0,   133,    10,     0,     0,     0,     0,    66,    67,     0,
      11,     0,     0,     0,     0,    55,    12,    56,     0,    56,
      55,     0,     0,     0,     0,     0,   709,   713,   715,     0,
       0,     0,     0,   720,     0,     0,   722,     0,     0,     0,
       0,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,    57,   158,   159,     0,     0,     0,     0,    57,
       0,    57,     0,    66,    67,    57,     0,   733,     0,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,     0,    57,     0,     0,   747,     0,   748,     0,
      55,    55,    55,     0,    55,    55,     0,    55,    55,   260,
      55,   395,   403,     0,   283,   284,   285,   286,   287,   288,
       0,     0,   760,     0,     0,     0,   161,   256,   162,     0,
     450,   452,   163,   164,   165,   166,   167,   168,   169,   170,
     171,    55,   172,   173,   174,   175,   176,     0,   177,   178,
     179,   180,   181,   182,   183,   184,     0,   185,     0,   259,
      55,     0,    55,     0,   600,   601,   602,   603,   604,    55,
      55,    55,    55,    55,    55,     0,   278,   279,   280,    55,
     281,   282,     0,   161,     0,   162,    55,     0,     0,     0,
       0,   165,   166,   167,   168,     0,     0,     0,    57,     0,
     173,     0,     0,     0,   129,   130,     0,     2,     3,     4,
       5,     6,     7,     8,   185,     9,   261,   233,     0,     0,
      10,    57,     0,     0,    57,     0,     0,   234,    11,     0,
       0,   235,     0,    14,    12,     0,     0,     0,    72,   236,
     237,   238,   239,   240,   241,    24,    25,    26,    27,     0,
     300,     0,   301,   314,     0,     0,     0,     0,    57,     0,
      57,    13,    14,    15,    16,     0,    17,    18,    19,    20,
      21,    22,    23,     0,    24,    25,    26,    27,    28,    29,
       1,    30,    31,     2,     3,     4,     5,     6,     7,     8,
       0,     9,    56,     0,     0,     0,    10,    56,   200,   201,
     202,   203,   204,   205,    11,   161,   -95,   162,     0,     0,
      12,   163,   164,   165,   166,   167,   168,   169,   170,   171,
       0,   172,   173,   174,   175,   176,     0,   177,   178,   179,
     180,   181,   182,   183,   184,     0,   185,    13,    14,    15,
      16,     0,    17,    18,    19,    20,    21,    22,    23,     0,
      24,    25,    26,    27,    28,    29,     0,    30,    31,     0,
     219,   220,   221,   222,   223,   224,   225,    56,    56,    56,
     226,    56,    56,    14,    56,    56,     0,    56,   227,   228,
     229,   230,   231,   232,     0,    24,    25,    26,    27,     0,
     300,     0,   301,   318,     0,     0,     0,     0,     0,   130,
       0,     2,     3,     4,     5,     6,     7,     8,    56,     9,
       0,     0,   672,     0,    10,   200,   201,   202,   203,   204,
     205,     0,    11,     0,     0,     0,     0,    56,    12,    56,
      14,   211,   212,     0,     0,     0,    56,    56,    56,    56,
      56,    56,    24,    25,    26,    27,    56,   300,     0,   321,
     322,     0,     0,    56,     0,    13,    14,    15,    16,     0,
      17,    18,    19,    20,    21,    22,    23,     0,    24,    25,
      26,    27,    28,    29,     0,    30,    31,   219,   220,   221,
     222,   223,   224,     0,     0,   130,     0,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,   718,     0,
      10,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,     0,   259,     0,    12,     0,     0,   272,   273,   274,
     275,   276,   277,    57,     0,     0,     0,     0,    57,   278,
     279,   280,     0,   281,   282,     0,    73,     0,    86,    90,
      95,    13,    14,    15,    16,     0,    17,    18,    19,    20,
      21,    22,    23,     0,    24,    25,    26,    27,    28,    29,
       0,    30,    31,   138,     3,     4,     5,     6,     7,     8,
       0,     9,     0,   139,     0,     0,    10,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,     0,     0,     0,
      12,     0,   219,   220,   221,   222,   223,   224,    57,    57,
      57,     0,    57,    57,     0,    57,    57,     0,    57,   267,
      86,   271,   229,   230,   231,   232,     0,    13,    14,    15,
      16,     0,    17,    18,    19,    20,    21,    22,    23,     0,
      24,    25,    26,    27,    28,    29,     0,    30,    31,    57,
       0,     0,    14,     0,   310,     0,     0,     0,     0,     0,
       0,   310,     0,     0,    24,    25,    26,    27,    57,   300,
      57,   301,   380,     0,     0,     0,    14,    57,    57,    57,
      57,    57,    57,     0,     0,     0,     0,    57,    24,    25,
      26,    27,     0,   300,    57,   301,   302,     0,     0,     0,
     310,   351,   354,   357,   360,   363,   366,   370,    90,    90,
      90,     0,   383,   385,   387,   389,   391,   396,   404,   409,
     413,   417,   421,     0,     0,   310,    90,    90,    90,    90,
       0,   437,    90,    90,    90,    90,    90,    90,   454,   457,
     460,   463,   466,    90,   472,    90,   479,   481,   483,   485,
     487,   489,   492,   495,   498,   501,   504,   507,   510,   513,
     516,   519,   522,   526,    90,   533,   536,   539,   542,   545,
     548,   310,   553,    90,    90,    90,    90,    90,    90,    90,
     574,    90,    90,    90,    90,    90,    74,     0,    87,    91,
      91,     0,     0,   310,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   598,   599,     0,
     605,   607,   609,   611,   613,   615,   617,   618,   619,   620,
     621,   622,   624,   626,   628,   630,   632,     0,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,   327,
       0,    10,     0,     0,   655,     0,     0,     0,     0,    11,
       0,     0,     0,     0,     0,    12,     0,     0,     0,   268,
      87,   272,   273,   274,   275,   276,   277,     0,     0,     0,
       0,     0,     0,   278,   279,   280,     0,   281,   282,     0,
       0,     0,    13,    14,    15,    16,     0,    17,    18,    19,
      20,    21,    22,    23,    91,    24,    25,    26,    27,    28,
      29,    91,    30,    31,   161,     0,   162,     0,     0,     0,
     163,   164,   165,   166,   167,   168,   169,   170,   171,     0,
     172,   173,   174,   175,   176,     0,   177,   178,   179,   180,
     181,   182,   183,   184,     0,   185,     0,     0,     0,     0,
      91,   352,   355,   358,   361,   364,   367,   371,    91,    91,
      91,     0,    91,    91,    91,    91,    91,   397,   405,   410,
     414,   418,   422,     0,     0,    91,    91,    91,    91,    91,
       0,   438,    91,    91,    91,    91,    91,    91,   455,   458,
     461,   464,   467,   469,   473,    91,    91,    91,    91,    91,
      91,   490,   493,   496,   499,   502,   505,   508,   511,   514,
     517,   520,   523,   527,    91,   534,   537,   540,   543,   546,
     549,    91,   554,    91,    91,    91,    91,    91,    91,    91,
     575,    91,    91,    91,    91,    91,   200,   201,   202,   203,
     204,   205,   206,    91,     0,     0,   207,     0,   208,   209,
     210,     0,   211,   212,   213,   214,   215,   216,   217,   218,
     606,   608,   610,   612,   614,   616,   600,   601,   602,   603,
     604,   623,   625,   627,   629,   631,   633,     0,   278,     0,
     280,     0,   281,   282,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74,     0,    68,     0,     0,    88,
      94,     2,     3,     4,     5,     6,     7,     8,     0,     9,
     161,     0,   162,     0,    10,     0,   163,   164,   165,   166,
     167,   168,    11,     0,     0,     0,     0,   173,    12,     0,
       0,     0,   177,   178,   179,   180,   181,   182,   183,   184,
       0,   185,     0,     0,     0,     0,     0,     0,   687,   688,
     689,   690,   691,     0,     0,    13,    14,    15,    16,     0,
      17,    18,    19,    20,    21,    22,    23,     0,    24,    25,
      26,    27,    28,    29,     0,    30,    31,   161,     0,   162,
       0,     0,     0,   163,   164,   165,   166,   167,   168,     0,
       0,     0,     0,     0,   173,     0,     0,     0,     0,   177,
     178,     0,     0,     0,   307,     0,   310,   310,   185,     0,
       0,   307,     0,     0,   712,   712,   712,   161,     0,   162,
       0,     0,     0,   163,   164,   165,   166,   167,   168,     0,
     170,   171,     0,   172,   173,   174,   175,   176,     0,   177,
     178,   179,   180,   181,   182,   183,   184,     0,   185,     0,
     307,   349,   353,   356,   359,   362,   365,   368,   374,   376,
     378,     0,   382,   384,   386,   388,   390,   392,   400,   408,
     412,   416,   420,     0,     0,   307,   427,   429,   431,   433,
     310,   435,   441,   443,   445,   447,   449,   451,   453,   456,
     459,   462,   465,   468,   470,   476,   478,   480,   482,   484,
     486,   488,   491,   494,   497,   500,   503,   506,   509,   512,
     515,   518,   521,   524,   530,   532,   535,   538,   541,   544,
     547,   307,   551,   557,   560,   562,   564,   566,   568,   570,
     572,   578,   580,   582,   584,   586,     0,     0,   161,     0,
     162,     0,     0,   307,   163,   164,   165,   166,   167,   168,
       0,   170,     0,     0,   172,   173,   174,   175,   176,     0,
     177,   178,   179,   180,   181,   182,   183,   184,     0,   185,
       0,     0,     0,   161,     0,   162,     0,     0,     0,   163,
     164,   165,   166,   167,   168,     0,     0,     0,     0,   172,
     173,   174,   175,   176,   652,   177,   178,   179,   180,   181,
     182,   183,   184,   161,   185,   162,     0,     0,     0,   163,
     164,   165,   166,   167,   168,     0,     0,     0,     0,     0,
     173,   174,   175,   176,     0,   177,   178,   179,   180,   181,
     182,   183,   184,   161,   185,   162,     0,     0,     0,   163,
     164,   165,   166,   167,   168,     0,    91,    91,     0,     0,
     173,   174,     0,   176,     0,   177,   178,   179,   180,   181,
     182,   183,   184,   161,   185,   162,     0,     0,     0,   163,
     164,   165,   166,   167,   168,     0,     0,     0,     0,     0,
     173,   174,     0,     0,     0,   177,   178,   179,   180,   181,
     182,   183,   184,     0,   185,   161,     0,   162,     0,     0,
       0,   163,   164,   165,   166,   167,   168,     0,     0,     0,
       0,     0,   173,     0,     0,     0,     0,   177,   178,     0,
      91,   181,   182,   183,   184,   259,   185,     0,     0,     0,
     200,   201,   202,   203,   204,   205,   206,     0,     0,     0,
     207,     0,   208,   209,   210,     0,   211,   212,   213,   214,
     215,   216,   217,   218,   -98,     0,     0,     0,     0,   200,
     201,   202,   203,   204,   205,   206,     0,     0,     0,   207,
       0,   208,   209,   210,     0,   211,   212,   213,   214,   215,
     216,   217,   218,   260,     0,     0,     0,     0,   219,   220,
     221,   222,   223,   224,   225,     0,     0,     0,   226,     0,
       0,     0,     0,     0,     0,     0,   227,   228,   229,   230,
     231,   232,   200,   201,   202,   203,   204,   205,     0,     0,
       0,     0,   207,     0,   208,   209,   210,     0,   211,   212,
     213,   214,   215,   216,   217,   218,   200,   201,   202,   203,
     204,   205,     0,     0,     0,     0,     0,     0,   208,     0,
     210,     0,   211,   212,   213,   214,   215,   216,   217,   218,
     200,   201,   202,   203,   204,   205,     0,     0,     0,     0,
       0,     0,   208,     0,     0,     0,   211,   212,   213,   214,
     215,   216,   217,   218,   200,   201,   202,   203,   204,   205,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,     0,     0,     0,     0,   226,   200,
     201,   202,   203,   204,   205,     0,   227,   228,   229,   230,
     231,   232,     0,     0,     0,   211,   212,     0,     0,   215,
     216,   217,   218,     0,     0,     0,   307,   307,   600,   601,
     602,   603,   604,     0,   710,   710,   710,     0,     0,     0,
     278,     0,     0,     0,   281,   282,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,     0,   158,   159,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     307
  };

  const short
   Parser ::yycheck_[] =
  {
       0,   251,    33,     8,   306,   139,     0,   116,     8,     9,
     647,     9,    14,     9,   123,    31,     9,     9,    30,    31,
      20,    10,    24,    25,    26,    27,    77,     9,   638,   639,
       9,     3,     9,    33,    14,    77,    78,     4,     5,    33,
      12,    11,     9,    55,    44,    11,   683,    11,     9,    16,
      77,    67,    41,   162,    66,    67,    42,    77,    70,   113,
      62,    41,    11,    30,   118,   702,    43,    11,    11,    41,
     124,    11,     0,    11,    77,     3,    42,    77,   187,    77,
      41,    77,   136,    69,    77,    77,   696,   724,     3,     4,
       5,     6,     7,     8,     9,    77,    11,    12,    77,   130,
       0,    16,   104,    69,   106,    69,   108,     9,   110,    24,
      77,    78,    11,     3,    13,    30,     4,   119,    11,   173,
      69,     9,    15,    13,   233,    69,    69,    26,    16,    69,
     130,    69,    25,     3,    14,    69,   130,   137,    12,   139,
      33,    34,    30,   143,    14,   139,   255,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
      40,   161,    77,    78,    11,    39,     0,    41,    15,   169,
      69,    39,   172,    41,     8,     9,     9,    11,    77,   179,
     180,   181,   182,   183,   184,    39,    20,    57,    58,     9,
      11,    10,   326,   193,    15,    43,    11,   251,    13,    33,
      70,    71,    72,    73,    58,    75,   206,    77,    78,    10,
      44,    26,    33,    34,    37,    12,    70,    71,    72,    73,
      12,    75,     9,    77,    78,   225,    49,    50,    51,    52,
      11,    41,    13,    13,   234,   235,   236,   237,   238,   239,
     240,   241,   242,    77,   298,    26,   248,    39,     9,    41,
      11,   305,    43,     9,    69,     3,     4,     5,     6,     7,
       8,     9,    77,    11,     3,    26,   266,     3,    16,     9,
      11,    11,    13,    12,   670,    25,    24,    13,   674,    40,
      20,    63,    30,    33,    34,    26,    26,    12,   290,   289,
      13,     9,   292,    17,    18,    19,   130,   328,    69,     9,
      40,   306,    41,   137,    12,   139,   306,    10,    10,   143,
      20,    12,    77,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   326,   161,   328,    77,
      78,    39,   326,    41,   328,   169,   170,   171,   350,   735,
     736,   737,   738,   739,   740,   179,   180,    69,    21,   745,
      12,     9,    25,    69,     0,    42,    58,     9,    11,   193,
      33,    34,    10,     9,   666,   667,   668,    77,    70,    71,
      72,    73,   206,    75,    20,    77,    78,    39,    10,    41,
      11,   393,    35,    36,    37,    38,    11,    33,    69,   401,
      21,   225,    20,    20,    25,    11,   646,    12,    44,     3,
     234,    10,    33,    34,    35,    36,    37,    38,   242,   243,
     244,    10,   246,   247,    12,    10,   428,    20,   430,    20,
     432,    77,   434,    14,     3,    10,    25,   137,    77,    41,
     442,    77,   266,   143,    33,    34,   448,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
      10,   161,    25,    57,    58,   289,    43,    40,   292,     3,
      33,    34,    10,    58,    14,   477,    70,    71,    72,    73,
      39,    75,   306,    77,    78,    70,    71,    72,    73,    43,
      75,    43,    77,    78,   130,    77,    21,    22,    23,    10,
      25,   137,   326,   139,   328,    10,    10,   143,    33,    34,
      11,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,    25,   161,     3,   163,    10,   531,
      10,    10,    33,    34,    35,    36,    37,    38,    22,    23,
      10,    25,    61,   179,   180,    77,    43,   291,   592,    33,
      34,    64,   188,   189,   190,   191,   558,   592,   194,   658,
     659,   197,    17,    18,    19,    20,   266,     9,   136,    11,
      77,   207,    -1,    15,    16,    17,    18,    19,    20,    -1,
     147,   583,    -1,    -1,    26,    22,    -1,    -1,    25,   289,
     226,    -1,   292,    -1,   638,   639,    33,    34,    40,   235,
      -1,   591,   646,    25,    -1,    -1,   596,    -1,    -1,   245,
      -1,    33,    34,    10,    -1,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    21,    22,    23,    16,    25,    -1,
     266,     0,    -1,   732,    -1,    24,    33,    34,    -1,    -1,
       9,    30,     4,     5,     6,     7,     8,     9,    10,    11,
     671,    20,   696,   289,    16,    -1,   292,   701,    17,    18,
      19,    20,    24,    -1,    33,    -1,    -1,    -1,    30,    -1,
      -1,    11,    10,    -1,    -1,    44,   666,   667,   668,    -1,
     670,   671,    -1,   673,   674,    -1,   676,   671,    77,    78,
     326,    -1,   328,    33,    34,    35,    36,    37,    38,    -1,
      -1,    39,     4,     5,     6,     7,     8,     9,    77,    11,
      17,    18,    19,    20,    16,    77,    78,   707,     4,     5,
      58,    -1,    24,     9,    17,    18,    19,    20,    30,    -1,
      16,    -1,    70,    71,    72,    73,   726,    75,   728,    77,
      78,    -1,    -1,    -1,    30,   735,   736,   737,   738,   739,
     740,    -1,    -1,    -1,    -1,   745,    15,    16,    17,    18,
      19,   130,   752,    -1,    -1,    -1,    -1,   591,   137,    -1,
     139,    -1,   596,    10,   143,    77,    78,    -1,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,    -1,   161,    -1,     4,     5,     6,     7,     8,     9,
     169,    11,    39,    -1,    -1,    -1,    16,    -1,    -1,    -1,
     179,   180,    -1,    -1,    24,    15,    16,    17,    18,    19,
      30,    58,    -1,    -1,   193,    -1,   195,   196,    -1,    -1,
      -1,    31,    32,    70,    71,    72,    73,   206,    75,    -1,
      77,    78,   666,   667,   668,    -1,   670,   671,    -1,   673,
     674,    -1,   676,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,    -1,     0,    -1,    -1,   234,    -1,    77,    78,    -1,
       8,     9,    -1,   242,     4,     5,     6,     7,     8,     9,
      -1,    11,    20,   707,    -1,    -1,    16,    -1,    -1,    -1,
      -1,   591,    -1,    -1,    24,    33,   596,   266,    -1,    -1,
      30,    -1,   726,    -1,   728,    -1,    44,    -1,    -1,    -1,
      -1,   735,   736,   737,   738,   739,   740,    -1,    -1,    -1,
     289,   745,    -1,   292,    -1,    -1,    -1,    -1,   752,    -1,
       4,     5,     6,     7,     8,     9,    -1,    11,     0,    77,
      -1,     3,    16,    -1,    -1,    -1,    -1,    77,    78,    -1,
      24,    -1,    -1,    -1,    -1,   591,    30,   326,    -1,   328,
     596,    -1,    -1,    -1,    -1,    -1,   666,   667,   668,    -1,
      -1,    -1,    -1,   673,    -1,    -1,   676,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,   130,    55,    56,    -1,    -1,    -1,    -1,   137,
      -1,   139,    -1,    77,    78,   143,    -1,   707,    -1,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,    -1,   161,    -1,    -1,   726,    -1,   728,    -1,
     666,   667,   668,    -1,   670,   671,    -1,   673,   674,    10,
     676,   179,   180,    -1,    15,    16,    17,    18,    19,    20,
      -1,    -1,   752,    -1,    -1,    -1,     9,    10,    11,    -1,
     198,   199,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   707,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    40,    -1,    10,
     726,    -1,   728,    -1,    15,    16,    17,    18,    19,   735,
     736,   737,   738,   739,   740,    -1,    27,    28,    29,   745,
      31,    32,    -1,     9,    -1,    11,   752,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    -1,    -1,    -1,   266,    -1,
      26,    -1,    -1,    -1,     0,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    40,    11,    10,    11,    -1,    -1,
      16,   289,    -1,    -1,   292,    -1,    -1,    21,    24,    -1,
      -1,    25,    -1,    58,    30,    -1,    -1,    -1,   306,    33,
      34,    35,    36,    37,    38,    70,    71,    72,    73,    -1,
      75,    -1,    77,    78,    -1,    -1,    -1,    -1,   326,    -1,
     328,    57,    58,    59,    60,    -1,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
       0,    77,    78,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,   591,    -1,    -1,    -1,    16,   596,    15,    16,
      17,    18,    19,    20,    24,     9,    10,    11,    -1,    -1,
      30,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    40,    57,    58,    59,
      60,    -1,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    -1,    77,    78,    -1,
      15,    16,    17,    18,    19,    20,    21,   666,   667,   668,
      25,   670,   671,    58,   673,   674,    -1,   676,    33,    34,
      35,    36,    37,    38,    -1,    70,    71,    72,    73,    -1,
      75,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,   707,    11,
      -1,    -1,    14,    -1,    16,    15,    16,    17,    18,    19,
      20,    -1,    24,    -1,    -1,    -1,    -1,   726,    30,   728,
      58,    31,    32,    -1,    -1,    -1,   735,   736,   737,   738,
     739,   740,    70,    71,    72,    73,   745,    75,    -1,    77,
      78,    -1,    -1,   752,    -1,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    -1,    77,    78,    15,    16,    17,
      18,    19,    20,    -1,    -1,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    -1,    -1,    14,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    10,    -1,    30,    -1,    -1,    15,    16,    17,
      18,    19,    20,   591,    -1,    -1,    -1,    -1,   596,    27,
      28,    29,    -1,    31,    32,    -1,     8,    -1,    10,    11,
      12,    57,    58,    59,    60,    -1,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      -1,    77,    78,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    13,    -1,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    15,    16,    17,    18,    19,    20,   666,   667,
     668,    -1,   670,   671,    -1,   673,   674,    -1,   676,    81,
      82,    83,    35,    36,    37,    38,    -1,    57,    58,    59,
      60,    -1,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    -1,    77,    78,   707,
      -1,    -1,    58,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,   123,    -1,    -1,    70,    71,    72,    73,   726,    75,
     728,    77,    78,    -1,    -1,    -1,    58,   735,   736,   737,
     738,   739,   740,    -1,    -1,    -1,    -1,   745,    70,    71,
      72,    73,    -1,    75,   752,    77,    78,    -1,    -1,    -1,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,    -1,    -1,   187,   188,   189,   190,   191,
      -1,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     8,    -1,    10,    11,
      12,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,   270,    -1,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    -1,    -1,    14,
      -1,    16,    -1,    -1,   306,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    81,
      82,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    -1,    31,    32,    -1,
      -1,    -1,    57,    58,    59,    60,    -1,    62,    63,    64,
      65,    66,    67,    68,   116,    70,    71,    72,    73,    74,
      75,   123,    77,    78,     9,    -1,    11,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    40,    -1,    -1,    -1,    -1,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,    -1,    -1,   187,   188,   189,   190,   191,
      -1,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    15,    16,    17,    18,
      19,    20,    21,   255,    -1,    -1,    25,    -1,    27,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
     272,   273,   274,   275,   276,   277,    15,    16,    17,    18,
      19,   283,   284,   285,   286,   287,   288,    -1,    27,    -1,
      29,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   306,    -1,     8,    -1,    -1,    11,
      12,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
       9,    -1,    11,    -1,    16,    -1,    15,    16,    17,    18,
      19,    20,    24,    -1,    -1,    -1,    -1,    26,    30,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,   600,   601,
     602,   603,   604,    -1,    -1,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    -1,    77,    78,     9,    -1,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    -1,   116,    -1,   658,   659,    40,    -1,
      -1,   123,    -1,    -1,   666,   667,   668,     9,    -1,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    -1,
      22,    23,    -1,    25,    26,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    40,    -1,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,    -1,    -1,   187,   188,   189,   190,   191,
     732,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,     9,    -1,
      11,    -1,    -1,   255,    15,    16,    17,    18,    19,    20,
      -1,    22,    -1,    -1,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    40,
      -1,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    29,   306,    31,    32,    33,    34,    35,
      36,    37,    38,     9,    40,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,     9,    40,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    -1,   658,   659,    -1,    -1,
      26,    27,    -1,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,     9,    40,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      26,    27,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    40,     9,    -1,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,    -1,    -1,    -1,    -1,    31,    32,    -1,
     732,    35,    36,    37,    38,    10,    40,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      25,    -1,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    10,    -1,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    25,
      -1,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    10,    -1,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,
      37,    38,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    25,    -1,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    25,    15,
      16,    17,    18,    19,    20,    -1,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,
      36,    37,    38,    -1,    -1,    -1,   658,   659,    15,    16,
      17,    18,    19,    -1,   666,   667,   668,    -1,    -1,    -1,
      27,    -1,    -1,    -1,    31,    32,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     732
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
     117,   121,   122,   125,   126,   127,   128,     3,    12,   113,
     116,     9,    16,    30,    77,    78,   125,   126,   114,   122,
     125,   126,   127,   128,   114,   125,   128,    77,    11,   132,
      77,    89,   113,    77,    69,   132,    69,   132,    69,   132,
      69,   132,    77,     9,    77,   106,    11,    13,    26,    69,
     120,   123,   132,    11,    26,    69,   120,   123,     0,     0,
       1,    84,     0,     3,    83,    83,     9,     9,     3,    13,
      85,    86,    87,     9,    83,    83,    83,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    55,    56,
      83,     9,    11,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    25,    26,    27,    28,    29,    31,    32,    33,
      34,    35,    36,    37,    38,    40,   120,    11,    15,    25,
      33,    34,   120,    21,    25,    33,    34,    25,    33,    34,
      15,    16,    17,    18,    19,    20,    21,    25,    27,    28,
      29,    31,    32,    33,    34,    35,    36,    37,    38,    15,
      16,    17,    18,    19,    20,    21,    25,    33,    34,    35,
      36,    37,    38,    11,    21,    25,    33,    34,    35,    36,
      37,    38,    21,    22,    23,    25,    33,    34,    69,   132,
      69,     9,    77,   106,    10,    11,    10,    10,    10,    10,
      10,    10,    10,   116,     3,    12,    41,   125,   126,     9,
      16,   125,    15,    16,    17,    18,    19,    20,    27,    28,
      29,    31,    32,    15,    16,    17,    18,    19,    20,    43,
      12,    41,    43,   132,   132,   132,   132,     3,    13,    10,
      75,    77,    78,   130,   133,     9,     9,   114,   118,   119,
     125,    14,    40,   124,    78,   133,   132,   119,    78,   133,
      84,    77,    78,   109,   133,   113,    13,    14,    82,    63,
     113,   111,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,    10,   112,   113,   119,   114,
     117,   125,   126,   114,   125,   126,   114,   125,   126,   114,
     125,   126,   114,   125,   126,   114,   125,   126,   114,   121,
     125,   126,   127,   128,   114,   128,   114,   128,   114,   127,
      78,   133,   114,   125,   114,   125,   114,   125,   114,   125,
     114,   125,   114,   117,   121,   122,   125,   126,   127,   128,
     114,   117,   121,   122,   125,   126,   127,   128,   114,   125,
     126,   127,   114,   125,   126,   127,   114,   125,   126,   127,
     114,   125,   126,   127,    77,    78,   119,   114,   117,   114,
     117,   114,   117,   114,   117,   114,   121,   125,   126,   127,
     128,   114,   117,   114,   121,   114,   121,   114,   117,   114,
     122,   114,   122,   114,   125,   126,   114,   125,   126,   114,
     125,   126,   114,   125,   126,   114,   125,   126,   114,   126,
     114,   121,   125,   126,   127,   128,   114,   117,   114,   125,
     114,   125,   114,   125,   114,   125,   114,   125,   114,   125,
     126,   114,   125,   126,   114,   125,   126,   114,   125,   126,
     114,   125,   126,   114,   125,   126,   114,   125,   126,   114,
     125,   126,   114,   125,   126,   114,   125,   126,   114,   125,
     126,   114,   125,   126,   114,   121,   125,   126,   127,   128,
     114,   117,   114,   125,   126,   114,   125,   126,   114,   125,
     126,   114,   125,   126,   114,   125,   126,   114,   125,   126,
     119,   114,   121,   125,   126,   127,   128,   114,   117,   127,
     114,   127,   114,   127,   114,   127,   114,   127,   114,   127,
     114,   127,   114,   121,   125,   126,   127,   128,   114,   128,
     114,   128,   114,   117,   114,   128,   114,   128,   132,    10,
     130,    43,     9,     3,    12,    12,     3,   113,   125,   125,
      15,    16,    17,    18,    19,   125,   126,   125,   126,   125,
     126,   125,   126,   125,   126,   125,   126,   125,   125,   125,
     125,   125,   125,   126,   125,   126,   125,   126,   125,   126,
     125,   126,   125,   126,   113,   132,    89,   113,    13,     3,
      14,    57,   103,   104,   133,    10,    41,    10,    39,   107,
     108,   133,   114,   118,   119,   125,    12,    12,    39,    41,
      77,    14,    41,    69,    12,    69,    42,    42,    42,    77,
      10,    82,    14,     9,    10,    10,    41,    12,    69,    12,
      12,    10,   113,    10,   108,    12,   113,   125,   125,   125,
     125,   125,   103,   103,    77,    14,     3,    77,   130,    86,
      77,    41,    10,    77,    10,   119,   119,    43,    40,   113,
     114,   118,   125,   113,   118,   113,   118,    87,    14,     3,
     113,    87,   113,    86,    10,    14,    43,   103,    43,    39,
     133,    86,    39,   113,    77,    10,    10,    10,    10,    10,
      10,     3,    10,    61,    99,   101,    86,   113,   113,    77,
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
     103,   104,   104,   104,   105,   105,   105,   105,   106,   107,
     107,   108,   108,   108,   109,   110,   110,   110,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   112,   112,   113,   113,   113,   113,   113,   113,
     113,   113,   114,   114,   114,   114,   114,   114,   114,   114,
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
     114,   114,   114,   114,   115,   115,   115,   115,   115,   116,
     116,   116,   117,   117,   118,   118,   118,   119,   119,   120,
     121,   121,   122,   122,   122,   123,   123,   124,   124,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   129,   129,   129,   129,   130,   130,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     132,   132,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133
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
       4,     2,     4,     1,     2,     4,     4,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     3,     3,     4,     4,
       4,     4,     4,     4,     3,     3,     3,     4,     4,     4,
       3,     3,     3,     2,     2,     2,     2,     3,     3,     3,
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
       3,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     4,     4,     5,     1,
       3,     4,     1,     3,     3,     3,     5,     1,     1,     3,
       1,     3,     2,     2,     3,     2,     3,     4,     6,     1,
       2,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     3,     4,     3,     1,     3,     2,     2,     2,
       2,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       2,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
     348,   350,   351,   352,   357,   361,   362,   363,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   384,   385,   389,   390,   391,   392,   393,   394,
     395,   396,   399,   400,   401,   402,   403,   405,   406,   408,
     409,   410,   411,   412,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   424,   425,   426,   427,   429,   430,   433,
     434,   435,   436,   437,   439,   440,   441,   442,   443,   445,
     446,   447,   448,   449,   451,   452,   453,   454,   455,   457,
     458,   459,   460,   461,   462,   463,   464,   466,   467,   468,
     469,   470,   472,   473,   474,   476,   477,   478,   480,   481,
     482,   483,   484,   485,   486,   488,   489,   490,   491,   492,
     493,   494,   496,   497,   498,   499,   500,   501,   502,   504,
     505,   506,   507,   508,   509,   510,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     526,   527,   528,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     548,   549,   550,   552,   553,   554,   556,   557,   558,   560,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   577,   578,   579,   581,   582,
     583,   585,   587,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   603,   604,   605,   606,   607,   610,
     611,   612,   616,   617,   619,   620,   621,   623,   624,   626,
     631,   632,   636,   637,   638,   640,   641,   643,   644,   648,
     649,   650,   651,   652,   653,   654,   655,   656,   657,   658,
     659,   660,   661,   665,   666,   667,   668,   669,   670,   671,
     672,   673,   674,   675,   676,   677,   678,   679,   680,   681,
     682,   683,   684,   685,   689,   690,   691,   692,   693,   694,
     695,   696,   697,   698,   699,   700,   701,   702,   703,   704,
     705,   706,   707,   708,   709,   710,   711,   712,   713,   714,
     715,   719,   720,   721,   722,   723,   725,   726,   727,   728,
     729,   730,   731,   733,   734,   735,   736,   737,   738,   739,
     741,   742,   743,   744,   745,   747,   748,   749,   750,   751,
     753,   754,   755,   756,   757,   759,   760,   761,   762,   763,
     765,   769,   770,   771,   772,   774,   775,   779,   780,   781,
     782,   783,   784,   785,   786,   787,   788,   789,   790,   791,
     793,   795,   800,   801,   802,   803,   804,   805,   806,   807,
     808,   809,   810,   811,   812,   813,   814,   815,   816
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
#line 5109 "frontend/parser.cpp"

#line 819 "frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    auto msg = std::to_string(scanner->llvmloc->begin.line) + ":" + std::to_string(scanner->llvmloc->begin.column) + ": " + err_message;
    scanner->fatal_error(ptc::diag::ERR_SYNTAX, msg);
}
