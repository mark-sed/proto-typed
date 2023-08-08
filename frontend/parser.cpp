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
#line 46 "frontend/parser.yy"


    #include <cmath>
    #include <sstream>
    #include <vector>
    #include "scanner.hpp"
    #include "logging.hpp"
    #include "ir.hpp"
    #include "diagnostics.def"

    // Set correct token method
    #undef yylex
    #define yylex scanner->yylex

#line 61 "frontend/parser.cpp"


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

#line 14 "frontend/parser.yy"
namespace  ptc  {
#line 154 "frontend/parser.cpp"

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

      case symbol_kind::S_set: // set
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_var: // expr_var
        value.copy< ptc::ir::Expr * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmts_ne: // stmts_ne
      case symbol_kind::S_import: // import
      case symbol_kind::S_flowctl: // flowctl
      case symbol_kind::S_return: // return
      case symbol_kind::S_while: // while
      case symbol_kind::S_if: // if
      case symbol_kind::S_struct: // struct
      case symbol_kind::S_declistval: // declistval
      case symbol_kind::S_function: // function
      case symbol_kind::S_vardecl: // vardecl
      case symbol_kind::S_vardef: // vardef
      case symbol_kind::S_type: // type
        value.copy< ptc::ir::IR * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_EXT_ID: // "external identifier"
      case symbol_kind::S_fun_id: // fun_id
      case symbol_kind::S_expr_str: // expr_str
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_callarglist: // callarglist
        value.copy< std::vector<ptc::ir::Expr *>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_funargs: // funargs
        value.copy< std::vector<ptc::ir::FormalParamDecl *>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_block: // block
      case symbol_kind::S_body: // body
      case symbol_kind::S_else: // else
      case symbol_kind::S_decllist: // decllist
        value.copy< std::vector<ptc::ir::IR *>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_id_list: // id_list
        value.copy< std::vector<std::string>  > (YY_MOVE (that.value));
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

      case symbol_kind::S_set: // set
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_var: // expr_var
        value.move< ptc::ir::Expr * > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmts_ne: // stmts_ne
      case symbol_kind::S_import: // import
      case symbol_kind::S_flowctl: // flowctl
      case symbol_kind::S_return: // return
      case symbol_kind::S_while: // while
      case symbol_kind::S_if: // if
      case symbol_kind::S_struct: // struct
      case symbol_kind::S_declistval: // declistval
      case symbol_kind::S_function: // function
      case symbol_kind::S_vardecl: // vardecl
      case symbol_kind::S_vardef: // vardef
      case symbol_kind::S_type: // type
        value.move< ptc::ir::IR * > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_EXT_ID: // "external identifier"
      case symbol_kind::S_fun_id: // fun_id
      case symbol_kind::S_expr_str: // expr_str
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_callarglist: // callarglist
        value.move< std::vector<ptc::ir::Expr *>  > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_funargs: // funargs
        value.move< std::vector<ptc::ir::FormalParamDecl *>  > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_block: // block
      case symbol_kind::S_body: // body
      case symbol_kind::S_else: // else
      case symbol_kind::S_decllist: // decllist
        value.move< std::vector<ptc::ir::IR *>  > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_id_list: // id_list
        value.move< std::vector<std::string>  > (YY_MOVE (s.value));
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

      case symbol_kind::S_set: // set
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_var: // expr_var
        value.YY_MOVE_OR_COPY< ptc::ir::Expr * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmts_ne: // stmts_ne
      case symbol_kind::S_import: // import
      case symbol_kind::S_flowctl: // flowctl
      case symbol_kind::S_return: // return
      case symbol_kind::S_while: // while
      case symbol_kind::S_if: // if
      case symbol_kind::S_struct: // struct
      case symbol_kind::S_declistval: // declistval
      case symbol_kind::S_function: // function
      case symbol_kind::S_vardecl: // vardecl
      case symbol_kind::S_vardef: // vardef
      case symbol_kind::S_type: // type
        value.YY_MOVE_OR_COPY< ptc::ir::IR * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_EXT_ID: // "external identifier"
      case symbol_kind::S_fun_id: // fun_id
      case symbol_kind::S_expr_str: // expr_str
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_callarglist: // callarglist
        value.YY_MOVE_OR_COPY< std::vector<ptc::ir::Expr *>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_funargs: // funargs
        value.YY_MOVE_OR_COPY< std::vector<ptc::ir::FormalParamDecl *>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_block: // block
      case symbol_kind::S_body: // body
      case symbol_kind::S_else: // else
      case symbol_kind::S_decllist: // decllist
        value.YY_MOVE_OR_COPY< std::vector<ptc::ir::IR *>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_id_list: // id_list
        value.YY_MOVE_OR_COPY< std::vector<std::string>  > (YY_MOVE (that.value));
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

      case symbol_kind::S_set: // set
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_var: // expr_var
        value.move< ptc::ir::Expr * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmts_ne: // stmts_ne
      case symbol_kind::S_import: // import
      case symbol_kind::S_flowctl: // flowctl
      case symbol_kind::S_return: // return
      case symbol_kind::S_while: // while
      case symbol_kind::S_if: // if
      case symbol_kind::S_struct: // struct
      case symbol_kind::S_declistval: // declistval
      case symbol_kind::S_function: // function
      case symbol_kind::S_vardecl: // vardecl
      case symbol_kind::S_vardef: // vardef
      case symbol_kind::S_type: // type
        value.move< ptc::ir::IR * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_EXT_ID: // "external identifier"
      case symbol_kind::S_fun_id: // fun_id
      case symbol_kind::S_expr_str: // expr_str
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_callarglist: // callarglist
        value.move< std::vector<ptc::ir::Expr *>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_funargs: // funargs
        value.move< std::vector<ptc::ir::FormalParamDecl *>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_block: // block
      case symbol_kind::S_body: // body
      case symbol_kind::S_else: // else
      case symbol_kind::S_decllist: // decllist
        value.move< std::vector<ptc::ir::IR *>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_id_list: // id_list
        value.move< std::vector<std::string>  > (YY_MOVE (that.value));
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

      case symbol_kind::S_set: // set
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_var: // expr_var
        value.copy< ptc::ir::Expr * > (that.value);
        break;

      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmts_ne: // stmts_ne
      case symbol_kind::S_import: // import
      case symbol_kind::S_flowctl: // flowctl
      case symbol_kind::S_return: // return
      case symbol_kind::S_while: // while
      case symbol_kind::S_if: // if
      case symbol_kind::S_struct: // struct
      case symbol_kind::S_declistval: // declistval
      case symbol_kind::S_function: // function
      case symbol_kind::S_vardecl: // vardecl
      case symbol_kind::S_vardef: // vardef
      case symbol_kind::S_type: // type
        value.copy< ptc::ir::IR * > (that.value);
        break;

      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_EXT_ID: // "external identifier"
      case symbol_kind::S_fun_id: // fun_id
      case symbol_kind::S_expr_str: // expr_str
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_callarglist: // callarglist
        value.copy< std::vector<ptc::ir::Expr *>  > (that.value);
        break;

      case symbol_kind::S_funargs: // funargs
        value.copy< std::vector<ptc::ir::FormalParamDecl *>  > (that.value);
        break;

      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_block: // block
      case symbol_kind::S_body: // body
      case symbol_kind::S_else: // else
      case symbol_kind::S_decllist: // decllist
        value.copy< std::vector<ptc::ir::IR *>  > (that.value);
        break;

      case symbol_kind::S_id_list: // id_list
        value.copy< std::vector<std::string>  > (that.value);
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

      case symbol_kind::S_set: // set
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_var: // expr_var
        value.move< ptc::ir::Expr * > (that.value);
        break;

      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmts_ne: // stmts_ne
      case symbol_kind::S_import: // import
      case symbol_kind::S_flowctl: // flowctl
      case symbol_kind::S_return: // return
      case symbol_kind::S_while: // while
      case symbol_kind::S_if: // if
      case symbol_kind::S_struct: // struct
      case symbol_kind::S_declistval: // declistval
      case symbol_kind::S_function: // function
      case symbol_kind::S_vardecl: // vardecl
      case symbol_kind::S_vardef: // vardef
      case symbol_kind::S_type: // type
        value.move< ptc::ir::IR * > (that.value);
        break;

      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_EXT_ID: // "external identifier"
      case symbol_kind::S_fun_id: // fun_id
      case symbol_kind::S_expr_str: // expr_str
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_callarglist: // callarglist
        value.move< std::vector<ptc::ir::Expr *>  > (that.value);
        break;

      case symbol_kind::S_funargs: // funargs
        value.move< std::vector<ptc::ir::FormalParamDecl *>  > (that.value);
        break;

      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_block: // block
      case symbol_kind::S_body: // body
      case symbol_kind::S_else: // else
      case symbol_kind::S_decllist: // decllist
        value.move< std::vector<ptc::ir::IR *>  > (that.value);
        break;

      case symbol_kind::S_id_list: // id_list
        value.move< std::vector<std::string>  > (that.value);
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

      case symbol_kind::S_set: // set
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_var: // expr_var
        yylhs.value.emplace< ptc::ir::Expr * > ();
        break;

      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmts_ne: // stmts_ne
      case symbol_kind::S_import: // import
      case symbol_kind::S_flowctl: // flowctl
      case symbol_kind::S_return: // return
      case symbol_kind::S_while: // while
      case symbol_kind::S_if: // if
      case symbol_kind::S_struct: // struct
      case symbol_kind::S_declistval: // declistval
      case symbol_kind::S_function: // function
      case symbol_kind::S_vardecl: // vardecl
      case symbol_kind::S_vardef: // vardef
      case symbol_kind::S_type: // type
        yylhs.value.emplace< ptc::ir::IR * > ();
        break;

      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_EXT_ID: // "external identifier"
      case symbol_kind::S_fun_id: // fun_id
      case symbol_kind::S_expr_str: // expr_str
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_callarglist: // callarglist
        yylhs.value.emplace< std::vector<ptc::ir::Expr *>  > ();
        break;

      case symbol_kind::S_funargs: // funargs
        yylhs.value.emplace< std::vector<ptc::ir::FormalParamDecl *>  > ();
        break;

      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_block: // block
      case symbol_kind::S_body: // body
      case symbol_kind::S_else: // else
      case symbol_kind::S_decllist: // decllist
        yylhs.value.emplace< std::vector<ptc::ir::IR *>  > ();
        break;

