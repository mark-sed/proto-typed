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
    #include "scanner.hpp"
    #include "logging.hpp"
    #include "ir.hpp"

    // Set correct token method
    #undef yylex
    #define yylex scanner->yylex

#line 59 "frontend/parser.cpp"


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
#line 152 "frontend/parser.cpp"

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

      case symbol_kind::S_vardecl: // vardecl
      case symbol_kind::S_type: // type
        value.copy< ptc::ir::IR * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_expr_str: // expr_str
        value.copy< std::string > (YY_MOVE (that.value));
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

      case symbol_kind::S_vardecl: // vardecl
      case symbol_kind::S_type: // type
        value.move< ptc::ir::IR * > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_expr_str: // expr_str
        value.move< std::string > (YY_MOVE (s.value));
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

      case symbol_kind::S_vardecl: // vardecl
      case symbol_kind::S_type: // type
        value.YY_MOVE_OR_COPY< ptc::ir::IR * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_expr_str: // expr_str
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
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

      case symbol_kind::S_vardecl: // vardecl
      case symbol_kind::S_type: // type
        value.move< ptc::ir::IR * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_expr_str: // expr_str
        value.move< std::string > (YY_MOVE (that.value));
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

      case symbol_kind::S_vardecl: // vardecl
      case symbol_kind::S_type: // type
        value.copy< ptc::ir::IR * > (that.value);
        break;

      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_expr_str: // expr_str
        value.copy< std::string > (that.value);
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

      case symbol_kind::S_vardecl: // vardecl
      case symbol_kind::S_type: // type
        value.move< ptc::ir::IR * > (that.value);
        break;

      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_expr_str: // expr_str
        value.move< std::string > (that.value);
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

      case symbol_kind::S_vardecl: // vardecl
      case symbol_kind::S_type: // type
        yylhs.value.emplace< ptc::ir::IR * > ();
        break;

      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_expr_str: // expr_str
        yylhs.value.emplace< std::string > ();
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
  case 9: // stmts_ne: set "terminator (\\n or ;)"
#line 204 "frontend/parser.yy"
                        { scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 865 "frontend/parser.cpp"
    break;

  case 64: // vardecl: type "identifier"
#line 298 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 871 "frontend/parser.cpp"
    break;

  case 69: // set: expr "++=" expr
#line 309 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 877 "frontend/parser.cpp"
    break;

  case 70: // set: expr "**=" expr
#line 310 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 883 "frontend/parser.cpp"
    break;

  case 71: // set: expr "%=" expr
#line 311 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 889 "frontend/parser.cpp"
    break;

  case 72: // set: expr "/=" expr
#line 312 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 895 "frontend/parser.cpp"
    break;

  case 73: // set: expr "*=" expr
#line 313 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 901 "frontend/parser.cpp"
    break;

  case 74: // set: expr "-=" expr
#line 314 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 907 "frontend/parser.cpp"
    break;

  case 75: // set: expr "+=" expr
#line 315 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 913 "frontend/parser.cpp"
    break;

  case 76: // set: expr "&=" expr
#line 316 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 919 "frontend/parser.cpp"
    break;

  case 77: // set: expr "|=" expr
#line 317 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 925 "frontend/parser.cpp"
    break;

  case 78: // set: expr "^=" expr
#line 318 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 931 "frontend/parser.cpp"
    break;

  case 79: // set: expr "<<=" expr
#line 319 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 937 "frontend/parser.cpp"
    break;

  case 80: // set: expr ">>=" expr
#line 320 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 943 "frontend/parser.cpp"
    break;

  case 81: // set: expr "=" expr
#line 321 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 949 "frontend/parser.cpp"
    break;

  case 82: // set: expr "=" set
#line 322 "frontend/parser.yy"
      { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 955 "frontend/parser.cpp"
    break;

  case 85: // expr: expr_mat
#line 331 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = nullptr; }
#line 961 "frontend/parser.cpp"
    break;

  case 86: // expr: expr_var
#line 332 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 967 "frontend/parser.cpp"
    break;

  case 87: // expr: expr_none
#line 333 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = nullptr; }
#line 973 "frontend/parser.cpp"
    break;

  case 88: // expr: expr_struct
#line 334 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = nullptr; }
#line 979 "frontend/parser.cpp"
    break;

  case 89: // expr: expr_int
#line 335 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 985 "frontend/parser.cpp"
    break;

  case 90: // expr: expr_float
#line 336 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFloat(yystack_[0].value.as < double > ()); }
#line 991 "frontend/parser.cpp"
    break;

  case 91: // expr: expr_str
#line 337 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseString(yystack_[0].value.as < std::string > ()); }
#line 997 "frontend/parser.cpp"
    break;

  case 92: // expr: expr_bool
#line 338 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseBool(yystack_[0].value.as < bool > ()); }
#line 1003 "frontend/parser.cpp"
    break;

  case 93: // expr_var: "identifier"
#line 341 "frontend/parser.yy"
              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > ()); }
#line 1009 "frontend/parser.cpp"
    break;

  case 94: // expr_var: "-" "identifier"
#line 342 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1015 "frontend/parser.cpp"
    break;

  case 95: // expr_var: "(" expr_var ")"
#line 343 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1021 "frontend/parser.cpp"
    break;

  case 96: // expr_var: expr_var "(" ")"
#line 345 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1027 "frontend/parser.cpp"
    break;

  case 97: // expr_var: expr_var "(" callarglist ")"
#line 346 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[3].value.as < ptc::ir::Expr * > (); }
#line 1033 "frontend/parser.cpp"
    break;

  case 101: // expr_var: expr_var "[" int_val "]"
#line 351 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[3].value.as < ptc::ir::Expr * > (); }
#line 1039 "frontend/parser.cpp"
    break;

  case 104: // expr_var: expr_var slice
#line 355 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1045 "frontend/parser.cpp"
    break;

  case 106: // expr_var: expr_var "." expr_var
#line 358 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1051 "frontend/parser.cpp"
    break;

  case 108: // expr_var: expr_var "**" expr_float
#line 361 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1057 "frontend/parser.cpp"
    break;

  case 109: // expr_var: expr_var "**" expr_var
#line 362 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1063 "frontend/parser.cpp"
    break;

  case 112: // expr_var: expr_var "*" expr_int
#line 366 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1069 "frontend/parser.cpp"
    break;

  case 113: // expr_var: expr_var "*" expr_float
#line 367 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1075 "frontend/parser.cpp"
    break;

  case 116: // expr_var: expr_var "*" expr_mat
#line 370 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1081 "frontend/parser.cpp"
    break;

  case 117: // expr_var: expr_var "*" expr_var
#line 371 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1087 "frontend/parser.cpp"
    break;

  case 120: // expr_var: expr_var "/" expr_int
#line 375 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1093 "frontend/parser.cpp"
    break;

  case 121: // expr_var: expr_var "/" expr_float
#line 376 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1099 "frontend/parser.cpp"
    break;

  case 122: // expr_var: expr_var "/" expr_var
#line 377 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1105 "frontend/parser.cpp"
    break;

  case 125: // expr_var: expr_var "%" expr_int
#line 381 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1111 "frontend/parser.cpp"
    break;

  case 126: // expr_var: expr_var "%" expr_float
#line 382 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1117 "frontend/parser.cpp"
    break;

  case 127: // expr_var: expr_var "%" expr_var
#line 383 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1123 "frontend/parser.cpp"
    break;

  case 128: // expr_var: expr_int "+" expr_var
#line 385 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1129 "frontend/parser.cpp"
    break;

  case 129: // expr_var: expr_float "+" expr_var
#line 386 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1135 "frontend/parser.cpp"
    break;

  case 130: // expr_var: expr_var "+" expr_int
#line 387 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1141 "frontend/parser.cpp"
    break;

  case 131: // expr_var: expr_var "+" expr_float
#line 388 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1147 "frontend/parser.cpp"
    break;

  case 133: // expr_var: expr_var "+" expr_mat
#line 390 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1153 "frontend/parser.cpp"
    break;

  case 135: // expr_var: expr_var "+" expr_var
#line 392 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1159 "frontend/parser.cpp"
    break;

  case 138: // expr_var: expr_var "-" expr_int
#line 396 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1165 "frontend/parser.cpp"
    break;

  case 139: // expr_var: expr_var "-" expr_float
#line 397 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1171 "frontend/parser.cpp"
    break;

  case 141: // expr_var: expr_var "-" expr_mat
#line 399 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1177 "frontend/parser.cpp"
    break;

  case 143: // expr_var: expr_var "-" expr_var
#line 401 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1183 "frontend/parser.cpp"
    break;

  case 145: // expr_var: expr_var "<<" expr_int
#line 404 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1189 "frontend/parser.cpp"
    break;

  case 146: // expr_var: expr_var "<<" expr_var
#line 405 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1195 "frontend/parser.cpp"
    break;

  case 148: // expr_var: expr_var ">>" expr_int
#line 408 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1201 "frontend/parser.cpp"
    break;

  case 149: // expr_var: expr_var ">>" expr_var
#line 409 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1207 "frontend/parser.cpp"
    break;

  case 153: // expr_var: expr_var ">" expr_int
#line 414 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1213 "frontend/parser.cpp"
    break;

  case 154: // expr_var: expr_var ">" expr_float
#line 415 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1219 "frontend/parser.cpp"
    break;

  case 155: // expr_var: expr_var ">" expr_str
#line 416 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1225 "frontend/parser.cpp"
    break;

  case 156: // expr_var: expr_var ">" expr_var
#line 417 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1231 "frontend/parser.cpp"
    break;

  case 160: // expr_var: expr_var ">=" expr_int
#line 422 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1237 "frontend/parser.cpp"
    break;

  case 161: // expr_var: expr_var ">=" expr_float
#line 423 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1243 "frontend/parser.cpp"
    break;

  case 162: // expr_var: expr_var ">=" expr_str
#line 424 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1249 "frontend/parser.cpp"
    break;

  case 163: // expr_var: expr_var ">=" expr_var
#line 425 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1255 "frontend/parser.cpp"
    break;

  case 167: // expr_var: expr_var "<" expr_int
#line 430 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1261 "frontend/parser.cpp"
    break;

  case 168: // expr_var: expr_var "<" expr_float
#line 431 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1267 "frontend/parser.cpp"
    break;

  case 169: // expr_var: expr_var "<" expr_str
#line 432 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1273 "frontend/parser.cpp"
    break;

  case 170: // expr_var: expr_var "<" expr_var
#line 433 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1279 "frontend/parser.cpp"
    break;

  case 174: // expr_var: expr_var "<=" expr_int
#line 438 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1285 "frontend/parser.cpp"
    break;

  case 175: // expr_var: expr_var "<=" expr_float
#line 439 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1291 "frontend/parser.cpp"
    break;

  case 176: // expr_var: expr_var "<=" expr_str
#line 440 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1297 "frontend/parser.cpp"
    break;

  case 177: // expr_var: expr_var "<=" expr_var
#line 441 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1303 "frontend/parser.cpp"
    break;

  case 185: // expr_var: expr_var "==" expr_int
#line 450 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1309 "frontend/parser.cpp"
    break;

  case 186: // expr_var: expr_var "==" expr_float
#line 451 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1315 "frontend/parser.cpp"
    break;

  case 187: // expr_var: expr_var "==" expr_str
#line 452 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1321 "frontend/parser.cpp"
    break;

  case 188: // expr_var: expr_var "==" expr_bool
#line 453 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1327 "frontend/parser.cpp"
    break;

  case 189: // expr_var: expr_var "==" expr_none
