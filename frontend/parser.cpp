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
  case 68: // expr_int: "int"
#line 291 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 787 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 69: // expr_int: "-" expr_int
#line 292 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 793 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 70: // expr_int: "(" expr_int ")"
#line 293 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 799 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 71: // expr_int: expr_int "*" expr_int
#line 294 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 805 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 72: // expr_int: expr_int "/" expr_int
#line 295 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 811 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 73: // expr_int: expr_int "%" expr_int
#line 296 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 817 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 74: // expr_int: expr_int "-" expr_int
#line 297 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 823 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 75: // expr_int: expr_int "+" expr_int
#line 298 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 829 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 76: // expr_int: expr_int "&" expr_int
#line 299 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 835 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 77: // expr_int: expr_int "|" expr_int
#line 300 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 841 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 78: // expr_int: expr_int "^" expr_int
#line 301 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 847 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 79: // expr_int: "~" expr_int
#line 302 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 853 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 80: // expr_int: expr_int "<<" expr_int
#line 303 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 859 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 81: // expr_int: expr_int ">>" expr_int
#line 304 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 865 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 82: // expr_float: "float"
#line 308 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 871 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 83: // expr_float: "-" expr_float
#line 309 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 877 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 84: // expr_float: "(" expr_float ")"
#line 310 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 883 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 85: // expr_float: expr_float "**" expr_float
#line 311 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 889 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 86: // expr_float: expr_float "**" expr_int
#line 312 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 895 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 87: // expr_float: expr_int "**" expr_float
#line 313 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 901 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 88: // expr_float: expr_float "*" expr_float
#line 314 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 907 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 89: // expr_float: expr_float "*" expr_int
#line 315 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 913 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 90: // expr_float: expr_int "*" expr_float
#line 316 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 919 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 91: // expr_float: expr_float "/" expr_float
#line 317 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 925 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 92: // expr_float: expr_float "/" expr_int
#line 318 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 931 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 93: // expr_float: expr_int "/" expr_float
#line 319 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 937 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 94: // expr_float: expr_float "%" expr_float
#line 320 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 943 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 95: // expr_float: expr_float "%" expr_int
#line 321 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 949 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 96: // expr_float: expr_int "%" expr_float
#line 322 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 955 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 97: // expr_float: expr_float "-" expr_float
#line 323 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 961 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 98: // expr_float: expr_float "-" expr_int
#line 324 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 967 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 99: // expr_float: expr_int "-" expr_float
#line 325 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 973 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 100: // expr_float: expr_float "+" expr_float
#line 326 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 979 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 101: // expr_float: expr_float "+" expr_int
#line 327 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 985 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 102: // expr_float: expr_int "+" expr_float
#line 328 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 991 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 103: // expr_str: "string"
#line 332 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 997 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 104: // expr_str: "(" expr_str ")"
#line 333 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 1003 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 105: // expr_str: expr_str "++" expr_str
#line 334 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 1009 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 106: // expr_str: expr_str "++" expr_int
#line 335 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 1015 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 107: // expr_str: expr_str "++" expr_float
#line 336 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 1021 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 108: // expr_str: expr_str "++" expr_bool
#line 337 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1027 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 109: // expr_str: expr_int "++" expr_str
#line 338 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 1033 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 110: // expr_str: expr_int "++" expr_int
#line 339 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 1039 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 111: // expr_str: expr_int "++" expr_float
#line 340 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 1045 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 112: // expr_str: expr_int "++" expr_bool
#line 341 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1051 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 113: // expr_str: expr_float "++" expr_str
#line 342 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 1057 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 114: // expr_str: expr_float "++" expr_int
#line 343 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 1063 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 115: // expr_str: expr_float "++" expr_float
#line 344 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 1069 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 116: // expr_str: expr_float "++" expr_bool
#line 345 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1075 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 117: // expr_str: expr_bool "++" expr_str
#line 346 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 1081 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 118: // expr_str: expr_bool "++" expr_int
#line 347 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 1087 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 119: // expr_str: expr_bool "++" expr_float
#line 348 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 1093 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 120: // expr_str: expr_bool "++" expr_bool
#line 349 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 1099 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 121: // expr_bool: "bool"
#line 353 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 1105 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 122: // expr_bool: "(" expr_bool ")"
#line 354 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 1111 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 123: // expr_bool: "not" expr_bool
#line 355 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 1117 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 124: // expr_bool: expr_bool "or" expr_bool
#line 356 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 1123 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 125: // expr_bool: expr_bool "and" expr_bool
#line 357 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 1129 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 126: // expr_bool: expr_bool "==" expr_bool
#line 358 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 1135 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 127: // expr_bool: expr_int "==" expr_int
#line 359 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 1141 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 128: // expr_bool: expr_float "==" expr_float
#line 360 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 1147 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 129: // expr_bool: expr_str "==" expr_str
#line 361 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 1153 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 130: // expr_bool: expr_bool "!=" expr_bool
#line 362 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 1159 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 131: // expr_bool: expr_int "!=" expr_int
#line 363 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 1165 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 132: // expr_bool: expr_float "!=" expr_float
#line 364 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 1171 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 133: // expr_bool: expr_str "!=" expr_str
#line 365 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 1177 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 134: // expr_bool: expr_int ">" expr_int
#line 366 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 1183 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 135: // expr_bool: expr_float ">" expr_float
#line 367 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 1189 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 136: // expr_bool: expr_str ">" expr_str
#line 368 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 1195 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 137: // expr_bool: expr_int "<" expr_int
#line 369 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 1201 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 138: // expr_bool: expr_float "<" expr_float
#line 370 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 1207 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 139: // expr_bool: expr_str "<" expr_str
#line 371 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 1213 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 140: // expr_bool: expr_int ">=" expr_int
#line 372 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 1219 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 141: // expr_bool: expr_float ">=" expr_float
#line 373 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 1225 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 142: // expr_bool: expr_str ">=" expr_str
#line 374 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 1231 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 143: // expr_bool: expr_int "<=" expr_int
#line 375 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 1237 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 144: // expr_bool: expr_float "<=" expr_float
#line 376 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 1243 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"
    break;

  case 145: // expr_bool: expr_str "<=" expr_str