      case symbol_kind::S_id_list: // id_list
        yylhs.value.emplace< std::vector<std::string>  > ();
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
  case 3: // start: stmt "end of file"
#line 219 "frontend/parser.yy"
                        { scanner->parseEntry(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1098 "frontend/parser.cpp"
    break;

  case 4: // stmt: stmts
#line 221 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1104 "frontend/parser.cpp"
    break;

  case 5: // stmt: stmt stmts
#line 222 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1110 "frontend/parser.cpp"
    break;

  case 6: // stmt: stmt error stmts
#line 223 "frontend/parser.yy"
                        { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBodyAdd(yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1116 "frontend/parser.cpp"
    break;

  case 7: // stmts: "terminator (\\n or ;)"
#line 227 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = nullptr; }
#line 1122 "frontend/parser.cpp"
    break;

  case 8: // stmts: stmts_ne
#line 228 "frontend/parser.yy"
                 { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1128 "frontend/parser.cpp"
    break;

  case 9: // stmts_ne: set "terminator (\\n or ;)"
#line 230 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1134 "frontend/parser.cpp"
    break;

  case 10: // stmts_ne: vardecl "terminator (\\n or ;)"
#line 231 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1140 "frontend/parser.cpp"
    break;

  case 11: // stmts_ne: vardef "terminator (\\n or ;)"
#line 232 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1146 "frontend/parser.cpp"
    break;

  case 12: // stmts_ne: import "terminator (\\n or ;)"
#line 233 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1152 "frontend/parser.cpp"
    break;

  case 14: // stmts_ne: if
#line 235 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1158 "frontend/parser.cpp"
    break;

  case 15: // stmts_ne: while
#line 236 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1164 "frontend/parser.cpp"
    break;

  case 17: // stmts_ne: struct
#line 238 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1170 "frontend/parser.cpp"
    break;

  case 18: // stmts_ne: function
#line 239 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1176 "frontend/parser.cpp"
    break;

  case 19: // stmts_ne: flowctl "terminator (\\n or ;)"
#line 240 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[1].value.as < ptc::ir::IR * > (); }
#line 1182 "frontend/parser.cpp"
    break;

  case 20: // stmts_ne: expr "terminator (\\n or ;)"
#line 241 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseExprStmt(yystack_[1].value.as < ptc::ir::Expr * > ()); }
#line 1188 "frontend/parser.cpp"
    break;

  case 21: // block: "{" "}"
#line 245 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1194 "frontend/parser.cpp"
    break;

  case 22: // block: "{" stmt "}"
#line 246 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1200 "frontend/parser.cpp"
    break;

  case 23: // block: "terminator (\\n or ;)" "{" stmt "}"
#line 247 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1206 "frontend/parser.cpp"
    break;

  case 24: // block: "{" stmt "}" "terminator (\\n or ;)"
#line 248 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1212 "frontend/parser.cpp"
    break;

  case 25: // block: "terminator (\\n or ;)" "{" stmt "}" "terminator (\\n or ;)"
#line 249 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[2].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1218 "frontend/parser.cpp"
    break;

  case 26: // body: stmts_ne
#line 252 "frontend/parser.yy"
                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(yystack_[0].value.as < ptc::ir::IR * > ()); }
#line 1224 "frontend/parser.cpp"
    break;

  case 27: // body: block
#line 253 "frontend/parser.yy"
                { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1230 "frontend/parser.cpp"
    break;

  case 28: // import: "import" id_list
#line 257 "frontend/parser.yy"
                            { yylhs.value.as < ptc::ir::IR * > () = scanner->parseImports(yystack_[0].value.as < std::vector<std::string>  > ()); }
#line 1236 "frontend/parser.cpp"
    break;

  case 29: // id_list: "identifier"
#line 259 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseImportName(yystack_[0].value.as < std::string > ()); }
#line 1242 "frontend/parser.cpp"
    break;

  case 30: // id_list: "identifier" "," id_list
#line 260 "frontend/parser.yy"
                            { yylhs.value.as < std::vector<std::string>  > () = scanner->parseAddImportName(yystack_[0].value.as < std::vector<std::string>  > (), yystack_[2].value.as < std::string > ()); }
#line 1248 "frontend/parser.cpp"
    break;

  case 31: // flowctl: "break"
#line 264 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseBreak(); }
#line 1254 "frontend/parser.cpp"
    break;

  case 32: // flowctl: "continue"
#line 265 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseContinue(); }
#line 1260 "frontend/parser.cpp"
    break;

  case 33: // flowctl: return
#line 266 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = yystack_[0].value.as < ptc::ir::IR * > (); }
#line 1266 "frontend/parser.cpp"
    break;

  case 34: // return: "return"
#line 268 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(nullptr); }
#line 1272 "frontend/parser.cpp"
    break;

  case 35: // return: "return" expr
#line 269 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->parseReturn(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1278 "frontend/parser.cpp"
    break;

  case 37: // while: "while" "(" expr ")" body
#line 277 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::IR * > () = scanner->parseWhile(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1284 "frontend/parser.cpp"
    break;

  case 39: // if: "if" "(" expr ")" body else
#line 284 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::IR * > () = scanner->parseIfStmt(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1290 "frontend/parser.cpp"
    break;

  case 40: // else: "else" body
#line 290 "frontend/parser.yy"
                    { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1296 "frontend/parser.cpp"
    break;

  case 41: // else: %empty
#line 291 "frontend/parser.yy"
                    { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseStmtBody(nullptr); }
#line 1302 "frontend/parser.cpp"
    break;

  case 42: // struct: "'struct'" "identifier" "{" "}"
#line 295 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[2].value.as < std::string > (), std::vector<ptc::ir::IR *>{}); }
#line 1308 "frontend/parser.cpp"
    break;

  case 43: // struct: "'struct'" "identifier" "{" decllist "}"
#line 296 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1314 "frontend/parser.cpp"
    break;

  case 44: // struct: "'struct'" "identifier" "terminator (\\n or ;)" "{" decllist "}"
#line 297 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStruct(yystack_[4].value.as < std::string > (), yystack_[1].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1320 "frontend/parser.cpp"
    break;

  case 46: // decllist: "terminator (\\n or ;)" decllist
#line 300 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = yystack_[0].value.as < std::vector<ptc::ir::IR *>  > (); }
#line 1326 "frontend/parser.cpp"
    break;

  case 47: // decllist: declistval "terminator (\\n or ;)"
#line 301 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[1].value.as < ptc::ir::IR * > (), std::vector<ptc::ir::IR *>{}); }
#line 1332 "frontend/parser.cpp"
    break;

  case 48: // decllist: declistval "terminator (\\n or ;)" decllist
#line 302 "frontend/parser.yy"
                                   { yylhs.value.as < std::vector<ptc::ir::IR *>  > () = scanner->parseAddStructElement(yystack_[2].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1338 "frontend/parser.cpp"
    break;

  case 49: // declistval: type "identifier"
#line 304 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > (), nullptr); }
#line 1344 "frontend/parser.cpp"
    break;

  case 50: // declistval: type "identifier" "=" expr
#line 305 "frontend/parser.yy"
                                { yylhs.value.as < ptc::ir::IR * > () = scanner->parseStructElement(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1350 "frontend/parser.cpp"
    break;

  case 52: // function: type fun_id "(" ")" block
#line 310 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[4].value.as < ptc::ir::IR * > (), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1356 "frontend/parser.cpp"
    break;

  case 53: // function: type fun_id "(" funargs ")" block
#line 311 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(yystack_[5].value.as < ptc::ir::IR * > (), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1362 "frontend/parser.cpp"
    break;

  case 54: // function: "'void'" fun_id "(" ")" block
#line 312 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[3].value.as < std::string > (), std::vector<ptc::ir::FormalParamDecl *>{}, yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1368 "frontend/parser.cpp"
    break;

  case 55: // function: "'void'" fun_id "(" funargs ")" block
#line 313 "frontend/parser.yy"
                                                 { yylhs.value.as < ptc::ir::IR * > () = scanner->parseFun(scanner->sym_lookup("void"), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[0].value.as < std::vector<ptc::ir::IR *>  > ()); }
#line 1374 "frontend/parser.cpp"
    break;

  case 56: // fun_id: "identifier"
#line 315 "frontend/parser.yy"
            { scanner->enterFunScope(); yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1380 "frontend/parser.cpp"
    break;

  case 57: // funargs: type "identifier"
#line 317 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseFunParam(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1386 "frontend/parser.cpp"
    break;

  case 59: // funargs: funargs "," type "identifier"
#line 319 "frontend/parser.yy"
                                { yylhs.value.as < std::vector<ptc::ir::FormalParamDecl *>  > () = scanner->parseAddFunParam(yystack_[3].value.as < std::vector<ptc::ir::FormalParamDecl *>  > (), yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1392 "frontend/parser.cpp"
    break;

  case 62: // vardecl: type "identifier"
#line 326 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::IR * > () = scanner->parseVarDecl(yystack_[1].value.as < ptc::ir::IR * > (), yystack_[0].value.as < std::string > ()); }
#line 1398 "frontend/parser.cpp"
    break;

  case 63: // vardef: type "identifier" "=" struct_val
#line 330 "frontend/parser.yy"
         { yylhs.value.as < ptc::ir::IR * > () = yystack_[3].value.as < ptc::ir::IR * > (); }
#line 1404 "frontend/parser.cpp"
    break;

  case 64: // vardef: type "identifier" "=" expr
#line 331 "frontend/parser.yy"
                                 { scanner->parseVarDef(yystack_[3].value.as < ptc::ir::IR * > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1410 "frontend/parser.cpp"
    break;

  case 67: // set: expr "++=" expr
#line 337 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1416 "frontend/parser.cpp"
    break;

  case 68: // set: expr "**=" expr
#line 338 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_POW)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1422 "frontend/parser.cpp"
    break;

  case 69: // set: expr "%=" expr
#line 339 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1428 "frontend/parser.cpp"
    break;

  case 70: // set: expr "/=" expr
#line 340 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1434 "frontend/parser.cpp"
    break;

  case 71: // set: expr "*=" expr
#line 341 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1440 "frontend/parser.cpp"
    break;

  case 72: // set: expr "-=" expr
#line 342 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1446 "frontend/parser.cpp"
    break;

  case 73: // set: expr "+=" expr
#line 343 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1452 "frontend/parser.cpp"
    break;

  case 74: // set: expr "&=" expr
#line 344 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1458 "frontend/parser.cpp"
    break;

  case 75: // set: expr "|=" expr
#line 345 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1464 "frontend/parser.cpp"
    break;

  case 76: // set: expr "^=" expr
#line 346 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1470 "frontend/parser.cpp"
    break;

  case 77: // set: expr "<<=" expr
#line 347 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1476 "frontend/parser.cpp"
    break;

  case 78: // set: expr ">>=" expr
#line 348 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1482 "frontend/parser.cpp"
    break;

  case 79: // set: expr "=" expr
#line 349 "frontend/parser.yy"
                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ASSIGN)); }
#line 1488 "frontend/parser.cpp"
    break;

  case 80: // set: expr "=" set
#line 350 "frontend/parser.yy"
      { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1494 "frontend/parser.cpp"
    break;

  case 81: // callarglist: expr
#line 354 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseFunCallArg(yystack_[0].value.as < ptc::ir::Expr * > ()); }
#line 1500 "frontend/parser.cpp"
    break;

  case 82: // callarglist: expr "," callarglist
#line 355 "frontend/parser.yy"
                                      { yylhs.value.as < std::vector<ptc::ir::Expr *>  > () = scanner->parseAddFunCallArg(yystack_[0].value.as < std::vector<ptc::ir::Expr *>  > (), yystack_[2].value.as < ptc::ir::Expr * > ()); }
#line 1506 "frontend/parser.cpp"
    break;

  case 83: // expr: expr_mat
#line 359 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = nullptr; }
#line 1512 "frontend/parser.cpp"
    break;

  case 84: // expr: expr_var
#line 360 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = yystack_[0].value.as < ptc::ir::Expr * > (); }
#line 1518 "frontend/parser.cpp"
    break;

  case 85: // expr: expr_none
#line 361 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = nullptr; }
#line 1524 "frontend/parser.cpp"
    break;

  case 86: // expr: expr_struct
#line 362 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = nullptr; }
#line 1530 "frontend/parser.cpp"
    break;

  case 87: // expr: expr_int
#line 363 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInt(yystack_[0].value.as < long > ()); }
#line 1536 "frontend/parser.cpp"
    break;

  case 88: // expr: expr_float
#line 364 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFloat(yystack_[0].value.as < double > ()); }
#line 1542 "frontend/parser.cpp"
    break;

  case 89: // expr: expr_str
#line 365 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseString(yystack_[0].value.as < std::string > ()); }
#line 1548 "frontend/parser.cpp"
    break;

  case 90: // expr: expr_bool
#line 366 "frontend/parser.yy"
                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseBool(yystack_[0].value.as < bool > ()); }
#line 1554 "frontend/parser.cpp"
    break;

  case 91: // expr_var: "identifier"
#line 369 "frontend/parser.yy"
              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > ()); }
#line 1560 "frontend/parser.cpp"
    break;

  case 92: // expr_var: "external identifier"
#line 370 "frontend/parser.yy"
                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseVar(yystack_[0].value.as < std::string > (), true); }
#line 1566 "frontend/parser.cpp"
    break;

  case 93: // expr_var: "-" "identifier"
#line 371 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1572 "frontend/parser.cpp"
    break;

  case 94: // expr_var: "-" "external identifier"
#line 372 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(0), scanner->parseVar(yystack_[0].value.as < std::string > (), true), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1578 "frontend/parser.cpp"
    break;

  case 95: // expr_var: "(" expr_var ")"
#line 373 "frontend/parser.yy"
                              { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1584 "frontend/parser.cpp"
    break;

  case 96: // expr_var: expr_var "(" ")"
#line 375 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[2].value.as < ptc::ir::Expr * > (), std::vector<ptc::ir::Expr *>{}); }
#line 1590 "frontend/parser.cpp"
    break;

  case 97: // expr_var: expr_var "(" callarglist ")"
#line 376 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseFunCall(yystack_[3].value.as < ptc::ir::Expr * > (), yystack_[1].value.as < std::vector<ptc::ir::Expr *>  > ()); }
#line 1596 "frontend/parser.cpp"
    break;

  case 102: // expr_var: expr_var "[" int_val "]"
#line 382 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[3].value.as < ptc::ir::Expr * > (); }
#line 1602 "frontend/parser.cpp"
    break;

  case 106: // expr_var: expr_var slice
#line 387 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[1].value.as < ptc::ir::Expr * > (); }
#line 1608 "frontend/parser.cpp"
    break;

  case 109: // expr_var: expr_var "." expr_var
#line 391 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1614 "frontend/parser.cpp"
    break;

  case 111: // expr_var: expr_var "**" expr_float
#line 394 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1620 "frontend/parser.cpp"
    break;

  case 112: // expr_var: expr_var "**" expr_var
#line 395 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1626 "frontend/parser.cpp"
    break;

  case 113: // expr_var: expr_int "*" expr_var
#line 397 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1632 "frontend/parser.cpp"
    break;

  case 114: // expr_var: expr_float "*" expr_var
#line 398 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1638 "frontend/parser.cpp"
    break;

  case 115: // expr_var: expr_var "*" expr_int
#line 399 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1644 "frontend/parser.cpp"
    break;

  case 116: // expr_var: expr_var "*" expr_float
#line 400 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1650 "frontend/parser.cpp"
    break;

  case 119: // expr_var: expr_var "*" expr_mat
#line 403 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1656 "frontend/parser.cpp"
    break;

  case 120: // expr_var: expr_var "*" expr_var
#line 404 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MUL)); }
#line 1662 "frontend/parser.cpp"
    break;

  case 121: // expr_var: expr_int "/" expr_var
#line 406 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1668 "frontend/parser.cpp"
    break;

  case 122: // expr_var: expr_float "/" expr_var
#line 407 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1674 "frontend/parser.cpp"
    break;

  case 123: // expr_var: expr_var "/" expr_int
#line 408 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1680 "frontend/parser.cpp"
    break;

  case 124: // expr_var: expr_var "/" expr_float
#line 409 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1686 "frontend/parser.cpp"
    break;

  case 125: // expr_var: expr_var "/" expr_var
#line 410 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_DIV)); }
#line 1692 "frontend/parser.cpp"
    break;

  case 126: // expr_var: expr_int "%" expr_var
#line 412 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1698 "frontend/parser.cpp"
    break;

  case 127: // expr_var: expr_float "%" expr_var
#line 413 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1704 "frontend/parser.cpp"
    break;

  case 128: // expr_var: expr_var "%" expr_int
#line 414 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1710 "frontend/parser.cpp"
    break;

  case 129: // expr_var: expr_var "%" expr_float
#line 415 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1716 "frontend/parser.cpp"
    break;

  case 130: // expr_var: expr_var "%" expr_var
#line 416 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_MOD)); }
#line 1722 "frontend/parser.cpp"
    break;

  case 131: // expr_var: expr_int "+" expr_var
#line 418 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1728 "frontend/parser.cpp"
    break;

  case 132: // expr_var: expr_float "+" expr_var
#line 419 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1734 "frontend/parser.cpp"
    break;

  case 133: // expr_var: expr_var "+" expr_int
#line 420 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1740 "frontend/parser.cpp"
    break;

  case 134: // expr_var: expr_var "+" expr_float
#line 421 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1746 "frontend/parser.cpp"
    break;

  case 136: // expr_var: expr_var "+" expr_mat
#line 423 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1752 "frontend/parser.cpp"
    break;

  case 138: // expr_var: expr_var "+" expr_var
#line 425 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_ADD)); }
#line 1758 "frontend/parser.cpp"
    break;

  case 139: // expr_var: expr_int "-" expr_var
#line 427 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1764 "frontend/parser.cpp"
    break;

  case 140: // expr_var: expr_float "-" expr_var
#line 428 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1770 "frontend/parser.cpp"
    break;

  case 141: // expr_var: expr_var "-" expr_int
#line 429 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1776 "frontend/parser.cpp"
    break;

  case 142: // expr_var: expr_var "-" expr_float
#line 430 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1782 "frontend/parser.cpp"
    break;

  case 144: // expr_var: expr_var "-" expr_mat
#line 432 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1788 "frontend/parser.cpp"
    break;

  case 146: // expr_var: expr_var "-" expr_var
#line 434 "frontend/parser.yy"
                                     { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_SUB)); }
#line 1794 "frontend/parser.cpp"
    break;

  case 147: // expr_var: expr_int "<<" expr_var
#line 436 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 1800 "frontend/parser.cpp"
    break;

  case 148: // expr_var: expr_var "<<" expr_int
#line 437 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 1806 "frontend/parser.cpp"
    break;

  case 149: // expr_var: expr_var "<<" expr_var
#line 438 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BLSHFT)); }
#line 1812 "frontend/parser.cpp"
    break;

  case 150: // expr_var: expr_int ">>" expr_var
#line 440 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 1818 "frontend/parser.cpp"
    break;

  case 151: // expr_var: expr_var ">>" expr_int
#line 441 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 1824 "frontend/parser.cpp"
    break;

  case 152: // expr_var: expr_var ">>" expr_var
#line 442 "frontend/parser.yy"
                                    { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BRSHFT)); }
#line 1830 "frontend/parser.cpp"
    break;

  case 153: // expr_var: expr_int ">" expr_var
#line 444 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 1836 "frontend/parser.cpp"
    break;

  case 154: // expr_var: expr_float ">" expr_var
#line 445 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 1842 "frontend/parser.cpp"
    break;

  case 156: // expr_var: expr_var ">" expr_int
#line 447 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 1848 "frontend/parser.cpp"
    break;

  case 157: // expr_var: expr_var ">" expr_float
#line 448 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 1854 "frontend/parser.cpp"
    break;

  case 158: // expr_var: expr_var ">" expr_str
#line 449 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1860 "frontend/parser.cpp"
    break;

  case 159: // expr_var: expr_var ">" expr_var
#line 450 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BT)); }
#line 1866 "frontend/parser.cpp"
    break;

  case 160: // expr_var: expr_int ">=" expr_var
#line 452 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 1872 "frontend/parser.cpp"
    break;

  case 161: // expr_var: expr_float ">=" expr_var
#line 453 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 1878 "frontend/parser.cpp"
    break;

  case 163: // expr_var: expr_var ">=" expr_int
#line 455 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 1884 "frontend/parser.cpp"
    break;

  case 164: // expr_var: expr_var ">=" expr_float
#line 456 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 1890 "frontend/parser.cpp"
    break;

  case 165: // expr_var: expr_var ">=" expr_str
#line 457 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1896 "frontend/parser.cpp"
    break;

  case 166: // expr_var: expr_var ">=" expr_var
#line 458 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BEQ)); }
#line 1902 "frontend/parser.cpp"
    break;

  case 167: // expr_var: expr_int "<" expr_var
#line 460 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 1908 "frontend/parser.cpp"
    break;

  case 168: // expr_var: expr_float "<" expr_var
#line 461 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 1914 "frontend/parser.cpp"
    break;

  case 170: // expr_var: expr_var "<" expr_int
#line 463 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 1920 "frontend/parser.cpp"
    break;

  case 171: // expr_var: expr_var "<" expr_float
#line 464 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 1926 "frontend/parser.cpp"
    break;

  case 172: // expr_var: expr_var "<" expr_str
#line 465 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1932 "frontend/parser.cpp"
    break;

  case 173: // expr_var: expr_var "<" expr_var
#line 466 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LT)); }
#line 1938 "frontend/parser.cpp"
    break;

  case 174: // expr_var: expr_int "<=" expr_var
#line 468 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 1944 "frontend/parser.cpp"
    break;

  case 175: // expr_var: expr_float "<=" expr_var
#line 469 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 1950 "frontend/parser.cpp"
    break;

  case 177: // expr_var: expr_var "<=" expr_int
#line 471 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 1956 "frontend/parser.cpp"
    break;

  case 178: // expr_var: expr_var "<=" expr_float
#line 472 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 1962 "frontend/parser.cpp"
    break;

  case 179: // expr_var: expr_var "<=" expr_str
#line 473 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 1968 "frontend/parser.cpp"
    break;

  case 180: // expr_var: expr_var "<=" expr_var
#line 474 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LEQ)); }
#line 1974 "frontend/parser.cpp"
    break;

  case 181: // expr_var: expr_int "==" expr_var
#line 476 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 1980 "frontend/parser.cpp"
    break;

  case 182: // expr_var: expr_float "==" expr_var
#line 477 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 1986 "frontend/parser.cpp"
    break;

  case 184: // expr_var: expr_bool "==" expr_var
#line 479 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 1992 "frontend/parser.cpp"
    break;

  case 188: // expr_var: expr_var "==" expr_int
#line 483 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 1998 "frontend/parser.cpp"
    break;

  case 189: // expr_var: expr_var "==" expr_float
#line 484 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2004 "frontend/parser.cpp"
    break;

  case 190: // expr_var: expr_var "==" expr_str
#line 485 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2010 "frontend/parser.cpp"
    break;

  case 191: // expr_var: expr_var "==" expr_bool
#line 486 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2016 "frontend/parser.cpp"
    break;

  case 192: // expr_var: expr_var "==" expr_none
#line 487 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2022 "frontend/parser.cpp"
    break;

  case 193: // expr_var: expr_var "==" expr_struct
#line 488 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2028 "frontend/parser.cpp"
    break;

  case 195: // expr_var: expr_var "==" expr_mat
#line 490 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2034 "frontend/parser.cpp"
    break;

  case 197: // expr_var: expr_var "==" expr_var
#line 492 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_EQ)); }
#line 2040 "frontend/parser.cpp"
    break;

  case 198: // expr_var: expr_int "!=" expr_var
#line 494 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2046 "frontend/parser.cpp"
    break;

  case 199: // expr_var: expr_float "!=" expr_var
#line 495 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2052 "frontend/parser.cpp"
    break;

  case 205: // expr_var: expr_var "!=" expr_int
#line 501 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2058 "frontend/parser.cpp"
    break;

  case 206: // expr_var: expr_var "!=" expr_float
#line 502 "frontend/parser.yy"
                                       { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2064 "frontend/parser.cpp"
    break;

  case 207: // expr_var: expr_var "!=" expr_str
#line 503 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2070 "frontend/parser.cpp"
    break;

  case 208: // expr_var: expr_var "!=" expr_bool
#line 504 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2076 "frontend/parser.cpp"
    break;

  case 209: // expr_var: expr_var "!=" expr_none
#line 505 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2082 "frontend/parser.cpp"
    break;

  case 210: // expr_var: expr_var "!=" expr_struct
#line 506 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2088 "frontend/parser.cpp"
    break;

  case 212: // expr_var: expr_var "!=" expr_mat
#line 508 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2094 "frontend/parser.cpp"
    break;

  case 214: // expr_var: expr_var "!=" expr_var
#line 510 "frontend/parser.yy"
                                        { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_NEQ)); }
#line 2100 "frontend/parser.cpp"
    break;

  case 215: // expr_var: expr_int "&" expr_var
#line 512 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2106 "frontend/parser.cpp"
    break;

  case 216: // expr_var: expr_var "&" expr_int
#line 513 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2112 "frontend/parser.cpp"
    break;

  case 217: // expr_var: expr_var "&" expr_var
#line 514 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BAND)); }
#line 2118 "frontend/parser.cpp"
    break;

  case 218: // expr_var: expr_int "^" expr_var
#line 516 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2124 "frontend/parser.cpp"
    break;

  case 219: // expr_var: expr_var "^" expr_int
#line 517 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2130 "frontend/parser.cpp"
    break;

  case 220: // expr_var: expr_var "^" expr_var
#line 518 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BXOR)); }
#line 2136 "frontend/parser.cpp"
    break;

  case 221: // expr_var: expr_int "|" expr_var
#line 520 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2142 "frontend/parser.cpp"
    break;

  case 222: // expr_var: expr_var "|" expr_int
#line 521 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2148 "frontend/parser.cpp"
    break;

  case 223: // expr_var: expr_var "|" expr_var
#line 522 "frontend/parser.yy"
                                 { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_BOR)); }
#line 2154 "frontend/parser.cpp"
    break;

  case 238: // expr_var: expr_var "in" expr_str
#line 538 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2160 "frontend/parser.cpp"
    break;

  case 239: // expr_var: expr_var "in" expr_var
#line 539 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2166 "frontend/parser.cpp"
    break;

  case 240: // expr_var: expr_bool "and" expr_var
#line 541 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2172 "frontend/parser.cpp"
    break;

  case 241: // expr_var: expr_var "and" expr_bool
#line 542 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2178 "frontend/parser.cpp"
    break;

  case 242: // expr_var: expr_var "and" expr_var
#line 543 "frontend/parser.yy"
                                   { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LAND)); }
#line 2184 "frontend/parser.cpp"
    break;

  case 243: // expr_var: expr_bool "or" expr_var
#line 545 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2190 "frontend/parser.cpp"
    break;

  case 244: // expr_var: expr_var "or" expr_bool
#line 546 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2196 "frontend/parser.cpp"
    break;

  case 245: // expr_var: expr_var "or" expr_var
#line 547 "frontend/parser.yy"
                                  { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_LOR)); }
