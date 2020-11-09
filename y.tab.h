
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
     COMENTARIO = 262,
     SUMA = 263,
     RESTA = 264,
     MULTIPLICACION = 265,
     DIVISION = 266,
     ASIG = 267,
     MAYOR = 268,
     MENOR = 269,
     MAYORIGUAL = 270,
     MENORIGUAL = 271,
     IGUAL = 272,
     DISTINTO = 273,
     PUNTOYCOMA = 274,
     ABRIRPARENTESIS = 275,
     CERRARPARENTESIS = 276,
     ABRIRLLAVE = 277,
     CERRARLLAVE = 278,
     ABRIRCORCHETE = 279,
     CERRARCORCHETE = 280,
     IF = 281,
     ELSE = 282,
     WHILE = 283,
     PUT = 284,
     GET = 285,
     AND = 286,
     OR = 287,
     DECLARE = 288,
     INT = 289,
     FLOAT = 290,
     DOUBLE = 291,
     CHAR = 292,
     BOOLEAN = 293,
     ASIGESPMAS = 294,
     ASIGESPMENOS = 295,
     ASIGESPMULTIPLICACION = 296,
     ASIGESPDIVISION = 297,
     STRING = 298
   };
#endif
/* Tokens.  */
#define IDENTIFICADOR 258
#define CONSTANTE 259
#define REAL 260
#define MAIN 261
#define COMENTARIO 262
#define SUMA 263
#define RESTA 264
#define MULTIPLICACION 265
#define DIVISION 266
#define ASIG 267
#define MAYOR 268
#define MENOR 269
#define MAYORIGUAL 270
#define MENORIGUAL 271
#define IGUAL 272
#define DISTINTO 273
#define PUNTOYCOMA 274
#define ABRIRPARENTESIS 275
#define CERRARPARENTESIS 276
#define ABRIRLLAVE 277
#define CERRARLLAVE 278
#define ABRIRCORCHETE 279
#define CERRARCORCHETE 280
#define IF 281
#define ELSE 282
#define WHILE 283
#define PUT 284
#define GET 285
#define AND 286
#define OR 287
#define DECLARE 288
#define INT 289
#define FLOAT 290
#define DOUBLE 291
#define CHAR 292
#define BOOLEAN 293
#define ASIGESPMAS 294
#define ASIGESPMENOS 295
#define ASIGESPMULTIPLICACION 296
#define ASIGESPDIVISION 297
#define STRING 298




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 32 "analizadorSintactico.y"

	char var[20];
	int valor;



/* Line 1676 of yacc.c  */
#line 145 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


