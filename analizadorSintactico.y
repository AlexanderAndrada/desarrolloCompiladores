
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
%token COMENTARIO CONCAT
%token SUMA RESTA MULTIPLICACION DIVISION ASIG
%token MAYOR MENOR MAYORIGUAL MENORIGUAL IGUAL DISTINTO
%token PUNTOYCOMA ABRIRPARENTESIS CERRARPARENTESIS ABRIRLLAVE CERRARLLAVE ABRIRCORCHETE CERRARCORCHETE
%token IF ELSE WHILE PUT GET AND OR DECLARE
%token INT FLOAT DOUBLE CHAR BOOLEAN
%token <var> ASIGESPMAS 
%token ASIGESPMENOS ASIGESPMULTIPLICACION ASIGESPDIVISION
%token <var> STRING
%token JNA
%token ENDIF TRUE ENDSENTENCE ENDWHILE

%type <var> identificadorintermedio

%%
programa:
	MAIN ABRIRLLAVE declaracion sentencias CERRARLLAVE {printf("Main OK\n");escribirTablaSimbolos();guardarArchivoTercetos();}
	;

declaracion:
	DECLARE sentenciadeclaracion PUNTOYCOMA {printf("Declaraciones ok\n");}
	;

sentenciadeclaracion:
	tipo identificadorintermedio 
	|sentenciadeclaracion tipo identificadorintermedio 
	;

tipo: 
	FLOAT
	|INT
	|STRING
	|BOOLEAN
	|CHAR
	|DOUBLE
	;

identificadorintermedio:
	IDENTIFICADOR {
		printf("La variable es: %s ",$1);
		agregarVariableATablaDeSimbolos($1, IDENTIFICADOR);
		indiceIdentificador = buscarPosicionTablaSimbolos($1);
		printf("indice: %d ",indiceIdentificador);
		crear_terceto(NOOP, NOOP, indiceIdentificador);
		contadorVariables++;
		}
	|identificadorintermedio IDENTIFICADOR{
		printf("La variable es: %s ",$2);
		agregarVariableATablaDeSimbolos($2, IDENTIFICADOR);
		indiceIdentificador = buscarPosicionTablaSimbolos($2);
		crear_terceto(NOOP, NOOP, indiceIdentificador);
		contadorVariables++;		
		}
	;
	
sentencias:
	sentencia PUNTOYCOMA {printf("Sentencia ok\n");}
	|sentencias sentencia PUNTOYCOMA
	;

sentencia:
	WHILE sentenciawhile {printf("While ok\n");}
	|IF sentenciaif {printf("If ok\n");}
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
	ABRIRPARENTESIS {
		contadorWhile++;banderaWhileAnd[contadorWhile]=0;banderaWhileOr[contadorWhile]=0;
		indiceWhileCondicion[contadorWhile]=crear_terceto(WHILE, NOOP, NOOP);
		printf("numero de While: %d ",contadorWhile);}
	sentenciacomparacionwhile CERRARPARENTESIS sentenciainicialwhile{
		indiceWhileFin[contadorWhile]=crear_terceto(ENDSENTENCE, NOOP, NOOP);
		modificarTerceto(indiceWhileAux[contadorWhile],OP2,indiceWhileFin[contadorWhile]);
		contadorWhile--;}
	;

sentenciacomparacionwhile:
	expresioncomparacionwhile {
		printf("Sentencia comparacion WHILE ok\n");
		indiceWhileAux[contadorWhile]=crear_terceto(JNA, NOOP, NOOP);}
	|expresioncomparacionwhile {
		indiceWhileAuxAnd[contadorWhile]=crear_terceto(JNA, NOOP, NOOP);}
	AND expresioncomparacionwhile {
		banderaWhileAnd[contadorIf]=1;printf("Sentencia AND comparacion WHILE ok\n");
		indiceWhileAux[contadorIf]=crear_terceto(JNA, NOOP, NOOP);}
	|expresioncomparacionwhile {
		indiceWhileAuxOr[contadorIf]=crear_terceto(JMP, NOOP, NOOP);} 
	OR expresioncomparacionwhile{
		banderaWhileOr[contadorIf]=1;indiceWhileAux[contadorIf]=crear_terceto(JNA, NOOP, NOOP);
		printf("Sentencia OR comparacion WHILE ok\n");}
	;

