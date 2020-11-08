
%{
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
int indiceFactor;
int indiceTermino;
int indiceExpresion;
int indiceIdentificadorIntermedio;
int indiceAsignacionEspecial;
int indiceAsigEspSuma;
int indiceAsignacion;


int ultimoTerceto;

%}

%union{
	char var[20];
	int valor;
}

%token <var> IDENTIFICADOR
%token <var> CONSTANTE
%token <var> REAL
%right MAIN
%token COMENTARIO
%token SUMA RESTA MULTIPLICACION DIVISION ASIG
%token MAYOR MENOR MAYORIGUAL MENORIGUAL IGUAL DISTINTO
%token PUNTOYCOMA ABRIRPARENTESIS CERRARPARENTESIS ABRIRLLAVE CERRARLLAVE ABRIRCORCHETE CERRARCORCHETE
%token IF ELSE WHILE PUT GET AND OR 
%token <var> DECLARE
%token <var> INT 
%token <var> FLOAT DOUBLE CHAR BOOLEAN
%token <var> ASIGESPMAS 
%token ASIGESPMENOS ASIGESPMULTIPLICACION ASIGESPDIVISION
%token <var> STRING


%%
programa:
	MAIN ABRIRLLAVE sentencias CERRARLLAVE {printf("Main OK\n");guardarArchivoTercetos();}
	;

sentencias:
	sentencia PUNTOYCOMA{printf("Sentencia ok\n"); escribirTablaSimbolos();}
	|sentencias sentencia PUNTOYCOMA {escribirTablaSimbolos();}
	;

sentencia:
	WHILE sentenciawhile {printf("While ok\n");}
	|IF sentenciaif {printf("If ok\n");}
	|declaretion PUNTOYCOMA {printf("Declaracion de variable ok\n");}
	|expresion {printf("Expresion ok\n");}
	|asignacion {printf("Asignacion ok\n");}
	|asignacionespecial {printf("Asignacion especial ok\n");}
	|PUT sentenciaparentesis
	|GET factorparentesis
	;

sentenciaparentesis:
	factorparentesis
	|ABRIRPARENTESIS STRING CERRARPARENTESIS
	;

factorparentesis:
	ABRIRPARENTESIS IDENTIFICADOR CERRARPARENTESIS
	;

sentenciawhile:
	ABRIRPARENTESIS sentenciacomparacionwhile CERRARPARENTESIS sentenciainicialwhile
	;

sentenciacomparacionwhile:
	expresioncomparacionwhile {printf("Sentencia comparacion WHILE ok\n");}
	|expresioncomparacionwhile AND expresioncomparacionwhile 
	|expresioncomparacionwhile OR expresioncomparacionwhile
	;

expresioncomparacionwhile:
	expresion comparadores expresion {printf("Condicion WHILE ok\n");}
	;

sentenciainicialwhile:
	ABRIRLLAVE sentenciaintermediawhile CERRARLLAVE
	;

sentenciaintermediawhile:
	sentencia
	|sentenciaintermediawhile PUNTOYCOMA sentencia
	;

sentenciaif:
	ABRIRPARENTESIS sentenciacomparacionif CERRARPARENTESIS sentenciainicialif {printf("Sentencia if ok\n");}
	;

sentenciacomparacionif:
	expresioncomparacionif {printf("Sentencia comparacion IF ok\n");}
	|expresioncomparacionif AND expresioncomparacionif {printf("Sentencia AND comparacion IF ok\n");}
	|expresioncomparacionif OR expresioncomparacionif {printf("Sentencia OR comparacion IF ok\n");}
	;

expresioncomparacionif:
	expresion comparadores expresion {printf("Condicion IF ok\n");}
	;

sentenciainicialif:
	ABRIRLLAVE sentenciaintermediaif CERRARLLAVE ELSE ABRIRLLAVE sentenciaintermediaif CERRARLLAVE
	|ABRIRLLAVE sentenciaintermediaif CERRARLLAVE {printf("Cuerpo en If sin ELSE ok\n");}
	;

sentenciaintermediaif:
	sentencia
	|sentenciaintermediaif PUNTOYCOMA sentencia
	;

