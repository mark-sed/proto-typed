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
#line 1119 "frontend/parser.cpp"
    break;

  case 4: // stmt: stmts
#line 224 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1125 "frontend/parser.cpp"
    break;

  case 5: // stmt: stmt stmts
#line 225 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1131 "frontend/parser.cpp"
    break;

  case 6: // stmt: stmt error stmts
#line 226 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1137 "frontend/parser.cpp"
    break;

  case 9: // stmts: "terminator (\\n or ;)"
#line 233 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = nullptr; }
#line 1143 "frontend/parser.cpp"
    break;

  case 10: // stmts: stmts_ne
#line 234 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1149 "frontend/parser.cpp"
    break;

  case 11: // stmts_ne: set stmt_end
#line 236 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1155 "frontend/parser.cpp"
    break;

  case 12: // stmts_ne: vardecl stmt_end
#line 237 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1161 "frontend/parser.cpp"
    break;

  case 13: // stmts_ne: vardef stmt_end
#line 238 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1167 "frontend/parser.cpp"
    break;

  case 14: // stmts_ne: import stmt_end
#line 239 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1173 "frontend/parser.cpp"
    break;

  case 16: // stmts_ne: if
#line 241 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1179 "frontend/parser.cpp"
    break;

  case 17: // stmts_ne: while
#line 242 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1185 "frontend/parser.cpp"
    break;

  case 19: // stmts_ne: struct
#line 244 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1191 "frontend/parser.cpp"
    break;

  case 20: // stmts_ne: function
#line 245 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1197 "frontend/parser.cpp"
    break;

  case 21: // stmts_ne: flowctl stmt_end
#line 246 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1203 "frontend/parser.cpp"
    break;

  case 22: // stmts_ne: expr stmt_end
#line 247 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1209 "frontend/parser.cpp"
    break;

  case 23: // block: "{" "}"
#line 251 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1215 "frontend/parser.cpp"
    break;

  case 24: // block: "{" stmt "}"
#line 252 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1221 "frontend/parser.cpp"
    break;

  case 25: // block: "terminator (\\n or ;)" "{" stmt "}"
#line 253 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1227 "frontend/parser.cpp"
    break;

  case 26: // block: "{" stmt "}" "terminator (\\n or ;)"
#line 254 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1233 "frontend/parser.cpp"
    break;

  case 27: // block: "terminator (\\n or ;)" "{" stmt "}" "terminator (\\n or ;)"
#line 255 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1239 "frontend/parser.cpp"
    break;

  case 28: // body: stmts_ne
#line 258 "frontend/parser.yy"
                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1245 "frontend/parser.cpp"
    break;

  case 29: // body: block
#line 259 "frontend/parser.yy"
                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1251 "frontend/parser.cpp"
    break;

  case 30: // import: "import" id_list
#line 263 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::IR * > () = scanner->parseImports(yystack_[0].value.as < std::vector<std::string>  > ()); }
#line 1257 "frontend/parser.cpp"
    break;

  case 31: // id_list: "identifier"
#line 265 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseImportName(yystack_[0].value.as < std::string > ()); }
#line 1263 "frontend/parser.cpp"
    break;

  case 32: // id_list: "identifier" "," id_list
#line 266 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseAddImportName(yystack_[0].value.as < std::vector<std::string>  > (), yystack_[2].value.as < std::string > ()); }
#line 1269 "frontend/parser.cpp"
    break;

  case 33: // flowctl: "break"
#line 270 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseBreak(); }
#line 1275 "frontend/parser.cpp"
    break;

  case 34: // flowctl: "continue"
#line 271 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseContinue(); }
#line 1281 "frontend/parser.cpp"
    break;

  case 35: // flowctl: return
#line 272 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1287 "frontend/parser.cpp"
    break;

  case 36: // return: "return"
#line 274 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(nullptr); }
#line 1293 "frontend/parser.cpp"
    break;

  case 37: // return: "return" expr
#line 275 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1299 "frontend/parser.cpp"
    break;

  case 39: // while: "while" "(" expr ")" body
#line 283 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::IR * > () = scanner->parseWhile(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1305 "frontend/parser.cpp"
    break;

  case 41: // if: "if" "(" expr ")" body else
#line 290 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::IR * > () = scanner->parseIfStmt(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1311 "frontend/parser.cpp"
    break;

  case 42: // else: "else" body
