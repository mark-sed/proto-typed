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
#line 37 "frontend/parser.yy"


    #include <cmath>
    #include <sstream>
    // Include compiler to use error
    #include "scanner.hpp"

    // Set correct token method
    #undef yylex
    #define yylex scanner->yylex

#line 58 "frontend/parser.cpp"


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

#line 13 "frontend/parser.yy"
namespace  ptc  {
#line 151 "frontend/parser.cpp"

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
#line 585 "frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 787 "frontend/parser.cpp"
    break;

  case 305: // expr_int: "-" expr_int
#line 586 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 793 "frontend/parser.cpp"
    break;

  case 306: // expr_int: "(" expr_int ")"
#line 587 "frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 799 "frontend/parser.cpp"
    break;

  case 307: // expr_int: "~" expr_int
#line 588 "frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 805 "frontend/parser.cpp"
    break;

  case 308: // expr_int: expr_int "*" expr_int
#line 589 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 811 "frontend/parser.cpp"
    break;

  case 309: // expr_int: expr_int "/" expr_int
#line 590 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 817 "frontend/parser.cpp"
    break;

  case 310: // expr_int: expr_int "%" expr_int
#line 591 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 823 "frontend/parser.cpp"
    break;

  case 311: // expr_int: expr_int "-" expr_int
#line 592 "frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 829 "frontend/parser.cpp"
    break;

  case 312: // expr_int: expr_int "+" expr_int
#line 593 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 835 "frontend/parser.cpp"
    break;

  case 313: // expr_int: expr_int "<<" expr_int
#line 594 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 841 "frontend/parser.cpp"
    break;

  case 314: // expr_int: expr_int ">>" expr_int
#line 595 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 847 "frontend/parser.cpp"
    break;

  case 315: // expr_int: expr_int "&" expr_int
#line 596 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 853 "frontend/parser.cpp"
    break;

  case 316: // expr_int: expr_int "^" expr_int
#line 597 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 859 "frontend/parser.cpp"
    break;

  case 317: // expr_int: expr_int "|" expr_int
#line 598 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 865 "frontend/parser.cpp"
    break;

  case 318: // expr_float: "float"
#line 602 "frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 871 "frontend/parser.cpp"
    break;

  case 319: // expr_float: "-" expr_float
#line 603 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 877 "frontend/parser.cpp"
    break;

  case 320: // expr_float: "(" expr_float ")"
#line 604 "frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 883 "frontend/parser.cpp"
    break;

  case 321: // expr_float: expr_float "**" expr_float
#line 605 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 889 "frontend/parser.cpp"
    break;

  case 322: // expr_float: expr_float "**" expr_int
#line 606 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 895 "frontend/parser.cpp"
    break;

  case 323: // expr_float: expr_int "**" expr_float
#line 607 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 901 "frontend/parser.cpp"
    break;

  case 324: // expr_float: expr_float "*" expr_float
#line 608 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 907 "frontend/parser.cpp"
    break;

  case 325: // expr_float: expr_float "*" expr_int
#line 609 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 913 "frontend/parser.cpp"
    break;

  case 326: // expr_float: expr_int "*" expr_float
#line 610 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 919 "frontend/parser.cpp"
    break;

  case 327: // expr_float: expr_float "/" expr_float
#line 611 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 925 "frontend/parser.cpp"
    break;

  case 328: // expr_float: expr_float "/" expr_int
#line 612 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 931 "frontend/parser.cpp"
    break;

  case 329: // expr_float: expr_int "/" expr_float
#line 613 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 937 "frontend/parser.cpp"
    break;

  case 330: // expr_float: expr_float "%" expr_float
#line 614 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 943 "frontend/parser.cpp"
    break;

  case 331: // expr_float: expr_float "%" expr_int
#line 615 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 949 "frontend/parser.cpp"
    break;

  case 332: // expr_float: expr_int "%" expr_float
#line 616 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 955 "frontend/parser.cpp"
    break;

  case 333: // expr_float: expr_float "-" expr_float
#line 617 "frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 961 "frontend/parser.cpp"
    break;

  case 334: // expr_float: expr_float "-" expr_int
#line 618 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 967 "frontend/parser.cpp"
    break;

  case 335: // expr_float: expr_int "-" expr_float
#line 619 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 973 "frontend/parser.cpp"
    break;

  case 336: // expr_float: expr_float "+" expr_float
#line 620 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 979 "frontend/parser.cpp"
    break;

  case 337: // expr_float: expr_float "+" expr_int
#line 621 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 985 "frontend/parser.cpp"
    break;

  case 338: // expr_float: expr_int "+" expr_float
#line 622 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 991 "frontend/parser.cpp"
    break;

  case 339: // expr_str: "string"
#line 626 "frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 997 "frontend/parser.cpp"
    break;

  case 340: // expr_str: "(" expr_str ")"
#line 627 "frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 1003 "frontend/parser.cpp"
    break;

  case 341: // expr_str: expr_str "++" expr_str
#line 628 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 1009 "frontend/parser.cpp"
    break;

  case 342: // expr_str: expr_str "++" expr_int
#line 629 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 1015 "frontend/parser.cpp"
    break;

  case 343: // expr_str: expr_str "++" expr_float
#line 630 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 1021 "frontend/parser.cpp"
    break;

  case 344: // expr_str: expr_str "++" expr_bool
#line 631 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1027 "frontend/parser.cpp"
    break;

  case 345: // expr_str: expr_str "++" expr_none
#line 632 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 1033 "frontend/parser.cpp"
    break;

  case 346: // expr_str: expr_int "++" expr_str
#line 633 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 1039 "frontend/parser.cpp"
    break;

  case 347: // expr_str: expr_int "++" expr_int
#line 634 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 1045 "frontend/parser.cpp"
    break;

  case 348: // expr_str: expr_int "++" expr_float
#line 635 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 1051 "frontend/parser.cpp"
    break;

  case 349: // expr_str: expr_int "++" expr_bool
#line 636 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1057 "frontend/parser.cpp"
    break;

  case 350: // expr_str: expr_int "++" expr_none
#line 637 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 1063 "frontend/parser.cpp"
    break;

  case 351: // expr_str: expr_float "++" expr_str
#line 638 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 1069 "frontend/parser.cpp"
    break;

  case 352: // expr_str: expr_float "++" expr_int
#line 639 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 1075 "frontend/parser.cpp"
    break;

  case 353: // expr_str: expr_float "++" expr_float
#line 640 "frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 1081 "frontend/parser.cpp"
    break;

  case 354: // expr_str: expr_float "++" expr_bool
#line 641 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1087 "frontend/parser.cpp"
    break;

  case 355: // expr_str: expr_float "++" expr_none
#line 642 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 1093 "frontend/parser.cpp"
    break;

  case 356: // expr_str: expr_bool "++" expr_str
#line 643 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 1099 "frontend/parser.cpp"
    break;

  case 357: // expr_str: expr_bool "++" expr_int
#line 644 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 1105 "frontend/parser.cpp"
    break;

  case 358: // expr_str: expr_bool "++" expr_float
#line 645 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 1111 "frontend/parser.cpp"
    break;

  case 359: // expr_str: expr_bool "++" expr_bool
#line 646 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1117 "frontend/parser.cpp"
    break;

  case 360: // expr_str: expr_bool "++" expr_none
#line 647 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 1123 "frontend/parser.cpp"
    break;

  case 361: // expr_str: expr_none "++" expr_str
#line 648 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 1129 "frontend/parser.cpp"
    break;

  case 362: // expr_str: expr_none "++" expr_int
#line 649 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 1135 "frontend/parser.cpp"
    break;

  case 363: // expr_str: expr_none "++" expr_float
#line 650 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 1141 "frontend/parser.cpp"
    break;

  case 364: // expr_str: expr_none "++" expr_bool
#line 651 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1147 "frontend/parser.cpp"
    break;

  case 365: // expr_str: expr_none "++" expr_none
#line 652 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 1153 "frontend/parser.cpp"
    break;

  case 366: // expr_bool: "bool"
#line 656 "frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 1159 "frontend/parser.cpp"
    break;

  case 367: // expr_bool: "(" expr_bool ")"
#line 657 "frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 1165 "frontend/parser.cpp"
    break;

  case 368: // expr_bool: "not" expr_bool
#line 658 "frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 1171 "frontend/parser.cpp"
    break;

  case 369: // expr_bool: expr_bool "or" expr_bool
#line 659 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 1177 "frontend/parser.cpp"
    break;

  case 370: // expr_bool: expr_bool "and" expr_bool
#line 660 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 1183 "frontend/parser.cpp"
    break;

  case 371: // expr_bool: expr_bool "==" expr_bool
#line 662 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 1189 "frontend/parser.cpp"
    break;

  case 372: // expr_bool: expr_int "==" expr_int
#line 663 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 1195 "frontend/parser.cpp"
    break;

  case 373: // expr_bool: expr_int "==" expr_float
#line 664 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 1201 "frontend/parser.cpp"
    break;

