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
#line 37 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"


    #include <cmath>
    #include <sstream>
    // Include compiler to use error
    #include "scanner.hpp"

    // Set correct token method
    #undef yylex
    #define yylex scanner->yylex

#line 58 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"


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

#line 13 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
namespace  ptc  {
#line 151 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"

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
  case 262: // expr_int: "int"
#line 551 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 787 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 263: // expr_int: "-" expr_int
#line 552 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 793 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 264: // expr_int: "(" expr_int ")"
#line 553 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 799 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 265: // expr_int: "~" expr_int
#line 554 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 805 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 266: // expr_int: expr_int "*" expr_int
#line 555 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 811 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 267: // expr_int: expr_int "/" expr_int
#line 556 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 817 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 268: // expr_int: expr_int "%" expr_int
#line 557 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 823 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 269: // expr_int: expr_int "-" expr_int
#line 558 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 829 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 270: // expr_int: expr_int "+" expr_int
#line 559 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 835 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 271: // expr_int: expr_int "<<" expr_int
#line 560 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 841 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 272: // expr_int: expr_int ">>" expr_int
#line 561 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 847 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 273: // expr_int: expr_int "&" expr_int
#line 562 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 853 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 274: // expr_int: expr_int "^" expr_int
#line 563 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 859 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 275: // expr_int: expr_int "|" expr_int
#line 564 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 865 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 276: // expr_float: "float"
#line 568 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 871 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 277: // expr_float: "-" expr_float
#line 569 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 877 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 278: // expr_float: "(" expr_float ")"
#line 570 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 883 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 279: // expr_float: expr_float "**" expr_float
#line 571 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 889 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 280: // expr_float: expr_float "**" expr_int
#line 572 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 895 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 281: // expr_float: expr_int "**" expr_float
#line 573 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 901 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 282: // expr_float: expr_float "*" expr_float
#line 574 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 907 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 283: // expr_float: expr_float "*" expr_int
#line 575 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 913 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 284: // expr_float: expr_int "*" expr_float
#line 576 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 919 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 285: // expr_float: expr_float "/" expr_float
#line 577 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 925 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 286: // expr_float: expr_float "/" expr_int
#line 578 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 931 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 287: // expr_float: expr_int "/" expr_float
#line 579 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 937 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 288: // expr_float: expr_float "%" expr_float
#line 580 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 943 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 289: // expr_float: expr_float "%" expr_int
#line 581 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 949 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 290: // expr_float: expr_int "%" expr_float
#line 582 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 955 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 291: // expr_float: expr_float "-" expr_float
#line 583 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 961 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 292: // expr_float: expr_float "-" expr_int
#line 584 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 967 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 293: // expr_float: expr_int "-" expr_float
#line 585 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 973 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 294: // expr_float: expr_float "+" expr_float
#line 586 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 979 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 295: // expr_float: expr_float "+" expr_int
#line 587 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 985 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 296: // expr_float: expr_int "+" expr_float
#line 588 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 991 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 297: // expr_str: "string"
#line 592 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 997 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 298: // expr_str: "(" expr_str ")"
#line 593 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 1003 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 299: // expr_str: expr_str "++" expr_str
#line 594 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 1009 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 300: // expr_str: expr_str "++" expr_int
#line 595 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 1015 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 301: // expr_str: expr_str "++" expr_float
#line 596 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 1021 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 302: // expr_str: expr_str "++" expr_bool
#line 597 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1027 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 303: // expr_str: expr_str "++" expr_none
#line 598 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 1033 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 304: // expr_str: expr_int "++" expr_str
#line 599 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 1039 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 305: // expr_str: expr_int "++" expr_int
#line 600 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 1045 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 306: // expr_str: expr_int "++" expr_float
#line 601 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 1051 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 307: // expr_str: expr_int "++" expr_bool
#line 602 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1057 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 308: // expr_str: expr_int "++" expr_none
#line 603 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 1063 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 309: // expr_str: expr_float "++" expr_str
#line 604 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 1069 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 310: // expr_str: expr_float "++" expr_int
#line 605 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 1075 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 311: // expr_str: expr_float "++" expr_float
#line 606 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 1081 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 312: // expr_str: expr_float "++" expr_bool
#line 607 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1087 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 313: // expr_str: expr_float "++" expr_none
#line 608 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 1093 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 314: // expr_str: expr_bool "++" expr_str
#line 609 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 1099 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 315: // expr_str: expr_bool "++" expr_int
#line 610 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 1105 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 316: // expr_str: expr_bool "++" expr_float
#line 611 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 1111 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 317: // expr_str: expr_bool "++" expr_bool
#line 612 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1117 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 318: // expr_str: expr_bool "++" expr_none
#line 613 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 1123 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 319: // expr_str: expr_none "++" expr_str
#line 614 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 1129 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 320: // expr_str: expr_none "++" expr_int
#line 615 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 1135 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 321: // expr_str: expr_none "++" expr_float
#line 616 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 1141 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 322: // expr_str: expr_none "++" expr_bool
#line 617 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1147 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 323: // expr_str: expr_none "++" expr_none
#line 618 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 1153 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 324: // expr_bool: "bool"
#line 622 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 1159 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 325: // expr_bool: "(" expr_bool ")"
#line 623 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 1165 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 326: // expr_bool: "not" expr_bool
#line 624 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 1171 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 327: // expr_bool: expr_bool "or" expr_bool
#line 625 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 1177 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 328: // expr_bool: expr_bool "and" expr_bool
#line 626 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 1183 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 329: // expr_bool: expr_bool "==" expr_bool
#line 628 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 1189 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 330: // expr_bool: expr_int "==" expr_int
#line 629 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 1195 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 331: // expr_bool: expr_int "==" expr_float
#line 630 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 1201 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 332: // expr_bool: expr_float "==" expr_float
#line 631 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 1207 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 333: // expr_bool: expr_float "==" expr_int
#line 632 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 1213 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 334: // expr_bool: expr_str "==" expr_str
#line 633 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 1219 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 335: // expr_bool: expr_none "==" expr_none
#line 634 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 1225 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 336: // expr_bool: expr_bool "!=" expr_bool
#line 636 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 1231 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 337: // expr_bool: expr_int "!=" expr_int
#line 637 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 1237 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 338: // expr_bool: expr_int "!=" expr_float
#line 638 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 1243 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 339: // expr_bool: expr_float "!=" expr_float
#line 639 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 1249 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 340: // expr_bool: expr_float "!=" expr_int
#line 640 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 1255 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 341: // expr_bool: expr_str "!=" expr_str
#line 641 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 1261 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 342: // expr_bool: expr_none "!=" expr_none
#line 642 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 1267 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 343: // expr_bool: expr_int ">" expr_int
#line 644 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 1273 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 344: // expr_bool: expr_int ">" expr_float
#line 645 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 1279 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 345: // expr_bool: expr_float ">" expr_float
#line 646 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 1285 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 346: // expr_bool: expr_float ">" expr_int
#line 647 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 1291 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 347: // expr_bool: expr_str ">" expr_str
#line 648 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 1297 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 348: // expr_bool: expr_int "<" expr_int
#line 650 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 1303 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 349: // expr_bool: expr_int "<" expr_float
#line 651 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 1309 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 350: // expr_bool: expr_float "<" expr_float
#line 652 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 1315 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 351: // expr_bool: expr_float "<" expr_int
#line 653 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 1321 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 352: // expr_bool: expr_str "<" expr_str
#line 654 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 1327 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 353: // expr_bool: expr_int ">=" expr_int
#line 656 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 1333 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 354: // expr_bool: expr_int ">=" expr_float
#line 657 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 1339 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 355: // expr_bool: expr_float ">=" expr_float
#line 658 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 1345 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 356: // expr_bool: expr_float ">=" expr_int
#line 659 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 1351 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 357: // expr_bool: expr_str ">=" expr_str
#line 660 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 1357 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 358: // expr_bool: expr_int "<=" expr_int
#line 662 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 1363 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 359: // expr_bool: expr_int "<=" expr_float
#line 663 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 1369 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 360: // expr_bool: expr_float "<=" expr_float
#line 664 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 1375 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 361: // expr_bool: expr_float "<=" expr_int
#line 665 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 1381 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 362: // expr_bool: expr_str "<=" expr_str
#line 666 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 1387 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;


#line 1391 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -681;

