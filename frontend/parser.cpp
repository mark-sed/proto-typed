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
#line 204 "frontend/parser.yy"
                        { scanner->parseMain(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 978 "frontend/parser.cpp"
    break;

  case 4: // stmt: stmts
#line 206 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 984 "frontend/parser.cpp"
    break;

  case 5: // stmt: stmt stmts
#line 207 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 990 "frontend/parser.cpp"
    break;

  case 6: // stmt: stmt error stmts
#line 208 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 996 "frontend/parser.cpp"
    break;

  case 7: // stmts: "terminator (\\n or ;)"
#line 212 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = nullptr; }
#line 1002 "frontend/parser.cpp"
    break;

  case 8: // stmts: stmts_ne
#line 213 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1008 "frontend/parser.cpp"
    break;

  case 9: // stmts_ne: set "terminator (\\n or ;)"
#line 215 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1014 "frontend/parser.cpp"
    break;

  case 10: // stmts_ne: vardecl "terminator (\\n or ;)"
#line 216 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1020 "frontend/parser.cpp"
    break;

  case 11: // stmts_ne: vardef "terminator (\\n or ;)"
#line 217 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1026 "frontend/parser.cpp"
    break;

  case 14: // stmts_ne: if
#line 220 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1032 "frontend/parser.cpp"
    break;

  case 18: // stmts_ne: function
#line 224 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1038 "frontend/parser.cpp"
    break;

  case 20: // stmts_ne: expr "terminator (\\n or ;)"
#line 226 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1044 "frontend/parser.cpp"
    break;

  case 21: // block: "{" "}"
#line 230 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1050 "frontend/parser.cpp"
    break;

  case 22: // block: "{" stmt "}"
#line 231 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1056 "frontend/parser.cpp"
    break;

  case 23: // block: "terminator (\\n or ;)" "{" stmt "}"
#line 232 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1062 "frontend/parser.cpp"
    break;

  case 24: // block: "{" stmt "}" "terminator (\\n or ;)"
#line 233 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1068 "frontend/parser.cpp"
    break;

  case 25: // block: "terminator (\\n or ;)" "{" stmt "}" "terminator (\\n or ;)"
#line 234 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1074 "frontend/parser.cpp"
    break;

  case 26: // body: stmts_ne
#line 237 "frontend/parser.yy"
                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1080 "frontend/parser.cpp"
    break;

  case 27: // body: block
#line 238 "frontend/parser.yy"
                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1086 "frontend/parser.cpp"
    break;

  case 39: // if: "if" "(" expr ")" body else
#line 269 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::IR * > () = scanner->parseIfStmt(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1092 "frontend/parser.cpp"
    break;

  case 40: // else: "else" body
#line 275 "frontend/parser.yy"
                    { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1098 "frontend/parser.cpp"
    break;

  case 41: // else: %empty
#line 276 "frontend/parser.yy"
                    { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1104 "frontend/parser.cpp"
    break;

  case 52: // function: type "identifier" "(" ")" block
#line 295 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::IR * > () = yystack_[4].value.as < ptc::ir::IR * > (); }
#line 1110 "frontend/parser.cpp"
    break;

  case 53: // function: type "identifier" "(" funargs ")" block
#line 296 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::IR * > () = yystack_[5].value.as < ptc::ir::IR * > (); }
#line 1116 "frontend/parser.cpp"
    break;

  case 54: // function: "\"void\"" "identifier" "(" ")" block
#line 297 "frontend/parser.yy"
                                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::Expr *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1122 "frontend/parser.cpp"
    break;

  case 61: // vardecl: type "identifier"
#line 309 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1128 "frontend/parser.cpp"
    break;

  case 62: // vardef: type "identifier" "=" struct_val
#line 313 "frontend/parser.yy"
         { yylhs.value.as < ptc::ir::IR * > () = yystack_[3].value.as < ptc::ir::IR * > (); }
#line 1134 "frontend/parser.cpp"
    break;

  case 63: // vardef: type "identifier" "=" expr
#line 314 "frontend/parser.yy"
                                 { scanner->parseVarDef(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1140 "frontend/parser.cpp"
    break;

  case 66: // set: expr "++=" expr
#line 320 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1146 "frontend/parser.cpp"
    break;

  case 67: // set: expr "**=" expr
#line 321 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1152 "frontend/parser.cpp"
    break;

  case 68: // set: expr "%=" expr
#line 322 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1158 "frontend/parser.cpp"
    break;

  case 69: // set: expr "/=" expr
#line 323 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1164 "frontend/parser.cpp"
    break;

  case 70: // set: expr "*=" expr
#line 324 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1170 "frontend/parser.cpp"
    break;

  case 71: // set: expr "-=" expr
#line 325 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1176 "frontend/parser.cpp"
    break;

  case 72: // set: expr "+=" expr
#line 326 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1182 "frontend/parser.cpp"
    break;

  case 73: // set: expr "&=" expr
#line 327 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1188 "frontend/parser.cpp"
    break;

  case 74: // set: expr "|=" expr
#line 328 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1194 "frontend/parser.cpp"
    break;

  case 75: // set: expr "^=" expr
#line 329 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1200 "frontend/parser.cpp"
    break;

  case 76: // set: expr "<<=" expr
#line 330 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1206 "frontend/parser.cpp"
    break;

  case 77: // set: expr ">>=" expr
#line 331 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1212 "frontend/parser.cpp"
    break;

  case 78: // set: expr "=" expr
#line 332 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1218 "frontend/parser.cpp"
    break;

  case 79: // set: expr "=" set
#line 333 "frontend/parser.yy"
      { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1224 "frontend/parser.cpp"
    break;

  case 80: // callarglist: expr
#line 337 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseFunCallArg(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1230 "frontend/parser.cpp"
    break;

  case 81: // callarglist: callarglist "," expr
#line 338 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddFunCallArg(yystack_[2].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1236 "frontend/parser.cpp"
    break;

  case 82: // expr: expr_mat
#line 342 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = nullptr; }
#line 1242 "frontend/parser.cpp"
    break;

  case 83: // expr: expr_var
#line 343 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1248 "frontend/parser.cpp"
    break;

  case 84: // expr: expr_none
#line 344 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = nullptr; }
#line 1254 "frontend/parser.cpp"
    break;

  case 85: // expr: expr_struct
#line 345 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = nullptr; }
#line 1260 "frontend/parser.cpp"
    break;

  case 86: // expr: expr_int
#line 346 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 1266 "frontend/parser.cpp"
    break;

  case 87: // expr: expr_float
#line 347 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFloat(yystack_[0].value.as < double > ()); }
#line 1272 "frontend/parser.cpp"
    break;

  case 88: // expr: expr_str
#line 348 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseString(yystack_[0].value.as < std::string > ()); }
#line 1278 "frontend/parser.cpp"
    break;

  case 89: // expr: expr_bool
#line 349 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseBool(yystack_[0].value.as < bool > ()); }
#line 1284 "frontend/parser.cpp"
    break;

  case 90: // expr_var: "identifier"
#line 352 "frontend/parser.yy"
              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > ()); }
#line 1290 "frontend/parser.cpp"
    break;

  case 91: // expr_var: "-" "identifier"
#line 353 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1296 "frontend/parser.cpp"
    break;

  case 92: // expr_var: "(" expr_var ")"
#line 354 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1302 "frontend/parser.cpp"
    break;

  case 93: // expr_var: expr_var "(" ")"
#line 356 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[2].value.as < ptc::ir::Expr * > (), std::vector<ptc::ir::Expr *>{}); }
#line 1308 "frontend/parser.cpp"
    break;

  case 94: // expr_var: expr_var "(" callarglist ")"
#line 357 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 1314 "frontend/parser.cpp"
    break;

  case 98: // expr_var: expr_var "[" int_val "]"
#line 362 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[3].value.as < ptc::ir::Expr * > (); }
#line 1320 "frontend/parser.cpp"
    break;

  case 101: // expr_var: expr_var slice
#line 366 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1326 "frontend/parser.cpp"
    break;

  case 103: // expr_var: expr_var "." expr_var
#line 369 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1332 "frontend/parser.cpp"
    break;

  case 105: // expr_var: expr_var "**" expr_float
#line 372 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1338 "frontend/parser.cpp"
    break;

  case 106: // expr_var: expr_var "**" expr_var
#line 373 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1344 "frontend/parser.cpp"
    break;

  case 109: // expr_var: expr_var "*" expr_int
#line 377 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1350 "frontend/parser.cpp"
    break;

  case 110: // expr_var: expr_var "*" expr_float
#line 378 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1356 "frontend/parser.cpp"
    break;

  case 113: // expr_var: expr_var "*" expr_mat
#line 381 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1362 "frontend/parser.cpp"
    break;

  case 114: // expr_var: expr_var "*" expr_var
#line 382 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1368 "frontend/parser.cpp"
    break;

  case 117: // expr_var: expr_var "/" expr_int
#line 386 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1374 "frontend/parser.cpp"
    break;

  case 118: // expr_var: expr_var "/" expr_float
#line 387 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1380 "frontend/parser.cpp"
    break;

  case 119: // expr_var: expr_var "/" expr_var
#line 388 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1386 "frontend/parser.cpp"
    break;

  case 122: // expr_var: expr_var "%" expr_int
#line 392 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1392 "frontend/parser.cpp"
    break;

  case 123: // expr_var: expr_var "%" expr_float
#line 393 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1398 "frontend/parser.cpp"
    break;

  case 124: // expr_var: expr_var "%" expr_var
#line 394 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1404 "frontend/parser.cpp"
    break;

  case 125: // expr_var: expr_int "+" expr_var
#line 396 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1410 "frontend/parser.cpp"
    break;

  case 126: // expr_var: expr_float "+" expr_var
#line 397 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1416 "frontend/parser.cpp"
    break;

  case 127: // expr_var: expr_var "+" expr_int
#line 398 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1422 "frontend/parser.cpp"
    break;

  case 128: // expr_var: expr_var "+" expr_float
#line 399 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1428 "frontend/parser.cpp"
    break;

  case 130: // expr_var: expr_var "+" expr_mat
#line 401 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1434 "frontend/parser.cpp"
    break;

  case 132: // expr_var: expr_var "+" expr_var
#line 403 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1440 "frontend/parser.cpp"
    break;

  case 135: // expr_var: expr_var "-" expr_int
#line 407 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1446 "frontend/parser.cpp"
    break;

  case 136: // expr_var: expr_var "-" expr_float
#line 408 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1452 "frontend/parser.cpp"
    break;

  case 138: // expr_var: expr_var "-" expr_mat
#line 410 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1458 "frontend/parser.cpp"
    break;

  case 140: // expr_var: expr_var "-" expr_var
#line 412 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1464 "frontend/parser.cpp"
    break;

  case 142: // expr_var: expr_var "<<" expr_int
#line 415 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1470 "frontend/parser.cpp"
    break;

  case 143: // expr_var: expr_var "<<" expr_var
#line 416 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1476 "frontend/parser.cpp"
    break;

  case 145: // expr_var: expr_var ">>" expr_int
#line 419 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1482 "frontend/parser.cpp"
    break;

  case 146: // expr_var: expr_var ">>" expr_var
#line 420 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1488 "frontend/parser.cpp"
    break;

  case 150: // expr_var: expr_var ">" expr_int
#line 425 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1494 "frontend/parser.cpp"
    break;

  case 151: // expr_var: expr_var ">" expr_float
#line 426 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1500 "frontend/parser.cpp"
    break;

  case 152: // expr_var: expr_var ">" expr_str
#line 427 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1506 "frontend/parser.cpp"
    break;

  case 153: // expr_var: expr_var ">" expr_var
#line 428 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1512 "frontend/parser.cpp"
    break;

  case 157: // expr_var: expr_var ">=" expr_int
#line 433 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1518 "frontend/parser.cpp"
    break;

  case 158: // expr_var: expr_var ">=" expr_float
#line 434 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1524 "frontend/parser.cpp"
    break;

  case 159: // expr_var: expr_var ">=" expr_str
#line 435 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1530 "frontend/parser.cpp"
    break;

  case 160: // expr_var: expr_var ">=" expr_var
#line 436 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1536 "frontend/parser.cpp"
    break;

  case 164: // expr_var: expr_var "<" expr_int
#line 441 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1542 "frontend/parser.cpp"
    break;

  case 165: // expr_var: expr_var "<" expr_float
#line 442 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1548 "frontend/parser.cpp"
    break;

  case 166: // expr_var: expr_var "<" expr_str
#line 443 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1554 "frontend/parser.cpp"
    break;

  case 167: // expr_var: expr_var "<" expr_var
#line 444 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1560 "frontend/parser.cpp"
    break;

  case 171: // expr_var: expr_var "<=" expr_int
#line 449 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1566 "frontend/parser.cpp"
    break;

  case 172: // expr_var: expr_var "<=" expr_float
#line 450 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1572 "frontend/parser.cpp"
    break;

  case 173: // expr_var: expr_var "<=" expr_str
#line 451 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1578 "frontend/parser.cpp"
    break;

  case 174: // expr_var: expr_var "<=" expr_var
#line 452 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1584 "frontend/parser.cpp"
    break;

  case 182: // expr_var: expr_var "==" expr_int
#line 461 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1590 "frontend/parser.cpp"
    break;

  case 183: // expr_var: expr_var "==" expr_float
#line 462 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1596 "frontend/parser.cpp"
    break;

  case 184: // expr_var: expr_var "==" expr_str
#line 463 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1602 "frontend/parser.cpp"
    break;

  case 185: // expr_var: expr_var "==" expr_bool
#line 464 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1608 "frontend/parser.cpp"
    break;

  case 186: // expr_var: expr_var "==" expr_none
#line 465 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1614 "frontend/parser.cpp"
    break;

  case 187: // expr_var: expr_var "==" expr_struct
#line 466 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1620 "frontend/parser.cpp"
    break;

  case 189: // expr_var: expr_var "==" expr_mat
#line 468 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1626 "frontend/parser.cpp"
    break;

  case 191: // expr_var: expr_var "==" expr_var
#line 470 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1632 "frontend/parser.cpp"
    break;

  case 199: // expr_var: expr_var "!=" expr_int
#line 479 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1638 "frontend/parser.cpp"
    break;

  case 200: // expr_var: expr_var "!=" expr_float
#line 480 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1644 "frontend/parser.cpp"
    break;

  case 201: // expr_var: expr_var "!=" expr_str
#line 481 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1650 "frontend/parser.cpp"
    break;

  case 202: // expr_var: expr_var "!=" expr_bool
#line 482 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1656 "frontend/parser.cpp"
    break;

  case 203: // expr_var: expr_var "!=" expr_none
#line 483 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1662 "frontend/parser.cpp"
    break;

  case 204: // expr_var: expr_var "!=" expr_struct
#line 484 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1668 "frontend/parser.cpp"
    break;

  case 206: // expr_var: expr_var "!=" expr_mat
#line 486 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1674 "frontend/parser.cpp"
    break;

  case 208: // expr_var: expr_var "!=" expr_var
#line 488 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1680 "frontend/parser.cpp"
    break;

  case 210: // expr_var: expr_var "&" expr_int
#line 491 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1686 "frontend/parser.cpp"
    break;

  case 211: // expr_var: expr_var "&" expr_var
#line 492 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1692 "frontend/parser.cpp"
    break;

  case 213: // expr_var: expr_var "^" expr_int
#line 495 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1698 "frontend/parser.cpp"
    break;

  case 214: // expr_var: expr_var "^" expr_var
#line 496 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1704 "frontend/parser.cpp"
    break;

  case 216: // expr_var: expr_var "|" expr_int
#line 499 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1710 "frontend/parser.cpp"
    break;

  case 217: // expr_var: expr_var "|" expr_var
#line 500 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1716 "frontend/parser.cpp"
    break;

  case 232: // expr_var: expr_var "in" expr_str
#line 516 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1722 "frontend/parser.cpp"
    break;

  case 233: // expr_var: expr_var "in" expr_var
#line 517 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1728 "frontend/parser.cpp"
    break;

  case 235: // expr_var: expr_var "and" expr_bool
#line 520 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1734 "frontend/parser.cpp"
    break;

  case 236: // expr_var: expr_var "and" expr_var
#line 521 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1740 "frontend/parser.cpp"
    break;

  case 238: // expr_var: expr_var "or" expr_bool
#line 524 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1746 "frontend/parser.cpp"
    break;

  case 239: // expr_var: expr_var "or" expr_var
#line 525 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1752 "frontend/parser.cpp"
    break;

  case 257: // expr_var: expr_var "++" expr_int
#line 544 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1758 "frontend/parser.cpp"
    break;

  case 258: // expr_var: expr_var "++" expr_float
#line 545 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1764 "frontend/parser.cpp"
    break;

  case 259: // expr_var: expr_var "++" expr_str
#line 546 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1770 "frontend/parser.cpp"
    break;

  case 260: // expr_var: expr_var "++" expr_bool
#line 547 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1776 "frontend/parser.cpp"
    break;

  case 261: // expr_var: expr_var "++" expr_none
#line 548 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1782 "frontend/parser.cpp"
    break;

  case 262: // expr_var: expr_var "++" expr_struct
#line 549 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1788 "frontend/parser.cpp"
    break;

  case 263: // expr_var: expr_var "++" expr_var
#line 550 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1794 "frontend/parser.cpp"
    break;

  case 300: // expr_int: "int"
#line 608 "frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 1800 "frontend/parser.cpp"
    break;

  case 301: // expr_int: "-" expr_int
#line 609 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 1806 "frontend/parser.cpp"
    break;

  case 302: // expr_int: "(" expr_int ")"
#line 610 "frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 1812 "frontend/parser.cpp"
    break;

  case 303: // expr_int: "~" expr_int
#line 611 "frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 1818 "frontend/parser.cpp"
    break;

  case 304: // expr_int: expr_int "*" expr_int
#line 612 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 1824 "frontend/parser.cpp"
    break;

  case 305: // expr_int: expr_int "/" expr_int
#line 613 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 1830 "frontend/parser.cpp"
    break;

  case 306: // expr_int: expr_int "%" expr_int
#line 614 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 1836 "frontend/parser.cpp"
    break;

  case 307: // expr_int: expr_int "-" expr_int
#line 615 "frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 1842 "frontend/parser.cpp"
    break;

  case 308: // expr_int: expr_int "+" expr_int
#line 616 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 1848 "frontend/parser.cpp"
    break;

  case 309: // expr_int: expr_int "<<" expr_int
#line 617 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 1854 "frontend/parser.cpp"
    break;

  case 310: // expr_int: expr_int ">>" expr_int
#line 618 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 1860 "frontend/parser.cpp"
    break;

  case 311: // expr_int: expr_int "&" expr_int
#line 619 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 1866 "frontend/parser.cpp"
    break;

  case 312: // expr_int: expr_int "^" expr_int
#line 620 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 1872 "frontend/parser.cpp"
    break;

  case 313: // expr_int: expr_int "|" expr_int
#line 621 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 1878 "frontend/parser.cpp"
    break;

  case 314: // expr_float: "float"
#line 625 "frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 1884 "frontend/parser.cpp"
    break;

  case 315: // expr_float: "-" expr_float
#line 626 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 1890 "frontend/parser.cpp"
    break;

  case 316: // expr_float: "(" expr_float ")"
#line 627 "frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 1896 "frontend/parser.cpp"
    break;

  case 317: // expr_float: expr_float "**" expr_float
#line 628 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 1902 "frontend/parser.cpp"
    break;

  case 318: // expr_float: expr_float "**" expr_int
#line 629 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 1908 "frontend/parser.cpp"
    break;

  case 319: // expr_float: expr_int "**" expr_float
#line 630 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 1914 "frontend/parser.cpp"
    break;

  case 320: // expr_float: expr_float "*" expr_float
#line 631 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 1920 "frontend/parser.cpp"
    break;

  case 321: // expr_float: expr_float "*" expr_int
#line 632 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 1926 "frontend/parser.cpp"
    break;

  case 322: // expr_float: expr_int "*" expr_float
#line 633 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 1932 "frontend/parser.cpp"
    break;

  case 323: // expr_float: expr_float "/" expr_float
#line 634 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 1938 "frontend/parser.cpp"
    break;

  case 324: // expr_float: expr_float "/" expr_int
#line 635 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 1944 "frontend/parser.cpp"
    break;

  case 325: // expr_float: expr_int "/" expr_float
#line 636 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 1950 "frontend/parser.cpp"
    break;

  case 326: // expr_float: expr_float "%" expr_float
#line 637 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 1956 "frontend/parser.cpp"
    break;

  case 327: // expr_float: expr_float "%" expr_int
#line 638 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 1962 "frontend/parser.cpp"
    break;

  case 328: // expr_float: expr_int "%" expr_float
#line 639 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 1968 "frontend/parser.cpp"
    break;

  case 329: // expr_float: expr_float "-" expr_float
#line 640 "frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 1974 "frontend/parser.cpp"
    break;

  case 330: // expr_float: expr_float "-" expr_int
#line 641 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 1980 "frontend/parser.cpp"
    break;

  case 331: // expr_float: expr_int "-" expr_float
#line 642 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 1986 "frontend/parser.cpp"
    break;

  case 332: // expr_float: expr_float "+" expr_float
#line 643 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 1992 "frontend/parser.cpp"
    break;

  case 333: // expr_float: expr_float "+" expr_int
#line 644 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 1998 "frontend/parser.cpp"
    break;

  case 334: // expr_float: expr_int "+" expr_float
#line 645 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 2004 "frontend/parser.cpp"
    break;

  case 335: // expr_str: "string"
#line 649 "frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2010 "frontend/parser.cpp"
    break;

  case 336: // expr_str: "(" expr_str ")"
#line 650 "frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 2016 "frontend/parser.cpp"
    break;

  case 337: // expr_str: expr_str "++" expr_str
#line 651 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 2022 "frontend/parser.cpp"
    break;

  case 338: // expr_str: expr_str "++" expr_int
#line 652 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 2028 "frontend/parser.cpp"
    break;

  case 339: // expr_str: expr_str "++" expr_float
#line 653 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 2034 "frontend/parser.cpp"
    break;

  case 340: // expr_str: expr_str "++" expr_bool
#line 654 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2040 "frontend/parser.cpp"
    break;

  case 341: // expr_str: expr_str "++" expr_none
#line 655 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 2046 "frontend/parser.cpp"
    break;

  case 342: // expr_str: expr_int "++" expr_str
#line 656 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 2052 "frontend/parser.cpp"
    break;

  case 343: // expr_str: expr_int "++" expr_int
#line 657 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 2058 "frontend/parser.cpp"
    break;

  case 344: // expr_str: expr_int "++" expr_float
#line 658 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 2064 "frontend/parser.cpp"
    break;

  case 345: // expr_str: expr_int "++" expr_bool
#line 659 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2070 "frontend/parser.cpp"
    break;

  case 346: // expr_str: expr_int "++" expr_none
#line 660 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 2076 "frontend/parser.cpp"
    break;

  case 347: // expr_str: expr_float "++" expr_str
#line 661 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 2082 "frontend/parser.cpp"
    break;

  case 348: // expr_str: expr_float "++" expr_int
#line 662 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 2088 "frontend/parser.cpp"
    break;

  case 349: // expr_str: expr_float "++" expr_float
#line 663 "frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 2094 "frontend/parser.cpp"
    break;

  case 350: // expr_str: expr_float "++" expr_bool
#line 664 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2100 "frontend/parser.cpp"
    break;

  case 351: // expr_str: expr_float "++" expr_none
#line 665 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 2106 "frontend/parser.cpp"
    break;

  case 352: // expr_str: expr_bool "++" expr_str
#line 666 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 2112 "frontend/parser.cpp"
    break;

  case 353: // expr_str: expr_bool "++" expr_int
#line 667 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 2118 "frontend/parser.cpp"
    break;

  case 354: // expr_str: expr_bool "++" expr_float
#line 668 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 2124 "frontend/parser.cpp"
    break;

  case 355: // expr_str: expr_bool "++" expr_bool
#line 669 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2130 "frontend/parser.cpp"
    break;

  case 356: // expr_str: expr_bool "++" expr_none
#line 670 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 2136 "frontend/parser.cpp"
    break;

  case 357: // expr_str: expr_none "++" expr_str
#line 671 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 2142 "frontend/parser.cpp"
    break;

  case 358: // expr_str: expr_none "++" expr_int
#line 672 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 2148 "frontend/parser.cpp"
    break;

  case 359: // expr_str: expr_none "++" expr_float
#line 673 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 2154 "frontend/parser.cpp"
    break;

  case 360: // expr_str: expr_none "++" expr_bool
#line 674 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2160 "frontend/parser.cpp"
    break;

  case 361: // expr_str: expr_none "++" expr_none
#line 675 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 2166 "frontend/parser.cpp"
    break;

  case 362: // expr_bool: "bool"
#line 679 "frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 2172 "frontend/parser.cpp"
    break;

  case 363: // expr_bool: "(" expr_bool ")"
#line 680 "frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 2178 "frontend/parser.cpp"
    break;

  case 364: // expr_bool: "not" expr_bool
#line 681 "frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 2184 "frontend/parser.cpp"
    break;

  case 365: // expr_bool: expr_bool "or" expr_bool
#line 682 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 2190 "frontend/parser.cpp"
    break;

  case 366: // expr_bool: expr_bool "and" expr_bool
#line 683 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 2196 "frontend/parser.cpp"
    break;

  case 367: // expr_bool: expr_bool "==" expr_bool
#line 685 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 2202 "frontend/parser.cpp"
    break;

  case 368: // expr_bool: expr_int "==" expr_int
#line 686 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 2208 "frontend/parser.cpp"
    break;

  case 369: // expr_bool: expr_int "==" expr_float
#line 687 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 2214 "frontend/parser.cpp"
    break;

  case 370: // expr_bool: expr_float "==" expr_float
#line 688 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 2220 "frontend/parser.cpp"
    break;

  case 371: // expr_bool: expr_float "==" expr_int
#line 689 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 2226 "frontend/parser.cpp"
    break;

  case 372: // expr_bool: expr_str "==" expr_str
#line 690 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 2232 "frontend/parser.cpp"
    break;

  case 373: // expr_bool: expr_none "==" expr_none
#line 691 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 2238 "frontend/parser.cpp"
    break;

  case 374: // expr_bool: expr_bool "!=" expr_bool
#line 693 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 2244 "frontend/parser.cpp"
    break;

  case 375: // expr_bool: expr_int "!=" expr_int
#line 694 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 2250 "frontend/parser.cpp"
    break;

  case 376: // expr_bool: expr_int "!=" expr_float
#line 695 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 2256 "frontend/parser.cpp"
    break;

  case 377: // expr_bool: expr_float "!=" expr_float
#line 696 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 2262 "frontend/parser.cpp"
    break;

  case 378: // expr_bool: expr_float "!=" expr_int
#line 697 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 2268 "frontend/parser.cpp"
    break;

  case 379: // expr_bool: expr_str "!=" expr_str
#line 698 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 2274 "frontend/parser.cpp"
    break;

  case 380: // expr_bool: expr_none "!=" expr_none
#line 699 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 2280 "frontend/parser.cpp"
    break;

  case 381: // expr_bool: expr_int ">" expr_int
#line 701 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 2286 "frontend/parser.cpp"
    break;

  case 382: // expr_bool: expr_int ">" expr_float
#line 702 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 2292 "frontend/parser.cpp"
    break;

  case 383: // expr_bool: expr_float ">" expr_float
#line 703 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 2298 "frontend/parser.cpp"
    break;

  case 384: // expr_bool: expr_float ">" expr_int
#line 704 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 2304 "frontend/parser.cpp"
    break;

  case 385: // expr_bool: expr_str ">" expr_str
#line 705 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 2310 "frontend/parser.cpp"
    break;

  case 386: // expr_bool: expr_int "<" expr_int
#line 707 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 2316 "frontend/parser.cpp"
    break;

  case 387: // expr_bool: expr_int "<" expr_float
#line 708 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 2322 "frontend/parser.cpp"
    break;

  case 388: // expr_bool: expr_float "<" expr_float
#line 709 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 2328 "frontend/parser.cpp"
    break;

  case 389: // expr_bool: expr_float "<" expr_int
#line 710 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 2334 "frontend/parser.cpp"
    break;

  case 390: // expr_bool: expr_str "<" expr_str
#line 711 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 2340 "frontend/parser.cpp"
    break;

  case 391: // expr_bool: expr_int ">=" expr_int
#line 713 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 2346 "frontend/parser.cpp"
    break;

  case 392: // expr_bool: expr_int ">=" expr_float
#line 714 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 2352 "frontend/parser.cpp"
    break;

  case 393: // expr_bool: expr_float ">=" expr_float
#line 715 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 2358 "frontend/parser.cpp"
    break;

  case 394: // expr_bool: expr_float ">=" expr_int
#line 716 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 2364 "frontend/parser.cpp"
    break;

  case 395: // expr_bool: expr_str ">=" expr_str
#line 717 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 2370 "frontend/parser.cpp"
    break;

  case 396: // expr_bool: expr_int "<=" expr_int
#line 719 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 2376 "frontend/parser.cpp"
    break;

  case 397: // expr_bool: expr_int "<=" expr_float
#line 720 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 2382 "frontend/parser.cpp"
    break;

  case 398: // expr_bool: expr_float "<=" expr_float
#line 721 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 2388 "frontend/parser.cpp"
    break;

  case 399: // expr_bool: expr_float "<=" expr_int
#line 722 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 2394 "frontend/parser.cpp"
    break;

  case 400: // expr_bool: expr_str "<=" expr_str
#line 723 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 2400 "frontend/parser.cpp"
    break;

  case 401: // expr_bool: expr_str "in" expr_str
#line 725 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[0].value.as < std::string > ().find(yystack_[2].value.as < std::string > ()) != std::string::npos; }
#line 2406 "frontend/parser.cpp"
    break;

  case 418: // type: "\"int\"" "?"
#line 753 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2412 "frontend/parser.cpp"
    break;

  case 419: // type: "\"float\"" "?"
#line 754 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2418 "frontend/parser.cpp"
    break;

  case 420: // type: "\"string\"" "?"
#line 755 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2424 "frontend/parser.cpp"
    break;

  case 421: // type: "\"bool\"" "?"
#line 756 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2430 "frontend/parser.cpp"
    break;

  case 422: // type: "identifier" "?"
#line 757 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2436 "frontend/parser.cpp"
    break;

  case 423: // type: funtype "?"
#line 758 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2442 "frontend/parser.cpp"
    break;

  case 424: // type: mattype "?"
#line 759 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2448 "frontend/parser.cpp"
    break;

  case 425: // type: "\"int\""
#line 760 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("int"); }
#line 2454 "frontend/parser.cpp"
    break;

  case 426: // type: "\"float\""
#line 761 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("float"); }
#line 2460 "frontend/parser.cpp"
    break;

  case 427: // type: "\"string\""
#line 762 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("string"); }
#line 2466 "frontend/parser.cpp"
    break;

  case 428: // type: "\"bool\""
#line 763 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("bool"); }
#line 2472 "frontend/parser.cpp"
    break;

  case 429: // type: "identifier"
#line 764 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[0].value.as < std::string > ()); }
#line 2478 "frontend/parser.cpp"
    break;

  case 430: // type: funtype
#line 765 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2484 "frontend/parser.cpp"
    break;

  case 431: // type: mattype
#line 766 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2490 "frontend/parser.cpp"
    break;


#line 2494 "frontend/parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -723;

  const short  Parser ::yytable_ninf_ = -430;

  const short
   Parser ::yypact_[] =
  {
    1433,  -723,  -723,  -723,  -723,  -723,  -723,  -723,  2196,    29,
      52,  1622,   325,   -32,   -15,     6,    77,    94,  2287,  2404,
    -723,  -723,   -12,    -4,     2,    12,    54,    49,    85,   311,
     172,   839,  -723,  -723,   173,   176,  -723,  -723,  -723,  -723,
    -723,  -723,  -723,   190,   194,   223,  1074,  2494,  -723,   214,
    -723,   293,   523,  2606,  3025,  1031,   602,   185,   195,     7,
     267,   145,  2465,   301,   214,   305,   119,   293,   523,  2781,
    2846,   796,   629,  2404,  -723,   145,   280,    63,   477,   477,
    -723,  -723,  -723,  1941,   312,  2899,  3059,  1948,  -723,   325,
     325,  -723,   281,  -723,   287,  2404,   256,  2404,   333,  2317,
    -723,  -723,   295,  -723,   319,   331,  -723,   493,  -723,   572,
    -723,   986,  -723,   108,   369,   396,   157,  2404,  -723,  -723,
    -723,  -723,  -723,  2390,  -723,  -723,  -723,  -723,  -723,  -723,
    -723,  2404,  2404,  2404,  2404,  2404,  2404,  2404,  2404,  2404,
    2404,  2404,  2404,  2404,  1240,  1354,  2404,  2404,  2404,  2404,
    2404,  2404,  2404,  2404,  2404,  2404,  2404,  2404,  2404,  2404,
    2404,  2404,  2404,  2404,  2404,  2404,  2404,  2404,  -723,  1354,
    2404,  2404,  2404,  2404,  2404,  2404,  -723,  2404,  2404,  2404,
    2404,  2404,  2404,  2404,  2404,  2404,  2404,  2404,  2404,  2404,
     477,  2404,  2404,  2404,  2404,  2404,  2404,  2404,  2404,  2404,
    2404,  2404,  2404,  2404,  2404,  2404,  2404,  2404,  2404,  2404,
    2404,  2404,  2404,  2404,  2404,  2404,  2404,  2404,  2404,  2404,
    2404,  2404,  2404,  2404,  2404,  2404,  2404,  2404,  2404,  2404,
    2404,  2404,  2404,  -723,  -723,    45,    35,  -723,  1354,   370,
    -723,  -723,  -723,  2404,  2404,  -723,  -723,  -723,  -723,   107,
      43,   375,  -723,  1291,  1117,   477,   477,   477,   477,   477,
     325,   325,   325,   325,   325,   477,   477,   477,   477,   477,
     477,  2809,  2874,   848,   239,  1622,   410,   410,  1622,   477,
     477,   477,   477,   477,   477,  1622,   477,   477,   477,   477,
     477,   477,  1622,  1622,  1622,  1622,  1622,  1622,  1622,  1622,
    1622,  1622,  1622,  1622,  1622,  1754,  -723,   325,   325,   325,
     325,   325,  2404,   307,   374,   352,   403,  2390,  -723,  1788,
     400,  2404,  -723,  2494,   382,  2606,  3025,  1031,   602,   414,
    -723,   429,  -723,   452,  -723,   463,   464,    98,   165,  -723,
     668,   180,   466,  -723,   413,   482,   265,  2606,  -723,  -723,
    2187,  -723,  -723,  -723,  -723,  -723,  -723,  -723,  -723,  -723,
    -723,  -723,  -723,  -723,    88,  -723,    72,   372,   221,   772,
     817,   372,   221,   772,   817,   234,   479,   471,   472,   234,
     471,   472,   234,   471,   472,   234,   472,  2523,   491,   528,
    2933,  3082,  1160,   570,  2581,   573,  2552,   447,  2645,   678,
    2753,  3036,  2680,  2979,  2724,  3002,   713,   903,   713,   903,
     431,   419,  -723,  -723,  3093,  1356,   478,  -723,   431,   419,
    -723,  -723,  3093,  1356,   478,  -723,  1256,  1790,   963,   492,
    1256,  1790,   963,   492,  1256,  1790,   963,   492,  1256,  1790,
     963,   492,   265,   133,   372,   221,   372,   221,   234,   479,
    2645,   412,   431,   419,   431,   419,  2523,   491,   528,  2933,
    3082,  1160,   570,  2645,   412,   431,  -723,   431,  -723,  2523,
     491,   528,  2933,  3082,  1160,   570,  2645,   412,   431,  -723,
     431,  -723,   372,   772,   817,   372,   772,   817,   234,   471,
     472,   234,   471,   472,   234,   471,   472,   729,   490,  2523,
     491,   528,  2933,  3082,  1160,   570,  2645,   412,  2753,  3036,
    2680,  2979,  2724,  3002,   713,   903,   713,   903,   431,  3093,
    1356,   431,  3093,  1356,  1256,  1790,   963,  1256,  1790,   963,
    1256,  1790,   963,  1256,  1790,   963,   372,   772,   817,   372,
     772,   817,   234,   471,   472,   234,   471,   472,   234,   471,
     472,   234,   471,   472,  2523,   491,   528,  2933,  3082,  1160,
     570,  2645,   412,   431,  3093,  1356,   431,  3093,  1356,  1256,
    1790,   963,  1256,  1790,   963,  1256,  1790,   963,  1256,  1790,
     963,   507,  2523,   491,   528,  2933,  3082,  1160,   570,  2645,
     412,   678,   431,   478,   431,   478,  1256,   492,  1256,   492,
    1256,   492,  1256,   492,  2523,   491,   528,  2933,  3082,  1160,
     570,  2581,   573,  2552,   447,  2645,   412,   431,  -723,   431,
    -723,  -723,    58,   510,    62,   238,  1463,   170,  -723,   511,
     503,   530,  -723,  2404,  -723,  -723,   834,   944,   834,   944,
     471,   490,   471,   490,   471,   490,  1971,  1146,  1892,   683,
     683,   834,   944,   834,   944,   471,   490,   471,   490,   471,
     490,   471,   490,   406,  2956,  3116,  1448,   326,   535,  -723,
    -723,   406,  2956,  3116,  1448,   326,  1944,  1335,  1944,  1335,
    1944,  1335,  1944,  1335,  1944,  1335,  1944,  1335,   406,  2956,
    3116,  1448,   326,  1944,  1335,  1944,  1335,  1944,  1335,  1944,
    1335,  1944,  1335,  1944,  1335,   406,  2956,  3116,  1448,   326,
    1365,   330,   994,   994,  -723,  -723,  -723,  -723,   406,  2956,
    3116,  1448,   326,   441,   399,  -723,  -723,    89,    89,  -723,
    -723,  -723,  -723,  -723,  2287,  2404,  2287,  1863,   543,  2404,
    -723,  2404,  -723,  -723,  -723,  -723,    18,    18,  -723,   483,
     533,   548,  -723,    16,   215,   115,   517,    21,  -723,  1547,
     182,  -723,   936,  -723,   520,  -723,  -723,  2404,  -723,  -723,
    -723,  1561,  -723,   712,   215,   143,  -723,  -723,  -723,  2404,
    -723,  -723,   267,   504,   557,  -723,   566,  -723,   562,  -723,
     560,  -723,   540,  -723,    18,   545,  -723,   215,   712,   712,
     547,  -723,   585,  -723,  1575,  -723,  1750,   183,  2404,  -723,
    -723,  -723,   215,   575,  2287,  -723,  2287,  -723,  -723,  -723,
    2404,  -723,  2404,  -723,   564,   517,    30,  2404,  -723,  -723,
     588,  -723,   609,  -723,  1877,   582,  -723,  -723,  -723,  -723,
    -723,  -723,   547,  -723,  -723,  -723,  -723,   619,   593,  -723,
    -723
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     7,   300,   314,   335,   362,   292,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      31,    32,     0,   425,   426,   427,   428,     0,     0,    90,
       0,     0,     4,     8,     0,     0,    33,    13,    15,    16,
      14,    17,    18,     0,     0,     0,     0,    83,   272,    82,
     273,    84,    85,    86,    87,    88,    89,   430,   431,     0,
     292,    90,   279,   272,     0,   273,     0,     0,     0,   278,
       0,     0,     0,     0,   264,    90,   269,     0,     0,     0,
      91,   301,   315,     0,     0,     0,     0,     0,   364,     0,
       0,   303,     0,    29,    28,     0,     0,     0,     0,     0,
      26,    27,     0,    35,     0,     0,   418,     0,   419,     0,
     420,     0,   421,     0,     0,     0,     0,     0,   422,   100,
     294,     1,     3,     0,     5,    12,    19,    10,    11,     9,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   101,     0,
       0,     0,     0,     0,     0,     0,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   423,   424,     0,    61,   293,     0,   294,
      92,   274,   275,     0,     0,   302,   316,   336,   363,     0,
       0,     0,   265,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   301,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,   409,   279,   416,   278,     0,     0,     0,     0,
     411,     0,   413,     0,   415,     0,     0,     0,     0,   407,
       0,     0,     0,   296,     0,     0,   102,     0,     6,    79,
      78,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    93,     0,    80,     0,   132,   130,   127,
     128,   140,   138,   135,   136,   114,   113,   109,   110,   119,
     117,   118,   124,   122,   123,   106,   105,   263,   261,   262,
     257,   258,   259,   260,   236,   235,   239,   238,   233,   232,
     211,   210,   217,   216,   214,   213,   143,   142,   146,   145,
     191,   189,   186,   187,   182,   183,   184,   185,   208,   206,
     203,   204,   199,   200,   201,   202,   153,   150,   151,   152,
     167,   164,   165,   166,   160,   157,   158,   159,   174,   171,
     172,   173,   103,     0,   131,   129,   139,   137,   112,   111,
     231,   224,   190,   188,   207,   205,   255,   361,   244,   358,
     359,   357,   360,   229,   222,   179,   373,   196,   380,   256,
     249,   250,   245,   246,   247,   248,   230,   223,   181,   180,
     198,   197,   125,   308,   334,   133,   307,   331,   107,   304,
     322,   115,   305,   325,   120,   306,   328,     0,   319,   251,
     346,   240,   343,   344,   342,   345,   225,   218,   209,   311,
     215,   313,   212,   312,   141,   309,   144,   310,   175,   368,
     369,   192,   375,   376,   147,   381,   382,   161,   386,   387,
     154,   391,   392,   168,   396,   397,   126,   333,   332,   134,
     330,   329,   108,   321,   320,   116,   324,   323,   121,   327,
     326,   104,   318,   317,   252,   351,   241,   348,   349,   347,
     350,   226,   219,   176,   371,   370,   193,   378,   377,   148,
     384,   383,   162,   389,   388,   155,   394,   393,   169,   399,
     398,     0,   253,   341,   242,   338,   339,   337,   340,   227,
     220,   401,   177,   372,   194,   379,   149,   385,   163,   390,
     156,   395,   170,   400,   254,   356,   243,   353,   354,   352,
     355,   234,   366,   237,   365,   228,   221,   178,   367,   195,
     374,   403,   429,     0,   404,     0,     0,     0,   295,     0,
       0,     0,   266,     0,   270,   267,   308,   334,   307,   331,
     304,   322,   305,   325,   306,   328,   311,   313,   312,   309,
     310,   333,   332,   330,   329,   321,   320,   324,   323,   327,
     326,   318,   317,   361,   358,   359,   357,   360,     0,   373,
     380,   346,   343,   344,   342,   345,   368,   369,   375,   376,
     381,   382,   386,   387,   391,   392,   396,   397,   351,   348,
     349,   347,   350,   371,   370,   378,   377,   384,   383,   389,
     388,   394,   393,   399,   398,   341,   338,   339,   337,   340,
     401,     0,   372,   379,   385,   390,   395,   400,   356,   353,
     354,   352,   355,   366,   365,   367,   374,   308,   307,   304,
     305,   306,    65,    30,     0,     0,     0,     0,    22,     0,
      64,     0,   408,   410,   412,   414,     0,    45,    42,     0,
       0,     0,    49,     0,     0,     0,    57,     0,   280,     0,
       0,    97,     0,   406,     0,   297,    94,     0,    98,    96,
      95,     0,   402,     0,     0,     0,    63,    62,   276,     0,
     268,   271,     0,    41,     0,    37,    23,    24,     0,   417,
       0,    46,     0,    43,    47,    61,    54,     0,     0,     0,
      56,   284,     0,   282,     0,   281,     0,     0,     0,    81,
     405,    52,     0,     0,     0,    39,     0,    25,    38,    44,
       0,    48,     0,    55,    58,    60,     0,     0,   287,   286,
       0,   285,     0,   283,     0,   298,    53,   277,    40,    36,
      51,    50,     0,    59,   290,   289,   288,     0,     0,   291,
     299
  };

  const short
   Parser ::yypgoto_[] =
  {
    -723,  -723,   -95,   -14,   -16,  -712,  -722,  -723,  -723,  -723,
    -723,  -723,  -723,  -723,  -723,  -723,  -723,  -718,  -723,  -723,
    -620,  -163,  -331,  -723,   509,  -723,  2120,  1508,   633,   -70,
    1008,   634,   425,   958,   794,  1205,   -60,  -204,  1888,     0,
     233,   476,  -723,  -128,  -723,   -85,  -208
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    30,    31,    32,    33,   101,   102,    34,    94,    35,
      36,    37,    38,    39,    40,   815,    41,   750,   751,    42,
     755,   756,    43,    44,    45,   364,    46,    47,    48,    77,
      64,    50,   324,   168,    67,    68,   120,   345,    53,   326,
     327,   328,    57,   623,    58,   342,    59
  };

  const short
   Parser ::yytable_[] =
  {
      54,   239,   100,   249,   319,   775,   752,   105,    70,    54,
      82,    86,   783,   107,   785,    95,   235,   124,    54,    54,
     329,   747,   331,   109,   333,   235,   335,   624,   790,   791,
     235,    54,    73,     3,     4,     5,     6,     7,     8,   235,
       9,    74,   796,    92,   625,    10,   633,     3,     4,     5,
       6,     7,     8,    11,     9,   621,     3,     4,    12,    10,
      93,    78,   811,   104,   106,   111,   251,    11,    79,   771,
     108,   235,    12,    54,   749,   252,   821,   626,   254,    82,
     110,    12,   236,   272,   768,   823,    96,    23,    24,    25,
      26,   795,   838,   622,   839,    54,   800,    54,   766,    54,
     836,   747,   773,    97,    75,   842,   309,   310,   311,   348,
     631,   336,   748,   762,    23,    24,    25,    26,    75,   632,
     622,   337,   112,    54,   113,   797,   118,    80,   767,   753,
     757,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,   769,   370,   374,   378,   381,
     384,   386,   391,   812,   749,   798,   238,   243,   116,   244,
     114,   415,   423,   428,   432,   436,   440,    23,    24,    25,
      26,   343,   121,   622,   762,   754,   125,   460,   824,   126,
     634,   473,   761,   798,   117,   484,   487,   490,   493,   496,
     498,   503,   761,   127,   803,   833,   344,   128,   520,   523,
     526,   529,   532,   535,   538,   541,   544,   547,   550,   553,
     558,   762,   565,   568,   571,   574,   577,   580,    98,   586,
     741,   762,   737,   804,   834,   169,   129,   608,    99,   170,
     171,   172,   169,    55,    23,    24,    25,    26,   172,   173,
     622,    71,    55,   144,    87,   145,   174,   175,   774,   248,
      54,    55,    55,   233,   151,   637,   639,   641,   643,   645,
     300,   301,   302,   234,    55,   652,   654,   656,   658,   660,
     662,   303,   304,   167,   144,   665,   145,   237,   673,   677,
     679,   681,   683,   685,   687,   690,   694,   696,   698,   700,
     702,   704,   707,    86,    86,    86,    86,    86,    86,    86,
     720,    86,    86,    86,    86,   124,    55,    23,    24,    25,
      26,   241,    54,   622,   177,   242,   273,    54,   178,    54,
     250,    54,   115,   312,   116,   179,   180,   313,    55,     3,
      55,   315,    55,   275,    89,     3,     4,     5,     6,     7,
       8,    90,     9,   322,   276,   277,   317,    10,   301,   302,
     117,   300,   301,   302,    12,    11,    55,   320,   303,   304,
      12,   321,   303,   304,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,   338,   118,
     628,   144,   733,   145,   734,   392,  -429,   635,   399,   148,
     149,   150,   151,   735,   416,   424,   429,   433,   437,   441,
       3,     4,     5,     6,     7,     8,    75,     9,   339,   739,
     461,   167,    10,   736,   474,   752,   752,   757,     7,   668,
      11,   301,   741,   169,   504,    12,   742,   170,   171,   172,
     169,   303,   304,    66,   170,   171,   172,   340,   276,   277,
     144,   743,   145,   559,   174,   175,   146,   147,   148,   149,
     150,   151,   587,   591,   593,   595,   597,   599,   601,   603,
     609,   159,   160,   752,   744,   163,   164,   165,   166,   228,
     167,    75,   230,   303,   304,   745,    56,   746,   763,   231,
     232,     3,     4,    55,    72,    56,    78,    88,   764,   218,
     169,   190,   209,    79,    56,    56,   765,     3,     4,     5,
       6,     7,     8,   218,     9,   330,    12,    56,   666,    10,
     270,   674,   223,   224,   225,   226,   178,    11,   691,   770,
     772,   778,    12,   179,   180,   708,   710,   712,   713,   714,
     715,   716,   717,   721,    87,    87,    87,    87,   753,   753,
     341,   779,   780,   782,   181,    55,   787,   793,   182,    56,
      55,   794,    55,   182,    55,   183,   184,   799,   792,   274,
     183,   184,   808,   781,   814,   624,   777,   816,    75,   817,
     366,    56,   818,    56,   819,    56,     3,     4,     5,     6,
       7,     8,   820,     9,   332,   837,   753,   822,    10,   827,
     757,   826,   228,   229,   443,   230,    11,   828,   230,    56,
     844,    12,   231,   232,   798,   231,   232,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,   845,   848,   227,   228,   229,    54,   230,   393,   395,
     397,   849,   344,    54,   231,   232,   825,   417,   425,   248,
     349,    63,    65,   581,   850,   810,     0,    75,     0,     0,
     227,   228,   229,   462,   230,     0,   789,   475,     0,     0,
       0,   231,   232,   627,     0,     0,     0,   505,   629,   630,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     9,
     758,     0,     0,     0,    10,     0,   560,     0,     0,   218,
       0,     0,    11,     0,     0,   588,     0,    12,   307,   308,
     309,   310,   311,   610,   612,   614,     0,   618,   620,   759,
     221,   222,   223,   224,   225,   226,     0,     0,   100,     0,
     100,     0,   144,   124,   145,     0,    56,     0,   146,   147,
     148,   149,   150,   151,    54,    54,    54,    54,     0,    54,
       0,     0,     0,    75,   255,   256,   257,   258,   259,   190,
       0,   667,   167,     0,   675,   260,   261,   262,     0,   263,
     264,   692,     0,     0,     0,   760,     0,    54,   709,   711,
     711,   711,   711,   711,   711,   711,   722,   723,   724,   725,
     726,    23,    24,    25,    26,     0,     0,   622,    56,   187,
     188,   189,   190,    56,    51,    56,     0,    56,   100,     0,
     100,     0,     0,    51,     0,    84,   247,   218,    54,     0,
       0,     0,    51,    51,    54,     0,    54,   219,     0,     0,
      54,   220,    54,     0,     0,    51,     0,    54,   221,   222,
     223,   224,   225,   226,   206,   207,   208,   209,     0,   122,
     123,     0,     2,     3,     4,     5,     6,     7,     8,     0,
       9,   257,   258,   259,   190,    10,     0,     0,   247,    55,
       0,     0,     0,    11,     0,     0,    55,    51,    12,   292,
       0,     0,     0,   293,     0,     0,     0,    84,     0,     0,
     294,   295,   296,   297,   298,   299,     0,     0,     0,    51,
       0,    51,     0,    51,     0,    13,    14,    15,     0,     0,
      16,    17,    18,    19,    20,    21,    22,     0,    23,    24,
      25,    26,    27,    28,    29,     0,     0,    51,   185,   186,
     187,   188,   189,   190,     0,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,     0,
       3,     4,     5,     6,     7,     8,   388,     9,   805,     0,
       0,     0,    10,     0,     0,   412,   420,     0,     0,     0,
      11,   267,   268,   269,   270,    12,     0,    55,    55,    55,
      55,   457,    55,   466,   468,   470,     0,   806,   204,   205,
     206,   207,   208,   209,     0,   500,     0,   119,     0,     0,
       3,     4,     5,     6,     7,     8,     0,     9,   334,     0,
      55,     0,    10,     0,   555,     0,     0,   176,    49,     0,
      11,    75,     0,   583,     0,    12,     0,    49,     0,   119,
       0,   605,   176,     0,     0,     0,    49,    49,   296,   297,
     298,   299,     0,   119,     0,     0,     0,     0,     0,    49,
       0,    55,   218,     0,    51,     0,     0,    55,     0,    55,
       0,     0,   219,    55,     0,    55,   220,     0,     0,     0,
      55,    75,     0,   221,   222,   223,   224,   225,   226,   663,
     669,   670,   671,     0,     0,     0,     0,   130,     0,   688,
       0,    49,     0,     0,     0,     0,   705,    84,    84,    84,
      84,    84,    84,    84,   718,    84,    84,    84,    84,     0,
       0,     0,    56,    49,     0,    49,    51,    49,     0,    56,
       0,    51,     0,    51,     0,    51,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   246,   142,   143,
       0,    49,   265,   266,   267,   268,   269,   270,     0,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,     0,   368,   372,   376,     0,     0,     0,
       0,   307,   308,   309,   310,   311,     0,     0,     0,   411,
     419,   218,   260,     0,   262,     0,   263,   264,   445,   447,
     449,   451,   453,   455,   802,   220,   464,   807,     0,     0,
     477,     0,   221,   222,   223,   224,   225,   226,     0,     0,
     507,     0,     0,     0,   813,    52,     0,     0,     0,     0,
      56,    56,    56,    56,    52,    56,     0,     0,     0,   562,
       0,     0,     0,    52,    52,     0,     0,     0,   590,   830,
       0,   832,     0,     0,     0,     0,    52,     0,   616,     0,
       0,     0,     0,    56,     3,     4,     5,     6,     7,     8,
     363,     9,     0,     0,     0,     0,    10,     0,    49,   847,
       0,     0,     0,     0,    11,   144,     0,   145,     0,    12,
       0,   146,   147,   148,   149,   150,   151,     0,    52,     0,
       0,     0,     0,     0,    56,     0,   159,   160,     0,     0,
      56,     0,    56,     0,     0,   167,    56,     0,    56,     0,
      52,   245,    52,    56,    52,     0,   255,   256,   257,   258,
     259,   190,     0,     0,     0,    75,     0,   260,   261,   262,
      49,   263,   264,     0,     0,    49,   176,    49,    52,    49,
     176,     0,     0,     0,   176,     0,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
     265,   266,   267,   268,   269,   270,     0,   389,     3,     4,
       5,     6,     7,     8,     0,     9,   413,   421,     0,   176,
      10,   204,   205,   206,   207,   208,   209,   176,    11,     0,
       0,     0,   458,    12,     0,     0,   471,     0,   479,   481,
     214,   215,   216,   217,     0,   340,   501,   294,   295,   296,
     297,   298,   299,   176,     0,   176,     0,   176,     0,   176,
       0,   176,     0,   176,     0,   556,     0,     0,     0,     0,
      51,     0,   176,     0,   584,     0,     0,    51,     0,    75,
       0,     0,   606,     1,     0,   176,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,     0,    10,
       0,     0,     0,     0,     0,    52,     0,    11,     0,     0,
       0,     0,    12,     0,     0,   176,     0,     3,     4,     5,
       6,     7,     8,   293,     9,     0,   116,     0,     0,    10,
     294,   295,   296,   297,   298,   299,     0,    11,     0,    13,
      14,    15,    12,     0,    16,    17,    18,    19,    20,    21,
      22,     0,    23,    24,    25,    26,    27,    28,    29,     0,
       0,     0,     0,     0,     0,     0,    62,    52,     0,     0,
     176,     0,    52,     0,    52,     0,    52,     0,    51,    51,
      51,    51,     0,    51,     0,     0,     0,     0,    75,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   176,     0,
       0,     3,     4,     5,     6,     7,     8,     0,     9,   801,
       0,    51,     0,    10,     0,     3,     4,     5,     6,     7,
       8,    11,     9,   339,   176,     0,    12,    10,     0,     3,
       4,     5,     6,     7,     8,    11,     9,   829,     0,     0,
      12,    10,     0,     0,     0,     0,     0,     0,     0,    11,
       0,     0,    51,     0,    12,     0,     0,     0,    51,     0,
      51,     0,     0,   323,    51,   323,    51,   323,     0,   323,
       0,    51,    75,   323,     0,   346,     3,     4,     5,     6,
       7,    83,     0,     0,    49,     0,    75,     0,    79,     0,
       0,    49,     0,     0,     0,     0,    11,     0,     0,     0,
      75,    12,     0,   323,   367,   371,   375,   379,   382,   385,
     387,   394,   396,   398,   400,   402,   404,   406,   408,   410,
     418,   426,   430,   434,   438,   442,     0,   323,   444,   446,
     448,   450,   452,   454,     0,   456,   463,   465,   467,   469,
     476,   478,   480,   482,   485,   488,   491,   494,     0,   499,
     506,   508,   510,   512,   514,   516,   518,   521,   524,   527,
     530,   533,   536,   539,   542,   545,   548,   551,   554,   561,
     563,   566,   569,   572,   575,   578,   323,   582,   589,   592,
     594,   596,   598,   600,   602,   604,   611,   613,   615,   617,
     619,     0,    49,    49,    49,    49,   323,    49,     0,     0,
       0,   323,   323,     0,     3,     4,     5,     6,     7,     8,
       0,     9,   831,     0,   245,     0,    10,     0,     0,   307,
     308,   309,   310,   311,    11,    49,     0,     0,     0,    12,
     260,   261,   262,     0,   263,   264,     0,     0,     0,   123,
       0,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,   738,     0,    10,   185,   186,   187,   188,   189,
     190,     0,    11,     0,     0,     0,    49,    12,     0,     0,
     196,   197,    49,     0,    49,    75,     0,     0,    49,     0,
      49,    52,     0,     0,     0,    49,     0,     0,    52,     0,
       0,     0,     0,     0,    13,    14,    15,     0,   323,    16,
      17,    18,    19,    20,    21,    22,     0,    23,    24,    25,
      26,    27,    28,    29,   123,     0,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,   786,     0,    10,
       0,     3,     4,     5,     6,     7,     8,    11,     9,   846,
       0,     0,    12,    10,     0,     0,    69,     0,    81,    85,
      91,    11,     0,     0,     0,     0,    12,   307,   308,   309,
     310,   311,     0,     0,     0,     0,     0,     0,   260,    13,
      14,    15,   263,   264,    16,    17,    18,    19,    20,    21,
      22,     0,    23,    24,    25,    26,    27,    28,    29,    52,
      52,    52,    52,     0,    52,     3,     4,     5,     6,    60,
      83,     0,    75,     0,     0,     0,     0,    79,     0,   255,
     256,   257,   258,   259,   190,    11,   253,    81,     0,   292,
      12,   271,    52,   293,   263,   264,     0,   305,   306,     0,
     294,   295,   296,   297,   298,   299,   307,   308,   309,   310,
     311,     0,     0,   325,     0,   325,     0,   325,     0,   325,
       0,   263,   264,   325,     0,   347,     0,     0,     0,     0,
       0,     0,     0,    52,     0,     0,     0,     0,     0,    52,
       0,    52,     0,     0,     0,    52,     0,    52,     0,     0,
       0,     0,    52,   325,   369,   373,   377,   380,   383,   347,
     390,   347,   347,   347,   401,   403,   405,   407,   409,   414,
     422,   427,   431,   435,   439,   347,     0,   325,   347,   347,
     347,   347,   347,   347,     0,   459,   347,   347,   347,   472,
     347,   347,   347,   483,   486,   489,   492,   495,   497,   502,
     347,   509,   511,   513,   515,   517,   519,   522,   525,   528,
     531,   534,   537,   540,   543,   546,   549,   552,   557,   347,
     564,   567,   570,   573,   576,   579,   325,   585,   347,   347,
     347,   347,   347,   347,   347,   607,   347,   347,   347,   347,
     347,     0,     0,     0,     0,     0,   325,     0,     0,    76,
       0,   325,   325,     0,     0,     0,     0,     0,     0,   103,
       0,     0,     0,   636,   638,   640,   642,   644,   646,   647,
     648,   649,   650,   651,   653,   655,   657,   659,   661,     0,
       0,     0,     0,   664,     0,     0,   672,   676,   678,   680,
     682,   684,   686,   689,   693,   695,   697,   699,   701,   703,
     706,    85,    85,    85,    85,    85,    85,    85,   719,    85,
      85,    85,    85,    76,     0,   727,   728,   729,   730,   731,
       3,     4,     5,     6,    60,     8,     0,     9,     0,     0,
       0,     0,    10,     0,     0,   314,     0,   316,     0,     0,
      11,     0,     0,     0,     0,    12,     0,     0,   325,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,   142,   143,     0,     0,     0,     0,     0,     0,   323,
       0,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   365,     0,     0,   323,     0,     0,
     323,    61,     0,     0,     0,     0,     0,     0,     0,   323,
       0,     0,     0,     0,     0,     0,     0,   323,     0,     0,
      98,     3,     4,     5,     6,     7,     8,     0,     9,     0,
      99,     0,     0,    10,     0,     0,     0,     0,     0,     0,
       0,    11,   323,     0,   323,     0,    12,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,   318,     0,    10,     0,     0,     0,     0,     0,     0,
       0,    11,   323,    13,    14,    15,    12,     0,    16,    17,
      18,    19,    20,    21,    22,     0,    23,    24,    25,    26,
      27,    28,    29,     0,     0,     0,     0,     0,     0,     0,
      76,     0,     0,    13,    14,    15,     0,     0,    16,    17,
      18,    19,    20,    21,    22,     0,    23,    24,    25,    26,
      27,    28,    29,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,     0,     0,    10,     0,     3,     4,
       5,     6,     7,     8,    11,     9,     0,     0,     0,    12,
      10,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,     0,   732,    12,     0,     0,     0,     0,     0,     0,
       0,   740,     0,     0,     0,     0,    13,    14,    15,     0,
       0,    16,    17,    18,    19,    20,    21,    22,     0,    23,
      24,    25,    26,    27,    28,    29,     0,     0,     0,     0,
       0,     0,     0,     0,   144,   240,   145,     0,     0,    75,
     146,   147,   148,   149,   150,   151,   152,   153,   154,     0,
     155,   156,   157,   158,     0,   159,   160,   161,   162,   163,
     164,   165,   166,   144,   167,   145,     0,     0,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,     0,   155,
     156,   157,   158,     0,   159,   160,   161,   162,   163,   164,
     165,   166,   144,   167,   145,     0,     0,     0,   146,   147,
     148,   149,   150,   151,     0,   153,   154,     0,   155,   156,
     157,   158,     0,   159,   160,   161,   162,   163,   164,   165,
     166,   144,   167,   145,     0,     0,     0,   146,   147,   148,
     149,   150,   151,     0,   153,     0,     0,   155,   156,   157,
     158,     0,   159,   160,   161,   162,   163,   164,   165,   166,
     144,   167,   145,     0,     0,     0,   146,   147,   148,   149,
     150,   151,     0,     0,     0,     0,   155,   156,   157,   158,
       0,   159,   160,   161,   162,   163,   164,   165,   166,     0,
     167,   185,   186,   187,   188,   189,   190,   191,     0,   325,
       0,   192,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,     0,     0,     0,   325,     0,     0,
     325,     0,     0,     0,   144,     0,   145,     0,     0,   325,
     146,   147,   148,   149,   150,   151,     0,   325,     0,     0,
       0,   156,   157,   158,     0,   159,   160,   161,   162,   163,
     164,   165,   166,     0,   167,     0,     0,     0,     0,   144,
       0,   145,   325,     0,   325,   146,   147,   148,   149,   150,
     151,     0,     0,     0,     0,     0,   156,     0,   158,     0,
     159,   160,   161,   162,   163,   164,   165,   166,     0,   167,
       0,     0,   325,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   144,     0,   145,     0,     0,     0,   146,
     147,   148,   149,   150,   151,     0,   776,     0,     0,     0,
     156,     0,     0,    76,   159,   160,   161,   162,   163,   164,
     165,   166,   144,   167,   145,     0,     0,     0,   146,   147,
     148,   149,   150,   151,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   159,   160,   161,   162,   163,   164,   165,
     166,   245,   167,     0,     0,     0,   185,   186,   187,   188,
     189,   190,   191,     0,     0,     0,   192,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   245,
       0,     0,     0,     0,   255,   256,   257,   258,   259,   190,
     278,     0,     0,     0,     0,   260,   261,   262,     0,   263,
     264,   279,   280,   281,   282,   283,   284,     0,     0,     0,
       0,     0,     0,     0,     0,   784,   246,     0,     0,   788,
       0,   204,   205,   206,   207,   208,   209,   210,     0,     0,
       0,   211,     0,     0,     0,     0,     0,     0,   212,   213,
     214,   215,   216,   217,   246,     0,     0,   809,     0,   265,
     266,   267,   268,   269,   270,   285,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   286,   287,   288,   289,
     290,   291,     0,     0,   255,   256,   257,   258,   259,   190,
     278,     0,     0,     0,     0,   260,   261,   262,   835,   263,
     264,   279,   280,   281,   282,   283,   284,     0,     0,     0,
     840,     0,   841,     0,     0,     0,     0,   843,   185,   186,
     187,   188,   189,   190,     0,     0,     0,     0,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   255,   256,   257,   258,   259,   190,     0,     0,     0,
       0,     0,   260,   261,   262,     0,   263,   264,   279,   280,
     281,   282,   283,   284,   185,   186,   187,   188,   189,   190,
       0,     0,     0,     0,     0,   193,     0,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   185,   186,   187,
     188,   189,   190,     0,     0,     0,     0,     0,   193,     0,
       0,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,     0,     0,     0,
     211,   185,   186,   187,   188,   189,   190,   212,   213,   214,
     215,   216,   217,     0,     0,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   265,   266,   267,   268,   269,   270,
     285,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   286,   287,   288,   289,   290,   291,   204,   205,   206,
     207,   208,   209,     0,     0,     0,     0,   211,   185,   186,
     187,   188,   189,   190,   212,   213,   214,   215,   216,   217,
       0,     0,     0,   196,   197,     0,     0,   200,   201,   202,
     203,   265,   266,   267,   268,   269,   270,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   286,   287,
     288,   289,   290,   291
  };

  const short
   Parser ::yycheck_[] =
  {
       0,    61,    18,    73,    99,   625,   337,    11,     8,     9,
      10,    11,   734,    11,   736,     9,     9,    31,    18,    19,
     105,     3,   107,    11,   109,     9,   111,   235,   746,   747,
       9,    31,     3,     4,     5,     6,     7,     8,     9,     9,
      11,    12,   754,    75,     9,    16,     3,     4,     5,     6,
       7,     8,     9,    24,    11,    10,     4,     5,    29,    16,
      75,     9,   774,    75,    68,    11,     3,    24,    16,    11,
      68,     9,    29,    73,    56,    12,   794,    42,    78,    79,
      68,    29,    75,    83,    12,   797,     9,    69,    70,    71,
      72,    75,   814,    75,   816,    95,    75,    97,    10,    99,
     812,     3,    40,     9,    75,    75,    17,    18,    19,   123,
       3,     3,    14,    41,    69,    70,    71,    72,    75,    12,
      75,    13,    68,   123,    75,    10,    68,    75,    40,   337,
     338,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,    12,   146,   147,   148,   149,
     150,   151,   152,    10,    56,    40,    11,    38,    13,    40,
      75,   161,   162,   163,   164,   165,   166,    69,    70,    71,
      72,    14,     0,    75,    41,    10,     3,   177,   798,     3,
     250,   181,    12,    40,    39,   185,   186,   187,   188,   189,
     190,   191,    12,     3,    12,    12,    39,     3,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    41,   212,   213,   214,   215,   216,   217,     3,   219,
      40,    41,   317,    41,    41,    11,     3,   227,    13,    15,
      16,    17,    11,     0,    69,    70,    71,    72,    17,    25,
      75,     8,     9,     9,    11,    11,    32,    33,    10,    10,
     250,    18,    19,    68,    20,   255,   256,   257,   258,   259,
      21,    22,    23,    68,    31,   265,   266,   267,   268,   269,
     270,    32,    33,    39,     9,   275,    11,    10,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   319,    73,    69,    70,    71,
      72,    10,   312,    75,    21,    10,    83,   317,    25,   319,
      40,   321,    11,    42,    13,    32,    33,    40,    95,     4,
      97,    75,    99,    21,     9,     4,     5,     6,     7,     8,
       9,    16,    11,    12,    32,    33,    13,    16,    22,    23,
      39,    21,    22,    23,    29,    24,   123,    62,    32,    33,
      29,    42,    32,    33,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,     9,    68,
      10,     9,    75,    11,    10,   152,    75,    12,   155,    17,
      18,    19,    20,    41,   161,   162,   163,   164,   165,   166,
       4,     5,     6,     7,     8,     9,    75,    11,    12,     9,
     177,    39,    16,    10,   181,   746,   747,   625,     8,     9,
      24,    22,    40,    11,   191,    29,    12,    15,    16,    17,
      11,    32,    33,     8,    15,    16,    17,    41,    32,    33,
       9,    12,    11,   210,    32,    33,    15,    16,    17,    18,
      19,    20,   219,   220,   221,   222,   223,   224,   225,   226,
     227,    30,    31,   794,    12,    34,    35,    36,    37,    22,
      39,    75,    25,    32,    33,    12,     0,    13,    12,    32,
      33,     4,     5,   250,     8,     9,     9,    11,    75,    11,
      11,    20,    20,    16,    18,    19,    14,     4,     5,     6,
       7,     8,     9,    11,    11,    12,    29,    31,   275,    16,
      20,   278,    34,    35,    36,    37,    25,    24,   285,    12,
      10,    10,    29,    32,    33,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   746,   747,
     115,    38,    12,     8,    21,   312,     3,    14,    25,    73,
     317,     3,   319,    25,   321,    32,    33,    40,    75,    83,
      32,    33,    42,   633,    60,   773,   626,    10,    75,     3,
     145,    95,    10,    97,    14,    99,     4,     5,     6,     7,
       8,     9,    42,    11,    12,    10,   794,    42,    16,    42,
     798,   799,    22,    23,   169,    25,    24,    12,    25,   123,
      12,    29,    32,    33,    40,    32,    33,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    12,    40,    21,    22,    23,   626,    25,   152,   153,
     154,    12,    39,   633,    32,    33,   799,   161,   162,    10,
     131,     8,     8,   218,   848,   773,    -1,    75,    -1,    -1,
      21,    22,    23,   177,    25,    -1,   741,   181,    -1,    -1,
      -1,    32,    33,   238,    -1,    -1,    -1,   191,   243,   244,
      -1,    -1,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    -1,    -1,    16,    -1,   210,    -1,    -1,    11,
      -1,    -1,    24,    -1,    -1,   219,    -1,    29,    15,    16,
      17,    18,    19,   227,   228,   229,    -1,   231,   232,    41,
      32,    33,    34,    35,    36,    37,    -1,    -1,   734,    -1,
     736,    -1,     9,   737,    11,    -1,   250,    -1,    15,    16,
      17,    18,    19,    20,   734,   735,   736,   737,    -1,   739,
      -1,    -1,    -1,    75,    15,    16,    17,    18,    19,    20,
      -1,   275,    39,    -1,   278,    26,    27,    28,    -1,    30,
      31,   285,    -1,    -1,    -1,   340,    -1,   767,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,    69,    70,    71,    72,    -1,    -1,    75,   312,    17,
      18,    19,    20,   317,     0,   319,    -1,   321,   814,    -1,
     816,    -1,    -1,     9,    -1,    11,    10,    11,   808,    -1,
      -1,    -1,    18,    19,   814,    -1,   816,    21,    -1,    -1,
     820,    25,   822,    -1,    -1,    31,    -1,   827,    32,    33,
      34,    35,    36,    37,    17,    18,    19,    20,    -1,     0,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    17,    18,    19,    20,    16,    -1,    -1,    10,   626,
      -1,    -1,    -1,    24,    -1,    -1,   633,    73,    29,    21,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    83,    -1,    -1,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    95,
      -1,    97,    -1,    99,    -1,    56,    57,    58,    -1,    -1,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    -1,    -1,   123,    15,    16,
      17,    18,    19,    20,    -1,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,    -1,
       4,     5,     6,     7,     8,     9,   152,    11,    12,    -1,
      -1,    -1,    16,    -1,    -1,   161,   162,    -1,    -1,    -1,
      24,    17,    18,    19,    20,    29,    -1,   734,   735,   736,
     737,   177,   739,   179,   180,   181,    -1,    41,    15,    16,
      17,    18,    19,    20,    -1,   191,    -1,    29,    -1,    -1,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
     767,    -1,    16,    -1,   210,    -1,    -1,    49,     0,    -1,
      24,    75,    -1,   219,    -1,    29,    -1,     9,    -1,    61,
      -1,   227,    64,    -1,    -1,    -1,    18,    19,    34,    35,
      36,    37,    -1,    75,    -1,    -1,    -1,    -1,    -1,    31,
      -1,   808,    11,    -1,   250,    -1,    -1,   814,    -1,   816,
      -1,    -1,    21,   820,    -1,   822,    25,    -1,    -1,    -1,
     827,    75,    -1,    32,    33,    34,    35,    36,    37,   275,
     276,   277,   278,    -1,    -1,    -1,    -1,     3,    -1,   285,
      -1,    73,    -1,    -1,    -1,    -1,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,    -1,
      -1,    -1,   626,    95,    -1,    97,   312,    99,    -1,   633,
      -1,   317,    -1,   319,    -1,   321,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    10,    54,    55,
      -1,   123,    15,    16,    17,    18,    19,    20,    -1,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,    -1,   146,   147,   148,    -1,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    -1,    -1,    -1,   161,
     162,    11,    26,    -1,    28,    -1,    30,    31,   170,   171,
     172,   173,   174,   175,   759,    25,   178,   762,    -1,    -1,
     182,    -1,    32,    33,    34,    35,    36,    37,    -1,    -1,
     192,    -1,    -1,    -1,   779,     0,    -1,    -1,    -1,    -1,
     734,   735,   736,   737,     9,   739,    -1,    -1,    -1,   211,
      -1,    -1,    -1,    18,    19,    -1,    -1,    -1,   220,   804,
      -1,   806,    -1,    -1,    -1,    -1,    31,    -1,   230,    -1,
      -1,    -1,    -1,   767,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    16,    -1,   250,   834,
      -1,    -1,    -1,    -1,    24,     9,    -1,    11,    -1,    29,
      -1,    15,    16,    17,    18,    19,    20,    -1,    73,    -1,
      -1,    -1,    -1,    -1,   808,    -1,    30,    31,    -1,    -1,
     814,    -1,   816,    -1,    -1,    39,   820,    -1,   822,    -1,
      95,    10,    97,   827,    99,    -1,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    75,    -1,    26,    27,    28,
     312,    30,    31,    -1,    -1,   317,   368,   319,   123,   321,
     372,    -1,    -1,    -1,   376,    -1,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      15,    16,    17,    18,    19,    20,    -1,   152,     4,     5,
       6,     7,     8,     9,    -1,    11,   161,   162,    -1,   411,
      16,    15,    16,    17,    18,    19,    20,   419,    24,    -1,
      -1,    -1,   177,    29,    -1,    -1,   181,    -1,   183,   184,
      34,    35,    36,    37,    -1,    41,   191,    32,    33,    34,
      35,    36,    37,   445,    -1,   447,    -1,   449,    -1,   451,
      -1,   453,    -1,   455,    -1,   210,    -1,    -1,    -1,    -1,
     626,    -1,   464,    -1,   219,    -1,    -1,   633,    -1,    75,
      -1,    -1,   227,     0,    -1,   477,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    -1,   250,    -1,    24,    -1,    -1,
      -1,    -1,    29,    -1,    -1,   507,    -1,     4,     5,     6,
       7,     8,     9,    25,    11,    -1,    13,    -1,    -1,    16,
      32,    33,    34,    35,    36,    37,    -1,    24,    -1,    56,
      57,    58,    29,    -1,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     8,   312,    -1,    -1,
     562,    -1,   317,    -1,   319,    -1,   321,    -1,   734,   735,
     736,   737,    -1,   739,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   590,    -1,
      -1,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      -1,   767,    -1,    16,    -1,     4,     5,     6,     7,     8,
       9,    24,    11,    12,   616,    -1,    29,    16,    -1,     4,
       5,     6,     7,     8,     9,    24,    11,    12,    -1,    -1,
      29,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,   808,    -1,    29,    -1,    -1,    -1,   814,    -1,
     816,    -1,    -1,   105,   820,   107,   822,   109,    -1,   111,
      -1,   827,    75,   115,    -1,   117,     4,     5,     6,     7,
       8,     9,    -1,    -1,   626,    -1,    75,    -1,    16,    -1,
      -1,   633,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      75,    29,    -1,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,   169,   170,   171,
     172,   173,   174,   175,    -1,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,    -1,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,   734,   735,   736,   737,   238,   739,    -1,    -1,
      -1,   243,   244,    -1,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    10,    -1,    16,    -1,    -1,    15,
      16,    17,    18,    19,    24,   767,    -1,    -1,    -1,    29,
      26,    27,    28,    -1,    30,    31,    -1,    -1,    -1,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      -1,    -1,    14,    -1,    16,    15,    16,    17,    18,    19,
      20,    -1,    24,    -1,    -1,    -1,   808,    29,    -1,    -1,
      30,    31,   814,    -1,   816,    75,    -1,    -1,   820,    -1,
     822,   626,    -1,    -1,    -1,   827,    -1,    -1,   633,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    -1,   340,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    -1,    14,    -1,    16,
      -1,     4,     5,     6,     7,     8,     9,    24,    11,    12,
      -1,    -1,    29,    16,    -1,    -1,     8,    -1,    10,    11,
      12,    24,    -1,    -1,    -1,    -1,    29,    15,    16,    17,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    26,    56,
      57,    58,    30,    31,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,   734,
     735,   736,   737,    -1,   739,     4,     5,     6,     7,     8,
       9,    -1,    75,    -1,    -1,    -1,    -1,    16,    -1,    15,
      16,    17,    18,    19,    20,    24,    78,    79,    -1,    21,
      29,    83,   767,    25,    30,    31,    -1,    89,    90,    -1,
      32,    33,    34,    35,    36,    37,    15,    16,    17,    18,
      19,    -1,    -1,   105,    -1,   107,    -1,   109,    -1,   111,
      -1,    30,    31,   115,    -1,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   808,    -1,    -1,    -1,    -1,    -1,   814,
      -1,   816,    -1,    -1,    -1,   820,    -1,   822,    -1,    -1,
      -1,    -1,   827,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,   169,   170,   171,
     172,   173,   174,   175,    -1,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,     9,
      -1,   243,   244,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    -1,    -1,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,    -1,
      -1,    -1,    -1,   275,    -1,    -1,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,    73,    -1,   307,   308,   309,   310,   311,
       4,     5,     6,     7,     8,     9,    -1,    11,    -1,    -1,
      -1,    -1,    16,    -1,    -1,    95,    -1,    97,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    29,    -1,    -1,   340,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,   741,
      -1,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,    -1,    -1,   759,    -1,    -1,
     762,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   771,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   779,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
      13,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,   804,    -1,   806,    -1,    29,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
      -1,    14,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,   834,    56,    57,    58,    29,    -1,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     250,    -1,    -1,    56,    57,    58,    -1,    -1,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    -1,    -1,    -1,    16,    -1,     4,     5,
       6,     7,     8,     9,    24,    11,    -1,    -1,    -1,    29,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,   312,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   321,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,
      -1,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    75,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      25,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,     9,    39,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    25,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,     9,    39,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    -1,    25,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,     9,    39,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    -1,    22,    -1,    -1,    25,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
       9,    39,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    25,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      39,    15,    16,    17,    18,    19,    20,    21,    -1,   741,
      -1,    25,    26,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,   759,    -1,    -1,
     762,    -1,    -1,    -1,     9,    -1,    11,    -1,    -1,   771,
      15,    16,    17,    18,    19,    20,    -1,   779,    -1,    -1,
      -1,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    39,    -1,    -1,    -1,    -1,     9,
      -1,    11,   804,    -1,   806,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    39,
      -1,    -1,   834,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    -1,   626,    -1,    -1,    -1,
      26,    -1,    -1,   633,    30,    31,    32,    33,    34,    35,
      36,    37,     9,    39,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    10,    39,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    25,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    10,
      -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   735,    10,    -1,    -1,   739,
      -1,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37,    10,    -1,    -1,   767,    -1,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    37,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    26,    27,    28,   808,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
     820,    -1,   822,    -1,    -1,    -1,    -1,   827,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    25,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      25,    15,    16,    17,    18,    19,    20,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    37,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    25,    15,    16,
      17,    18,    19,    20,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    30,    31,    -1,    -1,    34,    35,    36,
      37,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,     0,     3,     4,     5,     6,     7,     8,     9,    11,
      16,    24,    29,    56,    57,    58,    61,    62,    63,    64,
      65,    66,    67,    69,    70,    71,    72,    73,    74,    75,
      78,    79,    80,    81,    84,    86,    87,    88,    89,    90,
      91,    93,    96,    99,   100,   101,   103,   104,   105,   107,
     108,   111,   112,   115,   116,   117,   118,   119,   121,   123,
       8,    75,   104,   105,   107,   108,   109,   111,   112,   115,
     116,   117,   118,     3,    12,    75,   103,   106,     9,    16,
      75,   115,   116,     9,   111,   115,   116,   117,   118,     9,
      16,   115,    75,    75,    85,     9,     9,     9,     3,    13,
      81,    82,    83,   103,    75,    11,    68,    11,    68,    11,
      68,    11,    68,    75,    75,    11,    13,    39,    68,   110,
     113,     0,     0,     1,    80,     3,     3,     3,     3,     3,
       3,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    54,    55,     9,    11,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    25,    26,    27,    28,    30,
      31,    32,    33,    34,    35,    36,    37,    39,   110,    11,
      15,    16,    17,    25,    32,    33,   110,    21,    25,    32,
      33,    21,    25,    32,    33,    15,    16,    17,    18,    19,
      20,    21,    25,    26,    27,    28,    30,    31,    32,    33,
      34,    35,    36,    37,    15,    16,    17,    18,    19,    20,
      21,    25,    32,    33,    34,    35,    36,    37,    11,    21,
      25,    32,    33,    34,    35,    36,    37,    21,    22,    23,
      25,    32,    33,    68,    68,     9,    75,    10,    11,   113,
      10,    10,    10,    38,    40,    10,    10,    10,    10,   106,
      40,     3,    12,   115,   116,    15,    16,    17,    18,    19,
      26,    27,    28,    30,    31,    15,    16,    17,    18,    19,
      20,   115,   116,   117,   118,    21,    32,    33,    21,    32,
      33,    34,    35,    36,    37,    21,    32,    33,    34,    35,
      36,    37,    21,    25,    32,    33,    34,    35,    36,    37,
      21,    22,    23,    32,    33,   115,   115,    15,    16,    17,
      18,    19,    42,    40,   103,    75,   103,    13,    14,    79,
      62,    42,    12,   104,   109,   115,   116,   117,   118,   122,
      12,   122,    12,   122,    12,   122,     3,    13,     9,    12,
      41,   109,   122,    14,    39,   114,   104,   115,    80,   101,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,    10,   102,   103,   109,   104,   107,   115,
     116,   104,   107,   115,   116,   104,   107,   115,   116,   104,
     115,   116,   104,   115,   116,   104,   116,   104,   111,   112,
     115,   116,   117,   118,   104,   118,   104,   118,   104,   117,
     104,   115,   104,   115,   104,   115,   104,   115,   104,   115,
     104,   107,   111,   112,   115,   116,   117,   118,   104,   107,
     111,   112,   115,   116,   117,   118,   104,   115,   116,   117,
     104,   115,   116,   117,   104,   115,   116,   117,   104,   115,
     116,   117,   104,   109,   104,   107,   104,   107,   104,   107,
     104,   107,   104,   107,   104,   107,   104,   111,   112,   115,
     116,   117,   118,   104,   107,   104,   111,   104,   111,   104,
     111,   112,   115,   116,   117,   118,   104,   107,   104,   112,
     104,   112,   104,   115,   116,   104,   115,   116,   104,   115,
     116,   104,   115,   116,   104,   115,   116,   115,   116,   104,
     111,   112,   115,   116,   117,   118,   104,   107,   104,   115,
     104,   115,   104,   115,   104,   115,   104,   115,   104,   115,
     116,   104,   115,   116,   104,   115,   116,   104,   115,   116,
     104,   115,   116,   104,   115,   116,   104,   115,   116,   104,
     115,   116,   104,   115,   116,   104,   115,   116,   104,   115,
     116,   104,   115,   116,   104,   111,   112,   115,   116,   117,
     118,   104,   107,   104,   115,   116,   104,   115,   116,   104,
     115,   116,   104,   115,   116,   104,   115,   116,   104,   115,
     116,   109,   104,   111,   112,   115,   116,   117,   118,   104,
     107,   117,   104,   117,   104,   117,   104,   117,   104,   117,
     104,   117,   104,   117,   104,   111,   112,   115,   116,   117,
     118,   104,   118,   104,   118,   104,   107,   104,   118,   104,
     118,    10,    75,   120,   123,     9,    42,   109,    10,   109,
     109,     3,    12,     3,   106,    12,   115,   116,   115,   116,
     115,   116,   115,   116,   115,   116,   115,   115,   115,   115,
     115,   115,   116,   115,   116,   115,   116,   115,   116,   115,
     116,   115,   116,   111,   115,   116,   117,   118,     9,   111,
     111,   111,   115,   116,   117,   118,   115,   116,   115,   116,
     115,   116,   115,   116,   115,   116,   115,   116,   111,   115,
     116,   117,   118,   115,   116,   115,   116,   115,   116,   115,
     116,   115,   116,   115,   116,   111,   115,   116,   117,   118,
     117,   118,   117,   117,   117,   117,   117,   117,   111,   115,
     116,   117,   118,   118,   118,   118,   118,   115,   115,   115,
     115,   115,   103,    75,    10,    41,    10,    79,    14,     9,
     103,    40,    12,    12,    12,    12,    13,     3,    14,    56,
      94,    95,    99,   123,    10,    97,    98,   123,    12,    41,
     109,    12,    41,    12,    75,    14,    10,    40,    12,    12,
      12,    11,    10,    40,    10,    97,   103,   113,    10,    38,
      12,   106,     8,    83,   103,    83,    14,     3,   103,   122,
      94,    94,    75,    14,     3,    75,    82,    10,    40,    40,
      75,    12,   109,    12,    41,    12,    41,   109,    42,   103,
     120,    82,    10,   109,    60,    92,    10,     3,    10,    14,
      42,    94,    42,    82,    97,    98,   123,    42,    12,    12,
     109,    12,   109,    12,    41,   103,    82,    10,    83,    83,
     103,   103,    75,   103,    12,    12,    12,   109,    40,    12,
     114
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    77,    78,    78,    79,    79,    79,    80,    80,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    82,    82,    82,    82,    82,    83,    83,    84,    85,
      85,    86,    86,    86,    87,    87,    88,    89,    90,    91,
      92,    92,    93,    93,    93,    94,    94,    94,    94,    95,
      95,    95,    96,    96,    96,    96,    97,    97,    97,    98,
      98,    99,   100,   100,   100,   100,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     102,   102,   103,   103,   103,   103,   103,   103,   103,   103,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   105,   105,   105,   105,   105,   106,
     106,   106,   107,   107,   107,   107,   108,   108,   109,   109,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   111,   111,   112,   112,   113,   113,   114,   114,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   119,   119,   120,   120,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   122,   122,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     1,     2,     1,     2,     3,     1,     1,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     3,     4,     4,     5,     1,     1,     2,     1,
       3,     1,     1,     1,     1,     2,     7,     5,     6,     6,
       2,     0,     4,     5,     6,     1,     2,     2,     3,     1,
       4,     4,     5,     6,     5,     6,     2,     1,     3,     4,
       3,     2,     4,     4,     4,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     3,     4,     4,     4,     4,     4,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
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
       3,     3,     3,     3,     2,     3,     4,     4,     5,     1,
       3,     4,     1,     1,     3,     3,     5,     7,     1,     1,
       3,     4,     4,     5,     4,     5,     5,     5,     6,     6,
       6,     7,     1,     3,     2,     4,     2,     3,     4,     6,
       1,     2,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     3,     1,     3,     4,     3,     4,     3,
       4,     3,     4,     3,     4,     3,     1,     3,     2,     2,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1
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
  "function", "funargs", "funargdef", "vardecl", "vardef", "set",
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
       0,   203,   203,   204,   206,   207,   208,   212,   213,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   230,   231,   232,   233,   234,   237,   238,   242,   244,
     245,   249,   250,   251,   253,   254,   258,   262,   265,   269,
     275,   276,   280,   281,   282,   284,   285,   286,   287,   289,
     290,   291,   295,   296,   297,   298,   300,   301,   302,   304,
     305,   309,   313,   314,   315,   316,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     337,   338,   342,   343,   344,   345,   346,   347,   348,   349,
     352,   353,   354,   356,   357,   359,   360,   361,   362,   364,
     365,   366,   368,   369,   371,   372,   373,   375,   376,   377,
     378,   379,   380,   381,   382,   384,   385,   386,   387,   388,
     390,   391,   392,   393,   394,   396,   397,   398,   399,   400,
     401,   402,   403,   405,   406,   407,   408,   409,   410,   411,
     412,   414,   415,   416,   418,   419,   420,   422,   423,   424,
     425,   426,   427,   428,   430,   431,   432,   433,   434,   435,
     436,   438,   439,   440,   441,   442,   443,   444,   446,   447,
     448,   449,   450,   451,   452,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   490,
     491,   492,   494,   495,   496,   498,   499,   500,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   519,   520,   521,   523,   524,   525,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   554,   555,   556,   557,   558,   560,
     561,   562,   566,   567,   568,   569,   571,   572,   574,   575,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   592,   593,   597,   598,   600,   601,   603,   604,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   625,   626,   627,   628,   629,   630,
     631,   632,   633,   634,   635,   636,   637,   638,   639,   640,
     641,   642,   643,   644,   645,   649,   650,   651,   652,   653,
     654,   655,   656,   657,   658,   659,   660,   661,   662,   663,
     664,   665,   666,   667,   668,   669,   670,   671,   672,   673,
     674,   675,   679,   680,   681,   682,   683,   685,   686,   687,
     688,   689,   690,   691,   693,   694,   695,   696,   697,   698,
     699,   701,   702,   703,   704,   705,   707,   708,   709,   710,
     711,   713,   714,   715,   716,   717,   719,   720,   721,   722,
     723,   725,   729,   730,   732,   733,   737,   738,   739,   740,
     741,   742,   743,   744,   745,   746,   748,   749,   753,   754,
     755,   756,   757,   758,   759,   760,   761,   762,   763,   764,
     765,   766
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
#line 4000 "frontend/parser.cpp"

#line 769 "frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    auto msg = std::to_string(scanner->loc->begin.line) + ":" + std::to_string(scanner->loc->begin.column) + ": " + err_message;
    ptc::log::error(msg);
}
