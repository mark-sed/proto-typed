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
  case 113: // expr_int: "int"
#line 363 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 787 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 114: // expr_int: "-" expr_int
#line 364 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 793 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 115: // expr_int: "(" expr_int ")"
#line 365 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 799 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 116: // expr_int: expr_int "*" expr_int
#line 366 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 805 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 117: // expr_int: expr_int "/" expr_int
#line 367 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 811 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 118: // expr_int: expr_int "%" expr_int
#line 368 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 817 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 119: // expr_int: expr_int "-" expr_int
#line 369 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 823 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 120: // expr_int: expr_int "+" expr_int
#line 370 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 829 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 121: // expr_int: expr_int "&" expr_int
#line 371 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 835 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 122: // expr_int: expr_int "|" expr_int
#line 372 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 841 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 123: // expr_int: expr_int "^" expr_int
#line 373 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 847 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 124: // expr_int: "~" expr_int
#line 374 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 853 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 125: // expr_int: expr_int "<<" expr_int
#line 375 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 859 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 126: // expr_int: expr_int ">>" expr_int
#line 376 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 865 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 127: // expr_float: "float"
#line 380 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 871 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 128: // expr_float: "-" expr_float
#line 381 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 877 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 129: // expr_float: "(" expr_float ")"
#line 382 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 883 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 130: // expr_float: expr_float "**" expr_float
#line 383 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 889 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 131: // expr_float: expr_float "**" expr_int
#line 384 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 895 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 132: // expr_float: expr_int "**" expr_float
#line 385 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 901 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 133: // expr_float: expr_float "*" expr_float
#line 386 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 907 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 134: // expr_float: expr_float "*" expr_int
#line 387 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 913 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 135: // expr_float: expr_int "*" expr_float
#line 388 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 919 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 136: // expr_float: expr_float "/" expr_float
#line 389 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 925 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 137: // expr_float: expr_float "/" expr_int
#line 390 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 931 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 138: // expr_float: expr_int "/" expr_float
#line 391 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 937 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 139: // expr_float: expr_float "%" expr_float
#line 392 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 943 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 140: // expr_float: expr_float "%" expr_int
#line 393 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 949 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 141: // expr_float: expr_int "%" expr_float
#line 394 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 955 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 142: // expr_float: expr_float "-" expr_float
#line 395 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 961 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 143: // expr_float: expr_float "-" expr_int
#line 396 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 967 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 144: // expr_float: expr_int "-" expr_float
#line 397 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 973 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 145: // expr_float: expr_float "+" expr_float
#line 398 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 979 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 146: // expr_float: expr_float "+" expr_int
#line 399 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 985 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 147: // expr_float: expr_int "+" expr_float
#line 400 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 991 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 148: // expr_str: "string"
#line 404 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 997 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 149: // expr_str: "(" expr_str ")"
#line 405 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 1003 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 150: // expr_str: expr_str "++" expr_str
#line 406 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 1009 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 151: // expr_str: expr_str "++" expr_int
#line 407 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 1015 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 152: // expr_str: expr_str "++" expr_float
#line 408 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 1021 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 153: // expr_str: expr_str "++" expr_bool
#line 409 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1027 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 154: // expr_str: expr_int "++" expr_str
#line 410 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 1033 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 155: // expr_str: expr_int "++" expr_int
#line 411 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 1039 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 156: // expr_str: expr_int "++" expr_float
#line 412 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 1045 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 157: // expr_str: expr_int "++" expr_bool
#line 413 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1051 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 158: // expr_str: expr_float "++" expr_str
#line 414 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 1057 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 159: // expr_str: expr_float "++" expr_int
#line 415 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 1063 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 160: // expr_str: expr_float "++" expr_float
#line 416 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 1069 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 161: // expr_str: expr_float "++" expr_bool
#line 417 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1075 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 162: // expr_str: expr_bool "++" expr_str
#line 418 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 1081 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 163: // expr_str: expr_bool "++" expr_int
#line 419 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 1087 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 164: // expr_str: expr_bool "++" expr_float
#line 420 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 1093 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 165: // expr_str: expr_bool "++" expr_bool
#line 421 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1099 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 166: // expr_bool: "bool"
#line 425 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 1105 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 167: // expr_bool: "(" expr_bool ")"
#line 426 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 1111 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 168: // expr_bool: "not" expr_bool
#line 427 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 1117 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 169: // expr_bool: expr_bool "or" expr_bool
#line 428 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 1123 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 170: // expr_bool: expr_bool "and" expr_bool
#line 429 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 1129 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 171: // expr_bool: expr_bool "==" expr_bool
#line 430 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 1135 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 172: // expr_bool: expr_int "==" expr_int
#line 431 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 1141 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 173: // expr_bool: expr_float "==" expr_float
#line 432 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 1147 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 174: // expr_bool: expr_str "==" expr_str
#line 433 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 1153 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 175: // expr_bool: expr_bool "!=" expr_bool
#line 434 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 1159 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 176: // expr_bool: expr_int "!=" expr_int
#line 435 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 1165 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 177: // expr_bool: expr_float "!=" expr_float
#line 436 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 1171 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 178: // expr_bool: expr_str "!=" expr_str
#line 437 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 1177 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 179: // expr_bool: expr_int ">" expr_int
#line 438 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 1183 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 180: // expr_bool: expr_float ">" expr_float
#line 439 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 1189 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 181: // expr_bool: expr_str ">" expr_str
#line 440 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 1195 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 182: // expr_bool: expr_int "<" expr_int
#line 441 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 1201 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 183: // expr_bool: expr_float "<" expr_float
#line 442 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 1207 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 184: // expr_bool: expr_str "<" expr_str
#line 443 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 1213 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 185: // expr_bool: expr_int ">=" expr_int
#line 444 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 1219 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 186: // expr_bool: expr_float ">=" expr_float
#line 445 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 1225 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 187: // expr_bool: expr_str ">=" expr_str
#line 446 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 1231 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 188: // expr_bool: expr_int "<=" expr_int
#line 447 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 1237 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 189: // expr_bool: expr_float "<=" expr_float
#line 448 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 1243 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 190: // expr_bool: expr_str "<=" expr_str
#line 449 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
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


  const short  Parser ::yypact_ninf_ = -317;

  const signed char  Parser ::yytable_ninf_ = -1;

  const short
   Parser ::yypact_[] =
  {
     523,  -317,  -317,  -317,  -317,  -317,  -317,   829,     8,   160,
     829,    26,   -38,   -31,    24,    36,    38,   701,   535,  -317,
    -317,    10,    57,    80,    91,   105,    59,    76,   136,   147,
     462,  -317,  -317,  -317,  -317,  -317,  -317,  -317,  -317,  -317,
    -317,  -317,  -317,  -317,  -317,  -317,     1,  -317,  -317,  -317,
    1007,  1030,  1135,   108,  -317,  -317,    -2,   978,   703,   648,
     265,   535,  -317,   142,    17,   115,    96,   160,  -317,  -317,
    1007,  1030,  1135,  -317,    26,    26,  -317,   114,  -317,   117,
     535,   101,   535,   157,   759,   168,  -317,   125,    27,  -317,
     131,   889,   903,   917,   946,    37,   171,   960,   145,  -317,
    -317,   817,  -317,   474,   127,   535,   160,   160,   160,   160,
     160,   160,   829,    26,    26,    26,    26,    26,    26,    26,
      26,    26,    26,    26,   160,   160,   160,   160,   160,   160,
     829,   160,   160,   160,   160,   160,   160,   829,   829,   829,
     829,   829,   829,   829,   829,   829,   829,   829,   829,   375,
       9,  -317,  -317,  -317,  -317,   121,   535,   355,   875,   174,
    -317,  1058,   477,  1077,  -317,    26,    26,    26,    26,    26,
     535,   129,   183,    27,  -317,   164,   192,   817,  -317,   583,
    -317,   197,   535,  -317,    25,   180,   209,  -317,   218,  -317,
     269,  -317,   271,   272,   103,   499,  -317,   277,    25,   180,
     283,   127,  -317,  -317,   286,   259,    27,  -317,   292,    27,
    -317,   382,   457,   382,   457,   282,   287,   282,   287,   282,
     287,  1094,   287,  1111,   299,  -317,  -317,   659,  1134,   833,
     762,   762,  1117,  1117,  1117,  1117,  1117,  1117,  1156,   457,
    1156,   457,  1071,   287,  1071,   287,  1071,   287,  1071,   287,
    1111,   299,  -317,  -317,  1037,  1037,  1037,  1037,  1037,  1037,
    1111,   299,  -317,  -317,   161,   108,   161,   290,   290,   290,
     290,  1111,   299,  -317,  -317,    78,    72,   301,   301,  -317,
     297,   319,    13,   605,   535,   318,  -317,    27,  -317,   535,
    -317,   535,  -317,  -317,   104,   104,  -317,  -317,  -317,    27,
    -317,  -317,   701,   595,   701,   643,   329,   535,    27,  -317,
     535,   535,  -317,  -317,  -317,  -317,   351,   351,  -317,   285,
     333,   346,  -317,    16,    54,    66,   311,    18,   142,  -317,
     292,  -317,   535,   960,  -317,   167,    54,    79,    27,  -317,
    -317,  -317,  -317,   306,   347,   761,  -317,   352,  -317,   348,
    -317,  -317,   358,  -317,   323,  -317,   351,   327,  -317,    54,
     167,   167,   331,  -317,  -317,  -317,  -317,    54,   367,    98,
     701,   701,  -317,  -317,  -317,   535,  -317,   535,  -317,   338,
     311,    19,   535,  -317,   535,   371,   701,  -317,  -317,  -317,
      27,  -317,    27,  -317,   331,    27,  -317,   372,   535,  -317,
     701,   373,  -317,   701,  -317
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
       0,     2,     7,   113,   127,   148,   166,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    35,    32,
      33,     0,   209,   210,   211,   212,     0,     0,    91,     0,
       0,     4,     8,    13,    21,    34,    14,    16,    17,    15,
      19,    20,    11,    12,     9,    92,    18,    10,    96,    97,
      98,    99,   100,   101,   214,   215,     0,     0,     0,     0,
       0,     0,   102,    91,   108,   107,     0,     0,   114,   128,
       0,     0,     0,   168,     0,     0,   124,     0,    30,    29,
       0,     0,     0,     0,     0,     0,    28,     0,    36,    37,
       0,     0,     0,     0,     0,     0,     0,     0,    93,     1,
       3,     0,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      72,   115,   129,   149,   167,     0,     0,     0,     0,     0,
     103,     0,     0,     0,   114,     0,     0,     0,     0,     0,
       0,     0,     0,    38,    39,     0,     0,     0,    22,     0,
      27,     0,     0,   198,   205,   206,     0,   200,     0,   202,
       0,   204,     0,     0,     0,     0,   196,     0,    88,    87,
       0,     0,     6,    81,     0,    83,    86,    85,    95,    80,
      79,   120,   147,   119,   144,   116,   135,   117,   138,   118,
     141,     0,   132,   155,   156,   154,   157,   121,   122,   123,
     125,   126,   172,   176,   179,   182,   185,   188,   146,   145,
     143,   142,   134,   133,   137,   136,   140,   139,   131,   130,
     159,   160,   158,   161,   173,   177,   180,   183,   186,   189,
     151,   152,   150,   153,   174,     0,   178,   181,   184,   187,
     190,   163,   164,   162,   165,   170,   169,   171,   175,   192,
     213,     0,   193,     0,     0,     0,   104,    88,    87,     0,
     110,     0,   109,   105,   120,   119,   116,   117,   118,    77,
      78,    31,     0,     0,     0,     0,    23,     0,    75,    76,
       0,     0,   197,   199,   201,   203,     0,    53,    50,     0,
       0,     0,    57,     0,     0,     0,    67,     0,    89,   195,
      94,    82,     0,     0,   191,     0,     0,     0,    73,    74,
     106,   112,   111,    47,     0,     0,    42,    24,    25,     0,
     207,   208,     0,    54,     0,    51,    55,    72,    64,     0,
       0,     0,    66,    90,    84,   194,    62,     0,     0,    49,
       0,     0,    26,    43,    52,     0,    56,     0,    65,    68,
      71,     0,     0,    63,     0,     0,     0,    44,    40,    41,
      61,    60,    59,    58,     0,    70,    69,     0,     0,    48,
       0,     0,    45,     0,    46
  };

  const short
   Parser ::yypgoto_[] =
  {
    -317,  -317,   -83,   -28,     7,  -316,  -233,  -317,  -317,  -317,
    -317,   -79,  -317,  -317,  -317,  -317,  -317,  -317,  -317,  -269,
    -317,  -317,  -278,    28,  -190,  -317,  -317,  -317,    53,  -317,
    -317,    58,    -8,    20,  -317,  -317,   -16,   124,   313,    70,
     196,  -317,    61,  -317,   -32,    31
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    29,    30,    31,    85,    86,    87,    33,    79,    34,
      35,   172,    36,    37,    38,    39,   369,   387,    40,   320,
     321,    41,   325,   326,    42,    43,    44,    45,   204,   205,
     197,    98,    46,    47,    48,    49,    66,    50,    51,    52,
      53,    54,   281,    55,   200,    56
  };

  const short
   Parser ::yytable_[] =
  {
      64,   179,   102,   176,   322,   337,   149,    32,   358,   103,
      88,    61,     3,     4,     5,     6,     7,   283,     8,    62,
     366,   149,    77,     9,   149,   103,   149,   149,    65,    78,
       3,    10,    80,   103,    74,   103,    11,    32,    89,   104,
     193,    75,   105,   378,    81,   155,    82,   352,   353,   194,
     284,   383,   335,    64,    11,   104,   157,    83,   150,   186,
     188,   190,   192,   104,   310,   104,    84,    91,    63,   343,
      90,   346,   173,   202,   173,   359,   357,    59,   362,   394,
      72,    65,   379,   184,   184,   184,   184,   376,   367,   198,
      92,    32,   144,   145,   305,   206,   208,   209,   144,   159,
     174,    93,   174,   147,   148,   360,   317,   160,    32,   147,
     148,   185,   185,   185,   185,    94,   318,   199,   360,    95,
     167,   168,   169,   207,   285,   210,   322,   322,   144,   145,
     146,    57,   286,    68,    70,    76,    96,   388,   389,   147,
     148,   290,   292,   385,   386,   319,    97,    99,   287,    64,
      64,   102,   156,   399,   158,   170,   171,    22,    23,    24,
      25,   175,   299,   280,     3,     4,   322,   402,    67,   177,
     404,   180,   182,   181,   308,     9,   288,    65,    65,   195,
     282,   137,   225,   201,    32,   293,    32,    63,    11,   301,
     300,   161,   302,   330,   140,   141,   142,   143,   163,   164,
     252,   304,   309,    60,   303,   307,    73,   262,   264,   266,
     267,   268,   269,   270,   273,    72,    72,    72,    72,   311,
     312,    22,    23,    24,    25,   323,   327,   280,   349,   313,
     211,   213,   215,   217,   219,   221,   223,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   240,
     242,   244,   246,   248,   250,   221,   221,   221,   221,   221,
     221,   260,    70,    70,    70,    70,    70,    70,   271,    70,
      70,    70,    70,   341,   154,   342,   338,   102,   350,   351,
     314,    64,   315,    64,   316,   144,   145,   146,   328,   294,
     295,   296,   297,   298,   329,   331,   147,   148,   332,   173,
     103,   111,   184,   184,   339,   397,   129,   333,   226,    65,
     137,    65,    32,   124,   327,   126,   127,   128,   129,   401,
      58,   144,    69,    71,   206,   184,   253,   174,   334,   340,
     185,   185,   348,   263,   265,   265,   265,   265,   265,   265,
     274,   275,   276,   277,   278,   354,   355,   323,   323,   356,
     361,   368,   207,   185,   317,   372,   370,   373,   289,     3,
       4,     5,     6,     7,   375,     8,   282,   390,   377,   392,
       9,   374,   382,   345,   395,   384,   173,   360,    10,   398,
     162,   400,   403,    11,   279,   364,   363,   323,     0,   380,
     173,   327,   381,   319,     0,   391,   365,   393,   108,   109,
     110,   111,   396,     0,   174,    22,    23,    24,    25,     0,
       0,   280,     0,     0,     0,    63,     0,     0,   174,   212,
     214,   216,   218,   220,   222,   224,     0,    70,     0,    22,
      23,    24,    25,     0,     0,   280,     0,   239,   241,   243,
     245,   247,   249,   251,   254,   255,   256,   257,   258,   259,
     261,    71,    71,    71,    71,    71,    71,   272,    71,    71,
      71,    71,   100,   101,     0,     2,     3,     4,     5,     6,
       7,     0,     8,   126,   127,   128,   129,     9,     3,     4,
       5,     6,     7,   203,     8,    10,   152,     0,     0,     9,
      11,   124,   125,   126,   127,   128,   129,    10,     0,   265,
       0,     0,    11,     0,    12,    13,    14,     0,   324,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     1,     0,     0,     2,     3,     4,     5,
       6,     7,     0,     8,    63,     0,     0,     0,     9,     3,
       4,     5,     6,     7,     0,     8,    10,     0,     0,     0,
       9,    11,     0,    22,    23,    24,    25,     0,    10,   280,
       0,     0,     0,    11,     0,    12,    13,    14,     0,     0,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,   101,     0,     2,     3,     4,     5,
       6,     7,     0,     8,     0,    63,   306,     0,     9,     3,
       4,     5,     6,     7,     0,     0,    10,     0,     0,     0,
       9,    11,     0,     0,   336,     0,    71,     0,    10,     0,
       0,     0,     0,    11,     0,    12,    13,    14,     0,     0,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,   101,     0,     2,     3,     4,     5,
       6,     7,     0,     8,     0,   344,   347,   153,     9,    22,
      23,    24,    25,     0,     0,   280,    10,     0,   137,     0,
       0,    11,     0,   165,   166,   167,   168,   169,     0,   138,
     139,   140,   141,   142,   143,    12,    13,    14,   116,   117,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    83,     3,     4,     5,     6,     7,
       0,     8,   152,    84,     0,     0,     9,   124,   125,   126,
     127,   128,   129,   130,    10,     0,     0,     0,     0,    11,
       0,     0,     0,     0,   131,   132,   133,   134,   135,   136,
       0,     0,     0,    12,    13,    14,     0,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     2,     3,     4,     5,     6,     7,     0,     8,
     371,     0,   178,     0,     9,     0,   165,   166,   167,   168,
     169,   137,    10,     0,     0,     0,     0,    11,     0,     0,
       0,     0,   138,   139,   140,   141,   142,   143,     0,     0,
       0,    12,    13,    14,     0,     0,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
       2,     3,     4,     5,     6,     7,     0,     8,     0,     0,
       0,     0,     9,     3,     4,     5,     6,     7,     0,     0,
      10,     0,     0,     0,     9,    11,     0,   165,   166,   167,
     168,   169,    10,     0,     0,     0,     0,    11,   113,    12,
      13,    14,   116,   117,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,   291,     3,
       4,     5,     6,     7,     0,     8,     0,     0,     0,     0,
       9,     0,     0,     3,     4,     5,     6,     7,    10,     8,
     183,     0,     0,    11,     9,     0,     0,     3,     4,     5,
       6,     7,    10,     8,   187,     0,     0,    11,     9,     0,
       0,     3,     4,     5,     6,     7,    10,     8,   189,     0,
       0,    11,     9,     0,     0,    63,     0,     0,     0,     0,
      10,     0,     0,     0,     0,    11,     0,     0,     0,    63,
       3,     4,     5,     6,     7,     0,     8,   191,     0,     0,
       0,     9,     0,    63,     3,     4,     5,     6,     7,    10,
       8,   196,     0,     0,    11,     9,     0,    63,     0,     0,
       0,     0,     0,    10,     0,     0,     0,   151,    11,     0,
       0,     0,   106,   107,   108,   109,   110,   111,   112,     0,
       0,     0,     0,   113,   114,   115,    63,   116,   117,   118,
     119,   120,   121,   122,   123,     0,     0,     0,     0,     0,
      63,   106,   107,   108,   109,   110,   111,   112,     0,     0,
       0,     0,   113,   114,   115,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   124,   125,   126,   127,   128,   129,     0,     0,     0,
       0,   131,   132,   133,   134,   135,   136,   151,     0,     0,
       0,     0,   106,   107,   108,   109,   110,   111,     0,     0,
       0,     0,     0,   113,   114,   115,   151,   116,   117,     0,
     111,   165,   166,   167,   168,   169,   113,   114,   115,     0,
     116,   117,   113,   114,   115,     0,   116,   117,   106,   107,
     108,   109,   110,   111,     0,     0,     0,     0,     0,   113,
     114,   115,     0,   116,   117,   106,     0,   108,   109,   110,
     111,   165,   166,   167,   168,   169,   113,   114,   115,     0,
     116,   117,   113,   114,   115,     0,   116,   117,   165,   166,
     167,   168,   169,     0,     0,   137,     0,     0,     0,   113,
       0,   115,     0,   116,   117,     0,   138,   139,   140,   141,
     142,   143,   108,   109,   110,   111,     0,     0,     0,     0,
       0,   113,   114,   115,     0,   116,   117
  };

  const short
   Parser ::yycheck_[] =
  {
       8,    84,    30,    82,   194,   283,     8,     0,   324,     8,
      18,     3,     4,     5,     6,     7,     8,     8,    10,    11,
     336,     8,    60,    15,     8,     8,     8,     8,     8,    60,
       4,    23,     8,     8,     8,     8,    28,    30,    18,    38,
       3,    15,    41,   359,     8,    61,     8,   316,   317,    12,
      41,   367,    39,    61,    28,    38,    39,     3,    60,    91,
      92,    93,    94,    38,    39,    38,    12,    10,    60,   302,
      60,   304,    80,   101,    82,     9,    60,     7,    60,    60,
      10,    61,   360,    91,    92,    93,    94,   356,     9,    97,
      10,    84,    20,    21,   177,   103,   104,   105,    20,     3,
      80,    10,    82,    31,    32,    39,     3,    11,   101,    31,
      32,    91,    92,    93,    94,    10,    13,    97,    39,    60,
      16,    17,    18,   103,     3,   105,   316,   317,    20,    21,
      22,     7,    11,     9,    10,    11,    60,   370,   371,    31,
      32,   157,   158,    45,    46,    42,    10,     0,   156,   157,
     158,   179,    10,   386,    39,    41,    39,    54,    55,    56,
      57,    60,   170,    60,     4,     5,   356,   400,     8,    12,
     403,     3,    41,    48,   182,    15,   156,   157,   158,     8,
     149,    20,   112,    38,   177,    11,   179,    60,    28,    60,
     170,    67,     9,   201,    33,    34,    35,    36,    74,    75,
     130,     9,   182,     7,    40,     8,    10,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,    39,
      11,    54,    55,    56,    57,   194,   195,    60,   307,    11,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   289,     9,   291,   284,   305,   310,   311,
      11,   289,    11,   291,    12,    20,    21,    22,    11,   165,
     166,   167,   168,   169,    11,     9,    31,    32,    39,   307,
       8,    19,   310,   311,   284,   384,    19,    10,   112,   289,
      20,   291,   305,    14,   283,    16,    17,    18,    19,   398,
       7,    20,     9,    10,   332,   333,   130,   307,     9,    11,
     310,   311,     3,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,    60,    13,   316,   317,     3,
      39,    45,   332,   333,     3,     3,     9,     9,     3,     4,
       5,     6,     7,     8,    41,    10,   335,   375,    41,   377,
      15,    13,    41,   303,   382,     8,   384,    39,    23,     8,
      67,     9,     9,    28,     9,   332,   328,   356,    -1,   361,
     398,   360,   361,    42,    -1,   375,   335,   377,    16,    17,
      18,    19,   382,    -1,   384,    54,    55,    56,    57,    -1,
      -1,    60,    -1,    -1,    -1,    60,    -1,    -1,   398,   106,
     107,   108,   109,   110,   111,   112,    -1,   303,    -1,    54,
      55,    56,    57,    -1,    -1,    60,    -1,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,     0,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    16,    17,    18,    19,    15,     4,     5,
       6,     7,     8,     9,    10,    23,     9,    -1,    -1,    15,
      28,    14,    15,    16,    17,    18,    19,    23,    -1,   303,
      -1,    -1,    28,    -1,    42,    43,    44,    -1,     9,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,     0,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    60,    -1,    -1,    -1,    15,     4,
       5,     6,     7,     8,    -1,    10,    23,    -1,    -1,    -1,
      15,    28,    -1,    54,    55,    56,    57,    -1,    23,    60,
      -1,    -1,    -1,    28,    -1,    42,    43,    44,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    60,    13,    -1,    15,     4,
       5,     6,     7,     8,    -1,    -1,    23,    -1,    -1,    -1,
      15,    28,    -1,    -1,     9,    -1,   303,    -1,    23,    -1,
      -1,    -1,    -1,    28,    -1,    42,    43,    44,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    60,    13,     9,    15,    54,
      55,    56,    57,    -1,    -1,    60,    23,    -1,    20,    -1,
      -1,    28,    -1,    14,    15,    16,    17,    18,    -1,    31,
      32,    33,    34,    35,    36,    42,    43,    44,    29,    30,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,     3,     4,     5,     6,     7,     8,
      -1,    10,     9,    12,    -1,    -1,    15,    14,    15,    16,
      17,    18,    19,    20,    23,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    42,    43,    44,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,     3,     4,     5,     6,     7,     8,    -1,    10,
       9,    -1,    13,    -1,    15,    -1,    14,    15,    16,    17,
      18,    20,    23,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    42,    43,    44,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    15,     4,     5,     6,     7,     8,    -1,    -1,
      23,    -1,    -1,    -1,    15,    28,    -1,    14,    15,    16,
      17,    18,    23,    -1,    -1,    -1,    -1,    28,    25,    42,
      43,    44,    29,    30,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      15,    -1,    -1,     4,     5,     6,     7,     8,    23,    10,
      11,    -1,    -1,    28,    15,    -1,    -1,     4,     5,     6,
       7,     8,    23,    10,    11,    -1,    -1,    28,    15,    -1,
      -1,     4,     5,     6,     7,     8,    23,    10,    11,    -1,
      -1,    28,    15,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    60,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    15,    -1,    60,     4,     5,     6,     7,     8,    23,
      10,    11,    -1,    -1,    28,    15,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    23,    -1,    -1,    -1,     9,    28,    -1,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    25,    26,    27,    60,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      60,    14,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    25,    26,    27,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    14,    15,    16,    17,    18,    19,
      20,    14,    15,    16,    17,    18,    19,    -1,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,     9,    -1,    -1,
      -1,    -1,    14,    15,    16,    17,    18,    19,    -1,    -1,
      -1,    -1,    -1,    25,    26,    27,     9,    29,    30,    -1,
      19,    14,    15,    16,    17,    18,    25,    26,    27,    -1,
      29,    30,    25,    26,    27,    -1,    29,    30,    14,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,
      26,    27,    -1,    29,    30,    14,    -1,    16,    17,    18,
      19,    14,    15,    16,    17,    18,    25,    26,    27,    -1,
      29,    30,    25,    26,    27,    -1,    29,    30,    14,    15,
      16,    17,    18,    -1,    -1,    20,    -1,    -1,    -1,    25,
      -1,    27,    -1,    29,    30,    -1,    31,    32,    33,    34,
      35,    36,    16,    17,    18,    19,    -1,    -1,    -1,    -1,
      -1,    25,    26,    27,    -1,    29,    30
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,     0,     3,     4,     5,     6,     7,     8,    10,    15,
      23,    28,    42,    43,    44,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    63,
      64,    65,    66,    69,    71,    72,    74,    75,    76,    77,
      80,    83,    86,    87,    88,    89,    94,    95,    96,    97,
      99,   100,   101,   102,   103,   105,   107,    99,   100,   101,
     102,     3,    11,    60,    94,    95,    98,     8,    99,   100,
      99,   100,   101,   102,     8,    15,    99,    60,    60,    70,
       8,     8,     8,     3,    12,    66,    67,    68,    94,    95,
      60,    10,    10,    10,    10,    60,    60,    10,    93,     0,
       0,     1,    65,     8,    38,    41,    14,    15,    16,    17,
      18,    19,    20,    25,    26,    27,    29,    30,    31,    32,
      33,    34,    35,    36,    14,    15,    16,    17,    18,    19,
      20,    31,    32,    33,    34,    35,    36,    20,    31,    32,
      33,    34,    35,    36,    20,    21,    22,    31,    32,     8,
      60,     9,     9,     9,     9,    98,    10,    39,    39,     3,
      11,    99,   100,    99,    99,    14,    15,    16,    17,    18,
      41,    39,    73,    94,    95,    60,    73,    12,    13,    64,
       3,    48,    41,    11,    94,    95,   106,    11,   106,    11,
     106,    11,   106,     3,    12,     8,    11,    92,    94,    95,
     106,    38,    65,     9,    90,    91,    94,    95,    94,    94,
      95,    99,   100,    99,   100,    99,   100,    99,   100,    99,
     100,    99,   100,    99,   100,   101,   102,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,   100,
      99,   100,    99,   100,    99,   100,    99,   100,    99,   100,
      99,   100,   101,   102,   100,   100,   100,   100,   100,   100,
      99,   100,   101,   102,   101,   102,   101,   101,   101,   101,
     101,    99,   100,   101,   102,   102,   102,   102,   102,     9,
      60,   104,   107,     8,    41,     3,    11,    94,    95,     3,
      98,     3,    98,    11,    99,    99,    99,    99,    99,    94,
      95,    60,     9,    40,     9,    64,    13,     8,    94,    95,
      39,    39,    11,    11,    11,    11,    12,     3,    13,    42,
      81,    82,    86,   107,     9,    84,    85,   107,    11,    11,
      94,     9,    39,    10,     9,    39,     9,    84,    94,    95,
      11,    98,    98,    68,    60,   101,    68,    13,     3,    73,
     106,   106,    81,    81,    60,    13,     3,    60,    67,     9,
      39,    39,    60,    93,    90,   104,    67,     9,    45,    78,
       9,     9,     3,     9,    13,    41,    81,    41,    67,    84,
      85,   107,    41,    67,     8,    45,    46,    79,    68,    68,
      94,    95,    94,    95,    60,    94,    95,    73,     8,    68,
       9,    73,    68,     9,    68
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    62,    63,    63,    64,    64,    64,    65,    65,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    67,    67,    67,    67,    67,    68,    68,    69,
      70,    70,    71,    71,    71,    72,    72,    72,    73,    73,
      74,    74,    75,    76,    77,    78,    78,    78,    79,    79,
      80,    80,    80,    81,    81,    81,    81,    82,    82,    82,
      82,    82,    83,    83,    83,    83,    84,    84,    84,    85,
      85,    85,    86,    87,    87,    87,    87,    87,    87,    88,
      88,    89,    89,    90,    90,    91,    91,    92,    92,    93,
      93,    94,    94,    94,    94,    94,    95,    95,    96,    96,
      96,    96,    97,    97,    97,    97,    97,    98,    98,    98,
      98,    98,    98,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   103,   103,   104,   104,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   106,   106,   106,   106,   107,
     107,   107,   107,   107,   107,   107
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     1,     2,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     4,     4,     5,     2,     1,     2,
       1,     3,     1,     1,     1,     1,     2,     2,     1,     1,
       7,     7,     5,     6,     7,     5,     6,     0,     2,     0,
       4,     5,     6,     1,     2,     2,     3,     1,     4,     4,
       4,     4,     5,     6,     5,     6,     2,     1,     3,     4,
       4,     3,     2,     4,     4,     4,     4,     4,     4,     3,
       3,     3,     4,     1,     3,     1,     1,     1,     1,     3,
       4,     1,     1,     2,     4,     3,     1,     1,     1,     1,
       1,     1,     2,     3,     4,     4,     5,     1,     1,     3,
       3,     4,     4,     1,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     1,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     3,     1,     3,     4,     3,     4,     3,     4,
       3,     4,     3,     4,     3,     1,     1,     3,     3,     1,
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
  "return", "cond", "for", "while", "dowhile", "if", "elif", "else",
  "struct", "decllist", "declistval", "function", "funargs", "funargdef",
  "vardecl", "vardef", "set", "funcall", "callarglist", "callarg", "index",
  "select", "scope", "expr", "val", "expr_mat", "matvals", "expr_int",
  "expr_float", "expr_str", "expr_bool", "funtype", "typelist", "mattype",
  "matsize", "type", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   167,   167,   168,   170,   171,   172,   176,   177,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   195,   196,   197,   198,   199,   202,   203,   207,
     209,   210,   214,   215,   216,   218,   219,   220,   224,   225,
     229,   230,   234,   237,   241,   243,   244,   245,   247,   248,
     252,   253,   254,   256,   257,   258,   259,   261,   262,   263,
     264,   265,   269,   270,   271,   272,   274,   275,   276,   278,
     279,   280,   284,   288,   289,   290,   291,   292,   293,   297,
     298,   302,   303,   305,   307,   309,   310,   318,   319,   323,
     324,   328,   329,   330,   331,   332,   336,   337,   341,   342,
     343,   344,   348,   349,   350,   351,   352,   354,   355,   356,
     357,   358,   359,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   453,   454,   456,   457,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   472,   473,   474,   475,   479,
     480,   481,   482,   483,   484,   485
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
#line 2209 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"

#line 488 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    std::cerr << scanner->loc->begin.line << ":" << scanner->loc->begin.column << ": " << err_message << std::endl;
}
