/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         javalette_parse
#define yylex           javalette_lex
#define yyerror         javalette_error
#define yydebug         javalette_debug
#define yynerrs         javalette_nerrs

/* First part of user prologue.  */
#line 20 "Javalette.y"

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

#line 105 "Parser.C"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "Bison.H"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL__ERROR_ = 3,                    /* _ERROR_  */
  YYSYMBOL__BANG = 4,                      /* _BANG  */
  YYSYMBOL__BANGEQ = 5,                    /* _BANGEQ  */
  YYSYMBOL__PERCENT = 6,                   /* _PERCENT  */
  YYSYMBOL__DAMP = 7,                      /* _DAMP  */
  YYSYMBOL__LPAREN = 8,                    /* _LPAREN  */
  YYSYMBOL__RPAREN = 9,                    /* _RPAREN  */
  YYSYMBOL__STAR = 10,                     /* _STAR  */
  YYSYMBOL__PLUS = 11,                     /* _PLUS  */
  YYSYMBOL__DPLUS = 12,                    /* _DPLUS  */
  YYSYMBOL__COMMA = 13,                    /* _COMMA  */
  YYSYMBOL__MINUS = 14,                    /* _MINUS  */
  YYSYMBOL__DMINUS = 15,                   /* _DMINUS  */
  YYSYMBOL__DOT = 16,                      /* _DOT  */
  YYSYMBOL__SLASH = 17,                    /* _SLASH  */
  YYSYMBOL__COLON = 18,                    /* _COLON  */
  YYSYMBOL__SEMI = 19,                     /* _SEMI  */
  YYSYMBOL__LT = 20,                       /* _LT  */
  YYSYMBOL__LDARROW = 21,                  /* _LDARROW  */
  YYSYMBOL__EQ = 22,                       /* _EQ  */
  YYSYMBOL__DEQ = 23,                      /* _DEQ  */
  YYSYMBOL__GT = 24,                       /* _GT  */
  YYSYMBOL__GTEQ = 25,                     /* _GTEQ  */
  YYSYMBOL__LBRACK = 26,                   /* _LBRACK  */
  YYSYMBOL__EMPTYBRACK = 27,               /* _EMPTYBRACK  */
  YYSYMBOL__RBRACK = 28,                   /* _RBRACK  */
  YYSYMBOL__KW_boolean = 29,               /* _KW_boolean  */
  YYSYMBOL__KW_double = 30,                /* _KW_double  */
  YYSYMBOL__KW_else = 31,                  /* _KW_else  */
  YYSYMBOL__KW_false = 32,                 /* _KW_false  */
  YYSYMBOL__KW_for = 33,                   /* _KW_for  */
  YYSYMBOL__KW_if = 34,                    /* _KW_if  */
  YYSYMBOL__KW_int = 35,                   /* _KW_int  */
  YYSYMBOL__KW_new = 36,                   /* _KW_new  */
  YYSYMBOL__KW_return = 37,                /* _KW_return  */
  YYSYMBOL__KW_true = 38,                  /* _KW_true  */
  YYSYMBOL__KW_void = 39,                  /* _KW_void  */
  YYSYMBOL__KW_while = 40,                 /* _KW_while  */
  YYSYMBOL__LBRACE = 41,                   /* _LBRACE  */
  YYSYMBOL__DBAR = 42,                     /* _DBAR  */
  YYSYMBOL__RBRACE = 43,                   /* _RBRACE  */
  YYSYMBOL__STRING_ = 44,                  /* _STRING_  */
  YYSYMBOL__INTEGER_ = 45,                 /* _INTEGER_  */
  YYSYMBOL__DOUBLE_ = 46,                  /* _DOUBLE_  */
  YYSYMBOL__IDENT_ = 47,                   /* _IDENT_  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_Prog = 49,                      /* Prog  */
  YYSYMBOL_TopDef = 50,                    /* TopDef  */
  YYSYMBOL_ListTopDef = 51,                /* ListTopDef  */
  YYSYMBOL_Arg = 52,                       /* Arg  */
  YYSYMBOL_ListArg = 53,                   /* ListArg  */
  YYSYMBOL_Blk = 54,                       /* Blk  */
  YYSYMBOL_ListStmt = 55,                  /* ListStmt  */
  YYSYMBOL_Stmt = 56,                      /* Stmt  */
  YYSYMBOL_Item = 57,                      /* Item  */
  YYSYMBOL_ListItem = 58,                  /* ListItem  */
  YYSYMBOL_Type = 59,                      /* Type  */
  YYSYMBOL_Expr6 = 60,                     /* Expr6  */
  YYSYMBOL_Expr5 = 61,                     /* Expr5  */
  YYSYMBOL_Expr4 = 62,                     /* Expr4  */
  YYSYMBOL_Expr3 = 63,                     /* Expr3  */
  YYSYMBOL_Expr2 = 64,                     /* Expr2  */
  YYSYMBOL_Expr1 = 65,                     /* Expr1  */
  YYSYMBOL_Expr = 66,                      /* Expr  */
  YYSYMBOL_ListExpr = 67,                  /* ListExpr  */
  YYSYMBOL_AddOp = 68,                     /* AddOp  */
  YYSYMBOL_MulOp = 69,                     /* MulOp  */
  YYSYMBOL_RelOp = 70                      /* RelOp  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 74 "Javalette.y"

void yyerror(YYLTYPE *loc, yyscan_t scanner, YYSTYPE *result, const char *msg)
{
  fprintf(stderr, "error: %d,%d: %s at %s\n",
    loc->first_line, loc->first_column, msg, javalette_get_text(scanner));
}

int yyparse(yyscan_t scanner, YYSTYPE *result);

extern int yylex(YYSTYPE *lvalp, YYLTYPE *llocp, yyscan_t scanner);

#line 221 "Parser.C"


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   225

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  133

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   160,   160,   162,   164,   165,   167,   169,   170,   171,
     173,   175,   176,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   194,   195,
     196,   198,   199,   201,   202,   203,   204,   205,   206,   207,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     224,   225,   226,   227,   229,   230,   232,   233,   235,   236,
     238,   239,   241,   242,   244,   245,   246,   248,   249,   251,
     252,   253,   255,   256,   257,   258,   259,   260
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "_ERROR_", "_BANG",
  "_BANGEQ", "_PERCENT", "_DAMP", "_LPAREN", "_RPAREN", "_STAR", "_PLUS",
  "_DPLUS", "_COMMA", "_MINUS", "_DMINUS", "_DOT", "_SLASH", "_COLON",
  "_SEMI", "_LT", "_LDARROW", "_EQ", "_DEQ", "_GT", "_GTEQ", "_LBRACK",
  "_EMPTYBRACK", "_RBRACK", "_KW_boolean", "_KW_double", "_KW_else",
  "_KW_false", "_KW_for", "_KW_if", "_KW_int", "_KW_new", "_KW_return",
  "_KW_true", "_KW_void", "_KW_while", "_LBRACE", "_DBAR", "_RBRACE",
  "_STRING_", "_INTEGER_", "_DOUBLE_", "_IDENT_", "$accept", "Prog",
  "TopDef", "ListTopDef", "Arg", "ListArg", "Blk", "ListStmt", "Stmt",
  "Item", "ListItem", "Type", "Expr6", "Expr5", "Expr4", "Expr3", "Expr2",
  "Expr1", "Expr", "ListExpr", "AddOp", "MulOp", "RelOp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302
};
#endif

#define YYPACT_NINF (-32)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,    -3,    12,    23,   -32,    32,     5,   -32,    14,   -32,
     -32,   -32,   -32,   -32,    46,     5,    43,    54,    18,     5,
      25,   -32,   -32,   -32,   -32,    74,    97,    13,    97,   -32,
     -32,   118,    59,     5,   162,   -32,    66,   -32,   -32,   -32,
     -32,    -2,   -32,   -32,    28,   -11,   -32,     6,     0,    48,
      37,     9,   178,    72,    65,    28,    76,    65,   -32,   178,
      61,   -32,    70,   178,   178,    71,    75,   178,     7,    78,
      77,    97,   178,   -32,   -32,   -32,   178,   -32,   -32,   178,
     -32,   178,   -32,   -32,   -32,   -32,   -32,   178,   178,   -32,
     178,    86,   -32,    88,    97,   -32,    89,   103,    90,   -32,
     -32,    82,   178,   178,    28,   -32,    65,    95,   -32,     6,
     -32,     0,   -32,    83,   118,   118,    -9,   118,   178,   -32,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,    93,   -32,   -32,
     -32,   118,   -32
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    35,    34,    33,    36,     0,     4,     2,     0,    39,
      38,    37,     1,     5,     0,     7,     8,     0,     0,     7,
       0,     6,     9,    11,     3,     0,     0,     0,     0,    13,
      44,     0,     0,     0,     0,    43,     0,    10,    46,    41,
      42,    40,    14,    12,     0,    53,    55,    57,    59,    61,
      63,     0,     0,    40,    52,     0,     0,    51,    26,     0,
       0,    21,     0,     0,    64,     0,     0,     0,    28,    31,
       0,     0,     0,    71,    69,    70,     0,    67,    68,     0,
      77,     0,    72,    73,    76,    74,    75,     0,     0,    27,
       0,     0,    49,     0,     0,    20,     0,    65,     0,    18,
      19,     0,     0,     0,     0,    15,    48,     0,    54,    56,
      60,    58,    62,     0,     0,     0,     0,     0,    64,    45,
      16,    30,    29,    32,    50,    17,    25,    22,    47,    24,
      66,     0,    23
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -32,   -32,   -32,   119,   -32,   108,   110,   -32,   -31,    73,
      27,     3,   -24,    58,    57,    51,   -32,    64,   -26,    21,
     -32,   -32,   -32
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,     7,    16,    17,    42,    25,    43,    69,
      70,    44,    45,    46,    47,    48,    49,    50,    51,    98,
      79,    76,    87
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      58,    56,    54,     8,    57,    71,    64,    71,    62,     8,
      65,    77,    73,    66,    78,    72,    74,    26,    18,   128,
      67,    52,    18,    75,     9,   102,    56,    28,    89,   103,
      55,    90,    12,    93,     1,     2,    60,    96,    97,    10,
       3,   101,     1,     2,     4,    30,   107,   106,     3,    33,
      11,    35,     4,    80,    15,    81,    19,    38,    39,    40,
      53,    14,   112,    20,   113,    21,    23,    59,    82,    83,
     116,    84,    85,    86,    63,    68,   121,   122,    26,    88,
      64,    71,    27,   126,   127,    92,   129,    94,    28,    95,
      99,   104,    97,    29,   100,   114,   105,   115,   117,   119,
     132,   120,   125,     1,     2,    52,    30,    31,    32,     3,
      33,    34,    35,     4,    36,    23,   118,    37,    38,    39,
      40,    41,    26,   124,   131,    13,    27,    22,    91,    30,
      24,   123,    28,    33,   108,    35,   109,    29,   111,   130,
       0,    38,    39,    40,    53,   110,     0,     1,     2,     0,
      30,    31,    32,     3,    33,    34,    35,     4,    36,    23,
       0,     0,    38,    39,    40,    41,    26,     0,     0,     0,
      52,     0,     0,     0,     0,     0,    28,     0,     0,     0,
       0,    61,    26,     0,     0,     0,    52,     0,     0,     0,
       0,     0,    28,     0,    30,     0,     0,     0,    33,     0,
      35,     0,     0,     0,     0,     0,    38,    39,    40,    53,
      30,     0,     0,     0,    33,     0,    35,     0,     0,     0,
       0,     0,    38,    39,    40,    53
};

static const yytype_int16 yycheck[] =
{
      31,    27,    26,     0,    28,    16,     8,    16,    34,     6,
      12,    11,     6,    15,    14,    26,    10,     4,    15,    28,
      22,     8,    19,    17,    27,    18,    52,    14,    19,    22,
      27,    22,     0,    59,    29,    30,    33,    63,    64,    27,
      35,    67,    29,    30,    39,    32,    72,    71,    35,    36,
      27,    38,    39,     5,     8,     7,    13,    44,    45,    46,
      47,    47,    88,     9,    90,    47,    41,     8,    20,    21,
      94,    23,    24,    25,     8,    47,   102,   103,     4,    42,
       8,    16,     8,   114,   115,     9,   117,    26,    14,    19,
      19,    13,   118,    19,    19,     9,    19,     9,     9,     9,
     131,    19,    19,    29,    30,     8,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    13,    43,    44,    45,
      46,    47,     4,    28,    31,     6,     8,    19,    55,    32,
      20,   104,    14,    36,    76,    38,    79,    19,    87,   118,
      -1,    44,    45,    46,    47,    81,    -1,    29,    30,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    44,    45,    46,    47,     4,    -1,    -1,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,
      -1,    19,     4,    -1,    -1,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    14,    -1,    32,    -1,    -1,    -1,    36,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      32,    -1,    -1,    -1,    36,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    29,    30,    35,    39,    49,    50,    51,    59,    27,
      27,    27,     0,    51,    47,     8,    52,    53,    59,    13,
       9,    47,    53,    41,    54,    55,     4,     8,    14,    19,
      32,    33,    34,    36,    37,    38,    40,    43,    44,    45,
      46,    47,    54,    56,    59,    60,    61,    62,    63,    64,
      65,    66,     8,    47,    60,    59,    66,    60,    56,     8,
      59,    19,    66,     8,     8,    12,    15,    22,    47,    57,
      58,    16,    26,     6,    10,    17,    69,    11,    14,    68,
       5,     7,    20,    21,    23,    24,    25,    70,    42,    19,
      22,    57,     9,    66,    26,    19,    66,    66,    67,    19,
      19,    66,    18,    22,    13,    19,    60,    66,    61,    62,
      65,    63,    66,    66,     9,     9,    60,     9,    13,     9,
      19,    66,    66,    58,    28,    19,    56,    56,    28,    56,
      67,    31,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    51,    51,    52,    53,    53,    53,
      54,    55,    55,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    57,    57,
      57,    58,    58,    59,    59,    59,    59,    59,    59,    59,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      61,    61,    61,    61,    62,    62,    63,    63,    64,    64,
      65,    65,    66,    66,    67,    67,    67,    68,    68,    69,
      69,    69,    70,    70,    70,    70,    70,    70
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     6,     1,     2,     2,     0,     1,     3,
       3,     0,     2,     1,     1,     3,     4,     4,     3,     3,
       3,     2,     5,     7,     5,     5,     2,     2,     1,     3,
       3,     1,     3,     1,     1,     1,     1,     2,     2,     2,
       1,     1,     1,     1,     1,     4,     1,     5,     3,     3,
       4,     2,     2,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     0,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (&yylloc, scanner, result, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YY_LOCATION_PRINT
#  if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#   define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

#  else
#   define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#  endif
# endif /* !defined YY_LOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, scanner, result); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner, YYSTYPE *result)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (scanner);
  YY_USE (result);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner, YYSTYPE *result)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, scanner, result);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, yyscan_t scanner, YYSTYPE *result)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), scanner, result);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, scanner, result); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, yyscan_t scanner, YYSTYPE *result)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (scanner);
  YY_USE (result);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (yyscan_t scanner, YYSTYPE *result)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Prog: ListTopDef  */