  case 374: // expr_bool: expr_float "==" expr_float
#line 665 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 1207 "frontend/parser.cpp"
    break;

  case 375: // expr_bool: expr_float "==" expr_int
#line 666 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 1213 "frontend/parser.cpp"
    break;

  case 376: // expr_bool: expr_str "==" expr_str
#line 667 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 1219 "frontend/parser.cpp"
    break;

  case 377: // expr_bool: expr_none "==" expr_none
#line 668 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 1225 "frontend/parser.cpp"
    break;

  case 378: // expr_bool: expr_bool "!=" expr_bool
#line 670 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 1231 "frontend/parser.cpp"
    break;

  case 379: // expr_bool: expr_int "!=" expr_int
#line 671 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 1237 "frontend/parser.cpp"
    break;

  case 380: // expr_bool: expr_int "!=" expr_float
#line 672 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 1243 "frontend/parser.cpp"
    break;

  case 381: // expr_bool: expr_float "!=" expr_float
#line 673 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 1249 "frontend/parser.cpp"
    break;

  case 382: // expr_bool: expr_float "!=" expr_int
#line 674 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 1255 "frontend/parser.cpp"
    break;

  case 383: // expr_bool: expr_str "!=" expr_str
#line 675 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 1261 "frontend/parser.cpp"
    break;

  case 384: // expr_bool: expr_none "!=" expr_none
#line 676 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 1267 "frontend/parser.cpp"
    break;

  case 385: // expr_bool: expr_int ">" expr_int
#line 678 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 1273 "frontend/parser.cpp"
    break;

  case 386: // expr_bool: expr_int ">" expr_float
#line 679 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 1279 "frontend/parser.cpp"
    break;

  case 387: // expr_bool: expr_float ">" expr_float
#line 680 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 1285 "frontend/parser.cpp"
    break;

  case 388: // expr_bool: expr_float ">" expr_int
#line 681 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 1291 "frontend/parser.cpp"
    break;

  case 389: // expr_bool: expr_str ">" expr_str
#line 682 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 1297 "frontend/parser.cpp"
    break;

  case 390: // expr_bool: expr_int "<" expr_int
#line 684 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 1303 "frontend/parser.cpp"
    break;

  case 391: // expr_bool: expr_int "<" expr_float
#line 685 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 1309 "frontend/parser.cpp"
    break;

  case 392: // expr_bool: expr_float "<" expr_float
#line 686 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 1315 "frontend/parser.cpp"
    break;

  case 393: // expr_bool: expr_float "<" expr_int
#line 687 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 1321 "frontend/parser.cpp"
    break;

  case 394: // expr_bool: expr_str "<" expr_str
#line 688 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 1327 "frontend/parser.cpp"
    break;

  case 395: // expr_bool: expr_int ">=" expr_int
#line 690 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 1333 "frontend/parser.cpp"
    break;

  case 396: // expr_bool: expr_int ">=" expr_float
#line 691 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 1339 "frontend/parser.cpp"
    break;

  case 397: // expr_bool: expr_float ">=" expr_float
#line 692 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 1345 "frontend/parser.cpp"
    break;

  case 398: // expr_bool: expr_float ">=" expr_int
#line 693 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 1351 "frontend/parser.cpp"
    break;

  case 399: // expr_bool: expr_str ">=" expr_str
#line 694 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 1357 "frontend/parser.cpp"
    break;

  case 400: // expr_bool: expr_int "<=" expr_int
#line 696 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 1363 "frontend/parser.cpp"
    break;

  case 401: // expr_bool: expr_int "<=" expr_float
#line 697 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 1369 "frontend/parser.cpp"
    break;

  case 402: // expr_bool: expr_float "<=" expr_float
#line 698 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 1375 "frontend/parser.cpp"
    break;

  case 403: // expr_bool: expr_float "<=" expr_int
#line 699 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 1381 "frontend/parser.cpp"
    break;

  case 404: // expr_bool: expr_str "<=" expr_str
#line 700 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 1387 "frontend/parser.cpp"
    break;

  case 405: // expr_bool: expr_str "in" expr_str
#line 702 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[0].value.as < std::string > ().find(yystack_[2].value.as < std::string > ()) != std::string::npos; }
#line 1393 "frontend/parser.cpp"
    break;


#line 1397 "frontend/parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -745;

  const short  Parser ::yytable_ninf_ = -435;

