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
#line 219 "frontend/parser.yy"
                        { scanner->parseEntry(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1098 "frontend/parser.cpp"
    break;

  case 4: // stmt: stmts
#line 221 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1104 "frontend/parser.cpp"
    break;

  case 5: // stmt: stmt stmts
#line 222 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1110 "frontend/parser.cpp"
    break;

  case 6: // stmt: stmt error stmts
#line 223 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1116 "frontend/parser.cpp"
    break;

  case 9: // stmts: "terminator (\\n or ;)"
#line 230 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = nullptr; }
#line 1122 "frontend/parser.cpp"
    break;

  case 10: // stmts: stmts_ne
#line 231 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1128 "frontend/parser.cpp"
    break;

  case 11: // stmts_ne: set stmt_end
#line 233 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1134 "frontend/parser.cpp"
    break;

  case 12: // stmts_ne: vardecl stmt_end
#line 234 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1140 "frontend/parser.cpp"
    break;

  case 13: // stmts_ne: vardef stmt_end
#line 235 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1146 "frontend/parser.cpp"
    break;

  case 14: // stmts_ne: import stmt_end
#line 236 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1152 "frontend/parser.cpp"
    break;

  case 16: // stmts_ne: if
#line 238 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1158 "frontend/parser.cpp"
    break;

  case 17: // stmts_ne: while
#line 239 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1164 "frontend/parser.cpp"
    break;

  case 19: // stmts_ne: struct
#line 241 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1170 "frontend/parser.cpp"
    break;

  case 20: // stmts_ne: function
#line 242 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1176 "frontend/parser.cpp"
    break;

  case 21: // stmts_ne: flowctl stmt_end
#line 243 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1182 "frontend/parser.cpp"
    break;

  case 22: // stmts_ne: expr stmt_end
#line 244 "frontend/parser.yy"
                             { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1188 "frontend/parser.cpp"
    break;

  case 23: // block: "{" "}"
#line 248 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1194 "frontend/parser.cpp"
    break;

  case 24: // block: "{" stmt "}"
#line 249 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1200 "frontend/parser.cpp"
    break;

  case 25: // block: "terminator (\\n or ;)" "{" stmt "}"
#line 250 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1206 "frontend/parser.cpp"
    break;

  case 26: // block: "{" stmt "}" "terminator (\\n or ;)"
#line 251 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1212 "frontend/parser.cpp"
    break;

  case 27: // block: "terminator (\\n or ;)" "{" stmt "}" "terminator (\\n or ;)"
#line 252 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1218 "frontend/parser.cpp"
    break;

  case 28: // body: stmts_ne
#line 255 "frontend/parser.yy"
                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1224 "frontend/parser.cpp"
    break;

  case 29: // body: block
#line 256 "frontend/parser.yy"
                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1230 "frontend/parser.cpp"
    break;

  case 30: // import: "import" id_list
#line 260 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::IR * > () = scanner->parseImports(yystack_[0].value.as < std::vector<std::string>  > ()); }
#line 1236 "frontend/parser.cpp"
    break;

  case 31: // id_list: "identifier"
#line 262 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseImportName(yystack_[0].value.as < std::string > ()); }
#line 1242 "frontend/parser.cpp"
    break;

  case 32: // id_list: "identifier" "," id_list
#line 263 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseAddImportName(yystack_[0].value.as < std::vector<std::string>  > (), yystack_[2].value.as < std::string > ()); }
#line 1248 "frontend/parser.cpp"
    break;

  case 33: // flowctl: "break"
#line 267 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseBreak(); }
#line 1254 "frontend/parser.cpp"
    break;

  case 34: // flowctl: "continue"
#line 268 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseContinue(); }
#line 1260 "frontend/parser.cpp"
    break;

  case 35: // flowctl: return
#line 269 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1266 "frontend/parser.cpp"
    break;

  case 36: // return: "return"
#line 271 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(nullptr); }
#line 1272 "frontend/parser.cpp"
    break;

  case 37: // return: "return" expr
#line 272 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1278 "frontend/parser.cpp"
    break;

  case 39: // while: "while" "(" expr ")" body
#line 280 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::IR * > () = scanner->parseWhile(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1284 "frontend/parser.cpp"
    break;

  case 41: // if: "if" "(" expr ")" body else
#line 287 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::IR * > () = scanner->parseIfStmt(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1290 "frontend/parser.cpp"
    break;

  case 42: // else: "else" body
#line 293 "frontend/parser.yy"
                    { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1296 "frontend/parser.cpp"
    break;

  case 43: // else: %empty
#line 294 "frontend/parser.yy"
                    { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1302 "frontend/parser.cpp"
    break;

  case 44: // struct: "'struct'" "identifier" "{" "}"
#line 298 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[2].value.as < std::string > (), std::vector<ptc::ir::IR *>{}); }
#line 1308 "frontend/parser.cpp"
    break;

  case 45: // struct: "'struct'" "identifier" "{" decllist "}"
#line 299 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1314 "frontend/parser.cpp"
    break;

  case 46: // struct: "'struct'" "identifier" "terminator (\\n or ;)" "{" decllist "}"
#line 300 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[4].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1320 "frontend/parser.cpp"
    break;

  case 48: // decllist: "terminator (\\n or ;)" decllist
#line 303 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1326 "frontend/parser.cpp"
    break;

  case 49: // decllist: declistval "terminator (\\n or ;)"
#line 304 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[1].value.as < ptc::ir::IR * > (), std::vector<ptc::ir::IR *>{}); }
#line 1332 "frontend/parser.cpp"
    break;

  case 50: // decllist: declistval "terminator (\\n or ;)" decllist
#line 305 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[2].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1338 "frontend/parser.cpp"
    break;

  case 51: // declistval: type "identifier"
#line 307 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > (), nullptr); }
#line 1344 "frontend/parser.cpp"
    break;

  case 52: // declistval: type "identifier" "=" expr
#line 308 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1350 "frontend/parser.cpp"
    break;

  case 54: // function: type fun_id "(" ")" block
#line 313 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1356 "frontend/parser.cpp"
    break;

  case 55: // function: type fun_id "(" funargs ")" block
#line 314 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[5].value.as < ptc::ir::IR * > (), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1362 "frontend/parser.cpp"
    break;

  case 56: // function: "'void'" fun_id "(" ")" block
#line 315 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1368 "frontend/parser.cpp"
    break;

  case 57: // function: "'void'" fun_id "(" funargs ")" block
#line 316 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1374 "frontend/parser.cpp"
    break;

  case 58: // fun_id: "identifier"
#line 318 "frontend/parser.yy"
            { scanner->enterFunScope(); yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1380 "frontend/parser.cpp"
    break;

  case 59: // funargs: type "identifier"
#line 320 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseFunParam(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1386 "frontend/parser.cpp"
    break;

  case 61: // funargs: funargs "," type "identifier"
#line 322 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseAddFunParam(yystack_[3].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1392 "frontend/parser.cpp"
    break;

  case 64: // vardecl: type "identifier"
#line 329 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1398 "frontend/parser.cpp"
    break;

  case 65: // vardef: type "identifier" "=" struct_val
#line 333 "frontend/parser.yy"
         { yylhs.value.as < ptc::ir::IR * > () = yystack_[3].value.as < ptc::ir::IR * > (); }
#line 1404 "frontend/parser.cpp"
    break;

  case 66: // vardef: type "identifier" "=" expr
#line 334 "frontend/parser.yy"
                                 { scanner->parseVarDef(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1410 "frontend/parser.cpp"
    break;

  case 69: // set: expr "++=" expr
#line 340 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1416 "frontend/parser.cpp"
    break;

  case 70: // set: expr "**=" expr
#line 341 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1422 "frontend/parser.cpp"
    break;

  case 71: // set: expr "%=" expr
#line 342 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1428 "frontend/parser.cpp"
    break;

  case 72: // set: expr "/=" expr
#line 343 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1434 "frontend/parser.cpp"
    break;

  case 73: // set: expr "*=" expr
#line 344 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1440 "frontend/parser.cpp"
    break;

  case 74: // set: expr "-=" expr
#line 345 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1446 "frontend/parser.cpp"
    break;

  case 75: // set: expr "+=" expr
#line 346 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1452 "frontend/parser.cpp"
    break;

  case 76: // set: expr "&=" expr
#line 347 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1458 "frontend/parser.cpp"
    break;

  case 77: // set: expr "|=" expr
#line 348 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1464 "frontend/parser.cpp"
    break;

  case 78: // set: expr "^=" expr
#line 349 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1470 "frontend/parser.cpp"
    break;

  case 79: // set: expr "<<=" expr
#line 350 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1476 "frontend/parser.cpp"
    break;

  case 80: // set: expr ">>=" expr
#line 351 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1482 "frontend/parser.cpp"
    break;

  case 81: // set: expr "=" expr
#line 352 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1488 "frontend/parser.cpp"
    break;

  case 82: // set: expr "=" set
#line 353 "frontend/parser.yy"
      { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1494 "frontend/parser.cpp"
    break;

  case 83: // callarglist: expr
#line 357 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseFunCallArg(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1500 "frontend/parser.cpp"
    break;

  case 84: // callarglist: expr "," callarglist
#line 358 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddFunCallArg(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[2].value.as < ptc::ir::Expr * > ()); }
#line 1506 "frontend/parser.cpp"
    break;

  case 85: // expr: expr_mat
#line 362 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = nullptr; }
#line 1512 "frontend/parser.cpp"
    break;

  case 86: // expr: expr_var
#line 363 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1518 "frontend/parser.cpp"
    break;

  case 87: // expr: expr_none
#line 364 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = nullptr; }
#line 1524 "frontend/parser.cpp"
    break;

  case 88: // expr: expr_struct
#line 365 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = nullptr; }
#line 1530 "frontend/parser.cpp"
    break;

  case 89: // expr: expr_int
#line 366 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 1536 "frontend/parser.cpp"
    break;

  case 90: // expr: expr_float
#line 367 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFloat(yystack_[0].value.as < double > ()); }
#line 1542 "frontend/parser.cpp"
    break;

  case 91: // expr: expr_str
#line 368 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseString(yystack_[0].value.as < std::string > ()); }
#line 1548 "frontend/parser.cpp"
    break;

  case 92: // expr: expr_bool
#line 369 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseBool(yystack_[0].value.as < bool > ()); }
#line 1554 "frontend/parser.cpp"
    break;

  case 93: // expr_var: "identifier"
#line 372 "frontend/parser.yy"
              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > ()); }
#line 1560 "frontend/parser.cpp"
    break;

  case 94: // expr_var: "external identifier"
#line 373 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > (), true); }
#line 1566 "frontend/parser.cpp"
    break;

  case 95: // expr_var: "-" "identifier"
#line 374 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1572 "frontend/parser.cpp"
    break;

  case 96: // expr_var: "-" "external identifier"
#line 375 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > (), true), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1578 "frontend/parser.cpp"
    break;

  case 97: // expr_var: "(" expr_var ")"
#line 376 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1584 "frontend/parser.cpp"
    break;

  case 98: // expr_var: expr_var "(" ")"
#line 378 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[2].value.as < ptc::ir::Expr * > (), std::vector<ptc::ir::Expr *>{}); }
#line 1590 "frontend/parser.cpp"
    break;

  case 99: // expr_var: expr_var "(" callarglist ")"
#line 379 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 1596 "frontend/parser.cpp"
    break;

  case 104: // expr_var: expr_var "[" int_val "]"
#line 385 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[3].value.as < ptc::ir::Expr * > (); }
#line 1602 "frontend/parser.cpp"
    break;

  case 108: // expr_var: expr_var slice
#line 390 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1608 "frontend/parser.cpp"
    break;

  case 111: // expr_var: expr_var "." expr_var
#line 394 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1614 "frontend/parser.cpp"
    break;

  case 113: // expr_var: expr_var "**" expr_float
#line 397 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1620 "frontend/parser.cpp"
    break;

  case 114: // expr_var: expr_var "**" expr_var
#line 398 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1626 "frontend/parser.cpp"
    break;

  case 115: // expr_var: expr_int "*" expr_var
#line 400 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1632 "frontend/parser.cpp"
    break;

  case 116: // expr_var: expr_float "*" expr_var
#line 401 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1638 "frontend/parser.cpp"
    break;

  case 117: // expr_var: expr_var "*" expr_int
#line 402 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1644 "frontend/parser.cpp"
    break;

  case 118: // expr_var: expr_var "*" expr_float
#line 403 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1650 "frontend/parser.cpp"
    break;

  case 121: // expr_var: expr_var "*" expr_mat
#line 406 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1656 "frontend/parser.cpp"
    break;

  case 122: // expr_var: expr_var "*" expr_var
#line 407 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1662 "frontend/parser.cpp"
    break;

  case 123: // expr_var: expr_int "/" expr_var
#line 409 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1668 "frontend/parser.cpp"
    break;

  case 124: // expr_var: expr_float "/" expr_var
#line 410 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1674 "frontend/parser.cpp"
    break;

  case 125: // expr_var: expr_var "/" expr_int
#line 411 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1680 "frontend/parser.cpp"
    break;

  case 126: // expr_var: expr_var "/" expr_float
#line 412 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1686 "frontend/parser.cpp"
    break;

  case 127: // expr_var: expr_var "/" expr_var
#line 413 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1692 "frontend/parser.cpp"
    break;

  case 128: // expr_var: expr_int "%" expr_var
#line 415 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1698 "frontend/parser.cpp"
    break;

  case 129: // expr_var: expr_float "%" expr_var
#line 416 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1704 "frontend/parser.cpp"
    break;

  case 130: // expr_var: expr_var "%" expr_int
#line 417 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1710 "frontend/parser.cpp"
    break;

  case 131: // expr_var: expr_var "%" expr_float
#line 418 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1716 "frontend/parser.cpp"
    break;

  case 132: // expr_var: expr_var "%" expr_var
#line 419 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1722 "frontend/parser.cpp"
    break;

  case 133: // expr_var: expr_int "+" expr_var
#line 421 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1728 "frontend/parser.cpp"
    break;

  case 134: // expr_var: expr_float "+" expr_var
#line 422 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1734 "frontend/parser.cpp"
    break;

  case 135: // expr_var: expr_var "+" expr_int
#line 423 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1740 "frontend/parser.cpp"
    break;

  case 136: // expr_var: expr_var "+" expr_float
#line 424 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1746 "frontend/parser.cpp"
    break;

  case 138: // expr_var: expr_var "+" expr_mat
#line 426 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1752 "frontend/parser.cpp"
    break;

  case 140: // expr_var: expr_var "+" expr_var
#line 428 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1758 "frontend/parser.cpp"
    break;

  case 141: // expr_var: expr_int "-" expr_var
#line 430 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1764 "frontend/parser.cpp"
    break;

  case 142: // expr_var: expr_float "-" expr_var
#line 431 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1770 "frontend/parser.cpp"
    break;

  case 143: // expr_var: expr_var "-" expr_int
#line 432 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1776 "frontend/parser.cpp"
    break;

  case 144: // expr_var: expr_var "-" expr_float
#line 433 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1782 "frontend/parser.cpp"
    break;

  case 146: // expr_var: expr_var "-" expr_mat
#line 435 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1788 "frontend/parser.cpp"
    break;

  case 148: // expr_var: expr_var "-" expr_var
#line 437 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1794 "frontend/parser.cpp"
    break;

  case 149: // expr_var: expr_int "<<" expr_var
#line 439 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 1800 "frontend/parser.cpp"
    break;

  case 150: // expr_var: expr_var "<<" expr_int
#line 440 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 1806 "frontend/parser.cpp"
    break;

  case 151: // expr_var: expr_var "<<" expr_var
#line 441 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 1812 "frontend/parser.cpp"
    break;

  case 152: // expr_var: expr_int ">>" expr_var
#line 443 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 1818 "frontend/parser.cpp"
    break;

  case 153: // expr_var: expr_var ">>" expr_int
#line 444 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 1824 "frontend/parser.cpp"
    break;

  case 154: // expr_var: expr_var ">>" expr_var
#line 445 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 1830 "frontend/parser.cpp"
    break;

  case 155: // expr_var: expr_int ">" expr_var
#line 447 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 1836 "frontend/parser.cpp"
    break;

  case 156: // expr_var: expr_float ">" expr_var
#line 448 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 1842 "frontend/parser.cpp"
    break;

  case 158: // expr_var: expr_var ">" expr_int
#line 450 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 1848 "frontend/parser.cpp"
    break;

  case 159: // expr_var: expr_var ">" expr_float
#line 451 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 1854 "frontend/parser.cpp"
    break;

  case 160: // expr_var: expr_var ">" expr_str
#line 452 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1860 "frontend/parser.cpp"
    break;

  case 161: // expr_var: expr_var ">" expr_var
#line 453 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 1866 "frontend/parser.cpp"
    break;

  case 162: // expr_var: expr_int ">=" expr_var
#line 455 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 1872 "frontend/parser.cpp"
    break;

  case 163: // expr_var: expr_float ">=" expr_var
#line 456 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 1878 "frontend/parser.cpp"
    break;

  case 165: // expr_var: expr_var ">=" expr_int
#line 458 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 1884 "frontend/parser.cpp"
    break;

  case 166: // expr_var: expr_var ">=" expr_float
#line 459 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 1890 "frontend/parser.cpp"
    break;

  case 167: // expr_var: expr_var ">=" expr_str
#line 460 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1896 "frontend/parser.cpp"
    break;

  case 168: // expr_var: expr_var ">=" expr_var
#line 461 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 1902 "frontend/parser.cpp"
    break;

  case 169: // expr_var: expr_int "<" expr_var
#line 463 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 1908 "frontend/parser.cpp"
    break;

  case 170: // expr_var: expr_float "<" expr_var
#line 464 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 1914 "frontend/parser.cpp"
    break;

  case 172: // expr_var: expr_var "<" expr_int
#line 466 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 1920 "frontend/parser.cpp"
    break;

  case 173: // expr_var: expr_var "<" expr_float
#line 467 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 1926 "frontend/parser.cpp"
    break;

  case 174: // expr_var: expr_var "<" expr_str
#line 468 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1932 "frontend/parser.cpp"
    break;

  case 175: // expr_var: expr_var "<" expr_var
#line 469 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 1938 "frontend/parser.cpp"
    break;

  case 176: // expr_var: expr_int "<=" expr_var
#line 471 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 1944 "frontend/parser.cpp"
    break;

  case 177: // expr_var: expr_float "<=" expr_var
#line 472 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 1950 "frontend/parser.cpp"
    break;

  case 179: // expr_var: expr_var "<=" expr_int
#line 474 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 1956 "frontend/parser.cpp"
    break;

  case 180: // expr_var: expr_var "<=" expr_float
#line 475 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 1962 "frontend/parser.cpp"
    break;

  case 181: // expr_var: expr_var "<=" expr_str
#line 476 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1968 "frontend/parser.cpp"
    break;

  case 182: // expr_var: expr_var "<=" expr_var
#line 477 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 1974 "frontend/parser.cpp"
    break;

  case 183: // expr_var: expr_int "==" expr_var
#line 479 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 1980 "frontend/parser.cpp"
    break;

  case 184: // expr_var: expr_float "==" expr_var
#line 480 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 1986 "frontend/parser.cpp"
    break;

  case 186: // expr_var: expr_bool "==" expr_var
#line 482 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 1992 "frontend/parser.cpp"
    break;

  case 190: // expr_var: expr_var "==" expr_int
#line 486 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 1998 "frontend/parser.cpp"
    break;

  case 191: // expr_var: expr_var "==" expr_float
#line 487 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2004 "frontend/parser.cpp"
    break;

  case 192: // expr_var: expr_var "==" expr_str
#line 488 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2010 "frontend/parser.cpp"
    break;

  case 193: // expr_var: expr_var "==" expr_bool
#line 489 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2016 "frontend/parser.cpp"
    break;

  case 194: // expr_var: expr_var "==" expr_none
#line 490 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2022 "frontend/parser.cpp"
    break;

  case 195: // expr_var: expr_var "==" expr_struct
#line 491 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2028 "frontend/parser.cpp"
    break;

  case 197: // expr_var: expr_var "==" expr_mat
#line 493 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2034 "frontend/parser.cpp"
    break;

  case 199: // expr_var: expr_var "==" expr_var
#line 495 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2040 "frontend/parser.cpp"
    break;

  case 200: // expr_var: expr_int "!=" expr_var
#line 497 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2046 "frontend/parser.cpp"
    break;

  case 201: // expr_var: expr_float "!=" expr_var
#line 498 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2052 "frontend/parser.cpp"
    break;

  case 207: // expr_var: expr_var "!=" expr_int
#line 504 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2058 "frontend/parser.cpp"
    break;

  case 208: // expr_var: expr_var "!=" expr_float
#line 505 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2064 "frontend/parser.cpp"
    break;

  case 209: // expr_var: expr_var "!=" expr_str
#line 506 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2070 "frontend/parser.cpp"
    break;

  case 210: // expr_var: expr_var "!=" expr_bool
#line 507 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2076 "frontend/parser.cpp"
    break;

  case 211: // expr_var: expr_var "!=" expr_none
#line 508 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2082 "frontend/parser.cpp"
    break;

  case 212: // expr_var: expr_var "!=" expr_struct
#line 509 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2088 "frontend/parser.cpp"
    break;

  case 214: // expr_var: expr_var "!=" expr_mat
#line 511 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2094 "frontend/parser.cpp"
    break;

  case 216: // expr_var: expr_var "!=" expr_var
#line 513 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2100 "frontend/parser.cpp"
    break;

  case 217: // expr_var: expr_int "&" expr_var
#line 515 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2106 "frontend/parser.cpp"
    break;

  case 218: // expr_var: expr_var "&" expr_int
#line 516 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2112 "frontend/parser.cpp"
    break;

  case 219: // expr_var: expr_var "&" expr_var
#line 517 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2118 "frontend/parser.cpp"
    break;

  case 220: // expr_var: expr_int "^" expr_var
#line 519 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2124 "frontend/parser.cpp"
    break;

  case 221: // expr_var: expr_var "^" expr_int
#line 520 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2130 "frontend/parser.cpp"
    break;

  case 222: // expr_var: expr_var "^" expr_var
#line 521 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2136 "frontend/parser.cpp"
    break;

  case 223: // expr_var: expr_int "|" expr_var
#line 523 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2142 "frontend/parser.cpp"
    break;

  case 224: // expr_var: expr_var "|" expr_int
#line 524 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2148 "frontend/parser.cpp"
    break;

  case 225: // expr_var: expr_var "|" expr_var
#line 525 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2154 "frontend/parser.cpp"
    break;

  case 240: // expr_var: expr_var "in" expr_str
#line 541 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2160 "frontend/parser.cpp"
    break;

  case 241: // expr_var: expr_var "in" expr_var
#line 542 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2166 "frontend/parser.cpp"
    break;

  case 242: // expr_var: expr_bool "and" expr_var
#line 544 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2172 "frontend/parser.cpp"
    break;

  case 243: // expr_var: expr_var "and" expr_bool
#line 545 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2178 "frontend/parser.cpp"
    break;

  case 244: // expr_var: expr_var "and" expr_var
#line 546 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2184 "frontend/parser.cpp"
    break;

  case 245: // expr_var: expr_bool "or" expr_var
#line 548 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2190 "frontend/parser.cpp"
    break;

  case 246: // expr_var: expr_var "or" expr_bool
#line 549 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2196 "frontend/parser.cpp"
    break;

  case 247: // expr_var: expr_var "or" expr_var
#line 550 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2202 "frontend/parser.cpp"
    break;

  case 259: // expr_var: expr_int "++" expr_var
#line 563 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2208 "frontend/parser.cpp"
    break;

  case 260: // expr_var: expr_float "++" expr_var
#line 564 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2214 "frontend/parser.cpp"
    break;

  case 261: // expr_var: expr_str "++" expr_var
#line 565 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2220 "frontend/parser.cpp"
    break;

  case 262: // expr_var: expr_bool "++" expr_var
#line 566 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2226 "frontend/parser.cpp"
    break;

  case 265: // expr_var: expr_var "++" expr_int
#line 569 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2232 "frontend/parser.cpp"
    break;

  case 266: // expr_var: expr_var "++" expr_float
#line 570 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2238 "frontend/parser.cpp"
    break;

  case 267: // expr_var: expr_var "++" expr_str
#line 571 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2244 "frontend/parser.cpp"
    break;

  case 268: // expr_var: expr_var "++" expr_bool
#line 572 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2250 "frontend/parser.cpp"
    break;

  case 269: // expr_var: expr_var "++" expr_none
#line 573 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2256 "frontend/parser.cpp"
    break;

  case 270: // expr_var: expr_var "++" expr_struct
#line 574 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2262 "frontend/parser.cpp"
    break;

  case 271: // expr_var: expr_var "++" expr_var
#line 575 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2268 "frontend/parser.cpp"
    break;

  case 308: // expr_int: "int"
#line 633 "frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 2274 "frontend/parser.cpp"
    break;

  case 309: // expr_int: "-" expr_int
#line 634 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 2280 "frontend/parser.cpp"
    break;

  case 310: // expr_int: "(" expr_int ")"
#line 635 "frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 2286 "frontend/parser.cpp"
    break;

  case 311: // expr_int: "~" expr_int
#line 636 "frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 2292 "frontend/parser.cpp"
    break;

  case 312: // expr_int: expr_int "*" expr_int
#line 637 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 2298 "frontend/parser.cpp"
    break;

  case 313: // expr_int: expr_int "/" expr_int
#line 638 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 2304 "frontend/parser.cpp"
    break;

  case 314: // expr_int: expr_int "%" expr_int
#line 639 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 2310 "frontend/parser.cpp"
    break;

  case 315: // expr_int: expr_int "-" expr_int
#line 640 "frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 2316 "frontend/parser.cpp"
    break;

  case 316: // expr_int: expr_int "+" expr_int
#line 641 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 2322 "frontend/parser.cpp"
    break;

  case 317: // expr_int: expr_int "<<" expr_int
#line 642 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 2328 "frontend/parser.cpp"
    break;

  case 318: // expr_int: expr_int ">>" expr_int
#line 643 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 2334 "frontend/parser.cpp"
    break;

  case 319: // expr_int: expr_int "&" expr_int
#line 644 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 2340 "frontend/parser.cpp"
    break;

  case 320: // expr_int: expr_int "^" expr_int
#line 645 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 2346 "frontend/parser.cpp"
    break;

  case 321: // expr_int: expr_int "|" expr_int
#line 646 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 2352 "frontend/parser.cpp"
    break;

  case 322: // expr_float: "float"
#line 650 "frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 2358 "frontend/parser.cpp"
    break;

  case 323: // expr_float: "-" expr_float
#line 651 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 2364 "frontend/parser.cpp"
    break;

  case 324: // expr_float: "(" expr_float ")"
#line 652 "frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 2370 "frontend/parser.cpp"
    break;

  case 325: // expr_float: expr_float "**" expr_float
#line 653 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2376 "frontend/parser.cpp"
    break;

  case 326: // expr_float: expr_float "**" expr_int
#line 654 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2382 "frontend/parser.cpp"
    break;

  case 327: // expr_float: expr_int "**" expr_float
#line 655 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2388 "frontend/parser.cpp"
    break;

  case 328: // expr_float: expr_float "*" expr_float
#line 656 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 2394 "frontend/parser.cpp"
    break;

  case 329: // expr_float: expr_float "*" expr_int
#line 657 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 2400 "frontend/parser.cpp"
    break;

  case 330: // expr_float: expr_int "*" expr_float
#line 658 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 2406 "frontend/parser.cpp"
    break;

  case 331: // expr_float: expr_float "/" expr_float
#line 659 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 2412 "frontend/parser.cpp"
    break;

  case 332: // expr_float: expr_float "/" expr_int
#line 660 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 2418 "frontend/parser.cpp"
    break;

  case 333: // expr_float: expr_int "/" expr_float
#line 661 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 2424 "frontend/parser.cpp"
    break;

  case 334: // expr_float: expr_float "%" expr_float
#line 662 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2430 "frontend/parser.cpp"
    break;

  case 335: // expr_float: expr_float "%" expr_int
#line 663 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2436 "frontend/parser.cpp"
    break;

  case 336: // expr_float: expr_int "%" expr_float
#line 664 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2442 "frontend/parser.cpp"
    break;

  case 337: // expr_float: expr_float "-" expr_float
#line 665 "frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 2448 "frontend/parser.cpp"
    break;

  case 338: // expr_float: expr_float "-" expr_int
#line 666 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 2454 "frontend/parser.cpp"
    break;

  case 339: // expr_float: expr_int "-" expr_float
#line 667 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 2460 "frontend/parser.cpp"
    break;

  case 340: // expr_float: expr_float "+" expr_float
#line 668 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 2466 "frontend/parser.cpp"
    break;

  case 341: // expr_float: expr_float "+" expr_int
#line 669 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 2472 "frontend/parser.cpp"
    break;

  case 342: // expr_float: expr_int "+" expr_float
#line 670 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 2478 "frontend/parser.cpp"
    break;

  case 343: // expr_str: "string"
#line 674 "frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2484 "frontend/parser.cpp"
    break;

  case 344: // expr_str: "(" expr_str ")"
#line 675 "frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 2490 "frontend/parser.cpp"
    break;

  case 345: // expr_str: expr_str "++" expr_str
#line 676 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 2496 "frontend/parser.cpp"
    break;

  case 346: // expr_str: expr_str "++" expr_int
#line 677 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 2502 "frontend/parser.cpp"
    break;

  case 347: // expr_str: expr_str "++" expr_float
#line 678 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 2508 "frontend/parser.cpp"
    break;

  case 348: // expr_str: expr_str "++" expr_bool
#line 679 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2514 "frontend/parser.cpp"
    break;

  case 349: // expr_str: expr_str "++" expr_none
#line 680 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 2520 "frontend/parser.cpp"
    break;

  case 350: // expr_str: expr_int "++" expr_str
#line 681 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 2526 "frontend/parser.cpp"
    break;

  case 351: // expr_str: expr_int "++" expr_int
#line 682 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 2532 "frontend/parser.cpp"
    break;

  case 352: // expr_str: expr_int "++" expr_float
#line 683 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 2538 "frontend/parser.cpp"
    break;

  case 353: // expr_str: expr_int "++" expr_bool
#line 684 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2544 "frontend/parser.cpp"
    break;

  case 354: // expr_str: expr_int "++" expr_none
#line 685 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 2550 "frontend/parser.cpp"
    break;

  case 355: // expr_str: expr_float "++" expr_str
#line 686 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 2556 "frontend/parser.cpp"
    break;

  case 356: // expr_str: expr_float "++" expr_int
#line 687 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 2562 "frontend/parser.cpp"
    break;

  case 357: // expr_str: expr_float "++" expr_float
#line 688 "frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 2568 "frontend/parser.cpp"
    break;

  case 358: // expr_str: expr_float "++" expr_bool
#line 689 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2574 "frontend/parser.cpp"
    break;

  case 359: // expr_str: expr_float "++" expr_none
#line 690 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 2580 "frontend/parser.cpp"
    break;

  case 360: // expr_str: expr_bool "++" expr_str
#line 691 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 2586 "frontend/parser.cpp"
    break;

  case 361: // expr_str: expr_bool "++" expr_int
#line 692 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 2592 "frontend/parser.cpp"
    break;

  case 362: // expr_str: expr_bool "++" expr_float
#line 693 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 2598 "frontend/parser.cpp"
    break;

  case 363: // expr_str: expr_bool "++" expr_bool
#line 694 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2604 "frontend/parser.cpp"
    break;

  case 364: // expr_str: expr_bool "++" expr_none
#line 695 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 2610 "frontend/parser.cpp"
    break;

  case 365: // expr_str: expr_none "++" expr_str
#line 696 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 2616 "frontend/parser.cpp"
    break;

  case 366: // expr_str: expr_none "++" expr_int
#line 697 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 2622 "frontend/parser.cpp"
    break;

  case 367: // expr_str: expr_none "++" expr_float
#line 698 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 2628 "frontend/parser.cpp"
    break;

  case 368: // expr_str: expr_none "++" expr_bool
#line 699 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2634 "frontend/parser.cpp"
    break;

  case 369: // expr_str: expr_none "++" expr_none
#line 700 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 2640 "frontend/parser.cpp"
    break;

  case 370: // expr_bool: "bool"
#line 704 "frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 2646 "frontend/parser.cpp"
    break;

  case 371: // expr_bool: "(" expr_bool ")"
#line 705 "frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 2652 "frontend/parser.cpp"
    break;

  case 372: // expr_bool: "not" expr_bool
#line 706 "frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 2658 "frontend/parser.cpp"
    break;

  case 373: // expr_bool: expr_bool "or" expr_bool
#line 707 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 2664 "frontend/parser.cpp"
    break;

  case 374: // expr_bool: expr_bool "and" expr_bool
#line 708 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 2670 "frontend/parser.cpp"
    break;

  case 375: // expr_bool: expr_bool "==" expr_bool
#line 710 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 2676 "frontend/parser.cpp"
    break;

  case 376: // expr_bool: expr_int "==" expr_int
#line 711 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 2682 "frontend/parser.cpp"
    break;

  case 377: // expr_bool: expr_int "==" expr_float
#line 712 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 2688 "frontend/parser.cpp"
    break;

  case 378: // expr_bool: expr_float "==" expr_float
#line 713 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 2694 "frontend/parser.cpp"
    break;

  case 379: // expr_bool: expr_float "==" expr_int
#line 714 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 2700 "frontend/parser.cpp"
    break;

  case 380: // expr_bool: expr_str "==" expr_str
#line 715 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 2706 "frontend/parser.cpp"
    break;

  case 381: // expr_bool: expr_none "==" expr_none
#line 716 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 2712 "frontend/parser.cpp"
    break;

  case 382: // expr_bool: expr_bool "!=" expr_bool
#line 718 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 2718 "frontend/parser.cpp"
    break;

  case 383: // expr_bool: expr_int "!=" expr_int
#line 719 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 2724 "frontend/parser.cpp"
    break;

  case 384: // expr_bool: expr_int "!=" expr_float
#line 720 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 2730 "frontend/parser.cpp"
    break;

  case 385: // expr_bool: expr_float "!=" expr_float
#line 721 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 2736 "frontend/parser.cpp"
    break;

  case 386: // expr_bool: expr_float "!=" expr_int
#line 722 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 2742 "frontend/parser.cpp"
    break;

  case 387: // expr_bool: expr_str "!=" expr_str
#line 723 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 2748 "frontend/parser.cpp"
    break;

  case 388: // expr_bool: expr_none "!=" expr_none
#line 724 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 2754 "frontend/parser.cpp"
    break;

  case 389: // expr_bool: expr_int ">" expr_int
#line 726 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 2760 "frontend/parser.cpp"
    break;

  case 390: // expr_bool: expr_int ">" expr_float
#line 727 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 2766 "frontend/parser.cpp"
    break;

  case 391: // expr_bool: expr_float ">" expr_float
#line 728 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 2772 "frontend/parser.cpp"
    break;

  case 392: // expr_bool: expr_float ">" expr_int
#line 729 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 2778 "frontend/parser.cpp"
    break;

  case 393: // expr_bool: expr_str ">" expr_str
#line 730 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 2784 "frontend/parser.cpp"
    break;

  case 394: // expr_bool: expr_int "<" expr_int
#line 732 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 2790 "frontend/parser.cpp"
    break;

  case 395: // expr_bool: expr_int "<" expr_float
#line 733 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 2796 "frontend/parser.cpp"
    break;

  case 396: // expr_bool: expr_float "<" expr_float
#line 734 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 2802 "frontend/parser.cpp"
    break;

  case 397: // expr_bool: expr_float "<" expr_int
#line 735 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 2808 "frontend/parser.cpp"
    break;

  case 398: // expr_bool: expr_str "<" expr_str
#line 736 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 2814 "frontend/parser.cpp"
    break;

  case 399: // expr_bool: expr_int ">=" expr_int
#line 738 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 2820 "frontend/parser.cpp"
    break;

  case 400: // expr_bool: expr_int ">=" expr_float
#line 739 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 2826 "frontend/parser.cpp"
    break;

  case 401: // expr_bool: expr_float ">=" expr_float
#line 740 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 2832 "frontend/parser.cpp"
    break;

  case 402: // expr_bool: expr_float ">=" expr_int
#line 741 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 2838 "frontend/parser.cpp"
    break;

  case 403: // expr_bool: expr_str ">=" expr_str
#line 742 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 2844 "frontend/parser.cpp"
    break;

  case 404: // expr_bool: expr_int "<=" expr_int
#line 744 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 2850 "frontend/parser.cpp"
    break;

  case 405: // expr_bool: expr_int "<=" expr_float
#line 745 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 2856 "frontend/parser.cpp"
    break;

  case 406: // expr_bool: expr_float "<=" expr_float
#line 746 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 2862 "frontend/parser.cpp"
    break;

  case 407: // expr_bool: expr_float "<=" expr_int
#line 747 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 2868 "frontend/parser.cpp"
    break;

  case 408: // expr_bool: expr_str "<=" expr_str
#line 748 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 2874 "frontend/parser.cpp"
    break;

  case 409: // expr_bool: expr_str "in" expr_str
#line 750 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[0].value.as < std::string > ().find(yystack_[2].value.as < std::string > ()) != std::string::npos; }
#line 2880 "frontend/parser.cpp"
    break;

  case 426: // type: "'int'" "?"
#line 778 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2886 "frontend/parser.cpp"
    break;

  case 427: // type: "'float'" "?"
#line 779 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2892 "frontend/parser.cpp"
    break;

  case 428: // type: "'string'" "?"
#line 780 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2898 "frontend/parser.cpp"
    break;

  case 429: // type: "'bool'" "?"
#line 781 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2904 "frontend/parser.cpp"
    break;

  case 430: // type: "identifier" "?"
#line 782 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2910 "frontend/parser.cpp"
    break;

  case 431: // type: funtype "?"
#line 783 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2916 "frontend/parser.cpp"
    break;

  case 432: // type: mattype "?"
#line 784 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2922 "frontend/parser.cpp"
    break;

  case 433: // type: "'int'"
#line 785 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("int", true); }
#line 2928 "frontend/parser.cpp"
    break;

  case 434: // type: "'float'"
#line 786 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("float", true); }
#line 2934 "frontend/parser.cpp"
    break;

  case 435: // type: "'string'"
#line 787 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("string", true); }
#line 2940 "frontend/parser.cpp"
    break;

  case 436: // type: "'bool'"
#line 788 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("bool", true); }
#line 2946 "frontend/parser.cpp"
    break;

  case 437: // type: "identifier"
#line 789 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[0].value.as < std::string > (), true); }
#line 2952 "frontend/parser.cpp"
    break;

  case 438: // type: funtype
#line 790 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2958 "frontend/parser.cpp"
    break;

  case 439: // type: mattype
#line 791 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2964 "frontend/parser.cpp"
    break;


#line 2968 "frontend/parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -744;

  const short  Parser ::yytable_ninf_ = -438;

  const short
   Parser ::yypact_[] =
  {
    1698,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  1494,    30,
     172,  1329,   526,    -6,    25,    68,   106,   127,  2466,  1856,
    -744,  -744,    89,     2,    18,    19,    20,   111,   130,   311,
      33,   108,   332,  -744,  -744,   184,   184,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,   184,   184,   184,   414,  1881,  -744,
     796,  -744,   388,   415,  2892,  3054,   890,   674,   158,   161,
      -4,   247,    50,  1653,   263,   796,   275,   216,   388,   415,
    2785,  2841,   683,   359,  1856,  -744,    50,   285,   230,   597,
     597,  -744,  -744,  -744,  -744,  1357,   147,  2915,  3088,  1198,
    -744,   526,   526,  -744,   287,   291,  -744,  1856,   259,  1856,
     314,  2496,  -744,  -744,   280,  -744,   309,   676,  -744,   785,
    -744,   871,  -744,   945,  -744,    13,  -744,   349,   426,   153,
    1856,  -744,  -744,  -744,    87,  1856,  -744,  -744,  -744,  2570,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  1856,  1856,
    1856,  1856,  1856,  1856,  1856,  1856,  1856,  1856,  1856,  1856,
    1856,  -744,  1056,    87,  1856,  1856,  1856,  1856,  1856,  1856,
    1856,  1856,  1856,  1856,  1856,  1856,  1856,  1856,  1856,  1856,
    1856,  1856,  1856,  1856,  1856,  1856,  -744,    87,  1856,  1856,
    1856,  1856,  1856,  1856,  -744,  1856,  1856,  1856,  1856,  1856,
    1856,  1856,  1856,  1856,  1856,  1856,  1856,  1856,   597,  1856,
    1856,  1856,  1856,  1856,  1856,  1856,  1856,  1856,  1856,  1856,
    1856,  1856,  1856,  1856,  1856,  1856,  1856,  1856,  1856,  1856,
    1856,  1856,  1856,  1856,  1856,  1856,  1856,  1856,  1856,  1856,
    1856,  1856,  1856,  1856,  1856,  1856,  1856,  1856,  1856,  1856,
    1856,  -744,  -744,    52,    -2,   351,  -744,    87,   354,  -744,
    -744,  -744,  1856,  1856,  -744,  -744,  -744,  -744,   250,    44,
     342,  -744,  3147,  1120,   597,   597,   597,   597,   597,   526,
     526,   526,   526,   526,   597,   597,   597,   597,   597,   597,
    2813,  2869,   390,   576,  1329,   306,   306,  1329,   597,   597,
     597,   597,   597,   597,  1329,   597,   597,   597,   597,   597,
     597,  1329,  1329,  1329,  1329,  1329,  1329,  1329,  1329,  1329,
    1329,  1329,  1329,  1329,  1547,  -744,   526,   526,   526,   526,
     526,  1856,    25,   373,   369,   375,  2570,  -744,  1783,   403,
    1856,  -744,  1881,   379,  2892,  3054,   890,   674,   416,  -744,
     427,  -744,   437,  -744,   459,   492,    62,   168,  -744,   515,
     163,   494,  -744,   450,   498,   252,  2892,    16,   252,  -744,
    -744,  1782,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,   518,   500,    63,   348,    47,
     706,   749,   348,    47,   706,   749,   221,   521,   514,   531,
     221,   514,   531,   221,   514,   531,   221,   531,  2327,   419,
     421,  2938,  1786,  1068,   536,  2638,   478,  2586,   636,  2667,
     338,  2750,  3065,  2017,  3003,  2696,  3031,   461,   917,   461,
     917,   745,   716,  -744,  -744,  3096,  1440,   235,  -744,   745,
     716,  -744,  -744,  3096,  1440,   235,  -744,   603,   948,  1037,
     527,   603,   948,  1037,   527,   603,   948,  1037,   527,   603,
     948,  1037,   527,   252,    69,   348,    47,   348,    47,   221,
     521,  2667,   726,   745,   716,   745,   716,  2327,   419,   421,
    2938,  1786,  1068,   536,  2667,   726,   745,  -744,   745,  -744,
    2327,   419,   421,  2938,  1786,  1068,   536,  2667,   726,   745,
    -744,   745,  -744,   348,   706,   749,   348,   706,   749,   221,
     514,   531,   221,   514,   531,   221,   514,   531,  1909,   534,
    2327,   419,   421,  2938,  1786,  1068,   536,  2667,   726,  2750,
    3065,  2017,  3003,  2696,  3031,   461,   917,   461,   917,   745,
    3096,  1440,   745,  3096,  1440,   603,   948,  1037,   603,   948,
    1037,   603,   948,  1037,   603,   948,  1037,   348,   706,   749,
     348,   706,   749,   221,   514,   531,   221,   514,   531,   221,
     514,   531,   221,   514,   531,  2327,   419,   421,  2938,  1786,
    1068,   536,  2667,   726,   745,  3096,  1440,   745,  3096,  1440,
     603,   948,  1037,   603,   948,  1037,   603,   948,  1037,   603,
     948,  1037,   529,  2327,   419,   421,  2938,  1786,  1068,   536,
    2667,   726,   338,   745,   235,   745,   235,   603,   527,   603,
     527,   603,   527,   603,   527,  2327,   419,   421,  2938,  1786,
    1068,   536,  2638,   478,  2586,   636,  2667,   726,   745,  -744,
     745,  -744,  -744,    45,   550,     5,  1138,   248,   141,  -744,
     554,   528,   555,  -744,  1856,  -744,  -744,   974,  1177,   974,
    1177,   514,   534,   514,   534,   514,   534,   755,  1359,   660,
     577,   577,   974,  1177,   974,  1177,   514,   534,   514,   534,
     514,   534,   514,   534,   345,  2976,  3119,   834,   783,   573,
    -744,  -744,   345,  2976,  3119,   834,   783,  1399,  1058,  1399,
    1058,  1399,  1058,  1399,  1058,  1399,  1058,  1399,  1058,   345,
    2976,  3119,   834,   783,  1399,  1058,  1399,  1058,  1399,  1058,
    1399,  1058,  1399,  1058,  1399,  1058,   345,  2976,  3119,   834,
     783,  1155,   476,  1230,  1230,  -744,  -744,  -744,  -744,   345,
    2976,  3119,   834,   783,   442,   212,  -744,  -744,   328,   328,
    -744,  -744,  -744,  -744,  -744,  2466,  1856,  2466,  1940,   580,
    1856,  -744,  1856,  -744,  -744,  -744,  -744,   180,   180,  -744,
     512,   586,   601,     3,    99,   125,   567,     8,  -744,  1104,
     178,  -744,   541,  -744,   568,  -744,  -744,  -744,  1856,  -744,
    -744,  -744,  1239,  -744,   211,  -744,  -744,    99,   151,  -744,
    1856,  -744,  -744,   247,   564,   605,  -744,   622,  -744,   617,
    -744,   615,  -744,   588,  -744,   180,   590,  -744,    99,   211,
     211,   593,  -744,   625,  -744,  1397,  -744,  1543,   190,  1856,
    -744,  -744,  -744,    99,   629,  2466,  -744,  2466,  -744,  -744,
    -744,  1856,  -744,  1856,  -744,    15,   567,    34,  1856,  -744,
    -744,   631,  -744,   647,  -744,  1583,   620,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,   593,  -744,  -744,  -744,  -744,   650,
     602,  -744,  -744
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     9,   308,   322,   343,   370,   300,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    36,
      33,    34,     0,   433,   434,   435,   436,     0,     0,    93,
      94,     0,     0,     4,    10,     0,     0,    35,    15,    17,
      18,    16,    19,    20,     0,     0,     0,     0,    86,   280,
      85,   281,    87,    88,    89,    90,    91,    92,   438,   439,
       0,   300,    93,   287,   280,     0,   281,     0,     0,     0,
     286,     0,     0,     0,     0,   272,    93,   277,     0,     0,
       0,    95,    96,   309,   323,     0,     0,     0,     0,     0,
     372,     0,     0,   311,     0,    31,    30,     0,     0,     0,
       0,     0,    28,    29,     0,    37,     0,     0,   426,     0,
     427,     0,   428,     0,   429,     0,    58,     0,     0,     0,
       0,   430,   106,   302,     0,     0,   107,     1,     3,     0,
       5,     8,     7,    14,    21,    12,    13,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,   105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   431,   432,     0,    64,     0,   301,     0,   302,    97,
     282,   283,     0,     0,   310,   324,   344,   371,     0,     0,
       0,   273,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   309,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,     0,     0,
       0,   417,   287,   424,   286,     0,     0,     0,     0,   419,
       0,   421,     0,   423,     0,     0,     0,     0,   415,     0,
       0,     0,   304,     0,     0,   109,     0,     0,   110,     6,
      82,    81,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    98,     0,    83,     0,   140,   138,
     135,   136,   148,   146,   143,   144,   122,   121,   117,   118,
     127,   125,   126,   132,   130,   131,   114,   113,   271,   269,
     270,   265,   266,   267,   268,   244,   243,   247,   246,   241,
     240,   219,   218,   225,   224,   222,   221,   151,   150,   154,
     153,   199,   197,   194,   195,   190,   191,   192,   193,   216,
     214,   211,   212,   207,   208,   209,   210,   161,   158,   159,
     160,   175,   172,   173,   174,   168,   165,   166,   167,   182,
     179,   180,   181,   111,     0,   139,   137,   147,   145,   120,
     119,   239,   232,   198,   196,   215,   213,   263,   369,   252,
     366,   367,   365,   368,   237,   230,   187,   381,   204,   388,
     264,   257,   258,   253,   254,   255,   256,   238,   231,   189,
     188,   206,   205,   133,   316,   342,   141,   315,   339,   115,
     312,   330,   123,   313,   333,   128,   314,   336,     0,   327,
     259,   354,   248,   351,   352,   350,   353,   233,   226,   217,
     319,   223,   321,   220,   320,   149,   317,   152,   318,   183,
     376,   377,   200,   383,   384,   155,   389,   390,   169,   394,
     395,   162,   399,   400,   176,   404,   405,   134,   341,   340,
     142,   338,   337,   116,   329,   328,   124,   332,   331,   129,
     335,   334,   112,   326,   325,   260,   359,   249,   356,   357,
     355,   358,   234,   227,   184,   379,   378,   201,   386,   385,
     156,   392,   391,   170,   397,   396,   163,   402,   401,   177,
     407,   406,     0,   261,   349,   250,   346,   347,   345,   348,
     235,   228,   409,   185,   380,   202,   387,   157,   393,   171,
     398,   164,   403,   178,   408,   262,   364,   251,   361,   362,
     360,   363,   242,   374,   245,   373,   236,   229,   186,   375,
     203,   382,   411,   437,     0,   412,     0,     0,     0,   303,
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
       0,    67,     0,   416,   418,   420,   422,     0,    47,    44,
       0,     0,     0,     0,     0,     0,    60,     0,   288,     0,
       0,   102,     0,   414,     0,   305,   103,    99,     0,   104,
     101,   100,     0,   410,     0,    66,    65,     0,     0,   284,
       0,   276,   279,     0,    43,     0,    39,    25,    26,     0,
     425,     0,    48,     0,    45,    49,    51,    56,     0,     0,
       0,    59,   292,     0,   290,     0,   289,     0,     0,     0,
      84,   413,    54,     0,     0,     0,    41,     0,    27,    40,
      46,     0,    50,     0,    57,     0,    63,     0,     0,   295,
     294,     0,   293,     0,   291,     0,   306,    55,   285,    42,
      38,    53,    52,    61,     0,    62,   298,   297,   296,     0,
       0,   299,   307
  };

  const short
   Parser ::yypgoto_[] =
  {
    -744,  -744,   -98,   860,   -12,   -17,  -657,  -743,  -744,   341,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -691,  -744,
    -744,   607,    36,  -139,  -744,  -744,   551,   -80,  1487,  2215,
     693,   -59,  1141,   694,   487,  1278,   899,  1294,   -56,  -151,
    1982,     0,   344,   703,  -744,   -74,  -744,   -86,  -221
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    31,    32,   133,    33,    34,   103,   104,    35,    96,
      36,    37,    38,    39,    40,    41,   826,    42,   761,   762,
      43,   117,   765,   766,    44,    45,    46,   375,    47,    48,
      49,    78,    65,    51,   333,   176,    68,    69,   123,   354,
      54,   335,   336,   337,    58,   634,    59,   351,    60
  };

  const short
   Parser ::yytable_[] =
  {
      55,   102,   794,   328,   796,   243,   248,   -58,    71,    55,
      84,    88,   243,   107,   243,   258,   345,   243,    55,    55,
     130,   338,   635,   340,   243,   342,   346,   344,   776,   109,
     111,   113,    55,    74,     3,     4,     5,     6,     7,     8,
     636,     9,    75,   243,   124,   784,    10,   644,     3,     4,
       5,     6,     7,     8,    11,     9,   782,   772,   177,    12,
      10,   247,   632,   119,   180,   758,   801,   802,    11,    94,
     108,   244,   125,    12,    55,   779,   759,    97,   806,   263,
      84,   780,   849,   811,   850,   281,   110,   112,   114,   120,
     853,     3,     4,     5,     6,     7,     8,    55,     9,    55,
      95,    55,   100,    10,   772,    76,    30,   807,   127,   854,
     772,    11,   101,   121,   832,    98,    12,   359,   760,    76,
      30,    23,    24,    25,    26,   763,   767,   633,   349,    55,
     822,    23,    24,    25,    26,   808,    99,   633,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,   834,    55,   771,   381,   385,   389,   392,   395,   397,
     402,   823,    76,    30,   106,   809,   847,   352,   284,   426,
     434,   439,   443,   447,   451,   771,     3,     4,   764,   285,
     286,    79,   772,   758,   131,   471,   115,   132,    80,   484,
     814,   809,   353,   495,   498,   501,   504,   507,   509,   514,
     645,    12,   844,   752,   772,   116,   531,   534,   537,   540,
     543,   546,   549,   552,   555,   558,   561,   564,   569,   815,
     576,   579,   582,   585,   588,   591,   241,   597,   748,   242,
     152,   845,   153,   260,   310,   619,   760,    23,    24,    25,
      26,   159,   261,   633,   312,   313,   226,    81,    82,    23,
      24,    25,    26,   642,   252,   633,   253,   246,   787,    55,
     175,   152,   643,   153,   648,   650,   652,   654,   656,   231,
     232,   233,   234,   250,   663,   665,   667,   669,   671,   673,
      23,    24,    25,    26,   676,   251,   633,   684,   688,   690,
     692,   694,   696,   698,   701,   705,   707,   709,   711,   713,
     715,   718,    88,    88,    88,    88,    88,    88,    88,   731,
      88,    88,    88,    88,     7,   679,   130,    23,    24,    25,
      26,    55,   118,   633,   119,   259,    55,   326,    55,   321,
      55,   322,   128,   129,   324,     2,     3,     4,     5,     6,
       7,     8,   329,     9,    56,   318,   319,   320,    10,   226,
     120,   330,    72,    56,   646,    89,    11,   152,   347,   153,
     637,    12,    56,    56,   639,   156,   157,   158,   159,   257,
     229,   230,   231,   232,   233,   234,    56,   285,   286,   121,
     235,   236,   237,   745,   238,   747,  -437,   175,    13,    14,
      15,   239,   240,    16,    17,    18,    19,    20,    21,    22,
     256,    23,    24,    25,    26,    27,    28,    29,    30,   185,
     746,   301,   750,   186,   131,   302,   767,   132,    56,   752,
     187,   188,   303,   304,   305,   306,   307,   308,   753,   282,
       3,     4,     5,     6,     7,     8,   189,     9,   348,   754,
     190,    56,    10,    56,   186,    56,   190,   191,   192,   755,
      11,   187,   188,   191,   192,    12,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   349,   149,   150,
     152,   756,   153,    56,   312,   313,   154,   155,   156,   157,
     158,   159,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    67,    56,   309,   310,   311,
     175,    76,    30,   238,   403,   757,   773,   410,   312,   313,
     239,   240,   775,   427,   435,   440,   444,   448,   452,     3,
       4,     5,     6,     7,     8,   774,     9,   768,   777,   472,
       3,    10,   177,   485,   198,    91,   763,   763,   226,    11,
     778,   781,    92,   515,    12,     3,     4,     5,     6,     7,
       8,   217,     9,   816,   279,    12,   769,    10,   236,   237,
     783,   238,   570,   635,   789,    11,   790,   791,   239,   240,
      12,   598,   602,   604,   606,   608,   610,   612,   614,   620,
     786,   793,   817,   798,   763,   792,   257,   803,   835,   837,
      76,    30,   316,   317,   318,   319,   320,   309,   310,   311,
     804,     3,     4,    56,   805,   350,    79,   810,   312,   313,
     819,   357,   152,    80,   153,   827,    76,    30,   154,   155,
     156,   157,   158,   159,   825,   828,    12,   829,   677,   830,
     831,   685,   833,   167,   168,   838,    55,   839,   702,   848,
     377,   353,   175,   856,    55,   719,   721,   723,   724,   725,
     726,   727,   728,   732,    89,    89,    89,    89,   236,   857,
     860,   238,   861,   744,   454,    56,   800,   245,   239,   240,
      56,   836,    56,   788,    56,   316,   317,   318,   319,   320,
       3,     4,     5,     6,     7,     8,   269,     9,   331,   360,
     272,   273,    10,   256,   226,   235,   236,   237,   820,   238,
      11,    64,    66,    57,   227,    12,   239,   240,   228,   862,
     821,    73,    57,   592,    90,   229,   230,   231,   232,   233,
     234,    57,    57,   195,   196,   197,   198,   177,   102,     0,
     102,   178,   179,   180,   638,    57,   130,   177,     0,   640,
     641,   178,   179,   180,     0,    55,    55,    55,    55,     0,
      55,    76,    30,     0,   152,     0,   153,     0,   182,   183,
     154,   155,   156,   157,   158,   159,   214,   215,   216,   217,
     316,   317,   318,   319,   320,   167,   168,    57,    55,   171,
     172,   173,   174,     0,   175,   272,   273,     0,   283,     3,
       4,     5,     6,     7,     8,     0,     9,   339,     0,     0,
      57,    10,    57,     0,    57,   310,   311,   177,   102,    11,
     102,   178,   179,   180,    12,   312,   313,     0,     0,    55,
       0,   181,     0,     0,     0,    55,     0,    55,   182,   183,
       0,    55,    57,    55,     0,     0,   770,     0,    55,     0,
       0,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,     0,    57,     0,     0,     0,   302,
      76,    30,     0,   404,   406,   408,   303,   304,   305,   306,
     307,   308,   428,   436,     0,     3,     4,     5,     6,     7,
       8,     0,     9,   341,     0,     0,     0,    10,   473,     0,
       0,     0,   486,     0,     0,    11,   134,     0,     0,    52,
      12,   226,   516,     0,   135,   136,   137,   151,    52,     0,
      86,   227,     0,     0,     0,   228,     0,    52,    52,     0,
       0,   571,   229,   230,   231,   232,   233,   234,     0,     0,
     599,    52,   193,   194,   195,   196,   197,   198,   621,   623,
     625,     0,   629,   631,     0,     0,    76,    30,     0,     3,
       4,     5,     6,     7,     8,     0,     9,   343,     0,     0,
       0,    10,    57,   193,   194,   195,   196,   197,   198,    11,
       0,     0,     0,    52,    12,     0,     0,     0,   204,   205,
      56,     0,     0,     0,    86,     0,     0,   678,    56,     0,
     686,   266,   267,   268,   198,     0,    52,   703,    52,     0,
      52,     0,     0,     0,   720,   722,   722,   722,   722,   722,
     722,   722,   733,   734,   735,   736,   737,     0,     0,     0,
      76,    30,     0,     0,    57,     0,     0,     0,    52,    57,
       0,    57,     0,    57,     0,     0,     0,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
       0,    52,   212,   213,   214,   215,   216,   217,     0,   399,
       3,     4,     5,     6,     7,     8,   374,     9,   423,   431,
       0,     0,    10,   274,   275,   276,   277,   278,   279,   226,
      11,     0,     0,     0,   468,    12,   477,   479,   481,    56,
      56,    56,    56,   228,    56,     0,     0,     0,   511,     0,
     229,   230,   231,   232,   233,   234,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     9,   812,   566,     0,     0,
      10,     0,    56,     0,     0,     0,   594,     0,    11,     0,
     255,    76,    30,    12,   616,   274,   275,   276,   277,   278,
     279,    50,     3,     4,     5,     6,     7,     8,     0,     9,
      50,   119,     0,     0,    10,     0,     0,     0,    52,    50,
      50,     0,    11,    56,     0,     0,     0,    12,     0,    56,
       0,    56,     0,    50,     0,    56,     0,    56,     0,    76,
      30,     0,    56,   674,   680,   681,   682,   303,   304,   305,
     306,   307,   308,   699,   276,   277,   278,   279,     0,     0,
     716,    86,    86,    86,    86,    86,    86,    86,   729,    86,
      86,    86,    86,    76,    30,    50,     0,     0,     0,   301,
      52,     0,     0,   302,     0,    52,     0,    52,     0,    52,
     303,   304,   305,   306,   307,   308,     0,     0,    50,     0,
      50,     0,    50,     3,     4,     5,     6,     7,     8,     0,
       9,   348,     0,     0,     0,    10,   813,     0,     0,   818,
       0,     0,     0,    11,   305,   306,   307,   308,    12,     0,
      50,     0,     0,     0,     0,     0,     0,   824,     0,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,     0,    50,    53,   379,   383,   387,     0,     0,
       0,     0,   841,    53,   843,     0,     0,   122,   126,     0,
     422,   430,    53,    53,    76,    30,     0,     0,     0,   456,
     458,   460,   462,   464,   466,     0,    53,   475,   184,     0,
       0,   488,   859,     3,     4,     5,     6,     7,    85,    57,
     122,   518,     0,   184,     0,    80,     0,    57,     0,     0,
       0,     0,     0,    11,   122,     0,     0,     0,    12,     0,
     573,     3,     4,     5,     6,    61,    85,     0,    53,   601,
       0,     0,     0,    80,   316,   317,   318,   319,   320,   627,
       0,    11,     0,     0,     0,   269,    12,   271,     0,   272,
     273,    53,     0,    53,     0,    53,     0,     0,     0,     0,
      50,     3,     4,     5,     6,     7,     8,     0,     9,   840,
       0,     0,     0,    10,   264,   265,   266,   267,   268,   198,
       0,    11,     0,    53,     0,     0,    12,     0,     0,   272,
     273,     0,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,     0,    53,     0,    57,    57,
      57,    57,     0,    57,   400,   212,   213,   214,   215,   216,
     217,     0,    50,   424,   432,     0,     0,    50,     0,    50,
       0,    50,    76,    30,   222,   223,   224,   225,     0,   469,
       0,    57,     0,   482,     0,   490,   492,     0,     0,     0,
       0,     0,     0,   512,     0,     0,    77,     0,     3,     4,
       5,     6,    61,     8,     0,     9,   105,     0,     0,     0,
      10,     0,   567,     0,     0,     0,     0,     0,    11,     0,
       0,   595,    57,    12,     0,     0,     0,     0,    57,   617,
      57,     0,     0,     0,    57,    52,    57,     0,     0,     0,
       0,    57,     0,    52,     0,     0,     0,     3,     4,     5,
       6,     7,     8,    53,     9,   842,     0,   254,     0,    10,
       0,    77,   316,   317,   318,   319,   320,    11,     0,    62,
      30,     0,    12,   269,   270,   271,     0,   272,   273,     0,
       0,     0,     0,     0,   323,     0,   325,     3,     4,     5,
       6,     7,     8,     0,     9,   858,     0,     0,     0,    10,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     0,
       0,     0,    12,     0,     0,    53,     0,     0,    76,    30,
      53,     0,    53,     0,    53,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,     0,   376,
       0,     0,     0,     0,    52,    52,    52,    52,     0,    52,
       0,     0,     0,     0,     0,     0,     0,   184,    76,    30,
       0,   184,   152,   249,   153,   184,     0,     0,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    52,   163,   164,
     165,   166,     0,   167,   168,   169,   170,   171,   172,   173,
     174,     0,   175,     0,     0,     0,     0,     0,     1,     0,
     184,     2,     3,     4,     5,     6,     7,     8,   184,     9,
       0,     0,     0,     0,    10,     0,     0,     0,    52,     0,
       0,     0,    11,     0,    52,     0,    52,    12,     0,     0,
      52,     0,    52,     0,   184,     0,   184,    52,   184,     0,
     184,     0,   184,     0,   184,     0,    77,     0,     0,     0,
       0,     0,     0,   184,    13,    14,    15,     0,     0,    16,
      17,    18,    19,    20,    21,    22,   184,    23,    24,    25,
      26,    27,    28,    29,    30,     0,     0,    50,     0,     0,
       0,     0,     0,     0,   129,    50,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,   184,   749,     0,    10,
       0,   212,   213,   214,   215,   216,   217,    11,   743,     0,
       0,   219,    12,     0,     0,     0,     0,   751,   220,   221,
     222,   223,   224,   225,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,     0,   149,   150,     0,    13,
      14,    15,     0,     0,    16,    17,    18,    19,    20,    21,
      22,   184,    23,    24,    25,    26,    27,    28,    29,    30,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,     0,    10,     0,     0,     0,     0,     0,     0,   184,
      11,     0,     0,     0,     0,    12,    50,    50,    50,    50,
     152,    50,   153,     0,     0,     0,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   184,   163,   164,   165,   166,
       0,   167,   168,   169,   170,   171,   172,   173,   174,    50,
     175,     0,     0,     0,   264,   265,   266,   267,   268,   198,
      53,    76,    30,     0,     0,   269,   270,   271,    53,   272,
     273,   129,     0,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,   797,     0,    10,     0,     0,     0,
      50,     0,     0,     0,    11,     0,    50,     0,    50,    12,
       0,     0,    50,     0,    50,     0,     0,     0,     0,    50,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,     0,    83,    87,    93,     0,    13,    14,    15,     0,
       0,    16,    17,    18,    19,    20,    21,    22,     0,    23,
      24,    25,    26,    27,    28,    29,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   152,     0,   153,     0,
       0,     0,   154,   155,   156,   157,   158,   159,     0,    53,
      53,    53,    53,   164,    53,   166,     0,   167,   168,   169,
     170,   171,   172,   173,   174,     0,   175,     0,     0,     0,
       0,   262,    83,     0,     0,     0,     0,   280,     0,     0,
       0,     0,    53,   314,   315,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   334,
       0,   334,     0,   334,     0,   334,     0,     0,     0,     0,
     334,     0,   356,     0,     0,     0,   334,   356,     0,     0,
       0,     0,     0,    53,     0,     0,     0,     0,     0,    53,
       0,    53,     0,   785,     0,    53,     0,    53,     0,     0,
       0,    77,    53,     0,     0,   334,   380,   384,   388,   391,
     394,   356,   401,   356,   356,   356,   412,   414,   416,   418,
     420,   425,   433,   438,   442,   446,   450,   356,     0,   334,
     356,   356,   356,   356,   356,   356,     0,   470,   356,   356,
     356,   483,   356,   356,   356,   494,   497,   500,   503,   506,
     508,   513,   356,   520,   522,   524,   526,   528,   530,   533,
     536,   539,   542,   545,   548,   551,   554,   557,   560,   563,
     568,   356,   575,   578,   581,   584,   587,   590,   334,   596,
     356,   356,   356,   356,   356,   356,   356,   618,   356,   356,
     356,   356,   356,    63,     0,     0,     0,     0,     0,   334,
       0,     0,     0,   795,   334,   334,     0,   799,     0,     0,
       0,     0,     0,     0,     0,     0,   647,   649,   651,   653,
     655,   657,   658,   659,   660,   661,   662,   664,   666,   668,
     670,   672,     0,     0,     0,   376,   675,     0,     0,   683,
     687,   689,   691,   693,   695,   697,   700,   704,   706,   708,
     710,   712,   714,   717,    87,    87,    87,    87,    87,    87,
      87,   730,    87,    87,    87,    87,     0,     0,   738,   739,
     740,   741,   742,     0,     0,     0,   846,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   851,     0,
     852,     0,   332,     0,   332,   855,   332,     0,   332,     0,
       0,   334,     0,   332,     0,   355,   152,     0,   153,   332,
     358,     0,   154,   155,   156,   157,   158,   159,     0,   161,
     162,     0,   163,   164,   165,   166,     0,   167,   168,   169,
     170,   171,   172,   173,   174,     0,   175,     0,   332,   378,
     382,   386,   390,   393,   396,   398,   405,   407,   409,   411,
     413,   415,   417,   419,   421,   429,   437,   441,   445,   449,
     453,     0,   332,   455,   457,   459,   461,   463,   465,     0,
     467,   474,   476,   478,   480,   487,   489,   491,   493,   496,
     499,   502,   505,     0,   510,   517,   519,   521,   523,   525,
     527,   529,   532,   535,   538,   541,   544,   547,   550,   553,
     556,   559,   562,   565,   572,   574,   577,   580,   583,   586,
     589,   332,   593,   600,   603,   605,   607,   609,   611,   613,
     615,   622,   624,   626,   628,   630,     0,     0,     0,     0,
       0,     0,   332,     0,     0,     0,     0,   332,   332,   100,
       3,     4,     5,     6,     7,     8,     0,     9,     0,   101,
       0,     0,    10,     0,     0,     0,     0,     0,     0,     0,
      11,     0,     0,     0,     0,    12,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
     327,     0,    10,     0,     0,     0,     0,     0,     0,     0,
      11,     0,    13,    14,    15,    12,     0,    16,    17,    18,
      19,    20,    21,    22,     0,    23,    24,    25,    26,    27,
      28,    29,    30,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    13,    14,    15,     0,     0,    16,    17,    18,
      19,    20,    21,    22,   332,    23,    24,    25,    26,    27,
      28,    29,    30,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,     0,     0,    10,     0,     0,     0,
       0,     0,     0,     0,    11,   152,     0,   153,     0,    12,
       0,   154,   155,   156,   157,   158,   159,     0,   161,     0,
       0,   163,   164,   165,   166,     0,   167,   168,   169,   170,
     171,   172,   173,   174,     0,   175,    13,    14,    15,     0,
       0,    16,    17,    18,    19,    20,    21,    22,     0,    23,
      24,    25,    26,    27,    28,    29,    30,   152,     0,   153,
       0,     0,     0,   154,   155,   156,   157,   158,   159,     0,
       0,     0,     0,   163,   164,   165,   166,     0,   167,   168,
     169,   170,   171,   172,   173,   174,   152,   175,   153,     0,
       0,     0,   154,   155,   156,   157,   158,   159,     0,     0,
       0,     0,     0,   164,   165,   166,     0,   167,   168,   169,
     170,   171,   172,   173,   174,   152,   175,   153,     0,     0,
       0,   154,   155,   156,   157,   158,   159,     0,     0,     0,
       0,     0,   164,     0,     0,     0,   167,   168,   169,   170,
     171,   172,   173,   174,   334,   175,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   334,     0,     0,   334,     0,     0,     0,     0,   152,
       0,   153,     0,     0,   334,   154,   155,   156,   157,   158,
     159,     0,   334,     0,     0,     0,     0,     0,     0,     0,
     167,   168,   169,   170,   171,   172,   173,   174,     0,   175,
       0,     0,     0,     0,     0,   254,     0,   334,     0,   334,
     193,   194,   195,   196,   197,   198,   199,     0,     0,     0,
     200,   201,   202,   203,     0,   204,   205,   206,   207,   208,
     209,   210,   211,   254,     0,     0,     0,   334,   264,   265,
     266,   267,   268,   198,   287,     0,     0,     0,     0,   269,
     270,   271,     0,   272,   273,   288,   289,   290,   291,   292,
     293,   255,     0,     0,     0,     0,   212,   213,   214,   215,
     216,   217,   218,     0,     0,     0,   219,     0,     0,     0,
       0,     0,     0,   220,   221,   222,   223,   224,   225,   255,
       0,     0,     0,     0,   274,   275,   276,   277,   278,   279,
     294,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   295,   296,   297,   298,   299,   300,   193,   194,   195,
     196,   197,   198,   199,     0,     0,     0,   200,   201,   202,
     203,     0,   204,   205,   206,   207,   208,   209,   210,   211,
     264,   265,   266,   267,   268,   198,   287,     0,     0,     0,
       0,   269,   270,   271,     0,   272,   273,   288,   289,   290,
     291,   292,   293,   193,   194,   195,   196,   197,   198,     0,
       0,     0,     0,   200,   201,   202,   203,   332,   204,   205,
     206,   207,   208,   209,   210,   211,     0,     0,     0,     0,
       0,     0,     0,     0,   332,     0,     0,   332,     0,     0,
       0,   264,   265,   266,   267,   268,   198,   332,     0,     0,
       0,     0,   269,   270,   271,   332,   272,   273,   288,   289,
     290,   291,   292,   293,     0,     0,     0,     0,   193,   194,
     195,   196,   197,   198,     0,     0,     0,     0,     0,   201,
     332,   203,   332,   204,   205,   206,   207,   208,   209,   210,
     211,     0,     0,     0,     0,     0,   193,   194,   195,   196,
     197,   198,     0,     0,     0,     0,     0,   201,     0,     0,
     332,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,     0,     0,     0,   219,
     193,   194,   195,   196,   197,   198,   220,   221,   222,   223,
     224,   225,     0,     0,     0,   204,   205,   206,   207,   208,
     209,   210,   211,   274,   275,   276,   277,   278,   279,   294,
       0,   193,   194,   195,   196,   197,   198,     0,     0,     0,
     295,   296,   297,   298,   299,   300,   204,   205,     0,     0,
     208,   209,   210,   211,   274,   275,   276,   277,   278,   279,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   295,   296,   297,   298,   299,   300,   254,     0,     0,
       0,     0,   264,   265,   266,   267,   268,   198,     0,     0,
       0,     0,     0,   269,   270,   271,     0,   272,   273
  };

  const short
   Parser ::yycheck_[] =
  {
       0,    18,   745,   101,   747,     9,    62,     9,     8,     9,
      10,    11,     9,    11,     9,    74,     3,     9,    18,    19,
      32,   107,   243,   109,     9,   111,    13,   113,    12,    11,
      11,    11,    32,     3,     4,     5,     6,     7,     8,     9,
      42,    11,    12,     9,    11,    40,    16,     3,     4,     5,
       6,     7,     8,     9,    24,    11,    11,    41,    11,    29,
      16,    11,    10,    13,    17,     3,   757,   758,    24,    75,
      68,    75,    39,    29,    74,    12,    14,     9,    75,    79,
      80,    12,   825,    75,   827,    85,    68,    68,    68,    39,
      75,     4,     5,     6,     7,     8,     9,    97,    11,    99,
      75,   101,     3,    16,    41,    75,    76,   764,     0,    75,
      41,    24,    13,    68,   805,     9,    29,   129,    56,    75,
      76,    69,    70,    71,    72,   346,   347,    75,    41,   129,
     787,    69,    70,    71,    72,    10,     9,    75,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   808,   152,    12,   154,   155,   156,   157,   158,   159,
     160,    10,    75,    76,    75,    40,   823,    14,    21,   169,
     170,   171,   172,   173,   174,    12,     4,     5,    10,    32,
      33,     9,    41,     3,     0,   185,    75,     3,    16,   189,
      12,    40,    39,   193,   194,   195,   196,   197,   198,   199,
     259,    29,    12,    40,    41,    75,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,    41,
     220,   221,   222,   223,   224,   225,    68,   227,   326,    68,
       9,    41,    11,     3,    22,   235,    56,    69,    70,    71,
      72,    20,    12,    75,    32,    33,    11,    75,    76,    69,
      70,    71,    72,     3,    38,    75,    40,    10,    10,   259,
      39,     9,    12,    11,   264,   265,   266,   267,   268,    34,
      35,    36,    37,    10,   274,   275,   276,   277,   278,   279,
      69,    70,    71,    72,   284,    10,    75,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,     8,     9,   328,    69,    70,    71,
      72,   321,    11,    75,    13,    40,   326,    13,   328,    42,
     330,    40,     0,     1,    75,     3,     4,     5,     6,     7,
       8,     9,    62,    11,     0,    17,    18,    19,    16,    11,
      39,    42,     8,     9,    12,    11,    24,     9,     9,    11,
       9,    29,    18,    19,    10,    17,    18,    19,    20,    10,
      32,    33,    34,    35,    36,    37,    32,    32,    33,    68,
      21,    22,    23,    10,    25,    10,    75,    39,    56,    57,
      58,    32,    33,    61,    62,    63,    64,    65,    66,    67,
      10,    69,    70,    71,    72,    73,    74,    75,    76,    21,
      41,    21,     9,    25,     0,    25,   637,     3,    74,    40,
      32,    33,    32,    33,    34,    35,    36,    37,    12,    85,
       4,     5,     6,     7,     8,     9,    21,    11,    12,    12,
      25,    97,    16,    99,    25,   101,    25,    32,    33,    12,
      24,    32,    33,    32,    33,    29,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    41,    54,    55,
       9,    12,    11,   129,    32,    33,    15,    16,    17,    18,
      19,    20,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,     8,   152,    21,    22,    23,
      39,    75,    76,    25,   160,    13,    12,   163,    32,    33,
      32,    33,    14,   169,   170,   171,   172,   173,   174,     4,
       5,     6,     7,     8,     9,    75,    11,    12,    10,   185,
       4,    16,    11,   189,    20,     9,   757,   758,    11,    24,
      40,    12,    16,   199,    29,     4,     5,     6,     7,     8,
       9,    20,    11,    12,    20,    29,    41,    16,    22,    23,
      10,    25,   218,   784,    10,    24,    38,    12,    32,    33,
      29,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     636,     8,    41,     3,   805,   644,    10,    75,   809,   810,
      75,    76,    15,    16,    17,    18,    19,    21,    22,    23,
      14,     4,     5,   259,     3,   118,     9,    40,    32,    33,
      42,   124,     9,    16,    11,    10,    75,    76,    15,    16,
      17,    18,    19,    20,    60,     3,    29,    10,   284,    14,
      42,   287,    42,    30,    31,    42,   636,    12,   294,    10,
     153,    39,    39,    12,   644,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,    22,    12,
      40,    25,    12,   322,   177,   321,   752,    60,    32,    33,
     326,   810,   328,   637,   330,    15,    16,    17,    18,    19,
       4,     5,     6,     7,     8,     9,    26,    11,    12,   138,
      30,    31,    16,    10,    11,    21,    22,    23,   778,    25,
      24,     8,     8,     0,    21,    29,    32,    33,    25,   860,
     784,     8,     9,   226,    11,    32,    33,    34,    35,    36,
      37,    18,    19,    17,    18,    19,    20,    11,   745,    -1,
     747,    15,    16,    17,   247,    32,   748,    11,    -1,   252,
     253,    15,    16,    17,    -1,   745,   746,   747,   748,    -1,
     750,    75,    76,    -1,     9,    -1,    11,    -1,    32,    33,
      15,    16,    17,    18,    19,    20,    17,    18,    19,    20,
      15,    16,    17,    18,    19,    30,    31,    74,   778,    34,
      35,    36,    37,    -1,    39,    30,    31,    -1,    85,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    -1,    -1,
      97,    16,    99,    -1,   101,    22,    23,    11,   825,    24,
     827,    15,    16,    17,    29,    32,    33,    -1,    -1,   819,
      -1,    25,    -1,    -1,    -1,   825,    -1,   827,    32,    33,
      -1,   831,   129,   833,    -1,    -1,   349,    -1,   838,    -1,
      -1,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,    -1,   152,    -1,    -1,    -1,    25,
      75,    76,    -1,   160,   161,   162,    32,    33,    34,    35,
      36,    37,   169,   170,    -1,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    -1,    -1,    -1,    16,   185,    -1,
      -1,    -1,   189,    -1,    -1,    24,    36,    -1,    -1,     0,
      29,    11,   199,    -1,    44,    45,    46,    47,     9,    -1,
      11,    21,    -1,    -1,    -1,    25,    -1,    18,    19,    -1,
      -1,   218,    32,    33,    34,    35,    36,    37,    -1,    -1,
     227,    32,    15,    16,    17,    18,    19,    20,   235,   236,
     237,    -1,   239,   240,    -1,    -1,    75,    76,    -1,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    -1,    -1,
      -1,    16,   259,    15,    16,    17,    18,    19,    20,    24,
      -1,    -1,    -1,    74,    29,    -1,    -1,    -1,    30,    31,
     636,    -1,    -1,    -1,    85,    -1,    -1,   284,   644,    -1,
     287,    17,    18,    19,    20,    -1,    97,   294,    99,    -1,
     101,    -1,    -1,    -1,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,    -1,    -1,    -1,
      75,    76,    -1,    -1,   321,    -1,    -1,    -1,   129,   326,
      -1,   328,    -1,   330,    -1,    -1,    -1,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
      -1,   152,    15,    16,    17,    18,    19,    20,    -1,   160,
       4,     5,     6,     7,     8,     9,    10,    11,   169,   170,
      -1,    -1,    16,    15,    16,    17,    18,    19,    20,    11,
      24,    -1,    -1,    -1,   185,    29,   187,   188,   189,   745,
     746,   747,   748,    25,   750,    -1,    -1,    -1,   199,    -1,
      32,    33,    34,    35,    36,    37,    -1,    -1,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,   218,    -1,    -1,
      16,    -1,   778,    -1,    -1,    -1,   227,    -1,    24,    -1,
      10,    75,    76,    29,   235,    15,    16,    17,    18,    19,
      20,     0,     4,     5,     6,     7,     8,     9,    -1,    11,
       9,    13,    -1,    -1,    16,    -1,    -1,    -1,   259,    18,
      19,    -1,    24,   819,    -1,    -1,    -1,    29,    -1,   825,
      -1,   827,    -1,    32,    -1,   831,    -1,   833,    -1,    75,
      76,    -1,   838,   284,   285,   286,   287,    32,    33,    34,
      35,    36,    37,   294,    17,    18,    19,    20,    -1,    -1,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,    75,    76,    74,    -1,    -1,    -1,    21,
     321,    -1,    -1,    25,    -1,   326,    -1,   328,    -1,   330,
      32,    33,    34,    35,    36,    37,    -1,    -1,    97,    -1,
      99,    -1,   101,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    -1,    -1,    -1,    16,   769,    -1,    -1,   772,
      -1,    -1,    -1,    24,    34,    35,    36,    37,    29,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,   790,    -1,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,    -1,   152,     0,   154,   155,   156,    -1,    -1,
      -1,    -1,   815,     9,   817,    -1,    -1,    29,    30,    -1,
     169,   170,    18,    19,    75,    76,    -1,    -1,    -1,   178,
     179,   180,   181,   182,   183,    -1,    32,   186,    50,    -1,
      -1,   190,   845,     4,     5,     6,     7,     8,     9,   636,
      62,   200,    -1,    65,    -1,    16,    -1,   644,    -1,    -1,
      -1,    -1,    -1,    24,    76,    -1,    -1,    -1,    29,    -1,
     219,     4,     5,     6,     7,     8,     9,    -1,    74,   228,
      -1,    -1,    -1,    16,    15,    16,    17,    18,    19,   238,
      -1,    24,    -1,    -1,    -1,    26,    29,    28,    -1,    30,
      31,    97,    -1,    99,    -1,   101,    -1,    -1,    -1,    -1,
     259,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      -1,    -1,    -1,    16,    15,    16,    17,    18,    19,    20,
      -1,    24,    -1,   129,    -1,    -1,    29,    -1,    -1,    30,
      31,    -1,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,    -1,   152,    -1,   745,   746,
     747,   748,    -1,   750,   160,    15,    16,    17,    18,    19,
      20,    -1,   321,   169,   170,    -1,    -1,   326,    -1,   328,
      -1,   330,    75,    76,    34,    35,    36,    37,    -1,   185,
      -1,   778,    -1,   189,    -1,   191,   192,    -1,    -1,    -1,
      -1,    -1,    -1,   199,    -1,    -1,     9,    -1,     4,     5,
       6,     7,     8,     9,    -1,    11,    19,    -1,    -1,    -1,
      16,    -1,   218,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,   227,   819,    29,    -1,    -1,    -1,    -1,   825,   235,
     827,    -1,    -1,    -1,   831,   636,   833,    -1,    -1,    -1,
      -1,   838,    -1,   644,    -1,    -1,    -1,     4,     5,     6,
       7,     8,     9,   259,    11,    12,    -1,    10,    -1,    16,
      -1,    74,    15,    16,    17,    18,    19,    24,    -1,    75,
      76,    -1,    29,    26,    27,    28,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    97,    -1,    99,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    29,    -1,    -1,   321,    -1,    -1,    75,    76,
     326,    -1,   328,    -1,   330,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,    -1,   152,
      -1,    -1,    -1,    -1,   745,   746,   747,   748,    -1,   750,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   379,    75,    76,
      -1,   383,     9,    10,    11,   387,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   778,    25,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    -1,    -1,    -1,    -1,    -1,     0,    -1,
     422,     3,     4,     5,     6,     7,     8,     9,   430,    11,
      -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,   819,    -1,
      -1,    -1,    24,    -1,   825,    -1,   827,    29,    -1,    -1,
     831,    -1,   833,    -1,   456,    -1,   458,   838,   460,    -1,
     462,    -1,   464,    -1,   466,    -1,   259,    -1,    -1,    -1,
      -1,    -1,    -1,   475,    56,    57,    58,    -1,    -1,    61,
      62,    63,    64,    65,    66,    67,   488,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,   636,    -1,    -1,
      -1,    -1,    -1,    -1,     1,   644,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,   518,    14,    -1,    16,
      -1,    15,    16,    17,    18,    19,    20,    24,   321,    -1,
      -1,    25,    29,    -1,    -1,    -1,    -1,   330,    32,    33,
      34,    35,    36,    37,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    -1,    56,
      57,    58,    -1,    -1,    61,    62,    63,    64,    65,    66,
      67,   573,    69,    70,    71,    72,    73,    74,    75,    76,
       4,     5,     6,     7,     8,     9,    -1,    11,    -1,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,   601,
      24,    -1,    -1,    -1,    -1,    29,   745,   746,   747,   748,
       9,   750,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,   627,    25,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,   778,
      39,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
     636,    75,    76,    -1,    -1,    26,    27,    28,   644,    30,
      31,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    -1,    14,    -1,    16,    -1,    -1,    -1,
     819,    -1,    -1,    -1,    24,    -1,   825,    -1,   827,    29,
      -1,    -1,   831,    -1,   833,    -1,    -1,    -1,    -1,   838,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       8,    -1,    10,    11,    12,    -1,    56,    57,    58,    -1,
      -1,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    -1,   745,
     746,   747,   748,    26,   750,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    39,    -1,    -1,    -1,
      -1,    79,    80,    -1,    -1,    -1,    -1,    85,    -1,    -1,
      -1,    -1,   778,    91,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
      -1,   109,    -1,   111,    -1,   113,    -1,    -1,    -1,    -1,
     118,    -1,   120,    -1,    -1,    -1,   124,   125,    -1,    -1,
      -1,    -1,    -1,   819,    -1,    -1,    -1,    -1,    -1,   825,
      -1,   827,    -1,   636,    -1,   831,    -1,   833,    -1,    -1,
      -1,   644,   838,    -1,    -1,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,    -1,   177,
     178,   179,   180,   181,   182,   183,    -1,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,     8,    -1,    -1,    -1,    -1,    -1,   247,
      -1,    -1,    -1,   746,   252,   253,    -1,   750,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,    -1,    -1,    -1,   778,   284,    -1,    -1,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,    -1,    -1,   316,   317,
     318,   319,   320,    -1,    -1,    -1,   819,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   831,    -1,
     833,    -1,   107,    -1,   109,   838,   111,    -1,   113,    -1,
      -1,   349,    -1,   118,    -1,   120,     9,    -1,    11,   124,
     125,    -1,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    -1,    25,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    39,    -1,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,   177,   178,   179,   180,   181,   182,   183,    -1,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,    -1,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,    -1,    -1,    -1,    -1,
      -1,    -1,   247,    -1,    -1,    -1,    -1,   252,   253,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    -1,    13,
      -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    -1,    -1,
      14,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    56,    57,    58,    29,    -1,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    -1,    -1,    61,    62,    63,
      64,    65,    66,    67,   349,    69,    70,    71,    72,    73,
      74,    75,    76,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,     9,    -1,    11,    -1,    29,
      -1,    15,    16,    17,    18,    19,    20,    -1,    22,    -1,
      -1,    25,    26,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    39,    56,    57,    58,    -1,
      -1,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,     9,    -1,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,     9,    39,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,     9,    39,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,   752,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   769,    -1,    -1,   772,    -1,    -1,    -1,    -1,     9,
      -1,    11,    -1,    -1,   782,    15,    16,    17,    18,    19,
      20,    -1,   790,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    10,    -1,   815,    -1,   817,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      25,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    10,    -1,    -1,    -1,   845,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    10,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    10,
      -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    37,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    25,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,   752,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   769,    -1,    -1,   772,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,   782,    -1,    -1,
      -1,    -1,    26,    27,    28,   790,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,
     815,    28,   817,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,
     845,    30,    31,    32,    33,    34,    35,    36,    37,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    25,
      15,    16,    17,    18,    19,    20,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    15,    16,    17,    18,    19,    20,    21,
      -1,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    37,    30,    31,    -1,    -1,
      34,    35,    36,    37,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    37,    10,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    -1,    30,    31
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
       3,    13,    83,    84,    85,   106,    75,    11,    68,    11,
      68,    11,    68,    11,    68,    75,    75,    99,    11,    13,
      39,    68,   113,   116,    11,    39,   113,     0,     0,     1,
      82,     0,     3,    81,    81,    81,    81,    81,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    54,
      55,    81,     9,    11,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    25,    26,    27,    28,    30,    31,    32,
      33,    34,    35,    36,    37,    39,   113,    11,    15,    16,
      17,    25,    32,    33,   113,    21,    25,    32,    33,    21,
      25,    32,    33,    15,    16,    17,    18,    19,    20,    21,
      25,    26,    27,    28,    30,    31,    32,    33,    34,    35,
      36,    37,    15,    16,    17,    18,    19,    20,    21,    25,
      32,    33,    34,    35,    36,    37,    11,    21,    25,    32,
      33,    34,    35,    36,    37,    21,    22,    23,    25,    32,
      33,    68,    68,     9,    75,    99,    10,    11,   116,    10,
      10,    10,    38,    40,    10,    10,    10,    10,   109,    40,
       3,    12,   118,   119,    15,    16,    17,    18,    19,    26,
      27,    28,    30,    31,    15,    16,    17,    18,    19,    20,
     118,   119,   120,   121,    21,    32,    33,    21,    32,    33,
      34,    35,    36,    37,    21,    32,    33,    34,    35,    36,
      37,    21,    25,    32,    33,    34,    35,    36,    37,    21,
      22,    23,    32,    33,   118,   118,    15,    16,    17,    18,
      19,    42,    40,   106,    75,   106,    13,    14,    80,    62,
      42,    12,   107,   112,   118,   119,   120,   121,   125,    12,
     125,    12,   125,    12,   125,     3,    13,     9,    12,    41,
     112,   125,    14,    39,   117,   107,   118,   112,   107,    82,
     104,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,    10,   105,   106,   112,   107,   110,
     118,   119,   107,   110,   118,   119,   107,   110,   118,   119,
     107,   118,   119,   107,   118,   119,   107,   119,   107,   114,
     115,   118,   119,   120,   121,   107,   121,   107,   121,   107,
     120,   107,   118,   107,   118,   107,   118,   107,   118,   107,
     118,   107,   110,   114,   115,   118,   119,   120,   121,   107,
     110,   114,   115,   118,   119,   120,   121,   107,   118,   119,
     120,   107,   118,   119,   120,   107,   118,   119,   120,   107,
     118,   119,   120,   107,   112,   107,   110,   107,   110,   107,
     110,   107,   110,   107,   110,   107,   110,   107,   114,   115,
     118,   119,   120,   121,   107,   110,   107,   114,   107,   114,
     107,   114,   115,   118,   119,   120,   121,   107,   110,   107,
     115,   107,   115,   107,   118,   119,   107,   118,   119,   107,
     118,   119,   107,   118,   119,   107,   118,   119,   118,   119,
     107,   114,   115,   118,   119,   120,   121,   107,   110,   107,
     118,   107,   118,   107,   118,   107,   118,   107,   118,   107,
     118,   119,   107,   118,   119,   107,   118,   119,   107,   118,
     119,   107,   118,   119,   107,   118,   119,   107,   118,   119,
     107,   118,   119,   107,   118,   119,   107,   118,   119,   107,
     118,   119,   107,   118,   119,   107,   114,   115,   118,   119,
     120,   121,   107,   110,   107,   118,   119,   107,   118,   119,
     107,   118,   119,   107,   118,   119,   107,   118,   119,   107,
     118,   119,   112,   107,   114,   115,   118,   119,   120,   121,
     107,   110,   120,   107,   120,   107,   120,   107,   120,   107,
     120,   107,   120,   107,   120,   107,   114,   115,   118,   119,
     120,   121,   107,   121,   107,   121,   107,   110,   107,   121,
     107,   121,    10,    75,   123,   126,    42,     9,   112,    10,
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
       9,   106,    40,    12,    12,    12,    12,    13,     3,    14,
      56,    96,    97,   126,    10,   100,   101,   126,    12,    41,
     112,    12,    41,    12,    75,    14,    12,    10,    40,    12,
      12,    12,    11,    10,    40,   106,   116,    10,   100,    10,
      38,    12,   109,     8,    85,   106,    85,    14,     3,   106,
     125,    96,    96,    75,    14,     3,    75,    84,    10,    40,
      40,    75,    12,   112,    12,    41,    12,    41,   112,    42,
     105,   123,    84,    10,   112,    60,    94,    10,     3,    10,
      14,    42,    96,    42,    84,   126,   101,   126,    42,    12,
      12,   112,    12,   112,    12,    41,   106,    84,    10,    85,
      85,   106,   106,    75,    75,   106,    12,    12,    12,   112,
      40,    12,   117
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
     124,   124,   124,   124,   125,   125,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126
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
       4,     3,     1,     3,     4,     3,     4,     3,     4,     3,
       4,     3,     4,     3,     1,     3,     2,     2,     2,     2,
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
  "expr_bool", "funtype", "typelist", "mattype", "matsize", "type", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   218,   218,   219,   221,   222,   223,   226,   227,   230,
     231,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   248,   249,   250,   251,   252,   255,   256,
     260,   262,   263,   267,   268,   269,   271,   272,   276,   280,
     283,   287,   293,   294,   298,   299,   300,   302,   303,   304,
     305,   307,   308,   309,   313,   314,   315,   316,   318,   320,
     321,   322,   324,   325,   329,   333,   334,   335,   336,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   357,   358,   362,   363,   364,   365,   366,
     367,   368,   369,   372,   373,   374,   375,   376,   378,   379,
     381,   382,   383,   384,   385,   387,   388,   389,   390,   392,
     393,   394,   396,   397,   398,   400,   401,   402,   403,   404,
     405,   406,   407,   409,   410,   411,   412,   413,   415,   416,
     417,   418,   419,   421,   422,   423,   424,   425,   426,   427,
     428,   430,   431,   432,   433,   434,   435,   436,   437,   439,
     440,   441,   443,   444,   445,   447,   448,   449,   450,   451,
     452,   453,   455,   456,   457,   458,   459,   460,   461,   463,
     464,   465,   466,   467,   468,   469,   471,   472,   473,   474,
     475,   476,   477,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   515,   516,   517,
     519,   520,   521,   523,   524,   525,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   544,   545,   546,   548,   549,   550,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   579,   580,   581,   582,   583,   585,   586,   587,
     591,   592,   593,   594,   596,   597,   599,   600,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     617,   618,   622,   623,   625,   626,   628,   629,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,   650,   651,   652,   653,   654,   655,   656,   657,
     658,   659,   660,   661,   662,   663,   664,   665,   666,   667,
     668,   669,   670,   674,   675,   676,   677,   678,   679,   680,
     681,   682,   683,   684,   685,   686,   687,   688,   689,   690,
     691,   692,   693,   694,   695,   696,   697,   698,   699,   700,
     704,   705,   706,   707,   708,   710,   711,   712,   713,   714,
     715,   716,   718,   719,   720,   721,   722,   723,   724,   726,
     727,   728,   729,   730,   732,   733,   734,   735,   736,   738,
     739,   740,   741,   742,   744,   745,   746,   747,   748,   750,
     754,   755,   757,   758,   762,   763,   764,   765,   766,   767,
     768,   769,   770,   771,   773,   774,   778,   779,   780,   781,
     782,   783,   784,   785,   786,   787,   788,   789,   790,   791
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
#line 4481 "frontend/parser.cpp"

#line 794 "frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    auto msg = std::to_string(scanner->loc->begin.line) + ":" + std::to_string(scanner->loc->begin.column) + ": " + err_message;
    scanner->fatal_error(ptc::diag::ERR_SYNTAX, msg);
}