  const short  Parser ::yytable_ninf_ = -392;

  const short
   Parser ::yypact_[] =
  {
     823,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  1159,    38,
      47,   690,   233,   -59,   -45,    27,    39,    50,  1963,  1212,
    -681,  -681,    -4,     9,    16,    17,    18,    49,    28,    32,
      89,   120,   793,  -681,  -681,   124,   148,  -681,  -681,  -681,
    -681,  -681,  -681,  -681,   158,   163,   202,  -681,  1415,   204,
    1847,  -681,  -681,  -681,   319,   137,  2127,  1791,  1004,   127,
     144,   164,    -3,   237,  1080,   206,   113,    70,   264,   171,
    1463,  1650,   218,   533,  1212,  -681,   113,     1,   243,   153,
     206,   281,     1,  -681,  -681,  2173,  2387,   368,  -681,   233,
     233,  -681,   283,  -681,   250,  1212,   257,  1212,   323,  1993,
    -681,  -681,   292,  -681,   314,  -681,   410,  -681,   529,  -681,
     696,  -681,   914,  -681,    52,   372,   940,    80,  -681,   338,
    -681,  -681,  -681,  2066,  -681,  -681,  -681,  -681,  -681,  -681,
    1126,   307,  1212,  1212,  1212,  1212,  1212,  1212,  1212,  1212,
    1212,  1212,  1212,  1212,  1212,  1212,  -681,   652,   652,   652,
     652,   652,   652,   652,   652,   652,   652,   652,   652,   652,
     652,   652,   652,   652,   652,   652,   652,   652,   652,   652,
     652,   652,   652,   652,   652,   652,   652,   652,   652,   652,
     206,   652,   652,   652,   652,   652,   652,   652,   652,   652,
     652,   652,   652,   652,   652,   652,   652,   652,   652,   652,
     652,   652,   652,   652,   652,   652,   652,   652,   652,   652,
     652,   652,   652,   652,   652,   652,   652,   652,   652,   652,
     652,   652,  -681,  -681,    21,    24,  -681,  1212,   376,  -681,
    -681,   690,   221,   221,  -681,   206,   206,   206,   206,   206,
     690,   233,   233,   233,   233,   233,   206,   206,   206,   206,
     206,   206,  -681,   206,   206,   206,   206,   206,   206,   690,
     206,   206,   206,   206,   206,   206,  -681,   690,   690,   690,
     690,   690,   690,   690,  -681,   690,   690,   690,   690,   690,
     179,   190,   378,  -681,   713,   471,  1227,  -681,   233,   233,
     233,   233,   233,  1212,   324,   384,   357,   397,  2066,  -681,
    1054,   400,  1212,  -681,   370,   399,  -681,   401,  -681,   408,
    -681,   411,   422,   115,   105,  -681,    61,   412,  -681,   361,
     429,   307,  -681,  -681,   435,   407,   439,  -681,  -681,  -681,
    -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,
    -681,  -681,   743,   494,   319,   137,   611,   647,  1004,   127,
     494,   611,   647,   431,   433,   434,   431,   433,   434,   431,
     433,   434,   431,  2127,   434,  2081,   213,   228,  2196,  2410,
     808,   405,  2219,  1791,   313,  2150,   279,  2243,   837,  1174,
    2381,  2289,  2312,  2335,  2358,  1027,  1056,  1027,  1056,  2421,
    -681,  -681,  2444,  2473,   293,  -681,  2421,  -681,  -681,  2444,
    2473,   293,  -681,   942,  1814,  1128,  -681,   942,  1814,  1128,
    -681,   942,  1814,  1128,  -681,   942,  1814,  1128,  -681,  2081,
     213,   228,  2196,  2410,   808,   405,  2243,  2421,  -681,  2421,
    -681,  2081,   213,   228,  2196,  2410,   808,   405,  2421,  -681,
    2421,  -681,   494,   611,   647,   494,   611,   647,   431,   433,
     434,   431,   433,   434,   431,   433,   434,  1417,   460,  2081,
     213,   228,  2196,  2410,   808,   405,  2243,  1174,  2381,  2289,
    2312,  2335,  2358,  1027,  1056,  1027,  1056,  2421,  2444,  2473,
    2421,  2444,  2473,   942,  1814,  1128,   942,  1814,  1128,   942,
    1814,  1128,   942,  1814,  1128,   494,   611,   647,   494,   611,
     647,   431,   433,   434,   431,   433,   434,   431,   433,   434,
     431,   433,   434,  2081,   213,   228,  2196,  2410,   808,   405,
    2243,  2421,  2444,  2473,  2421,  2444,  2473,   942,  1814,  1128,
     942,  1814,  1128,   942,  1814,  1128,   942,  1814,  1128,  2081,
     213,   228,  2196,  2410,   808,   405,  2243,  2421,   293,  2421,
     293,   942,  -681,   942,  -681,   942,  -681,   942,  -681,  2081,
     213,   228,  2196,  2410,   808,   405,  2219,   313,  2150,   279,
    2243,  2421,  -681,  2421,  -681,  -681,    57,   445,    29,   216,
     310,   437,  -681,   231,  2266,  2450,  1144,   156,   474,  -681,
    -681,   744,   796,   744,   796,   433,   460,   433,   460,   433,
     460,   231,  2266,  2450,  1144,   156,   570,   759,  2485,   444,
     444,  2502,  1232,  2502,  1232,  2502,  1232,  2502,  1232,  2502,
    1232,  2502,  1232,   744,   796,   744,   796,   433,   460,   433,
     460,   433,   460,   433,   460,   231,  2266,  2450,  1144,   156,
    2502,  1232,  2502,  1232,  2502,  1232,  2502,  1232,  2502,  1232,
    2502,  1232,   231,  2266,  2450,  1144,   156,   801,   351,   801,
    -681,  -681,  -681,  -681,   231,  2266,  2450,  1144,   156,   317,
     191,  -681,  -681,   487,  -681,  1212,  -681,  -681,   278,   278,
    -681,  -681,  -681,  -681,  -681,  1963,   900,  1963,  1648,   480,
    1212,  -681,  1212,  -681,  -681,  -681,  -681,   238,   238,  -681,
     430,   493,   505,  -681,     3,   118,    13,   469,     8,   281,
    -681,   475,  -681,   439,  -681,  1212,   940,  -681,   542,   118,
      48,  -681,  -681,   237,  -681,  -681,   457,   511,   560,  -681,
     517,  -681,   512,  -681,   518,  -681,   482,  -681,   238,   484,
    -681,   118,   542,   542,   497,  -681,  1212,  -681,  -681,  -681,
     118,   535,   316,  1963,  1963,  -681,  -681,  -681,  1212,  -681,
    1212,  -681,   507,   469,    12,  1212,   509,  -681,  1212,   541,
    1963,  -681,  -681,  -681,  -681,  -681,   497,  -681,   513,   547,
    1212,  -681,  -681,  1963,   549,  -681,  1963,  -681
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     7,   262,   276,   297,   324,   254,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      31,    32,     0,     0,   387,   388,   389,   390,     0,     0,
      91,     0,     0,     4,     8,     0,     0,    33,    14,    16,
      17,    15,    18,    19,     0,     0,     0,    92,   101,     0,
      97,    98,   252,    96,    99,   100,   240,   241,   242,   243,
     392,   393,     0,   254,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,   244,    91,   101,   249,     0,
       0,    91,   102,   263,   277,     0,     0,     0,   326,     0,
       0,   265,     0,    29,    28,     0,     0,     0,     0,     0,
      26,    27,     0,    35,     0,   379,     0,   380,     0,   381,
       0,   382,     0,   383,     0,     0,     0,     0,   384,    93,
     256,     1,     3,     0,     5,    13,    20,    11,    12,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   385,   386,     0,    65,   255,     0,     0,   103,
     253,     0,     0,     0,   264,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   278,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   298,     0,     0,     0,
       0,     0,     0,     0,   325,     0,     0,     0,     0,     0,
       0,     0,     0,   245,     0,     0,     0,   263,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,   370,   377,     0,   372,     0,   374,     0,
     376,     0,     0,     0,     0,   368,     0,     0,   258,     0,
       0,     0,     6,    85,     0,    87,    95,    84,    83,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,     0,   126,     0,     0,   124,   125,     0,     0,
     131,   129,   130,   111,   109,   110,   116,   114,   115,   121,
     119,   120,   106,     0,   105,   239,   237,   238,   233,   234,
     235,   236,   212,     0,   211,   215,   214,   209,   208,   196,
     195,   202,   201,   199,   198,   134,   133,   137,   136,   179,
     177,   178,   173,   174,   175,   176,   193,   191,   192,   187,
     188,   189,   190,   144,   141,   142,   143,   158,   155,   156,
     157,   151,   148,   149,   150,   165,   162,   163,   164,   231,
     323,   220,   320,   321,   319,   322,   207,   170,   335,   184,
     342,   232,   225,   226,   221,   222,   223,   224,   172,   171,
     186,   185,   122,   270,   296,   127,   269,   293,   107,   266,
     284,   112,   267,   287,   117,   268,   290,     0,   281,   227,
     308,   216,   305,   306,   304,   307,   203,   194,   273,   200,
     275,   197,   274,   132,   271,   135,   272,   166,   330,   331,
     180,   337,   338,   138,   343,   344,   152,   348,   349,   145,
     353,   354,   159,   358,   359,   123,   295,   294,   128,   292,
     291,   108,   283,   282,   113,   286,   285,   118,   289,   288,
     104,   280,   279,   228,   313,   217,   310,   311,   309,   312,
     204,   167,   333,   332,   181,   340,   339,   139,   346,   345,
     153,   351,   350,   146,   356,   355,   160,   361,   360,   229,
     303,   218,   300,   301,   299,   302,   205,   168,   334,   182,
     341,   140,   347,   154,   352,   147,   357,   161,   362,   230,
     318,   219,   315,   316,   314,   317,   210,   328,   213,   327,
     206,   169,   329,   183,   336,   364,   391,     0,   365,     0,
       0,     0,   257,   323,   320,   321,   319,   322,     0,   335,
     342,   270,   296,   269,   293,   266,   284,   267,   287,   268,
     290,   308,   305,   306,   304,   307,   273,   275,   274,   271,
     272,   330,   331,   337,   338,   343,   344,   348,   349,   353,
     354,   358,   359,   295,   294,   292,   291,   283,   282,   286,
     285,   289,   288,   280,   279,   313,   310,   311,   309,   312,
     333,   332,   340,   339,   346,   345,   351,   350,   356,   355,
     361,   360,   303,   300,   301,   299,   302,   334,     0,   341,
     347,   352,   357,   362,   318,   315,   316,   314,   317,   328,
     327,   329,   336,     0,   246,     0,   250,   247,   270,   269,
     266,   267,   268,    69,    30,     0,     0,     0,     0,    22,
       0,    68,     0,   369,   371,   373,   375,     0,    49,    46,
       0,     0,     0,    53,     0,     0,     0,    61,     0,    89,
     367,     0,   259,    94,    86,     0,     0,   363,     0,     0,
       0,    67,    66,     0,   248,   251,    43,     0,     0,    38,
      23,    24,     0,   378,     0,    50,     0,    47,    51,    65,
      58,     0,     0,     0,    60,    90,     0,    88,   366,    56,
       0,     0,    45,     0,     0,    25,    39,    48,     0,    52,
       0,    59,    62,    64,     0,     0,   260,    57,     0,     0,
       0,    40,    36,    37,    55,    54,     0,    63,     0,     0,
       0,    44,   261,     0,     0,    41,     0,    42
  };