#line 160 "Javalette.y"
                  { std::reverse((yyvsp[0].listtopdef_)->begin(),(yyvsp[0].listtopdef_)->end()) ;(yyval.prog_) = new Program((yyvsp[0].listtopdef_)); result->prog_ = (yyval.prog_); }
#line 1405 "Parser.C"
    break;

  case 3: /* TopDef: Type _IDENT_ _LPAREN ListArg _RPAREN Blk  */
#line 162 "Javalette.y"
                                                  { std::reverse((yyvsp[-2].listarg_)->begin(),(yyvsp[-2].listarg_)->end()) ;(yyval.topdef_) = new FnDef((yyvsp[-5].type_), (yyvsp[-4]._string), (yyvsp[-2].listarg_), (yyvsp[0].blk_)); }
#line 1411 "Parser.C"
    break;

  case 4: /* ListTopDef: TopDef  */
#line 164 "Javalette.y"
                    { (yyval.listtopdef_) = new ListTopDef(); (yyval.listtopdef_)->push_back((yyvsp[0].topdef_)); }
#line 1417 "Parser.C"
    break;

  case 5: /* ListTopDef: TopDef ListTopDef  */
#line 165 "Javalette.y"
                      { (yyvsp[0].listtopdef_)->push_back((yyvsp[-1].topdef_)); (yyval.listtopdef_) = (yyvsp[0].listtopdef_); }
