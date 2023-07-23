/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sintatica.y"

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

#define YYSTYPE atributos

using namespace std;

struct atributos
{
    string label;
    string label2;
    string traducao;
    string declaracao;
    string tipo;
    string valor;
    string strcpy;
};

void naoDeclarado(string chave);
void declarado(string chave);
void empilha();
void desempilha();
string genTemp();
string genRot();
int busca_escopo(string var);
int verificaVar(string var);
int verificaVarBloco(string var);
void conversaoImplicitaOp(atributos& $$, atributos& $1, atributos& $3, string operador, string tipo);
void operacao(atributos& $$, atributos& $1, atributos& $2, atributos& $3, string operador);

// Struct de cada tipo
typedef struct
{
    string nome;
    string tipo;
	string temp;
    string valor;
    int atribuido;
    int bloco;
} TIPO_SIMBOLO;

int bloco_atual = -1;
vector<unordered_map<string, TIPO_SIMBOLO>> pilha; 
vector<tuple<string, string>> pilha_rotulo;
bool gerouRotulo = false;

vector<string> pilha_malloc;
int temp;
int tempRot;
bool bloco_switch = false;
bool defaultExecutado = false;
string auxPrint;

int yylex(void);
void yyerror(string);

#line 131 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_NUM = 258,
    TK_REAL = 259,
    TK_TRUE = 260,
    TK_FALSE = 261,
    TK_CHAR = 262,
    TK_STRING = 263,
    TK_IF = 264,
    TK_ELSE = 265,
    TK_FOR = 266,
    TK_WHILE = 267,
    TK_DO = 268,
    TK_SWITCH = 269,
    TK_CASE = 270,
    TK_DP = 271,
    TK_DEFAULT = 272,
    TK_PRINT = 273,
    TK_SCAN = 274,
    TK_BREAK = 275,
    TK_CONTINUE = 276,
    TK_MAIN = 277,
    TK_ID = 278,
    TK_TIPO_INT = 279,
    TK_TIPO_FLOAT = 280,
    TK_TIPO_BOOL = 281,
    TK_CAST_FLOAT = 282,
    TK_CAST_INT = 283,
    TK_CAST_BOOL = 284,
    TK_TIPO_CHAR = 285,
    TK_TIPO_STRING = 286,
    TK_FIM = 287,
    TK_ERROR = 288,
    AND = 289,
    OR = 290,
    NO = 291,
    EQ = 292,
    NE = 293,
    GE = 294,
    LE = 295,
    TK_CAST_CHAR = 296
  };
#endif
/* Tokens.  */
#define TK_NUM 258
#define TK_REAL 259
#define TK_TRUE 260
#define TK_FALSE 261
#define TK_CHAR 262
#define TK_STRING 263
#define TK_IF 264
#define TK_ELSE 265
#define TK_FOR 266
#define TK_WHILE 267
#define TK_DO 268
#define TK_SWITCH 269
#define TK_CASE 270
#define TK_DP 271
#define TK_DEFAULT 272
#define TK_PRINT 273
#define TK_SCAN 274
#define TK_BREAK 275
#define TK_CONTINUE 276
#define TK_MAIN 277
#define TK_ID 278
#define TK_TIPO_INT 279
#define TK_TIPO_FLOAT 280
#define TK_TIPO_BOOL 281
#define TK_CAST_FLOAT 282
#define TK_CAST_INT 283
#define TK_CAST_BOOL 284
#define TK_TIPO_CHAR 285
#define TK_TIPO_STRING 286
#define TK_FIM 287
#define TK_ERROR 288
#define AND 289
#define OR 290
#define NO 291
#define EQ 292
#define NE 293
#define GE 294
#define LE 295
#define TK_CAST_CHAR 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   465

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156

#define YYUNDEFTOK  2
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      49,    50,    45,    43,     2,    44,     2,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    52,
      38,    53,    37,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    51,     2,     2,     2,     2,
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
      35,    36,    39,    40,    41,    42,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    83,    83,    87,    90,    98,   105,   119,   125,   131,
     132,   137,   141,   145,   149,   153,   158,   163,   168,   172,
     186,   201,   215,   229,   245,   277,   315,   359,   404,   447,
     457,   461,   468,   477,   488,   499,   507,   513,   521,   527,
     563,   579,   588,   594,   638,   648,   657,   664,   668,   672,
     676,   680,   684,   688,   692,   696,   719,   723,   727,   731,
     735,   864,   873,   881,   889,   898,   908,   918,   935,   952,
     969,   976
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_NUM", "TK_REAL", "TK_TRUE",
  "TK_FALSE", "TK_CHAR", "TK_STRING", "TK_IF", "TK_ELSE", "TK_FOR",
  "TK_WHILE", "TK_DO", "TK_SWITCH", "TK_CASE", "TK_DP", "TK_DEFAULT",
  "TK_PRINT", "TK_SCAN", "TK_BREAK", "TK_CONTINUE", "TK_MAIN", "TK_ID",
  "TK_TIPO_INT", "TK_TIPO_FLOAT", "TK_TIPO_BOOL", "TK_CAST_FLOAT",
  "TK_CAST_INT", "TK_CAST_BOOL", "TK_TIPO_CHAR", "TK_TIPO_STRING",
  "TK_FIM", "TK_ERROR", "AND", "OR", "NO", "'>'", "'<'", "EQ", "NE", "GE",
  "LE", "'+'", "'-'", "'*'", "'/'", "'{'", "TK_CAST_CHAR", "'('", "')'",
  "'}'", "';'", "'='", "$accept", "S", "BLOCO", "INI", "FIM", "COMANDOS",
  "COMANDO", "IF", "IF_ELSE", "FOR", "WHILE", "DO_WHILE", "BLOCO_LOOP",
  "CMD", "BREAK_OR_CONTINUE", "SWITCH", "BLOCO_SWITCH", "CASE_LISTA",
  "CASE_STMT", "CASE", "PRINT", "EXPRESSAO", "TEXTO", "E", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,    62,    60,   292,
     293,   294,   295,    43,    45,    42,    47,   123,   296,    40,
      41,   125,    59,    61
};
# endif

#define YYPACT_NINF (-101)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-9)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -7,    -4,    22,   -26,  -101,   -22,     5,  -101,  -101,   239,
    -101,  -101,  -101,  -101,  -101,  -101,    12,    17,    18,     6,
      21,    24,    27,    60,    65,    67,   273,   273,    74,    77,
     273,   273,  -101,  -101,   141,  -101,  -101,  -101,  -101,  -101,
    -101,  -101,   301,   273,   273,   273,  -101,    89,   273,     4,
      88,    52,    53,    54,    56,  -101,  -101,    58,    61,    -8,
    -101,    66,  -101,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,  -101,   349,   317,   363,    51,
      63,   377,  -101,  -101,  -101,    68,    76,    71,   419,  -101,
    -101,  -101,   273,  -101,  -101,  -101,    -8,    -8,   -30,   -30,
     -30,   -30,   -30,   -30,   -41,   -41,  -101,  -101,     5,   273,
       6,   -12,  -101,   273,    75,    73,     4,    78,   111,   333,
    -101,    79,    80,    51,    72,   391,    69,  -101,  -101,  -101,
      81,     5,   273,  -101,  -101,  -101,  -101,    82,   273,   113,
      84,    69,  -101,  -101,  -101,   405,  -101,   288,   190,  -101,
    -101,     6,   190,  -101,  -101,  -101
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     0,     1,     0,     0,     5,     2,    71,
      61,    62,    66,    65,    63,    64,     0,     0,     0,     0,
       0,     0,    70,     0,     0,     0,    71,    71,     0,     0,
      71,    71,     9,     6,    71,    11,    12,    15,    13,    14,
      16,    17,     0,    71,    71,    71,     5,     0,    71,     0,
      71,     0,     0,     0,    70,    67,    68,     0,     0,    55,
      69,     0,     7,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    10,     0,     0,     0,    71,
       0,     0,    45,    44,    46,     0,    42,     0,    60,    19,
      20,    22,    71,    21,    23,     4,    53,    54,    47,    48,
      49,    50,    51,    52,    56,    57,    58,    59,     0,    71,
       0,    31,     6,    71,     0,     0,     0,     0,    24,     0,
      27,     0,     0,    71,     0,     0,    37,    34,    41,    43,
       0,     0,    71,    32,    33,    30,    29,     0,    71,     0,
       0,    37,    38,    18,    25,     0,    28,     0,    71,    35,
      36,     0,    71,    40,    26,    39
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -101,  -101,    -5,    91,    15,    -9,  -101,  -101,  -101,  -101,
    -101,  -101,  -100,     7,  -101,  -101,  -101,    -3,  -101,  -101,
    -101,    25,  -101,   -24
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    32,     9,    61,   111,    34,    35,    36,    37,
      38,    39,    47,   112,   123,    40,   127,   140,   141,   142,
      41,    85,    86,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      33,     8,    55,    56,    73,    74,    59,    60,   121,   122,
     120,    82,    83,    71,    72,    73,    74,     1,     3,    76,
      77,    78,     4,     5,    81,    62,    88,    84,     6,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   154,     7,    46,    10,    11,    12,    13,    14,    15,
      16,    43,    17,    18,    19,    20,    44,    45,    88,    21,
      48,    -8,    -8,    49,    22,    23,    24,    25,    26,    27,
      50,    28,    29,    51,   138,   119,   139,    30,    52,   125,
      53,    10,    11,    12,    13,    14,    15,    57,     7,    31,
      58,    80,    -8,   118,    89,    90,    91,    87,   145,    92,
      93,    54,   113,    94,   147,    26,    27,    95,   115,   116,
     117,   131,   126,   136,    30,   128,   144,   124,   130,   148,
     135,   133,   134,   143,   146,   149,    31,    79,   150,   153,
       0,   129,     0,   155,    10,    11,    12,    13,    14,    15,
      16,     0,    17,    18,    19,    20,    -8,     0,    -8,    21,
       0,    -8,    -8,     0,    22,    23,    24,    25,    26,    27,
       0,    28,    29,     0,     0,     0,     0,    30,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,    31,
       0,     0,    -8,    10,    11,    12,    13,    14,    15,    16,
       0,    17,    18,    19,    20,    -8,     0,    -8,    21,     0,
       0,     0,     0,    22,    23,    24,    25,    26,    27,     0,
      28,    29,     0,     0,     0,     0,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,    31,     0,
       0,    -8,    10,    11,    12,    13,    14,    15,    16,     0,
      17,    18,    19,    20,     0,     0,     0,    21,     0,     0,
       0,     0,    22,    23,    24,    25,    26,    27,     0,    28,
      29,     0,     0,     0,     0,    30,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,     7,    31,     0,     0,
      -8,     0,     0,     0,     0,     0,    54,     0,     0,     0,
      26,    27,     0,     0,   152,     0,     0,     0,     0,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,    63,    64,     0,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    63,    64,     0,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,     0,     0,
       0,    63,    64,    75,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,     0,     0,     0,    63,    64,   109,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
       0,     0,     0,    63,    64,   132,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,     0,    63,    64,   108,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
       0,    63,    64,   110,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,     0,    63,    64,   114,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,     0,    63,
      64,   137,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,     0,    63,    64,   151,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74
};

