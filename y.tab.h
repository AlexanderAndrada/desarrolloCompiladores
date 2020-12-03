
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 61 "analizadorSintactico.y"

	char var[20];
	int valor;



/* Line 1676 of yacc.c  */
#line 165 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