#line 1423 "Parser.C"
    break;

  case 6: /* Arg: Type _IDENT_  */
#line 167 "Javalette.y"
                   { (yyval.arg_) = new Argument((yyvsp[-1].type_), (yyvsp[0]._string)); }
#line 1429 "Parser.C"
    break;

  case 7: /* ListArg: %empty  */
#line 169 "Javalette.y"
                      { (yyval.listarg_) = new ListArg(); }
#line 1435 "Parser.C"
    break;

  case 8: /* ListArg: Arg  */
#line 170 "Javalette.y"
        { (yyval.listarg_) = new ListArg(); (yyval.listarg_)->push_back((yyvsp[0].arg_)); }
#line 1441 "Parser.C"
    break;

  case 9: /* ListArg: Arg _COMMA ListArg  */
#line 171 "Javalette.y"
                       { (yyvsp[0].listarg_)->push_back((yyvsp[-2].arg_)); (yyval.listarg_) = (yyvsp[0].listarg_); }
#line 1447 "Parser.C"
    break;

  case 10: /* Blk: _LBRACE ListStmt _RBRACE  */
#line 173 "Javalette.y"
                               { (yyval.blk_) = new Block((yyvsp[-1].liststmt_)); }
#line 1453 "Parser.C"
    break;

  case 11: /* ListStmt: %empty  */