static const yytype_int16 yycheck[] =
{
       9,     6,    26,    27,    45,    46,    30,    31,    20,    21,
     110,     7,     8,    43,    44,    45,    46,    24,    22,    43,
      44,    45,     0,    49,    48,    34,    50,    23,    50,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,   151,    47,    47,     3,     4,     5,     6,     7,     8,
       9,    49,    11,    12,    13,    14,    49,    49,    92,    18,
      49,    20,    21,    49,    23,    24,    25,    26,    27,    28,
      53,    30,    31,    23,    15,   109,    17,    36,    23,   113,
      23,     3,     4,     5,     6,     7,     8,    23,    47,    48,
      23,    12,    51,   108,    52,    52,    52,    19,   132,    53,
      52,    23,    49,    52,   138,    27,    28,    51,    50,    43,
      49,    10,    47,    51,    36,    52,   131,   112,    50,    16,
     123,    52,    52,    52,    52,    51,    48,    46,   141,   148,
      -1,   116,    -1,   152,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    13,    14,    15,    -1,    17,    18,
      -1,    20,    21,    -1,    23,    24,    25,    26,    27,    28,
      -1,    30,    31,    -1,    -1,    -1,    -1,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      -1,    -1,    51,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    13,    14,    15,    -1,    17,    18,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    -1,
      30,    31,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,
      -1,    51,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    13,    14,    -1,    -1,    -1,    18,    -1,    -1,
      -1,    -1,    23,    24,    25,    26,    27,    28,    -1,    30,
      31,    -1,    -1,    -1,    -1,    36,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      27,    28,    -1,    -1,    16,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    34,    35,    52,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    34,    35,    52,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    34,    35,    52,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    34,    35,    50,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    34,    35,    50,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    34,    35,    50,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    34,
      35,    50,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    34,    35,    50,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    24,    55,    22,     0,    49,    50,    47,    56,    57,
       3,     4,     5,     6,     7,     8,     9,    11,    12,    13,
      14,    18,    23,    24,    25,    26,    27,    28,    30,    31,
      36,    48,    56,    59,    60,    61,    62,    63,    64,    65,
      69,    74,    77,    49,    49,    49,    47,    66,    49,    49,
      53,    23,    23,    23,    23,    77,    77,    23,    23,    77,
      77,    58,    59,    34,    35,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    52,    77,    77,    77,    57,
      12,    77,     7,     8,    23,    75,    76,    19,    77,    52,
      52,    52,    53,    52,    52,    51,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    50,    52,
      50,    59,    67,    49,    50,    50,    43,    49,    56,    77,
      66,    20,    21,    68,    58,    77,    47,    70,    52,    75,
      50,    10,    52,    52,    52,    67,    51,    50,    15,    17,
      71,    72,    73,    52,    56,    77,    52,    77,    16,    51,
      71,    50,    16,    59,    66,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    55,    56,    57,    58,    59,    59,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    61,    62,    63,    64,    65,    66,
      67,    67,    68,    68,    69,    70,    71,    71,    72,    73,
      73,    74,    75,    75,    76,    76,    76,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     0,     5,     0,     0,     2,     0,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     6,     3,
       3,     3,     3,     3,     5,     7,     9,     5,     7,     5,
       3,     1,     2,     2,     5,     3,     2,     0,     1,     4,
       3,     5,     1,     3,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

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
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 84 "sintatica.y"
            {
                cout << "/*Compilador CAPY*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n" << yyvsp[0].declaracao << yyvsp[0].traducao << "\treturn 0;\n}" << endl;
            }
#line 1605 "y.tab.c"
    break;

  case 4:
#line 91 "sintatica.y"
            {
                yyval.traducao = yyvsp[-2].traducao + yyvsp[-1].traducao;
				yyval.declaracao = yyvsp[-2].declaracao;
            }
#line 1614 "y.tab.c"
    break;

  case 5:
#line 98 "sintatica.y"
            {
                empilha();
                bloco_atual++;
            }
#line 1623 "y.tab.c"
    break;

  case 6:
#line 105 "sintatica.y"
            {
                desempilha();
                bloco_atual--;
                string traducao;
                while (pilha_malloc.size() != 0) {
                    string aux = pilha_malloc.back();  // Obter o último elemento da pilha
                    pilha_malloc.pop_back();           // Remover o último elemento da pilha

                    traducao += string("\t") + string("free(") + aux + ");\n";  // Adicionar a instrução correspondente
                }
                yyval.traducao = traducao;
            }
#line 1640 "y.tab.c"
    break;

  case 7:
#line 120 "sintatica.y"
            {
                yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
				yyval.declaracao = yyvsp[-1].declaracao + yyvsp[0].declaracao;
            }
#line 1649 "y.tab.c"
    break;

  case 8:
#line 125 "sintatica.y"
            {
                yyval.traducao = "";
                yyval.declaracao = "";
            }
#line 1658 "y.tab.c"
    break;

  case 10:
#line 133 "sintatica.y"
            {
                yyval.traducao = yyvsp[-1].traducao;
                yyval.declaracao = yyvsp[-1].declaracao;
            }
#line 1667 "y.tab.c"
    break;

  case 11:
#line 138 "sintatica.y"
            {
                yyval.traducao = yyvsp[0].traducao;
            }
#line 1675 "y.tab.c"
    break;

  case 12:
#line 142 "sintatica.y"
            {
                yyval.traducao = yyvsp[0].traducao;
            }
#line 1683 "y.tab.c"
    break;

  case 13:
#line 146 "sintatica.y"
            {
                yyval.traducao = yyvsp[0].traducao;
            }
#line 1691 "y.tab.c"
    break;

  case 14:
#line 150 "sintatica.y"
            {
                yyval.traducao = yyvsp[0].traducao;
            }
#line 1699 "y.tab.c"
    break;

  case 15:
#line 154 "sintatica.y"
            {
                yyval.traducao = yyvsp[0].traducao;
                yyval.declaracao = yyvsp[0].declaracao;
            }
#line 1708 "y.tab.c"
    break;

  case 16:
#line 159 "sintatica.y"
            {
                yyval.traducao = yyvsp[0].traducao;
                yyval.declaracao = yyvsp[0].declaracao;
            }
#line 1717 "y.tab.c"
    break;

  case 17:
#line 164 "sintatica.y"
            {
                yyval.traducao = yyvsp[0].traducao;
                yyval.declaracao = yyvsp[0].declaracao;
            }
#line 1726 "y.tab.c"
    break;

  case 18:
#line 169 "sintatica.y"
            {   
                yyval.traducao = "\tcin >> " + pilha[busca_escopo(yyvsp[-5].label)][yyvsp[-5].label].temp + ";\n";
            }
#line 1734 "y.tab.c"
    break;

  case 19:
#line 173 "sintatica.y"
            {
                declarado(yyvsp[-1].label);
                TIPO_SIMBOLO var;
                var.nome = yyvsp[-1].label;
                var.tipo = "int";
                var.atribuido = 0;
				var.temp = genTemp();
                var.bloco = bloco_atual;
                pilha[bloco_atual][var.nome] = var;
                yyval.tipo = var.tipo;
                yyval.declaracao = "\t" + yyval.tipo + " " + var.temp + ";    " + var.temp + " = " + var.nome + " bloco " + to_string(bloco_atual) +"\n";
                yyval.traducao = "";
            }
#line 1752 "y.tab.c"
    break;

  case 20:
#line 187 "sintatica.y"
            {
                declarado(yyvsp[-1].label);
                TIPO_SIMBOLO var;
                var.nome = yyvsp[-1].label;
                var.tipo = "float";
                var.atribuido = 0;
				var.temp = genTemp();
                var.bloco = bloco_atual;
                pilha[bloco_atual][var.nome] = var;
                yyval.tipo = var.tipo;
                yyval.declaracao = "\t" + yyval.tipo + " " + var.temp + ";    " + var.temp + " = " + var.nome + " bloco " + to_string(bloco_atual) +"\n";
                yyval.traducao = "";
                
            }
#line 1771 "y.tab.c"
    break;

  case 21:
#line 202 "sintatica.y"
            {
                declarado(yyvsp[-1].label);
                TIPO_SIMBOLO var;
                var.nome = yyvsp[-1].label;
                var.tipo = "char";
                var.atribuido = 0;
				var.temp = genTemp();
                var.bloco = bloco_atual;
                pilha[bloco_atual][var.nome] = var;
                yyval.tipo = var.tipo;
                yyval.declaracao = "\t" + yyval.tipo + " " + var.temp + ";    " + var.temp + " = " + var.nome + " bloco " + to_string(bloco_atual) +"\n";
                yyval.traducao = "";
            }
#line 1789 "y.tab.c"
    break;

  case 22:
#line 216 "sintatica.y"
            {
                declarado(yyvsp[-1].label);
                TIPO_SIMBOLO var;
                var.nome = yyvsp[-1].label;
                var.tipo = "bool";
                var.atribuido = 0;
				var.temp = genTemp();
                var.bloco = bloco_atual;
                pilha[bloco_atual][var.nome] = var;
                yyval.tipo = var.tipo;
                yyval.declaracao = "\t" + string("int") + " " + var.temp + ";    " + var.temp + " = " + var.nome + " bloco " + to_string(bloco_atual) +"\n";
                yyval.traducao = "";
            }
#line 1807 "y.tab.c"
    break;

  case 23:
#line 230 "sintatica.y"
            {
                declarado(yyvsp[-1].label);
                TIPO_SIMBOLO var;
                var.nome = yyvsp[-1].label;
                var.tipo = "string";
                var.atribuido = 0;
				var.temp = genTemp();
                var.bloco = bloco_atual;
                pilha[bloco_atual][var.nome] = var;
                yyval.tipo = var.tipo;
                yyval.declaracao = "\t" + string("char") + " *" + var.temp + ";    " + var.temp + " = " + var.nome + " bloco " + to_string(bloco_atual) +"\n";
                yyval.traducao += "";
            }
#line 1825 "y.tab.c"
    break;

  case 24:
#line 246 "sintatica.y"
            {   
                if(verificaVar(yyvsp[-2].label)){
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo != "bool"){
                        yyerror("Erro: A condição do 'if' deve ser uma expressão booleana válida");
                    }
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].atribuido == 0){
                       yyerror("ERRO: Variável " + yyvsp[-2].label + " sem valor atribuido");
                    }
                    else{
                        yyval.label = genTemp();
                        yyval.declaracao = "\tint " + yyval.label + ";\n";
                        yyval.traducao += yyvsp[-2].traducao + "\t" + yyval.label + " = " + "!" + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + ";\n";
                        yyval.traducao += "\tif("+ yyval.label + ")" + " goto" + " FIM_IF" + ";\n";
                        yyval.traducao += yyvsp[0].traducao + "\tFIM_IF;\n";
                        yyval.declaracao += yyvsp[-2].declaracao + yyvsp[0].declaracao + "\tint " + yyval.label + ";\n";
                    }
                }
                else{
                    if(yyvsp[-2].tipo != "bool"){
                        yyerror("Erro: A condição do 'if' deve ser uma expressão booleana válida");
                    }
                    else{
                        yyval.label = genTemp();
                        yyval.traducao += yyvsp[-2].traducao + "\t" + yyval.label + " = " + "!" + yyvsp[-2].label + ";\n";
                        yyval.traducao += "\tif("+ yyval.label + ")" + " goto" + " FIM_IF" + ";\n";
                        yyval.traducao += yyvsp[0].traducao + "\tFIM_IF;\n";
                        yyval.declaracao += yyvsp[-2].declaracao + yyvsp[0].declaracao + "\tint " + yyval.label + ";\n";
                    }
                }
            }
