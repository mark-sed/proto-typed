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
  case 235: // expr_int: "int"
#line 520 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 787 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 236: // expr_int: "-" expr_int
#line 521 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 793 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 237: // expr_int: "(" expr_int ")"
#line 522 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 799 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 238: // expr_int: "~" expr_int
#line 523 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 805 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 239: // expr_int: expr_int "*" expr_int
#line 524 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 811 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 240: // expr_int: expr_int "/" expr_int
#line 525 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 817 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 241: // expr_int: expr_int "%" expr_int
#line 526 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 823 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 242: // expr_int: expr_int "-" expr_int
#line 527 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 829 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 243: // expr_int: expr_int "+" expr_int
#line 528 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 835 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 244: // expr_int: expr_int "<<" expr_int
#line 529 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 841 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 245: // expr_int: expr_int ">>" expr_int
#line 530 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 847 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 246: // expr_int: expr_int "&" expr_int
#line 531 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 853 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 247: // expr_int: expr_int "^" expr_int
#line 532 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 859 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 248: // expr_int: expr_int "|" expr_int
#line 533 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 865 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 249: // expr_float: "float"
#line 537 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 871 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 250: // expr_float: "-" expr_float
#line 538 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 877 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 251: // expr_float: "(" expr_float ")"
#line 539 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 883 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 252: // expr_float: expr_float "**" expr_float
#line 540 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 889 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 253: // expr_float: expr_float "**" expr_int
#line 541 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 895 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 254: // expr_float: expr_int "**" expr_float
#line 542 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 901 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 255: // expr_float: expr_float "*" expr_float
#line 543 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 907 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 256: // expr_float: expr_float "*" expr_int
#line 544 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 913 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 257: // expr_float: expr_int "*" expr_float
#line 545 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 919 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 258: // expr_float: expr_float "/" expr_float
#line 546 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 925 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 259: // expr_float: expr_float "/" expr_int
#line 547 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 931 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 260: // expr_float: expr_int "/" expr_float
#line 548 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 937 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 261: // expr_float: expr_float "%" expr_float
#line 549 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 943 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 262: // expr_float: expr_float "%" expr_int
#line 550 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 949 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 263: // expr_float: expr_int "%" expr_float
#line 551 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 955 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 264: // expr_float: expr_float "-" expr_float
#line 552 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 961 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 265: // expr_float: expr_float "-" expr_int
#line 553 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 967 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 266: // expr_float: expr_int "-" expr_float
#line 554 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 973 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 267: // expr_float: expr_float "+" expr_float
#line 555 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 979 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 268: // expr_float: expr_float "+" expr_int
#line 556 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 985 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 269: // expr_float: expr_int "+" expr_float
#line 557 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 991 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 270: // expr_str: "string"
#line 561 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 997 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 271: // expr_str: "(" expr_str ")"
#line 562 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 1003 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 272: // expr_str: expr_str "++" expr_str
#line 563 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 1009 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 273: // expr_str: expr_str "++" expr_int
#line 564 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 1015 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 274: // expr_str: expr_str "++" expr_float
#line 565 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 1021 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 275: // expr_str: expr_str "++" expr_bool
#line 566 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1027 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 276: // expr_str: expr_str "++" expr_none
#line 567 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 1033 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 277: // expr_str: expr_int "++" expr_str
#line 568 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 1039 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 278: // expr_str: expr_int "++" expr_int
#line 569 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 1045 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 279: // expr_str: expr_int "++" expr_float
#line 570 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 1051 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 280: // expr_str: expr_int "++" expr_bool
#line 571 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1057 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 281: // expr_str: expr_int "++" expr_none
#line 572 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 1063 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 282: // expr_str: expr_float "++" expr_str
#line 573 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 1069 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 283: // expr_str: expr_float "++" expr_int
#line 574 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 1075 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 284: // expr_str: expr_float "++" expr_float
#line 575 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 1081 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 285: // expr_str: expr_float "++" expr_bool
#line 576 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1087 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 286: // expr_str: expr_float "++" expr_none
#line 577 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 1093 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 287: // expr_str: expr_bool "++" expr_str
#line 578 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 1099 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 288: // expr_str: expr_bool "++" expr_int
#line 579 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 1105 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 289: // expr_str: expr_bool "++" expr_float
#line 580 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 1111 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 290: // expr_str: expr_bool "++" expr_bool
#line 581 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1117 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 291: // expr_str: expr_bool "++" expr_none
#line 582 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 1123 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 292: // expr_str: expr_none "++" expr_str
#line 583 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 1129 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 293: // expr_str: expr_none "++" expr_int
#line 584 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 1135 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 294: // expr_str: expr_none "++" expr_float
#line 585 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 1141 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 295: // expr_str: expr_none "++" expr_bool
#line 586 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1147 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 296: // expr_str: expr_none "++" expr_none
#line 587 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 1153 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 297: // expr_bool: "bool"
#line 591 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 1159 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 298: // expr_bool: "(" expr_bool ")"
#line 592 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 1165 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 299: // expr_bool: "not" expr_bool
#line 593 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 1171 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 300: // expr_bool: expr_bool "or" expr_bool
#line 594 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 1177 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 301: // expr_bool: expr_bool "and" expr_bool
#line 595 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 1183 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 302: // expr_bool: expr_bool "==" expr_bool
#line 596 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 1189 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 303: // expr_bool: expr_int "==" expr_int
#line 597 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 1195 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 304: // expr_bool: expr_float "==" expr_float
#line 598 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 1201 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 305: // expr_bool: expr_str "==" expr_str
#line 599 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 1207 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 306: // expr_bool: expr_none "==" expr_none
#line 600 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 1213 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 307: // expr_bool: expr_bool "!=" expr_bool
#line 601 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 1219 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 308: // expr_bool: expr_int "!=" expr_int
#line 602 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 1225 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 309: // expr_bool: expr_float "!=" expr_float
#line 603 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 1231 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 310: // expr_bool: expr_str "!=" expr_str
#line 604 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 1237 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 311: // expr_bool: expr_none "!=" expr_none
#line 605 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 1243 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 312: // expr_bool: expr_int ">" expr_int
#line 606 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 1249 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 313: // expr_bool: expr_float ">" expr_float
#line 607 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 1255 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 314: // expr_bool: expr_str ">" expr_str
#line 608 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 1261 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 315: // expr_bool: expr_int "<" expr_int
#line 609 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 1267 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 316: // expr_bool: expr_float "<" expr_float
#line 610 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 1273 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 317: // expr_bool: expr_str "<" expr_str
#line 611 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 1279 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 318: // expr_bool: expr_int ">=" expr_int
#line 612 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 1285 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 319: // expr_bool: expr_float ">=" expr_float
#line 613 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 1291 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 320: // expr_bool: expr_str ">=" expr_str
#line 614 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 1297 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 321: // expr_bool: expr_int "<=" expr_int
#line 615 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 1303 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 322: // expr_bool: expr_float "<=" expr_float
#line 616 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 1309 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 323: // expr_bool: expr_str "<=" expr_str
#line 617 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 1315 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;