#line 175 "Javalette.y"
                       { (yyval.liststmt_) = new ListStmt(); }
#line 1459 "Parser.C"
    break;

  case 12: /* ListStmt: ListStmt Stmt  */
#line 176 "Javalette.y"
                  { (yyvsp[-1].liststmt_)->push_back((yyvsp[0].stmt_)); (yyval.liststmt_) = (yyvsp[-1].liststmt_); }
#line 1465 "Parser.C"
    break;

  case 13: /* Stmt: _SEMI  */
#line 178 "Javalette.y"
             { (yyval.stmt_) = new Empty(); }
#line 1471 "Parser.C"
    break;

  case 14: /* Stmt: Blk  */
#line 179 "Javalette.y"
        { (yyval.stmt_) = new BStmt((yyvsp[0].blk_)); }
#line 1477 "Parser.C"
    break;

  case 15: /* Stmt: Type ListItem _SEMI  */
#line 180 "Javalette.y"
                        { std::reverse((yyvsp[-1].listitem_)->begin(),(yyvsp[-1].listitem_)->end()) ;(yyval.stmt_) = new Decl((yyvsp[-2].type_), (yyvsp[-1].listitem_)); }
#line 1483 "Parser.C"
    break;

  case 16: /* Stmt: _IDENT_ _EQ Expr _SEMI  */