#line 2202 "frontend/parser.cpp"
    break;

  case 257: // expr_var: expr_int "++" expr_var
#line 560 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseInt(yystack_[2].value.as < long > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2208 "frontend/parser.cpp"
    break;

  case 258: // expr_var: expr_float "++" expr_var
#line 561 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseFloat(yystack_[2].value.as < double > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2214 "frontend/parser.cpp"
    break;

  case 259: // expr_var: expr_str "++" expr_var
#line 562 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2220 "frontend/parser.cpp"
    break;

  case 260: // expr_var: expr_bool "++" expr_var
#line 563 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(scanner->parseBool(yystack_[2].value.as < bool > ()), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2226 "frontend/parser.cpp"
    break;

  case 263: // expr_var: expr_var "++" expr_int
#line 566 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseInt(yystack_[0].value.as < long > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2232 "frontend/parser.cpp"
    break;

  case 264: // expr_var: expr_var "++" expr_float
#line 567 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseFloat(yystack_[0].value.as < double > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2238 "frontend/parser.cpp"
    break;

  case 265: // expr_var: expr_var "++" expr_str
#line 568 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseString(yystack_[0].value.as < std::string > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2244 "frontend/parser.cpp"
    break;

  case 266: // expr_var: expr_var "++" expr_bool
#line 569 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), scanner->parseBool(yystack_[0].value.as < bool > ()), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2250 "frontend/parser.cpp"
    break;

  case 267: // expr_var: expr_var "++" expr_none
#line 570 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2256 "frontend/parser.cpp"
    break;

  case 268: // expr_var: expr_var "++" expr_struct
#line 571 "frontend/parser.yy"
           { yylhs.value.as < ptc::ir::Expr * > () = yystack_[2].value.as < ptc::ir::Expr * > (); }
#line 2262 "frontend/parser.cpp"
    break;

  case 269: // expr_var: expr_var "++" expr_var
#line 572 "frontend/parser.yy"
                                          { yylhs.value.as < ptc::ir::Expr * > () = scanner->parseInfixExpr(yystack_[2].value.as < ptc::ir::Expr * > (), yystack_[0].value.as < ptc::ir::Expr * > (), ir::Operator(ir::OperatorKind::OP_CONCAT)); }
#line 2268 "frontend/parser.cpp"
    break;

  case 306: // expr_int: "int"
#line 630 "frontend/parser.yy"
               { yylhs.value.as < long > () = yystack_[0].value.as < long > (); }
#line 2274 "frontend/parser.cpp"
    break;

  case 307: // expr_int: "-" expr_int
#line 631 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = -yystack_[0].value.as < long > (); }
#line 2280 "frontend/parser.cpp"
    break;

  case 308: // expr_int: "(" expr_int ")"
#line 632 "frontend/parser.yy"
                              { yylhs.value.as < long > () = yystack_[1].value.as < long > (); }
#line 2286 "frontend/parser.cpp"
    break;

  case 309: // expr_int: "~" expr_int
#line 633 "frontend/parser.yy"
                         { yylhs.value.as < long > () = ~yystack_[0].value.as < long > (); }
#line 2292 "frontend/parser.cpp"
    break;

  case 310: // expr_int: expr_int "*" expr_int
#line 634 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () * yystack_[0].value.as < long > (); }
#line 2298 "frontend/parser.cpp"
    break;

  case 311: // expr_int: expr_int "/" expr_int
#line 635 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () / yystack_[0].value.as < long > (); }
#line 2304 "frontend/parser.cpp"
    break;

  case 312: // expr_int: expr_int "%" expr_int
#line 636 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () % yystack_[0].value.as < long > (); }
#line 2310 "frontend/parser.cpp"
    break;

  case 313: // expr_int: expr_int "-" expr_int
#line 637 "frontend/parser.yy"
                                   { yylhs.value.as < long > () = yystack_[2].value.as < long > () - yystack_[0].value.as < long > (); }
#line 2316 "frontend/parser.cpp"
    break;

  case 314: // expr_int: expr_int "+" expr_int
#line 638 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () + yystack_[0].value.as < long > (); }
#line 2322 "frontend/parser.cpp"
    break;

  case 315: // expr_int: expr_int "<<" expr_int
#line 639 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () << yystack_[0].value.as < long > (); }
#line 2328 "frontend/parser.cpp"
    break;

  case 316: // expr_int: expr_int ">>" expr_int
#line 640 "frontend/parser.yy"
                                    { yylhs.value.as < long > () = yystack_[2].value.as < long > () >> yystack_[0].value.as < long > (); }
#line 2334 "frontend/parser.cpp"
    break;

  case 317: // expr_int: expr_int "&" expr_int
#line 641 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () & yystack_[0].value.as < long > (); }
#line 2340 "frontend/parser.cpp"
    break;

  case 318: // expr_int: expr_int "^" expr_int
#line 642 "frontend/parser.yy"
                                  { yylhs.value.as < long > () = yystack_[2].value.as < long > () ^ yystack_[0].value.as < long > (); }
#line 2346 "frontend/parser.cpp"
    break;

  case 319: // expr_int: expr_int "|" expr_int
#line 643 "frontend/parser.yy"
                                 { yylhs.value.as < long > () = yystack_[2].value.as < long > () | yystack_[0].value.as < long > (); }
#line 2352 "frontend/parser.cpp"
    break;

  case 320: // expr_float: "float"