expresioncomparacionwhile:
	expresion2 comparadores expresion {
		crear_terceto(indiceComparador, indiceExpresion, indiceExpresion2);
		printf("Condicion WHILE ok\n");
	}
	;

sentenciainicialwhile:
	ABRIRLLAVE sentenciaintermediawhile CERRARLLAVE{
	crear_terceto(JMP, NOOP, indiceWhileCondicion[contadorWhile]);}
	;

sentenciaintermediawhile:
	sentencia PUNTOYCOMA
	|sentenciaintermediawhile PUNTOYCOMA sentencia PUNTOYCOMA
	;

sentenciaif:
	ABRIRPARENTESIS {
		contadorIf++;banderaIfAnd[contadorIf]=0;banderaIfOr[contadorIf]=0;printf("numero de if: %d ",contadorIf);} 
	sentenciacomparacionif CERRARPARENTESIS {
		if(banderaIfOr[contadorIf]==1) modificarTerceto(indiceIfAuxOr[contadorIf],OP2,crear_terceto(TRUE, NOOP, NOOP));}
	sentenciainicialif {
		printf("Sentencia if ok\n");contadorIf--;}
	;

sentenciacomparacionif:
	expresioncomparacionif {
		printf("Sentencia comparacion IF ok\n");indiceIfAux[contadorIf]=crear_terceto(JNA, NOOP, NOOP);}
	|expresioncomparacionif {
		indiceIfAuxAnd[contadorIf]=crear_terceto(JNA, NOOP, NOOP);} 
	AND expresioncomparacionif {
		banderaIfAnd[contadorIf]=1;printf("Sentencia AND comparacion IF ok\n");indiceIfAux[contadorIf]=crear_terceto(JNA, NOOP, NOOP);}
	|expresioncomparacionif {
		indiceIfAuxOr[contadorIf]=crear_terceto(JMP, NOOP, NOOP);} 
	OR expresioncomparacionif {
		banderaIfOr[contadorIf]=1;indiceIfAux[contadorIf]=crear_terceto(JNA, NOOP, NOOP);
		printf("Sentencia OR comparacion IF ok\n");}
	;

expresioncomparacionif:
	expresion2 comparadores expresion {
		crear_terceto(indiceComparador, indiceExpresion, indiceExpresion2);
		printf("Condicion IF ok\n");}
	;

sentenciainicialif:
	ABRIRLLAVE sentenciaintermediaif CERRARLLAVE {
		indiceIfFalso=crear_terceto(JMP, NOOP, NOOP);}
	sentenciaelse
	|ABRIRLLAVE sentenciaintermediaif CERRARLLAVE {
		indiceAnd=crear_terceto(ENDIF, NOOP, NOOP);
		if(banderaIfAnd[contadorIf]==1) modificarTerceto(indiceIfAuxAnd[contadorIf],OP2,indiceAnd);
		modificarTerceto(indiceIfAux[contadorIf],OP2,indiceAnd); printf("Cuerpo en If sin ELSE ok\n");}
	;

sentenciaintermediaif:
	sentencia PUNTOYCOMA
	|sentenciaintermediaif PUNTOYCOMA sentencia PUNTOYCOMA
	;

sentenciaelse:
	ELSE ABRIRLLAVE {
		indiceAnd=crear_terceto(ELSE, NOOP, NOOP);
		if(banderaIfAnd[contadorIf]==1) modificarTerceto(indiceIfAuxAnd[contadorIf],OP2,indiceAnd);
		modificarTerceto(indiceIfAux[contadorIf],OP2,indiceAnd);}
	sentenciaintermediaif CERRARLLAVE {
		indiceAnd=crear_terceto(ENDIF, NOOP, NOOP);
		modificarTerceto(indiceIfFalso,OP2,indiceAnd);}
	;