#line 181 "Javalette.y"
                           { (yyval.stmt_) = new Ass((yyvsp[-3]._string), (yyvsp[-1].expr_)); }
#line 1489 "Parser.C"
    break;

  case 17: /* Stmt: Expr _EQ Expr _SEMI  */
#line 182 "Javalette.y"
                        { (yyval.stmt_) = new ArrayAss((yyvsp[-3].expr_), (yyvsp[-1].expr_)); }
#line 1495 "Parser.C"
    break;

  case 18: /* Stmt: _IDENT_ _DPLUS _SEMI  */
#line 183 "Javalette.y"
                         { (yyval.stmt_) = new Incr((yyvsp[-2]._string)); }
#line 1501 "Parser.C"
    break;

  case 19: /* Stmt: _IDENT_ _DMINUS _SEMI  */
#line 184 "Javalette.y"
                          { (yyval.stmt_) = new Decr((yyvsp[-2]._string)); }
#line 1507 "Parser.C"
    break;

  case 20: /* Stmt: _KW_return Expr _SEMI  */
#line 185 "Javalette.y"
                          { (yyval.stmt_) = new Ret((yyvsp[-1].expr_)); }
#line 1513 "Parser.C"
    break;

  case 21: /* Stmt: _KW_return _SEMI  */
#line 186 "Javalette.y"
                     { (yyval.stmt_) = new VRet(); }
#line 1519 "Parser.C"
    break;

  case 22: /* Stmt: _KW_if _LPAREN Expr _RPAREN Stmt  */
#line 187 "Javalette.y"
                                     { (yyval.stmt_) = new Cond((yyvsp[-2].expr_), (yyvsp[0].stmt_)); }
