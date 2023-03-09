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
  case 317: // expr_int: "int"
#line 602 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 787 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 318: // expr_int: "-" expr_int
#line 603 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 793 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 319: // expr_int: "(" expr_int ")"
#line 604 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 799 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 320: // expr_int: "~" expr_int
#line 605 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 805 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 321: // expr_int: expr_int "*" expr_int
#line 606 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 811 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 322: // expr_int: expr_int "/" expr_int
#line 607 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 817 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 323: // expr_int: expr_int "%" expr_int
#line 608 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 823 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 324: // expr_int: expr_int "-" expr_int
#line 609 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 829 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 325: // expr_int: expr_int "+" expr_int
#line 610 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 835 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 326: // expr_int: expr_int "<<" expr_int
#line 611 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 841 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 327: // expr_int: expr_int ">>" expr_int
#line 612 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 847 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 328: // expr_int: expr_int "&" expr_int
#line 613 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 853 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 329: // expr_int: expr_int "^" expr_int
#line 614 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 859 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 330: // expr_int: expr_int "|" expr_int
#line 615 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 865 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 331: // expr_float: "float"
#line 619 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 871 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 332: // expr_float: "-" expr_float
#line 620 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 877 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 333: // expr_float: "(" expr_float ")"
#line 621 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 883 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 334: // expr_float: expr_float "**" expr_float
#line 622 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 889 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 335: // expr_float: expr_float "**" expr_int
#line 623 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 895 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 336: // expr_float: expr_int "**" expr_float
#line 624 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 901 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 337: // expr_float: expr_float "*" expr_float
#line 625 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 907 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 338: // expr_float: expr_float "*" expr_int
#line 626 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 913 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 339: // expr_float: expr_int "*" expr_float
#line 627 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 919 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 340: // expr_float: expr_float "/" expr_float
#line 628 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 925 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 341: // expr_float: expr_float "/" expr_int
#line 629 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 931 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 342: // expr_float: expr_int "/" expr_float
#line 630 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 937 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 343: // expr_float: expr_float "%" expr_float
#line 631 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 943 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 344: // expr_float: expr_float "%" expr_int
#line 632 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 949 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 345: // expr_float: expr_int "%" expr_float
#line 633 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 955 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 346: // expr_float: expr_float "-" expr_float
#line 634 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 961 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 347: // expr_float: expr_float "-" expr_int
#line 635 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 967 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 348: // expr_float: expr_int "-" expr_float
#line 636 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 973 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 349: // expr_float: expr_float "+" expr_float
#line 637 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 979 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 350: // expr_float: expr_float "+" expr_int
#line 638 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 985 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 351: // expr_float: expr_int "+" expr_float
#line 639 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 991 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 352: // expr_str: "string"
#line 643 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 997 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 353: // expr_str: "(" expr_str ")"
#line 644 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 1003 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 354: // expr_str: expr_str "++" expr_str
#line 645 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 1009 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 355: // expr_str: expr_str "++" expr_int
#line 646 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 1015 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 356: // expr_str: expr_str "++" expr_float
#line 647 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 1021 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 357: // expr_str: expr_str "++" expr_bool
#line 648 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1027 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 358: // expr_str: expr_str "++" expr_none
#line 649 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 1033 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 359: // expr_str: expr_int "++" expr_str
#line 650 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 1039 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 360: // expr_str: expr_int "++" expr_int
#line 651 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 1045 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 361: // expr_str: expr_int "++" expr_float
#line 652 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 1051 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 362: // expr_str: expr_int "++" expr_bool
#line 653 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1057 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 363: // expr_str: expr_int "++" expr_none
#line 654 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 1063 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 364: // expr_str: expr_float "++" expr_str
#line 655 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 1069 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 365: // expr_str: expr_float "++" expr_int
#line 656 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 1075 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 366: // expr_str: expr_float "++" expr_float
#line 657 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 1081 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 367: // expr_str: expr_float "++" expr_bool
#line 658 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1087 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 368: // expr_str: expr_float "++" expr_none
#line 659 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 1093 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 369: // expr_str: expr_bool "++" expr_str
#line 660 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 1099 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 370: // expr_str: expr_bool "++" expr_int
#line 661 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 1105 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 371: // expr_str: expr_bool "++" expr_float
#line 662 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 1111 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 372: // expr_str: expr_bool "++" expr_bool
#line 663 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1117 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 373: // expr_str: expr_bool "++" expr_none
#line 664 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 1123 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 374: // expr_str: expr_none "++" expr_str
#line 665 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 1129 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 375: // expr_str: expr_none "++" expr_int
#line 666 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 1135 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 376: // expr_str: expr_none "++" expr_float
#line 667 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 1141 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 377: // expr_str: expr_none "++" expr_bool
#line 668 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1147 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 378: // expr_str: expr_none "++" expr_none
#line 669 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 1153 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 379: // expr_bool: "bool"
#line 673 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 1159 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 380: // expr_bool: "(" expr_bool ")"
#line 674 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 1165 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 381: // expr_bool: "not" expr_bool
#line 675 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 1171 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 382: // expr_bool: expr_bool "or" expr_bool
#line 676 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 1177 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 383: // expr_bool: expr_bool "and" expr_bool
#line 677 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 1183 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 384: // expr_bool: expr_bool "==" expr_bool
#line 679 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 1189 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 385: // expr_bool: expr_int "==" expr_int
#line 680 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 1195 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 386: // expr_bool: expr_int "==" expr_float
#line 681 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 1201 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 387: // expr_bool: expr_float "==" expr_float
#line 682 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 1207 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 388: // expr_bool: expr_float "==" expr_int
#line 683 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 1213 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 389: // expr_bool: expr_str "==" expr_str
#line 684 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 1219 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 390: // expr_bool: expr_none "==" expr_none
#line 685 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 1225 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 391: // expr_bool: expr_bool "!=" expr_bool
#line 687 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 1231 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 392: // expr_bool: expr_int "!=" expr_int
#line 688 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 1237 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 393: // expr_bool: expr_int "!=" expr_float
#line 689 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 1243 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 394: // expr_bool: expr_float "!=" expr_float
#line 690 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 1249 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 395: // expr_bool: expr_float "!=" expr_int
#line 691 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 1255 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 396: // expr_bool: expr_str "!=" expr_str
#line 692 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 1261 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 397: // expr_bool: expr_none "!=" expr_none
#line 693 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 1267 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 398: // expr_bool: expr_int ">" expr_int
#line 695 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 1273 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 399: // expr_bool: expr_int ">" expr_float
#line 696 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 1279 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 400: // expr_bool: expr_float ">" expr_float
#line 697 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 1285 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 401: // expr_bool: expr_float ">" expr_int
#line 698 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 1291 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 402: // expr_bool: expr_str ">" expr_str
#line 699 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 1297 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 403: // expr_bool: expr_int "<" expr_int
#line 701 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 1303 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 404: // expr_bool: expr_int "<" expr_float
#line 702 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 1309 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 405: // expr_bool: expr_float "<" expr_float
#line 703 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 1315 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 406: // expr_bool: expr_float "<" expr_int
#line 704 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 1321 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 407: // expr_bool: expr_str "<" expr_str
#line 705 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 1327 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 408: // expr_bool: expr_int ">=" expr_int
#line 707 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 1333 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 409: // expr_bool: expr_int ">=" expr_float
#line 708 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 1339 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 410: // expr_bool: expr_float ">=" expr_float
#line 709 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 1345 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 411: // expr_bool: expr_float ">=" expr_int
#line 710 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 1351 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 412: // expr_bool: expr_str ">=" expr_str
#line 711 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 1357 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 413: // expr_bool: expr_int "<=" expr_int
#line 713 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 1363 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 414: // expr_bool: expr_int "<=" expr_float
#line 714 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 1369 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 415: // expr_bool: expr_float "<=" expr_float
#line 715 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 1375 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 416: // expr_bool: expr_float "<=" expr_int
#line 716 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 1381 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 417: // expr_bool: expr_str "<=" expr_str
#line 717 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 1387 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 418: // expr_bool: expr_str "in" expr_str
#line 719 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
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


  const short  Parser ::yypact_ninf_ = -750;

  const short  Parser ::yytable_ninf_ = -448;

  const short
   Parser ::yypact_[] =
  {
    1778,  -750,  -750,  -750,  -750,  -750,  -750,  -750,  2206,    42,
     111,  1654,   345,   -61,   -34,   119,   123,   146,   936,  2248,
    -750,  -750,    95,   115,     9,    10,    20,    23,   113,   144,
     158,   232,  1900,  -750,  -750,   233,   241,  -750,  -750,  -750,
    -750,  -750,  -750,  -750,   246,   313,   320,  -750,  2528,   324,
    2804,  -750,  -750,   572,  -750,  -750,   159,   325,  3038,  2313,
     849,   802,   276,   280,    -5,   346,    52,   219,  2804,   349,
     572,   354,   202,   363,   159,   325,  2695,  2120,   696,   732,
    2248,  -750,    52,    91,   312,    56,   234,   234,  -750,    96,
    -750,  -750,  2296,   220,  3061,  3200,  1583,  -750,   345,   345,
    -750,   328,  -750,   322,  2248,   329,  2248,   392,  2176,  -750,
    -750,   373,  -750,   365,  -750,   434,  -750,   587,  -750,  1024,
    -750,  1084,  -750,   165,   428,   494,    30,  -750,  -750,  -750,
    -750,  2680,  -750,  -750,  -750,  -750,  -750,  -750,  1157,  1286,
     378,  2248,  2248,  2248,  2248,  2248,  2248,  2248,  2248,  2248,
    2248,  2248,  2248,  2248,  2248,  -750,  2248,  2248,  2248,  2248,
    2248,  2248,  2248,  2248,  2248,  2248,  2248,  2248,  2248,  2248,
    2248,  2248,  2248,  2248,  2248,  2248,  2248,  2248,  2248,  2248,
    2248,  2248,  2248,  2248,  2248,  2248,  2248,  2248,  2248,  2248,
    2248,  2248,  2248,  2248,  2248,  2248,  2248,  2248,   234,  2248,
    2248,  2248,  2248,  2248,  2248,  2248,  2248,  2248,  2248,  2248,
    2248,  2248,  2248,  2248,  2248,  2248,  2248,  2248,  2248,  2248,
    2248,  2248,  2248,  2248,  2248,  2248,  2248,  2248,  2248,  2248,
    2248,  2248,  2248,  2248,  2248,  2248,  2248,  2248,  2248,  2248,
    2248,  -750,  -750,    54,    -3,  -750,  1481,   444,  -750,  -750,
    -750,  2248,  2248,  -750,  -750,  -750,  -750,  -750,   100,   331,
     447,  -750,  1365,  1406,   234,   234,   234,   234,   234,   345,
     345,   345,   345,   345,   234,   234,   234,   234,   234,   234,
    2749,  2777,   822,   677,  1654,   196,   196,  1654,   234,   234,
     234,   234,   234,   234,  1654,   234,   234,   234,   234,   234,
     234,  1654,  1654,  1654,  1654,  1654,  1654,  1654,  1654,  1654,
    1654,  1654,  1654,  1654,  1904,  -750,   345,   345,   345,   345,
     345,  2248,   382,   463,   433,   478,  2680,  -750,  1977,   480,
    2248,  -750,   451,  3038,  2313,   849,   802,   481,  -750,   485,
    -750,   495,  -750,   505,   507,    26,   359,  -750,   647,   245,
     510,  -750,   417,   518,  -750,  -750,   523,   496,   673,   493,
     528,  -750,  -750,  -750,  -750,  -750,  -750,  -750,  -750,  -750,
    -750,  -750,  -750,  -750,  -750,  -750,   541,   508,   170,   263,
     781,   508,   170,   263,   781,   352,   544,   537,   540,   352,
     537,   540,   352,   537,   540,   352,  3038,   540,  2831,   400,
     419,  3084,  2054,   479,   529,  2885,   576,  2858,   229,  2918,
     360,  3002,  3011,  2966,  3130,  1532,  3153,   559,   999,   559,
     999,  1737,   675,  -750,  -750,  1435,   953,   236,  -750,  1737,
     675,  -750,  -750,  1435,   953,   236,  -750,  1196,  1929,  1186,
     553,  1196,  1929,  1186,   553,  1196,  1929,  1186,   553,  1196,
    1929,  1186,   553,   560,   508,   170,   508,   170,   352,   544,
    2918,   445,  1737,   675,  1737,   675,  2831,   400,   419,  3084,
    2054,   479,   529,  2918,   445,  1737,  -750,  1737,  -750,  2831,
     400,   419,  3084,  2054,   479,   529,  2918,   445,  1737,  -750,
    1737,  -750,   508,   263,   781,   508,   263,   781,   352,   537,
     540,   352,   537,   540,   352,   537,   540,  1252,   570,  2831,
     400,   419,  3084,  2054,   479,   529,  2918,   445,  3002,  3011,
    2966,  3130,  1532,  3153,   559,   999,   559,   999,  1737,  1435,
     953,  1737,  1435,   953,  1196,  1929,  1186,  1196,  1929,  1186,
    1196,  1929,  1186,  1196,  1929,  1186,   508,   263,   781,   508,
     263,   781,   352,   537,   540,   352,   537,   540,   352,   537,
     540,   352,   537,   540,  2831,   400,   419,  3084,  2054,   479,
     529,  2918,   445,  1737,  1435,   953,  1737,  1435,   953,  1196,
    1929,  1186,  1196,  1929,  1186,  1196,  1929,  1186,  1196,  1929,
    1186,   561,  2831,   400,   419,  3084,  2054,   479,   529,  2918,
     445,   360,  1737,   236,  1737,   236,  1196,   553,  1196,   553,
    1196,   553,  1196,   553,  2831,   400,   419,  3084,  2054,   479,
     529,  2885,   576,  2858,   229,  2918,   445,  1737,  -750,  1737,
    -750,  -750,    31,   590,    27,   411,  1233,   565,  -750,   592,
     574,   601,  -750,  2248,  -750,  -750,   833,   858,   833,   858,
     537,   570,   537,   570,   537,   570,  1118,   616,   708,  1415,
    1415,   833,   858,   833,   858,   537,   570,   537,   570,   537,
     570,   537,   570,   287,  3107,  3208,   877,   292,   602,  -750,
    -750,   287,  3107,  3208,   877,   292,  1979,  1444,  1979,  1444,
    1979,  1444,  1979,  1444,  1979,  1444,  1979,  1444,   287,  3107,
    3208,   877,   292,  1979,  1444,  1979,  1444,  1979,  1444,  1979,
    1444,  1979,  1444,  1979,  1444,   287,  3107,  3208,   877,   292,
     383,   344,   870,   870,  -750,  -750,  -750,  -750,   287,  3107,
    3208,   877,   292,   366,   168,  -750,  -750,   430,   430,  -750,
    -750,  -750,  -750,  -750,   936,   892,   936,  2103,   612,  2248,
    -750,  2248,  -750,  -750,  -750,  -750,     4,     4,  -750,   562,
     624,   642,  -750,     8,   319,   124,   610,    14,  -750,  1495,
      40,   804,  -750,   615,  -750,  -750,  2248,  -750,  1530,    49,
     950,  -750,  -750,  -750,  1687,  -750,   598,   319,   127,  -750,
    -750,  -750,  2248,  -750,  -750,   346,   605,   662,  1035,  -750,
     671,  -750,   683,  -750,   669,  -750,   653,  -750,     4,   654,
    -750,   319,   598,   598,   659,  -750,   692,  -750,  1721,  -750,
    1804,    73,  2248,  -750,  -750,   693,  -750,  1851,  -750,  1865,
      98,  -750,  -750,   319,   698,   709,   342,   936,   936,  -750,
    -750,  -750,  2248,  -750,  2248,  -750,   679,   610,    18,  2248,
    -750,  -750,   724,  -750,   728,  -750,  2007,   680,  -750,  -750,
     729,  -750,   731,  -750,  2051,  -750,  -750,  2248,   741,   936,
    -750,  -750,  -750,  -750,  -750,   659,  -750,  -750,  -750,  -750,
     739,   717,  -750,  -750,  -750,   746,   749,  2248,  -750,  -750,
    -750,  -750,   936,   751,  -750,   936,  -750
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     7,   317,   331,   352,   379,   309,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      31,    32,     0,     0,   443,   444,   445,   446,     0,     0,
      89,     0,     0,     4,     8,     0,     0,    33,    13,    15,
      16,    14,    17,    18,     0,     0,     0,    90,    97,     0,
      93,    96,   275,    92,   276,   277,    94,    95,   263,   264,
     265,   266,   448,   449,     0,   309,    89,    97,   284,   275,
       0,   276,     0,   277,     0,     0,   283,     0,     0,     0,
       0,   267,    89,    97,   272,     0,     0,     0,    89,    98,
     318,   332,     0,     0,     0,     0,     0,   381,     0,     0,
     320,     0,    29,    28,     0,     0,     0,     0,     0,    26,
      27,     0,    35,     0,   435,     0,   436,     0,   437,     0,
     438,     0,   439,     0,     0,     0,     0,   440,   311,     1,
       3,     0,     5,    12,    19,    10,    11,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   441,   442,     0,    65,   310,     0,   311,    99,   278,
     280,     0,     0,   279,   319,   333,   353,   380,     0,     0,
       0,   268,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   318,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,     0,     0,
       0,   426,   433,   283,     0,     0,     0,     0,   428,     0,
     430,     0,   432,     0,     0,     0,     0,   424,     0,   433,
       0,   313,     0,     0,     6,    85,     0,    87,     0,     0,
      91,    84,    83,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,     0,   131,   129,   126,
     127,   139,   137,   134,   135,   113,   112,   108,   109,   118,
     116,   117,   123,   121,   122,   105,     0,   104,   262,   260,
     261,   256,   257,   258,   259,   235,   234,   238,   237,   232,
     231,   210,   209,   216,   215,   213,   212,   142,   141,   145,
     144,   190,   188,   185,   186,   181,   182,   183,   184,   207,
     205,   202,   203,   198,   199,   200,   201,   152,   149,   150,
     151,   166,   163,   164,   165,   159,   156,   157,   158,   173,
     170,   171,   172,     0,   130,   128,   138,   136,   111,   110,
     230,   223,   189,   187,   206,   204,   254,   378,   243,   375,
     376,   374,   377,   228,   221,   178,   390,   195,   397,   255,
     248,   249,   244,   245,   246,   247,   229,   222,   180,   179,
     197,   196,   124,   325,   351,   132,   324,   348,   106,   321,
     339,   114,   322,   342,   119,   323,   345,     0,   336,   250,
     363,   239,   360,   361,   359,   362,   224,   217,   208,   328,
     214,   330,   211,   329,   140,   326,   143,   327,   174,   385,
     386,   191,   392,   393,   146,   398,   399,   160,   403,   404,
     153,   408,   409,   167,   413,   414,   125,   350,   349,   133,
     347,   346,   107,   338,   337,   115,   341,   340,   120,   344,
     343,   103,   335,   334,   251,   368,   240,   365,   366,   364,
     367,   225,   218,   175,   388,   387,   192,   395,   394,   147,
     401,   400,   161,   406,   405,   154,   411,   410,   168,   416,
     415,     0,   252,   358,   241,   355,   356,   354,   357,   226,
     219,   418,   176,   389,   193,   396,   148,   402,   162,   407,
     155,   412,   169,   417,   253,   373,   242,   370,   371,   369,
     372,   233,   383,   236,   382,   227,   220,   177,   384,   194,
     391,   420,   447,     0,   421,     0,     0,     0,   312,     0,
       0,     0,   269,     0,   273,   270,   325,   351,   324,   348,
     321,   339,   322,   342,   323,   345,   328,   330,   329,   326,
     327,   350,   349,   347,   346,   338,   337,   341,   340,   344,
     343,   335,   334,   378,   375,   376,   374,   377,     0,   390,
     397,   363,   360,   361,   359,   362,   385,   386,   392,   393,
     398,   399,   403,   404,   408,   409,   413,   414,   368,   365,
     366,   364,   367,   388,   387,   395,   394,   401,   400,   406,
     405,   411,   410,   416,   415,   358,   355,   356,   354,   357,
     418,     0,   389,   396,   402,   407,   412,   417,   373,   370,
     371,   369,   372,   383,   382,   384,   391,   325,   324,   321,
     322,   323,    69,    30,     0,     0,     0,     0,    22,     0,
      68,     0,   425,   427,   429,   431,     0,    49,    46,     0,
       0,     0,    53,     0,     0,     0,    61,     0,   285,     0,
       0,     0,   423,     0,   314,    86,     0,   297,     0,     0,
       0,   102,   101,   100,     0,   419,     0,     0,     0,    67,
      66,   281,     0,   271,   274,     0,    43,     0,     0,    38,
      23,    24,     0,   434,     0,    50,     0,    47,    51,    65,
      58,     0,     0,     0,    60,   289,     0,   287,     0,   286,
       0,     0,     0,    88,   301,     0,   299,     0,   298,     0,
       0,   422,    56,     0,     0,     0,    45,     0,     0,    25,
      39,    48,     0,    52,     0,    59,    62,    64,     0,     0,
     292,   291,     0,   290,     0,   288,     0,   315,   304,   303,
       0,   302,     0,   300,     0,    57,   282,     0,     0,     0,
      40,    36,    37,    55,    54,     0,    63,   295,   294,   293,
       0,     0,   307,   306,   305,     0,     0,     0,    44,   296,
     316,   308,     0,     0,    41,     0,    42
  };

  const short
   Parser ::yypgoto_[] =
  {
    -750,  -750,   -95,   -10,     5,  -749,  -635,  -750,  -750,  -750,
    -750,  -750,  -750,  -750,  -750,  -750,  -750,  -750,  -701,  -750,
    -750,  -633,   -51,  -333,  -750,   625,  -750,    -9,    25,   784,
    2430,  -750,   760,   -77,  1256,   765,   895,   766,  1046,  1449,
     -65,  -106,  2196,     0,   237,   476,  -750,     6,  -750,   -91,
    -227
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    31,    32,    33,   109,   110,   111,    35,   103,    36,
      37,    38,    39,    40,    41,   836,   870,    42,   760,   761,
      43,   765,   766,    44,    45,    46,    47,   356,    83,    49,
      50,    51,    52,    85,    70,    54,   332,    55,    74,    75,
     128,   353,    58,   334,   335,   336,    62,   633,    63,   350,
      64
  };

  const short
   Parser ::yytable_[] =
  {
      59,   247,   788,   258,   243,    34,   635,   757,    77,    59,
      91,    95,   762,   328,   101,   810,   634,   243,    59,    59,
     115,   117,   132,   243,   337,    48,   339,   243,   341,   757,
     343,   119,    59,    67,   121,    89,   243,    34,   832,   636,
     758,   102,   784,    48,   351,    80,     3,     4,     5,     6,
       7,     8,   817,     9,    81,   804,   805,    48,    10,   260,
     759,   826,   845,   246,   631,   126,    11,   786,   261,   352,
     244,    12,    23,    24,    25,    26,    27,   116,   118,   632,
      59,   818,   759,   809,   865,   855,   263,    91,   120,   814,
     827,   122,   281,   875,    23,    24,    25,    26,    27,   127,
     138,   632,   139,   641,    59,   138,    59,   843,    59,   796,
     863,   799,   642,    34,   856,     3,     4,    82,   763,   767,
      86,   354,    23,    24,    25,    26,    27,    87,   104,   632,
     140,    59,   105,    48,   811,   140,    34,   833,    59,   864,
      12,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,   106,    48,   380,   384,   388,
     391,   394,   397,   402,   812,   360,    48,   812,   344,   125,
     113,   126,   426,   434,   439,   443,   447,   451,   345,   846,
     185,   178,   644,   114,   186,   470,    88,   181,   123,   483,
     310,   187,   188,   494,   497,   500,   503,   506,   508,   513,
     312,   313,   871,   872,     7,   678,   530,   533,   536,   539,
     542,   545,   548,   551,   554,   557,   560,   563,   568,   124,
     575,   578,   581,   584,   587,   590,   127,   596,   138,   248,
     139,   747,   129,  -447,   888,   618,   133,    60,     3,     4,
     251,   284,   252,    86,   134,    78,    60,   226,    96,   135,
      87,   236,   285,   286,   238,    60,    60,   894,   140,    59,
     896,   239,   240,    12,   647,   649,   651,   653,   655,    60,
     231,   232,   233,   234,   662,   664,   666,   668,   670,   672,
     195,   196,   197,   198,   675,   751,   771,   683,   687,   689,
     691,   693,   695,   697,   700,   704,   706,   708,   710,   712,
     714,   717,    95,    95,    95,    95,    95,    95,    95,   730,
      95,    95,    95,    95,   310,   311,   136,    60,   132,   285,
     286,    59,   107,   137,   312,   313,    59,   155,    59,   282,
      59,    34,   108,    34,   643,     3,     4,     5,     6,     7,
       8,    60,     9,    60,   241,    60,   189,    10,   242,     3,
     190,    48,   259,    48,    98,    11,   245,   191,   192,   249,
      12,    99,   322,   156,   250,   309,   310,   311,    60,   764,
     321,   226,   162,   253,    12,    60,   312,   313,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,   229,   230,   231,   232,   233,   234,   312,   313,
     403,   868,   869,   410,   324,   326,    82,   330,   767,   427,
     435,   440,   444,   448,   452,   303,   304,   305,   306,   307,
     308,   787,   471,   762,   762,   186,   484,    23,    24,    25,
      26,    27,   187,   188,   632,   329,   514,   346,     3,     4,
       5,     6,     7,     8,   190,     9,   331,   318,   319,   320,
      10,   191,   192,    88,   638,   569,   178,   743,    11,   645,
     179,   180,   181,    12,   597,   601,   603,   605,   607,   609,
     611,   613,   619,   744,   745,   762,    61,   183,   184,    23,
      24,    25,    26,    27,    79,    61,   632,    97,   746,   749,
     226,   751,   773,   752,    61,    61,    60,   753,     3,     4,
       5,     6,     7,     8,   228,     9,   347,   754,    61,    82,
      10,   229,   230,   231,   232,   233,   234,   755,    11,   156,
     756,   676,   772,    12,   684,   159,   160,   161,   162,   763,
     763,   701,   774,   775,   780,   348,   776,   138,   718,   720,
     722,   723,   724,   725,   726,   727,   731,    96,    96,    96,
      96,   236,   237,   781,   238,   178,    61,   198,    60,   634,
     217,   239,   240,    60,   226,    60,   794,    60,   283,    82,
     156,   790,   782,   783,   157,   158,   159,   160,   161,   162,
      61,   763,    61,   178,    61,   767,   848,   179,   180,   181,
     279,     3,     4,     5,     6,     7,     8,   182,     9,   338,
     785,   238,   791,    10,   183,   184,   771,    61,   239,   240,
     795,    11,   792,   793,    61,   801,    12,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,   316,   317,   318,   319,   320,    59,   806,   807,   404,
     406,   408,   269,    59,   271,   808,   272,   273,   428,   436,
     813,     3,     4,     5,     6,     7,     8,   822,     9,   768,
     803,   472,    82,    10,   835,   485,    23,    24,    25,    26,
      27,    11,   837,   632,   839,   515,    12,     3,     4,     5,
       6,     7,     8,   841,     9,   777,   178,   257,   769,    10,
     179,   180,   181,   840,   570,   842,   844,    11,   309,   310,
     311,   849,    12,   598,   850,   858,   256,   226,   866,   312,
     313,   620,   622,   624,   778,   628,   630,   227,   867,   812,
     881,   228,    82,   316,   317,   318,   319,   320,   229,   230,
     231,   232,   233,   234,   269,    61,   877,   132,   272,   273,
     878,   882,   257,   883,    59,    95,    59,    59,    82,    59,
     887,   889,    34,   235,   236,   237,   352,   238,   891,   892,
     677,   895,   847,   685,   239,   240,   361,   823,    69,    48,
     702,    48,    48,    71,    73,   890,    59,   719,   721,   721,
     721,   721,   721,   721,   721,   732,   733,   734,   735,   736,
       0,     0,   831,    84,     0,     0,     0,    61,   214,   215,
     216,   217,    61,   112,    61,     0,    61,     0,     3,     4,
       5,     6,     7,     8,     0,     9,   819,     0,     0,     0,
      10,     0,    59,   235,   236,   237,     0,   238,    11,     0,
       0,     0,   256,    12,   239,   240,     0,    59,    59,     0,
       0,     0,    59,   301,    59,   820,     0,   302,     0,    59,
     266,   267,   268,   198,   303,   304,   305,   306,   307,   308,
     226,     0,    48,    48,    84,     0,     0,    59,     0,    59,
     227,     0,     0,    60,   228,   276,   277,   278,   279,    82,
      60,   229,   230,   231,   232,   233,   234,    59,   323,     0,
     325,     0,    59,     0,    48,    59,     3,     4,     5,     6,
       7,    92,   302,    72,   305,   306,   307,   308,    87,   303,
     304,   305,   306,   307,   308,     0,    11,    48,     0,     0,
      48,    12,   357,     0,     0,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   107,
       3,     4,     5,     6,     7,     8,     0,     9,     0,   108,
       0,     0,    10,     0,     3,     4,     5,     6,     7,     8,
      11,     9,   828,     0,     0,    12,    10,   797,   212,   213,
     214,   215,   216,   217,    11,     0,     0,     0,     0,    12,
       0,    60,   798,    60,    60,     0,    60,   222,   223,   224,
     225,   829,    13,    14,    15,     0,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     0,    60,   193,   194,   195,   196,   197,   198,
     349,     0,     0,     0,     0,    82,     0,     0,     3,     4,
       5,     6,     7,     8,   359,     9,   340,     0,     0,     0,
      10,     0,     0,    84,     0,   838,    56,     0,    11,     0,
       0,   376,     0,    12,     0,    56,   301,    93,     0,    60,
     302,     0,     0,     0,    56,    56,     0,   303,   304,   305,
     306,   307,   308,   453,    60,    60,     0,     0,    56,    60,
       0,    60,     0,     0,     0,     0,    60,     0,     3,     4,
       5,     6,     7,     8,     0,     9,   342,     0,     0,    82,
      10,     0,     0,     0,    60,   742,    60,     0,    11,     0,
       0,     0,    61,    12,   750,     0,     0,     0,     0,    61,
       0,   591,     0,     0,    60,     0,    56,     0,     0,    60,
       0,     0,    60,   316,   317,   318,   319,   320,    93,     0,
       0,   637,     0,     0,     0,     0,   639,   640,   272,   273,
      56,     0,    56,     0,    56,     0,     0,     0,     0,    82,
       0,     3,     4,     5,     6,     7,     8,   355,     9,     0,
       0,     0,     0,    10,     0,     0,     0,    56,     0,     0,
       0,    11,     0,     0,    56,     0,    12,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,   212,   213,   214,   215,   216,   217,   156,     0,   399,
       0,   157,   158,   159,   160,   161,   162,     0,   423,   431,
      61,   721,    61,    61,     0,    61,   170,   171,     0,     0,
       0,   467,    82,   476,   478,   480,     0,     3,     4,     5,
       6,     7,     8,   770,     9,   510,   126,     0,     0,    10,
       0,     0,    61,   779,     0,     0,    53,    11,     0,     0,
       0,     0,    12,     0,   565,    53,     0,   264,   265,   266,
     267,   268,   198,   593,    53,    53,     0,     0,   269,   270,
     271,   615,   272,   273,     0,     0,     0,     0,    53,     0,
       3,     4,     5,     6,     7,     8,     0,     9,    61,     0,
       0,     0,    10,     0,     0,    56,     0,     0,    82,     0,
      11,     0,     0,    61,    61,    12,     0,     0,    61,     0,
      61,     0,     0,     0,     0,    61,     0,   358,     0,     0,
     673,   679,   680,   681,     0,     0,    53,     0,     0,     0,
     698,     0,     0,    61,     0,    61,     0,   715,    93,    93,
      93,    93,    93,    93,    93,   728,    93,    93,    93,    93,
      53,    82,    53,    61,    53,     0,     0,    56,    61,     0,
       0,    61,    56,     0,    56,   254,    56,     0,     0,     0,
     264,   265,   266,   267,   268,   198,     0,    53,     0,     0,
       0,   269,   270,   271,    53,   272,   273,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,     0,     0,   378,   382,   386,   255,     0,     0,     0,
     789,   274,   275,   276,   277,   278,   279,    84,   422,   430,
     316,   317,   318,   319,   320,   455,   457,   459,   461,   463,
     465,     0,   474,     0,     0,     0,   487,     0,     0,    57,
     193,   194,   195,   196,   197,   198,   517,     0,    57,   274,
     275,   276,   277,   278,   279,   204,   205,    57,    57,   208,
     209,   210,   211,     0,     0,   572,     0,     0,     0,     0,
       0,    57,     0,     0,   600,     3,     4,     5,     6,     7,
       8,     0,     9,     0,   626,     0,     0,    10,     0,     3,
       4,     5,     6,     7,     8,    11,     9,   815,     0,     0,
      12,    10,     0,     0,     0,    53,     0,     0,     0,    11,
       0,     0,   348,     0,    12,     0,     0,     0,     0,    57,
       0,     0,     0,   802,     3,     4,     5,     6,     7,     8,
       0,     9,   824,   156,     0,     0,    10,   157,   158,   159,
     160,   161,   162,    57,    11,    57,    82,    57,   167,    12,
     357,     0,   170,   171,   172,   173,   174,   175,   176,   177,
      82,     0,     0,     0,     0,     0,     0,    53,     0,     0,
      57,     0,    53,     0,    53,     0,    53,    57,     0,     0,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,   301,    82,   857,     0,   302,     0,
       0,     0,   400,     0,     0,   303,   304,   305,   306,   307,
     308,   424,   432,     0,     0,     0,   873,     0,   874,     0,
       0,     0,     0,   876,   468,     0,     0,     0,   481,     0,
     489,   491,     0,     0,     0,     0,     0,     0,   511,     0,
       0,   886,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,    92,   816,     0,   821,   566,     0,     0,
      87,   893,     0,   825,     0,   830,   594,     0,    11,     0,
       0,     0,    56,    12,   616,     0,     0,   834,     0,    56,
       0,     3,     4,     5,     6,     7,     8,     0,     9,   347,
       0,     0,     0,    10,     0,     0,     0,     0,    57,     0,
       0,    11,     0,   852,     0,   854,    12,     0,     0,     0,
       0,     0,   860,     0,   862,     3,     4,     5,     6,     7,
       8,     0,     9,   851,     0,     0,     0,    10,     0,     0,
       0,     0,     0,     0,     0,    11,     0,     0,   156,     0,
      12,   880,   157,   158,   159,   160,   161,   162,     0,   885,
       0,     0,    82,     0,     0,     0,     0,   170,   171,     0,
      57,   174,   175,   176,   177,    57,     0,    57,     1,    57,
       0,     2,     3,     4,     5,     6,     7,     8,     0,     9,
      56,    93,    56,    56,    10,    56,    82,     0,     0,     0,
       0,     0,    11,     0,     0,     0,     0,    12,     3,     4,
       5,     6,     7,     8,     0,     9,   853,     0,     0,     0,
      10,     0,    56,     0,     0,     0,     0,     0,    11,     0,
       0,     0,     0,    12,    13,    14,    15,     0,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,     0,     3,     4,     5,     6,     7,
       8,     0,     9,   859,     0,     0,     0,    10,    56,     3,
       4,     5,     6,     7,     8,    11,     9,   861,     0,    82,
      12,    10,     0,    56,    56,     0,     0,     0,    56,    11,
      56,     0,    53,     0,    12,    56,     0,     0,     0,    53,
     130,   131,     0,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,    56,   254,    56,    10,     0,     0,   316,
     317,   318,   319,   320,    11,     0,    82,     0,     0,    12,
     269,   270,   271,    56,   272,   273,     0,     0,    56,     0,
      82,    56,     0,     0,   193,   194,   195,   196,   197,   198,
       0,     0,     0,     0,     0,     0,    13,    14,    15,   204,
     205,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,     0,     0,   131,     0,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,   748,     0,    10,   264,   265,   266,   267,   268,   198,
      53,    11,    53,    53,     0,    53,    12,     0,     0,   272,
     273,     3,     4,     5,     6,     7,     8,     0,     9,   879,
       0,     0,     0,    10,     0,     0,     0,     0,     0,     0,
       0,    11,    53,    13,    14,    15,    12,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,     0,     0,     3,     4,     5,     6,     7,
       8,     0,     9,   884,     0,     0,     0,    10,     0,   212,
     213,   214,   215,   216,   217,    11,     0,     0,    53,   219,
      12,     0,    82,     0,     0,    57,   220,   221,   222,   223,
     224,   225,    57,    53,    53,     0,     0,     0,    53,     0,
      53,     0,     0,     0,   131,    53,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,   800,     0,    10,
       0,     0,     0,    53,     0,    53,    82,    11,     0,     0,
     255,     0,    12,     0,     0,   212,   213,   214,   215,   216,
     217,   218,     0,    53,     0,   219,     0,     0,    53,     0,
       0,    53,   220,   221,   222,   223,   224,   225,     0,    13,
      14,    15,     0,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
     327,     0,    10,    57,     0,    57,    57,     0,    57,     0,
      11,     0,     0,     0,    76,    12,    90,    94,   100,     0,
       3,     4,     5,     6,    65,     8,     0,     9,     0,     0,
       0,     0,    10,     0,     0,    57,     0,     0,     0,     0,
      11,     0,    13,    14,    15,    12,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,     0,     0,    10,     0,     0,     0,     0,     0,
       0,    57,    11,     0,     0,     0,     0,    12,     0,     0,
       0,    66,   262,    90,     0,     0,    57,    57,   280,     0,
       0,    57,     0,    57,   314,   315,     0,     0,    57,     0,
       3,     4,     5,     6,    65,    92,     0,     0,     0,     0,
       0,   333,    87,   333,     0,   333,    57,   333,    57,     0,
      11,   333,     0,    82,     0,    12,     0,     0,   212,   213,
     214,   215,   216,   217,   218,   333,    57,     0,   219,     0,
       0,    57,     0,     0,    57,   220,   221,   222,   223,   224,
     225,     0,   333,   379,   383,   387,   390,   393,   396,   401,
     396,   396,   396,   412,   414,   416,   418,   420,   425,   433,
     438,   442,   446,   450,   333,   396,   396,   396,   396,   396,
     396,   469,   396,   396,   396,   482,   396,   396,   396,   493,
     496,   499,   502,   505,   507,   512,   396,   519,   521,   523,
     525,   527,   529,   532,   535,   538,   541,   544,   547,   550,
     553,   556,   559,   562,   567,   396,   574,   577,   580,   583,
     586,   589,   333,   595,   396,   396,   396,   396,   396,   396,
     396,   617,   396,   396,   396,   396,   396,     0,    68,     0,
       0,     0,   333,     0,     0,     0,     0,   333,   333,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     646,   648,   650,   652,   654,   656,   657,   658,   659,   660,
     661,   663,   665,   667,   669,   671,     0,     0,     0,     0,
     674,     0,     0,   682,   686,   688,   690,   692,   694,   696,
     699,   703,   705,   707,   709,   711,   713,   716,    94,    94,
      94,    94,    94,    94,    94,   729,    94,    94,    94,    94,
       0,     0,   737,   738,   739,   740,   741,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138,     0,   139,
       0,     0,     0,     0,   333,    68,     0,    68,     0,    68,
       0,    68,     0,     0,   333,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   140,     0,    68,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,     0,     0,    68,   377,   381,   385,
     389,   392,   395,   398,   405,   407,   409,   411,   413,   415,
     417,   419,   421,   429,   437,   441,   445,   449,    68,   454,
     456,   458,   460,   462,   464,   466,   473,   475,   477,   479,
     486,   488,   490,   492,   495,   498,   501,   504,     0,   509,
     516,   518,   520,   522,   524,   526,   528,   531,   534,   537,
     540,   543,   546,   549,   552,   555,   558,   561,   564,   571,
     573,   576,   579,   582,   585,   588,    68,   592,   599,   602,
     604,   606,   608,   610,   612,   614,   621,   623,   625,   627,
     629,     0,     0,     0,     0,     0,    68,     0,     0,     0,
       0,    68,    68,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,     0,     0,    10,     0,     0,     0,
       0,     0,     0,     0,    11,   254,     0,     0,     0,    12,
     193,   194,   195,   196,   197,   198,   199,     0,     0,     0,
     200,   201,   202,   203,     0,   204,   205,   206,   207,   208,
     209,   210,   211,     0,     0,     0,    13,    14,    15,     0,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,     0,     0,     0,   254,
       0,     0,     0,     0,   264,   265,   266,   267,   268,   198,
     287,     0,     0,     0,     0,   269,   270,   271,    68,   272,
     273,   288,   289,   290,   291,   292,   293,   255,    68,     0,
       0,     0,   274,   275,   276,   277,   278,   279,   294,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   295,
     296,   297,   298,   299,   300,   156,     0,     0,     0,   157,
     158,   159,   160,   161,   162,   163,   164,   165,     0,   166,
     167,   168,   169,     0,   170,   171,   172,   173,   174,   175,
     176,   177,   156,     0,     0,     0,   157,   158,   159,   160,
     161,   162,     0,   164,   165,     0,   166,   167,   168,   169,
       0,   170,   171,   172,   173,   174,   175,   176,   177,   156,
       0,     0,     0,   157,   158,   159,   160,   161,   162,     0,
     164,     0,     0,   166,   167,   168,   169,     0,   170,   171,
     172,   173,   174,   175,   176,   177,   156,     0,     0,     0,
     157,   158,   159,   160,   161,   162,     0,     0,     0,     0,
     166,   167,   168,   169,     0,   170,   171,   172,   173,   174,
     175,   176,   177,     0,     0,     0,     0,     0,     0,   156,
       0,     0,     0,   157,   158,   159,   160,   161,   162,     0,
       0,    94,     0,     0,   167,   168,   169,   333,   170,   171,
     172,   173,   174,   175,   176,   177,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   333,     0,   333,     0,     0,
       0,     0,     0,     0,   333,     0,   333,   156,     0,     0,
     333,   157,   158,   159,   160,   161,   162,     0,   333,     0,
       0,     0,   167,     0,   169,     0,   170,   171,   172,   173,
     174,   175,   176,   177,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   156,   333,     0,   333,   157,   158,   159,
     160,   161,   162,   333,     0,   333,   193,   194,   195,   196,
     197,   198,   170,   171,   172,   173,   174,   175,   176,   177,
       0,   204,   205,   206,   207,   208,   209,   210,   211,     0,
       0,     0,   333,   193,   194,   195,   196,   197,   198,   199,
     333,     0,     0,   200,   201,   202,   203,     0,   204,   205,
     206,   207,   208,   209,   210,   211,   264,   265,   266,   267,
     268,   198,   287,     0,     0,     0,     0,   269,   270,   271,
       0,   272,   273,   288,   289,   290,   291,   292,   293,   193,
     194,   195,   196,   197,   198,     0,     0,     0,     0,   200,
     201,   202,   203,     0,   204,   205,   206,   207,   208,   209,
     210,   211,   264,   265,   266,   267,   268,   198,     0,     0,
       0,     0,     0,   269,   270,   271,     0,   272,   273,   288,
     289,   290,   291,   292,   293,   193,   194,   195,   196,   197,
     198,     0,     0,     0,     0,     0,   201,     0,   203,     0,
     204,   205,   206,   207,   208,   209,   210,   211,   193,   194,
     195,   196,   197,   198,     0,     0,     0,     0,     0,   201,
       0,    68,     0,   204,   205,   206,   207,   208,   209,   210,
     211,     0,     0,     0,     0,     0,     0,     0,     0,    68,
       0,    68,     0,     0,     0,     0,     0,     0,    68,     0,
      68,     0,     0,     0,    68,   274,   275,   276,   277,   278,
     279,   294,    68,   274,   275,   276,   277,   278,   279,     0,
       0,     0,   295,   296,   297,   298,   299,   300,     0,     0,
     295,   296,   297,   298,   299,   300,     0,     0,    68,     0,
      68,     0,     0,     0,     0,     0,     0,    68,     0,    68,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    68,     0,     0,     0,
       0,     0,     0,     0,    68
  };

  const short
   Parser ::yycheck_[] =
  {
       0,    66,   635,    80,     9,     0,     9,     3,     8,     9,
      10,    11,   345,   108,    75,   764,   243,     9,    18,    19,
      11,    11,    32,     9,   115,     0,   117,     9,   119,     3,
     121,    11,    32,     8,    11,    10,     9,    32,   787,    42,
      14,    75,    11,    18,    14,     3,     4,     5,     6,     7,
       8,     9,    12,    11,    12,   756,   757,    32,    16,     3,
      56,    12,   811,    11,    10,    13,    24,    40,    12,    39,
      75,    29,    68,    69,    70,    71,    72,    68,    68,    75,
      80,    41,    56,    75,   833,    12,    86,    87,    68,    75,
      41,    68,    92,    75,    68,    69,    70,    71,    72,    68,
       9,    75,    11,     3,   104,     9,   106,   808,   108,   744,
      12,   746,    12,   108,    41,     4,     5,    75,   345,   346,
       9,   131,    68,    69,    70,    71,    72,    16,     9,    75,
      39,   131,     9,   108,    10,    39,   131,    10,   138,    41,
      29,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     9,   131,   157,   158,   159,
     160,   161,   162,   163,    40,   140,   141,    40,     3,    11,
      75,    13,   172,   173,   174,   175,   176,   177,    13,   812,
      21,    11,   259,    68,    25,   185,    75,    17,    75,   189,
      22,    32,    33,   193,   194,   195,   196,   197,   198,   199,
      32,    33,   837,   838,     8,     9,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,    75,
     220,   221,   222,   223,   224,   225,    68,   227,     9,    10,
      11,   326,     0,    75,   869,   235,     3,     0,     4,     5,
      38,    21,    40,     9,     3,     8,     9,    11,    11,     3,
      16,    22,    32,    33,    25,    18,    19,   892,    39,   259,
     895,    32,    33,    29,   264,   265,   266,   267,   268,    32,
      34,    35,    36,    37,   274,   275,   276,   277,   278,   279,
      17,    18,    19,    20,   284,    40,    41,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,    22,    23,     3,    80,   328,    32,
      33,   321,     3,     3,    32,    33,   326,     3,   328,    92,
     330,   326,    13,   328,     3,     4,     5,     6,     7,     8,
       9,   104,    11,   106,    68,   108,    21,    16,    68,     4,
      25,   326,    40,   328,     9,    24,    10,    32,    33,    10,
      29,    16,    40,    11,    10,    21,    22,    23,   131,    10,
      42,    11,    20,    10,    29,   138,    32,    33,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    32,    33,    34,    35,    36,    37,    32,    33,
     163,    59,    60,   166,    75,    13,    75,    42,   635,   172,
     173,   174,   175,   176,   177,    32,    33,    34,    35,    36,
      37,    10,   185,   756,   757,    25,   189,    68,    69,    70,
      71,    72,    32,    33,    75,    62,   199,     9,     4,     5,
       6,     7,     8,     9,    25,    11,    12,    17,    18,    19,
      16,    32,    33,    75,    10,   218,    11,    75,    24,    12,
      15,    16,    17,    29,   227,   228,   229,   230,   231,   232,
     233,   234,   235,    10,    41,   808,     0,    32,    33,    68,
      69,    70,    71,    72,     8,     9,    75,    11,    10,     9,
      11,    40,    75,    12,    18,    19,   259,    12,     4,     5,
       6,     7,     8,     9,    25,    11,    12,    12,    32,    75,
      16,    32,    33,    34,    35,    36,    37,    12,    24,    11,
      13,   284,    12,    29,   287,    17,    18,    19,    20,   756,
     757,   294,    14,    10,    41,    41,    40,     9,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,    22,    23,    12,    25,    11,    80,    20,   321,   786,
      20,    32,    33,   326,    11,   328,   643,   330,    92,    75,
      11,   636,    12,    12,    15,    16,    17,    18,    19,    20,
     104,   808,   106,    11,   108,   812,   813,    15,    16,    17,
      20,     4,     5,     6,     7,     8,     9,    25,    11,    12,
      10,    25,    10,    16,    32,    33,    41,   131,    32,    33,
       8,    24,    38,    12,   138,     3,    29,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    15,    16,    17,    18,    19,   636,    75,    14,   163,
     164,   165,    26,   643,    28,     3,    30,    31,   172,   173,
      40,     4,     5,     6,     7,     8,     9,    42,    11,    12,
     751,   185,    75,    16,    59,   189,    68,    69,    70,    71,
      72,    24,    10,    75,     3,   199,    29,     4,     5,     6,
       7,     8,     9,    14,    11,    12,    11,    10,    41,    16,
      15,    16,    17,    10,   218,    42,    42,    24,    21,    22,
      23,    42,    29,   227,    12,    12,    10,    11,    10,    32,
      33,   235,   236,   237,    41,   239,   240,    21,     9,    40,
      40,    25,    75,    15,    16,    17,    18,    19,    32,    33,
      34,    35,    36,    37,    26,   259,    12,   747,    30,    31,
      12,    12,    10,    12,   744,   745,   746,   747,    75,   749,
       9,    12,   747,    21,    22,    23,    39,    25,    12,    10,
     284,    10,   813,   287,    32,    33,   141,   776,     8,   744,
     294,   746,   747,     8,     8,   881,   776,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
      -1,    -1,   786,     9,    -1,    -1,    -1,   321,    17,    18,
      19,    20,   326,    19,   328,    -1,   330,    -1,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,
      16,    -1,   822,    21,    22,    23,    -1,    25,    24,    -1,
      -1,    -1,    10,    29,    32,    33,    -1,   837,   838,    -1,
      -1,    -1,   842,    21,   844,    41,    -1,    25,    -1,   849,
      17,    18,    19,    20,    32,    33,    34,    35,    36,    37,
      11,    -1,   837,   838,    80,    -1,    -1,   867,    -1,   869,
      21,    -1,    -1,   636,    25,    17,    18,    19,    20,    75,
     643,    32,    33,    34,    35,    36,    37,   887,   104,    -1,
     106,    -1,   892,    -1,   869,   895,     4,     5,     6,     7,
       8,     9,    25,     8,    34,    35,    36,    37,    16,    32,
      33,    34,    35,    36,    37,    -1,    24,   892,    -1,    -1,
     895,    29,   138,    -1,    -1,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    -1,    13,
      -1,    -1,    16,    -1,     4,     5,     6,     7,     8,     9,
      24,    11,    12,    -1,    -1,    29,    16,    75,    15,    16,
      17,    18,    19,    20,    24,    -1,    -1,    -1,    -1,    29,
      -1,   744,   745,   746,   747,    -1,   749,    34,    35,    36,
      37,    41,    56,    57,    58,    -1,    -1,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    -1,   776,    15,    16,    17,    18,    19,    20,
     125,    -1,    -1,    -1,    -1,    75,    -1,    -1,     4,     5,
       6,     7,     8,     9,   139,    11,    12,    -1,    -1,    -1,
      16,    -1,    -1,   259,    -1,    10,     0,    -1,    24,    -1,
      -1,   156,    -1,    29,    -1,     9,    21,    11,    -1,   822,
      25,    -1,    -1,    -1,    18,    19,    -1,    32,    33,    34,
      35,    36,    37,   178,   837,   838,    -1,    -1,    32,   842,
      -1,   844,    -1,    -1,    -1,    -1,   849,    -1,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,    75,
      16,    -1,    -1,    -1,   867,   321,   869,    -1,    24,    -1,
      -1,    -1,   636,    29,   330,    -1,    -1,    -1,    -1,   643,
      -1,   226,    -1,    -1,   887,    -1,    80,    -1,    -1,   892,
      -1,    -1,   895,    15,    16,    17,    18,    19,    92,    -1,
      -1,   246,    -1,    -1,    -1,    -1,   251,   252,    30,    31,
     104,    -1,   106,    -1,   108,    -1,    -1,    -1,    -1,    75,
      -1,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    16,    -1,    -1,    -1,   131,    -1,    -1,
      -1,    24,    -1,    -1,   138,    -1,    29,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    15,    16,    17,    18,    19,    20,    11,    -1,   163,
      -1,    15,    16,    17,    18,    19,    20,    -1,   172,   173,
     744,   745,   746,   747,    -1,   749,    30,    31,    -1,    -1,
      -1,   185,    75,   187,   188,   189,    -1,     4,     5,     6,
       7,     8,     9,   348,    11,   199,    13,    -1,    -1,    16,
      -1,    -1,   776,   358,    -1,    -1,     0,    24,    -1,    -1,
      -1,    -1,    29,    -1,   218,     9,    -1,    15,    16,    17,
      18,    19,    20,   227,    18,    19,    -1,    -1,    26,    27,
      28,   235,    30,    31,    -1,    -1,    -1,    -1,    32,    -1,
       4,     5,     6,     7,     8,     9,    -1,    11,   822,    -1,
      -1,    -1,    16,    -1,    -1,   259,    -1,    -1,    75,    -1,
      24,    -1,    -1,   837,   838,    29,    -1,    -1,   842,    -1,
     844,    -1,    -1,    -1,    -1,   849,    -1,    41,    -1,    -1,
     284,   285,   286,   287,    -1,    -1,    80,    -1,    -1,    -1,
     294,    -1,    -1,   867,    -1,   869,    -1,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     104,    75,   106,   887,   108,    -1,    -1,   321,   892,    -1,
      -1,   895,   326,    -1,   328,    10,   330,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    -1,   131,    -1,    -1,
      -1,    26,    27,    28,   138,    30,    31,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    -1,    -1,   157,   158,   159,    10,    -1,    -1,    -1,
     636,    15,    16,    17,    18,    19,    20,   643,   172,   173,
      15,    16,    17,    18,    19,   179,   180,   181,   182,   183,
     184,    -1,   186,    -1,    -1,    -1,   190,    -1,    -1,     0,
      15,    16,    17,    18,    19,    20,   200,    -1,     9,    15,
      16,    17,    18,    19,    20,    30,    31,    18,    19,    34,
      35,    36,    37,    -1,    -1,   219,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    -1,   228,     4,     5,     6,     7,     8,
       9,    -1,    11,    -1,   238,    -1,    -1,    16,    -1,     4,
       5,     6,     7,     8,     9,    24,    11,    12,    -1,    -1,
      29,    16,    -1,    -1,    -1,   259,    -1,    -1,    -1,    24,
      -1,    -1,    41,    -1,    29,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    -1,   749,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    11,    -1,    -1,    16,    15,    16,    17,
      18,    19,    20,   104,    24,   106,    75,   108,    26,    29,
     776,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      75,    -1,    -1,    -1,    -1,    -1,    -1,   321,    -1,    -1,
     131,    -1,   326,    -1,   328,    -1,   330,   138,    -1,    -1,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    21,    75,   822,    -1,    25,    -1,
      -1,    -1,   163,    -1,    -1,    32,    33,    34,    35,    36,
      37,   172,   173,    -1,    -1,    -1,   842,    -1,   844,    -1,
      -1,    -1,    -1,   849,   185,    -1,    -1,    -1,   189,    -1,
     191,   192,    -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,
      -1,   867,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,
       6,     7,     8,     9,   769,    -1,   771,   218,    -1,    -1,
      16,   887,    -1,   778,    -1,   780,   227,    -1,    24,    -1,
      -1,    -1,   636,    29,   235,    -1,    -1,   792,    -1,   643,
      -1,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,   259,    -1,
      -1,    24,    -1,   818,    -1,   820,    29,    -1,    -1,    -1,
      -1,    -1,   827,    -1,   829,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    11,    -1,
      29,   856,    15,    16,    17,    18,    19,    20,    -1,   864,
      -1,    -1,    75,    -1,    -1,    -1,    -1,    30,    31,    -1,
     321,    34,    35,    36,    37,   326,    -1,   328,     0,   330,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
     744,   745,   746,   747,    16,   749,    75,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    29,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,
      16,    -1,   776,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    29,    56,    57,    58,    -1,    -1,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    -1,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    -1,    -1,    -1,    16,   822,     4,
       5,     6,     7,     8,     9,    24,    11,    12,    -1,    75,
      29,    16,    -1,   837,   838,    -1,    -1,    -1,   842,    24,
     844,    -1,   636,    -1,    29,   849,    -1,    -1,    -1,   643,
       0,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,   867,    10,   869,    16,    -1,    -1,    15,
      16,    17,    18,    19,    24,    -1,    75,    -1,    -1,    29,
      26,    27,    28,   887,    30,    31,    -1,    -1,   892,    -1,
      75,   895,    -1,    -1,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    30,
      31,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    -1,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
      -1,    14,    -1,    16,    15,    16,    17,    18,    19,    20,
     744,    24,   746,   747,    -1,   749,    29,    -1,    -1,    30,
      31,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,   776,    56,    57,    58,    29,    -1,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    -1,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    -1,    -1,    -1,    16,    -1,    15,
      16,    17,    18,    19,    20,    24,    -1,    -1,   822,    25,
      29,    -1,    75,    -1,    -1,   636,    32,    33,    34,    35,
      36,    37,   643,   837,   838,    -1,    -1,    -1,   842,    -1,
     844,    -1,    -1,    -1,     1,   849,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    -1,    14,    -1,    16,
      -1,    -1,    -1,   867,    -1,   869,    75,    24,    -1,    -1,
      10,    -1,    29,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    -1,   887,    -1,    25,    -1,    -1,   892,    -1,
      -1,   895,    32,    33,    34,    35,    36,    37,    -1,    56,
      57,    58,    -1,    -1,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    -1,    -1,
      14,    -1,    16,   744,    -1,   746,   747,    -1,   749,    -1,
      24,    -1,    -1,    -1,     8,    29,    10,    11,    12,    -1,
       4,     5,     6,     7,     8,     9,    -1,    11,    -1,    -1,
      -1,    -1,    16,    -1,    -1,   776,    -1,    -1,    -1,    -1,
      24,    -1,    56,    57,    58,    29,    -1,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,     4,     5,     6,     7,     8,     9,    -1,    11,
      -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,
      -1,   822,    24,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    75,    86,    87,    -1,    -1,   837,   838,    92,    -1,
      -1,   842,    -1,   844,    98,    99,    -1,    -1,   849,    -1,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,   115,    16,   117,    -1,   119,   867,   121,   869,    -1,
      24,   125,    -1,    75,    -1,    29,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,   139,   887,    -1,    25,    -1,
      -1,   892,    -1,    -1,   895,    32,    33,    34,    35,    36,
      37,    -1,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,    -1,     8,    -1,
      -1,    -1,   246,    -1,    -1,    -1,    -1,   251,   252,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,    -1,    -1,    -1,    -1,
     284,    -1,    -1,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
      -1,    -1,   316,   317,   318,   319,   320,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    11,
      -1,    -1,    -1,    -1,   348,   115,    -1,   117,    -1,   119,
      -1,   121,    -1,    -1,   358,   125,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,   139,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,    -1,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,
      -1,   251,   252,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    10,    -1,    -1,    -1,    29,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      25,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    56,    57,    58,    -1,
      -1,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    -1,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    26,    27,    28,   348,    30,
      31,    32,    33,    34,    35,    36,    37,    10,   358,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    37,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    25,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    -1,    25,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    -1,
      22,    -1,    -1,    25,    26,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    11,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      25,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    -1,
      -1,   745,    -1,    -1,    26,    27,    28,   751,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   769,    -1,   771,    -1,    -1,
      -1,    -1,    -1,    -1,   778,    -1,   780,    11,    -1,    -1,
     784,    15,    16,    17,    18,    19,    20,    -1,   792,    -1,
      -1,    -1,    26,    -1,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    11,   818,    -1,   820,    15,    16,    17,
      18,    19,    20,   827,    -1,   829,    15,    16,    17,    18,
      19,    20,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,   856,    15,    16,    17,    18,    19,    20,    21,
     864,    -1,    -1,    25,    26,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,
      -1,   751,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   769,
      -1,   771,    -1,    -1,    -1,    -1,    -1,    -1,   778,    -1,
     780,    -1,    -1,    -1,   784,    15,    16,    17,    18,    19,
      20,    21,   792,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    37,    -1,    -1,
      32,    33,    34,    35,    36,    37,    -1,    -1,   818,    -1,
     820,    -1,    -1,    -1,    -1,    -1,    -1,   827,    -1,   829,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   856,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   864
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,     0,     3,     4,     5,     6,     7,     8,     9,    11,
      16,    24,    29,    56,    57,    58,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    78,    79,    80,    81,    84,    86,    87,    88,    89,
      90,    91,    94,    97,   100,   101,   102,   103,   105,   106,
     107,   108,   109,   111,   112,   114,   115,   116,   119,   120,
     121,   122,   123,   125,   127,     8,    75,   105,   107,   109,
     111,   112,   113,   114,   115,   116,   119,   120,   121,   122,
       3,    12,    75,   105,   106,   110,     9,    16,    75,   105,
     119,   120,     9,   115,   119,   120,   121,   122,     9,    16,
     119,    75,    75,    85,     9,     9,     9,     3,    13,    81,
      82,    83,   106,    75,    68,    11,    68,    11,    68,    11,
      68,    11,    68,    75,    75,    11,    13,    68,   117,     0,
       0,     1,    80,     3,     3,     3,     3,     3,     9,    11,
      39,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,     3,    11,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    25,    26,    27,    28,
      30,    31,    32,    33,    34,    35,    36,    37,    11,    15,
      16,    17,    25,    32,    33,    21,    25,    32,    33,    21,
      25,    32,    33,    15,    16,    17,    18,    19,    20,    21,
      25,    26,    27,    28,    30,    31,    32,    33,    34,    35,
      36,    37,    15,    16,    17,    18,    19,    20,    21,    25,
      32,    33,    34,    35,    36,    37,    11,    21,    25,    32,
      33,    34,    35,    36,    37,    21,    22,    23,    25,    32,
      33,    68,    68,     9,    75,    10,    11,   117,    10,    10,
      10,    38,    40,    10,    10,    10,    10,    10,   110,    40,
       3,    12,   119,   120,    15,    16,    17,    18,    19,    26,
      27,    28,    30,    31,    15,    16,    17,    18,    19,    20,
     119,   120,   121,   122,    21,    32,    33,    21,    32,    33,
      34,    35,    36,    37,    21,    32,    33,    34,    35,    36,
      37,    21,    25,    32,    33,    34,    35,    36,    37,    21,
      22,    23,    32,    33,   119,   119,    15,    16,    17,    18,
      19,    42,    40,   106,    75,   106,    13,    14,    79,    62,
      42,    12,   113,   119,   120,   121,   122,   126,    12,   126,
      12,   126,    12,   126,     3,    13,     9,    12,    41,   113,
     126,    14,    39,   118,    80,    10,   104,   106,    41,   113,
     105,   102,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   113,   107,   111,   119,
     120,   107,   111,   119,   120,   107,   111,   119,   120,   107,
     119,   120,   107,   119,   120,   107,   119,   120,   107,   115,
     116,   119,   120,   121,   122,   107,   122,   107,   122,   107,
     121,   107,   119,   107,   119,   107,   119,   107,   119,   107,
     119,   107,   111,   115,   116,   119,   120,   121,   122,   107,
     111,   115,   116,   119,   120,   121,   122,   107,   119,   120,
     121,   107,   119,   120,   121,   107,   119,   120,   121,   107,
     119,   120,   121,   113,   107,   111,   107,   111,   107,   111,
     107,   111,   107,   111,   107,   111,   107,   115,   116,   119,
     120,   121,   122,   107,   111,   107,   115,   107,   115,   107,
     115,   116,   119,   120,   121,   122,   107,   111,   107,   116,
     107,   116,   107,   119,   120,   107,   119,   120,   107,   119,
     120,   107,   119,   120,   107,   119,   120,   119,   120,   107,
     115,   116,   119,   120,   121,   122,   107,   111,   107,   119,
     107,   119,   107,   119,   107,   119,   107,   119,   107,   119,
     120,   107,   119,   120,   107,   119,   120,   107,   119,   120,
     107,   119,   120,   107,   119,   120,   107,   119,   120,   107,
     119,   120,   107,   119,   120,   107,   119,   120,   107,   119,
     120,   107,   119,   120,   107,   115,   116,   119,   120,   121,
     122,   107,   111,   107,   119,   120,   107,   119,   120,   107,
     119,   120,   107,   119,   120,   107,   119,   120,   107,   119,
     120,   113,   107,   115,   116,   119,   120,   121,   122,   107,
     111,   121,   107,   121,   107,   121,   107,   121,   107,   121,
     107,   121,   107,   121,   107,   115,   116,   119,   120,   121,
     122,   107,   122,   107,   122,   107,   111,   107,   122,   107,
     122,    10,    75,   124,   127,     9,    42,   113,    10,   113,
     113,     3,    12,     3,   110,    12,   119,   120,   119,   120,
     119,   120,   119,   120,   119,   120,   119,   119,   119,   119,
     119,   119,   120,   119,   120,   119,   120,   119,   120,   119,
     120,   119,   120,   115,   119,   120,   121,   122,     9,   115,
     115,   115,   119,   120,   121,   122,   119,   120,   119,   120,
     119,   120,   119,   120,   119,   120,   119,   120,   115,   119,
     120,   121,   122,   119,   120,   119,   120,   119,   120,   119,
     120,   119,   120,   119,   120,   115,   119,   120,   121,   122,
     121,   122,   121,   121,   121,   121,   121,   121,   115,   119,
     120,   121,   122,   122,   122,   122,   122,   119,   119,   119,
     119,   119,   106,    75,    10,    41,    10,    79,    14,     9,
     106,    40,    12,    12,    12,    12,    13,     3,    14,    56,
      95,    96,   100,   127,    10,    98,    99,   127,    12,    41,
     113,    41,    12,    75,    14,    10,    40,    12,    41,   113,
      41,    12,    12,    12,    11,    10,    40,    10,    98,   106,
     117,    10,    38,    12,   110,     8,    83,    75,   121,    83,
      14,     3,   106,   126,    95,    95,    75,    14,     3,    75,
      82,    10,    40,    40,    75,    12,   113,    12,    41,    12,
      41,   113,    42,   104,    12,   113,    12,    41,    12,    41,
     113,   124,    82,    10,   113,    59,    92,    10,    10,     3,
      10,    14,    42,    95,    42,    82,    98,    99,   127,    42,
      12,    12,   113,    12,   113,    12,    41,   106,    12,    12,
     113,    12,   113,    12,    41,    82,    10,     9,    59,    60,
      93,    83,    83,   106,   106,    75,   106,    12,    12,    12,
     113,    40,    12,    12,    12,   113,   106,     9,    83,    12,
     118,    12,    10,   106,    83,    10,    83
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
     105,   105,   106,   106,   106,   106,   106,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   108,   108,   108,   108,   109,   109,   109,
     109,   109,   110,   110,   110,   111,   111,   111,   111,   111,
     111,   112,   112,   113,   113,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   115,
     115,   116,   116,   117,   117,   118,   118,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   123,
     123,   124,   124,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   126,   126,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     1,     2,     1,     2,     3,     1,     1,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     3,     4,     4,     5,     1,     1,     2,     1,
       3,     1,     1,     1,     1,     2,     7,     7,     5,     6,
       7,     5,     6,     0,     2,     0,     4,     5,     6,     1,
       2,     2,     3,     1,     4,     4,     5,     6,     5,     6,
       2,     1,     3,     4,     3,     2,     4,     4,     4,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     1,     3,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     2,     3,
       4,     4,     4,     3,     3,     3,     3,     3,     3,     3,
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
       3,     3,     3,     1,     1,     1,     1,     2,     3,     4,
       4,     5,     1,     3,     4,     1,     1,     1,     3,     3,
       3,     5,     7,     1,     1,     4,     5,     5,     6,     5,
       6,     6,     6,     7,     7,     7,     8,     4,     5,     5,
       6,     5,     6,     6,     6,     7,     7,     7,     8,     1,
       3,     2,     4,     2,     3,     4,     6,     1,     2,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       3,     1,     3,     4,     3,     4,     3,     4,     3,     4,
       3,     4,     3,     1,     3,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1
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
  "set", "funcall", "callarglist", "scope", "expr", "expr_var", "val",
  "matrix", "matvals", "expr_mat", "range", "int_val", "slice",
  "expr_none", "expr_struct", "struct_val", "struct_list", "expr_int",
  "expr_float", "expr_str", "expr_bool", "funtype", "typelist", "mattype",
  "matsize", "type", YY_NULLPTR
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
     307,   308,   309,   310,   311,   315,   316,   318,   319,   323,
     324,   325,   329,   330,   331,   332,   333,   336,   337,   338,
     340,   341,   342,   344,   345,   346,   348,   349,   350,   351,
     352,   353,   354,   355,   357,   358,   359,   360,   361,   363,
     364,   365,   366,   367,   369,   370,   371,   372,   373,   374,
     375,   376,   378,   379,   380,   381,   382,   383,   384,   385,
     387,   388,   389,   391,   392,   393,   395,   396,   397,   398,
     399,   400,   401,   403,   404,   405,   406,   407,   408,   409,
     411,   412,   413,   414,   415,   416,   417,   419,   420,   421,
     422,   423,   424,   425,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   463,   464,
     465,   467,   468,   469,   471,   472,   473,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   492,   493,   494,   496,   497,   498,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   527,   528,   529,   530,   534,   535,   536,
     537,   538,   540,   541,   542,   546,   547,   548,   549,   550,
     551,   553,   554,   556,   557,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   586,
     587,   591,   592,   594,   595,   597,   598,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     628,   629,   630,   631,   632,   633,   634,   635,   636,   637,
     638,   639,   643,   644,   645,   646,   647,   648,   649,   650,
     651,   652,   653,   654,   655,   656,   657,   658,   659,   660,
     661,   662,   663,   664,   665,   666,   667,   668,   669,   673,
     674,   675,   676,   677,   679,   680,   681,   682,   683,   684,
     685,   687,   688,   689,   690,   691,   692,   693,   695,   696,
     697,   698,   699,   701,   702,   703,   704,   705,   707,   708,
     709,   710,   711,   713,   714,   715,   716,   717,   719,   723,
     724,   726,   727,   731,   732,   733,   734,   735,   736,   737,
     738,   739,   740,   742,   743,   747,   748,   749,   750,   751,
     752,   753,   754,   755,   756,   757,   758,   759,   760,   761
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
#line 2998 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"

#line 764 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    std::cerr << scanner->loc->begin.line << ":" << scanner->loc->begin.column << ": " << err_message << std::endl;
}
