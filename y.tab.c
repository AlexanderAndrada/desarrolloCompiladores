
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
#include "tercetos.c"
#include "tercetos.h"

//int yylval;
int yystopparser=0;
FILE  *yyin;
char *yyltext;
char *yytext;
char *stringConstante;
int indiceString;
int indiceStringAux;
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
int buscarString;
int buscarFactor;
int buscarTermino;
int buscarExpresion;
int buscarAsignacion;
int indicePut;
int indiceGet;
int tipoVariable;


int ultimoTerceto;



/* Line 189 of yacc.c  */
#line 135 "y.tab.c"

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
     MULTIPLICACION = 262,
     SUMA = 263,
     COMENTARIO = 264,
     CONCAT = 265,
     RESTA = 266,
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
     BOOLEAN = 293,
     ASIGESPMAS = 294,
     ASIGESPMENOS = 295,
     ASIGESPMULTIPLICACION = 296,
     ASIGESPDIVISION = 297,
     STRING = 298,
     JNA = 299,
     JNAE = 300,
     JNB = 301,
     JNBE = 302,
     JE = 303,
     JNE = 304,
     ENDIF = 305,
     TRUE = 306,
     ENDSENTENCE = 307,
     ENDWHILE = 308
   };
#endif
/* Tokens.  */
#define IDENTIFICADOR 258
#define CONSTANTE 259
#define REAL 260
#define MAIN 261
#define MULTIPLICACION 262
#define SUMA 263
#define COMENTARIO 264
#define CONCAT 265
#define RESTA 266
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
#define BOOLEAN 293
#define ASIGESPMAS 294
#define ASIGESPMENOS 295
#define ASIGESPMULTIPLICACION 296
#define ASIGESPDIVISION 297
#define STRING 298
#define JNA 299
#define JNAE 300
#define JNB 301
#define JNBE 302
#define JE 303
#define JNE 304
#define ENDIF 305
#define TRUE 306
#define ENDSENTENCE 307
#define ENDWHILE 308




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 63 "analizadorSintactico.y"

	char var[40];
	int valor;



