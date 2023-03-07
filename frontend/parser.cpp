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
  case 100: // expr_int: "int"
#line 433 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 787 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 101: // expr_int: "-" expr_int
#line 434 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 793 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 102: // expr_int: "(" expr_int ")"
#line 435 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 799 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 103: // expr_int: "~" expr_int
#line 436 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 805 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 104: // expr_int: expr_int "*" expr_int
#line 437 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 811 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 105: // expr_int: expr_int "/" expr_int
#line 438 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 817 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 106: // expr_int: expr_int "%" expr_int
#line 439 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 823 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 107: // expr_int: expr_int "-" expr_int
#line 440 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 829 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 108: // expr_int: expr_int "+" expr_int
#line 441 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 835 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 109: // expr_int: expr_int "<<" expr_int
#line 442 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 841 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 110: // expr_int: expr_int ">>" expr_int
#line 443 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 847 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 111: // expr_int: expr_int "&" expr_int
#line 444 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 853 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 112: // expr_int: expr_int "^" expr_int
#line 445 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 859 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 113: // expr_int: expr_int "|" expr_int
#line 446 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 865 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 114: // expr_float: "float"
#line 450 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 871 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 115: // expr_float: "-" expr_float
#line 451 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 877 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 116: // expr_float: "(" expr_float ")"
#line 452 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 883 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 117: // expr_float: expr_float "**" expr_float
#line 453 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 889 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 118: // expr_float: expr_float "**" expr_int
#line 454 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 895 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 119: // expr_float: expr_int "**" expr_float
#line 455 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 901 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 120: // expr_float: expr_float "*" expr_float
#line 456 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 907 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 121: // expr_float: expr_float "*" expr_int
#line 457 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 913 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 122: // expr_float: expr_int "*" expr_float
#line 458 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 919 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 123: // expr_float: expr_float "/" expr_float
#line 459 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 925 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 124: // expr_float: expr_float "/" expr_int
#line 460 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 931 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 125: // expr_float: expr_int "/" expr_float
#line 461 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 937 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 126: // expr_float: expr_float "%" expr_float
#line 462 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 943 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 127: // expr_float: expr_float "%" expr_int
#line 463 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 949 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 128: // expr_float: expr_int "%" expr_float
#line 464 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 955 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 129: // expr_float: expr_float "-" expr_float
#line 465 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 961 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 130: // expr_float: expr_float "-" expr_int
#line 466 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 967 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 131: // expr_float: expr_int "-" expr_float
#line 467 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 973 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 132: // expr_float: expr_float "+" expr_float
#line 468 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 979 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 133: // expr_float: expr_float "+" expr_int
#line 469 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 985 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 134: // expr_float: expr_int "+" expr_float
#line 470 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 991 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 135: // expr_str: "string"
#line 474 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 997 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 136: // expr_str: "(" expr_str ")"
#line 475 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 1003 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 137: // expr_str: expr_str "++" expr_str
#line 476 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 1009 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 138: // expr_str: expr_str "++" expr_int
#line 477 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 1015 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 139: // expr_str: expr_str "++" expr_float
#line 478 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 1021 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 140: // expr_str: expr_str "++" expr_bool
#line 479 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1027 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 141: // expr_str: expr_int "++" expr_str
#line 480 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 1033 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 142: // expr_str: expr_int "++" expr_int
#line 481 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 1039 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 143: // expr_str: expr_int "++" expr_float
#line 482 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 1045 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 144: // expr_str: expr_int "++" expr_bool
#line 483 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1051 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 145: // expr_str: expr_float "++" expr_str
#line 484 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 1057 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 146: // expr_str: expr_float "++" expr_int
#line 485 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 1063 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 147: // expr_str: expr_float "++" expr_float
#line 486 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 1069 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 148: // expr_str: expr_float "++" expr_bool
#line 487 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1075 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 149: // expr_str: expr_bool "++" expr_str
#line 488 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 1081 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 150: // expr_str: expr_bool "++" expr_int
#line 489 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 1087 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 151: // expr_str: expr_bool "++" expr_float
#line 490 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 1093 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 152: // expr_str: expr_bool "++" expr_bool
#line 491 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1099 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 153: // expr_bool: "bool"
#line 495 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 1105 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 154: // expr_bool: "(" expr_bool ")"
#line 496 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 1111 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 155: // expr_bool: "not" expr_bool
#line 497 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 1117 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 156: // expr_bool: expr_bool "or" expr_bool
#line 498 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 1123 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 157: // expr_bool: expr_bool "and" expr_bool
#line 499 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 1129 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 158: // expr_bool: expr_bool "==" expr_bool
#line 500 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 1135 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 159: // expr_bool: expr_int "==" expr_int
#line 501 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 1141 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 160: // expr_bool: expr_float "==" expr_float
#line 502 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 1147 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 161: // expr_bool: expr_str "==" expr_str
#line 503 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 1153 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 162: // expr_bool: expr_bool "!=" expr_bool
#line 504 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 1159 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 163: // expr_bool: expr_int "!=" expr_int
#line 505 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 1165 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 164: // expr_bool: expr_float "!=" expr_float
#line 506 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 1171 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 165: // expr_bool: expr_str "!=" expr_str
#line 507 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 1177 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 166: // expr_bool: expr_int ">" expr_int
#line 508 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 1183 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 167: // expr_bool: expr_float ">" expr_float
#line 509 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 1189 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 168: // expr_bool: expr_str ">" expr_str
#line 510 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 1195 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 169: // expr_bool: expr_int "<" expr_int
#line 511 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 1201 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 170: // expr_bool: expr_float "<" expr_float
#line 512 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 1207 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 171: // expr_bool: expr_str "<" expr_str
#line 513 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 1213 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 172: // expr_bool: expr_int ">=" expr_int
#line 514 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 1219 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 173: // expr_bool: expr_float ">=" expr_float
#line 515 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 1225 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 174: // expr_bool: expr_str ">=" expr_str
#line 516 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 1231 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 175: // expr_bool: expr_int "<=" expr_int
#line 517 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 1237 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 176: // expr_bool: expr_float "<=" expr_float
#line 518 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 1243 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 177: // expr_bool: expr_str "<=" expr_str
#line 519 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 1249 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;


