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
  case 286: // expr_int: "int"
#line 575 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 787 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 287: // expr_int: "-" expr_int
#line 576 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 793 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 288: // expr_int: "(" expr_int ")"
#line 577 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 799 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 289: // expr_int: "~" expr_int
#line 578 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 805 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 290: // expr_int: expr_int "*" expr_int
#line 579 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 811 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 291: // expr_int: expr_int "/" expr_int
#line 580 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 817 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 292: // expr_int: expr_int "%" expr_int
#line 581 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 823 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 293: // expr_int: expr_int "-" expr_int
#line 582 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 829 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 294: // expr_int: expr_int "+" expr_int
#line 583 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 835 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 295: // expr_int: expr_int "<<" expr_int
#line 584 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 841 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 296: // expr_int: expr_int ">>" expr_int
#line 585 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 847 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 297: // expr_int: expr_int "&" expr_int
#line 586 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 853 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 298: // expr_int: expr_int "^" expr_int
#line 587 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 859 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 299: // expr_int: expr_int "|" expr_int
#line 588 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 865 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 300: // expr_float: "float"
#line 592 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 871 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 301: // expr_float: "-" expr_float
#line 593 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 877 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 302: // expr_float: "(" expr_float ")"
#line 594 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 883 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 303: // expr_float: expr_float "**" expr_float
#line 595 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 889 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 304: // expr_float: expr_float "**" expr_int
#line 596 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 895 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 305: // expr_float: expr_int "**" expr_float
#line 597 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 901 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 306: // expr_float: expr_float "*" expr_float
#line 598 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 907 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 307: // expr_float: expr_float "*" expr_int
#line 599 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 913 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 308: // expr_float: expr_int "*" expr_float
#line 600 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 919 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 309: // expr_float: expr_float "/" expr_float
#line 601 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 925 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 310: // expr_float: expr_float "/" expr_int
#line 602 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 931 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 311: // expr_float: expr_int "/" expr_float
#line 603 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 937 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 312: // expr_float: expr_float "%" expr_float
#line 604 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 943 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 313: // expr_float: expr_float "%" expr_int
#line 605 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 949 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 314: // expr_float: expr_int "%" expr_float
#line 606 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 955 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 315: // expr_float: expr_float "-" expr_float
#line 607 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 961 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 316: // expr_float: expr_float "-" expr_int
#line 608 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 967 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 317: // expr_float: expr_int "-" expr_float
#line 609 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 973 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 318: // expr_float: expr_float "+" expr_float
#line 610 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 979 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 319: // expr_float: expr_float "+" expr_int
#line 611 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 985 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 320: // expr_float: expr_int "+" expr_float
#line 612 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 991 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 321: // expr_str: "string"
#line 616 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 997 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 322: // expr_str: "(" expr_str ")"
#line 617 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 1003 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 323: // expr_str: expr_str "++" expr_str
#line 618 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 1009 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 324: // expr_str: expr_str "++" expr_int
#line 619 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 1015 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 325: // expr_str: expr_str "++" expr_float
#line 620 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 1021 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 326: // expr_str: expr_str "++" expr_bool
#line 621 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1027 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 327: // expr_str: expr_str "++" expr_none
#line 622 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 1033 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 328: // expr_str: expr_int "++" expr_str
#line 623 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 1039 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 329: // expr_str: expr_int "++" expr_int
#line 624 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 1045 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 330: // expr_str: expr_int "++" expr_float
#line 625 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 1051 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 331: // expr_str: expr_int "++" expr_bool
#line 626 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1057 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 332: // expr_str: expr_int "++" expr_none
#line 627 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 1063 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 333: // expr_str: expr_float "++" expr_str
#line 628 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 1069 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 334: // expr_str: expr_float "++" expr_int
#line 629 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 1075 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 335: // expr_str: expr_float "++" expr_float
#line 630 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 1081 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 336: // expr_str: expr_float "++" expr_bool
#line 631 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1087 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 337: // expr_str: expr_float "++" expr_none
#line 632 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 1093 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 338: // expr_str: expr_bool "++" expr_str
#line 633 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 1099 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 339: // expr_str: expr_bool "++" expr_int
#line 634 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 1105 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 340: // expr_str: expr_bool "++" expr_float
#line 635 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 1111 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 341: // expr_str: expr_bool "++" expr_bool
#line 636 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1117 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 342: // expr_str: expr_bool "++" expr_none
#line 637 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 1123 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 343: // expr_str: expr_none "++" expr_str
#line 638 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 1129 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 344: // expr_str: expr_none "++" expr_int
#line 639 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 1135 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 345: // expr_str: expr_none "++" expr_float
#line 640 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 1141 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 346: // expr_str: expr_none "++" expr_bool
#line 641 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1147 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 347: // expr_str: expr_none "++" expr_none
#line 642 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 1153 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 348: // expr_bool: "bool"
#line 646 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 1159 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 349: // expr_bool: "(" expr_bool ")"
#line 647 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 1165 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 350: // expr_bool: "not" expr_bool
#line 648 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 1171 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 351: // expr_bool: expr_bool "or" expr_bool
#line 649 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 1177 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 352: // expr_bool: expr_bool "and" expr_bool
#line 650 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 1183 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 353: // expr_bool: expr_bool "==" expr_bool
#line 652 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 1189 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 354: // expr_bool: expr_int "==" expr_int
#line 653 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 1195 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 355: // expr_bool: expr_int "==" expr_float
#line 654 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 1201 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 356: // expr_bool: expr_float "==" expr_float
#line 655 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 1207 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 357: // expr_bool: expr_float "==" expr_int
#line 656 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 1213 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 358: // expr_bool: expr_str "==" expr_str
#line 657 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 1219 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 359: // expr_bool: expr_none "==" expr_none
#line 658 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 1225 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 360: // expr_bool: expr_bool "!=" expr_bool
#line 660 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 1231 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 361: // expr_bool: expr_int "!=" expr_int
#line 661 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 1237 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 362: // expr_bool: expr_int "!=" expr_float
#line 662 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 1243 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 363: // expr_bool: expr_float "!=" expr_float
#line 663 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 1249 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 364: // expr_bool: expr_float "!=" expr_int
#line 664 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 1255 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 365: // expr_bool: expr_str "!=" expr_str
#line 665 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 1261 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 366: // expr_bool: expr_none "!=" expr_none
#line 666 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 1267 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 367: // expr_bool: expr_int ">" expr_int
#line 668 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 1273 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 368: // expr_bool: expr_int ">" expr_float
#line 669 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 1279 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 369: // expr_bool: expr_float ">" expr_float
#line 670 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 1285 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 370: // expr_bool: expr_float ">" expr_int
#line 671 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 1291 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 371: // expr_bool: expr_str ">" expr_str
#line 672 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 1297 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 372: // expr_bool: expr_int "<" expr_int
#line 674 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 1303 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 373: // expr_bool: expr_int "<" expr_float
#line 675 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 1309 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 374: // expr_bool: expr_float "<" expr_float
#line 676 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 1315 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 375: // expr_bool: expr_float "<" expr_int
#line 677 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 1321 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 376: // expr_bool: expr_str "<" expr_str
#line 678 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 1327 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 377: // expr_bool: expr_int ">=" expr_int
#line 680 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 1333 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 378: // expr_bool: expr_int ">=" expr_float
#line 681 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 1339 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 379: // expr_bool: expr_float ">=" expr_float
#line 682 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 1345 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 380: // expr_bool: expr_float ">=" expr_int
#line 683 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 1351 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 381: // expr_bool: expr_str ">=" expr_str
#line 684 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 1357 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 382: // expr_bool: expr_int "<=" expr_int
#line 686 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 1363 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 383: // expr_bool: expr_int "<=" expr_float
#line 687 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 1369 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 384: // expr_bool: expr_float "<=" expr_float
#line 688 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 1375 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 385: // expr_bool: expr_float "<=" expr_int
#line 689 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 1381 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 386: // expr_bool: expr_str "<=" expr_str
#line 690 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 1387 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 387: // expr_bool: expr_str "in" expr_str
#line 692 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[0].value.as < std::string > ().find(yystack_[2].value.as < std::string > ()) != std::string::npos; }
#line 1393 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;