#line 292 "frontend/parser.yy"
                    { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1317 "frontend/parser.cpp"
    break;

  case 43: // else: %empty
#line 293 "frontend/parser.yy"
                    { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1323 "frontend/parser.cpp"
    break;

  case 44: // struct: "'struct'" "identifier" "{" "}"
#line 297 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[2].value.as < std::string > (), std::vector<ptc::ir::IR *>{}); }
#line 1329 "frontend/parser.cpp"
    break;

  case 45: // struct: "'struct'" "identifier" "{" decllist "}"
#line 298 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1335 "frontend/parser.cpp"
    break;

  case 46: // struct: "'struct'" "identifier" "terminator (\\n or ;)" "{" decllist "}"
#line 299 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[4].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1341 "frontend/parser.cpp"
    break;

  case 48: // decllist: "terminator (\\n or ;)" decllist
#line 302 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1347 "frontend/parser.cpp"
    break;

  case 49: // decllist: declistval "terminator (\\n or ;)"
#line 303 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[1].value.as < ptc::ir::IR * > (), std::vector<ptc::ir::IR *>{}); }
#line 1353 "frontend/parser.cpp"
    break;

  case 50: // decllist: declistval "terminator (\\n or ;)" decllist
#line 304 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[2].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1359 "frontend/parser.cpp"
    break;

  case 51: // declistval: type "identifier"
#line 306 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > (), nullptr); }
#line 1365 "frontend/parser.cpp"
    break;

  case 52: // declistval: type "identifier" "=" expr
#line 307 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1371 "frontend/parser.cpp"
    break;

  case 54: // function: type fun_id "(" ")" block
#line 312 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1377 "frontend/parser.cpp"
    break;

  case 55: // function: type fun_id "(" funargs ")" block
#line 313 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[5].value.as < ptc::ir::IR * > (), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1383 "frontend/parser.cpp"
    break;

  case 56: // function: "'void'" fun_id "(" ")" block
#line 314 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1389 "frontend/parser.cpp"
    break;

  case 57: // function: "'void'" fun_id "(" funargs ")" block
#line 315 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1395 "frontend/parser.cpp"
    break;

  case 58: // fun_id: "identifier"
#line 317 "frontend/parser.yy"
            { scanner->enterFunScope(); yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1401 "frontend/parser.cpp"
    break;

  case 59: // funargs: type "identifier"
#line 319 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseFunParam(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1407 "frontend/parser.cpp"
    break;

  case 61: // funargs: funargs "," type "identifier"
#line 321 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseAddFunParam(yystack_[3].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1413 "frontend/parser.cpp"
    break;

  case 64: // vardecl: type "identifier"
#line 328 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1419 "frontend/parser.cpp"
    break;

  case 65: // vardef: type "identifier" "=" struct_val
#line 332 "frontend/parser.yy"
         { yylhs.value.as < ptc::ir::IR * > () = yystack_[3].value.as < ptc::ir::IR * > (); }
#line 1425 "frontend/parser.cpp"
    break;

  case 66: // vardef: type "identifier" "=" expr
#line 333 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1431 "frontend/parser.cpp"
    break;

  case 69: // set: expr "++=" expr
#line 339 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1437 "frontend/parser.cpp"
    break;

  case 70: // set: expr "**=" expr
#line 340 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1443 "frontend/parser.cpp"
    break;

  case 71: // set: expr "%=" expr
#line 341 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1449 "frontend/parser.cpp"
    break;

  case 72: // set: expr "/=" expr
#line 342 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1455 "frontend/parser.cpp"
    break;

  case 73: // set: expr "*=" expr
#line 343 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1461 "frontend/parser.cpp"
    break;

  case 74: // set: expr "-=" expr
#line 344 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1467 "frontend/parser.cpp"
    break;

  case 75: // set: expr "+=" expr
#line 345 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1473 "frontend/parser.cpp"
    break;

  case 76: // set: expr "&=" expr
#line 346 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1479 "frontend/parser.cpp"
    break;

  case 77: // set: expr "|=" expr
#line 347 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1485 "frontend/parser.cpp"
    break;

  case 78: // set: expr "^=" expr
#line 348 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1491 "frontend/parser.cpp"
    break;

  case 79: // set: expr "<<=" expr
#line 349 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1497 "frontend/parser.cpp"
    break;

  case 80: // set: expr ">>=" expr
#line 350 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1503 "frontend/parser.cpp"
    break;

  case 81: // set: expr "=" expr
#line 351 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1509 "frontend/parser.cpp"
    break;

  case 82: // set: expr "=" set
#line 352 "frontend/parser.yy"
      { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1515 "frontend/parser.cpp"
    break;

  case 83: // callarglist: expr
#line 356 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseFunCallArg(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1521 "frontend/parser.cpp"
    break;

  case 84: // callarglist: expr "," callarglist
#line 357 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddFunCallArg(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[2].value.as < ptc::ir::Expr * > ()); }
#line 1527 "frontend/parser.cpp"
    break;

  case 85: // expr: expr_mat
#line 361 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = nullptr; }
#line 1533 "frontend/parser.cpp"
    break;

  case 86: // expr: expr_var
#line 362 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1539 "frontend/parser.cpp"
    break;

  case 87: // expr: expr_none
#line 363 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = nullptr; }
#line 1545 "frontend/parser.cpp"
    break;

  case 88: // expr: expr_struct
#line 364 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = nullptr; }
#line 1551 "frontend/parser.cpp"
    break;

  case 89: // expr: expr_int
#line 365 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 1557 "frontend/parser.cpp"
    break;

  case 90: // expr: expr_float
#line 366 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFloat(yystack_[0].value.as < double > ()); }
#line 1563 "frontend/parser.cpp"
    break;

  case 91: // expr: expr_str
#line 367 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseString(yystack_[0].value.as < std::string > ()); }
#line 1569 "frontend/parser.cpp"
    break;

  case 92: // expr: expr_bool
#line 368 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseBool(yystack_[0].value.as < bool > ()); }
#line 1575 "frontend/parser.cpp"
    break;

  case 93: // expr_var: "identifier"
#line 371 "frontend/parser.yy"
              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > ()); }
#line 1581 "frontend/parser.cpp"
    break;

  case 94: // expr_var: "external identifier"
#line 372 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > (), true); }
#line 1587 "frontend/parser.cpp"
    break;

  case 95: // expr_var: "-" "identifier"
#line 373 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1593 "frontend/parser.cpp"
    break;

  case 96: // expr_var: "-" "external identifier"
#line 374 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > (), true), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1599 "frontend/parser.cpp"
    break;

  case 97: // expr_var: "(" expr_var ")"
#line 375 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1605 "frontend/parser.cpp"
    break;

  case 98: // expr_var: expr_var "(" ")"
#line 377 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[2].value.as < ptc::ir::Expr * > (), std::vector<ptc::ir::Expr *>{}); }
#line 1611 "frontend/parser.cpp"
    break;

  case 99: // expr_var: expr_var "(" callarglist ")"
#line 378 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 1617 "frontend/parser.cpp"
    break;

  case 104: // expr_var: expr_var "[" int_val "]"
#line 384 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[3].value.as < ptc::ir::Expr * > (); }
#line 1623 "frontend/parser.cpp"
    break;

  case 108: // expr_var: expr_var slice
#line 389 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1629 "frontend/parser.cpp"
    break;

  case 109: // expr_var: "identifier" "." expr_var
#line 391 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1635 "frontend/parser.cpp"
    break;

  case 110: // expr_var: "external identifier" "." expr_var
#line 392 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseVar(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1641 "frontend/parser.cpp"
    break;

  case 111: // expr_var: expr_var "." expr_var
#line 393 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ACCESS)); }
#line 1647 "frontend/parser.cpp"
    break;

  case 113: // expr_var: expr_var "**" expr_float
#line 396 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1653 "frontend/parser.cpp"
    break;

  case 114: // expr_var: expr_var "**" expr_var
#line 397 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1659 "frontend/parser.cpp"
    break;

  case 115: // expr_var: expr_int "*" expr_var
#line 399 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1665 "frontend/parser.cpp"
    break;

  case 116: // expr_var: expr_float "*" expr_var
#line 400 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1671 "frontend/parser.cpp"
    break;

  case 117: // expr_var: expr_var "*" expr_int
#line 401 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1677 "frontend/parser.cpp"
    break;

  case 118: // expr_var: expr_var "*" expr_float
#line 402 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1683 "frontend/parser.cpp"
    break;

  case 121: // expr_var: expr_var "*" expr_mat
#line 405 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1689 "frontend/parser.cpp"
    break;

  case 122: // expr_var: expr_var "*" expr_var
#line 406 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1695 "frontend/parser.cpp"
    break;

  case 123: // expr_var: expr_int "/" expr_var
#line 408 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1701 "frontend/parser.cpp"
    break;

  case 124: // expr_var: expr_float "/" expr_var
#line 409 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1707 "frontend/parser.cpp"
    break;

  case 125: // expr_var: expr_var "/" expr_int
#line 410 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1713 "frontend/parser.cpp"
    break;

  case 126: // expr_var: expr_var "/" expr_float
#line 411 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1719 "frontend/parser.cpp"
    break;

  case 127: // expr_var: expr_var "/" expr_var
#line 412 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1725 "frontend/parser.cpp"
    break;

  case 128: // expr_var: expr_int "%" expr_var
#line 414 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1731 "frontend/parser.cpp"
    break;

  case 129: // expr_var: expr_float "%" expr_var
#line 415 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1737 "frontend/parser.cpp"
    break;

  case 130: // expr_var: expr_var "%" expr_int
#line 416 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1743 "frontend/parser.cpp"
    break;

  case 131: // expr_var: expr_var "%" expr_float
#line 417 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1749 "frontend/parser.cpp"
    break;

  case 132: // expr_var: expr_var "%" expr_var
#line 418 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1755 "frontend/parser.cpp"
    break;

  case 133: // expr_var: expr_int "+" expr_var
#line 420 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1761 "frontend/parser.cpp"
    break;

  case 134: // expr_var: expr_float "+" expr_var
#line 421 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1767 "frontend/parser.cpp"
    break;

  case 135: // expr_var: expr_var "+" expr_int
#line 422 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1773 "frontend/parser.cpp"
    break;

  case 136: // expr_var: expr_var "+" expr_float
#line 423 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1779 "frontend/parser.cpp"
    break;

  case 138: // expr_var: expr_var "+" expr_mat
#line 425 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1785 "frontend/parser.cpp"
    break;

  case 140: // expr_var: expr_var "+" expr_var
#line 427 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1791 "frontend/parser.cpp"
    break;

  case 141: // expr_var: expr_int "-" expr_var
#line 429 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1797 "frontend/parser.cpp"
    break;

  case 142: // expr_var: expr_float "-" expr_var
#line 430 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1803 "frontend/parser.cpp"
    break;

  case 143: // expr_var: expr_var "-" expr_int
#line 431 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1809 "frontend/parser.cpp"
    break;

  case 144: // expr_var: expr_var "-" expr_float
#line 432 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1815 "frontend/parser.cpp"
    break;

  case 146: // expr_var: expr_var "-" expr_mat
#line 434 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1821 "frontend/parser.cpp"
    break;

  case 148: // expr_var: expr_var "-" expr_var
#line 436 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1827 "frontend/parser.cpp"
    break;

  case 149: // expr_var: expr_int "<<" expr_var
#line 438 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 1833 "frontend/parser.cpp"
    break;

  case 150: // expr_var: expr_var "<<" expr_int
#line 439 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 1839 "frontend/parser.cpp"
    break;

  case 151: // expr_var: expr_var "<<" expr_var
#line 440 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 1845 "frontend/parser.cpp"
    break;

  case 152: // expr_var: expr_int ">>" expr_var
#line 442 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 1851 "frontend/parser.cpp"
    break;

  case 153: // expr_var: expr_var ">>" expr_int
#line 443 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 1857 "frontend/parser.cpp"
    break;

  case 154: // expr_var: expr_var ">>" expr_var
#line 444 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 1863 "frontend/parser.cpp"
    break;

  case 155: // expr_var: expr_int ">" expr_var
#line 446 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 1869 "frontend/parser.cpp"
    break;

  case 156: // expr_var: expr_float ">" expr_var
#line 447 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 1875 "frontend/parser.cpp"
    break;

  case 158: // expr_var: expr_var ">" expr_int
#line 449 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 1881 "frontend/parser.cpp"
    break;

  case 159: // expr_var: expr_var ">" expr_float
#line 450 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 1887 "frontend/parser.cpp"
    break;

  case 160: // expr_var: expr_var ">" expr_str
#line 451 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1893 "frontend/parser.cpp"
    break;

  case 161: // expr_var: expr_var ">" expr_var
#line 452 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 1899 "frontend/parser.cpp"
    break;

  case 162: // expr_var: expr_int ">=" expr_var
#line 454 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 1905 "frontend/parser.cpp"
    break;

  case 163: // expr_var: expr_float ">=" expr_var
#line 455 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 1911 "frontend/parser.cpp"
    break;

  case 165: // expr_var: expr_var ">=" expr_int
#line 457 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 1917 "frontend/parser.cpp"
    break;

  case 166: // expr_var: expr_var ">=" expr_float
#line 458 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 1923 "frontend/parser.cpp"
    break;

  case 167: // expr_var: expr_var ">=" expr_str
#line 459 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1929 "frontend/parser.cpp"
    break;

  case 168: // expr_var: expr_var ">=" expr_var
#line 460 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 1935 "frontend/parser.cpp"
    break;

  case 169: // expr_var: expr_int "<" expr_var
#line 462 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 1941 "frontend/parser.cpp"
    break;

  case 170: // expr_var: expr_float "<" expr_var
#line 463 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 1947 "frontend/parser.cpp"
    break;

  case 172: // expr_var: expr_var "<" expr_int
#line 465 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 1953 "frontend/parser.cpp"
    break;

  case 173: // expr_var: expr_var "<" expr_float
#line 466 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 1959 "frontend/parser.cpp"
    break;

  case 174: // expr_var: expr_var "<" expr_str
#line 467 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1965 "frontend/parser.cpp"
    break;

  case 175: // expr_var: expr_var "<" expr_var
#line 468 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 1971 "frontend/parser.cpp"
    break;

  case 176: // expr_var: expr_int "<=" expr_var
#line 470 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 1977 "frontend/parser.cpp"
    break;

  case 177: // expr_var: expr_float "<=" expr_var
#line 471 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 1983 "frontend/parser.cpp"
    break;

  case 179: // expr_var: expr_var "<=" expr_int
#line 473 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 1989 "frontend/parser.cpp"
    break;

  case 180: // expr_var: expr_var "<=" expr_float
#line 474 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 1995 "frontend/parser.cpp"
    break;

  case 181: // expr_var: expr_var "<=" expr_str
#line 475 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2001 "frontend/parser.cpp"
    break;

  case 182: // expr_var: expr_var "<=" expr_var
#line 476 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 2007 "frontend/parser.cpp"
    break;

  case 183: // expr_var: expr_int "==" expr_var
#line 478 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2013 "frontend/parser.cpp"
    break;

  case 184: // expr_var: expr_float "==" expr_var
#line 479 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2019 "frontend/parser.cpp"
    break;

  case 186: // expr_var: expr_bool "==" expr_var
#line 481 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2025 "frontend/parser.cpp"
    break;

  case 190: // expr_var: expr_var "==" expr_int
#line 485 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2031 "frontend/parser.cpp"
    break;

  case 191: // expr_var: expr_var "==" expr_float
#line 486 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2037 "frontend/parser.cpp"
    break;

  case 192: // expr_var: expr_var "==" expr_str
#line 487 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2043 "frontend/parser.cpp"
    break;

  case 193: // expr_var: expr_var "==" expr_bool
#line 488 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2049 "frontend/parser.cpp"
    break;

  case 194: // expr_var: expr_var "==" expr_none
#line 489 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2055 "frontend/parser.cpp"
    break;

  case 195: // expr_var: expr_var "==" expr_struct
#line 490 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2061 "frontend/parser.cpp"
    break;

  case 197: // expr_var: expr_var "==" expr_mat
#line 492 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2067 "frontend/parser.cpp"
    break;

  case 199: // expr_var: expr_var "==" expr_var
#line 494 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2073 "frontend/parser.cpp"
    break;

  case 200: // expr_var: expr_int "!=" expr_var
#line 496 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2079 "frontend/parser.cpp"
    break;

  case 201: // expr_var: expr_float "!=" expr_var
#line 497 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2085 "frontend/parser.cpp"
    break;

  case 207: // expr_var: expr_var "!=" expr_int
#line 503 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2091 "frontend/parser.cpp"
    break;

  case 208: // expr_var: expr_var "!=" expr_float
#line 504 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2097 "frontend/parser.cpp"
    break;

  case 209: // expr_var: expr_var "!=" expr_str
#line 505 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2103 "frontend/parser.cpp"
    break;

  case 210: // expr_var: expr_var "!=" expr_bool
#line 506 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2109 "frontend/parser.cpp"
    break;

  case 211: // expr_var: expr_var "!=" expr_none
#line 507 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2115 "frontend/parser.cpp"
    break;

  case 212: // expr_var: expr_var "!=" expr_struct
#line 508 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2121 "frontend/parser.cpp"
    break;

  case 214: // expr_var: expr_var "!=" expr_mat
#line 510 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2127 "frontend/parser.cpp"
    break;

  case 216: // expr_var: expr_var "!=" expr_var
#line 512 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2133 "frontend/parser.cpp"
    break;

  case 217: // expr_var: expr_int "&" expr_var
#line 514 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2139 "frontend/parser.cpp"
    break;

  case 218: // expr_var: expr_var "&" expr_int
#line 515 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2145 "frontend/parser.cpp"
    break;

  case 219: // expr_var: expr_var "&" expr_var
#line 516 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2151 "frontend/parser.cpp"
    break;

  case 220: // expr_var: expr_int "^" expr_var
#line 518 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2157 "frontend/parser.cpp"
    break;

  case 221: // expr_var: expr_var "^" expr_int
#line 519 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2163 "frontend/parser.cpp"
    break;

  case 222: // expr_var: expr_var "^" expr_var
#line 520 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2169 "frontend/parser.cpp"
    break;

  case 223: // expr_var: expr_int "|" expr_var
#line 522 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2175 "frontend/parser.cpp"
    break;

  case 224: // expr_var: expr_var "|" expr_int
#line 523 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2181 "frontend/parser.cpp"
    break;

  case 225: // expr_var: expr_var "|" expr_var
#line 524 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2187 "frontend/parser.cpp"
    break;

  case 240: // expr_var: expr_var "in" expr_str
#line 540 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2193 "frontend/parser.cpp"
    break;

  case 241: // expr_var: expr_var "in" expr_var
#line 541 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2199 "frontend/parser.cpp"
    break;

  case 242: // expr_var: expr_bool "and" expr_var
#line 543 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2205 "frontend/parser.cpp"
    break;

  case 243: // expr_var: expr_var "and" expr_bool
#line 544 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2211 "frontend/parser.cpp"
    break;

  case 244: // expr_var: expr_var "and" expr_var
#line 545 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2217 "frontend/parser.cpp"
    break;

  case 245: // expr_var: expr_bool "or" expr_var
#line 547 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2223 "frontend/parser.cpp"
    break;

  case 246: // expr_var: expr_var "or" expr_bool
#line 548 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2229 "frontend/parser.cpp"
    break;

  case 247: // expr_var: expr_var "or" expr_var
#line 549 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2235 "frontend/parser.cpp"
    break;

  case 259: // expr_var: expr_int "++" expr_var
#line 562 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2241 "frontend/parser.cpp"
    break;

  case 260: // expr_var: expr_float "++" expr_var
#line 563 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2247 "frontend/parser.cpp"
    break;

  case 261: // expr_var: expr_str "++" expr_var
#line 564 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2253 "frontend/parser.cpp"
    break;

  case 262: // expr_var: expr_bool "++" expr_var
#line 565 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2259 "frontend/parser.cpp"
    break;

  case 265: // expr_var: expr_var "++" expr_int
#line 568 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2265 "frontend/parser.cpp"
    break;

  case 266: // expr_var: expr_var "++" expr_float
#line 569 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2271 "frontend/parser.cpp"
    break;

  case 267: // expr_var: expr_var "++" expr_str
#line 570 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2277 "frontend/parser.cpp"
    break;

  case 268: // expr_var: expr_var "++" expr_bool
#line 571 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2283 "frontend/parser.cpp"
    break;

  case 269: // expr_var: expr_var "++" expr_none
#line 572 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2289 "frontend/parser.cpp"
    break;

  case 270: // expr_var: expr_var "++" expr_struct
#line 573 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2295 "frontend/parser.cpp"
    break;

  case 271: // expr_var: expr_var "++" expr_var
#line 574 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2301 "frontend/parser.cpp"
    break;

  case 286: // int_val: expr_int
#line 598 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 2307 "frontend/parser.cpp"
    break;

  case 287: // int_val: expr_var
#line 599 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 2313 "frontend/parser.cpp"
    break;

  case 308: // expr_int: "int"
#line 632 "frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 2319 "frontend/parser.cpp"
    break;

  case 309: // expr_int: "-" expr_int
#line 633 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 2325 "frontend/parser.cpp"
    break;

  case 310: // expr_int: "(" expr_int ")"
#line 634 "frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 2331 "frontend/parser.cpp"
    break;

  case 311: // expr_int: "~" expr_int
#line 635 "frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 2337 "frontend/parser.cpp"
    break;

  case 312: // expr_int: expr_int "*" expr_int
#line 636 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 2343 "frontend/parser.cpp"
    break;

  case 313: // expr_int: expr_int "/" expr_int
#line 637 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 2349 "frontend/parser.cpp"
    break;

  case 314: // expr_int: expr_int "%" expr_int
#line 638 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 2355 "frontend/parser.cpp"
    break;

  case 315: // expr_int: expr_int "-" expr_int
#line 639 "frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 2361 "frontend/parser.cpp"
    break;

  case 316: // expr_int: expr_int "+" expr_int
#line 640 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 2367 "frontend/parser.cpp"
    break;

  case 317: // expr_int: expr_int "<<" expr_int
#line 641 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 2373 "frontend/parser.cpp"
    break;

  case 318: // expr_int: expr_int ">>" expr_int
#line 642 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 2379 "frontend/parser.cpp"
    break;

  case 319: // expr_int: expr_int "&" expr_int
#line 643 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 2385 "frontend/parser.cpp"
    break;

  case 320: // expr_int: expr_int "^" expr_int
#line 644 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 2391 "frontend/parser.cpp"
    break;

  case 321: // expr_int: expr_int "|" expr_int
#line 645 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 2397 "frontend/parser.cpp"
    break;

  case 322: // expr_float: "float"
#line 649 "frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 2403 "frontend/parser.cpp"
    break;

  case 323: // expr_float: "-" expr_float
#line 650 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 2409 "frontend/parser.cpp"
    break;

  case 324: // expr_float: "(" expr_float ")"
#line 651 "frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 2415 "frontend/parser.cpp"
    break;

  case 325: // expr_float: expr_float "**" expr_float
#line 652 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2421 "frontend/parser.cpp"
    break;

  case 326: // expr_float: expr_float "**" expr_int
#line 653 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2427 "frontend/parser.cpp"
    break;

  case 327: // expr_float: expr_int "**" expr_float
#line 654 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2433 "frontend/parser.cpp"
    break;

  case 328: // expr_float: expr_float "*" expr_float
#line 655 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 2439 "frontend/parser.cpp"
    break;

  case 329: // expr_float: expr_float "*" expr_int
#line 656 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 2445 "frontend/parser.cpp"
    break;

  case 330: // expr_float: expr_int "*" expr_float
#line 657 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 2451 "frontend/parser.cpp"
    break;

  case 331: // expr_float: expr_float "/" expr_float
#line 658 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 2457 "frontend/parser.cpp"
    break;

  case 332: // expr_float: expr_float "/" expr_int
#line 659 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 2463 "frontend/parser.cpp"
    break;

  case 333: // expr_float: expr_int "/" expr_float
#line 660 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 2469 "frontend/parser.cpp"
    break;

  case 334: // expr_float: expr_float "%" expr_float
#line 661 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2475 "frontend/parser.cpp"
    break;

  case 335: // expr_float: expr_float "%" expr_int
#line 662 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2481 "frontend/parser.cpp"
    break;

  case 336: // expr_float: expr_int "%" expr_float
#line 663 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2487 "frontend/parser.cpp"
    break;

  case 337: // expr_float: expr_float "-" expr_float
#line 664 "frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 2493 "frontend/parser.cpp"
    break;

  case 338: // expr_float: expr_float "-" expr_int
#line 665 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 2499 "frontend/parser.cpp"
    break;

  case 339: // expr_float: expr_int "-" expr_float
#line 666 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 2505 "frontend/parser.cpp"
    break;

  case 340: // expr_float: expr_float "+" expr_float
#line 667 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 2511 "frontend/parser.cpp"
    break;

  case 341: // expr_float: expr_float "+" expr_int
#line 668 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 2517 "frontend/parser.cpp"
    break;

  case 342: // expr_float: expr_int "+" expr_float
#line 669 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 2523 "frontend/parser.cpp"
    break;

  case 343: // expr_str: "string"
#line 673 "frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2529 "frontend/parser.cpp"
    break;

  case 344: // expr_str: "(" expr_str ")"
#line 674 "frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 2535 "frontend/parser.cpp"
    break;

  case 345: // expr_str: expr_str "++" expr_str
#line 675 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 2541 "frontend/parser.cpp"
    break;

  case 346: // expr_str: expr_str "++" expr_int
#line 676 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 2547 "frontend/parser.cpp"
    break;

  case 347: // expr_str: expr_str "++" expr_float
#line 677 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 2553 "frontend/parser.cpp"
    break;

  case 348: // expr_str: expr_str "++" expr_bool
#line 678 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2559 "frontend/parser.cpp"
    break;

  case 349: // expr_str: expr_str "++" expr_none
#line 679 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 2565 "frontend/parser.cpp"
    break;

  case 350: // expr_str: expr_int "++" expr_str
#line 680 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 2571 "frontend/parser.cpp"
    break;

  case 351: // expr_str: expr_int "++" expr_int
#line 681 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 2577 "frontend/parser.cpp"
    break;

  case 352: // expr_str: expr_int "++" expr_float
#line 682 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 2583 "frontend/parser.cpp"
    break;

  case 353: // expr_str: expr_int "++" expr_bool
#line 683 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2589 "frontend/parser.cpp"
    break;

  case 354: // expr_str: expr_int "++" expr_none
#line 684 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 2595 "frontend/parser.cpp"
    break;

  case 355: // expr_str: expr_float "++" expr_str
#line 685 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 2601 "frontend/parser.cpp"
    break;

  case 356: // expr_str: expr_float "++" expr_int
#line 686 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 2607 "frontend/parser.cpp"
    break;

  case 357: // expr_str: expr_float "++" expr_float
#line 687 "frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 2613 "frontend/parser.cpp"
    break;

  case 358: // expr_str: expr_float "++" expr_bool
#line 688 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2619 "frontend/parser.cpp"
    break;

  case 359: // expr_str: expr_float "++" expr_none
#line 689 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 2625 "frontend/parser.cpp"
    break;

  case 360: // expr_str: expr_bool "++" expr_str
#line 690 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 2631 "frontend/parser.cpp"
    break;

  case 361: // expr_str: expr_bool "++" expr_int
#line 691 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 2637 "frontend/parser.cpp"
    break;

  case 362: // expr_str: expr_bool "++" expr_float
#line 692 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 2643 "frontend/parser.cpp"
    break;

  case 363: // expr_str: expr_bool "++" expr_bool
#line 693 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2649 "frontend/parser.cpp"
    break;

  case 364: // expr_str: expr_bool "++" expr_none
#line 694 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 2655 "frontend/parser.cpp"
    break;

  case 365: // expr_str: expr_none "++" expr_str
#line 695 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 2661 "frontend/parser.cpp"
    break;

  case 366: // expr_str: expr_none "++" expr_int
#line 696 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 2667 "frontend/parser.cpp"
    break;

  case 367: // expr_str: expr_none "++" expr_float
#line 697 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 2673 "frontend/parser.cpp"
    break;

  case 368: // expr_str: expr_none "++" expr_bool
#line 698 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2679 "frontend/parser.cpp"
    break;

  case 369: // expr_str: expr_none "++" expr_none
#line 699 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 2685 "frontend/parser.cpp"
    break;

  case 370: // expr_bool: "bool"
#line 703 "frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 2691 "frontend/parser.cpp"
    break;

  case 371: // expr_bool: "(" expr_bool ")"
#line 704 "frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 2697 "frontend/parser.cpp"
    break;

  case 372: // expr_bool: "not" expr_bool
#line 705 "frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 2703 "frontend/parser.cpp"
    break;

  case 373: // expr_bool: expr_bool "or" expr_bool
#line 706 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 2709 "frontend/parser.cpp"
    break;

  case 374: // expr_bool: expr_bool "and" expr_bool
#line 707 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 2715 "frontend/parser.cpp"
    break;

  case 375: // expr_bool: expr_bool "==" expr_bool
#line 709 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 2721 "frontend/parser.cpp"
    break;

  case 376: // expr_bool: expr_int "==" expr_int
#line 710 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 2727 "frontend/parser.cpp"
    break;

  case 377: // expr_bool: expr_int "==" expr_float
#line 711 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 2733 "frontend/parser.cpp"
    break;

  case 378: // expr_bool: expr_float "==" expr_float
#line 712 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 2739 "frontend/parser.cpp"
    break;

  case 379: // expr_bool: expr_float "==" expr_int
#line 713 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 2745 "frontend/parser.cpp"
    break;

  case 380: // expr_bool: expr_str "==" expr_str
#line 714 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 2751 "frontend/parser.cpp"
    break;

  case 381: // expr_bool: expr_none "==" expr_none
#line 715 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 2757 "frontend/parser.cpp"
    break;

  case 382: // expr_bool: expr_bool "!=" expr_bool
#line 717 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 2763 "frontend/parser.cpp"
    break;

  case 383: // expr_bool: expr_int "!=" expr_int
#line 718 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 2769 "frontend/parser.cpp"
    break;

  case 384: // expr_bool: expr_int "!=" expr_float
#line 719 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 2775 "frontend/parser.cpp"
    break;

  case 385: // expr_bool: expr_float "!=" expr_float
#line 720 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 2781 "frontend/parser.cpp"
    break;

  case 386: // expr_bool: expr_float "!=" expr_int
#line 721 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 2787 "frontend/parser.cpp"
    break;

  case 387: // expr_bool: expr_str "!=" expr_str
#line 722 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 2793 "frontend/parser.cpp"
    break;

  case 388: // expr_bool: expr_none "!=" expr_none
#line 723 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 2799 "frontend/parser.cpp"
    break;

  case 389: // expr_bool: expr_int ">" expr_int
#line 725 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 2805 "frontend/parser.cpp"
    break;

  case 390: // expr_bool: expr_int ">" expr_float
#line 726 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 2811 "frontend/parser.cpp"
    break;

  case 391: // expr_bool: expr_float ">" expr_float
#line 727 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 2817 "frontend/parser.cpp"
    break;

  case 392: // expr_bool: expr_float ">" expr_int
#line 728 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 2823 "frontend/parser.cpp"
    break;

  case 393: // expr_bool: expr_str ">" expr_str
#line 729 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 2829 "frontend/parser.cpp"
    break;

  case 394: // expr_bool: expr_int "<" expr_int
#line 731 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 2835 "frontend/parser.cpp"
    break;

  case 395: // expr_bool: expr_int "<" expr_float
#line 732 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 2841 "frontend/parser.cpp"
    break;

  case 396: // expr_bool: expr_float "<" expr_float
#line 733 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 2847 "frontend/parser.cpp"
    break;

  case 397: // expr_bool: expr_float "<" expr_int
#line 734 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 2853 "frontend/parser.cpp"
    break;

  case 398: // expr_bool: expr_str "<" expr_str
#line 735 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 2859 "frontend/parser.cpp"
    break;

  case 399: // expr_bool: expr_int ">=" expr_int
#line 737 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 2865 "frontend/parser.cpp"
    break;

  case 400: // expr_bool: expr_int ">=" expr_float
#line 738 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 2871 "frontend/parser.cpp"
    break;

  case 401: // expr_bool: expr_float ">=" expr_float
#line 739 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 2877 "frontend/parser.cpp"
    break;

  case 402: // expr_bool: expr_float ">=" expr_int
#line 740 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 2883 "frontend/parser.cpp"
    break;

  case 403: // expr_bool: expr_str ">=" expr_str
#line 741 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 2889 "frontend/parser.cpp"
    break;

  case 404: // expr_bool: expr_int "<=" expr_int
#line 743 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 2895 "frontend/parser.cpp"
    break;

  case 405: // expr_bool: expr_int "<=" expr_float
#line 744 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 2901 "frontend/parser.cpp"
    break;

  case 406: // expr_bool: expr_float "<=" expr_float
#line 745 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 2907 "frontend/parser.cpp"
    break;

  case 407: // expr_bool: expr_float "<=" expr_int
#line 746 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 2913 "frontend/parser.cpp"
    break;

  case 408: // expr_bool: expr_str "<=" expr_str
#line 747 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 2919 "frontend/parser.cpp"
    break;

  case 409: // expr_bool: expr_str "in" expr_str
#line 749 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[0].value.as < std::string > ().find(yystack_[2].value.as < std::string > ()) != std::string::npos; }
#line 2925 "frontend/parser.cpp"
    break;

  case 414: // mattype: "identifier" matsq
#line 761 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2931 "frontend/parser.cpp"
    break;

  case 415: // mattype: "'int'" matsq
#line 762 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(INT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2937 "frontend/parser.cpp"
    break;

  case 416: // mattype: "'float'" matsq
#line 763 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(FLOAT_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2943 "frontend/parser.cpp"
    break;

  case 417: // mattype: "'string'" matsq
#line 764 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(STRING_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2949 "frontend/parser.cpp"
    break;

  case 418: // mattype: "'bool'" matsq
#line 765 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseMatrixType(BOOL_CSTR, yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 2955 "frontend/parser.cpp"
    break;

  case 426: // matsq: "[" "]"
#line 774 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(scanner->parseInt(-1)); }
#line 2961 "frontend/parser.cpp"
    break;

  case 427: // matsq: "[" int_val "]"
#line 775 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseMatrixSize(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 2967 "frontend/parser.cpp"
    break;

  case 428: // matsq: "[" "]" matsq
#line 776 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), scanner->parseInt(-1)); }
#line 2973 "frontend/parser.cpp"
    break;

  case 429: // matsq: "[" int_val "]" matsq
#line 777 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddMatrixSize(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[2].value.as < ptc::ir::Expr * > ()); }
#line 2979 "frontend/parser.cpp"
    break;

  case 436: // type: mattype "?"
#line 787 "frontend/parser.yy"
       { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 2985 "frontend/parser.cpp"
    break;

  case 437: // type: "'int'"
#line 788 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(INT_CSTR, true); }
#line 2991 "frontend/parser.cpp"
    break;

  case 438: // type: "'float'"
#line 789 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(FLOAT_CSTR, true); }
#line 2997 "frontend/parser.cpp"
    break;

  case 439: // type: "'string'"
#line 790 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(STRING_CSTR, true); }
#line 3003 "frontend/parser.cpp"
    break;

  case 440: // type: "'bool'"
#line 791 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(BOOL_CSTR, true); }
#line 3009 "frontend/parser.cpp"
    break;

  case 441: // type: "identifier"
#line 792 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[0].value.as < std::string > (), true); }
#line 3015 "frontend/parser.cpp"
    break;

  case 443: // type: mattype
#line 794 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 3021 "frontend/parser.cpp"
    break;


#line 3025 "frontend/parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -734;

  const short  Parser ::yytable_ninf_ = -442;

  const short
   Parser ::yypact_[] =
  {
    1854,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  1275,    30,
      46,  1118,   318,   -55,   -31,    49,    98,   176,  2375,  1960,
    -734,  -734,    95,    19,    32,    34,    41,   113,   115,   153,
     227,   207,  1479,  -734,  -734,    22,    22,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,    22,    22,    22,  2232,  2547,  -734,
     803,  -734,   365,   374,  2817,  2932,   665,   925,    42,   171,
      -3,   242,   247,  2495,   253,   803,   255,   129,   365,   374,
    2706,  2766,   576,   251,  1960,  -734,   247,   217,    28,   399,
     399,  -734,  -734,  -734,  -734,  1429,    97,  2840,  2966,  1053,
    -734,   318,   318,  -734,   233,   245,  -734,  1960,   243,  1960,
     306,  2405,  -734,  -734,   282,  -734,   322,   426,   367,  -734,
     367,  -734,   367,  -734,   367,  -734,   111,  -734,   370,   334,
      10,  1960,   367,  -734,  -734,  -734,   771,  1960,  -734,  -734,
    -734,  2479,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    1960,  1960,  1960,  1960,  1960,  1960,  1960,  1960,  1960,  1960,
    1960,  1960,  1960,  -734,   834,   771,  1960,  1960,  1960,  1960,
    1960,  1960,  1960,  1960,  1960,  1960,  1960,  1960,  1960,  1960,
    1960,  1960,  1960,  1960,  1960,  1960,  1960,  1960,  -734,   771,
    1960,  1960,  1960,  1960,  1960,  1960,  -734,  1960,  1960,  1960,
    1960,  1960,  1960,  1960,  1960,  1960,  1960,  1960,  1960,  1960,
     399,  1960,  1960,  1960,  1960,  1960,  1960,  1960,  1960,  1960,
    1960,  1960,  1960,  1960,  1960,  1960,  1960,  1960,  1960,  1960,
    1960,  1960,  1960,  1960,  1960,  1960,  1960,  1960,  1960,  1960,
    1960,  1960,  1960,  1960,  1960,  1960,  1960,  1960,  1960,  1960,
    1960,  1960,  1960,   367,  -734,  -734,   351,    14,   384,  -734,
     771,   366,  -734,  -734,  -734,  1960,  1960,  -734,  -734,  -734,
    -734,   116,    60,   407,  -734,  1816,  1458,   399,   399,   399,
     399,   399,   318,   318,   318,   318,   318,   399,   399,   399,
     399,   399,   399,  2737,  2794,   935,   473,  1118,    84,    84,
    1118,   399,   399,   399,   399,   399,   399,  1118,   399,   399,
     399,   399,   399,   399,  1118,  1118,  1118,  1118,  1118,  1118,
    1118,  1118,  1118,  1118,  1118,  1118,  1118,  1858,  -734,   318,
     318,   318,   318,   318,  1960,   -31,   417,   383,   419,  2479,
    -734,  1934,   431,  1960,   367,  2547,   429,  2817,  2932,   665,
     925,  -734,  -734,  -734,  -734,   432,   109,   403,   376,    45,
    -734,   378,   442,   194,  2817,  -734,   122,   194,  -734,  -734,
    2985,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,   460,   440,   127,   522,   236,   674,
     744,   522,   236,   674,   744,   312,   470,   464,   465,   312,
     464,   465,   312,   464,   465,   312,   465,  2576,   327,   411,
    2863,  2989,   337,   766,  2634,   414,  2605,   161,  2663,   533,
     887,  2943,  2316,  2909,  1653,  2177,   664,   651,   664,   651,
    2043,   573,  -734,  -734,   723,  1080,   319,  -734,  2043,   573,
    -734,  -734,   723,  1080,   319,  -734,   225,  1496,  1589,   486,
     225,  1496,  1589,   486,   225,  1496,  1589,   486,   225,  1496,
    1589,   486,   194,   165,   522,   236,   522,   236,   312,   470,
    2663,   583,  2043,   573,  2043,   573,  2576,   327,   411,  2863,
    2989,   337,   766,  2663,   583,  2043,  -734,  2043,  -734,  2576,
     327,   411,  2863,  2989,   337,   766,  2663,   583,  2043,  -734,
    2043,  -734,   522,   674,   744,   522,   674,   744,   312,   464,
     465,   312,   464,   465,   312,   464,   465,   983,   479,  2576,
     327,   411,  2863,  2989,   337,   766,  2663,   583,   887,  2943,
    2316,  2909,  1653,  2177,   664,   651,   664,   651,  2043,   723,
    1080,  2043,   723,  1080,   225,  1496,  1589,   225,  1496,  1589,
     225,  1496,  1589,   225,  1496,  1589,   522,   674,   744,   522,
     674,   744,   312,   464,   465,   312,   464,   465,   312,   464,
     465,   312,   464,   465,  2576,   327,   411,  2863,  2989,   337,
     766,  2663,   583,  2043,   723,  1080,  2043,   723,  1080,   225,
    1496,  1589,   225,  1496,  1589,   225,  1496,  1589,   225,  1496,
    1589,   488,  2576,   327,   411,  2863,  2989,   337,   766,  2663,
     583,   533,  2043,   319,  2043,   319,   225,   486,   225,   486,
     225,   486,   225,   486,  2576,   327,   411,  2863,  2989,   337,
     766,  2634,   414,  2605,   161,  2663,   583,  2043,  -734,  2043,
    -734,  -734,  -734,    87,   493,    51,  1320,   444,   190,  -734,
     497,   471,   498,  -734,  1960,  -734,  -734,   813,   847,   813,
     847,   464,   479,   464,   479,   464,   479,  1542,  1222,  1304,
     751,   751,   813,   847,   813,   847,   464,   479,   464,   479,
     464,   479,   464,   479,   100,  2886,  1147,  1239,   454,   509,
    -734,  -734,   100,  2886,  1147,  1239,   454,  1561,  1705,  1561,
    1705,  1561,  1705,  1561,  1705,  1561,  1705,  1561,  1705,   100,
    2886,  1147,  1239,   454,  1561,  1705,  1561,  1705,  1561,  1705,
    1561,  1705,  1561,  1705,  1561,  1705,   100,  2886,  1147,  1239,
     454,  1919,   698,   928,   928,  -734,  -734,  -734,  -734,   100,
    2886,  1147,  1239,   454,   256,   379,  -734,  -734,   511,   511,
    -734,  -734,  -734,  -734,  -734,  2375,  1960,  2375,  2300,   529,
    1960,  -734,  -734,   367,   179,   179,  -734,   459,   521,   535,
      -2,   124,    68,   503,     6,  -734,  1351,   192,     2,   648,
     513,  -734,  -734,  -734,  1960,  -734,  -734,  -734,  -734,   452,
    -734,  -734,   124,    86,  -734,  -734,  1960,  -734,  -734,   242,
     485,   546,  -734,   554,  -734,   567,  -734,   560,  -734,   536,
    -734,   179,   539,  -734,   124,   452,   452,   543,  -734,   579,
    -734,  1443,  -734,  1559,   218,  1960,  -734,  -734,  -734,   124,
     592,  2375,  -734,  2375,  -734,  -734,  -734,  1960,  -734,  1960,
    -734,     7,   503,     8,  1960,  -734,  -734,   581,  -734,   591,
    -734,  1637,   565,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
     543,  -734,  -734,  -734,  -734,   605,   580,  -734,  -734
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     9,   308,   322,   343,   370,   300,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    36,
      33,    34,     0,   437,   438,   439,   440,     0,     0,    93,
      94,     0,     0,     4,    10,     0,     0,    35,    15,    17,
      18,    16,    19,    20,     0,     0,     0,     0,    86,   280,
      85,   281,    87,    88,    89,    90,    91,    92,   442,   443,
       0,   300,    93,   287,   280,     0,   281,     0,     0,     0,
     286,     0,     0,     0,     0,   272,    93,   277,     0,     0,
       0,    95,    96,   309,   323,     0,     0,     0,     0,     0,
     372,     0,     0,   311,     0,    31,    30,     0,     0,     0,
       0,     0,    28,    29,     0,    37,     0,     0,   430,   415,
     431,   416,   432,   417,   433,   418,     0,    58,     0,     0,
       0,     0,   434,   106,   302,   414,     0,     0,   107,     1,
       3,     0,     5,     8,     7,    14,    21,    12,    13,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   108,     0,
       0,     0,     0,     0,     0,     0,   105,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   435,   419,   436,     0,    64,     0,   301,
       0,   302,    97,   282,   283,     0,     0,   310,   324,   344,
     371,     0,     0,     0,   273,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   309,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,     0,     0,     0,   426,   287,     0,   286,     0,     0,
       0,   421,   422,   423,   424,     0,     0,     0,     0,     0,
     304,     0,     0,   109,     0,   420,     0,   110,     6,    82,
      81,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    98,     0,    83,     0,   140,   138,   135,
     136,   148,   146,   143,   144,   122,   121,   117,   118,   127,
     125,   126,   132,   130,   131,   114,   113,   271,   269,   270,
     265,   266,   267,   268,   244,   243,   247,   246,   241,   240,
     219,   218,   225,   224,   222,   221,   151,   150,   154,   153,
     199,   197,   194,   195,   190,   191,   192,   193,   216,   214,
     211,   212,   207,   208,   209,   210,   161,   158,   159,   160,
     175,   172,   173,   174,   168,   165,   166,   167,   182,   179,
     180,   181,   111,     0,   139,   137,   147,   145,   120,   119,
     239,   232,   198,   196,   215,   213,   263,   369,   252,   366,
     367,   365,   368,   237,   230,   187,   381,   204,   388,   264,
     257,   258,   253,   254,   255,   256,   238,   231,   189,   188,
     206,   205,   133,   316,   342,   141,   315,   339,   115,   312,
     330,   123,   313,   333,   128,   314,   336,     0,   327,   259,
     354,   248,   351,   352,   350,   353,   233,   226,   217,   319,
     223,   321,   220,   320,   149,   317,   152,   318,   183,   376,
     377,   200,   383,   384,   155,   389,   390,   169,   394,   395,
     162,   399,   400,   176,   404,   405,   134,   341,   340,   142,
     338,   337,   116,   329,   328,   124,   332,   331,   129,   335,
     334,   112,   326,   325,   260,   359,   249,   356,   357,   355,
     358,   234,   227,   184,   379,   378,   201,   386,   385,   156,
     392,   391,   170,   397,   396,   163,   402,   401,   177,   407,
     406,     0,   261,   349,   250,   346,   347,   345,   348,   235,
     228,   409,   185,   380,   202,   387,   157,   393,   171,   398,
     164,   403,   178,   408,   262,   364,   251,   361,   362,   360,
     363,   242,   374,   245,   373,   236,   229,   186,   375,   203,
     382,   425,   411,   441,     0,   412,     0,     0,     0,   303,
       0,     0,     0,   274,     0,   278,   275,   316,   342,   315,
     339,   312,   330,   313,   333,   314,   336,   319,   321,   320,
     317,   318,   341,   340,   338,   337,   329,   328,   332,   331,
     335,   334,   326,   325,   369,   366,   367,   365,   368,     0,
     381,   388,   354,   351,   352,   350,   353,   376,   377,   383,
     384,   389,   390,   394,   395,   399,   400,   404,   405,   359,
     356,   357,   355,   358,   379,   378,   386,   385,   392,   391,
     397,   396,   402,   401,   407,   406,   349,   346,   347,   345,
     348,   409,     0,   380,   387,   393,   398,   403,   408,   364,
     361,   362,   360,   363,   374,   373,   375,   382,   316,   315,
     312,   313,   314,    68,    32,     0,     0,     0,     0,    24,
       0,    67,   428,   427,     0,    47,    44,     0,     0,     0,
       0,     0,     0,    60,     0,   288,     0,     0,   102,     0,
       0,   305,   103,    99,     0,   104,   101,   100,   410,     0,
      66,    65,     0,     0,   102,   284,     0,   276,   279,     0,
      43,     0,    39,    25,    26,     0,   429,     0,    48,     0,
      45,    49,    51,    56,     0,     0,     0,    59,   292,     0,
     290,     0,   289,     0,     0,     0,    84,   413,    54,     0,
       0,     0,    41,     0,    27,    40,    46,     0,    50,     0,
      57,     0,    63,     0,     0,   295,   294,     0,   293,     0,
     291,     0,   306,    55,   285,    42,    38,    53,    52,    61,
       0,    62,   298,   297,   296,     0,     0,   299,   307
  };

  const short
   Parser ::yypgoto_[] =
  {
    -734,  -734,   -97,   321,   -11,   -13,  -666,  -733,  -734,   295,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -707,  -734,
    -734,   574,     5,  -171,  -734,  -734,   499,  -137,   788,  1574,
     632,   -73,  1075,   635,   270,   530,   881,  1269,   -60,  -211,
    1949,     0,   317,   564,  -734,  -132,  -734,     3,  -243
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    31,    32,   135,    33,    34,   103,   104,    35,    96,
      36,    37,    38,    39,    40,    41,   822,    42,   758,   759,
      43,   118,   762,   763,    44,    45,    46,   374,    47,    48,
      49,    78,    65,    51,    67,   178,    68,    69,   124,   352,
      54,   338,   339,   340,    58,   634,    59,   125,    60
  };

  const short
   Parser ::yytable_[] =
  {
      55,   261,   251,   635,   331,   102,   246,   246,    71,    55,
      84,    88,   790,   107,   792,   246,   246,   246,    55,    55,
      94,   132,   133,   -58,   350,   134,   109,   111,   113,   115,
     107,   263,    55,    74,     3,     4,     5,     6,     7,     8,
     264,     9,    75,   107,    95,   107,    10,   797,   798,   351,
       3,     4,   107,   107,    11,    79,   636,   768,    97,    12,
     246,   244,    80,   644,     3,     4,     5,     6,     7,     8,
    -427,     9,   247,   802,    55,    12,    10,  -427,   804,   266,
      84,   807,   849,   850,    11,   284,   769,   108,   845,    12,
     846,   779,     7,   679,   828,   803,   819,    55,   107,    55,
     110,    55,   112,   760,   764,    76,    30,    98,   805,   114,
     243,   341,   755,   342,   345,   343,   818,   344,   287,   642,
     358,    81,    82,   756,   346,   355,   805,   100,   643,   288,
     289,    55,   288,   289,   772,    76,    30,   101,   830,   775,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,   843,    55,   122,   380,   384,   388,   391,
     394,   396,   401,   769,   119,   757,   120,   255,   769,   256,
     106,   425,   433,   438,   442,   446,   450,   776,    23,    24,
      25,    26,   755,   238,   633,    99,   240,   470,   116,   645,
     117,   483,   121,   241,   242,   494,   497,   500,   503,   506,
     508,   513,   784,   154,   810,   155,   769,   129,   530,   533,
     536,   539,   542,   545,   548,   551,   554,   557,   560,   563,
     568,   122,   575,   578,   581,   584,   587,   590,  -441,   596,
     840,   769,   748,   811,   154,   757,   155,   618,   126,   245,
     156,   157,   158,   159,   160,   161,   631,   179,    23,    24,
      25,    26,   249,   182,   633,   169,   170,   262,   250,   841,
     120,   260,    55,   253,   177,   254,   127,   648,   650,   652,
     654,   656,   237,   238,   239,   324,   240,   663,   665,   667,
     669,   671,   673,   241,   242,   325,   121,   676,   315,   316,
     684,   688,   690,   692,   694,   696,   698,   701,   705,   707,
     709,   711,   713,   715,   718,    88,    88,    88,    88,    88,
      88,    88,   731,    88,    88,    88,    88,    56,   327,   329,
     132,   154,     3,   155,    55,    72,    56,    91,    89,    55,
     228,    55,   161,    55,    92,    56,    56,   752,     3,     4,
       5,     6,     7,     8,   332,     9,   334,    12,   228,    56,
      10,   177,   188,   233,   234,   235,   236,   136,    11,   189,
     190,   632,   230,    12,   333,   137,   138,   139,   153,   231,
     232,   233,   234,   235,   236,   348,   639,   336,   107,   347,
       3,     4,     5,     6,     7,     8,   187,     9,   765,   349,
     188,    56,    10,   637,   764,   191,   356,   189,   190,   192,
      11,   313,   285,     3,     4,    12,   193,   194,    79,    76,
      30,   315,   316,   761,    56,    80,    56,   766,    56,   646,
      23,    24,    25,    26,   746,   376,   633,   745,    12,   747,
       3,     4,     5,     6,     7,     8,   192,     9,   334,   240,
     750,   753,    10,   193,   194,   754,   241,   242,    56,   453,
      11,    76,    30,   770,   782,    12,   771,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
     773,    56,    23,    24,    25,    26,   313,   314,   633,   402,
     774,   179,   409,   260,   200,   219,   315,   316,   426,   434,
     439,   443,   447,   451,   312,   313,   314,   228,   591,   282,
     777,    76,    30,   778,   471,   315,   316,   785,   484,   786,
     787,   760,   760,    23,    24,    25,    26,   789,   514,   633,
     638,    23,    24,    25,    26,   640,   641,   633,   321,   322,
     323,   154,   794,   155,   799,   800,   635,   569,   801,   158,
     159,   160,   161,   806,   228,   821,   597,   601,   603,   605,
     607,   609,   611,   613,   619,   815,   823,   824,   760,   123,
     128,   177,   831,   833,    57,   231,   232,   233,   234,   235,
     236,   788,    73,    57,   826,    90,   781,   825,   827,    56,
     186,   829,    57,    57,   179,   834,   259,   228,   180,   181,
     182,   835,   123,   852,   179,   186,    57,   229,   180,   181,
     182,   230,   844,   853,   677,   856,   123,   685,   231,   232,
     233,   234,   235,   236,   702,   184,   185,   857,   767,   351,
     744,   719,   721,   723,   724,   725,   726,   727,   728,   732,
      89,    89,    89,    89,   248,   832,    55,   816,    57,   359,
      64,    56,   783,    66,    55,   858,    56,   817,    56,   286,
      56,     0,     3,     4,     5,     6,     7,     8,     0,     9,
     812,    57,     0,    57,    10,    57,   195,   196,   197,   198,
     199,   200,    11,   154,     0,   155,   228,    12,     0,   156,
     157,   158,   159,   160,   161,     0,   229,     0,     0,   813,
     230,   197,   198,   199,   200,    57,     0,   231,   232,   233,
     234,   235,   236,   177,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,     0,    57,   312,
     313,   314,     0,    76,    30,     0,   403,   405,   407,     0,
     315,   316,   102,     0,   102,   427,   435,   132,   195,   196,
     197,   198,   199,   200,     0,    55,    55,    55,    55,     0,
      55,   472,     0,   206,   207,   485,   796,   210,   211,   212,
     213,   216,   217,   218,   219,   515,   319,   320,   321,   322,
     323,   796,     0,     0,    55,     3,     4,     5,     6,     7,
       8,     0,     9,     0,   570,     0,     0,    10,   238,   239,
       0,   240,     0,   598,     0,    11,     0,    77,   241,   242,
      12,   620,   622,   624,     0,   628,   630,   105,   102,     0,
     102,     0,   348,     0,   179,    55,     0,     0,   180,   181,
     182,    55,     0,    55,     0,     0,    57,    55,   183,    55,
     269,   270,   271,   200,    55,   184,   185,     0,     3,     4,
       5,     6,     7,     8,   373,     9,    76,    30,     0,     0,
      10,   678,     0,     0,   686,     0,     0,     0,    11,     0,
       0,   703,    77,    12,   279,   280,   281,   282,   720,   722,
     722,   722,   722,   722,   722,   722,   733,   734,   735,   736,
     737,    52,     0,     0,     0,   326,     0,   328,    57,     0,
      52,     0,    86,    57,     0,    57,   154,    57,   155,    52,
      52,     0,   156,   157,   158,   159,   160,   161,   186,    76,
      30,     0,   186,    52,     0,     0,   186,   169,   170,   171,
     172,   173,   174,   175,   176,     0,   177,     0,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,     0,   375,     0,     0,   259,   237,   238,   239,     0,
     240,   186,     0,    56,     0,    52,   304,   241,   242,   186,
     305,    56,   308,   309,   310,   311,    86,   306,   307,   308,
     309,   310,   311,     0,     0,     0,     0,     0,    52,     0,
      52,     0,    52,     0,     0,   186,     0,   186,     0,   186,
       0,   186,     0,   186,     0,   186,     0,     0,   267,   268,
     269,   270,   271,   200,   186,     0,     0,     0,     0,   272,
     273,   274,    52,   275,   276,     0,     0,   186,     0,     0,
       0,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,     0,    52,   809,     0,     0,   814,
       0,     0,     0,   398,     0,     0,     0,   186,     0,     0,
      77,     0,   422,   430,     0,     0,   820,     0,     0,     0,
       0,     0,    56,    56,    56,    56,     0,    56,   467,     0,
     476,   478,   480,     0,   304,    50,     0,     0,   305,     0,
       0,   837,   510,   839,    50,   306,   307,   308,   309,   310,
     311,    56,     0,    50,    50,   214,   215,   216,   217,   218,
     219,   565,   186,     0,     0,     0,     0,    50,     0,     0,
     593,   855,   743,     0,   224,   225,   226,   227,   615,     0,
       0,   751,     3,     4,     5,     6,     7,    85,     0,     0,
     186,     0,    56,     0,    80,     0,     0,     0,    56,     0,
      56,     0,    11,    52,    56,     0,    56,    12,     0,    50,
       0,    56,     0,     0,     0,     0,   186,     0,     0,     0,
       0,     0,   277,   278,   279,   280,   281,   282,   674,   680,
     681,   682,    50,     0,    50,     0,    50,     0,   699,   298,
     299,   300,   301,   302,   303,   716,    86,    86,    86,    86,
      86,    86,    86,   729,    86,    86,    86,    86,     0,     0,
      57,     0,     0,     0,     0,    52,    50,     0,    57,     0,
      52,     0,    52,     0,    52,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,     0,    50,
       0,   378,   382,   386,     0,     0,     0,   319,   320,   321,
     322,   323,     0,     0,     0,     0,   421,   429,   272,     0,
     274,     0,   275,   276,     0,   455,   457,   459,   461,   463,
     465,     0,     0,   474,   305,     0,     0,   487,     0,    53,
       0,   306,   307,   308,   309,   310,   311,   517,    53,     3,
       4,     5,     6,    61,     8,     0,     9,    53,    53,     0,
       0,    10,     0,     0,     0,     0,   572,     0,     0,    11,
       0,    53,     0,     0,    12,   600,     0,     0,     0,    57,
      57,    57,    57,     0,    57,   626,     0,     0,     0,   319,
     320,   321,   322,   323,     3,     4,     5,     6,     7,     8,
     272,     9,     0,   120,   275,   276,    10,    50,    57,     0,
       0,     0,     0,    53,    11,     0,     0,     0,     0,    12,
      62,    30,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     0,     9,   808,     0,     0,    53,    10,    53,     0,
      53,     0,     0,     0,     0,    11,     0,     0,     0,    57,
      12,     0,     0,     0,     0,    57,     0,    57,     0,     0,
       0,    57,     0,    57,     0,    76,    30,     0,    57,    50,
      53,     0,     0,     0,    50,     0,    50,     0,    50,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,     0,    53,   780,     0,    76,    30,     0,     0,
       0,   399,    77,     3,     4,     5,     6,    61,    85,     0,
     423,   431,     0,     0,     0,    80,     0,     3,     4,     5,
       6,     7,     8,    11,     9,   836,   468,     0,    12,    10,
     481,     0,   489,   491,     0,     0,     0,    11,   258,     0,
     511,     0,    12,   277,   278,   279,   280,   281,   282,   130,
     131,     0,     2,     3,     4,     5,     6,     7,     8,   566,
       9,     0,     0,     0,     0,    10,     0,     0,   594,     0,
       0,     0,     0,    11,     0,     0,   616,     0,    12,     0,
       0,   195,   196,   197,   198,   199,   200,    52,    76,    30,
       0,     0,     0,     0,     0,    52,   206,   207,     0,     0,
       0,    53,     0,     0,   791,    13,    14,    15,   795,     0,
      16,    17,    18,    19,    20,    21,    22,     0,    23,    24,
      25,    26,    27,    28,    29,    30,     0,   319,   320,   321,
     322,   323,   375,     3,     4,     5,     6,     7,     8,     0,
       9,   838,   275,   276,     0,    10,   267,   268,   269,   270,
     271,   200,    63,    11,     0,     0,     0,     0,    12,     0,
       0,   275,   276,    53,     0,     0,     0,     0,    53,     0,
      53,     0,    53,   842,   214,   215,   216,   217,   218,   219,
       0,     0,     0,     0,     0,   847,     0,   848,     0,     0,
       0,     0,   851,     0,     0,     0,    52,    52,    52,    52,
       0,    52,     0,     0,    76,    30,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     0,     9,   854,
       0,     0,     0,    10,     0,    52,     0,     0,     0,     0,
       0,    11,   154,     0,   155,     0,    12,     0,   156,   157,
     158,   159,   160,   161,     0,     0,     0,     0,     0,   166,
       0,   335,     0,   169,   170,   171,   172,   173,   174,   175,
     176,     0,   177,   335,     0,   353,    52,     0,     0,     0,
     335,   357,    52,     0,    52,     0,     0,     0,    52,     0,
      52,    50,    76,    30,     0,    52,     0,     0,     0,    50,
     277,   278,   279,   280,   281,   282,     0,     0,     0,   335,
     377,   381,   385,   389,   392,   395,   397,   404,   406,   408,
     410,   412,   414,   416,   418,   420,   428,   436,   440,   444,
     448,   452,     0,   335,   454,   456,   458,   460,   462,   464,
       0,   466,   473,   475,   477,   479,   486,   488,   490,   492,
     495,   498,   501,   504,     0,   509,   516,   518,   520,   522,
     524,   526,   528,   531,   534,   537,   540,   543,   546,   549,
     552,   555,   558,   561,   564,   571,   573,   576,   579,   582,
     585,   588,   335,   592,   599,   602,   604,   606,   608,   610,
     612,   614,   621,   623,   625,   627,   629,     0,     0,     0,
      50,    50,    50,    50,   335,    50,   257,     0,     0,   335,
     335,   267,   268,   269,   270,   271,   200,     0,     0,     0,
       0,     0,   272,   273,   274,     0,   275,   276,     0,    50,
       0,     0,     0,     0,     1,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,   257,     0,
      10,     0,     0,   319,   320,   321,   322,   323,    11,     0,
       0,     0,     0,    12,   272,   273,   274,     0,   275,   276,
      50,     0,     0,     0,     0,     0,    50,     0,    50,     0,
       0,     0,    50,     0,    50,    53,     0,     0,     0,    50,
      13,    14,    15,    53,     0,    16,    17,    18,    19,    20,
      21,    22,   335,    23,    24,    25,    26,    27,    28,    29,
      30,     0,     0,     0,     0,   131,     0,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,   749,     0,
      10,   306,   307,   308,   309,   310,   311,    70,    11,    83,
      87,    93,     0,    12,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,     0,     0,    10,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,     0,     0,    12,
      13,    14,    15,     0,     0,    16,    17,    18,    19,    20,
      21,    22,     0,    23,    24,    25,    26,    27,    28,    29,
      30,     0,     0,     0,    53,    53,    53,    53,     0,    53,
       0,     0,     0,     0,     0,     0,     0,     0,   265,    83,
       0,     0,     0,     0,   283,    76,    30,     0,     0,     0,
     317,   318,     0,    53,     0,     0,     0,     0,     0,     0,
       0,     0,   154,     0,   155,     0,   337,     0,   156,   157,
     158,   159,   160,   161,     0,     0,     0,     0,   337,     0,
     354,     0,     0,   169,   170,   337,   354,   173,   174,   175,
     176,     0,   177,     0,    53,     0,     0,     0,     0,     0,
      53,     0,    53,     0,     0,     0,    53,     0,    53,     0,
       0,     0,     0,    53,   337,   379,   383,   387,   390,   393,
     354,   400,   354,   354,   354,   411,   413,   415,   417,   419,
     424,   432,   437,   441,   445,   449,   354,     0,   337,   354,
     354,   354,   354,   354,   354,     0,   469,   354,   354,   354,
     482,   354,   354,   354,   493,   496,   499,   502,   505,   507,
     512,   354,   519,   521,   523,   525,   527,   529,   532,   535,
     538,   541,   544,   547,   550,   553,   556,   559,   562,   567,
     354,   574,   577,   580,   583,   586,   589,   337,   595,   354,
     354,   354,   354,   354,   354,   354,   617,   354,   354,   354,
     354,   354,   195,   196,   197,   198,   199,   200,     0,   337,
       0,     0,     0,   203,   337,   337,     0,   206,   207,   208,
     209,   210,   211,   212,   213,     0,   647,   649,   651,   653,
     655,   657,   658,   659,   660,   661,   662,   664,   666,   668,
     670,   672,   133,     0,     0,   134,   675,     0,     0,   683,
     687,   689,   691,   693,   695,   697,   700,   704,   706,   708,
     710,   712,   714,   717,    87,    87,    87,    87,    87,    87,
      87,   730,    87,    87,    87,    87,     0,     0,   738,   739,
     740,   741,   742,     0,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,     0,   151,   152,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   337,     0,     0,
       0,   131,     0,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,   793,     0,    10,     0,     0,     0,
       0,     0,     0,     0,    11,   154,     0,   155,     0,    12,
       0,   156,   157,   158,   159,   160,   161,     0,     0,     0,
     335,     0,   166,   335,   168,     0,   169,   170,   171,   172,
     173,   174,   175,   176,     0,   177,    13,    14,    15,     0,
     335,    16,    17,    18,    19,    20,    21,    22,     0,    23,
      24,    25,    26,    27,    28,    29,    30,     0,   100,     3,
       4,     5,     6,     7,     8,   335,     9,   335,   101,     0,
       0,    10,     0,     0,     0,     0,     0,     0,     0,    11,
       0,     0,     0,     0,    12,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     8,   335,     9,     0,     0,   330,
       0,    10,     0,     0,     0,     0,     0,     0,     0,    11,
       0,    13,    14,    15,    12,     0,    16,    17,    18,    19,
      20,    21,    22,     0,    23,    24,    25,    26,    27,    28,
      29,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13,    14,    15,     0,     0,    16,    17,    18,    19,
      20,    21,    22,     0,    23,    24,    25,    26,    27,    28,
      29,    30,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,     0,     0,    10,     0,     0,     0,     0,
       0,     0,     0,    11,   154,   252,   155,     0,    12,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,     0,
     165,   166,   167,   168,     0,   169,   170,   171,   172,   173,
     174,   175,   176,     0,   177,    13,    14,    15,     0,     0,
      16,    17,    18,    19,    20,    21,    22,     0,    23,    24,
      25,    26,    27,    28,    29,    30,   154,     0,   155,     0,
       0,     0,   156,   157,   158,   159,   160,   161,   162,   163,
     164,     0,   165,   166,   167,   168,     0,   169,   170,   171,
     172,   173,   174,   175,   176,   154,   177,   155,     0,     0,
       0,   156,   157,   158,   159,   160,   161,     0,   163,   164,
       0,   165,   166,   167,   168,     0,   169,   170,   171,   172,
     173,   174,   175,   176,   154,   177,   155,     0,     0,     0,
     156,   157,   158,   159,   160,   161,     0,   163,     0,     0,
     165,   166,   167,   168,     0,   169,   170,   171,   172,   173,
     174,   175,   176,   154,   177,   155,     0,     0,     0,   156,
     157,   158,   159,   160,   161,     0,     0,     0,     0,   165,
     166,   167,   168,     0,   169,   170,   171,   172,   173,   174,
     175,   176,   154,   177,   155,     0,     0,     0,   156,   157,
     158,   159,   160,   161,     0,     0,     0,     0,     0,   166,
     167,   168,     0,   169,   170,   171,   172,   173,   174,   175,
     176,     0,   177,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   337,   257,     0,   337,     0,
       0,   195,   196,   197,   198,   199,   200,   201,     0,     0,
       0,   202,   203,   204,   205,   337,   206,   207,   208,   209,
     210,   211,   212,   213,     0,     0,     0,   257,     0,     0,
       0,     0,   267,   268,   269,   270,   271,   200,   290,     0,
     337,     0,   337,   272,   273,   274,     0,   275,   276,   291,
     292,   293,   294,   295,   296,     0,   258,     0,     0,     0,
       0,   214,   215,   216,   217,   218,   219,   220,     0,     0,
     337,   221,     0,     0,     0,     0,     0,     0,   222,   223,
     224,   225,   226,   227,   258,     0,     0,     0,     0,   277,
     278,   279,   280,   281,   282,   297,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   298,   299,   300,   301,
     302,   303,   195,   196,   197,   198,   199,   200,   201,     0,
       0,     0,   202,   203,   204,   205,     0,   206,   207,   208,
     209,   210,   211,   212,   213,   267,   268,   269,   270,   271,
     200,   290,     0,     0,     0,     0,   272,   273,   274,     0,
     275,   276,   291,   292,   293,   294,   295,   296,   195,   196,
     197,   198,   199,   200,     0,     0,     0,     0,   202,   203,
     204,   205,     0,   206,   207,   208,   209,   210,   211,   212,
     213,   267,   268,   269,   270,   271,   200,     0,     0,     0,
       0,     0,   272,   273,   274,     0,   275,   276,   291,   292,
     293,   294,   295,   296,   195,   196,   197,   198,   199,   200,
       0,     0,     0,     0,     0,   203,     0,   205,     0,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,     0,     0,     0,   221,   195,   196,
     197,   198,   199,   200,   222,   223,   224,   225,   226,   227,
       0,     0,     0,   206,   207,   208,   209,   210,   211,   212,
     213,   277,   278,   279,   280,   281,   282,   297,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   298,   299,
     300,   301,   302,   303,   214,   215,   216,   217,   218,   219,
       0,     0,     0,     0,   221,     0,     0,     0,     0,     0,
       0,   222,   223,   224,   225,   226,   227,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,     0,   151,
     152
  };

  const short
   Parser ::yycheck_[] =
  {
       0,    74,    62,   246,   101,    18,     9,     9,     8,     9,
      10,    11,   745,    11,   747,     9,     9,     9,    18,    19,
      75,    32,     0,     9,    14,     3,    23,    24,    25,    26,
      11,     3,    32,     3,     4,     5,     6,     7,     8,     9,
      12,    11,    12,    11,    75,    11,    16,   754,   755,    39,
       4,     5,    11,    11,    24,     9,    42,    12,     9,    29,
       9,    58,    16,     3,     4,     5,     6,     7,     8,     9,
      68,    11,    75,    75,    74,    29,    16,    75,    10,    79,
      80,    75,    75,    75,    24,    85,    41,    68,   821,    29,
     823,    40,     8,     9,   801,   761,    10,    97,    11,    99,
      68,   101,    68,   346,   347,    75,    76,     9,    40,    68,
      68,   108,     3,   110,     3,   112,   782,   114,    21,     3,
     131,    75,    76,    14,    13,   122,    40,     3,    12,    32,
      33,   131,    32,    33,    12,    75,    76,    13,   804,    12,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   819,   154,    68,   156,   157,   158,   159,
     160,   161,   162,    41,    11,    56,    13,    38,    41,    40,
      75,   171,   172,   173,   174,   175,   176,    12,    69,    70,
      71,    72,     3,    22,    75,     9,    25,   187,    75,   262,
      75,   191,    39,    32,    33,   195,   196,   197,   198,   199,
     200,   201,    12,     9,    12,    11,    41,     0,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,    68,   222,   223,   224,   225,   226,   227,    75,   229,
      12,    41,   329,    41,     9,    56,    11,   237,    11,    68,
      15,    16,    17,    18,    19,    20,   243,    11,    69,    70,
      71,    72,    10,    17,    75,    30,    31,    40,    11,    41,
      13,    10,   262,    10,    39,    10,    39,   267,   268,   269,
     270,   271,    21,    22,    23,    42,    25,   277,   278,   279,
     280,   281,   282,    32,    33,    40,    39,   287,    32,    33,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,    75,    13,
     331,     9,     4,    11,   324,     8,     9,     9,    11,   329,
      11,   331,    20,   333,    16,    18,    19,   334,     4,     5,
       6,     7,     8,     9,    62,    11,    12,    29,    11,    32,
      16,    39,    25,    34,    35,    36,    37,    36,    24,    32,
      33,    10,    25,    29,    42,    44,    45,    46,    47,    32,
      33,    34,    35,    36,    37,    41,    10,   107,    11,     9,
       4,     5,     6,     7,     8,     9,    21,    11,    12,   119,
      25,    74,    16,     9,   637,    21,   126,    32,    33,    25,
      24,    22,    85,     4,     5,    29,    32,    33,     9,    75,
      76,    32,    33,    10,    97,    16,    99,    41,   101,    12,
      69,    70,    71,    72,    41,   155,    75,    10,    29,    10,
       4,     5,     6,     7,     8,     9,    25,    11,    12,    25,
       9,    12,    16,    32,    33,    13,    32,    33,   131,   179,
      24,    75,    76,    75,    10,    29,    14,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      10,   154,    69,    70,    71,    72,    22,    23,    75,   162,
      40,    11,   165,    10,    20,    20,    32,    33,   171,   172,
     173,   174,   175,   176,    21,    22,    23,    11,   228,    20,
      12,    75,    76,    10,   187,    32,    33,    10,   191,    38,
      12,   754,   755,    69,    70,    71,    72,     8,   201,    75,
     250,    69,    70,    71,    72,   255,   256,    75,    17,    18,
      19,     9,     3,    11,    75,    14,   779,   220,     3,    17,
      18,    19,    20,    40,    11,    60,   229,   230,   231,   232,
     233,   234,   235,   236,   237,    42,    10,     3,   801,    29,
      30,    39,   805,   806,     0,    32,    33,    34,    35,    36,
      37,   644,     8,     9,    14,    11,   636,    10,    42,   262,
      50,    42,    18,    19,    11,    42,    10,    11,    15,    16,
      17,    12,    62,    12,    11,    65,    32,    21,    15,    16,
      17,    25,    10,    12,   287,    40,    76,   290,    32,    33,
      34,    35,    36,    37,   297,    32,    33,    12,   348,    39,
     325,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,    60,   806,   636,   774,    74,   140,
       8,   324,   637,     8,   644,   856,   329,   779,   331,    85,
     333,    -1,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    97,    -1,    99,    16,   101,    15,    16,    17,    18,
      19,    20,    24,     9,    -1,    11,    11,    29,    -1,    15,
      16,    17,    18,    19,    20,    -1,    21,    -1,    -1,    41,
      25,    17,    18,    19,    20,   131,    -1,    32,    33,    34,
      35,    36,    37,    39,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,    -1,   154,    21,
      22,    23,    -1,    75,    76,    -1,   162,   163,   164,    -1,
      32,    33,   745,    -1,   747,   171,   172,   748,    15,    16,
      17,    18,    19,    20,    -1,   745,   746,   747,   748,    -1,
     750,   187,    -1,    30,    31,   191,   753,    34,    35,    36,
      37,    17,    18,    19,    20,   201,    15,    16,    17,    18,
      19,   768,    -1,    -1,   774,     4,     5,     6,     7,     8,
       9,    -1,    11,    -1,   220,    -1,    -1,    16,    22,    23,
      -1,    25,    -1,   229,    -1,    24,    -1,     9,    32,    33,
      29,   237,   238,   239,    -1,   241,   242,    19,   821,    -1,
     823,    -1,    41,    -1,    11,   815,    -1,    -1,    15,    16,
      17,   821,    -1,   823,    -1,    -1,   262,   827,    25,   829,
      17,    18,    19,    20,   834,    32,    33,    -1,     4,     5,
       6,     7,     8,     9,    10,    11,    75,    76,    -1,    -1,
      16,   287,    -1,    -1,   290,    -1,    -1,    -1,    24,    -1,
      -1,   297,    74,    29,    17,    18,    19,    20,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,    -1,    -1,    -1,    97,    -1,    99,   324,    -1,
       9,    -1,    11,   329,    -1,   331,     9,   333,    11,    18,
      19,    -1,    15,    16,    17,    18,    19,    20,   378,    75,
      76,    -1,   382,    32,    -1,    -1,   386,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    39,    -1,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,    -1,   154,    -1,    -1,    10,    21,    22,    23,    -1,
      25,   421,    -1,   636,    -1,    74,    21,    32,    33,   429,
      25,   644,    34,    35,    36,    37,    85,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    97,    -1,
      99,    -1,   101,    -1,    -1,   455,    -1,   457,    -1,   459,
      -1,   461,    -1,   463,    -1,   465,    -1,    -1,    15,    16,
      17,    18,    19,    20,   474,    -1,    -1,    -1,    -1,    26,
      27,    28,   131,    30,    31,    -1,    -1,   487,    -1,    -1,
      -1,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,   154,   766,    -1,    -1,   769,
      -1,    -1,    -1,   162,    -1,    -1,    -1,   517,    -1,    -1,
     262,    -1,   171,   172,    -1,    -1,   786,    -1,    -1,    -1,
      -1,    -1,   745,   746,   747,   748,    -1,   750,   187,    -1,
     189,   190,   191,    -1,    21,     0,    -1,    -1,    25,    -1,
      -1,   811,   201,   813,     9,    32,    33,    34,    35,    36,
      37,   774,    -1,    18,    19,    15,    16,    17,    18,    19,
      20,   220,   572,    -1,    -1,    -1,    -1,    32,    -1,    -1,
     229,   841,   324,    -1,    34,    35,    36,    37,   237,    -1,
      -1,   333,     4,     5,     6,     7,     8,     9,    -1,    -1,
     600,    -1,   815,    -1,    16,    -1,    -1,    -1,   821,    -1,
     823,    -1,    24,   262,   827,    -1,   829,    29,    -1,    74,
      -1,   834,    -1,    -1,    -1,    -1,   626,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,   287,   288,
     289,   290,    97,    -1,    99,    -1,   101,    -1,   297,    32,
      33,    34,    35,    36,    37,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,    -1,    -1,
     636,    -1,    -1,    -1,    -1,   324,   131,    -1,   644,    -1,
     329,    -1,   331,    -1,   333,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    -1,   154,
      -1,   156,   157,   158,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    -1,    -1,    -1,    -1,   171,   172,    26,    -1,
      28,    -1,    30,    31,    -1,   180,   181,   182,   183,   184,
     185,    -1,    -1,   188,    25,    -1,    -1,   192,    -1,     0,
      -1,    32,    33,    34,    35,    36,    37,   202,     9,     4,
       5,     6,     7,     8,     9,    -1,    11,    18,    19,    -1,
      -1,    16,    -1,    -1,    -1,    -1,   221,    -1,    -1,    24,
      -1,    32,    -1,    -1,    29,   230,    -1,    -1,    -1,   745,
     746,   747,   748,    -1,   750,   240,    -1,    -1,    -1,    15,
      16,    17,    18,    19,     4,     5,     6,     7,     8,     9,
      26,    11,    -1,    13,    30,    31,    16,   262,   774,    -1,
      -1,    -1,    -1,    74,    24,    -1,    -1,    -1,    -1,    29,
      75,    76,    -1,    -1,    -1,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    -1,    -1,    97,    16,    99,    -1,
     101,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,   815,
      29,    -1,    -1,    -1,    -1,   821,    -1,   823,    -1,    -1,
      -1,   827,    -1,   829,    -1,    75,    76,    -1,   834,   324,
     131,    -1,    -1,    -1,   329,    -1,   331,    -1,   333,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,   154,   636,    -1,    75,    76,    -1,    -1,
      -1,   162,   644,     4,     5,     6,     7,     8,     9,    -1,
     171,   172,    -1,    -1,    -1,    16,    -1,     4,     5,     6,
       7,     8,     9,    24,    11,    12,   187,    -1,    29,    16,
     191,    -1,   193,   194,    -1,    -1,    -1,    24,    10,    -1,
     201,    -1,    29,    15,    16,    17,    18,    19,    20,     0,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,   220,
      11,    -1,    -1,    -1,    -1,    16,    -1,    -1,   229,    -1,
      -1,    -1,    -1,    24,    -1,    -1,   237,    -1,    29,    -1,
      -1,    15,    16,    17,    18,    19,    20,   636,    75,    76,
      -1,    -1,    -1,    -1,    -1,   644,    30,    31,    -1,    -1,
      -1,   262,    -1,    -1,   746,    56,    57,    58,   750,    -1,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    15,    16,    17,
      18,    19,   774,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    30,    31,    -1,    16,    15,    16,    17,    18,
      19,    20,     8,    24,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    30,    31,   324,    -1,    -1,    -1,    -1,   329,    -1,
     331,    -1,   333,   815,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,   827,    -1,   829,    -1,    -1,
      -1,    -1,   834,    -1,    -1,    -1,   745,   746,   747,   748,
      -1,   750,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,
      -1,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      -1,    -1,    -1,    16,    -1,   774,    -1,    -1,    -1,    -1,
      -1,    24,     9,    -1,    11,    -1,    29,    -1,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,
      -1,   107,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,   119,    -1,   121,   815,    -1,    -1,    -1,
     126,   127,   821,    -1,   823,    -1,    -1,    -1,   827,    -1,
     829,   636,    75,    76,    -1,   834,    -1,    -1,    -1,   644,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,    -1,   179,   180,   181,   182,   183,   184,   185,
      -1,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,    -1,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,    -1,
     745,   746,   747,   748,   250,   750,    10,    -1,    -1,   255,
     256,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    -1,    30,    31,    -1,   774,
      -1,    -1,    -1,    -1,     0,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    -1,    -1,    10,    -1,
      16,    -1,    -1,    15,    16,    17,    18,    19,    24,    -1,
      -1,    -1,    -1,    29,    26,    27,    28,    -1,    30,    31,
     815,    -1,    -1,    -1,    -1,    -1,   821,    -1,   823,    -1,
      -1,    -1,   827,    -1,   829,   636,    -1,    -1,    -1,   834,
      56,    57,    58,   644,    -1,    61,    62,    63,    64,    65,
      66,    67,   348,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    -1,    -1,    14,    -1,
      16,    32,    33,    34,    35,    36,    37,     8,    24,    10,
      11,    12,    -1,    29,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    29,
      56,    57,    58,    -1,    -1,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,   745,   746,   747,   748,    -1,   750,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    80,
      -1,    -1,    -1,    -1,    85,    75,    76,    -1,    -1,    -1,
      91,    92,    -1,   774,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    -1,    11,    -1,   107,    -1,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,   119,    -1,
     121,    -1,    -1,    30,    31,   126,   127,    34,    35,    36,
      37,    -1,    39,    -1,   815,    -1,    -1,    -1,    -1,    -1,
     821,    -1,   823,    -1,    -1,    -1,   827,    -1,   829,    -1,
      -1,    -1,    -1,   834,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,    -1,   179,   180,
     181,   182,   183,   184,   185,    -1,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    15,    16,    17,    18,    19,    20,    -1,   250,
      -1,    -1,    -1,    26,   255,   256,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,     0,    -1,    -1,     3,   287,    -1,    -1,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,    -1,    -1,   319,   320,
     321,   322,   323,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   348,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    -1,    14,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,     9,    -1,    11,    -1,    29,
      -1,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
     766,    -1,    26,   769,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    39,    56,    57,    58,    -1,
     786,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,     3,     4,
       5,     6,     7,     8,     9,   811,    11,   813,    13,    -1,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,   841,    11,    -1,    -1,    14,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    56,    57,    58,    29,    -1,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    -1,    -1,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,     9,    10,    11,    -1,    29,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      25,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    39,    56,    57,    58,    -1,    -1,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,     9,    -1,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    25,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,     9,    39,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    -1,    22,    23,
      -1,    25,    26,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,     9,    39,    11,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    -1,    22,    -1,    -1,
      25,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,     9,    39,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,     9,    39,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   766,    10,    -1,   769,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    25,    26,    27,    28,   786,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    -1,
     811,    -1,   813,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    10,    -1,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
     841,    25,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37,    10,    -1,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    37,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    25,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    25,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    25,    15,    16,
      17,    18,    19,    20,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    37,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      55
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,     0,     3,     4,     5,     6,     7,     8,     9,    11,
      16,    24,    29,    56,    57,    58,    61,    62,    63,    64,
      65,    66,    67,    69,    70,    71,    72,    73,    74,    75,
      76,    79,    80,    82,    83,    86,    88,    89,    90,    91,
      92,    93,    95,    98,   102,   103,   104,   106,   107,   108,
     110,   111,   114,   115,   118,   119,   120,   121,   122,   124,
     126,     8,    75,   107,   108,   110,   111,   112,   114,   115,
     118,   119,   120,   121,     3,    12,    75,   106,   109,     9,
      16,    75,    76,   118,   119,     9,   114,   118,   119,   120,
     121,     9,    16,   118,    75,    75,    87,     9,     9,     9,
       3,    13,    83,    84,    85,   106,    75,    11,    68,   125,
      68,   125,    68,   125,    68,   125,    75,    75,    99,    11,
      13,    39,    68,   113,   116,   125,    11,    39,   113,     0,
       0,     1,    82,     0,     3,    81,    81,    81,    81,    81,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    54,    55,    81,     9,    11,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    25,    26,    27,    28,    30,
      31,    32,    33,    34,    35,    36,    37,    39,   113,    11,
      15,    16,    17,    25,    32,    33,   113,    21,    25,    32,
      33,    21,    25,    32,    33,    15,    16,    17,    18,    19,
      20,    21,    25,    26,    27,    28,    30,    31,    32,    33,
      34,    35,    36,    37,    15,    16,    17,    18,    19,    20,
      21,    25,    32,    33,    34,    35,    36,    37,    11,    21,
      25,    32,    33,    34,    35,    36,    37,    21,    22,    23,
      25,    32,    33,    68,   125,    68,     9,    75,    99,    10,
      11,   116,    10,    10,    10,    38,    40,    10,    10,    10,
      10,   109,    40,     3,    12,   118,   119,    15,    16,    17,
      18,    19,    26,    27,    28,    30,    31,    15,    16,    17,
      18,    19,    20,   118,   119,   120,   121,    21,    32,    33,
      21,    32,    33,    34,    35,    36,    37,    21,    32,    33,
      34,    35,    36,    37,    21,    25,    32,    33,    34,    35,
      36,    37,    21,    22,    23,    32,    33,   118,   118,    15,
      16,    17,    18,    19,    42,    40,   106,    75,   106,    13,
      14,    80,    62,    42,    12,   107,   112,   118,   119,   120,
     121,   125,   125,   125,   125,     3,    13,     9,    41,   112,
      14,    39,   117,   107,   118,   125,   112,   107,    82,   104,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,    10,   105,   106,   112,   107,   110,   118,
     119,   107,   110,   118,   119,   107,   110,   118,   119,   107,
     118,   119,   107,   118,   119,   107,   119,   107,   114,   115,
     118,   119,   120,   121,   107,   121,   107,   121,   107,   120,
     107,   118,   107,   118,   107,   118,   107,   118,   107,   118,
     107,   110,   114,   115,   118,   119,   120,   121,   107,   110,
     114,   115,   118,   119,   120,   121,   107,   118,   119,   120,
     107,   118,   119,   120,   107,   118,   119,   120,   107,   118,
     119,   120,   107,   112,   107,   110,   107,   110,   107,   110,
     107,   110,   107,   110,   107,   110,   107,   114,   115,   118,
     119,   120,   121,   107,   110,   107,   114,   107,   114,   107,
     114,   115,   118,   119,   120,   121,   107,   110,   107,   115,
     107,   115,   107,   118,   119,   107,   118,   119,   107,   118,
     119,   107,   118,   119,   107,   118,   119,   118,   119,   107,
     114,   115,   118,   119,   120,   121,   107,   110,   107,   118,
     107,   118,   107,   118,   107,   118,   107,   118,   107,   118,
     119,   107,   118,   119,   107,   118,   119,   107,   118,   119,
     107,   118,   119,   107,   118,   119,   107,   118,   119,   107,
     118,   119,   107,   118,   119,   107,   118,   119,   107,   118,
     119,   107,   118,   119,   107,   114,   115,   118,   119,   120,
     121,   107,   110,   107,   118,   119,   107,   118,   119,   107,
     118,   119,   107,   118,   119,   107,   118,   119,   107,   118,
     119,   112,   107,   114,   115,   118,   119,   120,   121,   107,
     110,   120,   107,   120,   107,   120,   107,   120,   107,   120,
     107,   120,   107,   120,   107,   114,   115,   118,   119,   120,
     121,   107,   121,   107,   121,   107,   110,   107,   121,   107,
     121,   125,    10,    75,   123,   126,    42,     9,   112,    10,
     112,   112,     3,    12,     3,   109,    12,   118,   119,   118,
     119,   118,   119,   118,   119,   118,   119,   118,   118,   118,
     118,   118,   118,   119,   118,   119,   118,   119,   118,   119,
     118,   119,   118,   119,   114,   118,   119,   120,   121,     9,
     114,   114,   114,   118,   119,   120,   121,   118,   119,   118,
     119,   118,   119,   118,   119,   118,   119,   118,   119,   114,
     118,   119,   120,   121,   118,   119,   118,   119,   118,   119,
     118,   119,   118,   119,   118,   119,   114,   118,   119,   120,
     121,   120,   121,   120,   120,   120,   120,   120,   120,   114,
     118,   119,   120,   121,   121,   121,   121,   121,   118,   118,
     118,   118,   118,   106,    87,    10,    41,    10,    80,    14,
       9,   106,   125,    12,    13,     3,    14,    56,    96,    97,
     126,    10,   100,   101,   126,    12,    41,   112,    12,    41,
      75,    14,    12,    10,    40,    12,    12,    12,    10,    40,
     106,   116,    10,   100,    12,    10,    38,    12,   109,     8,
      85,   106,    85,    14,     3,   106,   125,    96,    96,    75,
      14,     3,    75,    84,    10,    40,    40,    75,    12,   112,
      12,    41,    12,    41,   112,    42,   105,   123,    84,    10,
     112,    60,    94,    10,     3,    10,    14,    42,    96,    42,
      84,   126,   101,   126,    42,    12,    12,   112,    12,   112,
      12,    41,   106,    84,    10,    85,    85,   106,   106,    75,
      75,   106,    12,    12,    12,   112,    40,    12,   117
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    78,    79,    79,    80,    80,    80,    81,    81,    82,
      82,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    84,    84,    84,    84,    84,    85,    85,
      86,    87,    87,    88,    88,    88,    89,    89,    90,    91,
      92,    93,    94,    94,    95,    95,    95,    96,    96,    96,
      96,    97,    97,    97,    98,    98,    98,    98,    99,   100,
     100,   100,   101,   101,   102,   103,   103,   103,   103,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   105,   105,   106,   106,   106,   106,   106,
     106,   106,   106,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   108,   108,   108,   108,   108,   109,   109,   109,
     110,   110,   110,   110,   111,   111,   112,   112,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     114,   114,   115,   115,   116,   116,   117,   117,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     122,   122,   123,   123,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   125,   125,   125,   125,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     1,     2,     1,     2,     3,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     3,     4,     4,     5,     1,     1,
       2,     1,     3,     1,     1,     1,     1,     2,     7,     5,
       6,     6,     2,     0,     4,     5,     6,     1,     2,     2,
       3,     2,     4,     4,     5,     6,     5,     6,     1,     2,
       1,     4,     4,     3,     2,     4,     4,     4,     4,     3,
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
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     4,     4,     5,     1,     3,     4,
       1,     1,     3,     3,     5,     7,     1,     1,     3,     4,
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
       1,     1,     1,     1
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
  "\"import\"", "\"if\"", "\"elif\"", "\"else\"", "\"for\"", "\"while\"",
  "\"do\"", "\"return\"", "\"break\"", "\"continue\"", "\"const\"",
  "\"?\"", "\"'int'\"", "\"'float'\"", "\"'string'\"", "\"'bool'\"",
  "\"'struct'\"", "\"'void'\"", "\"identifier\"",
  "\"external identifier\"", "NEG", "$accept", "start", "stmt", "stmt_end",
  "stmts", "stmts_ne", "block", "body", "import", "id_list", "flowctl",
  "return", "for", "while", "dowhile", "if", "else", "struct", "decllist",
  "declistval", "function", "fun_id", "funargs", "funargdef", "vardecl",
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
       0,   221,   221,   222,   224,   225,   226,   229,   230,   233,
     234,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   251,   252,   253,   254,   255,   258,   259,
     263,   265,   266,   270,   271,   272,   274,   275,   279,   283,
     286,   290,   292,   293,   297,   298,   299,   301,   302,   303,
     304,   306,   307,   308,   312,   313,   314,   315,   317,   319,
     320,   321,   323,   324,   328,   332,   333,   334,   335,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   356,   357,   361,   362,   363,   364,   365,
     366,   367,   368,   371,   372,   373,   374,   375,   377,   378,
     380,   381,   382,   383,   384,   386,   387,   388,   389,   391,
     392,   393,   395,   396,   397,   399,   400,   401,   402,   403,
     404,   405,   406,   408,   409,   410,   411,   412,   414,   415,
     416,   417,   418,   420,   421,   422,   423,   424,   425,   426,
     427,   429,   430,   431,   432,   433,   434,   435,   436,   438,
     439,   440,   442,   443,   444,   446,   447,   448,   449,   450,
     451,   452,   454,   455,   456,   457,   458,   459,   460,   462,
     463,   464,   465,   466,   467,   468,   470,   471,   472,   473,
     474,   475,   476,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   514,   515,   516,
     518,   519,   520,   522,   523,   524,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   543,   544,   545,   547,   548,   549,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   578,   579,   580,   581,   582,   584,   585,   586,
     590,   591,   592,   593,   595,   596,   598,   599,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     616,   617,   621,   622,   624,   625,   627,   628,   632,   633,
     634,   635,   636,   637,   638,   639,   640,   641,   642,   643,
     644,   645,   649,   650,   651,   652,   653,   654,   655,   656,
     657,   658,   659,   660,   661,   662,   663,   664,   665,   666,
     667,   668,   669,   673,   674,   675,   676,   677,   678,   679,
     680,   681,   682,   683,   684,   685,   686,   687,   688,   689,
     690,   691,   692,   693,   694,   695,   696,   697,   698,   699,
     703,   704,   705,   706,   707,   709,   710,   711,   712,   713,
     714,   715,   717,   718,   719,   720,   721,   722,   723,   725,
     726,   727,   728,   729,   731,   732,   733,   734,   735,   737,
     738,   739,   740,   741,   743,   744,   745,   746,   747,   749,
     753,   754,   756,   757,   761,   762,   763,   764,   765,   766,
     767,   768,   769,   770,   771,   772,   774,   775,   776,   777,
     781,   782,   783,   784,   785,   786,   787,   788,   789,   790,
     791,   792,   793,   794
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
#line 4512 "frontend/parser.cpp"

#line 797 "frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    auto msg = std::to_string(scanner->loc->begin.line) + ":" + std::to_string(scanner->loc->begin.column) + ": " + err_message;
    scanner->fatal_error(ptc::diag::ERR_SYNTAX, msg);
}