#line 1253 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -290;

  const short  Parser ::yytable_ninf_ = -207;

  const short
   Parser ::yypact_[] =
  {
     529,  -290,  -290,  -290,  -290,  -290,  -290,  -290,   979,    58,
     429,  1052,   143,   -22,   -11,    67,    98,   127,   713,   965,
    -290,  -290,    76,   103,    -2,     3,    17,    30,    94,   107,
      -5,   176,   464,  -290,  -290,   174,   177,  -290,  -290,  -290,
    -290,  -290,  -290,  -290,   187,   197,   199,  -290,   123,   213,
    -290,  -290,  -290,  1067,   655,   778,   342,   211,   212,     6,
    1052,   450,   264,   101,  1016,   531,   347,   600,   965,  -290,
       7,   249,    77,   450,     7,  -290,  -290,  1067,   655,   778,
    -290,   143,   143,  -290,   248,  -290,   252,   965,   251,   965,
     294,   773,  -290,  -290,   265,  -290,   273,  -290,    15,  -290,
     338,  -290,   892,  -290,   906,  -290,    85,   313,   920,  -290,
     284,  -290,  -290,   833,  -290,  -290,  -290,  -290,  -290,  -290,
     951,   263,   965,  -290,   450,   450,   450,   450,   450,   450,
    1052,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   450,   450,   450,   450,   450,   450,  1052,   450,
     450,   450,   450,   450,   450,  1052,  1052,  1052,  1052,  1052,
    1052,  1052,  1052,  1052,  1052,  1052,  1052,  -290,  -290,   278,
      33,   965,  -290,  -290,  -290,  -290,  -290,    90,   119,   316,
    -290,  1118,  1158,   837,  -290,   143,   143,   143,   143,   143,
     965,   269,   322,   297,   331,   833,  -290,   591,   339,   965,
    -290,   315,   341,  -290,   344,  -290,   348,  -290,   349,   346,
     130,   394,  -290,   139,   354,   263,  -290,  -290,   360,   337,
     376,  -290,   537,   542,   537,   542,   366,   367,   366,   367,
     366,   367,  1047,   367,  1090,   715,   838,   161,   254,   922,
    1124,  1096,  1096,   777,   777,   777,   777,   777,   777,  1139,
     542,  1139,   542,   416,   367,   416,   367,   416,   367,   416,
     367,  1090,   715,   838,   161,  1164,  1164,  1164,  1164,  1164,
    1164,  1090,   715,   838,   161,   582,   342,   582,  -290,  -290,
    -290,  -290,  1090,   715,   838,   161,   -20,   128,  -290,  -290,
    -290,    44,   387,     8,   427,   965,   386,   389,  -290,   965,
    -290,  -290,   245,   245,  -290,  -290,  -290,  -290,  -290,   713,
     993,   713,   653,   402,   965,  -290,   965,  -290,  -290,  -290,
    -290,   262,   262,  -290,   345,   392,   436,  -290,    16,   154,
     124,   400,    21,   264,  -290,   376,  -290,   965,   920,  -290,
     439,   154,   131,  -290,  -290,  -290,   395,   447,   593,  -290,
     457,  -290,   451,  -290,   460,  -290,   434,  -290,   262,   435,
    -290,   154,   439,   439,   445,  -290,  -290,  -290,  -290,   154,
     469,    -9,   713,   713,  -290,  -290,  -290,   965,  -290,   965,
    -290,   452,   400,    24,   965,  -290,   965,   481,   713,  -290,
    -290,  -290,  -290,  -290,   445,  -290,   490,   965,  -290,   713,
     492,  -290,   713,  -290
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
       0,     2,     7,   100,   114,   135,   153,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      31,    32,     0,     0,   202,   203,   204,   205,     0,     0,
      76,     0,     0,     4,     8,     0,     0,    33,    14,    16,
      17,    15,    18,    19,     0,     0,     0,    77,    85,     0,
      82,    83,    81,    88,    89,    90,    91,   207,   208,     0,
       0,     0,    76,     0,     0,     0,     0,     0,     0,    92,
      85,    97,     0,     0,    86,   101,   115,     0,     0,     0,
     155,     0,     0,   103,     0,    29,    28,     0,     0,     0,
       0,     0,    26,    27,     0,    35,     0,   194,     0,   195,
       0,   196,     0,   197,     0,   198,     0,     0,     0,   199,
      78,     1,     3,     0,     5,    13,    20,    11,    12,     9,
       0,     0,     0,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   200,   201,     0,
      65,     0,    87,   102,   116,   136,   154,     0,     0,     0,
      93,     0,     0,     0,   101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,     0,     0,
     185,   192,     0,   187,     0,   189,     0,   191,     0,     0,
       0,     0,   183,     0,     0,     0,     6,    70,     0,    72,
      80,    69,   108,   134,   107,   131,   104,   122,   105,   125,
     106,   128,     0,   119,   142,   143,   141,   144,   111,   113,
     112,   109,   110,   159,   163,   166,   169,   172,   175,   133,
     132,   130,   129,   121,   120,   124,   123,   127,   126,   118,
     117,   146,   147,   145,   148,   160,   164,   167,   170,   173,
     176,   138,   139,   137,   140,   161,     0,   165,   168,   171,
     174,   177,   150,   151,   149,   152,   157,   156,   158,   162,
     179,   206,     0,   180,     0,     0,     0,     0,    94,     0,
      98,    95,   108,   107,   104,   105,   106,    68,    30,     0,
       0,     0,     0,    22,     0,    67,     0,   184,   186,   188,
     190,     0,    49,    46,     0,     0,     0,    53,     0,     0,
       0,    61,     0,    74,   182,    79,    71,     0,     0,   178,
       0,     0,     0,    66,    96,    99,    43,     0,     0,    38,
      23,    24,     0,   193,     0,    50,     0,    47,    51,    65,
      58,     0,     0,     0,    60,    75,    73,   181,    56,     0,
       0,    45,     0,     0,    25,    39,    48,     0,    52,     0,
      59,    62,    64,     0,     0,    57,     0,     0,     0,    40,
      36,    37,    55,    54,     0,    63,     0,     0,    44,     0,
       0,    41,     0,    42
  };

  const short
   Parser ::yypgoto_[] =
  {
    -290,  -290,   -89,   -29,     4,  -232,  -257,  -290,  -290,  -290,
    -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,  -287,  -290,
    -290,  -289,   142,  -203,  -290,  -290,  -290,   169,   178,     0,
      -8,  -290,  -290,  -290,   -39,    93,   266,    48,   138,  -290,
     170,  -290,   -55,   141
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    31,    32,    33,    92,    93,    94,    35,    86,    36,
      37,    38,    39,    40,    41,   371,   389,    42,   325,   326,
      43,   330,   331,    44,    45,    46,    47,   218,   110,    70,
      49,    50,    51,    52,    72,    53,    54,    55,    56,    57,
     292,    58,   214,    59
  };

  const short
   Parser ::yytable_[] =
  {
      48,    71,   197,   114,    34,   342,   108,   327,    63,    98,
      74,    95,   165,   166,   100,   169,   120,   169,    48,     3,
       4,     5,     6,     7,     8,   169,     9,   200,   102,   177,
     169,    10,    48,   169,   354,   355,    34,   387,   388,    11,
      84,   104,   294,   202,    12,   204,   121,   206,   340,   208,
     109,    85,   346,    99,   349,   338,    66,  -206,   101,    79,
      71,    68,     3,     4,     5,     6,     7,     8,   170,     9,
      69,   378,   103,   381,    10,   295,    87,    62,   359,   192,
     179,   194,    11,   364,   216,   105,   394,    12,   209,   180,
     201,    48,   201,   297,   201,    34,   201,   360,   210,   109,
     213,    64,   298,    75,    77,    83,   312,    88,    66,   368,
     120,   172,   219,    48,   221,   390,   391,    34,   327,   327,
      62,   220,   299,     3,     4,     5,     6,     7,     8,   380,
       9,   398,   120,   322,   361,    10,    89,   385,    96,   300,
     121,   369,   401,    11,   323,   403,    67,     3,    12,    80,
     163,   333,    81,    64,    75,   327,   106,    90,    97,    82,
     165,   166,   121,   296,   362,   122,   181,    91,   114,   107,
      71,   362,    12,   324,   183,   184,   111,   115,   236,   316,
     116,    62,   307,   163,   164,    23,    24,    25,    26,    27,
     117,   315,   291,   165,   166,    48,   263,    48,    67,    34,
     118,    34,   119,   273,   275,   277,   278,   279,   280,   281,
     284,    79,    79,    79,    79,   335,   123,   222,   224,   226,
     228,   230,   232,   234,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   251,   253,   255,   257,
     259,   261,   232,   232,   232,   232,   232,   232,   271,    77,
      77,    77,    77,    77,    77,   282,    77,    77,    77,    77,
     345,   353,   187,   188,   189,   322,   167,   168,   237,   185,
     186,   187,   188,   189,    65,   171,    76,    78,   302,   303,
     304,   305,   306,   114,   134,   135,   264,   343,   290,   178,
     190,    71,   191,   274,   276,   276,   276,   276,   276,   276,
     285,   286,   287,   288,   289,   324,   352,   195,   201,    48,
     293,    48,    48,   193,   198,   199,    34,    23,    24,    25,
      26,    27,   211,   215,   291,    62,    65,    76,   301,   219,
     201,   308,   309,    23,    24,    25,    26,    27,   310,   182,
     291,   311,     3,     4,     5,     6,     7,     8,   314,     9,
     203,   328,   332,   317,    10,   316,   318,   175,   348,   321,
     319,   320,    11,   162,   163,   164,   334,    12,   155,   392,
     336,   393,    48,    48,   165,   166,   395,   337,   396,   156,
     157,   158,   159,   160,   161,   120,   129,   147,    48,   400,
     223,   225,   227,   229,   231,   233,   235,   339,   333,    48,
      62,   344,    48,    77,   329,   351,   357,   356,   250,   252,
     254,   256,   258,   260,   262,   265,   266,   267,   268,   269,
     270,   272,    78,    78,    78,    78,    78,    78,   283,    78,
      78,    78,    78,     3,     4,   332,   129,   341,    73,   358,
     363,   370,   131,   132,   133,    61,   134,   135,   276,    23,
      24,    25,    26,    27,     3,     4,   291,   372,    12,    73,
     374,   375,   328,   328,   112,   113,    61,     2,     3,     4,
       5,     6,     7,     8,   376,     9,   377,   379,   386,    12,
      10,   293,    23,    24,    25,    26,    27,   384,    11,   291,
     397,    62,   362,    12,    23,    24,    25,    26,    27,   328,
     399,   291,   402,   332,   383,   382,   366,    13,    14,    15,
     367,   365,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,     0,     0,     1,
       0,     0,     2,     3,     4,     5,     6,     7,     8,     0,
       9,   174,     0,     0,     0,    10,   142,   143,   144,   145,
     146,   147,   148,    11,   126,   127,   128,   129,    12,   144,
     145,   146,   147,   149,   150,   151,   152,   153,   154,     0,
       0,     0,    13,    14,    15,     0,    78,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,   113,     0,     2,     3,     4,     5,     6,     7,
       8,     0,     9,   373,     0,   313,     0,    10,     0,     0,
     176,     0,     0,     0,   155,    11,   158,   159,   160,   161,
      12,   162,   163,   164,     0,   156,   157,   158,   159,   160,
     161,     0,   165,   166,    13,    14,    15,     0,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,   113,     0,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,   350,     0,    10,
     142,   143,   144,   145,   146,   147,   148,    11,     0,     0,
       0,     0,    12,     0,     0,     0,     0,   149,   150,   151,
     152,   153,   154,     0,     0,     0,    13,    14,    15,     0,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    90,     3,     4,     5,
       6,     7,     8,     0,     9,     0,    91,     0,     0,    10,
     142,   143,   144,   145,   146,   147,     0,    11,     0,     0,
       0,     0,    12,     0,     0,     0,     0,   149,   150,   151,
     152,   153,   154,     0,     0,     0,    13,    14,    15,     0,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,   196,     0,    10,
       0,     0,   185,   186,   187,   188,   189,    11,     0,   155,
       0,     0,    12,   131,   132,   133,     0,   134,   135,     0,
     156,   157,   158,   159,   160,   161,    13,    14,    15,     0,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,   173,     0,    10,
       0,     0,   185,   186,   187,   188,   189,    11,     0,     0,
       0,     0,    12,   131,   132,   133,     0,   134,   135,     0,
     156,   157,   158,   159,   160,   161,    13,    14,    15,     0,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,     3,     4,     5,     6,
       7,     8,     0,     9,   205,     0,     0,     0,    10,     0,
       3,     4,     5,     6,     7,     8,    11,     9,   207,     0,
       0,    12,    10,     0,     3,     4,     5,     6,     7,     8,
      11,     9,   212,     0,     0,    12,    10,   185,   186,   187,
     188,   189,     0,     0,    11,     0,     0,     0,   131,    12,
     133,     0,   134,   135,    62,     3,     4,     5,     6,     7,
       8,   217,     9,     0,     0,     0,     0,    10,    62,     3,
       4,     5,     6,     7,     8,    11,     9,     0,     0,     0,
      12,    10,    62,     3,     4,     5,     6,     0,    60,    11,
       0,     0,     0,     0,    12,    61,     0,     3,     4,     5,
       6,     0,    60,    11,     0,     0,     0,     0,    12,    61,
       0,     0,     0,    62,     0,     0,     0,    11,     0,     0,
       0,     0,    12,     0,     0,     0,   173,    62,     0,     0,
       0,   124,   125,   126,   127,   128,   129,   130,     0,     0,
       0,    62,   131,   132,   133,     0,   134,   135,   136,   137,
     138,   139,   140,   141,     0,   347,     3,     4,     5,     6,
       0,    60,   124,   125,   126,   127,   128,   129,    61,     0,
       0,     0,     0,   131,   132,   133,    11,   134,   135,     0,
       0,    12,   124,   125,   126,   127,   128,   129,   130,     0,
       0,     0,     0,   131,   132,   133,     0,   134,   135,   136,
     137,   138,   139,   140,   141,   124,   125,   126,   127,   128,
     129,   185,   186,   187,   188,   189,   131,   132,   133,     0,
     134,   135,   136,   137,   138,   139,   140,   141,   173,     0,
       0,     0,     0,   124,   125,   126,   127,   128,   129,   185,
     186,   187,   188,   189,   131,   132,   133,     0,   134,   135,
     131,     0,     0,     0,   134,   135,   126,   127,   128,   129,
       0,     0,     0,     0,     0,   131,   132,   133,   174,   134,
     135,     0,     0,   142,   143,   144,   145,   146,   147,   142,
     143,   144,   145,   146,   147
  };

  const short
   Parser ::yycheck_[] =
  {
       0,     9,    91,    32,     0,   294,    11,   210,     8,    11,
      10,    19,    32,    33,    11,     9,     9,     9,    18,     4,
       5,     6,     7,     8,     9,     9,    11,    12,    11,    68,
       9,    16,    32,     9,   321,   322,    32,    46,    47,    24,
      62,    11,     9,    98,    29,   100,    39,   102,    40,   104,
      55,    62,   309,    55,   311,    11,     8,    62,    55,    11,
      68,     3,     4,     5,     6,     7,     8,     9,    62,    11,
      12,   358,    55,   362,    16,    42,     9,    62,    62,    87,
       3,    89,    24,    62,   113,    55,    62,    29,     3,    12,
      98,    91,   100,     3,   102,    91,   104,   329,    13,    55,
     108,     8,    12,    10,    11,    12,   195,     9,    60,   341,
       9,    10,   120,   113,   122,   372,   373,   113,   321,   322,
      62,   121,     3,     4,     5,     6,     7,     8,     9,   361,
      11,   388,     9,     3,    10,    16,     9,   369,    62,   178,
      39,    10,   399,    24,    14,   402,     8,     4,    29,    11,
      22,    12,     9,    60,    61,   358,    62,     3,    55,    16,
      32,    33,    39,   171,    40,    42,    73,    13,   197,    62,
     178,    40,    29,    43,    81,    82,     0,     3,   130,    40,
       3,    62,   190,    22,    23,    55,    56,    57,    58,    59,
       3,   199,    62,    32,    33,   195,   148,   197,    60,   195,
       3,   197,     3,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   215,     3,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     299,   316,    17,    18,    19,     3,    55,    55,   130,    15,
      16,    17,    18,    19,     8,    11,    10,    11,   185,   186,
     187,   188,   189,   312,    30,    31,   148,   295,    10,    40,
      42,   299,    40,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,    43,   314,    13,   316,   309,
     169,   311,   312,    62,    49,    42,   312,    55,    56,    57,
      58,    59,     9,    39,    62,    62,    60,    61,    12,   337,
     338,    62,    10,    55,    56,    57,    58,    59,    41,    73,
      62,    10,     4,     5,     6,     7,     8,     9,     9,    11,
      12,   210,   211,    12,    16,    40,    12,    10,   310,    13,
      12,    12,    24,    21,    22,    23,    12,    29,    21,   377,
      10,   379,   372,   373,    32,    33,   384,    40,   386,    32,
      33,    34,    35,    36,    37,     9,    20,    20,   388,   397,
     124,   125,   126,   127,   128,   129,   130,    10,    12,   399,
      62,    12,   402,   310,    10,     3,    14,    62,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,     4,     5,   294,    20,    10,     9,     3,
      40,    46,    26,    27,    28,    16,    30,    31,   310,    55,
      56,    57,    58,    59,     4,     5,    62,    10,    29,     9,
       3,    10,   321,   322,     0,     1,    16,     3,     4,     5,
       6,     7,     8,     9,    14,    11,    42,    42,     9,    29,
      16,   340,    55,    56,    57,    58,    59,    42,    24,    62,
       9,    62,    40,    29,    55,    56,    57,    58,    59,   358,
      10,    62,    10,   362,   363,   363,   337,    43,    44,    45,
     340,   333,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    -1,     0,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    10,    -1,    -1,    -1,    16,    15,    16,    17,    18,
      19,    20,    21,    24,    17,    18,    19,    20,    29,    17,
      18,    19,    20,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    43,    44,    45,    -1,   310,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    10,    -1,    14,    -1,    16,    -1,    -1,
      10,    -1,    -1,    -1,    21,    24,    34,    35,    36,    37,
      29,    21,    22,    23,    -1,    32,    33,    34,    35,    36,
      37,    -1,    32,    33,    43,    44,    45,    -1,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    -1,    14,    -1,    16,
      15,    16,    17,    18,    19,    20,    21,    24,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    43,    44,    45,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    13,    -1,    -1,    16,
      15,    16,    17,    18,    19,    20,    -1,    24,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    43,    44,    45,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    -1,    14,    -1,    16,
      -1,    -1,    15,    16,    17,    18,    19,    24,    -1,    21,
      -1,    -1,    29,    26,    27,    28,    -1,    30,    31,    -1,
      32,    33,    34,    35,    36,    37,    43,    44,    45,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    -1,    10,    -1,    16,
      -1,    -1,    15,    16,    17,    18,    19,    24,    -1,    -1,
      -1,    -1,    29,    26,    27,    28,    -1,    30,    31,    -1,
      32,    33,    34,    35,    36,    37,    43,    44,    45,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,    -1,    16,    -1,
       4,     5,     6,     7,     8,     9,    24,    11,    12,    -1,
      -1,    29,    16,    -1,     4,     5,     6,     7,     8,     9,
      24,    11,    12,    -1,    -1,    29,    16,    15,    16,    17,
      18,    19,    -1,    -1,    24,    -1,    -1,    -1,    26,    29,
      28,    -1,    30,    31,    62,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    16,    62,     4,
       5,     6,     7,     8,     9,    24,    11,    -1,    -1,    -1,
      29,    16,    62,     4,     5,     6,     7,    -1,     9,    24,
      -1,    -1,    -1,    -1,    29,    16,    -1,     4,     5,     6,
       7,    -1,     9,    24,    -1,    -1,    -1,    -1,    29,    16,
      -1,    -1,    -1,    62,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    10,    62,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    62,    26,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    62,     4,     5,     6,     7,
      -1,     9,    15,    16,    17,    18,    19,    20,    16,    -1,
      -1,    -1,    -1,    26,    27,    28,    24,    30,    31,    -1,
      -1,    29,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    15,    16,    17,    18,    19,
      20,    15,    16,    17,    18,    19,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    10,    -1,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    15,
      16,    17,    18,    19,    26,    27,    28,    -1,    30,    31,
      26,    -1,    -1,    -1,    30,    31,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    10,    30,
      31,    -1,    -1,    15,    16,    17,    18,    19,    20,    15,
      16,    17,    18,    19,    20
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,     0,     3,     4,     5,     6,     7,     8,     9,    11,
      16,    24,    29,    43,    44,    45,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    65,    66,    67,    68,    71,    73,    74,    75,    76,
      77,    78,    81,    84,    87,    88,    89,    90,    93,    94,
      95,    96,    97,    99,   100,   101,   102,   103,   105,   107,
       9,    16,    62,    93,    99,   100,   101,   102,     3,    12,
      93,    94,    98,     9,    93,    99,   100,    99,   100,   101,
     102,     9,    16,    99,    62,    62,    72,     9,     9,     9,
       3,    13,    68,    69,    70,    94,    62,    55,    11,    55,
      11,    55,    11,    55,    11,    55,    62,    62,    11,    55,
      92,     0,     0,     1,    67,     3,     3,     3,     3,     3,
       9,    39,    42,     3,    15,    16,    17,    18,    19,    20,
      21,    26,    27,    28,    30,    31,    32,    33,    34,    35,
      36,    37,    15,    16,    17,    18,    19,    20,    21,    32,
      33,    34,    35,    36,    37,    21,    32,    33,    34,    35,
      36,    37,    21,    22,    23,    32,    33,    55,    55,     9,
      62,    11,    10,    10,    10,    10,    10,    98,    40,     3,
      12,    99,   100,    99,    99,    15,    16,    17,    18,    19,
      42,    40,    94,    62,    94,    13,    14,    66,    49,    42,
      12,    94,   106,    12,   106,    12,   106,    12,   106,     3,
      13,     9,    12,    94,   106,    39,    67,    10,    91,    94,
      93,    94,    99,   100,    99,   100,    99,   100,    99,   100,
      99,   100,    99,   100,    99,   100,   101,   102,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
     100,    99,   100,    99,   100,    99,   100,    99,   100,    99,
     100,    99,   100,   101,   102,   100,   100,   100,   100,   100,
     100,    99,   100,   101,   102,   101,   102,   101,   101,   101,
     101,   101,    99,   100,   101,   102,   102,   102,   102,   102,
      10,    62,   104,   107,     9,    42,    94,     3,    12,     3,
      98,    12,    99,    99,    99,    99,    99,    94,    62,    10,
      41,    10,    66,    14,     9,    94,    40,    12,    12,    12,
      12,    13,     3,    14,    43,    82,    83,    87,   107,    10,
      85,    86,   107,    12,    12,    93,    10,    40,    11,    10,
      40,    10,    85,    94,    12,    98,    70,    62,   101,    70,
      14,     3,    94,   106,    82,    82,    62,    14,     3,    62,
      69,    10,    40,    40,    62,    92,    91,   104,    69,    10,
      46,    79,    10,    10,     3,    10,    14,    42,    82,    42,
      69,    85,    86,   107,    42,    69,     9,    46,    47,    80,
      70,    70,    94,    94,    62,    94,    94,     9,    70,    10,
      94,    70,    10,    70
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    64,    65,    65,    66,    66,    66,    67,    67,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    69,    69,    69,    69,    69,    70,    70,    71,    72,
      72,    73,    73,    73,    74,    74,    75,    75,    76,    77,
      78,    79,    79,    79,    80,    80,    81,    81,    81,    82,
      82,    82,    82,    83,    83,    83,    84,    84,    84,    84,
      85,    85,    85,    86,    86,    87,    88,    88,    88,    89,
      90,    90,    91,    91,    92,    92,    93,    93,    93,    93,
      93,    94,    94,    94,    94,    95,    95,    95,    96,    96,
      96,    96,    97,    97,    97,    97,    97,    98,    98,    98,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   103,   103,
     104,   104,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   106,   106,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107
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
       2,     1,     3,     4,     3,     2,     4,     4,     4,     3,
       3,     4,     1,     3,     3,     4,     1,     1,     2,     4,
       3,     1,     1,     1,     1,     1,     2,     3,     1,     1,
       1,     1,     2,     3,     4,     4,     5,     1,     3,     4,
       1,     2,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     3,
       1,     3,     4,     3,     4,     3,     4,     3,     4,     3,
       4,     3,     1,     3,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1
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
  "\"var\"", "\"import\"", "\"if\"", "\"elif\"", "\"else\"", "\"for\"",
  "\"while\"", "\"do\"", "\"return\"", "\"break\"", "\"continue\"",
  "\"const\"", "\"?\"", "\"\\\"int\\\"\"", "\"\\\"float\\\"\"",
  "\"\\\"string\\\"\"", "\"\\\"bool\\\"\"", "\"\\\"struct\\\"\"",
  "\"\\\"void\\\"\"", "\"identifier\"", "NEG", "$accept", "start", "stmt",
  "stmts", "stmts_ne", "block", "body", "import", "id_list", "flowctl",
  "return", "for", "while", "dowhile", "if", "elif", "else", "struct",
  "decllist", "declistval", "function", "funargs", "funargdef", "vardecl",
  "vardef", "set", "funcall", "callarglist", "select", "scope", "expr",
  "expr_var", "val", "expr_mat", "matvals", "expr_int", "expr_float",
  "expr_str", "expr_bool", "funtype", "typelist", "mattype", "matsize",
  "type", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   167,   167,   168,   170,   171,   172,   176,   177,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   194,   195,   196,   197,   198,   201,   202,   206,   208,
     209,   213,   214,   215,   217,   218,   222,   223,   227,   230,
     234,   236,   237,   238,   240,   241,   245,   246,   247,   249,
     250,   251,   252,   254,   255,   256,   260,   261,   262,   263,
     265,   266,   267,   269,   270,   274,   278,   279,   280,   284,
     288,   289,   291,   293,   301,   302,   306,   307,   308,   309,
     310,   314,   315,   316,   317,   320,   321,   322,   414,   415,
     416,   417,   421,   422,   423,   424,   425,   427,   428,   429,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   523,   524,
     526,   527,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   542,   543,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561
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
      55,    56,    57,    58,    59,    60,    61,    62,    63
    };
    // Last valid token kind.
    const int code_max = 318;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 13 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
} //  ptc 
#line 2206 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"

#line 564 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    std::cerr << scanner->loc->begin.line << ":" << scanner->loc->begin.column << ": " << err_message << std::endl;
}