#line 454 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1333 "frontend/parser.cpp"
    break;

  case 190: // expr_var: expr_var "==" expr_struct
#line 455 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1339 "frontend/parser.cpp"
    break;

  case 192: // expr_var: expr_var "==" expr_mat
#line 457 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1345 "frontend/parser.cpp"
    break;

  case 194: // expr_var: expr_var "==" expr_var
#line 459 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1351 "frontend/parser.cpp"
    break;

  case 202: // expr_var: expr_var "!=" expr_int
#line 468 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1357 "frontend/parser.cpp"
    break;

  case 203: // expr_var: expr_var "!=" expr_float
#line 469 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1363 "frontend/parser.cpp"
    break;

  case 204: // expr_var: expr_var "!=" expr_str
#line 470 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1369 "frontend/parser.cpp"
    break;

  case 205: // expr_var: expr_var "!=" expr_bool
#line 471 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1375 "frontend/parser.cpp"
    break;

  case 206: // expr_var: expr_var "!=" expr_none
#line 472 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1381 "frontend/parser.cpp"
    break;

  case 207: // expr_var: expr_var "!=" expr_struct
#line 473 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1387 "frontend/parser.cpp"
    break;

  case 209: // expr_var: expr_var "!=" expr_mat
#line 475 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1393 "frontend/parser.cpp"
    break;

  case 211: // expr_var: expr_var "!=" expr_var
#line 477 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1399 "frontend/parser.cpp"
    break;

  case 213: // expr_var: expr_var "&" expr_int
#line 480 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1405 "frontend/parser.cpp"
    break;

  case 214: // expr_var: expr_var "&" expr_var
#line 481 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1411 "frontend/parser.cpp"
    break;

  case 216: // expr_var: expr_var "^" expr_int
#line 484 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1417 "frontend/parser.cpp"
    break;

  case 217: // expr_var: expr_var "^" expr_var
#line 485 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1423 "frontend/parser.cpp"
    break;

  case 219: // expr_var: expr_var "|" expr_int
#line 488 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1429 "frontend/parser.cpp"
    break;

  case 220: // expr_var: expr_var "|" expr_var
#line 489 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1435 "frontend/parser.cpp"
    break;

  case 235: // expr_var: expr_var "in" expr_str
#line 505 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1441 "frontend/parser.cpp"
    break;

  case 236: // expr_var: expr_var "in" expr_var
#line 506 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1447 "frontend/parser.cpp"
    break;

  case 238: // expr_var: expr_var "and" expr_bool
#line 509 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1453 "frontend/parser.cpp"
    break;

  case 239: // expr_var: expr_var "and" expr_var
#line 510 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1459 "frontend/parser.cpp"
    break;

  case 241: // expr_var: expr_var "or" expr_bool
#line 513 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1465 "frontend/parser.cpp"
    break;

  case 242: // expr_var: expr_var "or" expr_var
#line 514 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1471 "frontend/parser.cpp"
    break;

  case 260: // expr_var: expr_var "++" expr_int
#line 533 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1477 "frontend/parser.cpp"
    break;

  case 261: // expr_var: expr_var "++" expr_float
#line 534 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1483 "frontend/parser.cpp"
    break;

  case 262: // expr_var: expr_var "++" expr_str
#line 535 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1489 "frontend/parser.cpp"
    break;

  case 263: // expr_var: expr_var "++" expr_bool
#line 536 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1495 "frontend/parser.cpp"
    break;

  case 264: // expr_var: expr_var "++" expr_none
#line 537 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1501 "frontend/parser.cpp"
    break;

  case 265: // expr_var: expr_var "++" expr_struct
#line 538 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1507 "frontend/parser.cpp"
    break;

  case 266: // expr_var: expr_var "++" expr_var
#line 539 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1513 "frontend/parser.cpp"
    break;

  case 303: // expr_int: "int"
#line 597 "frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 1519 "frontend/parser.cpp"
    break;

  case 304: // expr_int: "-" expr_int
#line 598 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 1525 "frontend/parser.cpp"
    break;

  case 305: // expr_int: "(" expr_int ")"
#line 599 "frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 1531 "frontend/parser.cpp"
    break;

  case 306: // expr_int: "~" expr_int
#line 600 "frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 1537 "frontend/parser.cpp"
    break;

  case 307: // expr_int: expr_int "*" expr_int
#line 601 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 1543 "frontend/parser.cpp"
    break;

  case 308: // expr_int: expr_int "/" expr_int
#line 602 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 1549 "frontend/parser.cpp"
    break;

  case 309: // expr_int: expr_int "%" expr_int
#line 603 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 1555 "frontend/parser.cpp"
    break;

  case 310: // expr_int: expr_int "-" expr_int
#line 604 "frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 1561 "frontend/parser.cpp"
    break;

  case 311: // expr_int: expr_int "+" expr_int
#line 605 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 1567 "frontend/parser.cpp"
    break;

  case 312: // expr_int: expr_int "<<" expr_int
#line 606 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 1573 "frontend/parser.cpp"
    break;

  case 313: // expr_int: expr_int ">>" expr_int
#line 607 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 1579 "frontend/parser.cpp"
    break;

  case 314: // expr_int: expr_int "&" expr_int
#line 608 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 1585 "frontend/parser.cpp"
    break;

  case 315: // expr_int: expr_int "^" expr_int
#line 609 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 1591 "frontend/parser.cpp"
    break;

  case 316: // expr_int: expr_int "|" expr_int
#line 610 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 1597 "frontend/parser.cpp"
    break;

  case 317: // expr_float: "float"
#line 614 "frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 1603 "frontend/parser.cpp"
    break;

  case 318: // expr_float: "-" expr_float
#line 615 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 1609 "frontend/parser.cpp"
    break;

  case 319: // expr_float: "(" expr_float ")"
#line 616 "frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 1615 "frontend/parser.cpp"
    break;

  case 320: // expr_float: expr_float "**" expr_float
#line 617 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 1621 "frontend/parser.cpp"
    break;

  case 321: // expr_float: expr_float "**" expr_int
#line 618 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 1627 "frontend/parser.cpp"
    break;

  case 322: // expr_float: expr_int "**" expr_float
#line 619 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 1633 "frontend/parser.cpp"
    break;

  case 323: // expr_float: expr_float "*" expr_float
#line 620 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 1639 "frontend/parser.cpp"
    break;

  case 324: // expr_float: expr_float "*" expr_int
#line 621 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 1645 "frontend/parser.cpp"
    break;

  case 325: // expr_float: expr_int "*" expr_float
#line 622 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 1651 "frontend/parser.cpp"
    break;

  case 326: // expr_float: expr_float "/" expr_float
#line 623 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 1657 "frontend/parser.cpp"
    break;

  case 327: // expr_float: expr_float "/" expr_int
#line 624 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 1663 "frontend/parser.cpp"
    break;

  case 328: // expr_float: expr_int "/" expr_float
#line 625 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 1669 "frontend/parser.cpp"
    break;

  case 329: // expr_float: expr_float "%" expr_float
#line 626 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 1675 "frontend/parser.cpp"
    break;

  case 330: // expr_float: expr_float "%" expr_int
#line 627 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 1681 "frontend/parser.cpp"
    break;

  case 331: // expr_float: expr_int "%" expr_float
#line 628 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 1687 "frontend/parser.cpp"
    break;

  case 332: // expr_float: expr_float "-" expr_float
#line 629 "frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 1693 "frontend/parser.cpp"
    break;

  case 333: // expr_float: expr_float "-" expr_int
#line 630 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 1699 "frontend/parser.cpp"
    break;

  case 334: // expr_float: expr_int "-" expr_float
#line 631 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 1705 "frontend/parser.cpp"
    break;

  case 335: // expr_float: expr_float "+" expr_float
#line 632 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 1711 "frontend/parser.cpp"
    break;

  case 336: // expr_float: expr_float "+" expr_int
#line 633 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 1717 "frontend/parser.cpp"
    break;

  case 337: // expr_float: expr_int "+" expr_float
#line 634 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 1723 "frontend/parser.cpp"
    break;

  case 338: // expr_str: "string"
#line 638 "frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1729 "frontend/parser.cpp"
    break;

  case 339: // expr_str: "(" expr_str ")"
#line 639 "frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 1735 "frontend/parser.cpp"
    break;

  case 340: // expr_str: expr_str "++" expr_str
#line 640 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 1741 "frontend/parser.cpp"
    break;

  case 341: // expr_str: expr_str "++" expr_int
#line 641 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 1747 "frontend/parser.cpp"
    break;

  case 342: // expr_str: expr_str "++" expr_float
#line 642 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 1753 "frontend/parser.cpp"
    break;

  case 343: // expr_str: expr_str "++" expr_bool
#line 643 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1759 "frontend/parser.cpp"
    break;

  case 344: // expr_str: expr_str "++" expr_none
#line 644 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 1765 "frontend/parser.cpp"
    break;

  case 345: // expr_str: expr_int "++" expr_str
#line 645 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 1771 "frontend/parser.cpp"
    break;

  case 346: // expr_str: expr_int "++" expr_int
#line 646 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 1777 "frontend/parser.cpp"
    break;

  case 347: // expr_str: expr_int "++" expr_float
#line 647 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 1783 "frontend/parser.cpp"
    break;

  case 348: // expr_str: expr_int "++" expr_bool
#line 648 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1789 "frontend/parser.cpp"
    break;

  case 349: // expr_str: expr_int "++" expr_none
#line 649 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 1795 "frontend/parser.cpp"
    break;

  case 350: // expr_str: expr_float "++" expr_str
#line 650 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 1801 "frontend/parser.cpp"
    break;

  case 351: // expr_str: expr_float "++" expr_int
#line 651 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 1807 "frontend/parser.cpp"
    break;

  case 352: // expr_str: expr_float "++" expr_float
#line 652 "frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 1813 "frontend/parser.cpp"
    break;

  case 353: // expr_str: expr_float "++" expr_bool
#line 653 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1819 "frontend/parser.cpp"
    break;

  case 354: // expr_str: expr_float "++" expr_none
#line 654 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 1825 "frontend/parser.cpp"
    break;

  case 355: // expr_str: expr_bool "++" expr_str
#line 655 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 1831 "frontend/parser.cpp"
    break;

  case 356: // expr_str: expr_bool "++" expr_int
#line 656 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 1837 "frontend/parser.cpp"
    break;

  case 357: // expr_str: expr_bool "++" expr_float
#line 657 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 1843 "frontend/parser.cpp"
    break;

  case 358: // expr_str: expr_bool "++" expr_bool
#line 658 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1849 "frontend/parser.cpp"
    break;

  case 359: // expr_str: expr_bool "++" expr_none
#line 659 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 1855 "frontend/parser.cpp"
    break;

  case 360: // expr_str: expr_none "++" expr_str
#line 660 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 1861 "frontend/parser.cpp"
    break;

  case 361: // expr_str: expr_none "++" expr_int
#line 661 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 1867 "frontend/parser.cpp"
    break;

  case 362: // expr_str: expr_none "++" expr_float
#line 662 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 1873 "frontend/parser.cpp"
    break;

  case 363: // expr_str: expr_none "++" expr_bool
#line 663 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1879 "frontend/parser.cpp"
    break;

  case 364: // expr_str: expr_none "++" expr_none
#line 664 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 1885 "frontend/parser.cpp"
    break;

  case 365: // expr_bool: "bool"
#line 668 "frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 1891 "frontend/parser.cpp"
    break;

  case 366: // expr_bool: "(" expr_bool ")"
