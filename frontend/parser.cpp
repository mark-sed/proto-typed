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
#line 42 "frontend/parser.yy"


    #include <cmath>
    #include <sstream>
    #include "scanner.hpp"
    #include "logging.hpp"
    #include "ir.hpp"
    #include "expression.hpp"

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
  case 304: // expr_int: "int"
#line 594 "frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 817 "frontend/parser.cpp"
    break;

  case 305: // expr_int: "-" expr_int
#line 595 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 823 "frontend/parser.cpp"
    break;

  case 306: // expr_int: "(" expr_int ")"
#line 596 "frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 829 "frontend/parser.cpp"
    break;

  case 307: // expr_int: "~" expr_int
#line 597 "frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 835 "frontend/parser.cpp"
    break;

  case 308: // expr_int: expr_int "*" expr_int
#line 598 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 841 "frontend/parser.cpp"
    break;

  case 309: // expr_int: expr_int "/" expr_int
#line 599 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 847 "frontend/parser.cpp"
    break;

  case 310: // expr_int: expr_int "%" expr_int
#line 600 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 853 "frontend/parser.cpp"
    break;

  case 311: // expr_int: expr_int "-" expr_int
#line 601 "frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 859 "frontend/parser.cpp"
    break;

  case 312: // expr_int: expr_int "+" expr_int
#line 602 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 865 "frontend/parser.cpp"
    break;

  case 313: // expr_int: expr_int "<<" expr_int
#line 603 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 871 "frontend/parser.cpp"
    break;

  case 314: // expr_int: expr_int ">>" expr_int
#line 604 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 877 "frontend/parser.cpp"
    break;

  case 315: // expr_int: expr_int "&" expr_int
#line 605 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 883 "frontend/parser.cpp"
    break;

  case 316: // expr_int: expr_int "^" expr_int
#line 606 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 889 "frontend/parser.cpp"
    break;

  case 317: // expr_int: expr_int "|" expr_int
#line 607 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 895 "frontend/parser.cpp"
    break;

  case 318: // expr_float: "float"
#line 611 "frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 901 "frontend/parser.cpp"
    break;

  case 319: // expr_float: "-" expr_float
#line 612 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 907 "frontend/parser.cpp"
    break;

  case 320: // expr_float: "(" expr_float ")"
#line 613 "frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 913 "frontend/parser.cpp"
    break;

  case 321: // expr_float: expr_float "**" expr_float
#line 614 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 919 "frontend/parser.cpp"
    break;

  case 322: // expr_float: expr_float "**" expr_int
#line 615 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 925 "frontend/parser.cpp"
    break;

  case 323: // expr_float: expr_int "**" expr_float
#line 616 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 931 "frontend/parser.cpp"
    break;

  case 324: // expr_float: expr_float "*" expr_float
#line 617 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 937 "frontend/parser.cpp"
    break;

  case 325: // expr_float: expr_float "*" expr_int
#line 618 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 943 "frontend/parser.cpp"
    break;

  case 326: // expr_float: expr_int "*" expr_float
#line 619 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 949 "frontend/parser.cpp"
    break;

  case 327: // expr_float: expr_float "/" expr_float
#line 620 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 955 "frontend/parser.cpp"
    break;

  case 328: // expr_float: expr_float "/" expr_int
#line 621 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 961 "frontend/parser.cpp"
    break;

  case 329: // expr_float: expr_int "/" expr_float
#line 622 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 967 "frontend/parser.cpp"
    break;

  case 330: // expr_float: expr_float "%" expr_float
#line 623 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 973 "frontend/parser.cpp"
    break;

  case 331: // expr_float: expr_float "%" expr_int
#line 624 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 979 "frontend/parser.cpp"
    break;

  case 332: // expr_float: expr_int "%" expr_float
#line 625 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 985 "frontend/parser.cpp"
    break;

  case 333: // expr_float: expr_float "-" expr_float
#line 626 "frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 991 "frontend/parser.cpp"
    break;

  case 334: // expr_float: expr_float "-" expr_int
#line 627 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 997 "frontend/parser.cpp"
    break;

  case 335: // expr_float: expr_int "-" expr_float
#line 628 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 1003 "frontend/parser.cpp"
    break;

  case 336: // expr_float: expr_float "+" expr_float
#line 629 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 1009 "frontend/parser.cpp"
    break;

  case 337: // expr_float: expr_float "+" expr_int
#line 630 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 1015 "frontend/parser.cpp"
    break;

  case 338: // expr_float: expr_int "+" expr_float
#line 631 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 1021 "frontend/parser.cpp"
    break;

  case 339: // expr_str: "string"
#line 635 "frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1027 "frontend/parser.cpp"
    break;

  case 340: // expr_str: "(" expr_str ")"
#line 636 "frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 1033 "frontend/parser.cpp"
    break;

  case 341: // expr_str: expr_str "++" expr_str
#line 637 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 1039 "frontend/parser.cpp"
    break;

  case 342: // expr_str: expr_str "++" expr_int
#line 638 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 1045 "frontend/parser.cpp"
    break;

  case 343: // expr_str: expr_str "++" expr_float
#line 639 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 1051 "frontend/parser.cpp"
    break;

  case 344: // expr_str: expr_str "++" expr_bool
#line 640 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1057 "frontend/parser.cpp"
    break;

  case 345: // expr_str: expr_str "++" expr_none
#line 641 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 1063 "frontend/parser.cpp"
    break;

  case 346: // expr_str: expr_int "++" expr_str
#line 642 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 1069 "frontend/parser.cpp"
    break;

  case 347: // expr_str: expr_int "++" expr_int
#line 643 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 1075 "frontend/parser.cpp"
    break;

  case 348: // expr_str: expr_int "++" expr_float
#line 644 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 1081 "frontend/parser.cpp"
    break;

  case 349: // expr_str: expr_int "++" expr_bool
#line 645 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1087 "frontend/parser.cpp"
    break;

  case 350: // expr_str: expr_int "++" expr_none
#line 646 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 1093 "frontend/parser.cpp"
    break;

  case 351: // expr_str: expr_float "++" expr_str
#line 647 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 1099 "frontend/parser.cpp"
    break;

  case 352: // expr_str: expr_float "++" expr_int
#line 648 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 1105 "frontend/parser.cpp"
    break;

  case 353: // expr_str: expr_float "++" expr_float
#line 649 "frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 1111 "frontend/parser.cpp"
    break;

  case 354: // expr_str: expr_float "++" expr_bool
#line 650 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1117 "frontend/parser.cpp"
    break;

  case 355: // expr_str: expr_float "++" expr_none
#line 651 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 1123 "frontend/parser.cpp"
    break;

  case 356: // expr_str: expr_bool "++" expr_str
#line 652 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 1129 "frontend/parser.cpp"
    break;

  case 357: // expr_str: expr_bool "++" expr_int
#line 653 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 1135 "frontend/parser.cpp"
    break;

  case 358: // expr_str: expr_bool "++" expr_float
#line 654 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 1141 "frontend/parser.cpp"
    break;

  case 359: // expr_str: expr_bool "++" expr_bool
#line 655 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1147 "frontend/parser.cpp"
    break;

  case 360: // expr_str: expr_bool "++" expr_none
#line 656 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 1153 "frontend/parser.cpp"
    break;

  case 361: // expr_str: expr_none "++" expr_str
#line 657 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 1159 "frontend/parser.cpp"
    break;

  case 362: // expr_str: expr_none "++" expr_int
#line 658 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 1165 "frontend/parser.cpp"
    break;

  case 363: // expr_str: expr_none "++" expr_float
#line 659 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 1171 "frontend/parser.cpp"
    break;

  case 364: // expr_str: expr_none "++" expr_bool
#line 660 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1177 "frontend/parser.cpp"
    break;

  case 365: // expr_str: expr_none "++" expr_none
#line 661 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 1183 "frontend/parser.cpp"
    break;

  case 366: // expr_bool: "bool"
#line 665 "frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 1189 "frontend/parser.cpp"
    break;

  case 367: // expr_bool: "(" expr_bool ")"
#line 666 "frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 1195 "frontend/parser.cpp"
    break;

  case 368: // expr_bool: "not" expr_bool
#line 667 "frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 1201 "frontend/parser.cpp"
    break;

  case 369: // expr_bool: expr_bool "or" expr_bool
#line 668 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 1207 "frontend/parser.cpp"
    break;

  case 370: // expr_bool: expr_bool "and" expr_bool
#line 669 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 1213 "frontend/parser.cpp"
    break;

  case 371: // expr_bool: expr_bool "==" expr_bool
#line 671 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 1219 "frontend/parser.cpp"
    break;

  case 372: // expr_bool: expr_int "==" expr_int
#line 672 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 1225 "frontend/parser.cpp"
    break;

  case 373: // expr_bool: expr_int "==" expr_float
