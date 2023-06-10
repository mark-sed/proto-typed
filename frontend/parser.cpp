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
#line 44 "frontend/parser.yy"


    #include <cmath>
    #include <sstream>
    #include <vector>
    #include "scanner.hpp"
    #include "logging.hpp"
    #include "ir.hpp"

    // Set correct token method
    #undef yylex
    #define yylex scanner->yylex

#line 60 "frontend/parser.cpp"


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
#line 153 "frontend/parser.cpp"

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
#line 210 "frontend/parser.yy"
                        { scanner->parseMain(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1034 "frontend/parser.cpp"
    break;

  case 4: // stmt: stmts
#line 212 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1040 "frontend/parser.cpp"
    break;

  case 5: // stmt: stmt stmts
#line 213 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1046 "frontend/parser.cpp"
    break;

  case 6: // stmt: stmt error stmts
#line 214 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1052 "frontend/parser.cpp"
    break;

  case 7: // stmts: "terminator (\\n or ;)"
#line 218 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = nullptr; }
#line 1058 "frontend/parser.cpp"
    break;

  case 8: // stmts: stmts_ne
#line 219 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1064 "frontend/parser.cpp"
    break;

  case 9: // stmts_ne: set "terminator (\\n or ;)"
#line 221 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1070 "frontend/parser.cpp"
    break;

  case 10: // stmts_ne: vardecl "terminator (\\n or ;)"
#line 222 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1076 "frontend/parser.cpp"
    break;

  case 11: // stmts_ne: vardef "terminator (\\n or ;)"
#line 223 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1082 "frontend/parser.cpp"
    break;

  case 14: // stmts_ne: if
#line 226 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1088 "frontend/parser.cpp"
    break;

  case 15: // stmts_ne: while
#line 227 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1094 "frontend/parser.cpp"
    break;

  case 18: // stmts_ne: function
#line 230 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1100 "frontend/parser.cpp"
    break;

  case 19: // stmts_ne: flowctl "terminator (\\n or ;)"
#line 231 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1106 "frontend/parser.cpp"
    break;

  case 20: // stmts_ne: expr "terminator (\\n or ;)"
#line 232 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1112 "frontend/parser.cpp"
    break;

  case 21: // block: "{" "}"
#line 236 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1118 "frontend/parser.cpp"
    break;

  case 22: // block: "{" stmt "}"
#line 237 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1124 "frontend/parser.cpp"
    break;

  case 23: // block: "terminator (\\n or ;)" "{" stmt "}"
#line 238 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1130 "frontend/parser.cpp"
    break;

  case 24: // block: "{" stmt "}" "terminator (\\n or ;)"
#line 239 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1136 "frontend/parser.cpp"
    break;

  case 25: // block: "terminator (\\n or ;)" "{" stmt "}" "terminator (\\n or ;)"
#line 240 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1142 "frontend/parser.cpp"
    break;

  case 26: // body: stmts_ne
#line 243 "frontend/parser.yy"
                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1148 "frontend/parser.cpp"
    break;

  case 27: // body: block
#line 244 "frontend/parser.yy"
                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1154 "frontend/parser.cpp"
    break;

  case 33: // flowctl: return
#line 257 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1160 "frontend/parser.cpp"
    break;

  case 34: // return: "return"
#line 259 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(nullptr); }
#line 1166 "frontend/parser.cpp"
    break;

  case 35: // return: "return" expr
#line 260 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1172 "frontend/parser.cpp"
    break;

  case 37: // while: "while" "(" expr ")" body
#line 268 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::IR * > () = scanner->parseWhile(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1178 "frontend/parser.cpp"
    break;

  case 39: // if: "if" "(" expr ")" body else
#line 275 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::IR * > () = scanner->parseIfStmt(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1184 "frontend/parser.cpp"
    break;

  case 40: // else: "else" body
#line 281 "frontend/parser.yy"
                    { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1190 "frontend/parser.cpp"
    break;

  case 41: // else: %empty
#line 282 "frontend/parser.yy"
                    { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1196 "frontend/parser.cpp"
    break;

  case 52: // function: type fun_id "(" ")" block
#line 301 "frontend/parser.yy"
                                                     { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1202 "frontend/parser.cpp"
    break;

  case 53: // function: type fun_id "(" funargs ")" block
#line 302 "frontend/parser.yy"
                                                     { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[5].value.as < ptc::ir::IR * > (), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1208 "frontend/parser.cpp"
    break;

  case 54: // function: "\"void\"" fun_id "(" ")" block
#line 303 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1214 "frontend/parser.cpp"
    break;

  case 55: // function: "\"void\"" fun_id "(" funargs ")" block
#line 304 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1220 "frontend/parser.cpp"
    break;

  case 56: // fun_id: "identifier"
#line 306 "frontend/parser.yy"
            { scanner->enterFunScope(); yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1226 "frontend/parser.cpp"
    break;

  case 57: // funargs: type "identifier"
#line 308 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseFunParam(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1232 "frontend/parser.cpp"
    break;

  case 59: // funargs: funargs "," type "identifier"
#line 310 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseAddFunParam(yystack_[3].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1238 "frontend/parser.cpp"
    break;

  case 62: // vardecl: type "identifier"
#line 317 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1244 "frontend/parser.cpp"
    break;

  case 63: // vardef: type "identifier" "=" struct_val
#line 321 "frontend/parser.yy"
         { yylhs.value.as < ptc::ir::IR * > () = yystack_[3].value.as < ptc::ir::IR * > (); }
#line 1250 "frontend/parser.cpp"
    break;

  case 64: // vardef: type "identifier" "=" expr
#line 322 "frontend/parser.yy"
                                 { scanner->parseVarDef(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1256 "frontend/parser.cpp"
    break;

  case 67: // set: expr "++=" expr
#line 328 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1262 "frontend/parser.cpp"
    break;

  case 68: // set: expr "**=" expr
#line 329 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1268 "frontend/parser.cpp"
    break;

  case 69: // set: expr "%=" expr
#line 330 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1274 "frontend/parser.cpp"
    break;

  case 70: // set: expr "/=" expr
#line 331 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1280 "frontend/parser.cpp"
    break;

  case 71: // set: expr "*=" expr
#line 332 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1286 "frontend/parser.cpp"
    break;

  case 72: // set: expr "-=" expr
#line 333 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1292 "frontend/parser.cpp"
    break;

  case 73: // set: expr "+=" expr
#line 334 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1298 "frontend/parser.cpp"
    break;

  case 74: // set: expr "&=" expr
#line 335 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1304 "frontend/parser.cpp"
    break;

  case 75: // set: expr "|=" expr
#line 336 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1310 "frontend/parser.cpp"
    break;

  case 76: // set: expr "^=" expr
#line 337 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1316 "frontend/parser.cpp"
    break;

  case 77: // set: expr "<<=" expr
#line 338 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1322 "frontend/parser.cpp"
    break;

  case 78: // set: expr ">>=" expr
#line 339 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1328 "frontend/parser.cpp"
    break;

  case 79: // set: expr "=" expr
#line 340 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1334 "frontend/parser.cpp"
    break;

  case 80: // set: expr "=" set
#line 341 "frontend/parser.yy"
      { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1340 "frontend/parser.cpp"
    break;

  case 81: // callarglist: expr
#line 345 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseFunCallArg(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1346 "frontend/parser.cpp"
    break;

  case 82: // callarglist: callarglist "," expr
#line 346 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddFunCallArg(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1352 "frontend/parser.cpp"
    break;

  case 83: // expr: expr_mat
#line 350 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = nullptr; }
#line 1358 "frontend/parser.cpp"
    break;

  case 84: // expr: expr_var
#line 351 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1364 "frontend/parser.cpp"
    break;

  case 85: // expr: expr_none
#line 352 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = nullptr; }
#line 1370 "frontend/parser.cpp"
    break;

  case 86: // expr: expr_struct
#line 353 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = nullptr; }
#line 1376 "frontend/parser.cpp"
    break;

  case 87: // expr: expr_int
#line 354 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 1382 "frontend/parser.cpp"
    break;

  case 88: // expr: expr_float
#line 355 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFloat(yystack_[0].value.as < double > ()); }
#line 1388 "frontend/parser.cpp"
    break;

  case 89: // expr: expr_str
#line 356 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseString(yystack_[0].value.as < std::string > ()); }
#line 1394 "frontend/parser.cpp"
    break;

  case 90: // expr: expr_bool
#line 357 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseBool(yystack_[0].value.as < bool > ()); }
#line 1400 "frontend/parser.cpp"
    break;

  case 91: // expr_var: "identifier"
#line 360 "frontend/parser.yy"
              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > ()); }
#line 1406 "frontend/parser.cpp"
    break;

  case 92: // expr_var: "-" "identifier"
#line 361 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1412 "frontend/parser.cpp"
    break;

  case 93: // expr_var: "(" expr_var ")"
#line 362 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1418 "frontend/parser.cpp"
    break;

  case 94: // expr_var: expr_var "(" ")"
#line 364 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[2].value.as < ptc::ir::Expr * > (), std::vector<ptc::ir::Expr *>{}); }
#line 1424 "frontend/parser.cpp"
    break;

  case 95: // expr_var: expr_var "(" callarglist ")"
#line 365 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 1430 "frontend/parser.cpp"
    break;

  case 99: // expr_var: expr_var "[" int_val "]"
#line 370 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[3].value.as < ptc::ir::Expr * > (); }
#line 1436 "frontend/parser.cpp"
    break;

  case 102: // expr_var: expr_var slice
#line 374 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1442 "frontend/parser.cpp"
    break;

  case 104: // expr_var: expr_var "." expr_var
#line 377 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1448 "frontend/parser.cpp"
    break;

  case 106: // expr_var: expr_var "**" expr_float
#line 380 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1454 "frontend/parser.cpp"
    break;

  case 107: // expr_var: expr_var "**" expr_var
#line 381 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1460 "frontend/parser.cpp"
    break;

  case 110: // expr_var: expr_var "*" expr_int
#line 385 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1466 "frontend/parser.cpp"
    break;

  case 111: // expr_var: expr_var "*" expr_float
#line 386 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1472 "frontend/parser.cpp"
    break;

  case 114: // expr_var: expr_var "*" expr_mat
#line 389 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1478 "frontend/parser.cpp"
    break;

  case 115: // expr_var: expr_var "*" expr_var
#line 390 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1484 "frontend/parser.cpp"
    break;

  case 118: // expr_var: expr_var "/" expr_int
#line 394 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1490 "frontend/parser.cpp"
    break;

  case 119: // expr_var: expr_var "/" expr_float
#line 395 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1496 "frontend/parser.cpp"
    break;

  case 120: // expr_var: expr_var "/" expr_var
#line 396 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1502 "frontend/parser.cpp"
    break;

  case 123: // expr_var: expr_var "%" expr_int
#line 400 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1508 "frontend/parser.cpp"
    break;

  case 124: // expr_var: expr_var "%" expr_float
#line 401 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1514 "frontend/parser.cpp"
    break;

  case 125: // expr_var: expr_var "%" expr_var
#line 402 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1520 "frontend/parser.cpp"
    break;

  case 126: // expr_var: expr_int "+" expr_var
#line 404 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1526 "frontend/parser.cpp"
    break;

  case 127: // expr_var: expr_float "+" expr_var
#line 405 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1532 "frontend/parser.cpp"
    break;

  case 128: // expr_var: expr_var "+" expr_int
#line 406 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1538 "frontend/parser.cpp"
    break;

  case 129: // expr_var: expr_var "+" expr_float
#line 407 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1544 "frontend/parser.cpp"
    break;

  case 131: // expr_var: expr_var "+" expr_mat
#line 409 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1550 "frontend/parser.cpp"
    break;

  case 133: // expr_var: expr_var "+" expr_var
#line 411 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1556 "frontend/parser.cpp"
    break;

  case 136: // expr_var: expr_var "-" expr_int
#line 415 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1562 "frontend/parser.cpp"
    break;

  case 137: // expr_var: expr_var "-" expr_float
#line 416 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1568 "frontend/parser.cpp"
    break;

  case 139: // expr_var: expr_var "-" expr_mat
#line 418 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1574 "frontend/parser.cpp"
    break;

  case 141: // expr_var: expr_var "-" expr_var
#line 420 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1580 "frontend/parser.cpp"
    break;

  case 143: // expr_var: expr_var "<<" expr_int
#line 423 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1586 "frontend/parser.cpp"
    break;

  case 144: // expr_var: expr_var "<<" expr_var
#line 424 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1592 "frontend/parser.cpp"
    break;

  case 146: // expr_var: expr_var ">>" expr_int
#line 427 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1598 "frontend/parser.cpp"
    break;

  case 147: // expr_var: expr_var ">>" expr_var
#line 428 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1604 "frontend/parser.cpp"
    break;

  case 151: // expr_var: expr_var ">" expr_int
#line 433 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1610 "frontend/parser.cpp"
    break;

  case 152: // expr_var: expr_var ">" expr_float
#line 434 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1616 "frontend/parser.cpp"
    break;

  case 153: // expr_var: expr_var ">" expr_str
#line 435 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1622 "frontend/parser.cpp"
    break;

  case 154: // expr_var: expr_var ">" expr_var
#line 436 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1628 "frontend/parser.cpp"
    break;

  case 158: // expr_var: expr_var ">=" expr_int
#line 441 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1634 "frontend/parser.cpp"
    break;

  case 159: // expr_var: expr_var ">=" expr_float
#line 442 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1640 "frontend/parser.cpp"
    break;

  case 160: // expr_var: expr_var ">=" expr_str
#line 443 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1646 "frontend/parser.cpp"
    break;

  case 161: // expr_var: expr_var ">=" expr_var
#line 444 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1652 "frontend/parser.cpp"
    break;

  case 165: // expr_var: expr_var "<" expr_int
#line 449 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1658 "frontend/parser.cpp"
    break;

  case 166: // expr_var: expr_var "<" expr_float
#line 450 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1664 "frontend/parser.cpp"
    break;

  case 167: // expr_var: expr_var "<" expr_str
#line 451 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1670 "frontend/parser.cpp"
    break;

  case 168: // expr_var: expr_var "<" expr_var
#line 452 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1676 "frontend/parser.cpp"
    break;

  case 172: // expr_var: expr_var "<=" expr_int
#line 457 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1682 "frontend/parser.cpp"
    break;

  case 173: // expr_var: expr_var "<=" expr_float
#line 458 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1688 "frontend/parser.cpp"
    break;

  case 174: // expr_var: expr_var "<=" expr_str
#line 459 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1694 "frontend/parser.cpp"
    break;

  case 175: // expr_var: expr_var "<=" expr_var
#line 460 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1700 "frontend/parser.cpp"
    break;

  case 176: // expr_var: expr_int "==" expr_var
#line 462 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 1706 "frontend/parser.cpp"
    break;

  case 177: // expr_var: expr_float "==" expr_var
#line 463 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 1712 "frontend/parser.cpp"
    break;

  case 179: // expr_var: expr_bool "==" expr_var
#line 465 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 1718 "frontend/parser.cpp"
    break;

  case 183: // expr_var: expr_var "==" expr_int
#line 469 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 1724 "frontend/parser.cpp"
    break;

  case 184: // expr_var: expr_var "==" expr_float
#line 470 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 1730 "frontend/parser.cpp"
    break;

  case 185: // expr_var: expr_var "==" expr_str
#line 471 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1736 "frontend/parser.cpp"
    break;

  case 186: // expr_var: expr_var "==" expr_bool
#line 472 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 1742 "frontend/parser.cpp"
    break;

  case 187: // expr_var: expr_var "==" expr_none
#line 473 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1748 "frontend/parser.cpp"
    break;

  case 188: // expr_var: expr_var "==" expr_struct
#line 474 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1754 "frontend/parser.cpp"
    break;

  case 190: // expr_var: expr_var "==" expr_mat
#line 476 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1760 "frontend/parser.cpp"
    break;

  case 192: // expr_var: expr_var "==" expr_var
#line 478 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 1766 "frontend/parser.cpp"
    break;

  case 200: // expr_var: expr_var "!=" expr_int
#line 487 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1772 "frontend/parser.cpp"
    break;

  case 201: // expr_var: expr_var "!=" expr_float
#line 488 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1778 "frontend/parser.cpp"
    break;

  case 202: // expr_var: expr_var "!=" expr_str
#line 489 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1784 "frontend/parser.cpp"
    break;

  case 203: // expr_var: expr_var "!=" expr_bool
#line 490 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1790 "frontend/parser.cpp"
    break;

  case 204: // expr_var: expr_var "!=" expr_none
#line 491 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1796 "frontend/parser.cpp"
    break;

  case 205: // expr_var: expr_var "!=" expr_struct
#line 492 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1802 "frontend/parser.cpp"
    break;

  case 207: // expr_var: expr_var "!=" expr_mat
#line 494 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1808 "frontend/parser.cpp"
    break;

  case 209: // expr_var: expr_var "!=" expr_var
#line 496 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1814 "frontend/parser.cpp"
    break;

  case 211: // expr_var: expr_var "&" expr_int
#line 499 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1820 "frontend/parser.cpp"
    break;

  case 212: // expr_var: expr_var "&" expr_var
#line 500 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1826 "frontend/parser.cpp"
    break;

  case 214: // expr_var: expr_var "^" expr_int
#line 503 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1832 "frontend/parser.cpp"
    break;

  case 215: // expr_var: expr_var "^" expr_var
#line 504 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1838 "frontend/parser.cpp"
    break;

  case 217: // expr_var: expr_var "|" expr_int
#line 507 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1844 "frontend/parser.cpp"
    break;

  case 218: // expr_var: expr_var "|" expr_var
#line 508 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1850 "frontend/parser.cpp"
    break;

  case 233: // expr_var: expr_var "in" expr_str
#line 524 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1856 "frontend/parser.cpp"
    break;

  case 234: // expr_var: expr_var "in" expr_var
#line 525 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1862 "frontend/parser.cpp"
    break;

  case 236: // expr_var: expr_var "and" expr_bool
#line 528 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1868 "frontend/parser.cpp"
    break;

  case 237: // expr_var: expr_var "and" expr_var
#line 529 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1874 "frontend/parser.cpp"
    break;

  case 239: // expr_var: expr_var "or" expr_bool
#line 532 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1880 "frontend/parser.cpp"
    break;

  case 240: // expr_var: expr_var "or" expr_var
#line 533 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1886 "frontend/parser.cpp"
    break;

  case 258: // expr_var: expr_var "++" expr_int
#line 552 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1892 "frontend/parser.cpp"
    break;

  case 259: // expr_var: expr_var "++" expr_float
#line 553 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1898 "frontend/parser.cpp"
    break;

  case 260: // expr_var: expr_var "++" expr_str
#line 554 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1904 "frontend/parser.cpp"
    break;

  case 261: // expr_var: expr_var "++" expr_bool
#line 555 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1910 "frontend/parser.cpp"
    break;

  case 262: // expr_var: expr_var "++" expr_none
#line 556 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1916 "frontend/parser.cpp"
    break;

  case 263: // expr_var: expr_var "++" expr_struct
#line 557 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1922 "frontend/parser.cpp"
    break;

  case 264: // expr_var: expr_var "++" expr_var
#line 558 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1928 "frontend/parser.cpp"
    break;

  case 301: // expr_int: "int"
#line 616 "frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 1934 "frontend/parser.cpp"
    break;

  case 302: // expr_int: "-" expr_int
#line 617 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 1940 "frontend/parser.cpp"
    break;

  case 303: // expr_int: "(" expr_int ")"
#line 618 "frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 1946 "frontend/parser.cpp"
    break;

  case 304: // expr_int: "~" expr_int
#line 619 "frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 1952 "frontend/parser.cpp"
    break;

  case 305: // expr_int: expr_int "*" expr_int
#line 620 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 1958 "frontend/parser.cpp"
    break;

  case 306: // expr_int: expr_int "/" expr_int
#line 621 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 1964 "frontend/parser.cpp"
    break;

  case 307: // expr_int: expr_int "%" expr_int
#line 622 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 1970 "frontend/parser.cpp"
    break;

  case 308: // expr_int: expr_int "-" expr_int
#line 623 "frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 1976 "frontend/parser.cpp"
    break;

  case 309: // expr_int: expr_int "+" expr_int
#line 624 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 1982 "frontend/parser.cpp"
    break;

  case 310: // expr_int: expr_int "<<" expr_int
#line 625 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 1988 "frontend/parser.cpp"
    break;

  case 311: // expr_int: expr_int ">>" expr_int
#line 626 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 1994 "frontend/parser.cpp"
    break;

  case 312: // expr_int: expr_int "&" expr_int
#line 627 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 2000 "frontend/parser.cpp"
    break;

  case 313: // expr_int: expr_int "^" expr_int
#line 628 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 2006 "frontend/parser.cpp"
    break;

  case 314: // expr_int: expr_int "|" expr_int
#line 629 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 2012 "frontend/parser.cpp"
    break;

  case 315: // expr_float: "float"
#line 633 "frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 2018 "frontend/parser.cpp"
    break;

  case 316: // expr_float: "-" expr_float
#line 634 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 2024 "frontend/parser.cpp"
    break;

  case 317: // expr_float: "(" expr_float ")"
#line 635 "frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 2030 "frontend/parser.cpp"
    break;

  case 318: // expr_float: expr_float "**" expr_float
#line 636 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2036 "frontend/parser.cpp"
    break;

  case 319: // expr_float: expr_float "**" expr_int
#line 637 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2042 "frontend/parser.cpp"
    break;

  case 320: // expr_float: expr_int "**" expr_float
#line 638 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2048 "frontend/parser.cpp"
    break;

  case 321: // expr_float: expr_float "*" expr_float
#line 639 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 2054 "frontend/parser.cpp"
    break;

  case 322: // expr_float: expr_float "*" expr_int
#line 640 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 2060 "frontend/parser.cpp"
    break;

  case 323: // expr_float: expr_int "*" expr_float
#line 641 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 2066 "frontend/parser.cpp"
    break;

  case 324: // expr_float: expr_float "/" expr_float
#line 642 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 2072 "frontend/parser.cpp"
    break;

  case 325: // expr_float: expr_float "/" expr_int
#line 643 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 2078 "frontend/parser.cpp"
    break;

  case 326: // expr_float: expr_int "/" expr_float
#line 644 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 2084 "frontend/parser.cpp"
    break;

  case 327: // expr_float: expr_float "%" expr_float
#line 645 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2090 "frontend/parser.cpp"
    break;

  case 328: // expr_float: expr_float "%" expr_int
#line 646 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2096 "frontend/parser.cpp"
    break;

  case 329: // expr_float: expr_int "%" expr_float
#line 647 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2102 "frontend/parser.cpp"
    break;

  case 330: // expr_float: expr_float "-" expr_float
#line 648 "frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 2108 "frontend/parser.cpp"
    break;

  case 331: // expr_float: expr_float "-" expr_int
#line 649 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 2114 "frontend/parser.cpp"
    break;

  case 332: // expr_float: expr_int "-" expr_float
#line 650 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 2120 "frontend/parser.cpp"
    break;

  case 333: // expr_float: expr_float "+" expr_float
#line 651 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 2126 "frontend/parser.cpp"
    break;

  case 334: // expr_float: expr_float "+" expr_int
#line 652 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 2132 "frontend/parser.cpp"
    break;

  case 335: // expr_float: expr_int "+" expr_float
#line 653 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 2138 "frontend/parser.cpp"
    break;

  case 336: // expr_str: "string"
#line 657 "frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2144 "frontend/parser.cpp"
    break;

  case 337: // expr_str: "(" expr_str ")"
#line 658 "frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 2150 "frontend/parser.cpp"
    break;

  case 338: // expr_str: expr_str "++" expr_str
#line 659 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 2156 "frontend/parser.cpp"
    break;

  case 339: // expr_str: expr_str "++" expr_int
#line 660 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 2162 "frontend/parser.cpp"
    break;

  case 340: // expr_str: expr_str "++" expr_float
#line 661 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 2168 "frontend/parser.cpp"
    break;

  case 341: // expr_str: expr_str "++" expr_bool
#line 662 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2174 "frontend/parser.cpp"
    break;

  case 342: // expr_str: expr_str "++" expr_none
#line 663 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 2180 "frontend/parser.cpp"
    break;

  case 343: // expr_str: expr_int "++" expr_str
#line 664 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 2186 "frontend/parser.cpp"
    break;

  case 344: // expr_str: expr_int "++" expr_int
#line 665 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 2192 "frontend/parser.cpp"
    break;

  case 345: // expr_str: expr_int "++" expr_float
#line 666 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 2198 "frontend/parser.cpp"
    break;

  case 346: // expr_str: expr_int "++" expr_bool
#line 667 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2204 "frontend/parser.cpp"
    break;

  case 347: // expr_str: expr_int "++" expr_none
#line 668 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 2210 "frontend/parser.cpp"
    break;

  case 348: // expr_str: expr_float "++" expr_str
#line 669 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 2216 "frontend/parser.cpp"
    break;

  case 349: // expr_str: expr_float "++" expr_int
#line 670 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 2222 "frontend/parser.cpp"
    break;

  case 350: // expr_str: expr_float "++" expr_float
#line 671 "frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 2228 "frontend/parser.cpp"
    break;

  case 351: // expr_str: expr_float "++" expr_bool
#line 672 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2234 "frontend/parser.cpp"
    break;

  case 352: // expr_str: expr_float "++" expr_none
#line 673 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 2240 "frontend/parser.cpp"
    break;

  case 353: // expr_str: expr_bool "++" expr_str
#line 674 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 2246 "frontend/parser.cpp"
    break;

  case 354: // expr_str: expr_bool "++" expr_int
#line 675 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 2252 "frontend/parser.cpp"
    break;

  case 355: // expr_str: expr_bool "++" expr_float
#line 676 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 2258 "frontend/parser.cpp"
    break;

  case 356: // expr_str: expr_bool "++" expr_bool
#line 677 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2264 "frontend/parser.cpp"
    break;

  case 357: // expr_str: expr_bool "++" expr_none
#line 678 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 2270 "frontend/parser.cpp"
    break;

  case 358: // expr_str: expr_none "++" expr_str
#line 679 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 2276 "frontend/parser.cpp"
    break;

  case 359: // expr_str: expr_none "++" expr_int
#line 680 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 2282 "frontend/parser.cpp"
    break;

  case 360: // expr_str: expr_none "++" expr_float
#line 681 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 2288 "frontend/parser.cpp"
    break;

  case 361: // expr_str: expr_none "++" expr_bool
#line 682 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2294 "frontend/parser.cpp"
    break;

  case 362: // expr_str: expr_none "++" expr_none
#line 683 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 2300 "frontend/parser.cpp"
    break;

  case 363: // expr_bool: "bool"
#line 687 "frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 2306 "frontend/parser.cpp"
    break;

  case 364: // expr_bool: "(" expr_bool ")"
#line 688 "frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 2312 "frontend/parser.cpp"
    break;

  case 365: // expr_bool: "not" expr_bool
#line 689 "frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 2318 "frontend/parser.cpp"
    break;

  case 366: // expr_bool: expr_bool "or" expr_bool
#line 690 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 2324 "frontend/parser.cpp"
    break;

  case 367: // expr_bool: expr_bool "and" expr_bool
#line 691 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 2330 "frontend/parser.cpp"
    break;

  case 368: // expr_bool: expr_bool "==" expr_bool
#line 693 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 2336 "frontend/parser.cpp"
    break;

  case 369: // expr_bool: expr_int "==" expr_int
#line 694 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 2342 "frontend/parser.cpp"
    break;

  case 370: // expr_bool: expr_int "==" expr_float
#line 695 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 2348 "frontend/parser.cpp"
    break;

  case 371: // expr_bool: expr_float "==" expr_float
#line 696 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 2354 "frontend/parser.cpp"
    break;

  case 372: // expr_bool: expr_float "==" expr_int
#line 697 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 2360 "frontend/parser.cpp"
    break;

  case 373: // expr_bool: expr_str "==" expr_str
#line 698 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 2366 "frontend/parser.cpp"
    break;

  case 374: // expr_bool: expr_none "==" expr_none
#line 699 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 2372 "frontend/parser.cpp"
    break;

  case 375: // expr_bool: expr_bool "!=" expr_bool
#line 701 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 2378 "frontend/parser.cpp"
    break;

  case 376: // expr_bool: expr_int "!=" expr_int
#line 702 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 2384 "frontend/parser.cpp"
    break;

  case 377: // expr_bool: expr_int "!=" expr_float
#line 703 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 2390 "frontend/parser.cpp"
    break;

  case 378: // expr_bool: expr_float "!=" expr_float
#line 704 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 2396 "frontend/parser.cpp"
    break;

  case 379: // expr_bool: expr_float "!=" expr_int
#line 705 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 2402 "frontend/parser.cpp"
    break;

  case 380: // expr_bool: expr_str "!=" expr_str
#line 706 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 2408 "frontend/parser.cpp"
    break;

  case 381: // expr_bool: expr_none "!=" expr_none
#line 707 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 2414 "frontend/parser.cpp"
    break;

  case 382: // expr_bool: expr_int ">" expr_int
#line 709 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 2420 "frontend/parser.cpp"
    break;

  case 383: // expr_bool: expr_int ">" expr_float
#line 710 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 2426 "frontend/parser.cpp"
    break;

  case 384: // expr_bool: expr_float ">" expr_float
#line 711 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 2432 "frontend/parser.cpp"
    break;

  case 385: // expr_bool: expr_float ">" expr_int
#line 712 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 2438 "frontend/parser.cpp"
    break;

  case 386: // expr_bool: expr_str ">" expr_str
#line 713 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 2444 "frontend/parser.cpp"
    break;

  case 387: // expr_bool: expr_int "<" expr_int
#line 715 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 2450 "frontend/parser.cpp"
    break;

  case 388: // expr_bool: expr_int "<" expr_float
#line 716 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 2456 "frontend/parser.cpp"
    break;

  case 389: // expr_bool: expr_float "<" expr_float
#line 717 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 2462 "frontend/parser.cpp"
    break;

  case 390: // expr_bool: expr_float "<" expr_int
#line 718 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 2468 "frontend/parser.cpp"
    break;

  case 391: // expr_bool: expr_str "<" expr_str
#line 719 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 2474 "frontend/parser.cpp"
    break;

  case 392: // expr_bool: expr_int ">=" expr_int
#line 721 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 2480 "frontend/parser.cpp"
    break;

  case 393: // expr_bool: expr_int ">=" expr_float
#line 722 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 2486 "frontend/parser.cpp"
    break;

  case 394: // expr_bool: expr_float ">=" expr_float
#line 723 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 2492 "frontend/parser.cpp"
    break;

  case 395: // expr_bool: expr_float ">=" expr_int
#line 724 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 2498 "frontend/parser.cpp"
    break;

  case 396: // expr_bool: expr_str ">=" expr_str
#line 725 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 2504 "frontend/parser.cpp"
    break;

  case 397: // expr_bool: expr_int "<=" expr_int
#line 727 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 2510 "frontend/parser.cpp"
    break;

  case 398: // expr_bool: expr_int "<=" expr_float
#line 728 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 2516 "frontend/parser.cpp"
    break;

  case 399: // expr_bool: expr_float "<=" expr_float
#line 729 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 2522 "frontend/parser.cpp"
    break;

  case 400: // expr_bool: expr_float "<=" expr_int
#line 730 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 2528 "frontend/parser.cpp"
    break;

  case 401: // expr_bool: expr_str "<=" expr_str
#line 731 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 2534 "frontend/parser.cpp"
    break;

  case 402: // expr_bool: expr_str "in" expr_str
#line 733 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[0].value.as < std::string > ().find(yystack_[2].value.as < std::string > ()) != std::string::npos; }
#line 2540 "frontend/parser.cpp"
    break;

  case 419: // type: "\"int\"" "?"
#line 761 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2546 "frontend/parser.cpp"
    break;

  case 420: // type: "\"float\"" "?"
#line 762 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2552 "frontend/parser.cpp"
    break;

  case 421: // type: "\"string\"" "?"
#line 763 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2558 "frontend/parser.cpp"
    break;

  case 422: // type: "\"bool\"" "?"
#line 764 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2564 "frontend/parser.cpp"
    break;

  case 423: // type: "identifier" "?"
#line 765 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2570 "frontend/parser.cpp"
    break;

  case 424: // type: funtype "?"
#line 766 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2576 "frontend/parser.cpp"
    break;

  case 425: // type: mattype "?"
#line 767 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2582 "frontend/parser.cpp"
    break;

  case 426: // type: "\"int\""
#line 768 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("int"); }
#line 2588 "frontend/parser.cpp"
    break;

  case 427: // type: "\"float\""
#line 769 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("float"); }
#line 2594 "frontend/parser.cpp"
    break;

  case 428: // type: "\"string\""
#line 770 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("string"); }
#line 2600 "frontend/parser.cpp"
    break;

  case 429: // type: "\"bool\""
#line 771 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("bool"); }
#line 2606 "frontend/parser.cpp"
    break;

  case 430: // type: "identifier"
#line 772 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[0].value.as < std::string > ()); }
#line 2612 "frontend/parser.cpp"
    break;

  case 431: // type: funtype
#line 773 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2618 "frontend/parser.cpp"
    break;

  case 432: // type: mattype
#line 774 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2624 "frontend/parser.cpp"
    break;


#line 2628 "frontend/parser.cpp"

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

  const short  Parser ::yytable_ninf_ = -431;

  const short
   Parser ::yypact_[] =
  {
    2131,  -732,  -732,  -732,  -732,  -732,  -732,  -732,  1800,    29,
      52,  1896,   218,   -13,     9,    79,    83,   101,  2341,  1839,
    -732,  -732,    86,    -5,     6,    28,    44,   137,   163,   351,
     176,  1365,  -732,  -732,   191,   245,  -732,  -732,  -732,  -732,
    -732,  -732,  -732,   260,   276,   306,  1354,  2549,  -732,  1192,
    -732,   204,   443,  2845,  3001,   683,  1125,   252,   257,     5,
     319,   182,  2461,   321,  1192,   323,   158,   204,   443,  2735,
    2092,   866,   371,  1839,  -732,   182,   342,   221,   246,   246,
    -732,  -732,  -732,  2830,   125,  2886,  3024,  1033,  -732,   218,
     218,  -732,   345,  -732,   355,  1839,   286,  1839,   350,  2372,
    -732,  -732,   352,  -732,   365,   576,  -732,   669,  -732,  1127,
    -732,  1177,  -732,   261,  -732,   411,   424,    76,  1839,  -732,
    -732,  -732,  -732,  -732,  2445,  -732,  -732,  -732,  -732,  -732,
    -732,  -732,  1839,  1839,  1839,  1839,  1839,  1839,  1839,  1839,
    1839,  1839,  1839,  1839,  1839,   331,  1032,  1839,  1839,  1839,
    1839,  1839,  1839,  1839,  1839,  1839,  1839,  1839,  1839,  1839,
    1839,  1839,  1839,  1839,  1839,  1839,  1839,  1839,  1839,  -732,
    1032,  1839,  1839,  1839,  1839,  1839,  1839,  -732,  1839,  1839,
    1839,  1839,  1839,  1839,  1839,  1839,  1839,  1839,  1839,  1839,
    1839,   246,  1839,  1839,  1839,  1839,  1839,  1839,  1839,  1839,
    1839,  1839,  1839,  1839,  1839,  1839,  1839,  1839,  1839,  1839,
    1839,  1839,  1839,  1839,  1839,  1839,  1839,  1839,  1839,  1839,
    1839,  1839,  1839,  1839,  1839,  1839,  1839,  1839,  1839,  1839,
    1839,  1839,  1839,  1839,  -732,  -732,    50,    66,   416,  -732,
    1032,   427,  -732,  -732,  -732,  1839,  1839,  -732,  -732,  -732,
    -732,   253,    43,   422,  -732,  3086,   863,   246,   246,   246,
     246,   246,   218,   218,   218,   218,   218,   246,   246,   246,
     246,   246,   246,  2763,  2796,   925,   495,  1896,    98,    98,
    1896,   246,   246,   246,   246,   246,   246,  1896,   246,   246,
     246,   246,   246,   246,  1896,  1896,  1896,  1896,  1896,  1896,
    1896,  1896,  1896,  1896,  1896,  1896,  1896,  2146,  -732,   218,
     218,   218,   218,   218,  1839,   363,   429,   401,   434,  2445,
    -732,  2231,   438,  1839,  -732,  2549,   414,  2845,  3001,   683,
    1125,   454,  -732,   455,  -732,   458,  -732,   461,   476,   100,
     314,  -732,   638,    30,   485,  -732,   415,   484,   267,  2845,
    -732,  -732,  2843,  -732,  -732,  -732,  -732,  -732,  -732,  -732,
    -732,  -732,  -732,  -732,  -732,  -732,    54,  -732,    64,   432,
       4,   551,   646,   432,     4,   551,   646,    89,   493,   486,
     487,    89,   486,   487,    89,   486,   487,    89,   487,  2588,
     333,   391,  2909,  3047,  1130,   478,  2646,   459,  2617,   152,
    2675,   510,  2516,  2000,  2707,  2955,  1467,  2978,   822,  1156,
     822,  1156,   731,   296,  -732,  -732,   966,  1343,   317,  -732,
     731,   296,  -732,  -732,   966,  1343,   317,  -732,   463,  1083,
    1335,   498,   463,  1083,  1335,   498,   463,  1083,  1335,   498,
     463,  1083,  1335,   498,   267,    90,   432,     4,   432,     4,
      89,   493,  2675,   591,   731,   296,   731,   296,  2588,   333,
     391,  2909,  3047,  1130,   478,  2675,   591,   731,  -732,   731,
    -732,  2588,   333,   391,  2909,  3047,  1130,   478,  2675,   591,
     731,  -732,   731,  -732,   432,   551,   646,   432,   551,   646,
      89,   486,   487,    89,   486,   487,    89,   486,   487,  3103,
     499,  2588,   333,   391,  2909,  3047,  1130,   478,  2675,   591,
    2516,  2000,  2707,  2955,  1467,  2978,   822,  1156,   822,  1156,
     731,   966,  1343,   731,   966,  1343,   463,  1083,  1335,   463,
    1083,  1335,   463,  1083,  1335,   463,  1083,  1335,   432,   551,
     646,   432,   551,   646,    89,   486,   487,    89,   486,   487,
      89,   486,   487,    89,   486,   487,  2588,   333,   391,  2909,
    3047,  1130,   478,  2675,   591,   731,   966,  1343,   731,   966,
    1343,   463,  1083,  1335,   463,  1083,  1335,   463,  1083,  1335,
     463,  1083,  1335,   508,  2588,   333,   391,  2909,  3047,  1130,
     478,  2675,   591,   510,   731,   317,   731,   317,   463,   498,
     463,   498,   463,   498,   463,   498,  2588,   333,   391,  2909,
    3047,  1130,   478,  2646,   459,  2617,   152,  2675,   591,   731,
    -732,   731,  -732,  -732,    55,   538,    35,  1307,   340,   114,
    -732,   541,   515,   543,  -732,  1839,  -732,  -732,   715,   769,
     715,   769,   486,   499,   486,   499,   486,   499,   897,  1650,
    1687,   684,   684,   715,   769,   715,   769,   486,   499,   486,
     499,   486,   499,   486,   499,   147,  2932,  3058,   561,   491,
     549,  -732,  -732,   147,  2932,  3058,   561,   491,  1724,  1427,
    1724,  1427,  1724,  1427,  1724,  1427,  1724,  1427,  1724,  1427,
     147,  2932,  3058,   561,   491,  1724,  1427,  1724,  1427,  1724,
    1427,  1724,  1427,  1724,  1427,  1724,  1427,   147,  2932,  3058,
     561,   491,  1510,   294,   778,   778,  -732,  -732,  -732,  -732,
     147,  2932,  3058,   561,   491,   312,   324,  -732,  -732,   213,
     213,  -732,  -732,  -732,  -732,  -732,  2341,  1839,  2341,  2261,
     556,  1839,  -732,  1839,  -732,  -732,  -732,  -732,   170,   170,
    -732,   488,   547,   559,  -732,     7,   405,   119,   525,    14,
    -732,  1450,   142,  -732,   913,  -732,   524,  -732,  -732,  1839,
    -732,  -732,  -732,  1648,  -732,   620,  -732,  -732,   405,   120,
    -732,  1839,  -732,  -732,   319,   519,   565,  -732,   586,  -732,
     580,  -732,   577,  -732,   557,  -732,   170,   562,  -732,   405,
     620,   620,   583,  -732,   614,  -732,  1685,  -732,  1722,   156,
    1839,  -732,  -732,  -732,   405,   593,  2341,  -732,  2341,  -732,
    -732,  -732,  1839,  -732,  1839,  -732,    16,   525,    18,  1839,
    -732,  -732,   616,  -732,   617,  -732,  1774,   594,  -732,  -732,
    -732,  -732,  -732,  -732,  -732,   583,  -732,  -732,  -732,  -732,
     621,   597,  -732,  -732
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     7,   301,   315,   336,   363,   293,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      31,    32,     0,   426,   427,   428,   429,     0,     0,    91,
       0,     0,     4,     8,     0,     0,    33,    13,    15,    16,
      14,    17,    18,     0,     0,     0,     0,    84,   273,    83,
     274,    85,    86,    87,    88,    89,    90,   431,   432,     0,
     293,    91,   280,   273,     0,   274,     0,     0,     0,   279,
       0,     0,     0,     0,   265,    91,   270,     0,     0,     0,
      92,   302,   316,     0,     0,     0,     0,     0,   365,     0,
       0,   304,     0,    29,    28,     0,     0,     0,     0,     0,
      26,    27,     0,    35,     0,     0,   419,     0,   420,     0,
     421,     0,   422,     0,    56,     0,     0,     0,     0,   423,
     101,   295,     1,     3,     0,     5,    12,    19,    10,    11,
       9,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   102,
       0,     0,     0,     0,     0,     0,     0,   100,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   424,   425,     0,    56,     0,   294,
       0,   295,    93,   275,   276,     0,     0,   303,   317,   337,
     364,     0,     0,     0,   266,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   302,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,     0,   410,   280,   417,   279,     0,     0,
       0,     0,   412,     0,   414,     0,   416,     0,     0,     0,
       0,   408,     0,     0,     0,   297,     0,     0,   103,     0,
       6,    80,    79,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    94,     0,    81,     0,   133,
     131,   128,   129,   141,   139,   136,   137,   115,   114,   110,
     111,   120,   118,   119,   125,   123,   124,   107,   106,   264,
     262,   263,   258,   259,   260,   261,   237,   236,   240,   239,
     234,   233,   212,   211,   218,   217,   215,   214,   144,   143,
     147,   146,   192,   190,   187,   188,   183,   184,   185,   186,
     209,   207,   204,   205,   200,   201,   202,   203,   154,   151,
     152,   153,   168,   165,   166,   167,   161,   158,   159,   160,
     175,   172,   173,   174,   104,     0,   132,   130,   140,   138,
     113,   112,   232,   225,   191,   189,   208,   206,   256,   362,
     245,   359,   360,   358,   361,   230,   223,   180,   374,   197,
     381,   257,   250,   251,   246,   247,   248,   249,   231,   224,
     182,   181,   199,   198,   126,   309,   335,   134,   308,   332,
     108,   305,   323,   116,   306,   326,   121,   307,   329,     0,
     320,   252,   347,   241,   344,   345,   343,   346,   226,   219,
     210,   312,   216,   314,   213,   313,   142,   310,   145,   311,
     176,   369,   370,   193,   376,   377,   148,   382,   383,   162,
     387,   388,   155,   392,   393,   169,   397,   398,   127,   334,
     333,   135,   331,   330,   109,   322,   321,   117,   325,   324,
     122,   328,   327,   105,   319,   318,   253,   352,   242,   349,
     350,   348,   351,   227,   220,   177,   372,   371,   194,   379,
     378,   149,   385,   384,   163,   390,   389,   156,   395,   394,
     170,   400,   399,     0,   254,   342,   243,   339,   340,   338,
     341,   228,   221,   402,   178,   373,   195,   380,   150,   386,
     164,   391,   157,   396,   171,   401,   255,   357,   244,   354,
     355,   353,   356,   235,   367,   238,   366,   229,   222,   179,
     368,   196,   375,   404,   430,     0,   405,     0,     0,     0,
     296,     0,     0,     0,   267,     0,   271,   268,   309,   335,
     308,   332,   305,   323,   306,   326,   307,   329,   312,   314,
     313,   310,   311,   334,   333,   331,   330,   322,   321,   325,
     324,   328,   327,   319,   318,   362,   359,   360,   358,   361,
       0,   374,   381,   347,   344,   345,   343,   346,   369,   370,
     376,   377,   382,   383,   387,   388,   392,   393,   397,   398,
     352,   349,   350,   348,   351,   372,   371,   379,   378,   385,
     384,   390,   389,   395,   394,   400,   399,   342,   339,   340,
     338,   341,   402,     0,   373,   380,   386,   391,   396,   401,
     357,   354,   355,   353,   356,   367,   366,   368,   375,   309,
     308,   305,   306,   307,    66,    30,     0,     0,     0,     0,
      22,     0,    65,     0,   409,   411,   413,   415,     0,    45,
      42,     0,     0,     0,    49,     0,     0,     0,    58,     0,
     281,     0,     0,    98,     0,   407,     0,   298,    95,     0,
      99,    97,    96,     0,   403,     0,    64,    63,     0,     0,
     277,     0,   269,   272,     0,    41,     0,    37,    23,    24,
       0,   418,     0,    46,     0,    43,    47,    62,    54,     0,
       0,     0,    57,   285,     0,   283,     0,   282,     0,     0,
       0,    82,   406,    52,     0,     0,     0,    39,     0,    25,
      38,    44,     0,    48,     0,    55,     0,    61,     0,     0,
     288,   287,     0,   286,     0,   284,     0,   299,    53,   278,
      40,    36,    51,    50,    59,     0,    60,   291,   290,   289,
       0,     0,   292,   300
  };

  const short
   Parser ::yypgoto_[] =
  {
    -732,  -732,   -96,   -11,   -14,  -713,  -731,  -732,  -732,  -732,
    -732,  -732,  -732,  -732,  -732,  -732,  -732,  -719,  -732,  -732,
     578,    10,  -160,  -327,  -732,   516,  -732,  2086,  1405,   644,
     -71,   947,   645,   103,   877,   712,  1097,   -60,  -195,  1781,
       0,   235,   477,  -732,  -118,  -732,   -83,  -223
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    30,    31,    32,    33,   101,   102,    34,    94,    35,
      36,    37,    38,    39,    40,   817,    41,   752,   753,    42,
     115,   757,   758,    43,    44,    45,   366,    46,    47,    48,
      77,    64,    50,   326,   169,    67,    68,   121,   347,    53,
     328,   329,   330,    57,   625,    58,   344,    59
  };

  const short
   Parser ::yytable_[] =
  {
      54,   241,   251,   321,   100,   785,   105,   787,    70,    54,
      82,    86,   754,   626,   236,   170,   236,   107,    54,    54,
     125,   173,   331,   236,   333,   236,   335,   236,   337,   792,
     793,    54,    73,     3,     4,     5,     6,     7,     8,   109,
       9,    74,   763,   798,   236,    10,   635,     3,     4,     5,
       6,     7,     8,    11,     9,   111,     3,     4,    12,    10,
     623,    78,    92,   106,   768,   813,   773,    11,    79,   -62,
     743,   764,    12,    54,   108,   775,   770,   823,   256,    82,
     237,    12,   797,   274,    93,   840,   825,   841,    95,   802,
     345,   844,    96,   845,   769,    54,   110,    54,   145,    54,
     146,   838,   771,   749,    75,   764,     7,   670,   627,   152,
      97,    66,   112,   350,   750,   346,   755,   759,    75,    23,
      24,    25,    26,   119,    54,   624,   763,    80,   168,   799,
     814,   764,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,   277,   372,   376,   380,
     383,   386,   388,   393,   805,   764,   751,   278,   279,   800,
     800,   104,   417,   425,   430,   434,   438,   442,   835,    23,
      24,    25,    26,   749,   229,   624,   122,   231,   462,   278,
     279,   636,   475,   806,   232,   233,   486,   489,   492,   495,
     498,   500,   505,   240,   126,   117,   245,   836,   246,   522,
     525,   528,   531,   534,   537,   540,   543,   546,   549,   552,
     555,   560,   113,   567,   570,   573,   576,   579,   582,   343,
     588,   118,     3,   739,   253,   178,   751,    89,   610,   179,
     311,   312,   313,   254,    90,    55,   180,   181,   114,    23,
      24,    25,    26,    71,    55,   624,    87,    12,   127,   368,
       3,     4,    54,    55,    55,    78,   633,   639,   641,   643,
     645,   647,    79,   128,   338,   634,    55,   654,   656,   658,
     660,   662,   664,   445,   339,    12,   145,   667,   146,   129,
     675,   679,   681,   683,   685,   687,   689,   692,   696,   698,
     700,   702,   704,   706,   709,    86,    86,    86,    86,    86,
      86,    86,   722,    86,    86,    86,    86,   170,    55,   130,
     125,   171,   172,   173,    54,   302,   303,   304,   275,    54,
     234,    54,   583,    54,   756,   235,   305,   306,   219,   239,
      55,   243,    55,   244,    55,     3,     4,     5,     6,     7,
       8,   365,     9,   629,   305,   306,   303,    10,   631,   632,
     778,   224,   225,   226,   227,    11,   305,   306,   179,    55,
      12,   317,   116,   319,   117,   180,   181,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,   250,   252,    23,    24,    25,    26,   314,   394,   624,
     118,   401,   228,   229,   230,   315,   231,   418,   426,   431,
     435,   439,   443,   232,   233,   759,    75,   323,    98,    23,
      24,    25,    26,   463,   322,   624,   183,   476,    99,   119,
     340,   754,   754,   184,   185,   628,  -430,   506,     3,     4,
       5,     6,     7,     8,   637,     9,   341,   630,   735,   736,
      10,   145,   737,   146,   738,   762,   561,   741,    11,   149,
     150,   151,   152,    12,   743,   589,   593,   595,   597,   599,
     601,   603,   605,   611,   182,   342,   744,   745,   183,   754,
     746,   168,   145,   747,   146,   184,   185,    56,   147,   148,
     149,   150,   151,   152,   231,    72,    56,    55,    88,   748,
     766,   232,   233,   160,   161,    56,    56,   765,   767,    75,
     229,   230,   168,   231,   170,   250,   191,   210,    56,   219,
     232,   233,   668,   303,   304,   676,   302,   303,   304,   272,
     772,   219,   693,   305,   306,   755,   755,   305,   306,   710,
     712,   714,   715,   716,   717,   718,   719,   723,    87,    87,
      87,    87,   222,   223,   224,   225,   226,   227,   774,    55,
      56,   780,   626,   781,    55,   782,    55,   784,    55,   789,
     276,   795,   796,   794,   783,   801,   810,   777,   188,   189,
     190,   191,    56,   755,    56,   818,    56,   826,   828,   816,
       3,     4,     5,     6,     7,     8,   295,     9,   324,   819,
     820,   821,    10,   296,   297,   298,   299,   300,   301,   822,
      11,    56,   170,   839,   824,    12,   171,   172,   173,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,   175,   176,   829,   830,    54,   847,   848,
     395,   397,   399,   852,   851,    54,   346,   238,   779,   419,
     427,   827,     3,     4,     5,     6,     7,     8,   351,     9,
     760,    75,    63,    65,    10,   464,   853,   812,     0,   477,
     791,     0,    11,   207,   208,   209,   210,    12,     0,   507,
       0,     0,     0,     3,     4,     5,     6,     7,     8,   761,
       9,   332,     0,     0,     0,    10,     0,     0,   562,    23,
      24,    25,    26,    11,   219,   624,     0,   590,    12,   309,
     310,   311,   312,   313,   220,   612,   614,   616,   221,   620,
     622,     0,    51,    75,     0,   222,   223,   224,   225,   226,
     227,    51,   100,    84,   100,     0,     0,     0,   125,    56,
      51,    51,   259,   260,   261,   191,    54,    54,    54,    54,
     145,    54,   146,    51,    75,     0,   147,   148,   149,   150,
     151,   152,     0,     0,   669,     0,     0,   677,     0,     0,
       0,   160,   161,     0,   694,   164,   165,   166,   167,    54,
     168,   711,   713,   713,   713,   713,   713,   713,   713,   724,
     725,   726,   727,   728,     0,    51,   269,   270,   271,   272,
       0,    56,     0,     0,     0,    84,    56,     0,    56,     0,
      56,     0,   100,     0,   100,     0,     0,    51,     0,    51,
      54,    51,   298,   299,   300,   301,    54,     0,    54,     0,
       0,     0,    54,     0,    54,     0,     0,     0,     0,    54,
       0,   145,     0,   146,     0,     0,    51,   147,   148,   149,
     150,   151,   152,     0,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,     0,     0,
       0,   168,    55,     0,   804,   390,     0,   809,     0,     0,
      55,     0,     0,   248,   414,   422,   249,   219,   267,   268,
     269,   270,   271,   272,   815,     0,     0,   220,     0,     0,
     459,   221,   468,   470,   472,     0,     0,     0,   222,   223,
     224,   225,   226,   227,   502,     0,   120,     0,     0,   832,
       0,   834,   309,   310,   311,   312,   313,     3,     4,     5,
       6,     7,     8,   557,     9,   807,   177,   265,   266,    10,
       0,     0,   585,     0,     0,   249,     0,    11,   120,   850,
     607,   177,    12,     0,     0,     0,   294,    49,     0,     0,
     295,     0,   120,     0,   808,     0,    49,   296,   297,   298,
     299,   300,   301,     0,    51,    49,    49,     0,     0,     0,
       0,    55,    55,    55,    55,     0,    55,     0,    49,     0,
       0,   186,   187,   188,   189,   190,   191,     0,    75,   665,
     671,   672,   673,     0,     0,     0,   197,   198,     0,   690,
     201,   202,   203,   204,    55,     0,   707,    84,    84,    84,
      84,    84,    84,    84,   720,    84,    84,    84,    84,     0,
      49,     0,     0,     0,     0,     0,    51,     0,     0,     0,
       0,    51,     0,    51,     0,    51,     3,     4,     5,     6,
       7,     8,    49,     9,    49,    55,    49,     0,    10,     0,
       0,    55,     0,    55,   294,     0,    11,    55,   295,    55,
       0,    12,     0,     0,    55,   296,   297,   298,   299,   300,
     301,    49,     0,   342,     0,     0,     0,     0,     0,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,     0,   370,   374,   378,    52,   186,   187,
     188,   189,   190,   191,    56,     0,    52,    75,     0,   413,
     421,     0,    56,   197,   198,    52,    52,     0,   447,   449,
     451,   453,   455,   457,     0,     0,   466,     0,    52,     0,
     479,     3,     4,     5,     6,     7,     8,     0,     9,   334,
     509,   219,     0,    10,     0,     0,   228,   229,   230,     0,
     231,    11,     0,     0,     0,   221,    12,   232,   233,   564,
       0,     0,   222,   223,   224,   225,   226,   227,   592,     0,
      52,   186,   187,   188,   189,   190,   191,     0,   618,     0,
       0,     3,     4,     5,     6,     7,     8,     0,     9,   336,
       0,     0,    52,    10,    52,     0,    52,     0,     0,    49,
       0,    11,    75,   170,     0,     0,    12,   171,   172,   173,
       0,     0,     0,    56,    56,    56,    56,   174,    56,     0,
       0,    52,     0,     0,   175,   176,     0,     0,     0,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,     0,     0,     0,    56,   177,     0,     0,
     391,   177,    75,     0,     0,   177,     0,     0,     0,   415,
     423,    49,     0,     0,     0,     0,    49,     0,    49,     0,
      49,     0,     0,     0,     0,   460,     0,     0,     0,   473,
       0,   481,   483,     0,     0,     0,     0,    56,     0,   503,
     177,     0,     0,    56,     0,    56,     0,     0,   177,    56,
       0,    56,     0,     0,     0,     0,    56,     0,   558,     0,
       0,     3,     4,     5,     6,     7,     8,   586,     9,     0,
     117,     0,     0,    10,   177,   608,   177,     0,   177,     0,
     177,    11,   177,     0,   177,     0,    12,     0,     0,    51,
       0,     0,     0,   177,     0,     0,     0,    51,     0,    52,
     205,   206,   207,   208,   209,   210,   177,   131,   205,   206,
     207,   208,   209,   210,     0,   123,   124,     0,     2,     3,
       4,     5,     6,     7,     8,     0,     9,   215,   216,   217,
     218,    10,    75,     0,     0,     0,   177,     0,     0,    11,
       0,     0,     0,     0,    12,     0,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,     0,   143,   144,
       0,    52,     0,    62,     0,     0,    52,     0,    52,     0,
      52,    13,    14,    15,     0,     0,    16,    17,    18,    19,
      20,    21,    22,     0,    23,    24,    25,    26,    27,    28,
      29,   177,   267,   268,   269,   270,   271,   272,    51,    51,
      51,    51,     0,    51,     3,     4,     5,     6,     7,     8,
       0,     9,   803,     0,     0,     0,    10,     0,     0,   177,
       0,     0,     0,     0,    11,     0,   145,     0,   146,    12,
       0,    51,   147,   148,   149,   150,   151,   152,     0,     0,
       0,     0,     0,   157,     0,   177,     0,   160,   161,   162,
     163,   164,   165,   166,   167,     0,   168,     0,     0,     0,
     325,     0,   325,     0,   325,     0,   325,     0,     0,     0,
       0,   325,    51,   348,     0,    75,     0,     0,    51,     0,
      51,     0,     0,     0,    51,     0,    51,     0,     0,     0,
       0,    51,   296,   297,   298,   299,   300,   301,     0,     0,
       0,   325,   369,   373,   377,   381,   384,   387,   389,   396,
     398,   400,   402,   404,   406,   408,   410,   412,   420,   428,
     432,   436,   440,   444,    49,   325,   446,   448,   450,   452,
     454,   456,    49,   458,   465,   467,   469,   471,   478,   480,
     482,   484,   487,   490,   493,   496,     0,   501,   508,   510,
     512,   514,   516,   518,   520,   523,   526,   529,   532,   535,
     538,   541,   544,   547,   550,   553,   556,   563,   565,   568,
     571,   574,   577,   580,   325,   584,   591,   594,   596,   598,
     600,   602,   604,   606,   613,   615,   617,   619,   621,     0,
       0,     0,     0,     0,     0,   325,     0,     0,     0,     0,
     325,   325,     3,     4,     5,     6,     7,     8,     0,     9,
     341,     0,     0,     0,    10,   309,   310,   311,   312,   313,
       0,     0,    11,     0,     0,     0,   262,    12,   264,     0,
     265,   266,     0,    49,    49,    49,    49,     0,    49,     3,
       4,     5,     6,     7,     8,     0,     9,   831,     0,     0,
       0,    10,   309,   310,   311,   312,   313,     0,     0,    11,
       0,     0,     0,   262,    12,     0,    49,   265,   266,     0,
       0,     0,     0,    75,    52,     0,     3,     4,     5,     6,
       7,     8,    52,     9,   833,     0,     0,     0,    10,   257,
     258,   259,   260,   261,   191,     0,    11,   325,     0,     0,
       0,    12,     0,     0,   265,   266,     0,    49,     0,     0,
      75,     0,     0,    49,     0,    49,     0,     0,     0,    49,
       0,    49,     0,     0,     0,     0,    49,     0,     3,     4,
       5,     6,     7,     8,     0,     9,   849,     0,     0,    69,
      10,    81,    85,    91,     0,     0,     0,    75,    11,     0,
       0,     0,     0,    12,     3,     4,     5,     6,    60,     8,
       0,     9,     0,     0,     0,     0,    10,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,     0,     0,    12,
       0,     0,     0,    52,    52,    52,    52,     0,    52,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,    75,
       9,     0,     0,     0,     0,    10,     0,     0,     0,   255,
      81,     0,     0,    11,   273,     0,    52,     0,    12,     0,
     307,   308,     0,     0,     0,    61,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   327,     0,   327,     0,
     327,     0,   327,     0,     0,     0,     0,   327,     0,   349,
       3,     4,     5,     6,     7,    83,     0,    52,     0,     0,
       0,     0,    79,    52,    75,    52,     0,     0,     0,    52,
      11,    52,     0,     0,     0,    12,    52,   327,   371,   375,
     379,   382,   385,   349,   392,   349,   349,   349,   403,   405,
     407,   409,   411,   416,   424,   429,   433,   437,   441,   349,
       0,   327,   349,   349,   349,   349,   349,   349,     0,   461,
     349,   349,   349,   474,   349,   349,   349,   485,   488,   491,
     494,   497,   499,   504,   349,   511,   513,   515,   517,   519,
     521,   524,   527,   530,   533,   536,   539,   542,   545,   548,
     551,   554,   559,   349,   566,   569,   572,   575,   578,   581,
     327,   587,   349,   349,   349,   349,   349,   349,   349,   609,
     349,   349,   349,   349,   349,   186,   187,   188,   189,   190,
     191,   327,     0,     0,     0,     0,   327,   327,     0,     0,
     197,   198,   199,   200,   201,   202,   203,   204,   638,   640,
     642,   644,   646,   648,   649,   650,   651,   652,   653,   655,
     657,   659,   661,   663,     0,     0,     0,     0,   666,     0,
       0,   674,   678,   680,   682,   684,   686,   688,   691,   695,
     697,   699,   701,   703,   705,   708,    85,    85,    85,    85,
      85,    85,    85,   721,    85,    85,    85,    85,     0,     0,
     729,   730,   731,   732,   733,    76,     0,     0,     0,     0,
       0,     0,   248,     0,     0,   103,     0,   205,   206,   207,
     208,   209,   210,   211,     0,     0,     0,   212,     0,     0,
       0,     0,     0,   327,   213,   214,   215,   216,   217,   218,
       0,     1,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,     0,     0,    10,   325,     0,
       0,     0,     0,     0,     0,    11,   247,     0,     0,    76,
      12,   309,   310,   311,   312,   313,   325,     0,     0,   325,
       0,     0,   262,   263,   264,     0,   265,   266,   325,     0,
       0,   316,     0,   318,     0,     0,   325,    13,    14,    15,
       0,     0,    16,    17,    18,    19,    20,    21,    22,     0,
      23,    24,    25,    26,    27,    28,    29,     0,     0,     0,
       0,   325,     0,   325,     0,     0,     0,     0,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   367,   124,     0,     2,     3,     4,     5,     6,     7,
       8,   325,     9,     0,     0,   740,     0,    10,     0,     0,
       0,     0,     0,     0,     0,    11,     0,     0,     0,     0,
      12,     0,   124,     0,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,   788,     0,    10,     0,     0,
       0,     0,     0,     0,     0,    11,     0,    13,    14,    15,
      12,     0,    16,    17,    18,    19,    20,    21,    22,     0,
      23,    24,    25,    26,    27,    28,    29,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,    14,    15,
       0,     0,    16,    17,    18,    19,    20,    21,    22,     0,
      23,    24,    25,    26,    27,    28,    29,     0,    76,     0,
       0,     0,     0,     0,    98,     3,     4,     5,     6,     7,
       8,     0,     9,     0,    99,     0,     0,    10,     0,     0,
       0,     0,     0,     0,     0,    11,     0,     0,     0,     0,
      12,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     8,     0,     9,     0,     0,   320,     0,    10,     0,
       0,     0,     0,     0,     0,     0,    11,    13,    14,    15,
     734,    12,    16,    17,    18,    19,    20,    21,    22,   742,
      23,    24,    25,    26,    27,    28,    29,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,    14,
      15,     0,     0,    16,    17,    18,    19,    20,    21,    22,
       0,    23,    24,    25,    26,    27,    28,    29,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,     0,
       0,    10,     0,     0,     0,     0,     0,     0,     0,    11,
     145,   242,   146,     0,    12,     0,   147,   148,   149,   150,
     151,   152,   153,   154,   155,     0,   156,   157,   158,   159,
       0,   160,   161,   162,   163,   164,   165,   166,   167,     0,
     168,    13,    14,    15,     0,     0,    16,    17,    18,    19,
      20,    21,    22,     0,    23,    24,    25,    26,    27,    28,
      29,     0,     0,     0,   327,   145,     0,   146,     0,     0,
       0,   147,   148,   149,   150,   151,   152,     0,     0,     0,
       0,     0,   327,     0,     0,   327,   160,   161,   162,   163,
     164,   165,   166,   167,   327,   168,     0,     0,   145,     0,
     146,     0,   327,     0,   147,   148,   149,   150,   151,   152,
     153,   154,   155,     0,   156,   157,   158,   159,     0,   160,
     161,   162,   163,   164,   165,   166,   167,   327,   168,   327,
       0,     0,     0,     0,     0,     0,     0,   145,     0,   146,
       0,     0,     0,   147,   148,   149,   150,   151,   152,     0,
     154,   155,     0,   156,   157,   158,   159,   327,   160,   161,
     162,   163,   164,   165,   166,   167,   145,   168,   146,     0,
       0,     0,   147,   148,   149,   150,   151,   152,     0,   154,
       0,     0,   156,   157,   158,   159,     0,   160,   161,   162,
     163,   164,   165,   166,   167,   145,   168,   146,     0,     0,
       0,   147,   148,   149,   150,   151,   152,     0,     0,     0,
       0,   156,   157,   158,   159,     0,   160,   161,   162,   163,
     164,   165,   166,   167,   145,   168,   146,     0,     0,     0,
     147,   148,   149,   150,   151,   152,     0,     0,     0,     0,
       0,   157,   158,   159,     0,   160,   161,   162,   163,   164,
     165,   166,   167,   776,   168,     0,   145,     0,   146,     0,
       0,    76,   147,   148,   149,   150,   151,   152,     0,     0,
       0,     0,     0,   157,     0,   159,     0,   160,   161,   162,
     163,   164,   165,   166,   167,   247,   168,     0,     0,     0,
     186,   187,   188,   189,   190,   191,   192,     0,     0,     0,
     193,   194,   195,   196,     0,   197,   198,   199,   200,   201,
     202,   203,   204,   247,     0,     0,     0,     0,   257,   258,
     259,   260,   261,   191,   280,     0,     0,     0,     0,   262,
     263,   264,     0,   265,   266,   281,   282,   283,   284,   285,
     286,     0,     0,     0,     0,     0,   248,     0,     0,     0,
       0,   267,   268,   269,   270,   271,   272,   287,     0,     0,
       0,     0,     0,   786,     0,     0,     0,   790,   288,   289,
     290,   291,   292,   293,     3,     4,     5,     6,    60,    83,
       0,     0,     0,     0,     0,     0,    79,     0,     0,     0,
       0,     0,     0,     0,    11,   811,     0,     0,     0,    12,
     186,   187,   188,   189,   190,   191,   192,     0,     0,     0,
     193,   194,   195,   196,     0,   197,   198,   199,   200,   201,
     202,   203,   204,     0,     0,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   837,   143,   144,     0,
       0,   257,   258,   259,   260,   261,   191,   280,   842,     0,
     843,     0,   262,   263,   264,   846,   265,   266,   281,   282,
     283,   284,   285,   286,   186,   187,   188,   189,   190,   191,
       0,     0,     0,     0,   193,   194,   195,   196,     0,   197,
     198,   199,   200,   201,   202,   203,   204,   257,   258,   259,
     260,   261,   191,     0,     0,     0,     0,     0,   262,   263,
     264,     0,   265,   266,   281,   282,   283,   284,   285,   286,
     186,   187,   188,   189,   190,   191,     0,     0,     0,     0,
       0,   194,     0,   196,     0,   197,   198,   199,   200,   201,
     202,   203,   204,   186,   187,   188,   189,   190,   191,     0,
       0,     0,     0,     0,   194,     0,     0,     0,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,     0,     0,     0,   212,     0,     0,     0,
       0,     0,     0,   213,   214,   215,   216,   217,   218,   267,
     268,   269,   270,   271,   272,   287,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   288,   289,   290,   291,
     292,   293,   205,   206,   207,   208,   209,   210,     0,     0,
       0,     0,   212,   267,   268,   269,   270,   271,   272,   213,
     214,   215,   216,   217,   218,     0,     0,     0,     0,     0,
     288,   289,   290,   291,   292,   293,   247,     0,     0,     0,
       0,   257,   258,   259,   260,   261,   191,     0,     0,     0,
       0,     0,   262,   263,   264,     0,   265,   266,   257,   258,
     259,   260,   261,   191,     0,     0,     0,     0,     0,   262,
     263,   264,     0,   265,   266
  };

  const short
   Parser ::yycheck_[] =
  {
       0,    61,    73,    99,    18,   736,    11,   738,     8,     9,
      10,    11,   339,   236,     9,    11,     9,    11,    18,    19,
      31,    17,   105,     9,   107,     9,   109,     9,   111,   748,
     749,    31,     3,     4,     5,     6,     7,     8,     9,    11,
      11,    12,    12,   756,     9,    16,     3,     4,     5,     6,
       7,     8,     9,    24,    11,    11,     4,     5,    29,    16,
      10,     9,    75,    68,    10,   778,    11,    24,    16,     3,
      40,    41,    29,    73,    68,    40,    12,   796,    78,    79,
      75,    29,    75,    83,    75,   816,   799,   818,     9,    75,
      14,    75,     9,    75,    40,    95,    68,    97,     9,    99,
      11,   814,    12,     3,    75,    41,     8,     9,    42,    20,
       9,     8,    68,   124,    14,    39,   339,   340,    75,    69,
      70,    71,    72,    68,   124,    75,    12,    75,    39,    10,
      10,    41,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,    21,   147,   148,   149,
     150,   151,   152,   153,    12,    41,    56,    32,    33,    40,
      40,    75,   162,   163,   164,   165,   166,   167,    12,    69,
      70,    71,    72,     3,    22,    75,     0,    25,   178,    32,
      33,   252,   182,    41,    32,    33,   186,   187,   188,   189,
     190,   191,   192,    11,     3,    13,    38,    41,    40,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,    75,   213,   214,   215,   216,   217,   218,   116,
     220,    39,     4,   319,     3,    21,    56,     9,   228,    25,
      17,    18,    19,    12,    16,     0,    32,    33,    75,    69,
      70,    71,    72,     8,     9,    75,    11,    29,     3,   146,
       4,     5,   252,    18,    19,     9,     3,   257,   258,   259,
     260,   261,    16,     3,     3,    12,    31,   267,   268,   269,
     270,   271,   272,   170,    13,    29,     9,   277,    11,     3,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,    11,    73,     3,
     321,    15,    16,    17,   314,    21,    22,    23,    83,   319,
      68,   321,   219,   323,    10,    68,    32,    33,    11,    10,
      95,    10,    97,    10,    99,     4,     5,     6,     7,     8,
       9,    10,    11,   240,    32,    33,    22,    16,   245,   246,
      10,    34,    35,    36,    37,    24,    32,    33,    25,   124,
      29,    75,    11,    13,    13,    32,    33,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,    10,    40,    69,    70,    71,    72,    42,   153,    75,
      39,   156,    21,    22,    23,    40,    25,   162,   163,   164,
     165,   166,   167,    32,    33,   628,    75,    42,     3,    69,
      70,    71,    72,   178,    62,    75,    25,   182,    13,    68,
       9,   748,   749,    32,    33,     9,    75,   192,     4,     5,
       6,     7,     8,     9,    12,    11,    12,    10,    75,    10,
      16,     9,    41,    11,    10,   342,   211,     9,    24,    17,
      18,    19,    20,    29,    40,   220,   221,   222,   223,   224,
     225,   226,   227,   228,    21,    41,    12,    12,    25,   796,
      12,    39,     9,    12,    11,    32,    33,     0,    15,    16,
      17,    18,    19,    20,    25,     8,     9,   252,    11,    13,
      75,    32,    33,    30,    31,    18,    19,    12,    14,    75,
      22,    23,    39,    25,    11,    10,    20,    20,    31,    11,
      32,    33,   277,    22,    23,   280,    21,    22,    23,    20,
      12,    11,   287,    32,    33,   748,   749,    32,    33,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    32,    33,    34,    35,    36,    37,    10,   314,
      73,    10,   775,    38,   319,    12,   321,     8,   323,     3,
      83,    14,     3,    75,   635,    40,    42,   627,    17,    18,
      19,    20,    95,   796,    97,    10,    99,   800,   801,    60,
       4,     5,     6,     7,     8,     9,    25,    11,    12,     3,
      10,    14,    16,    32,    33,    34,    35,    36,    37,    42,
      24,   124,    11,    10,    42,    29,    15,    16,    17,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    32,    33,    42,    12,   627,    12,    12,
     153,   154,   155,    12,    40,   635,    39,    59,   628,   162,
     163,   801,     4,     5,     6,     7,     8,     9,   132,    11,
      12,    75,     8,     8,    16,   178,   851,   775,    -1,   182,
     743,    -1,    24,    17,    18,    19,    20,    29,    -1,   192,
      -1,    -1,    -1,     4,     5,     6,     7,     8,     9,    41,
      11,    12,    -1,    -1,    -1,    16,    -1,    -1,   211,    69,
      70,    71,    72,    24,    11,    75,    -1,   220,    29,    15,
      16,    17,    18,    19,    21,   228,   229,   230,    25,   232,
     233,    -1,     0,    75,    -1,    32,    33,    34,    35,    36,
      37,     9,   736,    11,   738,    -1,    -1,    -1,   739,   252,
      18,    19,    17,    18,    19,    20,   736,   737,   738,   739,
       9,   741,    11,    31,    75,    -1,    15,    16,    17,    18,
      19,    20,    -1,    -1,   277,    -1,    -1,   280,    -1,    -1,
      -1,    30,    31,    -1,   287,    34,    35,    36,    37,   769,
      39,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,    -1,    73,    17,    18,    19,    20,
      -1,   314,    -1,    -1,    -1,    83,   319,    -1,   321,    -1,
     323,    -1,   816,    -1,   818,    -1,    -1,    95,    -1,    97,
     810,    99,    34,    35,    36,    37,   816,    -1,   818,    -1,
      -1,    -1,   822,    -1,   824,    -1,    -1,    -1,    -1,   829,
      -1,     9,    -1,    11,    -1,    -1,   124,    15,    16,    17,
      18,    19,    20,    -1,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,    -1,    -1,
      -1,    39,   627,    -1,   761,   153,    -1,   764,    -1,    -1,
     635,    -1,    -1,    10,   162,   163,    10,    11,    15,    16,
      17,    18,    19,    20,   781,    -1,    -1,    21,    -1,    -1,
     178,    25,   180,   181,   182,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37,   192,    -1,    29,    -1,    -1,   806,
      -1,   808,    15,    16,    17,    18,    19,     4,     5,     6,
       7,     8,     9,   211,    11,    12,    49,    30,    31,    16,
      -1,    -1,   220,    -1,    -1,    10,    -1,    24,    61,   836,
     228,    64,    29,    -1,    -1,    -1,    21,     0,    -1,    -1,
      25,    -1,    75,    -1,    41,    -1,     9,    32,    33,    34,
      35,    36,    37,    -1,   252,    18,    19,    -1,    -1,    -1,
      -1,   736,   737,   738,   739,    -1,   741,    -1,    31,    -1,
      -1,    15,    16,    17,    18,    19,    20,    -1,    75,   277,
     278,   279,   280,    -1,    -1,    -1,    30,    31,    -1,   287,
      34,    35,    36,    37,   769,    -1,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,    -1,
      73,    -1,    -1,    -1,    -1,    -1,   314,    -1,    -1,    -1,
      -1,   319,    -1,   321,    -1,   323,     4,     5,     6,     7,
       8,     9,    95,    11,    97,   810,    99,    -1,    16,    -1,
      -1,   816,    -1,   818,    21,    -1,    24,   822,    25,   824,
      -1,    29,    -1,    -1,   829,    32,    33,    34,    35,    36,
      37,   124,    -1,    41,    -1,    -1,    -1,    -1,    -1,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    -1,   147,   148,   149,     0,    15,    16,
      17,    18,    19,    20,   627,    -1,     9,    75,    -1,   162,
     163,    -1,   635,    30,    31,    18,    19,    -1,   171,   172,
     173,   174,   175,   176,    -1,    -1,   179,    -1,    31,    -1,
     183,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
     193,    11,    -1,    16,    -1,    -1,    21,    22,    23,    -1,
      25,    24,    -1,    -1,    -1,    25,    29,    32,    33,   212,
      -1,    -1,    32,    33,    34,    35,    36,    37,   221,    -1,
      73,    15,    16,    17,    18,    19,    20,    -1,   231,    -1,
      -1,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      -1,    -1,    95,    16,    97,    -1,    99,    -1,    -1,   252,
      -1,    24,    75,    11,    -1,    -1,    29,    15,    16,    17,
      -1,    -1,    -1,   736,   737,   738,   739,    25,   741,    -1,
      -1,   124,    -1,    -1,    32,    33,    -1,    -1,    -1,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    -1,    -1,    -1,   769,   370,    -1,    -1,
     153,   374,    75,    -1,    -1,   378,    -1,    -1,    -1,   162,
     163,   314,    -1,    -1,    -1,    -1,   319,    -1,   321,    -1,
     323,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,   182,
      -1,   184,   185,    -1,    -1,    -1,    -1,   810,    -1,   192,
     413,    -1,    -1,   816,    -1,   818,    -1,    -1,   421,   822,
      -1,   824,    -1,    -1,    -1,    -1,   829,    -1,   211,    -1,
      -1,     4,     5,     6,     7,     8,     9,   220,    11,    -1,
      13,    -1,    -1,    16,   447,   228,   449,    -1,   451,    -1,
     453,    24,   455,    -1,   457,    -1,    29,    -1,    -1,   627,
      -1,    -1,    -1,   466,    -1,    -1,    -1,   635,    -1,   252,
      15,    16,    17,    18,    19,    20,   479,     3,    15,    16,
      17,    18,    19,    20,    -1,     0,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    34,    35,    36,
      37,    16,    75,    -1,    -1,    -1,   509,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    29,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    55,
      -1,   314,    -1,     8,    -1,    -1,   319,    -1,   321,    -1,
     323,    56,    57,    58,    -1,    -1,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,   564,    15,    16,    17,    18,    19,    20,   736,   737,
     738,   739,    -1,   741,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,   592,
      -1,    -1,    -1,    -1,    24,    -1,     9,    -1,    11,    29,
      -1,   769,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    26,    -1,   618,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    39,    -1,    -1,    -1,
     105,    -1,   107,    -1,   109,    -1,   111,    -1,    -1,    -1,
      -1,   116,   810,   118,    -1,    75,    -1,    -1,   816,    -1,
     818,    -1,    -1,    -1,   822,    -1,   824,    -1,    -1,    -1,
      -1,   829,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   627,   170,   171,   172,   173,   174,
     175,   176,   635,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,
     245,   246,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    -1,    -1,    16,    15,    16,    17,    18,    19,
      -1,    -1,    24,    -1,    -1,    -1,    26,    29,    28,    -1,
      30,    31,    -1,   736,   737,   738,   739,    -1,   741,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    -1,    -1,
      -1,    16,    15,    16,    17,    18,    19,    -1,    -1,    24,
      -1,    -1,    -1,    26,    29,    -1,   769,    30,    31,    -1,
      -1,    -1,    -1,    75,   627,    -1,     4,     5,     6,     7,
       8,     9,   635,    11,    12,    -1,    -1,    -1,    16,    15,
      16,    17,    18,    19,    20,    -1,    24,   342,    -1,    -1,
      -1,    29,    -1,    -1,    30,    31,    -1,   810,    -1,    -1,
      75,    -1,    -1,   816,    -1,   818,    -1,    -1,    -1,   822,
      -1,   824,    -1,    -1,    -1,    -1,   829,    -1,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,     8,
      16,    10,    11,    12,    -1,    -1,    -1,    75,    24,    -1,
      -1,    -1,    -1,    29,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,   736,   737,   738,   739,    -1,   741,    -1,
      -1,    -1,    -1,     4,     5,     6,     7,     8,     9,    75,
      11,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,    78,
      79,    -1,    -1,    24,    83,    -1,   769,    -1,    29,    -1,
      89,    90,    -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,   107,    -1,
     109,    -1,   111,    -1,    -1,    -1,    -1,   116,    -1,   118,
       4,     5,     6,     7,     8,     9,    -1,   810,    -1,    -1,
      -1,    -1,    16,   816,    75,   818,    -1,    -1,    -1,   822,
      24,   824,    -1,    -1,    -1,    29,   829,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,   170,   171,   172,   173,   174,   175,   176,    -1,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    15,    16,    17,    18,    19,
      20,   240,    -1,    -1,    -1,    -1,   245,   246,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,    -1,    -1,    -1,    -1,   277,    -1,
      -1,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,    -1,    -1,
     309,   310,   311,   312,   313,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    10,    -1,    -1,    19,    -1,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    -1,   342,    32,    33,    34,    35,    36,    37,
      -1,     0,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    -1,    -1,    -1,    -1,    16,   743,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    10,    -1,    -1,    73,
      29,    15,    16,    17,    18,    19,   761,    -1,    -1,   764,
      -1,    -1,    26,    27,    28,    -1,    30,    31,   773,    -1,
      -1,    95,    -1,    97,    -1,    -1,   781,    56,    57,    58,
      -1,    -1,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,   806,    -1,   808,    -1,    -1,    -1,    -1,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,   836,    11,    -1,    -1,    14,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      29,    -1,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    -1,    -1,    14,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    56,    57,    58,
      29,    -1,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      -1,    -1,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    -1,   252,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    -1,    13,    -1,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    -1,    -1,    14,    -1,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    56,    57,    58,
     314,    29,    61,    62,    63,    64,    65,    66,    67,   323,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    -1,    -1,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    -1,    -1,    -1,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
       9,    10,    11,    -1,    29,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    25,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      39,    56,    57,    58,    -1,    -1,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    -1,    -1,    -1,   743,     9,    -1,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,   761,    -1,    -1,   764,    30,    31,    32,    33,
      34,    35,    36,    37,   773,    39,    -1,    -1,     9,    -1,
      11,    -1,   781,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,   806,    39,   808,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    -1,
      22,    23,    -1,    25,    26,    27,    28,   836,    30,    31,
      32,    33,    34,    35,    36,    37,     9,    39,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    -1,    22,
      -1,    -1,    25,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,     9,    39,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    25,    26,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,     9,    39,    11,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,   627,    39,    -1,     9,    -1,    11,    -1,
      -1,   635,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    10,    39,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      25,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    10,    -1,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,   737,    -1,    -1,    -1,   741,    32,    33,
      34,    35,    36,    37,     4,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,   769,    -1,    -1,    -1,    29,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      25,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,   810,    54,    55,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,   822,    -1,
     824,    -1,    26,    27,    28,   829,    30,    31,    32,    33,
      34,    35,    36,    37,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    25,    26,    27,    28,    -1,    30,
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
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    37,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    25,    15,    16,    17,    18,    19,    20,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    37,    10,    -1,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    -1,    30,    31,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    -1,    30,    31
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,     0,     3,     4,     5,     6,     7,     8,     9,    11,
      16,    24,    29,    56,    57,    58,    61,    62,    63,    64,
      65,    66,    67,    69,    70,    71,    72,    73,    74,    75,
      78,    79,    80,    81,    84,    86,    87,    88,    89,    90,
      91,    93,    96,   100,   101,   102,   104,   105,   106,   108,
     109,   112,   113,   116,   117,   118,   119,   120,   122,   124,
       8,    75,   105,   106,   108,   109,   110,   112,   113,   116,
     117,   118,   119,     3,    12,    75,   104,   107,     9,    16,
      75,   116,   117,     9,   112,   116,   117,   118,   119,     9,
      16,   116,    75,    75,    85,     9,     9,     9,     3,    13,
      81,    82,    83,   104,    75,    11,    68,    11,    68,    11,
      68,    11,    68,    75,    75,    97,    11,    13,    39,    68,
     111,   114,     0,     0,     1,    80,     3,     3,     3,     3,
       3,     3,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    54,    55,     9,    11,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    25,    26,    27,    28,
      30,    31,    32,    33,    34,    35,    36,    37,    39,   111,
      11,    15,    16,    17,    25,    32,    33,   111,    21,    25,
      32,    33,    21,    25,    32,    33,    15,    16,    17,    18,
      19,    20,    21,    25,    26,    27,    28,    30,    31,    32,
      33,    34,    35,    36,    37,    15,    16,    17,    18,    19,
      20,    21,    25,    32,    33,    34,    35,    36,    37,    11,
      21,    25,    32,    33,    34,    35,    36,    37,    21,    22,
      23,    25,    32,    33,    68,    68,     9,    75,    97,    10,
      11,   114,    10,    10,    10,    38,    40,    10,    10,    10,
      10,   107,    40,     3,    12,   116,   117,    15,    16,    17,
      18,    19,    26,    27,    28,    30,    31,    15,    16,    17,
      18,    19,    20,   116,   117,   118,   119,    21,    32,    33,
      21,    32,    33,    34,    35,    36,    37,    21,    32,    33,
      34,    35,    36,    37,    21,    25,    32,    33,    34,    35,
      36,    37,    21,    22,    23,    32,    33,   116,   116,    15,
      16,    17,    18,    19,    42,    40,   104,    75,   104,    13,
      14,    79,    62,    42,    12,   105,   110,   116,   117,   118,
     119,   123,    12,   123,    12,   123,    12,   123,     3,    13,
       9,    12,    41,   110,   123,    14,    39,   115,   105,   116,
      80,   102,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,    10,   103,   104,   110,   105,
     108,   116,   117,   105,   108,   116,   117,   105,   108,   116,
     117,   105,   116,   117,   105,   116,   117,   105,   117,   105,
     112,   113,   116,   117,   118,   119,   105,   119,   105,   119,
     105,   118,   105,   116,   105,   116,   105,   116,   105,   116,
     105,   116,   105,   108,   112,   113,   116,   117,   118,   119,
     105,   108,   112,   113,   116,   117,   118,   119,   105,   116,
     117,   118,   105,   116,   117,   118,   105,   116,   117,   118,
     105,   116,   117,   118,   105,   110,   105,   108,   105,   108,
     105,   108,   105,   108,   105,   108,   105,   108,   105,   112,
     113,   116,   117,   118,   119,   105,   108,   105,   112,   105,
     112,   105,   112,   113,   116,   117,   118,   119,   105,   108,
     105,   113,   105,   113,   105,   116,   117,   105,   116,   117,
     105,   116,   117,   105,   116,   117,   105,   116,   117,   116,
     117,   105,   112,   113,   116,   117,   118,   119,   105,   108,
     105,   116,   105,   116,   105,   116,   105,   116,   105,   116,
     105,   116,   117,   105,   116,   117,   105,   116,   117,   105,
     116,   117,   105,   116,   117,   105,   116,   117,   105,   116,
     117,   105,   116,   117,   105,   116,   117,   105,   116,   117,
     105,   116,   117,   105,   116,   117,   105,   112,   113,   116,
     117,   118,   119,   105,   108,   105,   116,   117,   105,   116,
     117,   105,   116,   117,   105,   116,   117,   105,   116,   117,
     105,   116,   117,   110,   105,   112,   113,   116,   117,   118,
     119,   105,   108,   118,   105,   118,   105,   118,   105,   118,
     105,   118,   105,   118,   105,   118,   105,   112,   113,   116,
     117,   118,   119,   105,   119,   105,   119,   105,   108,   105,
     119,   105,   119,    10,    75,   121,   124,    42,     9,   110,
      10,   110,   110,     3,    12,     3,   107,    12,   116,   117,
     116,   117,   116,   117,   116,   117,   116,   117,   116,   116,
     116,   116,   116,   116,   117,   116,   117,   116,   117,   116,
     117,   116,   117,   116,   117,   112,   116,   117,   118,   119,
       9,   112,   112,   112,   116,   117,   118,   119,   116,   117,
     116,   117,   116,   117,   116,   117,   116,   117,   116,   117,
     112,   116,   117,   118,   119,   116,   117,   116,   117,   116,
     117,   116,   117,   116,   117,   116,   117,   112,   116,   117,
     118,   119,   118,   119,   118,   118,   118,   118,   118,   118,
     112,   116,   117,   118,   119,   119,   119,   119,   119,   116,
     116,   116,   116,   116,   104,    75,    10,    41,    10,    79,
      14,     9,   104,    40,    12,    12,    12,    12,    13,     3,
      14,    56,    94,    95,   100,   124,    10,    98,    99,   124,
      12,    41,   110,    12,    41,    12,    75,    14,    10,    40,
      12,    12,    12,    11,    10,    40,   104,   114,    10,    98,
      10,    38,    12,   107,     8,    83,   104,    83,    14,     3,
     104,   123,    94,    94,    75,    14,     3,    75,    82,    10,
      40,    40,    75,    12,   110,    12,    41,    12,    41,   110,
      42,   104,   121,    82,    10,   110,    60,    92,    10,     3,
      10,    14,    42,    94,    42,    82,   124,    99,   124,    42,
      12,    12,   110,    12,   110,    12,    41,   104,    82,    10,
      83,    83,   104,   104,    75,    75,   104,    12,    12,    12,
     110,    40,    12,   115
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    77,    78,    78,    79,    79,    79,    80,    80,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    82,    82,    82,    82,    82,    83,    83,    84,    85,
      85,    86,    86,    86,    87,    87,    88,    89,    90,    91,
      92,    92,    93,    93,    93,    94,    94,    94,    94,    95,
      95,    95,    96,    96,    96,    96,    97,    98,    98,    98,
      99,    99,   100,   101,   101,   101,   101,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   103,   103,   104,   104,   104,   104,   104,   104,   104,
     104,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   106,   106,   106,   106,   106,
     107,   107,   107,   108,   108,   108,   108,   109,   109,   110,
     110,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   112,   112,   113,   113,   114,   114,   115,
     115,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   120,   120,   121,   121,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   123,   123,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124
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
       1,     1,     2,     3,     3,     4,     4,     4,     4,     4,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
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
       3,     3,     3,     3,     3,     2,     3,     4,     4,     5,
       1,     3,     4,     1,     1,     3,     3,     5,     7,     1,
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
       3,     3,     3,     4,     3,     1,     3,     4,     3,     4,
       3,     4,     3,     4,     3,     4,     3,     1,     3,     2,
       2,     2,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1
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
  "\"identifier\"", "NEG", "$accept", "start", "stmt", "stmts", "stmts_ne",
  "block", "body", "import", "id_list", "flowctl", "return", "for",
  "while", "dowhile", "if", "else", "struct", "decllist", "declistval",
  "function", "fun_id", "funargs", "funargdef", "vardecl", "vardef", "set",
  "callarglist", "expr", "expr_var", "matrix", "matvals", "expr_mat",
  "range", "int_val", "slice", "expr_none", "expr_struct", "struct_val",
  "struct_list", "expr_int", "expr_float", "expr_str", "expr_bool",
  "funtype", "typelist", "mattype", "matsize", "type", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   209,   209,   210,   212,   213,   214,   218,   219,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   236,   237,   238,   239,   240,   243,   244,   248,   250,
     251,   255,   256,   257,   259,   260,   264,   268,   271,   275,
     281,   282,   286,   287,   288,   290,   291,   292,   293,   295,
     296,   297,   301,   302,   303,   304,   306,   308,   309,   310,
     312,   313,   317,   321,   322,   323,   324,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   345,   346,   350,   351,   352,   353,   354,   355,   356,
     357,   360,   361,   362,   364,   365,   367,   368,   369,   370,
     372,   373,   374,   376,   377,   379,   380,   381,   383,   384,
     385,   386,   387,   388,   389,   390,   392,   393,   394,   395,
     396,   398,   399,   400,   401,   402,   404,   405,   406,   407,
     408,   409,   410,   411,   413,   414,   415,   416,   417,   418,
     419,   420,   422,   423,   424,   426,   427,   428,   430,   431,
     432,   433,   434,   435,   436,   438,   439,   440,   441,   442,
     443,   444,   446,   447,   448,   449,   450,   451,   452,   454,
     455,   456,   457,   458,   459,   460,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     498,   499,   500,   502,   503,   504,   506,   507,   508,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   527,   528,   529,   531,   532,
     533,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   562,   563,   564,   565,   566,
     568,   569,   570,   574,   575,   576,   577,   579,   580,   582,
     583,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   600,   601,   605,   606,   608,   609,   611,
     612,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   633,   634,   635,   636,   637,
     638,   639,   640,   641,   642,   643,   644,   645,   646,   647,
     648,   649,   650,   651,   652,   653,   657,   658,   659,   660,
     661,   662,   663,   664,   665,   666,   667,   668,   669,   670,
     671,   672,   673,   674,   675,   676,   677,   678,   679,   680,
     681,   682,   683,   687,   688,   689,   690,   691,   693,   694,
     695,   696,   697,   698,   699,   701,   702,   703,   704,   705,
     706,   707,   709,   710,   711,   712,   713,   715,   716,   717,
     718,   719,   721,   722,   723,   724,   725,   727,   728,   729,
     730,   731,   733,   737,   738,   740,   741,   745,   746,   747,
     748,   749,   750,   751,   752,   753,   754,   756,   757,   761,
     762,   763,   764,   765,   766,   767,   768,   769,   770,   771,
     772,   773,   774
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
#line 4130 "frontend/parser.cpp"

#line 777 "frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    auto msg = std::to_string(scanner->loc->begin.line) + ":" + std::to_string(scanner->loc->begin.column) + ": " + err_message;
    ptc::log::error(msg);
}