#line 1525 "Parser.C"
    break;

  case 23: /* Stmt: _KW_if _LPAREN Expr _RPAREN Stmt _KW_else Stmt  */
#line 188 "Javalette.y"
                                                   { (yyval.stmt_) = new CondElse((yyvsp[-4].expr_), (yyvsp[-2].stmt_), (yyvsp[0].stmt_)); }
#line 1531 "Parser.C"
    break;

  case 24: /* Stmt: _KW_while _LPAREN Expr _RPAREN Stmt  */
#line 189 "Javalette.y"
                                        { (yyval.stmt_) = new While((yyvsp[-2].expr_), (yyvsp[0].stmt_)); }
#line 1537 "Parser.C"
    break;

  case 25: /* Stmt: _LPAREN Type Item _RPAREN Stmt  */
#line 190 "Javalette.y"
                                   { (yyval.stmt_) = new ForBlk((yyvsp[-3].type_), (yyvsp[-2].item_), (yyvsp[0].stmt_)); }
#line 1543 "Parser.C"
    break;

  case 26: /* Stmt: _KW_for Stmt  */
#line 191 "Javalette.y"
                 { (yyval.stmt_) = new ForLoop((yyvsp[0].stmt_)); }
#line 1549 "Parser.C"
    break;

  case 27: /* Stmt: Expr _SEMI  */
#line 192 "Javalette.y"
               { (yyval.stmt_) = new SExp((yyvsp[-1].expr_)); }
#line 1555 "Parser.C"
    break;

  case 28: /* Item: _IDENT_  */
#line 194 "Javalette.y"
               { (yyval.item_) = new NoInit((yyvsp[0]._string)); }
#line 1561 "Parser.C"
    break;

  case 29: /* Item: _IDENT_ _EQ Expr  */
#line 195 "Javalette.y"
                     { (yyval.item_) = new Init((yyvsp[-2]._string), (yyvsp[0].expr_)); }
#line 1567 "Parser.C"
    break;

  case 30: /* Item: _IDENT_ _COLON Expr  */
#line 196 "Javalette.y"
                        { (yyval.item_) = new InitElem((yyvsp[-2]._string), (yyvsp[0].expr_)); }
#line 1573 "Parser.C"
    break;

  case 31: /* ListItem: Item  */
#line 198 "Javalette.y"
                { (yyval.listitem_) = new ListItem(); (yyval.listitem_)->push_back((yyvsp[0].item_)); }
#line 1579 "Parser.C"
    break;

  case 32: /* ListItem: Item _COMMA ListItem  */
#line 199 "Javalette.y"
                         { (yyvsp[0].listitem_)->push_back((yyvsp[-2].item_)); (yyval.listitem_) = (yyvsp[0].listitem_); }
#line 1585 "Parser.C"
    break;

  case 33: /* Type: _KW_int  */
#line 201 "Javalette.y"
               { (yyval.type_) = new Int(); }
#line 1591 "Parser.C"
    break;

  case 34: /* Type: _KW_double  */
#line 202 "Javalette.y"
               { (yyval.type_) = new Doub(); }
#line 1597 "Parser.C"
    break;

  case 35: /* Type: _KW_boolean  */
#line 203 "Javalette.y"
                { (yyval.type_) = new Bool(); }
#line 1603 "Parser.C"
    break;

  case 36: /* Type: _KW_void  */
#line 204 "Javalette.y"
             { (yyval.type_) = new Void(); }
#line 1609 "Parser.C"
    break;

  case 37: /* Type: _KW_int _EMPTYBRACK  */
#line 205 "Javalette.y"
                        { (yyval.type_) = new IntArray(); }
#line 1615 "Parser.C"
    break;

  case 38: /* Type: _KW_double _EMPTYBRACK  */
#line 206 "Javalette.y"
                           { (yyval.type_) = new DoubArray(); }
#line 1621 "Parser.C"
    break;

  case 39: /* Type: _KW_boolean _EMPTYBRACK  */
#line 207 "Javalette.y"
                            { (yyval.type_) = new BoolArray(); }
#line 1627 "Parser.C"
    break;

  case 40: /* Expr6: _IDENT_  */
#line 213 "Javalette.y"
                { (yyval.expr_) = new EVar((yyvsp[0]._string)); }
#line 1633 "Parser.C"
    break;

  case 41: /* Expr6: _INTEGER_  */