  const short
   Parser ::yypact_[] =
  {
    1904,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  1546,    35,
      49,  1322,   225,   -45,     1,    99,   218,   219,  2145,  1572,
    -745,  -745,   168,   187,    17,    37,    51,    52,   204,   253,
     310,   319,  1760,  -745,  -745,   327,   331,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,   343,   348,   360,  1752,  2212,  -745,
     669,  -745,   699,   755,  2312,  3111,   486,   572,   263,   271,
       6,   354,   148,  1863,   357,   669,   371,    33,   699,   755,
    2240,  1635,   712,   242,  1572,  -745,   148,   313,   145,   378,
     378,  -745,  -745,  -745,  1832,   193,  2959,  3145,  1042,  -745,
     225,   225,  -745,   344,  -745,   349,  1572,   315,  1572,   382,
    2752,  -745,  -745,   339,  -745,   366,  -745,   484,  -745,   653,
    -745,   667,  -745,   761,  -745,    22,   403,   336,    31,  1572,
    -745,  -745,  -745,  -745,  -745,  2041,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  1572,  1572,  1572,  1572,  1572,  1572,  1572,
    1572,  1572,  1572,  1572,  1572,  1572,  1572,   906,   934,  1572,
    1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,
    1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,
    1572,  -745,   934,  1572,  1572,  1572,  1572,  1572,  1572,  -745,
    1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,
    1572,  1572,  1572,   378,  1572,  1572,  1572,  1572,  1572,  1572,
    1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,
    1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,
    1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,
    1572,  1572,  1572,  1572,  1572,  1572,  -745,  -745,   176,    14,
    -745,   934,   405,  -745,  -745,  -745,  1572,  1572,  -745,  -745,
    -745,  -745,   171,    83,   401,  -745,  2390,  1029,   378,   378,
     378,   378,   378,   225,   225,   225,   225,   225,   378,   378,
     378,   378,   378,   378,  2936,  1284,   868,   552,  1322,   118,
     118,  1322,   378,   378,   378,   378,   378,   378,  1322,   378,
     378,   378,   378,   378,   378,  1322,  1322,  1322,  1322,  1322,
    1322,  1322,  1322,  1322,  1322,  1322,  1322,  1322,  3010,  -745,
     225,   225,   225,   225,   225,  1572,   346,   409,   383,   416,
    2041,  -745,  1935,   432,  1572,  -745,  2212,   402,  2312,  3111,
     486,   572,   438,  -745,   454,  -745,   462,  -745,   463,   459,
      46,   328,  -745,   350,    63,   469,  -745,   419,   487,   100,
    2312,  -745,  -745,  2144,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,   499,   464,
      56,   460,    16,   517,   914,   460,    16,   517,   914,   494,
     504,   490,   496,   494,   490,   496,   494,   490,   496,   494,
     496,  2287,   224,   284,  2982,  2148,   395,   535,  2768,   300,
    2612,   199,  2821,   519,  2908,  3122,  2850,  3060,  2879,  3088,
     429,  1104,   429,  1104,   798,   297,  -745,  -745,  1588,   592,
     161,  -745,   798,   297,  -745,  -745,  1588,   592,   161,  -745,
    1117,  1252,  1211,   506,  1117,  1252,  1211,   506,  1117,  1252,
    1211,   506,  1117,  1252,  1211,   506,   100,    65,   460,    16,
     460,    16,   494,   504,  2821,   746,   798,   297,   798,   297,
    2287,   224,   284,  2982,  2148,   395,   535,  2821,   746,   798,
    -745,   798,  -745,  2287,   224,   284,  2982,  2148,   395,   535,
    2821,   746,   798,  -745,   798,  -745,   460,   517,   914,   460,
     517,   914,   494,   490,   496,   494,   490,   496,   494,   490,
     496,  1486,   529,  2287,   224,   284,  2982,  2148,   395,   535,
    2821,   746,  2908,  3122,  2850,  3060,  2879,  3088,   429,  1104,
     429,  1104,   798,  1588,   592,   798,  1588,   592,  1117,  1252,
    1211,  1117,  1252,  1211,  1117,  1252,  1211,  1117,  1252,  1211,
     460,   517,   914,   460,   517,   914,   494,   490,   496,   494,
     490,   496,   494,   490,   496,   494,   490,   496,  2287,   224,
     284,  2982,  2148,   395,   535,  2821,   746,   798,  1588,   592,
     798,  1588,   592,  1117,  1252,  1211,  1117,  1252,  1211,  1117,
    1252,  1211,  1117,  1252,  1211,   512,  2287,   224,   284,  2982,
    2148,   395,   535,  2821,   746,   519,   798,   161,   798,   161,
    1117,   506,  1117,   506,  1117,   506,  1117,   506,  2287,   224,
     284,  2982,  2148,   395,   535,  2768,   300,  2612,   199,  2821,
     746,   798,  -745,   798,  -745,  -745,    55,   540,    15,   457,
     991,    81,  -745,   551,   525,   554,  -745,  1572,  -745,  -745,
     972,   999,   972,   999,   490,   529,   490,   529,   490,   529,
    1454,   780,  1081,   418,   418,   972,   999,   972,   999,   490,
     529,   490,   529,   490,   529,   490,   529,   130,  3033,  3152,
     616,   665,   556,  -745,  -745,   130,  3033,  3152,   616,   665,
    1387,  1426,  1387,  1426,  1387,  1426,  1387,  1426,  1387,  1426,
    1387,  1426,   130,  3033,  3152,   616,   665,  1387,  1426,  1387,
    1426,  1387,  1426,  1387,  1426,  1387,  1426,  1387,  1426,   130,
    3033,  3152,   616,   665,  1656,   613,  1116,  1116,  -745,  -745,
    -745,  -745,   130,  3033,  3152,   616,   665,   149,   244,  -745,
    -745,   160,   160,  -745,  -745,  -745,  -745,  -745,  2145,  1572,
    2145,  2010,   573,  1572,  -745,  1572,  -745,  -745,  -745,  -745,
     167,   167,  -745,   502,   566,   579,  -745,     7,   237,    21,
     543,     8,  -745,  1079,    89,  -745,   364,  -745,   545,  -745,
    -745,  1572,  -745,  -745,  -745,  1209,  -745,   784,   237,    27,
    -745,  -745,  -745,  1572,  -745,  -745,   354,   533,   588,  -745,
     597,  -745,   591,  -745,   589,  -745,   590,  -745,   167,   601,
    -745,   237,   784,   784,   605,  -745,   619,  -745,  1250,  -745,
    1349,   119,  1572,  -745,  -745,  -745,   237,   645,   647,   140,
    2145,  -745,  -745,  -745,  1572,  -745,  1572,  -745,   623,   543,
      20,  1572,  -745,  -745,   655,  -745,   677,  -745,  1515,   641,
    -745,  -745,  1572,   681,  2145,  -745,  -745,  -745,  -745,   605,
    -745,  -745,  -745,  -745,   680,   654,   689,  1572,  -745,  -745,
    -745,  2145,   690,  -745,  2145,  -745
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     7,   304,   318,   339,   366,   296,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      31,    32,     0,     0,   430,   431,   432,   433,     0,     0,
      94,     0,     0,     4,     8,     0,     0,    33,    13,    15,
      16,    14,    17,    18,     0,     0,     0,     0,    87,   276,
      86,   277,    88,    89,    90,    91,    92,    93,   435,   436,
       0,   296,    94,   283,   276,     0,   277,     0,     0,     0,
     282,     0,     0,     0,     0,   268,    94,   273,     0,     0,
       0,    95,   305,   319,     0,     0,     0,     0,     0,   368,
       0,     0,   307,     0,    29,    28,     0,     0,     0,     0,
       0,    26,    27,     0,    35,     0,   422,     0,   423,     0,
     424,     0,   425,     0,   426,     0,     0,     0,     0,     0,
     427,   104,   298,     1,     3,     0,     5,    12,    19,    10,
      11,     9,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,     0,     0,     0,     0,     0,     0,     0,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   428,   429,     0,    64,
     297,     0,   298,    96,   278,   279,     0,     0,   306,   320,
     340,   367,     0,     0,     0,   269,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   305,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,   413,   283,   420,   282,     0,
       0,     0,     0,   415,     0,   417,     0,   419,     0,     0,
       0,     0,   411,     0,     0,     0,   300,     0,     0,   106,
       0,     6,    83,    82,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    97,     0,    84,
       0,   136,   134,   131,   132,   144,   142,   139,   140,   118,
     117,   113,   114,   123,   121,   122,   128,   126,   127,   110,
     109,   267,   265,   266,   261,   262,   263,   264,   240,   239,
     243,   242,   237,   236,   215,   214,   221,   220,   218,   217,
     147,   146,   150,   149,   195,   193,   190,   191,   186,   187,
     188,   189,   212,   210,   207,   208,   203,   204,   205,   206,
     157,   154,   155,   156,   171,   168,   169,   170,   164,   161,
     162,   163,   178,   175,   176,   177,   107,     0,   135,   133,
     143,   141,   116,   115,   235,   228,   194,   192,   211,   209,
     259,   365,   248,   362,   363,   361,   364,   233,   226,   183,
     377,   200,   384,   260,   253,   254,   249,   250,   251,   252,
     234,   227,   185,   184,   202,   201,   129,   312,   338,   137,
     311,   335,   111,   308,   326,   119,   309,   329,   124,   310,
     332,     0,   323,   255,   350,   244,   347,   348,   346,   349,
     229,   222,   213,   315,   219,   317,   216,   316,   145,   313,
     148,   314,   179,   372,   373,   196,   379,   380,   151,   385,
     386,   165,   390,   391,   158,   395,   396,   172,   400,   401,
     130,   337,   336,   138,   334,   333,   112,   325,   324,   120,
     328,   327,   125,   331,   330,   108,   322,   321,   256,   355,
     245,   352,   353,   351,   354,   230,   223,   180,   375,   374,
     197,   382,   381,   152,   388,   387,   166,   393,   392,   159,
     398,   397,   173,   403,   402,     0,   257,   345,   246,   342,
     343,   341,   344,   231,   224,   405,   181,   376,   198,   383,
     153,   389,   167,   394,   160,   399,   174,   404,   258,   360,
     247,   357,   358,   356,   359,   238,   370,   241,   369,   232,
     225,   182,   371,   199,   378,   407,   434,     0,   408,     0,
       0,     0,   299,     0,     0,     0,   270,     0,   274,   271,
     312,   338,   311,   335,   308,   326,   309,   329,   310,   332,
     315,   317,   316,   313,   314,   337,   336,   334,   333,   325,
     324,   328,   327,   331,   330,   322,   321,   365,   362,   363,
     361,   364,     0,   377,   384,   350,   347,   348,   346,   349,
     372,   373,   379,   380,   385,   386,   390,   391,   395,   396,
     400,   401,   355,   352,   353,   351,   354,   375,   374,   382,
     381,   388,   387,   393,   392,   398,   397,   403,   402,   345,
     342,   343,   341,   344,   405,     0,   376,   383,   389,   394,
     399,   404,   360,   357,   358,   356,   359,   370,   369,   371,
     378,   312,   311,   308,   309,   310,    68,    30,     0,     0,
       0,     0,    22,     0,    67,     0,   412,   414,   416,   418,
       0,    48,    45,     0,     0,     0,    52,     0,     0,     0,
      60,     0,   284,     0,     0,   101,     0,   410,     0,   301,
      98,     0,   102,   100,    99,     0,   406,     0,     0,     0,
      66,    65,   280,     0,   272,   275,     0,    42,     0,    37,
      23,    24,     0,   421,     0,    49,     0,    46,    50,    64,
      57,     0,     0,     0,    59,   288,     0,   286,     0,   285,
       0,     0,     0,    85,   409,    55,     0,     0,     0,    44,
       0,    25,    38,    47,     0,    51,     0,    58,    61,    63,
       0,     0,   291,   290,     0,   289,     0,   287,     0,   302,
      56,   281,     0,     0,     0,    39,    36,    54,    53,     0,
      62,   294,   293,   292,     0,     0,     0,     0,    43,   295,
     303,     0,     0,    40,     0,    41
  };

  const short
   Parser ::yypgoto_[] =
  {
    -745,  -745,   -87,   -12,    18,  -744,  -688,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -729,  -745,
    -745,  -627,   -85,  -328,  -745,   586,   -50,  1106,  2507,   722,
     -68,  1315,   728,   163,   917,   888,  1540,   -58,  -104,  2279,
       0,   318,   570,  -745,   -25,  -745,  -106,  -212
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    31,    32,    33,    34,   102,   103,    35,    95,    36,
      37,    38,    39,    40,    41,   819,   845,    42,   754,   755,
      43,   759,   760,    44,    45,    46,   368,    47,    48,    49,
      78,    65,    51,   327,   171,    68,    69,   122,   348,    54,
     329,   330,   331,    58,   627,    59,   345,    60
  };

