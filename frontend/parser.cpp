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
#line 216 "frontend/parser.yy"
                        { scanner->parseEntry(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1077 "frontend/parser.cpp"
    break;

  case 4: // stmt: stmts
#line 218 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1083 "frontend/parser.cpp"
    break;

  case 5: // stmt: stmt stmts
#line 219 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1089 "frontend/parser.cpp"
    break;

  case 6: // stmt: stmt error stmts
#line 220 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1095 "frontend/parser.cpp"
    break;

  case 7: // stmts: "terminator (\\n or ;)"
#line 224 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = nullptr; }
#line 1101 "frontend/parser.cpp"
    break;

  case 8: // stmts: stmts_ne
#line 225 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1107 "frontend/parser.cpp"
    break;

  case 9: // stmts_ne: set "terminator (\\n or ;)"
#line 227 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1113 "frontend/parser.cpp"
    break;

  case 10: // stmts_ne: vardecl "terminator (\\n or ;)"
#line 228 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1119 "frontend/parser.cpp"
    break;

  case 11: // stmts_ne: vardef "terminator (\\n or ;)"
#line 229 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1125 "frontend/parser.cpp"
    break;

  case 12: // stmts_ne: import "terminator (\\n or ;)"
#line 230 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1131 "frontend/parser.cpp"
    break;

  case 14: // stmts_ne: if
#line 232 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1137 "frontend/parser.cpp"
    break;

  case 15: // stmts_ne: while
#line 233 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1143 "frontend/parser.cpp"
    break;

  case 18: // stmts_ne: function
#line 236 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1149 "frontend/parser.cpp"
    break;

  case 19: // stmts_ne: flowctl "terminator (\\n or ;)"
#line 237 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1155 "frontend/parser.cpp"
    break;

  case 20: // stmts_ne: expr "terminator (\\n or ;)"
#line 238 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1161 "frontend/parser.cpp"
    break;

  case 21: // block: "{" "}"
#line 242 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1167 "frontend/parser.cpp"
    break;

  case 22: // block: "{" stmt "}"
#line 243 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1173 "frontend/parser.cpp"
    break;

  case 23: // block: "terminator (\\n or ;)" "{" stmt "}"
#line 244 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1179 "frontend/parser.cpp"
    break;

  case 24: // block: "{" stmt "}" "terminator (\\n or ;)"
#line 245 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1185 "frontend/parser.cpp"
    break;

  case 25: // block: "terminator (\\n or ;)" "{" stmt "}" "terminator (\\n or ;)"
#line 246 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1191 "frontend/parser.cpp"
    break;

  case 26: // body: stmts_ne
#line 249 "frontend/parser.yy"
                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1197 "frontend/parser.cpp"
    break;

  case 27: // body: block
#line 250 "frontend/parser.yy"
                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1203 "frontend/parser.cpp"
    break;

  case 28: // import: "import" id_list
#line 254 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::IR * > () = scanner->parseImports(yystack_[0].value.as < std::vector<std::string>  > ()); }
#line 1209 "frontend/parser.cpp"
    break;

  case 29: // id_list: "identifier"
#line 256 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseImportName(yystack_[0].value.as < std::string > ()); }
#line 1215 "frontend/parser.cpp"
    break;

  case 30: // id_list: "identifier" "," id_list
#line 257 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseAddImportName(yystack_[0].value.as < std::vector<std::string>  > (), yystack_[2].value.as < std::string > ()); }
#line 1221 "frontend/parser.cpp"
    break;

  case 31: // flowctl: "break"
#line 261 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseBreak(); }
#line 1227 "frontend/parser.cpp"
    break;

  case 32: // flowctl: "continue"
#line 262 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseContinue(); }
#line 1233 "frontend/parser.cpp"
    break;

  case 33: // flowctl: return
#line 263 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1239 "frontend/parser.cpp"
    break;

  case 34: // return: "return"
#line 265 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(nullptr); }
#line 1245 "frontend/parser.cpp"
    break;

  case 35: // return: "return" expr
#line 266 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1251 "frontend/parser.cpp"
    break;

  case 37: // while: "while" "(" expr ")" body
#line 274 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::IR * > () = scanner->parseWhile(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1257 "frontend/parser.cpp"
    break;

  case 39: // if: "if" "(" expr ")" body else
#line 281 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::IR * > () = scanner->parseIfStmt(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1263 "frontend/parser.cpp"
    break;

  case 40: // else: "else" body
#line 287 "frontend/parser.yy"
                    { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1269 "frontend/parser.cpp"
    break;

  case 41: // else: %empty
#line 288 "frontend/parser.yy"
                    { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1275 "frontend/parser.cpp"
    break;

  case 52: // function: type fun_id "(" ")" block
#line 307 "frontend/parser.yy"
                                                     { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1281 "frontend/parser.cpp"
    break;

  case 53: // function: type fun_id "(" funargs ")" block
#line 308 "frontend/parser.yy"
                                                     { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[5].value.as < ptc::ir::IR * > (), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1287 "frontend/parser.cpp"
    break;

  case 54: // function: "\"void\"" fun_id "(" ")" block
#line 309 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1293 "frontend/parser.cpp"
    break;

  case 55: // function: "\"void\"" fun_id "(" funargs ")" block
#line 310 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1299 "frontend/parser.cpp"
    break;

  case 56: // fun_id: "identifier"
#line 312 "frontend/parser.yy"
            { scanner->enterFunScope(); yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1305 "frontend/parser.cpp"
    break;

  case 57: // funargs: type "identifier"
#line 314 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseFunParam(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1311 "frontend/parser.cpp"
    break;

  case 59: // funargs: funargs "," type "identifier"
#line 316 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseAddFunParam(yystack_[3].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1317 "frontend/parser.cpp"
    break;

  case 62: // vardecl: type "identifier"
#line 323 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1323 "frontend/parser.cpp"
    break;

  case 63: // vardef: type "identifier" "=" struct_val
#line 327 "frontend/parser.yy"
         { yylhs.value.as < ptc::ir::IR * > () = yystack_[3].value.as < ptc::ir::IR * > (); }
#line 1329 "frontend/parser.cpp"
    break;

  case 64: // vardef: type "identifier" "=" expr
#line 328 "frontend/parser.yy"
                                 { scanner->parseVarDef(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1335 "frontend/parser.cpp"
    break;

  case 67: // set: expr "++=" expr
#line 334 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1341 "frontend/parser.cpp"
    break;

  case 68: // set: expr "**=" expr
#line 335 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1347 "frontend/parser.cpp"
    break;

  case 69: // set: expr "%=" expr
#line 336 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1353 "frontend/parser.cpp"
    break;

  case 70: // set: expr "/=" expr
#line 337 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1359 "frontend/parser.cpp"
    break;

  case 71: // set: expr "*=" expr
#line 338 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1365 "frontend/parser.cpp"
    break;

  case 72: // set: expr "-=" expr
#line 339 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1371 "frontend/parser.cpp"
    break;

  case 73: // set: expr "+=" expr
#line 340 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1377 "frontend/parser.cpp"
    break;

  case 74: // set: expr "&=" expr
#line 341 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1383 "frontend/parser.cpp"
    break;

  case 75: // set: expr "|=" expr
#line 342 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1389 "frontend/parser.cpp"
    break;

  case 76: // set: expr "^=" expr
#line 343 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1395 "frontend/parser.cpp"
    break;

  case 77: // set: expr "<<=" expr
#line 344 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1401 "frontend/parser.cpp"
    break;

  case 78: // set: expr ">>=" expr
#line 345 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1407 "frontend/parser.cpp"
    break;

  case 79: // set: expr "=" expr
#line 346 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1413 "frontend/parser.cpp"
    break;

  case 80: // set: expr "=" set
#line 347 "frontend/parser.yy"
      { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1419 "frontend/parser.cpp"
    break;

  case 81: // callarglist: expr
#line 351 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseFunCallArg(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1425 "frontend/parser.cpp"
    break;

  case 82: // callarglist: expr "," callarglist
#line 352 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddFunCallArg(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[2].value.as < ptc::ir::Expr * > ()); }
#line 1431 "frontend/parser.cpp"
    break;

  case 83: // expr: expr_mat
#line 356 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = nullptr; }
#line 1437 "frontend/parser.cpp"
    break;

  case 84: // expr: expr_var
#line 357 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1443 "frontend/parser.cpp"
    break;

  case 85: // expr: expr_none
#line 358 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = nullptr; }
#line 1449 "frontend/parser.cpp"
    break;

  case 86: // expr: expr_struct
#line 359 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = nullptr; }
#line 1455 "frontend/parser.cpp"
    break;

  case 87: // expr: expr_int
#line 360 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 1461 "frontend/parser.cpp"
    break;

  case 88: // expr: expr_float
#line 361 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFloat(yystack_[0].value.as < double > ()); }
#line 1467 "frontend/parser.cpp"
    break;

  case 89: // expr: expr_str
#line 362 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseString(yystack_[0].value.as < std::string > ()); }
#line 1473 "frontend/parser.cpp"
    break;

  case 90: // expr: expr_bool
#line 363 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseBool(yystack_[0].value.as < bool > ()); }
#line 1479 "frontend/parser.cpp"
    break;

  case 91: // expr_var: "identifier"
#line 366 "frontend/parser.yy"
              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > ()); }
#line 1485 "frontend/parser.cpp"
    break;

  case 92: // expr_var: "external identifier"
#line 367 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > (), true); }
#line 1491 "frontend/parser.cpp"
    break;

  case 93: // expr_var: "-" "identifier"
#line 368 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1497 "frontend/parser.cpp"
    break;

  case 94: // expr_var: "-" "external identifier"
#line 369 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > (), true), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1503 "frontend/parser.cpp"
    break;

  case 95: // expr_var: "(" expr_var ")"
#line 370 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1509 "frontend/parser.cpp"
    break;

  case 96: // expr_var: expr_var "(" ")"
#line 372 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[2].value.as < ptc::ir::Expr * > (), std::vector<ptc::ir::Expr *>{}); }
#line 1515 "frontend/parser.cpp"
    break;

  case 97: // expr_var: expr_var "(" callarglist ")"
#line 373 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 1521 "frontend/parser.cpp"
    break;

  case 102: // expr_var: expr_var "[" int_val "]"
#line 379 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[3].value.as < ptc::ir::Expr * > (); }
#line 1527 "frontend/parser.cpp"
    break;

  case 106: // expr_var: expr_var slice
#line 384 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1533 "frontend/parser.cpp"
    break;

  case 109: // expr_var: expr_var "." expr_var
#line 388 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1539 "frontend/parser.cpp"
    break;

  case 111: // expr_var: expr_var "**" expr_float
#line 391 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1545 "frontend/parser.cpp"
    break;

  case 112: // expr_var: expr_var "**" expr_var
#line 392 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1551 "frontend/parser.cpp"
    break;

  case 113: // expr_var: expr_int "*" expr_var
#line 394 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1557 "frontend/parser.cpp"
    break;

  case 114: // expr_var: expr_float "*" expr_var
#line 395 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1563 "frontend/parser.cpp"
    break;

  case 115: // expr_var: expr_var "*" expr_int
#line 396 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1569 "frontend/parser.cpp"
    break;

  case 116: // expr_var: expr_var "*" expr_float
#line 397 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1575 "frontend/parser.cpp"
    break;

  case 119: // expr_var: expr_var "*" expr_mat
#line 400 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1581 "frontend/parser.cpp"
    break;

  case 120: // expr_var: expr_var "*" expr_var
#line 401 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1587 "frontend/parser.cpp"
    break;

  case 121: // expr_var: expr_int "/" expr_var
#line 403 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1593 "frontend/parser.cpp"
    break;

  case 122: // expr_var: expr_float "/" expr_var
#line 404 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1599 "frontend/parser.cpp"
    break;

  case 123: // expr_var: expr_var "/" expr_int
#line 405 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1605 "frontend/parser.cpp"
    break;

  case 124: // expr_var: expr_var "/" expr_float
#line 406 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1611 "frontend/parser.cpp"
    break;

  case 125: // expr_var: expr_var "/" expr_var
#line 407 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1617 "frontend/parser.cpp"
    break;

  case 126: // expr_var: expr_int "%" expr_var
#line 409 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1623 "frontend/parser.cpp"
    break;

  case 127: // expr_var: expr_float "%" expr_var
#line 410 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1629 "frontend/parser.cpp"
    break;

  case 128: // expr_var: expr_var "%" expr_int
#line 411 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1635 "frontend/parser.cpp"
    break;

  case 129: // expr_var: expr_var "%" expr_float
#line 412 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1641 "frontend/parser.cpp"
    break;

  case 130: // expr_var: expr_var "%" expr_var
#line 413 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1647 "frontend/parser.cpp"
    break;

  case 131: // expr_var: expr_int "+" expr_var
#line 415 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1653 "frontend/parser.cpp"
    break;

  case 132: // expr_var: expr_float "+" expr_var
#line 416 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1659 "frontend/parser.cpp"
    break;

  case 133: // expr_var: expr_var "+" expr_int
#line 417 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1665 "frontend/parser.cpp"
    break;

  case 134: // expr_var: expr_var "+" expr_float
#line 418 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1671 "frontend/parser.cpp"
    break;

  case 136: // expr_var: expr_var "+" expr_mat
#line 420 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1677 "frontend/parser.cpp"
    break;

  case 138: // expr_var: expr_var "+" expr_var
#line 422 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1683 "frontend/parser.cpp"
    break;

  case 139: // expr_var: expr_int "-" expr_var
#line 424 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1689 "frontend/parser.cpp"
    break;

  case 140: // expr_var: expr_float "-" expr_var
#line 425 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1695 "frontend/parser.cpp"
    break;

  case 141: // expr_var: expr_var "-" expr_int
#line 426 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1701 "frontend/parser.cpp"
    break;

  case 142: // expr_var: expr_var "-" expr_float
#line 427 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1707 "frontend/parser.cpp"
    break;

  case 144: // expr_var: expr_var "-" expr_mat
#line 429 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1713 "frontend/parser.cpp"
    break;

  case 146: // expr_var: expr_var "-" expr_var
#line 431 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1719 "frontend/parser.cpp"
    break;

  case 147: // expr_var: expr_int "<<" expr_var
#line 433 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 1725 "frontend/parser.cpp"
    break;

  case 148: // expr_var: expr_var "<<" expr_int
#line 434 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 1731 "frontend/parser.cpp"
    break;

  case 149: // expr_var: expr_var "<<" expr_var
#line 435 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 1737 "frontend/parser.cpp"
    break;

  case 150: // expr_var: expr_int ">>" expr_var
#line 437 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 1743 "frontend/parser.cpp"
    break;

  case 151: // expr_var: expr_var ">>" expr_int
#line 438 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 1749 "frontend/parser.cpp"
    break;

  case 152: // expr_var: expr_var ">>" expr_var
#line 439 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 1755 "frontend/parser.cpp"
    break;

  case 153: // expr_var: expr_int ">" expr_var
#line 441 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 1761 "frontend/parser.cpp"
    break;

  case 154: // expr_var: expr_float ">" expr_var
#line 442 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 1767 "frontend/parser.cpp"
    break;

  case 156: // expr_var: expr_var ">" expr_int
#line 444 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 1773 "frontend/parser.cpp"
    break;

  case 157: // expr_var: expr_var ">" expr_float
#line 445 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 1779 "frontend/parser.cpp"
    break;

  case 158: // expr_var: expr_var ">" expr_str
#line 446 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1785 "frontend/parser.cpp"
    break;

  case 159: // expr_var: expr_var ">" expr_var
#line 447 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 1791 "frontend/parser.cpp"
    break;

  case 160: // expr_var: expr_int ">=" expr_var
#line 449 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 1797 "frontend/parser.cpp"
    break;

  case 161: // expr_var: expr_float ">=" expr_var
#line 450 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 1803 "frontend/parser.cpp"
    break;

  case 163: // expr_var: expr_var ">=" expr_int
#line 452 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 1809 "frontend/parser.cpp"
    break;

  case 164: // expr_var: expr_var ">=" expr_float
#line 453 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 1815 "frontend/parser.cpp"
    break;

  case 165: // expr_var: expr_var ">=" expr_str
#line 454 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1821 "frontend/parser.cpp"
    break;

  case 166: // expr_var: expr_var ">=" expr_var
#line 455 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 1827 "frontend/parser.cpp"
    break;

  case 167: // expr_var: expr_int "<" expr_var
#line 457 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 1833 "frontend/parser.cpp"
    break;

  case 168: // expr_var: expr_float "<" expr_var
#line 458 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 1839 "frontend/parser.cpp"
    break;

  case 170: // expr_var: expr_var "<" expr_int
#line 460 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 1845 "frontend/parser.cpp"
    break;

  case 171: // expr_var: expr_var "<" expr_float
#line 461 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 1851 "frontend/parser.cpp"
    break;

  case 172: // expr_var: expr_var "<" expr_str
#line 462 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1857 "frontend/parser.cpp"
    break;

  case 173: // expr_var: expr_var "<" expr_var
#line 463 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 1863 "frontend/parser.cpp"
    break;

  case 174: // expr_var: expr_int "<=" expr_var
#line 465 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 1869 "frontend/parser.cpp"
    break;

  case 175: // expr_var: expr_float "<=" expr_var
#line 466 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 1875 "frontend/parser.cpp"
    break;

  case 177: // expr_var: expr_var "<=" expr_int
#line 468 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 1881 "frontend/parser.cpp"
    break;

  case 178: // expr_var: expr_var "<=" expr_float
#line 469 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 1887 "frontend/parser.cpp"
    break;

  case 179: // expr_var: expr_var "<=" expr_str
#line 470 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1893 "frontend/parser.cpp"
    break;

  case 180: // expr_var: expr_var "<=" expr_var
#line 471 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 1899 "frontend/parser.cpp"
    break;

  case 181: // expr_var: expr_int "==" expr_var
#line 473 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 1905 "frontend/parser.cpp"
    break;

  case 182: // expr_var: expr_float "==" expr_var
#line 474 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 1911 "frontend/parser.cpp"
    break;

  case 184: // expr_var: expr_bool "==" expr_var
#line 476 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 1917 "frontend/parser.cpp"
    break;

  case 188: // expr_var: expr_var "==" expr_int
#line 480 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 1923 "frontend/parser.cpp"
    break;

  case 189: // expr_var: expr_var "==" expr_float
#line 481 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 1929 "frontend/parser.cpp"
    break;

  case 190: // expr_var: expr_var "==" expr_str
#line 482 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1935 "frontend/parser.cpp"
    break;

  case 191: // expr_var: expr_var "==" expr_bool
#line 483 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 1941 "frontend/parser.cpp"
    break;

  case 192: // expr_var: expr_var "==" expr_none
#line 484 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1947 "frontend/parser.cpp"
    break;

  case 193: // expr_var: expr_var "==" expr_struct
#line 485 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1953 "frontend/parser.cpp"
    break;

  case 195: // expr_var: expr_var "==" expr_mat
#line 487 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1959 "frontend/parser.cpp"
    break;

  case 197: // expr_var: expr_var "==" expr_var
#line 489 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 1965 "frontend/parser.cpp"
    break;

  case 198: // expr_var: expr_int "!=" expr_var
#line 491 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 1971 "frontend/parser.cpp"
    break;

  case 199: // expr_var: expr_float "!=" expr_var
#line 492 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 1977 "frontend/parser.cpp"
    break;

  case 205: // expr_var: expr_var "!=" expr_int
#line 498 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 1983 "frontend/parser.cpp"
    break;

  case 206: // expr_var: expr_var "!=" expr_float
#line 499 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 1989 "frontend/parser.cpp"
    break;

  case 207: // expr_var: expr_var "!=" expr_str
#line 500 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1995 "frontend/parser.cpp"
    break;

  case 208: // expr_var: expr_var "!=" expr_bool
#line 501 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2001 "frontend/parser.cpp"
    break;

  case 209: // expr_var: expr_var "!=" expr_none
#line 502 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2007 "frontend/parser.cpp"
    break;

  case 210: // expr_var: expr_var "!=" expr_struct
#line 503 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2013 "frontend/parser.cpp"
    break;

  case 212: // expr_var: expr_var "!=" expr_mat
#line 505 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2019 "frontend/parser.cpp"
    break;

  case 214: // expr_var: expr_var "!=" expr_var
#line 507 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2025 "frontend/parser.cpp"
    break;

  case 215: // expr_var: expr_int "&" expr_var
#line 509 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2031 "frontend/parser.cpp"
    break;

  case 216: // expr_var: expr_var "&" expr_int
#line 510 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2037 "frontend/parser.cpp"
    break;

  case 217: // expr_var: expr_var "&" expr_var
#line 511 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2043 "frontend/parser.cpp"
    break;

  case 218: // expr_var: expr_int "^" expr_var
#line 513 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2049 "frontend/parser.cpp"
    break;

  case 219: // expr_var: expr_var "^" expr_int
#line 514 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2055 "frontend/parser.cpp"
    break;

  case 220: // expr_var: expr_var "^" expr_var
#line 515 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2061 "frontend/parser.cpp"
    break;

  case 221: // expr_var: expr_int "|" expr_var
#line 517 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2067 "frontend/parser.cpp"
    break;

  case 222: // expr_var: expr_var "|" expr_int
#line 518 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2073 "frontend/parser.cpp"
    break;

  case 223: // expr_var: expr_var "|" expr_var
#line 519 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2079 "frontend/parser.cpp"
    break;

  case 238: // expr_var: expr_var "in" expr_str
#line 535 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2085 "frontend/parser.cpp"
    break;

  case 239: // expr_var: expr_var "in" expr_var
#line 536 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2091 "frontend/parser.cpp"
    break;

  case 240: // expr_var: expr_bool "and" expr_var
#line 538 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2097 "frontend/parser.cpp"
    break;

  case 241: // expr_var: expr_var "and" expr_bool
#line 539 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2103 "frontend/parser.cpp"
    break;

  case 242: // expr_var: expr_var "and" expr_var
#line 540 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2109 "frontend/parser.cpp"
    break;

  case 243: // expr_var: expr_bool "or" expr_var
#line 542 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2115 "frontend/parser.cpp"
    break;

  case 244: // expr_var: expr_var "or" expr_bool
#line 543 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2121 "frontend/parser.cpp"
    break;

  case 245: // expr_var: expr_var "or" expr_var
#line 544 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2127 "frontend/parser.cpp"
    break;

  case 263: // expr_var: expr_var "++" expr_int
#line 563 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2133 "frontend/parser.cpp"
    break;

  case 264: // expr_var: expr_var "++" expr_float
#line 564 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2139 "frontend/parser.cpp"
    break;

  case 265: // expr_var: expr_var "++" expr_str
#line 565 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2145 "frontend/parser.cpp"
    break;

  case 266: // expr_var: expr_var "++" expr_bool
#line 566 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2151 "frontend/parser.cpp"
    break;

  case 267: // expr_var: expr_var "++" expr_none
#line 567 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2157 "frontend/parser.cpp"
    break;

  case 268: // expr_var: expr_var "++" expr_struct
#line 568 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2163 "frontend/parser.cpp"
    break;

  case 269: // expr_var: expr_var "++" expr_var
#line 569 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2169 "frontend/parser.cpp"
    break;

  case 306: // expr_int: "int"
#line 627 "frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 2175 "frontend/parser.cpp"
    break;

  case 307: // expr_int: "-" expr_int
#line 628 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 2181 "frontend/parser.cpp"
    break;

  case 308: // expr_int: "(" expr_int ")"
#line 629 "frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 2187 "frontend/parser.cpp"
    break;

  case 309: // expr_int: "~" expr_int
#line 630 "frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 2193 "frontend/parser.cpp"
    break;

  case 310: // expr_int: expr_int "*" expr_int
#line 631 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 2199 "frontend/parser.cpp"
    break;

  case 311: // expr_int: expr_int "/" expr_int
#line 632 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 2205 "frontend/parser.cpp"
    break;

  case 312: // expr_int: expr_int "%" expr_int
#line 633 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 2211 "frontend/parser.cpp"
    break;

  case 313: // expr_int: expr_int "-" expr_int
#line 634 "frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 2217 "frontend/parser.cpp"
    break;

  case 314: // expr_int: expr_int "+" expr_int
#line 635 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 2223 "frontend/parser.cpp"
    break;

  case 315: // expr_int: expr_int "<<" expr_int
#line 636 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 2229 "frontend/parser.cpp"
    break;

  case 316: // expr_int: expr_int ">>" expr_int
#line 637 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 2235 "frontend/parser.cpp"
    break;

  case 317: // expr_int: expr_int "&" expr_int
#line 638 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 2241 "frontend/parser.cpp"
    break;

  case 318: // expr_int: expr_int "^" expr_int
#line 639 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 2247 "frontend/parser.cpp"
    break;

  case 319: // expr_int: expr_int "|" expr_int
#line 640 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 2253 "frontend/parser.cpp"
    break;

  case 320: // expr_float: "float"
#line 644 "frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 2259 "frontend/parser.cpp"
    break;

  case 321: // expr_float: "-" expr_float
#line 645 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 2265 "frontend/parser.cpp"
    break;

  case 322: // expr_float: "(" expr_float ")"
#line 646 "frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 2271 "frontend/parser.cpp"
    break;

  case 323: // expr_float: expr_float "**" expr_float
#line 647 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2277 "frontend/parser.cpp"
    break;

  case 324: // expr_float: expr_float "**" expr_int
#line 648 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2283 "frontend/parser.cpp"
    break;

  case 325: // expr_float: expr_int "**" expr_float
#line 649 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2289 "frontend/parser.cpp"
    break;

  case 326: // expr_float: expr_float "*" expr_float
#line 650 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 2295 "frontend/parser.cpp"
    break;

  case 327: // expr_float: expr_float "*" expr_int
#line 651 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 2301 "frontend/parser.cpp"
    break;

  case 328: // expr_float: expr_int "*" expr_float
#line 652 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 2307 "frontend/parser.cpp"
    break;

  case 329: // expr_float: expr_float "/" expr_float
#line 653 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 2313 "frontend/parser.cpp"
    break;

  case 330: // expr_float: expr_float "/" expr_int
#line 654 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 2319 "frontend/parser.cpp"
    break;

  case 331: // expr_float: expr_int "/" expr_float
#line 655 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 2325 "frontend/parser.cpp"
    break;

  case 332: // expr_float: expr_float "%" expr_float
#line 656 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2331 "frontend/parser.cpp"
    break;

  case 333: // expr_float: expr_float "%" expr_int
#line 657 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2337 "frontend/parser.cpp"
    break;

  case 334: // expr_float: expr_int "%" expr_float
#line 658 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2343 "frontend/parser.cpp"
    break;

  case 335: // expr_float: expr_float "-" expr_float
#line 659 "frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 2349 "frontend/parser.cpp"
    break;

  case 336: // expr_float: expr_float "-" expr_int
#line 660 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 2355 "frontend/parser.cpp"
    break;

  case 337: // expr_float: expr_int "-" expr_float
#line 661 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 2361 "frontend/parser.cpp"
    break;

  case 338: // expr_float: expr_float "+" expr_float
#line 662 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 2367 "frontend/parser.cpp"
    break;

  case 339: // expr_float: expr_float "+" expr_int
#line 663 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 2373 "frontend/parser.cpp"
    break;

  case 340: // expr_float: expr_int "+" expr_float
#line 664 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 2379 "frontend/parser.cpp"
    break;

  case 341: // expr_str: "string"
#line 668 "frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2385 "frontend/parser.cpp"
    break;

  case 342: // expr_str: "(" expr_str ")"
#line 669 "frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 2391 "frontend/parser.cpp"
    break;

  case 343: // expr_str: expr_str "++" expr_str
#line 670 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 2397 "frontend/parser.cpp"
    break;

  case 344: // expr_str: expr_str "++" expr_int
#line 671 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 2403 "frontend/parser.cpp"
    break;

  case 345: // expr_str: expr_str "++" expr_float
#line 672 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 2409 "frontend/parser.cpp"
    break;

  case 346: // expr_str: expr_str "++" expr_bool
#line 673 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2415 "frontend/parser.cpp"
    break;

  case 347: // expr_str: expr_str "++" expr_none
#line 674 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 2421 "frontend/parser.cpp"
    break;

  case 348: // expr_str: expr_int "++" expr_str
#line 675 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 2427 "frontend/parser.cpp"
    break;

  case 349: // expr_str: expr_int "++" expr_int
#line 676 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 2433 "frontend/parser.cpp"
    break;

  case 350: // expr_str: expr_int "++" expr_float
#line 677 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 2439 "frontend/parser.cpp"
    break;

  case 351: // expr_str: expr_int "++" expr_bool
#line 678 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2445 "frontend/parser.cpp"
    break;

  case 352: // expr_str: expr_int "++" expr_none
#line 679 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 2451 "frontend/parser.cpp"
    break;

  case 353: // expr_str: expr_float "++" expr_str
#line 680 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 2457 "frontend/parser.cpp"
    break;

  case 354: // expr_str: expr_float "++" expr_int
#line 681 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 2463 "frontend/parser.cpp"
    break;

  case 355: // expr_str: expr_float "++" expr_float
#line 682 "frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 2469 "frontend/parser.cpp"
    break;

  case 356: // expr_str: expr_float "++" expr_bool
#line 683 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2475 "frontend/parser.cpp"
    break;

  case 357: // expr_str: expr_float "++" expr_none
#line 684 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 2481 "frontend/parser.cpp"
    break;

  case 358: // expr_str: expr_bool "++" expr_str
#line 685 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 2487 "frontend/parser.cpp"
    break;

  case 359: // expr_str: expr_bool "++" expr_int
#line 686 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 2493 "frontend/parser.cpp"
    break;

  case 360: // expr_str: expr_bool "++" expr_float
#line 687 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 2499 "frontend/parser.cpp"
    break;

  case 361: // expr_str: expr_bool "++" expr_bool
#line 688 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2505 "frontend/parser.cpp"
    break;

  case 362: // expr_str: expr_bool "++" expr_none
#line 689 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 2511 "frontend/parser.cpp"
    break;

  case 363: // expr_str: expr_none "++" expr_str
#line 690 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 2517 "frontend/parser.cpp"
    break;

  case 364: // expr_str: expr_none "++" expr_int
#line 691 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 2523 "frontend/parser.cpp"
    break;

  case 365: // expr_str: expr_none "++" expr_float
#line 692 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 2529 "frontend/parser.cpp"
    break;

  case 366: // expr_str: expr_none "++" expr_bool
#line 693 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2535 "frontend/parser.cpp"
    break;

  case 367: // expr_str: expr_none "++" expr_none
#line 694 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 2541 "frontend/parser.cpp"
    break;

  case 368: // expr_bool: "bool"
#line 698 "frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 2547 "frontend/parser.cpp"
    break;

  case 369: // expr_bool: "(" expr_bool ")"
#line 699 "frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 2553 "frontend/parser.cpp"
    break;

  case 370: // expr_bool: "not" expr_bool
#line 700 "frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 2559 "frontend/parser.cpp"
    break;

  case 371: // expr_bool: expr_bool "or" expr_bool
#line 701 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 2565 "frontend/parser.cpp"
    break;

  case 372: // expr_bool: expr_bool "and" expr_bool
#line 702 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 2571 "frontend/parser.cpp"
    break;

  case 373: // expr_bool: expr_bool "==" expr_bool
#line 704 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 2577 "frontend/parser.cpp"
    break;

  case 374: // expr_bool: expr_int "==" expr_int
#line 705 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 2583 "frontend/parser.cpp"
    break;

  case 375: // expr_bool: expr_int "==" expr_float
#line 706 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 2589 "frontend/parser.cpp"
    break;

  case 376: // expr_bool: expr_float "==" expr_float
#line 707 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 2595 "frontend/parser.cpp"
    break;

  case 377: // expr_bool: expr_float "==" expr_int
#line 708 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 2601 "frontend/parser.cpp"
    break;

  case 378: // expr_bool: expr_str "==" expr_str
#line 709 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 2607 "frontend/parser.cpp"
    break;

  case 379: // expr_bool: expr_none "==" expr_none
#line 710 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 2613 "frontend/parser.cpp"
    break;

  case 380: // expr_bool: expr_bool "!=" expr_bool
#line 712 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 2619 "frontend/parser.cpp"
    break;

  case 381: // expr_bool: expr_int "!=" expr_int
#line 713 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 2625 "frontend/parser.cpp"
    break;

  case 382: // expr_bool: expr_int "!=" expr_float
#line 714 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 2631 "frontend/parser.cpp"
    break;

  case 383: // expr_bool: expr_float "!=" expr_float
#line 715 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 2637 "frontend/parser.cpp"
    break;

  case 384: // expr_bool: expr_float "!=" expr_int
#line 716 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 2643 "frontend/parser.cpp"
    break;

  case 385: // expr_bool: expr_str "!=" expr_str
#line 717 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 2649 "frontend/parser.cpp"
    break;

  case 386: // expr_bool: expr_none "!=" expr_none
#line 718 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 2655 "frontend/parser.cpp"
    break;

  case 387: // expr_bool: expr_int ">" expr_int
#line 720 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 2661 "frontend/parser.cpp"
    break;

  case 388: // expr_bool: expr_int ">" expr_float
#line 721 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 2667 "frontend/parser.cpp"
    break;

  case 389: // expr_bool: expr_float ">" expr_float
#line 722 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 2673 "frontend/parser.cpp"
    break;

  case 390: // expr_bool: expr_float ">" expr_int
#line 723 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 2679 "frontend/parser.cpp"
    break;

  case 391: // expr_bool: expr_str ">" expr_str
#line 724 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 2685 "frontend/parser.cpp"
    break;

  case 392: // expr_bool: expr_int "<" expr_int
#line 726 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 2691 "frontend/parser.cpp"
    break;

  case 393: // expr_bool: expr_int "<" expr_float
#line 727 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 2697 "frontend/parser.cpp"
    break;

  case 394: // expr_bool: expr_float "<" expr_float
#line 728 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 2703 "frontend/parser.cpp"
    break;

  case 395: // expr_bool: expr_float "<" expr_int
#line 729 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 2709 "frontend/parser.cpp"
    break;

  case 396: // expr_bool: expr_str "<" expr_str
#line 730 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 2715 "frontend/parser.cpp"
    break;

  case 397: // expr_bool: expr_int ">=" expr_int
#line 732 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 2721 "frontend/parser.cpp"
    break;

  case 398: // expr_bool: expr_int ">=" expr_float
#line 733 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 2727 "frontend/parser.cpp"
    break;

  case 399: // expr_bool: expr_float ">=" expr_float
#line 734 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 2733 "frontend/parser.cpp"
    break;

  case 400: // expr_bool: expr_float ">=" expr_int
#line 735 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 2739 "frontend/parser.cpp"
    break;

  case 401: // expr_bool: expr_str ">=" expr_str
#line 736 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 2745 "frontend/parser.cpp"
    break;

  case 402: // expr_bool: expr_int "<=" expr_int
#line 738 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 2751 "frontend/parser.cpp"
    break;

  case 403: // expr_bool: expr_int "<=" expr_float
#line 739 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 2757 "frontend/parser.cpp"
    break;

  case 404: // expr_bool: expr_float "<=" expr_float
#line 740 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 2763 "frontend/parser.cpp"
    break;

  case 405: // expr_bool: expr_float "<=" expr_int
#line 741 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 2769 "frontend/parser.cpp"
    break;

  case 406: // expr_bool: expr_str "<=" expr_str
#line 742 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 2775 "frontend/parser.cpp"
    break;

  case 407: // expr_bool: expr_str "in" expr_str
#line 744 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[0].value.as < std::string > ().find(yystack_[2].value.as < std::string > ()) != std::string::npos; }
#line 2781 "frontend/parser.cpp"
    break;

  case 424: // type: "\"int\"" "?"
#line 772 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2787 "frontend/parser.cpp"
    break;

  case 425: // type: "\"float\"" "?"
#line 773 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2793 "frontend/parser.cpp"
    break;

  case 426: // type: "\"string\"" "?"
#line 774 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2799 "frontend/parser.cpp"
    break;

  case 427: // type: "\"bool\"" "?"
#line 775 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2805 "frontend/parser.cpp"
    break;

  case 428: // type: "identifier" "?"
#line 776 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2811 "frontend/parser.cpp"
    break;

  case 429: // type: funtype "?"
#line 777 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2817 "frontend/parser.cpp"
    break;

  case 430: // type: mattype "?"
#line 778 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2823 "frontend/parser.cpp"
    break;

  case 431: // type: "\"int\""
#line 779 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("int"); }
#line 2829 "frontend/parser.cpp"
    break;

  case 432: // type: "\"float\""
#line 780 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("float"); }
#line 2835 "frontend/parser.cpp"
    break;

  case 433: // type: "\"string\""
#line 781 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("string"); }
#line 2841 "frontend/parser.cpp"
    break;

  case 434: // type: "\"bool\""
#line 782 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("bool"); }
#line 2847 "frontend/parser.cpp"
    break;

  case 435: // type: "identifier"
#line 783 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[0].value.as < std::string > ()); }
#line 2853 "frontend/parser.cpp"
    break;

  case 436: // type: funtype
#line 784 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2859 "frontend/parser.cpp"
    break;

  case 437: // type: mattype
#line 785 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2865 "frontend/parser.cpp"
    break;


#line 2869 "frontend/parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -732;

  const short  Parser ::yytable_ninf_ = -436;

  const short
   Parser ::yypact_[] =
  {
    1484,  -732,  -732,  -732,  -732,  -732,  -732,  -732,  2548,    30,
      87,  1023,   390,   -68,    -4,    49,    75,    80,  1753,  2581,
    -732,  -732,     1,     2,    34,    40,    58,    35,    59,    36,
     229,   185,  1332,  -732,  -732,   231,   238,  -732,  -732,  -732,
    -732,  -732,  -732,  -732,   245,   252,   264,   378,  2643,  -732,
     895,  -732,   410,   442,  1631,  3111,   483,   646,   164,   202,
      -3,   303,   240,  2610,   308,   895,   315,    -9,   410,   442,
    2861,  2923,   556,   502,  2581,  -732,   240,   275,   244,   497,
     497,  -732,  -732,  -732,  -732,  1099,   157,  2995,  3134,   856,
    -732,   390,   390,  -732,   290,   325,  -732,  2581,   293,  2581,
     357,  1875,  -732,  -732,   307,  -732,   331,   792,  -732,   910,
    -732,  1071,  -732,  1456,  -732,    37,  -732,   389,   342,    16,
    2581,  -732,  -732,  -732,   371,  2581,  -732,  -732,  -732,  1949,
    -732,  -732,  -732,  -732,  -732,  -732,  -732,  2581,  2581,  2581,
    2581,  2581,  2581,  2581,  2581,  2581,  2581,  2581,  2581,  2581,
    2038,   371,  2581,  2581,  2581,  2581,  2581,  2581,  2581,  2581,
    2581,  2581,  2581,  2581,  2581,  2581,  2581,  2581,  2581,  2581,
    2581,  2581,  2581,  2581,  -732,   371,  2581,  2581,  2581,  2581,
    2581,  2581,  -732,  2581,  2581,  2581,  2581,  2581,  2581,  2581,
    2581,  2581,  2581,  2581,  2581,  2581,   497,  2581,  2581,  2581,
    2581,  2581,  2581,  2581,  2581,  2581,  2581,  2581,  2581,  2581,
    2581,  2581,  2581,  2581,  2581,  2581,  2581,  2581,  2581,  2581,
    2581,  2581,  2581,  2581,  2581,  2581,  2581,  2581,  2581,  2581,
    2581,  2581,  2581,  2581,  2581,  2581,  2581,  2581,  2581,  -732,
    -732,    43,    45,   396,  -732,   371,   398,  -732,  -732,  -732,
    2581,  2581,  -732,  -732,  -732,  -732,   266,    57,   402,  -732,
     981,  1234,   497,   497,   497,   497,   497,   390,   390,   390,
     390,   390,   497,   497,   497,   497,   497,   497,  2889,  2963,
     652,   577,  1023,   191,   191,  1023,   497,   497,   497,   497,
     497,   497,  1023,   497,   497,   497,   497,   497,   497,  1023,
    1023,  1023,  1023,  1023,  1023,  1023,  1023,  1023,  1023,  1023,
    1023,  1023,  1296,  -732,   390,   390,   390,   390,   390,  2581,
      -4,   426,   403,   427,  1949,  -732,  1569,   439,  2581,  -732,
    2643,   425,  1631,  3111,   483,   646,   456,  -732,   466,  -732,
     479,  -732,   484,   485,    53,   167,  -732,   481,     3,   488,
    -732,   428,   493,   192,  1631,    86,   192,  -732,  -732,  2250,
    -732,  -732,  -732,  -732,  -732,  -732,  -732,  -732,  -732,  -732,
    -732,  -732,  -732,   501,   474,   118,   241,   305,   588,   607,
     241,   305,   588,   607,   215,   510,   509,   512,   215,   509,
     512,   215,   509,   512,   215,   512,  2672,   444,   527,  3019,
    1137,   808,   707,  2701,   570,  2741,   740,  2775,   356,  1756,
    2971,  2804,  3065,  2833,  3088,   318,   832,   318,   832,  1190,
     423,  -732,  -732,  1248,  1422,   306,  -732,  1190,   423,  -732,
    -732,  1248,  1422,   306,  -732,   940,  1571,   947,   522,   940,
    1571,   947,   522,   940,  1571,   947,   522,   940,  1571,   947,
     522,   192,   139,   241,   305,   241,   305,   215,   510,  2775,
     920,  1190,   423,  1190,   423,  2672,   444,   527,  3019,  1137,
     808,   707,  2775,   920,  1190,  -732,  1190,  -732,  2672,   444,
     527,  3019,  1137,   808,   707,  2775,   920,  1190,  -732,  1190,
    -732,   241,   588,   607,   241,   588,   607,   215,   509,   512,
     215,   509,   512,   215,   509,   512,  1507,   516,  2672,   444,
     527,  3019,  1137,   808,   707,  2775,   920,  1756,  2971,  2804,
    3065,  2833,  3088,   318,   832,   318,   832,  1190,  1248,  1422,
    1190,  1248,  1422,   940,  1571,   947,   940,  1571,   947,   940,
    1571,   947,   940,  1571,   947,   241,   588,   607,   241,   588,
     607,   215,   509,   512,   215,   509,   512,   215,   509,   512,
     215,   509,   512,  2672,   444,   527,  3019,  1137,   808,   707,
    2775,   920,  1190,  1248,  1422,  1190,  1248,  1422,   940,  1571,
     947,   940,  1571,   947,   940,  1571,   947,   940,  1571,   947,
     534,  2672,   444,   527,  3019,  1137,   808,   707,  2775,   920,
     356,  1190,   306,  1190,   306,   940,   522,   940,   522,   940,
     522,   940,   522,  2672,   444,   527,  3019,  1137,   808,   707,
    2701,   570,  2741,   740,  2775,   920,  1190,  -732,  1190,  -732,
    -732,    67,   537,    17,   641,   174,   176,  -732,   538,   513,
     541,  -732,  2581,  -732,  -732,   735,   795,   735,   795,   509,
     516,   509,   516,   509,   516,  1877,  1336,  1845,   926,   926,
     735,   795,   735,   795,   509,   516,   509,   516,   509,   516,
     509,   516,   251,  3042,  3141,   327,   762,   547,  -732,  -732,
     251,  3042,  3141,   327,   762,  1782,  1051,  1782,  1051,  1782,
    1051,  1782,  1051,  1782,  1051,  1782,  1051,   251,  3042,  3141,
     327,   762,  1782,  1051,  1782,  1051,  1782,  1051,  1782,  1051,
    1782,  1051,  1782,  1051,   251,  3042,  3141,   327,   762,  1179,
     686,   624,   624,  -732,  -732,  -732,  -732,   251,  3042,  3141,
     327,   762,   323,   352,  -732,  -732,   147,   147,  -732,  -732,
    -732,  -732,  -732,  1753,  2581,  1753,  1675,   558,  2581,  -732,
    2581,  -732,  -732,  -732,  -732,   104,   104,  -732,   489,   561,
     573,  -732,     8,   268,    42,   540,    13,  -732,  1963,   186,
    -732,   752,  -732,   536,  -732,  -732,  -732,  2581,  -732,  -732,
    -732,  2454,  -732,   332,  -732,  -732,   268,   121,  -732,  2581,
    -732,  -732,   303,   569,   591,  -732,   627,  -732,   622,  -732,
     619,  -732,   593,  -732,   104,   595,  -732,   268,   332,   332,
     599,  -732,   631,  -732,  2468,  -732,  2494,   190,  2581,  -732,
    -732,  -732,   268,   634,  1753,  -732,  1753,  -732,  -732,  -732,
    2581,  -732,  2581,  -732,    15,   540,    19,  2581,  -732,  -732,
     644,  -732,   651,  -732,  2508,   626,  -732,  -732,  -732,  -732,
    -732,  -732,  -732,   599,  -732,  -732,  -732,  -732,   660,   635,
    -732,  -732
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     7,   306,   320,   341,   368,   298,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      31,    32,     0,   431,   432,   433,   434,     0,     0,    91,
      92,     0,     0,     4,     8,     0,     0,    33,    13,    15,
      16,    14,    17,    18,     0,     0,     0,     0,    84,   278,
      83,   279,    85,    86,    87,    88,    89,    90,   436,   437,
       0,   298,    91,   285,   278,     0,   279,     0,     0,     0,
     284,     0,     0,     0,     0,   270,    91,   275,     0,     0,
       0,    93,    94,   307,   321,     0,     0,     0,     0,     0,
     370,     0,     0,   309,     0,    29,    28,     0,     0,     0,
       0,     0,    26,    27,     0,    35,     0,     0,   424,     0,
     425,     0,   426,     0,   427,     0,    56,     0,     0,     0,
       0,   428,   104,   300,     0,     0,   105,     1,     3,     0,
       5,    12,    19,    10,    11,     9,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   106,     0,     0,     0,     0,     0,
       0,     0,   103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   429,
     430,     0,    56,     0,   299,     0,   300,    95,   280,   281,
       0,     0,   308,   322,   342,   369,     0,     0,     0,   271,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   307,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,     0,     0,   415,
     285,   422,   284,     0,     0,     0,     0,   417,     0,   419,
       0,   421,     0,     0,     0,     0,   413,     0,     0,     0,
     302,     0,     0,   107,     0,     0,   108,     6,    80,    79,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    96,     0,    81,     0,   138,   136,   133,   134,
     146,   144,   141,   142,   120,   119,   115,   116,   125,   123,
     124,   130,   128,   129,   112,   111,   269,   267,   268,   263,
     264,   265,   266,   242,   241,   245,   244,   239,   238,   217,
     216,   223,   222,   220,   219,   149,   148,   152,   151,   197,
     195,   192,   193,   188,   189,   190,   191,   214,   212,   209,
     210,   205,   206,   207,   208,   159,   156,   157,   158,   173,
     170,   171,   172,   166,   163,   164,   165,   180,   177,   178,
     179,   109,     0,   137,   135,   145,   143,   118,   117,   237,
     230,   196,   194,   213,   211,   261,   367,   250,   364,   365,
     363,   366,   235,   228,   185,   379,   202,   386,   262,   255,
     256,   251,   252,   253,   254,   236,   229,   187,   186,   204,
     203,   131,   314,   340,   139,   313,   337,   113,   310,   328,
     121,   311,   331,   126,   312,   334,     0,   325,   257,   352,
     246,   349,   350,   348,   351,   231,   224,   215,   317,   221,
     319,   218,   318,   147,   315,   150,   316,   181,   374,   375,
     198,   381,   382,   153,   387,   388,   167,   392,   393,   160,
     397,   398,   174,   402,   403,   132,   339,   338,   140,   336,
     335,   114,   327,   326,   122,   330,   329,   127,   333,   332,
     110,   324,   323,   258,   357,   247,   354,   355,   353,   356,
     232,   225,   182,   377,   376,   199,   384,   383,   154,   390,
     389,   168,   395,   394,   161,   400,   399,   175,   405,   404,
       0,   259,   347,   248,   344,   345,   343,   346,   233,   226,
     407,   183,   378,   200,   385,   155,   391,   169,   396,   162,
     401,   176,   406,   260,   362,   249,   359,   360,   358,   361,
     240,   372,   243,   371,   234,   227,   184,   373,   201,   380,
     409,   435,     0,   410,     0,     0,     0,   301,     0,     0,
       0,   272,     0,   276,   273,   314,   340,   313,   337,   310,
     328,   311,   331,   312,   334,   317,   319,   318,   315,   316,
     339,   338,   336,   335,   327,   326,   330,   329,   333,   332,
     324,   323,   367,   364,   365,   363,   366,     0,   379,   386,
     352,   349,   350,   348,   351,   374,   375,   381,   382,   387,
     388,   392,   393,   397,   398,   402,   403,   357,   354,   355,
     353,   356,   377,   376,   384,   383,   390,   389,   395,   394,
     400,   399,   405,   404,   347,   344,   345,   343,   346,   407,
       0,   378,   385,   391,   396,   401,   406,   362,   359,   360,
     358,   361,   372,   371,   373,   380,   314,   313,   310,   311,
     312,    66,    30,     0,     0,     0,     0,    22,     0,    65,
       0,   414,   416,   418,   420,     0,    45,    42,     0,     0,
       0,    49,     0,     0,     0,    58,     0,   286,     0,     0,
     100,     0,   412,     0,   303,   101,    97,     0,   102,    99,
      98,     0,   408,     0,    64,    63,     0,     0,   282,     0,
     274,   277,     0,    41,     0,    37,    23,    24,     0,   423,
       0,    46,     0,    43,    47,    62,    54,     0,     0,     0,
      57,   290,     0,   288,     0,   287,     0,     0,     0,    82,
     411,    52,     0,     0,     0,    39,     0,    25,    38,    44,
       0,    48,     0,    55,     0,    61,     0,     0,   293,   292,
       0,   291,     0,   289,     0,   304,    53,   283,    40,    36,
      51,    50,    59,     0,    60,   296,   295,   294,     0,     0,
     297,   305
  };

  const short
   Parser ::yypgoto_[] =
  {
    -732,  -732,   -96,   -12,   -17,  -686,  -731,  -732,   355,  -732,
    -732,  -732,  -732,  -732,  -732,  -732,  -732,  -574,  -732,  -732,
     616,    46,  -129,  -340,  -732,   545,   -87,  1709,  2204,   697,
     -71,  1093,   698,   221,   520,   876,  1286,   -60,  -149,  1973,
       0,   312,   554,  -732,   -72,  -732,   -86,  -225
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    31,    32,    33,    34,   103,   104,    35,    96,    36,
      37,    38,    39,    40,    41,   825,    42,   759,   760,    43,
     117,   764,   765,    44,    45,    46,   373,    47,    48,    49,
      78,    65,    51,   331,   174,    68,    69,   123,   352,    54,
     333,   334,   335,    58,   632,    59,   349,    60
  };

  const short
   Parser ::yytable_[] =
  {
      55,   102,   246,   256,   761,   326,   241,    94,    71,    55,
      84,    88,   793,   107,   795,   770,   633,   241,    55,    55,
     130,   336,   241,   338,   241,   340,   241,   342,   241,   250,
     350,   251,    55,    74,     3,     4,     5,     6,     7,     8,
     343,     9,    75,   750,   771,   109,    10,   118,   -62,   119,
     344,   111,   807,   630,    11,   351,   756,   783,    97,    12,
     642,     3,     4,     5,     6,     7,     8,   757,     9,   113,
     108,    95,   242,    10,    55,   120,   106,   806,   781,   261,
      84,    11,   808,   805,    98,   279,    12,   634,   810,    99,
     852,     3,     4,   848,   853,   849,    79,    55,   775,    55,
     821,    55,   110,    80,   121,    76,    30,   756,   112,   758,
     115,  -435,    23,    24,    25,    26,    12,   357,   631,   762,
     766,   833,    23,    24,    25,    26,   114,   771,   631,    55,
     778,   822,    76,    30,   116,   121,   846,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,   779,   379,   383,   387,   390,   393,   395,   400,   771,
     758,   808,    81,    82,   316,   317,   318,   424,   432,   437,
     441,   445,   449,    23,    24,    25,    26,   763,   282,   631,
     771,   800,   801,   469,   786,   127,   643,   482,   770,   283,
     284,   493,   496,   499,   502,   505,   507,   512,   813,     7,
     677,   150,   843,   151,   529,   532,   535,   538,   541,   544,
     547,   550,   553,   556,   559,   562,   567,   771,   574,   577,
     580,   583,   586,   589,   150,   595,   151,   814,   746,    67,
     831,   844,   239,   617,   131,   157,    23,    24,    25,    26,
     124,   132,   631,    23,    24,    25,    26,   258,   133,   631,
     150,   245,   151,   119,   173,   134,   259,    55,   154,   155,
     156,   157,   646,   648,   650,   652,   654,   135,   125,   640,
     240,   100,   661,   663,   665,   667,   669,   671,   641,   120,
     173,   101,   674,   283,   284,   682,   686,   688,   690,   692,
     694,   696,   699,   703,   705,   707,   709,   711,   713,   716,
      88,    88,    88,    88,    88,    88,    88,   729,    88,    88,
      88,    88,    56,   244,   130,   257,   175,   224,   248,    55,
      72,    56,   178,    89,    55,   249,    55,   150,    55,   151,
      56,    56,   319,   152,   153,   154,   155,   156,   157,   348,
     229,   230,   231,   232,    56,   355,     3,     4,     5,     6,
       7,     8,   300,     9,   346,   310,   311,   173,    10,   301,
     302,   303,   304,   305,   306,   320,    11,   224,   322,   327,
     324,    12,   375,   328,   308,     3,     4,     5,     6,     7,
       8,   136,     9,   347,   310,   311,    56,    10,   227,   228,
     229,   230,   231,   232,     3,    11,   452,   280,   345,    91,
      12,    23,    24,    25,    26,   635,    92,   631,   637,    56,
     766,    56,   347,    56,   644,   761,   761,    76,    30,    12,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   183,   148,   149,   175,   184,   743,   745,   176,   177,
     178,    56,   185,   186,   744,   590,    76,    30,   748,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,   187,   761,   750,   636,   188,   751,   184,
     401,   638,   639,   408,   189,   190,   185,   186,   752,   425,
     433,   438,   442,   446,   450,     3,     4,     5,     6,     7,
       8,   753,     9,   767,   224,   470,   754,    10,   755,   483,
     772,     3,     4,   773,   225,    11,    79,   774,   226,   513,
      12,   776,   255,    80,   777,   227,   228,   229,   230,   231,
     232,   175,   768,   233,   234,   235,    12,   236,   568,   196,
     762,   762,   215,   224,   237,   238,   277,   596,   600,   602,
     604,   606,   608,   610,   612,   618,   780,   782,   788,   122,
     126,   789,   188,   790,    57,   792,    76,    30,   633,   189,
     190,   797,    73,    57,   802,    90,   254,   224,   769,    56,
     182,   791,    57,    57,   785,   803,   804,   225,   818,   762,
     809,   226,   122,   834,   836,   182,    57,   255,   227,   228,
     229,   230,   231,   232,   675,   236,   122,   683,   307,   308,
     309,   826,   237,   238,   700,   193,   194,   195,   196,   310,
     311,   717,   719,   721,   722,   723,   724,   725,   726,   730,
      89,    89,    89,    89,   212,   213,   214,   215,    57,   824,
     827,    56,   828,   829,    55,   830,    56,   832,    56,   281,
      56,   837,    55,   838,   847,     3,     4,     5,     6,     7,
       8,    57,     9,    57,   119,    57,   855,    10,   303,   304,
     305,   306,   254,   856,   799,    11,   859,   233,   234,   235,
      12,   236,   860,   299,   351,   742,   243,   300,   237,   238,
     835,   787,   358,    57,   301,   302,   303,   304,   305,   306,
     819,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    64,    66,   307,   308,   309,
     861,   820,   402,   404,   406,     0,    76,    30,   310,   311,
       0,   426,   434,     0,     0,     0,   102,     0,   102,   234,
     235,     0,   236,     0,   130,     0,     0,   471,     0,   237,
     238,   484,     0,    55,    55,    55,    55,     0,    55,     0,
       0,   514,   264,   265,   266,   196,     3,     4,     5,     6,
       7,     8,   234,     9,   815,   236,     0,     0,    10,     0,
     569,     0,   237,   238,     0,     0,    11,    55,     0,   597,
       0,    12,     0,     0,   308,   309,     0,   619,   621,   623,
       0,   627,   629,   816,   310,   311,     3,     4,     5,     6,
       7,     8,     0,     9,   329,     0,     0,   102,    10,   102,
       0,    57,   274,   275,   276,   277,    11,     0,    55,   224,
       0,    12,     0,     0,    55,     0,    55,    76,    30,     0,
      55,     0,    55,   226,     0,     0,   676,    55,     0,   684,
     227,   228,   229,   230,   231,   232,   701,   191,   192,   193,
     194,   195,   196,   718,   720,   720,   720,   720,   720,   720,
     720,   731,   732,   733,   734,   735,     0,    76,    30,     0,
       0,     0,     0,    57,     0,     0,    52,   299,    57,     0,
      57,   300,    57,     0,     0,    52,     0,    86,   301,   302,
     303,   304,   305,   306,    52,    52,     0,   182,     0,     0,
       0,   182,     0,     0,     0,   182,   175,     0,    52,     0,
     176,   177,   178,     0,     3,     4,     5,     6,     7,     8,
     179,     9,   337,     0,     0,     0,    10,   180,   181,     0,
       0,   175,     0,     0,    11,   176,   177,   178,     0,    12,
     182,   314,   315,   316,   317,   318,    56,     0,   182,   150,
      52,   151,   180,   181,    56,   152,   153,   154,   155,   156,
     157,    86,   210,   211,   212,   213,   214,   215,     0,     0,
     165,   166,     0,    52,   182,    52,   182,    52,   182,   173,
     182,     0,   182,     0,   182,    76,    30,     0,     0,   812,
       0,   252,   817,   182,     0,     0,   262,   263,   264,   265,
     266,   196,     0,     0,     0,    52,   182,   267,   268,   269,
     823,   270,   271,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,     3,     4,     5,
       6,     7,    85,     0,   397,   840,   182,   842,     0,    80,
       0,     0,     0,   421,   429,     0,     0,    11,     0,     0,
       0,     0,    12,     0,     0,    56,    56,    56,    56,   466,
      56,   475,   477,   479,     0,   858,   272,   273,   274,   275,
     276,   277,     0,   509,     0,     3,     4,     5,     6,     7,
       8,     0,     9,   339,     0,     0,     0,    10,     0,    56,
       0,   182,   564,    50,     0,    11,     0,     0,     0,     0,
      12,   592,    50,     3,     4,     5,     6,    61,    85,   614,
       0,    50,    50,     0,     0,    80,     0,     0,     0,   182,
       0,     0,     0,    11,     0,    50,     0,     0,    12,     0,
      56,     0,     0,    52,     0,     0,    56,     0,    56,     0,
       0,     0,    56,     0,    56,   182,    76,    30,     0,    56,
       0,     0,   210,   211,   212,   213,   214,   215,   672,   678,
     679,   680,   217,     0,     0,     0,     0,    50,   697,   218,
     219,   220,   221,   222,   223,   714,    86,    86,    86,    86,
      86,    86,    86,   727,    86,    86,    86,    86,    57,     0,
      50,     0,    50,     0,    50,    52,    57,     0,     0,   150,
      52,   151,    52,     0,    52,   152,   153,   154,   155,   156,
     157,   301,   302,   303,   304,   305,   306,     0,     0,     0,
     165,   166,    50,     0,   169,   170,   171,   172,     0,   173,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,   253,   377,   381,   385,     0,   272,
     273,   274,   275,   276,   277,     0,     0,     0,     0,     0,
     420,   428,     0,   191,   192,   193,   194,   195,   196,   454,
     456,   458,   460,   462,   464,     0,     0,   473,   202,   203,
       0,   486,   206,   207,   208,   209,    53,     0,     0,     0,
       0,   516,     0,     0,     0,    53,     0,    57,    57,    57,
      57,     0,    57,     0,    53,    53,   252,     0,     0,     0,
     571,   314,   315,   316,   317,   318,     0,     0,    53,   599,
       0,     0,   267,   268,   269,     0,   270,   271,     0,   625,
       0,    57,   128,   129,     0,     2,     3,     4,     5,     6,
       7,     8,     0,     9,     0,     0,     0,     0,    10,     0,
      50,   314,   315,   316,   317,   318,    11,     0,     0,     0,
      53,    12,   267,     0,   269,     0,   270,   271,     0,     0,
       0,     0,    57,     0,     0,     0,     0,     0,    57,     0,
      57,     0,     0,    53,    57,    53,    57,    53,    13,    14,
      15,    57,     0,    16,    17,    18,    19,    20,    21,    22,
       0,    23,    24,    25,    26,    27,    28,    29,    30,     0,
       0,     0,    50,     0,     0,    53,     0,    50,     0,    50,
       0,    50,     0,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,   210,   211,   212,
     213,   214,   215,     0,   398,     0,     0,     0,     0,     0,
       0,     0,     0,   422,   430,     0,   220,   221,   222,   223,
       3,     4,     5,     6,     7,     8,     0,     9,   341,   467,
       0,     0,    10,   480,     0,   488,   490,     0,     0,     0,
      11,     0,     0,   510,     1,    12,     0,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,     0,     0,
      10,     0,   565,     0,     0,     0,     0,     0,    11,     0,
      52,   593,     0,    12,     0,     0,     0,     0,    52,   615,
       0,     0,   262,   263,   264,   265,   266,   196,     0,     0,
       0,    76,    30,   267,   268,   269,     0,   270,   271,     0,
      13,    14,    15,    53,     0,    16,    17,    18,    19,    20,
      21,    22,     0,    23,    24,    25,    26,    27,    28,    29,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     129,     0,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,   747,     0,    10,   191,   192,   193,   194,
     195,   196,     0,    11,     0,     0,     0,     0,    12,     0,
       0,   202,   203,     0,     0,    53,     0,     0,     0,     0,
      53,     0,    53,     0,    53,     0,     0,     0,     0,    52,
      52,    52,    52,     0,    52,    13,    14,    15,     0,     0,
      16,    17,    18,    19,    20,    21,    22,     0,    23,    24,
      25,    26,    27,    28,    29,    30,   191,   192,   193,   194,
     195,   196,   197,    52,     0,     0,   198,   199,   200,   201,
       0,   202,   203,   204,   205,   206,   207,   208,   209,     0,
       0,     0,     0,     0,     0,     0,   129,     0,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,   796,
       0,    10,     0,     0,    52,     0,     0,     0,     0,    11,
      52,     0,    52,     0,    12,     0,    52,     0,    52,     0,
       0,     0,     0,    52,     0,     0,     0,     0,    77,     0,
       0,     0,     0,     0,     0,     0,     0,    50,   105,     0,
       0,    13,    14,    15,     0,    50,    16,    17,    18,    19,
      20,    21,    22,     0,    23,    24,    25,    26,    27,    28,
      29,    30,     0,     0,     0,     0,   100,     3,     4,     5,
       6,     7,     8,     0,     9,   150,   101,   151,     0,    10,
       0,   152,   153,   154,   155,   156,   157,    11,     0,     0,
       0,     0,    12,    77,     0,     0,   165,   166,   167,   168,
     169,   170,   171,   172,     0,   173,     0,   262,   263,   264,
     265,   266,   196,     0,     0,     0,   321,     0,   323,    13,
      14,    15,   270,   271,    16,    17,    18,    19,    20,    21,
      22,     0,    23,    24,    25,    26,    27,    28,    29,    30,
       0,     0,     0,     0,     0,     0,    50,    50,    50,    50,
       0,    50,     0,     0,     0,     0,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   374,
     314,   315,   316,   317,   318,     0,     0,     0,     0,     0,
      50,   267,     0,     0,     0,   270,   271,     0,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,   325,
       0,    10,   314,   315,   316,   317,   318,     0,     0,    11,
       0,     0,     0,     0,    12,     0,     0,   270,   271,     0,
       0,    50,     0,     0,     0,     0,     0,    50,     0,    50,
      53,     0,     0,    50,     0,    50,     0,     0,    53,     0,
      50,    13,    14,    15,     0,     0,    16,    17,    18,    19,
      20,    21,    22,     0,    23,    24,    25,    26,    27,    28,
      29,    30,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,     0,     0,    10,    77,     3,     4,     5,
       6,     7,     8,    11,     9,   811,     0,     0,    12,    10,
       0,    70,     0,    83,    87,    93,     0,    11,     0,     0,
       0,     0,    12,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,    14,    15,     0,     0,
      16,    17,    18,    19,    20,    21,    22,     0,    23,    24,
      25,    26,    27,    28,    29,    30,     0,     0,   741,    53,
      53,    53,    53,     0,    53,     0,     0,   749,    76,    30,
       0,     0,     3,     4,     5,     6,     7,     8,   372,     9,
       0,     0,   260,    83,    10,     0,     0,     0,   278,     0,
       0,     0,    11,    53,   312,   313,     0,    12,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     332,     0,   332,     0,   332,     0,   332,     0,     0,     0,
       0,   332,     0,   354,     0,     0,     0,   332,   354,     0,
       0,     0,     0,     0,    53,     0,     0,     0,     0,     0,
      53,     0,    53,    76,    30,     0,    53,     0,    53,     0,
       0,     0,     0,    53,   332,   378,   382,   386,   389,   392,
     354,   399,   354,   354,   354,   410,   412,   414,   416,   418,
     423,   431,   436,   440,   444,   448,   354,     0,   332,   354,
     354,   354,   354,   354,   354,     0,   468,   354,   354,   354,
     481,   354,   354,   354,   492,   495,   498,   501,   504,   506,
     511,   354,   518,   520,   522,   524,   526,   528,   531,   534,
     537,   540,   543,   546,   549,   552,   555,   558,   561,   566,
     354,   573,   576,   579,   582,   585,   588,   332,   594,   354,
     354,   354,   354,   354,   354,   354,   616,   354,   354,   354,
     354,   354,    63,     0,     0,     0,     0,     0,   332,     0,
       0,     0,     0,   332,   332,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   645,   647,   649,   651,   653,
     655,   656,   657,   658,   659,   660,   662,   664,   666,   668,
     670,     0,     0,     0,     0,   673,     0,     0,   681,   685,
     687,   689,   691,   693,   695,   698,   702,   704,   706,   708,
     710,   712,   715,    87,    87,    87,    87,    87,    87,    87,
     728,    87,    87,    87,    87,     0,     0,   736,   737,   738,
     739,   740,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,     0,   148,   149,     0,     0,     0,     0,
       0,   330,     0,   330,     0,   330,     0,   330,     0,     0,
     332,     0,   330,     0,   353,     0,     0,     0,   330,   356,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   784,     0,     0,     0,     0,     0,     0,
       0,    77,     0,     0,     0,   330,   376,   380,   384,   388,
     391,   394,   396,   403,   405,   407,   409,   411,   413,   415,
     417,   419,   427,   435,   439,   443,   447,   451,     0,   330,
     453,   455,   457,   459,   461,   463,     0,   465,   472,   474,
     476,   478,   485,   487,   489,   491,   494,   497,   500,   503,
       0,   508,   515,   517,   519,   521,   523,   525,   527,   530,
     533,   536,   539,   542,   545,   548,   551,   554,   557,   560,
     563,   570,   572,   575,   578,   581,   584,   587,   330,   591,
     598,   601,   603,   605,   607,   609,   611,   613,   620,   622,
     624,   626,   628,     0,     0,     0,     0,     0,     0,   330,
       0,     0,     0,   794,   330,   330,     0,   798,     3,     4,
       5,     6,     7,     8,     0,     9,   346,     0,     0,     0,
      10,     0,     3,     4,     5,     6,     7,     8,    11,     9,
     839,     0,     0,    12,    10,     0,   374,     0,     0,     0,
       0,     0,    11,     0,     0,     0,     0,    12,     3,     4,
       5,     6,     7,     8,     0,     9,   841,     0,     0,     0,
      10,     0,     3,     4,     5,     6,     7,     8,    11,     9,
     857,     0,     0,    12,    10,     0,     0,   845,     0,    76,
      30,     0,    11,     0,     0,     0,     0,    12,     0,   850,
       0,   851,     0,    76,    30,     0,   854,     0,     0,     0,
       0,   330,     3,     4,     5,     6,    61,     8,     0,     9,
       0,     0,     0,     0,    10,     0,     0,     0,     0,    76,
      30,     0,    11,     0,     0,     0,     0,    12,     0,     0,
       0,     0,     0,    76,    30,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,     0,     0,    10,     0,     0,
       0,     0,     0,     0,     0,    11,     0,     0,     0,     0,
      12,     0,     0,     0,     0,     0,     0,     0,     0,   150,
     247,   151,     0,    62,    30,   152,   153,   154,   155,   156,
     157,   158,   159,   160,     0,   161,   162,   163,   164,     0,
     165,   166,   167,   168,   169,   170,   171,   172,     0,   173,
       0,     0,   150,     0,   151,     0,    76,    30,   152,   153,
     154,   155,   156,   157,   158,   159,   160,     0,   161,   162,
     163,   164,     0,   165,   166,   167,   168,   169,   170,   171,
     172,   150,   173,   151,     0,     0,     0,   152,   153,   154,
     155,   156,   157,     0,   159,   160,     0,   161,   162,   163,
     164,     0,   165,   166,   167,   168,   169,   170,   171,   172,
     150,   173,   151,     0,     0,     0,   152,   153,   154,   155,
     156,   157,     0,   332,     0,     0,   161,   162,   163,   164,
       0,   165,   166,   167,   168,   169,   170,   171,   172,     0,
     173,   332,     0,     0,   332,     0,     0,     0,     0,     0,
     150,     0,   151,     0,   332,     0,   152,   153,   154,   155,
     156,   157,   332,   159,     0,     0,   161,   162,   163,   164,
       0,   165,   166,   167,   168,   169,   170,   171,   172,     0,
     173,     0,     0,     0,   150,     0,   151,   332,     0,   332,
     152,   153,   154,   155,   156,   157,     0,     0,     0,     0,
       0,   162,   163,   164,     0,   165,   166,   167,   168,   169,
     170,   171,   172,   150,   173,   151,     0,   332,     0,   152,
     153,   154,   155,   156,   157,     0,     0,     0,     0,     0,
     162,     0,   164,     0,   165,   166,   167,   168,   169,   170,
     171,   172,   150,   173,   151,     0,     0,     0,   152,   153,
     154,   155,   156,   157,     0,     0,     0,     0,     0,   162,
       0,     0,     0,   165,   166,   167,   168,   169,   170,   171,
     172,   252,   173,     0,     0,     0,   191,   192,   193,   194,
     195,   196,   197,     0,     0,     0,   198,   199,   200,   201,
       0,   202,   203,   204,   205,   206,   207,   208,   209,   252,
       0,     0,     0,     0,   262,   263,   264,   265,   266,   196,
     285,     0,     0,     0,     0,   267,   268,   269,     0,   270,
     271,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,     0,   253,     0,     0,     0,     0,   210,   211,
     212,   213,   214,   215,   216,     0,     0,     0,   217,     0,
       0,     0,     0,     0,   330,   218,   219,   220,   221,   222,
     223,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   330,   253,     0,   330,     0,     0,   272,   273,
     274,   275,   276,   277,   292,   330,   191,   192,   193,   194,
     195,   196,     0,   330,     0,   293,   294,   295,   296,   297,
     298,   202,   203,   204,   205,   206,   207,   208,   209,     0,
     262,   263,   264,   265,   266,   196,   285,     0,   330,     0,
     330,   267,   268,   269,     0,   270,   271,   286,   287,   288,
     289,   290,   291,     0,   191,   192,   193,   194,   195,   196,
       0,     0,     0,     0,   198,   199,   200,   201,   330,   202,
     203,   204,   205,   206,   207,   208,   209,   262,   263,   264,
     265,   266,   196,     0,     0,     0,     0,     0,   267,   268,
     269,     0,   270,   271,   286,   287,   288,   289,   290,   291,
     191,   192,   193,   194,   195,   196,     0,     0,     0,     0,
       0,   199,     0,   201,     0,   202,   203,   204,   205,   206,
     207,   208,   209,   191,   192,   193,   194,   195,   196,     0,
       0,     0,     0,     0,   199,     0,     0,     0,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,     0,     0,     0,   217,     0,     0,     0,
       0,     0,     0,   218,   219,   220,   221,   222,   223,   272,
     273,   274,   275,   276,   277,   292,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,   293,   294,   295,   296,
     297,   298,     0,   293,   294,   295,   296,   297,   298
  };

  const short
   Parser ::yycheck_[] =
  {
       0,    18,    62,    74,   344,   101,     9,    75,     8,     9,
      10,    11,   743,    11,   745,    12,   241,     9,    18,    19,
      32,   107,     9,   109,     9,   111,     9,   113,     9,    38,
      14,    40,    32,     3,     4,     5,     6,     7,     8,     9,
       3,    11,    12,    40,    41,    11,    16,    11,     3,    13,
      13,    11,    10,    10,    24,    39,     3,    40,     9,    29,
       3,     4,     5,     6,     7,     8,     9,    14,    11,    11,
      68,    75,    75,    16,    74,    39,    75,   763,    11,    79,
      80,    24,    40,    75,     9,    85,    29,    42,    75,     9,
      75,     4,     5,   824,    75,   826,     9,    97,    12,    99,
     786,   101,    68,    16,    68,    75,    76,     3,    68,    56,
      75,    75,    69,    70,    71,    72,    29,   129,    75,   344,
     345,   807,    69,    70,    71,    72,    68,    41,    75,   129,
      12,    10,    75,    76,    75,    68,   822,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,    12,   152,   153,   154,   155,   156,   157,   158,    41,
      56,    40,    75,    76,    17,    18,    19,   167,   168,   169,
     170,   171,   172,    69,    70,    71,    72,    10,    21,    75,
      41,   755,   756,   183,    10,     0,   257,   187,    12,    32,
      33,   191,   192,   193,   194,   195,   196,   197,    12,     8,
       9,     9,    12,    11,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    41,   218,   219,
     220,   221,   222,   223,     9,   225,    11,    41,   324,     8,
     804,    41,    68,   233,     3,    20,    69,    70,    71,    72,
      11,     3,    75,    69,    70,    71,    72,     3,     3,    75,
       9,    11,    11,    13,    39,     3,    12,   257,    17,    18,
      19,    20,   262,   263,   264,   265,   266,     3,    39,     3,
      68,     3,   272,   273,   274,   275,   276,   277,    12,    39,
      39,    13,   282,    32,    33,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,     0,    10,   326,    40,    11,    11,    10,   319,
       8,     9,    17,    11,   324,    10,   326,     9,   328,    11,
      18,    19,    42,    15,    16,    17,    18,    19,    20,   118,
      34,    35,    36,    37,    32,   124,     4,     5,     6,     7,
       8,     9,    25,    11,    12,    32,    33,    39,    16,    32,
      33,    34,    35,    36,    37,    40,    24,    11,    75,    62,
      13,    29,   151,    42,    22,     4,     5,     6,     7,     8,
       9,     3,    11,    41,    32,    33,    74,    16,    32,    33,
      34,    35,    36,    37,     4,    24,   175,    85,     9,     9,
      29,    69,    70,    71,    72,     9,    16,    75,    10,    97,
     635,    99,    41,   101,    12,   755,   756,    75,    76,    29,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    21,    54,    55,    11,    25,    10,    10,    15,    16,
      17,   129,    32,    33,    41,   224,    75,    76,     9,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,    21,   804,    40,   245,    25,    12,    25,
     158,   250,   251,   161,    32,    33,    32,    33,    12,   167,
     168,   169,   170,   171,   172,     4,     5,     6,     7,     8,
       9,    12,    11,    12,    11,   183,    12,    16,    13,   187,
      12,     4,     5,    75,    21,    24,     9,    14,    25,   197,
      29,    10,    10,    16,    40,    32,    33,    34,    35,    36,
      37,    11,    41,    21,    22,    23,    29,    25,   216,    20,
     755,   756,    20,    11,    32,    33,    20,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    12,    10,    10,    29,
      30,    38,    25,    12,     0,     8,    75,    76,   783,    32,
      33,     3,     8,     9,    75,    11,    10,    11,   347,   257,
      50,   642,    18,    19,   634,    14,     3,    21,    42,   804,
      40,    25,    62,   808,   809,    65,    32,    10,    32,    33,
      34,    35,    36,    37,   282,    25,    76,   285,    21,    22,
      23,    10,    32,    33,   292,    17,    18,    19,    20,    32,
      33,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,    17,    18,    19,    20,    74,    60,
       3,   319,    10,    14,   634,    42,   324,    42,   326,    85,
     328,    42,   642,    12,    10,     4,     5,     6,     7,     8,
       9,    97,    11,    99,    13,   101,    12,    16,    34,    35,
      36,    37,    10,    12,   750,    24,    40,    21,    22,    23,
      29,    25,    12,    21,    39,   320,    60,    25,    32,    33,
     809,   635,   137,   129,    32,    33,    34,    35,    36,    37,
     777,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,     8,     8,    21,    22,    23,
     859,   783,   158,   159,   160,    -1,    75,    76,    32,    33,
      -1,   167,   168,    -1,    -1,    -1,   743,    -1,   745,    22,
      23,    -1,    25,    -1,   746,    -1,    -1,   183,    -1,    32,
      33,   187,    -1,   743,   744,   745,   746,    -1,   748,    -1,
      -1,   197,    17,    18,    19,    20,     4,     5,     6,     7,
       8,     9,    22,    11,    12,    25,    -1,    -1,    16,    -1,
     216,    -1,    32,    33,    -1,    -1,    24,   777,    -1,   225,
      -1,    29,    -1,    -1,    22,    23,    -1,   233,   234,   235,
      -1,   237,   238,    41,    32,    33,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,   824,    16,   826,
      -1,   257,    17,    18,    19,    20,    24,    -1,   818,    11,
      -1,    29,    -1,    -1,   824,    -1,   826,    75,    76,    -1,
     830,    -1,   832,    25,    -1,    -1,   282,   837,    -1,   285,
      32,    33,    34,    35,    36,    37,   292,    15,    16,    17,
      18,    19,    20,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,    -1,    75,    76,    -1,
      -1,    -1,    -1,   319,    -1,    -1,     0,    21,   324,    -1,
     326,    25,   328,    -1,    -1,     9,    -1,    11,    32,    33,
      34,    35,    36,    37,    18,    19,    -1,   377,    -1,    -1,
      -1,   381,    -1,    -1,    -1,   385,    11,    -1,    32,    -1,
      15,    16,    17,    -1,     4,     5,     6,     7,     8,     9,
      25,    11,    12,    -1,    -1,    -1,    16,    32,    33,    -1,
      -1,    11,    -1,    -1,    24,    15,    16,    17,    -1,    29,
     420,    15,    16,    17,    18,    19,   634,    -1,   428,     9,
      74,    11,    32,    33,   642,    15,    16,    17,    18,    19,
      20,    85,    15,    16,    17,    18,    19,    20,    -1,    -1,
      30,    31,    -1,    97,   454,    99,   456,   101,   458,    39,
     460,    -1,   462,    -1,   464,    75,    76,    -1,    -1,   768,
      -1,    10,   771,   473,    -1,    -1,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,   129,   486,    26,    27,    28,
     789,    30,    31,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,     4,     5,     6,
       7,     8,     9,    -1,   158,   814,   516,   816,    -1,    16,
      -1,    -1,    -1,   167,   168,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    29,    -1,    -1,   743,   744,   745,   746,   183,
     748,   185,   186,   187,    -1,   844,    15,    16,    17,    18,
      19,    20,    -1,   197,    -1,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    -1,    -1,    -1,    16,    -1,   777,
      -1,   571,   216,     0,    -1,    24,    -1,    -1,    -1,    -1,
      29,   225,     9,     4,     5,     6,     7,     8,     9,   233,
      -1,    18,    19,    -1,    -1,    16,    -1,    -1,    -1,   599,
      -1,    -1,    -1,    24,    -1,    32,    -1,    -1,    29,    -1,
     818,    -1,    -1,   257,    -1,    -1,   824,    -1,   826,    -1,
      -1,    -1,   830,    -1,   832,   625,    75,    76,    -1,   837,
      -1,    -1,    15,    16,    17,    18,    19,    20,   282,   283,
     284,   285,    25,    -1,    -1,    -1,    -1,    74,   292,    32,
      33,    34,    35,    36,    37,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   634,    -1,
      97,    -1,    99,    -1,   101,   319,   642,    -1,    -1,     9,
     324,    11,   326,    -1,   328,    15,    16,    17,    18,    19,
      20,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      30,    31,   129,    -1,    34,    35,    36,    37,    -1,    39,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,    10,   152,   153,   154,    -1,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
     167,   168,    -1,    15,    16,    17,    18,    19,    20,   176,
     177,   178,   179,   180,   181,    -1,    -1,   184,    30,    31,
      -1,   188,    34,    35,    36,    37,     0,    -1,    -1,    -1,
      -1,   198,    -1,    -1,    -1,     9,    -1,   743,   744,   745,
     746,    -1,   748,    -1,    18,    19,    10,    -1,    -1,    -1,
     217,    15,    16,    17,    18,    19,    -1,    -1,    32,   226,
      -1,    -1,    26,    27,    28,    -1,    30,    31,    -1,   236,
      -1,   777,     0,     1,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    -1,    -1,    -1,    -1,    16,    -1,
     257,    15,    16,    17,    18,    19,    24,    -1,    -1,    -1,
      74,    29,    26,    -1,    28,    -1,    30,    31,    -1,    -1,
      -1,    -1,   818,    -1,    -1,    -1,    -1,    -1,   824,    -1,
     826,    -1,    -1,    97,   830,    99,   832,   101,    56,    57,
      58,   837,    -1,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,   319,    -1,    -1,   129,    -1,   324,    -1,   326,
      -1,   328,    -1,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,    15,    16,    17,
      18,    19,    20,    -1,   158,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   167,   168,    -1,    34,    35,    36,    37,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,   183,
      -1,    -1,    16,   187,    -1,   189,   190,    -1,    -1,    -1,
      24,    -1,    -1,   197,     0,    29,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    -1,    -1,    -1,    -1,
      16,    -1,   216,    -1,    -1,    -1,    -1,    -1,    24,    -1,
     634,   225,    -1,    29,    -1,    -1,    -1,    -1,   642,   233,
      -1,    -1,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    75,    76,    26,    27,    28,    -1,    30,    31,    -1,
      56,    57,    58,   257,    -1,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    -1,    -1,    14,    -1,    16,    15,    16,    17,    18,
      19,    20,    -1,    24,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    30,    31,    -1,    -1,   319,    -1,    -1,    -1,    -1,
     324,    -1,   326,    -1,   328,    -1,    -1,    -1,    -1,   743,
     744,   745,   746,    -1,   748,    56,    57,    58,    -1,    -1,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    15,    16,    17,    18,
      19,    20,    21,   777,    -1,    -1,    25,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    -1,    -1,    14,
      -1,    16,    -1,    -1,   818,    -1,    -1,    -1,    -1,    24,
     824,    -1,   826,    -1,    29,    -1,   830,    -1,   832,    -1,
      -1,    -1,    -1,   837,    -1,    -1,    -1,    -1,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   634,    19,    -1,
      -1,    56,    57,    58,    -1,   642,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,     9,    13,    11,    -1,    16,
      -1,    15,    16,    17,    18,    19,    20,    24,    -1,    -1,
      -1,    -1,    29,    74,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    39,    -1,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    97,    -1,    99,    56,
      57,    58,    30,    31,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,    -1,   743,   744,   745,   746,
      -1,   748,    -1,    -1,    -1,    -1,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
      15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
     777,    26,    -1,    -1,    -1,    30,    31,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    -1,    -1,    14,
      -1,    16,    15,    16,    17,    18,    19,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    30,    31,    -1,
      -1,   818,    -1,    -1,    -1,    -1,    -1,   824,    -1,   826,
     634,    -1,    -1,   830,    -1,   832,    -1,    -1,   642,    -1,
     837,    56,    57,    58,    -1,    -1,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    -1,    -1,    -1,    -1,    16,   257,     4,     5,     6,
       7,     8,     9,    24,    11,    12,    -1,    -1,    29,    16,
      -1,     8,    -1,    10,    11,    12,    -1,    24,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    -1,   319,   743,
     744,   745,   746,    -1,   748,    -1,    -1,   328,    75,    76,
      -1,    -1,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    79,    80,    16,    -1,    -1,    -1,    85,    -1,
      -1,    -1,    24,   777,    91,    92,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,   109,    -1,   111,    -1,   113,    -1,    -1,    -1,
      -1,   118,    -1,   120,    -1,    -1,    -1,   124,   125,    -1,
      -1,    -1,    -1,    -1,   818,    -1,    -1,    -1,    -1,    -1,
     824,    -1,   826,    75,    76,    -1,   830,    -1,   832,    -1,
      -1,    -1,    -1,   837,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,   175,   176,
     177,   178,   179,   180,   181,    -1,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     8,    -1,    -1,    -1,    -1,    -1,   245,    -1,
      -1,    -1,    -1,   250,   251,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,    -1,    -1,    -1,    -1,   282,    -1,    -1,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,    -1,    -1,   314,   315,   316,
     317,   318,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    -1,    -1,    -1,    -1,
      -1,   107,    -1,   109,    -1,   111,    -1,   113,    -1,    -1,
     347,    -1,   118,    -1,   120,    -1,    -1,    -1,   124,   125,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   634,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   642,    -1,    -1,    -1,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,   175,
     176,   177,   178,   179,   180,   181,    -1,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
      -1,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,    -1,    -1,   245,
      -1,    -1,    -1,   744,   250,   251,    -1,   748,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,
      16,    -1,     4,     5,     6,     7,     8,     9,    24,    11,
      12,    -1,    -1,    29,    16,    -1,   777,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    29,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,
      16,    -1,     4,     5,     6,     7,     8,     9,    24,    11,
      12,    -1,    -1,    29,    16,    -1,    -1,   818,    -1,    75,
      76,    -1,    24,    -1,    -1,    -1,    -1,    29,    -1,   830,
      -1,   832,    -1,    75,    76,    -1,   837,    -1,    -1,    -1,
      -1,   347,     4,     5,     6,     7,     8,     9,    -1,    11,
      -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    75,
      76,    -1,    24,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    75,    76,     4,     5,     6,     7,     8,
       9,    -1,    11,    -1,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    75,    76,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    25,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    39,
      -1,    -1,     9,    -1,    11,    -1,    75,    76,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,     9,    39,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    -1,    22,    23,    -1,    25,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
       9,    39,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    -1,   750,    -1,    -1,    25,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      39,   768,    -1,    -1,   771,    -1,    -1,    -1,    -1,    -1,
       9,    -1,    11,    -1,   781,    -1,    15,    16,    17,    18,
      19,    20,   789,    22,    -1,    -1,    25,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      39,    -1,    -1,    -1,     9,    -1,    11,   814,    -1,   816,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,     9,    39,    11,    -1,   844,    -1,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,     9,    39,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    10,    39,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    25,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    10,
      -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    -1,   750,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   768,    10,    -1,   771,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,   781,    15,    16,    17,    18,
      19,    20,    -1,   789,    -1,    32,    33,    34,    35,    36,
      37,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      15,    16,    17,    18,    19,    20,    21,    -1,   814,    -1,
     816,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    25,    26,    27,    28,   844,    30,
      31,    32,    33,    34,    35,    36,    37,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    15,
      16,    17,    18,    19,    20,    21,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    37,    -1,    32,    33,    34,    35,    36,    37
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,     0,     3,     4,     5,     6,     7,     8,     9,    11,
      16,    24,    29,    56,    57,    58,    61,    62,    63,    64,
      65,    66,    67,    69,    70,    71,    72,    73,    74,    75,
      76,    79,    80,    81,    82,    85,    87,    88,    89,    90,
      91,    92,    94,    97,   101,   102,   103,   105,   106,   107,
     109,   110,   113,   114,   117,   118,   119,   120,   121,   123,
     125,     8,    75,   106,   107,   109,   110,   111,   113,   114,
     117,   118,   119,   120,     3,    12,    75,   105,   108,     9,
      16,    75,    76,   117,   118,     9,   113,   117,   118,   119,
     120,     9,    16,   117,    75,    75,    86,     9,     9,     9,
       3,    13,    82,    83,    84,   105,    75,    11,    68,    11,
      68,    11,    68,    11,    68,    75,    75,    98,    11,    13,
      39,    68,   112,   115,    11,    39,   112,     0,     0,     1,
      81,     3,     3,     3,     3,     3,     3,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    54,    55,
       9,    11,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    25,    26,    27,    28,    30,    31,    32,    33,    34,
      35,    36,    37,    39,   112,    11,    15,    16,    17,    25,
      32,    33,   112,    21,    25,    32,    33,    21,    25,    32,
      33,    15,    16,    17,    18,    19,    20,    21,    25,    26,
      27,    28,    30,    31,    32,    33,    34,    35,    36,    37,
      15,    16,    17,    18,    19,    20,    21,    25,    32,    33,
      34,    35,    36,    37,    11,    21,    25,    32,    33,    34,
      35,    36,    37,    21,    22,    23,    25,    32,    33,    68,
      68,     9,    75,    98,    10,    11,   115,    10,    10,    10,
      38,    40,    10,    10,    10,    10,   108,    40,     3,    12,
     117,   118,    15,    16,    17,    18,    19,    26,    27,    28,
      30,    31,    15,    16,    17,    18,    19,    20,   117,   118,
     119,   120,    21,    32,    33,    21,    32,    33,    34,    35,
      36,    37,    21,    32,    33,    34,    35,    36,    37,    21,
      25,    32,    33,    34,    35,    36,    37,    21,    22,    23,
      32,    33,   117,   117,    15,    16,    17,    18,    19,    42,
      40,   105,    75,   105,    13,    14,    80,    62,    42,    12,
     106,   111,   117,   118,   119,   120,   124,    12,   124,    12,
     124,    12,   124,     3,    13,     9,    12,    41,   111,   124,
      14,    39,   116,   106,   117,   111,   106,    81,   103,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,    10,   104,   105,   111,   106,   109,   117,   118,
     106,   109,   117,   118,   106,   109,   117,   118,   106,   117,
     118,   106,   117,   118,   106,   118,   106,   113,   114,   117,
     118,   119,   120,   106,   120,   106,   120,   106,   119,   106,
     117,   106,   117,   106,   117,   106,   117,   106,   117,   106,
     109,   113,   114,   117,   118,   119,   120,   106,   109,   113,
     114,   117,   118,   119,   120,   106,   117,   118,   119,   106,
     117,   118,   119,   106,   117,   118,   119,   106,   117,   118,
     119,   106,   111,   106,   109,   106,   109,   106,   109,   106,
     109,   106,   109,   106,   109,   106,   113,   114,   117,   118,
     119,   120,   106,   109,   106,   113,   106,   113,   106,   113,
     114,   117,   118,   119,   120,   106,   109,   106,   114,   106,
     114,   106,   117,   118,   106,   117,   118,   106,   117,   118,
     106,   117,   118,   106,   117,   118,   117,   118,   106,   113,
     114,   117,   118,   119,   120,   106,   109,   106,   117,   106,
     117,   106,   117,   106,   117,   106,   117,   106,   117,   118,
     106,   117,   118,   106,   117,   118,   106,   117,   118,   106,
     117,   118,   106,   117,   118,   106,   117,   118,   106,   117,
     118,   106,   117,   118,   106,   117,   118,   106,   117,   118,
     106,   117,   118,   106,   113,   114,   117,   118,   119,   120,
     106,   109,   106,   117,   118,   106,   117,   118,   106,   117,
     118,   106,   117,   118,   106,   117,   118,   106,   117,   118,
     111,   106,   113,   114,   117,   118,   119,   120,   106,   109,
     119,   106,   119,   106,   119,   106,   119,   106,   119,   106,
     119,   106,   119,   106,   113,   114,   117,   118,   119,   120,
     106,   120,   106,   120,   106,   109,   106,   120,   106,   120,
      10,    75,   122,   125,    42,     9,   111,    10,   111,   111,
       3,    12,     3,   108,    12,   117,   118,   117,   118,   117,
     118,   117,   118,   117,   118,   117,   117,   117,   117,   117,
     117,   118,   117,   118,   117,   118,   117,   118,   117,   118,
     117,   118,   113,   117,   118,   119,   120,     9,   113,   113,
     113,   117,   118,   119,   120,   117,   118,   117,   118,   117,
     118,   117,   118,   117,   118,   117,   118,   113,   117,   118,
     119,   120,   117,   118,   117,   118,   117,   118,   117,   118,
     117,   118,   117,   118,   113,   117,   118,   119,   120,   119,
     120,   119,   119,   119,   119,   119,   119,   113,   117,   118,
     119,   120,   120,   120,   120,   120,   117,   117,   117,   117,
     117,   105,    86,    10,    41,    10,    80,    14,     9,   105,
      40,    12,    12,    12,    12,    13,     3,    14,    56,    95,
      96,   101,   125,    10,    99,   100,   125,    12,    41,   111,
      12,    41,    12,    75,    14,    12,    10,    40,    12,    12,
      12,    11,    10,    40,   105,   115,    10,    99,    10,    38,
      12,   108,     8,    84,   105,    84,    14,     3,   105,   124,
      95,    95,    75,    14,     3,    75,    83,    10,    40,    40,
      75,    12,   111,    12,    41,    12,    41,   111,    42,   104,
     122,    83,    10,   111,    60,    93,    10,     3,    10,    14,
      42,    95,    42,    83,   125,   100,   125,    42,    12,    12,
     111,    12,   111,    12,    41,   105,    83,    10,    84,    84,
     105,   105,    75,    75,   105,    12,    12,    12,   111,    40,
      12,   116
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    78,    79,    79,    80,    80,    80,    81,    81,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    83,    83,    83,    83,    83,    84,    84,    85,    86,
      86,    87,    87,    87,    88,    88,    89,    90,    91,    92,
      93,    93,    94,    94,    94,    95,    95,    95,    95,    96,
      96,    96,    97,    97,    97,    97,    98,    99,    99,    99,
     100,   100,   101,   102,   102,   102,   102,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   104,   104,   105,   105,   105,   105,   105,   105,   105,
     105,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     107,   107,   107,   107,   107,   108,   108,   108,   109,   109,
     109,   109,   110,   110,   111,   111,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   113,   113,
     114,   114,   115,   115,   116,   116,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   121,   121,
     122,   122,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   124,   124,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     1,     2,     1,     2,     3,     1,     1,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     3,     4,     4,     5,     1,     1,     2,     1,
       3,     1,     1,     1,     1,     2,     7,     5,     6,     6,
       2,     0,     4,     5,     6,     1,     2,     2,     3,     1,
       4,     4,     5,     6,     5,     6,     1,     2,     1,     4,
       4,     3,     2,     4,     4,     4,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     3,     4,     4,     4,
       4,     4,     4,     2,     2,     2,     2,     3,     3,     3,
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
       2,     3,     4,     4,     5,     1,     3,     4,     1,     1,
       3,     3,     5,     7,     1,     1,     3,     4,     4,     5,
       4,     5,     5,     5,     6,     6,     6,     7,     1,     3,
       2,     4,     2,     3,     4,     6,     1,     2,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     3,
       1,     3,     4,     3,     4,     3,     4,     3,     4,     3,
       4,     3,     1,     3,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1
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
  "\"?\"", "\"\\\"int\\\"\"", "\"\\\"float\\\"\"", "\"\\\"string\\\"\"",
  "\"\\\"bool\\\"\"", "\"\\\"struct\\\"\"", "\"\\\"void\\\"\"",
  "\"identifier\"", "\"external identifier\"", "NEG", "$accept", "start",
  "stmt", "stmts", "stmts_ne", "block", "body", "import", "id_list",
  "flowctl", "return", "for", "while", "dowhile", "if", "else", "struct",
  "decllist", "declistval", "function", "fun_id", "funargs", "funargdef",
  "vardecl", "vardef", "set", "callarglist", "expr", "expr_var", "matrix",
  "matvals", "expr_mat", "range", "int_val", "slice", "expr_none",
  "expr_struct", "struct_val", "struct_list", "expr_int", "expr_float",
  "expr_str", "expr_bool", "funtype", "typelist", "mattype", "matsize",
  "type", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   215,   215,   216,   218,   219,   220,   224,   225,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   242,   243,   244,   245,   246,   249,   250,   254,   256,
     257,   261,   262,   263,   265,   266,   270,   274,   277,   281,
     287,   288,   292,   293,   294,   296,   297,   298,   299,   301,
     302,   303,   307,   308,   309,   310,   312,   314,   315,   316,
     318,   319,   323,   327,   328,   329,   330,   334,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   351,   352,   356,   357,   358,   359,   360,   361,   362,
     363,   366,   367,   368,   369,   370,   372,   373,   375,   376,
     377,   378,   379,   381,   382,   383,   384,   386,   387,   388,
     390,   391,   392,   394,   395,   396,   397,   398,   399,   400,
     401,   403,   404,   405,   406,   407,   409,   410,   411,   412,
     413,   415,   416,   417,   418,   419,   420,   421,   422,   424,
     425,   426,   427,   428,   429,   430,   431,   433,   434,   435,
     437,   438,   439,   441,   442,   443,   444,   445,   446,   447,
     449,   450,   451,   452,   453,   454,   455,   457,   458,   459,
     460,   461,   462,   463,   465,   466,   467,   468,   469,   470,
     471,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,   505,   506,   507,   509,   510,   511,   513,   514,
     515,   517,   518,   519,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     538,   539,   540,   542,   543,   544,   546,   547,   548,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     573,   574,   575,   576,   577,   579,   580,   581,   585,   586,
     587,   588,   590,   591,   593,   594,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   611,   612,
     616,   617,   619,   620,   622,   623,   627,   628,   629,   630,
     631,   632,   633,   634,   635,   636,   637,   638,   639,   640,
     644,   645,   646,   647,   648,   649,   650,   651,   652,   653,
     654,   655,   656,   657,   658,   659,   660,   661,   662,   663,
     664,   668,   669,   670,   671,   672,   673,   674,   675,   676,
     677,   678,   679,   680,   681,   682,   683,   684,   685,   686,
     687,   688,   689,   690,   691,   692,   693,   694,   698,   699,
     700,   701,   702,   704,   705,   706,   707,   708,   709,   710,
     712,   713,   714,   715,   716,   717,   718,   720,   721,   722,
     723,   724,   726,   727,   728,   729,   730,   732,   733,   734,
     735,   736,   738,   739,   740,   741,   742,   744,   748,   749,
     751,   752,   756,   757,   758,   759,   760,   761,   762,   763,
     764,   765,   767,   768,   772,   773,   774,   775,   776,   777,
     778,   779,   780,   781,   782,   783,   784,   785
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
#line 4383 "frontend/parser.cpp"

#line 788 "frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    auto msg = std::to_string(scanner->loc->begin.line) + ":" + std::to_string(scanner->loc->begin.column) + ": " + err_message;
    scanner->fatal_error(ptc::diag::ERR_SYNTAX, msg);
}
