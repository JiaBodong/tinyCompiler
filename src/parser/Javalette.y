/* -*- c++ -*- File generated by the BNF Converter (bnfc 2.9.4). */

/* Parser definition to be used with Bison. */

/* Generate header file for lexer. */
%defines "Bison.H"

/* Reentrant parser */
%pure_parser
  /* From Bison 2.3b (2008): %define api.pure full */
%lex-param   { yyscan_t scanner }
%parse-param { yyscan_t scanner }

/* Turn on line/column tracking in the javalette_lloc structure: */
%locations

/* Argument to the parser to be filled with the parsed tree. */
%parse-param { YYSTYPE *result }

%{
/* Begin C preamble code */

#include <algorithm> /* for std::reverse */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Absyn.H"

#define YYMAXDEPTH 10000000

/* The type yyscan_t is defined by flex, but we need it in the parser already. */
#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif

typedef struct yy_buffer_state *YY_BUFFER_STATE;
extern YY_BUFFER_STATE javalette__scan_string(const char *str, yyscan_t scanner);
extern void javalette__delete_buffer(YY_BUFFER_STATE buf, yyscan_t scanner);

extern void javalette_lex_destroy(yyscan_t scanner);
extern char* javalette_get_text(yyscan_t scanner);

extern yyscan_t javalette__initialize_lexer(FILE * inp);

/* End C preamble code */
%}

%union
{
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
}

%{
void yyerror(YYLTYPE *loc, yyscan_t scanner, YYSTYPE *result, const char *msg)
{
  fprintf(stderr, "error: %d,%d: %s at %s\n",
    loc->first_line, loc->first_column, msg, javalette_get_text(scanner));
}

int yyparse(yyscan_t scanner, YYSTYPE *result);

extern int yylex(YYSTYPE *lvalp, YYLTYPE *llocp, yyscan_t scanner);
%}

%token          _ERROR_
%token          _BANG        /* ! */
%token          _BANGEQ      /* != */
%token          _PERCENT     /* % */
%token          _DAMP        /* && */
%token          _LPAREN      /* ( */
%token          _RPAREN      /* ) */
%token          _STAR        /* * */
%token          _PLUS        /* + */
%token          _DPLUS       /* ++ */
%token          _COMMA       /* , */
%token          _MINUS       /* - */
%token          _DMINUS      /* -- */
%token          _DOT         /* . */
%token          _SLASH       /* / */
%token          _COLON       /* : */
%token          _SEMI        /* ; */
%token          _LT          /* < */
%token          _LDARROW     /* <= */
%token          _EQ          /* = */
%token          _DEQ         /* == */
%token          _GT          /* > */
%token          _GTEQ        /* >= */
%token          _LBRACK      /* [ */
%token          _EMPTYBRACK  /* [] */
%token          _RBRACK      /* ] */
%token          _KW_boolean  /* boolean */
%token          _KW_double   /* double */
%token          _KW_else     /* else */
%token          _KW_false    /* false */
%token          _KW_for      /* for */
%token          _KW_if       /* if */
%token          _KW_int      /* int */
%token          _KW_new      /* new */
%token          _KW_return   /* return */
%token          _KW_true     /* true */
%token          _KW_void     /* void */
%token          _KW_while    /* while */
%token          _LBRACE      /* { */
%token          _DBAR        /* || */
%token          _RBRACE      /* } */
%token<_string> _STRING_
%token<_int>    _INTEGER_
%token<_double> _DOUBLE_
%token<_string> _IDENT_

%type <prog_> Prog
%type <topdef_> TopDef
%type <listtopdef_> ListTopDef
%type <arg_> Arg
%type <listarg_> ListArg
%type <blk_> Blk
%type <liststmt_> ListStmt
%type <stmt_> Stmt
%type <item_> Item
%type <listitem_> ListItem
%type <type_> Type
%type <listtype_> ListType
%type <expr_> Expr6
%type <expr_> Expr5
%type <expr_> Expr4
%type <expr_> Expr3
%type <expr_> Expr2
%type <expr_> Expr1
%type <expr_> Expr
%type <listexpr_> ListExpr
%type <addop_> AddOp
%type <mulop_> MulOp
%type <relop_> RelOp

%start Prog

%%

Prog : ListTopDef { std::reverse($1->begin(),$1->end()) ;$$ = new Program($1); result->prog_ = $$; }
;
TopDef : Type _IDENT_ _LPAREN ListArg _RPAREN Blk { std::reverse($4->begin(),$4->end()) ;$$ = new FnDef($1, $2, $4, $6); }
;
ListTopDef : TopDef { $$ = new ListTopDef(); $$->push_back($1); }
  | TopDef ListTopDef { $2->push_back($1); $$ = $2; }
;
Arg : Type _IDENT_ { $$ = new Argument($1, $2); }
;
ListArg : /* empty */ { $$ = new ListArg(); }
  | Arg { $$ = new ListArg(); $$->push_back($1); }
  | Arg _COMMA ListArg { $3->push_back($1); $$ = $3; }
;
Blk : _LBRACE ListStmt _RBRACE { $$ = new Block($2); }
;
ListStmt : /* empty */ { $$ = new ListStmt(); }
  | ListStmt Stmt { $1->push_back($2); $$ = $1; }
