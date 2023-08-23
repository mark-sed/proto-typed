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
      case symbol_kind::S_int_val: // int_val
        value.copy< ptc::ir::Expr * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmts_ne: // stmts_ne
      case symbol_kind::S_import: // import
      case symbol_kind::S_flowctl: // flowctl
      case symbol_kind::S_return: // return
      case symbol_kind::S_while: // while
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
      case symbol_kind::S_int_val: // int_val
        value.move< ptc::ir::Expr * > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmts_ne: // stmts_ne
      case symbol_kind::S_import: // import
      case symbol_kind::S_flowctl: // flowctl
      case symbol_kind::S_return: // return
      case symbol_kind::S_while: // while
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
      case symbol_kind::S_int_val: // int_val
        value.YY_MOVE_OR_COPY< ptc::ir::Expr * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmts_ne: // stmts_ne
      case symbol_kind::S_import: // import
      case symbol_kind::S_flowctl: // flowctl
      case symbol_kind::S_return: // return
      case symbol_kind::S_while: // while
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
      case symbol_kind::S_int_val: // int_val
        value.move< ptc::ir::Expr * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmts_ne: // stmts_ne
      case symbol_kind::S_import: // import
      case symbol_kind::S_flowctl: // flowctl
      case symbol_kind::S_return: // return
      case symbol_kind::S_while: // while
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
      case symbol_kind::S_int_val: // int_val
        value.copy< ptc::ir::Expr * > (that.value);
        break;

      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmts_ne: // stmts_ne
      case symbol_kind::S_import: // import
      case symbol_kind::S_flowctl: // flowctl
      case symbol_kind::S_return: // return
      case symbol_kind::S_while: // while
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
      case symbol_kind::S_int_val: // int_val
        value.move< ptc::ir::Expr * > (that.value);
        break;

      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmts_ne: // stmts_ne
      case symbol_kind::S_import: // import
      case symbol_kind::S_flowctl: // flowctl
      case symbol_kind::S_return: // return
      case symbol_kind::S_while: // while
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
      case symbol_kind::S_int_val: // int_val
        yylhs.value.emplace< ptc::ir::Expr * > ();
        break;

      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmts_ne: // stmts_ne
      case symbol_kind::S_import: // import
      case symbol_kind::S_flowctl: // flowctl
      case symbol_kind::S_return: // return
      case symbol_kind::S_while: // while
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
#line 222 "frontend/parser.yy"
                        { scanner->parseEntry(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1126 "frontend/parser.cpp"
    break;

  case 4: // stmt: stmts
#line 224 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1132 "frontend/parser.cpp"
    break;

  case 5: // stmt: stmt stmts
#line 225 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1138 "frontend/parser.cpp"
    break;

  case 6: // stmt: stmt error stmts
#line 226 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1144 "frontend/parser.cpp"
    break;

  case 9: // stmts: "terminator (\\n or ;)"
#line 233 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = nullptr; }
#line 1150 "frontend/parser.cpp"
    break;

  case 10: // stmts: stmts_ne
#line 234 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1156 "frontend/parser.cpp"
    break;

  case 11: // stmts_ne: set stmt_end
#line 236 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1162 "frontend/parser.cpp"
    break;

  case 12: // stmts_ne: vardecl stmt_end
#line 237 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1168 "frontend/parser.cpp"
    break;

  case 13: // stmts_ne: vardef stmt_end
#line 238 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1174 "frontend/parser.cpp"
    break;

  case 14: // stmts_ne: import stmt_end
#line 239 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1180 "frontend/parser.cpp"
    break;

  case 16: // stmts_ne: if
#line 241 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1186 "frontend/parser.cpp"
    break;

  case 17: // stmts_ne: while
#line 242 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1192 "frontend/parser.cpp"
    break;

  case 19: // stmts_ne: struct
#line 244 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1198 "frontend/parser.cpp"
    break;

  case 20: // stmts_ne: function
#line 245 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1204 "frontend/parser.cpp"
    break;

  case 21: // stmts_ne: flowctl stmt_end
#line 246 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1210 "frontend/parser.cpp"
    break;

  case 22: // stmts_ne: expr stmt_end
#line 247 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1216 "frontend/parser.cpp"
    break;

  case 23: // block: "{" "}"
#line 251 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1222 "frontend/parser.cpp"
    break;

  case 24: // block: "{" stmt "}"
#line 252 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1228 "frontend/parser.cpp"
    break;

  case 25: // block: "terminator (\\n or ;)" "{" stmt "}"
#line 253 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1234 "frontend/parser.cpp"
    break;

  case 26: // block: "{" stmt "}" "terminator (\\n or ;)"
#line 254 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1240 "frontend/parser.cpp"
    break;

  case 27: // block: "terminator (\\n or ;)" "{" stmt "}" "terminator (\\n or ;)"
#line 255 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1246 "frontend/parser.cpp"
    break;

  case 28: // body: stmts_ne
#line 258 "frontend/parser.yy"
                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1252 "frontend/parser.cpp"
    break;

  case 29: // body: block
#line 259 "frontend/parser.yy"
                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1258 "frontend/parser.cpp"
    break;

  case 30: // scope_body: stmts_ne
#line 262 "frontend/parser.yy"
                      { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); scanner->leaveScope(); }
#line 1264 "frontend/parser.cpp"
    break;

  case 31: // scope_body: block
#line 263 "frontend/parser.yy"
                      { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); scanner->leaveScope(); }
#line 1270 "frontend/parser.cpp"
    break;

  case 32: // import: "import" id_list
#line 267 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::IR * > () = scanner->parseImports(yystack_[0].value.as < std::vector<std::string>  > ()); }
#line 1276 "frontend/parser.cpp"
    break;

  case 33: // id_list: "identifier"
#line 269 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseImportName(yystack_[0].value.as < std::string > ()); }
#line 1282 "frontend/parser.cpp"
    break;

  case 34: // id_list: "identifier" "," id_list
#line 270 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseAddImportName(yystack_[0].value.as < std::vector<std::string>  > (), yystack_[2].value.as < std::string > ()); }
#line 1288 "frontend/parser.cpp"
    break;

  case 35: // flowctl: "break"
#line 274 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseBreak(); }
#line 1294 "frontend/parser.cpp"
    break;

  case 36: // flowctl: "continue"
#line 275 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseContinue(); }
#line 1300 "frontend/parser.cpp"
    break;

  case 37: // flowctl: return
#line 276 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1306 "frontend/parser.cpp"
    break;

  case 38: // return: "return"
#line 278 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(nullptr); }
#line 1312 "frontend/parser.cpp"
    break;

  case 39: // return: "return" expr
#line 279 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1318 "frontend/parser.cpp"
    break;

  case 41: // while: wh_kw "(" expr ")" scope_body
#line 287 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseWhile(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1324 "frontend/parser.cpp"
    break;

  case 42: // wh_kw: "while"
#line 289 "frontend/parser.yy"
                { scanner->enterBlockScope(); }
#line 1330 "frontend/parser.cpp"
    break;

  case 44: // do_kw: "do"
#line 293 "frontend/parser.yy"
             { /*scanner->enterBlockScope();*/ }
#line 1336 "frontend/parser.cpp"
    break;

  case 45: // if: if_kw "(" expr ")" scope_body else
#line 296 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseIfStmt(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1342 "frontend/parser.cpp"
    break;

  case 46: // else: el_kw scope_body
