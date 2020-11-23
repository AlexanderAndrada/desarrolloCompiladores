
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 2 "analizadorSintactico.y"

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "y.tab.h"
#include "tercetos.h"

//int yylval;
int yystopparser=0;
FILE  *yyin;
char *yyltext;
char *yytext;
int indiceIdentificador;
int indiceConstante;
int indiceReal;
int indiceFactor;
int indiceTermino;
int indiceExpresion;
int indiceExpresion2;
int indiceIdentificadorIntermedio;
int indiceComparador;
int indiceAsignacionEspecial;
int indiceAsigEspSuma;
int indiceAsignacion;
int indiceIfAux[9];
int indiceIfAuxAnd[9];
int indiceIfAuxOr[9];
int indiceIfFalso;
int indiceIfVerdadero;
int indiceAnd;
int indiceWhileCondicion[9];
int indiceWhileFin[9];
int indiceWhileAux[9];
int indiceWhileAuxAnd[9];
int indiceWhileAuxOr[9];
int banderaIfAnd[9];
int banderaIfOr[9];
int banderaWhileAnd[9];
int banderaWhileOr[9];
int contadorIf=0;
int contadorWhile=0;
int contadorVariables=0;
int indiceTipo;


int ultimoTerceto;



/* Line 189 of yacc.c  */
#line 123 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFICADOR = 258,
     CONSTANTE = 259,
     REAL = 260,
     MAIN = 261,
     COMENTARIO = 262,
     CONCAT = 263,
     SUMA = 264,
     RESTA = 265,
     MULTIPLICACION = 266,
     DIVISION = 267,
     ASIG = 268,
     MAYOR = 269,
     MENOR = 270,
     MAYORIGUAL = 271,
     MENORIGUAL = 272,
     IGUAL = 273,
     DISTINTO = 274,
     PUNTOYCOMA = 275,
     ABRIRPARENTESIS = 276,
     CERRARPARENTESIS = 277,
     ABRIRLLAVE = 278,
     CERRARLLAVE = 279,
     ABRIRCORCHETE = 280,
     CERRARCORCHETE = 281,
     IF = 282,
     ELSE = 283,
     WHILE = 284,
     PUT = 285,
     GET = 286,
     AND = 287,
     OR = 288,
     DECLARE = 289,
     INT = 290,
     FLOAT = 291,
     DOUBLE = 292,
     CHAR = 293,
     BOOLEAN = 294,
     ASIGESPMAS = 295,
     ASIGESPMENOS = 296,
     ASIGESPMULTIPLICACION = 297,
     ASIGESPDIVISION = 298,
     STRING = 299,
     JNA = 300,
     ENDIF = 301,
     TRUE = 302,
     ENDSENTENCE = 303,
     ENDWHILE = 304
   };
#endif
/* Tokens.  */
#define IDENTIFICADOR 258
#define CONSTANTE 259
#define REAL 260
#define MAIN 261
#define COMENTARIO 262
#define CONCAT 263
#define SUMA 264
#define RESTA 265
#define MULTIPLICACION 266
#define DIVISION 267
#define ASIG 268
#define MAYOR 269
#define MENOR 270
#define MAYORIGUAL 271
#define MENORIGUAL 272
#define IGUAL 273
#define DISTINTO 274
#define PUNTOYCOMA 275
#define ABRIRPARENTESIS 276
#define CERRARPARENTESIS 277
#define ABRIRLLAVE 278
#define CERRARLLAVE 279
#define ABRIRCORCHETE 280
#define CERRARCORCHETE 281
#define IF 282
#define ELSE 283
#define WHILE 284
#define PUT 285
#define GET 286
#define AND 287
#define OR 288
#define DECLARE 289
#define INT 290
#define FLOAT 291
#define DOUBLE 292
#define CHAR 293
#define BOOLEAN 294
#define ASIGESPMAS 295
#define ASIGESPMENOS 296
#define ASIGESPMULTIPLICACION 297
#define ASIGESPDIVISION 298
#define STRING 299
#define JNA 300
#define ENDIF 301
#define TRUE 302
#define ENDSENTENCE 303
#define ENDWHILE 304




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 51 "analizadorSintactico.y"

	char var[20];
	int valor;



