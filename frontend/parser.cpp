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
#line 238 "frontend/parser.yy"
                        { scanner->parseEntry(std::vector<ptc::ir::IR *>{}); }
#line 1218 "frontend/parser.cpp"
    break;

  case 3: // start: stmt "end of file"
#line 239 "frontend/parser.yy"
                        { scanner->parseEntry(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1224 "frontend/parser.cpp"
    break;

  case 4: // stmt: stmts
#line 241 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1230 "frontend/parser.cpp"
    break;

  case 5: // stmt: stmt stmts
#line 242 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1236 "frontend/parser.cpp"
    break;

  case 6: // stmt: stmt error stmts
#line 243 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1242 "frontend/parser.cpp"
    break;

  case 9: // stmts: "terminator (\\n or ;)"
#line 250 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = nullptr; }
#line 1248 "frontend/parser.cpp"
    break;

  case 10: // stmts: stmts_ne
#line 251 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1254 "frontend/parser.cpp"
    break;

  case 11: // stmts_ne: set stmt_end
#line 253 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1260 "frontend/parser.cpp"
    break;

  case 12: // stmts_ne: vardecl stmt_end
#line 254 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1266 "frontend/parser.cpp"
    break;

  case 13: // stmts_ne: vardef stmt_end
#line 255 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1272 "frontend/parser.cpp"
    break;

  case 14: // stmts_ne: import stmt_end
#line 256 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1278 "frontend/parser.cpp"
    break;

  case 15: // stmts_ne: for
#line 257 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1284 "frontend/parser.cpp"
    break;

  case 16: // stmts_ne: if
#line 258 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1290 "frontend/parser.cpp"
    break;

  case 17: // stmts_ne: while
#line 259 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1296 "frontend/parser.cpp"
    break;

  case 18: // stmts_ne: dowhile
#line 260 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1302 "frontend/parser.cpp"
    break;

  case 19: // stmts_ne: struct
#line 261 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1308 "frontend/parser.cpp"
    break;

  case 20: // stmts_ne: function
#line 262 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1314 "frontend/parser.cpp"
    break;

  case 21: // stmts_ne: flowctl stmt_end
#line 263 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1320 "frontend/parser.cpp"
    break;

  case 22: // stmts_ne: expr stmt_end
#line 264 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1326 "frontend/parser.cpp"
    break;

  case 23: // block: "{" "}"
#line 268 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1332 "frontend/parser.cpp"
    break;

  case 24: // block: "{" stmt "}"
#line 269 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1338 "frontend/parser.cpp"
    break;

  case 25: // block: "terminator (\\n or ;)" "{" stmt "}"
#line 270 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1344 "frontend/parser.cpp"
    break;

  case 26: // block: "{" stmt "}" "terminator (\\n or ;)"
#line 271 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1350 "frontend/parser.cpp"
    break;

  case 27: // block: "terminator (\\n or ;)" "{" stmt "}" "terminator (\\n or ;)"
#line 272 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1356 "frontend/parser.cpp"
    break;

  case 28: // scope_body: stmts_ne
#line 275 "frontend/parser.yy"
                      { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); scanner->leaveScope(); }
#line 1362 "frontend/parser.cpp"
    break;

  case 29: // scope_body: block
#line 276 "frontend/parser.yy"
                      { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); scanner->leaveScope(); }
#line 1368 "frontend/parser.cpp"
    break;

  case 30: // import: "import" id_list
#line 280 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::IR * > () = scanner->parseImports(yystack_[0].value.as < std::vector<std::string>  > ()); }
#line 1374 "frontend/parser.cpp"
    break;

  case 31: // id_list: "identifier"
#line 282 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseImportName(yystack_[0].value.as < std::string > ()); }
#line 1380 "frontend/parser.cpp"
    break;

  case 32: // id_list: "identifier" "," id_list
#line 283 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseAddImportName(yystack_[0].value.as < std::vector<std::string>  > (), yystack_[2].value.as < std::string > ()); }
#line 1386 "frontend/parser.cpp"
    break;

  case 33: // flowctl: "break"
#line 287 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseBreak(); }
#line 1392 "frontend/parser.cpp"
    break;

  case 34: // flowctl: "continue"
#line 288 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseContinue(); }
#line 1398 "frontend/parser.cpp"
    break;

  case 35: // flowctl: return
#line 289 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1404 "frontend/parser.cpp"
    break;

  case 36: // return: "return"
#line 291 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(nullptr); }
#line 1410 "frontend/parser.cpp"
    break;

  case 37: // return: "return" expr
#line 292 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1416 "frontend/parser.cpp"
    break;

  case 38: // for: for_kw "(" vardecl ":" expr ")" scope_body