#line 1397 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -707;

  const short  Parser ::yytable_ninf_ = -417;

  const short
   Parser ::yypact_[] =
  {
    1593,  -707,  -707,  -707,  -707,  -707,  -707,  -707,   836,    34,
      43,   769,   182,   -45,    -8,    66,    68,    71,  2355,   947,
    -707,  -707,    13,    57,    16,    17,    18,    33,    52,    74,
      49,   170,  1517,  -707,  -707,   172,   173,  -707,  -707,  -707,
    -707,  -707,  -707,  -707,   196,   203,   205,  -707,  1290,   228,
    1929,  -707,  -707,   410,    36,   125,  1864,  1333,   549,   272,
     105,   142,    -2,   226,  1001,   143,   109,    61,   281,   193,
    1476,  1595,   449,   180,   947,  -707,   109,    -3,   210,   116,
     143,   271,    -3,  -707,  -707,  2473,  1897,   616,  -707,   182,
     182,  -707,   254,  -707,   262,   947,   232,   947,   290,  2385,
    -707,  -707,   250,  -707,   276,  -707,   412,  -707,   533,  -707,
     678,  -707,  1124,  -707,   118,   313,  1205,    64,  -707,   292,
    -707,  -707,  -707,  2458,  -707,  -707,  -707,  -707,  -707,  -707,
     652,   258,   947,   947,   947,   947,   947,   947,   947,   947,
     947,   947,   947,   947,   947,   947,  -707,   947,   947,   947,
     947,   947,   947,   947,   947,   947,   947,   947,   947,   947,
     947,   947,   947,   947,   947,   947,   947,   947,   947,   947,
     947,   947,   947,   947,   947,   947,   947,   947,   947,   947,
     947,   947,   947,   947,   947,   947,   947,   143,   947,   947,
     947,   947,   947,   947,   947,   947,   947,   947,   947,   947,
     947,   947,   947,   947,   947,   947,   947,   947,   947,   947,
     947,   947,   947,   947,   947,   947,   947,   947,   947,   947,
     947,   947,   947,   947,   947,   947,   947,   947,   947,  -707,
    -707,    21,    24,  -707,   947,   325,  -707,  -707,   769,   146,
     146,  -707,   143,   143,   143,   143,   143,   769,   182,   182,
     182,   182,   182,   143,   143,   143,   143,   143,   143,  -707,
     143,   143,   143,   143,   143,   143,   769,   143,   143,   143,
     143,   143,   143,  -707,   769,   769,   769,   769,   769,   769,
     769,   769,  -707,   769,   769,   769,   769,   769,   165,   176,
     327,  -707,  2711,  1090,   366,  -707,   182,   182,   182,   182,
     182,   947,   278,   370,   296,   378,  2458,  -707,  1677,   392,
     947,  -707,   368,   397,  -707,   399,  -707,   401,  -707,   417,
     409,   190,   245,  -707,    11,   418,  -707,   362,   424,   258,
    -707,  -707,   430,   404,   436,  -707,  -707,  -707,  -707,  -707,
    -707,  -707,  -707,  -707,  -707,  -707,  -707,  -707,  -707,  -707,
     509,   429,    36,   125,   559,   587,   549,   272,   509,   429,
     559,   587,   440,  -707,   441,   453,   440,   410,   441,   453,
     440,   441,   453,   440,  1864,   453,  2136,   164,   212,  2519,
    1049,   902,   431,  2542,  1333,   216,  2159,   447,  2565,   338,
    1679,  2680,  1805,  2611,  2634,  2657,   476,  1030,   476,  1030,
    1155,   256,  -707,  -707,  2688,  1446,   664,  -707,  1155,   256,
    -707,  -707,  2688,  1446,   664,  -707,   698,   886,  1285,  -707,
     698,   886,  1285,  -707,   698,   886,  1285,  -707,   698,   886,
    1285,  -707,   509,   429,   509,   429,   440,  -707,  2565,   237,
    1155,   256,  1155,   256,  2136,   164,   212,  2519,  1049,   902,
     431,  2565,   237,  1155,  -707,  1155,  -707,  2136,   164,   212,
    2519,  1049,   902,   431,  2565,   237,  1155,  -707,  1155,  -707,
     509,   559,   587,   509,   559,   587,   440,   441,   453,   440,
     441,   453,   440,   441,   453,  2182,   458,  2136,   164,   212,
    2519,  1049,   902,   431,  2565,   237,  1679,  2680,  1805,  2611,
    2634,  2657,   476,  1030,   476,  1030,  1155,  2688,  1446,  1155,
    2688,  1446,   698,   886,  1285,   698,   886,  1285,   698,   886,
    1285,   698,   886,  1285,   509,   559,   587,   509,   559,   587,
     440,   441,   453,   440,   441,   453,   440,   441,   453,   440,
     441,   453,  2136,   164,   212,  2519,  1049,   902,   431,  2565,
     237,  1155,  2688,  1446,  1155,  2688,  1446,   698,   886,  1285,
     698,   886,  1285,   698,   886,  1285,   698,   886,  1285,  2136,
     164,   212,  2519,  1049,   902,   431,  2565,   237,   338,  1155,
     664,  1155,   664,   698,  -707,   698,  -707,   698,  -707,   698,
    -707,  2136,   164,   212,  2519,  1049,   902,   431,  2542,   216,
    2159,   447,  2565,   237,  1155,  -707,  1155,  -707,  -707,    45,
     467,    25,   280,   802,   438,  -707,   162,  2588,   309,   959,
     367,   459,  -707,  -707,   604,   737,   604,   737,   441,   458,
     441,   458,   441,   458,   162,  2588,   309,   959,   367,  1706,
    1748,  1209,   817,   817,  1622,  1439,  1622,  1439,  1622,  1439,
    1622,  1439,  1622,  1439,  1622,  1439,   604,   737,   604,   737,
     441,   458,   441,   458,   441,   458,   441,   458,   162,  2588,
     309,   959,   367,  1622,  1439,  1622,  1439,  1622,  1439,  1622,
    1439,  1622,  1439,  1622,  1439,   162,  2588,   309,   959,   367,
    1524,   207,   787,   787,  -707,  -707,  -707,  -707,   162,  2588,
     309,   959,   367,   231,   235,  -707,  -707,   485,  -707,   947,
    -707,  -707,   415,   415,  -707,  -707,  -707,  -707,  -707,  2355,
    1027,  2355,  1803,   503,   947,  -707,   947,  -707,  -707,  -707,
    -707,   335,   335,  -707,   413,   498,   519,  -707,     1,   158,
      15,   484,     8,   271,  -707,   491,  -707,   436,  -707,   947,
    1205,  -707,   448,   158,    39,  -707,  -707,   226,  -707,  -707,
     477,   536,   593,  -707,   544,  -707,   540,  -707,   550,  -707,
     516,  -707,   335,   524,  -707,   158,   448,   448,   526,  -707,
     947,  -707,  -707,  -707,   158,   562,   240,  2355,  2355,  -707,
    -707,  -707,   947,  -707,   947,  -707,   532,   484,    12,   947,
     548,  -707,   947,   600,  2355,  -707,  -707,  -707,  -707,  -707,
     526,  -707,   572,   602,   947,  -707,  -707,  2355,   605,  -707,
    2355,  -707
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     7,   286,   300,   321,   348,   278,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      31,    32,     0,     0,   412,   413,   414,   415,     0,     0,
      91,     0,     0,     4,     8,     0,     0,    33,    14,    16,
      17,    15,    18,    19,     0,     0,     0,    92,   101,     0,
      97,   100,   276,    96,    98,    99,   264,   265,   266,   267,
     417,   418,     0,   278,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,   268,    91,   101,   273,     0,
       0,    91,   102,   287,   301,     0,     0,     0,   350,     0,
       0,   289,     0,    29,    28,     0,     0,     0,     0,     0,
      26,    27,     0,    35,     0,   404,     0,   405,     0,   406,
       0,   407,     0,   408,     0,     0,     0,     0,   409,    93,
     280,     1,     3,     0,     5,    13,    20,    11,    12,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   410,
     411,     0,    65,   279,     0,     0,   103,   277,     0,     0,
       0,   288,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   302,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   322,     0,     0,     0,     0,     0,     0,
       0,     0,   349,     0,     0,     0,     0,     0,     0,     0,
       0,   269,     0,     0,     0,   287,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,     0,     0,
       0,   395,   402,     0,   397,     0,   399,     0,   401,     0,
       0,     0,     0,   393,     0,     0,   282,     0,     0,     0,
       6,    85,     0,    87,    95,    84,    83,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
     132,   130,     0,     0,   127,   128,     0,     0,   140,   138,
     135,   136,   114,   113,   109,   110,   119,     0,   117,   118,
     124,   122,   123,   106,     0,   105,   263,   261,   262,   257,
     258,   259,   260,   236,     0,   235,   239,   238,   233,   232,
     211,   210,   217,   216,   214,   213,   143,   142,   146,   145,
     191,   189,   186,   187,   182,   183,   184,   185,   208,   206,
     203,   204,   199,   200,   201,   202,   153,   150,   151,   152,
     167,   164,   165,   166,   160,   157,   158,   159,   174,   171,
     172,   173,   131,   129,   139,   137,   112,   111,   231,   224,
     190,   188,   207,   205,   255,   347,   244,   344,   345,   343,
     346,   229,   222,   179,   359,   196,   366,   256,   249,   250,
     245,   246,   247,   248,   230,   223,   181,   180,   198,   197,
     125,   294,   320,   133,   293,   317,   107,   290,   308,   115,
     291,   311,   120,   292,   314,     0,   305,   251,   332,   240,
     329,   330,   328,   331,   225,   218,   209,   297,   215,   299,
     212,   298,   141,   295,   144,   296,   175,   354,   355,   192,
     361,   362,   147,   367,   368,   161,   372,   373,   154,   377,
     378,   168,   382,   383,   126,   319,   318,   134,   316,   315,
     108,   307,   306,   116,   310,   309,   121,   313,   312,   104,
     304,   303,   252,   337,   241,   334,   335,   333,   336,   226,
     219,   176,   357,   356,   193,   364,   363,   148,   370,   369,
     162,   375,   374,   155,   380,   379,   169,   385,   384,   253,
     327,   242,   324,   325,   323,   326,   227,   220,   387,   177,
     358,   194,   365,   149,   371,   163,   376,   156,   381,   170,
     386,   254,   342,   243,   339,   340,   338,   341,   234,   352,
     237,   351,   228,   221,   178,   353,   195,   360,   389,   416,
       0,   390,     0,     0,     0,   281,   347,   344,   345,   343,
     346,     0,   359,   366,   294,   320,   293,   317,   290,   308,
     291,   311,   292,   314,   332,   329,   330,   328,   331,   297,
     299,   298,   295,   296,   354,   355,   361,   362,   367,   368,
     372,   373,   377,   378,   382,   383,   319,   318,   316,   315,
     307,   306,   310,   309,   313,   312,   304,   303,   337,   334,
     335,   333,   336,   357,   356,   364,   363,   370,   369,   375,
     374,   380,   379,   385,   384,   327,   324,   325,   323,   326,
     387,     0,   358,   365,   371,   376,   381,   386,   342,   339,
     340,   338,   341,   352,   351,   353,   360,     0,   270,     0,
     274,   271,   294,   293,   290,   291,   292,    69,    30,     0,
       0,     0,     0,    22,     0,    68,     0,   394,   396,   398,
     400,     0,    49,    46,     0,     0,     0,    53,     0,     0,
       0,    61,     0,    89,   392,     0,   283,    94,    86,     0,
       0,   388,     0,     0,     0,    67,    66,     0,   272,   275,
      43,     0,     0,    38,    23,    24,     0,   403,     0,    50,
       0,    47,    51,    65,    58,     0,     0,     0,    60,    90,
       0,    88,   391,    56,     0,     0,    45,     0,     0,    25,
      39,    48,     0,    52,     0,    59,    62,    64,     0,     0,
     284,    57,     0,     0,     0,    40,    36,    37,    55,    54,
       0,    63,     0,     0,     0,    44,   285,     0,     0,    41,
       0,    42
  };

  const short
   Parser ::yypgoto_[] =
  {
    -707,  -707,   -97,   -16,     3,  -624,  -706,  -707,  -707,  -707,
    -707,  -707,  -707,  -707,  -707,  -707,  -707,  -707,  -678,  -707,
    -707,  -607,  -161,  -317,  -707,   500,  -707,  -132,  -107,   543,
    1178,  1225,  -707,   630,   -62,   751,   457,   981,   -65,  -173,
    1846,  2070,     0,   224,  -707,  -109,  -707,   -86,  -217
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    31,    32,    33,   100,   101,   102,    35,    94,    36,
      37,    38,    39,    40,    41,   786,   805,    42,   735,   736,
      43,   740,   741,    44,    45,    46,    47,   332,   119,    77,
      49,    50,    51,    52,    79,   367,   352,   353,   120,   328,
      56,    57,   356,   357,    60,   610,    61,   325,    62
  };

  const short
   Parser ::yytable_[] =
  {
      58,   235,   308,    34,   737,   754,   130,   231,    72,    58,
     231,    87,   288,   760,   611,   763,   124,   231,    58,    58,
     313,   231,   315,   743,   317,   775,   319,   106,   108,   110,
      92,   608,    58,   612,   231,    34,   131,    74,     3,     4,
       5,     6,     7,     8,   112,     9,    75,     3,     4,   784,
      10,   726,    80,   768,   769,   776,   750,   174,    11,    65,
     116,   175,   117,    12,    72,   752,   613,    93,   176,   177,
     130,   236,    12,   232,    58,    95,   773,    96,   326,   776,
      97,   806,   807,   778,   107,   109,   111,   810,   104,    23,
      24,    25,    26,    27,   793,    58,   609,    58,   815,    58,
     131,   113,    34,   327,   738,   742,    58,   330,    58,    76,
      58,   819,    58,   118,   821,   774,    58,   118,    81,   290,
     234,   320,   117,    58,  -416,   105,    34,   114,   291,   783,
      58,   321,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,   178,     3,     4,   115,
     179,   795,    80,   381,     7,   621,   389,   180,   181,    65,
     801,    98,   406,   414,   419,   423,   427,   431,   707,   796,
     121,    99,    12,   229,   449,   125,   126,   708,   462,   709,
       3,     4,     5,     6,     7,     8,     3,     9,   492,   175,
     282,    89,    10,   732,   239,   240,   176,   177,    90,   127,
      11,   283,   284,   285,   733,    12,   128,   547,   129,   722,
     230,    12,   286,   287,   238,   574,   578,   580,   582,   584,
     586,   588,   590,   596,    59,   239,   240,   710,   283,   284,
     285,   146,    73,    59,    58,    88,   233,   179,   619,   286,
     287,   226,    59,    59,   180,   181,   734,   637,   227,   228,
     289,    76,   168,   169,   170,   739,    59,   284,    23,    24,
      25,    26,    27,   286,   287,   609,   671,   286,   287,   172,
     173,   168,   169,   170,   688,   690,   692,   693,   694,   695,
     696,   697,   234,   701,    87,    87,    87,    87,    73,    58,
     753,   237,   124,   223,   224,   225,   301,   226,    59,   803,
     804,    58,   302,   306,   227,   228,    58,   304,    58,    34,
      58,    34,   309,    23,    24,    25,    26,    27,   310,    59,
     609,    59,   322,    59,   260,   261,   262,   263,   264,   265,
      59,   329,    59,    81,    59,   615,    59,   720,   732,   711,
      59,   267,   268,   269,   270,   271,   272,    59,    23,    24,
      25,    26,    27,   718,    59,   609,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
     217,   218,   219,   220,   221,   222,   241,   382,   385,   387,
     719,   296,   297,   298,   299,   300,   407,   415,   721,   284,
     285,   734,   248,   249,   250,   742,   251,   252,   450,   286,
     287,   724,   463,    23,    24,    25,    26,    27,   726,   727,
     609,   728,   493,   729,   737,   737,     3,     4,     5,     6,
       7,     8,   731,     9,   311,   168,   169,   170,    10,   730,
     744,   548,   298,   299,   300,   171,    11,   745,   746,   575,
     748,    12,   172,   173,   749,   130,   170,   597,   599,   601,
     743,   605,   607,   224,   225,   737,   226,    54,    59,   273,
     152,   187,   620,   227,   228,    69,    54,   757,    69,   224,
     274,   638,   226,   206,   275,    54,    54,   751,   265,   227,
     228,   276,   277,   278,   279,   280,   281,    76,   770,    54,
     672,   147,   148,   149,   150,   151,   152,   758,   689,   691,
     691,   691,   691,   691,   691,   691,   765,   702,   703,   704,
     705,   706,   771,    59,   738,   738,    23,    24,    25,    26,
      27,    69,   772,   609,   777,    59,   149,   150,   151,   152,
      59,    54,    59,   780,    59,   611,   785,     3,     4,     5,
       6,     7,     8,    48,     9,   314,   787,   789,   756,    10,
     790,    67,    54,    82,    54,   738,    54,    11,   792,   742,
     798,    48,    12,    54,   791,    54,   794,    54,   799,    54,
     215,   802,   776,    54,   216,    48,   184,   185,   186,   187,
      54,   217,   218,   219,   220,   221,   222,    54,   812,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,   788,   203,   204,   205,   206,    76,   814,
     377,   327,   817,    58,   274,   820,   797,   781,   275,   402,
     410,   244,   245,   246,   187,   276,   277,   278,   279,   280,
     281,   445,   335,   454,   456,   458,   779,   274,    68,   816,
     767,   275,    48,   782,     0,   488,     0,   759,   276,   277,
     278,   279,   280,   281,     0,     0,     3,     4,     5,     6,
       7,     8,   331,     9,   543,     0,    48,     0,    10,     0,
       0,     0,   570,     0,   334,    48,    11,     0,     0,     0,
     592,    12,     3,     4,     5,     6,     7,     8,     0,     9,
     316,    54,     0,     0,    10,   616,   622,   623,   219,   220,
     221,   222,    11,     0,   634,     0,   124,    12,     0,    58,
       0,     0,     0,   147,   148,   149,   150,   151,   152,    58,
     762,    58,    58,   668,    58,    34,    58,    76,   160,   161,
       0,   685,    69,    69,    69,    69,    69,    69,    69,     0,
     698,    69,    69,    69,    69,     0,    54,     0,     0,    58,
      58,    53,     0,    76,   262,   263,   264,   265,    54,     0,
      53,     0,     0,    54,     0,    54,     0,    54,     0,    53,
      53,     0,     0,     3,     4,     5,     6,     7,    64,     0,
      58,     0,     0,    53,     0,    65,     0,    58,    58,     0,
       0,     0,    58,    11,    58,     0,     0,     0,    12,    58,
       0,     0,    58,     0,    58,     0,     3,     4,     5,     6,
       7,     8,     0,     9,    58,   117,     0,    58,    10,     0,
      58,   278,   279,   280,   281,    53,    11,     0,     0,     0,
       0,    12,   296,   297,   298,   299,   300,    59,     0,     0,
       3,     4,     5,     6,    63,    64,    53,     9,    53,    48,
      53,    48,    65,     0,     0,     0,     0,    53,     0,    53,
      11,    53,     0,    53,     0,    12,     0,    53,     0,     0,
       0,     0,   747,     0,    53,     0,     0,    76,     0,     0,
       0,    53,     0,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,     0,   351,   359,
     363,   182,   183,   184,   185,   186,   187,     0,     0,     0,
       0,    66,     0,   401,   409,     0,   193,   194,     0,   433,
     435,   437,   439,   441,   443,     0,   452,   216,     0,     0,
     465,     0,     0,    59,   217,   218,   219,   220,   221,   222,
     495,     0,     0,    59,   691,    59,    59,     0,    59,     0,
      59,     3,     4,     5,     6,     7,     8,     0,     9,   550,
       0,     0,     0,    10,     0,     0,     0,   577,     0,     0,
       0,    11,     0,    59,    59,     0,    12,   603,     0,     0,
       0,    55,     0,     0,   275,    53,     0,     0,     0,     0,
      55,   276,   277,   278,   279,   280,   281,     0,     0,    55,
      55,     0,     0,     0,    59,     3,     4,     5,     6,    63,
      64,    59,    59,    55,     0,     0,    59,    65,    59,     0,
       0,     0,    76,    59,     0,    11,    59,     0,    59,     0,
      12,     3,     4,     5,     6,     7,    64,     0,    59,     0,
      53,    59,     0,    65,    59,   182,   183,   184,   185,   186,
     187,    11,    53,     0,     0,    55,    12,    53,     0,    53,
       0,    53,     0,     0,   201,   202,   203,   204,   205,   206,
      54,     0,     0,     0,   208,     0,    55,     0,    55,     0,
      55,   209,   210,   211,   212,   213,   214,    55,     0,    55,
       0,    55,     0,    55,     0,     0,     0,    55,     0,     0,
     259,     0,   761,     0,    55,   260,   261,   262,   263,   264,
     265,    55,     0,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,     0,     3,     4,
       5,     6,     7,     8,   378,     9,   318,     0,     0,     0,
      10,     0,     0,   403,   411,     0,     0,     0,    11,     0,
       0,     0,     0,    12,     0,   446,     0,     0,     0,   459,
       0,   467,   469,     0,     0,     0,    54,     0,     0,   489,
     147,   148,   149,   150,   151,   152,    54,    69,    54,    54,
       0,    54,     0,    54,     0,   160,   161,    78,   544,   164,
     165,   166,   167,     0,     0,     0,   571,   103,     0,    76,
       0,     0,     0,     0,   593,     0,    54,    54,     0,     3,
       4,     5,     6,     7,     8,    55,     9,   323,     0,     0,
       0,    10,     0,     0,   296,   297,   298,   299,   300,    11,
       0,     0,     0,     0,    12,   248,     0,    54,     0,   251,
     252,     0,     0,     0,    54,    54,     0,     0,     0,    54,
       0,    54,    78,     0,     0,     0,    54,     0,     0,    54,
       0,    54,    48,     0,    48,    48,     0,     0,     0,     0,
      55,    54,     0,   303,    54,   305,     0,    54,     0,     0,
      76,     0,    55,     0,   312,     0,   312,    55,   312,    55,
     312,    55,     0,     0,   324,     0,     0,     0,     0,   130,
     201,   202,   203,   204,   205,   206,     0,     0,   333,     0,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,     0,     0,     0,     0,     0,   131,
      48,    48,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,     0,    48,   201,   202,
     203,   204,   205,   206,   207,     0,     0,     0,   208,     0,
      48,     0,     0,    48,    53,   209,   210,   211,   212,   213,
     214,     0,   350,   358,   362,   366,   370,   373,   376,   383,
     386,   388,   390,   392,   394,   396,   398,   400,   408,   416,
     420,   424,   428,   432,   434,   436,   438,   440,   442,   444,
     451,   453,   455,   457,   464,   466,   468,   470,   473,   476,
     479,   482,   614,   487,   494,   496,   498,   500,   502,   504,
     506,   509,   512,   515,   518,   521,   524,   527,   530,   533,
     536,   539,   542,   549,   551,   554,   557,   560,   563,   566,
     569,   576,   579,   581,   583,   585,   587,   589,   591,   598,
     600,   602,   604,   606,   260,   261,   262,   263,   264,   265,
      53,   201,   202,   203,   204,   205,   206,    78,     0,     0,
      53,     0,    53,    53,     0,    53,     0,    53,     0,   717,
     211,   212,   213,   214,     0,     0,   241,     0,   725,     0,
       0,   242,   243,   244,   245,   246,   187,   247,     0,     0,
      53,    53,   248,   249,   250,     0,   251,   252,   253,   254,
     255,   256,   257,   258,     0,     0,     0,   122,   123,     0,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,    53,     0,    10,     0,     0,     0,     0,    53,    53,
       0,    11,     0,    53,     0,    53,    12,     0,     0,     0,
      53,     0,     0,    53,     0,    53,   276,   277,   278,   279,
     280,   281,     0,     0,     0,    53,     0,     0,    53,     0,
       0,    53,     0,    13,    14,    15,     0,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,     1,    55,     0,     2,     3,     4,     5,
       6,     7,     8,     0,     9,   259,     0,     0,     0,    10,
     260,   261,   262,   263,   264,   265,   266,    11,     0,     0,
       0,     0,    12,     0,     0,     0,     0,   267,   268,   269,
     270,   271,   272,     0,     0,     0,     0,   242,   243,   244,
     245,   246,   187,     0,     0,     0,     0,     0,     0,    13,
      14,    15,   251,   252,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   123,     0,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
      55,   723,     0,    10,   147,   148,   149,   150,   151,   152,
      55,    11,    55,    55,     0,    55,    12,    55,     0,   160,
     161,   162,   163,   164,   165,   166,   167,     0,     0,     0,
       0,   296,   297,   298,   299,   300,     0,     0,     0,     0,
      55,    55,     0,    13,    14,    15,   251,   252,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,   296,   297,   298,   299,   300,    55,    55,
       0,     0,     0,    55,   248,    55,   250,     0,   251,   252,
      55,     0,     0,    55,     0,    55,     0,     0,     0,     0,
       0,   755,     0,     0,     0,    55,     0,     0,    55,     0,
       0,    55,     0,     0,   123,     0,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,   764,     0,    10,
     147,   148,   149,   150,   151,   152,     0,    11,     0,     0,
       0,   157,    12,   159,     0,   160,   161,   162,   163,   164,
     165,   166,   167,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,     0,    83,    85,    91,    13,
      14,    15,     0,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,   182,
     183,   184,   185,   186,   187,   188,     0,    78,     0,   189,
     190,   191,   192,     0,   193,   194,   195,   196,   197,   198,
     199,   200,   766,     0,   312,     0,     0,     0,     0,     0,
      70,    83,   260,   261,   262,   263,   264,   265,   266,     0,
       0,     0,     0,     0,     0,     0,   292,   333,   312,   267,
     268,   269,   270,   271,   272,   294,   295,     0,     0,     0,
       0,     0,     0,     0,   147,   148,   149,   150,   151,   152,
     153,   154,   155,     0,   156,   157,   158,   159,   800,   160,
     161,   162,   163,   164,   165,   166,   167,     0,     0,     0,
     808,     0,   809,     0,     0,     0,     0,   811,     0,     0,
     813,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   818,   354,   360,   364,   368,   371,   374,   379,
     374,   374,   374,   391,   393,   395,   397,   399,   404,   412,
     417,   421,   425,   429,   374,   374,   374,   374,   374,   374,
     447,   374,   374,   374,   460,   374,   374,   374,   471,   474,
     477,   480,   483,   485,   490,   374,   497,   499,   501,   503,
     505,   507,   510,   513,   516,   519,   522,   525,   528,   531,
     534,   537,   540,   545,   374,   552,   555,   558,   561,   564,
     567,   572,   374,   374,   374,   374,   374,   374,   374,   594,
     374,   374,   374,   374,   374,     0,     0,     0,    71,     0,
      84,    86,     0,     0,   617,     0,     0,     0,   624,   626,
     628,   630,   632,   635,   639,   640,   641,   642,   643,   644,
     646,   648,   650,   652,   654,     0,   656,   658,   660,   662,
     664,   666,   669,   673,   675,   677,   679,   681,   683,     0,
     686,    85,    85,    85,    85,    85,    85,    85,     0,   699,
      85,    85,    85,    85,    71,    84,     0,     0,     0,     0,
       0,     0,   712,   713,   714,   715,   716,     0,     0,     0,
     293,   147,   148,   149,   150,   151,   152,     0,   154,   155,
       0,   156,   157,   158,   159,     0,   160,   161,   162,   163,
     164,   165,   166,   167,   147,   148,   149,   150,   151,   152,
       0,   154,     0,     0,   156,   157,   158,   159,     0,   160,
     161,   162,   163,   164,   165,   166,   167,   242,   243,   244,
     245,   246,   187,     0,     0,     0,     0,     0,   248,   249,
     250,     0,   251,   252,     0,     0,     0,   355,   361,   365,
     369,   372,   375,   380,   384,   384,   384,   384,   384,   384,
     384,   384,   405,   413,   418,   422,   426,   430,   384,   384,
     384,   384,   384,   384,   448,   384,   384,   384,   461,   384,
     384,   384,   472,   475,   478,   481,   484,   486,   491,   384,
     384,   384,   384,   384,   384,   508,   511,   514,   517,   520,
     523,   526,   529,   532,   535,   538,   541,   546,   384,   553,
     556,   559,   562,   565,   568,   573,   384,   384,   384,   384,
     384,   384,   384,   595,   384,   384,   384,   384,   384,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   618,     0,
       0,     0,   625,   627,   629,   631,   633,   636,     0,     0,
       0,     0,     0,   645,   647,   649,   651,   653,   655,     0,
     657,   659,   661,   663,   665,   667,   670,   674,   676,   678,
     680,   682,   684,     0,   687,    86,    86,    86,    86,    86,
      86,    86,     0,   700,    86,    86,    86,    86,    98,     3,
       4,     5,     6,     7,     8,     0,     9,     0,    99,     0,
       0,    10,     0,     0,     0,     0,     0,     0,     0,    11,
       0,     0,     0,     0,    12,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,   307,
       0,    10,     0,     0,     0,     0,     0,     0,     0,    11,
       0,    13,    14,    15,    12,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13,    14,    15,     0,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,     0,     0,    10,     0,     0,     0,     0,     0,
       0,     0,    11,     0,     0,     0,     0,    12,   242,   243,
     244,   245,   246,   187,   247,     0,     0,     0,     0,   248,
     249,   250,     0,   251,   252,   253,   254,   255,   256,   257,
     258,     0,     0,     0,    13,    14,    15,     0,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,   182,   183,   184,   185,   186,   187,
       0,     0,     0,     0,   189,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   147,   148,   149,
     150,   151,   152,     0,     0,     0,    85,   156,   157,   158,
     159,     0,   160,   161,   162,   163,   164,   165,   166,   167,
     147,   148,   149,   150,   151,   152,     0,     0,     0,     0,
       0,   157,   158,   159,     0,   160,   161,   162,   163,   164,
     165,   166,   167,   242,   243,   244,   245,   246,   187,     0,
       0,     0,     0,     0,   248,   249,   250,     0,   251,   252,
     253,   254,   255,   256,   257,   258,   182,   183,   184,   185,
     186,   187,     0,     0,     0,     0,     0,   190,     0,   192,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   147,
     148,   149,   150,   151,   152,     0,     0,     0,     0,     0,
     157,     0,     0,     0,   160,   161,   162,   163,   164,   165,
     166,   167,   182,   183,   184,   185,   186,   187,     0,     0,
       0,     0,     0,   190,     0,     0,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   182,   183,   184,   185,   186,
     187,     0,     0,   182,   183,   184,   185,   186,   187,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   193,   194,
       0,   241,   197,   198,   199,   200,   242,   243,   244,   245,
     246,   187,     0,     0,     0,     0,     0,   248,   249,   250,
       0,   251,   252,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      86
  };

  const short
   Parser ::yycheck_[] =
  {
       0,    66,    99,     0,   321,   612,     9,     9,     8,     9,
       9,    11,    74,   719,   231,   721,    32,     9,    18,    19,
     106,     9,   108,    12,   110,    10,   112,    11,    11,    11,
      75,    10,    32,     9,     9,    32,    39,     3,     4,     5,
       6,     7,     8,     9,    11,    11,    12,     4,     5,    10,
      16,    40,     9,   731,   732,    40,    11,    21,    24,    16,
      11,    25,    13,    29,    64,    40,    42,    75,    32,    33,
       9,    10,    29,    75,    74,     9,    75,     9,    14,    40,
       9,   787,   788,    75,    68,    68,    68,    75,    75,    68,
      69,    70,    71,    72,   772,    95,    75,    97,   804,    99,
      39,    68,    99,    39,   321,   322,   106,   123,   108,    75,
     110,   817,   112,    68,   820,   739,   116,    68,    75,     3,
      11,     3,    13,   123,    75,    68,   123,    75,    12,   753,
     130,    13,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,    21,     4,     5,    75,
      25,   775,     9,   153,     8,     9,   156,    32,    33,    16,
     784,     3,   162,   163,   164,   165,   166,   167,     3,   776,
       0,    13,    29,    68,   174,     3,     3,    12,   178,     3,
       4,     5,     6,     7,     8,     9,     4,    11,   188,    25,
      10,     9,    16,     3,    32,    33,    32,    33,    16,     3,
      24,    21,    22,    23,    14,    29,     3,   207,     3,   306,
      68,    29,    32,    33,    21,   215,   216,   217,   218,   219,
     220,   221,   222,   223,     0,    32,    33,   289,    21,    22,
      23,     3,     8,     9,   234,    11,    10,    25,   238,    32,
      33,    25,    18,    19,    32,    33,    56,   247,    32,    33,
      40,    75,    15,    16,    17,    10,    32,    22,    68,    69,
      70,    71,    72,    32,    33,    75,   266,    32,    33,    32,
      33,    15,    16,    17,   274,   275,   276,   277,   278,   279,
     280,   281,    11,   283,   284,   285,   286,   287,    64,   289,
      10,    10,   308,    21,    22,    23,    42,    25,    74,    59,
      60,   301,    40,    13,    32,    33,   306,    75,   308,   306,
     310,   308,    62,    68,    69,    70,    71,    72,    42,    95,
      75,    97,     9,    99,    15,    16,    17,    18,    19,    20,
     106,    39,   108,    75,   110,    10,   112,    41,     3,    12,
     116,    32,    33,    34,    35,    36,    37,   123,    68,    69,
      70,    71,    72,    75,   130,    75,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
      32,    33,    34,    35,    36,    37,    10,   153,   154,   155,
      10,    15,    16,    17,    18,    19,   162,   163,    10,    22,
      23,    56,    26,    27,    28,   612,    30,    31,   174,    32,
      33,     9,   178,    68,    69,    70,    71,    72,    40,    12,
      75,    12,   188,    12,   731,   732,     4,     5,     6,     7,
       8,     9,    13,    11,    12,    15,    16,    17,    16,    12,
      12,   207,    17,    18,    19,    25,    24,    75,    14,   215,
      10,    29,    32,    33,    40,     9,    17,   223,   224,   225,
      12,   227,   228,    22,    23,   772,    25,     0,   234,    10,
      20,    20,   238,    32,    33,     8,     9,     8,    11,    22,
      21,   247,    25,    20,    25,    18,    19,    10,    20,    32,
      33,    32,    33,    34,    35,    36,    37,    75,    75,    32,
     266,    15,    16,    17,    18,    19,    20,    12,   274,   275,
     276,   277,   278,   279,   280,   281,     3,   283,   284,   285,
     286,   287,    14,   289,   731,   732,    68,    69,    70,    71,
      72,    64,     3,    75,    40,   301,    17,    18,    19,    20,
     306,    74,   308,    42,   310,   752,    59,     4,     5,     6,
       7,     8,     9,     0,    11,    12,    10,     3,   613,    16,
      10,     8,    95,    10,    97,   772,    99,    24,    42,   776,
     777,    18,    29,   106,    14,   108,    42,   110,    42,   112,
      21,     9,    40,   116,    25,    32,    17,    18,    19,    20,
     123,    32,    33,    34,    35,    36,    37,   130,    40,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    10,    17,    18,    19,    20,    75,     9,
     153,    39,    10,   613,    21,    10,   777,   749,    25,   162,
     163,    17,    18,    19,    20,    32,    33,    34,    35,    36,
      37,   174,   132,   176,   177,   178,   743,    21,     8,   812,
     726,    25,    99,   752,    -1,   188,    -1,   709,    32,    33,
      34,    35,    36,    37,    -1,    -1,     4,     5,     6,     7,
       8,     9,    10,    11,   207,    -1,   123,    -1,    16,    -1,
      -1,    -1,   215,    -1,   131,   132,    24,    -1,    -1,    -1,
     223,    29,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,   234,    -1,    -1,    16,   238,   239,   240,    34,    35,
      36,    37,    24,    -1,   247,    -1,   722,    29,    -1,   709,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,   719,
     720,   721,   722,   266,   724,   722,   726,    75,    30,    31,
      -1,   274,   275,   276,   277,   278,   279,   280,   281,    -1,
     283,   284,   285,   286,   287,    -1,   289,    -1,    -1,   749,
     750,     0,    -1,    75,    17,    18,    19,    20,   301,    -1,
       9,    -1,    -1,   306,    -1,   308,    -1,   310,    -1,    18,
      19,    -1,    -1,     4,     5,     6,     7,     8,     9,    -1,
     780,    -1,    -1,    32,    -1,    16,    -1,   787,   788,    -1,
      -1,    -1,   792,    24,   794,    -1,    -1,    -1,    29,   799,
      -1,    -1,   802,    -1,   804,    -1,     4,     5,     6,     7,
       8,     9,    -1,    11,   814,    13,    -1,   817,    16,    -1,
     820,    34,    35,    36,    37,    74,    24,    -1,    -1,    -1,
      -1,    29,    15,    16,    17,    18,    19,   613,    -1,    -1,
       4,     5,     6,     7,     8,     9,    95,    11,    97,   306,
      99,   308,    16,    -1,    -1,    -1,    -1,   106,    -1,   108,
      24,   110,    -1,   112,    -1,    29,    -1,   116,    -1,    -1,
      -1,    -1,   329,    -1,   123,    -1,    -1,    75,    -1,    -1,
      -1,   130,    -1,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,    -1,   147,   148,
     149,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    75,    -1,   162,   163,    -1,    30,    31,    -1,   168,
     169,   170,   171,   172,   173,    -1,   175,    25,    -1,    -1,
     179,    -1,    -1,   709,    32,    33,    34,    35,    36,    37,
     189,    -1,    -1,   719,   720,   721,   722,    -1,   724,    -1,
     726,     4,     5,     6,     7,     8,     9,    -1,    11,   208,
      -1,    -1,    -1,    16,    -1,    -1,    -1,   216,    -1,    -1,
      -1,    24,    -1,   749,   750,    -1,    29,   226,    -1,    -1,
      -1,     0,    -1,    -1,    25,   234,    -1,    -1,    -1,    -1,
       9,    32,    33,    34,    35,    36,    37,    -1,    -1,    18,
      19,    -1,    -1,    -1,   780,     4,     5,     6,     7,     8,
       9,   787,   788,    32,    -1,    -1,   792,    16,   794,    -1,
      -1,    -1,    75,   799,    -1,    24,   802,    -1,   804,    -1,
      29,     4,     5,     6,     7,     8,     9,    -1,   814,    -1,
     289,   817,    -1,    16,   820,    15,    16,    17,    18,    19,
      20,    24,   301,    -1,    -1,    74,    29,   306,    -1,   308,
      -1,   310,    -1,    -1,    15,    16,    17,    18,    19,    20,
     613,    -1,    -1,    -1,    25,    -1,    95,    -1,    97,    -1,
      99,    32,    33,    34,    35,    36,    37,   106,    -1,   108,
      -1,   110,    -1,   112,    -1,    -1,    -1,   116,    -1,    -1,
      10,    -1,    75,    -1,   123,    15,    16,    17,    18,    19,
      20,   130,    -1,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,    -1,     4,     5,
       6,     7,     8,     9,   153,    11,    12,    -1,    -1,    -1,
      16,    -1,    -1,   162,   163,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    29,    -1,   174,    -1,    -1,    -1,   178,
      -1,   180,   181,    -1,    -1,    -1,   709,    -1,    -1,   188,
      15,    16,    17,    18,    19,    20,   719,   720,   721,   722,
      -1,   724,    -1,   726,    -1,    30,    31,     9,   207,    34,
      35,    36,    37,    -1,    -1,    -1,   215,    19,    -1,    75,
      -1,    -1,    -1,    -1,   223,    -1,   749,   750,    -1,     4,
       5,     6,     7,     8,     9,   234,    11,    12,    -1,    -1,
      -1,    16,    -1,    -1,    15,    16,    17,    18,    19,    24,
      -1,    -1,    -1,    -1,    29,    26,    -1,   780,    -1,    30,
      31,    -1,    -1,    -1,   787,   788,    -1,    -1,    -1,   792,
      -1,   794,    74,    -1,    -1,    -1,   799,    -1,    -1,   802,
      -1,   804,   719,    -1,   721,   722,    -1,    -1,    -1,    -1,
     289,   814,    -1,    95,   817,    97,    -1,   820,    -1,    -1,
      75,    -1,   301,    -1,   106,    -1,   108,   306,   110,   308,
     112,   310,    -1,    -1,   116,    -1,    -1,    -1,    -1,     9,
      15,    16,    17,    18,    19,    20,    -1,    -1,   130,    -1,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,    -1,    -1,    -1,    -1,    -1,    39,
     787,   788,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,   804,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    25,    -1,
     817,    -1,    -1,   820,   613,    32,    33,    34,    35,    36,
      37,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   234,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,    15,    16,    17,    18,    19,    20,
     709,    15,    16,    17,    18,    19,    20,   289,    -1,    -1,
     719,    -1,   721,   722,    -1,   724,    -1,   726,    -1,   301,
      34,    35,    36,    37,    -1,    -1,    10,    -1,   310,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
     749,   750,    26,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,     0,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
      -1,   780,    -1,    16,    -1,    -1,    -1,    -1,   787,   788,
      -1,    24,    -1,   792,    -1,   794,    29,    -1,    -1,    -1,
     799,    -1,    -1,   802,    -1,   804,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,   814,    -1,    -1,   817,    -1,
      -1,   820,    -1,    56,    57,    58,    -1,    -1,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,   613,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    10,    -1,    -1,    -1,    16,
      15,    16,    17,    18,    19,    20,    21,    24,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    58,    30,    31,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
     709,    14,    -1,    16,    15,    16,    17,    18,    19,    20,
     719,    24,   721,   722,    -1,   724,    29,   726,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,
     749,   750,    -1,    56,    57,    58,    30,    31,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   780,    -1,    15,    16,    17,    18,    19,   787,   788,
      -1,    -1,    -1,   792,    26,   794,    28,    -1,    30,    31,
     799,    -1,    -1,   802,    -1,   804,    -1,    -1,    -1,    -1,
      -1,   613,    -1,    -1,    -1,   814,    -1,    -1,   817,    -1,
      -1,   820,    -1,    -1,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    -1,    14,    -1,    16,
      15,    16,    17,    18,    19,    20,    -1,    24,    -1,    -1,
      -1,    26,    29,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     8,    -1,    10,    11,    12,    56,
      57,    58,    -1,    -1,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    15,
      16,    17,    18,    19,    20,    21,    -1,   709,    -1,    25,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,   724,    -1,   726,    -1,    -1,    -1,    -1,    -1,
      64,    65,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,   749,   750,    32,
      33,    34,    35,    36,    37,    89,    90,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,   780,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
     792,    -1,   794,    -1,    -1,    -1,    -1,   799,    -1,    -1,
     802,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   814,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,    -1,    -1,    -1,     8,    -1,
      10,    11,    -1,    -1,   238,    -1,    -1,    -1,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    -1,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,    -1,
     274,   275,   276,   277,   278,   279,   280,   281,    -1,   283,
     284,   285,   286,   287,    64,    65,    -1,    -1,    -1,    -1,
      -1,    -1,   296,   297,   298,   299,   300,    -1,    -1,    -1,
      80,    15,    16,    17,    18,    19,    20,    -1,    22,    23,
      -1,    25,    26,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    15,    16,    17,    18,    19,    20,
      -1,    22,    -1,    -1,    25,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    -1,    30,    31,    -1,    -1,    -1,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,   242,   243,   244,   245,   246,   247,    -1,    -1,
      -1,    -1,    -1,   253,   254,   255,   256,   257,   258,    -1,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,    -1,   274,   275,   276,   277,   278,   279,
     280,   281,    -1,   283,   284,   285,   286,   287,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    -1,    13,    -1,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    -1,    -1,    14,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    56,    57,    58,    29,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    -1,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    25,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,   720,    25,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    15,    16,    17,    18,    19,
      20,    -1,    -1,    15,    16,    17,    18,    19,    20,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    30,    31,
      -1,    10,    34,    35,    36,    37,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     720
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
      30,    31,    32,    33,    34,    35,    36,    37,    15,    16,
      17,    25,    32,    33,    21,    25,    32,    33,    21,    25,
      32,    33,    15,    16,    17,    18,    19,    20,    21,    25,
      26,    27,    28,    30,    31,    32,    33,    34,    35,    36,
      37,    15,    16,    17,    18,    19,    20,    21,    25,    32,
      33,    34,    35,    36,    37,    21,    25,    32,    33,    34,
      35,    36,    37,    21,    22,    23,    25,    32,    33,    68,
      68,     9,    75,    10,    11,   115,    10,    10,    21,    32,
      33,    10,    15,    16,    17,    18,    19,    21,    26,    27,
      28,    30,    31,    32,    33,    34,    35,    36,    37,    10,
      15,    16,    17,    18,    19,    20,    21,    32,    33,    34,
      35,    36,    37,    10,    21,    25,    32,    33,    34,    35,
      36,    37,    10,    21,    22,    23,    32,    33,   111,    40,
       3,    12,   117,   118,   117,   117,    15,    16,    17,    18,
      19,    42,    40,   107,    75,   107,    13,    14,    79,    62,
      42,    12,   107,   124,    12,   124,    12,   124,    12,   124,
       3,    13,     9,    12,   107,   124,    14,    39,   116,    39,
      80,    10,   104,   107,   106,   102,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     108,   112,   113,   114,   117,   118,   119,   120,   108,   112,
     117,   118,   108,   112,   117,   118,   108,   112,   117,   118,
     108,   117,   118,   108,   117,   118,   108,   113,   114,   117,
     118,   119,   120,   108,   118,   120,   108,   120,   108,   119,
     108,   117,   108,   117,   108,   117,   108,   117,   108,   117,
     108,   112,   113,   114,   117,   118,   119,   120,   108,   112,
     113,   114,   117,   118,   119,   120,   108,   117,   118,   119,
     108,   117,   118,   119,   108,   117,   118,   119,   108,   117,
     118,   119,   108,   112,   108,   112,   108,   112,   108,   112,
     108,   112,   108,   112,   108,   113,   114,   117,   118,   119,
     120,   108,   112,   108,   113,   108,   113,   108,   113,   114,
     117,   118,   119,   120,   108,   112,   108,   114,   108,   114,
     108,   117,   118,   108,   117,   118,   108,   117,   118,   108,
     117,   118,   108,   117,   118,   117,   118,   108,   113,   114,
     117,   118,   119,   120,   108,   112,   108,   117,   108,   117,
     108,   117,   108,   117,   108,   117,   108,   117,   118,   108,
     117,   118,   108,   117,   118,   108,   117,   118,   108,   117,
     118,   108,   117,   118,   108,   117,   118,   108,   117,   118,
     108,   117,   118,   108,   117,   118,   108,   117,   118,   108,
     117,   118,   108,   113,   114,   117,   118,   119,   120,   108,
     112,   108,   117,   118,   108,   117,   118,   108,   117,   118,
     108,   117,   118,   108,   117,   118,   108,   117,   118,   108,
     113,   114,   117,   118,   119,   120,   108,   112,   119,   108,
     119,   108,   119,   108,   119,   108,   119,   108,   119,   108,
     119,   108,   113,   114,   117,   118,   119,   120,   108,   120,
     108,   120,   108,   112,   108,   120,   108,   120,    10,    75,
     122,   125,     9,    42,   107,    10,   113,   117,   118,   119,
     120,     9,   113,   113,   117,   118,   117,   118,   117,   118,
     117,   118,   117,   118,   113,   117,   118,   119,   120,   117,
     117,   117,   117,   117,   117,   118,   117,   118,   117,   118,
     117,   118,   117,   118,   117,   118,   117,   118,   117,   118,
     117,   118,   117,   118,   117,   118,   117,   118,   113,   117,
     118,   119,   120,   117,   118,   117,   118,   117,   118,   117,
     118,   117,   118,   117,   118,   113,   117,   118,   119,   120,
     119,   120,   119,   119,   119,   119,   119,   119,   113,   117,
     118,   119,   120,   120,   120,   120,   120,     3,    12,     3,
     111,    12,   117,   117,   117,   117,   117,   107,    75,    10,
      41,    10,    79,    14,     9,   107,    40,    12,    12,    12,
      12,    13,     3,    14,    56,    95,    96,   100,   125,    10,
      98,    99,   125,    12,    12,    75,    14,   106,    10,    40,
      11,    10,    40,    10,    98,   107,   115,     8,    12,   111,
      83,    75,   119,    83,    14,     3,   107,   124,    95,    95,
      75,    14,     3,    75,    82,    10,    40,    40,    75,   105,
      42,   104,   122,    82,    10,    59,    92,    10,    10,     3,
      10,    14,    42,    95,    42,    82,    98,    99,   125,    42,
     107,    82,     9,    59,    60,    93,    83,    83,   107,   107,
      75,   107,    40,   107,     9,    83,   116,    10,   107,    83,
      10,    83
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
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   109,   109,   109,   109,   110,   110,
     110,   110,   110,   111,   111,   111,   112,   112,   113,   113,
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
     125,   125,   125,   125,   125,   125,   125,   125,   125
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
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     2,     3,
       4,     4,     5,     1,     3,     4,     1,     3,     1,     3,
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
     359,   360,   361,   362,   363,   365,   366,   367,   368,   369,
     371,   372,   373,   374,   375,   377,   378,   379,   380,   381,
     382,   383,   384,   386,   387,   388,   389,   390,   391,   392,
     393,   395,   396,   397,   399,   400,   401,   403,   404,   405,
     406,   407,   408,   409,   411,   412,   413,   414,   415,   416,
     417,   419,   420,   421,   422,   423,   424,   425,   427,   428,
     429,   430,   431,   432,   433,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   471,
     472,   473,   475,   476,   477,   479,   480,   481,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   500,   501,   502,   504,   505,   506,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,   535,   536,   537,   538,   542,   543,
     544,   545,   546,   548,   549,   550,   554,   555,   559,   560,
     564,   565,   567,   568,   570,   571,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   646,   647,
     648,   649,   650,   652,   653,   654,   655,   656,   657,   658,
     660,   661,   662,   663,   664,   665,   666,   668,   669,   670,
     671,   672,   674,   675,   676,   677,   678,   680,   681,   682,
     683,   684,   686,   687,   688,   689,   690,   692,   696,   697,
     699,   700,   704,   705,   706,   707,   708,   709,   710,   711,
     712,   713,   715,   716,   720,   721,   722,   723,   724,   725,
     726,   727,   728,   729,   730,   731,   732,   733,   734
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
#line 2865 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"

#line 737 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    std::cerr << scanner->loc->begin.line << ":" << scanner->loc->begin.column << ": " << err_message << std::endl;
}