#line 1860 "y.tab.c"
    break;

  case 25:
#line 278 "sintatica.y"
            {   
                if(verificaVar(yyvsp[-4].label)){
                    if(pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].tipo != "bool"){
                        yyerror("Erro: A condição do 'if' deve ser uma expressão booleana válida");
                    }
                    if(pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].atribuido == 0){
                       yyerror("ERRO: Variável " + yyvsp[-4].label + " sem valor atribuido");
                    }
                    else{
                        yyval.label = genTemp();
                        yyval.declaracao = "\tint " + yyval.label + ";\n";
                        yyval.traducao += yyvsp[-4].traducao + "\t" + yyval.label + " = " + "!" + pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].temp + ";\n";
                        yyval.traducao += "\tif("+ yyval.label + ")" + " goto" + " FIM_IF" + ";\n";
                        yyval.traducao += yyvsp[-2].traducao + "\tFIM_IF;\n";
                        yyval.declaracao += yyvsp[-4].declaracao + yyvsp[-2].declaracao + "\tint " + yyval.label + ";\n";
                    }
                }
                else{
                    if(yyvsp[-4].tipo != "bool"){
                        yyerror("Erro: A condição do 'if' deve ser uma expressão booleana válida");
                    }
                    else{
                        yyval.label = genTemp();
                        yyval.declaracao = "\tint " + yyval.label + ";\n";
                        yyval.traducao += yyvsp[-4].traducao + "\t" + yyval.label + " = " + "!" + yyvsp[-4].label + ";\n";
                        yyval.traducao += "\tif("+ yyval.label + ")" + " goto" + " else" + ";\n";
                        yyval.traducao += yyvsp[-2].traducao + "\tFIM_IF" + " goto" + " FIM_ELSE" + ";\n"; 
                        yyval.declaracao += yyvsp[-4].declaracao + yyvsp[-2].declaracao + "\tint " + yyval.label + ";\n";
                    }
                }

                // Adiciona a tradução e declaração do bloco do else
                yyval.traducao += "\telse\n" + yyvsp[0].traducao + "\tFIM_ELSE;\n";
                yyval.declaracao += yyvsp[0].declaracao;
            }
#line 1900 "y.tab.c"
    break;

  case 26:
#line 316 "sintatica.y"
            {
                if(verificaVar(yyvsp[-4].label)){
                    if(pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].tipo != "bool"){
                        yyerror("Erro: A condição do 'for' deve ser uma expressão booleana válida");
                    }
                    if(pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].atribuido == 0){
                       yyerror("ERRO: Variável " + yyvsp[-4].label + " sem valor atribuido");
                    }
                    else{
                        string iniRotulo = get<0>(pilha_rotulo.back());
                        string fimRotulo = get<1>(pilha_rotulo.back());
                        pilha_rotulo.pop_back();
                        gerouRotulo = false;
                        yyval.label = genTemp(); 
                        yyval.traducao += yyvsp[-6].traducao + "\t" +iniRotulo + "\n" + yyvsp[-4].traducao; 
                        yyval.traducao += "\t" + yyval.label + " = " + "!" + pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].temp + ";\n";
                        yyval.traducao += "\tif("+ yyval.label + ")" + " goto " + fimRotulo + "\n";
                        yyval.declaracao += yyvsp[-6].declaracao + yyvsp[-4].declaracao + yyvsp[-2].declaracao + yyvsp[0].declaracao + "\tint " + yyval.label + ";\n";
                        yyval.traducao +=  yyvsp[0].traducao + yyvsp[-2].traducao ;
                        yyval.traducao += "\t" + fimRotulo;  
                    }
                }
                else{
                    if(yyvsp[-4].tipo != "bool"){
                        yyerror("Erro: A condição do 'for' deve ser uma expressão booleana válida");
                    }
                    else{
                        string iniRotulo = get<0>(pilha_rotulo.back());
                        string fimRotulo = get<1>(pilha_rotulo.back());
                        pilha_rotulo.pop_back();
                        yyval.label = genTemp(); 
                        yyval.traducao += yyvsp[-6].traducao + "\t" + iniRotulo + "\n" + yyvsp[-4].traducao;
                        yyval.traducao += "\t" + yyval.label + " = " + "!" + yyvsp[-4].label + ";\n";
                        yyval.traducao += "\tif("+ yyval.label + ")" + " goto " + fimRotulo + "\n";
                        yyval.declaracao += yyvsp[-6].declaracao + yyvsp[-4].declaracao + yyvsp[-2].declaracao + yyvsp[0].declaracao + "\tint " + yyval.label + ";\n";
                        yyval.traducao +=  yyvsp[0].traducao + yyvsp[-2].traducao ;
                        yyval.traducao += string("\tgoto ") + iniRotulo + "\n\t" + fimRotulo + "\n";
                    }
                }
                gerouRotulo = false;
            }