#line 647 "frontend/parser.yy"
                   { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 2358 "frontend/parser.cpp"
    break;

  case 321: // expr_float: "-" expr_float
#line 648 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 2364 "frontend/parser.cpp"
    break;

  case 322: // expr_float: "(" expr_float ")"
#line 649 "frontend/parser.yy"
                                  { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 2370 "frontend/parser.cpp"
    break;

  case 323: // expr_float: expr_float "**" expr_float
#line 650 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2376 "frontend/parser.cpp"
    break;

  case 324: // expr_float: expr_float "**" expr_int
#line 651 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2382 "frontend/parser.cpp"
    break;

  case 325: // expr_float: expr_int "**" expr_float
#line 652 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::pow(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2388 "frontend/parser.cpp"
    break;

  case 326: // expr_float: expr_float "*" expr_float
#line 653 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 2394 "frontend/parser.cpp"
    break;

  case 327: // expr_float: expr_float "*" expr_int
#line 654 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < long > (); }
#line 2400 "frontend/parser.cpp"
    break;

  case 328: // expr_float: expr_int "*" expr_float
#line 655 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () * yystack_[0].value.as < double > (); }
#line 2406 "frontend/parser.cpp"
    break;

  case 329: // expr_float: expr_float "/" expr_float
#line 656 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 2412 "frontend/parser.cpp"
    break;

  case 330: // expr_float: expr_float "/" expr_int
#line 657 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < long > (); }
#line 2418 "frontend/parser.cpp"
    break;

  case 331: // expr_float: expr_int "/" expr_float
#line 658 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = yystack_[2].value.as < long > () / yystack_[0].value.as < double > (); }
#line 2424 "frontend/parser.cpp"
    break;

  case 332: // expr_float: expr_float "%" expr_float
#line 659 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 2430 "frontend/parser.cpp"
    break;

  case 333: // expr_float: expr_float "%" expr_int
#line 660 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < double > (), yystack_[0].value.as < long > ()); }
#line 2436 "frontend/parser.cpp"
    break;

  case 334: // expr_float: expr_int "%" expr_float
#line 661 "frontend/parser.yy"
                                     { yylhs.value.as < double > () = std::fmod(yystack_[2].value.as < long > (), yystack_[0].value.as < double > ()); }
#line 2442 "frontend/parser.cpp"
    break;

  case 335: // expr_float: expr_float "-" expr_float
#line 662 "frontend/parser.yy"
                                         { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 2448 "frontend/parser.cpp"
    break;

  case 336: // expr_float: expr_float "-" expr_int
#line 663 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < long > (); }
#line 2454 "frontend/parser.cpp"
    break;

  case 337: // expr_float: expr_int "-" expr_float
#line 664 "frontend/parser.yy"
                                       { yylhs.value.as < double > () = yystack_[2].value.as < long > () - yystack_[0].value.as < double > (); }
#line 2460 "frontend/parser.cpp"
    break;

  case 338: // expr_float: expr_float "+" expr_float
#line 665 "frontend/parser.yy"
                                        { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 2466 "frontend/parser.cpp"
    break;

  case 339: // expr_float: expr_float "+" expr_int
#line 666 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < long > (); }
#line 2472 "frontend/parser.cpp"
    break;

  case 340: // expr_float: expr_int "+" expr_float
#line 667 "frontend/parser.yy"
                                      { yylhs.value.as < double > () = yystack_[2].value.as < long > () + yystack_[0].value.as < double > (); }
#line 2478 "frontend/parser.cpp"
    break;

  case 341: // expr_str: "string"
#line 671 "frontend/parser.yy"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2484 "frontend/parser.cpp"
    break;

  case 342: // expr_str: "(" expr_str ")"
#line 672 "frontend/parser.yy"
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 2490 "frontend/parser.cpp"
    break;

  case 343: // expr_str: expr_str "++" expr_str
#line 673 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > (); }
#line 2496 "frontend/parser.cpp"
    break;

  case 344: // expr_str: expr_str "++" expr_int
#line 674 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < long > ()); }
#line 2502 "frontend/parser.cpp"
    break;

  case 345: // expr_str: expr_str "++" expr_float
#line 675 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + std::to_string(yystack_[0].value.as < double > ()); }
#line 2508 "frontend/parser.cpp"
    break;

  case 346: // expr_str: expr_str "++" expr_bool
#line 676 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2514 "frontend/parser.cpp"
    break;

  case 347: // expr_str: expr_str "++" expr_none
#line 677 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "none"; }
#line 2520 "frontend/parser.cpp"
    break;

  case 348: // expr_str: expr_int "++" expr_str
#line 678 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + yystack_[0].value.as < std::string > (); }
#line 2526 "frontend/parser.cpp"
    break;

  case 349: // expr_str: expr_int "++" expr_int
#line 679 "frontend/parser.yy"
                                    { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 2532 "frontend/parser.cpp"
    break;

  case 350: // expr_str: expr_int "++" expr_float
#line 680 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 2538 "frontend/parser.cpp"
    break;

  case 351: // expr_str: expr_int "++" expr_bool
#line 681 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2544 "frontend/parser.cpp"
    break;

  case 352: // expr_str: expr_int "++" expr_none
#line 682 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < long > ()) + "none"; }
#line 2550 "frontend/parser.cpp"
    break;

  case 353: // expr_str: expr_float "++" expr_str
#line 683 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + yystack_[0].value.as < std::string > (); }
#line 2556 "frontend/parser.cpp"
    break;

  case 354: // expr_str: expr_float "++" expr_int
#line 684 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < long > ()); }
#line 2562 "frontend/parser.cpp"
    break;

  case 355: // expr_str: expr_float "++" expr_float
#line 685 "frontend/parser.yy"
                                        { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + std::to_string(yystack_[0].value.as < double > ()); }
#line 2568 "frontend/parser.cpp"
    break;

  case 356: // expr_str: expr_float "++" expr_bool
#line 686 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2574 "frontend/parser.cpp"
    break;

  case 357: // expr_str: expr_float "++" expr_none
#line 687 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::to_string(yystack_[2].value.as < double > ()) + "none"; }
#line 2580 "frontend/parser.cpp"
    break;

  case 358: // expr_str: expr_bool "++" expr_str
#line 688 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + yystack_[0].value.as < std::string > (); }
#line 2586 "frontend/parser.cpp"
    break;

  case 359: // expr_str: expr_bool "++" expr_int
#line 689 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < long > ()); }
#line 2592 "frontend/parser.cpp"
    break;

  case 360: // expr_str: expr_bool "++" expr_float
#line 690 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? "true" : "false") + std::to_string(yystack_[0].value.as < double > ()); }
#line 2598 "frontend/parser.cpp"
    break;

  case 361: // expr_str: expr_bool "++" expr_bool
#line 691 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2604 "frontend/parser.cpp"
    break;

  case 362: // expr_str: expr_bool "++" expr_none
#line 692 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = (yystack_[2].value.as < bool > () ? std::string("true") : std::string("false")) + "none"; }
#line 2610 "frontend/parser.cpp"
    break;

  case 363: // expr_str: expr_none "++" expr_str
#line 693 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + yystack_[0].value.as < std::string > (); }
#line 2616 "frontend/parser.cpp"
    break;

  case 364: // expr_str: expr_none "++" expr_int
#line 694 "frontend/parser.yy"
                                     { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < long > ()); }
#line 2622 "frontend/parser.cpp"
    break;

  case 365: // expr_str: expr_none "++" expr_float
#line 695 "frontend/parser.yy"
                                       { yylhs.value.as < std::string > () = std::string("none") + std::to_string(yystack_[0].value.as < double > ()); }
#line 2628 "frontend/parser.cpp"
    break;

  case 366: // expr_str: expr_none "++" expr_bool
#line 696 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("none") + (yystack_[0].value.as < bool > () ? "true" : "false"); }
#line 2634 "frontend/parser.cpp"
    break;

  case 367: // expr_str: expr_none "++" expr_none
#line 697 "frontend/parser.yy"
                                      { yylhs.value.as < std::string > () = std::string("nonenone"); }
#line 2640 "frontend/parser.cpp"
    break;

  case 368: // expr_bool: "bool"
#line 701 "frontend/parser.yy"
                 { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 2646 "frontend/parser.cpp"
    break;

  case 369: // expr_bool: "(" expr_bool ")"
#line 702 "frontend/parser.yy"
                                { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 2652 "frontend/parser.cpp"
    break;

  case 370: // expr_bool: "not" expr_bool
#line 703 "frontend/parser.yy"
                           { yylhs.value.as < bool > () = !yystack_[0].value.as < bool > (); }
#line 2658 "frontend/parser.cpp"
    break;

  case 371: // expr_bool: expr_bool "or" expr_bool
#line 704 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > (); }
#line 2664 "frontend/parser.cpp"
    break;

  case 372: // expr_bool: expr_bool "and" expr_bool
#line 705 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 2670 "frontend/parser.cpp"
    break;

  case 373: // expr_bool: expr_bool "==" expr_bool
#line 707 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () == yystack_[0].value.as < bool > (); }
#line 2676 "frontend/parser.cpp"
    break;

  case 374: // expr_bool: expr_int "==" expr_int
#line 708 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < long > (); }
#line 2682 "frontend/parser.cpp"
    break;

  case 375: // expr_bool: expr_int "==" expr_float
#line 709 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () == yystack_[0].value.as < double > (); }
#line 2688 "frontend/parser.cpp"
    break;

  case 376: // expr_bool: expr_float "==" expr_float
#line 710 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < double > (); }
#line 2694 "frontend/parser.cpp"
    break;

  case 377: // expr_bool: expr_float "==" expr_int
#line 711 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () == yystack_[0].value.as < long > (); }
#line 2700 "frontend/parser.cpp"
    break;

  case 378: // expr_bool: expr_str "==" expr_str
#line 712 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > (); }
#line 2706 "frontend/parser.cpp"
    break;

  case 379: // expr_bool: expr_none "==" expr_none
#line 713 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = true; }
#line 2712 "frontend/parser.cpp"
    break;

  case 380: // expr_bool: expr_bool "!=" expr_bool
#line 715 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () != yystack_[0].value.as < bool > (); }
#line 2718 "frontend/parser.cpp"
    break;

  case 381: // expr_bool: expr_int "!=" expr_int
#line 716 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < long > (); }
#line 2724 "frontend/parser.cpp"
    break;

  case 382: // expr_bool: expr_int "!=" expr_float
#line 717 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () != yystack_[0].value.as < double > (); }
#line 2730 "frontend/parser.cpp"
    break;

  case 383: // expr_bool: expr_float "!=" expr_float
#line 718 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < double > (); }
#line 2736 "frontend/parser.cpp"
    break;

  case 384: // expr_bool: expr_float "!=" expr_int
#line 719 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () != yystack_[0].value.as < long > (); }
#line 2742 "frontend/parser.cpp"
    break;

  case 385: // expr_bool: expr_str "!=" expr_str
#line 720 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > (); }
#line 2748 "frontend/parser.cpp"
    break;

  case 386: // expr_bool: expr_none "!=" expr_none
#line 721 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = false; }
#line 2754 "frontend/parser.cpp"
    break;

  case 387: // expr_bool: expr_int ">" expr_int
#line 723 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < long > (); }
#line 2760 "frontend/parser.cpp"
    break;

  case 388: // expr_bool: expr_int ">" expr_float
#line 724 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () > yystack_[0].value.as < double > (); }
#line 2766 "frontend/parser.cpp"
    break;

  case 389: // expr_bool: expr_float ">" expr_float
#line 725 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < double > (); }
#line 2772 "frontend/parser.cpp"
    break;

  case 390: // expr_bool: expr_float ">" expr_int
#line 726 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () > yystack_[0].value.as < long > (); }
#line 2778 "frontend/parser.cpp"
    break;

  case 391: // expr_bool: expr_str ">" expr_str
#line 727 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () > yystack_[0].value.as < std::string > (); }
#line 2784 "frontend/parser.cpp"
    break;

  case 392: // expr_bool: expr_int "<" expr_int
#line 729 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < long > (); }
#line 2790 "frontend/parser.cpp"
    break;

  case 393: // expr_bool: expr_int "<" expr_float
#line 730 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < long > () < yystack_[0].value.as < double > (); }
#line 2796 "frontend/parser.cpp"
    break;

  case 394: // expr_bool: expr_float "<" expr_float
#line 731 "frontend/parser.yy"
                                     { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < double > (); }
#line 2802 "frontend/parser.cpp"
    break;

  case 395: // expr_bool: expr_float "<" expr_int
#line 732 "frontend/parser.yy"
                                   { yylhs.value.as < bool > () = yystack_[2].value.as < double > () < yystack_[0].value.as < long > (); }
#line 2808 "frontend/parser.cpp"
    break;

  case 396: // expr_bool: expr_str "<" expr_str
#line 733 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () < yystack_[0].value.as < std::string > (); }
#line 2814 "frontend/parser.cpp"
    break;

  case 397: // expr_bool: expr_int ">=" expr_int
#line 735 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < long > (); }
#line 2820 "frontend/parser.cpp"
    break;

  case 398: // expr_bool: expr_int ">=" expr_float
#line 736 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () >= yystack_[0].value.as < double > (); }
#line 2826 "frontend/parser.cpp"
    break;

  case 399: // expr_bool: expr_float ">=" expr_float
#line 737 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < double > (); }
#line 2832 "frontend/parser.cpp"
    break;

  case 400: // expr_bool: expr_float ">=" expr_int
#line 738 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () >= yystack_[0].value.as < long > (); }
#line 2838 "frontend/parser.cpp"
    break;

  case 401: // expr_bool: expr_str ">=" expr_str
#line 739 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () >= yystack_[0].value.as < std::string > (); }
#line 2844 "frontend/parser.cpp"
    break;

  case 402: // expr_bool: expr_int "<=" expr_int
#line 741 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < long > (); }
#line 2850 "frontend/parser.cpp"
    break;

  case 403: // expr_bool: expr_int "<=" expr_float
#line 742 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < long > () <= yystack_[0].value.as < double > (); }
#line 2856 "frontend/parser.cpp"
    break;

  case 404: // expr_bool: expr_float "<=" expr_float
#line 743 "frontend/parser.yy"
                                      { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < double > (); }
#line 2862 "frontend/parser.cpp"
    break;

  case 405: // expr_bool: expr_float "<=" expr_int
#line 744 "frontend/parser.yy"
                                    { yylhs.value.as < bool > () = yystack_[2].value.as < double > () <= yystack_[0].value.as < long > (); }
#line 2868 "frontend/parser.cpp"
    break;

  case 406: // expr_bool: expr_str "<=" expr_str
#line 745 "frontend/parser.yy"
                                  { yylhs.value.as < bool > () = yystack_[2].value.as < std::string > () <= yystack_[0].value.as < std::string > (); }
#line 2874 "frontend/parser.cpp"
    break;

  case 407: // expr_bool: expr_str "in" expr_str
#line 747 "frontend/parser.yy"
                                 { yylhs.value.as < bool > () = yystack_[0].value.as < std::string > ().find(yystack_[2].value.as < std::string > ()) != std::string::npos; }
#line 2880 "frontend/parser.cpp"
    break;

  case 424: // type: "'int'" "?"
#line 775 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2886 "frontend/parser.cpp"
    break;

  case 425: // type: "'float'" "?"
#line 776 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2892 "frontend/parser.cpp"
    break;

  case 426: // type: "'string'" "?"
#line 777 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2898 "frontend/parser.cpp"
    break;

  case 427: // type: "'bool'" "?"
#line 778 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2904 "frontend/parser.cpp"
    break;

  case 428: // type: "identifier" "?"
#line 779 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2910 "frontend/parser.cpp"
    break;

  case 429: // type: funtype "?"
#line 780 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2916 "frontend/parser.cpp"
    break;

  case 430: // type: mattype "?"
#line 781 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2922 "frontend/parser.cpp"
    break;

  case 431: // type: "'int'"
#line 782 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("int", true); }
#line 2928 "frontend/parser.cpp"
    break;

  case 432: // type: "'float'"
#line 783 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("float", true); }
#line 2934 "frontend/parser.cpp"
    break;

  case 433: // type: "'string'"
#line 784 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("string", true); }
#line 2940 "frontend/parser.cpp"
    break;

  case 434: // type: "'bool'"
#line 785 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup("bool", true); }
#line 2946 "frontend/parser.cpp"
    break;

  case 435: // type: "identifier"
#line 786 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = scanner->sym_lookup(yystack_[0].value.as < std::string > (), true); }
#line 2952 "frontend/parser.cpp"
    break;

  case 436: // type: funtype
#line 787 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2958 "frontend/parser.cpp"
    break;

  case 437: // type: mattype
#line 788 "frontend/parser.yy"
                        { yylhs.value.as < ptc::ir::IR * > () = nullptr; /*TODO*/ }
#line 2964 "frontend/parser.cpp"
    break;


#line 2968 "frontend/parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -732;

  const short  Parser ::yytable_ninf_ = -436;

  const short
   Parser ::yypact_[] =
  {
    1458,  -732,  -732,  -732,  -732,  -732,  -732,  -732,  2527,    30,
      84,   709,   252,   -68,   -49,     6,    22,    68,  2350,  2541,
    -732,  -732,   -24,     2,    19,    34,    42,     7,    43,    36,
      92,   121,   359,  -732,  -732,   159,   178,  -732,  -732,  -732,
    -732,  -732,  -732,  -732,   195,   228,   233,   468,  2560,  -732,
    1053,  -732,   371,   534,  2944,  3113,   453,   895,   183,   245,
      -6,   261,    37,  2603,   305,  1053,   308,   146,   371,   534,
    2865,  1134,   937,   622,  2541,  -732,    37,   215,   255,   390,
     390,  -732,  -732,  -732,  -732,   775,   301,  2979,  3136,   471,
    -732,   252,   252,  -732,   287,   292,  -732,  2541,   260,  2541,
     328,  2424,  -732,  -732,   285,  -732,   316,   654,  -732,   746,
    -732,   890,  -732,  1589,  -732,   246,  -732,   363,   987,   203,
    2541,  -732,  -732,  -732,   789,  2541,  -732,  -732,  -732,  2454,
    -732,  -732,  -732,  -732,  -732,  -732,  -732,  2541,  2541,  2541,
    2541,  2541,  2541,  2541,  2541,  2541,  2541,  2541,  2541,  2541,
    1810,   789,  2541,  2541,  2541,  2541,  2541,  2541,  2541,  2541,
    2541,  2541,  2541,  2541,  2541,  2541,  2541,  2541,  2541,  2541,
    2541,  2541,  2541,  2541,  -732,   789,  2541,  2541,  2541,  2541,
    2541,  2541,  -732,  2541,  2541,  2541,  2541,  2541,  2541,  2541,
    2541,  2541,  2541,  2541,  2541,  2541,   390,  2541,  2541,  2541,
    2541,  2541,  2541,  2541,  2541,  2541,  2541,  2541,  2541,  2541,
    2541,  2541,  2541,  2541,  2541,  2541,  2541,  2541,  2541,  2541,
    2541,  2541,  2541,  2541,  2541,  2541,  2541,  2541,  2541,  2541,
    2541,  2541,  2541,  2541,  2541,  2541,  2541,  2541,  2541,  -732,
    -732,   168,    54,   365,  -732,   789,   351,  -732,  -732,  -732,
    2541,  2541,  -732,  -732,  -732,  -732,   313,    57,   366,  -732,
    1293,  1003,   390,   390,   390,   390,   390,   252,   252,   252,
     252,   252,   390,   390,   390,   390,   390,   390,  2893,  2921,
    1005,   817,   709,   271,   271,   709,   390,   390,   390,   390,
     390,   390,   709,   390,   390,   390,   390,   390,   390,   709,
     709,   709,   709,   709,   709,   709,   709,   709,   709,   709,
     709,   709,  1480,  -732,   252,   252,   252,   252,   252,  2541,
     -49,   377,   350,   388,  2454,  -732,  1275,   393,  2541,  -732,
    2560,   372,  2944,  3113,   453,   895,   406,  -732,   415,  -732,
     460,  -732,   463,   392,    53,   175,  -732,  1231,    86,   479,
    -732,   418,   483,   192,  2944,   122,   192,  -732,  -732,  3166,
    -732,  -732,  -732,  -732,  -732,  -732,  -732,  -732,  -732,  -732,
    -732,  -732,  -732,   488,   481,   123,   362,    67,   747,   754,
     362,    67,   747,   754,   221,   489,   504,   506,   221,   504,
     506,   221,   504,   506,   221,   506,  2632,   352,   375,  3007,
    3159,   875,   573,  2708,   469,  2663,   157,  2743,   514,  2830,
    2166,  2772,  3067,  2801,  3090,   337,   688,   337,   688,  1190,
     334,  -732,  -732,  1401,  1393,   403,  -732,  1190,   334,  -732,
    -732,  1401,  1393,   403,  -732,   570,  1108,  1485,   516,   570,
    1108,  1485,   516,   570,  1108,  1485,   516,   570,  1108,  1485,
     516,   192,   124,   362,    67,   362,    67,   221,   489,  2743,
     237,  1190,   334,  1190,   334,  2632,   352,   375,  3007,  3159,
     875,   573,  2743,   237,  1190,  -732,  1190,  -732,  2632,   352,
     375,  3007,  3159,   875,   573,  2743,   237,  1190,  -732,  1190,
    -732,   362,   747,   754,   362,   747,   754,   221,   504,   506,
     221,   504,   506,   221,   504,   506,  1655,   509,  2632,   352,
     375,  3007,  3159,   875,   573,  2743,   237,  2830,  2166,  2772,
    3067,  2801,  3090,   337,   688,   337,   688,  1190,  1401,  1393,
    1190,  1401,  1393,   570,  1108,  1485,   570,  1108,  1485,   570,
    1108,  1485,   570,  1108,  1485,   362,   747,   754,   362,   747,
     754,   221,   504,   506,   221,   504,   506,   221,   504,   506,
     221,   504,   506,  2632,   352,   375,  3007,  3159,   875,   573,
    2743,   237,  1190,  1401,  1393,  1190,  1401,  1393,   570,  1108,
    1485,   570,  1108,  1485,   570,  1108,  1485,   570,  1108,  1485,
     541,  2632,   352,   375,  3007,  3159,   875,   573,  2743,   237,
     514,  1190,   403,  1190,   403,   570,   516,   570,   516,   570,
     516,   570,   516,  2632,   352,   375,  3007,  3159,   875,   573,
    2708,   469,  2663,   157,  2743,   237,  1190,  -732,  1190,  -732,
    -732,    44,   544,    31,  1824,   268,   161,  -732,   546,   520,
     550,  -732,  2541,  -732,  -732,   828,   850,   828,   850,   504,
     509,   504,   509,   504,   509,  1349,   656,  1533,   517,   517,
     828,   850,   828,   850,   504,   509,   504,   509,   504,   509,
     504,   509,   251,  3033,  3170,   411,   699,   556,  -732,  -732,
     251,  3033,  3170,   411,   699,  1621,  1614,  1621,  1614,  1621,
    1614,  1621,  1614,  1621,  1614,  1621,  1614,   251,  3033,  3170,
     411,   699,  1621,  1614,  1621,  1614,  1621,  1614,  1621,  1614,
    1621,  1614,  1621,  1614,   251,  3033,  3170,   411,   699,  1757,
     444,   838,   838,  -732,  -732,  -732,  -732,   251,  3033,  3170,
     411,   699,   357,   202,  -732,  -732,    97,    97,  -732,  -732,
    -732,  -732,  -732,  2350,  2541,  2350,  1902,   565,  2541,  -732,
    2541,  -732,  -732,  -732,  -732,   105,   105,  -732,   497,   561,
     574,    -3,   314,    12,   536,     8,  -732,  1916,   187,  -732,
    1549,  -732,   538,  -732,  -732,  -732,  2541,  -732,  -732,  -732,
    2002,  -732,   558,  -732,  -732,   314,    18,  -732,  2541,  -732,
    -732,   261,   531,   582,  -732,   590,  -732,   589,  -732,   588,
    -732,   566,  -732,   105,   568,  -732,   314,   558,   558,   583,
    -732,   591,  -732,  2261,  -732,  2289,   188,  2541,  -732,  -732,
    -732,   314,   597,  2350,  -732,  2350,  -732,  -732,  -732,  2541,
    -732,  2541,  -732,    15,   536,    20,  2541,  -732,  -732,   612,
    -732,   623,  -732,  2322,   599,  -732,  -732,  -732,  -732,  -732,
    -732,  -732,   583,  -732,  -732,  -732,  -732,   629,   607,  -732,
    -732
  };

  const short
   Parser ::yydefact_[] =
  {
       0,     2,     7,   306,   320,   341,   368,   298,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      31,    32,     0,   431,   432,   433,   434,     0,     0,    91,
      92,     0,     0,     4,     8,     0,     0,    33,    13,    15,
      16,    14,    17,    18,     0,     0,     0,     0,    84,   278,
      83,   279,    85,    86,    87,    88,    89,    90,   436,   437,
       0,   298,    91,   285,   278,     0,   279,     0,     0,     0,
     284,     0,     0,     0,     0,   270,    91,   275,     0,     0,
       0,    93,    94,   307,   321,     0,     0,     0,     0,     0,
     370,     0,     0,   309,     0,    29,    28,     0,     0,     0,
       0,     0,    26,    27,     0,    35,     0,     0,   424,     0,
     425,     0,   426,     0,   427,     0,    56,     0,     0,     0,
       0,   428,   104,   300,     0,     0,   105,     1,     3,     0,
       5,    12,    19,    10,    11,     9,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   106,     0,     0,     0,     0,     0,
       0,     0,   103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   429,
     430,     0,    56,     0,   299,     0,   300,    95,   280,   281,
       0,     0,   308,   322,   342,   369,     0,     0,     0,   271,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   307,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,     0,     0,   415,
     285,   422,   284,     0,     0,     0,     0,   417,     0,   419,
       0,   421,     0,     0,     0,     0,   413,     0,     0,     0,
     302,     0,     0,   107,     0,     0,   108,     6,    80,    79,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    96,     0,    81,     0,   138,   136,   133,   134,
     146,   144,   141,   142,   120,   119,   115,   116,   125,   123,
     124,   130,   128,   129,   112,   111,   269,   267,   268,   263,
     264,   265,   266,   242,   241,   245,   244,   239,   238,   217,
     216,   223,   222,   220,   219,   149,   148,   152,   151,   197,
     195,   192,   193,   188,   189,   190,   191,   214,   212,   209,
     210,   205,   206,   207,   208,   159,   156,   157,   158,   173,
     170,   171,   172,   166,   163,   164,   165,   180,   177,   178,
     179,   109,     0,   137,   135,   145,   143,   118,   117,   237,
     230,   196,   194,   213,   211,   261,   367,   250,   364,   365,
     363,   366,   235,   228,   185,   379,   202,   386,   262,   255,
     256,   251,   252,   253,   254,   236,   229,   187,   186,   204,
     203,   131,   314,   340,   139,   313,   337,   113,   310,   328,
     121,   311,   331,   126,   312,   334,     0,   325,   257,   352,
     246,   349,   350,   348,   351,   231,   224,   215,   317,   221,
     319,   218,   318,   147,   315,   150,   316,   181,   374,   375,
     198,   381,   382,   153,   387,   388,   167,   392,   393,   160,
     397,   398,   174,   402,   403,   132,   339,   338,   140,   336,
     335,   114,   327,   326,   122,   330,   329,   127,   333,   332,
     110,   324,   323,   258,   357,   247,   354,   355,   353,   356,
     232,   225,   182,   377,   376,   199,   384,   383,   154,   390,
     389,   168,   395,   394,   161,   400,   399,   175,   405,   404,
       0,   259,   347,   248,   344,   345,   343,   346,   233,   226,
     407,   183,   378,   200,   385,   155,   391,   169,   396,   162,
     401,   176,   406,   260,   362,   249,   359,   360,   358,   361,
     240,   372,   243,   371,   234,   227,   184,   373,   201,   380,
     409,   435,     0,   410,     0,     0,     0,   301,     0,     0,
       0,   272,     0,   276,   273,   314,   340,   313,   337,   310,
     328,   311,   331,   312,   334,   317,   319,   318,   315,   316,
     339,   338,   336,   335,   327,   326,   330,   329,   333,   332,
     324,   323,   367,   364,   365,   363,   366,     0,   379,   386,
     352,   349,   350,   348,   351,   374,   375,   381,   382,   387,
     388,   392,   393,   397,   398,   402,   403,   357,   354,   355,
     353,   356,   377,   376,   384,   383,   390,   389,   395,   394,
     400,   399,   405,   404,   347,   344,   345,   343,   346,   407,
       0,   378,   385,   391,   396,   401,   406,   362,   359,   360,
     358,   361,   372,   371,   373,   380,   314,   313,   310,   311,
     312,    66,    30,     0,     0,     0,     0,    22,     0,    65,
       0,   414,   416,   418,   420,     0,    45,    42,     0,     0,
       0,     0,     0,     0,    58,     0,   286,     0,     0,   100,
       0,   412,     0,   303,   101,    97,     0,   102,    99,    98,
       0,   408,     0,    64,    63,     0,     0,   282,     0,   274,
     277,     0,    41,     0,    37,    23,    24,     0,   423,     0,
      46,     0,    43,    47,    49,    54,     0,     0,     0,    57,
     290,     0,   288,     0,   287,     0,     0,     0,    82,   411,
      52,     0,     0,     0,    39,     0,    25,    38,    44,     0,
      48,     0,    55,     0,    61,     0,     0,   293,   292,     0,
     291,     0,   289,     0,   304,    53,   283,    40,    36,    51,
      50,    59,     0,    60,   296,   295,   294,     0,     0,   297,
     305
  };

  const short
   Parser ::yypgoto_[] =
  {
    -732,  -732,   -97,   -12,   -17,  -655,  -731,  -732,   330,  -732,
    -732,  -732,  -732,  -732,  -732,  -732,  -732,  -712,  -732,  -732,
     592,    13,  -152,  -732,  -732,   530,  -119,  2245,  1537,   660,
     -69,  1035,   661,   218,  1418,   792,  1256,   -60,  -182,  1942,
       0,   312,   552,  -732,  -105,  -732,   -86,  -225
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    31,    32,    33,    34,   103,   104,    35,    96,    36,
      37,    38,    39,    40,    41,   824,    42,   759,   760,    43,
     117,   763,   764,    44,    45,    46,   373,    47,    48,    49,
      78,    65,    51,   331,   174,    68,    69,   123,   352,    54,
     333,   334,   335,    58,   632,    59,   349,    60
  };

  const short
   Parser ::yytable_[] =
  {
      55,   102,   246,   241,   326,   256,   241,    94,    71,    55,
      84,    88,   792,   107,   794,    97,   633,   241,    55,    55,
     130,   336,   806,   338,   241,   340,    95,   342,   821,   241,
     109,    98,    55,    74,     3,     4,     5,     6,     7,     8,
     241,     9,    75,   799,   800,   111,    10,   118,   245,   119,
     119,   106,   807,   113,    11,   780,   756,   -62,   807,    12,
     642,     3,     4,     5,     6,     7,     8,   757,     9,   242,
     108,   782,   804,    10,    55,   120,   120,    99,   175,   261,
      84,    11,   115,   809,   178,   279,    12,   110,     3,     4,
     851,   830,   847,    79,   848,   852,   634,    55,   769,    55,
      80,    55,   112,   124,   121,    76,    30,   805,   756,   758,
     114,  -435,   121,    12,   316,   317,   318,   357,   116,   761,
     765,   127,    23,    24,    25,    26,   750,   770,   631,    55,
     820,   125,    76,    30,   774,   777,   778,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,   832,   379,   383,   387,   390,   393,   395,   400,    81,
      82,   758,   131,   770,   770,   770,   845,   424,   432,   437,
     441,   445,   449,   769,    23,    24,    25,    26,   630,   234,
     631,   132,   236,   469,   250,   762,   251,   482,   643,   237,
     238,   493,   496,   499,   502,   505,   507,   512,   133,   812,
     842,   150,   770,   151,   529,   532,   535,   538,   541,   544,
     547,   550,   553,   556,   559,   562,   567,   350,   574,   577,
     580,   583,   586,   589,   308,   595,    67,   746,   813,   843,
     150,   134,   151,   617,   310,   311,   135,    23,    24,    25,
      26,   157,   351,   631,    23,    24,    25,    26,   175,   343,
     631,   239,   176,   177,   178,   257,     3,    55,   258,   344,
     173,    91,   646,   648,   650,   652,   654,   259,    92,   180,
     181,   244,   661,   663,   665,   667,   669,   671,   785,     7,
     677,    12,   674,   283,   284,   682,   686,   688,   690,   692,
     694,   696,   699,   703,   705,   707,   709,   711,   713,   716,
      88,    88,    88,    88,    88,    88,    88,   729,    88,    88,
      88,    88,    56,   240,   130,   248,   640,   100,   249,    55,
      72,    56,   282,    89,    55,   641,    55,   101,    55,   319,
      56,    56,   320,   283,   284,   322,   348,    23,    24,    25,
      26,   324,   355,   631,    56,   175,   150,   327,   151,   176,
     177,   178,   152,   153,   154,   155,   156,   157,   328,   128,
     129,   637,     2,     3,     4,     5,     6,     7,     8,   375,
       9,   150,   345,   151,   635,    10,   173,   184,   644,   154,
     155,   156,   157,    11,   185,   186,    56,   743,    12,   310,
     311,   744,   183,   452,     3,     4,   184,   280,   745,    79,
     188,   173,   748,   185,   186,   755,    80,   189,   190,    56,
     765,    56,   750,    56,   224,    13,    14,    15,   751,    12,
      16,    17,    18,    19,    20,    21,    22,   752,    23,    24,
      25,    26,    27,    28,    29,    30,   300,   229,   230,   231,
     232,    56,   590,   301,   302,   303,   304,   305,   306,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,   636,   224,   307,   308,   309,   638,   639,
     401,   136,   753,   408,   225,   754,   310,   311,   226,   425,
     433,   438,   442,   446,   450,   227,   228,   229,   230,   231,
     232,   771,   299,   772,   236,   470,   300,   773,   775,   483,
     175,   237,   238,   301,   302,   303,   304,   305,   306,   513,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   776,   148,   149,   196,   224,   215,   224,   568,   277,
     761,   761,   314,   315,   316,   317,   318,   596,   600,   602,
     604,   606,   608,   610,   612,   618,   227,   228,   229,   230,
     231,   232,    57,   779,   781,   187,   787,   633,   788,   188,
      73,    57,   789,    90,   791,   768,   189,   190,   796,    56,
      57,    57,   801,   790,   784,   802,   808,   803,   761,   150,
     817,   151,   833,   835,    57,   152,   153,   154,   155,   156,
     157,   823,   825,   826,   675,   234,   235,   683,   236,   827,
     165,   166,   828,   837,   700,   237,   238,   846,   829,   173,
     831,   717,   719,   721,   722,   723,   724,   725,   726,   730,
      89,    89,    89,    89,   854,   836,    57,    23,    24,    25,
      26,    56,   255,   631,    55,   855,    56,   281,    56,   858,
      56,   859,    55,   233,   234,   235,   351,   236,   786,    57,
     742,    57,   243,    57,   237,   238,   834,   818,     3,     4,
       5,     6,     7,     8,   798,     9,   329,   358,    64,    66,
      10,   314,   315,   316,   317,   318,   860,   819,    11,     0,
       0,    57,   267,    12,   269,     0,   270,   271,     0,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,   191,   192,   193,   194,   195,   196,     0,
     402,   404,   406,     3,     4,     5,     6,     7,    85,   426,
     434,   308,   309,     0,     0,    80,   102,     0,   102,    76,
      30,   310,   311,    11,   130,   471,     0,     0,    12,   484,
       0,     0,     0,    55,    55,    55,    55,     0,    55,   514,
       3,     4,     5,     6,     7,     8,     0,     9,   337,     0,
       0,     0,    10,     0,   193,   194,   195,   196,   569,     0,
      11,   212,   213,   214,   215,    12,    55,   597,     0,     3,
       4,     5,     6,    61,    85,   619,   621,   623,     0,   627,
     629,    80,    52,     3,     4,     5,     6,     7,     8,    11,
       9,    52,     0,    86,    12,    10,   102,     0,   102,    57,
      52,    52,     0,    11,     0,     0,     0,    55,    12,     0,
       0,    76,    30,    55,    52,    55,     0,   255,     0,    55,
     347,    55,     0,     0,   676,     0,    55,   684,   307,   308,
     309,     0,     0,     0,   701,   264,   265,   266,   196,   310,
     311,   718,   720,   720,   720,   720,   720,   720,   720,   731,
     732,   733,   734,   735,    76,    30,    52,   274,   275,   276,
     277,    57,   303,   304,   305,   306,    57,    86,    57,     0,
      57,     0,     0,     0,     0,     0,   224,     0,     0,    52,
       0,    52,     0,    52,     3,     4,     5,     6,     7,     8,
     226,     9,   339,     0,     0,     0,    10,   227,   228,   229,
     230,   231,   232,     0,    11,     0,   233,   234,   235,    12,
     236,    52,     0,     0,     0,     0,     0,   237,   238,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,     0,     0,     0,    56,   254,   224,     0,
     397,     0,     0,     0,    56,     0,     0,     0,   225,   421,
     429,     0,   226,     0,     0,    76,    30,     0,     0,   227,
     228,   229,   230,   231,   232,   466,     0,   475,   477,   479,
       0,     0,     0,     0,     0,   811,     0,     0,   816,   509,
       0,     3,     4,     5,     6,     7,     8,     0,     9,   346,
       0,     0,     0,    10,     0,     0,   822,     0,   564,     0,
       0,    11,     0,   253,     0,   254,    12,   592,   272,   273,
     274,   275,   276,   277,     0,   614,   299,     0,   347,     0,
     300,   839,     0,   841,     0,    50,     0,   301,   302,   303,
     304,   305,   306,     0,    50,     0,     0,     0,     0,    52,
       0,     0,     0,    50,    50,    56,    56,    56,    56,     0,
      56,   857,    76,    30,   175,     0,     0,    50,   176,   177,
     178,     0,     0,     0,   672,   678,   679,   680,   179,     0,
       0,     0,     0,     0,   697,   180,   181,     0,    56,     0,
       0,   714,    86,    86,    86,    86,    86,    86,    86,   727,
      86,    86,    86,    86,     0,     0,     0,     0,     0,    50,
       0,    52,     0,     0,     0,     0,    52,     0,    52,     0,
      52,     0,     0,   191,   192,   193,   194,   195,   196,    56,
       0,     0,    50,     0,    50,    56,    50,    56,   202,   203,
       0,    56,     0,    56,   253,     0,     0,     0,    56,   210,
     211,   212,   213,   214,   215,   216,     0,     0,     0,   217,
       0,     0,     0,     0,    50,     0,   218,   219,   220,   221,
     222,   223,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    57,   377,   381,   385,
       0,     0,     0,     0,    57,     0,     0,     0,     0,   150,
       0,   151,   420,   428,     0,   152,   153,   154,   155,   156,
     157,   454,   456,   458,   460,   462,   464,     0,     0,   473,
     165,   166,     0,   486,   169,   170,   171,   172,     0,   173,
       0,     0,     0,   516,     0,     3,     4,     5,     6,     7,
       8,     0,     9,   766,     0,     0,     0,    10,     0,     0,
       0,     0,   571,     0,     0,    11,    53,     0,     0,     0,
      12,   599,     0,     0,     0,    53,     0,     0,     0,     0,
       0,   625,   767,     0,    53,    53,   129,     0,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,    53,   747,
       0,    10,    50,     0,     0,    57,    57,    57,    57,    11,
      57,     0,     0,   252,    12,     0,    76,    30,   262,   263,
     264,   265,   266,   196,     0,     0,     0,     0,     0,   267,
     268,   269,     0,   270,   271,     0,     0,     0,    57,     0,
      53,    13,    14,    15,     0,     0,    16,    17,    18,    19,
      20,    21,    22,     0,    23,    24,    25,    26,    27,    28,
      29,    30,     0,    53,    50,    53,     0,    53,     0,    50,
       0,    50,     0,    50,   314,   315,   316,   317,   318,    57,
       0,     0,     0,     0,     0,    57,     0,    57,     0,   270,
     271,    57,     0,    57,     0,    53,     0,     0,    57,     0,
       0,     0,     0,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,     0,   210,   211,
     212,   213,   214,   215,   398,     0,   191,   192,   193,   194,
     195,   196,     0,   422,   430,     0,    52,   220,   221,   222,
     223,   202,   203,     0,    52,   206,   207,   208,   209,   467,
       0,     0,     0,   480,     0,   488,   490,   122,   126,     0,
       0,     0,     0,   510,     0,     0,     0,     0,     1,     0,
       0,     2,     3,     4,     5,     6,     7,     8,   182,     9,
       0,     0,   565,     0,    10,     0,     0,     0,     0,     0,
     122,   593,    11,   182,     0,     0,     0,    12,     0,   615,
     252,     0,     0,     0,   122,   314,   315,   316,   317,   318,
     210,   211,   212,   213,   214,   215,   267,   268,   269,     0,
     270,   271,     0,    53,    13,    14,    15,     0,     0,    16,
      17,    18,    19,    20,    21,    22,     0,    23,    24,    25,
      26,    27,    28,    29,    30,    52,    52,    52,    52,     0,
      52,     0,     0,     0,     0,    63,     0,     0,   314,   315,
     316,   317,   318,     3,     4,     5,     6,     7,     8,   267,
       9,   814,     0,   270,   271,    10,     0,     0,    52,     0,
       0,     0,     0,    11,     0,    53,     0,     0,    12,     0,
      53,     0,    53,     0,    53,     0,     0,     0,     0,     0,
     815,     0,     0,     3,     4,     5,     6,     7,     8,     0,
       9,   341,     0,     0,     0,    10,     0,     0,     0,    52,
       0,     0,     0,    11,     0,    52,     0,    52,    12,     0,
       0,    52,     0,    52,    76,    30,     0,     0,    52,   272,
     273,   274,   275,   276,   277,     0,   262,   263,   264,   265,
     266,   196,     0,     0,   330,     0,   330,     0,   330,     0,
     330,   270,   271,     0,     0,   330,     0,   353,     0,     0,
       0,   330,   356,     0,    76,    30,     0,     0,     0,    50,
     262,   263,   264,   265,   266,   196,     0,    50,     0,     0,
       0,   267,   268,   269,     0,   270,   271,     0,   330,   376,
     380,   384,   388,   391,   394,   396,   403,   405,   407,   409,
     411,   413,   415,   417,   419,   427,   435,   439,   443,   447,
     451,     0,   330,   453,   455,   457,   459,   461,   463,     0,
     465,   472,   474,   476,   478,   485,   487,   489,   491,   494,
     497,   500,   503,     0,   508,   515,   517,   519,   521,   523,
     525,   527,   530,   533,   536,   539,   542,   545,   548,   551,
     554,   557,   560,   563,   570,   572,   575,   578,   581,   584,
     587,   330,   591,   598,   601,   603,   605,   607,   609,   611,
     613,   620,   622,   624,   626,   628,     0,     0,    50,    50,
      50,    50,   330,    50,     0,     0,     0,   330,   330,   301,
     302,   303,   304,   305,   306,   182,     0,     0,     0,   182,
       0,     0,     0,   182,     0,     0,     0,     0,     0,     0,
       0,    50,     0,     0,     3,     4,     5,     6,     7,     8,
     372,     9,     0,     0,     0,     0,    10,     0,     3,     4,
       5,     6,     7,     8,    11,     9,     0,   119,   182,    12,
      10,     0,     0,     0,     0,     0,   182,     0,    11,     0,
       0,     0,    50,    12,     0,     0,     0,     0,    50,     0,
      50,     0,     0,     0,    50,     0,    50,     0,     0,     0,
       0,    50,   182,     0,   182,     0,   182,     0,   182,     0,
     182,     0,   182,     0,   330,    76,    30,     0,     0,     0,
      53,   182,     0,     0,     0,     0,     0,     0,    53,    76,
      30,     0,     0,   129,   182,     2,     3,     4,     5,     6,
       7,     8,     0,     9,     0,     0,   795,     0,    10,     0,
       3,     4,     5,     6,     7,     8,    11,     9,   810,     0,
       0,    12,    10,     0,   182,     0,     0,     0,     0,     0,
      11,     0,     0,     0,     0,    12,     0,     0,     0,     0,
      70,     0,    83,    87,    93,     0,     0,     0,    13,    14,
      15,     0,     0,    16,    17,    18,    19,    20,    21,    22,
       0,    23,    24,    25,    26,    27,    28,    29,    30,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   182,
       0,    76,    30,     0,     0,     0,     0,     0,     0,    53,
      53,    53,    53,     0,    53,     0,     3,     4,     5,     6,
       7,     8,     0,     9,   346,     0,     0,   182,    10,     0,
       0,   260,    83,     0,     0,     0,    11,   278,     0,     0,
       0,    12,    53,   312,   313,     0,     0,     0,     0,     0,
       0,     0,     0,   182,     0,     0,     0,     0,     0,   332,
       0,   332,     0,   332,     0,   332,     0,     0,     0,     0,
     332,     0,   354,     0,     0,     0,   332,   354,     0,     0,
       0,     0,     0,    53,     0,     0,     0,    76,    30,    53,
       0,    53,     0,     0,     0,    53,     0,    53,     0,     0,
       0,     0,    53,   332,   378,   382,   386,   389,   392,   354,
     399,   354,   354,   354,   410,   412,   414,   416,   418,   423,
     431,   436,   440,   444,   448,   354,     0,   332,   354,   354,
     354,   354,   354,   354,     0,   468,   354,   354,   354,   481,
     354,   354,   354,   492,   495,   498,   501,   504,   506,   511,
     354,   518,   520,   522,   524,   526,   528,   531,   534,   537,
     540,   543,   546,   549,   552,   555,   558,   561,   566,   354,
     573,   576,   579,   582,   585,   588,   332,   594,   354,   354,
     354,   354,   354,   354,   354,   616,   354,   354,   354,   354,
     354,   191,   192,   193,   194,   195,   196,   332,     0,     0,
       0,     0,   332,   332,     0,     0,   202,   203,   204,   205,
     206,   207,   208,   209,   645,   647,   649,   651,   653,   655,
     656,   657,   658,   659,   660,   662,   664,   666,   668,   670,
       0,     0,     0,     0,   673,     0,     0,   681,   685,   687,
     689,   691,   693,   695,   698,   702,   704,   706,   708,   710,
     712,   715,    87,    87,    87,    87,    87,    87,    87,   728,
      87,    87,    87,    87,    77,     0,   736,   737,   738,   739,
     740,     0,     0,     0,   105,     3,     4,     5,     6,     7,
       8,     0,     9,   838,     0,     0,     0,    10,     0,     0,
       0,     0,     0,     0,     0,    11,     0,   330,     0,   332,
      12,     0,     0,     3,     4,     5,     6,     7,     8,     0,
       9,   840,     0,     0,   330,    10,     0,   330,     0,     0,
       0,     0,     0,    11,     0,     0,     0,   330,    12,    77,
       0,     0,     0,     0,     0,   330,     3,     4,     5,     6,
       7,     8,     0,     9,   856,     0,    76,    30,    10,     0,
       0,     0,   321,     0,   323,     0,    11,     0,     0,     0,
     330,    12,   330,   100,     3,     4,     5,     6,     7,     8,
       0,     9,     0,   101,    76,    30,    10,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,     0,     0,    12,
     330,     0,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   374,     0,    76,    30,     0,
       0,     0,     0,     0,     0,     0,    13,    14,    15,     0,
       0,    16,    17,    18,    19,    20,    21,    22,     0,    23,
      24,    25,    26,    27,    28,    29,    30,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,   325,     0,
      10,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,     0,     0,    12,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,     0,     0,
      10,     0,     0,     0,     0,     0,     0,     0,    11,     0,
      13,    14,    15,    12,     0,    16,    17,    18,    19,    20,
      21,    22,     0,    23,    24,    25,    26,    27,    28,    29,
      30,     0,    77,     0,     0,     0,     0,     0,     0,     0,
      13,    14,    15,     0,     0,    16,    17,    18,    19,    20,
      21,    22,     0,    23,    24,    25,    26,    27,    28,    29,
      30,     3,     4,     5,     6,    61,     8,     0,     9,     0,
       0,     0,     0,    10,     0,     3,     4,     5,     6,     7,
       8,    11,     9,     0,     0,     0,    12,    10,     0,     0,
       0,     0,     0,     0,   741,    11,     0,     0,     0,   150,
      12,   151,     0,   749,     0,   152,   153,   154,   155,   156,
     157,   158,   159,   160,     0,   161,   162,   163,   164,     0,
     165,   166,   167,   168,   169,   170,   171,   172,     0,   173,
       0,     0,    62,    30,     0,     0,     0,     0,     0,     0,
       0,     0,   150,   247,   151,     0,    76,    30,   152,   153,
     154,   155,   156,   157,   158,   159,   160,     0,   161,   162,
     163,   164,     0,   165,   166,   167,   168,   169,   170,   171,
     172,   150,   173,   151,     0,     0,     0,   152,   153,   154,
     155,   156,   157,     0,   159,   160,     0,   161,   162,   163,
     164,     0,   165,   166,   167,   168,   169,   170,   171,   172,
       0,   173,   150,     0,   151,     0,     0,     0,   152,   153,
     154,   155,   156,   157,     0,   159,     0,     0,   161,   162,
     163,   164,   332,   165,   166,   167,   168,   169,   170,   171,
     172,     0,   173,     0,     0,     0,     0,     0,     0,   332,
       0,     0,   332,     0,     0,     0,     0,   150,     0,   151,
       0,     0,   332,   152,   153,   154,   155,   156,   157,     0,
     332,     0,     0,   161,   162,   163,   164,     0,   165,   166,
     167,   168,   169,   170,   171,   172,     0,   173,     0,     0,
       0,     0,   150,     0,   151,   332,     0,   332,   152,   153,
     154,   155,   156,   157,     0,     0,     0,     0,     0,   162,
     163,   164,     0,   165,   166,   167,   168,   169,   170,   171,
     172,   150,   173,   151,     0,   332,     0,   152,   153,   154,
     155,   156,   157,     0,     0,     0,     0,     0,   162,     0,
     164,     0,   165,   166,   167,   168,   169,   170,   171,   172,
     150,   173,   151,     0,     0,     0,   152,   153,   154,   155,
     156,   157,     0,     0,     0,     0,     0,   162,     0,     0,
       0,   165,   166,   167,   168,   169,   170,   171,   172,   150,
     173,   151,     0,     0,     0,   152,   153,   154,   155,   156,
     157,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     165,   166,   167,   168,   169,   170,   171,   172,     0,   173,
       0,     0,     0,     0,     0,   252,     0,     0,     0,   783,
     191,   192,   193,   194,   195,   196,   197,    77,     0,     0,
     198,   199,   200,   201,     0,   202,   203,   204,   205,   206,
     207,   208,   209,   252,     0,     0,     0,     0,   262,   263,
     264,   265,   266,   196,   285,     0,     0,     0,     0,   267,
     268,   269,     0,   270,   271,   286,   287,   288,   289,   290,
     291,   253,     0,     0,     0,     0,   272,   273,   274,   275,
     276,   277,   292,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   293,   294,   295,   296,   297,   298,   191,
     192,   193,   194,   195,   196,   197,     0,     0,     0,   198,
     199,   200,   201,     0,   202,   203,   204,   205,   206,   207,
     208,   209,     0,     0,     0,     0,     0,     0,     0,   793,
       0,     0,     0,   797,   262,   263,   264,   265,   266,   196,
     285,     0,     0,     0,     0,   267,   268,   269,     0,   270,
     271,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,   374,   191,   192,   193,   194,   195,   196,     0,     0,
       0,     0,   198,   199,   200,   201,     0,   202,   203,   204,
     205,   206,   207,   208,   209,     0,     0,     0,   262,   263,
     264,   265,   266,   196,     0,     0,     0,     0,     0,   267,
     268,   269,   844,   270,   271,   286,   287,   288,   289,   290,
     291,     0,     0,     0,   849,     0,   850,     0,     0,     0,
       0,   853,   191,   192,   193,   194,   195,   196,     0,     0,
       0,     0,     0,   199,     0,   201,     0,   202,   203,   204,
     205,   206,   207,   208,   209,   191,   192,   193,   194,   195,
     196,     0,     0,     0,     0,     0,   199,     0,     0,     0,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,     0,     0,     0,   217,     0,
       0,     0,     0,     0,     0,   218,   219,   220,   221,   222,
     223,   272,   273,   274,   275,   276,   277,   292,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   293,   294,
     295,   296,   297,   298,   210,   211,   212,   213,   214,   215,
       0,     0,     0,     0,   217,   272,   273,   274,   275,   276,
     277,   218,   219,   220,   221,   222,   223,     0,     0,     0,
       0,     0,   293,   294,   295,   296,   297,   298,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,     0,
     148,   149
  };

  const short
   Parser ::yycheck_[] =
  {
       0,    18,    62,     9,   101,    74,     9,    75,     8,     9,
      10,    11,   743,    11,   745,     9,   241,     9,    18,    19,
      32,   107,    10,   109,     9,   111,    75,   113,    10,     9,
      11,     9,    32,     3,     4,     5,     6,     7,     8,     9,
       9,    11,    12,   755,   756,    11,    16,    11,    11,    13,
      13,    75,    40,    11,    24,    11,     3,     3,    40,    29,
       3,     4,     5,     6,     7,     8,     9,    14,    11,    75,
      68,    40,    75,    16,    74,    39,    39,     9,    11,    79,
      80,    24,    75,    75,    17,    85,    29,    68,     4,     5,
      75,   803,   823,     9,   825,    75,    42,    97,    12,    99,
      16,   101,    68,    11,    68,    75,    76,   762,     3,    56,
      68,    75,    68,    29,    17,    18,    19,   129,    75,   344,
     345,     0,    69,    70,    71,    72,    40,    41,    75,   129,
     785,    39,    75,    76,    12,    12,    12,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   806,   152,   153,   154,   155,   156,   157,   158,    75,
      76,    56,     3,    41,    41,    41,   821,   167,   168,   169,
     170,   171,   172,    12,    69,    70,    71,    72,    10,    22,
      75,     3,    25,   183,    38,    10,    40,   187,   257,    32,
      33,   191,   192,   193,   194,   195,   196,   197,     3,    12,
      12,     9,    41,    11,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    14,   218,   219,
     220,   221,   222,   223,    22,   225,     8,   324,    41,    41,
       9,     3,    11,   233,    32,    33,     3,    69,    70,    71,
      72,    20,    39,    75,    69,    70,    71,    72,    11,     3,
      75,    68,    15,    16,    17,    40,     4,   257,     3,    13,
      39,     9,   262,   263,   264,   265,   266,    12,    16,    32,
      33,    10,   272,   273,   274,   275,   276,   277,    10,     8,
       9,    29,   282,    32,    33,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,     0,    68,   326,    10,     3,     3,    10,   319,
       8,     9,    21,    11,   324,    12,   326,    13,   328,    42,
      18,    19,    40,    32,    33,    75,   118,    69,    70,    71,
      72,    13,   124,    75,    32,    11,     9,    62,    11,    15,
      16,    17,    15,    16,    17,    18,    19,    20,    42,     0,
       1,    10,     3,     4,     5,     6,     7,     8,     9,   151,
      11,     9,     9,    11,     9,    16,    39,    25,    12,    17,
      18,    19,    20,    24,    32,    33,    74,    10,    29,    32,
      33,    41,    21,   175,     4,     5,    25,    85,    10,     9,
      25,    39,     9,    32,    33,    13,    16,    32,    33,    97,
     635,    99,    40,   101,    11,    56,    57,    58,    12,    29,
      61,    62,    63,    64,    65,    66,    67,    12,    69,    70,
      71,    72,    73,    74,    75,    76,    25,    34,    35,    36,
      37,   129,   224,    32,    33,    34,    35,    36,    37,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   245,    11,    21,    22,    23,   250,   251,
     158,     3,    12,   161,    21,    12,    32,    33,    25,   167,
     168,   169,   170,   171,   172,    32,    33,    34,    35,    36,
      37,    12,    21,    75,    25,   183,    25,    14,    10,   187,
      11,    32,    33,    32,    33,    34,    35,    36,    37,   197,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    40,    54,    55,    20,    11,    20,    11,   216,    20,
     755,   756,    15,    16,    17,    18,    19,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    32,    33,    34,    35,
      36,    37,     0,    12,    10,    21,    10,   782,    38,    25,
       8,     9,    12,    11,     8,   347,    32,    33,     3,   257,
      18,    19,    75,   642,   634,    14,    40,     3,   803,     9,
      42,    11,   807,   808,    32,    15,    16,    17,    18,    19,
      20,    60,    10,     3,   282,    22,    23,   285,    25,    10,
      30,    31,    14,    12,   292,    32,    33,    10,    42,    39,
      42,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,    12,    42,    74,    69,    70,    71,
      72,   319,    10,    75,   634,    12,   324,    85,   326,    40,
     328,    12,   642,    21,    22,    23,    39,    25,   635,    97,
     320,    99,    60,   101,    32,    33,   808,   776,     4,     5,
       6,     7,     8,     9,   750,    11,    12,   137,     8,     8,
      16,    15,    16,    17,    18,    19,   858,   782,    24,    -1,
      -1,   129,    26,    29,    28,    -1,    30,    31,    -1,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,    15,    16,    17,    18,    19,    20,    -1,
     158,   159,   160,     4,     5,     6,     7,     8,     9,   167,
     168,    22,    23,    -1,    -1,    16,   743,    -1,   745,    75,
      76,    32,    33,    24,   746,   183,    -1,    -1,    29,   187,
      -1,    -1,    -1,   743,   744,   745,   746,    -1,   748,   197,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
      -1,    -1,    16,    -1,    17,    18,    19,    20,   216,    -1,
      24,    17,    18,    19,    20,    29,   776,   225,    -1,     4,
       5,     6,     7,     8,     9,   233,   234,   235,    -1,   237,
     238,    16,     0,     4,     5,     6,     7,     8,     9,    24,
      11,     9,    -1,    11,    29,    16,   823,    -1,   825,   257,
      18,    19,    -1,    24,    -1,    -1,    -1,   817,    29,    -1,
      -1,    75,    76,   823,    32,   825,    -1,    10,    -1,   829,
      41,   831,    -1,    -1,   282,    -1,   836,   285,    21,    22,
      23,    -1,    -1,    -1,   292,    17,    18,    19,    20,    32,
      33,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,    75,    76,    74,    17,    18,    19,
      20,   319,    34,    35,    36,    37,   324,    85,   326,    -1,
     328,    -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,    97,
      -1,    99,    -1,   101,     4,     5,     6,     7,     8,     9,
      25,    11,    12,    -1,    -1,    -1,    16,    32,    33,    34,
      35,    36,    37,    -1,    24,    -1,    21,    22,    23,    29,
      25,   129,    -1,    -1,    -1,    -1,    -1,    32,    33,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,    -1,    -1,    -1,   634,    10,    11,    -1,
     158,    -1,    -1,    -1,   642,    -1,    -1,    -1,    21,   167,
     168,    -1,    25,    -1,    -1,    75,    76,    -1,    -1,    32,
      33,    34,    35,    36,    37,   183,    -1,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   767,    -1,    -1,   770,   197,
      -1,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,   788,    -1,   216,    -1,
      -1,    24,    -1,    10,    -1,    10,    29,   225,    15,    16,
      17,    18,    19,    20,    -1,   233,    21,    -1,    41,    -1,
      25,   813,    -1,   815,    -1,     0,    -1,    32,    33,    34,
      35,    36,    37,    -1,     9,    -1,    -1,    -1,    -1,   257,
      -1,    -1,    -1,    18,    19,   743,   744,   745,   746,    -1,
     748,   843,    75,    76,    11,    -1,    -1,    32,    15,    16,
      17,    -1,    -1,    -1,   282,   283,   284,   285,    25,    -1,
      -1,    -1,    -1,    -1,   292,    32,    33,    -1,   776,    -1,
      -1,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,    -1,    -1,    -1,    -1,    -1,    74,
      -1,   319,    -1,    -1,    -1,    -1,   324,    -1,   326,    -1,
     328,    -1,    -1,    15,    16,    17,    18,    19,    20,   817,
      -1,    -1,    97,    -1,    99,   823,   101,   825,    30,    31,
      -1,   829,    -1,   831,    10,    -1,    -1,    -1,   836,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    -1,   129,    -1,    32,    33,    34,    35,
      36,    37,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   634,   152,   153,   154,
      -1,    -1,    -1,    -1,   642,    -1,    -1,    -1,    -1,     9,
      -1,    11,   167,   168,    -1,    15,    16,    17,    18,    19,
      20,   176,   177,   178,   179,   180,   181,    -1,    -1,   184,
      30,    31,    -1,   188,    34,    35,    36,    37,    -1,    39,
      -1,    -1,    -1,   198,    -1,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    -1,   217,    -1,    -1,    24,     0,    -1,    -1,    -1,
      29,   226,    -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,
      -1,   236,    41,    -1,    18,    19,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    -1,    32,    14,
      -1,    16,   257,    -1,    -1,   743,   744,   745,   746,    24,
     748,    -1,    -1,    10,    29,    -1,    75,    76,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    -1,    30,    31,    -1,    -1,    -1,   776,    -1,
      74,    56,    57,    58,    -1,    -1,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    97,   319,    99,    -1,   101,    -1,   324,
      -1,   326,    -1,   328,    15,    16,    17,    18,    19,   817,
      -1,    -1,    -1,    -1,    -1,   823,    -1,   825,    -1,    30,
      31,   829,    -1,   831,    -1,   129,    -1,    -1,   836,    -1,
      -1,    -1,    -1,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,    -1,    15,    16,
      17,    18,    19,    20,   158,    -1,    15,    16,    17,    18,
      19,    20,    -1,   167,   168,    -1,   634,    34,    35,    36,
      37,    30,    31,    -1,   642,    34,    35,    36,    37,   183,
      -1,    -1,    -1,   187,    -1,   189,   190,    29,    30,    -1,
      -1,    -1,    -1,   197,    -1,    -1,    -1,    -1,     0,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    50,    11,
      -1,    -1,   216,    -1,    16,    -1,    -1,    -1,    -1,    -1,
      62,   225,    24,    65,    -1,    -1,    -1,    29,    -1,   233,
      10,    -1,    -1,    -1,    76,    15,    16,    17,    18,    19,
      15,    16,    17,    18,    19,    20,    26,    27,    28,    -1,
      30,    31,    -1,   257,    56,    57,    58,    -1,    -1,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,   743,   744,   745,   746,    -1,
     748,    -1,    -1,    -1,    -1,     8,    -1,    -1,    15,    16,
      17,    18,    19,     4,     5,     6,     7,     8,     9,    26,
      11,    12,    -1,    30,    31,    16,    -1,    -1,   776,    -1,
      -1,    -1,    -1,    24,    -1,   319,    -1,    -1,    29,    -1,
     324,    -1,   326,    -1,   328,    -1,    -1,    -1,    -1,    -1,
      41,    -1,    -1,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,   817,
      -1,    -1,    -1,    24,    -1,   823,    -1,   825,    29,    -1,
      -1,   829,    -1,   831,    75,    76,    -1,    -1,   836,    15,
      16,    17,    18,    19,    20,    -1,    15,    16,    17,    18,
      19,    20,    -1,    -1,   107,    -1,   109,    -1,   111,    -1,
     113,    30,    31,    -1,    -1,   118,    -1,   120,    -1,    -1,
      -1,   124,   125,    -1,    75,    76,    -1,    -1,    -1,   634,
      15,    16,    17,    18,    19,    20,    -1,   642,    -1,    -1,
      -1,    26,    27,    28,    -1,    30,    31,    -1,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,   175,   176,   177,   178,   179,   180,   181,    -1,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,    -1,    -1,   743,   744,
     745,   746,   245,   748,    -1,    -1,    -1,   250,   251,    32,
      33,    34,    35,    36,    37,   377,    -1,    -1,    -1,   381,
      -1,    -1,    -1,   385,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   776,    -1,    -1,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    16,    -1,     4,     5,
       6,     7,     8,     9,    24,    11,    -1,    13,   420,    29,
      16,    -1,    -1,    -1,    -1,    -1,   428,    -1,    24,    -1,
      -1,    -1,   817,    29,    -1,    -1,    -1,    -1,   823,    -1,
     825,    -1,    -1,    -1,   829,    -1,   831,    -1,    -1,    -1,
      -1,   836,   454,    -1,   456,    -1,   458,    -1,   460,    -1,
     462,    -1,   464,    -1,   347,    75,    76,    -1,    -1,    -1,
     634,   473,    -1,    -1,    -1,    -1,    -1,    -1,   642,    75,
      76,    -1,    -1,     1,   486,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    -1,    -1,    14,    -1,    16,    -1,
       4,     5,     6,     7,     8,     9,    24,    11,    12,    -1,
      -1,    29,    16,    -1,   516,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
       8,    -1,    10,    11,    12,    -1,    -1,    -1,    56,    57,
      58,    -1,    -1,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   571,
      -1,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,   743,
     744,   745,   746,    -1,   748,    -1,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,   599,    16,    -1,
      -1,    79,    80,    -1,    -1,    -1,    24,    85,    -1,    -1,
      -1,    29,   776,    91,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   625,    -1,    -1,    -1,    -1,    -1,   107,
      -1,   109,    -1,   111,    -1,   113,    -1,    -1,    -1,    -1,
     118,    -1,   120,    -1,    -1,    -1,   124,   125,    -1,    -1,
      -1,    -1,    -1,   817,    -1,    -1,    -1,    75,    76,   823,
      -1,   825,    -1,    -1,    -1,   829,    -1,   831,    -1,    -1,
      -1,    -1,   836,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,   175,   176,   177,
     178,   179,   180,   181,    -1,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,    15,    16,    17,    18,    19,    20,   245,    -1,    -1,
      -1,    -1,   250,   251,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
      -1,    -1,    -1,    -1,   282,    -1,    -1,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,     9,    -1,   314,   315,   316,   317,
     318,    -1,    -1,    -1,    19,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,   750,    -1,   347,
      29,    -1,    -1,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    -1,    -1,   767,    16,    -1,   770,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,   780,    29,    74,
      -1,    -1,    -1,    -1,    -1,   788,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    75,    76,    16,    -1,
      -1,    -1,    97,    -1,    99,    -1,    24,    -1,    -1,    -1,
     813,    29,   815,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    13,    75,    76,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    29,
     843,    -1,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,    -1,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,
      -1,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    -1,    -1,    14,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    -1,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      56,    57,    58,    29,    -1,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    -1,    -1,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
      -1,    -1,    -1,    16,    -1,     4,     5,     6,     7,     8,
       9,    24,    11,    -1,    -1,    -1,    29,    16,    -1,    -1,
      -1,    -1,    -1,    -1,   319,    24,    -1,    -1,    -1,     9,
      29,    11,    -1,   328,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    25,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    39,
      -1,    -1,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    10,    11,    -1,    75,    76,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,     9,    39,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    -1,    22,    23,    -1,    25,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    39,     9,    -1,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    -1,    22,    -1,    -1,    25,    26,
      27,    28,   750,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,   767,
      -1,    -1,   770,    -1,    -1,    -1,    -1,     9,    -1,    11,
      -1,    -1,   780,    15,    16,    17,    18,    19,    20,    -1,
     788,    -1,    -1,    25,    26,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    39,    -1,    -1,
      -1,    -1,     9,    -1,    11,   813,    -1,   815,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,     9,    39,    11,    -1,   843,    -1,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,    -1,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
       9,    39,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,     9,
      39,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,   634,
      15,    16,    17,    18,    19,    20,    21,   642,    -1,    -1,
      25,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    10,    -1,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    10,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    25,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   744,
      -1,    -1,    -1,   748,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,   776,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,   817,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,   829,    -1,   831,    -1,    -1,    -1,
      -1,   836,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      37,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    25,    15,    16,    17,    18,    19,
      20,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    37,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      54,    55
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,     0,     3,     4,     5,     6,     7,     8,     9,    11,
      16,    24,    29,    56,    57,    58,    61,    62,    63,    64,
      65,    66,    67,    69,    70,    71,    72,    73,    74,    75,
      76,    79,    80,    81,    82,    85,    87,    88,    89,    90,
      91,    92,    94,    97,   101,   102,   103,   105,   106,   107,
     109,   110,   113,   114,   117,   118,   119,   120,   121,   123,
     125,     8,    75,   106,   107,   109,   110,   111,   113,   114,
     117,   118,   119,   120,     3,    12,    75,   105,   108,     9,
      16,    75,    76,   117,   118,     9,   113,   117,   118,   119,
     120,     9,    16,   117,    75,    75,    86,     9,     9,     9,
       3,    13,    82,    83,    84,   105,    75,    11,    68,    11,
      68,    11,    68,    11,    68,    75,    75,    98,    11,    13,
      39,    68,   112,   115,    11,    39,   112,     0,     0,     1,
      81,     3,     3,     3,     3,     3,     3,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    54,    55,
       9,    11,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    25,    26,    27,    28,    30,    31,    32,    33,    34,
      35,    36,    37,    39,   112,    11,    15,    16,    17,    25,
      32,    33,   112,    21,    25,    32,    33,    21,    25,    32,
      33,    15,    16,    17,    18,    19,    20,    21,    25,    26,
      27,    28,    30,    31,    32,    33,    34,    35,    36,    37,
      15,    16,    17,    18,    19,    20,    21,    25,    32,    33,
      34,    35,    36,    37,    11,    21,    25,    32,    33,    34,
      35,    36,    37,    21,    22,    23,    25,    32,    33,    68,
      68,     9,    75,    98,    10,    11,   115,    10,    10,    10,
      38,    40,    10,    10,    10,    10,   108,    40,     3,    12,
     117,   118,    15,    16,    17,    18,    19,    26,    27,    28,
      30,    31,    15,    16,    17,    18,    19,    20,   117,   118,
     119,   120,    21,    32,    33,    21,    32,    33,    34,    35,
      36,    37,    21,    32,    33,    34,    35,    36,    37,    21,
      25,    32,    33,    34,    35,    36,    37,    21,    22,    23,
      32,    33,   117,   117,    15,    16,    17,    18,    19,    42,
      40,   105,    75,   105,    13,    14,    80,    62,    42,    12,
     106,   111,   117,   118,   119,   120,   124,    12,   124,    12,
     124,    12,   124,     3,    13,     9,    12,    41,   111,   124,
      14,    39,   116,   106,   117,   111,   106,    81,   103,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,    10,   104,   105,   111,   106,   109,   117,   118,
     106,   109,   117,   118,   106,   109,   117,   118,   106,   117,
     118,   106,   117,   118,   106,   118,   106,   113,   114,   117,
     118,   119,   120,   106,   120,   106,   120,   106,   119,   106,
     117,   106,   117,   106,   117,   106,   117,   106,   117,   106,
     109,   113,   114,   117,   118,   119,   120,   106,   109,   113,
     114,   117,   118,   119,   120,   106,   117,   118,   119,   106,
     117,   118,   119,   106,   117,   118,   119,   106,   117,   118,
     119,   106,   111,   106,   109,   106,   109,   106,   109,   106,
     109,   106,   109,   106,   109,   106,   113,   114,   117,   118,
     119,   120,   106,   109,   106,   113,   106,   113,   106,   113,
     114,   117,   118,   119,   120,   106,   109,   106,   114,   106,
     114,   106,   117,   118,   106,   117,   118,   106,   117,   118,
     106,   117,   118,   106,   117,   118,   117,   118,   106,   113,
     114,   117,   118,   119,   120,   106,   109,   106,   117,   106,
     117,   106,   117,   106,   117,   106,   117,   106,   117,   118,
     106,   117,   118,   106,   117,   118,   106,   117,   118,   106,
     117,   118,   106,   117,   118,   106,   117,   118,   106,   117,
     118,   106,   117,   118,   106,   117,   118,   106,   117,   118,
     106,   117,   118,   106,   113,   114,   117,   118,   119,   120,
     106,   109,   106,   117,   118,   106,   117,   118,   106,   117,
     118,   106,   117,   118,   106,   117,   118,   106,   117,   118,
     111,   106,   113,   114,   117,   118,   119,   120,   106,   109,
     119,   106,   119,   106,   119,   106,   119,   106,   119,   106,
     119,   106,   119,   106,   113,   114,   117,   118,   119,   120,
     106,   120,   106,   120,   106,   109,   106,   120,   106,   120,
      10,    75,   122,   125,    42,     9,   111,    10,   111,   111,
       3,    12,     3,   108,    12,   117,   118,   117,   118,   117,
     118,   117,   118,   117,   118,   117,   117,   117,   117,   117,
     117,   118,   117,   118,   117,   118,   117,   118,   117,   118,
     117,   118,   113,   117,   118,   119,   120,     9,   113,   113,
     113,   117,   118,   119,   120,   117,   118,   117,   118,   117,
     118,   117,   118,   117,   118,   117,   118,   113,   117,   118,
     119,   120,   117,   118,   117,   118,   117,   118,   117,   118,
     117,   118,   117,   118,   113,   117,   118,   119,   120,   119,
     120,   119,   119,   119,   119,   119,   119,   113,   117,   118,
     119,   120,   120,   120,   120,   120,   117,   117,   117,   117,
     117,   105,    86,    10,    41,    10,    80,    14,     9,   105,
      40,    12,    12,    12,    12,    13,     3,    14,    56,    95,
      96,   125,    10,    99,   100,   125,    12,    41,   111,    12,
      41,    12,    75,    14,    12,    10,    40,    12,    12,    12,
      11,    10,    40,   105,   115,    10,    99,    10,    38,    12,
     108,     8,    84,   105,    84,    14,     3,   105,   124,    95,
      95,    75,    14,     3,    75,    83,    10,    40,    40,    75,
      12,   111,    12,    41,    12,    41,   111,    42,   104,   122,
      83,    10,   111,    60,    93,    10,     3,    10,    14,    42,
      95,    42,    83,   125,   100,   125,    42,    12,    12,   111,
      12,   111,    12,    41,   105,    83,    10,    84,    84,   105,
     105,    75,    75,   105,    12,    12,    12,   111,    40,    12,
     116
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    78,    79,    79,    80,    80,    80,    81,    81,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    83,    83,    83,    83,    83,    84,    84,    85,    86,
      86,    87,    87,    87,    88,    88,    89,    90,    91,    92,
      93,    93,    94,    94,    94,    95,    95,    95,    95,    96,
      96,    96,    97,    97,    97,    97,    98,    99,    99,    99,
     100,   100,   101,   102,   102,   102,   102,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   104,   104,   105,   105,   105,   105,   105,   105,   105,
     105,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     107,   107,   107,   107,   107,   108,   108,   108,   109,   109,
     109,   109,   110,   110,   111,   111,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   113,   113,
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
     125,   125,   125,   125,   125,   125,   125,   125
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     1,     2,     1,     2,     3,     1,     1,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     3,     4,     4,     5,     1,     1,     2,     1,
       3,     1,     1,     1,     1,     2,     7,     5,     6,     6,
       2,     0,     4,     5,     6,     1,     2,     2,     3,     2,
       4,     4,     5,     6,     5,     6,     1,     2,     1,     4,
       4,     3,     2,     4,     4,     4,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     3,     4,     4,     4,
       4,     4,     4,     2,     2,     2,     2,     3,     3,     3,
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
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     4,     4,     5,     1,     3,     4,     1,     1,
       3,     3,     5,     7,     1,     1,     3,     4,     4,     5,
       4,     5,     5,     5,     6,     6,     6,     7,     1,     3,
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
       2,     1,     1,     1,     1,     1,     1,     1
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
  "\"?\"", "\"'int'\"", "\"'float'\"", "\"'string'\"", "\"'bool'\"",
  "\"'struct'\"", "\"'void'\"", "\"identifier\"",
  "\"external identifier\"", "NEG", "$accept", "start", "stmt", "stmts",
  "stmts_ne", "block", "body", "import", "id_list", "flowctl", "return",
  "for", "while", "dowhile", "if", "else", "struct", "decllist",
  "declistval", "function", "fun_id", "funargs", "funargdef", "vardecl",
  "vardef", "set", "callarglist", "expr", "expr_var", "matrix", "matvals",
  "expr_mat", "range", "int_val", "slice", "expr_none", "expr_struct",
  "struct_val", "struct_list", "expr_int", "expr_float", "expr_str",
  "expr_bool", "funtype", "typelist", "mattype", "matsize", "type", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   218,   218,   219,   221,   222,   223,   227,   228,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   245,   246,   247,   248,   249,   252,   253,   257,   259,
     260,   264,   265,   266,   268,   269,   273,   277,   280,   284,
     290,   291,   295,   296,   297,   299,   300,   301,   302,   304,
     305,   306,   310,   311,   312,   313,   315,   317,   318,   319,
     321,   322,   326,   330,   331,   332,   333,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   354,   355,   359,   360,   361,   362,   363,   364,   365,
     366,   369,   370,   371,   372,   373,   375,   376,   378,   379,
     380,   381,   382,   384,   385,   386,   387,   389,   390,   391,
     393,   394,   395,   397,   398,   399,   400,   401,   402,   403,
     404,   406,   407,   408,   409,   410,   412,   413,   414,   415,
     416,   418,   419,   420,   421,   422,   423,   424,   425,   427,
     428,   429,   430,   431,   432,   433,   434,   436,   437,   438,
     440,   441,   442,   444,   445,   446,   447,   448,   449,   450,
     452,   453,   454,   455,   456,   457,   458,   460,   461,   462,
     463,   464,   465,   466,   468,   469,   470,   471,   472,   473,
     474,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   512,   513,   514,   516,   517,
     518,   520,   521,   522,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     541,   542,   543,   545,   546,   547,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     576,   577,   578,   579,   580,   582,   583,   584,   588,   589,
     590,   591,   593,   594,   596,   597,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   614,   615,
     619,   620,   622,   623,   625,   626,   630,   631,   632,   633,
     634,   635,   636,   637,   638,   639,   640,   641,   642,   643,
     647,   648,   649,   650,   651,   652,   653,   654,   655,   656,
     657,   658,   659,   660,   661,   662,   663,   664,   665,   666,
     667,   671,   672,   673,   674,   675,   676,   677,   678,   679,
     680,   681,   682,   683,   684,   685,   686,   687,   688,   689,
     690,   691,   692,   693,   694,   695,   696,   697,   701,   702,
     703,   704,   705,   707,   708,   709,   710,   711,   712,   713,
     715,   716,   717,   718,   719,   720,   721,   723,   724,   725,
     726,   727,   729,   730,   731,   732,   733,   735,   736,   737,
     738,   739,   741,   742,   743,   744,   745,   747,   751,   752,
     754,   755,   759,   760,   761,   762,   763,   764,   765,   766,
     767,   768,   770,   771,   775,   776,   777,   778,   779,   780,
     781,   782,   783,   784,   785,   786,   787,   788
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
    return static_cast<symbol_kind_type> (t);
  }

#line 14 "frontend/parser.yy"
} //  ptc 
#line 4491 "frontend/parser.cpp"

#line 791 "frontend/parser.yy"


/* Error method */
void ptc::Parser::error(const location_type &l, const std::string &err_message) {
    auto msg = std::to_string(scanner->loc->begin.line) + ":" + std::to_string(scanner->loc->begin.column) + ": " + err_message;
    scanner->fatal_error(ptc::diag::ERR_SYNTAX, msg);
}
