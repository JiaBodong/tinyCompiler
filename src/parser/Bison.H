/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_JAVALETTE_BISON_H_INCLUDED
# define YY_JAVALETTE_BISON_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int javalette_debug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    _ERROR_ = 258,                 /* _ERROR_  */
    _BANG = 259,                   /* _BANG  */
    _BANGEQ = 260,                 /* _BANGEQ  */
    _PERCENT = 261,                /* _PERCENT  */
    _DAMP = 262,                   /* _DAMP  */
    _LPAREN = 263,                 /* _LPAREN  */
    _RPAREN = 264,                 /* _RPAREN  */
    _STAR = 265,                   /* _STAR  */
    _PLUS = 266,                   /* _PLUS  */
    _DPLUS = 267,                  /* _DPLUS  */
    _COMMA = 268,                  /* _COMMA  */
    _MINUS = 269,                  /* _MINUS  */
    _DMINUS = 270,                 /* _DMINUS  */
    _DOT = 271,                    /* _DOT  */
    _SLASH = 272,                  /* _SLASH  */
    _COLON = 273,                  /* _COLON  */
    _SEMI = 274,                   /* _SEMI  */
    _LT = 275,                     /* _LT  */
    _LDARROW = 276,                /* _LDARROW  */
    _EQ = 277,                     /* _EQ  */
    _DEQ = 278,                    /* _DEQ  */
    _GT = 279,                     /* _GT  */
    _GTEQ = 280,                   /* _GTEQ  */
    _LBRACK = 281,                 /* _LBRACK  */
    _EMPTYBRACK = 282,             /* _EMPTYBRACK  */
    _RBRACK = 283,                 /* _RBRACK  */
    _KW_boolean = 284,             /* _KW_boolean  */
    _KW_double = 285,              /* _KW_double  */
    _KW_else = 286,                /* _KW_else  */
    _KW_false = 287,               /* _KW_false  */
    _KW_for = 288,                 /* _KW_for  */
    _KW_if = 289,                  /* _KW_if  */
    _KW_int = 290,                 /* _KW_int  */
    _KW_new = 291,                 /* _KW_new  */
    _KW_return = 292,              /* _KW_return  */
    _KW_true = 293,                /* _KW_true  */
    _KW_void = 294,                /* _KW_void  */
    _KW_while = 295,               /* _KW_while  */
    _LBRACE = 296,                 /* _LBRACE  */
    _DBAR = 297,                   /* _DBAR  */
    _RBRACE = 298,                 /* _RBRACE  */
    _STRING_ = 299,                /* _STRING_  */
    _INTEGER_ = 300,               /* _INTEGER_  */
    _DOUBLE_ = 301,                /* _DOUBLE_  */
    _IDENT_ = 302                  /* _IDENT_  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 50 "Javalette.y"

  int    _int;
  char   _char;
  double _double;
  char*  _string;
  Prog* prog_;
  TopDef* topdef_;
  ListTopDef* listtopdef_;
  Arg* arg_;
  ListArg* listarg_;
  Blk* blk_;
  ListStmt* liststmt_;
  Stmt* stmt_;
  Item* item_;
  ListItem* listitem_;
  Type* type_;
  ListType* listtype_;
  Expr* expr_;
  ListExpr* listexpr_;
  AddOp* addop_;
  MulOp* mulop_;
  RelOp* relop_;

#line 135 "Bison.H"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int javalette_parse (yyscan_t scanner, YYSTYPE *result);

#endif /* !YY_JAVALETTE_BISON_H_INCLUDED  */