#line 1946 "y.tab.c"
    break;

  case 27:
#line 360 "sintatica.y"
            {
                if(verificaVar(yyvsp[-2].label)){
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo != "bool"){
                        yyerror("Erro: A condição do 'if' deve ser uma expressão booleana válida");
                    }
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].atribuido == 0){
                       yyerror("ERRO: Variável " + yyvsp[-2].label + " sem valor atribuido");
                    }
                    else{
                        string iniRotulo = get<0>(pilha_rotulo.back());
                        string fimRotulo = get<1>(pilha_rotulo.back());
                        pilha_rotulo.pop_back();
                        gerouRotulo = false;
                        yyval.traducao += "\t" + iniRotulo + "\n";
                        yyval.label = genTemp();
                        yyval.traducao += yyvsp[-2].traducao + "\t" + yyval.label + " = " + "!" + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + ";\n";
                        yyval.traducao += "\tif("+ yyval.label + ")" + " goto " + fimRotulo + ";\n";
                        yyval.traducao += yyvsp[0].traducao + "\tgoto " + iniRotulo +"\n";
                        yyval.traducao += "\t" + fimRotulo + "\n";
                        yyval.declaracao += yyvsp[-2].declaracao + yyvsp[0].declaracao;
                    }
                }
                else{
                    if(yyvsp[-2].tipo != "bool"){
                        yyerror("Erro: A condição do 'if' deve ser uma expressão booleana válida");
                    }
                    else{
                        string iniRotulo = get<0>(pilha_rotulo.back());
                        string fimRotulo = get<1>(pilha_rotulo.back());
                        pilha_rotulo.pop_back();
                        gerouRotulo = false;
                        yyval.traducao += "\t" + iniRotulo + "\n";
                        yyval.label = genTemp();
                        yyval.traducao += yyvsp[-2].traducao + "\t" + yyval.label + " = " + "!" + yyvsp[-2].label + ";\n";
                        yyval.traducao += "\tif("+ yyval.label + ")" + " goto " + fimRotulo + ";\n";
                        yyval.traducao += yyvsp[0].traducao + "\tgoto " + iniRotulo +"\n";
                        yyval.traducao += "\t" + fimRotulo + "\n";
                        yyval.declaracao += yyvsp[-2].declaracao + yyvsp[0].declaracao;
                    }
                }
                gerouRotulo = false;
            }
#line 1993 "y.tab.c"
    break;

  case 28:
#line 405 "sintatica.y"
            {
                if(verificaVar(yyvsp[-2].label)){
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo != "bool"){
                        yyerror("Erro: A condição do 'while' deve ser uma expressão booleana válida");
                    }
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].atribuido == 0){
                       yyerror("ERRO: Variável " + yyvsp[-2].label + " sem valor atribuido");
                    }
                    else{
                        string iniRotulo = get<0>(pilha_rotulo.back());
                        string fimRotulo = get<1>(pilha_rotulo.back());
                        pilha_rotulo.pop_back();
                        yyval.traducao += "\t" + iniRotulo + "\n";
                        yyval.declaracao += yyvsp[-5].declaracao + yyvsp[-2].declaracao;
                        yyval.traducao += yyvsp[-5].traducao + yyvsp[-2].traducao;
                        yyval.label = genTemp();
                        yyval.traducao += "\t" + yyval.label + " = " + "!" + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + ";\n";
                        yyval.traducao += "\tif("+ yyval.label + ")" + " goto " + fimRotulo + ";\n";
                        yyval.traducao += "\t"+ iniRotulo +"\n";
                    }
                }
                else{
                    if(yyvsp[-2].tipo != "bool"){
                        yyerror("Erro: A condição do 'while' deve ser uma expressão booleana válida");
                    }
                    else{
                        string iniRotulo = get<0>(pilha_rotulo.back());
                        string fimRotulo = get<1>(pilha_rotulo.back());
                        pilha_rotulo.pop_back();
                        yyval.traducao += "\t" + iniRotulo + "\n";
                        yyval.declaracao += yyvsp[-5].declaracao + yyvsp[-2].declaracao;
                        yyval.traducao += yyvsp[-5].traducao + yyvsp[-2].traducao;
                        yyval.label = genTemp();
                        yyval.traducao += "\t" + yyval.label + " = " + "!" + yyvsp[-2].label + ";\n";
                        yyval.traducao += "\tif("+ yyval.label + ")" + " goto " + fimRotulo + ";\n";
                        yyval.traducao += "\t"+ iniRotulo +"\n";
                    }
                }
                gerouRotulo = false;
            }
#line 2038 "y.tab.c"
    break;

  case 29:
#line 448 "sintatica.y"
            {
                yyval.declaracao += yyvsp[-2].declaracao;
                yyval.traducao += yyvsp[-2].traducao;
                if(!gerouRotulo){
                    pilha_rotulo.push_back(make_tuple(genRot(),genRot())); //ini fim
                }
            }
#line 2050 "y.tab.c"
    break;

  case 30:
#line 457 "sintatica.y"
                                            {
                yyval.declaracao = yyvsp[-2].declaracao + yyvsp[-1].declaracao + yyvsp[0].declaracao;
                yyval.traducao = yyvsp[-2].traducao + yyvsp[-1].traducao + yyvsp[0].traducao;
            }
#line 2059 "y.tab.c"
    break;

  case 31:
#line 462 "sintatica.y"
            {
                yyval.declaracao = yyvsp[0].declaracao;
                yyval.traducao = yyvsp[0].traducao;
            }
#line 2068 "y.tab.c"
    break;

  case 32:
#line 469 "sintatica.y"
            {     
                if(!gerouRotulo){
                    pilha_rotulo.push_back(make_tuple(genRot(),genRot())); //ini fim
                    gerouRotulo = true;
                }
                string lula = get<1>(pilha_rotulo.back());
                yyval.traducao += "\t" + string("goto ") + lula + ";\n";
            }
#line 2081 "y.tab.c"
    break;

  case 33:
#line 478 "sintatica.y"
            {
                if(!gerouRotulo){
                    pilha_rotulo.push_back(make_tuple(genRot(),genRot())); //ini fim
                    gerouRotulo = true;
                }
                string iniRotulo = get<0>(pilha_rotulo.back());
                yyval.traducao += "\t" + string("goto ") + iniRotulo + ";\n"; 
            }
#line 2094 "y.tab.c"
    break;

  case 34:
#line 489 "sintatica.y"
            {
                string rotuloIni = genRot();
                string rotuloFim = genRot();
                yyval.traducao += yyvsp[-2].traducao + "\t" +rotuloIni + "\n" + yyvsp[0].traducao; 
                yyval.declaracao += yyvsp[-2].declaracao + yyvsp[0].declaracao;
                yyval.traducao += "\t" + rotuloFim + "\n";
                defaultExecutado = false;
            }
#line 2107 "y.tab.c"
    break;

  case 35:
#line 500 "sintatica.y"
            {
                // Faça o processamento necessário para o bloco switch
                yyval.traducao += yyvsp[-1].traducao;
                yyval.declaracao += yyvsp[-1].declaracao;
            }
#line 2117 "y.tab.c"
    break;

  case 36:
#line 508 "sintatica.y"
            {
                yyval.traducao += yyvsp[0].traducao;
                yyval.declaracao += yyvsp[0].declaracao;
            }
#line 2126 "y.tab.c"
    break;

  case 37:
#line 513 "sintatica.y"
            {
                // Caso base: não há mais casos na lista
                yyval.traducao = "";
                yyval.declaracao = "";
            }
#line 2136 "y.tab.c"
    break;

  case 38:
#line 522 "sintatica.y"
            {
                // Faça o processamento necessário para o caso
            }
#line 2144 "y.tab.c"
    break;

  case 39:
#line 528 "sintatica.y"
            {
                if(verificaVar(yyvsp[-2].label)){
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].atribuido == 0){
                       yyerror("ERRO: Variável " + yyvsp[-2].label + " sem valor atribuido");
                    }
                    else{
                        yyval.declaracao += yyvsp[-2].declaracao + yyvsp[0].declaracao;
                        string rotuloIni = genRot();
                        string rotuloFim = genRot();
                        yyval.label = genTemp();
                        yyval.declaracao += "\t" + string("int ") + yyval.label + ";\n";
                        yyval.traducao += "\t" + rotuloIni + "\n"; 
                        yyval.traducao += yyvsp[-2].traducao;
                        yyval.traducao += "\t" + yyval.label + " = " + "!" + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + ";\n";
                        yyval.traducao += "\tif("+ yyval.label + ")" + " goto " + rotuloFim + ";\n";
                        yyval.traducao += yyvsp[0].traducao;
                        yyval.traducao += "\t"+ rotuloFim +"\n";
                    }
                }
                else{
                        yyval.declaracao += yyvsp[-2].declaracao + yyvsp[0].declaracao;
                        string rotuloIni = genRot();
                        string rotuloFim = genRot();
                        yyval.label = genTemp();
                        yyval.declaracao += "\t" + string("int ") + yyval.label + ";\n";
                        yyval.traducao += "\t" + rotuloIni + "\n"; 
                        yyval.traducao += yyvsp[-2].traducao;
                        yyval.traducao += "\t" + yyval.label + " = " + "!" + yyvsp[-2].label + ";\n";
                        yyval.traducao += "\tif("+ yyval.label + ")" + " goto " + rotuloFim + ";\n";
                        yyval.traducao += yyvsp[0].traducao;
                        yyval.traducao += "\t"+ rotuloFim +"\n";
                }
                

            }
#line 2184 "y.tab.c"
    break;

  case 40:
#line 564 "sintatica.y"
            {
                if(defaultExecutado){
                   yyerror("ERRO: Mais de um case padrão (default) encontrado.");
                }else{
                    yyval.declaracao += yyvsp[0].declaracao;
                    string rotuloIni = genRot();
                    string rotuloFim = genRot();
                    yyval.traducao += "\t" + rotuloIni + "\n"; 
                    yyval.traducao += yyvsp[0].traducao;
                    yyval.traducao += "\t"+ rotuloFim +"\n";
                    defaultExecutado = true;
                }
            }
#line 2202 "y.tab.c"
    break;

  case 41:
#line 580 "sintatica.y"
            {   
                yyval.declaracao += yyvsp[-2].declaracao;

                yyval.traducao += yyvsp[-2].strcpy + auxPrint + "\t" + string("cout << ") + yyvsp[-2].traducao + ";\n";
                auxPrint = "";
            }
#line 2213 "y.tab.c"
    break;

  case 42:
#line 589 "sintatica.y"
            {
                yyval.declaracao = yyvsp[0].declaracao;
                yyval.traducao = yyvsp[0].traducao;
                yyval.strcpy = yyvsp[0].strcpy;
            }
#line 2223 "y.tab.c"
    break;

  case 43:
#line 595 "sintatica.y"
            {
                if(verificaVar(yyvsp[0].label)){
                    string tipo = pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].tipo;
                    if(tipo == "int" || tipo == "float" || tipo == "bool"){
                        yyerror("Apenas valores do tipo 'char' ou 'string' podem ser concatenados!");
                    }
                    
                } // ##############################################
                //VAR NUM
                if(verificaVar(yyval.label) && !verificaVar(yyvsp[0].label)){
                    string aux = genTemp();
                    yyval.declaracao += yyvsp[0].declaracao + "\tchar " + aux + "[" + to_string(pilha[busca_escopo(yyval.label)][yyval.label].valor.length() + yyvsp[0].label.length() - 2) + "];\n";
                    yyval.strcpy += yyvsp[0].strcpy;
                    auxPrint += "\tstrcpy(" + aux + ", strcat(" + yyval.traducao + ", " + yyvsp[0].label2 + "));\n";
                    yyval.traducao = aux;
                //VAR VAR
                }else if(verificaVar(yyval.label) && verificaVar(yyval.label)){
                    string aux = genTemp();
                    yyval.declaracao += yyvsp[0].declaracao + "\tchar " + aux + "[" + to_string(pilha[busca_escopo(yyval.label)][yyval.label].valor.length() + pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].valor.length() - 2) + "];\n";
                    yyval.strcpy += yyvsp[0].strcpy;
                    auxPrint += "\tstrcpy(" + aux + ", strcat(" + yyval.traducao + ", " + pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].temp + "));\n";
                    yyval.traducao = aux;
                //NUM VAR
                }else if(!verificaVar(yyval.label) && verificaVar(yyvsp[0].label)){
                    string aux = genTemp();
                    yyval.declaracao += yyvsp[0].declaracao + "\tchar " + aux + "["  + to_string(yyval.traducao.length() + pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].valor.length() - 2) + "];\n";
                    yyval.strcpy += yyvsp[0].strcpy;
                    auxPrint += "\tstrcpy(" + aux + ", strcat(" + yyval.traducao + ", " + pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].temp + "));\n";
                    yyval.traducao = aux;
                }
                //NUM NUM
                else{
                    yyval.label = genTemp();
                    yyval.declaracao += yyvsp[0].declaracao + "\tchar " + yyval.label + "[" + to_string(yyval.traducao.length() + yyvsp[0].traducao.length() - 2) + "];\n";
                    yyval.strcpy += yyvsp[0].strcpy;
                    auxPrint += "\tstrcpy(" + yyval.label + ", strcat(" + yyval.label2 + ", " + yyvsp[0].label2 + "));\n";
                    yyval.traducao = yyval.label;
                }
                
                
            }
#line 2269 "y.tab.c"
    break;

  case 44:
#line 639 "sintatica.y"
            {   
                yyval.tipo = "string";
                yyval.label = genTemp();
                yyval.valor = yyvsp[0].label;
                yyval.declaracao += "\t" + string("char") + " " + yyval.label + string("[") + to_string(yyvsp[0].label.length()-1) +string("]")+ ";\n";
                yyval.strcpy += "\t" + string("strcpy(") + yyval.label + ", "+ yyvsp[0].label + ")"+";\n"; 
                yyval.traducao += yyval.valor;
                yyval.label2 += yyval.label;
            }
#line 2283 "y.tab.c"
    break;

  case 45:
#line 649 "sintatica.y"
            {
                yyval.tipo = "char";
                yyval.label = genTemp();
                yyval.valor = yyvsp[0].label;
                yyval.declaracao += "\t" + string("char") + " " + yyval.label + string("[") + to_string(yyvsp[0].label.length()-1) +string("]")+ ";\n";
                yyval.strcpy += "\t" + string("strcpy(") + yyval.label + ", "+ yyvsp[0].label + ")"+";\n";
                yyval.traducao += yyvsp[0].label;
            }
#line 2296 "y.tab.c"
    break;

  case 46:
#line 658 "sintatica.y"
            {
                yyval.traducao += pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].temp;
            }
#line 2304 "y.tab.c"
    break;

  case 47:
#line 665 "sintatica.y"
            {	
				operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0], ">");
            }
#line 2312 "y.tab.c"
    break;

  case 48:
#line 669 "sintatica.y"
            {	
				operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0], "<");
            }
#line 2320 "y.tab.c"
    break;

  case 49:
#line 673 "sintatica.y"
            {	
				operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0], "==");
            }
#line 2328 "y.tab.c"
    break;

  case 50:
#line 677 "sintatica.y"
            {	
				operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0], "!=");
            }
#line 2336 "y.tab.c"
    break;

  case 51:
#line 681 "sintatica.y"
            {	
				operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0], ">=");
            }
#line 2344 "y.tab.c"
    break;

  case 52:
#line 685 "sintatica.y"
            {	
				operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0], "<=");
            }
#line 2352 "y.tab.c"
    break;

  case 53:
#line 689 "sintatica.y"
            {	
				operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0], "&&");
            }
#line 2360 "y.tab.c"
    break;

  case 54:
#line 693 "sintatica.y"
            {	
				operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0], "||");
            }
#line 2368 "y.tab.c"
    break;

  case 55:
#line 697 "sintatica.y"
            {	
                
                //VAR
                if(verificaVar(yyvsp[0].label)){
                    if(pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].tipo != "bool"){
                        yyerror("ERRO: Operadores Lógicos só aceitam tipo Booleano!");
                    }
                    yyval.label = genTemp();
                    yyval.tipo = "bool";
                    yyval.declaracao += yyvsp[-1].declaracao + yyvsp[0].declaracao + "\t" + "int" + " " + yyval.label + ";\n";
                    yyval.traducao += yyvsp[-1].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + "!" + pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].temp + ";\n";
                }else{
                    //NAO VAR
                    if(yyvsp[0].tipo != "bool"){
                        yyerror("ERRO: Operadores Lógicos só aceitam tipos Booleano!");
                    }
                    yyval.label = genTemp();
                    yyval.tipo = "bool";
                    yyval.declaracao += yyvsp[-1].declaracao + yyvsp[0].declaracao + "\t" + "int" + " " + yyval.label + ";\n";
                    yyval.traducao += yyvsp[-1].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + "!" + yyvsp[0].label + ";\n";
                }
            }