  const short
   Parser ::yytable_[] =
  {
      55,   332,   779,   334,   242,   336,   252,   338,    71,    55,
      83,    87,   756,   322,   800,   238,   238,   238,    55,    55,
     126,   794,   795,   629,   238,   339,   628,   172,   107,   238,
      93,   801,    55,   175,   815,   340,   101,   816,    74,     3,
       4,     5,     6,     7,     8,   346,     9,    75,   109,   751,
     787,    10,   789,     3,     4,   777,   630,   827,    79,    11,
     752,   802,   111,   113,    12,    80,   775,   802,   772,   825,
     347,   246,   840,   247,    55,   765,    94,   773,    12,   257,
      83,   239,   799,   804,   275,   108,   637,     3,     4,     5,
       6,     7,     8,   765,     9,   849,    55,   766,    55,    10,
      55,   807,   753,   745,   766,   110,   766,    11,    96,   147,
      76,   148,    12,   351,    23,    24,    25,    26,    27,   112,
     114,   626,   766,   120,    81,    55,     7,   672,   757,   761,
     808,   837,   846,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,   254,   374,
     378,   382,   385,   388,   390,   395,   858,   255,    76,   241,
     838,   118,   279,   280,   419,   427,   432,   436,   440,   444,
     751,    67,   221,   863,   635,   828,   865,   312,   313,   314,
     464,   306,   307,   636,   477,   638,   625,   119,   488,   491,
     494,   497,   500,   502,   507,   226,   227,   228,   229,   843,
     844,   524,   527,   530,   533,   536,   539,   542,   545,   548,
     551,   554,   557,   562,   278,   569,   572,   575,   578,   581,
     584,   231,   590,   753,   233,   279,   280,    97,    98,     3,
     612,   234,   235,   741,    90,    23,    24,    25,    26,    27,
      99,    91,   626,   105,    23,    24,    25,    26,    27,   181,
     100,   626,   251,    55,    12,   106,   182,   183,   641,   643,
     645,   647,   649,   230,   231,   232,   304,   233,   656,   658,
     660,   662,   664,   666,   234,   235,   306,   307,   669,   115,
     344,   677,   681,   683,   685,   687,   689,   691,   694,   698,
     700,   702,   704,   706,   708,   711,    87,    87,    87,    87,
      87,    87,    87,   724,    87,    87,    87,    87,   172,   185,
     126,   370,   173,   174,   175,    55,   186,   187,    56,   123,
      55,   117,    55,   118,    55,   233,    72,    56,   116,    88,
     127,   236,   234,   235,   128,   447,    56,    56,   758,   237,
       3,     4,     5,     6,     7,     8,   129,     9,   342,   119,
      56,   130,    10,   253,     3,     4,     5,     6,     7,     8,
      11,     9,   762,   131,   240,    12,    10,   244,     3,     4,
       5,     6,     7,     8,    11,     9,   809,   343,   120,    12,
      10,   245,     3,     4,   585,  -434,   315,    79,    11,   316,
     318,   763,    56,    12,    80,   320,    23,    24,    25,    26,
      27,   323,   276,   626,   631,   810,   221,    12,   324,   633,
     634,    76,   341,   639,    56,   632,    56,   761,    56,   738,
     223,   737,   756,   756,   739,    76,   740,   224,   225,   226,
     227,   228,   229,   310,   311,   312,   313,   314,   147,    76,
     148,   743,   745,    56,   149,   150,   151,   152,   153,   154,
     746,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,   747,   778,   170,   147,
     756,   148,   750,   396,   748,   749,   403,   151,   152,   153,
     154,   767,   420,   428,   433,   437,   441,   445,     3,     4,
       5,     6,     7,     8,   768,     9,   325,   221,   465,   170,
      10,   769,   478,   147,   771,   148,   764,   222,    11,   770,
     193,   223,   508,    12,   154,   172,   212,   221,   224,   225,
     226,   227,   228,   229,   774,    23,    24,    25,    26,    27,
     221,   563,   626,   170,   190,   191,   192,   193,   757,   757,
     591,   595,   597,   599,   601,   603,   605,   607,   613,   273,
     776,   224,   225,   226,   227,   228,   229,   231,   232,    76,
     233,   782,   251,   783,   786,   628,   784,   234,   235,   785,
      57,    56,   781,   303,   304,   305,   791,   796,    73,    57,
     797,    89,   798,   803,   306,   307,   757,   812,    57,    57,
     761,   830,   818,   230,   231,   232,   670,   233,   820,   678,
     821,   822,    57,   823,   234,   235,   695,   207,   208,   209,
     210,   211,   212,   712,   714,   716,   717,   718,   719,   720,
     721,   725,    88,    88,    88,    88,   217,   218,   219,   220,
      55,   832,   824,    56,   303,   304,   305,    55,    56,   793,
      56,   296,    56,   826,    57,   306,   307,   831,   297,   298,
     299,   300,   301,   302,   277,   841,   842,     3,     4,     5,
       6,     7,     8,   802,     9,   333,    57,   851,    57,    10,
      57,     3,     4,     5,     6,     7,     8,    11,     9,   335,
     172,   855,    12,    10,   173,   174,   175,   304,   305,   852,
     857,    11,   859,   347,   176,    57,    12,   306,   307,   861,
     864,   177,   178,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,   829,   352,
     180,   813,   250,   221,   181,   397,   399,   401,    76,   126,
      64,   182,   183,   222,   421,   429,    66,   223,    55,    55,
      55,    55,    76,    55,   224,   225,   226,   227,   228,   229,
     466,   860,   814,     0,   479,     0,   101,   172,   101,     0,
       0,   173,   174,   175,   509,     3,     4,     5,     6,     7,
       8,    55,     9,   337,     0,     0,   184,    10,   177,   178,
     185,     0,     0,   564,     0,    11,     0,   186,   187,     0,
      12,     0,   592,     0,     0,   310,   311,   312,   313,   314,
     614,   616,   618,     0,   622,   624,   263,   147,   265,   148,
     266,   267,    55,   149,   150,   151,   152,   153,   154,     0,
      55,     0,     0,    57,    55,     0,    55,     0,   162,   163,
       0,    55,   166,   167,   168,   169,    76,   170,   101,     0,
       0,     0,    55,     0,    55,     0,     0,     0,   671,     0,
       0,   679,    23,    24,    25,    26,    27,    55,   696,   626,
       0,    55,   101,     0,    55,   713,   715,   715,   715,   715,
     715,   715,   715,   726,   727,   728,   729,   730,   250,   101,
       0,     0,   101,     0,     0,    57,     0,     0,    52,   295,
      57,     0,    57,   296,    57,     0,     0,    52,     0,    85,
     297,   298,   299,   300,   301,   302,    52,    52,     0,     0,
       3,     4,     5,     6,     7,     8,   367,     9,     0,     0,
      52,     0,    10,     0,     0,     0,   806,     0,     0,   811,
      11,   209,   210,   211,   212,    12,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     9,   817,   121,    56,     0,
      10,     0,     0,     0,     0,    56,     0,     0,    11,     0,
       0,     0,    52,    12,     0,     0,     0,   179,     0,     0,
       0,   834,    85,   836,     0,   343,     0,     0,     0,   121,
       0,    76,   179,     0,    52,     0,    52,     0,    52,   260,
     261,   262,   193,   121,     0,     3,     4,     5,     6,     7,
       8,   854,     9,     0,   118,     0,     0,    10,     0,    76,
       0,     0,     0,    52,     0,    11,   270,   271,   272,   273,
      12,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,     0,     0,     0,   249,
       0,     0,     0,   392,   268,   269,   270,   271,   272,   273,
       0,     0,   416,   424,     0,     0,    56,    56,    56,    56,
       0,    56,     0,   295,     0,     0,    76,   296,   461,     0,
     470,   472,   474,     0,   297,   298,   299,   300,   301,   302,
       0,     0,   504,     3,     4,     5,     6,     7,     8,    56,
       9,   805,     0,     0,     0,    10,   310,   311,   312,   313,
     314,   559,     0,    11,     0,     0,     0,   263,    12,     0,
     587,   266,   267,     0,     0,    77,     0,     0,   609,   188,
     189,   190,   191,   192,   193,   104,   147,     0,   148,     0,
      56,     0,   149,   150,   151,   152,   153,   154,    56,     0,
       0,    52,    56,     0,    56,     0,     0,   162,   163,    56,
     299,   300,   301,   302,    76,     0,   170,     0,     0,     0,
      56,     0,    56,     0,     0,     0,   667,   673,   674,   675,
       0,     0,     0,     0,     0,    56,   692,     0,     0,    56,
      77,     0,    56,   709,    85,    85,    85,    85,    85,    85,
      85,   722,    85,    85,    85,    85,     0,     0,     0,     0,
      57,     0,   317,    52,   319,     0,     0,    57,    52,     0,
      52,     0,    52,     3,     4,     5,     6,     7,     8,     0,
       9,   342,     0,     0,     0,    10,   207,   208,   209,   210,
     211,   212,     0,    11,     0,     0,     0,     0,    12,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   369,     3,     4,     5,     6,     7,     8,
       0,     9,   833,     0,     0,     0,    10,   188,   189,   190,
     191,   192,   193,     0,    11,     0,     0,     0,     0,    12,
       0,     0,   199,   200,    76,     0,     0,     0,     0,   179,
       0,     0,     0,   179,   249,     0,     0,   179,     0,   268,
     269,   270,   271,   272,   273,   288,     0,     0,    57,    57,
      57,    57,     0,    57,     0,    50,   289,   290,   291,   292,
     293,   294,     0,     0,    50,    76,     3,     4,     5,     6,
       7,    84,   179,    50,    50,     0,     0,     0,    80,     0,
     179,    57,     0,     0,     0,     0,    11,    50,     0,     0,
       0,    12,     0,     3,     4,     5,     6,     7,     8,    77,
       9,   835,     0,     0,     0,    10,   179,     0,   179,     0,
     179,     0,   179,    11,   179,     0,   179,     0,    12,     0,
       0,     0,    57,     0,     0,   179,     0,     0,     0,    50,
      57,     0,     0,     0,    57,     0,    57,     0,   179,     0,
       0,    57,   258,   259,   260,   261,   262,   193,     0,     0,
       0,    50,    57,    50,    57,    50,     0,   266,   267,     0,
       0,   736,     0,     0,    76,     0,     0,    57,   179,     0,
     744,    57,     0,     0,    57,     0,     0,     0,     0,     0,
      50,   268,   269,   270,   271,   272,   273,     0,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,     0,   372,   376,   380,     0,     0,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   415,
     423,     0,     0,   179,   266,   267,     0,     0,   449,   451,
     453,   455,   457,   459,     0,     0,   468,     0,     0,     0,
     481,   258,   259,   260,   261,   262,   193,     0,     0,     0,
     511,   179,   263,   264,   265,     0,   266,   267,    52,     3,
       4,     5,     6,     7,     8,    52,     9,   853,     0,   566,
       0,    10,     0,     0,     0,     0,     0,   179,   594,    11,
      53,     0,     0,     0,    12,     0,     0,     0,   620,    53,
       3,     4,     5,     6,    61,     8,     0,     9,    53,    53,
       0,     0,    10,     0,     0,     0,     0,     0,    50,     0,
      11,     0,    53,     0,     0,    12,     3,     4,     5,     6,
       7,     8,     0,     9,     0,     0,     0,     0,    10,     0,
      76,     0,     0,     0,     0,     0,    11,     0,     0,     0,
       0,    12,     0,   188,   189,   190,   191,   192,   193,     0,
       0,     0,     0,     0,    53,     0,     0,     0,   199,   200,
       0,    62,   203,   204,   205,   206,    52,    52,    52,    52,
      50,    52,     0,     0,     0,    50,    53,    50,    53,    50,
      53,     0,     0,     0,     0,   249,     0,    76,     0,     0,
     207,   208,   209,   210,   211,   212,   213,     0,     0,    52,
     214,     0,     0,     0,     0,    53,     0,   215,   216,   217,
     218,   219,   220,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,   297,   298,
     299,   300,   301,   302,     0,   393,     0,     0,     0,     0,
      52,     0,     0,     0,   417,   425,     0,     0,    52,     0,
       0,     0,    52,     0,    52,     0,     0,     0,     0,    52,
     462,     0,     0,     0,   475,     0,   483,   485,     0,     0,
      52,     0,    52,     0,   505,     0,   780,     0,     0,     0,
       0,     0,     0,    77,     0,    52,     0,     0,     0,    52,
       0,     0,    52,   560,     0,   132,     0,     0,     0,     0,
     124,   125,   588,     2,     3,     4,     5,     6,     7,     8,
     610,     9,     0,     0,     0,     0,    10,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,     0,     0,    12,
       0,     0,     0,    53,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
       0,     0,     0,     0,     0,     0,    13,    14,    15,     0,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,     3,     4,     5,     6,
      61,    84,     0,     0,     0,   788,     0,     0,    80,   792,
       0,     0,     0,     0,     0,    53,    11,     0,     0,     0,
      53,    12,    53,     0,    53,     0,     0,     0,     0,     0,
       0,     0,   147,   243,   148,     0,     0,   369,   149,   150,
     151,   152,   153,   154,   155,   156,   157,     0,   158,   159,
     160,   161,     0,   162,   163,   164,   165,   166,   167,   168,
     169,     0,   170,     0,     1,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,   839,     0,
      10,     0,     0,     0,     0,     0,     0,     0,    11,     0,
     847,     0,   848,    12,     0,     0,   125,   850,     2,     3,
       4,     5,     6,     7,     8,    50,     9,     0,   856,   742,
       0,    10,    50,     0,     0,     0,     0,     0,     0,    11,
      13,    14,    15,   862,    12,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13,    14,    15,     0,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,   125,     0,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,   790,     0,    10,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,     0,     0,    12,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     0,     9,    50,    50,    50,    50,    10,    50,     0,
       0,     0,     0,     0,     0,    11,    13,    14,    15,     0,
      12,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,    14,    15,
       0,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,     0,     0,
       0,     0,     0,     0,     0,    50,     0,     0,     0,    50,
       0,    50,     0,     0,     0,     0,    50,     0,    99,     3,
       4,     5,     6,     7,     8,     0,     9,    50,   100,    50,
       0,    10,     0,   207,   208,   209,   210,   211,   212,    11,
      53,     0,    50,   214,    12,     0,    50,    53,     0,    50,
     215,   216,   217,   218,   219,   220,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,    13,    14,    15,     0,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,   147,     0,   148,     0,     0,     0,   149,   150,   151,
     152,   153,   154,   155,   156,   157,     0,   158,   159,   160,
     161,     0,   162,   163,   164,   165,   166,   167,   168,   169,
     248,   170,     0,     0,     0,   188,   189,   190,   191,   192,
     193,   194,     0,     0,     0,   195,   196,   197,   198,     0,
     199,   200,   201,   202,   203,   204,   205,   206,    53,    53,
      53,    53,     0,    53,     0,     0,     0,    70,     0,    82,
      86,    92,     0,     0,     0,     0,   147,     0,   148,     0,
       0,     0,   149,   150,   151,   152,   153,   154,     0,   156,
     157,    53,   158,   159,   160,   161,     0,   162,   163,   164,
     165,   166,   167,   168,   169,     0,   170,   188,   189,   190,
     191,   192,   193,   194,     0,     0,     0,   195,   196,   197,
     198,     0,   199,   200,   201,   202,   203,   204,   205,   206,
       0,     0,    53,     0,     0,     0,     0,     0,   256,    82,
      53,     0,     0,   274,    53,     0,    53,     0,     0,   308,
     309,    53,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,     0,    53,     0,   328,     0,   328,     0,
     328,     0,   328,     0,     0,     0,   328,    53,   350,     0,
     248,    53,     0,     0,    53,   258,   259,   260,   261,   262,
     193,     0,     0,     0,     0,     0,   263,   264,   265,     0,
     266,   267,     0,     0,     0,     0,     0,   328,   373,   377,
     381,   384,   387,   350,   394,   350,   350,   350,   405,   407,
     409,   411,   413,   418,   426,   431,   435,   439,   443,   350,
       0,   328,   350,   350,   350,   350,   350,   350,     0,   463,
     350,   350,   350,   476,   350,   350,   350,   487,   490,   493,
     496,   499,   501,   506,   350,   513,   515,   517,   519,   521,
     523,   526,   529,   532,   535,   538,   541,   544,   547,   550,
     553,   556,   561,   350,   568,   571,   574,   577,   580,   583,
     328,   589,   350,   350,   350,   350,   350,   350,   350,   611,
     350,   350,   350,   350,   350,    63,     0,     0,     0,     0,
     328,     0,     0,     0,     0,   328,   328,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   640,   642,   644,
     646,   648,   650,   651,   652,   653,   654,   655,   657,   659,
     661,   663,   665,     0,     0,     0,     0,   668,     0,     0,
     676,   680,   682,   684,   686,   688,   690,   693,   697,   699,
     701,   703,   705,   707,   710,    86,    86,    86,    86,    86,
      86,    86,   723,    86,    86,    86,    86,     0,     0,   731,
     732,   733,   734,   735,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   326,     0,   326,     0,   326,     0,
     326,   147,   328,   148,   326,     0,   349,   149,   150,   151,
     152,   153,   154,     0,   156,     0,     0,   158,   159,   160,
     161,     0,   162,   163,   164,   165,   166,   167,   168,   169,
       0,   170,     0,     0,     0,   326,   371,   375,   379,   383,
     386,   389,   391,   398,   400,   402,   404,   406,   408,   410,
     412,   414,   422,   430,   434,   438,   442,   446,     0,   326,
     448,   450,   452,   454,   456,   458,     0,   460,   467,   469,
     471,   473,   480,   482,   484,   486,   489,   492,   495,   498,
       0,   503,   510,   512,   514,   516,   518,   520,   522,   525,
     528,   531,   534,   537,   540,   543,   546,   549,   552,   555,
     558,   565,   567,   570,   573,   576,   579,   582,   326,   586,
     593,   596,   598,   600,   602,   604,   606,   608,   615,   617,
     619,   621,   623,     0,     0,     0,     0,     0,   326,     0,
       0,     0,     0,   326,   326,     2,     3,     4,     5,     6,
       7,     8,     0,     9,     0,     0,   321,     0,    10,     0,
       0,     0,     0,     0,     0,     0,    11,   147,     0,   148,
       0,    12,     0,   149,   150,   151,   152,   153,   154,     0,
       0,     0,     0,   158,   159,   160,   161,     0,   162,   163,
     164,   165,   166,   167,   168,   169,     0,   170,    13,    14,
      15,     0,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,     0,     0,
     147,     0,   148,     0,     0,     0,   149,   150,   151,   152,
     153,   154,     0,     0,     0,     0,     0,   159,   160,   161,
     326,   162,   163,   164,   165,   166,   167,   168,   169,   147,
     170,   148,     0,     0,     0,   149,   150,   151,   152,   153,
     154,     0,     0,     0,     0,     0,   159,     0,   161,     0,
     162,   163,   164,   165,   166,   167,   168,   169,   147,   170,
     148,     0,     0,     0,   149,   150,   151,   152,   153,   154,
       0,     0,     0,     0,     0,   159,     0,     0,     0,   162,
     163,   164,   165,   166,   167,   168,   169,   147,   170,   148,
       0,     0,     0,   149,   150,   151,   152,   153,   154,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   162,   163,
     164,   165,   166,   167,   168,   169,   248,   170,     0,     0,
       0,   258,   259,   260,   261,   262,   193,   281,     0,     0,
       0,     0,   263,   264,   265,     0,   266,   267,   282,   283,
     284,   285,   286,   287,   258,   259,   260,   261,   262,   193,
     281,     0,     0,     0,     0,   263,   264,   265,     0,   266,
     267,   282,   283,   284,   285,   286,   287,   188,   189,   190,
     191,   192,   193,     0,     0,     0,     0,   195,   196,   197,
     198,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     248,     0,     0,     0,   328,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,     0,   263,   264,   265,     0,
     266,   267,   328,     0,     0,   328,     0,     0,   258,   259,
     260,   261,   262,   193,   328,     0,     0,     0,     0,   263,
     264,   265,   328,   266,   267,   282,   283,   284,   285,   286,
     287,     0,     0,     0,     0,   188,   189,   190,   191,   192,
     193,     0,     0,     0,     0,     0,   196,   328,   198,   328,
     199,   200,   201,   202,   203,   204,   205,   206,     0,     0,
       0,     0,     0,   188,   189,   190,   191,   192,   193,     0,
       0,     0,     0,     0,   196,     0,     0,   328,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,     0,     0,     0,   214,   188,   189,   190,
     191,   192,   193,   215,   216,   217,   218,   219,   220,     0,
       0,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     268,   269,   270,   271,   272,   273,   288,   268,   269,   270,
     271,   272,   273,     0,     0,     0,     0,   289,   290,   291,
     292,   293,   294,     0,   289,   290,   291,   292,   293,   294,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   326,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     326,     0,     0,   326,     0,     0,     0,     0,     0,     0,
       0,     0,   326,     0,     0,     0,     0,     0,     0,     0,
     326,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   326,     0,   326,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   326
  };