;
Stmt : _SEMI { $$ = new Empty(); }
  | Blk { $$ = new BStmt($1); }
  | Type ListItem _SEMI { std::reverse($2->begin(),$2->end()) ;$$ = new Decl($1, $2); }
  | _IDENT_ _EQ Expr _SEMI { $$ = new Ass($1, $3); }
  | Expr _EQ Expr _SEMI { $$ = new ArrayAss($1, $3); }
  | _IDENT_ _DPLUS _SEMI { $$ = new Incr($1); }
  | _IDENT_ _DMINUS _SEMI { $$ = new Decr($1); }
  | _KW_return Expr _SEMI { $$ = new Ret($2); }
  | _KW_return _SEMI { $$ = new VRet(); }
  | _KW_if _LPAREN Expr _RPAREN Stmt { $$ = new Cond($3, $5); }
  | _KW_if _LPAREN Expr _RPAREN Stmt _KW_else Stmt { $$ = new CondElse($3, $5, $7); }
  | _KW_while _LPAREN Expr _RPAREN Stmt { $$ = new While($3, $5); }
  | _LPAREN Type Item _RPAREN Stmt { $$ = new ForBlk($2, $3, $5); }
  | _KW_for Stmt { $$ = new ForLoop($2); }
  | Expr _SEMI { $$ = new SExp($1); }
;
Item : _IDENT_ { $$ = new NoInit($1); }
  | _IDENT_ _EQ Expr { $$ = new Init($1, $3); }
  | _IDENT_ _COLON Expr { $$ = new InitElem($1, $3); }
;
ListItem : Item { $$ = new ListItem(); $$->push_back($1); }
  | Item _COMMA ListItem { $3->push_back($1); $$ = $3; }
;
Type : _KW_int { $$ = new Int(); }
  | _KW_double { $$ = new Doub(); }
  | _KW_boolean { $$ = new Bool(); }
  | _KW_void { $$ = new Void(); }
  | _KW_int _EMPTYBRACK { $$ = new IntArray(); }
  | _KW_double _EMPTYBRACK { $$ = new DoubArray(); }
  | _KW_boolean _EMPTYBRACK { $$ = new BoolArray(); }
;
ListType : /* empty */ { $$ = new ListType(); }
  | Type { $$ = new ListType(); $$->push_back($1); }
  | Type _COMMA ListType { $3->push_back($1); $$ = $3; }
;
Expr6 : _IDENT_ { $$ = new EVar($1); }
  | _INTEGER_ { $$ = new ELitInt($1); }
  | _DOUBLE_ { $$ = new ELitDoub($1); }
  | _KW_true { $$ = new ELitTrue(); }
  | _KW_false { $$ = new ELitFalse(); }
  | _IDENT_ _LPAREN ListExpr _RPAREN { std::reverse($3->begin(),$3->end()) ;$$ = new EApp($1, $3); }
  | _STRING_ { $$ = new EString($1); }
  | _KW_new Type _LBRACK Expr6 _RBRACK { $$ = new EArrayNew($2, $4); }
  | Expr6 _DOT Expr6 { $$ = new EArrayLen($1, $3); }
  | _LPAREN Expr _RPAREN { $$ = $2; }
;
Expr5 : Expr6 _LBRACK Expr _RBRACK { $$ = new EArray($1, $3); }
  | _MINUS Expr6 { $$ = new Neg($2); }
  | _BANG Expr6 { $$ = new Not($2); }
  | Expr6 { $$ = $1; }
;
Expr4 : Expr4 MulOp Expr5 { $$ = new EMul($1, $2, $3); }
  | Expr5 { $$ = $1; }
;
Expr3 : Expr3 AddOp Expr4 { $$ = new EAdd($1, $2, $3); }
  | Expr4 { $$ = $1; }
;
Expr2 : Expr2 RelOp Expr3 { $$ = new ERel($1, $2, $3); }
  | Expr3 { $$ = $1; }
;
Expr1 : Expr2 _DAMP Expr1 { $$ = new EAnd($1, $3); }
  | Expr2 { $$ = $1; }
;
Expr : Expr1 _DBAR Expr { $$ = new EOr($1, $3); }
  | Expr1 { $$ = $1; }
;
ListExpr : /* empty */ { $$ = new ListExpr(); }
  | Expr { $$ = new ListExpr(); $$->push_back($1); }
  | Expr _COMMA ListExpr { $3->push_back($1); $$ = $3; }
;
AddOp : _PLUS { $$ = new Plus(); }
  | _MINUS { $$ = new Minus(); }
;
MulOp : _STAR { $$ = new Times(); }
  | _SLASH { $$ = new Div(); }
  | _PERCENT { $$ = new Mod(); }
;
RelOp : _LT { $$ = new LTH(); }
  | _LDARROW { $$ = new LE(); }
  | _GT { $$ = new GTH(); }
  | _GTEQ { $$ = new GE(); }
  | _DEQ { $$ = new EQU(); }
  | _BANGEQ { $$ = new NE(); }
;

%%


/* Entrypoint: parse Prog* from file. */
Prog* pProg(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = javalette__initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  javalette_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.prog_;
  }
}

/* Entrypoint: parse Prog* from string. */
Prog* psProg(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = javalette__initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = javalette__scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  javalette__delete_buffer(buf, scanner);
  javalette_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.prog_;
  }
}