#line 214 "Javalette.y"
              { (yyval.expr_) = new ELitInt((yyvsp[0]._int)); }
#line 1639 "Parser.C"
    break;

  case 42: /* Expr6: _DOUBLE_  */
#line 215 "Javalette.y"
             { (yyval.expr_) = new ELitDoub((yyvsp[0]._double)); }
#line 1645 "Parser.C"
    break;

  case 43: /* Expr6: _KW_true  */
#line 216 "Javalette.y"
             { (yyval.expr_) = new ELitTrue(); }
#line 1651 "Parser.C"
    break;

  case 44: /* Expr6: _KW_false  */
#line 217 "Javalette.y"
              { (yyval.expr_) = new ELitFalse(); }
#line 1657 "Parser.C"
    break;

  case 45: /* Expr6: _IDENT_ _LPAREN ListExpr _RPAREN  */
#line 218 "Javalette.y"
                                     { std::reverse((yyvsp[-1].listexpr_)->begin(),(yyvsp[-1].listexpr_)->end()) ;(yyval.expr_) = new EApp((yyvsp[-3]._string), (yyvsp[-1].listexpr_)); }
#line 1663 "Parser.C"
    break;

  case 46: /* Expr6: _STRING_  */
#line 219 "Javalette.y"
             { (yyval.expr_) = new EString((yyvsp[0]._string)); }
#line 1669 "Parser.C"
    break;

  case 47: /* Expr6: _KW_new Type _LBRACK Expr6 _RBRACK  */
#line 220 "Javalette.y"
                                       { (yyval.expr_) = new EArrayNew((yyvsp[-3].type_), (yyvsp[-1].expr_)); }
#line 1675 "Parser.C"
    break;

  case 48: /* Expr6: Expr6 _DOT Expr6  */
#line 221 "Javalette.y"
                     { (yyval.expr_) = new EArrayLen((yyvsp[-2].expr_), (yyvsp[0].expr_)); }
#line 1681 "Parser.C"
    break;

  case 49: /* Expr6: _LPAREN Expr _RPAREN  */
#line 222 "Javalette.y"
                         { (yyval.expr_) = (yyvsp[-1].expr_); }
#line 1687 "Parser.C"
    break;

  case 50: /* Expr5: Expr6 _LBRACK Expr _RBRACK  */
#line 224 "Javalette.y"
                                   { (yyval.expr_) = new EArray((yyvsp[-3].expr_), (yyvsp[-1].expr_)); }
#line 1693 "Parser.C"
    break;

  case 51: /* Expr5: _MINUS Expr6  */
#line 225 "Javalette.y"
                 { (yyval.expr_) = new Neg((yyvsp[0].expr_)); }
#line 1699 "Parser.C"
    break;

  case 52: /* Expr5: _BANG Expr6  */
#line 226 "Javalette.y"
                { (yyval.expr_) = new Not((yyvsp[0].expr_)); }
#line 1705 "Parser.C"
    break;

  case 53: /* Expr5: Expr6  */
#line 227 "Javalette.y"
          { (yyval.expr_) = (yyvsp[0].expr_); }
#line 1711 "Parser.C"
    break;

  case 54: /* Expr4: Expr4 MulOp Expr5  */
#line 229 "Javalette.y"
                          { (yyval.expr_) = new EMul((yyvsp[-2].expr_), (yyvsp[-1].mulop_), (yyvsp[0].expr_)); }
#line 1717 "Parser.C"
    break;

  case 55: /* Expr4: Expr5  */
#line 230 "Javalette.y"
          { (yyval.expr_) = (yyvsp[0].expr_); }
#line 1723 "Parser.C"
    break;

  case 56: /* Expr3: Expr3 AddOp Expr4  */
#line 232 "Javalette.y"
                          { (yyval.expr_) = new EAdd((yyvsp[-2].expr_), (yyvsp[-1].addop_), (yyvsp[0].expr_)); }
#line 1729 "Parser.C"
    break;

  case 57: /* Expr3: Expr4  */
#line 233 "Javalette.y"
          { (yyval.expr_) = (yyvsp[0].expr_); }
#line 1735 "Parser.C"
    break;

  case 58: /* Expr2: Expr2 RelOp Expr3  */