  const short
   Parser ::yypgoto_[] =
  {
    -681,  -681,   -96,   -18,     5,  -680,  -672,  -681,  -681,  -681,
    -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -663,  -681,
    -681,  -575,  -183,  -306,  -681,   432,  -681,  -153,  -146,   248,
     334,  1744,  -681,   564,   -72,  -681,   225,   510,   -65,  -210,
    1150,  1366,  1582,     0,  -681,  -145,  -681,   -86,  -167
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    31,    32,    33,   100,   101,   102,    35,    94,    36,
      37,    38,    39,    40,    41,   752,   771,    42,   701,   702,
      43,   706,   707,    44,    45,    46,    47,   324,   119,    77,
      49,    50,    51,    52,    79,    53,   344,   345,   120,   320,
      56,    57,    58,   349,    60,   577,    61,   317,    62
  };

  const short
   Parser ::yytable_[] =
  {
      59,   228,   280,   300,   720,    34,   224,   703,    73,    59,
     130,    88,   224,   726,   124,   729,    92,   224,    59,    59,
     305,   224,   307,   741,   309,   740,   311,   106,   108,   110,
      93,   575,    59,   579,   734,   735,    95,    34,   224,   749,
     131,    74,     3,     4,     5,     6,     7,     8,    96,     9,
      75,     3,     4,   742,    10,   312,    80,   578,   750,    97,
     112,   761,    11,    65,    73,   313,   580,    12,   716,   718,
     767,   104,   225,   709,    59,   759,    12,   105,   739,   130,
     229,   772,   773,   744,   107,   109,   111,   776,   742,    23,
      24,    25,    26,    27,   318,    59,   576,    59,   781,    59,
     116,   692,   117,   114,    34,   322,    59,   115,    59,   131,
      59,   785,    59,    76,   787,   705,    59,   113,   698,   319,
     121,    98,    81,    59,   227,   118,   117,   125,    34,   699,
      59,    99,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,   704,   708,   216,   217,
     218,   126,   219,   371,   374,   376,   282,   118,   172,   220,
     221,   127,   395,   402,  -391,   283,   128,   762,   425,   173,
     174,   700,   437,    23,    24,    25,    26,    27,   276,   277,
     576,   465,   673,    23,    24,    25,    26,    27,   278,   279,
     576,   674,   231,   675,     3,     4,     5,     6,     7,     8,
     519,     9,   688,   232,   233,   129,    10,   146,   545,   676,
       3,     4,   222,   276,    11,    80,   565,   567,   569,    12,
     572,   574,    65,   278,   279,    54,   719,    59,   266,     7,
     588,   587,   223,    69,    54,    12,    69,     3,   169,   267,
     605,   698,    89,    54,    54,   170,   171,   226,    48,    90,
     268,   269,   270,   271,   272,   273,    67,    54,    82,   639,
     173,   174,    12,   232,   233,    76,    48,   656,   658,   658,
     658,   658,   658,   658,   230,   668,   669,   670,   671,   672,
      48,    59,   124,   281,    23,    24,    25,    26,    27,    69,
     294,   576,   227,    59,   700,   290,   291,   292,    59,    54,
      59,   217,    59,    34,   219,    34,    23,    24,    25,    26,
      27,   220,   221,   576,     3,     4,     5,     6,     7,     8,
      54,     9,    54,   117,    54,   293,    10,   212,   213,   214,
     215,    54,   296,    54,    11,    54,   298,    54,   219,    12,
     168,    54,    73,    78,   169,   220,   221,    48,    54,   278,
     279,   170,   171,   103,   301,    54,   302,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    48,   275,   276,   277,   769,   770,   321,   366,   326,
      48,   314,    81,   278,   279,    76,   582,   390,   397,   267,
     677,   703,   703,   420,   685,   428,   430,   432,   686,   684,
     268,   269,   270,   271,   272,   273,   460,   687,    78,   690,
     692,   693,   708,   694,     3,     4,     5,     6,     7,     8,
     695,     9,   303,   696,   710,   514,    10,   217,   218,   295,
     219,   297,   703,   540,    11,   697,   711,   220,   221,    12,
     304,   560,   304,   712,   304,   714,   304,   715,   130,   709,
     316,   152,    54,   180,   199,   717,   583,   589,   590,   288,
     289,   290,   291,   292,   325,   601,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     258,   252,   723,   731,   635,    76,   253,   254,   255,   256,
     257,   258,   652,    69,    69,    69,    69,    69,    69,   724,
     664,    69,    69,    69,    69,   736,    54,   737,   738,   743,
      55,   149,   150,   151,   152,   722,   751,   746,    54,    55,
     755,   753,   756,    54,   758,    54,   760,    54,    55,    55,
     704,   704,   757,     3,     4,     5,     6,     7,     8,   765,
       9,   306,    55,   274,   768,    10,    48,   742,    48,   778,
     780,   578,   319,    11,   275,   276,   277,   783,    12,   786,
     763,   581,   747,   745,   327,   278,   279,    69,   782,   713,
     754,   704,    68,   748,     0,   708,   764,     0,     0,     0,
      59,   267,     0,     0,    55,   288,   289,   290,   291,   292,
      67,     0,   268,   269,   270,   271,   272,   273,     0,     0,
     244,   245,     0,   725,    76,    55,   733,    55,     0,    55,
      23,    24,    25,    26,    27,    78,    55,   576,    55,     0,
      55,     0,    55,     0,     0,     0,    55,   683,   177,   178,
     179,   180,     0,    55,     0,     0,   691,     0,     0,     0,
      55,     0,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,     3,     4,     5,     6,
       7,   342,     0,   367,   196,   197,   198,   199,    10,     0,
     124,     0,   391,   398,     0,    59,    11,     0,   421,     0,
       0,    12,   433,   439,   441,    59,   658,    59,    59,     0,
      59,   461,    59,    34,     3,     4,     5,     6,     7,    64,
       3,     4,     5,     6,     7,     8,    65,     9,   308,     0,
     515,     0,    10,     0,    11,    59,    59,     0,   541,    12,
      11,     0,     0,   234,     0,    12,   561,    76,   235,   236,
     237,   238,   239,   180,     0,     0,     0,    55,     0,   241,
     242,   243,     0,   244,   245,     0,    59,     3,     4,     5,
       6,    63,    64,    59,    59,     0,     0,     0,    59,    65,
      59,   237,   238,   239,   180,    59,     0,    11,    59,     0,
      59,    76,    12,     0,   288,   289,   290,   291,   292,     0,
      59,     0,     0,    59,     0,   241,    59,   243,     0,   244,
     245,    55,     0,   122,   123,     0,     2,     3,     4,     5,
       6,     7,     8,    55,     9,    54,     0,     0,    55,    10,
      55,     0,    55,   255,   256,   257,   258,    11,    66,     0,
       0,     0,    12,     1,     0,     0,     2,     3,     4,     5,
       6,     7,     8,   209,     9,   270,   271,   272,   273,    10,
     210,   211,   212,   213,   214,   215,     0,    11,     0,    13,
      14,    15,    12,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,   210,
     211,   212,   213,   214,   215,     0,     0,     0,     0,    13,
      14,    15,     0,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,     0,
      54,     0,     0,     0,     3,     4,     5,     6,     7,    64,
      54,    69,    54,    54,   721,    54,    65,    54,     3,     4,
       5,     6,     7,     8,    11,     9,   310,     0,     0,    12,
      10,     0,     0,    48,     0,    48,    48,     0,    11,     0,
      54,    54,     0,    12,     3,     4,     5,     6,     7,     8,
       0,     9,   315,     0,     0,     0,    10,   147,   148,   149,
     150,   151,   152,     0,    11,     0,     0,     0,     0,    12,
       0,    54,   160,   161,     0,   727,     0,     0,    54,    54,
       0,     0,     0,    54,     0,    54,     0,     0,     0,    76,
      54,     0,     0,    54,     0,    54,     0,     0,     0,     0,
       0,    48,    48,     0,     0,    54,     0,     0,    54,    78,
       0,    54,     0,     0,     0,    76,     0,     0,    48,     0,
       0,     0,     0,     0,   732,   208,   304,     0,     0,   209,
       0,    48,     0,     0,    48,     0,   210,   211,   212,   213,
     214,   215,   147,   148,   149,   150,   151,   152,     0,   325,
     304,     0,     0,     0,     0,   123,     0,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,   689,     0,
      10,   175,   176,   177,   178,   179,   180,     0,    11,     0,
     766,     0,     0,    12,     3,     4,     5,     6,    63,    64,
      55,     0,   774,     0,   775,     0,    65,     0,     0,   777,
       0,     0,   779,     0,    11,     0,     0,     0,     0,    12,
      13,    14,    15,     0,   784,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
       3,     4,     5,     6,     7,     8,   323,     9,     0,     0,
       0,     0,    10,   194,   195,   196,   197,   198,   199,     0,
      11,     0,     0,     0,     0,    12,     0,     0,    70,     0,
      83,    85,    91,     3,     4,     5,     6,    63,    64,     0,
       9,     0,     0,     0,     0,    65,   268,   269,   270,   271,
     272,   273,     0,    11,     0,    55,     0,     0,    12,   147,
     148,   149,   150,   151,   152,    55,     0,    55,    55,     0,
      55,    76,    55,     0,   160,   161,   162,   163,   164,   165,
     166,   167,     0,     0,    70,    83,     3,     4,     5,     6,
       7,     8,     0,     9,     0,    55,    55,     0,    10,     0,
     284,     0,     0,     0,    66,     0,    11,   234,     0,   286,
     287,    12,   288,   289,   290,   291,   292,   253,   254,   255,
     256,   257,   258,   241,   242,   243,    55,   244,   245,     0,
       0,     0,     0,    55,    55,     0,     0,     0,    55,     0,
      55,     0,     0,     0,     0,    55,     0,     0,    55,     0,
      55,     0,     0,     0,     0,     0,     0,    76,     0,     0,
      55,     0,     0,    55,     0,     0,    55,   346,   351,   354,
     357,   360,   363,   368,   363,   363,   363,   380,   382,   384,
     386,   388,   392,   399,   404,   408,   412,   416,   422,   363,
     363,   363,   434,   363,   363,   443,   446,   449,   452,   455,
     457,   462,   363,   468,   470,   472,   474,   476,   478,   481,
     484,   487,   490,   493,   496,   499,   502,   505,   508,   511,
     516,   363,   522,   525,   528,   531,   534,   537,   542,   363,
     363,   363,   363,   363,   363,   363,   562,   363,   363,   363,
     363,   363,     0,     0,    71,     0,    84,    86,     0,     0,
       0,   584,     0,     0,     0,   591,   593,   595,   597,   599,
     602,   606,   607,   608,   609,   610,   611,   613,   615,   617,
     619,   621,     0,   623,   625,   627,   629,   631,   633,   636,
     640,   642,   644,   646,   648,   650,     0,   653,    85,    85,
      85,    85,    85,    85,   130,   665,    85,    85,    85,    85,
      71,    84,   235,   236,   237,   238,   239,   180,   678,   679,
     680,   681,   682,   241,   242,   243,   285,   244,   245,     0,
       0,     0,     0,     0,   131,     0,     0,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,     0,     0,   234,     0,     0,     0,     0,   235,   236,
     237,   238,   239,   180,   240,     0,     0,     0,     0,   241,
     242,   243,    70,   244,   245,   246,   247,   248,   249,   250,
     251,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   347,   352,   355,   358,   361,   364,   369,
     373,   373,   373,   373,   373,   373,   373,   373,   393,   400,
     405,   409,   413,   417,   423,   373,   373,   373,   435,   373,
     373,   444,   447,   450,   453,   456,   458,   463,   373,   373,
     373,   373,   373,   373,   479,   482,   485,   488,   491,   494,
     497,   500,   503,   506,   509,   512,   517,   373,   523,   526,
     529,   532,   535,   538,   543,   373,   373,   373,   373,   373,
     373,   373,   563,   373,   373,   373,   373,   373,     0,     0,
      72,     0,     0,    87,     0,     0,     0,   585,     0,     0,
       0,   592,   594,   596,   598,   600,   603,     0,     0,     0,
       0,     0,   612,   614,   616,   618,   620,   622,     0,   624,
     626,   628,   630,   632,   634,   637,   641,   643,   645,   647,
     649,   651,     0,   654,    86,    86,    86,    86,    86,    86,
       0,   666,    86,    86,    86,    86,    72,     0,     0,   123,
       0,     2,     3,     4,     5,     6,     7,     8,     0,     9,
     252,     0,   730,     0,    10,   253,   254,   255,   256,   257,
     258,   259,    11,     0,     0,     0,     0,    12,     0,     0,
       0,     0,   260,   261,   262,   263,   264,   265,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,    14,    15,     0,    71,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,     0,     0,     0,     0,     0,   348,
     348,   348,   348,   348,   348,   370,   348,   348,   378,   348,
     348,   348,   348,   348,   394,   401,   406,   410,   414,   418,
     424,   348,   348,   348,   436,   348,   348,   348,   348,   348,
     348,   348,     0,   464,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   518,   348,   348,   348,   348,   348,   348,   348,
     544,   348,   548,   550,   552,   554,   556,   558,   564,   348,
     348,   348,   348,   348,     0,     0,   194,   195,   196,   197,
     198,   199,   200,   586,     0,     0,   201,     0,     0,     0,
       0,     0,   604,   202,   203,   204,   205,   206,   207,   175,
     176,   177,   178,   179,   180,     0,    85,     0,     0,     0,
       0,   638,     0,     0,   186,   187,     0,     0,     0,   655,
     657,   659,   660,   661,   662,   663,     0,   667,    87,    87,
      87,    87,   147,   148,   149,   150,   151,   152,   153,   154,
     155,     0,   156,   157,   158,   159,     0,   160,   161,   162,
     163,   164,   165,   166,   167,     0,     0,     0,     0,     0,
       0,   343,   350,   353,   356,   359,   362,   365,   372,   375,
     377,   379,   381,   383,   385,   387,   389,   396,   403,   407,
     411,   415,   419,   426,   427,   429,   431,   438,   440,   442,
     445,   448,   451,   454,    72,   459,   466,   467,   469,   471,
     473,   475,   477,   480,   483,   486,   489,   492,   495,   498,
     501,   504,   507,   510,   513,   520,   521,   524,   527,   530,
     533,   536,   539,   546,   547,   549,   551,   553,   555,   557,
     559,   566,   568,   570,   571,   573,    98,     3,     4,     5,
       6,     7,     8,     0,     9,     0,    99,     0,     0,    10,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     0,
       0,     0,    12,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,   299,     0,    10,
       0,     0,     0,     0,     0,     0,     0,    11,     0,    13,
      14,    15,    12,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
      14,    15,    86,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,     0,    10,     0,     0,     0,     0,     0,     0,     0,
      11,     0,     0,     0,     0,    12,   147,   148,   149,   150,
     151,   152,     0,   154,   155,     0,   156,   157,   158,   159,
       0,   160,   161,   162,   163,   164,   165,   166,   167,     0,
       0,     0,    13,    14,    15,     0,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,   175,   176,   177,   178,   179,   180,   181,     0,
       0,     0,   182,   183,   184,   185,     0,   186,   187,   188,
     189,   190,   191,   192,   193,   147,   148,   149,   150,   151,
     152,     0,   154,     0,     0,   156,   157,   158,   159,     0,
     160,   161,   162,   163,   164,   165,   166,   167,   235,   236,
     237,   238,   239,   180,   240,     0,     0,     0,     0,   241,
     242,   243,     0,   244,   245,   246,   247,   248,   249,   250,
     251,   175,   176,   177,   178,   179,   180,     0,     0,     0,
       0,   182,   183,   184,   185,     0,   186,   187,   188,   189,
     190,   191,   192,   193,   147,   148,   149,   150,   151,   152,
       0,     0,     0,     0,   156,   157,   158,   159,     0,   160,
     161,   162,   163,   164,   165,   166,   167,     0,   147,   148,
     149,   150,   151,   152,     0,     0,     0,     0,   728,   157,
     158,   159,     0,   160,   161,   162,   163,   164,   165,   166,
     167,   235,   236,   237,   238,   239,   180,     0,     0,     0,
       0,     0,   241,   242,   243,     0,   244,   245,   246,   247,
     248,   249,   250,   251,   147,   148,   149,   150,   151,   152,
       0,     0,     0,     0,     0,   157,     0,   159,     0,   160,
     161,   162,   163,   164,   165,   166,   167,   175,   176,   177,
     178,   179,   180,     0,     0,     0,     0,     0,   183,     0,
     185,     0,   186,   187,   188,   189,   190,   191,   192,   193,
     147,   148,   149,   150,   151,   152,     0,     0,     0,     0,
       0,   157,     0,     0,     0,   160,   161,   162,   163,   164,
     165,   166,   167,   175,   176,   177,   178,   179,   180,     0,
       0,     0,     0,     0,   183,     0,     0,     0,   186,   187,
     188,   189,   190,   191,   192,   193,   175,   176,   177,   178,
     179,   180,   253,   254,   255,   256,   257,   258,   259,     0,
       0,   186,   187,   188,   189,   190,   191,   192,   193,   260,
     261,   262,   263,   264,   265,   194,   195,   196,   197,   198,
     199,     0,     0,     0,     0,   201,   147,   148,   149,   150,
     151,   152,   202,   203,   204,   205,   206,   207,     0,     0,
       0,   160,   161,     0,     0,   164,   165,   166,   167,   175,
     176,   177,   178,   179,   180,   253,   254,   255,   256,   257,
     258,     0,     0,     0,   186,   187,     0,     0,   190,   191,
     192,   193,   260,   261,   262,   263,   264,   265,   194,   195,
     196,   197,   198,   199,     0,     0,     0,     0,     0,     0,
     288,   289,   290,   291,   292,     0,     0,   204,   205,   206,
     207,   241,     0,     0,     0,   244,   245,   235,   236,   237,
     238,   239,   180,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   244,   245
  };