/* Line 214 of yacc.c  */
#line 284 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 296 "y.tab.c"

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
#define YYLAST   174

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNRULES -- Number of states.  */
#define YYNSTATES  130

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     9,    14,    18,    21,    25,    27,    29,
      31,    33,    35,    37,    40,    43,    47,    50,    53,    55,
      57,    59,    61,    63,    64,    70,    72,    73,    78,    79,
      84,    88,    92,    95,    99,   100,   101,   108,   110,   111,
     116,   117,   122,   126,   127,   133,   137,   140,   144,   145,
     151,   155,   159,   162,   165,   168,   171,   174,   176,   178,
     182,   184,   186,   190,   194,   196,   200,   204,   206,   208,
     210,   212,   214,   216,   218,   220,   222,   225
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,     6,    23,    56,    60,    24,    -1,     6,
      23,    60,    24,    -1,    34,    57,    20,    -1,    58,    59,
      -1,    57,    58,    59,    -1,    36,    -1,    35,    -1,    43,
      -1,    38,    -1,    37,    -1,     3,    -1,    59,     3,    -1,
      61,    20,    -1,    60,    61,    20,    -1,    29,    62,    -1,
      27,    70,    -1,    88,    -1,    82,    -1,    83,    -1,    93,
      -1,    92,    -1,    -1,    21,    63,    64,    22,    68,    -1,
      67,    -1,    -1,    67,    65,    32,    67,    -1,    -1,    67,
      66,    33,    67,    -1,    87,    90,    88,    -1,    23,    69,
      24,    -1,    61,    20,    -1,    69,    61,    20,    -1,    -1,
      -1,    21,    71,    73,    22,    72,    77,    -1,    76,    -1,
      -1,    76,    74,    32,    76,    -1,    -1,    76,    75,    33,
      76,    -1,    87,    90,    88,    -1,    -1,    23,    79,    24,
      78,    80,    -1,    23,    79,    24,    -1,    61,    20,    -1,
      79,    61,    20,    -1,    -1,    28,    23,    81,    79,    24,
      -1,     3,    13,    88,    -1,     3,    13,    85,    -1,     3,
      84,    -1,    39,    88,    -1,    40,    88,    -1,    41,    88,
      -1,    42,    88,    -1,    86,    -1,    43,    -1,    43,    10,
      43,    -1,    88,    -1,    89,    -1,    88,    11,    89,    -1,
      88,     8,    89,    -1,    91,    -1,    89,     7,    91,    -1,
      89,    12,    91,    -1,    14,    -1,    15,    -1,    17,    -1,
      16,    -1,    18,    -1,    19,    -1,     3,    -1,    35,    -1,
      36,    -1,    31,     3,    -1,    30,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    91,    91,    98,   108,   112,   113,   117,   119,   121,
     123,   125,   130,   138,   149,   150,   154,   155,   156,   157,
     158,   159,   160,   184,   184,   195,   199,   199,   204,   204,
     212,   219,   224,   225,   229,   231,   229,   238,   241,   241,
     245,   245,   253,   259,   259,   262,   269,   270,   274,   274,
     284,   292,   304,   314,   315,   316,   317,   321,   322,   332,
     349,   353,   356,   361,   369,   372,   377,   385,   386,   387,
     388,   389,   390,   394,   401,   407,   416,   424
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFICADOR", "CONSTANTE", "REAL",
  "MAIN", "MULTIPLICACION", "SUMA", "COMENTARIO", "CONCAT", "RESTA",
  "DIVISION", "ASIG", "MAYOR", "MENOR", "MAYORIGUAL", "MENORIGUAL",
  "IGUAL", "DISTINTO", "PUNTOYCOMA", "ABRIRPARENTESIS", "CERRARPARENTESIS",
  "ABRIRLLAVE", "CERRARLLAVE", "ABRIRCORCHETE", "CERRARCORCHETE", "IF",
  "ELSE", "WHILE", "PUT", "GET", "AND", "OR", "DECLARE", "INT", "FLOAT",
  "DOUBLE", "BOOLEAN", "ASIGESPMAS", "ASIGESPMENOS",
  "ASIGESPMULTIPLICACION", "ASIGESPDIVISION", "STRING", "JNA", "JNAE",
  "JNB", "JNBE", "JE", "JNE", "ENDIF", "TRUE", "ENDSENTENCE", "ENDWHILE",
  "$accept", "programa", "declaracion", "sentenciadeclaracion", "tipo",
  "identificadorintermedio", "sentencias", "sentencia", "sentenciawhile",
  "$@1", "sentenciacomparacionwhile", "$@2", "$@3",
  "expresioncomparacionwhile", "sentenciainicialwhile",
  "sentenciaintermediawhile", "sentenciaif", "$@4", "$@5",
  "sentenciacomparacionif", "$@6", "$@7", "expresioncomparacionif",
  "sentenciainicialif", "$@8", "sentenciaintermediaif", "sentenciaelse",
  "$@9", "asignacion", "asignacionespecial", "asignadorespecial",
  "expresionstrings", "expresionconcat", "expresion2", "expresion",
  "termino", "comparadores", "factor", "lectura", "escritura", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    56,    57,    57,    58,    58,    58,
      58,    58,    59,    59,    60,    60,    61,    61,    61,    61,
      61,    61,    61,    63,    62,    64,    65,    64,    66,    64,
      67,    68,    69,    69,    71,    72,    70,    73,    74,    73,
      75,    73,    76,    78,    77,    77,    79,    79,    81,    80,
      82,    82,    83,    84,    84,    84,    84,    85,    85,    86,
      87,    88,    88,    88,    89,    89,    89,    90,    90,    90,
      90,    90,    90,    91,    91,    91,    92,    93
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     3,     2,     3,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     2,     2,     1,     1,
       1,     1,     1,     0,     5,     1,     0,     4,     0,     4,
       3,     3,     2,     3,     0,     0,     6,     1,     0,     4,
       0,     4,     3,     0,     5,     3,     2,     3,     0,     5,
       3,     3,     2,     2,     2,     2,     2,     1,     1,     3,
       1,     1,     3,     3,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,    73,     0,     0,     0,     0,
       0,    74,    75,     0,     0,     0,    19,    20,    18,    61,
      64,    22,    21,     0,     0,     0,     0,     0,    52,    34,
      17,    23,    16,    77,    76,     8,     7,    11,    10,     9,
       0,     0,     0,     3,     0,    14,     0,     0,     0,     0,
      73,    58,    51,    57,    50,    53,    54,    55,    56,     0,
       0,     4,     0,    12,     5,     2,    15,    63,    62,    65,
      66,     0,     0,    37,     0,    60,     0,    25,     0,     6,
      13,    59,    35,     0,     0,    67,    68,    70,    69,    71,
      72,     0,     0,     0,     0,     0,     0,     0,     0,    42,
       0,    24,     0,     0,    30,     0,    36,    39,    41,     0,
       0,    27,    29,     0,     0,    32,    31,     0,    46,    43,
       0,    33,     0,    47,     0,    44,    48,     0,     0,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    13,    40,    41,    64,    14,    15,    32,    60,
      76,    93,    94,    77,   101,   110,    30,    59,    96,    72,
      83,    84,    73,   106,   122,   114,   125,   127,    16,    17,
      28,    52,    53,    74,    18,    19,    91,    20,    21,    22
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -70
static const yytype_int16 yypact[] =
{
       2,     8,    27,    23,   -70,   122,    24,    25,    48,    57,
     -25,   -70,   -70,   123,    58,    42,   -70,   -70,    21,    18,
     -70,   -70,   -70,     4,     6,     6,     6,     6,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     131,    60,    68,   -70,    44,   -70,     6,     6,     6,     6,
     -70,    55,   -70,   -70,    21,    21,    21,    21,    21,     6,
       6,   -70,    60,   -70,    63,   -70,   -70,    18,    18,   -70,
     -70,    29,    45,   -18,     5,    21,    46,   -16,     5,    63,
     -70,   -70,   -70,    38,    41,   -70,   -70,   -70,   -70,   -70,
     -70,     6,    54,    47,    50,     6,    67,     6,     6,    21,
     123,   -70,     6,     6,    21,   123,   -70,   -70,   -70,    82,
      81,   -70,   -70,    86,    98,   -70,   -70,    87,   -70,    89,
      99,   -70,    90,   -70,    97,   -70,   -70,   123,   112,   -70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -70,   -70,   -70,   -70,    83,    16,   108,   -14,   -70,   -70,
     -70,   -70,   -70,   -69,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -62,   -70,   -70,     3,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -54,   -22,    -3,    53,     7,   -70,   -70
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -46
static const yytype_int16 yytable[] =
{
      44,    54,    55,    56,    57,    58,    78,    50,     1,    50,
      35,    36,    37,    38,   -38,   -40,   -26,   -28,    39,    85,
      86,    87,    88,    89,    90,    48,     5,     4,    44,    46,
      49,     3,    47,   111,   112,   107,   108,    75,    75,    11,
      12,    11,    12,    67,    68,    29,    31,    51,    78,    78,
       6,    33,     7,     8,     9,    69,    70,    10,    11,    12,
      34,     5,    45,    63,    66,    71,    80,    82,    92,    99,
      97,     5,    81,   104,    98,    75,    75,   100,    79,   102,
      75,    75,    43,   103,     5,     6,   109,     7,     8,     9,
     105,   113,    65,    11,    12,     6,   117,     7,     8,     9,
     120,     5,   115,    11,    12,   116,   118,   121,     6,   -45,
       7,     8,     9,   113,   120,     5,    11,    12,   124,   123,
     126,    42,   119,    62,     0,     6,     5,     7,     8,     9,
     128,    95,     0,    11,    12,    23,   129,     0,     0,     6,
       0,     7,     8,     9,     0,     0,     0,    11,    12,     0,
       6,    61,     7,     8,     9,     0,     0,     0,    11,    12,
       0,    24,    25,    26,    27,     0,    35,    36,    37,    38,
       0,     0,     0,     0,    39
};

static const yytype_int16 yycheck[] =
{
      14,    23,    24,    25,    26,    27,    60,     3,     6,     3,
      35,    36,    37,    38,    32,    33,    32,    33,    43,    14,
      15,    16,    17,    18,    19,     7,     3,     0,    42,     8,
      12,    23,    11,   102,   103,    97,    98,    59,    60,    35,
      36,    35,    36,    46,    47,    21,    21,    43,   102,   103,
      27,     3,    29,    30,    31,    48,    49,    34,    35,    36,
       3,     3,    20,     3,    20,    10,     3,    22,    22,    91,
      32,     3,    43,    95,    33,    97,    98,    23,    62,    32,
     102,   103,    24,    33,     3,    27,   100,    29,    30,    31,
      23,   105,    24,    35,    36,    27,   110,    29,    30,    31,
     114,     3,    20,    35,    36,    24,    20,    20,    27,    20,
      29,    30,    31,   127,   128,     3,    35,    36,    28,    20,
      23,    13,    24,    40,    -1,    27,     3,    29,    30,    31,
     127,    78,    -1,    35,    36,    13,    24,    -1,    -1,    27,
      -1,    29,    30,    31,    -1,    -1,    -1,    35,    36,    -1,
      27,    20,    29,    30,    31,    -1,    -1,    -1,    35,    36,
      -1,    39,    40,    41,    42,    -1,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    55,    23,     0,     3,    27,    29,    30,    31,
      34,    35,    36,    56,    60,    61,    82,    83,    88,    89,
      91,    92,    93,    13,    39,    40,    41,    42,    84,    21,
      70,    21,    62,     3,     3,    35,    36,    37,    38,    43,
      57,    58,    60,    24,    61,    20,     8,    11,     7,    12,
       3,    43,    85,    86,    88,    88,    88,    88,    88,    71,
      63,    20,    58,     3,    59,    24,    20,    89,    89,    91,
      91,    10,    73,    76,    87,    88,    64,    67,    87,    59,
       3,    43,    22,    74,    75,    14,    15,    16,    17,    18,
      19,    90,    22,    65,    66,    90,    72,    32,    33,    88,
      23,    68,    32,    33,    88,    23,    77,    76,    76,    61,
      69,    67,    67,    61,    79,    20,    24,    61,    20,    24,
      61,    20,    78,    20,    28,    80,    23,    81,    79,    24
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
#line 91 "analizadorSintactico.y"
    {
		printf("Main OK\n");
		escribirTablaSimbolos();
		guardarArchivoTercetos();

		//generarAssembler(devolverTercetos(),devolverCantidadTercetos(),devolverTercetoResultado(),devolverCantidadSimbolos());
		}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 98 "analizadorSintactico.y"
    {
		printf("Main OK\n");
		escribirTablaSimbolos();
		guardarArchivoTercetos();

		//generarAssembler(devolverTercetos(),devolverCantidadTercetos(),devolverTercetoResultado(),devolverCantidadSimbolos());
		}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 108 "analizadorSintactico.y"
    {printf("Declaraciones ok\n");}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 117 "analizadorSintactico.y"
    {
		tipoVariable=FLOAT;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 119 "analizadorSintactico.y"
    {
		tipoVariable=INT;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 121 "analizadorSintactico.y"
    {
		tipoVariable=STRING;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 123 "analizadorSintactico.y"
    {
		tipoVariable=BOOLEAN;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 125 "analizadorSintactico.y"
    {
		tipoVariable=DOUBLE;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 130 "analizadorSintactico.y"
    {
		indiceIdentificador = buscarPosicionTablaSimbolos((yyvsp[(1) - (1)].var));
		validarExistenciaVariable(indiceIdentificadorIntermedio,(yyvsp[(1) - (1)].var));
		indiceTipo = agregarTipoTablaDeSimbolos(tipoVariable);
		indiceIdentificadorIntermedio = agregarNombreTablaDeSimbolos(indiceTipo,(yyvsp[(1) - (1)].var));
		crear_terceto(NOOP, NOOP, indiceIdentificadorIntermedio);
		contadorVariables++;
		}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 138 "analizadorSintactico.y"
    {
		indiceIdentificador = buscarPosicionTablaSimbolos((yyvsp[(2) - (2)].var));
		validarExistenciaVariable(indiceIdentificadorIntermedio,(yyvsp[(2) - (2)].var));
		indiceTipo = agregarTipoTablaDeSimbolos(tipoVariable);		
		indiceIdentificadorIntermedio = agregarNombreTablaDeSimbolos(indiceTipo,(yyvsp[(2) - (2)].var));
		crear_terceto(NOOP, NOOP, indiceIdentificadorIntermedio);
		contadorVariables++;		
		}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 149 "analizadorSintactico.y"
    {printf("Sentencia ok\n");}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 154 "analizadorSintactico.y"
    {printf("While ok\n");}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 155 "analizadorSintactico.y"
    {printf("If ok\n");}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 156 "analizadorSintactico.y"
    {printf("Expresion ok\n");}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 157 "analizadorSintactico.y"
    {printf("Asignacion ok\n");}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 158 "analizadorSintactico.y"
    {printf("Asignacion especial ok\n");}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 184 "analizadorSintactico.y"
    {
		contadorWhile++;banderaWhileAnd[contadorWhile]=0;banderaWhileOr[contadorWhile]=0;
		indiceWhileCondicion[contadorWhile]=crear_terceto(WHILE, NOOP, NOOP);
		printf("numero de While: %d ",contadorWhile);}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 188 "analizadorSintactico.y"
    {
		indiceWhileFin[contadorWhile]=crear_terceto(ENDWHILE, NOOP, NOOP);
		modificarTerceto(indiceWhileAux[contadorWhile],OP2,indiceWhileFin[contadorWhile]);
		contadorWhile--;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 195 "analizadorSintactico.y"
    {
		printf("Sentencia comparacion WHILE ok\n");
		
		indiceWhileAux[contadorWhile]=crear_terceto(cambiarComparador(indiceComparador), NOOP, NOOP);}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 199 "analizadorSintactico.y"
    {
		indiceWhileAuxAnd[contadorWhile]=crear_terceto(cambiarComparador(indiceComparador), NOOP, NOOP);}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 201 "analizadorSintactico.y"
    {
		banderaWhileAnd[contadorIf]=1;printf("Sentencia AND comparacion WHILE ok\n");
		indiceWhileAux[contadorIf]=crear_terceto(cambiarComparador(indiceComparador), NOOP, NOOP);}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 204 "analizadorSintactico.y"
    {
		indiceWhileAuxOr[contadorIf]=crear_terceto(JMP, NOOP, NOOP);}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 206 "analizadorSintactico.y"
    {
		banderaWhileOr[contadorIf]=1;indiceWhileAux[contadorIf]=crear_terceto(cambiarComparador(indiceComparador), NOOP, NOOP);
		printf("Sentencia OR comparacion WHILE ok\n");}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 212 "analizadorSintactico.y"
    {
		crear_terceto(indiceComparador, indiceExpresion, indiceExpresion2);
		printf("Condicion WHILE ok\n");
	}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 219 "analizadorSintactico.y"
    {
	crear_terceto(JMP, NOOP, indiceWhileCondicion[contadorWhile]);}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 229 "analizadorSintactico.y"
    {
		contadorIf++;banderaIfAnd[contadorIf]=0;banderaIfOr[contadorIf]=0;printf("numero de if: %d ",contadorIf);}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 231 "analizadorSintactico.y"
    {
		if(banderaIfOr[contadorIf]==1) modificarTerceto(indiceIfAuxOr[contadorIf],OP2,crear_terceto(TRUE, NOOP, NOOP));}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 233 "analizadorSintactico.y"
    {
		printf("Sentencia if ok\n");contadorIf--;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 238 "analizadorSintactico.y"
    {
		printf("Sentencia comparacion IF ok\n");
		indiceIfAux[contadorIf]=crear_terceto(cambiarComparador(indiceComparador), NOOP, NOOP);}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 241 "analizadorSintactico.y"
    {
		indiceIfAuxAnd[contadorIf]=crear_terceto(cambiarComparador(indiceComparador), NOOP, NOOP);}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 243 "analizadorSintactico.y"
    {
		banderaIfAnd[contadorIf]=1;printf("Sentencia AND comparacion IF ok\n");indiceIfAux[contadorIf]=crear_terceto(cambiarComparador(indiceComparador), NOOP, NOOP);}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 245 "analizadorSintactico.y"
    {
		indiceIfAuxOr[contadorIf]=crear_terceto(JMP, NOOP, NOOP);}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 247 "analizadorSintactico.y"
    {
		banderaIfOr[contadorIf]=1;indiceIfAux[contadorIf]=crear_terceto(cambiarComparador(indiceComparador), NOOP, NOOP);
		printf("Sentencia OR comparacion IF ok\n");}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 253 "analizadorSintactico.y"
    {
		crear_terceto(indiceComparador, indiceExpresion, indiceExpresion2);
		printf("Condicion IF ok\n");}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 259 "analizadorSintactico.y"
    {
		indiceIfFalso=crear_terceto(JMP, NOOP, NOOP);}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 262 "analizadorSintactico.y"
    {
		indiceAnd=crear_terceto(ENDIF, NOOP, NOOP);
		if(banderaIfAnd[contadorIf]==1) modificarTerceto(indiceIfAuxAnd[contadorIf],OP2,indiceAnd);
		modificarTerceto(indiceIfAux[contadorIf],OP2,indiceAnd); printf("Cuerpo en If sin ELSE ok\n");}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 274 "analizadorSintactico.y"
    {
		indiceAnd=crear_terceto(ELSE, NOOP, NOOP);
		if(banderaIfAnd[contadorIf]==1) modificarTerceto(indiceIfAuxAnd[contadorIf],OP2,indiceAnd);
		modificarTerceto(indiceIfAux[contadorIf],OP2,indiceAnd);}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 278 "analizadorSintactico.y"
    {
		indiceAnd=crear_terceto(ENDIF, NOOP, NOOP);
		modificarTerceto(indiceIfFalso,OP2,indiceAnd);}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 284 "analizadorSintactico.y"
    {
		indiceIdentificador = buscarPosicionTablaSimbolos((yyvsp[(1) - (3)].var));
		validarExistenciaVariable(indiceIdentificador,(yyvsp[(1) - (3)].var));		
		compararTipoVariable((yyvsp[(1) - (3)].var),buscarExpresion);
		indiceAsignacion = buscar_terceto(indiceIdentificador,contadorVariables);
		crear_terceto(ASIG, indiceExpresion, indiceAsignacion);
		printf("Asignacion ok\n",(yyvsp[(1) - (3)].var));
		}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 292 "analizadorSintactico.y"
    {
		//compararTipoVariable($1,buscarString); //alex
		indiceIdentificador = buscarPosicionTablaSimbolos((yyvsp[(1) - (3)].var));
		agregarValorTablaDeSimbolos(indiceIdentificador, stringConstante);

		//indiceAsignacion = buscar_terceto(indiceIdentificador,contadorVariables);
		//crear_terceto(ASIG, indiceString, indiceAsignacion);
		printf("Asignacion string ok\n",(yyvsp[(1) - (3)].var));
		}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 304 "analizadorSintactico.y"
    {
		indiceIdentificador = buscarPosicionTablaSimbolos((yyvsp[(1) - (2)].var));
		indiceAsignacion = buscar_terceto(indiceIdentificador,contadorVariables);
		indiceAsignacionEspecial = crear_terceto(indiceAsignacionEspecial, indiceExpresion, indiceAsignacion);
		indiceAsignacionEspecial = crear_terceto(ASIG,indiceAsignacionEspecial,indiceAsignacion);
		printf("asigesp es: %d\n", indiceAsignacionEspecial );
		}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 314 "analizadorSintactico.y"
    {indiceAsignacionEspecial=SUMA;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 315 "analizadorSintactico.y"
    {indiceAsignacionEspecial=RESTA;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 316 "analizadorSintactico.y"
    {indiceAsignacionEspecial=MULTIPLICACION;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 317 "analizadorSintactico.y"
    {indiceAsignacionEspecial=DIVISION;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 322 "analizadorSintactico.y"
    {
		stringConstante = (yyvsp[(1) - (1)].var);
		//indiceString = agregarTipoTablaDeSimbolos(STRING);
		//indiceString = agregarNombreTablaDeSimbolos(indiceString,$1);
		//indiceString = crear_terceto(NOOP, NOOP, indiceString);
		//buscarString = $1;
		}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 332 "analizadorSintactico.y"
    {
		printf("Entra aca, a concatenacion \n");
		verificarLargoString((yyvsp[(1) - (3)].var),(yyvsp[(3) - (3)].var));
		indiceString = agregarTipoTablaDeSimbolos(STRING);
		indiceString = agregarNombreTablaDeSimbolos(indiceString,(yyvsp[(1) - (3)].var));
		indiceStringAux = agregarTipoTablaDeSimbolos(STRING);
		indiceStringAux = agregarNombreTablaDeSimbolos(indiceStringAux,(yyvsp[(3) - (3)].var));
		indiceString = crear_terceto(NOOP, NOOP, indiceString);
		indiceStringAux = crear_terceto(NOOP, NOOP, indiceStringAux);
		indiceString = crear_terceto(CONCAT, indiceStringAux, indiceString);
		buscarString = (yyvsp[(1) - (3)].var);		
		printf("El string es: %s %s ",(yyvsp[(1) - (3)].var),(yyvsp[(3) - (3)].var));
		}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 349 "analizadorSintactico.y"
    {indiceExpresion2 = indiceExpresion;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 353 "analizadorSintactico.y"
    {
		indiceExpresion = indiceTermino;
		buscarExpresion=buscarTermino;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 356 "analizadorSintactico.y"
    {
		compararTipoVariable(buscarTermino,buscarExpresion);	
		printf("Resta OK\n");
		indiceExpresion=crear_terceto(RESTA, indiceExpresion,indiceTermino);
		}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 361 "analizadorSintactico.y"
    {
		compararTipoVariable(buscarTermino,buscarExpresion);	
		printf("Suma OK\n");
		indiceExpresion=crear_terceto(SUMA, indiceExpresion,indiceTermino);
		}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 369 "analizadorSintactico.y"
    {
		indiceTermino = indiceFactor;
		buscarTermino=buscarFactor;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 372 "analizadorSintactico.y"
    {
		compararTipoVariable(buscarFactor,buscarTermino);
		printf("Multiplicacion OK\n");
		indiceTermino=crear_terceto(MULTIPLICACION, indiceFactor,indiceTermino);
		   }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 377 "analizadorSintactico.y"
    {
		compararTipoVariable(buscarFactor,buscarTermino);		
		printf("Division OK\n");
		indiceTermino=crear_terceto(DIVISION, indiceFactor,indiceTermino);
		  }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 385 "analizadorSintactico.y"
    {indiceComparador=MAYOR;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 386 "analizadorSintactico.y"
    {indiceComparador=MENOR;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 387 "analizadorSintactico.y"
    {indiceComparador=MENORIGUAL;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 388 "analizadorSintactico.y"
    {indiceComparador=MAYORIGUAL;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 389 "analizadorSintactico.y"
    {indiceComparador=IGUAL;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 390 "analizadorSintactico.y"
    {indiceComparador=DISTINTO;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 394 "analizadorSintactico.y"
    {
		indiceIdentificador = buscarPosicionTablaSimbolos((yyvsp[(1) - (1)].var));
		validarExistenciaVariable(indiceIdentificador,(yyvsp[(1) - (1)].var));
		indiceFactor = buscar_terceto(indiceIdentificador,contadorVariables);
		buscarFactor=(yyvsp[(1) - (1)].var);		
		//printf("\nLa variable es: %d\n", indiceFactor);		
		}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 401 "analizadorSintactico.y"
    {
		indiceConstante = agregarTipoTablaDeSimbolos(INT);
		indiceConstante = agregarNombreTablaDeSimbolos(indiceConstante,(yyvsp[(1) - (1)].var));
		indiceFactor = crear_terceto(NOOP, NOOP, indiceConstante);
		buscarFactor=(yyvsp[(1) - (1)].var);		
		}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 407 "analizadorSintactico.y"
    {
		indiceReal = agregarTipoTablaDeSimbolos(FLOAT);
		indiceReal = agregarNombreTablaDeSimbolos(indiceReal,(yyvsp[(1) - (1)].var));
		indiceFactor = crear_terceto(NOOP, NOOP, indiceReal);
		buscarFactor=(yyvsp[(1) - (1)].var);		
		}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 416 "analizadorSintactico.y"
    {
			indiceGet = buscarPosicionTablaSimbolos((yyvsp[(2) - (2)].var));
			validarExistenciaVariable(indiceGet,(yyvsp[(2) - (2)].var));	
			crear_terceto(GET, NOOP, indiceGet);
		}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 424 "analizadorSintactico.y"
    {
		indicePut = buscarPosicionTablaSimbolos((yyvsp[(2) - (2)].var));
		validarExistenciaVariable(indicePut,(yyvsp[(2) - (2)].var));	
		crear_terceto(PUT, NOOP, indicePut);
		}
    break;



/* Line 1455 of yacc.c  */
#line 2235 "y.tab.c"
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
#line 431 "analizadorSintactico.y"


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