#line 669 "frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 1897 "frontend/parser.cpp"
    break;

  case 367: // expr_bool: "not" expr_bool
#line 670 "frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 1903 "frontend/parser.cpp"
    break;

  case 368: // expr_bool: expr_bool "or" expr_bool
#line 671 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 1909 "frontend/parser.cpp"
    break;

  case 369: // expr_bool: expr_bool "and" expr_bool
#line 672 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 1915 "frontend/parser.cpp"
    break;

  case 370: // expr_bool: expr_bool "==" expr_bool
#line 674 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 1921 "frontend/parser.cpp"
    break;

  case 371: // expr_bool: expr_int "==" expr_int
#line 675 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 1927 "frontend/parser.cpp"
    break;

  case 372: // expr_bool: expr_int "==" expr_float
#line 676 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 1933 "frontend/parser.cpp"
    break;

  case 373: // expr_bool: expr_float "==" expr_float
#line 677 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 1939 "frontend/parser.cpp"
    break;

  case 374: // expr_bool: expr_float "==" expr_int
#line 678 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 1945 "frontend/parser.cpp"
    break;

  case 375: // expr_bool: expr_str "==" expr_str
#line 679 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 1951 "frontend/parser.cpp"
    break;

  case 376: // expr_bool: expr_none "==" expr_none
#line 680 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 1957 "frontend/parser.cpp"
    break;

  case 377: // expr_bool: expr_bool "!=" expr_bool
#line 682 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 1963 "frontend/parser.cpp"
    break;

  case 378: // expr_bool: expr_int "!=" expr_int
#line 683 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 1969 "frontend/parser.cpp"
    break;

  case 379: // expr_bool: expr_int "!=" expr_float
#line 684 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 1975 "frontend/parser.cpp"
    break;

  case 380: // expr_bool: expr_float "!=" expr_float
#line 685 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 1981 "frontend/parser.cpp"
    break;

  case 381: // expr_bool: expr_float "!=" expr_int
#line 686 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 1987 "frontend/parser.cpp"
    break;

  case 382: // expr_bool: expr_str "!=" expr_str
#line 687 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 1993 "frontend/parser.cpp"
    break;

  case 383: // expr_bool: expr_none "!=" expr_none
#line 688 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 1999 "frontend/parser.cpp"
    break;

  case 384: // expr_bool: expr_int ">" expr_int
#line 690 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 2005 "frontend/parser.cpp"
    break;

  case 385: // expr_bool: expr_int ">" expr_float
#line 691 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 2011 "frontend/parser.cpp"
    break;

  case 386: // expr_bool: expr_float ">" expr_float
#line 692 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 2017 "frontend/parser.cpp"
    break;

  case 387: // expr_bool: expr_float ">" expr_int
#line 693 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 2023 "frontend/parser.cpp"
    break;

  case 388: // expr_bool: expr_str ">" expr_str
#line 694 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 2029 "frontend/parser.cpp"
    break;

  case 389: // expr_bool: expr_int "<" expr_int
#line 696 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 2035 "frontend/parser.cpp"
    break;

  case 390: // expr_bool: expr_int "<" expr_float
#line 697 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 2041 "frontend/parser.cpp"
    break;

  case 391: // expr_bool: expr_float "<" expr_float
#line 698 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 2047 "frontend/parser.cpp"
    break;

  case 392: // expr_bool: expr_float "<" expr_int
#line 699 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 2053 "frontend/parser.cpp"
    break;

  case 393: // expr_bool: expr_str "<" expr_str
#line 700 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 2059 "frontend/parser.cpp"
    break;

  case 394: // expr_bool: expr_int ">=" expr_int
#line 702 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 2065 "frontend/parser.cpp"
    break;

  case 395: // expr_bool: expr_int ">=" expr_float
#line 703 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 2071 "frontend/parser.cpp"
    break;

  case 396: // expr_bool: expr_float ">=" expr_float
#line 704 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 2077 "frontend/parser.cpp"
    break;

  case 397: // expr_bool: expr_float ">=" expr_int
#line 705 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 2083 "frontend/parser.cpp"
    break;

  case 398: // expr_bool: expr_str ">=" expr_str
#line 706 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 2089 "frontend/parser.cpp"
    break;

  case 399: // expr_bool: expr_int "<=" expr_int
#line 708 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 2095 "frontend/parser.cpp"
    break;

  case 400: // expr_bool: expr_int "<=" expr_float
#line 709 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 2101 "frontend/parser.cpp"
    break;

  case 401: // expr_bool: expr_float "<=" expr_float
#line 710 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 2107 "frontend/parser.cpp"
    break;

  case 402: // expr_bool: expr_float "<=" expr_int
#line 711 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 2113 "frontend/parser.cpp"
    break;

  case 403: // expr_bool: expr_str "<=" expr_str
#line 712 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 2119 "frontend/parser.cpp"
    break;

  case 404: // expr_bool: expr_str "in" expr_str
#line 714 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[0].value.as < std::string > ().find(yystack_[2].value.as < std::string > ()) != std::string::npos; }
#line 2125 "frontend/parser.cpp"
    break;

  case 421: // type: "\"int\"" "?"
#line 742 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2131 "frontend/parser.cpp"
    break;

  case 422: // type: "\"float\"" "?"
#line 743 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2137 "frontend/parser.cpp"
    break;

  case 423: // type: "\"string\"" "?"
#line 744 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2143 "frontend/parser.cpp"
    break;

  case 424: // type: "\"bool\"" "?"
#line 745 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2149 "frontend/parser.cpp"
    break;

  case 425: // type: "identifier" "?"
#line 746 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2155 "frontend/parser.cpp"
    break;

  case 426: // type: funtype "?"
#line 747 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2161 "frontend/parser.cpp"
    break;

  case 427: // type: mattype "?"
#line 748 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2167 "frontend/parser.cpp"
    break;

  case 428: // type: "\"int\""
#line 749 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("int"); }
#line 2173 "frontend/parser.cpp"
    break;

  case 429: // type: "\"float\""
#line 750 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("float"); }
#line 2179 "frontend/parser.cpp"
    break;

  case 430: // type: "\"string\""
#line 751 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("string"); }
#line 2185 "frontend/parser.cpp"
    break;

  case 431: // type: "\"bool\""
#line 752 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("bool"); }
#line 2191 "frontend/parser.cpp"
    break;

  case 432: // type: "identifier"
#line 753 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[0].value.as < std::string > ()); }
#line 2197 "frontend/parser.cpp"
    break;

  case 433: // type: funtype
#line 754 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2203 "frontend/parser.cpp"
    break;

  case 434: // type: mattype
#line 755 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2209 "frontend/parser.cpp"
    break;