#line 2395 "y.tab.c"
    break;

  case 56:
#line 720 "sintatica.y"
            {	
				operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0], "+");
            }
#line 2403 "y.tab.c"
    break;

  case 57:
#line 724 "sintatica.y"
            {
				operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0], "-");
            }
#line 2411 "y.tab.c"
    break;

  case 58:
#line 728 "sintatica.y"
            {
				operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0], "*");
            }
#line 2419 "y.tab.c"
    break;

  case 59:
#line 732 "sintatica.y"
            {
				operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0], "/");
            }
#line 2427 "y.tab.c"
    break;

  case 60:
#line 736 "sintatica.y"
            {   
                //E -> VAR  
                if(verificaVar(yyvsp[0].label)){
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo == "bool" && pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].tipo != "bool"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo != "bool" && pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].tipo == "bool"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo == "char" && pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].tipo != "char"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo != "char" && pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].tipo == "char"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo == "string" && pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].tipo != "string"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo != "string" && pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].tipo == "string"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if(pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].atribuido == 0){
                       yyerror("ERRO: Variável " + yyvsp[0].label + " sem valor atribuido");
                    }
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo == "int" && pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].tipo == "string"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo == "int" && yyvsp[0].tipo != "int"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if(pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].tipo == "string" && pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo != "string"){
                    yyerror("ERRO: Tipos difentes!");
                }
                    
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo == "float" && pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].tipo == "int"){
                        pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].atribuido = 1;
                        yyval.label = genTemp();
                        yyval.declaracao += yyvsp[-2].declaracao + yyvsp[0].declaracao + "\t" + "float" + " " + yyval.label + ";\n";
                        yyval.traducao += yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + "(" + "float" + ")" + pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].temp + ";\n";
                        yyval.traducao += "\t" + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + " = " + yyval.label + ";\n";
				    }
                    else if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo == "int" && yyvsp[0].tipo == "float"){
                        pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].atribuido = 1;
                        yyval.label = genTemp();
                        yyval.declaracao += yyvsp[-2].declaracao + yyvsp[0].declaracao + "\t" + "int" + " " + yyval.label + ";\n";
                        yyval.traducao += yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + "(" + "int" + ")" + pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].temp + ";\n";
                        yyval.traducao += "\t" + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + " = " + yyval.label + ";\n";
                    }
				    //IGUAIS
                    else{
                        pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].atribuido = 1;
                        yyval.declaracao += yyvsp[-2].declaracao + yyvsp[0].declaracao;
                            if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo == "string"){
                                pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].valor = yyvsp[0].valor;
                                yyval.traducao += "\t" + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + " = " + string("(char*) malloc(") + to_string(pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].valor.length()-1) + string(")") + ";\n";
                                yyval.traducao += "\t" + string("strcpy(") + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + string(", ") + pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].temp + ");\n";
                            }else{
                                yyval.traducao += yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + " = " + pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].temp + ";\n";
                            }
                        pilha_malloc.push_back(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp);
                    }
                }
                else{
                    //E -> NUM
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo == "bool" && yyvsp[0].tipo != "bool"){
                        yyerror("ERRO: Tipos difentes!");
                    } 
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo != "bool" && yyvsp[0].tipo == "bool"){
                        yyerror("ERRO: Tipos difentes!");
                    } 
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo == "char" && yyvsp[0].tipo != "char"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo != "char" && yyvsp[0].tipo == "char"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if((pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo == "string") && (yyvsp[0].tipo != "string")){
                        yyerror("ERRO: Tipos difentes!");
                    }    
                    if(yyvsp[0].tipo == "string" && pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo != "string"){
                    yyerror("ERRO: Tipos difentes!");
                }   
                    
                    
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo == "float" && yyvsp[0].tipo == "int"){
                        pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].atribuido = 1;
                        yyvsp[0].tipo = "float";
                        yyval.label = genTemp();
                        yyval.declaracao += yyvsp[-2].declaracao + yyvsp[0].declaracao + "\t" + yyvsp[0].tipo + " " + yyval.label + ";\n";
                        yyval.traducao += yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + "(" + yyvsp[0].tipo + ")" + yyvsp[0].label + ";\n";
                        yyval.traducao += "\t" + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + " = " + yyval.label + ";\n";
                    }
                    else if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo == "int" && yyvsp[0].tipo == "float"){
                        pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].atribuido = 1;
                        yyvsp[0].tipo = "int";
                        yyval.label = genTemp();
                        yyval.declaracao += yyvsp[-2].declaracao + yyvsp[0].declaracao + "\t" + yyvsp[0].tipo + " " + yyval.label + ";\n";
                        yyval.traducao += yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + "(" + yyvsp[0].tipo + ")" + yyvsp[0].label + ";\n";
                        yyval.traducao += "\t" + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + " = " + yyval.label + ";\n";
                    }
                    //IGUAIS -string
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo == "string"){
                        if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].atribuido == 1){
                            int i;
                            for (i = 0; i < pilha_malloc.size(); i++) {
                                if (pilha_malloc[i] == pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp) {
                                    break; 
                                }
                            }
                            string aux = pilha_malloc[i];  // Obter o último elemento da pilha
                            pilha_malloc.erase(pilha_malloc.begin() + i);  // Remover o último elemento da pilha
                            yyval.traducao += string("\t") + string("free(") + aux + ");\n";  // Adicionar a instrução 
                        }
                        pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].atribuido = 1;
                        pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].valor = yyvsp[0].valor;
                        yyval.declaracao += yyvsp[-2].declaracao + yyvsp[0].declaracao;
                        yyval.traducao += "\t" + string("strcpy(") + yyvsp[0].label + string(", ") + yyvsp[0].valor + ");\n";
                        yyval.traducao += "\t" + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + " = " + string("(char*) malloc(") + to_string(yyvsp[0].valor.length()-1) + string(")") + ";\n";
                        yyval.traducao += "\t" + string("strcpy(") + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + string(", ") + yyvsp[0].label + ");\n";
                        pilha_malloc.push_back(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp);
                    }
                    else{
                        pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].atribuido = 1;
                        yyval.declaracao += yyvsp[-2].declaracao + yyvsp[0].declaracao;
                        yyval.traducao += yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + " = " + yyvsp[0].label + ";\n";
                    }
                }
            }
#line 2560 "y.tab.c"
    break;

  case 61:
#line 865 "sintatica.y"
            {
				yyval.tipo = "int";
				yyval.label = genTemp();
				yyval.declaracao += "\t" + yyval.tipo + " " + yyval.label + ";\n";
				yyval.traducao += "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";

                //$$.label = $1.label;
            }
#line 2573 "y.tab.c"
    break;

  case 62:
#line 874 "sintatica.y"
            {
                yyval.tipo = "float";
                yyval.label = genTemp();
                yyval.declaracao += "\t" + yyval.tipo + " " + yyval.label + ";\n";
                yyval.traducao += "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
                //$$.label = $1.label;
            }
#line 2585 "y.tab.c"
    break;

  case 63:
#line 882 "sintatica.y"
            {
                yyval.tipo = "char";
                yyval.label = genTemp();
                yyval.declaracao += "\t" + yyval.tipo + " " + yyval.label + ";\n";
                yyval.traducao += "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
                //$$.label = $1.label;
            }
#line 2597 "y.tab.c"
    break;

  case 64:
#line 890 "sintatica.y"
            {
                yyval.label = genTemp();
                yyval.tipo = "string";
                yyval.valor = yyvsp[0].label;
                yyval.declaracao += "\t" + string("char") + " " + yyval.label + string("[") +to_string(yyvsp[0].label.length()-1) +string("]")+ ";\n";
                yyval.traducao += "\t" + string("strcpy(") + yyval.label + ", " + yyvsp[0].label + ");\n";
                //$$.label = $1.label;
            }
#line 2610 "y.tab.c"
    break;

  case 65:
#line 899 "sintatica.y"
            {
                string valor = "0";
                string tipo = "int";
                yyval.tipo = "bool";
                yyval.label = genTemp();
                yyval.declaracao += "\t" + tipo + " " + yyval.label + ";\n";
                yyval.traducao += "\t" + yyval.label + " = " + valor + ";\n";
                //$$.label = valor;
            }
#line 2624 "y.tab.c"
    break;

  case 66:
#line 909 "sintatica.y"
            {
                string valor = "1";
                string tipo = "int";
                yyval.tipo = "bool";
                yyval.label = genTemp();
                yyval.declaracao += "\t" + tipo + " " + yyval.label + ";\n";
                yyval.traducao += "\t" + yyval.label + " = " + valor + ";\n";
                //$$.label = valor;
            }
#line 2638 "y.tab.c"
    break;

  case 67:
#line 919 "sintatica.y"
            {   
                yyval.tipo = "float";
                yyval.label = genTemp();

                yyval.declaracao += "\t" + yyval.tipo + " " + yyval.label + ";\n";

                //CAST VAR
                if(verificaVar(yyvsp[0].label)){
                    yyval.traducao += "\t" + yyval.label + " = "  + "(float)"  + pilha[bloco_atual][yyvsp[0].label].temp + ";\n";
                }
                //CAST NUM
                else if(!verificaVar(yyvsp[0].label)){
                    yyval.declaracao += yyvsp[-1].declaracao + yyvsp[0].declaracao;
                    yyval.traducao += yyvsp[-1].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = "  + "(float)"  + yyvsp[0].label + ";\n";
                }
            }
#line 2659 "y.tab.c"
    break;

  case 68:
#line 936 "sintatica.y"
            {   
                yyval.tipo = "int";
                yyval.label = genTemp();

                yyval.declaracao += "\t" + yyval.tipo + " " + yyval.label + ";\n";

                //CAST VAR
                if(verificaVar(yyvsp[0].label)){
                    yyval.traducao += "\t" + yyval.label + " = "  + "(int)"  + pilha[bloco_atual][yyvsp[0].label].temp + ";\n";
                }
                //CAST NUM
                else if(!verificaVar(yyvsp[0].label)){
                    yyval.declaracao += yyvsp[-1].declaracao + yyvsp[0].declaracao;
                    yyval.traducao += yyvsp[-1].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = "  + "(int)"  + yyvsp[0].label + ";\n";
                }
            }
#line 2680 "y.tab.c"
    break;

  case 69:
#line 953 "sintatica.y"
            {   
                yyval.tipo = "char";
                yyval.label = genTemp();

                yyval.declaracao += "\t" + yyval.tipo + " " + yyval.label + ";\n";

                //CAST VAR
                if(verificaVar(yyvsp[0].label)){
                    yyval.traducao += "\t" + yyval.label + " = "  + "(char)"  + pilha[bloco_atual][yyvsp[0].label].temp + ";\n";
                }
                //CAST NUM
                else if(!verificaVar(yyvsp[0].label)){
                    yyval.declaracao += yyvsp[-1].declaracao + yyvsp[0].declaracao;
                    yyval.traducao += yyvsp[-1].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = "  + "(char)"  + yyvsp[0].label + ";\n";
                }
            }
#line 2701 "y.tab.c"
    break;

  case 70:
#line 970 "sintatica.y"
            {
                naoDeclarado(yyvsp[0].label);
                //TIPO_SIMBOLO var = pilha[bloco_atual][$1.label];
                //$$.tipo = var.tipo;
            }
#line 2711 "y.tab.c"
    break;

  case 71:
#line 976 "sintatica.y"
            {
                
            }
#line 2719 "y.tab.c"
    break;


#line 2723 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval);
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 981 "sintatica.y"


#include "lex.yy.c"

int yyparse();

string genTemp()
{
	temp++;
	return  "t" + std::to_string(temp);
}
string genRot()
{
	tempRot++;
	return  "label_" + std::to_string(tempRot);
}

void declarado(string chave){
	if (verificaVarBloco(chave))
    	yyerror("ERRO: Variável " + chave + " já foi declarada!");
}

void naoDeclarado(string chave){
	if (!verificaVar(chave))
		yyerror("ERRO: Variável " + chave + " não foi declarada!");
}

int verificaVar(string var){
    for(int i=bloco_atual;i>=0;i--){
        if(!(pilha[i].find(var) == pilha[i].end())){
            return 1;
        }
    }  
    return 0;
}

int verificaVarBloco(string var){
    if(!(pilha[bloco_atual].find(var) == pilha[bloco_atual].end())){
        return 1;
    }
    return 0;
}

int busca_escopo(string var){
    for(int i= bloco_atual; i>=0; i--){
        if(!(pilha[i].find(var) == pilha[i].end())){
            return pilha[i][var].bloco;
        }
    } 
    yyerror("ERRO: Variável " + var + " não foi declarada!");  
    return 0;
} 

void conversaoImplicitaOp(atributos& $$, atributos& $1, atributos& $3, string operador, string tipo){
    //NUMERO NUMERO
    if(!verificaVar($1.label) && !verificaVar($3.label)){
        if(($1.tipo == "int" && $3.tipo == "float") || ($1.tipo == "float" && $3.tipo == "int") ){
            $$.label = genTemp();
            $$.tipo = "float";
            $$.declaracao += $1.declaracao + $3.declaracao + "\t" + $$.tipo + " " + $$.label + ";\n";
            $$.traducao += $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $$.tipo + ")" + $1.label + ";\n";

            string aux = $$.label;
            $$.label = genTemp();
            if(operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                $$.tipo = "float";
            }
            else{
                $$.tipo = "bool";
            }
            
            $$.declaracao += "\t" + tipo + " " + $$.label + ";\n"; 
            $$.traducao += "\t" + $$.label + " = " + aux + " " + operador + " " + $3.label + ";\n";
        }
        else{
            $$.label = genTemp();
            if(operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                $$.tipo = $1.tipo;
            }
            else{
                $$.tipo = "bool";
            }
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " " + operador + " " + $3.label + ";\n";
            $$.declaracao = $1.declaracao + $3.declaracao +"\t" + tipo + " " + $$.label + ";\n";
        }
    }
    //VAR NUMERO
    else if(verificaVar($1.label) && !verificaVar($3.label)){
        if((pilha[busca_escopo($1.label)][$1.label].tipo == "int" && $3.tipo == "float") || (pilha[busca_escopo($1.label)][$1.label].tipo == "float" && $3.tipo == "int") ){
            $$.label = genTemp();
            $$.tipo = "float";
            $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $$.tipo + " " + $$.label + ";\n";
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $$.tipo + ")" + pilha[busca_escopo($1.label)][$1.label].temp + ";\n";

            string aux = $$.label;
            $$.label = genTemp();
            if(operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                $$.tipo = "float";
            }
            else{
                $$.tipo = "bool";
            }
            
            $$.declaracao += "\t" + tipo + " " + $$.label + ";\n"; 
            $$.traducao += "\t" + $$.label + " = " + aux + " " + operador + " " + $3.label + ";\n";
        }
        else{
            $$.label = genTemp();
            if(operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                $$.tipo = pilha[busca_escopo($1.label)][$1.label].tipo;
            }
            else{
                $$.tipo = "bool";
            }
            $$.declaracao = $1.declaracao + $3.declaracao + "\t" + tipo + " " + $$.label + ";\n";
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + pilha[busca_escopo($1.label)][$1.label].temp + " " + operador + " " + $3.label + ";\n";
        }
    }
    //NUMERO VAR
    else if(!verificaVar($1.label) && verificaVar($3.label)){
        if(($1.tipo == "int" && pilha[busca_escopo($3.label)][$3.label].tipo == "float") || ($1.tipo == "float" && pilha[busca_escopo($3.label)][$3.label].tipo == "int") ){
            $$.label = genTemp();
            $$.tipo = "float";
            $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $$.tipo + " " + $$.label + ";\n";
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $$.tipo + ")" + $1.label + ";\n";

            string aux = $$.label;
            $$.label = genTemp();
            if(operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                $$.tipo = "float";
            }
            else{
                $$.tipo = "bool";
            }
            
            $$.declaracao += "\t" + tipo + " " + $$.label + ";\n"; 
            $$.traducao += "\t" + $$.label + " = " + aux + " " + operador + " " + pilha[busca_escopo($3.label)][$3.label].temp + ";\n";
        }
        else{
            $$.label = genTemp();
            if(operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                $$.tipo = $1.tipo;
            }
            else{
                $$.tipo = "bool";
            }
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " " + operador + " " + pilha[busca_escopo($3.label)][$3.label].temp + ";\n";
            $$.declaracao = $1.declaracao + $3.declaracao +"\t" + tipo + " " + $$.label + ";\n";
        }
    }
    //VAR VAR
    else if(verificaVar($1.label) && verificaVar($3.label)){
        if((pilha[busca_escopo($1.label)][$1.label].tipo == "int" && pilha[busca_escopo($3.label)][$3.label].tipo == "float") || (pilha[busca_escopo($1.label)][$1.label].tipo == "float" && pilha[busca_escopo($3.label)][$3.label].tipo == "int") ){
            $$.label = genTemp();
            $$.tipo = "float";
            $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $$.tipo + " " + $$.label + ";\n";
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $$.tipo + ")" + pilha[busca_escopo($1.label)][$1.label].temp + ";\n";

            string aux = $$.label;
            $$.label = genTemp();
            if(operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                $$.tipo = "float";
            }
            else{
                $$.tipo = "bool";
            }
            
            $$.declaracao += "\t" + tipo + " " + $$.label + ";\n"; 
            $$.traducao += "\t" + $$.label + " = " + aux + " " + operador + " " + pilha[busca_escopo($3.label)][$3.label].temp + ";\n";
        }
        else{
            $$.label = genTemp();
            if(operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                $$.tipo = pilha[busca_escopo($1.label)][$1.label].tipo;
            }
            else{
                $$.tipo = "bool";
            }
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + pilha[busca_escopo($1.label)][$1.label].temp + " " + operador + " " + pilha[busca_escopo($3.label)][$3.label].temp + ";\n";
            $$.declaracao = $1.declaracao + $3.declaracao +"\t" + tipo + " " + $$.label + ";\n";
        }
    }
}