asignacion:
	IDENTIFICADOR ASIG expresion {
		printf("Var: %s Asignacion ok\n",$1);
		agregarVariableATablaDeSimbolos($1, IDENTIFICADOR);
		indiceIdentificador = buscarPosicionTablaSimbolos($1);
		indiceAsignacion = crear_terceto(NOOP, NOOP, indiceIdentificador);
		crear_terceto(ASIG, indiceIdentificador,indiceExpresion);
		}
	;

asignacionespecial:
	IDENTIFICADOR asignadorespecial {
		agregarVariableATablaDeSimbolos($1, IDENTIFICADOR);
		indiceAsignacion = buscarPosicionTablaSimbolos($1);
		printf("asigesp es: %d\n", ASIGESPMAS );
		indiceAsignacion = crear_terceto(NOOP,NOOP,indiceAsignacion);
		//modificarTerceto(indiceAsignacionEspecial,OP1,indiceAsignacion);
		indiceAsignacionEspecial = crear_terceto(indiceAsignacionEspecial, indiceExpresion, indiceAsignacion);
		indiceAsignacionEspecial = crear_terceto(ASIG,indiceAsignacionEspecial,indiceAsignacion);

		}
	;

asignadorespecial:
	ASIGESPMAS expresion {indiceAsignacionEspecial=SUMA;}
	|ASIGESPMENOS expresion {indiceAsignacionEspecial=RESTA;}
	|ASIGESPMULTIPLICACION expresion {indiceAsignacionEspecial=MULTIPLICACION;}
	|ASIGESPDIVISION expresion {indiceAsignacionEspecial=DIVISION;}
	;

declaretion:
	DECLARE tipo identificadorintermedio {printf("Primer Declaretion ok");}
/*|declaretion PUNTOYCOMA tipo identificadorintermedio {printf("aca xd");}*/
	;

tipo: 
	FLOAT {printf("Variable de tipo float\n");}
	|INT {printf("Variable de tipo entero leido\n");}
	|STRING {printf("Variable de tipo string leido\n");}
	|BOOLEAN {printf("Variable de tipo boolean leido\n");}
	|CHAR {printf("Variable de tipo char leido\n");}
	|DOUBLE {printf("Variable de tipo double leido\n");}
;

identificadorintermedio:
	IDENTIFICADOR {
		printf("IdentificadorIntermedio: %s ",$1);
		indiceIdentificadorIntermedio = crear_terceto(NOOP, NOOP, $1);
		}
	|identificadorintermedio ',' IDENTIFICADOR 
	;

expresion:
        termino {printf("llega a expresion");indiceExpresion = indiceTermino;};
		|expresion RESTA termino {
			printf("Resta OK\n");
			indiceExpresion=crear_terceto(RESTA, indiceExpresion,indiceTermino);
			}
       	|expresion SUMA termino  {
			   printf("Suma OK\n");
			   indiceExpresion=crear_terceto(SUMA, indiceExpresion,indiceTermino);
			   }
 	 ;

termino:
       	factor {indiceTermino = indiceFactor;};
       	|termino MULTIPLICACION factor  {
			   printf("Multiplicacion OK\n");
			   indiceTermino=crear_terceto(MULTIPLICACION, indiceFactor,indiceTermino);
			   }
      	|termino DIVISION factor {
			  printf("Division OK\n");
			  indiceTermino=crear_terceto(DIVISION, indiceFactor,indiceTermino);
			  }
       ;

comparadores:
	MAYOR
	|MENOR
	|MAYORIGUAL
	|MENORIGUAL
	|IGUAL
	|DISTINTO
	;

factor:
    IDENTIFICADOR {
		printf("var: %s ",$1);
		agregarVariableATablaDeSimbolos($1, IDENTIFICADOR);
		indiceIdentificador = buscarPosicionTablaSimbolos($1);
		indiceFactor = crear_terceto(NOOP, NOOP, indiceIdentificador);

		}
    |CONSTANTE {
		printf("La constante es: %s\n",$1);
		agregarVariableATablaDeSimbolos($1, CONSTANTE);
		indiceConstante = buscarPosicionTablaSimbolos($1);
		indiceFactor = crear_terceto(NOOP, NOOP, indiceConstante);
		printf("\nEl indiceFactor es: %d\n", indiceFactor);
		}
	|REAL {printf("El real es: %\n ",$1);}
	|IDENTIFICADOR ABRIRCORCHETE CONSTANTE CERRARCORCHETE {printf("vector %s con %s espacios",$1,$3);}
	|STRING {printf("string: %s ",$1);}
    ;

%%

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