#line 2213 "frontend/parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -713;

  const short  Parser ::yytable_ninf_ = -433;

  const short
   Parser ::yypact_[] =
  {
    1785,  -713,  -713,  -713,  -713,  -713,  -713,  -713,  1551,    29,
      52,   942,   304,   -47,   -32,    46,    93,   101,  1988,  1694,
    -713,  -713,     9,    -4,     1,     2,     6,   105,   117,   311,
      15,  1680,  -713,  -713,   217,   228,  -713,  -713,  -713,  -713,
    -713,  -713,  -713,   240,   250,   307,  1780,  2679,  -713,   531,
    -713,   151,   293,  3013,  1612,  1127,   491,   156,   247,     5,
     297,   221,  2650,   313,   531,   319,   120,   151,   293,  2414,
    2962,   456,   640,  1694,  -713,   221,   291,   242,   435,   435,
    -713,  -713,  -713,  1270,   204,  3068,  3042,   862,  -713,   304,
     304,  -713,   305,  -713,   295,  1694,   277,  1694,   342,  2553,
    -713,  -713,   301,  -713,   336,   493,  -713,   573,  -713,   825,
    -713,   864,  -713,    85,   371,   421,    51,  1694,  -713,  -713,
    -713,  -713,  -713,  2583,  -713,  -713,  -713,  -713,  -713,  -713,
    -713,  1694,  1694,  1694,  1694,  1694,  1694,  1694,  1694,  1694,
    1694,  1694,  1694,  1694,   333,   972,  1694,  1694,  1694,  1694,
    1694,  1694,  1694,  1694,  1694,  1694,  1694,  1694,  1694,  1694,
    1694,  1694,  1694,  1694,  1694,  1694,  1694,  1694,  -713,   972,
    1694,  1694,  1694,  1694,  1694,  1694,  -713,  1694,  1694,  1694,
    1694,  1694,  1694,  1694,  1694,  1694,  1694,  1694,  1694,  1694,
     435,  1694,  1694,  1694,  1694,  1694,  1694,  1694,  1694,  1694,
    1694,  1694,  1694,  1694,  1694,  1694,  1694,  1694,  1694,  1694,
    1694,  1694,  1694,  1694,  1694,  1694,  1694,  1694,  1694,  1694,
    1694,  1694,  1694,  1694,  1694,  1694,  1694,  1694,  1694,  1694,
    1694,  1694,  1694,  -713,  -713,    50,    21,  -713,   972,   374,
    -713,  -713,  -713,  1694,  1694,  -713,  -713,  -713,  -713,   324,
      43,   370,  -713,  1569,   740,   435,   435,   435,   435,   435,
     304,   304,   304,   304,   304,   435,   435,   435,   435,   435,
     435,  2934,  2990,   696,   829,   942,   268,   268,   942,   435,
     435,   435,   435,   435,   435,   942,   435,   435,   435,   435,
     435,   435,   942,   942,   942,   942,   942,   942,   942,   942,
     942,   942,   942,   942,   942,  1698,  -713,   304,   304,   304,
     304,   304,  1694,   318,   394,   366,   399,  2583,  -713,  1883,
     409,  1694,  -713,  2679,   391,  3013,  1612,  1127,   491,   424,
    -713,   426,  -713,   430,  -713,   434,   452,   331,    84,  -713,
     635,   155,   470,  -713,   400,   472,   164,  3013,  -713,  -713,
    2026,  -713,  -713,  -713,  -713,  -713,  -713,  -713,  -713,  -713,
    -713,  -713,  -713,  -713,   496,   475,    75,   372,   294,   651,
     681,   372,   294,   651,   681,   106,   492,   490,   533,   106,
     490,   533,   106,   490,   533,   106,   533,  2708,   321,   380,
    3093,  3185,   436,   602,  2737,   416,  2115,   326,  2766,   708,
    2877,  1741,  2797,  3139,  2842,  3162,  1096,   916,  1096,   916,
    2906,   463,  -713,  -713,  1900,  1489,   212,  -713,  2906,   463,
    -713,  -713,  1900,  1489,   212,  -713,  1050,  1449,  1104,   540,
    1050,  1449,  1104,   540,  1050,  1449,  1104,   540,  1050,  1449,
    1104,   540,   164,   116,   372,   294,   372,   294,   106,   492,
    2766,   589,  2906,   463,  2906,   463,  2708,   321,   380,  3093,
    3185,   436,   602,  2766,   589,  2906,  -713,  2906,  -713,  2708,
     321,   380,  3093,  3185,   436,   602,  2766,   589,  2906,  -713,
    2906,  -713,   372,   651,   681,   372,   651,   681,   106,   490,
     533,   106,   490,   533,   106,   490,   533,  1201,   535,  2708,
     321,   380,  3093,  3185,   436,   602,  2766,   589,  2877,  1741,
    2797,  3139,  2842,  3162,  1096,   916,  1096,   916,  2906,  1900,
    1489,  2906,  1900,  1489,  1050,  1449,  1104,  1050,  1449,  1104,
    1050,  1449,  1104,  1050,  1449,  1104,   372,   651,   681,   372,
     651,   681,   106,   490,   533,   106,   490,   533,   106,   490,
     533,   106,   490,   533,  2708,   321,   380,  3093,  3185,   436,
     602,  2766,   589,  2906,  1900,  1489,  2906,  1900,  1489,  1050,
    1449,  1104,  1050,  1449,  1104,  1050,  1449,  1104,  1050,  1449,
    1104,   545,  2708,   321,   380,  3093,  3185,   436,   602,  2766,
     589,   708,  2906,   212,  2906,   212,  1050,   540,  1050,   540,
    1050,   540,  1050,   540,  2708,   321,   380,  3093,  3185,   436,
     602,  2737,   416,  2115,   326,  2766,   589,  2906,  -713,  2906,
    -713,  -713,    18,   548,    35,    99,  1010,   170,  -713,   550,
     529,   549,  -713,  1694,  -713,  -713,   745,   872,   745,   872,
     490,   535,   490,   535,   490,   535,   404,   768,   788,   675,
     675,   745,   872,   745,   872,   490,   535,   490,   535,   490,
     535,   490,   535,   328,  3116,  3196,  1783,   239,   561,  -713,
    -713,   328,  3116,  3196,  1783,   239,  1521,  1154,  1521,  1154,
    1521,  1154,  1521,  1154,  1521,  1154,  1521,  1154,   328,  3116,
    3196,  1783,   239,  1521,  1154,  1521,  1154,  1521,  1154,  1521,
    1154,  1521,  1154,  1521,  1154,   328,  3116,  3196,  1783,   239,
    1158,   207,   950,   950,  -713,  -713,  -713,  -713,   328,  3116,
    3196,  1783,   239,   508,   241,  -713,  -713,   502,   502,  -713,
    -713,  -713,  -713,  -713,  1988,  1694,  1988,  1958,   567,  1694,
    -713,  1694,  -713,  -713,  -713,  -713,    36,    36,  -713,   497,
     560,   580,  -713,     7,    90,    56,   536,    14,  -713,  1125,
     181,  -713,   673,  -713,   546,  -713,  -713,  1694,  -713,  -713,
    -713,  1233,  -713,   523,    90,    61,  -713,  -713,  -713,  1694,
    -713,  -713,   297,   528,   586,  -713,   598,  -713,   593,  -713,
     609,  -713,   590,  -713,    36,   594,  -713,    90,   523,   523,
     603,  -713,   619,  -713,  1372,  -713,  1398,   185,  1694,  -713,
    -713,  -713,    90,   639,   643,   484,  1988,  -713,  -713,  -713,
    1694,  -713,  1694,  -713,   614,   536,    16,  1694,  -713,  -713,
     646,  -713,   648,  -713,  1447,   615,  -713,  -713,  1694,   657,
    1988,  -713,  -713,  -713,  -713,   603,  -713,  -713,  -713,  -713,
     663,   644,   677,  1694,  -713,  -713,  -713,  1988,   678,  -713,
    1988,  -713
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     7,   303,   317,   338,   365,   295,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      31,    32,     0,   428,   429,   430,   431,     0,     0,    93,
       0,     0,     4,     8,     0,     0,    33,    13,    15,    16,
      14,    17,    18,     0,     0,     0,     0,    86,   275,    85,
     276,    87,    88,    89,    90,    91,    92,   433,   434,     0,
     295,    93,   282,   275,     0,   276,     0,     0,     0,   281,
       0,     0,     0,     0,   267,    93,   272,     0,     0,     0,
      94,   304,   318,     0,     0,     0,     0,     0,   367,     0,
       0,   306,     0,    29,    28,     0,     0,     0,     0,     0,
      26,    27,     0,    35,     0,     0,   421,     0,   422,     0,
     423,     0,   424,     0,     0,     0,     0,     0,   425,   103,
     297,     1,     3,     0,     5,    12,    19,    10,    11,     9,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,     0,
       0,     0,     0,     0,     0,     0,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   426,   427,     0,    64,   296,     0,   297,
      95,   277,   278,     0,     0,   305,   319,   339,   366,     0,
       0,     0,   268,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   304,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,   412,   282,   419,   281,     0,     0,     0,     0,
     414,     0,   416,     0,   418,     0,     0,     0,     0,   410,
       0,     0,     0,   299,     0,     0,   105,     0,     6,    82,
      81,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    96,     0,    83,     0,   135,   133,   130,
     131,   143,   141,   138,   139,   117,   116,   112,   113,   122,
     120,   121,   127,   125,   126,   109,   108,   266,   264,   265,
     260,   261,   262,   263,   239,   238,   242,   241,   236,   235,
     214,   213,   220,   219,   217,   216,   146,   145,   149,   148,
     194,   192,   189,   190,   185,   186,   187,   188,   211,   209,
     206,   207,   202,   203,   204,   205,   156,   153,   154,   155,
     170,   167,   168,   169,   163,   160,   161,   162,   177,   174,
     175,   176,   106,     0,   134,   132,   142,   140,   115,   114,
     234,   227,   193,   191,   210,   208,   258,   364,   247,   361,
     362,   360,   363,   232,   225,   182,   376,   199,   383,   259,
     252,   253,   248,   249,   250,   251,   233,   226,   184,   183,
     201,   200,   128,   311,   337,   136,   310,   334,   110,   307,
     325,   118,   308,   328,   123,   309,   331,     0,   322,   254,
     349,   243,   346,   347,   345,   348,   228,   221,   212,   314,
     218,   316,   215,   315,   144,   312,   147,   313,   178,   371,
     372,   195,   378,   379,   150,   384,   385,   164,   389,   390,
     157,   394,   395,   171,   399,   400,   129,   336,   335,   137,
     333,   332,   111,   324,   323,   119,   327,   326,   124,   330,
     329,   107,   321,   320,   255,   354,   244,   351,   352,   350,
     353,   229,   222,   179,   374,   373,   196,   381,   380,   151,
     387,   386,   165,   392,   391,   158,   397,   396,   172,   402,
     401,     0,   256,   344,   245,   341,   342,   340,   343,   230,
     223,   404,   180,   375,   197,   382,   152,   388,   166,   393,
     159,   398,   173,   403,   257,   359,   246,   356,   357,   355,
     358,   237,   369,   240,   368,   231,   224,   181,   370,   198,
     377,   406,   432,     0,   407,     0,     0,     0,   298,     0,
       0,     0,   269,     0,   273,   270,   311,   337,   310,   334,
     307,   325,   308,   328,   309,   331,   314,   316,   315,   312,
     313,   336,   335,   333,   332,   324,   323,   327,   326,   330,
     329,   321,   320,   364,   361,   362,   360,   363,     0,   376,
     383,   349,   346,   347,   345,   348,   371,   372,   378,   379,
     384,   385,   389,   390,   394,   395,   399,   400,   354,   351,
     352,   350,   353,   374,   373,   381,   380,   387,   386,   392,
     391,   397,   396,   402,   401,   344,   341,   342,   340,   343,
     404,     0,   375,   382,   388,   393,   398,   403,   359,   356,
     357,   355,   358,   369,   368,   370,   377,   311,   310,   307,
     308,   309,    68,    30,     0,     0,     0,     0,    22,     0,
      67,     0,   411,   413,   415,   417,     0,    48,    45,     0,
       0,     0,    52,     0,     0,     0,    60,     0,   283,     0,
       0,   100,     0,   409,     0,   300,    97,     0,   101,    99,
      98,     0,   405,     0,     0,     0,    66,    65,   279,     0,
     271,   274,     0,    42,     0,    37,    23,    24,     0,   420,
       0,    49,     0,    46,    50,    64,    57,     0,     0,     0,
      59,   287,     0,   285,     0,   284,     0,     0,     0,    84,
     408,    55,     0,     0,     0,    44,     0,    25,    38,    47,
       0,    51,     0,    58,    61,    63,     0,     0,   290,   289,
       0,   288,     0,   286,     0,   301,    56,   280,     0,     0,
       0,    39,    36,    54,    53,     0,    62,   293,   292,   291,
       0,     0,     0,     0,    43,   294,   302,     0,     0,    40,
       0,    41
  };

  const short
   Parser ::yypgoto_[] =
  {
    -713,  -713,   -96,   -10,   -14,  -712,  -622,  -713,  -713,  -713,
    -713,  -713,  -713,  -713,  -713,  -713,  -713,  -713,  -670,  -713,
    -713,  -620,  -103,  -331,  -713,   578,   -56,  1300,  2311,   704,
     -71,   782,   705,   666,  1205,  1045,  1351,   -60,  -136,  2085,
       0,   233,   476,  -713,   -57,  -713,   -85,  -208
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    30,    31,    32,    33,   101,   102,    34,    94,    35,
      36,    37,    38,    39,    40,   815,   841,    41,   750,   751,
      42,   755,   756,    43,    44,    45,   364,    46,    47,    48,
      77,    64,    50,   324,   168,    67,    68,   120,   345,    53,
     326,   327,   328,    57,   623,    58,   342,    59
  };

  const short
   Parser ::yytable_[] =
  {
      54,   239,   249,   319,   100,   775,   752,   105,    70,    54,
      82,    86,   107,   109,   235,   121,   235,   111,    54,    54,
     329,   124,   331,   235,   333,   235,   335,   624,    92,   771,
     625,    54,    73,     3,     4,     5,     6,     7,     8,   747,
       9,    74,   796,    93,   235,    10,   633,     3,     4,     5,
       6,     7,     8,    11,     9,    95,     3,     4,    12,    10,
     621,    78,   811,   626,   106,   343,   797,    11,    79,   108,
     110,   812,    12,    54,   112,   773,   790,   791,   254,    82,
     236,    12,   795,   272,   104,   823,   118,   768,   336,   800,
     344,   845,   749,    98,   754,    54,   798,    54,   337,    54,
     836,   798,    96,    99,    75,    23,    24,    25,    26,   774,
      97,   622,   783,   348,   785,   144,   762,   145,    75,    23,
      24,    25,    26,    54,   821,   622,   151,    80,   769,   753,
     757,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,   167,   370,   374,   378,   381,
     384,   386,   391,    23,    24,    25,    26,   762,   243,   622,
     244,   415,   423,   428,   432,   436,   440,   761,    23,    24,
      25,    26,   177,   144,   622,   145,   178,   460,   824,   634,
     113,   473,   761,   179,   180,   484,   487,   490,   493,   496,
     498,   503,   114,   803,   842,   741,   762,   833,   520,   523,
     526,   529,   532,   535,   538,   541,   544,   547,   550,   553,
     558,   762,   565,   568,   571,   574,   577,   580,   854,   586,
     125,   737,   804,   218,   233,   275,   834,   608,   300,   301,
     302,   126,   238,    55,   116,   859,   276,   277,   861,   303,
     304,    71,    55,   127,    87,   251,   223,   224,   225,   226,
      54,    55,    55,   128,   252,   637,   639,   641,   643,   645,
     117,   301,   302,   301,    55,   652,   654,   656,   658,   660,
     662,   303,   304,   303,   304,   665,     7,   668,   673,   677,
     679,   681,   683,   685,   687,   690,   694,   696,   698,   700,
     702,   704,   707,    86,    86,    86,    86,    86,    86,    86,
     720,    86,    86,    86,    86,   169,    55,   237,     3,   124,
     129,   172,    54,    89,   181,   234,   273,    54,   182,    54,
      90,    54,   115,   241,   116,   183,   184,   631,    55,   242,
      55,   250,    55,    12,   747,   313,   632,     3,     4,     5,
       6,     7,     8,   363,     9,   748,   178,   312,   228,    10,
     117,   230,   315,   179,   180,   317,    55,    11,   231,   232,
     276,   277,    12,   320,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,   321,   118,
     338,   144,   635,   145,   628,   392,  -432,   749,   399,   148,
     149,   150,   151,   733,   416,   424,   429,   433,   437,   441,
      23,    24,    25,    26,   734,   182,   622,   735,    75,   736,
     461,   167,   183,   184,   474,   752,   752,   757,   739,   307,
     308,   309,   310,   311,   504,     3,     4,     5,     6,     7,
       8,   741,     9,   339,   263,   264,   742,    10,   743,     3,
       4,   230,   744,   559,    78,    11,   745,   218,   231,   232,
      12,    79,   587,   591,   593,   595,   597,   599,   601,   603,
     609,   220,   340,   752,    12,   746,   247,   218,   221,   222,
     223,   224,   225,   226,   169,   764,    56,   219,   170,   171,
     172,   220,   763,    55,    72,    56,   765,    88,   221,   222,
     223,   224,   225,   226,    56,    56,    75,     3,     4,     5,
       6,     7,     8,   169,     9,   322,   766,    56,   666,    10,
     190,   674,   227,   228,   229,   767,   230,    11,   691,   309,
     310,   311,    12,   231,   232,   708,   710,   712,   713,   714,
     715,   716,   717,   721,    87,    87,    87,    87,   753,   753,
     303,   304,   169,   839,   840,    55,   170,   171,   172,    56,
      55,   218,    55,   209,    55,   270,   173,   770,   772,   274,
     778,   780,   781,   174,   175,   624,   777,   779,    75,   782,
     787,    56,   792,    56,   793,    56,   799,     3,     4,     5,
       6,     7,     8,   794,     9,   330,   753,   814,   808,    10,
     757,   826,    23,    24,    25,    26,   816,    11,   622,    56,
     169,   817,    12,   818,   170,   171,   172,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,   174,   175,   819,   228,   229,    54,   230,   393,   395,
     397,   828,   820,    54,   231,   232,   822,   417,   425,     3,
       4,     5,     6,     7,     8,   827,     9,   758,    75,   837,
     248,    10,   838,   462,   798,   851,   789,   475,   847,    11,
     848,   227,   228,   229,    12,   230,   853,   505,   187,   188,
     189,   190,   231,   232,    66,   855,   759,     3,     4,     5,
       6,     7,     8,   344,     9,   805,   560,   857,   860,    10,
     307,   308,   309,   310,   311,   588,   825,    11,   206,   207,
     208,   209,    12,   610,   612,   614,   247,   618,   620,   349,
      75,   809,    63,    65,   806,   856,   810,   292,     0,   218,
     100,   293,   100,     0,     0,     0,    56,   124,   294,   295,
     296,   297,   298,   299,    54,    54,    54,    54,     0,    54,
     221,   222,   223,   224,   225,   226,     0,     0,    75,     0,
     246,   667,     0,     0,   675,   265,   266,   267,   268,   269,
     270,   692,   257,   258,   259,   190,     0,    54,   709,   711,
     711,   711,   711,   711,   711,   711,   722,   723,   724,   725,
     726,   341,    49,   307,   308,   309,   310,   311,    56,     0,
       0,    49,     0,    56,   260,    56,   262,    56,   263,   264,
      49,    49,   100,   307,   308,   309,   310,   311,    54,     0,
       0,   366,     0,    49,   260,     0,    54,     0,   263,   264,
      54,     0,    54,     0,     0,     0,   100,    54,     0,     3,
       4,     5,     6,     7,     8,   443,     9,   332,    54,   248,
      54,    10,     0,   100,     0,     0,   100,     0,     0,    11,
     300,   301,   302,    54,    12,    49,     0,    54,     0,    55,
      54,   303,   304,     0,     0,     0,    55,     0,     3,     4,
       5,     6,     7,     8,     0,     9,   334,    49,     0,    49,
      10,    49,     0,   292,   581,     0,     0,   293,    11,   267,
     268,   269,   270,    12,   294,   295,   296,   297,   298,   299,
      75,     0,     0,     0,   627,    49,     0,     0,     0,   629,
     630,     0,     0,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,     0,   368,   372,
     376,   185,   186,   187,   188,   189,   190,     0,     0,    75,
       0,     0,     0,   411,   419,     0,     3,     4,     5,     6,
       7,    83,   445,   447,   449,   451,   453,   455,    79,     0,
     464,     0,     0,     0,   477,     0,    11,    55,    55,    55,
      55,    12,    55,     0,   507,     0,     3,     4,     5,     6,
       7,     8,     0,     9,   296,   297,   298,   299,    10,     0,
       0,     0,     0,   562,     0,     0,    11,     0,     0,     0,
      55,    12,   590,     0,     0,     0,   760,     0,     0,     0,
       0,     0,   616,   340,     3,     4,     5,     6,     7,     8,
       0,     9,     0,   116,     0,     0,    10,     0,     0,     0,
       0,     0,    49,     0,    11,     0,     0,     0,     0,    12,
       0,    55,     0,     0,     0,    51,     0,    75,     0,    55,
       0,     0,     0,    55,    51,    55,    84,     0,     0,   144,
      55,   145,     0,    51,    51,   146,   147,   148,   149,   150,
     151,    55,     0,    55,     0,     0,    51,     0,     0,     0,
     159,   160,     0,     0,     0,    75,    55,     0,     0,   167,
      55,     0,     0,    55,    49,     0,     0,     0,     0,    49,
       0,    49,    56,    49,     0,   144,     0,   145,     0,    56,
       0,   146,   147,   148,   149,   150,   151,     0,    51,   204,
     205,   206,   207,   208,   209,     0,     0,     0,    84,     3,
       4,     5,     6,     7,     8,   167,     9,   801,   218,     0,
      51,    10,    51,     0,    51,     0,     0,     0,   219,    11,
       0,     0,   220,     0,    12,     0,     0,     0,     0,   221,
     222,   223,   224,   225,   226,     0,     0,     0,    51,   265,
     266,   267,   268,   269,   270,     0,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
     294,   295,   296,   297,   298,   299,     0,   388,     0,     0,
      75,     0,     0,     0,     0,     0,   412,   420,     0,     0,
      56,    56,    56,    56,     0,    56,   255,   256,   257,   258,
     259,   190,   457,     0,   466,   468,   470,   260,   261,   262,
       0,   263,   264,     0,   119,     0,   500,     3,     4,     5,
       6,     7,     8,    56,     9,   339,     0,     0,     0,    10,
       0,     0,     0,     0,   176,   555,     0,    11,     0,     0,
       0,     0,    12,     0,   583,     0,   119,     0,     0,   176,
       0,     0,   605,     0,     3,     4,     5,     6,    60,    83,
     119,     0,     0,     0,    56,     0,    79,     0,     0,     0,
       0,     0,    56,     0,    11,    51,    56,     0,    56,    12,
       0,     0,     0,    56,     0,     0,     0,     0,    75,    76,
       0,     0,     0,     0,    56,     0,    56,     0,     0,   103,
     663,   669,   670,   671,     0,     0,     0,     0,     0,    56,
     688,     0,     0,    56,     0,     0,    56,   705,    84,    84,
      84,    84,    84,    84,    84,   718,    84,    84,    84,    84,
       0,    52,     0,     0,     0,     0,     0,    51,     0,     0,
      52,     0,    51,     0,    51,     0,    51,     0,     0,    52,
      52,     0,     0,    76,     0,     0,     3,     4,     5,     6,
       7,     8,    52,     9,   829,     0,     0,     0,    10,     0,
       0,     0,     0,     0,     0,   314,    11,   316,     0,     0,
       0,    12,     3,     4,     5,     6,     7,     8,    49,     9,
     831,     0,     0,     0,    10,    49,     0,     0,     0,     0,
       0,     0,    11,     0,    52,   802,     0,    12,   807,     0,
       0,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   365,   813,    52,    75,    52,     0,
      52,     3,     4,     5,     6,     7,     8,     0,     9,   849,
       0,     0,     0,    10,   185,   186,   187,   188,   189,   190,
     830,    11,   832,    75,    52,     0,    12,     0,     0,   196,
     197,     0,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,     0,     0,     0,     0,
     850,     0,     0,   389,   204,   205,   206,   207,   208,   209,
       0,     0,   413,   421,     0,     0,    49,    49,    49,    49,
       0,    49,    75,   214,   215,   216,   217,     0,   458,     0,
       0,     0,   471,     0,   479,   481,   255,   256,   257,   258,
     259,   190,   501,     0,     0,     0,     0,     0,     0,    49,
      76,   263,   264,     0,     0,     3,     4,     5,     6,    60,
       8,   556,     9,     0,     0,     0,     0,    10,     0,     0,
     584,     0,     0,   176,     0,    11,     0,   176,   606,   245,
      12,   176,     0,     0,   255,   256,   257,   258,   259,   190,
      49,     0,     0,     0,     0,   260,   261,   262,    49,   263,
     264,    52,    49,     0,    49,     0,     0,     0,     0,    49,
       0,     0,   732,     0,     0,     0,   176,     0,     0,     0,
      49,   740,    49,     0,   176,     0,    61,   204,   205,   206,
     207,   208,   209,   210,     0,    49,     0,   211,     0,    49,
       0,     0,    49,     0,   212,   213,   214,   215,   216,   217,
     176,     0,   176,     0,   176,     0,   176,     0,   176,     0,
     176,     0,     0,    52,     0,     0,     0,     0,    52,   176,
      52,    51,    52,     0,     0,     0,     0,     0,    51,     0,
     122,   123,   176,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,     0,     0,    10,     0,     3,     4,
       5,     6,     7,     8,    11,     9,     0,     0,   245,    12,
      10,     0,   176,   307,   308,   309,   310,   311,    11,     0,
       0,     0,     0,    12,   260,   261,   262,     0,   263,   264,
       0,     0,     0,     0,     0,     0,    13,    14,    15,     0,
       0,    16,    17,    18,    19,    20,    21,    22,     0,    23,
      24,    25,    26,    27,    28,    29,   185,   186,   187,   188,
     189,   190,     0,     0,     0,     0,     0,   176,     0,    75,
       0,   196,   197,   198,   199,   200,   201,   202,   203,    51,
      51,    51,    51,   130,    51,     1,     0,     0,     2,     3,
       4,     5,     6,     7,     8,   176,     9,     0,     0,     0,
       0,    10,     0,     0,     0,     0,     0,     0,   293,    11,
       0,     0,    51,     0,    12,   294,   295,   296,   297,   298,
     299,   176,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,   142,   143,     0,     0,     0,     0,
       0,    13,    14,    15,     0,     0,    16,    17,    18,    19,
      20,    21,    22,    51,    23,    24,    25,    26,    27,    28,
      29,    51,     0,     0,     0,    51,     0,    51,     0,     0,
       0,     0,    51,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    51,   123,    51,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,   738,    51,    10,
       0,     0,    51,     0,     0,    51,     0,    11,     0,     0,
       0,     0,    12,     0,     0,   185,   186,   187,   188,   189,
     190,     0,     0,     0,     0,     0,   776,     0,     0,     0,
     196,   197,     0,    76,   200,   201,   202,   203,     0,    13,
      14,    15,     0,     0,    16,    17,    18,    19,    20,    21,
      22,     0,    23,    24,    25,    26,    27,    28,    29,   123,
       0,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,   786,     0,    10,     0,     0,    52,     0,     0,
       0,     0,    11,     0,    52,     0,     0,    12,     0,     0,
       0,    98,     3,     4,     5,     6,     7,     8,     0,     9,
       0,    99,     0,     0,    10,     0,     0,     0,     0,     0,
       0,     0,    11,     0,    13,    14,    15,    12,     0,    16,
      17,    18,    19,    20,    21,    22,     0,    23,    24,    25,
      26,    27,    28,    29,     0,   784,     0,     0,     0,   788,
       0,     0,     0,     0,    13,    14,    15,     0,     0,    16,
      17,    18,    19,    20,    21,    22,     0,    23,    24,    25,
      26,    27,    28,    29,     0,     0,     0,   365,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
     142,   143,     0,     0,     0,    52,    52,    52,    52,     0,
      52,     0,     0,    69,     0,    81,    85,    91,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   835,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,     0,
     843,     0,   844,     0,   144,     0,   145,   846,     0,     0,
     146,   147,   148,   149,   150,   151,     0,   153,   852,     0,
     155,   156,   157,   158,     0,   159,   160,   161,   162,   163,
     164,   165,   166,   858,   167,     0,     0,     0,     0,    52,
       0,     0,     0,   253,    81,     0,     0,    52,   271,     0,
       0,    52,     0,    52,   305,   306,     0,     0,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
     325,    52,   325,     0,   325,     0,   325,     0,     0,     0,
     325,     0,   347,     0,    52,     0,     0,     0,    52,     0,
       0,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     325,   369,   373,   377,   380,   383,   347,   390,   347,   347,
     347,   401,   403,   405,   407,   409,   414,   422,   427,   431,
     435,   439,   347,     0,   325,   347,   347,   347,   347,   347,
     347,     0,   459,   347,   347,   347,   472,   347,   347,   347,
     483,   486,   489,   492,   495,   497,   502,   347,   509,   511,
     513,   515,   517,   519,   522,   525,   528,   531,   534,   537,
     540,   543,   546,   549,   552,   557,   347,   564,   567,   570,
     573,   576,   579,   325,   585,   347,   347,   347,   347,   347,
     347,   347,   607,   347,   347,   347,   347,   347,     0,    62,
       0,     0,     0,   325,     0,     0,     0,     0,   325,   325,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     636,   638,   640,   642,   644,   646,   647,   648,   649,   650,
     651,   653,   655,   657,   659,   661,     0,     0,     0,     0,
     664,     0,     0,   672,   676,   678,   680,   682,   684,   686,
     689,   693,   695,   697,   699,   701,   703,   706,    85,    85,
      85,    85,    85,    85,    85,   719,    85,    85,    85,    85,
       0,     0,   727,   728,   729,   730,   731,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   323,     0,   323,     0,
     323,     0,   323,     0,   245,   325,   323,     0,   346,   185,
     186,   187,   188,   189,   190,   191,     0,     0,     0,   192,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,     0,     0,     0,     0,   323,   367,   371,   375,
     379,   382,   385,   387,   394,   396,   398,   400,   402,   404,
     406,   408,   410,   418,   426,   430,   434,   438,   442,     0,
     323,   444,   446,   448,   450,   452,   454,     0,   456,   463,
     465,   467,   469,   476,   478,   480,   482,   485,   488,   491,
     494,     0,   499,   506,   508,   510,   512,   514,   516,   518,
     521,   524,   527,   530,   533,   536,   539,   542,   545,   548,
     551,   554,   561,   563,   566,   569,   572,   575,   578,   323,
     582,   589,   592,   594,   596,   598,   600,   602,   604,   611,
     613,   615,   617,   619,     0,     0,     0,     0,     0,   323,
       0,     0,     0,     0,   323,   323,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,   318,     0,    10,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     0,
       0,     0,    12,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,     0,    10,
       0,     0,     0,     0,     0,     0,     0,    11,     0,    13,
      14,    15,    12,     0,    16,    17,    18,    19,    20,    21,
      22,     0,    23,    24,    25,    26,    27,    28,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
      14,    15,     0,     0,    16,    17,    18,    19,    20,    21,
      22,   323,    23,    24,    25,    26,    27,    28,    29,   144,
     240,   145,     0,     0,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,     0,   155,   156,   157,   158,     0,
     159,   160,   161,   162,   163,   164,   165,   166,   144,   167,
     145,     0,     0,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,   155,   156,   157,   158,     0,   159,
     160,   161,   162,   163,   164,   165,   166,   144,   167,   145,
       0,     0,     0,   146,   147,   148,   149,   150,   151,     0,
     153,   154,     0,   155,   156,   157,   158,     0,   159,   160,
     161,   162,   163,   164,   165,   166,   144,   167,   145,     0,
       0,     0,   146,   147,   148,   149,   150,   151,     0,     0,
       0,     0,   155,   156,   157,   158,     0,   159,   160,   161,
     162,   163,   164,   165,   166,   144,   167,   145,     0,     0,
       0,   146,   147,   148,   149,   150,   151,     0,     0,     0,
       0,     0,   156,   157,   158,     0,   159,   160,   161,   162,
     163,   164,   165,   166,     0,   167,   144,     0,   145,     0,
       0,     0,   146,   147,   148,   149,   150,   151,     0,     0,
       0,     0,     0,   156,     0,   158,   325,   159,   160,   161,
     162,   163,   164,   165,   166,     0,   167,     0,     0,     0,
       0,     0,     0,     0,   325,     0,     0,   325,     0,     0,
       0,   144,     0,   145,     0,     0,   325,   146,   147,   148,
     149,   150,   151,     0,   325,     0,     0,     0,   156,     0,
       0,     0,   159,   160,   161,   162,   163,   164,   165,   166,
       0,   167,     0,     0,     0,     0,   144,     0,   145,   325,
       0,   325,   146,   147,   148,   149,   150,   151,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   159,   160,   161,
     162,   163,   164,   165,   166,   144,   167,   145,     0,   325,
       0,   146,   147,   148,   149,   150,   151,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   159,   160,     0,     0,
     163,   164,   165,   166,   245,   167,     0,     0,     0,   255,
     256,   257,   258,   259,   190,   278,     0,     0,     0,     0,
     260,   261,   262,     0,   263,   264,   279,   280,   281,   282,
     283,   284,   246,     0,     0,     0,     0,   204,   205,   206,
     207,   208,   209,   210,     0,     0,     0,   211,     0,     0,
       0,     0,     0,     0,   212,   213,   214,   215,   216,   217,
     246,     0,     0,     0,     0,   265,   266,   267,   268,   269,
     270,   285,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   286,   287,   288,   289,   290,   291,   185,   186,
     187,   188,   189,   190,   191,     0,     0,     0,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,     0,   323,     0,     0,     0,     0,   265,   266,   267,
     268,   269,   270,   285,     0,     0,     0,     0,     0,     0,
     323,     0,     0,   323,   286,   287,   288,   289,   290,   291,
       0,     0,   323,   255,   256,   257,   258,   259,   190,   278,
     323,     0,     0,     0,   260,   261,   262,     0,   263,   264,
     279,   280,   281,   282,   283,   284,     0,     0,   185,   186,
     187,   188,   189,   190,     0,   323,     0,   323,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   255,   256,   257,   258,   259,   190,     0,     0,     0,
       0,     0,   260,   261,   262,   323,   263,   264,   279,   280,
     281,   282,   283,   284,   185,   186,   187,   188,   189,   190,
       0,     0,     0,     0,     0,   193,     0,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   185,   186,   187,
     188,   189,   190,     0,     0,     0,     0,     0,   193,     0,
       0,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,     0,     0,     0,     0,
     211,   265,   266,   267,   268,   269,   270,   212,   213,   214,
     215,   216,   217,     0,     0,     0,     0,     0,   286,   287,
     288,   289,   290,   291
  };

  const short
   Parser ::yycheck_[] =
  {
       0,    61,    73,    99,    18,   625,   337,    11,     8,     9,
      10,    11,    11,    11,     9,     0,     9,    11,    18,    19,
     105,    31,   107,     9,   109,     9,   111,   235,    75,    11,
       9,    31,     3,     4,     5,     6,     7,     8,     9,     3,
      11,    12,   754,    75,     9,    16,     3,     4,     5,     6,
       7,     8,     9,    24,    11,     9,     4,     5,    29,    16,
      10,     9,   774,    42,    68,    14,    10,    24,    16,    68,
      68,    10,    29,    73,    68,    40,   746,   747,    78,    79,
      75,    29,    75,    83,    75,   797,    68,    12,     3,    75,
      39,    75,    56,     3,    10,    95,    40,    97,    13,    99,
     812,    40,     9,    13,    75,    69,    70,    71,    72,    10,
       9,    75,   734,   123,   736,     9,    41,    11,    75,    69,
      70,    71,    72,   123,   794,    75,    20,    75,    12,   337,
     338,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,    39,   146,   147,   148,   149,
     150,   151,   152,    69,    70,    71,    72,    41,    38,    75,
      40,   161,   162,   163,   164,   165,   166,    12,    69,    70,
      71,    72,    21,     9,    75,    11,    25,   177,   798,   250,
      75,   181,    12,    32,    33,   185,   186,   187,   188,   189,
     190,   191,    75,    12,   816,    40,    41,    12,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    41,   212,   213,   214,   215,   216,   217,   840,   219,
       3,   317,    41,    11,    68,    21,    41,   227,    21,    22,
      23,     3,    11,     0,    13,   857,    32,    33,   860,    32,
      33,     8,     9,     3,    11,     3,    34,    35,    36,    37,
     250,    18,    19,     3,    12,   255,   256,   257,   258,   259,
      39,    22,    23,    22,    31,   265,   266,   267,   268,   269,
     270,    32,    33,    32,    33,   275,     8,     9,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,    11,    73,    10,     4,   319,
       3,    17,   312,     9,    21,    68,    83,   317,    25,   319,
      16,   321,    11,    10,    13,    32,    33,     3,    95,    10,
      97,    40,    99,    29,     3,    40,    12,     4,     5,     6,
       7,     8,     9,    10,    11,    14,    25,    42,    22,    16,
      39,    25,    75,    32,    33,    13,   123,    24,    32,    33,
      32,    33,    29,    62,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    42,    68,
       9,     9,    12,    11,    10,   152,    75,    56,   155,    17,
      18,    19,    20,    75,   161,   162,   163,   164,   165,   166,
      69,    70,    71,    72,    10,    25,    75,    41,    75,    10,
     177,    39,    32,    33,   181,   746,   747,   625,     9,    15,
      16,    17,    18,    19,   191,     4,     5,     6,     7,     8,
       9,    40,    11,    12,    30,    31,    12,    16,    12,     4,
       5,    25,    12,   210,     9,    24,    12,    11,    32,    33,
      29,    16,   219,   220,   221,   222,   223,   224,   225,   226,
     227,    25,    41,   794,    29,    13,    10,    11,    32,    33,
      34,    35,    36,    37,    11,    75,     0,    21,    15,    16,
      17,    25,    12,   250,     8,     9,    14,    11,    32,    33,
      34,    35,    36,    37,    18,    19,    75,     4,     5,     6,
       7,     8,     9,    11,    11,    12,    10,    31,   275,    16,
      20,   278,    21,    22,    23,    40,    25,    24,   285,    17,
      18,    19,    29,    32,    33,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   746,   747,
      32,    33,    11,    59,    60,   312,    15,    16,    17,    73,
     317,    11,   319,    20,   321,    20,    25,    12,    10,    83,
      10,    12,   633,    32,    33,   773,   626,    38,    75,     8,
       3,    95,    75,    97,    14,    99,    40,     4,     5,     6,
       7,     8,     9,     3,    11,    12,   794,    59,    42,    16,
     798,   799,    69,    70,    71,    72,    10,    24,    75,   123,
      11,     3,    29,    10,    15,    16,    17,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    32,    33,    14,    22,    23,   626,    25,   152,   153,
     154,    12,    42,   633,    32,    33,    42,   161,   162,     4,
       5,     6,     7,     8,     9,    42,    11,    12,    75,    10,
      10,    16,     9,   177,    40,    40,   741,   181,    12,    24,
      12,    21,    22,    23,    29,    25,     9,   191,    17,    18,
      19,    20,    32,    33,     8,    12,    41,     4,     5,     6,
       7,     8,     9,    39,    11,    12,   210,    10,    10,    16,
      15,    16,    17,    18,    19,   219,   799,    24,    17,    18,
      19,    20,    29,   227,   228,   229,    10,   231,   232,   131,
      75,   767,     8,     8,    41,   851,   773,    21,    -1,    11,
     734,    25,   736,    -1,    -1,    -1,   250,   737,    32,    33,
      34,    35,    36,    37,   734,   735,   736,   737,    -1,   739,
      32,    33,    34,    35,    36,    37,    -1,    -1,    75,    -1,
      10,   275,    -1,    -1,   278,    15,    16,    17,    18,    19,
      20,   285,    17,    18,    19,    20,    -1,   767,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   115,     0,    15,    16,    17,    18,    19,   312,    -1,
      -1,     9,    -1,   317,    26,   319,    28,   321,    30,    31,
      18,    19,   816,    15,    16,    17,    18,    19,   808,    -1,
      -1,   145,    -1,    31,    26,    -1,   816,    -1,    30,    31,
     820,    -1,   822,    -1,    -1,    -1,   840,   827,    -1,     4,
       5,     6,     7,     8,     9,   169,    11,    12,   838,    10,
     840,    16,    -1,   857,    -1,    -1,   860,    -1,    -1,    24,
      21,    22,    23,   853,    29,    73,    -1,   857,    -1,   626,
     860,    32,    33,    -1,    -1,    -1,   633,    -1,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    95,    -1,    97,
      16,    99,    -1,    21,   218,    -1,    -1,    25,    24,    17,
      18,    19,    20,    29,    32,    33,    34,    35,    36,    37,
      75,    -1,    -1,    -1,   238,   123,    -1,    -1,    -1,   243,
     244,    -1,    -1,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,    -1,   146,   147,
     148,    15,    16,    17,    18,    19,    20,    -1,    -1,    75,
      -1,    -1,    -1,   161,   162,    -1,     4,     5,     6,     7,
       8,     9,   170,   171,   172,   173,   174,   175,    16,    -1,
     178,    -1,    -1,    -1,   182,    -1,    24,   734,   735,   736,
     737,    29,   739,    -1,   192,    -1,     4,     5,     6,     7,
       8,     9,    -1,    11,    34,    35,    36,    37,    16,    -1,
      -1,    -1,    -1,   211,    -1,    -1,    24,    -1,    -1,    -1,
     767,    29,   220,    -1,    -1,    -1,   340,    -1,    -1,    -1,
      -1,    -1,   230,    41,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    13,    -1,    -1,    16,    -1,    -1,    -1,
      -1,    -1,   250,    -1,    24,    -1,    -1,    -1,    -1,    29,
      -1,   808,    -1,    -1,    -1,     0,    -1,    75,    -1,   816,
      -1,    -1,    -1,   820,     9,   822,    11,    -1,    -1,     9,
     827,    11,    -1,    18,    19,    15,    16,    17,    18,    19,
      20,   838,    -1,   840,    -1,    -1,    31,    -1,    -1,    -1,
      30,    31,    -1,    -1,    -1,    75,   853,    -1,    -1,    39,
     857,    -1,    -1,   860,   312,    -1,    -1,    -1,    -1,   317,
      -1,   319,   626,   321,    -1,     9,    -1,    11,    -1,   633,
      -1,    15,    16,    17,    18,    19,    20,    -1,    73,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    83,     4,
       5,     6,     7,     8,     9,    39,    11,    12,    11,    -1,
      95,    16,    97,    -1,    99,    -1,    -1,    -1,    21,    24,
      -1,    -1,    25,    -1,    29,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,   123,    15,
      16,    17,    18,    19,    20,    -1,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      32,    33,    34,    35,    36,    37,    -1,   152,    -1,    -1,
      75,    -1,    -1,    -1,    -1,    -1,   161,   162,    -1,    -1,
     734,   735,   736,   737,    -1,   739,    15,    16,    17,    18,
      19,    20,   177,    -1,   179,   180,   181,    26,    27,    28,
      -1,    30,    31,    -1,    29,    -1,   191,     4,     5,     6,
       7,     8,     9,   767,    11,    12,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    49,   210,    -1,    24,    -1,    -1,
      -1,    -1,    29,    -1,   219,    -1,    61,    -1,    -1,    64,
      -1,    -1,   227,    -1,     4,     5,     6,     7,     8,     9,
      75,    -1,    -1,    -1,   808,    -1,    16,    -1,    -1,    -1,
      -1,    -1,   816,    -1,    24,   250,   820,    -1,   822,    29,
      -1,    -1,    -1,   827,    -1,    -1,    -1,    -1,    75,     9,
      -1,    -1,    -1,    -1,   838,    -1,   840,    -1,    -1,    19,
     275,   276,   277,   278,    -1,    -1,    -1,    -1,    -1,   853,
     285,    -1,    -1,   857,    -1,    -1,   860,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
      -1,     0,    -1,    -1,    -1,    -1,    -1,   312,    -1,    -1,
       9,    -1,   317,    -1,   319,    -1,   321,    -1,    -1,    18,
      19,    -1,    -1,    73,    -1,    -1,     4,     5,     6,     7,
       8,     9,    31,    11,    12,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    24,    97,    -1,    -1,
      -1,    29,     4,     5,     6,     7,     8,     9,   626,    11,
      12,    -1,    -1,    -1,    16,   633,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    73,   759,    -1,    29,   762,    -1,
      -1,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   779,    95,    75,    97,    -1,
      99,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      -1,    -1,    -1,    16,    15,    16,    17,    18,    19,    20,
     804,    24,   806,    75,   123,    -1,    29,    -1,    -1,    30,
      31,    -1,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
     834,    -1,    -1,   152,    15,    16,    17,    18,    19,    20,
      -1,    -1,   161,   162,    -1,    -1,   734,   735,   736,   737,
      -1,   739,    75,    34,    35,    36,    37,    -1,   177,    -1,
      -1,    -1,   181,    -1,   183,   184,    15,    16,    17,    18,
      19,    20,   191,    -1,    -1,    -1,    -1,    -1,    -1,   767,
     250,    30,    31,    -1,    -1,     4,     5,     6,     7,     8,
       9,   210,    11,    -1,    -1,    -1,    -1,    16,    -1,    -1,
     219,    -1,    -1,   368,    -1,    24,    -1,   372,   227,    10,
      29,   376,    -1,    -1,    15,    16,    17,    18,    19,    20,
     808,    -1,    -1,    -1,    -1,    26,    27,    28,   816,    30,
      31,   250,   820,    -1,   822,    -1,    -1,    -1,    -1,   827,
      -1,    -1,   312,    -1,    -1,    -1,   411,    -1,    -1,    -1,
     838,   321,   840,    -1,   419,    -1,    75,    15,    16,    17,
      18,    19,    20,    21,    -1,   853,    -1,    25,    -1,   857,
      -1,    -1,   860,    -1,    32,    33,    34,    35,    36,    37,
     445,    -1,   447,    -1,   449,    -1,   451,    -1,   453,    -1,
     455,    -1,    -1,   312,    -1,    -1,    -1,    -1,   317,   464,
     319,   626,   321,    -1,    -1,    -1,    -1,    -1,   633,    -1,
       0,     1,   477,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    -1,    -1,    -1,    16,    -1,     4,     5,
       6,     7,     8,     9,    24,    11,    -1,    -1,    10,    29,
      16,    -1,   507,    15,    16,    17,    18,    19,    24,    -1,
      -1,    -1,    -1,    29,    26,    27,    28,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,
      -1,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,   562,    -1,    75,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,   734,
     735,   736,   737,     3,   739,     0,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,   590,    11,    -1,    -1,    -1,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    25,    24,
      -1,    -1,   767,    -1,    29,    32,    33,    34,    35,    36,
      37,   616,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    -1,    -1,    61,    62,    63,    64,
      65,    66,    67,   808,    69,    70,    71,    72,    73,    74,
      75,   816,    -1,    -1,    -1,   820,    -1,   822,    -1,    -1,
      -1,    -1,   827,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   838,     1,   840,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    -1,    14,   853,    16,
      -1,    -1,   857,    -1,    -1,   860,    -1,    24,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,   626,    -1,    -1,    -1,
      30,    31,    -1,   633,    34,    35,    36,    37,    -1,    56,
      57,    58,    -1,    -1,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      -1,    -1,    14,    -1,    16,    -1,    -1,   626,    -1,    -1,
      -1,    -1,    24,    -1,   633,    -1,    -1,    29,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      -1,    13,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    56,    57,    58,    29,    -1,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    -1,   735,    -1,    -1,    -1,   739,
      -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,   767,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      54,    55,    -1,    -1,    -1,   734,   735,   736,   737,    -1,
     739,    -1,    -1,     8,    -1,    10,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   808,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   767,    -1,
     820,    -1,   822,    -1,     9,    -1,    11,   827,    -1,    -1,
      15,    16,    17,    18,    19,    20,    -1,    22,   838,    -1,
      25,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,   853,    39,    -1,    -1,    -1,    -1,   808,
      -1,    -1,    -1,    78,    79,    -1,    -1,   816,    83,    -1,
      -1,   820,    -1,   822,    89,    90,    -1,    -1,   827,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   838,
     105,   840,   107,    -1,   109,    -1,   111,    -1,    -1,    -1,
     115,    -1,   117,    -1,   853,    -1,    -1,    -1,   857,    -1,
      -1,   860,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,   169,   170,   171,   172,   173,   174,
     175,    -1,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,     8,
      -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,   243,   244,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,    -1,    -1,    -1,    -1,
     275,    -1,    -1,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
      -1,    -1,   307,   308,   309,   310,   311,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,   107,    -1,
     109,    -1,   111,    -1,    10,   340,   115,    -1,   117,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    25,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
     169,   170,   171,   172,   173,   174,   175,    -1,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,    -1,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,    -1,   243,   244,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    -1,    14,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    56,
      57,    58,    29,    -1,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    58,    -1,    -1,    61,    62,    63,    64,    65,    66,
      67,   340,    69,    70,    71,    72,    73,    74,    75,     9,
      10,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    25,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,     9,    39,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,     9,    39,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    -1,
      22,    23,    -1,    25,    26,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,     9,    39,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,     9,    39,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    39,     9,    -1,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    28,   741,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   759,    -1,    -1,   762,    -1,    -1,
      -1,     9,    -1,    11,    -1,    -1,   771,    15,    16,    17,
      18,    19,    20,    -1,   779,    -1,    -1,    -1,    26,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    39,    -1,    -1,    -1,    -1,     9,    -1,    11,   804,
      -1,   806,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,     9,    39,    11,    -1,   834,
      -1,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      34,    35,    36,    37,    10,    39,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    10,    -1,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    37,
      10,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    37,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    25,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,   741,    -1,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
     759,    -1,    -1,   762,    32,    33,    34,    35,    36,    37,
      -1,    -1,   771,    15,    16,    17,    18,    19,    20,    21,
     779,    -1,    -1,    -1,    26,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    15,    16,
      17,    18,    19,    20,    -1,   804,    -1,   806,    25,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,   834,    30,    31,    32,    33,
      34,    35,    36,    37,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      25,    15,    16,    17,    18,    19,    20,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,     0,     3,     4,     5,     6,     7,     8,     9,    11,
      16,    24,    29,    56,    57,    58,    61,    62,    63,    64,
      65,    66,    67,    69,    70,    71,    72,    73,    74,    75,
      78,    79,    80,    81,    84,    86,    87,    88,    89,    90,
      91,    94,    97,   100,   101,   102,   104,   105,   106,   108,
     109,   112,   113,   116,   117,   118,   119,   120,   122,   124,
       8,    75,   105,   106,   108,   109,   110,   112,   113,   116,
     117,   118,   119,     3,    12,    75,   104,   107,     9,    16,
      75,   116,   117,     9,   112,   116,   117,   118,   119,     9,
      16,   116,    75,    75,    85,     9,     9,     9,     3,    13,
      81,    82,    83,   104,    75,    11,    68,    11,    68,    11,
      68,    11,    68,    75,    75,    11,    13,    39,    68,   111,
     114,     0,     0,     1,    80,     3,     3,     3,     3,     3,
       3,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    54,    55,     9,    11,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    25,    26,    27,    28,    30,
      31,    32,    33,    34,    35,    36,    37,    39,   111,    11,
      15,    16,    17,    25,    32,    33,   111,    21,    25,    32,
      33,    21,    25,    32,    33,    15,    16,    17,    18,    19,
      20,    21,    25,    26,    27,    28,    30,    31,    32,    33,
      34,    35,    36,    37,    15,    16,    17,    18,    19,    20,
      21,    25,    32,    33,    34,    35,    36,    37,    11,    21,
      25,    32,    33,    34,    35,    36,    37,    21,    22,    23,
      25,    32,    33,    68,    68,     9,    75,    10,    11,   114,
      10,    10,    10,    38,    40,    10,    10,    10,    10,   107,
      40,     3,    12,   116,   117,    15,    16,    17,    18,    19,
      26,    27,    28,    30,    31,    15,    16,    17,    18,    19,
      20,   116,   117,   118,   119,    21,    32,    33,    21,    32,
      33,    34,    35,    36,    37,    21,    32,    33,    34,    35,
      36,    37,    21,    25,    32,    33,    34,    35,    36,    37,
      21,    22,    23,    32,    33,   116,   116,    15,    16,    17,
      18,    19,    42,    40,   104,    75,   104,    13,    14,    79,
      62,    42,    12,   105,   110,   116,   117,   118,   119,   123,
      12,   123,    12,   123,    12,   123,     3,    13,     9,    12,
      41,   110,   123,    14,    39,   115,   105,   116,    80,   102,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,    10,   103,   104,   110,   105,   108,   116,
     117,   105,   108,   116,   117,   105,   108,   116,   117,   105,
     116,   117,   105,   116,   117,   105,   117,   105,   112,   113,
     116,   117,   118,   119,   105,   119,   105,   119,   105,   118,
     105,   116,   105,   116,   105,   116,   105,   116,   105,   116,
     105,   108,   112,   113,   116,   117,   118,   119,   105,   108,
     112,   113,   116,   117,   118,   119,   105,   116,   117,   118,
     105,   116,   117,   118,   105,   116,   117,   118,   105,   116,
     117,   118,   105,   110,   105,   108,   105,   108,   105,   108,
     105,   108,   105,   108,   105,   108,   105,   112,   113,   116,
     117,   118,   119,   105,   108,   105,   112,   105,   112,   105,
     112,   113,   116,   117,   118,   119,   105,   108,   105,   113,
     105,   113,   105,   116,   117,   105,   116,   117,   105,   116,
     117,   105,   116,   117,   105,   116,   117,   116,   117,   105,
     112,   113,   116,   117,   118,   119,   105,   108,   105,   116,
     105,   116,   105,   116,   105,   116,   105,   116,   105,   116,
     117,   105,   116,   117,   105,   116,   117,   105,   116,   117,
     105,   116,   117,   105,   116,   117,   105,   116,   117,   105,
     116,   117,   105,   116,   117,   105,   116,   117,   105,   116,
     117,   105,   116,   117,   105,   112,   113,   116,   117,   118,
     119,   105,   108,   105,   116,   117,   105,   116,   117,   105,
     116,   117,   105,   116,   117,   105,   116,   117,   105,   116,
     117,   110,   105,   112,   113,   116,   117,   118,   119,   105,
     108,   118,   105,   118,   105,   118,   105,   118,   105,   118,
     105,   118,   105,   118,   105,   112,   113,   116,   117,   118,
     119,   105,   119,   105,   119,   105,   108,   105,   119,   105,
     119,    10,    75,   121,   124,     9,    42,   110,    10,   110,
     110,     3,    12,     3,   107,    12,   116,   117,   116,   117,
     116,   117,   116,   117,   116,   117,   116,   116,   116,   116,
     116,   116,   117,   116,   117,   116,   117,   116,   117,   116,
     117,   116,   117,   112,   116,   117,   118,   119,     9,   112,
     112,   112,   116,   117,   118,   119,   116,   117,   116,   117,
     116,   117,   116,   117,   116,   117,   116,   117,   112,   116,
     117,   118,   119,   116,   117,   116,   117,   116,   117,   116,
     117,   116,   117,   116,   117,   112,   116,   117,   118,   119,
     118,   119,   118,   118,   118,   118,   118,   118,   112,   116,
     117,   118,   119,   119,   119,   119,   119,   116,   116,   116,
     116,   116,   104,    75,    10,    41,    10,    79,    14,     9,
     104,    40,    12,    12,    12,    12,    13,     3,    14,    56,
      95,    96,   100,   124,    10,    98,    99,   124,    12,    41,
     110,    12,    41,    12,    75,    14,    10,    40,    12,    12,
      12,    11,    10,    40,    10,    98,   104,   114,    10,    38,
      12,   107,     8,    83,   104,    83,    14,     3,   104,   123,
      95,    95,    75,    14,     3,    75,    82,    10,    40,    40,
      75,    12,   110,    12,    41,    12,    41,   110,    42,   103,
     121,    82,    10,   110,    59,    92,    10,     3,    10,    14,
      42,    95,    42,    82,    98,    99,   124,    42,    12,    12,
     110,    12,   110,    12,    41,   104,    82,    10,     9,    59,
      60,    93,    83,   104,   104,    75,   104,    12,    12,    12,
     110,    40,   104,     9,    83,    12,   115,    10,   104,    83,
      10,    83
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    77,    78,    78,    79,    79,    79,    80,    80,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    82,    82,    82,    82,    82,    83,    83,    84,    85,
      85,    86,    86,    86,    87,    87,    88,    89,    90,    91,
      92,    92,    92,    93,    93,    94,    94,    94,    95,    95,
      95,    95,    96,    96,    96,    97,    97,    97,    97,    98,
      98,    98,    99,    99,   100,   101,   101,   101,   101,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   103,   103,   104,   104,   104,   104,   104,
     104,   104,   104,   105,   105,   105,   105,   105,   105,   105,
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
     105,   105,   105,   105,   105,   105,   105,   106,   106,   106,
     106,   106,   107,   107,   107,   108,   108,   108,   108,   109,
     109,   110,   110,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   112,   112,   113,   113,   114,
     114,   115,   115,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   120,   120,   121,   121,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   123,
     123,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     1,     2,     1,     2,     3,     1,     1,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     3,     4,     4,     5,     1,     1,     2,     1,
       3,     1,     1,     1,     1,     2,     7,     5,     6,     7,
       5,     6,     0,     2,     0,     4,     5,     6,     1,     2,
       2,     3,     1,     4,     4,     5,     6,     5,     6,     2,
       1,     3,     4,     3,     2,     4,     4,     4,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     3,     4,     4,     4,
       4,     4,     2,     2,     2,     3,     3,     3,     3,     3,
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
       3,     3,     3,     3,     3,     3,     3,     2,     3,     4,
       4,     5,     1,     3,     4,     1,     1,     3,     3,     5,
       7,     1,     1,     3,     4,     4,     5,     4,     5,     5,
       5,     6,     6,     6,     7,     1,     3,     2,     4,     2,
       3,     4,     6,     1,     2,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     3,     1,     3,     4,
       3,     4,     3,     4,     3,     4,     3,     4,     3,     1,
       3,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1
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
  "while", "dowhile", "if", "elif", "else", "struct", "decllist",
  "declistval", "function", "funargs", "funargdef", "vardecl", "vardef",
  "set", "callarglist", "expr", "expr_var", "matrix", "matvals",
  "expr_mat", "range", "int_val", "slice", "expr_none", "expr_struct",
  "struct_val", "struct_list", "expr_int", "expr_float", "expr_str",
  "expr_bool", "funtype", "typelist", "mattype", "matsize", "type", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   192,   192,   193,   195,   196,   197,   201,   202,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   219,   220,   221,   222,   223,   226,   227,   231,   233,
     234,   238,   239,   240,   242,   243,   247,   251,   254,   258,
     260,   261,   262,   264,   265,   269,   270,   271,   273,   274,
     275,   276,   278,   279,   280,   284,   285,   286,   287,   289,
     290,   291,   293,   294,   298,   302,   303,   304,   305,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   326,   327,   331,   332,   333,   334,   335,
     336,   337,   338,   341,   342,   343,   345,   346,   348,   349,
     350,   351,   353,   354,   355,   357,   358,   360,   361,   362,
     364,   365,   366,   367,   368,   369,   370,   371,   373,   374,
     375,   376,   377,   379,   380,   381,   382,   383,   385,   386,
     387,   388,   389,   390,   391,   392,   394,   395,   396,   397,
     398,   399,   400,   401,   403,   404,   405,   407,   408,   409,
     411,   412,   413,   414,   415,   416,   417,   419,   420,   421,
     422,   423,   424,   425,   427,   428,   429,   430,   431,   432,
     433,   435,   436,   437,   438,   439,   440,   441,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   479,   480,   481,   483,   484,   485,   487,   488,
     489,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   505,   506,   508,   509,   510,
     512,   513,   514,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   543,   544,   545,
     546,   547,   549,   550,   551,   555,   556,   557,   558,   560,
     561,   563,   564,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   581,   582,   586,   587,   589,
     590,   592,   593,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   629,   630,   631,   632,   633,   634,   638,   639,
     640,   641,   642,   643,   644,   645,   646,   647,   648,   649,
     650,   651,   652,   653,   654,   655,   656,   657,   658,   659,
     660,   661,   662,   663,   664,   668,   669,   670,   671,   672,
     674,   675,   676,   677,   678,   679,   680,   682,   683,   684,
     685,   686,   687,   688,   690,   691,   692,   693,   694,   696,
     697,   698,   699,   700,   702,   703,   704,   705,   706,   708,
     709,   710,   711,   712,   714,   718,   719,   721,   722,   726,
     727,   728,   729,   730,   731,   732,   733,   734,   735,   737,
     738,   742,   743,   744,   745,   746,   747,   748,   749,   750,
     751,   752,   753,   754,   755
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
#line 3738 "frontend/parser.cpp"

#line 758 "frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    auto msg = std::to_string(scanner->loc->begin.line) + ":" + std::to_string(scanner->loc->begin.column) + ": " + err_message;
    ptc::log::error(msg);
}