  const short
   Parser ::yycheck_[] =
  {
       0,   107,   629,   109,    62,   111,    74,   113,     8,     9,
      10,    11,   340,   100,   758,     9,     9,     9,    18,    19,
      32,   750,   751,     9,     9,     3,   238,    11,    11,     9,
      75,    10,    32,    17,   778,    13,    18,    10,     3,     4,
       5,     6,     7,     8,     9,    14,    11,    12,    11,     3,
     738,    16,   740,     4,     5,    40,    42,   801,     9,    24,
      14,    40,    11,    11,    29,    16,    11,    40,    12,   798,
      39,    38,   816,    40,    74,    12,    75,    12,    29,    79,
      80,    75,    75,    75,    84,    68,     3,     4,     5,     6,
       7,     8,     9,    12,    11,    75,    96,    41,    98,    16,
     100,    12,    56,    40,    41,    68,    41,    24,     9,     9,
      75,    11,    29,   125,    68,    69,    70,    71,    72,    68,
      68,    75,    41,    68,    75,   125,     8,     9,   340,   341,
      41,    12,   820,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,     3,   149,
     150,   151,   152,   153,   154,   155,   844,    12,    75,    11,
      41,    13,    32,    33,   164,   165,   166,   167,   168,   169,
       3,     8,    11,   861,     3,   802,   864,    17,    18,    19,
     180,    32,    33,    12,   184,   253,    10,    39,   188,   189,
     190,   191,   192,   193,   194,    34,    35,    36,    37,    59,
      60,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,    21,   215,   216,   217,   218,   219,
     220,    22,   222,    56,    25,    32,    33,     9,     9,     4,
     230,    32,    33,   320,     9,    68,    69,    70,    71,    72,
       3,    16,    75,    75,    68,    69,    70,    71,    72,    25,
      13,    75,    10,   253,    29,    68,    32,    33,   258,   259,
     260,   261,   262,    21,    22,    23,    22,    25,   268,   269,
     270,   271,   272,   273,    32,    33,    32,    33,   278,    75,
     117,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,    11,    25,
     322,   148,    15,    16,    17,   315,    32,    33,     0,     0,
     320,    11,   322,    13,   324,    25,     8,     9,    75,    11,
       3,    68,    32,    33,     3,   172,    18,    19,    10,    68,
       4,     5,     6,     7,     8,     9,     3,    11,    12,    39,
      32,     3,    16,    40,     4,     5,     6,     7,     8,     9,
      24,    11,    12,     3,    10,    29,    16,    10,     4,     5,
       6,     7,     8,     9,    24,    11,    12,    41,    68,    29,
      16,    10,     4,     5,   221,    75,    42,     9,    24,    40,
      75,    41,    74,    29,    16,    13,    68,    69,    70,    71,
      72,    62,    84,    75,   241,    41,    11,    29,    42,   246,
     247,    75,     9,    12,    96,    10,    98,   629,   100,    10,
      25,    75,   750,   751,    41,    75,    10,    32,    33,    34,
      35,    36,    37,    15,    16,    17,    18,    19,     9,    75,
      11,     9,    40,   125,    15,    16,    17,    18,    19,    20,
      12,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    12,    10,    39,     9,
     798,    11,    13,   155,    12,    12,   158,    17,    18,    19,
      20,    12,   164,   165,   166,   167,   168,   169,     4,     5,
       6,     7,     8,     9,    75,    11,    12,    11,   180,    39,
      16,    14,   184,     9,    40,    11,   343,    21,    24,    10,
      20,    25,   194,    29,    20,    11,    20,    11,    32,    33,
      34,    35,    36,    37,    12,    68,    69,    70,    71,    72,
      11,   213,    75,    39,    17,    18,    19,    20,   750,   751,
     222,   223,   224,   225,   226,   227,   228,   229,   230,    20,
      10,    32,    33,    34,    35,    36,    37,    22,    23,    75,
      25,    10,    10,    38,     8,   777,    12,    32,    33,   637,
       0,   253,   630,    21,    22,    23,     3,    75,     8,     9,
      14,    11,     3,    40,    32,    33,   798,    42,    18,    19,
     802,   803,    59,    21,    22,    23,   278,    25,    10,   281,
       3,    10,    32,    14,    32,    33,   288,    15,    16,    17,
      18,    19,    20,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,    34,    35,    36,    37,
     630,    12,    42,   315,    21,    22,    23,   637,   320,   745,
     322,    25,   324,    42,    74,    32,    33,    42,    32,    33,
      34,    35,    36,    37,    84,    10,     9,     4,     5,     6,
       7,     8,     9,    40,    11,    12,    96,    12,    98,    16,
     100,     4,     5,     6,     7,     8,     9,    24,    11,    12,
      11,    40,    29,    16,    15,    16,    17,    22,    23,    12,
       9,    24,    12,    39,    25,   125,    29,    32,    33,    10,
      10,    32,    33,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   803,   133,
      21,   771,    10,    11,    25,   155,   156,   157,    75,   741,
       8,    32,    33,    21,   164,   165,     8,    25,   738,   739,
     740,   741,    75,   743,    32,    33,    34,    35,    36,    37,
     180,   855,   777,    -1,   184,    -1,   738,    11,   740,    -1,
      -1,    15,    16,    17,   194,     4,     5,     6,     7,     8,
       9,   771,    11,    12,    -1,    -1,    21,    16,    32,    33,
      25,    -1,    -1,   213,    -1,    24,    -1,    32,    33,    -1,
      29,    -1,   222,    -1,    -1,    15,    16,    17,    18,    19,
     230,   231,   232,    -1,   234,   235,    26,     9,    28,    11,
      30,    31,   812,    15,    16,    17,    18,    19,    20,    -1,
     820,    -1,    -1,   253,   824,    -1,   826,    -1,    30,    31,
      -1,   831,    34,    35,    36,    37,    75,    39,   820,    -1,
      -1,    -1,   842,    -1,   844,    -1,    -1,    -1,   278,    -1,
      -1,   281,    68,    69,    70,    71,    72,   857,   288,    75,
      -1,   861,   844,    -1,   864,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,    10,   861,
      -1,    -1,   864,    -1,    -1,   315,    -1,    -1,     0,    21,
     320,    -1,   322,    25,   324,    -1,    -1,     9,    -1,    11,
      32,    33,    34,    35,    36,    37,    18,    19,    -1,    -1,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      32,    -1,    16,    -1,    -1,    -1,   763,    -1,    -1,   766,
      24,    17,    18,    19,    20,    29,    -1,    -1,     4,     5,
       6,     7,     8,     9,    -1,    11,   783,    30,   630,    -1,
      16,    -1,    -1,    -1,    -1,   637,    -1,    -1,    24,    -1,
      -1,    -1,    74,    29,    -1,    -1,    -1,    50,    -1,    -1,
      -1,   808,    84,   810,    -1,    41,    -1,    -1,    -1,    62,
      -1,    75,    65,    -1,    96,    -1,    98,    -1,   100,    17,
      18,    19,    20,    76,    -1,     4,     5,     6,     7,     8,
       9,   838,    11,    -1,    13,    -1,    -1,    16,    -1,    75,
      -1,    -1,    -1,   125,    -1,    24,    17,    18,    19,    20,
      29,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,    10,
      -1,    -1,    -1,   155,    15,    16,    17,    18,    19,    20,
      -1,    -1,   164,   165,    -1,    -1,   738,   739,   740,   741,
      -1,   743,    -1,    21,    -1,    -1,    75,    25,   180,    -1,
     182,   183,   184,    -1,    32,    33,    34,    35,    36,    37,
      -1,    -1,   194,     4,     5,     6,     7,     8,     9,   771,
      11,    12,    -1,    -1,    -1,    16,    15,    16,    17,    18,
      19,   213,    -1,    24,    -1,    -1,    -1,    26,    29,    -1,
     222,    30,    31,    -1,    -1,     9,    -1,    -1,   230,    15,
      16,    17,    18,    19,    20,    19,     9,    -1,    11,    -1,
     812,    -1,    15,    16,    17,    18,    19,    20,   820,    -1,
      -1,   253,   824,    -1,   826,    -1,    -1,    30,    31,   831,
      34,    35,    36,    37,    75,    -1,    39,    -1,    -1,    -1,
     842,    -1,   844,    -1,    -1,    -1,   278,   279,   280,   281,
      -1,    -1,    -1,    -1,    -1,   857,   288,    -1,    -1,   861,
      74,    -1,   864,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,    -1,    -1,    -1,    -1,
     630,    -1,    96,   315,    98,    -1,    -1,   637,   320,    -1,
     322,    -1,   324,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    -1,    -1,    -1,    16,    15,    16,    17,    18,
      19,    20,    -1,    24,    -1,    -1,    -1,    -1,    29,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    -1,    -1,    16,    15,    16,    17,
      18,    19,    20,    -1,    24,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    30,    31,    75,    -1,    -1,    -1,    -1,   372,
      -1,    -1,    -1,   376,    10,    -1,    -1,   380,    -1,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,   738,   739,
     740,   741,    -1,   743,    -1,     0,    32,    33,    34,    35,
      36,    37,    -1,    -1,     9,    75,     4,     5,     6,     7,
       8,     9,   415,    18,    19,    -1,    -1,    -1,    16,    -1,
     423,   771,    -1,    -1,    -1,    -1,    24,    32,    -1,    -1,
      -1,    29,    -1,     4,     5,     6,     7,     8,     9,   253,
      11,    12,    -1,    -1,    -1,    16,   449,    -1,   451,    -1,
     453,    -1,   455,    24,   457,    -1,   459,    -1,    29,    -1,
      -1,    -1,   812,    -1,    -1,   468,    -1,    -1,    -1,    74,
     820,    -1,    -1,    -1,   824,    -1,   826,    -1,   481,    -1,
      -1,   831,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    96,   842,    98,   844,   100,    -1,    30,    31,    -1,
      -1,   315,    -1,    -1,    75,    -1,    -1,   857,   511,    -1,
     324,   861,    -1,    -1,   864,    -1,    -1,    -1,    -1,    -1,
     125,    15,    16,    17,    18,    19,    20,    -1,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,    -1,   149,   150,   151,    -1,    -1,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,   164,
     165,    -1,    -1,   566,    30,    31,    -1,    -1,   173,   174,
     175,   176,   177,   178,    -1,    -1,   181,    -1,    -1,    -1,
     185,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
     195,   594,    26,    27,    28,    -1,    30,    31,   630,     4,
       5,     6,     7,     8,     9,   637,    11,    12,    -1,   214,
      -1,    16,    -1,    -1,    -1,    -1,    -1,   620,   223,    24,
       0,    -1,    -1,    -1,    29,    -1,    -1,    -1,   233,     9,
       4,     5,     6,     7,     8,     9,    -1,    11,    18,    19,
      -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,   253,    -1,
      24,    -1,    32,    -1,    -1,    29,     4,     5,     6,     7,
       8,     9,    -1,    11,    -1,    -1,    -1,    -1,    16,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    29,    -1,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    30,    31,
      -1,    75,    34,    35,    36,    37,   738,   739,   740,   741,
     315,   743,    -1,    -1,    -1,   320,    96,   322,    98,   324,
     100,    -1,    -1,    -1,    -1,    10,    -1,    75,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,   771,
      25,    -1,    -1,    -1,    -1,   125,    -1,    32,    33,    34,
      35,    36,    37,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    32,    33,
      34,    35,    36,    37,    -1,   155,    -1,    -1,    -1,    -1,
     812,    -1,    -1,    -1,   164,   165,    -1,    -1,   820,    -1,
      -1,    -1,   824,    -1,   826,    -1,    -1,    -1,    -1,   831,
     180,    -1,    -1,    -1,   184,    -1,   186,   187,    -1,    -1,
     842,    -1,   844,    -1,   194,    -1,   630,    -1,    -1,    -1,
      -1,    -1,    -1,   637,    -1,   857,    -1,    -1,    -1,   861,
      -1,    -1,   864,   213,    -1,     3,    -1,    -1,    -1,    -1,
       0,     1,   222,     3,     4,     5,     6,     7,     8,     9,
     230,    11,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,   253,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,
      -1,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,     4,     5,     6,     7,
       8,     9,    -1,    -1,    -1,   739,    -1,    -1,    16,   743,
      -1,    -1,    -1,    -1,    -1,   315,    24,    -1,    -1,    -1,
     320,    29,   322,    -1,   324,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,   771,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    -1,     0,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    -1,    -1,   812,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
     824,    -1,   826,    29,    -1,    -1,     1,   831,     3,     4,
       5,     6,     7,     8,     9,   630,    11,    -1,   842,    14,
      -1,    16,   637,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      56,    57,    58,   857,    29,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    -1,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    -1,    14,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,   738,   739,   740,   741,    16,   743,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    56,    57,    58,    -1,
      29,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,   771,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      -1,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   812,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   820,    -1,    -1,    -1,   824,
      -1,   826,    -1,    -1,    -1,    -1,   831,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,   842,    13,   844,
      -1,    16,    -1,    15,    16,    17,    18,    19,    20,    24,
     630,    -1,   857,    25,    29,    -1,   861,   637,    -1,   864,
      32,    33,    34,    35,    36,    37,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    56,    57,    58,    -1,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     9,    -1,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    25,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      10,    39,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    25,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,   738,   739,
     740,   741,    -1,   743,    -1,    -1,    -1,     8,    -1,    10,
      11,    12,    -1,    -1,    -1,    -1,     9,    -1,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,   771,    25,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    39,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    25,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,   812,    -1,    -1,    -1,    -1,    -1,    79,    80,
     820,    -1,    -1,    84,   824,    -1,   826,    -1,    -1,    90,
      91,   831,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   842,    -1,   844,    -1,   107,    -1,   109,    -1,
     111,    -1,   113,    -1,    -1,    -1,   117,   857,   119,    -1,
      10,   861,    -1,    -1,   864,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
      -1,   172,   173,   174,   175,   176,   177,   178,    -1,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,     8,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,   246,   247,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,    -1,    -1,    -1,    -1,   278,    -1,    -1,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,    -1,    -1,   310,
     311,   312,   313,   314,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,    -1,   109,    -1,   111,    -1,
     113,     9,   343,    11,   117,    -1,   119,    15,    16,    17,
      18,    19,    20,    -1,    22,    -1,    -1,    25,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    39,    -1,    -1,    -1,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,    -1,   172,
     173,   174,   175,   176,   177,   178,    -1,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
      -1,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,    -1,    -1,    -1,    -1,    -1,   241,    -1,
      -1,    -1,    -1,   246,   247,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    -1,    -1,    14,    -1,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,     9,    -1,    11,
      -1,    29,    -1,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    39,    56,    57,
      58,    -1,    -1,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    -1,    -1,
       9,    -1,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
     343,    30,    31,    32,    33,    34,    35,    36,    37,     9,
      39,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,     9,    39,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,     9,    39,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    10,    39,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    26,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      10,    -1,    -1,    -1,   745,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    -1,
      30,    31,   763,    -1,    -1,   766,    -1,    -1,    15,    16,
      17,    18,    19,    20,   775,    -1,    -1,    -1,    -1,    26,
      27,    28,   783,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    26,   808,    28,   810,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,   838,    30,    31,
      32,    33,    34,    35,    36,    37,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    25,    15,    16,    17,
      18,    19,    20,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      15,    16,    17,    18,    19,    20,    21,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    37,    -1,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   745,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     763,    -1,    -1,   766,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   775,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     783,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   808,    -1,   810,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   838
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,     0,     3,     4,     5,     6,     7,     8,     9,    11,
      16,    24,    29,    56,    57,    58,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    78,    79,    80,    81,    84,    86,    87,    88,    89,
      90,    91,    94,    97,   100,   101,   102,   104,   105,   106,
     108,   109,   112,   113,   116,   117,   118,   119,   120,   122,
     124,     8,    75,   105,   106,   108,   109,   110,   112,   113,
     116,   117,   118,   119,     3,    12,    75,   104,   107,     9,
      16,    75,   116,   117,     9,   112,   116,   117,   118,   119,
       9,    16,   116,    75,    75,    85,     9,     9,     9,     3,
      13,    81,    82,    83,   104,    75,    68,    11,    68,    11,
      68,    11,    68,    11,    68,    75,    75,    11,    13,    39,
      68,   111,   114,     0,     0,     1,    80,     3,     3,     3,
       3,     3,     3,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     9,    11,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    25,    26,
      27,    28,    30,    31,    32,    33,    34,    35,    36,    37,
      39,   111,    11,    15,    16,    17,    25,    32,    33,   111,
      21,    25,    32,    33,    21,    25,    32,    33,    15,    16,
      17,    18,    19,    20,    21,    25,    26,    27,    28,    30,
      31,    32,    33,    34,    35,    36,    37,    15,    16,    17,
      18,    19,    20,    21,    25,    32,    33,    34,    35,    36,
      37,    11,    21,    25,    32,    33,    34,    35,    36,    37,
      21,    22,    23,    25,    32,    33,    68,    68,     9,    75,
      10,    11,   114,    10,    10,    10,    38,    40,    10,    10,
      10,    10,   107,    40,     3,    12,   116,   117,    15,    16,
      17,    18,    19,    26,    27,    28,    30,    31,    15,    16,
      17,    18,    19,    20,   116,   117,   118,   119,    21,    32,
      33,    21,    32,    33,    34,    35,    36,    37,    21,    32,
      33,    34,    35,    36,    37,    21,    25,    32,    33,    34,
      35,    36,    37,    21,    22,    23,    32,    33,   116,   116,
      15,    16,    17,    18,    19,    42,    40,   104,    75,   104,
      13,    14,    79,    62,    42,    12,   105,   110,   116,   117,
     118,   119,   123,    12,   123,    12,   123,    12,   123,     3,
      13,     9,    12,    41,   110,   123,    14,    39,   115,   105,
     116,    80,   102,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,    10,   103,   104,
     110,   105,   108,   116,   117,   105,   108,   116,   117,   105,
     108,   116,   117,   105,   116,   117,   105,   116,   117,   105,
     117,   105,   112,   113,   116,   117,   118,   119,   105,   119,
     105,   119,   105,   118,   105,   116,   105,   116,   105,   116,
     105,   116,   105,   116,   105,   108,   112,   113,   116,   117,
     118,   119,   105,   108,   112,   113,   116,   117,   118,   119,
     105,   116,   117,   118,   105,   116,   117,   118,   105,   116,
     117,   118,   105,   116,   117,   118,   105,   110,   105,   108,
     105,   108,   105,   108,   105,   108,   105,   108,   105,   108,
     105,   112,   113,   116,   117,   118,   119,   105,   108,   105,
     112,   105,   112,   105,   112,   113,   116,   117,   118,   119,
     105,   108,   105,   113,   105,   113,   105,   116,   117,   105,
     116,   117,   105,   116,   117,   105,   116,   117,   105,   116,
     117,   116,   117,   105,   112,   113,   116,   117,   118,   119,
     105,   108,   105,   116,   105,   116,   105,   116,   105,   116,
     105,   116,   105,   116,   117,   105,   116,   117,   105,   116,
     117,   105,   116,   117,   105,   116,   117,   105,   116,   117,
     105,   116,   117,   105,   116,   117,   105,   116,   117,   105,
     116,   117,   105,   116,   117,   105,   116,   117,   105,   112,
     113,   116,   117,   118,   119,   105,   108,   105,   116,   117,
     105,   116,   117,   105,   116,   117,   105,   116,   117,   105,
     116,   117,   105,   116,   117,   110,   105,   112,   113,   116,
     117,   118,   119,   105,   108,   118,   105,   118,   105,   118,
     105,   118,   105,   118,   105,   118,   105,   118,   105,   112,
     113,   116,   117,   118,   119,   105,   119,   105,   119,   105,
     108,   105,   119,   105,   119,    10,    75,   121,   124,     9,
      42,   110,    10,   110,   110,     3,    12,     3,   107,    12,
     116,   117,   116,   117,   116,   117,   116,   117,   116,   117,
     116,   116,   116,   116,   116,   116,   117,   116,   117,   116,
     117,   116,   117,   116,   117,   116,   117,   112,   116,   117,
     118,   119,     9,   112,   112,   112,   116,   117,   118,   119,
     116,   117,   116,   117,   116,   117,   116,   117,   116,   117,
     116,   117,   112,   116,   117,   118,   119,   116,   117,   116,
     117,   116,   117,   116,   117,   116,   117,   116,   117,   112,
     116,   117,   118,   119,   118,   119,   118,   118,   118,   118,
     118,   118,   112,   116,   117,   118,   119,   119,   119,   119,
     119,   116,   116,   116,   116,   116,   104,    75,    10,    41,
      10,    79,    14,     9,   104,    40,    12,    12,    12,    12,
      13,     3,    14,    56,    95,    96,   100,   124,    10,    98,
      99,   124,    12,    41,   110,    12,    41,    12,    75,    14,
      10,    40,    12,    12,    12,    11,    10,    40,    10,    98,
     104,   114,    10,    38,    12,   107,     8,    83,   104,    83,
      14,     3,   104,   123,    95,    95,    75,    14,     3,    75,
      82,    10,    40,    40,    75,    12,   110,    12,    41,    12,
      41,   110,    42,   103,   121,    82,    10,   110,    59,    92,
      10,     3,    10,    14,    42,    95,    42,    82,    98,    99,
     124,    42,    12,    12,   110,    12,   110,    12,    41,   104,
      82,    10,     9,    59,    60,    93,    83,   104,   104,    75,
     104,    12,    12,    12,   110,    40,   104,     9,    83,    12,
     115,    10,   104,    83,    10,    83
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
     124,   124,   124,   124,   124,   124,   124
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
       1,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1
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
       0,   179,   179,   180,   182,   183,   184,   188,   189,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   206,   207,   208,   209,   210,   213,   214,   218,   220,
     221,   225,   226,   227,   229,   230,   234,   238,   241,   245,
     247,   248,   249,   251,   252,   256,   257,   258,   260,   261,
     262,   263,   265,   266,   267,   271,   272,   273,   274,   276,
     277,   278,   280,   281,   285,   289,   290,   291,   292,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   314,   315,   319,   320,   321,   322,
     323,   324,   325,   326,   329,   330,   331,   333,   334,   336,
     337,   338,   339,   341,   342,   343,   345,   346,   348,   349,
     350,   352,   353,   354,   355,   356,   357,   358,   359,   361,
     362,   363,   364,   365,   367,   368,   369,   370,   371,   373,
     374,   375,   376,   377,   378,   379,   380,   382,   383,   384,
     385,   386,   387,   388,   389,   391,   392,   393,   395,   396,
     397,   399,   400,   401,   402,   403,   404,   405,   407,   408,
     409,   410,   411,   412,   413,   415,   416,   417,   418,   419,
     420,   421,   423,   424,   425,   426,   427,   428,   429,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   467,   468,   469,   471,   472,   473,   475,
     476,   477,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   496,   497,
     498,   500,   501,   502,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   531,   532,
     533,   534,   535,   537,   538,   539,   543,   544,   545,   546,
     548,   549,   551,   552,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   569,   570,   574,   575,
     577,   578,   580,   581,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   626,
     627,   628,   629,   630,   631,   632,   633,   634,   635,   636,
     637,   638,   639,   640,   641,   642,   643,   644,   645,   646,
     647,   648,   649,   650,   651,   652,   656,   657,   658,   659,
     660,   662,   663,   664,   665,   666,   667,   668,   670,   671,
     672,   673,   674,   675,   676,   678,   679,   680,   681,   682,
     684,   685,   686,   687,   688,   690,   691,   692,   693,   694,
     696,   697,   698,   699,   700,   702,   706,   707,   709,   710,
     714,   715,   716,   717,   718,   719,   720,   721,   722,   723,
     725,   726,   730,   731,   732,   733,   734,   735,   736,   737,
     738,   739,   740,   741,   742,   743,   744
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
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76
    };
    // Last valid token kind.
    const int code_max = 331;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 13 "frontend/parser.yy"
} //  ptc 
#line 2993 "frontend/parser.cpp"

#line 747 "frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    std::cerr << scanner->loc->begin.line << ":" << scanner->loc->begin.column << ": " << err_message << std::endl;
}
