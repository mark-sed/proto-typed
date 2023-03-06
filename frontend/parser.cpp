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
  case 99: // expr_int: "int"
#line 432 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 787 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 100: // expr_int: "-" expr_int
#line 433 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 793 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 101: // expr_int: "(" expr_int ")"
#line 434 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 799 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 102: // expr_int: "~" expr_int
#line 435 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 805 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 103: // expr_int: expr_int "*" expr_int
#line 436 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 811 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 104: // expr_int: expr_int "/" expr_int
#line 437 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 817 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 105: // expr_int: expr_int "%" expr_int
#line 438 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 823 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 106: // expr_int: expr_int "-" expr_int
#line 439 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 829 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 107: // expr_int: expr_int "+" expr_int
#line 440 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 835 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 108: // expr_int: expr_int "<<" expr_int
#line 441 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 841 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 109: // expr_int: expr_int ">>" expr_int
#line 442 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 847 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 110: // expr_int: expr_int "&" expr_int
#line 443 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 853 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 111: // expr_int: expr_int "^" expr_int
#line 444 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 859 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 112: // expr_int: expr_int "|" expr_int
#line 445 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 865 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 113: // expr_float: "float"
#line 449 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 871 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 114: // expr_float: "-" expr_float
#line 450 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 877 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 115: // expr_float: "(" expr_float ")"
#line 451 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 883 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 116: // expr_float: expr_float "**" expr_float
#line 452 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 889 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 117: // expr_float: expr_float "**" expr_int
#line 453 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 895 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 118: // expr_float: expr_int "**" expr_float
#line 454 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 901 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 119: // expr_float: expr_float "*" expr_float
#line 455 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 907 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 120: // expr_float: expr_float "*" expr_int
#line 456 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 913 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 121: // expr_float: expr_int "*" expr_float
#line 457 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 919 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 122: // expr_float: expr_float "/" expr_float
#line 458 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 925 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 123: // expr_float: expr_float "/" expr_int
#line 459 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 931 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 124: // expr_float: expr_int "/" expr_float
#line 460 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 937 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 125: // expr_float: expr_float "%" expr_float
#line 461 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 943 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 126: // expr_float: expr_float "%" expr_int
#line 462 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 949 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 127: // expr_float: expr_int "%" expr_float
#line 463 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 955 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 128: // expr_float: expr_float "-" expr_float
#line 464 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 961 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 129: // expr_float: expr_float "-" expr_int
#line 465 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 967 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 130: // expr_float: expr_int "-" expr_float
#line 466 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 973 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 131: // expr_float: expr_float "+" expr_float
#line 467 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 979 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 132: // expr_float: expr_float "+" expr_int
#line 468 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 985 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 133: // expr_float: expr_int "+" expr_float
#line 469 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 991 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 134: // expr_str: "string"
#line 473 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 997 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 135: // expr_str: "(" expr_str ")"
#line 474 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 1003 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 136: // expr_str: expr_str "++" expr_str
#line 475 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 1009 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 137: // expr_str: expr_str "++" expr_int
#line 476 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 1015 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 138: // expr_str: expr_str "++" expr_float
#line 477 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 1021 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 139: // expr_str: expr_str "++" expr_bool
#line 478 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1027 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 140: // expr_str: expr_int "++" expr_str
#line 479 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 1033 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 141: // expr_str: expr_int "++" expr_int
#line 480 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 1039 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 142: // expr_str: expr_int "++" expr_float
#line 481 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 1045 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 143: // expr_str: expr_int "++" expr_bool
#line 482 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1051 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 144: // expr_str: expr_float "++" expr_str
#line 483 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 1057 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 145: // expr_str: expr_float "++" expr_int
#line 484 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 1063 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 146: // expr_str: expr_float "++" expr_float
#line 485 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 1069 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 147: // expr_str: expr_float "++" expr_bool
#line 486 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1075 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 148: // expr_str: expr_bool "++" expr_str
#line 487 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 1081 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 149: // expr_str: expr_bool "++" expr_int
#line 488 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 1087 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 150: // expr_str: expr_bool "++" expr_float
#line 489 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 1093 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 151: // expr_str: expr_bool "++" expr_bool
#line 490 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1099 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 152: // expr_bool: "bool"
#line 494 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 1105 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 153: // expr_bool: "(" expr_bool ")"
#line 495 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 1111 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 154: // expr_bool: "not" expr_bool
#line 496 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 1117 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 155: // expr_bool: expr_bool "or" expr_bool
#line 497 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 1123 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 156: // expr_bool: expr_bool "and" expr_bool
#line 498 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 1129 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 157: // expr_bool: expr_bool "==" expr_bool
#line 499 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 1135 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 158: // expr_bool: expr_int "==" expr_int
#line 500 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 1141 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 159: // expr_bool: expr_float "==" expr_float
#line 501 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 1147 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 160: // expr_bool: expr_str "==" expr_str
#line 502 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 1153 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 161: // expr_bool: expr_bool "!=" expr_bool
#line 503 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 1159 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 162: // expr_bool: expr_int "!=" expr_int
#line 504 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 1165 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 163: // expr_bool: expr_float "!=" expr_float
#line 505 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 1171 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 164: // expr_bool: expr_str "!=" expr_str
#line 506 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 1177 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 165: // expr_bool: expr_int ">" expr_int
#line 507 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 1183 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 166: // expr_bool: expr_float ">" expr_float
#line 508 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 1189 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 167: // expr_bool: expr_str ">" expr_str
#line 509 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 1195 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 168: // expr_bool: expr_int "<" expr_int
#line 510 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 1201 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 169: // expr_bool: expr_float "<" expr_float
#line 511 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 1207 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 170: // expr_bool: expr_str "<" expr_str
#line 512 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 1213 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 171: // expr_bool: expr_int ">=" expr_int
#line 513 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 1219 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 172: // expr_bool: expr_float ">=" expr_float
#line 514 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 1225 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 173: // expr_bool: expr_str ">=" expr_str
#line 515 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 1231 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 174: // expr_bool: expr_int "<=" expr_int
#line 516 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 1237 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 175: // expr_bool: expr_float "<=" expr_float
#line 517 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 1243 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 176: // expr_bool: expr_str "<=" expr_str
#line 518 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
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


  const short  Parser ::yypact_ninf_ = -287;

  const short  Parser ::yytable_ninf_ = -198;

  const short
   Parser ::yypact_[] =
  {
     478,  -287,  -287,  -287,  -287,  -287,  -287,   610,    21,   673,
     360,   180,   -17,     5,    25,    74,    88,   656,   490,  -287,
    -287,    47,   115,   125,   132,   151,   105,   110,    13,   175,
     417,  -287,  -287,   174,   187,  -287,  -287,  -287,  -287,  -287,
    -287,  -287,   190,   204,   207,  -287,    10,   210,  -287,  -287,
    -287,   947,   993,  1088,   102,  -287,  -287,     8,   360,   158,
     206,    29,   918,   774,   540,   364,   490,  -287,    42,   228,
      91,   158,    42,  -287,  -287,   947,   993,  1088,  -287,   180,
     180,  -287,   229,  -287,   230,   490,   212,   490,   262,   714,
    -287,  -287,   233,  -287,   243,   829,   843,   857,   871,    83,
     278,   900,   251,  -287,  -287,   772,  -287,  -287,  -287,  -287,
    -287,  -287,   429,   231,   490,  -287,   158,   158,   158,   158,
     158,   158,   360,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   158,   158,   158,   158,   158,   158,
     360,   158,   158,   158,   158,   158,   158,   360,   360,   360,
     360,   360,   360,   360,   360,   360,   360,   360,   360,   146,
      11,   490,  -287,  -287,  -287,  -287,  -287,   171,    56,   279,
    -287,  1028,  1128,  1047,  -287,   180,   180,   180,   180,   180,
     490,   240,   295,   265,   299,   772,  -287,   538,   302,   490,
    -287,   273,   304,  -287,   306,  -287,   314,  -287,   322,   301,
     272,   393,  -287,     1,   323,   231,  -287,  -287,   326,   330,
     353,  -287,   412,   618,   412,   618,   352,   355,   352,   355,
     352,   355,  1064,   355,   970,  1000,  1035,   147,   941,  1087,
     614,   904,   904,  1070,  1070,  1070,  1070,  1070,  1070,  1109,
     618,  1109,   618,   268,   355,   268,   355,   268,   355,   268,
     355,   970,  1000,  1035,   147,  1134,  1134,  1134,  1134,  1134,
    1134,   970,  1000,  1035,   147,   521,   102,   521,  -287,  -287,
    -287,  -287,   970,  1000,  1035,   147,   165,   183,  -287,  -287,
    -287,   366,   372,     6,   454,   490,   371,   376,  -287,   490,
    -287,  -287,   121,   121,  -287,  -287,  -287,  -287,  -287,   656,
     668,   656,   598,   388,   490,  -287,   490,  -287,  -287,  -287,
    -287,    72,    72,  -287,   333,   381,   394,  -287,    12,   128,
      44,   361,    14,   206,  -287,   353,  -287,   490,   900,  -287,
     508,   128,    82,  -287,  -287,  -287,   354,   395,   716,  -287,
     400,  -287,   410,  -287,   413,  -287,   401,  -287,    72,   402,
    -287,   128,   508,   508,   405,  -287,  -287,  -287,  -287,   128,
     433,   218,   656,   656,  -287,  -287,  -287,   490,  -287,   490,
    -287,   415,   361,    27,   490,  -287,   490,   443,   656,  -287,
    -287,  -287,  -287,  -287,   405,  -287,   446,   490,  -287,   656,
     447,  -287,   656,  -287
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
       0,     2,     7,    99,   113,   134,   152,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    34,    31,
      32,     0,   193,   194,   195,   196,     0,     0,    76,     0,
       0,     4,     8,     0,     0,    33,    14,    16,    17,    15,
      18,    19,     0,     0,     0,    77,    84,     0,    82,    83,
      81,    87,    88,    89,    90,   198,   199,     0,     0,     0,
      76,     0,     0,     0,     0,     0,     0,    91,    84,    96,
       0,     0,    85,   100,   114,     0,     0,     0,   154,     0,
       0,   102,     0,    29,    28,     0,     0,     0,     0,     0,
      26,    27,     0,    35,     0,     0,     0,     0,     0,     0,
       0,     0,    78,     1,     3,     0,     5,    13,    20,    11,
      12,     9,     0,     0,     0,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,     0,    86,   101,   115,   135,   153,     0,     0,     0,
      92,     0,     0,     0,   100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,     0,     0,
     184,   191,     0,   186,     0,   188,     0,   190,     0,     0,
       0,     0,   182,     0,     0,     0,     6,    70,     0,    72,
      80,    69,   107,   133,   106,   130,   103,   121,   104,   124,
     105,   127,     0,   118,   141,   142,   140,   143,   110,   112,
     111,   108,   109,   158,   162,   165,   168,   171,   174,   132,
     131,   129,   128,   120,   119,   123,   122,   126,   125,   117,
     116,   145,   146,   144,   147,   159,   163,   166,   169,   172,
     175,   137,   138,   136,   139,   160,     0,   164,   167,   170,
     173,   176,   149,   150,   148,   151,   156,   155,   157,   161,
     178,   197,     0,   179,     0,     0,     0,     0,    93,     0,
      97,    94,   107,   106,   103,   104,   105,    68,    30,     0,
       0,     0,     0,    22,     0,    67,     0,   183,   185,   187,
     189,     0,    49,    46,     0,     0,     0,    53,     0,     0,
       0,    61,     0,    74,   181,    79,    71,     0,     0,   177,
       0,     0,     0,    66,    95,    98,    43,     0,     0,    38,
      23,    24,     0,   192,     0,    50,     0,    47,    51,    65,
      58,     0,     0,     0,    60,    75,    73,   180,    56,     0,
       0,    45,     0,     0,    25,    39,    48,     0,    52,     0,
      59,    62,    64,     0,     0,    57,     0,     0,     0,    40,
      36,    37,    55,    54,     0,    63,     0,     0,    44,     0,
       0,    41,     0,    42
  };

  const short
   Parser ::yypgoto_[] =
  {
    -287,  -287,   -88,   -20,     4,   -48,  -286,  -287,  -287,  -287,
    -287,  -287,  -287,  -287,  -287,  -287,  -287,  -287,  -270,  -287,
    -287,  -282,   109,  -192,  -287,  -287,  -287,   131,   156,     0,
       3,  -287,  -287,  -287,   -27,   101,   202,    -4,   258,  -287,
     150,  -287,   -40,  -154
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    29,    30,    31,    90,    91,    92,    33,    84,    34,
      35,    36,    37,    38,    39,   361,   379,    40,   315,   316,
      41,   320,   321,    42,    43,    44,    45,   208,   102,    68,
      47,    48,    49,    50,    70,    51,    52,    53,    54,    55,
     282,    56,   204,    57
  };

  const short
   Parser ::yytable_[] =
  {
      46,   187,   332,    64,    32,   283,    77,    61,   317,    72,
     106,    69,   323,   336,   159,   339,   159,    46,   112,   284,
     159,    93,   159,   101,    66,     3,     4,     5,     6,     7,
      46,     8,    67,    85,    32,   159,     9,   112,   162,   167,
     306,   344,   345,    82,    10,   330,   318,   322,   113,    11,
     112,   114,   285,   351,    64,   192,   194,   196,   198,   289,
       3,     4,     5,     6,     7,    83,     8,   113,   160,    69,
     371,     9,   349,  -197,   354,   312,   380,   381,   368,    10,
     113,    60,    86,   352,    11,   206,   199,   384,   182,    46,
     184,   359,   388,    32,   169,   200,    87,   302,   191,   191,
     191,   191,   170,   391,   203,    46,   393,    94,    62,    32,
      73,    75,    81,   210,   314,   209,    60,   211,   226,   317,
     317,   352,   154,   155,   156,    95,    22,    23,    24,    25,
     322,    88,   281,   157,   158,    96,   253,   177,   178,   179,
      89,   290,    97,   263,   265,   267,   268,   269,   270,   271,
     274,    77,    77,    77,    77,   280,   317,   318,   318,    62,
      73,    98,     3,     4,   286,    99,    71,   106,   155,   156,
     100,    69,   171,    59,   287,   103,   283,   107,   157,   158,
     173,   174,   288,   297,     3,    46,    11,    46,    79,    32,
     108,    32,   305,   109,   318,    80,   157,   158,   322,   373,
      22,    23,    24,    25,   155,   325,   281,   110,    11,    63,
     111,    74,    76,   115,   157,   158,   161,   212,   214,   216,
     218,   220,   222,   224,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   241,   243,   245,   247,
     249,   251,   222,   222,   222,   222,   222,   222,   261,    75,
      75,    75,    75,    75,    75,   272,    75,    75,    75,    75,
      63,    74,   335,   377,   378,    65,   343,   168,    78,   181,
     180,   350,   183,   172,   185,   312,   292,   293,   294,   295,
     296,   188,   106,   358,   189,   313,   201,   121,   333,   205,
     291,    60,    69,   123,   124,   125,   338,   126,   127,    46,
     298,    46,    46,   370,   299,   300,    32,   342,   301,   191,
     304,   375,   306,   311,   314,   307,    65,   308,   213,   215,
     217,   219,   221,   223,   225,   309,    22,    23,    24,    25,
     209,   191,   281,   310,   324,   326,   240,   242,   244,   246,
     248,   250,   252,   255,   256,   257,   258,   259,   260,   262,
      76,    76,    76,    76,    76,    76,   273,    76,    76,    76,
      76,   112,    46,    46,     3,     4,     5,     6,    58,   327,
     382,   121,   383,   166,   139,    59,   328,   385,    46,   386,
     227,   329,   323,    10,   154,   155,   156,   334,    11,    46,
     390,   341,    46,   346,   347,   157,   158,   348,   254,   360,
     353,    75,   319,   364,   362,   264,   266,   266,   266,   266,
     266,   266,   275,   276,   277,   278,   279,   104,   105,   365,
       2,     3,     4,     5,     6,     7,   366,     8,   118,   119,
     120,   121,     9,     3,     4,     5,     6,     7,   207,     8,
      10,   376,   367,   369,     9,    11,   374,    22,    23,    24,
      25,   387,    10,   281,   352,   389,   392,    11,   356,    12,
      13,    14,   372,   331,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     1,   355,
     357,     2,     3,     4,     5,     6,     7,     0,     8,    60,
       0,     0,     0,     9,     3,     4,     5,     6,     7,     0,
       8,    10,    76,     0,     0,     9,    11,     0,    22,    23,
      24,    25,     0,    10,   281,     0,     0,     0,    11,     0,
      12,    13,    14,     0,     0,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,   105,
       0,     2,     3,     4,     5,     6,     7,     0,     8,   165,
      60,   303,     0,     9,   150,   151,   152,   153,   266,     0,
     147,    10,    22,    23,    24,    25,    11,     0,   281,     0,
       0,   148,   149,   150,   151,   152,   153,     0,     0,     0,
      12,    13,    14,     0,     0,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,   105,
       0,     2,     3,     4,     5,     6,     7,     0,     8,     0,
       0,   340,     0,     9,     3,     4,     5,     6,    58,     0,
       0,    10,     0,     0,     0,    59,    11,     0,   175,   176,
     177,   178,   179,    10,   136,   137,   138,   139,    11,   123,
      12,    13,    14,   126,   127,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    88,
       3,     4,     5,     6,     7,     0,     8,     0,    89,     0,
      60,     9,     3,     4,     5,     6,    58,     3,     4,    10,
       0,    71,     0,    59,    11,     0,     0,     0,    59,     0,
       0,    10,     0,     0,     0,     0,    11,     0,    12,    13,
      14,    11,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     2,     3,     4,
       5,     6,     7,     0,     8,   363,     0,   186,   337,     9,
       0,     0,     0,    60,     0,     0,   147,    10,     0,     0,
       0,     0,    11,     0,     0,     0,     0,   148,   149,   150,
     151,   152,   153,     0,     0,     0,    12,    13,    14,     0,
       0,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,     2,     3,     4,     5,     6,
       7,     0,     8,   164,     0,     0,     0,     9,   134,   135,
     136,   137,   138,   139,   140,    10,     0,     0,     0,     0,
      11,     0,     0,     0,     0,   141,   142,   143,   144,   145,
     146,     0,     0,     0,    12,    13,    14,     0,     0,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     3,     4,     5,     6,     7,     0,     8,
     190,     0,     0,     0,     9,     0,     0,     3,     4,     5,
       6,     7,    10,     8,   193,     0,     0,    11,     9,     0,
       0,     3,     4,     5,     6,     7,    10,     8,   195,     0,
       0,    11,     9,     0,     0,     3,     4,     5,     6,     7,
      10,     8,   197,     0,     0,    11,     9,     0,     0,    60,
       0,     0,     0,     0,    10,     0,     0,     0,     0,    11,
       0,     0,     0,    60,     3,     4,     5,     6,     7,     0,
       8,   202,     0,     0,     0,     9,     0,    60,   175,   176,
     177,   178,   179,    10,     0,     0,     0,   163,    11,     0,
       0,    60,   116,   117,   118,   119,   120,   121,   122,     0,
       0,     0,     0,   123,   124,   125,     0,   126,   127,   128,
     129,   130,   131,   132,   133,   175,   176,   177,   178,   179,
      60,   116,   117,   118,   119,   120,   121,   122,     0,     0,
     126,   127,   123,   124,   125,     0,   126,   127,   128,   129,
     130,   131,   132,   133,   116,   117,   118,   119,   120,   121,
       0,     0,     0,     0,     0,   123,   124,   125,     0,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   134,   135,   136,   137,   138,   139,
       0,     0,     0,     0,   141,   142,   143,   144,   145,   146,
       0,   141,   142,   143,   144,   145,   146,   163,     0,     0,
       0,     0,   116,   117,   118,   119,   120,   121,     0,     0,
       0,     0,     0,   123,   124,   125,   163,   126,   127,     0,
       0,   175,   176,   177,   178,   179,   148,   149,   150,   151,
     152,   153,   123,   124,   125,     0,   126,   127,   116,   117,
     118,   119,   120,   121,   175,   176,   177,   178,   179,   123,
     124,   125,     0,   126,   127,   123,   124,   125,     0,   126,
     127,   175,   176,   177,   178,   179,     0,     0,   147,     0,
       0,     0,   123,     0,   125,     0,   126,   127,     0,   148,
     149,   150,   151,   152,   153,   118,   119,   120,   121,     0,
       0,     0,     0,     0,   123,   124,   125,   164,   126,   127,
       0,     0,   134,   135,   136,   137,   138,   139,   134,   135,
     136,   137,   138,   139
  };

  const short
   Parser ::yycheck_[] =
  {
       0,    89,   284,     7,     0,   159,    10,     7,   200,     9,
      30,     8,    11,   299,     8,   301,     8,    17,     8,     8,
       8,    18,     8,    10,     3,     4,     5,     6,     7,     8,
      30,    10,    11,     8,    30,     8,    15,     8,     9,    66,
      39,   311,   312,    60,    23,    39,   200,   201,    38,    28,
       8,    41,    41,     9,    58,    95,    96,    97,    98,     3,
       4,     5,     6,     7,     8,    60,    10,    38,    60,    66,
     352,    15,    60,    60,    60,     3,   362,   363,   348,    23,
      38,    60,     8,    39,    28,   105,     3,    60,    85,    89,
      87,     9,   378,    89,     3,    12,     8,   185,    95,    96,
      97,    98,    11,   389,   101,   105,   392,    60,     7,   105,
       9,    10,    11,   113,    42,   112,    60,   114,   122,   311,
     312,    39,    20,    21,    22,    10,    54,    55,    56,    57,
     284,     3,    60,    31,    32,    10,   140,    16,    17,    18,
      12,   168,    10,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,     9,   348,   311,   312,    58,
      59,    10,     4,     5,   161,    60,     8,   187,    21,    22,
      60,   168,    71,    15,     3,     0,   330,     3,    31,    32,
      79,    80,    11,   180,     4,   185,    28,   187,     8,   185,
       3,   187,   189,     3,   348,    15,    31,    32,   352,   353,
      54,    55,    56,    57,    21,   205,    60,     3,    28,     7,
       3,     9,    10,     3,    31,    32,    10,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      58,    59,   289,    45,    46,     7,   306,    39,    10,    39,
      41,   319,    60,    71,    12,     3,   175,   176,   177,   178,
     179,    48,   302,   331,    41,    13,     8,    19,   285,    38,
      11,    60,   289,    25,    26,    27,   300,    29,    30,   299,
      60,   301,   302,   351,     9,    40,   302,   304,     9,   306,
       8,   359,    39,    12,    42,    11,    58,    11,   116,   117,
     118,   119,   120,   121,   122,    11,    54,    55,    56,    57,
     327,   328,    60,    11,    11,     9,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,     8,   362,   363,     4,     5,     6,     7,     8,    39,
     367,    19,   369,     9,    19,    15,    10,   374,   378,   376,
     122,     9,    11,    23,    20,    21,    22,    11,    28,   389,
     387,     3,   392,    60,    13,    31,    32,     3,   140,    45,
      39,   300,     9,     3,     9,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,     0,     1,     9,
       3,     4,     5,     6,     7,     8,    13,    10,    16,    17,
      18,    19,    15,     4,     5,     6,     7,     8,     9,    10,
      23,     8,    41,    41,    15,    28,    41,    54,    55,    56,
      57,     8,    23,    60,    39,     9,     9,    28,   327,    42,
      43,    44,   353,     9,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,     0,   323,
     330,     3,     4,     5,     6,     7,     8,    -1,    10,    60,
      -1,    -1,    -1,    15,     4,     5,     6,     7,     8,    -1,
      10,    23,   300,    -1,    -1,    15,    28,    -1,    54,    55,
      56,    57,    -1,    23,    60,    -1,    -1,    -1,    28,    -1,
      42,    43,    44,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,     9,
      60,    13,    -1,    15,    33,    34,    35,    36,   300,    -1,
      20,    23,    54,    55,    56,    57,    28,    -1,    60,    -1,
      -1,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      42,    43,    44,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    13,    -1,    15,     4,     5,     6,     7,     8,    -1,
      -1,    23,    -1,    -1,    -1,    15,    28,    -1,    14,    15,
      16,    17,    18,    23,    16,    17,    18,    19,    28,    25,
      42,    43,    44,    29,    30,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    12,    -1,
      60,    15,     4,     5,     6,     7,     8,     4,     5,    23,
      -1,     8,    -1,    15,    28,    -1,    -1,    -1,    15,    -1,
      -1,    23,    -1,    -1,    -1,    -1,    28,    -1,    42,    43,
      44,    28,    -1,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,     3,     4,     5,
       6,     7,     8,    -1,    10,     9,    -1,    13,    60,    15,
      -1,    -1,    -1,    60,    -1,    -1,    20,    23,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    42,    43,    44,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,     3,     4,     5,     6,     7,
       8,    -1,    10,     9,    -1,    -1,    -1,    15,    14,    15,
      16,    17,    18,    19,    20,    23,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    42,    43,    44,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    15,    -1,    -1,     4,     5,     6,
       7,     8,    23,    10,    11,    -1,    -1,    28,    15,    -1,
      -1,     4,     5,     6,     7,     8,    23,    10,    11,    -1,
      -1,    28,    15,    -1,    -1,     4,     5,     6,     7,     8,
      23,    10,    11,    -1,    -1,    28,    15,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    60,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    15,    -1,    60,    14,    15,
      16,    17,    18,    23,    -1,    -1,    -1,     9,    28,    -1,
      -1,    60,    14,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    25,    26,    27,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    14,    15,    16,    17,    18,
      60,    14,    15,    16,    17,    18,    19,    20,    -1,    -1,
      29,    30,    25,    26,    27,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    14,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    -1,    -1,    25,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    14,    15,    16,
      17,    18,    19,    20,    14,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      -1,    31,    32,    33,    34,    35,    36,     9,    -1,    -1,
      -1,    -1,    14,    15,    16,    17,    18,    19,    -1,    -1,
      -1,    -1,    -1,    25,    26,    27,     9,    29,    30,    -1,
      -1,    14,    15,    16,    17,    18,    31,    32,    33,    34,
      35,    36,    25,    26,    27,    -1,    29,    30,    14,    15,
      16,    17,    18,    19,    14,    15,    16,    17,    18,    25,
      26,    27,    -1,    29,    30,    25,    26,    27,    -1,    29,
      30,    14,    15,    16,    17,    18,    -1,    -1,    20,    -1,
      -1,    -1,    25,    -1,    27,    -1,    29,    30,    -1,    31,
      32,    33,    34,    35,    36,    16,    17,    18,    19,    -1,
      -1,    -1,    -1,    -1,    25,    26,    27,     9,    29,    30,
      -1,    -1,    14,    15,    16,    17,    18,    19,    14,    15,
      16,    17,    18,    19
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,     0,     3,     4,     5,     6,     7,     8,    10,    15,
      23,    28,    42,    43,    44,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    63,
      64,    65,    66,    69,    71,    72,    73,    74,    75,    76,
      79,    82,    85,    86,    87,    88,    91,    92,    93,    94,
      95,    97,    98,    99,   100,   101,   103,   105,     8,    15,
      60,    91,    97,    98,    99,   100,     3,    11,    91,    92,
      96,     8,    91,    97,    98,    97,    98,    99,   100,     8,
      15,    97,    60,    60,    70,     8,     8,     8,     3,    12,
      66,    67,    68,    92,    60,    10,    10,    10,    10,    60,
      60,    10,    90,     0,     0,     1,    65,     3,     3,     3,
       3,     3,     8,    38,    41,     3,    14,    15,    16,    17,
      18,    19,    20,    25,    26,    27,    29,    30,    31,    32,
      33,    34,    35,    36,    14,    15,    16,    17,    18,    19,
      20,    31,    32,    33,    34,    35,    36,    20,    31,    32,
      33,    34,    35,    36,    20,    21,    22,    31,    32,     8,
      60,    10,     9,     9,     9,     9,     9,    96,    39,     3,
      11,    97,    98,    97,    97,    14,    15,    16,    17,    18,
      41,    39,    92,    60,    92,    12,    13,    64,    48,    41,
      11,    92,   104,    11,   104,    11,   104,    11,   104,     3,
      12,     8,    11,    92,   104,    38,    65,     9,    89,    92,
      91,    92,    97,    98,    97,    98,    97,    98,    97,    98,
      97,    98,    97,    98,    97,    98,    99,   100,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      98,    97,    98,    97,    98,    97,    98,    97,    98,    97,
      98,    97,    98,    99,   100,    98,    98,    98,    98,    98,
      98,    97,    98,    99,   100,    99,   100,    99,    99,    99,
      99,    99,    97,    98,    99,   100,   100,   100,   100,   100,
       9,    60,   102,   105,     8,    41,    92,     3,    11,     3,
      96,    11,    97,    97,    97,    97,    97,    92,    60,     9,
      40,     9,    64,    13,     8,    92,    39,    11,    11,    11,
      11,    12,     3,    13,    42,    80,    81,    85,   105,     9,
      83,    84,   105,    11,    11,    91,     9,    39,    10,     9,
      39,     9,    83,    92,    11,    96,    68,    60,    99,    68,
      13,     3,    92,   104,    80,    80,    60,    13,     3,    60,
      67,     9,    39,    39,    60,    90,    89,   102,    67,     9,
      45,    77,     9,     9,     3,     9,    13,    41,    80,    41,
      67,    83,    84,   105,    41,    67,     8,    45,    46,    78,
      68,    68,    92,    92,    60,    92,    92,     8,    68,     9,
      92,    68,     9,    68
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    62,    63,    63,    64,    64,    64,    65,    65,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    67,    67,    67,    67,    67,    68,    68,    69,    70,
      70,    71,    71,    71,    72,    72,    73,    73,    74,    75,
      76,    77,    77,    77,    78,    78,    79,    79,    79,    80,
      80,    80,    80,    81,    81,    81,    82,    82,    82,    82,
      83,    83,    83,    84,    84,    85,    86,    86,    86,    87,
      88,    88,    89,    89,    90,    90,    91,    91,    91,    91,
      91,    92,    92,    92,    93,    93,    93,    94,    94,    94,
      94,    95,    95,    95,    95,    95,    96,    96,    96,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   101,   101,   102,
     102,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   104,   104,   105,   105,   105,   105,   105,   105,   105
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
       3,     1,     1,     1,     1,     2,     3,     1,     1,     1,
       1,     2,     3,     4,     4,     5,     1,     3,     4,     1,
       2,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     3,     1,
       3,     4,     3,     4,     3,     4,     3,     4,     3,     4,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"",
  "\"terminator (\\\\n or ;)\"", "\"int\"", "\"float\"", "\"string\"",
  "\"bool\"", "\"(\"", "\")\"", "\"[\"", "\"]\"", "\"{\"", "\"}\"",
  "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"%\"", "\"**\"", "\"++\"",
  "\"and\"", "\"or\"", "\"not\"", "\"in\"", "\"&\"", "\"|\"", "\"^\"",
  "\"~\"", "\"<<\"", "\">>\"", "\"==\"", "\"!=\"", "\">\"", "\"<\"",
  "\">=\"", "\"<=\"", "\"..\"", "\".\"", "\",\"", "\":\"", "\"=\"",
  "\"var\"", "\"import\"", "\"if\"", "\"elif\"", "\"else\"", "\"for\"",
  "\"while\"", "\"do\"", "\"return\"", "\"break\"", "\"continue\"",
  "\"const\"", "\"\\\"int\\\"\"", "\"\\\"float\\\"\"",
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
     310,   314,   315,   316,   319,   320,   321,   413,   414,   415,
     416,   420,   421,   422,   423,   424,   426,   427,   428,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   522,   523,   525,
     526,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   541,   542,   546,   547,   548,   549,   550,   551,   552
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
      55,    56,    57,    58,    59,    60,    61
    };
    // Last valid token kind.
    const int code_max = 316;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 13 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
} //  ptc 
#line 2194 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"

#line 555 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    std::cerr << scanner->loc->begin.line << ":" << scanner->loc->begin.column << ": " << err_message << std::endl;
}