#line 235 "Javalette.y"
                          { (yyval.expr_) = new ERel((yyvsp[-2].expr_), (yyvsp[-1].relop_), (yyvsp[0].expr_)); }
#line 1741 "Parser.C"
    break;

  case 59: /* Expr2: Expr3  */
#line 236 "Javalette.y"
          { (yyval.expr_) = (yyvsp[0].expr_); }
#line 1747 "Parser.C"
    break;

  case 60: /* Expr1: Expr2 _DAMP Expr1  */
#line 238 "Javalette.y"
                          { (yyval.expr_) = new EAnd((yyvsp[-2].expr_), (yyvsp[0].expr_)); }
#line 1753 "Parser.C"
    break;

  case 61: /* Expr1: Expr2  */
#line 239 "Javalette.y"
          { (yyval.expr_) = (yyvsp[0].expr_); }
#line 1759 "Parser.C"
    break;

  case 62: /* Expr: Expr1 _DBAR Expr  */
#line 241 "Javalette.y"
                        { (yyval.expr_) = new EOr((yyvsp[-2].expr_), (yyvsp[0].expr_)); }
#line 1765 "Parser.C"
    break;

  case 63: /* Expr: Expr1  */
#line 242 "Javalette.y"
          { (yyval.expr_) = (yyvsp[0].expr_); }
#line 1771 "Parser.C"
    break;

  case 64: /* ListExpr: %empty  */
#line 244 "Javalette.y"
                       { (yyval.listexpr_) = new ListExpr(); }
#line 1777 "Parser.C"
    break;

  case 65: /* ListExpr: Expr  */
#line 245 "Javalette.y"
         { (yyval.listexpr_) = new ListExpr(); (yyval.listexpr_)->push_back((yyvsp[0].expr_)); }
#line 1783 "Parser.C"
    break;

  case 66: /* ListExpr: Expr _COMMA ListExpr  */
#line 246 "Javalette.y"
                         { (yyvsp[0].listexpr_)->push_back((yyvsp[-2].expr_)); (yyval.listexpr_) = (yyvsp[0].listexpr_); }
#line 1789 "Parser.C"
    break;

  case 67: /* AddOp: _PLUS  */
#line 248 "Javalette.y"
              { (yyval.addop_) = new Plus(); }
#line 1795 "Parser.C"
    break;

  case 68: /* AddOp: _MINUS  */
#line 249 "Javalette.y"
           { (yyval.addop_) = new Minus(); }
#line 1801 "Parser.C"
    break;

  case 69: /* MulOp: _STAR  */
#line 251 "Javalette.y"
              { (yyval.mulop_) = new Times(); }
#line 1807 "Parser.C"
    break;

  case 70: /* MulOp: _SLASH  */
#line 252 "Javalette.y"
           { (yyval.mulop_) = new Div(); }
#line 1813 "Parser.C"
    break;

  case 71: /* MulOp: _PERCENT  */
#line 253 "Javalette.y"
             { (yyval.mulop_) = new Mod(); }
#line 1819 "Parser.C"
    break;

  case 72: /* RelOp: _LT  */
#line 255 "Javalette.y"
            { (yyval.relop_) = new LTH(); }
#line 1825 "Parser.C"
    break;

  case 73: /* RelOp: _LDARROW  */
#line 256 "Javalette.y"
             { (yyval.relop_) = new LE(); }
#line 1831 "Parser.C"
    break;

  case 74: /* RelOp: _GT  */
#line 257 "Javalette.y"
        { (yyval.relop_) = new GTH(); }
#line 1837 "Parser.C"
    break;

  case 75: /* RelOp: _GTEQ  */
#line 258 "Javalette.y"
          { (yyval.relop_) = new GE(); }
#line 1843 "Parser.C"
    break;

  case 76: /* RelOp: _DEQ  */
#line 259 "Javalette.y"
         { (yyval.relop_) = new EQU(); }
#line 1849 "Parser.C"
    break;

  case 77: /* RelOp: _BANGEQ  */
#line 260 "Javalette.y"
            { (yyval.relop_) = new NE(); }
#line 1855 "Parser.C"
    break;


#line 1859 "Parser.C"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (&yylloc, scanner, result, YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, scanner, result);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, scanner, result);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, scanner, result, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, scanner, result);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, scanner, result);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 263 "Javalette.y"



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