#line 296 "frontend/parser.yy"
                                                      { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1422 "frontend/parser.cpp"
    break;

  case 39: // for: for_kw "(" "identifier" ":" expr ")" scope_body
#line 297 "frontend/parser.yy"
                                                      { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1428 "frontend/parser.cpp"
    break;

  case 40: // for: for_kw "(" "external identifier" ":" expr ")" scope_body
#line 298 "frontend/parser.yy"
                                                      { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1434 "frontend/parser.cpp"
    break;

  case 41: // for: for_kw "(" vardecl ":" range ")" scope_body
#line 299 "frontend/parser.yy"
                                                      { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1440 "frontend/parser.cpp"
    break;

  case 42: // for: for_kw "(" "identifier" ":" range ")" scope_body
#line 300 "frontend/parser.yy"
                                                      { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1446 "frontend/parser.cpp"
    break;

  case 43: // for: for_kw "(" "external identifier" ":" range ")" scope_body
#line 301 "frontend/parser.yy"
                                                      { yylhs.value.as < ptc::ir::IR * > () = scanner->parseForeach(scanner->parseVar(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1452 "frontend/parser.cpp"
    break;

  case 44: // for_kw: "for"
#line 303 "frontend/parser.yy"
               { scanner->enterBlockScope(); }
#line 1458 "frontend/parser.cpp"
    break;

  case 45: // while: wh_kw "(" expr ")" scope_body
#line 306 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseWhile(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1464 "frontend/parser.cpp"
    break;

  case 46: // wh_kw: "while"
#line 308 "frontend/parser.yy"
                { scanner->enterBlockScope(); }
#line 1470 "frontend/parser.cpp"
    break;

  case 47: // dowhile: do_kw scope_body "while" "(" expr ")"
#line 310 "frontend/parser.yy"
                                                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseDoWhile(yystack_[1].value.as < ptc::ir::Expr * > (), yystack_[4].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1476 "frontend/parser.cpp"
    break;

  case 48: // do_kw: "do"
#line 312 "frontend/parser.yy"
             { scanner->enterBlockScope(); }
#line 1482 "frontend/parser.cpp"
    break;

  case 49: // if: if_kw "(" expr ")" scope_body else
#line 315 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseIfStmt(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1488 "frontend/parser.cpp"
    break;

  case 50: // else: el_kw scope_body
#line 317 "frontend/parser.yy"
                         { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1494 "frontend/parser.cpp"
    break;

  case 51: // else: %empty
#line 318 "frontend/parser.yy"
                         { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1500 "frontend/parser.cpp"
    break;

  case 52: // if_kw: "if"
#line 320 "frontend/parser.yy"
             { scanner->enterBlockScope(); }
#line 1506 "frontend/parser.cpp"
    break;

  case 53: // el_kw: "else"
#line 321 "frontend/parser.yy"
               { scanner->enterBlockScope(); }
#line 1512 "frontend/parser.cpp"
    break;

  case 54: // struct: "'struct'" "identifier" "{" "}"
#line 324 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[2].value.as < std::string > (), std::vector<ptc::ir::IR *>{}); }
#line 1518 "frontend/parser.cpp"
    break;

  case 55: // struct: "'struct'" "identifier" "{" decllist "}"
#line 325 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1524 "frontend/parser.cpp"
    break;

  case 56: // struct: "'struct'" "identifier" "terminator (\\n or ;)" "{" decllist "}"
#line 326 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[4].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1530 "frontend/parser.cpp"
    break;

  case 58: // decllist: "terminator (\\n or ;)" decllist
#line 329 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1536 "frontend/parser.cpp"
    break;

  case 59: // decllist: declistval "terminator (\\n or ;)"
#line 330 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[1].value.as < ptc::ir::IR * > (), std::vector<ptc::ir::IR *>{}); }
#line 1542 "frontend/parser.cpp"
    break;

  case 60: // decllist: declistval "terminator (\\n or ;)" decllist
#line 331 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[2].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1548 "frontend/parser.cpp"
    break;

  case 61: // declistval: type "identifier"
#line 333 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > (), nullptr); }
#line 1554 "frontend/parser.cpp"
    break;

  case 62: // declistval: type "identifier" "=" expr
#line 334 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1560 "frontend/parser.cpp"
    break;

  case 64: // function: type fun_id "(" ")" block
#line 339 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1566 "frontend/parser.cpp"
    break;

  case 65: // function: type fun_id "(" funargs ")" block
#line 340 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[5].value.as < ptc::ir::IR * > (), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1572 "frontend/parser.cpp"
    break;

  case 66: // function: "'void'" fun_id "(" ")" block
#line 341 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1578 "frontend/parser.cpp"
    break;

  case 67: // function: "'void'" fun_id "(" funargs ")" block
#line 342 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1584 "frontend/parser.cpp"
    break;

  case 68: // fun_id: "identifier"
#line 344 "frontend/parser.yy"
            { scanner->enterFunScope(); yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1590 "frontend/parser.cpp"
    break;

  case 69: // funargsnvar: type "identifier"
#line 346 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseFunParam(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1596 "frontend/parser.cpp"
    break;

  case 70: // funargsnvar: funargsnvar "," type "identifier"
#line 347 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseAddFunParam(yystack_[3].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1602 "frontend/parser.cpp"
    break;

  case 71: // funargs: ".." "identifier"
#line 349 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseFunParam(scanner->sym_lookup(VARARGS_CSTR, false, true), yystack_[0].value.as < std::string > ()); }
#line 1608 "frontend/parser.cpp"
    break;

  case 72: // funargs: funargsnvar "," ".." "identifier"
#line 350 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseAddFunParam(yystack_[3].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), scanner->sym_lookup(VARARGS_CSTR, false, true), yystack_[0].value.as < std::string > ());}
#line 1614 "frontend/parser.cpp"
    break;

  case 73: // funargs: funargsnvar
#line 351 "frontend/parser.yy"
                                        { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = yystack_[0].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (); }
#line 1620 "frontend/parser.cpp"
    break;

  case 74: // vardecl: type "identifier"
#line 356 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1626 "frontend/parser.cpp"
    break;

  case 75: // vardef: type "identifier" "=" struct_val
#line 360 "frontend/parser.yy"
         { yylhs.value.as < ptc::ir::IR * > () = yystack_[3].value.as < ptc::ir::IR * > (); }
#line 1632 "frontend/parser.cpp"
    break;

  case 76: // vardef: type "identifier" "=" expr
#line 361 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1638 "frontend/parser.cpp"
    break;

  case 79: // set: expr "++=" expr
#line 367 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1644 "frontend/parser.cpp"
    break;

  case 80: // set: expr "**=" expr
#line 368 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1650 "frontend/parser.cpp"
    break;

  case 81: // set: expr "%=" expr
#line 369 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1656 "frontend/parser.cpp"
    break;

  case 82: // set: expr "/=" expr
#line 370 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1662 "frontend/parser.cpp"
    break;

  case 83: // set: expr "*=" expr
#line 371 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1668 "frontend/parser.cpp"
    break;

  case 84: // set: expr "-=" expr
#line 372 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1674 "frontend/parser.cpp"
    break;

  case 85: // set: expr "+=" expr
#line 373 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1680 "frontend/parser.cpp"
    break;

  case 86: // set: expr "&=" expr
#line 374 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1686 "frontend/parser.cpp"
    break;

  case 87: // set: expr "|=" expr
#line 375 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1692 "frontend/parser.cpp"
    break;

  case 88: // set: expr "^=" expr
#line 376 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1698 "frontend/parser.cpp"
    break;

  case 89: // set: expr "<<=" expr
#line 377 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1704 "frontend/parser.cpp"
    break;

  case 90: // set: expr ">>=" expr
#line 378 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1710 "frontend/parser.cpp"
    break;

  case 91: // set: expr "=" expr
#line 379 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1716 "frontend/parser.cpp"
    break;

  case 92: // set: expr "=" set
#line 380 "frontend/parser.yy"
      { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1722 "frontend/parser.cpp"
    break;

  case 93: // callarglist: expr
#line 384 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseFunCallArg(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1728 "frontend/parser.cpp"
    break;

  case 94: // callarglist: callarglist "," expr
#line 385 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddFunCallArg(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1734 "frontend/parser.cpp"
    break;

  case 95: // expr: expr_mat
#line 389 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1740 "frontend/parser.cpp"
    break;

  case 96: // expr: expr_var
#line 390 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1746 "frontend/parser.cpp"
    break;

  case 97: // expr: expr_none
#line 391 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1752 "frontend/parser.cpp"
    break;

  case 98: // expr: expr_struct
#line 392 "frontend/parser.yy"
       { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1758 "frontend/parser.cpp"
    break;

  case 99: // expr: expr_int
#line 393 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 1764 "frontend/parser.cpp"
    break;

  case 100: // expr: expr_float
#line 394 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFloat(yystack_[0].value.as < double > ()); }
#line 1770 "frontend/parser.cpp"
    break;

  case 101: // expr: expr_str
#line 395 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseString(yystack_[0].value.as < std::string > ()); }
#line 1776 "frontend/parser.cpp"
    break;

  case 102: // expr: expr_bool
#line 396 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseBool(yystack_[0].value.as < bool > ()); }
#line 1782 "frontend/parser.cpp"
    break;

  case 103: // expr_var: "identifier"
#line 399 "frontend/parser.yy"
              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > ()); }
#line 1788 "frontend/parser.cpp"
    break;

  case 104: // expr_var: "external identifier"
#line 400 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > (), true); }
#line 1794 "frontend/parser.cpp"
    break;

  case 105: // expr_var: "-" "identifier"
#line 401 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1800 "frontend/parser.cpp"
    break;

  case 106: // expr_var: "-" "external identifier"
#line 402 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > (), true), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1806 "frontend/parser.cpp"
    break;

  case 107: // expr_var: "(" expr_var ")"
#line 403 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1812 "frontend/parser.cpp"
    break;

  case 108: // expr_var: expr_var "(" ")"
#line 405 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[2].value.as < ptc::ir::Expr * > (), std::vector<ptc::ir::Expr *>{}); }
#line 1818 "frontend/parser.cpp"
    break;

  case 109: // expr_var: expr_var "(" callarglist ")"
#line 406 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 1824 "frontend/parser.cpp"
    break;

  case 110: // expr_var: expr_str "[" int_val "]"
#line 408 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1830 "frontend/parser.cpp"
    break;

  case 111: // expr_var: expr_mat "[" int_val "]"
#line 409 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1836 "frontend/parser.cpp"
    break;

  case 112: // expr_var: "identifier" "[" int_val "]"
#line 410 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1842 "frontend/parser.cpp"
    break;

  case 113: // expr_var: "external identifier" "[" int_val "]"
#line 411 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1848 "frontend/parser.cpp"
    break;

  case 114: // expr_var: expr_var "[" int_val "]"
#line 412 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUBSCR)); }
#line 1854 "frontend/parser.cpp"
    break;

  case 115: // expr_var: "identifier" "as" "external identifier"
#line 414 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > ()), scanner->parseVar(scanner->parseExtType(yystack_[0].value.as < std::string > (), false)->getName(), true, false), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1860 "frontend/parser.cpp"
    break;

  case 116: // expr_var: "external identifier" "as" "external identifier"
#line 415 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > (), true), scanner->parseVar(scanner->parseExtType(yystack_[0].value.as < std::string > (), false)->getName(), true, false), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1866 "frontend/parser.cpp"
    break;

  case 117: // expr_var: expr_var "as" "external identifier"
#line 416 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseVar(scanner->parseExtType(yystack_[0].value.as < std::string > (), false)->getName(), true, false), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1872 "frontend/parser.cpp"
    break;

  case 118: // expr_var: "identifier" "as" "external identifier" "?"
#line 417 "frontend/parser.yy"
                                      { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > ()), scanner->parseVar(scanner->parseExtType(yystack_[1].value.as < std::string > (), true)->getName(), true, true), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1878 "frontend/parser.cpp"
    break;

  case 119: // expr_var: "external identifier" "as" "external identifier" "?"
#line 418 "frontend/parser.yy"
                                      { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[3].value.as < std::string > (), true), scanner->parseVar(scanner->parseExtType(yystack_[1].value.as < std::string > (), true)->getName(), true, true), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1884 "frontend/parser.cpp"
    break;

  case 120: // expr_var: expr_var "as" "external identifier" "?"
#line 419 "frontend/parser.yy"
                                      { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[3].value.as < ptc::ir::Expr * > (), scanner->parseVar(scanner->parseExtType(yystack_[1].value.as < std::string > (), true)->getName(), true, true), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1890 "frontend/parser.cpp"
    break;

  case 121: // expr_var: "identifier" "as" type
#line 420 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > ()), scanner->parseVar(yystack_[0].value.as < ptc::ir::IR * > ()->getName(), false, llvm::dyn_cast<ptc::ir::TypeDecl>(yystack_[0].value.as < ptc::ir::IR * > ())->isMaybe()), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1896 "frontend/parser.cpp"
    break;

  case 122: // expr_var: "external identifier" "as" type
#line 421 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > (), true), scanner->parseVar(yystack_[0].value.as < ptc::ir::IR * > ()->getName(), false, llvm::dyn_cast<ptc::ir::TypeDecl>(yystack_[0].value.as < ptc::ir::IR * > ())->isMaybe()), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1902 "frontend/parser.cpp"
    break;

  case 123: // expr_var: expr_var "as" type
#line 422 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseVar(yystack_[0].value.as < ptc::ir::IR * > ()->getName(), false, llvm::dyn_cast<ptc::ir::TypeDecl>(yystack_[0].value.as < ptc::ir::IR * > ())->isMaybe()), ir::Operator(ir::OperatorKind::OP_AS)); }
#line 1908 "frontend/parser.cpp"
    break;

  case 124: // expr_var: expr_mat slice
#line 424 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1914 "frontend/parser.cpp"
    break;

  case 127: // expr_var: expr_var slice
#line 427 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1920 "frontend/parser.cpp"
    break;

  case 128: // expr_var: expr_var "." "identifier"
#line 429 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1926 "frontend/parser.cpp"
    break;

  case 129: // expr_var: expr_var "." "external identifier"
#line 430 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1932 "frontend/parser.cpp"
    break;

  case 130: // expr_var: expr_float "**" expr_var
#line 433 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1938 "frontend/parser.cpp"
    break;

  case 131: // expr_var: expr_var "**" expr_float
#line 434 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1944 "frontend/parser.cpp"
    break;

  case 132: // expr_var: expr_var "**" expr_var
#line 435 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1950 "frontend/parser.cpp"
    break;

  case 133: // expr_var: expr_int "**" expr_var
#line 436 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < long > ()) /*Float on purpose*/, yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1956 "frontend/parser.cpp"
    break;

  case 134: // expr_var: expr_var "**" expr_int
#line 437 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < long > ()) /*Float on purpose*/, ir::Operator(ir::OperatorKind::OP_POW)); }
#line 1962 "frontend/parser.cpp"
    break;

  case 135: // expr_var: expr_int "*" expr_var
#line 439 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1968 "frontend/parser.cpp"
    break;

  case 136: // expr_var: expr_float "*" expr_var
#line 440 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1974 "frontend/parser.cpp"
    break;

  case 137: // expr_var: expr_var "*" expr_int
#line 441 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1980 "frontend/parser.cpp"
    break;

  case 138: // expr_var: expr_var "*" expr_float
#line 442 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1986 "frontend/parser.cpp"
    break;

  case 139: // expr_var: expr_var "*" expr_var
#line 443 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1992 "frontend/parser.cpp"
    break;

  case 140: // expr_var: expr_int "/" expr_var
#line 445 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1998 "frontend/parser.cpp"
    break;

  case 141: // expr_var: expr_float "/" expr_var
#line 446 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 2004 "frontend/parser.cpp"
    break;

  case 142: // expr_var: expr_var "/" expr_int
#line 447 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 2010 "frontend/parser.cpp"
    break;

  case 143: // expr_var: expr_var "/" expr_float
#line 448 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 2016 "frontend/parser.cpp"
    break;

  case 144: // expr_var: expr_var "/" expr_var
#line 449 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 2022 "frontend/parser.cpp"
    break;

  case 145: // expr_var: expr_int "%" expr_var
#line 451 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 2028 "frontend/parser.cpp"
    break;

  case 146: // expr_var: expr_float "%" expr_var
#line 452 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 2034 "frontend/parser.cpp"
    break;

  case 147: // expr_var: expr_var "%" expr_int
#line 453 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 2040 "frontend/parser.cpp"
    break;

  case 148: // expr_var: expr_var "%" expr_float
#line 454 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 2046 "frontend/parser.cpp"
    break;

  case 149: // expr_var: expr_var "%" expr_var
#line 455 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 2052 "frontend/parser.cpp"
    break;

  case 150: // expr_var: expr_int "+" expr_var
#line 457 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2058 "frontend/parser.cpp"
    break;

  case 151: // expr_var: expr_float "+" expr_var
#line 458 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2064 "frontend/parser.cpp"
    break;

  case 152: // expr_var: expr_var "+" expr_int
#line 459 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2070 "frontend/parser.cpp"
    break;

  case 153: // expr_var: expr_var "+" expr_float
#line 460 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2076 "frontend/parser.cpp"
    break;

  case 154: // expr_var: expr_mat "+" expr_mat
#line 461 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2082 "frontend/parser.cpp"
    break;

  case 155: // expr_var: expr_var "+" expr_mat
#line 462 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2088 "frontend/parser.cpp"
    break;

  case 156: // expr_var: expr_mat "+" expr_var
#line 463 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2094 "frontend/parser.cpp"
    break;

  case 157: // expr_var: expr_var "+" expr_var
#line 464 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 2100 "frontend/parser.cpp"
    break;

  case 158: // expr_var: expr_int "-" expr_var
#line 466 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2106 "frontend/parser.cpp"
    break;

  case 159: // expr_var: expr_float "-" expr_var
#line 467 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2112 "frontend/parser.cpp"
    break;

  case 160: // expr_var: expr_var "-" expr_int
#line 468 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2118 "frontend/parser.cpp"
    break;

  case 161: // expr_var: expr_var "-" expr_float
#line 469 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2124 "frontend/parser.cpp"
    break;

  case 162: // expr_var: expr_var "-" expr_var
#line 470 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 2130 "frontend/parser.cpp"
    break;

  case 163: // expr_var: expr_int "<<" expr_var
#line 472 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2136 "frontend/parser.cpp"
    break;

  case 164: // expr_var: expr_var "<<" expr_int
#line 473 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2142 "frontend/parser.cpp"
    break;

  case 165: // expr_var: expr_var "<<" expr_var
#line 474 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 2148 "frontend/parser.cpp"
    break;

  case 166: // expr_var: expr_int ">>" expr_var
#line 476 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2154 "frontend/parser.cpp"
    break;

  case 167: // expr_var: expr_var ">>" expr_int
#line 477 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2160 "frontend/parser.cpp"
    break;

  case 168: // expr_var: expr_var ">>" expr_var
#line 478 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 2166 "frontend/parser.cpp"
    break;

  case 169: // expr_var: expr_int ">" expr_var
#line 480 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2172 "frontend/parser.cpp"
    break;

  case 170: // expr_var: expr_float ">" expr_var
#line 481 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2178 "frontend/parser.cpp"
    break;

  case 171: // expr_var: expr_str ">" expr_var
#line 482 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2184 "frontend/parser.cpp"
    break;

  case 172: // expr_var: expr_var ">" expr_int
#line 483 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2190 "frontend/parser.cpp"
    break;

  case 173: // expr_var: expr_var ">" expr_float
#line 484 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2196 "frontend/parser.cpp"
    break;

  case 174: // expr_var: expr_var ">" expr_str
#line 485 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2202 "frontend/parser.cpp"
    break;

  case 175: // expr_var: expr_var ">" expr_var
#line 486 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 2208 "frontend/parser.cpp"
    break;

  case 176: // expr_var: expr_int ">=" expr_var
#line 488 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2214 "frontend/parser.cpp"
    break;

  case 177: // expr_var: expr_float ">=" expr_var
#line 489 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2220 "frontend/parser.cpp"
    break;

  case 178: // expr_var: expr_str ">=" expr_var
#line 490 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2226 "frontend/parser.cpp"
    break;

  case 179: // expr_var: expr_var ">=" expr_int
#line 491 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2232 "frontend/parser.cpp"
    break;

  case 180: // expr_var: expr_var ">=" expr_float
#line 492 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2238 "frontend/parser.cpp"
    break;

  case 181: // expr_var: expr_var ">=" expr_str
#line 493 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2244 "frontend/parser.cpp"
    break;

  case 182: // expr_var: expr_var ">=" expr_var
#line 494 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 2250 "frontend/parser.cpp"
    break;

  case 183: // expr_var: expr_int "<" expr_var
#line 496 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2256 "frontend/parser.cpp"
    break;

  case 184: // expr_var: expr_float "<" expr_var
#line 497 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2262 "frontend/parser.cpp"
    break;

  case 185: // expr_var: expr_str "<" expr_var
#line 498 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2268 "frontend/parser.cpp"
    break;

  case 186: // expr_var: expr_var "<" expr_int
#line 499 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2274 "frontend/parser.cpp"
    break;

  case 187: // expr_var: expr_var "<" expr_float
#line 500 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2280 "frontend/parser.cpp"
    break;

  case 188: // expr_var: expr_var "<" expr_str
#line 501 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2286 "frontend/parser.cpp"
    break;

  case 189: // expr_var: expr_var "<" expr_var
#line 502 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2292 "frontend/parser.cpp"
    break;

  case 190: // expr_var: expr_int "<=" expr_var
#line 504 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2298 "frontend/parser.cpp"
    break;

  case 191: // expr_var: expr_float "<=" expr_var
#line 505 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2304 "frontend/parser.cpp"
    break;

  case 192: // expr_var: expr_str "<=" expr_var
#line 506 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2310 "frontend/parser.cpp"
    break;

  case 193: // expr_var: expr_var "<=" expr_int
#line 507 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2316 "frontend/parser.cpp"
    break;

  case 194: // expr_var: expr_var "<=" expr_float
#line 508 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2322 "frontend/parser.cpp"
    break;

  case 195: // expr_var: expr_var "<=" expr_str
#line 509 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2328 "frontend/parser.cpp"
    break;

  case 196: // expr_var: expr_var "<=" expr_var
#line 510 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2334 "frontend/parser.cpp"
    break;

  case 197: // expr_var: expr_int "==" expr_var
#line 512 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2340 "frontend/parser.cpp"
    break;

  case 198: // expr_var: expr_float "==" expr_var
#line 513 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2346 "frontend/parser.cpp"
    break;

  case 199: // expr_var: expr_str "==" expr_var
#line 514 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2352 "frontend/parser.cpp"
    break;

  case 200: // expr_var: expr_bool "==" expr_var
#line 515 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2358 "frontend/parser.cpp"
    break;

  case 201: // expr_var: expr_none "==" expr_var
#line 516 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2364 "frontend/parser.cpp"
    break;

  case 202: // expr_var: expr_struct "==" expr_struct
#line 517 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2370 "frontend/parser.cpp"
    break;

  case 203: // expr_var: expr_struct "==" expr_var
#line 518 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2376 "frontend/parser.cpp"
    break;

  case 204: // expr_var: expr_var "==" expr_int
#line 519 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2382 "frontend/parser.cpp"
    break;

  case 205: // expr_var: expr_var "==" expr_float
#line 520 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2388 "frontend/parser.cpp"
    break;

  case 206: // expr_var: expr_var "==" expr_str
#line 521 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2394 "frontend/parser.cpp"
    break;

  case 207: // expr_var: expr_var "==" expr_bool
#line 522 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2400 "frontend/parser.cpp"
    break;

  case 208: // expr_var: expr_var "==" expr_none
#line 523 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2406 "frontend/parser.cpp"
    break;

  case 209: // expr_var: expr_var "==" expr_struct
#line 524 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2412 "frontend/parser.cpp"
    break;

  case 210: // expr_var: expr_mat "==" expr_mat
#line 525 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2418 "frontend/parser.cpp"
    break;

  case 211: // expr_var: expr_var "==" expr_mat
#line 526 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2424 "frontend/parser.cpp"
    break;

  case 212: // expr_var: expr_mat "==" expr_var
#line 527 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2430 "frontend/parser.cpp"
    break;

  case 213: // expr_var: expr_var "==" expr_var
#line 528 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2436 "frontend/parser.cpp"
    break;

  case 214: // expr_var: expr_int "!=" expr_var
#line 530 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2442 "frontend/parser.cpp"
    break;

  case 215: // expr_var: expr_float "!=" expr_var
#line 531 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2448 "frontend/parser.cpp"
    break;

  case 216: // expr_var: expr_str "!=" expr_var
#line 532 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2454 "frontend/parser.cpp"
    break;

  case 217: // expr_var: expr_bool "!=" expr_var
#line 533 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2460 "frontend/parser.cpp"
    break;

  case 218: // expr_var: expr_none "!=" expr_var
#line 534 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2466 "frontend/parser.cpp"
    break;

  case 219: // expr_var: expr_struct "!=" expr_struct
#line 535 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2472 "frontend/parser.cpp"
    break;

  case 220: // expr_var: expr_struct "!=" expr_var
#line 536 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2478 "frontend/parser.cpp"
    break;

  case 221: // expr_var: expr_var "!=" expr_int
#line 537 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2484 "frontend/parser.cpp"
    break;

  case 222: // expr_var: expr_var "!=" expr_float
#line 538 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2490 "frontend/parser.cpp"
    break;

  case 223: // expr_var: expr_var "!=" expr_str
#line 539 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2496 "frontend/parser.cpp"
    break;

  case 224: // expr_var: expr_var "!=" expr_bool
#line 540 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2502 "frontend/parser.cpp"
    break;

  case 225: // expr_var: expr_var "!=" expr_none
#line 541 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2508 "frontend/parser.cpp"
    break;

  case 226: // expr_var: expr_var "!=" expr_struct
#line 542 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2514 "frontend/parser.cpp"
    break;

  case 227: // expr_var: expr_mat "!=" expr_mat
#line 543 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2520 "frontend/parser.cpp"
    break;

  case 228: // expr_var: expr_var "!=" expr_mat
#line 544 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2526 "frontend/parser.cpp"
    break;

  case 229: // expr_var: expr_mat "!=" expr_var
#line 545 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2532 "frontend/parser.cpp"
    break;

  case 230: // expr_var: expr_var "!=" expr_var
#line 546 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2538 "frontend/parser.cpp"
    break;

  case 231: // expr_var: expr_int "&" expr_var
#line 548 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2544 "frontend/parser.cpp"
    break;

  case 232: // expr_var: expr_var "&" expr_int
#line 549 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2550 "frontend/parser.cpp"
    break;

  case 233: // expr_var: expr_var "&" expr_var
#line 550 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2556 "frontend/parser.cpp"
    break;

  case 234: // expr_var: expr_int "^" expr_var
#line 552 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2562 "frontend/parser.cpp"
    break;

  case 235: // expr_var: expr_var "^" expr_int
#line 553 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2568 "frontend/parser.cpp"
    break;

  case 236: // expr_var: expr_var "^" expr_var
#line 554 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2574 "frontend/parser.cpp"
    break;

  case 237: // expr_var: expr_int "|" expr_var
#line 556 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2580 "frontend/parser.cpp"
    break;

  case 238: // expr_var: expr_var "|" expr_int
#line 557 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2586 "frontend/parser.cpp"
    break;

  case 239: // expr_var: expr_var "|" expr_var
#line 558 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2592 "frontend/parser.cpp"
    break;

  case 244: // expr_var: expr_none "in" expr_mat
#line 564 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2598 "frontend/parser.cpp"
    break;

  case 245: // expr_var: expr_struct "in" expr_mat
#line 565 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2604 "frontend/parser.cpp"
    break;

  case 246: // expr_var: expr_mat "in" expr_mat
#line 566 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2610 "frontend/parser.cpp"
    break;

  case 251: // expr_var: expr_none "in" expr_var
#line 571 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2616 "frontend/parser.cpp"
    break;

  case 252: // expr_var: expr_struct "in" expr_var
#line 572 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2622 "frontend/parser.cpp"
    break;

  case 253: // expr_var: expr_mat "in" expr_var
#line 573 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2628 "frontend/parser.cpp"
    break;

  case 254: // expr_var: expr_var "in" expr_str
#line 574 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2634 "frontend/parser.cpp"
    break;

  case 255: // expr_var: expr_var "in" expr_var
#line 575 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2640 "frontend/parser.cpp"
    break;

  case 256: // expr_var: expr_bool "and" expr_var
#line 577 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2646 "frontend/parser.cpp"
    break;

  case 257: // expr_var: expr_var "and" expr_bool
#line 578 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2652 "frontend/parser.cpp"
    break;

  case 258: // expr_var: expr_var "and" expr_var
#line 579 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2658 "frontend/parser.cpp"
    break;

  case 259: // expr_var: expr_bool "or" expr_var
#line 581 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2664 "frontend/parser.cpp"
    break;

  case 260: // expr_var: expr_var "or" expr_bool
#line 582 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2670 "frontend/parser.cpp"
    break;

  case 261: // expr_var: expr_var "or" expr_var
#line 583 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2676 "frontend/parser.cpp"
    break;

  case 262: // expr_var: "not" expr_var
#line 585 "frontend/parser.yy"
                         { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseUnaryPrefixExpr(yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LNOT)); }
#line 2682 "frontend/parser.cpp"
    break;

  case 263: // expr_var: "~" expr_var
#line 587 "frontend/parser.yy"
                         { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseUnaryPrefixExpr(yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BNOT)); }
#line 2688 "frontend/parser.cpp"
    break;

  case 264: // expr_var: expr_int "++" expr_var
#line 589 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2694 "frontend/parser.cpp"
    break;

  case 265: // expr_var: expr_float "++" expr_var
#line 590 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2700 "frontend/parser.cpp"
    break;

  case 266: // expr_var: expr_str "++" expr_var
#line 591 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2706 "frontend/parser.cpp"
    break;

  case 267: // expr_var: expr_bool "++" expr_var
#line 592 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2712 "frontend/parser.cpp"
    break;

  case 268: // expr_var: expr_none "++" expr_var
#line 593 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseNone(), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2718 "frontend/parser.cpp"
    break;

  case 269: // expr_var: expr_var "++" expr_int
#line 594 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2724 "frontend/parser.cpp"
    break;

  case 270: // expr_var: expr_var "++" expr_float
#line 595 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2730 "frontend/parser.cpp"
    break;

  case 271: // expr_var: expr_var "++" expr_str
#line 596 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2736 "frontend/parser.cpp"
    break;

  case 272: // expr_var: expr_var "++" expr_bool
#line 597 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2742 "frontend/parser.cpp"
    break;

  case 273: // expr_var: expr_var "++" expr_none
#line 598 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseNone(), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2748 "frontend/parser.cpp"
    break;

  case 274: // expr_var: expr_var "++" expr_var
#line 599 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2754 "frontend/parser.cpp"
    break;

  case 275: // matrix: "[" "]"
#line 603 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(std::vector<ptc::ir::Expr *>{}); }
#line 2760 "frontend/parser.cpp"
    break;

  case 276: // matrix: "[" matvals "]"
#line 604 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2766 "frontend/parser.cpp"
    break;

  case 277: // matrix: "[" "terminator (\\n or ;)" matvals "]"
#line 605 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2772 "frontend/parser.cpp"
    break;

  case 278: // matrix: "[" matvals "terminator (\\n or ;)" "]"
#line 606 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2778 "frontend/parser.cpp"
    break;

  case 279: // matrix: "[" "terminator (\\n or ;)" matvals "terminator (\\n or ;)" "]"
#line 607 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseMatrix(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2784 "frontend/parser.cpp"
    break;

  case 280: // matvals: expr
#line 610 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixValue(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2790 "frontend/parser.cpp"
    break;

  case 281: // matvals: matvals "," expr
#line 611 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2796 "frontend/parser.cpp"
    break;

  case 282: // matvals: matvals "," "terminator (\\n or ;)" expr
#line 612 "frontend/parser.yy"
                                 { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixValue(yystack_[3].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2802 "frontend/parser.cpp"
    break;

  case 283: // expr_mat: matrix
#line 616 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2808 "frontend/parser.cpp"
    break;

  case 284: // expr_mat: "(" matrix ")"
#line 617 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2814 "frontend/parser.cpp"
    break;

  case 285: // range: "(" range ")"
#line 619 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2820 "frontend/parser.cpp"
    break;

  case 286: // range: int_val ".." int_val
#line 620 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseRange(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2826 "frontend/parser.cpp"
    break;

  case 287: // range: int_val "," int_val ".." int_val
#line 621 "frontend/parser.yy"
                                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseRange(yystack_[4].value.as < ptc::ir::Expr * > (), yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2832 "frontend/parser.cpp"
    break;

  case 288: // int_val: expr_int
#line 623 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 2838 "frontend/parser.cpp"
    break;

  case 289: // int_val: expr_var
#line 624 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2844 "frontend/parser.cpp"
    break;

  case 302: // expr_none: "none"
#line 641 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseNone(); }
#line 2850 "frontend/parser.cpp"
    break;

  case 303: // expr_none: "(" "none" ")"
#line 642 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseNone(); }
#line 2856 "frontend/parser.cpp"
    break;

  case 304: // expr_struct: "identifier" struct_val
#line 646 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseStruct(scanner->sym_lookup(yystack_[1].value.as < std::string > (), false, true), yystack_[0].value.as < std::map<std::string, ptc::ir::Expr *>  > ()); }
#line 2862 "frontend/parser.cpp"
    break;

  case 305: // expr_struct: "external identifier" struct_val
#line 647 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseStruct(scanner->parseExtType(yystack_[1].value.as < std::string > (), false), yystack_[0].value.as < std::map<std::string, ptc::ir::Expr *>  > ()); }
#line 2868 "frontend/parser.cpp"
    break;

  case 306: // expr_struct: "(" expr_struct ")"
#line 648 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 2874 "frontend/parser.cpp"
    break;

  case 307: // struct_val: "{" "}"
#line 650 "frontend/parser.yy"
                                    { yylhs.value.as < std::map<std::string, ptc::ir::Expr *>  > () = std::map<std::string, ptc::ir::Expr*>{}; }
#line 2880 "frontend/parser.cpp"
    break;

  case 308: // struct_val: "{" struct_list "}"
#line 651 "frontend/parser.yy"
                                    { yylhs.value.as < std::map<std::string, ptc::ir::Expr *>  > () = yystack_[1].value.as < std::map<std::string, ptc::ir::Expr *>  > (); }
#line 2886 "frontend/parser.cpp"
    break;

  case 309: // struct_list: "." "identifier" "=" expr
#line 653 "frontend/parser.yy"
                                                { yylhs.value.as < std::map<std::string, ptc::ir::Expr *>  > () = scanner->parseStructVals(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2892 "frontend/parser.cpp"
    break;

  case 310: // struct_list: struct_list "," "." "identifier" "=" expr
#line 654 "frontend/parser.yy"
                                                { yylhs.value.as < std::map<std::string, ptc::ir::Expr *>  > () = scanner->parseStructVals(yystack_[5].value.as < std::map<std::string, ptc::ir::Expr *>  > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 2898 "frontend/parser.cpp"
    break;

  case 311: // expr_int: "int"
#line 658 "frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 2904 "frontend/parser.cpp"
    break;

  case 312: // expr_int: "-" expr_int
#line 659 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 2910 "frontend/parser.cpp"
    break;

  case 313: // expr_int: "(" expr_int ")"
#line 660 "frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 2916 "frontend/parser.cpp"
    break;

  case 314: // expr_int: "~" expr_int
#line 661 "frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 2922 "frontend/parser.cpp"
    break;

  case 315: // expr_int: expr_int "*" expr_int
#line 662 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 2928 "frontend/parser.cpp"
    break;

  case 316: // expr_int: expr_int "/" expr_int
#line 663 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 2934 "frontend/parser.cpp"
    break;

  case 317: // expr_int: expr_int "%" expr_int
#line 664 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 2940 "frontend/parser.cpp"
    break;

  case 318: // expr_int: expr_int "-" expr_int
#line 665 "frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 2946 "frontend/parser.cpp"
    break;

  case 319: // expr_int: expr_int "+" expr_int
#line 666 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 2952 "frontend/parser.cpp"
    break;

  case 320: // expr_int: expr_int "<<" expr_int
#line 667 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 2958 "frontend/parser.cpp"
    break;

  case 321: // expr_int: expr_int ">>" expr_int
#line 668 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 2964 "frontend/parser.cpp"
    break;

  case 322: // expr_int: expr_int "&" expr_int
#line 669 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 2970 "frontend/parser.cpp"
    break;

  case 323: // expr_int: expr_int "^" expr_int
#line 670 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 2976 "frontend/parser.cpp"
    break;

  case 324: // expr_int: expr_int "|" expr_int
#line 671 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 2982 "frontend/parser.cpp"
    break;

  case 325: // expr_float: "float"
#line 675 "frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 2988 "frontend/parser.cpp"
    break;

  case 326: // expr_float: "-" expr_float
#line 676 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 2994 "frontend/parser.cpp"
    break;

  case 327: // expr_float: "(" expr_float ")"
#line 677 "frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 3000 "frontend/parser.cpp"
    break;

  case 328: // expr_float: expr_float "**" expr_float
#line 678 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 3006 "frontend/parser.cpp"
    break;

  case 329: // expr_float: expr_float "**" expr_int
#line 679 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 3012 "frontend/parser.cpp"
    break;

  case 330: // expr_float: expr_int "**" expr_float
#line 680 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 3018 "frontend/parser.cpp"
    break;

  case 331: // expr_float: expr_float "*" expr_float
#line 681 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 3024 "frontend/parser.cpp"
    break;

  case 332: // expr_float: expr_float "*" expr_int
#line 682 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 3030 "frontend/parser.cpp"
    break;

  case 333: // expr_float: expr_int "*" expr_float
#line 683 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 3036 "frontend/parser.cpp"
    break;

  case 334: // expr_float: expr_float "/" expr_float
#line 684 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 3042 "frontend/parser.cpp"
    break;

  case 335: // expr_float: expr_float "/" expr_int
#line 685 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 3048 "frontend/parser.cpp"
    break;

  case 336: // expr_float: expr_int "/" expr_float
#line 686 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 3054 "frontend/parser.cpp"
    break;

  case 337: // expr_float: expr_float "%" expr_float
#line 687 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 3060 "frontend/parser.cpp"
    break;

  case 338: // expr_float: expr_float "%" expr_int
#line 688 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 3066 "frontend/parser.cpp"
    break;

  case 339: // expr_float: expr_int "%" expr_float
#line 689 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 3072 "frontend/parser.cpp"
    break;

  case 340: // expr_float: expr_float "-" expr_float
#line 690 "frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 3078 "frontend/parser.cpp"
    break;

  case 341: // expr_float: expr_float "-" expr_int
#line 691 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 3084 "frontend/parser.cpp"
    break;

  case 342: // expr_float: expr_int "-" expr_float
#line 692 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 3090 "frontend/parser.cpp"
    break;

  case 343: // expr_float: expr_float "+" expr_float
#line 693 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 3096 "frontend/parser.cpp"
    break;

  case 344: // expr_float: expr_float "+" expr_int
#line 694 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 3102 "frontend/parser.cpp"
    break;

  case 345: // expr_float: expr_int "+" expr_float
#line 695 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 3108 "frontend/parser.cpp"
    break;

  case 346: // expr_str: "string"
#line 699 "frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3114 "frontend/parser.cpp"
    break;

  case 347: // expr_str: "(" expr_str ")"
#line 700 "frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 3120 "frontend/parser.cpp"
    break;

  case 348: // expr_str: expr_str "++" expr_str
#line 701 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 3126 "frontend/parser.cpp"
    break;

  case 349: // expr_str: expr_str "++" expr_int
#line 702 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 3132 "frontend/parser.cpp"
    break;

  case 350: // expr_str: expr_str "++" expr_float
#line 703 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 3138 "frontend/parser.cpp"
    break;

  case 351: // expr_str: expr_str "++" expr_bool
#line 704 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3144 "frontend/parser.cpp"
    break;

  case 352: // expr_str: expr_str "++" expr_none
#line 705 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 3150 "frontend/parser.cpp"
    break;

  case 353: // expr_str: expr_int "++" expr_str
#line 706 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 3156 "frontend/parser.cpp"
    break;

  case 354: // expr_str: expr_int "++" expr_int
#line 707 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 3162 "frontend/parser.cpp"
    break;

  case 355: // expr_str: expr_int "++" expr_float
#line 708 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 3168 "frontend/parser.cpp"
    break;

  case 356: // expr_str: expr_int "++" expr_bool
#line 709 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3174 "frontend/parser.cpp"
    break;

  case 357: // expr_str: expr_int "++" expr_none
#line 710 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 3180 "frontend/parser.cpp"
    break;

  case 358: // expr_str: expr_float "++" expr_str
#line 711 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 3186 "frontend/parser.cpp"
    break;

  case 359: // expr_str: expr_float "++" expr_int
#line 712 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 3192 "frontend/parser.cpp"
    break;

  case 360: // expr_str: expr_float "++" expr_float
#line 713 "frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 3198 "frontend/parser.cpp"
    break;

  case 361: // expr_str: expr_float "++" expr_bool
#line 714 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3204 "frontend/parser.cpp"
    break;

  case 362: // expr_str: expr_float "++" expr_none
#line 715 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 3210 "frontend/parser.cpp"
    break;

  case 363: // expr_str: expr_bool "++" expr_str
#line 716 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 3216 "frontend/parser.cpp"
    break;

  case 364: // expr_str: expr_bool "++" expr_int
#line 717 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 3222 "frontend/parser.cpp"
    break;

  case 365: // expr_str: expr_bool "++" expr_float
#line 718 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 3228 "frontend/parser.cpp"
    break;

  case 366: // expr_str: expr_bool "++" expr_bool
#line 719 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3234 "frontend/parser.cpp"
    break;

  case 367: // expr_str: expr_bool "++" expr_none
#line 720 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 3240 "frontend/parser.cpp"
    break;

  case 368: // expr_str: expr_none "++" expr_str
#line 721 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 3246 "frontend/parser.cpp"
    break;

  case 369: // expr_str: expr_none "++" expr_int
#line 722 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 3252 "frontend/parser.cpp"
    break;

  case 370: // expr_str: expr_none "++" expr_float
#line 723 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 3258 "frontend/parser.cpp"
    break;

  case 371: // expr_str: expr_none "++" expr_bool
#line 724 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 3264 "frontend/parser.cpp"
    break;

  case 372: // expr_str: expr_none "++" expr_none
#line 725 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 3270 "frontend/parser.cpp"
    break;

  case 373: // expr_bool: "bool"
#line 729 "frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 3276 "frontend/parser.cpp"
    break;

  case 374: // expr_bool: "(" expr_bool ")"
#line 730 "frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 3282 "frontend/parser.cpp"
    break;

  case 375: // expr_bool: "not" expr_bool
#line 731 "frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 3288 "frontend/parser.cpp"
    break;

  case 376: // expr_bool: expr_bool "or" expr_bool
#line 732 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 3294 "frontend/parser.cpp"
    break;

  case 377: // expr_bool: expr_bool "and" expr_bool
#line 733 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 3300 "frontend/parser.cpp"
    break;

  case 378: // expr_bool: expr_bool "==" expr_bool
#line 735 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 3306 "frontend/parser.cpp"
    break;

  case 379: // expr_bool: expr_int "==" expr_int
#line 736 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 3312 "frontend/parser.cpp"
    break;

  case 380: // expr_bool: expr_int "==" expr_float
#line 737 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 3318 "frontend/parser.cpp"
    break;

  case 381: // expr_bool: expr_float "==" expr_float
#line 738 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 3324 "frontend/parser.cpp"
    break;

  case 382: // expr_bool: expr_float "==" expr_int
#line 739 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 3330 "frontend/parser.cpp"
    break;

  case 383: // expr_bool: expr_str "==" expr_str
#line 740 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 3336 "frontend/parser.cpp"
    break;

  case 384: // expr_bool: expr_none "==" expr_none
#line 741 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 3342 "frontend/parser.cpp"
    break;

  case 385: // expr_bool: expr_bool "!=" expr_bool
#line 743 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 3348 "frontend/parser.cpp"
    break;

  case 386: // expr_bool: expr_int "!=" expr_int
#line 744 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 3354 "frontend/parser.cpp"
    break;

  case 387: // expr_bool: expr_int "!=" expr_float
#line 745 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 3360 "frontend/parser.cpp"
    break;

  case 388: // expr_bool: expr_float "!=" expr_float
#line 746 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 3366 "frontend/parser.cpp"
    break;

  case 389: // expr_bool: expr_float "!=" expr_int
#line 747 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 3372 "frontend/parser.cpp"
    break;

  case 390: // expr_bool: expr_str "!=" expr_str
#line 748 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 3378 "frontend/parser.cpp"
    break;

  case 391: // expr_bool: expr_none "!=" expr_none
#line 749 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 3384 "frontend/parser.cpp"
    break;

  case 392: // expr_bool: expr_int ">" expr_int
#line 751 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 3390 "frontend/parser.cpp"
    break;

  case 393: // expr_bool: expr_int ">" expr_float
#line 752 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 3396 "frontend/parser.cpp"
    break;

  case 394: // expr_bool: expr_float ">" expr_float
#line 753 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 3402 "frontend/parser.cpp"
    break;

  case 395: // expr_bool: expr_float ">" expr_int
#line 754 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 3408 "frontend/parser.cpp"
    break;

  case 396: // expr_bool: expr_str ">" expr_str
#line 755 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 3414 "frontend/parser.cpp"
    break;

  case 397: // expr_bool: expr_int "<" expr_int
#line 757 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 3420 "frontend/parser.cpp"
    break;

  case 398: // expr_bool: expr_int "<" expr_float
#line 758 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 3426 "frontend/parser.cpp"
    break;

  case 399: // expr_bool: expr_float "<" expr_float
#line 759 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 3432 "frontend/parser.cpp"
    break;

  case 400: // expr_bool: expr_float "<" expr_int
#line 760 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 3438 "frontend/parser.cpp"
    break;

  case 401: // expr_bool: expr_str "<" expr_str
#line 761 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 3444 "frontend/parser.cpp"
    break;

  case 402: // expr_bool: expr_int ">=" expr_int
#line 763 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 3450 "frontend/parser.cpp"
    break;

  case 403: // expr_bool: expr_int ">=" expr_float
#line 764 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 3456 "frontend/parser.cpp"
    break;

  case 404: // expr_bool: expr_float ">=" expr_float
#line 765 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 3462 "frontend/parser.cpp"
    break;

  case 405: // expr_bool: expr_float ">=" expr_int
#line 766 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 3468 "frontend/parser.cpp"
    break;

  case 406: // expr_bool: expr_str ">=" expr_str
#line 767 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 3474 "frontend/parser.cpp"
    break;

  case 407: // expr_bool: expr_int "<=" expr_int
#line 769 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 3480 "frontend/parser.cpp"
    break;

  case 408: // expr_bool: expr_int "<=" expr_float
#line 770 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 3486 "frontend/parser.cpp"
    break;

  case 409: // expr_bool: expr_float "<=" expr_float
#line 771 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 3492 "frontend/parser.cpp"
    break;

  case 410: // expr_bool: expr_float "<=" expr_int
#line 772 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 3498 "frontend/parser.cpp"
    break;

  case 411: // expr_bool: expr_str "<=" expr_str
#line 773 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 3504 "frontend/parser.cpp"
    break;

  case 412: // expr_bool: expr_str "in" expr_str
#line 775 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[0].value.as < std::string > ().find(yystack_[2].value.as < std::string > ()) != std::string::npos; }
#line 3510 "frontend/parser.cpp"
    break;

  case 419: // mattype: "identifier" matsq
#line 789 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3516 "frontend/parser.cpp"
    break;

  case 420: // mattype: "'int'" matsq
#line 790 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(INT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3522 "frontend/parser.cpp"
    break;

  case 421: // mattype: "'float'" matsq
#line 791 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(FLOAT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3528 "frontend/parser.cpp"
    break;

  case 422: // mattype: "'string'" matsq
#line 792 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(STRING_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3534 "frontend/parser.cpp"
    break;

  case 423: // mattype: "'bool'" matsq
#line 793 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(BOOL_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3540 "frontend/parser.cpp"
    break;

  case 424: // mattype: "any" matsq
#line 794 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(ANY_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 3546 "frontend/parser.cpp"
    break;

  case 432: // matsq: "[" "]"
#line 803 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(scanner->parseInt(-1)); }
#line 3552 "frontend/parser.cpp"
    break;

  case 433: // matsq: "[" "]" matsq
#line 805 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), scanner->parseInt(-1)); }
#line 3558 "frontend/parser.cpp"
    break;

  case 434: // type: "'int'" "?"
#line 810 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, true, true); }
#line 3564 "frontend/parser.cpp"
    break;

  case 435: // type: "'float'" "?"
#line 811 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, true, true); }
#line 3570 "frontend/parser.cpp"
    break;

  case 436: // type: "'string'" "?"
#line 812 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, true, true); }
#line 3576 "frontend/parser.cpp"
    break;

  case 437: // type: "'bool'" "?"
#line 813 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, true, true); }
#line 3582 "frontend/parser.cpp"
    break;

  case 438: // type: "identifier" "?"
#line 814 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[1].value.as < std::string > (), true, true); }
#line 3588 "frontend/parser.cpp"
    break;

  case 441: // type: mattype "?"
#line 817 "frontend/parser.yy"
       { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 3594 "frontend/parser.cpp"
    break;

  case 442: // type: "'int'"
#line 818 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, false, true); }
#line 3600 "frontend/parser.cpp"
    break;

  case 443: // type: "'float'"
#line 819 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, false, true); }
#line 3606 "frontend/parser.cpp"
    break;

  case 444: // type: "'string'"
#line 820 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, false, true); }
#line 3612 "frontend/parser.cpp"
    break;

  case 445: // type: "'bool'"
#line 821 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, false, true); }
#line 3618 "frontend/parser.cpp"
    break;

  case 446: // type: "any"
#line 822 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(ANY_CSTR, false, true); }
#line 3624 "frontend/parser.cpp"
    break;

  case 447: // type: "identifier"
#line 823 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[0].value.as < std::string > (), false, true); }
#line 3630 "frontend/parser.cpp"
    break;

  case 448: // type: "external identifier"
#line 824 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExtType(yystack_[0].value.as < std::string > (), false); }
#line 3636 "frontend/parser.cpp"
    break;

  case 450: // type: mattype
#line 826 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 3642 "frontend/parser.cpp"
    break;


#line 3646 "frontend/parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -641;

  const short  Parser ::yytable_ninf_ = -449;

  const short
   Parser ::yypact_[] =
  {
    1986,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  1576,    20,
      33,  1723,  1723,   -44,    42,   -19,  -641,  -641,  -641,  -641,
    1723,  -641,  -641,     9,    23,    35,    37,    40,    13,    -1,
     366,   437,   119,   746,  -641,  -641,   246,   246,  -641,  -641,
     116,  -641,   122,  -641,  2298,  -641,   143,  -641,  -641,   246,
     246,   246,  1979,  2566,  -641,   811,   490,   624,  2858,  2930,
     897,   846,    49,    63,     1,   167,   363,   400,  2482,   174,
     811,   490,   503,  2805,  2101,  1014,   653,  1723,  -641,  -641,
      59,   636,   636,   460,  -641,  -641,  -641,  -641,   425,   624,
    2858,  2930,   897,  -641,   425,  -641,   846,   212,   251,  -641,
     276,  -641,  -641,   240,    42,  -641,    42,  -641,    42,  -641,
      42,  -641,   127,    71,  -641,   373,   492,   113,  1051,    42,
    -641,  -641,  -641,   885,  1264,  -641,  -641,  -641,  -641,  -641,
    2466,  -641,  -641,  -641,  -641,  -641,  1423,  1723,   362,  2390,
    -641,  -641,   325,  1723,  -641,  -641,  -641,  1723,  1723,  1723,
    1723,  1723,  1723,  1723,  1723,  1723,  1723,  1723,  1723,  1723,
    -641,  1239,   885,  1723,  1723,  1723,  1723,  1723,  1723,  1723,
    1723,  1723,  1723,  1497,  1723,  1723,  1723,  1723,  1723,  1723,
    1723,  1723,  1723,  1723,  1723,   -60,  -641,   885,  1723,  1723,
    1723,  1723,  -641,  1723,  1723,  1723,  1723,  1723,  1723,  1723,
    1723,  1723,  1723,  1723,  1723,  1723,  1723,  1723,  1723,  1723,
    1723,  1723,  1723,  1723,  1723,  1723,  1723,  1723,  1723,  1723,
    1723,  1723,  1723,  1723,  1723,  1723,  1723,  1723,  1723,  1723,
    1723,  1723,  1723,  1723,  1723,  1723,  1723,  1723,  1723,  1723,
    1723,  1723,  1723,  1723,  1723,  1723,  1723,  1723,    42,  -641,
    -641,   903,     4,   381,  -641,   885,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,   241,   382,  -641,    61,  2263,  1368,   460,
     460,  -641,   636,   636,   636,   636,   636,   636,   460,   460,
     460,   460,   460,   636,   636,   636,   636,   636,   636,  1723,
      42,   -19,  1723,  -641,  -641,  -641,  -641,   380,   384,  -641,
     388,    78,   331,   392,    43,   720,  1130,  2566,    84,  2858,
    -641,   337,    93,   348,   419,  -641,   123,   364,   419,  -641,
      19,   109,   390,     2,   435,  2466,  -641,  2099,   444,   436,
    -641,  2985,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,    83,  -641,   242,   501,   449,
     512,   782,   501,   512,   782,   375,   448,   451,   375,   448,
     451,   375,   448,   451,   375,   448,   451,  2596,   702,  2052,
    2965,   972,   549,  2656,   805,  2626,   626,  2686,   570,   403,
     419,  2301,  2941,  2716,  2882,  2746,  2906,  1410,   939,  1410,
     939,  2776,    30,  -641,  -641,  1579,   748,   372,  -641,  2776,
      30,  -641,  -641,  1579,   748,   372,  -641,   700,   674,  1181,
     463,   700,   674,  1181,   463,   700,   674,  1181,   463,   700,
     674,  1181,   463,  -641,  -641,   244,   501,   449,  2686,   631,
    2776,    30,  2776,    30,  2596,   702,  2052,  2965,   972,   549,
    2686,   631,  2776,  -641,  2776,  -641,  2686,   631,  2776,  -641,
    2776,  -641,   501,   512,   782,   501,   512,   782,   375,   448,
     451,   375,   448,   451,   375,   448,   451,   375,   451,  2596,
     702,  2052,  2965,   972,   549,  2686,   631,  2301,  2941,  2716,
    2882,  2746,  2906,  1410,   939,  1410,   939,  2776,  1579,   748,
    2776,  1579,   748,   700,   674,  1181,   700,   674,  1181,   700,
     674,  1181,   700,   674,  1181,   501,   512,   782,   501,   512,
     782,   375,   448,   451,   375,   448,   451,   375,   448,   451,
     375,   448,   451,  2596,   702,  2052,  2965,   972,   549,  2686,
     631,  2776,  1579,   748,  2776,  1579,   748,   700,   674,  1181,
     700,   674,  1181,   700,   674,  1181,   700,   674,  1181,   471,
    2596,   702,  2052,  2965,   972,   549,  2686,   631,   570,  2776,
     372,  2776,   372,   700,   463,   700,   463,   700,   463,   700,
     463,  2596,   702,  2052,  2965,   972,   549,  2656,   805,  2626,
     626,  2686,   631,  2776,  -641,  2776,  -641,  -641,  -641,   465,
     414,   943,   473,  -641,  -641,  1723,  -641,  2977,  -641,   460,
     460,   460,   460,   460,   886,   970,   886,   970,   468,   469,
     468,   469,   468,   469,  2995,   469,  1054,  1490,  1739,   618,
     618,   886,   970,   886,   970,   468,   469,   468,   469,   468,
     469,   468,   469,  -641,  -641,  -641,  -641,   409,   409,  -641,
     416,   480,   499,     3,  -641,  1641,   378,   428,   484,   528,
       5,  -641,  1303,   269,  -641,  1212,   466,  -641,   500,  -641,
    -641,  -641,  1848,  1848,  1848,  -641,  2298,  2191,   539,  1723,
    2298,  -641,  1723,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
     378,   546,  -641,  -641,   569,   569,  -641,  -641,  -641,   544,
    -641,   524,  -641,   409,   530,  -641,  -641,  -641,  1042,   378,
    -641,  -641,   572,  -641,  1339,  -641,  1460,   361,  1723,   513,
    1935,   612,  2536,   619,   211,  2834,   621,   633,   643,   651,
    -641,   664,  -641,   667,   634,  -641,  -641,   378,  -641,  1723,
    -641,  1723,   620,     6,  -641,  -641,  -641,   687,  -641,   688,
    -641,  1541,  -641,   658,  2482,   697,  2805,  2298,  2298,  1723,
    1723,  2298,  2298,  2298,  2298,  -641,  -641,  -641,  -641,  2298,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,   696,  1723,
    -641,  -641,  -641,  -641,   671,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  1723,  -641
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     9,   311,   325,   346,   373,   302,     0,     0,
       0,     0,     0,     0,   446,     0,    52,    44,    46,    48,
      36,    33,    34,     0,   442,   443,   444,   445,     0,     0,
     103,   104,     0,     0,     4,    10,     0,     0,    35,    15,
       0,    17,     0,    18,     0,    16,     0,    19,    20,     0,
       0,     0,     0,    96,   283,    95,    97,    98,    99,   100,
     101,   102,   449,   450,     0,   302,   103,   104,     0,   283,
       0,     0,     0,     0,     0,     0,     0,     0,   275,   280,
       0,     0,     0,     0,   105,   106,   312,   326,   262,     0,
       0,     0,     0,   375,   263,   314,     0,     0,     0,   424,
      31,    30,    37,     0,   434,   420,   435,   421,   436,   422,
     437,   423,     0,     0,    68,     0,     0,     0,     0,   438,
     125,   304,   419,     0,     0,   439,   126,   305,     1,     3,
       0,     5,     8,     7,    14,    21,     0,     0,     0,     0,
      28,    29,     0,     0,    12,    13,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   127,     0,     0,     0,
       0,     0,   124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   440,   425,
     441,     0,    74,     0,   303,     0,   107,   284,   306,   313,
     327,   347,   374,     0,     0,   276,     0,     0,     0,     0,
       0,   314,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     432,     0,     0,   427,   428,   429,   430,     0,     0,   416,
       0,   447,   448,     0,   417,     0,     0,   289,     0,   288,
     307,     0,     0,   115,   121,   426,     0,   116,   122,     6,
     447,   448,     0,     0,     0,     0,    23,     0,     0,     0,
      92,    91,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,   108,     0,    93,     0,   157,   155,
     152,   153,   162,   160,   161,   139,   137,   138,   144,   142,
     143,   149,   147,   148,   132,   134,   131,   274,   273,   269,
     270,   271,   272,   258,   257,   261,   260,   255,   254,   117,
     123,   233,   232,   239,   238,   236,   235,   165,   164,   168,
     167,   213,   211,   208,   209,   204,   205,   206,   207,   230,
     228,   225,   226,   221,   222,   223,   224,   175,   172,   173,
     174,   189,   186,   187,   188,   182,   179,   180,   181,   196,
     193,   194,   195,   128,   129,     0,   156,   154,   253,   246,
     212,   210,   229,   227,   268,   372,   369,   370,   368,   371,
     251,   244,   201,   384,   218,   391,   252,   245,   203,   202,
     220,   219,   150,   319,   345,   158,   318,   342,   135,   315,
     333,   140,   316,   336,   145,   317,   339,   133,   330,   264,
     357,   354,   355,   353,   356,   247,   240,   231,   322,   237,
     324,   234,   323,   163,   320,   166,   321,   197,   379,   380,
     214,   386,   387,   169,   392,   393,   183,   397,   398,   176,
     402,   403,   190,   407,   408,   151,   344,   343,   159,   341,
     340,   136,   332,   331,   141,   335,   334,   146,   338,   337,
     130,   329,   328,   265,   362,   359,   360,   358,   361,   248,
     241,   198,   382,   381,   215,   389,   388,   170,   395,   394,
     184,   400,   399,   177,   405,   404,   191,   410,   409,     0,
     266,   352,   349,   350,   348,   351,   249,   242,   412,   199,
     383,   216,   390,   171,   396,   185,   401,   178,   406,   192,
     411,   267,   367,   364,   365,   363,   366,   256,   377,   259,
     376,   250,   243,   200,   378,   217,   385,   431,   414,     0,
       0,     0,     0,   277,   278,     0,   281,     0,   312,     0,
       0,     0,     0,     0,   319,   345,   318,   342,   315,   333,
     316,   336,   317,   339,     0,   330,   322,   324,   323,   320,
     321,   344,   343,   341,   340,   332,   331,   335,   334,   338,
     337,   329,   328,    78,   433,    32,    77,     0,    57,    54,
       0,     0,     0,     0,   415,     0,     0,     0,    73,     0,
       0,   290,     0,     0,   112,     0,     0,   308,     0,   118,
     113,   119,     0,     0,     0,    74,     0,     0,    24,     0,
       0,   109,     0,   114,   120,   111,   110,   413,    76,    75,
       0,     0,   279,   282,   319,   318,   315,   316,   317,     0,
      58,     0,    55,    59,    61,   418,    66,    71,     0,     0,
      69,   294,     0,   292,     0,   291,     0,     0,     0,     0,
       0,     0,   289,     0,     0,   288,     0,     0,     0,     0,
      45,    25,    26,     0,    51,    94,    64,     0,    56,     0,
      60,     0,     0,     0,    67,   297,   296,     0,   295,     0,
     293,     0,   309,     0,   289,     0,   288,     0,     0,     0,
       0,     0,     0,     0,     0,    27,    47,    53,    49,     0,
      65,    63,    62,    72,    70,   300,   299,   298,     0,     0,
     285,    39,    42,   286,     0,    40,    43,    38,    41,    50,
     301,   310,     0,   287
  };

  const short
   Parser ::yypgoto_[] =
  {
    -641,  -641,   -85,   208,   -17,   112,  -640,  -631,  -641,   423,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -543,  -641,  -641,   661,  -641,   131,   592,
    -641,   582,  -641,   940,   125,    -7,   657,  1252,  -608,   262,
    1458,  1483,  1682,   -24,  -641,    -8,   396,   704,  1034,  -641,
    -246,  -641,    -5,   334
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    32,    33,   134,    34,   140,   141,   142,    36,   101,
      37,    38,    39,    40,    41,    42,    43,    44,    45,   758,
      46,   759,    47,   641,   642,    48,   115,   648,   649,    49,
      50,    51,   345,    52,    53,    54,    80,    70,   713,   714,
     186,    71,    89,   121,   312,    58,    91,    92,    96,    62,
     303,    63,   122,    64
  };

  const short
   Parser ::yytable_[] =
  {
      73,    69,    86,    90,    95,   589,   696,   127,   113,    99,
     251,   251,   251,   -68,   251,   251,   131,   423,   424,   105,
     107,   109,   111,    77,     3,     4,     5,     6,     7,     8,
      98,     9,    78,    97,    98,   720,    10,     3,     4,   724,
     726,   187,    81,   127,    11,   188,    98,   590,    98,    82,
      12,    98,   251,    98,   327,   717,   719,   249,   100,   734,
      98,   662,   264,    83,   595,     3,     4,     5,     6,     7,
       8,   265,     9,   267,    86,   271,   114,    10,   252,   665,
     694,   299,   700,   764,   645,    11,   103,   760,   119,    98,
     112,    12,   104,   671,   689,   690,   654,    66,    67,   293,
     266,   294,   745,   295,   106,   296,   108,   657,   309,   110,
      84,    85,    35,   319,   315,   309,   771,   772,   248,   128,
     775,   776,   777,   778,   672,   136,   655,   310,   779,    14,
     297,   137,   250,    68,   658,   660,    88,    94,    66,    67,
     298,    24,    25,    26,    27,    35,   300,   119,   301,   302,
     730,   663,   143,   311,   309,   350,   353,   356,   359,   362,
     365,   369,    90,    90,    90,   655,   382,   384,   386,   388,
     390,   395,   403,   408,   412,   416,   420,   254,   125,   309,
      90,    90,    90,    90,   257,   436,    90,    90,    90,    90,
      90,    90,   453,   456,   459,   462,   465,    90,   471,    90,
     478,   480,   482,   484,   486,   488,   491,   494,   497,   500,
     503,   506,   509,   512,   515,   518,   521,   525,    90,   532,
     535,   538,   541,   544,   547,   309,   552,    90,    90,    90,
      90,    90,    90,    90,   573,    90,    90,    90,    90,    90,
     667,   307,    35,   587,   592,   135,   132,   309,   307,   133,
     749,    35,   750,   593,   673,   289,   675,   144,   145,   146,
     160,   597,   598,   290,   604,   606,   608,   610,   612,   614,
     616,   617,   618,   619,   620,   621,   623,   625,   627,   629,
     631,   703,   266,   292,   655,   634,   655,   307,   348,   352,
     355,   358,   361,   364,   367,   373,   375,   377,   309,   381,
     383,   385,   387,   389,   391,   399,   407,   411,   415,   419,
     131,   704,   307,   426,   428,   430,   432,   291,   434,   440,
     442,   444,   446,   448,   450,   452,   455,   458,   461,   464,
     467,   469,   475,   477,   479,   481,   483,   485,   487,   490,
     493,   496,   499,   502,   505,   508,   511,   514,   517,   520,
     523,   529,   531,   534,   537,   540,   543,   546,   307,   550,
     556,   559,   561,   563,   565,   567,   569,   571,   577,   579,
     581,   583,   585,   740,   255,   325,   117,   116,   308,   117,
     307,   138,   305,   233,   161,   316,   162,   638,   328,   118,
     591,   139,   118,   637,   594,   168,    59,   113,   639,   695,
     125,   173,   644,   741,    74,    59,    87,   238,   239,   240,
     241,   123,   638,   117,   656,   185,    59,   659,     3,     4,
       5,     6,     7,     8,   347,     9,   124,   117,   251,    59,
      10,   307,   664,   661,   161,   119,   162,    35,    11,    35,
      59,   640,    14,  -447,    12,   666,   670,   304,   123,   425,
     117,   173,   314,   669,    24,    25,    26,    27,   318,   300,
     187,   301,   302,   124,     3,   185,   640,    14,   205,   269,
     323,   224,   674,    59,   233,   677,   270,   268,    87,    24,
      25,    26,    27,   676,   300,   682,   301,   302,   277,   288,
      83,    66,    67,   691,   692,   549,     3,     4,     5,     6,
       7,     8,   693,     9,   290,   697,   125,   380,    10,   708,
     161,   193,   162,   258,  -448,   194,    11,   308,   165,   166,
     167,   168,    12,   195,   196,   698,    59,   173,   197,   202,
     203,   204,   205,    59,   306,    59,   198,   199,   699,    59,
     709,   185,   722,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,   727,    59,   728,   351,
     354,   357,   360,   363,   366,   370,   679,   729,   653,    66,
      67,   243,   244,   731,   245,   396,   404,   409,   413,   417,
     421,   233,   246,   247,   735,   304,   601,   602,   603,   437,
     743,   684,   685,   686,   687,   688,   454,   457,   460,   463,
     466,   468,   472,   236,   237,   238,   239,   240,   241,   489,
     492,   495,   498,   501,   504,   507,   510,   513,   516,   519,
     522,   526,   747,   533,   536,   539,   542,   545,   548,   748,
     553,   751,   643,   599,   600,   601,   602,   603,   574,   650,
       3,     4,   187,   752,   309,    81,   188,   309,   243,   197,
     131,   245,    82,   753,   715,   715,   715,   198,   199,   246,
     247,   754,    59,   262,   190,   191,    83,   755,   605,   607,
     609,   611,   613,   615,   242,   243,   244,   756,   245,   622,
     624,   626,   628,   630,   632,    59,   246,   247,    59,   200,
     201,   202,   203,   204,   205,   757,   309,   763,   309,   765,
     766,   769,   746,    69,    60,   211,   212,   770,   780,   161,
     782,   162,    75,    60,   635,   163,   164,   165,   166,   167,
     168,    59,   681,    59,    60,   253,   173,   194,   322,   330,
     646,   177,   178,   309,   263,   195,   196,    60,     0,     0,
     185,   309,   309,     0,     0,     0,   129,   130,    60,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,   647,
       0,     0,    10,   219,   220,   221,   222,   223,   224,     0,
      11,     0,     0,     0,   309,     0,    12,   307,    14,    35,
     307,    60,     0,   229,   230,   231,   232,   712,   712,   712,
      24,    25,    26,    27,     0,   300,     0,   301,   302,   221,
     222,   223,   224,    13,    14,    15,    16,     0,    17,    18,
      19,    20,    21,    22,    23,     0,    24,    25,    26,    27,
      28,    29,   187,    30,    31,     0,   188,     0,     0,   307,
     245,   307,     0,     0,    60,   744,   189,     0,   246,   247,
       0,    60,     0,    60,   190,   191,     0,    60,     0,     0,
       0,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,     0,    60,   307,   242,   243,   244,
       0,   245,     0,   371,   307,   307,   378,     0,     0,   246,
     247,     0,     0,   397,   405,   410,   414,   418,   422,     3,
       4,     5,     6,     7,     8,     0,     9,   438,     0,     0,
       0,    10,     0,   274,   275,   276,   277,   307,   233,    11,
     473,     0,     0,   588,   702,    12,     0,   707,   234,     0,
       0,     0,   235,     0,     0,   650,     0,   306,     0,   527,
     236,   237,   238,   239,   240,   241,     0,     0,   554,   558,
     560,   562,   564,   566,   568,   570,   575,     0,     0,    79,
       0,     0,     0,   680,   200,   201,   202,   203,   204,   205,
     102,    14,    66,    67,     0,     0,   737,     0,   739,     0,
      60,   643,   643,    24,    25,    26,    27,     0,   300,   304,
     301,   302,   647,   233,     0,     0,    59,   285,   286,   287,
     288,    59,     0,    60,     0,     0,    60,   235,     0,     0,
       0,    14,     0,   768,     0,   236,   237,   238,   239,   240,
     241,   773,   774,    24,    25,    26,    27,    79,   300,     0,
     301,   302,     0,     0,   261,   233,     0,   643,     0,    60,
       0,    60,   733,     0,    61,   234,     0,     0,     0,   235,
       0,     0,    76,    61,   783,    93,     0,   236,   237,   238,
     239,   240,   241,     0,    61,     0,     0,     0,    59,    59,
      59,     0,    59,    59,     0,    59,    59,    61,    59,   599,
     600,   601,   602,   603,     0,     0,     0,   324,    61,     0,
       0,   732,     0,   329,     0,   281,   282,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
      14,   346,     0,     0,    59,     0,    74,     0,     0,    14,
       0,    61,    24,    25,    26,    27,     0,   300,     0,   301,
     302,    24,    25,    26,    27,    59,   300,    59,   301,   313,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     9,   651,    59,    59,     0,    10,    59,    59,    59,
      59,     0,     0,     0,    11,    59,     0,     0,     0,     0,
      12,     0,     0,     0,    61,    59,     0,     0,     0,     0,
       0,    61,   652,    61,     0,     0,     0,    61,     0,     0,
       0,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,     0,    61,   219,   220,   221,   222,
     223,   224,     0,   372,   374,   376,   596,    66,    67,     0,
       0,     0,     0,   398,   406,     0,     3,     4,     5,     6,
       7,     8,     0,     9,   705,     0,     0,   439,    10,   633,
       0,     0,   636,     0,     0,     0,    11,     0,     0,     0,
     474,     0,    12,     3,     4,     5,     6,     7,     8,   344,
       9,     0,    55,     0,   706,    10,     0,     0,     0,   528,
       0,    55,     0,    11,     0,     0,     0,     0,   555,    12,
       0,     0,    55,     0,     0,     0,   576,   578,   580,     0,
     584,   586,     0,     0,     0,    55,     0,     0,     0,    66,
      67,     0,     0,     0,    60,     0,    55,     0,     0,    60,
      61,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     0,     9,   701,    66,    67,     0,    10,
       0,     0,    14,    61,     0,     0,    61,    11,     0,    55,
       0,     0,     0,    12,    24,    25,    26,    27,     0,   300,
       0,   301,   317,     3,     4,     5,     6,     7,     8,     0,
       9,   736,     0,     0,     0,    10,     0,     0,     0,    61,
       0,    61,     0,    11,     0,     0,    60,    60,    60,    12,
      60,    60,     0,    60,    60,     0,    60,     0,   260,     0,
      66,    67,    55,   283,   284,   285,   286,   287,   288,    55,
       0,    55,     0,     0,     0,    55,     0,     0,     0,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    60,    55,    75,   349,    66,    67,     0,   161,
       0,   162,     0,     0,     0,   163,   164,   165,   166,   167,
     168,   392,   400,    60,     0,    60,   173,     0,     0,     0,
     427,   429,   431,   433,     0,     0,   441,     0,     0,   447,
     185,    60,    60,     0,     0,    60,    60,    60,    60,   476,
       0,     0,     0,    60,     3,     4,     5,     6,     7,     8,
       0,     9,   738,    60,     0,     0,    10,     0,   530,     0,
       0,    14,     0,    56,    11,     0,     0,   557,   120,   126,
      12,     0,    56,    24,    25,    26,    27,   582,   300,     0,
     320,   321,     0,    56,     0,   599,   600,   601,   602,   603,
       0,     0,     0,   192,     0,     0,    56,   278,    55,   280,
       0,   281,   282,     0,   120,   126,     0,    56,   192,     0,
     678,     0,     0,     0,     0,   683,     0,    66,    67,     0,
       0,    55,     0,     0,    55,     3,     4,     5,     6,     7,
       8,     0,     9,   767,     0,    14,     0,    10,     0,     0,
      56,     0,     0,     0,     0,    11,     0,    24,    25,    26,
      27,    12,   300,     0,   301,   379,     0,    55,     0,    55,
       3,     4,     5,     6,    65,     8,     0,     9,     0,     0,
       0,     0,    10,     0,   200,   201,   202,   203,   204,   205,
      11,     0,   711,   716,   718,     0,    12,     0,     0,   723,
     211,   212,   725,    56,   215,   216,   217,   218,    66,    67,
      56,     0,    56,     0,    61,     0,    56,     0,     0,    61,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,     0,    56,     0,     0,     0,   742,     0,
       0,     0,   368,    66,    67,     0,     0,     0,     0,     0,
       0,     0,   393,   401,     0,     0,     0,     0,     0,   761,
       0,   762,     0,     0,     0,     0,   435,     0,   443,   445,
       0,     0,    57,     0,     0,     0,     0,     0,     0,   470,
      72,    57,     0,     0,     0,     0,    61,    61,    61,    14,
      61,    61,    57,    61,    61,     0,    61,     0,   524,   781,
       0,    24,    25,    26,    27,    57,   300,   551,   301,   302,
       0,     0,     0,     0,     0,   572,    57,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,     0,    10,
       0,     0,    61,     0,    76,     0,     0,    11,     0,    56,
       0,     0,     0,    12,   599,   600,   601,   602,   603,    57,
       0,     0,     0,    61,     0,    61,   278,     0,     0,     0,
     281,   282,    56,     0,     0,    56,     0,     0,     0,     0,
       0,    61,    61,     0,     0,    61,    61,    61,    61,     0,
       0,     0,     0,    61,     0,     0,     0,     0,     0,     0,
      66,    67,     0,    61,     0,     0,     0,   192,    56,     0,
      56,     0,    57,     0,     0,     0,     0,     0,     0,    57,
       0,    57,     0,     0,     0,    57,     0,     0,     0,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    55,    57,     0,     0,     0,    55,     0,     0,
     192,     0,     3,     4,     5,     6,     7,   710,   192,     9,
       0,   394,   402,     0,    10,     0,     0,     0,     0,     0,
       0,     0,    11,     0,     0,     0,     0,     0,    12,     0,
     449,   451,     0,     0,     0,   192,     0,   192,     0,   192,
       0,   192,     0,     0,     0,     0,     0,     0,     0,   192,
       0,     0,     0,     0,     0,   192,     0,     0,     0,     0,
       0,     0,     0,     0,    55,    55,    55,     0,    55,    55,
       0,    55,    55,     0,    55,    66,    67,     0,     0,     0,
       0,     0,     0,     0,   192,     0,     0,     0,     0,     3,
       4,     5,     6,    65,   710,     0,     9,     0,    57,     0,
       0,    10,     0,     0,     0,     0,     0,     0,     0,    11,
      55,     0,     0,     0,     0,    12,     0,     0,     0,     0,
       0,    57,     0,     0,    57,     0,     0,     0,     0,   132,
       0,    55,   133,    55,     0,     0,     1,     0,   192,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,    55,
      55,     0,    10,    55,    55,    55,    55,    57,     0,    57,
      11,    55,    66,    67,     0,   192,    12,     0,     0,     0,
       0,    55,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,     0,   158,   159,     0,     0,     0,     0,
     192,     0,     0,    13,    14,    15,    16,     0,    17,    18,
      19,    20,    21,    22,    23,     0,    24,    25,    26,    27,
      28,    29,     0,    30,    31,     0,     0,   200,   201,   202,
     203,   204,   205,    56,     0,     0,     0,   207,    56,   208,
     209,   210,     0,   211,   212,   213,   214,   215,   216,   217,
     218,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     130,     0,     2,     3,     4,     5,     6,     7,     8,     0,
       9,   260,     0,   668,     0,    10,   219,   220,   221,   222,
     223,   224,   225,    11,     0,     0,   226,     0,     0,    12,
       0,     0,     0,     0,   227,   228,   229,   230,   231,   232,
       0,     0,     0,     0,     0,    56,    56,    56,     0,    56,
      56,     0,    56,    56,     0,    56,    13,    14,    15,    16,
       0,    17,    18,    19,    20,    21,    22,    23,     0,    24,
      25,    26,    27,    28,    29,     0,    30,    31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    56,   130,     0,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,   721,     0,    10,     0,     0,
       0,     0,    56,     0,    56,    11,     0,     0,     0,     0,
       0,    12,     0,     0,     0,     0,     0,     0,     0,     0,
      56,    56,     0,     0,    56,    56,    56,    56,     0,     0,
       0,     0,    56,     0,     0,     0,     0,     0,    13,    14,
      15,    16,    56,    17,    18,    19,    20,    21,    22,    23,
       0,    24,    25,    26,    27,    28,    29,     0,    30,    31,
       0,     0,    57,   259,     0,     0,     0,    57,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,     0,
     278,   279,   280,     0,   281,   282,     0,     0,     0,     0,
       0,   138,     3,     4,     5,     6,     7,     8,     0,     9,
     161,   139,   162,     0,    10,     0,   163,   164,   165,   166,
     167,   168,    11,     0,     0,     0,     0,   173,    12,     0,
       0,     0,   177,   178,   179,   180,   181,   182,   183,   184,
       0,   185,     0,     0,    57,    57,    57,     0,    57,    57,
       0,    57,    57,     0,    57,    13,    14,    15,    16,     0,
      17,    18,    19,    20,    21,    22,    23,     0,    24,    25,
      26,    27,    28,    29,     0,    30,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      57,     0,    72,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,   326,     0,    10,     0,     0,     0,
       0,    57,     0,    57,    11,     0,     0,     0,     0,     0,
      12,     0,     0,     0,     0,     0,     0,     0,     0,    57,
      57,     0,     0,    57,    57,    57,    57,     0,     0,     0,
       0,    57,     0,     0,     0,     0,     0,    13,    14,    15,
      16,    57,    17,    18,    19,    20,    21,    22,    23,     0,
      24,    25,    26,    27,    28,    29,     0,    30,    31,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,     0,    10,     0,     0,     0,     0,     0,     0,     0,
      11,   161,   256,   162,     0,     0,    12,   163,   164,   165,
     166,   167,   168,   169,   170,   171,     0,   172,   173,   174,
     175,   176,     0,   177,   178,   179,   180,   181,   182,   183,
     184,     0,   185,    13,    14,    15,    16,     0,    17,    18,
      19,    20,    21,    22,    23,     0,    24,    25,    26,    27,
      28,    29,     0,    30,    31,   161,   -96,   162,     0,     0,
       0,   163,   164,   165,   166,   167,   168,   169,   170,   171,
       0,   172,   173,   174,   175,   176,     0,   177,   178,   179,
     180,   181,   182,   183,   184,   161,   185,   162,     0,     0,
       0,   163,   164,   165,   166,   167,   168,   169,   170,   171,
       0,   172,   173,   174,   175,   176,     0,   177,   178,   179,
     180,   181,   182,   183,   184,   161,   185,   162,     0,     0,
       0,   163,   164,   165,   166,   167,   168,     0,   170,   171,
       0,   172,   173,   174,   175,   176,     0,   177,   178,   179,
     180,   181,   182,   183,   184,   161,   185,   162,     0,     0,
       0,   163,   164,   165,   166,   167,   168,     0,   170,     0,
       0,   172,   173,   174,   175,   176,     0,   177,   178,   179,
     180,   181,   182,   183,   184,   161,   185,   162,     0,     0,
       0,   163,   164,   165,   166,   167,   168,     0,     0,     0,
       0,   172,   173,   174,   175,   176,     0,   177,   178,   179,
     180,   181,   182,   183,   184,   161,   185,   162,     0,     0,
       0,   163,   164,   165,   166,   167,   168,     0,     0,     0,
       0,     0,   173,   174,   175,   176,     0,   177,   178,   179,
     180,   181,   182,   183,   184,   161,   185,   162,     0,     0,
       0,   163,   164,   165,   166,   167,   168,     0,     0,     0,
       0,     0,   173,   174,     0,   176,     0,   177,   178,   179,
     180,   181,   182,   183,   184,   161,   185,   162,     0,     0,
       0,   163,   164,   165,   166,   167,   168,     0,     0,     0,
       0,     0,   173,   174,     0,     0,     0,   177,   178,   179,
     180,   181,   182,   183,   184,   161,   185,   162,     0,     0,
       0,   163,   164,   165,   166,   167,   168,     0,     0,     0,
       0,     0,   173,     0,     0,     0,     0,   177,   178,     0,
       0,   181,   182,   183,   184,   259,   185,     0,     0,     0,
     200,   201,   202,   203,   204,   205,   206,     0,     0,     0,
     207,     0,   208,   209,   210,     0,   211,   212,   213,   214,
     215,   216,   217,   218,   -99,     0,     0,     0,     0,   200,
     201,   202,   203,   204,   205,   206,     0,     0,     0,   207,
       0,   208,   209,   210,     0,   211,   212,   213,   214,   215,
     216,   217,   218,   200,   201,   202,   203,   204,   205,   206,
       0,     0,     0,   207,     0,   208,   209,   210,     0,   211,
     212,   213,   214,   215,   216,   217,   218,   200,   201,   202,
     203,   204,   205,     0,     0,     0,     0,     0,     0,   208,
       0,   210,     0,   211,   212,   213,   214,   215,   216,   217,
     218,   200,   201,   202,   203,   204,   205,     0,     0,     0,
       0,     0,     0,   208,     0,     0,     0,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,     0,     0,     0,   226,   200,   201,   202,   203,
     204,   205,     0,   227,   228,   229,   230,   231,   232,     0,
       0,     0,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,     0,   259,     0,     0,
     226,     0,   599,   600,   601,   602,   603,     0,   227,   228,
     229,   230,   231,   232,   278,   279,   280,     0,   281,   282,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,     0,   278,   279,   280,     0,   281,   282,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,     0,
     158,   159
  };

  const short
   Parser ::yycheck_[] =
  {
       8,     8,    10,    11,    12,   251,   646,    31,     9,    14,
       9,     9,     9,     9,     9,     9,    33,    77,    78,    24,
      25,    26,    27,     3,     4,     5,     6,     7,     8,     9,
      11,    11,    12,    77,    11,   666,    16,     4,     5,   670,
     680,    11,     9,    67,    24,    15,    11,    43,    11,    16,
      30,    11,     9,    11,   139,   663,   664,    62,    77,   699,
      11,    42,     3,    30,     3,     4,     5,     6,     7,     8,
       9,    12,    11,    81,    82,    83,    77,    16,    77,    77,
      77,    10,    77,    77,    41,    24,    77,   727,    69,    11,
      77,    30,    69,    10,   637,   638,    12,    77,    78,   104,
      41,   106,   710,   108,    69,   110,    69,    14,   116,    69,
      77,    78,     0,   130,   119,   123,   747,   748,    69,     0,
     751,   752,   753,   754,    41,     9,    42,    14,   759,    58,
       3,     9,    69,     8,    41,    12,    11,    12,    77,    78,
      13,    70,    71,    72,    73,    33,    75,    69,    77,    78,
     693,    42,     9,    40,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    42,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,    10,    69,   187,
     188,   189,   190,   191,    10,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     325,   116,   130,   248,     3,    37,     0,   255,   123,     3,
      39,   139,    41,    12,    12,    43,    12,    49,    50,    51,
      52,   269,   270,    12,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,    12,    41,    43,    42,   290,    42,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   306,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     327,    42,   187,   188,   189,   190,   191,    41,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,    12,    11,    13,    13,    11,   116,    13,
     255,     3,     9,    11,     9,   123,    11,     3,    63,    26,
       9,    13,    26,    13,    12,    20,     0,     9,    14,   645,
      69,    26,    10,    42,     8,     9,    10,    35,    36,    37,
      38,    11,     3,    13,    77,    40,    20,    69,     4,     5,
       6,     7,     8,     9,   162,    11,    26,    13,     9,    33,
      16,   306,    42,    69,     9,    69,    11,   325,    24,   327,
      44,    57,    58,    77,    30,    10,    10,   113,    11,   187,
      13,    26,   118,     9,    70,    71,    72,    73,   124,    75,
      11,    77,    78,    26,     4,    40,    57,    58,    20,     9,
     136,    20,    69,    77,    11,    10,    16,    81,    82,    70,
      71,    72,    73,    12,    75,    12,    77,    78,    20,    20,
      30,    77,    78,    77,    14,   233,     4,     5,     6,     7,
       8,     9,     3,    11,    12,    77,    69,   173,    16,    43,
       9,    21,    11,    10,    77,    25,    24,   255,    17,    18,
      19,    20,    30,    33,    34,    41,   130,    26,    25,    17,
      18,    19,    20,   137,    42,   139,    33,    34,    10,   143,
      40,    40,     3,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,    10,   161,    14,   163,
     164,   165,   166,   167,   168,   169,   590,    43,   306,    77,
      78,    22,    23,    43,    25,   179,   180,   181,   182,   183,
     184,    11,    33,    34,    12,   251,    17,    18,    19,   193,
      77,   599,   600,   601,   602,   603,   200,   201,   202,   203,
     204,   205,   206,    33,    34,    35,    36,    37,    38,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    10,   227,   228,   229,   230,   231,   232,    10,
     234,    10,   298,    15,    16,    17,    18,    19,   242,   305,
       4,     5,    11,    10,   652,     9,    15,   655,    22,    25,
     667,    25,    16,    10,   662,   663,   664,    33,    34,    33,
      34,    10,   266,    10,    33,    34,    30,     3,   272,   273,
     274,   275,   276,   277,    21,    22,    23,    10,    25,   283,
     284,   285,   286,   287,   288,   289,    33,    34,   292,    15,
      16,    17,    18,    19,    20,    61,   704,    77,   706,    12,
      12,    43,   710,   710,     0,    31,    32,    10,    12,     9,
      39,    11,     8,     9,   291,    15,    16,    17,    18,    19,
      20,   325,   591,   327,    20,    64,    26,    25,   136,   147,
      10,    31,    32,   741,    77,    33,    34,    33,    -1,    -1,
      40,   749,   750,    -1,    -1,    -1,     0,     1,    44,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    -1,    39,
      -1,    -1,    16,    15,    16,    17,    18,    19,    20,    -1,
      24,    -1,    -1,    -1,   782,    -1,    30,   652,    58,   667,
     655,    77,    -1,    35,    36,    37,    38,   662,   663,   664,
      70,    71,    72,    73,    -1,    75,    -1,    77,    78,    17,
      18,    19,    20,    57,    58,    59,    60,    -1,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    11,    77,    78,    -1,    15,    -1,    -1,   704,
      25,   706,    -1,    -1,   130,   710,    25,    -1,    33,    34,
      -1,   137,    -1,   139,    33,    34,    -1,   143,    -1,    -1,
      -1,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,    -1,   161,   741,    21,    22,    23,
      -1,    25,    -1,   169,   749,   750,   172,    -1,    -1,    33,
      34,    -1,    -1,   179,   180,   181,   182,   183,   184,     4,
       5,     6,     7,     8,     9,    -1,    11,   193,    -1,    -1,
      -1,    16,    -1,    17,    18,    19,    20,   782,    11,    24,
     206,    -1,    -1,    10,   652,    30,    -1,   655,    21,    -1,
      -1,    -1,    25,    -1,    -1,   591,    -1,    42,    -1,   225,
      33,    34,    35,    36,    37,    38,    -1,    -1,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,     9,
      -1,    -1,    -1,    10,    15,    16,    17,    18,    19,    20,
      20,    58,    77,    78,    -1,    -1,   704,    -1,   706,    -1,
     266,   637,   638,    70,    71,    72,    73,    -1,    75,   645,
      77,    78,    39,    11,    -1,    -1,   590,    17,    18,    19,
      20,   595,    -1,   289,    -1,    -1,   292,    25,    -1,    -1,
      -1,    58,    -1,   741,    -1,    33,    34,    35,    36,    37,
      38,   749,   750,    70,    71,    72,    73,    77,    75,    -1,
      77,    78,    -1,    -1,    10,    11,    -1,   693,    -1,   325,
      -1,   327,   698,    -1,     0,    21,    -1,    -1,    -1,    25,
      -1,    -1,     8,     9,   782,    11,    -1,    33,    34,    35,
      36,    37,    38,    -1,    20,    -1,    -1,    -1,   662,   663,
     664,    -1,   666,   667,    -1,   669,   670,    33,   672,    15,
      16,    17,    18,    19,    -1,    -1,    -1,   137,    44,    -1,
      -1,    39,    -1,   143,    -1,    31,    32,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
      58,   161,    -1,    -1,   708,    -1,   710,    -1,    -1,    58,
      -1,    77,    70,    71,    72,    73,    -1,    75,    -1,    77,
      78,    70,    71,    72,    73,   729,    75,   731,    77,    78,
      -1,    -1,    -1,    -1,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,   747,   748,    -1,    16,   751,   752,   753,
     754,    -1,    -1,    -1,    24,   759,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    -1,   130,   769,    -1,    -1,    -1,    -1,
      -1,   137,    42,   139,    -1,    -1,    -1,   143,    -1,    -1,
      -1,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,    -1,   161,    15,    16,    17,    18,
      19,    20,    -1,   169,   170,   171,   266,    77,    78,    -1,
      -1,    -1,    -1,   179,   180,    -1,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,   193,    16,   289,
      -1,    -1,   292,    -1,    -1,    -1,    24,    -1,    -1,    -1,
     206,    -1,    30,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,     0,    -1,    42,    16,    -1,    -1,    -1,   225,
      -1,     9,    -1,    24,    -1,    -1,    -1,    -1,   234,    30,
      -1,    -1,    20,    -1,    -1,    -1,   242,   243,   244,    -1,
     246,   247,    -1,    -1,    -1,    33,    -1,    -1,    -1,    77,
      78,    -1,    -1,    -1,   590,    -1,    44,    -1,    -1,   595,
     266,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    77,    78,    -1,    16,
      -1,    -1,    58,   289,    -1,    -1,   292,    24,    -1,    77,
      -1,    -1,    -1,    30,    70,    71,    72,    73,    -1,    75,
      -1,    77,    78,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,   325,
      -1,   327,    -1,    24,    -1,    -1,   662,   663,   664,    30,
     666,   667,    -1,   669,   670,    -1,   672,    -1,    10,    -1,
      77,    78,   130,    15,    16,    17,    18,    19,    20,   137,
      -1,   139,    -1,    -1,    -1,   143,    -1,    -1,    -1,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   708,   161,   710,   163,    77,    78,    -1,     9,
      -1,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,   179,   180,   729,    -1,   731,    26,    -1,    -1,    -1,
     188,   189,   190,   191,    -1,    -1,   194,    -1,    -1,   197,
      40,   747,   748,    -1,    -1,   751,   752,   753,   754,   207,
      -1,    -1,    -1,   759,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,   769,    -1,    -1,    16,    -1,   226,    -1,
      -1,    58,    -1,     0,    24,    -1,    -1,   235,    30,    31,
      30,    -1,     9,    70,    71,    72,    73,   245,    75,    -1,
      77,    78,    -1,    20,    -1,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    55,    -1,    -1,    33,    27,   266,    29,
      -1,    31,    32,    -1,    66,    67,    -1,    44,    70,    -1,
     590,    -1,    -1,    -1,    -1,   595,    -1,    77,    78,    -1,
      -1,   289,    -1,    -1,   292,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    -1,    58,    -1,    16,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    24,    -1,    70,    71,    72,
      73,    30,    75,    -1,    77,    78,    -1,   325,    -1,   327,
       4,     5,     6,     7,     8,     9,    -1,    11,    -1,    -1,
      -1,    -1,    16,    -1,    15,    16,    17,    18,    19,    20,
      24,    -1,   662,   663,   664,    -1,    30,    -1,    -1,   669,
      31,    32,   672,   130,    35,    36,    37,    38,    77,    78,
     137,    -1,   139,    -1,   590,    -1,   143,    -1,    -1,   595,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,    -1,   161,    -1,    -1,    -1,   708,    -1,
      -1,    -1,   169,    77,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   179,   180,    -1,    -1,    -1,    -1,    -1,   729,
      -1,   731,    -1,    -1,    -1,    -1,   193,    -1,   195,   196,
      -1,    -1,     0,    -1,    -1,    -1,    -1,    -1,    -1,   206,
       8,     9,    -1,    -1,    -1,    -1,   662,   663,   664,    58,
     666,   667,    20,   669,   670,    -1,   672,    -1,   225,   769,
      -1,    70,    71,    72,    73,    33,    75,   234,    77,    78,
      -1,    -1,    -1,    -1,    -1,   242,    44,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    -1,    -1,    -1,    16,
      -1,    -1,   708,    -1,   710,    -1,    -1,    24,    -1,   266,
      -1,    -1,    -1,    30,    15,    16,    17,    18,    19,    77,
      -1,    -1,    -1,   729,    -1,   731,    27,    -1,    -1,    -1,
      31,    32,   289,    -1,    -1,   292,    -1,    -1,    -1,    -1,
      -1,   747,   748,    -1,    -1,   751,   752,   753,   754,    -1,
      -1,    -1,    -1,   759,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    78,    -1,   769,    -1,    -1,    -1,   349,   325,    -1,
     327,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
      -1,   139,    -1,    -1,    -1,   143,    -1,    -1,    -1,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   590,   161,    -1,    -1,    -1,   595,    -1,    -1,
     392,    -1,     4,     5,     6,     7,     8,     9,   400,    11,
      -1,   179,   180,    -1,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,
     198,   199,    -1,    -1,    -1,   427,    -1,   429,    -1,   431,
      -1,   433,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   441,
      -1,    -1,    -1,    -1,    -1,   447,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   662,   663,   664,    -1,   666,   667,
      -1,   669,   670,    -1,   672,    77,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   476,    -1,    -1,    -1,    -1,     4,
       5,     6,     7,     8,     9,    -1,    11,    -1,   266,    -1,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
     708,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,   289,    -1,    -1,   292,    -1,    -1,    -1,    -1,     0,
      -1,   729,     3,   731,    -1,    -1,     0,    -1,   530,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    -1,   747,
     748,    -1,    16,   751,   752,   753,   754,   325,    -1,   327,
      24,   759,    77,    78,    -1,   557,    30,    -1,    -1,    -1,
      -1,   769,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    -1,    -1,    -1,    -1,
     582,    -1,    -1,    57,    58,    59,    60,    -1,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    -1,    77,    78,    -1,    -1,    15,    16,    17,
      18,    19,    20,   590,    -1,    -1,    -1,    25,   595,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    10,    -1,    14,    -1,    16,    15,    16,    17,    18,
      19,    20,    21,    24,    -1,    -1,    25,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,   662,   663,   664,    -1,   666,
     667,    -1,   669,   670,    -1,   672,    57,    58,    59,    60,
      -1,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    -1,    77,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   708,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    -1,    -1,    14,    -1,    16,    -1,    -1,
      -1,    -1,   729,    -1,   731,    24,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     747,   748,    -1,    -1,   751,   752,   753,   754,    -1,    -1,
      -1,    -1,   759,    -1,    -1,    -1,    -1,    -1,    57,    58,
      59,    60,   769,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    -1,    77,    78,
      -1,    -1,   590,    10,    -1,    -1,    -1,   595,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    -1,    31,    32,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
       9,    13,    11,    -1,    16,    -1,    15,    16,    17,    18,
      19,    20,    24,    -1,    -1,    -1,    -1,    26,    30,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    40,    -1,    -1,   662,   663,   664,    -1,   666,   667,
      -1,   669,   670,    -1,   672,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    -1,    77,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     708,    -1,   710,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    -1,    14,    -1,    16,    -1,    -1,    -1,
      -1,   729,    -1,   731,    24,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   747,
     748,    -1,    -1,   751,   752,   753,   754,    -1,    -1,    -1,
      -1,   759,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,
      60,   769,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    -1,    77,    78,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    -1,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,     9,    10,    11,    -1,    -1,    30,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    25,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    57,    58,    59,    60,    -1,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    -1,    77,    78,     9,    10,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,     9,    40,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,     9,    40,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    -1,    22,    23,
      -1,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,     9,    40,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    -1,    22,    -1,
      -1,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,     9,    40,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,     9,    40,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,     9,    40,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    -1,    29,    -1,    31,    32,    33,
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
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      -1,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    25,    15,    16,    17,    18,
      19,    20,    -1,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      15,    16,    17,    18,    19,    20,    -1,    10,    -1,    -1,
      25,    -1,    15,    16,    17,    18,    19,    -1,    33,    34,
      35,    36,    37,    38,    27,    28,    29,    -1,    31,    32,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    -1,    31,    32,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56
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
      75,    77,    78,   130,   133,     9,    42,   114,   119,   125,
      14,    40,   124,    78,   133,   132,   119,    78,   133,    84,
      77,    78,   109,   133,   113,    13,    14,    82,    63,   113,
     111,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,    10,   112,   113,   119,   114,   117,
     125,   126,   114,   125,   126,   114,   125,   126,   114,   125,
     126,   114,   125,   126,   114,   125,   126,   114,   121,   125,
     126,   127,   128,   114,   128,   114,   128,   114,   127,    78,
     133,   114,   125,   114,   125,   114,   125,   114,   125,   114,
     125,   114,   117,   121,   122,   125,   126,   127,   128,   114,
     117,   121,   122,   125,   126,   127,   128,   114,   125,   126,
     127,   114,   125,   126,   127,   114,   125,   126,   127,   114,
     125,   126,   127,    77,    78,   119,   114,   117,   114,   117,
     114,   117,   114,   117,   114,   121,   125,   126,   127,   128,
     114,   117,   114,   121,   114,   121,   114,   117,   114,   122,
     114,   122,   114,   125,   126,   114,   125,   126,   114,   125,
     126,   114,   125,   126,   114,   125,   126,   114,   126,   114,
     121,   125,   126,   127,   128,   114,   117,   114,   125,   114,
     125,   114,   125,   114,   125,   114,   125,   114,   125,   126,
     114,   125,   126,   114,   125,   126,   114,   125,   126,   114,
     125,   126,   114,   125,   126,   114,   125,   126,   114,   125,
     126,   114,   125,   126,   114,   125,   126,   114,   125,   126,
     114,   125,   126,   114,   121,   125,   126,   127,   128,   114,
     117,   114,   125,   126,   114,   125,   126,   114,   125,   126,
     114,   125,   126,   114,   125,   126,   114,   125,   126,   119,
     114,   121,   125,   126,   127,   128,   114,   117,   127,   114,
     127,   114,   127,   114,   127,   114,   127,   114,   127,   114,
     127,   114,   121,   125,   126,   127,   128,   114,   128,   114,
     128,   114,   117,   114,   128,   114,   128,   132,    10,   130,
      43,     9,     3,    12,    12,     3,   113,   125,   125,    15,
      16,    17,    18,    19,   125,   126,   125,   126,   125,   126,
     125,   126,   125,   126,   125,   126,   125,   125,   125,   125,
     125,   125,   126,   125,   126,   125,   126,   125,   126,   125,
     126,   125,   126,   113,   132,    89,   113,    13,     3,    14,
      57,   103,   104,   133,    10,    41,    10,    39,   107,   108,
     133,    12,    42,   119,    12,    42,    77,    14,    41,    69,
      12,    69,    42,    42,    42,    77,    10,    82,    14,     9,
      10,    10,    41,    12,    69,    12,    12,    10,   113,   123,
      10,   108,    12,   113,   125,   125,   125,   125,   125,   103,
     103,    77,    14,     3,    77,   130,    86,    77,    41,    10,
      77,    12,   119,    12,    42,    12,    42,   119,    43,    40,
       9,   113,   114,   118,   119,   125,   113,   118,   113,   118,
      87,    14,     3,   113,    87,   113,    86,    10,    14,    43,
     103,    43,    39,   133,    86,    12,    12,   119,    12,   119,
      12,    42,   113,    77,   114,   118,   125,    10,    10,    39,
      41,    10,    10,    10,    10,     3,    10,    61,    99,   101,
      86,   113,   113,    77,    77,    12,    12,    12,   119,    43,
      10,    87,    87,   119,   119,    87,    87,    87,    87,    87,
      12,   113,    39,   119
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
     120,   120,   121,   121,   122,   122,   122,   123,   123,   124,
     124,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   129,   129,   129,   129,   130,   130,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   132,   132,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133
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
       6,     7,     1,     3,     2,     2,     3,     2,     3,     4,
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
       0,   238,   238,   239,   241,   242,   243,   246,   247,   250,
     251,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   268,   269,   270,   271,   272,   275,   276,
     280,   282,   283,   287,   288,   289,   291,   292,   296,   297,
     298,   299,   300,   301,   303,   306,   308,   310,   312,   315,
     317,   318,   320,   321,   324,   325,   326,   328,   329,   330,
     331,   333,   334,   335,   339,   340,   341,   342,   344,   346,
     347,   349,   350,   351,   356,   360,   361,   362,   363,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   384,   385,   389,   390,   391,   392,   393,
     394,   395,   396,   399,   400,   401,   402,   403,   405,   406,
     408,   409,   410,   411,   412,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   424,   425,   426,   427,   429,   430,
     433,   434,   435,   436,   437,   439,   440,   441,   442,   443,
     445,   446,   447,   448,   449,   451,   452,   453,   454,   455,
     457,   458,   459,   460,   461,   462,   463,   464,   466,   467,
     468,   469,   470,   472,   473,   474,   476,   477,   478,   480,
     481,   482,   483,   484,   485,   486,   488,   489,   490,   491,
     492,   493,   494,   496,   497,   498,   499,   500,   501,   502,
     504,   505,   506,   507,   508,   509,   510,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   548,   549,   550,   552,   553,   554,   556,   557,   558,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   577,   578,   579,   581,
     582,   583,   585,   587,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   603,   604,   605,   606,   607,
     610,   611,   612,   616,   617,   619,   620,   621,   623,   624,
     626,   627,   628,   629,   630,   631,   632,   633,   634,   635,
     636,   637,   641,   642,   646,   647,   648,   650,   651,   653,
     654,   658,   659,   660,   661,   662,   663,   664,   665,   666,
     667,   668,   669,   670,   671,   675,   676,   677,   678,   679,
     680,   681,   682,   683,   684,   685,   686,   687,   688,   689,
     690,   691,   692,   693,   694,   695,   699,   700,   701,   702,
     703,   704,   705,   706,   707,   708,   709,   710,   711,   712,
     713,   714,   715,   716,   717,   718,   719,   720,   721,   722,
     723,   724,   725,   729,   730,   731,   732,   733,   735,   736,
     737,   738,   739,   740,   741,   743,   744,   745,   746,   747,
     748,   749,   751,   752,   753,   754,   755,   757,   758,   759,
     760,   761,   763,   764,   765,   766,   767,   769,   770,   771,
     772,   773,   775,   779,   780,   781,   782,   784,   785,   789,
     790,   791,   792,   793,   794,   795,   796,   797,   798,   799,
     800,   801,   803,   805,   810,   811,   812,   813,   814,   815,
     816,   817,   818,   819,   820,   821,   822,   823,   824,   825,
     826
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
#line 5118 "frontend/parser.cpp"

#line 829 "frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    auto msg = std::to_string(scanner->llvmloc->begin.line) + ":" + std::to_string(scanner->llvmloc->begin.column) + ": " + err_message;
    scanner->fatal_error(ptc::diag::ERR_SYNTAX, msg);
}