asignacion:
	IDENTIFICADOR ASIG expresion {
		printf("Var: %s Asignacion ok\n",$1);
		agregarVariableATablaDeSimbolos($1, IDENTIFICADOR);
		indiceIdentificador = buscarPosicionTablaSimbolos($1);
		indiceAsignacion = buscar_terceto(indiceIdentificador,contadorVariables);
		crear_terceto(ASIG, indiceExpresion, indiceAsignacion);
		}
	|IDENTIFICADOR ASIG expresionstrings {
		printf("Var: %s Asignacion ok\n",$1);
		agregarVariableATablaDeSimbolos($1, IDENTIFICADOR);
		indiceIdentificador = buscarPosicionTablaSimbolos($1);
		indiceAsignacion = buscar_terceto(indiceIdentificador,contadorVariables);
		crear_terceto(ASIG, indiceExpresion, indiceAsignacion);
		}
	;

asignacionespecial:
	IDENTIFICADOR asignadorespecial {
		agregarVariableATablaDeSimbolos($1, IDENTIFICADOR);
		indiceIdentificador = buscarPosicionTablaSimbolos($1);
		printf("asigesp es: %d\n", indiceAsignacionEspecial );
		indiceAsignacion = buscar_terceto(indiceIdentificador,contadorVariables);
		//modificarTerceto(indiceAsignacionEspecial,OP1,indiceAsignacion);
		indiceAsignacionEspecial = crear_terceto(indiceAsignacionEspecial, indiceExpresion, indiceAsignacion);
		indiceAsignacionEspecial = crear_terceto(ASIG,indiceAsignacionEspecial,indiceAsignacion);
		printf("falla");
		}
	;

asignadorespecial:
	ASIGESPMAS expresion {indiceAsignacionEspecial=SUMA;}
	|ASIGESPMENOS expresion {indiceAsignacionEspecial=RESTA;}
	|ASIGESPMULTIPLICACION expresion {indiceAsignacionEspecial=MULTIPLICACION;}
	|ASIGESPDIVISION expresion {indiceAsignacionEspecial=DIVISION;}
	;

expresionstrings:
	STRING CONCAT STRING {
		printf("concatenacion de %s y %s ",$1,$3);}
	|expresionstrings CONCAT STRING
	;


expresion2:
	expresion {indiceExpresion2 = indiceExpresion;}
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
	MAYOR {indiceComparador=MAYOR;}
	|MENOR {indiceComparador=MENOR;}
	|MENORIGUAL {indiceComparador=MENORIGUAL;}
	|MAYORIGUAL {indiceComparador=MAYORIGUAL;}
	|IGUAL {indiceComparador=IGUAL;}
	|DISTINTO {indiceComparador=DISTINTO;}
	;

factor:
	IDENTIFICADOR {
		printf("La variable es: %s ",$1);
		agregarVariableATablaDeSimbolos($1, IDENTIFICADOR);
		indiceIdentificador = buscarPosicionTablaSimbolos($1);
		indiceFactor = buscar_terceto(indiceIdentificador,contadorVariables);
		}
	|CONSTANTE {
		printf("La constante es: %s\n",$1);
		agregarVariableATablaDeSimbolos($1, CONSTANTE);
		indiceConstante = buscarPosicionTablaSimbolos($1);
		indiceFactor = crear_terceto(NOOP, NOOP, indiceConstante);
		printf("\nEl indiceFactor es: %d\n", indiceFactor);
		}
	|REAL {
		printf("El numero real es: %s ",$1);
		agregarVariableATablaDeSimbolos($1, REAL);
		indiceReal = buscarPosicionTablaSimbolos($1);
		indiceFactor = crear_terceto(NOOP, NOOP, indiceReal);
		}
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