  const short
   Parser ::yycheck_[] =
  {
       0,    66,    74,    99,   579,     0,     9,   313,     8,     9,
       9,    11,     9,   685,    32,   687,    75,     9,    18,    19,
     106,     9,   108,    10,   110,   705,   112,    11,    11,    11,
      75,    10,    32,     9,   697,   698,     9,    32,     9,   719,
      39,     3,     4,     5,     6,     7,     8,     9,     9,    11,
      12,     4,     5,    40,    16,     3,     9,   224,    10,     9,
      11,   741,    24,    16,    64,    13,    42,    29,    11,    40,
     750,    75,    75,    12,    74,   738,    29,    68,    75,     9,
      10,   753,   754,    75,    68,    68,    68,    75,    40,    68,
      69,    70,    71,    72,    14,    95,    75,    97,   770,    99,
      11,    40,    13,    75,    99,   123,   106,    75,   108,    39,
     110,   783,   112,    75,   786,    10,   116,    68,     3,    39,
       0,     3,    75,   123,    11,    68,    13,     3,   123,    14,
     130,    13,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   313,   314,    21,    22,
      23,     3,    25,   153,   154,   155,     3,    68,    21,    32,
      33,     3,   162,   163,    75,    12,     3,   742,   168,    32,
      33,    56,   172,    68,    69,    70,    71,    72,    22,    23,
      75,   181,     3,    68,    69,    70,    71,    72,    32,    33,
      75,    12,    21,     3,     4,     5,     6,     7,     8,     9,
     200,    11,   298,    32,    33,     3,    16,     3,   208,   281,
       4,     5,    68,    22,    24,     9,   216,   217,   218,    29,
     220,   221,    16,    32,    33,     0,    10,   227,    10,     8,
       9,   231,    68,     8,     9,    29,    11,     4,    25,    21,
     240,     3,     9,    18,    19,    32,    33,    10,     0,    16,
      32,    33,    34,    35,    36,    37,     8,    32,    10,   259,
      32,    33,    29,    32,    33,    75,    18,   267,   268,   269,
     270,   271,   272,   273,    10,   275,   276,   277,   278,   279,
      32,   281,   300,    40,    68,    69,    70,    71,    72,    64,
      40,    75,    11,   293,    56,    17,    18,    19,   298,    74,
     300,    22,   302,   298,    25,   300,    68,    69,    70,    71,
      72,    32,    33,    75,     4,     5,     6,     7,     8,     9,
      95,    11,    97,    13,    99,    42,    16,    34,    35,    36,
      37,   106,    75,   108,    24,   110,    13,   112,    25,    29,
      21,   116,   342,     9,    25,    32,    33,    99,   123,    32,
      33,    32,    33,    19,    62,   130,    42,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   123,    21,    22,    23,    59,    60,    39,   153,   131,
     132,     9,    75,    32,    33,    75,    10,   162,   163,    21,
      12,   697,   698,   168,    10,   170,   171,   172,    41,    75,
      32,    33,    34,    35,    36,    37,   181,    10,    74,     9,
      40,    12,   579,    12,     4,     5,     6,     7,     8,     9,
      12,    11,    12,    12,    12,   200,    16,    22,    23,    95,
      25,    97,   738,   208,    24,    13,    75,    32,    33,    29,
     106,   216,   108,    14,   110,    10,   112,    40,     9,    12,
     116,    20,   227,    20,    20,    10,   231,   232,   233,    15,
      16,    17,    18,    19,   130,   240,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
      20,    10,     8,     3,   259,    75,    15,    16,    17,    18,
      19,    20,   267,   268,   269,   270,   271,   272,   273,    12,
     275,   276,   277,   278,   279,    75,   281,    14,     3,    40,
       0,    17,    18,    19,    20,   580,    59,    42,   293,     9,
       3,    10,    10,   298,    42,   300,    42,   302,    18,    19,
     697,   698,    14,     4,     5,     6,     7,     8,     9,    42,
      11,    12,    32,    10,     9,    16,   298,    40,   300,    40,
       9,   718,    39,    24,    21,    22,    23,    10,    29,    10,
     743,   227,   715,   709,   132,    32,    33,   342,   778,   321,
      10,   738,     8,   718,    -1,   742,   743,    -1,    -1,    -1,
     580,    21,    -1,    -1,    74,    15,    16,    17,    18,    19,
     342,    -1,    32,    33,    34,    35,    36,    37,    -1,    -1,
      30,    31,    -1,   675,    75,    95,   692,    97,    -1,    99,
      68,    69,    70,    71,    72,   281,   106,    75,   108,    -1,
     110,    -1,   112,    -1,    -1,    -1,   116,   293,    17,    18,
      19,    20,    -1,   123,    -1,    -1,   302,    -1,    -1,    -1,
     130,    -1,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,     4,     5,     6,     7,
       8,     9,    -1,   153,    17,    18,    19,    20,    16,    -1,
     688,    -1,   162,   163,    -1,   675,    24,    -1,   168,    -1,
      -1,    29,   172,   173,   174,   685,   686,   687,   688,    -1,
     690,   181,   692,   688,     4,     5,     6,     7,     8,     9,
       4,     5,     6,     7,     8,     9,    16,    11,    12,    -1,
     200,    -1,    16,    -1,    24,   715,   716,    -1,   208,    29,
      24,    -1,    -1,    10,    -1,    29,   216,    75,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,   227,    -1,    26,
      27,    28,    -1,    30,    31,    -1,   746,     4,     5,     6,
       7,     8,     9,   753,   754,    -1,    -1,    -1,   758,    16,
     760,    17,    18,    19,    20,   765,    -1,    24,   768,    -1,
     770,    75,    29,    -1,    15,    16,    17,    18,    19,    -1,
     780,    -1,    -1,   783,    -1,    26,   786,    28,    -1,    30,
      31,   281,    -1,     0,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,   293,    11,   580,    -1,    -1,   298,    16,
     300,    -1,   302,    17,    18,    19,    20,    24,    75,    -1,
      -1,    -1,    29,     0,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    25,    11,    34,    35,    36,    37,    16,
      32,    33,    34,    35,    36,    37,    -1,    24,    -1,    56,
      57,    58,    29,    -1,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    56,
      57,    58,    -1,    -1,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    -1,
     675,    -1,    -1,    -1,     4,     5,     6,     7,     8,     9,
     685,   686,   687,   688,   580,   690,    16,   692,     4,     5,
       6,     7,     8,     9,    24,    11,    12,    -1,    -1,    29,
      16,    -1,    -1,   685,    -1,   687,   688,    -1,    24,    -1,
     715,   716,    -1,    29,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    -1,    -1,    16,    15,    16,    17,
      18,    19,    20,    -1,    24,    -1,    -1,    -1,    -1,    29,
      -1,   746,    30,    31,    -1,    75,    -1,    -1,   753,   754,
      -1,    -1,    -1,   758,    -1,   760,    -1,    -1,    -1,    75,
     765,    -1,    -1,   768,    -1,   770,    -1,    -1,    -1,    -1,
      -1,   753,   754,    -1,    -1,   780,    -1,    -1,   783,   675,
      -1,   786,    -1,    -1,    -1,    75,    -1,    -1,   770,    -1,
      -1,    -1,    -1,    -1,   690,    21,   692,    -1,    -1,    25,
      -1,   783,    -1,    -1,   786,    -1,    32,    33,    34,    35,
      36,    37,    15,    16,    17,    18,    19,    20,    -1,   715,
     716,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    -1,    -1,    14,    -1,
      16,    15,    16,    17,    18,    19,    20,    -1,    24,    -1,
     746,    -1,    -1,    29,     4,     5,     6,     7,     8,     9,
     580,    -1,   758,    -1,   760,    -1,    16,    -1,    -1,   765,
      -1,    -1,   768,    -1,    24,    -1,    -1,    -1,    -1,    29,
      56,    57,    58,    -1,   780,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    16,    15,    16,    17,    18,    19,    20,    -1,
      24,    -1,    -1,    -1,    -1,    29,    -1,    -1,     8,    -1,
      10,    11,    12,     4,     5,     6,     7,     8,     9,    -1,
      11,    -1,    -1,    -1,    -1,    16,    32,    33,    34,    35,
      36,    37,    -1,    24,    -1,   675,    -1,    -1,    29,    15,
      16,    17,    18,    19,    20,   685,    -1,   687,   688,    -1,
     690,    75,   692,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    64,    65,     4,     5,     6,     7,
       8,     9,    -1,    11,    -1,   715,   716,    -1,    16,    -1,
      80,    -1,    -1,    -1,    75,    -1,    24,    10,    -1,    89,
      90,    29,    15,    16,    17,    18,    19,    15,    16,    17,
      18,    19,    20,    26,    27,    28,   746,    30,    31,    -1,
      -1,    -1,    -1,   753,   754,    -1,    -1,    -1,   758,    -1,
     760,    -1,    -1,    -1,    -1,   765,    -1,    -1,   768,    -1,
     770,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,
     780,    -1,    -1,   783,    -1,    -1,   786,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,     8,    -1,    10,    11,    -1,    -1,
      -1,   231,    -1,    -1,    -1,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,    -1,   267,   268,   269,
     270,   271,   272,   273,     9,   275,   276,   277,   278,   279,
      64,    65,    15,    16,    17,    18,    19,    20,   288,   289,
     290,   291,   292,    26,    27,    28,    80,    30,    31,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    10,    -1,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    26,
      27,    28,   342,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
       8,    -1,    -1,    11,    -1,    -1,    -1,   231,    -1,    -1,
      -1,   235,   236,   237,   238,   239,   240,    -1,    -1,    -1,
      -1,    -1,   246,   247,   248,   249,   250,   251,    -1,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,    -1,   267,   268,   269,   270,   271,   272,   273,
      -1,   275,   276,   277,   278,   279,    64,    -1,    -1,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      10,    -1,    14,    -1,    16,    15,    16,    17,    18,    19,
      20,    21,    24,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    -1,   342,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,    -1,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,   231,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    -1,   240,    32,    33,    34,    35,    36,    37,    15,
      16,    17,    18,    19,    20,    -1,   686,    -1,    -1,    -1,
      -1,   259,    -1,    -1,    30,    31,    -1,    -1,    -1,   267,
     268,   269,   270,   271,   272,   273,    -1,   275,   276,   277,
     278,   279,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    25,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   342,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    13,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    -1,    14,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    56,
      57,    58,    29,    -1,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    58,   686,    -1,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    -1,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    29,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    -1,    25,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    56,    57,    58,    -1,    -1,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    25,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    15,    16,    17,    18,    19,
      20,    -1,    22,    -1,    -1,    25,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    25,    26,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    25,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,   686,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,    -1,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    15,    16,    17,    18,
      19,    20,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    32,
      33,    34,    35,    36,    37,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    25,    15,    16,    17,    18,
      19,    20,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    30,    31,    -1,    -1,    34,    35,    36,    37,    15,
      16,    17,    18,    19,    20,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    30,    31,    -1,    -1,    34,    35,
      36,    37,    32,    33,    34,    35,    36,    37,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    -1,    -1,    34,    35,    36,
      37,    26,    -1,    -1,    -1,    30,    31,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,     0,     3,     4,     5,     6,     7,     8,     9,    11,
      16,    24,    29,    56,    57,    58,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    78,    79,    80,    81,    84,    86,    87,    88,    89,
      90,    91,    94,    97,   100,   101,   102,   103,   106,   107,
     108,   109,   110,   112,   113,   114,   117,   118,   119,   120,
     121,   123,   125,     8,     9,    16,    75,   106,   110,   113,
     117,   118,   119,   120,     3,    12,    75,   106,   107,   111,
       9,    75,   106,   117,   118,   117,   118,   119,   120,     9,
      16,   117,    75,    75,    85,     9,     9,     9,     3,    13,
      81,    82,    83,   107,    75,    68,    11,    68,    11,    68,
      11,    68,    11,    68,    75,    75,    11,    13,    68,   105,
     115,     0,     0,     1,    80,     3,     3,     3,     3,     3,
       9,    39,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     3,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    25,    26,    27,    28,
      30,    31,    32,    33,    34,    35,    36,    37,    21,    25,
      32,    33,    21,    32,    33,    15,    16,    17,    18,    19,
      20,    21,    25,    26,    27,    28,    30,    31,    32,    33,
      34,    35,    36,    37,    15,    16,    17,    18,    19,    20,
      21,    25,    32,    33,    34,    35,    36,    37,    21,    25,
      32,    33,    34,    35,    36,    37,    21,    22,    23,    25,
      32,    33,    68,    68,     9,    75,    10,    11,   115,    10,
      10,    21,    32,    33,    10,    15,    16,    17,    18,    19,
      21,    26,    27,    28,    30,    31,    32,    33,    34,    35,
      36,    37,    10,    15,    16,    17,    18,    19,    20,    21,
      32,    33,    34,    35,    36,    37,    10,    21,    32,    33,
      34,    35,    36,    37,    10,    21,    22,    23,    32,    33,
     111,    40,     3,    12,   117,   118,   117,   117,    15,    16,
      17,    18,    19,    42,    40,   107,    75,   107,    13,    14,
      79,    62,    42,    12,   107,   124,    12,   124,    12,   124,
      12,   124,     3,    13,     9,    12,   107,   124,    14,    39,
     116,    39,    80,    10,   104,   107,   106,   102,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,     9,   108,   113,   114,   117,   118,   119,   120,
     108,   117,   118,   108,   117,   118,   108,   117,   118,   108,
     117,   118,   108,   117,   118,   108,   113,   114,   117,   118,
     119,   120,   108,   118,   120,   108,   120,   108,   119,   108,
     117,   108,   117,   108,   117,   108,   117,   108,   117,   108,
     113,   114,   117,   118,   119,   120,   108,   113,   114,   117,
     118,   119,   120,   108,   117,   118,   119,   108,   117,   118,
     119,   108,   117,   118,   119,   108,   117,   118,   119,   108,
     113,   114,   117,   118,   119,   120,   108,   108,   113,   108,
     113,   108,   113,   114,   117,   118,   119,   120,   108,   114,
     108,   114,   108,   117,   118,   108,   117,   118,   108,   117,
     118,   108,   117,   118,   108,   117,   118,   117,   118,   108,
     113,   114,   117,   118,   119,   120,   108,   108,   117,   108,
     117,   108,   117,   108,   117,   108,   117,   108,   117,   118,
     108,   117,   118,   108,   117,   118,   108,   117,   118,   108,
     117,   118,   108,   117,   118,   108,   117,   118,   108,   117,
     118,   108,   117,   118,   108,   117,   118,   108,   117,   118,
     108,   117,   118,   108,   113,   114,   117,   118,   119,   120,
     108,   108,   117,   118,   108,   117,   118,   108,   117,   118,
     108,   117,   118,   108,   117,   118,   108,   117,   118,   108,
     113,   114,   117,   118,   119,   120,   108,   108,   119,   108,
     119,   108,   119,   108,   119,   108,   119,   108,   119,   108,
     113,   114,   117,   118,   119,   120,   108,   120,   108,   120,
     108,   108,   120,   108,   120,    10,    75,   122,   125,     9,
      42,   107,    10,   113,   117,   118,   119,   120,     9,   113,
     113,   117,   118,   117,   118,   117,   118,   117,   118,   117,
     118,   113,   117,   118,   119,   120,   117,   117,   117,   117,
     117,   117,   118,   117,   118,   117,   118,   117,   118,   117,
     118,   117,   118,   117,   118,   117,   118,   117,   118,   117,
     118,   117,   118,   117,   118,   113,   117,   118,   119,   120,
     117,   118,   117,   118,   117,   118,   117,   118,   117,   118,
     117,   118,   113,   117,   118,   119,   120,   119,   120,   119,
     119,   119,   119,   119,   113,   117,   118,   119,   120,   120,
     120,   120,   120,     3,    12,     3,   111,    12,   117,   117,
     117,   117,   117,   107,    75,    10,    41,    10,    79,    14,
       9,   107,    40,    12,    12,    12,    12,    13,     3,    14,
      56,    95,    96,   100,   125,    10,    98,    99,   125,    12,
      12,    75,    14,   106,    10,    40,    11,    10,    40,    10,
      98,   107,   115,     8,    12,   111,    83,    75,   119,    83,
      14,     3,   107,   124,    95,    95,    75,    14,     3,    75,
      82,    10,    40,    40,    75,   105,    42,   104,   122,    82,
      10,    59,    92,    10,    10,     3,    10,    14,    42,    95,
      42,    82,    98,    99,   125,    42,   107,    82,     9,    59,
      60,    93,    83,    83,   107,   107,    75,   107,    40,   107,
       9,    83,   116,    10,   107,    83,    10,    83
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    77,    78,    78,    79,    79,    79,    80,    80,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    82,    82,    82,    82,    82,    83,    83,    84,    85,
      85,    86,    86,    86,    87,    87,    88,    88,    89,    90,
      91,    92,    92,    92,    93,    93,    94,    94,    94,    95,
      95,    95,    95,    96,    96,    96,    97,    97,    97,    97,
      98,    98,    98,    99,    99,   100,   101,   101,   101,   101,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   103,   103,   104,   104,   105,
     105,   106,   106,   106,   106,   106,   107,   107,   107,   107,
     107,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     109,   109,   109,   109,   110,   110,   110,   110,   110,   111,
     111,   111,   112,   112,   113,   113,   114,   114,   115,   115,
     116,   116,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   121,   121,   122,   122,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   124,   124,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     1,     2,     1,     2,     3,     1,     1,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     4,     4,     5,     1,     1,     2,     1,
       3,     1,     1,     1,     1,     2,     7,     7,     5,     6,
       7,     5,     6,     0,     2,     0,     4,     5,     6,     1,
       2,     2,     3,     1,     4,     4,     5,     6,     5,     6,
       2,     1,     3,     4,     3,     2,     4,     4,     4,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     1,     3,     3,
       4,     1,     1,     2,     4,     3,     1,     1,     1,     1,
       1,     1,     2,     3,     3,     3,     3,     3,     3,     3,
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
       1,     1,     1,     1,     2,     3,     4,     4,     5,     1,
       3,     4,     1,     3,     1,     3,     2,     4,     2,     3,
       4,     6,     1,     2,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     3,     1,     3,     4,     3,     4,
       3,     4,     3,     4,     3,     4,     3,     1,     3,     2,
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
  "\"?\"", "\"\\\"int\\\"\"", "\"\\\"float\\\"\"", "\"\\\"string\\\"\"",
  "\"\\\"bool\\\"\"", "\"\\\"struct\\\"\"", "\"\\\"void\\\"\"",
  "\"identifier\"", "NEG", "$accept", "start", "stmt", "stmts", "stmts_ne",
  "block", "body", "import", "id_list", "flowctl", "return", "for",
  "while", "dowhile", "if", "elif", "else", "struct", "decllist",
  "declistval", "function", "funargs", "funargdef", "vardecl", "vardef",
  "set", "funcall", "callarglist", "select", "scope", "expr", "expr_var",
  "val", "matrix", "matvals", "expr_mat", "expr_none", "expr_struct",
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
     221,   225,   226,   227,   229,   230,   234,   235,   239,   242,
     246,   248,   249,   250,   252,   253,   257,   258,   259,   261,
     262,   263,   264,   266,   267,   268,   272,   273,   274,   275,
     277,   278,   279,   281,   282,   286,   290,   291,   292,   293,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   315,   316,   318,   320,   328,
     329,   333,   334,   335,   336,   337,   341,   342,   343,   344,
     345,   348,   349,   350,   352,   353,   354,   356,   357,   358,
     359,   360,   362,   363,   364,   365,   366,   368,   369,   370,
     371,   372,   374,   375,   376,   377,   378,   380,   381,   382,
     383,   384,   386,   387,   388,   390,   391,   392,   394,   395,
     396,   397,   398,   399,   400,   402,   403,   404,   405,   406,
     407,   408,   410,   411,   412,   413,   414,   415,   416,   418,
     419,   420,   421,   422,   423,   424,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   456,   457,   458,   460,   461,   462,
     464,   465,   466,   468,   469,   470,   471,   472,   473,   474,
     476,   477,   478,   480,   481,   482,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     511,   512,   513,   514,   518,   519,   520,   521,   522,   524,
     525,   526,   530,   531,   535,   536,   540,   541,   543,   544,
     546,   547,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   622,   623,   624,   625,   626,   628,
     629,   630,   631,   632,   633,   634,   636,   637,   638,   639,
     640,   641,   642,   644,   645,   646,   647,   648,   650,   651,
     652,   653,   654,   656,   657,   658,   659,   660,   662,   663,
     664,   665,   666,   670,   671,   673,   674,   678,   679,   680,
     681,   682,   683,   684,   685,   686,   687,   689,   690,   694,
     695,   696,   697,   698,   699,   700,   701,   702,   703,   704,
     705,   706,   707,   708
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

#line 13 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
} //  ptc 
#line 2789 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"

#line 711 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    std::cerr << scanner->loc->begin.line << ":" << scanner->loc->begin.column << ": " << err_message << std::endl;
}
