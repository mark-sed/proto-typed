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
#line 43 "frontend/parser.yy"


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
#line 205 "frontend/parser.yy"
                        { scanner->parseMain(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 985 "frontend/parser.cpp"
    break;

  case 4: // stmt: stmts
#line 207 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 991 "frontend/parser.cpp"
    break;

  case 5: // stmt: stmt stmts
#line 208 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 997 "frontend/parser.cpp"
    break;

  case 6: // stmt: stmt error stmts
#line 209 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1003 "frontend/parser.cpp"
    break;

  case 7: // stmts: "terminator (\\n or ;)"
#line 213 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = nullptr; }
#line 1009 "frontend/parser.cpp"
    break;

  case 8: // stmts: stmts_ne
#line 214 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1015 "frontend/parser.cpp"
    break;

  case 9: // stmts_ne: set "terminator (\\n or ;)"
#line 216 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1021 "frontend/parser.cpp"
    break;

  case 10: // stmts_ne: vardecl "terminator (\\n or ;)"
#line 217 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1027 "frontend/parser.cpp"
    break;

  case 11: // stmts_ne: vardef "terminator (\\n or ;)"
#line 218 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1033 "frontend/parser.cpp"
    break;

  case 14: // stmts_ne: if
#line 221 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1039 "frontend/parser.cpp"
    break;

  case 18: // stmts_ne: function
#line 225 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1045 "frontend/parser.cpp"
    break;

  case 20: // stmts_ne: expr "terminator (\\n or ;)"
#line 227 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1051 "frontend/parser.cpp"
    break;

  case 21: // block: "{" "}"
#line 231 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1057 "frontend/parser.cpp"
    break;

  case 22: // block: "{" stmt "}"
#line 232 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1063 "frontend/parser.cpp"
    break;

  case 23: // block: "terminator (\\n or ;)" "{" stmt "}"
#line 233 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1069 "frontend/parser.cpp"
    break;

  case 24: // block: "{" stmt "}" "terminator (\\n or ;)"
#line 234 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1075 "frontend/parser.cpp"
    break;

  case 25: // block: "terminator (\\n or ;)" "{" stmt "}" "terminator (\\n or ;)"
#line 235 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1081 "frontend/parser.cpp"
    break;

  case 26: // body: stmts_ne
#line 238 "frontend/parser.yy"
                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1087 "frontend/parser.cpp"
    break;

  case 27: // body: block
#line 239 "frontend/parser.yy"
                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1093 "frontend/parser.cpp"
    break;

  case 39: // if: "if" "(" expr ")" body else
#line 270 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::IR * > () = scanner->parseIfStmt(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1099 "frontend/parser.cpp"
    break;

  case 40: // else: "else" body
#line 276 "frontend/parser.yy"
                    { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1105 "frontend/parser.cpp"
    break;

  case 41: // else: %empty
#line 277 "frontend/parser.yy"
                    { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1111 "frontend/parser.cpp"
    break;

  case 52: // function: type "identifier" "(" ")" block
#line 296 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::IR * > () = yystack_[4].value.as < ptc::ir::IR * > (); }
#line 1117 "frontend/parser.cpp"
    break;

  case 53: // function: type "identifier" "(" funargs ")" block
#line 297 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::IR * > () = yystack_[5].value.as < ptc::ir::IR * > (); }
#line 1123 "frontend/parser.cpp"
    break;

  case 54: // function: "\"void\"" fun_id "(" ")" block
#line 298 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::Expr *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1129 "frontend/parser.cpp"
    break;

  case 56: // fun_id: "identifier"
#line 301 "frontend/parser.yy"
            { scanner->enterFunScope(); }
#line 1135 "frontend/parser.cpp"
    break;

  case 62: // vardecl: type "identifier"
#line 312 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1141 "frontend/parser.cpp"
    break;

  case 63: // vardef: type "identifier" "=" struct_val
#line 316 "frontend/parser.yy"
         { yylhs.value.as < ptc::ir::IR * > () = yystack_[3].value.as < ptc::ir::IR * > (); }
#line 1147 "frontend/parser.cpp"
    break;

  case 64: // vardef: type "identifier" "=" expr
#line 317 "frontend/parser.yy"
                                 { scanner->parseVarDef(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1153 "frontend/parser.cpp"
    break;

  case 67: // set: expr "++=" expr
#line 323 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1159 "frontend/parser.cpp"
    break;

  case 68: // set: expr "**=" expr
#line 324 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1165 "frontend/parser.cpp"
    break;

  case 69: // set: expr "%=" expr
#line 325 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1171 "frontend/parser.cpp"
    break;

  case 70: // set: expr "/=" expr
#line 326 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1177 "frontend/parser.cpp"
    break;

  case 71: // set: expr "*=" expr
#line 327 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1183 "frontend/parser.cpp"
    break;

  case 72: // set: expr "-=" expr
#line 328 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1189 "frontend/parser.cpp"
    break;

  case 73: // set: expr "+=" expr
#line 329 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1195 "frontend/parser.cpp"
    break;

  case 74: // set: expr "&=" expr
#line 330 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1201 "frontend/parser.cpp"
    break;

  case 75: // set: expr "|=" expr
#line 331 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1207 "frontend/parser.cpp"
    break;

  case 76: // set: expr "^=" expr
#line 332 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1213 "frontend/parser.cpp"
    break;

  case 77: // set: expr "<<=" expr
#line 333 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1219 "frontend/parser.cpp"
    break;

  case 78: // set: expr ">>=" expr
#line 334 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1225 "frontend/parser.cpp"
    break;

  case 79: // set: expr "=" expr
#line 335 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1231 "frontend/parser.cpp"
    break;

  case 80: // set: expr "=" set
#line 336 "frontend/parser.yy"
      { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1237 "frontend/parser.cpp"
    break;

  case 81: // callarglist: expr
#line 340 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseFunCallArg(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1243 "frontend/parser.cpp"
    break;

  case 82: // callarglist: callarglist "," expr
#line 341 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddFunCallArg(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1249 "frontend/parser.cpp"
    break;

  case 83: // expr: expr_mat
#line 345 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = nullptr; }
#line 1255 "frontend/parser.cpp"
    break;

  case 84: // expr: expr_var
#line 346 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1261 "frontend/parser.cpp"
    break;

  case 85: // expr: expr_none
#line 347 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = nullptr; }
#line 1267 "frontend/parser.cpp"
    break;

  case 86: // expr: expr_struct
#line 348 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = nullptr; }
#line 1273 "frontend/parser.cpp"
    break;

  case 87: // expr: expr_int
#line 349 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 1279 "frontend/parser.cpp"
    break;

  case 88: // expr: expr_float
#line 350 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFloat(yystack_[0].value.as < double > ()); }
#line 1285 "frontend/parser.cpp"
    break;

  case 89: // expr: expr_str
#line 351 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseString(yystack_[0].value.as < std::string > ()); }
#line 1291 "frontend/parser.cpp"
    break;

  case 90: // expr: expr_bool
#line 352 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseBool(yystack_[0].value.as < bool > ()); }
#line 1297 "frontend/parser.cpp"
    break;

  case 91: // expr_var: "identifier"
#line 355 "frontend/parser.yy"
              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > ()); }
#line 1303 "frontend/parser.cpp"
    break;

  case 92: // expr_var: "-" "identifier"
#line 356 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1309 "frontend/parser.cpp"
    break;

  case 93: // expr_var: "(" expr_var ")"
#line 357 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1315 "frontend/parser.cpp"
    break;

  case 94: // expr_var: expr_var "(" ")"
#line 359 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[2].value.as < ptc::ir::Expr * > (), std::vector<ptc::ir::Expr *>{}); }
#line 1321 "frontend/parser.cpp"
    break;

  case 95: // expr_var: expr_var "(" callarglist ")"
#line 360 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 1327 "frontend/parser.cpp"
    break;

  case 99: // expr_var: expr_var "[" int_val "]"
#line 365 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[3].value.as < ptc::ir::Expr * > (); }
#line 1333 "frontend/parser.cpp"
    break;

  case 102: // expr_var: expr_var slice
#line 369 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1339 "frontend/parser.cpp"
    break;

  case 104: // expr_var: expr_var "." expr_var
#line 372 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1345 "frontend/parser.cpp"
    break;

  case 106: // expr_var: expr_var "**" expr_float
#line 375 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1351 "frontend/parser.cpp"
    break;

  case 107: // expr_var: expr_var "**" expr_var
#line 376 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1357 "frontend/parser.cpp"
    break;

  case 110: // expr_var: expr_var "*" expr_int
#line 380 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1363 "frontend/parser.cpp"
    break;

  case 111: // expr_var: expr_var "*" expr_float
#line 381 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1369 "frontend/parser.cpp"
    break;

  case 114: // expr_var: expr_var "*" expr_mat
#line 384 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1375 "frontend/parser.cpp"
    break;

  case 115: // expr_var: expr_var "*" expr_var
#line 385 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1381 "frontend/parser.cpp"
    break;

  case 118: // expr_var: expr_var "/" expr_int
#line 389 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1387 "frontend/parser.cpp"
    break;

  case 119: // expr_var: expr_var "/" expr_float
#line 390 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1393 "frontend/parser.cpp"
    break;

  case 120: // expr_var: expr_var "/" expr_var
#line 391 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1399 "frontend/parser.cpp"
    break;

  case 123: // expr_var: expr_var "%" expr_int
#line 395 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1405 "frontend/parser.cpp"
    break;

  case 124: // expr_var: expr_var "%" expr_float
#line 396 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1411 "frontend/parser.cpp"
    break;

  case 125: // expr_var: expr_var "%" expr_var
#line 397 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1417 "frontend/parser.cpp"
    break;

  case 126: // expr_var: expr_int "+" expr_var
#line 399 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1423 "frontend/parser.cpp"
    break;

  case 127: // expr_var: expr_float "+" expr_var
#line 400 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1429 "frontend/parser.cpp"
    break;

  case 128: // expr_var: expr_var "+" expr_int
#line 401 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1435 "frontend/parser.cpp"
    break;

  case 129: // expr_var: expr_var "+" expr_float
#line 402 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1441 "frontend/parser.cpp"
    break;

  case 131: // expr_var: expr_var "+" expr_mat
#line 404 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1447 "frontend/parser.cpp"
    break;

  case 133: // expr_var: expr_var "+" expr_var
#line 406 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1453 "frontend/parser.cpp"
    break;

  case 136: // expr_var: expr_var "-" expr_int
#line 410 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1459 "frontend/parser.cpp"
    break;

  case 137: // expr_var: expr_var "-" expr_float
#line 411 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1465 "frontend/parser.cpp"
    break;

  case 139: // expr_var: expr_var "-" expr_mat
#line 413 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1471 "frontend/parser.cpp"
    break;

  case 141: // expr_var: expr_var "-" expr_var
#line 415 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1477 "frontend/parser.cpp"
    break;

  case 143: // expr_var: expr_var "<<" expr_int
#line 418 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1483 "frontend/parser.cpp"
    break;

  case 144: // expr_var: expr_var "<<" expr_var
#line 419 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1489 "frontend/parser.cpp"
    break;

  case 146: // expr_var: expr_var ">>" expr_int
#line 422 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1495 "frontend/parser.cpp"
    break;

  case 147: // expr_var: expr_var ">>" expr_var
#line 423 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1501 "frontend/parser.cpp"
    break;

  case 151: // expr_var: expr_var ">" expr_int
#line 428 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1507 "frontend/parser.cpp"
    break;

  case 152: // expr_var: expr_var ">" expr_float
#line 429 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1513 "frontend/parser.cpp"
    break;

  case 153: // expr_var: expr_var ">" expr_str
#line 430 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1519 "frontend/parser.cpp"
    break;

  case 154: // expr_var: expr_var ">" expr_var
#line 431 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1525 "frontend/parser.cpp"
    break;

  case 158: // expr_var: expr_var ">=" expr_int
#line 436 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1531 "frontend/parser.cpp"
    break;

  case 159: // expr_var: expr_var ">=" expr_float
#line 437 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1537 "frontend/parser.cpp"
    break;

  case 160: // expr_var: expr_var ">=" expr_str
#line 438 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1543 "frontend/parser.cpp"
    break;

  case 161: // expr_var: expr_var ">=" expr_var
#line 439 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1549 "frontend/parser.cpp"
    break;

  case 165: // expr_var: expr_var "<" expr_int
#line 444 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1555 "frontend/parser.cpp"
    break;

  case 166: // expr_var: expr_var "<" expr_float
#line 445 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1561 "frontend/parser.cpp"
    break;

  case 167: // expr_var: expr_var "<" expr_str
#line 446 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1567 "frontend/parser.cpp"
    break;

  case 168: // expr_var: expr_var "<" expr_var
#line 447 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1573 "frontend/parser.cpp"
    break;

  case 172: // expr_var: expr_var "<=" expr_int
#line 452 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1579 "frontend/parser.cpp"
    break;

  case 173: // expr_var: expr_var "<=" expr_float
#line 453 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1585 "frontend/parser.cpp"
    break;

  case 174: // expr_var: expr_var "<=" expr_str
#line 454 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1591 "frontend/parser.cpp"
    break;

  case 175: // expr_var: expr_var "<=" expr_var
#line 455 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1597 "frontend/parser.cpp"
    break;

  case 183: // expr_var: expr_var "==" expr_int
#line 464 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1603 "frontend/parser.cpp"
    break;

  case 184: // expr_var: expr_var "==" expr_float
#line 465 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1609 "frontend/parser.cpp"
    break;

  case 185: // expr_var: expr_var "==" expr_str
#line 466 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1615 "frontend/parser.cpp"
    break;

  case 186: // expr_var: expr_var "==" expr_bool
#line 467 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1621 "frontend/parser.cpp"
    break;

  case 187: // expr_var: expr_var "==" expr_none
#line 468 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1627 "frontend/parser.cpp"
    break;

  case 188: // expr_var: expr_var "==" expr_struct
#line 469 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1633 "frontend/parser.cpp"
    break;

  case 190: // expr_var: expr_var "==" expr_mat
#line 471 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1639 "frontend/parser.cpp"
    break;

  case 192: // expr_var: expr_var "==" expr_var
#line 473 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1645 "frontend/parser.cpp"
    break;

  case 200: // expr_var: expr_var "!=" expr_int
#line 482 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1651 "frontend/parser.cpp"
    break;

  case 201: // expr_var: expr_var "!=" expr_float
#line 483 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1657 "frontend/parser.cpp"
    break;

  case 202: // expr_var: expr_var "!=" expr_str
#line 484 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1663 "frontend/parser.cpp"
    break;

  case 203: // expr_var: expr_var "!=" expr_bool
#line 485 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1669 "frontend/parser.cpp"
    break;

  case 204: // expr_var: expr_var "!=" expr_none
#line 486 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1675 "frontend/parser.cpp"
    break;

  case 205: // expr_var: expr_var "!=" expr_struct
#line 487 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1681 "frontend/parser.cpp"
    break;

  case 207: // expr_var: expr_var "!=" expr_mat
#line 489 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1687 "frontend/parser.cpp"
    break;

  case 209: // expr_var: expr_var "!=" expr_var
#line 491 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1693 "frontend/parser.cpp"
    break;

  case 211: // expr_var: expr_var "&" expr_int
#line 494 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1699 "frontend/parser.cpp"
    break;

  case 212: // expr_var: expr_var "&" expr_var
#line 495 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1705 "frontend/parser.cpp"
    break;

  case 214: // expr_var: expr_var "^" expr_int
#line 498 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1711 "frontend/parser.cpp"
    break;

  case 215: // expr_var: expr_var "^" expr_var
#line 499 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1717 "frontend/parser.cpp"
    break;

  case 217: // expr_var: expr_var "|" expr_int
#line 502 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1723 "frontend/parser.cpp"
    break;

  case 218: // expr_var: expr_var "|" expr_var
#line 503 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1729 "frontend/parser.cpp"
    break;

  case 233: // expr_var: expr_var "in" expr_str
#line 519 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1735 "frontend/parser.cpp"
    break;

  case 234: // expr_var: expr_var "in" expr_var
#line 520 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1741 "frontend/parser.cpp"
    break;

  case 236: // expr_var: expr_var "and" expr_bool
#line 523 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1747 "frontend/parser.cpp"
    break;

  case 237: // expr_var: expr_var "and" expr_var
#line 524 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1753 "frontend/parser.cpp"
    break;

  case 239: // expr_var: expr_var "or" expr_bool
#line 527 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1759 "frontend/parser.cpp"
    break;

  case 240: // expr_var: expr_var "or" expr_var
#line 528 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1765 "frontend/parser.cpp"
    break;

  case 258: // expr_var: expr_var "++" expr_int
#line 547 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1771 "frontend/parser.cpp"
    break;

  case 259: // expr_var: expr_var "++" expr_float
#line 548 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1777 "frontend/parser.cpp"
    break;

  case 260: // expr_var: expr_var "++" expr_str
#line 549 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1783 "frontend/parser.cpp"
    break;

  case 261: // expr_var: expr_var "++" expr_bool
#line 550 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1789 "frontend/parser.cpp"
    break;

  case 262: // expr_var: expr_var "++" expr_none
#line 551 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1795 "frontend/parser.cpp"
    break;

  case 263: // expr_var: expr_var "++" expr_struct
#line 552 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1801 "frontend/parser.cpp"
    break;

  case 264: // expr_var: expr_var "++" expr_var
#line 553 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1807 "frontend/parser.cpp"
    break;

  case 301: // expr_int: "int"
#line 611 "frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 1813 "frontend/parser.cpp"
    break;

  case 302: // expr_int: "-" expr_int
#line 612 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 1819 "frontend/parser.cpp"
    break;

  case 303: // expr_int: "(" expr_int ")"
#line 613 "frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 1825 "frontend/parser.cpp"
    break;

  case 304: // expr_int: "~" expr_int
#line 614 "frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 1831 "frontend/parser.cpp"
    break;

  case 305: // expr_int: expr_int "*" expr_int
#line 615 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 1837 "frontend/parser.cpp"
    break;

  case 306: // expr_int: expr_int "/" expr_int
#line 616 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 1843 "frontend/parser.cpp"
    break;

  case 307: // expr_int: expr_int "%" expr_int
#line 617 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 1849 "frontend/parser.cpp"
    break;

  case 308: // expr_int: expr_int "-" expr_int
#line 618 "frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 1855 "frontend/parser.cpp"
    break;

  case 309: // expr_int: expr_int "+" expr_int
#line 619 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 1861 "frontend/parser.cpp"
    break;

  case 310: // expr_int: expr_int "<<" expr_int
#line 620 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 1867 "frontend/parser.cpp"
    break;

  case 311: // expr_int: expr_int ">>" expr_int
#line 621 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 1873 "frontend/parser.cpp"
    break;

  case 312: // expr_int: expr_int "&" expr_int
#line 622 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 1879 "frontend/parser.cpp"
    break;

  case 313: // expr_int: expr_int "^" expr_int
#line 623 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 1885 "frontend/parser.cpp"
    break;

  case 314: // expr_int: expr_int "|" expr_int
#line 624 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 1891 "frontend/parser.cpp"
    break;

  case 315: // expr_float: "float"
#line 628 "frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 1897 "frontend/parser.cpp"
    break;

  case 316: // expr_float: "-" expr_float
#line 629 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 1903 "frontend/parser.cpp"
    break;

  case 317: // expr_float: "(" expr_float ")"
#line 630 "frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 1909 "frontend/parser.cpp"
    break;

  case 318: // expr_float: expr_float "**" expr_float
#line 631 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 1915 "frontend/parser.cpp"
    break;

  case 319: // expr_float: expr_float "**" expr_int
#line 632 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 1921 "frontend/parser.cpp"
    break;

  case 320: // expr_float: expr_int "**" expr_float
#line 633 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 1927 "frontend/parser.cpp"
    break;

  case 321: // expr_float: expr_float "*" expr_float
#line 634 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 1933 "frontend/parser.cpp"
    break;

  case 322: // expr_float: expr_float "*" expr_int
#line 635 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 1939 "frontend/parser.cpp"
    break;

  case 323: // expr_float: expr_int "*" expr_float
#line 636 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 1945 "frontend/parser.cpp"
    break;

  case 324: // expr_float: expr_float "/" expr_float
#line 637 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 1951 "frontend/parser.cpp"
    break;

  case 325: // expr_float: expr_float "/" expr_int
#line 638 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 1957 "frontend/parser.cpp"
    break;

  case 326: // expr_float: expr_int "/" expr_float
#line 639 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 1963 "frontend/parser.cpp"
    break;

  case 327: // expr_float: expr_float "%" expr_float
#line 640 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 1969 "frontend/parser.cpp"
    break;

  case 328: // expr_float: expr_float "%" expr_int
#line 641 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 1975 "frontend/parser.cpp"
    break;

  case 329: // expr_float: expr_int "%" expr_float
#line 642 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 1981 "frontend/parser.cpp"
    break;

  case 330: // expr_float: expr_float "-" expr_float
#line 643 "frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 1987 "frontend/parser.cpp"
    break;

  case 331: // expr_float: expr_float "-" expr_int
#line 644 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 1993 "frontend/parser.cpp"
    break;

  case 332: // expr_float: expr_int "-" expr_float
#line 645 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 1999 "frontend/parser.cpp"
    break;

  case 333: // expr_float: expr_float "+" expr_float
#line 646 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 2005 "frontend/parser.cpp"
    break;

  case 334: // expr_float: expr_float "+" expr_int
#line 647 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 2011 "frontend/parser.cpp"
    break;

  case 335: // expr_float: expr_int "+" expr_float
#line 648 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 2017 "frontend/parser.cpp"
    break;

  case 336: // expr_str: "string"
#line 652 "frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2023 "frontend/parser.cpp"
    break;

  case 337: // expr_str: "(" expr_str ")"
#line 653 "frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 2029 "frontend/parser.cpp"
    break;

  case 338: // expr_str: expr_str "++" expr_str
#line 654 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 2035 "frontend/parser.cpp"
    break;

  case 339: // expr_str: expr_str "++" expr_int
#line 655 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 2041 "frontend/parser.cpp"
    break;

  case 340: // expr_str: expr_str "++" expr_float
#line 656 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 2047 "frontend/parser.cpp"
    break;

  case 341: // expr_str: expr_str "++" expr_bool
#line 657 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2053 "frontend/parser.cpp"
    break;

  case 342: // expr_str: expr_str "++" expr_none
#line 658 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 2059 "frontend/parser.cpp"
    break;

  case 343: // expr_str: expr_int "++" expr_str
#line 659 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 2065 "frontend/parser.cpp"
    break;

  case 344: // expr_str: expr_int "++" expr_int
#line 660 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 2071 "frontend/parser.cpp"
    break;

  case 345: // expr_str: expr_int "++" expr_float
#line 661 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 2077 "frontend/parser.cpp"
    break;

  case 346: // expr_str: expr_int "++" expr_bool
#line 662 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2083 "frontend/parser.cpp"
    break;

  case 347: // expr_str: expr_int "++" expr_none
#line 663 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 2089 "frontend/parser.cpp"
    break;

  case 348: // expr_str: expr_float "++" expr_str
#line 664 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 2095 "frontend/parser.cpp"
    break;

  case 349: // expr_str: expr_float "++" expr_int
#line 665 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 2101 "frontend/parser.cpp"
    break;

  case 350: // expr_str: expr_float "++" expr_float
#line 666 "frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 2107 "frontend/parser.cpp"
    break;

  case 351: // expr_str: expr_float "++" expr_bool
#line 667 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2113 "frontend/parser.cpp"
    break;

  case 352: // expr_str: expr_float "++" expr_none
#line 668 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 2119 "frontend/parser.cpp"
    break;

  case 353: // expr_str: expr_bool "++" expr_str
#line 669 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 2125 "frontend/parser.cpp"
    break;

  case 354: // expr_str: expr_bool "++" expr_int
#line 670 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 2131 "frontend/parser.cpp"
    break;

  case 355: // expr_str: expr_bool "++" expr_float
#line 671 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 2137 "frontend/parser.cpp"
    break;

  case 356: // expr_str: expr_bool "++" expr_bool
#line 672 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2143 "frontend/parser.cpp"
    break;

  case 357: // expr_str: expr_bool "++" expr_none
#line 673 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 2149 "frontend/parser.cpp"
    break;

  case 358: // expr_str: expr_none "++" expr_str
#line 674 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 2155 "frontend/parser.cpp"
    break;

  case 359: // expr_str: expr_none "++" expr_int
#line 675 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 2161 "frontend/parser.cpp"
    break;

  case 360: // expr_str: expr_none "++" expr_float
#line 676 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 2167 "frontend/parser.cpp"
    break;

  case 361: // expr_str: expr_none "++" expr_bool
#line 677 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2173 "frontend/parser.cpp"
    break;

  case 362: // expr_str: expr_none "++" expr_none
#line 678 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 2179 "frontend/parser.cpp"
    break;

  case 363: // expr_bool: "bool"
#line 682 "frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 2185 "frontend/parser.cpp"
    break;

  case 364: // expr_bool: "(" expr_bool ")"
#line 683 "frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 2191 "frontend/parser.cpp"
    break;

  case 365: // expr_bool: "not" expr_bool
#line 684 "frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 2197 "frontend/parser.cpp"
    break;

  case 366: // expr_bool: expr_bool "or" expr_bool
#line 685 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 2203 "frontend/parser.cpp"
    break;

  case 367: // expr_bool: expr_bool "and" expr_bool
#line 686 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 2209 "frontend/parser.cpp"
    break;

  case 368: // expr_bool: expr_bool "==" expr_bool
#line 688 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 2215 "frontend/parser.cpp"
    break;

  case 369: // expr_bool: expr_int "==" expr_int
#line 689 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 2221 "frontend/parser.cpp"
    break;

  case 370: // expr_bool: expr_int "==" expr_float
#line 690 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 2227 "frontend/parser.cpp"
    break;

  case 371: // expr_bool: expr_float "==" expr_float
#line 691 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 2233 "frontend/parser.cpp"
    break;

  case 372: // expr_bool: expr_float "==" expr_int
#line 692 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 2239 "frontend/parser.cpp"
    break;

  case 373: // expr_bool: expr_str "==" expr_str
#line 693 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 2245 "frontend/parser.cpp"
    break;

  case 374: // expr_bool: expr_none "==" expr_none
#line 694 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 2251 "frontend/parser.cpp"
    break;

  case 375: // expr_bool: expr_bool "!=" expr_bool
#line 696 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 2257 "frontend/parser.cpp"
    break;

  case 376: // expr_bool: expr_int "!=" expr_int
#line 697 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 2263 "frontend/parser.cpp"
    break;

  case 377: // expr_bool: expr_int "!=" expr_float
#line 698 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 2269 "frontend/parser.cpp"
    break;

  case 378: // expr_bool: expr_float "!=" expr_float
#line 699 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 2275 "frontend/parser.cpp"
    break;

  case 379: // expr_bool: expr_float "!=" expr_int
#line 700 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 2281 "frontend/parser.cpp"
    break;

  case 380: // expr_bool: expr_str "!=" expr_str
#line 701 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 2287 "frontend/parser.cpp"
    break;

  case 381: // expr_bool: expr_none "!=" expr_none
#line 702 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 2293 "frontend/parser.cpp"
    break;

  case 382: // expr_bool: expr_int ">" expr_int
#line 704 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 2299 "frontend/parser.cpp"
    break;

  case 383: // expr_bool: expr_int ">" expr_float
#line 705 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 2305 "frontend/parser.cpp"
    break;

  case 384: // expr_bool: expr_float ">" expr_float
#line 706 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 2311 "frontend/parser.cpp"
    break;

  case 385: // expr_bool: expr_float ">" expr_int
#line 707 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 2317 "frontend/parser.cpp"
    break;

  case 386: // expr_bool: expr_str ">" expr_str
#line 708 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 2323 "frontend/parser.cpp"
    break;

  case 387: // expr_bool: expr_int "<" expr_int
#line 710 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 2329 "frontend/parser.cpp"
    break;

  case 388: // expr_bool: expr_int "<" expr_float
#line 711 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 2335 "frontend/parser.cpp"
    break;

  case 389: // expr_bool: expr_float "<" expr_float
#line 712 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 2341 "frontend/parser.cpp"
    break;

  case 390: // expr_bool: expr_float "<" expr_int
#line 713 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 2347 "frontend/parser.cpp"
    break;

  case 391: // expr_bool: expr_str "<" expr_str
#line 714 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 2353 "frontend/parser.cpp"
    break;

  case 392: // expr_bool: expr_int ">=" expr_int
#line 716 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 2359 "frontend/parser.cpp"
    break;

  case 393: // expr_bool: expr_int ">=" expr_float
#line 717 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 2365 "frontend/parser.cpp"
    break;

  case 394: // expr_bool: expr_float ">=" expr_float
#line 718 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 2371 "frontend/parser.cpp"
    break;

  case 395: // expr_bool: expr_float ">=" expr_int
#line 719 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 2377 "frontend/parser.cpp"
    break;

  case 396: // expr_bool: expr_str ">=" expr_str
#line 720 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 2383 "frontend/parser.cpp"
    break;

  case 397: // expr_bool: expr_int "<=" expr_int
#line 722 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 2389 "frontend/parser.cpp"
    break;

  case 398: // expr_bool: expr_int "<=" expr_float
#line 723 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 2395 "frontend/parser.cpp"
    break;

  case 399: // expr_bool: expr_float "<=" expr_float
#line 724 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 2401 "frontend/parser.cpp"
    break;

  case 400: // expr_bool: expr_float "<=" expr_int
#line 725 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 2407 "frontend/parser.cpp"
    break;

  case 401: // expr_bool: expr_str "<=" expr_str
#line 726 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 2413 "frontend/parser.cpp"
    break;

  case 402: // expr_bool: expr_str "in" expr_str
#line 728 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[0].value.as < std::string > ().find(yystack_[2].value.as < std::string > ()) != std::string::npos; }
#line 2419 "frontend/parser.cpp"
    break;

  case 419: // type: "\"int\"" "?"
#line 756 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2425 "frontend/parser.cpp"
    break;

  case 420: // type: "\"float\"" "?"
#line 757 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2431 "frontend/parser.cpp"
    break;

  case 421: // type: "\"string\"" "?"
#line 758 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2437 "frontend/parser.cpp"
    break;

  case 422: // type: "\"bool\"" "?"
#line 759 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2443 "frontend/parser.cpp"
    break;

  case 423: // type: "identifier" "?"
#line 760 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2449 "frontend/parser.cpp"
    break;

  case 424: // type: funtype "?"
#line 761 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2455 "frontend/parser.cpp"
    break;

  case 425: // type: mattype "?"
#line 762 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2461 "frontend/parser.cpp"
    break;

  case 426: // type: "\"int\""
#line 763 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("int"); }
#line 2467 "frontend/parser.cpp"
    break;

  case 427: // type: "\"float\""
#line 764 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("float"); }
#line 2473 "frontend/parser.cpp"
    break;

  case 428: // type: "\"string\""
#line 765 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("string"); }
#line 2479 "frontend/parser.cpp"
    break;

  case 429: // type: "\"bool\""
#line 766 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("bool"); }
#line 2485 "frontend/parser.cpp"
    break;

  case 430: // type: "identifier"
#line 767 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[0].value.as < std::string > ()); }
#line 2491 "frontend/parser.cpp"
    break;

  case 431: // type: funtype
#line 768 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2497 "frontend/parser.cpp"
    break;

  case 432: // type: mattype
#line 769 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2503 "frontend/parser.cpp"
    break;


#line 2507 "frontend/parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -724;

  const short  Parser ::yytable_ninf_ = -431;

  const short
   Parser ::yypact_[] =
  {
     830,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  1825,    18,
      82,  1651,   437,   -47,   -25,    49,    62,    83,  2297,  1952,
    -724,  -724,    81,    78,   144,   157,   158,   120,   123,   317,
     108,    56,  -724,  -724,   113,   219,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,   226,   247,   251,  2188,  2508,  -724,  1309,
    -724,   294,   320,  2821,  2987,   640,   603,   196,   210,     6,
     302,   312,  2479,   306,  1309,   314,   121,   294,   320,  2738,
    1004,   845,   693,  1952,  -724,   312,   292,   218,   409,   409,
    -724,  -724,  -724,  1981,   370,  2844,  3021,  1388,  -724,   437,
     437,  -724,   301,  -724,   304,  1952,   271,  1952,   335,  2382,
    -724,  -724,   297,  -724,   377,   577,  -724,   737,  -724,   903,
    -724,   933,  -724,    38,  -724,   415,   423,   146,  1952,  -724,
    -724,  -724,  -724,  -724,  2412,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  1952,  1952,  1952,  1952,  1952,  1952,  1952,  1952,
    1952,  1952,  1952,  1952,  1952,  1061,  1306,  1952,  1952,  1952,
    1952,  1952,  1952,  1952,  1952,  1952,  1952,  1952,  1952,  1952,
    1952,  1952,  1952,  1952,  1952,  1952,  1952,  1952,  1952,  -724,
    1306,  1952,  1952,  1952,  1952,  1952,  1952,  -724,  1952,  1952,
    1952,  1952,  1952,  1952,  1952,  1952,  1952,  1952,  1952,  1952,
    1952,   409,  1952,  1952,  1952,  1952,  1952,  1952,  1952,  1952,
    1952,  1952,  1952,  1952,  1952,  1952,  1952,  1952,  1952,  1952,
    1952,  1952,  1952,  1952,  1952,  1952,  1952,  1952,  1952,  1952,
    1952,  1952,  1952,  1952,  1952,  1952,  1952,  1952,  1952,  1952,
    1952,  1952,  1952,  1952,  -724,  -724,   166,    24,  -724,  1306,
     405,  -724,  -724,  -724,  1952,  1952,  -724,  -724,  -724,  -724,
     408,   331,   421,  -724,  1686,   948,   409,   409,   409,   409,
     409,   437,   437,   437,   437,   437,   409,   409,   409,   409,
     409,   409,  2770,  2798,  1066,   536,  1651,   231,   231,  1651,
     409,   409,   409,   409,   409,   409,  1651,   409,   409,   409,
     409,   409,   409,  1651,  1651,  1651,  1651,  1651,  1651,  1651,
    1651,  1651,  1651,  1651,  1651,  1651,  2315,  -724,   437,   437,
     437,   437,   437,  1952,   362,   453,   424,   457,  2412,  -724,
    1465,   459,  1952,  -724,  2508,   432,  2821,  2987,   640,   603,
     462,  -724,   465,  -724,   476,  -724,   490,   463,    32,   239,
    -724,   638,    36,   493,  -724,   416,   492,   266,  2821,  -724,
    -724,  3071,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,    60,  -724,    27,   431,   406,
     504,   578,   431,   406,   504,   578,   235,   497,   470,   506,
     235,   470,   506,   235,   470,   506,   235,   506,  2237,   411,
     467,  2876,  1108,   482,   770,  2566,   479,  2537,   332,  2595,
     815,  2710,  2998,  2630,  2930,  2675,  2964,   964,  1592,   964,
    1592,  1828,   549,  -724,  -724,  3029,  3058,   373,  -724,  1828,
     549,  -724,  -724,  3029,  3058,   373,  -724,   464,  1374,  1607,
     529,   464,  1374,  1607,   529,   464,  1374,  1607,   529,   464,
    1374,  1607,   529,   266,    33,   431,   406,   431,   406,   235,
     497,  2595,   164,  1828,   549,  1828,   549,  2237,   411,   467,
    2876,  1108,   482,   770,  2595,   164,  1828,  -724,  1828,  -724,
    2237,   411,   467,  2876,  1108,   482,   770,  2595,   164,  1828,
    -724,  1828,  -724,   431,   504,   578,   431,   504,   578,   235,
     470,   506,   235,   470,   506,   235,   470,   506,  3081,   521,
    2237,   411,   467,  2876,  1108,   482,   770,  2595,   164,  2710,
    2998,  2630,  2930,  2675,  2964,   964,  1592,   964,  1592,  1828,
    3029,  3058,  1828,  3029,  3058,   464,  1374,  1607,   464,  1374,
    1607,   464,  1374,  1607,   464,  1374,  1607,   431,   504,   578,
     431,   504,   578,   235,   470,   506,   235,   470,   506,   235,
     470,   506,   235,   470,   506,  2237,   411,   467,  2876,  1108,
     482,   770,  2595,   164,  1828,  3029,  3058,  1828,  3029,  3058,
     464,  1374,  1607,   464,  1374,  1607,   464,  1374,  1607,   464,
    1374,  1607,   537,  2237,   411,   467,  2876,  1108,   482,   770,
    2595,   164,   815,  1828,   373,  1828,   373,   464,   529,   464,
     529,   464,   529,   464,   529,  2237,   411,   467,  2876,  1108,
     482,   770,  2566,   479,  2537,   332,  2595,   164,  1828,  -724,
    1828,  -724,  -724,   159,   540,    29,   311,  1173,    41,  -724,
     543,   517,   550,  -724,  1952,  -724,  -724,   769,   825,   769,
     825,   470,   521,   470,   521,   470,   521,  1239,  1177,  1425,
     715,   715,   769,   825,   769,   825,   470,   521,   470,   521,
     470,   521,   470,   521,   329,  2904,  3052,   888,   240,   555,
    -724,  -724,   329,  2904,  3052,   888,   240,  1494,  1627,  1494,
    1627,  1494,  1627,  1494,  1627,  1494,  1627,  1494,  1627,   329,
    2904,  3052,   888,   240,  1494,  1627,  1494,  1627,  1494,  1627,
    1494,  1627,  1494,  1627,  1494,  1627,   329,  2904,  3052,   888,
     240,  1837,   372,   839,   839,  -724,  -724,  -724,  -724,   329,
    2904,  3052,   888,   240,   356,    22,  -724,  -724,   561,   561,
    -724,  -724,  -724,  -724,  -724,  2297,  1952,  2297,  1875,   568,
    1952,  -724,  1952,  -724,  -724,  -724,  -724,   102,   102,  -724,
     501,   558,   584,  -724,    31,   220,   184,   551,    34,  -724,
    1268,   142,  -724,   676,  -724,   548,  -724,  -724,  1952,  -724,
    -724,  -724,  1491,  -724,   473,   220,   221,  -724,  -724,  -724,
    1952,  -724,  -724,   302,   532,   593,  -724,   601,  -724,   595,
    -724,   594,  -724,   565,  -724,   102,   567,  -724,   220,   473,
     473,   587,  -724,   618,  -724,  1553,  -724,  1590,   207,  1952,
    -724,  -724,  -724,   220,   629,  2297,  -724,  2297,  -724,  -724,
    -724,  1952,  -724,  1952,  -724,   608,   551,    40,  1952,  -724,
    -724,   641,  -724,   643,  -724,  1625,   617,  -724,  -724,  -724,
    -724,  -724,  -724,   587,  -724,  -724,  -724,  -724,   646,   620,
    -724,  -724
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
       0,     0,     0,     0,   424,   425,     0,    62,   294,     0,
     295,    93,   275,   276,     0,     0,   303,   317,   337,   364,
       0,     0,     0,   266,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   302,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,   410,   280,   417,   279,     0,     0,     0,
       0,   412,     0,   414,     0,   416,     0,     0,     0,     0,
     408,     0,     0,     0,   297,     0,     0,   103,     0,     6,
      80,    79,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    94,     0,    81,     0,   133,   131,
     128,   129,   141,   139,   136,   137,   115,   114,   110,   111,
     120,   118,   119,   125,   123,   124,   107,   106,   264,   262,
     263,   258,   259,   260,   261,   237,   236,   240,   239,   234,
     233,   212,   211,   218,   217,   215,   214,   144,   143,   147,
     146,   192,   190,   187,   188,   183,   184,   185,   186,   209,
     207,   204,   205,   200,   201,   202,   203,   154,   151,   152,
     153,   168,   165,   166,   167,   161,   158,   159,   160,   175,
     172,   173,   174,   104,     0,   132,   130,   140,   138,   113,
     112,   232,   225,   191,   189,   208,   206,   256,   362,   245,
     359,   360,   358,   361,   230,   223,   180,   374,   197,   381,
     257,   250,   251,   246,   247,   248,   249,   231,   224,   182,
     181,   199,   198,   126,   309,   335,   134,   308,   332,   108,
     305,   323,   116,   306,   326,   121,   307,   329,     0,   320,
     252,   347,   241,   344,   345,   343,   346,   226,   219,   210,
     312,   216,   314,   213,   313,   142,   310,   145,   311,   176,
     369,   370,   193,   376,   377,   148,   382,   383,   162,   387,
     388,   155,   392,   393,   169,   397,   398,   127,   334,   333,
     135,   331,   330,   109,   322,   321,   117,   325,   324,   122,
     328,   327,   105,   319,   318,   253,   352,   242,   349,   350,
     348,   351,   227,   220,   177,   372,   371,   194,   379,   378,
     149,   385,   384,   163,   390,   389,   156,   395,   394,   170,
     400,   399,     0,   254,   342,   243,   339,   340,   338,   341,
     228,   221,   402,   178,   373,   195,   380,   150,   386,   164,
     391,   157,   396,   171,   401,   255,   357,   244,   354,   355,
     353,   356,   235,   367,   238,   366,   229,   222,   179,   368,
     196,   375,   404,   430,     0,   405,     0,     0,     0,   296,
       0,     0,     0,   267,     0,   271,   268,   309,   335,   308,
     332,   305,   323,   306,   326,   307,   329,   312,   314,   313,
     310,   311,   334,   333,   331,   330,   322,   321,   325,   324,
     328,   327,   319,   318,   362,   359,   360,   358,   361,     0,
     374,   381,   347,   344,   345,   343,   346,   369,   370,   376,
     377,   382,   383,   387,   388,   392,   393,   397,   398,   352,
     349,   350,   348,   351,   372,   371,   379,   378,   385,   384,
     390,   389,   395,   394,   400,   399,   342,   339,   340,   338,
     341,   402,     0,   373,   380,   386,   391,   396,   401,   357,
     354,   355,   353,   356,   367,   366,   368,   375,   309,   308,
     305,   306,   307,    66,    30,     0,     0,     0,     0,    22,
       0,    65,     0,   409,   411,   413,   415,     0,    45,    42,
       0,     0,     0,    49,     0,     0,     0,    58,     0,   281,
       0,     0,    98,     0,   407,     0,   298,    95,     0,    99,
      97,    96,     0,   403,     0,     0,     0,    64,    63,   277,
       0,   269,   272,     0,    41,     0,    37,    23,    24,     0,
     418,     0,    46,     0,    43,    47,    62,    54,     0,     0,
       0,    57,   285,     0,   283,     0,   282,     0,     0,     0,
      82,   406,    52,     0,     0,     0,    39,     0,    25,    38,
      44,     0,    48,     0,    55,    59,    61,     0,     0,   288,
     287,     0,   286,     0,   284,     0,   299,    53,   278,    40,
      36,    51,    50,     0,    60,   291,   290,   289,     0,     0,
     292,   300
  };

  const short
   Parser ::yypgoto_[] =
  {
    -724,  -724,   -86,   -14,   -16,  -723,  -721,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -711,  -724,  -724,
    -724,  -606,  -137,  -326,  -724,   534,  -724,  2150,  1577,   656,
     -67,  1088,   660,   355,   983,   853,  1234,   -57,  -180,  1917,
       0,   234,   478,  -724,  -103,  -724,  -104,    11
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    30,    31,    32,    33,   101,   102,    34,    94,    35,
      36,    37,    38,    39,    40,   816,    41,   751,   752,    42,
     115,   756,   757,    43,    44,    45,   365,    46,    47,    48,
      77,    64,    50,   325,   169,    67,    68,   121,   346,    53,
     327,   328,   329,    57,   624,    58,   343,    59
  };

  const short
   Parser ::yytable_[] =
  {
      54,   330,   100,   332,   240,   334,   250,   336,    70,    54,
      82,    86,   753,   320,   784,   236,   786,   125,    54,    54,
     776,    73,     3,     4,     5,     6,     7,     8,    92,     9,
      74,    54,   797,   626,    10,   748,   791,   792,   236,   769,
     236,   337,    11,   236,   302,   770,   749,    12,   762,   236,
      93,   338,   812,   762,   304,   305,   123,   124,    95,     2,
       3,     4,     5,     6,     7,     8,   627,     9,   763,   774,
     767,    96,    10,    54,   763,   824,   742,   763,   255,    82,
      11,   237,   763,   273,   822,    12,     3,     4,   750,   105,
     837,    78,    97,    75,   839,    54,   840,    54,    79,    54,
     768,    23,    24,    25,    26,   748,   796,   623,   122,   801,
     349,    12,    13,    14,    15,   843,   126,    16,    17,    18,
      19,    20,    21,    22,    54,    23,    24,    25,    26,    27,
      28,    29,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,   106,   371,   375,   379,
     382,   385,   387,   392,   804,   107,   104,    80,   750,   244,
     344,   245,   416,   424,   429,   433,   437,   441,   109,   111,
     772,    23,    24,    25,    26,   170,   622,   623,   461,   171,
     172,   173,   474,   805,   635,   345,   485,   488,   491,   494,
     497,   499,   504,   825,   798,   113,   175,   176,   114,   521,
     524,   527,   530,   533,   536,   539,   542,   545,   548,   551,
     554,   559,   108,   566,   569,   572,   575,   578,   581,   834,
     587,   252,   127,    98,   799,   110,   112,   119,   609,   128,
     253,   813,   738,    99,    55,    23,    24,    25,    26,     7,
     669,   623,    71,    55,   145,    87,   146,   625,   835,   755,
     129,    54,    55,    55,   130,   152,   638,   640,   642,   644,
     646,   799,   302,   303,   234,    55,   653,   655,   657,   659,
     661,   663,   304,   305,   168,   145,   666,   146,   235,   674,
     678,   680,   682,   684,   686,   688,   691,   695,   697,   699,
     701,   703,   705,   708,    86,    86,    86,    86,    86,    86,
      86,   721,    86,    86,    86,    86,   125,    55,    23,    24,
      25,    26,   238,    54,   623,   178,   242,   274,    54,   179,
      54,   775,    54,   239,   243,   117,   180,   181,   116,    55,
     117,    55,   251,    55,   634,     3,     4,     5,     6,     7,
       8,   182,     9,   313,   314,   183,   316,    10,   318,   754,
     758,   118,   184,   185,   229,    11,   118,   231,    55,   321,
      12,   277,   278,    66,   232,   233,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      23,    24,    25,    26,   219,   119,   623,   393,   304,   305,
     400,   276,  -430,   301,   302,   303,   417,   425,   430,   434,
     438,   442,   277,   278,   304,   305,    75,   224,   225,   226,
     227,   632,   462,     3,     4,   629,   475,   170,    78,   322,
     633,   753,   753,   173,   339,    79,   505,     3,     4,     5,
       6,     7,     8,   636,     9,   340,   179,   734,    12,    10,
     145,     3,   146,   180,   181,   560,    89,    11,   149,   150,
     151,   152,    12,    90,   588,   592,   594,   596,   598,   600,
     602,   604,   610,   735,   341,   736,    12,   737,   740,   753,
     168,   342,   742,   145,   743,   146,   747,   744,    56,   147,
     148,   149,   150,   151,   152,    55,    72,    56,   745,    88,
     191,   765,   183,   219,   160,   161,    56,    56,    75,   184,
     185,   367,   746,   168,   231,   764,   766,   221,   170,    56,
     667,   232,   233,   675,   222,   223,   224,   225,   226,   227,
     692,   188,   189,   190,   191,   444,   210,   709,   711,   713,
     714,   715,   716,   717,   718,   722,    87,    87,    87,    87,
     219,   271,    23,    24,    25,    26,   249,    55,   623,   771,
     773,    56,    55,   779,    55,   780,    55,   301,   302,   303,
     170,   275,   781,   783,   171,   172,   173,   782,   304,   305,
     778,   788,   794,    56,   582,    56,   793,    56,   310,   311,
     312,     3,     4,     5,     6,     7,     8,   795,     9,   323,
     809,   800,   815,    10,   628,   207,   208,   209,   210,   630,
     631,    11,    56,   817,   818,   819,    12,   821,   820,   823,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,   228,   229,   230,    54,   231,   828,
     829,   394,   396,   398,    54,   232,   233,   758,   790,   838,
     418,   426,     3,     4,     5,     6,     7,     8,   799,     9,
     759,   219,    75,   845,    10,   846,   463,   849,   850,   345,
     476,   220,    11,   826,    63,   221,   350,    12,    65,   851,
     506,   811,   222,   223,   224,   225,   226,   227,     0,   760,
       3,     4,     5,     6,     7,     8,     0,     9,   806,   561,
       0,     0,    10,     0,     0,     0,   761,     0,   589,     0,
      11,     0,     0,   249,     0,    12,   611,   613,   615,     0,
     619,   621,     0,    75,   228,   229,   230,   807,   231,   100,
       0,   100,     0,     0,   125,   232,   233,     0,     0,    56,
     308,   309,   310,   311,   312,    54,    54,    54,    54,     0,
      54,     3,     4,     5,     6,     7,     8,     0,     9,   331,
       0,    75,     0,    10,   668,     0,     0,   676,   754,   754,
       0,    11,     0,     0,   693,     0,    12,     0,    54,     0,
       0,   710,   712,   712,   712,   712,   712,   712,   712,   723,
     724,   725,   726,   727,     0,   625,   258,   259,   260,   191,
       0,    56,   229,   230,     0,   231,    56,     0,    56,   100,
      56,   100,   232,   233,     0,     0,   754,     0,     0,    54,
     758,   827,    75,     0,     0,    54,     0,    54,     0,     0,
       0,    54,     0,    54,     0,     0,   219,     0,    54,     0,
       1,     0,     0,     2,     3,     4,     5,     6,     7,     8,
       0,     9,   268,   269,   270,   271,    10,   222,   223,   224,
     225,   226,   227,    51,    11,   248,   219,     0,     0,    12,
       0,    55,    51,     0,    84,     0,   220,     0,    55,     0,
     221,    51,    51,   297,   298,   299,   300,   222,   223,   224,
     225,   226,   227,     0,    51,     0,    13,    14,    15,     0,
       0,    16,    17,    18,    19,    20,    21,    22,     0,    23,
      24,    25,    26,    27,    28,    29,     0,     3,     4,     5,
       6,     7,     8,   294,     9,   333,     0,     0,     0,    10,
     295,   296,   297,   298,   299,   300,    51,    11,     0,     0,
       0,     0,    12,     0,     0,     0,    84,     3,     4,     5,
       6,     7,     8,     0,     9,   335,     0,     0,    51,    10,
      51,     0,    51,     0,     0,     0,     0,    11,   247,     0,
       0,     0,    12,   266,   267,   268,   269,   270,   271,    55,
      55,    55,    55,   145,    55,   146,     0,    51,    75,   147,
     148,   149,   150,   151,   152,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,     0,
       0,     0,    55,   168,     0,     0,   389,     0,    75,     0,
       0,     0,   120,     0,   247,   413,   421,     0,     0,   205,
     206,   207,   208,   209,   210,   211,     0,     0,     0,   212,
       0,   458,   177,   467,   469,   471,   213,   214,   215,   216,
     217,   218,     0,    55,   120,   501,     0,   177,     0,    55,
       0,    55,     0,     0,     0,    55,     0,    55,   120,     0,
       0,     0,    55,     0,   556,     3,     4,     5,     6,     7,
       8,   364,     9,   584,     0,     0,   248,    10,     0,     0,
       0,   606,     0,     0,     0,    11,     0,   293,    49,     0,
      12,   294,     0,     0,     0,     0,     0,    49,   295,   296,
     297,   298,   299,   300,    51,    56,    49,    49,     0,     0,
       0,     0,    56,     0,     0,   803,     0,     0,   808,    49,
       0,     0,     0,   205,   206,   207,   208,   209,   210,   664,
     670,   671,   672,   212,     0,   814,    75,     0,     0,   689,
     213,   214,   215,   216,   217,   218,   706,    84,    84,    84,
      84,    84,    84,    84,   719,    84,    84,    84,    84,     0,
     831,    49,   833,     0,     0,     0,    51,     0,     0,     0,
       0,    51,     0,    51,     0,    51,     0,     3,     4,     5,
       6,     7,     8,    49,     9,    49,   117,    49,     0,    10,
     848,     0,   308,   309,   310,   311,   312,    11,     0,     0,
       0,     0,    12,   261,     0,   263,     0,   264,   265,     0,
       0,     0,    49,    56,    56,    56,    56,     0,    56,     0,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    52,   369,   373,   377,     0,     0,
       0,     0,     0,    52,     0,     0,    56,     0,    75,     0,
     412,   420,    52,    52,   308,   309,   310,   311,   312,   446,
     448,   450,   452,   454,   456,    52,     0,   465,     0,   264,
     265,   478,     3,     4,     5,     6,     7,     8,     0,     9,
     802,   508,     0,     0,    10,     0,     0,    56,     0,     0,
       0,     0,    11,    56,     0,    56,     0,    12,     0,    56,
     563,    56,     0,     0,     0,     0,    56,    52,     0,   591,
       3,     4,     5,     6,     7,     8,     0,     9,     0,   617,
     170,     0,    10,     0,   171,   172,   173,     0,     0,    52,
      11,    52,     0,    52,   174,    12,     0,     0,     0,    49,
       0,   175,   176,    75,     0,     0,     0,   341,     0,     0,
       0,     0,   177,     0,     0,     0,   177,     0,    52,     0,
     177,     0,     0,     0,     0,     0,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
       0,    75,     0,     0,     0,     0,     0,   390,     0,   186,
     187,   188,   189,   190,   191,   177,   414,   422,     0,     0,
       0,    49,     0,   177,   197,   198,    49,     0,    49,   293,
      49,     0,   459,   294,     0,     0,   472,     0,   480,   482,
     295,   296,   297,   298,   299,   300,   502,     0,     0,   177,
       0,   177,     0,   177,     0,   177,     0,   177,     0,   177,
     308,   309,   310,   311,   312,   557,     0,     0,   177,     0,
       0,   261,     0,     0,   585,   264,   265,     0,     0,     0,
       0,   177,   607,     0,     0,     0,   124,     0,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,   739,
      51,    10,     0,     0,     0,    52,     0,    51,     0,    11,
       0,   177,     0,     0,    12,     3,     4,     5,     6,     7,
       8,     0,     9,   340,     0,     0,     0,    10,     0,   256,
     257,   258,   259,   260,   191,    11,     0,     0,     0,     0,
      12,    13,    14,    15,   264,   265,    16,    17,    18,    19,
      20,    21,    22,     0,    23,    24,    25,    26,    27,    28,
      29,     0,     0,     0,     0,     0,   177,    52,     0,     0,
       0,     0,    52,     0,    52,     0,    52,     3,     4,     5,
       6,     7,     8,     0,     9,   830,    75,     0,     0,    10,
       0,     0,     0,     0,   177,     0,     0,    11,     0,     0,
       0,     0,    12,     0,     0,    62,     0,     0,    51,    51,
      51,    51,     0,    51,     3,     4,     5,     6,     7,     8,
     177,     9,   832,     0,     0,     0,    10,   186,   187,   188,
     189,   190,   191,     0,    11,     0,     0,     0,     0,    12,
       0,    51,   205,   206,   207,   208,   209,   210,    75,     3,
       4,     5,     6,     7,     8,     0,     9,   847,     0,     0,
       0,    10,   266,   267,   268,   269,   270,   271,     0,    11,
       0,     0,     0,     0,    12,     3,     4,     5,     6,     7,
      83,     0,    51,     0,     0,    75,     0,    79,    51,     0,
      51,     0,     0,     0,    51,    11,    51,     0,     0,     0,
      12,    51,   324,     0,   324,     0,   324,     0,   324,     0,
       0,     0,     0,   324,     0,   347,   246,     0,     0,     0,
      75,   256,   257,   258,   259,   260,   191,     0,     0,     0,
       0,     0,   261,   262,   263,    49,   264,   265,     0,     0,
       0,     0,    49,   324,   368,   372,   376,   380,   383,   386,
     388,   395,   397,   399,   401,   403,   405,   407,   409,   411,
     419,   427,   431,   435,   439,   443,     0,   324,   445,   447,
     449,   451,   453,   455,     0,   457,   464,   466,   468,   470,
     477,   479,   481,   483,   486,   489,   492,   495,     0,   500,
     507,   509,   511,   513,   515,   517,   519,   522,   525,   528,
     531,   534,   537,   540,   543,   546,   549,   552,   555,   562,
     564,   567,   570,   573,   576,   579,   324,   583,   590,   593,
     595,   597,   599,   601,   603,   605,   612,   614,   616,   618,
     620,     0,     0,     0,     0,     0,   324,     0,     0,     0,
       0,   324,   324,    49,    49,    49,    49,     0,    49,     3,
       4,     5,     6,    60,     8,     0,     9,   145,     0,   146,
       0,    10,     0,   147,   148,   149,   150,   151,   152,    11,
       0,     0,     0,     0,    12,     0,    49,     0,   160,   161,
       0,    52,   164,   165,   166,   167,     0,   168,    52,   295,
     296,   297,   298,   299,   300,     0,   124,     0,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,   787,
       0,    10,     0,     0,     0,     0,     0,    49,     0,    11,
      61,     0,     0,    49,    12,    49,     0,     0,     0,    49,
       0,    49,     0,     0,     0,     0,    49,     0,   324,     0,
       0,     0,     0,     0,     0,    69,     0,    81,    85,    91,
       0,    13,    14,    15,     0,     0,    16,    17,    18,    19,
      20,    21,    22,     0,    23,    24,    25,    26,    27,    28,
      29,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     0,     9,     0,     0,     0,     0,    10,    52,
      52,    52,    52,     0,    52,     0,    11,     0,     0,     0,
       0,    12,     0,     0,     0,     3,     4,     5,     6,    60,
      83,     0,     0,     0,     0,   254,    81,    79,     0,     0,
     272,     0,    52,     0,     0,    11,   306,   307,     0,     0,
      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   326,     0,   326,     0,   326,    75,   326,     0,
       0,     0,     0,   326,     0,   348,     0,     0,     0,     0,
       0,     0,     0,    52,     0,     0,     0,     0,     0,    52,
       0,    52,     0,     0,     0,    52,     0,    52,     0,     0,
       0,     0,    52,   326,   370,   374,   378,   381,   384,   348,
     391,   348,   348,   348,   402,   404,   406,   408,   410,   415,
     423,   428,   432,   436,   440,   348,     0,   326,   348,   348,
     348,   348,   348,   348,     0,   460,   348,   348,   348,   473,
     348,   348,   348,   484,   487,   490,   493,   496,   498,   503,
     348,   510,   512,   514,   516,   518,   520,   523,   526,   529,
     532,   535,   538,   541,   544,   547,   550,   553,   558,   348,
     565,   568,   571,   574,   577,   580,   326,   586,   348,   348,
     348,   348,   348,   348,   348,   608,   348,   348,   348,   348,
     348,     0,     0,     0,     0,     0,   326,     0,     0,    76,
       0,   326,   326,     0,     0,     0,     0,     0,     0,   103,
       0,     0,     0,   637,   639,   641,   643,   645,   647,   648,
     649,   650,   651,   652,   654,   656,   658,   660,   662,     0,
       0,   131,     0,   665,     0,     0,   673,   677,   679,   681,
     683,   685,   687,   690,   694,   696,   698,   700,   702,   704,
     707,    85,    85,    85,    85,    85,    85,    85,   720,    85,
      85,    85,    85,    76,     0,   728,   729,   730,   731,   732,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,     0,   143,   144,     0,   315,   145,   317,   146,     0,
       0,     0,   147,   148,   149,   150,   151,   152,   326,   154,
     155,     0,   156,   157,   158,   159,     0,   160,   161,   162,
     163,   164,   165,   166,   167,     0,   168,     0,     0,     0,
       0,     0,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   366,     0,     0,     0,     0,
      98,     3,     4,     5,     6,     7,     8,     0,     9,     0,
      99,     0,     0,    10,     0,     0,     0,     0,     0,   324,
       0,    11,     0,     0,     0,   246,    12,     0,     0,     0,
     308,   309,   310,   311,   312,     0,     0,   324,     0,     0,
     324,   261,   262,   263,     0,   264,   265,     0,     0,   324,
       0,     0,     0,    13,    14,    15,     0,   324,    16,    17,
      18,    19,    20,    21,    22,     0,    23,    24,    25,    26,
      27,    28,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   324,     0,   324,     2,     3,     4,     5,     6,
       7,     8,     0,     9,     0,     0,   319,     0,    10,     0,
       0,    76,     0,     0,     0,     0,    11,     0,     0,     0,
       0,    12,   324,     0,     0,     2,     3,     4,     5,     6,
       7,     8,     0,     9,     0,     0,     0,     0,    10,     0,
       0,     0,     0,     0,     0,     0,    11,     0,    13,    14,
      15,    12,     0,    16,    17,    18,    19,    20,    21,    22,
       0,    23,    24,    25,    26,    27,    28,    29,     0,     0,
       0,     0,     0,   733,     0,     0,     0,     0,    13,    14,
      15,     0,   741,    16,    17,    18,    19,    20,    21,    22,
       0,    23,    24,    25,    26,    27,    28,    29,   145,   241,
     146,     0,     0,     0,   147,   148,   149,   150,   151,   152,
     153,   154,   155,     0,   156,   157,   158,   159,     0,   160,
     161,   162,   163,   164,   165,   166,   167,   145,   168,   146,
       0,     0,     0,   147,   148,   149,   150,   151,   152,   153,
     154,   155,     0,   156,   157,   158,   159,     0,   160,   161,
     162,   163,   164,   165,   166,   167,   145,   168,   146,     0,
       0,     0,   147,   148,   149,   150,   151,   152,     0,   154,
       0,     0,   156,   157,   158,   159,     0,   160,   161,   162,
     163,   164,   165,   166,   167,   145,   168,   146,     0,     0,
       0,   147,   148,   149,   150,   151,   152,     0,     0,     0,
       0,   156,   157,   158,   159,     0,   160,   161,   162,   163,
     164,   165,   166,   167,   145,   168,   146,     0,     0,     0,
     147,   148,   149,   150,   151,   152,     0,     0,     0,     0,
       0,   157,   158,   159,     0,   160,   161,   162,   163,   164,
     165,   166,   167,     0,   168,     0,     0,     0,     0,   145,
       0,   146,     0,     0,     0,   147,   148,   149,   150,   151,
     152,     0,     0,     0,     0,     0,   157,     0,   159,   326,
     160,   161,   162,   163,   164,   165,   166,   167,     0,   168,
       0,     0,     0,     0,     0,     0,     0,   326,     0,     0,
     326,     0,     0,     0,   145,     0,   146,     0,     0,   326,
     147,   148,   149,   150,   151,   152,     0,   326,     0,     0,
       0,   157,     0,     0,     0,   160,   161,   162,   163,   164,
     165,   166,   167,     0,   168,     0,     0,     0,     0,   145,
       0,   146,   326,     0,   326,   147,   148,   149,   150,   151,
     152,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     160,   161,   162,   163,   164,   165,   166,   167,   246,   168,
       0,     0,   326,   186,   187,   188,   189,   190,   191,   192,
       0,     0,     0,   193,   194,   195,   196,     0,   197,   198,
     199,   200,   201,   202,   203,   204,     0,   777,     0,     0,
     246,     0,     0,     0,    76,   256,   257,   258,   259,   260,
     191,   279,     0,     0,     0,     0,   261,   262,   263,     0,
     264,   265,   280,   281,   282,   283,   284,   285,   247,     0,
       0,     0,     0,   266,   267,   268,   269,   270,   271,   286,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     287,   288,   289,   290,   291,   292,   186,   187,   188,   189,
     190,   191,   192,     0,     0,     0,   193,   194,   195,   196,
       0,   197,   198,   199,   200,   201,   202,   203,   204,   256,
     257,   258,   259,   260,   191,   279,     0,     0,     0,     0,
     261,   262,   263,     0,   264,   265,   280,   281,   282,   283,
     284,   285,     0,     0,     0,     0,   785,     0,     0,     0,
     789,   186,   187,   188,   189,   190,   191,     0,     0,     0,
       0,   193,   194,   195,   196,     0,   197,   198,   199,   200,
     201,   202,   203,   204,     0,     0,     0,     0,   810,   256,
     257,   258,   259,   260,   191,     0,     0,     0,     0,     0,
     261,   262,   263,     0,   264,   265,   280,   281,   282,   283,
     284,   285,     0,     0,     0,   186,   187,   188,   189,   190,
     191,     0,     0,     0,     0,     0,   194,     0,   196,   836,
     197,   198,   199,   200,   201,   202,   203,   204,     0,     0,
       0,   841,     0,   842,     0,     0,     0,     0,   844,   186,
     187,   188,   189,   190,   191,     0,     0,     0,     0,     0,
     194,     0,     0,     0,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,     0,
       0,     0,   212,   186,   187,   188,   189,   190,   191,   213,
     214,   215,   216,   217,   218,     0,     0,     0,   197,   198,
     199,   200,   201,   202,   203,   204,   266,   267,   268,   269,
     270,   271,   286,     0,   186,   187,   188,   189,   190,   191,
       0,     0,     0,   287,   288,   289,   290,   291,   292,   197,
     198,     0,     0,   201,   202,   203,   204,   266,   267,   268,
     269,   270,   271,   205,   206,   207,   208,   209,   210,     0,
       0,     0,     0,     0,   287,   288,   289,   290,   291,   292,
       0,     0,   215,   216,   217,   218,   256,   257,   258,   259,
     260,   191,     0,     0,     0,     0,     0,   261,   262,   263,
       0,   264,   265,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,     0,   143,   144
  };

  const short
   Parser ::yycheck_[] =
  {
       0,   105,    18,   107,    61,   109,    73,   111,     8,     9,
      10,    11,   338,    99,   735,     9,   737,    31,    18,    19,
     626,     3,     4,     5,     6,     7,     8,     9,    75,    11,
      12,    31,   755,     9,    16,     3,   747,   748,     9,    12,
       9,     3,    24,     9,    22,    12,    14,    29,    12,     9,
      75,    13,   775,    12,    32,    33,     0,     1,     9,     3,
       4,     5,     6,     7,     8,     9,    42,    11,    41,    40,
      10,     9,    16,    73,    41,   798,    40,    41,    78,    79,
      24,    75,    41,    83,   795,    29,     4,     5,    56,    11,
     813,     9,     9,    75,   815,    95,   817,    97,    16,    99,
      40,    69,    70,    71,    72,     3,    75,    75,     0,    75,
     124,    29,    56,    57,    58,    75,     3,    61,    62,    63,
      64,    65,    66,    67,   124,    69,    70,    71,    72,    73,
      74,    75,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,    68,   147,   148,   149,
     150,   151,   152,   153,    12,    11,    75,    75,    56,    38,
      14,    40,   162,   163,   164,   165,   166,   167,    11,    11,
      11,    69,    70,    71,    72,    11,    10,    75,   178,    15,
      16,    17,   182,    41,   251,    39,   186,   187,   188,   189,
     190,   191,   192,   799,    10,    75,    32,    33,    75,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,    68,   213,   214,   215,   216,   217,   218,    12,
     220,     3,     3,     3,    40,    68,    68,    68,   228,     3,
      12,    10,   318,    13,     0,    69,    70,    71,    72,     8,
       9,    75,     8,     9,     9,    11,    11,   236,    41,    10,
       3,   251,    18,    19,     3,    20,   256,   257,   258,   259,
     260,    40,    22,    23,    68,    31,   266,   267,   268,   269,
     270,   271,    32,    33,    39,     9,   276,    11,    68,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   320,    73,    69,    70,
      71,    72,    10,   313,    75,    21,    10,    83,   318,    25,
     320,    10,   322,    11,    10,    13,    32,    33,    11,    95,
      13,    97,    40,    99,     3,     4,     5,     6,     7,     8,
       9,    21,    11,    42,    40,    25,    75,    16,    13,   338,
     339,    39,    32,    33,    22,    24,    39,    25,   124,    62,
      29,    32,    33,     8,    32,    33,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
      69,    70,    71,    72,    11,    68,    75,   153,    32,    33,
     156,    21,    75,    21,    22,    23,   162,   163,   164,   165,
     166,   167,    32,    33,    32,    33,    75,    34,    35,    36,
      37,     3,   178,     4,     5,    10,   182,    11,     9,    42,
      12,   747,   748,    17,     9,    16,   192,     4,     5,     6,
       7,     8,     9,    12,    11,    12,    25,    75,    29,    16,
       9,     4,    11,    32,    33,   211,     9,    24,    17,    18,
      19,    20,    29,    16,   220,   221,   222,   223,   224,   225,
     226,   227,   228,    10,    41,    41,    29,    10,     9,   795,
      39,   116,    40,     9,    12,    11,    13,    12,     0,    15,
      16,    17,    18,    19,    20,   251,     8,     9,    12,    11,
      20,    75,    25,    11,    30,    31,    18,    19,    75,    32,
      33,   146,    12,    39,    25,    12,    14,    25,    11,    31,
     276,    32,    33,   279,    32,    33,    34,    35,    36,    37,
     286,    17,    18,    19,    20,   170,    20,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
      11,    20,    69,    70,    71,    72,    10,   313,    75,    12,
      10,    73,   318,    10,   320,    38,   322,    21,    22,    23,
      11,    83,    12,     8,    15,    16,    17,   634,    32,    33,
     627,     3,    14,    95,   219,    97,    75,    99,    17,    18,
      19,     4,     5,     6,     7,     8,     9,     3,    11,    12,
      42,    40,    60,    16,   239,    17,    18,    19,    20,   244,
     245,    24,   124,    10,     3,    10,    29,    42,    14,    42,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,    21,    22,    23,   627,    25,    42,
      12,   153,   154,   155,   634,    32,    33,   626,   742,    10,
     162,   163,     4,     5,     6,     7,     8,     9,    40,    11,
      12,    11,    75,    12,    16,    12,   178,    40,    12,    39,
     182,    21,    24,   800,     8,    25,   132,    29,     8,   849,
     192,   774,    32,    33,    34,    35,    36,    37,    -1,    41,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,   211,
      -1,    -1,    16,    -1,    -1,    -1,   341,    -1,   220,    -1,
      24,    -1,    -1,    10,    -1,    29,   228,   229,   230,    -1,
     232,   233,    -1,    75,    21,    22,    23,    41,    25,   735,
      -1,   737,    -1,    -1,   738,    32,    33,    -1,    -1,   251,
      15,    16,    17,    18,    19,   735,   736,   737,   738,    -1,
     740,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      -1,    75,    -1,    16,   276,    -1,    -1,   279,   747,   748,
      -1,    24,    -1,    -1,   286,    -1,    29,    -1,   768,    -1,
      -1,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,    -1,   774,    17,    18,    19,    20,
      -1,   313,    22,    23,    -1,    25,   318,    -1,   320,   815,
     322,   817,    32,    33,    -1,    -1,   795,    -1,    -1,   809,
     799,   800,    75,    -1,    -1,   815,    -1,   817,    -1,    -1,
      -1,   821,    -1,   823,    -1,    -1,    11,    -1,   828,    -1,
       0,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    17,    18,    19,    20,    16,    32,    33,    34,
      35,    36,    37,     0,    24,    10,    11,    -1,    -1,    29,
      -1,   627,     9,    -1,    11,    -1,    21,    -1,   634,    -1,
      25,    18,    19,    34,    35,    36,    37,    32,    33,    34,
      35,    36,    37,    -1,    31,    -1,    56,    57,    58,    -1,
      -1,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    -1,     4,     5,     6,
       7,     8,     9,    25,    11,    12,    -1,    -1,    -1,    16,
      32,    33,    34,    35,    36,    37,    73,    24,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    83,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    -1,    -1,    95,    16,
      97,    -1,    99,    -1,    -1,    -1,    -1,    24,    10,    -1,
      -1,    -1,    29,    15,    16,    17,    18,    19,    20,   735,
     736,   737,   738,     9,   740,    11,    -1,   124,    75,    15,
      16,    17,    18,    19,    20,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,    -1,
      -1,    -1,   768,    39,    -1,    -1,   153,    -1,    75,    -1,
      -1,    -1,    29,    -1,    10,   162,   163,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    25,
      -1,   178,    49,   180,   181,   182,    32,    33,    34,    35,
      36,    37,    -1,   809,    61,   192,    -1,    64,    -1,   815,
      -1,   817,    -1,    -1,    -1,   821,    -1,   823,    75,    -1,
      -1,    -1,   828,    -1,   211,     4,     5,     6,     7,     8,
       9,    10,    11,   220,    -1,    -1,    10,    16,    -1,    -1,
      -1,   228,    -1,    -1,    -1,    24,    -1,    21,     0,    -1,
      29,    25,    -1,    -1,    -1,    -1,    -1,     9,    32,    33,
      34,    35,    36,    37,   251,   627,    18,    19,    -1,    -1,
      -1,    -1,   634,    -1,    -1,   760,    -1,    -1,   763,    31,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,   276,
     277,   278,   279,    25,    -1,   780,    75,    -1,    -1,   286,
      32,    33,    34,    35,    36,    37,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,    -1,
     805,    73,   807,    -1,    -1,    -1,   313,    -1,    -1,    -1,
      -1,   318,    -1,   320,    -1,   322,    -1,     4,     5,     6,
       7,     8,     9,    95,    11,    97,    13,    99,    -1,    16,
     835,    -1,    15,    16,    17,    18,    19,    24,    -1,    -1,
      -1,    -1,    29,    26,    -1,    28,    -1,    30,    31,    -1,
      -1,    -1,   124,   735,   736,   737,   738,    -1,   740,    -1,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,     0,   147,   148,   149,    -1,    -1,
      -1,    -1,    -1,     9,    -1,    -1,   768,    -1,    75,    -1,
     162,   163,    18,    19,    15,    16,    17,    18,    19,   171,
     172,   173,   174,   175,   176,    31,    -1,   179,    -1,    30,
      31,   183,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,   193,    -1,    -1,    16,    -1,    -1,   809,    -1,    -1,
      -1,    -1,    24,   815,    -1,   817,    -1,    29,    -1,   821,
     212,   823,    -1,    -1,    -1,    -1,   828,    73,    -1,   221,
       4,     5,     6,     7,     8,     9,    -1,    11,    -1,   231,
      11,    -1,    16,    -1,    15,    16,    17,    -1,    -1,    95,
      24,    97,    -1,    99,    25,    29,    -1,    -1,    -1,   251,
      -1,    32,    33,    75,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    -1,   369,    -1,    -1,    -1,   373,    -1,   124,    -1,
     377,    -1,    -1,    -1,    -1,    -1,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
      -1,    75,    -1,    -1,    -1,    -1,    -1,   153,    -1,    15,
      16,    17,    18,    19,    20,   412,   162,   163,    -1,    -1,
      -1,   313,    -1,   420,    30,    31,   318,    -1,   320,    21,
     322,    -1,   178,    25,    -1,    -1,   182,    -1,   184,   185,
      32,    33,    34,    35,    36,    37,   192,    -1,    -1,   446,
      -1,   448,    -1,   450,    -1,   452,    -1,   454,    -1,   456,
      15,    16,    17,    18,    19,   211,    -1,    -1,   465,    -1,
      -1,    26,    -1,    -1,   220,    30,    31,    -1,    -1,    -1,
      -1,   478,   228,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    -1,    -1,    14,
     627,    16,    -1,    -1,    -1,   251,    -1,   634,    -1,    24,
      -1,   508,    -1,    -1,    29,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    -1,    -1,    -1,    16,    -1,    15,
      16,    17,    18,    19,    20,    24,    -1,    -1,    -1,    -1,
      29,    56,    57,    58,    30,    31,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,   563,   313,    -1,    -1,
      -1,    -1,   318,    -1,   320,    -1,   322,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    75,    -1,    -1,    16,
      -1,    -1,    -1,    -1,   591,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    29,    -1,    -1,     8,    -1,    -1,   735,   736,
     737,   738,    -1,   740,     4,     5,     6,     7,     8,     9,
     617,    11,    12,    -1,    -1,    -1,    16,    15,    16,    17,
      18,    19,    20,    -1,    24,    -1,    -1,    -1,    -1,    29,
      -1,   768,    15,    16,    17,    18,    19,    20,    75,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    -1,    -1,
      -1,    16,    15,    16,    17,    18,    19,    20,    -1,    24,
      -1,    -1,    -1,    -1,    29,     4,     5,     6,     7,     8,
       9,    -1,   809,    -1,    -1,    75,    -1,    16,   815,    -1,
     817,    -1,    -1,    -1,   821,    24,   823,    -1,    -1,    -1,
      29,   828,   105,    -1,   107,    -1,   109,    -1,   111,    -1,
      -1,    -1,    -1,   116,    -1,   118,    10,    -1,    -1,    -1,
      75,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,   627,    30,    31,    -1,    -1,
      -1,    -1,   634,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,   170,   171,   172,
     173,   174,   175,   176,    -1,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,
      -1,   244,   245,   735,   736,   737,   738,    -1,   740,     4,
       5,     6,     7,     8,     9,    -1,    11,     9,    -1,    11,
      -1,    16,    -1,    15,    16,    17,    18,    19,    20,    24,
      -1,    -1,    -1,    -1,    29,    -1,   768,    -1,    30,    31,
      -1,   627,    34,    35,    36,    37,    -1,    39,   634,    32,
      33,    34,    35,    36,    37,    -1,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    -1,    -1,    14,
      -1,    16,    -1,    -1,    -1,    -1,    -1,   809,    -1,    24,
      75,    -1,    -1,   815,    29,   817,    -1,    -1,    -1,   821,
      -1,   823,    -1,    -1,    -1,    -1,   828,    -1,   341,    -1,
      -1,    -1,    -1,    -1,    -1,     8,    -1,    10,    11,    12,
      -1,    56,    57,    58,    -1,    -1,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,     4,     5,     6,     7,
       8,     9,    -1,    11,    -1,    -1,    -1,    -1,    16,   735,
     736,   737,   738,    -1,   740,    -1,    24,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,     4,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    78,    79,    16,    -1,    -1,
      83,    -1,   768,    -1,    -1,    24,    89,    90,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,   107,    -1,   109,    75,   111,    -1,
      -1,    -1,    -1,   116,    -1,   118,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   809,    -1,    -1,    -1,    -1,    -1,   815,
      -1,   817,    -1,    -1,    -1,   821,    -1,   823,    -1,    -1,
      -1,    -1,   828,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,   170,   171,   172,
     173,   174,   175,   176,    -1,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,     9,
      -1,   244,   245,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    -1,    -1,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,    -1,
      -1,     3,    -1,   276,    -1,    -1,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,    73,    -1,   308,   309,   310,   311,   312,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    54,    55,    -1,    95,     9,    97,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,   341,    22,
      23,    -1,    25,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    39,    -1,    -1,    -1,
      -1,    -1,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
      13,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,   742,
      -1,    24,    -1,    -1,    -1,    10,    29,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    -1,    -1,   760,    -1,    -1,
     763,    26,    27,    28,    -1,    30,    31,    -1,    -1,   772,
      -1,    -1,    -1,    56,    57,    58,    -1,   780,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   805,    -1,   807,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    -1,    -1,    14,    -1,    16,    -1,
      -1,   251,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    29,   835,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    -1,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    56,    57,
      58,    29,    -1,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,   313,    -1,    -1,    -1,    -1,    56,    57,
      58,    -1,   322,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,     9,    10,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,     9,    39,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    25,    26,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,     9,    39,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    -1,    22,
      -1,    -1,    25,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,     9,    39,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    25,    26,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,     9,    39,    11,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    39,    -1,    -1,    -1,    -1,     9,
      -1,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    28,   742,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   760,    -1,    -1,
     763,    -1,    -1,    -1,     9,    -1,    11,    -1,    -1,   772,
      15,    16,    17,    18,    19,    20,    -1,   780,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    39,    -1,    -1,    -1,    -1,     9,
      -1,    11,   805,    -1,   807,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    10,    39,
      -1,    -1,   835,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    25,    26,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,   627,    -1,    -1,
      10,    -1,    -1,    -1,   634,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    10,    -1,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    37,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    25,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,   736,    -1,    -1,    -1,
     740,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    25,    26,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,   768,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    28,   809,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,   821,    -1,   823,    -1,    -1,    -1,    -1,   828,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    25,    15,    16,    17,    18,    19,    20,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    15,    16,    17,    18,
      19,    20,    21,    -1,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    30,
      31,    -1,    -1,    34,    35,    36,    37,    15,    16,    17,
      18,    19,    20,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    37,
      -1,    -1,    34,    35,    36,    37,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      -1,    30,    31,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    55
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
      23,    25,    32,    33,    68,    68,     9,    75,    10,    11,
     114,    10,    10,    10,    38,    40,    10,    10,    10,    10,
     107,    40,     3,    12,   116,   117,    15,    16,    17,    18,
      19,    26,    27,    28,    30,    31,    15,    16,    17,    18,
      19,    20,   116,   117,   118,   119,    21,    32,    33,    21,
      32,    33,    34,    35,    36,    37,    21,    32,    33,    34,
      35,    36,    37,    21,    25,    32,    33,    34,    35,    36,
      37,    21,    22,    23,    32,    33,   116,   116,    15,    16,
      17,    18,    19,    42,    40,   104,    75,   104,    13,    14,
      79,    62,    42,    12,   105,   110,   116,   117,   118,   119,
     123,    12,   123,    12,   123,    12,   123,     3,    13,     9,
      12,    41,   110,   123,    14,    39,   115,   105,   116,    80,
     102,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,    10,   103,   104,   110,   105,   108,
     116,   117,   105,   108,   116,   117,   105,   108,   116,   117,
     105,   116,   117,   105,   116,   117,   105,   117,   105,   112,
     113,   116,   117,   118,   119,   105,   119,   105,   119,   105,
     118,   105,   116,   105,   116,   105,   116,   105,   116,   105,
     116,   105,   108,   112,   113,   116,   117,   118,   119,   105,
     108,   112,   113,   116,   117,   118,   119,   105,   116,   117,
     118,   105,   116,   117,   118,   105,   116,   117,   118,   105,
     116,   117,   118,   105,   110,   105,   108,   105,   108,   105,
     108,   105,   108,   105,   108,   105,   108,   105,   112,   113,
     116,   117,   118,   119,   105,   108,   105,   112,   105,   112,
     105,   112,   113,   116,   117,   118,   119,   105,   108,   105,
     113,   105,   113,   105,   116,   117,   105,   116,   117,   105,
     116,   117,   105,   116,   117,   105,   116,   117,   116,   117,
     105,   112,   113,   116,   117,   118,   119,   105,   108,   105,
     116,   105,   116,   105,   116,   105,   116,   105,   116,   105,
     116,   117,   105,   116,   117,   105,   116,   117,   105,   116,
     117,   105,   116,   117,   105,   116,   117,   105,   116,   117,
     105,   116,   117,   105,   116,   117,   105,   116,   117,   105,
     116,   117,   105,   116,   117,   105,   112,   113,   116,   117,
     118,   119,   105,   108,   105,   116,   117,   105,   116,   117,
     105,   116,   117,   105,   116,   117,   105,   116,   117,   105,
     116,   117,   110,   105,   112,   113,   116,   117,   118,   119,
     105,   108,   118,   105,   118,   105,   118,   105,   118,   105,
     118,   105,   118,   105,   118,   105,   112,   113,   116,   117,
     118,   119,   105,   119,   105,   119,   105,   108,   105,   119,
     105,   119,    10,    75,   121,   124,     9,    42,   110,    10,
     110,   110,     3,    12,     3,   107,    12,   116,   117,   116,
     117,   116,   117,   116,   117,   116,   117,   116,   116,   116,
     116,   116,   116,   117,   116,   117,   116,   117,   116,   117,
     116,   117,   116,   117,   112,   116,   117,   118,   119,     9,
     112,   112,   112,   116,   117,   118,   119,   116,   117,   116,
     117,   116,   117,   116,   117,   116,   117,   116,   117,   112,
     116,   117,   118,   119,   116,   117,   116,   117,   116,   117,
     116,   117,   116,   117,   116,   117,   112,   116,   117,   118,
     119,   118,   119,   118,   118,   118,   118,   118,   118,   112,
     116,   117,   118,   119,   119,   119,   119,   119,   116,   116,
     116,   116,   116,   104,    75,    10,    41,    10,    79,    14,
       9,   104,    40,    12,    12,    12,    12,    13,     3,    14,
      56,    94,    95,   100,   124,    10,    98,    99,   124,    12,
      41,   110,    12,    41,    12,    75,    14,    10,    40,    12,
      12,    12,    11,    10,    40,    10,    98,   104,   114,    10,
      38,    12,   107,     8,    83,   104,    83,    14,     3,   104,
     123,    94,    94,    75,    14,     3,    75,    82,    10,    40,
      40,    75,    12,   110,    12,    41,    12,    41,   110,    42,
     104,   121,    82,    10,   110,    60,    92,    10,     3,    10,
      14,    42,    94,    42,    82,    98,    99,   124,    42,    12,
      12,   110,    12,   110,    12,    41,   104,    82,    10,    83,
      83,   104,   104,    75,   104,    12,    12,    12,   110,    40,
      12,   115
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
       4,     4,     5,     6,     5,     6,     1,     2,     1,     3,
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
       0,   204,   204,   205,   207,   208,   209,   213,   214,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   231,   232,   233,   234,   235,   238,   239,   243,   245,
     246,   250,   251,   252,   254,   255,   259,   263,   266,   270,
     276,   277,   281,   282,   283,   285,   286,   287,   288,   290,
     291,   292,   296,   297,   298,   299,   301,   303,   304,   305,
     307,   308,   312,   316,   317,   318,   319,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   340,   341,   345,   346,   347,   348,   349,   350,   351,
     352,   355,   356,   357,   359,   360,   362,   363,   364,   365,
     367,   368,   369,   371,   372,   374,   375,   376,   378,   379,
     380,   381,   382,   383,   384,   385,   387,   388,   389,   390,
     391,   393,   394,   395,   396,   397,   399,   400,   401,   402,
     403,   404,   405,   406,   408,   409,   410,   411,   412,   413,
     414,   415,   417,   418,   419,   421,   422,   423,   425,   426,
     427,   428,   429,   430,   431,   433,   434,   435,   436,   437,
     438,   439,   441,   442,   443,   444,   445,   446,   447,   449,
     450,   451,   452,   453,   454,   455,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     493,   494,   495,   497,   498,   499,   501,   502,   503,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   522,   523,   524,   526,   527,
     528,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   557,   558,   559,   560,   561,
     563,   564,   565,   569,   570,   571,   572,   574,   575,   577,
     578,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   595,   596,   600,   601,   603,   604,   606,
     607,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   628,   629,   630,   631,   632,
     633,   634,   635,   636,   637,   638,   639,   640,   641,   642,
     643,   644,   645,   646,   647,   648,   652,   653,   654,   655,
     656,   657,   658,   659,   660,   661,   662,   663,   664,   665,
     666,   667,   668,   669,   670,   671,   672,   673,   674,   675,
     676,   677,   678,   682,   683,   684,   685,   686,   688,   689,
     690,   691,   692,   693,   694,   696,   697,   698,   699,   700,
     701,   702,   704,   705,   706,   707,   708,   710,   711,   712,
     713,   714,   716,   717,   718,   719,   720,   722,   723,   724,
     725,   726,   728,   732,   733,   735,   736,   740,   741,   742,
     743,   744,   745,   746,   747,   748,   749,   751,   752,   756,
     757,   758,   759,   760,   761,   762,   763,   764,   765,   766,
     767,   768,   769
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
#line 4007 "frontend/parser.cpp"

#line 772 "frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    auto msg = std::to_string(scanner->loc->begin.line) + ":" + std::to_string(scanner->loc->begin.column) + ": " + err_message;
    ptc::log::error(msg);
}