#line 673 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 1231 "frontend/parser.cpp"
    break;

  case 374: // expr_bool: expr_float "==" expr_float
#line 674 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 1237 "frontend/parser.cpp"
    break;

  case 375: // expr_bool: expr_float "==" expr_int
#line 675 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 1243 "frontend/parser.cpp"
    break;

  case 376: // expr_bool: expr_str "==" expr_str
#line 676 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 1249 "frontend/parser.cpp"
    break;

  case 377: // expr_bool: expr_none "==" expr_none
#line 677 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 1255 "frontend/parser.cpp"
    break;

  case 378: // expr_bool: expr_bool "!=" expr_bool
#line 679 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 1261 "frontend/parser.cpp"
    break;

  case 379: // expr_bool: expr_int "!=" expr_int
#line 680 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 1267 "frontend/parser.cpp"
    break;

  case 380: // expr_bool: expr_int "!=" expr_float
#line 681 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 1273 "frontend/parser.cpp"
    break;

  case 381: // expr_bool: expr_float "!=" expr_float
#line 682 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 1279 "frontend/parser.cpp"
    break;

  case 382: // expr_bool: expr_float "!=" expr_int
#line 683 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 1285 "frontend/parser.cpp"
    break;

  case 383: // expr_bool: expr_str "!=" expr_str
#line 684 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 1291 "frontend/parser.cpp"
    break;

  case 384: // expr_bool: expr_none "!=" expr_none
#line 685 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 1297 "frontend/parser.cpp"
    break;

  case 385: // expr_bool: expr_int ">" expr_int
#line 687 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 1303 "frontend/parser.cpp"
    break;

  case 386: // expr_bool: expr_int ">" expr_float
#line 688 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 1309 "frontend/parser.cpp"
    break;

  case 387: // expr_bool: expr_float ">" expr_float
#line 689 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 1315 "frontend/parser.cpp"
    break;

  case 388: // expr_bool: expr_float ">" expr_int
#line 690 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 1321 "frontend/parser.cpp"
    break;

  case 389: // expr_bool: expr_str ">" expr_str
#line 691 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 1327 "frontend/parser.cpp"
    break;

  case 390: // expr_bool: expr_int "<" expr_int
#line 693 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 1333 "frontend/parser.cpp"
    break;

  case 391: // expr_bool: expr_int "<" expr_float
#line 694 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 1339 "frontend/parser.cpp"
    break;

  case 392: // expr_bool: expr_float "<" expr_float
#line 695 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 1345 "frontend/parser.cpp"
    break;

  case 393: // expr_bool: expr_float "<" expr_int
#line 696 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 1351 "frontend/parser.cpp"
    break;

  case 394: // expr_bool: expr_str "<" expr_str
#line 697 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 1357 "frontend/parser.cpp"
    break;

  case 395: // expr_bool: expr_int ">=" expr_int
#line 699 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 1363 "frontend/parser.cpp"
    break;

  case 396: // expr_bool: expr_int ">=" expr_float
#line 700 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 1369 "frontend/parser.cpp"
    break;

  case 397: // expr_bool: expr_float ">=" expr_float
#line 701 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 1375 "frontend/parser.cpp"
    break;

  case 398: // expr_bool: expr_float ">=" expr_int
#line 702 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 1381 "frontend/parser.cpp"
    break;

  case 399: // expr_bool: expr_str ">=" expr_str
#line 703 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 1387 "frontend/parser.cpp"
    break;

  case 400: // expr_bool: expr_int "<=" expr_int
#line 705 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 1393 "frontend/parser.cpp"
    break;

  case 401: // expr_bool: expr_int "<=" expr_float
#line 706 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 1399 "frontend/parser.cpp"
    break;

  case 402: // expr_bool: expr_float "<=" expr_float
#line 707 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 1405 "frontend/parser.cpp"
    break;

  case 403: // expr_bool: expr_float "<=" expr_int
#line 708 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 1411 "frontend/parser.cpp"
    break;

  case 404: // expr_bool: expr_str "<=" expr_str
#line 709 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 1417 "frontend/parser.cpp"
    break;

  case 405: // expr_bool: expr_str "in" expr_str
#line 711 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[0].value.as < std::string > ().find(yystack_[2].value.as < std::string > ()) != std::string::npos; }
#line 1423 "frontend/parser.cpp"
    break;

  case 422: // type: "\"int\"" "?"
#line 739 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 1429 "frontend/parser.cpp"
    break;

  case 423: // type: "\"float\"" "?"
#line 740 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 1435 "frontend/parser.cpp"
    break;

  case 424: // type: "\"string\"" "?"
#line 741 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 1441 "frontend/parser.cpp"
    break;

  case 425: // type: "\"bool\"" "?"
#line 742 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 1447 "frontend/parser.cpp"
    break;

  case 426: // type: "identifier" "?"
#line 743 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 1453 "frontend/parser.cpp"
    break;

  case 427: // type: funtype "?"
#line 744 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 1459 "frontend/parser.cpp"
    break;

  case 428: // type: mattype "?"
#line 745 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 1465 "frontend/parser.cpp"
    break;

  case 429: // type: "\"int\""
#line 746 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("int"); }
#line 1471 "frontend/parser.cpp"
    break;

  case 430: // type: "\"float\""
#line 747 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("float"); }
#line 1477 "frontend/parser.cpp"
    break;

  case 431: // type: "\"string\""
#line 748 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("string"); }
#line 1483 "frontend/parser.cpp"
    break;

  case 432: // type: "\"bool\""
#line 749 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("bool"); }
#line 1489 "frontend/parser.cpp"
    break;

  case 433: // type: "identifier"
#line 750 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[0].value.as < std::string > ()); }
#line 1495 "frontend/parser.cpp"
    break;

  case 434: // type: funtype
#line 751 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 1501 "frontend/parser.cpp"
    break;

  case 435: // type: mattype
#line 752 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 1507 "frontend/parser.cpp"
    break;