void operacao(atributos& $$, atributos& $1, atributos& $2, atributos& $3, string operador){
    if(verificaVar($1.label) || verificaVar($3.label)){
        // $1 var
        if(verificaVar($1.label)){
            if (pilha[busca_escopo($1.label)][$1.label].atribuido == 0){
                yyerror("ERRO: variável " + $1.label + " sem valor atribuido!");
            }
            if(operador == "||" || operador == "&&"){
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "int" || pilha[busca_escopo($1.label)][$1.label].tipo  == "float" || pilha[busca_escopo($1.label)][$1.label].tipo == "char" || pilha[busca_escopo($1.label)][$1.label].tipo == "string" || $3.tipo == "int" || $3.tipo == "float" || $3.tipo == "char" || $3.tipo == "string"){
                    yyerror("ERRO: Operadores lógicos só aceitam tipo Booleano!");
                }
            }
            if(operador == ">" || operador == "<" || operador == ">=" || operador == "<="){
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "bool" ||  $3.tipo == "bool"){
                    yyerror("ERRO: Operadores relacionais não aceitam tipo Booleano!");
                }
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "string" ||  $3.tipo == "string"){
                    yyerror("ERRO: Operadores relacionais não aceitam tipo string!");
                }
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "char" ||  $3.tipo == "char"){
                yyerror("ERRO: Operadores relacionais não aceitam tipo char!");
                }
            }
            if (operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "bool" || $3.tipo == "bool"){
                    yyerror("Erro: operações aritiméticas não aceitam booleanos!");
                }
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "string" ||  $3.tipo == "string"){
                    yyerror("ERRO: Operadores aritiméticos não aceitam tipo string!");
                }
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "char" ||  $3.tipo == "char"){
                    yyerror("ERRO: Operadores aritiméticos não aceitam tipo char!");
                }
            }
        }
        // $3 var
        if(verificaVar($3.label)){ 
            if (pilha[busca_escopo($3.label)][$3.label].atribuido == 0){
                yyerror("ERRO: Variável " + $3.label + " sem valor atribuido!");
            }
            if(operador == "||" || operador == "&&"){
                if($1.tipo == "int" || $1.tipo == "float" || $1.tipo == "char" || $1.tipo == "string" || pilha[busca_escopo($3.label)][$3.label].tipo == "int" || pilha[busca_escopo($3.label)][$3.label].tipo == "float" || pilha[busca_escopo($3.label)][$3.label].tipo == "char" || pilha[busca_escopo($3.label)][$3.label].tipo == "string"){
                    yyerror("ERRO: Operadores Lógicos só aceitam tipo Booleano!");
                }
            }
            if(operador == ">" || operador == "<" || operador == ">=" || operador == "<="){
                if($1.tipo == "bool" ||  pilha[busca_escopo($3.label)][$3.label].tipo == "bool"){
                    yyerror("ERRO: Operadores Relacionais não aceitam tipo Booleano!");
                }
                if($1.tipo == "string" ||  pilha[busca_escopo($3.label)][$3.label].tipo == "string"){
                    yyerror("ERRO: Operadores Relacionais não aceitam tipo string!");
                }
                if($1.tipo == "char" ||  pilha[busca_escopo($3.label)][$3.label].tipo == "char"){
                yyerror("ERRO: Operadores relacionais não aceitam tipo char!");
                }
            }
            if (operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                if($1.tipo == "bool" || pilha[busca_escopo($3.label)][$3.label].tipo == "bool"){
                    yyerror("Erro: operações aritiméticas não aceitam booleanos!");
                }
                if($1.tipo == "string" ||  pilha[busca_escopo($3.label)][$3.label].tipo == "string"){
                    yyerror("ERRO: Operadores aritiméticos não aceitam tipo string!");
                }
                if($1.tipo == "char" ||  pilha[busca_escopo($3.label)][$3.label].tipo == "char"){
                    yyerror("ERRO: Operadores aritiméticos não aceitam tipo char!");
                }
            }
        }
        // $1 e $3 var
        if(verificaVar($1.label) && verificaVar($3.label)){
            if (pilha[busca_escopo($1.label)][$1.label].atribuido == 0){
                yyerror("ERRO: Variável " + $1.label + " sem valor atribuido!");
            }
            if (pilha[busca_escopo($3.label)][$3.label].atribuido == 0){
                yyerror("ERRO: Variável " + $3.label + " sem valor atribuido!");
            }
            if(operador == "||" || operador == "&&"){
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "int" || pilha[busca_escopo($1.label)][$1.label].tipo == "float" || pilha[busca_escopo($1.label)][$1.label].tipo == "char" || pilha[busca_escopo($1.label)][$1.label].tipo == "string" || pilha[busca_escopo($3.label)][$3.label].tipo == "int" || pilha[busca_escopo($3.label)][$3.label].tipo == "float" || pilha[busca_escopo($3.label)][$3.label].tipo == "char" || pilha[busca_escopo($3.label)][$3.label].tipo == "string"){
                    yyerror("ERRO: Operadores Lógicos só aceitam tipo Booleano!");
                }
            }
            if(operador == ">" || operador == "<" || operador == ">=" || operador == "<="){
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "bool" ||  pilha[busca_escopo($3.label)][$3.label].tipo == "bool"){
                    yyerror("ERRO: Operadores Relacionais não aceitam tipo Booleano!");
                }
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "string" ||  pilha[busca_escopo($3.label)][$3.label].tipo == "string"){
                    yyerror("ERRO: Operadores Relacionais não aceitam tipo string!");
                }
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "char" ||  pilha[busca_escopo($3.label)][$3.label].tipo == "char"){
                yyerror("ERRO: Operadores relacionais não aceitam tipo char!");
            }
            }
            if (operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "bool" || pilha[busca_escopo($3.label)][$3.label].tipo == "bool"){
                    yyerror("Erro: operações aritiméticas não aceitam booleanos!");
                }
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "string" ||  pilha[busca_escopo($3.label)][$3.label].tipo == "string"){
                    yyerror("ERRO: Operadores aritiméticos não aceitam tipo string!");
                }
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "char" ||  pilha[busca_escopo($3.label)][$3.label].tipo == "char"){
                    yyerror("ERRO: Operadores aritiméticos não aceitam tipo char!");
                }
            }
        }
    }
    // $1 e $3 não var
    else{
        if(operador == "||" || operador == "&&"){
            if(pilha[busca_escopo($1.label)][$1.label].tipo == "int" || pilha[busca_escopo($1.label)][$1.label].tipo == "float" || pilha[busca_escopo($1.label)][$1.label].tipo == "char" || pilha[busca_escopo($1.label)][$1.label].tipo == "string" || $3.tipo == "int" || $3.tipo == "float" || $3.tipo == "char" || $3.tipo == "string"){
                yyerror("ERRO: Operadores Lógicos só aceitam tipo Booleano!");
            }
        }
        if(operador == ">" || operador == "<" || operador == ">=" || operador == "<="){
            if($1.tipo == "bool" ||  $3.tipo == "bool"){
                yyerror("ERRO: Operadores relacionais não aceitam tipo Booleano!");
            }
            if($1.tipo == "string" ||  $3.tipo == "string"){
                yyerror("ERRO: Operadores relacionais não aceitam tipo string!");
            }
            if($1.tipo == "char" ||  $3.tipo == "char"){
                yyerror("ERRO: Operadores relacionais não aceitam tipo char!");
            }
        }
        if (operador == "+" || operador == "-" || operador == "*" || operador == "/"){
            if($1.tipo == "bool" || $3.tipo == "bool"){
                yyerror("Erro: operações aritiméticas não aceitam booleanos!");
            }
            if($1.tipo == "string" ||  $3.tipo == "string"){
                yyerror("ERRO: Operadores aritiméticos não aceitam tipo string!");
            }
            if($1.tipo == "char" ||  $3.tipo == "char"){
                yyerror("ERRO: Operadores aritiméticos não aceitam tipo char!");
            }
        }
    }

    //relacionanis e lógicos
    if(operador == ">" || operador == "<" || operador == ">=" || operador == "<=" || operador == "==" || operador == "!=" || operador == "&&" || operador == "||"){
        conversaoImplicitaOp($$, $1, $3, operador, "int");
    }
    
    //aritimeticos
    if(operador == "+" || operador == "-" || operador == "*" || operador == "/"){
        conversaoImplicitaOp($$,$1,$3,operador,"int");
    }
}

void empilha(){
    pilha.push_back(unordered_map<string, TIPO_SIMBOLO>());
}

void desempilha(){
    pilha.pop_back();
}

int main( int argc, char* argv[] )
{
	temp = 0;
    tempRot = 0;
	yyparse();
	

	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}
