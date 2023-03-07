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
  case 213: // expr_int: "int"
#line 479 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 787 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 214: // expr_int: "-" expr_int
#line 480 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 793 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 215: // expr_int: "(" expr_int ")"
#line 481 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 799 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 216: // expr_int: "~" expr_int
#line 482 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 805 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 217: // expr_int: expr_int "*" expr_int
#line 483 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 811 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 218: // expr_int: expr_int "/" expr_int
#line 484 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 817 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 219: // expr_int: expr_int "%" expr_int
#line 485 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 823 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 220: // expr_int: expr_int "-" expr_int
#line 486 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 829 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 221: // expr_int: expr_int "+" expr_int
#line 487 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 835 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 222: // expr_int: expr_int "<<" expr_int
#line 488 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 841 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 223: // expr_int: expr_int ">>" expr_int
#line 489 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 847 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 224: // expr_int: expr_int "&" expr_int
#line 490 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 853 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 225: // expr_int: expr_int "^" expr_int
#line 491 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 859 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 226: // expr_int: expr_int "|" expr_int
#line 492 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 865 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 227: // expr_float: "float"
#line 496 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 871 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 228: // expr_float: "-" expr_float
#line 497 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 877 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 229: // expr_float: "(" expr_float ")"
#line 498 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 883 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 230: // expr_float: expr_float "**" expr_float
#line 499 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 889 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 231: // expr_float: expr_float "**" expr_int
#line 500 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 895 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 232: // expr_float: expr_int "**" expr_float
#line 501 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 901 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 233: // expr_float: expr_float "*" expr_float
#line 502 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 907 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 234: // expr_float: expr_float "*" expr_int
#line 503 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 913 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 235: // expr_float: expr_int "*" expr_float
#line 504 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 919 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 236: // expr_float: expr_float "/" expr_float
#line 505 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 925 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 237: // expr_float: expr_float "/" expr_int
#line 506 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 931 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 238: // expr_float: expr_int "/" expr_float
#line 507 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 937 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 239: // expr_float: expr_float "%" expr_float
#line 508 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 943 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 240: // expr_float: expr_float "%" expr_int
#line 509 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 949 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 241: // expr_float: expr_int "%" expr_float
#line 510 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 955 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 242: // expr_float: expr_float "-" expr_float
#line 511 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 961 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 243: // expr_float: expr_float "-" expr_int
#line 512 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 967 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 244: // expr_float: expr_int "-" expr_float
#line 513 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 973 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 245: // expr_float: expr_float "+" expr_float
#line 514 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 979 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 246: // expr_float: expr_float "+" expr_int
#line 515 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 985 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 247: // expr_float: expr_int "+" expr_float
#line 516 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 991 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 248: // expr_str: "string"
#line 520 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 997 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 249: // expr_str: "(" expr_str ")"
#line 521 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 1003 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 250: // expr_str: expr_str "++" expr_str
#line 522 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 1009 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 251: // expr_str: expr_str "++" expr_int
#line 523 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 1015 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 252: // expr_str: expr_str "++" expr_float
#line 524 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 1021 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 253: // expr_str: expr_str "++" expr_bool
#line 525 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1027 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 254: // expr_str: expr_int "++" expr_str
#line 526 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 1033 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 255: // expr_str: expr_int "++" expr_int
#line 527 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 1039 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 256: // expr_str: expr_int "++" expr_float
#line 528 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 1045 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 257: // expr_str: expr_int "++" expr_bool
#line 529 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1051 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 258: // expr_str: expr_float "++" expr_str
#line 530 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 1057 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 259: // expr_str: expr_float "++" expr_int
#line 531 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 1063 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 260: // expr_str: expr_float "++" expr_float
#line 532 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 1069 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 261: // expr_str: expr_float "++" expr_bool
#line 533 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1075 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 262: // expr_str: expr_bool "++" expr_str
#line 534 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 1081 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 263: // expr_str: expr_bool "++" expr_int
#line 535 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 1087 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 264: // expr_str: expr_bool "++" expr_float
#line 536 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 1093 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 265: // expr_str: expr_bool "++" expr_bool
#line 537 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1099 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 266: // expr_bool: "bool"
#line 541 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 1105 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 267: // expr_bool: "(" expr_bool ")"
#line 542 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 1111 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 268: // expr_bool: "not" expr_bool
#line 543 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 1117 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 269: // expr_bool: expr_bool "or" expr_bool
#line 544 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 1123 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 270: // expr_bool: expr_bool "and" expr_bool
#line 545 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 1129 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 271: // expr_bool: expr_bool "==" expr_bool
#line 546 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 1135 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 272: // expr_bool: expr_int "==" expr_int
#line 547 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 1141 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 273: // expr_bool: expr_float "==" expr_float
#line 548 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 1147 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 274: // expr_bool: expr_str "==" expr_str
#line 549 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 1153 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 275: // expr_bool: expr_bool "!=" expr_bool
#line 550 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 1159 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 276: // expr_bool: expr_int "!=" expr_int
#line 551 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 1165 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 277: // expr_bool: expr_float "!=" expr_float
#line 552 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 1171 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 278: // expr_bool: expr_str "!=" expr_str
#line 553 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 1177 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 279: // expr_bool: expr_int ">" expr_int
#line 554 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 1183 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 280: // expr_bool: expr_float ">" expr_float
#line 555 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 1189 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 281: // expr_bool: expr_str ">" expr_str
#line 556 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 1195 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 282: // expr_bool: expr_int "<" expr_int
#line 557 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 1201 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 283: // expr_bool: expr_float "<" expr_float
#line 558 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 1207 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 284: // expr_bool: expr_str "<" expr_str
#line 559 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 1213 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 285: // expr_bool: expr_int ">=" expr_int
#line 560 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 1219 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 286: // expr_bool: expr_float ">=" expr_float
#line 561 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 1225 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 287: // expr_bool: expr_str ">=" expr_str
#line 562 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 1231 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 288: // expr_bool: expr_int "<=" expr_int
#line 563 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 1237 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 289: // expr_bool: expr_float "<=" expr_float
#line 564 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 1243 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 290: // expr_bool: expr_str "<=" expr_str
#line 565 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
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


  const short  Parser ::yypact_ninf_ = -563;

  const short  Parser ::yytable_ninf_ = -320;

  const short
   Parser ::yypact_[] =
  {
    1284,  -563,  -563,  -563,  -563,  -563,  -563,  -563,   247,    66,
     264,   815,   298,   -47,   -35,    35,    36,    41,  1484,   755,
    -563,  -563,   -10,    42,     6,    25,    28,    29,    30,    55,
      26,   103,   656,  -563,  -563,   126,   132,  -563,  -563,  -563,
    -563,  -563,  -563,  -563,   156,   164,   168,  -563,    20,   184,
    1652,  -563,  -563,  1698,  1546,  1994,   170,    68,   106,    -4,
     815,   201,   183,    37,   847,  1036,   534,   104,   755,  -563,
      40,   167,    93,   201,    40,  -563,  -563,  1744,  1606,  2018,
    -563,   298,   298,  -563,   155,  -563,   171,   755,   176,   755,
     257,  1544,  -563,  -563,   206,  -563,   178,  -563,   459,  -563,
     485,  -563,   521,  -563,   568,  -563,    96,   263,   596,  -563,
     239,  -563,  -563,  1604,  -563,  -563,  -563,  -563,  -563,  -563,
     716,   223,   755,  -563,   386,   386,   386,   386,   386,   386,
     386,   386,   386,   386,   386,   386,   386,   386,   386,   386,
     386,   386,   386,   386,   386,   386,   386,   386,   386,   386,
     201,   386,   386,   386,   386,   386,   386,   386,   386,   386,
     386,   386,   386,   386,   386,   386,   386,   386,   386,   386,
     386,   386,   386,   386,   386,   386,   386,   386,   386,   386,
     386,   386,   386,   386,   386,   386,   386,   386,   386,   386,
     386,   386,  -563,  -563,   387,    12,   755,  -563,  -563,   201,
     201,   201,   201,   201,   815,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,  -563,   201,   201,   201,
     201,   201,   201,   815,   201,   201,   201,   201,   201,   201,
    -563,   815,   815,   815,   815,   815,   815,   815,  -563,   815,
     815,   815,   815,   815,   146,   342,   274,  -563,  1954,  1072,
    1973,  -563,   298,   298,   298,   298,   298,   755,   225,   279,
     255,   281,  1604,  -563,  1347,   292,   755,  -563,   268,   293,
    -563,   301,  -563,   316,  -563,   319,   291,   107,   449,  -563,
      13,   320,   223,  -563,  -563,   332,   271,   334,  -563,   207,
     229,   299,  1994,   170,   207,   229,   299,   324,   335,   336,
     324,   335,   336,   324,   335,   336,   324,  1698,   336,  1675,
    1767,   870,   581,   714,  1790,  1546,   250,  1721,   196,  1813,
    1836,  1882,  1440,   120,  1044,  1149,  1286,  1349,  1411,  1486,
    1463,  1978,  1463,  1978,  1890,  1913,  1942,   303,  -563,  1890,
    1913,  1942,   303,  -563,  1019,  2017,  2025,  -563,  1019,  2017,
    2025,  -563,  1019,  2017,  2025,  -563,  1019,  2017,  2025,  -563,
     207,   229,   299,   207,   229,   299,   324,   335,   336,   324,
     335,   336,   324,   335,   336,  1990,   337,  1675,  1767,   870,
     581,   714,  1813,  1044,  1149,  1286,  1349,  1411,  1486,  1463,
    1978,  1463,  1978,  1890,  1913,  1890,  1913,  1019,  2017,  1019,
    2017,  1019,  2017,  1019,  2017,   207,   229,   299,   207,   229,
     299,   324,   335,   336,   324,   335,   336,   324,   335,   336,
     324,   335,   336,  1675,  1767,   870,   581,   714,  1813,  1890,
    1942,  1890,  1942,  1019,  2025,  1019,  2025,  1019,  2025,  1019,
    2025,  1675,  1767,   870,   581,   714,  1813,  1890,   303,  1890,
     303,  1019,  -563,  1019,  -563,  1019,  -563,  1019,  -563,  1675,
    1767,   870,   581,   714,  1790,   250,  1721,   196,  1813,  1890,
    -563,  1890,  -563,  -563,    31,   349,    -2,   585,   755,   350,
     711,   750,   711,   750,   335,   337,   335,   337,   335,   337,
    1859,  1919,  2024,   302,   158,   660,   776,  1819,  1819,   158,
     158,   158,   158,   158,   158,   711,   750,   711,   750,   335,
     337,   335,   337,   335,   337,   335,   337,  1859,  1919,  2024,
     302,  2047,  2047,  2047,  2047,  2047,  2047,  1859,  1919,  2024,
     302,   517,   384,   517,  -563,  -563,  -563,  -563,  1859,  1919,
    2024,   302,   123,    79,  -563,  -563,   352,  -563,   755,  -563,
    -563,   242,   242,  -563,  -563,  -563,  -563,  -563,  1484,   781,
    1484,  1409,   358,   755,  -563,   755,  -563,  -563,  -563,  -563,
     157,   157,  -563,   308,   360,   369,  -563,     1,   144,    24,
     339,     4,   183,  -563,   334,  -563,   755,   596,  -563,   461,
     144,    75,  -563,  -563,  -563,   329,   372,   661,  -563,   380,
    -563,   374,  -563,   375,  -563,   346,  -563,   157,   354,  -563,
     144,   461,   461,   356,  -563,  -563,  -563,  -563,   144,   392,
     -16,  1484,  1484,  -563,  -563,  -563,   755,  -563,   755,  -563,
     363,   339,     5,   755,  -563,   755,   399,  1484,  -563,  -563,
    -563,  -563,  -563,   356,  -563,   401,   755,  -563,  1484,   402,
    -563,  1484,  -563
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     7,   213,   227,   248,   266,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      31,    32,     0,     0,   315,   316,   317,   318,     0,     0,
      76,     0,     0,     4,     8,     0,     0,    33,    14,    16,
      17,    15,    18,    19,     0,     0,     0,    77,    85,     0,
      82,    83,    81,   201,   202,   203,   204,   320,   321,     0,
       0,     0,    76,     0,     0,     0,     0,     0,     0,   205,
      85,   210,     0,     0,    86,   214,   228,     0,     0,     0,
     268,     0,     0,   216,     0,    29,    28,     0,     0,     0,
       0,     0,    26,    27,     0,    35,     0,   307,     0,   308,
       0,   309,     0,   310,     0,   311,     0,     0,     0,   312,
      78,     1,     3,     0,     5,    13,    20,    11,    12,     9,
       0,     0,     0,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   313,   314,     0,    65,     0,    87,   215,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   229,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     249,     0,     0,     0,     0,     0,     0,     0,   267,     0,
       0,     0,     0,     0,     0,     0,     0,   206,     0,     0,
       0,   214,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,   298,   305,     0,
     300,     0,   302,     0,   304,     0,     0,     0,     0,   296,
       0,     0,     0,     6,    70,     0,    72,    80,    69,   110,
     108,   109,     0,     0,   115,   113,   114,    95,    93,    94,
     100,    98,    99,   105,   103,   104,    90,     0,    89,   200,
     196,   197,   198,   199,   188,     0,   187,   191,   190,   185,
     181,   182,   183,   184,   170,   169,   176,   175,   173,   172,
     118,   117,   121,   120,   158,   154,   155,   156,   157,   167,
     163,   164,   165,   166,   128,   125,   126,   127,   142,   139,
     140,   141,   135,   132,   133,   134,   149,   146,   147,   148,
     106,   221,   247,   111,   220,   244,    91,   217,   235,    96,
     218,   238,   101,   219,   241,     0,   232,   192,   255,   256,
     254,   257,   177,   168,   224,   174,   226,   171,   225,   116,
     222,   119,   223,   150,   272,   159,   276,   122,   279,   136,
     282,   129,   285,   143,   288,   107,   246,   245,   112,   243,
     242,    92,   234,   233,    97,   237,   236,   102,   240,   239,
      88,   231,   230,   193,   259,   260,   258,   261,   178,   151,
     273,   160,   277,   123,   280,   137,   283,   130,   286,   144,
     289,   194,   251,   252,   250,   253,   179,   152,   274,   161,
     278,   124,   281,   138,   284,   131,   287,   145,   290,   195,
     263,   264,   262,   265,   186,   270,   189,   269,   180,   153,
     271,   162,   275,   292,   319,     0,   293,     0,     0,     0,
     221,   247,   220,   244,   217,   235,   218,   238,   219,   241,
     255,   256,   254,   257,   224,   226,   225,   222,   223,   272,
     276,   279,   282,   285,   288,   246,   245,   243,   242,   234,
     233,   237,   236,   240,   239,   231,   230,   259,   260,   258,
     261,   273,   277,   280,   283,   286,   289,   251,   252,   250,
     253,   274,     0,   278,   281,   284,   287,   290,   263,   264,
     262,   265,   270,   269,   271,   275,     0,   207,     0,   211,
     208,   221,   220,   217,   218,   219,    68,    30,     0,     0,
       0,     0,    22,     0,    67,     0,   297,   299,   301,   303,
       0,    49,    46,     0,     0,     0,    53,     0,     0,     0,
      61,     0,    74,   295,    79,    71,     0,     0,   291,     0,
       0,     0,    66,   209,   212,    43,     0,     0,    38,    23,
      24,     0,   306,     0,    50,     0,    47,    51,    65,    58,
       0,     0,     0,    60,    75,    73,   294,    56,     0,     0,
      45,     0,     0,    25,    39,    48,     0,    52,     0,    59,
      62,    64,     0,     0,    57,     0,     0,     0,    40,    36,
      37,    55,    54,     0,    63,     0,     0,    44,     0,     0,
      41,     0,    42
  };

  const short
   Parser ::yypgoto_[] =
  {
    -563,  -563,   -90,   -20,     3,  -562,  -503,  -563,  -563,  -563,
    -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -439,  -563,
    -563,  -473,  -203,  -271,  -563,  -563,  -563,  -172,  -163,    33,
     265,  1092,  -563,  -563,   -66,   788,   972,     0,   190,  -563,
    -169,  -563,   -78,  -171
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    31,    32,    33,    92,    93,    94,    35,    86,    36,
      37,    38,    39,    40,    41,   620,   638,    42,   574,   575,
      43,   579,   580,    44,    45,    46,    47,   285,   110,    70,
      49,    50,    51,    52,    72,    53,    54,   292,   293,    57,
     475,    58,   281,    59
  };

  const short
   Parser ::yytable_[] =
  {
      55,   264,   244,    34,   591,   194,   576,   194,    66,    55,
     194,    79,   114,   194,   194,    84,   609,    98,    55,    55,
     269,   477,   271,   476,   273,   582,   275,    85,   617,   120,
     636,   637,    55,    48,   610,    34,   100,   108,   589,   102,
     104,    63,   587,    74,    87,    88,   120,   197,   629,   120,
      89,    48,    96,   565,   478,   595,   634,   598,   195,   121,
      66,    99,   122,   608,   611,    48,   613,   643,    55,    68,
       3,     4,     5,     6,     7,     8,   121,     9,    69,   121,
     101,   109,    10,   103,   105,   618,   109,    55,  -319,    55,
      11,    55,   106,   283,    34,    12,   246,    97,    55,   276,
      55,   240,    55,   111,    55,   247,   577,   581,    55,   277,
     571,   242,   243,    55,   238,   611,    34,   107,   639,   640,
      55,   572,    55,   192,    48,   239,   240,   241,    62,   115,
     312,   603,   604,   322,   647,   116,   242,   243,   630,   337,
     342,   347,   351,   355,   359,   650,    48,    90,   652,   546,
     573,   380,   190,   191,   287,   242,   243,    91,   547,   117,
     571,   193,    23,    24,    25,    26,    27,   118,   627,   474,
     426,   119,   561,   252,   253,   254,   255,   256,   444,   549,
     448,   450,   452,   454,   456,   458,   462,   123,   208,   209,
      56,   186,   187,   188,   196,   189,    55,   257,    67,    56,
     573,    80,   190,   191,   492,     3,     4,   245,    56,    56,
      73,   258,    23,    24,    25,    26,    27,    61,   187,   474,
     266,   189,    56,   519,   126,   127,   128,   129,   190,   191,
      12,   529,   531,   533,   534,   535,   536,   537,   260,   540,
      79,    79,    79,    79,   114,    55,   147,   148,   149,   150,
      67,     3,     4,     5,     6,   265,    60,    55,    56,   254,
     255,   256,    55,    61,    55,    34,    55,    34,     3,     4,
     262,    11,   278,    73,    71,   189,    12,    56,   282,    56,
      61,    56,   190,   191,    95,    62,   550,   557,    56,   558,
      56,   560,    56,    12,    56,    48,   559,    48,    56,   576,
     576,   563,     3,    56,   570,   566,   581,    81,   565,    62,
      56,   586,    56,   567,    82,   584,   166,   167,   168,   169,
     313,   316,   318,   323,   240,   241,    62,    12,   568,   338,
     343,   569,   583,    71,   242,   243,   576,   182,   183,   184,
     185,   381,   585,   120,   129,   548,     3,     4,     5,     6,
       7,     8,   259,     9,   261,   150,   169,   222,    10,   588,
     427,   600,   582,   268,   593,   268,    11,   268,   445,   268,
     605,    12,   607,   280,   606,   619,   463,   465,   467,   612,
     470,   472,   621,   623,   624,   286,    56,   288,   626,   625,
       3,     4,     5,     6,   493,     8,   628,   473,   633,   577,
     577,   635,    10,   611,    62,   239,   240,   241,   646,   631,
      11,   648,   651,   520,   615,    12,   242,   243,   476,   614,
     616,   530,   532,   532,   532,   532,   532,   532,     0,   541,
     542,   543,   544,   545,     0,    56,   577,     0,     0,     0,
     581,   632,    23,    24,    25,    26,    27,    56,    62,   474,
       0,     0,    56,     0,    56,     0,    56,     0,     0,   578,
       0,   479,     0,     3,     4,     5,     6,     7,     8,     0,
       9,   267,     0,     0,     0,    10,     0,     0,    55,     0,
       0,     0,   594,    11,     0,     0,     0,   602,    12,     3,
       4,     5,     6,     7,     8,     0,     9,   270,     0,     0,
       0,    10,     0,     0,    23,    24,    25,    26,    27,    11,
      71,   474,     0,     0,    12,     0,    23,    24,    25,    26,
      27,    62,   556,   474,     0,     3,     4,     5,     6,     7,
       8,   564,     9,   272,     0,     0,     0,    10,     0,     0,
       0,   114,     0,     0,   230,    11,     0,    62,    55,     0,
      12,   234,   235,   236,   237,   231,     0,     0,    55,   597,
      55,    55,     0,    55,    34,    55,   232,   233,   234,   235,
     236,   237,     3,     4,     5,     6,     7,     8,     0,     9,
     274,     0,     0,    62,    10,     0,    55,    55,     0,     0,
       0,    48,    11,    48,    48,   590,     0,    12,     0,     0,
       3,     4,     5,     6,     7,     8,   179,     9,   279,     0,
       0,     0,    10,   180,   181,   182,   183,   184,   185,     0,
      11,    55,    55,     0,     0,    12,    55,     0,    55,     0,
      62,     0,     0,    55,     0,    55,     0,    55,     0,     0,
      23,    24,    25,    26,    27,     0,    55,   474,    55,     0,
       0,    55,     0,     0,    48,    48,   112,   113,    62,     2,
       3,     4,     5,     6,     7,     8,     0,     9,    56,     0,
      48,   622,    10,     0,     0,   252,   253,   254,   255,   256,
      11,    48,   231,     0,    48,    12,   205,     0,   207,     0,
     208,   209,     0,   232,   233,   234,   235,   236,   237,    13,
      14,    15,     0,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,     0,
       3,     4,     5,     6,     7,     8,   284,     9,   201,   202,
     203,   150,    10,     0,     0,     0,   187,   188,    56,   189,
      11,     0,     0,   592,     0,    12,   190,   191,    56,   532,
      56,    56,     0,    56,     0,    56,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     0,     9,   219,   220,   221,
     222,    10,     0,     0,     0,     0,    56,    56,    62,    11,
       0,     0,     0,     0,    12,     3,     4,     5,     6,     0,
      60,   252,   253,   254,   255,   256,    64,    61,    75,    77,
      83,     0,   205,     0,     0,    11,   208,   209,     0,     0,
      12,    56,    56,    71,     0,     0,    56,    62,    56,     3,
       4,     5,     6,    56,    60,    56,     0,    56,   601,     0,
     268,    61,     0,     0,     0,     0,    56,     0,    56,    11,
       0,    56,     0,   596,    12,     0,     0,     0,    64,    75,
       0,   286,   268,     0,     0,     0,     0,   198,     0,     0,
       0,   248,   199,   200,   201,   202,   203,   150,   204,   250,
     251,     0,     0,   205,   206,   207,     0,   208,   209,   210,
     211,   212,   213,   214,   215,   164,   165,   166,   167,   168,
     169,   641,     0,   642,     0,   171,     0,     0,   644,     0,
     645,     0,   172,   173,   174,   175,   176,   177,     0,     0,
       0,   649,   290,   295,   298,   301,   304,   307,   310,   307,
     307,   320,   325,   327,   329,   331,   333,   335,   340,   345,
     349,   353,   357,   361,   364,   367,   370,   373,   375,   378,
     307,   384,   386,   388,   390,   392,   394,   396,   398,   400,
     402,   404,   406,   409,   412,   415,   418,   421,   424,   307,
     307,   307,   307,   307,   307,   307,   442,   307,   307,   307,
     307,   307,   307,   307,   460,   307,   307,   307,   307,   307,
      65,     0,    76,    78,     0,     0,     0,   480,   482,   484,
     486,   488,   490,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,     0,   505,   507,   509,   511,   513,
     515,   517,   375,   375,   375,   375,   375,   375,     0,   527,
      77,    77,    77,    77,    77,    77,     0,   538,    77,    77,
      77,    77,    65,    76,   124,   125,   126,   127,   128,   129,
     551,   552,   553,   554,   555,   249,   216,     0,     0,   137,
     138,   217,   218,   219,   220,   221,   222,   223,     0,   124,
     125,   126,   127,   128,   129,     0,     0,     0,   224,   225,
     226,   227,   228,   229,   137,   138,   139,   140,   141,   142,
     143,   144,   216,     0,     0,     0,     0,   217,   218,   219,
     220,   221,   222,     0,     0,     0,   291,   296,   299,   302,
     305,   308,   311,   315,   315,   321,   315,   315,   315,   315,
     315,   336,   341,   346,   350,   354,   358,   362,   365,   368,
     371,   374,   376,   379,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   407,   410,   413,   416,
     419,   422,   425,   315,   430,   432,   434,   436,   438,   440,
     443,   315,   315,   315,   315,   315,   315,   315,   461,   315,
     315,   315,   315,   315,   145,   146,   147,   148,   149,   150,
       0,   481,   483,   485,   487,   489,   491,     0,     0,   156,
     157,   158,   159,   160,   161,   162,   163,     0,     0,   506,
     508,   510,   512,   514,   516,   518,   521,   522,   523,   524,
     525,   526,     0,   528,    78,    78,    78,    78,    78,    78,
       0,   539,    78,    78,    78,    78,   289,   294,   297,   300,
     303,   306,   309,   314,   317,   319,   324,   326,   328,   330,
     332,   334,   339,   344,   348,   352,   356,   360,   363,   366,
     369,   372,     0,   377,   382,   383,   385,   387,   389,   391,
     393,   395,   397,   399,   401,   403,   405,   408,   411,   414,
     417,   420,   423,   428,   429,   431,   433,   435,   437,   439,
     441,   446,   447,   449,   451,   453,   455,   457,   459,   464,
     466,   468,   469,   471,     1,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,     0,     0,
      10,   124,   125,   126,   127,   128,   129,     0,    11,     0,
       0,     0,   134,    12,   136,     0,   137,   138,   139,   140,
     141,   142,   143,   144,     0,     0,     0,    13,    14,    15,
       0,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    77,   113,     0,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,   562,     0,    10,   145,   146,   147,   148,   149,   150,
       0,    11,     0,     0,     0,   153,    12,   155,     0,   156,
     157,   158,   159,   160,   161,   162,   163,     0,     0,     0,
      13,    14,    15,     0,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
     113,     0,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,   599,     0,    10,   124,   125,   126,   127,
     128,   129,     0,    11,     0,     0,     0,   134,    12,     0,
       0,   137,   138,   139,   140,   141,   142,   143,   144,     0,
       0,     0,    13,    14,    15,     0,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,   180,   181,   182,   183,   184,   185,   124,   125,
     126,   127,   128,   129,     0,     0,     0,    90,     3,     4,
       5,     6,     7,     8,     0,     9,     0,    91,     0,     0,
      10,   145,   146,   147,   148,   149,   150,     0,    11,     0,
       0,     0,   153,    12,     0,     0,   156,   157,   158,   159,
     160,   161,   162,   163,     0,     0,     0,    13,    14,    15,
       0,    78,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,   263,     0,
      10,   164,   165,   166,   167,   168,   169,   170,    11,     0,
       0,   171,     0,    12,     0,     0,     0,     0,   172,   173,
     174,   175,   176,   177,     0,     0,     0,    13,    14,    15,
       0,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,     0,     0,
      10,   217,   218,   219,   220,   221,   222,   223,    11,     0,
       0,     0,     0,    12,     0,     0,     0,     0,   224,   225,
     226,   227,   228,   229,     0,     0,     0,    13,    14,    15,
       0,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,   124,   125,   126,
     127,   128,   129,   130,   131,   132,     0,   133,   134,   135,
     136,     0,   137,   138,   139,   140,   141,   142,   143,   144,
     124,   125,   126,   127,   128,   129,     0,   131,   132,     0,
     133,   134,   135,   136,     0,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
       0,     0,     0,   152,   153,   154,   155,     0,   156,   157,
     158,   159,   160,   161,   162,   163,   124,   125,   126,   127,
     128,   129,     0,   131,     0,     0,   133,   134,   135,   136,
       0,   137,   138,   139,   140,   141,   142,   143,   144,   199,
     200,   201,   202,   203,   150,   204,     0,     0,     0,     0,
     205,   206,   207,     0,   208,   209,   210,   211,   212,   213,
     214,   215,   145,   146,   147,   148,   149,   150,     0,     0,
       0,     0,   152,   153,   154,   155,     0,   156,   157,   158,
     159,   160,   161,   162,   163,   124,   125,   126,   127,   128,
     129,     0,     0,     0,     0,   133,   134,   135,   136,     0,
     137,   138,   139,   140,   141,   142,   143,   144,   124,   125,
     126,   127,   128,   129,   252,   253,   254,   255,   256,   134,
     135,   136,     0,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,     0,     0,     0,
       0,     0,   153,   154,   155,     0,   156,   157,   158,   159,
     160,   161,   162,   163,   199,   200,   201,   202,   203,   150,
       0,     0,     0,     0,     0,   205,   206,   207,     0,   208,
     209,   210,   211,   212,   213,   214,   215,   164,   165,   166,
     167,   168,   169,     0,     0,   124,   125,   126,   127,   128,
     129,     0,     0,     0,   172,   173,   174,   175,   176,   177,
     137,   138,     0,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   217,   218,   219,   220,   221,   222,
       0,     0,     0,   156,   157,     0,     0,   160,   161,   162,
     163,   224,   225,   226,   227,   228,   229,   164,   165,   166,
     167,   168,   169,     0,   198,     0,     0,     0,     0,   199,
     200,   201,   202,   203,   150,     0,   174,   175,   176,   177,
     205,   206,   207,   198,   208,   209,     0,     0,   252,   253,
     254,   255,   256,   145,   146,   147,   148,   149,   150,   205,
     206,   207,     0,   208,   209,   199,   200,   201,   202,   203,
     150,     0,     0,     0,     0,   178,   205,   206,   207,   179,
     208,   209,     0,     0,     0,     0,   180,   181,   182,   183,
     184,   185,   145,   146,   147,   148,   149,   150,     0,   231,
     164,   165,   166,   167,   168,   169,     0,   156,   157,     0,
     232,   233,   234,   235,   236,   237,   232,   233,   234,   235,
     236,   237,   217,   218,   219,   220,   221,   222
  };

  const short
   Parser ::yycheck_[] =
  {
       0,    91,    68,     0,   477,     9,   277,     9,     8,     9,
       9,    11,    32,     9,     9,    62,   578,    11,    18,    19,
      98,     9,   100,   194,   102,    12,   104,    62,   590,     9,
      46,    47,    32,     0,    10,    32,    11,    11,    40,    11,
      11,     8,    11,    10,     9,     9,     9,    10,   610,     9,
       9,    18,    62,    40,    42,   558,   618,   560,    62,    39,
      60,    55,    42,    62,    40,    32,    62,    62,    68,     3,
       4,     5,     6,     7,     8,     9,    39,    11,    12,    39,
      55,    55,    16,    55,    55,    10,    55,    87,    62,    89,
      24,    91,    62,   113,    91,    29,     3,    55,    98,     3,
     100,    22,   102,     0,   104,    12,   277,   278,   108,    13,
       3,    32,    33,   113,    10,    40,   113,    62,   621,   622,
     120,    14,   122,    55,    91,    21,    22,    23,    62,     3,
     130,   570,   571,   133,   637,     3,    32,    33,   611,   139,
     140,   141,   142,   143,   144,   648,   113,     3,   651,     3,
      43,   151,    32,    33,   121,    32,    33,    13,    12,     3,
       3,    55,    55,    56,    57,    58,    59,     3,   607,    62,
     170,     3,   262,    15,    16,    17,    18,    19,   178,   245,
     180,   181,   182,   183,   184,   185,   186,     3,    30,    31,
       0,    21,    22,    23,    11,    25,   196,    42,     8,     9,
      43,    11,    32,    33,   204,     4,     5,    40,    18,    19,
       9,    40,    55,    56,    57,    58,    59,    16,    22,    62,
      42,    25,    32,   223,    17,    18,    19,    20,    32,    33,
      29,   231,   232,   233,   234,   235,   236,   237,    62,   239,
     240,   241,   242,   243,   264,   245,    17,    18,    19,    20,
      60,     4,     5,     6,     7,    49,     9,   257,    68,    17,
      18,    19,   262,    16,   264,   262,   266,   264,     4,     5,
      13,    24,     9,     9,     9,    25,    29,    87,    39,    89,
      16,    91,    32,    33,    19,    62,    12,    62,    98,    10,
     100,    10,   102,    29,   104,   262,    41,   264,   108,   570,
     571,     9,     4,   113,    13,    12,   477,     9,    40,    62,
     120,    40,   122,    12,    16,   282,    17,    18,    19,    20,
     130,   131,   132,   133,    22,    23,    62,    29,    12,   139,
     140,    12,    12,    68,    32,    33,   607,    34,    35,    36,
      37,   151,    10,     9,    20,     3,     4,     5,     6,     7,
       8,     9,    87,    11,    89,    20,    20,    20,    16,    10,
     170,     3,    12,    98,    12,   100,    24,   102,   178,   104,
      62,    29,     3,   108,    14,    46,   186,   187,   188,    40,
     190,   191,    10,     3,    10,   120,   196,   122,    42,    14,
       4,     5,     6,     7,   204,     9,    42,    10,    42,   570,
     571,     9,    16,    40,    62,    21,    22,    23,     9,   612,
      24,    10,    10,   223,   586,    29,    32,    33,   589,   582,
     589,   231,   232,   233,   234,   235,   236,   237,    -1,   239,
     240,   241,   242,   243,    -1,   245,   607,    -1,    -1,    -1,
     611,   612,    55,    56,    57,    58,    59,   257,    62,    62,
      -1,    -1,   262,    -1,   264,    -1,   266,    -1,    -1,    10,
      -1,   196,    -1,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    -1,    -1,    -1,    16,    -1,    -1,   478,    -1,
      -1,    -1,   548,    24,    -1,    -1,    -1,   565,    29,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    -1,    -1,
      -1,    16,    -1,    -1,    55,    56,    57,    58,    59,    24,
     245,    62,    -1,    -1,    29,    -1,    55,    56,    57,    58,
      59,    62,   257,    62,    -1,     4,     5,     6,     7,     8,
       9,   266,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
      -1,   561,    -1,    -1,    10,    24,    -1,    62,   548,    -1,
      29,    34,    35,    36,    37,    21,    -1,    -1,   558,   559,
     560,   561,    -1,   563,   561,   565,    32,    33,    34,    35,
      36,    37,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    -1,    62,    16,    -1,   586,   587,    -1,    -1,
      -1,   558,    24,   560,   561,    10,    -1,    29,    -1,    -1,
       4,     5,     6,     7,     8,     9,    25,    11,    12,    -1,
      -1,    -1,    16,    32,    33,    34,    35,    36,    37,    -1,
      24,   621,   622,    -1,    -1,    29,   626,    -1,   628,    -1,
      62,    -1,    -1,   633,    -1,   635,    -1,   637,    -1,    -1,
      55,    56,    57,    58,    59,    -1,   646,    62,   648,    -1,
      -1,   651,    -1,    -1,   621,   622,     0,     1,    62,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,   478,    -1,
     637,    10,    16,    -1,    -1,    15,    16,    17,    18,    19,
      24,   648,    21,    -1,   651,    29,    26,    -1,    28,    -1,
      30,    31,    -1,    32,    33,    34,    35,    36,    37,    43,
      44,    45,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    -1,
       4,     5,     6,     7,     8,     9,    10,    11,    17,    18,
      19,    20,    16,    -1,    -1,    -1,    22,    23,   548,    25,
      24,    -1,    -1,   478,    -1,    29,    32,    33,   558,   559,
     560,   561,    -1,   563,    -1,   565,    -1,    -1,    -1,     4,
       5,     6,     7,     8,     9,    -1,    11,    17,    18,    19,
      20,    16,    -1,    -1,    -1,    -1,   586,   587,    62,    24,
      -1,    -1,    -1,    -1,    29,     4,     5,     6,     7,    -1,
       9,    15,    16,    17,    18,    19,     8,    16,    10,    11,
      12,    -1,    26,    -1,    -1,    24,    30,    31,    -1,    -1,
      29,   621,   622,   548,    -1,    -1,   626,    62,   628,     4,
       5,     6,     7,   633,     9,   635,    -1,   637,   563,    -1,
     565,    16,    -1,    -1,    -1,    -1,   646,    -1,   648,    24,
      -1,   651,    -1,    62,    29,    -1,    -1,    -1,    60,    61,
      -1,   586,   587,    -1,    -1,    -1,    -1,    10,    -1,    -1,
      -1,    73,    15,    16,    17,    18,    19,    20,    21,    81,
      82,    -1,    -1,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    15,    16,    17,    18,    19,
      20,   626,    -1,   628,    -1,    25,    -1,    -1,   633,    -1,
     635,    -1,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,   646,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       8,    -1,    10,    11,    -1,    -1,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,    -1,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,    -1,   231,
     232,   233,   234,   235,   236,   237,    -1,   239,   240,   241,
     242,   243,    60,    61,    15,    16,    17,    18,    19,    20,
     252,   253,   254,   255,   256,    73,    10,    -1,    -1,    30,
      31,    15,    16,    17,    18,    19,    20,    21,    -1,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37,    30,    31,    32,    33,    34,    35,
      36,    37,    10,    -1,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    15,    16,    17,    18,    19,    20,
      -1,   199,   200,   201,   202,   203,   204,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,    -1,   231,   232,   233,   234,   235,   236,   237,
      -1,   239,   240,   241,   242,   243,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    -1,    -1,    -1,    -1,
      16,    15,    16,    17,    18,    19,    20,    -1,    24,    -1,
      -1,    -1,    26,    29,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    43,    44,    45,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,   559,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
      -1,    14,    -1,    16,    15,    16,    17,    18,    19,    20,
      -1,    24,    -1,    -1,    -1,    26,    29,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      43,    44,    45,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    -1,    -1,    14,    -1,    16,    15,    16,    17,    18,
      19,    20,    -1,    24,    -1,    -1,    -1,    26,    29,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    43,    44,    45,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    32,    33,    34,    35,    36,    37,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    -1,    13,    -1,    -1,
      16,    15,    16,    17,    18,    19,    20,    -1,    24,    -1,
      -1,    -1,    26,    29,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    43,    44,    45,
      -1,   559,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    -1,    -1,    14,    -1,
      16,    15,    16,    17,    18,    19,    20,    21,    24,    -1,
      -1,    25,    -1,    29,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    43,    44,    45,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    -1,    -1,    -1,    -1,
      16,    15,    16,    17,    18,    19,    20,    21,    24,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    43,    44,    45,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    25,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    -1,
      25,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    25,    26,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    15,    16,    17,    18,
      19,    20,    -1,    22,    -1,    -1,    25,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    25,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    15,    16,
      17,    18,    19,    20,    15,    16,    17,    18,    19,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    15,    16,    17,
      18,    19,    20,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    32,    33,    34,    35,    36,    37,
      30,    31,    -1,    -1,    34,    35,    36,    37,    15,    16,
      17,    18,    19,    20,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    30,    31,    -1,    -1,    34,    35,    36,
      37,    32,    33,    34,    35,    36,    37,    15,    16,    17,
      18,    19,    20,    -1,    10,    -1,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    -1,    34,    35,    36,    37,
      26,    27,    28,    10,    30,    31,    -1,    -1,    15,    16,
      17,    18,    19,    15,    16,    17,    18,    19,    20,    26,
      27,    28,    -1,    30,    31,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    21,    26,    27,    28,    25,
      30,    31,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    37,    15,    16,    17,    18,    19,    20,    -1,    21,
      15,    16,    17,    18,    19,    20,    -1,    30,    31,    -1,
      32,    33,    34,    35,    36,    37,    32,    33,    34,    35,
      36,    37,    15,    16,    17,    18,    19,    20
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
      21,    22,    23,    25,    26,    27,    28,    30,    31,    32,
      33,    34,    35,    36,    37,    15,    16,    17,    18,    19,
      20,    21,    25,    26,    27,    28,    30,    31,    32,    33,
      34,    35,    36,    37,    15,    16,    17,    18,    19,    20,
      21,    25,    32,    33,    34,    35,    36,    37,    21,    25,
      32,    33,    34,    35,    36,    37,    21,    22,    23,    25,
      32,    33,    55,    55,     9,    62,    11,    10,    10,    15,
      16,    17,    18,    19,    21,    26,    27,    28,    30,    31,
      32,    33,    34,    35,    36,    37,    10,    15,    16,    17,
      18,    19,    20,    21,    32,    33,    34,    35,    36,    37,
      10,    21,    32,    33,    34,    35,    36,    37,    10,    21,
      22,    23,    32,    33,    98,    40,     3,    12,    99,   100,
      99,    99,    15,    16,    17,    18,    19,    42,    40,    94,
      62,    94,    13,    14,    66,    49,    42,    12,    94,   106,
      12,   106,    12,   106,    12,   106,     3,    13,     9,    12,
      94,   106,    39,    67,    10,    91,    94,    93,    94,    95,
      99,   100,   101,   102,    95,    99,   100,    95,    99,   100,
      95,    99,   100,    95,    99,   100,    95,    99,   100,    95,
      99,   100,   101,   102,    95,   100,   102,    95,   102,    95,
      99,   100,   101,   102,    95,    99,    95,    99,    95,    99,
      95,    99,    95,    99,    95,    99,   100,   101,   102,    95,
      99,   100,   101,   102,    95,    99,   100,   101,    95,    99,
     100,   101,    95,    99,   100,   101,    95,    99,   100,   101,
      95,    99,   100,    95,    99,   100,    95,    99,   100,    95,
      99,   100,    95,    99,   100,    99,   100,    95,    99,   100,
     101,   102,    95,    95,    99,    95,    99,    95,    99,    95,
      99,    95,    99,    95,    99,    95,    99,    95,    99,    95,
      99,    95,    99,    95,    99,    95,    99,   100,    95,    99,
     100,    95,    99,   100,    95,    99,   100,    95,    99,   100,
      95,    99,   100,    95,    99,   100,   101,   102,    95,    95,
     100,    95,   100,    95,   100,    95,   100,    95,   100,    95,
     100,    95,    99,   100,   101,   102,    95,    95,   101,    95,
     101,    95,   101,    95,   101,    95,   101,    95,   101,    95,
      99,   100,   101,   102,    95,   102,    95,   102,    95,    95,
     102,    95,   102,    10,    62,   104,   107,     9,    42,    94,
      99,   100,    99,   100,    99,   100,    99,   100,    99,   100,
      99,   100,   101,   102,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,   100,    99,   100,    99,
     100,    99,   100,    99,   100,    99,   100,    99,   100,   101,
     102,   100,   100,   100,   100,   100,   100,    99,   100,   101,
     102,   101,   102,   101,   101,   101,   101,   101,    99,   100,
     101,   102,   102,   102,   102,   102,     3,    12,     3,    98,
      12,    99,    99,    99,    99,    99,    94,    62,    10,    41,
      10,    66,    14,     9,    94,    40,    12,    12,    12,    12,
      13,     3,    14,    43,    82,    83,    87,   107,    10,    85,
      86,   107,    12,    12,    93,    10,    40,    11,    10,    40,
      10,    85,    94,    12,    98,    70,    62,   101,    70,    14,
       3,    94,   106,    82,    82,    62,    14,     3,    62,    69,
      10,    40,    40,    62,    92,    91,   104,    69,    10,    46,
      79,    10,    10,     3,    10,    14,    42,    82,    42,    69,
      85,    86,   107,    42,    69,     9,    46,    47,    80,    70,
      70,    94,    94,    62,    94,    94,     9,    70,    10,    94,
      70,    10,    70
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
      93,    94,    94,    94,    94,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    96,    96,    96,    96,    97,    97,    97,    97,    97,
      98,    98,    98,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   103,   103,   104,   104,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   106,   106,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107
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
       3,     1,     1,     1,     1,     1,     2,     3,     3,     3,
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
       3,     1,     1,     1,     1,     2,     3,     4,     4,     5,
       1,     3,     4,     1,     2,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     3,     1,     3,     4,     3,     4,     3,     4,
       3,     4,     3,     4,     3,     1,     3,     2,     2,     2,
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
     310,   314,   315,   316,   317,   320,   321,   322,   324,   325,
     326,   328,   329,   330,   331,   332,   334,   335,   336,   337,
     338,   340,   341,   342,   343,   344,   346,   347,   348,   349,
     350,   352,   353,   354,   355,   356,   358,   359,   360,   362,
     363,   364,   366,   367,   368,   369,   370,   371,   372,   374,
     375,   376,   377,   378,   379,   380,   382,   383,   384,   385,
     386,   387,   388,   390,   391,   392,   393,   394,   395,   396,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   418,   419,
     420,   422,   423,   424,   426,   427,   428,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   440,   441,   442,   444,
     445,   446,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   460,   461,   462,   463,   467,   468,   469,   470,   471,
     473,   474,   475,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   569,   570,   572,   573,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   588,   589,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607
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
#line 2493 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"

#line 610 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    std::cerr << scanner->loc->begin.line << ":" << scanner->loc->begin.column << ": " << err_message << std::endl;
}