#line 1511 "frontend/parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -726;

  const short  Parser ::yytable_ninf_ = -434;

  const short
   Parser ::yypact_[] =
  {
    1760,  -726,  -726,  -726,  -726,  -726,  -726,  -726,  1677,    29,
      38,  1086,   408,   -46,   -26,   101,   119,   186,  2556,  1729,
    -726,  -726,   -18,    28,    44,    48,    57,   106,   122,    33,
     176,  1605,  -726,  -726,   209,   251,  -726,  -726,  -726,  -726,
    -726,  -726,  -726,   261,   271,   304,  1804,  2173,  -726,   635,
    -726,   402,   452,  2924,  2001,  1425,   341,   175,   253,     5,
     302,   183,  2144,   309,   635,   313,   -10,   402,   452,  2860,
    2628,  1195,  1138,  1729,  -726,   183,   294,   167,   389,   389,
    -726,  -726,  -726,  1125,   140,  2947,  3068,  1447,  -726,   408,
     408,  -726,   295,  -726,   298,  1729,   267,  1729,   331,  2675,
    -726,  -726,   284,  -726,   305,   574,  -726,   600,  -726,   614,
    -726,   675,  -726,    63,   346,   324,   141,  1729,  -726,  -726,
    -726,  -726,  -726,  2705,  -726,  -726,  -726,  -726,  -726,  -726,
    -726,  1729,  1729,  1729,  1729,  1729,  1729,  1729,  1729,  1729,
    1729,  1729,  1729,  1729,  1729,   985,   886,  1729,  1729,  1729,
    1729,  1729,  1729,  1729,  1729,  1729,  1729,  1729,  1729,  1729,
    1729,  1729,  1729,  1729,  1729,  1729,  1729,  1729,  1729,  -726,
     886,  1729,  1729,  1729,  1729,  1729,  1729,  -726,  1729,  1729,
    1729,  1729,  1729,  1729,  1729,  1729,  1729,  1729,  1729,  1729,
    1729,   389,  1729,  1729,  1729,  1729,  1729,  1729,  1729,  1729,
    1729,  1729,  1729,  1729,  1729,  1729,  1729,  1729,  1729,  1729,
    1729,  1729,  1729,  1729,  1729,  1729,  1729,  1729,  1729,  1729,
    1729,  1729,  1729,  1729,  1729,  1729,  1729,  1729,  1729,  1729,
    1729,  1729,  1729,  1729,  -726,  -726,   239,    18,  -726,   886,
     360,  -726,  -726,  -726,  1729,  1729,  -726,  -726,  -726,  -726,
     238,    82,   378,  -726,  1503,   958,   389,   389,   389,   389,
     389,   408,   408,   408,   408,   408,   389,   389,   389,   389,
     389,   389,  2899,   815,  1366,   496,  1086,   151,   151,  1086,
     389,   389,   389,   389,   389,   389,  1086,   389,   389,   389,
     389,   389,   389,  1086,  1086,  1086,  1086,  1086,  1086,  1086,
    1086,  1086,  1086,  1086,  1086,  1086,  2252,  -726,   408,   408,
     408,   408,   408,  1729,   281,   362,   350,   385,  2705,  -726,
    2453,   387,  1729,  -726,  2173,   361,  2924,  2001,  1425,   341,
     390,  -726,   392,  -726,   413,  -726,   418,   407,    49,   344,
    -726,   434,    62,   432,  -726,   381,   445,    66,  2924,  -726,
    -726,  3115,  -726,  -726,  -726,  -726,  -726,  -726,  -726,  -726,
    -726,  -726,  -726,  -726,  -726,  -726,   450,   421,    53,   754,
     166,   228,   582,   754,   166,   228,   582,   222,   463,   456,
     458,   222,   456,   458,   222,   456,   458,   222,   458,  2572,
     240,   396,  2970,  3091,   559,   336,  2772,   482,  1873,   480,
    2801,   660,  1763,  3062,  2830,  3016,  1961,  3039,   472,  1236,
     472,  1236,   696,   558,  -726,  -726,  1904,   917,   315,  -726,
     696,   558,  -726,  -726,  1904,   917,   315,  -726,  1277,   851,
    1390,   468,  1277,   851,  1390,   468,  1277,   851,  1390,   468,
    1277,   851,  1390,   468,    66,   105,   754,   166,   754,   166,
     222,   463,  2801,   780,   696,   558,   696,   558,  2572,   240,
     396,  2970,  3091,   559,   336,  2801,   780,   696,  -726,   696,
    -726,  2572,   240,   396,  2970,  3091,   559,   336,  2801,   780,
     696,  -726,   696,  -726,   754,   228,   582,   754,   228,   582,
     222,   456,   458,   222,   456,   458,   222,   456,   458,  3125,
     462,  2572,   240,   396,  2970,  3091,   559,   336,  2801,   780,
    1763,  3062,  2830,  3016,  1961,  3039,   472,  1236,   472,  1236,
     696,  1904,   917,   696,  1904,   917,  1277,   851,  1390,  1277,
     851,  1390,  1277,   851,  1390,  1277,   851,  1390,   754,   228,
     582,   754,   228,   582,   222,   456,   458,   222,   456,   458,
     222,   456,   458,   222,   456,   458,  2572,   240,   396,  2970,
    3091,   559,   336,  2801,   780,   696,  1904,   917,   696,  1904,
     917,  1277,   851,  1390,  1277,   851,  1390,  1277,   851,  1390,
    1277,   851,  1390,   481,  2572,   240,   396,  2970,  3091,   559,
     336,  2801,   780,   660,   696,   315,   696,   315,  1277,   468,
    1277,   468,  1277,   468,  1277,   468,  2572,   240,   396,  2970,
    3091,   559,   336,  2772,   482,  1873,   480,  2801,   780,   696,
    -726,   696,  -726,  -726,    58,   484,    16,   382,  1032,   115,
    -726,   500,   488,   510,  -726,  1729,  -726,  -726,   797,   899,
     797,   899,   456,   462,   456,   462,   456,   462,   208,  1349,
    1412,   868,   868,   797,   899,   797,   899,   456,   462,   456,
     462,   456,   462,   456,   462,   245,  2993,  3102,   723,   609,
     519,  -726,  -726,   245,  2993,  3102,   723,   609,   987,  1575,
     987,  1575,   987,  1575,   987,  1575,   987,  1575,   987,  1575,
     245,  2993,  3102,   723,   609,   987,  1575,   987,  1575,   987,
    1575,   987,  1575,   987,  1575,   987,  1575,   245,  2993,  3102,
     723,   609,  1565,   890,   869,   869,  -726,  -726,  -726,  -726,
     245,  2993,  3102,   723,   609,   283,   197,  -726,  -726,   430,
     430,  -726,  -726,  -726,  -726,  -726,  2556,  1729,  2556,  2483,
     528,  1729,  -726,  1729,  -726,  -726,  -726,  -726,   165,   165,
    -726,   457,   520,   533,  -726,     6,   172,    11,   512,     7,
    -726,  1317,   117,  -726,   492,  -726,   508,  -726,  -726,  1729,
    -726,  -726,  -726,  1345,  -726,   631,   172,    60,  -726,  -726,
    -726,  1729,  -726,  -726,   302,   494,   544,  -726,   553,  -726,
     548,  -726,   545,  -726,   521,  -726,   165,   523,  -726,   172,
     631,   631,   546,  -726,   575,  -726,  1486,  -726,  1547,   157,
    1729,  -726,  -726,  -726,   172,   579,   588,     2,  2556,  -726,
    -726,  -726,  1729,  -726,  1729,  -726,   570,   512,    17,  1729,
    -726,  -726,   601,  -726,   602,  -726,  1635,   577,  -726,  -726,
    1729,   606,  2556,  -726,  -726,  -726,  -726,   546,  -726,  -726,
    -726,  -726,   615,   594,   624,  1729,  -726,  -726,  -726,  2556,
     626,  -726,  2556,  -726
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     7,   304,   318,   339,   366,   296,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      31,    32,     0,   429,   430,   431,   432,     0,     0,    94,
       0,     0,     4,     8,     0,     0,    33,    13,    15,    16,
      14,    17,    18,     0,     0,     0,     0,    87,   276,    86,
     277,    88,    89,    90,    91,    92,    93,   434,   435,     0,
     296,    94,   283,   276,     0,   277,     0,     0,     0,   282,
       0,     0,     0,     0,   268,    94,   273,     0,     0,     0,
      95,   305,   319,     0,     0,     0,     0,     0,   368,     0,
       0,   307,     0,    29,    28,     0,     0,     0,     0,     0,
      26,    27,     0,    35,     0,     0,   422,     0,   423,     0,
     424,     0,   425,     0,     0,     0,     0,     0,   426,   104,
     298,     1,     3,     0,     5,    12,    19,    10,    11,     9,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   105,
       0,     0,     0,     0,     0,     0,     0,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   427,   428,     0,    64,   297,     0,
     298,    96,   278,   279,     0,     0,   306,   320,   340,   367,
       0,     0,     0,   269,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   305,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,   413,   283,   420,   282,     0,     0,     0,
       0,   415,     0,   417,     0,   419,     0,     0,     0,     0,
     411,     0,     0,     0,   300,     0,     0,   106,     0,     6,
      83,    82,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    97,     0,    84,     0,   136,
     134,   131,   132,   144,   142,   139,   140,   118,   117,   113,
     114,   123,   121,   122,   128,   126,   127,   110,   109,   267,
     265,   266,   261,   262,   263,   264,   240,   239,   243,   242,
     237,   236,   215,   214,   221,   220,   218,   217,   147,   146,
     150,   149,   195,   193,   190,   191,   186,   187,   188,   189,
     212,   210,   207,   208,   203,   204,   205,   206,   157,   154,
     155,   156,   171,   168,   169,   170,   164,   161,   162,   163,
     178,   175,   176,   177,   107,     0,   135,   133,   143,   141,
     116,   115,   235,   228,   194,   192,   211,   209,   259,   365,
     248,   362,   363,   361,   364,   233,   226,   183,   377,   200,
     384,   260,   253,   254,   249,   250,   251,   252,   234,   227,
     185,   184,   202,   201,   129,   312,   338,   137,   311,   335,
     111,   308,   326,   119,   309,   329,   124,   310,   332,     0,
     323,   255,   350,   244,   347,   348,   346,   349,   229,   222,
     213,   315,   219,   317,   216,   316,   145,   313,   148,   314,
     179,   372,   373,   196,   379,   380,   151,   385,   386,   165,
     390,   391,   158,   395,   396,   172,   400,   401,   130,   337,
     336,   138,   334,   333,   112,   325,   324,   120,   328,   327,
     125,   331,   330,   108,   322,   321,   256,   355,   245,   352,
     353,   351,   354,   230,   223,   180,   375,   374,   197,   382,
     381,   152,   388,   387,   166,   393,   392,   159,   398,   397,
     173,   403,   402,     0,   257,   345,   246,   342,   343,   341,
     344,   231,   224,   405,   181,   376,   198,   383,   153,   389,
     167,   394,   160,   399,   174,   404,   258,   360,   247,   357,
     358,   356,   359,   238,   370,   241,   369,   232,   225,   182,
     371,   199,   378,   407,   433,     0,   408,     0,     0,     0,
     299,     0,     0,     0,   270,     0,   274,   271,   312,   338,
     311,   335,   308,   326,   309,   329,   310,   332,   315,   317,
     316,   313,   314,   337,   336,   334,   333,   325,   324,   328,
     327,   331,   330,   322,   321,   365,   362,   363,   361,   364,
       0,   377,   384,   350,   347,   348,   346,   349,   372,   373,
     379,   380,   385,   386,   390,   391,   395,   396,   400,   401,
     355,   352,   353,   351,   354,   375,   374,   382,   381,   388,
     387,   393,   392,   398,   397,   403,   402,   345,   342,   343,
     341,   344,   405,     0,   376,   383,   389,   394,   399,   404,
     360,   357,   358,   356,   359,   370,   369,   371,   378,   312,
     311,   308,   309,   310,    68,    30,     0,     0,     0,     0,
      22,     0,    67,     0,   412,   414,   416,   418,     0,    48,
      45,     0,     0,     0,    52,     0,     0,     0,    60,     0,
     284,     0,     0,   101,     0,   410,     0,   301,    98,     0,
     102,   100,    99,     0,   406,     0,     0,     0,    66,    65,
     280,     0,   272,   275,     0,    42,     0,    37,    23,    24,
       0,   421,     0,    49,     0,    46,    50,    64,    57,     0,
       0,     0,    59,   288,     0,   286,     0,   285,     0,     0,
       0,    85,   409,    55,     0,     0,     0,    44,     0,    25,
      38,    47,     0,    51,     0,    58,    61,    63,     0,     0,
     291,   290,     0,   289,     0,   287,     0,   302,    56,   281,
       0,     0,     0,    39,    36,    54,    53,     0,    62,   294,
     293,   292,     0,     0,     0,     0,    43,   295,   303,     0,
       0,    40,     0,    41
  };

  const short
   Parser ::yypgoto_[] =
  {
    -726,  -726,   -86,   -14,   -16,  -692,  -688,  -726,  -726,  -726,
    -726,  -726,  -726,  -726,  -726,  -726,  -726,  -726,  -725,  -726,
    -726,  -607,  -164,  -316,  -726,   509,  -125,  1104,  1894,   639,
     -67,  1127,   640,   316,   296,   889,  1404,   -57,  -198,  2140,
       0,   244,   645,  -726,  -117,  -726,  -104,  -224
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    30,    31,    32,    33,   101,   102,    34,    94,    35,
      36,    37,    38,    39,    40,   817,   843,    41,   752,   753,
      42,   757,   758,    43,    44,    45,   366,    46,    47,    48,
      77,    64,    50,   325,   169,    67,    68,   120,   346,    53,
     327,   328,   329,    57,   625,    58,   343,    59
  };

  const short
   Parser ::yytable_[] =
  {
      54,   330,   100,   332,   240,   334,   250,   336,    70,    54,
      82,    86,   626,   320,   236,   236,   236,   124,    54,    54,
     777,   799,   754,   792,   793,   236,   236,   627,   244,    92,
     245,    54,    73,     3,     4,     5,     6,     7,     8,   105,
       9,    74,     3,     4,   115,    10,   116,    78,   785,    93,
     787,   800,   749,    11,    79,   107,   775,   104,    12,   109,
     628,   841,   842,   750,   798,   770,   337,    12,   111,   773,
     814,   823,   117,    54,   763,   145,   338,   146,   255,    82,
     237,   797,   802,   273,   813,   635,     3,     4,     5,     6,
       7,     8,   847,     9,   764,    54,   106,    54,    10,    54,
     800,   118,   743,   764,    75,   751,    11,   825,  -433,   349,
      95,    12,   108,    80,   755,   759,   110,   771,    23,    24,
      25,    26,   838,    54,   624,   112,   118,   763,    96,   805,
     844,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,   764,   372,   376,   380,
     383,   386,   388,   393,   856,   344,   764,    75,   806,     7,
     670,   276,   417,   425,   430,   434,   438,   442,   749,   835,
     252,   861,   277,   278,   863,    98,   121,   170,   462,   253,
     345,   113,   475,   173,   636,    99,   486,   489,   492,   495,
     498,   500,   505,   826,   239,    97,   116,   114,   836,   522,
     525,   528,   531,   534,   537,   540,   543,   546,   549,   552,
     555,   560,   125,   567,   570,   573,   576,   579,   582,   302,
     588,   751,   117,   308,   309,   310,   311,   312,   610,   304,
     305,   145,   739,   146,    23,    24,    25,    26,   264,   265,
     624,   633,   152,   234,    55,   188,   189,   190,   191,   623,
     634,    54,    71,    55,   126,    87,   639,   641,   643,   645,
     647,   168,    55,    55,   127,   179,   654,   656,   658,   660,
     662,   664,   180,   181,   128,    55,   667,   277,   278,   675,
     679,   681,   683,   685,   687,   689,   692,   696,   698,   700,
     702,   704,   706,   709,    86,    86,    86,    86,    86,    86,
      86,   722,    86,    86,    86,    86,   124,   129,    23,    24,
      25,    26,   238,    54,   624,   304,   305,    55,    54,   242,
      54,   235,    54,   243,    66,   119,   219,   274,     3,     4,
       5,     6,     7,     8,   251,     9,   340,   313,   314,    55,
      10,    55,   316,    55,   318,   177,   321,   322,    11,   224,
     225,   226,   227,    12,   756,   339,   735,   119,   229,   230,
     177,   231,   228,   229,   230,   341,   231,    55,   232,   233,
     630,   119,   736,   232,   233,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
     637,   737,   776,     3,     4,   738,   741,   394,    78,    75,
     401,   743,   744,   759,   745,    79,   418,   426,   431,   435,
     439,   443,     3,    23,    24,    25,    26,    89,    12,   624,
     748,   183,   463,   178,    90,   746,   476,   179,   184,   185,
     747,   342,   754,   754,   180,   181,   506,    12,     3,     4,
       5,     6,     7,     8,   765,     9,   760,   310,   311,   312,
      10,    23,    24,    25,    26,   561,   766,   624,    11,   767,
     768,   769,   368,    12,   589,   593,   595,   597,   599,   601,
     603,   605,   611,   182,   170,   761,   191,   183,   210,   219,
     754,   145,   271,   146,   184,   185,   445,   147,   148,   149,
     150,   151,   152,   772,   774,    55,     3,     4,     5,     6,
       7,     8,   229,     9,   807,   231,   249,   231,    10,    75,
     780,   168,   232,   233,   232,   233,    11,   301,   302,   303,
     668,    12,   782,   676,   755,   755,   781,   784,   304,   305,
     693,   789,   794,   808,   795,   583,   796,   710,   712,   714,
     715,   716,   717,   718,   719,   723,    87,    87,    87,    87,
     810,   626,   801,   816,   818,   629,   819,    55,   820,   821,
     631,   632,    55,   822,    55,   824,    55,    75,   783,   170,
     219,   779,   755,   171,   172,   173,   759,   828,     3,     4,
       5,     6,     7,     8,   221,     9,   323,   830,   829,   839,
      10,   222,   223,   224,   225,   226,   227,   840,    11,   207,
     208,   209,   210,    12,     3,     4,     5,     6,     7,     8,
     800,     9,   331,   849,   850,   855,    10,   853,     3,     4,
       5,     6,     7,     8,    11,     9,   333,   857,    54,    12,
      10,   302,   303,   345,   859,    54,   862,   827,    11,   791,
     350,   304,   305,    12,   811,    56,   170,    63,    65,    75,
     171,   172,   173,    72,    56,   858,    88,   762,   812,     0,
     174,     0,     0,    56,    56,     0,   177,   175,   176,     0,
     177,   219,     0,     0,   177,    75,    56,     0,     0,     3,
       4,     5,     6,     7,     8,     0,     9,   335,     0,    75,
       0,    10,   222,   223,   224,   225,   226,   227,     0,    11,
      23,    24,    25,    26,    12,   145,   624,   146,     0,   177,
       0,   147,   148,   149,   150,   151,   152,   177,    56,     0,
     100,     0,   100,     0,     0,   124,   160,   161,   275,     0,
     164,   165,   166,   167,     0,   168,    54,    54,    54,    54,
      56,    54,    56,   177,    56,   177,     0,   177,   294,   177,
      75,   177,     0,   177,     0,   295,   296,   297,   298,   299,
     300,     0,   177,   145,     0,   146,     0,     0,    56,    54,
       0,   149,   150,   151,   152,   177,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,   170,     0,   168,     0,   171,   172,   173,   395,   397,
     399,     0,   100,     0,     0,   177,     0,   419,   427,     0,
      54,     0,   175,   176,   258,   259,   260,   191,    54,     0,
       0,     0,    54,   464,    54,   247,   100,   477,     0,    54,
     266,   267,   268,   269,   270,   271,   286,   507,     0,     0,
      54,     0,    54,   100,     0,     0,   100,   287,   288,   289,
     290,   291,   292,     0,     0,    54,   562,     0,     0,    54,
     177,     0,    54,     0,     0,   590,   186,   187,   188,   189,
     190,   191,    55,   612,   614,   616,     0,   620,   622,    55,
       0,   197,   198,   308,   309,   310,   311,   312,   177,    51,
       3,     4,     5,     6,     7,     8,    56,     9,    51,     0,
      84,     0,    10,   297,   298,   299,   300,    51,    51,     0,
      11,   301,   302,   303,   177,    12,   268,   269,   270,   271,
      51,   669,   304,   305,   677,     0,     0,   341,     0,     0,
       0,   694,   205,   206,   207,   208,   209,   210,   711,   713,
     713,   713,   713,   713,   713,   713,   724,   725,   726,   727,
     728,   215,   216,   217,   218,     0,     0,     0,    56,     0,
       0,    75,    51,    56,     0,    56,     0,    56,   247,     0,
       0,     0,    84,   266,   267,   268,   269,   270,   271,     0,
      55,    55,    55,    55,    51,    55,    51,     0,    51,     3,
       4,     5,     6,     7,     8,   365,     9,     0,     0,     0,
       0,    10,   256,   257,   258,   259,   260,   191,     0,    11,
       0,     0,    51,    55,    12,     0,     0,   264,   265,     0,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,     0,     3,     4,     5,     6,
       7,     8,   390,     9,     0,   116,     0,     0,    10,     0,
       0,   414,   422,     0,    55,     0,    11,     0,     0,     0,
      75,    12,    55,     0,     0,     0,    55,   459,    55,   468,
     470,   472,     0,    55,     0,     0,     0,   804,     0,     0,
     809,   502,     0,     0,    55,     0,    55,     0,     0,     0,
       3,     4,     5,     6,     7,    83,     0,   815,     0,    55,
     557,     0,    79,    55,     0,     0,    55,    75,     0,   585,
      11,     0,     0,    76,     0,    12,     0,   607,     0,     0,
       0,     0,   832,   103,   834,     0,     0,    49,     0,     3,
       4,     5,     6,    60,    83,     0,    49,     0,     0,     0,
      51,    79,     0,     0,     0,    49,    49,     0,   249,    11,
       0,     0,   852,     0,    12,     0,     0,     0,    49,   228,
     229,   230,     0,   231,     0,   665,   671,   672,   673,     0,
     232,   233,     0,     0,     0,   690,     0,    76,     0,     0,
       0,     0,   707,    84,    84,    84,    84,    84,    84,    84,
     720,    84,    84,    84,    84,     0,     0,     0,     0,   315,
      49,   317,    51,     0,     0,   248,   219,    51,     0,    51,
       0,    51,     0,     0,     0,     0,   220,     0,     0,     0,
     221,     0,    49,     0,    49,     0,    49,   222,   223,   224,
     225,   226,   227,     0,     0,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   367,
      49,   186,   187,   188,   189,   190,   191,     0,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    56,   370,   374,   378,     0,     0,     0,
      56,     0,     0,     0,     0,     0,   145,     0,   146,   413,
     421,     0,   147,   148,   149,   150,   151,   152,   447,   449,
     451,   453,   455,   457,     0,     0,   466,   160,   161,     0,
     479,     0,     0,     0,     0,     0,   168,     0,     0,     0,
     509,     3,     4,     5,     6,     7,     8,     0,     9,   803,
       0,     0,     0,    10,     0,     0,     0,     0,     0,   564,
       0,    11,     0,     0,     0,     0,    12,     0,   592,     3,
       4,     5,     6,     7,     8,    76,     9,   340,   618,     0,
       0,    10,     0,     0,   308,   309,   310,   311,   312,    11,
       0,     0,     0,     0,    12,   261,   248,   263,    49,   264,
     265,    56,    56,    56,    56,     0,    56,   293,     0,     0,
       0,   294,    75,     0,     0,     0,     0,     0,   295,   296,
     297,   298,   299,   300,    52,   205,   206,   207,   208,   209,
     210,     0,     0,    52,    56,     0,     0,   734,     0,     0,
      75,     0,    52,    52,     0,     0,   742,   308,   309,   310,
     311,   312,     0,     0,     0,    52,   219,     0,   261,     0,
      49,     0,   264,   265,     0,    49,   220,    49,     0,    49,
     221,     0,     0,     0,     0,    56,     0,   222,   223,   224,
     225,   226,   227,    56,     0,     0,     0,    56,   293,    56,
       0,     0,   294,     0,    56,     0,     0,    52,     0,   295,
     296,   297,   298,   299,   300,    56,     0,    56,     0,     0,
       3,     4,     5,     6,     7,     8,     0,     9,   831,    52,
      56,    52,    10,    52,    56,     0,     0,    56,     0,     0,
      11,     0,     0,   246,     0,    12,     0,    51,   256,   257,
     258,   259,   260,   191,    51,     0,     0,    52,     0,   261,
     262,   263,     0,   264,   265,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
       0,     3,     4,     5,     6,     7,     8,   391,     9,   833,
       0,    75,     0,    10,     0,     0,   415,   423,     0,     0,
       0,    11,     0,     0,     0,     0,    12,     0,     0,     0,
       0,     0,   460,     0,     0,     0,   473,     0,   481,   483,
     266,   267,   268,   269,   270,   271,   503,   295,   296,   297,
     298,   299,   300,     0,     0,   122,   123,     0,     2,     3,
       4,     5,     6,     7,     8,   558,     9,     0,     0,     0,
       0,    10,    75,     0,   586,    51,    51,    51,    51,    11,
      51,     0,   608,     0,    12,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     0,     9,   851,     0,     0,
       0,    10,     0,     0,     0,    52,     0,     0,    51,    11,
       0,    13,    14,    15,    12,     0,    16,    17,    18,    19,
      20,    21,    22,     0,    23,    24,    25,    26,    27,    28,
      29,     3,     4,     5,     6,    60,     8,     0,     9,     0,
       0,     0,     0,    10,     0,     0,     0,     0,     0,    51,
       0,    11,     0,     0,     0,     0,    12,    51,     0,     0,
      75,    51,     0,    51,     0,     0,     0,    52,    51,     0,
       0,     0,    52,     0,    52,     0,    52,     0,     0,    51,
       0,    51,   778,     3,     4,     5,     6,     7,     8,    76,
       9,     0,     0,     0,    51,    10,     0,     0,    51,     0,
       0,    51,    61,    11,     0,    49,     0,     0,    12,     0,
       1,     0,    49,     2,     3,     4,     5,     6,     7,     8,
       0,     9,   145,     0,   146,     0,    10,     0,   147,   148,
     149,   150,   151,   152,    11,     0,     0,     0,     0,    12,
       0,     0,     0,   160,   161,   162,   163,   164,   165,   166,
     167,     0,   168,     0,    75,     0,     0,   130,     0,     0,
       0,     0,     0,     0,     0,     0,    13,    14,    15,     0,
       0,    16,    17,    18,    19,    20,    21,    22,     0,    23,
      24,    25,    26,    27,    28,    29,     0,     0,     0,     0,
       0,   786,     0,     0,     0,   790,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
       0,     0,     0,    49,    49,    49,    49,     0,    49,     0,
       0,     0,     0,   367,     0,     0,     0,     0,     0,     0,
       0,     0,   145,     0,   146,     0,     0,     0,   147,   148,
     149,   150,   151,   152,     0,   154,    49,     0,   156,   157,
     158,   159,    62,   160,   161,   162,   163,   164,   165,   166,
     167,     0,   168,     0,   837,     0,     0,     0,     0,   186,
     187,   188,   189,   190,   191,     0,   845,     0,   846,     0,
       0,     0,     0,   848,   197,   198,     0,    49,   201,   202,
     203,   204,     0,     0,   854,    49,     0,     0,     0,    49,
       0,    49,     0,     0,     0,     0,    49,     0,     0,   860,
       0,     0,     0,     0,     0,     0,     0,    49,     0,    49,
     145,     0,   146,     0,     0,     0,   147,   148,   149,   150,
     151,   152,    49,     0,     0,     0,    49,   157,     0,    49,
       0,   160,   161,   162,   163,   164,   165,   166,   167,   324,
     168,   324,     0,   324,     0,   324,     0,     0,     0,   324,
       0,   347,     0,     0,     0,     0,   205,   206,   207,   208,
     209,   210,   211,     0,     0,     0,   212,     0,     0,     0,
       0,     0,    52,   213,   214,   215,   216,   217,   218,    52,
     324,   369,   373,   377,   381,   384,   387,   389,   396,   398,
     400,   402,   404,   406,   408,   410,   412,   420,   428,   432,
     436,   440,   444,     0,   324,   446,   448,   450,   452,   454,
     456,     0,   458,   465,   467,   469,   471,   478,   480,   482,
     484,   487,   490,   493,   496,     0,   501,   508,   510,   512,
     514,   516,   518,   520,   523,   526,   529,   532,   535,   538,
     541,   544,   547,   550,   553,   556,   563,   565,   568,   571,
     574,   577,   580,   324,   584,   591,   594,   596,   598,   600,
     602,   604,   606,   613,   615,   617,   619,   621,     0,     0,
       0,     0,     0,   324,     0,     0,     0,     0,   324,   324,
      52,    52,    52,    52,     0,    52,     0,     0,    69,     0,
      81,    85,    91,   145,   241,   146,     0,     0,     0,   147,
     148,   149,   150,   151,   152,   153,   154,   155,     0,   156,
     157,   158,   159,    52,   160,   161,   162,   163,   164,   165,
     166,   167,   145,   168,   146,     0,     0,     0,   147,   148,
     149,   150,   151,   152,   153,   154,   155,     0,   156,   157,
     158,   159,     0,   160,   161,   162,   163,   164,   165,   166,
     167,     0,   168,     0,    52,     0,     0,     0,   254,    81,
       0,     0,    52,   272,     0,     0,    52,     0,    52,   306,
     307,     0,     0,    52,     0,   324,     0,     0,     0,     0,
       0,     0,     0,     0,    52,   326,    52,   326,     0,   326,
       0,   326,     0,     0,     0,   326,     0,   348,     0,    52,
       0,     0,   246,    52,     0,     0,    52,   308,   309,   310,
     311,   312,     0,     0,     0,     0,     0,     0,   261,   262,
     263,     0,   264,   265,     0,     0,   326,   371,   375,   379,
     382,   385,   348,   392,   348,   348,   348,   403,   405,   407,
     409,   411,   416,   424,   429,   433,   437,   441,   348,     0,
     326,   348,   348,   348,   348,   348,   348,     0,   461,   348,
     348,   348,   474,   348,   348,   348,   485,   488,   491,   494,
     497,   499,   504,   348,   511,   513,   515,   517,   519,   521,
     524,   527,   530,   533,   536,   539,   542,   545,   548,   551,
     554,   559,   348,   566,   569,   572,   575,   578,   581,   326,
     587,   348,   348,   348,   348,   348,   348,   348,   609,   348,
     348,   348,   348,   348,     0,     0,     0,     0,     0,   326,
       0,     0,     0,     0,   326,   326,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   638,   640,   642,   644,
     646,   648,   649,   650,   651,   652,   653,   655,   657,   659,
     661,   663,     0,     0,     0,     0,   666,     0,     0,   674,
     678,   680,   682,   684,   686,   688,   691,   695,   697,   699,
     701,   703,   705,   708,    85,    85,    85,    85,    85,    85,
      85,   721,    85,    85,    85,    85,     0,     0,   729,   730,
     731,   732,   733,     0,   123,     0,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,   740,     0,    10,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     0,
       0,   326,    12,     0,   123,     0,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,   788,     0,    10,
       0,     0,     0,     0,     0,     0,     0,    11,     0,    13,
      14,    15,    12,     0,    16,    17,    18,    19,    20,    21,
      22,     0,    23,    24,    25,    26,    27,    28,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
      14,    15,     0,     0,    16,    17,    18,    19,    20,    21,
      22,     0,    23,    24,    25,    26,    27,    28,    29,    98,
       3,     4,     5,     6,     7,     8,     0,     9,     0,    99,
       0,     0,    10,     0,     0,     0,     0,     0,     0,     0,
      11,   145,     0,   146,     0,    12,     0,   147,   148,   149,
     150,   151,   152,     0,   154,   155,     0,   156,   157,   158,
     159,     0,   160,   161,   162,   163,   164,   165,   166,   167,
       0,   168,    13,    14,    15,     0,     0,    16,    17,    18,
      19,    20,    21,    22,     0,    23,    24,    25,    26,    27,
      28,    29,     0,     0,     0,     0,     0,   324,   247,     0,
       0,     0,     0,   205,   206,   207,   208,   209,   210,   211,
       0,     0,     0,   212,     0,   324,     0,     0,   324,     0,
     213,   214,   215,   216,   217,   218,     0,   324,     0,     0,
       0,     0,     0,     0,     0,   324,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,   319,
       0,    10,     0,     0,     0,     0,     0,     0,     0,    11,
     324,     0,   324,     0,    12,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,     0,
       0,    10,     0,     0,     0,     0,     0,     0,     0,    11,
     324,    13,    14,    15,    12,     0,    16,    17,    18,    19,
      20,    21,    22,     0,    23,    24,    25,    26,    27,    28,
      29,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13,    14,    15,     0,     0,    16,    17,    18,    19,
      20,    21,    22,     0,    23,    24,    25,    26,    27,    28,
      29,   145,     0,   146,     0,     0,     0,   147,   148,   149,
     150,   151,   152,     0,     0,     0,     0,   156,   157,   158,
     159,     0,   160,   161,   162,   163,   164,   165,   166,   167,
     145,   168,   146,     0,     0,     0,   147,   148,   149,   150,
     151,   152,     0,     0,     0,     0,     0,   157,   158,   159,
       0,   160,   161,   162,   163,   164,   165,   166,   167,   145,
     168,   146,     0,     0,     0,   147,   148,   149,   150,   151,
     152,     0,     0,     0,     0,     0,   157,     0,   159,     0,
     160,   161,   162,   163,   164,   165,   166,   167,     0,   168,
     246,     0,     0,     0,     0,   186,   187,   188,   189,   190,
     191,   192,     0,   326,     0,   193,   194,   195,   196,     0,
     197,   198,   199,   200,   201,   202,   203,   204,     0,     0,
       0,   326,     0,     0,   326,     0,     0,     0,     0,   246,
       0,     0,     0,   326,   256,   257,   258,   259,   260,   191,
     279,   326,     0,     0,     0,   261,   262,   263,     0,   264,
     265,   280,   281,   282,   283,   284,   285,     0,     0,   186,
     187,   188,   189,   190,   191,   192,   326,     0,   326,   193,
     194,   195,   196,     0,   197,   198,   199,   200,   201,   202,
     203,   204,   256,   257,   258,   259,   260,   191,   279,     0,
       0,     0,     0,   261,   262,   263,   326,   264,   265,   280,
     281,   282,   283,   284,   285,   186,   187,   188,   189,   190,
     191,     0,     0,     0,     0,   193,   194,   195,   196,     0,
     197,   198,   199,   200,   201,   202,   203,   204,   256,   257,
     258,   259,   260,   191,     0,     0,     0,     0,     0,   261,
     262,   263,     0,   264,   265,   280,   281,   282,   283,   284,
     285,   186,   187,   188,   189,   190,   191,     0,     0,     0,
       0,     0,   194,     0,   196,     0,   197,   198,   199,   200,
     201,   202,   203,   204,   186,   187,   188,   189,   190,   191,
       0,     0,     0,     0,     0,   194,     0,     0,     0,   197,
     198,   199,   200,   201,   202,   203,   204,   186,   187,   188,
     189,   190,   191,   266,   267,   268,   269,   270,   271,   286,
       0,     0,   197,   198,   199,   200,   201,   202,   203,   204,
     287,   288,   289,   290,   291,   292,   205,   206,   207,   208,
     209,   210,     0,     0,     0,     0,   212,   266,   267,   268,
     269,   270,   271,   213,   214,   215,   216,   217,   218,     0,
       0,     0,     0,     0,   287,   288,   289,   290,   291,   292,
     256,   257,   258,   259,   260,   191,     0,     0,     0,     0,
       0,   261,   262,   263,     0,   264,   265,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144
  };

  const short
   Parser ::yycheck_[] =
  {
       0,   105,    18,   107,    61,   109,    73,   111,     8,     9,
      10,    11,   236,    99,     9,     9,     9,    31,    18,    19,
     627,    10,   338,   748,   749,     9,     9,     9,    38,    75,
      40,    31,     3,     4,     5,     6,     7,     8,     9,    11,
      11,    12,     4,     5,    11,    16,    13,     9,   736,    75,
     738,    40,     3,    24,    16,    11,    40,    75,    29,    11,
      42,    59,    60,    14,   756,    12,     3,    29,    11,    11,
      10,   796,    39,    73,    12,     9,    13,    11,    78,    79,
      75,    75,    75,    83,   776,     3,     4,     5,     6,     7,
       8,     9,    75,    11,    41,    95,    68,    97,    16,    99,
      40,    68,    40,    41,    75,    56,    24,   799,    75,   123,
       9,    29,    68,    75,   338,   339,    68,    12,    69,    70,
      71,    72,   814,   123,    75,    68,    68,    12,     9,    12,
     818,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,    41,   147,   148,   149,
     150,   151,   152,   153,   842,    14,    41,    75,    41,     8,
       9,    21,   162,   163,   164,   165,   166,   167,     3,    12,
       3,   859,    32,    33,   862,     3,     0,    11,   178,    12,
      39,    75,   182,    17,   251,    13,   186,   187,   188,   189,
     190,   191,   192,   800,    11,     9,    13,    75,    41,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,     3,   213,   214,   215,   216,   217,   218,    22,
     220,    56,    39,    15,    16,    17,    18,    19,   228,    32,
      33,     9,   318,    11,    69,    70,    71,    72,    30,    31,
      75,     3,    20,    68,     0,    17,    18,    19,    20,    10,
      12,   251,     8,     9,     3,    11,   256,   257,   258,   259,
     260,    39,    18,    19,     3,    25,   266,   267,   268,   269,
     270,   271,    32,    33,     3,    31,   276,    32,    33,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   320,     3,    69,    70,
      71,    72,    10,   313,    75,    32,    33,    73,   318,    10,
     320,    68,   322,    10,     8,    29,    11,    83,     4,     5,
       6,     7,     8,     9,    40,    11,    12,    42,    40,    95,
      16,    97,    75,    99,    13,    49,    62,    42,    24,    34,
      35,    36,    37,    29,    10,     9,    75,    61,    22,    23,
      64,    25,    21,    22,    23,    41,    25,   123,    32,    33,
      10,    75,    10,    32,    33,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
      12,    41,    10,     4,     5,    10,     9,   153,     9,    75,
     156,    40,    12,   627,    12,    16,   162,   163,   164,   165,
     166,   167,     4,    69,    70,    71,    72,     9,    29,    75,
      13,    25,   178,    21,    16,    12,   182,    25,    32,    33,
      12,   115,   748,   749,    32,    33,   192,    29,     4,     5,
       6,     7,     8,     9,    12,    11,    12,    17,    18,    19,
      16,    69,    70,    71,    72,   211,    75,    75,    24,    14,
      10,    40,   146,    29,   220,   221,   222,   223,   224,   225,
     226,   227,   228,    21,    11,    41,    20,    25,    20,    11,
     796,     9,    20,    11,    32,    33,   170,    15,    16,    17,
      18,    19,    20,    12,    10,   251,     4,     5,     6,     7,
       8,     9,    22,    11,    12,    25,    10,    25,    16,    75,
      10,    39,    32,    33,    32,    33,    24,    21,    22,    23,
     276,    29,    12,   279,   748,   749,    38,     8,    32,    33,
     286,     3,    75,    41,    14,   219,     3,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
      42,   775,    40,    59,    10,   239,     3,   313,    10,    14,
     244,   245,   318,    42,   320,    42,   322,    75,   635,    11,
      11,   628,   796,    15,    16,    17,   800,   801,     4,     5,
       6,     7,     8,     9,    25,    11,    12,    12,    42,    10,
      16,    32,    33,    34,    35,    36,    37,     9,    24,    17,
      18,    19,    20,    29,     4,     5,     6,     7,     8,     9,
      40,    11,    12,    12,    12,     9,    16,    40,     4,     5,
       6,     7,     8,     9,    24,    11,    12,    12,   628,    29,
      16,    22,    23,    39,    10,   635,    10,   801,    24,   743,
     131,    32,    33,    29,   769,     0,    11,     8,     8,    75,
      15,    16,    17,     8,     9,   853,    11,   341,   775,    -1,
      25,    -1,    -1,    18,    19,    -1,   370,    32,    33,    -1,
     374,    11,    -1,    -1,   378,    75,    31,    -1,    -1,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    -1,    75,
      -1,    16,    32,    33,    34,    35,    36,    37,    -1,    24,
      69,    70,    71,    72,    29,     9,    75,    11,    -1,   413,
      -1,    15,    16,    17,    18,    19,    20,   421,    73,    -1,
     736,    -1,   738,    -1,    -1,   739,    30,    31,    83,    -1,
      34,    35,    36,    37,    -1,    39,   736,   737,   738,   739,
      95,   741,    97,   447,    99,   449,    -1,   451,    25,   453,
      75,   455,    -1,   457,    -1,    32,    33,    34,    35,    36,
      37,    -1,   466,     9,    -1,    11,    -1,    -1,   123,   769,
      -1,    17,    18,    19,    20,   479,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,    11,    -1,    39,    -1,    15,    16,    17,   153,   154,
     155,    -1,   818,    -1,    -1,   509,    -1,   162,   163,    -1,
     810,    -1,    32,    33,    17,    18,    19,    20,   818,    -1,
      -1,    -1,   822,   178,   824,    10,   842,   182,    -1,   829,
      15,    16,    17,    18,    19,    20,    21,   192,    -1,    -1,
     840,    -1,   842,   859,    -1,    -1,   862,    32,    33,    34,
      35,    36,    37,    -1,    -1,   855,   211,    -1,    -1,   859,
     564,    -1,   862,    -1,    -1,   220,    15,    16,    17,    18,
      19,    20,   628,   228,   229,   230,    -1,   232,   233,   635,
      -1,    30,    31,    15,    16,    17,    18,    19,   592,     0,
       4,     5,     6,     7,     8,     9,   251,    11,     9,    -1,
      11,    -1,    16,    34,    35,    36,    37,    18,    19,    -1,
      24,    21,    22,    23,   618,    29,    17,    18,    19,    20,
      31,   276,    32,    33,   279,    -1,    -1,    41,    -1,    -1,
      -1,   286,    15,    16,    17,    18,    19,    20,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,    34,    35,    36,    37,    -1,    -1,    -1,   313,    -1,
      -1,    75,    73,   318,    -1,   320,    -1,   322,    10,    -1,
      -1,    -1,    83,    15,    16,    17,    18,    19,    20,    -1,
     736,   737,   738,   739,    95,   741,    97,    -1,    99,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    16,    15,    16,    17,    18,    19,    20,    -1,    24,
      -1,    -1,   123,   769,    29,    -1,    -1,    30,    31,    -1,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,    -1,     4,     5,     6,     7,
       8,     9,   153,    11,    -1,    13,    -1,    -1,    16,    -1,
      -1,   162,   163,    -1,   810,    -1,    24,    -1,    -1,    -1,
      75,    29,   818,    -1,    -1,    -1,   822,   178,   824,   180,
     181,   182,    -1,   829,    -1,    -1,    -1,   761,    -1,    -1,
     764,   192,    -1,    -1,   840,    -1,   842,    -1,    -1,    -1,
       4,     5,     6,     7,     8,     9,    -1,   781,    -1,   855,
     211,    -1,    16,   859,    -1,    -1,   862,    75,    -1,   220,
      24,    -1,    -1,     9,    -1,    29,    -1,   228,    -1,    -1,
      -1,    -1,   806,    19,   808,    -1,    -1,     0,    -1,     4,
       5,     6,     7,     8,     9,    -1,     9,    -1,    -1,    -1,
     251,    16,    -1,    -1,    -1,    18,    19,    -1,    10,    24,
      -1,    -1,   836,    -1,    29,    -1,    -1,    -1,    31,    21,
      22,    23,    -1,    25,    -1,   276,   277,   278,   279,    -1,
      32,    33,    -1,    -1,    -1,   286,    -1,    73,    -1,    -1,
      -1,    -1,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,    -1,    -1,    -1,    -1,    95,
      73,    97,   313,    -1,    -1,    10,    11,   318,    -1,   320,
      -1,   322,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,
      25,    -1,    95,    -1,    97,    -1,    99,    32,    33,    34,
      35,    36,    37,    -1,    -1,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     123,    15,    16,    17,    18,    19,    20,    -1,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   628,   147,   148,   149,    -1,    -1,    -1,
     635,    -1,    -1,    -1,    -1,    -1,     9,    -1,    11,   162,
     163,    -1,    15,    16,    17,    18,    19,    20,   171,   172,
     173,   174,   175,   176,    -1,    -1,   179,    30,    31,    -1,
     183,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,
     193,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,   212,
      -1,    24,    -1,    -1,    -1,    -1,    29,    -1,   221,     4,
       5,     6,     7,     8,     9,   251,    11,    12,   231,    -1,
      -1,    16,    -1,    -1,    15,    16,    17,    18,    19,    24,
      -1,    -1,    -1,    -1,    29,    26,    10,    28,   251,    30,
      31,   736,   737,   738,   739,    -1,   741,    21,    -1,    -1,
      -1,    25,    75,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37,     0,    15,    16,    17,    18,    19,
      20,    -1,    -1,     9,   769,    -1,    -1,   313,    -1,    -1,
      75,    -1,    18,    19,    -1,    -1,   322,    15,    16,    17,
      18,    19,    -1,    -1,    -1,    31,    11,    -1,    26,    -1,
     313,    -1,    30,    31,    -1,   318,    21,   320,    -1,   322,
      25,    -1,    -1,    -1,    -1,   810,    -1,    32,    33,    34,
      35,    36,    37,   818,    -1,    -1,    -1,   822,    21,   824,
      -1,    -1,    25,    -1,   829,    -1,    -1,    73,    -1,    32,
      33,    34,    35,    36,    37,   840,    -1,   842,    -1,    -1,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    95,
     855,    97,    16,    99,   859,    -1,    -1,   862,    -1,    -1,
      24,    -1,    -1,    10,    -1,    29,    -1,   628,    15,    16,
      17,    18,    19,    20,   635,    -1,    -1,   123,    -1,    26,
      27,    28,    -1,    30,    31,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
      -1,     4,     5,     6,     7,     8,     9,   153,    11,    12,
      -1,    75,    -1,    16,    -1,    -1,   162,   163,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,   178,    -1,    -1,    -1,   182,    -1,   184,   185,
      15,    16,    17,    18,    19,    20,   192,    32,    33,    34,
      35,    36,    37,    -1,    -1,     0,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,   211,    11,    -1,    -1,    -1,
      -1,    16,    75,    -1,   220,   736,   737,   738,   739,    24,
     741,    -1,   228,    -1,    29,    -1,    -1,    -1,    -1,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    -1,    -1,
      -1,    16,    -1,    -1,    -1,   251,    -1,    -1,   769,    24,
      -1,    56,    57,    58,    29,    -1,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,   810,
      -1,    24,    -1,    -1,    -1,    -1,    29,   818,    -1,    -1,
      75,   822,    -1,   824,    -1,    -1,    -1,   313,   829,    -1,
      -1,    -1,   318,    -1,   320,    -1,   322,    -1,    -1,   840,
      -1,   842,   628,     4,     5,     6,     7,     8,     9,   635,
      11,    -1,    -1,    -1,   855,    16,    -1,    -1,   859,    -1,
      -1,   862,    75,    24,    -1,   628,    -1,    -1,    29,    -1,
       0,    -1,   635,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,     9,    -1,    11,    -1,    16,    -1,    15,    16,
      17,    18,    19,    20,    24,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    -1,    75,    -1,    -1,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,
      -1,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,   737,    -1,    -1,    -1,   741,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,   736,   737,   738,   739,    -1,   741,    -1,
      -1,    -1,    -1,   769,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    -1,    22,   769,    -1,    25,    26,
      27,    28,     8,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    -1,   810,    -1,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    -1,   822,    -1,   824,    -1,
      -1,    -1,    -1,   829,    30,    31,    -1,   810,    34,    35,
      36,    37,    -1,    -1,   840,   818,    -1,    -1,    -1,   822,
      -1,   824,    -1,    -1,    -1,    -1,   829,    -1,    -1,   855,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   840,    -1,   842,
       9,    -1,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,   855,    -1,    -1,    -1,   859,    26,    -1,   862,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,   105,
      39,   107,    -1,   109,    -1,   111,    -1,    -1,    -1,   115,
      -1,   117,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    -1,   628,    32,    33,    34,    35,    36,    37,   635,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,    -1,   170,   171,   172,   173,   174,   175,
     176,    -1,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,   244,   245,
     736,   737,   738,   739,    -1,   741,    -1,    -1,     8,    -1,
      10,    11,    12,     9,    10,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    25,
      26,    27,    28,   769,    30,    31,    32,    33,    34,    35,
      36,    37,     9,    39,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    -1,   810,    -1,    -1,    -1,    78,    79,
      -1,    -1,   818,    83,    -1,    -1,   822,    -1,   824,    89,
      90,    -1,    -1,   829,    -1,   341,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   840,   105,   842,   107,    -1,   109,
      -1,   111,    -1,    -1,    -1,   115,    -1,   117,    -1,   855,
      -1,    -1,    10,   859,    -1,    -1,   862,    15,    16,    17,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    -1,    30,    31,    -1,    -1,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,    -1,
     170,   171,   172,   173,   174,   175,   176,    -1,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,   244,   245,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,    -1,    -1,    -1,    -1,   276,    -1,    -1,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,    -1,    -1,   308,   309,
     310,   311,   312,    -1,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    -1,    14,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,   341,    29,    -1,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    -1,    14,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    56,
      57,    58,    29,    -1,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    58,    -1,    -1,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    -1,    13,
      -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,     9,    -1,    11,    -1,    29,    -1,    15,    16,    17,
      18,    19,    20,    -1,    22,    23,    -1,    25,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    39,    56,    57,    58,    -1,    -1,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,   743,    10,    -1,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    25,    -1,   761,    -1,    -1,   764,    -1,
      32,    33,    34,    35,    36,    37,    -1,   773,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   781,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    -1,    -1,    14,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
     806,    -1,   808,    -1,    29,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    -1,    -1,    -1,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
     836,    56,    57,    58,    29,    -1,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    -1,    -1,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,     9,    -1,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
       9,    39,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,     9,
      39,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    39,
      10,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    -1,   743,    -1,    25,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,   761,    -1,    -1,   764,    -1,    -1,    -1,    -1,    10,
      -1,    -1,    -1,   773,    15,    16,    17,    18,    19,    20,
      21,   781,    -1,    -1,    -1,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,   806,    -1,   808,    25,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    26,    27,    28,   836,    30,    31,    32,
      33,    34,    35,    36,    37,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    25,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,    -1,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    15,    16,    17,
      18,    19,    20,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      32,    33,    34,    35,    36,    37,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    25,    15,    16,    17,
      18,    19,    20,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    37,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    -1,    30,    31,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
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
      51,    52,    53,    54,    55,     9,    11,    15,    16,    17,
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
     119,   105,   119,    10,    75,   121,   124,     9,    42,   110,
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
      14,    56,    95,    96,   100,   124,    10,    98,    99,   124,
      12,    41,   110,    12,    41,    12,    75,    14,    10,    40,
      12,    12,    12,    11,    10,    40,    10,    98,   104,   114,
      10,    38,    12,   107,     8,    83,   104,    83,    14,     3,
     104,   123,    95,    95,    75,    14,     3,    75,    82,    10,
      40,    40,    75,    12,   110,    12,    41,    12,    41,   110,
      42,   103,   121,    82,    10,   110,    59,    92,    10,     3,
      10,    14,    42,    95,    42,    82,    98,    99,   124,    42,
      12,    12,   110,    12,   110,    12,    41,   104,    82,    10,
       9,    59,    60,    93,    83,   104,   104,    75,   104,    12,
      12,    12,   110,    40,   104,     9,    83,    12,   115,    10,
     104,    83,    10,    83
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
     102,   102,   102,   102,   103,   103,   104,   104,   104,   104,
     104,   104,   104,   104,   105,   105,   105,   105,   105,   105,
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
     105,   105,   105,   105,   105,   105,   105,   105,   106,   106,
     106,   106,   106,   107,   107,   107,   108,   108,   108,   108,
     109,   109,   110,   110,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   112,   112,   113,   113,
     114,   114,   115,   115,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   120,   120,   121,   121,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     123,   123,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124
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
       3,     3,     3,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     3,     4,     4,
       4,     4,     4,     2,     2,     2,     3,     3,     3,     3,
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
       4,     3,     4,     3,     4,     3,     4,     3,     4,     3,
       1,     3,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1
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
       0,   188,   188,   189,   191,   192,   193,   197,   198,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   215,   216,   217,   218,   219,   222,   223,   227,   229,
     230,   234,   235,   236,   238,   239,   243,   247,   250,   254,
     256,   257,   258,   260,   261,   265,   266,   267,   269,   270,
     271,   272,   274,   275,   276,   280,   281,   282,   283,   285,
     286,   287,   289,   290,   294,   298,   299,   300,   301,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   323,   324,   328,   329,   330,   331,
     332,   333,   334,   335,   338,   339,   340,   342,   343,   345,
     346,   347,   348,   350,   351,   352,   354,   355,   357,   358,
     359,   361,   362,   363,   364,   365,   366,   367,   368,   370,
     371,   372,   373,   374,   376,   377,   378,   379,   380,   382,
     383,   384,   385,   386,   387,   388,   389,   391,   392,   393,
     394,   395,   396,   397,   398,   400,   401,   402,   404,   405,
     406,   408,   409,   410,   411,   412,   413,   414,   416,   417,
     418,   419,   420,   421,   422,   424,   425,   426,   427,   428,
     429,   430,   432,   433,   434,   435,   436,   437,   438,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   476,   477,   478,   480,   481,   482,   484,
     485,   486,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   505,   506,
     507,   509,   510,   511,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   540,   541,
     542,   543,   544,   546,   547,   548,   552,   553,   554,   555,
     557,   558,   560,   561,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   578,   579,   583,   584,
     586,   587,   589,   590,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   628,   629,   630,   631,   635,
     636,   637,   638,   639,   640,   641,   642,   643,   644,   645,
     646,   647,   648,   649,   650,   651,   652,   653,   654,   655,
     656,   657,   658,   659,   660,   661,   665,   666,   667,   668,
     669,   671,   672,   673,   674,   675,   676,   677,   679,   680,
     681,   682,   683,   684,   685,   687,   688,   689,   690,   691,
     693,   694,   695,   696,   697,   699,   700,   701,   702,   703,
     705,   706,   707,   708,   709,   711,   715,   716,   718,   719,
     723,   724,   725,   726,   727,   728,   729,   730,   731,   732,
     734,   735,   739,   740,   741,   742,   743,   744,   745,   746,
     747,   748,   749,   750,   751,   752
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
#line 3024 "frontend/parser.cpp"

#line 755 "frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    auto msg = std::to_string(scanner->loc->begin.line) + ":" + std::to_string(scanner->loc->begin.column) + ": " + err_message;
    ptc::log::error(msg);
}