#line 1319 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -610;

  const short  Parser ::yytable_ninf_ = -353;

  const short
   Parser ::yypact_[] =
  {
    1236,  -610,  -610,  -610,  -610,  -610,  -610,  -610,   667,    40,
      49,   855,   185,   -49,   -45,    30,    33,    52,  1441,  1540,
    -610,  -610,     2,    36,    17,    27,    29,    46,    68,    72,
      16,   101,   765,  -610,  -610,   120,   189,  -610,  -610,  -610,
    -610,  -610,  -610,  -610,   197,   201,   208,  -610,   802,   210,
    1328,  -610,  -610,  -610,   121,  1820,  2073,   686,  1171,   176,
     215,    -3,   178,  1691,   311,   293,    61,   296,   154,  1030,
    1603,   342,   253,  1540,  -610,    -2,   271,    99,   311,    -2,
    -610,  -610,  1866,  2107,   711,  -610,   185,   185,  -610,   272,
    -610,   277,  1540,   256,  1540,   306,  1514,  -610,  -610,   273,
    -610,   292,  -610,   289,  -610,   541,  -610,   555,  -610,   627,
    -610,   107,   329,   653,  -610,   319,  -610,  -610,  1587,  -610,
    -610,  -610,  -610,  -610,  -610,  1162,   275,  1540,  1540,  1540,
    1540,  1540,  1540,  1540,  1540,  1540,  1540,  1540,  1540,  1540,
    1540,  -610,  1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,
    1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,
    1601,  1601,  1601,   855,  1601,  1601,  1601,  1601,  1601,  1601,
    1601,   311,  1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,
    1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,
    1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,
    1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,
    1601,  1601,  1601,  -610,  -610,    98,    25,  -610,  1540,  -610,
    -610,    67,    67,  -610,   311,   311,   311,   311,   311,   855,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,  -610,   311,   311,   311,   311,   311,   311,   855,   311,
     311,   311,   311,   311,   311,  -610,   855,   855,   855,   855,
     855,   855,   855,  -610,   855,   855,   855,   855,   855,   114,
     174,   347,  -610,   371,   235,   788,  -610,   185,   185,   185,
     185,   185,  1540,   286,   352,   330,   370,  1587,  -610,  1015,
     383,  1540,  -610,   353,   384,  -610,   388,  -610,   462,  -610,
     463,   382,   285,   274,  -610,    10,   464,   275,  -610,  -610,
     474,   476,   493,  -610,  -610,  -610,  -610,  -610,  -610,  -610,
    -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,  1659,   513,
     121,   563,   635,   686,  1171,   513,   563,   635,   504,   516,
     517,   504,   516,   517,   504,   516,   517,   504,  1820,   517,
    1797,  1889,  1444,   750,   585,  1912,  2073,   123,  1843,   304,
    1935,  1958,  2114,   446,   191,   949,  2084,  1693,  2004,  2027,
    2050,  1206,  1212,  1206,  1212,  2137,  -610,  2145,   743,   244,
    -610,  2137,  -610,  2145,   743,   244,  -610,   575,  1686,  1238,
    -610,   575,  1686,  1238,  -610,   575,  1686,  1238,  -610,   575,
    1686,  1238,  -610,   194,  1981,  2168,  1252,   129,  2137,  -610,
    2137,  -610,   513,   563,   635,   513,   563,   635,   504,   516,
     517,   504,   516,   517,   504,   516,   517,   850,   524,  1797,
     270,  1889,  1444,   750,   585,  1935,   949,  2084,  1693,  2004,
    2027,  2050,  1206,  1212,  1206,  1212,  2137,  2145,  2137,  2145,
     575,  1686,   575,  1686,   575,  1686,   575,  1686,   513,   563,
     635,   513,   563,   635,   504,   516,   517,   504,   516,   517,
     504,   516,   517,   504,   516,   517,  1797,   270,  1889,  1444,
     750,   585,  1935,  2137,   743,  2137,   743,   575,  1238,   575,
    1238,   575,  1238,   575,  1238,  1797,   270,  1889,  1444,   750,
     585,  1935,  2137,   244,  2137,   244,   575,  -610,   575,  -610,
     575,  -610,   575,  -610,  1797,   270,  1889,  1444,   750,   585,
    1912,   123,  1843,   304,  1935,  2137,  -610,  2137,  -610,  -610,
      48,   544,    20,   297,  1540,   539,   547,  -610,  -610,  1035,
    1157,  1035,  1157,   516,   524,   516,   524,   516,   524,   194,
    1981,  2168,  1252,   129,  2202,  2180,  2197,  1303,  1303,  2202,
    2202,  2202,  2202,  2202,  2202,  1035,  1157,  1035,  1157,   516,
     524,   516,   524,   516,   524,   516,   524,   194,  1981,  2168,
    1252,   129,  1297,  1297,  1297,  1297,  1297,  1297,   194,  1981,
    2168,  1252,   129,   838,   672,   838,  -610,  -610,  -610,  -610,
     194,  1981,  2168,  1252,   129,   276,   187,  -610,  -610,   546,
    -610,  1540,  -610,  -610,   365,   365,  -610,  -610,  -610,  -610,
    -610,  1441,  1665,  1441,  1267,   553,  1540,  -610,  1540,  -610,
    -610,  -610,  -610,    18,    18,  -610,   494,   554,   569,  -610,
       4,   202,    26,   533,     6,   293,  -610,   493,  -610,  1540,
     653,  -610,   966,   202,    58,  -610,   178,  -610,  -610,   515,
     566,   565,  -610,   582,  -610,   577,  -610,   574,  -610,   561,
    -610,    18,   562,  -610,   202,   966,   966,   567,  -610,  -610,
    -610,  -610,   202,   604,   263,  1441,  1441,  -610,  -610,  -610,
    1540,  -610,  1540,  -610,   589,   533,     8,  1540,  -610,  1540,
     605,  1441,  -610,  -610,  -610,  -610,  -610,   567,  -610,   615,
    1540,  -610,  1441,   630,  -610,  1441,  -610
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     7,   235,   249,   270,   297,   233,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      31,    32,     0,     0,   348,   349,   350,   351,     0,     0,
      90,     0,     0,     4,     8,     0,     0,    33,    14,    16,
      17,    15,    18,    19,     0,     0,     0,    91,    99,     0,
      96,    97,   231,    95,    98,   219,   220,   221,   222,   353,
     354,     0,   233,     0,     0,    90,     0,     0,     0,     0,
       0,     0,     0,     0,   223,    99,   228,     0,     0,   100,
     236,   250,     0,     0,     0,   299,     0,     0,   238,     0,
      29,    28,     0,     0,     0,     0,     0,    26,    27,     0,
      35,     0,   340,     0,   341,     0,   342,     0,   343,     0,
     344,     0,     0,     0,   345,    92,     1,     3,     0,     5,
      13,    20,    11,    12,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   346,   347,     0,    65,   234,     0,   101,
     232,     0,     0,   237,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   251,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   271,     0,     0,     0,     0,
       0,     0,     0,   298,     0,     0,     0,     0,     0,     0,
       0,     0,   224,     0,     0,     0,   236,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,   331,   338,     0,   333,     0,   335,     0,   337,
       0,     0,     0,     0,   329,     0,     0,     0,     6,    84,
       0,    86,    94,    83,    82,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,     0,   124,
       0,   122,   123,     0,     0,   129,   127,   128,   109,   107,
     108,   114,   112,   113,   119,   117,   118,   104,     0,   103,
     218,   214,   215,   216,   217,   206,     0,   205,   209,   208,
     203,   199,   200,   201,   202,   188,   187,   194,   193,   191,
     190,   132,   131,   135,   134,   174,   173,   169,   170,   171,
     172,   185,   184,   180,   181,   182,   183,   142,   139,   140,
     141,   156,   153,   154,   155,   149,   146,   147,   148,   163,
     160,   161,   162,   296,   293,   294,   292,   295,   168,   306,
     179,   311,   120,   243,   269,   125,   242,   266,   105,   239,
     257,   110,   240,   260,   115,   241,   263,     0,   254,   210,
     281,   278,   279,   277,   280,   195,   186,   246,   192,   248,
     189,   247,   130,   244,   133,   245,   164,   303,   175,   308,
     136,   312,   150,   315,   143,   318,   157,   321,   121,   268,
     267,   126,   265,   264,   106,   256,   255,   111,   259,   258,
     116,   262,   261,   102,   253,   252,   211,   286,   283,   284,
     282,   285,   196,   165,   304,   176,   309,   137,   313,   151,
     316,   144,   319,   158,   322,   212,   276,   273,   274,   272,
     275,   197,   166,   305,   177,   310,   138,   314,   152,   317,
     145,   320,   159,   323,   213,   291,   288,   289,   287,   290,
     204,   301,   207,   300,   198,   167,   302,   178,   307,   325,
     352,     0,   326,     0,     0,     0,     0,   306,   311,   243,
     269,   242,   266,   239,   257,   240,   260,   241,   263,   281,
     278,   279,   277,   280,   246,   248,   247,   244,   245,   303,
     308,   312,   315,   318,   321,   268,   267,   265,   264,   256,
     255,   259,   258,   262,   261,   253,   252,   286,   283,   284,
     282,   285,   304,   309,   313,   316,   319,   322,   276,   273,
     274,   272,   275,   305,     0,   310,   314,   317,   320,   323,
     291,   288,   289,   287,   290,   301,   300,   302,   307,     0,
     225,     0,   229,   226,   243,   242,   239,   240,   241,    68,
      30,     0,     0,     0,     0,    22,     0,    67,     0,   330,
     332,   334,   336,     0,    49,    46,     0,     0,     0,    53,
       0,     0,     0,    61,     0,    88,   328,    93,    85,     0,
       0,   324,     0,     0,     0,    66,     0,   227,   230,    43,
       0,     0,    38,    23,    24,     0,   339,     0,    50,     0,
      47,    51,    65,    58,     0,     0,     0,    60,    89,    87,
     327,    56,     0,     0,    45,     0,     0,    25,    39,    48,
       0,    52,     0,    59,    62,    64,     0,     0,    57,     0,
       0,     0,    40,    36,    37,    55,    54,     0,    63,     0,
       0,    44,     0,     0,    41,     0,    42
  };

  const short
   Parser ::yypgoto_[] =
  {
    -610,  -610,   -94,   -12,     3,  -457,  -541,  -610,  -610,  -610,
    -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,  -609,  -610,
    -610,  -529,   -35,  -301,  -610,   518,  -610,    -7,    21,    23,
     103,  1599,  -610,   640,   -68,  -610,     0,   261,   746,   952,
    1227,  -610,    11,  -610,   -93,   -56
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    31,    32,    33,    97,    98,    99,    35,    91,    36,
      37,    38,    39,    40,    41,   684,   702,    42,   637,   638,
      43,   642,   643,    44,    45,    46,    47,   310,   115,    75,
      49,    50,    51,    52,    77,    53,   330,    55,    56,    57,
      58,    59,   531,    60,   306,    61
  };

  const short
   Parser ::yytable_[] =
  {
      54,   639,   289,    34,   654,   269,   215,   125,    68,    54,
     294,    68,   296,   215,   298,   215,   300,   215,    54,    54,
     119,   634,   645,    48,   667,   668,    89,   113,   103,   215,
      90,    66,    54,    79,   533,    34,   674,   126,   105,    92,
     107,    48,    93,    73,     3,     4,     5,     6,     7,     8,
     628,     9,    74,     3,     4,    48,    10,   109,    78,   650,
     652,    94,   691,    68,    11,    64,   675,   534,   682,    12,
     125,   219,   216,    54,   636,     7,   536,   101,    12,   672,
     659,   677,   662,   707,   114,   104,    23,    24,    25,    26,
      27,  -352,    54,   530,    54,   106,    54,   108,   675,    34,
     126,   116,   271,    54,   102,    54,   308,    54,   529,    54,
     301,   272,    76,    54,   110,    65,   114,   609,    54,    48,
     302,    34,   100,   120,    65,    54,   610,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    48,   163,   111,   703,   704,   694,   112,   210,   312,
      48,   265,   266,   164,   165,   211,   212,   376,   382,   532,
     711,   267,   268,   403,   409,   411,    23,    24,    25,    26,
      27,   714,   430,   530,   716,   163,    76,   611,     3,     4,
       5,     6,     7,     8,   673,     9,   221,   222,   217,     3,
      10,   477,   121,   624,    86,   284,   681,   286,    11,   496,
     122,    87,   612,    12,   123,    95,   293,   515,   293,   265,
     293,   124,   293,   141,    12,    96,   305,   693,    54,   267,
     268,   537,   538,   211,   212,   698,   221,   222,   311,   549,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   213,   241,   640,   644,   577,    65,
     242,   243,   244,   245,   246,   247,   588,    68,    68,    68,
      68,    68,    68,   263,   600,    68,    68,    68,    68,    69,
      54,    80,    82,    88,   264,   265,   266,   119,   203,   204,
     205,   206,    54,   214,   641,   267,   268,    54,   634,    54,
      34,    54,    34,     3,     4,     5,     6,     7,     8,   635,
       9,   292,   164,   165,   218,    10,   220,   653,   267,   268,
      48,   270,    48,    11,   282,     3,     4,   283,    12,   287,
      78,   535,   700,   701,    69,    80,   208,    64,    68,   210,
     647,   285,   639,   639,   291,   290,   211,   212,   303,   273,
      12,   636,    23,    24,    25,    26,    27,   275,   276,   530,
      65,    66,   255,    23,    24,    25,    26,    27,   307,   613,
     530,   620,   621,   256,    65,    23,    24,    25,    26,    27,
     639,   622,   530,    76,   257,   258,   259,   260,   261,   262,
     623,   223,   279,   280,   281,   619,   224,   225,   226,   227,
     228,   171,   626,   628,   627,   633,   629,   230,   231,   232,
     630,   233,   234,   331,   336,   339,   342,   345,   348,   351,
     348,   348,   361,   366,   368,   370,   372,   374,   377,   383,
     388,   392,   396,   400,   404,   348,   348,   413,   416,   419,
     422,   425,   427,   431,   348,   437,   439,   441,   443,   445,
     447,   449,   451,   453,   455,   457,   459,   462,   465,   468,
     471,   474,   478,   348,   348,   348,   348,   348,   348,   348,
     497,   348,   348,   348,   348,   348,   348,   348,   516,   348,
     348,   348,   348,   348,   631,   632,   646,   644,   201,   202,
     203,   204,   205,   206,   648,   539,   541,   543,   545,   547,
     550,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   125,   565,   567,   569,   571,   573,   575,   578,
     427,   427,   427,   427,   427,   427,   649,   589,    82,    82,
      82,    82,    82,    82,   147,   601,    82,    82,    82,    82,
     144,   145,   146,   147,    54,   666,   171,   190,   614,   615,
     616,   617,   618,   658,   247,     3,     4,     5,     6,     7,
       8,   645,     9,   295,   651,   656,   664,    10,   657,     3,
       4,     5,     6,     7,     8,    11,     9,   297,   670,   669,
      12,    10,   671,   676,   683,   686,   685,   640,   640,    11,
     168,   169,   170,   171,    12,   687,   256,   688,   689,    69,
     142,   143,   144,   145,   146,   147,   532,   257,   258,   259,
     260,   261,   262,   690,   692,   155,   156,   208,   209,   697,
     210,    54,   119,   699,   710,   640,    65,   211,   212,   644,
     696,    54,    68,    54,    54,   712,    54,    34,    54,   675,
      65,     3,     4,     5,     6,     7,     8,   655,     9,   299,
     715,   695,   679,    10,    48,   313,    48,    48,    67,    54,
      54,    11,   187,   188,   189,   190,    12,     3,     4,     5,
       6,     7,     8,   680,     9,   304,   678,     0,     0,    10,
       0,     3,     4,     5,     6,    62,    63,    11,     9,     0,
       0,     0,    12,    64,     0,    54,    54,     0,     0,     0,
      54,    11,    54,   264,   265,   266,    12,    54,     0,    54,
       0,    54,    65,     0,   267,   268,     0,   199,    48,    48,
      54,   200,    54,     0,    76,    54,     0,     0,   201,   202,
     203,   204,   205,   206,    48,     0,     0,     0,    65,   665,
       0,   293,   256,     0,     0,    48,     0,     0,    48,     0,
       0,     0,    65,   257,   258,   259,   260,   261,   262,     0,
       0,     0,   311,   293,    70,     0,    81,    83,   185,   186,
     187,   188,   189,   190,     0,   117,   118,     0,     2,     3,
       4,     5,     6,     7,     8,   200,     9,   195,   196,   197,
     198,    10,   201,   202,   203,   204,   205,   206,     0,    11,
       0,     0,     0,   705,    12,   706,     0,     0,   223,     0,
     708,     0,   709,   277,   278,   279,   280,   281,     0,    70,
      81,   125,     0,   713,   230,   231,   232,     0,   233,   234,
       0,    13,    14,    15,   274,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,   126,     0,     0,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     3,
       4,     5,     6,     7,    63,   224,   225,   226,   227,   228,
     171,    64,   259,   260,   261,   262,   230,   231,   232,    11,
     233,   234,     0,    82,    12,     0,     0,     0,   332,   337,
     340,   343,   346,   349,   352,   356,   356,   362,   356,   356,
     356,   356,   356,   378,   384,   389,   393,   397,   401,   405,
     356,   356,   414,   417,   420,   423,   426,   428,   432,   356,
     356,   356,   356,   356,   356,   356,   356,   356,   356,   356,
     356,   460,   463,   466,   469,   472,   475,   479,   356,   484,
     486,   488,   490,   492,   494,   498,   356,   356,   356,   356,
     356,   356,   356,   517,   356,   356,   356,   356,   356,     0,
      71,     0,     0,    84,   142,   143,   144,   145,   146,   147,
     540,   542,   544,   546,   548,   551,     0,     0,     0,   155,
     156,   157,   158,   159,   160,   161,   162,     0,   566,   568,
     570,   572,   574,   576,   579,   582,   583,   584,   585,   586,
     587,     0,   590,    83,    83,    83,    83,    83,    83,     0,
     602,    83,    83,    83,    83,    71,   118,     0,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,   625,
       0,    10,     0,     0,    23,    24,    25,    26,    27,    11,
     223,   530,     0,     0,    12,   224,   225,   226,   227,   228,
     171,   229,   226,   227,   228,   171,   230,   231,   232,     0,
     233,   234,   235,   236,   237,   238,   239,   240,     0,     0,
       0,    13,    14,    15,    70,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,     0,     0,     0,   333,   333,   333,   333,   333,   333,
     353,   333,   333,   363,   333,   333,   333,   333,   333,   379,
     385,   390,   394,   398,   402,   406,   333,   333,   333,   333,
     333,   333,   333,     0,   433,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   480,   333,   333,   333,   333,   333,   333,
     333,   499,   333,   503,   505,   507,   509,   511,   513,   518,
     333,   333,   333,   333,   333,     0,     3,     4,     5,     6,
       7,     8,   309,     9,   244,   245,   246,   247,    10,     0,
       0,   552,     0,     0,     0,     0,    11,     0,     0,     0,
       0,    12,   207,   208,   209,     0,   210,     0,     0,     0,
     580,     0,     0,   211,   212,     0,     0,     0,   591,   593,
     595,   596,   597,   598,   599,     0,   603,    84,    84,    84,
      84,   142,   143,   144,   145,   146,   147,   166,   167,   168,
     169,   170,   171,     0,     0,    72,     1,    65,    85,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,     0,    10,   185,   186,   187,   188,   189,   190,     0,
      11,     0,     0,     0,     0,    12,     0,     0,   118,     0,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
      71,   663,     0,    10,   257,   258,   259,   260,   261,   262,
      72,    11,    13,    14,    15,     0,    12,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,   242,   243,   244,   245,   246,   247,   277,   278,
     279,   280,   281,    13,    14,    15,     0,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,   142,   143,   144,   145,   146,   147,   148,
     149,   150,     0,   151,   152,   153,   154,     0,   155,   156,
     157,   158,   159,   160,   161,   162,     0,     0,    83,   334,
     334,   334,   334,   334,   334,   354,   357,   359,   364,   334,
     334,   334,   334,   334,   380,   386,   334,   334,   334,   334,
     407,   334,   334,   334,   334,   334,   334,   334,     0,   434,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   481,   334,
     334,   334,   334,   334,   334,   334,   500,   334,   334,   334,
     334,   334,   334,   334,   519,   521,   523,   334,   526,   528,
       0,     0,     0,     0,    95,     3,     4,     5,     6,     7,
       8,     0,     9,     0,    96,     0,   553,    10,     0,   185,
     186,   187,   188,   189,   190,    11,     0,     0,     0,   192,
      12,     0,     0,     0,     0,   581,   193,   194,   195,   196,
     197,   198,     0,   592,   594,   594,   594,   594,   594,   594,
       0,   604,   605,   606,   607,   608,     0,    13,    14,    15,
       0,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,   288,     0,
      10,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,     0,     0,    12,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,     0,    72,    10,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,     0,     0,    12,
      13,    14,    15,     0,   661,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,     0,     0,    10,     0,     3,     4,     5,     6,     7,
     328,    11,     0,   241,     0,    65,    12,    10,   242,   243,
     244,   245,   246,   247,   248,    11,     0,     0,     0,     0,
      12,     0,     0,     0,     0,   249,   250,   251,   252,   253,
     254,     0,     0,    13,    14,    15,     0,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,     3,     4,     5,     6,    62,    63,     3,
       4,     5,     6,     7,    63,    64,    65,     0,     0,     0,
       0,    64,     0,    11,     0,     0,     0,     0,    12,    11,
       0,     0,     0,     0,    12,     3,     4,     5,     6,    62,
      63,   166,   167,   168,   169,   170,   171,    64,   142,   143,
     144,   145,   146,   147,     0,    11,   177,   178,     0,   152,
      12,   154,     0,   155,   156,   157,   158,   159,   160,   161,
     162,     0,     0,     0,    65,     0,     0,     0,     0,     0,
     660,   329,   335,   338,   341,   344,   347,   350,   355,   358,
     360,   365,   367,   369,   371,   373,   375,   381,   387,   391,
     395,   399,     0,   408,   410,   412,   415,   418,   421,   424,
       0,   429,   435,   436,   438,   440,   442,   444,   446,   448,
     450,   452,   454,   456,   458,   461,   464,   467,   470,   473,
     476,   482,   483,   485,   487,   489,   491,   493,   495,   501,
     502,   504,   506,   508,   510,   512,   514,   520,   522,   524,
     525,   527,   142,   143,   144,   145,   146,   147,     0,   149,
     150,     0,   151,   152,   153,   154,     0,   155,   156,   157,
     158,   159,   160,   161,   162,   166,   167,   168,   169,   170,
     171,   172,     0,     0,     0,   173,   174,   175,   176,   594,
     177,   178,   179,   180,   181,   182,   183,   184,   142,   143,
     144,   145,   146,   147,     0,   149,     0,     0,   151,   152,
     153,   154,     0,   155,   156,   157,   158,   159,   160,   161,
     162,   224,   225,   226,   227,   228,   171,   229,     0,     0,
       0,     0,   230,   231,   232,     0,   233,   234,   235,   236,
     237,   238,   239,   240,   166,   167,   168,   169,   170,   171,
       0,     0,     0,     0,   173,   174,   175,   176,     0,   177,
     178,   179,   180,   181,   182,   183,   184,   142,   143,   144,
     145,   146,   147,     0,     0,     0,     0,   151,   152,   153,
     154,     0,   155,   156,   157,   158,   159,   160,   161,   162,
     142,   143,   144,   145,   146,   147,     0,     0,     0,     0,
       0,   152,   153,   154,     0,   155,   156,   157,   158,   159,
     160,   161,   162,   166,   167,   168,   169,   170,   171,     0,
       0,     0,     0,     0,   174,   175,   176,     0,   177,   178,
     179,   180,   181,   182,   183,   184,   224,   225,   226,   227,
     228,   171,     0,     0,     0,     0,     0,   230,   231,   232,
       0,   233,   234,   235,   236,   237,   238,   239,   240,   166,
     167,   168,   169,   170,   171,     0,     0,     0,     0,     0,
     174,     0,   176,     0,   177,   178,   179,   180,   181,   182,
     183,   184,   142,   143,   144,   145,   146,   147,     0,     0,
       0,     0,     0,   152,     0,     0,     0,   155,   156,   157,
     158,   159,   160,   161,   162,   166,   167,   168,   169,   170,
     171,     0,     0,     0,     0,     0,   174,     0,     0,     0,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,     0,     0,   192,   166,
     167,   168,   169,   170,   171,   193,   194,   195,   196,   197,
     198,     0,     0,     0,   177,   178,   179,   180,   181,   182,
     183,   184,   242,   243,   244,   245,   246,   247,   248,   185,
     186,   187,   188,   189,   190,     0,     0,     0,     0,   249,
     250,   251,   252,   253,   254,     0,   193,   194,   195,   196,
     197,   198,   142,   143,   144,   145,   146,   147,     0,     0,
     166,   167,   168,   169,   170,   171,     0,   155,   156,     0,
       0,   159,   160,   161,   162,   177,   178,     0,     0,   181,
     182,   183,   184,   242,   243,   244,   245,   246,   247,     0,
       0,     0,     0,     0,     0,   277,   278,   279,   280,   281,
     249,   250,   251,   252,   253,   254,   230,     0,   232,     0,
     233,   234,   277,   278,   279,   280,   281,   277,   278,   279,
     280,   281,     0,   230,     0,     0,     0,   233,   234,     0,
       0,     0,   233,   234
  };

  const short
   Parser ::yycheck_[] =
  {
       0,   302,    96,     0,   533,    73,     9,     9,     8,     9,
     103,    11,   105,     9,   107,     9,   109,     9,    18,    19,
      32,     3,    12,     0,   633,   634,    75,    11,    11,     9,
      75,     8,    32,    10,     9,    32,    10,    39,    11,     9,
      11,    18,     9,     3,     4,     5,     6,     7,     8,     9,
      40,    11,    12,     4,     5,    32,    16,    11,     9,    11,
      40,     9,   671,    63,    24,    16,    40,    42,    10,    29,
       9,    10,    75,    73,    56,     8,     9,    75,    29,    75,
     621,    75,   623,    75,    68,    68,    68,    69,    70,    71,
      72,    75,    92,    75,    94,    68,    96,    68,    40,    96,
      39,     0,     3,   103,    68,   105,   118,   107,    10,   109,
       3,    12,     9,   113,    68,    75,    68,     3,   118,    96,
      13,   118,    19,     3,    75,   125,    12,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   118,    21,    75,   685,   686,   675,    75,    25,   126,
     127,    22,    23,    32,    33,    32,    33,   157,   158,   215,
     701,    32,    33,   163,   164,   165,    68,    69,    70,    71,
      72,   712,   172,    75,   715,    21,    73,     3,     4,     5,
       6,     7,     8,     9,   641,    11,    32,    33,    10,     4,
      16,   191,     3,   287,     9,    92,   653,    94,    24,   199,
       3,    16,   270,    29,     3,     3,   103,   207,   105,    22,
     107,     3,   109,     3,    29,    13,   113,   674,   218,    32,
      33,   221,   222,    32,    33,   682,    32,    33,   125,   229,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,    68,    10,   302,   303,   248,    75,
      15,    16,    17,    18,    19,    20,   256,   257,   258,   259,
     260,   261,   262,    10,   264,   265,   266,   267,   268,     8,
     270,    10,    11,    12,    21,    22,    23,   289,    34,    35,
      36,    37,   282,    68,    10,    32,    33,   287,     3,   289,
     287,   291,   289,     4,     5,     6,     7,     8,     9,    14,
      11,    12,    32,    33,    11,    16,    10,    10,    32,    33,
     287,    40,   289,    24,    42,     4,     5,    40,    29,    13,
       9,   218,    59,    60,    63,    64,    22,    16,   328,    25,
     307,    75,   633,   634,    42,    62,    32,    33,     9,    78,
      29,    56,    68,    69,    70,    71,    72,    86,    87,    75,
      75,   328,    10,    68,    69,    70,    71,    72,    39,    12,
      75,    75,    10,    21,    75,    68,    69,    70,    71,    72,
     671,    41,    75,   270,    32,    33,    34,    35,    36,    37,
      10,    10,    17,    18,    19,   282,    15,    16,    17,    18,
      19,    20,     9,    40,   291,    13,    12,    26,    27,    28,
      12,    30,    31,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    12,    12,    12,   533,    32,    33,
      34,    35,    36,    37,    10,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,     9,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    40,   256,   257,   258,
     259,   260,   261,   262,    20,   264,   265,   266,   267,   268,
      17,    18,    19,    20,   534,   628,    20,    20,   277,   278,
     279,   280,   281,   611,    20,     4,     5,     6,     7,     8,
       9,    12,    11,    12,    10,     8,     3,    16,    12,     4,
       5,     6,     7,     8,     9,    24,    11,    12,    14,    75,
      29,    16,     3,    40,    59,    10,    10,   633,   634,    24,
      17,    18,    19,    20,    29,     3,    21,    10,    14,   328,
      15,    16,    17,    18,    19,    20,   652,    32,    33,    34,
      35,    36,    37,    42,    42,    30,    31,    22,    23,    42,
      25,   611,   624,     9,     9,   671,    75,    32,    33,   675,
     676,   621,   622,   623,   624,    10,   626,   624,   628,    40,
      75,     4,     5,     6,     7,     8,     9,   534,    11,    12,
      10,   676,   649,    16,   621,   127,   623,   624,     8,   649,
     650,    24,    17,    18,    19,    20,    29,     4,     5,     6,
       7,     8,     9,   652,    11,    12,   645,    -1,    -1,    16,
      -1,     4,     5,     6,     7,     8,     9,    24,    11,    -1,
      -1,    -1,    29,    16,    -1,   685,   686,    -1,    -1,    -1,
     690,    24,   692,    21,    22,    23,    29,   697,    -1,   699,
      -1,   701,    75,    -1,    32,    33,    -1,    21,   685,   686,
     710,    25,   712,    -1,   611,   715,    -1,    -1,    32,    33,
      34,    35,    36,    37,   701,    -1,    -1,    -1,    75,   626,
      -1,   628,    21,    -1,    -1,   712,    -1,    -1,   715,    -1,
      -1,    -1,    75,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,   649,   650,     8,    -1,    10,    11,    15,    16,
      17,    18,    19,    20,    -1,     0,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    25,    11,    34,    35,    36,
      37,    16,    32,    33,    34,    35,    36,    37,    -1,    24,
      -1,    -1,    -1,   690,    29,   692,    -1,    -1,    10,    -1,
     697,    -1,   699,    15,    16,    17,    18,    19,    -1,    63,
      64,     9,    -1,   710,    26,    27,    28,    -1,    30,    31,
      -1,    56,    57,    58,    78,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    39,    -1,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,     4,
       5,     6,     7,     8,     9,    15,    16,    17,    18,    19,
      20,    16,    34,    35,    36,    37,    26,    27,    28,    24,
      30,    31,    -1,   622,    29,    -1,    -1,    -1,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,    -1,
       8,    -1,    -1,    11,    15,    16,    17,    18,    19,    20,
     224,   225,   226,   227,   228,   229,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,   256,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,   267,   268,    63,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    -1,    -1,    14,
      -1,    16,    -1,    -1,    68,    69,    70,    71,    72,    24,
      10,    75,    -1,    -1,    29,    15,    16,    17,    18,    19,
      20,    21,    17,    18,    19,    20,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    56,    57,    58,   328,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    -1,    -1,    -1,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,    -1,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,    -1,     4,     5,     6,     7,
       8,     9,    10,    11,    17,    18,    19,    20,    16,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    29,    21,    22,    23,    -1,    25,    -1,    -1,    -1,
     248,    -1,    -1,    32,    33,    -1,    -1,    -1,   256,   257,
     258,   259,   260,   261,   262,    -1,   264,   265,   266,   267,
     268,    15,    16,    17,    18,    19,    20,    15,    16,    17,
      18,    19,    20,    -1,    -1,     8,     0,    75,    11,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    -1,    -1,
      -1,    -1,    16,    15,    16,    17,    18,    19,    20,    -1,
      24,    -1,    -1,    -1,    -1,    29,    -1,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
     328,    14,    -1,    16,    32,    33,    34,    35,    36,    37,
      63,    24,    56,    57,    58,    -1,    29,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    15,    16,    17,    18,    19,    20,    15,    16,
      17,    18,    19,    56,    57,    58,    -1,    -1,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    25,    26,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,   622,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,    -1,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    -1,    13,    -1,   229,    16,    -1,    15,
      16,    17,    18,    19,    20,    24,    -1,    -1,    -1,    25,
      29,    -1,    -1,    -1,    -1,   248,    32,    33,    34,    35,
      36,    37,    -1,   256,   257,   258,   259,   260,   261,   262,
      -1,   264,   265,   266,   267,   268,    -1,    56,    57,    58,
      -1,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    -1,    -1,    14,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    29,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    -1,    -1,   328,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    29,
      56,    57,    58,    -1,   622,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
      -1,    -1,    -1,    16,    -1,     4,     5,     6,     7,     8,
       9,    24,    -1,    10,    -1,    75,    29,    16,    15,    16,
      17,    18,    19,    20,    21,    24,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      37,    -1,    -1,    56,    57,    58,    -1,    -1,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     4,     5,     6,     7,     8,     9,     4,
       5,     6,     7,     8,     9,    16,    75,    -1,    -1,    -1,
      -1,    16,    -1,    24,    -1,    -1,    -1,    -1,    29,    24,
      -1,    -1,    -1,    -1,    29,     4,     5,     6,     7,     8,
       9,    15,    16,    17,    18,    19,    20,    16,    15,    16,
      17,    18,    19,    20,    -1,    24,    30,    31,    -1,    26,
      29,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,
      75,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,    -1,   164,   165,   166,   167,   168,   169,   170,
      -1,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    -1,    25,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    25,    26,    27,    28,   622,
      30,    31,    32,    33,    34,    35,    36,    37,    15,    16,
      17,    18,    19,    20,    -1,    22,    -1,    -1,    25,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    26,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    25,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    25,    15,
      16,    17,    18,    19,    20,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    15,    16,    17,    18,    19,    20,    21,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    37,    -1,    32,    33,    34,    35,
      36,    37,    15,    16,    17,    18,    19,    20,    -1,    -1,
      15,    16,    17,    18,    19,    20,    -1,    30,    31,    -1,
      -1,    34,    35,    36,    37,    30,    31,    -1,    -1,    34,
      35,    36,    37,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      32,    33,    34,    35,    36,    37,    26,    -1,    28,    -1,
      30,    31,    15,    16,    17,    18,    19,    15,    16,    17,
      18,    19,    -1,    26,    -1,    -1,    -1,    30,    31,    -1,
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
     108,   109,   110,   112,   113,   114,   115,   116,   117,   118,
     120,   122,     8,     9,    16,    75,   106,   110,   113,   114,
     115,   116,   117,     3,    12,   106,   107,   111,     9,   106,
     114,   115,   114,   115,   116,   117,     9,    16,   114,    75,
      75,    85,     9,     9,     9,     3,    13,    81,    82,    83,
     107,    75,    68,    11,    68,    11,    68,    11,    68,    11,
      68,    75,    75,    11,    68,   105,     0,     0,     1,    80,
       3,     3,     3,     3,     3,     9,    39,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     3,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    25,    26,    27,    28,    30,    31,    32,    33,    34,
      35,    36,    37,    21,    32,    33,    15,    16,    17,    18,
      19,    20,    21,    25,    26,    27,    28,    30,    31,    32,
      33,    34,    35,    36,    37,    15,    16,    17,    18,    19,
      20,    21,    25,    32,    33,    34,    35,    36,    37,    21,
      25,    32,    33,    34,    35,    36,    37,    21,    22,    23,
      25,    32,    33,    68,    68,     9,    75,    10,    11,    10,
      10,    32,    33,    10,    15,    16,    17,    18,    19,    21,
      26,    27,    28,    30,    31,    32,    33,    34,    35,    36,
      37,    10,    15,    16,    17,    18,    19,    20,    21,    32,
      33,    34,    35,    36,    37,    10,    21,    32,    33,    34,
      35,    36,    37,    10,    21,    22,    23,    32,    33,   111,
      40,     3,    12,   114,   115,   114,   114,    15,    16,    17,
      18,    19,    42,    40,   107,    75,   107,    13,    14,    79,
      62,    42,    12,   107,   121,    12,   121,    12,   121,    12,
     121,     3,    13,     9,    12,   107,   121,    39,    80,    10,
     104,   107,   106,   102,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,     9,   108,
     113,   114,   115,   116,   117,   108,   114,   115,   108,   114,
     115,   108,   114,   115,   108,   114,   115,   108,   114,   115,
     108,   114,   115,   116,   117,   108,   115,   117,   108,   117,
     108,   114,   115,   116,   117,   108,   114,   108,   114,   108,
     114,   108,   114,   108,   114,   108,   113,   114,   115,   116,
     117,   108,   113,   114,   115,   116,   117,   108,   114,   115,
     116,   108,   114,   115,   116,   108,   114,   115,   116,   108,
     114,   115,   116,   113,   114,   115,   116,   117,   108,   113,
     108,   113,   108,   114,   115,   108,   114,   115,   108,   114,
     115,   108,   114,   115,   108,   114,   115,   114,   115,   108,
     113,   114,   115,   116,   117,   108,   108,   114,   108,   114,
     108,   114,   108,   114,   108,   114,   108,   114,   108,   114,
     108,   114,   108,   114,   108,   114,   108,   114,   108,   114,
     115,   108,   114,   115,   108,   114,   115,   108,   114,   115,
     108,   114,   115,   108,   114,   115,   108,   113,   114,   115,
     116,   117,   108,   108,   115,   108,   115,   108,   115,   108,
     115,   108,   115,   108,   115,   108,   113,   114,   115,   116,
     117,   108,   108,   116,   108,   116,   108,   116,   108,   116,
     108,   116,   108,   116,   108,   113,   114,   115,   116,   117,
     108,   117,   108,   117,   108,   108,   117,   108,   117,    10,
      75,   119,   122,     9,    42,   107,     9,   113,   113,   114,
     115,   114,   115,   114,   115,   114,   115,   114,   115,   113,
     114,   115,   116,   117,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   115,   114,   115,   114,
     115,   114,   115,   114,   115,   114,   115,   113,   114,   115,
     116,   117,   115,   115,   115,   115,   115,   115,   113,   114,
     115,   116,   117,   116,   117,   116,   116,   116,   116,   116,
     113,   114,   115,   116,   117,   117,   117,   117,   117,     3,
      12,     3,   111,    12,   114,   114,   114,   114,   114,   107,
      75,    10,    41,    10,    79,    14,     9,   107,    40,    12,
      12,    12,    12,    13,     3,    14,    56,    95,    96,   100,
     122,    10,    98,    99,   122,    12,    12,   106,    10,    40,
      11,    10,    40,    10,    98,   107,     8,    12,   111,    83,
      75,   116,    83,    14,     3,   107,   121,    95,    95,    75,
      14,     3,    75,    82,    10,    40,    40,    75,   105,   104,
     119,    82,    10,    59,    92,    10,    10,     3,    10,    14,
      42,    95,    42,    82,    98,    99,   122,    42,    82,     9,
      59,    60,    93,    83,    83,   107,   107,    75,   107,   107,
       9,    83,    10,   107,    83,    10,    83
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
      98,    98,    98,    99,    99,   100,   101,   101,   101,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   103,   103,   104,   104,   105,   105,
     106,   106,   106,   106,   106,   107,   107,   107,   107,   108,
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
     108,   108,   108,   108,   108,   108,   108,   108,   108,   109,
     109,   109,   109,   110,   110,   110,   110,   110,   111,   111,
     111,   112,   112,   113,   113,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   118,   118,   119,   119,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   121,   121,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122
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
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     1,     3,     3,     4,
       1,     1,     2,     4,     3,     1,     1,     1,     1,     1,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
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
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     2,     3,     4,     4,     5,     1,     3,
       4,     1,     3,     1,     3,     1,     2,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     3,     1,     3,     4,     3,
       4,     3,     4,     3,     4,     3,     4,     3,     1,     3,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
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
  "set", "funcall", "callarglist", "select", "scope", "expr", "expr_var",
  "val", "matrix", "matvals", "expr_mat", "expr_none", "expr_int",
  "expr_float", "expr_str", "expr_bool", "funtype", "typelist", "mattype",
  "matsize", "type", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   180,   180,   181,   183,   184,   185,   189,   190,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   207,   208,   209,   210,   211,   214,   215,   219,   221,
     222,   226,   227,   228,   230,   231,   235,   236,   240,   243,
     247,   249,   250,   251,   253,   254,   258,   259,   260,   262,
     263,   264,   265,   267,   268,   269,   273,   274,   275,   276,
     278,   279,   280,   282,   283,   287,   291,   292,   293,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   315,   316,   318,   320,   328,   329,
     333,   334,   335,   336,   337,   341,   342,   343,   344,   347,
     348,   349,   351,   352,   353,   355,   356,   357,   358,   359,
     361,   362,   363,   364,   365,   367,   368,   369,   370,   371,
     373,   374,   375,   376,   377,   379,   380,   381,   382,   383,
     385,   386,   387,   389,   390,   391,   393,   394,   395,   396,
     397,   398,   399,   401,   402,   403,   404,   405,   406,   407,
     409,   410,   411,   412,   413,   414,   415,   417,   418,   419,
     420,   421,   422,   423,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   449,   450,   451,   453,
     454,   455,   457,   458,   459,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   471,   472,   473,   475,   476,   477,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   491,
     492,   493,   494,   498,   499,   500,   501,   502,   504,   505,
     506,   510,   511,   515,   516,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   553,   554,   555,   556,   557,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   621,   622,   624,   625,   629,   630,
     631,   632,   633,   634,   635,   636,   637,   638,   640,   641,
     645,   646,   647,   648,   649,   650,   651,   652,   653,   654,
     655,   656,   657,   658,   659
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
#line 2624 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"

#line 662 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    std::cerr << scanner->loc->begin.line << ":" << scanner->loc->begin.column << ": " << err_message << std::endl;
}