#line 298 "frontend/parser.yy"
                         { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1348 "frontend/parser.cpp"
    break;

  case 47: // else: %empty
#line 299 "frontend/parser.yy"
                    { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1354 "frontend/parser.cpp"
    break;

  case 48: // if_kw: "if"
#line 301 "frontend/parser.yy"
             { scanner->enterBlockScope(); }
#line 1360 "frontend/parser.cpp"
    break;

  case 49: // el_kw: "else"
#line 302 "frontend/parser.yy"
               { scanner->enterBlockScope(); }
#line 1366 "frontend/parser.cpp"
    break;

  case 50: // struct: "'struct'" "identifier" "{" "}"
#line 305 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[2].value.as < std::string > (), std::vector<ptc::ir::IR *>{}); }
#line 1372 "frontend/parser.cpp"
    break;

  case 51: // struct: "'struct'" "identifier" "{" decllist "}"
#line 306 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1378 "frontend/parser.cpp"
    break;

  case 52: // struct: "'struct'" "identifier" "terminator (\\n or ;)" "{" decllist "}"
#line 307 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[4].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1384 "frontend/parser.cpp"
    break;

  case 54: // decllist: "terminator (\\n or ;)" decllist
#line 310 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1390 "frontend/parser.cpp"
    break;

  case 55: // decllist: declistval "terminator (\\n or ;)"
#line 311 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[1].value.as < ptc::ir::IR * > (), std::vector<ptc::ir::IR *>{}); }
#line 1396 "frontend/parser.cpp"
    break;

  case 56: // decllist: declistval "terminator (\\n or ;)" decllist
#line 312 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[2].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1402 "frontend/parser.cpp"
    break;

  case 57: // declistval: type "identifier"
#line 314 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > (), nullptr); }
#line 1408 "frontend/parser.cpp"
    break;

  case 58: // declistval: type "identifier" "=" expr
#line 315 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1414 "frontend/parser.cpp"
    break;

  case 60: // function: type fun_id "(" ")" block
#line 320 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1420 "frontend/parser.cpp"
    break;

  case 61: // function: type fun_id "(" funargs ")" block
#line 321 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[5].value.as < ptc::ir::IR * > (), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1426 "frontend/parser.cpp"
    break;

  case 62: // function: "'void'" fun_id "(" ")" block
#line 322 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1432 "frontend/parser.cpp"
    break;

  case 63: // function: "'void'" fun_id "(" funargs ")" block
#line 323 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1438 "frontend/parser.cpp"
    break;

  case 64: // fun_id: "identifier"
#line 325 "frontend/parser.yy"
            { scanner->enterFunScope(); yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1444 "frontend/parser.cpp"
    break;

  case 65: // funargs: type "identifier"
#line 327 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseFunParam(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1450 "frontend/parser.cpp"
    break;

  case 67: // funargs: funargs "," type "identifier"
#line 329 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseAddFunParam(yystack_[3].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1456 "frontend/parser.cpp"
    break;

  case 70: // vardecl: type "identifier"
#line 336 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1462 "frontend/parser.cpp"
    break;

  case 71: // vardef: type "identifier" "=" struct_val
#line 340 "frontend/parser.yy"
         { yylhs.value.as < ptc::ir::IR * > () = yystack_[3].value.as < ptc::ir::IR * > (); }
#line 1468 "frontend/parser.cpp"
    break;

  case 72: // vardef: type "identifier" "=" expr
#line 341 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1474 "frontend/parser.cpp"
    break;

  case 75: // set: expr "++=" expr
#line 347 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1480 "frontend/parser.cpp"
    break;

  case 76: // set: expr "**=" expr
#line 348 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1486 "frontend/parser.cpp"
    break;

  case 77: // set: expr "%=" expr
#line 349 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1492 "frontend/parser.cpp"
    break;

  case 78: // set: expr "/=" expr
#line 350 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1498 "frontend/parser.cpp"
    break;

  case 79: // set: expr "*=" expr
#line 351 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1504 "frontend/parser.cpp"
    break;

  case 80: // set: expr "-=" expr
#line 352 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1510 "frontend/parser.cpp"
    break;

  case 81: // set: expr "+=" expr
#line 353 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1516 "frontend/parser.cpp"
    break;

  case 82: // set: expr "&=" expr
#line 354 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1522 "frontend/parser.cpp"
    break;

  case 83: // set: expr "|=" expr
#line 355 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1528 "frontend/parser.cpp"
    break;

  case 84: // set: expr "^=" expr
#line 356 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1534 "frontend/parser.cpp"
    break;

  case 85: // set: expr "<<=" expr
#line 357 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1540 "frontend/parser.cpp"
    break;

  case 86: // set: expr ">>=" expr
#line 358 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1546 "frontend/parser.cpp"
    break;

  case 87: // set: expr "=" expr
#line 359 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1552 "frontend/parser.cpp"
    break;

  case 88: // set: expr "=" set
#line 360 "frontend/parser.yy"
      { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1558 "frontend/parser.cpp"
    break;

  case 89: // callarglist: expr
#line 364 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseFunCallArg(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1564 "frontend/parser.cpp"
    break;

  case 90: // callarglist: expr "," callarglist
#line 365 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddFunCallArg(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[2].value.as < ptc::ir::Expr * > ()); }
#line 1570 "frontend/parser.cpp"
    break;

  case 91: // expr: expr_mat
#line 369 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = nullptr; }
#line 1576 "frontend/parser.cpp"
    break;

  case 92: // expr: expr_var
#line 370 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1582 "frontend/parser.cpp"
    break;

  case 93: // expr: expr_none
#line 371 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = nullptr; }
#line 1588 "frontend/parser.cpp"
    break;

  case 94: // expr: expr_struct
#line 372 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = nullptr; }
#line 1594 "frontend/parser.cpp"
    break;

  case 95: // expr: expr_int
#line 373 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 1600 "frontend/parser.cpp"
    break;

  case 96: // expr: expr_float
#line 374 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFloat(yystack_[0].value.as < double > ()); }
#line 1606 "frontend/parser.cpp"
    break;

  case 97: // expr: expr_str
#line 375 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseString(yystack_[0].value.as < std::string > ()); }
#line 1612 "frontend/parser.cpp"
    break;

  case 98: // expr: expr_bool
#line 376 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseBool(yystack_[0].value.as < bool > ()); }
#line 1618 "frontend/parser.cpp"
    break;

  case 99: // expr_var: "identifier"
#line 379 "frontend/parser.yy"
              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > ()); }
#line 1624 "frontend/parser.cpp"
    break;

  case 100: // expr_var: "external identifier"
#line 380 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > (), true); }
#line 1630 "frontend/parser.cpp"
    break;

  case 101: // expr_var: "-" "identifier"
#line 381 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1636 "frontend/parser.cpp"
    break;

  case 102: // expr_var: "-" "external identifier"
#line 382 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > (), true), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1642 "frontend/parser.cpp"
    break;

  case 103: // expr_var: "(" expr_var ")"
#line 383 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1648 "frontend/parser.cpp"
    break;

  case 104: // expr_var: expr_var "(" ")"
#line 385 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[2].value.as < ptc::ir::Expr * > (), std::vector<ptc::ir::Expr *>{}); }
#line 1654 "frontend/parser.cpp"
    break;

  case 105: // expr_var: expr_var "(" callarglist ")"
#line 386 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 1660 "frontend/parser.cpp"
    break;

  case 110: // expr_var: expr_var "[" int_val "]"
#line 392 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[3].value.as < ptc::ir::Expr * > (); }
#line 1666 "frontend/parser.cpp"
    break;

  case 114: // expr_var: expr_var slice
#line 397 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1672 "frontend/parser.cpp"
    break;

  case 115: // expr_var: "identifier" "." expr_var
#line 399 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1678 "frontend/parser.cpp"
    break;

  case 116: // expr_var: "external identifier" "." expr_var
#line 400 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1684 "frontend/parser.cpp"
    break;

  case 117: // expr_var: expr_var "." expr_var
#line 401 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1690 "frontend/parser.cpp"
    break;

  case 119: // expr_var: expr_var "**" expr_float
#line 404 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1696 "frontend/parser.cpp"
    break;

  case 120: // expr_var: expr_var "**" expr_var
#line 405 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1702 "frontend/parser.cpp"
    break;

  case 121: // expr_var: expr_int "*" expr_var
#line 407 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1708 "frontend/parser.cpp"
    break;

  case 122: // expr_var: expr_float "*" expr_var
#line 408 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1714 "frontend/parser.cpp"
    break;

  case 123: // expr_var: expr_var "*" expr_int
#line 409 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1720 "frontend/parser.cpp"
    break;

  case 124: // expr_var: expr_var "*" expr_float
#line 410 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1726 "frontend/parser.cpp"
    break;

  case 127: // expr_var: expr_var "*" expr_mat
#line 413 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1732 "frontend/parser.cpp"
    break;

  case 128: // expr_var: expr_var "*" expr_var
#line 414 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1738 "frontend/parser.cpp"
    break;

  case 129: // expr_var: expr_int "/" expr_var
#line 416 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1744 "frontend/parser.cpp"
    break;

  case 130: // expr_var: expr_float "/" expr_var
#line 417 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1750 "frontend/parser.cpp"
    break;

  case 131: // expr_var: expr_var "/" expr_int
#line 418 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1756 "frontend/parser.cpp"
    break;

  case 132: // expr_var: expr_var "/" expr_float
#line 419 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1762 "frontend/parser.cpp"
    break;

  case 133: // expr_var: expr_var "/" expr_var
#line 420 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1768 "frontend/parser.cpp"
    break;

  case 134: // expr_var: expr_int "%" expr_var
#line 422 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1774 "frontend/parser.cpp"
    break;

  case 135: // expr_var: expr_float "%" expr_var
#line 423 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1780 "frontend/parser.cpp"
    break;

  case 136: // expr_var: expr_var "%" expr_int
#line 424 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1786 "frontend/parser.cpp"
    break;

  case 137: // expr_var: expr_var "%" expr_float
#line 425 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1792 "frontend/parser.cpp"
    break;

  case 138: // expr_var: expr_var "%" expr_var
#line 426 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1798 "frontend/parser.cpp"
    break;

  case 139: // expr_var: expr_int "+" expr_var
#line 428 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1804 "frontend/parser.cpp"
    break;

  case 140: // expr_var: expr_float "+" expr_var
#line 429 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1810 "frontend/parser.cpp"
    break;

  case 141: // expr_var: expr_var "+" expr_int
#line 430 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1816 "frontend/parser.cpp"
    break;

  case 142: // expr_var: expr_var "+" expr_float
#line 431 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1822 "frontend/parser.cpp"
    break;

  case 144: // expr_var: expr_var "+" expr_mat
#line 433 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1828 "frontend/parser.cpp"
    break;

  case 146: // expr_var: expr_var "+" expr_var
#line 435 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1834 "frontend/parser.cpp"
    break;

  case 147: // expr_var: expr_int "-" expr_var
#line 437 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1840 "frontend/parser.cpp"
    break;

  case 148: // expr_var: expr_float "-" expr_var
#line 438 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1846 "frontend/parser.cpp"
    break;

  case 149: // expr_var: expr_var "-" expr_int
#line 439 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1852 "frontend/parser.cpp"
    break;

  case 150: // expr_var: expr_var "-" expr_float
#line 440 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1858 "frontend/parser.cpp"
    break;

  case 152: // expr_var: expr_var "-" expr_mat
#line 442 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1864 "frontend/parser.cpp"
    break;

  case 154: // expr_var: expr_var "-" expr_var
#line 444 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1870 "frontend/parser.cpp"
    break;

  case 155: // expr_var: expr_int "<<" expr_var
#line 446 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 1876 "frontend/parser.cpp"
    break;

  case 156: // expr_var: expr_var "<<" expr_int
#line 447 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 1882 "frontend/parser.cpp"
    break;

  case 157: // expr_var: expr_var "<<" expr_var
#line 448 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 1888 "frontend/parser.cpp"
    break;

  case 158: // expr_var: expr_int ">>" expr_var
#line 450 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 1894 "frontend/parser.cpp"
    break;

  case 159: // expr_var: expr_var ">>" expr_int
#line 451 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 1900 "frontend/parser.cpp"
    break;

  case 160: // expr_var: expr_var ">>" expr_var
#line 452 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 1906 "frontend/parser.cpp"
    break;

  case 161: // expr_var: expr_int ">" expr_var
#line 454 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 1912 "frontend/parser.cpp"
    break;

  case 162: // expr_var: expr_float ">" expr_var
#line 455 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 1918 "frontend/parser.cpp"
    break;

  case 164: // expr_var: expr_var ">" expr_int
#line 457 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 1924 "frontend/parser.cpp"
    break;

  case 165: // expr_var: expr_var ">" expr_float
#line 458 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 1930 "frontend/parser.cpp"
    break;

  case 166: // expr_var: expr_var ">" expr_str
#line 459 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1936 "frontend/parser.cpp"
    break;

  case 167: // expr_var: expr_var ">" expr_var
#line 460 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 1942 "frontend/parser.cpp"
    break;

  case 168: // expr_var: expr_int ">=" expr_var
#line 462 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 1948 "frontend/parser.cpp"
    break;

  case 169: // expr_var: expr_float ">=" expr_var
#line 463 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 1954 "frontend/parser.cpp"
    break;

  case 171: // expr_var: expr_var ">=" expr_int
#line 465 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 1960 "frontend/parser.cpp"
    break;

  case 172: // expr_var: expr_var ">=" expr_float
#line 466 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 1966 "frontend/parser.cpp"
    break;

  case 173: // expr_var: expr_var ">=" expr_str
#line 467 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1972 "frontend/parser.cpp"
    break;

  case 174: // expr_var: expr_var ">=" expr_var
#line 468 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 1978 "frontend/parser.cpp"
    break;

  case 175: // expr_var: expr_int "<" expr_var
#line 470 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 1984 "frontend/parser.cpp"
    break;

  case 176: // expr_var: expr_float "<" expr_var
#line 471 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 1990 "frontend/parser.cpp"
    break;

  case 178: // expr_var: expr_var "<" expr_int
#line 473 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 1996 "frontend/parser.cpp"
    break;

  case 179: // expr_var: expr_var "<" expr_float
#line 474 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2002 "frontend/parser.cpp"
    break;

  case 180: // expr_var: expr_var "<" expr_str
#line 475 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2008 "frontend/parser.cpp"
    break;

  case 181: // expr_var: expr_var "<" expr_var
#line 476 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 2014 "frontend/parser.cpp"
    break;

  case 182: // expr_var: expr_int "<=" expr_var
#line 478 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2020 "frontend/parser.cpp"
    break;

  case 183: // expr_var: expr_float "<=" expr_var
#line 479 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2026 "frontend/parser.cpp"
    break;

  case 185: // expr_var: expr_var "<=" expr_int
#line 481 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2032 "frontend/parser.cpp"
    break;

  case 186: // expr_var: expr_var "<=" expr_float
#line 482 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2038 "frontend/parser.cpp"
    break;

  case 187: // expr_var: expr_var "<=" expr_str
#line 483 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2044 "frontend/parser.cpp"
    break;

  case 188: // expr_var: expr_var "<=" expr_var
#line 484 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2050 "frontend/parser.cpp"
    break;

  case 189: // expr_var: expr_int "==" expr_var
#line 486 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2056 "frontend/parser.cpp"
    break;

  case 190: // expr_var: expr_float "==" expr_var
#line 487 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2062 "frontend/parser.cpp"
    break;

  case 192: // expr_var: expr_bool "==" expr_var
#line 489 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2068 "frontend/parser.cpp"
    break;

  case 196: // expr_var: expr_var "==" expr_int
#line 493 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2074 "frontend/parser.cpp"
    break;

  case 197: // expr_var: expr_var "==" expr_float
#line 494 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2080 "frontend/parser.cpp"
    break;

  case 198: // expr_var: expr_var "==" expr_str
#line 495 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2086 "frontend/parser.cpp"
    break;

  case 199: // expr_var: expr_var "==" expr_bool
#line 496 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2092 "frontend/parser.cpp"
    break;

  case 200: // expr_var: expr_var "==" expr_none
#line 497 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2098 "frontend/parser.cpp"
    break;

  case 201: // expr_var: expr_var "==" expr_struct
#line 498 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2104 "frontend/parser.cpp"
    break;

  case 203: // expr_var: expr_var "==" expr_mat
#line 500 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2110 "frontend/parser.cpp"
    break;

  case 205: // expr_var: expr_var "==" expr_var
#line 502 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2116 "frontend/parser.cpp"
    break;

  case 206: // expr_var: expr_int "!=" expr_var
#line 504 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2122 "frontend/parser.cpp"
    break;

  case 207: // expr_var: expr_float "!=" expr_var
#line 505 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2128 "frontend/parser.cpp"
    break;

  case 213: // expr_var: expr_var "!=" expr_int
#line 511 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2134 "frontend/parser.cpp"
    break;

  case 214: // expr_var: expr_var "!=" expr_float
#line 512 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2140 "frontend/parser.cpp"
    break;

  case 215: // expr_var: expr_var "!=" expr_str
#line 513 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2146 "frontend/parser.cpp"
    break;

  case 216: // expr_var: expr_var "!=" expr_bool
#line 514 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2152 "frontend/parser.cpp"
    break;

  case 217: // expr_var: expr_var "!=" expr_none
#line 515 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2158 "frontend/parser.cpp"
    break;

  case 218: // expr_var: expr_var "!=" expr_struct
#line 516 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2164 "frontend/parser.cpp"
    break;

  case 220: // expr_var: expr_var "!=" expr_mat
#line 518 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2170 "frontend/parser.cpp"
    break;

  case 222: // expr_var: expr_var "!=" expr_var
#line 520 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2176 "frontend/parser.cpp"
    break;

  case 223: // expr_var: expr_int "&" expr_var
#line 522 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2182 "frontend/parser.cpp"
    break;

  case 224: // expr_var: expr_var "&" expr_int
#line 523 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2188 "frontend/parser.cpp"
    break;

  case 225: // expr_var: expr_var "&" expr_var
#line 524 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2194 "frontend/parser.cpp"
    break;

  case 226: // expr_var: expr_int "^" expr_var
#line 526 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2200 "frontend/parser.cpp"
    break;

  case 227: // expr_var: expr_var "^" expr_int
#line 527 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2206 "frontend/parser.cpp"
    break;

  case 228: // expr_var: expr_var "^" expr_var
#line 528 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2212 "frontend/parser.cpp"
    break;

  case 229: // expr_var: expr_int "|" expr_var
#line 530 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2218 "frontend/parser.cpp"
    break;

  case 230: // expr_var: expr_var "|" expr_int
#line 531 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2224 "frontend/parser.cpp"
    break;

  case 231: // expr_var: expr_var "|" expr_var
#line 532 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2230 "frontend/parser.cpp"
    break;

  case 246: // expr_var: expr_var "in" expr_str
#line 548 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2236 "frontend/parser.cpp"
    break;

  case 247: // expr_var: expr_var "in" expr_var
#line 549 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2242 "frontend/parser.cpp"
    break;

  case 248: // expr_var: expr_bool "and" expr_var
#line 551 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2248 "frontend/parser.cpp"
    break;

  case 249: // expr_var: expr_var "and" expr_bool
#line 552 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2254 "frontend/parser.cpp"
    break;

  case 250: // expr_var: expr_var "and" expr_var
#line 553 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2260 "frontend/parser.cpp"
    break;

  case 251: // expr_var: expr_bool "or" expr_var
#line 555 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2266 "frontend/parser.cpp"
    break;

  case 252: // expr_var: expr_var "or" expr_bool
#line 556 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2272 "frontend/parser.cpp"
    break;

  case 253: // expr_var: expr_var "or" expr_var
#line 557 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2278 "frontend/parser.cpp"
    break;

  case 265: // expr_var: expr_int "++" expr_var
#line 570 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2284 "frontend/parser.cpp"
    break;

  case 266: // expr_var: expr_float "++" expr_var
#line 571 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2290 "frontend/parser.cpp"
    break;

  case 267: // expr_var: expr_str "++" expr_var
#line 572 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2296 "frontend/parser.cpp"
    break;

  case 268: // expr_var: expr_bool "++" expr_var
#line 573 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2302 "frontend/parser.cpp"
    break;

  case 271: // expr_var: expr_var "++" expr_int
#line 576 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2308 "frontend/parser.cpp"
    break;

  case 272: // expr_var: expr_var "++" expr_float
#line 577 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2314 "frontend/parser.cpp"
    break;

  case 273: // expr_var: expr_var "++" expr_str
#line 578 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2320 "frontend/parser.cpp"
    break;

  case 274: // expr_var: expr_var "++" expr_bool
#line 579 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2326 "frontend/parser.cpp"
    break;

  case 275: // expr_var: expr_var "++" expr_none
#line 580 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2332 "frontend/parser.cpp"
    break;

  case 276: // expr_var: expr_var "++" expr_struct
#line 581 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2338 "frontend/parser.cpp"
    break;

  case 277: // expr_var: expr_var "++" expr_var
#line 582 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2344 "frontend/parser.cpp"
    break;

  case 292: // int_val: expr_int
#line 606 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 2350 "frontend/parser.cpp"
    break;

  case 293: // int_val: expr_var
#line 607 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2356 "frontend/parser.cpp"
    break;

  case 314: // expr_int: "int"
#line 640 "frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 2362 "frontend/parser.cpp"
    break;

  case 315: // expr_int: "-" expr_int
#line 641 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 2368 "frontend/parser.cpp"
    break;

  case 316: // expr_int: "(" expr_int ")"
#line 642 "frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 2374 "frontend/parser.cpp"
    break;

  case 317: // expr_int: "~" expr_int
#line 643 "frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 2380 "frontend/parser.cpp"
    break;

  case 318: // expr_int: expr_int "*" expr_int
#line 644 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 2386 "frontend/parser.cpp"
    break;

  case 319: // expr_int: expr_int "/" expr_int
#line 645 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 2392 "frontend/parser.cpp"
    break;

  case 320: // expr_int: expr_int "%" expr_int
#line 646 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 2398 "frontend/parser.cpp"
    break;

  case 321: // expr_int: expr_int "-" expr_int
#line 647 "frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 2404 "frontend/parser.cpp"
    break;

  case 322: // expr_int: expr_int "+" expr_int
#line 648 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 2410 "frontend/parser.cpp"
    break;

  case 323: // expr_int: expr_int "<<" expr_int
#line 649 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 2416 "frontend/parser.cpp"
    break;

  case 324: // expr_int: expr_int ">>" expr_int
#line 650 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 2422 "frontend/parser.cpp"
    break;

  case 325: // expr_int: expr_int "&" expr_int
#line 651 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 2428 "frontend/parser.cpp"
    break;

  case 326: // expr_int: expr_int "^" expr_int
#line 652 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 2434 "frontend/parser.cpp"
    break;

  case 327: // expr_int: expr_int "|" expr_int
#line 653 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 2440 "frontend/parser.cpp"
    break;

  case 328: // expr_float: "float"
#line 657 "frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 2446 "frontend/parser.cpp"
    break;

  case 329: // expr_float: "-" expr_float
#line 658 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 2452 "frontend/parser.cpp"
    break;

  case 330: // expr_float: "(" expr_float ")"
#line 659 "frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 2458 "frontend/parser.cpp"
    break;

  case 331: // expr_float: expr_float "**" expr_float
#line 660 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2464 "frontend/parser.cpp"
    break;

  case 332: // expr_float: expr_float "**" expr_int
#line 661 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2470 "frontend/parser.cpp"
    break;

  case 333: // expr_float: expr_int "**" expr_float
#line 662 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2476 "frontend/parser.cpp"
    break;

  case 334: // expr_float: expr_float "*" expr_float
#line 663 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 2482 "frontend/parser.cpp"
    break;

  case 335: // expr_float: expr_float "*" expr_int
#line 664 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 2488 "frontend/parser.cpp"
    break;

  case 336: // expr_float: expr_int "*" expr_float
#line 665 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 2494 "frontend/parser.cpp"
    break;

  case 337: // expr_float: expr_float "/" expr_float
#line 666 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 2500 "frontend/parser.cpp"
    break;

  case 338: // expr_float: expr_float "/" expr_int
#line 667 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 2506 "frontend/parser.cpp"
    break;

  case 339: // expr_float: expr_int "/" expr_float
#line 668 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 2512 "frontend/parser.cpp"
    break;

  case 340: // expr_float: expr_float "%" expr_float
#line 669 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2518 "frontend/parser.cpp"
    break;

  case 341: // expr_float: expr_float "%" expr_int
#line 670 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2524 "frontend/parser.cpp"
    break;

  case 342: // expr_float: expr_int "%" expr_float
#line 671 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2530 "frontend/parser.cpp"
    break;

  case 343: // expr_float: expr_float "-" expr_float
#line 672 "frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 2536 "frontend/parser.cpp"
    break;

  case 344: // expr_float: expr_float "-" expr_int
#line 673 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 2542 "frontend/parser.cpp"
    break;

  case 345: // expr_float: expr_int "-" expr_float
#line 674 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 2548 "frontend/parser.cpp"
    break;

  case 346: // expr_float: expr_float "+" expr_float
#line 675 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 2554 "frontend/parser.cpp"
    break;

  case 347: // expr_float: expr_float "+" expr_int
#line 676 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 2560 "frontend/parser.cpp"
    break;

  case 348: // expr_float: expr_int "+" expr_float
#line 677 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 2566 "frontend/parser.cpp"
    break;

  case 349: // expr_str: "string"
#line 681 "frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2572 "frontend/parser.cpp"
    break;

  case 350: // expr_str: "(" expr_str ")"
#line 682 "frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 2578 "frontend/parser.cpp"
    break;

  case 351: // expr_str: expr_str "++" expr_str
#line 683 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 2584 "frontend/parser.cpp"
    break;

  case 352: // expr_str: expr_str "++" expr_int
#line 684 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 2590 "frontend/parser.cpp"
    break;

  case 353: // expr_str: expr_str "++" expr_float
#line 685 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 2596 "frontend/parser.cpp"
    break;

  case 354: // expr_str: expr_str "++" expr_bool
#line 686 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2602 "frontend/parser.cpp"
    break;

  case 355: // expr_str: expr_str "++" expr_none
#line 687 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 2608 "frontend/parser.cpp"
    break;

  case 356: // expr_str: expr_int "++" expr_str
#line 688 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 2614 "frontend/parser.cpp"
    break;

  case 357: // expr_str: expr_int "++" expr_int
#line 689 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 2620 "frontend/parser.cpp"
    break;

  case 358: // expr_str: expr_int "++" expr_float
#line 690 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 2626 "frontend/parser.cpp"
    break;

  case 359: // expr_str: expr_int "++" expr_bool
#line 691 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2632 "frontend/parser.cpp"
    break;

  case 360: // expr_str: expr_int "++" expr_none
#line 692 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 2638 "frontend/parser.cpp"
    break;

  case 361: // expr_str: expr_float "++" expr_str
#line 693 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 2644 "frontend/parser.cpp"
    break;

  case 362: // expr_str: expr_float "++" expr_int
#line 694 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 2650 "frontend/parser.cpp"
    break;

  case 363: // expr_str: expr_float "++" expr_float
#line 695 "frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 2656 "frontend/parser.cpp"
    break;

  case 364: // expr_str: expr_float "++" expr_bool
#line 696 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2662 "frontend/parser.cpp"
    break;

  case 365: // expr_str: expr_float "++" expr_none
#line 697 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 2668 "frontend/parser.cpp"
    break;

  case 366: // expr_str: expr_bool "++" expr_str
#line 698 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 2674 "frontend/parser.cpp"
    break;

  case 367: // expr_str: expr_bool "++" expr_int
#line 699 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 2680 "frontend/parser.cpp"
    break;

  case 368: // expr_str: expr_bool "++" expr_float
#line 700 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 2686 "frontend/parser.cpp"
    break;

  case 369: // expr_str: expr_bool "++" expr_bool
#line 701 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2692 "frontend/parser.cpp"
    break;

  case 370: // expr_str: expr_bool "++" expr_none
#line 702 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 2698 "frontend/parser.cpp"
    break;

  case 371: // expr_str: expr_none "++" expr_str
#line 703 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 2704 "frontend/parser.cpp"
    break;

  case 372: // expr_str: expr_none "++" expr_int
#line 704 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 2710 "frontend/parser.cpp"
    break;

  case 373: // expr_str: expr_none "++" expr_float
#line 705 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 2716 "frontend/parser.cpp"
    break;

  case 374: // expr_str: expr_none "++" expr_bool
#line 706 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2722 "frontend/parser.cpp"
    break;

  case 375: // expr_str: expr_none "++" expr_none
#line 707 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 2728 "frontend/parser.cpp"
    break;

  case 376: // expr_bool: "bool"
#line 711 "frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 2734 "frontend/parser.cpp"
    break;

  case 377: // expr_bool: "(" expr_bool ")"
#line 712 "frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 2740 "frontend/parser.cpp"
    break;

  case 378: // expr_bool: "not" expr_bool
#line 713 "frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 2746 "frontend/parser.cpp"
    break;

  case 379: // expr_bool: expr_bool "or" expr_bool
#line 714 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 2752 "frontend/parser.cpp"
    break;

  case 380: // expr_bool: expr_bool "and" expr_bool
#line 715 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 2758 "frontend/parser.cpp"
    break;

  case 381: // expr_bool: expr_bool "==" expr_bool
#line 717 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 2764 "frontend/parser.cpp"
    break;

  case 382: // expr_bool: expr_int "==" expr_int
#line 718 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 2770 "frontend/parser.cpp"
    break;

  case 383: // expr_bool: expr_int "==" expr_float
#line 719 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 2776 "frontend/parser.cpp"
    break;

  case 384: // expr_bool: expr_float "==" expr_float
#line 720 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 2782 "frontend/parser.cpp"
    break;

  case 385: // expr_bool: expr_float "==" expr_int
#line 721 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 2788 "frontend/parser.cpp"
    break;

  case 386: // expr_bool: expr_str "==" expr_str
#line 722 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 2794 "frontend/parser.cpp"
    break;

  case 387: // expr_bool: expr_none "==" expr_none
#line 723 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 2800 "frontend/parser.cpp"
    break;

  case 388: // expr_bool: expr_bool "!=" expr_bool
#line 725 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 2806 "frontend/parser.cpp"
    break;

  case 389: // expr_bool: expr_int "!=" expr_int
#line 726 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 2812 "frontend/parser.cpp"
    break;

  case 390: // expr_bool: expr_int "!=" expr_float
#line 727 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 2818 "frontend/parser.cpp"
    break;

  case 391: // expr_bool: expr_float "!=" expr_float
#line 728 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 2824 "frontend/parser.cpp"
    break;

  case 392: // expr_bool: expr_float "!=" expr_int
#line 729 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 2830 "frontend/parser.cpp"
    break;

  case 393: // expr_bool: expr_str "!=" expr_str
#line 730 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 2836 "frontend/parser.cpp"
    break;

  case 394: // expr_bool: expr_none "!=" expr_none
#line 731 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 2842 "frontend/parser.cpp"
    break;

  case 395: // expr_bool: expr_int ">" expr_int
#line 733 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 2848 "frontend/parser.cpp"
    break;

  case 396: // expr_bool: expr_int ">" expr_float
#line 734 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 2854 "frontend/parser.cpp"
    break;

  case 397: // expr_bool: expr_float ">" expr_float
#line 735 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 2860 "frontend/parser.cpp"
    break;

  case 398: // expr_bool: expr_float ">" expr_int
#line 736 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 2866 "frontend/parser.cpp"
    break;

  case 399: // expr_bool: expr_str ">" expr_str
#line 737 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 2872 "frontend/parser.cpp"
    break;

  case 400: // expr_bool: expr_int "<" expr_int
#line 739 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 2878 "frontend/parser.cpp"
    break;

  case 401: // expr_bool: expr_int "<" expr_float
#line 740 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 2884 "frontend/parser.cpp"
    break;

  case 402: // expr_bool: expr_float "<" expr_float
#line 741 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 2890 "frontend/parser.cpp"
    break;

  case 403: // expr_bool: expr_float "<" expr_int
#line 742 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 2896 "frontend/parser.cpp"
    break;

  case 404: // expr_bool: expr_str "<" expr_str
#line 743 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 2902 "frontend/parser.cpp"
    break;

  case 405: // expr_bool: expr_int ">=" expr_int
#line 745 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 2908 "frontend/parser.cpp"
    break;

  case 406: // expr_bool: expr_int ">=" expr_float
#line 746 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 2914 "frontend/parser.cpp"
    break;

  case 407: // expr_bool: expr_float ">=" expr_float
#line 747 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 2920 "frontend/parser.cpp"
    break;

  case 408: // expr_bool: expr_float ">=" expr_int
#line 748 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 2926 "frontend/parser.cpp"
    break;

  case 409: // expr_bool: expr_str ">=" expr_str
#line 749 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 2932 "frontend/parser.cpp"
    break;

  case 410: // expr_bool: expr_int "<=" expr_int
#line 751 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 2938 "frontend/parser.cpp"
    break;

  case 411: // expr_bool: expr_int "<=" expr_float
#line 752 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 2944 "frontend/parser.cpp"
    break;

  case 412: // expr_bool: expr_float "<=" expr_float
#line 753 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 2950 "frontend/parser.cpp"
    break;

  case 413: // expr_bool: expr_float "<=" expr_int
#line 754 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 2956 "frontend/parser.cpp"
    break;

  case 414: // expr_bool: expr_str "<=" expr_str
#line 755 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 2962 "frontend/parser.cpp"
    break;

  case 415: // expr_bool: expr_str "in" expr_str
#line 757 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[0].value.as < std::string > ().find(yystack_[2].value.as < std::string > ()) != std::string::npos; }
#line 2968 "frontend/parser.cpp"
    break;

  case 420: // mattype: "identifier" matsq
#line 769 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2974 "frontend/parser.cpp"
    break;

  case 421: // mattype: "'int'" matsq
#line 770 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(INT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2980 "frontend/parser.cpp"
    break;

  case 422: // mattype: "'float'" matsq
#line 771 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(FLOAT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2986 "frontend/parser.cpp"
    break;

  case 423: // mattype: "'string'" matsq
#line 772 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(STRING_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2992 "frontend/parser.cpp"
    break;

  case 424: // mattype: "'bool'" matsq
#line 773 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(BOOL_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2998 "frontend/parser.cpp"
    break;

  case 432: // matsq: "[" "]"
#line 782 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(scanner->parseInt(-1)); }
#line 3004 "frontend/parser.cpp"
    break;

  case 433: // matsq: "[" int_val "]"
#line 783 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 3010 "frontend/parser.cpp"
    break;

  case 434: // matsq: "[" "]" matsq
#line 784 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), scanner->parseInt(-1)); }
#line 3016 "frontend/parser.cpp"
    break;

  case 435: // matsq: "[" int_val "]" matsq
#line 785 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[2].value.as < ptc::ir::Expr * > ()); }
#line 3022 "frontend/parser.cpp"
    break;

  case 442: // type: mattype "?"
#line 795 "frontend/parser.yy"
       { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 3028 "frontend/parser.cpp"
    break;

  case 443: // type: "'int'"
#line 796 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, true); }
#line 3034 "frontend/parser.cpp"
    break;

  case 444: // type: "'float'"
#line 797 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, true); }
#line 3040 "frontend/parser.cpp"
    break;

  case 445: // type: "'string'"
#line 798 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, true); }
#line 3046 "frontend/parser.cpp"
    break;

  case 446: // type: "'bool'"
#line 799 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, true); }
#line 3052 "frontend/parser.cpp"
    break;

  case 447: // type: "identifier"
#line 800 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[0].value.as < std::string > (), true); }
#line 3058 "frontend/parser.cpp"
    break;

  case 449: // type: mattype
#line 802 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 3064 "frontend/parser.cpp"
    break;


#line 3068 "frontend/parser.cpp"

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
     861,  -756,  -756,  -756,  -756,  -756,  -756,  -756,  2027,   331,
     340,  1235,   632,    57,    64,  -756,    95,  -756,  -756,  2099,
    -756,  -756,    94,    14,    17,    22,    23,   132,   136,    24,
     197,   231,    50,  -756,  -756,    41,    41,  -756,  -756,  -756,
     215,  -756,  1666,  -756,   234,  -756,  -756,    41,    41,    41,
    1391,  2160,  -756,   424,  -756,   217,   670,  2794,  1948,   733,
     637,    25,   208,    -6,   254,   196,  2115,   267,   424,   269,
     149,   217,   670,  2687,  2743,  1164,  1097,  2099,  -756,   196,
     219,    37,   622,   622,  -756,  -756,  -756,  -756,  1799,   109,
    2817,  2936,   877,  -756,   632,   632,  -756,   247,   280,  -756,
     257,  -756,   291,   704,   337,  -756,   337,  -756,   337,  -756,
     337,  -756,   123,  -756,   342,   494,     9,  2099,   337,  -756,
    -756,  -756,  1208,  2099,  -756,  -756,  -756,  2013,  -756,  -756,
    -756,  -756,  -756,  2099,   348,  1785,  -756,  -756,   307,  2099,
    -756,  -756,  -756,  2099,  2099,  2099,  2099,  2099,  2099,  2099,
    2099,  2099,  2099,  2099,  2099,  2099,  -756,   831,  1208,  2099,
    2099,  2099,  2099,  2099,  2099,  2099,  2099,  2099,  2099,  2099,
    2099,  2099,  2099,  2099,  2099,  2099,  2099,  2099,  2099,  2099,
    2099,  -756,  1208,  2099,  2099,  2099,  2099,  2099,  2099,  -756,
    2099,  2099,  2099,  2099,  2099,  2099,  2099,  2099,  2099,  2099,
    2099,  2099,  2099,   622,  2099,  2099,  2099,  2099,  2099,  2099,
    2099,  2099,  2099,  2099,  2099,  2099,  2099,  2099,  2099,  2099,
    2099,  2099,  2099,  2099,  2099,  2099,  2099,  2099,  2099,  2099,
    2099,  2099,  2099,  2099,  2099,  2099,  2099,  2099,  2099,  2099,
    2099,  2099,  2099,  2099,  2099,  2099,   337,  -756,  -756,   390,
      20,   361,  -756,  1208,   362,  -756,  -756,  -756,  2099,  2099,
    -756,  -756,  -756,  -756,   275,   421,   368,  -756,  1636,  1043,
     622,   622,   622,   622,   622,   632,   632,   632,   632,   632,
     622,   622,   622,   622,   622,   622,  2715,  2771,  1723,   510,
    1235,    56,    56,  1235,   622,   622,   622,   622,   622,   622,
    1235,   622,   622,   622,   622,   622,   622,  1235,  1235,  1235,
    1235,  1235,  1235,  1235,  1235,  1235,  1235,  1235,  1235,  1235,
    1319,  -756,   632,   632,   632,   632,   632,  2099,    64,   343,
    2099,   337,  2160,   369,  2794,  1948,   733,   637,  -756,  -756,
    -756,  -756,   389,   114,   400,   605,    19,  -756,   308,   393,
     230,  2794,  -756,    31,   230,  -756,   394,  2013,  -756,  1040,
     399,   401,  -756,  2161,  -756,  -756,  -756,  -756,  -756,  -756,
    -756,  -756,  -756,  -756,  -756,  -756,  -756,   403,   363,    88,
     249,   341,   658,   856,   249,   341,   658,   856,   147,   405,
     397,   411,   147,   397,   411,   147,   397,   411,   147,   411,
    2482,   229,   321,  2840,   924,   513,   440,  2543,   353,  2514,
     575,  2572,   330,  2659,  2913,  2601,  2890,  2630,  2381,   985,
     799,   985,   799,  1605,   511,  -756,  -756,  2947,  2029,   339,
    -756,  1605,   511,  -756,  -756,  2947,  2029,   339,  -756,  2231,
     707,  1019,   422,  2231,   707,  1019,   422,  2231,   707,  1019,
     422,  2231,   707,  1019,   422,   230,    91,   249,   341,   249,
     341,   147,   405,  2572,   475,  1605,   511,  1605,   511,  2482,
     229,   321,  2840,   924,   513,   440,  2572,   475,  1605,  -756,
    1605,  -756,  2482,   229,   321,  2840,   924,   513,   440,  2572,
     475,  1605,  -756,  1605,  -756,   249,   658,   856,   249,   658,
     856,   147,   397,   411,   147,   397,   411,   147,   397,   411,
     960,   416,  2482,   229,   321,  2840,   924,   513,   440,  2572,
     475,  2659,  2913,  2601,  2890,  2630,  2381,   985,   799,   985,
     799,  1605,  2947,  2029,  1605,  2947,  2029,  2231,   707,  1019,
    2231,   707,  1019,  2231,   707,  1019,  2231,   707,  1019,   249,
     658,   856,   249,   658,   856,   147,   397,   411,   147,   397,
     411,   147,   397,   411,   147,   397,   411,  2482,   229,   321,
    2840,   924,   513,   440,  2572,   475,  1605,  2947,  2029,  1605,
    2947,  2029,  2231,   707,  1019,  2231,   707,  1019,  2231,   707,
    1019,  2231,   707,  1019,   430,  2482,   229,   321,  2840,   924,
     513,   440,  2572,   475,   330,  1605,   339,  1605,   339,  2231,
     422,  2231,   422,  2231,   422,  2231,   422,  2482,   229,   321,
    2840,   924,   513,   440,  2543,   353,  2514,   575,  2572,   475,
    1605,  -756,  1605,  -756,  -756,  -756,    27,   436,    30,  1268,
     445,    93,  -756,   437,   406,   439,  -756,  2099,  -756,  -756,
     862,  1147,   862,  1147,   397,   416,   397,   416,   397,   416,
    1459,  1518,  1389,  1076,  1076,   862,  1147,   862,  1147,   397,
     416,   397,   416,   397,   416,   397,   416,   224,  2863,  2976,
    1677,   723,   444,  -756,  -756,   224,  2863,  2976,  1677,   723,
    1734,  1141,  1734,  1141,  1734,  1141,  1734,  1141,  1734,  1141,
    1734,  1141,   224,  2863,  2976,  1677,   723,  1734,  1141,  1734,
    1141,  1734,  1141,  1734,  1141,  1734,  1141,  1734,  1141,   224,
    2863,  2976,  1677,   723,  1597,   830,   588,   588,  -756,  -756,
    -756,  -756,   224,  2863,  2976,  1677,   723,   259,   159,  -756,
    -756,   154,   154,  -756,  -756,  -756,  -756,  -756,  2099,  -756,
    -756,   337,   177,   177,  -756,   380,   452,   472,    -3,   192,
      35,   447,     4,  -756,  1315,   125,    13,   677,   443,  -756,
    -756,  1666,  1502,   485,  2099,  1666,  -756,  2099,  -756,  -756,
    -756,  -756,   255,  -756,  -756,   192,    36,  -756,  -756,  2099,
    -756,  -756,   254,   479,  -756,   480,  -756,   455,  -756,   177,
     462,  -756,   192,   255,   255,   470,  -756,   509,  -756,  1516,
    -756,  1692,   128,  2099,  -756,   522,  -756,   520,   481,  -756,
    -756,  -756,   192,   529,  1666,  -756,  2099,  -756,  2099,  -756,
      11,   447,    12,  2099,  -756,  -756,   552,  -756,   553,  -756,
    1983,   501,  -756,  -756,  -756,  -756,  1666,  -756,  -756,  -756,
    -756,  -756,  -756,  -756,  -756,   470,  -756,  -756,  -756,  -756,
     554,   531,  -756,  -756,  -756
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
     316,   330,   350,   377,     0,     0,     0,   279,     0,     0,
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
       0,     0,   309,     0,     0,     0,   280,     0,   284,   281,
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
    -756,  -756,  -123,   737,   -31,   -35,  -755,  -756,  -753,  -756,
     262,  -756,  -756,  -756,  -756,  -756,  -756,  -756,  -756,  -756,
    -756,  -756,  -756,  -726,  -756,  -756,   530,   -48,  -206,  -756,
    -756,   456,  -175,   434,  1717,   596,   -72,  1226,   607,   414,
     565,   998,  1453,   -63,  -242,  2150,     0,   244,   655,  -756,
    -162,  -756,    -9,  -147
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
      58,   128,   254,   249,   801,   264,   249,   136,    74,    58,
      87,    91,   359,   249,   105,   107,   109,   111,   814,    58,
     249,   249,   818,   347,   103,   103,   795,   796,   103,   -64,
     821,   766,    58,   103,   103,   115,   103,   116,   103,   249,
     266,   129,    58,   770,   130,   802,   822,   829,   348,   267,
     126,   127,   247,     2,     3,     4,     5,     6,     7,     8,
     767,     9,   639,   117,     7,   682,    10,   847,   250,   850,
     782,   800,   767,   827,    11,   803,   803,    58,   805,    12,
    -433,   104,   269,    87,   106,   854,   855,  -433,   287,   108,
     110,   118,   246,   862,   118,   338,   355,   339,  -447,   340,
     778,   341,   638,   779,   100,   787,    13,    14,    15,   352,
      16,    17,    18,    19,    20,    21,    22,   753,    23,    24,
      25,    26,    27,    28,    29,    30,   342,    58,   754,   767,
     290,    97,   767,    58,   767,    58,   343,   808,    98,    58,
     839,   291,   292,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,   157,    58,   158,   383,
     387,   391,   394,   397,   399,   404,   809,   164,   102,   840,
     755,   324,   325,   326,   428,   436,   441,   445,   449,   453,
     753,   316,    23,    24,    25,    26,   180,   258,   636,   259,
     473,   318,   319,   648,   486,   134,   758,   762,   497,   500,
     503,   506,   509,   511,   516,   135,   112,   253,   122,   116,
     113,   533,   536,   539,   542,   545,   548,   551,   554,   557,
     560,   563,   566,   571,   133,   578,   581,   584,   587,   590,
     593,   125,   599,   755,   772,   117,   123,   634,   190,   157,
     621,   158,   191,   139,    59,    23,    24,    25,    26,   192,
     193,   636,    75,    59,   191,    92,   291,   292,   157,   265,
     158,   192,   193,    59,   252,    58,   161,   162,   163,   164,
     651,   653,   655,   657,   659,   248,    59,   256,   645,   257,
     666,   668,   670,   672,   674,   676,    59,   646,   180,   327,
     679,   318,   319,   687,   691,   693,   695,   697,   699,   701,
     704,   708,   710,   712,   714,   716,   718,   721,    91,    91,
      91,    91,    91,    91,    91,   734,    91,    91,    91,    91,
     328,    59,   750,    23,    24,    25,    26,    58,   128,   636,
      58,   329,   288,   330,    77,     3,     4,     5,     6,     7,
       8,   231,     9,    78,     3,     4,   195,    10,   103,    82,
     231,   344,   182,   196,   197,    11,    83,    58,   185,    58,
      12,   357,   234,   235,   236,   237,   238,   239,   360,    12,
     640,    59,   642,   236,   237,   238,   239,    59,   243,    59,
     649,   751,   768,    59,   748,   244,   245,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
     635,    59,   752,   777,   771,    79,    30,   769,   774,   405,
     759,   775,   412,   776,    84,    85,   182,   203,   429,   437,
     442,   446,   450,   454,   647,     3,     4,     5,     6,     7,
       8,   222,     9,   231,   474,   182,   285,    10,   487,   183,
     184,   185,   780,    80,   789,    11,   781,   788,   517,   186,
      12,   790,   792,   101,   797,   785,   187,   188,    23,    24,
      25,    26,   241,   242,   636,   243,   798,   572,    23,    24,
      25,    26,   244,   245,   636,   799,   600,   604,   606,   608,
     610,   612,   614,   616,   622,   813,   182,   804,   816,   824,
     183,   184,   185,   762,   825,    79,    30,   826,     3,     4,
       5,     6,     7,     8,   828,     9,   331,   187,   188,    59,
      10,    80,   833,    23,    24,    25,    26,   333,    11,   636,
     263,   834,   182,    12,   231,   842,   183,   184,   185,   346,
     843,   315,   316,   317,   680,   345,   353,   688,   233,   848,
     844,   861,   318,   319,   705,   234,   235,   236,   237,   238,
     239,   722,   724,   726,   727,   728,   729,   730,   731,   735,
      92,    92,    92,    92,   857,   858,   863,   356,    79,    30,
     348,    59,   379,   361,    59,   791,   784,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     747,   378,   786,   251,   119,   124,   456,   241,   831,   362,
     243,    59,   819,    59,    67,   758,   758,   244,   245,     3,
       4,     5,     6,     7,     8,    69,     9,   763,   189,   864,
     820,    10,   311,   312,   313,   314,     3,     4,     0,    11,
     119,    82,     0,   189,    12,   638,     3,     0,    83,    58,
       0,    94,     0,     0,   119,   594,   764,    58,    95,     0,
       0,    12,   758,     0,     0,    60,   830,   832,   240,   241,
     242,    12,   243,    76,    60,     0,    93,   641,     0,   244,
     245,     0,   643,   644,    60,   200,   201,   202,   203,    79,
      30,     3,     4,     5,     6,     7,     8,    60,     9,   810,
       0,   194,     0,    10,     0,   195,     0,    60,     0,    80,
       0,    11,   196,   197,     0,     0,    12,     0,     3,     4,
       5,     6,     7,     8,     0,     9,   331,     0,   811,     0,
      10,     0,   198,   199,   200,   201,   202,   203,    11,     0,
       0,     0,    60,    12,     0,     0,   136,   209,   210,     0,
     136,   128,   794,   289,   231,   316,   317,     0,    58,     0,
       0,    79,    30,     0,   232,   318,   319,   794,   233,   765,
       0,   746,     0,     0,   749,   234,   235,   236,   237,   238,
     239,    58,    58,   132,    58,    58,     0,    58,    79,    30,
       0,     0,    60,     0,   140,   141,   142,   156,    60,   849,
      60,     0,     0,     0,    60,     0,     0,     0,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,   136,    60,    58,   198,   199,   200,   201,   202,   203,
     406,   408,   410,     0,    58,     0,    58,     0,    58,   430,
     438,     0,     0,    58,     0,     3,     4,     5,     6,     7,
       8,   376,     9,     0,     0,   475,    58,    10,     0,   488,
       0,   315,   316,   317,     0,    11,     0,     0,     0,   518,
      12,     1,   318,   319,     2,     3,     4,     5,     6,     7,
       8,     0,     9,   219,   220,   221,   222,    10,   573,   272,
     273,   274,   203,    59,     0,    11,     0,   601,     0,     0,
      12,    59,     0,     0,     0,   623,   625,   627,   307,   631,
     633,     0,   308,     0,     0,    79,    30,     0,     0,   309,
     310,   311,   312,   313,   314,     0,     0,    13,    14,    15,
      60,    16,    17,    18,    19,    20,    21,    22,     0,    23,
      24,    25,    26,    27,    28,    29,    30,     0,     0,   217,
     218,   219,   220,   221,   222,   681,   189,     0,   689,   224,
     189,     0,     0,     0,   189,   706,   225,   226,   227,   228,
     229,   230,   723,   725,   725,   725,   725,   725,   725,   725,
     736,   737,   738,   739,   740,   270,   271,   272,   273,   274,
     203,     0,    60,     0,     0,    60,   275,   276,   277,   189,
     278,   279,    59,     0,   157,     0,   158,   189,    55,     0,
     159,   160,   161,   162,   163,   164,     0,    55,     0,    89,
       0,     0,    60,     0,    60,    59,    59,    55,    59,    59,
       0,    59,     0,   189,   180,   189,     0,   189,     0,   189,
      55,   189,     0,   189,   217,   218,   219,   220,   221,   222,
      55,   127,   189,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,   261,   773,   189,    10,    59,   280,   281,
     282,   283,   284,   285,    11,     0,     0,     0,    59,    12,
      59,     0,    59,   783,     0,    55,     0,    59,     0,     0,
       0,    80,     0,     0,     0,   189,    89,     0,     0,     0,
      59,   322,   323,   324,   325,   326,    13,    14,    15,     0,
      16,    17,    18,    19,    20,    21,    22,   263,    23,    24,
      25,    26,    27,    28,    29,    30,     0,     0,   240,   241,
     242,     0,   243,     0,     0,    55,     0,     0,     0,   244,
     245,    55,     0,    55,     0,     0,     0,    55,     0,     0,
     189,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,     0,    55,   280,   281,   282,   283,
     284,   285,     0,   401,   282,   283,   284,   285,   189,     0,
       0,     0,   425,   433,   262,   231,     0,     0,   807,     0,
       0,   812,   793,     0,     0,   232,     0,     0,   470,   233,
     479,   481,   483,     0,   189,     0,   234,   235,   236,   237,
     238,   239,   513,   823,     0,     0,     0,     0,   817,     0,
       0,   378,     3,     4,     5,     6,     7,     8,     0,     9,
       0,   568,     0,   836,    10,   838,    53,     0,     0,     0,
     596,     0,    11,     0,     0,    53,     0,    12,   618,     3,
       4,     5,     6,     7,    88,    53,     0,   841,     0,   345,
       0,    83,     0,     0,   860,     0,     0,     0,    53,    11,
     852,     0,   853,    55,    12,     0,     0,   856,    53,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     9,
       0,   116,    79,    30,    10,     0,     0,     0,   677,   683,
     684,   685,    11,     0,    60,     0,     0,    12,   702,     0,
       0,     0,    60,    53,     0,   719,    89,    89,    89,    89,
      89,    89,    89,   732,    89,    89,    89,    89,     0,     3,
       4,     5,     6,     7,     8,    55,     9,   806,    55,   260,
       0,    10,     0,     0,   322,   323,   324,   325,   326,    11,
       0,     0,    79,    30,    12,   275,   276,   277,     0,   278,
     279,     0,     0,    53,     0,    55,     0,    55,     0,    53,
       0,    53,     0,     0,     0,    53,     0,     0,     0,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,     0,    53,     0,   381,   385,   389,     0,    79,
      30,   129,     0,     0,   130,     0,     0,     0,     0,     0,
     424,   432,     0,    60,   322,   323,   324,   325,   326,   458,
     460,   462,   464,   466,   468,   275,     0,   477,     0,   278,
     279,   490,     0,     0,     0,     0,    60,    60,     0,    60,
      60,   520,    60,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,     0,   154,   155,     0,     0,     0,
     575,     0,     0,    56,     0,     0,     0,     0,     0,   603,
       0,     0,    56,     0,     0,     0,     0,     0,    60,   629,
       0,     0,    56,     0,   322,   323,   324,   325,   326,    60,
       0,    60,     0,    60,     0,    56,     0,     0,    60,   278,
     279,    53,     0,     0,     0,    56,     0,     0,     0,     0,
       0,    60,     0,   127,     0,     2,     3,     4,     5,     6,
       7,     8,     0,     9,     0,     0,   815,     0,    10,     0,
       3,     4,     5,     6,     7,     8,    11,     9,   835,     0,
      56,    12,    10,   322,   323,   324,   325,   326,     0,     0,
      11,     0,     0,     0,   275,    12,   277,     0,   278,   279,
       0,     0,     0,    53,     0,     0,    53,     0,    13,    14,
      15,     0,    16,    17,    18,    19,    20,    21,    22,     0,
      23,    24,    25,    26,    27,    28,    29,    30,     0,     0,
      56,     0,     0,    53,     0,    53,    56,     0,    56,     0,
      79,    30,    56,     0,     0,     0,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,     0,
      56,     0,     0,     0,   157,     0,   158,     0,   402,     0,
     159,   160,   161,   162,   163,   164,     0,   426,   434,   309,
     310,   311,   312,   313,   314,   172,   173,    55,     0,   176,
     177,   178,   179,   471,   180,    55,   260,   484,     0,   492,
     494,   270,   271,   272,   273,   274,   203,   514,     0,     0,
       0,     0,   275,   276,   277,     0,   278,   279,     0,   134,
       3,     4,     5,     6,     7,     8,   569,     9,     0,   135,
       0,     0,    10,     0,     0,   597,     0,     0,     0,     0,
      11,     0,     0,   619,     0,    12,     3,     4,     5,     6,
       7,     8,   308,     9,   837,     0,     0,     0,    10,   309,
     310,   311,   312,   313,   314,     0,    11,     0,    56,     0,
       0,    12,    13,    14,    15,    66,    16,    17,    18,    19,
      20,    21,    22,   262,    23,    24,    25,    26,    27,    28,
      29,    30,     0,     0,   307,     0,    55,     0,   308,   270,
     271,   272,   273,   274,   203,   309,   310,   311,   312,   313,
     314,     0,     0,     0,   278,   279,    79,    30,     0,    55,
      55,     0,    55,    55,     0,    55,     0,     0,     0,     0,
      56,     0,     0,    56,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,   358,
       0,    10,     0,     3,     4,     5,     6,    64,    88,    11,
      56,    55,    56,     0,    12,    83,     0,     0,     0,     0,
     332,     0,    55,    11,    55,     0,    55,     0,    12,     0,
       0,    55,   332,     0,   350,     0,     0,     0,     0,   332,
     354,    13,    14,    15,    55,    16,    17,    18,    19,    20,
      21,    22,     0,    23,    24,    25,    26,    27,    28,    29,
      30,     0,     0,     0,     0,    53,     0,     0,     0,     0,
       0,     0,     0,    53,     0,   332,   380,   384,   388,   392,
     395,   398,   400,   407,   409,   411,   413,   415,   417,   419,
     421,   423,   431,   439,   443,   447,   451,   455,     0,   332,
     457,   459,   461,   463,   465,   467,     0,   469,   476,   478,
     480,   482,   489,   491,   493,   495,   498,   501,   504,   507,
       0,   512,   519,   521,   523,   525,   527,   529,   531,   534,
     537,   540,   543,   546,   549,   552,   555,   558,   561,   564,
     567,   574,   576,   579,   582,   585,   588,   591,   332,   595,
     602,   605,   607,   609,   611,   613,   615,   617,   624,   626,
     628,   630,   632,   217,   218,   219,   220,   221,   222,   223,
     332,     0,     0,   224,    53,   332,   332,     0,     0,     0,
     225,   226,   227,   228,   229,   230,     0,     3,     4,     5,
       6,     7,     8,     0,     9,   859,     0,    53,    53,    10,
      53,    53,     0,    53,     0,     0,     0,    11,     0,     0,
       0,     0,    12,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,     0,    10,
       0,     3,     4,     5,     6,    64,     8,    11,     9,    53,
       0,     0,    12,    10,   217,   218,   219,   220,   221,   222,
      53,    11,    53,     0,    53,     0,    12,    79,    30,    53,
       0,     0,   332,   227,   228,   229,   230,     0,     0,    13,
      14,    15,    53,    16,    17,    18,    19,    20,    21,    22,
       0,    23,    24,    25,    26,    27,    28,    29,    30,     0,
       0,     0,    56,     0,     0,     0,     0,     0,     0,     0,
      56,    65,    30,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,     0,     0,    10,     0,     0,     0,     0,
       0,     0,     0,    11,   157,   255,   158,     0,    12,     0,
     159,   160,   161,   162,   163,   164,   165,   166,   167,     0,
     168,   169,   170,   171,     0,   172,   173,   174,   175,   176,
     177,   178,   179,     0,   180,     0,     0,     0,    73,     0,
      86,    90,    96,     0,     0,     0,     0,     0,     0,   157,
       0,   158,     0,    79,    30,   159,   160,   161,   162,   163,
     164,   165,   166,   167,     0,   168,   169,   170,   171,     0,
     172,   173,   174,   175,   176,   177,   178,   179,     0,   180,
       0,    56,     0,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,     0,   154,   155,     0,     0,     0,
       0,     0,     0,     0,    56,    56,     0,    56,    56,     0,
      56,     0,   268,    86,     0,     0,     0,     0,   286,     0,
     157,     0,   158,     0,   320,   321,   159,   160,   161,   162,
     163,   164,     0,   334,     0,     0,     0,     0,     0,     0,
       0,   172,   173,     0,     0,   334,    56,   351,     0,     0,
     180,     0,   334,   351,     0,     0,     0,    56,     0,    56,
       0,    56,     0,     0,     0,     0,    56,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    56,
       0,     0,     0,     0,     0,     0,     0,     0,   334,   382,
     386,   390,   393,   396,   351,   403,   351,   351,   351,   414,
     416,   418,   420,   422,   427,   435,   440,   444,   448,   452,
     351,     0,   334,   351,   351,   351,   351,   351,   351,     0,
     472,   351,   351,   351,   485,   351,   351,   351,   496,   499,
     502,   505,   508,   510,   515,   351,   522,   524,   526,   528,
     530,   532,   535,   538,   541,   544,   547,   550,   553,   556,
     559,   562,   565,   570,   351,   577,   580,   583,   586,   589,
     592,   334,   598,   351,   351,   351,   351,   351,   351,   351,
     620,   351,   351,   351,   351,   351,   198,   199,   200,   201,
     202,   203,     0,   334,     0,     0,     0,   206,   334,   334,
       0,   209,   210,   211,   212,   213,   214,   215,   216,     0,
     650,   652,   654,   656,   658,   660,   661,   662,   663,   664,
     665,   667,   669,   671,   673,   675,     0,     0,     0,     0,
     678,     0,     0,   686,   690,   692,   694,   696,   698,   700,
     703,   707,   709,   711,   713,   715,   717,   720,    90,    90,
      90,    90,    90,    90,    90,   733,    90,    90,    90,    90,
       0,     0,   741,   742,   743,   744,   745,     0,     0,     0,
       0,   332,     0,     0,   332,     0,     0,     0,     0,     0,
       0,   157,     0,   158,     0,   334,     0,   159,   160,   161,
     162,   163,   164,     0,   166,   167,   332,   168,   169,   170,
     171,     0,   172,   173,   174,   175,   176,   177,   178,   179,
       0,   180,     0,   157,     0,   158,   332,     0,   332,   159,
     160,   161,   162,   163,   164,     0,   166,     0,     0,   168,
     169,   170,   171,     0,   172,   173,   174,   175,   176,   177,
     178,   179,   157,   180,   158,     0,     0,   332,   159,   160,
     161,   162,   163,   164,     0,     0,     0,     0,   168,   169,
     170,   171,     0,   172,   173,   174,   175,   176,   177,   178,
     179,   157,   180,   158,     0,     0,     0,   159,   160,   161,
     162,   163,   164,     0,     0,     0,     0,     0,   169,   170,
     171,     0,   172,   173,   174,   175,   176,   177,   178,   179,
     157,   180,   158,     0,     0,     0,   159,   160,   161,   162,
     163,   164,     0,     0,     0,     0,     0,   169,     0,   171,
       0,   172,   173,   174,   175,   176,   177,   178,   179,   157,
     180,   158,     0,     0,     0,   159,   160,   161,   162,   163,
     164,     0,     0,     0,     0,     0,   169,     0,     0,     0,
     172,   173,   174,   175,   176,   177,   178,   179,   157,   180,
     158,     0,     0,     0,   159,   160,   161,   162,   163,   164,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   172,
     173,   174,   175,   176,   177,   178,   179,   260,   180,     0,
       0,     0,   198,   199,   200,   201,   202,   203,   204,     0,
       0,     0,   205,   206,   207,   208,     0,   209,   210,   211,
     212,   213,   214,   215,   216,   260,     0,     0,     0,     0,
     270,   271,   272,   273,   274,   203,   293,     0,     0,     0,
       0,   275,   276,   277,     0,   278,   279,   294,   295,   296,
     297,   298,   299,   261,     0,     0,     0,     0,   217,   218,
     219,   220,   221,   222,   223,     0,     0,     0,   224,     0,
       0,     0,     0,     0,     0,   225,   226,   227,   228,   229,
     230,   261,     0,     0,     0,     0,   280,   281,   282,   283,
     284,   285,   300,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   301,   302,   303,   304,   305,   306,   198,
     199,   200,   201,   202,   203,   204,     0,     0,     0,   205,
     206,   207,   208,     0,   209,   210,   211,   212,   213,   214,
     215,   216,   270,   271,   272,   273,   274,   203,   293,     0,
       0,     0,     0,   275,   276,   277,     0,   278,   279,   294,
     295,   296,   297,   298,   299,   198,   199,   200,   201,   202,
     203,     0,     0,     0,     0,   205,   206,   207,   208,     0,
     209,   210,   211,   212,   213,   214,   215,   216,   270,   271,
     272,   273,   274,   203,     0,     0,     0,     0,     0,   275,
     276,   277,     0,   278,   279,   294,   295,   296,   297,   298,
     299,     0,     0,     0,     0,   198,   199,   200,   201,   202,
     203,     0,     0,     0,   334,     0,   206,   334,   208,     0,
     209,   210,   211,   212,   213,   214,   215,   216,   198,   199,
     200,   201,   202,   203,     0,     0,     0,     0,     0,   334,
       0,     0,     0,   209,   210,   211,   212,   213,   214,   215,
     216,   280,   281,   282,   283,   284,   285,   300,     0,   334,
       0,   334,   198,   199,   200,   201,   202,   203,   301,   302,
     303,   304,   305,   306,     0,     0,     0,   209,   210,     0,
       0,   213,   214,   215,   216,     0,     0,     0,     0,     0,
     334,   280,   281,   282,   283,   284,   285,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   301,   302,
     303,   304,   305,   306
  };

  const short
   Parser ::yycheck_[] =
  {
       0,    32,    65,     9,   759,    77,     9,    42,     8,     9,
      10,    11,   135,     9,    23,    24,    25,    26,   771,    19,
       9,     9,   775,    14,    11,    11,   752,   753,    11,     9,
     785,    12,    32,    11,    11,    11,    11,    13,    11,     9,
       3,     0,    42,    12,     3,    10,    10,   802,    39,    12,
       0,     1,    61,     3,     4,     5,     6,     7,     8,     9,
      41,    11,    42,    39,     8,     9,    16,   822,    74,   824,
      40,    74,    41,   799,    24,    40,    40,    77,    74,    29,
      67,    67,    82,    83,    67,    74,    74,    74,    88,    67,
      67,    67,    67,   846,    67,   104,   127,   106,    74,   108,
      12,   110,   249,    12,     9,    12,    56,    57,    58,   118,
      60,    61,    62,    63,    64,    65,    66,     3,    68,    69,
      70,    71,    72,    73,    74,    75,     3,   127,    14,    41,
      21,    74,    41,   133,    41,   135,    13,    12,    74,   139,
      12,    32,    33,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,     9,   157,    11,   159,
     160,   161,   162,   163,   164,   165,    41,    20,    74,    41,
      56,    17,    18,    19,   174,   175,   176,   177,   178,   179,
       3,    22,    68,    69,    70,    71,    39,    38,    74,    40,
     190,    32,    33,   265,   194,     3,   343,   344,   198,   199,
     200,   201,   202,   203,   204,    13,    74,    11,    11,    13,
      74,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,     9,   225,   226,   227,   228,   229,
     230,     0,   232,    56,   357,    39,    39,   246,    21,     9,
     240,    11,    25,     9,     0,    68,    69,    70,    71,    32,
      33,    74,     8,     9,    25,    11,    32,    33,     9,    40,
      11,    32,    33,    19,    10,   265,    17,    18,    19,    20,
     270,   271,   272,   273,   274,    67,    32,    10,     3,    10,
     280,   281,   282,   283,   284,   285,    42,    12,    39,    42,
     290,    32,    33,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
      40,    77,   331,    68,    69,    70,    71,   327,   359,    74,
     330,    74,    88,    42,     3,     4,     5,     6,     7,     8,
       9,    11,    11,    12,     4,     5,    25,    16,    11,     9,
      11,     9,    11,    32,    33,    24,    16,   357,    17,   359,
      29,    13,    32,    33,    34,    35,    36,    37,    61,    29,
       9,   127,    10,    34,    35,    36,    37,   133,    25,   135,
      12,    12,    74,   139,    41,    32,    33,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
      10,   157,    13,    40,    10,    74,    75,    14,     9,   165,
      10,    10,   168,    10,    74,    75,    11,    20,   174,   175,
     176,   177,   178,   179,     3,     4,     5,     6,     7,     8,
       9,    20,    11,    11,   190,    11,    20,    16,   194,    15,
      16,    17,    12,     9,    38,    24,    10,    10,   204,    25,
      29,    12,     8,    19,    74,    10,    32,    33,    68,    69,
      70,    71,    22,    23,    74,    25,    14,   223,    68,    69,
      70,    71,    32,    33,    74,     3,   232,   233,   234,   235,
     236,   237,   238,   239,   240,    42,    11,    40,     3,    10,
      15,    16,    17,   640,    14,    74,    75,    42,     4,     5,
       6,     7,     8,     9,    42,    11,    12,    32,    33,   265,
      16,    77,    42,    68,    69,    70,    71,   103,    24,    74,
      10,    12,    11,    29,    11,     3,    15,    16,    17,   115,
      10,    21,    22,    23,   290,    41,   122,   293,    25,    10,
      59,    40,    32,    33,   300,    32,    33,    34,    35,    36,
      37,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,    12,    12,    12,   133,    74,    75,
      39,   327,   158,   139,   330,   647,   639,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     328,   157,   640,    63,    29,    30,   182,    22,   804,   143,
      25,   357,   777,   359,     8,   752,   753,    32,    33,     4,
       5,     6,     7,     8,     9,     8,    11,    12,    53,   861,
     782,    16,    34,    35,    36,    37,     4,     5,    -1,    24,
      65,     9,    -1,    68,    29,   782,     4,    -1,    16,   639,
      -1,     9,    -1,    -1,    79,   231,    41,   647,    16,    -1,
      -1,    29,   799,    -1,    -1,     0,   803,   804,    21,    22,
      23,    29,    25,     8,     9,    -1,    11,   253,    -1,    32,
      33,    -1,   258,   259,    19,    17,    18,    19,    20,    74,
      75,     4,     5,     6,     7,     8,     9,    32,    11,    12,
      -1,    21,    -1,    16,    -1,    25,    -1,    42,    -1,   265,
      -1,    24,    32,    33,    -1,    -1,    29,    -1,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    41,    -1,
      16,    -1,    15,    16,    17,    18,    19,    20,    24,    -1,
      -1,    -1,    77,    29,    -1,    -1,   771,    30,    31,    -1,
     775,   772,   751,    88,    11,    22,    23,    -1,   748,    -1,
      -1,    74,    75,    -1,    21,    32,    33,   766,    25,   345,
      -1,   327,    -1,    -1,   330,    32,    33,    34,    35,    36,
      37,   771,   772,    36,   774,   775,    -1,   777,    74,    75,
      -1,    -1,   127,    -1,    47,    48,    49,    50,   133,   824,
     135,    -1,    -1,    -1,   139,    -1,    -1,    -1,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   846,   157,   813,    15,    16,    17,    18,    19,    20,
     165,   166,   167,    -1,   824,    -1,   826,    -1,   828,   174,
     175,    -1,    -1,   833,    -1,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,   190,   846,    16,    -1,   194,
      -1,    21,    22,    23,    -1,    24,    -1,    -1,    -1,   204,
      29,     0,    32,    33,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    17,    18,    19,    20,    16,   223,    17,
      18,    19,    20,   639,    -1,    24,    -1,   232,    -1,    -1,
      29,   647,    -1,    -1,    -1,   240,   241,   242,    21,   244,
     245,    -1,    25,    -1,    -1,    74,    75,    -1,    -1,    32,
      33,    34,    35,    36,    37,    -1,    -1,    56,    57,    58,
     265,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,    15,
      16,    17,    18,    19,    20,   290,   381,    -1,   293,    25,
     385,    -1,    -1,    -1,   389,   300,    32,    33,    34,    35,
      36,    37,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,    15,    16,    17,    18,    19,
      20,    -1,   327,    -1,    -1,   330,    26,    27,    28,   424,
      30,    31,   748,    -1,     9,    -1,    11,   432,     0,    -1,
      15,    16,    17,    18,    19,    20,    -1,     9,    -1,    11,
      -1,    -1,   357,    -1,   359,   771,   772,    19,   774,   775,
      -1,   777,    -1,   458,    39,   460,    -1,   462,    -1,   464,
      32,   466,    -1,   468,    15,    16,    17,    18,    19,    20,
      42,     1,   477,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    10,    14,   490,    16,   813,    15,    16,
      17,    18,    19,    20,    24,    -1,    -1,    -1,   824,    29,
     826,    -1,   828,   639,    -1,    77,    -1,   833,    -1,    -1,
      -1,   647,    -1,    -1,    -1,   520,    88,    -1,    -1,    -1,
     846,    15,    16,    17,    18,    19,    56,    57,    58,    -1,
      60,    61,    62,    63,    64,    65,    66,    10,    68,    69,
      70,    71,    72,    73,    74,    75,    -1,    -1,    21,    22,
      23,    -1,    25,    -1,    -1,   127,    -1,    -1,    -1,    32,
      33,   133,    -1,   135,    -1,    -1,    -1,   139,    -1,    -1,
     575,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,   157,    15,    16,    17,    18,
      19,    20,    -1,   165,    17,    18,    19,    20,   603,    -1,
      -1,    -1,   174,   175,    10,    11,    -1,    -1,   764,    -1,
      -1,   767,   748,    -1,    -1,    21,    -1,    -1,   190,    25,
     192,   193,   194,    -1,   629,    -1,    32,    33,    34,    35,
      36,    37,   204,   789,    -1,    -1,    -1,    -1,   774,    -1,
      -1,   777,     4,     5,     6,     7,     8,     9,    -1,    11,
      -1,   223,    -1,   809,    16,   811,     0,    -1,    -1,    -1,
     232,    -1,    24,    -1,    -1,     9,    -1,    29,   240,     4,
       5,     6,     7,     8,     9,    19,    -1,   813,    -1,    41,
      -1,    16,    -1,    -1,   840,    -1,    -1,    -1,    32,    24,
     826,    -1,   828,   265,    29,    -1,    -1,   833,    42,    -1,
      -1,    -1,     4,     5,     6,     7,     8,     9,    -1,    11,
      -1,    13,    74,    75,    16,    -1,    -1,    -1,   290,   291,
     292,   293,    24,    -1,   639,    -1,    -1,    29,   300,    -1,
      -1,    -1,   647,    77,    -1,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,    -1,     4,
       5,     6,     7,     8,     9,   327,    11,    12,   330,    10,
      -1,    16,    -1,    -1,    15,    16,    17,    18,    19,    24,
      -1,    -1,    74,    75,    29,    26,    27,    28,    -1,    30,
      31,    -1,    -1,   127,    -1,   357,    -1,   359,    -1,   133,
      -1,   135,    -1,    -1,    -1,   139,    -1,    -1,    -1,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    -1,   157,    -1,   159,   160,   161,    -1,    74,
      75,     0,    -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,
     174,   175,    -1,   748,    15,    16,    17,    18,    19,   183,
     184,   185,   186,   187,   188,    26,    -1,   191,    -1,    30,
      31,   195,    -1,    -1,    -1,    -1,   771,   772,    -1,   774,
     775,   205,   777,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    -1,    -1,    -1,
     224,    -1,    -1,     0,    -1,    -1,    -1,    -1,    -1,   233,
      -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,   813,   243,
      -1,    -1,    19,    -1,    15,    16,    17,    18,    19,   824,
      -1,   826,    -1,   828,    -1,    32,    -1,    -1,   833,    30,
      31,   265,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,   846,    -1,     1,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    -1,    -1,    14,    -1,    16,    -1,
       4,     5,     6,     7,     8,     9,    24,    11,    12,    -1,
      77,    29,    16,    15,    16,    17,    18,    19,    -1,    -1,
      24,    -1,    -1,    -1,    26,    29,    28,    -1,    30,    31,
      -1,    -1,    -1,   327,    -1,    -1,   330,    -1,    56,    57,
      58,    -1,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    -1,    -1,
     127,    -1,    -1,   357,    -1,   359,   133,    -1,   135,    -1,
      74,    75,   139,    -1,    -1,    -1,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
     157,    -1,    -1,    -1,     9,    -1,    11,    -1,   165,    -1,
      15,    16,    17,    18,    19,    20,    -1,   174,   175,    32,
      33,    34,    35,    36,    37,    30,    31,   639,    -1,    34,
      35,    36,    37,   190,    39,   647,    10,   194,    -1,   196,
     197,    15,    16,    17,    18,    19,    20,   204,    -1,    -1,
      -1,    -1,    26,    27,    28,    -1,    30,    31,    -1,     3,
       4,     5,     6,     7,     8,     9,   223,    11,    -1,    13,
      -1,    -1,    16,    -1,    -1,   232,    -1,    -1,    -1,    -1,
      24,    -1,    -1,   240,    -1,    29,     4,     5,     6,     7,
       8,     9,    25,    11,    12,    -1,    -1,    -1,    16,    32,
      33,    34,    35,    36,    37,    -1,    24,    -1,   265,    -1,
      -1,    29,    56,    57,    58,     8,    60,    61,    62,    63,
      64,    65,    66,    10,    68,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,    21,    -1,   748,    -1,    25,    15,
      16,    17,    18,    19,    20,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    30,    31,    74,    75,    -1,   771,
     772,    -1,   774,   775,    -1,   777,    -1,    -1,    -1,    -1,
     327,    -1,    -1,   330,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    -1,    -1,    14,
      -1,    16,    -1,     4,     5,     6,     7,     8,     9,    24,
     357,   813,   359,    -1,    29,    16,    -1,    -1,    -1,    -1,
     103,    -1,   824,    24,   826,    -1,   828,    -1,    29,    -1,
      -1,   833,   115,    -1,   117,    -1,    -1,    -1,    -1,   122,
     123,    56,    57,    58,   846,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    -1,   639,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   647,    -1,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,   182,
     183,   184,   185,   186,   187,   188,    -1,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
      -1,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    15,    16,    17,    18,    19,    20,    21,
     253,    -1,    -1,    25,   748,   258,   259,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    37,    -1,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    -1,   771,   772,    16,
     774,   775,    -1,   777,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    -1,    -1,    -1,    16,
      -1,     4,     5,     6,     7,     8,     9,    24,    11,   813,
      -1,    -1,    29,    16,    15,    16,    17,    18,    19,    20,
     824,    24,   826,    -1,   828,    -1,    29,    74,    75,   833,
      -1,    -1,   345,    34,    35,    36,    37,    -1,    -1,    56,
      57,    58,   846,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,   639,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     647,    74,    75,     4,     5,     6,     7,     8,     9,    -1,
      11,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,     9,    10,    11,    -1,    29,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      25,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    39,    -1,    -1,    -1,     8,    -1,
      10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      -1,    11,    -1,    74,    75,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    25,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    39,
      -1,   748,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   771,   772,    -1,   774,   775,    -1,
     777,    -1,    82,    83,    -1,    -1,    -1,    -1,    88,    -1,
       9,    -1,    11,    -1,    94,    95,    15,    16,    17,    18,
      19,    20,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,   115,   813,   117,    -1,    -1,
      39,    -1,   122,   123,    -1,    -1,    -1,   824,    -1,   826,
      -1,   828,    -1,    -1,    -1,    -1,   833,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   846,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,    -1,   182,   183,   184,   185,   186,   187,   188,    -1,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    15,    16,    17,    18,
      19,    20,    -1,   253,    -1,    -1,    -1,    26,   258,   259,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,    -1,    -1,    -1,    -1,
     290,    -1,    -1,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
      -1,    -1,   322,   323,   324,   325,   326,    -1,    -1,    -1,
      -1,   764,    -1,    -1,   767,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    11,    -1,   345,    -1,    15,    16,    17,
      18,    19,    20,    -1,    22,    23,   789,    25,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    39,    -1,     9,    -1,    11,   809,    -1,   811,    15,
      16,    17,    18,    19,    20,    -1,    22,    -1,    -1,    25,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,     9,    39,    11,    -1,    -1,   840,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    25,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,     9,    39,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
       9,    39,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,     9,
      39,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,     9,    39,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    10,    39,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    25,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    10,    -1,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
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
      37,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,   764,    -1,    26,   767,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,   789,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    15,    16,    17,    18,    19,    20,    21,    -1,   809,
      -1,   811,    15,    16,    17,    18,    19,    20,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    30,    31,    -1,
      -1,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
     840,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37
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
      10,    10,    10,    10,   113,    40,     3,    12,   122,   123,
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
       9,   116,    10,   116,   116,     3,    12,     3,   113,    12,
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
      12,   113,     8,   110,   129,   100,   100,    74,    14,     3,
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
       0,   221,   221,   222,   224,   225,   226,   229,   230,   233,
     234,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   251,   252,   253,   254,   255,   258,   259,
     262,   263,   267,   269,   270,   274,   275,   276,   278,   279,
     283,   287,   289,   291,   293,   296,   298,   299,   301,   302,
     305,   306,   307,   309,   310,   311,   312,   314,   315,   316,
     320,   321,   322,   323,   325,   327,   328,   329,   331,   332,
     336,   340,   341,   342,   343,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   364,
     365,   369,   370,   371,   372,   373,   374,   375,   376,   379,
     380,   381,   382,   383,   385,   386,   388,   389,   390,   391,
     392,   394,   395,   396,   397,   399,   400,   401,   403,   404,
     405,   407,   408,   409,   410,   411,   412,   413,   414,   416,
     417,   418,   419,   420,   422,   423,   424,   425,   426,   428,
     429,   430,   431,   432,   433,   434,   435,   437,   438,   439,
     440,   441,   442,   443,   444,   446,   447,   448,   450,   451,
     452,   454,   455,   456,   457,   458,   459,   460,   462,   463,
     464,   465,   466,   467,   468,   470,   471,   472,   473,   474,
     475,   476,   478,   479,   480,   481,   482,   483,   484,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   522,   523,   524,   526,   527,   528,   530,
     531,   532,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   551,   552,
     553,   555,   556,   557,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   586,   587,
     588,   589,   590,   592,   593,   594,   598,   599,   600,   601,
     603,   604,   606,   607,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   624,   625,   629,   630,
     632,   633,   635,   636,   640,   641,   642,   643,   644,   645,
     646,   647,   648,   649,   650,   651,   652,   653,   657,   658,
     659,   660,   661,   662,   663,   664,   665,   666,   667,   668,
     669,   670,   671,   672,   673,   674,   675,   676,   677,   681,
     682,   683,   684,   685,   686,   687,   688,   689,   690,   691,
     692,   693,   694,   695,   696,   697,   698,   699,   700,   701,
     702,   703,   704,   705,   706,   707,   711,   712,   713,   714,
     715,   717,   718,   719,   720,   721,   722,   723,   725,   726,
     727,   728,   729,   730,   731,   733,   734,   735,   736,   737,
     739,   740,   741,   742,   743,   745,   746,   747,   748,   749,
     751,   752,   753,   754,   755,   757,   761,   762,   764,   765,
     769,   770,   771,   772,   773,   774,   775,   776,   777,   778,
     779,   780,   782,   783,   784,   785,   789,   790,   791,   792,
     793,   794,   795,   796,   797,   798,   799,   800,   801,   802
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
#line 4555 "frontend/parser.cpp"

#line 805 "frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    auto msg = std::to_string(scanner->loc->begin.line) + ":" + std::to_string(scanner->loc->begin.column) + ": " + err_message;
    scanner->fatal_error(ptc::diag::ERR_SYNTAX, msg);
}