#line 377 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"
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


  const signed char  Parser ::yypact_ninf_ = -118;

  const short  Parser ::yytable_ninf_ = -155;

  const short
   Parser ::yypact_[] =
  {
     336,  -118,  -118,  -118,  -118,  -118,  -118,    28,   295,    28,
     309,   -46,    13,    33,    44,   505,  -118,  -118,  -118,  -118,
      58,    29,   278,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,   -22,    -1,  -118,   712,   735,   375,   149,
    -118,    -6,   670,   158,   219,   225,   295,  -118,  -118,   712,
     735,   375,  -118,   309,   309,  -118,  -118,    22,   429,    -7,
     429,    55,   563,   130,  -118,    88,   429,  -118,  -118,  -118,
     593,  -118,   366,    77,   429,   295,   295,   295,   295,   295,
     295,    28,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   295,   295,   295,   295,   295,   295,    28,
     295,   295,   295,   295,   295,   295,    28,    28,    28,    28,
      28,    28,    28,    28,    28,    28,    28,    28,     9,    98,
    -118,  -118,  -118,  -118,   763,   565,   782,  -118,   309,   309,
     309,   309,   309,    80,   132,   143,  -118,     7,  -118,   139,
     189,   593,  -118,   417,  -118,   223,   233,     7,  -118,  -118,
    -118,    -2,   250,   222,   224,     7,  -118,   256,     7,  -118,
     386,   430,   386,   430,   258,   261,   258,   261,   258,   261,
     645,   261,   799,   349,  -118,  -118,   744,   477,   822,   105,
     105,   805,   805,   805,   805,   805,   805,   837,   430,   837,
     430,     1,   261,     1,   261,     1,   261,     1,   261,   799,
     349,  -118,  -118,   697,   697,   697,   697,   697,   697,   799,
     349,  -118,  -118,   115,   149,   115,   267,   267,   267,   267,
     799,   349,  -118,  -118,   299,   217,   269,   269,  -118,  -118,
     281,     5,   535,    30,    30,  -118,  -118,  -118,  -118,   505,
     623,   505,   475,   291,   429,   132,   429,  -118,   650,   235,
    -118,   300,  -118,  -118,   251,   289,   689,  -118,   302,  -118,
     293,  -118,     7,  -118,  -118,   268,   224,  -118,   303,    14,
     505,   505,  -118,  -118,   429,   304,   505,  -118,  -118,  -118,
     305,   429,  -118,   505,   306,  -118,   505,  -118
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
       0,     2,     7,    68,    82,   103,   121,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   150,   151,   152,   153,
      60,     0,     0,     4,     8,    13,    14,    16,    17,    15,
      11,    12,     9,    18,     0,    10,    64,    65,    66,    67,
     155,     0,     0,     0,     0,     0,     0,    69,    83,     0,
       0,     0,   123,     0,     0,    79,    27,    26,     0,     0,
       0,     0,     0,     0,    25,     0,     0,    62,     1,     3,
       0,     5,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    41,
      70,    84,   104,   122,     0,     0,     0,    69,     0,     0,
       0,     0,     0,     0,    60,     0,    61,    29,    30,     0,
       0,     0,    19,     0,    24,     0,     0,    57,    56,     6,
      46,    60,     0,    48,    49,    52,    51,    63,    45,    44,
      75,   102,    74,    99,    71,    90,    72,    93,    73,    96,
       0,    87,   110,   111,   109,   112,    76,    77,    78,    80,
      81,   127,   131,   134,   137,   140,   143,   101,   100,    98,
      97,    89,    88,    92,    91,    95,    94,    86,    85,   114,
     115,   113,   116,   128,   132,   135,   138,   141,   144,   106,
     107,   105,   108,   129,     0,   133,   136,   139,   142,   145,
     118,   119,   117,   120,   125,   124,   126,   130,   147,   154,
       0,   148,     0,    75,    74,    71,    72,    73,    28,     0,
       0,     0,     0,    20,     0,    58,     0,    47,     0,     0,
     146,     0,    42,    43,    38,     0,     0,    33,    21,    22,
       0,    59,    54,    53,    50,     0,    55,   149,     0,    40,
       0,     0,    23,    34,     0,     0,     0,    35,    31,    32,
       0,     0,    39,     0,     0,    36,     0,    37
  };

  const short
   Parser ::yypgoto_[] =
  {
    -118,  -118,   -24,   -12,     0,  -118,    21,  -118,  -118,   -48,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,   -49,
      60,  -118,    79,  -118,    84,    72,   169,    -4,   107,    48,
     159,  -118,    94,  -117
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    21,    22,    23,    63,    64,    65,    25,    57,   135,
      26,    27,    28,    29,   269,   277,    30,    31,    32,    33,
     152,   153,   154,   146,    67,    34,    35,    36,    37,    38,
      39,    40,   230,    41
  };

  const short
   Parser ::yytable_[] =
  {
      24,   231,   118,    42,    47,    49,    55,    72,    66,   136,
      71,   136,   140,   118,    56,    72,   -61,   136,   228,   -61,
      80,    58,    24,   136,   136,   136,    82,    83,    84,    68,
      85,    86,     3,     4,     5,     6,     7,    73,   143,   246,
      74,    59,   124,     8,   251,    73,   130,   131,   132,   126,
     127,     9,    60,   139,   119,    44,    10,    51,   149,   275,
     276,   133,    24,    16,    17,    18,    19,   141,    66,   229,
      24,   160,   162,   164,   166,   168,   170,   172,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     189,   191,   193,   195,   197,   199,   170,   170,   170,   170,
     170,   170,   209,    49,    49,    49,    49,    49,    49,   220,
      49,    49,    49,    49,    43,    48,    50,   242,  -154,   128,
     129,   130,   131,   132,   233,   234,   235,   236,   237,   174,
     137,    71,   137,   144,   231,   106,   145,   134,   147,   232,
     238,    24,    66,    24,   155,   157,   158,   201,   109,   110,
     111,   112,   239,   125,   211,   213,   215,   216,   217,   218,
     219,   222,    51,    51,    51,    51,    45,   121,    52,   113,
     114,   115,    93,    94,    95,    96,    97,    98,    99,   240,
     116,   117,   161,   163,   165,   167,   169,   171,   173,   100,
     101,   102,   103,   104,   105,   136,   260,   136,   241,   136,
     188,   190,   192,   194,   196,   198,   200,   203,   204,   205,
     206,   207,   208,   210,    50,    50,    50,    50,    50,    50,
     221,    50,    50,    50,    50,   136,   280,   138,   122,   138,
      71,   244,   136,   284,   123,   148,    49,   113,   114,   106,
     175,   156,    24,   159,   245,   113,   114,   115,   116,   117,
     107,   108,   109,   110,   111,   112,   116,   117,   202,   247,
     254,   248,   257,   249,    72,   212,   214,   214,   214,   214,
     214,   214,   223,   224,   225,   226,   227,    80,    69,    70,
      98,     2,     3,     4,     5,     6,     7,   106,   256,   113,
     250,   278,   279,     8,   259,   265,   268,   282,   270,     3,
       4,     9,   273,    46,   285,   272,    10,   287,   264,   246,
       8,   274,   281,     3,   283,   286,   137,    53,   262,   113,
     155,    11,    12,    10,    54,    13,    14,    15,   266,   261,
     116,   117,    16,    17,    18,    19,     1,    10,    20,     2,
       3,     4,     5,     6,     7,   267,   137,    50,     0,     0,
       0,     8,     0,   137,    16,    17,    18,    19,     0,     9,
     229,     0,     0,    93,    10,    95,    96,    97,    98,     0,
       3,     4,     5,     6,     7,   150,     0,     0,     0,    11,
      12,     8,     0,    13,    14,    15,     0,     0,     0,     9,
      16,    17,    18,    19,    10,   106,    20,     0,     0,   214,
       0,   253,    77,    78,    79,    80,   107,   108,   109,   110,
     111,   112,     0,   138,     0,   263,     0,   156,    70,     0,
       2,     3,     4,     5,     6,     7,   151,     0,     0,     0,
     243,     0,     8,     3,     4,     5,     6,     7,     0,     0,
       9,     0,     0,   138,     8,    10,    95,    96,    97,    98,
     138,     0,     9,     0,     0,     0,     0,    10,     0,     0,
      11,    12,     0,     0,    13,    14,    15,     0,     0,     0,
       0,    16,    17,    18,    19,     0,    70,    20,     2,     3,
       4,     5,     6,     7,     0,     0,     0,     0,   258,   134,
       8,   128,   129,   130,   131,   132,     0,     0,     9,     0,
       0,     0,    82,    10,    84,     0,    85,    86,    61,     3,
       4,     5,     6,     7,     0,     0,     0,    62,    11,    12,
       8,     0,    13,    14,    15,     0,     0,     0,     9,    16,
      17,    18,    19,    10,     0,    20,     0,     0,     0,     3,
       4,     5,     6,     7,     0,     0,     0,     0,    11,    12,
       8,     0,    13,    14,    15,     0,     0,     0,     9,    16,
      17,    18,    19,    10,     0,    20,     2,     3,     4,     5,
       6,     7,     0,     0,   121,     0,   142,     0,     8,    93,
      94,    95,    96,    97,    98,     0,     9,     0,     0,     0,
       0,    10,     0,     0,     0,   252,     2,     3,     4,     5,
       6,     7,     0,     0,     0,     0,    11,    12,     8,     0,
      13,    14,    15,     0,     0,     0,     9,    16,    17,    18,
      19,    10,     0,    20,     0,     0,     0,     3,     4,     5,
       6,     7,     0,     0,     0,     0,    11,    12,     8,     0,
      13,    14,    15,     0,     0,     0,     9,    16,    17,    18,
      19,    10,     0,    20,     3,     4,     5,     6,     7,    75,
      76,    77,    78,    79,    80,     8,     0,     0,     0,     0,
      82,    83,    84,     9,    85,    86,     0,     0,    10,   120,
       0,     0,     0,   255,    75,    76,    77,    78,    79,    80,
      81,     0,     0,     0,     0,    82,    83,    84,   271,    85,
      86,    87,    88,    89,    90,    91,    92,     0,     0,   106,
     151,    93,    94,    95,    96,    97,    98,     0,     0,     0,
     107,   108,   109,   110,   111,   112,    75,    76,    77,    78,
      79,    80,    81,     0,     0,     0,     0,    82,    83,    84,
       0,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,     0,     0,   128,   129,
     130,   131,   132,     0,     0,     0,   100,   101,   102,   103,
     104,   105,   120,    85,    86,     0,     0,    75,    76,    77,
      78,    79,    80,     0,     0,     0,     0,     0,    82,    83,
      84,   120,    85,    86,     0,     0,   128,   129,   130,   131,
     132,     0,     0,     0,     0,     0,     0,    82,    83,    84,
       0,    85,    86,    75,     0,    77,    78,    79,    80,   128,
     129,   130,   131,   132,    82,    83,    84,     0,    85,    86,
      82,    83,    84,     0,    85,    86,   128,   129,   130,   131,
     132,     0,     0,     0,     0,     0,     0,    82,     0,     0,
       0,    85,    86,    77,    78,    79,    80,     0,     0,     0,
       0,     0,    82,    83,    84,     0,    85,    86
  };

  const short
   Parser ::yycheck_[] =
  {
       0,   118,     8,     7,     8,     9,    10,     8,    10,    58,
      22,    60,    60,     8,    60,     8,    38,    66,     9,    41,
      19,     8,    22,    72,    73,    74,    25,    26,    27,     0,
      29,    30,     4,     5,     6,     7,     8,    38,    62,    41,
      41,     8,    46,    15,    39,    38,    16,    17,    18,    53,
      54,    23,     8,    60,    60,     7,    28,     9,    70,    45,
      46,    39,    62,    54,    55,    56,    57,    12,    10,    60,
      70,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,     7,     8,     9,   141,    60,    14,
      15,    16,    17,    18,   128,   129,   130,   131,   132,    81,
      58,   143,    60,     3,   251,    20,    48,    60,    66,    41,
      60,   141,    10,   143,    72,    73,    74,    99,    33,    34,
      35,    36,     9,    46,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,     7,     9,     9,    20,
      21,    22,    14,    15,    16,    17,    18,    19,    20,    40,
      31,    32,    75,    76,    77,    78,    79,    80,    81,    31,
      32,    33,    34,    35,    36,   244,   244,   246,     9,   248,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   274,   274,    58,     9,    60,
     242,     8,   281,   281,     9,    66,   240,    20,    21,    20,
      81,    72,   242,    74,    11,    20,    21,    22,    31,    32,
      31,    32,    33,    34,    35,    36,    31,    32,    99,     9,
     239,    39,   241,    39,     8,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    19,     0,     1,
      19,     3,     4,     5,     6,     7,     8,    20,   240,    20,
       9,   270,   271,    15,     3,    60,    45,   276,     9,     4,
       5,    23,     9,     8,   283,     3,    28,   286,   248,    41,
      15,     8,     8,     4,     9,     9,   244,     8,   246,    20,
     248,    43,    44,    28,    15,    47,    48,    49,   249,   245,
      31,    32,    54,    55,    56,    57,     0,    28,    60,     3,
       4,     5,     6,     7,     8,   251,   274,   240,    -1,    -1,
      -1,    15,    -1,   281,    54,    55,    56,    57,    -1,    23,
      60,    -1,    -1,    14,    28,    16,    17,    18,    19,    -1,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    43,
      44,    15,    -1,    47,    48,    49,    -1,    -1,    -1,    23,
      54,    55,    56,    57,    28,    20,    60,    -1,    -1,   240,
      -1,   232,    16,    17,    18,    19,    31,    32,    33,    34,
      35,    36,    -1,   244,    -1,   246,    -1,   248,     1,    -1,
       3,     4,     5,     6,     7,     8,    60,    -1,    -1,    -1,
      13,    -1,    15,     4,     5,     6,     7,     8,    -1,    -1,
      23,    -1,    -1,   274,    15,    28,    16,    17,    18,    19,
     281,    -1,    23,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      43,    44,    -1,    -1,    47,    48,    49,    -1,    -1,    -1,
      -1,    54,    55,    56,    57,    -1,     1,    60,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,    13,    60,
      15,    14,    15,    16,    17,    18,    -1,    -1,    23,    -1,
      -1,    -1,    25,    28,    27,    -1,    29,    30,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    43,    44,
      15,    -1,    47,    48,    49,    -1,    -1,    -1,    23,    54,
      55,    56,    57,    28,    -1,    60,    -1,    -1,    -1,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,    43,    44,
      15,    -1,    47,    48,    49,    -1,    -1,    -1,    23,    54,
      55,    56,    57,    28,    -1,    60,     3,     4,     5,     6,
       7,     8,    -1,    -1,     9,    -1,    13,    -1,    15,    14,
      15,    16,    17,    18,    19,    -1,    23,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    60,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,    43,    44,    15,    -1,
      47,    48,    49,    -1,    -1,    -1,    23,    54,    55,    56,
      57,    28,    -1,    60,    -1,    -1,    -1,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,    43,    44,    15,    -1,
      47,    48,    49,    -1,    -1,    -1,    23,    54,    55,    56,
      57,    28,    -1,    60,     4,     5,     6,     7,     8,    14,
      15,    16,    17,    18,    19,    15,    -1,    -1,    -1,    -1,
      25,    26,    27,    23,    29,    30,    -1,    -1,    28,     9,
      -1,    -1,    -1,    60,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    25,    26,    27,     9,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    20,
      60,    14,    15,    16,    17,    18,    19,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    14,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    25,    26,    27,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    36,     9,    29,    30,    -1,    -1,    14,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,    26,
      27,     9,    29,    30,    -1,    -1,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,
      -1,    29,    30,    14,    -1,    16,    17,    18,    19,    14,
      15,    16,    17,    18,    25,    26,    27,    -1,    29,    30,
      25,    26,    27,    -1,    29,    30,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    29,    30,    16,    17,    18,    19,    -1,    -1,    -1,
      -1,    -1,    25,    26,    27,    -1,    29,    30
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,     0,     3,     4,     5,     6,     7,     8,    15,    23,
      28,    43,    44,    47,    48,    49,    54,    55,    56,    57,
      60,    63,    64,    65,    66,    69,    72,    73,    74,    75,
      78,    79,    80,    81,    87,    88,    89,    90,    91,    92,
      93,    95,    89,    90,    91,    92,     8,    89,    90,    89,
      90,    91,    92,     8,    15,    89,    60,    70,     8,     8,
       8,     3,    12,    66,    67,    68,    10,    86,     0,     0,
       1,    65,     8,    38,    41,    14,    15,    16,    17,    18,
      19,    20,    25,    26,    27,    29,    30,    31,    32,    33,
      34,    35,    36,    14,    15,    16,    17,    18,    19,    20,
      31,    32,    33,    34,    35,    36,    20,    31,    32,    33,
      34,    35,    36,    20,    21,    22,    31,    32,     8,    60,
       9,     9,     9,     9,    89,    90,    89,    89,    14,    15,
      16,    17,    18,    39,    60,    71,    81,    87,    88,    60,
      71,    12,    13,    64,     3,    48,    85,    87,    88,    65,
       9,    60,    82,    83,    84,    87,    88,    87,    87,    88,
      89,    90,    89,    90,    89,    90,    89,    90,    89,    90,
      89,    90,    89,    90,    91,    92,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    90,    89,
      90,    89,    90,    89,    90,    89,    90,    89,    90,    89,
      90,    91,    92,    90,    90,    90,    90,    90,    90,    89,
      90,    91,    92,    91,    92,    91,    91,    91,    91,    91,
      89,    90,    91,    92,    92,    92,    92,    92,     9,    60,
      94,    95,    41,    89,    89,    89,    89,    89,    60,     9,
      40,     9,    64,    13,     8,    11,    41,     9,    39,    39,
       9,    39,    60,    88,    68,    60,    91,    68,    13,     3,
      71,    86,    87,    88,    82,    60,    84,    94,    45,    76,
       9,     9,     3,     9,     8,    45,    46,    77,    68,    68,
      71,     8,    68,     9,    71,    68,     9,    68
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    62,    63,    63,    64,    64,    64,    65,    65,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    67,
      67,    67,    67,    67,    68,    68,    69,    70,    70,    71,
      71,    72,    72,    73,    74,    75,    76,    76,    76,    77,
      77,    78,    79,    79,    80,    80,    81,    81,    82,    82,
      82,    83,    83,    84,    84,    84,    85,    85,    86,    86,
      87,    87,    87,    87,    88,    88,    88,    88,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    93,    93,    94,    94,
      95,    95,    95,    95,    95,    95
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     1,     2,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     4,     4,     5,     2,     1,     2,     1,     3,     1,
       1,     7,     7,     5,     6,     7,     5,     6,     0,     2,
       0,     2,     4,     4,     3,     3,     3,     4,     1,     1,
       3,     1,     1,     3,     3,     3,     1,     1,     3,     4,
       1,     1,     2,     3,     1,     1,     1,     1,     1,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     1,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     3,     1,     3,
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
  "stmts", "stmts_ne", "block", "body", "import", "id_list", "cond", "for",
  "while", "dowhile", "if", "elif", "else", "vardecl", "vardef", "set",
  "funcall", "callarglist", "callarg", "callargnamed", "index", "select",
  "scope", "val", "expr_int", "expr_float", "expr_str", "expr_bool",
  "funtype", "typelist", "type", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   167,   167,   168,   170,   171,   172,   176,   177,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   192,
     193,   194,   195,   196,   199,   200,   204,   206,   207,   211,
     212,   216,   217,   221,   224,   228,   230,   231,   232,   234,
     235,   239,   243,   244,   248,   249,   253,   254,   256,   257,
     258,   260,   261,   263,   264,   265,   269,   270,   273,   274,
     277,   278,   279,   280,   284,   285,   286,   287,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   381,   382,   385,   386,
     390,   391,   392,   393,   394,   395
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
#line 2087 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.cpp"

#line 398 "/home/marek/Desktop/Programming/proto-typed/frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    std::cerr << scanner->loc->begin.line << ":" << scanner->loc->begin.column << ": " << err_message << std::endl;
}