/* Line 214 of yacc.c  */
#line 264 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 276 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   139

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNRULES -- Number of states.  */
#define YYNSTATES  141

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     9,    13,    16,    20,    22,    24,    26,
      28,    30,    32,    34,    37,    40,    44,    47,    50,    52,
      54,    56,    59,    62,    64,    68,    72,    73,    79,    81,
      82,    87,    88,    93,    97,   101,   104,   109,   110,   111,
     118,   120,   121,   126,   127,   132,   136,   137,   143,   147,
     150,   155,   156,   162,   166,   170,   173,   176,   179,   182,
     185,   189,   193,   195,   197,   201,   205,   207,   211,   215,
     217,   219,   221,   223,   225,   227,   229,   231,   233,   238
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,     6,    23,    52,    56,    24,    -1,    34,
      53,    20,    -1,    54,    55,    -1,    53,    54,    55,    -1,
      36,    -1,    35,    -1,    44,    -1,    39,    -1,    38,    -1,
      37,    -1,     3,    -1,    55,     3,    -1,    57,    20,    -1,
      56,    57,    20,    -1,    29,    60,    -1,    27,    68,    -1,
      85,    -1,    80,    -1,    81,    -1,    30,    58,    -1,    31,
      59,    -1,    59,    -1,    21,    44,    22,    -1,    21,     3,
      22,    -1,    -1,    21,    61,    62,    22,    66,    -1,    65,
      -1,    -1,    65,    63,    32,    65,    -1,    -1,    65,    64,
      33,    65,    -1,    84,    87,    85,    -1,    23,    67,    24,
      -1,    57,    20,    -1,    67,    20,    57,    20,    -1,    -1,
      -1,    21,    69,    71,    22,    70,    75,    -1,    74,    -1,
      -1,    74,    72,    32,    74,    -1,    -1,    74,    73,    33,
      74,    -1,    84,    87,    85,    -1,    -1,    23,    77,    24,
      76,    78,    -1,    23,    77,    24,    -1,    57,    20,    -1,
      77,    20,    57,    20,    -1,    -1,    28,    23,    79,    77,
      24,    -1,     3,    13,    85,    -1,     3,    13,    83,    -1,
       3,    82,    -1,    40,    85,    -1,    41,    85,    -1,    42,
      85,    -1,    43,    85,    -1,    44,     8,    44,    -1,    83,
       8,    44,    -1,    85,    -1,    86,    -1,    85,    10,    86,
      -1,    85,     9,    86,    -1,    88,    -1,    86,    11,    88,
      -1,    86,    12,    88,    -1,    14,    -1,    15,    -1,    17,
      -1,    16,    -1,    18,    -1,    19,    -1,     3,    -1,     4,
      -1,     5,    -1,     3,    25,     4,    26,    -1,    44,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    76,    76,    86,    90,    91,    95,    96,    97,    98,
      99,   100,   104,   112,   121,   122,   126,   127,   128,   129,
     130,   131,   132,   136,   137,   141,   145,   145,   156,   159,
     159,   164,   164,   172,   179,   184,   185,   189,   191,   189,
     198,   200,   200,   204,   204,   212,   218,   218,   221,   228,
     229,   233,   233,   243,   250,   260,   273,   274,   275,   276,
     280,   282,   287,   291,   292,   296,   303,   304,   308,   315,
     316,   317,   318,   319,   320,   324,   329,   336,   342,   343
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFICADOR", "CONSTANTE", "REAL",
  "MAIN", "COMENTARIO", "CONCAT", "SUMA", "RESTA", "MULTIPLICACION",
  "DIVISION", "ASIG", "MAYOR", "MENOR", "MAYORIGUAL", "MENORIGUAL",
  "IGUAL", "DISTINTO", "PUNTOYCOMA", "ABRIRPARENTESIS", "CERRARPARENTESIS",
  "ABRIRLLAVE", "CERRARLLAVE", "ABRIRCORCHETE", "CERRARCORCHETE", "IF",
  "ELSE", "WHILE", "PUT", "GET", "AND", "OR", "DECLARE", "INT", "FLOAT",
  "DOUBLE", "CHAR", "BOOLEAN", "ASIGESPMAS", "ASIGESPMENOS",
  "ASIGESPMULTIPLICACION", "ASIGESPDIVISION", "STRING", "JNA", "ENDIF",
  "TRUE", "ENDSENTENCE", "ENDWHILE", "$accept", "programa", "declaracion",
  "sentenciadeclaracion", "tipo", "identificadorintermedio", "sentencias",
  "sentencia", "sentenciaparentesis", "factorparentesis", "sentenciawhile",
  "$@1", "sentenciacomparacionwhile", "$@2", "$@3",
  "expresioncomparacionwhile", "sentenciainicialwhile",
  "sentenciaintermediawhile", "sentenciaif", "$@4", "$@5",
  "sentenciacomparacionif", "$@6", "$@7", "expresioncomparacionif",
  "sentenciainicialif", "$@8", "sentenciaintermediaif", "sentenciaelse",
  "$@9", "asignacion", "asignacionespecial", "asignadorespecial",
  "expresionstrings", "expresion2", "expresion", "termino", "comparadores",
  "factor", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    53,    53,    54,    54,    54,    54,
      54,    54,    55,    55,    56,    56,    57,    57,    57,    57,
      57,    57,    57,    58,    58,    59,    61,    60,    62,    63,
      62,    64,    62,    65,    66,    67,    67,    69,    70,    68,
      71,    72,    71,    73,    71,    74,    76,    75,    75,    77,
      77,    79,    78,    80,    80,    81,    82,    82,    82,    82,
      83,    83,    84,    85,    85,    85,    86,    86,    86,    87,
      87,    87,    87,    87,    87,    88,    88,    88,    88,    88
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     2,     2,     1,     1,
       1,     2,     2,     1,     3,     3,     0,     5,     1,     0,
       4,     0,     4,     3,     3,     2,     4,     0,     0,     6,
       1,     0,     4,     0,     4,     3,     0,     5,     3,     2,
       4,     0,     5,     3,     3,     2,     2,     2,     2,     2,
       3,     3,     1,     1,     3,     3,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     7,     6,    11,
      10,     9,     8,     0,     0,    75,    76,    77,     0,     0,
       0,     0,    79,     0,     0,    19,    20,    18,    63,    66,
       3,     0,    12,     4,     0,     0,     0,     0,     0,     0,
      55,    37,    17,    26,    16,     0,    21,    23,     0,    22,
       2,     0,    14,     0,     0,     0,     0,     5,    13,    75,
      79,    54,    53,     0,    56,    57,    58,    59,     0,     0,
       0,     0,    15,    65,    64,    67,    68,     0,     0,    78,
       0,    40,     0,    62,     0,    28,     0,    25,    24,    60,
      61,    38,     0,     0,    69,    70,    72,    71,    73,    74,
       0,     0,     0,     0,     0,     0,     0,     0,    45,     0,
      27,     0,     0,    33,     0,    39,    42,    44,     0,     0,
      30,    32,     0,     0,    35,     0,    34,    49,     0,    46,
       0,     0,     0,    36,    50,     0,    47,    51,     0,     0,
      52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,    13,    14,    33,    23,   122,    46,    47,
      44,    69,    84,   102,   103,    85,   110,   119,    42,    68,
     105,    80,    92,    93,    81,   115,   132,   123,   136,   138,
      25,    26,    40,    61,    82,    27,    28,   100,    29
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -68
static const yytype_int8 yypact[] =
{
       3,    35,    21,    -1,   -68,    60,    19,   -68,   -68,   -68,
     -68,   -68,   -68,    49,    52,    40,   -68,   -68,    41,    45,
      51,    56,   -68,    10,    44,   -68,   -68,    -2,    20,   -68,
     -68,    52,   -68,    65,     7,    66,    15,    15,    15,    15,
     -68,   -68,   -68,   -68,   -68,    13,   -68,   -68,    91,   -68,
     -68,    82,   -68,    15,    15,    15,    15,    65,   -68,    83,
      99,   101,    -2,    84,    -2,    -2,    -2,    -2,    15,    15,
      89,    90,   -68,    20,    20,   -68,   -68,    69,    70,   -68,
      93,    28,    11,    -2,    94,    43,    11,   -68,   -68,   -68,
     -68,   -68,    85,    87,   -68,   -68,   -68,   -68,   -68,   -68,
      15,    95,    92,    88,    15,   100,    15,    15,    -2,    19,
     -68,    15,    15,    -2,    19,   -68,   -68,   -68,   105,    18,
     -68,   -68,   106,    23,   -68,    19,   -68,   -68,    19,   107,
     108,   109,   102,   -68,   -68,   110,   -68,   -68,    19,    32,
     -68
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -68,   -68,   -68,   -68,   118,   103,   -68,    -6,   -68,   111,
     -68,   -68,   -68,   -68,   -68,   -22,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -15,   -68,   -68,    -3,   -68,   -68,
     -68,   -68,   -68,   -68,   -67,   -33,    47,    53,    50
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -49
static const yytype_int16 yytable[] =
{
      24,    62,    86,    64,    65,    66,    67,    53,    54,     1,
      59,    16,    17,    15,    16,    17,    70,    51,    59,    16,
      17,     4,    15,    16,    17,    94,    95,    96,    97,    98,
      99,    55,    56,     5,    50,    83,    83,    18,   125,    19,
      20,    21,   126,   128,    86,    86,    18,   129,    19,    20,
      21,    60,   128,    34,    22,    32,   140,    71,     3,    22,
     -41,   -43,    41,    22,    52,    35,    43,   108,    58,    30,
      63,   113,    45,    83,    83,   -29,   -31,    48,    83,    83,
      36,    37,    38,    39,     7,     8,     9,    10,    11,   120,
     121,   116,   117,    12,    70,     7,     8,     9,    10,    11,
      73,    74,    72,   118,    12,    75,    76,    77,    35,    78,
      79,    87,    88,    89,    90,    91,   101,   106,   109,   130,
     107,   112,   131,   114,   111,   124,   127,   -48,   133,   134,
     135,    31,    49,   137,    57,   139,     0,     0,     0,   104
};

static const yytype_int16 yycheck[] =
{
       6,    34,    69,    36,    37,    38,    39,     9,    10,     6,
       3,     4,     5,     3,     4,     5,     3,    23,     3,     4,
       5,     0,     3,     4,     5,    14,    15,    16,    17,    18,
      19,    11,    12,    34,    24,    68,    69,    27,    20,    29,
      30,    31,    24,    20,   111,   112,    27,    24,    29,    30,
      31,    44,    20,    13,    44,     3,    24,    44,    23,    44,
      32,    33,    21,    44,    20,    25,    21,   100,     3,    20,
       4,   104,    21,   106,   107,    32,    33,    21,   111,   112,
      40,    41,    42,    43,    35,    36,    37,    38,    39,   111,
     112,   106,   107,    44,     3,    35,    36,    37,    38,    39,
      53,    54,    20,   109,    44,    55,    56,     8,    25,     8,
      26,    22,    22,    44,    44,    22,    22,    32,    23,   125,
      33,    33,   128,    23,    32,    20,    20,    20,    20,    20,
      28,    13,    21,    23,    31,   138,    -1,    -1,    -1,    86
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    51,    23,     0,    34,    52,    35,    36,    37,
      38,    39,    44,    53,    54,     3,     4,     5,    27,    29,
      30,    31,    44,    56,    57,    80,    81,    85,    86,    88,
      20,    54,     3,    55,    13,    25,    40,    41,    42,    43,
      82,    21,    68,    21,    60,    21,    58,    59,    21,    59,
      24,    57,    20,     9,    10,    11,    12,    55,     3,     3,
      44,    83,    85,     4,    85,    85,    85,    85,    69,    61,
       3,    44,    20,    86,    86,    88,    88,     8,     8,    26,
      71,    74,    84,    85,    62,    65,    84,    22,    22,    44,
      44,    22,    72,    73,    14,    15,    16,    17,    18,    19,
      87,    22,    63,    64,    87,    70,    32,    33,    85,    23,
      66,    32,    33,    85,    23,    75,    74,    74,    57,    67,
      65,    65,    57,    77,    20,    20,    24,    20,    20,    24,
      57,    57,    76,    20,    20,    28,    78,    23,    79,    77,
      24
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 76 "analizadorSintactico.y"
    {
		printf("Main OK\n");
		escribirTablaSimbolos();
		guardarArchivoTercetos();

		generarAssembler(devolverTercetos(),devolverCantidadTercetos(),devolverTercetoResultado(),devolverCantidadSimbolos());
		}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 86 "analizadorSintactico.y"
    {printf("Declaraciones ok\n");}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 95 "analizadorSintactico.y"
    {indiceTipo = agregarTipoTablaDeSimbolos(FLOAT);}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 96 "analizadorSintactico.y"
    {indiceTipo = agregarTipoTablaDeSimbolos(INT);}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 97 "analizadorSintactico.y"
    {indiceTipo = agregarTipoTablaDeSimbolos(STRING);}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 98 "analizadorSintactico.y"
    {indiceTipo = agregarTipoTablaDeSimbolos(BOOLEAN);}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 99 "analizadorSintactico.y"
    {indiceTipo = agregarTipoTablaDeSimbolos(CHAR);}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 100 "analizadorSintactico.y"
    {indiceTipo = agregarTipoTablaDeSimbolos(DOUBLE);}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 104 "analizadorSintactico.y"
    {
		indiceIdentificador = buscarPosicionTablaSimbolos((yyvsp[(1) - (1)].var));
		validarExistenciaVariable(indiceIdentificadorIntermedio,(yyvsp[(1) - (1)].var));
		indiceIdentificadorIntermedio = agregarNombreTablaDeSimbolos(indiceTipo);

		crear_terceto(NOOP, NOOP, indiceIdentificadorIntermedio);
		contadorVariables++;
		}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 112 "analizadorSintactico.y"
    {
		//agregarVariableATablaDeSimbolos($2, IDENTIFICADOR);
		//indiceIdentificador = buscarPosicionTablaSimbolos($2);
		//crear_terceto(NOOP, NOOP, indiceIdentificador);
		contadorVariables++;		
		}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 121 "analizadorSintactico.y"
    {printf("Sentencia ok\n");}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 126 "analizadorSintactico.y"
    {printf("While ok\n");}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 127 "analizadorSintactico.y"
    {printf("If ok\n");}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 128 "analizadorSintactico.y"
    {printf("Expresion ok\n");}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 129 "analizadorSintactico.y"
    {printf("Asignacion ok\n");}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 130 "analizadorSintactico.y"
    {printf("Asignacion especial ok\n");}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 145 "analizadorSintactico.y"
    {
		contadorWhile++;banderaWhileAnd[contadorWhile]=0;banderaWhileOr[contadorWhile]=0;
		indiceWhileCondicion[contadorWhile]=crear_terceto(WHILE, NOOP, NOOP);
		printf("numero de While: %d ",contadorWhile);}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 149 "analizadorSintactico.y"
    {
		indiceWhileFin[contadorWhile]=crear_terceto(ENDSENTENCE, NOOP, NOOP);
		modificarTerceto(indiceWhileAux[contadorWhile],OP2,indiceWhileFin[contadorWhile]);
		contadorWhile--;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 156 "analizadorSintactico.y"
    {
		printf("Sentencia comparacion WHILE ok\n");
		indiceWhileAux[contadorWhile]=crear_terceto(JNA, NOOP, NOOP);}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 159 "analizadorSintactico.y"
    {
		indiceWhileAuxAnd[contadorWhile]=crear_terceto(JNA, NOOP, NOOP);}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 161 "analizadorSintactico.y"
    {
		banderaWhileAnd[contadorIf]=1;printf("Sentencia AND comparacion WHILE ok\n");
		indiceWhileAux[contadorIf]=crear_terceto(JNA, NOOP, NOOP);}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 164 "analizadorSintactico.y"
    {
		indiceWhileAuxOr[contadorIf]=crear_terceto(JMP, NOOP, NOOP);}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 166 "analizadorSintactico.y"
    {
		banderaWhileOr[contadorIf]=1;indiceWhileAux[contadorIf]=crear_terceto(JNA, NOOP, NOOP);
		printf("Sentencia OR comparacion WHILE ok\n");}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 172 "analizadorSintactico.y"
    {
		crear_terceto(indiceComparador, indiceExpresion, indiceExpresion2);
		printf("Condicion WHILE ok\n");
	}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 179 "analizadorSintactico.y"
    {
	crear_terceto(JMP, NOOP, indiceWhileCondicion[contadorWhile]);}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 189 "analizadorSintactico.y"
    {
		contadorIf++;banderaIfAnd[contadorIf]=0;banderaIfOr[contadorIf]=0;printf("numero de if: %d ",contadorIf);}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 191 "analizadorSintactico.y"
    {
		if(banderaIfOr[contadorIf]==1) modificarTerceto(indiceIfAuxOr[contadorIf],OP2,crear_terceto(TRUE, NOOP, NOOP));}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 193 "analizadorSintactico.y"
    {
		printf("Sentencia if ok\n");contadorIf--;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 198 "analizadorSintactico.y"
    {
		printf("Sentencia comparacion IF ok\n");indiceIfAux[contadorIf]=crear_terceto(JNA, NOOP, NOOP);}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 200 "analizadorSintactico.y"
    {
		indiceIfAuxAnd[contadorIf]=crear_terceto(JNA, NOOP, NOOP);}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 202 "analizadorSintactico.y"
    {
		banderaIfAnd[contadorIf]=1;printf("Sentencia AND comparacion IF ok\n");indiceIfAux[contadorIf]=crear_terceto(JNA, NOOP, NOOP);}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 204 "analizadorSintactico.y"
    {
		indiceIfAuxOr[contadorIf]=crear_terceto(JMP, NOOP, NOOP);}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 206 "analizadorSintactico.y"
    {
		banderaIfOr[contadorIf]=1;indiceIfAux[contadorIf]=crear_terceto(JNA, NOOP, NOOP);
		printf("Sentencia OR comparacion IF ok\n");}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 212 "analizadorSintactico.y"
    {
		crear_terceto(indiceComparador, indiceExpresion, indiceExpresion2);
		printf("Condicion IF ok\n");}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 218 "analizadorSintactico.y"
    {
		indiceIfFalso=crear_terceto(JMP, NOOP, NOOP);}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 221 "analizadorSintactico.y"
    {
		indiceAnd=crear_terceto(ENDIF, NOOP, NOOP);
		if(banderaIfAnd[contadorIf]==1) modificarTerceto(indiceIfAuxAnd[contadorIf],OP2,indiceAnd);
		modificarTerceto(indiceIfAux[contadorIf],OP2,indiceAnd); printf("Cuerpo en If sin ELSE ok\n");}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 233 "analizadorSintactico.y"
    {
		indiceAnd=crear_terceto(ELSE, NOOP, NOOP);
		if(banderaIfAnd[contadorIf]==1) modificarTerceto(indiceIfAuxAnd[contadorIf],OP2,indiceAnd);
		modificarTerceto(indiceIfAux[contadorIf],OP2,indiceAnd);}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 237 "analizadorSintactico.y"
    {
		indiceAnd=crear_terceto(ENDIF, NOOP, NOOP);
		modificarTerceto(indiceIfFalso,OP2,indiceAnd);}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 243 "analizadorSintactico.y"
    {
		printf("Var: %s Asignacion ok\n",(yyvsp[(1) - (3)].var));
		agregarVariableATablaDeSimbolos((yyvsp[(1) - (3)].var), IDENTIFICADOR);
		indiceIdentificador = buscarPosicionTablaSimbolos((yyvsp[(1) - (3)].var));
		indiceAsignacion = buscar_terceto(indiceIdentificador,contadorVariables);
		crear_terceto(ASIG, indiceExpresion, indiceAsignacion);
		}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 250 "analizadorSintactico.y"
    {
		printf("Var: %s Asignacion ok\n",(yyvsp[(1) - (3)].var));
		agregarVariableATablaDeSimbolos((yyvsp[(1) - (3)].var), IDENTIFICADOR);
		indiceIdentificador = buscarPosicionTablaSimbolos((yyvsp[(1) - (3)].var));
		indiceAsignacion = buscar_terceto(indiceIdentificador,contadorVariables);
		crear_terceto(ASIG, indiceExpresion, indiceAsignacion);
		}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 260 "analizadorSintactico.y"
    {
		agregarVariableATablaDeSimbolos((yyvsp[(1) - (2)].var), IDENTIFICADOR);
		indiceIdentificador = buscarPosicionTablaSimbolos((yyvsp[(1) - (2)].var));
		printf("asigesp es: %d\n", indiceAsignacionEspecial );
		indiceAsignacion = buscar_terceto(indiceIdentificador,contadorVariables);
		
		indiceAsignacionEspecial = crear_terceto(indiceAsignacionEspecial, indiceExpresion, indiceAsignacion);
		indiceAsignacionEspecial = crear_terceto(ASIG,indiceAsignacionEspecial,indiceAsignacion);

		}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 273 "analizadorSintactico.y"
    {indiceAsignacionEspecial=SUMA;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 274 "analizadorSintactico.y"
    {indiceAsignacionEspecial=RESTA;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 275 "analizadorSintactico.y"
    {indiceAsignacionEspecial=MULTIPLICACION;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 276 "analizadorSintactico.y"
    {indiceAsignacionEspecial=DIVISION;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 280 "analizadorSintactico.y"
    {
		printf("concatenacion de %s y %s ",(yyvsp[(1) - (3)].var),(yyvsp[(3) - (3)].var));}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 287 "analizadorSintactico.y"
    {indiceExpresion2 = indiceExpresion;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 291 "analizadorSintactico.y"
    {indiceExpresion = indiceTermino;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 292 "analizadorSintactico.y"
    {
		printf("Resta OK\n");
		indiceExpresion=crear_terceto(RESTA, indiceExpresion,indiceTermino);
		}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 296 "analizadorSintactico.y"
    {
		printf("Suma OK\n");
		indiceExpresion=crear_terceto(SUMA, indiceExpresion,indiceTermino);
		}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 303 "analizadorSintactico.y"
    {indiceTermino = indiceFactor;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 304 "analizadorSintactico.y"
    {
		   printf("Multiplicacion OK\n");
		   indiceTermino=crear_terceto(MULTIPLICACION, indiceFactor,indiceTermino);
		   }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 308 "analizadorSintactico.y"
    {
		  printf("Division OK\n");
		  indiceTermino=crear_terceto(DIVISION, indiceFactor,indiceTermino);
		  }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 315 "analizadorSintactico.y"
    {indiceComparador=MAYOR;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 316 "analizadorSintactico.y"
    {indiceComparador=MENOR;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 317 "analizadorSintactico.y"
    {indiceComparador=MENORIGUAL;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 318 "analizadorSintactico.y"
    {indiceComparador=MAYORIGUAL;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 319 "analizadorSintactico.y"
    {indiceComparador=IGUAL;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 320 "analizadorSintactico.y"
    {indiceComparador=DISTINTO;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 324 "analizadorSintactico.y"
    {
		indiceIdentificador = buscarPosicionTablaSimbolos((yyvsp[(1) - (1)].var));
		validarExistenciaVariable(indiceIdentificador,(yyvsp[(1) - (1)].var));
		indiceFactor = buscar_terceto(indiceIdentificador,contadorVariables);
		}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 329 "analizadorSintactico.y"
    {

		agregarVariableATablaDeSimbolos((yyvsp[(1) - (1)].var), CONSTANTE);
		indiceConstante = buscarPosicionTablaSimbolos((yyvsp[(1) - (1)].var));
		indiceFactor = crear_terceto(NOOP, NOOP, indiceConstante);
		printf("\nEl indiceFactor es: %d\n", indiceFactor);
		}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 336 "analizadorSintactico.y"
    {
		
		agregarVariableATablaDeSimbolos((yyvsp[(1) - (1)].var), REAL);
		indiceReal = buscarPosicionTablaSimbolos((yyvsp[(1) - (1)].var));
		indiceFactor = crear_terceto(NOOP, NOOP, indiceReal);
		}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 342 "analizadorSintactico.y"
    {printf("vector %s con %s espacios",(yyvsp[(1) - (4)].var),(yyvsp[(3) - (4)].var));}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 343 "analizadorSintactico.y"
    {printf("string: %s ",(yyvsp[(1) - (1)].var));}
    break;



/* Line 1455 of yacc.c  */
#line 2157 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 346 "analizadorSintactico.y"


int main(int argc,char *argv[])
{
  if ((yyin = fopen(argv[1], "rt")) == NULL)
  {
	  printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
  }
  else
  {
	yyparse();
    printf("\nCompilacion Ok\n");
  }
  
  fclose(yyin);
  return (0);
}

int yyerror(void)
{
  printf("Error de sintaxis\n");
	getchar();
	exit (1);
}
